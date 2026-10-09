# R3: R2 direct-A4 25-case first-observable-locus triage (static; not runtime R3 evidence)

**Source authority:** frozen R2 run `37767144537`, artifact `11545716507`, SHA256 manifest **1019/1019 PASS**. Each row is a historical R2 result and not a current R3 reproduction.

**Current source:** semantic `32994a92dcc6492230ee768c476e65d31a38f59e`, GMP/GMPXX compile run `37878691159`, artifact `11593975930`, **28/28 PASS**, `runtimeExecution=false`. Only source-static classification is allowed in this Code+Build turn.

## Evidence grouping (do not equate shared fixtures to a proven common cause)

- **17 thrown from shared 3×3 constant-field `make_hard_rail_fixture`** (`tests/SurfaceCellTransitionQuotientTests.cpp:525–585`): they throw at `require_produced` before the per-test mutation assertions. The historical thrown text is `internal-midline hard-rail rectangle producer failed: InvalidHardRailRouteCertificate`. This is a shared *visible stop*, not a proven common A4 defect.
- **2 thrown from nonconstant 3×3 field producer** (`tests/SurfaceCellTransitionQuotientTests.cpp:680–790`): both historical CP3 rows throw `non-constant internal-midline hard-rail rectangle producer failed: InvalidHardRailRouteCertificate`, again before per-test witness assertions.
- **6 Phase10 entry assertions** (`tests/SurfaceCellsPhase10Tests.cpp`): five report an expected `Produced` versus actual `InvalidHardRailRouteCertificate` (or equivalent disposition/code mismatch); one has several errors plus `NotProductionReady:tracing:InvalidHardRailRouteCertificate`. These are separate calling sites; do not silently unify their cause with the first group.

## Historical cases

| Group/ordinal | Exact GoogleTest identity | First observable R2 diagnostic |
|---|---|---|
| `focused30:3` | `M6CP1.SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused30:12` | `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused30:14` | `M6CP1.A7ExactSourceSupportAcceptsVertexEdgeAndFaceInteriorClasses` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused30:15` | `M6CP1.A7RejectsSupportKindIdentityAndSameSimplexPointMismatches` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused30:17` | `M6CP1.A7ProjectsCompleteClassLineageAndSelectedRelationValues` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused30:18` | `M6CP1.A7NeverConsumesPlacementTransportForGeometryOrLineage` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused30:22` | `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused30:23` | `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused30:24` | `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused12:5` | `M6CP2.VerifierRejectsEveryForbiddenRepairClassWithoutMutation` | constant fixture threw InvalidHardRailRouteCertificate |
| `focused12:6` | `M6CP2.CertificateChainRequiresExactA5A6A7PayloadBinding` | constant fixture threw InvalidHardRailRouteCertificate |
| `selector:115` | `SurfaceCellAuthorityContractCutover.AuthoritativePhaseFrontClosureProjectsAndValidatesBeforeOptimizer` | Phase10 assertion(s); tracing InvalidHardRailRouteCertificate |
| `selector:117` | `SurfaceCellAuthorityContractCutover.AuthoritativePhaseFrontPublishesCanonicalSourceChartsBeforeMaterialization` | Phase10 assertion(s); tracing InvalidHardRailRouteCertificate |
| `selector:141` | `SurfaceCellAuthorityContractCutover.HardRailPairPublishesReverseRouteTransportBeforeMaterialization` | Phase10 assertion(s); tracing InvalidHardRailRouteCertificate |
| `selector:150` | `SurfaceCellAuthorityContractCutover.RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent` | Phase10 assertion(s); tracing InvalidHardRailRouteCertificate |
| `selector:211` | `SurfaceCellTransitionQuotient.AmbiguousHardRailCounterpartIsRejected` | constant fixture threw InvalidHardRailRouteCertificate |
| `selector:217` | `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions` | constant fixture threw InvalidHardRailRouteCertificate |
| `selector:219` | `SurfaceCellTransitionQuotient.MissingHardRailCounterpartIsRejected` | constant fixture threw InvalidHardRailRouteCertificate |
| `selector:227` | `SurfaceCellTypedTransportAuthority.DuplicateSemanticRouteTopologyFailsClosed` | constant fixture threw InvalidHardRailRouteCertificate |
| `selector:230` | `SurfaceCellTypedTransportAuthority.RouteTopologyTransitionMismatchFailsClosed` | constant fixture threw InvalidHardRailRouteCertificate |
| `selector:231` | `SurfaceCellTypedTransportAuthority.ValidHardRailRouteUsesTypedIdentity` | constant fixture threw InvalidHardRailRouteCertificate |
| `selector:404` | `SurfaceCellAuthorityContractCutover.ProductionA4PublishesAcceptedA2bA3ConformityReceipt` | Phase10 assertion(s); tracing InvalidHardRailRouteCertificate |
| `selector:405` | `SurfaceCellAuthorityContractCutover.FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals` | Phase10 assertion(s); tracing InvalidHardRailRouteCertificate |
| `cp3entry:2` | `M6CP3.HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge` | nonconstant fixture threw InvalidHardRailRouteCertificate |
| `cp3entry:6` | `M6CP3.HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels` | nonconstant fixture threw InvalidHardRailRouteCertificate |

## Explicit follow-up for the future authorized TB/independent Review

1. Run the **existing frozen 497 exact-filter processes only** at the future TB boundary; preserve all original identities and evidence. This static regrouping is not permission to partition the suite or add hidden tests.
2. For every R3 `InvalidHardRailRouteCertificate`, record immutable `firstPredicate`, `locus`, route length, endpoint face rows, `firstFailSpoke`, source-face incidence, and carrier owner values. At the `A3-commuting-square` locus record source-attested `phi_A`, `phi_B`, `chi_previous`, `chi_next`, and both compositions if the diagnostic-only augmentation is compiled.
3. Compare R3 first failures with these R2 first-observable log messages **by individual test ID**. A fixture throw can make many tests RED without establishing that their intended downstream assertions were reached. Do not credit the 47 CP2 accepted-green restorations or any D2 nonvacuity from source code inspection.
4. Do not synthesize fake multi-carrier certificates or relax RA-39 endpoint-local crossing, frozen selectors, A3 provenance, `A5/A6/A7` typed semantics, or failure precedence. If bounded organic A4 producer search remains empty, STOP for independent producer review.

**Checksum accounting:** 1019/1019 R2 manifest entries PASS; 25 direct A4 historical classified rows; shared source stop grouping 17 + 2 + 6 = 25. No R3 test has been run in this response.
