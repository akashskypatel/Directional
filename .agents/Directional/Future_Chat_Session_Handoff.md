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
| Currency | 2026-10-26, after [RA-158](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md) (TB41-REV confirmed; O3 owner assigned; DEFN split). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB41 focused **18/18 PASS**, candidate only: CB42 source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, package `12634151125` (ZIP `d7f7b830…8b87`, **expires 2026-11-02T07:22:41Z**), [run 40296007299](https://github.com/akashskypatel/Directional/actions/runs/40296007299), result `12638251384` (ZIP `1817f829…d854`); [report](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Report_20261026.md), [TB41-REV](Architecture_M6_CP3_TB41_Rehomed_Oracle_Independent_Review_Decision_20261026.md). TB32 481/500 and TB38 490/504 candidate; selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. O3 third locus test (`Phase10Tests:2940`) unexecuted → TB42. O5: 249 producer-binary tests are in no frozen gate (RA-158 L5). Carried: DIAG-RETAIN, O1, O2, O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY` — EXACT NEXT

- **Authority:** [RA-158.4](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md). Artifact-only Test + Benchmark; no compile.
- **Package:** CB42 artifact `12634151125`, ZIP SHA-256 `d7f7b8302966b14acd919eeef4465d518a6179f1823fbb86ad0e5b1b43488b87`, source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, 28/28. Run before **2026-11-02T07:22Z**.
- **Harness:** unchanged `tools/m6_cp3_targeted_artifact_harness.sh` (SHA-256 `436f5fff…3c9a`).
- **Manifest:** freeze and commit before dispatch; exactly one row: `POSITIVE`, `o3:polygonal-partial-phase`, `SurfaceCellsPhase10.PolygonalCurvedDiskRejectsWithoutPublishingPartialPhase`, `directional_surface_cell_producer_tests`, `PASS`.
- **STOP → Review:** package expired or hash mismatch (no recompile); harness rejects a one-row manifest (no harness edit). A RED is recorded with its first failure line and not fixed in this turn.
- **On PASS:** O3 runtime discharged as focused candidate (3/3). Successor `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY-REV`.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB39 → CB40 → CB41 → CB42 (each → REV) → TB41 → TB41-REV → audit ([RA-158](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md)) | RA-155.3 A/B/C and 250 focused candidate; O3 2/3 run. |
| 1 — next | `M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY` → `…-REV` | One POSITIVE row on package `12634151125` before it expires. |
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

`load_next`: **M6-CP3-TB42-RP01-O3-OFF-SELECTOR-LOCUS-VERIFY** — artifact-only, one POSITIVE row per [RA-158.4](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md). Load the TB41 [manifest](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Case_Manifest.tsv) as the format model, the unchanged targeted harness, CB42 package `12634151125` and `tests/SurfaceCellsPhase10Tests.cpp:2940–2958`. No compile, source, harness or selector change.

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
