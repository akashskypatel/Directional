# TB152 — edge-piece face-side full gate (2026-11-20 UTC)

## Situation

**PASS at the frozen helper scope.** The immutable CB168O package executed the TB152 gate: **967/967 PASS**. The previous **966/966** test identities match TB151 under frozen N1–N3, with all 504 slide-contact arrival records preserved without masking. The accepted CP2 prefix remains **491/491 PASS**. This is not a direct-production repair or acceptance promotion.

## Background — source and executable authority

| Item | Evidence |
|---|---|
| Branch | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 open, draft) |
| Semantic source | `1df6a09ad386791a9befddd9658ddc4d5bb795f2` (CB168O) |
| Compiled immutable package | Artifact `14628449217`, ZIP SHA-256 `20c8aed1d38e42cd00fc6cd5f790fd8d23075fe3cb8bc25522304c54886b3709`; CB168O compile run `44736786708`, GMP/GMPXX, `runtimeExecution=false` |
| Manifest | `gates/Architecture_M6_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Case_Manifest.tsv`, SHA-256 `cab375d014112b6ab48fe468003b9a57b2918a717e6f56e7478f0417362c0204`, 967 required + 81 deferred |
| Harness | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94` |
| Dispatch | Request `m6-cp3-tb152-full-gate-20261120-v1`, event `1df9e84325d01184ba6ba6a794da5857838ddd06`; mailbox `workflow-mailbox:.workflow-mailbox/m6-cp3-tb152-full-gate/latest.json` |
| Executed gate | [run 44739657527](https://github.com/akashskypatel/Directional/actions/runs/44739657527); runtime job `136300003534` succeeded, compile job skipped |
| Result artifact | `14630642490`, ZIP SHA-256 `5bfce8410e736c1fce63c4c6fa9b272b20ff91ceac8044bb339c814bfaa3cd04` |
| Diagnostic log artifact | `14630682437`, ZIP SHA-256 `5e61550d6dfe1fa705656b5d70936bd7e55abf590941690af6b5d52a485372c9` |
| Frozen TB151 baseline | [run 44716246061](https://github.com/akashskypatel/Directional/actions/runs/44716246061), result `14619414153`, ZIP SHA-256 `c28d6ecc128bf9994d3c5f5ba2e2c799c192176f11d8818ca08c70d65caf1dab` |
| Snapshot inspected | [run 44738999656](https://github.com/akashskypatel/Directional/actions/runs/44738999656), archive artifact `14630236608`, source SHA `d888118ff14857423fed8939cb25b6e0b4289a8f`; internal archive SHA verified |

## Assessment — independent archive comparison

- Result ZIP checksums match both GitHub artifact digests. Internal `SHA256SUMS`: **1,942/1,942** TB152 files and **1,940/1,940** TB151 files valid. All 967 raw log hashes match the candidate ledger.
- `execution-boundary.json`: `planned=967`, `executed=967`, `passed=967`; `red=abnormal=missing=skipped=duplicate=control_bad=unexpected_pass=0`, `membership=1048`, `postflight=true`, `exit=0`.
- Ledger rows 1–966 match all TB151 metadata except expected per-process raw-log hashes. Their full raw log text matches under frozen **N1** (Google Test timing only), **N2** (line endings), and **N3** (complete `M3_CP4AB_FRAGMENT_DIAG record=region_support_projection` records as multisets; every other line remains in order). The M3 record multiset has **1,750 records**. All **504** `FieldAlignedCurveNetwork.slideContactArrival` records were compared unmasked and retain exact original order.
- Row 967 `FieldAlignedCarrierOccupancy.EdgePieceFaceSideFollowsTheFaceWindingAlongTheSlide` has verdict PASS, an independent successful Google Test raw record, `exit=0`, and a valid raw hash. First 491 rows remain PASS.
- The archived boundary confirms **`compile=false`, `configure=false`, `relink=false`, `benchmark=false`**. The compile job was skipped. The gate executed without source, test, fixture, selector or package mutation and without a production census.
- Source inspection confirms `edge_piece_face_side` appears only at its definition/declaration and the focused test; no production caller. The new case does **not** validate O49 wiring or the row686 piece oracle.

## Regression classification and recommendation

**No new stable event or candidate is supported.** All accepted and previously selected cases remain PASS and every earlier raw log matches. Carry existing open O47/C5/O49/H4 and the sphere row686 χ6 versus source χ2 (+4), plus rows669/698 `CutSearchExhaustedBeforeCellularity`. No direct production census was requested or executed. Stable accounting stays **66 events / 17 categories / 49 recurrences**, produced-witness debt **1**, deferred **81**. CP2 **491/491** remains accepted; CP3, selector497, D0, H4 and row686 are not promoted.

**Next canonical turn only:** `M6-CP3-TB152-P13-EDGE-PIECE-FACE-SIDE-FULL-GATE-REV`. The Review must independently re-open this immutable archive, re-derive the frozen comparisons, and freeze exact subsequent O49 ownership wiring and row686 test-only piece-oracle patches or record a specific stop. Do not implement them in TB152.
