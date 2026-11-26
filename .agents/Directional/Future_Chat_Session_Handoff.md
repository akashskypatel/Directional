# Directional — Current handoff

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
| Currency | 2026-11-26 UTC. [TB-REV-186T](Architecture_M6_CP3_TB_REV_186T_Activated_Sphere_Termination_Independent_Review_20261126.md) confirms six activated sphere rows terminate, 5 PASS / row858 test-premise RED, exact receipts. [CB-208R](Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Code_Build_Record_20261126.md) exact test-only compile passed. Full gate/V5 pending; no cap/CB-207D or gate credit. TB187Q 1006/1006 accepted preactivation only; 67/17/50, debt1/deferred81. No promotion. |
| Branch / source | PR #8 draft/open, `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-208R source `cc25a6402cdd3ca1a33a9a9778250176b182bb2a`, package `15154205483` ZIP SHA-256 `cd84ab8b591759f4e01b5aaa685b048d69ed0a30a6b7e63dde6b1a97031971e8`, [compile run 45895803711](https://github.com/akashskypatel/Directional/actions/runs/45895803711), 28/28 checks, eight GMP/GMPXX targets, `runtimeExecution=false` ([record](Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Code_Build_Record_20261126.md)). Prior TB187Q source `9d69f8e568cad9253f8e0ac0efd1d61bc073840b`, package `15087219160`, remains accepted preactivation only. |
| Current TB evidence | [TB186T](Architecture_M6_CP3_TB186T_P13_Activated_Sphere_Termination_Execution_Report_20261126.md), result `15138712336`, 16/16 checks, all six finish, row858 RED at completion without locus; 648/979/1006 exact predictions. No gate credit. [TB187Q execution](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md), result `15130286146`, 1006/1006 PASS, 738 exact + 268 N1 + 0 material, row1006 51.56 s; independent review [accepted](Architecture_M6_CP3_TB_REV_187Q_QF1_Behaviour_Preservation_Independent_Review_20261126.md). TB185V accepted preactivation [execution](Architecture_M6_CP3_TB185V_Reach_Receipt_Reader_Selection_Scope_Full_Gate_Execution_Report_20261125.md), result `15066180913`, 1006/1006 PASS, comparison/receipt prediction PASS. TB184/TB183 and invalid TB185 evidence: retained sequence and Vol D3 below. |
| Historical comparison | TB182 `14979452472` (1004/1004), TB181 `14967943314`, TB180 `14951803089`; manifests 1004 `d778afbe…8ca5f`, 1003 `2928fd31…f724`, TB169 `82581dd1…e436`, CP2 491 `483f1101…a038`. |
| Regression / debt | TB170 mechanical recurrence closed; K6 closed. Row858 invalid unconditional diagnostic location expectation on unpromoted activation, non-stable, CB-208R correction compiled, runtime falsifier pending. 67 events / 17 categories / 50 recurrences, witness debt1/deferred81. J6 production contact not exercised. |
| Executor | CB-208R source `cc25a6402cdd3ca1a33a9a9778250176b182bb2a` contains unchanged harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. Full gate unchanged; frozen census complete. No TB rebuild. |
| Terminal execution request | `m6-cp3-tb186t-exec`; [run 45861079666](https://github.com/akashskypatel/Directional/actions/runs/45861079666), job `140052235045`, result `15138712336`; exit0, postflight PASS; [report](Architecture_M6_CP3_TB186T_P13_Activated_Sphere_Termination_Execution_Report_20261126.md). |
| First unresolved question | Will CB-208R pass the unchanged 1006-case activation gate and V5? Exact sphere completion rejection predicate and fine-resolution close_sheets termination remain unmeasured. |

## Mandatory next turn

- **COMPLETE:** … → TB185V → TB-REV-185 (+[adv.](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md): activation sends sphere into quotient production; QF1 first) → CB-207A/B → TB187Q 1006/1006 → TB-REV-187Q (+[adv.](Architecture_M6_CP3_TB_REV_187Q_Adversarial_Review_20261126.md)) → CB-206 (compile only) → TB-EXEC-186T ([report](Architecture_M6_CP3_TB186T_P13_Activated_Sphere_Termination_Execution_Report_20261126.md), all six finish) → TB-REV-186T (+[adv.](Architecture_M6_CP3_TB_REV_186T_Adversarial_Review_20261126.md)).
- **TB-REV-186T adv.:** CB-208 diff does not compile (`RemeshResult` has no `faces`) — withdrawn (Z1). CB-208R: `is_produced()` check plus recorded `SphereDisplayStopDetail` line naming which of five completion sites fired; prefix witness unchanged (Z2). Row972 is the only other cut-dependent gated row, predicted PASS from row979 counts (Z3).
- **TB-REV-187Q adv.:** census path + contingent CB-207D frozen; no cap measured, so not applied.

```text
NEXT_TURN: M6-CP3-TB-EXEC-186
Owner: Test + Benchmark only. Immutable full 1006-case gate with 81 deferred, then V5 only after valid full gate. STOP-on-RED. No rebuild, repair, semantic mutation, fixture/selector/harness change, or full-gate timeout.
Authority: Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Code_Build_Record_20261126.md; gates/Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Exact_Manifest.md; CB-208 manifest (runtime plan only); CB-206 manifest (activation predictions).
  Source/executor cc25a6402cdd3ca1a33a9a9778250176b182bb2a; candidate 15154205483; ZIP cd84ab8b591759f4e01b5aaa685b048d69ed0a30a6b7e63dde6b1a97031971e8; root manifest 4c6ad586ca35afff9ad61da3cdae88c62d0356fec906d37c0b9cc1a67e477648; source archive 5c316970e7163432d3bffb0ec2ac1646cef27ce4bc13ec999a9d70ae447eeb79.
  Harness 423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c; 1006 gate + 81 deferred = 1087 members; compare TB185V 15066180913 and retained TB187Q 15130286146, frozen N1–N3 only.
  Row858 exact stop receipt and 69196-byte prefix witness; record SphereDisplayStopDetail verbatim; row972 predicted PASS. Preserve all frozen activation receipts and negative controls. V5 Cylinder/BunnyRandom offgate:360/Vase; both pending-wall contacts; no census gate credit.
Then: M6-CP3-TB-REV-186 (independent adjudication and completion-site step from measured detail). No CP3/497/D0/H4 promotion or CB-207D; no J6/E5/CB-190 repair.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-REV-177 | Adversarial records TB-REV-162…177 (`Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`); TB169 993/993 accepted; TB170–TB177 rejected (same 7 RED); D13 = A ([TB-REV-173](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md)). |
| COMPLETE | CB-199A → … → TB-REV-183 (TB179–TB183; 1003→1005 accepted) | Reports and reviews folded in [Vol D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md); adversarial records `Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`. |
| COMPLETE | CB-204 → TB-EXEC-184 (1005/1005) → TB-REV-184 (+[adv.](Architecture_M6_CP3_TB_REV_184_Adversarial_Review_20261125.md)) → CB-205 → TB185/185R/185S (invalid) → CB-205R/S/T → TB185T → TB-REV-185T (+[adv.](Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md)) | [TB184](Architecture_M6_CP3_TB184_P13_Slide_Entry_Pre_Staging_Full_Gate_Execution_Report_20261125.md), [TB185T](Architecture_M6_CP3_TB185T_Reach_Termination_Diagnostic_Execution_Report_20261125.md); invalid attempts folded in Vol D3. |
| COMPLETE | CB-205V → TB-EXEC-185V (1006/1006) → TB-REV-185 (+[adv.](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md)) → CB-207A → CB-207B → TB-EXEC-187Q (1006/1006, N1–N3-equal) → TB-REV-187Q (+[adv.](Architecture_M6_CP3_TB_REV_187Q_Adversarial_Review_20261126.md)) | [CB-205V](Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Code_Build_Record_20261125.md), [TB185V](Architecture_M6_CP3_TB185V_Reach_Receipt_Reader_Selection_Scope_Full_Gate_Execution_Report_20261125.md), [TB-REV-185](Architecture_M6_CP3_TB_REV_185_Slide_Entry_Activation_Reach_Independent_Review_20261125.md), [CB-207B](Architecture_M6_CP3_CB207B_QF1_Verifier_Forest_Edges_By_Class_Code_Build_Record_20261126.md) (207A in Vol D3), [TB187Q](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md), [TB-REV-187Q](Architecture_M6_CP3_TB_REV_187Q_QF1_Behaviour_Preservation_Independent_Review_20261126.md). |
| **4B NEXT** | CB-206 → TB-EXEC-186T → TB-REV-186T (+adv.) COMPLETE → CB-208R COMPLETE → `M6-CP3-TB-EXEC-186` (full + V5) → TB-REV-186 (completion-site step from measured detail) → parameter deletion → V3b → R1 → O48 | [Review](Architecture_M6_CP3_TB_REV_186T_Activated_Sphere_Termination_Independent_Review_20261126.md); [CB-208R compile record](Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Code_Build_Record_20261126.md); [CB-208R manifest](gates/Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Exact_Manifest.md) (CB-208 diff withdrawn, adv. Z1). No cap: CB-207D and TB186U not authorized. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | CB-208 diff `15dd890d…` (TB-REV-186T adv. Z1, does not compile); CB-206 → full gate before QF1 (TB-REV-185 adv. X1); prose CB-205U (TB-REV-185T adv. W3); prose CB-200 plan + C4 assertion (TB-REV-179 adv. M2); CB-199A `4f458361…` (TB-REV-177 adv. J4); prose CB-198 (176 H1); prose CB-197A/196/195/193/187/186/183/180/178/175/173, CB-194, CB-191, DEFN-161A/159A, CB-185 v1, activation-before-plan — see TB-REV-162…177 adversarial records | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | Row858 location premise correction compiled in CB-208R, runtime pending; completion predicate remains unmeasured. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: Test + Benchmark turn skill; [CB-208R record](Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Code_Build_Record_20261126.md), [CB-208R exact manifest](gates/Architecture_M6_CP3_CB208R_P13_Display_Stop_Location_Detail_Receipt_Exact_Manifest.md), [CB-208 runtime plan](gates/Architecture_M6_CP3_CB208_P13_Display_Stop_Location_Authority_Exact_Manifest.md), [TB-REV-186T review](Architecture_M6_CP3_TB_REV_186T_Activated_Sphere_Termination_Independent_Review_20261126.md), [TB186T report](Architecture_M6_CP3_TB186T_P13_Activated_Sphere_Termination_Execution_Report_20261126.md), [CB-206 exact manifest](gates/Architecture_M6_CP3_CB206_P13_Slide_Entry_Activation_Exact_Manifest.md), [LESSONS.md](LESSONS.md).

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff. Earlier CB/TB/RA records (TB138 back to RA-244), their compile records and preserved exact diffs resolve through `load_next` Reviews and [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
3. [Architecture_M6_Frozen_Definitions.md](Architecture_M6_Frozen_Definitions.md), [DESIGN.md](DESIGN.md), [tracker](Regression_Root_Cause_Tracker.md) and [TODO](../../TODO.md).
4. [Historical record index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17) resolves superseded filenames; old turn ladders and navigation preimages are history only, not instructions. CB84 Linux Vase diagnostic timing attempt, CB121A 16-row fan-resolver plan and CB102 withdrawn. Reviews runtime-free; no deprecated scratch-build authorization. D6 pending, chain switch off.

**Review tooling:** `tools/review_check.py authority <sha>` and `tools/review_check.py boundary`, `tools/selector_probe.py` and `tools/fixture_probe.py`; see [tools/README.md](tools/README.md). Consult original normative definitions and [LESSONS.md](LESSONS.md) before any later evidence or semantic decision.

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
