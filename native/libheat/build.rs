use std::path::{Path, PathBuf};

use cc::Build;
use walkdir::WalkDir;

fn is_windows() -> bool {
    #[cfg(target_os = "windows")]
    return true;
    #[cfg(not(target_os = "windows"))]
    return false;
}

fn is_linux() -> bool {
    #[cfg(target_os = "linux")]
    return true;
    #[cfg(not(target_os = "linux"))]
    return false;
}


fn get_files(path: &str, ext: &str, recursive: bool) -> Vec<String> {
    let mut result: Vec<String> = Vec::new();

    if recursive {
        let walker = WalkDir::new(path);
        for entry in walker {
            let entry = entry.unwrap();
            if let Some(found_ext) = entry.path().extension() {
                if found_ext == ext {
                    result.push(entry.path().to_str().unwrap().to_string());
                }
            }
        }
    } else {
        let files = std::fs::read_dir(path).unwrap();
        for file in files {
            let file = file.unwrap();
            if let Some(found_ext) = file.path().extension() {
                if found_ext == ext {
                    result.push(file.path().to_str().unwrap().to_string());
                }
            }
        }
    }

    if is_windows() {
        // replace / with \\ for windows
        result = result.iter().map(|x| x.replace("/", "\\")).collect();
    }

    return result;
}

pub fn change_extension(path: &str, ext: &str) -> String {
    let path = Path::new(path);
    let path = path.with_extension(ext);
    path.display().to_string()
}

fn mark_intentional_no_warn(_build: &mut Build, _use_cpp: bool) {
    // build
    //     .flag("-Wno-unused")
    //     .flag("-Wno-implicit-fallthrough")
    //     .flag("-Wno-sign-compare")
    //     .flag("-Wno-parentheses")
    //     .flag("-Wno-type-limits");

    // if use_cpp {
    //     build.flag("-Wno-class-memaccess").flag("-Wno-reorder");
    // }
}

// pure c build
fn build_bdwgc() -> Vec<PathBuf> {
    let mut build = Build::new();
    if is_linux() {
        build.flag("-D_GNU_SOURCE");
    }

    let files = get_files("libheat/bdwgc", "c", false);
    let include_dir = &["libheat/bdwgc/include", "libheat/atomic_ops/src"];

    let mut define_bdwgc = vec![
        "GC_ATOMIC_UNCOLLECTABLE",
        "GC_GCJ_SUPPORT",
        "JAVA_FINALIZATION",
        "NO_EXECUTE_PERMISSION",
        "USE_MMAP",
        "USE_MUNMAP",
        "GC_PTHREADS",
        "GC_THREADS",
        "PARALLEL_MARK",
        "THREAD_LOCAL_ALLOC",
    ];

    if build.get_compiler().is_like_msvc() {
        define_bdwgc.push("WIN32_THREADS");
    }

    build.file("libheat/win32-implib/bdwgc.c");

    define_bdwgc.iter().for_each(|define| {
        build.define(define, None);
    });

    if is_windows() {
        build.define("WIN32_LEAN_AND_MEAN", None);
    }

    build.files(files).includes(include_dir);
    build.compile_intermediates()
}

fn build_syslabcrt() -> Vec<PathBuf> {
    let mut build = Build::new();
    let mut files = get_files("libheat/syslabcrt-io/src", "c", true);
    files.extend(get_files("libheat/syslabcrt-dylib", "c", true));

    let include_dir = &["libheat/syslabcrt-io/include"];

    build.files(files.clone()).includes(include_dir);

    mark_intentional_no_warn(&mut build, false);

    if is_windows() {
        build.define("WIN32_LEAN_AND_MEAN", None);
    }

    build.compile_intermediates()
}

fn build_lib() -> Vec<PathBuf> {
    let mut build = Build::new();
    build
        .cpp(true)
        .file("libheat/libheat.cpp")
        .flag("-fno-strict-aliasing");

    mark_intentional_no_warn(&mut build, true);

    build.includes(&[
        "libheat/syslabcrt-io/include",
        "libheat/syslabcrt-intrinsics",
        "libheat/ghc-filesystem",
    ]);

    // Add system libraries needed for dynamic loading
    if is_linux() {
        println!("cargo:rustc-link-lib=dylib=dl");
        println!("cargo:rustc-link-lib=dylib=pthread");
    }

    build.compile_intermediates()
}

pub fn build_into_one() {
    let mut build = Build::new();

    build
        .cpp(true)
        .objects(build_bdwgc())
        .objects(build_syslabcrt())
        .objects(build_lib())
        .compile("syslabcc_app");
}

fn main() {
    // https://rinf.cunarist.com/frequently-asked-questions/#my-app-failed-to-load-dynamic-library
    // https://github.com/Losses/rune/pull/26
    let target_os = std::env::var("CARGO_CFG_TARGET_OS");
    match target_os.as_ref().map(|x| &**x) {
        Ok("android") => {
            println!("cargo:rustc-link-lib=dylib=stdc++");
            println!("cargo:rustc-link-lib=c++_shared");
        },
        _ => {}
    }

    build_into_one();

    // write the rebuild token
    println!("cargo:rerun-if-changed=rebuild-token");
    println!("cargo:rerun-if-changed=build.rs");
}
