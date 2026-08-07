# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Mandatory design-first operating mandate

Every future agent must prioritize the overall architecture in `.agents/Directional/DESIGN.md` over local repair activity. Always work on the **earliest incomplete high-level design gate**. Diagnostics, ownership taxonomies, cache behavior, memory accounting, scheduling, performance, historical cleanup, or downstream repair machinery must not become the principal objective while an earlier constructive gate is red.

Before any code change, write:

```text
Active design gate:
Earliest failing fixture:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

A task that cannot identify the active gate and observable material-progress condition must be deferred.

Material progress means at least one of:

- the active direct fixture passes;
- the first invalid producer advances because a missing first-class contract was implemented;
- authoritative phase/front/topology state becomes live and is consumed by the next constructive stage;
- a general structural ambiguity is removed without replacing it with an equivalent downstream ambiguity.

The following are not material progress by themselves:

- new diagnostics, subtypes, counters, hashes, or ownership classes;
- movement between equivalent fan-interval or repair failures;
- higher aggregate pass counts while the direct gate remains red;
- cache, memory, scheduling, or performance changes to a failing producer;
- fixture-specific behavior, fallback, or recovery output.

### Mandatory no-progress stop rule

If two consecutive Code + Build turns do not materially advance the earliest active gate, the next turn must be a design review or bounded producer replacement proof. Do not continue an equivalent micro-repair sequence without evidence that it implements the missing design contract.

## High-level gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** **active**.
3. **G2 — Cross-chart and close-sheet propagation:** blocked by G1.
4. **G3 — Periodic closure and holonomy:** blocked by G2.
5. **G4 — Topology-distinct completion and singularities:** blocked by G3.
6. **G5 — Adaptive scale and hard features:** blocked by G4.
7. **G6 — General production geometry on `bunny_1k_random.obj`:** blocked by G5.
8. **G7 — Operational hardening and default-on decision:** blocked by G6.

Do not work on a blocked gate as the principal objective.

## Current checkpoint

The **Gate 1 Phase-Front Orientation and Direct-Cell Materialization Code + Build** turn is complete.

### Synchronized source authority

Layer 1 — uniform phase-front producer:

- source commit: `4842911b6134c60410c92496d85d1152164a73c7`;
- five expected Layer 1 source blobs verified exactly.

Layer 2 — orientation and direct-cell materialization:

- incremental patch SHA-256: `cb06890449bc56b2e5bc25d7033260bc9c180deccb38b545bd5ab6e56efff9ab`;
- source commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- payload cleanup commit: `54a79a17f48bd3974367c3e043507d0550fb8daa`;
- source-sync run/job: `31135783371` / `92734653996`;
- source-sync evidence artifact: `8977861759`.

Final Layer 2 blobs:

```text
074bd7692b95202a9f6733cd58d5c958d30845b9  include/directional/geometry/SurfaceCellTracing.h
6f3aa122fc9ed9faed19b37ad59a1124be68b4e5  src/geometry/SurfaceCellTracing.cpp
056d9d533b4885a9df78e45b279b1a41a153ad3a  src/pipeline/RemeshPipeline.cpp
56da480a41f7d96ac5bd4470202e3e49a9eef745  tests/SurfaceCellsPhase10Tests.cpp
c95f27211394de1c238649062ab4d173f4bfe220  tests/AdaptiveTargetSizePhase12Tests.cpp
```

Every temporary Gate 1 patch/build payload was removed only after source commits and expected blobs were verified. The bounded source-sync workflow and its trigger markers were removed from `master`. GitHub service recovery has ended the prior outage-only prohibition; future workflows remain governed by `.agents/Directional/GitHub_Workflow_Policy.md`.

## Implemented Gate 1 slice

The current source now enforces:

- four distinct authoritative corners;
- ordered boundary-path endpoint continuity;
- consistent component and local-sheet provenance;
- nonzero quad-loop normal and valid quad-loop classification;
- source-normal-consistent winding;
- transactional reversal of the complete cell cycle when winding is opposite;
- one filled cell per directed edge and exactly one reciprocal opposite edge or explicit exterior;
- deterministic direct-vertex canonicalization by integer lattice coordinate;
- one accepted four-sided phase-front cell to one output quad-domain cell;
- direct lineage and boundary-loop construction;
- fail-closed `tracing/phase-front-materialization` before generic completion on invalid orientation/incidence;
- bypass of generic patch completion for valid authoritative phase-front cells.

Two stale non-direct producer tests were corrected to test their intended diagnostics and direct/recovery semantics without weakening direct acceptance or validators.

## Local compile authority

- GNU C++ 14.2.0;
- CMake 3.31.6;
- Ninja 1.12.1;
- Release `-O2 -DNDEBUG`;
- static libraries;
- GoogleTest discovery mode `PRE_TEST`;
- two compiler jobs;
- approved targets: **7/7**;
- wall-clock interval including wrapper resumptions: **577 seconds**;
- package closure: five executables, two libraries, 26 fixtures, **45/45** checksums;
- artifact: `directional-g1-orientation-local-build-artifact.zip`;
- artifact SHA-256: `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`.

No generated project binary, test, benchmark, GoogleTest discovery command, CLI, GUI, help, list, or project runtime command was executed.

## Latest runtime authority

The latest runtime evidence remains the preceding artifact-only turn:

| Fixture | Result | Traces | Arrangement | Quads | Earliest failure |
|---|---:|---:|---:|---:|---|
| Plane | failed | 352 | 65 | 409 | `completion/output-validation:FlippedFace` |
| Multi-face seam | failed | 137 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | failed | 158 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Cylinder | failed | 732 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |

Direct acceptance was **0/4** and the non-overlapping default inventory was **299/315**. The new Code + Build turn makes no runtime-success claim.

## Next authoritative turn

Execute:

`.agents/Directional/Gate_1_Phase_Front_Orientation_Artifact_Only_Test_Benchmark_Plan.md`

Required order:

1. verify artifact SHA-256 and all 45 internal checksums;
2. verify source commits and five final blobs;
3. run plane first in a fresh process;
4. report whether direct one-to-one cell materialization replaces the prior 65-to-409 expansion;
5. report whether `FlippedFace` is eliminated, the plane passes, or invalid incidence fails earlier at `tracing/phase-front-materialization`;
6. run seam, close sheets, and cylinder only after plane evidence;
7. run remaining default suites;
8. run three independent bounded processes per analytic fixture;
9. perform no rebuild or source/test/fixture/validator edit.

### Material-progress condition

Gate 1 passes only with direct non-empty pure-quad `CompletedSurfaceCells` output under strict source-authoritative validation and no fallback/recovery.

A failing result still demonstrates material progress only when it proves a general orientation/incidence invariant by failing before generic completion, or preserves one-to-one direct-cell materialization and reaches a later strict-validation boundary. A new diagnostic alone is not progress.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Uniform_Phase_Front_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Phase_Front_Orientation_Local_Code_Build_Report.md`
- `.agents/Directional/Gate_1_Phase_Front_Orientation_Artifact_Only_Test_Benchmark_Plan.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/REORIENTATION_PLAN.md`
6. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
7. latest Test + Benchmark report
8. latest Code + Build report
9. next artifact-only plan
10. latest runtime summary
11. `tests/TESTING_STRATEGY.md`
12. `.agents/Directional/GitHub_Workflow_Policy.md`
13. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- A cross field supplies orientation but not authoritative lattice phase or connectivity.
- First-class phase/front state is live; winding, incidence, and direct-cell ownership are now first-class rather than inferred downstream.
- Already-decided four-sided cells must not be expanded through generic patch completion.
- Direct gates outrank aggregate totals.
- Tests with obsolete failure or recovery assumptions must be corrected using valid scenarios, never by weakening validation.
- `PRE_TEST` discovery preserves compile-only boundaries.
- Persistent mounted volumes may severely slow template compilation; local ephemeral storage is acceptable when source, logs, and artifacts remain exact and externally preserved.
- A source-sync payload should be split and checksum-verified when connector transport cannot preserve one large encoded file reliably.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the **start and end of every turn**, inspect `.github/workflows` and temporary support locations, including triggers, transfer files, patch/payload directories, and generated build artifacts.
2. Remove stale bounded or turn-specific workflows before beginning work so they cannot run or conflict.
3. During a remote compile turn, retain only approved durable base workflows plus at most one bounded workflow and exact payloads required for that turn.
4. Immediately after the artifact and logs are verified, remove bounded workflows, triggers, and payloads no longer required.
5. Final branch state must contain only approved durable workflows and no stale trigger or generated build artifact.
6. Do not remove a durable dependency explicitly consumed by an approved retained workflow.
7. Retain every exact patch/build payload until its corresponding remote source commit, expected blobs, and build authority are committed and verified; then remove that payload.

### Documentation and result cleanup

1. At the end of every turn, remove stale or superseded plans, reports, closure notes, evidence indexes, and results from `.agents` and `benchmark-results`.
2. Retain only the live handoff, latest completed report, next executable plan, current source/package authority, latest runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Update retained documents so they reference only existing files.
4. Git history and the PR conversation are the historical archive; do not keep duplicate snapshots merely for provenance.
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
