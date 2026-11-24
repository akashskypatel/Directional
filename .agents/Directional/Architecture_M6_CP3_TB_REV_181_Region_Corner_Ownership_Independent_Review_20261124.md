# M6-CP3-TB-REV-181 — independent review (2026-11-24 UTC)

## Situation

Accept TB181 as the cumulative runtime baseline, 1003/1003. Close K6 (shared exact trace-segment namespace) at its frozen contract. No production or CP3/497/D0/H4 acceptance. Freeze only the compile-only successor `M6-CP3-CB-202-P13-REGION-CORNER-SINGULARITY-REACH`. The proposed code is a review artifact, not an applied implementation.

## Background — exact authority

- Entry STATUS `80a234893e49dd383e64ab8eede08dae157adfc9`; Started at `2026-11-24T22:22:03Z`, no Resumed at. The previous beacon was TB-EXEC-181 COMPLETE with this Review as successor; the user requested this canonical turn only.
- Source/executor `b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3`, [CB201 compile record](Architecture_M6_CP3_CB201_P13_Exact_Trace_Segment_Namespace_Code_Build_Record_20261124.md), run 45488907549, package 14966635283 ZIP SHA-256 `fbad076e0d30e099ece6e197191f7a5ec98016a8713a286a4a391ede0cdb644a`. 28/28 checksums independently verified; root SHA256SUMS `0641144df8b7d0b957a800fbc9d5853b79521daa3fdc760593acfa07594fe1ef`, source archive `b0f867441b2ef0e00fa08764a7aa2eda41b350541e7dab5bd35bdeb3893d7248`. Eight targets, GMP/GMPXX linkage, empty source status, runtimeExecution=false.
- TB181 [run 45492294397](https://github.com/akashskypatel/Directional/actions/runs/45492294397), job 138793718042, result 14967943314 SHA-256 `877efb75d3ed801aab7fdc9931356254155162a114d9fc36a2f680f02ec9fa6b`; request SHA-256 `8fd1f9e9972c3704f02fceebcee8dc82a9abfef93e4d67609a4775160dfd9c2b`. [Execution report](Architecture_M6_CP3_TB181_P13_Trace_Segment_Namespace_Full_Gate_Execution_Report_20261124.md). Runtime job and mailbox success; configure/relink/compile/benchmark false, immutable postflight true. TB180 baseline result 14951803089 SHA-256 `67e784747b1c8d04bf781b69b486f3310876fde101b7935f0207fd2fd36a39f8`, source `4c2b4cf16732cddb58252d5e758ea0b24449ed2a`, package 14901170173, run 45457449013.
- Review snapshot [run 45500317863](https://github.com/akashskypatel/Directional/actions/runs/45500317863), job 138821732547, artifact 14969183368 SHA-256 `35eb06541d1a51e5e81bc866695cada61ea29cf635d1e6966f101fb257226269`, 5818/5818 file checks, source `1aebcd183113512cce435d45b7ae373164f1b8f7`. GitHub compare confirms semantic source ancestor (19 commits ahead, zero behind, zero code paths changed); independent package/snapshot SHA-256 census matches 162 src, 146 include, 68 tests, 30 benchmarks, 12 cmake and root CMakeLists files. PR #8 open/draft/unmerged.

## Assessment — independent evidence

| Check | Result |
|---|---|
| Frozen 1003-row manifest | `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724` |
| Historical 993-row prefix | `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436` |
| CP2 491-row prefix | `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038` |
| Deferred ledger | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; 81 unchanged |
| Membership | 1084, SHA-256 `556019b09f8a31392d3e9860acd2e9c63ad61d7179da9899006eff59ce031a46`; both archives byte-identical |
| Archive verification | 2014/2014 files each, all 1003 raw-log hashes and test RUN/OK/PASSED records checked independently |
| Raw equality | 607 byte-equal, 393 equal after N1/N2, 3 after N3 (164/172/176), zero material differences |
| Fragment record multiset | 1554 complete records in each archive; all per-row multisets equal; N3 moves only whole counted records |
| Controls | 445/652/653/656/658/660/786 PASS; CP2 491/491; no skipped, abnormal, missing or duplicate executions |

The independent comparison reads the raw bytes and exact ledger fields, not the execution report's arithmetic. K6 is namespace-only: the five operations/types are in `exact_trace_segment_detail`, no downstream alias for a moved operation remains. The exact CB201 diff SHA-256 `0da2ffe20ff5f0b4913acba5fa5dfd3e18c0e23ef1f6965d9d94098696d8d91c` and seven packaged postimages match the frozen manifest; reverse application in scratch recovers every frozen preimage. This is a source-ownership correction, not an assertion of more production witness coverage. K1–K5/J4/J5 and M1–M4 retained as discharged or withdrawn per prior Review; TB170/L2 closed at seven-control boundary; C4 withdrawn. K6 discharged. J6 remains unexercised in the production path (isolated row1002 is not a production witness); debt1/deferred81, stable 67 events / 17 categories / 50 recurrences. E5, CB-190, Branch A and CP3/497/D0/H4 carried, not authorized.

### P1 and CB-202 — exact next hypothesis

Row979 remains a staged stop at `RegionContainsInteriorSingularity` vertex8 (node1, three departures plus two arrivals; five arc ends). The raw record is identical under permitted normalization; no production sphere is proved. Region source support is fragment-level by contract (`GlobalTopologyPlan.h:78–81`). `GlobalTopologyPlan.cpp:1791–1806` checks any incident source face; `:2196–2222` already restricts the certificate to owning-orbit corners. This is a real semantic disagreement independent of the staged result. Cause of row979 remains unclassified until the next TB.

The [exact successor manifest](gates/Architecture_M6_CP3_CB202_P13_Region_Corner_Singularity_Reach_Exact_Manifest.md) binds six prior requirements. It extracts the existing corner selection into one internal helper and preserves the exact missing-owner error. Both field regularity and the disc certificate consume the same set. The new appended guard discriminates a non-owning corner, a reached singularity with no port, empty corner set, a boundary port and a missing owner. It does not weaken or modify existing assertions. Source census identifies four existing negative tests (rows354/355/654/966) and no direct assertion of `RegionOrbitMissing`. The current validator checks singularity reach before orbit selection. Simply reordering it could invalidate the row355 negative, which collapses all canonical regions into an exterior-only candidate. The proposed validation-only full-partition union proof uses exact support union and exterior arc multiplicity, derives all corners from the same helper, and always rejects that malformed union. This is a deliberate bounded decision to preserve the negative test's actual semantic rejection, not a repair of invalid region topology. Broken walks/missing orbits on other invalid inputs precede unprovable reach. All frozen old tests must stay PASS and no off-row material difference is permitted. The new plan is not compiled or executed; future TB is the falsifier. Only row979 plus appended row1004 may differ. The new gate preserves the exact 1003-row prefix, 1004 gated + 81 deferred, SHA-256 `d778afbe65e181391116a67ada06f4482e9786917ca58dd2a17f7b7459d8ca5f`. No selector promotion.

## Recommendation

Only `M6-CP3-CB-202-P13-REGION-CORNER-SINGULARITY-REACH` is frozen. Exact diff SHA-256 `26ec484d0434afd3f0376661e945bdbd73d1c9a1fc206e7b589be34bb3ba5332`, 25,159 bytes, three paths, +297/−105. `git apply --check`, exact postimages and `git diff --check` pass in scratch. See [manifest](gates/Architecture_M6_CP3_CB202_P13_Region_Corner_Singularity_Reach_Exact_Manifest.md) for preimages, precedence census and TB182 stop rules. Code + Build only in a separate turn, eight GMP/GMPXX targets, `runtimeExecution=false`. The current Review must not implement, compile or run the successor. No Branch A before a valid sphere plan and independent Review.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 993/491 prefixes and 1003 manifest hash above; no selector byte changed. |
| Decisive claims independently re-derived | Raw archive checksums, logs, membership, ledger, complete records, exact package and source, K6 reverse preimages and postimages. |
| Non-vacuity checked | All seven controls and six corruption labels retained; old row355 requires typed rejection; new positive/negative guard is frozen, not yet executed. J6 debt retained. |
| Prior obligations discharged/carried | K6 discharged; M1–M4/K1–K5/J4/J5 and withdrawn C4 retained; J6/E5/row979/CB-190/Branch A held. |
| Stable accounting | 67/17/50, debt1/deferred81; TB181 accepted 1003/1003, CP2 491/491, no promotion. |
| New candidates/obligations recorded | P1 source-level disagreement and frozen precedence proof; tracker updated. |
| ORIENTATION currency line | TB-REV-181, 2026-11-24 UTC. |
| ORIENTATION §3 / §4 / §7 / §8 | Runtime baseline, K6 closure, unchanged controls and prioritized P1; source-reader disagreement recorded; no production promotion. |
| CHANGELOG | New entry. |
| ROADMAP | Current acceptance and next-turn label updated; milestone unchanged. |
| Selector manifest | Baseline index updated; historical selectors unchanged. |
| LESSONS | Existing single-producing-authority, representation-consumer and non-vacuity rules apply; no new general rule. |
| Consolidation under CLEAN_UP_POLICY | Seven superseded CB200/TB180 records folded with exact content (the old diff is encoded losslessly as Base64), hashes, original paths and snapshot; live references repaired. CB201 package authority and TB181 current runtime evidence retained. |
| Successor frozen | `M6-CP3-CB-202-P13-REGION-CORNER-SINGULARITY-REACH`, exact [manifest](gates/Architecture_M6_CP3_CB202_P13_Region_Corner_Singularity_Reach_Exact_Manifest.md) with falsifiers. |
| Turn boundary held | No product/test/fixture/benchmark/build/selector mutation on working branch; scratch proposal only; no project compile/runtime. New gate manifest is future plan input. |
| review_check.py boundary | Local boundary confirms clean code and selectors and fails four historic-authority checks because the snapshot omits original Git history. GitHub compare confirms rewrite base `8b7299b43764a6ba3444e5bc774a2f1b65e99731` is ancestor (8063 commits ahead); independent exact connector reads and local heading census confirm all durable headings retained. Drift audit: zero errors; three authorized protected-document changes and one pre-existing orientation size warning. |
| STATUS lifecycle maintained | `M6-CP3-TB-REV-181`, entry IN_PROGRESS, Started at 2026-11-24T22:22:03Z, Resumed at blank. Final direct STATUS write only after verified remote closeout; successor `M6-CP3-CB-202-P13-REGION-CORNER-SINGULARITY-REACH`. Ended at recorded by final beacon. |
| Pushed to origin, branch in sync | Remote apply and cleanup receipt are required before the COMPLETE beacon; at preparation no push claimed. Final receipt in chat closeout and repository STATUS. |

Process deviations: initial document reads preceded explicit snapshot mode and the full mandatory start-policy read. Corrected by verified snapshot and package comparison. The full initial lesson/policy and separate turn-based skill read is not established; tool ledger is partial after context compaction. No acceptance claim relies on those missing process receipts. No actual syntax compilation of the proposed diff is claimed. Existing orientation size warning is tracked; no durable requirement is removed to meet a size heuristic.
