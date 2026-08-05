# Milestone G Production Readiness TODO

Last updated: 2026-08-05

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **P5-R2E7 cyclic fan-sector cover and directed hard-rail side Code + Build**.
- Next turn: **P5-TB35 artifact-only R2E7 validation**.
- R2 runtime remains open. Do not advance to R2F or R3 from compilation.

## P5-R2E7 compiled checkpoint

- Starting documentation head: `7c46b888ff9336a9a83d26097c41b50c3e770a8f`.
- Workflow event: `7d5450cb6411722818844548de59a09c8f4451d5`.
- Exact compiled source: `31c8d9a212f649df7c70fe9291d1fac8c4db7132`.
- Workflow cleanup: `a95d2531f87833373bfde92b5d697185f9c71687`.
- Reviewed/applied diff SHA-256: `711286a519d39c18b074caae3b999ec15a7202a9b9454e0eb04a8eb642cc2745`.
- Artifact: `8938299309`, SHA-256 `af34097d6579ff07eafbe24e75ed05db3dfec98170ef7576ce30a12b538f063e`.
- Workflow logs: `8938299624`, SHA-256 `a4c1dee2951ab2f374b86fca6767ebf17835797fdf4a9a8ac26d9771fc54331c`.
- Empty source status; manifest **48/48**; package files **49**; fixtures **26**; recursive submodules **9**.
- Four target hashes verified; Ninja **132/132**; compile exit code **0**.
- Compiled only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`.
- Executed zero tests, benchmarks, project binaries, custom meshes, or discovery commands.

## R2E7 implementation

- [x] exact R2E5 degree-two mapping preserved;
- [x] genuine R2E6 four-disk higher-valence authority preserved;
- [x] R1 fan adjacency treated cyclically, including vector wrap;
- [x] only the independently proven exterior adjacency excluded;
- [x] accepted cyclic-wrap interior sectors tracked after successful audit;
- [x] hard-rail sides derived from separator witness orientation and cyclic adjacency;
- [x] opposite rail sides require distinct authoritative fan identities;
- [x] directed rail-side order and local owner/target cardinality re-audited transactionally;
- [x] typed `BoundaryFanSectorCoverConflict` retained for malformed evidence;
- [x] planar and hard-rail contracts strengthened;
- [x] Phase 17 left unchanged;
- [x] global predecessor, repeated-cycle, disk, ownership, Euler, boundary-loop, orientation, and area validators unchanged.

## Required next work: P5-TB35

Follow `.agents/Directional/Milestone_G_P5_R2E7_Test_Benchmark_Plan.md`:

- [ ] verify exact artifact/source/package authority before runtime;
- [ ] preserve source-chart **11/11**, validator **6/6**, recovery **9/9**, feature/barrier **8/8**, graph-dependent **5/6**, and Phase 18 **57/57**;
- [ ] preserve the degree-two and genuine four-disk contracts;
- [ ] restore the planar cyclic-wrap producer to at least its P5-TB33 Euler diagnostic position, preferably full closure;
- [ ] restore all six P5-TB34 Phase 17 regressions naturally and require Phase 17 **26/26**;
- [ ] require directed hard-rail side-pair evidence and one exterior plus two bounded disks;
- [ ] require R2 focused at least **14/16** and Milestone D at least **6/7**;
- [ ] run Phase 20 and the complete suite exactly once;
- [ ] diagnose remaining planar, cylinder, and bunny producers independently.

## Standing process requirements

- Remove stale workflows, triggers, patch payloads, transfer files, and temporary artifacts at every Code + Build turn start and end.
- Every completed turn ends with a new final PR #8 comment containing the handoff summary after all documentation commits.

## Current authority

- `.agents/Directional/Milestone_G_P5_R2E7_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E7_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r2e7-summary.json`
- `.agents/Directional/Milestone_G_P5_TB34_Artifact_Only_R2E6_Test_Benchmark_Report.md`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `TODO`

P5 remains open.
