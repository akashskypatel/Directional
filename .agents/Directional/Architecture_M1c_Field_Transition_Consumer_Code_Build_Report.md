# M1c Field-Transition Consumer — Code + Build Report

**Status:** completed for compile/package authority; immutable runtime pending  
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — authority kernel and staged production adoption  
**Production behavior delta:** none intended; runtime not executed in this turn  
**Review policy:** `never`  
**Date:** 2026-08-09 UTC

## 1. Result

M1c completed the bounded migration of the authoritative `fields::CrossFieldEdgeTransition` consumer inside:

`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`.

The selected seam now makes source-face reciprocity, source-edge identity, and quarter-turn branch transport semantic through the accepted M1 authority kernel. Public `CrossFieldResult` storage, raw compatibility result fields, the separate `edgeTransitions == nullptr` fallback, topology/certificate policy, rails, completion, validators, fixtures, fallback/recovery, and G4 behavior remain intentionally unchanged.

Compilation and packaging establish implementation/build authority only. M1c semantics are **not accepted** until the following immutable Test + Benchmark turn consumes this exact artifact without rebuilding or editing source.

## 2. Authoritative compile/package evidence

| Evidence | Value |
|---|---|
| Entering migration base | `512d9523f13158a9f71b406b6db7137a1db3c504` |
| M1c implementation | `e139fca885538e310dc47ed7ba531517603d92cf` |
| Build/event commit | `ebda31859a18005844f81274393211991361cbbb` |
| Workflow run/job | `31334345368 / 93297618568` |
| Result artifact | `9043971772` |
| Result artifact SHA-256 | `dde120c94be222dc93aeebb08f7a674882c5f8011ede62ec420209b0e0f4fd85` |
| Log artifact | `9043971968` |
| Log artifact SHA-256 | `7747b3b25882fc86e54890a1efb69d753f9b2e08bff7db8fd2be4f4a8a82fedb` |
| Recursive package manifest | **54/54**, SHA-256 `d9a4bdfe5b160095a6cf4949c57e54d726d36f745ff0a6580e9080d5319d495d` |
| Package regular files | **55**, including `SHA256SUMS` |
| Compile closure | Release/static/Ninja **120/120** |
| Build wall / peak RSS | **8:31.95 / 1,836,460 KiB** |
| GoogleTest discovery mode | `PRE_TEST` |
| Runtime execution | **false** |
| Retention | through **2026-08-23 UTC** |

Read-only artifact preflight confirmed:

- both outer ZIP digests exactly match GitHub artifact digests;
- neither ZIP contains absolute or escaping archive paths;
- all **54/54** packaged checksums verify;
- seven ELF executables, two static libraries, and all 27 benchmark fixtures are present;
- no generated Directional binary was executed during build or inspection.

## 3. Exact implementation boundary

After temporary connector workflow/helper cleanup, the M1c product/test diff from the migration base is exactly:

1. `src/geometry/SurfaceCellTracing.cpp`;
2. `tests/SurfaceCellsPhase10Tests.cpp`.

No public/detail header, CMake, cross-field schema, fixture, validator, benchmark-policy, or product-policy change was required.

### Checked source-face reciprocity

The authoritative transition branch keeps the pre-existing source-edge topology/adjacency check first. It then converts:

- `sourceFace` and `targetFace`;
- `CrossFieldEdgeTransition.firstFace` and `secondFace`;

through `LegacyAuthorityAdapters::source_face(..., faces.rows())`. Invalid conversion fails through the existing invalid `BranchTransitionResult`. Forward/reverse authoritative reciprocity is decided from typed `SourceFaceId`, not raw integer coincidence.

### Canonical source-edge identity

`sourceVertex0/1` are converted through `LegacyAuthorityAdapters::source_vertex(..., vertices.rows())` and canonicalized through `SourceEdgeTopologyKey::make`.

Endpoint order therefore does not define semantic identity. The canonical typed endpoints are converted back to legacy row indices only at the existing `uint64_t edge_key` compatibility boundary. No second semantic hash/key scheme was introduced.

### Exact quarter-turn transport

Authoritative semantic branch transport now uses:

`QuarterTurn::from_integer(transition.matching)`

and `.inverse()` for reverse traversal. The selected target branch is derived from the typed modulo-four quarter turn.

The existing compatibility value remains unchanged:

- forward traversal publishes raw `transition.matching`;
- reverse traversal publishes the negated raw integer.

Thus `matching=+5` is semantically equivalent to `+1` while legacy diagnostics/certificate representation remains unchanged in this slice.

### Preserved fallback boundary

The separate `edgeTransitions == nullptr` `edgeMatching` / `edgeEffort` fallback remains unchanged. When authoritative transition metadata is selected, missing or malformed authoritative metadata fails closed and does not fall through to legacy matching or geometric inference.

## 4. Focused test authority compiled

Exactly six new semantic/counterexample contracts are compiled into `directional_surface_cell_producer_tests`:

1. `SurfaceCellFieldTransitionAuthorityMigration.ForwardQuarterTurnUsesTypedModuloTransport`;
2. `SurfaceCellFieldTransitionAuthorityMigration.ReverseTraversalUsesExactQuarterTurnInverse`;
3. `SurfaceCellFieldTransitionAuthorityMigration.EquivalentQuarterTurnsNormalizeSemantically`;
4. `SurfaceCellFieldTransitionAuthorityMigration.ReversedSourceEdgeEndpointsPreserveSemanticIdentity`;
5. `SurfaceCellFieldTransitionAuthorityMigration.MalformedAuthoritativeFaceOrEdgeFailsClosed`;
6. `SurfaceCellFieldTransitionAuthorityMigration.LegacyMatchingFallbackRemainsUnchangedWhenTransitionMetadataAbsent`.

Static M1c focused manifest SHA-256:
`4cb94bd2afc6bc9430a138f794d4395a2847af2e8631e177b86e784c01cf1055`.

These tests call the real `resolve_branch_transition` seam with explicit expected direction/family/sign results. They do not replace independent product authority and were not executed during Code + Build.

Existing counterexample sources remain unchanged, including:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

## 5. Preserved M1b/M1a/T1 static authority

The immutable package retains unchanged static manifests/source authority:

| Authority | Count / SHA-256 |
|---|---|
| M1b focused | **6**, `a536c0772bc90b8fe3c91dd466b1d515339232bbcaf7c807956fdbfbfeea9320` |
| M1a authority kernel | **14**, `d0fc5ed736b048d5b72136fe17ce579661b3c65ca9118f01cfcbefc35ba8d79d` |
| T1 independent oracle | **29**, `909a53d28c0c5eaa3d8759c95b55a0ff664074259153325e703ccd0e371004bb` |

Unchanged source blobs include:

- `tests/SurfaceMeshOptimizerPhase22Tests.cpp`: `466e2bbd000413ee60c77cc06fe707641dbe4740`;
- `tests/SurfaceCellAuthorityKernelTests.cpp`: `9dcdab568e204026eb0c2aebc1b43cd8de8db62c`;
- `tests/SurfaceCellProductOracleTests.cpp`: `28932c8c2dbe844b62f8fe848e6ebb9ef67550de`;
- `tests/SurfaceCellDesignAcceptanceTests.cpp`: `aff7894aae3397bef47be777a8bf7e2fbb0c27ef`.

Runtime preservation remains the following turn's responsibility.

## 6. Exact M1c source/package hashes

| Member | SHA-256 / Git blob |
|---|---|
| `SurfaceCellTracing.cpp` blob | `053759bec2e07a2827f54411d85e73ef4b4ef71a` |
| `SurfaceCellsPhase10Tests.cpp` blob | `2a1aa2ae17a9be1f2660eef6da396f9b3793566a` |
| tracing header blob | `b87e37676a980162e7ef3ac1fa9d954ce2199ad2` |
| authority IDs blob | `3892126eb7646ac6e1cd47bf0b139286d329b73d` |
| legacy adapters blob | `e23fb460f3b435c8ea9d5958b3d9c9cd813899b6` |
| grid automorphism blob | `b3e8128707eea56ca52377385758f390e3c5e284` |
| packaged M1c patch | `32c0c89ee8e899667f323cab74fed0d74423c3685e8474c26b8195bca911516b` |
| source archive | `a6aac583ea419a39d449e5caa64dc8140cfbbf77df6d94feca01017be827208b` |
| compile database | `aa91af44338f8776d982b43ae9ef0a8ba65a58ec879c8a7266d8bf0c1bd11ce9` |

Packaged binary/library hashes:

| Member | SHA-256 |
|---|---|
| `libdirectional_core.a` | `59cd0248adc5d7b91436126063036cdfd439b81260bca66f25a874efc7b5112e` |
| `libdirectional_pipeline.a` | `4f0f9079034f1d61fc3fb5a44d0ae0667e5814fec158fce8418d775c99587495` |
| compiled API tests | `65d452ebd8116a4b409273ba2abdc30a07f558a0f457252be897b7ad0036e0e0` |
| producer tests | `9608ec2a0fc8eec52e4ceb61df53c0aae5670f9834b358a08e390ac9bb93fbdd` |
| oracle tests | `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90` |
| authority-kernel tests | `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71` |
| completion tests | `bd6626c73c25c2d721db7a6e5f6d5fbb1dd15751da5cdc249b8dfd4fa057cfaa` |
| validation tests | `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6` |
| benchmarks | `07cc207afcfb8e1b8d67a6746a2c5a87a9b4935b1690703895171d767f0111b3` |

## 7. Code + Build runtime boundary

Package metadata and workflow activity record:

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

No generated Directional binary was executed. Compile success is not semantic acceptance.

## 8. Non-authoritative orchestration attempts

Temporary connector workflow development produced non-authoritative orchestration attempts before/around the accepted run:

- an initial malformed workflow revision failed at workflow startup before any job or generated project binary;
- redundant later triggers encountered deterministic preflight mismatches after `e139fca...` had already been applied and failed before product edit/configure/compile/runtime.

They are retained as orchestration evidence only and do not represent loss of accepted product/test authority. The authoritative build is solely run/job `31334345368 / 93297618568` and artifacts `9043971772 / 9043971968`.

All temporary M1c workflows, triggers, and helper scripts were removed after artifact capture. They are not part of the final implementation/test/build delta.

## 9. Regression-pattern disposition

| Pattern | M1c Code + Build state | Evidence / next gate |
|---|---|---|
| `RP-01` authority-domain conflation | **compile-complete; runtime pending** | checked `SourceFaceId`/`SourceVertexId`; malformed authority counterexample compiled |
| `RP-05` representation-dependent identity | **compile-complete; runtime pending** | canonical `SourceEdgeTopologyKey`; endpoint-reversal counterexample compiled |
| `RP-07` cyclic topology linearization | **compile-complete; runtime pending** | `QuarterTurn` modulo/inverse; `+5 == +1` semantic counterexample compiled |
| `RP-02 / TA-05` independent authority | **preservation pending** | following immutable turn must repeat M1b/M1a/T1/direct evidence |
| `RP-03/04/06/08/09` | untouched | bounded two-path product/test diff |

No previously accepted runtime behavior has been shown lost in this compile-only turn. Historical totals remain **34 events / 14 categories / 20 recurrences**. `PR8-R034 / G4-R007` remains active and separate.

## 10. Required following turn

Run **M1c Field-Transition Consumer — immutable Test + Benchmark only** under:

`.agents/Directional/Architecture_M1c_Field_Transition_Consumer_Artifact_Only_Test_Benchmark_Plan.md`.

Consume exactly result/log artifacts `9043971772 / 9043971968`. Rebuild, relink, edit, substitute, regenerate, or repair nothing.

The immutable turn must establish the six M1c contracts, the explicit existing transition counterexamples, complete relevant producer preservation, M1b validation authority, M1a, T1, and direct Plane/MultiFaceSeam/CloseSheets/Cylinder product authority. Bunny/Vase retain their explicit known-red/safety-only comparison roles and may use the authorized artifact-only GitHub Actions procedure.

Only after that immutable runtime acceptance may M1c be marked accepted or another production consumer be planned.
