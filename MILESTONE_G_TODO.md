# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Exact compiled source: `f4cce52006d21a248473e327ada1d66183af54e6`.
- Artifact: `8904835304`, `surface-cell-p5-r1c-github-source-linux-release`.
- Artifact SHA-256: `cf4d2532353d8f93848d01b51f9ee4d5ddbed0ff365e9acccab69688b3c4e2cc`.
- Completed turn: **P5-R1C code + compile-only build**.
- Next turn: **P5-TB24 artifact-only R1C validation**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] P5-TB22 — deterministic terminating baseline, **585/600**, production **0/8**.
- [x] P5-TB23 — identified inverted source-edge orientation and GP26 termination regression.
- [x] R0 compile — recovery defaults off with distinct `SourceGridRecovery` origin.
- [ ] R0 runtime — explicit planar recovery was preempted in P5-TB23.
- [x] R1 compile — canonical source-entity transition graph integrated.
- [x] R1C compile — shared-edge orientation predicate corrected and validator contracts packaged.
- [ ] R1 runtime — P5-TB24 must independently close orientation, fan, validator, recovery, analytic, and termination gates.
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

## P5-R1C package evidence

- P5-TB23 tested source `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- workflow event commit `f652e518152b2944b176464b2ea8cfd99d09ccda`;
- exact compiled source `f4cce52006d21a248473e327ada1d66183af54e6`;
- applied source-diff SHA-256 `b41f4a6ffc517d1547a6da777fe01fc55e18e0b09aad47db83843333f6bea99c`;
- successful run `30939748719`, job `92094837803`;
- artifact `8904835304`, SHA-256 `cf4d2532353d8f93848d01b51f9ee4d5ddbed0ff365e9acccab69688b3c4e2cc`;
- workflow logs `8904836090`, SHA-256 `c8ef21410b17971ff7a4d6366c5da5a4b8df157be7fab3068e4c4efa021d7db3`;
- source status empty;
- recursive checksum manifest **40/40**;
- package files **42**;
- fixture files **26**;
- recursive submodule records **9**;
- all **132/132** Ninja actions completed;
- compiled exactly four required targets;
- no project binary executed.

## R1C implementation

- [x] consistently oriented manifold faces with opposite shared-edge traversal are accepted;
- [x] equal-direction shared-edge traversal is rejected;
- [x] exact endpoint and barycentric transition semantics remain unchanged;
- [x] whole-mesh orientation reversal contract added;
- [x] existing invalid single-face reversal and row-permutation contracts preserved;
- [x] `SourceAuthoritativeMeshValidatorPhase22Tests.cpp` linked into `directional_phase1_tests`;
- [x] no validator weakening, positional fallback, recovery substitution, R2 work, or bunny-specific behavior.

## Last runtime evidence: P5-TB23

- focused R0/R1 **8/12**;
- focused recovery **8/9**;
- Phase 14–18 **233/242**;
- Phase20 **35/48**;
- bounded suite **553/603**;
- analytic plane/seam/close sheets **0/3**;
- full suite discovered 606 tests and timed out after 1200 seconds at `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback`.

No runtime improvement is claimed from R1C compile evidence.

## P5-TB24 requirements

Follow `.agents/Directional/Milestone_G_P5_R1C_Test_Benchmark_Plan.md`:

- [ ] verify exact package authority and source archive;
- [ ] pass all `SourceChartTransitionsR1.*` contracts;
- [ ] execute newly packaged `SourceAuthoritativeMeshValidatorPhase22.*` contracts;
- [ ] prove valid opposite traversal, invalid equal traversal, exact inverse maps, orientation reversal, and row-permutation stability;
- [ ] prove intrinsic fan barriers remain correct;
- [ ] validate explicit planar recovery and distinct `SourceGridRecovery` origin;
- [ ] close graph-dependent arrangement and completion-alias regressions;
- [ ] run Phase 14–18 and Phase 16 independently;
- [ ] run direct plane, seam, close sheets, and any packaged disconnected-close-sheet case;
- [ ] run affected and complete Phase 20 scopes;
- [ ] run the complete suite once and treat any watchdog expiration as failure;
- [ ] do not run the full direct bunny matrix solely for R1C.

Execute artifact `8904835304` directly. No configure, rebuild, relink, patch, regeneration, or source modification.

Advance to R2 only after R1 closes independently. When a later producer appears, record its earliest typed failure and demonstrate that source-chart orientation is no longer causal.

## Current authority

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Milestone_G_P5_TB23_Artifact_Only_R0_R1_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R1C_Source_Chart_Orientation_Correction_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_R1C_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_R1C_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r1c-summary.json`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
