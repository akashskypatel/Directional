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

**This stop rule is now active.** Two bounded Gate 1 Code + Build attempts were artifact-tested without material plane advancement. A third local predicate-repair turn is not authorized.

## Gate state

1. G0 truthful authority — passed.
2. G1 uniform phase-front plane — **active mandatory producer-architecture design review**.
3. G2 cross-chart/close sheets — seam sub-contract proven; blocked by G1 and close-sheet failure.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The Gate 1 live-transition artifact-only Test + Benchmark turn is complete.

### Exact artifact and evidence authority

- tested source commit: `364a20e12165af7dbfe213bb6d075e3fe25b1574`;
- payload cleanup: `591ada601843237a709d2d6e133a438ca403f042`;
- artifact: `directional-g1-live-transition-local-build-artifact.zip`;
- artifact SHA-256: `922be37c4ee849152dee40168e3e8604357af46189d6491124b7b83dce7ca741`;
- internal checksums: 45/45;
- five executables, two project static libraries, 27 fixture/input files;
- changed source blobs: 4/4 exact;
- evidence archive: `directional-g1-live-transition-artifact-only-test-evidence.zip`;
- evidence SHA-256: `99a4922767d567830f202b440504f2b48d07fdb02bb117668baf846e7eeb9b64`;
- evidence files covered by checksums: 118;
- rebuild/configure/relink performed during test turn: no;
- source, test, fixture, manifest, validator, fallback, or recovery edit during test turn: no.

A runtime-only `bin/test-data -> ../test-data` symlink was used because the immutable package stores fixtures beside `bin` while the compiled fixture resolver expects `bin/test-data`. No packaged byte was modified.

### Runtime authority

Explicit contract/topology tests: **4/4**.

| Fixture | Result | Traces | Arrangement | Completed | Output quads |
|---|---:|---:|---:|---:|---:|
| Plane | fail | 106 | 9 | 12 | 0 |
| Seam | **pass** | 256 | 65 | 64 | 64 |
| Close sheets | fail | 158 | 0 | 0 | 0 |
| Cylinder | fail | 732 | 0 | 0 | 0 |
| Bunny | fail | 80,862 | 0 | 0 | 0 |
| Vase | fail | 116,922 | 0 | 0 | 0 |

Direct acceptance remains 1/6.

The seam remains direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, output hash `a8972efd7c4900a4`, fallback `Fail`, and no recovery.

The plane remains `NotProductionReady:completion` with 15 validation failures. Its tracing structural hash changed to `18291124109639474708`, but the constructive 106/9/12 signature did not move. This is not material progress.

All required benchmark cases were structurally deterministic across three processes for plane/seam/close-sheets/cylinder and two processes for bunny/vase.

Default/non-overlapping evidence:

- remaining producer: 78/79; only `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` failed;
- completion: 154/164, same ten historical/downstream failures;
- validation: 60/60;
- compiled API: 8/8;
- non-overlapping total including explicit contract/direct tests: 305/321.

### Durable review findings

1. All new source-vertex fan tests pass, but the exact production plane does not produce direct phase-front output.
2. `make_vertex_fan_plane_mesh()` reconstructs the same rectangular geometry with different indexing and directly injects a constant target size. It is a valid isolated contract fixture but not production-path authority.
3. Future Gate 1 implementation must include producer-level proof using the exact committed `plane.obj` and `plane.rawfield` with production cross-field finalization, target-size computation, source labels, features/barriers, and tracing options.
4. `RemeshPipeline.cpp` records a typed `tracing/phase-front` first-invalid result but later generic completion failure paths overwrite the same diagnostic fields. Final benchmark JSON therefore does not preserve the authoritative phase-front rejection.
5. More importantly, the pipeline continues from phase-front non-success into the generic tracing/arrangement/completion producer. The next review must determine whether that substitution is a valid general architecture or the reason local repairs are failing to establish one coherent producer authority path.
6. The last successful Gate 1 source `aea10409c73c490b92f78760b73191641ef823c6` remains mandatory comparison authority. Compare it semantically with Gate 2 source `21f081b330418a0f34709f61d857f54a03d2fd48`, first restoration `a90f6b9de83dba4aeac359b2f63d735e2049b54e`, and current `364a20e...`.

## Workflow status

GitHub workflow operations have returned to normal. Future **authorized Code + Build turns may use GitHub Actions to compile binaries and create artifacts again**, while still following `.agents/Directional/GitHub_Workflow_Policy.md` and all workflow/payload hygiene rules below. Test + Benchmark turns remain artifact-only. The next mandatory Review turn does not require a build.

## Next authoritative turn

Execute `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Plan.md`.

This is a Review turn. Do not modify production source, tests, fixtures, validators, fallback/recovery, or build logic.

Required review work:

1. reconstruct the exact committed plane production route from manifest/raw field through finalization, labels, target size, tracing options, `build_surface_cell_network`, phase-front outcome, and downstream producer selection;
2. compare `aea10409...` → `21f081b...` → `a90f6b...` → `364a20e...` for semantic control-flow changes;
3. explain why the isolated fan contract passes while the production fixture remains on 106/9/12;
4. audit whether authoritative phase-front failure/result remains first-class or is silently substituted/overwritten by generic tracing/completion;
5. choose exactly one evidence-backed outcome:
   - bounded architectural correction; or
   - bounded producer replacement proof;
6. produce exactly one next Code + Build plan with explicit success/failure criteria;
7. do not authorize another isolated predicate patch.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Live_Transition_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Plan.md`
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
6. next Design Review plan
7. latest runtime summary
8. `tests/TESTING_STRATEGY.md`
9. `.agents/Directional/GitHub_Workflow_Policy.md`
10. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, review, and connector-workflow references.

## Durable lessons

- Passed earlier gates are mandatory regressions and become active immediately when broken.
- A cross field supplies orientation, not authoritative lattice phase/connectivity.
- Empty prescribed-field metadata is absence, but the ordinary raw-field finalization path populates matching, effort, and transitions before tracing.
- Complete zero-turn metadata and reciprocal quarter-turn metadata must use one general source-topology transport contract.
- A source-vertex crossing is represented by a unique ordered incident-edge fan, never a positional face jump or arbitrary subset.
- Typed first-rejection state is necessary authority but does not replace constructive success.
- Synthetic/reconstructed contract fixtures isolate invariants but do not replace exact production-fixture pipeline coverage.
- The exact production target size, labels, options, metadata, and mesh indexing are first-class until invariance is proven.
- Internal producer substitution must not be mistaken for user-visible fallback semantics; one coherent source-authoritative producer outcome is required.
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
