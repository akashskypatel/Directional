# Future Chat Session Handoff

> **EXPLICIT USER AUTHORIZATION REQUIRED** to modify or delete this file; unauthorized changes must be reverted during documentation drift audit. This rewrite was expressly requested on 2026-10-16.</br>
> Edits to this document must follow the format laid out in `.agents/Directional/Future_Chat_Session_Handoff_Template.md`.

## Purpose — DURABLE, DO NOT DELETE

This file contains durable operating policy, the exact next action, current immutable authority, standing product state, and resume-critical information required to continue safely. Architecture belongs in `DESIGN.md`; tasks in `TODO.md`; completed history in `CHANGELOG.md`; lessons in `LESSONS.md`; roadmap in `ROADMAP.md`; exact runtime evidence in retained reports/closure records and the regression tracker. Do not add transcripts, chronological tool history, tool/policy/procedural failures, copied old artifact tables, obsolete selections, or procedure owned by policy/skill files. Concision never authorizes deleting durable information.

This section is durable and must be preserved. The displaced chronological handoff remains in Git history, **not** as instructions to replay.

All instructions and sections prefixed `[ChatGPT Web]` are mandatory for `ChatGPT Web` sessions. Non-`ChatGPT Web` agents (`ChatGPT Work`, `Codex`, `Claude`, etc.) can ignore instructions/sections bearing that prefix.

## Policies - Read first at start of every turn - DURABLE, DO NOT DELETE

Policies cannot be deleted or modified without explicit user authorization. The list uses verified existing paths (three old template filenames were outdated).

| Policy | File |
|---|---|
| Turn Cadence | `.agents/Directional/Turn_Cadence.md` |
| Agent Policy | `.agents/Directional/AGENT_POLICY.md` |
| Mandatory Start Checklist | `.agents/Directional/Mandatory_Start_Checklist.md` |
| Clean up Policy | `.agents/Directional/CLEAN_UP_POLICY.md` |
| Handoff Policy | `.agents/Directional/Durable_Handoff_Policy.md` |
| GitHub Workflow Policy | `.agents/Directional/GitHub_Workflow_Policy.md` |
| GMP Compile Policy | `.agents/Directional/GMP_COMPILE_POLICY.md` |
| Retention Policy | `.agents/Directional/RETENTION_POLICY.md` |
| Review Turn Policy | `.agents/Directional/REVIEW_TURN_POLICY.md` |
| Tool Use Conservation Policy | `.agents/Directional/TOOL_USE_CONSERVATION_POLICY.md` |
| Patch Application Strategy | `.agents/Directional/Patch_Application_Strategy.md` |
| Mandatory End Checklist | `.agents/Directional/Mandatory_End_Checklist.md` |

## Current immutable authority — replace in place

| Field | Exact value / evidence owner |
|---|---|
| Currency | 2026-11-04 · [RA-203](Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md) closes the TB78 Review. The review-boundary block is RA-202.9's route, not the policy: Review scratch probes are a duty (RA-166.6 F6, RA-188.1), and Linux runtime is a TB. TB78 matches everywhere except the count line. Vase completes in 268.93 s with 67,784 quads on Linux against 67,829 on macOS. RA-202.9 pinned a macOS-only value, and the split is **O30**. CB89 compiled without runtime; next TB79 immutable test/benchmark. |
| Working branch / compiled source | `agent/surface_cell_quad/p5-recover-bridge-healing` · **CB89 source `9c9616695ecdc8c6ec219eb7486cbe85f3915c95`, artifact `13370954424`**, [record](Architecture_M6_CP3_CB89_P13_Census_Platform_Digest_Code_Build_Record_20261104.md), [compile run 41932156223](https://github.com/akashskypatel/Directional/actions/runs/41932156223), eight Linux GMP/GMPXX targets PASS, 28/28 checksums, `runtimeExecution=false`. TB79 not yet run. |
| Last accepted semantic runtime | **CP2 491/491**, accepted 2026-10-06; unchanged. TB71 remains unpromoted candidate only. |
| Latest candidate | **TB78** CB88 immutable gate **899/899 PASS**, membership 980, 81 deferred, 1,806/1,806 checksums; census Cylinder PASS, BunnyRandom P13-e, Vase typed RED in 268.93 s. The quad count (67,784 against macOS 67,829) is O30, a platform split, not a CB85–CB88 defect (RA-203.3). Unpromoted. [TB78 report](Architecture_M6_CP3_TB78_P13_Census_Path_Cost_Full_Gate_Execution_Report_20261104.md). |
| Regression accounting and debt | Accepted CP2 **491/491**; stable **66/17/49**, debt **1**; ledger v5 81 deferred (47 FIXTURE, 7 PRODUCT, 22 OPEN, 5 RETIRE), current membership **977**; selector497 and CP3 unpromoted. DR1/DR3 open, DR2/DR4 to M8-CP2. |
| Active boundary | CB89 Code + Build COMPLETE (verified source, test-only patch, eight-target compile only). Next: `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-EXEC`, separate immutable-artifact execution turn. No acceptance or selector promotion, and no new stable event. Carried: O30, P13-l, P13-e and O27–O29. |

## Mandatory next turn — `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-EXEC` (Test + Benchmark, no rebuild)

- **Authority:** [RA-203](Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md) §6; [CB89 compile report](Architecture_M6_CP3_CB89_P13_Census_Platform_Digest_Code_Build_Record_20261104.md).
- **Immutable package:** `13370954424` built from source `9c9616695ecdc8c6ec219eb7486cbe85f3915c95`, compile [41932156223](https://github.com/akashskypatel/Directional/actions/runs/41932156223), ZIP SHA256 `abe4814d0c480d68b5026004761c347e1fdb7c284f364eab0e31a3d402599551`, 28/28 hashes, `runtimeExecution=false`.
- **Execute artifact-only:** reuse exactly the TB78 manifest (899 cases; digest `9d2c1ec5…`) and ledger v5 (81 deferred), membership 980. Four gated rows 795–797 and 864 and three census processes must print exactly one `platform-digest` line each, preserved verbatim in evidence. Do not configure, compile, relink, repair packages or modify test source.
- **Registered census:** Cylinder PASS; BunnyRandom P13-e RED sourceVertex49; Vase `SelfIntersectingFace` RED within 600 seconds, Linux completed quads 67,784 and counts 192,482 / 26,817 / 67,784. Require full 899/899 test gate. Digest lines are observation, not match criteria.
- **Dispositions:** match → the authorized O30 Review/Definition `M6-CP3-DEFN-P13-PLATFORM-SPLIT` after proper TB79 closeout/review boundary; mismatch → `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-REV` (Review, Claude, scratch build); orchestration → `M6-CP3-TB79A-P13-PLATFORM-DIGEST-ORCH`.
- **Preserve:** CP2 491/491, stable 66/17/49, debt 1, selector497/CP3 unpromoted. CB89 did not execute any tests, and O30 is open.

### Earlier: TB78 and its Review

- [TB78 report](Architecture_M6_CP3_TB78_P13_Census_Path_Cost_Full_Gate_Execution_Report_20261104.md):
  - CB88 package `13358062295`;
  - [gate 41906228679](https://github.com/akashskypatel/Directional/actions/runs/41906228679) **899/899**, membership 980, 1,806/1,806 hashes;
  - [census 41906541304](https://github.com/akashskypatel/Directional/actions/runs/41906541304): Cylinder PASS; BunnyRandom P13-e; Vase RED `SelfIntersectingFace` in 268.93 s, peak RSS 2,080,256 KiB, 192,482 / 26,817 / **67,784**.
- The ChatGPT Review ([WIP](Architecture_M6_CP3_TB78_REV_P13_Census_Count_Review_WIP_20261104.md)) rehashed the evidence and narrowed the count statically. It then blocked: the RA-202.9 route asked a Review for runtime without naming the track.
- RA-203 resolves the block, owns RA-202.9's macOS-only count, and opens O30.

### Earlier: TB76 and its Reviews

- [TB76 report](Architecture_M6_CP3_TB76_P13_Optimizer_Source_Query_Full_Gate_Execution_Report_20261104.md):
  - CB83 source `2278b8b649b4262fb70a522371ed282655383af5`, package `13289188434`;
  - gate **893/893**, membership 974, 1794/1794 hashes;
  - census: Cylinder PASS, BunnyRandom P13-e RED, **Vase ABNORMAL 600 s**. That is a mismatch under RA-201.10.
- The [ChatGPT TB76 Review](Architecture_M6_CP3_TB76_P13_Linux_Vase_Independent_Review_Decision_20261104.md) verified the evidence. Its successor, the diagnostic CB84, is superseded by RA-202.1: open-ended product instrumentation for the implementation agent, which overlooked the same-run Linux/macOS ratio evidence.
- RA-202 also corrects RA-201.10. Its registration predicted Linux from a macOS-only time, and its "timeout means CB82 did not take" was not a valid inference.

### Earlier: TB71 to TB73 (folded by RA-203)

Facts are in the records, `TODO.md` steps and Review track, `CHANGELOG.md` and the tracker:
- [RA-200](Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md), [CB79](Architecture_M6_CP3_CB79_P13_Node_Stitch_Key_Code_Build_Record_20261103.md), [TB73](Architecture_M6_CP3_TB73_P13_Node_Stitch_Key_Full_Gate_Execution_Report_20261103.md);
- [RA-199](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md), [CB78](Architecture_M6_CP3_CB78_P13_Support_Chord_Admission_Code_Build_Record_20261102.md), [TB72A](Architecture_M6_CP3_TB72A_Orchestration_Record_20261102.md), [TB72 invalid attempt](Architecture_M6_CP3_TB72_Orchestration_Failure_Report_20261102.md);
- [TB71](Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md).

## Turn Sequence

| Step | Canonical turn | Track / condition |
|---|---|---|
| 1 — COMPLETE | `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC` | Linux 869/869, membership 950, census as registered |
| 2 — COMPLETE | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` | Static decision; RA-193 probe adjudication (exact patches, TB67 manifest 871); RA-194 review of the landed diagnostics and its revert |
| 3 — COMPLETE | `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` | Implementation agent, Linux; exact revert (RA-194.6), source equality with `911840c1…`, no build |
| 4 — COMPLETE | `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | Implementation agent, Linux; RA-193.10 (`35727214…`, `29 1`), spec RA-193.5, compile only. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TERMINAL-STOP`; infrastructure → `M6-CP3-CB69A-P13-ARRANGEMENT-TERMINAL-ORCH` |
| 5 — COMPLETE | `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869/869, membership 950, census per RA-193.6 (Vase `arrangement` / `RepeatedNodeCycle`). Mismatch → `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-REV`; infrastructure → `M6-CP3-TB66A-P13-ARRANGEMENT-TERMINAL-ORCH` |
| 6 — COMPLETE | `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION` | Implementation agent, Linux; RA-193.11 (`e93f5d8c…`, `37 30` / `95 0`), spec RA-193.7, compile only. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-WEDGE-STOP`; infrastructure → `M6-CP3-CB70A-P13-ARRANGEMENT-WEDGE-ORCH` |
| 7 — COMPLETE | `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | Implementation agent, Linux; gate 871/871, membership 952, census per RA-193.8 (Vase ABNORMAL 600 s timeout). Mismatch → `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-REV`; infrastructure → `M6-CP3-TB67A-P13-ARRANGEMENT-WEDGE-ORCH` |
| 8 — Review COMPLETE | `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (P13-f) | Static decision, then RA-195 probe adjudication: Amendment 27, exact CB71/CB72, TB68 manifest 873 |
| 9 — COMPLETE | `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` | Implementation agent, Linux; RA-195.8 (`8512400f…`), spec RA-195.4, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-GRAPH-STOP`; infrastructure → `M6-CP3-CB71A-P13-COMPLETION-GRAPH-ORCH` |
| 10 — COMPLETE | `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH` | Implementation agent, Linux; RA-195.9 (`514c6d87…`), spec RA-195.5, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-PASS-GRAPH-STOP`; infrastructure → `M6-CP3-CB72A-P13-COMPLETION-PASS-GRAPH-ORCH` |
| 11 — COMPLETE | `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 873 `3b6b9f42…` + ledger v5, 873/873, membership 954; census per RA-195.6. Mismatch → `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-REV`; infrastructure → `M6-CP3-TB68A-P13-COMPLETION-GRAPH-ORCH` |
| 12 — Review COMPLETE | `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING` (P13-g) | Static decision (no probe, open A/B CB73), then [RA-196](Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md) probe adjudication: Amendment 28, exact CB73/CB74/CB75, TB69 manifest 878 |
| 13 — COMPLETE | `M6-CP3-CB73-P13-COMPLETION-EMBEDDING` | **COMPLETE**; exact RA-196.9 patch source `57c24325f539`, eight-target compile package 13104267023. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-EMBEDDING-STOP`; infrastructure → `M6-CP3-CB73A-P13-COMPLETION-EMBEDDING-ORCH` |
| 14 — COMPLETE | `M6-CP3-CB74-P13-COMPLETION-QUADRANGULATION-SEARCH` | Implementation agent, Linux; RA-196.10 (`b2c6a251…`), spec RA-196.5, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-QUADRANGULATION-STOP`; infrastructure → `M6-CP3-CB74A-P13-COMPLETION-QUADRANGULATION-ORCH` |
| 15 — COMPLETE | `M6-CP3-CB75-P13-COMPLETION-TERMINAL-DETAIL` | Implementation agent, Linux; RA-196.11 (`d1f5652a…`), spec RA-196.6, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-TERMINAL-STOP`; infrastructure → `M6-CP3-CB75A-P13-COMPLETION-TERMINAL-ORCH` |
| 16 — COMPLETE | `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 878 `aaaba077…` + ledger v5, 878/878, membership 959; census per RA-196.7 (Vase RED `completion` / `PatchCompletionRejected` / `closed-form`). Mismatch → `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-REV`; infrastructure → `M6-CP3-TB69A-P13-COMPLETION-EMBEDDING-ORCH` |
| 17 — Review COMPLETE | `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING` (P13-h; P13-i classified) | ChatGPT review WIP (blocked: "no trace"), then [RA-197](Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md) probe adjudication: Amendment 29, exact CB76, TB70 manifest 880 |
| 18 — COMPLETE | `M6-CP3-CB76-P13-PATCH-BOUNDARY-SIDE-START` | Implementation agent, Linux; RA-197.7 (`5c7918fb…`), spec RA-197.4, compile only. Mismatch → `M6-CP3-PLAN-P13-PATCH-SIDE-START-STOP`; infrastructure → `M6-CP3-CB76A-P13-PATCH-SIDE-START-ORCH` |
| 19 — COMPLETE | `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-EXEC` | [Report](Architecture_M6_CP3_TB70_P13_Patch_Side_Start_Full_Gate_Execution_Report_20261102.md): 880/880 PASS, membership 961, census Cylinder PASS / BunnyRandom P13-e RED / Vase generated-vertex P13-h2 RED, registered outcomes MATCH; no mismatch or infrastructure route |
| 20 — Review COMPLETE | `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (P13-h2, P13-i) | ChatGPT review WIP (BLOCKED: "Review policy prohibits runtime probes"), then [RA-198](Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md) probe adjudication: Amendment 30, exact CB77, TB71 manifest 881; P13-i → selection DEFN |
| 21 — COMPLETE | `M6-CP3-CB77-P13-NEEDLE-GRID-BOUNDARY-SEARCH` | Implementation agent, Linux; RA-198.8 (`673010d4…`), spec RA-198.4, compile only. Mismatch → `M6-CP3-PLAN-P13-NEEDLE-GRID-STOP`; infrastructure → `M6-CP3-CB77A-P13-NEEDLE-GRID-ORCH` |
| 22 — COMPLETE | `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-EXEC` | [Report](Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md): 881/881 PASS, membership 962; census Cylinder PASS / BunnyRandom P13-e RED / Vase P13-i `side-count-unsupported` RED; registered outcomes MATCH, no mismatch or infrastructure route |
| 23 — Review COMPLETE | `M6-CP3-DEFN-P13-FLOWREP-SELECTION` (P13-i) | ChatGPT preflight (BLOCKED: no scratch execution), then [RA-199](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md) probe adjudication: unmet support chords → Amendment 31, exact CB78, TB72 manifest 883; O25; next failure P13-j |
| 24 — COMPLETE | `M6-CP3-CB78-P13-SUPPORT-CHORD-ADMISSION` | Implementation agent, Linux; RA-199.8 (`1d8b80e7…`, `119 0` / `153 0`, keep 3 single-space context lines), spec RA-199.4, compile only. Mismatch → `M6-CP3-PLAN-P13-SUPPORT-CHORD-STOP`; infrastructure → `M6-CP3-CB78A-P13-SUPPORT-CHORD-ORCH` |
| 25 — INVALID ORCHESTRATION | `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 883 `e9eabb06…` + ledger v5, 883/883, membership 964; census per RA-199.5 (Vase RED `completion` / `AssemblyRejected` / `NonManifoldStitchedVertex`, within 600 s). Mismatch → `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-REV`; infrastructure → `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH` |
| 25A — COMPLETE | `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH` | Corrected executor; run 41540264758, 883/883 PASS, 81 deferred, membership964, 1774/1774 hashes; invalid TB72 attempt retained. |
| 26 — Review COMPLETE | `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (P13-j, Vase) | ChatGPT same-turn records (BLOCKED: completed lineage unmeasured, no C++), then [RA-200](Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md) probe adjudication: node-intrinsic boundary key → Amendment 32, exact CB79, TB73 manifest 886; O26; next failure P13-k |
| 27 — COMPLETE | `M6-CP3-CB79-P13-NODE-STITCH-KEY` | Implementation agent, Linux; RA-200.8 (`89f37001…`, `25 2` / `95 0`, keep 1 single-space context line), spec RA-200.4, compile only. Mismatch → `M6-CP3-PLAN-P13-NODE-STITCH-KEY-STOP`; infrastructure → `M6-CP3-CB79A-P13-NODE-STITCH-KEY-ORCH` |
| 28 — COMPLETE | `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 886 `5d09fa33…` + ledger v5, 886/886, membership 967; census per RA-200.5 (Vase **ABNORMAL** 600 s timeout after assembly; any verdict before 600 s is a mismatch). Mismatch → `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-REV`; infrastructure → `M6-CP3-TB73A-P13-NODE-STITCH-KEY-ORCH` |
| 29 — Review COMPLETE | `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (P13-k, Vase) | ChatGPT static preflight (BLOCKED: needs scratch execution), then [RA-201](Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md) probe adjudication: five instances of one class → Amendment 33, exact CB80–CB83, TB74–TB76 manifests; P13-l named (pre-optimization output validation; detail `SelfIntersectingFace`) |
| 30 — COMPLETE | `M6-CP3-CB80-P13-RAIL-BINDING-ONCE` | Implementation agent, Linux; RA-201.4: patch file `d4dda97e…` (281 lines, keep its 11 single-space context lines), numstat `15 8` / `31 23` / `128 0`, compile only. Mismatch → `M6-CP3-PLAN-P13-RAIL-BINDING-STOP`; infrastructure → `M6-CP3-CB80A-P13-RAIL-BINDING-ORCH` |
| 31 — COMPLETE | `M6-CP3-TB74-P13-RAIL-BINDING-ONCE-FULL-GATE-EXEC` | Implementation agent; manifest 888 `bb4e771f…` + ledger v5, 888/888, membership 969; census Cylinder PASS, BunnyRandom P13-e, **Vase ABNORMAL 600 s**. Mismatch → `…-FULL-GATE-REV`; infrastructure → `M6-CP3-TB74A-P13-RAIL-BINDING-ONCE-ORCH` |
| 32 — COMPLETE | `M6-CP3-CB81-P13-LENT-PROJECTION-CACHE` | Implementation agent; RA-201.6: `ffa4b554…` (169 lines, 6 single-space context lines), numstat `7 1` / `29 11` / `58 0`. Mismatch → `M6-CP3-PLAN-P13-LENT-PROJECTION-CACHE-STOP`; infrastructure → `M6-CP3-CB81A-P13-LENT-PROJECTION-CACHE-ORCH` |
| 33 — COMPLETE | `M6-CP3-TB75-P13-LENT-PROJECTION-CACHE-FULL-GATE-EXEC` | Implementation agent; manifest 890 `a134d941…`, 890/890, membership 971; census as TB74 (**Vase ABNORMAL 600 s**) |
| 34 — COMPLETE | `M6-CP3-CB82-P13-LENT-LABEL-SUPPORT` | Implementation agent; RA-201.8: `b963ea3d…` (349 lines, 10 single-space context lines), numstat `19 5` / `3 2` / `54 13` / `122 0`. Mismatch → `M6-CP3-PLAN-P13-LENT-LABEL-SUPPORT-STOP`; infrastructure → `M6-CP3-CB82A-P13-LENT-LABEL-SUPPORT-ORCH` |
| 35 — COMPLETE | `M6-CP3-CB83-P13-OUTPUT-VALIDATION-TERMINAL-DETAIL` | Implementation agent; RA-201.9: `3741697e…` (16 lines, 1 single-space context line), numstat `4 1` `RemeshPipeline.cpp`. Mismatch → `M6-CP3-PLAN-P13-OUTPUT-VALIDATION-TERMINAL-STOP`; infrastructure → `M6-CP3-CB83A-P13-OUTPUT-VALIDATION-TERMINAL-ORCH` |
| 36 — COMPLETE / MISMATCH | `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-EXEC` | Implementation agent; manifest 893 `3b727161…`, 893/893, membership 974; census Cylinder PASS, BunnyRandom P13-e, **Vase RED within 600 s, `NotProductionReady:completion detail=SelfIntersectingFace`**. Timeout → CB82 did not take; `detail=None` → CB83 did not take. Mismatch → `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV`; infrastructure → `M6-CP3-TB76A-P13-OPTIMIZER-SOURCE-QUERY-ORCH`. Actual: Vase ABNORMAL 600 s → Review |
| 36A — Review COMPLETE | `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV` (P13-m, Vase) | ChatGPT Review (evidence verified; successor diagnostic CB84), then [RA-202](Architecture_M6_CP3_TB76_REV_P13_Census_Path_Cost_Probe_Adjudication_20261104.md) probe adjudication: three memory-bound census-path scans and two Amendment 33 sites → Amendment 34, exact CB85–CB88, TB77/TB78 manifests 896/899; O27, O28, O29 |
| 36B — WITHDRAWN | `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING` | Started by the implementation agent; never applied or compiled. Superseded by RA-202.3; do not apply its preserved patch |
| 37 — COMPLETE | `M6-CP3-CB85-P13-ARRANGEMENT-TJUNCTION-FACE-SCAN` | Implementation agent, Linux; RA-202.4: `5b6d35a4…` (178 lines, keep 2 single-space context lines), numstat `3 0` / `25 11` / `96 0`, compile only. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TJUNCTION-STOP`; infrastructure → `M6-CP3-CB85A-P13-ARRANGEMENT-TJUNCTION-ORCH` |
| 38 — COMPLETE | `M6-CP3-CB86-P13-SELECTION-ENDPOINT-NET-CHANGE` | Implementation agent, Linux; RA-202.5 exact patch (167 lines), source `0f4c78c4…`, eight-target compile [41879102285](https://github.com/akashskypatel/Directional/actions/runs/41879102285) PASS, package `13347299644` (28/28 hashes); GUARD rows 895–896 compiled, not executed. [Record](Architecture_M6_CP3_CB86_P13_Selection_Endpoint_Net_Change_Code_Build_Record_20261104.md) |
| 39 — COMPLETE | `M6-CP3-TB77-P13-PRE-ASSEMBLY-COST-FULL-GATE-EXEC` | [TB77 report](Architecture_M6_CP3_TB77_P13_Pre_Assembly_Cost_Full_Gate_Execution_Report_20261104.md): immutable CB86 gate [41886202087](https://github.com/akashskypatel/Directional/actions/runs/41886202087) **896/896 PASS**, membership 977, 81 deferred, 1,800/1,800 hashes; census [41886240724](https://github.com/akashskypatel/Directional/actions/runs/41886240724) Cylinder PASS, BunnyRandom P13-e RED vertex49, Vase ABNORMAL `HARNESS_TIMEOUT 600s` (registered); no promotion. Next CB87 separate. |
| 40 — COMPLETE | `M6-CP3-CB87-P13-BOW-TIE-VERTEX-EDGES` | Exact RA-202.7 patch on source `d02fa6ce7467`; Linux eight-target [compile 41897641171](https://github.com/akashskypatel/Directional/actions/runs/41897641171) PASS, artifact `13356343883` (28/28 hashes), GMP/GMPXX, `runtimeExecution=false`; GUARD rows 897–898 compiled, not executed. [Record](Architecture_M6_CP3_CB87_P13_Bow_Tie_Vertex_Edges_Code_Build_Record_20261104.md) |
| 41 — COMPLETE | `M6-CP3-CB88-P13-FINAL-VALIDATION-ROW-LABELS` | Implementation agent; RA-202.8: `ee12a33f…` (72 lines, 0 single-space context lines), numstat `5 2` / `40 0`, compile only. Mismatch → `M6-CP3-PLAN-P13-FINAL-VALIDATION-LABELS-STOP`; infrastructure → `M6-CP3-CB88A-P13-FINAL-VALIDATION-LABELS-ORCH` |
| 42 — COMPLETE | `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-EXEC` | Implementation agent; manifest 899 `9d2c1ec5…`, 899/899, membership 980; census Cylinder PASS, BunnyRandom P13-e, Vase RED `SelfIntersectingFace` in 268.93 s. The registered 67,829 quads was a macOS-only value; Linux has 67,784 (RA-203.2/.3, O30) |
| 42A — Review COMPLETE | `M6-CP3-TB78-P13-CENSUS-PATH-COST-FULL-GATE-REV` | ChatGPT [WIP](Architecture_M6_CP3_TB78_REV_P13_Census_Count_Review_WIP_20261104.md) (BLOCKED on the review boundary), then [RA-203](Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md): the block is RA-202.9's route; TB78 is COMPLETE; O30 opened; exact CB89 → TB79 |
| 42B — COMPLETE | `M6-CP3-CB89-P13-CENSUS-PLATFORM-DIGEST` | Implementation agent, Linux; RA-203.5: `64af5c71…` (68 lines, keep its 3 single-space context lines), numstat `45 0` tests only, compile only. Mismatch → `M6-CP3-PLAN-P13-CENSUS-PLATFORM-DIGEST-STOP`; infrastructure → `M6-CP3-CB89A-P13-CENSUS-PLATFORM-DIGEST-ORCH` |
| 42C — NEXT | `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-EXEC` | Implementation agent; RA-203.6: TB78 manifest 899 reused, 899/899, membership 980; census Cylinder PASS, BunnyRandom P13-e, Vase RED `SelfIntersectingFace` within 600 s with **67,784** quads; seven `platform-digest` lines recorded verbatim. Mismatch → `M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-REV` (Review, Claude, scratch build); infrastructure → `M6-CP3-TB79A-P13-PLATFORM-DIGEST-ORCH` |
| 42D (Review, after TB79) | `M6-CP3-DEFN-P13-PLATFORM-SPLIT` (O30, Vase) | Claude, scratch build. Compare TB79's digests with the [macOS reference](Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv) through the RA-203.4 decision table → exact fix, or the GCC/libstdc++ discriminator |
| 43 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l, Vase) → CB → TB | Claude, scratch build (RA-202 state = CB88). First measurement: same-direction interior edges right after assembly and after `orient_quads_to_source_normals`, by patch. Then decide whether the pre-optimization gate applies final quality thresholds (DESIGN §4.9). Time O27 once orientation passes. Its TB pins only typed verdicts and counts already observed on Linux (RA-203.2) |
| 44 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) → CB → TB | Claude, scratch build; probe DEFN, then exact patch |
| 45 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

The implementation agent takes rows 42B and 42C, in order, one turn each, and starts 42C only after 42B is verified. Rows 42D, 43 and 44 are probe turns on the Review track (Claude, scratch build). A turn that cannot run a scratch probe must not start them; it records BLOCKED at entry (RA-172, RA-198 to RA-203).

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB79-P13-PLATFORM-DIGEST-FULL-GATE-EXEC**.
- CB89 compiled source `9c9616695ecdc8c6ec219eb7486cbe85f3915c95`, immutable package artifact `13370954424`, 28/28 hashes, eight GMP/GMPXX targets; no test execution.
- Next is separate TB79 artifact-only gate (RA-203.6), no rebuild.
- Do not resume or apply `M6-CP3-CB84-P13-LINUX-VASE-DIAGNOSTIC-TIMING` (withdrawn).
- Review track, only with scratch-build execution:
  - `M6-CP3-DEFN-P13-PLATFORM-SPLIT` (O30, after TB79);
  - `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l);
  - the P13-e DEFN.
- CB85–CB88, TB77–TB78 and the TB78 Review are complete; do not replay them.

Read first:
- [RA-203](Architecture_M6_CP3_TB78_REV_P13_Platform_Split_Adjudication_20261104.md):
  - §1, the block and its resolution (Review scratch probes are a duty; Linux runtime is a TB);
  - §2, RA-202.9's macOS-only count;
  - §3, TB78 adjudication and attribution;
  - §4, O30 and the frozen decision table;
  - §5–§6, the CB89 and TB79 specs, with the `.diff` file and the [macOS reference digests](Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv);
  - §8, the sequence.
- [RA-202](Architecture_M6_CP3_TB76_REV_P13_Census_Path_Cost_Probe_Adjudication_20261104.md):
  - §1, the review of the TB76 Review and RA-201's corrections;
  - §2, findings: the census-path cost profile, FMA ruled out, the cross-checks;
  - §3, rulings: CB84 withdrawn, Amendment 34, O27–O29;
  - §4–§9, the CB85, CB86, TB77, CB87, CB88 and TB78 specs, with the four `.diff` files;
  - §10, the sequence; §11, scratch verification;
  - DESIGN Amendment 34.
- [RA-201](Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md): §1 findings (five instances of one class; P13-l named); §3 rulings; §4–§10 CB80, TB74, CB81, TB75, CB82, CB83, TB76 specs with the four `.diff` files; §11 sequence; §12 scratch verification; DESIGN Amendment 33.
- [RA-200](Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md): §1 findings (identical certificates, halfedge-scoped key, 23,221 split nodes, P13-k next); §2 probes; §3 rulings (closes the earlier Review's open conditions); §4 CB79 and §5 TB73 specs; §6 sequence; §8 exact patch; DESIGN Amendment 32.
- [RA-199](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md): §1 findings (lenses are unmet support chords; coverage and degrees not the owner; P13-j next); §2 probes; §4 CB78 and §5 TB72 specs; §6 sequence; §8 exact patch; DESIGN Amendment 31.
- [TB71 report](Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md): immutable CB77 gate 881/881 and census (Vase P13-i).
- [RA-198](Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md): §1 findings (P13-h2 owner completion; P13-i owner selection, which removes 0 of 4,057 candidates); §2 probes; §4 CB77 and §5 TB71 specs; §6 sequence; §8 exact patch; DESIGN Amendment 30.
- [TB70 report](Architecture_M6_CP3_TB70_P13_Patch_Side_Start_Full_Gate_Execution_Report_20261102.md): exact Linux immutable gate/census evidence and new post-CB76 Vase failure.
- [RA-197](Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md): §1 findings (owner: side-0 registration); §2 probes (first-pass census, rotation, interpolants, P13-i lenses); §4 CB76 and §5 TB70 specs; §6 sequence; §7 exact patch; DESIGN Amendment 29.
- [TB69 report](Architecture_M6_CP3_TB69_P13_Completion_Embedding_Full_Gate_Execution_Report_20261102.md): immutable CB75 gate 878/878 and census (Vase P13-h at patch 4).
- [RA-196](Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md): §1 findings on the static decision; §2 probes (first-pass failure census); §4–§7 CB73, CB74, CB75, TB69 specs; §8 sequence; §9–§11 exact patches; DESIGN Amendment 28.
- [TB68 full gate and production census report](Architecture_M6_CP3_TB68_P13_Completion_Graph_Full_Gate_Execution_Report_20261101.md): exact immutable source, gate, census and P13-g failure locus.
- [CB72 Code + Build record](Architecture_M6_CP3_CB72_Completion_Pass_Graph_Code_Build_Record_20261101.md): exact source, immutable compile artifact, 28 checks and no-runtime boundary.
- [CB71 Code + Build record](Architecture_M6_CP3_CB71_Completion_Chart_Graph_Reuse_Code_Build_Record_20261101.md): frozen exact source/patch, successful compile artifacts and no-runtime boundary.
- [RA-195](Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md): §4–§6 CB71, CB72, TB68 specs; §7 sequence; §8–§9 exact patches; DESIGN Amendment 27.
- [TB67 report](Architecture_M6_CP3_TB67_P13_Arrangement_Wedge_Full_Gate_Execution_Report_20261101.md): immutable 871/871 gate, exact result artifacts, independent census, timeout limits and no acceptance promotion.
- [RA-193](Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md): §8 registered timeout, §9 P13-f Review successor and earlier O(F) probe attribution; use current renumbering from [RA-194](Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md).
- [CB70 report](Architecture_M6_CP3_CB70_Arrangement_Wedge_Rotation_Code_Build_Record_20261101.md): immutable source/package boundary, not runtime acceptance.
- [TB66 report](Architecture_M6_CP3_TB66_P13_Arrangement_Terminal_Full_Gate_Execution_Report_20261101.md): predecessor baseline and P13-e signature.
- Relevant `DESIGN.md` Amendments 26–33, `LESSONS.md` §§1, 2, 3, 5, 6, 7 and `Regression_Root_Cause_Tracker.md` P13-f candidate.

Inputs:

| Input | Value |
|---|---|
| CB68 completed | [`90fa3a15`](https://github.com/akashskypatel/Directional/commit/90fa3a155930c2683ed0789ef88e9f8f52775437); restored source byte-identical to compiled `911840c1…` on all source/build/test paths; workflow `41306617232`, `runtimeExecution=false` |
| TB66 evidence | gate [41312768151](https://github.com/akashskypatel/Directional/actions/runs/41312768151) / `13086562028`; census [41312834931](https://github.com/akashskypatel/Directional/actions/runs/41312834931) / `13086079391`; 869/869, 1 PASS / 2 registered RED; all hashes/pass boundaries verified. |
| CB71 package | Source `042979f7a264dff21de4e3b1af25a1a27fe27c95`, [run 41329208274](https://github.com/akashskypatel/Directional/actions/runs/41329208274), artifact `13092069619`, ZIP `729a5ff0020ea81d762ef7fa2276e40c07288a93c75219918408de0dabc2d9e0`, 28/28 checks, no runtime. |
| CB72 package | Source `7b85b450bc98abfb65db511fdcd524eb11f537f8`, [run 41333097065](https://github.com/akashskypatel/Directional/actions/runs/41333097065), artifact `13093439789`, ZIP `9b9482fd92af01bc4de0e72964459765c70bca3acb4583a12df0ac5ccb7c7e20`, 28/28, GMP/GMPXX, `runtimeExecution=false` |
| CB69 package | Source `5b08abe42f91f88fd6d09e225c7cf32d0aeb1ef3`, [run 41310503404](https://github.com/akashskypatel/Directional/actions/runs/41310503404), artifact `13084749209`, eight GMP/GMPXX targets, compile-only |
| TB66 gate | TB65 manifest 869 `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`, unchanged; ledger v5 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; membership 950 |
| TB67 gate | Manifest 871 `Architecture_M6_TB67_P13_Arrangement_Wedge_Full_Gate_Case_Manifest.tsv` `434e6d373c327d909f6b458fb9b10bd8cdac5d3c073dfefe11fbb30ee34a385b` (TB65 869 byte-identical prefix plus rows 870–871); same ledger; membership 952 |
| TB68 gate | Manifest 873 `Architecture_M6_TB68_P13_Completion_Graph_Reuse_Full_Gate_Case_Manifest.tsv` `3b6b9f425d4061885b393ccd2d530cbcd3d4f39916859e0db197ce1e6029ea60` (TB67 871 byte-identical prefix plus rows 872–873); same ledger; membership 954; `SELF_CHECK_PASS cases=873 deferred=81` |
| CB75 package | Source `8656c4fed5070a467da491b60ead5c8ab1d99dbd`, [compile 41365067300](https://github.com/akashskypatel/Directional/actions/runs/41365067300), artifact `13107147891`, ZIP SHA-256 `a689c5b3254682a6345f2e17e43e3a8e571401c1ed6a224d13a4a5f84c8bc7d2`, 28/28 internal hashes; GMP/GMPXX, no runtime. |
| TB69 gate | Manifest 878 `Architecture_M6_TB69_P13_Completion_Embedding_Full_Gate_Case_Manifest.tsv` `aaaba077a067853a00310683946f82394c60247bd42717fd283b4d7cde423c82` (TB68 873 byte-identical prefix plus GUARD rows 874–878); same ledger; membership 959; `SELF_CHECK_PASS cases=878 deferred=81` |
| TB70 gate | Manifest 880 `Architecture_M6_TB70_P13_Patch_Side_Start_Full_Gate_Case_Manifest.tsv` `a9f964c843a5620f281bf2ca2f07e7df9b8d11a7769218a635a5b707aaf2b03b` (TB69 878 byte-identical prefix plus GUARD rows 879–880); same ledger; membership 961; `SELF_CHECK_PASS cases=880 deferred=81` |
| TB71 gate | Manifest 881 `Architecture_M6_TB71_P13_Needle_Grid_Full_Gate_Case_Manifest.tsv` `f2503dcaf91b13c4a221d52fe7a18899327ab6f96862c3688a67f8f8d14c78a6` (TB70 880 byte-identical prefix plus GUARD row 881); same ledger; membership 962; `SELF_CHECK_PASS cases=881 deferred=81` |
| TB72 gate | Manifest 883 `Architecture_M6_TB72_P13_Support_Chord_Full_Gate_Case_Manifest.tsv` `e9eabb064fba1aa625b20931f1b85cf3f441c0c877a81cccd49b73bb5ebd3031` (TB71 881 byte-identical prefix plus GUARD rows 882–883); same ledger; membership 964; `SELF_CHECK_PASS cases=883 deferred=81` |
| TB73 gate | Manifest 886 `Architecture_M6_TB73_P13_Node_Stitch_Key_Full_Gate_Case_Manifest.tsv` `5d09fa337b42adc8629f4bded8ea35b2181e468fb9dd91f7db5414fa534cfc4a` (TB72 883 byte-identical prefix plus GUARD rows 884–886); same ledger; membership 967; `SELF_CHECK_PASS cases=886 deferred=81` |
| CB80–CB83 patches | `Architecture_M6_CP3_CB80_P13_Rail_Binding_Once.diff` `d4dda97eeea13c4c50ca107fa06bf093b7a173abce9a0bbfb268e8793da265fe`; `…CB81_P13_Lent_Projection_Cache.diff` `ffa4b5548b6bf45f044dac4b46fb2cca51db051b324d2ca7c0116faae99a4e30`; `…CB82_P13_Lent_Label_Support.diff` `b963ea3d4b440fea66b65926478861b7bb6c489166f21b7db41769dc31cde1d2`; `…CB83_P13_Output_Validation_Terminal_Detail.diff` `3741697ed34d219579a97081db3763126292a3d103a445e2ceda6cbbf37df682`. They apply in that order on CB79 source; result hashes are in RA-201.4/.6/.8/.9 |
| TB74 gate | Manifest 888 `Architecture_M6_TB74_P13_Rail_Binding_Once_Full_Gate_Case_Manifest.tsv` `bb4e771fd911d9aefdb83c89cf2ac8def41e464bb41f26778a1b3a98adbee4da` (TB73 886 byte-identical prefix plus GUARD rows 887–888); same ledger; membership 969; `SELF_CHECK_PASS cases=888 deferred=81` |
| TB75 gate | Manifest 890 `Architecture_M6_TB75_P13_Lent_Projection_Cache_Full_Gate_Case_Manifest.tsv` `a134d9411bd5885fa85d7405e2a733da7cd4d5899d17a83f6dbcb501d18326c6` (TB74 888 prefix plus rows 889–890); membership 971; `SELF_CHECK_PASS cases=890 deferred=81` |
| TB76 gate | Manifest 893 `Architecture_M6_TB76_P13_Optimizer_Source_Query_Full_Gate_Case_Manifest.tsv` `3b72716137800726f9ce46a7ea6aee1f8a7db0122be29df97c359ea098545bf8` (TB75 890 prefix plus rows 891–893); membership 974; `SELF_CHECK_PASS cases=893 deferred=81` |
| CB85–CB88 patches | Each applies on the previous one, starting from CB83 source:<br>`Architecture_M6_CP3_CB85_P13_Arrangement_TJunction_Face_Scan.diff` `5b6d35a4808393d7274d8f574fa4f68eb343946bc3b065f2c1e8992babcac2f7`<br>`…CB86_P13_Selection_Endpoint_Net_Change.diff` `c2a0c3083df29f99b43dd953ca871f02abf7961f731b52d5de5650c0b621ae81`<br>`…CB87_P13_Bow_Tie_Vertex_Edges.diff` `eeef1a515995e032e2a35342a4b92a678c309933845c03102915c1e071f53237`<br>`…CB88_P13_Final_Validation_Row_Labels.diff` `ee12a33fedc24047a960f38a7ba04b905d54716d80ff8c40b5723614b5636640`<br>Result hashes are in RA-202.4/.5/.7/.8 |
| TB77 gate | Manifest 896 `Architecture_M6_TB77_P13_Pre_Assembly_Cost_Full_Gate_Case_Manifest.tsv` `48ef4743b18683e78d9f740c4eb0e7f249abcab78a4aeac849620e251d9fface` (TB76's 893-row prefix plus rows 894–896); membership 977; `SELF_CHECK_PASS cases=896 deferred=81` |
| TB78 gate | Manifest 899 `Architecture_M6_TB78_P13_Census_Path_Cost_Full_Gate_Case_Manifest.tsv` `9d2c1ec598fea2b95b251fd2e007b7086740e51fb8f6f3ad7ff5671ab09ddb44` (TB77's 896-row prefix plus rows 897–899); membership 980; `SELF_CHECK_PASS cases=899 deferred=81` |
| CB89 patch | `Architecture_M6_CP3_CB89_P13_Census_Platform_Digest.diff` `64af5c71ad57a662724b077761f71c1c38893be6ed32516fc568166e85c23f71`, 68 lines, keep its 3 single-space context lines. Precheck base CB88 `6cc50f878ef8…`; numstat `45 0` `tests/SurfaceCellDesignAcceptanceTests.cpp`; result `ba60c6905db983b53c35a2b5e909a04152eaa557cac8382c84457c5d0f5b1941` |
| TB79 gate and census | TB78 manifest 899 `9d2c1ec5…` reused unchanged, membership 980; census three-case manifest `3af1dc0d…`. Comparator for the Review only: [macOS reference](Architecture_M6_CP3_CB89_P13_Platform_Digest_macOS_Reference.tsv) `7e2796fe4991553becf1006d400f288368fe9c9781a6bc0d154faaaa821a167e` |
| Census | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Harness | P8 `78b8002c…`, unchanged |

Standing state: CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted. O16 (macOS), O17, O19, O20, O21, O22, O23, P13-e, P13-g gated by CB73–CB75/TB69, P13-h CB76/TB70 verified; P13-h2 → CB77/TB71 verified; P13-i → Amendment 31, CB78/TB72A verified (RA-199); P13-j → Amendment 32, CB79/TB73 verified (RA-200); P13-k → Amendment 33, CB80–CB83/TB74–TB76 verified (RA-201); P13-m → Amendment 34, CB85–CB88/TB77–TB78 verified (RA-202, RA-203; Linux Vase 268.93 s); O30 Vase completion platform split → CB89/TB79, then DEFN (RA-203); P13-l → completed-mesh orientation DEFN; O24, O25, O26; O27, O28, O29 (RA-202); DR1/DR3, DR2/DR4 and O6/O9 are carried.

## Resume-critical lessons — DURABLE, DO NOT DELETE

The substantive lessons live in `LESSONS.md`; use the relevant section rather than copying incident accounts.

| Section | Read it before |
|---|---|
| 1. Evidence, acceptance, and scope | Interpreting results, claiming acceptance, changing gates/selectors or classifying regressions. |
| 2. Witnesses, tests, and independent oracles | Designing fixtures, tests, invariants or independent checks. |
| 3. Semantic ownership, identity, and dataflow | Modifying semantic IDs, representations or producer-consumer contracts. |
| 4. Geometry, topology, and mathematical obligations | Changing geometric algorithms, topology or exact predicates. |
| 5. Diagnostics, classifiers, and causal investigation | Instrumentation, rejecting predicates or root-cause hypotheses. |
| 6. Contracts, planning, reviews, and durable records | Requirements, plans, reviews, authorization or documentation. |
| 7. Build, artifact, workflow, and tool mechanics | Compilation, packaging, CI, artifacts or repository operations. |

New lessons belong in `LESSONS.md`, not here.

## Maintenance — one live handoff

At authorized closeout, **replace** current authority, next action, conditional successor and context **in place**. Keep the durable purpose/policy/load/lesson sections. Archive completed changes in `CHANGELOG.md`, evidence in reports/tracker, tasks in `TODO.md`. Never append a second `CURRENT` section, a transcript or old turn ladder. The mandatory end checklist and `Durable_Handoff_Policy.md` govern `STATUS` closeout.
