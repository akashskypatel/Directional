# CB-205T — debugger provisioning (2026-11-25 UTC)

## Situation

TB185S was invalid before inferior launch: GDB (GNU Debugger) was unavailable on the hosted runner. The cause of row1006 non-completion is still unknown. [Invalid attempt](Architecture_M6_CP3_TB185S_Reach_Termination_Diagnostic_Execution_Report_20261125.md). TB184 remains independently accepted, 1005/1005.

## Background

- Snapshot `e2829fc4ca325776bc7706dd0c3c916fde45f679`, run `45634669586`, artifact `15030799091`, ZIP SHA-256 `5da75a889d168e56e03c7135ea32663b89cac19ffd4dcba647dd7147f9d0a80d`, source archive SHA-256 `9b757ce0e5a97ce42f0ade44a6a841f10fcbd12f451c7c0829030d03383a094d`; 5835/5835 file checks. Exact package authority remains `14995401750`/`21087c8285a5dd367cc16f610386accc061bd194`; see [preparation](Architecture_M6_CP3_CB205S_Reach_Termination_Diagnostic_Preparation_Record_20261125.md).
- Only `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` changed. Patch SHA-256 `ee94f592a73cb7cb58f750190bf9a2fc32e352a9a5444a5190726d7b2ac5b798`, base `e2829fc4ca325776bc7706dd0c3c916fde45f679`. Apply run `45635605830`, applied executor `90319deb1dc277a2b0ab8bba70c8aa2cf3f2f6a1`; evidence result `15032588097` SHA-256 `de4952ccf1c517b2970da1f989b6f39fa0084f68349ba2ad1ef5191b42ce311b`, log `15032682892` SHA-256 `770de0c3bd92bc2301dbf136f72307f6f16620a297edfbabc55a598bc687c515`; both ZIPs verified. Library recovery patch retained; staging deleted through the owner connector.
- Provisioning runs only in diagnostic or preflight mode. If GDB is absent, install the Ubuntu `gdb` package with noninteractive apt-get and bounded command times. Record actual version, executable and package version. No workflow permission changes or product/test/fixture changes. Package versions are not pinned to a repository snapshot; repeat the control on every diagnostic runner. Initial policy/handoff reads preceded the snapshot-mode selection and the mailbox was polled too frequently. Source inspection and editing used the verified snapshot; these process misses do not change product authority.

## Assessment — hosted control

[Run 45636089835](https://github.com/akashskypatel/Directional/actions/runs/45636089835), job `139282056378`, exact executor `90319deb1dc277a2b0ab8bba70c8aa2cf3f2f6a1`, request `febdc1f32e0afcf01e2b9064f0dc7bc7977f3b4a`, request SHA-256 `ca166501a2a4448b1157764572d3c0465dc78ea1316669dfa0b4e7f0e510f22d`. The reusable wrapper's generic runtime flag describes its job type; control-only receipt explicitly records `runtimeExecution=false` for Directional. The control uses `/usr/bin/sleep 8`, the same machine-interface (MI) observer, a 60-second maximum and 2-second sampling. No candidate download, Directional process, rebuild, reconfiguration, link, benchmark, or acceptance credit.

| Evidence | Result |
|---|---|
| GDB path/version | `/usr/bin/gdb` / `GNU gdb (Ubuntu 15.1-1ubuntu1~24.04.1) 15.1` |
| Ubuntu package version | `15.1-1ubuntu1~24.04.1` |
| Linux PID file descriptor (pidfd) | Verified by signal 0 against the exact control child |
| Interrupt / stack / continue | 3/3 recorded samples completed |
| Control completion | Organic exit 0 in 8.273 s; control preflight exit 0 |
| Local checks | `bash -n`, self-test 30/30, self-check 1006 + 81, mutually exclusive modes rejected (90), patch application and whitespace checks PASS |
| Result checksums | 7/7 PASS |

Artifacts (ZIP SHA-256):
- `15032459275` result: `be922745e4a10bd73142326a5c441f640a8b5bce1979bf8b840da53f61356b53`
- `15032374634` harness log: `970d5c241e585092bd950d3a7abdfe098e7ec88387da73cdffa0aca7078c4aec`
- `15032239605` wrapper log: `3a5699d8b80bc3bf9b8114d2d333b9b324a49acede1fde6b2714492db3fd44f5`

Stable 67 events / 17 categories / 50 recurrences; witness debt1/deferred81. CP2 491/491 accepted. P1 supported, D-U carried, TB170/K6 closed. No activation, J6/E5/CB-190 repair or CP3/497/D0/H4 promotion. The control establishes debugger availability and protocol, not the product's termination or semantic verdict.

## Recommendation — next turn only

Authorize `M6-CP3-TB-EXEC-185T-REACH-TERMINATION-DIAGNOSTIC`. Do not start it in CB-205T. Freeze the following replacement executor authority; all immutable package inputs, selection, evidence and diagnostic stop conditions in [CB-205S preparation](Architecture_M6_CP3_CB205S_Reach_Termination_Diagnostic_Preparation_Record_20261125.md) remain binding.

| Field | Value |
|---|---|
| Executor SHA | `90319deb1dc277a2b0ab8bba70c8aa2cf3f2f6a1` |
| Harness path | `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` |
| Harness SHA-256 | `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c` |
| Request ID / mailbox key / artifact prefix | `m6-cp3-tb185t-reach-termination` |
| Mode | `REACH_TERMINATION_DIAGNOSTIC=1` only; preflight-only mode must be absent |
| Candidate artifact / source | `14995401750` / `21087c8285a5dd367cc16f610386accc061bd194` |
| Frozen gate / deferred counts | 1006 / 81 |
| Diagnostic | One row1006 `TraceTerminationCorrection.SlideEntryActivationReachByReaderRecipe`, 600 seconds, 30-second samples, no gate credit |

Provision and verify the real debugger on the new runner before candidate download; retain the control receipt separately from product observations. On failure stop without Directional execution. Reuse exact hashes from [CB-205S preparation](Architecture_M6_CP3_CB205S_Reach_Termination_Diagnostic_Preparation_Record_20261125.md). Keep immutable postflight and classify the actual observation without inferring a root cause from the previous invalid attempts. Then valid diagnostic → justified correction under applicable Review authority → uninterrupted full immutable 1006-case gate → TB-REV-185 → conditional CB-206. No blind retry or successor execution in this turn.

## Closeout evidence

- [Documentation application 45636721251](https://github.com/akashskypatel/Directional/actions/runs/45636721251), commit `7036353581032ec42888151e7a3b148fb436f5f0`; result `15034565372` SHA-256 `17c9912e158a9a380dda3d19436cdefe9911008e9c7d338840fbe0526027ad56`, log `15033067318` SHA-256 `a22a549d6ceb25607d9bb72706bbaba68453c1a92512eee5162a686ab21de4e3`. Both ZIPs verified. Seven intended documentation paths; owner connector deleted the staged patch; Library backup retained.
- [Cleanup 45637115474](https://github.com/akashskypatel/Directional/actions/runs/45637115474), commit `2ee262fb943f5bbc9cebb115241a3653dcb8c3f9`; result `15034485680` SHA-256 `04b68c81f57c9540d4c9e391fc6da40b8ae6cb086aed74ef57e03f6f3d9ade92`, log `15033257181` SHA-256 `d50fbd9b5b5069b4256db8b9e8a6126be7403a7d3f7b968ff8c6ffb73da4bdcf`. Both ZIPs verified; snapshot marker and cleanup manifest removed. Durable workflow set and dispatcher retained; mailbox records isolated. Zero PR comments removed. PR #8 remains draft/open, unmerged.
- Documentation audit: zero errors, two pre-existing navigation-size warnings. The first disposable audit view omitted non-document link targets; added the exact snapshot targets and reran the audit. All protected headings retained. Remote handoff and TODO agree with the one successor. No successor request dispatched. Tool-call ledger partial/unknown after context compaction; no invented counts.
