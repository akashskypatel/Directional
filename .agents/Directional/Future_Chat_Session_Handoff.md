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
| Currency | 2026-10-18, after `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE-REV` (RA-88) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `70217cc2bf7d257bebd2969e1aa56b5a43326a70` (CB13), package `12130290543`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, result `11661044443`, 403/497). |
| Latest candidate or rejected evidence | TB13 run `39112131501`, result `12130683535`: 1 PASS / 5 RED. #1 RED comes from a wrong truth-table row in RA-87.4.7 (RA-88.2), not from the helper. #3/#4 B2 at front 61/179; #5/#6 B3, byte-identical to TB12. U3 production code accepted (RA-88.3). |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-87.3): B1 → U3, code accepted, closes at TB13A; B2 R endpoint → U4/U5; B3 inexact I parameter → U6 (DEFN first). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` — EXACT NEXT

- **Type / owner:** `CB` (compile only), test-only. The specification is RA-88.4 and is binding.
- **Objective:** correct the one RA-87.4.7 row that contradicts the either-direction rule, and add three discriminating rows.
- **Read before work:** the RA-88 record; RA-87.4.1; `tests/SurfaceCellsPhase10Tests.cpp:7152-7187`.
- **In scope:** in `OpenRailRouteChainIntervalTruthTable`, over chain `[1,4,7]`:
  1. flip `check({{4,7},{1,4}}, nullopt, nullopt, chain)` to `EXPECT_TRUE`;
  2. add `EXPECT_TRUE(check({{4,7},{1,4}}, t7, t1, chain))`;
  3. add `EXPECT_FALSE(check({{4,7},{1,4}}, t1, t7, chain))`;
  4. add `EXPECT_FALSE(check({{1,4},{1,4}}, nullopt, nullopt, chain))`.

  Then GMP/GMPXX compile and package.
- **Out of scope:** every other row, test or production line; harness, selector or workflow changes; running tests.
- **Success evidence:** compile green; package ID, ZIP SHA-256 and source SHA recorded; `runtimeExecution=false`; a CB13A record of 25 lines or fewer.
- **On success:** `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` (RA-88.5).
- **On failure/blocker:** `UNKNOWN — STOP`; orchestration failures follow `Turn_Cadence.md` rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` | Test-only, compile only (RA-88.4). |
| 2 — conditional | `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` | After CB13A is packaged. TB13's harness with only sha, artifact, digest and labels changed. Predictions: #1/#2 PASS; #3–#6 `first_failure` byte-identical to TB13. Falsifiers: #1 RED, any #3–#6 change, or `open-rail-chain-interval` anywhere. U3 closes on success. |
| 3 — conditional | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` | On the CB13A package, with the unchanged 497 harness (`947a95ee…`) and the candidate given only through its environment inputs. Classify every RED's first failure as B1/B2/B3/other; list the R3 PASSes that are now RED. A RED on `open-rail-chain-interval` goes to Review. No interpretation. |
| 4 — conditional | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV` | Review: orders U4/U5/U6 and issues the DEFN for U6 (the exact I-endpoint parameter). |

A RED TB goes to Review (rule 4); orchestration failures follow rule 5. Anything beyond step 4 is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — use the turn-based-coding-agent Code + Build guidance; test-only edit; no runtime execution.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md` (RA-88), `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md` (RA-87.3–87.5), `Architecture_M6_CP3_TB13_Open_Rail_Chain_Interval_Harvest_Report_20261018.md`, `Architecture_M6_Frozen_Definitions.md` RA-87/RA-88, `GMP_COMPILE_POLICY.md`.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats. History gates (`authority|boundary|ledgers`, drift `--base`) are Review gates (RA-82.3); implementation turns run `document_drift_audit.py --root .` only.

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
