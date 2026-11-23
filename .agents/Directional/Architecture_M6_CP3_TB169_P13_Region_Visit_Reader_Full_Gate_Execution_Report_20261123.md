# TB169 — region-visit reader immutable full-gate execution

## Situation

**The frozen TB169 artifact-only full gate passed 993/993 cases.** The independent comparison found no unauthorized change in prior records. The reader corrected the expected four face-count receipts; it did **not** construct a production sphere mesh. The independent TB-REV-169 is the only authorized next turn.

## Background

- Turn: `M6-CP3-TB-EXEC-169-P13-REGION-VISIT-READER-FULL-GATE`; source branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open, draft, unmerged.
- Exact immutable semantic source: `b2e976f204fa5b2988a9cbe5a77defd106a96aad`; CB-188 GMP/GMPXX compile run `45101939539`; eight-target package artifact `14786260085`, outer ZIP SHA-256 `d877a0ea4c05cfe93275506823652abb6b0e012dd3a5925103606e28e69625a5`.
- Frozen 993-case manifest `.agents/Directional/gates/Architecture_M6_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Case_Manifest.tsv` SHA-256 `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`; 81-item deferred-ledger SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`.
- Executor SHA `8cd169210fee847bc608e87ee8af4d797983c64a`; exact harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- Dispatcher request commit `9cd25dea9cd0101998d7c298d8c255a119d7ab6e`; mailbox key `m6-cp3-tb169-region-visit-reader-full-gate`, published only on orphan `workflow-mailbox`.
- [Execution run 45104059492](https://github.com/akashskypatel/Directional/actions/runs/45104059492): test_benchmark/runtime SUCCESS, compile job SKIPPED. Result artifact `14787082075`, ZIP SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`; log artifact `14786703046`, ZIP SHA-256 `ed97c83b7d1ee074bb4eb3442c7b28b7244ded1d9405fa8dd10f5f2d7e8ad2c6`.
- Baseline TB168: [run 45092627119](https://github.com/akashskypatel/Directional/actions/runs/45092627119), result artifact `14781634158` ZIP SHA-256 `db2f8f2981c7c2ac914f59598a1e40c553ea8b94b21a23e41b84e74dd1aafb09`.

## Assessment — independent evidence

1. The full ZIP bytes match the published GitHub artifact digest. All **1,994/1,994** internal candidate checksums and all **1,994/1,994** baseline checksums verified. Each of 993 raw logs also matches its recorded row digest.
2. Exactly **993 planned, 993 executed, 993 PASS**, 0 RED, abnormal, missing, skipped, duplicate, control-bad, unexpected PASS, later-positive RED or red-site-bad; postflight true, exit 0. CP2 accepted prefix **491/491**. Membership **1,074 = 993 gated + 81 deferred**, with exact byte equality of membership.tsv to TB168.
3. Every row retains identical non-hash ledger metadata. The independent comparator normalized only N1 Google Test elapsed time, N2 line endings and N3 complete `M3_CP4AB_FRAGMENT_DIAG` record multisets (1,750 records per package). There are **zero unexpected normalized raw or diagnostic-record differences** across all 993 rows. Raw bytes differ in 244 cases before allowed normalization.
4. Row **979**: each of faces **6-8-9, 16-20-21, 32-33-34 and 40-45-46** prints exactly `traceChordCount=4`, `expectedFragmentCount=5`, `ownerCount=5`, `ownerDeficit=0`. The comparison reverses *only* the three approved count fields for these four face records and requires every other row-979 text byte to agree after N1–N3. The typed outcome remains `SourceFaceCarriesMultipleTraceCuts sourceFace=6-8-9`.
5. `execution-boundary.json` proves exact package/source and `compile=false`, `relink=false`, `configure=false`, `benchmark=false`; no rebuild, source/test/fixture/selector/manifest edit, or production census occurred in this TB turn.
6. The independent comparator was checked by a negative control using TB168 as both sides: it rejected the four incorrect face counts and the old package/source. The TB169-to-TB168 comparison has `accepted=true` and zero failures. Comparator SHA-256 `7dcba90852123763f4647cee5d68ee7baab421ac20af471c08a164f056939b3d`, retained at ChatGPT Library `/Directional/Recovery/TB169_Independent_Comparator_20261123.py`.

## Regression classification and limits

**No new stable event, recurrence, candidate failure, or PASS-to-RED regression is observed.** The changed row is an authorized count correction, not a new topology acceptance. The existing staged sphere plan still fails closed on face 6-8-9; the production sphere remains `CutSearchExhaustedBeforeCellularity`. Stable register: **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**. The pre-existing G2/G3 reader/corner obligation remains open. No CP3/497/D0/H4 or production promotion is justified. No census ran.

## Recommendation

Only start the independent review `M6-CP3-TB-REV-169-P13-REGION-VISIT-READER-FULL-GATE` in the **next response**. Independently re-open the immutable result and confirm complete N1–N3 comparison, four face-count corrections, typed stop and no regression. Do not start CB-189, activation or promotion in this TB169 turn.
