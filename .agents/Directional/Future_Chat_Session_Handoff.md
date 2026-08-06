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

The **Gate 1 Uniform Phase-Front Artifact-Only Test + Benchmark** turn is complete. It used the local compile artifact directly and performed no configure, compile, relink, source edit, test edit, fixture edit, validator edit, or workflow execution.

### Exact tested source authority

- base source: `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9`;
- payload checkpoint: `5649cbe6b2ee353955a39db6ceb7fc0d67ee72ce`;
- patch path: `.agents/Directional/turn-payloads/g1-uniform-phase-front.patch.gz.b64`;
- patch Git blob: `aa18d454877ccf40d16f71f173fdaf765f5f1086`;
- uncompressed patch SHA-256: `48a01a37b038c59af18f2fca8904642f23bf8ea54f8ff8c3c784191dc99b8bf7`;
- artifact SHA-256: `7e520acda5d402300711d1803a666e505ce4a03c0b92d969f5ae2ba3ca2d1f28`;
- internal checksums: **47/47**;
- package closure: five executables, two libraries, 26 fixtures;
- remote implementation commit: **pending**.

Do not call `5649cbe6...` the implementation commit. It contains the payload checkpoint, not the applied five source files.

### Required Layer 1 source blobs

```text
a1ff3fa4c97af4f1fe55baa475c7e83c48f655f9  include/directional/geometry/SurfaceCellTracing.h
6e635768487321efd724e26d4c4f0bbf0140100b  src/geometry/SurfaceCellTracing.cpp
9f9ac145ccacf17a8d2c10e13771cf1ee22c5f61  include/directional/geometry/SurfaceArrangement.h
a2eaa6008a0fbb4ad9dc12d16ce0820ee940ac67  src/geometry/SurfaceArrangement.cpp
a4a06dc214e4a567b90ea6d87e4fef2d62a4de62  src/pipeline/RemeshPipeline.cpp
```

When GitHub service recovers, apply Layer 1 exactly and accept its source commit only when all five blobs match. Do not regenerate, approximately reproduce, or silently alter the patch.

## Direct acceptance result

| Fixture | Result | Traces | Arrangement | Quads | Earliest failure |
|---|---:|---:|---:|---:|---|
| Plane | failed | 352 | 65 | 409 | `completion/output-validation:FlippedFace` |
| Multi-face seam | failed | 137 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | failed | 158 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Cylinder | failed | 732 | 0 | 0 | `SideSubdivisionRepair:InvalidInputIncidence` |

All four requested and executed `SurfaceCells`, attempted no fallback, used no source-grid recovery, and returned output origin `None`.

### Plane interpretation

Previous baseline: 106 traces, 9 arrangement cells, 12 quads, 15 completion-validation failures.

Current Gate 1 patch: **352 traces, 65 arrangement cells, 409 quads, 100 validation failures**. First invalid record: cell 38, source face 41. Tracing, arrangement, and completion structural hashes and counts were identical across three independent processes.

This is material architectural progress because first-class phase-front state is live and consumed by arrangement and completion. It is not Gate 1 success. The current producer sends already-decided four-sided cells through generic patch completion, expands 65 cells into 409 quads, and emits flipped output.

## Default-suite result

- direct acceptance: **0/4**;
- remaining producer: **77/79**;
- completion: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- total: **299/315**, 16 failures.

Two new producer failures are stale expectations:

1. `AdaptiveTargetSizePhase12.SurfaceCellScaffoldPopulatesSizeDiagnostics` assumes the scaffold must fail, but the new tiny planar path succeeds.
2. `SurfaceCellsPhase10.SurfaceCellsBackendIsDefaultOffAndSupportsPlanarFixture` assumes recovery must run even when direct SurfaceCells succeeds. Replace it with a true recovery-only fixture or separate direct-success and recovery-only assertions.

The ten completion failures are unchanged from the prior artifact and remain downstream/historical fixture work. They must not displace the active Gate 1 objective.

## Next authoritative turn

Execute **Gate 1 Phase-Front Orientation and Direct-Cell Materialization Code + Build**:

`.agents/Directional/Gate_1_Phase_Front_Orientation_Code_Build_Plan.md`

Required implementation direction:

1. Preserve the first-class phase, lattice, front ownership, event, and hashing model.
2. Validate four distinct corners, ordered side endpoint continuity, nonzero signed area, authoritative source-normal winding, component/sheet consistency, and one-filled-side ownership before accepting a cell.
3. Reverse the complete cell cycle transactionally when winding is opposite. Reverse corners, lattice states, side paths, families/signs, and edge ownership coherently; do not use positional reordering.
4. Materialize one accepted four-sided phase-front cell as one quad-domain cell. Arrangement may canonicalize and split exact crossings, but generic completion must not invent or expand its topology.
5. Fail closed before completion on any orientation, incidence, route, component, or sheet inconsistency.
6. Correct the two stale producer tests without weakening the four direct acceptance tests or recovery validation.
7. Compile the approved seven targets only. Execute no generated binary, test, benchmark, help/list, discovery, CLI, or GUI command.
8. Keep seam, close-sheet, cylinder, periodic, adaptive, hard-feature, singularity, and bunny work blocked.

### Material-progress condition

The next artifact must either pass the plane or materially advance beyond `completion/output-validation:FlippedFace` with one-to-one direct-cell materialization and fewer structural validation failures. A new diagnostic alone is not progress.

## Ordered source synchronization backlog during outage

The GitHub outage is still active for this project workflow path. Do not use workflows for repository updates or builds while it persists.

### Layer 1 — current tested phase-front patch

- Keep the exact existing patch immutable and versioned.
- Keep its five-blob synchronization task on both TODO files.
- After recovery, apply it through direct Git objects or an authenticated local client and verify every expected blob.

### Layer 2 — next orientation/direct-cell patch

- Reconstruct Layer 1 exactly from the recorded base and patch.
- Implement orientation/direct-cell changes as a separate incremental patch.
- Record Layer 2 digest, expected final blobs, local build artifact, logs, and dependency closure.
- Apply Layer 2 as a separate coherent source commit only after Layer 1 is synchronized and verified.

### Cleanup

- Preserve every unsynchronized patch layer in order.
- Remove a payload only after its corresponding source commit, expected blobs, and build authority are verified.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Uniform_Phase_Front_Local_Code_Build_Report.md`
- `.agents/Directional/Gate_1_Uniform_Phase_Front_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Phase_Front_Orientation_Code_Build_Plan.md`
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
8. next Code + Build plan
9. latest runtime summary
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- A cross field supplies orientation but not authoritative lattice phase or connectivity.
- First-class phase/front state is now live; the next missing contract is valid winding/incidence and direct-cell materialization.
- Already-decided four-sided cells must not be expanded through generic patch completion.
- Zero-cell invalid incidence on later fixtures remains blocked work, not a reason to weaken completion.
- Direct gates outrank aggregate totals.
- Tests with obsolete failure or recovery assumptions must be corrected using valid scenarios, never by weakening validation.
- `PRE_TEST` discovery preserves compile-only boundaries.
- Persistent mounted volumes may severely slow template compilation; local ephemeral storage is acceptable when source, logs, and artifacts remain exact and externally preserved.
- Base-plus-patch authority is exact only with patch and output-blob identities; it is not a substitute for a verified source commit.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the **start and end of every turn**, inspect `.github/workflows` and temporary support locations, including triggers, transfer files, patch/payload directories, and generated build artifacts.
2. Remove stale bounded or turn-specific workflows before beginning work so they cannot run or conflict.
3. During a remote compile turn, retain only approved durable base workflows plus at most one bounded workflow and exact payloads required for that turn.
4. Immediately after the artifact and logs are verified, remove bounded workflows, triggers, and payloads no longer required.
5. Final branch state must contain only approved durable workflows and no stale trigger or generated build artifact.
6. Do not remove a durable dependency explicitly consumed by an approved retained workflow.
7. Retain every exact Gate 1 patch/build payload until its corresponding remote source commit, expected blobs, and build authority are committed and verified; then remove that payload.
8. While the current outage persists, do not create, trigger, or use GitHub Actions workflows for repository updates or builds.

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
