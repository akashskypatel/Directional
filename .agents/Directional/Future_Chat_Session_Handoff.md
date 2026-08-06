# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB42 artifact-only R2E14 Test + Benchmark is complete. P5-R2E14 is **not accepted**.

- exact tested source: `2a8b9870b8e3854ae77a7e4eeae6da29a7899968`;
- artifact: `8958361834`, SHA-256 `1f2607859ecf84d2cb82597f2c4f8f9341491df62d99b694510241f8df719db6`, size **12,307,622 bytes**;
- manifest: **20/20**; package files: **21**; recursive submodules: **9**; source status empty; fixtures staged: **26**;
- evidence archive: `directional-p5-tb42-8958361834-evidence.zip`;
- evidence SHA-256: `41a2a7b58cc16ac96944a796a67d6a42ec00559b86a6cdb6991e0e9b04500fa3`;
- evidence files: **214**.

Only packaged binaries were executed. No configure, rebuild, relink, regeneration, patch, binary replacement, or implementation/test/fixture/validator/workflow/build change occurred.

The next turn is **P5-R2E15 chart-local lifted interval authority Code + Build**. R2 remains open. Do not advance to R2F or R3.

## Exact runtime disposition

Planar remains deterministic across three byte-identical processes:

- `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`;
- tuple `3/5/4/9`;
- canonical pairs **3**;
- exterior exclusions **1**;
- cyclic-wrap interior sectors **0**.

Interior hard rail advances deterministically across three byte-identical processes:

- P5-TB41: `ExteriorPairMismatch(2)` at tuple `1/7/6/1`;
- P5-TB42: `InvalidOrientedInterval(8)` at tuple `1/5/4/1`.

The prior exterior-root equality mismatch is no longer the first observable hard-rail producer. Publication counters remain zero because chart interval resolution fails before candidate publication, so do not infer later exterior, separator, orbit, Euler, or topology validity from those counters.

Current aggregate authority:

- source chart + validator **17/17**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 14–18 **235/244**;
- Phase 20 **46/48**;
- full single-process suite **597/625**, exact 28 failures;
- complete split inventory **597/625**, the same exact 28 failures.

The single-process complete suite finished normally in **74.23 s**, maximum RSS **282,848 KiB**. The prior P27/bunny cumulative-state stop was not reproduced in TB42. Preserve it only as historical performance/nontermination evidence; timeout is never correctness evidence.

Direct plane, multi-face seam, close sheets, cylinder, and bunny remain `success=false` under backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution. Structural lineage remains deterministic.

## Earliest remaining producer

The exact source computes a unique lifted angle for each chart ray inside the authoritative entity wedge, then creates a second inventory sorted by raw global `atan2` angle and uses that second ordering for adjacency and interval resolution.

The next implementation must make the already-computed wedge-local lifted coordinate authoritative:

- pair existence and normalized entity/root ownership remain node-level;
- each ray must have one exact integer-turn lift inside the chart wedge;
- source must be the immediate directed successor of target in lifted order;
- span and third-ray checks use lifted angles;
- `cyclicWrap` is true only for an exact one-turn source/target lift difference;
- raw angle remains diagnostic provenance only;
- chart-local evidence never creates or chooses a pair.

See `.agents/Directional/Milestone_G_P5_R2E15_Chart_Local_Lifted_Interval_Authority_Code_Build_Plan.md`.

## Retained authoritative documentation

Only current and durable documents must remain under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_TB42_Artifact_Only_R2E14_Test_Benchmark_Report.md` — exact runtime authority;
3. `Milestone_G_P5_R2E15_Chart_Local_Lifted_Interval_Authority_Code_Build_Plan.md` — next executable plan;
4. `DESIGN.md`;
5. `REORIENTATION_PLAN.md`;
6. `Surface_Cell_Backend_Remediation_Plan.md`;
7. `GitHub_Workflow_Policy.md`.

Superseded per-turn plans, reports, closure notes, and summaries are removed after their replacements are verified. Git history and PR #8 retain historical authority.

## Retained benchmark results

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-tb42-summary.json` — exact source, runtime, failure inventory, and next-producer authority.

## Read first for P5-R2E15

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB42_Artifact_Only_R2E14_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E15_Chart_Local_Lifted_Interval_Authority_Code_Build_Plan.md`
6. `benchmark-results/p5-tb42-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E15 first actions

1. Inspect `.github/workflows` and temporary payload locations; only the durable source-snapshot workflow should remain.
2. Confirm PR #8 is open, draft, unmerged and the branch starts at the current documentation checkpoint.
3. Re-read the P5-TB42 report and authoritative R2E15 plan.
4. Verify exact preimage blobs before modifying any approved file.
5. Implement only chart-local lifted interval authority while preserving canonical pair, two-sided exterior, common-root, and downstream validation contracts.
6. Push the exact source commit before configuration or compilation.
7. Build exactly the four approved targets in Release `-O2 -DNDEBUG`.
8. Execute no test, benchmark, project binary, custom input, help/list/discovery command, CLI, or GUI.
9. Package and verify exact source, binaries, libraries, fixtures, submodules, metadata, checksums, and separate detailed logs.
10. Remove the bounded workflow and every temporary payload after artifact verification.
11. Prepare P5-TB43 artifact-only validation and update the live handoff without removing any mandatory instruction.
12. Make the final top-level PR #8 comment the final repository write.

## Lessons from P5-TB42

- Passing the old first failure does not establish complete exterior publication; stop at the first newly observable producer.
- Zero publication counters after an interval rejection cannot be used to infer whether pre-publication exterior construction succeeded or failed.
- A global raw-angle sort is not authoritative for a bounded chart wedge whose rays already have unique lifted coordinates.
- The lifted coordinate should encode the branch-cut turn; do not add `2π` later as a heuristic.
- Chart-local evidence resolves geometry only after canonical pair existence and ownership are established.
- Normal full-suite completion in this turn supersedes the need for split correctness authority, but the retained split still cross-checks the exact inventory.
- A prior timeout remains historical performance evidence; it must not be silently converted into correctness evidence or erased.
- The exact source commit must be pushed before compilation and packaged unchanged.

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
