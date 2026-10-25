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
| Currency | 2026-10-25: TB38 artifact-only 504-row census executed; 490 PASS / 14 inherited RED, exactly RA-154 predicted, integrity checks green. Independent TB38-REV next; CP3 and selector stay unpromoted. |
| Source/package | CB36 exact semantic `038ae7fd7c290731c28225d2693a3e13866e325a`; [compile run 40173209091](https://github.com/akashskypatel/Directional/actions/runs/40173209091), artifact `12590917524`, ZIP SHA256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`; 28/28 hashes, all eight GMP/GMPXX targets, clean source, `runtimeExecution=false`. [CB36 record](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md). |
| Reviewed decision | [RA-154](Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md) independently re-verified TB37: 21/21 hashes, 14/2, k=1/k=2 reason 29 with all-−1 locus. TB38 is bound to [manifest](Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Case_Manifest.tsv) (SHA-256 `b27eecb6…dcf8c2`) and the unchanged harness `436f5fff…3c9a`. 250 is D2-reachable. O1: cut-route steps publish identity transport. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500**; TB37 focused **14/16 reviewed**; TB38 candidate **490/504** (497 selector 483/14) pending independent Review; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS-REV` — independent REVIEW

- **Authority:** [RA-154.4](Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md) and [TB38 immutable report](Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Report_20261025.md).
- **Exact evidence:** [run 40185527486](https://github.com/akashskypatel/Directional/actions/runs/40185527486); result artifact `12597140251` outer SHA-256 `0cdfe445fbc5388b8e95331f87c4a291001645f30458001bb5426244022a9870`; 1,014/1,014 SHA manifest entries, 504/504 logs; 490 PASS / 14 RED; immutable CB36 package `12590917524`.
- **Review independently:** per-row manifest and raw log joins; all 14 residual first assertions against TB32 (not line-number equality); specifically 191/192 move from A3 exception to Produced-versus-Rejected is predicted, and `cp3entry:2` pointer addresses are nonsemantic; 250 remains `PublishedProductRejected(68)`. Verify four appended guards, five reclassified guards, 497-selector no loss, zero missing/skip/duplicates/postflight failures, no source/test/selector mutation.
- **Decision/gates:** document accepted or rejected candidate evidence and owning residual debt without promoting CP3 or selector. If accepted, authorize next `M6-CP3-DEFN-RP01-ATLAS-INGRESS-TAMPER-ORACLE-HOMES` (design only); no test/code modifications in this Review. Preserve stable 66/17/49 debt1, CP2 491/491, RP-01 open and RP-02 unreached; carry `DIAG-RETAIN` and other RA-154 obligations separately.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB35 → REV → AUDIT (RA-152); CB35 → R1 → R2 (all REV) | F1 found; D1–D4; 3 witnesses statically accepted. |
| done | TB36-R1 → TB36-REV → AUDIT (RA-153) → CB36 → CB36-REV | 0/5 pre-fix baseline; D2 compiled and accepted (static). |
| done | TB37 → TB37-REV → `…-REV-AUDIT` ([RA-154](Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md)) | 14/16 focused accepted; TB38 manifest issued; tamper family reclassified. |
| done → next | TB38 complete → `M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS-REV` | Measured 504/504, 490/14, 1,014 checksums; independent Review next. |
| 2 | `M6-CP3-DEFN-RP01-ATLAS-INGRESS-TAMPER-ORACLE-HOMES` → `…-REV` | Design only: 189, 190, 191, 192, 204, 242, 247. Per oracle: home, keep or retire, selector bookkeeping. |
| 3 | Test-only CB groups A (191+204), B (192+247), C (242+189/190), each → REV; then one focused TB → REV | Compile only per CB; no production edits. |
| 4 | 250 `publishedProductError` site diagnostic (only if TB38 still shows 68) | Diagnostic only. |
| 5 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; DEFN or diagnostic first. |
| 6 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (A5–A7 diagnostic snapshots; full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | RA-154 O1 (cut-route identity transport), RA-152.5 axis binding, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB38-RP01-PERIODIC-ROUTE-ATLAS-CENSUS-REV** — [RA-154.4](Architecture_M6_CP3_TB37_REV_Audit_Periodic_Census_Manifest_Decision_20261025.md), [TB38 report](Architecture_M6_CP3_TB38_Periodic_Route_Atlas_Census_Report_20261025.md), immutable result artifact `12597140251`, TB32 baseline `12534679588`, CB36 package `12590917524`. Independent evidence Review only; no source/test/selector changes or promotion.

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
