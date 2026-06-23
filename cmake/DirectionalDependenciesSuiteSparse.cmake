function(_directional_find_suitesparse)
  unset(DIRECTIONAL_SUITESPARSE_CONFIG_FOUND PARENT_SCOPE)
  if(NOT MSVC)
    include(FindSuiteSparse)
    find_package(SuiteSparse REQUIRED)
    message(STATUS "Found SuiteSparse: ${SuiteSparse_FOUND}")
    return()
  endif()

  if(SuiteSparse_FOUND AND TARGET SuiteSparse::umfpack)
    message(STATUS "Found SuiteSparse CMake config package: ${SuiteSparse_DIR}")
    set(DIRECTIONAL_SUITESPARSE_CONFIG_FOUND
        TRUE
        PARENT_SCOPE)
    return()
  endif()

  if(SuiteSparse_FOUND AND TARGET SuiteSparse::umfpack)
    message(STATUS "Found SuiteSparse CMake config package")
    set(DIRECTIONAL_SUITESPARSE_CONFIG_FOUND
        TRUE
        PARENT_SCOPE)
    return()
  endif()
  set(_directional_suitesparse_include_hints "${CMAKE_SOURCE_DIR}/.deps/suitesparse")
  set(_directional_suitesparse_library_hints "${CMAKE_SOURCE_DIR}/.deps/suitesparse")
  set(_include_patterns)
  get_target_architecture(_ss_arch)
  _directional_append_vcpkg_paths(_directional_suitesparse_include_hints
                                  "suitesparse" "include" "include/suitesparse")
  _directional_append_vcpkg_paths(
    _directional_suitesparse_library_hints "suitesparse" "bin" "lib"
    "debug/lib" "debug/bin")

  if(WIN32)
    set(_directional_suitesparse_libraries)
    if(NOT TARGET SuiteSparse::openblas)
      add_library(SuiteSparse::openblas SHARED IMPORTED GLOBAL)
      set(_directional_openblas_library_hints "${CMAKE_SOURCE_DIR}/.deps/openblas")
      _directional_find_file(
        SUITESPARSE_OPENBLAS_DLL
        PATTERNS
        "openblas.dll"
        "libopenblas.dll"
        "openblas-*.dll"
        "libopenblas-*.dll"
        DIRECTORIES
        ${_directional_openblas_library_hints})
      _directional_find_file(
        SUITESPARSE_OPENBLAS_LIB
        PATTERNS
        "openblas.lib"
        "libopenblas.lib"
        "openblas-*.lib"
        "libopenblas-*.lib"
        DIRECTORIES
        ${_directional_openblas_library_hints})
      set(_directional_openblas_include_hints 
        "${CMAKE_SOURCE_DIR}/.deps/openblas")

      _directional_append_vcpkg_paths(_directional_openblas_include_hints
                                      "openblas" "include" "include/openblas")
      _directional_find_directory(
        SUITESPARSE_OPENBLAS_INCLUDE PATTERNS "openblas/xw/include" DIRECTORIES
        ${_directional_openblas_include_hints})
      if(SUITESPARSE_OPENBLAS_INCLUDE MATCHES
         "SUITESPARSE_OPENBLAS_INCLUDE-NOTFOUND$" 
         OR SUITESPARSE_OPENBLAS_DLL MATCHES "SUITESPARSE_OPENBLAS_DLL-NOTFOUND$")
        message(WARNING "SuiteSparse::openblas libraries or include directory not found")
        return()
      endif()
      set_target_properties(
        SuiteSparse::openblas
        PROPERTIES IMPORTED_CONFIGURATIONS RELEASE
                   IMPORTED_IMPLIB_RELEASE "${SUITESPARSE_OPENBLAS_LIB}"
                   IMPORTED_LOCATION_RELEASE "${SUITESPARSE_OPENBLAS_DLL}"
                   MAP_IMPORTED_CONFIG_DEBUG RELEASE
                   MAP_IMPORTED_CONFIG_RELEASE RELEASE
                   MAP_IMPORTED_CONFIG_MINSIZEREL RELEASE
                   MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)
      target_include_directories(SuiteSparse::openblas
                                 INTERFACE "${SUITESPARSE_OPENBLAS_INCLUDE}")
      if(TARGET SuiteSparse::openblas)
        list(APPEND SUITESPARSE_TARGETS "SuiteSparse::openblas")
        message(STATUS "Added SuiteSparse::openblas to SUITESPARSE_TARGETS")
        message(
          STATUS
            "SuiteSparse::openblas include directory: ${SUITESPARSE_OPENBLAS_INCLUDE}"
        )
        message(
          STATUS
            "SuiteSparse::openblas link library: ${SUITESPARSE_OPENBLAS_LIB}")
        message(
          STATUS
            "SuiteSparse::openblas runtime library: ${SUITESPARSE_OPENBLAS_DLL}"
        )
      endif()
    endif()
    if(NOT TARGET SuiteSparse::suitesparseconfig)
      add_library(SuiteSparse::suitesparseconfig SHARED IMPORTED GLOBAL)
      _directional_find_file(
        SUITESPARSE_SUITESPARSECONFIG_DLL
        PATTERNS
        "suitesparseconfig.dll"
        "libsuitesparseconfig.dll"
        "suitesparseconfig-*.dll"
        "libsuitesparseconfig-*.dll"
        DIRECTORIES
        ${_directional_suitesparse_library_hints})
      _directional_find_file(
        SUITESPARSE_SUITESPARSECONFIG_LIB
        PATTERNS
        "suitesparseconfig.lib"
        "libsuitesparseconfig.lib"
        "suitesparseconfig-*.lib"
        "libsuitesparseconfig-*.lib"
        DIRECTORIES
        ${_directional_suitesparse_library_hints})
      _directional_find_directory(
        SUITESPARSE_SUITESPARSECONFIG_INCLUDE PATTERNS
        "suitesparse-config/xw/include" DIRECTORIES
        ${_directional_suitesparse_library_hints})
      if(SUITESPARSE_SUITESPARSECONFIG_INCLUDE MATCHES
         "SUITESPARSE_SUITESPARSECONFIG_INCLUDE-NOTFOUND$" 
         OR SUITESPARSE_SUITESPARSECONFIG_DLL MATCHES "SUITESPARSE_SUITESPARSECONFIG_DLL-NOTFOUND$")
        message(WARNING "SuiteSparse::suitesparseconfig libraries or include directory not found")
        return()
      endif()
      set_target_properties(
        SuiteSparse::suitesparseconfig
        PROPERTIES IMPORTED_CONFIGURATIONS RELEASE
                   IMPORTED_IMPLIB_RELEASE
                   "${SUITESPARSE_SUITESPARSECONFIG_LIB}"
                   IMPORTED_LOCATION_RELEASE
                   "${SUITESPARSE_SUITESPARSECONFIG_DLL}"
                   MAP_IMPORTED_CONFIG_DEBUG RELEASE
                   MAP_IMPORTED_CONFIG_RELEASE RELEASE
                   MAP_IMPORTED_CONFIG_MINSIZEREL RELEASE
                   MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE)
      target_include_directories(
        SuiteSparse::suitesparseconfig
        INTERFACE "${SUITESPARSE_SUITESPARSECONFIG_INCLUDE}")
      if(TARGET SuiteSparse::suitesparseconfig)
        list(APPEND SUITESPARSE_TARGETS "SuiteSparse::suitesparseconfig")
        message(
          STATUS "Added SuiteSparse::suitesparseconfig to SUITESPARSE_TARGETS")
        message(
          STATUS
            "SuiteSparse::suitesparseconfig include directory: ${SUITESPARSE_SUITESPARSECONFIG_INCLUDE}"
        )
        message(
          STATUS
            "SuiteSparse::suitesparseconfig link library: ${SUITESPARSE_SUITESPARSECONFIG_LIB}"
        )
        message(
          STATUS
            "SuiteSparse::suitesparseconfig runtime library: ${SUITESPARSE_SUITESPARSECONFIG_DLL}"
        )
      endif()
    endif()
    foreach(_component IN LISTS _directional_suitesparse_components)
      if(_component STREQUAL "openblas"
         OR _component STREQUAL "suitesparseconfig"
         OR TARGET SuiteSparse::${_component})
        continue()
      endif()
      unset(_component_path CACHE)
      unset(_component_path)
      _directional_find_file(
        SUITESPARSE_${_component}_DLL
        PATTERNS
        "${_component}.dll"
        "lib${_component}.dll"
        "${_component}-*.dll"
        "lib${_component}-*.dll"
        DIRECTORIES
        ${_directional_suitesparse_library_hints})
      _directional_find_file(
        SUITESPARSE_${_component}_LIB
        PATTERNS
        "${_component}.lib"
        "lib${_component}.lib"
        "${_component}-*.lib"
        "lib${_component}-*.lib"
        DIRECTORIES
        ${_directional_suitesparse_library_hints})
      if(SUITESPARSE_${_component}_DLL)
        list(APPEND _directional_suitesparse_libraries
             "${SUITESPARSE_${_component}_DLL}")
      endif()
      _directional_find_directory(
        SUITESPARSE_${_component}_INCLUDE
        PATTERNS
        "suitesparse-${_component}/xw/include"
        DIRECTORIES
        ${_directional_suitesparse_library_hints})
      if(SUITESPARSE_${_component}_INCLUDE)
        list(APPEND _directional_suitesparse_includes
             "${SUITESPARSE_${_component}_INCLUDE}")
      endif()
      if(SUITESPARSE_${_component}_INCLUDE MATCHES
         "SUITESPARSE_${_component}_INCLUDE-NOTFOUND$" 
         OR SUITESPARSE_${_component}_DLL MATCHES "SUITESPARSE_${_component}_DLL-NOTFOUND$")
        message(WARNING "SuiteSparse::${_component} libraries or include directory not found")
        continue()
      endif()
      if(NOT TARGET SuiteSparse::${_component})
        if(${_component} IN_LIST _directional_tutorials_exclude)
          add_library(SuiteSparse::${_component} INTERFACE IMPORTED GLOBAL)
        else()
          add_library(SuiteSparse::${_component} SHARED IMPORTED GLOBAL)
        endif()
      endif()

      if(${_component} IN_LIST _directional_tutorials_exclude)
        set_target_properties(
          SuiteSparse::${_component}
          PROPERTIES
            SUITESPARSE_RUNTIME_DLL "${SUITESPARSE_${_component}_DLL}"
        )
      else()
        set_target_properties(
          SuiteSparse::${_component}
          PROPERTIES
            IMPORTED_CONFIGURATIONS RELEASE
            IMPORTED_IMPLIB_RELEASE "${SUITESPARSE_${_component}_LIB}"
            IMPORTED_LOCATION_RELEASE "${SUITESPARSE_${_component}_DLL}"
            MAP_IMPORTED_CONFIG_DEBUG RELEASE
            MAP_IMPORTED_CONFIG_RELEASE RELEASE
            MAP_IMPORTED_CONFIG_MINSIZEREL RELEASE
            MAP_IMPORTED_CONFIG_RELWITHDEBINFO RELEASE
        )
      endif()
      target_include_directories(
        SuiteSparse::${_component}
        INTERFACE "${SUITESPARSE_${_component}_INCLUDE}")
      if(TARGET SuiteSparse::${_component})
        list(APPEND SUITESPARSE_TARGETS "SuiteSparse::${_component}")
        message(
          STATUS "Added SuiteSparse::${_component} to SUITESPARSE_TARGETS")
        message(
          STATUS
            "SuiteSparse::${_component} include directory: ${SUITESPARSE_${_component}_INCLUDE}"
        )
        message(
          STATUS
            "SuiteSparse::${_component} link library: ${SUITESPARSE_${_component}_LIB}"
        )
        message(
          STATUS
            "SuiteSparse::${_component} runtime library: ${SUITESPARSE_${_component}_DLL}"
        )
      endif()
    endforeach()
  else()
    set(_directional_suitesparse_libraries)
    foreach(_component IN LISTS _directional_suitesparse_components)
      unset(_component_path CACHE)
      unset(_component_path)
      find_library(
        _component_path
        NAMES ${_component}
        HINTS ${_directional_suitesparse_library_hints})
      if(_component_path)
        list(APPEND _directional_suitesparse_libraries "${_component_path}")
      endif()
    endforeach()
  endif()

  set(SUITESPARSE_TARGETS
      "${SUITESPARSE_TARGETS}"
      PARENT_SCOPE)
endfunction()

function(_directional_try_autoinstall_suitesparse)
  if(MSVC)
    _directional_enable_vcpkg(_directional_vcpkg_exe)
    _directional_install_vcpkg(
      DESTINATION
      "suitesparse"
      PACKAGES
      "suitesparse-config"
      "suitesparse-amd"
      "suitesparse-btf"
      "suitesparse-camd"
      "suitesparse-ccolamd"
      "suitesparse-cholmod"
      "suitesparse-colamd"
      "suitesparse-cxsparse"
      "suitesparse-klu"
      "suitesparse-ldl"
      "suitesparse-umfpack")
    _directional_install_vcpkg(PACKAGES "openblas")
  elseif(APPLE)
    find_program(_directional_brew_exe brew)
    if(_directional_brew_exe)
      message(
        STATUS "SuiteSparse not found. Attempting auto-install via Homebrew.")
      execute_process(COMMAND "${_directional_brew_exe}" install suitesparse
                      RESULT_VARIABLE _directional_brew_result)
      if(_directional_brew_result EQUAL 0)
        execute_process(
          COMMAND "${_directional_brew_exe}" --prefix suitesparse
          OUTPUT_VARIABLE _directional_brew_prefix
          OUTPUT_STRIP_TRAILING_WHITESPACE
          RESULT_VARIABLE _directional_brew_prefix_result)
        if(_directional_brew_prefix_result EQUAL 0
           AND EXISTS "${_directional_brew_prefix}")
          list(APPEND CMAKE_PREFIX_PATH "${_directional_brew_prefix}")
          set(CMAKE_PREFIX_PATH
              "${CMAKE_PREFIX_PATH}"
              PARENT_SCOPE)
          message(STATUS "Homebrew SuiteSparse install completed successfully.")
        endif()
      else()
        message(
          WARNING
            "Homebrew SuiteSparse auto-install failed with exit code ${_directional_brew_result}."
        )
      endif()
    else()
      message(STATUS "SuiteSparse not found and Homebrew is unavailable.")
    endif()
  endif()
endfunction()
