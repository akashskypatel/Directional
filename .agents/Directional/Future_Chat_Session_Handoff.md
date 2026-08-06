# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05
**Repository:** `akashskypatel/Directional`
**Base:** `surface_cell_quad`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Current checkpoint

P5-TB40 artifact-only R2E12 Test + Benchmark is complete.

P5-R2E12 is **not accepted**. Runtime behavior is unchanged from P5-TB39:

- exact tested source: `556efab8c26e012a6019e0b0a10fb847fc8e2ace`;
- artifact `8951981127`, SHA-256 `7472441fb8b4f82d7e7bc5a62066a8a3db2022851f72c809bb45244bb1b996f0`;
- manifest **20/20**, package files **21**, recursive submodules **9**, fixtures **26**, source status empty;
- planar and hard rail still reject before successor publication with aggregate `BoundaryFanSectorCoverConflict`;
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
- complete non-overlapping split inventory **597/625**, 28 failures, exact P5-TB39 failure set.

The next turn is **P5-R2E13 authoritative boundary-witness projected exterior-ray evidence Code + Build**. R2 remains open. Do not advance to R2F or R3.

## P5-TB40 focused evidence

- Planar was run three times; byte-identical failure log SHA-256 `f36b6d762047152019b28c6898fd51995530c2337c28cf7aface952f8c4ca33a`.
- Hard rail was run three times; byte-identical failure log SHA-256 `8a4beb40039ae1840df95178648ab46f0c8ef6a338ca230070dc50f23e512e65`.
- Both stop at `incidenceValid == true`; no wrap/Euler or hard-rail orbit/embedding assertions are reached.
- The unchanged assertions expose only the aggregate failure, not `boundaryFanConflict` or its tuple. Do not claim an R2E12 derived subtype/tuple that the packaged runtime did not emit.

## Complete-suite and production evidence

- One full process produced complete XML **597/625** in **71.675 s**, but its wrapper exit/time files were lost; use it only as corroboration.
- A second bounded full process again stopped at the P27 bunny `BEFORE_PIPELINE` marker and was terminated after 180 s. This is nontermination/performance evidence only.
- Authoritative split: **596/623** plus P27 matrix **0/1** plus isolated bunny parameter **1/1** = **597/625**.
- Direct plane: `9 / 9 / 12`, failed completion/output validation.
- Direct seam, close sheets, cylinder, and two completed bunny processes: `0 / 0 / 0`, failed `SideSubdivisionRepair:InvalidInputIncidence`.
- All direct runs used backend `SurfaceCells`, fallback `Fail`, recovery disabled, and no legacy execution.

## Source-supported next producer

R2E12 collects every source-vertex/source-edge fan membership containing each exterior ray and then requires each complete evidence map to have exactly one normalized entity/root entry and both maps to be identical before the explicit exterior record is inserted.

This can reject a valid boundary ray with multiple legitimate fan memberships even though the exact boundary witness already fixes the authoritative loop, side, chart, source entity, and transition root. This is a source-supported inference because the current target assertions do not emit the derived subtype.

P5-R2E13 must:

1. project exterior entity/root authority directly from exact boundary witnesses;
2. reconcile all fan provenance that exactly agrees with that projection;
3. retain unrelated fan memberships for interior authority;
4. fail closed on contradictory claims to the same boundary identity/side;
5. preserve exact generic-pair reconciliation and every publication/orbit gate;
6. add deterministic non-weakening assertion context for the derived failure and tuple.

## Retained authoritative documentation

Only current and durable documents remain under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md`;
2. `Milestone_G_P5_TB40_Artifact_Only_R2E12_Test_Benchmark_Report.md`;
3. `Milestone_G_P5_R2E13_Authoritative_Boundary_Witness_Projected_Exterior_Ray_Evidence_Code_Build_Plan.md`;
4. `DESIGN.md`;
5. `REORIENTATION_PLAN.md`;
6. `Surface_Cell_Backend_Remediation_Plan.md`;
7. `GitHub_Workflow_Policy.md`.

## Retained benchmark results

- `baseline_synthetic_grid_2.json`;
- `p5-tb40-summary.json`.

## Read first for P5-R2E13

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB40_Artifact_Only_R2E12_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E13_Authoritative_Boundary_Witness_Projected_Exterior_Ray_Evidence_Code_Build_Plan.md`
6. `benchmark-results/p5-tb40-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## Lessons from P5-TB40

- A first-class record can still fail before insertion when its authority collector is over-constrained.
- Raw evidence-map cardinality is not ownership authority; exact boundary witnesses must define the projection first.
- Unrelated fan memberships must not be discarded, selected by heuristic, or allowed to veto unrelated authority.
- Artifact-only acceptance must state observability limits when unchanged tests do not emit newly needed derived fields.
- A complete XML without wrapper exit/time is corroborative, not full process-state evidence.
- Repeated P27 bunny stalls remain independent performance/nontermination evidence; never use timeout as correctness.

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
