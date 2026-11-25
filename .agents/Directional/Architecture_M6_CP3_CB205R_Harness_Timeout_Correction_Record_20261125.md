# CB-205R — full-gate timeout correction (2026-11-25 UTC)

## Situation

`M6-CP3-CB-205R-HARNESS-TIMEOUT` corrects only the execution harness. TB185 is invalid-attempt evidence: row1006 was killed after 600 seconds, with 11 of 13 recipe receipts and no completed elapsed time or final selection receipt. No product hang or semantic failure is established. TB184 remains independently accepted (1005/1005). See [invalid execution record](Architecture_M6_CP3_TB185_P13_Slide_Entry_Activation_Reach_Orchestration_Failure_Report_20261125.md).

## Background — exact authority

| Evidence | Value |
|---|---|
| Inspection | Snapshot `2cb0b4e62bc68ccca438a780e61a956650690f1f`, [run 45562839730](https://github.com/akashskypatel/Directional/actions/runs/45562839730), job `139030501668`, artifact `14998418037`, ZIP SHA-256 `641b9098a5c6664586687c28470e7f2bf82b3a44c3b0e042111dae34b086a1aa`, source archive SHA-256 `a4adf12794d620926446c6c499bea19e48caedf1f4fc733e70e6e96306efd5ba`, 5831/5831 member checks. |
| Application | [Run 45563209845](https://github.com/akashskypatel/Directional/actions/runs/45563209845), job `139031821156`, event `b83b7a26b9674fc79d839b0366650e940a665bca`; result `14998224060` SHA-256 `aa8e7e7a086d3b3a41b5e8d90ab731a0297c27b7a8a6253822808c6b9066030c`; log `14998757845` SHA-256 `e91b3fbc9cc127650190a195493574ccbb01e774035686a6548f14feac953059`. Both archives verified; application and push exit 0; compile and test jobs skipped; Drive transport copy moved to Trash after push. |
| Patch | One path, +1/−1, 1453 bytes, SHA-256 `6d3d968fae668d32423dc78c55ee7cbaaea2642ea71491f82d3fdf1343da5a95`, diff-body SHA-256 `ac74d64eef96864e6cee9673332f35a6fe683057cba1b67b5e31ed5a8f74b302`. File-Library recovery copy retained. |
| Executor | `57a4a755944e611df4998c9f00b010cae683a5b4`; `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `688db110dc11f33331caa9a151ea348731de2a82983442bb52818b8dc8594090`, Git blob `7b04e126134cc7a570273098371d6e937563fc4b` (verified on remote executor). Old SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`. |
| Workflow | Unchanged `agent-test-benchmark-reusable.yml` SHA-256 `81249e23a162152aace51f84ae1bffc0c0770420a19e2832fd2cd58a93b1511b`; dispatcher SHA-256 `91bacf466c65611a1ed615d045092435a7cb811bc905d853a5bf9b995d5ce6fa`. |
| Candidate | Semantic source `21087c8285a5dd367cc16f610386accc061bd194`, [compile run 45554728034](https://github.com/akashskypatel/Directional/actions/runs/45554728034), package `14995401750`, ZIP SHA-256 `7e66ef7b3b16e76618a60b250a76038e65bf2e092601958f8252ac993b778da9`, root manifest `255e344116e2faa2d351b637cdfc6d11805b83352965f794b8bddaf56409f5d3`, source archive `bba6f2ce82c27a1481dad5fb16952b88476fca25411840a3e6d588ad67d2502e`. Prior GMP/GMPXX build: eight targets and 28/28 checks; no new build or package. |
| Accepted baseline | TB184 result `14992995631`, ZIP SHA-256 `8686e64c07fed5e72a5285fa6071a50944f1ea0b24c4b9e61eea831c46e0dd9c`. Invalid TB185 result `14997312958` remains provenance only. |

## Assessment

At harness line 520, replace `process.wait(timeout=600)` with `process.wait() if gate else process.wait(timeout=600)`. The existing manifest contract derives `gate` from the homogeneous case kinds and requires the membership ledger for gates. The change removes the elapsed cutoff for every gate case, not just row1006. The 600-second non-gate census timeout, process-group kill, reap, exit 124 and timeout marker remain unchanged. The separately bounded test-listing preflight remains unchanged. The reusable execution workflow imposes no additional gate elapsed cutoff. GitHub service limits still apply.

Verification (control plane only):

- `bash -n`: PASS; harness `--self-test`: PASS, 30 cases; `--self-check`: PASS, 1006 gate cases and 81 deferred cases.
- Independently extract the real wait/timeout exception block from each harness version. A process double rejects the old gate wait (timeout argument). The corrected gate wait has no timeout argument and propagates organic exit 7. Non-gate wait retains 600 seconds and propagates exit 7. A forced non-gate timeout retains SIGKILL of the process group, reap, exit 124 and `HARNESS_TIMEOUT 600s` marker.
- Exact diff applicability and whitespace checks passed. Remote compare from snapshot to executor shows only the dispatcher request and the one-line harness change. Remote harness blob matches the local postimage. No production, test, fixture, selector, membership manifest, package, or workflow permission changes. No configure, compile, relink, repackage or Directional runtime: `runtimeExecution=false`.
- No new stable event or semantic acceptance. Stable 67 events / 17 categories / 50 recurrences; witness debt1, deferred81. TB170/K6 closed; P1 supported, D-U carried. J6/E5/CB-190 and CP3/497/D0/H4 held.

## Recommendation — next turn only

`M6-CP3-TB-EXEC-185R` must execute all 1006 frozen cases afresh, with no stitched results or row-only rerun. Use the exact executor and semantic source above; use the same immutable package and inputs as TB185. Set `EXPECTED_CASE_COUNT=1006`. Use [case manifest](gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv), SHA-256 `a9b8083269ebd0786f0584d66c1f89f43362d884840ab95b95c3d0fa59ca0587`, first 1005 rows including header SHA-256 `94f02d6bd2d599f02bbc7dc7cd317e490cdb00e18827596acac2cfdd827460be`; [deferred ledger v5](gates/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v5.tsv), SHA-256 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`. Require membership 1087, exact single execution of each gate case, fail-closed controls and immutable postflight. Verify first 1005 against TB184 with the existing comparison contract; no new allowance. Require all 13 recipe keys, sphere explicit false binding and true difference/four later-entry stops, other required baseline builds, final selection receipt and resource elapsed time. Follow [exact manifest](gates/Architecture_M6_CP3_CB205_P13_Slide_Entry_Activation_Reach_Exact_Manifest.md) for receipt and reader obligations. Invalid-attempt partial evidence cannot substitute for any measurement. Route semantic RED to Review; route invalid orchestration per cadence. TB-REV-185 and conditional CB-206 follow only under their existing authority. Do not activate Branch A or start the successor in this turn.
