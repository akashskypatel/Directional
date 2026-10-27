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
| Currency | 2026-10-27, TB46 rerun [report](Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md): immutable CB46B package `12716018703` (source `8f0d4329695d`), [run 40468913755](https://github.com/akashskypatel/Directional/actions/runs/40468913755) verified 504/504, **498 PASS / 6 registered RED**, all 497 guards and selector174 positive pass, zero control violations, harness exit0. Valid red outcome under RA-165.4; DEFN-E Review next. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | [TB46 rerun report](Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md), result artifact `12719412600`, SHA256 `2a33427b…5fd37`; logs `12719912170`, wrapper `12719462521`; 1,014/1,014 checked members, 504/504 raw process joins, postflight true. Expected E failures: 201, cp3entry:2, cp3entry:4 D5 (`:4063`); expected G: 442, focused30:12, cp3entry:1. Original run `40448739180` remains S5 invalid attempt. Last previously valid full gate TB38 490/504 candidate; no production change since. Selector497 frozen/unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached; next Review decides E (`selector:201`, `cp3entry:2`, `cp3entry:4` D5) and freezes TB47 `asserted_site` pins. G (`selector:442`, `focused30:12`, `cp3entry:1`) later. Hard-coded source-line pins remain until CB47A: prior edits must be line-neutral. Carried O1, O2 (post-RP-01), O6, O7, DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` — EXACT NEXT

- **Authority:** RA-165.4/165.5; [valid TB46 rerun](Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md), immutable result `12719412600` and 504-row frozen manifest. This is **Review + Plan**; do not edit source, tests, selector/harness or execute builds/runtime in this turn.
- **Decision scope:** E cluster: `selector:201` at `REPackageTests:715`, `cp3entry:2` at `TQTests:3154`, `cp3entry:4` later D5 at `TQTests:4063`. Reopen raw evidence, separate product defects from invalid fixtures, define corrective owner/falsifiers and freeze TB47 manifest with `asserted_site=file:line|witness` for every pinned RED/later-POSITIVE. Respect RA-164.3 P1–P6 and RA-165.2 F1/F2.
- **After Review:** CB47A harness pin migration and named CB47 corrections (as Review authorizes), then TB47; the G cluster follows separately. Stable 66/17/49 debt1, CP2 491/491, RP-01 open, selector497 unpromoted.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` | Review E using verified TB46 rerun raw evidence; freeze TB47 manifest site/witness pins. |
| 2 — conditional | `M6-CP3-CB47A-HARNESS-MANIFEST-PINS` and named `M6-CP3-CB47-…` | Only after Review decisions; TB47 requires both CB47A and CB47. |
| rule | RA-164.3 P1–P6; RA-165.2 F1/F2 | Preserve immutable CP2 authority and line-neutral edits until CB47A. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER** — reread [RA-165](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md), [valid rerun report](Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md), frozen TB46 manifest, six raw first-site logs from result artifact `12719412600`, and cluster E owner/decision history. Decide E and freeze TB47 `asserted_site` pins; runtime-free Review. No further TB46 rerun.

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
