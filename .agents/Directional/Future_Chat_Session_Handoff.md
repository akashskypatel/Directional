# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-05  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB36 artifact-only R2E8 Test + Benchmark is complete against compiled source `478d058ab2060a1a02a1e4ca3bfc0e6625fa8047` and artifact `8944910920`.

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
- complete suite: **603/625**, 22 failures, XML **72.397 s**, wall **72.40 s**, maximum RSS **281,112 KiB**;
- exact failure set: P5-TB35 minus the six restored Phase 17 tests, with no new failures.

R2E8 is not accepted. Planar now publishes incidence and reaches unchanged topology validators, but has no accepted cyclic-wrap interior sector and closes Euler `0` instead of `1`. Hard rail retains its passing incidence, ownership, disk, loop, Euler, and cell-count authority but still fails embedding and aggregate topology.

The next turn is **P5-R2E9 canonical boundary wrap-sector and bounded rail-orbit chart publication Code + Build**. Do not advance to R2F or R3.

## Evidence authority

- artifact SHA-256: `5b93e86db0ddccf4ca3eba2e9b53e6523f02d7ef70809aa8eb67b91f6e9bef39`;
- `SurfaceArrangement.cpp` blob: `76e57fef36f9322598387b6b5e968a14b885b755`;
- workflow run: `31041383154`;
- evidence archive: `directional-p5-tb36-8944910920-evidence.zip`;
- evidence SHA-256: `af3747b1238a01802a4fc158032451a505cbeb224c51601d888e390b6fd01096`;
- artifact-only: no configure, rebuild, relink, patch, regeneration, or repository source/test/fixture/validator/workflow modification.

Two independent direct bunny processes are structurally identical. They fail closed at `completion` with `SideSubdivisionRepair:InvalidInputIncidence`, zero arrangement cells, and zero output quads in 24.995377 s and 25.475514 s.

## Retained authoritative documentation

Only current, durable documentation is retained under `.agents/Directional`:

1. `Future_Chat_Session_Handoff.md` — this live entry point;
2. `Milestone_G_P5_TB36_Artifact_Only_R2E8_Test_Benchmark_Report.md` — latest runtime evidence and producer diagnosis;
3. `Milestone_G_P5_R2E9_Canonical_Wrap_Sector_Rail_Orbit_Chart_Code_Build_Plan.md` — next executable plan;
4. `DESIGN.md` — durable design authority;
5. `REORIENTATION_PLAN.md` — durable reorientation authority;
6. `Surface_Cell_Backend_Remediation_Plan.md` — milestone and remediation authority;
7. `GitHub_Workflow_Policy.md` — remote build and repository-write policy.

Superseded per-turn plans, reports, closure notes, and evidence indexes are removed after replacement. Their historical commit data remains available through Git history and PR #8.

## Retained benchmark results

Only current or durable result files are retained under `benchmark-results`:

- `baseline_synthetic_grid_2.json` — durable baseline;
- `p5-tb36-summary.json` — latest runtime and exact source/artifact authority.

Older P5 checkpoint summaries and superseded runtime snapshots are removed after their current conclusions are carried into this handoff and the active trackers.

## Read first for P5-R2E9

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Milestone_G_P5_TB36_Artifact_Only_R2E8_Test_Benchmark_Report.md`
5. `.agents/Directional/Milestone_G_P5_R2E9_Canonical_Wrap_Sector_Rail_Orbit_Chart_Code_Build_Plan.md`
6. `benchmark-results/p5-tb36-summary.json`
7. `.agents/Directional/REORIENTATION_PLAN.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-R2E9 objective

1. Enumerate every canonical cyclic adjacent R1 fan pair before chart filtering, including vector wrap.
2. Resolve each pair to exactly one authoritative chart corner and exclude the independently proven exterior pair once.
3. Restore planar cyclic-wrap evidence and Euler-one disk topology without arbitrary selection.
4. Propagate each accepted hard-rail chart root through its complete predicted bounded orbit.
5. Publish the selected orbit root as authoritative bounded-cell embedding support while retaining full provenance separately.
6. Preserve degree-two, genuine four-disk, row-order, orientation, pinched-fan, close-sheet, bridge/support, nested, nonmanifold, and Phase 17 **26/26** authority.
7. Leave cylinder, bunny, FlowRep, completion, optimizer, fallback/recovery, memory, and downstream validators unchanged.
8. Compile only `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks`; execute no project binary.

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
