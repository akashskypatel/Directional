function(_directional_find_suitesparse)
  set(_directional_suitesparse_include_hints
    $ENV{SUITESPARSE_DIR}/include
    ${CMAKE_PREFIX_PATH}/include
    /usr/include
    /usr/local/include
    /opt/homebrew/include
    "C:/Program Files/SuiteSparse/include"
  )
  _directional_append_vcpkg_paths(_directional_suitesparse_include_hints "include" "include/suitesparse")

  set(_directional_suitesparse_library_hints
    $ENV{SUITESPARSE_DIR}/lib
    ${CMAKE_PREFIX_PATH}/lib
    /usr/lib
    /usr/local/lib
    /opt/homebrew/lib
    "C:/Program Files/SuiteSparse/lib"
  )
  _directional_append_vcpkg_paths(_directional_suitesparse_library_hints "lib" "debug/lib" "bin" "debug/bin")

  find_path(SUITESPARSE_INCLUDE_DIR
    NAMES
      suitesparse/SuiteSparse_config.h
      suitesparse/suitesparseconfig.h
    HINTS ${_directional_suitesparse_include_hints}
  )

  find_path(SUITESPARSE_UMFPACK_INCLUDE_DIR
    NAMES
      suitesparse/umfpack.h
      umfpack.h
    HINTS ${_directional_suitesparse_include_hints}
  )

  set(_directional_suitesparse_libraries)
  foreach(_directional_suitesparse_component IN LISTS _directional_suitesparse_components)
    unset(_directional_suitesparse_component_path CACHE)
    unset(_directional_suitesparse_component_path)
    find_library(_directional_suitesparse_component_path
      NAMES ${_directional_suitesparse_component}
      HINTS ${_directional_suitesparse_library_hints}
    )
    if(_directional_suitesparse_component_path)
      list(APPEND _directional_suitesparse_libraries "${_directional_suitesparse_component_path}")
    endif()
  endforeach()

  set(SUITESPARSE_LIBRARIES "${_directional_suitesparse_libraries}")
  set(SUITESPARSE_INCLUDE_DIR "${SUITESPARSE_INCLUDE_DIR}" PARENT_SCOPE)
  set(SUITESPARSE_UMFPACK_INCLUDE_DIR "${SUITESPARSE_UMFPACK_INCLUDE_DIR}" PARENT_SCOPE)
  set(SUITESPARSE_LIBRARIES "${SUITESPARSE_LIBRARIES}" PARENT_SCOPE)
endfunction()

function(_directional_find_gmp)
  set(_directional_gmp_include_hints
    $ENV{GMP_DIR}/include
    ${CMAKE_PREFIX_PATH}/include
    /usr/include
    /usr/local/include
    /opt/homebrew/include
    "C:/Program Files/GMP/include"
  )
  _directional_append_vcpkg_paths(_directional_gmp_include_hints "include" "include/gmp")

  set(_directional_gmp_library_hints
    $ENV{GMP_DIR}/lib
    ${CMAKE_PREFIX_PATH}/lib
    /usr/lib
    /usr/local/lib
    /opt/homebrew/lib
    "C:/Program Files/GMP/lib"
  )
  _directional_append_vcpkg_paths(_directional_gmp_library_hints "lib" "debug/lib" "bin" "debug/bin")

  find_path(GMP_INCLUDE_DIR
    NAMES gmp.h
    HINTS ${_directional_gmp_include_hints}
  )

  find_library(GMP_LIBRARIES
    NAMES gmp libgmp
    HINTS ${_directional_gmp_library_hints}
  )

  set(GMP_INCLUDE_DIR "${GMP_INCLUDE_DIR}" PARENT_SCOPE)
  set(GMP_LIBRARIES "${GMP_LIBRARIES}" PARENT_SCOPE)
endfunction()

function(_directional_try_autoinstall_gmp)
  if(NOT DIRECTIONAL_AUTO_INSTALL_GMP)
    return()
  endif()

  if(MSVC)
    _directional_enable_vcpkg(_directional_vcpkg_exe)
    _directional_install_vcpkg("gmp")
  elseif(APPLE)
    find_program(_directional_brew_exe brew)
    if(_directional_brew_exe)
      message(STATUS "GMP not found. Attempting auto-install via Homebrew.")
      execute_process(
        COMMAND "${_directional_brew_exe}" install gmp
        RESULT_VARIABLE _directional_brew_result
      )
      if(_directional_brew_result EQUAL 0)
        execute_process(
          COMMAND "${_directional_brew_exe}" --prefix gmp
          OUTPUT_VARIABLE _directional_brew_prefix
          OUTPUT_STRIP_TRAILING_WHITESPACE
          RESULT_VARIABLE _directional_brew_prefix_result
        )
        if(_directional_brew_prefix_result EQUAL 0 AND EXISTS "${_directional_brew_prefix}")
          list(APPEND CMAKE_PREFIX_PATH "${_directional_brew_prefix}")
          set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
          message(STATUS "Homebrew GMP install completed successfully.")
        endif()
      else()
        message(WARNING "Homebrew GMP auto-install failed with exit code ${_directional_brew_result}.")
      endif()
    else()
      message(STATUS "GMP not found and Homebrew is unavailable.")
    endif()
  endif()
endfunction()

function(_directional_try_autoinstall_suitesparse)
  if(MSVC)
    _directional_enable_vcpkg(_directional_vcpkg_exe)
    _directional_install_vcpkg("suitesparse-config;suitesparse-amd;suitesparse-btf;suitesparse-camd;suitesparse-ccolamd;suitesparse-cholmod;suitesparse-colamd;suitesparse-cxsparse;suitesparse-klu;suitesparse-ldl;suitesparse-umfpack")
  elseif(APPLE)
    find_program(_directional_brew_exe brew)
    if(_directional_brew_exe)
      message(STATUS "SuiteSparse not found. Attempting auto-install via Homebrew.")
      execute_process(
        COMMAND "${_directional_brew_exe}" install suitesparse
        RESULT_VARIABLE _directional_brew_result
      )
      if(_directional_brew_result EQUAL 0)
        execute_process(
          COMMAND "${_directional_brew_exe}" --prefix suitesparse
          OUTPUT_VARIABLE _directional_brew_prefix
          OUTPUT_STRIP_TRAILING_WHITESPACE
          RESULT_VARIABLE _directional_brew_prefix_result
        )
        if(_directional_brew_prefix_result EQUAL 0 AND EXISTS "${_directional_brew_prefix}")
          list(APPEND CMAKE_PREFIX_PATH "${_directional_brew_prefix}")
          set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
          message(STATUS "Homebrew SuiteSparse install completed successfully.")
        endif()
      else()
        message(WARNING "Homebrew SuiteSparse auto-install failed with exit code ${_directional_brew_result}.")
      endif()
    else()
      message(STATUS "SuiteSparse not found and Homebrew is unavailable.")
    endif()
  endif()
endfunction()
