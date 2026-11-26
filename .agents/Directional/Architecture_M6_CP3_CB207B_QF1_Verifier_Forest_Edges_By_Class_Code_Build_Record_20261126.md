# CB-207B — verifier forest edges by class (2026-11-26 UTC)

## Situation

`M6-CP3-CB-207B-QF1-VERIFIER-FOREST-EDGES-BY-CLASS`: exact reviewed QF1 product change compiled. No runtime execution, activation or checkpoint promotion.

## Background — exact authority

| Evidence | Exact authority |
|---|---|
| Reviewed difference | 1,959 bytes, SHA-256 `523357c9b32633ebe21f9a0c6744b562c7ddf723f745df9a519b16956e53a279`; `src/pipeline/RemeshPipeline.cpp` only, +17/−9. Preimage `e52e8dc4ff81fc0ab2fa01c2e6c50020563c6da95d27ed9b98cf42d7839c38d4`; postimage `5da1fcc98dcb08b21279a3ba59ccd81861bc1f2fc3f2d2bf2ba3acd2c979dd03`. |
| Verified snapshot | [Run 45720954323](https://github.com/akashskypatel/Directional/actions/runs/45720954323), job `139578922885`, source `18af5c7cf6a7eb0d6dd2bbce3ab48135c220d475`, artifact `15071658186`, ZIP SHA-256 `99dab30d992d276ee85d38f0ce4350856a13da48d01d28ed65d784a15b0450d3`, archive SHA-256 `ae1f03cbe5257c831c33d26d86db960f89ac595d8de631a20e2dab56f637d355`, 5845/5845 checks. |
| Source application | [Run 45755525104](https://github.com/akashskypatel/Directional/actions/runs/45755525104), job `139693278249`, request `b67e28d3cceaf708c653959f2ea0797b1c0eeb43`, source `9d69f8e568cad9253f8e0ac0efd1d61bc073840b`. Patch SHA-256 `a7a2fd1601805a144456bb3334784fc8feff92e909d612e249bf4fe6aa813ef6`, diff body `780f791149d22710b8bbf3dfb2096aeb3fc19d5b1d42e39bb3b978ad7734d9dd`. Result `15087288558` ZIP SHA-256 `7cf2b72f511d8ec4322d5e0c368c48b6d83e7afe69fdd28242fcac286ea61bb3`, log `15087597303` ZIP SHA-256 `e6191aaa9653ec5424abaa906e8231e4d409b79d1f5132a97dee13a4896b7bd5`. Apply/push exit 0; staged Drive file deleted by owner-authorized connector after verification. |
| Compile | [Run 45755716781](https://github.com/akashskypatel/Directional/actions/runs/45755716781), job `139693831585`, request `aaa1dd4ec672d14e4ceca0a2749465df8a653894`, source `9d69f8e568cad9253f8e0ac0efd1d61bc073840b`. Configure, preflight, compile passed; runtime skipped. |
| Candidate package | [15087219160](https://github.com/akashskypatel/Directional/actions/runs/45755716781/artifacts/15087219160), ZIP SHA-256 `66bff31c42987d4312fb8789a7148c15f448df3c470035463361e48718eb4bde`, 28/28 checks, root manifest SHA-256 `4e57738d7d3337841bc6616f082df649def3da5bdeb186b09d6a3de3e84a3d1d`, source archive SHA-256 `dcea7b9f5b61ee9d12dd73dd3d6bbdec0a3e454e3e6e6049f771cdb8f3ccfdfc`; expires 2026-12-03T04:33:15Z. |
| Compile log | [15087951186](https://github.com/akashskypatel/Directional/actions/runs/45755716781/artifacts/15087951186), ZIP SHA-256 `bb644263de277af20edde0b03fb8117173426a929a1041e4a0087be8476d978a`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, empty source status, preflight and build exit 0, GMP and GMPXX link evidence; two libraries and six executables. |

## Assessment

The verifier groups forest edges once by the common endpoint class. It preserves each class's edge order, cardinality and spanning checks, and the original membership predicate. The only product change is the exact frozen difference. `git apply --check` and `git diff --check` passed. Archived source postimage and all 1163 archived regular files verified against the snapshot and applied product change; expected control changes: `.agents/Directional/agent-dispatch-request.json`, `STATUS`. No local compilation, test discovery, Directional runtime, tests or benchmarks.

TB185V remains independently accepted 1006/1006 preactivation. CP2 491/491 remains accepted. Stable 67 events / 17 categories / 50 recurrences; witness debt1/deferred81. P1 supported, D-U carried; QF1 remains non-stable. No activation, CP3/497/D0/H4 promotion or J6/E5/CB-190 repair. Performance and termination are unproved.

### Closeout checks

- [Cleanup run 45755750687](https://github.com/akashskypatel/Directional/actions/runs/45755750687), job `139693914139`, result `15087597644` ZIP SHA-256 `20ba4fddabc9dbe8ca896b147d8edc46a39d62ad425e04ca5d906cb87cde90be`, log `15087318719` ZIP SHA-256 `d1b94e49ae93c891bd067fb1f509d402eec9714575d3d686db800d4639700af0`, cleanup commit `59a5de05588ed261e14f2aa5721a7bafb7583ad8`. Only snapshot marker and cleanup manifest removed; ten durable workflows and dispatcher preserved; no PR comments deleted.
- Process limitations: initial repository reads preceded full snapshot-mode selection; complete mandatory pre-work policy/LESSONS review is not established. Exact full-turn tool ledger not retained through compaction. No successor work performed.
- Documentation drift audit: zero errors; existing ORIENTATION size warning.

## Recommendation — executable plan for the separate TB-EXEC-187Q turn

Only after CB-207B completion, use the dispatcher request below with the frozen package. Do not execute it in CB-207B. Resolve the exact current authority and check package expiry before dispatch; do not substitute a rebuild or another candidate. N1 = GoogleTest elapsed-time normalization, N2 = CRLF to LF, N3 = counted complete region diagnostic records with ordered residual bytes preserved. Use the existing independent comparison rules from [TB185V report](Architecture_M6_CP3_TB185V_Reach_Receipt_Reader_Selection_Scope_Full_Gate_Execution_Report_20261125.md) and [review](Architecture_M6_CP3_TB_REV_185_Slide_Entry_Activation_Reach_Independent_Review_20261125.md). Baseline result `15066180913`, ZIP SHA-256 `16983f7e40ac9f5934b3a50ffd556925d582e857e41aaf34aae8f5fb3b181082` (2020/2020 checks). Do not change selectors, fixtures, tests, diagnostic modes or production activation.

```json
{
  "schema_version": 1,
  "operation": "test_benchmark",
  "request_id": "m6-cp3-tb187q-exec",
  "mailbox_key": "m6-cp3-tb187q-exec",
  "executor_sha": "9d69f8e568cad9253f8e0ac0efd1d61bc073840b",
  "semantic_source_sha": "9d69f8e568cad9253f8e0ac0efd1d61bc073840b",
  "turn_id": "M6-CP3-TB-EXEC-187Q",
  "harness_path": ".agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh",
  "harness_sha256": "423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c",
  "environment": {
    "CANDIDATE_ARTIFACT_ID": "15087219160",
    "EXPECTED_SOURCE_SHA": "9d69f8e568cad9253f8e0ac0efd1d61bc073840b",
    "EXPECTED_CANDIDATE_ZIP_SHA256": "66bff31c42987d4312fb8789a7148c15f448df3c470035463361e48718eb4bde",
    "EXPECTED_ROOT_MANIFEST_SHA256": "4e57738d7d3337841bc6616f082df649def3da5bdeb186b09d6a3de3e84a3d1d",
    "EXPECTED_SOURCE_ARCHIVE_SHA256": "dcea7b9f5b61ee9d12dd73dd3d6bbdec0a3e454e3e6e6049f771cdb8f3ccfdfc",
    "CASE_MANIFEST": ".agents/Directional/gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv",
    "CASE_MANIFEST_SHA256": "a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587",
    "EXPECTED_CASE_COUNT": "1006",
    "MEMBERSHIP_LEDGER": ".agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv",
    "MEMBERSHIP_LEDGER_SHA256": "fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce"
  },
  "artifact_prefix": "m6-cp3-tb187q",
  "retention_days": 14
}
```

1. Verify request schema and exact package/hash/mode/manifest authority. Dispatch once with the durable request slot; observe the exact orphan mailbox key. No configuration, build, relink or repair during execution.
2. Verify result ZIP and all internal hashes, source and binary postflight, exact 1006 ordered ledger rows, exact membership 1087 (81 deferred), one organic selected PASS per row, exit 0, no missing/duplicate/skipped/abnormal/RED. Include controls 8–12, 17, 25–27, 35–36 and CP2 prefix. Preserve logs and per-row resource records.
3. Compare every row's semantic ledger and raw transcript to TB185V using N1–N3 only. Record exact/N1/N2/N3 counts, ordered residuals and any material difference; record row1006 elapsed against 52.17 s baseline, without prescribing a speed threshold. STOP on any material difference or invalid/incomplete gate. No new stable count without adjudicated evidence. No timing-only claim of termination or activation sufficiency.
4. Publish result/report and next `M6-CP3-TB-REV-187Q` for independent acceptance. CB-206 stays held until then. No successor execution here.
