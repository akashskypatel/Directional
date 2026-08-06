# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Mandatory design-first operating mandate

Every future agent must prioritize implementation of the overall architecture in `.agents/Directional/DESIGN.md` over local repair activity.

The agent must always work on the **earliest incomplete high-level design gate**. It must not allow diagnostics, ownership classifications, cache behavior, memory accounting, scheduling, performance, historical milestone cleanup, or downstream repair machinery to become the main implementation objective while an earlier constructive gate is red.

Before any code change, the agent must write this declaration in its turn plan or report:

```text
Active design gate:
Earliest failing fixture:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

A task that cannot identify the design gate and observable material-progress condition must be deferred.

Material progress means at least one of:

- the active direct fixture passes;
- the first invalid producer advances to a later design stage because a missing first-class contract was implemented;
- authoritative phase/front/topology state becomes live and is consumed by the next constructive stage;
- a general structural ambiguity is removed without an equivalent downstream ambiguity.

The following are not material progress by themselves:

- new diagnostic strings, subtypes, counters, hashes, or ownership categories;
- movement between equivalent fan-interval or repair failures;
- a higher aggregate pass count while the direct gate remains red;
- cache, memory, scheduling, or performance changes to a failing producer;
- fixture-specific behavior, fallback, or recovery output.

### Mandatory no-progress stop rule

If two consecutive Code + Build turns do not materially advance the earliest active gate, the next turn must be a design review or bounded producer replacement proof. Do not continue the same micro-repair sequence without explicit evidence that it now implements the missing design contract.

## High-level gates

Only one gate is active at a time.

1. **Gate 0 — Truthful authority:** direct `SurfaceCells`, fallback `Fail`, recovery disabled, `CompletedSurfaceCells` only, strict source-authoritative validation. Status: passed and continuously enforced.
2. **Gate 1 — Uniform phase-front plane:** first-class lattice phase, integer coordinates, directed front ownership, intrinsic uniform cells, arrangement materialization of already-decided topology. Status: **active**.
3. **Gate 2 — Cross-chart and close-sheet propagation:** multi-face seam and close sheets, deterministic chart transport, zero cross-sheet merges. Blocked by Gate 1.
4. **Gate 3 — Periodic closure and holonomy:** cylinder periodic phase reconciliation and valid directed incidence. Blocked by Gate 2.
5. **Gate 4 — Topology-distinct completion and singularities:** distinct patch graphs, intentional poles, supported 3–6-sided completion, sphere/torus cases. Blocked by Gate 3.
6. **Gate 5 — Adaptive scale and hard features:** dyadic 2:1 transitions, feature rails, thin tube and mechanical fixtures. Blocked by Gate 4.
7. **Gate 6 — General production geometry:** deterministic direct `bunny_1k_random.obj` success. Blocked by Gate 5.
8. **Gate 7 — Operational hardening and default-on decision:** caches, parallelism, memory, exact predicates, performance, full production matrix. Blocked by Gate 6.

Do not work on a blocked gate as the principal turn objective.

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

Do not expand acceptance to torus, sphere, thin tube, mechanical feature, or random bunny while the preceding gates fail.

## Default-suite result

- direct acceptance: **0/4**;
- remaining producer tests: **79/79**;
- completion tests: **154/164**;
- validation tests: **60/60**;
- compiled API tests: **8/8**;
- complete non-overlapping default inventory: **301/315**, 14 failures.

Aggregate totals do not offset the failed direct producer gate.

## Residual test-suite findings

The default suite is substantially better aligned than the former milestone inventory, but residual cleanup remains:

1. `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` is a scheduler-sensitive wall-clock microbenchmark and belongs in optional benchmark or closeout coverage.
2. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger` protects superseded post-hoc route-repair machinery and belongs in historical coverage.
3. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse` asserts exact cache and recomputation counters and belongs in historical coverage.
4. Invalid or obsolete completion and Phase 17 fixtures must be reconstructed without weakening assertions or synthesizing counters.

This cleanup is deferred unless required to compile the active Gate 1 targets. It must not consume the constructive Code + Build turn.

## Next authoritative turn

Execute the **Design-Aligned Uniform Phase-Front Code + Build** plan:

`.agents/Directional/Design_Aligned_Uniform_Phase_Front_Code_Build_Plan.md`

This is a compile-only turn. Do not execute tests, benchmarks, CLI, GUI, discovery, or generated project binaries.

Required Gate 1 work:

1. Add first-class local lattice phase, integer lattice coordinate, branch rotation, and scale level.
2. Add directed front-edge ownership with one unfilled side or explicit exterior classification.
3. Make phase/front state serializable and deterministically hashable.
4. Transport phase and lattice identity through source-chart transitions and cross-field matching.
5. Implement only:
   - `CompatibleFrontMerge`;
   - `BoundaryTermination`;
   - `HardRailCapture`;
   - `PhaseMismatch`;
   - `PeriodicHolonomyConflict`.
6. Seed and advance the plane front intrinsically.
7. Construct a quad only after all four source-attached corners and sides are phase compatible.
8. Feed already-decided embedded cells or front cycles into arrangement.
9. Do not let arrangement invent new-path connectivity from pair-local fan-sector intervals.
10. Preserve the existing validated provenance, extraction, and validation infrastructure behind a clear internal boundary.
11. Compile and package only the approved seven targets.

Do not resume pair-local fan-interval micro-repair.

## Gate 1 exit criteria

The next artifact-only turn must prove:

- plane direct acceptance passes, or its first invalid stage materially advances because the phase-front contract is live and consumed;
- output origin remains `CompletedSurfaceCells` for success;
- no fallback or source-grid recovery;
- non-empty pure-quad output for a pass;
- strict source-authoritative validation;
- no fan-sector inference, positional merge, or post-hoc cycle decomposition on the new producer path.

A different diagnostic string, counter, hash, interval subtype, or aggregate test count is not progress.

## Current authoritative documents

- `.agents/Directional/DESIGN.md` — architecture and high-level gates;
- `.agents/Directional/REORIENTATION_PLAN.md` — gate execution and anti-detour policy;
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md` — current remediation authority;
- `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md` — latest runtime authority;
- `.agents/Directional/Design_Aligned_Uniform_Phase_Front_Code_Build_Plan.md` — next executable plan;
- `benchmark-results/design-aligned-runtime-summary.json` — machine-readable runtime summary;
- `tests/TESTING_STRATEGY.md` — gate-first test policy;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- this live handoff.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/REORIENTATION_PLAN.md`
6. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
7. `.agents/Directional/Design_Aligned_Uniform_Phase_Front_Code_Build_Plan.md`
8. `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md`
9. `benchmark-results/design-aligned-runtime-summary.json`
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. `turn-based-coding-agent/SKILL.md` and the relevant Code + Build, testing-integrity, artifact, status, handoff, and GitHub connector references.

## Durable lessons

- A cross field supplies orientation but not authoritative lattice phase or connectivity.
- The current producer can materialize partial plane quads, but partial output is not acceptance when source-authoritative completion validation fails.
- Zero-cell `SideSubdivisionRepair:InvalidInputIncidence` on seam, close sheets, and cylinder indicates missing authoritative incidence before completion, not a reason to weaken completion.
- Arrangement and extraction tests remain necessary, but they cannot substitute for a phase-labelled advancing-front producer.
- A high aggregate pass count is misleading when the active direct gate fails.
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
