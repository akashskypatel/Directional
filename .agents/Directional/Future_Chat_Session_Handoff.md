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
| Currency | 2026-10-20, TB18 artifact-only harvest complete. Part A 12/14 PASS; Part B 448/497 PASS, 49 RED, +23 PASS vs TB16C, zero PASS→RED; 30 B2 exited B2 (16 PASS, 14 RED/other). Candidate/non-stable only; independent TB18-REV mandatory. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 draft); refetch before mutation. Semantic source `3bd24682c5e18eece541ab4d1f38f781a2230e41`; CB18 package `12227516380` (ZIP `d09c32d6…31cdc4`, expires 2026-10-26), compile-only. Record: `Architecture_M6_CP3_CB18_R10_Consumer_Rail_Vertex_Endpoint_Code_Build_Record_20261019.md`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB18 Part A: run `39349041417`, result `12231529583` (ZIP `e08b092d…b459`, 12/14); Part B: run `39349459268`, result `12232299548` (ZIP `b3ba4566…6e9b`, 448/497). Both expire 2026-11-03; harvested, **not independently adjudicated**. TB16C baseline `12207970911`: 425/497. Inventory SHA `36cc9682cab7…`, report `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Harvest_Report_20261020.md`. Not promoted. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected. Fixture debt (RA-96.6 order) after TB18-REV; see `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` remains open: 30 prior B2 I–R records now 16 PASS / 14 RED with new first failures; independent Review must adjudicate remaining producer `PublishedProductRejected` and fixture debt. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` — EXACT NEXT

- **Type / owner:** Independent Review; RA-103.5 and existing review policy.
- **Objective:** independently re-derive and adjudicate TB18 Part A/Part B; assign the next precise `RP-01` and fixture-debt turn.
- **Read before work:** RA-103.5 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`); report `Architecture_M6_CP3_TB18_Rail_Vertex_Endpoint_Harvest_Report_20261020.md`; inventory `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`; immutable artifacts `12231529583`, `12232299548` and TB16C baseline `Architecture_M6_CP3_TB16C_Selector_497_Red_Inventory.tsv`.
- **In scope:** independent artifact/log/hash/classification verification; assign or reject candidate evidence; document corrective plan and fixture debt, update appropriate review records/tracker.
- **Out of scope:** runtime execution, compiles, source/test/fixture/selector changes or unreviewed `RP-01` repairs.
- **Success evidence:** independently computed 14-row and 497-row outcomes, all 30 previous B2 classifications, both cross-region `PublishedProductRejected` cases and Part A universal-factory uncertainty addressed, next exact turn frozen.
- **On success:** successor `UNKNOWN` until Review assigns it under existing authority.
- **On failure/blocker:** retain review turn and publish precise unresolved evidence, no speculative successor.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` | Independent Review of both harvested artifacts. |
| 2 — conditional | `UNKNOWN` | Next `RP-01` or fixture-debt turn assigned by TB18-REV, not in TB18. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — independent TB18-REV on archived immutable evidence; no runtime, compile or source edits.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. RA-103.5 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`), new TB18 report and inventory; both TB18 result artifacts; TB16C baseline inventory/report; `LESSONS.md` §§1, 2, 5.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md`.

**Review tooling:** `.agents/Directional/tools/` holds read-only `review_check.py`, `selector_probe.py`, and `fixture_probe.py`; history-sensitive review gates require real committed history, not a synthesized snapshot.

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
