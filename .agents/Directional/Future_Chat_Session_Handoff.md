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
| Currency | 2026-10-24, TB35 artifact-only 13-case run verified 11 PASS / 2 RED, with selector191/192 A4 negative expectations unsatisfied. No acceptance promotion; independent TB35-REV is next. |
| Source/package | CB34 semantic `d5fc8f22fd309ba90ad1fd7b4fbdc3491a5a8f7d`; [compile run 40111610291](https://github.com/akashskypatel/Directional/actions/runs/40111610291), package `12566907246`, ZIP `ca5c490bae2d65f9c043636c285d29edcfe5695b9334c24edcc281fac26c6a17`; 28/28 manifest entries, eight GMP/GMPXX targets, `runtimeExecution=false`. [Record](Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Record_20261024.md). |
| Reviewed decision | [CB34-REV](Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Review_Decision_20261024.md) accepted static gauge only. [TB35 report](Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Verification_Report_20261024.md) measures 5/7 selector positives, 2 A4 negative RED, all six oracle/guard/control PASS; independent Review pending. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500** (19 inherited RED); TB34 **5 PASS / 7 inherited RED** (12 measured), TB33 synthetic **6/6** only; selector497 frozen; stable **66/17/49**, debt 1. RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV` — EXACT NEXT

- **Type:** independent evidence Review only; no source/test/compile/benchmark/selector/fixture changes. Reopen original immutable 13-case manifest, hashes, raw logs and negative-oracle source; do not accept harness summary alone.
- **Evidence:** [run 40116807908](https://github.com/akashskypatel/Directional/actions/runs/40116807908), result `12569985565`, ZIP SHA-256 `155ae1c43c7c83b43decf43ba5b8a711860cf00f304e9f975a0c552a26e1309e` (18/18 internal checksums, 13/13 terminal, 11 PASS / 2 RED, postflight true), semantic package `d5fc8f22fd309ba90ad1fd7b4fbdc3491a5a8f7d` / artifact `12566907246`; exact original TB35 manifest SHA-256 `d67e503db14f2cb1ae978482665057372edd2e56d7763cd38288469174e75af8`.
- **Decisive task:** independently determine why `selector:191` and `selector:192` expected `PeriodicHolonomyMismatch` but got `Produced`, assign correct owning first predicate and discharge or retain each candidate (no post-hoc fixture retune). Five other original selectors, gauge oracle, guards, factory controls PASS in TB35. Preserve TB32's 19 inherited RED full-census baseline; no automatic cumulative promotion.
- **After Review only:** if A4 is confirmed as the owning defect, separately authorize a DEFN periodic producer. Preserve stable 66/17/49, debt1, CP2 491/491 accepted, frozen 497 selector, RP-01 open.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV` → `…-REV-AUDIT` (RA-150) | Owner kept; CB34 transformation corrected. |
| done | `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR` | Gauge helper/oracle compiled; no runtime. |
| done | `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR-REV` | Static gauge/source/compile accepted; TB35 manifest issued; no runtime. |
| done | `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY` | 13 cases, 11 PASS / 2 RED, 18/18 checksums; no runtime acceptance. |
| 1 — next | `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV` | Independently adjudicate two A4 negative REDs, review five recoveries, decide conditional owner. |
| 4 | Untyped 7 (`selector:174,201,204,242,247,250,405`) per-row first-site pins → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; DEFN or diagnostic first. |
| 5 | Census → RP-01 Review | Review-owned 497(+) manifest. |
| carried | `DIAG-RETAIN` (A5–A7 diagnostic snapshots; full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | DEFN-SEAM-NZ, Periodic follow-up, RA-146.2/4, RA-45.4, G4-B002 | After a witness / separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **TB35 independent Review** — reopen TB35 report, frozen 13-case manifest, run 40116807908 / artifact 12569985565 raw logs and negative GTest bodies (`selector:191/192`), cross-check first A4 rejection responsibilities and exact source before any acceptance or new DEFN. No test, source, compile, benchmark or selector mutation in Review.

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
