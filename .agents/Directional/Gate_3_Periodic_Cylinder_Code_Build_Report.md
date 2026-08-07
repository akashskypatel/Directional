# Gate 3 Periodic Cylinder / Holonomy — Code + Build Report

## Turn boundary

This was a **Code + Build** turn only. Production source, diagnostics, benchmark serialization, and producer-test source changed. The seven approved targets were configured, compiled, and linked with `PRE_TEST`. No generated Directional binary, unit test, benchmark, `ctest` discovery, CLI, GUI, help, list, or custom-mesh command was executed.

## Design declaration

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells
Missing design contract: authoritative phase/front construction and periodic seam reconciliation on a singularity-free annulus without treating the periodic cut as an exterior boundary or falling back to generic tracing
Smallest general implementation change: extend the uniform authoritative producer with one deterministic intrinsic cut/unwrapped chart for annular source topology, record exact lattice holonomy across that cut, and stitch periodic front counterparts through source-topology/phase equivalence
Observable material-progress condition: exact production cylinder becomes authoritative Produced or reaches a new typed periodic-holonomy Rejected state with zero generic substitution, while plane, seam, and close sheets remain mandatory regressions
Explicitly deferred work: torus/non-annular topology, singularities/topology-distinct completion, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production/performance, scheduler timing, downstream completion/simplification failures
```

## Source authority

Exact compiled source commit:

- `56f823273cad041a01ebb4d0772c3265ff248f4a`

Source patch:

- SHA-256 `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`
- six changed files
- 1,297 insertions / 27 deletions

Changed authoritative blobs:

- `include/directional/geometry/SurfaceCellTracing.h` → `931669018a986096cf78d66a2aed9de5aa8e0fe1`
- `include/directional/diagnostics/RemeshDiagnostics.h` → `a51215982318e77581efa4fa7887d0406a9d4bf0`
- `src/geometry/SurfaceCellTracing.cpp` → `b1a2c6d4051cc17b79e342170285d69552cad16d`
- `src/pipeline/RemeshPipeline.cpp` → `7674ed3fe40c5f43c668c931c01b59f6c7829df8`
- `src/bench/DirectionalBenchmark.cpp` → `18955ca8ef72812c9c70ed522bb578409e6a176f`
- `tests/SurfaceCellsPhase10Tests.cpp` → `bccd6abf3e31b8096c471c515b1949d08dcfde59`

## Implemented bounded G3 contract

The uniform authoritative producer now attempts a second, explicitly bounded producer only after the connected planar producer reports `NotApplicable`.

For an active source sheet, the periodic producer:

1. derives annular applicability from source manifold topology, Euler characteristic, exactly two boundary cycles, source connectivity, and singularity-free state rather than fixture identity;
2. derives deterministic canonical boundary/ring ordering from source topology;
3. constructs one cut-open intrinsic `(s,t)` chart without requiring world-space coplanarity;
4. retains exact source face/barycentric attachment for chart samples and cell boundaries;
5. computes one complete periodic source route and records first-class holonomy as `(Z4 quarter-turn rotation, Z2 lattice translation, ordered source route)`;
6. records the deterministic boundary-to-boundary source cut separately from the holonomy route;
7. rejects duplicate, missing, non-reciprocal, or incompatible bounded-cylinder holonomy with typed periodic producer authority;
8. pairs artificial-cut front edges by intrinsic periodic lattice identity and emits explicit `PeriodicFrontMerge` events rather than exterior seam edges;
9. leaves only the two genuine annulus boundaries exterior;
10. materializes periodic output by exact lattice quotient identity rather than Euclidean seam welding;
11. preserves `Rejected` as terminal authority and leaves unsupported topology `NotApplicable`.

Periodic holonomy is included in structural hashing and serialized diagnostics. The materializer recognizes the one-direction periodic quotient while retaining the existing non-periodic plane/seam/close-sheet path.

The bounded implementation is intentionally not a general genus or arbitrary-annulus solution. Its canonical chart assumes equal-cardinality source rings. Artifact execution must determine whether its source-route/chart assumptions are sufficient for the exact production cylinder. Compile validity alone does not establish this.

## Compile-verified regression sources

The producer test source contains, but did not execute, focused contracts for:

1. `SurfaceCellsPhase10.PeriodicPhaseFrontDerivesAnnulusFromSourceTopology`
2. `SurfaceCellsPhase10.PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`
3. `SurfaceCellsPhase10.PeriodicPhaseFrontPairsArtificialCutWithoutExteriorSeam`
4. `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`
5. `SurfaceCellsPhase10.ExactCommittedCylinderReachesAuthoritativePeriodicProducerBoundary`

Existing plane, multi-face seam, and close-sheet producer regressions remain compiled in the same producer executable. No test was executed in this turn.

## Successful build authority

- workflow run: `31196268841`
- job: `92925122791`
- build artifact: `9001168379` (`g3-periodic-cylinder-code-build`)
- artifact SHA-256: `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`
- detailed log artifact: `9001167184` (`g3-periodic-cylinder-code-build-logs`)
- log artifact SHA-256: `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`
- recursive build-artifact checksums: **44/44 passed**
- packaged executables: **5**
- packaged project libraries: **2**
- packaged fixture/input files: **27**
- compile/link actions: **111/111**
- approved targets: **7/7**
- compiler: GNU C++ 13.3.0
- CMake: 3.31.6
- Ninja: 1.13.2
- configuration: Release static
- test discovery mode: `PRE_TEST`
- generated project binary execution: **none**

Approved targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

The downloaded artifacts matched the GitHub-provided outer digests. All 44 internal build-artifact checksums passed. The packaged command-boundary metadata records `runtimeExecution=false`.

## Runtime status

G3 remains **runtime-unverified**. Compile success is not evidence that cylinder succeeds or even that the new producer becomes applicable on the exact production route. The latest executed cylinder authority remains the preceding G2 artifact result: `NotApplicable`, 732 generic traces, zero arrangement/completion, no fallback/recovery.

The next turn is artifact-only Test + Benchmark using exact artifact `9001168379` and `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Plan.md`.
