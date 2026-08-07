# Gate 1 Live Transition Path — Local Code + Build Report

## Turn declaration

```text
Active design gate: Gate 1 — uniform phase-front plane regression restoration
Earliest failing fixture: plane__surface_cells
Missing design contract: complete zero-turn prescribed-field metadata must support exact source-vertex fan transport while preserving ordinary reciprocal edge transport
Smallest general implementation change: expose a typed first phase-front rejection and replace only the confirmed shared-edge-only source-vertex transition predicate with a unique ordered authoritative fan traversal
Observable material-progress condition: the first-class failure/route contract is live and consumed; the next artifact must advance the plane beyond the unchanged 106/9/12 generic-completion signature while retaining the seam's direct 64-quads
Explicitly deferred work: close sheets, cylinder holonomy, bunny/vase completion, validator timing, fallback/recovery, and historical completion cleanup
```

## Confirmed source-topology defect

The exact committed plane triangulation and 8x8 phase-front side grid were emulated from the tested source path. Sixteen consecutive selected interval transitions meet exactly at a source vertex while their selected faces do not share one edge. The Gate 2 shared-edge-only predicate rejected the first such transition before authoritative phase-front construction.

This confirmation used the committed mesh/raw field and the implementation's interval-selection/topology rules. No generated project binary was executed.

## General correction

The implementation now:

- exposes `SurfacePhaseFrontFailureReason` and `SurfacePhaseFrontFailure` with first-failure cell, side, face, target-face, vertex, and edge context;
- propagates the typed failure into existing tracing/pipeline first-invalid-producer diagnostics without changing success or validation semantics;
- retains the ordinary shared-edge transition path unchanged;
- detects exact shared-vertex attachment from source barycentric endpoints;
- derives at most the two deterministic manifold fan directions from source topology;
- selects exactly one fan using the directed geometric side of the lattice segment;
- traverses every fan edge in order through `resolve_branch_transition`;
- requires component/sheet compatibility, no hard/relief barrier crossing, authoritative transition validity, final face/family/sign agreement, and canonical source-edge provenance;
- records the full ordered source-edge route rather than collapsing the fan to a positional jump;
- fails closed for disconnected, repeated, non-manifold, ambiguous, invalid, missing-provenance, or branch-mismatched fans;
- includes the complete route and failure state in deterministic hashes and owned/logical memory accounting.

No fixture name, path, ID, vertex/face count, expected output count, fallback, recovery, validator relaxation, subset search, or positional merge was added.

## Contract-level test coverage added

The source adds tests for:

- zero-turn authoritative planar transport through source vertices;
- non-empty multi-edge transition provenance;
- invariance under reversed face-row ordering;
- duplicate transition metadata failing closed with a typed reason;
- continued one-cell-to-one-quad authoritative construction.

The tests compile but were not executed in this Code + Build turn.

## Source authority

- tested parent: `a90f6b9de83dba4aeac359b2f63d735e2049b54e`;
- payload checkpoint: `5b9892bd9f3a3e51cf8af49b0d492450529ff765`;
- patch SHA-256: `b45802f0ede3cfd490fae5453ad60041e991a9f5ba2715e53566fd8db0fb79ba`;
- source commit: `364a20e12165af7dbfe213bb6d075e3fe25b1574`;
- payload cleanup: `591ada601843237a709d2d6e133a438ca403f042`;
- source-sync run/job: `31147985555` / `92771436461`;
- source-sync evidence artifact: `8982197509`;
- source-sync evidence SHA-256: `27c7f435a2c26b4b6c6df2ccc0ff258f297ddea129df657d1af2d795ba3a43e4`.

Final changed-file blobs:

```text
f04bc39c8b83f6ac673c19560296c2f4041c38c8  include/directional/geometry/SurfaceCellTracing.h
d604348b895c797ab2f5cf59885894cff3961fe6  src/geometry/SurfaceCellTracing.cpp
e4ab7f9aa236c6719a3b0ba13cd63a08dc4845a5  src/pipeline/RemeshPipeline.cpp
44f68df797e988c678194cb3ac3072081ff3424c  tests/SurfaceCellsPhase10Tests.cpp
```

## Build authority

The source was configured locally with GNU C++ 14.2.0, CMake, Ninja, Release static libraries, and `PRE_TEST` discovery. The approved seven targets built successfully:

1. `directional_core`
2. `directional_pipeline`
3. `directional_compiled_api_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_benchmarks`

The execution wrapper required incremental resumptions; Ninja retained completed objects and the final graph linked all five executables and two project static libraries. The build log records 111 compile/link actions across the resumed graph.

Artifact authority:

- artifact: `directional-g1-live-transition-local-build-artifact.zip`;
- SHA-256: `922be37c4ee849152dee40168e3e8604357af46189d6491124b7b83dce7ca741`;
- internal checksums: 45/45;
- executables: 5;
- project static libraries: 2;
- fixture/input files: 27;
- archived changed-file blobs: 4/4 exact.

## Turn boundary

No generated test, benchmark, discovery, CLI, GUI, help, or list command was executed. This turn makes no runtime-success claim for the plane, seam, or any other mandatory fixture.

## Next turn

Execute `.agents/Directional/Gate_1_Live_Transition_Artifact_Only_Test_Benchmark_Plan.md` from the exact artifact. Run plane first and seam second, then the remaining mandatory fixtures and non-overlapping default suites.

If that artifact-only turn does not materially advance Gate 1, the following mandatory turn is a design review or bounded producer replacement proof—not another local repair attempt.
