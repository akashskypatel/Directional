# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB43 artifact-only R2E15 Test + Benchmark is complete.

**P5-R2E15 is not accepted. R2 remains open. Do not advance to R2F or R3.**

Exact runtime authority:

- workflow event commit: `47a5bf7a93fca3f63d9c54e09a1becd22251caef`;
- exact tested source: `f14f1d416a9cb1b7afdf8109d22a76895e22fced`;
- workflow run/job: `31096815851` / `92600707664`;
- build artifact: `8965975937`, SHA-256 `2ea192b2be7496aa104948171d509d0f422b63afcf4ce296d4b35c60e2a28315`, size **12,306,846 bytes**;
- log artifact: `8965976454`, SHA-256 `68a5c352a618f594c757a1904ea1e9df31706dcb0706adabf6f4e9d87de3f0e9`;
- manifest **20/20**; artifact package files **21**; recursive submodules **9**; fixture closure **26/26**; source status empty;
- only packaged binaries were executed; no configure, build, relink, patch, regeneration, source/test/fixture/validator/workflow/build change, or binary replacement occurred.

Focused runtime disposition:

- planar: `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`, tuple `3/5/4/9`, three canonical pairs, one exterior exclusion, zero wraps; three independent logs are byte-identical with SHA-256 `3498659bc601e18794fc90fe2d3b87349f66e4c172d9f57a9312b9d049887ade`;
- interior hard rail: `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`, tuple `1/5/4/1`, zero publication counters; three independent logs are byte-identical with SHA-256 `fc7c65f89c71d707f7cf2df8873ec28147788d6b203307f39b0150194819f5cf`.

Neither target advances from P5-TB42. The complete suite is still **597/625** with the exact same 28 failures. Phase 17 remains **20/26**. The authoritative full process completed normally in **75.894 s** XML / **1:15.90** wall with **279,568 KiB** maximum RSS.

Direct plane, multi-face seam, close-sheet, cylinder, and `bunny_1k_random.obj` processes remain `success=false` under backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution. Structural lineage is deterministic.

The next turn is **P5-R2E16 Pair-Local Authoritative Fan-Chart Interval Projection Code + Build**. The authoritative plan is:

`.agents/Directional/Milestone_G_P5_R2E16_Pair_Local_Authoritative_Fan_Chart_Interval_Projection_Code_Build_Plan.md`

## Exact source authority

- `src/geometry/SurfaceArrangement.cpp`: `bc14dff449151f7925cb39e03cdc9d089f161558`;
- `include/directional/geometry/SurfaceArrangement.h`: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- `tests/SurfaceArrangementPhase16Tests.cpp`: `de5b7c4f3d7c53f8488bc7de5d883ac72429e894`;
- `tests/MilestoneDClosureTests.cpp`: `1625b8139a9da8e2a6cfddd1bb026ae69ba47ed2`.

## Current runtime inventory

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
- complete suite **597/625**, 28 failures, 0 errors, 0 disabled;
- exact failure-set change from P5-TB42: 0 closed, 0 new.

## Source-supported next producer

This is an inference from the exact source and deterministic P5-TB43 evidence; current runtime diagnostics do not emit the exact interval-rejection subtype.

The implementation still builds one node-wide same-chart ray inventory from every fan identity, then resolves each already-authoritative canonical pair against all same-kind rays in that chart. It does not project interval geometry from the complete exact identity set stored on that pair in `record.fanIdentities`. An unrelated identity sharing the node/chart can therefore affect immediate adjacency or third-ray intrusion for a pair it does not own.

R2E16 must:

- retain node-level pair existence, normalized entity, and exact common non-exterior root;
- retain R2E14 two-sided exterior authority;
- project interval geometry from the union of **every exact identity** in `record.fanIdentities`;
- never choose one identity or arbitrary subset;
- require all contributing identities to agree on chart, source/target lifted interval, and turn classification;
- prevent unrelated identities from intruding while preserving them for their own pairs;
- fail closed on missing, ambiguous, incomplete, or contradictory evidence;
- expose a deterministic first interval-rejection subtype and exact chart/entity/root/position/angle/turn/wedge context;
- preserve complete cover, predecessor, hard-rail, bounded-orbit, embedding, Euler, ownership, and aggregate-topology gates.

## Retained authoritative documentation

Only current and durable documents must remain under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_TB43_Artifact_Only_R2E15_Test_Benchmark_Report.md` — exact runtime authority;
3. `Milestone_G_P5_R2E16_Pair_Local_Authoritative_Fan_Chart_Interval_Projection_Code_Build_Plan.md` — authoritative next plan;
4. `DESIGN.md`;
5. `REORIENTATION_PLAN.md`;
6. `Surface_Cell_Backend_Remediation_Plan.md`;
7. `GitHub_Workflow_Policy.md`.

Superseded per-turn plans, reports, closure notes, and summaries are removed after their replacements are verified. Git history and PR #8 retain historical authority.

## Retained benchmark results

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-tb43-summary.json` — exact artifact/runtime/failure/direct-process authority.

Evidence archive outside the repository:

- `directional-p5-tb43-8965975937-evidence.zip`;
- SHA-256 `a905452fc0061344b21b61aba386be4c8084c1919a0b5398145f0c19dc5ec3b5`;
- **296** entries, **474,775 bytes**.

## Read first for P5-R2E16

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB43_Artifact_Only_R2E15_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E16_Pair_Local_Authoritative_Fan_Chart_Interval_Projection_Code_Build_Plan.md`
6. `benchmark-results/p5-tb43-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`
11. `turn-based-coding-agent/SKILL.md` and Code + Build/testing-integrity/status/handoff/GitHub connector references.

## P5-R2E16 first actions

1. Inspect `.github/workflows`, temporary trigger locations, `.agents/Directional/patches`, and generated artifacts; remove stale bounded payloads before work.
2. Resolve and record the current branch head, PR #8 state, exact source/header/test preimage blobs, and allowed scope.
3. Re-read the P5-TB43 source excerpt around `raysByChart`, `chartWitnesses`, `record.fanIdentities`, lifted adjacency, and `invalidIntervalCount`.
4. Implement complete pair-local exact-identity projection without changing node-level pair ownership or exterior/root contracts.
5. Add only non-weakening diagnostic context and generalized regressions in the approved two target test files.
6. Push the exact source commit before compilation.
7. Use one bounded compile-only workflow to build exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks` in Release `-O2 -DNDEBUG`.
8. Do not execute tests, benchmarks, custom inputs, help/list/discovery commands, CLI, GUI, or generated project binaries.
9. Package and verify exact source/test blobs, source status, submodules, fixtures, binaries/libraries, logs, and manifest.
10. Remove the bounded workflow and every temporary trigger/patch/payload after verification.
11. Produce P5-R2E16 Code + Build authority and the P5-TB44 artifact-only validation plan.

## Lessons from P5-TB43

- Replacing raw-angle order with lifted order was necessary but not sufficient; neither deterministic focused tuple changed.
- A node-wide chart inventory can contain valid rays belonging to unrelated exact fan identities. Those rays must not become pair-local interval intruders merely because they share the node/chart.
- Pair-local projection is not subset selection: every exact identity recorded on the pair must be reconciled, and any contradiction must fail closed.
- Current `InvalidOrientedInterval` diagnostics are too coarse to identify the exact remaining branch. Add subtype/context without weakening aggregate failure or assertions.
- Publication counters equal to zero prove only that publication was not reached; they do not prove later exterior, root, orbit, Euler, or topology behavior.
- A complete process that exits normally with test failures is authoritative failure evidence. A clean benchmark process with `success=false` is still a production failure.
- Incomplete local orchestration attempts are not correctness or performance authority; remove their incomplete outputs and identify one exact authoritative run.

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
