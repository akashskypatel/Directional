# Directional — Current handoff

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
| Currency | 2026-11-17 UTC, CB150 compile verified. [Code + Build record](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Code_Build_Record_20261117.md). RA-250 upholds TB128 MISMATCH; CB151 and TB129 remain frozen. |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD. CB150 source `b3d7b66e10ed8cfdd94eb0a1f67222efcd2525d9`; compile package `14325348753`, ZIP SHA-256 `4bfe84808ac5d88dc23c607e8d31bb2e4a9af4406d6523432cce7e5c388f470d`; [record](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Code_Build_Record_20261117.md). CB149 source/package remain the TB128 execution authority. |
| Accepted evidence | [TB125](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb125_p13_edge_terminal_exact_inventory_execution_report_20261117md) scoped 950/950; artifacts `14289730737`/`14289927334`. CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. TB127 comparison authority: package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate `14302887671` 951/951, census `14302668940`. |
| Latest candidate | TB128 gate `14318100443` (951/953, 1,034 membership, valid postflight); row858 inherited guard RED, row952 new RED, row953 PASS. Inherited raw differences beyond permitted normalization at 164, 644, 669, 698, 858. Census `14317054197`: Cylinder PASS 288, Vase RED unchanged, BunnyRandom RED new terminal; full preterminal prefix unchanged. [Report](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md). |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | A2a′ `ArcTraceTerminalCutPositionMismatch` (BunnyRandom, origin vertex 3; prescribed sphere). Statically, every Terminal incidence resolved to k < n. Only two deterministic owners remain: H1, a common-carrier contact proxy on the terminator's incoming edge (an FC-7 defect); and H2, a limit-cycle event published on the re-entered face. The CB151 receipt decides between them. Row 952's premise was false (GMP truncation); CB150 corrects it. Row 164 is std::async log interleaving and is compared as a multiset from TB129 on. Row 858 is restored by the real terminal-event face. Vase RED is unchanged. CP3/D0 are not accepted. |

## Mandatory next turn — `M6-CP3-CB151-P13-TERMINAL-CUT-BEFORE-END-RECEIPT` — EXACT NEXT

Start only after root [STATUS](../../STATUS) records COMPLETE for CB150. CB149B is withdrawn; do not implement its prose plan.

- **Type / owner:** Code + Build, compile only, exact diff. [RA-250 §R5](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md#r5-cb151-terminal-cut-before-end-receipt-diagnostic-only-replaces-cb149b).
- **Patch:** [CB151 exact diff](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Exact.diff), SHA-256 `044529d63c2f9e82cad38fb95cad00d4fa299918c6bcd02ffb3c56cc1947b516`; 168 lines; `129 0 src/geometry/EmbeddedGraphTopology.cpp`.
- **Precheck:** `src include tests` equal CB149 `85f9c703c5de86fb2b401cf83c03499a1ce73a27` plus exactly CB150 (source `b3d7b66e10ed8cfdd94eb0a1f67222efcd2525d9`).
- **Build:** eight RA-245 GMP/GMPXX targets; `runtimeExecution=false`.
- **Routes:** mismatch → `M6-CP3-PLAN-P13-TERMINAL-CUT-RECEIPT-STOP`; infrastructure failure → `M6-CP3-CB151A-P13-TERMINAL-CUT-RECEIPT-ORCH`.
- **Out of scope:** product decisions, tests, manifests, selectors, TB129 execution, FC-6, CB145, CP3 promotion.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE (MISMATCH) | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC` | 951/953; the census comparison matched. [Report](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md). |
| COMPLETE | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-REV` + RA-250 | Mismatch upheld. CB149B withdrawn. Row 164 is a concurrency-order artifact. Terminal owner narrowed to H1 (common-carrier contact proxy) or H2 (limit-cycle face). [Review + RA-250](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md#ra-250--adversarial-re-review-of-this-review-2026-11-17-utc). |
| COMPLETE | `M6-CP3-CB150-P13-FACE-CHART-WITNESS-CORRECTION` | Test-only exact diff compiled; [record](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Code_Build_Record_20261117.md). |
| NEXT | `M6-CP3-CB151-P13-TERMINAL-CUT-BEFORE-END-RECEIPT` | Diagnostic exact diff [`044529d6…`](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Exact.diff), 168 lines, `129 0 src/geometry/EmbeddedGraphTopology.cpp`. Precheck: `85f9c703c` + CB150. Routes `M6-CP3-PLAN-P13-TERMINAL-CUT-RECEIPT-STOP` / `M6-CP3-CB151A-P13-TERMINAL-CUT-RECEIPT-ORCH`. |
| then | `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-EXEC` | TB128 manifest unchanged (`941287fa…`, 953 rows); census `3af1dc0d…`. MATCH criteria and H1/H2 classes are in [RA-250 §R6](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md#r6-tb129-frozen-m6-cp3-tb129-p13-terminal-cut-receipt-full-gate-exec). |
| then | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME` | Review: classify H1/H2 and freeze the fix CBs, staged per RA-230. |
| Held | `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6) | After the terminal-cut fix. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT` | Replaced by CB151. |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY`; O45 | O45 is retired if H1 is confirmed. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: Code + Build (`M6-CP3-CB151-P13-TERMINAL-CUT-BEFORE-END-RECEIPT`, exact diff) only after root STATUS records CB150 COMPLETE. Use the turn-appropriate skill and read all mandatory policies first.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [CB150 Code + Build record](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Code_Build_Record_20261117.md), the exact [CB150](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Exact.diff) and [CB151](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Exact.diff) diffs, [TB128 independent Review](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md), [TB128 execution report](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md), [CB149 compile record](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Code_Build_Record_20261117.md), [RA-249](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Freeze_Review_20261117.md) and [RA-248](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md). Preserve all [CB147](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Exact.diff), [CB148](Architecture_M6_CP3_CB148_P13_Face_Contact_Node_Helpers_Exact.diff) and [CB149](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Exact.diff) exact diffs; retain the frozen gate/census. Prior execution records resolve through [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md) and [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) retain the earlier definition and evidence obligations; [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retains the mandatory-edge decision.
3. [Architecture_M6_Frozen_Definitions.md](Architecture_M6_Frozen_Definitions.md) and [DESIGN.md](DESIGN.md) for normative constraints; [tracker](Regression_Root_Cause_Tracker.md) and [TODO](../../TODO.md) for unresolved issues and authorized scope.
4. [Historical record index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17) resolves superseded filenames; old turn ladders and navigation preimages are history only, not instructions. The CB84 Linux Vase diagnostic timing attempt, CB121A 16-row fan-resolver plan and CB102 remain withdrawn. Reviews remain runtime-free; no deprecated scratch-build authorization. D6 remains pending and the chain switch remains off.

**Review tooling:** `tools/review_check.py authority <sha>` and `tools/review_check.py boundary`, `tools/selector_probe.py` and `tools/fixture_probe.py`; see [tools/README.md](tools/README.md). Consult original normative definitions and [LESSONS.md](LESSONS.md) before any later evidence or semantic decision.

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
