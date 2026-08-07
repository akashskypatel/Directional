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
2. **G1 — Uniform phase-front plane:** **passed**.
3. **G2 — Cross-chart and close-sheet propagation:** **active**.
4. **G3 — Periodic closure and holonomy:** blocked by G2.
5. **G4 — Topology-distinct completion and singularities:** blocked by G3.
6. **G5 — Adaptive scale and hard features:** blocked by G4.
7. **G6 — General production geometry on `bunny_1k_random.obj`:** blocked by G5.
8. **G7 — Operational hardening and default-on decision:** blocked by G6.

Do not work on a blocked gate as the principal objective.

## Current checkpoint

The **Gate 1 Phase-Front Orientation Artifact-Only Test + Benchmark** turn is complete.

### Exact source and package authority

- uniform phase-front source commit: `4842911b6134c60410c92496d85d1152164a73c7`;
- orientation/direct-cell source commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- payload cleanup commit: `54a79a17f48bd3974367c3e043507d0550fb8daa`;
- artifact: `directional-g1-orientation-local-build-artifact.zip`;
- artifact SHA-256: `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`;
- evidence archive SHA-256: `458afe01241e8bf0c4623b5064f00eb294b17ffe99b9e34188625c14fbd0f074`;
- internal checksums: **45/45**;
- package closure: five executables, two static libraries, 26 fixture/input files.

Final verified source/test blobs:

```text
074bd7692b95202a9f6733cd58d5c958d30845b9  include/directional/geometry/SurfaceCellTracing.h
6f3aa122fc9ed9faed19b37ad59a1124be68b4e5  src/geometry/SurfaceCellTracing.cpp
056d9d533b4885a9df78e45b279b1a41a153ad3a  src/pipeline/RemeshPipeline.cpp
56da480a41f7d96ac5bd4470202e3e49a9eef745  tests/SurfaceCellsPhase10Tests.cpp
c95f27211394de1c238649062ab4d173f4bfe220  tests/AdaptiveTargetSizePhase12Tests.cpp
```

No rebuild, discovery regeneration, source/test/fixture/validator edit, or workflow execution occurred in the Test + Benchmark turn.

## Gate 1 closure

The plane passed direct acceptance and three independent benchmarks:

- requested/executed backend `SurfaceCells`;
- fallback `Fail`, no fallback attempt;
- source-grid recovery disabled and unused;
- output origin `CompletedSurfaceCells`;
- 352 trace segments;
- 64 authoritative direct cells;
- 65 arrangement/simplified cells including the exterior domain;
- 81 output vertices and 64 pure quads;
- zero non-quads and zero strict validation failures;
- stable output hash `730caeae49ec872c`;
- identical stage counts and structural hashes across all three processes.

The previous generic 65-to-409 completion expansion and `FlippedFace` failure are eliminated. Gate 1 remains a mandatory regression gate.

## Current direct acceptance

| Fixture | Result | Traces | Arrangement | Direct cells / quads | Earliest failure |
|---|---:|---:|---:|---:|---|
| Plane | **pass** | 352 | 65 | 64 / 64 | none |
| Multi-face seam | fail | 137 | 0 | 0 / 0 | `completion:SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | fail | 158 | 0 | 0 / 0 | `completion:SideSubdivisionRepair:InvalidInputIncidence` |
| Cylinder | fail | 732 | 0 | 0 / 0 | `completion:SideSubdivisionRepair:InvalidInputIncidence` |

All use direct `SurfaceCells`, fallback `Fail`, no fallback attempt, and no source-grid recovery.

## Default-suite result

- direct acceptance: **1/4**;
- remaining producer: **78/79**;
- completion: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- non-overlapping total: **301/315**, 14 failures.

The sole remaining producer failure is the known scheduler-sensitive wall-clock ratio test `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`. Treat it as optional benchmark/closeout coverage, not a functional active-gate blocker.

The ten completion failures are unchanged historical/downstream fixtures. They must not displace Gate 2.

## Next authoritative turn

Execute **Gate 2 Cross-Chart and Close-Sheet Propagation Code + Build**:

`.agents/Directional/Gate_2_Cross_Chart_Close_Sheet_Code_Build_Plan.md`

Required opening declaration:

```text
Active design gate: Gate 2 — Cross-chart and close-sheet propagation
Earliest failing fixture: multi_face_seam
Missing design contract: authoritative source-chart phase/lattice transport with close-sheet isolation
Smallest general implementation change: integrate exact source-chart and quarter-turn field transitions into the constructive phase front while preserving Gate 1 direct materialization
Observable material-progress condition: nonzero deterministic cross-chart cells or direct seam success, with no generic completion/fallback/recovery substitution
Explicitly deferred work: Gate 3 periodic cylinder logic, Gates 4–7, performance, cache, scheduler, and unrelated historical cleanup
```

Required implementation direction:

1. Add exact source-chart identity and transition provenance to lattice/front/cell state.
2. Use `SourceChartTransitionGraph`, exact source topology, hard-feature barriers, and cross-field matching/transition data.
3. Transport barycentric support, branch quarter-turn, phase, integer lattice coordinates, family/sign, component, local sheet, and source route coherently.
4. Require exact forward/reverse transition consistency; fail closed on missing, ambiguous, or inconsistent state.
5. Advance front sides intrinsically through multiple source faces rather than using one global planar projection.
6. Merge only reciprocal chart/route/phase-compatible fronts. Do not rank by distance, count, order, or frequency.
7. Retain local-sheet identity and prohibit positional capture or merging of close unrelated sheets.
8. Preserve Gate 1 source-normal orientation, whole-cycle reversal, directed ownership, and one-cell-to-one-quad materialization.
9. Keep cylinder periodic holonomy and all later gates blocked.
10. Compile the approved seven targets and execute no generated binary.

### Material-progress condition

The next artifact must pass the multi-face seam or produce nonzero authoritative cross-chart cells that deterministically reach a new chart-transport/direct-materialization boundary. Unchanged zero-cell completion failure, new diagnostics, counters, or hashes alone are not progress.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Phase_Front_Orientation_Local_Code_Build_Report.md`
- `.agents/Directional/Gate_1_Phase_Front_Orientation_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_2_Cross_Chart_Close_Sheet_Code_Build_Plan.md`
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
9. next Code + Build plan
10. latest runtime summary
11. `tests/TESTING_STRATEGY.md`
12. `.agents/Directional/GitHub_Workflow_Policy.md`
13. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- A cross field supplies orientation but not authoritative lattice phase or connectivity.
- Gate 1 proves first-class phase/front state, source-normal orientation, and one-cell-to-one-quad materialization on a planar domain.
- Arrangement cell inventories may include an exterior domain; direct bounded cell count must be compared to output quads, not raw arrangement count.
- Already-decided four-sided cells must not be expanded through generic patch completion.
- Gate 2 must use exact source-chart topology and field matching, not world-space projection or positional sheet merging.
- Direct gates outrank aggregate totals.
- Scheduler-sensitive timing ratios are benchmark/closeout evidence, not default functional correctness.
- `PRE_TEST` discovery preserves compile-only boundaries.
- Persistent mounted volumes may severely slow template compilation; local ephemeral storage is acceptable when source, logs, and artifacts remain exact and externally preserved.

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
