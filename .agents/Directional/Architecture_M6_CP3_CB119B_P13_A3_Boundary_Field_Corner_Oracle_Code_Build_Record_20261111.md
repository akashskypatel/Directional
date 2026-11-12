# CB119B boundary field-corner oracle — Code + Build record (2026-11-11)

## Situation

**Compile-only complete.** The previous TB100 result remains 937/938 until the separately authorized corrected runtime gate. No runtime acceptance is asserted.

## Background

- Authoritative turn: `M6-CP3-CB119B-P13-A3-BOUNDARY-FIELD-CORNER-ORACLE`; base `e31595097e70f498b7df99e6b1e1851d254a1bbb`.
- Exact changed source: `d47b7c24b11cfb568d4ffce971590b8e5f966dc4`, one path `tests/SurfaceCellsPhase10Tests.cpp` (+53/-2).
- Patch SHA-256 `e7e0bc1bb0eae0387b072fa465bb9f5187f5746a766cf10d8040907743334524` (local preserved copy). No source, fixture, atlas, selector or workflow changes.

## Assessment

- Test 938 independently derives original source-mesh boundary endpoints, then intersects them with configured source hard-feature edges. Atlas `HardFeature` barriers must match those configured edges and prohibit adjacency.
- Plain eight-corner control and hard-rail 12-corner expectation remain exact. Both face-row permutations and scoped side-start assertions remain.
- [CB119B compile run](https://github.com/akashskypatel/Directional/actions/runs/42953097338); [artifact 13826405755](https://github.com/akashskypatel/Directional/actions/runs/42953097338/artifacts/13826405755); ZIP SHA-256 `a94196c1276a976618db161478d2e43cfc49f2d1a6977b54a74725f8dac2d667`.
- The eight required targets compiled with GNU Multiple Precision (GMP/GMPXX). Compile package verification is recorded with the run evidence. No test or benchmark executed.
- CP2 491/491 accepted; stable 66/17/49, debt1, deferred81 unchanged. CP3 and selector497 unpromoted.

## Recommendation

- Next `M6-CP3-TB100B-P13-A3-BOUNDARY-FIELD-CORNERS-CORRECTED-GATE-EXEC`: immutable 938-row full gate plus existing three-case census; never rebuild within that turn. An independent Review must adjudicate the result before CB120.
