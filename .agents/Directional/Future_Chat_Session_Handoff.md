# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-R2E9 canonical boundary wrap-sector and bounded rail-orbit chart publication Code + Build is complete.

- workflow event commit: `29e71770a3c2ff001fa6daa687a2bdf957dd79c4`;
- exact compiled source: `a5b9382c2877ef72a3280ad9dbca2d5b20caaa1c`;
- workflow run/job: `31046039110` / `92441663510`;
- compiled artifact: `8946700183`;
- artifact SHA-256: `bae182ef1e3e5fbbc9fff25ea60a56821e31e4e6fe81787137cdac58f30c6a3a`;
- log artifact: `8946700685`;
- log artifact SHA-256: `03e137c8af8c41a24595ba1176a3e575fe8da34c44c4605d352a2c9629117e37`;
- compile/link actions: **132/132**;
- artifact manifest: **19/19**, package files **20**, recursive submodules **9**, source status empty;
- exact approved targets: `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`;
- no test, benchmark, help/list/discovery command, CLI, GUI, or generated project binary was executed.

R2E9 now enumerates canonical cyclic R1 fan pairs before chart filtering, including vector wrap; excludes the independently proven exterior pair exactly once; publishes only a complete incoming/target bijection; propagates each selected hard-rail chart root through its complete bounded successor orbit; and materializes one authoritative bounded-cell embedding root while retaining full provenance separately. Phase 17 and downstream validators remain unchanged.

The next turn is **P5-TB37 artifact-only R2E9 Test + Benchmark** using artifact `8946700183`. Runtime acceptance is not yet claimed. R2 remains open. Do not advance to R2F or R3.

## Last runtime baseline

The last completed runtime checkpoint is P5-TB36:

- source chart + validator: **17/17**;
- recovery authority: **9/9**;
- feature/barrier: **8/8**;
- graph-dependent: **5/6**, bunny only;
- R2 focused: **13/16**;
- Milestone D: **5/7**;
- Phase 16: **45/47**;
- Phase 17: **26/26**, six natural restorations;
- Phase 18: **57/57**;
- Phase 14–18: **241/244**;
- Phase 20: **46/48**;
- complete suite: **603/625**, 22 failures, wall **72.40 s**, maximum RSS **281,112 KiB**.

At that checkpoint, planar incidence published but no cyclic-wrap interior sector was accepted, Euler remained `0` instead of `1`, and aggregate topology was invalid. Hard rail passed incidence, one-exterior/two-bounded cell count, disk, loop, Euler, ownership, and distinct bounded rail-twin ownership, but failed embedding and aggregate topology. Cylinder and bunny remained independent.

## Retained authoritative documentation

Only current, durable documentation is retained under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_R2E9_Code_Build_Report.md` — exact implementation and compile authority;
3. `Milestone_G_P5_TB37_Artifact_Only_R2E9_Test_Benchmark_Plan.md` — next executable plan;
4. `DESIGN.md` — durable design authority;
5. `REORIENTATION_PLAN.md` — durable reorientation authority;
6. `Surface_Cell_Backend_Remediation_Plan.md` — milestone and remediation authority;
7. `GitHub_Workflow_Policy.md` — remote build and repository-write policy.

Superseded per-turn plans, reports, closure notes, and evidence indexes are removed after replacement. Their historical commit data remains available through Git history and PR #8.

## Retained benchmark results

The minimum current evidence chain under `benchmark-results` is:

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-tb36-summary.json` — latest completed runtime baseline;
- `p5-r2e9-summary.json` — exact compiled-source and package authority for the active source.

Older P5 checkpoint summaries and superseded runtime snapshots are removed after their current conclusions are carried into this handoff and the active trackers.

## Read first for P5-TB37

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_R2E9_Code_Build_Report.md`
5. `.agents/Directional/Milestone_G_P5_TB37_Artifact_Only_R2E9_Test_Benchmark_Plan.md`
6. `benchmark-results/p5-r2e9-summary.json`
7. `benchmark-results/p5-tb36-summary.json`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB37 objective

1. Download artifact `8946700183` and verify archive SHA-256 plus all 19 internal manifest entries.
2. Execute only packaged binaries; do not configure, rebuild, relink, patch, regenerate, or modify source/tests/fixtures/validators/workflows.
3. Run source-chart and source-authoritative validator prerequisites first.
4. Run the focused R2 set and prove planar positive canonical pair inventory, exact exterior exclusion, positive cyclic-wrap count, Euler-one disk topology, and unchanged aggregate validation—or record the earliest typed failure.
5. Prove one complete authoritative chart root per hard-rail bounded orbit, distinct roots on opposite sides, valid bounded-cell embedding, and valid aggregate topology—or record the earliest typed failure.
6. Preserve degree-two, genuine four-disk, source-row, whole-orientation, pinched-fan, close-sheet, bridge/support, nested, nonmanifold, and Phase 17 **26/26** authority.
7. Run Milestone D, Phase 16, Phase 17, Phase 18, Phase 14–18, Phase 20, graph-dependent, and complete-suite scopes.
8. Run deterministic direct production processes only after focused regressions, with fallback `Fail`, source-grid recovery disabled, and no legacy execution.
9. Produce the next Code + Build plan from the earliest remaining authoritative producer.

## Lessons from P5-R2E8

- Generated whole-file transformations can hide a one-brace scope error even when the intended semantic change is narrow. Inspect the exact transformed hunk and compile before treating the source commit as authoritative.
- Large base64 workflow payloads are fragile when transferred through repository writes. Prefer a bounded inline transformation with exact pre-image blob checks, one-file scope verification, `git diff --check`, and a compile-only gate.
- Build-orchestration failures are not implementation acceptance evidence. Preserve their logs, correct the mechanism narrowly, and claim only the final verified source/artifact.
- The final successful workflow must push the exact compiled source commit before building, then package that same commit and record both workflow-event and source authority.

## Lessons from P5-TB36

- A producer can pass the typed local incidence gate while still publishing the wrong global cell topology. Planar must be judged by the derived cyclic-wrap inventory and Euler-one closure, not incidence validity alone.
- Enumerating consecutive rays after chart filtering is not equivalent to enumerating the authoritative cyclic R1 fan pairs. The wrap relation must exist in the canonical fan inventory before chart-corner resolution.
- Hard-rail provenance may legitimately contain both incident charts, while one bounded directed orbit requires one authoritative embedding root. Preserve full provenance and publish selected orbit support as distinct concepts.
- R2E8 restored all six Phase 17 failures without changing Phase 17. Preserve that upstream improvement and do not patch downstream tests or implementation.
- A green benchmark process exit only means the benchmark harness wrote a result; each direct case still reports `success=false` and must remain classified as failed production output.

## Lessons from P5-R2E9

- GitHub contents writes preserve exactly the supplied text; omitting one final newline changes the payload SHA-256 even when base64 decoding would yield identical bytes. Verify the repository blob's exact digest before triggering a bounded workflow.
- The first R2E9 workflow failed at the payload precondition before applying source changes. Its log is infrastructure evidence only; the successful run and exact compiled source are the only compile authority.
- Canonical topology inventory and chart witness resolution must remain separate stages. Chart evidence can validate a canonical pair but must not decide which canonical pairs exist.
- A hard-rail root is authoritative only after the complete bounded orbit closes and every directed halfedge supports the same root. Do not publish partial-orbit evidence.

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
