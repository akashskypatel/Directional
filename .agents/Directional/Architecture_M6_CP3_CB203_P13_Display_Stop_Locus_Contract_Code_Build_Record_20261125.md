# CB-203 — display stop-location contract (2026-11-25 UTC)

## Situation

`M6-CP3-CB-203-P13-DISPLAY-STOP-LOCUS-CONTRACT` satisfies the compile-only gate. The exact reviewed test-only change is committed. All eight required targets compile with GNU Multiple Precision arithmetic libraries (GMP and GMPXX). No Directional executable ran. Only `M6-CP3-TB-EXEC-183-P13-DISPLAY-STOP-LOCUS-CONTRACT-FULL-GATE` is authorized next, in a separate turn.

## Background

[Exact manifest](gates/Architecture_M6_CP3_CB203_P13_Display_Stop_Locus_Contract_Exact_Manifest.md) and [TB-REV-182 adversarial review](Architecture_M6_CP3_TB_REV_182_Adversarial_Review_20261125.md), findings R3/R4, authorize the change. Row858 now checks that the display shows each source location reported by the sphere's terminal stage. It retains the stop-location and zero-cell assertions and adds one `SphereDisplayStop` receipt. Row1005 independently checks a face location given by its rotated corner key. The genus-two and half-index-fan sub-cases and all other tests remain unchanged. No product code or Branch A activation is authorized.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed diff | SHA-256 `063f87fc61202f3a1dc45d2b46eecfbeb8c2a025b534ee7a08f6a304a5b4f3ad`, 6492 bytes, one path, +91/−16. Semantic preimage `5698f79a77e08ad1d2f5e80ab351040060c8bf31`. |
| Source snapshot | [Run 45532336007](https://github.com/akashskypatel/Directional/actions/runs/45532336007), job `138930551590`, source `a0fd5a30a517f78f000aed21825641406bc233af`; artifact `14984738165`, ZIP SHA-256 `4a7b13ba136cdb786dcbad8729f3a15c3fd5ccabc20eb1c078de3a0c52a1cca0`, 5824/5824 member checks. |
| Source application | [Run 45532621651](https://github.com/akashskypatel/Directional/actions/runs/45532621651), job `138931555687`, request `c89fbd7e8f6c18a3648e28142c0a59eb1aed4b5f`, source `58baa583770dba7c4c2f88537ba4c7c317f47573`. Transport SHA-256 `22893d34ef25a34f656a7dcd7977e5cdd2b87ea4b48a7326768c785e1f35d18a`. Result `14984774458` ZIP SHA-256 `c42eb592e4321a220ae19807fbf83b27c471575c2608dfe855681ce53214da9d`; log `14985403062` ZIP SHA-256 `f96f1783e96f5899918b4a4cad60bfe057c31ecdc9f83b38a6ab642f33d5302c`. Download/verify and apply/push exit 0. Owner-authorized Drive retirement succeeded. |
| Compile | [Run 45532819564](https://github.com/akashskypatel/Directional/actions/runs/45532819564), job `138932218169`, request `d3e445b536b7d8aae9900c2618d7965af4b69230`; source `58baa583770dba7c4c2f88537ba4c7c317f47573`. Configure, preflight and build passed; TB job skipped. |
| Package | [14984948549](https://github.com/akashskypatel/Directional/actions/runs/45532819564/artifacts/14984948549), ZIP SHA-256 `aecef095ea5ebc5dcfbf1828a1fefb6424dbc772f87ddc10b74409871ddc7465`, 28/28 internal checksums. Root SHA256SUMS SHA-256 `39b1b784ecc17058fff9015d215cda243bb069f07a9a567cc8f1f8564bf662c6`; source archive SHA-256 `9c8de4d8d7bfa287474760ad7296b497b1e094b1975df5dc599775c639d82d9f`. Expires 2026-12-02 UTC. |
| Compile log | [14984608986](https://github.com/akashskypatel/Directional/actions/runs/45532819564/artifacts/14984608986), ZIP SHA-256 `ec5947e8f50a8c1848518343388491988c639aafb857fc57c70719d729f8c59d`. Both archive digests match the workflow mailbox. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, clean source status files, preflight and build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`, generated link command contains `libgmpxx.so` and `libgmp.so`. |

The test preimage `f32540153871bd6d6c2f453f5e3784f9f392ab4fdafcb274f496f3a3ee199974` and postimage `b054f3b2fabc07553c0efcef293048ff46a18649609997665593cb6827d10a75` match the frozen manifest. The packaged source matches the postimage. The remote application changed only `tests/SurfaceCellTracingDisplayTests.cpp` (+91/−16), with matching Git blob `a21f8e5e6c6ec5da10dbc585f815078a13fcf44b`. The TB183 case manifest is the exact 1004-row TB182 prefix plus row1005. The 81-row deferred ledger and harness hashes match. No local compile, runtime, benchmark or membership discovery occurred. The package contains two libraries and six executables.

The independently accepted TB182 baseline remains 1004/1004 and CP2 remains 491/491. Stable 67 events / 17 categories / 50 recurrences, witness debt1/deferred81 unchanged. No CP3/497/D0/H4 promotion. The later sphere stop stage remains unmeasured.

### Closeout checks

- Temporary-state cleanup [run 45532832506](https://github.com/akashskypatel/Directional/actions/runs/45532832506), result `14985548473` ZIP SHA-256 `38afa201f2bd8cc7091ed7eb3ad84db4cbae06b4b344f49d96d78af221cb1b8f`, commit `8c17ea1a12b64ccc2c2a57ac5eb1408b789c17cd`. Only the CB-203 snapshot trigger and cleanup manifest were removed; the durable dispatcher and mailbox remain.
- Documentation drift audit: zero errors; existing ORIENTATION.md size warning and the authorized handoff change. Durable sections remain intact.
- Process deviations: handoff read preceded the entry beacon, some policy and manifest reads preceded the snapshot read-mode gate, premature mailbox reads returned stale records or HTTP 404, and the exact tool ledger was not retained through context compaction. A local Git safe-directory error was corrected with command-scoped configuration. These do not invalidate the verified source, application and compile evidence.

## Recommendation — separate TB-EXEC-183

Use the immutable package in the next turn. Preserve archived executable mode bits with ordinary `unzip` or `tar`. Do not repair package contents or permissions, rebuild, relink, change tests or run benchmarks. Submit this request only after the separate successor entry beacon:

```json
{
  "schema_version": 1,
  "operation": "test_benchmark",
  "request_id": "m6-cp3-tb183-exec",
  "mailbox_key": "m6-cp3-tb183-exec",
  "executor_sha": "58baa583770dba7c4c2f88537ba4c7c317f47573",
  "semantic_source_sha": "58baa583770dba7c4c2f88537ba4c7c317f47573",
  "turn_id": "M6-CP3-TB-EXEC-183-P13-DISPLAY-STOP-LOCUS-CONTRACT-FULL-GATE",
  "harness_path": ".agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh",
  "harness_sha256": "78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94",
  "environment": {
    "CANDIDATE_ARTIFACT_ID": "14984948549",
    "EXPECTED_SOURCE_SHA": "58baa583770dba7c4c2f88537ba4c7c317f47573",
    "EXPECTED_CANDIDATE_ZIP_SHA256": "aecef095ea5ebc5dcfbf1828a1fefb6424dbc772f87ddc10b74409871ddc7465",
    "EXPECTED_ROOT_MANIFEST_SHA256": "39b1b784ecc17058fff9015d215cda243bb069f07a9a567cc8f1f8564bf662c6",
    "EXPECTED_SOURCE_ARCHIVE_SHA256": "9c8de4d8d7bfa287474760ad7296b497b1e094b1975df5dc599775c639d82d9f",
    "CASE_MANIFEST": ".agents/Directional/gates/Architecture_M6_TB183_P13_Display_Stop_Locus_Contract_Full_Gate_Case_Manifest.tsv",
    "CASE_MANIFEST_SHA256": "94f02d6bd2d599f02bbc7dc7cd317e490cdb00e18827596acac2cfdd827460be",
    "EXPECTED_CASE_COUNT": "1005",
    "MEMBERSHIP_LEDGER": ".agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv",
    "MEMBERSHIP_LEDGER_SHA256": "fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce"
  },
  "artifact_prefix": "m6-cp3-tb183-display-stop-locus-contract",
  "retention_days": 14
}
```

Expected 1005/1005 PASS and membership 1086 (1005 gated + 81 deferred). Compare with accepted TB182 result `14979452472`, ZIP SHA-256 `bbbc344b8213b16c9259eb4e5edc24b8a8aadbc8390df32137e239fb113420b7`. All inherited ledger fields except raw-log hash must match. Normalize only N1 (elapsed time), N2 (line endings), and N3 (counted complete fragment-record ordering). Only row858's added `SphereDisplayStop` line and new row1005 may differ. The receipt must report the existing cut-graph stop with `sourceFace` present. Any other change, missing/duplicate/extra membership, new RED or lost negative means STOP. TB-REV-183 independently accepts or rejects the gate and may freeze CB-204 test-only pre-staging. No Branch A activation, J6/E5/CB-190 repair or CP3/497/D0/H4 promotion.
