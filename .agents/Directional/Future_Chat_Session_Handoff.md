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
| Currency | 2026-10-21, after CB22A Review (RA-119). CB22A compiled GREEN (harvested by Review) and CB22+CB22A are accepted statically: the A5 isolation site diagnostic compiles and changes no decision. Design finding: the site reaches only rows that print the pipeline failure string; five A5-ISO rows, including G4-B002 `focused30:28`, call A5 directly or assert without a message. Next: CB22B routes the site into those test messages (test-only), then TB23. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB22A `f082d9aebce0ad72906ccbf70c37a4bf90a9ae6f`; HEAD `src`, `include` and `tests` are identical to it. Last compiled: CB22A package `12333216637` (ZIP `ecde5067…4066`, 28/28, GMP/GMPXX, `runtimeExecution=false`), expires 2026-10-28T09:05:23Z; accepted statically by RA-119; not yet executed. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB22: run [39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), result `12323004201` (ZIP `71569a41…8c87`), expires 2026-11-04T05:31:17Z; 11/11 executed, 4 PASS / 7 RED; report `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`, reviewed by RA-117 (`Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`). Census: TB21 result `12317287104`, **449/497**, 0 PASS→RED (RA-115); baseline `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`. **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. Owned CP2 families: **A5-ISO** (torus A5 `MismatchedIsolationEvidence`, ≥ 8 rows incl. G4-B002 `focused30:28`; branch unknown until TB23 prints the site; RA-117.3, RA-119.3); **F** (torus witness fixture lacks `fieldTransportAtlas`, 2 rows; fixed in source, unverified at runtime); **M1** (10 rows plus `focused30:12`, `cp3entry:2`, DEFN-M1). CP3-entry: D2 for `cp3entry:1` (DEFN-T1). Restriction: CB22B edits TQ messages only; no assertion, fixture or production change. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` — EXACT NEXT

- **Type / owner:** Code + Build; implementation agent. Authority: RA-119.4 (`Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md`).
- **Objective:** make the A5 isolation site visible in the five A5-ISO rows that call A5 directly or assert without a message, by changing test failure messages only.
- **Read before work:**
  - RA-119 (§3, §4, §5);
  - `tests/SurfaceCellTransitionQuotientTests.cpp` (TQ) at `f082d9aeb`: `retained_pipeline_first_failure` TQ:461–473; `build_torus_closed_complex_view` TQ:960–1000; TQ:6008 (`focused30:24`), TQ:6193 (`focused30:25`), TQ:6472–6484 (`focused30:26`), TQ:6544–6556 (`focused30:27`);
  - `include/directional/pipeline/RemeshPipeline.h:963–971` (`SurfaceOccurrenceComplexError`) and :1015–1018 (`ConstructionResult`);
  - `LESSONS.md` §5 and §7.
- **In scope (TQ only, base `f082d9aeb`):**
  1. **Helper.** Immediately before TQ:960 add `std::string a5_rejection_message(const directional::pipeline::SurfaceOccurrenceComplexProducer::ConstructionResult &construction)`: `A5:unexpected-disposition` when there is no error; otherwise `A5:<surface_occurrence_complex_error_name(code)>`, plus `;site=<isolationSite>` when non-empty.
  2. **TQ:973–978:** `*firstFailure = a5_rejection_message(a5);`.
  3. **TQ:6008:** `ASSERT_NE(a5, nullptr) << a5_rejection_message(a5Construction);`.
  4. **TQ:6193:** append `<< retained_pipeline_first_failure(run)`.
  5. **TQ:6475–6483 and TQ:6547–6555:** stream `"torus downstream first rejection=" << a5_rejection_message(a5Construction)`; delete the now-unused `a5Error` declarations.
  6. **Compile.** GMP/GMPXX, eight targets, package, `runtimeExecution=false`.
  7. **Record.** `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Code_Build_Record_20261021.md`, at most 30 lines: source SHA; TQ diff stat and changed ranges against `f082d9aeb`; compile run, package id, ZIP SHA-256, hash count, expiry, root-manifest and source-archive SHA-256.
- **Out of scope:**
  - RP, the header and every file other than TQ, which stay byte-identical to `f082d9aeb`;
  - any assertion condition, fixture, selection or control-flow change; any other test's messages;
  - any A5-ISO repair; selectors, harnesses, workflows; runtime; DEFN-M1 and DEFN-T1.
- **Success evidence:**
  - the diff touches only the helper and the five listed TQ sites; existing message text is unchanged except the `;site=` suffix; no line over 100 columns;
  - the compile is GREEN;
  - the package is verified: hashes, clean statuses, `runtimeExecution=false`;
  - the record is committed and STATUS is COMPLETE.

  If the compile is still running at your closeout bound, leave STATUS `IN_PROGRESS`; Review harvests.
- **On success:** `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-REV` (Review, mandatory). It verifies the diff and package and issues the TB23 plan (RA-119.5 frame).
- **On failure/blocker:** STOP and return to Review on:
  - any compile error;
  - any need to edit outside TQ or to change an assertion.

  There is no repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE` | Compile RED; reviewed by RA-118: diagnostic accepted statically. |
| done | `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER` | Compile GREEN (package `12333216637`), harvested and accepted statically by RA-119. |
| 1 — next | `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` | Code + Build per RA-119.4: route the site into five A5-ISO test messages; TQ only; compile only. |
| 2 — mandatory | `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-REV` | Review: verifies the diff and package; issues the TB23 plan (RA-119.5). |
| planned, not authorized | TB23 (torus A5 site harvest: A5-ISO `focused30:20/24/25/26/27/28`, `selector:444/446/448`; F `focused30:6`, `selector:447`; controls `cp3entry:6`, `selector:217`, TB18 A#14, `selector:443`, `focused30:7`) → TB23-REV → DEFN-ISO (A4 seam certificate ↔ A5 binding contract; the `8be01326d` reject) → corrective CB/TB → DEFN-M1 (RA-105.3; also `focused30:12`, `cp3entry:2`) → corrective CB/TB → DEFN-T1 (D2 attainability) → fixture debt → census → RP-01 Review | Only as each Review assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB22B: route the A5 isolation site into five torus test failure messages (RA-119.4); TQ only; compile only, no runtime.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md` (RA-119, the CB22B specification and the TB23 frame); `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Compile_Stop_Review_Decision.md` (RA-118, the CB22 diagnostic); `LESSONS.md` §§5, 7.
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
