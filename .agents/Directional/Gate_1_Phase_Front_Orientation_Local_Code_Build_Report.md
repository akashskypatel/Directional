# Gate 1 Phase-Front Orientation and Direct-Cell Materialization — Code + Build Report

Date: 2026-08-06

## Turn declaration

```text
Active design gate: Gate 1 — Uniform phase-front plane
Earliest failing fixture: Plane
Missing design contract: source-normal-consistent four-sided cell orientation and one-to-one direct-cell materialization
Smallest general implementation change: validate and orient complete phase-front cycles, then directly materialize accepted four-sided cells
Observable material-progress condition: invalid cells fail before completion, or valid cells preserve one phase-front cell to one quad-domain cell
Explicitly deferred work: Gates 2–7, later fixtures, adaptivity, features, performance, cache work, and unrelated cleanup
```

## Source synchronization

The previously compiled uniform phase-front layer was synchronized first:

- source commit: `4842911b6134c60410c92496d85d1152164a73c7`;
- all five expected Layer 1 blobs matched exactly.

The orientation/direct-cell implementation was then applied as a separate exact layer:

- incremental patch SHA-256: `cb06890449bc56b2e5bc25d7033260bc9c180deccb38b545bd5ab6e56efff9ab`;
- source commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- payload cleanup commit: `54a79a17f48bd3974367c3e043507d0550fb8daa`;
- source-sync run/job: `31135783371` / `92734653996`;
- evidence artifact: `8977861759`.

Final source blobs:

```text
074bd7692b95202a9f6733cd58d5c958d30845b9  include/directional/geometry/SurfaceCellTracing.h
6f3aa122fc9ed9faed19b37ad59a1124be68b4e5  src/geometry/SurfaceCellTracing.cpp
056d9d533b4885a9df78e45b279b1a41a153ad3a  src/pipeline/RemeshPipeline.cpp
56da480a41f7d96ac5bd4470202e3e49a9eef745  tests/SurfaceCellsPhase10Tests.cpp
c95f27211394de1c238649062ab4d173f4bfe220  tests/AdaptiveTargetSizePhase12Tests.cpp
```

All temporary Gate 1 patch/build payloads were removed only after both source layers and their expected blobs were verified.

## Implemented contracts

### Phase-front cell validity

- four distinct authoritative corners;
- ordered side endpoint continuity;
- consistent source component and local sheet;
- nonzero loop normal and valid quad-loop classification;
- source-normal-consistent winding;
- transactional reversal of the complete cycle when winding is opposite;
- one filled cell per directed edge and exactly one of reciprocal opposite edge or explicit exterior.

### Direct-cell materialization

- authoritative integer lattice coordinates canonicalize direct vertices;
- repeated lattice coordinates must agree in position, component, and sheet;
- one accepted four-sided phase-front cell becomes one output quad-domain cell;
- complete vertex and face lineage is emitted;
- the authoritative path bypasses generic patch completion that previously expanded 65 phase-front cells into 409 quads;
- invalid orientation, incidence, component, sheet, or ownership fails closed at `tracing/phase-front-materialization` before completion.

### Test integrity corrections

- the planar backend test now distinguishes direct success from recovery behavior and keeps recovery disabled for the direct proof;
- the adaptive target-size diagnostic test no longer requires the producer to fail when its intended diagnostics are populated;
- no direct acceptance assertion or validator was weakened.

## Local compile authority

Environment:

- GNU C++ 14.2.0;
- CMake 3.31.6;
- Ninja 1.12.1;
- Release `-O2 -DNDEBUG`;
- static libraries;
- GoogleTest discovery mode `PRE_TEST`;
- two compiler jobs.

Result:

- configure: success;
- approved targets: **7/7**;
- Ninja graph completed and `ninja -n` reported no work to do;
- wall-clock interval including incremental wrapper resumptions: **577 seconds**;
- packaged executables: **5**;
- packaged libraries: **2**;
- packaged fixture/input files: **26**;
- internal artifact checksums: **45/45**.

Artifact:

- `directional-g1-orientation-local-build-artifact.zip`;
- SHA-256: `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`.

## Compile-only boundary

No generated project binary was executed. No test, benchmark, GoogleTest discovery, CLI, GUI, help, list, or project runtime command was executed.

## Runtime status

This turn makes no runtime-success claim. The latest runtime authority remains the preceding artifact-only report: plane failed with 352 traces, 65 arrangement cells, 409 quads, and `completion/output-validation:FlippedFace`.

## Next turn

Execute `.agents/Directional/Gate_1_Phase_Front_Orientation_Artifact_Only_Test_Benchmark_Plan.md` directly from the new artifact.

The first required observation is whether the plane now:

1. passes direct acceptance with one-to-one phase-front cell materialization; or
2. fails earlier at `tracing/phase-front-materialization` under a truthful orientation/incidence invariant; or
3. reaches a later strict-validation boundary without generic completion expansion.
