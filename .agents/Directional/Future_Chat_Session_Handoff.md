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

This rule was triggered for Gate 1. The mandatory Review selected **Outcome B — bounded producer replacement proof**. That bounded replacement has now been implemented, compile-verified, and artifact-tested successfully. A third isolated phase-transition predicate repair remains prohibited.

## Gate state

1. G0 truthful authority — passed.
2. G1 uniform phase-front plane — **passed**.
3. G2 cross-chart/close sheets — **active**; seam sub-contract proven, close sheets failing.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **Gate 1 Authoritative Producer Boundary artifact-only Test + Benchmark** turn is complete.

### Exact artifact authority

- source commit: `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- payload cleanup: `bcf934d34e9a15f5d0929628ffd26f6833643214`;
- workflow run/job/artifact: `31154489371` / `92790924907` / `8984760467`;
- archive: `directional-g1-authoritative-producer-boundary-build-artifact.zip`;
- outer SHA-256: `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031`;
- recursive checksums: **44/44 passed**;
- packaged closure: five executables, two project static libraries, 27 fixture/input files;
- six changed-file blob identities matched packaged source authority;
- bunny SHA-256: `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`;
- vase SHA-256: `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`.

This test turn did not configure, compile, relink, regenerate discovery, or edit source/tests/fixtures/manifests/validators/build logic. Runtime-only symlinks were used only to expose packaged fixture paths expected by compiled tests; no packaged byte changed.

### Explicit producer-contract tests

All required prerequisite checks passed:

1. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`;
2. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`;
3. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`;
4. `SurfaceCellsPhase10.UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded`;
5. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`;
6. `SurfaceCellMandatoryProductionFixtures.BunnyAndVaseAreNontrivialManifoldProductionInputs`.

### Gate 1 closure

The exact production plane now succeeds directly:

- `surfaceCellAuthoritativeProducerDisposition = Produced`;
- requested/executed backend `SurfaceCells`;
- fallback policy `Fail`, no fallback attempt;
- source-grid recovery disabled and unused;
- terminal failure `None`;
- output origin `CompletedSurfaceCells`;
- 81 provenance/output vertices;
- 64 pure quads;
- zero strict validation failures;
- output hash suffix `730caeae49ec872c`.

Three independent benchmark processes reproduced the same `Produced` disposition, 352 traces, 65 arrangement cells, 64 quads, and output hash.

The previous plane failure signature — 106 traces / 9 arrangement cells / 12 completion candidates / no output — is eliminated.

The multi-face seam remains a mandatory direct success:

- `Produced`;
- 256 traces;
- 65 arrangement cells;
- 64 pure quads;
- 81 vertices;
- zero validation failures;
- no fallback/recovery;
- deterministic output hash `a8972efd7c4900a4` in 3/3 independent benchmark processes.

Therefore **G1 is closed**.

## Latest direct runtime matrix

| Fixture | Result | Producer disposition | Traces | Arrangement | Completed | Output quads |
|---|---:|---|---:|---:|---:|---:|
| Plane | **pass** | `Produced` | 352 | 65 | 64 | 64 |
| Seam | **pass** | `Produced` | 256 | 65 | 64 | 64 |
| Close sheets | fail | `NotApplicable` | 158 | 0 | 0 | 0 |
| Cylinder | fail | `NotApplicable` | 732 | 0 | 0 | 0 |
| Bunny | fail | `NotApplicable` | 80,862 | 0 | 0 | 0 |
| Vase | timeout/fail | not fully observed | — | — | — | 0 |

### Close sheets — active G2 blocker

- disposition `NotApplicable`;
- 158 generic traces;
- zero arrangement cells;
- zero completed quads;
- terminal `NotProductionReady:completion`;
- no fallback/recovery.

This is the earliest failing direct fixture and is the only principal objective for the next Code + Build turn.

### Cylinder

- disposition `NotApplicable`;
- 732 traces;
- zero arrangement/completion;
- terminal `NotProductionReady:completion`.

G3 remains blocked by G2; do not broaden the next turn into periodic holonomy.

### Bunny and vase

Bunny completed one direct benchmark process as a failure:

- wall 53.493351 s;
- disposition `NotApplicable`;
- 80,862 traces;
- zero arrangement/completion;
- terminal `NotProductionReady:completion`;
- no fallback/recovery.

A direct bunny GoogleTest exceeded its bounded execution window before completion; that timeout is not correctness evidence.

Vase exceeded the 180 s bounded runtime window. Timeout is failure only and no correctness conclusion is allowed. Bunny/vase remain mandatory G6 observations but cannot supersede G2.

## Default-suite evidence

- remaining `SurfaceCellsPhase10.*`: **23/24 passed**;
  - only scheduler-sensitive `StrictValidatorOverheadStaysBelowFivePercent` failed its 5% timing ratio;
- completion/simplification executable: **154/164 passed**, same ten downstream failures;
- validation executable: **60/60 passed**;
- compiled API executable: **8/8 passed**.

Direct gate ordering outranks aggregate totals. The timing ratio, completion/simplification failures, cache/memory work, and performance are deferred while G2 is red.

## Next authoritative turn

**Code + Build — G2 close-sheet authoritative producer extension.** Review policy is `never`, so the Test + Benchmark next-action plan is authoritative.

Before editing, write exactly this status declaration:

```text
Active design gate: G2 cross-chart/close-sheet isolation
Earliest failing fixture: close_sheets__surface_cells
Missing design contract: authoritative uniform phase/front applicability and construction across multiple disconnected but spatially close source sheets without positional cross-sheet coupling
Smallest general implementation change: extend the existing authoritative phase/front producer from the proven plane/seam domain to independent same-topology sheet components using source component/local-sheet authority and exact per-component transition/fan routing; do not alter cylinder/periodic logic
Observable material-progress condition: close_sheets disposition becomes Produced and yields direct deterministic valid pure quads with zero cross-sheet provenance/merge violations while plane and seam remain unchanged regressions
Explicitly deferred work: cylinder holonomy, singularities, topology-distinct completion, adaptive scale/hard features, bunny/vase production/performance, scheduler timing, downstream completion/simplification failures
```

### Required G2 implementation constraints

1. Preserve `NotApplicable / Produced / Rejected` semantics exactly.
2. Determine applicability from general topology/field/source-sheet state, never fixture identity, counts, names, bounding boxes, or output expectations.
3. Partition authoritative producer state by source component/local-sheet **before** phase/front construction.
4. A front on one disconnected sheet must never inspect, snap to, merge with, capture, inherit phase from, or share ownership with another sheet solely because world-space positions are close.
5. Reuse the already proven ordinary source-edge and ordered source-vertex-fan transport contract independently within each authoritative sheet.
6. Preserve complete ordered source-route provenance and reciprocal quarter-turn transport on every sheet.
7. Concatenate accepted authoritative cells only after each cell preserves exact source component/local-sheet authority and one accepted cell → one quad.
8. Canonical output must be invariant to source component enumeration and source-face row ordering except canonical renumbering.
9. If an applicable sheet fails an invariant, return `Rejected` with typed producer authority; do not substitute generic tracing for that sheet.
10. Keep periodic topology such as cylinder explicitly outside G2; it may remain `NotApplicable` until G3.
11. Add or strengthen unit tests only where necessary to prove disconnected-close-sheet independence and ordering invariance. Do not weaken direct acceptance tests or validators.
12. Code + Build turn only: configure/compile approved targets as authorized, but execute no generated project binary, test, benchmark, CLI, help/list command, or discovery command.
13. Use `PRE_TEST` or equivalent compile-only-safe discovery configuration.
14. Package an immutable artifact containing exact source authority, changed blobs, binaries/libraries, required fixtures, logs, recursive checksums, and outer digest for the next artifact-only Test + Benchmark turn.
15. Plane and seam are mandatory regressions in the next Test + Benchmark artifact.

## Current authoritative documents

- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
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
5. `.agents/Directional/REORIENTATION_PLAN.md`
6. `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Report.md`
7. `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
8. latest runtime summary
9. `tests/TESTING_STRATEGY.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`
11. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, connector-workflow, and unit-testing references.

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
- Plane and seam now prove the authoritative phase/front producer on connected planar/seam domains.
- Spatial proximity must never substitute for source component/local-sheet identity on close sheets.
- Real bunny/vase fixtures remain mandatory and may not be simplified or bypassed.
- Direct gates outrank aggregate totals.
- Scheduler timing ratios are closeout evidence, not functional correctness.
- `PRE_TEST` preserves compile-only boundaries.
- Timeout is failure only, never correctness evidence.

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
