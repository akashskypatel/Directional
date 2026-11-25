# CB-205 — slide-entry activation reach (2026-11-25 UTC)

## Situation

`M6-CP3-CB-205-P13-SLIDE-ENTRY-ACTIVATION-REACH` meets the compile-only gate. The exact reviewed test append is committed. Eight targets compiled with GNU Multiple Precision arithmetic libraries (GMP and GMPXX). No Directional executable ran. Runtime acceptance remains at TB184 (1005/1005). The next turn is `M6-CP3-TB-EXEC-185`, in a separate session.

## Background

The [exact manifest](gates/Architecture_M6_CP3_CB205_P13_Slide_Entry_Activation_Reach_Exact_Manifest.md) and [adversarial review](Architecture_M6_CP3_TB_REV_184_Adversarial_Review_20261125.md) authorize one test at the end of `tests/FieldAlignedCurveNetworkTests.cpp`. The test records production and staged network results for thirteen exact fixture recipes, includes the explicit unstaged sphere control, and records the first eligible polyline recipe. Its receipts are diagnostic. No test result, digest equality, activation reach or runtime elapsed time is established by compilation. The production default remains `stopAtLaterSlideEntry=false`; the arrival priority remains `ArcLengthFiltered`. No existing test, fixture, selector, product source or workflow changed.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed diff | SHA-256 `d39216d278b42dd9ee72c62afe3c5826d080c03089fabfd805329347dd6f777f`, 8747 bytes, one path, +169/−0. Semantic preimage `754369dfb9e98d209e79802d8b13855f42a77f26`. |
| Source snapshot | [Run 45554110724](https://github.com/akashskypatel/Directional/actions/runs/45554110724), job `139002003900`, source `990e0fccc6bb155df1c3942246c8e0d55454e586`, artifact `14994278789`, ZIP SHA-256 `aecc3c47a39712a7d17b127422455ca8400746bd760db5fdf60ebcf42243079b`, archive SHA-256 `5e55948e7692f87bb72bacaa463662cf7a50a6dce4cd717b9f09249cf6f4b478`, 5829/5829 member checks. |
| Source application | [Run 45554541672](https://github.com/akashskypatel/Directional/actions/runs/45554541672), job `139003494108`, request `fedd44376ccbca59f4db75de9e2c80616cd67161`, semantic source `21087c8285a5dd367cc16f610386accc061bd194`. Transport SHA-256 `ad525de4874830eaa4050b442b1803492375ba019aaeb304419fc6ee614e0e72`. Result `14995815561` ZIP SHA-256 `c2b11e67d311c2fc8075057c70f89e71c1317273c532f218aabacfe95ec6073c`; log `14995665793` ZIP SHA-256 `6895034ed338d6e93169a487709ad1f5fffd57283f213e9616b11cb968837cdd`. Apply/push exit 0. Owner-authorized Drive retirement passed. |
| Compile | [Run 45554728034](https://github.com/akashskypatel/Directional/actions/runs/45554728034), job `139004065204`, request `c956f30e7ef4ce36312022b1fa1edca2bdfa9503`, source `21087c8285a5dd367cc16f610386accc061bd194`. Configure, preflight and build passed. Test + Benchmark skipped. |
| Candidate package | [14995401750](https://github.com/akashskypatel/Directional/actions/runs/45554728034/artifacts/14995401750), ZIP SHA-256 `7e66ef7b3b16e76618a60b250a76038e65bf2e092601958f8252ac993b778da9`, 28/28 internal checksums, root SHA256SUMS SHA-256 `255e344116e2faa2d351b637cdfc6d11805b83352965f794b8bddaf56409f5d3`, source archive SHA-256 `bba6f2ce82c27a1481dad5fb16952b88476fca25411840a3e6d588ad67d2502e`. Expires 2026-12-02T05:39:06Z. |
| Compile log | [14995621446](https://github.com/akashskypatel/Directional/actions/runs/45554728034/artifacts/14995621446), ZIP SHA-256 `6230150d92da3155d7b6c908ba68b7c11db0d46c8b2eb3e6669bcb6519408f6d`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, clean source status files, preflight and build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`; generated link command includes `libgmpxx.so` and `libgmp.so`. |

The preimage SHA-256 `d4543d0844013a50dc551fac6f66468412903f9f3cad2bf3affc0ca5a8cf95c5` and postimage SHA-256 `03abb0a6abcd8dbafb40bfe4dfbc56c0a2744a5eca9353749c1bf08b9cf3d72d` match the frozen manifest. The regenerated diff is byte-identical to the reviewed diff. The remote change contains one file (+169/−0) with Git blob `b40ea4b82d6bccce521da20aceea2e0726b50399`. The packaged source matches the postimage and the unchanged production tracing source. The case manifest, exact 1005-row prefix, deferred ledger and harness bytes match their frozen hashes. The package contains two libraries and six executables. The compiler cache returned 142/143 hits (99.30%). No local compile, runtime, benchmark or membership discovery occurred.

Accepted TB184 stays 1005/1005. CP2 stays 491/491. Stable accounting remains 67 events / 17 categories / 50 recurrences; witness debt1/deferred81. P1 supported and D-U carried. No CP3/497/D0/H4 promotion, activation or J6/E5/CB-190 repair. The later activated sphere stop stage/locus and other fixture reach remain unmeasured.

### Closeout checks

- Temporary-state cleanup [run 45554743934](https://github.com/akashskypatel/Directional/actions/runs/45554743934), job `139004076604`, result `14994952320` ZIP SHA-256 `9222b86525d81e83399c89b9b8116d59dbd76fcfe65f01e78d92f8c9ad372414`, commit `e8b61f740e25d340a58fca2caf1d11e3792281cb`. Cleanup removes only the CB-205 snapshot marker and cleanup manifest. The durable dispatcher and mailbox remain.
- Document drift audit: zero errors. The existing ORIENTATION size warning remains. Handoff, orientation and roadmap protection warnings reflect only authorized current-turn navigation updates; no protected section was removed.
- Process deviations: initial handoff/policy reads preceded full snapshot-mode selection. Full pre-work LESSONS coverage is not established. The external turn-based coding skill fetch returned HTTP 404. One PR-comments request used an invalid argument and was corrected. Early mailbox reads returned stale records or HTTP 404 before publication. One local payload-helper invocation used a path instead of a hash and was corrected before any dispatch. The exact tool ledger was not retained through context compaction. These issues do not change the verified patch or compile evidence.

## Recommendation — separate TB-EXEC-185

Use only the immutable candidate package. Preserve archived executable mode bits with ordinary `unzip` or `tar`. Do not repair contents or permissions, rebuild, relink, change tests or run benchmarks. Submit the request only after the separate successor entry beacon:

```json
{
  "schema_version": 1,
  "operation": "test_benchmark",
  "request_id": "m6-cp3-tb185-exec",
  "mailbox_key": "m6-cp3-tb185-exec",
  "executor_sha": "21087c8285a5dd367cc16f610386accc061bd194",
  "semantic_source_sha": "21087c8285a5dd367cc16f610386accc061bd194",
  "turn_id": "M6-CP3-TB-EXEC-185",
  "harness_path": ".agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh",
  "harness_sha256": "78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94",
  "environment": {
    "CANDIDATE_ARTIFACT_ID": "14995401750",
    "EXPECTED_SOURCE_SHA": "21087c8285a5dd367cc16f610386accc061bd194",
    "EXPECTED_CANDIDATE_ZIP_SHA256": "7e66ef7b3b16e76618a60b250a76038e65bf2e092601958f8252ac993b778da9",
    "EXPECTED_ROOT_MANIFEST_SHA256": "255e344116e2faa2d351b637cdfc6d11805b83352965f794b8bddaf56409f5d3",
    "EXPECTED_SOURCE_ARCHIVE_SHA256": "bba6f2ce82c27a1481dad5fb16952b88476fca25411840a3e6d588ad67d2502e",
    "CASE_MANIFEST": ".agents/Directional/gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv",
    "CASE_MANIFEST_SHA256": "a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587",
    "EXPECTED_CASE_COUNT": "1006",
    "MEMBERSHIP_LEDGER": ".agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv",
    "MEMBERSHIP_LEDGER_SHA256": "fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce"
  },
  "artifact_prefix": "m6-cp3-tb185-slide-entry-activation-reach",
  "retention_days": 14
}
```

Require 1006/1006 PASS and 1087 members (1006 gated + 81 deferred). Compare every ledger field except raw-log hashes, and the raw logs of the first 1005 rows, to accepted TB184 result `14992995631` ZIP SHA-256 `8686e64c07fed5e72a5285fa6071a50944f1ea0b24c4b9e61eea831c46e0dd9c`. Each raw hash must match its own ledger. Only established N1–N3 normalizations; no new material allowance for any existing row. Row979's prior extra trace block is now part of the accepted TB184 baseline. Check exact membership, resource commands, immutable postflight and the elapsed time of row1006. STOP on any missing, duplicate, extra, skipped, abnormal or RED case, material mismatch, false control, or immutable postflight failure.

Verify all thirteen exact keys and the polyline-selection receipt. For the sphere require successful production, explicit false and explicit true; production digest equals explicit false and differs from true; staged stop count 4. Verify required baseline builds and published-network bindings. A missing input or network failure must retain its exact typed outcome and leave dependent readers UNKNOWN. See the [exact manifest](gates/Architecture_M6_CP3_CB205_P13_Slide_Entry_Activation_Reach_Exact_Manifest.md) for recipe-specific conditions. The row1006 receipt diagnoses reach; it does not prove global activation safety. TB-REV-185 classifies measured recipes and readers (S4 + U2) and marks other families UNMEASURED. CB-206 remains held until the independent review freezes the exact signature-default flip, rows648/978/979, row979 label and row1006 transcript. V5 BunnyRandom waits for activation.
