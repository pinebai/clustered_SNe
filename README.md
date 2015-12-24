# SNe
Riemann solver with cooling, for the Sedov and cooling phases of a supernova remnant
-------

Author: Eric Gentry   (gentry.e@gmail.com; egentry@ucsc.edu)   

Licensed under the GPLv3.

-------

##Main Objectives
  - Evolve a spherical symmetric blast wave, incorporating hydrodynamics and radiative cooling
    - Achieve accurate and stable results through Sedov and (thin shell) radiative phases
  - Incorporate pre-supernova feedback, to create more realistic initial conditions for the background medium
  - Incorporate multiple supernovae, with realistic delay times and energies
  - Measure the energy and momentum injected into the surrounding medium, to be used as feedback prescriptions in lower resolution galaxy simulations


##Setup
This code will generally not run immediately out of the box.  In addition to the installation of the dependencies below, this code requires a few setup steps:
  - Dependency paths must be set within `src/makefile` (`INC_*` and `LIB_*`)
  - Within the `sedov` directory, `make` should build the executable `sedov3`
    - Only required for visualization

##Requires
  - c++ compiler (assumes clang for OS X, gcc for Linux)
    - should (must?) be c++11 capable
  - [slug2](https://bitbucket.org/krumholz/slug2)
    - slug2 must be built as a shared library (change into the `src` directory and call `make lib`; if you enabled FITS at compile time, then keep it enabled at link time. For simplicity, use `make clean && make lib` in the `src` directory.)
    - requires the [GSL](https://www.gnu.org/software/gsl/), [Boost](http://www.boost.org/)
  - libuuid
  - [grackle cooling](https://bitbucket.org/grackle/grackle)
    - requires [HDF5](https://www.hdfgroup.org/HDF5/release/obtain5.html)
  - For visualization:
    - gfortran
      - Requires quad precision math, but this can be removed
        - Removing quad precision math will result in not being able to generate a sedov solution at small radii (this problem is purely aesthetic
    - Python (tested for v.3.4, probably backwards compatible)
    - IPython/Jupyter (tested for v.4; should be compatible with v.3)
      - ipywidgets (tested for v.4)
    - Matplotlib
    - Bokeh
    - Numpy
    - Astropy
    - Pandas
    - Seaborn
    - Numba

##Acknowledgements
This project built upon [RT1D](https://github.com/duffell/RT1D), an open-source riemann solver from [Paul Duffell](http://duffell.org/).

This project was also includes the `sedov3.f` code of http://cococubed.asu.edu/research_pages/sedov.shtml in order to generate the analytic sedov solution for the purpose of visualization.  While it's not difficult to generate a basic sedov solution, it's difficult to do well. Using `sedov3.f` allows us to avoid worrying about the details of quad precision math ourselves.
