# M3-CP4c-3-CB1 — Phase-1 Instrumentation Code + Build Report

Date: 2026-08-30 UTC
Turn type: **Code + Build only**
Status: **COMPLETE / BUILD GREEN / RUNTIME-FREE / PHASE-1 INSTRUMENTATION ONLY**

## 1. Scope and authority

This turn implements only `M3-CP4c-3-DEFN` measures **AK0–AK3**. It adds provenance and diagnostic publication for the two currently collapsed failures; it does **not** design or implement a product correction, execute the 367 gate, run a Directional test/benchmark binary, change selector bytes, reopen Amendments 12/13/14, or select a phase-2 branch.

Accepted predecessor authority remains CP4c-2 at **365/365 PASS**, source `57444781af7bdc460e38cc68930a9a8c8199eeea`, package 67 artifact `9736088354`. CP4c-3 selector 367 remains byte-for-byte frozen at SHA-256 `ef9d082f56f5c8de83124cf2e6257d098408cc597d9147b967cf9c84da4916bf`; the frozen prefixes remain:

- 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
- 361: `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`
- 365: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`

The selector remains **367 lines / 367 unique identities**. `selected_r2_branch=NONE`, `selected_gate=NONE`, and `gate_execution_authorized=false`.

## 2. Implemented instrumentation

### AK1 — exact A1 `IncompleteCycleBasis` reason

`FieldAtlasBuildError` now carries optional `IncompleteCycleBasisReason` provenance. The search-produced producer enumeration is eight sites with eight explicit reasons:

1. `LocalTangentBundleInitializationFailed`
2. `CycleDimensionCountMismatch`
3. `CycleCoefficientInvalid`
4. `CycleTransportAdjacencyMissing`
5. `CycleEdgeIncidentFaceMissing`
6. `CycleOrderingFailed`
7. `CycleKindPartitionMismatch`
8. `BoundaryCycleCountMismatch`

All eight still map to the existing `FieldAtlasBuildErrorCode::IncompleteCycleBasis`; no existing error value was renumbered and no new `FieldAtlasBuildErrorCode` was introduced.

Search also found four existing diagnostic consumers of `field_atlas_build_error_code_name(...)`, excluding the name function itself, and each now publishes the optional reason:

- `src/pipeline/RemeshPipeline.cpp`
- `tests/FieldTransportAtlasTests.cpp`
- two diagnostic surfaces in `tests/FieldAlignedCurveNetworkTests.cpp`

### AK2 — per-region local cycle-basis shape

`FieldAtlasBuildError` now carries `regionCycleBasisDiagnostics`, generated for **every region** in the supplied `SourceTopologyRegions` authority whenever one of the eight `IncompleteCycleBasis` sites fires. Each row carries:

- `TopologyRegionId`
- local-mesh availability and tangent-bundle initialization state
- `V / E / F`
- computed Euler characteristic
- boundary-loop count
- genus when derivable
- interior-local-vertex count
- expected cycle count
- actual `bundle.cycles.rows()` count
- actual `cycleCurvatures.size()` count
- actual `innerAdjacencies.size()` count

Search-produced consumers are the pipeline diagnostic publisher and the CP4c diagnostic surface in `tests/FieldAlignedCurveNetworkTests.cpp`. No runtime values are claimed by this CB; those values are the successor TB's evidence.

### AK3 — nine-way `RotationSystemInconsistent` provenance

`GlobalTopologyPlanError` now carries optional `RotationSystemInconsistencyReason`, and `SurfaceCutGraphError` transports the originating reason. Search found and instrumented the nine source-face/locus-producing failure sites in `EmbeddedGraphTopology.cpp`:

1. `TraceEventPositionInvalid`
2. `TraceEventPositionNodeConflict`
3. `EventNodeLocusMissing`
4. `EventLocusMissingSourceEdge`
5. `EventLocusSourceEdgeConflict`
6. `VertexTraceFaceMissingFromFan`
7. `VertexTracePortOrdinalInvalid`
8. `EdgeTraceFaceSideInvalid`
9. `EdgeTraceSecondaryRankInvalid`

The reason is published through the existing frozen sphere/non-gating diagnostic paths. No sphere product correction is present in this turn.

## 3. Source and compile correction

The instrumentation first landed as semantic commit `014c7f7f8d6984518cf5c81156a10d3e06298349` (10 files, **321 insertions / 23 deletions**).

The first compile-only attempt, run `33338011871`, correctly failed before package acceptance because `FieldAtlasRegionCycleBasisDiagnostics` was default-constructed even though its `TopologyRegionId` member is non-default-constructible. The only corrective source change was:

```cpp
FieldAtlasRegionCycleBasisDiagnostics row{region.id()};
```

replacing the default construction followed by assignment. The corrected semantic source is:

`48dd011c4aa689a245b74527ed9df0900ada9bf3`

This is a compile correction to the new diagnostics object only; it changes no intended product behavior and does not weaken any diagnostic or gate.

## 4. Authoritative compile/package evidence

Authoritative compile-only run/job: **`33338642383 / 99330058374`**.

- exact semantic source: `48dd011c4aa689a245b74527ed9df0900ada9bf3`
- immutable package number: **68**
- result artifact: **`9739919234`** (`m3-cp4c3-cb1-result-33338642383`)
- package artifact SHA-256: `127c7b086a8849de7f0c14928f2c5d762c3bf71711821d0a1fabfefda889d11c`
- packaged source archive SHA-256: `f1fce7f720718c8ac974d0d5f77ca1fee4244b10c710d2b505a1af162e4f937f`
- compile log artifact: **`9739919468`**
- compile log artifact SHA-256: `2074a5d2035dd84fe62ad424a8d95dfebe7af219f520f9f07e062af57ade21cd`
- packaged internal manifest: **28/28 verified**
- preflight compile exit: `0`
- full compile exit: `0`
- source status before configure, after configure, after build, and final: clean
- `DIRECTIONAL_ENABLE_GMP=ON`
- authoritative link evidence contains both `libgmpxx.so` and `libgmp.so`
- `exactArithmeticBackend=GMP`
- `runtimeExecution=false`
- `turnBoundary=Code+Build-only`

Compiled/linked targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No compiled binary was executed. No test, benchmark, selector identity, fixture, or accepted semantic contract was exercised as runtime evidence.

## 5. Bookkeeping and disposition

- CP4c-2 remains **CLOSED / ACCEPTED at 365/365**.
- CP4c-3 remains **OPEN**; selector 367 is frozen and unselected.
- Stable regression accounting remains **44 events / 14 categories / 30 recurrences**.
- Produced-witness debt remains **5**.
- Authoritative M3 package count advances **67 → 68** because this compile produced a new immutable package.
- `M3-CP4c2-TB-X2-CAND-04`, `M3-CP4c2-TB-X2-R10-CAND-01`, `M3-CP4c2-TB-X2-R8-CAND-02`, and `M3-CP4c3-DEFN-CAND-01` remain open/owned exactly as defined; CB1 does not adjudicate them.

## 6. Exact successor

The exact next turn is the **artifact-only CP4c-3 phase-1 Test + Benchmark execution on package 68**. It must consume artifact `9739919234` directly, execute the frozen **367** selector from ordinal 1, run the frozen non-gating diagnostic selector in full or justify any per-identity skip under AF6, and publish the measured **AK1–AK3** evidence. It must not rebuild or repair the immutable package.

That TB's independent review then orders phase 2 from the measured causes. No `AK4–AK7` product correction is authorized before that evidence/review boundary.
