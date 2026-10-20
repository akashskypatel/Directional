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
| Currency | 2026-10-19, Review pull after the TB18 yield: both RA-103.5 runs (Part A and Part B) completed in CI, but `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` is still IN_PROGRESS with no harvest, inventory or report. TB18 resumes for harvest only. The CB18 package was re-verified by Review (28/28; packaged `src/include/tests/CMakeLists.txt` byte-identical to `3bd24682c`). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 draft); refetch before mutation. Semantic source `3bd24682c5e18eece541ab4d1f38f781a2230e41`; CB18 package `12227516380` (ZIP `d09c32d6…31cdc4`, expires 2026-10-26), compile-only. Record: `Architecture_M6_CP3_CB18_R10_Consumer_Rail_Vertex_Endpoint_Code_Build_Record_20261019.md`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB18 Part A: run `39349041417`, result `12231529583` (ZIP `e08b092d…b459`). TB18 Part B: run `39349459268`, result `12232299548` (ZIP `b3ba4566…6e9b`). Both expire 2026-11-03; **unharvested and unadjudicated**. Census baseline TB16C `12207970911`: **425/497** (expires 2026-11-02). Not promoted. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected. Fixture debt (RA-96.6 order) after TB18-REV; see `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` B2 (30 I–R records at rail vertex 4). CB17 (U4) accepted; CB18 (U5) compiled and measured by TB18, not yet adjudicated. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` (resume) — EXACT NEXT

- **Type / owner:** TB, artifact-only, resumed turn; RA-103.5. Keep `Turn` and `Started at`; set `Resumed at`.
- **Objective:** harvest the two completed immutable runs into the RA-103.5 deliverables. No new execution.
- **Read before work:** RA-103.5 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`); the two TB18 result artifacts above; `Architecture_M6_CP3_TB16C_Selector_497_Red_Inventory.tsv` and its report (format and baseline).
- **In scope:**
  1. Download both results; verify the ZIP SHA-256, the internal `SHA256SUMS`, the harness hashes (`cf613111…ead6` Part A, `947a95ee…79dd` Part B) and the candidate authority (artifact `12227516380`, source `3bd24682c`).
  2. Part A: the 14-row ledger. Mark each RA-103.5 Part A prediction and falsifier as held, fired or undetermined, citing the raw log. For the falsifier "factory `InvalidSourceAuthority` on a route the consumer certified with R", state exactly what the raw logs can and cannot show.
  3. Part B: `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv` in TB16C's column format with TB16C as the baseline columns. Classes (RA-90.4/RA-91.2: B1, B2, B3, B2+B3, U6, other) are computed from the raw logs. List TB16C PASS→RED and RED→PASS, and give the TB18 result and first failure of each of the 30 TB16C B2 identities.
  4. One report of 30 lines or fewer covering Part A and Part B; a tracker entry; docs updated in place.
- **Out of scope:** re-running any workflow; compiles; source, test, selector or harness edits; root-cause claims beyond first-failure classification; remediation.
- **Success evidence:** both artifacts verified; the TSV and the report; every RA-103.5 prediction and falsifier adjudicated with an evidence pointer.
- **On success:** `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` (mandatory).
- **On failure/blocker:** STOP if an artifact cannot be downloaded or verified; never re-run inside TB18.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` (resume) | Harvest only; both runs are complete. |
| 2 — mandatory | `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` | Review in every case: adjudicates RA-103.5 against the harvest and assigns the next RP-01 turn and fixture debt. |
| planned, not authorized | next RP-01 blocker diagnosis → fixture debt (242 → 174 → 250 → adjacent-sheet → 191 → 442, plus the I/R sites) → census → RP-01 Review | Only as TB18-REV assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — resume TB18 for harvest only (RA-103.5); no execution, compile or source edits.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. RA-103.5 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`); the TB18 Part A and Part B result artifacts; `Architecture_M6_CP3_TB16C_Selector_497_Red_Inventory.tsv` and `Architecture_M6_CP3_TB16C_Selector_497_Census_Report_20261019.md`; `Architecture_M6_CP3_TB17_Factory_Rail_Vertex_Endpoint_Harvest_Report_20261019.md` (report format); `LESSONS.md` §§1, 2, 5.
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
