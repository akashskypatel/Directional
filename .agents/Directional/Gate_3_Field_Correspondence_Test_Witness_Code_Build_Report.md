# Gate 3 Field-Correspondence Test Witness — Code + Build Report

## Decision

**Code + Build complete. Runtime validation remains pending.**

The sole remaining G3 focused-contract failure was corrected in test source only. Production source is byte-identical to the runtime-proven G3 closure source from artifact `9010838200`.

The corrected test no longer requires one un-subdivided V front edge to connect two exact source-ring vertices. It instead observes nonzero source-attached V-family boundary-path segments reconstructed from each segment's authoritative source face and barycentric endpoints, then verifies those segments align with the local V cross-field family independently of target subdivision.

No generated Directional binary was executed in this turn.

## Design declaration

```text
Active design gate: G3 periodic closure / holonomy — production runtime contract satisfied; formal closure pending test correction
Earliest failing contract: SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence
Missing test contract: field-authoritative adjacent-ring correspondence must be observed through source-attached V-family path geometry independent of target subdivision; a test may not require one un-subdivided phase-front edge to span two exact source-ring vertices
Smallest general change: replace the exactInterRingEdges witness with a subdivision-invariant check over nonzero V-family boundary-path segments reconstructed from face+barycentric source provenance, asserting alignment with the local authoritative V cross-field family while retaining a nonempty observation requirement
Observable closure condition: corrected field-correspondence test passes without production changes, the endpoint/ambiguity/periodic/G1/G2 contracts remain compiled unchanged, and the next exact artifact keeps cylinder direct deterministic strict-valid periodic CompletedSurfaceCells output
Explicitly deferred work: G4 topology/singularities, G5 adaptivity/features, G6 bunny/vase production, scheduler timing, historical completion/simplification failures, and unrelated optimization
```

## Exact source authority

Final evidence commit:

- `117620ec2da2083ce11b205835e58fa404f163ef` — `test(surface-cells): make field witness subdivision invariant`.

Patch SHA-256:

- `f5699ea435ec650384ed2d3791ec032e2cddbf09ae9d9fd4e0f86928d5e078fb`.

Blobs:

- `tests/SurfaceCellsPhase10Tests.cpp` → `80a0b58339102279ab863d9112e243a557cd270d`;
- `src/geometry/SurfaceCellTracing.cpp` → unchanged `63e5ee427f675077f710db51ffb56d91838d3519`;
- `include/directional/geometry/SurfaceCellTracing.h` → unchanged `c1b816a584d67a3f74c2d7389962bd92d52244c9`.

The commit changes exactly one file: `tests/SurfaceCellsPhase10Tests.cpp`.

Runtime-proven production source remains `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`.

## Corrected test contract

`SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` now:

1. requires the producer to reach its existing `Produced` precondition;
2. iterates authoritative phase-front cell boundary paths rather than demanding one particular front-edge subdivision;
3. examines only `family == 1` source-attached segments;
4. requires valid source faces and finite barycentric endpoints;
5. requires barycentric sums to remain one and coordinates to remain in the source simplex within numerical tolerance;
6. reconstructs each segment's source-space endpoints from `(source face, barycentric)` provenance;
7. ignores only genuine zero-length segments;
8. projects the reconstructed segment and local `faceAxisY` onto the source-face tangent plane;
9. requires absolute normalized dot product `1` within the existing `1e-10` semantic tolerance;
10. requires a nonempty set of observed V-family source-attached segments.

This preserves the original field-authority assertion while removing the invalid assumption that target subdivision leaves a whole source inter-ring edge as one front edge. It adds no fixture count, ring-size, output-count, source-ID, ordering, frequency, or production special case.

The typed ambiguity test, endpoint-canonicalization contracts, periodic contracts, validators, fixtures, and production behavior were not modified.

## Successful compile-only authority

Workflow:

- run `31228899303`;
- job `93028533210`;
- conclusion **success**.

Build artifact:

- ID `9013161456`;
- name `g3-field-correspondence-test-witness-code-build`;
- outer SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- created 2026-08-08 UTC;
- 14-day retention.

Detailed log artifact:

- ID `9013161584`;
- name `g3-field-correspondence-test-witness-code-build-logs`;
- outer SHA-256 `baef2956f2c455a963f96ffe935c1d6173ba0854c847a690919e21c61423630f`.

Verified artifact closure:

- recursive checksums **44/44**;
- compile/link **111/111**;
- approved targets **7/7**;
- five executables;
- two project static libraries;
- 27 fixture/input files;
- Release / Ninja;
- repository targets enabled with `DIRECTIONAL_BUILD_TESTS=ON` and `DIRECTIONAL_BUILD_BENCHMARKS=ON`;
- no generated test-discovery command was run during the build;
- source archive, exact one-file patch, compile database and configure/build/toolchain logs;
- `runtimeExecution=false` command-boundary metadata.

Approved targets:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

No generated project test, benchmark, CLI, GUI, help/list, discovery or other Directional runtime command was executed.

## Bounded infrastructure corrections

Three earlier remote attempts failed before producing an authoritative build artifact:

- one malformed temporary workflow was rejected before a job existed;
- one run configured without the repository's `DIRECTIONAL_BUILD_TESTS` / `DIRECTIONAL_BUILD_BENCHMARKS` options and therefore had no test targets;
- one run fetched the exact evidence source at depth one and could not resolve its parent for patch packaging.

These were workflow/build-evidence defects only. They did not execute generated Directional binaries, change production source, or create runtime evidence. The successful run uses the repository's actual build options and a depth-two exact-source fetch.

## Cleanup

After artifact and log verification:

- the bounded G3 workflow was removed before its marker;
- the marker was removed;
- the turn payload was removed;
- final `.github/workflows` contains only `.github/workflows/agent-source-snapshot.yml`;
- connector-trigger and turn-payload directories are absent.

## Runtime authority entering the next turn

Artifact `9010838200`, source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`, remains the latest executed runtime authority until artifact `9013161456` is tested.

That authority already proves exact cylinder production G3 closure behavior:

- `Produced / CompletedSurfaceCells`;
- holonomy `r=0`, `t=(32,0)`, route 32, cut 4;
- 288 pure output quads / 320 output vertices;
- zero completed/strict validation failures;
- field P95 approximately `8.54e-7°`;
- exactly two true annulus exterior loops, no artificial-cut exterior seam;
- no fallback/recovery;
- deterministic output hash `32135be51d7a0a26` across 3/3 processes.

The only previous focused-contract failure was the invalid subdivision-dependent test witness corrected by this turn.

## Next turn

Execute `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9013161456`.

The following turn must obtain **17/17 focused/retained contracts** and retain the direct strict-valid cylinder result above. If so, formally close G3 and activate G4. Do not rebuild or edit source/test/fixture/validator/build logic in that Test + Benchmark turn.
