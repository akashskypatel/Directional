# Milestone G Production Readiness TODO

Last updated: 2026-08-05  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open, draft, and unmerged.
- P5-TB32 tested source: `ec44ab7570f258f800a27086fca053c573878a13`.
- Tested artifact: `8929111021`, SHA-256 `dcb3dcca095a62efde3bc534a8eafca1a5a3976f3e98b649845c6ca47c682450`.
- Completed turn: **P5-TB32 artifact-only R2E4 validation**.
- Next turn: **P5-R2E5 degree-two boundary rotational degeneracy Code + Build**.
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
- [x] R2E3 — canonical aliases, target bijection, and orientation identity.
- [x] R2E4 compile — authoritative local rotational construction.
- [ ] R2E4 runtime — invalid at degree-two boundary nodes.
- [ ] R2E5 — explicit degree-two exterior/interior sector construction.
- [ ] R2F — intrinsic singularity-fan embedding after boundary closure.
- [ ] R3–R11 — later direct-paving remediation.
- [ ] P6–P8 — final validation and production disposition.

## P5-TB32 results

| Scope | Result |
|---|---:|
| Source-chart R1 | **11/11** |
| Source validator | **6/6** |
| Recovery authority | **9/9** |
| Feature/barrier | **6/8** |
| Graph-dependent | **2/6** |
| R2 focused | **2/15** |
| Milestone D | **3/7** |
| Phase 14–18 | **215/243** |
| Phase 16 | **27/46** |
| Phase 17 | **18/26** |
| Phase 18 | **57/57** |
| Phase 20 | **46/48** |
| Complete suite | **575/624**, 157.156 s |

P5-TB32 introduces 21 failures relative to P5-TB31 and closes none.

## Earliest producer

At `rayCount == 2`, predecessor and successor positions both identify the same opposite ray. R2E4 treats the equivalent cyclic directions as contradictory and emits `BoundaryRotationalSystemConflict`.

Consequences:

- planar and no-arc curved boundary meshes fail before successor publication;
- hard-rail tests fail at ordinary boundary nodes before reaching the intended high-valence endpoint;
- bridge, support, ownership, disconnected, close-sheet, face-row, and orientation contracts regress transactionally;
- cylinder publication clears and leaves `cell == -1`;
- direct seam, close sheets, and cylinder retain zero arrangement cells.

## P5-R2E5 requirements

- [ ] explicitly construct the two-ray exterior and interior sectors;
- [ ] require the local ray inventory to equal `{exteriorTwin, exteriorOutgoing}`;
- [ ] map `exteriorIncoming -> exteriorOutgoing`;
- [ ] map `twin(exteriorOutgoing) -> exteriorTwin`;
- [ ] require endpoint continuity and exact local target cardinality;
- [ ] assign loop identity only to the exterior sector and canonical rotation identity to the interior sector;
- [ ] preserve the `rayCount >= 3` canonical adjacent-ray branch;
- [ ] restore all 21 regressions before claiming progress;
- [ ] preserve source-row/orientation identity hashing and all prior R2 authority;
- [ ] leave orbit, disk, owner, Euler, FlowRep, simplification, completion, fallback, and recovery validators unchanged;
- [ ] compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- [ ] execute no project binary.

## Standing requirements

Every completed Code + Build, Test + Benchmark, and optional Review turn must end with a new final PR #8 comment containing the concise handoff summary after all documentation commits. Code + Build turns must remove bounded workflows and payloads after artifact upload.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB32_Artifact_Only_R2E4_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E5_Degree_Two_Boundary_Rotation_Code_Build_Plan.md`
- `benchmark-results/p5-tb32-summary.json`
- `.agents/Directional/Milestone_G_P5_R2E4_Code_Build_Report.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

P5 remains open. PR #8 remains draft and unmerged.
