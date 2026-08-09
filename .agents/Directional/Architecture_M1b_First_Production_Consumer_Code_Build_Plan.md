# M1b First Production Consumer — Code + Build Plan

**Status:** authoritative next turn  
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — authority kernel and compatibility boundary  
**Depends on:** accepted M1a immutable report  
**Production behavior delta:** none intended  
**Review policy:** `never`

## 1. Objective

Migrate exactly one real production consumer across the accepted M1a authority kernel without changing producer decisions, public result schema, source-support classification, optimization policy, or product disposition.

The selected first consumer is the **source-face/source-vertex identity boundary inside surface-optimization rail sheet compatibility**:

`RemeshPipeline -> fill_surface_optimization_rail_constraints -> surface_optimization_rail_detail::provenance_supports_interval_sheet`.

This slice is deliberately narrower than chart/transition migration. It proves that a live production consumer can ingest validated legacy authority through strong `SourceFaceId` / `SourceVertexId` values and return to legacy representation only at an explicit rollback seam.

## 2. Why this boundary is first

`provenance_supports_interval_sheet` is a bounded, single-purpose production consumer that currently reads raw source-face/source-vertex integers to validate exact source incidence before assigning rail constraints. It is downstream of producer construction and does not own topology, chart selection, quotient, completion, or validator authority.

That makes it suitable for the first strangler step:

- real production call path;
- one local consumer and one local helper;
- no producer-state migration;
- no change to public legacy structs yet;
- explicit sentinel handling already exists;
- exact row-index conversion can be isolated at matrix access;
- rollback can restore one consumer without touching the accepted M1a kernel.

Do **not** use M1b to migrate `SourceChartId`, `SurfaceCellSourceChart`, transition graphs, arrangement, completion, quotient, or validators. Those have multi-consumer ownership and require later bounded M1 slices.

## 3. Exact implementation boundary

Allowed production paths:

- `CMakeLists.txt` — attach `src/authority/AuthorityKernel.cpp` to `directional_core` so production consumers can link the accepted kernel;
- `cmake/DirectionalTests.cmake` — stop compiling `AuthorityKernel.cpp` directly into the authority test executable once it is supplied by `directional_core`;
- `include/directional/geometry/SurfaceOptimizationRailConstraints.h` — type the internal detail helper boundary only if required;
- `src/geometry/SurfaceOptimizationRailConstraints.cpp` — migrate only `source_face_contains_vertex` and the validated source-face/source-vertex portion of `provenance_supports_interval_sheet`;
- `tests/SurfaceMeshOptimizerPhase22Tests.cpp` — add or strengthen focused semantic/counterexample coverage for this consumer boundary if existing tests are insufficient.

M1a authority headers/source may change only for a **minimal adapter deficiency proven by this consumer**. Such a change is a stop-and-document condition before modification; do not expand the kernel opportunistically.

No other production/test path is authorized.

## 4. Compatibility rollback boundary

Legacy public/runtime objects remain unchanged in M1b:

- `SurfacePoint.face` remains legacy `int`;
- `SurfaceFeatureCurveInterval.sourceFace` remains legacy `int`;
- source-face/component/sheet vectors remain their current representation;
- rail samples, producers, optimizer output, diagnostics, and public result schema remain unchanged.

The compatibility seam is inside `provenance_supports_interval_sheet`:

```text
legacy sentinel / extent checks
    -> named LegacyAuthorityAdapters conversion
    -> SourceFaceId / SourceVertexId semantic consumer logic
    -> LegacyAuthorityAdapters::to_legacy_index only at Eigen/vector row access
```

Rollback is therefore bounded: revert the typed helper/consumer and core source attachment while leaving the accepted M1a kernel intact.

No raw value may cross from this seam into typed consumer logic without named checked conversion.

## 5. Required behavior preservation

M1b must preserve the existing function's truth table exactly.

In particular:

- negative legacy sentinel handling remains exactly where the legacy contract currently permits/denies absence;
- out-of-range source faces still reject; no clamp/wrap/default is introduced;
- same-component mismatch behavior remains unchanged;
- same-sheet fast path remains unchanged;
- cross-sheet path still requires valid provenance and exact source incidence under the **existing** support classification;
- source-face component/sheet authority checks retain the same predicates;
- rail interval construction, feature assignment, tolerance, projection, ordering, and fixed-vertex policy are byte-for-byte behavior goals.

M1b does **not** redesign the existing `1e-8` barycentric support classification. That is later exact-source-support work under M5/AR-09. Typed IDs must not be used to legitimize or broaden tolerance-derived identity.

## 6. Strong-domain migration rule

Once the current code establishes that a source-face or source-vertex legacy value is nonnegative and within its declared extent:

- convert source face with `LegacyAuthorityAdapters::source_face`;
- convert source vertex with `LegacyAuthorityAdapters::source_vertex`;
- internal helper comparisons take the strong ID type, not raw `int`;
- matrix indexing converts back only with `LegacyAuthorityAdapters::to_legacy_index` at the access expression;
- conversion failure follows the existing rejection path and does not substitute a fallback value.

Do not convert component/sheet sentinels in this slice unless required to compile the exact boundary; they remain a later consumer migration. This prevents M1b from becoming a multi-domain/multi-consumer rewrite.

## 7. Mandatory regression-pattern review

| Pattern | Touched? | M1b invariant | Following immutable evidence |
|---|---|---|---|
| `RP-01` | **yes** | source face and source vertex are distinct typed domains after the compatibility seam; no raw cross-domain comparison | focused positive + negative domain/extent tests; M1a 14/14 |
| `RP-02` | preservation | semantic tests observe rail assignment/incidence outcome, not merely typed construction | named focused tests + T1 29/29/direct comparison |
| `RP-05` | yes, bounded | semantic face/vertex identity does not depend on incidental row/hash handles beyond the explicitly declared legacy source-row adapter | exact incidence counterexamples; no hash/order oracle |
| `RP-03` | no | producer/stage state unchanged | source diff + direct behavior |
| `RP-04` | no | no recursion/search/work loop | source diff |
| `RP-06` | no | no copied authority membership added | source diff |
| `RP-07` | no | no route/Z4 migration in this slice | M1a preservation only |
| `RP-08` | no | no producer disposition changes | source diff |
| `RP-09` | no | no global/local relation-consumption policy changes | source diff; G4-R007 unchanged |

A touched row without a named negative/representative gate is a stop condition.

## 8. Required focused tests

Use existing default-built validation/optimizer authority where possible; add minimal tests only where the consumer boundary is not already observable.

At minimum immutable test authority after the build must cover:

1. valid same-sheet provenance/interval retains the same accepted rail assignment;
2. exact cross-sheet source-edge/vertex incidence that is currently legal remains legal;
3. a cross-sheet interior provenance case remains rejected;
4. negative/out-of-range legacy source-face values remain rejected where the old consumer rejects them;
5. wrong source face that does not contain the typed source vertex remains rejected;
6. source-face component/sheet mismatch retains the same rejection;
7. compile-time helper signatures prevent `SourceFaceId`/`SourceVertexId` interchange;
8. no test derives expected output from the typed implementation itself.

Use exact barycentric boundary values for cross-sheet incidence fixtures so this M1b test does not make a tolerance threshold the semantic oracle.

## 9. Code + Build rules

This turn may:

- edit only the declared paths;
- compile/link the touched default targets;
- package the new authority-kernel and existing T1 preservation executables;
- record exact source/binary/dependency authority and `runtimeExecution=false`.

This turn must **not**:

- execute generated Directional binaries, discovery, tests, benchmarks, `ctest`, CLI/GUI/help/version, fuzzers, or custom input;
- modify producer, tracing, arrangement, completion, quotient, validator, pipeline decision, fixture, or benchmark behavior;
- migrate component/sheet/chart/transition/rail IDs outside this exact consumer;
- alter support tolerances or projection/optimizer policy;
- repair G4-R007, Bunny, Vase, or historical failures;
- weaken M1a/T1 assertions or labels.

## 10. Compile/package acceptance

M1b Code + Build succeeds only if:

1. diff is restricted to the declared boundary;
2. `AuthorityKernel.cpp` is linked once through `directional_core`, not duplicated into test targets;
3. the typed consumer contains no direct raw-int source-face/source-vertex comparison after conversion;
4. legacy sentinel/extent behavior is explicit before conversion;
5. production geometry/rail semantics are intended unchanged;
6. authority-kernel test manifest remains exactly 14 names unless a separately justified M1b focused target adds names outside that manifest;
7. T1 oracle manifest remains exactly 29 names;
8. Release/static/Ninja configured targets compile/link;
9. immutable result/log artifacts include source patch, blobs, executable inventory, focused test manifest, and `runtimeExecution=false`;
10. no test or generated binary runs.

Compilation is not runtime acceptance.

## 11. Following immutable Test + Benchmark

The immediately following turn consumes only the M1b immutable artifact and must:

- verify package/source/dependency authority and no source substitution;
- discover and run every M1b focused consumer contract individually;
- require M1a authority-kernel **14/14**;
- require T1 oracle **29/29**;
- run Plane, MultiFaceSeam, CloseSheets, Cylinder and preserve green/oracle-clean behavior;
- run BunnyRandom/Vase with their accepted known-red interpretation;
- require focused rail-assignment/incidence outcomes to match the pre-M1b comparison boundary;
- reject any typed-domain failure, changed rail assignment, production-result drift, or package mutation.

Only after immutable M1b acceptance may another production consumer be migrated.
