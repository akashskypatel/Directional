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

The preceding G3 artifact materially advanced the gate: exact cylinder moved from `NotApplicable` generic tracing to deterministic authoritative periodic `Produced` with 290 direct completed quads. This Code + Build turn then made the missing first-class source-strip breakpoint contract live in the producer and compile-verified it. The no-progress rule is therefore not triggered. Runtime material acceptance of the new source remains pending the next artifact-only turn.

## Gate state

1. G0 truthful authority — **passed**.
2. G1 uniform authoritative phase-front plane — **passed**.
3. G2 cross-chart / close-sheet isolation — **passed**.
4. G3 periodic closure / holonomy — **active; periodic authority is runtime-proven, source-strip output-validation correction is compile-valid, runtime revalidation pending**.
5. G4 topology/singularities — blocked.
6. G5 adaptive scale/hard features — blocked.
7. G6 full production geometry — blocked as success gate; bunny/vase remain mandatory observations.
8. G7 hardening/default-on — blocked.

## Completed turn

The **G3 Periodic Output Validation Code + Build** turn is complete.

Authoritative Code + Build report: `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Report.md`.

### Design declaration used by the turn

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: a Produced periodic phase-front must materialize its cut-quotiented annular cells into a source-authoritative completed quad mesh that passes the existing pre-optimization validation without shortcutting canonical source-strip structure; row-order invariance must be compared in canonical source identity rather than DCEL edge numbering
Smallest general implementation change: preserve canonical annulus source-strip breakpoints in periodic lattice/materialization, choosing deterministic per-strip subdivisions nearest the target size so output sides do not bridge source topological corners, while retaining exact periodic holonomy quotient and one accepted cell -> one quad; separately correct the row-order contract test to compare ordered canonical source-edge endpoint keys instead of raw sourceEdge IDs
Observable material-progress condition: exact cylinder remains Produced with the same valid periodic authority and reaches zero completed-checkpoint validation failures/direct CompletedSurfaceCells output, while plane, seam, and close sheets remain strict-valid deterministic regressions; the row-order test passes by canonical endpoint identity without weakening its holonomy invariants
Explicitly deferred work: torus/general genus, singularity topology and G4 completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production, scheduler timing, and unrelated historical completion/simplification failures
```

## Latest executed runtime authority — unchanged by Code + Build

The latest executed G3 authority is still source `56f823273cad041a01ebb4d0772c3265ff248f4a`, artifact `9001168379`.

Artifact-only Test + Benchmark established:

| Fixture | Result | Producer | Holonomy | Traces | Completed quads | Validation | Hash |
|---|---:|---|---|---:|---:|---:|---|
| Plane | **pass** | `Produced` | — | 352 | 64 | 0 | `730caeae49ec872c` |
| Seam | **pass** | `Produced` | — | 256 | 64 | 0 | `5bdf34d7802e9fb0` |
| Close sheets | **pass** | `Produced` | — | 1,104 | 200 | 0 | `89b052762f52a5af` |
| Cylinder | **fail / material progress** | `Produced` | `r=0, t=(29,0), route=32, cut=4` | 2,163 | 290 | 2 failures | — |
| Bunny | later gate | `NotApplicable` | — | 80,862 | 0 | — | — |
| Vase | later gate | `NotApplicable` | — | 116,922 | 0 | — | — |

No passing case uses fallback or source-grid recovery.

### Cylinder runtime blocker

The exact cylinder consumes first-class periodic authority and is deterministic 3/3, but the completed checkpoint terminates at:

- `NotProductionReady:completion`;
- first invalid producer stage `completion/output-validation`;
- reason `AggregateCompletionValidationFailure`;
- exactly two aggregate validation failures;
- output origin `None` because the completed checkpoint is correctly rejected.

The benchmark record does **not** serialize the two individual `SurfaceFinalValidationReport` threshold fields. Never claim a specific threshold is proven and never relax validation.

The previous `t=(29,0)` is historical runtime evidence, not a future acceptance constant. The new source-strip-conforming producer is allowed to choose a different deterministic integral U translation.

### Latest executed focused/default evidence

- focused/retained producer contracts: **11/12**;
- remaining producer executable excluding those 12: **82/86**;
- completion/simplification: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- non-overlapping total: **315/330**.

The sole focused failure was the row-enumeration test's raw DCEL ID comparison. Runtime evidence proved the ordered canonical source-endpoint route/cut identities were equal. The source test expectation is corrected in this Code + Build turn but is not yet executed.

The known scheduler-sensitive validator timing ratio remains performance/closeout evidence. The ten completion/simplification failures and bunny/vase direct acceptance remain deferred by gate order. Direct gate status outranks aggregate totals.

## G3 source-strip output-validation implementation

Exact production/test source commit:

- `2783ea718ffb15f8fb3868795173472ab8636c1c`

Source patch and changed blobs:

- patch SHA-256 `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
- `src/geometry/SurfaceCellTracing.cpp` → `9df9a9759c761293fef1278f97b82fbb0aee0600`;
- `tests/SurfaceCellsPhase10Tests.cpp` → `c9dcbe9f67ba239c061ddb295f40c9b82ebafb49`.

No validator, fixture, benchmark, API, materializer, fallback, or recovery source changed.

### Constructive change

The periodic annulus producer now preserves canonical source-strip structure before materialization:

1. the already-derived canonical annulus source rings define ordered source strips;
2. every canonical strip endpoint is a mandatory intrinsic periodic lattice breakpoint;
3. each strip's intrinsic transported length is combined with local target-size samples from both source endpoints over every canonical ring;
4. each strip gets a deterministic positive nearest-integer subdivision count from `stripLength / localTarget`;
5. invalid/non-finite/overflowing subdivision state fails closed as `InvalidPeriodicChart`;
6. cumulative nonuniform periodic coordinates are built strip by strip, inserting the exact source-strip endpoint at the end of every strip;
7. `gridU` and periodic holonomy translation are the sum of strip subdivisions;
8. phase-front points, cells, side paths, and intrinsic cell validation consume those nonuniform source-strip-conforming coordinates directly;
9. axial construction and the two genuine annulus boundaries remain unchanged;
10. exact periodic quotient identity and one accepted cell → one output quad remain intact.

No post-hoc cell split/merge, Euclidean seam welding, nearest-point repair, validator bypass, fallback/recovery, fixture identity, or hard-coded source-ring/output count was added.

### Row-order semantic identity correction

`PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` now maps each mesh's route/cut source-edge IDs through that mesh's authoritative `EV` table to canonical endpoint keys `(min(v0,v1), max(v0,v1))` and compares the **ordered** key sequences. It does not sort away route order. Existing grid, rotation, translation, disposition, route/cut cardinality, and periodic assertions remain.

### New structural regression source

`SurfaceCellsPhase10.PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints` derives genuine source boundary vertices from `EV/EF` and requires every one to occur as an exact phase-front corner on the two genuine annulus boundaries. It does not hard-code the committed cylinder ring count or expected output count.

Both test changes are compile-valid only until the next artifact turn executes them.

## Compile-only authority

Successful bounded build:

- workflow run/job: `31204848178` / `92953250176`;
- artifact: `9004509871` (`g3-periodic-output-validation-code-build`);
- artifact SHA-256: `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`;
- detailed log artifact: `9004508508` (`g3-periodic-output-validation-code-build-logs`);
- log SHA-256: `80c6ab8997caafb49306adf3496a9dd20f1e2c029f63f8a71237e9b7e68a292b`;
- recursive checksums: **44/44 passed**;
- compile/link actions: **111/111**;
- approved targets: **7/7**;
- packaged closure: five executables, two project libraries, 27 fixture/input files;
- toolchain: GNU C++ 13.3.0, CMake 3.31.6, Ninja 1.13.2, Release static, `PRE_TEST`;
- packaged command boundary: `runtimeExecution=false`;
- generated project binary/test/benchmark execution: **none**.

The downloaded build and log archives matched the GitHub outer digests. Compilation establishes source validity only. **No new cylinder runtime-success claim is permitted from this turn.**

The bounded workflow, trigger marker, and source payload were removed after artifact/log/source verification.

## Next authoritative turn

**Artifact-only Test + Benchmark — G3 Periodic Output Validation.**

Execute exactly `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9004509871`.

### Mandatory artifact authority

- artifact ID: `9004509871`;
- artifact name: `g3-periodic-output-validation-code-build`;
- artifact SHA-256: `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`;
- source commit: `2783ea718ffb15f8fb3868795173472ab8636c1c`;
- source patch SHA-256: `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
- expected recursive checksums: **44/44**;
- build run/job: `31204848178` / `92953250176`;
- log artifact: `9004508508`, SHA-256 `80c6ab8997caafb49306adf3496a9dd20f1e2c029f63f8a71237e9b7e68a292b`.

### Test + Benchmark turn boundary

1. Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, validators, benchmark logic, or build logic.
2. Runtime-only fixture symlinks are allowed only to expose packaged immutable fixture paths expected by the binaries.
3. Verify outer artifact digest, all 44 recursive checksums, exact source authority, patch, changed blobs, five executables, two project libraries, and fixture closure before executing any project binary.
4. If integrity fails, classify infrastructure invalid and stop; do not repair packaged source or inputs.
5. Execute the six focused periodic/output-validation producer contracts first.
6. Revalidate plane, seam, and close sheets as mandatory passed-gate regressions.
7. Execute exact production cylinder as the active G3 acceptance fixture.
8. Require source-strip breakpoint retention, exact periodic quotient, absence of a false exterior seam/Euclidean weld, and zero completed-checkpoint validation failures.
9. Do **not** require the historical translation `t=(29,0)`; accept the new deterministic integral translation if semantically valid.
10. Run bounded determinism and non-overlapping default suites only after the active acceptance cases.
11. Observe bunny/vase only after the G3 decision; later cases cannot make G3 pass.
12. For `Rejected`, verify generic producer substitution does not occur. For `NotApplicable`, record it separately and never reinterpret it as success.
13. Timeout is failure only, never correctness evidence.

### Focused contracts to run first

1. `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
2. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
3. `SurfaceCellsPhase10.PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
5. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
6. `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`.

Then run retained plane/source-fan/close-sheet contracts required by the exact plan.

### G3 acceptance hierarchy

**G3 closure:** exact cylinder remains authoritative periodic `Produced` and becomes direct deterministic strict-valid pure-quad `CompletedSurfaceCells` output with source-strip-conforming periodic lattice/quotient, zero completed-checkpoint validation failures, artificial cut absent from exterior output, complete provenance, no fallback/recovery, and plane/seam/close sheets green. Advance to G4 topology-distinct completion and singularities.

**Material progress, G3 still open:** cylinder remains on the authoritative periodic path and reaches a new exact source-authoritative structural/validation failure after source-strip conformity, with zero fallback/generic substitution and G0–G2 green. The next Code + Build addresses only that exact general failure.

**No material progress/regression:** cylinder returns to `NotApplicable`, loses valid periodic authority, treats the cut as exterior, relies on proximity repair, fails the source-strip breakpoint contract, or regresses a passed gate. Apply the no-progress rule when applicable.

## Current authoritative documents

- `TODO`
- `MILESTONE_G_TODO.md`
- this handoff
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
- `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Report.md`
- `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `benchmark-results/design-aligned-runtime-summary.json`
- `tests/TESTING_STRATEGY.md`

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. this handoff
4. `.agents/Directional/DESIGN.md`
5. `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Report.md`
6. `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Report.md`
7. `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/Surface_Cell_Backend_Remediation_Plan.md`
10. latest runtime summary
11. `tests/TESTING_STRATEGY.md`
12. `.agents/Directional/GitHub_Workflow_Policy.md`
13. the turn-based coding-agent skill and relevant Test + Benchmark, testing-integrity, recovery, handoff, connector-workflow, and unit-testing references.

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
- Plane proves the bounded authoritative phase/front on a connected planar domain.
- Seam proves reciprocal cross-chart transport.
- Spatial proximity must never substitute for source component/local-sheet identity; close sheets prove this at production runtime.
- Periodic topology requires explicit holonomy and cannot be represented by declaring an artificial chart cut to be a real boundary.
- Periodic seam identification must use exact source/phase/lattice authority, never Euclidean welding.
- The exact cylinder proves periodic `Produced` authority and deterministic holonomy; the active runtime defect remains completed output validation until the new artifact is executed.
- Raw DCEL edge integers are incidental identities across independently enumerated meshes; compare canonical source-edge endpoint identity when row-order invariance explicitly permits canonical renumbering.
- Source-route provenance alone does not justify a straight direct output side skipping a mandatory source topological corner; periodic construction must retain canonical source-strip breakpoints upstream of materialization.
- Per-strip deterministic target subdivisions may legitimately change periodic lattice translation; historical grid counts are evidence, not required constants.
- Validation remains authoritative; when benchmark serialization reports only an aggregate validation failure, do not invent the individual failed thresholds.
- Compile-valid source is not runtime proof; exact artifact execution decides gate closure.
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
- no Euclidean periodic seam welding;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.