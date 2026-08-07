# Gate 2 Cross-Chart Transport and Mandatory Production Fixtures — Local Code + Build Report

**Date:** 2026-08-06  
**Turn type:** Code + Build  
**Active gate:** G2 — Cross-chart and close-sheet propagation  
**Earliest failing fixture:** `multi_face_seam__surface_cells`

## Purpose

Implement the first exact source-chart transport slice and replace a synthetic-only acceptance matrix with a mandatory mixed matrix that includes real closed and open-boundary production geometry.

This turn makes no runtime-success claim. No generated project binary, test, benchmark, discovery command, CLI, GUI, help, or list command was executed.

## Source authority

- Gate 1 orientation/direct-cell commit: `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`
- Gate 2 payload checkpoint: `aea10409c73c490b92f78760b73191641ef823c6`
- Gate 2 patch SHA-256: `512d2cda4f9799d5600af277b9d63bbce76ace334b076bb922e762d0059f1b9c`
- Compressed patch SHA-256: `29bd156ad17198b610614956489d50114d10ac96faf4b3bd907e8a09adcc712f`
- Gate 2 source commit: `21f081b330418a0f34709f61d857f54a03d2fd48`
- Payload cleanup commit: `98fe525bb46f348cddcad91b0525353796b9e061`
- Source-sync run/job: `31140198130` / `92748287591`
- Source-sync evidence artifact: `8979516674`
- Source-sync evidence digest: `9789218c72628dead864881838716a6b3fd9070eb0f277c32c2cadf71da1eaa4`

All 16 changed source, test, fixture, and manifest blobs were verified before the source commit.

## Mandatory production fixtures

### `bunny_1k_random.obj`

- SHA-256: `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`
- 502 vertices, 1,000 triangles, 1,500 edges
- one closed component
- zero boundary edges, non-manifold edges, degenerate faces, or repeated faces
- same geometric bunny as the prior fixture but with a different vertex/face permutation
- generated smooth cross field

This fixture protects irregular closed production geometry and ordering/permutation determinism. The suite asserts its topology so a simplified replacement cannot silently satisfy acceptance.

### `vase.off`

- SHA-256: `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`
- 1,274 vertices, 2,404 triangles, 3,677 edges
- one component and one open boundary loop
- 142 boundary edges
- zero non-manifold edges, degenerate faces, or repeated faces
- generated smooth cross field

This fixture protects curved open-boundary production geometry. Its topology is asserted before remeshing.

Neither fixture can pass through fallback, recovery, input return, fixture-name special handling, or relaxed validation.

## Mandatory direct matrix

1. plane
2. multi-face seam
3. close sheets
4. cylinder
5. `bunny_1k_random`
6. vase

All require requested/executed `SurfaceCells`, fallback `Fail`, recovery disabled, non-empty pure-quad `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

The ordered gate policy remains in force: a later complex fixture cannot conceal failure of an earlier analytic contract.

## Implemented Gate 2 slice

- `SurfaceTraceSegment` now carries source-chart identity and the exact source edge crossed to enter the segment.
- `LocalLatticeState` carries authoritative source-chart identity.
- The planar phase-frame constructor computes per-face local branch rotation relative to global lattice `+U`.
- Interior source transitions are validated against exact cross-field quarter-turn matching and reciprocal inverse transition metadata.
- Source charts are deterministic connected regions of equal transported branch orientation.
- Intrinsic source intervals carry local family/sign, chart, and transition-edge provenance.
- Missing, non-adjacent, ambiguous, or non-reciprocal transitions fail closed.
- Phase-front hashing includes the new chart and transition state.
- Gate 1 source-normal orientation and one-cell-to-one-quad materialization remain unchanged.
- Benchmark fixtures without prescribed fields can request a generated smooth cross field through production field extraction.

No implementation behavior branches on fixture names, paths, IDs, vertex counts, or face counts.

## Compile result

- GNU C++ 14.2.0
- CMake 3.31.6
- Ninja
- Release `-O2 -DNDEBUG`
- static libraries
- GoogleTest discovery mode `PRE_TEST`
- two compiler jobs
- compile/link actions: **95/95**
- approved targets: **7/7**
- wall time: **385.09 seconds**
- peak RSS: **1,529,528 KiB**

Approved targets:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

## Artifact

- Archive: `directional-g2-cross-chart-mandatory-fixtures-local-build-artifact.zip`
- SHA-256: `f5c2be0e2131dbce7a6460e3c61da2de57f7d256c00a5401ac6285d6a0145755`
- Internal checksums: **45/45**
- Five executables
- Two project static libraries
- 27 fixture/input files
- Exact patch, source snapshot without dependencies, compile commands, metadata, and logs

## Material-progress classification

This is constructive progress because exact chart/quarter-turn transport state is now first-class in the producer and the mandatory acceptance matrix includes two nontrivial production meshes. Runtime material progress remains unproven until the artifact-only turn executes the six mandatory cases.

## Next turn

Run `.agents/Directional/Gate_2_Cross_Chart_Mandatory_Fixtures_Artifact_Only_Test_Benchmark_Plan.md` without rebuilding or editing source, tests, fixtures, build logic, or validators.
