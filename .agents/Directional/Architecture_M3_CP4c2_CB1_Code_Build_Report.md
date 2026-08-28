# M3-CP4c-2 CB1 Code + Build Report

## Verdict

`M3-CP4c-2-CB1` is **COMPLETE / BUILD GREEN / RUNTIME-FREE**.

The turn implemented the frozen A2a′ `SurfaceCutGraph` authority from
`Architecture_M3_CP4c2_DEFN_Frozen_Definitions.md`, made A2b consume that certified product, applied Amendment 12
to the architecture document, added the required X1/X2/X5/X6/X7 observations and regression coverage, and froze
both conditional successor selectors. The exact final semantic/test source is
`93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`.

No Directional test, benchmark, `ctest`, produced executable, discovery/help/version command, CLI, fuzzer, or
custom runtime input was executed. Runtime acceptance remains entirely for Test + Benchmark.

## Implementation

The bounded change adds one new single-writer authority between A2a and A2b:

- `SurfaceCutGraph` is produced from immutable source topology, field-transport authority, and the immutable
  `FieldAlignedCurveNetwork`; it does not consume a `GlobalTopologyPlan`.
- Cuts are existing `SourceEdgeTopologyKey` edges only. The product carries provenance/cellularity evidence and
  mandatory-preservation state and fails closed rather than publishing an uncertified partial product.
- The complementary-face traversal is shared through `SourceFaceComponentPartition.h` rather than copied into a
  second implementation.
- `GlobalTopologyPlan` now consumes the certified cut graph and incorporates cut arcs during region derivation.
  No post-region non-disc repair, collapse, re-cut, geometry insertion, subdivision, or positional mutation was
  added.
- `RemeshPipeline` publishes the new A2a′ product between `FieldAlignedCurveNetwork` and `GlobalTopologyPlan`.
- `DESIGN.md` now carries Amendment 12's conditional cellular-embedding statement and A2a′ pipeline stage.
- CP4c-2 tests include:
  - X1 torus `V=48`, `E=48`, source `χ=0` publication;
  - an independent pre-cut complement measurement for prediction 2 (`χ==0`, two boundary cycles for each
    non-disc torus component);
  - X5 input-order determinism;
  - X6 already-cellular idempotence;
  - X7 torus region/C6 examined-region non-vacuity publication;
  - the X2 prescribed-sphere report-only diagnostic that decides whether C3 joins the gate.

The implementation started from the exact source snapshot used by this turn and remained surgical to A2a′/A2b,
pipeline plumbing, design authority, selectors, and checkpoint-local tests.

## Frozen selector authority

The accepted predecessor selector and all frozen prefixes remain unchanged:

- accepted 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`;
- first 316: `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`;
- first 346: `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`;
- first 353: `51ff96d72e1c2c88e9407e99737e42ec9093ea238aaf8b1e45ff2559f71ac6a5`.

CB1 intentionally freezes **both** outcomes allowed by X2 rather than inventing a runtime conclusion during a
Code + Build turn:

- candidate 357: **357 lines**, SHA-256
  `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
  = accepted 355 + C1 + C6;
- candidate 358: **358 lines**, SHA-256
  `6eda3aad83de81fc55d5cd446f80704d604a842f10995789b483291bb64fbe62`
  = accepted 355 + C1 + C3 + C6;
- X2 non-gating diagnostic selector: **1 line**, SHA-256
  `88af227b7c7ca78d2a6247624b3a5f860026cf50fd3c2bd6a215756b086dafc8`.

The final 357-versus-358 gate is **not claimed by CB1**. The immutable TB X2 diagnostic decides it exactly as
frozen by the DEFN turn.

## Compile corrections

Two compile-only defects were exposed and corrected without runtime:

1. Compile run `33194850786` found one stale A2b call to `build_node_loci(network)` after the new cut-node
   bindings became required. The smallest correction threads the existing `CutNodeBindings` argument through
   that validation path.
2. Compile run `33196358853`, changed-owner job `98934449434`, found that the independent complement test helper
   treated `DomainResult<SourceEdgeTopologyKey>` like an optional and attempted to default-construct
   `SourceEdgeTopologyKey` in a fixed array. The test-only correction uses `.value()` and a populated vector.

Neither failure is runtime or product-regression evidence; both occurred before a successful compile/package and
were corrected inside the Code + Build boundary.

## Authoritative compile evidence

Final compile workflow: `33196876096`.

### Changed-owner precompile

- job: `98936191472` — **PASS**
- target: `directional_surface_cell_producer_tests`
- source: `93d9d49f052fa481bd3a8ad8c9bf31eccda7705c`
- result artifact: `9696170230`, digest
  `sha256:349d2c68a683e34c95631f43d397ad8ba8a35c3084fdebae7f39392918a0c28f`
- log artifact: `9696170581`, digest
  `sha256:821850b89eaaf6d95410dadbf15c32884abd8d9519e5a2d40826f63a1edc7145`

### Immutable full GMP package

- job: `98936799976` — **PASS**
- package artifact: `9696201700`
- package digest:
  `sha256:af3ebe2efaab66fed70de8d954cb5615abd9428f401ea974dffe1e14577c8097`
- persistent log artifact: `9696202046`, digest
  `sha256:96fc85af885ece730c8526cf0a03480133d297a1a14b67d76f5814fbe83786d3`
- packaged source archive:
  `source-93d9d49f052fa481bd3a8ad8c9bf31eccda7705c.tar.gz`,
  SHA-256 `8694f0fb85d101e3c5862e5a6a8a8a3ed241c723fd229eb44f83844b30321687`
- build/preflight exit codes: `0 / 0`
- exact arithmetic backend: **GMP**
- CMake evidence links both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and
  `/usr/lib/x86_64-linux-gnu/libgmp.so`
- all source-status snapshots are empty
- package manifest: **all entries verified**
- `runtimeExecution=false`
- `turnBoundary=Code+Build-only`

The eight packaged targets are exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

All six packaged executables have executable mode `0755`; the two static libraries are `0644`. The changed-owner
precompile is compile evidence only. The immutable eight-target package advances M3 package accounting from
**57 to 58**.

## Accounting and boundary

No runtime regression was observed in this turn, so stable regression accounting remains
**42 events / 14 categories / 28 recurrences** and produced-witness debt remains **5**.

`M3-CP4c-2` is **not accepted yet**. CB1 establishes compiled package authority only.

Exact successor is **`M3-CP4c-2-TB-X2-EXEC`**, the first artifact-only Test + Benchmark execution subturn. It
must consume package `9696201700` without rebuild or mutation and execute only the frozen one-identity X2
diagnostic. Its review then selects candidate 357 or 358 before the required gate is executed.

The full canonical-TB execution/review sequence is frozen in
`Architecture_M3_CP4c2_TB_Artifact_Only_Test_Benchmark_Plan.md`.
