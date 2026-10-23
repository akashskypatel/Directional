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
| Currency | 2026-10-23, RA-147 independently accepts CB30 test-only static/compile evidence and authorizes TB32 immutable 500-case verification. No runtime or gate promotion. |
| Branch/source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open. CB30 semantic `19267540081a4ff3a99826e3b9a766f1dbbded42`; compile [run 40023541183](https://github.com/akashskypatel/Directional/actions/runs/40023541183), artifact `12531891913` ZIP SHA-256 `040b7b12e4b36fa78f2c5eae6465ddaadd2a1fbd8ee9bf18ebda6e35e9a3b97b`; 28/28 hashes verified, GMP/GMPXX eight targets, `runtimeExecution=false`. |
| TB30 runtime evidence | [run 39949886169](https://github.com/akashskypatel/Directional/actions/runs/39949886169), immutable result `12500088095` ZIP SHA-256 `bba928eb45957a29521a221ad093891de29f6a498c156691acc9c68b3a7308bf`; all 29 identities once, 22 PASS / 7 typed RED, 61/61 result hashes, no missing/skip/invalid/duplicates/unexpected PASS, no rebuild. Owning `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Report_20261023.md`. |
| Unresolved first failures | Six `face-gauge-missing` (`selector:220,221,296,302,304,439`) and one `open-rail-chain` (`cp3entry:4`) remain inherited typed RED, no new stable regression or resolved causal assignment. |
| TB31 independently reviewed evidence | [run 39959505758](https://github.com/akashskypatel/Directional/actions/runs/39959505758), result `12506242253`, ZIP SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b`; 1,000/1,000 checksum entries and 497/497 raw logs verified. All 497 Review-owned manifest rows matched exact test/binary/expected outcome; exit 0, postflight true, no compile/relink/benchmark. Report `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md`, RED inventory and RA-145 review retained. |
| Accepted versus candidate | CP2 491/491 accepted. R3 403/497 rejected; TB28 462/497 superseded as candidate by TB31 472/497, **unaccepted**. Selector 497 byte-frozen; stable 66/17/49, debt 1; RP-01 open, RP-02 unreached, Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB32-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-VERIFY` — EXACT NEXT

- **Type/owner:** immutable Test + Benchmark, artifact-only; no rebuild, configure, relink, benchmark, product/test/fixture/selector/source mutation. RA-147 independently accepted CB30 compile scope, not behavior.
- **Exact package:** `19267540081a4ff3a99826e3b9a766f1dbbded42`; [run 40023541183](https://github.com/akashskypatel/Directional/actions/runs/40023541183), artifact `12531891913` ZIP SHA-256 `040b7b12e4b36fa78f2c5eae6465ddaadd2a1fbd8ee9bf18ebda6e35e9a3b97b`, 28/28 verified, eight GMP/GMPXX targets, `runtimeExecution=false`.
- **Exact selected evidence:** `Architecture_M6_CP3_TB32_Periodic_Owner_Gauge_Case_Manifest.tsv` SHA-256 `597741409f06a80877cb8ae6f5fd2f92785de99a629a7d2c6453921858996437`, 500 unique one-execution identities: unchanged frozen 497 test names and IDs, six amended expected RED→PASS (`selector:220,221,296,302,304,439`), plus three distinct new factory controls. Anticipated **478/497 and 481/500 PASS** only; 19 inherited RED predicted, do not treat as measured.
- **Falsifiers/STOP:** incorrect exact package, missing/skipped/duplicate/invalid test, wrong first typed site or unexpected verdict, changed immutable pre/post hash, actual PASS→RED, or failed new control. Publish raw individual logs and independent 500-row ledger. Stop for TB32-REV; do not repair, modify expectations or start other owners.
- **Evidence/authority:** [RA-147 review](Architecture_M6_CP3_CB30_Periodic_Owner_Fixture_Gauge_Review_Decision_20261023.md) and [TB32 plan](Architecture_M6_CP3_TB32_Periodic_Owner_Gauge_Verification_Plan_20261023.md). CP2 491/491 accepted, TB31 472/497 candidate, stable 66/17/49 debt1, RP-01 open, RP-02 unreached. Synthetic owner-map fixture is not produced periodic/A6 proof.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB32-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-VERIFY` | Execute exactly 500 immutable cases, no rebuild/mutation |
| 2 — conditional | `M6-CP3-TB32-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-VERIFY-REV` | Independently review actual 500 outcomes, first failures and pre/postflight; no runtime |
| 3 — separately planned | Odd-transport/permutation CB → TB → Review | Real odd A3 transport and unequal gauge, full row/corner remap, stale-vector/inverse negatives; new authorization required |
| later — UNKNOWN | Remaining 19 RED owners → census → RP-01 Review | Cycle locus, untyped cases, A5, open-rail, selector442, DEFN-T1; A6 produced invariance separately retained |
| deferred | DIAG-RETAIN, DEFN-SEAM-NZ and periodic follow-up | Existing separate gates retained |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — immutable CB30 compiled package, TB32 exact 500-case manifest and execution policy; no code/runtime change outside bounded TB.

Minimum context after mandatory policies:
0. ORIENTATION, ROADMAP, this handoff, TODO, RA-147 decision and TB32 plan/manifest.
1. Immutable CB30 report `.agents/Directional/Architecture_M6_CP3_CB30_Periodic_Owner_Fixture_Gauge_Code_Build_Record_20261023.md` and [run 40023541183](https://github.com/akashskypatel/Directional/actions/runs/40023541183), artifact `12531891913` ZIP SHA-256 `040b7b12e4b36fa78f2c5eae6465ddaadd2a1fbd8ee9bf18ebda6e35e9a3b97b`; 28/28 hashes verified, GMP/GMPXX eight targets, `runtimeExecution=false`.
2. TB32 500-row manifest (497 census plus three controls) with SHA-256 597741409f06a80877cb8ae6f5fd2f92785de99a629a7d2c6453921858996437; do not change identities, expected verdicts or source.
3. Source A3 / factory gauge pin and RA-146.2–4 witness limitations; inspect outcomes only and preserve 19 inherited REDs.
4. Frozen RA-45/RA-111 rules and RA-145/TB31 census evidence; no gate promotion.

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
