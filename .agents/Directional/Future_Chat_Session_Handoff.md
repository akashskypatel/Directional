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
2. G1 uniform phase-front plane — **active; first restoration artifact tested and rejected**.
3. G2 cross-chart/close sheets — seam sub-contract proven; blocked by G1 and close-sheet failure.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The Gate 1 regression-restoration artifact-only Test + Benchmark turn is complete.

### Exact artifact and evidence authority

- tested source commit: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- tested source blob: `850971a60b75dd84a81ddd4d260998f7ec9c326a`;
- artifact: `directional-g1-regression-restoration-local-build-artifact.zip`;
- artifact SHA-256: `c516af42f6aa388ef219408ef63e939490176385e976885f1ea9176ec3609e20`;
- internal checksums: 44/44;
- five executables, two project static libraries, 27 fixture/input files;
- evidence archive: `directional-g1-regression-restoration-artifact-only-test-evidence.zip`;
- evidence SHA-256: `57e2f247dbf1cb7ad4c2470f30fa8ec7705b888ec891515ce61b76c329cd2591`;
- evidence files covered by checksums: 114;
- rebuild performed: no;
- source, test, fixture, manifest, validator, fallback, or recovery edit: no.

### Runtime authority

| Fixture | Result | Traces | Arrangement | Completed | Output quads |
|---|---:|---:|---:|---:|---:|
| Plane | fail | 106 | 9 | 12 | 0 |
| Seam | **pass** | 256 | 65 | 64 | 64 |
| Close sheets | fail | 158 | 0 | 0 | 0 |
| Cylinder | fail | 732 | 0 | 0 | 0 |
| Bunny | fail | 80,862 | 0 | 0 | 0 |
| Vase | fail | 116,922 | 0 | 0 | 0 |

Direct acceptance is 1/6. All benchmark cases were structurally deterministic across independent processes. The seam remains direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, output hash `a8972efd7c4900a4`, fallback `Fail`, and no recovery.

Default suites are 301/312: remaining producer 79/80, completion 154/164, validation 60/60, compiled API 8/8. Direct gates remain separate and authoritative.

### Durable root-cause correction

The rejected patch treated empty matching/effort/transition containers as absent metadata. That condition is not reached by the actual prescribed-plane pipeline:

1. `finalize_surface_cell_raw_cross_field()` computes principal matching;
2. it copies matching and effort into `CrossFieldResult`;
3. it populates edge transitions;
4. those nonempty containers are passed into the phase-front producer.

The compiled patch was therefore behaviorally unreachable on the plane, which is consistent with unchanged stage hashes and counts.

The leading next-failure candidate is the Gate 2 requirement that consecutive selected segment intervals share one source edge. A segment can pass exactly through a triangulation vertex, causing consecutive intervals to meet at the vertex without one shared edge. This is a source-review inference, not a runtime-proven diagnosis, because the current producer exposes only Boolean failure.

## Next authoritative turn

Execute `.agents/Directional/Gate_1_Live_Transition_Path_Code_Build_Plan.md`.

The next turn must:

1. compare the successful Gate 1 parent `aea10409c73c490b92f78760b73191641ef823c6` with the tested source;
2. expose a typed first phase-front rejection result and consume it in diagnostics;
3. confirm the first rejected invariant on the exact complete-metadata plane route;
4. implement only the confirmed general topology transition correction;
5. preserve ordinary reciprocal edge transitions, chart/sheet ownership, and the seam contract;
6. add contract-level tests without weakening existing tests;
7. compile the approved seven targets and execute no generated project binary;
8. package a fresh immutable artifact for plane-first testing.

This is the second bounded Code + Build attempt after one non-advancing restoration. If its artifact-only verification does not materially advance Gate 1, the mandatory following turn is a design review or bounded producer replacement proof.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Regression_Restoration_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Live_Transition_Path_Code_Build_Plan.md`
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
5. latest Test + Benchmark report
6. next Code + Build plan
7. latest runtime summary
8. `tests/TESTING_STRATEGY.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`
10. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, and connector-workflow references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not authoritative lattice phase/connectivity.
- Empty prescribed-field metadata is absence, but the ordinary raw-field finalization path populates matching, effort, and transitions before tracing.
- Complete zero-turn metadata and reciprocal quarter-turn metadata must use one general source-topology transport contract.
- A source-vertex crossing must be represented by a unique ordered incident-edge fan, never a positional face jump; this candidate must be confirmed by typed rejection evidence before implementation.
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
