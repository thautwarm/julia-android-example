include("juliamk.jl")

const OUTPUT_EXE = ""
const OUTPUT_DL = "libheat"
const PREDEFINED_TARGET_OS = "windows"
const PREDEFINED_TARGET_ARCH = "x86_64"
const EXTRA_ARGS = split("")
const CPP_VERSION = "c++11"
const STATIC_MINGW = false
const CTOOLCHAIN_DETAILS = CToolchainDetails(
    libc = "glibc",
    glibc_version = "2.17",
    hardfloat = false,
    endianness = "little",
)
# If your machine has no GNU make or Unix toolchains,
# and zig does not work, set this to 'true'.
const USE_NATIVE_CXXCOMPILER = haskey(ENV, "JULIAMK_NATIVE_BUILD")

function main()
    OS, ARCH = normalize_os_arch(PREDEFINED_TARGET_OS, PREDEFINED_TARGET_ARCH)
    ctoolchain = find_ctoolchain(OS, ARCH, CTOOLCHAIN_DETAILS, USE_NATIVE_CXXCOMPILER)

    CXX = ctoolchain.CXX
    CC = ctoolchain.CC
    AR = ctoolchain.AR
    RANLIB = ctoolchain.RANLIB

    DL_PREFIX = ""
    DL_EXT = ""
    SL_EXT = ""
    SL_PREFIX = ""

    if (CXX == ["g++"])
        CXXFLAGS_USER = split("-std=$(CPP_VERSION) -O2 -fno-stack-protector")
        CFLAGS_DEPS = split("-w -O2 -fno-stack-protector")
    else
        CXXFLAGS_USER = split("-std=$(CPP_VERSION) -O2 -fno-sanitize=undefined -fno-stack-protector")
        CFLAGS_DEPS = split("-w -O2 -fno-sanitize=undefined -fno-stack-protector")
    end
    FINAL_ARGS = [
        "-Wl,--as-needed",
        "-Wl,-rpath,\$ORIGIN:\$ORIGIN/lib:.",
        "-Wno-unused-variable",
        "-Wno-unused-value",
    ]

    if OS === "windows"
        DL_EXT = ".dll"
        if ctoolchain.use_zig
            SL_EXT = ".lib"
        else
            SL_EXT = ".a"
            SL_PREFIX = "lib"
        end
        push!(FINAL_ARGS, "-DWIN32_LEAN_AND_MEAN")
    elseif OS === "linux"
        DL_EXT = ".so"
        DL_PREFIX = "lib"
        SL_EXT = ".a"
        SL_PREFIX = "lib"
        push!(CFLAGS_DEPS, "-D_GNU_SOURCE")
        push!(FINAL_ARGS, "-ldl")
        push!(FINAL_ARGS, "-lpthread")
    elseif OS === "macos"
        DL_EXT = ".dylib"
        DL_PREFIX = "lib"
        SL_EXT = ".a"
        SL_PREFIX = "lib"
        push!(CFLAGS_DEPS, "-D_DARWIN_C_SOURCE")
    else
        error("Unsupported OS: $OS")
    end

    # iort
    header_iort = fglob(".h", "syslabcrt-io/include")
    srcs_iort = fglob(".c", "syslabcrt-io/src")
    objs_iort = [replace(src, ".c" => ".o") for src in srcs_iort]

    # dylib
    srcs_dylib = ["syslabcrt-dylib/syslabcrt_dylib.c"]
    objs_dylib = ["syslabcrt-dylib/syslabcrt_dylib.o"]

    # intrinsc
    header_intrinsics = fglob(".hpp", "syslabcrt-intrinsics")

    # bdwgc
    header_atomic_ops = fglob(".h", "atomic_ops/src")
    header_bdwgc = fglob(".h", "bdwgc/include")
    srcs_bdwgc = [joinpath("bdwgc", file) for file in readdir("bdwgc") if endswith(file, ".c")]
    objs_dbwgc = [replace(src, ".c" => ".o") for src in srcs_bdwgc]
    define_bdwgc = [
        "-DENABLE_DISCLAIM",
        "-DGC_ATOMIC_UNCOLLECTABLE",
        "-DGC_GCJ_SUPPORT",
        "-DJAVA_FINALIZATION",
        "-DNO_EXECUTE_PERMISSION",
        "-DUSE_MMAP",
        "-DUSE_MUNMAP",
        "-DGC_THREADS",
        "-DPARALLEL_MARK",
        "-DTHREAD_LOCAL_ALLOC",
    ]
    if OS === "windows"
        push!(define_bdwgc, "-DWIN32_THREADS")
        if STATIC_MINGW
            push!(
                FINAL_ARGS,
                "-static-libgcc",
                "-static-libstdc++",
            )
            if !ctoolchain.use_zig
                push!(
                    FINAL_ARGS,
                    "-Wl,-Bstatic",
                    "-lstdc++",
                    "-lpthread",
                    "-Wl,-Bdynamic",
                )
            end
        end
    end

    target("bin/$(DL_PREFIX)bdwgc$(DL_EXT)") do b
        depends_on(b, objs_dbwgc)
        isdir("bin") || mkdir("bin")
        T = b.target
        D = b.deps
        runcmd(`$(CC) -shared $(CFLAGS_DEPS) -o $T win32-implib/bdwgc.c $D`)
    end

    for src in srcs_bdwgc
        target(replace(src, ".c" => ".o")) do b
            depends_on(b, src)
            depends_on(b, header_bdwgc)
            depends_on(b, header_atomic_ops)

            T = b.target
            runcmd(`$(CC) -fPIC -c $(CFLAGS_DEPS) -Ibdwgc/include -Iatomic_ops/src -o $T $src $(define_bdwgc)`)
        end
    end

    target("bin/$(SL_PREFIX)syslabcrt-io$(SL_EXT)") do b
        depends_on(b, objs_iort)
        isdir("bin") || mkdir("bin")
        T = b.target
        D = b.deps
        runcmd(`$(AR) rcs $T $D`)
        runcmd(`$(RANLIB) $T`)
    end

    for src in srcs_iort
        target(replace(src, ".c" => ".o")) do b
            depends_on(b, src)
            depends_on(b, header_iort)

            T = b.target
            D = b.deps
            runcmd(`$(CC) -fPIC -c $(CFLAGS_DEPS) -Isyslabcrt-io/include -o $T $src`)
        end
    end

    target("bin/$(SL_PREFIX)syslabcrt-dylib$(SL_EXT)") do b
        depends_on(b, objs_dylib)
        isdir("bin") || mkdir("bin")
        T = b.target
        D = b.deps
        runcmd(`$(AR) rcs $T $D`)
        runcmd(`$(RANLIB) $T`)
    end

    for src in srcs_dylib
        target(replace(src, ".c" => ".o")) do b
            depends_on(b, [
                "syslabcrt-dylib/syslabcrt_dylib.c",
            ])

            T = b.target
            D = b.deps
            runcmd(`$(CC) -fPIC -c $(CFLAGS_DEPS) -o $T $D`)
        end
    end

    target("bin/$OUTPUT_EXE") do b
        depends_on(b, header_intrinsics)
        depends_on(b, "bin/$(SL_PREFIX)syslabcrt-io$(SL_EXT)")
        depends_on(b, "bin/$(SL_PREFIX)syslabcrt-dylib$(SL_EXT)")
        depends_on(b, "bin/$(DL_PREFIX)bdwgc$(DL_EXT)")
        depends_on(b, "$(OUTPUT_EXE).cpp")

        isdir("bin") || mkdir("bin")

        T = b.target
        extra = String[]
        if (OS === "windows")
            linkbdwgc = "-lbdwgc"
            if ctoolchain.use_zig
                # reference: https://github.com/ziglang/zig/issues/8531
                extra = ["-fno-lto"]
            end
        else
            linkbdwgc = "-l:$(DL_PREFIX)bdwgc$(DL_EXT)"
        end
        runcmd(`$(CXX) $(CXXFLAGS_USER) -o $T $(OUTPUT_EXE).cpp -Isyslabcrt-intrinsics -Isyslabcrt-io/include -Ighc-filesystem -Lbin -lsyslabcrt-io -lsyslabcrt-dylib $linkbdwgc $extra $(FINAL_ARGS) $(EXTRA_ARGS)`)
    end

    target("bin/$(OUTPUT_DL)$(DL_EXT)") do b
        depends_on(b, header_intrinsics)
        depends_on(b, "bin/$(SL_PREFIX)syslabcrt-io$(SL_EXT)")
        depends_on(b, "bin/$(SL_PREFIX)syslabcrt-dylib$(SL_EXT)")
        depends_on(b, "bin/$(DL_PREFIX)bdwgc$(DL_EXT)")
        depends_on(b, "$(OUTPUT_DL).cpp")

        isdir("bin") || mkdir("bin")

        T = b.target
        extra = String[]
        if (OS === "windows")
            linkbdwgc = "-lbdwgc"
            if !ctoolchain.use_zig
                append!(extra, ["-Wl,--out-implib", "bin/$(OUTPUT_DL).lib"])
            end
        else
            linkbdwgc = "-l:$(DL_PREFIX)bdwgc$(DL_EXT)"
        end
        if (OS === "windows")
            # create file first, in case some mingw linker didn't recognize -Wl,--out-implib option
            touch("bin/$(OUTPUT_DL).lib")
        end
        runcmd(`$(CXX) -fPIC -shared $(CXXFLAGS_USER) -o $T $(OUTPUT_DL).cpp -Isyslabcrt-intrinsics -Isyslabcrt-io/include -Ighc-filesystem -Lbin -lsyslabcrt-io -lsyslabcrt-dylib $linkbdwgc $extra $(FINAL_ARGS) $(EXTRA_ARGS)`)
    end

    if isfile("$OUTPUT_EXE.cpp")
        assure_target("bin/$OUTPUT_EXE")
    end
    if isfile("$OUTPUT_DL.cpp")
        assure_target("bin/$(OUTPUT_DL)$(DL_EXT)")
    end
end

const PHONY = Dict(
    "clean" => function build_clean()
        rm("bin"; recursive = true, force = true)
        for each in fglob(".o", ".")
            rm(each; force = true)
        end
        @info "Cleaned up!"
    end,
    "all" => function build_all()
        try
            rm("bin"; recursive = true, force = true)
        catch
            # ignore
        end
        try
            for each in fglob(".o", ".")
                rm(each; force = true)
            end
        catch
            # ignore
        end
        isdir("bin") || mkdir("bin")
        isdir("lib/") && cp("lib/", "bin/lib"; force=true)
        main()
    end,
)

try
    for arg in ARGS
        f = get(PHONY, arg, nothing)
        if !isnothing(f)
            f()
            if arg == "all"
                println("\x1b[1m\x1b[32m[Info]:\x1b[0m\x1b[0m Build succeeded.")
            end
        else
            @warn("Unknown PHONY target: $arg")
        end
    end
catch e
    # for juliamk.jl developers, you may remove the
    # following line to see the full backtrace.
    # showerror(stderr, e, catch_backtrace())

    @error "Build failed." _file=nothing _line=nothing _module=nothing
    yield()
    flush(stdout)
    flush(stderr)
    exit(1)
end
