# M1e Segment Route Transport Consumer — Artifact-Only Test + Benchmark Plan

**Status:** authoritative next turn  
**Turn type:** immutable Test + Benchmark only  
**Review policy:** `never`  
**Source/test/build mutation:** prohibited

## 1. Objective

Validate the exact compiled M1e package without rebuilding, relinking, regenerating, editing, repairing, or substituting any source, test, fixture, executable, library, or regular package content.

M1e selected consumer:
`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`.

The immutable turn must establish that the typed ordered route transport is behaviorally correct and preserves accepted M1d/M1c/M1b/M1a/T1/direct authority. Compile success alone is not semantic acceptance.

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

The first compile-red commit `9edbef1fe34d60d2a507160aa4a27883cea36903` is not runtime authority. The immutable implementation is `bb9cb63...` only.

## 3. Immutable preflight

Before executing any packaged Directional binary:

1. download artifact `9047295489` specifically from build run `31345475101` and log artifact `9047295703`;
2. verify GitHub artifact/run identity, expiration and API digest;
3. verify downloaded ZIP hashes exactly;
4. reject absolute paths, `..` traversal, unsafe members and substitution;
5. extract into a fresh arbitrary directory;
6. verify `SHA256SUMS` digest `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e` and all **61/61** entries;
7. require exactly 62 regular files, seven executables, two static libraries and 27 fixtures;
8. verify build authority identifies `bb9cb63...`, event `106e408...`, run `31345475101`, Release/static/Ninja, PRE_TEST and `runtimeExecution=false`;
9. verify every runtime/test/discovery/benchmark/ctest/CLI/fuzzer/custom-input boundary flag remains false;
10. verify source patch/archive and source blobs;
11. verify executable hashes before restoring executable permission if extraction stripped modes;
12. only after content verification may a runtime-only non-regular fixture symlink be created if required.

Expected hashes: producer `0a8e67953e7221daf0fe607794c3b69f2e3fb8331b91ab08a02c10d52152943e`; oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`; authority `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`; validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`.

## 4. Native discovery authority

Use native packaged GoogleTest discovery. Zero selection is invalid.

Require:

- producer exactly **184 unique tests**;
- validation exactly **77**;
- M1a authority kernel exactly **14**;
- T1 oracle exactly **29**.

M1e must discover exactly six:

1. `SurfaceCellSegmentRouteTransportAuthorityMigration.MultiStepVertexFanComposesTypedRouteTransport`;
2. `.ReverseObservedRouteUsesExactTransportInverse`;
3. `.EquivalentSignedQuarterTurnsComposeSemantically`;
4. `.RouteTopologyAndCompactTransitionProvenanceRemainUnchanged`;
5. `.MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`;
6. `.LegacyMatchingFallbackUsesSameTypedRouteComposition`.

Static M1e manifest SHA-256 remains `b6a1c9035b2cd15a13844f812e7261ee0e199e72d0150d9a093a59d1ce713556`.

## 5. M1e focused semantic execution

Run each M1e test in a fresh process, exactly one selected test per invocation. Require **6/6** pass with rc=0.

Intent is strict:

- multi-step must prove a real multi-crossing production route and semantic composition;
- reverse must find a genuine reciprocal observed route and exact quarter-turn inverse;
- equivalent signed quarter-turns must prove `+4` representation changes preserve semantics;
- provenance must preserve exact existing ordered packed topology and compact transition IDs;
- malformed authoritative metadata must fail closed without fallback/recovery/synthetic output;
- `edgeTransitions`-absent legacy matching must preserve equivalent observable route behavior through typed composition.

If a fixture does not establish its precondition, do not weaken/reinterpret the test in this immutable turn; return to corrective Code + Build.

## 6. Preservation matrix

Require existing ordered vertex-fan witnesses **2/2**:

- `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`;
- `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`.

Require M1d exact six **6/6** plus:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

Require M1c exact six **6/6** plus:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

Require M1b exact six **6/6** + full validation **77/77**; M1a **14/14**; T1 **29/29**.

## 7. Complete producer accounting

Producer discovery target is exactly **184**:

- required-green segment **169**, require **169/169**;
- direct required-green cases **4** separately;
- historical/deferred known-red tests **9** individually classified;
- BunnyRandom **1**;
- Vase **1**.

The required-green aggregate excludes only those 4 direct, 9 declared reds, Bunny and Vase. It may not silently exclude newly red M1e/preservation tests.

The nine historical/deferred reds remain the existing transition-quotient multi-isolation/full-periodic/relation-owner/lineage cases plus `StrictValidatorOverheadStaysBelowFivePercent` and exact committed torus `InvalidHardRailPairing`. Persistence of their existing class is not a new recurrence; any materially changed failure must be classified.

## 8. Direct product preservation

Run Plane, MultiFaceSeam, CloseSheets and Cylinder individually. Each must select exactly one, rc=0, remain direct `SurfaceCells` with no fallback/recovery and remain independent-oracle clean. Record elapsed/RSS diagnostically only.

## 9. Bunny/Vase comparison

Use exact existing direct cases from artifact `9047295489`. Artifact-only Actions is authorized if needed.

Any temporary workflow must download exact artifact `9047295489` from run `31345475101`, verify GitHub/ZIP/build/61-checksum/62-file/producer authority before runtime, rebuild/edit nothing, restore executable mode only after hash verification, retain exact raw runtime evidence, reverify postflight, and remove/disable the workflow **before** deleting its trigger marker/payload.

Accepted entering comparison: Bunny independent oracle rejects first, followed by `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`; Vase reaches `[ RUN ]` and is bounded at 60 seconds, safety-only. Do not relabel either green merely to close M1e.

## 10. Postflight

Require original result ZIP `74e5a1abe37d14c5cdf8a13b753b3f70b80b6a61d83ec051d3b8e4d44b8b8e9f`, log ZIP `9df806949994145dba689b58afcc49106cedd1aadafbff409d70705188400f52`, manifest `ae82db8c02575926fe28ede2cbd6a4738cf7ed4e7ae1576ce8778970c532bc8e`, all **61/61** checksums, unchanged executable hashes and exactly 62 regular package files.

## 11. Acceptance/regression disposition

Accept M1e only if all required-green gates pass and package immutability remains exact.

On acceptance:

- `RP-01`: accept checked step domains at ordered route transport;
- `RP-05`: accept semantic step identity and observed/canonical orientation boundary;
- `RP-07`: accept typed cumulative route composition at `segment_on_source`;
- `RP-02 / TA-05`: preserve independent authority through exact 184 accounting and M1d/M1c/M1b/M1a/T1/direct evidence;
- leave historical totals unchanged unless a genuine restored-then-lost authority is proven;
- leave `PR8-R034 / G4-R007` separate unless direct product evidence changes it independently.

Any required-green failure remains at M1e and returns to corrective Code + Build. Do not advance to another M1 consumer, M2 or G4 remediation.

## 12. Mandatory checked-in evidence cleanup

At Test + Benchmark start, apply the durable handoff cleanup policy. At closeout retain only durable `.agents/Directional` documents, the new M1e TB report, and exactly one following Code + Build plan. Remove the consumed M1e TB plan and superseded M1e Code + Build evidence only after necessary facts are folded into durable/live authority.
