# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2E14 two-sided exterior-root authority and chart-seam interval normalization Code + Build is complete and compile-valid.

- workflow event commit: `c35fd7a4ca44946a233be4e18f175d4aa88bc03d`;
- exact compiled source: `2a8b9870b8e3854ae77a7e4eeae6da29a7899968`;
- workflow run/job: `31077891125` / `92539833523`;
- build artifact: `8958361834`, SHA-256 `1f2607859ecf84d2cb82597f2c4f8f9341491df62d99b694510241f8df719db6`, size **12,307,622 bytes**;
- log artifact: `8958362185`, SHA-256 `d7b499c3a9a69a6702ca96bff4dd1b3241f7db2051113d88b05320165e9323cb`;
- compile/link actions: **132/132**;
- manifest: **20/20**; package files: **21**; recursive submodules: **9**; source status empty;
- built exactly `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- no test, benchmark, custom input, help/list/discovery command, CLI, GUI, or generated project binary was executed.

R2E14 retains endpoint-specific exterior source/target chart roots and sides while preserving one common normalized boundary entity. The two excluded exterior roots may differ across an authoritative hard rail and are not interior bounded-orbit root authority. Non-exterior pairs continue to require exactly one common root.

For an already-authoritative non-exterior pair, chart geometry now uses the complete raw-angle circular inventory. A wrap is published only for unique exact seam adjacency; ambiguous angular positions, non-adjacency, third-ray intrusion, non-positive spans, and spans outside the chart wedge fail closed. Chart-local evidence cannot create or choose pair ownership.

The next turn is **P5-TB42 artifact-only R2E14 Test + Benchmark** using artifact `8958361834`. Runtime acceptance is not yet claimed. R2 remains open. Do not advance to R2F or R3.

## Exact implementation authority

- `src/geometry/SurfaceArrangement.cpp`: `bea11b3b24149c552e3569669d170419532f527e`;
- unchanged `include/directional/geometry/SurfaceArrangement.h`: `b9ed2d969b7de2d4df9639d53ff2e9b35e3475d8`;
- unchanged `tests/SurfaceArrangementPhase16Tests.cpp`: `de5b7c4f3d7c53f8488bc7de5d883ac72429e894`;
- unchanged `tests/MilestoneDClosureTests.cpp`: `1625b8139a9da8e2a6cfddd1bb026ae69ba47ed2`;
- patch SHA-256: `c09ce5e87b4ab7e9a23cdcd2dde6bec05cdd9a62f983917526df1471b3e5dfa1`.

## Last runtime baseline: P5-TB41

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
- complete non-overlapping split inventory **597/625**, 28 failures.

Planar had already inserted three canonical pairs and excluded one exterior pair, then failed `InvalidOrientedInterval(8)` at tuple `3/5/4/9` with zero wraps. Hard rail failed `ExteriorPairMismatch(2)` at tuple `1/7/6/1` before canonical-pair insertion. P5-TB42 must prove exact progression or report the first newly observable producer.

A bounded single-process full suite again stopped when P27 entered bunny after prior suite state. This remains separate performance/nontermination evidence, never correctness evidence.

## Retained authoritative documentation

Only current and durable documents must remain under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_R2E14_Code_Build_Report.md` — implementation and compile authority;
3. `Milestone_G_P5_TB42_Artifact_Only_R2E14_Test_Benchmark_Plan.md` — next executable plan;
4. `DESIGN.md`;
5. `REORIENTATION_PLAN.md`;
6. `Surface_Cell_Backend_Remediation_Plan.md`;
7. `GitHub_Workflow_Policy.md`.

Superseded per-turn plans, reports, closure notes, and summaries are removed after their replacements are verified. Git history and PR #8 retain historical authority.

## Retained benchmark results

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-r2e14-summary.json` — exact source/package authority and retained P5-TB41 runtime baseline.

## Read first for P5-TB42

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_R2E14_Code_Build_Report.md`
5. `.agents/Directional/Milestone_G_P5_TB42_Artifact_Only_R2E14_Test_Benchmark_Plan.md`
6. `benchmark-results/p5-r2e14-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB42 first actions

1. Download artifact `8958361834` through the GitHub connector and verify outer digest `1f2607859ecf84d2cb82597f2c4f8f9341491df62d99b694510241f8df719db6`.
2. Verify all internal manifest entries, exact source/event commits, production/header/test blobs, empty source status, nine recursive submodules, and executable-relative fixture closure.
3. Extract into an arbitrary clean directory and execute only packaged binaries; do not configure, compile, relink, patch, or regenerate.
4. Run source-chart/validator prerequisites first.
5. Run planar and hard rail in at least three independent processes, retaining full deterministic diagnostics.
6. Apply the exact gates in `.agents/Directional/Milestone_G_P5_TB42_Artifact_Only_R2E14_Test_Benchmark_Plan.md`.
7. Treat any cumulative-state P27/bunny stop separately and use a complete non-overlapping split inventory if needed.
8. Produce the next Code + Build plan from the first authoritative remaining producer; review remains skipped.

## Lessons from P5-R2E14

- The excluded exterior continuation is a two-sided boundary relation; forcing its endpoint charts to share one root destroys valid hard-rail separation.
- Exterior endpoint roots must be retained as provenance but must not be reused as interior complete-orbit authority.
- Non-exterior ownership still requires one exact common root; the two-sided exception is limited to the excluded exterior relation.
- Raw fan-vector index is not circular chart-seam authority. Unique raw-angle adjacency on the matched chart is required.
- Chart-local evidence resolves geometry only after canonical pair existence and ownership are established.
- A temporary transfer fragment that is deleted before any bounded workflow executes carries no source, build, or runtime authority.
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
