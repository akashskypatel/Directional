# Milestone G P5-TB24 Artifact-Only R1C Test and Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Turn type:** artifact-only runtime validation

## Disposition

P5-TB24 is complete. The R1C shared-edge orientation correction is validated, R0 recovery authority is now closed, and the complete packaged suite terminates normally. R1 remains open because exact manifold adjacency is still incorrectly split when incident faces carry different local-sheet labels.

Do not advance to R2.

## Package authority

Artifact `8904835304`, `surface-cell-p5-r1c-github-source-linux-release`, was executed directly.

- archive SHA-256: `cf4d2532353d8f93848d01b51f9ee4d5ddbed0ff365e9acccab69688b3c4e2cc`;
- exact compiled source: `f4cce52006d21a248473e327ada1d66183af54e6`;
- workflow event commit: `f652e518152b2944b176464b2ea8cfd99d09ccda`;
- applied source-diff SHA-256: `b41f4a6ffc517d1547a6da777fe01fc55e18e0b09aad47db83843333f6bea99c`;
- source status empty;
- recursive checksums **40/40**;
- package files **42**;
- fixture files **26**;
- recursive submodule records **9**;
- all four packaged target hashes verified;
- source archive contains the corrected orientation predicate, the whole-mesh orientation-reversal test, and the Phase 22 validator source in `directional_phase1_tests`.

No configure, build, relink, patch, regeneration, or source modification occurred.

## R1C and R0 focused gates

| Scope | Result |
|---|---:|
| `SourceChartTransitionsR1.*` | **7/7 passed** |
| `SourceAuthoritativeMeshValidatorPhase22.*` | **6/6 passed** |
| Focused recovery authority | **9/9 passed** |

The corrected graph now accepts opposite shared-edge traversal, rejects equal-direction traversal, preserves inverse endpoint/barycentric maps, and remains invariant under face-row and whole-mesh orientation changes.

The explicit planar recovery case now succeeds and reports `SourceGridRecovery`. Recovery remains default-off, fallback `Fail` does not run legacy output, paired-boundary rejection remains fail-closed, and component/sheet provenance is preserved.

## Remaining graph-dependent failures

The focused graph-dependent scope is **3/6 passed**.

Failed:

1. `PureQuadCompletionPhase18.CompletionAcceptsBoundaryVertexAndEdgeChartAliases`
2. `SurfaceArrangementPhase16.AdjacentPerFaceChartsShareOneCanonicalCellOwnershipClass`
3. `SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation`

The completion alias failure remains:

```text
CompletionOwnershipComponentSheetMismatch;
sourcePatch=27;localVertex=10;storedFace=1;
entity=source-vertex;sourceVertex=0;
candidateFaces=0,1;patchFaces=0;component=0;sheet=0
```

## Earliest remaining R1 producer

`SourceChartTransitionGraph::build()` still admits a manifold shared-edge transition only when both incident faces have equal source-component **and equal local-sheet** labels.

That local-sheet equality gate is inconsistent with established exact-adjacency contracts:

- tracing explicitly allows adjacent local-sheet charts across a genuine source edge or source vertex;
- completion must accept source-vertex and source-edge aliases supported by adjacent incident charts;
- Phase 16 expects adjacent per-face charts with different local-sheet labels to share one canonical ownership class;
- the bunny singularity fan must traverse the exact incident fan across local chart labels;
- `MilestoneGP26.FeatureRailVerticesSupportBothIncidentLocalSheets` expects a feature-rail vertex to support both incident local sheets.

Local-sheet labels must remain authoritative provenance and must continue to block proximity-based capture, projection, and disconnected close-sheet reconciliation. They must not split an exact manifold source adjacency within one source component when no hard rail, boundary, or nonmanifold barrier intervenes.

## Phase regressions

### Phase 14–18

- P5-TB23: **233/242**.
- P5-TB24: **240/243**.

The orientation correction recovered six prior failures and added one passing orientation-reversal contract. Three local-sheet exact-adjacency failures remain.

### Phase 16

- **37/39 passed**.
- Remaining failures are the adjacent ownership class and bunny singularity fan tests.

### Phase 20

- P5-TB23: **35/48**.
- P5-TB24: **46/48**.

Remaining failures:

- `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput`;
- `SurfaceCellPipelinePhase20.ValidationRejectionCannotReportCompletedSurfaceCells`.

The second is preempted because completion fails before the intended validation-stage rejection.

## Analytic direct production

All cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Result | Quads | Validation failures | Wall time | Peak working set |
|---|---:|---:|---:|---:|---:|
| Plane | failed | 12 | 15 | 0.013002 s | 8,491,008 B |
| Multi-face seam | failed | 24 | 22 | 0.022407 s | 8,654,848 B |
| Close sheets | failed | 34 | 27 | 0.034595 s | 8,826,880 B |

Every case reports `NotProductionReady/completion`, output origin `None`, and earliest serialized producer `completion/output-validation: AggregateCompletionValidationFailure`. None used recovery, fallback, or legacy output.

Compared with P5-TB23, validation failures fell:

- plane: **27 → 15**;
- seam: **46 → 22**;
- close sheets: **61 → 27**.

The orientation fix therefore removed a substantial invalid-graph contribution, but direct production remains **0/3**.

## Complete suite

The packaged binary discovered **613 tests** and terminated normally within the 1200-second watchdog:

- **590/613 passed**;
- **23 failed**;
- test time: **75.260 seconds**;
- maximum resident set: **256,544 KiB**.

This closes the P5-TB23 termination regression. The suite now passes through the GP26 and GP27 bunny production cases instead of stalling.

The 23 failures include the four local-sheet/exact-adjacency indicators listed above, production-output expectations preempted at completion, known later completion-route failures, and later-stage lineage tests that cannot reach their injected stage while completion remains invalid.

## Decision

- R0 recovery authority: **closed**.
- R1 shared-edge orientation predicate: **closed**.
- R1 exact adjacent-local-sheet reconciliation: **open**.
- Advance to R2: **no**.

The next turn is **P5-R1D adjacent local-sheet exact-adjacency correction plus compile-only build**.

Preserve all prohibitions: no validator weakening, frequency/count/order ownership selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.
