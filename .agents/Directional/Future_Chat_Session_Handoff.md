# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-06  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Mandatory design-first operating mandate

Every future agent must prioritize `.agents/Directional/DESIGN.md` over local repair activity and work on the earliest incomplete or regressed high-level gate. Diagnostics, taxonomies, cache/memory work, scheduling, performance, historical cleanup, or downstream repair machinery must not become the principal objective while an earlier constructive gate is red.

Before any code change, write:

```text
Active design gate:
Earliest failing fixture:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

Material progress means an active direct fixture passes, a missing first-class contract becomes live and consumed, or a general structural ambiguity is removed. New diagnostics, counters, hashes, equivalent failure movement, aggregate gains, performance work, fallback/recovery, or fixture-specific behavior are not material progress alone.

### Mandatory no-progress stop rule

If two consecutive Code + Build turns do not materially advance the earliest active gate, the next turn must be a design review or bounded producer replacement proof.

## Gate state

1. G0 truthful authority — passed.
2. G1 uniform phase-front plane — **active; second bounded Code + Build complete, artifact-only verification pending**.
3. G2 cross-chart/close sheets — seam sub-contract proven; blocked by G1 and close-sheet failure.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The Gate 1 live-transition Code + Build turn is complete.

### Exact source and build authority

- tested parent source: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- payload checkpoint: `5b9892bd9f3a3e51cf8af49b0d492450529ff765`;
- patch SHA-256: `b45802f0ede3cfd490fae5453ad60041e991a9f5ba2715e53566fd8db0fb79ba`;
- source commit: `364a20e12165af7dbfe213bb6d075e3fe25b1574`;
- payload cleanup: `591ada601843237a709d2d6e133a438ca403f042`;
- source-sync run/job: `31147985555` / `92771436461`;
- source-sync evidence artifact: `8982197509`, SHA-256 `27c7f435a2c26b4b6c6df2ccc0ff258f297ddea129df657d1af2d795ba3a43e4`;
- local build artifact: `directional-g1-live-transition-local-build-artifact.zip`;
- artifact SHA-256: `922be37c4ee849152dee40168e3e8604357af46189d6491124b7b83dce7ca741`;
- internal checksums: 45/45;
- five executables, two project static libraries, 27 fixture/input files;
- approved targets: 7/7;
- archived changed-file blobs: 4/4 exact.

Final source blobs:

```text
f04bc39c8b83f6ac673c19560296c2f4041c38c8  include/directional/geometry/SurfaceCellTracing.h
d604348b895c797ab2f5cf59885894cff3961fe6  src/geometry/SurfaceCellTracing.cpp
e4ab7f9aa236c6719a3b0ba13cd63a08dc4845a5  src/pipeline/RemeshPipeline.cpp
44f68df797e988c678194cb3ac3072081ff3424c  tests/SurfaceCellsPhase10Tests.cpp
```

No generated project binary, test, benchmark, discovery command, CLI, GUI, help command, or list command was executed. This turn makes no plane or seam runtime-success claim.

### Confirmed implementation contract

Static emulation of the exact committed plane triangulation and 8x8 phase-front grid found 16 transitions where consecutive selected source-face intervals meet at one source vertex without sharing an edge. The former Gate 2 shared-edge-only predicate rejected the first such transition before authoritative phase-front construction.

The source now:

- exposes typed first phase-front rejection state and source cell/side/face/vertex/edge context;
- propagates that state into existing first-invalid-producer diagnostics;
- leaves ordinary shared-edge transition handling unchanged;
- classifies exact shared-vertex attachment from source barycentric endpoints;
- derives at most the two manifold fan directions from source topology;
- selects exactly one route by the directed geometric side of the lattice segment;
- traverses every route edge through authoritative `resolve_branch_transition`;
- requires component/sheet compatibility, no hard/relief barrier, final face/family/sign agreement, and complete canonical source-edge provenance;
- records the ordered edge route in hashing and memory accounting;
- fails closed for disconnected, repeated, non-manifold, ambiguous, invalid, missing-provenance, or branch-mismatched fans;
- contains no fixture-specific condition, arbitrary subset search, positional jump, fallback, recovery, or validator weakening.

Contract-level tests were added for valid multi-edge source-vertex traversal, face-row reordering invariance, duplicate metadata typed failure, and one-cell-to-one-quad construction. They compiled but were not executed.

### Last runtime authority

The last executed artifact remains the rejected restoration package:

| Fixture | Result | Traces | Arrangement | Completed | Output quads |
|---|---:|---:|---:|---:|---:|
| Plane | fail | 106 | 9 | 12 | 0 |
| Seam | **pass** | 256 | 65 | 64 | 64 |
| Close sheets | fail | 158 | 0 | 0 | 0 |
| Cylinder | fail | 732 | 0 | 0 | 0 |
| Bunny | fail | 80,862 | 0 | 0 | 0 |
| Vase | fail | 116,922 | 0 | 0 | 0 |

Direct acceptance is 1/6. The seam remains direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, output hash `a8972efd7c4900a4`, fallback `Fail`, and no recovery. The new artifact must not be described as successful until artifact-only execution proves it.

## Next authoritative turn

Execute `.agents/Directional/Gate_1_Live_Transition_Artifact_Only_Test_Benchmark_Plan.md`.

Required order:

1. verify the artifact and 45 checksums;
2. run the new source-vertex contract tests without changing them;
3. run plane first and capture typed rejection context if it remains red;
4. run seam second and preserve direct reciprocal quarter-turn output;
5. continue close sheets, cylinder, bunny, and vase;
6. run non-overlapping default suites and bounded determinism processes;
7. rebuild nothing and edit nothing.

If artifact-only evidence does not materially advance Gate 1 beyond the prior 106/9/12 signature, the mandatory following turn is a design review or bounded producer replacement proof. A third local predicate-repair turn is not authorized.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Live_Transition_Local_Code_Build_Report.md`
- `.agents/Directional/Gate_1_Live_Transition_Artifact_Only_Test_Benchmark_Plan.md`
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
5. latest Code + Build report
6. next artifact-only Test + Benchmark plan
7. latest runtime summary
8. `tests/TESTING_STRATEGY.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`
10. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not authoritative lattice phase/connectivity.
- Empty prescribed-field metadata is absence, but the ordinary raw-field finalization path populates matching, effort, and transitions before tracing.
- Complete zero-turn metadata and reciprocal quarter-turn metadata must use one general source-topology transport contract.
- A source-vertex crossing is represented by a unique ordered incident-edge fan, never a positional face jump or arbitrary subset.
- Typed first-rejection state is necessary authority but does not replace constructive success.
- Analytic fixtures isolate contracts but real bunny/vase fixtures remain mandatory.
- Fixture hashes/topology prevent synthetic simplification.
- Direct gates outrank aggregate totals.
- Scheduler timing ratios are closeout evidence, not functional correctness.
- `PRE_TEST` preserves compile-only boundaries.

## Mandatory turn hygiene and instruction preservation

These requirements apply to every Code + Build, Test + Benchmark, optional Review, and documentation-maintenance turn.

### Workflow and temporary payload cleanup

1. At the start and end of every turn, inspect `.github/workflows` and all temporary triggers, transfer files, payload/patch directories, and generated artifacts.
2. Remove stale bounded or turn-specific workflows before work begins.
3. During remote compile, retain only approved durable workflows plus at most one bounded workflow and its exact payload.
4. After artifact/log verification, remove bounded workflows, triggers, and payloads.
5. Final branch state must contain only approved durable workflows and no stale generated artifact.
6. Do not remove a durable dependency consumed by an approved retained workflow.
7. Retain exact payloads until their source commit, expected blobs, and build authority are verified; then remove them.

### Documentation and result cleanup

1. End every turn by removing stale/superseded plans, reports, closure notes, evidence indexes, and results from `.agents` and `benchmark-results`.
2. Retain only the live handoff, latest report, next executable plan, current authority, latest runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
3. Retained documents may reference only existing files.
4. Git history and PR conversation are the historical archive.
5. Never delete latest evidence or next-turn instructions before verified replacements exist.

### Mandatory instruction preservation

1. **Never remove, weaken, consolidate away, reinterpret, or silently replace an existing mandatory instruction in this handoff unless the user explicitly requests it.**
2. Handoff edits are additive or narrowly corrective by default; preserve all procedural, safety, scope, cleanup, validation, repository-write, and turn-boundary requirements.
3. Compare handoff updates with the prior version and verify every pre-existing mandatory instruction remains materially present.
4. If a new instruction conflicts, preserve both and request user direction rather than deleting either.
5. Documentation cleanup never authorizes removal of mandatory handoff rules.

## End-of-turn requirement

Every completed turn ends with a new top-level PR #8 comment after all documentation and PR metadata updates. That comment is the final repository write.

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
