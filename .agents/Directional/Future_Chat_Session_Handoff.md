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
| Currency | 2026-10-21, after CB22B test-only message routing compiled GREEN; independent CB22B Review is next. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB22B semantic source `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`, later control/documentation heads must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB22: run [39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), result `12323004201` (ZIP `71569a41…8c87`), expires 2026-11-04T05:31:17Z; 11/11 executed, 4 PASS / 7 RED; report `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`, reviewed by RA-117 (`Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`). Census: TB21 result `12317287104`, **449/497**, 0 PASS→RED (RA-115); baseline `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`. **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open; A5-ISO/F/M1 and D2 ownership as RA-119.3, unchanged. CB22B messages compiled only; independent Review must verify diff and package before authorizing TB23. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-REV` — EXACT NEXT

- **Type/owner:** Independent Review, authorized by RA-119.4 and the completed CB22B code-build. This is a separate turn.
- **Objective:** Verify the exact TQ-only +22/−24 diagnostic-message diff and immutable eight-target GMP/GMPXX compile package; issue the TB23 plan using RA-119.5 only if review accepts.
- **Read first:** RA-119 (`Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md`), `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md`, packaged result `12341307713`, `LESSONS.md`, frozen regression ledger.
- **In scope:** Verify unchanged assertions/fixtures/selector/control flow, site suffix formatting, exactly one test-source path, no added line over 100 columns; 28/28 hashes, exact source, eight targets, clean statuses, GMP/GMPXX, `runtimeExecution=false`.
- **Out of scope:** No source repairs, runtime, TB23 execution, selector changes or acceptance promotion during the Review.
- **Success evidence:** Frozen Review decision, precise verdict, TB23 artifact-only plan keyed to RA-119.5's 16 rows and falsifiers.
- **On success:** TB23 only if independently authorized by that Review; otherwise `UNKNOWN` and STOP. On failure: STOP and issue bounded corrective authority, never silently change the test or runtime boundary.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE` | Compile RED; reviewed by RA-118: diagnostic accepted statically. |
| done | `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER` | Compile GREEN (package `12333216637`), harvested and accepted statically by RA-119. |
| done | `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` (attempt 1) | Yielded `IN_PROGRESS` after a source snapshot; no source change. |
| done | `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-YIELD-REV` | Review: RA-119.4 anchors re-verified at HEAD; specification unchanged; CB22B re-entered as a new turn. |
| 1 — next | `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` | Code + Build per RA-119.4, new turn: route the site into five A5-ISO test messages; TQ only; compile only. |
| 2 — conditional | TB23 (exact ID only when Review grants authority) | Artifact-only, separate turn; no runtime here. |
| planned, not authorized | TB23 (torus A5 site harvest: A5-ISO `focused30:20/24/25/26/27/28`, `selector:444/446/448`; F `focused30:6`, `selector:447`; controls `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`) → TB23-REV → DEFN-ISO (A4 seam certificate ↔ A5 binding contract; the `8be01326d` reject) → corrective CB/TB → DEFN-M1 (RA-105.3; also `focused30:12`, `cp3entry:2`) → corrective CB/TB → DEFN-T1 (D2 attainability) → fixture debt → census → RP-01 Review | Only as each Review assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — CB22B independent code-build review; verify TQ-only scope and compile-only package, then decide TB23 authority.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md` (RA-119), `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md`, package `12341307713`; `LESSONS.md` §§5, 7.
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
