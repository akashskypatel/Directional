# Independent TB-REV-169 — region visit reader full gate

## Situation

**PASS for the narrow TB169 gate.** The immutable test-and-benchmark (TB) evidence supports the exact CB-188 region reader count correction. It does **not** establish a completed sphere mesh or authorize CP3, 497, D0, H4 or production promotion. This review performs no compiled execution and makes no product, test, selector, fixture, build or benchmark changes.

## Background

- Canonical review turn: `M6-CP3-TB-REV-169-P13-REGION-VISIT-READER-FULL-GATE`; working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; pull request #8 remains open, draft and unmerged.
- Exact compiled source: `b2e976f204fa5b2988a9cbe5a77defd106a96aad`; GNU Multiple Precision (GMP) and C++ GMP (GMPXX) compile run `45101939539`, immutable package `14786260085`. The compile record states `runtimeExecution=false`.
- TB169 [run 45104059492](https://github.com/akashskypatel/Directional/actions/runs/45104059492), result archive `14787082075`, SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`.
- Frozen baseline TB168 [run 45092627119](https://github.com/akashskypatel/Directional/actions/runs/45092627119), result archive `14781634158`, SHA-256 `db2f8f2981c7c2ac914f59598a1e40c553ea8b94b21a23e41b84e74dd1aafb09`.
- The original source archive used in this review was frozen at control commit `a80ef82200601a915c19b7124b3115baf3d82ca8`; snapshot workflow `45108684801` succeeded. Its inner source archive and all 5,777 individual file hashes passed independent verification. This control commit is **not** the compiled semantic source.

**Procedure exception:** Initial small connector reads of repository guidance began before the required snapshot read-mode decision. This was a tool-use policy miss. The review stopped piecemeal code inspection, acquired one exact verified snapshot, and used its local files for the remaining static review. This exception does not alter the immutable TB comparison, but the policy was not fully met.

## Assessment — independent checks

1. Reopened and hashed the exact **two immutable result archives**, not only their published reports. Both outer ZIP hashes match. Each has **1,994/1,994** valid member SHA-256 hashes, including each of the 993 raw test logs.
2. Each execution ledger contains 993 distinct scheduled, executed, successful rows. Both execution-boundary files show **993/993 PASS**, no missing, skipped, duplicate, unexpected or RED cases; no compile, relink, configure or benchmark activity. The **491/491** closed CP2 accepted prefix remains green. The 1,074-entry membership table is byte-identical between both archives (993 gated + 81 deferred).
3. Independently hashed the frozen 993-row manifest: `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`. Its header plus first 491 data rows hash to `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. All manifest identities and expected verdicts agree with both ledgers. All non-log-hash ledger fields are identical between results.
4. Compared **every** raw log under only the frozen normalizations: N1 Google Test duration suffix, N2 line endings, N3 order of complete `M3_CP4AB_FRAGMENT_DIAG` records (1,750 per archive). **244** rows differ in original raw bytes; after authorized normalization, no unexpected line or diagnostic record differs. N3 does not discard or alter record fields.
5. Row 979 changes on exactly four source faces: `6-8-9`, `16-20-21`, `32-33-34`, `40-45-46`. Each now prints `traceChordCount=4`, `expectedFragmentCount=5`, `ownerCount=5`, `ownerDeficit=0`. Before comparison, the checker reverses *only* those three changed count fields; the remainder of row 979 and all other rows must match the baseline exactly under N1–N3. They do.
6. The negative control with the old TB168 package/source and old row-979 counts does not meet the TB169 expected values. The complete normalized-record comparison would reject a changed count, a missing row or an unrelated changed diagnostic record; it is not an outcome-only comparison. No accepted-green loss or new typed failure was observed.
7. The staged sphere still reports `SourceFaceCarriesMultipleTraceCuts sourceFace=6-8-9`. Production sphere still reports `CutSearchExhaustedBeforeCellularity`. These are **unresolved pre-existing failures**, not newly passing product checks.

**Adjudication:** Accept TB169's intended reader-count change, preservation of prior test results, and execution boundary. **Do not accept** staged-sphere construction, full region/corner repair, direct production, CP3/497/D0/H4 promotion, or a changed stable regression count. The 993-row gate did not measure performance or a production census; do not infer them.

## Prior review obligations — explicit disposition

| Source | Result | Next owner and falsifier |
|---|---|---|
| TB-REV-168 Q1/Q2 / CB-188 R1–R4 | **Discharged for the measured gate:** four faces print 4 chords, 5 expected and 5 owned; zero unauthorized raw difference | General source proof remains subject to production acceptance; no new assumption of a finished sphere |
| TB-REV-168 Q3 | **Carried:** deleting unused corner reader branches is not verified by CB-188's region-reader switch | CB-189, then TB-EXEC-170; rows other than 979 must stay identical |
| TB-REV-168 Q4 | **Carried:** CB-189's six enum value compile-time checks are frozen but not implemented in this review | CB-189 must apply only amended diff `6e391678934f776d83b1bbae6652724e080763329d6171c7cdb1c5663259e3b8` on its exact preimage, compile only |
| TB-REV-168 Q5 | **Discharged previously:** unsubstantiated performance hold withdrawn | No new performance requirement or performance claim |
| TB-REV-168 Q6 / C1/C2 | **Carried:** no gated witness for new corner reader error codes | TB-EXEC-170 may count a code as witnessed only if an actual log prints it; row 652 must stay PASS |
| TB-REV-168 Q7 | **Held:** separate code, test and review turns | CB-189 only in next turn; no combined source and review mutation |
| TB-REV-167 S4/S6/S7 | **Carried:** diagnostics only, independent of the region reader count correction | CB-190; no diagnostic substitution for topology proof |
| G5 staged plan | **Open:** face 6-8-9 still stops; no production sphere output | CB-189/TB-EXEC-170 must build the staged plan or show the next actual typed stage without synthetic acceptance; activation remains held |

No new stable event, recurrence or candidate. Stable accounting **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**. The regression tracker retains the ongoing staged and production failures. PR #8 remains draft.

## Recommendation — one frozen successor

Authorize **only** `M6-CP3-CB-189-P13-CORNER-VISIT-READER` as the subsequent independent **Code + Build** turn. Apply precisely `.agents/Directional/Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Exact.diff` with full SHA-256 `6e391678934f776d83b1bbae6652724e080763329d6171c7cdb1c5663259e3b8` on the documented CB-188 postimage. Observe the source/hash preimage and the six enum guards. Compile with the mandatory GMP/GMPXX workflow and **do not execute tests or compiled binaries** in that code turn. Pre-frozen following TB-EXEC-170 falsifiers: all 992 other rows unchanged under N1–N3; row 979 produces a staged plan or advances to the next typed failure; row 652 remains PASS; C1/C2 only witnessed when printed. On a preimage/hash/compile failure, stop and return to Review. Do not start CB-189 inside TB-REV-169.

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | 993-row manifest `82581dd1…e436`; first 491 manifest rows with header `483f1101…038`; no selector modification |
| Decisive claims independently re-derived | Two ZIP outer hashes; 1,994 files each; 993 exact ledgers/logs; 1,074 membership; 491 accepted cases; four exact row-979 records; full N1–N3 comparison |
| Non-vacuity checked | Old-package/old-count negative control fails target; line-by-line diff checks all 993 rows; N3 retains complete records |
| Prior obligations discharged/carried | TB-REV-168 Q1–Q7, TB-REV-167 S4/S6/S7, staged G5 explicitly handled above |
| Stable accounting | 66 / 17 / 49; debt 1; 81 deferred; package `14786260085` / frozen manifest `82581dd1…e436` |
| New candidates/obligations recorded | None new; tracker current carry updated in place |
| ORIENTATION currency line | `M6-CP3-TB-REV-169-P13-REGION-VISIT-READER-FULL-GATE`; 2026-11-23 UTC |
| ORIENTATION §3 / §4 / §7 / §8 | §3, §7 updated; §4 updated for new reader witness; §8 existing failure pattern applies, no new general lesson |
| CHANGELOG | Single TB-REV-169 review entry prepended |
| ROADMAP | n/a — M6-CP3 remains active; no checkpoint transition |
| Selector manifest | n/a — accepted identities and selector bytes did not change |
| LESSONS | n/a — existing source-authority/non-vacuity rules apply; no new generalizable rule |
| Consolidation under CLEAN_UP_POLICY | Checked current report, amended next diff, predecessor authority; no safe document to fold without removing still-cited exact evidence; retain current authorities |
| Successor frozen | `M6-CP3-CB-189-P13-CORNER-VISIT-READER` only; exact diff and TB-EXEC-170 falsifiers above |
| Turn boundary held | Review runtime-free; no source/test/fixture/selector/build/benchmark mutation |
| review_check.py boundary | Local snapshot lacks repository Git history; standalone boundary command reports unavailable history and cannot establish full boundary PASS. Patch-path audit and artifact/source invariants checked separately; no false PASS claimed |
| `STATUS` lifecycle maintained | Entered this canonical Review in root beacon at `2026-11-23T03:53:28Z`; final direct-write scheduled after committed documentation and cleanup |
| Pushed to origin, branch in sync | Remote result must be confirmed through GitHub connector; the downloaded local snapshot has no origin history, so its `git status -sb` cannot prove remote sync |
