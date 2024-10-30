import 'package:flutter/material.dart';
import 'package:julia_android/pages.dart';
import 'package:oktoast/oktoast.dart';
import 'package:rinf/rinf.dart';
import './messages/all.dart';

void main() async {
  await initializeRust(assignRustSignal);
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'SyslabCC Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
        useMaterial3: true,
      ),
      home: OKToast(
        child: MaterialApp(
          title: 'SyslabCC Demo',
          theme: ThemeData(primarySwatch: Colors.blue),
          home: const Scaffold(body: AppWithSettings()),
        ),
      ),
    );
  }
}
