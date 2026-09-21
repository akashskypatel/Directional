# M5-CP3-CB5 Code + Build Report

**Turn:** `M5-CP3-CB5`
**Boundary:** Code + Build / runtime-free
**Result:** **COMPLETE / STATIC GREEN / GMP COMPILE-PACKAGE GREEN / CORRECTION BUILT**
**Exact successor:** `M5-CP3-TB1-R4-EXEC`

## 1. Scope and source

Authorized semantic mutation remained exactly:

- `include/directional/authority/FieldTransportAtlas.h`
- `src/authority/FieldTransportAtlas.cpp`
- `src/geometry/SurfaceCellTracing.cpp`

Exact semantic source is `001dfe8f0fec8a8dc2475e534fadc29967cadf84`. The semantic patch was applied through Drive run/job `35571765480 / 106244733083` with patch SHA-256 `44931e29f8ca13eec8f4311fb6f8ab930fe61d63018410b3adfd1c37269beaa1`; owner-side Drive retirement completed. No test, fixture, benchmark, selector, frozen-definition, CMake/build-source, `RemeshPipeline`, CP2 failure-contract, cross-region `HardRail`, or same-region `HardRail` rejection byte changed.

## 2. Implementation

`FieldTransportAtlas` now owns one immutable transition-value fact for every validated interior source edge independently of traversability. Atlas construction validates unique edge identity and two-face identity first, derives exact forward/reverse quarter-turn and signed lift/effort, stores the canonical value, and only then classifies the edge as traversable or nontraversable. Traversable adjacency is derived from that retained fact rather than independently re-reading raw ingress.

The public `transition_value(sourceEdge, fromFace, toFace)` query returns a separately typed value with no `FieldTransportAdjacencyId`; reverse direction uses the inverse quarter-turn and negated signed lift/effort. `FieldTransportAtlas::transport(...)` remains adjacency-only. Hard-feature edges remain absent from `adjacencies_` and remain `FieldTransportBarrierKind::HardFeature` barriers. Canonical transition-value facts are included in atlas semantic identity with storage-independent ordering.

`generator_route_for_span` preserves the exact A3 `Mandatory` carrier and CB4 exact-edge-parameter orientation logic, but no longer requires or reads raw `edgeTransitions`. It queries only the installed atlas for the exact carrier edge and directed source-face pair and fails closed if that semantic fact is absent. No fallback, global path search, guessed transport, floating conversion, or second production transition owner was introduced.

## 3. Static verification

Pre-build inspection established:

- only the three authorized semantic paths changed;
- transition value is retained before barrier/traversal exclusion;
- traversable adjacency derives from the retained validated value;
- hard-feature traversal remains absent;
- directed reverse semantics are exact and the query type carries no adjacency ID;
- atlas semantic identity covers retained transition values;
- production generator routing no longer references raw `edgeTransitions`;
- selector430 remains 430 LF rows at `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

No CB5 stop rule fired.

## 4. Mandatory GMP compile/package

Workflow run/job: `35572051606 / 106245602800`. Exact compiled source: `001dfe8f0fec8a8dc2475e534fadc29967cadf84`.

All eight standard targets compiled and linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Evidence:

- preflight exit: `0`
- build exit: `0`
- exact arithmetic backend: GMP
- explicit GMPXX + GMP linkage: present
- source-status receipts before/after configure/build/final: all empty
- `runtimeExecution=false`
- candidate artifact: `10627250028`
- candidate ZIP SHA-256: `0d26b01c026651ecacf57af04615746e6b48b09db2e5f1baa1dce62db31bc28f`
- root `SHA256SUMS`: **28/28 verified**, manifest SHA-256 `abbda66e46b059832027b82b5dde457dfb2f8b10472bdb742f61f25979e7e02b`
- packaged source archive SHA-256: `4335090caf9a1b5f38efa7ce3745d9f1a4bae13871c41572baa62abd2e06570b`
- compile log artifact: `10626109792` / SHA-256 `167f16e9886c24839581c4e94061e4219bc6e833bdf31e81884a52ad3f7e4af5`

No generated Directional binary, test, benchmark, discovery/list/help/version command, CLI/GUI, `ctest`, fuzzer, or custom input executed.

## 5. Disposition

CB5 is compile-green and static-faithful but supplies **no runtime acceptance**. Candidate `10627250028` remains unpromoted. Accepted runtime authority remains package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` under selector430 **430/430**. Stable accounting remains **50 events / 14 categories / 36 recurrences**, produced-witness debt **5**; all four M5 produced debts remain open and selector publication remains prohibited.

`M5-CP3-TB1-R2-REV-OBS-01` remains for the corrected Review to verify reached production consumption of validated atlas authority, and `M5-CP3-TB1-R3-REV-OBS-01` remains for that Review to record the non-traversal transition-value contract in frozen definitions before accepting CB5's result.

Exact successor is fresh artifact-only `M5-CP3-TB1-R4-EXEC`, consuming candidate `10627250028` and restarting the complete frozen **9 + 6 + 430 = 445** process sequence with benchmark execution `0` and no semantic-credit reuse from R1/R2/R3.
