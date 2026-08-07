# Gate 3 Periodic Ring Correspondence — Artifact-Only Test + Benchmark Plan

## Turn boundary

This is an **artifact-only Test + Benchmark** turn.

Use exactly:

- artifact ID: `9008118764`;
- artifact name: `g3-periodic-ring-correspondence-code-build`;
- artifact SHA-256: `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- final source/test commit: `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- initial ring-correspondence implementation commit: `18f2c880f1714d8c41c9e11dadd53169756629fe`;
- initial implementation patch SHA-256: `49cd71bc5aafc33ccdfd5e5104e5a23c7452e72074aac3c7775794f55737d6de`;
- compile-only test correction patch SHA-256: `8c96fa983990ab6c3f3ace5b24b8af59678aa7d6a0b7ed4f57b06f1397d1cd56`;
- expected recursive checksum entries: **44/44**;
- successful build run/job: `31214404170` / `92984429773`;
- detailed log artifact: `9008117677`;
- detailed log SHA-256: `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`.

Final changed blobs:

- `include/directional/geometry/SurfaceCellTracing.h` → `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
- `src/geometry/SurfaceCellTracing.cpp` → `6980850bd32d40b1da9350ebbe3f601b8ce5e07b`;
- `tests/SurfaceCellsPhase10Tests.cpp` → `c4671ef674228d74b96e80499abbb6846bcdf3e3`.

Do not configure, compile, relink, regenerate discovery, or edit source, tests, fixtures, manifests, validators, benchmark logic, or build logic. Runtime-only fixture symlinks are allowed solely to expose immutable packaged fixture paths expected by the binaries.

Timeout is failure, never correctness evidence.

## Pre-execution integrity

Before running any packaged project binary:

1. verify the outer artifact SHA-256 exactly;
2. extract into a fresh arbitrary directory;
3. verify all **44/44** recursive checksums;
4. verify five executables, two project libraries, and 27 fixture/input files;
5. verify final source authority `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
6. verify both declared patch SHA-256 values and all three final changed blobs;
7. verify packaged command-boundary/build metadata records `runtimeExecution=false`, Release static, Ninja, seven approved targets, and `PRE_TEST` discovery mode;
8. verify exact plane, seam, close-sheet, cylinder, bunny and vase production fixtures remain covered by the packaged checksum manifest;
9. verify the detailed build log reaches `111/111`, `build_exit=0`, and `package_exit=0`.

If integrity fails, classify infrastructure invalid and stop. Do not repair packaged bytes or create a replacement build in this turn.

## Focused ring-correspondence contracts first

Run directly from the packaged producer-test executable, in fresh bounded processes where practical:

1. `SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`;
2. `SurfaceCellsPhase10.PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed`;
3. `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
5. `SurfaceCellsPhase10.PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`;
6. `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
7. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
8. `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`.

Then execute the retained passed-gate producer contracts required to prove no regression, including:

- exact committed plane authoritative producer boundary;
- disconnected close-sheet partition;
- close-sheet face-row invariance;
- ordered authoritative source-vertex-fan traversal;
- source-vertex-fan row-order invariance;
- duplicate-transition metadata fail-closed behavior;
- relief-guidance hard-stop only when embedded.

Record exact results. Do not weaken, replace, or reinterpret a failing contract.

### Field-authoritative correspondence evidence

For `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`, require the exact-source-vertex inter-ring V-family phase-front edges to be aligned with the authoritative transported axial field family. Do not replace the assertion with a cylinder vertex/ring/count special case.

For `PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed`, require typed `Rejected/AmbiguousPeriodicRingCorrespondence` and verify generic seeds/traces/proposals remain empty. Do not select a candidate through source ID, lexicographic order, count, frequency, arbitrary subset, or proximity.

## Direct acceptance order

Run each direct case in a fresh bounded process using `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled:

1. plane — mandatory G1 regression;
2. multi-face seam — mandatory G2 cross-chart regression;
3. close sheets — mandatory G2 source-sheet isolation regression;
4. cylinder — active G3 acceptance fixture;
5. randomized bunny — later production observation only;
6. vase — later production observation only.

Later fixtures cannot make G3 pass if cylinder fails.

## Cylinder G3 closure contract

G3 closes only if the exact committed cylinder proves all of the following simultaneously:

- authoritative producer disposition `Produced`;
- direct output origin `CompletedSurfaceCells`;
- non-empty pure-quadrilateral output and zero non-quads;
- first-class periodic holonomy available;
- quarter-turn holonomy rotation remains zero for this singularity-free cylinder;
- periodic lattice translation is integral, positive in the single periodic direction and has zero unsupported transverse component;
- ordered source holonomy route and deterministic source cut remain non-empty, canonical, reciprocal and source-authoritative;
- source-strip breakpoint authority remains consumed;
- artificial-cut counterparts pair reciprocally through exact periodic ownership and do not become output exterior seam edges;
- the two genuine source boundaries remain the only annulus exterior boundaries;
- adjacent-ring correspondence follows reciprocal transported cross-field family/sign authority and no diagonal source-ID/lexicographic tie-break remains;
- one accepted phase-front cell maps directly to one output quad;
- complete source provenance;
- zero completed-checkpoint/strict source-authoritative validation failures;
- `fieldP95Degrees <= 15.0`;
- `normalP95Degrees <= 15.0`;
- `warpageP95Degrees <= 30.0`;
- no fallback attempt/use;
- source-grid recovery disabled/unused;
- deterministic producer disposition, holonomy, ordered canonical route/cut identity, stage/structural hashes and output hash across independent processes;
- plane, seam and close sheets remain their proven direct strict-valid successes.

Do not require historical cylinder translation `29` or `32`, grid counts, output counts or provenance counts. Correct field-authoritative construction may legitimately alter deterministic cardinality.

A cylinder improvement that regresses any passed G0–G2 gate does not close G3.

## Compare with current runtime authority

Artifact `9004509871` / source `2783ea718ffb15f8fb3868795173472ab8636c1c` currently gives:

- cylinder periodic `Produced`;
- holonomy `r=0, t=(32,0)`, route 32, cut 4;
- 2,237 traces;
- 320 direct completed quads / 352 provenance vertices;
- three validation failures;
- normal P95 `16.6272734366°`;
- field P95 `37.9670987281°`;
- warpage P95 `30.6213792811°`;
- source-to-output P95 approximately `0.008174`;
- quad-to-source P95 approximately `0.031281`;
- terminal `completion/output-validation:AggregateCompletionValidationFailure`;
- no fallback/recovery;
- deterministic 3/3.

For artifact `9008118764`, explicitly compare:

- producer disposition and typed failure if any;
- periodic rotation/translation, route/cut canonical identity;
- correspondence focused-contract outcomes;
- traces/front/cell/provenance/output counts;
- output boundary/component evidence;
- normal/field/warpage P95 values;
- source approximation metrics;
- completed validation failures and terminal stage;
- output origin;
- stage/structural/output hashes;
- wall time and memory when available.

Changed counts are not regressions by themselves; correctness, field authority and strict validation decide acceptance.

## Required observations per direct case

Record at minimum:

- producer disposition;
- terminal stage/reason;
- requested/executed backend;
- phase-front attempted/succeeded and typed failure context;
- phase-front cell/edge/event counts;
- periodic holonomy availability, rotation, translation, route-edge count and cut-edge count;
- trace count;
- source component/local-sheet counts;
- arrangement, simplification, direct, completion and output counts;
- output vertices/quads/non-quads;
- output connected-component/boundary-loop evidence when available;
- completed-checkpoint and strict validation failures;
- normal/field/warpage P95 plus source-approximation metrics when exposed;
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
- bunny: at least 1 bounded process;
- vase: at least 1 bounded process, second only if the first completes within the runtime budget.

Compare producer disposition, periodic holonomy tuple, ordered canonical route/cut identity, stage counts, validation values/failure identity, structural hashes and output hashes. Timeout remains failure only.

## Default suites

After focused contracts and active direct cases:

1. run the remaining producer suite excluding already executed focused tests;
2. run completion/simplification suite;
3. run validation suite;
4. run compiled API suite.

Report direct gate status separately from aggregate totals. Scheduler-sensitive timing remains closeout/performance evidence and cannot override functional gate results.

## Decision hierarchy

### G3 closure

Cylinder remains periodic `Produced`, consumes field-authoritative ring correspondence, and becomes direct deterministic strict-valid `CompletedSurfaceCells` pure-quad output with zero validation failures, all three quality P95 thresholds within existing limits, correct exact periodic quotient, retained source-strip authority and G0–G2 green. Advance to **G4 topology-distinct completion and singularities**.

### Material progress, G3 still open

The field-authoritative ring correspondence is live/consumed and the exact cylinder reaches a new later source-authoritative quality/structural failure with no generic substitution/fallback and G0–G2 green. Preserve the exact failure and make the next Code + Build address only that general defect.

### Regression / no progress

Keep G3 active if cylinder returns to `NotApplicable`, loses valid holonomy, selects a correspondence by incidental identity/count/order/frequency, introduces a false exterior cut seam/proximity weld, regresses source-strip authority, or breaks plane/seam/close sheets. Apply the mandatory no-progress rule when applicable.

## Required evidence and closeout

Preserve exact commands, raw stdout/stderr, artifact/checksum verification, focused/default test results, benchmark JSON, validation-quality values, periodic holonomy/correspondence records, determinism comparisons, machine-readable runtime summary and an evidence archive with recursive checksums/SHA-256.

At turn end update live authority documents, remove superseded plans/reports as required by hygiene, verify only approved durable workflow/temporary-state rules, and make the required new top-level PR #8 comment the final repository write.

## Prohibitions

- no rebuild or relink;
- no source/test/fixture/manifest/validator edits;
- no validator weakening;
- no fixture/ID/count/order/frequency ownership special cases;
- no Euclidean/nearest-point periodic seam welding;
- no fallback/recovery substitution;
- no arbitrary subset search;
- no synthetic counters/Euler correction;
- no post-hoc cell splitting/merging;
- no timeout-as-correctness.
