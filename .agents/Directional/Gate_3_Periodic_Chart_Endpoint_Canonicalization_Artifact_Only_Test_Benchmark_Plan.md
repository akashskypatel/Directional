# Gate 3 Periodic Chart Endpoint Canonicalization — Artifact-Only Test + Benchmark Plan

## Turn boundary

This is an **artifact-only Test + Benchmark** turn.

Use exactly:

- artifact ID `9010838200`;
- artifact name `g3-periodic-chart-endpoint-canonicalization-code-build`;
- artifact SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- source/test commit `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- base production source checkpoint `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`;
- patch SHA-256 `f6cd294846a6a8fc3c04a356c4044e5be9e3f9ddc9f35d9b451e27b3849df9b8`;
- build run/job `31221873296 / 93007996817`;
- log artifact `9010837410`;
- log SHA-256 `2b994f158e8a28ecdc52fd3c532b48edf936aeaaf8284053a728b56a58979973`;
- recursive checksum entries **44/44**.

Final blobs:

- `include/directional/geometry/SurfaceCellTracing.h` `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
- `src/geometry/SurfaceCellTracing.cpp` `63e5ee427f675077f710db51ffb56d91838d3519`;
- `tests/SurfaceCellsPhase10Tests.cpp` `bef95b04c95c9a213c634e604d004b3d7d22646e`.

Do not configure, compile, relink, regenerate discovery, or edit production/test/fixture/manifest/validator/benchmark/build logic. Runtime-only symlinks may expose immutable packaged fixture paths and must be recorded.

Timeout is failure only, never correctness evidence.

## Pre-execution integrity

Before executing any packaged project binary:

1. download artifact `9010838200` fresh;
2. verify outer SHA-256 exactly;
3. extract into a fresh arbitrary directory;
4. verify all **44/44** recursive checksums;
5. verify five executables, two project libraries and 27 fixture/input files;
6. verify source commit, patch SHA and all three declared blobs from the packaged source authority/archive;
7. verify Release static / Ninja / seven approved targets / `PRE_TEST` and `runtimeExecution=false` metadata;
8. verify build log reaches `111/111`, `build_exit=0` and `package_exit=0`;
9. verify exact cylinder fixture hashes:
   - OBJ `59ed6d736410dbef6bc751136ba0eb1d557a43c9df63fb2a570daf85c79419ae`;
   - raw field `6e861e06fa5d3dd6ed84c48bf7d459df701acd7f6ab241cc2adbde66d829084d`.

If integrity fails, classify infrastructure invalid and stop. Do not repair packaged bytes or create a replacement build during this turn.

## Focused contracts first — 17 retained/active contracts

Run from the packaged producer-test executable in fresh bounded processes where practical.

### Endpoint-canonicalization contracts

1. `SurfaceCellsPhase10.PeriodicPhaseFrontCanonicalizesSourceSimplexEndpoints`;
2. `SurfaceCellsPhase10.PeriodicChartEndpointCanonicalizationKeepsGenuineOverlapRejected`.

Required evidence from contract 1:

- exact cylinder phase front reaches `Produced` rather than `InvalidPeriodicChart`;
- emitted barycentrics are finite, normalized and inside the exact source simplex;
- source-vertex endpoints are exact one-hot barycentrics;
- no tolerance-only zero-length source segment is emitted;
- adjacent periodic cell sides share the same exact source-space breakpoint;
- unchanged strict `validate_closed_boundary_paths()` returns `Accepted`.

Contract 2 must continue to allow only a true shared endpoint while rejecting overlap beyond it. Do not modify or reinterpret the strict predicate.

### Field-authoritative ring-correspondence contracts

3. `SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`;
4. `SurfaceCellsPhase10.PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed`.

Contract 3 must reach its axial-field-family assertion and pass. Contract 4 must remain typed `Rejected/AmbiguousPeriodicRingCorrespondence` with generic seeds/traces/proposals empty.

### Retained G3 periodic contracts

5. `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
6. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
7. `SurfaceCellsPhase10.PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`;
8. `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
9. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
10. `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`.

All six nominal G3 periodic contracts that regressed in artifact `9008118764` must return to their intended `Produced`/typed behavior for material progress.

### Retained G1/G2 contracts

Then run the seven established passed-gate contracts:

- exact committed plane authoritative producer boundary;
- disconnected close-sheet partition;
- close-sheet face-row invariance;
- ordered authoritative source-vertex-fan traversal;
- source-vertex-fan row-order invariance;
- duplicate transition metadata fail-closed behavior;
- relief guidance becomes a hard stop only when embedded.

G0-G2 remain mandatory regressions.

## Direct acceptance order

Run each direct case in a fresh bounded process with requested backend `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled:

1. plane;
2. multi-face seam;
3. close sheets;
4. exact cylinder — active G3 fixture;
5. randomized bunny — later-gate observation only;
6. vase — later-gate observation only.

Later fixtures cannot make G3 pass if cylinder fails.

## Cylinder minimum material-progress contract

Compared with artifact `9008118764`, exact cylinder must at minimum:

- advance beyond `Rejected/InvalidPeriodicChart` cell 29;
- retain field-authoritative adjacent-ring correspondence;
- avoid generic producer substitution, fallback and source-grid recovery;
- retain source-strip, cut and periodic quotient authority if the producer reaches those stages;
- keep G0-G2 green.

Restoring the old diagonal/lexicographic correspondence is not progress even if it reaches a later stage.

If the cylinder becomes authoritative periodic `Produced` but later fails completed output validation, record exact validation fields/values and classify **material progress, G3 still open**. Address only that next general defect in the following Code + Build turn.

## G3 closure contract

G3 closes only if exact cylinder proves all of the following simultaneously:

- producer disposition `Produced`;
- direct output origin `CompletedSurfaceCells`;
- non-empty pure-quadrilateral output, zero non-quads;
- field-authoritative adjacent-ring correspondence consumed;
- first-class periodic holonomy available and valid;
- singularity-free cylinder quarter-turn rotation remains zero;
- integral positive periodic translation in the supported direction with zero unsupported transverse component;
- ordered canonical holonomy route and deterministic source cut remain non-empty, reciprocal and source-authoritative;
- source-strip breakpoint authority retained;
- artificial cut is paired through exact periodic ownership and does not become an exterior seam;
- only the two true annulus boundaries remain exterior;
- one accepted phase-front cell maps directly to one output quad;
- complete source provenance;
- zero completed-checkpoint/strict validation failures;
- `fieldP95Degrees <= 15.0`;
- `normalP95Degrees <= 15.0`;
- `warpageP95Degrees <= 30.0`;
- no fallback attempt/use;
- source-grid recovery disabled/unused;
- deterministic producer disposition, holonomy, canonical route/cut identity, stage hashes and output hash across independent processes;
- plane, seam and close sheets retain their proven direct strict-valid outputs.

Historical cylinder translation/grid/output/provenance counts are not acceptance constants.

## Comparison authorities

### Immediately preceding artifact — regression state

Artifact `9008118764`, source `c5d2c90...`:

- focused/retained **9/15**;
- cylinder `Rejected/InvalidPeriodicChart`, cell 29;
- zero traces/arrangement/completion/output;
- no terminal holonomy;
- deterministic 3/3;
- no fallback/recovery.

### Previous constructive G3 state

Artifact `9004509871`, source `2783ea...`:

- cylinder periodic `Produced`;
- `r=0`, `t=(32,0)`, route 32, cut 4;
- 2,237 traces;
- 320 direct completed quads / 352 provenance vertices;
- completed output validation failed normal P95 `16.6272734366°`, field P95 `37.9670987281°`, warpage P95 `30.6213792811°`;
- no fallback/recovery.

The next artifact should not be judged by matching either historical cardinality. Correct field authority and strict validity decide acceptance.

## Required observations per direct case

Record at minimum:

- producer disposition;
- terminal stage/reason and typed phase-front failure details;
- requested/executed backend;
- phase-front attempted/succeeded;
- phase-front cells/edges/events and periodic merge evidence;
- periodic holonomy availability, rotation, translation, route/cut counts;
- trace count;
- source component/local-sheet counts;
- arrangement/direct/completion/output counts;
- output vertices/quads/non-quads;
- output component and boundary-loop evidence when available;
- strict/completed validation failures;
- normal/field/warpage P95 and source approximation metrics when exposed;
- fallback/recovery state;
- output origin;
- producer/stage/structural/output hashes;
- wall time, peak memory and exit code.

For `Rejected`, prove no generic substitution follows. `NotApplicable` remains distinct from `Rejected` and from success.

## Determinism

After first-pass direct gate decision:

- plane: 3 independent processes;
- seam: 3;
- close sheets: 3;
- cylinder: 3;
- bunny: at least one bounded observation;
- vase: at least one bounded observation, second only if tractable.

Compare producer disposition, exact failure identity or holonomy tuple, canonical route/cut identity, stage counts, validation values, structural hashes and output hash. Timeout remains failure only.

## Default suites

After focused and direct acceptance:

1. remaining producer suite excluding already executed focused tests;
2. completion/simplification suite;
3. validation suite;
4. compiled API suite.

Report direct gate status separately from aggregate totals. Scheduler-sensitive timing evidence cannot override functional gate status.

## Decision hierarchy

### G3 closure

All endpoint/field/periodic contracts pass and exact cylinder becomes direct deterministic strict-valid periodic `CompletedSurfaceCells` output with zero validation failures and G0-G2 green. Advance to G4.

### Material progress, G3 open

The six periodic regressions are restored, field-authoritative correspondence is consumed, and cylinder advances beyond cell 29 to a new later exact source-authoritative failure. Preserve the exact later failure; next Code + Build addresses only that general defect.

### No progress / regression

Cylinder remains at `InvalidPeriodicChart`, loses field correspondence, restores source-ID/lexicographic ownership, breaks cut/quotient/source-strip authority, introduces a proximity weld, or breaks G0-G2.

Because the preceding ring-correspondence Code + Build was already classified runtime-no-progress, **a second artifact-only no-progress result after this endpoint-canonicalization Code + Build triggers the mandatory next-turn design review or bounded producer replacement proof.** Do not take another ordinary isolated Code + Build turn in that case.

## Closeout

Preserve exact commands, raw stdout/stderr, checksum verification, focused/default test logs, benchmark JSON, determinism comparisons and an evidence archive with SHA-256. Update live authority documents, remove superseded plans/reports according to hygiene, verify only approved durable workflow state remains, update PR #8 while keeping it draft/unmerged, and make the required new top-level PR #8 comment the final repository write.
