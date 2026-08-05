# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB37 artifact-only R2E9 Test + Benchmark is complete against compiled source `a5b9382c2877ef72a3280ad9dbca2d5b20caaa1c` and artifact `8946700183`.

- source chart + validator **17/17**; recovery **9/9**; feature/barrier **8/8**;
- graph-dependent **5/6**, bunny only; core R2E9 producers **0/3**;
- R2 focused **13/16**; Milestone D **5/7**; Phase 16 **45/47**;
- Phase 17 **20/26**, six regressions from R2E8; Phase 18 **57/57**;
- Phase 14–18 **235/244**; Phase 20 **46/48**;
- complete suite **597/625**, 28 failures, XML **70.736 s**, wall **70.74 s**, maximum RSS **281,668 KiB**;
- exact failure set: P5-TB36's 22 failures plus the six regressed Phase 17 tests.

R2E9 is not accepted. Planar and hard rail both regress to `BoundaryFanSectorCoverConflict` before successor publication. The unchanged R2 focused count hides an earlier producer failure. The six Phase 17 tests naturally restored by R2E8 fail again from invalid upstream arrangements.

The next turn is **P5-R2E10 canonical wrap-pair chart-witness and unique boundary fan-cover reconciliation Code + Build**. R2 remains open. Do not advance to R2F or R3.

## Evidence authority

- artifact ID `8946700183`, SHA-256 `bae182ef1e3e5fbbc9fff25ea60a56821e31e4e6fe81787137cdac58f30c6a3a`;
- exact source `a5b9382c2877ef72a3280ad9dbca2d5b20caaa1c`;
- workflow event commit `29e71770a3c2ff001fa6daa687a2bdf957dd79c4`;
- `SurfaceArrangement.cpp` blob `fec7b37c0692a0e23d28727d8fad60215bd7fa6c`;
- manifest **19/19**, package files **20**, staged fixtures **26**, recursive submodules **9**;
- evidence archive `directional-p5-tb37-8946700183-evidence.zip`, SHA-256 `246debf82198c5369c27975886d30ce38dbd3a3d8c21ad46325dd1cfa022c614`;
- artifact-only: no configure, rebuild, relink, patch, regeneration, or repository source/test/fixture/validator/workflow modification.

Two independent bunny processes are structurally identical and fail closed at `completion` with `SideSubdivisionRepair:InvalidInputIncidence`, zero arrangement cells, and zero quads in 22.999296 s and 22.519749 s.

## Retained authority

Under `.agents/Directional`, retain only:

1. `Future_Chat_Session_Handoff.md`;
2. `Milestone_G_P5_TB37_Artifact_Only_R2E9_Test_Benchmark_Report.md`;
3. `Milestone_G_P5_R2E10_Canonical_Wrap_Pair_Chart_Witness_Fan_Cover_Code_Build_Plan.md`;
4. `DESIGN.md`;
5. `REORIENTATION_PLAN.md`;
6. `Surface_Cell_Backend_Remediation_Plan.md`;
7. `GitHub_Workflow_Policy.md`.

Under `benchmark-results`, retain only `baseline_synthetic_grid_2.json` and `p5-tb37-summary.json`. Git history and PR #8 are the historical archive.

## Read first for P5-R2E10

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB37_Artifact_Only_R2E9_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E10_Canonical_Wrap_Pair_Chart_Witness_Fan_Cover_Code_Build_Plan.md`
6. `benchmark-results/p5-tb37-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E10 objective

1. Build one normalized node-level canonical boundary pair inventory keyed by directed incidence before chart resolution.
2. Reconcile equivalent fan-identity records only when canonical source-entity, chart, and transition-root evidence agree; fail closed on conflicts.
3. Resolve canonical wrap pairs in one continuous exact chart-corner interval, including the required `2*pi` lift where appropriate.
4. Identify and exclude the independently proven exterior relation exactly once.
5. Require exactly one agreeing chart/root witness for each non-exterior pair and publish only a complete incoming/target bijection.
6. Retain the R2E9 complete hard-rail bounded-orbit root audit and authoritative embedding-root materialization.
7. Restore planar and hard-rail valid incidence and the six Phase 17 tests without Phase 17 changes.
8. Preserve all accepted R2, recovery, feature/barrier, permutation, close-sheet, bridge/support, nested, and nonmanifold authority.
9. Leave cylinder, bunny, FlowRep, completion, optimizer, fallback/recovery, fixtures, memory, and downstream validators unchanged.
10. Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`; execute no project binary.

## Lessons to preserve

- Compare the first typed failure and reached assertions, not only pass totals; P5-TB37 proves an unchanged count can conceal a producer regression.
- Canonical topology inventory and chart-witness resolution are separate stages. Charts validate canonical pairs but do not create or remove them.
- A canonical wrap requires one continuous exact chart-corner interval; scalar angle order alone is insufficient.
- A hard-rail root is authoritative only after the complete bounded orbit closes and every directed halfedge supports the same root.
- The six Phase 17 regressions are invalid-upstream-input consequences. Do not modify Phase 17 to compensate.
- A green benchmark process exit with `success=false` remains a production failure.
- Separate orchestration/infrastructure failures from product evidence; retain only the complete authoritative run.
- Build workflows must push and package the exact compiled source and preserve detailed logs. Verify exact payload and blob digests before triggering them.

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
