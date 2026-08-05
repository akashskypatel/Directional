# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open, draft, and unmerged.
- P5-TB30 tested source: `f5305ade5bf5360df36b681d135e5299322f5fdb`.
- Tested artifact: `8916209271`, SHA-256 `2117cc2b99bc82a197bb7ee94f3e21a9c8f71b48f735c15c878515dabd4915df`.
- Completed turn: **P5-TB30 artifact-only R2E2 validation**.
- Next turn: **P5-R2E3 boundary-node permutation splice + compile-only build**.
- R2 remains open; do not advance to R2F or R3.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery authority.
- [x] R1 — source transitions and validator authority.
- [x] R2C — bridge/core ownership narrow contracts.
- [x] R2D — nonmanifold preflight and multi-boundary representation.
- [x] R2E — source-side evidence and structural Euler accounting compiled.
- [ ] R2E2 — ordered boundary loops execute but boundary permutation remains invalid.
- [ ] R2E3 — complete boundary-node exterior/interior permutation splice and orientation identity.
- [ ] R2F — intrinsic singularity-fan embedding after boundary closure.
- [ ] R3–R11 — later direct-paving remediation.
- [ ] P6–P8 — final validation and production disposition.

## P5-TB30 results

| Scope | Result |
|---|---:|
| Source-chart R1 | **11/11** |
| Source validator | **6/6** |
| Recovery authority | **9/9** |
| Feature/barrier | **8/8** |
| Graph-dependent | **5/6** |
| R2 focused | **10/14** |
| Milestone D | **5/7** |
| Phase 14–18 | **232/242** |
| Phase 16 | **42/45** |
| Phase 17 | **20/26** |
| Phase 18 | **57/57** |
| Phase 20 | **46/48** |
| Complete suite | **594/623**, 77.761 s |

P5-TB30 has 29 failures: the same 28 as P5-TB29 plus `SurfaceArrangementPhase16.WholeMeshOrientationReversalPreservesDirectedIncidence`.

## R2E2 evidence

- [x] artifact authority and manifest **48/48**;
- [x] R0/R1 authority preserved;
- [x] nonmanifold, nested multi-boundary, bridge, support-only, and close-sheet narrow contracts preserved;
- [ ] planar disk fails `IncompletePermutation`;
- [ ] interior hard rail fails `BoundaryContinuationDiscontinuity`;
- [ ] cylinder clears publication and leaves invalid cell ownership;
- [ ] whole-orientation directed-incidence hash regressed;
- [ ] seam, close sheets, and cylinder publish zero arrangement cells;
- [ ] structural Euler runtime authority remains blocked;
- [ ] bunny singularity fan remains independently invalid.

## P5-R2E3 requirements

- [ ] create a transactional complete candidate successor array;
- [ ] construct canonical boundary-vertex classes across hard-rail fan scopes while preserving components, close sheets, and pinched fans;
- [ ] build exterior and complementary interior local successor partitions together;
- [ ] require exact local incoming/outgoing bijection and endpoint continuity;
- [ ] derive boundary subsegment orientation from canonical edge parameters, not directed provenance sign;
- [ ] run one global successor/predecessor/orbit audit before cell publication;
- [ ] restore orientation-invariant boundary twin hashing;
- [ ] close planar, hard-rail, and cylinder topology naturally;
- [ ] preserve every passing R2C/R2D/R2E contract and Phase 18;
- [ ] do not patch Phase 15, Phase 17, completion, fallback, or bunny fan in this turn;
- [ ] remove stale workflows and payloads before and after build;
- [ ] compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- [ ] execute no project binary.

## Standing requirements

Every completed Code + Build, Test + Benchmark, and optional Review turn must end with a new final PR #8 comment containing the concise handoff summary after all documentation commits.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB30_Artifact_Only_R2E2_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E3_Boundary_Node_Permutation_Code_Build_Plan.md`
- `benchmark-results/p5-tb30-summary.json`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
