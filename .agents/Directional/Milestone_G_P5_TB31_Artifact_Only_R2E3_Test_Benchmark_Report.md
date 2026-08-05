# Milestone G P5-TB31 Artifact-Only R2E3 Test/Benchmark Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-TB31 artifact-only validation is complete against exact source `571ff9095ec06a8931fc54aafe1a70a38f80b4a1` and artifact `8918054686`.

R2E3 **closes the whole-mesh orientation-reversal directed-incidence hash regression**, returning the complete suite to the same 28-failure set as P5-TB29. It does **not** close planar, interior-hard-rail, or open-cylinder boundary publication.

R2 remains open. Do not advance to intrinsic-fan R2F or R3.

## Artifact authority

- artifact: `8918054686`, `surface-cell-p5-r2e3-github-source-linux-release`;
- archive SHA-256: `6491eaaaa2276b0d89ddcda5f94d1b8e1e6cf6fe251b2b6ec99d242d8e29534d`;
- exact source: `571ff9095ec06a8931fc54aafe1a70a38f80b4a1`;
- workflow event: `2d1d616eaf6e5be025e1a190b995172954d3f102`;
- reviewed/applied diff SHA-256: `f7a26c3b3869a59247532e86f4468e0d17bce7caa72cf31a5c315b620fac1ff3`;
- source status empty;
- recursive checksums **48/48**;
- physical package files **49**;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes match the Code + Build report;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e3.yml`.

No configure, compilation, relink, patch, regeneration, fixture modification, or source modification occurred during this turn.

## Focused results

| Scope | Result |
|---|---:|
| Source-chart R1 | **11/11** |
| Source validator | **6/6** |
| Recovery authority | **9/9** |
| Feature/barrier authority | **8/8** |
| Graph-dependent | **5/6** |
| R2 focused | **11/14** |
| Milestone D | **5/7** |
| Phase 14–18 | **233/242** |
| Phase 16 | **43/45** |
| Phase 17 | **20/26** |
| Phase 18 | **57/57** |
| Phase 20 | **46/48** |

Relative to P5-TB30:

- `SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence` is now passing;
- R2 focused improves from **10/14** to **11/14**;
- Phase 16 improves from **42/45** to **43/45**;
- Phase 14–18 improves from **232/242** to **233/242**;
- no new failure appears.

The bunny singularity-fan contract remains the sole graph-dependent failure and is still independent of the boundary producer.

## Boundary producer evidence

### Planar disk

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` now passes the complete predecessor-bijection gate but fails during orbit analysis:

- `incidenceValid=false`;
- typed failure `RepeatedEdgeCycle`.

This is progress beyond P5-TB30's `IncompletePermutation`, but it is not closure. The local target transposition creates a bijection whose cyclic face walk traverses a non-bridge undirected edge more than once.

### Interior hard rail

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` fails before orbit publication:

- `incidenceValid=false`;
- typed failure `BoundaryLocalPermutationConflict`.

The one-target swap assumption does not define the complete cyclic sector mapping at a boundary node split by an interior hard rail.

### Open cylinder

`MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` reaches a published complex, but the independent simplification incidence audit rejects it:

- failure `NonDiskCell`;
- `cell=1`, `halfedge=30`, `twin=42`, `next=29`.

The same incorrect local cyclic pairing produces a bounded non-disk orbit rather than the expected disk cells. The cylinder therefore remains invalid even though raw successor cardinality is no longer the first reported defect.

### Orientation identity

`SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence` passes. Canonical paired boundary-twin incidence identity is therefore retained in the next correction.

## Earliest remaining producer

R2E3 performs a two-target transposition at each affected node:

1. force the exterior incoming halfedge to the authoritative exterior outgoing halfedge;
2. find the generic owner of that outgoing target;
3. give that owner the exterior incoming halfedge's former target.

This preserves target cardinality in simple cases but does not construct the authoritative **rotational system** around the node. A permutation can be bijective and endpoint-continuous while still pairing rays across the wrong sectors. That explains all three observed boundary outcomes:

- planar: bijection passes, face orbit repeats an edge;
- hard rail: the transposition cannot satisfy the multi-sector local map;
- cylinder: the resulting orbit is non-disk.

The next correction must rebuild the complete local successor map from canonical cyclic ray order and explicit source-boundary exterior/interior sectors. It must not patch predecessor counts, merge cells, or weaken orbit/disk validation.

## Direct analytic cases

All cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Result | Arrangement | Simplified | Completed quads | Earliest invalid producer | Wall time | Peak working set |
|---|---|---:|---:|---:|---|---:|---:|
| plane | failed | 9 | 9 | 12 | `completion/output-validation`: `AggregateCompletionValidationFailure` | 0.030254 s | 8,527,872 B |
| multi-face seam | failed | 0 | 0 | 0 | `completion` | 0.017579 s | 8,372,224 B |
| close sheets | failed | 0 | 0 | 0 | `completion` | 0.030814 s | 8,679,424 B |
| cylinder | failed | 0 | 0 | 0 | `completion` | 0.183580 s | 9,969,664 B |

No direct production case closes. Seam, close sheets, and cylinder still violate the required nonzero arrangement-inventory gate.

## Complete suite

- discovered: **623**;
- passed: **595**;
- failed: **28**;
- errors/disabled: **0/0**;
- normal GoogleTest termination;
- GoogleTest runtime: **142.550 seconds**;
- sampled RSS lower bound: **169,268 KiB**;
- exact maximum RSS unavailable because the outer execution wrapper was terminated by the tool timeout while the test child continued to normal completion.

Compared with P5-TB30, exactly one failure closes and no failure is introduced. The 28-failure set is identical to P5-TB29.

P5-TB31 is **83.32% slower** than P5-TB30. This is not characterized as a performance regression or improvement while incidence remains invalid; P5-TB30 terminated dominant matrix work earlier. Dominant P5-TB31 cases were:

- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`: **49.099 s**;
- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition`: **44.356 s**;
- `ProductionManifestCases/.../7`: **43.253 s**.

## Decision

Do not advance to R2F or R3.

Proceed to **P5-R2E4 authoritative boundary-node rotational-system Code + Build**. Follow `.agents/Directional/Milestone_G_P5_R2E4_Boundary_Node_Rotation_Code_Build_Plan.md`.

Preserve the R2E3 orientation-invariant paired boundary identity and every passing R0/R1/R2C/R2D/R2E contract. Do not alter FlowRep, simplification, completion, fallback, cache, optimizer, lineage, or bunny intrinsic-fan behavior in the next turn.
