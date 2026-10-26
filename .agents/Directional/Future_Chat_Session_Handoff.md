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
| Currency | 2026-10-26, after [RA-161](Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md) (TB43-REV confirmed; selector405 root-caused to fixture rail provenance; O4 demoted behind the REDs). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB43 **4/4** on CB43 source `d354d6ae9`, package `12657932087` ([run 40353956056](https://github.com/akashskypatel/Directional/actions/runs/40353956056), result `12664712967`, ZIP `fbe75000…26804`, [TB43-REV](Architecture_M6_CP3_TB43_Selector190_Rehome_Independent_Review_Decision_20261026.md)). Earlier focused: TB41 18/18, TB42 1/1 (O3 3/3). TB32 481/500 and TB38 490/504 candidate; selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. Nine TB38 REDs remain: `selector:174, 201, 242, 405, 442` (accepted-prefix regressions), `focused30:12`, `cp3entry:1, 2, 4`. 405 = fixture omits A2b rail provenance (RA-161.3). P1: two off-gate negatives use the same empty default. O5: 249 off-gate producer tests. O6: nonrectangular disks unowned. Carried: DIAG-RETAIN, O1, O2 (post-RP-01, + RA-161 T2), O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE` — EXACT NEXT

- **Authority:** [RA-161.4](Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md). Test-only Code+Build, compile only; edit only the body of `FixedConformityPlanTargetPerturbationPreservesSharedBoundaryIntervals` (`tests/SurfaceCellsPhase10Tests.cpp:7583–7609`).
- **Change:** derive `provenance = directional::pipeline::hard_rail_source_provenance_from_rails(fixture.rails, V.rows())`, `ASSERT_TRUE(provenance.has_value())`; pass `&provenance->terminalContacts, nullptr, &provenance->closedChains` to both the 0.5 and 2.0 helper calls. Keep every existing assertion and message.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, record ≤30 lines with the exact hunk.
- **STOP → Review:** symbol not visible; helper change needed; selector bytes would change. A runtime rejection after the fix is a TB44 finding, not a CB fix.
- **On success:** `M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE-REV` (static; issues TB44 manifest).

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB43 → REV → TB43 → REV → audit ([RA-161](Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md)) | 190 re-home 4/4 focused candidate; 405 root-caused. |
| 1 — next | `M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE` → `…-REV` | Test-only, one test body; REV issues TB44 manifest. |
| 2 | `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY` → `…-REV` | Artifact-only, CB44 package: 405 POSITIVE; GUARD `Phase10Tests:7614/7414/8219` companions (off-gate). REV disposes P1. |
| 3 | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV` | RED 242; coordinate DEFN-SEAM-NZ; design only. |
| 4 | 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns IDs. |
| 5 | `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4); `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (O5) → REV each | No RED identity; before census. |
| 6 | Census → RP-01 Review | Review-owned manifest; must state O6 CP3 scope and owner. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT` | RA-160.4 + RA-161 T2 (discriminating fixture for identity default). |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O4/O5 (step 5), O6 (step 6), P1 (step 2), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE** — test-only per [RA-161.4](Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md). Load `tests/SurfaceCellsPhase10Tests.cpp:6981–7028` (fixture), `7099–7132` (fixed-plan helper), `7583–7609` (405), `include/directional/pipeline/RemeshPipeline.h:1863–1871`, `src/pipeline/RemeshPipeline.cpp:12775–12782`. Compile only; no helper, production, selector, harness or workflow change.

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
