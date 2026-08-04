# Milestone G P5-TB17 Parity, Reuse, Output, and Memory Test/Benchmark Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** artifact-only test and benchmark

## Disposition

P5-TB17 is complete as an artifact-only runtime turn. P5 remains open.

The exact GitHub Actions package from run `30864341083` was extracted to an arbitrary directory and executed without configuring, compiling, relinking, patching, or regenerating code. The package is valid, but the runtime closure gates do not pass:

- complete suite: **572/594 passed**, **22 assertion failures**, no abnormal termination;
- the ten P5-TB16 failures remain;
- twelve Phase 16/17 and Milestone D regressions were introduced by the P5-CB91–P5-CB98 source-scope changes;
- both random-bunny field paths remain deterministic but fail closed at `BoundaryParityRepair:MixedCellSourceScope` and emit no output;
- both guaranteed exact-reuse scenarios still report zero reuse;
- the invalid-midpoint fixture still stops earlier at `MissingCommonSourceChart`;
- cylinder topology and production output remain invalid;
- memory ownership telemetry is deterministic and internally populated, but explains only 28.0–33.6% of peak RSS.

No source, test, benchmark, build-system, or workflow logic was modified during execution.

## TB17-A — package integrity

Artifact:

- ID: `8875627676`
- name: `surface-cell-p5-cb98-github-source-linux-release`
- exact archive SHA-256: `b9560c9438289e90e6acca3a0f4b7f1d46a5ad34663693c1243bf4176056c165`
- source commit: `680d81c6946f45b1daed9dd477cfde565f8ac7a2`
- source status: empty
- recursive checksums: **38/38 passed**
- packaged fixture files: **26**
- random bunny: **502 vertices / 1,000 triangle faces**
- both executables and both static libraries present
- executable-relative fixture closure passed

Pinned dependencies:

- Eigen `769c72fd8019e389810d1de1e7c243521a43b594`
- googletest `3940de91897160fea4815998e08d0fa3c2fb077e`
- polyscope `59da72df6517cab8379865899bdffdbc96171301`

## TB17-B — focused regression gates

The focused run contained the ten P5-TB16 failures plus four new direct scope, midpoint, rail, and memory checks.

| Result | Count |
|---|---:|
| Passed | 4 |
| Failed | 10 |
| Total | 14 |
| Duration | 25.320 s |

New checks that pass:

- `PatchDescriptorMilestoneE.AuthoritativeCellScopeOverridesMultiScopeBoundaryDuringSubdivision`
- `PatchDescriptorMilestoneE.SubdivisionWithoutCommonSourceChartFailsBeforeMutation`
- `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails`
- `SurfaceCellPipelinePhase20.ProductionDefaultReleasesConsumedIntermediateGeometry`

The ten pre-existing failures remain:

1. `MilestoneGP26.PlaneAndMechanicalFixturesCompleteEndToEnd`
2. `MilestoneGP26.CylinderCompletesEndToEnd`
3. `MilestoneGP26.MultiFaceSeamCompletesEndToEnd`
4. `MilestoneGP26.TorusCompletesEndToEnd`
5. `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`
6. `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved`
7. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`
8. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse`
9. `PatchDescriptorMilestoneE.FailedSubdivisionReturnsBitExactCommittedComplex`
10. `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput`

Key failure evidence:

- route repair still exhausts with `same-corner-distinct-boundary` after route validation;
- one-candidate exact-reuse fixture records incremental recomputation `0`, reused completions `0`, and recomputed completions `0`;
- invalid-midpoint fixture returns `MissingCommonSourceChart`, not `InvalidMidpointEmbedding`;
- cylinder simplification fails initial complex incidence validation;
- production plane, cylinder, and seam reach output validation with invalid orientation/non-convex topology; mechanical and torus stop earlier in completion.

## TB17-C — milestone scopes

| Scope | Passed | Failed | Total | Duration | First failure |
|---|---:|---:|---:|---:|---|
| Phase 14–18 | 220 | 10 | 230 | 0.016 s | `SurfaceArrangementPhase16.AuthoritativeTopologyDiagnosticsMatchSingleDiskSource` |
| `PatchDescriptorMilestoneE.*` | 23 | 3 | 26 | 0.004 s | `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` |
| Milestone D | 4 | 3 | 7 | 0.000 s | `CurvedStitchedCellUsesGlobalEmbeddingAndSourceFaces` |
| Milestone G P23 | 6 | 0 | 6 | 0.026 s | — |
| Milestone G P26 | 15 | 4 | 19 | 26.357 s | `PlaneAndMechanicalFixturesCompleteEndToEnd` |
| Milestone G P27 + parameter cases | 16 | 1 | 17 | 51.036 s | `ProductionSurfaceCellMatrixMatchesSupportedDisposition` |
| Phase 20 | 47 | 1 | 48 | 0.268 s | `CylinderFixtureCompletesProductionOutput` |
| Complete suite | **572** | **22** | **594** | **80.995 s** | `MilestoneGP26.PlaneAndMechanicalFixturesCompleteEndToEnd` |

### Newly regressed contracts

P5-TB16 reported Phase 14–18 at 230/230 and Milestone D at 6/7. P5-TB17 adds twelve failures:

**Phase 16 — four failures**

- `AuthoritativeTopologyDiagnosticsMatchSingleDiskSource`
- `AuthoritativeTopologyDiagnosticsHandleDisconnectedSourceComponents`
- `CurvedMultiFaceFixturePreservesStitchedTopologyAndEulerCharacteristic`
- `BunnySingularityFanUsesIntrinsicSourceVertexRotation`

**Phase 17 — six failures**

- `SimplifySurfaceCellComplexReturnsMutatedComplex`
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`
- `TransactionalMutationCommitsExtractedOversampledCandidate`
- `TransactionalMutationPreservesHardRailSupport`
- `OptionalLayoutBridgeHealsPinchedCellTransactionally`
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`

**Milestone D — two additional failures**

- `CurvedStitchedCellUsesGlobalEmbeddingAndSourceFaces`
- `InteriorHardRailIsNotClassifiedAsExteriorBoundary`

A supplementary artifact-only run of these twelve tests using the independently compiled Clang P5-CB98 package also failed 0/12 with the same assertions. The regression is therefore source-level, not GCC-specific.

The relevant source delta replaced the previous oriented-cell scope selection with a strict intersection of every boundary provenance scope, and it marks the arrangement invalid when that intersection is not exactly one pair. This conflicts with the existing tracing contract that field traces may cross adjacent local sheet-chart boundaries while remaining in one connected source component. Downstream simplification then receives invalid topology and cannot commit otherwise valid candidates.

### Former signal-11 cases

| Test | Result | Duration |
|---|---|---:|
| `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` | passed | 25.459 s |
| `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` | normal assertion failure | 26.080 s |
| `ProductionManifestCases/MilestoneGP27SurfaceCellCase.RunsIndependentlyAndOwnsReturnedDiagnostics/7` | passed | 24.297 s |

All three terminate normally. No signal-11 or other abnormal process termination occurred.

## TB17-D — random-bunny benchmarks

Eight independent processes used zero warmups, one measured run, `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled. Every benchmark process exited normally with code 0 while recording a failed pipeline run in JSON.

### Face-edge field

Manifest/case: `repo_regressions.json` / `bunny_1k_random_medium`

| Run | Wall | Peak RSS |
|---:|---:|---:|
| 1 | 18.627678 s | 130,584,576 B |
| 2 | 17.401721 s | 130,613,248 B |
| 3 | 17.689128 s | 130,482,176 B |
| 4 | 17.159562 s | 130,637,824 B |

- normalized structural digest: `aa0ae261c0bda69864d74db10d829fc5367582b06060958bc35165aded8969e8`
- all four structural digests identical
- common failure: `NotProductionReady/completion:BoundaryParityRepair:MixedCellSourceScope`
- trace segments: `12,130`
- arrangement/simplified cells: `7,405 / 7,405`
- odd cells: `1,860 -> 0` only inside the rejected parity transaction
- output vertices/quads: `0 / 0`
- output origin: `None`
- fallback/recovery: none
- exact reused/recomputed completions: `0 / 0`
- mismatch vector: empty because completion stops before cache reuse

Typed first-invalid parity evidence is deterministic:

- original/replacement cell: `19 / 19`
- halfedge/twin: `21767 / 21766`
- selected component/sheet: `-1 / -1`
- available components: `[0, 0]`
- available local sheets: `[0, 1]`
- mutation phase: `preflight`

Endpoint completion:

- open `2,002`
- resolved `1,396`
- unresolved `606`
- unresolved required `606`
- added arcs `697`

Simplification:

- candidates `7,518`
- generated `3,725`
- invalidated `2,978`
- evaluated `762`
- committed/rejected `4 / 758`
- peak live `747`

Memory:

- estimated simultaneous owned peak: `36,629,988 B`
- maximum process RSS: `130,637,824 B`
- owned/RSS ratio: `28.04–28.07%`
- maximum unexplained bytes: `94,007,836 B`
- ownership timeline events: `12`

### Smooth field

Manifest/case: `milestone_g_manifest.json` / `bunny_1k_random__surface_cells`

| Run | Wall | Benchmark peak working set | `/usr/bin/time` max RSS |
|---:|---:|---:|---:|
| 1 | 24.328261 s | 281,448,448 B | 283,938,816 B |
| 2 | 23.926394 s | 283,869,184 B | 284,000,256 B |
| 3 | 26.078714 s | 282,722,304 B | 284,164,096 B |
| 4 | 24.131837 s | 282,066,944 B | 284,045,312 B |

- normalized structural digest: `27b0a7e69a9e47bd1f0189a9d6e5a2e8bacaf7676248fd05cb3e069673161e50`
- all four structural digests identical
- common failure: `NotProductionReady/completion:BoundaryParityRepair:MixedCellSourceScope`
- trace segments: `80,862`
- arrangement/simplified cells: `21,298 / 21,298`
- odd cells: `959 -> 0` only inside the rejected parity transaction
- output vertices/quads: `0 / 0`
- output origin: `None`
- fallback/recovery: none
- exact reused/recomputed completions: `0 / 0`
- mismatch vector: empty

Typed first-invalid parity evidence is deterministic:

- original/replacement cell: `45 / 45`
- halfedge/twin: `46451 / 46450`
- selected component/sheet: `-1 / -1`
- available components: `[0, 0]`
- available local sheets: `[0, 1]`
- mutation phase: `preflight`

Endpoint completion:

- open `3,959`
- resolved `3,956`
- unresolved `3`
- unresolved required `0`
- added arcs `2,050`

Simplification:

- candidates `2,673`
- generated `4`
- invalidated `3`
- evaluated `1`
- committed/rejected `1 / 0`
- peak live `4`

Memory:

- estimated simultaneous owned peak: `94,660,556 B`
- maximum observed RSS: `284,164,096 B`
- owned/RSS ratio: `33.35–33.63%`
- maximum unexplained bytes: `189,208,628 B`
- ownership timeline events: `12`

### Resource gates

Using the established limits:

- wall limit: `39.228299 s`
- memory limit: `1,115,394,560 B`

All eight benchmark processes pass both resource limits. The memory telemetry gate still fails because the reported simultaneous ownership does not explain the dominant RSS allocation.

## Gate disposition

| Gate | Result |
|---|---|
| Package integrity and fixture closure | pass |
| All ten prior assertion failures pass | fail |
| New direct parity-scope regression | pass |
| Positive exact reuse on both guaranteed cases | fail |
| Invalid midpoint after valid common-chart setup | fail |
| Cylinder incidence/topology and output | fail |
| Phase 14–18 remains closed | fail — 10 regressions |
| Former signal-11 cases terminate normally | pass |
| Complete suite has no unexpected failure | fail — 22 failures |
| Four face-edge runs deterministic | pass |
| Four smooth-field runs deterministic | pass |
| Both paths emit valid nonempty pure-quad output | fail |
| No fallback or source-grid recovery | pass |
| Wall and memory limits | pass |
| Memory telemetry populated and deterministic | pass |
| Memory telemetry explains dominant peak RSS | fail |

## Required next turn

The next authoritative turn is **P5-CB99 through P5-CB107 code changes + compile-only build**. Follow:

`.agents/Directional/Milestone_G_P5_Post_TB17_Source_Scope_Topology_Reuse_Output_Memory_Code_Build_Plan.md`

Do not execute tests or benchmarks during that code/build turn.
