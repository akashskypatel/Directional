# M4-CP-SCALE-CB24 — S5 selector427 publication Code + Build plan

**Turn:** `M4-CP-SCALE-CB24`
**Type:** Code + Build, publication-only
**Runtime:** generated Directional runtime forbidden
**Input accepted authority:** package `10560828304` / source `e86206759a6a0f68afbf83d8f6abf9efbe7bd5ff` / selector426 **426/426**

## Goal

Publish the already-reviewed focused S5 identity into the append-only cumulative required-green selector without changing any semantic implementation or test authority.

The only new gate row is:

`M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`

## Frozen publication contract

1. Create `Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt` with exactly **427 LF rows**.
2. Its first **426** rows must be byte-for-byte identical to `Architecture_M4_CP_SCALE_CB12_Required_Green_Selector_426.txt` and re-hash to `41f4d559211375c11c8d1f8c9ccde2581db75819d9409366e8f2695b008b5114`.
3. Row427 must be exactly the S5 identity above, followed by one LF newline.
4. Expected selector427 LF SHA-256: `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.
5. Expected static owner census: **30 authority-kernel / 281 producer / 75 completion / 41 validation**.
6. Update `Required_Green_Selector_Manifest.md` only to publish this exact append and provenance. Do not rewrite historical selector rows.

## Allowed source surface

- `.agents/Directional/Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt` — new selector only.
- selector manifest and bounded CB24 compile/report/handoff documentation.
- temporary workflow/trigger files required by repository policy, removed before closeout.

No C++ product/test source, fixtures/rawfield, benchmarks, CMake semantics, accepted selector426 bytes, or earlier selectors may change.

## Static falsifiers before compile

STOP back to Review if any of the following is true:

- selector427 is not exactly 427 LF rows;
- first426 bytes/hash differ from accepted selector426;
- full selector hash differs from `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- appended row text differs from the reviewed S5 identity;
- owner census is not **30 / 281 / 75 / 41**;
- selector427 publication requires changing product/test/fixture/benchmark/CMake semantics;
- any proposal edits selector426 or rewrites history.

Run `git diff --check` and the repository's selector static validation before compile. Do not invoke any generated Directional executable.

## Mandatory compile/package

Use the repository GitHub compile workflow with mandatory GMP/GMPXX authority. Compile/package the accepted standard target set with the owner test target included. The package must record `runtimeExecution=false`, clean source state and executable modes; no test/benchmark runtime may execute.

Compile/package failure routes to the smallest bounded CB correction. A compile-green package does not grant cumulative S5 credit.

## Success condition and next evidence

CB24 succeeds only when selector427 is statically exact and immutable package compile evidence is GREEN with no generated runtime. Exact next after a green CB24 is artifact-only **`M4-CP-SCALE-TB13-EXEC`**: execute selector427 427/427 in exact file order, one fresh process per identity, zero benchmark execution, immutable pre/postflight, then mandatory `M4-CP-SCALE-TB13-REV` before cumulative S5 selector credit.
