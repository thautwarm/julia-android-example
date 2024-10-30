import 'dart:convert';

import 'package:fl_heatmap/fl_heatmap.dart';
import 'package:flutter/material.dart';
import 'package:julia_android/messages/basic.pb.dart';
import 'package:julia_android/obs.dart';
import 'package:julia_android/types.dart';
import 'package:oktoast/oktoast.dart';
import 'package:provider/provider.dart';

class AppWithSettings extends StatelessWidget {
  const AppWithSettings({super.key});

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      // initialize the temperature distribution
      // with a constant temperature on the left edge
      create: (_) =>
          SimulationRequest(DemoSimulation.initWithTempOnTheLeftEdge(10)),
      child: Builder(builder: (context) {
        final req = Provider.of<SimulationRequest>(context);
        return Column(
          children: [
            const SizedBox(height: 80),
            const SizedBox(height: 50, child: Text("SyslabCC 热力学方程仿真示例")),
            const SizedBox(height: 50, child: SimulationRunButton()),
            Row(
              children: [
                Expanded(
                  child: SimulationFactorControl(
                    // alpha in unicode
                    name: "α",
                    value: req.value.alpha,
                    onChanged: (v) {
                      req.value = req.value.copyWith(alpha: v);
                    },
                  ),
                ),
                Expanded(
                  child: SimulationFactorControl(
                    // alpha in unicode
                    name: "N(t)",
                    min: 1,
                    max: 50,
                    divisions: 15,
                    value: req.value.n_t.toDouble(),
                    onChanged: (v) {
                      req.value = req.value.copyWith(n_t: v.toInt());
                    },
                  ),
                ),
              ],
            ),

            // delta factors
            Row(
              children: [
                Expanded(
                  child: SimulationFactorControl(
                    name: "Δx",
                    min: 0.01,
                    max: 0.5,
                    value: req.value.dx,
                    onChanged: (v) {
                      req.value = req.value.copyWith(dx: v);
                    },
                  ),
                ),
                Expanded(
                  child: SimulationFactorControl(
                    name: "Δy",
                    min: 0.01,
                    max: 0.5,
                    value: req.value.dy,
                    onChanged: (v) {
                      req.value = req.value.copyWith(dy: v);
                    },
                  ),
                ),
                Expanded(
                  child: SimulationFactorControl(
                    name: "Δt",
                    min: 0.01,
                    max: 0.5,
                    value: req.value.dy,
                    onChanged: (v) {
                      req.value = req.value.copyWith(dt: v);
                    },
                  ),
                ),
              ],
            ),
            const Expanded(child: HeapmapContainer())
          ],
        );
      }),
    );
  }
}

class SimulationFactorControl extends StatelessWidget {
  final String name;
  final Function(double) onChanged;
  final double min;
  final double max;
  final double value;
  final int? divisions;

  const SimulationFactorControl({
    this.min = 0,
    this.max = 1,
    this.divisions,
    required this.value,
    required this.name,
    required this.onChanged,
    super.key,
  });

  @override
  Widget build(BuildContext context) {
    return Row(mainAxisSize: MainAxisSize.max, children: [
      // prefix space
      const SizedBox(width: 10),
      // Button: Simulation Execution
      Text(name),
      // pad space
      const SizedBox(width: 10),
      // Simulation Settings
      Expanded(
        child: Slider(
          key: ValueKey((name, value)),
          label: "$value",
          value: value,
          min: min,
          max: max,
          divisions: divisions,
          onChanged: onChanged,
        ),
      )
    ]);
  }
}

class SimulationRunButton extends StatelessWidget {
  const SimulationRunButton({super.key});

  @override
  Widget build(BuildContext context) {
    final req = Provider.of<SimulationRequest>(context);
    return ElevatedButton(
      style: ButtonStyle(
        shape: WidgetStateProperty.all(
          RoundedRectangleBorder(
            borderRadius: BorderRadius.circular(5),
          ),
        ),
      ),
      onPressed: () {
        GenericDartSignal(text: json.encode(req.value.toJson()))
            .sendSignalToRust();

        showToast("Simulation started");
      },
      child: const Text("Syslab，Run!"),
    );
  }
}

class HeatmapBuildCache extends ChangeNotifier {
  final SimulationResponse resp;
  HeatmapData? _data;
  int _selectedT = 0;

  HeatmapBuildCache(this.resp) {
    _rebuildData(false);
  }

  HeatmapData? get data => _data;

  int get selectedT => _selectedT;

  set selectedT(int selectedT) {
    _selectedT = selectedT;
    _rebuildData(true);
  }

  void _rebuildData(bool notify) {
    final nX = resp.value.n_x;
    final nY = resp.value.n_y;
    final area = nX * nY;
    final nT = resp.value.n_t;
    List<String> columns = Iterable.generate(nY, (i) => i.toString()).toList();
    List<String> rows = Iterable.generate(nX, (i) => i.toString()).toList();
    List<HeatmapItem> items = [];

    if (_selectedT < nT) {
      final dataRange = resp.value.data.sublist(
        _selectedT * area,
        (_selectedT + 1) * area,
      );

      var d = 0;
      for (var j = 0; j < nX; j++) {
        for (var i = 0; i < nY; i++, d++) {
          items.add(
            HeatmapItem(
              value: dataRange[d],
              unit: 'kWh',
              style: HeatmapItemStyle.filled,
              yAxisLabel: columns[j],
              xAxisLabel: rows[i],
            ),
          );
        }
      }

      _data = HeatmapData(
        columns: columns,
        rows: rows,
        items: items,
        colorPalette: colorPaletteRed,
      );
    }
    if (notify) notifyListeners();
  }
}

class HeapmapContainer extends StatefulWidget {
  const HeapmapContainer({super.key});
  @override
  State<HeapmapContainer> createState() => _HeapmapContainerState();
}

class _HeapmapContainerState extends State<HeapmapContainer> {
  bool running = true;
  SimulationResponse? result;
  @override
  void initState() {
    super.initState();

    runCoro();
  }

  @override
  void dispose() {
    running = false;
    super.dispose();
  }

  void runCoro() async {
    await for (final each in GenericRustSignal.rustSignalStream) {
      if (!running) {
        break;
      }
      try {
        final msg = RustMessage.fromJson(json.decode(each.message.text));
        switch (msg) {
          case RustError msg:
            showToast(msg.msg);
            break;
          case SimulationResult msg:
            showToast("Simulation finished");
            setState(() => result = SimulationResponse(msg));
            break;
        }
      } catch (e) {
        showToast("Error: $e");
      }
      // wait for the next signal
      await Future.delayed(const Duration(milliseconds: 5));
    }
  }

  @override
  Widget build(BuildContext context) {
    if (result == null) {
      return const Center(child: CircularProgressIndicator());
    }
    return ChangeNotifierProvider.value(
      value: result!,
      child: const HeatmapView(),
    );
  }
}

class HeatmapView extends StatelessWidget {
  const HeatmapView({super.key});

  @override
  Widget build(BuildContext context) {
    final resp = Provider.of<SimulationResponse>(context);

    return ChangeNotifierProvider(
      key: ValueKey(resp),
      create: (_) => HeatmapBuildCache(resp),
      child: Consumer<HeatmapBuildCache>(builder: (context, cache, _) {
        final data = cache.data;
        if (data == null) {
          return const CircularProgressIndicator();
        }
        return Column(
          children: [
            Expanded(child: Heatmap(heatmapData: data)),
            const Divider(),
            // a slide that controls the selectedT
            Row(
              children: [
                const SizedBox(width: 10),
                const Text("N(t)"),
                const SizedBox(width: 10),
                Expanded(
                  child: SizedBox(
                    height: 70,
                    child: Slider(
                      label: "N(t): ${cache.selectedT}",
                      min: 0,
                      max: resp.value.n_t.toDouble() + 1,
                      value: cache.selectedT.toDouble(),
                      onChanged: (value) {
                        final index = value.toInt().clamp(0, resp.value.n_t);
                        cache.selectedT = index;
                      },
                    ),
                  ),
                ),
              ],
            )
          ],
        );
      }),
    );
  }
}
