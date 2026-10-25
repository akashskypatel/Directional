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
| Currency | 2026-10-25: CB36 D2 source and compiled package independently accepted statically at CB36-REV, not runtime-tested; TB37 16-row manifest is the exact next authority. No CP3 or selector promotion. |
| Source/package | CB36 exact semantic `038ae7fd7c290731c28225d2693a3e13866e325a`; [compile run 40173209091](https://github.com/akashskypatel/Directional/actions/runs/40173209091), artifact `12590917524`, ZIP SHA256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`; 28/28 hashes, all eight GMP/GMPXX targets, clean source, `runtimeExecution=false`. [CB36 record](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md). |
| Reviewed decision | [RA-153](Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md) binds CB36 and CB36-REV; TB36-R1 0 PASS / 5 RED remains the pre-fix baseline. Missing transport falsifier is static-only. TB37 is focused 16 rows and TB38 is a separate census. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500** (19 inherited RED); TB35 **11/13**, TB36-R1 **0/5**; selector497 frozen; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` — EXACT NEXT

- **Type:** artifact-only focused Test + Benchmark, 16 individually selected fresh processes. No compile/relink/runtime source alteration; use only CB36's immutable package `12590917524` (semantic `038ae7fd7c290731c28225d2693a3e13866e325a`), ZIP digest `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`.
- **Manifest:** [Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Case_Manifest.tsv](Architecture_M6_CP3_TB37_Periodic_Route_Atlas_Verification_Case_Manifest.tsv) (SHA-256 `d14b24d96c66c6a2c346b60003a5697dfab1764109b45854a3f145bba70b667d`); 3 TB36 witnesses plus the unchanged 13 TB35 controls. Review authority: [Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Independent_Review_Decision_20261025.md](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Independent_Review_Decision_20261025.md) and RA-153.4.
- **Predictions:** k1/k2 GREEN rejecting A4 reason 29, directed route GREEN with ±1/inverse steps, TB35 189/190/193–195 plus six other controls PASS; frozen 191/192 remain RED unchanged. STOP to independent Review if reason 68 persists, 191/192 disposition changes, or a former PASS regresses. No missing/duplicate/skipped processes; 0 tests or crashes are orchestration errors.
- **Preserve:** stable 66/17/49 debt1; CP2 491/491, TB32 candidate 481/500, TB35 11/13, TB36 0/5, selector497 frozen; RP-01 open, RP-02 unreached. TB38 census is a **separate** successor only after TB37-REV.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB35 → TB35-REV (RA-151) → TB35-REV-AUDIT (RA-152) | 11/2; F1 found; D1–D4. |
| done | CB35 → REV → CB35-R1 → REV → CB35-R2 → REV | 3 witnesses; directed 32-step and reversal oracle statically accepted. |
| done | TB36 (invalid harness) → `M6-CP3-CB36-ORCH-RP01-TB36-HARNESS-CORRECTION` → TB36-R1 → TB36-REV | Valid 0/5 pre-fix baseline; F1 confirmed. |
| done | `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE-REV-AUDIT` (RA-153) | TB36-REV accepted; CB36 spec bound; RA-152 errata E1/E2; TB37 split. |
| done | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` | D2 only; compiled eight GMP/GMPXX targets, no runtime. |
| done | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT-REV` | Static accepted, 16-row manifest published; no runtime. |
| 1 — next | `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` → `…-REV` | 3 witnesses GREEN; TB35 189,190,193–195 + 6 controls PASS; 191/192 RED unchanged. STOP if 68 persists, 191/192 change, or a PASS regresses. |
| 4 | `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` → `…-REV` | Full 497 vs TB32 ledger; no accepted-green loss. |
| 5 | `M6-CP3-DEFN-RP01-PERIODIC-LEGACY-ORACLE-HOMES` → CB/TB | D4 + E1: 191 → A3 `NonReciprocalAdjacency`; 192 → k=1 field; 189/190 → A3-level or retired. |
| 6 | Untyped 7 (`selector:174,201,204,242,247,250,405`) → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; DEFN or diagnostic first. |
| 7 | Census → RP-01 Review | Review-owned 497(+) manifest. |
| carried | `DIAG-RETAIN` (A5–A7 diagnostic snapshots; full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | RA-152.5 axis-binding, DEFN-SEAM-NZ, Periodic follow-up, RA-146.2/4, RA-45.4, G4-B002 | After a witness / separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY** — use the verified 16-row manifest, RA-153.4 predictions and immutable package evidence; CB36 static Review [Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Independent_Review_Decision_20261025.md](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Independent_Review_Decision_20261025.md) accepted. Historical [CB36 record](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md), source hunk `SurfaceCellTracing.cpp:14934–14998`, RA-153.3/.4, `FieldTransportAtlas::transport` and the immutable package. Review only; no runtime.

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
