# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

The design-aligned surface-cell test suite is **compile-valid** and packaged for
an artifact-only Test + Benchmark turn.

Exact source authority:

- source checkpoint: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`;
- `CMakeLists.txt`: `680e1d1fc1cfe6fa7c5ef846bed2d3afc20fb4d2`;
- `cmake/DirectionalTests.cmake`: `9846b5d25e2bec16b77c2f4f658552cc9c4ded82`;
- `tests/SurfaceCellDesignAcceptanceTests.cpp`:
  `6a5faa1a03486720f04907efef6efd78688a0ab9`;
- `tests/TESTING_STRATEGY.md`:
  `cffdf515735d5c76a9a8d3883bac824b35cfca76`.

Compile and package authority:

- workflow event commit: `b412c8f78a7b597b204b52efbb64afc9899d6517`;
- workflow run/job: `31118705108` / `92674426941`;
- build artifact: `8974081923`;
- build artifact SHA-256:
  `4166325a2f38fa17d05d0d7e71cb147760a1e5208a6e971f60c35665bf3671de`;
- build artifact size: **15,128,734 bytes**;
- log artifact: `8974081997`;
- log artifact SHA-256:
  `920eeff4e5909c2661773b845b325579fdd8c40a1dbf9e2be2351ff2760bb69a`;
- log artifact size: **4,726 bytes**;
- compile/link actions: **112/112**;
- recursive submodules: **9/9**;
- packaged fixture/input files: **26/26**;
- internal checksum entries: **49/49**;
- packaged files including checksum manifest: **50**;
- tracked source status: empty.

The artifact contains:

1. `directional_compiled_api_tests`;
2. `directional_surface_cell_producer_tests`;
3. `directional_surface_cell_completion_tests`;
4. `directional_surface_cell_validation_tests`;
5. `directional_benchmarks`;
6. `libdirectional_core.a` and `libdirectional_pipeline.a`;
7. the complete benchmark-fixture closure, exact source archive, compile
   database, logs, source/blob markers, and checksum manifest.

No test, benchmark, custom input, help/list/discovery command, CLI, GUI, or
generated project binary was executed. Compile validity is established; runtime
acceptance is not claimed.

## Test-suite authority

The default test configuration contains only four authoritative targets:

1. `directional_compiled_api_tests`;
2. `directional_surface_cell_producer_tests`;
3. `directional_surface_cell_completion_tests`;
4. `directional_surface_cell_validation_tests`.

The direct producer gate requires direct, source-authoritative, pure-quad
`CompletedSurfaceCells` output on:

```text
plane
→ multi-face seam
→ close sheets
→ cylinder
```

All four cases use `SurfaceCells`, fallback `Fail`, source-grid recovery
disabled, and optional skeleton guidance disabled. These acceptance tests are
expected to expose the current producer failure; they must not be weakened or
made to pass through fallback, recovery, synthetic fixtures, or diagnostic-only
success.

Historical, legacy-integration, and optional-guidance tests remain available
through separate default-off CMake options. No test source was deleted solely
to improve the pass count.

## Current authoritative documents

- `.agents/Directional/Design_Aligned_Test_Suite_Code_Build_Report.md` — exact
  compile/package authority;
- `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Plan.md` —
  next executable turn;
- `tests/TESTING_STRATEGY.md` — test-selection and validity policy;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- this live handoff.

`benchmark-results/p5-r2e16-summary.json` remains only as the latest historical
runtime baseline until the design-aligned artifact-only turn publishes its
replacement. Artifact `8971571147` does not contain the current test suite and
must not be used for current runtime authority.

## Next authoritative turn

Execute the **artifact-only design-aligned Test + Benchmark turn** using artifact
`8974081923` and the exact plan:

`.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Plan.md`

Required order:

1. Verify the outer artifact SHA-256, source/event commits, all 49 internal
   checksums, empty tracked source status, nine submodules, five executables,
   two libraries, and 26 fixture/input files.
2. Run the four direct acceptance cases individually in fresh processes and in
   this order: plane, multi-face seam, close sheets, cylinder.
3. Report those four results separately before any aggregate totals.
4. Run the remaining producer tests, then completion, validation, and API suites
   as a complete non-overlapping default inventory.
5. Run only a bounded benchmark needed to capture the first authoritative
   producer failure; benchmark results cannot substitute for correctness.
6. Do not configure, compile, relink, patch, regenerate, or modify tests,
   fixtures, validators, CMake, workflow logic, or implementation.
7. Produce the next Code + Build plan from the first authoritative direct
   producer failure, following `DESIGN.md`, `REORIENTATION_PLAN.md`, and
   `tests/TESTING_STRATEGY.md`.

Do not resume pair-local fan-interval micro-repair merely because a demoted
historical test remains available.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Design_Aligned_Test_Suite_Code_Build_Report.md`
5. `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Plan.md`
6. `tests/TESTING_STRATEGY.md`
7. `.agents/Directional/DESIGN.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`
11. `turn-based-coding-agent/SKILL.md` and the relevant Test + Benchmark,
    testing-integrity, artifact, status, handoff, and GitHub connector references.

## Durable lessons

- A cross field supplies orientation but not authoritative lattice phase or
  connectivity.
- Arrangement and extraction tests remain necessary, but they cannot substitute
  for a phase-labelled advancing-front producer.
- A high aggregate pass count is misleading when plane, seam, close-sheet, and
  cylinder direct acceptance all fail.
- Diagnostic strings, counters, hashes, cache layouts, memory inventories, and
  milestone numbers are secondary observability contracts, not the primary
  production gate.
- Legacy MIQ/integration tests remain valid for the legacy backend but do not
  establish direct `SurfaceCells` correctness.
- QEx-style sanitation, FlowRep simplification, completion, optimization, and
  topology cleanup are downstream of a coherent producer.
- Tests must reject fallback and source-grid recovery as substitutes for direct
  surface-paving output.
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST` prevents post-build test
  discovery from executing packaged GoogleTest binaries during compile-only
  turns.
- Artifact packaging must ignore the newly created untracked artifact directory
  when checking tracked source cleanliness, and checksum paths must be generated
  relative to the artifact root.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional
Review, and documentation-maintenance turn.

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

Every completed Code + Build, Test + Benchmark, optional Review, or
documentation-maintenance turn ends with a **new top-level PR #8 comment** after
all documentation and PR metadata updates. That comment must be the final
repository write.

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
