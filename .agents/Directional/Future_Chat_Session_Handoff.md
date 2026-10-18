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
| Currency | 2026-10-18, after TB13A immutable truth-table verification (RA-88.5) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b` (CB13A). Production code is unchanged since CB13 (`70217cc2`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, result `11661044443`, 403/497). |
| Latest candidate or rejected evidence | CB13A package `12132184878` (run `39117126811`): ZIP SHA-256 `36197dffa91b5dbb3a36d589cab314e95e4d7d24e9121617ed17f59256f2b072`, root manifest `bdb4ad988c463f082a1129d17d463da7e3638f24c81396220adb996a328583e1`, source archive `25ec06e748ea29445d50993c0cd0874bb30da7ab030e24a99cff737e70b3e77f`; 28/28, GMP, `runtimeExecution=false` (RA-89.1). Latest runtime: TB13A result `12134411966` from run `39121449664`, two gates PASS, four unchanged expected B2/B3 RED; see TB13A harvest. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-87.3): B1 → U3 CLOSED at TB13A; B2 R endpoint → U4/U5; B3 inexact I parameter → U6 (DEFN first). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` — EXACT NEXT

- **Owner:** artifact-only Test + Benchmark, RA-87.5/RA-89. Execute unchanged frozen `m6_cp3_entry_497_artifact_only_harness.sh` selector497 against CB13A; classify each RED B1/B2/B3/other and list R3 PASS→RED identities. Do not interpret or change source, tests, selector, compile, relink, or benchmark.
- **Five inputs:** artifact `12132184878`; source `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b`; ZIP SHA-256 `36197dffa91b5dbb3a36d589cab314e95e4d7d24e9121617ed17f59256f2b072`; root manifest SHA-256 `bdb4ad988c463f082a1129d17d463da7e3638f24c81396220adb996a328583e1`; source archive SHA-256 `25ec06e748ea29445d50993c0cd0874bb30da7ab030e24a99cff737e70b3e77f`.
- **Read first:** `Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md` RA-88.5/RA-89; `Architecture_M6_CP3_TB13A_Truth_Table_Harvest_Report_20261018.md`; frozen 497 harness and Turn Cadence. Any `open-rail-chain-interval` RED requires Review. Keep immutable results and first-failure inventory.
- **Successor:** mandatory `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV` for acceptance and U4/U5/U6 disposition. Orchestration failure follows Turn_Cadence rule 5.

## Turn Sequence

| Step | Turn | Condition |
|---|---|---|
| next | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` | Immutable 497 census |
| conditional | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV` | Review of RED inventory and subsequent remediation authority |

Further successors UNKNOWN. Do not start successor work in this turn.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — artifact-only frozen 497-identity TB13C census on CB13A; do not compile or modify source, tests or fixtures.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md` (RA-88, RA-89), `Architecture_M6_CP3_TB13_Open_Rail_Chain_Interval_Harvest_Report_20261018.md` (RA-88/89 baseline), `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md` (RA-87.3, RA-87.5), `Architecture_M6_Frozen_Definitions.md` RA-87–RA-89.
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
