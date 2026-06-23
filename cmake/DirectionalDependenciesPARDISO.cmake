# Intel oneMKL/PARDISO dependency discovery and runtime deployment helpers.

function(_directional_collect_pardiso_runtime_files out_var)
  set(_runtime_dirs)

  if(DEFINED DIRECTIONAL_PARDISO_RUNTIME_DIR
     AND IS_DIRECTORY "${DIRECTIONAL_PARDISO_RUNTIME_DIR}")
    list(APPEND _runtime_dirs "${DIRECTIONAL_PARDISO_RUNTIME_DIR}")
  endif()

  if(MSVC)
    list(APPEND _runtime_dirs
      "${DIRECTIONAL_VCPKG_INSTALL_ROOT}/intel-mkl/${DIRECTIONAL_VCPKG_TRIPLET}/bin")

    if(DEFINED MKL_DIR AND IS_DIRECTORY "${MKL_DIR}")
      get_filename_component(_mkl_prefix "${MKL_DIR}/../.." ABSOLUTE)
      list(APPEND _runtime_dirs "${_mkl_prefix}/bin")
    endif()
  endif()

  list(REMOVE_DUPLICATES _runtime_dirs)

  set(_runtime_files)
  set(_selected_runtime_dir "")
  foreach(_runtime_dir IN LISTS _runtime_dirs)
    if(NOT IS_DIRECTORY "${_runtime_dir}")
      continue()
    endif()

    # mkl_rt dynamically loads implementation modules such as mkl_def,
    # mkl_core, CPU-dispatch kernels, and the selected threading runtime.
    # These dependencies are intentionally loaded at runtime and therefore
    # are not reported by TARGET_RUNTIME_DLLS or GET_RUNTIME_DEPENDENCIES.
    file(GLOB _mkl_runtime_candidates
      LIST_DIRECTORIES FALSE
      "${_runtime_dir}/mkl_*.dll"
      "${_runtime_dir}/libiomp5md.dll"
      "${_runtime_dir}/libiompstubs5md.dll"
      "${_runtime_dir}/libimalloc.dll")

    if(_mkl_runtime_candidates)
      set(_runtime_files ${_mkl_runtime_candidates})
      set(_selected_runtime_dir "${_runtime_dir}")
      break()
    endif()
  endforeach()

  list(REMOVE_DUPLICATES _runtime_files)
  list(SORT _runtime_files)

  if(NOT _runtime_files)
    message(FATAL_ERROR
      "Intel oneMKL was found, but its Windows runtime DLLs were not found. "
      "Set DIRECTIONAL_PARDISO_RUNTIME_DIR to the oneMKL bin directory.")
  endif()

  set(DIRECTIONAL_PARDISO_RUNTIME_DIR
      "${_selected_runtime_dir}"
      CACHE PATH "Directory containing Intel oneMKL runtime DLLs" FORCE)
  set(${out_var} "${_runtime_files}" PARENT_SCOPE)

  list(LENGTH _runtime_files _runtime_count)
  message(STATUS
    "Intel oneMKL runtime directory: ${DIRECTIONAL_PARDISO_RUNTIME_DIR}")
  message(STATUS
    "Intel oneMKL runtime DLLs selected for deployment: ${_runtime_count}")
endfunction()

function(_directional_copy_pardiso_runtime_to_target target_name)
  if(NOT WIN32 OR NOT TARGET "${target_name}")
    return()
  endif()

  if(NOT DIRECTIONAL_PARDISO_RUNTIME_FILES)
    message(FATAL_ERROR
      "PARDISO runtime files were not collected before configuring target ${target_name}.")
  endif()

  add_custom_command(
    TARGET "${target_name}"
    POST_BUILD
    COMMAND "${CMAKE_COMMAND}" -E copy_if_different
            ${DIRECTIONAL_PARDISO_RUNTIME_FILES}
            "$<TARGET_FILE_DIR:${target_name}>"
    COMMAND_EXPAND_LISTS
    VERBATIM
    COMMENT "Copying Intel oneMKL runtime DLLs beside ${target_name}")
endfunction()

function(_directional_install_pardiso_runtime destination)
  if(NOT WIN32)
    return()
  endif()

  if(NOT DIRECTIONAL_PARDISO_RUNTIME_FILES)
    message(FATAL_ERROR
      "PARDISO runtime files were not collected before install rules were created.")
  endif()

  install(
    FILES ${DIRECTIONAL_PARDISO_RUNTIME_FILES}
    DESTINATION "${destination}")
endfunction()

function(_directional_find_PARDISO)
  if(NOT MSVC)
    find_package(MKL CONFIG REQUIRED)
    return()
  endif()

  if(NOT MKL_DIR)
    set(MKL_DIR
        "${DIRECTIONAL_VCPKG_INSTALL_ROOT}/intel-mkl/${DIRECTIONAL_VCPKG_TRIPLET}/share/mkl"
        CACHE PATH "Directory containing MKLConfig.cmake")
  endif()
  message(STATUS "Looking for MKL in: ${MKL_DIR}")
  list(PREPEND CMAKE_PREFIX_PATH "${MKL_DIR}")
  find_package(MKL CONFIG REQUIRED)

  if(TARGET MKL::MKL)
    message(STATUS "Intel oneMKL PARDISO target found")
  else()
    message(WARNING "Intel oneMKL PARDISO target not found")
  endif()
endfunction()

function(_directional_try_autoinstall_PARDISO)
  if(MSVC)
    _directional_enable_vcpkg(_directional_vcpkg_exe)
    _directional_install_vcpkg(PACKAGES "intel-mkl")
  elseif(APPLE)
    find_program(_directional_brew_exe brew)
    if(_directional_brew_exe)
      message(STATUS "PARDISO not found. Attempting auto-install via Homebrew.")
      execute_process(COMMAND "${_directional_brew_exe}" install "intel-mkl"
                      RESULT_VARIABLE _directional_brew_result)
      if(_directional_brew_result EQUAL 0)
        execute_process(
          COMMAND "${_directional_brew_exe}" --prefix "intel-mkl"
          OUTPUT_VARIABLE _directional_brew_prefix
          OUTPUT_STRIP_TRAILING_WHITESPACE
          RESULT_VARIABLE _directional_brew_prefix_result)
        if(_directional_brew_prefix_result EQUAL 0
           AND EXISTS "${_directional_brew_prefix}")
          list(APPEND CMAKE_PREFIX_PATH "${_directional_brew_prefix}")
          set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
          message(STATUS "Homebrew PARDISO install completed successfully.")
        endif()
      else()
        message(WARNING
          "Homebrew PARDISO auto-install failed with exit code ${_directional_brew_result}.")
      endif()
    else()
      message(STATUS "PARDISO not found and Homebrew is unavailable.")
    endif()
  endif()
endfunction()
