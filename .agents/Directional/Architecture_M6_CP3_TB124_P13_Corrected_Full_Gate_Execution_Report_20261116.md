# TB124 — corrected cross-face oracle, full-gate execution (2026-11-16 UTC)

## Situation

**Scoped MATCH, with one classified nondeterministic diagnostic-output qualification.** The CB142 immutable artifact completed the complete 949-case required gate: **949 PASS / 0 RED / 0 skipped**, including corrected row 949 and all four internal negative assertions. This was artifact-only GitHub Actions execution. The earlier TB122 948/949 result remains historical evidence. No source, selector, fixture, or build input changed. The only authorized distinct successor is Review `M6-CP3-DEFN-P13-EDGE-TERMINAL-INVENTORY`, under RA-242; it is not performed here.

## Background — exact authority and independent evidence

- Authority: [RA-242](Architecture_M6_CP3_TB123_REV_P13_Cross_Face_Oracle_Outcome_Review_20261116.md#owner-requested-adversarial-re-review-ra-242-2026-11-16-utc), which narrowed TB124 to the 949-case gate only. No census was requested or executed; the source product is identical CB141→CB142.
- CB142 compiled source `57b28b737fd92b083d24d882152dea186211f735`. Immutable artifact `14224898790`, provider ZIP SHA-256 `98f448f9e5b5ebcacbd1884ad4e62415d7c10d5878da0ccf1438654b4aeaf52b`; the immutable ZIP and **28/28** internal package entries were independently verified, including its source archive. The four `EXPECT_FALSE` negative helper assertions exist in the packaged source. No rebuild or package repair occurred.
- Verified executor source-snapshot event `305d228e4ea06c3fc6b4e4edcb2634124808aa97`, [snapshot run `43980047429`](https://github.com/akashskypatel/Directional/actions/runs/43980047429), artifact `14282187723`, outer ZIP SHA-256 `27b4c85949fb40857ca4bf0f0eb8c4aff744fa1d921d95a7b86cee060a7fb0f1`: **5,566/5,566** source hashes and source archive verified. Temporary snapshot marker later removed, commit `82f252ed322049c06bcf89d6c846138170622d66`.
- Frozen manifest SHA-256 `a56ad00ce48424a8505b7a6ab71500a4c60285b3d96ceecaf7cf1a3724f5f2b1`: 949 rows; membership 1,030 with 81 separately deferred rows. Executor harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` self-test 30 and self-check 949/81 passed prior to runtime.
- Durable request commit `f149c0f108455b5dccc171e09ce8ee1933d0f6be`, request `m6-cp3-tb124-corrected-full-gate-20261116-v1`. [Test run `43980520479`](https://github.com/akashskypatel/Directional/actions/runs/43980520479), runtime job `133695660997` **success**, result artifact `14283755675` (ZIP SHA-256 `016b9528c330d60a3202d8594d0d6f37b6c0eb76415cab2f0c93ecc965d30d42`), diagnostic log artifact `14283725881` (ZIP SHA-256 `00d81c610969747fd975bdd3b03a13e0e8f86f38d8693db5e02d8ea3e122c5e4`). Provider digests agree with downloaded ZIPs; **1,906/1,906** result SHA256SUMS entries verified. Mailbox `m6-cp3-tb124-corrected-full-gate-v1` reports exact request event and semantic source.
- [TB122 baseline](Architecture_M6_CP3_TB122_P13_Vertex_Transit_Carrier_Seed_And_Outflow_Follow_Full_Gate_Execution_Report_20261116.md): run `43848562969`, result artifact `14216937463`, 948 PASS / row949 RED, 1,906/1,906 hashes.

## Assessment — independent, case-level result

| Check | TB124 result |
|---|---|
| Planned/executed/unique | **949 / 949 / 949** |
| Passed / red / skipped / abnormal | **949 / 0 / 0 / 0** |
| Missing / duplicate / control failure | **0 / 0 / 0** |
| Membership / deferred | **1,030 / 81** |
| `execution-boundary.json` | `exit=0`, `postflight=true`, `compile=false`, `configure=false`, `relink=false`, `benchmark=false` |
| Row 949 | `ResolvedBranchCorrection.OwnerWithoutOutflowFollowsFieldAcrossRadialEdge` **PASS**, one test, four local negative helper assertions in its compiled source |
| Rows 1–948 | **948/948** identical semantic ledger fields (row, identity, test, binary, verdict, exit, run, passed, skipped, first-failure, typed-reason) |
| Gate follow lines | **0** `vertexOutflowFollow` and **0** follow-kind `Unresolved` lines in all 949 raw logs |
| Postflight package | **28/28** packaged file hashes unchanged; full result manifest valid |

**Raw log qualification.** Normalizing only test elapsed-time values yields 944/948 byte-identical inherited logs. Rows **164, 176, 190, 195** contain ordering and line-join variation of existing `M3_CP4AB_FRAGMENT_DIAG` diagnostic prints. In all four, the **multiset and exact contents** of those records are unchanged (respectively 6/6, 6/6, 8/8, 4/4). After splitting adjacent joined diagnostic markers, all other ordered test-output lines and all 948 row verdict/first-failure receipts match TB122. Do not call these four raw logs byte-identical; the difference is verified, not discarded. This does not establish a new product failure or an accepted-control change. The origin of the log interleaving is not independently proven. The receipt requirement is met for the semantic case and required gate receipts, not for byte-for-byte raw log identity.

**Regression disposition.** The prior row949 RED was caused by a reviewed invalid cross-frame test oracle, not a verified producer regression. The corrected compiled oracle passes in the full gate; **no new stable event, category or recurrence** is supported. The four variable diagnostic logs are recorded as **non-stable diagnostic-order candidates**; no test assertion changed and the output values agree. BunnyRandom multi-terminal edge `(241,251)` is a separate existing off-gate cut-graph obligation; TB124 did not run or adjudicate a new census. Keep C3, O42 and O43 open; O44 closed by RA-242, C4 and exact-grazing work parked for CB145. Accepted CP2 **491/491**, stable **66 events / 17 categories / 49 recurrences**, debt **1**, deferred **81**. CP3 and selector497 not promoted; `chainRimSchedules=false`. D11=A, D12=A, D10 deferred, D6 pending.

## Recommendation and turn boundary

Accept TB124 as the scoped full-gate MATCH with its explicit raw diagnostic-output qualification. The next **separate Review-only** turn, `M6-CP3-DEFN-P13-EDGE-TERMINAL-INVENTORY`, may use this gate as the evidence prerequisite and must freeze the exact CB143 inventory diff. It must not assume that the cut-graph issue, C4, grazing, or direct production are resolved. No Code + Build, census, benchmark, selector edit, merge, or successor Review was performed in TB124.
