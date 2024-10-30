//! This module is written for Rinf demonstrations.

use libheat::FMatrix;

use crate::{messages::*, types::*};

pub fn send_to_dart(msg: RustMessage) {
    let text = match serde_json::to_string(&msg) {
        Ok(r) => r,
        Err(_) => {
            // this is not supposed to get errors
            return;
        }
    };

    GenericRustSignal { text }.send_signal_to_dart();
}

pub fn receive_from_dart(signal: GenericDartSignal) -> Option<DartMessage> {
    let text = signal.text;

    let message: DartMessage = match serde_json::from_str(&text) {
        Ok(r) => r,
        Err(r) => {
            send_to_dart(RustMessage::Error { msg: r.to_string() });
            // this is not supposed to get errors
            return None;
        }
    };

    Some(message)
}

pub async fn communicate() {
    // Get receivers that listen to Dart signals like below.
    let receiver = GenericDartSignal::get_dart_signal_receiver();
    while let Some(dart_signal) = receiver.recv().await {
        if let Some(request) = receive_from_dart(dart_signal.message) {
            match request {
                DartMessage::Simulation {
                    init_data,
                    n_y,
                    n_t,
                    alpha,
                    dx,
                    dy,
                    dt,
                } => {
                    let init_condition = match FMatrix::adapt_vec(init_data, n_y) {
                        Ok(r) => r,
                        Err(msg) => {
                            send_to_dart(RustMessage::Error { msg });
                            continue;
                        }
                    };

                    match libheat::run_simulation(&init_condition, n_t, alpha, dx, dy, dt) {
                        Err(()) => {
                            send_to_dart(RustMessage::Error {
                                msg: "simulation failed".to_string(),
                            });
                            continue;
                        }
                        Ok(result) => {
                            send_to_dart(RustMessage::SimulationResult {
                                data: result,
                                n_x: init_condition.ncol(),
                                n_y: init_condition.nrow(),
                                n_t,
                            });
                        }
                    }
                }
            }
        }
    }
}

// Though async tasks work, using the actor model
// is highly recommended for state management
// to achieve modularity and scalability in your app.
// To understand how to use the actor model,
// refer to the Rinf documentation.
