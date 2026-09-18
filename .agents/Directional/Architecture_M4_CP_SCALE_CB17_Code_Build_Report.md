# M4-CP-SCALE-CB17 — Test-Authority Repair Code + Build Report

**Turn:** `M4-CP-SCALE-CB17`
**Disposition:** **COMPLETE / COMPILE GREEN / RUNTIME-FREE / CANDIDATE UNPROMOTED**
**Semantic commit:** `b5ee824fe40f371b830c8bd9ed0d95b65edf58cf`
**Exact compile source:** `1b44d2b7b3173590db9837a1386eadbc9ac32981`
**Compile run:** `35294467857`
**Package job:** `105444324051`
**Candidate artifact:** `10527625935`
**Exact next:** `M4-CP-SCALE-TB12-R4-EXEC`

## 1. Scope held

The semantic change is exactly one file: `tests/FieldTransportAtlasTests.cpp`. Commit `b5ee824fe40f371b830c8bd9ed0d95b65edf58cf` contains no `src/**`, public header, S5 producer test, retained genus-two fixture/rawfield/metadata, CMake, benchmark or selector change. Selector426 remains byte-frozen and no selector427 is published.

CB17 removes the invalid `BuildsSyntheticGenusTwoAtlasWithMultiComponentBoundarySupport` acceptance control and restores/adapts a synthetic disk authority that proves the subject before atlas construction. Product correction from CB16 is untouched.

## 2. Test-authority correction

The replacement control is `FieldTransportAtlas.OrdersEveryClosedComponentOfOneAlgebraicBoundaryRow` over test-local `make_two_interior_islands_disk()`.

Before `FieldTransportAtlas::make`, the independent oracle:

- derives cycle facts from the mesh/field authority rather than producer output;
- identifies a `BoundaryLoop` row;
- requires exactly **6 directed support steps**;
- requires exactly **2 closed successor components**;
- independently derives the canonical flattened component sequence.

`IndependentCycleRow` now carries that expected `orderedSupport`. The snapshot validator compares producer-published steps against it order-sensitively. After atlas construction, the integration control requires six published steps, exact one-time support-edge consumption, exact ordered equality, exact support-set equality and a clean independent snapshot validation.

The R3 Review falsifier is implemented: the producer snapshot's two closed components are swapped while the exact step multiset and each component's internal order remain unchanged. `independent_validate_snapshot` must return `IncompleteCycleBasis`. The existing direct multi-component oracle, single-component canonical-sequence control and tamper control remain intact.

## 3. Compile/package evidence

Run `35294467857` uses the durable reusable compile workflow. Preflight job `105444076710` and package job `105444324051` both complete successfully. The package compiles/links exactly the standard eight targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Artifact `10527625935` has provider/local SHA-256 `88e61b93328ff4617f6810077b9469602466c06e4059b23b7c0402aefbd80e93`. Its root `SHA256SUMS` has **28 entries**, verifies **28/28**, and hashes to `d3a1ae00bc214397e23ca7a62b760566207990d108783d7355ca5cdc84224dd4`. Packaged semantic source archive `source-1b44d2b7b3173590db9837a1386eadbc9ac32981.tar.gz` hashes to `636855d94efdb8cac3898b2f0a2dd020c2ff85c90cd61ee9006d3d0a671b267e`.

`metadata/gmp-evidence.txt` records `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` on the authority-kernel link command, and `CMakeCache.txt` records `DIRECTIONAL_ENABLE_GMP=ON`. Preflight/build exit codes are `0/0`; all recorded source-status snapshots are empty; packaged executables are mode `0755`.

Package log artifact `10528325198` has provider SHA-256 `99638a4a40ea9c186c990a2c605ba726a5d3a33acddb6a72c3aae7089fb1dfab`.

## 4. Frozen-authority re-verification

From the packaged exact source:

- selector426 is exactly **426 LF rows**, SHA-256 `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`;
- exact first425 prefix SHA-256 is `e0e0f394faae536ac257ec5409653a34755a8afe0ca437562eb44c9895790e0b`;
- retained `genus_two.obj` SHA-256 is `c6bacd981fb0559dc3e290ee1367b9e369f4657b189ce288ce732461d8caeab3`;
- retained `genus_two.rawfield` SHA-256 is `7bd71837954ded74461a46d65761b953cbc186978639d41567ad4a4aac4af70e`;
- retained `genus_two.fixturemeta.json` SHA-256 is `22600270cc11b7b421007e10a3861124c4238bc0e5353b2637a9c70005bf1b76`.

No frozen selector or retained S5 fixture byte changed.

## 5. Runtime boundary and authority disposition

`metadata/command-boundary.txt` records `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP` and `semanticContracts=compiled-not-executed`. No Directional test, benchmark, CTest, discovery/list/help/version or custom runtime input was executed in CB17.

Therefore candidate artifact `10527625935` is **compile-green but unpromoted**. Accepted runtime authority remains package `10473134357` / semantic source `e15e83c79a1e1962c0ed8d31ea85187ab6600e47` / selector426 **426/426**. Stable accounting remains **49 events / 14 categories / 35 recurrences** and produced-witness debt remains **5**.

`M4-CP-SCALE-TB12-R3-EXEC-CAND-01` remains open/non-stable pending artifact-only execution of the corrected control and Review. `M4-CP-SCALE-TB12-R1-EXEC-CAND-01` remains open under `RP-07` because the post-CB16 production S5 path still has not executed.

## 6. Handoff

Exact successor is immutable artifact-only `M4-CP-SCALE-TB12-R4-EXEC` under `Architecture_M4_CP_SCALE_TB12_R4_Artifact_Only_Test_Benchmark_Plan.md`. It consumes artifact `10527625935` unchanged, runs four Gate-A controls first, then the unchanged S5 focus, then selector426 only if all prior gates are green. Fail-fast applies and mandatory Review follows every semantic outcome before S5/selector credit, candidate closure or package promotion.
