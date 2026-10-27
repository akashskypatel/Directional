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
| Currency | 2026-10-27 TB46A harness-only fix compiled (source `5e6de03f`, [compile record](Architecture_M6_CP3_TB46A_Orchestration_Correction_Compile_Record_20261027.md)); **fixture Review prerequisite** blocks TB46 re-execution. Original TB46 S5 remains invalid, no semantic promotion. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491**, accepted 2026-10-06. Nothing newer accepted; selector497 unpromoted. |
| Exact attempted evidence | CB46 semantic `c05d52dd7...`, package `12708707491`; full gate [run 40448739180](https://github.com/akashskypatel/Directional/actions/runs/40448739180), job `122006250303`, result `12711165610` (ZIP SHA-256 `158b8d25...9ed1`), harness log `12711016096`, reusable log `12711205512`. 504/504 raw processes and clean immutable postflight, 497 PASS / 7 RED, 2 POSITIVE controls failed; harness exit90. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, [tracker](Regression_Root_Cause_Tracker.md). TB46 raw ledger retained as S5 invalid-attempt provenance; no stable event. |
| Active boundary | RP-01 open. Five REDs remain pinned (`focused30:12`, `selector:201`, `selector:442`, `cp3entry:1`, `cp3entry:2`). Cluster E D1/D2 and G D3 messages harvested. POSITIVE 174: uncaught DCEL exception `unknown file` (not localized to later site); POSITIVE cp3entry:4: later failure `ordinaryCarrier` at `:4063`. RA-164.5 later-failure allowance is now source-location-gated in the harness; 174 remains early/unattributed and requires independent fixture Review. |

## Current canonical turn — `M6-CP3-TB46A-ORCH` (Code + Build; Review prerequisite unresolved)

- **Implemented:** harness-only first-failure classification, source `5e6de03fadd88cc4f9bbe749b32ea012264fe73e`; independently verified **eight-target compile-only** [run 40457083585](https://github.com/akashskypatel/Directional/actions/runs/40457083585), package `12712389032`, GMP/GMPXX, `runtimeExecution=false`, 28/28 internal checksums. [Record](Architecture_M6_CP3_TB46A_Orchestration_Correction_Compile_Record_20261027.md). Preserve original CB46 semantic package `12708707491`, manifest `717f4f0f…6bb087` and TB46 attempt run `40448739180` as nonaccepted evidence.
- **Remaining review prerequisite:** POSITIVE `selector:174` has an apparent *earlier* unguarded exception because `manifoldHardSource.set_mesh` receives an isolated fifth vertex at `SurfaceCellREPackageTests.cpp:439`; the failing raw GTest log is `unknown file` and cannot be admitted as a source-located later assertion. Correcting that fixture is **outside** this orchestration-only CB scope; independent Review must approve exact preconditions and a separate fix. Do not rerun TB46 merely to get the predictable S5 result, and do not weaken the harness or test.
- **Conditional next full gate:** `M6-CP3-TB46-RP01-FULL-GATE` remains frozen, but must not be entered until the Review prerequisite is resolved under the turn-cadence authority. No invented successor or permission to edit the frozen 504-case manifest. Stable 66/17/49, debt1, CP2 accepted 491/491, CP3/selector497 unpromoted.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB46 | 8 GMP/GMPXX targets, `runtimeExecution=false`. |
| done with S5 stop | `M6-CP3-TB46-RP01-FULL-GATE` (attempt 1) | 504/504, 497/7, harness control contract failure; not accepted. |
| active, review-gated | `M6-CP3-TB46A-ORCH` (Code + Build) | Harness corrected and compiled; separate 174 fixture Review prerequisite blocks proceeding. |
| conditional | `M6-CP3-TB46-RP01-FULL-GATE` (re-execute) | Held for independent disposition of 174 and valid subsequent build/package authority. |
| gated | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review) → CB47 → TB47 | Only after valid TB46; E: 201, cp3entry:2. |
| later | `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review) → CB48 → TB48 | G: 442, focused30:12, cp3entry:1. |
| later | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review) → CB49 → TB49 | O4/O5, P1-a/P1-b, RA-162 C1, A5 reachability. |
| after green gate | RP-01 Review | Own O6 nonrectangular disk scope. |
| post-RP-01 | O2/T2 DEFN, then DIAG-RETAIN | Preserve original deferred constraints. |
| carried | O1, O6, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **`M6-CP3-TB46A-ORCH`** (review-gated current turn) — Read [TB46A compile record](Architecture_M6_CP3_TB46A_Orchestration_Correction_Compile_Record_20261027.md), then independently resolve selector174's manifold fixture precondition before any fixture mutation or frozen TB46 rerun. Harness committed `5e6de03f`, compile source/package same SHA / `12712389032`; original CB46 semantic package `12708707491` and original TB46 raw evidence remain immutable. Current STATUS reflects review prerequisite; do not enter conditional successor while that prerequisite is unresolved.

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
