# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Tested source: `306fab5d440199cb090e1aa343fadb6112663edc`.
- Artifact: `8908691591`, `surface-cell-p5-r2-final-github-source-linux-release`.
- Artifact SHA-256: `7db07fc02a92ce08ce529e6f5175a961398c5a9708d4d6ad23dd7133e1407cec`.
- Completed turn: **P5-TB26 artifact-only R2 validation**.
- Next turn: **P5-R2C directed boundary-sector/cycle-inventory correction + compile-only build**.
- Do not advance to R3.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] R0 — recovery authority closed.
- [x] R1 orientation and adjacent-chart transitions — source-level authority closed.
- [x] R1 runtime — source charts **11/11**, validator **6/6**, recovery **9/9**, feature/barriers **8/8** remain clean in P5-TB26.
- [x] R2 compile — explicit wedges, one-to-one incidence audit, simple cycles before cell assignment.
- [ ] R2 valid cycle/cell inventory — P5-TB26 regresses valid boundary, disconnected, singularity, hard-rail, and periodic sectors.
- [ ] R2C — restore authoritative boundary-sector closure and complete cell assignment without post-hoc decomposition.
- [ ] R3 — topology-distinct patch completion engine.
- [ ] R4 — repeated-node wedge/splice producer.
- [ ] R5 — explicit local lattice phase and advancing-front state.
- [ ] R6 — torus decomposition/descriptor support.
- [ ] R7 — adaptive dyadic 2:1 transitions.
- [ ] R8 — direct analytic production validation.
- [ ] R9 — real completion-cache reuse after geometry succeeds.
- [ ] R10 — production-valid later-stage lineage fixtures.
- [ ] R11 — truthful synchronized memory telemetry.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-TB26 package authority

- exact source `306fab5d440199cb090e1aa343fadb6112663edc`;
- workflow event `b332bb3119a133b957b2f573a5bd447d4ca62d4e`;
- artifact `8908691591`, SHA-256 `7db07fc02a92ce08ce529e6f5175a961398c5a9708d4d6ad23dd7133e1407cec`;
- source status empty;
- recursive checksums **41/41**;
- package files **43**;
- fixtures **26**;
- recursive submodules **9**;
- no configure, rebuild, relink, patch, regeneration, or source modification.

## P5-TB26 runtime evidence

- source-chart R1 **11/11**;
- source validator **6/6**;
- recovery authority **9/9**;
- feature/barriers **8/8**;
- graph-dependent **5/6**;
- R2 focused **6/7**;
- Milestone D **4/7**;
- Phase 14–18 **227/240**;
- Phase 16 **39/43**;
- Phase 17 **18/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48**;
- complete suite **588/621**, terminated normally in **74.763 seconds**;
- exact maximum RSS unavailable.

Three bunny executions fall to approximately **23–24 seconds**, compared with **108–113 seconds** in P5-TB25. Failures regress **19 → 33**; faster early rejection is not correctness.

## Earliest remaining R2 producer

The implementation assigns cells only from the fully accepted `auditedCycles` inventory. Valid sectors are being rejected or omitted before cell publication:

- cylinder: `invalid-cell cell=-1 halfedge=0 twin=1 next=4`;
- planar fixture: Euler `-1`, area error `1`, no boundary cycle;
- disconnected fixture: zero interior cells;
- interior hard rail: two exterior cycles instead of one;
- bunny fan: zero center cells instead of three;
- seam, close sheets, and cylinder: zero arrangement cells and zero quads, then `SideSubdivisionRepair:InvalidInputIncidence`;
- eight Phase 17 contracts lose valid arrangement candidates.

Plane still reaches 12 quads with 15 later aggregate validation failures. Phase 18 is clean. Therefore R2 cycle/cell inventory remains earlier than R3 completion work.

## P5-R2C requirements

Follow `.agents/Directional/Milestone_G_P5_R2C_Directed_Boundary_Cycle_Code_Build_Plan.md`:

- [ ] separate successor/predecessor permutation validity from interior/exterior cycle class;
- [ ] represent source-boundary sectors explicitly and close their exterior successor relation;
- [ ] prevent interior hard rails from voting as source boundaries or creating extra exterior cycles;
- [ ] ensure every valid halfedge belongs to one audited cycle and receives one cell ID;
- [ ] preserve valid periodic seam closure across R1 transitions;
- [ ] restore planar, disconnected, non-disk/candidate, singularity-fan, seam, close-sheet, and cylinder inventories;
- [ ] retain typed rejection for genuinely nonmanifold, ambiguous, incomplete, repeated-node, and repeated-edge incidence;
- [ ] retain `directedIncidenceHash`, source-row/orientation invariance, R1 authority, and no post-hoc decomposition;
- [ ] keep R3–R11 deferred.

Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. Execute no project binary.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB26_Artifact_Only_R2_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb26-summary.json`
- `.agents/Directional/Milestone_G_P5_R2C_Directed_Boundary_Cycle_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_R2_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_R2_Test_Benchmark_Plan.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/DESIGN.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, post-hoc cycle decomposition, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
