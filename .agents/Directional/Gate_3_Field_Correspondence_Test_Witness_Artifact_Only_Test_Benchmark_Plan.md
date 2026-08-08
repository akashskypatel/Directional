# Gate 3 Field-Correspondence Test Witness — Artifact-Only Test + Benchmark Plan

## Turn boundary

This is an **artifact-only Test + Benchmark** turn.

Use exactly:

- artifact ID `9013161456`;
- artifact name `g3-field-correspondence-test-witness-code-build`;
- artifact SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- source/test evidence commit `117620ec2da2083ce11b205835e58fa404f163ef`;
- runtime-proven production source commit `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`;
- test-only patch SHA-256 `f5699ea435ec650384ed2d3791ec032e2cddbf09ae9d9fd4e0f86928d5e078fb`;
- workflow run/job `31228899303 / 93028533210`;
- log artifact `9013161584`;
- log artifact SHA-256 `baef2956f2c455a963f96ffe935c1d6173ba0854c847a690919e21c61423630f`;
- recursive checksum entries **44/44**.

Expected blobs:

- `tests/SurfaceCellsPhase10Tests.cpp` `80a0b58339102279ab863d9112e243a557cd270d`;
- `src/geometry/SurfaceCellTracing.cpp` unchanged `63e5ee427f675077f710db51ffb56d91838d3519`;
- `include/directional/geometry/SurfaceCellTracing.h` unchanged `c1b816a584d67a3f74c2d7389962bd92d52244c9`.

Do not configure, compile, relink, regenerate discovery, or edit source/tests/fixtures/manifests/validators/benchmarks/build logic. A runtime-only symlink may expose immutable packaged fixture paths and must be recorded.

## Pre-execution integrity gate

Before any packaged project binary executes:

1. download artifact `9013161456` fresh;
2. verify outer SHA-256 exactly;
3. extract into a fresh arbitrary directory;
4. verify all **44/44** recursive checksums;
5. verify five executables, two project libraries and 27 fixture/input files;
6. verify source commit, patch SHA and all declared blobs;
7. verify `productionSourceChanged=false` and runtime-proven production source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc` in source authority;
8. verify Release / Ninja / seven approved targets and `runtimeExecution=false` metadata;
9. verify build log reaches `111/111`, `payload_exit=0`, and exact final evidence head `117620ec2da2083ce11b205835e58fa404f163ef`;
10. verify immutable cylinder fixture hashes against the preceding runtime authority if available in the packaged fixture manifest/checksums.

If integrity fails, classify infrastructure invalid and stop. Do not create a replacement build in this turn.

## Focused/retained contracts first — target 17/17

Run the same 17 focused/retained contracts used in the preceding G3 artifact validation.

### Corrected field-authority witness

Run first:

- `SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`.

Required result:

- **pass**;
- producer reaches `Produced` as before;
- corrected witness observes a nonzero count of `family == 1` source-attached boundary-path segments;
- observed segment endpoints remain finite, normalized barycentrics inside the source simplex;
- reconstructed nonzero source-space V segments align with the local authoritative V cross-field family;
- result is independent of the 0.25 target subdividing a 0.5 source inter-ring connection;
- no fixture count/source-ID/order/frequency assertion substitutes for field semantics.

Do not reinterpret a zero witness count as success. The corrected test intentionally preserves a nonempty semantic observation requirement.

### Retained endpoint and ambiguity contracts

Then run:

- `SurfaceCellsPhase10.PeriodicPhaseFrontCanonicalizesSourceSimplexEndpoints`;
- `SurfaceCellsPhase10.PeriodicChartEndpointCanonicalizationKeepsGenuineOverlapRejected`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed`.

All must remain green. Genuine overlap must remain rejected by the unchanged strict validator.

### Retained G3 periodic contracts

Run the six established periodic contracts:

- `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
- `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`.

### Retained G1/G2 contracts

Run the seven established passed-gate contracts:

- exact committed plane authoritative producer boundary;
- disconnected close-sheet partition;
- close-sheet face-row invariance;
- ordered authoritative source-vertex-fan traversal;
- source-vertex-fan row-order invariance;
- duplicate transition metadata fail-closed behavior;
- relief guidance becomes a hard stop only when embedded.

Formal G3 closure requires **17/17** focused/retained contracts.

## Direct acceptance order

After focused contracts, run direct mandatory fixtures in fresh bounded processes with requested backend `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled:

1. plane;
2. multi-face seam;
3. close sheets;
4. exact cylinder.

Bunny/vase may be later-gate observations only after the G3 decision if turn budget permits. They cannot determine G3 closure.

## Exact cylinder formal G3 closure contract

The corrected test-only artifact must retain the runtime result already established by artifact `9010838200`:

- producer disposition `Produced`;
- direct output origin `CompletedSurfaceCells`;
- nonempty pure-quad output, zero non-quads;
- field-authoritative adjacent-ring correspondence consumed;
- periodic holonomy available and valid;
- quarter-turn rotation zero for the singularity-free cylinder;
- positive integral periodic translation in the supported direction with zero unsupported transverse component;
- ordered canonical route and source cut nonempty/reciprocal/source-authoritative;
- source-strip breakpoint authority retained;
- artificial cut paired through exact periodic ownership and not exterior;
- exactly the two genuine annulus boundary loops exterior;
- one accepted cell -> one output quad;
- complete source provenance;
- completed/strict validation failures zero;
- `fieldP95Degrees <= 15.0`;
- `normalP95Degrees <= 15.0`;
- `warpageP95Degrees <= 30.0`;
- no fallback attempt/use;
- source-grid recovery disabled/unused;
- deterministic producer state, holonomy, route/cut identity, stage hashes and output hash across independent processes;
- plane, seam and close sheets retain their proven direct strict-valid outputs.

Historical cardinalities are evidence rather than fixed assertions. However, record comparison to the preceding accepted cylinder state: `r=0`, `t=(32,0)`, route 32, cut 4, 288 quads, 320 vertices, zero validation failures, field P95 approximately `8.54e-7°`, output hash `32135be51d7a0a26`.

Any changed cardinality must be explained by actual runtime semantics; test-only source is expected not to alter production output.

## Determinism

If first-pass direct acceptance is green:

- plane: three independent processes;
- seam: three;
- close sheets: three;
- cylinder: three.

Compare producer disposition, holonomy tuple, canonical route/cut identity, stage counts, validation values, structural hashes and output hash.

## Default suites

After direct G3 decision, execute:

1. remaining producer suite excluding already executed focused tests;
2. completion/simplification suite;
3. validation suite;
4. compiled API suite.

Report direct G3 status separately from aggregate totals. The known scheduler/environment-sensitive validator-overhead test remains performance evidence and cannot override semantic closure.

Do not repair the ten historical completion/simplification failures in this turn.

## Decision hierarchy

### Formal G3 closure

If:

- focused/retained contracts are **17/17**;
- exact cylinder retains direct deterministic strict-valid periodic `CompletedSurfaceCells` output with zero validation failures;
- plane/seam/close sheets stay green;
- no fallback/recovery is used;

then mark **G3 passed** and activate **G4 topology-distinct completion and singularities**. Produce the next G4 Code + Build plan from `.agents/Directional/DESIGN.md` and current remediation/reorientation authority.

### Unexpected production regression

If the corrected test passes but direct cylinder or a passed G0-G2 fixture regresses, G3 remains active at the earliest exact production regression. Do not call G3 closed from focused test success alone.

### Corrected witness still invalid/failing

If the corrected field witness still fails, classify independently whether the fixture/precondition, expectation, or production behavior is responsible. Do not weaken the semantic field-alignment assertion, remove the nonempty observation requirement, or modify source during this turn.

## Closeout

Preserve exact commands, stdout/stderr, checksums, focused/default logs, benchmark JSON, determinism comparisons and an evidence archive with SHA-256. Update TODO, milestone/design/remediation/reorientation/runtime summary and live handoff. Remove superseded plans/reports only after replacements exist. Verify only approved durable workflow state remains. Keep PR #8 open/draft/unmerged and make a new top-level PR #8 comment the final repository write.
