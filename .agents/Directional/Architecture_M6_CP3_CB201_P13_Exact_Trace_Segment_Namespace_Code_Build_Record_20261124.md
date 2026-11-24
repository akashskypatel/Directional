# CB-201 — exact trace-segment namespace (2026-11-24 UTC)

## Situation

`M6-CP3-CB-201-P13-EXACT-TRACE-SEGMENT-NAMESPACE` satisfies the compile-only gate. The exact reviewed namespace-only change is committed. The eight required targets compile with GNU Multiple Precision arithmetic libraries (GMP and GMPXX). No Directional executable ran. Only `M6-CP3-TB-EXEC-181-P13-TRACE-SEGMENT-NAMESPACE-FULL-GATE` is authorized next, in a separate turn.

## Background

[Exact manifest](gates/Architecture_M6_CP3_CB201_P13_Exact_Trace_Segment_Namespace_Exact_Manifest.md) and [TB-REV-180](Architecture_M6_CP3_TB_REV_180_Cross_Partition_Arc_Census_Independent_Review_20261124.md) authorize the K6 namespace correction. Move five shared trace-segment operations/types to `exact_trace_segment_detail`: `FaceChartPoint`, `face_chart_segment_parameter`, `exact_trace_segment_end`, `canonical_boundary_barycentric`, and `exact_trace_segment_pieces`. Update consumer qualifications without changing semantics, test identities or source line counts. K6 remains open until the independent TB-REV-181 verdict.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed patch | `Architecture_M6_CP3_CB201_P13_Exact_Trace_Segment_Namespace_Exact.diff`; SHA-256 `0da2ffe20ff5f0b4913acba5fa5dfd3e18c0e23ef1f6965d9d94098696d8d91c`, 27844 bytes, seven paths, +66/−66. |
| Source snapshot | [Run 45488166187](https://github.com/akashskypatel/Directional/actions/runs/45488166187), job `138779118749`; source `6288eb3a641a51acab8e10abf57f0830e108d4e8`; artifact `14964364320` ZIP SHA-256 `7ec2cd5da878f092213001cb79b6103fe1b7b899d4994982ffc33a462311f551`; 5816/5816 member checks. |
| Source application | [Run 45488678425](https://github.com/akashskypatel/Directional/actions/runs/45488678425), job `138781175904`, base `6288eb3a641a51acab8e10abf57f0830e108d4e8`, request `09acd14d35e197c7f7076f8ce473451a4ec5cf87`, source `b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3`. Transport SHA-256 `b629d327e9049ad6a89d2e1cbf6f13a837483deb91423e6d7d1bb7288663945b`; result `14964559299` ZIP SHA-256 `e16b4bed4bedeeba3ede7a8209ce1b625bad3f3e98e98f0377c2cc8ebfa26924`; log `14965366582` ZIP SHA-256 `b80f192f44427f28881cb5fb3d30194e548f52375eb08d3e53f01316634c4f99`. Apply and push exit 0; owner-authorized Drive retirement successful. |
| Compile | [Run 45488907549](https://github.com/akashskypatel/Directional/actions/runs/45488907549), job `138781977639`, request `a057fc1b2bc3d11f147054bb4ac2d6ea584d15d7`, exact source `b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3`. Configure, preflight and build succeeded. Test/benchmark job skipped. |
| Package | [14966635283](https://github.com/akashskypatel/Directional/actions/runs/45488907549/artifacts/14966635283), ZIP SHA-256 `fbad076e0d30e099ece6e197191f7a5ec98016a8713a286a4a391ede0cdb644a`, 28/28 internal checksums. Root `SHA256SUMS` SHA-256 `0641144df8b7d0b957a800fbc9d5853b79521daa3fdc760593acfa07594fe1ef`; source archive SHA-256 `b0f867441b2ef0e00fa08764a7aa2eda41b350541e7dab5bd35bdeb3893d7248`. |
| Compile log | [14963894943](https://github.com/akashskypatel/Directional/actions/runs/45488907549/artifacts/14963894943), ZIP SHA-256 `dbe6c66668fe2dd757d2345762361097076a5f49193bc8ab7cef3d093a3914bb`. Both ZIP hashes match the mailbox and artifact API. Expires 2026-12-01 UTC. |
| Mailbox | `workflow-mailbox:.workflow-mailbox/m6-cp3-cb201-compile-20261124/runs/45488907549-attempt-1.json`, blob `ec9aad65d0a795fee082dc97bacada4c10a20ede`, result success. |
| Scope and clean state | `runtimeExecution=false`; `semanticContracts=compiled-not-executed`; five source status files empty. Preflight and build exit 0. `DIRECTIONAL_ENABLE_GMP=ON`; link uses `libgmpxx.so` and `libgmp.so`. |

The seven preimages and postimages match the exact manifest (7/7 each). The packaged source also matches all seven postimages. The reviewed diff applies without errors; `git diff --check` passes. The remote source commit changes only the seven expected paths. Source line counts and 224 textual test declaration identities in the changed test file are unchanged. No moved symbol retains a downstream qualification. No compatibility alias, selector, gate manifest, harness, or deferred ledger changed. The eight targets are `directional_core`, `directional_pipeline`, `directional_surface_cell_authority_kernel_tests`, `directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`, `directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and `directional_benchmarks`. The package contains two libraries and six executables. No local compile, project binary execution, membership discovery or benchmark occurred.

Accepted TB180 remains 1003/1003 and CP2 491/491. Stable 67 events / 17 categories / 50 recurrences; witness debt1/deferred81 unchanged. No CP3/497/D0/H4 promotion. Row979 remains unclassified.

### Closeout checks

- Temporary-state cleanup [run 45489026117](https://github.com/akashskypatel/Directional/actions/runs/45489026117), result artifact `14964654154`, ZIP SHA-256 `db6a16690bd117c5fca907702b8a36d6f684b1dab2825e285f5223767673959c`, cleanup commit `c7fb614bae17726a43ce8cf888fe40fd93cfafbc`. Only the CB-201 snapshot trigger and cleanup manifest were removed. No PR comments were deleted. Dispatcher slot retained; the mailbox remains on its dedicated branch.
- Local document drift audit before and after edits: zero errors, one existing `DOCUMENT_BLOAT` warning for ORIENTATION.md (36,761 bytes against the 24,000-byte heuristic). Not changed in this compile-only turn. Review owns orientation maintenance. Durable section headings preserved; the task index and handoff name TB-EXEC-181 as the only next turn.
- Process deviations: initial direct document reads preceded the required read-mode gate; the full mandatory start-policy/lesson read is not established before source work. The source patch request used a literal verified checksum rather than the payload writer. Compile dispatch followed independent remote source comparison but preceded download of the apply receipt; that receipt subsequently verified the exact frozen diff and successful push. Cleanup of the verified snapshot marker preceded completion of compile verification. The separate turn-based skill could not be retrieved at its attempted root path. These are process gaps, not proof of a product defect. The source snapshot, both apply receipts, and complete compile package were independently verified. The turn tool-call ledger is partial after context compaction; no exact total is claimed.

## Recommendation — separate TB-EXEC-181

Use the immutable package above. Submit this request only in the next turn after its entry STATUS write. No rebuild, repair, relink, test modification or benchmark is authorized.

```json
{
  "schema_version": 1,
  "operation": "test_benchmark",
  "request_id": "m6-cp3-tb181-exec",
  "mailbox_key": "m6-cp3-tb181-exec",
  "executor_sha": "b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3",
  "semantic_source_sha": "b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3",
  "turn_id": "M6-CP3-TB-EXEC-181-P13-TRACE-SEGMENT-NAMESPACE-FULL-GATE",
  "harness_path": ".agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh",
  "harness_sha256": "78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94",
  "environment": {
    "CANDIDATE_ARTIFACT_ID": "14966635283",
    "EXPECTED_SOURCE_SHA": "b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3",
    "EXPECTED_CANDIDATE_ZIP_SHA256": "fbad076e0d30e099ece6e197191f7a5ec98016a8713a286a4a391ede0cdb644a",
    "EXPECTED_ROOT_MANIFEST_SHA256": "0641144df8b7d0b957a800fbc9d5853b79521daa3fdc760593acfa07594fe1ef",
    "EXPECTED_SOURCE_ARCHIVE_SHA256": "b0f867441b2ef0e00fa08764a7aa2eda41b350541e7dab5bd35bdeb3893d7248",
    "CASE_MANIFEST": ".agents/Directional/gates/Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv",
    "CASE_MANIFEST_SHA256": "2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724",
    "EXPECTED_CASE_COUNT": "1003",
    "MEMBERSHIP_LEDGER": ".agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv",
    "MEMBERSHIP_LEDGER_SHA256": "fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce"
  },
  "artifact_prefix": "m6-cp3-tb181-trace-segment-namespace",
  "retention_days": 14
}
```

The unchanged TB179 manifest has 1003 rows and 81 deferred names; expected membership 1084. Runtime membership is a TB preflight obligation. Compare all 1003 raw records and ledger rows against accepted TB180 result `14951803089`, ZIP SHA-256 `67e784747b1c8d04bf781b69b486f3310876fde101b7935f0207fd2fd36a39f8`. All cases must PASS; every ledger field except raw-log hash must match. Normalize only N1 (GoogleTest elapsed time), N2 (line endings), N3 (counted complete fragment-record ordering). All normalized raw bytes must match. No source-line normalization, receipt exception, changed semantic digest, membership, diagnostic or corruption classification. Any material difference, new RED, missing/duplicate result or changed membership means STOP. Independent TB-REV-181 decides whether K6 closes and freezes CB-202 under the prior adversarial requirements. J6, row979, Branch A, CB-190 and E5 remain held. No promotion.
