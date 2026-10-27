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
| Currency | 2026-10-27, CB46B test-fixture correction compiled under [RA-165](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md); two historically invalid selector174 `TriMesh` fixtures corrected line-neutrally. [CB46B record](Architecture_M6_CP3_CB46B_Selector174_Manifold_Fixture_Code_Build_Record_20261027.md): source `8f0d4329695d`, package `12716018703`, GMP/GMPXX, no runtime; TB46 full gate is next. RA-164.3 P1–P6 and RA-165.2 F1/F2 bind. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | CB46B [compile-only run 40466255947](https://github.com/akashskypatel/Directional/actions/runs/40466255947) GREEN; eight targets, package `12716018703`, no runtime. Earlier: TB46 run `40448739180` on CB46 package `12708707491`: 504/504 processes, 497 PASS / 7 RED, **invalid attempt (S5)** ([report](Architecture_M6_CP3_TB46_Full_Gate_Test_Benchmark_Report_20261027.md)); 497 GUARD green, 5 pinned REDs at pins, 174 uncaught DCEL exception, cp3entry:4 later `TQTests:4063`. TB46A harness compile run `40457083585` ([record](Architecture_M6_CP3_TB46A_Orchestration_Correction_Compile_Record_20261027.md)). Last valid full gate TB38 **490/504** candidate (`038ae7fd7`); no production change since. Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. TB46 re-run predicted **498/6**: RED `selector:201`, `selector:442`, `focused30:12`, `cp3entry:1`, `cp3entry:2` at pins; cp3entry:4 RED at registered `:4063` (cluster E, D5); 174 PASS. Harness pins are hard-coded `file:line` until CB47A → edits above pinned lines must be line-neutral. Carried: O1, O2 (post-RP-01, + RA-161 T2), O6, **O7** (oracle-tests target non-compiling, RP-01 decides owner), DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-TB46-RP01-FULL-GATE` — EXACT NEXT

- **Authority:** [RA-165.4](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md), artifact-only full-gate 504-case test/benchmark re-run on CB46B immutable package `12716018703` (source `8f0d4329695de1c7542ea240e30e55761acc3a38`). Do not rebuild, modify test source, selectors, harness, manifest, or repair package bytes.
- **Frozen:** harness `5e6de03fa` (SHA256 `37b01215…b0af72`) and case manifest (SHA256 `717f4f0f…6bb087`); expected 498 PASS / 6 RED, not acceptance. CP2 491/491 and 66/17/49 debt1 unchanged.
- **Outcomes:** harness exit 0 with expected behavior → `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review); any unregistered failure / guard failure / 174 red → `M6-CP3-TB46-RP01-FULL-GATE-REV`; orchestration / package failure → `M6-CP3-TB46B-ORCH`, per RA-165.4 and cadence rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB46-RP01-FULL-GATE` | Artifact-only on CB46B package `12716018703`; apply RA-165.4 outcome table. |
| 2 — conditional | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` | On permitted TB46 exit-0 outcomes; otherwise TB46-REV or TB46B-ORCH as RA-165.4 specifies. |
| rule | RA-164.3 P1–P6; RA-165.2 F1/F2 | No new source edits above harness pins until CB47A; subsequent schedule retained in `TODO.md`. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB46-RP01-FULL-GATE** — read [RA-165.4](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md), [CB46B record](Architecture_M6_CP3_CB46B_Selector174_Manifold_Fixture_Code_Build_Record_20261027.md), frozen TB46 504-row manifest and harness. Exact package `12716018703` from source `8f0d4329695de1c7542ea240e30e55761acc3a38`; immutable artifact-only execution, no compile/relink/repair.

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
