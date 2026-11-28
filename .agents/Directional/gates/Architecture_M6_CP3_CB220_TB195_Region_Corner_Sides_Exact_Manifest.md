# CB-220 exact manifest and TB-EXEC-195 contract (2026-11-28 UTC)

Authority:
- [corners DEFN](../Architecture_M6_CP3_DEFN_P13_A4_Disc_Corners_20261128.md) CR1–CR4;
- [TB-REV-194 adv.](../Architecture_M6_CP3_TB_REV_194_Adversarial_Review_20261128.md) FF2–FF4;
- DESIGN §4.11 and Amendment 30; DEFN-65C A4D2 item 2 and A4D5.

CB-220 is Code + Build only:
- apply exactly one diff;
- compile the eight GMP/GMPXX targets with `runtimeExecution=false`;
- STOP on any hash, path, patch or compile mismatch, and do not adapt.

## `M6-CP3-CB-220-P13-REGION-CORNER-SIDES` — A4 product slice, compile only, not wired

Diff [`Architecture_M6_CP3_CB220_P13_Region_Corner_Sides_Exact.diff`](../Architecture_M6_CP3_CB220_P13_Region_Corner_Sides_Exact.diff): SHA-256 `35a164a8b4490ae1e6ab29f480745d49f8bbd0f79db84c0334d94f87bb7141fa`, 22,405 B, +434/−0. It adds the new `src/geometry/RegionCornerSides.cpp` and one `CMakeLists.txt` line. It applies on the CB-219 source.

| Path | Preimage SHA-256 | Postimage SHA-256 |
|---|---|---|
| `CMakeLists.txt` | `7b3eadf6b73a30510dff503c45c2f1b46954c70cc0dc0f6eec8bc98b09c311ab` | `25f2fd0a7ef5c05c6fddc5bfad84dcbe1686a7680904aaf6ddb03287c32a7251` |
| `include/directional/geometry/GlobalConformityBaseline.h` | `8a7e7494bbf2ce0a5a9788aa0e19da4955ea9106dad033c6eb6f33edbcdea4ed` | `4d9d8edababa0dc5a4a042bbf7dfd10e8d7b98c30f60df353459df533d116627` |
| `src/geometry/RegionCornerSides.cpp` (new) | — | `e590f1e57be814e4f67573ac66516ea04d6b958652cbeb54b5122f6cee20500f` |
| `tests/SurfaceCellTracingDisplayTests.cpp` | `730c06d9504e07c59050986fdf3ed27133a33d7a2e21d5f326906d3c30b9613e` | `f6265aac642e0cd2a69fa33a8e039e256f56935cecc91ff8acd7242a88f6ee19` |

Content: `build_region_corner_sides(topology, network, schedules)` returns per-region corners (`RegionBoundaryCorner {node, scheduleSide, quarterTurns}`) and corner-delimited sides (`RegionCornerSide {firstScheduleSide, scheduleSideCount, count}`), or one of six typed failures: `topology-plan-mismatch`, `network-mismatch`, `unsupported-arc-kind`, `unsupported-contact-node`, `port-not-found`, `turning-not-four-quarter-turns`. The API is declared beside the schedule types in `GlobalConformityBaseline.h`. Row 858 receipts are emitted by the display test. No production caller is added. New tests: `RegionCornerSides.PrescribedSphereRegionsTurnAtFourQuarterTurnCorners` and `RegionCornerSides.ReversedPrescribedSphereWalkIsRejectedByItsTurning`.

Verification: independent apply and reverse, hashes, syntax check with 0 errors, identical location-stripped warning multisets for `GlobalConformityBaseline.cpp` (20) and the display tests (24), new file with 0 errors and no warning inside it, no plan identifiers in code.

## `M6-CP3-TB-EXEC-195` — full gate on the CB-220 package

**Inputs:**
- the CB-220 package;
- harness `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`;
- the **1015-row manifest** `Architecture_M6_CP3_CB220_TB195_Region_Corner_Sides_Full_Gate_Case_Manifest.tsv`, SHA-256 `34a4e86406f043739c56eec6bc104615bee05fc08960be2dc6ae4a303b43b821`. Its header plus rows 1–1013 equal the CB-218/TB-EXEC-193 manifest `b910f2a9…2fc2` byte for byte. It appends two GUARD rows: 1014 (`PrescribedSphereRegionsTurnAtFourQuarterTurnCorners`) and 1015 (`ReversedPrescribedSphereWalkIsRejectedByItsTurning`), both on the binary of row 858 (`directional_compiled_api_tests`);
- deferred `fd433f54…64ce` (81), so membership is 1096;
- comparator TB194 result `15255025606` (ZIP `5fedd54ddf3416bf1cdb475a8e53206ab6382fcd75e9ea8b4a3bfebb4f8d99b4`).

No rebuild, retry, timeout substitution or V5.

**Comparisons:**
- All 1015 rows must PASS.
- Rows 1–1013 except 858 must be N1–N3-equal to TB194. Any difference is STOP.
- Row 858 must equal the TB194 bytes with only the new `RegionCornerSides` lines inserted at the printer's insertion point. Insertion point (from the diff: `print_corner_sides("Sphere", …)` and `print_corner_sides("Genus", …)` run immediately after `print_arrivals("Genus", …)`): every byte of TB194 row858 through the end of the `GenusSingularityArrivals …` line must be equal; then exactly 10 new lines follow — one `SphereRegionCornerSides …` summary, eight `SphereRegionCornerSide …` lines, one `GenusRegionCornerSides …` line; then the remaining TB194 suffix must be N1/N2-equal.

**Predictions.** A mismatch is STOP for review, never a repair.
- `SphereRegionCornerSides built=1 regions=8 corners=32 sides=32`.
- Eight `SphereRegionCornerSide` lines, each with all corners at gap 1, and side counts equal to the CR2 table, with region ids as in TB194's schedules: r0 30,35,35,32; r1 31,35,35,31; r2 1,32,1,32; r3 30,32,35,35; r4 1,32,1,32; r5 32,30,35,35; r6 32,35,35,30; r7 35,31,31,35.
- Genus summary measured: `built=1 …` or `built=0 failure=unsupported-arc-kind`. Any other failure name is STOP.
- Rows 1014 and 1015 PASS.
- A `turning-not-four-quarter-turns` or `port-not-found` on the sphere falsifies CR1's orientation or port mapping.

**Not allowed:** activating corners or the schedule in production, A3 count changes, sliver deletion, B1 or fallback repair, dispatch or veto change, promotion of CP3/497/D0/H4.
