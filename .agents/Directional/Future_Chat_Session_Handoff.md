# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05
**Repository:** `akashskypatel/Directional`
**Base:** `surface_cell_quad`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Current checkpoint

P5-R2E13 authoritative boundary-witness projected exterior-ray evidence Code + Build is complete and compile-valid.

- workflow event commit: `45a4c1031cccd3e814b2cf8e24209662dbfdae87`;
- exact compiled source: `39b60e66d72f412c1d648ffef213beca93bd19dc`;
- workflow run/job: `31064914809` / `92500525659`;
- build artifact: `8953600942`;
- build artifact SHA-256: `9144cde751377199a8df135ac0871e75e65c44b5d8efce07ea42a0732ae6f7d1`;
- build artifact size: **12,295,987 bytes**;
- log artifact: `8953601264`;
- log artifact SHA-256: `6fd241cb97616e7a349e427f1130373d5b7e1e212eb63f56b3eea0e196e836ba`;
- compile/link actions: **132/132**;
- manifest: **20/20**; package files: **21**; recursive submodules: **9**; source status empty;
- built exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- no test, benchmark, custom input, help/list/discovery command, CLI, GUI, or generated project binary was executed.

R2E13 projects exterior chart/entity/root/loop/side authority from exact boundary witnesses before fan reconciliation. A fan identity contributes exterior provenance only when the exact directed witness occupies that projected chart and resolves to the same normalized entity/root. Unrelated memberships remain available for interior authority. Contradictions on the projected chart fail closed.

The two target assertions retain their original acceptance criteria and now append deterministic boundary-fan diagnostic context on failure.

The next turn is **P5-TB41 artifact-only R2E13 Test + Benchmark** using artifact `8953600942`. Runtime acceptance is not yet claimed. R2 remains open. Do not advance to R2F or R3.

## Exact implementation authority

Production blob:

- `src/geometry/SurfaceArrangement.cpp`: `afeb0f1931ee80fdb0d617be9e5bece02fa179b6`.

Focused diagnostic-test blobs:

- `tests/SurfaceArrangementPhase16Tests.cpp`: `de5b7c4f3d7c53f8488bc7de5d883ac72429e894`;
- `tests/MilestoneDClosureTests.cpp`: `1625b8139a9da8e2a6cfddd1bb026ae69ba47ed2`.

Unchanged public header:

- `include/directional/geometry/SurfaceArrangement.h`: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`.

Patch SHA-256: `b2a068ba41b0a170d227c2320921ccc3cf6a94883803fba6b06b3a7e87947094`.

## P5-R2E13 behavior

1. `BoundarySubsegmentWitness` retains resolved source component and sheet.
2. Canonical boundary-witness identity includes component and sheet.
3. Stored and resolved boundary chart provenance must agree exactly; disagreement remains fail-closed.
4. Exact exterior source and target witnesses project chart, normalized entity, transition root, loop, and side.
5. Source and target projections must agree on normalized entity/root, authoritative loop, and exact `+1/-1` sides.
6. Fan provenance is accepted only from the same projected chart with the same normalized entity/root.
7. Unrelated fan memberships do not veto the exterior projection and remain available for independent interior pairs.
8. A conflicting claim on the projected chart is a deterministic contradiction, not a candidate for heuristic selection.
9. The explicit exterior record still reconciles with any generic exact-key contribution and is excluded exactly once.
10. Pair-cover, predecessor, separator, complete-orbit, embedding, disk, Euler, orientation, area, ownership, and aggregate topology gates remain unchanged.

## Last runtime baseline

P5-TB40 against R2E12 remains the runtime authority:

- source chart + validator: **17/17**;
- recovery authority: **9/9**;
- feature/barrier: **8/8**;
- graph-dependent: **5/6**;
- R2 focused: **13/16**;
- Milestone D: **5/7**;
- Phase 16: **45/47**;
- Phase 17: **20/26**;
- Phase 18: **57/57**;
- Phase 14–18: **235/244**;
- Phase 20: **46/48**;
- complete non-overlapping split inventory: **597/625**, 28 failures.

Planar and hard rail still stopped before successor publication with aggregate `BoundaryFanSectorCoverConflict`. Their R2E12 assertions did not expose the derived subtype or tuple. R2E13's non-weakening context must make the exact first remaining producer observable if the aggregate failure persists.

A bounded single-process full suite again stalled when P27 entered the bunny case after prior suite state. This is separate performance/nontermination evidence, not correctness evidence.

## Retained authoritative documentation

Only current and durable documents must remain under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_R2E13_Code_Build_Report.md` — exact implementation and compile authority;
3. `Milestone_G_P5_TB41_Artifact_Only_R2E13_Test_Benchmark_Plan.md` — next executable plan;
4. `DESIGN.md` — durable design authority;
5. `REORIENTATION_PLAN.md` — durable reorientation authority;
6. `Surface_Cell_Backend_Remediation_Plan.md` — milestone and remediation authority;
7. `GitHub_Workflow_Policy.md` — remote build and repository-write policy.

Superseded per-turn plans, reports, closure notes, and summaries are removed after replacement. Git history and PR #8 retain historical authority.

## Retained benchmark results

Only current or durable result files remain under `benchmark-results`:

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-r2e13-summary.json` — exact source/package authority and retained P5-TB40 runtime baseline.

## Read first for P5-TB41

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_R2E13_Code_Build_Report.md`
5. `.agents/Directional/Milestone_G_P5_TB41_Artifact_Only_R2E13_Test_Benchmark_Plan.md`
6. `benchmark-results/p5-r2e13-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB41 objective

1. Verify artifact `8953600942`, its exact digest, all 20 manifest entries, source/header/test blobs, fixture closure, submodules, and clean source status.
2. Execute only packaged binaries; do not configure, rebuild, relink, patch, regenerate, or modify implementation/tests/fixtures/validators/workflows.
3. Run planar and hard rail at least three independent times and retain the full enhanced diagnostic context.
4. Determine whether exact boundary-witness projection now inserts and excludes one exterior record per boundary-fan node.
5. Require all non-exterior pairs to receive exactly one authoritative chart witness with complete incoming/target cover.
6. Determine whether planar reaches genuine wrap publication, Euler `1`, and valid aggregate topology.
7. Determine whether hard rail reaches distinct complete-orbit roots and valid embedding/topology.
8. Restore Phase 17 **26/26** without Phase 17 changes and preserve all accepted authority groups.
9. Record the P27/bunny cumulative-state stall separately from correctness and use a complete split inventory if a single process does not terminate normally.
10. Run direct analytic and bunny production processes with fallback `Fail`, source-grid recovery disabled, and no legacy execution.
11. Produce the next Code + Build plan from the earliest remaining authoritative producer.

## Lessons from P5-R2E13

- Boundary provenance must carry enough chart identity to distinguish source component and sheet before entity/root authority is projected.
- An exact boundary witness can define ownership authority while broader fan memberships remain valid evidence for other interior relations.
- Reconciliation means proving agreement with projected authority; it does not mean selecting a convenient subset from conflicting evidence.
- A contradictory claim on the same projected chart is materially different from an unrelated membership on another chart.
- Diagnostic context can be strengthened without weakening an assertion or changing its acceptance semantics.
- Transfer-integrity failures before patch application are infrastructure failures only; correct the transport narrowly and preserve the intended patch and postimage authority.
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
