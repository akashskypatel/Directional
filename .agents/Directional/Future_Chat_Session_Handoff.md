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
| Currency | 2026-10-25, RA-153 audits TB36-REV. The 0/5 pre-fix baseline and F1 are confirmed, and CB36 (D2) is authorized with a binding exact spec. RA-152 errata: A3 already validates `sourceEdge` (`NonReciprocalAdjacency`), and D2 does not change relation ids. TB37 is split into a focused 16-row run and a separate TB38 census. No promotion. |
| Source/package | CB35-R2 exact semantic `7de805c487fa66bcb96744f51b8bfbe7210ee8dc`; [compile run 40147720351](https://github.com/akashskypatel/Directional/actions/runs/40147720351), package `12580989509`, ZIP `a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54`; 28/28 hashes, eight GMP/GMPXX targets, `runtimeExecution=false`; no runtime/tests/benchmarks. [R2 record](Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Code_Build_Record_20261025.md). Earlier R1/CB35/CB34 packages remain in records. |
| Reviewed decision | [RA-153](Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md) accepts [TB36-REV](Architecture_M6_CP3_TB36_R1_Periodic_Monodromy_Baseline_Independent_Review_Decision_20261025.md): TB36-R1 run 40159803899, artifact `12586275698`, 0 PASS / 5 RED. It fixes CB36 to `transport()` as the first branch, with the existing locus convention and a static-only missing-transport falsifier. [RA-152](Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md) carries F1/D1–D4. [CB35-R2-REV](Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Independent_Review_20261025.md) statically accepted the witnesses. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500** (19 inherited RED); TB34 **5 PASS / 7 inherited RED** (12 measured), TB33 synthetic **6/6** only; selector497 frozen; stable **66/17/49**, debt 1. RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` — EXACT NEXT

- **Type:** Code + Build, production, compile-only. **Authority:** RA-152 D2 as specified by [RA-153.3](Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md); [plan](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Plan_20261025.md).
- **Edit (`SurfaceCellTracing.cpp:14937–14982` only):**
  - The step rotation becomes `authority::QuarterTurn stepRotation`.
  - A new **first** branch `if (transitionLookup.atlas != nullptr)` uses `atlas->transport(*sharedKey, faceCycle[index], faceCycle[(index+1)%n])->transport`.
  - A missing transport is rejected with `PeriodicHolonomyMismatch`, locus `(-1,-1,sourceFace,targetFace,-1,sourceEdge)`.
  - The legacy `else if` branches are unchanged and end in `from_integer(matching)`.
  - `TransitionStep::interior` takes `GridAutomorphism{stepRotation, {0,0}}`.
- **Out of scope:** the guard (`:15000`), action, cut route, BFS, overload, `make`, all tests (witnesses and the frozen 189–195), selectors, workflows, runtime.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`; record ≤30 lines with the exact hunk.
- **STOP → Review:** typed faces unavailable without plumbing; `transport()` not callable; any edit outside the site.
- **Preserve:** stable 66/17/49 debt 1, CP2 491/491, TB32 481/500 candidate, TB35 11/13, TB36 0/5, selector 497 frozen; RP-01 open, RP-02 unreached. `DIAG-RETAIN`, RA-152.5, RA-146.2/.4, RA-45.4 and G4-B002 stay separate.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB35 → TB35-REV (RA-151) → TB35-REV-AUDIT (RA-152) | 11/2; F1 found; D1–D4. |
| done | CB35 → REV → CB35-R1 → REV → CB35-R2 → REV | 3 witnesses; directed 32-step and reversal oracle statically accepted. |
| done | TB36 (invalid harness) → `M6-CP3-CB36-ORCH-RP01-TB36-HARNESS-CORRECTION` → TB36-R1 → TB36-REV | Valid 0/5 pre-fix baseline; F1 confirmed. |
| done | `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE-REV-AUDIT` (RA-153) | TB36-REV accepted; CB36 spec bound; RA-152 errata E1/E2; TB37 split. |
| 1 — next | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` | D2 only; compile only. |
| 2 | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT-REV` | Static; issues the TB37 16-row manifest with RA-153.4 predictions. |
| 3 | `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` → `…-REV` | 3 witnesses GREEN; TB35 189,190,193–195 + 6 controls PASS; 191/192 RED unchanged. STOP if 68 persists, 191/192 change, or a PASS regresses. |
| 4 | `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` → `…-REV` | Full 497 vs TB32 ledger; no accepted-green loss. |
| 5 | `M6-CP3-DEFN-RP01-PERIODIC-LEGACY-ORACLE-HOMES` → CB/TB | D4 + E1: 191 → A3 `NonReciprocalAdjacency`; 192 → k=1 field; 189/190 → A3-level or retired. |
| 6 | Untyped 7 (`selector:174,201,204,242,247,250,405`) → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; DEFN or diagnostic first. |
| 7 | Census → RP-01 Review | Review-owned 497(+) manifest. |
| carried | `DIAG-RETAIN` (A5–A7 diagnostic snapshots; full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | RA-152.5 axis-binding, DEFN-SEAM-NZ, Periodic follow-up, RA-146.2/4, RA-45.4, G4-B002 | After a witness / separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT** — read [RA-153](Architecture_M6_CP3_TB36_REV_Audit_Periodic_Route_Atlas_Transport_Decision_20261025.md) §3 and the [CB36 plan](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Plan_20261025.md), then `SurfaceCellTracing.cpp:14905–15004` and `:6718–6730`, and `FieldTransportAtlas::transport`. Production D2 only; compile only.

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
