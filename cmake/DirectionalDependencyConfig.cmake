set(DIRECTIONAL_VCPKG_INSTALL_ROOT
    "${CMAKE_SOURCE_DIR}/.deps"
    CACHE PATH "Directory used for Directional-managed vcpkg installs")
set(DIRECTIONAL_VCPKG_TRIPLET
    "xw"
    CACHE STRING
          "Primary vcpkg triplet used by Directional auto-install on Windows")
set(_directional_known_triplets x64-windows "${DIRECTIONAL_VCPKG_TRIPLET}")
set(_directional_suitesparse_components
    suitesparseconfig
    amd
    btf
    camd
    ccolamd
    cholmod
    colamd
    cxsparse
    klu
    ldl
    umfpack
    openblas)
set(_directional_suitesparse_metis_components
    spqr
    blas
    lapack
    quadmath
    gfortran
    libgcc_s_sjlj)

if(DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
  set(_directional_tutorials_exclude
      quadmath
      gfortran
      libgcc_s_sjlj)
else()
  set(_directional_tutorials_exclude)
endif()