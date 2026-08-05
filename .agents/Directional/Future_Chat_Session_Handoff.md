# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2E8 canonical boundary corner-sector and rail-chart embedding Code + Build is complete.

- exact source: `478d058ab2060a1a02a1e4ca3bfc0e6625fa8047`;
- `SurfaceArrangement.cpp` blob: `76e57fef36f9322598387b6b5e968a14b885b755`;
- workflow run: `31041383154`;
- compiled artifact: `8944910920`;
- artifact SHA-256: `5b93e86db0ddccf4ca3eba2e9b53e6523f02d7ef70809aa8eb67b91f6e9bef39`;
- compile/link actions: **132/132**;
- exact approved targets: `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- no test, benchmark, help/list/discovery command, CLI, GUI, or generated project binary was executed.

R2E8 now constructs affected higher-valence source-boundary covers from canonical cyclic R1 corner pairs, excludes the independently proven exterior continuation, requires a complete local bijection before publication, derives hard-rail sides from exact incident source-face/chart roots, and audits a common root over predicted bounded rail-side orbits. Generic intrinsic successors are no longer complete-cover authority. Downstream validators remain unchanged.

The next turn is **P5-TB36 artifact-only R2E8 Test + Benchmark**. Runtime acceptance is not yet claimed. Do not advance to R2F or R3.

## Last runtime baseline

The last completed runtime checkpoint predates R2E8:

- complete suite: **597/625**;
- R2 focused: **13/16**;
- Phase 16: **45/47**;
- Phase 17: **20/26**;
- Phase 18: **57/57**;
- planar boundary node failed `BoundaryFanSectorCoverConflict` before publication;
- hard rail passed incidence, cell count, disk, loop, Euler, ownership, and distinct bounded rail-twin ownership, but failed embedding and aggregate topology.

P5-TB36 must compare directly against this baseline and establish whether R2E8 closes those two producers without regressing accepted R2E5/R2E6/R2E7 authority.

## Retained authoritative documentation

Only current, durable documentation is retained under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_R2E8_Code_Build_Report.md` — exact implementation and compile authority;
3. `Milestone_G_P5_TB36_Artifact_Only_R2E8_Test_Benchmark_Plan.md` — next executable plan;
4. `DESIGN.md` — durable design authority;
5. `REORIENTATION_PLAN.md` — durable reorientation authority;
6. `Surface_Cell_Backend_Remediation_Plan.md` — milestone and remediation authority;
7. `GitHub_Workflow_Policy.md` — remote build and repository-write policy.

Superseded per-turn plans, reports, closure notes, and evidence indexes are removed after replacement. Their historical commit data remains available through Git history and PR #8.

## Retained benchmark results

Only current or durable result files are retained under `benchmark-results`:

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-r2e8-summary.json` — exact compiled-source/package authority for the active source.

Older P5 checkpoint summaries and superseded runtime snapshots are removed after their current conclusions are carried into this handoff and the active trackers.

## Read first for P5-TB36

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_R2E8_Code_Build_Report.md`
5. `.agents/Directional/Milestone_G_P5_TB36_Artifact_Only_R2E8_Test_Benchmark_Plan.md`
6. `benchmark-results/p5-r2e8-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB36 objective

1. Download artifact `8944910920` and verify archive SHA-256 plus every internal manifest entry.
2. Execute only the packaged binaries; do not configure, rebuild, relink, patch, regenerate, or modify source/tests/fixtures.
3. Run source-chart and validator prerequisites before arrangement tests.
4. Run the R2 focused set, Milestone D, Phase 16, Phase 17, Phase 18, Phase 14–18, Phase 20, graph-dependent, and complete-suite scopes.
5. Prove the planar direct corner-sector relation publishes and reaches unchanged topology validators, or record its earliest typed failure.
6. Prove hard-rail incident chart roots, bounded orbit roots, embedding, and aggregate topology, or record the earliest typed failure.
7. Preserve degree-two, genuine four-disk, source-row, whole-orientation, pinched-fan, close-sheet, bridge/support, nested, and nonmanifold authority.
8. Run deterministic bunny production processes only after focused regressions, with fallback `Fail`, source-grid recovery disabled, and no legacy execution.
9. Produce the next Code + Build plan from the earliest remaining authoritative producer.

## Lessons from P5-R2E8

- Generated whole-file transformations can hide a one-brace scope error even when the intended semantic change is narrow. Inspect the exact transformed hunk and compile before treating the source commit as authoritative.
- Large base64 workflow payloads are fragile when transferred through repository writes. Prefer a bounded inline transformation with exact pre-image blob checks, one-file scope verification, `git diff --check`, and a compile-only gate.
- Build-orchestration failures are not implementation acceptance evidence. Preserve their logs, correct the mechanism narrowly, and claim only the final verified source/artifact.
- The final successful workflow must push the exact compiled source commit before building, then package that same commit and record both workflow-event and source authority.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the **start and end of every turn**, inspect `.github/workflows` and all temporary workflow-support locations, including temporary trigger files, transfer files, patch/payload directories, and generated build artifacts.
2. Remove stale bounded or turn-specific workflow files before beginning work so an old workflow cannot run, conflict with the current turn, or generate unrelated errors.
3. During a remote compile turn, retain only the approved durable base workflow files plus at most one bounded workflow and the exact temporary payloads required for the current turn.
4. Immediately after the current artifact and logs are published and verified, remove the bounded workflow, its trigger, and its temporary payload or transfer files.
5. The final branch state for every turn must contain only approved durable base workflows and no stale temporary workflow payloads or generated build artifacts.
6. Do not remove a durable base workflow dependency that is explicitly consumed by an approved retained workflow. Distinguish active base-workflow inputs from stale turn-specific payloads before deleting anything.

### Documentation and test-result cleanup

1. At the **end of every turn**, review `.agents` and `benchmark-results` and remove stale or superseded documents, plans, reports, closure notes, evidence indexes, test results, benchmark results, and machine summaries.
2. Retain only durable project authority and the minimum current turn chain required to resume expertly: the live handoff, the latest completed authoritative report, the next executable plan, current source/package authority, the latest runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Update every retained document so it references only files that still exist after cleanup.
4. Do not keep duplicate historical snapshots merely for provenance; Git history and the PR conversation are the historical archive.
5. Never delete the latest authoritative evidence or next-turn instructions before their replacement is committed and verified.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction in this handoff unless the user explicitly instructs its removal or replacement.**
2. Handoff edits must be additive or narrowly corrective by default. Preserve all existing procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements.
3. Before committing a handoff update, compare the new document with the previous version and verify that every pre-existing mandatory instruction remains present and materially unchanged.
4. When a new instruction appears to conflict with an existing mandatory instruction, preserve both, identify the conflict explicitly, and request user direction rather than deleting either instruction.
5. Documentation cleanup does not authorize removal of mandatory handoff rules. Mandatory rules remain even when older reports, plans, and results are deleted.

## End-of-turn requirement

Every completed Code + Build, Test + Benchmark, optional Review, or documentation-maintenance turn ends with a **new top-level PR #8 comment** after all documentation and PR metadata updates. That comment must be the final repository write.

## Preserved prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
