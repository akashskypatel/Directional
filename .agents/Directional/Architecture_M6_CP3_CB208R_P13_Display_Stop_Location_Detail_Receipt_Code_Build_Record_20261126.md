# CB-208R — display stop-location detail receipt (2026-11-26 UTC)

## Situation

`M6-CP3-CB-208R-P13-DISPLAY-STOP-LOCATION-DETAIL-RECEIPT` meets the compile-only gate. The exact reviewed test change is committed. Runtime acceptance is not established. The next separate turn is `M6-CP3-TB-EXEC-186`.

## Background

The [CB-208R manifest](gates/Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Exact_Manifest.md) and [adversarial review Z1–Z3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb_rev_186t_adversarial_review_20261126md) control the change. The [CB-208 manifest](gates/Architecture_M6_CP3_CB208_P13_Display_Stop_Location_Authority_Exact_Manifest.md) controls the retained runtime plan, not the withdrawn diff. Row858 now checks each reported location. The unlocated completion branch rejects invented geometry, requires stage/code notes and checks `is_produced() == false`. The new `SphereDisplayStopDetail` receipt records the completion detail code and first invalid producer stage/reason. The positive location controls and row1005 remain unchanged. No product change occurred.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed diff | 3806 bytes, SHA-256 `29ce73c74f4a1ab2dcd6295048002c6f5e882796e076d19021489deb7f44a02c`. `tests/SurfaceCellTracingDisplayTests.cpp` only, +39/−4. Preimage `b054f3b2fabc07553c0efcef293048ff46a18649609997665593cb6827d10a75`; postimage `1957d13f6aa2c86d84a337cef192e090ac6a9695bd45b79fcf8629cffc2c8712`. |
| Snapshot | [Run 45874712497](https://github.com/akashskypatel/Directional/actions/runs/45874712497), source `fc3f31cb20b7981a3b47b4ea01dd60ca16055968`, artifact `15144362628`, ZIP SHA-256 `fb2e2d5d327b598f7685bfcce8599c671710159bbc4b85502477567042175a38`, archive SHA-256 `36d5f0d8fde8eab0556aad6adc0809997e45eb83fa93e35a22b976680a3d25ca`, 5859/5859 checks. |
| Source application | [Run 45895610123](https://github.com/akashskypatel/Directional/actions/runs/45895610123), job `140168764905`, request `0de830d480c063d807af4b92d9d9449fdaa468c7`, applied source `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`. Patch SHA-256 `dfa077e460039ae682f13a823306d19254da4955a0dabff91034a02456f5caf3`, diff body `0353c953830fabc47b43bbe72a5e37581bd0be13e06b565fb2f3af8af36f483c`. Result `15154265360`, ZIP SHA-256 `6e9ce2d093773448e8674da38eb6c5693809e495f366e2c2e70fe86a3f1a6377`; log `15153915870`, ZIP SHA-256 `49745494fd0c963d2936c8191b7005cc91a46ae5a86243575e04380bb59c285d`. Apply/push exit 0. Owner connector deleted the staged Drive file after verification. |
| Compile | [Run 45895803711](https://github.com/akashskypatel/Directional/actions/runs/45895803711), job `140169419475`, request `4dfba64325bd14bfd5ffb8fe1ccbf433a427e8aa`, source `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`. Configure, preflight and build passed. |
| Candidate | [15154205483](https://github.com/akashskypatel/Directional/actions/runs/45895803711/artifacts/15154205483), ZIP SHA-256 `cd84ab8b591759f4e01b5aaa685b048d69ed0a30a6b7e63dde6b1a97031971e8`, root manifest SHA-256 `4c6ad586ca35afff9ad61da3cdae88c62d0356fec906d37c0b9cc1a67e477648`, source archive SHA-256 `5c316970e7163432d3bffb0ec2ac1646cef27ce4bc13ec999a9d70ae447eeb79`. 28/28 checks, expires 2026-12-03T21:08:08Z. |
| Compile log | [15153701287](https://github.com/akashskypatel/Directional/actions/runs/45895803711/artifacts/15153701287), ZIP SHA-256 `76868891a3e41c21a01bf94bfc05c0eb949449905f3bb75f17c9958d37977aee`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, all five source-status files empty, preflight/build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`, generated link command includes `libgmpxx.so` and `libgmp.so`. Two libraries and six executables, eight exact targets, archived executable modes present. |

The remote test blob equals the verified patch postimage. All 1177 archived regular files were compared with the verified snapshot. Only the exact test change, `STATUS` and the dispatcher request differ. No other test, product, fixture, selector, harness, workflow or build logic changed. Compiler cache: 142/143 hits (99.30%). No local compilation, test discovery, Directional execution or benchmark occurred.

TB187Q remains accepted at 1006/1006 before activation. CP2 remains accepted at 491/491. Stable regression totals remain 67 events, 17 categories and 50 recurrences. Witness debt1/deferred81 remain. No CP3/497/D0/H4 promotion, no CB-207D, and no new runtime claim. The exact completion rejection predicate and fine-resolution close_sheets termination remain unmeasured.

### Closeout checks

- [Cleanup run 45896125061](https://github.com/akashskypatel/Directional/actions/runs/45896125061), job `140170467698`, result `15154325583` ZIP SHA-256 `dfe4099382277c731cc5c433803f349f304e2ecbdb1e80901608c1c550dc40d8`, cleanup commit `41735c4b51c643e08c6ecf29fa2cc1d464edf739`. Snapshot trigger and cleanup manifest removed; durable workflows and dispatcher retained.
- Document drift audit: zero errors; the existing ORIENTATION size warning remains. Current navigation and evidence only; no durable section removed.
- Process limitations: the initial attempt inspected several repository files before completing snapshot selection. Full pre-work policy/LESSONS and external turn-based skill review are not established. Early mailbox queries returned absent/stale records before terminal publication. Full multi-attempt tool ledger is not available. These limitations do not change the verified patch or compile evidence.

## Recommendation — separate TB-EXEC-186

Use candidate `15154205483` and source/executor `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`. Preserve the archived executable mode bits with ordinary `unzip` or `tar`. Do not rebuild, relink, repair the artifact, regenerate discovery, or edit any source, test, fixture, selector or harness. Run the unchanged 1006-case gate with the 81-row deferred ledger. Require 1087 total members, 1006 organic PASS and valid immutable postflight. Do not add a full-gate elapsed-time cutoff. Use the [CB-208 runtime plan](gates/Architecture_M6_CP3_CB208_P13_Display_Stop_Location_Authority_Exact_Manifest.md), amended by the [CB-208R manifest](gates/Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Exact_Manifest.md). The [CB-206 manifest](gates/Architecture_M6_CP3_CB206_P13_Slide_Entry_Activation_Exact_Manifest.md) retains the exact activation predictions. Compare ordered ledgers and complete raw logs with TB185V result `15066180913` under frozen N1–N3 only. TB187Q result `15130286146` is the accepted preactivation QF1 comparator. Preserve rows393/648/669/843/844/858/968/972/978/979/1005/1006 and explicit unstaged controls.

Frozen gate inputs and exact dispatcher environment values:

| Key | Value |
|---|---|
| `CANDIDATE_ARTIFACT_ID` | `15154205483` |
| `EXPECTED_SOURCE_SHA` | `cc25a6402cdd3ca1a33a9a9778250176b182bb2a` |
| `EXPECTED_CANDIDATE_ZIP_SHA256` | `cd84ab8b591759f4e01b5aaa685b048d69ed0a30a6b7e63dde6b1a97031971e8` |
| `EXPECTED_ROOT_MANIFEST_SHA256` | `4c6ad586ca35afff9ad61da3cdae88c62d0356fec906d37c0b9cc1a67e477648` |
| `EXPECTED_SOURCE_ARCHIVE_SHA256` | `5c316970e7163432d3bffb0ec2ac1646cef27ce4bc13ec999a9d70ae447eeb79` |
| `CASE_MANIFEST` | `.agents/Directional/gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv` |
| `CASE_MANIFEST_SHA256` | `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587` |
| `EXPECTED_CASE_COUNT` | `1006` |
| `MEMBERSHIP_LEDGER` | `.agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv` |
| `MEMBERSHIP_LEDGER_SHA256` | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |

Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. No reach-termination diagnostic mode. Row858 must pass and print exactly `SphereDisplayStop stage=completion code=NotProductionReady sourceFace=- relatedSourceFace=- sourceEdge=- sourceVertex=-`. Compare the 69196-byte/397-line activated prefix through its LF with SHA-256 `32d6de52259ed91a9968109bda21b68d3dc4d37a3b1aed7b59193301c61a42d9` under N1–N3. Record `SphereDisplayStopDetail` verbatim; do not predict the detail. Row972 is predicted PASS. STOP on any RED, invalid boundary or missing/mismatched required receipt. Report every other material difference with complete lines for independent review.

After a valid full gate only, use the same candidate and harness for V5 with `CASE_MANIFEST=.agents/Directional/gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv`, SHA-256 `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`, `EXPECTED_CASE_COUNT=3` and no membership ledger. Retain all Cylinder, BunnyRandom (`offgate:360`) and Vase outcomes and raw logs. Check both pending-wall contacts `142:2→87:0` and `26:1→99:0`. `InvalidNetworkBinding` or carrier-contact struck-index rejection is STOP. No V5 result grants full-gate membership or deferred witness credit. Then `M6-CP3-TB-REV-186` independently adjudicates gate and V5, and freezes the completion-site step from the measured detail. No successor execution in CB-208R.
