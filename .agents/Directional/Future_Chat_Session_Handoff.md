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
| Currency | 2026-10-21, CB21 Code + Build compiled GREEN on exact source `8453e19e6ac7d976a9cac45978ad31104a52f034`; 28/28 package checksums, GMP/GMPXX eight targets, runtime-free. Next: mandatory independent CB21-REV; TB22 not yet authorized. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source `8453e19e6ac7d976a9cac45978ad31104a52f034` (TQ only); HEAD will include nonsemantic evidence/closeout commits. |
| Last compiled semantic source | CB21 GMP/GMPXX eight-target compile [39540888446](https://github.com/akashskypatel/Directional/actions/runs/39540888446), package `12318897957`, ZIP SHA-256 `f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`; 28/28, statuses clean, `runtimeExecution=false`, expires 2026-10-28T03:54:02Z. Source archive `63b260ac…c98520`, root SHA256SUMS `4726b882…1bc0`; owning `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Code_Build_Record_20261021.md`. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate / rejected evidence | TB21: run [39533914719](https://github.com/akashskypatel/Directional/actions/runs/39533914719), result `12317287104` (ZIP `12279a26…9c8d`), expires 2026-11-04T02:46:55Z; 497/497 executed, 449 PASS / 48 RED, 0 PASS→RED; verified harvest in `Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md` (RA-115.1); census baseline `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv` (`6eb5022a…7c34`). TB20: run `39527537505`, result `12314700010`, expires 2026-11-04; 26 rows; RA-114.1. TB19A `12292268624` and TB19 `12285225197` (expire 2026-11-03): pin-site harvests accepted by RA-110/RA-109. TB18 Part A `12231529583` and Part B `12232299548` (448/497), expire 2026-11-03; superseded as candidate evidence by TB21. |
| Regression accounting | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 **449/497** (was TB18 448/497). |
| Active boundary | `RP-01` open. CB20/CB20A is regression-free on the 497 selector (RA-115.2). M2 residue: six torus rows fail at the D2 odd-gauge selection inherited from the shared fixture (RA-115.3; test-scope defect, CB21); `cp3entry:1` alone requires D2, and D2's attainability on this torus goes to DEFN-T1 after TB22; `cp3entry:2` and `focused30:12` go to the M1 DEFN. M1 (10 identities, RA-105.3) unchanged. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE-REV` — EXACT NEXT

- **Type / owner:** independent Review (planning-only). Authority RA-115.5 and verified CB21 record.
- **Immutable source:** `8453e19e6ac7d976a9cac45978ad31104a52f034`. Compile run `39540888446`, package `12318897957`, SHA-256 `f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`; runtime-free, GMP/GMPXX, hashes 28/28. PR #8 remains draft/open.
- **Read:** RA-115 sections 3 and 5; D2 definition/review; CB21 code/build record; exact CB21 diff and `LESSONS.md` §2.
- **Review:** independently verify that only TQ struct member, candidate selection/predicate census, receipt, return and `cp3entry:1` assertion stream changed. Every candidate must be evaluated; reciprocal/holonomy conditions unchanged; D2 assertion must remain; no source/include/other test edits. Correct any missing evidence or handoff issues only under Review permissions; do not execute tests or change test logic.
- **TB22 plan/predictions:** seven torus consumers, `cp3entry:6`, three controls; five CP2 rows should pass the fixture, `cp3entry:1` may fail at its own D2 assertion with receipt, `focused30:12` unchanged; falsifier if fixture throws with `reciprocalTracerPairs=0` or `holonomyMatchedPairs=0`. Do not promote unexecuted predictions or authorize TB22 until Review resolves the static gate.
- **On review success:** set exact TB22 scope, immutability, and handoff; respect next turn boundary. On defect: record actionable findings, assign corrective Code + Build, no implementation inside Review.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE-REV` | Review: static diff and evidence check; TB22 rows and predictions. |
| planned, not authorized | TB22 (the seven torus consumers, `cp3entry:6`, three controls) → TB22-REV → DEFN-T1 (D2 attainability on the torus under RA-111.3, from the TB22 receipt) → DEFN-M1 (M1 binding owner, RA-105.3; also `cp3entry:2`, `focused30:12`) → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as each Review assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — CB21 independent static diff and evidence check; TB22 remains not yet authorized.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md` (RA-115); D2 in `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md` and `Architecture_M6_DEFN_R5_R2_Review_Record.md`; `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Code_Build_Record_20261021.md`; `LESSONS.md` §§2, 7.
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
