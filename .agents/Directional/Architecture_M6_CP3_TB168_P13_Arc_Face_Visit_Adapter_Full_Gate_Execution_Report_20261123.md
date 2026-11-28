# TB168 — arc-face-visit adapter, immutable full-gate execution

## Situation

**The frozen TB168 gate passed 993/993 independent rows.** All four new pure-adapter tests passed. The 989 previously accepted TB167 rows retained identical verdict and diagnostics under exactly the approved N1–N3 comparisons. The adapter remains unwired; this is a test result, **not** evidence of staged/production sphere recovery.

## Background

- Canonical turn: `M6-CP3-TB-EXEC-168-P13-ARC-FACE-VISIT-ADAPTER-FULL-GATE`. Working branch `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 remains draft, open, unmerged.
- Exact semantic source: `486704038a6bf659a253a2e2f99edde5d03c7ffe`; CB-187 GMP/GMPXX compile run [`45090657623`](https://github.com/akashskypatel/Directional/actions/runs/45090657623), immutable package `14781561211`, outer ZIP SHA-256 `fa9781a710f29c926c9fd60a39cf6868d15b8d3e50ea5b7989b17aebd59b67a6`. No binary execution in CB-187.
- Frozen TB168 case manifest: `.agents/Directional/gates/Architecture_M6_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Case_Manifest.tsv`, SHA-256 `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`; deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- Artifact-only dispatcher request commit `ec046a705abebc5f43495cba25aff07c7a1ec586`, key `m6-cp3-tb168-arc-face-visits-full-gate`; exact executor SHA `8cd169210fee847bc608e87ee8af4d797983c64a`; harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- [Execution run 45092627119](https://github.com/akashskypatel/Directional/actions/runs/45092627119) returned success. Immutable result artifact `14781634158`, ZIP SHA-256 `db2f8f2981c7c2ac914f59598a1e40c553ea8b94b21a23e41b84e74dd1aafb09`; separate diagnostic artifact `14782296952`, ZIP SHA-256 `c8e1cdd805b433abba52c9540e7e58d9602ef8cf7247b1b7bda4fa1517841199`. The matching mailbox on orphan `workflow-mailbox` records event `ec046a705abe`, semantic source and result.
- TB167 accepted comparison: run `45063416334`, artifact `14770748728`, ZIP SHA-256 `446eff8a01b4895030a3c969896f97976b57dcb03624a03acf88a2308ad09f93`.

## Assessment — independently verified archive results

1. Independent read-only verifier checked **1,994/1,994** candidate and **1,986/1,986** TB167 checksum entries, exact result ZIP/provider digest, and every row's raw log SHA-256. No mismatch occurred.
2. Full gate: **993 planned, 993 executed, 993 PASS; 0 RED, abnormal, missing, skipped, duplicate, control-bad, unexpected PASS, later-positive RED, or red-site-bad**; `postflight=true`, exit 0. CP2 accepted prefix: **491/491**.
3. Membership: **1,074** identities, consisting of **993 gated + 81 deferred**; all 1,070 TB167 identities retained, exactly four new gated identities, none removed.
4. Rows **1–989**: **zero** non-hash ledger differences, **zero** normalized raw transcript differences, and **zero** complete `M3_CP4AB_FRAGMENT_DIAG` multiset differences under only N1 Google Test time removal, N2 line-ending normalization and N3 full-record multiset comparison. No other allowance applied.
5. New rows **990–993**, each one independent process and each PASS with published raw logs: `ArcFaceVisits.ReadFacePiecesAsBoundaryCutsAndSlidesAsOneSide`, `ArcFaceVisits.SlideSideFollowsFaceWindingAndDirection`, `ArcFaceVisits.InteriorEndsHaveNoBoundaryPosition`, `ArcFaceVisits.RejectsUnboundUnknownOffFaceAndStationaryPieces`.
6. The immutable execution boundary records **compile=false, relink=false, configure=false, benchmark=false**, exact package `14781561211`, exact source SHA and no source/test/fixture/selector/manifest mutation. No production census was requested or performed.

## Regression classification and remaining limits

No PASS-to-RED change, new regression candidate or new product acceptance was observed. Existing staged row-979 plan remains at `SourceFaceCarriesMultipleTraceCuts` on face `6-8-9`; the production sphere remains at `CutSearchExhaustedBeforeCellularity`. CB-187 is a pure unwired adapter, so this gate does not measure either reader switch or repair either stop. Existing stable accounting remains **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**. No CP3/497/D0/H4 promotion.

## Recommendation

Start only the separately authorized independent `M6-CP3-TB-REV-168-P13-ARC-FACE-VISIT-ADAPTER-FULL-GATE`. Recheck the immutable evidence and freeze exact CB-188 region-reader and CB-189 corner-reader diffs from TB-REV-167 contracts R1–R4 and C1–C4. Do not begin their implementation in this Test + Benchmark turn.
