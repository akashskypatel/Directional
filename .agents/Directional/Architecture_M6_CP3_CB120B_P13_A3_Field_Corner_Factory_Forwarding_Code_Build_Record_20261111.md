# CB120B factory field-corner forwarding — Code + Build (2026-11-11)

## Situation

CB120B changed the chained baseline input factory and compiled eight approved targets. The separate TB101B runtime has not started.

## Background

- Canonical turn: `M6-CP3-CB120B-P13-A3-FIELD-CORNER-FACTORY-FORWARDING`. Source snapshot base `4aebd4a989b122d39af0d5e33a2789106239276a`; verified 5455/5455 file hashes.
- The three source paths are `include/directional/geometry/GlobalConformityBaseline.h`, `src/geometry/GlobalConformityBaseline.cpp`, and `tests/SurfaceCellsPhase10Tests.cpp`.
- Applied code commit [`5e603a239d9d7519668b9c42cb3c2b6e8f16d2f8`](https://github.com/akashskypatel/Directional/commit/5e603a239d9d7519668b9c42cb3c2b6e8f16d2f8); [Drive apply run 43003912737](https://github.com/akashskypatel/Directional/actions/runs/43003912737); patch SHA-256 `3bd4555f863e54e604a67b9684b4db3a42913c3773b7963940f544b13182d0c9`.

## Assessment

- The factory forwards optional authoritative source-vertex field corners to the existing stop-node helper. Existing callers retain default-empty behavior.
- The new focused test asserts existing-corner equivalence, a new side stop, duplicate invariance, and forward/reverse source-face row behavior. It has **not** been executed in CB120B.
- [GMP/GMPXX compile run 43004287273](https://github.com/akashskypatel/Directional/actions/runs/43004287273); [package 13848350912](https://github.com/akashskypatel/Directional/actions/runs/43004287273/artifacts/13848350912); ZIP SHA-256 `ad7ced00acc60c3da2ffe5b051d0cc929a8f509a7591ca6274d022db66d80e7c`. Eight targets and package checksums verified. `exactArithmeticBackend=GMP` and `runtimeExecution=false`; no tests or benchmarks executed.
- The source-boundary product is not wired into production. No census, full gate, selector497/CP3 promotion, or D4/D5 production switch. CP2 491/491 accepted; stable 66/17/49, debt 1, deferred 81 unchanged. O39 exact shared branch authority remains required before O36.

## Recommendation

Next separate artifact-only turn: `M6-CP3-TB101B-P13-A3-FIELD-CORNER-FACTORY-EXEC`. Run focused factory test on this immutable compiled package; do not rebuild. A mismatch requires independent Review before further code work.
