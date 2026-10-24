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
| Currency | 2026-10-24, independent CB32-REV **accepts static signed raw-source oracle sufficiency** and exact compile provenance for separate immutable TB, not runtime acceptance. [M6-CP3-CB32-RP01-ODD-TRANSPORT-ORACLE-CORRECTION-REV decision](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Review_Decision_20261024.md). |
| Branch/source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB32 semantic `30e46b9aabc44925643f46bab20db40962a5e494`, immutable compile [run 40046062512](https://github.com/akashskypatel/Directional/actions/runs/40046062512), artifact `12541198172`, ZIP SHA-256 `17a121aac12d288892853a2455d3f72411a5538eeda512a7d2c9c096a7d47651`, 28/28 checksums, eight GMP/GMPXX targets, `runtimeExecution=false`. [Record](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Code_Build_Record_20261024.md). |
| TB32 scoped candidate | RA-148 reviewed **481/500 PASS / 19 RED**; original 497 **478 PASS / 19 inherited RED**, no regressions. Factory only; no generated odd inverse or A6 acceptance. |
| Accepted vs candidate | CP2 **491/491 accepted**, CP3 unaccepted; stable **66/17/49**, debt1; RP-01 open, RP-02 unreached, Gate C suspended; selector497 and TB32 manifest frozen. |

## Mandatory next turn — `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION` — EXACT NEXT

- **Type:** immutable-artifact Test + Benchmark, no configure/build/relink/source/test/selector mutation. Source package `12541198172`, CB32 semantic SHA `30e46b9aabc44925643f46bab20db40962a5e494`.
- **Execute:** three new odd-atlas cases and three unchanged factory controls (six named processes); six earlier recovered selector identities are preserved without unnecessary re-execution; exact named GTest selectors and preflight/postflight are frozen in [M6-CP3-CB32-RP01-ODD-TRANSPORT-ORACLE-CORRECTION-REV decision](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Review_Decision_20261024.md). Independent count, one fresh process per identity, no skips; capture complete raw logs and first guard/locus.
- **Stop:** missing identity, wrong guard, invalid artifact, nonterminal test, skip, timeout, or source/package drift invalidates evidence. Semantic RED stays RED; no post-hoc oracle rewrite. No other cases and no benchmark.
- **Boundary:** the Review accepted only source-oracle sufficiency and compile provenance; all 19 historical RED, accepted CP2 491/491, selector497 and stable 66/17/49 remain unchanged. TB output requires separate TB Review before any gate credit.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — exact next | `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION` | Immutable CB32 focused GTest execution only, no recompile |
| 2 — conditional | `UNKNOWN` | Independent TB Review only after valid evidence; TB cannot claim promotion |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test_benchmark** — immutable CB32 artifact-only odd atlas tests, exact case identities and stop rules from the CB32-REV decision; no compile or test-source edit.

Minimum context after mandatory policies:
0. ORIENTATION, ROADMAP, this handoff, TODO, CB32-REV decision, CB32 record and plan, CB31 rejection, and exact immutable CB32 compile artifact.
1. Exact compiled CB32 source `30e46b9aabc44925643f46bab20db40962a5e494`, [CB32 package 40046062512](https://github.com/akashskypatel/Directional/actions/runs/40046062512) and [CB32 record](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Code_Build_Record_20261024.md), plus prior CB31 source and decision.
2. RA-148 TB32 481/500 candidate and frozen 497 478/497, 19 RED; RA-146.2–4, RA-45.4.
3. Tracker carried obligations and lessons §2; no gate promotion.

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
