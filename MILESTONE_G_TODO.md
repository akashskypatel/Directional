# Milestone G Production Readiness TODO

Last updated: 2026-08-07 UTC

## Current gate

G0 truthful authority [passed] → G1 uniform phase-front plane [passed] → G2 cross-chart / close-sheet isolation [passed] → **G3 cylinder / periodic holonomy [active; compile-valid, runtime verification pending]** → G4 topology/singularities → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## G3 Code + Build complete

The bounded periodic-annulus producer is implemented and compile-verified.

Source authority:

- source commit `56f823273cad041a01ebb4d0772c3265ff248f4a`;
- patch SHA-256 `d93cc65f86ea402111af3b409e73d08c72be37fdee1f2758538033fc7525802f`;
- changed blobs:
  - `SurfaceCellTracing.h` `931669018a986096cf78d66a2aed9de5aa8e0fe1`;
  - `RemeshDiagnostics.h` `a51215982318e77581efa4fa7887d0406a9d4bf0`;
  - `SurfaceCellTracing.cpp` `b1a2c6d4051cc17b79e342170285d69552cad16d`;
  - `RemeshPipeline.cpp` `7674ed3fe40c5f43c668c931c01b59f6c7829df8`;
  - `DirectionalBenchmark.cpp` `18955ca8ef72812c9c70ed522bb578409e6a176f`;
  - `SurfaceCellsPhase10Tests.cpp` `bccd6abf3e31b8096c471c515b1949d08dcfde59`.

Implemented contracts:

- annulus applicability derives from source topology and singularity-free state rather than fixture identity;
- deterministic source boundary/ring structure defines a cut-open intrinsic chart without world-space planarity;
- periodic holonomy is first-class `(quarter-turn rotation, integer lattice translation, ordered source route)` and the deterministic cut route is retained separately;
- duplicate/missing/incompatible holonomy fails closed with typed periodic authority;
- artificial-cut fronts use explicit `PeriodicFrontMerge` ownership rather than exterior-boundary or proximity semantics;
- only genuine annulus boundaries remain exterior in the bounded periodic front;
- materialization quotients duplicate cut-chart lattice vertices through exact periodic identity rather than Euclidean welding;
- holonomy contributes to structural hashing and diagnostics;
- five focused periodic regression sources were added and compiled, not executed.

The implementation is intentionally bounded to a canonical equal-cardinality ring annulus class. Runtime artifact validation must determine whether the exact production cylinder is handled correctly; compile success is not runtime proof.

## Build authority

Successful compile-only authority:

- run/job `31196268841` / `92925122791`;
- artifact `9001168379` (`g3-periodic-cylinder-code-build`);
- artifact SHA-256 `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`;
- detailed log artifact `9001167184`, SHA-256 `fdd873fe4e0980ddf8613bd04b3be8f795730928bd73844cd92aec75c41031a4`;
- recursive checksums **44/44 passed**;
- compile/link actions **111/111**;
- approved targets **7/7**;
- five executables, two project libraries, 27 fixture/input files packaged;
- no generated project binary/test/benchmark executed.

This is compile evidence only. G3 remains runtime-unverified.

## Passed-gate runtime authority

Latest executed artifact evidence remains:

- plane: direct valid `Produced`, 64 pure quads, hash `730caeae49ec872c`;
- seam: direct valid `Produced`, 64 pure quads, hash `5bdf34d7802e9fb0`;
- close sheets: direct valid `Produced`, 200 pure quads, two isolated components, hash `89b052762f52a5af`;
- cylinder: prior `NotApplicable`, 732 generic traces, zero arrangement/completion;
- no fallback/recovery on passed fixtures.

## Required next turn

Execute `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9001168379`.

Priority order:

1. verify artifact/source/patch/blob/checksum authority;
2. execute the five focused G3 periodic producer contracts;
3. preserve plane, seam, and close sheets mandatory regressions;
4. execute exact production cylinder as G3 acceptance;
5. prove first-class holonomy, reciprocal artificial-cut pairing, and no false exterior seam;
6. run bounded determinism and non-overlapping default suites;
7. observe bunny/vase only after the active G3 decision.

G3 closes only through direct deterministic strict-valid `Produced` cylinder output with correct periodic quotient/holonomy and retained G0–G2 successes. A new typed periodic `Rejected` result with zero generic substitution is material progress but leaves G3 active.

Do not broaden the next turn into torus/general genus, singularity topology, adaptivity/features, bunny/vase remediation, timing, or unrelated completion work.

Every completed turn ends with a new top-level PR #8 comment after all other repository writes.
