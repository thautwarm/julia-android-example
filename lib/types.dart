// ignore_for_file: non_constant_identifier_names

import 'dart:math';

abstract class DartMessage {
  String get k;

  Map<String, dynamic> toJson() {
    var res = toJsonImpl();
    res["k"] = k;
    return res;
  }

  static DartMessage fromJson(Map<String, dynamic> json) {
    switch (json["k"]) {
      case "Simulation":
        return DemoSimulation.fromJson(json);
      default:
        throw Exception("Unknown message type: ${json["k"]}");
    }
  }

  Map<String, dynamic> toJsonImpl();
}

class DemoSimulation extends DartMessage {
  List<double> init_data;
  int n_y;
  int n_t;
  double alpha;
  double dx;
  double dy;
  double dt;

  DemoSimulation(
      {required this.init_data,
      required this.n_y,
      required this.n_t,
      required this.alpha,
      required this.dx,
      required this.dy,
      required this.dt});

  DemoSimulation copyWith(
          {List<double>? init_data,
          int? n_y,
          int? n_t,
          double? alpha,
          double? dx,
          double? dy,
          double? dt}) =>
      DemoSimulation(
        init_data: init_data ?? this.init_data,
        n_y: n_y ?? this.n_y,
        n_t: n_t ?? this.n_t,
        alpha: alpha ?? this.alpha,
        dx: dx ?? this.dx,
        dy: dy ?? this.dy,
        dt: dt ?? this.dt,
      );

  // 产生一组默认默认的
  static DemoSimulation initWithTempOnTheLeftEdge(double initialTemperature) {
    final rnd = Random();
    const int nX = 10;
    const int nY = 10;
    const int nT = 20;
    final initData = List.generate(nX * nY, (index) => 0.0);

    for (var i = 0; i < nX; i++) {
      initData[i * nY + 0] = rnd.nextDouble() * initialTemperature;
    }

    return DemoSimulation(
      alpha: 0.01,
      n_y: nY,
      n_t: nT,
      dt: 0.1,
      dx: 0.1,
      dy: 0.1,
      init_data: initData,
    );
  }

  @override
  String get k => "Simulation";

  @override
  Map<String, dynamic> toJsonImpl() {
    return {
      "init_data": init_data,
      "n_y": n_y,
      "n_t": n_t,
      "alpha": alpha,
      "dx": dx,
      "dy": dy,
      "dt": dt
    };
  }

  factory DemoSimulation.fromJson(Map<String, dynamic> json) {
    return DemoSimulation(
      init_data: List<double>.from(json["init_data"]),
      n_y: json["n_y"],
      n_t: json["n_t"],
      alpha: json["alpha"],
      dx: json["dx"],
      dy: json["dy"],
      dt: json["dt"],
    );
  }
}

abstract class RustMessage {
  String get k;

  Map<String, dynamic> toJson() {
    var res = toJsonImpl();
    res["k"] = k;
    return res;
  }

  static RustMessage fromJson(Map<String, dynamic> json) {
    switch (json["k"]) {
      case "Error":
        return RustError.fromJson(json);
      case "SimulationResult":
        return SimulationResult.fromJson(json);
      default:
        throw Exception("Unknown message type: ${json["k"]}");
    }
  }

  Map<String, dynamic> toJsonImpl();
}

class RustError extends RustMessage {
  String msg;

  RustError(this.msg);

  @override
  String get k => "Error";

  @override
  Map<String, dynamic> toJsonImpl() {
    return {
      "msg": msg,
    };
  }

  factory RustError.fromJson(Map<String, dynamic> json) {
    return RustError(json["msg"]);
  }
}

class SimulationResult extends RustMessage {
  List<double> data;
  int n_x;
  int n_y;
  int n_t;

  SimulationResult({
    required this.data,
    required this.n_x,
    required this.n_y,
    required this.n_t,
  });

  @override
  String get k => "SimulationResult";

  @override
  Map<String, dynamic> toJsonImpl() {
    return {
      "data": data,
      "n_x": n_x,
      "n_y": n_y,
      "n_t": n_t,
    };
  }

  factory SimulationResult.fromJson(Map<String, dynamic> json) {
    return SimulationResult(
      data: List<double>.from(json["data"]),
      n_x: json["n_x"],
      n_y: json["n_y"],
      n_t: json["n_t"],
    );
  }
}
