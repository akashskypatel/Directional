# M1e Segment Route Transport Consumer — Artifact-Only Test + Benchmark Report

**Status:** immutable accepted  
**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Source/test/build mutation:** none

## 1. Result

M1e is **accepted** at the selected transport-owning consumer:

`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

The exact compiled package from implementation `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` passed every required-green semantic, preservation, product, discovery, integrity, and postflight gate. No source, test, fixture, benchmark, build logic, executable, library, or regular packaged content was rebuilt, relinked, regenerated, patched, repaired, or substituted during this turn.

M1e therefore accepts:

- `RP-01` checked source-vertex/interior-transition authority at ordered segment-route transport;
- `RP-05` semantic route-step identity and observed-versus-canonical route orientation at this consumer;
- `RP-07` typed cumulative quarter-turn/grid-automorphism composition at this consumer;
- `RP-02 / TA-05` preservation through complete producer accounting and independent M1d/M1c/M1b/M1a/T1/direct product authority.

Historical totals remain **34 regression events / 14 categories / 20 recurrences**. No new stable regression event or recurrence was created. `PR8-R034 / G4-R007` remains active and unchanged.

## 2. Exact immutable authority

| Evidence | Value |
|---|---|
| implementation | `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` |
| build/event | `34036600128262e909c377006a056a2b9976f986` |
| build run/job | `31351113129 / 93341993183` |
| result artifact | `9049125645` |
| result ZIP SHA-256 | `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7` |
| log artifact | `9049125905` |
| log ZIP SHA-256 | `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be` |
| recursive manifest | **61/61**, `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5` |
| package | **62** regular files; 7 executables; 2 static libraries; 27 fixtures |
| production blob | `34372a48412213d3b4db6d0bc3e653e7d3225ef0` |
| rewritten test blob | `f55d016db2c89710b79c711a0d5e780dcfb2bdfc` |
| Code + Build runtime | `false` |

The branch head at turn entry was documentation-only ahead of the implementation. Comparison from `a0330d0...` to the then-current PR head contained only `.agents/Directional`, `TODO`, and `MILESTONE_G_TODO.md` changes; no later product/test/build change replaced the built implementation authority.

Artifacts were confirmed unexpired and their GitHub API digests matched the declared ZIP digests before download.

## 3. Immutable preflight

The exact result and log artifacts were downloaded through the GitHub connector and inspected in a fresh arbitrary directory.

Preflight passed:

- result ZIP SHA-256 exact;
- log ZIP SHA-256 exact;
- no absolute, parent-traversal, or unsafe archive member;
- `SHA256SUMS` digest exact;
- **61/61** recursive package checksums exact;
- exactly 62 regular package files;
- exactly seven executables;
- exactly two static libraries;
- exactly 27 fixtures;
- `metadata/build-authority.json` identified implementation `a0330d0...`, event `3403660...`, run `31351113129`, Release/static/Ninja, `PRE_TEST`, and `runtimeExecution=false`;
- every runtime/test/discovery/benchmark/ctest/CLI/fuzzer/custom-input boundary flag remained false;
- source archive/patch, source blobs, static manifests, and compile database were retained;
- executable hashes matched the immutable plan before execution permission was restored;
- runtime-only `bin/test-data -> ../test-data` was created only after content verification and remained a non-regular symlink outside packaged-content accounting.

Executable SHA-256 values matched the plan exactly:

- producer `5e2e85ede99f50b82aba70ce0a829a59b5c74bb42585845f681d80e578402259`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `97a1b99948bc5b76521be2501d2573f75cf958f44aa9918a02dfcd8180619acd`;
- compiled API `84c1bc634770715f095c64d6c749b0ffa46e024af3656d5f0fc3c43982fbc7de`;
- benchmark `6490b7c39c2b58d2ab44ba2b258167b93dccf53dd1f7e8160cc626861c69f42e`.

Runtime environment used for artifact execution was Linux x86-64, Debian glibc 2.41, Intel Xeon Platinum 8370C, with approximately 6.2 GB reported system memory. Runtime measurements in this report are diagnostic only unless an existing gate states otherwise.

## 4. Discovery authority

Native packaged GoogleTest discovery passed with exact unique counts:

| executable | discovered |
|---|---:|
| producer | **184** |
| validation | **77** |
| M1a authority kernel | **14** |
| T1 independent oracle | **29** |

The static M1e manifest SHA-256 was exact:

`b6a1c9035b2cd15a13844f812e7261ee0e199e72d0150d9a093a59d1ce713556`.

It contained exactly the six planned `SurfaceCellSegmentRouteTransportAuthorityMigration` tests and no extra or missing member.

## 5. M1e focused semantic result

Each M1e test ran as one exact selection in a fresh process. Result: **6/6 passed**.

| Contract | Result |
|---|---:|
| `MultiStepVertexFanComposesTypedRouteTransport` | pass |
| `ReverseObservedRouteUsesExactTransportInverse` | pass |
| `EquivalentSignedQuarterTurnsComposeSemantically` | pass |
| `RouteTopologyAndCompactTransitionProvenanceRemainUnchanged` | pass |
| `MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback` | pass |
| `LegacyMatchingFallbackUsesSameTypedRouteComposition` | pass |

A source-level oracle review was also performed against the exact packaged test source. The fixture uses the predetermined route `2 -> 3 -> 10` through source vertex `7`, independently authored nonzero step turns `3` and `2`, hard endpoint expectations `1/3`, topology `(1,7) -> (6,7)`, and independently enumerated compact IDs `2/9`. Equivalent-representation and legacy comparisons are semantic route-keyed comparisons rather than positional output pairing. The malformed test first establishes the valid route and then corrupts the reachable predecessor provenance boundary, requiring `MissingTransitionProvenance` without fallback/output.

No focused expected value was accepted merely because it duplicated the production route-composition algorithm.

## 6. Preservation gates

All planned preservation gates passed:

| Gate | Result |
|---|---:|
| ordered vertex-fan witnesses | **2/2** |
| M1d focused route authority | **6/6** individually |
| M1d route counterexamples | **3/3** individually |
| M1c focused transition authority | **6/6** individually |
| M1c transition counterexamples | **3/3** individually |
| M1b rail/source authority | **6/6** individually |
| producer required-green aggregate | **169/169** |
| full validation executable | **77/77** |
| M1a authority kernel | **14/14** |
| T1 independent product oracle | **29/29** |

The producer required-green aggregate selected exactly 169 tests after excluding only the four separately executed direct product tests, nine declared historical/deferred cases, BunnyRandom, and Vase. It returned rc=0 with **169/169** passing.

One discarded invocation attempted the six M1b names against the producer executable and selected zero tests. It is not acceptance evidence. The six contracts were then executed against their correct validation executable, each selected exactly once, and passed **6/6**. No product state was inferred from the zero-selection invocation.

## 7. Direct product preservation

Each direct product case ran as one exact test with direct `SurfaceCells` output, recovery/fallback prohibitions and the independent product oracle enforced by the existing acceptance fixture.

| Product | Result | wall | peak RSS |
|---|---:|---:|---:|
| Plane | pass | 1.30 s | 11,112 KiB |
| MultiFaceSeam | pass | 2.06 s | 11,028 KiB |
| CloseSheets | pass | 15.73 s | 13,092 KiB |
| Cylinder | pass | 8.82 s | 14,752 KiB |

All four remained independent-oracle clean. These timings are diagnostics rather than a cross-machine performance claim.

## 8. Historical/deferred producer cases

The nine declared historical/deferred cases were executed individually.

Eight retained their established failure classes:

1. `MultiIsolationMaterializationRetainsAllLocalSheets` — existing boolean assertion red;
2. `FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`;
3. `TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`;
4. `MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`;
5. `SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`;
6. `MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`;
7. `QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing boolean assertion red;
8. `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — `NotProductionReady:tracing ... InvalidHardRailPairing` with the same unmet downstream diagnostic expectations.

`StrictValidatorOverheadStaysBelowFivePercent` passed its first planned invocation, which conflicted with the entering historical timing-red disposition. It was therefore characterized rather than relabeled green. Ten fresh repetitions produced **6 passes / 4 failures**. Failing samples compare sub-millisecond measurements around the 5% threshold, e.g. `0.000183516` versus `0.0001824849` and `0.000263726` versus `0.00019117395`.

Classification: **nondeterministic microbenchmark timing gate**. It remains deferred and is not stable product evidence. This does not create a restored-then-lost production regression event; it exposes instability in the existing performance test/oracle. No retry was used to manufacture acceptance, and no threshold/test edit occurred in this immutable turn.

## 9. Bunny and Vase comparison

The exact M1e producer executable and packaged fixtures were used.

### BunnyRandom

- exactly one test selected;
- rc=1;
- 89.28 s wall;
- 338,232 KiB peak RSS;
- independent product oracle rejected first with empty/non-quad/component/Euler/output-origin/terminal-failure evidence;
- terminal product failure remained exactly:

`NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`.

The prior known-red failure class is preserved. Runtime is diagnostic only because the entering Bunny evidence came from a different execution environment and no comparison threshold is authorized here.

### Vase

- exactly one test selected and reached `[ RUN ]`;
- bounded at 60.01 s;
- rc=124;
- 68,972 KiB peak RSS;
- no success/failure product claim was made.

Disposition remains **bounded safety-only**.

## 10. Immutable postflight

Postflight passed after all executions:

- original result ZIP SHA-256 exact;
- original log ZIP SHA-256 exact;
- manifest SHA-256 exact;
- **61/61** packaged checksums exact;
- producer/oracle/authority/validation executable hashes unchanged;
- exactly 62 regular package files remained;
- the runtime fixture locator remained the only recorded non-regular addition.

The immutable artifact therefore remained byte-authoritative for every regular packaged item.

## 11. Regression and architecture disposition

M1e is immutable accepted. Update architecture state as follows:

- M1a/M1b/M1c/M1d/M1e: **accepted**;
- `RP-01`: accepted at the ordered segment-route step domain boundary;
- `RP-05`: accepted at the route-step identity and observed/canonical orientation boundary;
- `RP-07`: accepted at cumulative ordered segment-route transport;
- `RP-02 / TA-05`: preserved through exact producer 184 accounting plus M1d/M1c/M1b/M1a/T1/direct evidence;
- `RP-03/04/06/08/09`: untouched by M1e;
- `PR8-R034 / G4-R007`: still active;
- G4 product acceptance remains active and separate from M1 architecture migration.

The strict-validator timing instability should remain tracked as a deferred nondeterministic performance-test defect. It must not be “fixed” by retries or threshold weakening.

## 12. Remaining real transport owners inspected

After M1e acceptance, the exact packaged production source was inspected for remaining raw cyclic/route transport ownership before selecting another M1 slice.

Two real consumers remain notable:

1. `surface_cell_tracing_detail::resolve_vertex_continuation` keeps cumulative `PathState::matching` and advances it with raw `transition.matching` while enumerating an ordered source-vertex continuation route. It later publishes candidate/segment matching. This is a narrow, direct continuation of the M1e ownership boundary and can reuse the accepted typed route algebra without changing path selection.
2. periodic annulus phase-front construction keeps a separate whole-cycle `totalMatching` holonomy accumulator and rejects nonzero normalized rotation. That is a wider global cyclic owner adjacent to deferred periodic/G4 capability and remains a later candidate, not the next approved slice.

No production `FieldChartId` migration is selected merely because the type exists.

The next bounded architecture slice is therefore **M1f Vertex Continuation Route Transport Consumer**. It must preserve path discovery/ranking and migrate only the transport fact at the real continuation owner.

Authoritative next plan:

`.agents/Directional/Architecture_M1f_Vertex_Continuation_Route_Transport_Consumer_Code_Build_Plan.md`.

## 13. Evidence retention and cleanup

At turn start, the stale M1d per-turn Test + Benchmark report was removed only after its accepted facts were confirmed in durable/live authority and immutable artifact history.

At closeout, the consumed M1e Test + Benchmark plan and superseded M1e Code + Build plan/report are stale per-turn evidence. They are removed after this report and the next Code + Build plan become authoritative, with durable-document references repaired to point at stable facts or this current report.

Durable design, architecture, regression, workflow, testing, TODO, and handoff authority is preserved. No destructive durable-information edit is authorized or performed.
