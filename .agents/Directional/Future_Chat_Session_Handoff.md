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
| Currency | 2026-10-23, after the audit of the TB29 review (RA-142). TB29's evidence and RA-141's partition are upheld. Corrected: M1 is RA-105.3's **ten** rows. Six are measured at `certificate-pair-binding`. `selector:211/219` (wrong `oppositeEdge`; actual code 0 = `InvalidSourceAuthority`) and `selector:227/230` (wrong `route`; any factory rejection reported as `InvalidPhaseFrontProduct`) are statically proven to reach the same clause (SCT:8833–8837) before `InvalidOppositeEdge` (SCT:9350). They are M1's frozen-precedence oracles, so DEFN-M1 covers all ten. |
| Working branch / semantic source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open. CB28A semantic source `4473e41e94a35f1bf189fa046e86bac92c7391fb`. |
| Accepted vs candidate | CP2 491/491 accepted. R3 403/497 rejected; TB28 462/497 candidate only. Selector 497 byte-frozen. |
| TB29 evidence | [run 39906802267](https://github.com/akashskypatel/Directional/actions/runs/39906802267), artifact `12481556884`, ZIP SHA-256 `4e639a633a64df419f1891083911506679c6c4848f1ecbce7b206c4f5d653ae1`; 44/44, 9 PASS/35 RED, 92/92 checksums, 44/44 log/manifest identity matches. |
| Independently reviewed partition | RA-141: six R2 certificate-pair M1 first failures, six earlier face-gauge missing, one open-rail-chain; A3 eight (7 cycle + 1 singularity), A5 one, untyped thirteen. Cause not extrapolated. |
| Accounting | Stable 66/17/49; debt 1; RP-01 open, RP-02 unreached, Gate C suspended. |

## Mandatory next turn — `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` — EXACT NEXT

- **Type / owner:** DEFN (documents only); implementation agent. Authority: RA-141 (`Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Review_Decision_20261023.md`) as amended by RA-142 (`Architecture_M6_CP3_TB29_Review_Audit_Decision_20261023.md`); plan `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Plan_20261023.md` (annotated by RA-142).
- **Objective:** a precedence and ownership contract under which each of the ten M1 tampers is rejected first by the owner and with the typed code that its frozen test names, without weakening the A4 certificate binding.
- **Read before work:**
  - RA-142 (all), RA-141.1, RA-105.3; RA-15.2–15.4 and RA-19.1 (`Architecture_M6_Frozen_Definitions.md`);
  - the TB29 report `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md`;
  - SCT:8439 (`SurfacePhaseFrontProduct::make`), SCT:8814–8841 (R2 binding), SCT:9350 (`InvalidOppositeEdge`);
  - the ten tests: TQ `focused30:3, 22, 23`, TQ:9049, 9067, 10146, 10189; SP10 `selector:139/140/142`; TQ:2551 (`materialize`).
- **In scope:** write `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_20261023.md` (at most 100 lines, anchored at HEAD):
  1. a clause audit of the factory validation order and the downstream A5 and pipeline owners the tests expect;
  2. a ten-row ownership matrix (tamper; frozen expected code and owner; reached clause, measured or static; proposed first clause);
  3. the chosen option (a) structural-first, (b) field-specific binding codes, or (c) A5-owned checks leave A4, with its rationale traced to RA-15/RA-19/RA-105.3;
  4. a non-weakening table (forged or absent certificate, wrong rail, reversed route, same region all still reject, with the clause named);
  5. corrective-TB predictions and falsifiers (ten rows reach their frozen outcomes; seven non-M1 factory rows unchanged; nine TB29 controls PASS);
  6. the exclusions, each with its owner.
- **Out of scope:** any code, test, fixture, selector or runtime change; changing test expectations; the face-gauge, A3, A5 `focused30:12` and D2 work.
- **Success evidence:** the contract committed with all six parts; STATUS COMPLETE.
- **On success:** `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE-REV` (Review, mandatory); it scopes the corrective CB.
- **On failure/blocker:** STOP and return to Review if no option satisfies all ten frozen expectations without a test change or a disabled guard.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE` | DEFN, documents only, ten-row scope (RA-142.4). |
| 2 — conditional | `M6-CP3-DEFN-M1-RP01-CERTIFICATE-PAIR-BINDING-PRECEDENCE-REV` | Review, only after step 1 completes: adjudicates the contract; scopes the corrective CB. |
| later — UNKNOWN until assigned | corrective CB (product; scoped by DEFN-M1-REV) → CB-REV → TB (10 M1 rows + 7 non-M1 factory rows + 9 TB29 controls; targeted harness with a Review-owned manifest) → TB-REV → owners for face-gauge-missing (6), A3 cycle locus (7) and `selector:442`, A5 `focused30:12` (each DEFN or diagnostic first) → DEFN-T1 (`cp3entry:1/2`) → fixture debt → census (needs an RA-139.3-compliant harness) → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **plan** — DEFN-M1: ten-row certificate-pair-binding precedence contract (RA-141, RA-142); documents only.

Minimum next context after mandatory start/policies:

0. `.agents/Directional/ORIENTATION.md`; `.agents/Directional/ROADMAP.md`.
1. `.agents/Directional/Future_Chat_Session_Handoff.md` and `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Plan_20261023.md`.
2. RA-141 review and TB29 raw result artifact `12481556884`; RA-140.4; RA-105.3; TB28 RED inventory.
3. `Architecture_M6_CP3_TB29_Review_Audit_Decision_20261023.md` (RA-142: ten-row M1 scope, static proofs, design question, deliverables); `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Review_Decision_20261023.md` (RA-141); `Architecture_M6_CP3_TB29_Typed_Factory_Cause_Harvest_Report_20261023.md`; `Architecture_M6_CP3_DEFN_M1_Certificate_Pair_Binding_Precedence_Plan_20261023.md`.
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
