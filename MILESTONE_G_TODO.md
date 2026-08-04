# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Tested source: `e31e5abd52ca9e673d1718f47d088d19296d1d22`.
- Artifact: `8902050372`, `surface-cell-p5-r1-github-source-linux-release`.
- Artifact SHA-256: `5d1e5ca4fa8bc74e0a30615725c79a8b491830ab1f4407152cf79bfe56f8880f`.
- Completed turn: **P5-TB23 artifact-only R0/R1 validation**.
- Next turn: **P5-R1C source-chart orientation correction + compile-only build**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] P5-TB22 — deterministic runtime baseline, **585/600**, production **0/8**.
- [x] R0 compile — recovery defaults off and has distinct `SourceGridRecovery` origin.
- [ ] R0 runtime — **8/9** focused recovery contracts; explicit planar recovery remains preempted.
- [x] R1 compile — canonical source-entity transition graph integrated.
- [ ] R1 runtime — orientation predicate is inverted; remain on R1.
- [ ] R1C — correct shared-edge winding classification and restore graph-dependent behavior.
- [ ] R2 — directed wedge/incidence reconstruction before cell assignment.
- [ ] R3 — topology-distinct patch completion engine.
- [ ] R4 — repeated-node wedge/splice producer.
- [ ] R5 — explicit local lattice phase and advancing-front event state.
- [ ] R6 — torus decomposition/descriptor support.
- [ ] R7 — adaptive dyadic 2:1 transitions.
- [ ] R8 — direct analytic production validation.
- [ ] R9 — real completion-cache reuse after geometry succeeds.
- [ ] R10 — production-valid later-stage lineage fixtures after geometry succeeds.
- [ ] R11 — truthful synchronized memory telemetry after geometry succeeds.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-TB23 package authority

- source status empty;
- recursive checksums **41/41**;
- package files **43**;
- fixture files **26**;
- recursive submodules **9**;
- exact target hashes verified;
- no configure, build, relink, patch, regeneration, or source modification.

## P5-TB23 runtime evidence

- focused R0/R1 **8/12**;
- focused recovery **8/9**;
- Phase 14–18 **233/242**;
- Phase20 **35/48**;
- bounded diagnostic suite **553/603** in 4.943 seconds;
- complete suite: 606 tests discovered, did not terminate within 1200 seconds;
- stall: `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`, case `bunny_1k_random__surface_cells`;
- analytic direct production plane/seam/close sheets **0/3**.

Direct analytic failures:

- plane: 12 quads, 27 validation failures, `LocalSheetMismatch` at 0/0;
- multi-face seam: 24 quads, 46 validation failures, `LocalSheetMismatch` at 0/0;
- close sheets: 34 quads, 61 validation failures, `LocalSheetMismatch` at 0/0;
- recovery/fallback/legacy execution: none.

## Earliest R1 producer

`SourceChartTransitionGraph::edge_orientation` accepts equal-direction shared-edge traversal and rejects the opposite traversal required by a consistently oriented manifold triangle pair.

Consequences observed:

- valid transition graph unavailable;
- exact shared-edge rebind fails;
- source-vertex fan resolution fails;
- invalid same-direction winding test is accepted;
- graph-dependent arrangement ownership and completion alias contracts fail;
- explicit planar recovery fails strict validation;
- analytic `LocalSheetMismatch` counts increase;
- full-suite termination regresses.

## P5-R1C requirements

Follow `.agents/Directional/Milestone_G_P5_R1C_Source_Chart_Orientation_Correction_Code_Build_Plan.md`:

- [ ] fix the orientation predicate, not the tests;
- [ ] preserve exact endpoint/barycentric inverse maps;
- [ ] preserve deterministic face-row and whole-mesh orientation invariance;
- [ ] restore admissible source-vertex fan adjacency and hard-rail/nonmanifold barriers;
- [ ] repair only graph-dependent arrangement, completion alias, validator, and explicit recovery behavior that remains invalid after the predicate fix;
- [ ] include `SourceAuthoritativeMeshValidatorPhase22Tests.cpp` in `directional_phase1_tests` so the four-target artifact exposes validator contracts;
- [ ] keep R2–R11 deferred.

Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`; execute no project binary.

## Current authority

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Milestone_G_P5_TB23_Artifact_Only_R0_R1_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb23-summary.json`
- `.agents/Directional/Milestone_G_P5_R1C_Source_Chart_Orientation_Correction_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_R0_R1_Code_Build_Report.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
