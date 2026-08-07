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
2. **G1 — Uniform phase-front plane:** passed.
3. **G2 — Cross-chart and close-sheet propagation:** **active**.
4. **G3 — Periodic closure and holonomy:** blocked by G2.
5. **G4 — Topology-distinct completion and singularities:** blocked by G3.
6. **G5 — Adaptive scale and hard features:** blocked by G4.
7. **G6 — Full production geometry:** blocked by G5 as a success gate; bunny and vase remain mandatory observations now.
8. **G7 — Operational hardening and default-on decision:** blocked by G6.

Do not work on a blocked gate as the principal objective.

## Current checkpoint

The **Gate 2 Cross-Chart Transport and Mandatory Production Fixtures Code + Build** turn is complete.

### Source authority

- Gate 1 orientation/direct-cell source commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- Gate 2 payload checkpoint: `aea10409c73c490b92f78760b73191641ef823c6`;
- Gate 2 patch SHA-256: `512d2cda4f9799d5600af277b9d63bbce76ace334b076bb922e762d0059f1b9c`;
- compressed patch SHA-256: `29bd156ad17198b610614956489d50114d10ac96faf4b3bd907e8a09adcc712f`;
- Gate 2 source commit: `21f081b330418a0f34709f61d857f54a03d2fd48`;
- payload cleanup commit: `98fe525bb46f348cddcad91b0525353796b9e061`;
- source-sync run/job: `31140198130` / `92748287591`;
- source-sync evidence artifact: `8979516674`;
- source-sync evidence digest: `9789218c72628dead864881838716a6b3fd9070eb0f277c32c2cadf71da1eaa4`.

All 16 expected source, test, manifest, and fixture blobs were verified before commit. The temporary payload was removed only after source verification.

### Compile artifact

- archive: `directional-g2-cross-chart-mandatory-fixtures-local-build-artifact.zip`;
- SHA-256: `f5c2be0e2131dbce7a6460e3c61da2de57f7d256c00a5401ac6285d6a0145755`;
- internal checksums: **45/45**;
- five executables, two project static libraries, 27 fixture/input files;
- GNU C++ 14.2.0, CMake 3.31.6, Ninja, Release `-O2 -DNDEBUG`, static, `PRE_TEST`;
- approved targets: **7/7**;
- compile/link actions: **95/95**;
- wall time: 385.09 seconds;
- peak RSS: 1,529,528 KiB.

No generated project binary, test, benchmark, GoogleTest discovery command, CLI, GUI, help, list, or project runtime command was executed. This Code + Build turn makes no runtime-success claim.

## Implemented Gate 2 slice

- source-chart identity is first-class on trace intervals and lattice state;
- each trace interval records the exact source edge crossed to enter it;
- per-face branch rotation identifies the local branch corresponding to global lattice `+U`;
- interior transitions validate exact cross-field quarter-turn matching and reciprocal inverse metadata;
- deterministic source charts are connected regions of equal transported branch orientation;
- intrinsic source intervals carry local family/sign, chart, transition edge, component, sheet, and route provenance;
- missing, non-adjacent, ambiguous, or non-reciprocal transitions fail closed;
- structural hashes include chart and transition state;
- Gate 1 source-normal orientation and one-cell-to-one-quad materialization are preserved;
- fieldless production fixtures can request generated smooth cross fields through the ordinary production extractor.

No implementation behavior branches on fixture name, path, ID, vertex count, face count, or expected output count.

## Mandatory fixture expansion

The mandatory direct matrix is now:

1. plane;
2. multi-face seam;
3. close sheets;
4. cylinder;
5. `bunny_1k_random`;
6. vase.

All six must execute in Test + Benchmark turns. Later fixtures cannot be used to bypass an earlier failed gate.

### Randomized bunny

- SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`;
- 502 vertices, 1,000 triangles, 1,500 edges;
- closed, one component, no boundary/non-manifold/degenerate elements;
- same geometric bunny as the prior asset under a different vertex/face permutation;
- generated smooth cross field.

### Vase

- SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`;
- 1,274 vertices, 2,404 triangles, 3,677 edges;
- one component, one boundary loop, 142 boundary edges;
- no non-manifold or degenerate elements;
- generated smooth cross field.

Tests assert the exact topology and hashes so neither fixture can be silently simplified or replaced to make the implementation appear functional.

## Latest runtime authority

The latest executed evidence remains the preceding Gate 1 artifact:

| Fixture | Result | Traces | Direct cells / quads | Earliest failure |
|---|---:|---:|---:|---|
| Plane | pass | 352 | 64 / 64 | none |
| Multi-face seam | fail | 137 | 0 / 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Close sheets | fail | 158 | 0 / 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Cylinder | fail | 732 | 0 / 0 | `SideSubdivisionRepair:InvalidInputIncidence` |
| Bunny | not yet executed in mandatory matrix | — | — | pending artifact turn |
| Vase | not yet executed | — | — | pending artifact turn |

The last executed default inventory was 301/315. Do not reinterpret the compile-only fixture additions as runtime passes.

## Next authoritative turn

Execute:

`.agents/Directional/Gate_2_Cross_Chart_Mandatory_Fixtures_Artifact_Only_Test_Benchmark_Plan.md`

Required order:

1. verify artifact SHA-256 and 45 internal checksums;
2. verify source commits and all expected blobs;
3. verify bunny and vase hashes/topology;
4. run plane, seam, close sheets, cylinder, bunny, and vase in separate processes;
5. run all six even if an earlier gate fails, but preserve gate-order interpretation;
6. run remaining default suites;
7. run bounded independent determinism processes;
8. perform no rebuild or source/test/fixture/manifest/validator edit.

### Material-progress condition

Gate 2 material progress requires seam success or nonzero deterministic authoritative cross-chart cells reaching a first-class chart-transport/direct-materialization boundary. Unchanged zero-cell completion failure, fixture-specific success, or new diagnostics alone is not progress.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Cross_Chart_Mandatory_Fixtures_Local_Code_Build_Report.md`
- `.agents/Directional/Gate_2_Cross_Chart_Mandatory_Fixtures_Artifact_Only_Test_Benchmark_Plan.md`
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
7. latest Code + Build report
8. next artifact-only plan
9. latest runtime summary
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- A cross field supplies orientation but not authoritative lattice phase or connectivity.
- Gate 1 proves source-normal orientation and one-cell-to-one-quad materialization on a planar domain.
- Gate 2 must use exact source topology, reciprocal transition metadata, and chart/sheet provenance rather than global projection or proximity.
- Analytic fixtures isolate contracts but cannot establish production readiness alone.
- Real production fixtures must remain mandatory even while they expose blocked later contracts.
- Fixture topology and hashes must be asserted to prevent synthetic simplification.
- Generated smooth fields exercise the production field extractor; synthetic face-edge fields are not sufficient for bunny/vase acceptance.
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
