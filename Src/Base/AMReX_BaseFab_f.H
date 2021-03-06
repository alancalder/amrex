#ifndef BASEFAB_F_H_
#define BASEFAB_F_H_

#include <AMReX_REAL.H>
#include <AMReX_ArrayLim.H>

#ifdef __cplusplus
extern "C"
{
#endif
    void fort_fab_copy (const int* lo, const int* hi,
			amrex_real* dst, const int* dlo, const int* dhi,
			const amrex_real* src, const int* slo, const int* shi, const int* sblo,
			const int* ncomp);

    long fort_fab_copytomem (const int* lo, const int* hi,
                             amrex_real* dst,
                             const amrex_real* src, const int* slo, const int* shi,
                             const int* ncomp);

    long fort_fab_copyfrommem (const int* lo, const int* hi,
                               const amrex_real* dst, const int* dlo, const int* dhi, const int* ncomp,
                               const amrex_real* src);

    void fort_fab_setval (const int* lo, const int* hi, 
			  const amrex_real* dst, const int* dlo, const int* dhi, const int* ncomp,
			  const amrex_real* val);

    amrex_real fort_fab_norm (const int* lo, const int* hi,
			const amrex_real* src, const int* slo, const int* shi, const int* ncomp,
			const int* p);

    amrex_real fort_fab_sum (const int* lo, const int* hi,
		       const amrex_real* src, const int* slo, const int* shi, const int* ncomp);

    void fort_fab_plus (const int* lo, const int* hi,
			amrex_real* dst, const int* dlo, const int* dhi,
			const amrex_real* src, const int* slo, const int* shi, const int* sblo,
			const int* ncomp);    

    void fort_fab_minus (const int* lo, const int* hi,
			 amrex_real* dst, const int* dlo, const int* dhi,
			 const amrex_real* src, const int* slo, const int* shi, const int* sblo,
			 const int* ncomp);    

    void fort_fab_mult (const int* lo, const int* hi,
			amrex_real* dst, const int* dlo, const int* dhi,
			const amrex_real* src, const int* slo, const int* shi, const int* sblo,
			const int* ncomp);    

    void fort_fab_divide (const int* lo, const int* hi,
			  amrex_real* dst, const int* dlo, const int* dhi,
			  const amrex_real* src, const int* slo, const int* shi, const int* sblo,
			  const int* ncomp);    

    void fort_fab_protdivide (const int* lo, const int* hi,
			      amrex_real* dst, const int* dlo, const int* dhi,
			      const amrex_real* src, const int* slo, const int* shi, const int* sblo,
			      const int* ncomp);        

    void fort_fab_invert (const int* lo, const int* hi,
			  amrex_real* dst, const int* dlo, const int* dhi, const int* ncomp,
			  const amrex_real* a);

    void fort_fab_saxpy (const int* lo, const int* hi,
			 amrex_real* dst, const int* dlo, const int* dhi,
			 const amrex_real* a,
			 const amrex_real* src, const int* slo, const int* shi, const int* sblo,
			 const int* ncomp);

    void fort_fab_xpay (const int* lo, const int* hi,
			amrex_real* dst, const int* dlo, const int* dhi,
			const amrex_real* a,
			const amrex_real* src, const int* slo, const int* shi, const int* sblo,
			const int* ncomp);

    void fort_fab_lincomb (const int* lo, const int* hi,
			   amrex_real* dst, const int* dlo, const int* dhi,
			   const amrex_real* a, const amrex_real* x, const int* xlo, const int* xhi, const int* xblo,
			   const amrex_real* b, const amrex_real* y, const int* ylo, const int* yhi, const int* yblo,
			   const int* ncomp);

    void fort_fab_addproduct (const int* lo, const int* hi,
			      amrex_real* dst, const int* dlo, const int* dhi,
			      const amrex_real* src1, const int* s1lo, const int* s1hi,
			      const amrex_real* src2, const int* s2lo, const int* s2hi,
			      const int* ncomp);

    amrex_real fort_fab_dot (const int* lo, const int* hi,
		       const amrex_real* x, const int* xlo, const int* xhi,
		       const amrex_real* y, const int* ylo, const int* yhi, const int* yblo,
		       const int* ncomp);
#ifdef __cplusplus
}
#endif

#endif
