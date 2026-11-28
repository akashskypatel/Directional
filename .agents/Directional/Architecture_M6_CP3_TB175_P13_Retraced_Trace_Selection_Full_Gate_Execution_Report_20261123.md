# TB-EXEC-175 — retraced-trace selection full gate (2026-11-23 UTC)

## Situation

The immutable 1,000-case gate is **REJECTED: 993 PASS, 7 RED**. All 1,000 cases executed. Missing, skipped, duplicate, abnormal, unexpected PASS and wrong-site RED counts are zero. The seven known mechanical failures are rows 445, 652, 653, 656, 658, 660, 786. Both new helper tests 999/1000 PASS. This is a completed test measurement, not a production or CP3 acceptance.

## Background — exact evidence

- Canonical turn `M6-CP3-TB-EXEC-175-P13-RETRACED-TRACE-SELECTION-FULL-GATE`; source `f4acd5d1f29d55f36c427e88fed8f5ca09ae7ee5`, compile-only GMP/GMPXX run `45225040406`, immutable package `14845101702`, ZIP SHA-256 `9afbf9c90c96697c49e97669ba108d68e61f57d0182cff3f42807d133be6034f`, 28/28 checksums. No build in this TB.
- Frozen 1,000-case manifest `gates/Architecture_M6_TB175_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv`, SHA-256 `e1d77fd2a10b67e71ecbc6712a92eec48713e91e0006c7282652dc2391b43e35`. Deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Membership: 1,000 gated plus 81 deferred.
- Dispatcher request commit `ca59a42a52f42be8f8f929dbb7ae0691cd606414`; executor `0a2fb0b276b683f8d0da429c7b79b8833c518789`; harness SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. [Run 45233825958](https://github.com/akashskypatel/Directional/actions/runs/45233825958), mailbox `m6-cp3-tb175-retraced-selection-full-gate` on orphan `workflow-mailbox`; matching event and semantic source SHAs. Result artifact `14849271506` ZIP SHA-256 **`be7a0f783d0afb025ccee2353921a765c340766340553f2d70b4b5c32992b347`**, **2008/2008** internal SHA-256 entries valid. Diagnostic log artifact `14848558032` ZIP SHA-256 `a04d6535b33633d270420cf1a88df872173486f338267956b773df22f32273f4`. Reusable-executor log artifact `14849441417` ZIP SHA-256 `cbba93d9a1e0f2b07c73e8802e412efa9321a9d5037a36018089719641895b3c`.
- Prior reference [TB174 run 45206305297](https://github.com/akashskypatel/Directional/actions/runs/45206305297), result artifact `14833644440` ZIP SHA-256 `f77730c1896c346b15de704c90326a5a6543816a3e8ab553d4d8a70b9e11d5a3`, 2004/2004 checksum entries, 991/998 PASS and seven RED.

## Assessment — tests, provenance and regression

| Measure | TB174 | TB175 |
|---|---:|---:|
| Planned / executed | 998 / 998 | **1000 / 1000** |
| PASS / RED | 991 / 7 | **993 / 7** |
| Missing / skipped / duplicate / abnormal | 0 / 0 / 0 / 0 | **0 / 0 / 0 / 0** |
| Control failures / unexpected PASS / wrong RED site | 7 / 0 / 0 | **7 / 0 / 0** |
| Gated + deferred membership | 1,079 | **1,081** |
| Result file checksums | 2,004/2,004 | **2,008/2,008** |

- **998/998 inherited identities and verdicts match TB174.** All 998 raw process logs were compared. **757 are byte-identical**, **240** differ only under permitted N1/N2 Google Test elapsed-time or line-ending normalization, and **one row (179)** uses permitted N3 whole-record reorder: exactly 24 `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records with the same multiset and all other normalized text unchanged. **Zero unapproved raw or ledger differences; zero assertion-site moves.** Full comparison JSON is available in the turn's preserved chat evidence and must be independently rechecked during TB-REV-175.
- New **row 999** `ExactSourceRetracedTraces.EachLaterRetraceIsRemovedInFavourOfItsEarliestKeptTrace` PASS and **row 1000** `ExactSourceRetracedTraces.SameWayOtherEdgeAndEmptyPathsAreKept` PASS. These validate an **unwired helper** only. They do not establish A2a production repair.
- Seven existing mechanical controls remain RED on the same raw witnesses. Row 652 retains `RegionElectedCutComponentEmpty`, at `RegionConstruction`, from co-traced zero-area lens/arrival ownership. Candidate CP2 still fails 1 of 491 controls; the accepted CP2 **491/491** and TB169 **993/993** are unchanged. Row 979 is a passing diagnostic test but its staged subject still records `RegionContainsInteriorSingularity` at vertex 8, not production success.
- `execution-boundary.json`: correct source/package, `postflight=true`, `error=ValueError: required controls failed`, exit **90**, `compile=false`, `relink=false`, `configure=false`, `benchmark=false`. No rebuild, source/test/fixture/selector/manifest edit, generated discovery or production acceptance occurred in this TB.
- **Regression category: same TB170 accepted-green mechanical recurrence.** No evidence of a new stable event, category or recurrence. Historic totals stay **67 events / 17 categories / 50 recurrences**; witness debt **1**, deferred **81**. Only independent TB-REV-175 can adjudicate this gate. CP3/497/D0/H4 and production promotion remain held.

## Recommendation

The exact next separate turn is `M6-CP3-TB-REV-175`. It must re-open primary archives, re-derive the 998-case comparison, check helper non-vacuity, and decide if CB-197a piece-accurate path extraction is authorized. Do not start CB-197a/b, CB-198 or any production wiring in this TB execution turn.
