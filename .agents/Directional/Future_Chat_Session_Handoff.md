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
| Currency | 2026-10-21: CB21 independently reviewed (RA-116), static source/compile accepted, no runtime. Exactly next is immutable TB22, eleven independent tests; no selector or product acceptance. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Last semantic CB21 source `8453e19e6ac7d976a9cac45978ad31104a52f034`; later STATUS/snapshot/record commits are nonsemantic. |
| CB21 immutable compile authority | Run [39540888446](https://github.com/akashskypatel/Directional/actions/runs/39540888446), package `12318897957`, ZIP SHA-256 `f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`; 28/28, clean statuses, eight GMP/GMPXX targets, `runtimeExecution=false`, expires 2026-10-28T03:54:02Z. Independent exact-byte revalidation: `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md`. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`; R3 **403/497 rejected**. |
| Latest candidate census | TB21 run `39533914719`, result `12317287104`: **449/497** (48 RED, 0 PASS→RED), reviewed RA-115 and inventory `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`; frozen selector 497 unchanged. |
| Regression and blockers | **66/17/49**, debt **1**; `RP-01` open, `RP-02` UNREACHED, Gate C suspended. D2 organic odd-gauge witness unresolved, M1/other fixture debt unchanged. |

## Mandatory next turn — `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST` — EXACT NEXT

- **Type:** Test + Benchmark (artifact-only); after the independent RA-116 CB21 Review. Full immutable scope, identity names, predictions and stop rules: `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Plan_20261021.md`.
- **Exact package:** artifact `12318897957`, source `8453e19e6ac7d976a9cac45978ad31104a52f034`, ZIP SHA-256 `f0ae4338c462600b6cddbd0a768e0432f2148148f40f920790d6c8f1c0e9c606`; no compiling, modifying source/tests/fixtures, selector promotion or regeneration. Run exactly **11 independent test processes**: the 7 torus fixture consumers, `cp3entry:6`, and 3 control identities. Verify manifest/source before and after.
- **Predictions:** five CP2-GREEN torus consumers advance through fixture and pass their assertions; `cp3entry:1` reaches and, absent an odd pair, fails its own D2 assertion with `oddFaceGaugePairs=0` receipt; `focused30:12` unchanged A5 failure; four controls PASS. **Falsifier:** fixture throw with `reciprocalTracerPairs=0` or `holonomyMatchedPairs=0` diagnoses missing earlier periodic witness publication, not D2; return to TB22 Review. Any new first failure must be captured honestly.
- **Boundary:** TB22 itself must not repair anything. Its only planned successor is separate mandatory `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST-REV`; DEFN-T1, DEFN-M1 and further CB turns are not yet authorized.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB22-RP01-TORUS-WITNESS-HARVEST` | Immutable 11-process torus fixture and control harvest, no build; artifact-only |
| planned, not authorized | TB22-REV → DEFN-T1 (D2 attainability under RA-111.3) → DEFN-M1 (M1 binding owner, RA-105.3) → corrective CB/TB → remaining fixture debt → census → RP-01 Review | Requires the separate preceding Review at each boundary. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test_benchmark** — the RA-116-frozen immutable 11-process TB22, with CB21 package exact authority.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md` (RA-116), `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Plan_20261021.md`, CB21 compile record, RA-115, D2 definition/review; `LESSONS.md` §§2, 7.
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
