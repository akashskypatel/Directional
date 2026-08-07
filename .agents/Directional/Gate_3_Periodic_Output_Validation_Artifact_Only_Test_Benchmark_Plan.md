# Gate 3 Periodic Output Validation — Artifact-Only Test + Benchmark Plan

## Turn boundary

This is an **artifact-only Test + Benchmark** turn.

Use exactly:

- artifact ID: `9004509871`
- artifact name: `g3-periodic-output-validation-code-build`
- artifact SHA-256: `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`
- source commit: `2783ea718ffb15f8fb3868795173472ab8636c1c`
- source patch SHA-256: `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`
- expected recursive checksum entries: **44/44**
- successful build run/job: `31204848178` / `92953250176`
- detailed log artifact: `9004508508`
- detailed log SHA-256: `80c6ab8997caafb49306adf3496a9dd20f1e2c029f63f8a71237e9b7e68a292b`

Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, validators, benchmark logic, or build logic. Runtime-only fixture symlinks are allowed solely to expose immutable packaged paths expected by the binaries.

Timeout is failure, never correctness evidence.

## Pre-execution integrity

Before running any packaged project binary:

1. verify the outer artifact SHA-256 exactly;
2. extract into a fresh arbitrary directory;
3. verify all **44/44** recursive checksums;
4. verify five executables, two project libraries, and 27 fixture/input files;
5. verify source authority `2783ea718ffb15f8fb3868795173472ab8636c1c`;
6. verify source patch SHA-256 `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
7. verify changed blobs:
   - `src/geometry/SurfaceCellTracing.cpp` `9df9a9759c761293fef1278f97b82fbb0aee0600`;
   - `tests/SurfaceCellsPhase10Tests.cpp` `c9dcbe9f67ba239c061ddb295f40c9b82ebafb49`;
8. verify packaged command-boundary metadata records `runtimeExecution=false`;
9. verify exact plane, seam, close-sheet, cylinder, bunny, and vase production inputs are present and unchanged from the packaged checksum manifest.

If integrity fails, classify infrastructure invalid and stop. Do not repair packaged bytes or create a replacement build in this turn.

## Focused producer contracts first

Run directly from the packaged producer-test executable:

1. `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`
2. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`
3. `SurfaceCellsPhase10.PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`
4. `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`
5. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`
6. `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`

Then run the retained passed-gate producer contracts required to prove no regression, including:

- `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
- `SurfaceCellsPhase10.UniformPhaseFrontPartitionsDisconnectedCloseSheetsBySourceAuthority`
- `SurfaceCellsPhase10.UniformPhaseFrontCloseSheetsIgnoresFaceRowEnumeration`
- the ordered source-vertex-fan / reciprocal transition contracts used by G1/G2 authority.

Record every exact result. Do not weaken or replace a failing contract.

For the row-order test, confirm that the **ordered canonical endpoint-key route and cut sequences** agree across face-row reversal. Do not substitute unordered sets or raw DCEL integers.

For the new source-strip test, confirm that all source boundary vertices derived from authoritative boundary edges appear as exact phase-front corners on the two genuine annulus boundaries. Do not replace the assertion with a fixture count.

## Direct acceptance order

Run each direct case in a fresh bounded process using `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled:

1. plane — mandatory G1 regression;
2. multi-face seam — mandatory G2 cross-chart regression;
3. close sheets — mandatory G2 isolation regression;
4. cylinder — active G3 acceptance fixture;
5. randomized bunny — later production observation only;
6. vase — later production observation only.

Later fixtures cannot make G3 pass if cylinder fails.

## Cylinder G3 acceptance

G3 closes only if the exact cylinder demonstrates all of the following:

- authoritative producer disposition `Produced`;
- direct `CompletedSurfaceCells` output;
- non-empty pure-quadrilateral output and zero non-quads;
- first-class periodic holonomy available;
- holonomy quarter-turn rotation remains compatible with the singularity-free cylinder and equals zero for the committed cylinder;
- periodic lattice translation is integral, positive in the single periodic lattice direction, and has zero unsupported transverse component;
- **do not require the previous translation `t=(29,0)`**: source-strip-conforming subdivision is allowed and expected to change periodic grid cardinality;
- ordered periodic source route and deterministic source cut remain non-empty, canonical, reciprocal, and source-authoritative;
- artificial-cut front edges pair reciprocally through periodic ownership and do not become output exterior seam edges;
- the two genuine source boundary loops remain the only annulus exterior boundaries;
- all canonical source-strip breakpoints required by the source topology are retained by the periodic lattice/materialization;
- one accepted phase-front cell still maps directly to one output quad;
- no Euclidean/nearest-point seam welding, post-hoc splitting/merging, or topology repair;
- complete source provenance;
- **zero completed-checkpoint / strict source-authoritative validation failures**;
- no fallback attempt/use;
- source-grid recovery disabled/unused;
- deterministic holonomy, producer/stage/structural, and output hashes across independent processes;
- plane, seam, and close sheets remain their proven strict-valid direct successes.

A cylinder improvement that regresses any passed G0–G2 gate does not close G3.

## Compare with previous G3 artifact

The prior tested authority `9001168379` had:

- cylinder periodic `Produced`;
- holonomy `r=0`, `t=(29,0)`, route 32 edges, cut 4 edges;
- 2,163 traces;
- 290 completed quads / 319 provenance vertices;
- two aggregate completed-mesh validation failures;
- terminal `completion/output-validation:AggregateCompletionValidationFailure`;
- deterministic 3/3;
- no fallback/recovery.

For the new artifact, explicitly compare:

- producer disposition;
- periodic translation/grid cardinality;
- route/cut canonical endpoint identities;
- trace/front/cell counts;
- direct quad/provenance counts;
- completed-checkpoint validation failures and terminal stage;
- output origin;
- structural/output hashes;
- runtime/memory where available.

Changed counts are not regressions by themselves; correctness and source-authoritative validation decide acceptance.

## Required observations per direct case

Record at minimum:

- producer disposition;
- terminal stage and reason;
- requested/executed backend;
- phase-front attempted/succeeded and typed failure context;
- authoritative phase-front cell/edge/event counts;
- periodic holonomy availability, rotation, translation, route-edge count, and cut-edge count;
- trace count;
- source component/local-sheet counts;
- arrangement, simplification, direct, completion, and output counts;
- output vertices, quads, and non-quads;
- output connected-component and boundary-loop evidence;
- completed-checkpoint and strict validation failure counts plus first invalid reason when exposed;
- fallback/recovery state;
- output origin;
- producer/stage/structural/output hashes;
- wall time, peak memory when available, and exit code.

For `Rejected`, verify generic producer substitution does not occur. For `NotApplicable`, report it separately and do not reinterpret it as success.

## Determinism

After first-pass direct acceptance:

- plane: 3 independent processes;
- seam: 3;
- close sheets: 3;
- cylinder: 3;
- bunny: at least 1 bounded process, second only if reasonable;
- vase: at least 1 bounded process, second only if the first completes within the runtime budget.

Compare producer dispositions, periodic holonomy tuple, ordered canonical route/cut identities, stage counts, typed failure identities, structural hashes, and output hashes. Timeout remains failure only.

## Default suites

After focused contracts and active direct cases:

1. run the remaining producer suite excluding already executed focused tests;
2. run completion/simplification suite;
3. run validation suite;
4. run compiled API suite.

Report direct gate acceptance separately from aggregate totals. Scheduler-sensitive timing remains closeout/performance evidence and cannot override functional gate results.

## Decision hierarchy

### G3 closure

Cylinder remains periodic `Produced` and becomes direct deterministic strict-valid `CompletedSurfaceCells` pure-quad output with zero completed-checkpoint validation failures, source-strip-conforming periodic lattice/materialization, correct exact periodic quotient, and retained plane/seam/close-sheet success. The next implementation gate becomes **G4 topology-distinct completion and singularities**.

### Material progress, G3 still open

Cylinder remains on the authoritative periodic path and reaches a new exact structural/validation failure after source-strip conformity, with no fallback/generic substitution and G0–G2 green. The next Code + Build turn addresses only that exact general failure.

### Regression / no progress

Keep G3 active if cylinder returns to `NotApplicable`, loses valid holonomy, gains an artificial exterior seam, relies on proximity welding/repair, fails source-strip breakpoint authority, or regresses plane/seam/close sheets. Apply the no-progress rule when applicable.

## Required evidence and closeout

Preserve exact commands, raw stdout/stderr, fixture integrity, artifact digest/checksum verification, focused/default test results, benchmark JSON, periodic-holonomy records, determinism comparisons, machine-readable summary, and an evidence archive with SHA-256/recursive checksums.

At turn end update live authority documents, remove superseded plans/reports as required by hygiene, verify only approved durable workflows/temporary-state rules, and make the required new top-level PR #8 comment the final repository write.

## Prohibitions

- no rebuild or relink;
- no source/test/fixture/manifest/validator edits;
- no validator weakening;
- no fixture/ID/count/order special cases;
- no Euclidean/nearest-point periodic seam welding;
- no fallback/recovery substitution;
- no arbitrary subset search;
- no synthetic counters/Euler correction;
- no post-hoc cell splitting/merging;
- no timeout-as-correctness.
