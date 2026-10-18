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
| Currency | 2026-10-18, after `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE`; independent Review next. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. CB12 semantic source `b1b02d5bed43898af0708d76dcd70ada96aeecc9`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. |
| Latest candidate or rejected evidence | TB12 [run 39103358061](https://github.com/akashskypatel/Directional/actions/runs/39103358061), result `12127706461`, ZIP SHA-256 `1b6c3babd942cfc7fc7bbeff94774bf719297fdb9bc7ca3c0088e40110f2dfee`, CB12 package `12125223513`. **6/6 selected; two gates PASS, four existing RP-01 diagnostics RED; immutable postflight.** `Architecture_M6_CP3_TB12_Open_Rail_Chain_Provenance_Harvest_Report_20261018.md`. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. No TB12 stable-regression promotion. |
| Active boundary | `RP-01` open: #3/#4 byte-identical TB11 open-rail route-anchor rejection at front 29/147; #5/#6 `endpoint-1` rejection before CB12 product publication. U3–U5 (CB13–CB15) remain conditional on Review. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV` — EXACT NEXT

- **Type / owner:** independent `REV` after TB12, authorized by RA-86.4.
- **Objective:** independently adjudicate all six TB12 measurements against RA-86.4, including reachability, prediction non-vacuity, and the precise scope of CB12 validation; issue or amend the CB13 specification only after Review.
- **Read before work:** RA-86 decision; TB12 owning report and raw immutable result artifact; TB11 report; CB12 record; `Architecture_M6_Frozen_Definitions.md`, `Regression_Root_Cause_Tracker.md`.
- **In scope:** re-derive observed predicates and ledger; examine #3/#4 exact TB11 equivalence and #5/#6 `firstPredicate=`; classify stable versus non-stable evidence; decide the U3 constraints under RA-86.5, and carry any unresolved witnesses.
- **Out of scope:** code, tests, source, harness, selector, compile, benchmark, unreviewed CB13 work, or fabricated direct-production success.
- **Success evidence:** independent Review decision and non-vacuity assessment; corrected/frozen CB13 authority if justified; tracker and handoff updated with exact next turn.
- **On any measured outcome:** CB13 may follow only after a completed Review that explicitly authorizes it; do not begin CB13 from this TB12 turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---| 
| 1 — next | `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV` | Review TB12 artifact and RA-86 predictions. |
| 2 — conditional | `UNKNOWN` (CB13) | Canonical ID and exact allowed scope require the next independent Review; do not start before an explicitly reviewed specification. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — independently examine TB12 raw evidence and RA-86.4 predictions; no code/build/test mutation.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB12_Harness_Authority_Review_Decision.md` (RA-86), `Architecture_M6_CP3_TB12_Open_Rail_Chain_Provenance_Harvest_Report_20261018.md` and its raw result artifact, the TB11 report, CB12 record, and `Architecture_M6_Frozen_Definitions.md` RA-85/RA-86.
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
