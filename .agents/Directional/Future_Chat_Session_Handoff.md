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
| Currency | 2026-10-19, after `M6-CP3-CB18-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` compiled and packaged successfully; runtime validation is owned by TB18, not CB18. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 draft); refetch head before mutation. Exact compiled semantic source `3bd24682c5e18eece541ab4d1f38f781a2230e41`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | CB18 compile [run 39337458721](https://github.com/akashskypatel/Directional/actions/runs/39337458721), artifact `12227516380` (ZIP `d09c32d6e7c06e280b3f9888008cde2ebb4738c3e6273f7a661903f2d231cdc4`), manifest 28/28, 8 GMP/GMPXX targets, `runtimeExecution=false`; unpromoted. Owning record: `Architecture_M6_CP3_CB18_R10_Consumer_Rail_Vertex_Endpoint_Code_Build_Record_20261019.md`. TB17 reviewed RA-103; last full TB16C census 425/497. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen. No new runtime evidence from CB18. |
| Active boundary | `RP-01` B2 on 30 I–R rail-vertex-4 records. CB17 factory U4 and CB18 consumer U5 are compile-complete; TB18 RA-103.5 must measure them. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` — EXACT NEXT

- **Type / owner:** TB (Test + Benchmark, artifact-only); RA-103.5.
- **Objective:** measure CB18's R endpoint behavior against the frozen focused and conditional selector-497 gates; do not infer runtime success from compilation.
- **Read before work:** RA-103 §103.5 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`), CB18 compile record `Architecture_M6_CP3_CB18_R10_Consumer_Rail_Vertex_Endpoint_Code_Build_Record_20261019.md`, TB17 harness and frozen TB16C baseline.
- **In scope:** consume immutable artifact `12227516380` with exact semantic source `3bd24682c5e18eece541ab4d1f38f781a2230e41` and ZIP SHA-256 `d09c32d6e7c06e280b3f9888008cde2ebb4738c3e6273f7a661903f2d231cdc4`. Part A: TB17 harness with #14 added (14 exact-filter identities); Part B: unchanged 497 census harness only if Part A satisfies its gate. Produce frozen comparison TSV and ≤30-line results report per RA-103.5.
- **Out of scope:** source edits, fixture changes, compiles, relinks, selector edits, workflow redesign, remediation within the immutable TB gate, or benchmark execution.
- **Success evidence:** exact package/source postflight, full selected test ledger, RA-103.5 Part A falsifier adjudication and conditional Part B evidence. Even a RED gate goes to Review.
- **On success:** `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` (mandatory).
- **On failure/blocker:** do not repair/retest inside TB; mandatory `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV`, or STOP for environmental inability to execute the authorized TB.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|
| 1 — next | `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` | Artifact-only Part A; Part B only if Part A meets RA-103.5 gate. |
| 2 — mandatory | `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` | Independent review of TB18 under any measured outcome. |
| planned, not authorized | Fixture debt → census → RP-01 Review | Only after mandatory TB18 Review assigns exact turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — TB18 immutable CB18 package, Part A then conditional Part B (RA-103.5); no compile or source edits.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. RA-103.5 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`), CB18 compiled package/record (`Architecture_M6_CP3_CB18_R10_Consumer_Rail_Vertex_Endpoint_Code_Build_Record_20261019.md`), TB17 harness `efa91d9b…c7a9`, last full census TB16C report `Architecture_M6_CP3_TB16C_Selector_497_Census_Report_20261019.md`; `LESSONS.md` §§1, 2, 7.
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
