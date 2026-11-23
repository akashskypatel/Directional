# TB-EXEC-176 — immutable piece-builder and ordered-retrace full gate (2026-11-23 UTC)

## Situation

**COMPLETE as an execution turn; GATE REJECTED: 994/1001 PASS, seven existing RED.** All 1,001 required cases executed. No required case was missing, skipped, duplicated, or abnormal. The seven failures remained at the same historical test identities and assertion sites. The direct producer is not accepted, and the separate TB-REV-176 must review the immutable evidence before any successor code turn.

## Background — exact authority and verified artifacts

- Canonical turn: `M6-CP3-TB-EXEC-176-P13-PIECE-BUILDER-AND-ORDERED-RETRACE-FULL-GATE`.
- Semantic source: `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`. Existing GMP/GMPXX compile-only [run 45255304770](https://github.com/akashskypatel/Directional/actions/runs/45255304770), package `14859356205`, outer ZIP SHA-256 `e6111ff21530f107ab8b1db724155aa2c4fbbe4a2765342fbfabbd4a9c4fc664`. Package verification: 28/28 checksums. Source archive SHA-256 `44f478b25abf63f79d77b2c84fd0e3b70bd61b259f3c6323a377daf93cab278f`. Root package manifest SHA-256 `4d6523cc38f6a5051f44589eae6a42016a61fe8b1f1831a6dc381ba414cc3c26`.
- Frozen 1001-case manifest: `gates/Architecture_M6_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Case_Manifest.tsv`, SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642`. Off-gate deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- Dispatcher request: `m6-cp3-tb176-exec-20261123-a`, commit `a8ca498eaf18dd370d1e7eaec0332ab24a01da74`. Executor authority `a523df11e8a7b19b070aa0463df0df564d03994b`. Harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Immutable test [run 45263429563](https://github.com/akashskypatel/Directional/actions/runs/45263429563), runtime job `138004160862`, mailbox `.workflow-mailbox/m6-cp3-tb176-piece-builder-ordered-retrace-full-gate/latest.json` on orphan branch `workflow-mailbox`. Mailbox event and source SHAs match the request and compiled source. GitHub run conclusion: failure, because the seven mandatory controls remain RED.
- Result artifact **`14861444963`**, ZIP SHA-256 **`202cb81282d9e8a0bb6b711020af80450e407feb12b71de613b1be8cca110453`**. Independent complete internal SHA-256 verification **2010/2010 PASS**. Diagnostic-log artifact `14862267054`, ZIP SHA-256 `e8637354a176041c88508794411cf06e2805d412fcd0f34abc26c8b6cd5f1d37`.
- Immutable TB175 reference: [run 45233825958](https://github.com/akashskypatel/Directional/actions/runs/45233825958), result `14849271506`, ZIP SHA-256 `be7a0f783d0afb025ccee2353921a765c340766340553f2d70b4b5c32992b347`, **2008/2008** member hashes valid. TB175 measured 993/1000 PASS and seven existing RED.

## Assessment — independent execution and comparison

| Measure | TB175 | TB176 |
|---|---:|---:|
| Planned / executed | 1000 / 1000 | **1001 / 1001** |
| PASS / RED | 993 / 7 | **994 / 7** |
| Missing / skipped / duplicate / abnormal | 0 / 0 / 0 / 0 | **0 / 0 / 0 / 0** |
| Bad required controls / unexpected PASS / wrong RED site | 7 / 0 / 0 | **7 / 0 / 0** |
| Gated / deferred membership | 1000 / 81 | **1001 / 81** |
| Internal result SHA-256 checks | 2008 / 2008 | **2010 / 2010** |

The first **1000/1000** TB176 ledger entries match TB175 field by field, excluding the expected log-content SHA values. The independent comparison read all 1000 corresponding raw process logs. **778 logs are byte-identical; 222 differ only by allowed Google Test elapsed-time or line-ending normalization (N1/N2); zero need N3 reordering; zero are unapproved.** In particular, row179 retains the full fragment diagnostic record order without a new reordering exception. The 1,081 existing membership entries are unchanged. The sole new member is row1001, `ExactSourcePathRetrace.PathRunningOverAStretchTwiceDoesNotRetrace`, from the producer test executable. It executed once and **PASS**.

The seven historical RED rows are **445, 652, 653, 656, 658, 660, 786**. They retain their TB175 identities, verdicts, first failure sites, and normalized raw diagnostic text. Row652 still fails at production with `RegionElectedCutComponentEmpty`; the later staged row979 remains diagnostic-only with `RegionContainsInteriorSingularity` at source vertex8. The candidate CP2 total remains **490/491**, below the separately accepted **491/491**. Neither the row1001 helper PASS nor compilation proves A2a producer selection or runtime repair.

The `execution-boundary.json` record confirms exact artifact/source, `postflight=true`, `error=ValueError: required controls failed`, harness exit **90**, `configure=false`, `compile=false`, `relink=false`, and `benchmark=false`. The workflow had no build or Drive-apply activity. No source, test, fixture, benchmark, selector, or acceptance change was authorized or made in this test execution.

**Regression classification:** existing TB170 accepted-green mechanical recurrence; no new stable event, category, or recurrence. Historical totals remain **67 events / 17 categories / 50 recurrences**, produced-witness debt **1**, deferred **81**. Accepted TB169 (993/993) and CP2 (491/491) remain separate authorities. No CP3/497/D0/H4 or production promotion is claimed.

## Control-plane cleanup and procedure evidence

- The exact source snapshot used run `45262742839`, artifact `14861835422`, frozen at `a523df11e8a7b19b070aa0463df0df564d03994b`. An initial direct-read-before-snapshot sequence violated the project's read-order rule; the original attempt documented it. The corrected snapshot was verified and used for the remaining analysis. This is a procedure error, not a runtime defect.
- Temporary snapshot trigger cleanup completed with [run 45264413782](https://github.com/akashskypatel/Directional/actions/runs/45264413782) and commit `1e1de5ba04e67b8c337dc483c7f9364369bad848`, result artifact `14862695525`. The durable dispatcher request and orphan mailbox remain owned by the repository.
- This continuation used read-only local archive and text comparison. It did not execute Directional binaries. The tool-call ledger spans a prior ChatGPT session and is incomplete; no exact all-session count is claimed.

## Recommendation

The **exact next separate turn is `M6-CP3-TB-REV-176`**, an independent Review. It must reopen the immutable TB175 and TB176 archives, repeat all 1000 inherited ledger/log comparisons, verify new row1001 and its negative-control premise, inspect all seven unchanged mechanical RED witnesses, and decide CB-198 selection-receipt authority separately. Do not start CB-198, CB-199, any production wiring, or CP3/497/D0/H4 promotion during this execution turn.
