# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

The **Design-Aligned Artifact-Only Test + Benchmark** turn is complete.

Artifact `8974081923` was executed directly from exact source `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`. No configure, compile, relink, patch, regeneration, source edit, test edit, fixture edit, validator edit, CLI, or GUI operation occurred.

Package authority:

- workflow event commit: `b412c8f78a7b597b204b52efbb64afc9899d6517`;
- workflow run/job: `31118705108` / `92674426941`;
- build artifact: `8974081923`;
- artifact location: `https://github.com/akashskypatel/Directional/actions/runs/31118705108/artifacts/8974081923`;
- artifact SHA-256: `4166325a2f38fa17d05d0d7e71cb147760a1e5208a6e971f60c35665bf3671de`;
- log artifact: `8974081997`;
- log artifact location: `https://github.com/akashskypatel/Directional/actions/runs/31118705108/artifacts/8974081997`;
- internal checksums: **49/49**;
- recursive submodules: **9/9**;
- packaged fixture/input files: **26/26**;
- tracked source status: empty.

## Direct acceptance result

All four direct `SurfaceCells` cases used fallback `Fail`, source-grid recovery disabled, no fallback attempt, no remesh output, and output origin `None`.

| Fixture | Result | Terminal | Traces | Arrangement | Quads |
|---|---:|---|---:|---:|---:|
| Plane | failed | `NotProductionReady/completion` | 106 | 9 | 12 |
| Multi-face seam | failed | `NotProductionReady/completion` | 137 | 0 | 0 |
| Close sheets | failed | `NotProductionReady/completion` | 158 | 0 | 0 |
| Cylinder | failed | `NotProductionReady/completion` | 732 | 0 | 0 |

The plane is the first authoritative producer failure. It produced nine arrangement cells and twelve completed quads, then failed before optimization at:

```text
completion/output-validation:AggregateCompletionValidationFailure
```

The completion validation failure count is **15**.

Multi-face seam, close sheets, and cylinder failed with:

```text
SideSubdivisionRepair:InvalidInputIncidence
```

Each bounded benchmark was repeated in three independent processes. Stage structural hashes, terminal state, trace count, arrangement count, and quad count were identical for every fixture.

Do not expand acceptance to torus, sphere, thin tube, mechanical feature, or random bunny while these four fixtures fail.

## Default-suite result

- direct acceptance: **0/4**;
- remaining producer tests: **79/79**;
- completion tests: **154/164**;
- validation tests: **60/60**;
- compiled API tests: **8/8**;
- complete non-overlapping default inventory: **301/315**, 14 failures.

Aggregate totals do not offset the failed direct producer gate.

## Residual test-suite findings

The default suite is substantially better aligned than the former milestone inventory, but four categories still require correction:

1. `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` is a scheduler-sensitive wall-clock microbenchmark. It failed once, then passed in the full run and five isolated repeats. Move it to optional benchmark or closeout coverage.
2. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` protects superseded post-hoc route-repair machinery. Move it to historical coverage.
3. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse` asserts exact cache and recomputation counters. Move it to historical coverage.
4. Correct invalid or obsolete completion and Phase 17 fixtures. Do not weaken assertions or synthesize counters. Fixtures must create valid source-supported embedded complexes and reach the behavior they claim to test.

`FlowRepStrandsPhase15.PreRingReturnRerootsRetainedSingularityContinuation` may remain a valid directed-incidence regression, but it is downstream and is not the next producer target.

## Next authoritative turn

Execute the **Design-Aligned Uniform Phase-Front Code + Build** plan:

`.agents/Directional/Design_Aligned_Uniform_Phase_Front_Code_Build_Plan.md`

This is a compile-only turn. Do not execute tests, benchmarks, CLI, GUI, discovery, or generated project binaries.

Required work:

1. Finish the bounded default-test hygiene corrections listed above without weakening direct acceptance.
2. Add first-class local lattice phase, integer lattice coordinate, branch rotation, and scale level.
3. Add directed front-edge ownership with one unfilled side or explicit exterior classification.
4. Transport phase and lattice identity through source-chart transitions and cross-field matching.
5. Implement only these uniform events:
   - `CompatibleFrontMerge`;
   - `BoundaryTermination`;
   - `HardRailCapture`;
   - `PhaseMismatch`;
   - `PeriodicHolonomyConflict`.
6. Seed and advance the plane front intrinsically and construct a quad only after all four source-attached corners and sides are phase compatible.
7. Feed already-decided embedded cells or front cycles into arrangement.
8. Do not let arrangement invent new-path connectivity from pair-local fan-sector intervals.
9. Preserve the existing implementation behind an internal path while the proof is incomplete.
10. Compile and package only the approved seven targets.

Do not resume pair-local fan-interval micro-repair.

## Current authoritative documents

- `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md` — latest runtime authority;
- `.agents/Directional/Design_Aligned_Uniform_Phase_Front_Code_Build_Plan.md` — next executable plan;
- `benchmark-results/design-aligned-runtime-summary.json` — machine-readable runtime summary;
- `tests/TESTING_STRATEGY.md` — test-selection and validity policy;
- `.agents/Directional/DESIGN.md`;
- `.agents/Directional/REORIENTATION_PLAN.md`;
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- this live handoff.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md`
5. `.agents/Directional/Design_Aligned_Uniform_Phase_Front_Code_Build_Plan.md`
6. `benchmark-results/design-aligned-runtime-summary.json`
7. `tests/TESTING_STRATEGY.md`
8. `.agents/Directional/DESIGN.md`
9. `.agents/Directional/REORIENTATION_PLAN.md`
10. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. `turn-based-coding-agent/SKILL.md` and the relevant Code + Build, testing-integrity, artifact, status, handoff, and GitHub connector references.

## Durable lessons

- A cross field supplies orientation but not authoritative lattice phase or connectivity.
- The current producer can materialize partial plane quads, but partial output is not acceptance when source-authoritative completion validation fails.
- Zero-cell `SideSubdivisionRepair:InvalidInputIncidence` on seam, close sheets, and cylinder indicates missing authoritative incidence before completion, not a reason to weaken completion.
- Arrangement and extraction tests remain necessary, but they cannot substitute for a phase-labelled advancing-front producer.
- A high aggregate pass count is misleading when plane, seam, close-sheet, and cylinder direct acceptance all fail.
- Diagnostic strings, counters, hashes, cache layouts, memory inventories, and milestone numbers are secondary observability contracts, not the primary production gate.
- Scheduler-sensitive wall-clock ratios do not belong in default correctness tests.
- A test fixture is invalid when its setup does not create the precondition it claims to test.
- Legacy MIQ and integration tests remain valid for the legacy backend but do not establish direct `SurfaceCells` correctness.
- QEx-style sanitation, FlowRep simplification, completion, optimization, and topology cleanup are downstream of a coherent producer.
- Tests must reject fallback and source-grid recovery as substitutes for direct surface-paving output.
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST` prevents post-build test discovery from executing packaged GoogleTest binaries during compile-only turns.
- Artifact packaging must ignore the newly created untracked artifact directory when checking tracked source cleanliness, and checksum paths must be generated relative to the artifact root.

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
