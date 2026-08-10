# M1j Phase-Front Edge Source-Scope Consumer — Artifact-Only Test + Benchmark Plan

**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Implementation under test:** `d5f681173600dc32dc7617de6105d9e584e593be`  
**Prerequisite:** M1j Code + Build compile/package complete; M1i immutable accepted  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

Determine whether the bounded M1j migration is semantically acceptable from the exact immutable Code + Build package. This turn must not modify implementation, tests, fixtures, build logic, validators, benchmarks, or packaged content.

M1j seam:

`SurfacePhaseFrontCell typed source scope -> SurfaceFrontEdge::{sourceComponent, sourceSheet, sourceIsolationSheets}`

The semantic question is whether persistent front sides now retain checked `SourceComponentId` / `IsolationSheetId` authority inherited from their owning cells, including multi-sheet no-representative semantics, without changing accepted product behavior or introducing consumer-side authority reconstruction.

## 2. Immutable input authority

Consume **only**:

| Evidence | Value |
|---|---|
| implementation | `d5f681173600dc32dc7617de6105d9e584e593be` |
| source parent | `391271e253557b5c6b267befb3f2f33330c090c9` |
| successful build run/job | `31422691741 / 93566993166` |
| result artifact | `9076217893` — `m1j-edge-source-scope-code-build-result-final` |
| result ZIP SHA-256 | `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c` |
| log artifact | `9076218338` — `m1j-edge-source-scope-code-build-logs-authoritative` |
| log ZIP SHA-256 | `76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9` |
| recursive manifest | **67/67**, SHA-256 `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59` |
| package cardinality | **68** regular files, 7 executables, 2 libraries, 27 fixtures |
| producer SHA-256 | `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40` |

The earlier build artifact `9075863759` is compile provenance only because one final package-log copy occurred after its manifest was generated. It must **not** be used or substituted for runtime. The authoritative package above rebuilds the same implementation and closes the manifest after all package writes.

## 3. Prohibited actions

This Test + Benchmark turn must not:

- configure CMake, compile, or relink;
- regenerate GoogleTest metadata or any build product;
- edit source, headers, tests, benchmarks, validators, fixtures, CMake, package metadata, or manifests;
- replace or repair any executable/library/fixture/package path;
- synthesize expected output;
- create `bin/test-data` or another runtime fixture symlink;
- weaken, skip, relabel, or retry a failing semantic contract to make the turn green;
- substitute the earlier incomplete-manifest artifact for the declared package.

If the exact package cannot execute from an arbitrary extraction directory, classify an immutable-package/portability failure and stop rather than repairing it.

## 4. Immutable preflight

Extract each artifact to fresh arbitrary directories. Before executing a packaged binary:

1. verify result ZIP SHA-256 exactly `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c`;
2. verify log ZIP SHA-256 exactly `76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9`;
3. reject absolute or `..` archive members;
4. verify `SHA256SUMS` SHA-256 exactly `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`;
5. verify every **67/67** manifest entry and require exactly 68 regular files including `SHA256SUMS`;
6. verify exactly 7 packaged executables, 2 static libraries, and 27 fixture files;
7. verify `metadata/build-authority.json` identifies implementation `d5f681173600dc32dc7617de6105d9e584e593be`, source parent `391271e253557b5c6b267befb3f2f33330c090c9`, run `31422691741`, Release/static/Ninja/PRE_TEST, and every runtime/test/benchmark/ctest/CLI/fuzzer/custom-input flag false;
8. verify producer hash exactly `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40`;
9. verify packaged source blobs:
   - tracing header `9098daea41e3ca3f75eca4a1683d5c4674c97319`;
   - tracing implementation `5d5404a98caf69abb962d477dde2f0e2b68aebf0`;
   - pipeline `8761e60166f5c1711a4f8ee15f54c864a55497bb`;
   - phase-10 tests `512edcb333f1f9770cc980d335cbb060a24e36dc`;
   - fixture paths `4a981f772ee70780d0011696010a0e1b8bef6972`;
10. verify no package symlink and no `bin/test-data` substitute exists.

Any mismatch is an infrastructure/immutable-artifact failure. Do not continue into semantic classification.

## 5. Native discovery authority

After preflight, use only native packaged GoogleTest `--gtest_list_tests` support.

Expected exact discovery:

| Target | Expected |
|---|---:|
| producer | **214** |
| validation | **77** |
| M1a authority kernel | **14** |
| T1 independent oracle | **29** |

Producer expectation is accepted M1i discovery 208 plus exactly six M1j focused contracts. Missing/duplicate names, unexpected counts, or zero-selected filters block acceptance; do not substitute source parsing.

## 6. M1j focused acceptance — six fresh processes

Run every M1j contract individually in a fresh process; each invocation must select exactly one test and pass:

1. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.PlanarEdgesPublishCheckedDefaultComponentAndSheet`
2. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.ExplicitSourceLabelsRemainDistinctTypedEdgeDomains`
3. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.MultipleObservedSheetsDoNotInventRepresentativeEdgeSheet`
4. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.MalformedOrMismatchedEdgeScopeFailsClosed`
5. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.FaceRowPermutationPreservesTypedEdgeSourceScope`
6. `SurfaceCellPhaseFrontEdgeSourceScopeAuthorityMigration.TypedEdgeToLegacyPipelineBoundaryPreservesCompatibility`

Required: **6/6**. Do not replace individual-process evidence with an aggregate suite pass.

Interpret red results against the contract rather than implementation convenience. In particular, multi-sheet authority must retain every observed sheet while leaving the optional single-sheet identity empty; face-row permutation must preserve semantic scope rather than positional edge IDs; malformed enabled source labels must fail closed rather than publish partially scoped edges.

## 7. Entering M1 preservation

Run every retained focused migration contract individually from the packaged name manifests:

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

Any newly red accepted contract blocks M1j acceptance until classified from exact evidence.

## 8. Complete required-green producer segment

From producer discovery **214**, exclude exactly 15 separately classified tests:

- four direct representative products;
- eight historical/deferred reds;
- `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- BunnyRandom;
- Vase.

Expected required-green selection:

`214 - 15 = 199`.

Require selected exactly **199**, passed **199/199**, rc=0. GoogleTest aggregate filter syntax must use exactly one positive/negative separator: `positive-negative1:negative2:...`. If selection count differs, stop and reconcile discovery/exclusion authority rather than modifying the filter opportunistically.

## 9. Independent preservation targets

Run exact packaged targets:

- validation: **77/77**;
- M1a authority kernel: **14/14**;
- T1 independent product oracle: **29/29**.

No binary may be rebuilt or replaced.

## 10. Direct representative product preservation

Run each product individually in a fresh process:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder.

Each must select one case, report product success, pass the independent oracle, resolve packaged sibling `../test-data` naturally, and use `fixtureSymlink=false`.

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

Persistence is not a new regression. A materially different terminal class, earlier invariant failure, crash, or hang is a regression candidate requiring evidence-based classification. Nonzero periodic whole-cycle rotation remains outside M1j and is expected to remain `PeriodicHolonomyMismatch`; `G4-B003` stays unresolved.

## 12. Strict-validator timing characterization

Run `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` in **10 independent fresh processes**. Record pass/fail, measured validation time, threshold/reference value, process wall time, and peak RSS where practical.

Do not retry for greening. Entering M1i characterization is **0/10 pass** and remains a known deferred sub-millisecond ratio/microbenchmark defect unless fresh evidence proves a different root cause.

## 13. Bunny and Vase bounded comparison

If all earlier mandatory gates permit continuing, run exact package BunnyRandom and Vase with bounded artifact-only execution. A temporary narrowly scoped Actions workflow is allowed only as an execution plane; it must download/use the exact declared result artifact, perform exact preflight/postflight, and never configure/build/relink/regenerate/repair/substitute package content.

### Bunny

Expected entering comparison:

`NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`

with independent-oracle failure reported before the fatal product-success assertion. A different failure class/order/signature is material.

### Vase

Use a 60-second safety bound. Reaching `[ RUN ]` and timing out with rc=124 is safety-only evidence; do not infer correctness or nontermination from the timeout.

Heavy jobs must retain `fixtureSymlink=false` and exact immutable package authority before and after runtime.

## 14. Exact postflight

After all runtime commands independently reverify:

- result ZIP SHA-256 `a428735f68793e7f4721094b11400c6b4d1276dbea4e6eeb1496fd0ce13f178c`;
- log ZIP SHA-256 `76684f4ac412f4da7fd1ccf3cbee5fddfbb7dd14efd43940c6a7568b3d22d1f9`;
- manifest digest `2134a0102a38b75d16c859be8fd862ab037c312609ab9bbae19499c9f875da59`;
- all **67/67** manifest entries;
- exactly 68 regular files including the manifest, 7 executables, 2 libraries, 27 fixtures;
- producer hash `04d5d4d59c3e7e9d15cc3e57b0887086939735867aeb1a122a4b3b82be826e40`;
- zero package symlinks and no runtime repair.

Any mutation invalidates the runtime evidence.

## 15. Acceptance gate

M1j is immutable accepted only when all simultaneously hold:

1. exact immutable preflight;
2. discovery producer **214**, validation **77**, M1a **14**, T1 **29**;
3. M1j **6/6** individually;
4. M1i through M1b focused preservation fully green;
5. M1d route witnesses **3/3**, M1c transition counterexamples **3/3**;
6. required-green producer exactly **199/199**;
7. validation **77/77**, M1a **14/14**, T1 **29/29**;
8. Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean without fixture symlink;
9. all eight historical/deferred reds retain entering classes;
10. strict-validator timing truthfully characterized in 10 fresh processes;
11. Bunny/Vase bounded and truthfully classified if executed;
12. exact immutable postflight unchanged.

If any new or entering accepted contract fails, stop acceptance and classify it. Do not edit source/test/build/package logic in this turn.

## 16. Closeout

If M1j passes, write one authoritative immutable runtime report, update durable status non-destructively, inspect the newly accepted source only then to choose exactly one next bounded M1 consumer, create exactly one next Code + Build plan, remove temporary runtime state, update PR #8, and make exactly one new top-level PR closeout comment as the final repository/PR write.

If M1j fails, write a truthful blocked report, classify product versus test-authority/package/infrastructure failure, select only the bounded remediation authorized by that evidence, perform the same temporary-state cleanup, and make the single final closeout comment.
