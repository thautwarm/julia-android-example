use serde::{Deserialize, Serialize};
#[derive(Serialize, Deserialize)]
pub struct SimulationParams {}

#[derive(Serialize, Deserialize)]
#[serde(tag = "k")]
pub enum DartMessage {
    Simulation {
        init_data: Vec<f64>,
        n_y: usize,
        n_t: usize,
        alpha: f64,
        dx: f64,
        dy: f64,
        dt: f64,
    },
}

#[derive(Serialize, Deserialize)]
#[serde(tag = "k")]
pub enum RustMessage {
    Error {
        msg: String,
    },
    SimulationResult {
        data: Vec<f64>,
        n_x: usize,
        n_y: usize,
        n_t: usize,
    },
}
