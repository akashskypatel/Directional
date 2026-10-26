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
| Currency | 2026-10-26, after [selector242 DEFN](Architecture_M6_CP3_DEFN_Selector242_Cross_Region_Seam_Consumer_Decision_20261026.md) (A3 reciprocal-by-construction; A4 certificate is the consumption owner; A3 mutated-field result not executed; independent DEFN Review required). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB44 **3/4** on CB44 source `c25667111` ([run 40387240269](https://github.com/akashskypatel/Directional/actions/runs/40387240269), result `12680557878` SHA-256 `f1b30006…6b986`, 11/11 members, [report](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Verification_Report_20261026.md), [TB44-REV](Architecture_M6_CP3_TB44_Selector405_Fixed_Plan_Independent_Review_Decision_20261026.md)): 405 PASS, guards 7614/7414 PASS, 8219 RED. Earlier focused: TB43 4/4, TB41 18/18, TB42 1/1. TB32 481/500, TB38 490/504 candidate; selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. Nine TB38 REDs stay counted until a complete gate: `selector:174, 201, 242, 405` (focused PASS), `442`, `focused30:12`, `cp3entry:1, 2, 4`. 242 = mutation never consumed by atlas-bound A4 (RA-162 F4). O5 carries P1-a (re-scoped: production-reachable witness), P1-b, RA-162 C1 (hard-edge/rail cover asymmetry). O6 unowned nonrectangular disks. Carried: DIAG-RETAIN, O1, O2 (post-RP-01, + RA-161 T2), O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER-REV` — EXACT NEXT

- **Authority:** [RA-162.4](Architecture_M6_CP3_TB44_REV_Audit_P1_Torn_Input_Selector242_Scope_Decision_20261026.md) and [completed definition](Architecture_M6_CP3_DEFN_Selector242_Cross_Region_Seam_Consumer_Decision_20261026.md), with [CB45 specification](Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Specification_20261026.md). Independent static Review only: no code, build, runtime or selector changes.
- **Review decision:** confirm static D1/A3 versus A4 owner; D2 A3 runtime not observed, branch A only on independently proven typed seam/cycle edge and branch B only on production-derived fixture; decide semantic reachability or STOP without fake positive.
- **On acceptance:** CB45 test-only compile-only; keep TB45 242 POSITIVE, sibling `Phase10Tests:3270` GUARD; independent CB45/TB45 Reviews required.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB44 → REV → TB44 → REV → audit ([RA-162](Architecture_M6_CP3_TB44_REV_Audit_P1_Torn_Input_Selector242_Scope_Decision_20261026.md)) | 405 focused PASS; 8219 RED is a stale torn-input fixture; P1 to O5. |
| 1 — next | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER-REV` | Independent review of D1–D4 decision, branch reachability and CB45 spec before test changes. |
| 2 | `M6-CP3-CB45-RP01-SELECTOR242-SEAM-REHOME` → `…-REV` | Test-only, compile only, per DEFN; REV issues TB45 manifest. |
| 3 | `M6-CP3-TB45-RP01-SELECTOR242-SEAM-REHOME-VERIFY` → `…-REV` | Artifact-only: 242 POSITIVE; GUARD `Phase10Tests:3270`. |
| 4 | 174 → 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns IDs. |
| 5 | `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` (O4); `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (O5 + P1-a/P1-b + RA-162 C1) → REV each | No RED identity; before census; separate test-only CB/TB/REV for P1. |
| 6 | Census → RP-01 Review | Review-owned manifest; must state O6 CP3 scope and owner. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT` | RA-160.4 + RA-161 T2. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O4/O5/P1/C1 (step 5), O6 (step 6), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER-REV** — independently review [242 decision](Architecture_M6_CP3_DEFN_Selector242_Cross_Region_Seam_Consumer_Decision_20261026.md) and [CB45 spec](Architecture_M6_CP3_CB45_Selector242_Seam_Rehome_Specification_20261026.md) against RA-162.4, `FieldTransportAtlas.cpp:1981–2045,2479–2518,2581–2589`, `SurfaceCellTracing.cpp:18052–18214,19215–19230,21174–21192`, and `Phase10Tests.cpp:3270–3391`. Review/authorization only; no source mutation, build or runtime.

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
