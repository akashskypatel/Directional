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
| Currency | 2026-10-21, CB20A Review (RA-113). CB20 and CB20A are accepted as one compiled unit: the frozen pin domain (RA-111.4) is compiled and verified statically. The agent left CB20A `IN_PROGRESS` without a record, so RA-113.1 holds the verified package facts. Next: TB20 (artifact-only, 26 rows) measures the corrected pin at runtime. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source `e22c5da5f8ab86a39650c670340a658847a2ac7e`; HEAD `src`, `include` and `tests` are identical to it. |
| Last compiled semantic source | CB20A eight-target GMP/GMPXX compile [39520787768](https://github.com/akashskypatel/Directional/actions/runs/39520787768), package `12310848591`, ZIP SHA-256 `0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`; hashes `28/28`, statuses clean, `runtimeExecution=false`; **expires 2026-10-28T00:23:30Z**; accepted by RA-113. Record: `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md` (RA-113.1). |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate / rejected evidence | CB20 compile RED (superseded by CB20A): run [39512680019](https://github.com/akashskypatel/Directional/actions/runs/39512680019), log artifact `12306507832`; five test accessor errors; record `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md`, reviewed by RA-112. TB19A: run `39484475466`, artifact `12292268624` (ZIP `25d48ed7…7efa7c`), expires 2026-11-03; 7/7 selected, control `selector:443` PASS, 6 torus RED at `gauge-pin-consistency;edge=0,3`; report `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`, accepted by RA-110. TB19: run `39464430751`, artifact `12285225197` (ZIP `2b5dfacf…dec0`), expires 2026-11-03; 16 valid rows; report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`, accepted by RA-109. TB18 Part A `12231529583` (12/14) and Part B `12232299548` (448/497), expire 2026-11-03; candidate evidence per RA-105. First failures: `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`. |
| Regression accounting | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected, TB18 candidate 448/497. |
| Active boundary | `RP-01` open. M2 = H-pin, CONFIRMED (RA-110.3). The corrected domain (RA-111.4) is compiled in `e22c5da5f` (RA-113) but not yet measured. The RA-103.5 R-route falsifier stays undetermined until TB20. Cut-set inclusion is open but fail-closed (RA-111.5); TB20's P3 bears on it. M1 certificate shadowing (10 identities, RA-105.3) is unchanged; its DEFN follows TB20-REV. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN` — EXACT NEXT

- **Type / owner:** Test + Benchmark, artifact-only; implementation agent. Authority: RA-113.3–113.5 (`Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md`).
- **Objective:** measure the corrected gauge pin at runtime on the 26 RA-113.3 rows, using the CB20A package.
- **Read before work:**
  - RA-113;
  - the TB19A harness `.agents/Directional/tools/m6_cp3_tb19a_torus_rejection_site_harness.sh` and the TB19A report (dispatch procedure);
  - the TB19 report (M1 first failures).
- **In scope:**
  1. **Harness.** Create `.agents/Directional/tools/m6_cp3_tb20_gauge_pin_domain_harness.sh` from the TB19A harness. Its diff is limited to:
     - `sha` `e22c5da5f8ab86a39650c670340a658847a2ac7e`, `artifact` `12310848591`, `digest` `0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`;
     - the 26-row table from RA-113.3, whose fourth field is the baseline;
     - the count 7→26;
     - the `TB19A` labels and ledger header → `TB20`, and `TB18` → `baseline`.
  2. **Run.** One dispatch against artifact `12310848591` before 2026-10-28T00:23:30Z.
  3. **Report.** `Architecture_M6_CP3_TB20_Gauge_Pin_Domain_Harvest_Report_20261021.md`, containing:
     - the run, artifact and digest;
     - the 26-row table: status, first failure, product, detail, site and raw SHA-256;
     - for each M1 row, whether its first failure equals TB19's after the +77 TQ mapping;
     - P1–P4 marked observed or not observed. The report does not interpret the M2 outcomes.
- **Out of scope:**
  - any source, test, selector or workflow change;
  - any repair;
  - accounting changes;
  - the M1 binding.
- **Success evidence:**
  - 26/26 single-identity selections;
  - the package digest and 28/28 manifest are verified before and after the run;
  - the result artifact is retained with its SHA-256;
  - the report and harness are committed.
- **On success:** `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN-REV` (Review, mandatory). It adjudicates P1–P4, determines the R-route and decides whether a selector-497 regression run must come before the M1 DEFN.
- **On failure/blocker:** STOP and return to Review on any of:
  - a digest or manifest mismatch;
  - a missing fixture;
  - a selection count other than 26;
  - a harness failure.

  There is no second harness repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN` | Test + Benchmark, artifact-only, 26 rows, per RA-113.5. The package expires 2026-10-28T00:23:30Z. |
| 2 — mandatory | `M6-CP3-TB20-RP01-GAUGE-PIN-DOMAIN-REV` | Review: adjudicates P1–P4, determines the R-route and sets the next unit. |
| planned, not authorized | [selector-497 regression run, if TB20-REV requires it] → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as TB20-REV assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — TB20, artifact-only (RA-113.5); never Code + Build.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md` (RA-113, the TB20 specification and package facts); `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md` and its harness (procedure); `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md` (M1 baselines); `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md` (RA-111, the domain); `LESSONS.md` §§1, 2, 7.
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
