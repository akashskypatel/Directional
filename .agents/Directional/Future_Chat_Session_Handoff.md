# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05
**Repository:** `akashskypatel/Directional`
**Base:** `surface_cell_quad`
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`
**Draft PR:** #8 — keep open, draft, and unmerged
**Review policy:** `never`

## Current checkpoint

P5-R2E12 normalized authoritative exterior-pair inventory Code + Build is complete and compile-valid.

- workflow event commit: `50d5db4280a5008764f73e5ba0a1827ce63eab1e`;
- exact compiled source: `556efab8c26e012a6019e0b0a10fb847fc8e2ace`;
- workflow run/job: `31060329035` / `92486695630`;
- build artifact: `8951981127`;
- build artifact SHA-256: `7472441fb8b4f82d7e7bc5a62066a8a3db2022851f72c809bb45244bb1b996f0`;
- log artifact: `8951981453`;
- log artifact SHA-256: `5a8731736441dae7a9a869f8854178071c0588640e2a3f94139c4c917167b3a6`;
- compile/link actions: **132/132**;
- manifest: **20/20**; package files: **21**; recursive submodules: **9**;
- built exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- no test, benchmark, custom input, help/list/discovery command, CLI, GUI, or generated project binary was executed.

R2E12 inserts one explicit normalized authoritative exterior pair before generic pair enumeration, proves its source-boundary loop identity and directed side evidence, reconciles normalized entity/root authority across both rays, and excludes the explicit record once from interior chart-corner witness resolution. All complete-cover, predecessor, separator, and bounded-orbit audits remain fail-closed and transactional.

The next turn is **P5-TB40 artifact-only R2E12 Test + Benchmark** using artifact `8951981127`. Runtime acceptance is not yet claimed. R2 remains open. Do not advance to R2F or R3.

## Last runtime baseline

P5-TB39 against R2E11 remains the runtime authority:

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

At P5-TB39:

- planar failed `BoundaryFanSectorCoverConflict / ExteriorPairMismatch`, tuple `3/11/10/9`;
- interior hard rail failed the same aggregate/derived failure, tuple `1/7/6/1`;
- two single-process full-suite attempts stalled when P27 entered the bunny case after prior suite state; this is separate nontermination/performance evidence, not correctness evidence.

## Retained authoritative documentation

Only current, durable documentation is retained under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_R2E12_Code_Build_Report.md` — exact implementation and compile authority;
3. `Milestone_G_P5_TB40_Artifact_Only_R2E12_Test_Benchmark_Plan.md` — next executable plan;
4. `DESIGN.md` — durable design authority;
5. `REORIENTATION_PLAN.md` — durable reorientation authority;
6. `Surface_Cell_Backend_Remediation_Plan.md` — milestone and remediation authority;
7. `GitHub_Workflow_Policy.md` — remote build and repository-write policy.

Superseded per-turn plans, reports, closure notes, and summaries are removed after replacement. Git history and PR #8 retain historical authority.

## Retained benchmark results

Only current or durable result files are retained under `benchmark-results`:

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-r2e12-summary.json` — exact compiled-source/package authority and retained P5-TB39 runtime baseline.

## Read first for P5-TB40

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_R2E12_Code_Build_Report.md`
5. `.agents/Directional/Milestone_G_P5_TB40_Artifact_Only_R2E12_Test_Benchmark_Plan.md`
6. `benchmark-results/p5-r2e12-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB40 objective

1. Verify artifact `8951981127`, its exact digest, all 20 manifest entries, source/test blobs, fixture closure, submodules, and clean source status.
2. Execute only packaged binaries; do not configure, rebuild, relink, patch, regenerate, or modify implementation/tests/fixtures/validators/workflows.
3. Repeat planar and hard-rail diagnostics and determine whether their P5-TB39 `ExteriorPairMismatch` tuples are removed.
4. Require exactly one explicit authoritative exterior pair and exclusion per boundary-fan node.
5. Determine whether planar reaches genuine wrap publication, Euler `1`, and valid aggregate topology.
6. Determine whether hard rail reaches distinct complete-orbit roots and valid embedding/topology.
7. Restore Phase 17 **26/26** without Phase 17 changes and preserve all accepted authority groups.
8. Record the P27/bunny cumulative-state stall separately from correctness and use a complete split inventory if a single-process suite does not terminate normally.
9. Run direct analytic and bunny production processes with fallback `Fail`, source-grid recovery disabled, and no legacy execution.
10. Produce the next Code + Build plan from the earliest remaining authoritative producer.

## Lessons from P5-R2E8

- Generated whole-file transformations can hide a one-brace scope error even when the intended semantic change is narrow. Inspect the exact transformed hunk and compile before treating the source commit as authoritative.
- Large base64 workflow payloads are fragile when transferred through repository writes. Prefer a bounded transformation with exact pre-image/post-image checks and a compile-only gate.
- Build-orchestration failures are not implementation acceptance evidence. Preserve their logs, correct the mechanism narrowly, and claim only the final verified source/artifact.
- The successful workflow must push the exact compiled source commit before building and package that same commit.

## Lessons from P5-TB36 through P5-TB39

- Compare first failure stage and derived diagnostics, not only pass totals.
- Canonical topology inventory and chart witness resolution must remain separate; charts validate pairs but do not define pair existence.
- Normalize equivalent fan identities once and use the same ownership contract end to end; exact identity variants remain provenance.
- The exterior continuation is independent source-boundary topology and must not be inferred from chart ordering.
- A wrap witness is an oriented interval problem and must reject intervening rays.
- Hard-rail bounded support is authoritative only after a complete orbit closes with one root on every directed halfedge and distinct roots on opposite sides.
- The six Phase 17 regressions are upstream arrangement consequences; do not patch Phase 17.
- Aggregate failures need deterministic derived subreasons without weakening fail-closed semantics.
- Timeout or wrapper interruption is not correctness evidence. Preserve it separately as infrastructure or nontermination/performance evidence.

## Lessons from P5-R2E12

- An independently proven exterior relation must be represented explicitly in the same canonical inventory that is later audited; requiring generic fan enumeration to rediscover it is not equivalent.
- Source-boundary loop identity and directed side witnesses provide exterior ownership evidence that interior chart corners cannot supply.
- Exterior ray authority must be reconciled through a unique normalized entity/root pair on both rays; never choose among conflicting authorities by order or frequency.
- Explicit record state is safer than re-inferring exterior ownership from map-key equality at later stages.
- Self-removing bounded workflows keep the exact source commit free of turn-specific execution infrastructure while still pushing source before compilation.
- For documentation-only cleanup, prefer direct GitHub connector writes over large encoded workflow payloads; repeated payload transport failures did not affect source or build authority in this turn.

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
