# CB50F RP-01 — C1 factory hard-rail cover (2026-10-29)

- **Turn:** `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` — Code + Build, compile only.
- **Authority:** [RA-169.6 and .11](Architecture_M6_CP3_TB49_REV_Closeout_C1_Rail_Cover_DEFN_Patches_20261028.md); successor sequence [RA-170.4](Architecture_M6_CP3_TB49_REV_Reaudit_P1_O4_DEFNs_E2_Site_Pins_OffGate_Census_20261028.md).
- **Exact patch:** P4 SHA-256 `c8af43a28a7aa694d8cb2c43d461773061b34f2ba811649509d3def95127a426`, applied verbatim with no hand edits.
- **Numstat:** `13 4 src/geometry/SurfaceCellTracing.cpp` and `52 0 tests/SurfaceCellTransitionQuotientTests.cpp`, exactly two touched paths; GitHub comparison verified.
- **Semantic source:** `b8c07a6f24664e0de70026951c9ab3dd408d8f80`.
- **GMP compile:** [run 40903589111](https://github.com/akashskypatel/Directional/actions/runs/40903589111); eight established targets compiled and linked.
- **Immutable package:** artifact `12910262428`, ZIP SHA-256 `3956be92b061b6a9df81cba1a54e62604a1eaf1639f2c6011d865791346913d9`, `28/28` package members verified; GMP/GMPXX linked; `exactArithmeticBackend=GMP`, `runtimeExecution=false`.
- **No Directional tests, benchmarks, or binaries executed** in this CB turn. Compile success is not selector or semantic acceptance.
- **Frozen:** CP2 491/491 accepted; TB49 504/0 reviewed candidate; selector497 unpromoted, RP-01 still open; stable 66/17/49, debt 1.
- **Next:** `M6-CP3-CB51-RP01-P1B-NETWORK-OWNER-WITNESS`, exact P5 `a610f39b93970da7bd50a463427957d2b1e6eaa5455a4b0511d9770b55efd43c` (separate compile-only turn).
