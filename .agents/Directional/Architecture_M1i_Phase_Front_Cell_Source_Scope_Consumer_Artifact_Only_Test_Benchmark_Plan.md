# M1i Phase-Front Cell Source-Scope Consumer — Artifact-Only Test + Benchmark Plan

**Turn type:** Test + Benchmark only  
**Review policy:** `never`  
**Implementation under test:** `b037157921094604f1b0c17f9c8b7076c7604b3b`  
**Prerequisite:** M1i Code + Build compile/package complete; M1h immutable accepted  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

This turn determines whether the bounded M1i migration is semantically acceptable from the exact immutable Code + Build package. It does not permit implementation, test, fixture, build, validator, or benchmark edits.

M1i seam:

`phase_front_cell_source_scope -> SurfacePhaseFrontCell::{sourceComponent, sourceSheet, sourceIsolationSheets}`.

The semantic question is whether persistent constructive cells now carry checked `SourceComponentId` / `IsolationSheetId` authority without changing accepted product behavior, inventing representative sheets, weakening fail-closed source-label handling, or breaking downstream compatibility.

## 2. Immutable input authority

Consume **only**:

| Evidence | Value |
|---|---|
| implementation | `b037157921094604f1b0c17f9c8b7076c7604b3b` |
| source parent | `48614f383111c96fce1e69871b66199d94033d11` |
| successful build run/job | `31411770135 / 93531293415` |
| result artifact | `9072101943` — `m1i-cell-source-scope-code-build-result` |
| result ZIP SHA-256 | `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25` |
| log artifact | `9072102331` — `m1i-cell-source-scope-code-build-logs-r2` |
| log ZIP SHA-256 | `38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44` |
| recursive manifest | **72/72**, SHA-256 `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3` |
| package cardinality | **73** regular files, 7 executables, 2 libraries, 27 fixtures |
| producer SHA-256 | `51f8af77c71b7607889a2379910892027464517b557c713c34411469ee7c5a5d` |

The first packaging attempt `31410750675` is retained only as orchestration provenance. Its compile succeeded **120/120** but package checksum verification ran from the wrong working directory. It is **not** a runtime input and must not be substituted for the final package.

## 3. Prohibited actions

This Test + Benchmark turn must not:

- checkout a different implementation as runtime authority;
- configure CMake;
- compile or relink;
- regenerate GoogleTest metadata/build products;
- edit source, headers, tests, benchmarks, validators, fixtures, CMake, or packaged metadata;
- replace any packaged executable/library/fixture;
- repair package paths or manifests;
- synthesize expected output;
- create a `bin/test-data` or other runtime fixture symlink;
- weaken, skip, relabel, or retry a failing semantic contract to make the turn green.

If the exact package cannot execute correctly from an arbitrary extraction directory, classify that as package/portability failure and stop rather than repairing it.

## 4. Immutable preflight

Extract each artifact into a fresh arbitrary directory. Before executing any packaged binary:

1. verify result ZIP SHA-256 exactly `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25`;
2. verify log ZIP SHA-256 exactly `38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`;
3. reject absolute or `..` archive members;
4. verify `SHA256SUMS` SHA-256 exactly `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`;
5. verify every **72/72** manifest entry;
6. verify exactly 73 regular files, 7 executables, 2 libraries, 27 fixture files;
7. verify `metadata/build-authority.json` identifies implementation `b037157921094604f1b0c17f9c8b7076c7604b3b`, source parent `48614f383111c96fce1e69871b66199d94033d11`, run `31411770135`, Release/static/Ninja/PRE_TEST, and every runtime flag false;
8. verify producer hash exactly `51f8af77c71b7607889a2379910892027464517b557c713c34411469ee7c5a5d`;
9. verify the packaged compiled-source blob authority:
   - tracing header `4036b16a3dc7e20369a9cd65a4422c61be58afb4`;
   - tracing implementation `33a41e70e240f198eaa49184c3a87773986b84cb`;
   - pipeline `601d02b7560e489246e30e1fa572f8ac2d6d1250`;
   - phase-10 tests `f63396f54e70d3c106cd2acbc4758e9d4fb1dda0`;
   - fixture paths `4a981f772ee70780d0011696010a0e1b8bef6972`;
10. verify no `bin/test-data` symlink or substitute path exists before runtime.

Any preflight mismatch is an infrastructure/immutable-artifact failure. Do not continue into semantic classification.

## 5. Native discovery authority

Use only the packaged GoogleTest executables and their native `--gtest_list_tests` support after immutable preflight.

Expected exact discovery:

| Target | Expected |
|---|---:|
| producer | **208** |
| validation | **77** |
| authority kernel | **14** |
| independent oracle | **29** |

Producer expectation is accepted M1h discovery 202 plus exactly six M1i focused contracts.

Unexpected discovery count, missing suite, duplicate name, or zero-selected filter is a runtime acceptance blocker. Do not compensate with source parsing.

## 6. M1i focused acceptance — six fresh processes

Run each exact M1i contract individually in a fresh process. Each invocation must select exactly one test and must pass:

1. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.PlanarCellPublishesCheckedDefaultComponentAndSheet`
2. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.ExplicitSourceLabelsRemainDistinctTypedDomains`
3. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.MultipleObservedSheetsDoNotInventRepresentativeSheet`
4. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.MalformedSourceScopeFailsClosed`
5. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.FaceRowPermutationPreservesTypedCellSourceScope`
6. `SurfaceCellPhaseFrontCellSourceScopeAuthorityMigration.CellToLegacyEdgeBoundaryPreservesTypedScope`

Required result: **6/6**.

Do not replace individual process evidence with one aggregate suite run.

### Focused risk checks

Two contracts deserve explicit interpretation if red:

- `MultipleObservedSheetsDoNotInventRepresentativeSheet` uses an already-existing valid reciprocal isolation-seam production path. If it fails to produce/retain multi-sheet cell authority, classify whether the new typed migration broke an accepted reachable path or whether the witness assumption is invalid. Do not alter the test in this turn.
- `FaceRowPermutationPreservesTypedCellSourceScope` compares semantic scope rather than positional cell IDs. Any failure must be classified against source-scope invariance, not repaired by sorting/emission-order tricks.

## 7. Entering M1 preservation

Run each retained focused migration suite individually from its packaged test-name manifest, with fresh processes per named test:

- M1h field-chart authority: **6/6**;
- M1g periodic holonomy route transport: **6/6**;
- M1f vertex-continuation route transport: **6/6**;
- M1e segment route transport: **6/6**;
- M1d phase-front route identity: **6/6**;
- M1c field-transition authority: **6/6**;
- M1b source/provenance consumer: **6/6**.

Also re-run the accepted counterexamples individually:

M1d route witnesses — **3/3**:

- `SurfaceCellTransitionQuotient.ExactHardRailCounterpartsStitchAcrossTopologyRegions`;
- `SurfaceCellTransitionQuotient.ArtificialInteriorBoundaryIsRejected`;
- `SurfaceCellTransitionQuotient.ComponentBoundaryAndEulerFactsAreComputedFromIncidence`.

M1c transition counterexamples — **3/3**:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

Any newly red accepted M1 contract blocks M1i acceptance and must be classified as a regression until disproven by exact evidence.

## 8. Complete required-green producer segment

From exact producer discovery **208**, exclude exactly 15 separately classified tests:

- four direct representative products;
- eight historical/deferred reds;
- `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent`;
- BunnyRandom;
- Vase.

Expected required-green selection:

`208 - 15 = 193`.

Run that exact aggregate and require:

- selected exactly **193**;
- passed **193/193**;
- rc=0.

This is the complete producer guard against focused-test-only acceptance. If selection is not exactly 193, stop and reconcile discovery/exclusion authority rather than changing the filter opportunistically.

## 9. Independent preservation targets

Run exact packaged executables/suites:

- validation: **77/77**;
- M1a authority kernel: **14/14**;
- T1 independent product oracle: **29/29**.

No package-native test may be rebuilt or replaced.

## 10. Direct representative product preservation

Run each product individually in a fresh process:

- Plane;
- MultiFaceSeam;
- CloseSheets;
- Cylinder.

Each must:

1. select exactly one product case;
2. report product success;
3. pass its independent oracle;
4. resolve packaged sibling `../test-data` directly;
5. run with `fixtureSymlink=false`.

These four cases remain outside the 193-test aggregate because they have separate representative-product/oracle authority.

## 11. Historical/deferred red classification

Run each entering red individually and require its existing class to remain recognizable:

1. `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` — existing assertion red.
2. `SurfaceCellTransitionQuotient.FullPeriodicRotationAndTranslationMaterialize` — `PeriodicHolonomyMismatch`.
3. `SurfaceCellTransitionQuotient.TamperedFullPeriodicTransformIsRejected` — `PeriodicHolonomyMismatch`.
4. `SurfaceCellTransitionQuotient.MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner` — `InvalidHardRailPairing`.
5. `SurfaceCellTransitionQuotient.SwappedPeriodicRelationOwnersAreRejected` — `InvalidHardRailPairing`.
6. `SurfaceCellTransitionQuotient.MissingPeriodicRelationOwnerIsRejected` — `InvalidHardRailPairing`.
7. `SurfaceCellTransitionQuotient.QuotientLineageRetainsScalarPointAndCompleteSortedAuthority` — existing assertion red.
8. `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` — `NotProductionReady:tracing ... InvalidHardRailPairing`.

Persistence of an entering known red is not a new regression. A materially different terminal class, crash, hang, or earlier invariant failure is a regression candidate and must be documented.

Nonzero periodic whole-cycle rotation is expected to remain unresolved as `PeriodicHolonomyMismatch`; `G4-B003` is not part of M1i repair.

## 12. Strict-validator timing characterization

Run `SurfaceCellsPhase10.StrictValidatorOverheadStaysBelowFivePercent` in **10 independent fresh processes**.

Record for every invocation:

- pass/fail;
- validation time;
- remesh/reference threshold value;
- process wall time and peak RSS when practical.

Do not retry failures for greening and do not collapse the result into a single final invocation. The test remains a known deferred sub-millisecond ratio/microbenchmark defect unless fresh evidence establishes a different root cause.

## 13. Bunny and Vase bounded comparison

If all earlier mandatory gates permit continuing, run the exact package on BunnyRandom and Vase in bounded artifact-only execution. A temporary narrowly scoped GitHub Actions workflow is allowed if local execution would exceed the interaction boundary.

Required heavy-job preflight and postflight:

- exact result ZIP SHA-256;
- exact **72/72** manifest/checksum authority;
- implementation/source blobs;
- producer SHA-256;
- package cardinalities;
- `fixtureSymlink=false`;
- no checkout build/configure/relink/regeneration;
- no package/source/test/fixture mutation.

### Bunny

Run exact BunnyRandom test with a bounded allowance sufficient to observe the accepted known-red path. Expected entering comparison:

`NotProductionReady:completion traceSegments=170831 arrangementCells=0 completedQuads=0`

with independent-oracle failure reported before the fatal product-success assertion.

A different failure class/order/signature is material and must be classified. Bunny is not expected to become green in M1i.

### Vase

Run the exact Vase test under a 60-second safety bound. If it reaches `[ RUN ]` and times out with rc=124, classify only as bounded safety evidence. Do **not** infer product correctness or nontermination from the timeout.

## 14. Exact postflight

After all runtime commands, independently reverify:

- result ZIP SHA-256 `e30860e5ec411dc4dc446d0a4dc65ce6f15c5784a6f5daca138ab44d7196bf25`;
- log ZIP SHA-256 `38353b8c101a298d9a537a82da17e075180619343246a6ba4a8e2f430bd14d44`;
- manifest digest `f5614100e1638990d46c7c8fa3d7c720c837dfae1ae515387977d4c0b9e9cac3`;
- all **72/72** package checksums;
- exactly 73 regular files, 7 executables, 2 libraries, 27 fixtures;
- producer hash `51f8af77c71b7607889a2379910892027464517b557c713c34411469ee7c5a5d`;
- no `bin/test-data` symlink or other runtime package repair.

Any postflight mutation invalidates the runtime evidence.

## 15. Acceptance gate

M1i is immutable accepted only if all of the following hold simultaneously:

1. immutable preflight is exact;
2. native discovery is producer **208**, validation **77**, M1a **14**, T1 **29**;
3. M1i focused is **6/6** individually;
4. M1h through M1b focused preservation remains fully green;
5. M1d route witnesses are **3/3** and M1c transition counterexamples are **3/3**;
6. required-green producer is exactly **193/193**;
7. validation **77/77**, M1a **14/14**, T1 **29/29**;
8. Plane/MultiFaceSeam/CloseSheets/Cylinder remain independent-oracle clean without fixture symlink;
9. all eight historical/deferred reds retain their entering classes;
10. strict-validator timing is characterized truthfully in 10 fresh processes without retry-based greening;
11. Bunny/Vase comparison is bounded and truthfully classified if executed;
12. exact postflight passes unchanged.

If any new M1i or entering accepted contract fails, stop acceptance and classify the exact defect. Do not edit it in this Test + Benchmark turn.

## 16. Closeout only after runtime truth is known

If M1i passes:

- write one authoritative M1i immutable Test + Benchmark report;
- update durable/live status documents non-destructively;
- inspect the newly accepted source only then and select exactly one next bounded M1 production consumer;
- write exactly one next Code + Build plan;
- clean temporary runtime workflow/trigger/payload state;
- update PR #8 title/body;
- make exactly one new top-level PR #8 closeout comment as the final repository/PR write.

If M1i fails:

- write a truthful blocked runtime report;
- classify product regression versus test-authority/package defect from evidence;
- do not select the next M1 consumer;
- write only the bounded remediation turn authorized by the failure class;
- perform the same temporary-state cleanup and final single-comment closeout discipline.
