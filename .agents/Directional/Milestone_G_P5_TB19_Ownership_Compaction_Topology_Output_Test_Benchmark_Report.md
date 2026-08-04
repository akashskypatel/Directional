# Milestone G P5-TB19 Ownership Compaction, Topology, and Output Test/Benchmark Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** artifact-only test and benchmark

## Disposition

P5-TB19 is complete as an artifact-only runtime turn. P5 remains open.

Artifact `8878170954` was extracted and executed directly. No configure, build,
relink, patch, regeneration, or source modification occurred. The CB108–CB116
checkpoint removes the catastrophic ownership-memory amplification and closes
all Phase 14–18 regressions, but production-ready direct `SurfaceCells` output
is not yet complete.

Key outcomes:

- package authority passed: exact source, empty source status, 40/40 checksums,
  26 fixtures, and 9 recursive submodule records;
- Phase 14–18 is **235/235**, including Phase 16 **39/39** and Phase 17
  **26/26**;
- the complete 599-test binary terminates at **583/599** in **100.312 s**, with
  maximum RSS **530,259,968 B**;
- all three formerly blocked heavy cases terminate;
- malformed midpoint now reaches its intended failure and exact rollback
  contract;
- typed prepared-domain evidence exposes exact repeated-boundary-node producers;
- both random-bunny paths finish within the established wall/RSS limits and
  produce deterministic failed-result signatures across four independent
  processes;
- every direct production fixture still fails and no valid returned production
  quad mesh exists;
- exact positive reuse remains `0/0`;
- cylinder incidence remains invalid;
- categorized same-sample memory coverage remains below 75%.

No fallback or source-grid recovery was used.

## Artifact integrity

- artifact ID: `8878170954`;
- name: `surface-cell-p5-cb116-github-source-linux-release`;
- archive SHA-256:
  `c82a27122aaa3f3cc96f6cb3621248ed8eed4bdaf92df503b0f8deb06ec8f5d6`;
- exact compiled source:
  `9bff7d352f2751228d10ce72e2860c899f90de80`;
- packaged source status bytes: `0`;
- recursive checksums: **40/40**;
- fixture files: **26**;
- recursive submodule records: **9**;
- rebuilt: **false**.

## Test results

| Scope | Passed | Failed | Total | Time |
|---|---:|---:|---:|---:|
| Focused ownership/topology/reuse/midpoint/output contracts | 22 | 4 | 26 | 0.129 s |
| Phase 14–18 | **235** | **0** | **235** | 0.017 s |
| Milestone D | 5 | 2 | 7 | 0.000 s |
| Milestone E | 23 | 3 | 26 | 0.004 s |
| Phase 20 | 46 | 2 | 48 | 0.239 s |
| Complete binary | **583** | **16** | **599** | **100.312 s** |

The complete binary now terminates. Its maximum RSS was **530,259,968 B**.
This closes the prior full-suite termination blocker, but not the clean-suite
gate.

### Closed topology scopes

Phase 14–18 is clean:

- `SurfaceCellTracingPhase14`: **59/59**;
- `FlowRepStrandsPhase15`: **55/55**;
- `SurfaceArrangementPhase16`: **39/39**;
- `SurfaceComplexSimplificationPhase17`: **26/26**;
- `PureQuadCompletionPhase18`: **56/56**.

The compact ownership registry, unlabeled intrinsic ownership derivation,
face-row invariance, and simplification propagation regressions all pass.

### Remaining full-suite failures

The 16 failing tests are:

1. `MilestoneGP23.FailReturnsNoMesh`
2. `MilestoneGP23.ReturnInputMeshIsCanonicalFallback`
3. `MilestoneGP23.SurfaceCellFailureTerminatesBeforeLegacyIntegration`
4. `MilestoneGP24.RealFailurePreservesLastValidStageArtifacts`
5. `MilestoneGP26.PlaneAndMechanicalFixturesCompleteEndToEnd`
6. `MilestoneGP26.CylinderCompletesEndToEnd`
7. `MilestoneGP26.MultiFaceSeamCompletesEndToEnd`
8. `MilestoneGP26.TorusCompletesEndToEnd`
9. `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`
10. `MilestoneDClosure.PartialMultiEdgeInterfaceFailsClosed`
11. `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved`
12. `PatchDescriptorMilestoneE.SharedEdgeParityRepairConforminglyCompletesTwoOddCells`
13. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`
14. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse`
15. `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput`
16. `SurfaceCellPipelinePhase20.ValidationRejectionCannotReportCompletedSurfaceCells`

### Heavy-case termination

| Test | Result | Time | Maximum RSS |
|---|---|---:|---:|
| `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` | pass | 32.872 s | 455,921,664 B |
| `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` | fail assertions | 32.411 s | 454,688,768 B |
| bunny smooth production parameter `/7` | pass contract | 30.904 s | 454,426,624 B |

A timeout or termination is not used as correctness. All three processes exited
normally in this turn.

## Midpoint, route, and reuse

`PatchDescriptorMilestoneE.FailedSubdivisionReturnsBitExactCommittedComplex`
now passes. The corrected fixture preserves common-chart preconditions, reaches
`InvalidMidpointEmbedding` after temporary mutation, and verifies bit-exact
rollback. The midpoint gate is closed.

The route/reuse gate remains open:

- `WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` still fails at
  `same-corner-distinct-boundary` route validation;
- `OneCandidateBudgetIsExactAndDoesNotRecurse` records incremental recomputation
  `0`, reused completions `0`, and recomputed completions `0`;
- direct production and bunny runs also report reuse/recompute `0/0`.

Counters were not altered or synthesized.

## Cylinder and transactional rollback

`MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` still
fails `validate_complex_incidence(complex)` before candidate extraction. The
current boolean incidence validator does not identify the first invalid
halfedge/cell, so the producer cannot yet be repaired from exact typed evidence.

`MilestoneDClosure.PartialMultiEdgeInterfaceFailsClosed` rejects the invalid
operation, but compares rollback against a pre-canonical manual/legacy complex.
The production transaction canonicalizes ownership before mutation, so the test
hashes the wrong baseline. The next test correction must canonicalize the
fixture before recording its rollback baseline; it must not weaken rollback
identity or accept a changed canonical committed state.

## Prepared-domain evidence

Typed domain auditing is working. Mechanical feature, prescribed sphere, and
face-edge bunny now identify the exact successful-subdivision defect:

- mechanical feature: `repeated-boundary-node`, cell 24, halfedge 304, node 67,
  source face 8;
- prescribed sphere: `repeated-boundary-node`, cell 2, halfedge 59, node 13,
  source face 6;
- face-edge bunny: `repeated-boundary-node`, cell 2, halfedge 69, node 20,
  source face 6.

This replaces the untyped `InvalidArrangementDomainIdentity` blocker from
P5-TB18 and localizes the next correction to successful side-subdivision
boundary-cycle construction.

## Production fixture matrix

All direct cases used backend `SurfaceCells`, fallback `Fail`, and source-grid
recovery disabled. No fallback or recovery occurred.

| Case | Result | Completed quads | Earliest typed failure |
|---|---|---:|---|
| plane | fail | 12 | `completion/output-validation:SelfIntersectingFace`, face 6 |
| cylinder | fail | 246 | `completion/output-validation:SelfIntersectingFace`, face 107 |
| multi-face seam | fail | 24 | `completion/output-validation:SelfIntersectingFace`, face 2 |
| close sheets | fail | 34 | `completion/output-validation:SelfIntersectingFace`, face 6 |
| mechanical feature | fail | 0 | successful subdivision: repeated node 67 in cell 24 |
| prescribed sphere | fail | 0 | successful subdivision: repeated node 13 in cell 2 |
| torus | fail | 0 | `IncompleteSurfaceCellComplex` |
| thin bent tube | fail | 0 | `IncompleteSurfaceCellComplex` |

Plane, cylinder, seam, and close-sheets prove that completion creates nonempty
buffers, but the buffers are already self-intersecting before optimization.
Optimizer rollback cannot repair an invalid completion checkpoint. The
completion producer must be corrected.

The pipeline stage-lineage tests also regress because newly inserted
pre-optimization completion validation preempts injected optimization or
validation failures. Validation must remain authoritative while preserving the
intended injected-stage and fallback semantics.

## Random bunny

### Face-edge field

Four independent processes complete with one deterministic failed-result
signature:

- result-signature SHA-256:
  `6c178a01567978c1158a4abdbd99e5e1c0f176351b8a37be97fa916354a24a6d`;
- wall range: **19.673779–20.659238 s**, median **20.409684 s**;
- peak working-set range: **204,283,904–204,439,552 B**;
- estimated simultaneous owned bytes: **38,216,984 B**;
- owned/RSS coverage: **18.69–18.71%**;
- failure: successful subdivision produced `repeated-boundary-node`, cell 2,
  halfedge 69, node 20;
- trace segments: `12,130`;
- arrangement/simplified cells: `7,405 / 7,405`;
- odd cells: `1,860 -> 0`;
- parity split edges: `2,213`;
- side-repair inserted vertices: `8,137`;
- completion output/reuse: `0 / 0`;
- fallback/recovery: none.

Compared with P5-TB18, wall time drops from **98.613553 s** to approximately
**20.4 s**, peak working set from **2,513,285,120 B** to approximately
**204.4 MB**, and estimated owned bytes from **636,377,024 B** to
**38,216,984 B**.

### Smooth field

Four independent processes also complete with one deterministic failed-result
signature:

- result-signature SHA-256:
  `0eb93a5dfeebb9bf944d83dc13fd25e117850e901a2c7cd97c5417ae3308bbcf`;
- wall range: **31.468875–32.522140 s**, median **31.944037 s**;
- peak working-set range: **450,940,928–451,096,576 B**;
- estimated simultaneous owned bytes: **195,565,304 B**;
- owned/RSS coverage: **43.35–43.37%**;
- deterministic failure: `DuplicateStitchedQuad`, completion-template conflict,
  first patch 3979 versus second patch 401;
- trace segments: `80,862`;
- arrangement/simplified cells: `21,298 / 21,298`;
- odd cells: `959 -> 0`;
- parity split edges: `2,729`;
- completed output/reuse: `0 / 0`;
- fallback/recovery: none.

P5-TB18 smooth was SIGKILL/137 at **3,801,161,728 B** RSS. The compact registry
removes that catastrophic growth. Determinism currently applies to the failed
result, not a successful quad mesh.

### Resource and memory gates

Both bunny paths satisfy the established limits of **39.228299 s** and
**1,115,394,560 B**. The resource gate passes.

The same-sample 75% memory-reconciliation gate fails:

- face-edge categorized ownership covers approximately **18.7%** of peak RSS;
- smooth categorized ownership covers approximately **43.4%** of peak RSS.

The remaining simultaneous ownership, allocator capacity, completion inventory,
process/runtime, and mapped-file categories must be measured against the same
sample rather than inferred from unrelated runs.

## Root-cause findings

1. **Successful subdivision boundary cycle:** side subdivision can repeat one
   boundary node while reporting successful mutation. Repair the producer using
   the typed cell/halfedge/node evidence.
2. **Cylinder DCEL incidence:** canonical open-cylinder construction remains
   malformed before extraction. Add a typed incidence audit and correct periodic
   seam/cell-cycle assembly.
3. **Shared-edge parity topology:** the two-odd-cell parity fixture becomes
   topology-invalid after registry-backed mutation. Recompute and validate the
   producer transactionally.
4. **Route/reuse:** same-corner distinct-boundary validation prevents cache
   lookup, so genuine reuse remains zero.
5. **Pipeline stage semantics:** completion validation preempts injected
   optimization/validation failure lineage and fallback expectations.
6. **Completion output:** four supported fixtures produce self-intersecting
   completed buffers; repair completion, not optimizer rollback.
7. **Smooth completion conflict:** smooth bunny deterministically emits a
   completion-template duplicate stitched quad.
8. **Incomplete complexes:** torus and thin bent tube remain incomplete.
9. **Memory telemetry:** catastrophic duplication is fixed, but current
   ownership categories explain less than 75% of same-sample peak RSS.

## Gate disposition

| Gate | Result |
|---|---|
| Package integrity | pass |
| Phase 14–18 | pass — 235/235 |
| Phase 16 | pass — 39/39 |
| Phase 17 | pass — 26/26 |
| Typed prepared-domain evidence | pass |
| Midpoint mutation and rollback | pass |
| Full suite terminates | pass |
| Full suite clean | fail — 583/599 |
| Positive exact reuse | fail |
| Canonical cylinder topology | fail |
| Valid nonempty production output | fail |
| Pipeline failure/fallback semantics | fail |
| No fallback/source-grid recovery | pass |
| Bunny wall/RSS limits | pass |
| Four-run deterministic failed outcomes | pass |
| 75% same-sample memory reconciliation | fail |

## Required next turn

Proceed with **P5-CB117 through P5-CB125 code changes + compile-only build**.
Follow:

`.agents/Directional/Milestone_G_P5_Post_TB19_Completion_Topology_Reuse_Output_Code_Build_Plan.md`

Compile exactly `directional_core`, `directional_pipeline`,
`directional_phase1_tests`, and `directional_benchmarks`. Execute no test,
benchmark, custom mesh, help/list/discovery command, or compiled project binary
in that code/build turn.
