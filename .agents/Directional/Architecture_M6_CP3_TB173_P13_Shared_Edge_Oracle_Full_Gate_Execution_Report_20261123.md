# TB-EXEC-173 — immutable shared-edge oracle full gate (2026-11-23 UTC)

## Situation

The frozen **996-case Test + Benchmark gate is REJECTED**: **989 PASS / 7 RED**. This is a completed runtime measurement, not an accepted production gate. Seven mechanical controls are still RED at rows **445, 652, 653, 656, 658, 660, 786**. New source-path oracle rows **995 and 996 both PASS**. No repair, retest, or source change is authorized by this result.

## Background — exact immutable authorities

- Canonical turn: `M6-CP3-TB-EXEC-173-P13-SHARED-EDGE-ORACLE-FULL-GATE`; branch `agent/surface_cell_quad/p5-recover-bridge-healing`, draft PR #8.
- CB-194 semantic and executable source: `fae9eb71bb5806d71901cc2ccb8c925201be0c0a`; GMP/GMPXX compile workflow `45173887503`, immutable package artifact `14820355596`, ZIP SHA-256 `817583b75f8d9a5f7b9e7300426756d1044d535e9f63ebf3ec5d5cf88fe45ec6`. Package 28/28 file checksums valid; package metadata `runtimeExecution=false`. No rebuild occurred in TB-173.
- Frozen manifest `gates/Architecture_M6_TB173_P13_Shared_Edge_Oracle_Full_Gate_Case_Manifest.tsv`, SHA-256 `b54de0b28dc646b465daae0d40dd7874f550567fb904647c7dff36a4f2e2ff6e` (996 rows); unchanged deferred ledger `gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv` SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 deferred).
- [TB-173 workflow](https://github.com/akashskypatel/Directional/actions/runs/45180338549) dispatched at commit `52d8706a5df0cfcf70563c3e5b8e97fb067dbdde`; result artifact **`14821438542`**, immutable ZIP SHA-256 **`22851acd9b27eb56ff504f038f9e9761f5b9d07fda854682da512f5022bb223d`**. Both schema checks and dispatcher parse passed; test runtime finished with semantic gate exit `90` / `ValueError: required controls failed`; compile, configure, relink, benchmark, Drive apply and noop did not run; mailbox publication succeeded.
- Previous rejected TB-172 [run `45149928894`](https://github.com/akashskypatel/Directional/actions/runs/45149928894), result artifact `14805479282`, ZIP SHA-256 `e9ddc7fd80d3e33b25b18901c783fbb21ec2eaf5c1b86438f887e93cee03edbc`, 987/994 with the same seven RED. Latest accepted TB-169 remains 993/993, CP2 491/491.

## Assessment — independently checked artifacts and comparisons

| Measurement | TB-172 | TB-173 |
|---|---:|---:|
| Planned / executed | 994 / 994 | 996 / 996 |
| PASS / RED | 987 / 7 | 989 / 7 |
| Abnormal, missing, skipped, duplicate | 0 each | 0 each |
| Required-control violations | 7 | 7 |
| Unexpected PASS / later-positive RED / incorrect RED site | 0 each | 0 each |
| Membership (gated + deferred) | 1075 (994+81) | 1077 (996+81) |
| ZIP internal checksums validated | 1996/1996 | 2000/2000 |

- **Exact prefix preservation:** every original row 1–994 has the same verdict and complete normalized raw log; an independent full per-row comparison found **zero differences** using only N1 (Google Test elapsed duration) and N2 (line endings). No N3 complete-diagnostic-record reorder or assertion-site allowance was necessary. Original ledger outcomes are unchanged. There is no new off-row drift.
- **New positive controls:** row 995 `ExactSourcePathSharedEdges.TracesRunningOneEdgeChainBothWaysShareEveryEdge` PASS; row 996 `ExactSourcePathSharedEdges.TouchingAndCrossingPathsShareNoEdge` PASS. These prove the isolated helper's two tested cases, not production wiring or resolution of mechanical region ownership.
- **Mechanical failure remains:** row 652 still publishes `RegionElectedCutComponentEmpty`; the other six accepted-green controls still fail on missing production topology plans, including CP2 row 445. CP2 candidate remains 490/491 and cannot replace its accepted 491/491 baseline. The existing A2a source-network co-traced digon/arrival-port issue from TB-REV-172 remains an independently reviewed hypothesis; TB-173 does not test a repair and supplies no new producer decision.
- **Staged-only result:** row 979 is a passing measurement test but still records `SphereStagedPlan outcome=RegionContainsInteriorSingularity` and a locus at source vertex 8. This is not production sphere acceptance.
- **Regression classification:** the same seven previously documented accepted-green regressions recur without a new failure signature; **no new stable event/category/recurrence is established by TB-173**. Historical **67 events / 17 categories / 50 recurrences**, produced witness debt **1**, deferred **81** remain unchanged until independent review. No CP3/selector497/D0/H4 activation or acceptance.

## Recommendation — independent Review, separately authorized

The next authorized turn is `M6-CP3-TB-REV-173-P13-SHARED-EDGE-ORACLE-FULL-GATE`. Independently verify the TB-172/TB-173 immutable archives, the 994-row N1–N3 comparison and the two new oracle cases; then re-ask owner design question D13 before authorizing any A2a source-network repair. CB-195/CB-196 and row979 remain held. This execution turn does not start that Review or any Code + Build work.
