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
| Currency | 2026-10-23, after the artifact-only TB29 44-case harvest; pending mandatory independent TB29-REV. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft. Semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb` (CB28A); implementation HEAD also carries dispatch/control/documentation commits. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901` / source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`; R3 **403/497** rejected. |
| Latest candidate evidence | TB29 [run 39906802267](https://github.com/akashskypatel/Directional/actions/runs/39906802267), result `12481556884`, outer ZIP SHA-256 `4e639a633a64df419f1891083911506679c6c4848f1ecbce7b206c4f5d653ae1`: **44/44** artifact-only cases, **9 PASS / 35 RED**, all 92 checksums, 44/44 manifest/log identities; no invalid or bad controls. 13 checked-factory, 8 A3, 1 A5, 13 untyped. Owning report `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md`. TB28 462/497 remains candidate only. |
| Regression accounting and debt | Stable **66/17/49**, witness debt **1**, 497-case selector frozen, RP-01 OPEN, RP-02 UNREACHED, Gate C suspended. Tracker `Regression_Root_Cause_Tracker.md`. |
| Active boundary | No causality/promotion from TB29: 13 failures retain `reason-not-observed`, factory emits `code=0`, A3/A5 failure ownership is not resolved. Independent Review must decide DEFN-M1 scope, A3 / `focused30:12` / `cp3entry:1,2` dispositions per RA-140.4; may not assume all failures share one cause. |

## Mandatory next turn — `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV` — EXACT NEXT

- **Type / owner:** Independent Review, from RA-140.4 and the TB29 plan; not a Code + Build or another TB run.
- **Objective:** independently review complete 44-case evidence and typed first-failure categories; decide DEFN-M1 exact scope, A3 atlas mismatch, `focused30:12` A5 transport, `cp3entry:1/2` fixture/witness dispositions, and untyped first failures without inferring causality.
- **Read before work:** `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md`, result artifact `12481556884` (ledger/raw logs), `Architecture_M6_CP3_TB29H_RP02_Review_Audit_Decision_20261023.md` RA-140.4, TB29 plan, TB28 reviewed inventory, tracker.
- **In scope:** independent evidence audit, root-cause adjudication, bounded DEFN-M1 ownership decision, Review documentation/consolidation and ORIENTATION update.
- **Out of scope:** correcting source, test, harness, manifest, selector; compile, rerun or benchmark; unreviewed promotion of 497-case CP3.
- **Success evidence:** independently reproduced 44-case/control/hash partition and decisions for factory, A3, A5, untyped and witness gaps; Review findings and updated records. Preserve stable counts unless independently justified.
- **On success:** assign precise authorized DEFN-M1 successor only through this Review; otherwise `UNKNOWN — STOP`.
- **On failure/blocker:** stop, preserve evidence, no speculative corrective turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|
| 1 — next | `M6-CP3-TB29-RP01-TYPED-FACTORY-CAUSE-HARVEST-REV` | Mandatory independent Review of TB29 immutable evidence; scope DEFN-M1, decide A3/A5 and fixture debts. |
| later — UNKNOWN until assigned | DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review | Planned only; separate Review authorizes each edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` A5–A7 snapshots for GUI/CLI | Planned user-directed work; Review schedules clear of RP-01 path. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — independent TB29-REV of the verified 44-case artifact-only result; no code/build/test.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md` and result artifact `12481556884` (44 logs); `Architecture_M6_CP3_TB29H_RP02_Review_Audit_Decision_20261023.md` RA-140.4; `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Plan_20261022.md`; TB28 reviewed RED inventory.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats.

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
