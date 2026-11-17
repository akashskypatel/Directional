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
| Currency | 2026-11-17 UTC, RA-251 re-review of the TB129 independent Review: MISMATCH and H1 upheld; prose CB152 withdrawn; exact CB153 gate-wide carrier-proxy dry-run census and TB130 frozen. [RA-251](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md#ra-251--adversarial-re-review-of-this-review-2026-11-17-utc). |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD. CB151 source `c45e9abe5085f39c1f5bcb149ec07f95b719177e`; package `14327212608`, ZIP SHA-256 `9ef0f781947748cf2433566f3704259ab362dbf8f042999f87248ca6d645eb69`; [compile record](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Code_Build_Record_20261117.md). |
| Accepted evidence | [TB125](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb125_p13_edge_terminal_exact_inventory_execution_report_20261117md) scoped 950/950; artifacts `14289730737`/`14289927334`. CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. TB127 comparison authority: package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate `14302887671` 951/951, census `14302668940`. |
| Latest candidate | TB129 gate `14329895372` (953/953, membership 1,034, postflight valid), census `14328938547` (1 PASS/2 RED). TB128 comparators `14318100443`/`14317054197`. Frozen gate `941287fa…`, census `3af1dc0d…`. All 951 prior PASS ledger records match; rows858/952 restored; 66 sphere receipt lines in 19 gate rows, two BunnyRandom lines. R6 excludes additional rows and requires one BunnyRandom line. [Report](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Execution_Report_20261117.md). |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | A2a′ `ArcTraceTerminalCutPositionMismatch`: H1 incoming-edge contact proxy confirmed on sphere and BunnyRandom. RA-251: the common carrier is the generic case (empty only without an incoming carrier); outgoing-proxy contacts pass the guard but get an edge locus (Amendment 13 violation, possibly in accepted output). Switch predicate is node-level (non-port node with TraceIntersection/TraceSelfClosure), never a blanket drop of the edge test (barrier FirstContact). Per-row incoming/outgoing counts come from TB130. FC-6 and MATCH-only definition held. No CP3/D0 acceptance. |

## Mandatory next turn — `M6-CP3-CB153-P13-CARRIER-PROXY-CONTACT-DRY-RUN` — EXACT NEXT

Start only after root [STATUS](../../STATUS) records COMPLETE for `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-REV` with this successor. Authority: [RA-251 §S4](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md#ra-251--adversarial-re-review-of-this-review-2026-11-17-utc).

- **Type / owner:** Code + Build, compile only. Apply exactly [CB153 diff](Architecture_M6_CP3_CB153_P13_Carrier_Proxy_Contact_Dry_Run_Exact.diff), SHA-256 `c8b9bc2115c1bc40da9520f473949b50d52ad5866782e58cf09d1acdd205e350`, 171 lines, numstat `102 2 src/geometry/EmbeddedGraphTopology.cpp`, `7 2 src/geometry/EmbeddedGraphTopology.h`. Precheck `git diff --quiet c45e9abe5085f39c1f5bcb149ec07f95b719177e HEAD -- src include tests`.
- **Verify:** eight RA-245 GMP/GMPXX targets, immutable package and compile evidence, runtimeExecution=false. No test, benchmark or binary execution. Compile defect → `M6-CP3-PLAN-P13-CARRIER-PROXY-DRY-RUN-STOP`; build infrastructure → `M6-CP3-CB153A-P13-CARRIER-PROXY-DRY-RUN-ORCH`.
- **Out of scope:** the contact switch, FC-6, CB145, H2, manifests/selectors, promotion, TB130 execution.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE (MISMATCH) | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC` | 951/953; census comparison matched. [Report](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md). |
| COMPLETE | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-REV` + RA-250 | Mismatch upheld. CB149B withdrawn. H1/H2 hypotheses frozen. [Review + RA-250](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md#ra-250--adversarial-re-review-of-this-review-2026-11-17-utc). |
| COMPLETE | `M6-CP3-CB150-P13-FACE-CHART-WITNESS-CORRECTION` | Test-only exact diff compiled; [record](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Code_Build_Record_20261117.md). |
| COMPLETE | `M6-CP3-CB151-P13-TERMINAL-CUT-BEFORE-END-RECEIPT` | Diagnostic-only exact diff compiled. [Record](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Code_Build_Record_20261117.md). |
| COMPLETE (MISMATCH) | `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-EXEC` | 953/953, frozen comparison fails; H1 observed both fixtures. [Report](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Execution_Report_20261117.md). |
| COMPLETE (MISMATCH upheld) | `M6-CP3-TB129-P13-TERMINAL-CUT-RECEIPT-FULL-GATE-REV` | [Independent Review](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md): all 68 H1; comparison scope/count defect; no promotion. |
| COMPLETE | RA-251 re-review of the TB129 Review | Upheld MISMATCH/H1; CB152 withdrawn; CB153 exact diff and TB130 criteria frozen. [RA-251](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md#ra-251--adversarial-re-review-of-this-review-2026-11-17-utc). |
| NEXT | `M6-CP3-CB153-P13-CARRIER-PROXY-CONTACT-DRY-RUN` | Exact diagnostic diff `c8b9bc21…`, compile only. |
| Then | `M6-CP3-TB130-P13-CARRIER-PROXY-CONTACT-FULL-GATE-EXEC` | Frozen gate/census/deferred on CB153 package; MATCH per RA-251 §S5 (TB129 logs after deleting census lines). |
| Then | Review `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH` | Freeze FC-7′ node-level switch (`:1075`, `:1910`, `build_node_loci`); unstaged only if no accepted row has `lastOutgoing>0`, else off-by-default option (RA-230). Then switch CB → TB. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6) | After the switch TB. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS` | Replaced by CB151; replaced by CB153 (RA-251). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY`; O45 | O45 disposition requires Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: Code + Build (`M6-CP3-CB153-P13-CARRIER-PROXY-CONTACT-DRY-RUN`), only after the TB129 Review STATUS is COMPLETE naming it. Use the turn-appropriate skill and read all mandatory policies first.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [CB153 exact diff](Architecture_M6_CP3_CB153_P13_Carrier_Proxy_Contact_Dry_Run_Exact.diff), [TB129 Review + RA-251](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md), [TB129 execution report](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Execution_Report_20261117.md), [TB128 independent Review](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md), [TB128 execution report](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md), [CB151 Code + Build record](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Code_Build_Record_20261117.md), [CB150 Code + Build record](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Code_Build_Record_20261117.md), exact [CB150](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Exact.diff) and [CB151](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Exact.diff) diffs, [CB149 compile record](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Code_Build_Record_20261117.md), [RA-249](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Freeze_Review_20261117.md) and [RA-248](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md). Preserve [CB147](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Exact.diff), [CB148](Architecture_M6_CP3_CB148_P13_Face_Contact_Node_Helpers_Exact.diff), [CB149](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Exact.diff) exact diffs and frozen gate/census. Prior records resolve through [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
3. [Architecture_M6_Frozen_Definitions.md](Architecture_M6_Frozen_Definitions.md), [DESIGN.md](DESIGN.md), [tracker](Regression_Root_Cause_Tracker.md) and [TODO](../../TODO.md).
4. [Historical record index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17) resolves superseded filenames; old turn ladders and navigation preimages are history only, not instructions. CB84 Linux Vase diagnostic timing attempt, CB121A 16-row fan-resolver plan and CB102 withdrawn. Reviews runtime-free; no deprecated scratch-build authorization. D6 pending, chain switch off.

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
