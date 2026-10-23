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
| Currency | 2026-10-23, after the DEFN-M1 architecture review (RA-143). The blocked DEFN-M1 contract is accepted, and its open question is resolved. A4 keeps certificate **authenticity** (RA-40.1). Edge-to-certificate **association** (opposite edge, rail id, route, region) belongs to A5 under RA-15/RA-16 §5. A5 already enforces it in the frozen order (RP:4904–4925, then the certificate lookup at RP:5040–5051) and is its only consumer. No passing test depends on A4 doing the association. CB29 removes those five predicates from A4's pair clause. |
| Working branch / semantic source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open. CB28A semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb`. |
| Accepted vs candidate | CP2 491/491 accepted. R3 403/497 rejected; TB28 462/497 candidate only. Selector 497 byte-frozen. |
| TB29 evidence | [run 39906802267](https://github.com/akashskypatel/Directional/actions/runs/39906802267), artifact `12481556884`, ZIP SHA-256 `4e639a633a64df419f1891083911506679c6c4848f1ecbce7b206c4f5d653ae1`; 44/44, 9 PASS/35 RED, 92/92 checksums, 44/44 log/manifest identity matches. |
| Independently reviewed partition | RA-141: six R2 certificate-pair M1 first failures, six earlier face-gauge missing, one open-rail-chain; A3 eight (7 cycle + 1 singularity), A5 one, untyped thirteen. Cause not extrapolated. |
| Accounting | Stable 66/17/49; debt 1; RP-01 open, RP-02 unreached, Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP` — EXACT NEXT

- **Type / owner:** Code + Build, compile only; implementation agent. Authority: RA-143.3 (`Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Review_Decision_20261023.md`), on the accepted contract `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md`.
- **Objective:** let each of the ten M1 tampers reach its frozen owner, by moving edge-to-certificate association out of A4's pair clause. A5 already enforces it.
- **Read before work:** RA-143 (all); the DEFN-M1 contract §§1–4; SCT:8814–8960 (certificate loop); SCT:≈9331–9353 (`InvalidOppositeEdge`); RP:4904–4925 and 5040–5051 (A5 checks); RA-15 and RA-16 §5.
- **In scope** (`src/geometry/SurfaceCellTracing.cpp` only): in the pair clause (SCT:8831–8841):
  1. remove `first.oppositeEdge != certificate.secondFrontEdge`, `second.oppositeEdge != certificate.firstFrontEdge`, both `railId` comparisons, `first.route != certificate.route`, `second.route != certificate.route.reversed()`, and `first.sourceTopologyRegion == second.sourceTopologyRegion`;
  2. keep both `HardRail` kind checks with site `certificate-pair-binding`;
  3. add one comment citing RA-15/RA-16 §5/RA-143 (A4 authenticates, A5 associates).

  Lines at most 100 columns.
- **Out of scope:** RP/A5 (it already enforces), headers, tests, selectors, workflows; any other A4 clause; runtime.
- **Success evidence:**
  - a diff confined to that clause plus the comment;
  - eight targets compile with GMP/GMPXX, `runtimeExecution=false`;
  - record `Architecture_M6_CP3_CB29_A4_Certificate_Association_Ownership_Code_Build_Record_20261023.md` (at most 30 lines) with the hunk, package id and hashes;
  - STATUS COMPLETE.
- **On success:** `M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP-REV` (Review, mandatory): static diff check; issues the TB30 manifest (RA-143.4).
- **On failure/blocker:** STOP and return to Review if a later clause in the same loop reads a removed field assuming it was bound, or if any edit outside the clause is needed.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP` | Code + Build, compile only (RA-143.3): remove the five association predicates from A4's pair clause. |
| 2 — conditional | `M6-CP3-CB29-RP01-A4-CERTIFICATE-ASSOCIATION-OWNERSHIP-REV` | Review, only after step 1 completes: static diff check; issues the TB30 manifest. |
| later — UNKNOWN until assigned | TB30 (targeted harness `436f5fff…c9a`; Review-owned manifest: 10 M1 rows expected PASS, 7 non-M1 factory rows expected unchanged RED, 9 TB29 controls, 3 certificate-authenticity guards; RA-143.4) → TB30-REV → owners for face-gauge-missing (6), A3 cycle locus (7) / `selector:442`, A5 `focused30:12` → DEFN-T1 (`cp3entry:1/2`) → fixture debt → census (RA-139.5 harness) → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB29: SCT-only removal of five association predicates from A4's certificate pair clause (RA-143.3); compile only.

Minimum next context after mandatory start/policies:

0. `.agents/Directional/ORIENTATION.md`; `.agents/Directional/ROADMAP.md`.
1. `.agents/Directional/Future_Chat_Session_Handoff.md` and `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Plan_20261023.md`.
2. RA-141 review and TB29 raw result artifact `12481556884`; RA-140.4; RA-105.3; TB28 RED inventory.
3. `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Review_Decision_20261023.md` (RA-143: owner split, predicate table, CB29 scope, TB30 plan); `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md` (accepted contract); `Architecture_M6_CP3_TB29_Review_Audit_Decision_20261023.md` (RA-142).
4. Review helpers in `.agents/Directional/tools/` for independent evidence. Do not interpret a synthetic snapshot's git-history checks as authoritative.

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
