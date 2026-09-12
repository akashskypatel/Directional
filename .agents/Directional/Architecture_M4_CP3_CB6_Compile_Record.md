# M4-CP3-CB6 Code + Build Record — exact-torus hard-rail reachability witness correction

**Turn:** `M4-CP3-CB6`
**Status:** BUILD GREEN / RUNTIME-FREE
**Semantic source:** `9d66fcebe4b91ab74a6d0234c46643a2723ab643`
**Compile run/job:** `34673625938 / 103499484128`
**Package artifact:** `10292005428`
**Compile-log artifact:** `10292090424`

## Guard result

The mandatory pre-mutation guard in `Architecture_M4_CP3_CB6_Code_Build_Plan.md` passed against the committed `benchmarks/fixtures/milestone-g/torus.obj`:

- mesh counts are exactly `V/E/F = 72/216/144`, every source edge has two incident faces, the mesh is connected, and `χ = 0`, hence the closed witness is genus 1;
- every consecutive pair in `C_minor = 0-3-25-37-49-61-0` and `C_major = 0-1-4-6-8-10-12-14-16-18-20-22-0` is an existing source edge;
- each cycle is simple except for closure and the cycles intersect only at source vertex `0`;
- the committed coordinates show `C_minor` at constant major angle while varying the minor coordinate and `C_major` at constant minor coordinate while varying the major angle, so they represent independent torus generators;
- cutting the 18-edge union yields a connected cut complex with `V/E/F = 91/234/144`, `χ = 1`, 36 boundary edges in one degree-2 boundary component, and genus 0: a disc complement;
- `AdaptiveFeatureMapOptions::userHardEdges` reaches `build_authoritative_surface_cell_rails(...) -> hard_feature_edge_keys_from_rails(...) -> tracingOptions.hardFeatureEdges` without geometric inference or product-semantic changes.

Therefore the frozen explicit torus hard-rail fixture authority is statically valid and the authorized test-only correction could proceed.

## Implemented

Only `tests/FieldAlignedCurveNetworkTests.cpp` changed semantically.

- Added `cp4c_torus_hard_rail_remesh_options()`, starting from `cp4c_remesh_options()` and inserting exactly the 18 unique source-edge pairs from the two frozen cycles into `surfaceCells.featureMap.userHardEdges`.
- Allowed the existing CP4c pipeline-products fixture builder to accept a caller-supplied `RemeshOptions`; all existing callers retain the prior default.
- Row408, `RemeshPipeline.ExactA3ToA4TorusProductionPathPublishesTypedSharedBoundaryIdentity`, alone uses the explicit torus hard-rail options.
- Strengthened row408 non-vacuity to require retained authoritative rails, at least one `HardFeature` rail, retained topology/baseline/trace-network authority, produced phase-front disposition, exact A2b/A3 conformity digests, at least one `HardRail` front edge, an exact `sharedBoundaryInterval` on every such edge, and no `InvalidHardRailPairing` terminal detail.

No production source/header, A2b/A3/A4 semantic, tolerance, fallback, selector, row404-407, CMake ownership, or reusable workflow permission changed.

## Selector and ownership contract

Packaged-source re-proof preserves:

```text
candidate selector408 SHA-256 = c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484
accepted selector403 SHA-256  = c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7
selector408 rows              = 408 LF identities
selector408 first403          = byte-identical to accepted selector403
owner partition               = 30 authority-kernel / 262 producer / 75 completion / 41 validation
missing / ambiguous owners    = 0 / 0
row408 owner                  = producer
```

## Compile/package evidence

The reusable compile workflow checked out the exact semantic source and used GMP/GMPXX. The changed owner was the preflight target, then the frozen eight-target package was compiled.

```text
semantic source             = 9d66fcebe4b91ab74a6d0234c46643a2723ab643
run / job                   = 34673625938 / 103499484128
package artifact            = 10292005428
package artifact SHA-256    = 7723188540182f9515b95efd83c13dd1dbc6f0813532a98cd8df0778a12a882f
compile-log artifact        = 10292090424
compile-log artifact SHA-256= 80b3950a876b7b5a765f3b95781111f5c7fcefa7e637f96406be96421a580d76
source archive SHA-256      = 3c82e4778ec4ea4631e25d39ed18f7f7ed68a2a24a1ad08e3ebfe298dfe331a9
package manifest SHA-256    = 26529a4d12434bc737e4952f09f9790dd8f36d4151e1500154fa7a60497101af
manifest entries            = 28
preflight target            = directional_surface_cell_producer_tests
preflight exit              = 0
full compile exit           = 0
runtimeExecution            = false
```

All five recorded source-status files are empty. The downloaded immutable package re-verified all 28 manifest entries. The six packaged executables are mode `755`. GMP evidence links `libgmpxx` and `libgmp`. The full compiled target set is:

1. `directional_surface_cell_producer_tests`
2. `directional_core`
3. `directional_pipeline`
4. `directional_surface_cell_authority_kernel_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No generated Directional binary, GTest discovery/listing command, `ctest`, test, benchmark, CLI/help/version command, fuzzer, or custom-input runtime executed during CB6.

## Disposition

CB6 is **COMPLETE / BUILD GREEN / RUNTIME-FREE**. It corrects only row408's test-authority precondition and produces a new immutable candidate package. It does **not** promote selector408, close `G4-B002`, close CP3, or establish A3→A4 runtime acceptance.

Accepted runtime authority remains corrected R4 artifact `10289601000` / selector403 **403/403**. Stable accounting remains **47 events / 14 categories / 33 recurrences**, debt **5**.

**Exact successor:** `M4-CP3-TB4-EXEC` under `Architecture_M4_CP3_TB4_Artifact_Only_Test_Benchmark_Plan.md`, followed by mandatory `M4-CP3-TB4-REV`.
