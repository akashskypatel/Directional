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
| Currency | 2026-10-26, after TB42 focused runtime (1/1 PASS), pending TB42-REV; [RA-158](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md) (TB41-REV confirmed; O3 owner assigned; DEFN split). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB41 focused **18/18 PASS**, candidate only: CB42 source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, package `12634151125` (ZIP `d7f7b830…8b87`, **expires 2026-11-02T07:22:41Z**), [run 40296007299](https://github.com/akashskypatel/Directional/actions/runs/40296007299), result `12638251384` (ZIP `1817f829…d854`); [report](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Report_20261026.md), [TB41-REV](Architecture_M6_CP3_TB41_Rehomed_Oracle_Independent_Review_Decision_20261026.md). TB32 481/500 and TB38 490/504 candidate; selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. O3 third locus test (`Phase10Tests:2940`) ran 1/1 PASS as candidate → TB42-REV. O5: 249 producer-binary tests are in no frozen gate (RA-158 L5). Carried: DIAG-RETAIN, O1, O2, O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY-REV` — EXACT NEXT

- **Authority:** RA-158.4; independent Review of completed artifact-only TB42 focused candidate.
- **Evidence:** [TB42 report](Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Verification_Report_20261026.md); run `40310754811`, result artifact `12644936205` (ZIP SHA-256 `2d0c6cf7ab7e1eb7321f1adf0720e5ea2fd585c6762e9458de03c4f260d9b1b6`); raw log one RUN/one OK, 1/1 PASS, postflight true.
- **Review:** independently verify exact source/package/manifest/harness and result hashes, raw single-test selection, first-locus assertions and non-vacuity; assess O3 3/3 focused candidate without promoting selector497 or CP3.
- **Next after Review:** follow RA-158 split DEFN ordering; do not start DEFN work in TB42 or its Review without separate authority.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB39 → CB40 → CB41 → CB42 (each → REV) → TB41 → TB41-REV → audit ([RA-158](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md)) | RA-155.3 A/B/C and 250 focused candidate; O3 2/3 run. |
| 1 — next | `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY-REV` | Independently review 1/1 O3 PASS; source/package unchanged; no selector/CP3 promotion. |
| 2 | `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` → `…-REV` | 190 + O2; accepted-prefix accounting rule; design only. |
| 3 | `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` → `…-REV` | O4 (`SurfaceCellTracing.cpp:12656/12698/12707`); design only. |
| 4 | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV` | 242; coordinate DEFN-SEAM-NZ; design only. |
| 5 | Code/TB turns authorized by steps 2–4 | Their Reviews assign canonical IDs. |
| 6 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns IDs. |
| 7 | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` → `…-REV` | O5: classify the 249 off-gate producer tests; freeze supplemental census rows. |
| 8 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O2 (step 2), O3 (step 1), O4 (step 3), O5 (step 7), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. Superseded: `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES`. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY-REV** — independently review one POSITIVE row from TB42 per [RA-158.4](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md). Use [TB42 report](Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Verification_Report_20261026.md), frozen TB42 manifest, result artifact `12644936205`, unchanged targeted harness and `tests/SurfaceCellsPhase10Tests.cpp:2940–2958`; re-derive raw evidence and non-vacuity without compile or source changes.

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
