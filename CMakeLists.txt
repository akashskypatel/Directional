cmake_minimum_required(VERSION 3.15)

project(Directional VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(BUILD_TUTORIALS "Build Directional tutorials" OFF)
option(BUILD_PYTHON "Build Python bindings" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(USE_GMP "Enable GMP support if found" ON)
option(DIRECTIONAL_AUTO_INSTALL_GMP "Attempt to auto-install GMP when missing on supported platforms" ON)
option(DIRECTIONAL_ENABLE_CUDA "Enable the optional CUDA-backed integration solver" ON)

add_library(directional SHARED
  src/directional_core.cpp
)
add_library(Directional::directional ALIAS directional)

set_target_properties(directional PROPERTIES
  OUTPUT_NAME directional
  WINDOWS_EXPORT_ALL_SYMBOLS ON
)

target_include_directories(directional
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/eigen>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

target_compile_features(directional PUBLIC cxx_std_20)

if(DIRECTIONAL_ENABLE_CUDA)
  find_package(CUDAToolkit QUIET)
  if(CUDAToolkit_FOUND)
    message(STATUS "CUDA toolkit found for optional Directional integration solver:")
    message(STATUS "  Include: ${CUDAToolkit_INCLUDE_DIRS}")
    if(DEFINED CUDAToolkit_BIN_DIR)
      message(STATUS "  Bin: ${CUDAToolkit_BIN_DIR}")
    endif()
    target_compile_definitions(directional PUBLIC DIRECTIONAL_ENABLE_CUDA)
    target_link_libraries(directional PRIVATE CUDA::cudart CUDA::cusolver CUDA::cublas)
  else()
    message(WARNING "DIRECTIONAL_ENABLE_CUDA was requested, but CUDAToolkit was not found. Continuing without CUDA support.")
    set(DIRECTIONAL_ENABLE_CUDA OFF CACHE BOOL "Enable the optional CUDA-backed integration solver" FORCE)
  endif()
endif()

function(_directional_find_gmp)
  set(_directional_gmp_include_hints
    $ENV{GMP_DIR}/include
    ${CMAKE_PREFIX_PATH}/include
    /usr/include
    /usr/local/include
    /opt/homebrew/include
    "C:/Program Files/GMP/include"
  )

  set(_directional_gmp_library_hints
    $ENV{GMP_DIR}/lib
    ${CMAKE_PREFIX_PATH}/lib
    /usr/lib
    /usr/local/lib
    /opt/homebrew/lib
    "C:/Program Files/GMP/lib"
  )

  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed")
    list(APPEND _directional_gmp_include_hints
      "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/include/gmp"
    )
    list(APPEND _directional_gmp_library_hints
      "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/lib"
      "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/debug/lib"
      "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/bin"
      "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/debug/bin"
    )
  endif()

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
    set(_directional_vcpkg_root "")
    if(DEFINED ENV{VCPKG_ROOT} AND EXISTS "$ENV{VCPKG_ROOT}")
      set(_directional_vcpkg_root "$ENV{VCPKG_ROOT}")
    elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")
      set(_directional_vcpkg_root "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg")
    else()
      message(STATUS "Downloading vcpkg...")
      include(FetchContent)
      FetchContent_Declare(
        vcpkg
        GIT_REPOSITORY https://github.com/Microsoft/vcpkg.git
      )
      FetchContent_MakeAvailable(vcpkg)
      set(_directional_vcpkg_root "${vcpkg_SOURCE_DIR}")
    endif()

    if(_directional_vcpkg_root)
      set(_directional_vcpkg_exe "${_directional_vcpkg_root}/vcpkg.exe")
      if(NOT EXISTS "${_directional_vcpkg_exe}")
        message(STATUS "No vcpkg executable found, trying to bootstrap...")
        # run bootstrap-vcpkg.bat
        execute_process(
          COMMAND ${_directional_vcpkg_root}/bootstrap-vcpkg.bat
          WORKING_DIRECTORY "${_directional_vcpkg_root}"
          RESULT_VARIABLE _directional_vcpkg_result
        )
        if(_directional_vcpkg_result EQUAL 0)
          message(STATUS "vcpkg bootstrapped successfully")
          set(_directional_vcpkg_exe "${_directional_vcpkg_root}/vcpkg.exe")
          if(NOT EXISTS "${_directional_vcpkg_exe}")
            message(FATAL_ERROR "Failed to bootstrap vcpkg")
            set(USE_GMP OFF PARENT_SCOPE)
            return()
          endif()
        else()
          message(WARNING "Failed to bootstrap vcpkg")
          set(USE_GMP OFF PARENT_SCOPE)
          return()
        endif()
      endif()

      if(EXISTS "${_directional_vcpkg_exe}")
        message(STATUS "GMP not found. Attempting auto-install via vcpkg: ${_directional_vcpkg_exe}")
        set(_directional_vcpkg_cmd "${_directional_vcpkg_exe}")
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg.json")
          list(APPEND _directional_vcpkg_cmd install)
        else()
          list(APPEND _directional_vcpkg_cmd install gmp:x64-windows)
        endif()
        execute_process(
          COMMAND ${_directional_vcpkg_cmd}
          WORKING_DIRECTORY "${_directional_vcpkg_root}"
          RESULT_VARIABLE _directional_vcpkg_result
        )
        if(_directional_vcpkg_result EQUAL 0)
          list(APPEND CMAKE_PREFIX_PATH "${_directional_vcpkg_root}/installed/x64-windows")
          set(CMAKE_PREFIX_PATH "${CMAKE_PREFIX_PATH}" PARENT_SCOPE)
          message(STATUS "vcpkg GMP install completed successfully.")
        else()
          message(WARNING "vcpkg GMP auto-install failed with exit code ${_directional_vcpkg_result}.")
        endif()
      else()
        message(STATUS "Vcpkg root was found, but no vcpkg executable exists at ${_directional_vcpkg_root}.")
      endif()
    else()
      message(STATUS "GMP not found and no VCPKG_ROOT/external/vcpkg checkout was detected.")
    endif()
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

    list(APPEND _runtime_candidates
      "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/bin"
      "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg_installed/x64-windows/debug/bin"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/packages/gmp_x64-windows/bin"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/vcpkg/installed/x64-windows/bin"
    )

    set(_runtime_files)
    foreach(_candidate_dir IN LISTS _runtime_candidates)
      if(EXISTS "${_candidate_dir}")
        file(GLOB _candidate_files
          "${_candidate_dir}/gmp*.dll"
          "${_candidate_dir}/gmpxx*.dll"
        )
        list(APPEND _runtime_files ${_candidate_files})
      endif()
    endforeach()

    list(REMOVE_DUPLICATES _runtime_files)
    set(${out_var} "${_runtime_files}" PARENT_SCOPE)
  else()
    set(${out_var} "" PARENT_SCOPE)
  endif()
endfunction()

function(_directional_collect_cuda_runtime_files out_var)
  if(NOT WIN32 OR NOT DIRECTIONAL_ENABLE_CUDA OR NOT CUDAToolkit_FOUND)
    set(${out_var} "" PARENT_SCOPE)
    return()
  endif()

  set(_runtime_files)
  set(_runtime_dirs)
  if(DEFINED CUDAToolkit_BIN_DIR)
    list(APPEND _runtime_dirs "${CUDAToolkit_BIN_DIR}")
  endif()
  if(DEFINED CUDAToolkit_LIBRARY_DIR)
    list(APPEND _runtime_dirs "${CUDAToolkit_LIBRARY_DIR}")
  endif()

  foreach(_candidate_dir IN LISTS _runtime_dirs)
    if(EXISTS "${_candidate_dir}")
      file(GLOB _candidate_files
        "${_candidate_dir}/cudart*.dll"
        "${_candidate_dir}/cusolver*.dll"
        "${_candidate_dir}/cusparse*.dll"
        "${_candidate_dir}/cublas*.dll"
        "${_candidate_dir}/cublasLt*.dll"
        "${_candidate_dir}/nvJitLink*.dll"
      )
      list(APPEND _runtime_files ${_candidate_files})
    endif()
  endforeach()

  list(REMOVE_DUPLICATES _runtime_files)
  set(${out_var} "${_runtime_files}" PARENT_SCOPE)
endfunction()

if(USE_GMP)
  message(STATUS "Attempting to find GMP for Directional core...")

  _directional_find_gmp()

  if(NOT (GMP_INCLUDE_DIR AND GMP_LIBRARIES))
    _directional_try_autoinstall_gmp()
    _directional_find_gmp()
  endif()

  if(GMP_INCLUDE_DIR AND GMP_LIBRARIES)
    message(STATUS "GMP found for Directional core:")
    message(STATUS "  Include: ${GMP_INCLUDE_DIR}")
    message(STATUS "  Library: ${GMP_LIBRARIES}")
    target_compile_definitions(directional PUBLIC USE_GMP USE_GMP_ENABLED)
    target_include_directories(directional PUBLIC $<BUILD_INTERFACE:${GMP_INCLUDE_DIR}>)
    target_link_libraries(directional PRIVATE ${GMP_LIBRARIES})
    _directional_collect_gmp_runtime_files(DIRECTIONAL_GMP_RUNTIME_FILES)
  else()
    message(WARNING "GMP not found for Directional core. Continuing without USE_GMP.")
    set(USE_GMP OFF CACHE BOOL "Enable GMP support if found" FORCE)
  endif()
endif()

if(DIRECTIONAL_ENABLE_CUDA AND CUDAToolkit_FOUND)
  _directional_collect_cuda_runtime_files(DIRECTIONAL_CUDA_RUNTIME_FILES)
endif()

if(BUILD_TUTORIALS)
  add_subdirectory(tutorial)
endif()

if(BUILD_PYTHON)
  find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
  find_package(pybind11 CONFIG REQUIRED)

  pybind11_add_module(_directional MODULE
    python/src/bindings.cpp
  )
  target_link_libraries(_directional PRIVATE Directional::directional)
  if(USE_GMP AND GMP_LIBRARIES)
    target_link_libraries(_directional PRIVATE ${GMP_LIBRARIES})
  endif()
  target_compile_features(_directional PRIVATE cxx_std_20)

  install(
    TARGETS _directional
    LIBRARY DESTINATION directional
    RUNTIME DESTINATION directional
  )

  install(
    FILES ${CMAKE_CURRENT_SOURCE_DIR}/python/directional/__init__.py
    DESTINATION directional
  )

  if(USE_GMP AND DIRECTIONAL_GMP_RUNTIME_FILES)
    install(
      FILES ${DIRECTIONAL_GMP_RUNTIME_FILES}
      DESTINATION directional
    )
  endif()
  if(DIRECTIONAL_ENABLE_CUDA AND DIRECTIONAL_CUDA_RUNTIME_FILES)
    install(
      FILES ${DIRECTIONAL_CUDA_RUNTIME_FILES}
      DESTINATION directional
    )
  endif()
endif()

install(
  TARGETS directional
  EXPORT DirectionalTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

if(USE_GMP AND DIRECTIONAL_GMP_RUNTIME_FILES)
  install(
    FILES ${DIRECTIONAL_GMP_RUNTIME_FILES}
    DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
endif()

if(DIRECTIONAL_ENABLE_CUDA AND DIRECTIONAL_CUDA_RUNTIME_FILES)
  install(
    FILES ${DIRECTIONAL_CUDA_RUNTIME_FILES}
    DESTINATION ${CMAKE_INSTALL_BINDIR}
  )
endif()

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(
  DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/Eigen
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/unsupported")
  install(
    DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/unsupported
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
  )
endif()

install(
  EXPORT DirectionalTargets
  FILE DirectionalTargets.cmake
  NAMESPACE Directional::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional
)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/DirectionalConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional
)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
)

install(
  FILES
    ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfigVersion.cmake
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional
)
