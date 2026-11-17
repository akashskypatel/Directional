# CB144 — ordered mandatory-edge terminal correction (Code + Build; 2026-11-17 UTC)

## Situation
- Turn: `M6-CP3-CB144-P13-EDGE-TERMINAL-OWNER-CORRECTION`.
- Frozen RA-244 correction committed as `7b0668d432ccb187c5a2d856494064f0bcb2fb95`.
- Compile-only [run 44002798772](https://github.com/akashskypatel/Directional/actions/runs/44002798772): `SUCCESS`.

## Background
- [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) accepted TB125 and assigned strictly ordered multi-cut edges to A2a′ `build_arcs`.
- Frozen 371-line [patch](Architecture_M6_CP3_CB144_P13_Edge_Terminal_Ordered_Split_Exact.diff), SHA-256 `081fcb5b96aff08824a661f985c40e3ab3304f3a6b218a1d14f1740df20de122`.

## Assessment
- Changes are limited to `src/geometry/EmbeddedGraphTopology.cpp`, `.h`, and `tests/FieldAlignedCurveNetworkTests.cpp`; exact changed-path comparison passed.
- Exact rational ordering makes N terminal cuts into N + 1 positive mandatory edge pieces. Equal parameters remain rejected. The rotation helper follows the low-to-high orientation for middle pieces.
- New row 951 `MandatoryEdgeTerminalSplit.SplitsAtOrderedDistinctCutsAndRejectsAmbiguousOnes` is compiled only; its assertions have not been executed.
- Eight approved targets: `all eight compiled and linked`; GMP and GMPXX: `GMP exact backend with libgmpxx.so and libgmp.so on the link command`; `runtimeExecution=false`.
- Immutable artifact `14293047782`, outer SHA-256 `638eaf00618283551bbec607c1f9484447d96d0bb5000f5ad5df7870d42af929`; internal hashes `28/28 passed`.
- Transport patch SHA-256 `22b9304038392dd10470b2fbb67bb86fa5a02af54c7232466406b7e4cfbfa740`; [apply run 44002567694](https://github.com/akashskypatel/Directional/actions/runs/44002567694) succeeded; Drive staging file retired.

## Recommendation
- Exactly next separate turn: `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-EXEC`. Use RA-244 §5's 951-row manifest (membership 1,032) and three-case census. Do not rebuild or run it in CB144.
- Preserve stable 66/17/49, debt 1, deferred 81 and CP2 491/491; CP3/selector497 unpromoted; `chainRimSchedules=false`. O42/O43/C3 remain open; O44/C1 are closed. PR #8 remains draft and unmerged.
