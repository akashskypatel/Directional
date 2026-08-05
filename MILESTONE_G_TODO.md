# Milestone G Production Readiness TODO

Last updated: 2026-08-05  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open, draft, and unmerged.
- Exact compiled source: `1eb9dc766bc6db74bd2c1ea4ced9c3cbeaae133b`.
- Artifact: `8934315316`, SHA-256 `69436143d96749cc09c6da8dc8c301e63304c2d25f9252497d0e9d0259c46c5c`.
- Completed turn: **P5-R2E5 Code + Build**.
- Next turn: **P5-TB33 artifact-only R2E5 validation**.
- R2 runtime remains open; do not advance to R2F or R3 from compile evidence.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery authority.
- [x] R1 — source transitions and validator authority.
- [x] R2C — bridge/core ownership narrow contracts.
- [x] R2D — nonmanifold preflight and multi-boundary representation.
- [x] R2E — source-side evidence and structural Euler accounting.
- [x] R2E2 — ordered boundary loops and exterior continuation.
- [x] R2E3 — canonical aliases, target bijection, and orientation identity.
- [x] R2E4 — canonical higher-valence rotational construction; runtime exposed degree-two degeneracy.
- [x] R2E5 compile — explicit two-ray exterior/interior sector construction.
- [ ] R2E5 runtime — P5-TB33 must restore every P5-TB32 regression before further advancement.
- [ ] R2F — intrinsic singularity-fan embedding after boundary closure.
- [ ] R3–R11 — later direct-paving remediation.
- [ ] P6–P8 — final validation and production disposition.

## P5-R2E5 evidence

- starting documentation head `e8f6c3f1641db916c53fc9dc938d0bc5d648a019`;
- workflow event `15704d30fc478858284df89d372fa713f2d88576`;
- exact compiled source `1eb9dc766bc6db74bd2c1ea4ced9c3cbeaae133b`;
- workflow cleanup `790714bbe8dffd1efbe7860093027daf3e0e8d54`;
- reviewed/applied diff SHA-256 `b7648b0bf870d7a65a7715a11e58cc2e8258af0118826c843d013384d485cc29`;
- successful run/job `31014985061` / `92336594420`;
- artifact `8934315316`, SHA-256 `69436143d96749cc09c6da8dc8c301e63304c2d25f9252497d0e9d0259c46c5c`;
- workflow logs `8934315771`, SHA-256 `3681d6b81d1251f3de17a5e004ddce42d3b204d636481ded4a390754ae4ebf34`;
- source status empty; manifest **48/48**; files **49**; fixtures **26**; submodules **9**;
- four target hashes verified; Ninja **132/132**; zero project binaries executed.

## R2E5 implementation

- [x] identifies the degree-two degeneracy by exact two-ray local inventory;
- [x] requires `{exteriorTwin, exteriorOutgoing}` and valid reciprocal twins;
- [x] maps the exterior incoming to exact source-loop continuation;
- [x] maps the complementary incoming to the complementary outgoing;
- [x] requires distinct incoming ownership, endpoint continuity, and target bijection;
- [x] separates exterior loop identity from interior canonical rotation identity;
- [x] adds derived `boundaryDegreeTwoRotationalNodeCount`;
- [x] preserves the `rayCount >= 3` canonical adjacent-ray branch;
- [x] retains typed fail-closed rotational conflict evidence for genuinely invalid inputs;
- [x] preserves canonical aliases, paired incidence hashing, repeated-edge/node, disk, owner, and Euler validation;
- [x] adds a generalized boundary-only two-sector disk contract and strengthens existing topology contracts.

## P5-TB33 requirements

- [ ] verify artifact authority and target hashes;
- [ ] restore all 21 failures introduced by P5-R2E4 before claiming progress;
- [ ] require source-chart **11/11**, validator **6/6**, recovery **9/9**, feature/barrier **8/8**, and Phase 18 **57/57**;
- [ ] require graph-dependent **5/6**, with only bunny allowed;
- [ ] require exact two-sector mapping, target cardinality, identity, and malformed-evidence contracts;
- [ ] preserve higher-valence rotational construction independently;
- [ ] preserve source-row and orientation incidence hashes;
- [ ] require Phase 16 at least **45/47**, Phase 17 at least **20/26**, and Phase 20 **46/48**;
- [ ] require the complete suite at least **597/625**, with no failure absent from the P5-TB31 failure set;
- [ ] preserve plane inventory and do not regress seam, close-sheet, or cylinder direct cases;
- [ ] after regression restoration, classify remaining planar, hard-rail, cylinder, and bunny producers independently.

## Standing requirements

Every completed Code + Build, Test + Benchmark, and optional Review turn must end with a new final PR #8 comment containing the concise handoff summary after all documentation commits. Code + Build turns must remove bounded workflows and payloads after artifact upload.

## Current authority

- `.agents/Directional/Milestone_G_P5_R2E5_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E5_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r2e5-summary.json`
- `.agents/Directional/Milestone_G_P5_TB32_Artifact_Only_R2E4_Test_Benchmark_Report.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
