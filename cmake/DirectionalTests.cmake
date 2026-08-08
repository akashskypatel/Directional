enable_testing()
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(external/googletest EXCLUDE_FROM_ALL)

option(
  DIRECTIONAL_BUILD_HISTORICAL_TESTS
  "Build superseded milestone, diagnostic, and implementation-detail tests"
  OFF)
option(
  DIRECTIONAL_BUILD_LEGACY_INTEGRATION_TESTS
  "Build legacy integer-parametrization and pre-surface-cell tests"
  OFF)
option(
  DIRECTIONAL_BUILD_OPTIONAL_GUIDANCE_TESTS
  "Build optional relief-guidance tests"
  OFF)

function(directional_copy_manifest_fixture target_name)
  add_custom_command(
    TARGET ${target_name}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E rm -rf
            "$<TARGET_FILE_DIR:${target_name}>/test-data/benchmarks/fixtures"
    COMMAND ${CMAKE_COMMAND} -E make_directory
            "$<TARGET_FILE_DIR:${target_name}>/test-data/benchmarks"
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            "${CMAKE_CURRENT_SOURCE_DIR}/benchmarks/fixtures"
            "$<TARGET_FILE_DIR:${target_name}>/test-data/benchmarks/fixtures"
    VERBATIM)
endfunction()

function(directional_configure_test_target target_name)
  target_link_libraries(
    ${target_name}
    PRIVATE Directional::directional GTest::gtest_main)
  target_compile_features(${target_name} PRIVATE cxx_std_20)
  target_include_directories(
    ${target_name}
    PRIVATE
      "${CMAKE_CURRENT_SOURCE_DIR}/include"
      "${CMAKE_CURRENT_SOURCE_DIR}/external/eigen")
  if(MSVC)
    target_compile_options(${target_name} PRIVATE /bigobj)
  endif()
  if(WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(
      TARGET ${target_name}
      POST_BUILD
      COMMAND
        ${CMAKE_COMMAND} -E copy_if_different
        $<TARGET_RUNTIME_DLLS:${target_name}>
        $<TARGET_FILE_DIR:${target_name}>
      COMMAND_EXPAND_LISTS
      VERBATIM)
  endif()
endfunction()

add_executable(
  directional_compiled_api_tests
  tests/CompiledLibraryTests.cpp)
directional_configure_test_target(directional_compiled_api_tests)

# Default gate 1: tests that construct or directly accept/reject the intended
# source-attached surface paving. The acceptance matrix deliberately fails until
# plane, multi-face seam, close-sheet, and periodic-cylinder output succeeds
# without legacy fallback or source-grid recovery.
add_executable(
  directional_surface_cell_producer_tests
  src/bench/BenchmarkCases.cpp
  src/bench/BenchmarkQuality.cpp
  tests/AdaptiveFeatureMapPhase11Tests.cpp
  tests/AdaptiveTargetSizePhase12Tests.cpp
  tests/BoundedMeshPreconditionerTests.cpp
  tests/CrossFieldTransferTests.cpp
  tests/RegularizedCurvaturePhase1Tests.cpp
  tests/SurfaceCellDesignAcceptanceTests.cpp
  tests/SurfaceCellTransitionQuotientTests.cpp
  tests/SurfaceCellsPhase10Tests.cpp)
directional_configure_test_target(directional_surface_cell_producer_tests)
directional_copy_manifest_fixture(directional_surface_cell_producer_tests)
target_compile_definitions(
  directional_surface_cell_producer_tests
  PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
target_include_directories(
  directional_surface_cell_producer_tests
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
if(WIN32)
  target_link_libraries(directional_surface_cell_producer_tests PRIVATE Psapi)
endif()

# Default gate 2: downstream topology contracts that remain relevant only after
# the producer supplies a coherent embedded complex.
add_executable(
  directional_surface_cell_completion_tests
  tests/FlowRepStrandsPhase15Tests.cpp
  tests/PatchDescriptorMilestoneETests.cpp
  tests/PureQuadCompletionPhase18Tests.cpp
  tests/SurfaceComplexSimplificationPhase17Tests.cpp)
directional_configure_test_target(directional_surface_cell_completion_tests)

# Default gate 3: source-constrained optimization and authoritative validation.
add_executable(
  directional_surface_cell_validation_tests
  tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp
  tests/SurfaceMeshOptimizerPhase19Tests.cpp
  tests/SurfaceMeshOptimizerPhase20Tests.cpp
  tests/SurfaceMeshOptimizerPhase21Tests.cpp
  tests/SurfaceMeshOptimizerPhase22Tests.cpp)
directional_configure_test_target(directional_surface_cell_validation_tests)

if(DIRECTIONAL_BUILD_OPTIONAL_GUIDANCE_TESTS)
  add_executable(
    directional_surface_cell_guidance_tests
    tests/ReliefTopologyPhase13Tests.cpp)
  directional_configure_test_target(directional_surface_cell_guidance_tests)
endif()

if(DIRECTIONAL_BUILD_LEGACY_INTEGRATION_TESTS)
  add_executable(
    directional_legacy_integration_tests
    src/bench/BenchmarkCases.cpp
    tests/AdaptiveIntegrationSolverTests.cpp
    tests/FunctionSkeletonTests.cpp
    tests/IntegerBatchSelectorTests.cpp
    tests/IntegerTransitionBasisTests.cpp
    tests/LocalPatchValidatorTests.cpp
    tests/ParametrizationQualityTests.cpp
    tests/PatchQuadrangulatorTests.cpp
    tests/RemeshRegressionTests.cpp
    tests/TargetedStiffeningTests.cpp)
  directional_configure_test_target(directional_legacy_integration_tests)
  directional_copy_manifest_fixture(directional_legacy_integration_tests)
  target_compile_definitions(
    directional_legacy_integration_tests
    PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
  target_include_directories(
    directional_legacy_integration_tests
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
  if(WIN32)
    target_link_libraries(directional_legacy_integration_tests PRIVATE Psapi)
  endif()
endif()

if(DIRECTIONAL_BUILD_HISTORICAL_TESTS)
  add_executable(
    directional_surface_cell_historical_tests
    src/bench/BenchmarkCases.cpp
    src/bench/BenchmarkQuality.cpp
    tests/ComponentParallelismTests.cpp
    tests/DiagnosticsTests.cpp
    tests/MilestoneBClosureTests.cpp
    tests/MilestoneCClosureTests.cpp
    tests/MilestoneDClosureTests.cpp
    tests/MilestoneFP19IntegrationTests.cpp
    tests/MilestoneGP23Tests.cpp
    tests/MilestoneGP24Tests.cpp
    tests/MilestoneGP25Tests.cpp
    tests/MilestoneGP26Tests.cpp
    tests/MilestoneGP27Tests.cpp
    tests/SurfaceArrangementPhase16Tests.cpp
    tests/SurfaceCellPipelinePhase20Tests.cpp
    tests/SurfaceCellTracingPhase14Tests.cpp)
  directional_configure_test_target(directional_surface_cell_historical_tests)
  directional_copy_manifest_fixture(directional_surface_cell_historical_tests)
  target_compile_definitions(
    directional_surface_cell_historical_tests
    PRIVATE DIRECTIONAL_TEST_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}")
  target_include_directories(
    directional_surface_cell_historical_tests
    PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
  if(WIN32)
    target_link_libraries(directional_surface_cell_historical_tests PRIVATE Psapi)
  endif()
endif()

include(GoogleTest)
gtest_discover_tests(
  directional_compiled_api_tests
  PROPERTIES LABELS "api")
gtest_discover_tests(
  directional_surface_cell_producer_tests
  TEST_PREFIX "Producer."
  PROPERTIES LABELS "surface-cell;producer")
gtest_discover_tests(
  directional_surface_cell_completion_tests
  TEST_PREFIX "Completion."
  PROPERTIES LABELS "surface-cell;completion")
gtest_discover_tests(
  directional_surface_cell_validation_tests
  TEST_PREFIX "Validation."
  PROPERTIES LABELS "surface-cell;validation")

if(DIRECTIONAL_BUILD_OPTIONAL_GUIDANCE_TESTS)
  gtest_discover_tests(
    directional_surface_cell_guidance_tests
    TEST_PREFIX "Guidance."
    PROPERTIES LABELS "surface-cell;optional-guidance")
endif()

if(DIRECTIONAL_BUILD_LEGACY_INTEGRATION_TESTS)
  gtest_discover_tests(
    directional_legacy_integration_tests
    TEST_PREFIX "Legacy."
    PROPERTIES LABELS "legacy")
endif()

if(DIRECTIONAL_BUILD_HISTORICAL_TESTS)
  gtest_discover_tests(
    directional_surface_cell_historical_tests
    TEST_PREFIX "Historical."
    PROPERTIES LABELS "historical")
endif()
