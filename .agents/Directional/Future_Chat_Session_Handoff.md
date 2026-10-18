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
| Currency | 2026-10-18, after artifact-only `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR` (semantic RED) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch before mutation. Immutable CB11 source `9432aa05ef4719cbea912ae0feb2c5508c4e497a`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. |
| Latest candidate/rejected evidence | [TB11 run 39092477302](https://github.com/akashskypatel/Directional/actions/runs/39092477302), immutable result artifact `12123605663`, ZIP SHA-256 `e98acd39a8a72f54118c6e6a66f7ec8346a6dd5d1043db06f1b12ad5298d9a65`; **1 PASS, 2 RED**, 0 missing. Both RED at `open-rail-route-anchor` locus 9 before intended assertions. CB11 compile artifact `12121016836`; prior R3 **403/497** rejected. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector **497** frozen. Candidate-only in `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` still open; U1 route-anchor checker rejects pre-existing `Produced` control. Unverified root cause. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — independent TB11 Review + Plan, exact ID UNKNOWN

- **Type:** independent Review + Plan; its canonical identifier is **UNKNOWN** until established by repository authority. Do not invent it.
- **Objective:** independently adjudicate the two shared U1 `open-rail-route-anchor` locus-9 rejections: both original `Produced` fixture preconditions now produce `Rejected`. The forged-terminal tampering was **not reached**.
- **Read before work:** `Architecture_M6_CP3_TB11_Open_Rail_Route_Anchor_Harvest_Report_20261018.md`, result artifact `12123605663`, compiled artifact `12121016836`, CB11 code/build record, RA-84 review and R10B rule.
- **Determine:** whether consumer implementation overrestricts a legal anchor, a fixture is truly invalid, or source-published witness data are absent; require evidence preserving existing positive/negative assertions and source-authoritative constraints.
- **Out of scope:** no automatic remedial code, tests, selectors or acceptance changes in TB11. `CB12/TB12` and U2–U4 require reviewed GREEN U1 predecessor and are currently NOT authorized.
- **Next:** independent Review + Plan with a prescribed authorized turn, ID UNKNOWN. Retain frozen 66/17/49, debt 1, CP2 491/491, R3 403/497, selector 497.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | Independent TB11 Review + Plan (ID `UNKNOWN`) | Review two common route-anchor semantic regressions; no unreviewed implementation. |
| 2 — conditional | Remediation (ID `UNKNOWN`) | Only if independently authorized with concrete causal proof. |
| 3 — held | `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | Only after reviewed GREEN U1 predecessor. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **independent review-plan** — use TB11 immutable evidence and CB11 source; CB12 unauthorized.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB11_Open_Rail_Route_Anchor_Harvest_Report_20261018.md`, CB11 code/build record, RA-84 Review, R10B rule §3, frozen definitions and required policies.
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
