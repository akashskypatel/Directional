# M1k Phase-Front Edge Topology-Region Consumer — Artifact-Only Test + Benchmark Plan

**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Implementation under test:** `b9181364926cea840e9cb50da21fe721f33fd874`  
**Prerequisite:** M1k Code + Build compile/package complete; M1j immutable accepted  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

Determine whether the bounded M1k topology-region authority migration is semantically acceptable from the exact immutable Code + Build package. This turn must not modify implementation, tests, fixtures, build logic, validators, benchmarks, or packaged content.

M1k seam:

`SurfaceTopologyRegion::id / normalize_scope -> SurfaceFrontEdge::sourceTopologyRegion -> still-raw pipeline compatibility consumers`

The semantic question is whether persistent front sides now retain checked `TopologyRegionId` authority established by authoritative region membership, remain distinct from source component/isolation-sheet/field-chart integer domains, fail closed when required authority is missing or inconsistent, and cross still-raw pipeline boundaries only through the named compatibility conversion without changing accepted product behavior.

## 2. Immutable input authority

Consume **only**:

| Evidence | Value |
|---|---|
| implementation | `b9181364926cea840e9cb50da21fe721f33fd874` |
| source parent | `38d6fc4c4042c5a0d200abf4e5594dcf325b8383` |
| accepted M1j implementation | `d5f681173600dc32dc7617de6105d9e584e593be` |
| successful build run/job | `31430898273 / 93593780187` |
| result artifact | `9079318682` — `m1k-edge-topology-region-code-build-result-final` |
| result ZIP SHA-256 | `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d` |
| log artifact | `9079319269` — `m1k-edge-topology-region-code-build-logs-authoritative` |
| log ZIP SHA-256 | `1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381` |
| recursive manifest | **68/68**, SHA-256 `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c` |
| package cardinality | **69** regular files including `SHA256SUMS`; 7 executables; 2 libraries; 27 fixtures |
| producer SHA-256 | `3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1` |

All earlier M1k build/package attempts are compile/orchestration provenance only and must not be substituted for the exact package above.

## 3. Prohibited actions

This Test + Benchmark turn must not:

- configure CMake, compile, or relink;
- regenerate GoogleTest metadata or any build product;
- edit source, headers, tests, benchmarks, validators, fixtures, CMake, package metadata, or manifests;
- replace, patch, repair, copy over, or repackage any executable/library/fixture/package path;
- synthesize expected output;
- create `bin/test-data`, another fixture symlink, or any path substitute to make the immutable package execute;
- weaken, skip, relabel, or retry a failing semantic contract to make the turn green;
- substitute a superseded M1k package or an M1j artifact for M1k runtime authority.

If the exact package cannot execute from a fresh arbitrary extraction directory, classify an immutable-package/portability failure and stop rather than repairing it.

## 4. Immutable preflight

Extract result and log artifacts to fresh arbitrary directories. Before executing a packaged binary:

1. verify result ZIP SHA-256 exactly `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d`;
2. verify log ZIP SHA-256 exactly `1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381`;
3. reject absolute or `..` archive members and require zero package symlinks;
4. verify `SHA256SUMS` SHA-256 exactly `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c`;
5. verify every **68/68** manifest entry and require exactly **69** regular files including `SHA256SUMS`;
6. verify exactly seven packaged executables, two static libraries, and 27 fixture files, including 21 files under `test-data/benchmarks/fixtures/milestone-g`;
7. verify `metadata/build-authority.json` identifies implementation `b9181364926cea840e9cb50da21fe721f33fd874`, source parent `38d6fc4c4042c5a0d200abf4e5594dcf325b8383`, accepted M1j `d5f681173600dc32dc7617de6105d9e584e593be`, run `31430898273`, Release/static/Ninja/PRE_TEST, and every runtime/test/benchmark/discovery/ctest/CLI/fuzzer/custom-input flag false;
8. verify producer hash exactly `3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1`;
9. verify packaged source blobs:
   - tracing header `f4d228fa815925d6ff361dd4093d24fb8d14c732`;
   - tracing implementation `56cb32248c1173b8acd5b7660885c468a3919f72`;
   - pipeline `a10808a9d267e664ea6484f9064ffb5b0972b6d3`;
   - phase-10 tests `a524a39ce21740442c904490952b9f7c41c0cf23`;
   - fixture paths `4a981f772ee70780d0011696010a0e1b8bef6972`;
10. verify the packaged name manifests and exact direct-product/deferred parameterized names are present and checksum-valid;
11. verify no runtime repair path or fixture symlink exists.

Any mismatch is an infrastructure/immutable-artifact failure. Do not continue into semantic classification.

## 5. Native discovery authority

After preflight, use only native packaged GoogleTest `--gtest_list_tests` support.

Expected exact discovery:

| Target | Expected |
|---|---:|
| producer | **220** |
| validation | **77** |
| M1a authority kernel | **14** |
| T1 independent oracle | **29** |

Producer expectation is accepted M1j discovery 214 plus exactly six M1k focused contracts. Missing/duplicate names, unexpected counts, or zero-selected filters block acceptance; do not substitute source parsing.

## 6. M1k focused acceptance — six fresh processes

Run every M1k contract individually in a fresh process; each invocation must select exactly one test and pass:

1. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.PlanarEdgesPublishCheckedTopologyRegionZero`
2. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.DistinctTopologyRegionsRemainDistinctFromIsolationSheets`
3. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.MissingOrInvalidEdgeTopologyRegionFailsClosed`
4. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.FaceRowPermutationPreservesTypedEdgeTopologyRegion`
5. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.CrossRegionOppositesRetainDistinctTypedRegionIdentity`
6. `SurfaceCellPhaseFrontEdgeTopologyRegionAuthorityMigration.TypedEdgeTopologyRegionToLegacyPipelineBoundaryPreservesCompatibility`

Required: **6/6**.

Interpret red results against the contract rather than implementation convenience. In particular:

- topology-region identity must derive from authoritative region ownership, not source component/sheet/chart identity or equal integer values;
- missing/stale/inconsistent region authority must fail closed through the existing authoritative materializer;
- face-row permutation must preserve semantic topology-region ownership rather than positional edge IDs;
- cross-region hard-rail counterparts must retain distinct checked region identities where production permits the relationship;
- raw compatibility consumers must derive their raw value from the typed edge authority.

## 7. Entering M1 preservation

Run every retained focused migration contract individually from the packaged name manifests:

- M1j edge source-scope authority: **6/6**;
- M1i cell source-scope authority: **6/6**;
- M1h field-chart authority: **6/6**;
- M1g periodic holonomy route transport: **6/6**;
- M1f vertex-continuation route transport: **6/6**;
- M1e segment route transport: **6/6**;
- M1d phase-front route identity: **6/6**;
- M1c field-transition authority: **6/6**;
- M1b source/provenance consumer: **6/6**.

**M1b names belong to the validation executable.** A producer filter selecting zero M1b tests is an orchestration error, never a semantic pass.

Also run accepted counterexamples individually:

M1d route witnesses — **3/3**:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

M1c transition counterexamples — **3/3**:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

Any newly red accepted contract blocks M1k acceptance until classified from exact evidence.

## 8. Complete required-green producer segment

From producer discovery **220**, exclude exactly 15 separately classified tests:

- four direct representative products;
- eight historical/deferred reds;
- `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- BunnyRandom;
- Vase.

Expected required-green selection:

`220 - 15 = 205`.

Require selected exactly **205**, passed **205/205**, rc=0. GoogleTest aggregate filter syntax must use exactly one positive/negative separator. If selection count differs, stop and reconcile discovery/exclusion authority rather than modifying the filter opportunistically.

## 9. Independent preservation targets

Run exact packaged targets:

- validation: **77/77**;
- M1a authority kernel: **14/14**;
- T1 independent product oracle: **29/29**.

No binary may be rebuilt or replaced.

## 10. Direct representative product preservation

Run each exact packaged product individually in a fresh process:

- `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Plane`;
- `.../MultiFaceSeam`;
- `.../CloseSheets`;
- `.../Cylinder`.

Each must select one case, report product success, pass the independent oracle, resolve packaged sibling `../test-data` naturally, and use no fixture symlink or runtime repair.

## 11. Historical/deferred red classification

Run every entering red individually and require its existing class to remain recognizable:

1. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red.
2. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`.
3. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`.
4. `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`.
5. `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`.
6. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`.
7. `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red.
8. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — `NotProductionReady:tracing ... InvalidHardRailPairing`.

Persistence is not a new regression. A materially different terminal class, earlier invariant failure, crash, or hang is a regression candidate requiring exact evidence-based classification. Nonzero periodic whole-cycle rotation remains outside M1k and `G4-B003` stays unresolved.

## 12. Strict-validator timing characterization

Run `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` in **10 independent fresh processes**. Record pass/fail, measured validation time, threshold/reference value, process wall time, and peak RSS where practical.

Do not retry for greening or weaken the threshold. Entering M1j characterization is **0/10 pass** and remains the known deferred sub-millisecond ratio/microbenchmark defect unless fresh evidence proves a different root cause.

## 13. Bunny and Vase bounded comparison

If all earlier mandatory gates permit continuing, run the exact parameterized package tests with bounded artifact-only execution:

### Bunny

`UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/BunnyRandom`

Expected entering comparison:

`NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`

with independent-oracle failure reported before the fatal product-success assertion. A different failure class/order/signature is material.

### Vase

`UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`

Use a 60-second safety bound. Reaching `[ RUN ]` and timing out with rc=124 is safety-only evidence; do not infer correctness or nontermination from the timeout.

A temporary narrowly scoped Actions workflow is allowed only as an execution plane when local bounds require it. It must consume the exact declared result artifact, perform exact preflight/postflight, and never configure/build/relink/regenerate/repair/substitute package content.

## 14. Exact postflight

After all runtime commands independently reverify:

- result ZIP SHA-256 `90b8deea85c12460ae45b66d0c7aa67fa3771074b60841fd1a0e586b0088869d`;
- log ZIP SHA-256 `1a9a06fe42e2329cff1ff9d5b4eba0b7986af47d855229119e6d76bc2f07e381`;
- manifest digest `0b76267ea2e40c5c417c0cade77e0b95d75fe1c27a6a2a94cc283f6c7660583c`;
- all **68/68** manifest entries;
- exactly 69 regular files including the manifest, seven executables, two libraries, 27 fixtures;
- producer hash `3218b439a038adff6834d6003289488a3fb266231d7f157151964ed58c3430d1`;
- zero package symlinks and no runtime repair/substitution.

Any mutation invalidates the runtime evidence.

## 15. Acceptance gate

M1k is immutable accepted only when all simultaneously hold:

1. exact immutable preflight;
2. discovery producer **220**, validation **77**, M1a **14**, T1 **29**;
3. M1k **6/6** individually;
4. M1j through M1b focused preservation fully green;
5. M1d route witnesses **3/3**, M1c transition counterexamples **3/3**;
6. required-green producer exactly **205/205**;
7. validation **77/77**, M1a **14/14**, T1 **29/29**;
8. Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink or repair;
9. all eight historical/deferred reds retain entering classes;
10. strict-validator timing truthfully characterized in 10 fresh processes;
11. Bunny/Vase bounded and truthfully classified if executed;
12. exact immutable postflight unchanged.

Compile success from the preceding turn is not semantic acceptance. If any newly red accepted contract fails, stop M1k acceptance and classify it from exact evidence; do not edit source/test/build/package logic in this turn.

## 16. Closeout

If M1k passes, write one authoritative immutable runtime report, update durable status non-destructively, inspect the newly accepted source only then to choose exactly one next bounded consumer, create exactly one next Code + Build plan, remove temporary runtime state, update PR #8, and make exactly one new top-level PR closeout comment as the final repository/PR write.

If M1k fails, write a truthful blocked report, classify product versus test-authority/package/infrastructure failure, select only the bounded remediation authorized by that evidence, perform the same temporary-state cleanup, and make the single final closeout comment.
