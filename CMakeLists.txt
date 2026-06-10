cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  Directional
  VERSION 0.1.0
  LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(BUILD_TUTORIALS "Build Directional tutorials" OFF)
option(BUILD_PYTHON "Build Python bindings" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(DIRECTIONAL_ENABLE_GMP "Enable GMP support if found" ON)
option(DIRECTIONAL_ENABLE_SUITESPARSE "Enable SuiteSparse support if found" ON)
option(DIRECTIONAL_ENABLE_METIS_SUITESPARSE
       "Enable METIS support in SuiteSparse" ON)

set(DIRECTIONAL_SUITESPARSE_METIS_GIT_TAG
    "v7.5.1-1"
    CACHE STRING "suitesparse-metis-for-windows Git tag")
set(DIRECTIONAL_SUITESPARSE_METIS_ROOT
    "${CMAKE_SOURCE_DIR}/.deps/suitesparse-metis"
    CACHE PATH "SuiteSparse+METIS source, build, and install root")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(DirectionalDependencyConfig)
include(DirectionalVcpkg)
include(DirectionalRuntime)

if(DIRECTIONAL_ENABLE_GMP)
  include(DirectionalDependenciesGMP)
endif()

if(DIRECTIONAL_ENABLE_SUITESPARSE OR DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
  include(DirectionalDependenciesSuiteSparse)
endif()

add_library(directional SHARED src/directional_core.cpp)
add_library(Directional::directional ALIAS directional)

set_target_properties(directional PROPERTIES OUTPUT_NAME directional
                                             WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_include_directories(
  directional
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/eigen>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_features(directional PUBLIC cxx_std_20)

if(DIRECTIONAL_ENABLE_SUITESPARSE)
  message(STATUS "Attempting to find SuiteSparse for Directional core...")

  if(MSVC AND DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
    _directional_install_suitesparse_metis_windows()
  endif()

  _directional_find_suitesparse()

  if(NOT DIRECTIONAL_SUITESPARSE_CONFIG_FOUND)
    if(NOT SUITESPARSE_TARGETS)
      _directional_try_autoinstall_suitesparse()
      _directional_find_suitesparse()
    endif()
  endif()

  if(SUITESPARSE_TARGETS)
    foreach(_target IN LISTS SUITESPARSE_TARGETS)
      if(TARGET ${_target})
        message(
          STATUS "SuiteSparse target found for Directional core: ${_target}")

        target_compile_definitions(directional
                                   PUBLIC DIRECTIONAL_ENABLE_SUITESPARSE)

        target_link_libraries(directional PUBLIC ${_target})
      endif()
    endforeach()
  else()
    message(FATAL_ERROR "SuiteSparse not found for Directional core.")
  endif()
endif()

if(DIRECTIONAL_ENABLE_GMP)
  message(STATUS "Attempting to find GMP for Directional core...")

  _directional_find_gmp()

  if(NOT TARGET GMP::GMP OR NOT TARGET GMP::GMPXX)
    _directional_try_autoinstall_gmp()
    _directional_find_gmp()
  endif()

  if(TARGET GMP::GMP AND TARGET GMP::GMPXX)
    message(STATUS "GMP found for Directional core")

    target_compile_definitions(
      directional PUBLIC DIRECTIONAL_ENABLE_GMP DIRECTIONAL_ENABLE_GMP_ENABLED)

    target_link_libraries(directional PUBLIC GMP::GMP)

    target_link_libraries(directional PUBLIC GMP::GMPXX)
  else()
    message(
      WARNING
        "GMP not found for Directional core. Continuing without DIRECTIONAL_ENABLE_GMP."
    )

    set(DIRECTIONAL_ENABLE_GMP
        OFF
        CACHE BOOL "Enable GMP support if found" FORCE)
  endif()
endif()

if(BUILD_TUTORIALS)
  add_subdirectory(tutorial)
endif()

if(BUILD_PYTHON)
  find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
  find_package(pybind11 CONFIG REQUIRED)

  pybind11_add_module(_directional MODULE python/src/bindings.cpp)
  target_link_libraries(_directional PRIVATE Directional::directional)
  target_compile_features(_directional PRIVATE cxx_std_20)

  install(
    TARGETS _directional
    LIBRARY DESTINATION directional
    RUNTIME DESTINATION directional)

  install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/python/directional/__init__.py
          DESTINATION directional)
endif()

install(
  TARGETS directional
  EXPORT DirectionalTargets
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(WIN32)
  install(FILES $<TARGET_RUNTIME_DLLS:directional>
          DESTINATION "${CMAKE_INSTALL_BINDIR}")
  if(DIRECTIONAL_ENABLE_METIS_SUITESPARSE)
    foreach(_excluded IN LISTS _directional_tutorials_exclude)
      get_target_property(_runtime_dll SuiteSparse::${_excluded} SUITESPARSE_RUNTIME_DLL)
      if(_runtime_dll)
        install(FILES "${_runtime_dll}" DESTINATION "${CMAKE_INSTALL_BINDIR}")
      endif()
    endforeach()
  endif()
endif()

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/include/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/Eigen
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/unsupported")
  install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/external/eigen/unsupported
          DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
endif()

install(
  EXPORT DirectionalTargets
  FILE DirectionalTargets.cmake
  NAMESPACE Directional::
  DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional)

configure_package_config_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/cmake/DirectionalConfig.cmake.in
  ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfig.cmake
  INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional)

write_basic_package_version_file(
  ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfigVersion.cmake
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional)
