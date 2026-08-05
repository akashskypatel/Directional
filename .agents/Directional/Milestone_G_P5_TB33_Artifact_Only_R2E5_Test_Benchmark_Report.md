# Milestone G P5-TB33 Artifact-Only R2E5 Test/Benchmark Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E5 successfully repairs the degree-two boundary rotational degeneracy and restores every regression introduced by R2E4. It also closes six pre-existing Phase 17 failures. R2 remains open because the higher-valence boundary fan path still produces a non-disk bounded orbit, the interior hard-rail fixture still fails typed rotational construction, the planar fixture remains Euler-invalid, and cylinder production remains incomplete.

The next turn is **P5-R2E6 authoritative boundary fan-sector cover Code + Build**. Do not advance to R2F or R3.

This was an artifact-only Test + Benchmark turn. No configure, build, relink, patch, regeneration, fixture modification, implementation modification, or build-logic modification occurred.

## Package authority

Validation used artifact `8934315316`, `surface-cell-p5-r2e5-github-source-linux-release`.

- archive SHA-256: `69436143d96749cc09c6da8dc8c301e63304c2d25f9252497d0e9d0259c46c5c`;
- exact compiled source: `1eb9dc766bc6db74bd2c1ea4ced9c3cbeaae133b`;
- workflow event commit: `15704d30fc478858284df89d372fa713f2d88576`;
- reviewed/applied diff SHA-256: `b7648b0bf870d7a65a7715a11e58cc2e8258af0118826c843d013384d485cc29`;
- source status empty;
- recursive manifest **48/48**;
- package files **49** including the manifest;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e5.yml`.

The authority gate passed before any packaged executable ran.

## Focused results

| Scope | Result | Disposition |
|---|---:|---|
| Source-chart R1 | **11/11** | preserved |
| Source validator | **6/6** | preserved |
| Recovery authority | **9/9** | preserved |
| Feature/barrier | **8/8** | all R2E4 regressions restored |
| Graph-dependent | **5/6** | only bunny fails |
| R2 focused | **12/16** | planar, hard rail, cylinder, and higher-valence fan fail |
| Milestone D | **5/7** | restored to P5-TB31 baseline |
| Phase 14–18 | **240/244** | four failures |
| Phase 16 | **44/47** | higher-valence fan, planar, bunny |
| Phase 17 | **26/26** | all eight P5-TB32 failures and six P5-TB31 failures closed |
| Phase 18 | **57/57** | preserved |
| Phase 20 | **46/48** | existing cylinder and terminal-stage failures |

### Degree-two closure

`SurfaceArrangementPhase16.DegreeTwoBoundaryNodesPublishExteriorAndInteriorSectors` passes.

The validated producer now demonstrates:

- exact two-ray outgoing inventory;
- authoritative `exteriorIncoming -> exteriorOutgoing` continuation;
- complementary `twin(exteriorOutgoing) -> exteriorTwin` interior sector;
- two distinct incoming owners;
- exact one-use target cardinality;
- endpoint continuity;
- one exterior disk and one bounded disk;
- topology-valid Euler-one boundary-only triangle;
- derived `boundaryDegreeTwoRotationalNodeCount`.

All 21 P5-TB32 regressions are restored. Relative to P5-TB32, the complete suite closes 26 failures and introduces none.

### Additional closure

Relative to P5-TB31, P5-TB33 closes these six pre-existing Phase 17 failures:

- `SurfaceComplexSimplificationPhase17.SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `SurfaceComplexSimplificationPhase17.ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `SurfaceComplexSimplificationPhase17.TransactionalMutationCommitsExtractedOversampledCandidate`;
- `SurfaceComplexSimplificationPhase17.TransactionalMutationPreservesHardRailSupport`;
- `SurfaceComplexSimplificationPhase17.MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `SurfaceComplexSimplificationPhase17.OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

These tests close naturally because their arrangement inputs are valid again. No Phase 17 implementation changed in R2E5.

## Remaining producer failures

### 1. Higher-valence boundary fan

`SurfaceArrangementPhase16.MultipleInteriorRaysAtBoundaryVertexUseAdjacentRotationalSectors` passes incidence, local predecessor cardinality, and repeated-node/repeated-edge audits, but fails:

- `cellsDiskValid`;
- `topologyValid`.

This is the new failure relative to P5-TB31. The current `rayCount >= 3` branch selects one common canonical wedge and applies one cyclic adjacency permutation across the complete local inventory. A complete local bijection is not sufficient to prove that every successor pair corresponds to one authoritative source-interior fan sector. The resulting orbit can therefore be incidence-valid while still representing a non-disk bounded cell.

### 2. Interior hard rail

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` still fails before orbit publication as `BoundaryRotationalSystemConflict`.

The current producer requires one common SourceVertex/SourceEdge wedge identity to contain every outgoing ray at a boundary node. At an authoritative hard-rail endpoint, R1 fan scopes intentionally partition the local source interior. No single wedge necessarily spans both sides of the hard rail, so “one common wedge” is an invalid completeness criterion. The local rotation must instead be assembled from a complete, non-overlapping cover of authoritative fan sectors.

### 3. Planar fixture

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` now passes incidence, node-local successor bijection, degree-two sector checks, and repeated-node/repeated-edge audits. It still fails topology with arrangement Euler characteristic **0** instead of source Euler characteristic **1**.

This must not be corrected synthetically. After boundary fan-sector construction is authoritative, the next artifact-only turn must identify whether the remaining deficit comes from an interior trace-end orbit, a non-disk bounded owner, or missing bounded-cell contribution.

### 4. Cylinder

`MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` remains uncommitted. `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput` remains `NotProductionReady/completion`. Direct cylinder execution publishes zero arrangement, simplified, and completed inventories.

Cylinder remains blocked until upstream arrangement fan/orbit ownership is valid.

### 5. Bunny

`SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation` remains the separate intrinsic singularity-fan embedding producer. It is not part of P5-R2E6.

## Direct analytic cases

All direct cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Arrangement | Simplified | Quads | Result | Earliest reported failure |
|---|---:|---:|---:|---|---|
| plane | 9 | 9 | 12 | fail | completion/output-validation: `AggregateCompletionValidationFailure` |
| multi-face seam | 0 | 0 | 0 | fail | completion: `SideSubdivisionRepair:InvalidInputIncidence` |
| close sheets | 0 | 0 | 0 | fail | completion: `SideSubdivisionRepair:InvalidInputIncidence` |
| cylinder | 0 | 0 | 0 | fail | completion: `SideSubdivisionRepair:InvalidInputIncidence` |

Peak process working-set evidence:

- plane: **8,601,600 bytes**, wall **0.020902 s**;
- multi-face seam: **8,462,336 bytes**, wall **0.024840 s**;
- close sheets: **8,626,176 bytes**, wall **0.049220 s**;
- cylinder: **9,994,240 bytes**, wall **0.292947 s**.

Plane preserves its P5-TB32 inventory. Seam, close sheets, and cylinder do not regress relative to P5-TB31, but zero arrangement inventory remains unacceptable for R2 closure. No fallback, source-grid recovery, returned-input substitution, or legacy execution was used.

## Complete suite

The complete suite executed exactly once after focused scopes.

- tests: **625**;
- passed: **602**;
- failures: **23**;
- errors: **0**;
- disabled: **0**;
- XML runtime: **84.132 s**;
- measured wall clock: **1:24.14**;
- exact maximum RSS: **280,640 KiB**;
- normal termination: yes.

Relative to P5-TB32:

- 26 failures closed;
- zero new failures;
- passed count increased by 27 because the suite also contains one additional test.

Relative to P5-TB31:

- six failures closed;
- one newly added higher-valence contract fails;
- net failures decrease from 28 to 23;
- passed count increases from 595/623 to 602/625.

Dominant cases:

- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`: **30.091 s**, fail;
- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`: **24.688 s**, pass;
- `ProductionManifestCases/.../7`: **24.493 s**, pass.

The shorter total runtime is not accepted as production performance progress while arrangement and completion gates remain invalid.

## Decision

P5-R2E5 is accepted as a correct degree-two remediation because:

- the new degree-two topology contract passes;
- all 21 R2E4 regressions are restored;
- no new complete-suite failure appears relative to P5-TB32;
- canonical orientation identity remains passing;
- validators were not weakened;
- Phase 17 closes naturally without Phase 17 changes.

R2 remains open because the higher-valence fan contract, hard-rail rotational construction, planar topology/Euler, cylinder ownership/completion, and bunny embedding are not closed.

Proceed with **P5-R2E6 authoritative boundary fan-sector cover Code + Build**.

## Evidence

- machine summary: `benchmark-results/p5-tb33-summary.json`;
- raw evidence bundle: `directional-p5-tb33-8934315316-evidence.zip`;
- evidence SHA-256: `1a4f1a780e29f09e0d93f75f0c01a818358029d6044839f32ffdff53aa340ec7`;
- evidence files: **188**.

Preserved prohibitions: no validator weakening, count/order/frequency ownership selection, fallback/recovery substitution, synthetic counters or Euler correction, positional merging across unrelated sheets, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition or cell merging, or timeout-as-correctness.
