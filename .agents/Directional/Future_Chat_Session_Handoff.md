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
| Currency | 2026-10-18, after immutable `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS`: **425/497**, with unexpected selector 199 PASS; independent TB14A Review next. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. CB14A semantic source `2ee499a3403c07be05e8084a669f30c1c735f04a` (test-only); production code unchanged since CB13 (`70217cc2`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, 403/497). The R3 baseline is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED); artifact `11661044443` expires 2026-10-24. |
| Latest candidate or rejected evidence | TB14A [run 39143325285](https://github.com/akashskypatel/Directional/actions/runs/39143325285), result `12141843937` SHA-256 `1b06e43e87f416e7b44dce65059f1789301f402dd9d43d71fcabf2a3c604d455`, CB14A package `12140756646`: **425 PASS / 72 RED** of 497, +5 over TB13C 420/497 (selectors 199,235,236,294,299 RED→PASS). Identity 199 falsifies RA-93.4 predicted RED; no production promotion. Owner `Architecture_M6_CP3_TB14A_Curved_Disk_Control_Census_Report_20261018.md`. |
| Regression accounting and debt | **66/17/49**, debt **1** unchanged; selector 497 frozen; M6 CP2 491/491 remains last accepted runtime, R3 403/497 rejected. Selector 199 unexpectedly PASS; 250 remains RED; remaining fixture debts 174/191-family/242/442/250 and adjacent-sheet helper. See regression tracker. |
| Active boundary | `RP-01`: B1 U3 closed; B2 U4/U5 11 identities; B3 U6 DEFN-first 19 identities. Four restored curved-disk controls 235/236/294/299 PASS; 199 PASS unexpectedly (RA-93.4 prediction falsifier) requires Review before promotion. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV` — EXACT NEXT

- **Type:** independent Review + Plan; no implementation, test, fixture, selector, compile, or runtime mutations.
- Re-open immutable TB14A [run 39143325285](https://github.com/akashskypatel/Directional/actions/runs/39143325285), result `12141843937` and unchanged source/package `2ee499a3403c07be05e8084a669f30c1c735f04a` / `12140756646`; compare TB13C census.
- Verify 497/497 processes, 1019/1019 result hashes, 425 PASS / 72 RED, five RED→PASS, no new RED, zero compile/relink/test/fixture/selector mutation.
- **Critical:** RA-93.4 predicted selector 199 stays RED but moves from P10:5395 to P10:5428; observed **PASS**. Independently determine non-vacuity and correct oracle behavior; do not presume promotion.
- Verify 235/236/294/299 expected PASS, 237/253/254 unchanged PASS and 250 unchanged RED at P10:3597 (`PublishedProductRejected`); assess all other unchanged identities.
- Classify any discrepancy without inventing stable regression IDs, update evidence and task records, perform Review policy orientation/consolidation. Only after Review assign DEFN-U6, U4/U5 order and test debt. No successor beyond Review yet authorized.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE` | Test-only source `2ee499a3403c`; GMP eight-target package `12140756646`. |
| done | `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE-REV` | RA-93 accepted CB14A and froze TB predictions. |
| done | `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS` | 425/497; unexpected selector 199 PASS; immutable source/package. |
| 1 — next | `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV` | Independent primary evidence review and plan; no implementation or runtime. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review-plan** — independently re-open immutable TB14A primary evidence and TB13C comparator; do not execute, compile or alter implementation/fixtures/selectors.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, TB14A report and primary artifact `12141843937`, TB13C selector inventory, RA-92/93 review decision, `Regression_Root_Cause_Tracker.md`, `TODO.md`, and `REVIEW_TURN_POLICY.md`.

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
