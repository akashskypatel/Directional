# CB-204 — slide-entry pre-staging (2026-11-25 UTC)

## Situation

`M6-CP3-CB-204-P13-SLIDE-ENTRY-PRE-STAGING` meets the compile-only gate. The exact reviewed test-only change is committed. All eight required targets compile with GNU Multiple Precision arithmetic libraries (GMP and GMPXX). No Directional executable ran. The next turn is `M6-CP3-TB-EXEC-184`, in a separate session. Runtime acceptance is not established.

## Background

The [exact manifest](gates/Architecture_M6_CP3_CB204_P13_Slide_Entry_Pre_Staging_Exact_Manifest.md) and [TB-REV-183 adversarial review](Architecture_M6_CP3_TB_REV_183_Adversarial_Review_20261125.md) authorize the change. Row978 explicitly passes `false` for the unstaged diagnostic call. Row979 requires a successful explicit unstaged network and exact production-digest equality before using that network for the existing negative cut-graph control. The error must be `CutSearchExhaustedBeforeCellularity`. All staged positive checks and receipts remain. The label `productionCut` stays for byte stability, after the equality check. The production default remains `false` and the production arrival priority remains `ArcLengthFiltered`. No product code, fixture, selector, build or benchmark change is authorized or present.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed diff | SHA-256 `a89a68f882629daad1507198525f6ea4a98a13f2278301ada716fde45ee44d34`, 2544 bytes, one path, +14/−6. Semantic preimage `58baa583770dba7c4c2f88537ba4c7c317f47573`. |
| Source snapshot | [Run 45543644874](https://github.com/akashskypatel/Directional/actions/runs/45543644874), job `138967980450`, source `caad2fc16c50b6fd632f00c9615d0bf269a7e1fd`, artifact `14990098032`, ZIP SHA-256 `5b42912a68b7b38be5d7e97ae04414d3909bf9b82de49e7a4044ec635ae86072`, archive SHA-256 `a29315eed24831bdabdb35fa318174c525e7573a583ca15939715d0e59649cf0`, 5824/5824 member checks. |
| Source application | [Run 45544085641](https://github.com/akashskypatel/Directional/actions/runs/45544085641), job `138969539714`, request `043ea4be858b65caac80f3a8e55941d266b86c8a`, source `754369dfb9e98d209e79802d8b13855f42a77f26`. Transport SHA-256 `0b93062b74d8df4a2b434ce56ecd6dedc01ef63209dbf49cbfb6b1246946080d`. Result `14990906082` ZIP SHA-256 `cfdf3f934098adf4675c82569def116a57a18c91d00b940a82c0ccf55dce9d91`. Log `14991330099` ZIP SHA-256 `81fc772cdf208afd960f31bafce337e514324e8218cb90f2224edacb198ebc4f`. Download/verify and apply/push exit 0. Owner-authorized Drive retirement passed. |
| Compile | [Run 45544269420](https://github.com/akashskypatel/Directional/actions/runs/45544269420), job `138970169554`, request `78b6fd02bdd861e737372ea04f69e6c947fa8084`, source `754369dfb9e98d209e79802d8b13855f42a77f26`. Configure, preflight and build passed. Test + Benchmark job skipped. |
| Package | [14990462714](https://github.com/akashskypatel/Directional/actions/runs/45544269420/artifacts/14990462714), ZIP SHA-256 `08ce494de8fa93179e1db251a3440301959379137828f254142e03cefc4d154d`, 28/28 internal checksums. Root SHA256SUMS SHA-256 `8e2dcacb106d5cd3bf9e8f680e6b45cedd13e593f57ea0fb92a17ace9eab47f7`. Source archive SHA-256 `3aaf3e55833c38d3dbe3021ae086741b7b3fe1107da811d2542fc4ee2bae04be`. Expires 2026-12-02 UTC. |
| Compile log | [14990562495](https://github.com/akashskypatel/Directional/actions/runs/45544269420/artifacts/14990562495), ZIP SHA-256 `362706b8fa8efef597b8cdaeefd9b0f3f635e5a6144adb818e63b3b6d1332fd6`. Both ZIP digests match the mailbox. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, clean source status files, preflight and build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`, generated link command includes `libgmpxx.so` and `libgmp.so`. |

The preimage SHA-256 `9f08edd716bd07348305e4f6edc460aa09bd2d2b9e3255806611301b553cd690` and postimage SHA-256 `d4543d0844013a50dc551fac6f66468412903f9f3cad2bf3affc0ca5a8cf95c5` match the frozen manifest. The packaged source matches the postimage. The remote application changes only `tests/FieldAlignedCurveNetworkTests.cpp` (+14/−6). Its Git blob `b474a90389db7360d8a3031a0dedfc9a8bc63dca` matches the reviewed postimage. The case manifest, deferred ledger and harness bytes are unchanged. No local compile, runtime, benchmark or membership discovery occurred. The package contains two libraries and six executables. The compiler cache returned 142/143 hits (99.30%).

The accepted baseline is still TB183 1005/1005. CP2 stays 491/491. Stable accounting remains 67 events / 17 categories / 50 recurrences, witness debt1/deferred81. P1 supported and D-U retained. No CP3/497/D0/H4 promotion, activation or J6/E5/CB-190 repair. The later activated sphere stop stage/locus and other fixture reach remain unmeasured.

### Closeout checks

- Temporary-state cleanup [run 45544287257](https://github.com/akashskypatel/Directional/actions/runs/45544287257), job `138970138208`, result `14991370307` ZIP SHA-256 `c05247d5f1bc5e9ff4e798006b0dbdbff1e3e515deb4ac2c2ad7d24de5b18dc3`, commit `91d9baf5cb89d717b56343d4503cd378b91517cd`. The cleanup removes only the CB-204 source snapshot marker and cleanup manifest. The durable dispatcher and mailbox remain.
- Local documentation drift audit: zero errors. The existing ORIENTATION.md size warning and the authorized handoff modification remain. Durable sections stay intact.
- Process deviations: initial handoff/policy reads preceded full snapshot-mode selection, the exact tool ledger was not retained through context compaction, one PR-comments request used an invalid argument and was corrected, and early mailbox reads returned stale records or HTTP 404 before publication. The first local Git setup failed due to directory ownership and was corrected using a separate owned copy. A regenerated diff used three context-space characters absent from the reviewed diff. The exact reviewed diff and exact postimage, not the regenerated diff, were verified and transported. The external turn-based coding skill was read after source application, and full pre-work LESSONS coverage is not established. A local log checker initially expected a status line written after log upload; the corrected check uses the recorded exit codes and successful job receipt. The initial documentation audit used an incomplete local tree; adding the omitted snapshot paths corrected its false link errors. These issues do not invalidate the source, application or compile evidence.

## Recommendation — separate TB-EXEC-184

Use only the immutable package. Preserve archived executable mode bits with ordinary `unzip` or `tar`. Do not repair contents or permissions, rebuild, relink, change tests or run benchmarks. Submit this request only after the separate successor entry beacon:

```json
{
  "schema_version": 1,
  "operation": "test_benchmark",
  "request_id": "m6-cp3-tb184-exec",
  "mailbox_key": "m6-cp3-tb184-exec",
  "executor_sha": "754369dfb9e98d209e79802d8b13855f42a77f26",
  "semantic_source_sha": "754369dfb9e98d209e79802d8b13855f42a77f26",
  "turn_id": "M6-CP3-TB-EXEC-184",
  "harness_path": ".agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh",
  "harness_sha256": "78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94",
  "environment": {
    "CANDIDATE_ARTIFACT_ID": "14990462714",
    "EXPECTED_SOURCE_SHA": "754369dfb9e98d209e79802d8b13855f42a77f26",
    "EXPECTED_CANDIDATE_ZIP_SHA256": "08ce494de8fa93179e1db251a3440301959379137828f254142e03cefc4d154d",
    "EXPECTED_ROOT_MANIFEST_SHA256": "8e2dcacb106d5cd3bf9e8f680e6b45cedd13e593f57ea0fb92a17ace9eab47f7",
    "EXPECTED_SOURCE_ARCHIVE_SHA256": "3aaf3e55833c38d3dbe3021ae086741b7b3fe1107da811d2542fc4ee2bae04be",
    "CASE_MANIFEST": ".agents/Directional/gates/Architecture_M6_TB183_P13_Display_Stop_Locus_Contract_Full_Gate_Case_Manifest.tsv",
    "CASE_MANIFEST_SHA256": "94f02d6bd2d599f02bbc7dc7cd317e490cdb00e18827596acac2cfdd827460be",
    "EXPECTED_CASE_COUNT": "1005",
    "MEMBERSHIP_LEDGER": ".agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv",
    "MEMBERSHIP_LEDGER_SHA256": "fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce"
  },
  "artifact_prefix": "m6-cp3-tb184-slide-entry-pre-staging",
  "retention_days": 14
}
```

Expected 1005/1005 PASS and 1086 members (1005 gated + 81 deferred). Compare all ledger fields except raw-log hashes to accepted TB183 result `14986349003` ZIP SHA-256 `95b49af95c09e1bca461198c798db57e506b4daf7e09da1466c0fbd2b76a9742`. Each raw hash must match its own ledger. Normalizations N1–N3 stay frozen: elapsed time, line endings, and counted complete fragment-record ordering with the non-record remainder unchanged. Row978 must compare equal after N1–N3. Only row979 may add one complete identical 30-line trace block in the second contiguous interval before `SphereStagedCutGraph`. Block SHA-256 `efd052db82a97fb658e54797d026989d1ddd48f9f807f158f63a2a67d45cabb7` (LF, including final newline). The first interval retains three blocks; the second grows from four to five. Remove exactly one added complete copy there and require N1–N3 equality. See the [exact manifest](gates/Architecture_M6_CP3_CB204_P13_Slide_Entry_Pre_Staging_Exact_Manifest.md) for raw-line intervals, record counts and receipt invariants. No other changes are allowed. STOP on any material mismatch, missing/duplicate/extra member, new RED, loss of negative or immutable postflight failure, even if all test cases PASS.

Row978 must retain four later-entry stops, 24 traces, 56 events, eight carrier ends 4/5/6/8/15/17/19/20 and ten slide segments. Row979 must retain its negative and built cellular cut graph V18/E30/F14, Euler 2, one component, 288 candidates, zero selected/cut edges, 192/192 established owners, no conflicts or violations and a built plan. Row858 and row1005 remain unchanged.

TB-REV-184 independently accepts or rejects this gate. Only after acceptance may it freeze CB-205, a test-only activation-reach receipt (row1006), as specified in the [adversarial review](Architecture_M6_CP3_TB_REV_183_Adversarial_Review_20261125.md). That review supersedes the exact manifest's earlier activation clause: row393 is an unchanged whitelist oracle, not an eight-carrier-ends replacement. The canonical signature default flip is held for CB-206 after the separate CB-205 receipt and its TB and Review. No successor work occurred in CB-204.
