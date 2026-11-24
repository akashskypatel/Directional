# CB-200 — cross-partition arc census test (2026-11-24 UTC)

## Situation

`M6-CP3-CB-200-P13-CROSS-PARTITION-ARC-CENSUS-TEST` satisfies the compile-only gate. The exact reviewed test-only change is committed. The eight required targets compile with GNU Multiple Precision arithmetic libraries (GMP and GMPXX). No Directional executable ran. Only `M6-CP3-TB-EXEC-180-P13-CROSS-PARTITION-ARC-CENSUS-FULL-GATE` is authorized next, in a separate turn.

## Background

[Adversarial review](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-180-folded-records--2026-11-24-utc) M1–M5 and [exact manifest](gates/Architecture_M6_CP3_CB200_P13_Cross_Partition_Arc_Census_Oracle_Exact_Manifest.md) replace the withdrawn prose plan. Row786 must independently establish membership of the certifier and plan partitions. Six corruptions must each fail the specified invariant. C4 is withdrawn. No production reader, region election, selector, manifest, build logic or test identity changed.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed patch | `Architecture_M6_CP3_CB200_P13_Cross_Partition_Arc_Census_Oracle_Exact.diff`; SHA-256 `d4cba179cec0d1971fac3c775b64cf8bb6ffcd913a8c464bb53b9bc0df2ebb26`, 9209 bytes, +155/−19, one file. |
| Source application | [Run 45350394518](https://github.com/akashskypatel/Directional/actions/runs/45350394518), base `fa9e16310925d69e53d88401ae19dd018eb8bc8e`, request `91ed008440d161153c89f69c47a69f64a3e5132c`, applied source `4c2b4cf16732cddb58252d5e758ea0b24449ed2a`. Patch SHA-256 `c1ea232468855f641e9ffde907f83217bc82fa33af1baf469b434ef7fea6c2d8`; result `14899837598` ZIP SHA-256 `f93faf36ea9a7f4f43b6c703c997844a5fdde5ce230cd507c4a69a6f0a9e02cd`; log `14899504448` ZIP SHA-256 `b0b629075d281ea05b68afa88568754ee444d4d8e303081326413cde1ab9b0d5`. Apply and push exit 0. |
| Compile | [Run 45351329597](https://github.com/akashskypatel/Directional/actions/runs/45351329597), job `138298392758`, request `93f421633a53f1aa6918677dd6fd4e31742e8ab1`, exact source `4c2b4cf16732cddb58252d5e758ea0b24449ed2a`. Configure, preflight and build succeeded. Test/benchmark job skipped. |
| Package | [14901170173](https://github.com/akashskypatel/Directional/actions/runs/45351329597/artifacts/14901170173), ZIP SHA-256 `8f4be71c9121cb0735ca07c1bc1dd83a66be20f4ab489b674a852dd122b6889f`, 28/28 internal checksums. Root `SHA256SUMS` SHA-256 `2699d635c1ffc298a73aa7468e885e05b535f821c92fe8b98e82d2d0ab6ab168`; source archive SHA-256 `c039e9bfb527ff8ffef0f2b687e0ebb555200593da46fdcc2309ac016c14e88d`. |
| Compile log | [14899953385](https://github.com/akashskypatel/Directional/actions/runs/45351329597/artifacts/14899953385), ZIP SHA-256 `0c2d9aa669d4d0a3cb305490f9269b194cdcd73593b72794fccf75904139360c`. Both compile ZIP hashes match the mailbox and artifact API. Expires 2026-12-01 UTC. |
| Mailbox | `workflow-mailbox:.workflow-mailbox/m6-cp3-cb200-compile-20261124/runs/45351329597-attempt-1.json`, blob `251a7c2c0f31c4ddf054d86ad42a7a457b06c74a`, result success. |
| Scope and clean state | `runtimeExecution=false`; `semanticContracts=compiled-not-executed`; five source status files empty. Preflight and build exit 0. `DIRECTIONAL_ENABLE_GMP=ON`; link uses `libgmpxx.so` and `libgmp.so`. |

The sole changed file `tests/FieldAlignedCurveNetworkTests.cpp` has preimage git blob `ef6a0b1a31ea283fde076333cb0c00ae0f48f166`, preimage SHA-256 `2b32275e271299da175317aa1d70514ede85926f8976fb5ff083ece975c2650a`, postimage SHA-256 `6e83fc338d7632c4540691cb12403d7b495ecd0ddea52f31d792c29c267e0b7b`. Source package postimage matches. The reviewed patch passes reverse-application check. The eight targets are `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`. The package contains two libraries and six executables. No local compile, project binary execution, membership discovery or benchmark occurred. Static manifest, deferred ledger and harness identities match.

TB179 remains rejected at 1002/1003, six controls recovered, row786 RED. Accepted TB169 993/993, CP2 491/491, stable 67 events / 17 categories / 50 recurrences, witness debt1/deferred81 remain unchanged. No production acceptance or CP3/497/D0/H4 promotion.

## Recommendation — separate TB-EXEC-180

Use the immutable package above. Submit this request only in the next turn after its entry STATUS write. No rebuild, repair, relink, test modification or benchmark is authorized.

```json
{
  "schema_version": 1,
  "operation": "test_benchmark",
  "request_id": "m6-cp3-tb180-exec",
  "mailbox_key": "m6-cp3-tb180-exec",
  "executor_sha": "4c2b4cf16732cddb58252d5e758ea0b24449ed2a",
  "semantic_source_sha": "4c2b4cf16732cddb58252d5e758ea0b24449ed2a",
  "turn_id": "M6-CP3-TB-EXEC-180-P13-CROSS-PARTITION-ARC-CENSUS-FULL-GATE",
  "harness_path": ".agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh",
  "harness_sha256": "78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94",
  "environment": {
    "CANDIDATE_ARTIFACT_ID": "14901170173",
    "EXPECTED_SOURCE_SHA": "4c2b4cf16732cddb58252d5e758ea0b24449ed2a",
    "EXPECTED_CANDIDATE_ZIP_SHA256": "8f4be71c9121cb0735ca07c1bc1dd83a66be20f4ab489b674a852dd122b6889f",
    "EXPECTED_ROOT_MANIFEST_SHA256": "2699d635c1ffc298a73aa7468e885e05b535f821c92fe8b98e82d2d0ab6ab168",
    "EXPECTED_SOURCE_ARCHIVE_SHA256": "c039e9bfb527ff8ffef0f2b687e0ebb555200593da46fdcc2309ac016c14e88d",
    "CASE_MANIFEST": ".agents/Directional/gates/Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv",
    "CASE_MANIFEST_SHA256": "2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724",
    "EXPECTED_CASE_COUNT": "1003",
    "MEMBERSHIP_LEDGER": ".agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv",
    "MEMBERSHIP_LEDGER_SHA256": "fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce"
  },
  "artifact_prefix": "m6-cp3-tb180-cross-partition-arc-census",
  "retention_days": 14
}
```

The unchanged TB179 manifest has 1003 rows and 81 deferred names; expected membership 1084. Runtime membership is a TB preflight obligation. All 1003 cases must PASS. Row786 receipt `m3Cp4c3PlanInteriorArcCensusCorruptions` must record `certifierLabelErased=certifierLabel`, `certifierLabelWrong=certifierLabel`, `crossedFaceCount=arcFaceCount`, `duplicateFace=arcFaceDuplicate`, `planLabel=planLabel`, and `reasonMissing=reason`.

Compare all 1003 raw records and ledger rows with TB179 result `14895572803`, ZIP SHA-256 `aeaacb099ea7d51292706802ccf3a9a64702abf70575d01bd8c52847acb0c636`. Apply only N1 (elapsed time), N2 (line endings), N3 (counted complete `M3_CP4AB_FRAGMENT_DIAG` records). Only row786 may change. Line locations move +65 after old 5585 and +136 after old 20108. Any changed record containing `FieldAlignedCurveNetworkTests.cpp:` or any other difference means STOP. Review must adjudicate recurrence closure, seven controls and new accepted baseline. J6, K6, row979, Branch A, CB-190 and E5 remain held. No promotion.
