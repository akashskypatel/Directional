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
| Currency | 2026-10-19, CB16A compile-only complete at RA-99-reviewed test patch `7cfa5b46`. Eight GMP/GMPXX targets, 28/28 hashes; `runtimeExecution=false`. No CB16A test executed. Next is immutable TB16A. B3 cleared only on three measured identities now stopping at B2. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `7cfa5b4612ed67ec0bbddb747edbc6c53076b781` (test-only; production unchanged from CB16 `1c45e89a`). CB16A compile [run 39266100202](https://github.com/akashskypatel/Directional/actions/runs/39266100202), package `12193816372`, ZIP SHA-256 `113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. The R3 baseline (403/497) is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`. |
| Latest candidate or rejected evidence | TB16 [run 39246335010](https://github.com/akashskypatel/Directional/actions/runs/39246335010), result `12183498229` (ZIP `8a329317…2dc32`): 6 PASS / 6 RED.<br>• #3 RED is the spec defect (RA-98.2).<br>• #8/#9 are byte-identical to TB15.<br>• #10–#12 now stop at B2: front 97/283, vertex 4.<br>Report: `Architecture_M6_CP3_TB16_Exact_I_Witness_Checkers_Harvest_Report_20261019.md`. The latest full census is still TB14A, **425/497**. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; no production regression. Fixture debt covers 174, 191, 242, 442, 250 and the adjacent-sheet helper (RA-96.6 order). |
| Active boundary | `RP-01` (RA-87.3):<br>• B1 is cleared.<br>• B3 (U6) is implemented by CB15/CB16 and cleared on `cp3entry:2/6` and selector 217; TB16C measures the other 16.<br>• B2 (R endpoint at rail vertex 4) is U4/U5 = CB17/CB18; its spec is re-derived from the TB16C census.<br>`RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` — EXACT NEXT

- **Type:** Test + Benchmark, artifact-only, immutable; CB16A compile-only predecessor is complete. Do not combine turns.
- **Authority:** RA-98.5 and RA-99.4, `Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`.
- **Package:** exact source `7cfa5b4612ed67ec0bbddb747edbc6c53076b781`, [compile run 39266100202](https://github.com/akashskypatel/Directional/actions/runs/39266100202), result `12193816372`, ZIP SHA-256 `113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3`. GMP/GMPXX eight-target package, `runtimeExecution=false` at build boundary.
- **Harness:** TB16 harness, changing only SHA, artifact, digest and labels; 12 identities, unchanged order. Preserve archived executable permissions. #1–#7 predicted PASS, #8–#12 first-failure byte-identical to TB16. Contrary outcomes falsify and route to Review.
- **Excluded:** recompile, relink, source/test/fixture repair, selector changes, CB17, census. TB16C and Review depend on TB16A.
- **Frozen:** 66/17/49, debt 1, CP2 491/491, R3 403/497 rejected, latest census 425/497, selector 497; RP-01 open, RP-02 UNREACHED; Gate C suspended.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | Checker rule (RA-97.4). |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | #3 RED (spec defect); B3 → B2 on 10–12. |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV` | RA-98: CB16 accepted; CB16A specified. |
| done | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW` | RA-99-reviewed source `7cfa5b4612ed67ec0bbddb747edbc6c53076b781` compiled and packaged; run `39266100202`, artifact `12193816372`, no runtime. |
| done | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-PATCH-REV` | RA-99: the patch conforms; resume compile only. |
| 1 — next | `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | Artifact-only TB on CB16A package `12193816372` (RA-98.5), 12 identities. |
| 3 — conditional | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS` | Only if TB16A holds. Run on the CB16A package with the unchanged 497 harness; compared with TB14A (RA-97.5, RA-98.5). |
| 4 — conditional | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV` | Re-derives and issues the CB17 (U4) spec from the census. |
| planned, not authorized | CB17 → TB17 → CB18 → TB18 → fixture debt (242 → 174 → 250 → adjacent-sheet → 191 → 442) → census → RP-01 Review | Each CB follows a reviewed TB; a RED TB goes to Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test_benchmark** — immutable TB16A on artifact `12193816372` from semantic source `7cfa5b4612ed67ec0bbddb747edbc6c53076b781`; 12 identities, no rebuilding.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-98/RA-99 (`Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`), CB16A code/build record (`.agents/Directional/Architecture_M6_CP3_CB16A_Exact_I_Witness_Unbound_Row_Code_Build_Record_20261019.md`), TB16 harness and report, `LESSONS.md` §§2, 7, `TODO.md`.

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
