# Milestone G Production Readiness TODO

Last updated: 2026-08-05  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open, draft, and unmerged.
- P5-TB31 tested source: `571ff9095ec06a8931fc54aafe1a70a38f80b4a1`.
- Tested artifact: `8918054686`, SHA-256 `6491eaaaa2276b0d89ddcda5f94d1b8e1e6cf6fe251b2b6ec99d242d8e29534d`.
- Completed turn: **P5-TB31 artifact-only R2E3 validation**.
- Next turn: **P5-R2E4 authoritative boundary-node rotational-system Code + Build**.
- R2 remains open; do not advance to R2F or R3.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery authority.
- [x] R1 — source transitions and validator authority.
- [x] R2C — bridge/core ownership narrow contracts.
- [x] R2D — nonmanifold preflight and multi-boundary representation.
- [x] R2E — source-side evidence and structural Euler accounting.
- [x] R2E2 — ordered boundary loops and exterior continuation.
- [x] R2E3 — canonical aliases, target bijection, and orientation identity; runtime still has wrong cyclic sector pairing.
- [ ] R2E4 — authoritative node-local rotational-system construction.
- [ ] R2F — intrinsic singularity-fan embedding after boundary closure.
- [ ] R3–R11 — later direct-paving remediation.
- [ ] P6–P8 — final validation and production disposition.

## P5-TB31 results

| Scope | Result |
|---|---:|
| Source-chart R1 | **11/11** |
| Source validator | **6/6** |
| Recovery authority | **9/9** |
| Feature/barrier | **8/8** |
| Graph-dependent | **5/6** |
| R2 focused | **11/14** |
| Milestone D | **5/7** |
| Phase 14–18 | **233/242** |
| Phase 16 | **43/45** |
| Phase 17 | **20/26** |
| Phase 18 | **57/57** |
| Phase 20 | **46/48** |
| Complete suite | **595/623**, 142.550 s |

R2E3 closes only `SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence`; no new failure appears.

## Earliest remaining producer

- planar: complete predecessor bijection but `RepeatedEdgeCycle` during orbit analysis;
- interior hard rail: `BoundaryLocalPermutationConflict` before orbit publication;
- cylinder: independent audit rejects bounded `NonDiskCell`;
- direct seam, close sheets, and cylinder: zero arrangement cells;
- bunny fan: independent embedding failure.

The two-target transposition preserves local cardinality but does not construct the authoritative cyclic rotational system. R2E4 must rebuild the entire affected node-local successor mapping directly from canonical ray/sector order.

## P5-R2E4 requirements

- [ ] canonical inventory of every incoming/outgoing ray per node and R1 fan;
- [ ] explicit exterior and interior boundary-sector identification;
- [ ] complete local successor reconstruction, not swaps or missing-target repair;
- [ ] hard rails partition interior sectors without splitting exterior continuation;
- [ ] pinched fans, close sheets, and components remain separate;
- [ ] typed fail-closed rotational-system evidence;
- [ ] one local and one global bijection audit before commit;
- [ ] preserve paired boundary-twin identity and orientation hash closure;
- [ ] keep repeated-edge, non-disk, owner, and Euler validators unchanged;
- [ ] close planar, hard-rail, and cylinder naturally;
- [ ] compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- [ ] execute no project binary.

## Standing requirements

Every completed Code + Build, Test + Benchmark, and optional Review turn must end with a new final PR #8 comment containing the concise handoff summary after all documentation commits. Code + Build turns must remove bounded workflows and payloads after artifact upload.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB31_Artifact_Only_R2E3_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E4_Boundary_Node_Rotation_Code_Build_Plan.md`
- `benchmark-results/p5-tb31-summary.json`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
