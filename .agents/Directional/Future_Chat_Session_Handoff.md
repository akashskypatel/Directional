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
| Currency | 2026-10-18, after TB15 nine-identity artifact-only harvest: 4 PASS, 5 expected diagnostic RED, exact I witnesses measured and matched baseline; next independent TB15 Review. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft. Semantic source `e4785d734e35d2f01ca3ee8099772f6ab5257f4c`; TB15 harness commit `f20bf54c770eee86e3b659235c2ced2aaff9bc43`, dispatcher event `971834454552560658d8b99978e84c26cbd2926d`. Refetch HEAD before writes; later documentation commits do not change semantic source. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. The rejected R3 baseline is 403/497 (`Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`). |
| Latest candidate or rejected evidence | TB15 [run 39170298228](https://github.com/akashskypatel/Directional/actions/runs/39170298228), result artifact `12152685129`, ZIP SHA-256 `2536c38b958f76cfef6c5e0ef951e902e958d2cdb863e650e2b8b4002a50f748`: 4 PASS + 5 predicted RED, zero missing, immutable postflight. TB14A latest full census remains 425/497; no new semantic promotion. |
| Regression accounting and debt | **66/17/49**, debt **1**, frozen selector 497; R3 403/497 rejected. Test debt 174,191,242,442,250 and adjacent-sheet helper deferred as reviewed. |
| Active boundary | `RP-01` open. B1 cleared; B2 middle-rail R witness absent, planned for later CB17/CB18; B3 strict interior `1,4@1/5` witness now proven bound on both sides, rule not implemented. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER-REV` — EXACT NEXT

- **Type:** independent Review / Plan, not a Code + Build or runtime turn. Re-open primary evidence, re-derive TB15 witness and byte-neutrality facts, adjudicate RA-96.5 falsifiers, and decide whether/what CB16 is authorized to change.
- **Authority:** RA-96.5 in `.agents/Directional/Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`; new owning report `.agents/Directional/Architecture_M6_CP3_TB15_Exact_I_Witness_Harvest_Report_20261018.md`; current regression tracker. Immutable result ZIP digest `2536c38b958f76cfef6c5e0ef951e902e958d2cdb863e650e2b8b4002a50f748`.
- **Observed:** three CB15 witness tests and one interval truth-table control PASS. B2 diagnostics #5/#6 remain RED at front 61/179, both witnesses absent/binds 0. B3 diagnostics #7/#8/#9 remain RED at front 17/203, two bound matching witnesses `1,4@1/5`, chi 3/3/0. Four new fields removed from first-failure records yield exact TB13A/TB14A baseline equality.
- **Boundary:** no compile, no runtime in Review; do not dispatch CB16 automatically. Review must explicitly authorize any succeeding CB scope and preserve I exactness, no tolerance, fail-closed rules, selector and accounting.
- **Current artifact package:** `12150973440` from `e4785d734e35d2f01ca3ee8099772f6ab5257f4c`, SHA-256 `7f56c6a551494ab4e5b9276719946e358ea23bd8b2c5bddec94014796d76c073`.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER-REV` | Independent Review of TB15 (RA-96.5), no runtime. |
| 2 — conditional | `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-ADMISSION` | **Not authorized until** the Review explicitly approves a concrete rule and non-weakening proof. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — re-derive nine TB15 observations and baseline equality, decide CB16 or stop.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-96.5 (`Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`), TB15 owning report and result artifact `12152685129`, CB15 compile record and immutable source package, TB13A and TB14A baseline artifacts, `LESSONS.md` Evidence/Witness/Build sections, `TODO.md` and regression tracker.

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
