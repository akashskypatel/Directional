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
| Currency | 2026-10-24, CB32 test-only oracle correction compiled without runtime (pending independent CB32-REV). The CB31 rejection is addressed as an unreviewed source candidate only; accepted product/selector state remains unchanged. [CB32 record](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Code_Build_Record_20261024.md). |
| Branch/source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB32 semantic `30e46b9aabc44925643f46bab20db40962a5e494`, immutable compile [run 40046062512](https://github.com/akashskypatel/Directional/actions/runs/40046062512), artifact `12541198172`, ZIP SHA-256 `17a121aac12d288892853a2455d3f72411a5538eeda512a7d2c9c096a7d47651`, 28/28 checksums, eight GMP/GMPXX targets, `runtimeExecution=false`. [Record](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Code_Build_Record_20261024.md). |
| TB32 scoped candidate | RA-148 reviewed **481/500 PASS / 19 RED**; original 497 **478 PASS / 19 inherited RED**, no regressions. Factory only; no generated odd inverse or A6 acceptance. |
| Accepted vs candidate | CP2 **491/491 accepted**, CP3 unaccepted; stable **66/17/49**, debt1; RP-01 open, RP-02 unreached, Gate C suspended; selector497 and TB32 manifest frozen. |

## Mandatory next turn — `M6-CP3-CB32-RP01-ODD-TRANSPORT-ORACLE-CORRECTION-REV` — EXACT NEXT

- **Type:** independent static Review of CB32 code/compile provenance; no runtime.
- **Required proof:** rederive expected odd signed transport from raw cross arms, oriented source edge and semantic topology; check row/corner remapping, distinct stale-gauge and inverse-arm falsifiers, and ensure unchanged nine preexisting cases. Source is a compile-only candidate, not a runtime PASS.
- **Read:** [CB32 plan](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Code_Build_Plan_20261023.md), [CB31 rejection](Architecture_M6_CP3_CB31_Odd_Atlas_Transport_Permutation_Review_Decision_20261023.md), [CB32 code/build record](Architecture_M6_CP3_CB32_Odd_Transport_Oracle_Correction_Code_Build_Record_20261024.md), RA-148 and `LESSONS.md` §2.
- **Boundary:** no source/product/test/selector/manifest/workflow changes or binaries in Review. No semantic acceptance or gate promotion without separately reviewed immutable test evidence.
- **Stop:** reject the candidate if expected signed inverse is circular, source topology assumptions are wrong, negatives are inert or an earlier guard masks the target. Review owns next-turn authorization; immutable TB remains `UNKNOWN` pending accepted Review.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — exact next | `M6-CP3-CB32-RP01-ODD-TRANSPORT-ORACLE-CORRECTION-REV` | Independent static oracle and compile-evidence Review; no runtime |
| 3 — conditional | `UNKNOWN` | Immutable TB only when separate CB32 Review accepts and freezes identities |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — independently reassess CB32 raw signed-oracle and compile provenance, no test execution or successor work.

Minimum context after mandatory policies:
0. ORIENTATION, ROADMAP, this handoff, TODO, CB32 record and plan, CB31 rejection decision, and exact CB32 compile artifacts.
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
