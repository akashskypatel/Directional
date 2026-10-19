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
| Currency | 2026-10-19, after `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT-REV` (RA-103): TB17 re-verified, every RA-102.5 prediction held; CB17 (U4, factory R branch) accepted; CB18 (U5, consumer emits R) and TB18 specified. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 draft) / refetch before mutation. Semantic source `ccc0b00ab6a94d0889ed7c60e4532b6c985ce03e`; CB17 package `12214741070` (ZIP `9acb5081…5ca5`, expires 2026-10-26), compile-only. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline 403/497: `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`. |
| Latest candidate or rejected evidence | TB17 result `12215967774` (ZIP `b32366a1…2ace`): 13/13, #1–#7 and #13 PASS, #8–#12 byte-identical to TB16A; adjudicated by RA-103 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`). Census baseline TB16C result `12207970911`: **425/497** (expires 2026-11-02). Not promoted. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected. Fixture debt (RA-96.6 order) after TB18; see `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-102.3, RA-103.3): B2 is the only blocker, 30 records of one I–R shape (rail 2, chain [1,4,7], route [1-4], R = vertex 4). U4 accepted; U5 = CB18 makes the consumer emit R. The factory I and R branches get their first real-data coverage at TB18. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB18-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` — EXACT NEXT

- **Type / owner:** CB (Code + Build, compile only); RA-103.4.
- **Objective:** the A4 consumer emits a typed R endpoint exactly where the CB17 factory admits one, and nowhere else.
- **Read before work:** RA-103 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`); RA-102.4; R10B §2; S:19505-19735 and S:20476-20488; P10:7320-7406.
- **In scope:** RA-103.4 items 1–7 only (R candidate replacing the S:19628 reject; star vertex; orientation parity; sixth certificate member; route-check R anchors; #9 filter; one new test); GMP/GMPXX eight-target compile and package.
- **Out of scope:** T, I and closed behaviour; probes; factory; digest; fixture-debt tests (TQ:3017, TQ:3257, TQ:8832, RE:713, P10:7518); selectors, harnesses, workflows; any test execution.
- **Success evidence:** package with `runtimeExecution=false`; record ≤25 lines (package ID, ZIP SHA-256, source SHA); docs updated in place.
- **On success:** `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` (RA-103.5).
- **On failure/blocker:** STOP and report; any clause that cannot be implemented as written goes to Review.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB18-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` | CB, compile only; RA-103.4. |
| 2 — conditional | `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT` | Only after a clean CB18 package; artifact-only; Part A focused (14 identities), then Part B census only if the gates hold (RA-103.5). |
| 3 — mandatory | `M6-CP3-TB18-R10-RAIL-VERTEX-ENDPOINT-REV` | Review of TB18 in every case; assigns fixture debt. |
| planned, not authorized | fixture debt (242 → 174 → 250 → adjacent-sheet → 191 → 442) → census → RP-01 Review | Each CB follows a reviewed TB. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB18 consumer R emission (RA-103.4), compile only; no runtime.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. RA-103 (`Architecture_M6_CP3_TB17_Rail_Vertex_U5_Review_Decision.md`); RA-102.4 (`Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`); R10B §2 (`Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md`); S:8249-8321, S:8884-8990, S:19505-19735, S:20476-20488, H:1495-1580, P10:7320-7406; `LESSONS.md` §§2, 3, 7.
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
