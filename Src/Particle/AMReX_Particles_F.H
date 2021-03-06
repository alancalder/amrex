#ifndef AMREX_Particles_F_H_
#define AMREX_Particles_F_H_

#include <AMReX_BLFort.H>
#include <AMReX_SPACE.H>

#ifdef USE_PARTICLES

#ifdef __cplusplus
extern "C"
{
#endif

    void amrex_particle_set_position (amrex_real*, int ns, int np,
                                      AMREX_D_DECL(const amrex_real* x,
                                             const amrex_real* y,
                                             const amrex_real* z));

    void amrex_particle_get_position (const amrex_real*, int ns, int np,
                                      AMREX_D_DECL(amrex_real* x,
                                             amrex_real* y,
                                             amrex_real* z));

    void amrex_deposit_cic(const amrex_real*, int ns, int np,
                           amrex_real* rho, const int* lo, const int* hi,
                           const amrex_real* plo, const amrex_real* dx);

    void amrex_interpolate_cic(const amrex_real*, int ns, int np,
                               amrex_real* rho, const int* lo, const int* hi, int ncomp,
                               const amrex_real* plo, const amrex_real* dx);

BL_FORT_PROC_DECL(PART_SUMMASSDOWN,part_summassdown)
    (BL_FORT_FAB_ARG(crse_fab),
     const BL_FORT_FAB_ARG(fine_fab),
     const int* ovlo, const int* ovhi, const int* rat);

BL_FORT_PROC_DECL(PART_SUMMASSUP,part_summassup)
    (const BL_FORT_FAB_ARG(crse_fab),
     BL_FORT_FAB_ARG(fine_fab),
     const int* ovlo, const int* ovhi, const int* rat);

BL_FORT_PROC_DECL(PART_SUMDENSUP,part_sumdensup)
    (const BL_FORT_FAB_ARG(crse_fab),
     BL_FORT_FAB_ARG(fine_fab),
     const int* ovlo, const int* ovhi, const int* rat);

#if (BL_SPACEDIM==2)
    BL_FORT_PROC_DECL(BICUBICINTERP,bicubicinterp)
    (const amrex_real* x, const amrex_real* y, const amrex_real* fab,
     const int* lo, const int* hi,
     const amrex_real* plo, const amrex_real* phi, const amrex_real* dx, amrex_real* z);
#endif

#ifdef __cplusplus
};
#endif

#endif

#endif /*_Particles_F_H_*/
