pub mod sys {
    #[link(name = "syslabcc_app", kind = "static")]
    extern "C" {
        #[allow(non_snake_case)]
        pub fn simulate(
            U: *mut f64,   // Nt x Ny x Nx array
            u: *const f64, // Ny x Nx matrix
            n_x: i64,      // number of rows
            n_y: i64,      // number of columns
            n_t: i64,      // number of time steps
            alpha: f64,    // thermal diffusivity
            dx: f64,       // spatial step size (x)
            dy: f64,       // spatial step size (y)
            dt: f64,       // time step size
        ) -> u8;
    }
}

#[derive(Clone, Debug)]
/// matrix using fortran memory-order (column-major)
pub struct FMatrix<T> {
    _data: Vec<T>,
    _nrow: usize,
}

impl<T: Default + Clone> FMatrix<T> {
    pub fn new(nrow: usize, ncol: usize) -> Self {
        Self {
            _data: vec![T::default(); nrow * ncol],
            _nrow: nrow,
        }
    }

    pub fn adapt_vec(vec: Vec<T>, nrows: usize) -> Result<Self, String> {
        if vec.len() % nrows != 0 {
            return Err(format!(
                "cannot create matrix from the vector(len={}) and nrows={}",
                vec.len(),
                nrows
            ));
        }
        Ok(Self {
            _data: vec,
            _nrow: nrows,
        })
    }

    pub fn nrow(&self) -> usize {
        self._nrow
    }

    pub fn ncol(&self) -> usize {
        self._data.len() / self._nrow
    }

    pub fn get_ref(&self, i: usize, j: usize) -> &T {
        &self._data[i + j * self._nrow]
    }

    pub fn get_mut(&mut self, i: usize, j: usize) -> &mut T {
        &mut self._data[i + j * self._nrow]
    }

    pub unsafe fn get_ptr(&self) -> *const T {
        self._data.as_ptr()
    }

    pub unsafe fn get_mut_ptr(&mut self) -> *mut T {
        self._data.as_mut_ptr()
    }

    pub fn into_vec(self) -> Vec<T> {
        self._data
    }
}

pub fn run_simulation(
    init_condition: &FMatrix<f64>,
    n_t: usize,
    alpha: f64,
    dx: f64,
    dy: f64,
    dt: f64,
) -> Result<Vec<f64>, ()> {
    let n_y = init_condition.nrow();
    let n_x = init_condition.ncol();

    let mut output_array = vec![0.0; n_t * n_y * n_x];

    let errcode = unsafe {
        sys::simulate(
            output_array.as_mut_ptr(),
            init_condition.get_ptr(),
            n_x as i64,
            n_y as i64,
            n_t as i64,
            alpha,
            dx,
            dy,
            dt,
        )
    };

    if errcode == 0 {
        return Err(());
    }
    return Ok(output_array);
}

#[allow(unused)]
#[cfg(test)]
mod tests;
