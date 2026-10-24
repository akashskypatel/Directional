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
| Currency | 2026-10-24, TB33 six-case artifact-only runtime complete as **candidate**, separate independent TB33 Review required. [TB33 report](Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Report_20261024.md). |
| Source and package | Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB32 semantic `30e46b9aabc44925643f46bab20db40962a5e494`; CB32 compile package `12541198172`, immutable ZIP SHA-256 `17a121aac12d288892853a2455d3f72411a5538eeda512a7d2c9c096a7d47651`, GMP/GMPXX, `runtimeExecution=false`. |
| Current runtime candidate | [TB33 run 40051854120](https://github.com/akashskypatel/Directional/actions/runs/40051854120); artifact `12543546779`, ZIP SHA256 `217f6b214707b4165252a23537284f5aa6ebf242e2de1d8b691774d35272c09d`, **15/15 checksums, six/6 PASS, zero RED/invalid/missing/duplicate/skip**, postflight verified. New six-case manifest `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Cases.tsv`. |
| Accepted vs candidate | Accepted CP2 **491/491**. TB32 **481/500 PASS, 19 inherited RED** candidate remains; TB33 synthetic odd source oracle run does not promote periodic/A5/A6 or CP3. Stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached; selector497 frozen. |

## Mandatory next turn — `UNKNOWN` — EXACT NEXT ROLE: independent TB33 Review

- **Type:** independent Review of `M6-CP3-TB33-RP01-ODD-ATLAS-ORACLE-VERIFICATION`. Exact canonical identifier is not assigned in present authority: **UNKNOWN**; do not invent one or start Review in the TB33 turn.
- **Evidence:** independently re-open immutable result `12543546779` from [run 40051854120](https://github.com/akashskypatel/Directional/actions/runs/40051854120); verify outer digest and 15 internal hashes, all six raw logs, exact GTest identities, one process each, immutable preflight/postflight, source-based signed odd `3/1` and topology-keyed permutation expected values; verify negative guard reachability and distinguish non-vacuous negative rejection from merely passing GTest. [Owning report](Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Report_20261024.md).
- **Stop/promotion:** any mismatch or vacuity invalidates the associated claim; no redesign or implementation in Review. Do not reinterpret 19 inherited REDs as fixed, alter accepted CP2 491/491 or stable 66/17/49, or credit A5/A6/produced periodic topology. Record Review verdict and independently assign any later owner.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — exact next role | `UNKNOWN` | Separate independent TB33 Review; repository authority must assign canonical ID |
| later | `UNKNOWN` | Only after Review adjudicates scoped evidence and owns following work |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **independent_review** — immutable TB33 six-process raw-log/negative-non-vacuity audit only; do not execute tests, recompile, or alter product/test source.

Minimum context after mandatory policies:
0. ORIENTATION, ROADMAP, this handoff, TODO, TB33 report, exact TB33 manifest, CB32-REV decision/CB32 source oracle tests, original immutable package authority.
1. Immutable [TB33 run 40051854120](https://github.com/akashskypatel/Directional/actions/runs/40051854120), result artifact `12543546779`, ZIP SHA-256 `217f6b214707b4165252a23537284f5aa6ebf242e2de1d8b691774d35272c09d`, ledger and raw logs.
2. RA-148 TB32 reviewed 481/500 candidate and 19 inherited RED; RA-146.2–4, RA-45.4, G4-B002, retained CP2 491/491 and stable 66/17/49 debt1.
3. Tracker unresolved owners and LESSONS §2; do not promote produced periodic/A6 or CP3 from synthetic fixture oracle evidence.

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
