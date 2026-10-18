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
| Currency | 2026-10-18, after `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` (artifact-only; 1 PASS / 5 RED) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. CB13 semantic source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`; TB13 executor `157145f3e2f1cf5a500dfb8d8b2bc2ce3fdd9272`; refetch HEAD before mutation. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, result `11661044443`, 403/497). |
| Latest candidate or rejected evidence | TB13 [run 39112131501](https://github.com/akashskypatel/Directional/actions/runs/39112131501), result `12130683535`, ZIP SHA-256 `43505af2912b840262307db96865c5e7f9e2af8ca3b9cbe5426f0b18e87f4885`: six selected, 1 PASS / 5 RED, postflight immutable; required reversed-route truth table RED, P10 cases move to B2, full-pipeline B3 unchanged. CB13 source/package above remains compile-valid, not runtime accepted. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` has three blocker shapes (RA-87.3): B1 I–I anchor → U3 P10 cases advance, but new bidirectional truth-table gate fails; B2 rail-interior vertex → U4/U5; B3 inexact I parameter → U6 (DEFN first). Independent Review required before TB13C. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — UNKNOWN (independent TB13 gate Review required)

- **Owner:** independent Review + Plan. The TB13 artifact harvest finished, but the required `OpenRailRouteChainIntervalTruthTable` was RED: reverse path `[4–7,1–4]` was accepted, even though the RA-87.4 negative test expects rejection; RA-87.4's bidirectional matching formula permits reverse traversal. Review must adjudicate the semantic contract rather than weaken the test to obtain green. Exact Review ID is **UNKNOWN**; do not invent one.
- **Evidence:** semantic CB13 source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`, compile artifact `12130290543`, TB13 [run 39112131501](https://github.com/akashskypatel/Directional/actions/runs/39112131501), result `12130683535` ZIP SHA-256 `43505af2912b840262307db96865c5e7f9e2af8ca3b9cbe5426f0b18e87f4885`. Six exact selected: 1 PASS / 5 RED, no missing, postflight immutable, no compilation or selector497.
- **Measurements:** focused chain-provenance gate PASS; P10 #3/#4 move from front 29/147 route anchor to front 61/179 `endpoint-1` (B2 at vertex 4); full-pipeline #5/#6 keep byte-identical TB12 raw 9,180-character `endpoint-1` lines (B3). No `Produced` fixture success or promotion.
- **Stop gate:** conditional `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS`, U4/U5/U6, and any source/test corrections remain HELD until Review assigns authority. Report: `Architecture_M6_CP3_TB13_Open_Rail_Chain_Interval_Harvest_Report_20261018.md`.

## Turn Sequence

| Step | Canonical turn | Condition |
|---|---|---|
| 1 — completed | `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` | Compile-only U3. |
| 2 — completed; required gate RED | `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` | Immutable 1 PASS / 5 RED. |
| 3 — next, ID UNKNOWN | Independent TB13 gate Review | Reconcile bidirectional interval specification and contradictory negative test row. |
| 4 — conditional, HELD | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` | Only after Review authority. |
| 5 — conditional, HELD | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV` | Interpret census; order U4/U5/U6. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review-plan** — evaluate TB13 required truth-table gate contradiction; no code, test, or selector alteration without independent authority.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB13_Open_Rail_Chain_Interval_Harvest_Report_20261018.md` (TB13 evidence), `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md` (RA-87.4 specification), `Architecture_M6_CP3_TB12_Open_Rail_Chain_Provenance_Harvest_Report_20261018.md` (B3 baseline), `Architecture_M6_Frozen_Definitions.md`, `GMP_COMPILE_POLICY.md`.
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
