# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB17 artifact-only test and benchmark is complete. P5 remains open.

Tested artifact:

- ID `8875627676`
- `surface-cell-p5-cb98-github-source-linux-release`
- exact source `680d81c6946f45b1daed9dd477cfde565f8ac7a2`
- SHA-256 `b9560c9438289e90e6acca3a0f4b7f1d46a5ad34663693c1243bf4176056c165`
- source status empty
- checksums **38/38**
- fixture files **26**
- bunny **502 vertices / 1,000 faces**

No build, configure, relink, patch, or code regeneration occurred.

Runtime result:

- complete suite **572/594**;
- 22 assertion failures;
- no abnormal termination;
- all former signal-11 cases terminate normally;
- four face-edge and four smooth-field runs are deterministic and inside wall/
  memory limits;
- both field paths fail closed at
  `BoundaryParityRepair:MixedCellSourceScope` and emit no output;
- exact reuse remains zero;
- invalid midpoint still stops at `MissingCommonSourceChart`;
- cylinder topology/output remains invalid;
- memory ownership explains only **28.0–33.6%** of peak RSS.

The next turn is **P5-CB99 through P5-CB107 code changes + compile-only build**.
Execute no test, benchmark, custom mesh, compiled binary, help/list, or discovery
command in that turn.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB17_Parity_Reuse_Output_Memory_Test_Benchmark_Report.md`
4. `benchmark-results/p5-tb17-summary.json`
5. `.agents/Directional/Milestone_G_P5_Post_TB17_Source_Scope_Topology_Reuse_Output_Memory_Code_Build_Plan.md`
6. `.agents/Directional/GitHub_Workflow_Policy.md`

## New source regressions

P5-TB16 had Phase 14–18 at 230/230 and Milestone D at 6/7. P5-TB17 has twelve
additional failures reproduced by both the GitHub GCC artifact and the
independently compiled Clang artifact:

Phase 16:

- `AuthoritativeTopologyDiagnosticsMatchSingleDiskSource`
- `AuthoritativeTopologyDiagnosticsHandleDisconnectedSourceComponents`
- `CurvedMultiFaceFixturePreservesStitchedTopologyAndEulerCharacteristic`
- `BunnySingularityFanUsesIntrinsicSourceVertexRotation`

Phase 17:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`
- `TransactionalMutationCommitsExtractedOversampledCandidate`
- `TransactionalMutationPreservesHardRailSupport`
- `OptionalLayoutBridgeHealsPinchedCellTransactionally`
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`

Milestone D:

- `CurvedStitchedCellUsesGlobalEmbeddingAndSourceFaces`
- `InteriorHardRailIsNotClassifiedAsExteriorBoundary`

The ten P5-TB16 failures also remain.

## Root cause to address first

P5-CB91 replaced oriented-cell scope selection with strict intersection of every
boundary record's raw `(component, localSheetByFace)` pair. The trace contract,
however, permits a valid cell to cross adjacent per-face local chart IDs through
intrinsic source adjacency while remaining in one connected physical sheet and
component.

The code must distinguish:

- connected source component;
- canonical cell-side/sheet equivalence class;
- exact per-source-face local chart on each oriented halfedge and occurrence.

Accept adjacent chart IDs only when intrinsic adjacency proves they belong to
the same canonical cell-side class. Continue to reject disconnected and close/
opposing physical sheets. Do not restore frequency voting or choose by count or
order.

Benchmark evidence identifies the first cells:

- face-edge: cell 19, halfedge/twin 21767/21766, component values `[0,0]`, local
  chart values `[0,1]`, selected `-1/-1`;
- smooth: cell 45, halfedge/twin 46451/46450, component values `[0,0]`, local
  chart values `[0,1]`, selected `-1/-1`.

## Required P5-CB99–P5-CB107 work

- **CB99:** canonical ownership across adjacent local charts; restore four Phase
  16 and two Milestone D regressions.
- **CB100:** propagate canonical ownership through simplification; restore all
  six Phase 17 regressions.
- **CB101:** parity preflight validates canonical ownership, not raw chart-ID
  equality; retain typed incompatibility evidence and exact rollback.
- **CB102:** repair route validation and real exact reuse; both guaranteed cases
  must reach cache lookup and later report positive reuse.
- **CB103:** make the invalid-midpoint fixture prove a valid common chart first,
  then fail at `InvalidMidpointEmbedding` after temporary mutation and roll back
  bit-exactly.
- **CB104:** rebuild the canonical cylinder DCEL with valid incidence,
  embedding, orientation, Euler 0, one component, and two boundary loops.
- **CB105:** correct the earliest invalid producer for production outputs.
- **CB106:** account dominant retained/overlapping allocations and target at
  least 75% peak-RSS reconciliation with categorized remainder.
- **CB107:** add regressions; compile/package exactly `directional_core`,
  `directional_pipeline`, `directional_phase1_tests`, and
  `directional_benchmarks`; execute no binary.

## Preserved prohibitions

- no validator weakening;
- no frequency-vote scope restoration;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Workflow policy

Every GitHub workflow must follow
`.agents/Directional/GitHub_Workflow_Policy.md`:

- initialize detailed logging before fallible work;
- retain complete success/failure activity;
- always upload a separate log artifact under `if: always()`;
- use that artifact for failure diagnosis;
- do not expose secrets in traced output;
- preserve the compile-only turn boundary.

## Key lessons

- A raw `localSheetByFace` ID is a per-face chart label, not by itself the
  canonical identity of a physical cell side across adjacent source faces.
- A direct unit regression can pass while aggregate topology contracts regress;
  always preserve Phase 14–18 and Milestone D closure when changing authority
  semantics.
- Compiler-independent reproduction is strong evidence of a source contract
  regression rather than toolchain variance.
- Typed first-invalid evidence is useful only when it represents the correct
  ownership model; cells 19 and 45 currently expose the raw-chart mismatch.
- Memory payload accounting is not sufficient; allocator capacity and concurrent
  retained owners must be included against the same RSS sample.
