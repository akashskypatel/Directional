# M1a Authority Kernel Core — Code + Build Report

**Status:** completed for compile/package authority; immutable semantic runtime pending  
**Turn type:** Code + Build only  
**Architecture milestone:** M1a — authority kernel core  
**Production behavior delta:** none  
**Review policy:** `never`  
**Date:** 2026-08-09 UTC

## 1. Result

M1a Code + Build completed successfully. The bounded authority-domain kernel is now compiled and packaged behind a test-only strangler boundary. No existing SurfaceCells producer, validator, tracing, arrangement, completion, optimizer, quotient, benchmark, fixture, or public production decision was migrated.

Compilation is not semantic acceptance. The following turn must consume the immutable artifact and execute the authority-kernel contracts plus the accepted T1 preservation authority before M1b may migrate a real production consumer.

## 2. Exact authority

| Evidence | Value |
|---|---|
| Entering branch head | `9f1d3ebd91403252e990f785c3521588197b4fd4` |
| M1a implementation | `8cd2e73fabf9ecbb9b771fb29db91973e1dca3a7` |
| Build/event commit | `a29c1f673ea93e1614751f42a0c1fef94d23e1fe` |
| Workflow run/job | `31327073928 / 93279043100` |
| Result artifact | `9041930767` |
| Result artifact SHA-256 | `1c1325c038ffe26b80e00dbb69fb15de8b0d0a42673d9720f28bcd9de8549ec5` |
| Log artifact | `9041930871` |
| Log artifact SHA-256 | `e99e053ea4503b720dbe9b6c9ed4762a4eedcbf67c15261e8ea4317824c427cb` |
| Recursive manifest | **53/53**, `fa9068fabd9922496635c82c164431c99590cac2fb9e4973f513623f2ba9bdf6` |
| Package regular files | **54** including `SHA256SUMS` |
| Build closure | Release/static/Ninja **120/120** |
| Build wall / peak RSS | **8:14.63 / 1,835,984 KiB** |
| GTest discovery mode | `PRE_TEST` |
| Runtime execution | **false** |
| Retention | through **2026-08-23 UTC** |

The workflow performed source/static verification, shallow dependency checkout, CMake configure, compile/link, static manifest extraction from source, packaging, and checksumming only. It ran no generated Directional executable, GoogleTest discovery, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.

Temporary workflow and trigger files were removed after immutable artifact capture.

## 3. Exact implementation boundary

The implementation diff from `9f1d3ebd...` to `8cd2e73f...` contains exactly eight paths:

1. `cmake/DirectionalTests.cmake`
2. `include/directional/authority/AuthorityIds.h`
3. `include/directional/authority/CanonicalRoute.h`
4. `include/directional/authority/GridAutomorphism.h`
5. `include/directional/authority/LegacyAuthorityAdapters.h`
6. `include/directional/authority/SourceSupport.h`
7. `src/authority/AuthorityKernel.cpp`
8. `tests/SurfaceCellAuthorityKernelTests.cpp`

`CMakeLists.txt` and existing production sources remain unchanged. `AuthorityKernel.cpp` is linked only into the new authority-kernel test executable in M1a. Existing production consumers remain entirely on their prior behavior path.

## 4. Implemented authority kernel

### Strong semantic domains

M1a introduces distinct non-implicitly-convertible domains for:

- `SourceVertexId`;
- `SourceFaceId`;
- `SourceEdgeTopologyKey`;
- `InteriorTransitionId`;
- `SourceComponentId`;
- `IsolationSheetId`;
- `TopologyRegionId`;
- `FieldChartId`;
- `HardRailId`;
- `PeriodicRelationId`;
- `CellId`;
- `OccurrenceId`;
- `QuotientClassId`.

Raw ID constructors are private. Cross-domain and raw integer implicit conversions are unavailable. `LegacyAuthorityAdapters` performs named checked conversion using explicit `AuthorityDomain`, rejects negative/out-of-range values, rejects deliberate domain mismatch, and returns typed `DomainError`.

### Source support

One tagged `SourceSupport` variant represents source vertex, canonical source edge, or source-face interior support. M1a establishes representation only; it does not replace the current production support classifier.

`SourceEdgeTopologyKey::make` canonicalizes endpoint order and rejects degenerate edges. Directed use remains separate through explicit `Orientation`.

### Exact transport algebra

`QuarterTurn` is exact modulo-4 algebra. `LatticeTranslation` uses integer coordinates. `GridAutomorphism` provides exact identity, composition, inverse, and application with no floating tolerance or zero-rotation special representation.

### Transition and route values

`TransitionStep` combines canonical source-edge topology, optional `InteriorTransitionId`, exact transport, and explicit orientation in one value object. Boundary construction permits no interior transition. Interior construction fails typed if the required transition is absent.

`CanonicalRoute` owns ordered semantic steps and canonical orientation. Exact route reversal reverses step order, inverts each transport, and reverses orientation. Canonical direction is selected from semantic values only.

## 5. Static test authority packaged

The new default-built target is:

`directional_surface_cell_authority_kernel_tests`

with labels:

`contract-required;authority-kernel`

Its immutable source-derived manifest contains exactly **14** contracts:

1. `SurfaceCellAuthorityKernel.StrongIdsAreStaticallyNonInterconvertible`
2. `SurfaceCellAuthorityKernel.CheckedLegacyConversionAcceptsAndRejectsDomainErrors`
3. `SurfaceCellAuthorityKernel.NumericCoincidenceDoesNotConflateDomains`
4. `SurfaceCellAuthorityKernel.SourceEdgeCanonicalizationPreservesExplicitOrientation`
5. `SurfaceCellAuthorityKernel.SourceSupportAlternativesRemainTypeDistinct`
6. `SurfaceCellAuthorityKernel.QuarterTurnNormalizesAndCyclesExactly`
7. `SurfaceCellAuthorityKernel.GridAutomorphismIdentityInverseAndAssociativityAreExact`
8. `SurfaceCellAuthorityKernel.NonzeroRotationTranslationRoundTripIsExact`
9. `SurfaceCellAuthorityKernel.BoundaryStepWithoutInteriorTransitionIsValid`
10. `SurfaceCellAuthorityKernel.InteriorStepRequiresNamedInteriorTransition`
11. `SurfaceCellAuthorityKernel.CanonicalRouteReversalRoundTripIsExact`
12. `SurfaceCellAuthorityKernel.RepresentationHandlePerturbationDoesNotChangeCanonicalRoute`
13. `SurfaceCellAuthorityKernel.LegacyAdapterRoundTripPreservesSemanticValue`
14. `SurfaceCellAuthorityKernel.DeliberateCrossDomainAdapterMisuseIsRejected`

The accepted T1 oracle manifest remains exactly **29** names with `contract-required;oracle-mutation` labels. No authority or oracle test was executed during this turn.

Static manifest hashes:

- authority-kernel names: `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d`;
- oracle names: `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb`.

## 6. Package inventory and source authority

The immutable package contains:

- seven ELF executables, including the new authority-kernel target;
- two static libraries;
- all 27 benchmark fixture files;
- source patch and source archive;
- compile database;
- exact source-blob inventory;
- toolchain/submodule records;
- static 14-name authority manifest;
- static 29-name T1 oracle manifest;
- command-boundary and build-authority metadata;
- logs and recursive checksums.

Additional hashes:

| Member | SHA-256 |
|---|---|
| Authority-kernel executable | `2ef7f06611787b088d0ddcfc16d6f15f5b12d313655f80dcf019c990a3509124` |
| M1a patch | `51d0f6e79681d8e02fea58781a9aaf35609ebd6e40230ecee538d7e4d02922b2` |
| Source archive | `1c0290da02148d0798f668d2d9ddbd91d6262ca875f3fb1b2d38cd162da7e2c3` |
| Compile database | `5288ccccdc7814dcda9b96dcf2e7bb5018ccb5d482b0b2d0cdab021895558088` |

Exact M1a source blobs recorded by the artifact include:

- `cmake/DirectionalTests.cmake`: `1f49d83eaac2bd6bf14513936d866683a03620a6`;
- `AuthorityIds.h`: `3892126eb7646ac6e1cd47bf0b139286d329b73d`;
- `SourceSupport.h`: `1281e5991d809f8cc3f4984e2f0ac9489abb7f3e`;
- `GridAutomorphism.h`: `b3e8128707eea56ca52377385758f390e3c5e284`;
- `CanonicalRoute.h`: `542b5475ac407ae4541e2ac36f298a727403aff4`;
- `LegacyAuthorityAdapters.h`: `e23fb460f3b435c8ea9d5958b3d9c9cd813899b6`;
- `AuthorityKernel.cpp`: `19abad161d865262413d00c310ca1def166b6494`;
- `SurfaceCellAuthorityKernelTests.cpp`: `9dcdab568e204026eb0c2aebc1b43cd8de8db62c`.

Accepted T1 source authority remains unchanged:

- oracle tests: `28932c8c2dbe844b62f8fe848e6ebb9ef67550de`;
- oracle support: `e3b04f4c45ab9acaa078c29defb868326db504dd`;
- direct acceptance: `aff7894aae3397bef47be777a8bf7e2fbb0c27ef`.

## 7. Strong no-production-delta compile evidence

Every pre-existing binary/library packaged in accepted T1 artifact `9041289209` is byte-for-byte identical in M1a artifact `9041930767`:

| Existing artifact member | SHA-256 |
|---|---|
| `libdirectional_core.a` | `d047dd9e9433a050480068b7d0fac1517026a7741bf11c86da376610c1fadd25` |
| `libdirectional_pipeline.a` | `4f0f9079034f1d61fc3fb5a44d0ae0667e5814fec158fce8418d775c99587495` |
| compiled API tests | `41bcf7db93b9d062545f9f0d6fbed8de1253e0ab1a4e471e8d7622ed27af3b9a` |
| producer tests | `a7cfc1637906d106992f9d391359d46549bb70b28f9bdbabe3c4c5289c6050a6` |
| oracle tests | `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90` |
| completion tests | `ba8052942454e2691bedb6fe237aa5cd751e993cca045ebd0b6fc291f4127261` |
| validation tests | `b4be6cd64ef84bc857ba5156d6c108c3d9ec9248dba968315a633690b4350bcd` |
| benchmarks | `af85f102974449bd4561ded0aec9b00c8168e3c8cc5ddc68843842c1b6fcb6e8` |

This is compile/package evidence that the M1a scaffolding did not alter existing executable/library authority. Runtime semantic acceptance still belongs to the following artifact-only turn.

## 8. Regression-pattern disposition

| Pattern | Touched? | M1a corrective invariant | Current evidence |
|---|---|---|---|
| `RP-01` | **yes** | distinct domain types; raw construction private; checked named adapter rejects domain mismatch/negative/out-of-range | compiled static asserts + packaged counterexample tests; runtime pending |
| `RP-02` | yes, preservation boundary | accepted independent oracle/package authority remains unchanged | T1 source blobs and oracle executable are byte-identical; 29-name manifest retained |
| `RP-03` | no | producer-state model unchanged | production diff excludes it |
| `RP-04` | no | no recursion/search introduced | bounded value algebra only |
| `RP-05` | **yes** | semantic equality excludes representation handles; orientation explicit | canonical-route/handle-perturbation contracts packaged; runtime pending |
| `RP-06` | no | no authority membership storage change | production diff excludes it |
| `RP-07` | **yes** | exact Z4 composition/inverse and route reversal | algebra/reversal contracts packaged; runtime pending |
| `RP-08` | no | producer disposition unchanged | production diff excludes it |
| `RP-09` | no | global/local relation consumption unchanged | production diff excludes it |

No accepted behavior was lost during this Code + Build, so there is no new regression event or recurrence. Historical totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and unaffected.

## 9. Required following turn

Run **M1a Authority Kernel Core — immutable Test + Benchmark** under:

`.agents/Directional/Architecture_M1a_Authority_Kernel_Core_Artifact_Only_Test_Benchmark_Plan.md`

Consume exactly result artifact `9041930767` and log artifact `9041930871`. Rebuild, relink, edit, substitute, or regenerate nothing.

M1a remains `fix_pending_runtime` at the architecture-migration boundary until that immutable turn accepts all authority-kernel semantics and preserves T1/product comparison authority. Only then may M1b migrate the first real production consumer.
