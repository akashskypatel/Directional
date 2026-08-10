# M1e Segment Route Transport Consumer — Artifact-Only Test + Benchmark Plan

**Status:** authoritative next turn
**Turn type:** immutable Test + Benchmark only
**Review policy:** `never`
**Source/test/build mutation:** prohibited

## 1. Objective

Validate the exact compiled M1e package without rebuilding, relinking, regenerating, editing, repairing, or substituting any source, test, fixture, executable, library, or regular package content.

M1e selected consumer:

`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`

The immutable turn must establish that the typed route transport is behaviorally correct and preserves accepted M1d/M1c/M1b/M1a/T1/direct product authority. Compile success alone is not semantic acceptance.

## 2. Exact immutable build authority

Consume only:

| Evidence | Value |
|---|---|
| M1e base | `5df33fc11deaac697cb886d8defcaba622ec436f` |
| Final M1e implementation | `a0330d0107f7d7340e9f8644d26dd6c8b753ff10` |
| Build/event commit | `34036600128262e909c377006a056a2b9976f986` |
| Build run/job | `31351113129 / 93341993183` |
| Result artifact | `9049125645` |
| Result ZIP SHA-256 | `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7` |
| Log artifact | `9049125905` |
| Log ZIP SHA-256 | `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be` |
| Recursive manifest | **61/61**, `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5` |
| Package | **62** regular files including manifest; 7 executables; 2 static libs; 27 fixtures |
| Runtime in Code + Build | **false** |
| Retention | through `2026-08-24 03:04 UTC` |

The packaged production blob `34372a48412213d3b4db6d0bc3e653e7d3225ef0` is exact; the packaged rewritten test blob is `f55d016db2c89710b79c711a0d5e780dcfb2bdfc`.

## 3. Immutable preflight

Before executing any packaged Directional binary:

1. download artifact `9049125645` specifically from build run `31351113129` and log artifact `9049125905`;
2. verify GitHub artifact ID, run ID, event commit, expiration state, and API digest;
3. verify downloaded ZIP SHA-256 values exactly;
4. reject absolute paths, `..` traversal, unsafe archive members, and unexpected archive substitution;
5. extract into a fresh arbitrary directory;
6. verify `SHA256SUMS` digest exactly `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5` and every **61/61** entry;
7. require exactly 62 regular package files, seven packaged executables, two static libraries, and 27 fixtures;
8. verify `metadata/build-authority.json` identifies implementation `a0330d0...`, event `3403660...`, run `31351113129`, Release/static/Ninja, PRE_TEST, and `runtimeExecution=false`;
9. verify every `metadata/command-boundary.txt` runtime/test/discovery/benchmark/ctest/CLI/fuzzer/custom-input flag remains false;
10. verify source patch/archive, source blobs, static manifests, and compile database;
11. verify executable content hashes before restoring executable permission if artifact extraction stripped mode bits;
12. only after content verification, create a runtime-only non-regular fixture locator symlink if packaged tests require `bin/test-data -> ../test-data`; record it separately and never count it as packaged regular content.

Expected executable SHA-256:

- producer `5e2e85ede99f50b82aba70ce0a829a59b5c74bb42585845f681d80e578402259`;
- oracle `6cc9e1f7a6e767e42bec0ab3fe54eee0c29d9381b4ea63fb716be3eb9f7dea90`;
- authority kernel `bb2bac416a809c7b286d574da800f1bdf471b7093f2e5d81dbbe434f1a799c71`;
- validation `ccbda0c7d5525c7a9d8a20d0696da40884ca95800e7ac7cb6dbb4befcced00e6`;
- completion `97a1b99948bc5b76521be2501d2573f75cf958f44aa9918a02dfcd8180619acd`;
- compiled API `84c1bc634770715f095c64d6c749b0ffa46e024af3656d5f0fc3c43982fbc7de`;
- benchmark `6490b7c39c2b58d2ab44ba2b258167b93dccf53dd1f7e8160cc626861c69f42e`.

## 4. Native discovery authority

Use native packaged GoogleTest discovery once for each required executable. Zero selection is invalid.

Require:

- producer exactly **184 unique tests**;
- validation exactly **77**;
- M1a authority kernel exactly **14**;
- T1 oracle exactly **29**.

The M1e suite must discover exactly the six statically packaged names, with no extra or missing member:

1. `SurfaceCellSegmentRouteTransportAuthorityMigration.MultiStepVertexFanComposesTypedRouteTransport`;
2. `.ReverseObservedRouteUsesExactTransportInverse`;
3. `.EquivalentSignedQuarterTurnsComposeSemantically`;
4. `.RouteTopologyAndCompactTransitionProvenanceRemainUnchanged`;
5. `.MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`;
6. `.LegacyMatchingFallbackUsesSameTypedRouteComposition`.

Static M1e manifest SHA-256 must remain `b6a1c9035b2cd15a13844f812e7261ee0e199e72d0150d9a093a59d1ce713556`.

## 5. M1e focused semantic execution

Run each M1e test in a **fresh process**, exactly one selected test per invocation. Require **6/6** pass with rc=0.

Interpret intent strictly and against independent fixture facts:

1. `MultiStepVertexFanComposesTypedRouteTransport`
   - must execute the predetermined production route `2 -> 3 -> 10` through source vertex `7` and topology `(1,7) -> (6,7)`;
   - must observe both nonzero directed step turns `3` and `2`;
   - final expected matching is the hard-authored endpoint-label oracle `1`, not a value recomputed by calling or duplicating production route composition.

2. `ReverseObservedRouteUsesExactTransportInverse`
   - must execute the exact predetermined reverse `10 -> 3 -> 2` with reversed topology;
   - forward must be `1`, reverse must be `3`, and their quarter-turn sum must be identity;
   - reciprocal evidence must be route-keyed, not inferred from positional output pairing or raw sign convention.

3. `EquivalentSignedQuarterTurnsComposeSemantically`
   - must change one raw transition by `+4` and the other by `-4` while retaining their semantic rotations;
   - must compare sorted semantic snapshots keyed by faces plus ordered route topology/provenance and preserve forward matching `1`;
   - positional vector equality without semantic keys is not acceptance authority.

4. `RouteTopologyAndCompactTransitionProvenanceRemainUnchanged`
   - must require exact forward topology `[(1,7),(6,7)]` and reverse topology in reverse order;
   - must require independently lexicographically enumerated compact IDs forward `[2,9]` and reverse `[9,2]`, with terminal compact provenance `9` and `2` respectively;
   - expected compact IDs must not come from production `edge_matching_indices` or the observed output itself.

5. `MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`
   - must first prove the baseline exact multi-step route is produced;
   - must corrupt the nonnegative `sourceEdge` sentinel on predetermined route edge `(6,7)` and reach the real `segment_on_source` vertex-fan seam;
   - must reject as `MissingTransitionProvenance` with concrete cell/side, source vertex `7`, faces `3 <-> 10`, and no cells/seeds/traces/proposals;
   - this is the review-authorized predecessor provenance boundary. Do not reinterpret it as a typed-constructor failure or promote `CrossFieldEdgeTransition::sourceEdge` to semantic `InteriorTransitionId`.

6. `LegacyMatchingFallbackUsesSameTypedRouteComposition`
   - must construct the compact legacy matching vector independently from all 29 fixture interior edges with `edgeTransitions` absent;
   - must require compact entries `2 -> 3` and `9 -> 2`, compare route-keyed semantic snapshots, and retain forward/reverse matchings `1/3`;
   - the existing legacy metadata path is preserved, but transport still crosses the typed production composition boundary.

Tests must call the real production entry point. A helper that reimplements route composition or obtains the expected answer from production output is not independent proof. If any fixture fails its intended precondition, do not weaken, reorder, or reinterpret it in this immutable turn; retain exact evidence and return to corrective M1e Code + Build.

## 6. Existing M1e route witnesses

Run individually and require green:

- `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`;
- `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`.

These are preservation witnesses only and cannot substitute for the six focused semantic contracts.

## 7. M1d preservation

Require exact M1d focused suite membership six and **6/6** individually:

`SurfaceCellPhaseFrontRouteAuthorityMigration.*`

Also run and require green:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

## 8. M1c preservation

Require exact M1c focused suite six and **6/6** individually:

`SurfaceCellFieldTransitionAuthorityMigration.*`

Also require these three existing counterexamples green:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

## 9. Complete producer accounting

Producer discovery target is exactly **184**.

Expected complete accounting:

- required-green producer segment: exactly **169**, require **169/169** pass;
- direct required-green cases run separately: four;
- historical/deferred known-red tests: nine, each executed individually and explicitly classified;
- BunnyRandom: one;
- Vase: one;
- total: `169 + 4 + 9 + 1 + 1 = 184`.

The required-green aggregate must exclude only the four separately run direct product tests, nine declared historical/deferred reds, BunnyRandom, and Vase. It must not silently exclude a newly red M1e or preservation test.

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

Persistence of an existing accepted failure class is not a new recurrence. Any materially changed failure or newly red required-green test must be investigated and classified.

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

Each must select exactly one test, return rc=0, remain direct `SurfaceCells` output without fallback/recovery, and remain independent-product-oracle clean. Record elapsed time and peak RSS as diagnostics, not new performance thresholds.

## 12. Bunny/Vase comparison

Use the exact existing direct product tests from artifact `9049125645`.

Long-runtime artifact-only GitHub Actions remains authorized if local execution is impractical. Any temporary runtime workflow must:

1. download exact artifact `9049125645` from build run `31351113129`;
2. verify GitHub digest, outer ZIP SHA, build authority, all **61/61** checksums, 62 regular files, and producer hash before runtime;
3. configure/build/relink/regenerate/edit nothing;
4. restore executable permission only after hash verification;
5. run exactly one requested case under an explicit guard;
6. retain selected count/filter/stdout/stderr/rc/time/resource/postflight evidence;
7. reverify artifact, manifest, producer, and regular-file count afterward;
8. remove or disable the temporary workflow **before** deleting its trigger marker/payload.

Accepted entering comparison:

- Bunny: independent oracle rejects first, followed by `NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`;
- Vase: reaches `[ RUN ]` and is bounded at 60 seconds, safety-only.

M1e must not relabel either green merely to close the migration. Changed behavior requires exact evidence and classification.

## 13. Postflight immutability

After all runtime checks, require:

- original result ZIP SHA-256 exactly `d16222c62f6f7491eaa830fe22ac4f768b6f426646639f155ccfd8feb9d378f7`;
- original log ZIP SHA-256 exactly `fd1d816fd4265f803f6be278941eb7647d056eb6336d05fe98e865621fd5e7be`;
- manifest SHA exactly `36a6377350aa4b58205ccd881a7ee34156800d28e3c5edecf634769289d9e7e5`;
- all **61/61** packaged checksums pass;
- producer/oracle/authority/validation executable hashes remain unchanged;
- exactly 62 regular package files remain; runtime-only symlinks are non-regular and recorded separately.

## 14. Acceptance and regression disposition

Accept M1e only if all required-green gates pass and the package remains immutable.

On acceptance:

- `RP-01`: accept checked source-vertex/interior-transition domain use at ordered segment-route transport;
- `RP-05`: accept semantic route-step identity and observed-vs-canonical orientation boundary;
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

Remove the consumed M1e Test + Benchmark plan, superseded M1e Code + Build report/plan, and stale M1d per-turn evidence only after their necessary facts are folded into live/durable authority.
