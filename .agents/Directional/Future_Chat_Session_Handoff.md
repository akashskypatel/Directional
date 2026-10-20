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
| Currency | 2026-10-20, TB19 harvest verified; 16 of 22 rows are valid: `cp3entry:2/6` and `focused30:12` reject at `gauge-pin-consistency;edge=1,4`, and M1 shows no regression. The six torus rows were not measured because the harness copied the fixtures one level too high (a gap in Review's spec). TB19 closeout complete; TB19A reruns torus. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`. |
| Last compiled semantic source | CB19A eight-target GMP/GMPXX compile [39446712217](https://github.com/akashskypatel/Directional/actions/runs/39446712217), package `12275794192`, ZIP SHA-256 `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`; hashes `28/28`, statuses clean, `runtimeExecution=false`; expires 2026-10-27T15:24Z; accepted by RA-107. Record: `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate / rejected evidence | TB19: run `39464430751`, artifact `12285225197` (ZIP `2b5dfacf…dec0`), expires 2026-11-03; 16 valid rows, 6 torus rows NOT MEASURED (RA-108.3). TB18 Part A: run `39349041417`, artifact `12231529583` (ZIP `e08b092d…b459`), 12/14. TB18 Part B: run `39349459268`, artifact `12232299548` (ZIP `b3ba4566…6e9b`), 448/497. Both expire 2026-11-03. RA-105 adjudicated them as candidate evidence, not promoted. First failures: `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`. |
| Regression accounting | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected, TB18 candidate 448/497. |
| Active boundary | `RP-01` open. B2 cleared; M1 certificate shadowing (10 identities), and M2, the H-pin hypothesis that the gauge pin's domain is wrong. Measured by TB19: `cp3entry:2/6` and `focused30:12` reject at the pin on rail carrier (1,4). The torus six are still unmeasured (TB19A). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE` — EXACT NEXT

- **Type:** Test + Benchmark, artifact-only. **Authority:** RA-108.5 (`Architecture_M6_CP3_TB19_Torus_Staging_Review_Decision.md`).
- **Entry:** TB19 report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md` committed and verified; 26/26 packaged hashes, 22/22 raw-log hashes; 16 valid measurements, 6 torus NOT MEASURED. No adjudication.
- **Action:** Derive TB19A harness from TB19; correct fixture staging to `view/test-data/benchmarks/fixtures`; precheck `torus.obj` and `torus.rawfield`; fail on any `test-data package not found` log; execute six torus tests and `selector:443` control.
- **Immutable pins:** source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`, package `12275794192`, digest `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`, expires `2026-10-27T15:24Z`. Preserve 28 manifest checks, GMP, no-runtime-build, postflight and G1–G4.
- **Output:** Seven-row ledger and G1–G4 held/fired. Apply all exact RA-108.5 requirements and STOP conditions. No source, test, selector, fixture, package mutation, compiler, relinker, benchmark, discovery or adjudication.
- **On success:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV` (mandatory).

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE` | Compiled; package `12275794192`, expires 2026-10-27T15:24Z. Accepted by RA-107. |
| done | TB19 dispatch (run `39464430751`) | 22/22 executed. RA-108 found 16 rows valid and 6 torus rows NOT MEASURED. |
| done | `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` (closeout) | Verified harvest report, 16 valid and 6 NOT MEASURED. |
| 1 — next | `M6-CP3-TB19A-RP01-TORUS-REJECTION-SITE` | TB, artifact-only: 6 torus rows plus the `selector:443` control, with staging fixed; RA-108.5. Must run before 2026-10-27T15:24Z. |
| 2 — mandatory | `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV` | Review of the TB19 and TB19A reports: rules on H-pin (rail carriers and periodic cuts), records the R-route as not reached, and orders the DEFN. No code repair before it. |
| planned, not authorized | DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as TB19-REV assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — TB19A artifact-only on CB19A package (RA-108.5); TB19 harvest complete.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB19_Torus_Staging_Review_Decision.md` (RA-108: validity ruling, closeout and TB19A specification); `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Review_Decision.md` (RA-107.3, the TB19 report format); `.agents/Directional/tools/m6_cp3_tb19_factory_rejection_site_harness.sh` (the TB19A template); `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`; `LESSONS.md` §§1, 5, 7.
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
