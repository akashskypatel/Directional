# Gate 1 Authoritative Producer Boundary — Local Code + Build Report

## Turn result

The bounded producer-authority replacement was implemented and compile-verified. This was a **Code + Build** turn only. No generated project binary, test, benchmark, discovery command, CLI, GUI, help command, or list command was executed, so this report makes **no runtime-success claim**.

Active gate remains **G1 — uniform phase-front plane**. The latest executed runtime authority remains the preceding artifact-only result: plane failed at 106 traces / 9 arrangement cells / 12 completion candidates; multi-face seam passed with 64 direct quads.

## Source authority

- payload checkpoint: `983112aabbc618bec9032e1d2a07e32be00ed20f`;
- exact patch SHA-256: `a9af7d502a237a3f0a58324639f0fe77129de5fe5f147ea14b1e077545c5ccef`;
- coherent source commit: `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- one-use payload cleanup commit: `bcf934d34e9a15f5d0929628ffd26f6833643214`.

Changed file blobs:

| Path | Git blob |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `b33c2118e65812d4b0a4a65fe9f46b7a8766bb59` |
| `src/geometry/SurfaceCellTracing.cpp` | `c9877d8ffa8aa5fbb59c83a1ab4b94eed5421431` |
| `include/directional/diagnostics/RemeshDiagnostics.h` | `8ddb4bcdf26a1caacdf927e74e56d3fe11b3e3b7` |
| `src/pipeline/RemeshPipeline.cpp` | `533648a1b1fd008286f3ef3292813817ad1f1146` |
| `src/bench/DirectionalBenchmark.cpp` | `73d9d29e49107073a44c2e9a6fe0e89331412737` |
| `tests/SurfaceCellsPhase10Tests.cpp` | `b726b85d189c5018d53c8561888dcda0ab55fa58` |

## Implemented producer boundary

The former implicit `phaseFront.succeeded == false` fall-through was replaced by explicit producer authority:

```text
NotApplicable
Produced
Rejected
```

Semantics now implemented:

- `NotApplicable`: the bounded uniform authoritative producer does not represent the topology; only this state may continue to a separately selected generic producer.
- `Produced`: complete authoritative phase-front cells exist and are converted directly one accepted cell to one quad.
- `Rejected`: the producer was applicable but a fail-closed invariant failed; `build_surface_cell_network()` returns immediately without generic seeds, traces, or proposals.

The pipeline serializes the disposition, retains the typed phase-front rejection, records the tracing stage, and stops a `Rejected` `SurfaceCells` request at `tracing` before FlowRep, arrangement, completion, or output validation can substitute/overwrite the producer authority.

The producer disposition and typed rejection identity are included in structural hashing and benchmark diagnostics.

## Applicability and transport authority

Applicability is determined before authoritative transition metadata is consumed. The bounded uniform producer currently treats planar rectangular phase-compatible nonsingular domains as applicable. Unsupported nonplanar/nonrectangular/nonuniform/singular topologies may remain `NotApplicable`; malformed authoritative metadata on an applicable domain remains `Rejected`.

Existing transport contracts were preserved:

- ordinary shared-edge transport;
- strict reciprocal forward/reverse quarter-turn transport;
- ordered source-vertex fan traversal;
- complete ordered source-edge route provenance;
- source component/local-sheet ownership;
- source-normal-consistent orientation;
- one authoritative accepted cell → one quad.

The relief semantic mismatch was corrected generally: hard-feature edges remain hard constraints, while `reliefBarrierEdges` veto authoritative phase transport only when `reliefBarriersEmbedded == true`.

## Tests added or strengthened

The source now contains compile-verified producer contracts, but they were **not executed** in this turn.

- `UniformPhaseFrontDuplicateTransitionMetadataFailsClosedWithTypedReason` now requires `Rejected` and zero generic seeds/traces/proposals.
- `UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded` checks that non-embedded relief guidance does not veto production and the same barriers become authoritative when embedded.
- `ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary` loads the exact committed `milestone-g/plane.obj` and `plane.rawfield`, calls the real `remesh_from_raw_cross_field` route with production `SurfaceCells` options, and asserts authoritative `Produced` behavior rather than injecting a convenient target or fabricated transition state.
- Existing narrow source-vertex and face-order invariance contracts remain unchanged in strength.

The exact committed-plane test compiling successfully is not evidence that it passes; the following artifact-only turn is authoritative for runtime behavior.

## Compile authority

Bounded GitHub Actions workflow:

- run: `31154489371`;
- job: `92790924907`;
- build artifact: `8984760467`;
- conclusion: success.

Toolchain/configuration:

- Ubuntu GitHub runner;
- GNU C++ 13.3.0;
- CMake 3.31.6;
- Ninja 1.13.2;
- Release;
- static libraries;
- `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`;
- two build jobs.

Approved targets compiled exactly:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

Result: **111/111 compile/link actions; 7/7 approved targets**.

## Immutable artifact

Artifact file: `directional-g1-authoritative-producer-boundary-build-artifact.zip`

- SHA-256: `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031`;
- internal checksums: **44/44**;
- five executables;
- two project static libraries;
- 27 fixture/input files;
- exact patch;
- no-dependency source archive;
- compile database;
- configure/build/toolchain logs;
- source/build/command-boundary metadata.

The downloaded artifact was independently unpacked and all 44 internal checksums verified.

## Runtime authority intentionally unchanged

No project binary was executed in this turn. The latest executed direct matrix remains:

| Fixture | Result | Traces | Arrangement | Completed | Output quads |
|---|---:|---:|---:|---:|---:|
| Plane | fail | 106 | 9 | 12 | 0 |
| Multi-face seam | **pass** | 256 | 65 | 64 | 64 |
| Close sheets | fail | 158 | 0 | 0 | 0 |
| Cylinder | fail | 732 | 0 | 0 | 0 |
| Bunny | fail | 80,862 | 0 | 0 | 0 |
| Vase | fail | 116,922 | 0 | 0 | 0 |

## Next turn

Execute `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Plan.md` against the exact artifact above.

Acceptance hierarchy:

1. **Gate 1 closure:** plane is `Produced` and returns deterministic direct valid pure-quads while seam retains its direct 64-quad success.
2. **Minimum architectural proof:** plane is explicit `Rejected`, terminal authority remains `tracing/phase-front`, generic traces/arrangement/completion do not run, and the old 106/9/12 substitution disappears. This is material progress but does not pass G1.
3. **No progress:** plane remains `NotApplicable` or reaches the old generic path, typed rejection is overwritten, seam regresses, or assertions are weakened.
