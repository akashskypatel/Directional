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
option(DIRECTIONAL_BUILD_CLI "Build the optional native command line executable" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(DIRECTIONAL_ENABLE_GMP "Enable GMP support. Will be auto-installed on MSVC if not found" ON)
option(DIRECTIONAL_ENABLE_SUITESPARSE "Enable SuiteSparse support. Will be auto-installed on MSVC if not found" ON)
option(DIRECTIONAL_ENABLE_PARDISO1
       "Enable Intel oneMKL PARDISO integration solver. Will be auto-installed on MSVC if not found" OFF)
option(DIRECTIONAL_ENABLE_CUDSS
       "Enable NVIDIA cuDSS integration solver if found" OFF)
set(CUDSS_ROOT "" CACHE PATH "Root directory of an NVIDIA cuDSS installation")

# Only one integration solver backend can be compiled into Directional. Resolve
# ambiguous requests deterministically before loading any backend dependencies.
set(_directional_requested_solver_backends "")
if(DIRECTIONAL_ENABLE_PARDISO)
  list(APPEND _directional_requested_solver_backends "PARDISO")
endif()
if(DIRECTIONAL_ENABLE_CUDSS)
  list(APPEND _directional_requested_solver_backends "CUDSS")
endif()
if(DIRECTIONAL_ENABLE_SUITESPARSE)
  list(APPEND _directional_requested_solver_backends "SUITESPARSE")
endif()

list(LENGTH _directional_requested_solver_backends
     _directional_requested_solver_backend_count)
if(_directional_requested_solver_backend_count GREATER 1)
  list(GET _directional_requested_solver_backends 0
       _directional_selected_solver_backend)
  string(JOIN ", " _directional_requested_solver_backend_list
         ${_directional_requested_solver_backends})
  message(
    WARNING
      "Multiple integration solver backends were requested: "
      "${_directional_requested_solver_backend_list}. Only "
      "${_directional_selected_solver_backend} will be enabled. "
      "Selection priority is PARDISO, CUDSS, SUITESPARSE.")

  set(DIRECTIONAL_ENABLE_PARDISO OFF CACHE BOOL
      "Enable Intel oneMKL PARDISO integration solver" FORCE)
  set(DIRECTIONAL_ENABLE_CUDSS OFF CACHE BOOL
      "Enable NVIDIA cuDSS integration solver" FORCE)
  set(DIRECTIONAL_ENABLE_SUITESPARSE OFF CACHE BOOL
      "Enable SuiteSparse integration solver" FORCE)

  if(_directional_selected_solver_backend STREQUAL "PARDISO")
    set(DIRECTIONAL_ENABLE_PARDISO ON CACHE BOOL
        "Enable Intel oneMKL PARDISO integration solver" FORCE)
  elseif(_directional_selected_solver_backend STREQUAL "CUDSS")
    set(DIRECTIONAL_ENABLE_CUDSS ON CACHE BOOL
        "Enable NVIDIA cuDSS integration solver" FORCE)
  else()
    set(DIRECTIONAL_ENABLE_SUITESPARSE ON CACHE BOOL
        "Enable SuiteSparse integration solver" FORCE)
  endif()
endif()

unset(_directional_requested_solver_backend_count)
unset(_directional_requested_solver_backend_list)
unset(_directional_requested_solver_backends)
unset(_directional_selected_solver_backend)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

include(DirectionalDependencyConfig)
include(DirectionalVcpkg)
include(DirectionalRuntime)

if(DIRECTIONAL_ENABLE_SUITESPARSE)
  include(DirectionalDependenciesSuiteSparse)
endif()

add_library(directional SHARED
  src/core/Library.cpp)
add_library(Directional::directional ALIAS directional)

set_target_properties(directional PROPERTIES OUTPUT_NAME directional
                                             WINDOWS_EXPORT_ALL_SYMBOLS ON)

target_include_directories(
  directional
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/eigen>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_features(directional PUBLIC cxx_std_20)

if(DIRECTIONAL_ENABLE_PARDISO)
  include(DirectionalDependenciesPARDISO)
  _directional_find_PARDISO()
  if(NOT TARGET MKL::MKL)
    _directional_try_autoinstall_PARDISO()
    _directional_find_PARDISO()
  endif()
  if(NOT TARGET MKL::MKL)
    message(FATAL_ERROR "Intel MKL PARDISO not found")
  endif()
  
  target_compile_definitions(directional INTERFACE DIRECTIONAL_HAS_PARDISO)
  target_link_libraries(directional PUBLIC MKL::MKL)
  _directional_collect_pardiso_runtime_files(
    DIRECTIONAL_PARDISO_RUNTIME_FILES)
elseif(DIRECTIONAL_ENABLE_CUDSS)
  find_package(CUDSS REQUIRED)
  if(NOT TARGET CUDSS::cudss)
    message(FATAL_ERROR "DIRECTIONAL_ENABLE_CUDSS requires CUDSS::cudss")
  endif()
  target_compile_definitions(directional INTERFACE DIRECTIONAL_HAS_CUDSS)
  target_link_libraries(directional PUBLIC CUDSS::cudss)
elseif(DIRECTIONAL_ENABLE_SUITESPARSE)
  message(STATUS "Attempting to find SuiteSparse for Directional core...")

  _directional_find_suitesparse()

  if(NOT DIRECTIONAL_SUITESPARSE_CONFIG_FOUND)
    if(NOT SUITESPARSE_TARGETS)
      _directional_try_autoinstall_suitesparse()
      _directional_find_suitesparse()
    endif()
  endif()

  if(SUITESPARSE_TARGETS OR SuiteSparse_FOUND)
    target_compile_definitions(
      directional
      INTERFACE DIRECTIONAL_ENABLE_SUITESPARSE USE_SUITESPARSE
                USE_SUITESPARSE_ENABLED SUITESPARSE_ENABLED ENABLE_SUITESPARSE)
    foreach(_target IN LISTS SUITESPARSE_TARGETS)
      if(TARGET ${_target})
        message(
          STATUS "SuiteSparse target found for Directional core: ${_target}")
        target_link_libraries(directional PUBLIC ${_target})
      endif()
    endforeach()
  else()
    message(FATAL_ERROR "SuiteSparse not found for Directional core."
    "Please install SuiteSparse or disable DIRECTIONAL_ENABLE_SUITESPARSE.")
  endif()
endif()

if(DIRECTIONAL_ENABLE_GMP)
  include(DirectionalDependenciesGMP)
  message(STATUS "Attempting to find GMP for Directional core...")

  _directional_find_gmp()

  if(NOT TARGET GMP::GMP OR NOT TARGET GMP::GMPXX)
    _directional_try_autoinstall_gmp()
    _directional_find_gmp()
  endif()

  if(TARGET GMP::GMP AND TARGET GMP::GMPXX)
    message(STATUS "GMP found for Directional core")

    target_compile_definitions(
      directional INTERFACE DIRECTIONAL_ENABLE_GMP USE_GMP USE_GMP_ENABLED
                          GMP_ENABLED ENABLE_GMP)

    target_link_libraries(directional PUBLIC GMP::GMP)

    target_link_libraries(directional PUBLIC GMP::GMPXX)
  else()
    message(
      WARNING
        "GMP not found for Directional core. Continuing without DIRECTIONAL_ENABLE_GMP."
        "Please install GMP and try again."
    )

    set(DIRECTIONAL_ENABLE_GMP
        OFF
        CACHE BOOL "Enable GMP support if found" FORCE)
  endif()
endif()

if(BUILD_TUTORIALS)
  add_subdirectory(tutorial)
endif()

if(DIRECTIONAL_BUILD_CLI OR BUILD_PYTHON)
  add_library(
    directional_cli_backend STATIC
    src/cli/CliBackend.cpp
    src/cli/ProgressDisplay.cpp
    src/cli/Usage.cpp
    src/cli/InfoCommand.cpp
    src/cli/MeshIO.cpp
    src/cli/MatrixIO.cpp
    src/cli/CrossFieldOutput.cpp
    src/cli/FieldConversion.cpp
    src/cli/CrossFieldCommand.cpp
    src/cli/RemeshOutput.cpp
    src/cli/RemeshCommand.cpp)
  add_library(Directional::directional_cli_backend ALIAS directional_cli_backend)
  set_target_properties(directional_cli_backend PROPERTIES POSITION_INDEPENDENT_CODE ON)
  target_link_libraries(directional_cli_backend PUBLIC Directional::directional)
  target_compile_features(directional_cli_backend PUBLIC cxx_std_20)
  target_compile_definitions(
    directional_cli_backend PRIVATE DIRECTIONAL_VERSION="${PROJECT_VERSION}")

  # Keep MSVC's expanded COFF section limit scoped to the two translation
  # units that instantiate Directional's template-heavy field and pipeline APIs.
  if(MSVC)
    set_source_files_properties(
      src/cli/CrossFieldCommand.cpp
      src/cli/RemeshCommand.cpp
      PROPERTIES COMPILE_OPTIONS "/bigobj")
  endif()
endif()

if(DIRECTIONAL_ENABLE_PARDISO)
  _directional_copy_pardiso_runtime_to_target(directional)
endif()

if(DIRECTIONAL_BUILD_CLI)
  add_executable(directional_cli src/cli/Main.cpp)
  add_executable(Directional::directional_cli ALIAS directional_cli)
  set_target_properties(directional_cli PROPERTIES OUTPUT_NAME directional)
  target_link_libraries(directional_cli PRIVATE Directional::directional_cli_backend)
  target_compile_features(directional_cli PRIVATE cxx_std_20)
  if(DIRECTIONAL_ENABLE_PARDISO)
    _directional_copy_pardiso_runtime_to_target(directional_cli)
  endif()
endif()

if(BUILD_PYTHON)
  find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
  find_package(pybind11 CONFIG REQUIRED)

  pybind11_add_module(_directional MODULE python/src/bindings.cpp)
  target_link_libraries(
    _directional PRIVATE Directional::directional
                         Directional::directional_cli_backend)
  target_compile_features(_directional PRIVATE cxx_std_20)
  if(DIRECTIONAL_ENABLE_PARDISO)
    _directional_copy_pardiso_runtime_to_target(_directional)
  endif()

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

if(DIRECTIONAL_BUILD_CLI)
  install(TARGETS directional_cli RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

if(DIRECTIONAL_ENABLE_PARDISO)
  # Native library and CLI load from the regular binary directory.
  _directional_install_pardiso_runtime("${CMAKE_INSTALL_BINDIR}")

  # Python 3.8+ uses restricted DLL search paths. Keep the complete oneMKL
  # runtime beside the extension module as well as in bin.
  if(BUILD_PYTHON)
    _directional_install_pardiso_runtime("directional")
  endif()
endif()

if(WIN32)
  install(FILES $<TARGET_RUNTIME_DLLS:directional>
          DESTINATION "${CMAKE_INSTALL_BINDIR}")
  if(DIRECTIONAL_BUILD_CLI)
    install(FILES $<TARGET_RUNTIME_DLLS:directional_cli>
            DESTINATION "${CMAKE_INSTALL_BINDIR}")
  endif()
  if(BUILD_PYTHON)
    # Keep ordinary linked DLLs, including directional.dll and mkl_rt, next
    # to the Python extension. Explicit PARDISO deployment above adds the
    # oneMKL modules that mkl_rt loads dynamically.
    install(FILES $<TARGET_RUNTIME_DLLS:_directional>
            DESTINATION directional)
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

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindCUDSS.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional)
