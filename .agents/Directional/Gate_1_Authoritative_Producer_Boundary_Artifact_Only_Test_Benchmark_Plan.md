# Gate 1 Authoritative Producer Boundary — Artifact-Only Test + Benchmark Plan

## Turn boundary

This is an **artifact-only Test + Benchmark** turn.

Use exactly:

- artifact: `directional-g1-authoritative-producer-boundary-build-artifact.zip`;
- SHA-256: `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031`;
- source commit: `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- payload cleanup: `bcf934d34e9a15f5d0929628ffd26f6833643214`;
- expected internal checksum entries: **44/44**.

Do not configure, compile, relink, regenerate discovery, or edit source/tests/fixtures/manifests/validators/build logic. Runtime-only symlinks needed to expose packaged fixture paths are permitted only if they do not modify packaged bytes.

Timeout is failure, never correctness evidence.

## Pre-execution integrity

Before running any project binary:

1. verify the outer SHA-256 exactly;
2. extract to a fresh directory;
3. verify all 44 internal checksums;
4. verify five executables, two project libraries, and 27 fixture/input files;
5. verify source commit/cleanup metadata;
6. verify changed Git blobs:
   - `SurfaceCellTracing.h` `b33c2118e65812d4b0a4a65fe9f46b7a8766bb59`;
   - `SurfaceCellTracing.cpp` `c9877d8ffa8aa5fbb59c83a1ab4b94eed5421431`;
   - `RemeshDiagnostics.h` `8ddb4bcdf26a1caacdf927e74e56d3fe11b3e3b7`;
   - `RemeshPipeline.cpp` `533648a1b1fd008286f3ef3292813817ad1f1146`;
   - `DirectionalBenchmark.cpp` `73d9d29e49107073a44c2e9a6fe0e89331412737`;
   - `SurfaceCellsPhase10Tests.cpp` `b726b85d189c5018d53c8561888dcda0ab55fa58`;
7. verify bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05` and topology 502 vertices / 1,000 triangles / closed / one component;
8. verify vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868` and topology 1,274 vertices / 2,404 triangles / one boundary loop / 142 boundary edges.

If integrity fails, stop and report artifact invalidity; do not repair packaged inputs.

## Explicit producer-contract tests first

Run these directly from the packaged producer-test executable before the six-fixture acceptance matrix:

1. `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`
2. `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`
3. `SurfaceCellsPhase10.UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason`
4. `SurfaceCellsPhase10.UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded`
5. `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`
6. the mandatory bunny/vase production-fixture topology guard from the design-acceptance suite.

Record each exact test result. Do not weaken or replace a failing test.

The exact committed-plane producer test is especially important: it must exercise the real `plane.obj` + `plane.rawfield` preprocessing path and expose the producer disposition before generic downstream behavior can obscure it.

## Mandatory direct acceptance matrix

Run all six in order, each in a fresh bounded process, even if an earlier case fails:

1. plane
2. multi-face seam
3. close sheets
4. cylinder
5. randomized bunny
6. vase

Later fixtures cannot pass an earlier design gate.

Every direct success still requires:

- requested/executed backend `SurfaceCells`;
- fallback policy `Fail`;
- no fallback attempt;
- source-grid recovery disabled/unused;
- non-empty pure-quad output;
- output origin `CompletedSurfaceCells`;
- complete source provenance;
- strict source-authoritative validation;
- deterministic structural output.

## Required observations per direct case

Record at minimum:

- `surfaceCellAuthoritativeProducerDisposition`;
- terminal stage and reason;
- requested/executed backend;
- phase-front attempted/succeeded and typed failure reason/context if present;
- trace segment count;
- accepted authoritative phase-front cell count;
- chart/transition/route provenance counts when available;
- arrangement, simplified, direct, completion, and output cell counts;
- output vertices, quads, and non-quads;
- strict validation failure count and first invalid reason;
- fallback attempt/use;
- recovery attempt/use;
- output origin;
- stage hashes, tracing/producer structural hash, and output hash;
- wall time and exit code.

For an explicit `Rejected` result, verify that generic seeds/traces/proposals are absent and that arrangement/completion do not become substitute producer authority.

## Gate 1 acceptance hierarchy

### 1. Gate 1 closure

Required:

- plane disposition `Produced`;
- direct deterministic `CompletedSurfaceCells` output;
- non-empty pure quads, expected previously proven topology of 64 quads unless the exact production target demonstrably and legitimately changes the count;
- zero strict validation failures;
- no fallback/recovery;
- complete source provenance;
- seam remains direct deterministic `Produced` success with its proven 64-quads unless a legitimately changed production target is explicitly evidenced.

If this closes G1, next active work returns to G2 close-sheet isolation.

### 2. Minimum architecture proof, G1 still red

If the plane remains invalid, material architectural progress requires all of:

- disposition `Rejected`;
- immutable typed first-invalid authority at `tracing/phase-front` or equivalent producer boundary;
- terminal failure at tracing before FlowRep/arrangement/completion substitution;
- zero generic trace segments generated because of rejection;
- zero arrangement/completion cells caused by a substitute generic producer;
- old 106 traces / 9 arrangement / 12 completion signature disappears;
- seam remains a direct valid mandatory regression.

This proves the replacement boundary but does **not** pass G1. The next Code + Build plan must address the exact retained typed rejection without restoring generic substitution.

### 3. No material progress

Any of these is no progress:

- plane is `NotApplicable` and silently reaches the old generic 106/9/12 path;
- plane is `Rejected` but generic seeds/traces/proposals still run;
- typed producer rejection is overwritten by completion/output validation;
- seam regresses;
- fixture/test/validator acceptance is weakened.

If this occurs, perform another mandatory architecture Review before any additional local repair.

## Determinism runs

After first-pass direct acceptance:

- plane: 3 independent bounded processes;
- seam: 3;
- close sheets: 3;
- cylinder: 3;
- bunny: at least 2;
- vase: at least 2;
- use a third bunny/vase run only if resource budget is reasonable.

Compare dispositions, terminal stages, typed rejection identity, structural hashes, cell counts, output hashes, and provenance-sensitive diagnostics. A timeout is a failed run.

## Default suites

After explicit contract tests and direct cases:

1. run the remaining producer suite, excluding tests already executed explicitly so totals do not overlap;
2. run completion suite;
3. run validation suite;
4. run compiled API suite.

Report direct acceptance separately from aggregate totals. Scheduler-sensitive performance/timing tests are closeout evidence, not correctness authority.

## Required evidence archive

Preserve:

- artifact digest verification;
- recursive checksum verification;
- fixture-integrity evidence;
- exact commands;
- raw stdout/stderr for every explicit test/direct case/determinism/default suite;
- benchmark JSON outputs;
- machine-readable summary;
- evidence archive SHA-256 and recursive checksums.

## Prohibitions

- no rebuild or relink;
- no source/test/fixture/manifest/validator edits;
- no validator weakening;
- no fixture/ID special cases;
- no fallback/recovery substitution;
- no generic producer substitution after authoritative rejection;
- no arbitrary subset or positional topology repair;
- no synthetic counters/Euler correction;
- no post-hoc cell merging;
- no timeout-as-correctness.
