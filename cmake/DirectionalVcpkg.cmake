# update function to also take additional package_name parameter
function(_directional_append_vcpkg_paths out_var package_name)
  set(_paths ${${out_var}})
  foreach(_suffix IN LISTS ARGN)
    foreach(_triplet IN LISTS _directional_known_triplets)
      set(_source_path
          "${DIRECTIONAL_VCPKG_INSTALL_ROOT}/${package_name}/${_triplet}/${_suffix}"
      )
      if(EXISTS "${_source_path}")
        list(APPEND _paths "${_source_path}")
      endif()
      set(_build_path
          "${CMAKE_CURRENT_BINARY_DIR}/_deps/vcpkg-src/installed/${package_name}/${_triplet}/${_suffix}"
      )
      if(EXISTS "${_build_path}")
        list(APPEND _paths "${_build_path}")
      endif()
    endforeach()
  endforeach()
  set(${out_var}
      "${_paths}"
      PARENT_SCOPE)
endfunction()

function(_directional_write_windows_triplet triplet_path)
  file(
    WRITE "${triplet_path}"
    [=[
set(VCPKG_TARGET_ARCHITECTURE x64)
set(VCPKG_CRT_LINKAGE dynamic)
set(VCPKG_LIBRARY_LINKAGE dynamic)
set(VCPKG_LINKER_FLAGS "/MANIFEST:NO")
set(VCPKG_LINKER_FLAGS_DEBUG "/MANIFEST:NO")
set(VCPKG_LINKER_FLAGS_RELEASE "/MANIFEST:NO")
]=])
endfunction()

function(_directional_write_blas_wrapper wrapper_path)
  file(
    WRITE "${wrapper_path}"
    [=[
if(WIN32)
  find_package(OpenBLAS CONFIG QUIET)
  if(OpenBLAS_FOUND)
    if(NOT TARGET BLAS::BLAS)
      add_library(BLAS::BLAS INTERFACE IMPORTED)
      set_property(TARGET BLAS::BLAS PROPERTY INTERFACE_LINK_LIBRARIES OpenBLAS::OpenBLAS)
    endif()
    set(BLAS_FOUND TRUE)
    set(BLAS_LIBRARIES BLAS::BLAS)
    set(BLAS_LINKER_FLAGS "")
    get_target_property(BLAS_INCLUDE_DIRS OpenBLAS::OpenBLAS INTERFACE_INCLUDE_DIRECTORIES)
    return()
  endif()
endif()

set(BLA_VENDOR OpenBLAS)
set(BLA_STATIC OFF)
set(BLA_PREFER_PKGCONFIG ON)
_find_package(${ARGS})
unset(BLA_VENDOR)
unset(BLA_STATIC)
unset(BLA_PREFER_PKGCONFIG)
]=])
endfunction()

function(_directional_enable_vcpkg _directional_vcpkg_exe)
  if(EXISTS "${_directional_vcpkg_exe}")
    get_filename_component(_directional_existing_vcpkg_root
                           "${_directional_vcpkg_exe}" DIRECTORY)
    set(_directional_vcpkg_exe
        "${_directional_vcpkg_exe}"
        PARENT_SCOPE)
    set(_directional_vcpkg_root
        "${_directional_existing_vcpkg_root}"
        PARENT_SCOPE)
    return()
  endif()
  if(MSVC)
    set(_directional_vcpkg_root "")
    if(DEFINED ENV{VCPKG_ROOT} AND EXISTS "$ENV{VCPKG_ROOT}")
      set(_directional_vcpkg_root "$ENV{VCPKG_ROOT}")
    elseif(EXISTS "${CMAKE_SOURCE_DIR}/.deps/vcpkg")
      set(_directional_vcpkg_root "${CMAKE_SOURCE_DIR}/.deps/vcpkg")
    else()
      message(STATUS "Downloading vcpkg...")
      include(FetchContent)
      FetchContent_Declare(
        vcpkg
        GIT_REPOSITORY https://github.com/Microsoft/vcpkg.git
        SOURCE_DIR "${CMAKE_SOURCE_DIR}/.deps/vcpkg")
      FetchContent_MakeAvailable(vcpkg)
      set(_directional_vcpkg_root "${vcpkg_SOURCE_DIR}")
    endif()

    if(_directional_vcpkg_root)
      set(_directional_vcpkg_exe "${_directional_vcpkg_root}/vcpkg.exe")
      if(NOT EXISTS "${_directional_vcpkg_exe}")
        message(STATUS "No vcpkg executable found, trying to bootstrap...")
        execute_process(
          COMMAND ${_directional_vcpkg_root}/bootstrap-vcpkg.bat
          WORKING_DIRECTORY "${_directional_vcpkg_root}"
          RESULT_VARIABLE _directional_vcpkg_result)
        if(_directional_vcpkg_result EQUAL 0)
          message(STATUS "vcpkg bootstrapped successfully")
          set(_directional_vcpkg_exe
              "${_directional_vcpkg_root}/vcpkg.exe"
              PARENT_SCOPE)
          set(_directional_vcpkg_root
              "${_directional_vcpkg_root}"
              PARENT_SCOPE)
          if(NOT EXISTS "${_directional_vcpkg_exe}")
            message(FATAL_ERROR "Failed to bootstrap vcpkg")
            return()
          endif()
        else()
          message(FATAL_ERROR "Failed to bootstrap vcpkg")
          return()
        endif()
      else()
        set(_directional_vcpkg_exe
            "${_directional_vcpkg_exe}"
            PARENT_SCOPE)
        set(_directional_vcpkg_root
            "${_directional_vcpkg_root}"
            PARENT_SCOPE)
      endif()
    endif()
  endif()
endfunction()

function(_directional_install_vcpkg)
  # Define valid keywords
  set(options) # Boolean flags
  set(one_value_args DESTINATION) # Single values
  set(multi_value_args PACKAGES) # Lists of values

  # Parse ARGN
  cmake_parse_arguments(ARG "${options}" "${one_value_args}"
                        "${multi_value_args}" ${ARGN})
  if(ARG_PACKAGES)
    set(package_names ${ARG_PACKAGES})
  else()
    message(FATAL_ERROR "No packages specified")
  endif()
  if(ARG_DESTINATION)
    set(dest_path "${ARG_DESTINATION}/")
  else()
    set(dest_path "")
  endif()
  if(MSVC)
    _directional_enable_vcpkg(_directional_vcpkg_exe)

    if(EXISTS "${_directional_vcpkg_exe}")
      string(REPLACE ";" ", " _directional_package_message "${package_names}")
      message(
        STATUS
          "${_directional_package_message} not found. Attempting auto-install via vcpkg: ${_directional_vcpkg_exe}"
      )
      set(_directional_vcpkg_install_root "${DIRECTIONAL_VCPKG_INSTALL_ROOT}")
      set(_directional_triplet_name "${DIRECTIONAL_VCPKG_TRIPLET}")
      set(_directional_triplet_dir
          "${CMAKE_CURRENT_BINARY_DIR}/vcpkg_custom_triplets")
      file(MAKE_DIRECTORY "${_directional_triplet_dir}")
      _directional_write_windows_triplet(
        "${_directional_triplet_dir}/${_directional_triplet_name}.cmake")
      set(_directional_blas_wrapper_dir
          "${_directional_vcpkg_install_root}/${_directional_triplet_name}/share/blas"
      )
      file(MAKE_DIRECTORY "${_directional_blas_wrapper_dir}")
      _directional_write_blas_wrapper(
        "${_directional_blas_wrapper_dir}/vcpkg-cmake-wrapper.cmake")
      foreach(_directional_package IN LISTS package_names)
        set(_directional_vcpkg_cmd "${_directional_vcpkg_exe}")
        set(_directional_vcpkg_install_root
            "${DIRECTIONAL_VCPKG_INSTALL_ROOT}/${dest_path}${_directional_package}"
        )
        list(
          APPEND
          _directional_vcpkg_cmd
          install
          "${_directional_package}:${_directional_triplet_name}"
          "--overlay-triplets=${_directional_triplet_dir}"
          "--x-install-root=${_directional_vcpkg_install_root}")
        execute_process(
          COMMAND ${_directional_vcpkg_cmd}
          WORKING_DIRECTORY "${_directional_vcpkg_root}"
          RESULT_VARIABLE _directional_vcpkg_result)
        if(_directional_vcpkg_result EQUAL 0)
          list(
            APPEND CMAKE_PREFIX_PATH
            "${_directional_vcpkg_install_root}/${_directional_triplet_name}")
          set(CMAKE_PREFIX_PATH
              "${CMAKE_PREFIX_PATH}"
              PARENT_SCOPE)
          message(
            STATUS
              "vcpkg ${_directional_package_message} install completed successfully."
          )
        else()
          message(
            FATAL_ERROR
              "vcpkg ${_directional_package_message} auto-install failed with exit code ${_directional_vcpkg_result}."
          )
        endif()
      endforeach()
    else()
      message(
        STATUS
          "Vcpkg root was found, but no vcpkg executable exists at ${_directional_vcpkg_root}."
      )
    endif()
  endif()
endfunction()

function(get_target_architecture RESULT_VAR)
    if(NOT CMAKE_SIZEOF_VOID_P)
        message(FATAL_ERROR "Language not enabled. Call project() before this function.")
    endif()

    if(CMAKE_SIZEOF_VOID_P EQUAL 8)
        set(${RESULT_VAR} "x64" PARENT_SCOPE)
    elseif(CMAKE_SIZEOF_VOID_P EQUAL 4)
        set(${RESULT_VAR} "x32" PARENT_SCOPE)
    else()
        set(${RESULT_VAR} "UNKNOWN" PARENT_SCOPE)
    endif()
endfunction()
