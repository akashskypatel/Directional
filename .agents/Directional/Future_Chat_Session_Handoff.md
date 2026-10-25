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
| Currency | 2026-10-25: RA-154 audit. TB37-REV is accepted, but its TB38 hand-off is replaced by a Review-owned 504-row manifest with per-row predictions. The tamper-oracle family is reclassified (adds 204, 242, 247). CP3 and the selector stay unpromoted. |
| Source/package | CB36 exact semantic `038ae7fd7c290731c28225d2693a3e13866e325a`; [compile run 40173209091](https://github.com/akashskypatel/Directional/actions/runs/40173209091), artifact `12590917524`, ZIP SHA256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`; 28/28 hashes, all eight GMP/GMPXX targets, clean source, `runtimeExecution=false`. [CB36 record](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md). |
| Reviewed decision | [RA-154](Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md) independently re-verified TB37: 21/21 hashes, 14/2, k=1/k=2 reason 29 with all-−1 locus. TB38 is bound to [manifest](Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Case_Manifest.tsv) (SHA-256 `b27eecb6…dcf8c2`) and the unchanged harness `436f5fff…3c9a`. 250 is D2-reachable. O1: cut-route steps publish identity transport. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500** (19 inherited RED); TB35 **11/13**, TB36-R1 **0/5**, TB37 focused **14/16 reviewed/accepted within scope**; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` — TEST + BENCHMARK

- **Authority:** [RA-154.4](Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md) replaces the TB37-REV TB38 hand-off. Artifact-only census on CB36 package `12590917524` (ZIP SHA-256 `6dcbfe5a…7d03`, source `038ae7fd7`).
- **Inputs (frozen, Review-issued):**
  - [manifest](Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Case_Manifest.tsv): 504 rows, SHA-256 `b27eecb6b4f6f32fd060b8510a0cabf71f86b8fe1028dbb10c36003867dcf8c2`.
    - Rows 1–500 are TB32 `597741…6437` with identities and order unchanged; only rows 231, 232, 235, 236 and 237 change, from RED to GUARD/PASS.
    - Rows 501–504 are the 3 TB36 witnesses plus the face-gauge oracle.
  - Harness: `tools/m6_cp3_targeted_artifact_harness.sh`, unchanged, SHA-256 `436f5fff…3c9a`, `EXPECTED_CASE_COUNT=504`.
- **Prediction:** 490 PASS / 14 RED; on the 497 selector 483/14.
  - **RED, same first-failure assertion as TB32 (compared by assertion, not line number):** `focused30:12`, `cp3entry:1/2/4`, 442, 174, 201, 405.
  - **RED, `Rejected` assertion fails with Produced:** 191, 192, 204, 242, 247.
  - **RED, first-failure drift admissible:** 250.
- **STOP → TB38-REV:**
  - any GUARD row not PASS;
  - any of the 14 RED passing (record it, no credit);
  - a first-failure assertion change on any RED other than 250;
  - any hash, selection, duplicate, skip or postflight failure.
- **Prohibited:** editing source, tests, the harness, the manifest or the selector; compiling; reusing the TB37 harness; promoting CP3.
- **Preserve:** stable 66/17/49, debt 1; CP2 491/491; TB32 481/500 candidate; selector497 frozen; RP-01 open; `DIAG-RETAIN`, RA-152.5, RA-146.2/.4, RA-45.4 and G4-B002 kept separate.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB35 → REV → AUDIT (RA-152); CB35 → R1 → R2 (all REV) | F1 found; D1–D4; 3 witnesses statically accepted. |
| done | TB36-R1 → TB36-REV → AUDIT (RA-153) → CB36 → CB36-REV | 0/5 pre-fix baseline; D2 compiled and accepted (static). |
| done | TB37 → TB37-REV → `…-REV-AUDIT` ([RA-154](Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md)) | 14/16 focused accepted; TB38 manifest issued; tamper family reclassified. |
| 1 — next | `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS` → `…-REV` | 504-row manifest; 490/14 predicted; STOP rules above. |
| 2 | `M6-CP3-DEFN-RP01-ATLAS-INGRESS-TAMPER-ORACLE-HOMES` → `…-REV` | Design only: 189, 190, 191, 192, 204, 242, 247. Per oracle: home, keep or retire, selector bookkeeping. |
| 3 | Test-only CB groups A (191+204), B (192+247), C (242+189/190), each → REV; then one focused TB → REV | Compile only per CB; no production edits. |
| 4 | 250 `publishedProductError` site diagnostic (only if TB38 still shows 68) | Diagnostic only. |
| 5 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; DEFN or diagnostic first. |
| 6 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (A5–A7 diagnostic snapshots; full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | RA-154 O1 (cut-route identity transport), RA-152.5 axis binding, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS** — [RA-154.4](Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md), [manifest](Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Case_Manifest.tsv), harness `tools/m6_cp3_targeted_artifact_harness.sh`, CB36 package `12590917524`. Artifact-only; no edits; then independent TB38-REV.

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
