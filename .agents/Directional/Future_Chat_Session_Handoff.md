# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-07 UTC  
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

This rule was triggered for Gate 1. The mandatory Review selected **Outcome B — bounded producer replacement proof**. That bounded replacement has now been implemented and compile-verified. A third isolated phase-transition predicate repair remains prohibited.

## Gate state

1. G0 truthful authority — passed.
2. G1 uniform phase-front plane — **active; authoritative producer-boundary artifact verification pending**.
3. G2 cross-chart/close sheets — seam sub-contract proven; blocked by G1 and close-sheet failure.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **Gate 1 Authoritative Producer Boundary Code + Build** turn is complete.

### Source authority

- payload checkpoint: `983112aabbc618bec9032e1d2a07e32be00ed20f`;
- exact patch SHA-256: `a9af7d502a237a3f0a58324639f0fe77129de5fe5f147ea14b1e077545c5ccef`;
- coherent source commit: `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- payload cleanup commit: `bcf934d34e9a15f5d0929628ffd26f6833643214`.

Changed Git blobs:

- `include/directional/geometry/SurfaceCellTracing.h` → `b33c2118e65812d4b0a4a65fe9f46b7a8766bb59`;
- `src/geometry/SurfaceCellTracing.cpp` → `c9877d8ffa8aa5fbb59c83a1ab4b94eed5421431`;
- `include/directional/diagnostics/RemeshDiagnostics.h` → `8ddb4bcdf26a1caacdf927e74e56d3fe11b3e3b7`;
- `src/pipeline/RemeshPipeline.cpp` → `533648a1b1fd008286f3ef3292813817ad1f1146`;
- `src/bench/DirectionalBenchmark.cpp` → `73d9d29e49107073a44c2e9a6fe0e89331412737`;
- `tests/SurfaceCellsPhase10Tests.cpp` → `b726b85d189c5018d53c8561888dcda0ab55fa58`.

### Implemented authoritative producer boundary

The source now carries first-class producer disposition:

```text
NotApplicable
Produced
Rejected
```

- `NotApplicable`: the bounded uniform producer does not represent the topology; only this state may continue to a separately selected producer.
- `Produced`: authoritative phase/front cells are complete and materialize directly one accepted cell to one quad.
- `Rejected`: the producer was applicable but a fail-closed invariant failed; preserve typed rejection and stop the `SurfaceCells` request. Generic seeds/traces/proposals are not generated.

Applicability is determined before authoritative transition metadata is consumed from general topology/field state, never fixture identity.

`build_surface_cell_network()` now returns immediately for `Rejected`. The pipeline serializes the producer disposition, preserves typed first-invalid phase-front authority, records the tracing stage, and stops at tracing before FlowRep/arrangement/completion/output validation can substitute or overwrite the producer result. Producer disposition and typed rejection identity participate in structural hashing and benchmark diagnostics.

Hard-feature barriers remain authoritative. `reliefBarrierEdges` now veto authoritative transport only when `reliefBarriersEmbedded == true`, matching the existing tracing contract.

Existing ordinary shared-edge transport, ordered source-vertex fan transport, reciprocal quarter-turn transport, complete ordered route provenance, component/sheet ownership, source-normal orientation, and one authoritative cell → one quad remain preserved.

### Producer-level tests compiled but not executed

The source now includes/strengthens:

- duplicate transition metadata → explicit `Rejected` and zero generic substitution;
- relief guidance versus embedded relief authority;
- exact committed `plane.obj` + `plane.rawfield` through the real `remesh_from_raw_cross_field` production route;
- existing narrow source-vertex/fan and face-order contracts unchanged in strength.

The exact committed-plane test compiling is **not** runtime evidence. No generated project binary was executed this turn.

### Compile/build authority

Bounded GitHub Actions compile:

- workflow run `31154489371`;
- job `92790924907`;
- artifact `8984760467`;
- GNU C++ 13.3.0;
- CMake 3.31.6;
- Ninja 1.13.2;
- Release static build;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- 111/111 compile/link actions;
- 7/7 approved targets.

Immutable artifact:

- file: `directional-g1-authoritative-producer-boundary-build-artifact.zip`;
- SHA-256: `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031`;
- internal checksums: 44/44;
- five executables;
- two project static libraries;
- 27 fixture/input files;
- exact patch, source archive, compile database, logs, and authority metadata.

The bounded workflow/trigger and one-use source payload were removed after verification.

## Latest executed runtime authority — unchanged

The current Code + Build turn executed no project binary. The latest artifact-tested source remains `364a20e12165af7dbfe213bb6d075e3fe25b1574` with evidence SHA-256 `99a4922767d567830f202b440504f2b48d07fdb02bb117668baf846e7eeb9b64`.

Runtime matrix:

| Fixture | Result | Traces | Arrangement | Completed | Output quads |
|---|---:|---:|---:|---:|---:|
| Plane | fail | 106 | 9 | 12 | 0 |
| Seam | **pass** | 256 | 65 | 64 | 64 |
| Close sheets | fail | 158 | 0 | 0 | 0 |
| Cylinder | fail | 732 | 0 | 0 | 0 |
| Bunny | fail | 80,862 | 0 | 0 | 0 |
| Vase | fail | 116,922 | 0 | 0 | 0 |

The seam remains direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, no fallback/recovery, output hash `a8972efd7c4900a4`. Direct acceptance remains 1/6; non-overlapping total remains 305/321.

## Next authoritative turn

Execute `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Plan.md` using the exact immutable artifact above.

### Next turn boundary

- artifact-only;
- no configure, compile, relink, regeneration, or source/test/fixture/manifest/validator/build-logic edits;
- verify outer SHA-256 before extraction;
- verify 44/44 internal checksums;
- verify source commit/cleanup and all six changed blobs;
- verify bunny/vase exact hashes and topology;
- timeout is failure, never correctness evidence.

### Required execution order

Run explicit producer contracts first:

1. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`
2. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`
3. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`
4. `SurfaceCellsPhase10.UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded`
5. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
6. mandatory bunny/vase topology guard.

Then mandatory direct cases, all in order and all executed even after earlier failure:

1. plane
2. multi-face seam
3. close sheets
4. cylinder
5. bunny
6. vase

Then bounded determinism and non-overlapping remaining producer/completion/validation/compiled-API suites.

### Required direct observations

Record producer disposition, terminal stage/reason, requested/executed backend, phase-front attempted/succeeded/rejection context, trace count, authoritative phase-front cells, route/chart provenance, arrangement/simplification/direct/completion/output counts, output vertices/quads/non-quads, strict validation failures/first invalid, fallback/recovery/output origin, stage/structural/output hashes, wall time, and exit code.

### Acceptance hierarchy

1. **Gate 1 closure:** plane disposition `Produced` with direct deterministic `CompletedSurfaceCells` valid pure-quads, zero strict validation failures, no fallback/recovery, complete provenance; seam retains direct valid success. Next gate returns to G2 close sheets.
2. **Minimum architecture proof:** plane disposition `Rejected`, immutable typed tracing/phase-front authority, terminal at tracing, zero generic trace/arrangement/completion substitution, old 106/9/12 signature disappears, seam remains valid. This is material architecture progress but G1 remains red.
3. **No progress:** plane is `NotApplicable` and reaches generic 106/9/12, `Rejected` still substitutes generic work, typed rejection is overwritten, seam regresses, or acceptance is weakened. Another architecture Review is mandatory before local repair.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Live_Transition_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
- `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Local_Code_Build_Report.md`
- `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`
- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
6. `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Local_Code_Build_Report.md`
7. `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Plan.md`
8. latest executed Test + Benchmark report
9. latest runtime summary
10. `tests/TESTING_STRATEGY.md`
11. `.agents/Directional/GitHub_Workflow_Policy.md`
12. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not authoritative lattice phase/connectivity.
- Exact production preprocessing is part of producer authority; geometrically equivalent reconstructed fixtures are not necessarily execution-equivalent.
- Complete zero-turn and reciprocal quarter-turn metadata must share one exact transport contract.
- Source-vertex crossings require ordered source-topology fans, never positional jumps or arbitrary subsets.
- `NotApplicable` and `Rejected` must not be conflated.
- Authoritative rejection cannot be silently substituted by another internal producer.
- Typed first-rejection state is necessary authority but does not replace constructive success.
- Relief barriers become hard only when their embedded-authority flag says so.
- Real bunny/vase fixtures remain mandatory and may not be simplified or bypassed.
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
2. Retain only the live handoff, latest report(s) needed for current authority, next executable plan, current runtime summary, durable baselines, and durable design/remediation/workflow-policy documents.
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

Every completed turn ends with a new top-level PR #8 comment after all documentation and PR metadata updates. That comment is the **final repository write**.

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
