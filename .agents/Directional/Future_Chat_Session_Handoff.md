# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R1C code changes and the exact four-target compile/package gate are complete. Runtime acceptance has not been executed for this source. Remain on R1 until P5-TB24 is authoritative.

Compiled checkpoint:

- P5-TB23 tested source `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- workflow event commit `f652e518152b2944b176464b2ea8cfd99d09ccda`;
- R1C implementation and exact compiled source `f4cce52006d21a248473e327ada1d66183af54e6`;
- applied source-diff SHA-256 `b41f4a6ffc517d1547a6da777fe01fc55e18e0b09aad47db83843333f6bea99c`;
- successful run `30939748719`, job `92094837803`;
- artifact `8904835304`, `surface-cell-p5-r1c-github-source-linux-release`;
- artifact SHA-256 `cf4d2532353d8f93848d01b51f9ee4d5ddbed0ff365e9acccab69688b3c4e2cc`;
- workflow-log artifact `8904836090`, SHA-256 `c8ef21410b17971ff7a4d6366c5da5a4b8df157be7fab3068e4c4efa021d7db3`;
- empty source status;
- recursive checksums **40/40**;
- package files **42**;
- fixtures **26**;
- recursive submodules **9**;
- all **132/132** Ninja actions complete.

The build compiled exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`. No project binary executed.

The next turn is **P5-TB24 artifact-only R1C validation**. Execute artifact `8904835304` directly. Do not configure, rebuild, relink, patch, regenerate, or modify source.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_R1C_Code_Build_Report.md`
4. `.agents/Directional/Milestone_G_P5_R1C_Test_Benchmark_Plan.md`
5. `benchmark-results/p5-r1c-summary.json`
6. `.agents/Directional/Milestone_G_P5_TB23_Artifact_Only_R0_R1_Test_Benchmark_Report.md`
7. `.agents/Directional/Milestone_G_P5_R1C_Source_Chart_Orientation_Correction_Code_Build_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB23 runtime authority

- focused R0/R1 **8/12**;
- focused recovery **8/9**;
- Phase 14–18 **233/242**;
- Phase20 **35/48**;
- bounded suite **553/603**;
- analytic direct plane/seam/close sheets **0/3**;
- complete suite discovered 606 tests and timed out after 1200 seconds at the GP26 bunny case.

The earliest cause was an inverted source-edge winding predicate: valid opposite traversal was rejected and invalid equal traversal was accepted.

## P5-R1C implementation

1. Corrected `SourceChartTransitionGraph::edge_orientation`:
   - opposite incident traversal is accepted;
   - equal incident traversal is rejected.
2. Preserved canonical endpoint and barycentric transition maps.
3. Added `SourceChartTransitionsR1.WholeMeshOrientationReversalPreservesCanonicalTransitions`.
4. Preserved the existing invalid single-face reversal and face-row permutation contracts.
5. Added `tests/SourceAuthoritativeMeshValidatorPhase22Tests.cpp` to `directional_phase1_tests` so the packaged artifact exposes the requested validator tests.
6. Added no R2 work, new recovery behavior, completion search, validator weakening, positional fallback, or bunny-specific condition.

Three preliminary workflow attempts failed before source modification because staged patch payload transport changed the checked bytes. The successful workflow used exact single-occurrence source transformations and hashed the resulting diff. Do not repeat the transport-payload approach.

## P5-TB24 execution order

1. Verify artifact SHA, source commit, empty status, **40/40** checksums, 42 files, 26 fixtures, nine submodules, source contents, and target hashes.
2. Run all `SourceChartTransitionsR1.*` tests.
3. Run all packaged `SourceAuthoritativeMeshValidatorPhase22.*` tests.
4. Run focused default-off recovery, explicit recovery, fallback `Fail`, and output-origin contracts.
5. Run graph-dependent arrangement ownership, singularity-fan, curved multi-face, and completion-alias contracts.
6. Run Phase 14–18 aggregate and Phase 16 independently.
7. Run plane, multi-face seam, close sheets, and any packaged disconnected-close-sheet direct entry with fallback `Fail` and recovery disabled.
8. Run affected and complete Phase 20 scopes.
9. Run the complete suite once with a watchdog used only as a safety mechanism.
10. Do not run the full direct bunny benchmark matrix solely for R1C.

## Decision rule

Advance to R2 only when:

- all source-chart orientation contracts pass;
- packaged Phase 22 validator contracts behave as intended;
- explicit recovery authority passes;
- graph-dependent Phase 14–18 regressions close;
- analytic cases are no longer blocked by valid winding rejection;
- the complete suite terminates.

A later analytic failure may justify an R2 plan only after evidence shows that source-chart orientation and fan construction are no longer causal. Otherwise remain on R1 and make the smallest producer correction.

## Subsequent authoritative order

1. R2 — directed wedge/incidence reconstruction;
2. R3 — topology-distinct patch completion;
3. R4 — repeated-node wedge/splice producer;
4. R5 — explicit local lattice phase and advancing-front events;
5. R6 — torus decomposition/descriptor support;
6. R7 — adaptive dyadic 2:1 transitions;
7. R8 — direct production validation;
8. R9 — cache reuse;
9. R10 — stage-lineage fixtures;
10. R11 — synchronized memory telemetry.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no timeout-as-correctness.

## Key lessons

- Fix the earliest exact topology predicate before modifying ownership, completion, stage lineage, or performance systems.
- Compile success establishes integration and packaging only; P5-TB24 determines whether R1C restores valid runtime graph behavior.
- Every runtime scope requested by an artifact-only plan must be linked into one of the packaged targets.
