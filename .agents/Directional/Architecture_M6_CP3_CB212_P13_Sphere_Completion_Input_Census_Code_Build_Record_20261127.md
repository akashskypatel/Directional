# CB-212 — sphere completion input census (2026-11-27 UTC)

## Situation

`M6-CP3-CB-212-P13-SPHERE-COMPLETION-INPUT-CENSUS` meets the compile-only gate. The exact test receipt is committed and compiled. Runtime acceptance is not established. Only `M6-CP3-TB-EXEC-189` is authorized after the root STATUS beacon records completion.

## Background

The [exact manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md) and [TB-REV-188 adversarial review BB1–BB4](Architecture_M6_CP3_TB_REV_188_Adversarial_Review_20261127.md) govern this turn. The [CB-211R record](Architecture_M6_CP3_CB211R_P13_Sphere_Route_Plan_Witness_Code_Build_Record_20261127.md) establishes source `9412fee8bcac4cb023cde42f07e0cf62027f726c`, package `15169033799`. Comparison to that source confirms only document/control changes and the exact census receipt. After the CB-211R receipt block, the test prints two `SphereCompletionInput` lines (arrangement and simplified complex), `SphereSimplification`, `SphereCompletionAudit`, and the audited input cell and same-cell twin bridges or the unavailable receipt. No assertion is added or changed.

## Assessment

| Evidence | Exact authority |
|---|---|
| Reviewed diff | 7,718 B, SHA-256 `2483d16a2d5f563681b59267ca7d84cb302e6af84aa77da94ead52a27779545b`; `tests/SurfaceCellTracingDisplayTests.cpp` only, +122/−0. Preimage `ae573fe424753dec91ea7f691e9f38efbcb2b69cf5304acb367114acbdf7bdbd`; postimage `6149b26dc7564342261920c1b669e25dfd61cb3ba323cf844ecff07aa65f16cc`. Local `git apply --check`, exact replay and `git diff --check` passed. Full-index transport body differs from reviewed diff only in expanded blob IDs. Remote blob `bab206adfc5e7de7289b3dceaa4f2588e5cd013c`; direct commit comparison confirms one path and +122/−0. |
| Snapshot | [Run 45934178863](https://github.com/akashskypatel/Directional/actions/runs/45934178863), job `140293525501`, source `ada2ebdfb9f1c453ac0a64f6aea4015fad00c847`, artifact `15169563404`, ZIP SHA-256 `ccf2fe10265d8967800557da340f88678d6ae4c6ae0e8bb334aca5777238dcdf`, source archive SHA-256 `28762e3fb176b05162549a252d241f6ce72fd4a7f2d6ee3426b77769db7e6827`, 5874/5874 checks. |
| Apply | [Run 45934418133](https://github.com/akashskypatel/Directional/actions/runs/45934418133), job `140294373289`, request `b9ba8cce79c0703e5a474f53f373822fd21376da`, source `39253c63c308a2699669095bdb12e4ece72d502a`. Full patch SHA-256 `e56f9785c945f45539c4f4e5c7a4ddeb6d1baee6527c2568892ab20b06f3e71e`, diff body SHA-256 `dd6a7279ff2f1fa9a27bbc8f6b2472ab74288b06d4fd7a6693d07cc74d76ca07`; result `15169253032` ZIP `5766f16c7e7d8caeb1dfc6c34de2aee5f40b0712313832404c24286975bedefd`; log `15169932226` ZIP `bebb66796b57ea59d10d9554a3344a8f37d7630988518705b8daead6682b86f2`. Download verification and apply/push exit 0. Owner connector retired consumed Drive file. |
| Compile | [Run 45934565154](https://github.com/akashskypatel/Directional/actions/runs/45934565154), job `140294834100`, request `8c14c6ae5dfa883d57c8d1c6e1d85f3cb2bb0e0e`, source `39253c63c308a2699669095bdb12e4ece72d502a`. Configure, preflight and build passed. |
| Candidate | [15170182914](https://github.com/akashskypatel/Directional/actions/runs/45934565154/artifacts/15170182914), ZIP SHA-256 `51cbdd7c323aa6cc29d42afd16a2905c24420d04efa5c1ecfff853f5ed2a5ebf`, root manifest SHA-256 `b7aac97b934933f863ebc4f8f72b048f966f8850025113bb536e57539d6d8124`, source archive SHA-256 `7c4194e692c13b0f897b974f95b18f292e60aba2746c3e8b1e8dcdc6ab73476a`. 28/28 checks. Expires 2026-12-04T03:31:58Z. |
| Compile log | [15170168041](https://github.com/akashskypatel/Directional/actions/runs/45934565154/artifacts/15170168041), ZIP SHA-256 `c3d84b63524066b54cb260f786debec8293c489b0d94f1d3d4491b96fe7c3d07`. |
| Boundary | `runtimeExecution=false`, `semanticContracts=compiled-not-executed`, five source-status files empty, preflight/build exit 0, `DIRECTIONAL_ENABLE_GMP=ON`, link evidence contains `libgmpxx.so` and `libgmp.so`. Eight exact targets, two libraries and six executables; executable modes verified. |

All 1192 archived regular source files were compared with the verified snapshot. Only the exact test change and dispatcher request differ. No product, other test, fixture, selector, harness or workflow definition change. No local compilation, discovery, runtime tests or benchmarks. TB-REV-188 accepts the activated 1006/1006 gate, not production. CP2 491/491; stable 67/17/50, debt1/deferred81, membership1087. V5 remains unaccepted; BunnyRandom cost cause and fine-resolution close_sheets remain unmeasured. No CP3/497/D0/H4 promotion. The new receipts do not prove the predicted phase-front route, region count or audited node.

### Closeout checks

- [Cleanup run 45934591360](https://github.com/akashskypatel/Directional/actions/runs/45934591360), job `140294841909`, result `15169708859` ZIP `8cbc797e18bcbfa92edd825626a0a729313dbb9613f4e0d5c2b8db45cfa32e71`, log `15169499378` ZIP `d2f41fc0d1b6c5dce143148c149e866888afa7dd7db1dc5464abb11de6c78895`, cleanup commit `7fa6469a4ecce26d56e31a9bef9e82689e961ba2`. Snapshot marker and cleanup manifest removed. Ten durable workflow files and request slot preserved; zero PR comments removed.
- Document drift audit returned zero errors; existing ORIENTATION size warning. Explicit durable-heading comparison passed. No policy or normative edit.
- Process limitations: initial repository policy/handoff inspection preceded verified snapshot and initial STATUS write; the entry beacon used UNKNOWN although the reviewed successor was frozen; full mandatory pre-work policy/LESSONS review and exact tool-call ledger are not established. The external turn-based-coding-agent skill was reviewed after source application. Early mailbox/run discovery required the exact request-SHA lookup. No duplicate workflow trigger. Cleanup used the pinned immutable source boundary while compile ran. These procedural limitations do not establish runtime or product acceptance.

## Recommendation — TB-EXEC-189 only, after CB-212 STATUS COMPLETE

Use the [frozen manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md) and the unchanged TB188 executor `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`. The exact harness is `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Verify the source/package/ZIP/root manifest/source archive identities above, then use the durable `test_benchmark` dispatcher with the following inputs (no diagnostic mode, no V5):

| Environment | Value |
|---|---|
| `CANDIDATE_ARTIFACT_ID` | `15170182914` |
| `EXPECTED_SOURCE_SHA` | `39253c63c308a2699669095bdb12e4ece72d502a` |
| `EXPECTED_CANDIDATE_ZIP_SHA256` | `51cbdd7c323aa6cc29d42afd16a2905c24420d04efa5c1ecfff853f5ed2a5ebf` |
| `EXPECTED_ROOT_MANIFEST_SHA256` | `b7aac97b934933f863ebc4f8f72b048f966f8850025113bb536e57539d6d8124` |
| `EXPECTED_SOURCE_ARCHIVE_SHA256` | `7c4194e692c13b0f897b974f95b18f292e60aba2746c3e8b1e8dcdc6ab73476a` |
| `CASE_MANIFEST` | `.agents/Directional/gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv` |
| `CASE_MANIFEST_SHA256` | `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587` |
| `EXPECTED_CASE_COUNT` | `1006` |
| `MEMBERSHIP_LEDGER` | `.agents/Directional/gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv` |
| `MEMBERSHIP_LEDGER_SHA256` | `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` |

Execute the 1006 cases once via the immutable harness; verify 1087-member accounting, 81 deferred, 491 CP2 PASS and no mutation/rebuild. Compare all ordered ledgers and complete raw logs to TB188 result `15163822727` under frozen N1–N3. Row858 must PASS; preserve the exact bytes through the LF after `SphereCompletionFailure detail=BoundaryParityRepair:InvalidReplacementBoundary:repeated-boundary-node;AlternativeRepairBudgetExhausted;attempted=106;budget=106`; record only the frozen additional receipt lines in order, then remove those lines for comparison. Other rows must be N1–N3-equal. Predictions in the exact manifest are unmeasured: NotApplicable phase front, 14 regions, repeated original boundary node and audited disk/twins. `Produced` is STOP; `Rejected:<reason>` falsifies the BB1 inference, not by itself a test RED. STOP on any RED, missing receipt, unexpected material difference, crash or invalid boundary. Preserve result and log artifacts, full receipts and first failure; no rerun or timeout substitution. TB-REV-189 independently adjudicates. No B1 repair, fallback repair, CB-207D, parity/activation change, V5, parameter deletion or promotion.
