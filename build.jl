function simulate!(pU::Ptr{Cdouble}, pu::Ptr{Cdouble}, Nx, Ny, Nt, α, dx, dy, dt)
    try
        U = unsafe_wrap(Array, pU, (Nx, Ny, Nt); own=false)
        u = unsafe_wrap(Array, pu, (Nx, Ny); own=false)
        simulate!(U, u, Nx, Ny, Nt, α, dx, dy, dt)
        return true
    catch
        return false
    end
end

function simulate!(U::Array, u::Matrix, Nx, Ny, Nt, α, dx, dy, dt)
    u = reshape(u, size(u)..., 1)
    u = @view u[:, :, 1]

    # 有限差分法的时间迭代
    for n in 1:Nt
        u_new = @view U[:, :, n]
        u_new .= u
        for i in 2:(Nx-1)
            for j in 2:(Ny-1)
                u_new[i, j] = u[i, j] + α * dt / dx^2 * (u[i+1, j] - 2 * u[i, j] + u[i-1, j]) +
                              α * dt / dy^2 * (u[i, j+1] - 2 * u[i, j] + u[i, j-1])
            end
        end
        u = u_new
    end
end

@static if @isdefined(SyslabCC)
    SyslabCC.static_compile(
        "simulate", simulate!,
        Ptr{Cdouble}, Ptr{Cdouble},         # U 和 u
        Int64, Int64, Int64,                # Nx, Ny, Nt
        Cdouble, Cdouble, Cdouble, Cdouble, # α, dx, dy, dt
    )
end
