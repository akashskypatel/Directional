# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Exact compiled source: `e31e5abd52ca9e673d1718f47d088d19296d1d22`.
- Artifact: `8902050372`, `surface-cell-p5-r1-github-source-linux-release`.
- Artifact SHA-256: `5d1e5ca4fa8bc74e0a30615725c79a8b491830ab1f4407152cf79bfe56f8880f`.
- Completed turn: **P5-R0/R1 code + compile-only build**.
- Next turn: **P5-TB23 artifact-only R0/R1 validation**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] P5-TB22 — deterministic terminating runtime baseline, **585/600**, production **0/8**.
- [x] R0 — recovery defaults off and reports a distinct non-authoritative output origin.
- [x] R1 compile — canonical source-entity transition graph and integration compiled.
- [ ] R1 runtime — focused transition, rollback, and analytic direct production acceptance.
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

## P5-R0/R1 package evidence

- workflow event commit `233466e5b02c3762a3f2648518f5860a2a2fb014`;
- implementation commit `ae0c09ed1290df75d1d2cc1d5af039fc1feb83a3`;
- compile fix / exact source `e31e5abd52ca9e673d1718f47d088d19296d1d22`;
- reviewed patch SHA-256 `a3898a847c6722a1f2d9b0de48e71ae71f08fcc0bc82b3d9396d8c842d9cad61`;
- compile-fix patch SHA-256 `92162aa709134c86a355253416dc614817fecabebaeb60c58555061958d12162`;
- successful run `30932812460`, job `92071429858`;
- source status empty;
- recursive checksum manifest **41/41**;
- package files **43**;
- fixture files **26**;
- recursive submodules **9**;
- all **131/131** Ninja actions completed;
- compiled exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- no project binary, test, benchmark, custom mesh, help/list, or discovery command executed;
- workflow-log artifact `8902051026`, SHA-256 `dee5e429cb9a57ee9b45db42d27b512c7b096aed875147a01364e5a757f4b5a6`.

## R0 implementation

- [x] `allowSourceGridRecovery` defaults to `false`.
- [x] Recovery requires explicit opt-in.
- [x] Successful recovery reports `SourceGridRecovery`, not `CompletedSurfaceCells`.
- [x] Direct fallback `Fail` semantics remain fail-closed.
- [x] No cache, lineage, memory, general FlowRep, or new completion-search work was added.

## R1 implementation

- [x] explicit chart nodes `(component, localSheet, sourceFace)`;
- [x] orientation-aware source-edge transitions and inverse maps;
- [x] exact source-edge/source-vertex barycentric rebinding;
- [x] intrinsic source-vertex fan partitioning;
- [x] component, sheet, source-boundary, hard-rail, and nonmanifold barriers;
- [x] deterministic canonical source entities;
- [x] inconsistent source winding rejection;
- [x] arrangement, completion, stitching, optimizer, pipeline, and validator integration;
- [x] compile-valid focused tests for edge, fan, barrier, disconnected sheet, permutation, inverse, recovery authority, and rollback contracts.

## Last runtime evidence: P5-TB22

- focused contracts **32/42**;
- Phase 14–18 **236/236**;
- Milestone D **6/7**;
- Milestone E **23/26**;
- GP23 + GP24 **10/14**;
- Phase20 **46/48**;
- complete suite **585/600** in **103.441 s**;
- direct production **0/8**;
- plane/seam/close sheets fail `LocalSheetMismatch` in the tested baseline.

No runtime claim is made for R1 until P5-TB23.

## P5-TB23 requirements

Follow `.agents/Directional/Milestone_G_P5_R1_Test_Benchmark_Plan.md`:

- [ ] verify exact artifact authority and packaged source;
- [ ] prove default-off and non-authoritative recovery behavior;
- [ ] pass exact adjacent-edge transition and inverse contracts;
- [ ] pass intrinsic source-vertex fan and barrier contracts;
- [ ] keep disconnected and opposite close sheets separate;
- [ ] preserve canonical hashes under face-row permutation and source orientation reversal;
- [ ] fail inconsistent transitions before global commit with exact rollback;
- [ ] pass focused arrangement, completion, stitching, and source-authoritative validator scopes;
- [ ] complete plane, multi-face seam, and close sheets directly without `LocalSheetMismatch` or leakage;
- [ ] run Phase 14–18 and required analytic regression scopes;
- [ ] confirm normal termination of the complete suite once;
- [ ] do not run the full bunny benchmark matrix solely for R1.

P5-TB23 must execute artifact `8902050372` directly and must not configure, rebuild, relink, patch, regenerate, or modify source.

Proceed to R2 only after R1 runtime evidence is authoritative.

## Current authority

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Milestone_G_P5_R0_R1_Code_Build_Report.md`
- `.agents/Directional/Milestone_G_P5_R1_Test_Benchmark_Plan.md`
- `benchmark-results/p5-r1-summary.json`
- `.agents/Directional/Milestone_G_P5_TB22_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

The prior CB143–CB150 plan remains historical diagnosis; its broad execution order is superseded.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
