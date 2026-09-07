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
set(DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES
  src/bench/BenchmarkCases.cpp
  src/bench/BenchmarkQuality.cpp
  tests/AdaptiveFeatureMapPhase11Tests.cpp
  tests/AdaptiveTargetSizePhase12Tests.cpp
  tests/BoundedMeshPreconditionerTests.cpp
  tests/CrossFieldTransferTests.cpp
  tests/FieldAlignedCurveNetworkTests.cpp
  tests/RegularizedCurvaturePhase1Tests.cpp
  tests/support/SurfaceCellProductOracle.cpp
  tests/SourceGridRecoveryAuthorityTests.cpp
  tests/SurfaceCellDesignAcceptanceTests.cpp
  tests/SurfaceCellREPackageTests.cpp
  tests/SurfaceCellTransitionQuotientTests.cpp
  tests/SurfaceCellsPhase10Tests.cpp)

add_executable(
  directional_surface_cell_producer_tests
  ${DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES})
directional_configure_test_target(directional_surface_cell_producer_tests)

function(directional_require_default_packaged_test_contract source_path identity)
  list(FIND DIRECTIONAL_SURFACE_CELL_PRODUCER_TEST_SOURCES "${source_path}"
       _directional_packaged_source_index)
  if(_directional_packaged_source_index EQUAL -1)
    message(FATAL_ERROR
      "Mandatory packaged test contract ${identity} is not owned by the default producer target: ${source_path}")
  endif()

  file(GLOB _directional_test_sources "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
  set(_directional_identity_count 0)
  set(_directional_identity_source "")
  foreach(_directional_test_source IN LISTS _directional_test_sources)
    file(READ "${_directional_test_source}" _directional_test_text)
    string(REGEX MATCHALL "${identity}" _directional_identity_matches
           "${_directional_test_text}")
    list(LENGTH _directional_identity_matches _directional_file_identity_count)
    if(_directional_file_identity_count GREATER 0)
      math(EXPR _directional_identity_count
           "${_directional_identity_count} + ${_directional_file_identity_count}")
      set(_directional_identity_source "${_directional_test_source}")
    endif()
  endforeach()

  if(NOT _directional_identity_count EQUAL 1)
    message(FATAL_ERROR
      "Mandatory packaged test contract ${identity} must have exactly one source definition; found ${_directional_identity_count}")
  endif()

  get_filename_component(_directional_expected_source
    "${CMAKE_CURRENT_SOURCE_DIR}/${source_path}" ABSOLUTE)
  if(NOT _directional_identity_source STREQUAL _directional_expected_source)
    message(FATAL_ERROR
      "Mandatory packaged test contract ${identity} is defined outside its packaged source: ${_directional_identity_source}")
  endif()
endfunction()

function(directional_require_absent_test_contract identity)
  file(GLOB _directional_test_sources "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp")
  set(_directional_identity_count 0)
  foreach(_directional_test_source IN LISTS _directional_test_sources)
    file(READ "${_directional_test_source}" _directional_test_text)
    string(REGEX MATCHALL "${identity}" _directional_identity_matches
           "${_directional_test_text}")
    list(LENGTH _directional_identity_matches _directional_file_identity_count)
    math(EXPR _directional_identity_count
         "${_directional_identity_count} + ${_directional_file_identity_count}")
  endforeach()
  if(NOT _directional_identity_count EQUAL 0)
    message(FATAL_ERROR
      "Retired test contract ${identity} must have zero source definitions; found ${_directional_identity_count}")
  endif()
endfunction()

directional_require_absent_test_contract(
  "LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails")
directional_require_default_packaged_test_contract(
  "tests/SurfaceCellREPackageTests.cpp"
  "AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement")
directional_require_default_packaged_test_contract(
  "tests/SurfaceCellREPackageTests.cpp"
  "InteriorHardRailSeedsBothIncidentFaceCharts")

directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "PublishesTypedSingularityPortsAndMandatoryGraph")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "RejectsInvalidSingularityPortOwnershipOrCount")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "RejectsMissingDuplicateOrForeignMandatoryEdges")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "PreservesBoundaryAndHardFeatureOwnersWithoutNumericAlias")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "IsInvariantToRailAndSourceFaceOrdering")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "DerivesRegionsAsFacesOfTheEmbeddedNetworkGraph")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "PublishesRotationSystemConsistentWithNetworkEvents")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "CoversEverySourceFaceExactlyOnce")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "PreservesMandatoryBoundaryAndHardFeatureEdges")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "RejectsForeignNetworkBindingOrTamperedRegionOwnership")
directional_require_default_packaged_test_contract(
  "tests/FieldAlignedCurveNetworkTests.cpp"
  "RegionAuthorityIsInvariantToEnumerationOrderAndBranchRelabeling")
directional_require_default_packaged_test_contract(
  "tests/SurfaceCellREPackageTests.cpp"
  "ProductionConsumesTypedSkeletonWithoutRawSingularityProjection")

function(directional_require_cp2_typed_network_cutover)
  file(READ "${CMAKE_CURRENT_SOURCE_DIR}/src/pipeline/RemeshPipeline.cpp"
       _directional_cp2_pipeline_text)
  foreach(_directional_forbidden_cp2_marker IN ITEMS
      "tracingOptions.singularityVertices"
      "tracingOptions.singularityIndexNumerators")
    string(FIND "${_directional_cp2_pipeline_text}"
                "${_directional_forbidden_cp2_marker}"
                _directional_forbidden_cp2_index)
    if(NOT _directional_forbidden_cp2_index EQUAL -1)
      message(FATAL_ERROR
        "M3 CP2 production pipeline still reconstructs raw singularity authority: ${_directional_forbidden_cp2_marker}")
    endif()
  endforeach()
  string(FIND "${_directional_cp2_pipeline_text}"
              "tracingOptions.fieldAlignedNetwork = &*fieldAlignedNetworkProduct"
              _directional_cp2_typed_marker)
  if(_directional_cp2_typed_marker EQUAL -1)
    message(FATAL_ERROR
      "M3 CP2 production pipeline lost typed FieldAlignedCurveNetwork ingress")
  endif()
endfunction()

directional_require_cp2_typed_network_cutover()

function(directional_require_re_authority_split source_path)
  file(READ "${CMAKE_CURRENT_SOURCE_DIR}/${source_path}"
       _directional_re_authority_text)
  string(FIND "${_directional_re_authority_text}"
              "AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement"
              _directional_full_pipeline_start)
  string(FIND "${_directional_re_authority_text}"
              "InteriorHardRailSeedsBothIncidentFaceCharts"
              _directional_direct_seed_start)
  if(_directional_full_pipeline_start EQUAL -1 OR
     _directional_direct_seed_start EQUAL -1 OR
     _directional_full_pipeline_start GREATER_EQUAL _directional_direct_seed_start)
    message(FATAL_ERROR
      "R-E packaged authority split identities are missing or ordered unexpectedly")
  endif()
  math(EXPR _directional_full_pipeline_length
       "${_directional_direct_seed_start} - ${_directional_full_pipeline_start}")
  string(SUBSTRING "${_directional_re_authority_text}"
         ${_directional_full_pipeline_start}
         ${_directional_full_pipeline_length}
         _directional_full_pipeline_body)
  string(SUBSTRING "${_directional_re_authority_text}"
         ${_directional_direct_seed_start} -1
         _directional_direct_seed_body)

  set(_directional_full_pipeline_markers
    "make_rectangular_internal_hard_feature_grid"
    "userHardEdges.insert({1, 4})"
    "userHardEdges.insert({4, 7})"
    "ASSERT_TRUE(context.productSnapshots.traceNetwork.phaseFront.is_produced())"
    "EXPECT_FALSE(context.productSnapshots.traceNetwork.phaseFront.product().cells().empty())"
    "EXPECT_EQ(1U, railIds.count(*arc.railId))"
    "EXPECT_TRUE(arc.mandatoryRail)"
    "EXPECT_TRUE(sawHardFlowRepRail)"
    "EXPECT_TRUE(sawBoundaryFlowRepRail)"
    "EXPECT_EQ(\"arrangement\", result.diagnostics.terminalFailureStage)"
    "EXPECT_TRUE(sawArrangementRail)"
    "EXPECT_EQ(1U, railIds.count(*halfedge.railId))"
    "EXPECT_GT(context.tracingCurrentOwnedBytes, 0U)"
    "EXPECT_GT(context.flowRepCurrentOwnedBytes, 0U)"
    "EXPECT_GT(context.arrangementCurrentOwnedBytes, 0U)"
    "find_stage_lineage(result.diagnostics, \"tracing\")"
    "EXPECT_TRUE(tracing->consumedByNextStage)"
    "tracing->outputObject.structuralHash")
  foreach(_directional_full_pipeline_marker IN LISTS _directional_full_pipeline_markers)
    string(FIND "${_directional_full_pipeline_body}"
                "${_directional_full_pipeline_marker}"
                _directional_full_pipeline_marker_index)
    if(_directional_full_pipeline_marker_index EQUAL -1)
      message(FATAL_ERROR
        "R-E full-pipeline authority contract lost required marker: ${_directional_full_pipeline_marker}")
    endif()
  endforeach()

  set(_directional_full_pipeline_forbidden_markers
    "traceNetwork.seeds"
    "sawRailSeed"
    "SurfaceSeedProvenance::Boundary"
    "SurfaceSeedProvenance::Feature")
  foreach(_directional_forbidden_marker IN LISTS _directional_full_pipeline_forbidden_markers)
    string(FIND "${_directional_full_pipeline_body}"
                "${_directional_forbidden_marker}"
                _directional_forbidden_marker_index)
    if(NOT _directional_forbidden_marker_index EQUAL -1)
      message(FATAL_ERROR
        "R-E full-pipeline authority contract illegally reclaims live-seed responsibility: ${_directional_forbidden_marker}")
    endif()
  endforeach()

  set(_directional_direct_seed_markers
    "generate_deterministic_surface_seeds"
    "ASSERT_EQ(4U, seeds.size())"
    "SurfaceSeedProvenance::Feature"
    "ASSERT_TRUE(seed.hardRailId.has_value())"
    "EXPECT_EQ(rail.id, *seed.hardRailId)"
    "EXPECT_EQ(-1, seed.sourceId)"
    "{0, 0}, {0, 1}, {3, 0}, {3, 1}")
  foreach(_directional_direct_seed_marker IN LISTS _directional_direct_seed_markers)
    string(FIND "${_directional_direct_seed_body}"
                "${_directional_direct_seed_marker}"
                _directional_direct_seed_marker_index)
    if(_directional_direct_seed_marker_index EQUAL -1)
      message(FATAL_ERROR
        "R-E direct typed-seed contract lost required marker: ${_directional_direct_seed_marker}")
    endif()
  endforeach()
endfunction()

directional_require_re_authority_split(
  "tests/SurfaceCellREPackageTests.cpp")

directional_copy_manifest_fixture(directional_surface_cell_producer_tests)
target_include_directories(
  directional_surface_cell_producer_tests
  PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src/bench")
if(WIN32)
  target_link_libraries(directional_surface_cell_producer_tests PRIVATE Psapi)
endif()

# Independent public input/output authority. This target is intentionally
# separate from production validators and benchmark-quality decisions.
add_executable(
  directional_surface_cell_oracle_tests
  tests/support/SurfaceCellProductOracle.cpp
  tests/SurfaceCellProductOracleTests.cpp)
directional_configure_test_target(directional_surface_cell_oracle_tests)

# M1 authority-domain kernel contracts. This target validates semantic IDs,
# exact Z4/lattice transport algebra, route canonicalization, and checked
# legacy conversion without migrating existing production consumers.
add_executable(
  directional_surface_cell_authority_kernel_tests
  tests/FieldTransportAtlasTests.cpp
  tests/SurfaceCellAuthorityKernelTests.cpp)
directional_configure_test_target(directional_surface_cell_authority_kernel_tests)

# Default gate 2: downstream topology contracts that remain relevant only after
# the producer supplies a coherent embedded complex.
add_executable(
  directional_surface_cell_completion_tests
  tests/FlowRepStrandsPhase15Tests.cpp
  tests/PatchDescriptorMilestoneETests.cpp
  tests/PureQuadCompletionPhase18Tests.cpp
  tests/SurfaceArrangementRowIdentityTests.cpp
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
  directional_surface_cell_oracle_tests
  TEST_PREFIX "Oracle."
  PROPERTIES LABELS "contract-required;oracle-mutation")
gtest_discover_tests(
  directional_surface_cell_authority_kernel_tests
  TEST_PREFIX "AuthorityKernel."
  PROPERTIES LABELS "contract-required;authority-kernel")
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
