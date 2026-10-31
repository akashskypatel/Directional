# M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC-R2 — Test + Benchmark complete (2026-10-29)

**Disposition: 408/408 OBSERVE census executed and independently verified; 323 PASS / 83 RED / 2 ABNORMAL / 0 INVALID. No classifications made; no CP3 acceptance or selector497 promotion. Exact successor:** `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION`.

**Provenance:** [GitHub Actions run 40965775275](https://github.com/akashskypatel/Directional/actions/runs/40965775275), event `931f0e5050aaab7b36d0a432fce166deb11de302`, mailbox `workflow-mailbox/.workflow-mailbox/m6-cp3-tb50c-r2-census-20261029-v1/latest.json` (mailbox event/source verified; all jobs successful except deliberately skipped compile, noop, drive apply). Immutable CB52 artifact `12918290481`, semantic source `7cf0857b4818186638ce77e4859adacbeebd288f`, frozen 408 manifest SHA256 `918239009ddee28ebc5c212ef3db0babf2b9f2b8a2755f4321242b7a1ea2ac86`, harness SHA256 `600c6455203519e79736e501288e4777921390bf365a9d3ee5e0141aa49275f8`.

**Artifact verification:** result `12941320247` ZIP/provider SHA256 `a18758bda0a0877f75f6a82876eb1256f39b51ba9c8a325e80f7c4f72452d18c`; log `12940158599` ZIP/provider SHA256 `eb4d98fafe42e61d08ccc795c4b2ee5db529ae5f4b84f129b67fc0099b53e1a8`. Result archive 822/822 checksums, manifest↔ledger 408/408 identities, raw log SHA 408/408, 408 resource traces. Boundary `planned=executed=408`, `passed=323`, `red=83`, `abnormal=2`, `missing=skipped=duplicate=control_bad=0`, `postflight=true`, `exit=0`, `compile=relink=configure=benchmark=false`, empty error. All 85 non-PASS rows below are **observation only**, not classified stable regressions.

**Boundary:** CP2 491/491 is last accepted semantic baseline; TB50-R2 508/508 is independently reviewed candidate. Stable 66/17/49 and debt1 unchanged pending disposition. No native builds or local tests; no code/test/fixture changes.

## Independently verified detailed ledger and per-suite counts

- Outer ZIP digest: `a18758bda0a0877f75f6a82876eb1256f39b51ba9c8a325e80f7c4f72452d18c`
- Internal checksums verified: **822/822**
- Frozen manifest checksum: `918239009ddee28ebc5c212ef3db0babf2b9f2b8a2755f4321242b7a1ea2ac86`
- 408/408 manifest-ledger identities and 408/408 raw log digests verified
- Immutable source `7cf0857b4818186638ce77e4859adacbeebd288f`, package `12918290481`
- Boundary: `{"artifact": 12918290481, "benchmark": false, "compile": false, "configure": false, "error": "", "exit": 0, "relink": false, "source": "7cf0857b4818186638ce77e4859adacbeebd288f", "state": {"abnormal": 2, "control_bad": 0, "duplicate": 0, "executed": 408, "later_positive_red": 0, "missing": 0, "passed": 323, "planned": 408, "postflight": true, "red": 83, "red_site_bad": 0, "skipped": 0, "unexpected_pass": 0}}`

## By binary

| Binary | PASS | RED | ABNORMAL | INVALID | Total |
|---|---:|---:|---:|---:|---:|
| `directional_surface_cell_authority_kernel_tests` | 7 | 0 | 0 | 0 | 7 |
| `directional_surface_cell_completion_tests` | 71 | 41 | 0 | 0 | 112 |
| `directional_surface_cell_producer_tests` | 211 | 33 | 2 | 0 | 246 |
| `directional_surface_cell_validation_tests` | 34 | 9 | 0 | 0 | 43 |

## By binary and suite

| Binary | Suite | PASS | RED | ABNORMAL | INVALID | Total |
|---|---|---:|---:|---:|---:|---:|
| `directional_surface_cell_authority_kernel_tests` | `FieldTransportAtlas` | 6 | 0 | 0 | 0 | 6 |
| `directional_surface_cell_authority_kernel_tests` | `M6CP3` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_completion_tests` | `FlowRepStrandsPhase15` | 26 | 17 | 0 | 0 | 43 |
| `directional_surface_cell_completion_tests` | `M4CP4` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_completion_tests` | `PatchDescriptorMilestoneE` | 7 | 11 | 0 | 0 | 18 |
| `directional_surface_cell_completion_tests` | `PureQuadCompletionPhase18` | 25 | 0 | 0 | 0 | 25 |
| `directional_surface_cell_completion_tests` | `SurfaceComplexSimplificationPhase17` | 12 | 13 | 0 | 0 | 25 |
| `directional_surface_cell_producer_tests` | `AdaptiveFeatureMapPhase11` | 24 | 0 | 0 | 0 | 24 |
| `directional_surface_cell_producer_tests` | `AdaptiveTargetSizePhase12` | 13 | 0 | 0 | 0 | 13 |
| `directional_surface_cell_producer_tests` | `BoundedMeshPreconditionerPhase07` | 6 | 2 | 0 | 0 | 8 |
| `directional_surface_cell_producer_tests` | `CrossFieldTransferPhase07` | 3 | 0 | 0 | 0 | 3 |
| `directional_surface_cell_producer_tests` | `FaceCurvaturePhase1` | 4 | 0 | 0 | 0 | 4 |
| `directional_surface_cell_producer_tests` | `FieldTransportAtlas` | 3 | 0 | 0 | 0 | 3 |
| `directional_surface_cell_producer_tests` | `GlobalTopologyPlan` | 27 | 6 | 0 | 0 | 33 |
| `directional_surface_cell_producer_tests` | `M4CP4` | 2 | 0 | 0 | 0 | 2 |
| `directional_surface_cell_producer_tests` | `M4CPScaleS1` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `M4CPScaleS4Prereq` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `M6CP3` | 12 | 2 | 0 | 0 | 14 |
| `directional_surface_cell_producer_tests` | `MilestoneGP26` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `RegularizedCurvatureFieldPhase1` | 2 | 0 | 0 | 0 | 2 |
| `directional_surface_cell_producer_tests` | `ResolvedBranchCorrection` | 17 | 5 | 0 | 0 | 22 |
| `directional_surface_cell_producer_tests` | `SurfaceCellAuthorityContractCutover` | 17 | 2 | 0 | 0 | 19 |
| `directional_surface_cell_producer_tests` | `SurfaceCellClosedProductContracts` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `SurfaceCellFactoryRejectionSite` | 3 | 0 | 0 | 0 | 3 |
| `directional_surface_cell_producer_tests` | `SurfaceCellFieldAlignedNetworkAuthority` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `SurfaceCellMandatoryProductionFixtures` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `SurfaceCellPhaseFrontFieldChartAuthorityMigration` | 0 | 1 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `SurfaceCellPipelinePhase20` | 0 | 1 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `SurfaceCellTransitionQuotient` | 17 | 2 | 0 | 0 | 19 |
| `directional_surface_cell_producer_tests` | `SurfaceCellVertexContinuationRouteTransportAuthorityMigration` | 5 | 0 | 0 | 0 | 5 |
| `directional_surface_cell_producer_tests` | `SurfaceCellsPhase10` | 34 | 8 | 0 | 0 | 42 |
| `directional_surface_cell_producer_tests` | `SurfaceCutGraph` | 8 | 2 | 0 | 0 | 10 |
| `directional_surface_cell_producer_tests` | `SurfacePhaseFrontProductFactoryAuthority` | 3 | 1 | 0 | 0 | 4 |
| `directional_surface_cell_producer_tests` | `TestFixturePaths` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `TriMeshPhase1` | 1 | 0 | 0 | 0 | 1 |
| `directional_surface_cell_producer_tests` | `UniformPhaseFront/SurfaceCellDesignAcceptance` | 3 | 1 | 2 | 0 | 6 |
| `directional_surface_cell_validation_tests` | `SurfaceMeshOptimizerPhase19` | 19 | 3 | 0 | 0 | 22 |
| `directional_surface_cell_validation_tests` | `SurfaceMeshOptimizerPhase20` | 8 | 1 | 0 | 0 | 9 |
| `directional_surface_cell_validation_tests` | `SurfaceMeshOptimizerPhase21` | 7 | 2 | 0 | 0 | 9 |
| `directional_surface_cell_validation_tests` | `SurfaceMeshOptimizerPhase22` | 0 | 3 | 0 | 0 | 3 |

## Every non-PASS row (observation only; not classified)

| Row | Identity | Test | Verdict | Exit | First failure | Typed reason |
|---:|---|---|---|---:|---|---|
| 8 | offgate:8 | FlowRepStrandsPhase15.AdjacentFaceFanCanonicalizesSubToleranceEndpointsToSourceVertex | RED | 1 | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:802: Failure | reason-not-observed |
| 15 | offgate:15 | FlowRepStrandsPhase15.EndpointCompletionExtendsToRetainedSameSheetNetwork | RED | 1 | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:444: Failure | reason-not-observed |
| 16 | offgate:16 | FlowRepStrandsPhase15.EndpointCompletionIgnoresSubToleranceIntersectionAtTraceOrigin | RED | 1 | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:501: Failure | reason-not-observed |
| 17 | offgate:17 | FlowRepStrandsPhase15.EndpointCompletionOnlyCommitsArrangementReproducibleIntersections | RED | 1 | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:552: Failure | reason-not-observed |
| 22 | offgate:22 | FlowRepStrandsPhase15.IndexAwareSingularitySeparatrixBecomesEmbeddedLayoutSupport | RED | 1 | unknown file: Failure | reason-not-observed |
| 24 | offgate:24 | FlowRepStrandsPhase15.IntraRingRailPrefixUsesCanonicalSingularitySpokeInsteadOfMicroLoop | RED | 1 | unknown file: Failure | reason-not-observed |
| 28 | offgate:28 | FlowRepStrandsPhase15.InvalidSingularitySeparatrixMetadataStillFailsClosed | RED | 1 | unknown file: Failure | reason-not-observed |
| 33 | offgate:33 | FlowRepStrandsPhase15.NetworkConversionUsesOnlyAcceptedClosedBoundaries | RED | 1 | unknown file: Failure | reason-not-observed |
| 34 | offgate:34 | FlowRepStrandsPhase15.NonemptyDegenerateSingularitySeparatrixRemainsCompletionObligation | RED | 1 | unknown file: Failure | reason-not-observed |
| 35 | offgate:35 | FlowRepStrandsPhase15.OpenHardFeatureEndpointsExtendWithoutRemovingAuthoritativeRail | RED | 1 | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:1384: Failure | reason-not-observed |
| 37 | offgate:37 | FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation | RED | 1 | unknown file: Failure | reason-not-observed |
| 38 | offgate:38 | FlowRepStrandsPhase15.ProposalRailSegmentsRemainMandatoryCycleEvidence | RED | 1 | unknown file: Failure | reason-not-observed |
| 39 | offgate:39 | FlowRepStrandsPhase15.RailEndpointTracesBecomeDeduplicatedOptionalLayoutSupport | RED | 1 | unknown file: Failure | reason-not-observed |
| 43 | offgate:43 | FlowRepStrandsPhase15.SelectionInputBuildsNormalizedCoverageAndClosedCycleEvidence | RED | 1 | unknown file: Failure | reason-not-observed |
| 45 | offgate:45 | FlowRepStrandsPhase15.SingularityTransitionRingIsIntrinsicClosedAndDeterministic | RED | 1 | unknown file: Failure | reason-not-observed |
| 46 | offgate:46 | FlowRepStrandsPhase15.SingularityTransitionRingMakesRadialSectorsNonBridgingDisks | RED | 1 | unknown file: Failure | reason-not-observed |
| 48 | offgate:48 | FlowRepStrandsPhase15.SubToleranceIntrinsicCaptureReconcilesOpenEndpointWithoutTinyArc | RED | 1 | ../../Directional/Directional/tests/FlowRepStrandsPhase15Tests.cpp:668: Failure | reason-not-observed |
| 52 | offgate:52 | PatchDescriptorMilestoneE.AuthoritativeCellScopeOverridesMultiScopeBoundaryDuringSubdivision | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1725: Failure | reason-not-observed |
| 54 | offgate:54 | PatchDescriptorMilestoneE.ComplexCompletionFailsClosedInsteadOfReturningPartialOutput | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1331: Failure | reason-not-observed |
| 57 | offgate:57 | PatchDescriptorMilestoneE.DuplicateDomainsFailBeforePatchCompletion | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1376: Failure | reason-not-observed |
| 58 | offgate:58 | PatchDescriptorMilestoneE.GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1291: Failure | reason-not-observed |
| 60 | offgate:60 | PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1597: Failure | reason-not-observed |
| 61 | offgate:61 | PatchDescriptorMilestoneE.PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1189: Failure | reason-not-observed |
| 64 | offgate:64 | PatchDescriptorMilestoneE.SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1541: Failure | reason-not-observed |
| 65 | offgate:65 | PatchDescriptorMilestoneE.StructuralRepairLedgerIsPatchOrderInvariant | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1660: Failure | reason-not-observed |
| 66 | offgate:66 | PatchDescriptorMilestoneE.SuccessfulSideSubdivisionPreservesCanonicalDomainIdentity | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1129: Failure | reason-not-observed |
| 68 | offgate:68 | PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1476: Failure | reason-not-observed |
| 69 | offgate:69 | PatchDescriptorMilestoneE.ZeroStructuralBudgetFailsBeforeCandidateExpansion | RED | 1 | ../../Directional/Directional/tests/PatchDescriptorMilestoneETests.cpp:1567: Failure | reason-not-observed |
| 95 | offgate:95 | SurfaceComplexSimplificationPhase17.BuildsElementsFromPhase16Complex | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:909: Failure | reason-not-observed |
| 96 | offgate:96 | SurfaceComplexSimplificationPhase17.CandidateExtractionIsDeterministicAndCarriesAuthoritativeSupport | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1024: Failure | reason-not-observed |
| 97 | offgate:97 | SurfaceComplexSimplificationPhase17.CandidateExtractionMarksProtectedSupportInsteadOfSilentlyDroppingIt | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1079: Failure | reason-not-observed |
| 100 | offgate:100 | SurfaceComplexSimplificationPhase17.ComplexCandidateRecomputationCreatesRealQueuedCandidates | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1005: Failure | reason-not-observed |
| 101 | offgate:101 | SurfaceComplexSimplificationPhase17.ComplexRollbackPreservesHashOnRejectedTrial | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:974: Failure | reason-not-observed |
| 103 | offgate:103 | SurfaceComplexSimplificationPhase17.MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1246: Failure | reason-not-observed |
| 106 | offgate:106 | SurfaceComplexSimplificationPhase17.OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1319: Failure | reason-not-observed |
| 107 | offgate:107 | SurfaceComplexSimplificationPhase17.OptionalLayoutBridgeHealsPinchedCellTransactionally | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1180: Failure | reason-not-observed |
| 109 | offgate:109 | SurfaceComplexSimplificationPhase17.OversampledArrangementGeneratesRealNonemptyCandidateSet | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1062: Failure | reason-not-observed |
| 112 | offgate:112 | SurfaceComplexSimplificationPhase17.RequiredSingularityBridgeIsProtectedAndRollsBackExactly | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1381: Failure | reason-not-observed |
| 114 | offgate:114 | SurfaceComplexSimplificationPhase17.SimplifySurfaceCellComplexReturnsMutatedComplex | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:943: Failure | reason-not-observed |
| 118 | offgate:118 | SurfaceComplexSimplificationPhase17.TransactionalMutationCommitsExtractedOversampledCandidate | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1112: Failure | reason-not-observed |
| 119 | offgate:119 | SurfaceComplexSimplificationPhase17.TransactionalMutationPreservesHardRailSupport | RED | 1 | ../../Directional/Directional/tests/SurfaceComplexSimplificationPhase17Tests.cpp:1145: Failure | reason-not-observed |
| 157 | offgate:157 | BoundedMeshPreconditionerPhase07.HistoricalArrangementComplexityCaseProducesNoWorseOutputTopology | RED | 1 | unknown file: Failure | reason-not-observed |
| 163 | offgate:163 | BoundedMeshPreconditionerPhase07.PreconditioningOnDoesNotChangeConnectedComponentCount | RED | 1 | unknown file: Failure | reason-not-observed |
| 175 | offgate:175 | GlobalTopologyPlan.CarrierlessTraceIncidenceDiagnosticsSurviveProductionFailureProjection | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:13946: Failure | reason-not-observed |
| 182 | offgate:182 | GlobalTopologyPlan.Cp4c2PrescribedSphereCellularityScopeDecisionIsObservable | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10506: Failure | reason-not-observed |
| 191 | offgate:191 | GlobalTopologyPlan.MechanicalWitnessStageReachabilityIsObservable | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10500: Failure | reason-not-observed |
| 192 | offgate:192 | GlobalTopologyPlan.PrescribedSphereWitnessDerivesRegionsThroughProductionEntryPath | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10890: Failure | reason-not-observed |
| 196 | offgate:196 | GlobalTopologyPlan.SpherePrescribedWitnessStageReachabilityIsObservable | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:16392: Failure | reason-not-observed |
| 197 | offgate:197 | GlobalTopologyPlan.TorusWitnessStageReachabilityIsObservable | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10494: Failure | reason-not-observed |
| 223 | offgate:223 | M6CP3.CheckedFactoryRejectsForgedTerminalA2bSideGerm | RED | 1 | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:10350: Failure | reason-not-observed |
| 225 | offgate:225 | M6CP3.TerminalRailContactPathsUseTypedSourceStarA3 | RED | 1 | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:9932: Failure | reason-not-observed |
| 235 | offgate:235 | ResolvedBranchCorrection.FoldedConeArrivalRayElectsOneOwnerAndFalsifiesCandidateLocalElection | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:11646: Failure | reason-not-observed |
| 236 | offgate:236 | ResolvedBranchCorrection.FoldedConeBoundaryContinuationUsesExactFallbackAndHalfOpenOwner | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:11710: Failure | reason-not-observed |
| 237 | offgate:237 | ResolvedBranchCorrection.FoldedConeRadialArrivalSeedUsesExactHalfOpenArrivalConvention | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:11985: Failure | reason-not-observed |
| 241 | offgate:241 | ResolvedBranchCorrection.HardCarrierStarCutPreservesBoundaryTransit | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:12132: Failure | reason-not-observed |
| 243 | offgate:243 | ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:11619: Failure | reason-not-observed |
| 261 | offgate:261 | SurfaceCellAuthorityContractCutover.MissingTerminalA3PathRejectsAtFirstA4ConsumerPredicate | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:8325: Failure | reason-not-observed |
| 265 | offgate:265 | SurfaceCellAuthorityContractCutover.ProducedHardCarriersAreAtlasBarriersNotSourceBoundaryTransit | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:7651: Failure | reason-not-observed |
| 276 | offgate:276 | SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:5950: Failure | reason-not-observed |
| 277 | offgate:277 | SurfaceCellPipelinePhase20.ProducedNonconstantTwoCarrierOddTauSharesA1VertexGerm | RED | 1 | ../../Directional/Directional/tests/SurfaceCellREPackageTests.cpp:1240: Failure | reason-not-observed |
| 279 | offgate:279 | SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:3666: Failure | reason-not-observed |
| 283 | offgate:283 | SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:5379: Failure | reason-not-observed |
| 286 | offgate:286 | SurfaceCellsPhase10.HardRailRegionCopiesPairReciprocallyBeforeQuotientMaterialization | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:3205: Failure | reason-not-observed |
| 296 | offgate:296 | SurfaceCellsPhase10.MeshValidatorUsesComponentSheetInsteadOfExactFaceEquality | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:888: Failure | reason-not-observed |
| 303 | offgate:303 | SurfaceCellsPhase10.PhaseFrontProducedThenUnsupportedSheetFailsClosedWithoutPartialAuthority | RED | 1 | unknown file: Failure | reason-not-observed |
| 313 | offgate:313 | SurfaceCellsPhase10.StrictValidatorAcceptsLegacySyntheticOutput | RED | 1 | unknown file: Failure | reason-not-observed |
| 314 | offgate:314 | SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:1104: Failure | reason-not-observed |
| 317 | offgate:317 | SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason | RED | 1 | ../../Directional/Directional/tests/SurfaceCellsPhase10Tests.cpp:1793: Failure | reason-not-observed |
| 324 | offgate:324 | SurfaceCellTransitionQuotient.GenuineBoundaryWithInventedInteriorIndexIsRejected | RED | 1 | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:7707: Failure | reason-not-observed |
| 331 | offgate:331 | SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority | RED | 1 | ../../Directional/Directional/tests/SurfaceCellTransitionQuotientTests.cpp:9675: Failure | reason-not-observed |
| 344 | offgate:344 | SurfaceCutGraph.CellularityCertificatePublishesTotalSourceFaceOwnershipOnProductionFixtures | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:17295: Failure | reason-not-observed |
| 350 | offgate:350 | SurfaceCutGraph.OrdinaryProposalSelectsTraceCrossedEdgeWithoutSaturation | RED | 1 | ../../Directional/Directional/tests/FieldAlignedCurveNetworkTests.cpp:10924: Failure | reason-not-observed |
| 354 | offgate:354 | SurfacePhaseFrontProductFactoryAuthority.HardRailTransitionNeedsExactlyTwoSourceFaceIncidences | RED | 1 | unknown file: Failure | reason-not-observed |
| 360 | offgate:360 | UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom | RED | 1 | ../../Directional/Directional/tests/SurfaceCellDesignAcceptanceTests.cpp:197: Failure | reason-not-observed |
| 362 | offgate:362 | UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Cylinder | ABNORMAL | 124 | failure-line-not-observed | reason-not-observed |
| 365 | offgate:365 | UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase | ABNORMAL | 124 | failure-line-not-observed | reason-not-observed |
| 373 | offgate:373 | SurfaceMeshOptimizerPhase19.FinalValidationPassesSectionFiveFixture | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase19Tests.cpp:267: Failure | reason-not-observed |
| 375 | offgate:375 | SurfaceMeshOptimizerPhase19.FixedFeatureVertexRefreshesSourceTriangleProvenance | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase19Tests.cpp:665: Failure | reason-not-observed |
| 385 | offgate:385 | SurfaceMeshOptimizerPhase19.ProjectsToSourceTrianglesWithProvenance | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase19Tests.cpp:388: Failure | reason-not-observed |
| 390 | offgate:390 | SurfaceMeshOptimizerPhase20.DirectDerivativesMatchFiniteDifferencesForEveryEnabledEnergy | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase20Tests.cpp:137: Failure | reason-not-observed |
| 399 | offgate:399 | SurfaceMeshOptimizerPhase21.MixedOutputSheetAuthorityFailsClosed | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase21Tests.cpp:440: Failure | reason-not-observed |
| 401 | offgate:401 | SurfaceMeshOptimizerPhase21.PipelineStyleBoundarySingularitiesAcceptCompletedCloseSheetQuads | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase21Tests.cpp:348: Failure | reason-not-observed |
| 406 | offgate:406 | SurfaceMeshOptimizerPhase22.MultiRailChainReachesSelectedChartWithoutConsumingUnusedRelation | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase22Tests.cpp:1056: Failure | reason-not-observed |
| 407 | offgate:407 | SurfaceMeshOptimizerPhase22.MultiRailChartReachabilityIsInvariantToSourceFaceRows | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase22Tests.cpp:1379: Failure | reason-not-observed |
| 408 | offgate:408 | SurfaceMeshOptimizerPhase22.MultiRailReciprocityMayBeCarriedOutsideTheSelectedFace | RED | 1 | ../../Directional/Directional/tests/SurfaceMeshOptimizerPhase22Tests.cpp:1078: Failure | reason-not-observed |

**Counts: PASS 323; RED 83; ABNORMAL 2; INVALID 0.**
