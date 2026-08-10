# M1h Phase-Front Field-Chart Consumer — Code + Build Report

**Status:** compile/package complete; immutable runtime pending  
**Turn type:** Code + Build only  
**Review policy:** `never`  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Result

M1h is **compile/package complete** at the bounded production authority seam:

`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

Implementation `de4e2ba7c19d2e49931655dc22d758f50656d054` adopts checked `authority::FieldChartId` at that seam while preserving the existing deterministic equal-orientation chart partition and BFS numbering. `LocalLatticeState::sourceChart` now carries explicit optional typed authority; downstream equality, hashing, quotient state, and representative ordering consume typed chart identity and convert to legacy numeric representation only at named compatibility boundaries.

The same bounded implementation corrects packaged fixture lookup so tests recognize executable-relative sibling `../test-data` before the historical `bin/test-data` lookup and compile-source fallback.

No generated Directional binary, GoogleTest discovery, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input executed in this turn. M1h remains runtime pending.

## 2. Exact source change

The exact implementation commit changes five production/test paths relative to its source parent `cc0073272239dea1686bcf79b28e4b3f3899bd04`:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`;
- `tests/TestFixturePaths.h`.

No fixture data, expected output, validator threshold, fallback/recovery behavior, optimization logic, periodic product capability, or G4 remediation was changed.

Compiled source blob authority:

| Path | Blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `102b2bbd3f57ec6b994cbe99b39c6d283eb0bf66` |
| `src/geometry/SurfaceCellTracing.cpp` | `0a8d85c20893ef65f2a2ba572096f2f38e2f652e` |
| `src/pipeline/RemeshPipeline.cpp` | `db87264809b35e325ad6c8f44fabef6ddca3883a` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `08878782d587fe9acf4579be2d356e7a62c9fde5` |
| `tests/TestFixturePaths.h` | `4a981f772ee70780d0011696010a0e1b8bef6972` |

## 3. Implementation boundary

### Typed producer chart authority

The planar phase-frame producer retains the pre-existing chart construction as a temporary compatibility vector solely while computing the unchanged BFS partition/numbering. After the chart cardinality is known, each active face crosses `LegacyAuthorityAdapters::field_chart(...)` into `FieldChartId`. Invalid/missing conversion fails closed as `MissingFaceState`.

`UniformPhaseFrame::faceChart` is now:

`std::vector<std::optional<authority::FieldChartId>>`.

`segment_on_source` requires typed chart presence and converts back to the existing integer `SurfaceTraceSegment::sourceChart` only at that compatibility output boundary.

### Typed constructive-front state

`LocalLatticeState::sourceChart` is now `std::optional<authority::FieldChartId>`. Planar state copies producer-owned typed authority directly. Periodic-annulus and bounded-disk single-chart paths obtain chart zero through the checked one-chart adapter rather than assigning a bare semantic integer.

Before locally produced front state is accepted by the aggregate producer, every lattice occurrence must carry chart authority. Missing authority fails through the existing `InvalidFinalCellState` aggregate rejection path.

### Typed downstream consumption

`RemeshPipeline.cpp` was touched only where `LocalLatticeState::sourceChart` crosses existing representation boundaries:

- lattice hashing records presence, then hashes the legacy index derived from typed authority;
- lattice equality rejects missing authority and compares `FieldChartId` values directly;
- quotient-domain compatibility tuples require typed presence and explicitly convert through `LegacyAuthorityAdapters::to_legacy_index`;
- representative ordering converts typed chart authority only at the existing tuple representation boundary.

Distinct `geometry::SourceChartId`, `SurfaceCellSourceChart`, and `SurfaceTraceSegment::sourceChart` schemas remain otherwise unchanged.

## 4. Focused contracts compiled — not executed

Exactly six `SurfaceCellPhaseFrontFieldChartAuthorityMigration` contracts are present in the compiled producer test executable:

1. `PlanarMultiFaceFrontPublishesCheckedSingleChart`;
2. `MultipleOrientationChartsPreserveEstablishedNumbering`;
3. `NumericCoincidenceCannotCrossAuthorityDomains`;
4. `MissingOrInvalidChartAuthorityCannotMasqueradeAsValid`;
5. `FaceRowPermutationPreservesTypedPlanarChartAuthority`;
6. `PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero`.

These contracts use production paths or the existing checked authority adapter. They do not derive expected chart-domain separation from the implementation under test. They are **unexecuted** until the following immutable Test + Benchmark turn.

## 5. Compile/package authority

| Evidence | Value |
|---|---|
| implementation | `de4e2ba7c19d2e49931655dc22d758f50656d054` |
| accepted M1g implementation | `ee1abbd91d8ab39b84b107bba73ebf7aa0acceb2` |
| workflow run/job | `31398571348 / 93487537918` |
| result artifact / ZIP SHA-256 | `9066967620` / `16d04835f9186b94fbb1ab987c5cd0bebd801daa7f368d01dc58139f67f5fe03` |
| log artifact / ZIP SHA-256 | `9066968049` / `d6fa10a4b188b5569dfc73008c1a6e8a6f3a4e51f64cf4232a568087b36ac816` |
| recursive manifest | **69/69**, `63c7000e00cf8608861d1651d84c02ddf419581dd7763ba25a9b3837162b92c9` |
| package | **70** regular files including `SHA256SUMS`; 7 executables; 2 static libraries; 27 fixtures |
| build | **120/120**, Release/static/Ninja/PRE_TEST |
| build wall / peak RSS | **8:22.50 / 1,850,536 KiB** |
| runtime execution | **false** |

Independent post-download inspection verified the outer artifact digests, `SHA256SUMS` digest, all **69/69** packaged content checksums, package cardinalities, build-authority metadata, and compiled source/test blob IDs without executing any packaged binary.

Executable SHA-256 authority for the next turn:

- producer `c9af71b0d32cb2af6f3ab6f466f54c9b30b8517f9413a047d9ae3b24827ca33a`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `4cab6a23edd96029cddd804c49048b90163c432dc2e832ab9c8c6a597dff17f8`;
- compiled API `e43b293b1a85b5e49343683c5a427a7981eb9d4fd32ff88e69017b883c98c037`;
- benchmark `fe9da9533c60c2f5b5881ffb7dbaa8f5a5001623e3854bb943e0cc98d63c2c83`.

## 6. Regression disposition

M1h touches the planned `RP-01` and `RP-05` authority boundary and adds six `RP-02 / TA-05` semantic contracts. Compile/package success does not accept these runtime claims. M1g `RP-07` periodic transport code is unchanged except for compile compatibility with typed lattice state.

No stable regression event or recurrence is assigned from compile-only evidence. Historical totals remain **34 regression events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unchanged.

## 7. Temporary workflow hygiene

The bounded source/build workflow, trigger marker, and source-edit payload were removed after result/log artifacts and exact source authority were independently verified. The durable workflow state returns to `.github/workflows/agent-source-snapshot.yml` only.

## 8. Next turn

Run **M1h Phase-Front Field-Chart Consumer — immutable Artifact-Only Test + Benchmark** under:

`.agents/Directional/Architecture_M1h_Phase_Front_Field_Chart_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume only exact artifacts `9066967620 / 9066968049`. Do not rebuild, relink, regenerate, repair, patch, or substitute packaged content. Runtime acceptance must prove the six M1h contracts, complete entering M1g/M1f/M1e/M1d/M1c/M1b/M1a/T1 authority, representative direct products, known-red classifications, and exact postflight. The packaged sibling `../test-data` lookup must work from arbitrary extraction/runtime directories **without creating the M1g runtime fixture symlink**.
