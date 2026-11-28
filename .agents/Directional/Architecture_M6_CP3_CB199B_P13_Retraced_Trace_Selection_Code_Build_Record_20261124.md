# CB-199B — retraced trace selection (2026-11-24 UTC)

## Situation

`M6-CP3-CB-199B-P13-RETRACED-TRACE-SELECTION` satisfies the compile-only gate. The exact reviewed three-path change is committed. The eight required targets compile with GMP and GMPXX (the GNU Multiple Precision arithmetic libraries). No Directional executable ran. Only `M6-CP3-TB-EXEC-179-P13-RETRACED-TRACE-SELECTION-FULL-GATE` is authorized next, in a separate turn.

## Background

[TB-REV-178 independent review](Architecture_M6_CP3_TB_REV_178_Retraced_Trace_Reference_Remap_Independent_Review_20261124.md) and [adversarial review](Architecture_M6_CP3_TB_REV_178_Adversarial_Review_20261124.md) K1–K6 authorize the [exact manifest](gates/Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Exact_Manifest.md) without amendment. The producer selects reciprocal exact edge paths after tracing. It records the retained arrival port, preserves original trace and port identities, remaps references atomically and checks equality and digest. The appended guard must prove the actual A2a product owns every port exactly once. No downstream reader, region election, existing fixture, selector or workflow changed in the semantic commit.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed patch | `Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Exact.diff`, SHA-256 `02cc43c4b4ed3144df4bb08d7a8a857afcb6ce6f0cfa582c08da0a3031411fe5`, 11,639 bytes, +172/−0, exactly three paths. |
| Source application | [Run 45332657490](https://github.com/akashskypatel/Directional/actions/runs/45332657490), base `9c732898f72ea101043491f46e918eb8086390e2`, request `f2f0d3ee3dad1d8eb585e51b51a6576d19fa29f2`, applied source `5d9468d168ee3c9eed086bd787979ced7f86843b`. Result [14892726653](https://github.com/akashskypatel/Directional/actions/runs/45332657490/artifacts/14892726653) ZIP `4fbfd74d99331078cfe7daf30ac7a106f8b0593d98961400cd2318bba1d286c4`; log [14891984286](https://github.com/akashskypatel/Directional/actions/runs/45332657490/artifacts/14891984286) ZIP `aee455ddc4f4a02fe38adfc6bf778099155d603f5ec08d72166e1a6b7227358c`. Both ZIP hashes match the mailbox. Apply and push exit 0. |
| Compile | [Run 45332816377](https://github.com/akashskypatel/Directional/actions/runs/45332816377), job `138237952149`, request `7b337ad64af317364b45e81254a3e5f68514398d`, exact source `5d9468d168ee3c9eed086bd787979ced7f86843b`. Configure, preflight and build succeeded. Test/benchmark job skipped. |
| Package | [14893165901](https://github.com/akashskypatel/Directional/actions/runs/45332816377/artifacts/14893165901), `m6-cp3-cb199b-result-45332816377`, ZIP SHA-256 `0ff23208d9329a02951d1aea83c0631ac7790b92bb3bfb46639d52d33e7c225c`; 28/28 internal checksums; root `SHA256SUMS` SHA-256 `b2c0c0fdc8b2cf530bf05b472d7525cd2d0be234b212f7d466564618b6d3d668`; source archive SHA-256 `e5e6e9d24a553e1b1d0d4b6f556ea23d9d01f2e2ff49a67d4d65e2908f00bb21`. |
| Compile log | [14893825225](https://github.com/akashskypatel/Directional/actions/runs/45332816377/artifacts/14893825225), `m6-cp3-cb199b-log-45332816377`, ZIP SHA-256 `eff4fe0437dfbb758b1e4c29c146b35d371bf12a2a8a99043e33c32705b975fd`. Both compile ZIP hashes match the immutable mailbox and artifact API. Expires 2026-12-01 UTC. |
| Mailbox | `workflow-mailbox:.workflow-mailbox/m6-cp3-cb199b-compile-20261124/runs/45332816377-attempt-1.json`, blob `137c200d23aba72f76069fa9386cb2f6e0f9a7ca`, result success. |
| Scope and clean state | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`. All five source status files are empty. Preflight and build exit code 0. `DIRECTIONAL_ENABLE_GMP=ON`; actual link command includes `libgmpxx.so` and `libgmp.so`. |

The source archive matches all three frozen postimages:

| Path | SHA-256 |
|---|---|
| `include/directional/geometry/SurfaceCellTracing.h` | `daf7b7a0c9fb66bcf58db10b534e502f7294463fb94fa7b4b30c10243e1f19d3` |
| `src/geometry/SurfaceCellTracing.cpp` | `642c829db50360c59ddb7b5ff2b2871a904b639cd1749a3bf11b5d74c911ada9` |
| `tests/FieldAlignedCurveNetworkTests.cpp` | `2b32275e271299da175317aa1d70514ede85926f8976fb5ff083ece975c2650a` |

The reviewed diff passes `git apply --reverse --check` against the source archive. The source commit has only the three authorized paths. The eight targets are `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`. The package contains two libraries and six executables. No local compilation, project binary execution, membership discovery or benchmark occurred in the resumed session. The manifest and deferred ledger pass static identity and count checks; runtime membership remains the TB preflight obligation.

Latest runtime evidence remains TB178, rejected at 995/1002 with seven existing mechanical failures. Accepted TB169 993/993 and CP2 491/491 remain unchanged. Stable 67 events / 17 categories / 50 recurrences, witness debt 1, deferred 81. No production acceptance or CP3/497/D0/H4 promotion.

## Recommendation — exact separate TB-EXEC-179 plan

Use the immutable compile package above. Submit this request **only in the next turn**, after its entry STATUS write. The frozen harness verifies archive hashes, source, command boundary and membership. It executes each case in a fresh process. No rebuild, repair, relink, test modification or benchmark is authorized.

```json
{
  "schema_version": 1,
  "operation": "test_benchmark",
  "request_id": "m6-cp3-tb179-exec",
  "mailbox_key": "m6-cp3-tb179-exec",
  "executor_sha": "5d9468d168ee3c9eed086bd787979ced7f86843b",
  "semantic_source_sha": "5d9468d168ee3c9eed086bd787979ced7f86843b",
  "turn_id": "M6-CP3-TB-EXEC-179-P13-RETRACED-TRACE-SELECTION-FULL-GATE",
  "harness_path": ".agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh",
  "harness_sha256": "78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94",
  "environment": {
    "CANDIDATE_ARTIFACT_ID": "14893165901",
    "EXPECTED_SOURCE_SHA": "5d9468d168ee3c9eed086bd787979ced7f86843b",
    "EXPECTED_CANDIDATE_ZIP_SHA256": "0ff23208d9329a02951d1aea83c0631ac7790b92bb3bfb46639d52d33e7c225c",
    "EXPECTED_ROOT_MANIFEST_SHA256": "b2c0c0fdc8b2cf530bf05b472d7525cd2d0be234b212f7d466564618b6d3d668",
    "EXPECTED_SOURCE_ARCHIVE_SHA256": "e5e6e9d24a553e1b1d0d4b6f556ea23d9d01f2e2ff49a67d4d65e2908f00bb21",
    "CASE_MANIFEST": ".agents/Directional/gates/Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv",
    "CASE_MANIFEST_SHA256": "2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724",
    "EXPECTED_CASE_COUNT": "1003",
    "MEMBERSHIP_LEDGER": ".agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv",
    "MEMBERSHIP_LEDGER_SHA256": "fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce"
  },
  "artifact_prefix": "m6-cp3-tb179-retraced-trace-selection",
  "retention_days": 14
}
```

The [frozen gate](gates/Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv) contains 1,003 rows. Its first 1,002 rows and header are byte-identical to TB178, SHA-256 `921bd04bbfab596da6679083d5880d3f4893126e19a91c4687ba5ba63827e8ed`. The 81 deferred names do not intersect the gate. Expected runtime membership is 1,084. The manifest hash and the deferred ledger hash match the reviewed values. Actual membership discovery must occur in the separate TB turn, not in CB.

Row1003 `FieldAlignedCurveNetwork.MechanicalRetracesPublishBothPortsBeforeTopologyReaders` must pass. It must prove 12 ports, eight retained traces, bindings 0→3, 2→8, 4→11, 7→9, original trace identities, complete live references and rejection of a missing arrival binding. Preserve all 995 previously passing rows. The seven existing mechanical failures at rows 445/652/653/656/658/660/786 can remain only under the reviewed conditions. Row652 must advance past `RegionElectedCutComponentEmpty` or the prediction is false. Stop for a failed guard, a new A2a rejection, missing or ambiguous remap, missing port, stale reference, unrelated verdict change or missing evidence. Do not repair a reader in TB.

Compare all 1,002 inherited raw records and ledger rows with TB178 result `14885616510`, ZIP SHA-256 `57260ad2ee62adb02bad56bc09d2ab7e2c4782b8ad4ef43faa76cb5e539600a6`. Apply only N1 (GoogleTest elapsed time), N2 (line endings) and N3 (counted complete `M3_CP4AB_FRAGMENT_DIAG` records, with all other bytes and order preserved). Do not normalize assertion-line shifts. List every changed row and exact before/after record, including dropped `committedSlide` lines (K4) and changed passing rows. Only actual removed paths, ownership bindings and their downstream propagation can explain a difference. Stop for non-mechanical selection without reviewed evidence or any unrelated difference. Retain the complete raw evidence. `M6-CP3-TB-REV-179` must independently adjudicate every difference and scope CB-200 from the actual first failure of row652 (K5). CB-200, row979, E5 and activation remain held. No acceptance promotion.
