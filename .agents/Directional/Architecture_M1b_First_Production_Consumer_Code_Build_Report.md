# M1b First Production Consumer — Code + Build Report

**Status:** completed for compile/package authority; immutable runtime pending  
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — first production consumer migration  
**Production behavior delta:** none intended; runtime not executed in this turn  
**Review policy:** `never`  
**Date:** 2026-08-09 UTC

## 1. Result

M1b completed the first bounded production-consumer migration from legacy integer source-face/source-vertex identity into the accepted M1a authority kernel. The selected boundary is:

`RemeshPipeline -> fill_surface_optimization_rail_constraints -> surface_optimization_rail_detail::provenance_supports_interval_sheet`.

Only this source-face/source-vertex identity seam was migrated. No chart, transition, rail, producer, tracing, arrangement, completion, quotient, validator policy, fixture, benchmark acceptance, fallback/recovery, G4-R007, Bunny, or Vase behavior was intentionally changed.

The authoritative build is compile/package evidence only. The following immutable Test + Benchmark must prove the migrated truth table and preserve M1a/T1/direct product authority before any second production consumer may migrate.

## 2. Authoritative compile/package evidence

| Evidence | Value |
|---|---|
| Entering branch head / migration base | `9a4131f9655567ffc60c2c513db1c73826165bb2` |
| First source-migration commit | `f768c2f434e2f340f4d7be3192d48abff645a78e` |
| Authoritative corrected implementation | `0340addf21473854856266ff00cb68915ce24ef0` |
| Build/event commit | `17c61b8d2eb835bd734010e160e6cd6b7dc9f5cf` |
| Workflow run/job | `31330737703 / 93288453677` |
| Result artifact | `9042940168` |
| Result artifact SHA-256 | `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b` |
| Log artifact | `9042940336` |
| Log artifact SHA-256 | `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614` |
| Recursive package manifest | **53/53**, SHA-256 `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1` |
| Package regular files | **54**, including `SHA256SUMS` |
| Compile closure | Release/static/Ninja **120/120** |
| Build wall / peak RSS | **8:07.42 / 1,836,308 KiB** |
| GoogleTest discovery mode | `PRE_TEST` |
| Runtime execution | **false** |
| Retention | through **2026-08-23 UTC** |

Local artifact preflight confirmed:

- both outer ZIP digests exactly match GitHub artifact digests;
- both ZIPs contain no absolute or escaping archive path;
- all **53/53** packaged checksums verify;
- seven ELF executables, two static libraries, and all 27 fixtures are present;
- no packaged regular file was modified during inspection.

## 3. Exact implementation boundary

Ignoring temporary connector execution files that were removed after artifact capture, the source/test/build diff from `9a4131f...` to `0340addf...` is exactly five paths:

1. `CMakeLists.txt`;
2. `cmake/DirectionalTests.cmake`;
3. `include/directional/geometry/SurfaceOptimizationRailConstraints.h`;
4. `src/geometry/SurfaceOptimizationRailConstraints.cpp`;
5. `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

### Build ownership

`src/authority/AuthorityKernel.cpp` is now compiled once into `directional_core`. The authority-kernel test target no longer compiles the same translation unit directly. This establishes the production linkage needed for later incremental consumers without duplicate ownership.

### Typed consumer seam

`source_face_contains_vertex` now accepts:

- `authority::SourceFaceId`;
- `authority::SourceVertexId`.

`provenance_supports_interval_sheet` preserves the existing legacy sentinel/range checks first, then converts validated source-face values through `LegacyAuthorityAdapters::source_face`. Source vertices extracted from the already-validated source-face topology are rejected when negative, converted through `LegacyAuthorityAdapters::source_vertex`, retained as `SourceVertexId`, and converted back only where legacy Eigen/vector indexing is required.

M1b deliberately preserves the pre-M1b source-vertex truth table: the old seam rejected negative topology vertex IDs but did not independently impose `sourceVertices.rows()` as a new bound. The compatibility adapter therefore receives the complete nonnegative legacy-`int` extent for this slice. Tight source-support rebinding remains M5/AR-09 work; M1b does not silently add a new product rejection policy.

### Preserved mechanics

The following remain byte-level/source-level unchanged in meaning inside the migrated seam:

- component mismatch behavior;
- unknown/same-sheet fast acceptance;
- source-face extent and triangle-arity checks;
- finite barycentric requirement;
- exact existing `barycentric(corner) > 1.0e-8` support-classification threshold;
- interior-support rejection;
- exact source-face vertex-incidence requirement;
- optional component/sheet authority-vector checks;
- rail projection, tolerance, feature assignment, ordering, fixed-vertex policy, and optimizer policy outside the seam.

## 4. Focused test authority compiled

Six new runtime contracts are compiled into the existing default-built validation target:

1. `SurfaceOptimizationRailAuthorityMigration.SameSheetRailAssignmentRemainsAccepted`;
2. `SurfaceOptimizationRailAuthorityMigration.CrossSheetExactVertexAndEdgeIncidenceRemainAccepted`;
3. `SurfaceOptimizationRailAuthorityMigration.CrossSheetInteriorProvenanceRemainsRejected`;
4. `SurfaceOptimizationRailAuthorityMigration.InvalidLegacySourceFacesRemainRejected`;
5. `SurfaceOptimizationRailAuthorityMigration.WrongSourceFaceWithoutTypedSupportRemainsRejected`;
6. `SurfaceOptimizationRailAuthorityMigration.SourceFaceComponentAndSheetAuthorityMismatchRemainRejected`.

Static test-name manifest SHA-256:
`a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320`.

The same source also contains compile-time assertions proving the detail helper has the exact `(SourceFaceId, SourceVertexId)` signature and cannot be invoked with those semantic domains swapped.

The complete validation executable now statically contains **77** tests: the accepted T1 validation baseline of 71 plus these six new focused contracts. Runtime discovery/execution belongs to the following turn.

## 5. Preserved M1a/T1 static authority

The immutable package retains:

- M1a authority-kernel static manifest: **14** names, SHA-256 `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`;
- T1 independent-oracle static manifest: **29** names, SHA-256 `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

No M1a authority test or T1 oracle source changed.

Exact unchanged source blobs include:

- `src/authority/AuthorityKernel.cpp`: `19abad161d865262413d00c310ca1def166b6494`;
- `tests/SurfaceCellAuthorityKernelTests.cpp`: `9dcdab568e204026eb0c2aebc1b43cd8de8db62c`;
- `tests/SurfaceCellProductOracleTests.cpp`: `28932c8c2dbe844b62f8fe848e6ebb9ef67550de`;
- `tests/SurfaceCellDesignAcceptanceTests.cpp`: `aff7894aae3397bef47be777a8bf7e2fbb0c27ef`.

## 6. Exact M1b source/package hashes

| Member | SHA-256 / Git blob |
|---|---|
| `CMakeLists.txt` blob | `9d7c8b5c3cc0b6a5098764fd44b463861c34249f` |
| `cmake/DirectionalTests.cmake` blob | `b24513327026f40186571cd290d9420302b7e9d4` |
| rail header blob | `b636a356b3b036b84aecb8e923392adba98e5b9b` |
| rail implementation blob | `9ffdde50252319386a1d140b8aba0a1bfb162440` |
| rail validation tests blob | `466e2bbd000413ee60c77cc06fe707641dbe4740` |
| packaged M1b patch | `8ff8a4fdbe0c4615f80ba8c91d61b9d8a29152a90239e0179523a5d13b743961` |
| source archive | `c90c871fee44ea43ac8370711eb6ad84a80025cfbf5ac14aef88eafca16867ec` |
| compile database | `aa91af44338f8776d982b43ae9ef0a8ba65a58ec879c8a7266d8bf0c1bd11ce9` |

Packaged binary/library hashes:

| Member | SHA-256 |
|---|---|
| `libdirectional_core.a` | `0133f7bbd232924baddd19f07eccf638b1d6666a7ba372977fed9a05e55a5c9e` |
| `libdirectional_pipeline.a` | `4f0f9079034f1d61fc3fb5a44d0ae0667e5814fec158fce8418d775c99587495` |
| compiled API tests | `392e1f39f1203b1a141f60d9d5f1d3b07155cdba7633965834f1b78ca84f77dd` |
| producer tests | `dcec7671b4ee961367e552a3e93e5b052890cf27fa14e792c4fc669ff25e71e1` |
| oracle tests | `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90` |
| authority-kernel tests | `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71` |
| completion tests | `ba8052942454e2691bedb6fe237aa5cd751e993cca045ebd0b6fc291f4127261` |
| validation tests | `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6` |
| benchmarks | `d94432673ae6c7ebc4f32967c1f052c5263be7095bf976317e3f9ad61b0409c9` |

The unchanged `libdirectional_pipeline.a`, oracle executable, and completion executable demonstrate that unrelated object ownership remains stable where static linking does not consume the migrated seam. Other linked artifacts are expected to change because the authority implementation moved into `directional_core`, the real rail consumer changed, and the validation executable gained six contracts. Runtime equivalence is therefore not inferred from binary hashes.

## 7. Code + Build runtime boundary

Package metadata and workflow activity both record:

```text
runtimeExecution=false
configured=true
compiled=true
generatedDirectionalBinaryExecuted=false
gtestDiscoveryExecuted=false
testExecuted=false
benchmarkExecuted=false
ctestExecuted=false
cliGuiHelpVersionExecuted=false
fuzzerExecuted=false
customInputExecuted=false
```

No generated Directional binary was executed in the authoritative build. Compilation is not semantic acceptance.

## 8. Non-authoritative attempts and correction

Three preliminary connector attempts are retained as failure evidence and are not used as acceptance authority.

### Attempt A — malformed transport patch

- run/job `31330513984 / 93287904577`;
- failed before configure/compile because the temporary connector patch was syntactically corrupt;
- log artifact `9042778290`, SHA-256 `866a4498409a93b9b506f22506504039d8b88a8d1b4eb08f35d06e9c958e53d3`;
- no generated project binary ran and no implementation source was committed by this attempt.

### Attempt B — first implementation compile

- run/job `31330597243 / 93288109479`;
- committed source migration `f768c2f434e2f340f4d7be3192d48abff645a78e`;
- configure succeeded;
- compile stopped at `[49/120]` in `SurfaceOptimizationRailConstraints.cpp` with `expected '}' at end of input`, pointing to the reopened `surface_optimization_rail_detail` namespace;
- log artifact `9042846778`, SHA-256 `d54d9e9639fb31a70e92e8c32d788baba0c9a36b439fc35b96b64d668ab091e0`;
- no test/discovery/runtime process ran.

The correction was intentionally minimal: commit `0340addf...` adds only the missing namespace close (two lines). The authoritative v3 compile then completed 120/120.

### Attempt C — redundant retrigger

- run/job `31330613165 / 93288542324`;
- failed in the deterministic edit step because the source migration had already been applied;
- no configure, compile, source mutation, or runtime process occurred;
- log artifact `9042850169`, SHA-256 `b160206506d60959885eb008eb8bae0cec320a37216af9ec6b44fd726883d264`.

These are orchestration/compile-development failures inside an unaccepted migration slice, not losses of previously accepted runtime authority and therefore not new historical production regression events.

## 9. Regression-pattern disposition

| Pattern | M1b state | Evidence / next gate |
|---|---|---|
| `RP-01` authority-domain conflation | **production adoption compile-complete; runtime pending** | source-face/source-vertex seam crosses named adapters once; helper signature uses distinct strong IDs; six focused contracts packaged |
| `RP-02` test-authority gap | **preservation boundary** | M1a 14-name and T1 29-name manifests unchanged; following immutable turn must execute them and direct cases |
| `RP-05` representation-dependent identity | **production adoption compile-complete; runtime pending** | raw row values are representation access only after typed identity; no row/hash becomes semantic identity |
| `RP-03/04/06/07/08/09` | untouched by M1b behavior scope | source diff and deferred ownership remain unchanged |

No previously accepted product/test authority has been shown lost. Historical totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unaffected.

## 10. Required following turn

Run **M1b First Production Consumer — immutable Test + Benchmark** under:

`.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume exactly result/log artifacts `9042940168 / 9042940336`. Rebuild, relink, edit, substitute, regenerate, or repair nothing.

The following turn must prove:

1. exact package/source/dependency authority and `runtimeExecution=false`;
2. exact discovery of the six M1b focused contracts and **6/6** fresh-process semantic success;
3. the complete validation target remains **77/77** (accepted 71 plus six M1b contracts);
4. M1a authority-kernel discovery remains exact **14** and contracts **14/14**;
5. T1 oracle discovery remains exact **29** and contracts **29/29**;
6. Plane, MultiFaceSeam, CloseSheets, and Cylinder remain green/oracle-clean;
7. BunnyRandom remains explicit known-red with independent-oracle-before-fatal behavior if it returns;
8. Vase remains an explicit bounded safety-only known-red case;
9. no product-result drift, expected-failure conversion, package mutation, or authority-domain conflation occurs.

Only after that immutable runtime acceptance may another M1 consumer migration be planned.
