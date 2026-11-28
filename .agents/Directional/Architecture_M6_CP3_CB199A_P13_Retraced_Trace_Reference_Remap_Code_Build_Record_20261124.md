# CB-199A — retraced trace reference remap (2026-11-24 UTC)

## Situation

`M6-CP3-CB-199A-P13-RETRACED-TRACE-REFERENCE-REMAP` is complete as a Code + Build turn. The amended helper and its guard compile. The helper has no production caller. No runtime execution occurred. Only `M6-CP3-TB-EXEC-178-P13-RETRACED-TRACE-REFERENCE-REMAP-FULL-GATE` is authorized next, in a separate turn.

## Background

[TB-REV-177 adversarial review](Architecture_M6_CP3_TB_REV_177_Adversarial_Review_20261124.md) J1–J6 and the [amended exact manifest](gates/Architecture_M6_CP3_CB199A_P13_Amended_Exact_Manifest.md) freeze the two-path +463/−0 change. The original diff is withdrawn. The amended helper returns the arrival-port binding separately from the event records; it does not rewrite port ownership into event fields. It remaps struck trace/segment references from exact path pieces and fails closed on unsupported or ambiguous references. The appended guard checks the remap, retained ports and unchanged input, with positive and negative controls. These contracts are compiled but not verified by runtime execution.

## Assessment

| Evidence | Exact authority |
|---|---|
| Snapshot | [Run 45311659189](https://github.com/akashskypatel/Directional/actions/runs/45311659189), job 138168704539, source `5bad4742599824c5bab233d23f18650fd17ca48d`; artifact 14883187899 ZIP `ef1320cd9114bfdec7121ca8452a5264eb0397eb06c81b1533be6dfd6d97209e`; source manifest 5840/5840 |
| Frozen diff | `Architecture_M6_CP3_CB199A_P13_Retraced_Trace_Reference_Remap_Amended_Exact.diff`; SHA-256 `cd43c3f002d890745701eff5f00de4cb8a658585d9ef414614fdbbcc875d4c5a`, 24726 bytes, +463/−0; `git apply --check` and `git diff --check` pass |
| Source application | [Run 45312024568](https://github.com/akashskypatel/Directional/actions/runs/45312024568), job 138170002370, result 14883667652 ZIP `010d99dbbb2f1ac5f000afd05ed937d9b2e4dbc0480f037cd89592dcd59efe6f`; commit `de65101eb04c73e08ea4b6b31968975f71d9d909`; only the two authorized paths; owner retired the temporary Drive file after push |
| Compile | [Run 45312324524](https://github.com/akashskypatel/Directional/actions/runs/45312324524), job 138171080435; exact source `de65101eb04c73e08ea4b6b31968975f71d9d909`, eight required targets; GMP/GMPXX; `runtimeExecution=false` |
| Compile package | Artifact `14883418907` ZIP SHA-256 `8452d0bbfad23c464c7ad29de2c9b92a4acde9bdbb96347a55aeb84917ef8beb`; 28/28 internal hashes; root `SHA256SUMS` SHA-256 `32a46319cff53f42c3ca6b938227cc8fdee0a304adf03d3c008d38d10c52f7e9`; source archive SHA-256 `fab1353b6bdf5c4f5a057dc1aa3996353f5257ace2c738df4c5caee0d164b4bd` |
| Compile log | Artifact `14883951343` ZIP SHA-256 `23b32c6a3654a7928b1d2a6c475ff843fe30e7900f4dac4088c7f87bfcd2d7b4` |

The new `src/geometry/RetracedTraceReferences.h` SHA-256 is `bcab2d6292b9f1317471c0659e714b4afd7339e1def7c07d5d409f85b2356944` (Git blob `1bdeb3da16761060bc92c2859cbff706be4a960c`). Test preimage Git blob `943187e3a732eca91bd3a824b9c05f9e8ca15bcb`; `tests/FieldAlignedCurveNetworkTests.cpp` postimage SHA-256 `e13d7182355d071e0fe6bd0dc645b8288037af0bf609eb59437711dda7d29b89` (Git blob `d03386d2b1b617166bb7af1dc68a0ae07055abd4`). Remote and package bytes match these identities. No product integration, fixture, selector, manifest or workflow change. No test, benchmark or project executable ran.

Latest runtime evidence is still TB177, rejected at 994/1001 with seven existing RED and H4 comparison STOP. Accepted TB169 993/993, CP2 491/491; stable 67 events / 17 categories / 50 recurrences; witness debt1, deferred81. No CP3/497/D0/H4 promotion.

## Recommendation — exact separate TB-EXEC-178 plan

Use the immutable compile package above. Submit the following durable dispatcher request **only in the next turn**, after its initial STATUS write. It checks out the exact executor revision and invokes the unchanged artifact-only harness with `--execute`; do not configure, compile, repair or relink. No benchmark is authorized. The harness verifies the provider and local ZIP hashes, internal manifest, source archive, source revision and command boundary; use `unzip` to preserve executable permissions. It checks the frozen case manifest and deferred ledger, enumerates membership, launches every case in a fresh process (600 s per case), and verifies the package and staged view after execution.

```json
{
  "schema_version": 1,
  "operation": "test_benchmark",
  "request_id": "m6-cp3-tb178-exec",
  "mailbox_key": "m6-cp3-tb178-exec",
  "executor_sha": "de65101eb04c73e08ea4b6b31968975f71d9d909",
  "semantic_source_sha": "de65101eb04c73e08ea4b6b31968975f71d9d909",
  "turn_id": "M6-CP3-TB-EXEC-178-P13-RETRACED-TRACE-REFERENCE-REMAP-FULL-GATE",
  "harness_path": ".agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh",
  "harness_sha256": "78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94",
  "environment": {
    "CANDIDATE_ARTIFACT_ID": "14883418907",
    "EXPECTED_SOURCE_SHA": "de65101eb04c73e08ea4b6b31968975f71d9d909",
    "EXPECTED_CANDIDATE_ZIP_SHA256": "8452d0bbfad23c464c7ad29de2c9b92a4acde9bdbb96347a55aeb84917ef8beb",
    "EXPECTED_ROOT_MANIFEST_SHA256": "32a46319cff53f42c3ca6b938227cc8fdee0a304adf03d3c008d38d10c52f7e9",
    "EXPECTED_SOURCE_ARCHIVE_SHA256": "fab1353b6bdf5c4f5a057dc1aa3996353f5257ace2c738df4c5caee0d164b4bd",
    "CASE_MANIFEST": ".agents/Directional/gates/Architecture_M6_TB178_P13_Retraced_Trace_Reference_Remap_Full_Gate_Case_Manifest.tsv",
    "CASE_MANIFEST_SHA256": "921bd04bbfab596da6679083d5880d3f4893126e19a91c4687ba5ba63827e8ed",
    "EXPECTED_CASE_COUNT": "1002",
    "MEMBERSHIP_LEDGER": ".agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv",
    "MEMBERSHIP_LEDGER_SHA256": "fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce"
  },
  "artifact_prefix": "m6-cp3-tb178-retraced-trace-reference-remap",
  "retention_days": 14
}
```

Acceptance: execute 1002/1002; 1083 members (1002 gated +81 deferred); 995 PASS and exactly seven RED rows 445/652/653/656/658/660/786. Row1002 `RetracedTraceReferences.RemapsExactStruckSegmentAndEndpointPortWithoutPublication` must execute and PASS. No skipped, duplicated, missing or abnormal cases; verify postflight. The expected failure exit of the harness due to existing required controls is not a successful product gate.

Compare all 1001 inherited ledger rows and raw transcripts against TB177 artifact `14871900641` ZIP SHA-256 `8c5bce907f59b77207833153912805cccca6fa122c70ff9f299a64f68102b068`. Preserve the exact first-1001-row manifest prefix SHA-256 `0f85400ff9713fc8a835f308304ded1db9830e668211bab71c88d580b2e84642` and accepted prefix. Apply only N1 (GoogleTest elapsed time), N2 (line endings), N3 (counted complete `M3_CP4AB_FRAGMENT_DIAG` records as a multiset; preserve the remaining bytes and order). No assertion-line move is authorized; row652/656 receipt bytes must be identical. Any other difference or failed guard means STOP to independent Review; preserve raw evidence and do not fix or rerun selectively to obtain green status. Record exact execution artifact, hashes, membership, ledger, raw logs, exit and postflight; update the regression tracker only from verified evidence. No acceptance promotion from this isolated guard. `M6-CP3-TB-REV-178` must independently adjudicate before CB-199B or CB-200 work.
