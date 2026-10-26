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
| Currency | 2026-10-26: [TB44](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Report_20261026.md) immutable artifact-only runtime **3 PASS / 1 RED**: positive selector405 PASS, guards 7614 and 7414 PASS, 8219 RED (expected `missing-terminal-A3-path`, actual `missing-terminal-or-closed-rail-provenance`). Valid 10/10 result hashes/postflight, no rebuild. [TB44-REV](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Independent_Review_Decision_20261026.md) independently confirms 8219 fixture failure and 7414 incomplete network guard; RA-161 P1 carried to O5. Next 242 DEFN; no selector/CP3 promotion. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB44 **3/4**, positive 405 PASS, guard 8219 RED; [run 40387240269](https://github.com/akashskypatel/Directional/actions/runs/40387240269), result `12680557878` (SHA-256 `f1b30006…3376b986`), [report](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Report_20261026.md). Earlier TB43 4/4, TB41 18/18, TB42 1/1; TB32 481/500, TB38 490/504 candidate; selector497 unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. Nine TB38 REDs remain: `selector:174, 201, 242, 405, 442` (accepted-prefix regressions), `focused30:12`, `cp3entry:1, 2, 4`. 405 = fixture omits A2b rail provenance (RA-161.3). P1: 8219 invalid missing-contact fixture; 7414 negative not differential for network-binding. O5 owns corrective Definition and separately gated test-only CB/TB/REV. O5: 249 off-gate producer tests. O6: nonrectangular disks unowned. Carried: DIAG-RETAIN, O1, O2 (post-RP-01, + RA-161 T2), O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` — EXACT NEXT

- **Type / authority:** Definition/Plan only, source-grounded analysis of accepted-prefix RED `selector:242`, coordinated with carried DEFN-SEAM-NZ. No implementation, build, test or selector mutation in Definition. Independent Review successor required before any Code + Build work.
- **Evidence:** TB44-REV is completed on immutable CB44 source and artifacts; focused selector405 passes but selector497/CP3 is not promoted. Its independent decision documents RA-161 P1: 8219 invalid negative precondition and 7414 network-discrimination gap; O5 owns separately bounded correction before census. Do not re-open these off-gate negatives in 242 scope.
- **Falsifiers/stop:** identify the exact earliest 242 production/consumer failure and its accepted-source authority; stop if existing evidence cannot show a reachable cross-region seam consumer, if ownership conflicts with DEFN-SEAM-NZ, or if a proposed witness could pass without consuming the tampered authority. Freeze one bounded corrective plan only after independent oracles are specified.
- **Preserve:** stable 66/17/49 debt1, CP2 accepted 491/491, RP-01 open and RP-02 unreached. O1/O2/O4/O5/O6/DIAG-RETAIN and other carried duties retain separate owners.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB43 → REV → TB43 → REV → audit ([RA-161](Architecture_M6_CP3_TB43_REV_Audit_Selector405_Fixture_Provenance_Decision_20261026.md)); CB44 compiled | 190 re-home 4/4 focused candidate; 405 fixture correction compiled, no runtime. |
| done | `M6-CP3-CB44-RP01-SELECTOR405-FIXED-PLAN-RAIL-PROVENANCE-REV` | Static review accepted, four-row manifest frozen; no runtime. |
| done | `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY` | Valid artifact-only 3/4, 8219 guard RED; 405 positive PASS, no promotion. |
| done | `M6-CP3-TB44-RP01-SELECTOR405-FIXED-PLAN-VERIFY-REV` | [TB44-REV](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Independent_Review_Decision_20261026.md) mechanical 3/4 confirmed; 8219 first rejection invalid fixture, 7414 guard not network-discriminating; P1 carried to O5. |
| 1 — next | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → `…-REV` | RED 242; coordinate DEFN-SEAM-NZ; design only. |
| 4 | 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns IDs. |
| 5 | `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4); `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (O5) → REV each | No RED identity; before census. |
| 6 | Census → RP-01 Review | Review-owned manifest; must state O6 CP3 scope and owner. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT` | RA-160.4 + RA-161 T2 (discriminating fixture for identity default). |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O4/O5 (step 5), O6 (step 6), P1 (step 2), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER** — Definition only. Read the latest 242 accepted-prefix failure, prior seam authority definitions/DEFN-SEAM-NZ, and TB44-REV decision, then freeze source-grounded producer/consumer contracts, independent non-vacuous witness, falsifiers and bounded corrective scope. No runtime or code changes in DEFN. Maintain the O5 owner for RA-161 P1 and do not treat focused 405 as accepted selector497 or CP3. Successor requires independent DEFN-REV.

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
