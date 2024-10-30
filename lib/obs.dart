import 'package:flutter/material.dart';
import 'package:julia_android/types.dart' as types;

class SimulationRequest extends ChangeNotifier {
  types.DemoSimulation _value;

  SimulationRequest(this._value);

  types.DemoSimulation get value => _value;

  set value(types.DemoSimulation value) {
    _value = value;
    notifyListeners();
  }
}

class SimulationResponse extends ChangeNotifier {
  types.SimulationResult _value;

  SimulationResponse(this._value);

  types.SimulationResult get value => _value;

  set value(types.SimulationResult value) {
    _value = value;
    notifyListeners();
  }
}
