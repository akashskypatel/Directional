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

This rule was triggered for Gate 1. The mandatory Review selected **Outcome B — bounded producer replacement proof**. That replacement was implemented, compile-verified, and artifact-tested successfully. A third isolated Gate 1 phase-transition predicate repair remains prohibited.

## Gate state

1. G0 truthful authority — passed.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart/close sheets — **active; bounded producer extension is compile-valid and runtime verification is pending**.
4. G3 periodic closure/holonomy — blocked.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G2 Close-Sheet Authoritative Producer Code + Build** turn is complete.

### Design declaration used by the turn

```text
Active design gate: G2 cross-chart/close-sheet isolation
Earliest failing fixture: close_sheets__surface_cells
Missing design contract: authoritative uniform phase/front applicability and construction across multiple disconnected but spatially close source sheets without positional cross-sheet coupling
Smallest general implementation change: partition the existing uniform phase/front producer and direct materializer by authoritative source component/local-sheet identity while preserving the proven per-sheet transport contract
Observable material-progress condition: close_sheets becomes direct deterministic Produced pure-quads with no cross-sheet provenance/merge violation while plane and seam remain valid regressions
Explicitly deferred work: cylinder holonomy, singularities, topology-distinct completion, adaptive scale/features, bunny/vase production/performance, timing, downstream completion/simplification failures
```

### G2 source authority

- production source commit: `218dd3ec3f6399dc82183390720a4ba4d3a70b42`;
- architecture patch SHA-256: `7b99d8a7ff227c2e4f07a1498805eb7fd34b542b772d3bd0c1bb1e455e31fa8c`;
- changed blobs:
  - `src/geometry/SurfaceCellTracing.cpp` → `c9570ecb4a9557eebaf0e30b751e2ccca90b2973`;
  - `src/pipeline/RemeshPipeline.cpp` → `55af3205fd7cdb8f21357ac69516ffa29cf8a6d3`;
  - `tests/SurfaceCellsPhase10Tests.cpp` → `7151077d7d4e0a10dad388dd008479f96fc1aae8`.

Implemented bounded contracts:

1. uniform phase/front work is partitioned by authoritative `(source component, local sheet)` before construction;
2. source lookup, edge incidence, boundary classification, and planar-frame checks are restricted to the active sheet;
3. proven reciprocal ordinary-edge and ordered source-vertex-fan transport is reused independently per sheet;
4. independent sheet results are concatenated only after each succeeds;
5. an applicable sheet invariant failure remains authoritative `Rejected`;
6. unsupported/periodic topology remains `NotApplicable` for later gates;
7. direct output lattice identity is `(component, sheet, u, v)`, preventing equal lattice coordinates on unrelated sheets from merging;
8. authoritative boundary loops are source-sheet-local;
9. disconnected-sheet isolation and source-face-row-order invariance regressions were added and compiled.

The review of the completed source change found it aligned with the bounded G2 contract. Runtime correctness is intentionally unclaimed until artifact execution.

### Compile authority

The first bounded compile found one ordinary syntax error in the new sheet-map key expression and failed before linking. The single syntax defect was corrected surgically without changing the design contract, then the same approved compile scope passed.

Successful build authority:

- workflow run/job/artifact: `31179899458` / `92870408341` / `8994541137`;
- artifact name: `g2-close-sheet-code-build`;
- artifact SHA-256: `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`;
- detailed log artifact: `8994539982`;
- log SHA-256: `c7d67285ca6b980111a53fe017b3de5800abccb2a3146352135c0d674ca0acc8`;
- recursive checksums: **45/45 passed**;
- compile/link actions: **111/111**;
- approved targets: **7/7**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- compiler/toolchain: GNU C++ 13.3.0, CMake 3.31.6, Ninja 1.13.2, Release static, `PRE_TEST`;
- generated project binary/test/benchmark execution: **none**.

Failed compile diagnostic authority:

- run/job: `31179523041` / `92869190592`;
- log artifact: `8994261249`;
- log SHA-256: `85276a0781c348f51970f4c9953cd9e805adbb2fbce444e6e4310ff12c46fa1a`.

The bounded G2 workflow, trigger, and turn payload were removed after artifact/log verification. Only the approved retained workflow and its durable dependencies remain.

## Gate 1 closure authority — mandatory regressions

Artifact-tested Gate 1 authority remains:

- source commit `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- artifact `8984760467`;
- artifact SHA-256 `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031`;
- recursive checksums **44/44 passed**;
- six explicit producer/topology contracts **6/6 passed**.

Direct proven regressions:

- plane: `Produced`, direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero strict validation failures, no fallback/recovery, deterministic hash suffix `730caeae49ec872c` across 3/3 benchmark processes;
- multi-face seam: `Produced`, 81 vertices, 64 pure quads, zero validation failures, no fallback/recovery, deterministic hash `a8972efd7c4900a4` across 3/3 processes.

The former plane 106 traces / 9 arrangement / 12 completion / no-output signature is eliminated. G1 is closed and both fixtures are mandatory regressions for every later gate.

## Latest executed runtime matrix

The latest runtime matrix is **unchanged by the G2 Code + Build turn** because no generated project binary was executed:

| Fixture | Result | Producer disposition | Traces | Arrangement | Completed quads |
|---|---:|---|---:|---:|---:|
| Plane | **pass** | `Produced` | 352 | 65 | 64 |
| Seam | **pass** | `Produced` | 256 | 65 | 64 |
| Close sheets | fail | `NotApplicable` | 158 | 0 | 0 |
| Cylinder | fail | `NotApplicable` | 732 | 0 | 0 |
| Bunny | fail | `NotApplicable` | 80,862 | 0 | 0 |
| Vase | timeout/fail | not fully observed | — | — | — |

Close sheets remains the earliest failing runtime fixture until artifact `8994541137` is executed. Cylinder is G3 and must not supersede the G2 decision. Bunny/vase remain later mandatory observations; timeout is failure only and never correctness evidence.

## Next authoritative turn

**Artifact-only Test + Benchmark — G2 Close-Sheet Authoritative Producer.**

Execute exactly `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Plan.md` against artifact `8994541137`.

### Mandatory artifact authority

- artifact ID: `8994541137`;
- artifact name: `g2-close-sheet-code-build`;
- artifact SHA-256: `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`;
- source commit: `218dd3ec3f6399dc82183390720a4ba4d3a70b42`;
- expected recursive checksums: **45/45**;
- build run/job: `31179899458` / `92870408341`;
- log artifact: `8994539982`, SHA-256 `c7d67285ca6b980111a53fe017b3de5800abccb2a3146352135c0d674ca0acc8`.

### Test + Benchmark turn boundary

1. Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, validators, benchmark logic, or build logic.
2. Runtime-only fixture symlinks are allowed only to expose packaged fixture paths without modifying packaged bytes.
3. Verify outer artifact digest, all 45 recursive checksums, exact source authority, changed blobs, five executables, two project libraries, and 27 fixture/input files before executing any project binary.
4. If integrity fails, classify infrastructure invalid and stop; do not repair packaged source or inputs.
5. Execute the two new close-sheet producer contracts first.
6. Revalidate plane and seam as mandatory passed-gate regressions.
7. Execute exact production close sheets as the active G2 acceptance fixture.
8. Prove output source component/local-sheet separation and absence of unrelated cross-sheet vertex/edge/twin/cell/route/ownership merges.
9. Run bounded determinism and non-overlapping default suites only after the active acceptance cases.
10. Observe cylinder/bunny/vase only after the G2 decision; later cases cannot make G2 pass.
11. For `Rejected`, verify generic producer substitution does not occur. For `NotApplicable`, record it separately and never reinterpret it as success.
12. Timeout is failure only, never correctness evidence.

### G2 acceptance hierarchy

**G2 closure:** exact close sheets is direct deterministic strict-valid `Produced` pure-quad `CompletedSurfaceCells` output with complete source provenance and zero cross-sheet coupling, while plane and seam remain valid. Next implementation gate becomes G3 periodic cylinder/holonomy.

**Material progress, G2 still open:** the correct disconnected-sheet domain becomes applicable and advances to a new authoritative typed `Rejected` state or otherwise removes the prior structural ambiguity without cross-sheet coupling, while plane/seam remain valid. Next Code + Build addresses only that exact general rejection.

**No material progress/regression:** close sheets remains on the same generic `NotApplicable` path without a justified new structural contract, unrelated sheets cross-merge, `Rejected` falls through to generic substitution, or plane/seam regress. Keep G2 active and apply the no-progress rule when applicable.

## Default-suite baseline evidence

Latest executed non-overlapping baseline remains:

- remaining `SurfaceCellsPhase10.*`: **23/24 passed**, only scheduler-sensitive `StrictValidatorOverheadStaysBelowFivePercent` failed its 5% timing ratio;
- completion/simplification executable: **154/164 passed**;
- validation executable: **60/60 passed**;
- compiled API executable: **8/8 passed**.

Direct gate ordering outranks aggregate totals. Scheduler timing, downstream completion/simplification failures, cache/memory work, and broad performance are deferred while G2 is red.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Authoritative_Producer_Code_Build_Report.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/REORIENTATION_PLAN.md`
6. `.agents/Directional/Gate_2_Close_Sheet_Authoritative_Producer_Code_Build_Report.md`
7. `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Plan.md`
8. `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Report.md`
9. `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Report.md`
10. latest runtime summary
11. `tests/TESTING_STRATEGY.md`
12. `.agents/Directional/GitHub_Workflow_Policy.md`
13. the turn-based coding-agent skill and relevant Code + Build, testing-integrity, recovery, handoff, connector-workflow, and unit-testing references.

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
- Plane and seam prove the authoritative phase/front producer on connected planar/seam domains.
- Spatial proximity must never substitute for source component/local-sheet identity on close sheets.
- G2 now has compile-valid sheet partitioning and sheet-qualified materialization, but only artifact execution may establish runtime correctness.
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
