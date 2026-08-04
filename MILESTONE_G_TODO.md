# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Tested source: `aa2917e280fabd2272911a39cd0ecc327cce1cf3`.
- Artifact: `8894034755`, `surface-cell-p5-cb142-github-source-linux-release`.
- Artifact SHA-256: `ff77004f8893b9f993165ba685794faca52f5611c9f1c47deb3f1dd5d930cb55`.
- Completed turn: **P5-TB22 artifact-only test and benchmark**.
- Reorientation authority: `.agents/Directional/REORIENTATION_PLAN.md`.
- Next turn: **P5-R0/R1 code + compile-only build**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct surface-paving producer remediation. **In progress**
- [x] P5-CB42–P5-CB142 — previous implementation and compile/package turns.
- [x] P5-TB11–P5-TB22 — runtime diagnosis through restored deterministic termination.
- [x] R0 review decision — freeze downstream repair expansion and make recovery non-authoritative.
- [ ] R0 implementation — recovery default-off/distinct origin and preserved direct fail-closed semantics.
- [ ] R1 — canonical source-entity transition graph.
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

## P5-TB22 evidence

Package authority:

- source status empty;
- recursive checksums **40/40**;
- package files **42**;
- fixture files **26**;
- recursive submodules **9**;
- no source modification or rebuild.

Tests:

- focused contracts **32/42**;
- Phase 14–18 **236/236**;
- Phase 16 **39/39**;
- Phase 17 **26/26**;
- Milestone D **6/7**;
- Milestone E **23/26**;
- GP23 + GP24 **10/14**;
- Phase20 **46/48**;
- complete suite terminates at **585/600** in **103.441 s**.

Production:

- direct production remains **0/8** with fallback `Fail` and recovery disabled;
- plane/seam/close sheets produce 12/24/34 quads then fail at the same `LocalSheetMismatch` locations;
- cylinder remains non-disk and fails with a bow-tie completion;
- thin tube and smooth bunny fail with degenerate local completion geometry;
- torus reports descriptor 22 / cell 23 / `side-count-unsupported`;
- sphere and mechanical exhaust 68/68 and 104/104 repeated-node alternatives;
- valid parallel route still fails and reuse/recompute remains `0/0`.

Bunny/resources:

- face-edge: four terminating deterministic failures, 20.727–22.865 s, 165.54–165.77 MB, 14/14 alternatives, one sequence hash;
- smooth: four terminating deterministic failures, 31.052–35.588 s, 452.57–452.69 MB, within established limits;
- valid output remains absent for both fields;
- same-sample telemetry marks availability true but records zero categorized bytes and 0% coverage.

## Reorientation rationale

The previous CB143–CB150 plan mixed foundational producer corrections with cache, lineage, and memory work. `REORIENTATION_PLAN.md` correctly identifies that the constructive heart is underdeveloped relative to repair infrastructure.

Critical order:

1. source-chart identity;
2. directed incidence;
3. topology-distinct completion;
4. repeated-node local topology;
5. explicit phase/front state;
6. torus and adaptive transitions;
7. direct production gates;
8. operational hardening.

The document contains an editorial mismatch between some section labels and its final revised task list. For execution, the R0–R11 sequence recorded here and in `Milestone_G_P5_R0_R1_Reoriented_Code_Build_Plan.md` is authoritative.

## P5-R0/R1 requirements

Follow `.agents/Directional/Milestone_G_P5_R0_R1_Reoriented_Code_Build_Plan.md`:

- [ ] preserve existing typed failures, hashes, exact rollback, and validator authority;
- [ ] add no unnecessary diagnostic/ownership categories;
- [ ] make source-grid recovery default-off or a distinct non-authoritative origin;
- [ ] create orientation-aware source-face chart transitions;
- [ ] partition source-vertex incidence into intrinsic fans;
- [ ] choose deterministic canonical source entities;
- [ ] validate transition composition around cycles;
- [ ] resolve arrangement/completion/stitch provenance through the graph;
- [ ] keep disconnected/opposite sheets distinct;
- [ ] compile tests for edge, vertex-fan, hard-rail, disconnected-sheet, permutation, inverse, and rollback contracts.

Runtime closure is not claimed in the compile turn. P5-TB23 must test plane, multi-face seam, close sheets, disconnected close sheets, source orientation reversal, face-row permutation, and exact transition rollback directly from the packaged artifact.

Do not run the full bunny matrix merely because R1 changed.

Compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`; execute no project binary.

## Current authority

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Milestone_G_P5_R0_R1_Reoriented_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_TB22_Artifact_Only_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb22-summary.json`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

The previous post-TB22 CB143–CB150 plan is retained as historical failure diagnosis; its ordering is superseded.

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
