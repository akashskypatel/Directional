function(_directional_collect_windows_runtime_files out_var)
  set(options)
  set(one_value_args)
  set(multi_value_args CANDIDATES PATTERNS)
  cmake_parse_arguments(PARSE_ARGV 1 _runtime "${options}" "${one_value_args}" "${multi_value_args}")

  set(_runtime_files)
  foreach(_candidate_dir IN LISTS _runtime_CANDIDATES)
    if(EXISTS "${_candidate_dir}")
      set(_candidate_patterns)
      foreach(_pattern IN LISTS _runtime_PATTERNS)
        list(APPEND _candidate_patterns "${_candidate_dir}/${_pattern}")
      endforeach()
      file(GLOB _candidate_files ${_candidate_patterns})
      list(APPEND _runtime_files ${_candidate_files})
    endif()
  endforeach()

  list(REMOVE_DUPLICATES _runtime_files)
  set(${out_var} "${_runtime_files}" PARENT_SCOPE)
endfunction()

function(_directional_collect_suitesparse_runtime_files out_var)
  set(_runtime_candidates)

  if(WIN32)
    if(SUITESPARSE_LIBRARIES)
      get_filename_component(_suitesparse_library_dir "${SUITESPARSE_LIBRARIES}" DIRECTORY)
      list(APPEND _runtime_candidates
        "${_suitesparse_library_dir}"
        "${_suitesparse_library_dir}/../bin"
        "${_suitesparse_library_dir}/../debug/bin"
      )
    endif()

    _directional_append_vcpkg_paths(_runtime_candidates "bin" "debug/bin")
    list(APPEND _runtime_candidates
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/packages/suitesparse_x64-windows/bin"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/installed/x64-windows/bin"
    )

    _directional_collect_windows_runtime_files(${out_var}
      CANDIDATES ${_runtime_candidates}
      PATTERNS
        "amd*.dll"
        "btf*.dll"
        "camd*.dll"
        "ccolamd*.dll"
        "cholmod*.dll"
        "colamd*.dll"
        "klu*.dll"
        "ldl*.dll"
        "metis*.dll"
        "openblas*.dll"
        "spqr*.dll"
        "SuiteSparse*.dll"
        "suitesparseconfig*.dll"
        "umfpack*.dll"
    )
  else()
    set(${out_var} "" PARENT_SCOPE)
  endif()
endfunction()

function(_directional_collect_gmp_runtime_files out_var)
  set(_runtime_candidates)

  if(WIN32)
    if(GMP_LIBRARIES)
      get_filename_component(_gmp_library_dir "${GMP_LIBRARIES}" DIRECTORY)
      list(APPEND _runtime_candidates
        "${_gmp_library_dir}"
        "${_gmp_library_dir}/../bin"
        "${_gmp_library_dir}/../debug/bin"
      )
    endif()

    _directional_append_vcpkg_paths(_runtime_candidates "bin" "debug/bin")
    list(APPEND _runtime_candidates
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/packages/gmp_x64-windows/bin"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/installed/x64-windows/bin"
    )

    _directional_collect_windows_runtime_files(${out_var}
      CANDIDATES ${_runtime_candidates}
      PATTERNS
        "gmp*.dll"
        "gmpxx*.dll"
    )
  else()
    set(${out_var} "" PARENT_SCOPE)
  endif()
endfunction()
