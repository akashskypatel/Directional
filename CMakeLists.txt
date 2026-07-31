cmake_minimum_required(VERSION 3.21)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(
  Directional
  VERSION 1.0.0
  LANGUAGES CXX)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

option(BUILD_TUTORIALS "Build Directional tutorials" OFF)
option(BUILD_PYTHON "Build Python bindings" OFF)
option(DIRECTIONAL_BUILD_CLI
       "Build the optional native command line executable" OFF)
option(DIRECTIONAL_BUILD_GUI
       "Build the optional Polyscope desktop UI" OFF)
option(DIRECTIONAL_BUILD_BENCHMARKS "Build Directional benchmark tools" OFF)
option(DIRECTIONAL_BUILD_TESTS "Build Directional unit tests" OFF)
option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(
  DIRECTIONAL_ENABLE_GMP
  "Enable GMP support. Will be auto-installed on MSVC if not found"
  ON)

set(_directional_pardiso_default OFF)
if(WIN32 AND MSVC)
  set(_directional_pardiso_default ON)
endif()

option(
  DIRECTIONAL_ENABLE_PARDISO
  "Enable Intel oneMKL PARDISO integration solver"
  ${_directional_pardiso_default})
option(
  DIRECTIONAL_ENABLE_CUDSS
  "Enable NVIDIA cuDSS integration solver"
  OFF)
option(
  DIRECTIONAL_ENABLE_SUITESPARSE
  "Enable SuiteSparse UMFPACK integration solver"
  OFF)

unset(_directional_pardiso_default)

set(CUDSS_ROOT
    ""
    CACHE PATH "Root directory of an NVIDIA cuDSS installation")

# Only one optional integration solver backend is selected. Eigen SparseLU
# remains the baseline fallback when SuiteSparse is not compiled.
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

list(
  LENGTH _directional_requested_solver_backends
  _directional_requested_solver_backend_count)

if(_directional_requested_solver_backend_count GREATER 1)
  list(
    GET _directional_requested_solver_backends 0
    _directional_selected_solver_backend)

  string(
    JOIN ", "
    _directional_requested_solver_backend_list
    ${_directional_requested_solver_backends})

  message(
    WARNING
      "Multiple integration solver backends were requested: "
      "${_directional_requested_solver_backend_list}. Only "
      "${_directional_selected_solver_backend} will be enabled. "
      "Selection priority is PARDISO, CUDSS, SUITESPARSE.")

  set(
    DIRECTIONAL_ENABLE_PARDISO OFF
    CACHE BOOL "Enable Intel oneMKL PARDISO integration solver" FORCE)
  set(
    DIRECTIONAL_ENABLE_CUDSS OFF
    CACHE BOOL "Enable NVIDIA cuDSS integration solver" FORCE)
  set(
    DIRECTIONAL_ENABLE_SUITESPARSE OFF
    CACHE BOOL "Enable SuiteSparse UMFPACK integration solver" FORCE)

  if(_directional_selected_solver_backend STREQUAL "PARDISO")
    set(
      DIRECTIONAL_ENABLE_PARDISO ON
      CACHE BOOL "Enable Intel oneMKL PARDISO integration solver" FORCE)
  elseif(_directional_selected_solver_backend STREQUAL "CUDSS")
    set(
      DIRECTIONAL_ENABLE_CUDSS ON
      CACHE BOOL "Enable NVIDIA cuDSS integration solver" FORCE)
  elseif(_directional_selected_solver_backend STREQUAL "SUITESPARSE")
    set(
      DIRECTIONAL_ENABLE_SUITESPARSE ON
      CACHE BOOL "Enable SuiteSparse UMFPACK integration solver" FORCE)
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

add_library(
  directional
  src/core/Library.cpp
  src/diagnostics/RemeshDiagnostics.cpp
  src/fields/CompareCrossFields.cpp
  src/fields/CrossField.cpp
  src/fields/CurlMatching.cpp
  src/fields/FieldCombing.cpp
  src/fields/FieldMatching.cpp
  src/fields/FieldOperators.cpp
  src/fields/IndexPrescription.cpp
  src/fields/PointSampledCrossField.cpp
  src/fields/PointwiseVectors.cpp
  src/fields/PolyVectorField.cpp
  src/fields/PolyVectorIteration.cpp
  src/fields/PolyVectorToRaw.cpp
  src/fields/PowerField.cpp
  src/fields/PowerToRaw.cpp
  src/fields/ProjectCurl.cpp
  src/fields/RawToPolyVector.cpp
  src/fields/RegularizedCurvatureCrossField.cpp
  src/fields/RotationToRaw.cpp
  src/fields/ShapeOperatorAlignment.cpp
  src/geometry/AdaptiveFeatureMap.cpp
  src/geometry/AdaptiveFeatureMapVisualizer.cpp
  src/geometry/AdaptiveTargetSize.cpp
  src/geometry/BarycentricCoordinates.cpp
  src/geometry/BarycentricSubdivision.cpp
  src/geometry/BranchedIsolines.cpp
  src/geometry/Curvature.cpp
  src/geometry/CutMesh.cpp
  src/geometry/FaceCurvature.cpp
  src/geometry/FlowRepStrands.cpp
  src/geometry/MeshComponents.cpp
  src/geometry/MeshTopology.cpp
  src/geometry/PatchDescriptor.cpp
  src/geometry/PolyToConstantSubdivision.cpp
  src/geometry/PureQuadCompletion.cpp
  src/geometry/RegularizedProxyMesh.cpp
  src/geometry/ReliefTopology.cpp
  src/geometry/Streamlines.cpp
  src/geometry/SurfaceArrangement.cpp
  src/geometry/SurfaceCellTracing.cpp
  src/geometry/SurfaceComplexSimplification.cpp
  src/geometry/SurfaceMeshOptimizer.cpp
  src/geometry/SurfaceOptimizationRailConstraints.cpp
  src/geometry/SurfacePoint.cpp
  src/geometry/TensorCurvatureTarget.cpp
  src/integration/Integrate.cpp
  src/integration/ParametrizationQuality.cpp
  src/integration/SetupIntegration.cpp
  src/meshing/Mesher.cpp
  src/meshing/SetupMesher.cpp
  src/pipeline/ParallelRemeshPipeline.cpp
  src/pipeline/RemeshPipeline.cpp
  src/validation/MeshValidator.cpp
  src/validation/SourceAuthoritativeMeshValidator.cpp
  src/validation/ValidationVisualizer.cpp)
add_library(Directional::directional ALIAS directional)

set_target_properties(
  directional
  PROPERTIES OUTPUT_NAME directional
             VERSION ${PROJECT_VERSION}
             SOVERSION ${PROJECT_VERSION_MAJOR}
             WINDOWS_EXPORT_ALL_SYMBOLS ON)
target_compile_definitions(
  directional
  PRIVATE DIRECTIONAL_BUILDING_LIBRARY
  PUBLIC DIRECTIONAL_VERSION="${CMAKE_PROJECT_VERSION}"
         $<$<BOOL:${BUILD_SHARED_LIBS}>:DIRECTIONAL_SHARED>)
target_include_directories(
  directional
  PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
         $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/external/eigen>
         $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)

target_compile_features(directional PUBLIC cxx_std_20)

if(MSVC)
  set_source_files_properties(
    src/integration/Integrate.cpp
    src/meshing/Mesher.cpp
    PROPERTIES COMPILE_OPTIONS "/bigobj")
endif()

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
  
  target_compile_definitions(directional PUBLIC DIRECTIONAL_HAS_PARDISO)
  target_link_libraries(directional PUBLIC MKL::MKL)
  _directional_collect_pardiso_runtime_files(
    DIRECTIONAL_PARDISO_RUNTIME_FILES)
elseif(DIRECTIONAL_ENABLE_CUDSS)
  find_package(CUDSS REQUIRED)
  if(NOT TARGET CUDSS::cudss)
    message(FATAL_ERROR "DIRECTIONAL_ENABLE_CUDSS requires CUDSS::cudss")
  endif()
  target_compile_definitions(directional PUBLIC DIRECTIONAL_HAS_CUDSS)
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
      PUBLIC DIRECTIONAL_ENABLE_SUITESPARSE USE_SUITESPARSE
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
      directional PUBLIC DIRECTIONAL_ENABLE_GMP USE_GMP USE_GMP_ENABLED
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

if(DIRECTIONAL_BUILD_TESTS)
  enable_testing()
  set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  add_subdirectory(external/googletest EXCLUDE_FROM_ALL)

  add_executable(
    directional_compiled_api_tests
    tests/CompiledLibraryTests.cpp)
  target_link_libraries(
    directional_compiled_api_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_compiled_api_tests PRIVATE cxx_std_20)

  add_executable(
    directional_phase1_tests
    src/bench/BenchmarkCases.cpp
    src/bench/BenchmarkQuality.cpp
    tests/AdaptiveFeatureMapPhase11Tests.cpp
    tests/AdaptiveTargetSizePhase12Tests.cpp
    tests/AdaptiveIntegrationSolverTests.cpp
    tests/BoundedMeshPreconditionerTests.cpp
    tests/ComponentParallelismTests.cpp
    tests/CrossFieldTransferTests.cpp
    tests/DiagnosticsTests.cpp
    tests/FlowRepStrandsPhase15Tests.cpp
    tests/FunctionSkeletonTests.cpp
    tests/IntegerBatchSelectorTests.cpp
    tests/IntegerTransitionBasisTests.cpp
    tests/LocalPatchValidatorTests.cpp
    tests/MilestoneFP19IntegrationTests.cpp
    tests/MilestoneGP23Tests.cpp
    tests/MilestoneGP24Tests.cpp
    tests/MilestoneGP25Tests.cpp
    tests/MilestoneGP26Tests.cpp
    tests/MilestoneGP27Tests.cpp
    tests/MilestoneBClosureTests.cpp
    tests/MilestoneCClosureTests.cpp
    tests/MilestoneDClosureTests.cpp
    tests/ParametrizationQualityTests.cpp
    tests/PatchDescriptorMilestoneETests.cpp
    tests/PatchQuadrangulatorTests.cpp
    tests/PureQuadCompletionPhase18Tests.cpp
    tests/RemeshRegressionTests.cpp
    tests/RegularizedCurvaturePhase1Tests.cpp
    tests/SurfaceArrangementPhase16Tests.cpp
    tests/SurfaceComplexSimplificationPhase17Tests.cpp
    tests/SurfaceCellPipelinePhase20Tests.cpp
    tests/SurfaceMeshOptimizerPhase19Tests.cpp
    tests/SurfaceMeshOptimizerPhase20Tests.cpp
    tests/SurfaceMeshOptimizerPhase21Tests.cpp
    tests/SurfaceMeshOptimizerPhase22Tests.cpp
    tests/ReliefTopologyPhase13Tests.cpp
    tests/SurfaceCellTracingPhase14Tests.cpp
    tests/SurfaceCellsPhase10Tests.cpp
    tests/TargetedStiffeningTests.cpp)
  target_link_libraries(
    directional_phase1_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_phase1_tests PRIVATE cxx_std_20)
  target_compile_definitions(
    directional_phase1_tests
    PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
  target_include_directories(
    directional_phase1_tests
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
  if(MSVC)
    target_compile_options(directional_phase1_tests PRIVATE /bigobj)
  endif()
  if(WIN32)
    target_link_libraries(directional_phase1_tests PRIVATE Psapi)
  endif()
  if(WIN32)
    add_custom_command(
      TARGET directional_phase1_tests
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_phase1_tests>
        $<TARGET_FILE_DIR:directional_phase1_tests>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  add_executable(
    directional_milestone_g_p23_tests
    src/bench/BenchmarkCases.cpp
    tests/MilestoneGP23Tests.cpp
    tests/SurfaceCellPipelinePhase20Tests.cpp)
  target_link_libraries(
    directional_milestone_g_p23_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_milestone_g_p23_tests PRIVATE cxx_std_20)
  target_compile_definitions(
    directional_milestone_g_p23_tests
    PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
  target_include_directories(
    directional_milestone_g_p23_tests
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen"
      "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
  if(MSVC)
    target_compile_options(directional_milestone_g_p23_tests PRIVATE /bigobj)
  endif()
  if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
      TARGET directional_milestone_g_p23_tests
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_g_p23_tests>
        $<TARGET_FILE_DIR:directional_milestone_g_p23_tests>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  add_executable(
    directional_milestone_g_p27_tests
    src/bench/BenchmarkCases.cpp
    src/bench/BenchmarkQuality.cpp
    tests/MilestoneGP27Tests.cpp)
  target_link_libraries(
    directional_milestone_g_p27_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_milestone_g_p27_tests PRIVATE cxx_std_20)
  target_compile_definitions(
    directional_milestone_g_p27_tests
    PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
  target_include_directories(
    directional_milestone_g_p27_tests
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
  if(MSVC)
    target_compile_options(directional_milestone_g_p27_tests PRIVATE /bigobj)
  endif()
  if(WIN32)
    target_link_libraries(directional_milestone_g_p27_tests PRIVATE Psapi)
  endif()

  add_executable(
    directional_milestone_g_p24_tests
    src/bench/BenchmarkCases.cpp
    tests/DiagnosticsTests.cpp
    tests/MilestoneGP24Tests.cpp
    tests/SurfaceCellPipelinePhase20Tests.cpp)
  target_link_libraries(
    directional_milestone_g_p24_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_milestone_g_p24_tests PRIVATE cxx_std_20)
  target_compile_definitions(
    directional_milestone_g_p24_tests
    PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
  target_include_directories(
    directional_milestone_g_p24_tests
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen"
      "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
  if(MSVC)
    target_compile_options(directional_milestone_g_p24_tests PRIVATE /bigobj)
  endif()
  if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
      TARGET directional_milestone_g_p24_tests
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_g_p24_tests>
        $<TARGET_FILE_DIR:directional_milestone_g_p24_tests>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  add_executable(
    directional_milestone_g_p25_tests
    src/bench/BenchmarkCases.cpp
    tests/ComponentParallelismTests.cpp
    tests/MilestoneGP25Tests.cpp
    tests/SurfaceCellPipelinePhase20Tests.cpp)
  target_link_libraries(
    directional_milestone_g_p25_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_milestone_g_p25_tests PRIVATE cxx_std_20)
  target_compile_definitions(
    directional_milestone_g_p25_tests
    PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
  target_include_directories(
    directional_milestone_g_p25_tests
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen"
      "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
  if(MSVC)
    target_compile_options(directional_milestone_g_p25_tests PRIVATE /bigobj)
  endif()
  if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
      TARGET directional_milestone_g_p25_tests
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_g_p25_tests>
        $<TARGET_FILE_DIR:directional_milestone_g_p25_tests>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  add_executable(
    directional_milestone_g_p26_tests
    src/bench/BenchmarkCases.cpp
    tests/MilestoneGP26Tests.cpp
    tests/SurfaceCellPipelinePhase20Tests.cpp)
  target_link_libraries(
    directional_milestone_g_p26_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_milestone_g_p26_tests PRIVATE cxx_std_20)
  target_compile_definitions(
    directional_milestone_g_p26_tests
    PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
  target_include_directories(
    directional_milestone_g_p26_tests
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen"
      "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
  if(MSVC)
    target_compile_options(directional_milestone_g_p26_tests PRIVATE /bigobj)
  endif()
  if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
      TARGET directional_milestone_g_p26_tests
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_g_p26_tests>
        $<TARGET_FILE_DIR:directional_milestone_g_p26_tests>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  add_executable(
    directional_milestone_c_tests
    tests/MilestoneCClosureTests.cpp
    tests/SurfaceCellTracingPhase14Tests.cpp
    tests/FlowRepStrandsPhase15Tests.cpp)
  target_link_libraries(
    directional_milestone_c_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_milestone_c_tests PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_c_tests PRIVATE /bigobj)
  endif()
  if(WIN32)
    add_custom_command(
      TARGET directional_milestone_c_tests
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_c_tests>
        $<TARGET_FILE_DIR:directional_milestone_c_tests>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  add_executable(
    directional_milestone_d_tests
    tests/MilestoneDClosureTests.cpp
    tests/SurfaceArrangementPhase16Tests.cpp
    tests/SurfaceComplexSimplificationPhase17Tests.cpp)
  target_link_libraries(
    directional_milestone_d_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_milestone_d_tests PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_d_tests PRIVATE /bigobj)
  endif()
  if(WIN32)
    add_custom_command(
      TARGET directional_milestone_d_tests
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_d_tests>
        $<TARGET_FILE_DIR:directional_milestone_d_tests>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()


  add_executable(
    directional_milestone_e_tests
    tests/PatchDescriptorMilestoneETests.cpp
    tests/PureQuadCompletionPhase18Tests.cpp)
  target_link_libraries(
    directional_milestone_e_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(directional_milestone_e_tests PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_e_tests PRIVATE /bigobj)
  endif()
  if(WIN32)
    add_custom_command(
      TARGET directional_milestone_e_tests
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_e_tests>
        $<TARGET_FILE_DIR:directional_milestone_e_tests>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  add_executable(
    directional_milestone_f_tests
    tests/SurfaceMeshOptimizerPhase19Tests.cpp
    tests/SurfaceMeshOptimizerPhase20Tests.cpp
    tests/SurfaceMeshOptimizerPhase21Tests.cpp
    tests/SurfaceMeshOptimizerPhase22Tests.cpp
    tests/MilestoneFP19IntegrationTests.cpp
    tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp)
  target_link_libraries(
    directional_milestone_f_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_include_directories(
    directional_milestone_f_tests
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen")
  target_compile_features(directional_milestone_f_tests PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_f_tests PRIVATE /bigobj)
  endif()

  add_executable(
    directional_milestone_f_optimizer_tests
    tests/SurfaceMeshOptimizerPhase19Tests.cpp
    tests/SurfaceMeshOptimizerPhase20Tests.cpp
    tests/SurfaceMeshOptimizerPhase21Tests.cpp
    tests/SurfaceMeshOptimizerPhase22Tests.cpp
    tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp)
  target_link_libraries(
    directional_milestone_f_optimizer_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_include_directories(
    directional_milestone_f_optimizer_tests
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen")
  target_compile_features(directional_milestone_f_optimizer_tests PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_f_optimizer_tests PRIVATE /bigobj)
  endif()

  add_executable(
    directional_milestone_f_validator_tests
    tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp)
  target_link_libraries(
    directional_milestone_f_validator_tests
    PRIVATE Directional::directional GTest::gtest_main)
  target_include_directories(
    directional_milestone_f_validator_tests
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen")
  target_compile_features(directional_milestone_f_validator_tests PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_f_validator_tests PRIVATE /bigobj)
  endif()

  add_executable(
    directional_milestone_f_benchmark
    tests/MilestoneFBenchmark.cpp)
  target_link_libraries(
    directional_milestone_f_benchmark
    PRIVATE Directional::directional)
  target_include_directories(
    directional_milestone_f_benchmark
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen")
  target_compile_features(directional_milestone_f_benchmark PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_f_benchmark PRIVATE /bigobj)
  endif()
  if(WIN32)
    target_link_libraries(directional_milestone_f_benchmark PRIVATE Psapi)
  endif()

  add_executable(
    directional_milestone_d_benchmark
    tests/MilestoneDBenchmark.cpp)
  target_link_libraries(
    directional_milestone_d_benchmark
    PRIVATE Directional::directional)
  target_compile_features(directional_milestone_d_benchmark PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_d_benchmark PRIVATE /bigobj)
  endif()
  if(WIN32)
    add_custom_command(
      TARGET directional_milestone_d_benchmark
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_d_benchmark>
        $<TARGET_FILE_DIR:directional_milestone_d_benchmark>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  add_executable(
    directional_milestone_c_benchmark
    tests/MilestoneCBenchmark.cpp)
  target_link_libraries(
    directional_milestone_c_benchmark
    PRIVATE Directional::directional)
  target_compile_features(directional_milestone_c_benchmark PRIVATE cxx_std_20)
  if(MSVC)
    target_compile_options(directional_milestone_c_benchmark PRIVATE /bigobj)
  endif()
  if(WIN32)
    add_custom_command(
      TARGET directional_milestone_c_benchmark
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_milestone_c_benchmark>
        $<TARGET_FILE_DIR:directional_milestone_c_benchmark>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()

  include(GoogleTest)
  gtest_discover_tests(directional_compiled_api_tests)
  gtest_discover_tests(directional_phase1_tests)
  gtest_discover_tests(directional_milestone_g_p23_tests TEST_PREFIX "P23Focused.")
  gtest_discover_tests(directional_milestone_g_p24_tests TEST_PREFIX "P24Focused.")
  gtest_discover_tests(directional_milestone_g_p25_tests TEST_PREFIX "P25Focused.")
  gtest_discover_tests(directional_milestone_g_p26_tests TEST_PREFIX "P26Focused.")
  gtest_discover_tests(directional_milestone_c_tests)
  gtest_discover_tests(directional_milestone_d_tests)
  gtest_discover_tests(directional_milestone_e_tests)
endif()

if(DIRECTIONAL_BUILD_CLI OR BUILD_PYTHON OR DIRECTIONAL_BUILD_GUI)
  add_library(
    directional_cli_io STATIC
    src/cli/ProgressDisplay.cpp
    src/cli/MeshIO.cpp
    src/cli/MatrixIO.cpp
    src/cli/CrossFieldOutput.cpp
    src/cli/FieldConversion.cpp
    src/cli/RemeshOutput.cpp)
  add_library(Directional::directional_cli_io ALIAS directional_cli_io)
  set_target_properties(directional_cli_io PROPERTIES POSITION_INDEPENDENT_CODE ON)
  target_link_libraries(directional_cli_io PUBLIC Directional::directional)
  target_compile_features(directional_cli_io PUBLIC cxx_std_20)
  target_compile_definitions(directional_cli_io INTERFACE DIRECTIONAL_VERSION="${CMAKE_PROJECT_VERSION}")
  if(DIRECTIONAL_BUILD_CLI OR BUILD_PYTHON)
    add_library(
      directional_cli_backend STATIC
      src/cli/CliBackend.cpp
      src/cli/Usage.cpp
      src/cli/InfoCommand.cpp
      src/cli/CrossFieldCommand.cpp
      src/cli/SimplifyCommand.cpp
      src/cli/RemeshCommand.cpp)
    add_library(Directional::directional_cli_backend ALIAS directional_cli_backend)
    set_target_properties(directional_cli_backend PROPERTIES POSITION_INDEPENDENT_CODE ON)
    target_link_libraries(
      directional_cli_backend
      PUBLIC
        Directional::directional_cli_io)
    target_compile_features(directional_cli_backend PUBLIC cxx_std_20)
    target_compile_definitions(
      directional_cli_backend PRIVATE DIRECTIONAL_VERSION="${CMAKE_PROJECT_VERSION}")

    # Keep MSVC's expanded COFF section limit scoped to the two translation
    # units that instantiate Directional's template-heavy field and pipeline APIs.
    if(MSVC)
      set_source_files_properties(
        src/cli/CliBackend.cpp
        src/cli/CrossFieldCommand.cpp
        src/cli/SimplifyCommand.cpp
        src/cli/RemeshCommand.cpp
        PROPERTIES COMPILE_OPTIONS "/bigobj")
    endif()
  endif()
endif()

if(DIRECTIONAL_ENABLE_PARDISO)
  _directional_copy_pardiso_runtime_to_target(directional)
endif()

if(DIRECTIONAL_BUILD_BENCHMARKS)
  add_executable(
    directional_benchmarks
    src/bench/BenchmarkCases.cpp
    src/bench/BenchmarkQuality.cpp
    src/bench/DirectionalBenchmark.cpp)
  target_link_libraries(directional_benchmarks PRIVATE Directional::directional)
  target_compile_features(directional_benchmarks PRIVATE cxx_std_20)
  target_compile_definitions(
    directional_benchmarks PRIVATE DIRECTIONAL_VERSION="${CMAKE_PROJECT_VERSION}")
  if(MSVC)
    target_compile_options(directional_benchmarks PRIVATE /bigobj)
  endif()
  if(WIN32)
    target_link_libraries(directional_benchmarks PRIVATE Psapi)
  endif()
endif()

if(DIRECTIONAL_BUILD_CLI)
  add_executable(directional_cli src/cli/Main.cpp)
  add_executable(Directional::directional_cli ALIAS directional_cli)
  set_target_properties(directional_cli PROPERTIES OUTPUT_NAME directional)
  target_link_libraries(directional_cli PRIVATE Directional::directional_cli_backend)
  target_compile_features(directional_cli PRIVATE cxx_std_20)
  target_compile_definitions(directional_cli PRIVATE DIRECTIONAL_VERSION="${CMAKE_PROJECT_VERSION}")
  if(DIRECTIONAL_ENABLE_PARDISO)
    _directional_copy_pardiso_runtime_to_target(directional_cli)
  endif()
endif()

if(DIRECTIONAL_BUILD_GUI)
  if(NOT TARGET polyscope)
    if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/external/polyscope/CMakeLists.txt")
      set(_directional_saved_build_shared_libs "${BUILD_SHARED_LIBS}")
      set(BUILD_SHARED_LIBS OFF)
      add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/external/polyscope"
                     "${CMAKE_BINARY_DIR}/polyscope")

      set(BUILD_SHARED_LIBS "${_directional_saved_build_shared_libs}")
      unset(_directional_saved_build_shared_libs)
    else()
      find_package(polyscope CONFIG REQUIRED)
    endif()
  endif()

  if(TARGET imgui)
    add_dependencies(polyscope imgui)
  endif()

  set(_directional_gui_sources
      src/gui/Main.cpp
      src/gui/FilePicker.cpp
      src/gui/GuiBackend.cpp
      src/gui/GuiSimplify.cpp
      src/gui/SessionLog.cpp
      src/gui/GuiField.cpp
      src/gui/GuiRemesh.cpp)

  if(WIN32)
    list(APPEND _directional_gui_sources src/gui/FileDialogWindows.cpp)
  elseif(APPLE)
    enable_language(OBJCXX)
    list(APPEND _directional_gui_sources src/gui/FileDialogMac.mm)
  elseif(UNIX)
    list(APPEND _directional_gui_sources src/gui/FileDialogLinux.cpp)
  endif()

  add_executable(directional_gui ${_directional_gui_sources})
  unset(_directional_gui_sources)
  add_executable(Directional::directional_gui ALIAS directional_gui)
  set_target_properties(directional_gui PROPERTIES OUTPUT_NAME directional-ui)
  target_compile_definitions(directional_gui PRIVATE DIRECTIONAL_VERSION="${CMAKE_PROJECT_VERSION}")
  target_link_libraries(
    directional_gui
    PRIVATE
      Directional::directional_cli_io
      polyscope)

  if(WIN32)
    target_link_libraries(directional_gui PRIVATE ole32 shell32 uuid)
  elseif(APPLE)
    find_library(DIRECTIONAL_APPKIT_FRAMEWORK AppKit REQUIRED)
    find_library(DIRECTIONAL_UTTYPE_FRAMEWORK UniformTypeIdentifiers REQUIRED)
    target_link_libraries(
      directional_gui
      PRIVATE
        ${DIRECTIONAL_APPKIT_FRAMEWORK}
        ${DIRECTIONAL_UTTYPE_FRAMEWORK})
  elseif(UNIX)
    find_package(PkgConfig QUIET)
    if(PkgConfig_FOUND)
      pkg_check_modules(DIRECTIONAL_GIO QUIET IMPORTED_TARGET gio-2.0)
    endif()

    if(TARGET PkgConfig::DIRECTIONAL_GIO)
      target_compile_definitions(
        directional_gui PRIVATE DIRECTIONAL_GUI_HAS_GIO=1)
      target_link_libraries(
        directional_gui PRIVATE PkgConfig::DIRECTIONAL_GIO)
    else()
      message(WARNING
        "GIO/GDBus was not found. directional-ui will use its ImGui file "
        "picker instead of the XDG Desktop Portal on Linux.")
    endif()
  endif()
  target_include_directories(
    directional_gui
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/src/cli")
  target_compile_features(directional_gui PRIVATE cxx_std_20)
  if(APPLE)
    set_target_properties(
      directional_gui
      PROPERTIES
        OBJCXX_STANDARD 20
        OBJCXX_STANDARD_REQUIRED YES
        OBJCXX_EXTENSIONS NO)
  endif()
  if(MSVC)
    target_compile_options(directional_gui PRIVATE /bigobj)
  endif()
  if(WIN32)
    add_custom_command(
      TARGET directional_gui
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:directional_gui>
        $<TARGET_FILE_DIR:directional_gui>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()
  if(DIRECTIONAL_ENABLE_PARDISO)
    _directional_copy_pardiso_runtime_to_target(directional_gui)
  endif()

  install(TARGETS directional_gui RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()

if(BUILD_PYTHON)
  find_package(Python REQUIRED COMPONENTS Interpreter Development.Module)
  find_package(pybind11 CONFIG REQUIRED)

  pybind11_add_module(_directional MODULE python/src/bindings.cpp)
  target_link_libraries(
    _directional PRIVATE Directional::directional
                         Directional::directional_cli_backend)
  target_compile_features(_directional PRIVATE cxx_std_20)
  target_compile_definitions(_directional INTERFACE DIRECTIONAL_VERSION="${CMAKE_PROJECT_VERSION}")
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
  if(DIRECTIONAL_BUILD_GUI)
    install(FILES $<TARGET_RUNTIME_DLLS:directional_gui>
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
  VERSION ${CMAKE_PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)

install(FILES ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfig.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/DirectionalConfigVersion.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional)

install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindCUDSS.cmake
        DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/Directional)
