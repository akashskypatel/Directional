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
| Currency | 2026-10-18, after compile-only `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR` |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Exact CB11 semantic source `9432aa05ef4719cbea912ae0feb2c5508c4e497a`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. |
| Latest candidate or rejected evidence | CB11 eight-target GMP compile **GREEN**, [run `39085601323`](https://github.com/akashskypatel/Directional/actions/runs/39085601323), artifact `12121016836`, source `9432aa05ef4719cbea912ae0feb2c5508c4e497a`; no runtime and **not promoted**. Latest TB10 diagnostic 44/44 RED (`38941839640`); R3 **403/497** rejected. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01`: no endpoint branch admits an interior vertex of an open rail. U1 shared route-anchor is compile-only complete; TB11 is next. R10B U2–U4 require a reviewed green predecessor (RA-84.5). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR` — EXACT NEXT

- **Type / owner:** `TB` (artifact-only, immutable); RA-84.5 U1 verification.
- **Objective:** execute the CB11 truth-table and forged-terminal regressions and the retained `Produced` control against the compiled U1 package; establish runtime evidence without source mutation.
- **Read before work:** `Architecture_M6_CP3_CB11_R10_Open_Rail_Route_Anchor_Code_Build_Record_20261018.md`, RA-84 review, and the R10B rule §3; exact compile artifact `12121016836` at source `9432aa05ef4719cbea912ae0feb2c5508c4e497a`.
- **In scope:** immutable artifact-only Test + Benchmark with the authorized CB11 tests and unchanged controls, exact-one process accounting, verified package and frozen selector authority.
- **Out of scope:** recompiling/relinking, test/source/selector mutation, new endpoint eligibility, U2–U4, recovery, or speculative repairs.
- **Success evidence:** tests run with independent assertions and existing `Produced` control intact; package/source hashes, GMP runtime dependencies, exact selection and immutability receipts; report runtime outcomes without conflating compile with pass.
- **On success:** mandatory independent predecessor review before conditional `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` (Review turn ID `UNKNOWN`; do not invent).
- **On semantic failure:** Review + Plan, ID `UNKNOWN — STOP`; orchestration failures follow `Turn_Cadence.md` rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR` | Immutable artifact-only verification of compiled U1. |
| 2 — conditional | `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | Only after green TB11 and its required independent Review; do not start during TB11. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — immutable compiled artifact; no compile or source mutation.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_CB11_R10_Open_Rail_Route_Anchor_Code_Build_Record_20261018.md`, RA-84 Review, R10B rule §3, `Architecture_M6_Frozen_Definitions.md` RA-84, `GMP_COMPILE_POLICY.md`.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats. History gates (`authority|boundary|ledgers`, drift `--base`) are Review gates (RA-82.3); implementation turns run `document_drift_audit.py --root .` only.

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
