# TB-EXEC-171 — immutable along-edge face-piece full gate (RED; 2026-11-23 UTC)

## Situation

The exact 994-case artifact-only full gate completed with **987 PASS, 7 RED**. The full gate is **rejected**. All seven mechanical controls that failed in TB170 still fail: **445, 652, 653, 656, 658, 660, 786**. One accepted CP2 control remains RED (CP2 **490/491**). This report records Test + Benchmark evidence only; no implementation change, retry, new test, or production acceptance is authorized in this turn.

## Background / immutable authority

- Canonical turn: `M6-CP3-TB-EXEC-171-P13-ALONG-EDGE-FACE-PIECE-FULL-GATE`. Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Source `462010254fa90bf6c853768019bcfc9132b5c631`; CB-192 compile run `45130510704`; immutable package artifact `14797941489`, ZIP SHA-256 `49824e664c79d13fc1b2ba047bd044303683f41b28df7a3344902e74d84b41cf`.
- Package root SHA-256 manifest `a917fa04222c0fd14adcdd157697b2555fd5d0ebf03d17164d11eadf8d3df0fb`; packaged source archive `a85ce6f72e17a84c1d7963ba95c7fb49293a987121e9628b788415ad7fedbad6`; packaged source records `runtimeExecution=false`, GMP.
- Frozen 994-row manifest `gates/Architecture_M6_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Case_Manifest.tsv`, SHA-256 `704dcf6c5525d244c09f3ba0fd1c93a860daa194d4381d6b427dddc3be6209c6`. Its first 993 rows are byte-identical to the frozen TB168 manifest, with appended `ArcFaceVisits.FacePiecesAlongOneEdgeReadAsSlides`. Deferred ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81).
- Artifact-only harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Dispatcher request commit `6445fdf3bcbae98d32e60c13aa8920cc830e7396`; orphan mailbox key `m6-cp3-tb171-along-edge-face-piece-full-gate`. [GitHub Actions run 45133081384](https://github.com/akashskypatel/Directional/actions/runs/45133081384), one attempt. Schema validation and request parse passed, compile and Drive apply skipped, artifact-only runtime job failed on semantic gate, mailbox published.
- Result artifact `14799346720`, ZIP SHA-256 `b79b5cc26044acd357243c3c8fe7350e6a68e450171400aad6228e059e143d0c`. Harness diagnostic artifact `14799391760`, ZIP SHA-256 `6fb935ba4b4d331570ed4af75e61aa164e58ddfc6bed24327eebe0aaaf49ec48`; reusable wrapper log `14799272112`, ZIP SHA-256 `13ee1740b473106abfa9b3e4fbbe4decb996f924413966d50b6562e50e24d645`. Outer artifact digests match the published GitHub mailbox/server values and downloaded bytes.
- Accepted baseline: TB169 result `14787082075`, ZIP SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`, 993/993 PASS, CP2 491/491.

## Assessment: independent evidence

- All **994 planned / 994 executed**, 987 PASS, 7 RED, zero missing/skipped/duplicate/abnormal; 7 required-control violations; membership exactly **1075 = 994 gated + 81 deferred**. Both result archives independently verified their recursive internal hashes: **TB169 1994/1994; TB171 1996/1996**. Every ledger row's raw-log SHA-256 matches.
- The execution boundary states `compile=false`, `configure=false`, `relink=false`, `benchmark=false`, `postflight=true`, `exit=90`, `error=ValueError: required controls failed`. Full runtime completed. This is a **semantic RED**, not an orchestration failure.
- An independent, strict N1–N3 comparison (N1 Google Test duration, N2 line endings, N3 unordered *complete* `M3_CP4AB_FRAGMENT_DIAG` records) found exactly **21 changed non-979 rows**: 396, 397, 445, 637, 638, 649, 650, 652, 653, 656, 658, 660, 662, 665, 669, 687, 784, 786, 787, 788, 857. The missing diagnostic records remain **300** (TB169 1750, TB171 1450). There are 253 byte-different original raw rows before normalization. No off-row allowance is justified.
- New **row 994 PASS**, proving the pure classifier's controlled along-edge cases. That does **not** prove integration recovery.
- **Row 652's first actual typed failure changed from TB170 `SourceFaceCutPartitionFailed` to `NotProductionReady/global-topology-plan/RegionElectedCutComponentEmpty`; `regionFrontierFailureStage=RegionConstruction`**. In its source-face records, face `(1,4,139)` now shows `traceChordCount=0`, `expectedFragmentCount=1`, `ownerCount=1`, `ownerDeficit=0`, although `sharedOwnerChordCount=1`; the prior false face cut is no longer the first rejection. Source face `(0,1,102)` still records `traceChordCount=1`, `expectedFragmentCount=2`, `ownerCount=1`, `ownerDeficit=1`. These are **observations**, not a proved cause of the empty-region election. The other six failures continue to depend on the missing mechanical topology plan.
- **Row 979 PASS as a test**, but still prints `SphereStagedPlan outcome=RegionContainsInteriorSingularity`. It remains a staged failure measurement, not production sphere acceptance. TB170 located the prior typed stage at source vertex 8; TB171's summary line does not independently identify that vertex.
- The TB170 accepted-green regression remains unresolved in TB171. No additional stable event or recurrence has yet been independently adjudicated; retained historical accounting remains **67 events / 17 categories / 50 recurrences**, witness debt 1, deferred 81. This TB cannot claim corrected mechanical behavior, promote CP3/497/D0/H4, or count production success.

## Recommendation and closeout boundary

**STOP at this RED test gate. No test rerun or source/fixture/selector change in TB171.** Next separately authorized Review turn: `M6-CP3-TB-REV-171-P13-ALONG-EDGE-FACE-PIECE-FULL-GATE`, to reopen both immutable artifacts; verify the 21 non-979 changes, seven RED controls, 300 missing records, row 994 controlled PASS, and new `RegionElectedCutComponentEmpty` source-face/region-frontier evidence before freezing any corrective measure. Update the stable regression tracker independently only with justified classification. No census or production activation.

This report establishes the immutable semantic result. If handoff/TODO/changelog/tracker maintenance or the final STATUS write remains outstanding at response closeout, retain the **same TB171 turn IN_PROGRESS** until those obligations are completed; do not start Review in this turn.
