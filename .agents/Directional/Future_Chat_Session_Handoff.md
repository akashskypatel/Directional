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
| Currency | 2026-10-18, after `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE-REV` (RA-90) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b` (CB13A). Production code is unchanged since CB13 (`70217cc2`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, 403/497). The R3 baseline is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED); artifact `11661044443` expires 2026-10-24. |
| Latest candidate or rejected evidence | TB13A run `39121449664`, result `12134411966` on CB13A package `12132184878`: #1/#2 PASS; #3–#6 byte-identical to TB13 (B2, B3). U3 closed (RA-90.2). |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-87.3): B1 cleared (U3 closed); B2 R endpoint → U4/U5; B3 inexact I parameter → U6 (DEFN first). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` — EXACT NEXT

- **Type / owner:** `TB`, artifact-only measurement. The specification is RA-87.5, RA-89 and RA-90.3–90.5.
- **Objective:** measure the frozen 497 on CB13A, classify every RED mechanically, and compare against R3. No interpretation.
- **Read before work:** the RA-88 record §RA-89/§RA-90; `tools/m6_cp3_entry_497_artifact_only_harness.sh`; `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`; `Architecture_M6_CP3_TB1_Entry_R3_Execution_Record.md` (the dispatch precedent).
- **Run:** the unchanged harness (SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`) with `--execute` and these environment inputs:

  | Variable | Value |
  |---|---|
  | `CANDIDATE_ARTIFACT_ID` | `12132184878` |
  | `EXPECTED_SOURCE_SHA` | `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b` |
  | `EXPECTED_CANDIDATE_ZIP_SHA256` | `36197dffa91b5dbb3a36d589cab314e95e4d7d24e9121617ed17f59256f2b072` |
  | `EXPECTED_ROOT_MANIFEST_SHA256` | `bdb4ad988c463f082a1129d17d463da7e3638f24c81396220adb996a328583e1` |
  | `EXPECTED_SOURCE_ARCHIVE_SHA256` | `25ec06e748ea29445d50993c0cd0874bb30da7ab030e24a99cff737e70b3e77f` |

- **Classify** each RED's first `firstPredicate=` text (or its first gtest failure line) per RA-90.4:
  - B1: `open-rail-chain-interval`;
  - B2: `predicate=endpoint-0|1` with `a3ProbeDecodedVertex=<integer>` and `a3ProbeContactEndpointMember=0`;
  - B3: `a2bProbeFirstFailedCondition=not-same-interior-carrier-point`;
  - B2+B3 if both apply;
  - other: grouped by `predicate=` name or by the first 80 characters of the line.
- **Deliver** (RA-90.5):
  - `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`, one row per RED with columns `phase, ordinal, identity, owner, exit, raw_sha256, class, first_failure (≤200 chars), R3 (PASS/RED), R3_first_observable`;
  - a report of 30 lines or fewer giving totals per phase, counts per class, the R3 PASS → now RED list, the R3 RED → now PASS list, and the TSV's SHA-256.
- **Prediction:** `cp3entry` 2 and 6 are B3. **Falsifier:** any B1 → Review.
- **Out of scope:** compile, relink, benchmarks; any source, test, fixture, selector or harness change; interpretation, ledger changes or promotion.
- **On completion (any totals):** `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV`. **On failure/blocker:** `UNKNOWN — STOP`; orchestration failures, including an exact-one selection abort, follow `Turn_Cadence.md` rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-TB13A-R10-OPEN-RAIL-CHAIN-INTERVAL-TRUTH-TABLE` | U3 closed (RA-90). |
| 1 — next | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` | Artifact-only census on CB13A (above). |
| 2 — conditional | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV` | Review: adjudicates the census, re-baselines controls, orders U4 (factory admits R), U5 (consumer emits R) and U6, and issues the DEFN for U6 (exact I-endpoint parameter: no epsilon, producer-origin, satisfiable on TB12's doubles). |

A RED TB goes to Review (rule 4); orchestration failures follow rule 5. Anything beyond step 2 is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — artifact-only frozen 497 census (TB13C) on CB13A with the unchanged harness; do not compile or modify source, tests, fixtures, selectors or harnesses.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md` (RA-88–RA-90), `Architecture_M6_CP3_TB1_Entry_R3_Execution_Record.md` and `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (the R3 baseline), `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md` (RA-87.3, RA-87.5), `Architecture_M6_Frozen_Definitions.md` RA-87–RA-90.
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
