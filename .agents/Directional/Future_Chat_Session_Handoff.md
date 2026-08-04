# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB24 artifact-only validation is complete against exact source `f4cce52006d21a248473e327ada1d66183af54e6` and artifact `8904835304`.

R0 recovery authority is closed. The R1 shared-edge orientation predicate is closed. R1 remains open because exact manifold adjacency is still incorrectly split by unequal local-sheet labels.

Do not advance to R2.

Package authority:

- artifact `8904835304`, `surface-cell-p5-r1c-github-source-linux-release`;
- artifact SHA-256 `cf4d2532353d8f93848d01b51f9ee4d5ddbed0ff365e9acccab69688b3c4e2cc`;
- source status empty;
- recursive checksums **40/40**;
- package files **42**;
- fixtures **26**;
- recursive submodules **9**.

P5-TB24 configured, rebuilt, relinked, patched, regenerated, and modified no source.

The next turn is **P5-R1D adjacent local-sheet exact-adjacency correction plus compile-only build**. Compile exactly four required targets and execute no project binary.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB24_Artifact_Only_R1C_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb24-summary.json`
5. `.agents/Directional/Milestone_G_P5_R1D_Adjacent_Local_Sheet_Code_Build_Plan.md`
6. `.agents/Directional/Milestone_G_P5_R1C_Code_Build_Report.md`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB24 results

- `SourceChartTransitionsR1.*`: **7/7**;
- `SourceAuthoritativeMeshValidatorPhase22.*`: **6/6**;
- focused recovery authority: **9/9**;
- graph-dependent focused: **3/6**;
- Phase 14–18: **240/243**;
- Phase 16: **37/39**;
- Phase 20: **46/48**;
- analytic direct plane/seam/close sheets: **0/3**;
- complete suite: **590/613**, terminated normally in **75.260 seconds**;
- complete-suite maximum resident set: **256,544 KiB**.

The P5-TB23 GP26 bunny nontermination regression is closed. The suite passes through GP26 and GP27 production cases.

Analytic validation counts improved:

- plane **27 → 15**;
- seam **46 → 22**;
- close sheets **61 → 27**.

All three still fail at `completion/output-validation: AggregateCompletionValidationFailure`, output origin `None`, with recovery, fallback, and legacy execution false.

## Closed R1C and R0 contracts

1. Valid opposite source-edge traversal is accepted.
2. Invalid equal-direction traversal is rejected.
3. Endpoint and barycentric transition maps remain exact inverses.
4. Face-row and whole-mesh orientation invariance pass.
5. Packaged Phase 22 validator contracts pass.
6. Explicit planar recovery succeeds with `SourceGridRecovery` origin.
7. Recovery remains default-off and cannot masquerade as direct completion.

## Earliest remaining R1 root cause

`SourceChartTransitionGraph::build()` admits exact manifold adjacency only when incident faces share both source component and local-sheet label.

Source-component equality is a true topology barrier. Local-sheet equality is not a valid barrier by itself for exact adjacency.

The current condition causes:

- `PureQuadCompletionPhase18.CompletionAcceptsBoundaryVertexAndEdgeChartAliases`;
- `SurfaceArrangementPhase16.AdjacentPerFaceChartsShareOneCanonicalCellOwnershipClass`;
- `SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation`;
- `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets`.

Required semantics:

- local-sheet labels remain authoritative provenance;
- local-sheet labels continue to block world-space/proximity capture, projection, and disconnected close-sheet reconciliation;
- exact manifold source-edge adjacency and intrinsic source-vertex fans may cross local-sheet labels within one source component;
- hard rails, boundaries, nonmanifold sectors, different components, and disconnected topology remain barriers.

## P5-R1D required work

1. Remove local-sheet equality from exact manifold transition admission.
2. Preserve equal source-component identity, valid opposite winding, exactly-two-face incidence, and hard-rail exclusion.
3. Preserve every face's local-sheet label in chart IDs, transition records, membership identities, provenance, diagnostics, and hashes.
4. Restore intrinsic source-vertex fans from admissible exact adjacency across local charts.
5. Preserve barriers for hard rails, source boundaries, nonmanifold sectors, components, and disconnected topology.
6. Preserve same-sheet restrictions for proximity/capture/projection operations.
7. Correct only immediate arrangement, completion-alias, validator, or explicit-recovery assumptions that still contradict exact adjacency.
8. Add focused adjacency and barrier regressions without changing intended expectations.
9. Keep R2–R11 deferred.

## Compile-only boundary

Compile exactly:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Run no tests, benchmarks, custom meshes, help/list/discovery commands, or generated executables. Initialize detailed logging before fallible work and always upload the log artifact.

## Next runtime gate

The artifact-only turn after R1D must require:

- source-chart tests remain clean;
- packaged Phase 22 validator tests remain clean;
- recovery remains **9/9**;
- all three remaining graph-dependent focused tests pass;
- the feature-rail incident-sheet contract passes;
- Phase 14–18 is clean;
- analytic cases are not rejected by local-sheet incompatibility;
- the complete suite still terminates.

Advance to R2 only after these R1 gates close.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- Source chart labels and exact topological connectivity are distinct concepts: provenance labels must not erase genuine manifold adjacency.
- Keep local-sheet barriers for geometric capture while allowing exact source topology to establish adjacency.
- The orientation fix materially reduced validation failures and restored termination, but the next correction must remain on the same earliest R1 producer.
