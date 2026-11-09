# TB93 Mandatory-chain partition — immutable full-gate execution report (2026-11-09)

**Turn:** `M6-CP3-TB93-P13-A3-MANDATORY-CHAIN-PARTITION-FULL-GATE-EXEC` (64B.2). **Disposition: COMPLETE / MATCH** under [RA-218 §6](Architecture_M6_CP3_DEFN_P13_A3_Mandatory_Chain_Scheduling_Takeover_Review_20261109.md). This Test + Benchmark turn executed the immutable CB110 artifact; no product, test, fixture, selector, benchmark or build source was changed, and the gate performed no compile/relink/configure/benchmark action.

## Immutable authority and transport

- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/unmerged. CB110 semantic source `3f81e804ac8dc44e16557339be7881a2d653fc61`; build [42681720745](https://github.com/akashskypatel/Directional/actions/runs/42681720745), immutable package artifact **13703311532**, ZIP SHA-256 `a9c3224463d5fd16a7ec07c30eac34b140b200d2bc1bb7279f2dc6b59e79da9d`, packaged checks 28/28.
- Gate manifest `.agents/Directional/gates/Architecture_M6_TB93_P13_A3_Mandatory_Chain_Partition_Full_Gate_Case_Manifest.tsv`: 923 rows, SHA-256 `a8c4a59920ee22c8f3260de2d5b467f9ce3aa4a72526d1dcd593a3b063e9095a`; rows 1–918 exactly preserve the TB92 manifest. Deferred ledger v5 SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce` (81 deferred). Harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. Preflight: `SELF_CHECK_PASS cases=923 deferred=81`.
- Gate dispatcher event SHA `141b7e3c0700035d336deae2ad96ba1b49f52694`, [run 42685084515](https://github.com/akashskypatel/Directional/actions/runs/42685084515), result artifact **13705261534**, ZIP SHA-256 `06a48a9886c5687a5b724aee968c1702c8ac784f8c2174e2da48d63354758ca3`.
- Census dispatcher event SHA `7a545a03ab99683fe4af0b736f6c5bb1353387a5`, [run 42685239925](https://github.com/akashskypatel/Directional/actions/runs/42685239925), result artifact **13704922860**, ZIP SHA-256 `173b21751266528bb8214153cdc12967bc7d6b04be625949543482e93d3ca1c5`.
- Each run's `workflow-mailbox` key (`m6-cp3-tb93-gate` and `m6-cp3-tb93-census`) matched its exact event and CB110 semantic-source SHA; the runtime jobs succeeded and their compile/drive-apply jobs were skipped. The two ZIP digests matched the mailbox and GitHub inventory. Internal SHA256SUMS verification: **1,854/1,854 gate**, **9/9 census**, with zero mismatches.

## Independent outcome comparison

| Check | Result |
|---|---|
| Gate | **923 planned / 923 executed / 923 PASS**; 0 RED, skipped, abnormal, missing, duplicate, unexpected-pass, or control errors |
| Gate membership | **1004**; postflight true |
| TB92 inheritance | First 918 gate rows match TB92 on identity, test, binary, verdict, exit, run/passed/skipped, first-failure and typed-reason fields; raw log hashes are intentionally not a verdict identity |
| Seven platform-digest raw lines | **7/7 byte-identical** to TB92: Plane, MultiFaceSeam, CloseSheets, Cylinder (gate and census), BunnyRandom, Vase |
| Seven A3-coverage raw lines | **7/7 byte-identical** to TB92 for the same seven observations |
| Census | **1 PASS / 2 registered RED**: Cylinder PASS; BunnyRandom RED; Vase RED; no new or unexpected result |
| Runtime boundary | `compile=false`, `relink=false`, `configure=false`, `benchmark=false`, `exit=0` in both execution-boundary receipts |
| Non-vacuity | New GUARD 919–923 all executed and PASS; joins, stop handling, closed rails, malformed graphs and real A2b support are exercised; see RA-218 §5 for registered mutation sensitivity |

The TB92 comparison is performed on the **literal raw `platform-digest` and `a3-coverage` lines**, not normalized numeric fields; all 14 observed raw lines match. The census REDs are non-gating, previously registered failures; they do not establish a newly successful BunnyRandom or Vase pipeline.

## Five D5 chain receipts

```text
D5_CHAIN_RECEIPT case=joins stop=0F,1R,2F|3F|4F|5F open=0F,1R,2F,3F|4F|5F permuted=same split=0F|1F|2F
D5_CHAIN_RECEIPT case=cycles uncut=0F|1F|2F stop0=0F,1F,2F stop1=0R,2R,1R pair=0F,1F self=0F
D5_CHAIN_RECEIPT case=rejections rejected=9 empty=accepted
D5_CHAIN_RECEIPT case=support chainCount=1 arcCounts=1,1,1 rejected=4
D5_CHAIN_RECEIPT case=square arcs=4 ownRails=4 oneRail=4 oneRailStop=1
```

All five are taken from independent gate log rows 919–923, respectively, and the corresponding test verdicts are PASS. These receipts are diagnostic evidence alongside the tests, not substitutes for assertions.

## Classification, scope and successor

**MATCH — no accepted-green loss.** Stable events/categories/recurrences **66/17/49**, accepted CP2 **491/491**, regression debt **1**, deferred ledger **81**; selector497/CP3 remain **unpromoted**. The current implementation is still an *unwired* partition, not evidence of a production Vase join, A3 span switch or D0 product acceptance. The outstanding Vase D5 cause, BunnyRandom P13-e, O34 uncut closed rails, later D4/D9c/A2b/A4/D8 obligations and D6 user decision remain carried.

Under RA-218 §3/§6 the sole authorized successor is **`M6-CP3-DEFN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH` (64B.3, Review agent)**. It must freeze separate CB111 stop-set, CB112 curved-disk multi-piece consumer and CB113 span-switch patches, each with its own TB, or route to `M6-CP3-PLAN-P13-A3-MANDATORY-CHAIN-SPAN-SWITCH-STOP`. **No CB111–CB113 implementation was performed in TB93.**

**Operational process disclosure:** the initial TB93 session read multiple GitHub source documents before selecting the mandatory snapshot mode; it corrected this by downloading and verifying the exact source snapshot. It also inserted dispatcher digests directly rather than using the prescribed `write_orchestration_payload.py`, although workflow-side schema and SHA verification succeeded. These process deviations are preserved, not concealed, and do not change the immutable test results.
