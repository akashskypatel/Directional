function(_directional_find_gmp)
  if(TARGET GMP::GMP)
    get_target_property(_existing_gmp_includes GMP::GMP
                        INTERFACE_INCLUDE_DIRECTORIES)

    message(STATUS "Using existing GMP::GMP; interface includes: "
                   "${_existing_gmp_includes}")
    return()
  endif()

  if(TARGET GMP::GMPXX)
    get_target_property(_existing_gmpxx_includes GMP::GMPXX
                        INTERFACE_INCLUDE_DIRECTORIES)

    message(STATUS "Using existing GMP::GMPXX; interface includes: "
                   "${_existing_gmpxx_includes}")
    return()
  endif()

  set(_directional_gmp_include_hints
      "${CMAKE_SOURCE_DIR}/.deps" "$ENV{GMP_DIR}/include" /usr/include
      /usr/local/include /opt/homebrew/include "C:/Program Files/GMP/include")

  _directional_append_vcpkg_paths(_directional_gmp_include_hints "gmp"
                                  "include" "include/gmp")

  set(_directional_gmp_library_hints
      "${CMAKE_SOURCE_DIR}/.deps" "$ENV{GMP_DIR}/lib" /usr/lib /usr/local/lib
      /opt/homebrew/lib "C:/Program Files/GMP/lib")

  _directional_append_vcpkg_paths(_directional_gmp_library_hints "gmp" "bin"
                                  "lib" "debug/lib" "debug/bin")

  find_path(
    GMP_INCLUDE_DIR
    NAMES gmp.h gmpxx.h
    HINTS ${_directional_gmp_include_hints})

  if(EXISTS ${GMP_INCLUDE_DIR})
    message(STATUS "GMP include directory found: ${GMP_INCLUDE_DIR}")
  else()
    message(WARNING "GMP include directory not found")
  endif()

  find_library(
    GMP_LIBRARY
    NAMES gmp libgmp
    HINTS ${_directional_gmp_library_hints})

  find_library(
    GMPXX_LIBRARY
    NAMES gmpxx libgmpxx
    HINTS ${_directional_gmp_library_hints})

  if(WIN32)
    _directional_append_vcpkg_paths(_directional_gmp_runtime_hints "gmp" "bin"
                                    "debug/bin")

    _directional_find_file(
      GMP_RUNTIME_LIBRARY
      PATTERNS
      "gmp.dll"
      "libgmp.dll"
      "gmp-*.dll"
      "libgmp-*.dll"
      DIRECTORIES
      ${_directional_gmp_runtime_hints})

    if(EXISTS ${GMP_RUNTIME_LIBRARY})
      message(STATUS "GMP runtime library found: ${GMP_RUNTIME_LIBRARY}")
    else()
      message(WARNING "GMP runtime library not found")
    endif()

    _directional_find_file(
      GMPXX_RUNTIME_LIBRARY
      PATTERNS
      "gmpxx.dll"
      "libgmpxx.dll"
      "gmpxx-*.dll"
      "libgmpxx-*.dll"
      DIRECTORIES
      ${_directional_gmp_runtime_hints})

    if(EXISTS ${GMPXX_RUNTIME_LIBRARY})
      message(STATUS "GMPXX runtime library found: ${GMPXX_RUNTIME_LIBRARY}")
    else()
      message(WARNING "GMPXX runtime library not found")
    endif()
  endif()

  include(FindPackageHandleStandardArgs)

  if(WIN32)
    find_package_handle_standard_args(
      GMP REQUIRED_VARS GMP_INCLUDE_DIR GMP_LIBRARY GMP_RUNTIME_LIBRARY)
    find_package_handle_standard_args(
      GMPXX REQUIRED_VARS GMP_INCLUDE_DIR GMPXX_LIBRARY GMPXX_RUNTIME_LIBRARY)
  else()
    find_package_handle_standard_args(GMP REQUIRED_VARS GMP_INCLUDE_DIR
                                                        GMP_LIBRARY)
    find_package_handle_standard_args(GMPXX REQUIRED_VARS GMP_INCLUDE_DIR
                                                          GMPXX_LIBRARY)
  endif()

  if(WIN32)
    add_library(GMP::GMP SHARED IMPORTED GLOBAL)

    set_target_properties(
      GMP::GMP
      PROPERTIES IMPORTED_CONFIGURATIONS RELEASE
                 IMPORTED_IMPLIB_RELEASE "${GMP_LIBRARY}"
                 IMPORTED_LOCATION_RELEASE "${GMP_RUNTIME_LIBRARY}"
                 MAP_IMPORTED_CONFIG_DEBUG RELEASE
                 MAP_IMPORTED_CONFIG_RELEASE RELEASE
                 MAP_IMPORTED_CONFIG_MINSIZEREL RELEASE
                 MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)
    add_library(GMP::GMPXX SHARED IMPORTED GLOBAL)

    set_target_properties(
      GMP::GMPXX
      PROPERTIES IMPORTED_CONFIGURATIONS RELEASE
                 IMPORTED_IMPLIB_RELEASE "${GMPXX_LIBRARY}"
                 IMPORTED_LOCATION_RELEASE "${GMPXX_RUNTIME_LIBRARY}"
                 MAP_IMPORTED_CONFIG_DEBUG RELEASE
                 MAP_IMPORTED_CONFIG_RELEASE RELEASE
                 MAP_IMPORTED_CONFIG_MINSIZEREL RELEASE
                 MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)
  else()
    add_library(GMP::GMP UNKNOWN IMPORTED GLOBAL)
    add_library(GMP::GMPXX UNKNOWN IMPORTED GLOBAL)

    set_target_properties(GMP::GMP PROPERTIES IMPORTED_LOCATION
                                              "${GMP_LIBRARY}")

    set_target_properties(GMP::GMPXX PROPERTIES IMPORTED_LOCATION
                                                "${GMPXX_LIBRARY}")
  endif()

  target_include_directories(GMP::GMP INTERFACE "${GMP_INCLUDE_DIR}")

  target_include_directories(GMP::GMPXX INTERFACE "${GMP_INCLUDE_DIR}")

  get_target_property(_gmp_interface_includes GMP::GMP
                      INTERFACE_INCLUDE_DIRECTORIES)

  get_target_property(_gmpxx_interface_includes GMP::GMPXX
                      INTERFACE_INCLUDE_DIRECTORIES)

  message(STATUS "GMP include directory: ${GMP_INCLUDE_DIR}")
  message(STATUS "GMP link library: ${GMP_LIBRARY}")
  message(STATUS "GMP target interface includes: ${_gmp_interface_includes}")
  message(STATUS "GMPXX include directory: ${GMP_INCLUDE_DIR}")
  message(STATUS "GMPXX link library: ${GMPXX_LIBRARY}")
  message(
    STATUS "GMPXX target interface includes: ${_gmpxx_interface_includes}")

  if(WIN32)
    message(STATUS "GMP runtime DLL: ${GMP_RUNTIME_LIBRARY}")
    message(STATUS "GMPXX runtime DLL: ${GMPXX_RUNTIME_LIBRARY}")
  endif()

  mark_as_advanced(GMP_INCLUDE_DIR GMP_LIBRARY GMP_RUNTIME_LIBRARY
                   GMP_INCLUDE_DIR GMPXX_LIBRARY GMPXX_RUNTIME_LIBRARY)
endfunction()

function(_directional_try_autoinstall_gmp)
  if(MSVC)
    _directional_enable_vcpkg(_directional_vcpkg_exe)
    _directional_install_vcpkg(PACKAGES "gmp")
  elseif(APPLE)
    find_program(_directional_brew_exe brew)
    if(_directional_brew_exe)
      message(STATUS "GMP not found. Attempting auto-install via Homebrew.")
      execute_process(COMMAND "${_directional_brew_exe}" install gmp
                      RESULT_VARIABLE _directional_brew_result)
      if(_directional_brew_result EQUAL 0)
        execute_process(
          COMMAND "${_directional_brew_exe}" --prefix gmp
          OUTPUT_VARIABLE _directional_brew_prefix
          OUTPUT_STRIP_TRAILING_WHITESPACE
          RESULT_VARIABLE _directional_brew_prefix_result)
        if(_directional_brew_prefix_result EQUAL 0
           AND EXISTS "${_directional_brew_prefix}")
          list(APPEND CMAKE_PREFIX_PATH "${_directional_brew_prefix}")
          set(CMAKE_PREFIX_PATH
              "${CMAKE_PREFIX_PATH}"
              PARENT_SCOPE)
          message(STATUS "Homebrew GMP install completed successfully.")
        endif()
      else()
        message(
          WARNING
            "Homebrew GMP auto-install failed with exit code ${_directional_brew_result}."
        )
      endif()
    else()
      message(STATUS "GMP not found and Homebrew is unavailable.")
    endif()
  endif()
endfunction()
