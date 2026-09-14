# M4-CP-SCALE-CB2 Code + Build Report — S2 Vertex-Star Certified Filter Equivalence

**Turn:** `M4-CP-SCALE-CB2`
**Disposition:** **COMPLETE / BUILD + PACKAGE GREEN / RUNTIME UNADJUDICATED**
**Semantic source:** `63cb20d6ba5393058086c62c6422ac58b75c939e`
**Candidate immutable package:** artifact `10367451675` (`m4-cp-scale-cb2-result-34892831641`)
**Accepted runtime authority remains:** package `10360085644` / source `a359b981f9350139304bc5a654041dfba78609b6` / selector423 **423/423**
**Exact successor:** `M4-CP-SCALE-TB2-EXEC`

## 1. Boundary and prediction

CB2 stayed inside the frozen Code + Build boundary. It authored one test-only S2 equivalence identity and test-local exact-oracle helpers in `tests/FieldAlignedCurveNetworkTests.cpp`. No production `src/`/`include/`, public API, CMake, fixture, selector, S1 threshold, S3/S4/S5, CP4, row399, or row408 semantic change was made. No generated Directional binary/test/benchmark/discovery/CLI/fuzzer/help/version/custom-input command executed; authoritative workflow receipts record `runtimeExecution=false`.

The frozen prediction remains falsifiable at runtime: existing production vertex-star certified-filter answers should agree with an independent exact oracle, while an exact equality subject should use `ExactFallback` and preserve the independently derived half-open owner.

## 2. Implemented S2 authority

Exactly one new identity was authored:

`M4CPScaleS2.VertexStarCertifiedFilterMatchesIndependentExactOracle`

The implementation adds `make_folded_cone_vertex_field_with_seed(mesh, rayX, rayY)` and a test-local `m4_cp_scale_s2_exact_oracle(rayX, rayY)`. Existing `make_folded_cone_vertex_field(mesh, radialBoundarySeed)` delegates to the seeded helper with its historical `(1,1)` / `(2,1)` seeds, preserving existing test behavior.

The independent oracle does not call `vertex_star_compare_angle_sums`, the production certified filter, or the production recursive radical comparator. It starts from exact integer ray seeds via `FieldExactRational::from_integer`. On the deliberately constructed three-right-angle cone, each sector is exactly `pi/2`, so `Theta = 3*pi/2` and the straight-through direction is `beta = alpha + 3*pi/4`. In the positive arrival quadrant, the discriminating boundary `beta = pi` is exactly `alpha = pi/4`, hence `sign(beta-pi) = sign(rayY-rayX)`. That exact integer comparison independently determines the expected owner and equality/radial case.

The single identity contains the frozen matrix:

| subject | exact seed `(x,y)` | independent boundary sign | expected route |
|---|---:|---:|---|
| positive strict interior | `(1,2)` | `+1` | `Filter` |
| negative / opposite order | `(2,1)` | `-1` | `Filter` |
| near-boundary certified | `(2^40, 2^40-1)` | `-1` | `Filter` |
| exact boundary | `(1,1)` | `0` | `ExactFallback` |
| tamper base | `(5,4)` | `-1` | `Filter` |
| tamper crossed | `(3,4)` | `+1` | `Filter` |

The tamper pair proves that changing an exact oracle input changes both the independently derived comparison and expected owner. The exact-boundary subject independently requires half-open ownership by face `(0,3,1)` and radial vertex 3. Every subject also checks the exact right-angle-sector witness `(dot,normProduct,crossSquared)=(0,1,1)`, owner cardinality one, and emitted route metadata. PASS diagnostics publish subject name, integer seed, oracle sign, expected owner, route, and radial status.

The identity remains **outside selector423**. CB2 assigns it zero runtime/gate credit.

## 3. Static preflight

Before mutation, CB2 enumerated the production `VertexStarDecisionKernelRoute` writers and retained route assertions. Production route authority remains in `src/geometry/SurfaceCellTracing.cpp`; existing folded-cone tests already assert both `Filter` and `ExactFallback`. No existing test asserted `RationalShortCircuit` as an S2 substitute. `FieldAlignedCurveNetworkTests.cpp` is owned by `directional_surface_cell_producer_tests`.

Selector423 was statically re-hashed at **423 LF rows** / `4e67e4dc6528a71e8399cd55dce6af4c6143e2502102e421b62a8eb712d89343`; first422 is `bbd496f3396bd656d13c728ddaad806276e00b901675255e0b67241beec4f7cc`. Static owner partition remains **30 authority-kernel / 277 producer / 75 completion / 41 validation**.

## 4. Source application evidence

The test-only preservation patch was applied by Drive workflow run/job `34892065285 / 104136993261`:

- patch SHA-256: `c05001c3dd308412c0e691e6a501ecad3256b0dbf6755e4ef7fe4a56f36f8925`;
- diff-body SHA-256: `23e77354fdcd08b41b3128a5d16c27406ec2d96fe1ae57ce873f0b57c1a64c36`;
- exact declared base: `56ba9f75d97ec96415ad34ab7873f6e5bfc25f93`;
- intended path: only `tests/FieldAlignedCurveNetworkTests.cpp`;
- applied semantic commit: `63cb20d6ba5393058086c62c6422ac58b75c939e`;
- result artifact `10367331025`, SHA-256 `b850b5e35967fd398f251f6a8a4f00dca436d14f1b713c3e959e7e4c2948806c`;
- log artifact `10367061604`, SHA-256 `23801ed9da05ffdaa6e143d91eac4e24941dbc52df8d1bbc35fae7ea638f175f`;
- `runtimeExecution=false`.

The owner-authorized Google Drive transport was permanently retired after the successful push and evidence verification.

## 5. Compile evidence

### 5.1 Changed-owner pre-package compile

Successful preflight run/job `34892475284 / 104138340270` compiled only `directional_surface_cell_producer_tests` from exact semantic source `63cb20d6...c939e` with GMP/GMPXX. The target completed **118/118** Ninja steps, `preflight_exit=0`, `build_exit=0`, with 112/113 cacheable calls hit. No generated executable was run.

- result artifact `10367556999`, SHA-256 `5efb65c232aab2dbee9bf5324d37b58c627993361c1fd5725e0c3810c2506028`;
- log artifact `10367562018`, SHA-256 `085bf0efb5e3ec66f5d05e556e8f34b3396c08201eb146f0aaf542f4ad75449f`;
- manifest: **23/23** verified;
- all source-status receipts empty;
- `runtimeExecution=false`.

A preceding temporary-caller attempt (`34892361929`) failed at workflow startup with no jobs or Directional execution because the caller used `contents: read` despite the already-frozen observer caller requirement for `contents: write`. Only the temporary caller permission ceiling was corrected; reusable workflow permissions and semantic source were unchanged. The successful run above is the compile authority.

### 5.2 Authoritative eight-target package compile

Run/job `34892831641 / 104139501513` compiled and packaged the frozen eight targets:

`directional_core directional_pipeline directional_surface_cell_authority_kernel_tests directional_surface_cell_producer_tests directional_surface_cell_completion_tests directional_surface_cell_validation_tests directional_compiled_api_tests directional_benchmarks`

The authoritative result is GREEN:

- exact semantic source: `63cb20d6ba5393058086c62c6422ac58b75c939e`;
- `preflight_exit=0`, `build_exit=0`;
- package compile: **53/53** Ninja steps, **129/129** cache hits;
- GMP/GMPXX link evidence present (`libgmpxx.so` + `libgmp.so`);
- exact arithmetic backend: `GMP`;
- result artifact: `10367451675`, SHA-256 `9a1b59bcbf6cbe14e1df180b0feaaeec6bf9e675d010f66303bc39cf4c83ddec`;
- log artifact: `10367267260`, SHA-256 `53ae0aadaca8e9893f05c243b448f8b8aaf603ff9b41c0338999b13412e7dcc9`;
- root `SHA256SUMS`: **28/28**, self-excluding, SHA-256 `b229f38237f3e3f00dfd70f5f4f28f8faae0af9a888609c2c397b6fb8af1e47b`;
- packaged source archive SHA-256: `de4667b5677ba3b60ae1737299ae3edb111cefa453e6ac4cc3f7357fe3607f27`;
- all five source-status receipts empty;
- packaged source contains the exact new identity/oracle helper;
- packaged selector423 remains **423 LF rows** / `4e67e4dc...d89343` with first422 `bbd496f3...f7cc`;
- owner executables for all **30/277/75/41** accepted selector rows are present;
- `runtimeExecution=false` and no generated Directional command executed.

## 6. Disposition and successor

CB2 is **compile/package GREEN only**. Candidate artifact `10367451675` is not promoted runtime authority here, S2 receives no selector row or gate credit, selector423 remains accepted unchanged, and stable accounting remains **49 events / 14 categories / 35 recurrences** with produced-witness debt **5**.

Exact successor is artifact-only **`M4-CP-SCALE-TB2-EXEC`** under `Architecture_M4_CP_SCALE_TB2_Artifact_Only_Test_Benchmark_Plan.md`. It may execute the focused S2 identity exactly once plus accepted selector423 as 423 fresh exact-filter processes on this immutable package, with exact postflight. It may not rebuild, repair, mutate source/tests/fixtures/selectors, append selector424, or adjudicate promotion. Mandatory Review follows EXEC.
