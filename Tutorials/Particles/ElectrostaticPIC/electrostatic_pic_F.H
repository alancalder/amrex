#ifndef AMREX_COMPUTE_FORCE_F_H_
#define AMREX_COMPUTE_FORCE_F_H_

#include <AMReX_BLFort.H>

#ifdef __cplusplus
extern "C"
{
#endif

    void compute_E_nodal (const int* lo, const int* hi,
                          const amrex::Real* phi,
                          amrex::Real* Ex, amrex::Real* Ey, 
                          amrex::Real* Ez, const amrex::Real* dx);
    
    void deposit_cic(const amrex::Real* particles, int ns, int np,
                     const amrex::Real* weights, 
                     const amrex::Real* charge,
                     amrex::Real* rho, const int* lo, const int* hi,
                     const amrex::Real* plo, const amrex::Real* dx,
                     const int* ng);
    
    void interpolate_cic(const amrex::Real* particles, int ns, int np,
                         amrex::Real* Ex_p, amrex::Real* Ey_p, amrex::Real* Ez_p,
                         const amrex::Real* Ex, const amrex::Real* Ey, const amrex::Real* Ez,
                         const int* lo, const int* hi,
                         const amrex::Real* plo, const amrex::Real* dx,
                         const int* ng);

    void push_leapfrog(amrex::Real* particles, int ns, int np, 
                       amrex::Real* vx_p, amrex::Real* vy_p, amrex::Real* vz_p,
                       const amrex::Real* Ex_p, const amrex::Real* Ey_p, const amrex::Real* Ez_p,
                       const amrex::Real* charge, const amrex::Real* mass, const amrex::Real* dt,
                       const amrex::Real* prob_lo, const amrex::Real* prob_hi);

    void push_leapfrog_positions(amrex::Real* particles, int ns, int np, 
                                 const amrex::Real* vx_p, const amrex::Real* vy_p, 
                                 const amrex::Real* vz_p, const amrex::Real* dt,
                                 const amrex::Real* prob_lo, const amrex::Real* prob_hi);

#ifdef __cplusplus
}
#endif

#endif /* _COMPUTE_FORCE_F_H_ */
