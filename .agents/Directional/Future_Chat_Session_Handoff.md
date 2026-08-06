# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

The surface-cell test suite has been reviewed and realigned with
`.agents/Directional/DESIGN.md`.

Current branch head at handoff preparation:

- `d629733c5e3a759e7b68678232b6210016384c91`

The previous default suite mixed the direct surface-paving backend with legacy
mixed-integer integration tests, historical milestone closure tests, detailed
diagnostic/memory accounting tests, and duplicated translation units across
multiple CTest executables. It could therefore report a high aggregate pass
count while every direct production fixture still failed.

The default test configuration now contains only four authoritative targets:

1. `directional_compiled_api_tests`;
2. `directional_surface_cell_producer_tests`;
3. `directional_surface_cell_completion_tests`;
4. `directional_surface_cell_validation_tests`.

The direct producer gate now explicitly requires direct, source-authoritative,
pure-quad `CompletedSurfaceCells` output on:

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

## Files changed

- `CMakeLists.txt` — delegates test configuration to the design-aligned module;
- `cmake/DirectionalTests.cmake` — defines default and opt-in test groups;
- `tests/SurfaceCellDesignAcceptanceTests.cpp` — four direct producer gates;
- `tests/TESTING_STRATEGY.md` — authoritative test-selection and validity rules.

## Verification status

This review turn performed repository inspection and static source validation
only. No CMake configure, compile, test, benchmark, CLI, GUI, or generated
project binary was executed. Compile validity and runtime results are therefore
**not claimed**.

The old R2E16 artifact `8971571147` remains valid only as historical evidence
for source commit `9db5531913195b255ea4c86ad50f609772527604`. It does not contain
the realigned test suite and must not be used to claim current branch-head test
authority.

## Next authoritative turn

The next turn is a **Code + Build compile-only turn** for the test-suite
realignment.

Build exactly:

```text
directional_compiled_api_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
```

Requirements:

1. Configure with `DIRECTIONAL_BUILD_TESTS=ON`.
2. Keep `DIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF`.
3. Keep `DIRECTIONAL_BUILD_LEGACY_INTEGRATION_TESTS=OFF`.
4. Keep `DIRECTIONAL_BUILD_OPTIONAL_GUIDANCE_TESTS=OFF`.
5. Compile and link only; execute no test, benchmark, discovery/listing,
   generated project binary, CLI, or GUI.
6. Package the four executables, required runtime libraries, source snapshot,
   complete benchmark-fixture closure, checksums, and full workflow logs.
7. If compilation fails, make only the minimum test/CMake correction required;
   do not change production implementation in that turn.

After a compile-valid artifact exists, perform an artifact-only Test + Benchmark
turn:

1. Run the four direct design acceptance cases first and report them separately.
2. Run the remaining default producer, completion, validation, and API tests.
3. Do not count demoted test removal as implementation progress.
4. Do not run legacy or historical suites unless a specific failure requires
   targeted comparison.
5. Preserve the first authoritative direct producer failure and use it to plan
   the uniform phase-front producer; do not resume fan-interval micro-repair
   merely because a detailed historical test still exists.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `tests/TESTING_STRATEGY.md`
5. `.agents/Directional/DESIGN.md`
6. `.agents/Directional/REORIENTATION_PLAN.md`
7. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
8. `.agents/Directional/GitHub_Workflow_Policy.md`
9. `turn-based-coding-agent/SKILL.md` and the relevant Code + Build or Test +
   Benchmark references.

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
