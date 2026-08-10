# M1e Segment Route Transport Consumer — Artifact-Only Test + Benchmark Plan

**Status:** authoritative next turn  
**Turn type:** immutable Test + Benchmark only  
**Review policy:** `never`  
**Source/test/build mutation:** prohibited

## 1. Objective

Validate the exact compiled M1e package without rebuilding, relinking, regenerating, editing, repairing, or substituting any source, test, fixture, executable, library, or regular package content.

M1e selected consumer:

`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`

The immutable turn must establish that the new typed route transport is behaviorally correct and preserves accepted M1d/M1c/M1b/M1a/T1/direct product authority. Compile success alone is not semantic acceptance.

## 2. Exact immutable build authority

Consume only:

| Evidence | Value |
|---|---|
| M1e base | `5df33fc11deaac697cb886d8defcaba622ec436f` |
| Final M1e implementation | `bb9cb63a36b64fe2f7c462ad864492c8352b65e8` |
| Build/event commit | `106e408065e5bda1eb680bc54aef007a1a2d68d6` |
| Build run/job | `31345475101 / 93326482946` |
| Result artifact | `9047295489` |
| Result ZIP SHA-256 | `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f` |
| Log artifact | `9047295703` |
| Log ZIP SHA-256 | `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52` |
| Recursive manifest | **61/61**, `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e` |
| Package | **62** regular files including manifest; 7 executables; 2 static libs; 27 fixtures |
| Runtime in Code + Build | **false** |
| Retention | through `2026-08-24 00:58 UTC` |

The package build authority also records first failed compile commit `9edbef1fe34d60d2a507160aa4a27883cea36903`; that commit is not runtime authority. The final immutable implementation is `bb9cb63...` only.

## 3. Immutable preflight

Before executing any packaged Directional binary:

1. download artifact `9047295489` specifically from build run `31345475101` and log artifact `9047295703`;
2. verify GitHub artifact ID, run ID, expiration state, and API digest;
3. verify downloaded ZIP SHA-256 values exactly;
4. reject absolute paths, `..` traversal, unsafe archive members, and unexpected archive substitution;
5. extract into a fresh arbitrary directory;
6. verify `SHA256SUMS` digest exactly `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e` and every **61/61** entry;
7. require exactly 62 regular package files, seven packaged executables, two static libraries, and 27 fixtures;
8. verify `metadata/build-authority.json` identifies implementation `bb9cb63...`, event `106e408...`, run `31345475101`, Release/static/Ninja, PRE_TEST, and `runtimeExecution=false`;
9. verify every `metadata/command-boundary.txt` runtime/test/discovery/benchmark/ctest/CLI/fuzzer/custom-input flag remains false;
10. verify source patch/archive and source-blob authority;
11. verify executable content hashes before restoring executable permission if artifact extraction stripped mode bits;
12. only after content verification, create a runtime-only non-regular fixture locator symlink if the packaged tests require `bin/test-data -> ../test-data`; record it separately and never count it as packaged regular content.

Expected executable SHA-256:

- producer `0a8e67953e7221daf0fe607794c3b69f2e3fb8331b91ab08a02c10d52152943e`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`.

## 4. Native discovery authority

Use native packaged GoogleTest discovery once for each required executable. Zero selection is invalid.

Require:

- producer exactly **184 unique tests**;
- validation exactly **77**;
- M1a authority kernel exactly **14**;
- T1 oracle exactly **29**.

The M1e suite must discover exactly the six statically packaged names, with no extra/missing member:

1. `SurfaceCellSegmentRouteTransportAuthorityMigration.MultiStepVertexFanComposesTypedRouteTransport`;
2. `.ReverseObservedRouteUsesExactTransportInverse`;
3. `.EquivalentSignedQuarterTurnsComposeSemantically`;
4. `.RouteTopologyAndCompactTransitionProvenanceRemainUnchanged`;
5. `.MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`;
6. `.LegacyMatchingFallbackUsesSameTypedRouteComposition`.

Static M1e manifest SHA-256 must remain `b6a1c9035b2cd15a13844f812e7261ee0e199e72d0150d9a093a59d1ce713556`.

## 5. M1e focused semantic execution

Run each M1e test in a **fresh process**, exactly one selected test per invocation. Require **6/6** pass with rc=0.

Interpret intent strictly:

- `MultiStepVertexFanComposesTypedRouteTransport` must prove the fixture actually exposes a multi-step production route and the published matching equals independently reconstructed semantic step composition;
- `ReverseObservedRouteUsesExactTransportInverse` must find a genuine reciprocal observed route and prove exact quarter-turn inverse, not merely sign negation;
- `EquivalentSignedQuarterTurnsComposeSemantically` must prove raw `+4` representation changes do not change semantic route/provenance/matching behavior;
- `RouteTopologyAndCompactTransitionProvenanceRemainUnchanged` must prove exact existing ordered packed topology and compact transition provenance;
- `MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback` must reject corrupted authoritative step metadata through production without fallback/recovery/synthetic output;
- `LegacyMatchingFallbackUsesSameTypedRouteComposition` must prove the explicitly supported `edgeTransitions`-absent path preserves equivalent observable route behavior through the typed composition boundary.

If any fixture fails to establish its intended semantic precondition, **do not weaken or reinterpret the test inside this immutable turn**. Record the exact evidence and return to corrective M1e Code + Build.

## 6. Existing M1e route witnesses

Run individually and require green:

- `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`;
- `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`.

These are preservation witnesses only; they cannot substitute for the six M1e focused semantic contracts.

## 7. M1d preservation

Require exact M1d focused suite membership six and **6/6** individually:

`SurfaceCellPhaseFrontRouteAuthorityMigration.*`

Also run and require green:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

This proves M1e route transport did not regress accepted phase-front route identity authority.

## 8. M1c preservation

Require exact M1c focused suite six and **6/6** individually:

`SurfaceCellFieldTransitionAuthorityMigration.*`

Also require these three existing counterexamples green:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

This preserves accepted per-edge quarter-turn/inverse semantics while M1e validates cumulative route composition.

## 9. Complete producer accounting

Producer discovery target is exactly **184**.

Expected complete accounting:

- required-green producer segment: exactly **169**, require **169/169** pass;
- direct required-green cases run separately: four;
- historical/deferred known-red tests: nine, each executed individually and explicitly classified;
- BunnyRandom: one;
- Vase: one;
- total: `169 + 4 + 9 + 1 + 1 = 184`.

The required-green aggregate must exclude only the four separately-run direct product tests, the nine declared historical/deferred reds, BunnyRandom, and Vase. It must not silently exclude newly red M1e or preservation tests.

The nine historical/deferred reds remain:

1. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets`;
2. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize`;
3. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected`;
4. `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner`;
5. `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected`;
6. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected`;
7. `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority`;
8. `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
9. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary`.

Persistence of their existing accepted failure class is not a new recurrence. Any materially changed failure or newly red required-green test must be investigated and classified.

## 10. M1b, M1a, and T1 preservation

Require:

- M1b `SurfaceOptimizationRailAuthorityMigration`: exact six, **6/6** individually;
- full validation executable: exact discovery **77**, **77/77**, rc=0;
- M1a authority kernel: exact 14, **14/14**, rc=0;
- T1 independent product oracle: exact 29, **29/29**, rc=0.

Focused M1e passes never substitute for this independent authority.

## 11. Direct product preservation

Run each exact existing direct product case individually:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder.

Each must:

- select exactly one test;
- return rc=0;
- remain direct `SurfaceCells` output with no fallback/recovery;
- remain independent-product-oracle clean.

Record elapsed time and peak RSS as diagnostic evidence, not newly calibrated performance thresholds.

## 12. Bunny/Vase comparison

Use the exact existing direct product tests from artifact `9047295489`.

Long-runtime artifact-only GitHub Actions remains authorized if local execution is impractical. Any temporary runtime workflow must:

1. download exact artifact `9047295489` from build run `31345475101`;
2. verify GitHub digest, outer ZIP SHA, build authority, all **61/61** checksums, 62 regular files, and producer hash **before** runtime;
3. configure/build/relink/regenerate/edit nothing;
4. restore executable permission only after hash verification;
5. run exactly one requested case under an explicit guard;
6. retain selected count/filter/stdout/stderr/rc/time/resource/postflight evidence;
7. reverify artifact, manifest, producer and regular-file count afterward;
8. remove/disable the temporary workflow **before** deleting its trigger marker/payload.

Accepted entering comparison:

- Bunny: independent oracle rejects first, followed by `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`;
- Vase: reaches `[ RUN ]` and is bounded at 60 seconds, safety-only.

M1e must not relabel either green merely to close the migration. Changed behavior requires exact evidence and classification.

## 13. Postflight immutability

After all runtime checks, require:

- original result ZIP SHA-256 exactly `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f`;
- original log ZIP SHA-256 exactly `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52`;
- manifest SHA exactly `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e`;
- all **61/61** packaged checksums pass;
- producer/oracle/authority/validation executable content hashes unchanged;
- exactly 62 regular package files remain; runtime-only symlinks are non-regular and recorded separately.

## 14. Acceptance and regression disposition

Accept M1e only if all required-green gates above pass and the package remains immutable.

On acceptance:

- `RP-01`: accept checked source-vertex/interior-transition domain use at ordered segment-route transport;
- `RP-05`: accept semantic route step identity and observed-vs-canonical orientation boundary;
- `RP-07`: accept typed cumulative quarter-turn/grid-automorphism composition at `segment_on_source`;
- `RP-02 / TA-05`: mark independent authority preserved through exact 184 accounting and M1d/M1c/M1b/M1a/T1/direct evidence;
- retain historical totals unless a genuine restored-then-lost authority is proven;
- leave `PR8-R034 / G4-R007` separate and active unless direct product evidence independently changes it.

If any required-green gate fails, remain at M1e and create a bounded corrective Code + Build plan. Do not advance to periodic-holonomy transport, `FieldChartId`, M2, or G4 remediation.

## 15. Mandatory checked-in evidence cleanup

At the **start** of this Test + Benchmark turn, apply the durable cleanup policy in `Future_Chat_Session_Handoff.md`: remove stale previous checked-in evidence after ensuring accepted facts are represented in durable/live authority.

At **closeout**, retain only:

- durable `.agents/Directional` documents;
- the new authoritative M1e Test + Benchmark report;
- exactly one following Code + Build plan.

Remove the consumed M1e TB plan, superseded M1e Code + Build report/plan, and any stale per-turn evidence after its necessary facts are folded into live/durable authority.