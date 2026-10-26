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
| Currency | 2026-10-26: [TB44](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Report_20261026.md) immutable artifact-only runtime **3 PASS / 1 RED**: positive selector405 PASS, guards 7614 and 7414 PASS, 8219 RED (expected `missing-terminal-A3-path`, actual `missing-terminal-or-closed-rail-provenance`). Valid 10/10 result hashes/postflight, no rebuild. Independent TB44-REV next; no selector/CP3 promotion. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB44 **3/4**, positive 405 PASS, guard 8219 RED; [run 40387240269](https://github.com/akashskypatel/Directional/actions/runs/40387240269), result `12680557878` (SHA-256 `f1b30006…3376b986`), [report](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Report_20261026.md). Earlier TB43 4/4, TB41 18/18, TB42 1/1; TB32 481/500, TB38 490/504 candidate; selector497 unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. Nine TB38 REDs remain: `selector:174, 201, 242, 405, 442` (accepted-prefix regressions), `focused30:12`, `cp3entry:1, 2, 4`. 405 = fixture omits A2b rail provenance (RA-161.3). P1: two off-gate negatives use the same empty default. O5: 249 off-gate producer tests. O6: nonrectangular disks unowned. Carried: DIAG-RETAIN, O1, O2 (post-RP-01, + RA-161 T2), O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY-REV` — EXACT NEXT

- **Type / authority:** independent **Review only**, following [TB44 focused report](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Report_20261026.md); never re-execute binaries or modify source/test/benchmark/selector in this Review.
- **Immutable inputs:** source `c256671115c92f7dd55fea5d680feeac3cbb5190`; compile artifact `12674401457` ZIP `38d88bbda3b6b768f1d243b9b121db6233a740d3b296ccd35a58a9d1e5932bd3`; [TB44 run](https://github.com/akashskypatel/Directional/actions/runs/40387240269), result `12680557878` ZIP SHA-256 `f1b300067c4020f0fd156b772785ee7a54b1e5deecdfcda91fb16afe3376b986`, diagnostic log `12680372908`. Four-row manifest SHA-256 `f410b55091cd8cc4fec743e141d4277662165f4feb6aa82de0590d716e5a6a8a`.
- **Independent duties:** verify package/result/checksums and four raw-log/ledger joins, source identity, exact-one test/process counts, postflight and immutable runtime boundary; determine the actual 8219 **first** rejection and whether missing provenance is an invalid fixture rather than production error. Inspect 7414's actual assertions/provenance to decide whether it discriminates or passes vacuously. Resolve RA-161 P1 with an actionable, correctly scoped follow-up and falsifier. Keep 405 focused candidate; do not infer 497-selector or CP3 promotion.
- **Preserve:** stable 66/17/49 debt1; CP2 accepted 491/491; RP-01 open, RP-02 unreached; no changes to frozen accepted selector, production, legacy recovery or tests in Review. Subsequent 242 DEFN and other queued owners begin only after completed Review authority.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB43 → REV → TB43 → REV → audit ([RA-161](Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md)); CB44 compiled | 190 re-home 4/4 focused candidate; 405 fixture correction compiled, no runtime. |
| done | `M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE-REV` | Static review accepted, four-row manifest frozen; no runtime. |
| done | `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY` | Valid artifact-only 3/4, 8219 guard RED; 405 positive PASS, no promotion. |
| 1 — next | `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY-REV` | Independent semantic/root-cause review of 8219 and 7414 P1; no runtime or edits. |
| 3 | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV` | RED 242; coordinate DEFN-SEAM-NZ; design only. |
| 4 | 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns IDs. |
| 5 | `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4); `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (O5) → REV each | No RED identity; before census. |
| 6 | Census → RP-01 Review | Review-owned manifest; must state O6 CP3 scope and owner. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT` | RA-160.4 + RA-161 T2 (discriminating fixture for identity default). |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O4/O5 (step 5), O6 (step 6), P1 (step 2), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY** — artifact-only TB. Inspect accepted [CB44-REV](Architecture_M6_CP3_CB44_Selector405_Rail_Provenance_Independent_Review_Decision_20261026.md) and exact [TB44 manifest](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Case_Manifest.tsv), consume immutable CB44 package artifact `12674401457`/source `c256671` without rebuilding; execute exactly the four manifest identities (405 POSITIVE; three off-gate GUARD), preserve raw per-case receipts and report a new first failure if RED. No selector promotion or CP3 acceptance. Mandatory successor is `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY-REV`.

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
