# M6-CP3-CB1-ENTRY-R4 — Phase14 typed valid-rail fixture (incremental)

**Authority:** existing Code + Build turn `M6-CP3-CB1-ENTRY-R4`, successor UNKNOWN. No Directional test, benchmark or binary execution is authorized or claimed.

## Source-only correction

The existing `SurfaceCellTracingPhase14.RailPreprocessingRejectsMalformedIntervalsAndReportsEndpointForValidRail` fixture constructs an invalid six-sample hard rail, verifies `InvalidSamplePair`, then truncates it to one valid two-sample rail and expects `Valid` plus an `OpenEndpoint` continuation. The valid fixture did not publish ordered source vertices; its exact `rail_sample` endpoints are source vertices 0 and 4.

At `tests/SurfaceCellTracingPhase14Tests.cpp:1812`, immediately after `validRail.samples.resize(2)`, publish `validRail.sourceVertices = {0, 4};`. The test identity, source face, sample positions, first negative, valid-interval assertions and production code remain unchanged. This exercises the existing RA-43.4 typed-rail validation path rather than claiming all legacy rail fixtures are migrated.

- Exact source baseline: `3c1f001fa03dde476222bbad48ae46cfebe12c9a`.
- Exact patch: `Directional_R4_Typed_Rail_Valid_Fixture_3c1.patch`, SHA-256 `0ac08b437cdb76bd36524193822961b217041f639cdc9b2cfc068144af505082`, diff-body SHA-256 `a853bf426ee9efcfed77ca73752593297da451257744fb4f95b76a92a9a5fb33`.
- Local diff checks: `git apply --check`, reverse check, `git diff --check` passed. No local build.
- Drive dispatcher apply: run `38193068301`, `SUCCESS`, result artifact `11722366850`, verified archive SHA-256 `e6487b36c1365d4c59c31cbeeac5c10ce6cc5265586933eca54b18b427097b9a`.
- Applied semantic source `5fbfa5de3f1421dab122ea70ba677efb6dd6f5f1`: exactly one added line in one test file. Consumed Drive file `1wniypxVb3U4SdZxUhjq4CyjJPWl44TmW` permanently deleted after successful push.

## Compile boundary

The first dispatcher compile request, event `b2dc5297f15988f247f18f48c9e21e6c7d1e419e`, run `38193166326`, **FAILED AT REQUEST PARSE**: unknown `retention_days` field for operation `compile`. The compile job was skipped; this is not a C++ compiler failure. No runtime execution occurred.

Corrected request `3858971cdc9af54f53152c6664a78050fee83c1b` removes only that unsupported field and retains exact source and the standard eight GMP/GMPXX targets. Authoritative terminal mailbox: `.workflow-mailbox/m6-cp3-r4-phase14-typed-rail-compile-c/latest.json`. **Compile result pending at this document's creation.** Do not treat the prior parse failure or the source apply as compilation success, and do not redispatch unchanged requests.

RA-43.4's remaining legacy fixture migration, independently gated overfull-A3 Review, 39 endpoints, 34 Phase10, seven DCEL, 88 CP2 accepted losses, six CP3 positives and real multi-carrier/odd-τ witnesses remain open. Frozen TB497 selectors, workflows, ABI, PR metadata and acceptance ledgers are unchanged.

## Exact-source compile/package verification (2026-10-12)

- Corrected request `3858971cdc9af54f53152c6664a78050fee83c1b`, workflow [38193556754](https://github.com/akashskypatel/Directional/actions/runs/38193556754), compile job `114631316138`: **SUCCESS**; parse, schema validation and mailbox jobs successful, no Test + Benchmark job run.
- Immutable packaged source `5fbfa5de3f1421dab122ea70ba677efb6dd6f5f1`; artifact `11721982481`, verified outer ZIP SHA-256 `2e665b1a2d7833c979e2bc5975979f36053e218443934de26c2cf208076637b2`. All **28/28** internal `SHA256SUMS` entries passed.
- Preflight/build exits `0/0`, all eight required targets listed in package, final source status clean, CMake `DIRECTIONAL_ENABLE_GMP=ON`, real `libgmpxx.so` and `libgmp.so` linker evidence, `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- **Compile-only candidate**. This does not establish the test's runtime assertions or restore any accepted CP2/R3 result. The first parse-failed request is retained above as historical diagnosis and was not rerun unchanged.
