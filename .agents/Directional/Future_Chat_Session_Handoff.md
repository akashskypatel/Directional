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
| Currency | 2026-11-26 UTC. TB185V 1006/1006 independently accepted preactivation ([review](Architecture_M6_CP3_TB_REV_185_Slide_Entry_Activation_Reach_Independent_Review_20261125.md)); QF1 before CB-206 (TB-REV-185 adv.); CB-207A/B compiled, [TB-EXEC-187Q](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md) 1006/1006 and comparison PASS; TB-REV-187Q next. TB185T diagnostic only; close_sheets outside measured reader scope. QF1 behaviour preservation awaits independent acceptance; stable 67/17/50, debt1/deferred81; no activation or CP3/497/D0/H4 promotion. |
| Branch / source | PR #8 draft/open, `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-207B Candidate source `9d69f8e568cad9253f8e0ac0efd1d61bc073840b`, package `15087219160` ZIP SHA-256 `66bff31c42987d4312fb8789a7148c15f448df3c470035463361e48718eb4bde`, [compile run 45755716781](https://github.com/akashskypatel/Directional/actions/runs/45755716781), 28/28 member checks, eight GMP/GMPXX targets, `runtimeExecution=false`. [Code + Build record](Architecture_M6_CP3_CB207B_QF1_Verifier_Forest_Edges_By_Class_Code_Build_Record_20261126.md). Prior TB185V remains independently accepted preactivation only; CB-207A/B full gate PASS pending independent review. |
| Current TB evidence | [TB187Q execution](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md), result `15130286146`, 1006/1006 PASS, 738 exact + 268 N1 + 0 material, row1006 51.56 s; independent review pending. TB185V accepted preactivation [execution](Architecture_M6_CP3_TB185V_Reach_Receipt_Reader_Selection_Scope_Full_Gate_Execution_Report_20261125.md), result `15066180913`, 1006/1006 PASS, comparison/receipt prediction PASS. Historical TB184 1005/1005, result `14992995631`: [execution](Architecture_M6_CP3_TB184_P13_Slide_Entry_Pre_Staging_Full_Gate_Execution_Report_20261125.md), [review](Architecture_M6_CP3_TB_REV_184_Slide_Entry_Pre_Staging_Independent_Review_20261125.md). TB183 result `14986349003` historical comparison; TB185 invalid result `14997312958` (folded in Vol D3). Exact hashes and checks in owning records. |
| Historical comparison | TB182 `14979452472` (1004/1004), TB181 `14967943314`, TB180 `14951803089`; manifests 1004 `d778afbe…8ca5f`, 1003 `2928fd31…f724`, TB169 `82581dd1…e436`, CP2 491 `483f1101…a038`. |
| Regression / debt | TB170 mechanical recurrence closed: controls 445/652/653/656/658/660/786 PASS; no new accepted-green loss. Historical 67 events / 17 categories / 50 recurrences; witness debt1/deferred81. J6 production contact case not exercised. K6 namespace correction independently accepted. |
| Executor | Full gate unchanged; diagnostic control previously verified. Executor `9d69f8e568cad9253f8e0ac0efd1d61bc073840b`, harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. [CB-205V record](Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Code_Build_Record_20261125.md). No rebuild during TB. |
| Terminal execution request | `m6-cp3-tb187q-exec`; [run 45841455761](https://github.com/akashskypatel/Directional/actions/runs/45841455761), job `139984165744`, result `15130286146`; exit0, immutable postflight PASS; [TB187Q report](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md). |
| First unresolved question | Does the activated sphere pipeline terminate (QF1 on the activation path, TB-REV-185 adv. X1), and at which stage (row858, X2)? |

## Mandatory next turn

- **COMPLETE:** CB-205 → … → TB185T → TB-REV-185T (+adv.) → CB-205V → TB185V (1006/1006) → [TB-REV-185](Architecture_M6_CP3_TB_REV_185_Slide_Entry_Activation_Reach_Independent_Review_20261125.md) (CB-206 exact diff frozen).
- **COMPLETE:** [TB-REV-185 adversarial](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md): CB-206 bytes upheld and syntax-clean (X4), but activation lets the sphere (98 V/192 F) pass its cut failure into quotient production (`RemeshPipeline.cpp:12936–12954` → `:13316`), where close_sheets (32 V) stalled; rows 648/843/844/858/1006 newly reach it (X1). Row858 asserts the sphere still fails somewhere (X2). QF1 A/B and a bounded sphere termination diagnostic now precede the activation full gate.

```text
NEXT_TURN: M6-CP3-TB-REV-187Q
Owner: Independent Review only; runtime-free. Accept or reject QF1 A/B behaviour preservation.
Authority: Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md; Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md (X1, step 4); frozen QF1 manifest and TB185V accepted result 15066180913.
  Candidate source 9d69f8e568cad9253f8e0ac0efd1d61bc073840b; package 15087219160; result 15130286146, ZIP SHA-256 a3fb3a89a3dd72ccc2870412fd0d6e78af4921943d7f491c4735443264de8ecc; 1006/1006 PASS, 1087 members, 81 deferred, immutable postflight PASS.
  Re-derive all gate and comparison evidence independently. Verify every semantic ledger and raw transcript under N1–N3; check row1006 receipts and resource evidence. STOP on material difference, missing/RED/abnormal row, or invalid boundary. No timing-only sufficiency claim.
Then: CB-206 (exact as frozen, only after independent acceptance) -> TB-EXEC-186T (bounded: rows 648/843/844/858/979/1006 under activation; terminal stage/code/elapsed; stacks on cutoff; no gate credit) -> TB-REV-186T -> TB-EXEC-186 (full + V5, STOP-on-RED) -> TB-REV-186
Do not: activate Branch A, edit product/tests/fixtures/selectors, promote CP3/497/D0/H4 or repair J6/E5/CB-190.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-REV-177 | Adversarial records TB-REV-162…177 (`Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`); TB169 993/993 accepted; TB170–TB177 rejected (same 7 RED); D13 = A ([TB-REV-173](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md)). |
| COMPLETE | CB-199A → … → TB-REV-183 (TB179–TB183; 1003→1005 accepted) | Reports and reviews folded in [Vol D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md); adversarial records `Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`. |
| COMPLETE | CB-204 → TB-EXEC-184 (1005/1005) → TB-REV-184 (+[adv.](Architecture_M6_CP3_TB_REV_184_Adversarial_Review_20261125.md)) → CB-205 → TB185/185R/185S (invalid) → CB-205R/S/T → TB185T → TB-REV-185T (+[adv.](Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md)) | [TB184](Architecture_M6_CP3_TB184_P13_Slide_Entry_Pre_Staging_Full_Gate_Execution_Report_20261125.md), [TB185T](Architecture_M6_CP3_TB185T_Reach_Termination_Diagnostic_Execution_Report_20261125.md); invalid attempts folded in Vol D3. |
| COMPLETE | `M6-CP3-CB-205V-P13-REACH-RECEIPT-READER-SELECTION-SCOPE` | Exact test-only; [record](Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Code_Build_Record_20261125.md); compile only. |
| COMPLETE | `M6-CP3-TB-EXEC-185V` | [TB185V execution report](Architecture_M6_CP3_TB185V_Reach_Receipt_Reader_Selection_Scope_Full_Gate_Execution_Report_20261125.md); 1006/1006, exact 10-receipt prediction met. |
| COMPLETE (adjudication) | `M6-CP3-TB-REV-185` | [Review](Architecture_M6_CP3_TB_REV_185_Slide_Entry_Activation_Reach_Independent_Review_20261125.md): accept 1006 preactivation cases, classify measured readers, freeze exact plan; [adversarial](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md) reorders QF1 before activation. |
| COMPLETE | `M6-CP3-CB-207A-QF1-QUOTIENT-FOREST-ADJACENCY-ONCE-PER-OWNER` | [Record](Architecture_M6_CP3_CB207A_QF1_Quotient_Forest_Adjacency_Once_Per_Owner_Code_Build_Record_20261125.md); exact one-path change; compile only. |
| COMPLETE | `M6-CP3-CB-207B-QF1-VERIFIER-FOREST-EDGES-BY-CLASS` | [Record](Architecture_M6_CP3_CB207B_QF1_Verifier_Forest_Edges_By_Class_Code_Build_Record_20261126.md); exact one-path change; compile only. |
| COMPLETE | `M6-CP3-TB-EXEC-187Q` | [Execution report](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md), 1006/1006 PASS, comparison PASS. |
| **4A NEXT** | `M6-CP3-TB-REV-187Q` | Independent acceptance before CB-206 ([TB-REV-185 adv.](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md) X1). |
| 4B | CB-206 ([exact manifest](gates/Architecture_M6_CP3_CB206_P13_Slide_Entry_Activation_Exact_Manifest.md)) → TB-EXEC-186T (bounded sphere rows 648/843/844/858/979/1006) → TB-REV-186T → TB-EXEC-186 (full + V5; STOP-on-RED) → TB-REV-186 → CB-207C if needed → parameter deletion → V3b → R1 → O48 | Separate turns; row858 premise adjudicated in TB-REV-186T (X2). |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | CB-206 → full gate before QF1 (TB-REV-185 adv. X1); prose CB-205U (TB-REV-185T adv. W3); prose CB-200 plan + C4 assertion (TB-REV-179 adv. M2); CB-199A `4f458361…` (TB-REV-177 adv. J4); prose CB-198 (176 H1); prose CB-197A/196/195/193/187/186/183/180/178/175/173, CB-194, CB-191, DEFN-161A/159A, CB-185 v1, activation-before-plan — see TB-REV-162…177 adversarial records | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB187Q report](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md), [CB-207B record](Architecture_M6_CP3_CB207B_QF1_Verifier_Forest_Edges_By_Class_Code_Build_Record_20261126.md), [TB-REV-185 adv.](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md), [QF1 manifest](gates/Architecture_M6_CP3_CB207_QF1_Quotient_Forest_Cost_Exact_Manifest.md), [TB185V report](Architecture_M6_CP3_TB185V_Reach_Receipt_Reader_Selection_Scope_Full_Gate_Execution_Report_20261125.md), [TB-REV-185 review](Architecture_M6_CP3_TB_REV_185_Slide_Entry_Activation_Reach_Independent_Review_20261125.md), [TB185 gate](gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv), [LESSONS.md](LESSONS.md).

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
