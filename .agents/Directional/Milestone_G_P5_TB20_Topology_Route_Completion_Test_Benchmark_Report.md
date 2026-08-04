# Milestone G P5-TB20 Topology, Route, and Completion Test/Benchmark Report

**Date:** 2026-08-03  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** artifact-only test and benchmark

## Disposition

P5-TB20 is complete as an artifact-only runtime turn. P5 remains open.

Artifact `8879272440` was extracted and executed directly. No configure, build,
relink, patch, source regeneration, or source modification occurred. Package
authority passed, but the CB117–CB125 checkpoint does not produce a valid
returned production quad mesh.

Main outcomes:

- package integrity passed: exact source, implementation ancestry, empty source
  status, **40/40** checksums, **26** fixtures, and **9** recursive submodules;
- canonical rollback fixture correction passes;
- typed cylinder incidence now identifies `non-disk-cell`, cell `0`, halfedge
  `43`, twin `42`, next `29`;
- invalid replacement boundaries are rejected before successful commit and
  retain typed repeated-node evidence;
- Phase 14–18 regresses from **235/235** to **234/235** because the provenance
  test uses a geometrically invalid zig-zag boundary fixture;
- Milestone D improves from **5/7** to **6/7**;
- Milestone E regresses from **23/26** to **21/26**;
- Phase 20 remains **46/48**;
- the full suite terminates at **581/599** in **103.05 s**, maximum RSS
  **529,739,776 B**;
- all eight direct production fixtures still fail without fallback or recovery;
- four face-edge bunny runs are deterministic failed results within resource
  limits;
- smooth bunny changes from duplicate stitched output to an earlier typed local
  embedding rejection, but its second independent run takes **45.55 s** and
  exceeds the established **39.228299 s** wall limit, so four-run repetition was
  stopped;
- positive completion reuse remains `0/0`;
- same-sample categorized memory remains below 75%.

## Artifact authority

- artifact ID: `8879272440`;
- artifact name: `surface-cell-p5-cb125-github-source-linux-release`;
- archive SHA-256:
  `bb9aca3881727093411f7f1012dbae9a65e1d62805a4c5a4900af58bd8f7fc76`;
- exact compiled source:
  `bc8ed616adfe59d4a3e0d5dca8ef7503d3c00e83`;
- implementation commit:
  `a8f8971766f55cf11828a1ae90daad3b98b50664`;
- reviewed patch SHA-256:
  `5657eb0b64aed76a5718d40a5db61e21d0c8fce60bb620e8abcf359062e873b9`;
- source status bytes: `0`;
- recursive checksums: **40/40**;
- fixtures: **26**;
- recursive submodule records: **9**.

## Test results

| Scope | Passed | Failed | Total | Runtime |
|---|---:|---:|---:|---:|
| Focused rollback/incidence/parity/route/output | 2 | 6 | 8 | 0.124 s |
| Phase 14–18 | **234** | **1** | **235** | 0.018 s |
| Milestone D | 6 | 1 | 7 | <0.001 s |
| Milestone E | 21 | 5 | 26 | 0.007 s |
| GP23 + GP24 | 10 | 4 | 14 | 0.037 s |
| Phase 20 | 46 | 2 | 48 | 0.247 s |
| Full suite | **581** | **18** | **599** | **103.05 s** |

The full-suite maximum RSS was **529,739,776 B**. It terminates normally, but
clean-suite closure regresses by two tests relative to P5-TB19.

## Closure and regression findings

### Canonical rollback closes

`MilestoneDClosure.PartialMultiEdgeInterfaceFailsClosed` now passes. The test
enters the production canonical ownership state before recording the committed
baseline and still proves full structural identity after rejection.

### Typed cylinder evidence works; cylinder topology remains invalid

The open-cylinder test reports:

`non-disk-cell cell=0 halfedge=43 twin=42 next=29`.

The next implementation must reconstruct the cell cycle and periodic seam so
cell 0 is a simple disk while the whole open cylinder remains Euler 0 with two
boundary loops and preserved protected rails.

### Shared parity fixture does not reach the parity transaction

`SharedEdgeParityRepairConforminglyCompletesTwoOddCells` fails its initial
`topologyValid` assertion after canonical ownership setup. The next turn must
run typed incidence/domain auditing on the fixture and correct the invalid
manual DCEL precondition. Parity repair must not accept an invalid baseline.

### Repeated-node false success is removed, but no valid alternative exists

Mechanical feature, sphere, and face-edge bunny now fail before invalid commit:

- mechanical: cell `2`, halfedge `719`, node `65`, source face `109`;
- sphere: cell `2`, halfedge `37`, node `13`, source face `7`;
- face-edge bunny: cell `2`, halfedge `45`, node `20`, source face `0`.

This closes the false-success defect but not completion. A conforming bounded
alternate replacement path is still required.

### Same-corner arbitration is over-permissive and reuse remains zero

The exact-disjoint rule permits the intentionally overlapping semantic fixture
to consume a structural candidate and succeed. That fixture duplicates the same
geometric/source domain while changing rail/curve identifiers and must still be
rejected before candidate expansion.

The valid annular parallel-route fixture reaches route validation but still
fails with a duplicate stitched quad classified as
`same-corner-distinct-boundary`. Incremental recomputation, reused completions,
and recomputed completions remain `0/0/0`.

### One invalid test fixture must be corrected

`CompletionVerticesCarrySourceProvenance` uses boundary positions
`(i, i mod 2, 1)`, creating a zig-zag/non-simple six-edge patch. The test is
intended to verify provenance, not invalid geometry. Replace it with a simple
nondegenerate embedded boundary while retaining component `2`, sheet `3`, and
its provenance assertions. Keep the production embedding validator enabled and
add a separate negative zig-zag regression.

### Local embedding validation exposes real producer defects

`PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion` reaches
`InvalidCompletionQuadEmbedding;localQuad=0`. Cylinder, thin tube, and smooth
bunny report local quads `1`, `0`, and `0`, respectively. The diagnostic must
also identify owning patch/cell, backend, variant, corner identity, and exact
geometric classification.

### Pipeline lineage remains open

The GP23, GP24, and Phase20 lineage failures remain because completion
validation preempts declared optimization/validation injection stages.
`RemeshPipeline.cpp` was not changed in CB117–CB125.

## Direct production matrix

All cases used backend `SurfaceCells`, fallback `Fail`, and disabled source-grid
recovery. No fallback or recovery occurred.

| Case | Result | Completed quads | Earliest failure |
|---|---|---:|---|
| plane | fail | 12 | `completion/output-validation:LocalSheetMismatch`, cell 4, face 7 |
| cylinder | fail | 0 | `InvalidCompletionQuadEmbedding;localQuad=1` |
| multi-face seam | fail | 24 | `completion/output-validation:LocalSheetMismatch`, cell 2, face 15 |
| close sheets | fail | 34 | `completion/output-validation:LocalSheetMismatch`, cell 3, face 13 |
| mechanical feature | fail | 0 | repeated node: cell 2, halfedge 719, node 65 |
| prescribed sphere | fail | 0 | repeated node: cell 2, halfedge 37, node 13 |
| torus | fail | 0 | `IncompleteSurfaceCellComplex` |
| thin bent tube | fail | 0 | `InvalidCompletionQuadEmbedding;localQuad=0` |

The previous self-intersection failures for plane, seam, and close sheets are
replaced by source-sheet mismatch evidence. Completed corner provenance and
patch ownership must select one consistent source sheet before global insertion.

## Random bunny

### Face-edge field

Four independent processes complete with one stable failed-result signature:

- signature:
  `f2663c72dda805ffecf5415591180fecf14999a2d969a6e5b5411c3d6e5cdd1f`;
- wall range: **19.124283–22.820833 s**;
- peak working-set range: **141,352,960–141,701,120 B**;
- estimated simultaneous owned bytes: **38,216,984 B**;
- categorized coverage: **26.97–27.04%**;
- failure: repeated boundary node, cell `2`, halfedge `45`, node `20`;
- arrangement/simplified cells: `7,405 / 7,405`;
- completed quads and reuse/recompute: `0`, `0/0`.

All four runs satisfy the established wall and RSS limits. Peak working set
falls from about 204 MB in P5-TB19 to about 141 MB.

### Smooth field

Two independent processes produce the same failed-result signature:

- signature:
  `eee229585de5ea08384677920e3cd989578e9e0dd899abda753610f50bea5718`;
- run 1: **31.544880 s**, **450,207,744 B**;
- run 2: **45.549332 s**, **450,301,952 B**;
- estimated simultaneous owned bytes: **176,144,432 B**;
- categorized coverage: **39.12–39.13%**;
- failure: `InvalidCompletionQuadEmbedding;localQuad=0`;
- arrangement/simplified cells: `21,298 / 21,298`;
- completed quads and reuse/recompute: `0`, `0/0`.

Run 2 exceeds the established wall limit. Smooth runs 3 and 4 were not started;
four-run determinism is not established.

## Gate disposition

| Gate | Result |
|---|---|
| Package integrity | pass |
| Canonical rollback baseline | pass |
| Typed cylinder incidence | pass evidence; topology fails |
| Phase 14–18 | fail — 234/235 |
| Phase 16 | pass — 39/39 |
| Phase 17 | pass — 26/26 |
| Full suite terminates | pass |
| Full suite clean | fail — 581/599 |
| Shared-edge parity | fail before transaction |
| Invalid repeated-node commit prevention | pass |
| Valid repeated-node alternative | fail |
| Positive exact reuse | fail — 0/0 |
| Pipeline lineage | fail |
| Valid production output | fail — 0/8 |
| No fallback/recovery | pass |
| Face-edge resources/four-run failed determinism | pass |
| Smooth resource repeat | fail |
| Smooth four-run determinism | not evaluated |
| 75% memory reconciliation | fail |

## Required next turn

Proceed with **P5-CB126 through P5-CB134 code changes + compile-only build**.
Follow:

`.agents/Directional/Milestone_G_P5_Post_TB20_Topology_Route_Completion_Code_Build_Plan.md`

Compile exactly `directional_core`, `directional_pipeline`,
`directional_phase1_tests`, and `directional_benchmarks`. Execute no project
binary in that code/build turn.
