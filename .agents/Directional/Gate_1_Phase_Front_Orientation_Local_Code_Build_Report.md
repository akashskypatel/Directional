# Gate 1 Phase-Front Orientation — Local Code + Build Report

## Status

The Gate 1 orientation/direct-cell implementation was compiled successfully and subsequently validated by the exact artifact-only test turn.

This report is retained as the current build/package authority for the artifact that passed Gate 1.

## Source authority

- uniform phase-front source commit: `4842911b6134c60410c92496d85d1152164a73c7`;
- orientation/direct-cell source commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- payload cleanup commit: `54a79a17f48bd3974367c3e043507d0550fb8daa`.

Final verified blobs:

```text
074bd7692b95202a9f6733cd58d5c958d30845b9  include/directional/geometry/SurfaceCellTracing.h
6f3aa122fc9ed9faed19b37ad59a1124be68b4e5  src/geometry/SurfaceCellTracing.cpp
056d9d533b4885a9df78e45b279b1a41a153ad3a  src/pipeline/RemeshPipeline.cpp
56da480a41f7d96ac5bd4470202e3e49a9eef745  tests/SurfaceCellsPhase10Tests.cpp
c95f27211394de1c238649062ab4d173f4bfe220  tests/AdaptiveTargetSizePhase12Tests.cpp
```

## Build authority

- compiler: GNU C++ 14.2.0;
- CMake: 3.31.6;
- Ninja: 1.12.1;
- configuration: Release, static, `-O2 -DNDEBUG`;
- GoogleTest discovery mode: `PRE_TEST`;
- compiler jobs: 2;
- approved targets: **7/7**;
- wall-clock interval including wrapper resumptions: **577 seconds**.

Compiled targets:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

## Package authority

- archive: `directional-g1-orientation-local-build-artifact.zip`;
- archive SHA-256: `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`;
- internal checksums: **45/45**;
- package closure: five executables, two static libraries, 26 fixture/input files.

No generated project binary, test, benchmark, discovery command, CLI, GUI, help, or list command was executed during Code + Build.

## Implemented Gate 1 contracts

- four distinct authoritative corners and ordered side continuity;
- consistent source component and local sheet;
- nonzero loop normal and source-normal-consistent winding;
- transactional reversal of the complete cell cycle;
- one filled cell per directed edge and one reciprocal opposite edge or explicit exterior;
- deterministic direct-vertex canonicalization from integer lattice coordinates;
- one accepted four-sided phase-front cell maps to one quad-domain cell;
- direct lineage and boundary-loop construction;
- fail-closed `tracing/phase-front-materialization` boundary;
- bypass of generic completion for valid authoritative phase-front cells;
- correction of two stale non-direct producer tests without weakening direct acceptance or validators.

## Subsequent runtime validation

The exact package passed the plane direct gate:

- 64 authoritative cells → 64 pure output quads;
- 81 vertices;
- zero strict validation failures;
- output origin `CompletedSurfaceCells`;
- no fallback or recovery;
- stable output hash `730caeae49ec872c` across three processes.

See `.agents/Directional/Gate_1_Phase_Front_Orientation_Artifact_Only_Test_Benchmark_Report.md` for runtime evidence. Gate 2 is now active.
