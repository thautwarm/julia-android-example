use crate::{sys::simulate, FMatrix};

#[test]
fn test_example() {
    let alpha = 0.01;
    let dx = 0.1;
    let dy = 0.1;
    let dt = 0.01;
    let nx = 10;
    let ny = 10;
    let nt = 100;

    let mut U: FMatrix<f64> = FMatrix::new(nt, ny * nx);
    let mut u: FMatrix<f64> = FMatrix::new(ny, nx);

    // set the boundary conditions
    for i in 0..nx {
        *u.get_mut(0, i) = 10.0;
        *u.get_mut(ny - 1, i) = 10.0;
        *u.get_mut(i, 0) = 10.0;
        *u.get_mut(i, nx - 1) = 10.0;
    }

    let success = unsafe {
        simulate(
            U.get_mut_ptr(),
            u.get_ptr(),
            nx as i64,
            ny as i64,
            nt as i64,
            alpha,
            dx,
            dy,
            dt,
        )
    };

    if success == 0 {
        panic!("Simulation failed");
    }

    println!("Simulation successful");
    println!("sum: {}", U.into_vec().into_iter().sum::<f64>());

    // sum of the U
}
