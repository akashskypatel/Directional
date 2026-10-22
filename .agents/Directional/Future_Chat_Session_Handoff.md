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
| Currency | 2026-10-22: RA-133 independently reviewed TB28: **462/497 PASS**, 35 inherited RED, 13 RED→PASS and **0 PASS→RED** vs TB21. Candidate only; successor CB27 A7 test negatives authorized, no promoted CP3 acceptance. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/open. Exact CB26 semantic source **`e3d60337ed34538547d3a6d519bafae5b184330e`**, compiled package `12409939859`; later control/document/tooling commits do not replace semantic source. Refresh current branch HEAD before mutation. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, semantic `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 **403/497** rejected. |
| Latest candidate evidence | RA-133-reviewed TB28 [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result artifact **`12424484672`**, ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`; 1019/1019 manifest, 497/497 executed, **462 PASS/35 RED**, 13 RED→PASS and no PASS→RED vs TB21 449/48. Owning report `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md`; TSV inventory and full ledger. **Not promoted.** |
| Regression accounting and debt | **66 events / 17 categories / 49 recurrences**, witness debt **1**, selector **497 frozen**, TB28 candidate 462/497, RP-01 OPEN. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | All 12 seam-family cases and selector:447 PASS at TB28, but 35 inherited RED remain. A7 `cross-sheet:seam-direction`, `cross-sheet:no-certificate`, `cross-sheet:periodic`, B4 precision and RA-127.4b tests still unproven (RA-132.6). M1 and D2 and fixture debt require independent classification. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES` — EXACT NEXT

- **Type:** Code + Build, test-only, GMP/GMPXX eight-target compile; no runtime. Authorization RA-133 in `Architecture_M6_CP3_TB28_Selector_497_Census_Review_Decision_20261022.md`, implementing RA-132.6 from `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md`.
- **Only file:** `tests/SurfaceCellTransitionQuotientTests.cpp`. Preserve all source/header/fixtures/selector/harness/workflow paths. Five D7/A7 tamper negatives (unrelated seam, missing cert, lattice-coordinate mismatch, outside wedge, same-side only if reachable), assert actual A7 site and A6 disposition, keep D3/D7 positives. Compiled package review next, runtime separately in TB29.
- **STOP/falsifiers:** inability to construct each intended witness, earlier unrelated rejection, positive control change, unexpected rejection site, assertion weakening, unauthorized production changes.
- **Frozen:** last accepted CP2 491/491, R3 rejected 403/497, TB28 candidate 462/497, stable 66/17/49 debt1, selector497, RP-01 OPEN, RP-02 UNREACHED, Gate C suspended.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB27-RP01-A7-CERTIFIED-SEAM-NEGATIVE-ORACLES` | Test-only A7 negative oracles; compile-only. |
| 2 — conditional | `UNKNOWN` (CB27-REV then TB29) | Separate independent Review must first accept compiled test-only change and specify exact successor. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — implement RA-133-authorized CB27 test-only A7 negative oracles, compile-only, no runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB28_Selector_497_Census_Review_Decision_20261022.md` (RA-133), `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md` §RA-132.6 (five falsifiers); TQ D7 fixture and A7 typed seam rule.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats.

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
