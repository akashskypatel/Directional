# Milestone G Production Readiness TODO

Last updated: 2026-08-04  
Base branch: `surface_cell_quad`  
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active checkpoint

- Phase: P5 — direct completion ownership remediation.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; review policy `never`; keep open and unmerged.
- Tested source: `247061bbaa835e5e5bf9298cc5e2c4dd25d5c74f`.
- Implementation commit: `01788193457e60bb8817a40b2c1551e672c4de5c`.
- Artifact: `8890167812`, `surface-cell-p5-cb134-github-source-linux-release`.
- Artifact SHA-256: `34a4da9a9c9e3374ed861c41b72493beefc90afbc85743fd25979484f3222bf1`.
- Completed turn: **P5-TB21 artifact-only test and benchmark**.
- Next turn: **P5-CB135 through P5-CB142 code + compile-only build**.

## Work phases

- [x] P0–P4 — earlier remediation.
- [ ] P5 — direct completion ownership remediation. **In progress**
- [x] P5-CB42–P5-CB134 — implementation and compile/package turns through typed embedding, route identity, source-sheet ownership, and telemetry semantics.
- [x] P5-TB11–P5-TB21 — runtime diagnosis through termination, topology, route, completion, and memory evidence.
- [x] P5-CB126 runtime — positive provenance and negative zig-zag contracts pass.
- [x] P5-CB127 runtime — focused shared-edge parity contract passes.
- [ ] P5-CB128 runtime — cylinder remains non-disk.
- [ ] P5-CB129 runtime — repeated-node alternatives do not commit and work is not deterministically bounded on bunny.
- [ ] P5-CB130 runtime — valid parallel route and real reuse remain open.
- [ ] P5-CB131 runtime — GP23/GP24/Phase20 later-stage lineage remains preempted.
- [ ] P5-CB132 runtime — typed failures are available; valid local producers remain open.
- [ ] P5-CB133 runtime — plane/seam/close sheets remain `LocalSheetMismatch`.
- [ ] P5-CB134 runtime — measurement availability is honest, but 75% same-sample reconciliation is not established.
- [ ] P5-CB135–P5-CB142 — next producer and termination remediation.
- [ ] P6–P8 — final validation, closure, and production disposition.

## P5-TB21 evidence

Package authority:

- source status empty;
- recursive checksums **41/41**;
- fixture files **26**;
- recursive submodules **9**;
- no source modification or rebuild.

Tests:

- Phase 14–18: **236/236**;
- Phase 16: **39/39**;
- Phase 17: **26/26**;
- Milestone D: **6/7**;
- Milestone E: **23/26**;
- GP23 + GP24: **10/14**;
- Phase 20: **46/48**;
- full suite: **does not terminate** on bunny aggregate cases;
- bounded subset: **583/597**, 14 failures.

Production:

- direct production remains **0/8** with fallback `Fail` and recovery disabled;
- plane/seam/close sheets produce 12/24/34 quads then fail `LocalSheetMismatch`;
- cylinder fails typed `bow-tie-intersection`, while the D closure fixture remains non-disk;
- thin tube fails typed `degenerate-normal`;
- torus reports exact incomplete inventory at descriptor 22 / cell 23;
- sphere, mechanical, and face-edge fail repeated-boundary-node before completion;
- valid parallel route still fails and reuse/recompute remains `0/0`.

Bunny/resources:

- face-edge: three stable failed runs at 20.191–22.047 s and 164.30–164.39 MB;
- face-edge fourth repetition did not complete within the remaining approximately 257 s of a 300 s batch;
- smooth: one failed run at 40.090 s and 452.79 MB, exceeding the 39.228299 s limit;
- same-sample ownership measurement unavailable; face-edge coverage about 23.25%, smooth about 39.03%.

## P5-CB135–P5-CB142 requirements

Follow `.agents/Directional/Milestone_G_P5_Post_TB21_Production_Termination_Code_Build_Plan.md`:

- [ ] P5-CB135 — canonical alternative-state budget, deduplication, memoization, typed cycle/exhaustion, exact rollback.
- [ ] P5-CB136 — valid repeated-node alternative for generalized sphere/mechanical/face-edge topologies.
- [ ] P5-CB137 — repair cylinder periodic DCEL incidence.
- [ ] P5-CB138 — reject invalid local variants and choose bounded valid templates.
- [ ] P5-CB139 — distinguish valid parallel routes and produce real reuse/recompute.
- [ ] P5-CB140 — global source-sheet chart equivalence and shared-edge agreement.
- [ ] P5-CB141 — production-valid optimization/validation injection and failure lineage.
- [ ] P5-CB142 — typed torus inventory repair, same-sample memory sampling, exact four-target compile/package gate.

The next turn must compile exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`; execute no project binary.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB21_Artifact_Only_Test_Benchmark_Report.md`
- `benchmark-results/p5-tb21-summary.json`
- `.agents/Directional/Milestone_G_P5_Post_TB21_Production_Termination_Code_Build_Plan.md`
- `.agents/Directional/Milestone_G_P5_CB126_CB134_Code_Build_Report.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `.agents/Directional/Future_Chat_Session_Handoff.md`

Preserve all prohibitions: no validator weakening, frequency/count/order selection, fallback/recovery substitution, synthetic counters, positional merging, source-triangle pairing, arbitrary subset search, fixture/ID special cases, or timeout-as-correctness.

P5 remains open. PR #8 remains draft and unmerged.
