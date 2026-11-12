# CB120C field-corner census — Code + Build (2026-11-11)

## Situation

The frozen field-corner census test was added and compiled on eight approved targets. The four-case census and the full gate have not been executed.

## Background

- Canonical turn: `M6-CP3-CB120C-P13-A3-FIELD-CORNER-CENSUS`. Exact verified source snapshot base `032557eb333dae62f8a6829bb50cb87563b268d6`, 5,458/5,458 file hashes passed.
- Only `tests/SurfaceCellDesignAcceptanceTests.cpp` changed: 34 lines inserted, none removed. The historical CB120 exact diff supplied this test-only hunk; the earlier helper and factory slices remain unchanged.
- Applied source commit [`e1e5b17e94f189c88c74172e12dfd6ac93cc532b`](https://github.com/akashskypatel/Directional/commit/e1e5b17e94f189c88c74172e12dfd6ac93cc532b), [Drive apply run 43013333565](https://github.com/akashskypatel/Directional/actions/runs/43013333565), complete patch SHA-256 `939804d7259d7e166f4651e2eedf60e39b9577970b163f7663daa67b618e24c1`. The workflow verified the exact base, patch bytes, intended path and clean application. No source tests ran.

## Assessment

- The D4 census now computes field corners from the cross field and its transport atlas, constructs a stopped chained input, checks baseline construction and validation, and prints four `d4-corner` case records. The existing `d4-rim` record remains unchanged.
- [GMP/GMPXX compile run 43013777504](https://github.com/akashskypatel/Directional/actions/runs/43013777504), [artifact 13852160952](https://github.com/akashskypatel/Directional/actions/runs/43013777504/artifacts/13852160952), ZIP SHA-256 `17dfdcf06d33b312a282d1c6f3cce68223df7010dce367b04897e848a2e16e74`. Eight required targets compiled; `runtimeExecution=false`. No runtime test, benchmark, census or full gate was executed in CB120C.
- No new observed regression or production acceptance: CP2 491/491 remains accepted; stable 66 events, 17 categories, 49 recurrences, debt 1, deferred 81 are unchanged. CP3/selector497 and D4/D5 production remain unpromoted; O39 precedes O36.

## Recommendation

The exact next turn is `M6-CP3-TB101C-P13-A3-FIELD-CORNER-STOPS-FULL-GATE-EXEC`. Run the immutable 940-case gate and census against this package without rebuilding or changing source. Follow the separate independent Review gate. Do not start those tasks in CB120C.
