# Milestone G P5-TB32 Artifact-Only R2E4 Test/Benchmark Report

**Date:** 2026-08-05  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-TB32 is complete against artifact `8929111021` and exact source `ec44ab7570f258f800a27086fca053c573878a13`.

R2E4 does **not** close the boundary rotational-system producer. It introduces a broad fail-closed regression at ordinary degree-two source-boundary nodes. The new `MultipleInteriorRaysAtBoundaryVertexUseAdjacentRotationalSectors` contract also fails, but the earliest common failure occurs before the implementation reaches those high-valence nodes.

Do not advance to R2F or R3. The authoritative next turn is **P5-R2E5 degree-two boundary rotational degeneracy Code + Build**.

## Artifact authority

The package gate passed:

- archive SHA-256: `dcb3dcca095a62efde3bc534a8eafca1a5a3976f3e98b649845c6ca47c682450`;
- exact source: `ec44ab7570f258f800a27086fca053c573878a13`;
- workflow event: `d81351aeb6bb7b728ceaf5bf468f924383167eb9`;
- reviewed/applied diff: `33ee4e40c7e5146abd732796b771d74ed28b7808bae6b0ed14bd327fd902aa01`;
- source status empty;
- recursive manifest **48/48**;
- physical files **49**;
- fixtures **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- cleaned source contains only `agent-source-snapshot.yml` and zero payloads;
- source exclusion contains only `.github/workflows/agent-build-p5-r2e4.yml`.

No configure, build, relink, patch, regeneration, fixture modification, or source modification occurred during validation.

## Focused results

| Scope | Passed | Total | Disposition |
|---|---:|---:|---|
| Source-chart R1 | **11** | **11** | preserved |
| Phase 22 source validator | **6** | **6** | preserved |
| Recovery authority | **9** | **9** | preserved |
| Feature/barrier | **6** | **8** | regressed |
| Graph-dependent | **2** | **6** | regressed; bunny still independently fails |
| R2 focused, including R2E4 | **2** | **15** | blocked |
| Milestone D | **3** | **7** | regressed |
| Phase 14–18 | **215** | **243** | blocked |
| Phase 16 | **27** | **46** | blocked |
| Phase 17 | **18** | **26** | downstream blocked |
| Phase 18 | **57** | **57** | preserved |
| Phase 20 | **46** | **48** | unchanged |

The source-chart, source validator, recovery, and Phase 18 authorities remain intact. Feature/barrier and multiple previously closed R2 ownership/topology contracts regress because boundary arrangements now fail transactionally before publication.

## Complete suite

The complete suite was executed exactly once after focused scopes.

- discovered: **624**;
- passed: **575**;
- failed: **49**;
- disabled: **0**;
- GoogleTest runtime: **157.156 seconds**;
- normal XML completion: yes.

P5-TB31 was **595/623** with 28 failures. P5-TB32 adds one new test and introduces **21 new failures**, with **zero prior failures closed**.

The new failures are concentrated in:

- ordinary boundary incidence and topology publication;
- canonical ownership registry and face-row/orientation invariance contracts;
- bridge/support ownership that depends on valid boundary incidence;
- two additional Phase 17 consumers;
- two additional Milestone D contracts.

The exact 49-test failure list and the 21-test regression delta are recorded in `benchmark-results/p5-tb32-summary.json` and the evidence bundle.

A reliable complete-suite maximum RSS is unavailable. The outer execution wrapper detached while the single permitted complete-suite process continued to normal XML completion, so no trustworthy per-process peak or lower-bound sample survived. Focused and direct runs retain their individual `/usr/bin/time` evidence.

## Direct analytic cases

All direct cases used packaged fixtures, backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution.

| Case | Arrangement | Simplified | Completed quads | Result |
|---|---:|---:|---:|---|
| plane | 9 | 9 | 12 | fails completion output validation with 15 validation failures |
| multi-face seam | 0 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| close sheets | 0 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| cylinder | 0 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |

The plane result is unchanged from P5-TB31 and does not produce output. Seam, close sheets, and cylinder still publish zero arrangement cells. No disconnected-close-sheets direct case exists in the packaged manifest.

No fallback, source-grid recovery, input-mesh return, or legacy output was used.

## Earliest common producer

The earliest common defect is the treatment of a canonical rotational system with exactly two outgoing rays.

For `rayCount == 2`, the predecessor and successor positions of either ray are the same opposite ray. R2E4 tests both directions and interprets this mathematically equivalent two-ray cyclic adjacency as contradictory:

1. the opposite ray satisfies the predecessor check, selecting `rotationStep = -1`;
2. the same opposite ray also satisfies the successor check;
3. the second match is classified as `BoundaryRotationalSystemConflict`.

This rejects ordinary degree-two boundary vertices before successor publication. It explains the immediate typed failure on:

- the planar unit fixture;
- no-arc curved boundary meshes;
- interior-hard-rail fixtures before the hard-rail endpoint is reached;
- bridge, support, disconnected, close-sheet, ownership, face-row, and orientation contracts that contain ordinary boundary vertices.

The cylinder again clears publication and the independent audit observes `cell == -1`.

The two-ray case has two distinct **sectors**—one exterior and one interior—even though both sectors are bounded by the same unordered ray pair. Sector semantics must therefore come from the authoritative source-boundary side and incoming/outgoing relation, not from uniqueness of the neighboring ray ID.

## Required correction

P5-R2E5 must add an explicit degree-two boundary-sector construction:

- set the authoritative exterior incoming successor directly to the authoritative exterior outgoing;
- map the complementary incoming to the complementary outgoing as the interior sector;
- do not infer a unique `rotationStep` from predecessor-versus-successor ray identity when `rayCount == 2`;
- preserve the existing canonical node/fan separation and paired boundary incidence identity;
- retain the current adjacency construction for `rayCount >= 3`, with its local/global audits;
- leave repeated-edge/node, non-disk, owner, and Euler validators unchanged.

This is not a generic target swap. It is the exact two-sector rotational system induced by two directed rays and the authoritative exterior side.

## Next turn

Run **P5-R2E5 degree-two boundary rotational degeneracy Code + Build** following `.agents/Directional/Milestone_G_P5_R2E5_Degree_Two_Boundary_Rotation_Code_Build_Plan.md`.

Compile only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

Execute no project binary. Preserve all standing prohibitions and end the turn with a new final PR #8 handoff comment after all documentation commits.
