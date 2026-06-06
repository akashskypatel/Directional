cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(Directional VERSION 0.1.0 LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(BUILD_TUTORIALS "Build Directional tutorials" OFF)
option(BUILD_PYTHON "Build Python bindings" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(USE_GMP "Enable GMP support if found" ON)
option(DIRECTIONAL_AUTO_INSTALL_GMP "Attempt to auto-install GMP when missing on supported platforms" ON)
option(DIRECTIONAL_ENABLE_SUITESPARSE "Enable SuiteSparse support if found" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(DirectionalDependencyConfig)
include(DirectionalVcpkg)
include(DirectionalDependencies)
include(DirectionalRuntime)

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

if(DIRECTIONAL_ENABLE_SUITESPARSE)
  message(STATUS "Attempting to find SuiteSparse for Directional core...")

  _directional_find_suitesparse()

  set(_directional_suitesparse_umfpack_libraries ${SUITESPARSE_LIBRARIES})
  list(FILTER _directional_suitesparse_umfpack_libraries INCLUDE REGEX "umfpack\\.lib$")
  list(LENGTH _directional_suitesparse_umfpack_libraries _directional_suitesparse_umfpack_count)
  if(NOT (SUITESPARSE_INCLUDE_DIR AND SUITESPARSE_UMFPACK_INCLUDE_DIR AND _directional_suitesparse_umfpack_count GREATER 0))
    _directional_try_autoinstall_suitesparse()
    _directional_find_suitesparse()
  endif()

  list(LENGTH SUITESPARSE_LIBRARIES _directional_suitesparse_library_count)
  if(SUITESPARSE_INCLUDE_DIR AND SUITESPARSE_UMFPACK_INCLUDE_DIR AND _directional_suitesparse_library_count GREATER 0)
    message(STATUS "SuiteSparse found for Directional core:")
    message(STATUS "  Include: ${SUITESPARSE_INCLUDE_DIR}")
    message(STATUS "  Library: ${SUITESPARSE_LIBRARIES}")
    target_compile_definitions(directional PUBLIC DIRECTIONAL_ENABLE_SUITESPARSE USE_SUITESPARSE_ENABLED)
    target_include_directories(directional PUBLIC
      $<BUILD_INTERFACE:${SUITESPARSE_INCLUDE_DIR}>
      $<BUILD_INTERFACE:${SUITESPARSE_INCLUDE_DIR}/suitesparse>
    )
    target_link_libraries(directional PRIVATE ${SUITESPARSE_LIBRARIES})
    _directional_collect_suitesparse_runtime_files(DIRECTIONAL_SUITESPARSE_RUNTIME_FILES)
  else()
    message(FATAL_ERROR "SuiteSparse not found for Directional core.")
  endif()
endif()

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
  if(DIRECTIONAL_ENABLE_SUITESPARSE AND SUITESPARSE_LIBRARIES)
    target_link_libraries(_directional PRIVATE ${SUITESPARSE_LIBRARIES})
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
  if(DIRECTIONAL_ENABLE_SUITESPARSE AND DIRECTIONAL_SUITESPARSE_RUNTIME_FILES)
    install(
      FILES ${DIRECTIONAL_SUITESPARSE_RUNTIME_FILES}
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

if(DIRECTIONAL_ENABLE_SUITESPARSE AND DIRECTIONAL_SUITESPARSE_RUNTIME_FILES)
  install(
    FILES ${DIRECTIONAL_SUITESPARSE_RUNTIME_FILES}
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
