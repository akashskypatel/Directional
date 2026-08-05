# Milestone G P5-TB30 Artifact-Only R2E2 Test/Benchmark Report

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-TB30 is complete against artifact `8916209271` and exact compiled source `f5305ade5bf5360df36b681d135e5299322f5fdb`.

R2E2 does **not** close the planar, hard-rail, or cylinder boundary producer. The complete suite regresses from **595/623** to **594/623**. The new failure is `SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence`; no P5-TB29 failure closes.

Do not advance to intrinsic-fan R2F or R3. The next turn is **P5-R2E3 boundary-node permutation splice and orientation-invariant boundary identity Code + Build**.

## Package authority

- artifact: `8916209271`, `surface-cell-p5-r2e2-github-source-linux-release`;
- archive SHA-256: `2117cc2b99bc82a197bb7ee94f3e21a9c8f71b48f735c15c878515dabd4915df`;
- exact compiled source: `f5305ade5bf5360df36b681d135e5299322f5fdb`;
- workflow event commit: `517735a53e4554d74cab14845cb8e26edb90de37`;
- reviewed/applied source diff SHA-256: `526c01714d6d11ca8c4e60458b176f0057d386a6d163e406bb89fb04c86a83ec`;
- workflow-log artifact: `8916209511`, SHA-256 `45606d385ffacdfc621c85d21316dca31bfd84cdc0421d16b6f990b817b47007`;
- empty source status;
- recursive checksums **48/48**;
- package files **49**;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- cleaned source contains only `.github/workflows/agent-source-snapshot.yml` and zero temporary payloads;
- source exclusion list contains only `.github/workflows/agent-build-p5-r2e2.yml`.

No configure, build, relink, patch, regeneration, or source/test/benchmark modification occurred during P5-TB30.

## Focused runtime results

| Scope | P5-TB29 | P5-TB30 | Result |
|---|---:|---:|---|
| Source-chart R1 | 11/11 | **11/11** | preserved |
| Phase 22 validator | 6/6 | **6/6** | preserved |
| Recovery authority | 9/9 | **9/9** | preserved |
| Feature/barrier authority | 8/8 | **8/8** | preserved |
| Graph-dependent | 5/6 | **5/6** | unchanged bunny failure |
| R2 focused | 11/14 | **10/14** | orientation regression |
| Milestone D | 5/7 | **5/7** | unchanged |
| Phase 14–18 | 233/242 | **232/242** | orientation regression |
| Phase 16 | 43/45 | **42/45** | orientation regression |
| Phase 17 | 20/26 | **20/26** | unchanged downstream failures |
| Phase 18 | 57/57 | **57/57** | preserved |
| Phase 20 | 46/48 | **46/48** | unchanged |
| Complete suite | 595/623 | **594/623** | one new failure |

## R2E2 boundary evidence

### Planar disk

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` now fails immediately with typed incidence failure `IncompletePermutation`.

R2E2 replaces exterior halfedge successors after the generic permutation is built, then recomputes predecessor counts. It does not rebuild the complementary interior mapping at the affected boundary nodes. The new exterior target can therefore retain a generic predecessor while the superseded generic target loses one. Publication is cleared before Euler, area, and exterior-owner assertions can run.

### Interior hard rail

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` fails with `BoundaryContinuationDiscontinuity`.

The authoritative loop sequence identifies adjacent source-boundary subsegments, but their raw arrangement endpoint node IDs differ at a hard-rail endpoint. Exterior continuation cannot be made valid solely by assigning `next`; boundary-vertex node authority and the interior/exterior local wedge partition must be constructed together.

### Open cylinder

`MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` still reaches independent incidence audit with `cell == -1`. An earlier boundary-incidence failure cleared transactional publication, so the two exterior loops and structural Euler zero remain unvalidated.

### Orientation-reversal regression

`SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence` remains incidence- and topology-valid in both orientations, but the hashes differ:

- forward: `17924083852263239109`;
- reversed: `13056443959550145429`.

R2E2 marks one directed boundary halfedge as authoritative exterior while its twin remains encoded through the generic directed-wedge path. Whole-mesh reversal swaps those roles. Hashing the two directed records independently is therefore not orientation invariant even when the published topology is equivalent.

### Bunny fan

`SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation` is unchanged: embedding and topology are invalid and zero center cells are published instead of three. It remains an independent deferred R2 producer.

## Earliest remaining producer

The source confirms this sequence:

1. Build the complete generic directed-wedge successor map.
2. Inventory boundary subsegments.
3. Overwrite only exterior boundary-halfedge `next` values.
4. Recompute predecessor counts and audit the resulting mixed map.

This is not sufficient. Authoritative exterior continuation changes a node-local permutation, not one isolated outgoing pointer. The exterior sector and complementary source-interior sector must be rebuilt together at every affected boundary node. Boundary endpoint identity must also be authoritative across a hard-rail fan split while preserving distinct pinched sheets and components.

The next correction must construct one transactional candidate successor array from node-local incoming/outgoing ray partitions and commit it only after a complete bijection and endpoint-continuity audit. It must not merge cells after orbit extraction or compensate for missing predecessors.

## Direct analytic evidence

All direct cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Result | Arrangement | Simplified | Quads | Earliest failure | Wall | Peak working set |
|---|---:|---:|---:|---:|---|---:|---:|
| plane | failed | 9 | 9 | 12 | `completion/output-validation: AggregateCompletionValidationFailure` | 0.013597 s | 8,388,608 B |
| multi-face seam | failed | 0 | 0 | 0 | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 0.015400 s | 8,359,936 B |
| close sheets | failed | 0 | 0 | 0 | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 0.020989 s | 8,605,696 B |
| cylinder | failed | 0 | 0 | 0 | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 0.134064 s | 10,579,968 B |

Plane still reports 15 output-validation failures. Seam, close sheets, and cylinder retain zero arrangement cells. The packaged matrix has no separate disconnected-close-sheets direct case; its focused topology contract remained passing.

## Complete-suite result

- **623 tests discovered**;
- **594 passed**;
- **29 failed**;
- **0 errors** and **0 disabled**;
- normal GoogleTest termination in **77.761 seconds**;
- no watchdog expiration;
- one new failure and zero closed failures relative to P5-TB29;
- exact maximum RSS unavailable because the outer execution wrapper detached while the test continued;
- sampled process RSS reached at least **220,348 KiB**;
- XML and stdout/stderr finalized normally.

The runtime is 61.26% shorter than P5-TB29, but this is not accepted as performance progress while boundary publication remains invalid. The dominant matrix tests also terminated much earlier, consistent with earlier rejection rather than demonstrated optimization:

- GP27 production matrix: **27.165 s**;
- GP26 production matrix: **24.369 s**;
- parameterized bunny case `/7`: **22.775 s**.

## Failure classification

- package integrity: valid;
- R0/R1 focused authority: valid;
- original planar, hard-rail, cylinder, bunny, Phase 17, and Phase 20 failures: production implementation defects;
- orientation-reversal hash failure: new R2E2 production regression;
- existing fixtures and assertions remain structurally valid and test their intended contracts;
- exact maximum RSS: infrastructure/evidence limitation only.

## Decision

- R0 recovery authority: **closed**;
- R1 source transitions and validator authority: **closed**;
- R2C/R2D prior narrow closures: **preserved**;
- R2E2 authoritative exterior successor construction: **not closed**;
- R2 complete permutation and endpoint continuity: **open**;
- R2 orientation-invariant incidence identity: **regressed/open**;
- R2 structural Euler runtime authority: **blocked**;
- R2 singularity-fan embedding: **open**;
- advance to R2F: **no**;
- advance to R3: **no**;
- next turn: **P5-R2E3 boundary-node permutation splice and orientation-invariant boundary identity Code + Build**.

Every turn must end with a new final PR #8 comment containing the concise handoff summary after documentation commits are complete.
