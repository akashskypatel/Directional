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
| Currency | 2026-10-26, after [RA-159](Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md) (TB42-REV confirmed; selector190 vacuity found; legacy-path DEFN bound). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | Focused candidates on CB42 source `8dc8cdeae`, package `12634151125` (expires 2026-11-02T07:22:41Z): TB41 **18/18** (result `12638251384`, [TB41-REV](Architecture_M6_CP3_TB41_Rehomed_Oracle_Independent_Review_Decision_20261026.md)); TB42 **1/1** ([run 40310754811](https://github.com/akashskypatel/Directional/actions/runs/40310754811), result `12644936205`, ZIP `2d0c6cf7…b1b6`, [TB42-REV](Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Independent_Review_Decision_20261026.md)); O3 3/3. TB32 481/500 and TB38 490/504 candidate; selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. selector190 passes vacuously since `7ccdcd527` (RA-159 N2/N3). O5: 249 producer tests in no frozen gate. O6: nonrectangular bounded disks rejected by design, no owner. Carried: DIAG-RETAIN, O1, O2, O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` — EXACT NEXT

- **Authority:** [RA-159.3](Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md). Definition only; one record ≤60 lines; no source/test/selector/workflow change, no compile or runtime.
- **Answer, with file:line evidence:** (1) whether `legacyField` in 190 decides any transport or published value (helper `Phase10Tests:4490–4516`, A4 `SurfaceCellTracing.cpp:14926–14979`); (2) 190 disposition — re-home as A3 `MissingAdjacency` negative under the same identity, or retire; (3) accounting rule for an accepted-prefix identity whose original oracle is void under D1; (4) O2 inventory of every non-atlas branch (at least `:14952–14979`, `:6731ff`) with reachability class and consuming tests (incl. `Phase10Tests:5716`); (5) removal scope and affected identities; (6) at most one test-only CB (190) and one production CB (O2), each with files, assertions, STOP rules.
- **STOP → Review:** a production caller publishes without an atlas; `make(legacyField)` returns a code other than `MissingAdjacency`; a legacy branch decides a published product; the rule would alter selector497 bytes without user authorization.
- **On success:** `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION-REV`.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB42 → TB42-REV → audit ([RA-159](Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md)) | O3 3/3 focused candidate; 190 vacuity found. |
| 1 — next | `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` → `…-REV` | 190 + O2; RA-159.3 questions; design only. |
| 2 | `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` → `…-REV` | O4 (`SurfaceCellTracing.cpp:12656/12698/12707`); design only. |
| 3 | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV` | 242; coordinate DEFN-SEAM-NZ; design only. |
| 4 | Code/TB turns authorized by steps 1–3 | Their Reviews assign canonical IDs; one CB per mechanism. |
| 5 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns IDs. |
| 6 | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` → `…-REV` | O5: classify 249 off-gate producer tests. |
| 7 | Census → RP-01 Review | Review-owned manifest; must state O6 CP3 scope and owner. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O2 (step 1), O4 (step 2), O5 (step 6), O6 (step 7), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION** — design only per [RA-159.3](Architecture_M6_CP3_TB42_REV_Audit_Selector190_Vacuity_And_DEFN_Spec_Decision_20261026.md). Load `tests/SurfaceCellsPhase10Tests.cpp:4490–4516, 4561ff, 5171–5195, 5716ff`, `src/geometry/SurfaceCellTracing.cpp:6719–6745, 8455–8468, 14926–14979`, `src/authority/FieldTransportAtlas.cpp:2016–2027`, commit `7ccdcd527` and the 449 selector line 190. No compile, runtime or selector change.

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
