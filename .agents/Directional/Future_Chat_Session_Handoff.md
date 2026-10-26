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
| Currency | 2026-10-26, after CB43 compile-only test re-home ([record](Architecture_M6_CP3_CB43_Selector190_Legacy_Ingress_Rehome_Code_Build_Record_20261026.md)); RA-160.3 remains Review-gated. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | Focused candidates on CB42 source `8dc8cdeae`, package `12634151125` (expires 2026-11-02T07:22:41Z): TB41 **18/18** (result `12638251384`, [TB41-REV](Architecture_M6_CP3_TB41_Rehomed_Oracle_Independent_Review_Decision_20261026.md)); TB42 **1/1** ([run 40310754811](https://github.com/akashskypatel/Directional/actions/runs/40310754811), result `12644936205`, ZIP `2d0c6cf7…b1b6`, [TB42-REV](Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Independent_Review_Decision_20261026.md)); O3 3/3. TB32 481/500 and TB38 490/504 candidate; selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. selector190 test re-home compiled in CB43, runtime unmeasured and awaiting independent Review; historical vacuity since `7ccdcd527` is not retroactively cured. No-atlas ingress still publishes legacy-decided seed-fallback outputs on NotApplicable inputs (RA-160 D2; test-only ingress). O5: 249 producer tests in no frozen gate. O6: nonrectangular bounded disks rejected by design, no owner. Carried: DIAG-RETAIN, O1, O2 (post-RP-01), O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-CB43-RP01-SELECTOR190-LEGACY-INGRESS-REHOME-REV` — EXACT NEXT

- **Type / owner:** Independent Review, per [RA-160.3](Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md).
- **Objective:** independently inspect exact CB43 test-only hunk, A2/A3 negative+anti-vacuity, A4 no-atlas pin, and immutable GMP/GMPXX compile artifact. Assess non-vacuity and ensure no other source/test or selector changes.
- **Evidence:** [CB43 record](Architecture_M6_CP3_CB43_Selector190_Legacy_Ingress_Rehome_Code_Build_Record_20261026.md), source `d354d6ae95afc73df968fc5cc4ee69fe5b7de451`; [compile 40338106985](https://github.com/akashskypatel/Directional/actions/runs/40338106985), package `12657932087`, 28/28 hashes and eight targets, `runtimeExecution=false`.
- **Boundary:** static Review only. Do not run binaries, modify selector497 or promote CP3. A4 runtime locus is unmeasured until separate TB43.
- **On success:** issue the frozen manifest for `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY` (190 POSITIVE, GUARD selector28/179/233); no Test+Benchmark execution in Review.
- **On failure:** record exact static finding and corrective owner; no speculative successor.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | Legacy-path DEFN → REV ([RA-160](Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md)) | Q1–Q3 accepted (Q2 amended); Q4–Q5 incomplete; O2 production CB withdrawn. |
| done | `M6-CP3-CB43-RP01-SELECTOR190-LEGACY-INGRESS-REHOME` | Test-only hunk compiled, no runtime; exact record above. |
| 1 — next | `M6-CP3-CB43-RP01-SELECTOR190-LEGACY-INGRESS-REHOME-REV` | Static review; issue TB43 manifest only on acceptance. |
| 2 | `M6-CP3-TB43-RP01-SELECTOR190-REHOME-VERIFY` → `…-REV` | Artifact-only, CB43 package: 190 POSITIVE; GUARD `selector:28/179/233`. |
| 3 | `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` → `…-REV` | O4 (`SurfaceCellTracing.cpp:12656/12698/12707`); design only. |
| 4 | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV` | 242; coordinate DEFN-SEAM-NZ; design only. |
| 5 | Code/TB turns authorized by steps 3–4 | Their Reviews assign canonical IDs; one CB per mechanism. |
| 6 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns IDs. |
| 7 | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` → `…-REV` | O5: classify 249 off-gate producer tests. |
| 8 | Census → RP-01 Review | Review-owned manifest; must state O6 CP3 scope and owner. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT` | RA-160.4: NotApplicable seed fallback, crossField overloads, detail consumers (179, 233, `Phase10Tests:489–611, 5716`), entry-gate vs factory locus. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O4 (step 3), O5 (step 7), O6 (step 8), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB43-RP01-SELECTOR190-LEGACY-INGRESS-REHOME-REV** — independent static Review per [RA-160.3](Architecture_M6_CP3_DEFN_Legacy_Matching_Path_Disposition_Review_Decision_20261026.md). Load `tests/SurfaceCellsPhase10Tests.cpp:4490–4516` (A2/A3 helper), `4561–4599` (legacy field), `5171–5195` (190), `include/directional/geometry/SurfaceCellTracing.h:1866–1885, 2147–2170` (failure fields/accessors), `src/authority/FieldTransportAtlas.cpp:1981–2018`, `src/geometry/SurfaceCellTracing.cpp:8459–8470, 13185–13200, 21175–21192`. Verify CB43 record, exact compiled source and RA-160.3 oracle scope; no runtime, production, selector, harness or workflow change.

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
