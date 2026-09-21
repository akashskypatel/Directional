# M5-CP3-CB4 Code + Build Report

**Turn:** `M5-CP3-CB4`
**Boundary:** **Code + Build / runtime-free**
**Disposition:** **COMPLETE / STATIC GREEN / GMP COMPILE-PACKAGE GREEN / CORRECTION BUILT**
**Exact successor:** `M5-CP3-TB1-R3-EXEC`

## 1. Goal and source scope

CB4 implements the narrow correction frozen by `M5-CP3-TB1-R2-REV`: preserve CB3's exact A3 `Mandatory` source-path carrier, but obtain the relation transport for a hard-feature support from the existing exact raw `CrossFieldEdgeTransition` authority rather than `FieldTransportAtlas` traversal adjacency. It also completes exact source-path orientation for intervals ending at `ExactSourceEdgePoint`.

Semantic mutation is exactly one file:

- `src/geometry/SurfaceCellTracing.cpp`

No test, fixture, benchmark, selector, frozen definition, public header, CMake/build source, `FieldTransportAtlas` implementation, CP2 checked relation failure, cross-region HardRail behavior, or same-region HardRail materializer rejection changed.

## 2. Hard-feature transition correction

Exact semantic source is `6dd0e5179686a4ea2ca4aacda0577855948864df`.

The corrected `generator_route_for_span` continues to resolve the exact A3 `sharedBoundaryInterval.span` through `GlobalTopologyPlan::find_arc`, requires a canonical `Mandatory` source path and its exact `SourceEdgeSupport` carrier, and retains `InteriorTransitionId` derivation from the existing source-edge matching-index authority.

For the route step's transport value CB4 now:

1. requires raw `edgeTransitions` authority and builds the existing edge-keyed lookup;
2. rejects duplicate edge-transition authority before route construction;
3. looks up the exact `SourceEdgeTopologyKey` carried by the A3 source path;
4. reconstructs the transition's source edge from `sourceVertex0/sourceVertex1` and requires exact equality with the carrier;
5. converts `firstFace/secondFace` to typed source-face identities and requires the requested `fromFace/toFace` to match the pair in either direction;
6. uses `QuarterTurn::from_integer(matching)` for recorded forward traversal and `inverse()` for reverse traversal;
7. attaches that quarter-turn to the exact `TransitionStep`, leaving canonical route composition unchanged.

The promotion seam no longer calls `fieldTransportAtlas->transport(...)` for the mandatory HardRail support. `FieldTransportAtlas` remains authoritative for traversal/nontraversability and hard features remain nontraversable.

CB4 also hoists the already-existing exact edge-parameter conversion into the shared tracing-detail scope and derives route-step orientation by comparing the two exact parameters. `SourceVertexId` endpoints map to exact 0/1; `ExactSourceEdgePoint` endpoints retain their exact rational parameter. Equal, absent or wrong-edge parameters fail closed. No floating value participates in route identity or orientation.

This satisfies the R2 Review observation that raw transition use must re-validate unique edge authority, carrier identity and the directed face pair at the seam instead of bypassing atlas validation.

## 3. Source-patch transport evidence

The source patch was prepared against exact base `a632bc1ce955a791c2aeb8687259f38797bea441` with:

- patch SHA-256 `f9d0981b7561ca4d0a628fbb2f919fd4d84a077f4ab51c56c9b89353e54e2d4f`;
- diff-body SHA-256 `4b29f1e617bf8f60e95c0c1c964fb158ee8eb91190aaede288b3d1eb0bc4faae`;
- intended path `src/geometry/SurfaceCellTracing.cpp` only.

Google Drive reusable apply run/job `35563418044 / 106220506524` verified and applied those bytes, pushing semantic commit `6dd0e5179686a4ea2ca4aacda0577855948864df` with `runtimeExecution=false`. Apply result/log artifacts are `10622564099 / 10622928340` with provider SHA-256 `c959287841df4a28730d84cb9cfee140a2c8bb98a3c0296b333ea26997c30397 / 5896c7efc9376167011e07a6db7f5532ceadff9a1e912a67d4c06796093af327`. The workflow recorded owner cleanup required; the user-authorized Drive connector then permanently deleted the staged patch successfully.

## 4. Static contract verification

Before compile, exact source inspection verified:

- semantic diff contains only `src/geometry/SurfaceCellTracing.cpp`;
- the same-region generator route no longer calls `FieldTransportAtlas::transport` for its mandatory HardRail support;
- the route step's quarter-turn comes from the exact raw edge-transition record keyed by the same carrier;
- the transition record is re-validated for unique edge authority, exact reconstructed edge and directed source-face pair;
- reverse face traversal uses the inverse quarter-turn;
- support orientation uses exact source-edge parameters and accepts `ExactSourceEdgePoint` endpoints;
- no whole-region path/rotation search or fallback transport inference exists in the promotion seam;
- hard-feature nontraversability is unchanged;
- commit `6dd0e517...` changes only the authorized source file;
- selector430 is **430 LF rows**, no CR bytes, SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`;
- selector first427 is `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- no test, fixture, selector, frozen-definition, CP1 or CP2 bytes changed.

## 5. Mandatory GMP compile/package

Authoritative compile run/job: `35564191247 / 106222789039`.

Exact compile source: `6dd0e5179686a4ea2ca4aacda0577855948864df`.

All eight standard targets compiled and linked successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Preflight/build exits are `0 / 0`. Configure evidence records `DIRECTIONAL_ENABLE_GMP=ON`, system GMP under `/usr`, and an authoritative link command containing both `libgmpxx.so` and `libgmp.so`. All five packaged source-status receipts are empty. The fixed compatible ccache key was restored and refreshed; cacheable calls were **129/129**, with **128 hits / 1 miss**.

Candidate result artifact:

- artifact `10624020011` — `m5-cp3-cb4-result-35564191247`;
- provider/download ZIP SHA-256 `eeba51295d20082c8f20840b3f3b280d6b6012a1178eef2bd3eb5afbfd1a0ed6`;
- root `SHA256SUMS` SHA-256 `a9ccee0d830768e1d91239741bba67f4912fe86efe12cca8ddd3a13cf50f4177`, **28/28 PASS**;
- packaged source archive SHA-256 `643ce57f4b23d2237d8be0d856b6e8b49229f12dc99c49ab0ff514e39bd39253`;
- configure log SHA-256 `cc91fb2ebd2ca14abb21b47dbbbe9c6ab9c358ccdc0589a1899e3c27fe27f231`;
- build log SHA-256 `a9dccc1e51680874d39e261eb8737493f3dda26576ec374d27e05080cfc2d8e7`;
- diagnostic-log artifact `10623905213`, provider/download SHA-256 `8e58b782ebe544e8b082e3c81b6e3634fc54de420acfe9a38a6a0d08a04a76ed`.

`metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, `preflightCompile=true`, `semanticContracts=compiled-not-executed`, and a runner-temp out-of-tree build. The compile log explicitly states that no generated Directional binary, test, benchmark, discovery command, `ctest`, CLI, fuzzer, help/version command or custom input executed.

## 6. Authority and accounting

CB4 is compile-only recovery evidence. Candidate artifact `10624020011` is **not promoted** and no produced-witness debt is discharged. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**.

The R1 accepted ordinal408 PASS→RED remains the already-recorded stable `RP-01 / AUTHORITY_DOMAIN_CONFLATION` recurrence; R2 remains a failed recovery merged into that same event. CB4 executes no semantic runtime and creates no new stable event/category/recurrence. Corrected totals remain **50 events / 14 categories / 36 recurrences**, debt **5**. All four M5 produced-witness debts remain open and selector publication remains prohibited.

## 7. Successor

Fresh artifact-only `M5-CP3-TB1-R3-EXEC` must consume artifact `10624020011` exactly and restart the unchanged **9 mechanism + 6 produced + selector430 = 445** exact-filter process gate from process 1. No R1/R2 semantic credit is reused. Green or semantic-RED mechanically complete R3 evidence routes to runtime-free `M5-CP3-TB1-R3-REV`.
