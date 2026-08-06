# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2E16 Pair-Local Authoritative Fan-Chart Interval Projection Code + Build is complete and compile-valid.

Runtime acceptance is not claimed. **R2 remains open. Do not advance to R2F or R3.**

Compile authority:

- workflow event commit: `a882dec6321ae632578b40aca6282015ac5284d2`;
- exact compiled source: `9db5531913195b255ea4c86ad50f609772527604`;
- workflow run/job: `31110167386` / `92645562024`;
- build artifact: `8971571147`, SHA-256 `a0f18f8f4d544f8dd8e1a0f3ebb2b558188beed485294019c68f56ab2f4c2da3`, size **12,343,344 bytes**;
- log artifact: `8971571865`, SHA-256 `4b2404a68368ae7eef3445f8c1db7c43ef8b05fcbb929a7768ea20b270d16358`, size **5,803 bytes**;
- compile/link actions **132/132**;
- manifest **20/20**; package files **21**; recursive submodules **9**; fixture/input closure **26/26**; source status empty;
- built exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- no test, benchmark, custom input, help/list/discovery command, CLI, GUI, or generated project binary was executed.

P5-R2E16 retains node-level canonical pair ownership, exact normalized entity, one common non-exterior root, and R2E14 two-sided exterior authority. Interval geometry now uses the union of every exact identity recorded in `record.fanIdentities`; all identities must reconcile, unrelated identities cannot intrude, and no identity ranking or arbitrary subset search is used. A deterministic non-weakening interval failure subtype/context is available to P5-TB44.

The next turn is **P5-TB44 artifact-only R2E16 Test + Benchmark** using artifact `8971571147`. The authoritative plan is:

`.agents/Directional/Milestone_G_P5_TB44_Artifact_Only_R2E16_Test_Benchmark_Plan.md`

## Exact implementation authority

- `src/geometry/SurfaceArrangement.cpp`: `ed26133b36673be28f70e91ea3e281c4cdd85441`;
- `include/directional/geometry/SurfaceArrangement.h`: `43484706abcc54cf68e5d3ec7092487d07e0cf8c`;
- `tests/SurfaceArrangementPhase16Tests.cpp`: `7f2dbddd3e45ee98d5ac37bfe18b7970f41a6d06`;
- `tests/MilestoneDClosureTests.cpp`: `6887608b5aea173d6e6b5eaaee60150c4db17924`;
- decoded patch SHA-256: `c8f281c966c7a2fcb102c8079b2ff4cc3b460ca5b0d94c978104dd5fc954f47c`.

## Last runtime baseline: P5-TB43

- planar: `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`, tuple `3/5/4/9`, three canonical pairs, one exterior exclusion, zero wraps;
- hard rail: `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`, tuple `1/5/4/1`, zero publication counters;
- source chart + validator **17/17**;
- recovery authority **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 14–18 **235/244**;
- Phase 20 **46/48**;
- complete suite **597/625**, 28 failures, 0 errors, 0 disabled.

## Retained authoritative documentation

Only current and durable documents must remain under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_R2E16_Code_Build_Report.md` — implementation and compile authority;
3. `Milestone_G_P5_TB44_Artifact_Only_R2E16_Test_Benchmark_Plan.md` — next executable plan;
4. `DESIGN.md`;
5. `REORIENTATION_PLAN.md`;
6. `Surface_Cell_Backend_Remediation_Plan.md`;
7. `GitHub_Workflow_Policy.md`.

Superseded per-turn plans, reports, closure notes, and summaries are removed after their replacements are verified. Git history and PR #8 retain historical authority.

## Retained benchmark results

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-r2e16-summary.json` — exact source/package authority and retained P5-TB43 runtime baseline.

## Read first for P5-TB44

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_R2E16_Code_Build_Report.md`
5. `.agents/Directional/Milestone_G_P5_TB44_Artifact_Only_R2E16_Test_Benchmark_Plan.md`
6. `benchmark-results/p5-r2e16-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`
11. `turn-based-coding-agent/SKILL.md` and Test + Benchmark/testing-integrity/status/handoff/GitHub connector references.

## P5-TB44 first actions

1. Inspect `.github/workflows`, temporary trigger locations, `.agents/Directional/patches`, and generated artifacts; final branch should contain only the durable source-snapshot workflow and no payload directory.
2. Download artifact `8971571147` through the GitHub connector and verify outer SHA-256 `a0f18f8f4d544f8dd8e1a0f3ebb2b558188beed485294019c68f56ab2f4c2da3`.
3. Verify all internal manifest entries, exact source/event commits, four production/header/test blobs, empty source status, nine recursive submodules, required binaries/libraries, and 26 fixture/input files.
4. Extract into an arbitrary clean directory and execute only packaged binaries; do not configure, compile, relink, patch, or regenerate.
5. Run source-chart/validator prerequisites first.
6. Run planar and hard rail in at least three independent processes, retaining the exact interval subtype/context and deterministic log hashes.
7. Apply the exact gates in `.agents/Directional/Milestone_G_P5_TB44_Artifact_Only_R2E16_Test_Benchmark_Plan.md`.
8. Run one normal single-process complete suite; if it does not complete, preserve process evidence and use a complete non-overlapping split inventory.
9. Produce the next Code + Build plan from the first authoritative remaining producer; review remains skipped.

## Lessons from P5-R2E16

- Pair-local projection is the complete union of every exact identity recorded on the pair; it is not identity choice or subset search.
- A ray belonging only to another exact fan identity must remain available for its own pair but cannot become an interval intruder for this pair.
- Multiple identities contributing the same ray must agree exactly on chart, lifted angle, turn, and provenance.
- Diagnostic detail must classify the first failure without changing the existing aggregate acceptance gate.
- Two workflow runs (`31109651905`, `31109796879`) correctly stopped at the turn-file closure gate because the payload had not yet landed. They created no source commit and executed no build or runtime command.
- Stage and verify the payload commit before changing the unique workflow trigger path. A workflow-only trigger commit is not evidence that the payload exists.
- Use only successful run `31110167386`, event `a882dec6321ae632578b40aca6282015ac5284d2`, and source `9db5531913195b255ea4c86ad50f609772527604` as P5-R2E16 authority.

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
