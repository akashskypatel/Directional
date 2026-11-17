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
| Currency | 2026-11-17 UTC, [CB147 record](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Code_Build_Record_20261117.md); RA-248 face-contact node definition ([record](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md)); prior RA-247 re-review of TB127-REV. |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD before work. CB146 source `48e6f97d278b2226036f658ce9060a38b8a374b5`, package `14301616031`; [compile record](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Code_Build_Record_20261117.md). CB144 product source unchanged; CB144B and CB146 test-only changes both included. |
| Accepted evidence | [TB125](Architecture_M6_CP3_TB125_P13_Edge_Terminal_Exact_Inventory_Execution_Report_20261117.md) scoped 950/950; artifacts `14289730737`/`14289927334`. Accepted CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. |
| Latest candidate | [TB127](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Full_Gate_Execution_Report_20261117.md): gate `14302887671`, 951/951 PASS; all 950 inherited records match [TB126](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Full_Gate_Execution_Report_20261117.md). Census `14302668940`: Cylinder PASS 288, BunnyRandom and Vase RED unchanged. Four assertion line numbers shift +61; remaining allowed-normalized lines and terminal prefixes match. RA-246 does not authorize line-number normalization. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43 open; narrow C3/O44/C1 closed. Middle-piece rotation witness remains open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | BunnyRandom `TraceEventPositionInvalid` at face `(5,104,359)` (C5): a trace–trace contact inside a face with no shared carrier edge. RA-248 defines the A2a′ face-contact node (FC-1–FC-5). The downstream fragment and ownership stages still use the stale M3 one-chord taxonomy (O46, FC-6). CB147 compiled; CB148 freeze Review is next. Vase completion RED unchanged. CP3/D0 not accepted. |

## Mandatory next turn — `M6-CP3-DEFN-P13-FACE-CONTACT-NODE-FREEZE` — EXACT NEXT

Root [STATUS](../../STATUS) governs the current turn. The CB147 source has been committed; see [CB147 record](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Code_Build_Record_20261117.md).

- **Type / owner:** Review only, per [RA-248](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md) §5.
- **Objective:** Freeze CB148 exactly for contacts with no shared carrier edge (FC-1–FC-5); put arithmetic in pure, unit-testable functions. Freeze TB128's manifest as the unchanged TB127 manifest plus rows 952 and 953.
- **Authority:** [CB147 record](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Code_Build_Record_20261117.md), compiled source `43294bde49e1f24aa09d10ca7e5ff632a7c28d6b`, package `14309111230`. The new helper test is not executed yet.
- **Out of scope:** runtime, implementation of CB148, FC-6 switch, promotion.
- **Conditional successor:** `M6-CP3-CB148-P13-FACE-CONTACT-NODE-SWITCH` only after the Review freezes its exact change and gate.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` (RA-248) | Face-contact node contract FC-1–FC-7; downstream finding O46; CB147 frozen. |
| COMPLETE | `M6-CP3-CB147-P13-FACE-CONTACT-EXACT-HELPERS` | Exact diff, compile only; [record](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Code_Build_Record_20261117.md). |
| NEXT | `M6-CP3-DEFN-P13-FACE-CONTACT-NODE-FREEZE` | Review: freezes CB148 (FC-1–FC-5 for contacts with no shared carrier edge, arithmetic in pure unit-tested functions) and the TB128 gate manifest (TB127 manifest + rows 952 and 953). |
| then | `M6-CP3-CB148-P13-FACE-CONTACT-NODE-SWITCH` | Code + Build. Gate unchanged by construction; only currently failing networks change. |
| then | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC` | Gate + census. BunnyRandom should leave `TraceEventPositionInvalid`; its next terminal is predicted at an FC-6 ownership stage, or at rotation or face walk. |
| then | `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` | Review: classifies TB128 and freezes CB149 (FC-6, not yet wired, with an equal-product test and a measuring receipt). |
| later | CB149 → TB129 → CB150 (FC-6 switch) → TB130 | Each staged per RA-230. |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY`; O45 common-carrier conformance | Not next. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: Review (CB148 freeze) only after root STATUS records CB147 complete. Read [CB147 record](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Code_Build_Record_20261117.md) and all mandatory policies first.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [RA-248](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md) and the [CB147 diff](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Exact.diff), [TB127 independent Review](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md), [TB127](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Full_Gate_Execution_Report_20261117.md), [CB146](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Code_Build_Record_20261117.md), [CB144B](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Code_Build_Record_20261117.md) and [RA-245](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) §5, [CB144](Architecture_M6_CP3_CB144_P13_Edge_Terminal_Owner_Correction_Code_Build_Record_20261117.md), [TB126](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Full_Gate_Execution_Report_20261117.md) and [TB125](Architecture_M6_CP3_TB125_P13_Edge_Terminal_Exact_Inventory_Execution_Report_20261117.md); verify the [exact diff](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Exact.diff), the [CB146 diff](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Exact.diff) (RA-246 §4) and the committed manifests.
3. [Architecture_M6_Frozen_Definitions.md](Architecture_M6_Frozen_Definitions.md) and [DESIGN.md](DESIGN.md) for normative constraints; [tracker](Regression_Root_Cause_Tracker.md) and [TODO](../../TODO.md) for unresolved issues and authorized scope.
4. [Historical record index](M6_Consolidated_Record.md#tb126-review-folded-record-index-2026-11-17) resolves superseded filenames; old turn ladders and navigation preimages are history only, not instructions. The CB84 Linux Vase diagnostic timing attempt, CB121A 16-row fan-resolver plan and CB102 remain withdrawn. Reviews remain runtime-free; no deprecated scratch-build authorization. D6 remains pending and the chain switch remains off.

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
