# M1h Phase-Front Field-Chart Consumer — Code + Build Plan

**Turn type:** Code + Build only  
**Review policy:** `never`  
**Prerequisite:** M1g immutable accepted  
**Product gate:** G4 topology-distinct completion and singularities remains active and separate

## 1. Purpose

Adopt the existing strong `authority::FieldChartId` at the first production seam that actually owns field-chart identity:

`build_planar_phase_frame -> UniformPhaseFrame::faceChart -> LocalLatticeState::sourceChart`.

The current phase-frame producer computes connected equal-orientation charts and stores their IDs as bare `int`. Those IDs are then copied into authoritative constructive-front lattice state and later participate in front equivalence, hashing, quotient-domain state, and lineage compatibility output. M1h migrates this specific semantic boundary without changing how charts are discovered, partitioned, numbered, or used geometrically.

M1h is a representation/authority migration, not a topology or product repair.

## 2. Required behavior-preserving implementation

### A. Type the producer-owned chart partition

In the planar phase-frame path:

1. preserve the existing equal-orientation adjacency construction and deterministic BFS/chart numbering exactly;
2. after chart cardinality is known, establish checked `FieldChartId` values through the existing authority adapter/kernel;
3. store/consume typed chart identity inside the phase-frame producer rather than allowing new semantic decisions to depend on bare chart integers;
4. fail closed on impossible/invalid chart-domain construction rather than silently using `-1` or another sentinel as semantic authority.

Do not redesign chart partitioning or canonicalize/reorder charts in this slice.

### B. Type constructive-front lattice chart identity

Migrate the field-chart member carried by `LocalLatticeState` to an explicit typed/optional authority representation suitable for default construction.

Required invariants:

- every accepted front occurrence has a valid `FieldChartId`;
- equality and hashing use typed chart equality/value only after presence is established;
- planar, bounded-disk, and periodic paths that currently use a single chart preserve the same compatibility value (`0`) through a checked one-chart authority boundary;
- missing chart authority fails through the existing typed front/authority failure path rather than being coerced.

### C. Preserve compatibility output narrowly

Where downstream legacy/public structures still require integer chart representation, convert from `FieldChartId` only at the existing compatibility boundary with `LegacyAuthorityAdapters::to_legacy_index` (or an equally explicit named adapter).

Do not migrate unrelated chart concepts such as `geometry::SourceChartId` or `SurfaceCellSourceChart`; those encode source-face/component/sheet chart support and are distinct from the phase-front field-chart domain.

`SurfaceTraceSegment::sourceChart` remains out of scope unless compilation proves that one narrow compatibility touchpoint is necessary. If touched, do not broaden the slice into public schema retirement.

## 3. Artifact-portability correction required by M1g runtime

The M1g package contained all fixtures but `tests/TestFixturePaths.h::test_data_root()` searched:

`test_executable_directory()/test-data`

while the immutable package layout is:

`bin/<test executable>` and sibling `test-data/...`.

Make the minimum correction so packaged tests first resolve the executable-relative sibling root:

`test_executable_directory().parent_path()/test-data`

when it contains `benchmarks/fixtures`, while preserving the existing compile-source fallback. Do not change fixture data, test expectations, test selection, or product behavior.

This correction is test-infrastructure portability only and is not M1h semantic acceptance by itself.

## 4. Focused contracts to add or adapt

Compile production-path tests that independently prove the typed boundary. Do not execute them in this Code + Build turn.

At minimum cover:

1. planar multi-face front assigns one valid typed field chart and preserves the existing compatibility value;
2. a deterministic multiple-chart construction preserves the existing chart partition/numbering while using distinct `FieldChartId` values;
3. chart equality is semantic-domain equality and cannot be confused with source face/component/sheet integer coincidence;
4. missing/invalid chart authority fails closed before authoritative front publication;
5. face-row permutation preserves the pre-existing semantic front result and does not make raw row position chart authority;
6. single-chart periodic/bounded-disk compatibility paths establish checked chart zero rather than assigning a bare integer.

Tests must use independently authored expected relationships. Do not derive the expected chart mapping by calling the production chart builder and comparing it with itself.

Also compile one portability contract for `test_data_root()` or equivalent package-layout helper if a deterministic unit seam exists; otherwise package metadata/source layout inspection in the following immutable Test + Benchmark turn must prove arbitrary-directory execution without runtime symlinks.

## 5. Allowed edit surface

Keep changes surgical. Expected files are limited to the smallest subset of:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp` only where typed lattice chart identity crosses an existing compatibility/hash/quotient boundary;
- `tests/SurfaceCellsPhase10Tests.cpp`;
- `tests/TestFixturePaths.h`;
- compile/package workflow metadata needed to produce the immutable artifact;
- live agent status/report documents required by turn closeout.

If compilation requires a wider production edit surface, stop and document the ownership dependency instead of refactoring unrelated modules.

## 6. Explicit non-goals

Do **not** implement or change:

- field-chart partitioning or chart-numbering policy;
- `geometry::SourceChartId` / `SourceChartTransitions` semantics;
- general `SurfaceTraceSegment::sourceChart` migration unless a narrow compile boundary requires it;
- public schema retirement;
- chart transition/relation certificates (M4);
- closed producer outcome migration (M2);
- global hard-rail scheduling (M3);
- occurrence/quotient redesign (M4/M5);
- nonzero periodic Z4 product support (`G4-B003`);
- direct-torus G4 repair;
- multi-isolation repair;
- Bunny/Vase completion;
- fallback/recovery or optimization changes;
- validator weakening;
- fixture/expected-output changes;
- strict-validator timing threshold changes.

## 7. Regression-pattern interlock

Review `RP-01` through `RP-09` before editing.

Touched patterns:

- `RP-01 AUTHORITY_DOMAIN_CONFLATION`: chart IDs may no longer be bare integers at the selected production boundary;
- `RP-05 REPRESENTATION_DEPENDENT_IDENTITY`: typed chart identity is semantic authority; compatibility integers are output representation only;
- `RP-02 / TA-05`: focused chart contracts do not replace independent producer/oracle/product authority.

Preserve M1g `RP-07` route algebra unchanged. No new search/retry loop or state-cardinality expansion is authorized.

## 8. Code + Build verification boundary

This turn may edit/configure/compile/link/package but must execute **no generated Directional binary**.

Use Release/static/Ninja with `PRE_TEST` discovery semantics or the accepted equivalent. Compile/package the seven accepted executable targets and two static libraries needed by immutable Test + Benchmark, including all production fixtures and source/metadata/checksum authority.

The workflow/build record must prove:

- exact implementation commit and accepted M1g parent;
- exact changed production/test paths;
- source/test/policy blob IDs;
- package fixture closure;
- recursive `SHA256SUMS`;
- command-boundary flags showing runtime/test/benchmark/ctest/CLI/fuzzer/custom-input execution are all `false`;
- detailed activity log artifact uploaded under `if: always()` and separate from the result artifact.

Do not run GoogleTest discovery that executes binaries during Code + Build; use `PRE_TEST`/static metadata as in the accepted M1g build.

## 9. Code + Build success criteria

The turn is compile/package complete only if:

1. the selected field-chart producer/consumer boundary uses checked typed `FieldChartId` authority;
2. chart discovery/partition/numbering and public behavior are intentionally unchanged;
3. the M1g route-transport implementation is untouched except for unavoidable type-compilation compatibility;
4. the fixture-root portability correction is executable-relative and does not change fixtures/tests semantically;
5. all required targets compile/link successfully;
6. package authority is complete and self-contained;
7. runtime execution flags remain false;
8. no generated Directional binary was executed;
9. no validator/test weakening, fallback substitution, fixture-specific product branch, or synthetic expected output was introduced;
10. the next turn is an immutable artifact-only Test + Benchmark against this exact package.

## 10. Required next immutable acceptance

A successful Code + Build does **not** accept M1h.

The following Test + Benchmark turn must consume the exact build artifact without rebuilding and prove:

- all M1h focused contracts individually;
- arbitrary-directory packaged fixture execution without the M1g runtime symlink workaround;
- complete producer discovery/accounting;
- all M1g/M1f/M1e/M1d/M1c/M1b preservation gates;
- M1d/M1c counterexamples and ordered vertex-fan witnesses;
- validation, M1a, and T1 authority;
- direct Plane/MultiFaceSeam/CloseSheets/Cylinder independent-oracle products;
- all historical/deferred red classifications unchanged;
- Bunny known-red and Vase bounded safety-only dispositions;
- exact immutable package postflight.

Only after that evidence may M1h be marked immutable accepted and a further M1/M2 owner be selected.
