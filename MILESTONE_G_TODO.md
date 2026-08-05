# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open, draft, and unmerged.
- Exact compiled source: `571ff9095ec06a8931fc54aafe1a70a38f80b4a1`.
- Artifact: `8918054686`, SHA-256 `6491eaaaa2276b0d89ddcda5f94d1b8e1e6cf6fe251b2b6ec99d242d8e29534d`.
- Completed turn: **P5-R2E3 Code + Build**.
- Next turn: **P5-TB31 artifact-only R2E3 validation**.
- R2 runtime remains open; do not advance to R2F or R3 from compile evidence.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery authority.
- [x] R1 — source transitions and validator authority.
- [x] R2C — bridge/core ownership narrow contracts.
- [x] R2D — nonmanifold preflight and multi-boundary representation.
- [x] R2E — source-side evidence and structural Euler accounting compiled.
- [x] R2E2 — ordered boundary loops and exterior continuation compiled; runtime exposed incomplete permutation.
- [x] R2E3 compile — complete boundary-node permutation splice and orientation identity.
- [ ] R2E3 runtime — P5-TB31 must close boundary/permutation gates.
- [ ] R2F — intrinsic singularity-fan embedding after boundary closure.
- [ ] R3–R11 — later direct-paving remediation.
- [ ] P6–P8 — final validation and production disposition.

## P5-R2E3 evidence

- starting documentation head `31b17ff6abb4965e5d506c35b38ca772d7591a5b`;
- workflow event `2d1d616eaf6e5be025e1a190b995172954d3f102`;
- exact compiled source `571ff9095ec06a8931fc54aafe1a70a38f80b4a1`;
- workflow cleanup `3d805eca6f1dfbc857c023a6f509d9310e9577dc`;
- reviewed/applied diff SHA-256 `f7a26c3b3869a59247532e86f4468e0d17bce7caa72cf31a5c315b620fac1ff3`;
- successful run/job `30975049986` / `92207228399`;
- artifact `8918054686`, SHA-256 `6491eaaaa2276b0d89ddcda5f94d1b8e1e6cf6fe251b2b6ec99d242d8e29534d`;
- workflow logs `8918054984`, SHA-256 `01578b07c754dd3eef0fc1aa63272b4fe5934565ddf0e48647ed3bf50aff7007`;
- source status empty; manifest **48/48**; files **49**; fixtures **26**; submodules **9**;
- four target hashes verified; Ninja **132/132**; zero project binaries executed.

## R2E3 implementation

- [x] separate transactional `candidateNext` map;
- [x] canonical boundary-node classes preserve component and R1 fan separation;
- [x] hard-rail chart aliases share one authoritative boundary node;
- [x] pinched fans and close sheets remain distinct;
- [x] typed alias and local-permutation failures;
- [x] canonical edge-parameter subsegment identity;
- [x] complete exterior/interior node-local successor bijection;
- [x] one global candidate permutation audit before commit;
- [x] canonical paired boundary-twin incidence hashing;
- [x] generalized contracts compiled but not executed.

## P5-TB31 requirements

- [ ] verify artifact authority and target hashes;
- [ ] preserve R0/R1 authority and all prior R2C/R2D/R2E closures;
- [ ] require one canonical node per manifold boundary vertex/fan and preserve pinched/close separation;
- [ ] pass node-local incoming/outgoing bijection and endpoint-continuity contracts;
- [ ] pass typed alias and local-permutation rejection contracts;
- [ ] restore whole-orientation incidence-hash equality;
- [ ] close planar area/Euler/topology;
- [ ] close hard-rail exterior continuation and bounded partition;
- [ ] close cylinder two-loop ownership, Euler zero, and all cell IDs;
- [ ] require R2 focused at least **13/14**, Milestone D **7/7**, and Phase 16 at least **44/45**;
- [ ] preserve Phase 18 **57/57**;
- [ ] require nonzero seam, close-sheet, and cylinder arrangement inventories;
- [ ] run Phase 20 and the complete suite once with runtime and memory evidence.

## Standing requirements

Every completed Code + Build, Test + Benchmark, and optional Review turn must end with a new final PR #8 comment containing the concise handoff summary after all documentation commits. Code + Build turns must also remove bounded workflows and payloads after artifact upload.

## Current authority

- `.agents/Directional/Milestone_G_P5_R2E3_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E3_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r2e3-summary.json`
- `.agents/Directional/Milestone_G_P5_TB30_Artifact_Only_R2E2_Test_Benchmark_Report.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
