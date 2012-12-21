  FCOMP_VERSION := $(shell $(COMP) -v 2>&1 | grep 'version')

  FC  := $(ROSECOMP)
  F90 := $(ROSECOMP)
  ifdef CCOMP
    CC  := $(ROSECCOMP)
  else
    CC  := gcc
  endif

  F90FLAGS += -J$(mdir) -I$(mdir)
  FFLAGS   += -J$(mdir) -I$(mdir)
  CFLAGS   += -Wall

  ifdef NDEBUG
    F90FLAGS += -O2 -fno-range-check
    FFLAGS   += -O2 -fno-range-check
    CFLAGS   += -O2
  else
    F90FLAGS += -g -fno-range-check -O1 -fbounds-check -fbacktrace -Wuninitialized -Wunused -ffpe-trap=invalid -finit-real=nan
    FFLAGS   += -g -fno-range-check -O1 -fbounds-check -fbacktrace -Wuninitialized -Wunused -ffpe-trap=invalid -finit-real=nan
    CFLAGS   += -g -O1
  endif

  ifdef OMP
    F90FLAGS += -fopenmp
    FFLAGS   += -fopenmp
    CFLAGS   += -fopenmp
  endif

  ifdef GPROF
    F90FLAGS += -pg
    FFLAGS   += -pg
    CFLAGS   += -pg
  endif