# CB-221 exact manifest and TB-EXEC-196 contract (2026-11-28 UTC)

Authority:
- [unequal-side DEFN](../Architecture_M6_CP3_DEFN_P13_A4_Unequal_Side_Construction_20261128.md) UC1–UC5;
- [TB-REV-195 adv.](../Architecture_M6_CP3_TB_REV_195_Adversarial_Review_20261128.md) GG2, GG4;
- DESIGN §4.9; DEFN-65C A4D2 item 3.

CB-221 is Code + Build only:
- apply exactly one diff;
- compile the eight GMP/GMPXX targets with `runtimeExecution=false`;
- STOP on any hash, path, patch or compile mismatch, and do not adapt.

## `M6-CP3-CB-221-P13-FOUR-SIDED-DISC-QUADRANGULATION` — pure combinatorial construction, compile only, not wired

Diff [`Architecture_M6_CP3_CB221_P13_Four_Sided_Disc_Quadrangulation_Exact.diff`](../Architecture_M6_CP3_CB221_P13_Four_Sided_Disc_Quadrangulation_Exact.diff): SHA-256 `2da0eb50a18f0dd38c730a8bc06f07706123c58235670553dfe4670f06a905cd`, 29,628 B, +644/−0. It applies on the CB-220 source.

| Path | Preimage SHA-256 | Postimage SHA-256 |
|---|---|---|
| `CMakeLists.txt` | `25f2fd0a7ef5c05c6fddc5bfad84dcbe1686a7680904aaf6ddb03287c32a7251` | `3808906189f32167f7c70c2c965e9b6aeb3a34fc39cfd61cf41435d452ea1cd4` |
| `cmake/DirectionalTests.cmake` | `50c9f93861add728d4617b062d84e42a4188df9d3e787e648583e84afb12dd80` | `c9a58f035050cbc9280f00aa68742bc3183320a06e8baa9be2373d984fcd2675` |
| `include/directional/geometry/FourSidedDiscQuadrangulation.h` (new) | — | `33e5661bef66a0a3b324e99c5dab6e3403be1384b32c5a4c37d30d4fc5933394` |
| `src/geometry/FourSidedDiscQuadrangulation.cpp` (new) | — | `07702b42733c227dc03b25d2de9cc74d5c2a1919a7b721773ba96dabdc6e24e3` |
| `tests/FourSidedDiscQuadrangulationTests.cpp` (new) | — | `7a8c094f27638e7dfdf4dc875819412a188d8214c939dee2c524f7288149cd8b` |

Content: `quadrangulate_four_sided_disc(std::array<std::size_t, 4>)` returns a `FourSidedDiscQuadrangulation` or a `FourSidedDiscQuadrangulationFailure` (`OddBoundary`, `NonPositiveSide`, `SideBeyondSizeBound`, `OutsideConstructionDomain`). The domain and the construction families (grid; pentagon–triangle) are defined by UC4. The CMake hunks only add the new files to the core library and the completion test binary. No production caller is added.

Verification: independent apply and reverse, hashes, syntax check with 0 errors and 0 warnings in the new files, no plan identifiers, and an independent script that reproduces the counts 5000 / 100 / 2200 from the C++ predicate.

## `M6-CP3-TB-EXEC-196` — full gate on the CB-221 package

**Inputs:**
- the CB-221 package;
- harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`;
- the **1019-row manifest** `Architecture_M6_CP3_CB221_TB196_Four_Sided_Disc_Full_Gate_Case_Manifest.tsv`, SHA-256 `6c8be9c29548a346d97bcd2fb82f1b30cdc6c72f18e4da1806c02865cb29833b`. Its header plus rows 1–1015 equal the CB-220/TB-EXEC-195 manifest `34a4e864…b821` byte for byte. It appends four GUARD rows (1016–1019) on binary `directional_surface_cell_completion_tests`;
- deferred `fd433f54…64ce` (81), so membership is 1100;
- comparator TB195 result `15259492817` (ZIP `f2fb104ac182cc24f1f8d6f68116eeb0fcb6d0e95f166c73d6a322aadd8f2a4b`).

No rebuild, retry, timeout substitution or V5.

**Comparisons:**
- All 1019 rows must PASS.
- Rows 1–1015 (row 858 included) must be N1–N3-equal to TB195. CB-221 changes no existing source, so any difference is STOP.
- Rows 1016–1019 must PASS.

**Predictions.** A failure falsifies UC4. Record the failing input and check; never repair.

**Not allowed:** production wiring, A3 count changes, sliver deletion, B1 or fallback repair, dispatch or veto change, promotion of CP3/497/D0/H4.
