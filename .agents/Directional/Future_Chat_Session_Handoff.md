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
| Currency | 2026-10-23, RA-146 FG01 independent Review: fixture-only correction accepted with binding amendments; synthetic evidence limited to owner bookkeeping, odd-transport/permutation split out. No code/runtime change; TB31 remains candidate. |
| Branch/source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open. CB29 semantic `2602e7398cdc6f1281abe11a758de35166b6590c`; CB29 compile [run 39932638282](https://github.com/akashskypatel/Directional/actions/runs/39932638282), package `12492950387` ZIP SHA `9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`; GMP eight targets, 28/28 hashes, compile-only. |
| TB30 runtime evidence | [run 39949886169](https://github.com/akashskypatel/Directional/actions/runs/39949886169), immutable result `12500088095` ZIP SHA-256 `bba928eb45957a29521a221ad093891de29f6a498c156691acc9c68b3a7308bf`; all 29 identities once, 22 PASS / 7 typed RED, 61/61 result hashes, no missing/skip/invalid/duplicates/unexpected PASS, no rebuild. Owning `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Report_20261023.md`. |
| Unresolved first failures | Six `face-gauge-missing` (`selector:220,221,296,302,304,439`) and one `open-rail-chain` (`cp3entry:4`) remain inherited typed RED, no new stable regression or resolved causal assignment. |
| TB31 independently reviewed evidence | [run 39959505758](https://github.com/akashskypatel/Directional/actions/runs/39959505758), result `12506242253`, ZIP SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b`; 1,000/1,000 checksum entries and 497/497 raw logs verified. All 497 Review-owned manifest rows matched exact test/binary/expected outcome; exit 0, postflight true, no compile/relink/benchmark. Report `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md`, RED inventory and RA-145 review retained. |
| Accepted versus candidate | CP2 491/491 accepted. R3 403/497 rejected; TB28 462/497 superseded as candidate by TB31 472/497, **unaccepted**. Selector 497 byte-frozen; stable 66/17/49, debt 1; RP-01 open, RP-02 unreached, Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB30-RP01-PERIODIC-OWNER-FIXTURE-GAUGE` — EXACT NEXT

- **Type / owner:** Code + Build, compile-only; RA-146 [decision](Architecture_M6_CP3_DEFN_FG01_Periodic_Face_Gauge_Factory_Contract_Review_Decision_20261023.md).
- **Objective:** restore six periodic-owner tests' factory preconditions without weakening factory admission or changing their owner assertions.
- **Read:** RA-146 (including six-case table and falsifiers), amended FG01 definition, frozen RA-45/RA-111, shared fixture and draft reconstruction, factory gauge/owner checks.
- **In scope:** only executable source `tests/SurfaceCellTransitionQuotientTests.cpp`: derive the two face gauges from real reciprocal atlas transport and topology-keyed faces; pass the vector; add the three explicitly named baseline/missing/one-face/uniform-shift controls defined in RA-146. Compile/package with GMP/GMPXX.
- **Out of scope:** production source, original six assertions, selector/manifest changes, runtime/discovery/benchmarks, periodic topology redesign, nonzero/permutation follow-up and other owners.
- **Success evidence:** exact one-file semantic diff, unchanged six assertions, complete narrowly named controls, immutable compile package. No runtime claim.
- **On success:** `M6-CP3-CB30-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-REV`.
- **On failure/blocker:** stop; same CB30-REV adjudicates exact failed prerequisite/compile or out-of-scope need. Never weaken a guard or expand the repair.
- **Preserve:** CP2 491/491 accepted; TB31 472/497 candidate; frozen 497; stable 66/17/49, debt1; RP-01 open, RP-02 unreached.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB30-RP01-PERIODIC-OWNER-FIXTURE-GAUGE` | Shared periodic-owner fixture gauge plus three factory controls; one test file, compile/package only |
| 2 — conditional | `M6-CP3-CB30-RP01-PERIODIC-OWNER-FIXTURE-GAUGE-REV` | Review exact completed package/diff, or adjudicate a blocked CB30; no runtime |
| 3 — planned, not yet authorized | TB32 immutable verification → independent Review; exact IDs assigned by step 2 | Six original cases + three controls; frozen 497 census retained. Prediction 478/497 + three focused PASS, no acceptance inferred |
| 4 — planned, not yet authorized | Odd-transport/permutation CB → TB → Review | Real odd transition, unequal gauges, complete remap positive/stale-vector negative; separate from initial repair |
| later — UNKNOWN until assigned | Remaining 19 RED owners → census → RP-01 Review | Seven A3 cycle, seven untyped, A5 focused30:12, A4 cp3entry:4, selector:442, DEFN-T1 cp3entry:1/2. Produced A6 gauge-invariance evidence remains separately owned |
| deferred | DIAG-RETAIN, DEFN-SEAM-NZ and Periodic follow-up | Existing separate witness and sequencing gates remain in force |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — only the bounded fixture repair; no project runtime.

Minimum context after mandatory policies:
0. ORIENTATION, ROADMAP, this handoff.
1. RA-146 `Architecture_M6_CP3_DEFN_FG01_Periodic_Face_Gauge_Factory_Contract_Review_Decision_20261023.md` and amended FG01 definition.
2. `tests/SurfaceCellTransitionQuotientTests.cpp` direct fixture, its six callers, draft copy/reconstruction; factory gauge and periodic-owner branches in SurfaceCellTracing.cpp.
3. Frozen RA-45 relational-gauge and RA-111 pin-domain rules; RA-145/TB31 remain runtime authority.
4. TODO and regression tracker, especially RA-146's synthetic evidence limits and separately gated nonzero/permutation/A6 obligations.

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
