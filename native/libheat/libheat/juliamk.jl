#=
    This file is part of [MWORKS.Syslab](https://www.tongyuan.cc/product/MWorksSyslab).
    It is designed as a tiny fallback build system when Makefile is not available on the user machine.
    NOTE that this file is not intented to be reused outside the scope of MWORKS.Syslab.
=#
mutable struct Target
    target::String
    deps::Vector{String}
    task::Union{Nothing,Task}
    build::Function
end

const _TARGETS = Dict{String, Target}()

const GLIBC_VERSION = "2.17"

Base.@kwdef struct CToolchainDetails
    # "glibc" or "musl"
    libc::String = "glibc"
    glibc_version::String = GLIBC_VERSION
    hardfloat::Bool = false
    # "little" or "big"
    endianness::String = "little"
end

mutable struct CToolchain
    CC::Vector{String}
    CXX::Vector{String}
    AR::Vector{String}
    RANLIB::Vector{String}
    is_cross_compilation::Bool
    use_zig::Bool
end

function runcmd(cmd)
    println(cmd)
    try
        wait(run(`$cmd`))
    catch
        @error "Failed to run command: $cmd" _file=nothing _line=nothing _module=nothing
        throw(BuildError())
    end
end

normpath_s(s) = replace(normpath(s), "\\" => "/")

function depends_on(t::Target, dep::String)
    try
        assure_target(dep)
    finally
        push!(t.deps, dep)
    end
end

function depends_on(t::Target, dep::AbstractVector{String})
    for d in dep
        depends_on(t, d)
    end
end

const _EXCS = Exception[]
const _DEBUG = !isempty(something(get(ENV, "DEBUG", nothing), ""))

function println_errors()
    for e in _EXCS
        showerror(stderr, e)
    end
end

struct BuildError <: Exception end

function assure_target(t::Target)
    async_job = t.task
    if isnothing(async_job)
        async_job = @async begin
            try
                t.build(t)
            catch e
                e isa BuildError && rethrow()
                push!(_EXCS, e)
                throw(BuildError())
            end
        end
        t.task = async_job
    end
    wait(async_job)
end

function assure_target(s::String)
    s = normpath_s(s)
    t = get(_TARGETS, s, nothing)
    isnothing(t) && return

    assure_target(t)
end

function target(f, artifact)
    task = Target(normpath_s(artifact), String[], nothing, f)
    _TARGETS[normpath_s(artifact)] = task
    return task
end

function fglob(suffix::String, root::String=".")
    result = String[]
    i = 0
    for (root, _, files) in collect(Base.Filesystem.walkdir(root))
        abspath(root) == abspath(pwd()) && continue

        for file in files
            if endswith(file, suffix)
                push!(result, normpath_s(joinpath(root, file)))
            end
        end
    end
    return result
end

function host_os()
    if Sys.iswindows()
        return "windows"
    elseif Sys.islinux()
        return "linux"
    elseif Sys.isapple()
        return "macos"
    else
        error("Unsupported platform: $(Sys.KERNEL)")
    end
end

function host_arch()
    arch = Sys.ARCH
    if arch === :x86_64
        return "x64"
    elseif arch === :aarch64
        return "aarch64"
    else
        error("Unsupported architecture: $arch")
    end
end

is_win7() = Sys.iswindows() && Sys.windows_version().major <= 6 && Sys.windows_version().minor <= 1

function load_target_os(os::String)
    isempty(os) || return os
    return get(ENV, "TARGET_OS", host_os())
end

function load_target_arch(arch::String)
    isempty(arch) || return arch
    return get(ENV, "TARGET_ARCH", host_arch())
end

function normalize_os_arch(os::String, arch::String)
    os = lowercase(load_target_os(os))
    arch = lowercase(load_target_arch(arch))
    if os == "win32"
        os = "windows"
    end
    if arch == "arm64"
        arch = "aarch64"
    end
    if arch == "x86_64"
        arch = "x64"
    end
    return os, arch
end

function _is_zig_available()
    try
        return run(pipeline(`zig version`; stderr=IOBuffer(), stdout=IOBuffer())).exitcode == 0
    catch
        return false
    end
end

function find_ctoolchain(os::String, arch::String, details::CToolchainDetails, use_native_compiler::Bool=false)
    is_cross_compilation = os != host_os() || arch != host_arch()

    if use_native_compiler || !_is_zig_available()
        is_cross_compilation &&
            error("Cross-compilation requires Zig to work properly (Windows 7 is not yet supported).")

        cxx = Sys.which("g++")
        cc = Sys.which("gcc")

        if !isnothing(cxx) && !isnothing(cc)
            return CToolchain(
                ["gcc"], ["g++"], ["ar"], ["ranlib"],
                is_cross_compilation, false
            )
        end

        cxx = Sys.which("clang++")
        cc = Sys.which("clang")

        if !isnothing(cxx) && !isnothing(cc)
            return CToolchain(
                ["clang++"], ["clang"], ["llvm-ar"], ["llvm-ranlib"],
                is_cross_compilation, false
            )
        end

        # find bundle mingw if gcc/clang not found in windows
        scc = Sys.which("scc")
        if host_os() == "windows" && !isnothing(scc)
            bundle_mingw = joinpath(dirname(scc), "mingw64", "bin")
            old_PATH = get(ENV, "PATH", "")
            ENV["PATH"] = bundle_mingw * ";" * old_PATH
            cxx = Sys.which("g++")
            cc = Sys.which("gcc")
            if !isnothing(cxx) && !isnothing(cc)
                return CToolchain(
                    ["clang++"], ["clang"], ["llvm-ar"], ["llvm-ranlib"],
                    is_cross_compilation, false
                )
            end
        end
    end

    zig_target = decide_zig_target(os, arch, details)
    return CToolchain(
        ["zig", "cc", "-target", zig_target],
        ["zig", "c++", "-target", zig_target],
        ["zig", "ar"],
        ["zig", "ranlib"],
        is_cross_compilation,
        true
    )
end

function decide_zig_target(os::String, arch::String, details::CToolchainDetails)
    endianness = details.endianness
    glibc_version = details.glibc_version
    libc = details.libc
    hardfloat = details.hardfloat

    if os == "windows"
        if arch == "x64"
            return "x86_64-windows-gnu"
        elseif arch == "x86"
            return "x86-windows-gnu"
        else
            error("Unsupported Windows arch: $(arch)")
        end
    elseif os == "linux"
        if arch == "x64"
            if libc == "glibc"
                return "x86_64-linux-gnu.$glibc_version"
            elseif libc == "musl"
                return "x86_64-linux-musl"
            else
                error("Unsupported libc: $(details.libc)")
            end
        elseif arch == "x86"
            if libc == "glibc"
                return "x86-linux-gnu.$glibc_version"
            elseif libc == "musl"
                return "x86-linux-musl"
            else
                error("Unsupported libc: $(details.libc)")
            end
        elseif arch == "aarch64"
            if endianness == "little"
                if libc == "glibc"
                    return "aarch64-linux-gnu.$glibc_version"
                elseif libc == "musl"
                    return "aarch64-linux-musl"
                else
                    error("Unsupported libc: $(details.libc)")
                end
            else
                if libc == "glibc"
                    return "aarch64_be-linux-gnu.$glibc_version"
                elseif libc == "musl"
                    return "aarch64_be-linux-musl"
                else
                    error("Unsupported libc: $(details.libc)")
                end
            end
        elseif arch == "arm"
            if endianness == "little"
                if hardfloat
                    if libc == "glibc"
                        # TODO: glibc version?
                        return "arm-linux-gnueabihf"
                    else
                        return "arm-linux-musleabihf"
                    end
                else
                    if libc == "glibc"
                        # TODO: glibc version?
                        return "arm-linux-gnueabi"
                    elseif libc == "musl"
                        return "arm-linux-musleabi"
                    else
                        error("Unsupported libc: $(details.libc)")
                    end
                end
            else
                if hardfloat
                    if libc == "glibc"
                        # TODO: glibc version?
                        return "armeb-linux-gnueabihf"
                    else
                        return "armeb-linux-musleabihf"
                    end
                else
                    if libc == "glibc"
                        # TODO: glibc version?
                        return "armeb-linux-gnueabi"
                    elseif libc == "musl"
                        return "armeb-linux-musleabi"
                    else
                        error("Unsupported libc: $(details.libc)")
                    end
                end
            end
        else
            error("Unsupported Linux arch: $(arch)")
        end
    elseif os == "macos"
        if arch == "x64"
            return "x86_64-macos-none"
        elseif arch == "aarch64"
            return "aarch64-macos-none"
        else
            error("Unsupported macOS arch: $(arch)")
        end
    else
        error("Unsupported target: $os-$arch")
    end
end
