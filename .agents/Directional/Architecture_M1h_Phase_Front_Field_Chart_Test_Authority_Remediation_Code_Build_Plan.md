# M1h Phase-Front Field-Chart Test-Authority Remediation — Code + Build Plan

**Turn type:** Code + Build only  
**Review policy:** `never`  
**Prerequisite:** blocked M1h immutable runtime report retained  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

Repair only the invalid M1h focused-test witness exposed by immutable artifact execution. Do **not** advance to the next M1 consumer, M2, G4 remediation, nonzero periodic Z4 support, fallback/recovery, optimization, or public schema retirement.

The production implementation under test remains:

`de4e2ba7c19d2e49931655dc22d758f50656d054`

at the bounded seam:

`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

Runtime evidence shows no entering product-preservation regression. The blocking failure is:

`SurfaceCellPhaseFrontFieldChartAuthorityMigration.MultipleOrientationChartsPreserveEstablishedNumbering`

because it expects every producer chart `{0,1,2}` to appear among accepted **lattice-corner occurrences**, while the existing fixture only places lattice corners on charts `{0,2}`. The same fixture independently proves producer chart `1` still exists on face `3` through the typed producer-to-compatibility segment boundary.

## 2. Required correction

Correct the test so it proves the intended authorities separately:

1. **Producer numbering authority:** the multi-orientation producer still creates the deterministic chart domain `{0,1,2}` with the established numbering. Use evidence that actually ranges over the producer chart domain, not only cell-corner occurrences.
2. **Constructive-front occurrence authority:** every actual `LocalLatticeState` occurrence has a valid `FieldChartId` equal to the producer-owned chart for its source face.
3. **Compatibility boundary:** converting the typed producer chart back to `SurfaceTraceSegment::sourceChart` preserves the established numeric chart representation.

Do **not** fix the failure by changing the expected lattice-corner set from `{0,1,2}` to `{0,2}`. That would encode accidental sampling coverage rather than the semantic contract.

## 3. Preferred minimal test design

Prefer a test-only correction in `tests/SurfaceCellsPhase10Tests.cpp` using the existing `SegmentRouteFixture` unless a hard-authored replacement fixture is demonstrably simpler.

A valid minimal shape is:

```text
build existing three-chart SegmentRouteFixture

producerCompatibilityByFace = chart values carried by boundary segments
assert producerCompatibilityByFace includes:
  face 3  -> chart 1
  face 10 -> chart 2
assert union of producer/segment chart values == {0,1,2}

for every accepted cell corner occurrence:
  assert lattice.sourceChart is present
  sourceFace = cell.corners[corner].face
  obtain independently observed producer chart for sourceFace
  assert typed lattice chart converts to exactly that chart value

assert at least two distinct typed lattice chart values are exercised
assert no invalid/default chart value is accepted
```

If not every corner source face is represented by a boundary segment in this fixture, build an independent expected face-to-chart map from hard-authored fixture topology/branch labels rather than from the implementation result. Do not copy the implementation's BFS output and call it an oracle.

A dedicated replacement fixture is acceptable only if it hard-authors a planar connected mesh and orientation labels such that chart numbering `{0,1,2}` and lattice-corner coverage are independently guaranteed. Avoid geometry-dependent coincidence or face-row-order assumptions.

## 4. Production-code boundary

Expected production source delta: **none**.

Do not edit:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- fixture data;
- validator thresholds;
- product expectations;
- periodic behavior;
- topology/completion/fallback/optimization code.

A production-code edit is authorized only if compile-time inspection proves the failed test exposed a real semantic inconsistency rather than the documented fixture-coverage defect. If that occurs, stop broadening the patch, document the contradiction, and keep the change confined to the same M1h seam.

The packaged sibling `../test-data` lookup correction in `tests/TestFixturePaths.h` is already runtime-proven and must remain unchanged.

## 5. Focused test inventory

Keep exactly six `SurfaceCellPhaseFrontFieldChartAuthorityMigration` contracts unless the correction genuinely requires a one-for-one rename with identical semantic cardinality:

1. `PlanarMultiFaceFrontPublishesCheckedSingleChart`;
2. `MultipleOrientationChartsPreserveEstablishedNumbering`;
3. `NumericCoincidenceCannotCrossAuthorityDomains`;
4. `MissingOrInvalidChartAuthorityCannotMasqueradeAsValid`;
5. `FaceRowPermutationPreservesTypedPlanarChartAuthority`;
6. `PeriodicAndBoundedDiskSingleChartPathsUseCheckedChartZero`.

The second contract must remain a real multi-chart producer/consumer test, not a helper-only adapter test.

## 6. Code + Build execution boundary

This turn may:

- edit the approved test source;
- configure a Release/static/Ninja/PRE_TEST build;
- compile/link approved targets;
- package the exact test executables, libraries, fixtures, source authority, metadata, and checksums.

This turn may **not execute**:

- any generated Directional binary;
- GoogleTest discovery/listing;
- any test;
- any benchmark;
- `ctest`;
- CLI/GUI/help/version commands;
- fuzzers;
- custom input.

Compile success does not accept the corrected test.

## 7. Build/package requirements

Use the same bounded build authority as the prior M1h Code + Build:

- `Release`;
- `BUILD_SHARED_LIBS=OFF`;
- Ninja;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- tests and benchmarks compiled;
- CLI/GUI/Python/tutorials disabled as before.

Package at minimum:

- producer, validation, M1a, T1, completion, compiled API, benchmark executables;
- `libdirectional_core.a` and `libdirectional_pipeline.a`;
- all 27 committed benchmark fixtures under sibling `test-data` layout;
- exact source patch/archive;
- build logs and compile commands;
- six M1h test names plus M1g/M1f/M1e/M1d/M1c/M1b/M1a/T1 metadata;
- direct-product names;
- build-authority JSON with every runtime flag `false`;
- recursive `SHA256SUMS`.

Record exact executable hashes and source/test blob IDs for the following immutable Test + Benchmark turn.

## 8. Static Code + Build checks

Before packaging, statically verify:

- the failing test no longer asserts that producer chart-domain cardinality must equal lattice-corner occurrence coverage;
- the corrected contract still proves deterministic producer chart numbering `{0,1,2}`;
- actual lattice occurrences are checked against independent expected/producer authority;
- no test expectation is weakened to accept `{0,2}` as the chart domain;
- exactly six M1h focused contracts remain compiled;
- production M1h files are unchanged unless an explicitly documented semantic contradiction forced a narrow correction;
- `tests/TestFixturePaths.h` still resolves executable sibling `../test-data`;
- `git diff --check` passes.

## 9. Success criteria

Code + Build succeeds only if:

1. the test-authority defect is corrected without weakening intent;
2. expected production behavior remains unchanged;
3. the approved targets compile/link successfully;
4. no generated Directional binary executes;
5. the exact immutable package and logs are retained with full checksum/source authority;
6. the handoff points to a new M1h immutable Test + Benchmark turn consuming only those exact artifacts.

Do not mark M1h accepted in this turn.

## 10. Following immutable Test + Benchmark expectations

The next runtime turn must again require:

- producer discovery exactly **202**;
- M1h focused **6/6** individually;
- required-green producer **187/187**;
- M1g/M1f/M1e/M1d/M1c/M1b preservation;
- validation **77/77**;
- M1a **14/14**;
- T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle clean with no fixture symlink;
- eight historical/deferred red classes preserved;
- Bunny/Vase bounded comparison if no earlier blocking semantic gate remains;
- strict-validator timing characterized only as the existing deferred defect;
- exact immutable postflight.

Only after that artifact passes may M1h become immutable accepted and a fresh source inspection select the next bounded M1 owner.

## 11. Procedural lesson retained

When constructing aggregate GoogleTest filters, use exactly one positive/negative separator:

```text
positive-pattern-negative1:negative2:...
```

Do not generate repeated `-` separators. This is a harness rule only; it must never be encoded into product/test semantics.

Every completed turn keeps PR #8 open/draft/unmerged, removes temporary workflow/trigger/helper state, updates the concise handoff, and ends with exactly one new top-level PR #8 conversation comment as the final repository write.