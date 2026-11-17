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
| Currency | 2026-11-17 UTC, TB131 executed the CB154 FC-7′ switch: MISMATCH under RA-252 §6. [Execution report](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Execution_Report_20261117.md). Gate 952/953 PASS, all 17 neutral PASS, 648 PASS, 858 permitted premise RED at line 155; no proxy census or trace-trace H1 receipt. |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD. CB154 source `452eb3d789016e744e99d88811add0f7e0949165`; package `14347130681`, ZIP SHA-256 `f768d7dc97fb6cf7f345f45fe6e52e681c6d7c21b6436ff3239ef44cec382489`; [compile record](Architecture_M6_CP3_CB154_P13_Carrier_Contact_Node_Switch_Code_Build_Record_20261117.md). CB151/TB129 comparator authority remains in the TB129 execution report. |
| Accepted evidence | [TB125](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb125_p13_edge_terminal_exact_inventory_execution_report_20261117md) scoped 950/950; artifacts `14289730737`/`14289927334`. CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. TB127 comparison authority: package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate `14302887671` 951/951, census `14302668940`. |
| Latest candidate | TB131 gate `14349985217` (952/953, membership 1,034), census `14349666706` (Cylinder PASS 288, BunnyRandom/Vase RED), both postflight valid. Unaffected gate 931/934 match; rows 174/176/179 differ in diagnostic order/framing; Vase parameter bytes differ under literal frozen rules. [Report](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Execution_Report_20261117.md). Comparator TB130 gate `14338844806`, census `14339793522`. 955/956 substantive ledger records equal. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O45/O46 open; narrow C3/O44/C1 closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | FC-7′ eliminates observed H1 receipts but TB131 MISMATCH precludes O45 closure. Sphere `InvalidNetworkBinding/origin=InvalidCutGraphBinding`, trace 4, edge 0-2, no face or rotation reason; BunnyRandom `RotationSystemInconsistent/TraceEventPositionNodeConflict`, trace 82, face (21,72,273). Row 648 sphere assertions not reached; row 858 RED at `SurfaceCellTracingDisplayTests.cpp:155` (no face locus). FC-6, H2 and MATCH-only definition held. No CP3/D0 acceptance. |

## Mandatory next turn — `M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-REV` — EXACT NEXT

Start only after root [STATUS](../../STATUS) records COMPLETE for `M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-EXEC` with this successor. Authority: [TB131 execution report](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Execution_Report_20261117.md) and [RA-252 §6](Architecture_M6_CP3_DEFN_P13_Carrier_Contact_Switch_Review_20261117.md).

- **Type / owner:** independent Review, runtime-free. Re-open immutable TB131 gate `14349985217` and census `14349666706`, plus TB130 comparator `14338844806`/`14339793522`; exact source and digests in report.
- **Verify:** adjudicate literal MISMATCH and four unexpected log differences, including TB129's parameter-object normalization precedent; confirm neutral and premise rows, absence of retired receipts, and new sphere/BunnyRandom failures. Distinguish diagnostic changes from semantic regressions; review FC-7′ locality and formulate the authorized next action only on evidence.
- **Out of scope:** runtime, rebuild, source/test/fixture/selector mutation, FC-6/H2 implementation, promotion. Do not treat disappearance of H1 as closure of O45 before adjudication.

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
| COMPLETE | `M6-CP3-CB153-P13-CARRIER-PROXY-CONTACT-DRY-RUN` | Frozen diagnostic diff compiled; [record](Architecture_M6_CP3_CB153_P13_Carrier_Proxy_Contact_Dry_Run_Code_Build_Record_20261117.md). |
| COMPLETE (MATCH) | `M6-CP3-TB130-P13-CARRIER-PROXY-CONTACT-FULL-GATE-EXEC` | 953/953 PASS, census dispositions unchanged; 19 PASS rows with outgoing proxies. [Report](Architecture_M6_CP3_TB130_P13_Carrier_Proxy_Contact_Full_Gate_Execution_Report_20261117.md). |
| COMPLETE | `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH` (RA-252) | FC-7′ frozen; unstaged switch justified (all proxy builds rejected); CB154 exact diff and TB131 criteria. [DEFN](Architecture_M6_CP3_DEFN_P13_Carrier_Contact_Switch_Review_20261117.md). |
| COMPLETE | `M6-CP3-CB154-P13-CARRIER-CONTACT-NODE-SWITCH` | Exact diff compiled with eight targets; [record](Architecture_M6_CP3_CB154_P13_Carrier_Contact_Node_Switch_Code_Build_Record_20261117.md). |
| COMPLETE (MISMATCH) | `M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-EXEC` | 952/953 PASS, permitted premise RED 858, unaffected log differences 174/176/179 and Vase; no retired receipts. [Report](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Execution_Report_20261117.md). |
| NEXT | `M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-REV` | Independently adjudicate literal mismatch, premise RED, and new sphere/BunnyRandom outcomes. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6) | After the TB131 Review. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS` | Replaced by CB151; replaced by CB153 (RA-251). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | O45 resolved by FC-7′ only on TB131 MATCH. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: independent Review (`M6-CP3-TB131-P13-CARRIER-CONTACT-SWITCH-FULL-GATE-REV`), only after TB131 STATUS is COMPLETE naming it. Use the turn-appropriate skill and read all mandatory policies first.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [TB131 execution report](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Execution_Report_20261117.md), [CB154 Code + Build record](Architecture_M6_CP3_CB154_P13_Carrier_Contact_Node_Switch_Code_Build_Record_20261117.md), [RA-252 DEFN](Architecture_M6_CP3_DEFN_P13_Carrier_Contact_Switch_Review_20261117.md), [CB154 exact diff](Architecture_M6_CP3_CB154_P13_Carrier_Contact_Node_Switch_Exact.diff), [TB130 execution report](Architecture_M6_CP3_TB130_P13_Carrier_Proxy_Contact_Full_Gate_Execution_Report_20261117.md), [CB153 Code + Build record](Architecture_M6_CP3_CB153_P13_Carrier_Proxy_Contact_Dry_Run_Code_Build_Record_20261117.md), [CB153 exact diff](Architecture_M6_CP3_CB153_P13_Carrier_Proxy_Contact_Dry_Run_Exact.diff), [TB129 Review + RA-251](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md), [TB129 execution report](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Execution_Report_20261117.md), [TB128 independent Review](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md), [TB128 execution report](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md), [CB151 Code + Build record](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Code_Build_Record_20261117.md), [CB150 Code + Build record](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Code_Build_Record_20261117.md), exact [CB150](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Exact.diff) and [CB151](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Exact.diff) diffs, [CB149 compile record](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Code_Build_Record_20261117.md), [RA-249](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Freeze_Review_20261117.md) and [RA-248](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md). Preserve [CB147](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Exact.diff), [CB148](Architecture_M6_CP3_CB148_P13_Face_Contact_Node_Helpers_Exact.diff), [CB149](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Exact.diff) exact diffs and frozen gate/census. Prior records resolve through [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
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
