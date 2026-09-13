# M4-CP3-CB9 Code + Build Report

**Turn:** `M4-CP3-CB9`
**Status:** COMPLETE / COMPILE-GREEN / RUNTIME UNADJUDICATED
**Semantic source:** `47ae78e1e46e7d2dcc230fc617291ca45f2e418e`
**Product mutation:** `src/geometry/SurfaceCellTracing.cpp` only
**Runtime execution:** none

## Guard result

G1-G3 were recorded GREEN before product mutation in `Architecture_M4_CP3_CB9_Derivation_Guard_Record.md`. G1 proves accepted selector403 ordinal138 is a valid three-segment planned hard-feature disc currently intercepted by the premature accepted-cut `<4` rejection. G2 independently re-derives the row408 torus as raw `72/216/144, chi=0`, with the frozen 18-edge two-generator cut producing occurrence-domain `91/234/144, chi=1` and one 36-edge boundary. G3 freezes invalid authority as `Rejected/InvalidFrontBoundaryAuthority` while valid total boundary authority below four segments remains `NotApplicable`.

## Implemented correction

Removed only the premature `acceptedSegments.size() < 4U` rejection in `build_curved_bounded_disk_phase_front_for_faces`. Accepted-cut authority validation now completes before the already-existing common bounded-disk cardinality gate. Therefore a fully valid three-segment domain declines as `NotApplicable`, while all digest/binding/carrier/orientation/schedule/topology/occurrence contradictions still hit their existing typed rejection sites. Row408 remains on the `>=4` occurrence-domain path.

Tests, fixtures, selector403/408 bytes, A2b/A3 writers, aggregate fail-closed behavior, and reusable workflow permissions were not changed.

## Compile evidence

Changed-owner preflight:
- run `34720050597`; result artifact `10306140656`; artifact SHA-256 `d375418b46770e395e720db39cf381f25aa1a6723ddaa761658e32fb5412f71e`
- exact source `47ae78e1e46e7d2dcc230fc617291ca45f2e418e`
- target `directional_surface_cell_producer_tests`
- preflight/build exit `0/0`; GMP/GMPXX linked; source status empty; `runtimeExecution=false`

Frozen eight-target package:
- run `34720182350`; result artifact `10305678151`; artifact SHA-256 `543fd253bf04bde38f16aac8c33a05447bf515f37027a077f6014ff13957a629`
- exact source `47ae78e1e46e7d2dcc230fc617291ca45f2e418e`
- targets: `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, `directional_benchmarks`
- preflight/build exit `0/0`; GMP/GMPXX linked; all source-status records empty; `runtimeExecution=false`
- root `SHA256SUMS`: **28/28 PASS** under independent local verification

No Directional binary, GTest, `ctest`, or benchmark was executed in this turn.

## Disposition

CB9 is complete at the Code + Build boundary. `M4-CP3-TB6-REV-CAND-01` remains OPEN / runtime-unadjudicated; accepted runtime authority remains corrected R4 artifact `10289601000` / selector403 403/403. Stable accounting remains **48 events / 14 categories / 34 recurrences**, debt **5**. The sole successor is `M4-CP3-TB7-EXEC`, consuming artifact `10305678151` without rebuild or repair.
