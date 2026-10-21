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
| Currency | 2026-10-21: TB22 immutable harvest executed 11/11, 4 PASS / 7 RED; next mandatory independent TB22 Review, not implementation. No selector or product acceptance. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Last semantic CB21 source `8453e19e6ac7d976a9cac45978ad31104a52f034`; later STATUS/snapshot/record commits are nonsemantic. |
| CB21 immutable compile authority | Run [39540888446](https://github.com/akashskypatel/Directional/actions/runs/39540888446), package `12318897957`, ZIP SHA-256 `f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`; 28/28, clean statuses, eight GMP/GMPXX targets, `runtimeExecution=false`, expires 2026-10-28T03:54:02Z. Independent exact-byte revalidation: `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md`. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`; R3 **403/497 rejected**. |
| Latest candidate census | TB21 run `39533914719`, result `12317287104`: **449/497** (48 RED, 0 PASS→RED), reviewed RA-115; TB22 focused candidate harvest 4/11 PASS, 7 RED, not selector promotion. Frozen selector 497 unchanged. |
| Regression and blockers | **66/17/49**, debt **1**; `RP-01` open, `RP-02` UNREACHED, Gate C suspended. D2 organic odd-gauge witness unresolved, M1/other fixture debt unchanged. |

## Mandatory next turn — `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST-REV` — EXACT NEXT

- **Type:** independent Review + Plan. Inspect raw logs and semantic first failures from `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`; review must adjudicate five new downstream candidate failure sites and D2 gauge attainability, not merely repeat the prediction.
- **Evidence:** immutable source `8453e19e6ac7d976a9cac45978ad31104a52f034`, package `12318897957`; TB22 [run 39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), artifact `12323004201`, ZIP SHA-256 `71569a41315a727da3b1285cbdc94ffa360c366074fdecc3729ef0ed0b058c87`. Eleven selected, 4 PASS / 7 RED, zero skips, immutable postflight; stable 66/17/49 unchanged.
- **Findings to adjudicate:** D2 own assertion reached with `oddFaceGaugePairs=0`, `reciprocalTracerPairs=5`, `holonomyMatchedPairs=5`, all five deltas zero; `focused30:6/20/24`, `selector:446/447` RED downstream, contrary to P1; `focused30:12` independent A5 RED; all four controls PASS.
- **Boundary:** TB22 is a completed semantic RED artifact-only harvest; its successor is only this Review. DEFN-T1, DEFN-M1, and any source fixes remain conditionally planned, not authorized.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST-REV` | Independently review exact immutable TB22 evidence, classify candidate failures, authorize one successor |
| planned, not authorized | DEFN-T1 → DEFN-M1 → corrective CB/TB → fixture debt → census → RP-01 Review | Dependent on TB22 Review's decision. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — independently adjudicate TB22 semantic RED evidence, using exact result artifact and RA-116-frozen CB21 package authority.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md` and exact result artifact, TB22 plan, RA-116 CB21 Review, RA-115, D2 definition/review; `LESSONS.md` §§2, 7.
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
