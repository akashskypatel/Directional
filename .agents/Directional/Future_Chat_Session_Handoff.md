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
| Currency | 2026-10-21, TB20 Review (RA-114). The corrected pin is confirmed at runtime on 26 rows: suite 3/3 and controls 3/3 PASS, no pin or factory rejection anywhere. M2 is cleared at the checked factory, and `cp3entry:6` now PASSES. Of the other eight M2 rows, six torus rows fail at a test-fixture odd-gauge filter (H-T1/H-T2, DEFN-T1) and two fail in the hard-rail certificate/A5 area. M1 is unchanged. Next: TB21 runs the selector-497 census on the CB20A package as the regression check. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source `e22c5da5f8ab86a39650c670340a658847a2ac7e`; HEAD `src`, `include` and `tests` are identical to it. |
| Last compiled semantic source | CB20A eight-target GMP/GMPXX compile [39520787768](https://github.com/akashskypatel/Directional/actions/runs/39520787768), package `12310848591`, ZIP SHA-256 `0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`; hashes `28/28`, statuses clean, `runtimeExecution=false`; **expires 2026-10-28T00:23:30Z**; accepted by RA-113. Record: `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md` (RA-113.1). |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate / rejected evidence | TB20: run [39527537505](https://github.com/akashskypatel/Directional/actions/runs/39527537505), result `12314700010` (ZIP `3731402f…787f`), expires 2026-11-04T01:35:20Z; 26/26 executed, 19 RED; verified harvest in `Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md` (RA-114.1). TB19A: run `39484475466`, artifact `12292268624` (ZIP `25d48ed7…7efa7c`), expires 2026-11-03; 7/7 selected, control `selector:443` PASS, 6 torus RED at `gauge-pin-consistency;edge=0,3`; report `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`, accepted by RA-110. TB19: run `39464430751`, artifact `12285225197` (ZIP `2b5dfacf…dec0`), expires 2026-11-03; 16 valid rows; report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`, accepted by RA-109. TB18 Part A `12231529583` (12/14) and Part B `12232299548` (448/497), expire 2026-11-03; candidate evidence per RA-105. First failures: `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`. |
| Regression accounting | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected, TB18 candidate 448/497. |
| Active boundary | `RP-01` open. M2's pin cause is fixed and confirmed at runtime (RA-114.2); the RA-103.5 R-route falsifier is not observed. M2 residue (RA-114.3): six torus rows at the fixture odd-gauge filter TQ:1697, added in `88aa8eae0` after CP2 (H-T1 test proxy vs H-T2 lost producer contract, for DEFN-T1); `cp3entry:2` and `focused30:12` in the hard-rail certificate/A5 area, for the M1 DEFN to classify. M1 (10 identities, RA-105.3) is unchanged. Regression safety beyond 26 rows awaits TB21. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS` — EXACT NEXT

- **Type / owner:** Test + Benchmark, artifact-only; implementation agent. Authority: RA-114.5 (`Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md`).
- **Objective:** run the selector-497 census on the CB20A package as the regression check for the corrected pin, and record the TB18→TB21 status changes.
- **Read before work:**
  - RA-114;
  - the TB18 report and `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv` (baseline and procedure);
  - the census harness `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh`.
- **In scope:**
  1. **Run.** The census harness, unchanged (SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`), with `--execute` and:
     - `CANDIDATE_ARTIFACT_ID=12310848591`;
     - `EXPECTED_SOURCE_SHA=e22c5da5f8ab86a39650c670340a658847a2ac7e`;
     - `EXPECTED_CANDIDATE_ZIP_SHA256=0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`;
     - `EXPECTED_ROOT_MANIFEST_SHA256=c735e5f76f84a887e0b5613bb65969a68cb4e10321d33a8113167e3978c8206b`;
     - `EXPECTED_SOURCE_ARCHIVE_SHA256=e231fcead36c5436719f13a87b249e2ff6bb69f54c3480fbecee2773d1878f57`.

     The package expires 2026-10-28T00:23:30Z.
  2. **Inventory.** `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`, one row per RED, with columns phase, ordinal, identity, owner, exit, raw_sha256, first_failure, TB18 status and TB18 first failure.
  3. **Report.** `Architecture_M6_CP3_TB21_Selector_497_Census_Report_20261021.md`, at most 30 lines:
     - the run, artifact and digest;
     - totals per phase;
     - the TB18→TB21 PASS→RED and RED→PASS lists by name;
     - the TSV's SHA-256.

     No interpretation.
- **Out of scope:**
  - any harness, source, test, selector or workflow change;
  - any repair;
  - accounting changes;
  - DEFN-T1 and the M1 DEFN.
- **Success evidence:**
  - the harness completes with verified digests;
  - 497 identities are accounted for;
  - the inventory and report are committed with their SHA-256s;
  - STATUS is COMPLETE in the same turn. Do not yield after dispatch.
- **On success:** `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS-REV` (Review, mandatory). It adjudicates the predictions:
  - 0 PASS→RED;
  - `cp3entry:6` RED→PASS;
  - at least 449 PASS;
  - no gauge-pin site on a hard edge, and no span site.
- **On failure/blocker:** STOP and return to Review on:
  - a harness orchestration failure or a digest mismatch;
  - any need to change the harness.

  There is no repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS` | Test + Benchmark, artifact-only, unchanged census harness on CB20A, per RA-114.5. Package expires 2026-10-28T00:23:30Z. |
| 2 — mandatory | `M6-CP3-TB21-RP01-SELECTOR-497-CENSUS-REV` | Review: regression verdict for CB20/CB20A; sets the next unit. |
| planned, not authorized | DEFN-T1 (source-only: the torus witness odd-gauge filter, CP2 `5ce3132ec` vs `88aa8eae0` vs HEAD; H-T1 vs H-T2) → DEFN on the M1 binding owner (RA-105.3), also classifying `cp3entry:2` and `focused30:12` → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as TB21-REV assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — TB21, artifact-only census (RA-114.5); never Code + Build.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Review_Decision.md` (RA-114, the TB21 specification); the TB18 census report and `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv` (baseline); `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md` (RA-113, package facts); `LESSONS.md` §§1, 7.
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
