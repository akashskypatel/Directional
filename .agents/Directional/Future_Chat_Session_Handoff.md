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
| Currency | 2026-10-19, after `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS`. Artifact-only run `39277232731`, result `12198063461` (ZIP `7f8769ed…06cba`) verified: 12/12 selected, 7 PASS / 5 expected diagnostic RED. #3 is corrected, and #8–#12 retain byte-identical `first_failure` records to TB16. RA-100.3 predictions hold; TB16C is now authorized as a separate turn. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Latest semantic source is `7cfa5b4612ed67ec0bbddb747edbc6c53076b781` (test-only; production unchanged from CB16 `1c45e89a`). CB16A package `12193816372` ([run 39266100202](https://github.com/akashskypatel/Directional/actions/runs/39266100202)): ZIP `113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3`, root manifest `f5ebf229a8ac9fad6a8797aefb36d8acb34a7e7441bb8dd9edb9858b4dfbf556`, source archive `85d487e45086eb0a111207f790e67dcf7069517f1f06f3b3620573d56e29106b`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. The R3 baseline (403/497) is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`. |
| Latest candidate or rejected evidence | TB16A [run 39277232731](https://github.com/akashskypatel/Directional/actions/runs/39277232731), result `12198063461` (ZIP SHA-256 `7f8769edbddc8439662526ca9520919ad78888b31a12abdd9548d476edd06cba`): **7 PASS / 5 expected RED**, 12/12 exact identities; all RA-100.3 predictions met, including byte-identical TB16 first failures for #8–#12. `Architecture_M6_CP3_TB16A_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`. Latest full census remains TB14A **425/497**. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; no production regression. Fixture debt covers 174, 191, 242, 442, 250 and the adjacent-sheet helper (RA-96.6 order). |
| Active boundary | `RP-01` (RA-87.3):<br>• B1 is cleared.<br>• B3 (U6) is implemented by CB15/CB16 and cleared on `cp3entry:2/6` and selector 217; TB16C measures the other 16.<br>• B2 (R endpoint at rail vertex 4) is U4/U5 = CB17/CB18; its spec is re-derived from the TB16C census.<br>`RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS` — EXACT NEXT

- **Type:** Test + Benchmark, artifact-only. No compile, relink, source, test, fixture, selector or harness mutation.
- **Authority:** RA-100.4 (`Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`), conditional on TB16A; the prerequisite held in run `39277232731` (7 PASS / 5 expected diagnostic RED).
- **Harness:** unchanged `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 prefix `947a95ee`, verify full hash), execute with `--execute` and exactly these inputs:
  - `CANDIDATE_ARTIFACT_ID=12193816372`
  - `EXPECTED_SOURCE_SHA=7cfa5b4612ed67ec0bbddb747edbc6c53076b781`
  - `EXPECTED_CANDIDATE_ZIP_SHA256=113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3`
  - `EXPECTED_ROOT_MANIFEST_SHA256=f5ebf229a8ac9fad6a8797aefb36d8acb34a7e7441bb8dd9edb9858b4dfbf556`
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=85d487e45086eb0a111207f790e67dcf7069517f1f06f3b3620573d56e29106b`
- **Evidence:** immutable 497-identity census against TB14A artifact `12141843937`; retain per-identity verdicts, B2/B3 mechanism classification, and no-spurious-regression checks under RA-97.5/RA-98.5. The remaining 16 B3 identities are predicted to advance to B2, but this has **not** been measured. Do not assert it before the census.
- **Stop:** a falsifier goes to independent `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV`, which re-derives and issues the CB17 (U4) spec from actual evidence. Do not enter the Review or CB17 in the TB16C response.
- **Docs:** in-place live handoff/TODO, CHANGELOG and tracker; preserve exact source, artifact and selector authorities. Final direct `STATUS` write must come last.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | Checker rule (RA-97.4). |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | #3 RED (spec defect); B3 → B2 on 10–12. |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV` | RA-98: CB16 accepted; CB16A specified. |
| done | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-PATCH-REV` | RA-99: the patch conforms; compile only. |
| done | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW` | Compiled `7cfa5b46`; package `12193816372`; no runtime. |
| done | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-REV` | RA-100: CB16A accepted; TB16A and TB16C inputs pinned. |
| done | `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | Run `39277232731`; all predictions met, 7 PASS / 5 expected RED; no source changes. |
| 1 — next | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS` | RA-100.4: unchanged 497 harness, CB16A package, compared with TB14A. |
| 2 — conditional | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV` | Independent Review derives and issues CB17 U4 specification from the census. |
| planned, not authorized | CB17 → TB17 → CB18 → TB18 → fixture debt (242 → 174 → 250 → adjacent-sheet → 191 → 442) → census → RP-01 Review | Each CB follows a reviewed TB; a RED TB goes to Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test_benchmark** — TB16C, artifact-only selector-497 census, on package `12193816372` (source `7cfa5b46`); compare against TB14A; no rebuild.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-98–RA-100 (`Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`), CB16A code/build record (`.agents/Directional/Architecture_M6_CP3_CB16A_Exact_I_Witness_Unbound_Row_Code_Build_Record_20261019.md`), TB16A harvest report, unchanged 497 census harness, TB14A baseline evidence, `LESSONS.md` §§1, 2, 7, `TODO.md`.

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
