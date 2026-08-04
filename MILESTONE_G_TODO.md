# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Tested source: `f4cce52006d21a248473e327ada1d66183af54e6`.
- Artifact: `8904835304`, `surface-cell-p5-r1c-github-source-linux-release`.
- Artifact SHA-256: `cf4d2532353d8f93848d01b51f9ee4d5ddbed0ff365e9acccab69688b3c4e2cc`.
- Completed turn: **P5-TB24 artifact-only R1C validation**.
- Next turn: **P5-R1D adjacent local-sheet exact-adjacency correction + compile-only build**.
- Do not advance to R2.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] P5-TB22 — deterministic terminating baseline, **585/600**, production **0/8**.
- [x] P5-TB23 — identified inverted source-edge orientation and GP26 termination regression.
- [x] R0 compile and runtime — recovery defaults off, explicit recovery reports `SourceGridRecovery`, focused authority **9/9**.
- [x] R1 orientation predicate — valid opposite traversal accepted; invalid equal traversal rejected; focused orientation **7/7**.
- [x] Packaged Phase 22 validator authority — **6/6**.
- [ ] R1 exact adjacent-local-sheet reconciliation — transition graph still splits valid adjacency by local-sheet inequality.
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

## P5-TB24 package authority

- source status empty;
- recursive checksums **40/40**;
- package files **42**;
- fixture files **26**;
- recursive submodule records **9**;
- all four built-target hashes verified;
- source archive contains the corrected orientation predicate, orientation-reversal contract, and packaged Phase 22 validator source;
- no configure, build, relink, patch, regeneration, or source modification.

## P5-TB24 runtime evidence

- source-chart orientation **7/7**;
- source-authoritative validator **6/6**;
- focused recovery **9/9**;
- graph-dependent focused **3/6**;
- Phase 14–18 **240/243**;
- Phase 16 **37/39**;
- Phase 20 **46/48**;
- analytic direct plane/seam/close sheets **0/3**;
- complete suite **590/613**, terminated normally in **75.260 seconds**;
- maximum resident set **256,544 KiB**;
- GP26/GP27 bunny cases no longer stall.

Direct analytic validation counts improved from P5-TB23:

- plane **27 → 15**;
- multi-face seam **46 → 22**;
- close sheets **61 → 27**.

All analytic cases still fail `NotProductionReady/completion` with output origin `None`. No recovery, fallback, or legacy output executed.

## Earliest remaining R1 producer

`SourceChartTransitionGraph::build()` requires both equal source-component and equal local-sheet labels before admitting an exact manifold edge transition.

The local-sheet equality condition conflicts with established exact-adjacency contracts. It preempts:

- boundary source-vertex/source-edge completion aliases;
- adjacent Phase 16 canonical ownership;
- bunny intrinsic source-vertex fan rotation;
- feature-rail vertices supporting both incident local sheets.

Required distinction:

```text
local sheet remains authoritative provenance and blocks proximity capture/projection;
exact manifold adjacency inside one component may cross local-sheet labels;
hard rails, source boundaries, nonmanifold incidence, components, and disconnection remain barriers.
```

## P5-R1D requirements

Follow `.agents/Directional/Milestone_G_P5_R1D_Adjacent_Local_Sheet_Code_Build_Plan.md`:

- [ ] admit exact opposite-winding manifold transitions across different local-sheet labels within one component;
- [ ] preserve local-sheet labels in chart IDs, membership identities, provenance, diagnostics, and hashes;
- [ ] preserve component, hard-rail, boundary, nonmanifold, and disconnected-topology barriers;
- [ ] restore intrinsic source-vertex fans across admissible adjacent local charts;
- [ ] retain same-sheet safety for proximity-based reconciliation and projection;
- [ ] correct only immediate R1 consumers that still contradict exact adjacency;
- [ ] add focused transition, fan, completion-alias, feature-rail, ownership, and barrier tests;
- [ ] keep R2–R11 deferred.

Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. Execute no project binary.

## Current authority

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Milestone_G_P5_TB24_Artifact_Only_R1C_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb24-summary.json`
- `.agents/Directional/Milestone_G_P5_R1D_Adjacent_Local_Sheet_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_R1C_Code_Build_Report.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
