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
| Currency | 2026-11-25 UTC. TB184 1005/1005 remains accepted; TB185T bounded diagnostic only ([independent](Architecture_M6_CP3_TB_REV_185T_Reach_Termination_Diagnostic_Independent_Review_20261125.md) + [adversarial](Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md)). Its receipts: only sphere changes under staging; stall is close_sheets, outside reader scope. CB-205V next; QF1 on its own track. Stable 67/17/50, debt1/deferred81; no activation or CP3/497/D0/H4 promotion. |
| Branch / source | PR #8 draft/open, `agent/surface_cell_quad/p5-recover-bridge-healing`. Candidate CB-205 source `21087c8285a5dd367cc16f610386accc061bd194`, GMP/GMPXX [run 45554728034](https://github.com/akashskypatel/Directional/actions/runs/45554728034), package `14995401750` ZIP SHA-256 `7e66ef7b3b16e76618a60b250a76038e65bf2e092601958f8252ac993b778da9`, 28/28 checks, eight targets, `runtimeExecution=false`. [Code + Build record](Architecture_M6_CP3_CB205_P13_Slide_Entry_Activation_Reach_Code_Build_Record_20261125.md). Candidate only. |
| Current TB evidence | Accepted TB184 (CB-204 package `14990462714`, [record](Architecture_M6_CP3_CB204_P13_Slide_Entry_Pre_Staging_Code_Build_Record_20261125.md)) [run 45546583508](https://github.com/akashskypatel/Directional/actions/runs/45546583508), result `14992995631` ZIP SHA-256 `8686e64c07fed5e72a5285fa6071a50944f1ea0b24c4b9e61eea831c46e0dd9c`, 2018/2018 checks, 1005/1005 PASS, 1086 members, 779 exact + 225 N1/N2 + one authorized row979 block, zero N3/material. [Execution](Architecture_M6_CP3_TB184_P13_Slide_Entry_Pre_Staging_Full_Gate_Execution_Report_20261125.md); [Review](Architecture_M6_CP3_TB_REV_184_Slide_Entry_Pre_Staging_Independent_Review_20261125.md). TB183 result `14986349003` ZIP SHA-256 `95b49af95c09e1bca461198c798db57e506b4daf7e09da1466c0fbd2b76a9742`, 1005/1005 historical comparison. TB185 invalid: result `14997312958`; see invalid execution record. |
| Historical comparison | TB182 `14979452472` (1004/1004), TB181 `14967943314`, TB180 `14951803089`; manifests 1004 `d778afbe…8ca5f`, 1003 `2928fd31…f724`, TB169 `82581dd1…e436`, CP2 491 `483f1101…a038`. |
| Regression / debt | TB170 mechanical recurrence closed: controls 445/652/653/656/658/660/786 PASS; no new accepted-green loss. Historical 67 events / 17 categories / 50 recurrences; witness debt1/deferred81. J6 production contact case not exercised. K6 namespace correction independently accepted. |
| Executor | Default full gate unchanged; diagnostic provision/control verified. Executor `90319deb1dc277a2b0ab8bba70c8aa2cf3f2f6a1`, harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`. [CB-205T record](Architecture_M6_CP3_CB205T_Debugger_Provisioning_Record_20261125.md). No rebuild. |
| Terminal execution request | `m6-cp3-tb185t-reach-termination`; [run 45639470951](https://github.com/akashskypatel/Directional/actions/runs/45639470951), job `139294131198`, result `15035995368`; exit124, immutable postflight PASS; [report](Architecture_M6_CP3_TB185T_Reach_Termination_Diagnostic_Execution_Report_20261125.md). |
| First unresolved question | Activation reach under the gate (TB185V); QF1 sufficiency (many-small vs one-huge class) unmeasured until CB-207C. |

## Mandatory next turn

- **COMPLETE:** CB-205 → TB185/185R/185S (invalid) → CB-205R/S/T → TB185T (bounded diagnostic) → [TB-REV-185T](Architecture_M6_CP3_TB_REV_185T_Reach_Termination_Diagnostic_Independent_Review_20261125.md) (QF1 localized).
- **COMPLETE:** [TB-REV-185T adversarial](Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md): stall is close_sheets, a fixture no reader reads; TB185T receipts show only the sphere changes and sphere stays polyline-eligible (W1); test-only CB-205V on the critical path (W2); prose CB-205U withdrawn, incomplete (verifier K×F loop) (W3); exact CB-207A/B frozen for the QF1 track (W4); syntax-clean (W5).

```text
NEXT_TURN: M6-CP3-CB-205V-P13-REACH-RECEIPT-READER-SELECTION-SCOPE
Owner: Code + Build only; apply exact one-file test-only diff; compile eight GMP/GMPXX targets; runtimeExecution=false.
Authority: Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md (W1/W2); gates/Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Exact_Manifest.md; Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Exact.diff
  diff SHA-256 c9d66976d9d8f765f572de4f66fc00ee8a815abac8f3a04b3f51b39b67881178; tests/FieldAlignedCurveNetworkTests.cpp 03abb0a6...d72d -> 39b22f998b29b9662640e1212440db3d3f997bd1e1eba8c5492fa25b350efc48; one path only
  row1006 polyline loop stops at first production+staged eligible fixture (reader scope); receipts 9+visited; ' published=not-applicable' separator; all other assertions unchanged
  STOP on preimage/postimage/path/compile/package mismatch; no product change
Then: M6-CP3-TB-EXEC-185V (1006/1006; row1006 exactly 10 receipts = TB185T lines 1-10 except census separator; polyline line sphere/sphere) -> M6-CP3-TB-REV-185 (classify readers; freeze CB-206 = flip SurfaceCellTracing.cpp:5336 + rows 648/978/979 + row979 label + row1006 transcript) -> CB-206 -> TB-EXEC-186 (V5; full compare; STOP-on-RED) -> TB-REV-186 -> QF1 track: CB-207A -> CB-207B (exact, frozen) -> CB-207C (close_sheets termination+size receipt) -> TB-EXEC-187 -> TB-REV-187
Withdrawn: prose CB-205U (TB-REV-185T adversarial W3/W4)
Do not: change product code in CB-205V, activate Branch A, promote CP3/497/D0/H4 or repair J6/E5/CB-190.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-REV-177 | Adversarial records TB-REV-162…177 (`Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`); TB169 993/993 accepted; TB170–TB177 rejected (same 7 RED); D13 = A ([TB-REV-173](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md)). |
| COMPLETE | CB-199A → … → TB-REV-183 (TB179–TB183; 1003→1005 accepted) | Reports and reviews folded in [Vol D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md); adversarial records `Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`. |
| COMPLETE | CB-204 → TB-EXEC-184 (1005/1005) → TB-REV-184 (+[adv.](Architecture_M6_CP3_TB_REV_184_Adversarial_Review_20261125.md)) → CB-205 → TB185/185R/185S (invalid) → CB-205R/S/T → TB185T → TB-REV-185T (+[adv.](Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md)) | [TB184](Architecture_M6_CP3_TB184_P13_Slide_Entry_Pre_Staging_Full_Gate_Execution_Report_20261125.md), [TB185T](Architecture_M6_CP3_TB185T_Reach_Termination_Diagnostic_Execution_Report_20261125.md); invalid attempts folded in Vol D3. |
| **1 NEXT** | `M6-CP3-CB-205V-P13-REACH-RECEIPT-READER-SELECTION-SCOPE` | Exact test-only; [manifest](gates/Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Exact_Manifest.md); compile only. |
| 2–3 | `M6-CP3-TB-EXEC-185V` → `M6-CP3-TB-REV-185` | Exact 10-receipt prediction; classify readers; freeze CB-206 (flip + rows 648/978/979 + row979 label + row1006 transcript). |
| 4A | CB-206 activation → TB-EXEC-186 (V5 BunnyRandom; full compare vs TB185V; STOP-on-RED) → TB-REV-186 (one correction CB per RED family) → parameter-deletion CB → V3b → R1 → O48 | Signature-default flip `SurfaceCellTracing.cpp:5336` (row669 falsifier) + exact rows 648/978/979; separate turns. |
| 4B | QF1: CB-207A → CB-207B (exact, [manifest](gates/Architecture_M6_CP3_CB207_QF1_Quotient_Forest_Cost_Exact_Manifest.md)) → CB-207C (close_sheets termination + N/K/R/F/max-class receipt) → TB-EXEC-187 → TB-REV-187 | One turn each; after TB-REV-186. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | prose CB-205U (TB-REV-185T adv. W3); prose CB-200 plan + C4 assertion (TB-REV-179 adv. M2); CB-199A `4f458361…` (TB-REV-177 adv. J4); prose CB-198 (176 H1); prose CB-197A/196/195/193/187/186/183/180/178/175/173, CB-194, CB-191, DEFN-161A/159A, CB-185 v1, activation-before-plan — see TB-REV-162…177 adversarial records | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB-REV-185T adversarial](Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md), [CB-205V manifest](gates/Architecture_M6_CP3_CB205V_P13_Reach_Receipt_Reader_Selection_Scope_Exact_Manifest.md), [QF1 manifest](gates/Architecture_M6_CP3_CB207_QF1_Quotient_Forest_Cost_Exact_Manifest.md), [TB-REV-185T](Architecture_M6_CP3_TB_REV_185T_Reach_Termination_Diagnostic_Independent_Review_20261125.md), [TB185T report](Architecture_M6_CP3_TB185T_Reach_Termination_Diagnostic_Execution_Report_20261125.md), [CB-205 reach contract](gates/Architecture_M6_CP3_CB205_P13_Slide_Entry_Activation_Reach_Exact_Manifest.md), [TB185 gate](gates/Architecture_M6_TB185_P13_Slide_Entry_Activation_Reach_Full_Gate_Case_Manifest.tsv), [TB-REV-184 adv.](Architecture_M6_CP3_TB_REV_184_Adversarial_Review_20261125.md), [folded attempts](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-185t-folded-records--2026-11-25-utc), [LESSONS.md](LESSONS.md).

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
