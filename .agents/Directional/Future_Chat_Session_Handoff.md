# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Mandatory design-first operating mandate

Every future agent must prioritize implementation of the overall architecture in `.agents/Directional/DESIGN.md` over local repair activity.

Always work on the **earliest incomplete high-level design gate**. Diagnostics, ownership classifications, cache behavior, memory accounting, scheduling, performance, historical milestone cleanup, or downstream repair machinery must not become the principal implementation objective while an earlier constructive gate is red.

Before any code change, write:

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

If two consecutive Code + Build turns do not materially advance the earliest active gate, the next turn must be a design review or bounded producer replacement proof. Do not continue an equivalent micro-repair sequence without evidence that it implements the missing design contract.

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

The **Gate 1 Uniform Phase-Front Local Code + Build** turn is complete.

GitHub Actions was unavailable, so the exact compiled source is represented by an authoritative base-plus-patch composition rather than an applied remote source commit:

- base source: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`;
- working-branch payload checkpoint: `5649cbe6b2ee353955a39db6ceb7fc0d67ee72ce`;
- patch path: `.agents/Directional/turn-payloads/g1-uniform-phase-front.patch.gz.b64`;
- patch Git blob: `aa18d454877ccf40d16f71f173fdaf765f5f1086`;
- encoded patch SHA-256: `b34b7346fdeb2c6520e9cd16ba75a9e17d92f8bbda41c61cd109bfdac37b92eb`;
- uncompressed patch SHA-256: `48a01a37b038c59af18f2fca8904642f23bf8ea54f8ff8c3c784191dc99b8bf7`;
- recursive submodules: exact previous artifact revisions, 9/9;
- remote implementation source commit: **pending**.

Do not describe `5649cbe6...` as the implementation commit. It contains the exact patch payload and former trigger state, not the five applied implementation files.

### Final post-patch implementation blobs

```text
a1ff3fa4c97af4f1fe55baa475c7e83c48f655f9  include/directional/geometry/SurfaceCellTracing.h
6e635768487321efd724e26d4c4f0bbf0140100b  src/geometry/SurfaceCellTracing.cpp
9f9ac145ccacf17a8d2c10e13771cf1ee22c5f61  include/directional/geometry/SurfaceArrangement.h
a2eaa6008a0fbb4ad9dc12d16ce0820ee940ac67  src/geometry/SurfaceArrangement.cpp
a4a06dc214e4a567b90ea6d87e4fef2d62a4de62  src/pipeline/RemeshPipeline.cpp
```

When the remote write path recovers, apply the exact patch and accept the source commit only if all five output blobs match exactly. Do not regenerate, alter, or approximately reproduce the patch.

## Implemented Gate 1 slice

The compiled patch adds and consumes:

- `LocalLatticeState` with phase, integer lattice coordinate, branch rotation, and scale level;
- directed `SurfaceFrontEdge` ownership and typed front events;
- a bounded planar uniform phase-front producer;
- source-attached grid corners and ordered source-face side paths;
- interior `CompatibleFrontMerge` events and exterior `BoundaryTermination` events;
- deterministic phase-front hashing and pipeline accounting;
- authoritative proposal-cycle incidence in arrangement;
- bypass of pair-local fan-sector connectivity inference on the phase-front path.

This is a bounded Gate 1 proof. Cross-chart phase transport, close-sheet handling, periodic holonomy, adaptivity, general topology completion, hard-feature production behavior, and bunny geometry remain blocked by later gates.

## Local compile authority

The first compile attempt on the persistent `/mnt/data` volume was stopped after severe compiler I/O contention; it produced no compiler diagnostic. The identical source and flags were then rebuilt from the container’s local ephemeral filesystem.

Successful compile:

- GNU C++ 14.2.0;
- CMake 3.31.6;
- Ninja 1.12.1;
- Release `-O2 -DNDEBUG`;
- static libraries;
- GoogleTest discovery mode `PRE_TEST`;
- parallel jobs: 2;
- configure: success;
- compile/link: **112/112**;
- duration: **435 seconds**;
- approved targets: **7/7**;
- packaged executables: **5/5**;
- packaged static libraries: **2/2**;
- packaged fixtures/inputs: **26/26**;
- recursive internal checksums: **47/47**.

Approved targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

No test, benchmark, fixture, discovery command, CLI, GUI, help/list command, or generated project binary was executed.

## Local artifact authority

- archive: `directional-g1-local-build-artifact.zip`;
- archive SHA-256: `7e520acda5d402300711d1803a666e505ce4a03c0b92d969f5ae2ba3ca2d1f28`;
- internal checksums: **47/47**;
- contents: five executables, two static libraries, 26 fixtures, exact base source archive, exact encoded and decoded patch, reconstructed modified source, source/dependency authority, compile commands, logs, and checksum manifest.

The archive exists in the active ChatGPT sandbox, not as a GitHub Actions artifact. A future session must use a user-provided re-upload or a recovered Actions artifact; never invent or assume a sandbox path persists across sessions.

## Failed remote execution record

Default-branch dispatcher run `31124584060`, job `92692478156`, was cancelled during the Actions outage. It did not establish source or build authority and produced no accepted implementation commit.

The temporary default-branch dispatcher was removed. The consumed branch trigger and bounded build workflow are also removed during this turn. Retain the exact patch and build-script payloads only until the five source blobs are committed and verified.

## Runtime baseline before the Gate 1 patch

Artifact `8974081923` was executed from exact source `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`.

| Fixture | Result | Terminal | Traces | Arrangement | Quads |
|---|---:|---|---:|---:|---:|
| Plane | failed | `NotProductionReady/completion` | 106 | 9 | 12 |
| Multi-face seam | failed | `NotProductionReady/completion` | 137 | 0 | 0 |
| Close sheets | failed | `NotProductionReady/completion` | 158 | 0 | 0 |
| Cylinder | failed | `NotProductionReady/completion` | 732 | 0 | 0 |

The plane failed at:

```text
completion/output-validation:AggregateCompletionValidationFailure
```

The other three failed with:

```text
SideSubdivisionRepair:InvalidInputIncidence
```

Direct acceptance was 0/4. This remains the comparison baseline until the local artifact is tested.

## Next authoritative turn

Execute the **Gate 1 Uniform Phase-Front Artifact-Only Test + Benchmark** plan:

`.agents/Directional/Gate_1_Uniform_Phase_Front_Artifact_Only_Test_Benchmark_Plan.md`

This is an artifact-only turn. Do not configure, compile, relink, regenerate, or edit source, tests, fixtures, build logic, or validators.

Required order:

1. verify outer archive SHA-256 and all 47 internal checksums;
2. verify source authority, patch identity, five final source blobs, 5 executables, 2 libraries, and 26 fixtures;
3. run plane in a fresh process;
4. run multi-face seam, close sheets, and cylinder in that order;
5. run remaining default suites only after all four direct cases;
6. run three independent bounded benchmark processes for each analytic fixture;
7. do not expand to torus, sphere, thin tube, mechanical, or bunny while the preceding gates fail.

## Gate 1 exit criteria

The next artifact-only turn must prove:

- plane direct acceptance passes, or its first invalid stage materially advances because the phase-front contract is live and consumed;
- output origin is `CompletedSurfaceCells` for success;
- output is non-empty and pure quad for a pass;
- strict source-authoritative validation passes;
- no fallback or source-grid recovery;
- arrangement consumes authoritative proposal cycles;
- no fan-sector inference, positional merge, or post-hoc cycle decomposition on the new path.

A different diagnostic string, counter, hash, interval subtype, or aggregate test count is not material progress.

## Current authoritative documents

- `.agents/Directional/DESIGN.md` — architecture and high-level gates;
- `.agents/Directional/REORIENTATION_PLAN.md` — gate execution and anti-detour policy;
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md` — remediation authority;
- `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md` — pre-patch runtime baseline;
- `.agents/Directional/Gate_1_Uniform_Phase_Front_Local_Code_Build_Report.md` — latest completed Code + Build evidence;
- `.agents/Directional/Gate_1_Uniform_Phase_Front_Artifact_Only_Test_Benchmark_Plan.md` — next executable plan;
- `benchmark-results/design-aligned-runtime-summary.json` — pre-patch machine-readable runtime baseline;
- `tests/TESTING_STRATEGY.md` — gate-first test policy;
- `.agents/Directional/GitHub_Workflow_Policy.md`;
- `TODO`;
- `MILESTONE_G_TODO.md`;
- this live handoff.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Future_Chat_Session_Handoff.md`
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/REORIENTATION_PLAN.md`
6. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
7. `.agents/Directional/Gate_1_Uniform_Phase_Front_Local_Code_Build_Report.md`
8. `.agents/Directional/Gate_1_Uniform_Phase_Front_Artifact_Only_Test_Benchmark_Plan.md`
9. `.agents/Directional/Design_Aligned_Artifact_Only_Test_Benchmark_Report.md`
10. `benchmark-results/design-aligned-runtime-summary.json`
11. `tests/TESTING_STRATEGY.md`
12. `.agents/Directional/GitHub_Workflow_Policy.md`
13. `turn-based-coding-agent/SKILL.md` and relevant turn, integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- A cross field supplies orientation but not authoritative lattice phase or connectivity.
- The current producer can materialize partial plane quads, but partial output is not acceptance when strict completion validation fails.
- Zero-cell invalid incidence on seam, close sheets, and cylinder indicates missing authoritative incidence before completion, not a reason to weaken completion.
- Arrangement and extraction tests cannot substitute for a phase-labelled producer.
- A high aggregate pass count is misleading while the active direct gate fails.
- Diagnostics, counters, hashes, cache layouts, memory inventories, and milestone numbers are observability contracts, not the production gate.
- Scheduler-sensitive wall-clock ratios do not belong in default correctness tests.
- A test fixture is invalid when its setup does not create the claimed precondition.
- QEx-style sanitation, FlowRep simplification, completion, optimization, and topology cleanup are downstream of a coherent producer.
- Tests must reject fallback and source-grid recovery as substitutes for direct paving output.
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST` prevents compile-only builds from executing GoogleTest discovery binaries.
- Mounted persistent volumes may cause severe template-compiler I/O contention; use local ephemeral storage for long builds while preserving logs/artifacts externally.
- A locally compiled base-plus-versioned-patch composition is exact only when patch and final output blob identities are recorded. It is not a substitute for committing and verifying the final source blobs.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the **start and end of every turn**, inspect `.github/workflows` and temporary support locations, including triggers, transfer files, patch/payload directories, and generated build artifacts.
2. Remove stale bounded or turn-specific workflows before beginning work so they cannot run or conflict.
3. During a remote compile turn, retain only approved durable base workflows plus at most one bounded workflow and the exact temporary payloads required for that turn.
4. Immediately after the artifact and logs are published and verified, remove the bounded workflow, trigger, and temporary payloads that are no longer required.
5. Final branch state must contain only approved durable workflows and no stale trigger or generated build artifact.
6. Do not remove a durable dependency explicitly consumed by an approved retained workflow. Distinguish active inputs from stale payloads before deletion.
7. For this checkpoint, retain the exact Gate 1 patch and build-script payloads only until the five remote source blobs are committed and verified; then remove both.

### Documentation and test-result cleanup

1. At the **end of every turn**, review `.agents` and `benchmark-results` and remove stale or superseded plans, reports, closure notes, evidence indexes, and results.
2. Retain only durable authority and the minimum current chain: live handoff, latest completed report, next executable plan, current source/package authority, latest runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Update retained documents so they reference only files that still exist.
4. Git history and the PR conversation are the historical archive; do not preserve duplicate snapshots merely for provenance.
5. Never delete the latest evidence or next-turn instructions before replacements are committed and verified.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction in this handoff unless the user explicitly instructs its removal or replacement.**
2. Handoff edits are additive or narrowly corrective by default. Preserve all procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements.
3. Before committing a handoff update, compare it with the prior version and verify every pre-existing mandatory instruction remains materially present.
4. When a new instruction conflicts with an existing mandatory instruction, preserve both, identify the conflict, and request user direction rather than deleting either.
5. Documentation cleanup never authorizes removal of mandatory handoff rules.

## End-of-turn requirement

Every completed Code + Build, Test + Benchmark, optional Review, or documentation-maintenance turn ends with a **new top-level PR #8 comment** after all documentation and PR metadata updates. That comment is the final repository write.

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
