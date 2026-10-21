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
| Currency | 2026-10-21, after CB22B Review (RA-120). CB22B compiled GREEN and is accepted statically: the A5 isolation site now reaches all nine A5-ISO rows (five through the pipeline failure string, four through the CB22B test messages), including G4-B002 `focused30:28`. CB22 + CB22A + CB22B are one statically accepted diagnostic unit, not yet executed. Next: TB23 runs the sixteen-row site harvest from the immutable package. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB22B `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`; HEAD `src`, `include` and `tests` are identical to it. Package for TB23: CB22B artifact `12341307713` (ZIP `b5f9a668…8ad5`, 28/28, GMP/GMPXX, `runtimeExecution=false`), expires 2026-10-28T11:21:37Z; accepted statically by RA-120; not yet executed. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB22: run [39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), result `12323004201` (ZIP `71569a41…8c87`), expires 2026-11-04T05:31:17Z; 11/11 executed, 4 PASS / 7 RED; report `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`, reviewed by RA-117 (`Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`). Census: TB21 result `12317287104`, **449/497**, 0 PASS→RED (RA-115); baseline `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`. **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. Owned CP2 families: **A5-ISO** (torus A5 isolation rejection, 9 rows incl. G4-B002 `focused30:28`; branch unknown until TB23 prints the site; RA-117.3, RA-120); **F** (torus witness fixture lacks `fieldTransportAtlas`, 2 rows; fixed in source, first executed in TB23); **M1** (10 rows plus `focused30:12`, `cp3entry:2`, DEFN-M1). CP3-entry: D2 for `cp3entry:1` (DEFN-T1). Restriction: TB23 is artifact-only; no rebuild, test, fixture, selector or source edit. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST` — EXACT NEXT

- **Type / owner:** Test + Benchmark, artifact-only; implementation agent. Authority: RA-120.4 (`Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md`); plan `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`.
- **Objective:** execute the sixteen TB23 rows from the immutable CB22B package and record the A5 isolation site for every A5-ISO row.
- **Read before work:**
  - the TB23 plan (all of it) and RA-120;
  - RA-117.3 (H-ISO-1/2/3) and RA-119.5;
  - the TB22 harness `.agents/Directional/tools/m6_cp3_tb22_torus_witness_harvest_harness.sh` and the TB22 report;
  - `LESSONS.md` §§1, 5, 7.
- **In scope:**
  1. **Harness.** `.agents/Directional/tools/m6_cp3_tb23_torus_a5_site_harvest_harness.sh`, derived from TB22's. Change only the package/source identities, the sixteen rows and the plan's added ledger columns (`fixture`, `path`, `a5_failures`, `site_raw`, parsed `label`, `region`, `seam`, `cert` or `certs` + `certN` clauses).
  2. **Integrity.** Verify package `12341307713`: ZIP `b5f9a6688226375ea1c6241c2d9a464d9b9ede7679f9259acd03b3fbbb1c8ad5`, root `SHA256SUMS` `7c396be6…7f11`, source archive `c3779cc9…cd75`. Check before execution and unchanged after.
  3. **Execute.** Use the durable `test_benchmark` dispatcher: one process per row, `GTEST_FAIL_IF_NO_TEST_SELECTED=1`, exactly one selected test per row, zero skips.
  4. **Report.** `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`, at most 40 lines: run, result artifact and ZIP SHA-256, harness SHA-256, integrity counts; one line per row (key, fixture, path, verdict, label, region, seam, cert or clauses); P1–P5 marked as observed.
- **Out of scope:**
  - rebuild, relink or benchmarks;
  - test, fixture, source, selector or workflow edits;
  - a broader census, a retry, any A5-ISO repair or root-cause verdict;
  - DEFN-ISO, DEFN-M1 and DEFN-T1.
- **Success evidence:**
  - 16/16 selected and executed, with no skips;
  - integrity holds before and after;
  - every A5-ISO row's site is recorded or its absence is classified;
  - the report is committed and STATUS is COMPLETE.

  A RED A5-ISO or F row is an expected observation, not a failure of the turn.
- **On success:** `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV` (Review, mandatory). It adjudicates P1–P5 and routes the family to DEFN-ISO under H-ISO-1, 2 or 3.
- **On failure/blocker:** STOP and return to Review on:
  - an isolation code without `site=`, a `valid` clause, or a label that contradicts its `a5-side`/`a5-wedge` suffix;
  - any control RED;
  - a package or source mismatch, `selected≠1`, a skip, a timeout or a runtime-flag mismatch.

  There is no repair or retry inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB22A-RP01-TORUS-A5-ISOLATION-SITE-FORMATTER` | Compile GREEN (package `12333216637`), accepted statically by RA-119. |
| done | `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES` | First attempt yielded with no source change (CB22B-YIELD-REV); re-entered; compile GREEN (package `12341307713`). |
| done | `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-REV` | RA-120: diff and package accepted statically; site reaches all nine A5-ISO rows; TB23 plan issued. |
| 1 — next | `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST` | Test + Benchmark, artifact-only, per `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`: sixteen rows; records the site of every A5-ISO row. |
| 2 — mandatory | `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV` | Review: adjudicates P1–P5; routes A5-ISO to DEFN-ISO under H-ISO-1/2/3; classifies the F rows. |
| planned, not authorized | DEFN-ISO (A4 seam certificate ↔ A5 binding contract; the `8be01326d` reject) → corrective CB/TB → DEFN-M1 (RA-105.3; also `focused30:12`, `cp3entry:2`) → corrective CB/TB → DEFN-T1 (D2 attainability) → fixture debt → census → RP-01 Review | Only as each Review assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — TB23: artifact-only sixteen-row torus A5 site harvest from CB22B package `12341307713` (RA-120.4; plan `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`).

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md` (the TB23 authority); `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md` (RA-120); `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md` (RA-117.3, H-ISO-1/2/3); the TB22 harness and report; `LESSONS.md` §§1, 5, 7.
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
