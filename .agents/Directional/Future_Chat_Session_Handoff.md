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
| Currency | 2026-10-21, after CB22 compile-stop Review (RA-118). CB22 (`384961bb4`) failed to compile on one wrong identity projection (`OccurrenceId` has no `index()`, RP:5274–5275); its diagnostic is otherwise accepted statically: every site prints exactly what the decision read and no A5 decision changes. Next: CB22A corrects the formatter and removes a canonical/storage name shadow, compile only. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB22 `384961bb4ac292e99bf41681117bf8d1d4e9d520` (uncompiled: run [39564087707](https://github.com/akashskypatel/Directional/actions/runs/39564087707) RED, no package); HEAD `src`, `include` and `tests` are identical to it. Last compiled: CB21 package `12318897957` (ZIP `f0ae4338…c606`, 28/28, GMP/GMPXX, `runtimeExecution=false`), expires 2026-10-28T03:54:02Z; accepted statically by RA-116, at runtime for its scope by RA-117.2. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB22: run [39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), result `12323004201` (ZIP `71569a41…8c87`), expires 2026-11-04T05:31:17Z; 11/11 executed, 4 PASS / 7 RED; report `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`, reviewed by RA-117 (`Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`). Census: TB21 result `12317287104`, **449/497**, 0 PASS→RED (RA-115); baseline `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`. **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. Owned CP2 families: **A5-ISO** (torus A5 `MismatchedIsolationEvidence`, ≥ 8 rows incl. G4-B002 `focused30:28`; branch unknown until TB23 prints the site; RA-117.3); **F** (torus witness fixture lacks `fieldTransportAtlas`, 2 rows; fixed in CB22 source, unverified at runtime); **M1** (10 rows plus `focused30:12`, `cp3entry:2`, DEFN-M1). CP3-entry: D2 for `cp3entry:1` (DEFN-T1). Restriction: CB22A edits RP:5264–5337 only and may not change any A5 decision. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER` — EXACT NEXT

- **Type / owner:** Code + Build; implementation agent. Authority: RA-118.5 (`Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md`).
- **Objective:** make the CB22 diagnostic compile by printing each relation endpoint through its real identity (cell, corner role), and remove the canonical/storage name shadow in the same block. No other change.
- **Read before work:**
  - RA-118 (§3, §4, §5); the CB22 stop record `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Stop_Record_20261021.md`;
  - `include/directional/authority/AuthorityIds.h:250–289` (`OccurrenceId`); the formatter idiom at TQ:3454–3468;
  - `src/pipeline/RemeshPipeline.cpp` (RP) at `384961bb4`: the relation reject RP:5249–5339, and the outer storage-order names RP:5193 and RP:5208–5212;
  - `LESSONS.md` §5 and §7.
- **In scope (RP only, base `384961bb4`):**
  1. **Formatter.** On RP:5274–5275, print each endpoint as `<id.cell().index()>:<static_cast<int>(id.canonical_corner_role())>`, giving `;relation=<c>:<k>,<c>:<k>`.
  2. **Names.** Within RP:5264–5337 only, rename `firstSpan`, `secondSpan`, `firstOccurrence` and `secondOccurrence` to `canonicalFirstSpan`, `canonicalSecondSpan`, `canonicalFirstOccurrence` and `canonicalSecondOccurrence`.
  3. **Compile.** The CB22 procedure: GMP/GMPXX, eight targets, package, `runtimeExecution=false`.
  4. **Record.** `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Code_Build_Record_20261021.md`, at most 30 lines: source SHA; RP diff stat and changed line range against `384961bb4`; cumulative per-file stat against `49c982195`; compile run, package id, ZIP SHA-256, hash count, expiry, root-manifest and source-archive SHA-256.
- **Out of scope:**
  - the header, TQ and every file other than RP, which stay byte-identical to `384961bb4`;
  - any RP edit outside RP:5264–5337; any A5 predicate, ordering, error code or return change;
  - refactoring `certified_seam_direction` or the clause classifier; any A5-ISO repair; selectors, harnesses, workflows; runtime; DEFN-M1 and DEFN-T1.
- **Success evidence:**
  - the diff against `384961bb4` touches only RP:5264–5337, with no line longer than 100 columns;
  - the compile is GREEN, including TQ, which compiles for the first time with the CB22 atlas line;
  - the package is verified: hashes, clean statuses, `runtimeExecution=false`;
  - the record is committed and STATUS is COMPLETE.

  If the compile is still running at your closeout bound, leave STATUS `IN_PROGRESS`; Review harvests.
- **On success:** `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER-REV` (Review, mandatory). It verifies the CB22A diff and package, and issues the TB23 plan with the RA-118.6 rows and predictions and the package identity.
- **On failure/blocker:** STOP and return to Review on:
  - any compile error, in RP, TQ or elsewhere;
  - any need to edit outside RP:5264–5337 or to change an A5 decision.

  There is no repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE` | Compile RED at RP:5274–5275; stopped. Reviewed by RA-118: diagnostic accepted statically. |
| 1 — next | `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER` | Code + Build per RA-118.5: `OccurrenceId` formatter and four renames in RP:5264–5337; compile only. |
| 2 — mandatory | `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER-REV` | Review: verifies the diff and package; issues the TB23 plan (RA-118.6). |
| planned, not authorized | TB23 (torus A5 site harvest: A5-ISO `focused30:20/24/25/26/27/28`, `selector:444/446/448`; F `focused30:6`, `selector:447`; controls `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`) → TB23-REV → DEFN-ISO (A4 seam certificate ↔ A5 binding contract; the `8be01326d` reject) → corrective CB/TB → DEFN-M1 (RA-105.3; also `focused30:12`, `cp3entry:2`) → corrective CB/TB → DEFN-T1 (D2 attainability) → fixture debt → census → RP-01 Review | Only as each Review assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB22A: `OccurrenceId` formatter and canonical renames in RP:5264–5337 (RA-118.5); compile only, no runtime.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md` (RA-118, the CB22A specification and the TB23 frame); `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Stop_Record_20261021.md`; `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md` (RA-117, the CB22 scope); `LESSONS.md` §§5, 7.
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
