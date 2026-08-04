# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open, draft, and unmerged.
- P5-TB27 tested source: `94b86c50c38a849a744f40b0a21c86ed19551769`.
- Tested artifact: `8912374007`, SHA-256 `ffe30c89655b60f5f7e90e509388c44b5a6c2c830508648348a4d01189ebb689`.
- Completed turn: **P5-TB27 artifact-only R2C validation**.
- Next turn: **P5-R2D authoritative orbit publication and structural cell classification + compile-only build**.
- R2 remains open; do not advance to R3.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery authority closed.
- [x] R1 — orientation and adjacent-chart transitions closed at source/validator authority.
- [x] R2 compile — typed directed incidence and permutation audit.
- [x] R2C compile — bridge/core orbit classification and transactional cell publication.
- [ ] R2 runtime — source admissibility, bounded-cell topology, exterior classification, and complete valid inventories remain open.
- [ ] R2D — authoritative orbit publication and structural cell classification.
- [ ] R3 — topology-distinct patch completion engine.
- [ ] R4 — repeated-node wedge/splice producer.
- [ ] R5 — explicit local lattice phase and advancing-front state.
- [ ] R6 — torus decomposition/descriptor support.
- [ ] R7 — adaptive dyadic 2:1 transitions.
- [ ] R8 — direct analytic production validation.
- [ ] R9 — completion-cache reuse after geometry succeeds.
- [ ] R10 — production-valid later-stage lineage fixtures.
- [ ] R11 — synchronized memory telemetry.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-TB27 package evidence

- exact compiled source `94b86c50c38a849a744f40b0a21c86ed19551769`;
- workflow event commit `69e7486ad59bdec64e95bd1c6a5c3ac0289bf244`;
- reviewed source patch SHA-256 `7ed8df0b92da7719395a50fb8f4d93485e163345d7f11c82c5866bd7adabf79a`;
- applied commit-diff SHA-256 `ddb5a8ae90ac227afd3ce5f1deccecfb8f676314d0638e7b295c49a390fc0ec3`;
- artifact `8912374007`, SHA-256 `ffe30c89655b60f5f7e90e509388c44b5a6c2c830508648348a4d01189ebb689`;
- workflow logs `8912374385`, SHA-256 `e1f4ccd6d218b6505f6e97d04eef9533d71adb987cbca7ad4daf1f7357a66d6f`;
- source status empty;
- recursive checksums **41/41**;
- package files **43**;
- fixture files **26**;
- recursive submodule records **9**;
- all four target hashes verified;
- no rebuild or source modification during validation.

## P5-TB27 results

| Scope | Result |
|---|---:|
| Source-chart R1 | **11/11** |
| Source validator | **6/6** |
| Recovery authority | **9/9** |
| Feature/barriers | **8/8** |
| Graph-dependent | **5/6** |
| R2/R2C focused | **7/10** |
| Milestone D | **5/7** |
| Phase 14–18 | **231/242** |
| Phase 16 | **41/45** |
| Phase 17 | **20/26** |
| Phase 18 | **57/57** |
| Phase 20 | **46/48** |
| Direct plane/seam/close sheets/cylinder | **0/4** |
| Complete suite | **593/623**, 161.786 s |

R2C improvements:

- both new bridge/support ownership contracts pass;
- branched-strand Milestone D contract passes;
- two Phase 17 bridge contracts return to passing;
- total suite failures decrease from 33 to 30 while two tests were added.

R2 remains open because:

- planar Euler is `-1` instead of `1`;
- nested bounded topology is not published as a two-boundary, Euler-zero non-disk cell;
- a three-face nonmanifold source edge incorrectly reports valid incidence;
- bunny singularity-fan embedding remains invalid;
- interior hard-rail and open-cylinder final topology remain invalid;
- seam, close sheets, and cylinder have zero arrangement cells and fail `InvalidInputIncidence`;
- six Phase 17 contracts remain without valid candidates/commits;
- total suite duration regresses 116.40% versus P5-TB26.

## P5-R2D requirements

Follow `.agents/Directional/Milestone_G_P5_R2D_Authoritative_Orbit_Publication_Code_Build_Plan.md`:

- [ ] reject nonmanifold source topology before accepting incidence;
- [ ] preserve complete successor/predecessor and R2C bridge/core audit;
- [ ] classify bounded topology and exterior ownership from exact source topology and audited core/bridge structure;
- [ ] derive boundary-component count and Euler characteristic rather than hard-code them;
- [ ] preserve support-only ownership while excluding it from area/Euler totals;
- [ ] transactionally assign every valid halfedge exactly one cell;
- [ ] restore planar, nested, hard-rail, singularity-fan, seam, close-sheet, and cylinder inventories;
- [ ] preserve deterministic hashes and R1 row/orientation invariance;
- [ ] compile only the four required targets and execute no binaries.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB27_Artifact_Only_R2C_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2D_Authoritative_Orbit_Publication_Code_Build_Plan.md`
- `benchmark-results/p5-tb27-summary.json`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/DESIGN.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
