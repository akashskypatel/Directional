function(_directional_find_suitesparse)
  unset(DIRECTIONAL_SUITESPARSE_CONFIG_FOUND PARENT_SCOPE)
  if(MSVC
     AND DIRECTIONAL_ENABLE_METIS_SUITESPARSE
     AND Directional_SuiteSparse_METIS_PREFIX)
    find_package(
      SuiteSparse
      CONFIG
      QUIET
      NO_DEFAULT_PATH
      PATHS
      "${Directional_SuiteSparse_METIS_PREFIX}"
      "${Directional_SuiteSparse_METIS_PREFIX}/lib"
      "${Directional_SuiteSparse_METIS_PREFIX}/lib64"
      PATH_SUFFIXES
      cmake
      cmake/suitesparse
      lib/cmake
      lib64/cmake)
  else()
    find_package(SuiteSparse CONFIG QUIET)
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
  #----------------------------------------------------------------------------------
  # If METIS is enabled .deps/sparsesuite-metis takes precedence over sparsesuite
  # If METIS is disabled .deps/sparsesuite is used only
  #----------------------------------------------------------------------------------
  set(_directional_suitesparse_include_hints "${CMAKE_SOURCE_DIR}/.deps/suitesparse")
  set(_directional_suitesparse_library_hints "${CMAKE_SOURCE_DIR}/.deps/suitesparse")
  set(_include_patterns)
  get_target_architecture(_ss_arch)
  if(DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
    message(STATUS "Using SuiteSparse with METIS")
    list(APPEND _directional_suitesparse_components
         ${_directional_suitesparse_metis_components})
    set(_directional_suitesparse_include_hints 
        "${CMAKE_SOURCE_DIR}/.deps/suitesparse-metis/install/include"
        "${CMAKE_SOURCE_DIR}/.deps/suitesparse")
    set(_directional_suitesparse_library_hints 
        "${CMAKE_SOURCE_DIR}/.deps/suitesparse-metis/install"
        "${CMAKE_SOURCE_DIR}/.deps/suitesparse-metis/source/lapack_windows/${_ss_arch}"
        "${CMAKE_SOURCE_DIR}/.deps/suitesparse")
  endif()

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
        message(FATAL_ERROR "SuiteSparse::openblas libraries or include directory not found")
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
        message(FATAL_ERROR "SuiteSparse::suitesparseconfig libraries or include directory not found")
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
      if(DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
        _directional_find_directory(
          SUITESPARSE_${_component}_INCLUDE
          PATTERNS
          "suitesparse-metis/install/include"
          "suitesparse-${_component}/xw/include"
          DIRECTORIES
          ${_directional_suitesparse_library_hints})
      else()
        _directional_find_directory(
          SUITESPARSE_${_component}_INCLUDE
          PATTERNS
          "suitesparse-${_component}/xw/include"
          DIRECTORIES
          ${_directional_suitesparse_library_hints})
      endif()
      if(SUITESPARSE_${_component}_INCLUDE)
        list(APPEND _directional_suitesparse_includes
             "${SUITESPARSE_${_component}_INCLUDE}")
      endif()
      if(SUITESPARSE_${_component}_INCLUDE MATCHES
         "SUITESPARSE_${_component}_INCLUDE-NOTFOUND$" 
         OR SUITESPARSE_${_component}_DLL MATCHES "SUITESPARSE_${_component}_DLL-NOTFOUND$")
        message(FATAL_ERROR "SuiteSparse::${_component} libraries or include directory not found")
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

function(_directional_install_suitesparse_metis_windows)
  if(NOT MSVC)
    message(
      FATAL_ERROR
        "_directional_install_suitesparse_metis_windows() is intended for MSVC builds"
    )
  endif()

  find_program(_directional_git_executable NAMES git git.exe REQUIRED)

  if(NOT EXISTS "${_directional_git_executable}")
    message(FATAL_ERROR "Git not found")
  endif()

  set(_directional_ssmetis_source_dir
      "${DIRECTIONAL_SUITESPARSE_METIS_ROOT}/source")
  set(_directional_ssmetis_build_dir
      "${DIRECTIONAL_SUITESPARSE_METIS_ROOT}/build")
  set(_directional_ssmetis_install_dir
      "${DIRECTIONAL_SUITESPARSE_METIS_ROOT}/install")
  set(_directional_ssmetis_stamp
      "${_directional_ssmetis_install_dir}/.directional-installed")

  if(EXISTS "${_directional_ssmetis_stamp}")
    message(STATUS "Reusing SuiteSparse+METIS installation: "
                   "${_directional_ssmetis_install_dir}")

    file(
      GLOB_RECURSE _directional_suitesparse_config_files
      LIST_DIRECTORIES FALSE
      "${_directional_ssmetis_install_dir}/SuiteSparseConfig.cmake"
      "${_directional_ssmetis_install_dir}/SuiteSparse-config.cmake"
      "${_directional_ssmetis_install_dir}/*/SuiteSparseConfig.cmake"
      "${_directional_ssmetis_install_dir}/*/*/SuiteSparseConfig.cmake"
      "${_directional_ssmetis_install_dir}/*/*/*/SuiteSparseConfig.cmake")

    list(LENGTH _directional_suitesparse_config_files
         _directional_suitesparse_config_count)

    if(_directional_suitesparse_config_count EQUAL 0)
      message(
        WARNING
          "SuiteSparse+METIS stamp exists, but its CMake config is missing. "
          "Removing the stale stamp and rebuilding.")

      file(REMOVE "${_directional_ssmetis_stamp}")
    else()
      list(GET _directional_suitesparse_config_files 0
           _directional_suitesparse_config_file)

      get_filename_component(
        _directional_suitesparse_config_dir
        "${_directional_suitesparse_config_file}" DIRECTORY)

      set(Directional_SuiteSparse_METIS_PREFIX
          "${_directional_ssmetis_install_dir}"
          CACHE INTERNAL "Directional SuiteSparse+METIS installation" FORCE)

      set(SuiteSparse_DIR
          "${_directional_suitesparse_config_dir}"
          CACHE PATH "METIS-enabled SuiteSparse config directory" FORCE)

      list(PREPEND CMAKE_PREFIX_PATH "${_directional_ssmetis_install_dir}")

      set(CMAKE_PREFIX_PATH
          "${CMAKE_PREFIX_PATH}"
          PARENT_SCOPE)

      set(SuiteSparse_DIR
          "${_directional_suitesparse_config_dir}"
          PARENT_SCOPE)

      return()
    endif()
  endif()

  file(MAKE_DIRECTORY "${DIRECTIONAL_SUITESPARSE_METIS_ROOT}")

  if(NOT EXISTS "${_directional_ssmetis_source_dir}/CMakeLists.txt")
    message(
      STATUS
        "Cloning suitesparse-metis-for-windows ${DIRECTIONAL_SUITESPARSE_METIS_GIT_TAG}"
    )

    execute_process(
      COMMAND
        "${_directional_git_executable}" clone --recursive --branch
        "${DIRECTIONAL_SUITESPARSE_METIS_GIT_TAG}" --depth 1
        "https://github.com/jlblancoc/suitesparse-metis-for-windows.git"
        "${_directional_ssmetis_source_dir}"
      RESULT_VARIABLE _directional_clone_result
      OUTPUT_VARIABLE _directional_clone_output
      ERROR_VARIABLE _directional_clone_error)

    if(NOT _directional_clone_result EQUAL 0)
      message(
        FATAL_ERROR
          "Failed to clone suitesparse-metis-for-windows.\n"
          "stdout:\n${_directional_clone_output}\n"
          "stderr:\n${_directional_clone_error}")
    endif()
    set(_directional_metis_source_dir
        "${_directional_ssmetis_source_dir}/SuiteSparse/CHOLMOD/SuiteSparse_metis"
    )

    if(NOT EXISTS "${_directional_metis_source_dir}/CMakeLists.txt")
      message(
        FATAL_ERROR
          "The cloned SuiteSparse repository does not contain the bundled "
          "SuiteSparse METIS source at:\n"
          "  ${_directional_metis_source_dir}\n"
          "Make sure the repository was cloned recursively.")
    endif()

    message(STATUS "Bundled SuiteSparse METIS source found: "
                   "${_directional_metis_source_dir}")
  endif()

  set(_directional_generator_arguments -G "${CMAKE_GENERATOR}")

  if(CMAKE_GENERATOR_PLATFORM)
    list(APPEND _directional_generator_arguments -A
         "${CMAKE_GENERATOR_PLATFORM}")
  endif()

  if(CMAKE_GENERATOR_TOOLSET)
    list(APPEND _directional_generator_arguments -T
         "${CMAKE_GENERATOR_TOOLSET}")
  endif()

  message(
    STATUS "Configuring SuiteSparse+METIS in ${_directional_ssmetis_build_dir}")

  execute_process(
    COMMAND
      "${CMAKE_COMMAND}" -S "${_directional_ssmetis_source_dir}" -B
      "${_directional_ssmetis_build_dir}" ${_directional_generator_arguments}
      -DCMAKE_INSTALL_PREFIX=${_directional_ssmetis_install_dir}
      -DBUILD_SHARED_LIBS=ON -DBUILD_METIS=ON -DWITH_CUDA=OFF -DWITH_TBB=OFF
      -DWITH_MKL=OFF -DWITH_OPENBLAS=OFF -DHAVE_COMPLEX=OFF
    RESULT_VARIABLE _directional_configure_result
    OUTPUT_VARIABLE _directional_configure_output
    ERROR_VARIABLE _directional_configure_error)

  if(NOT _directional_configure_result EQUAL 0)
    message(
      FATAL_ERROR
        "Failed to configure SuiteSparse+METIS.\n stdout:\n${_directional_configure_output}\n stderr:\n${_directional_configure_error}"
    )
  endif()

  message(STATUS "SuiteSparse+METIS configure output:\n"
                 "${_directional_configure_output}")

  if(NOT _directional_configure_output MATCHES
     "METIS: building with SuiteSparse_METIS_VERSION")
    message(
      FATAL_ERROR
        "SuiteSparse nested configuration succeeded, but METIS was not "
        "enabled. Full nested configure output:\n"
        "${_directional_configure_output}")
  endif()

  set(_directional_dependency_config "Release")

  message(
    STATUS
      "Building and installing SuiteSparse+METIS configuration ${_directional_dependency_config}"
  )

  execute_process(
    COMMAND
      "${CMAKE_COMMAND}" --build "${_directional_ssmetis_build_dir}" --config
      "${_directional_dependency_config}" --target INSTALL --parallel
    RESULT_VARIABLE _directional_build_result
    OUTPUT_VARIABLE _directional_build_output
    ERROR_VARIABLE _directional_build_error)

  if(NOT _directional_build_result EQUAL 0)
    message(
      FATAL_ERROR
        "Failed to build/install SuiteSparse+METIS.\n stdout:\n${_directional_build_output}\n stderr:\n${_directional_build_error}"
    )
  endif()

  file(
    GLOB_RECURSE _directional_suitesparse_config_files
    LIST_DIRECTORIES FALSE
    "${_directional_ssmetis_install_dir}/SuiteSparseConfig.cmake"
    "${_directional_ssmetis_install_dir}/SuiteSparse-config.cmake"
    "${_directional_ssmetis_install_dir}/*/SuiteSparseConfig.cmake"
    "${_directional_ssmetis_install_dir}/*/*/SuiteSparseConfig.cmake"
    "${_directional_ssmetis_install_dir}/*/*/*/SuiteSparseConfig.cmake")

  list(LENGTH _directional_suitesparse_config_files
       _directional_suitesparse_config_count)

  if(_directional_suitesparse_config_count EQUAL 0)
    message(
      FATAL_ERROR "SuiteSparse+METIS was built, but no SuiteSparseConfig.cmake "
                  "was installed below ${_directional_ssmetis_install_dir}")
  endif()

  list(GET _directional_suitesparse_config_files 0
       _directional_suitesparse_config_file)

  get_filename_component(_directional_suitesparse_config_dir
                         "${_directional_suitesparse_config_file}" DIRECTORY)

  file(
    WRITE "${_directional_ssmetis_stamp}"
    "tag=${DIRECTIONAL_SUITESPARSE_METIS_GIT_TAG}\n"
    "configuration=${_directional_dependency_config}\n"
    "config=${_directional_suitesparse_config_file}\n")

  set(Directional_SuiteSparse_METIS_PREFIX
      "${_directional_ssmetis_install_dir}"
      CACHE INTERNAL "Directional SuiteSparse+METIS installation" FORCE)

  set(SuiteSparse_DIR
      "${_directional_suitesparse_config_dir}"
      CACHE PATH "METIS-enabled SuiteSparse config directory" FORCE)

  list(PREPEND CMAKE_PREFIX_PATH "${_directional_ssmetis_install_dir}")

  set(CMAKE_PREFIX_PATH
      "${CMAKE_PREFIX_PATH}"
      PARENT_SCOPE)

  set(SuiteSparse_DIR
      "${_directional_suitesparse_config_dir}"
      PARENT_SCOPE)

  message(STATUS "SuiteSparse+METIS installation completed")

  message(STATUS "  Install prefix: ${_directional_ssmetis_install_dir}")

  message(STATUS "  Config directory: ${_directional_suitesparse_config_dir}")

  message(
    STATUS
      "SuiteSparse+METIS installation completed: ${_directional_ssmetis_install_dir}"
  )
endfunction()

function(_directional_try_autoinstall_suitesparse)
  if(MSVC)
    if(DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
      _directional_install_suitesparse_metis_windows()
    else()
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
    endif()
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
