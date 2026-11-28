# CB-180 — staged uncut-owner census receipt (Code + Build only)

## Situation

The frozen 68-line test-only diagnostic receipt was applied and compiled. This turn did not execute Directional tests, benchmarks, or binaries. The production path is unchanged.

## Background

- Authority: [TB-REV-162 adversarial review](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md) (X1–X6); frozen [CB-180 diff](Architecture_M6_CP3_CB180_P13_Staged_Uncut_Owner_Census_Receipt_Exact.diff), SHA-256 `b5161a4659f8a68bfaea6a6e982462e6e8f007de93bf373936859f22776d2b32`.
- Exact snapshot source: `ed6eaf8d813522ac64826ccfb1b2ccb3881c69d6`, [snapshot 45010329680](https://github.com/akashskypatel/Directional/actions/runs/45010329680), archive `14749841146`, 5,725/5,725 source hashes verified.
- Single semantic path: `tests/FieldAlignedCurveNetworkTests.cpp` (+68/−0). Preimage SHA-256 `98154a1fdffecf748d52fc3bef1c3923b3e350794a8c367ddafeeaa29ef9665e`; postimage SHA-256 `fedadbd318ad4754e7790c4232ccca055d8f97c64159c908dc7475aab7e82ef1`. Git blob `78868b742d3a1be3088a5ce69d40a704fe93bb8f`.
- Verified transport patch SHA-256 `e1fc3e1d707d03fbea3c99603c8bd9c2d4d95a6f3e2d8f511a702a6fb600ed5b` (5,075 B). [Patch apply 45010611979](https://github.com/akashskypatel/Directional/actions/runs/45010611979), result artifact `14749866542`; exact semantic commit `23d66f60d87329e178d9fc3963489cbef088555e`. Temporary Google Drive staging file was deleted by owner after successful push.
- Mandatory GMP/GMPXX compile [run 45010876980](https://github.com/akashskypatel/Directional/actions/runs/45010876980), eight approved targets, package artifact `14749353214` (ZIP SHA-256 `fdcba4479936b7e8b1d3ee955bd1ac069715f4fa513ec874bc4e535a8872a668`), `runtimeExecution=false`. Compilation is not a runtime acceptance result.

## Assessment

Row 979 now prints each unavailable component's source-edge owner census, opposite-face owner, interior-arc orbit sides, vertex transits and all arc end nodes. Existing assertions, the 979-row manifest, production source, selector and stop behavior are unchanged. The owner repair R-a versus H5 terminal-slit defect remains undecided until TB-EXEC-163.

The last runtime result remains TB162: 979/979 PASS, CP2 491/491, TB161 census 3/3. No CP3/497/D0/H4 promotion; stable 66/17/49, debt1, deferred81 unchanged.

## Recommendation

Next turn only: `M6-CP3-TB-EXEC-163-P13-STAGED-UNCUT-OWNER-CENSUS-RECEIPT-FULL-GATE`. Run the verified CB-180 package without rebuilding. Use unchanged [TB161 manifest](gates/Architecture_M6_TB161_P13_Staged_Slide_Entry_Stop_Downstream_Receipt_Full_Gate_Case_Manifest.tsv), SHA-256 `e15d616c9af2855b803dea8b5cfc4f5a0529f129c41df0c4fb0131e4ff4e7e8a`. Require 979/979, CP2 491/491, rows 1–978 equal TB162 under N1–N3, and all 60 prior row 979 lines preserved after removing only the five approved new prefixes. Publish every new line, do not run the production census, and do not change source, tests, manifests or selectors. TB-REV-163 decides R-a, H5, or a typed stop.
