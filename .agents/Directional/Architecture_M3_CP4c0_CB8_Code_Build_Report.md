# M3-CP4c-0-CB8 Code + Build Report

## Status

**COMPLETE / BUILD GREEN.** `M3-CP4c-0-CB8` implemented only frozen DEFN-2 measures L0–L9 and compiled the exact pushed semantic source. This was a Code + Build turn: **no Directional runtime test, benchmark, generated discovery, CLI, fuzzer, or custom-input execution occurred.**

## Exact authorities

- semantic source: `19ba8e9c5e58f9c33c14b309841165d3f0401db5`
- compile caller install commit: `dc36d0fff98936280da51bc02522954a1a33c204`
- compile trigger/control commit: `8abb7a37267ac20c6576160fd0984208af6914fa`
- authoritative compile run: `33025705457`
- preflight compile job: `98366398970`
- full package compile job: `98367264215`
- immutable result/package artifact: `9628445643`
- package ZIP SHA-256: `869e06a3524ecdb7fd901e2583d5ba5c60309cce3085e2e1996a37ddd780bce6`
- packaged semantic-source archive SHA-256: `98e7db71647a54f41edfd93aea56ef7f50e014989bbc3c617edc179791380d5d`
- compile diagnostic artifact: `9628446136` / `562bb275fccb61629a3a60bfd1f71c3cb8332a239674dab660ebcd1626f33d27`
- preflight result artifact: `9628386576` / `a9b66f29f9bb23927df9614066d43c7edaaeb70e5d1a01fd0551154d9a79778c`
- preflight diagnostic artifact: `9628386953` / `fb4ec9a4c041632cf7a3f5f14f0db9482b5c9c55b2c217654f42725c9872df90`

The package metadata records `source-commit=19ba8e9c5e58f9c33c14b309841165d3f0401db5`, `preflight-exit-code=0`, `build-exit-code=0`, `runtimeExecution=false`, `turnBoundary=Code+Build-only`, and empty final source-status snapshots. The package recursive `SHA256SUMS` was verified clean after download.

## Compiled targets

The preflight compiled `directional_surface_cell_producer_tests`. The full package then compiled and linked all eight standard targets:

1. `directional_surface_cell_producer_tests`
2. `directional_core`
3. `directional_pipeline`
4. `directional_surface_cell_authority_kernel_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No produced executable was launched.

## Frozen L0–L9 implementation

The implementation is bounded to `Architecture_M3_CP4c0_DEFN_2_Frozen_Definitions.md` §10:

- **L0/L1:** preserve the published-source preconditions and replace the retired cross-edge flow rejection with the exact three-way target-face classifier (`Inflow`, `Tangent`, `Outflow`).
- **L2:** implement one-hop grazing edge transit and the typed `BranchGrazingSlideDirectionAmbiguous` failure, while retaining enum value 25 without production emission.
- **L3:** distinguish `FaceInterior` from `EdgeTransit` arrival so existing vertex transit remains explicit and unchanged for face-interior arrivals.
- **L4:** add positive-face-scale invariance and endpoint-selection symmetry coverage.
- **L5:** publish the non-gating grazing-edge trace-multiplicity census without merging or tie-breaking.
- **L6:** publish exact `edgeTransitExit` support and digest material.
- **L7:** migrate only selector identities whose subject was the retired flow-rejection behavior.
- **L8:** correct the prescribed-sphere K2 walk to use the production continuation path and thread `exitPoint`.
- **L9:** preserve every prohibition: no A1 change, no new `FieldAlignedNetworkEventKind`, no A2b change, no `k >= 2` terminus ordering, no torus/mechanical work, no CP4c-1 selector change, and no tolerance/threshold/magnitude classifier.

## Selector migration and frozen gate

The CP4c-0 required-green selector is now **343 identities** with SHA-256 `63ca177e8c0f22a83085cfb1028915b444db67bf2bb3da79555e4a3033a74d09`.

Preserved prefixes:

- first 316 SHA-256 `601ce2b6a4aa2b0cda971e06e9378ebccba5fa75a9b416407447f7ed3600193c`
- first 328 SHA-256 `cf93622ea8807b26037d2fb6305adf721a23724bc519886c455e98c49c5f3600`

L7 retires exactly one obsolete required-green identity and replaces it with the behavior that now owns the same boundary:

- retired: `ResolvedBranchCorrection.CrossEdgeFlowDisagreementNamesBothPublishedAuthorities`
- replacement: `ResolvedBranchCorrection.CrossEdgeGrazingClassifiesAndTransitsWithPublishedAuthorities`

Five additional required-green identities were added:

1. `ResolvedBranchCorrection.GrazingSlideAmbiguityPublishesSiteSourcedLocus`
2. `ResolvedBranchCorrection.GrazingTransitIsInvariantToPositiveFaceScale`
3. `ResolvedBranchCorrection.GrazingTransitSelectsSameEndpointFromEitherFace`
4. `ResolvedBranchCorrection.FaceInteriorArrivalModePreservesExistingVertexTransit`
5. `ResolvedBranchCorrection.GrazingTraceSegmentsPublishExactEndpointSupport`

The non-gating K1/H1 census `ResolvedBranchCorrection.CrossFaceFlowAgreementCensusIsPublishedNonGating` was reauthored to call the new classifier rather than the retired rejection path. The new non-gating L5 census is `ResolvedBranchCorrection.GrazingEdgeTraceMultiplicityIsPublishedNonGating`. K2 remains non-gating under `ResolvedBranchCorrection.PrescribedSphereGrazingCostCensusIsPublishedNonGating`.

The old 338-file hash is **not** claimed preserved because one identity was deliberately reauthored. The accepted first-316 and prior first-328 identity prefixes are preserved exactly.

## Runtime claims deliberately not made

CB8 proves only compilation, packaging, source provenance, and frozen selector construction. It does **not** prove the 343 runtime identities, the L2/L5/K2 diagnostic predictions, the 24-trace sphere network, or any Q8 criterion. `Q8` remains unchanged and unexecuted in this turn.

Stable regression accounting remains **42 events / 14 categories / 28 recurrences**; produced-witness debt remains **5**. This successful compile creates M3 package **47**.

## Exact next

Artifact-only **`M3-CP4c-0-TB-R8`** consumes only package `9628445643` under `Architecture_M3_CP4c0_TB_R8_Artifact_Only_Test_Benchmark_Plan.md`. It may execute the frozen validation plan but may not configure, compile, relink, repair, or mutate product/test/fixture/selector/build logic.
