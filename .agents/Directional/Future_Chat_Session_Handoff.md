# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB35 artifact-only validation is complete against exact source `31c8d9a212f649df7c70fe9291d1fac8c4db7132` and artifact `8938299309`.

- complete suite: **597/625**;
- R2 focused: **13/16**;
- Phase 16: **45/47**;
- Phase 17: **20/26**;
- Phase 18: **57/57**;
- exact failure set unchanged from P5-TB34;
- hard-rail failure narrowed to `embeddingValid`/aggregate `topologyValid` only;
- planar boundary node still fails `BoundaryFanSectorCoverConflict` before publication.

The next turn is **P5-R2E8 canonical boundary corner-sector and rail-chart embedding Code + Build**. Do not advance to R2F or R3.

## Retained authoritative documentation

Only current, durable documentation is retained under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_TB35_Artifact_Only_R2E7_Test_Benchmark_Report.md` — latest runtime evidence and producer diagnosis;
3. `Milestone_G_P5_R2E8_Canonical_Boundary_Corner_Sector_Code_Build_Plan.md` — next executable plan;
4. `DESIGN.md` — durable design authority;
5. `REORIENTATION_PLAN.md` — durable reorientation authority;
6. `Surface_Cell_Backend_Remediation_Plan.md` — milestone and remediation authority;
7. `GitHub_Workflow_Policy.md` — remote build and repository-write policy.

Superseded per-turn plans, reports, closure notes, and evidence indexes were removed in the documentation-retention cleanup. Their historical commit data remains available through Git history and PR #8.

## Retained benchmark results

Only current or durable result files are retained under `benchmark-results`:

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-r2e7-summary.json` — exact compiled-source/package authority for the active source;
- `p5-tb35-summary.json` — latest runtime summary.

All older P5 checkpoint summaries and superseded test-result snapshots were removed.

## Read first for P5-R2E8

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB35_Artifact_Only_R2E7_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E8_Canonical_Boundary_Corner_Sector_Code_Build_Plan.md`
6. `benchmark-results/p5-tb35-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E8 objective

1. Construct the complete boundary-node cover directly from cyclic adjacent R1 corner records.
2. Remove exactly the independently proven exterior pair.
3. Require one authoritative sector per incoming halfedge and outgoing target without arbitrary selection.
4. Derive both hard-rail sides from exact incident source-face/chart corners.
5. Prove a common chart and ownership root for each predicted bounded rail-side orbit.
6. Preserve the passing degree-two and genuine four-disk paths.
7. Leave Phase 17 and all downstream topology validators unchanged.
8. Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`; execute no project binary.

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
