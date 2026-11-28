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
| Currency | 2026-11-28 UTC. [TB-REV-194](Architecture_M6_CP3_TB_REV_194_CoTrace_Deletion_Switch_Independent_Review_20261128.md) accepts the 1013/1013 test gate and the pinned O51 trace-removal witness. Two incorrect predictions are withdrawn: final subdivision counts are not additive (D7), and the fragment projections belong to A2b, not fallback completion. No independent exact numerical re-derivation of the two affected A3 counts is claimed. CP2 491/491, stable 67/17/50, debt1/deferred81. O52/O50 open, B1 held, B2 unmeasured. No V5, CP3/497/D0/H4 or production promotion. |
| Branch / source | PR #8 draft/open, `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-219 source `26eef1ce54b7b311cbf1cedf597ee0c106be52c2`, candidate `15252943713`, 28/28 checks ([CB-219 record](Architecture_M6_CP3_CB219_P13_CoTrace_Deletion_Switch_Code_Build_Record_20261128.md)). |
| Current TB evidence | [TB194 report](Architecture_M6_CP3_TB194_CoTrace_Deletion_Switch_Execution_Report_20261128.md), run `46122222893`, result `15255025606` ZIP `5fedd54ddf3416bf1cdb475a8e53206ab6382fcd75e9ea8b4a3bfebb4f8d99b4`, 2034/2034 checks, 1013/1013 PASS, membership1094, 984 N1–N3 equal; [TB-REV-194](Architecture_M6_CP3_TB_REV_194_CoTrace_Deletion_Switch_Independent_Review_20261128.md) accepts test gate only and adjudicates both incorrect predictions. [TB193 comparator](Architecture_M6_CP3_TB193_CoTrace_Deletion_Execution_Report_20261128.md) result `15250401219`, accepted test gate. V5 run `45920872749`, result `15165185584`, missing BunnyRandom resource receipt. |
| Historical comparison | TB182 `14979452472` (1004/1004); older via CHANGELOG. |
| Regression / debt | O51 trace ownership accepted for the pinned witness; D7 exact numeric input obligation carried to corners DEFN. O52/O50 open, row971 defect discharged for pinned contract. B1 (fallback cell164) held, off-trajectory (DESIGN §5.2); B2 off-gate runtime cause unproved. Stable 67/17/50, debt1/deferred81; J6 not exercised. |
| Executor | Unchanged harness SHA-256 `423f385b73c3825ce9fe18fbd5ca395287620475deb621389f0efbaa601e572c`; TB194 executor `26eef1ce54b7b311cbf1cedf597ee0c106be52c2`; earlier executors in retained reports. |
| Terminal execution request | `m6-cp3-tb194-exec`, run `46122222893`, job `140909114140`, exit0, postflight true, attempt1. |
| First unresolved question | [M6-CP3-DEFN-P13-A4-DISC-CORNERS](Architecture_M6_CP3_DEFN_P13_A4_Disc_Corners_Review_Entry_20261128.md): independently derive D7 counts on the two joined arcs before defining exact disc corners; O52 slivers 2/4 remain open; Vase ungated end-to-end. |

## Mandatory next turn

- **COMPLETE:** … → TB-REV-188 → CB-211R → CB-212 → TB-EXEC-189 → TB-REV-189 (+adv.) → DEFN-65C → CB-214 → TB-EXEC-191 → TB-REV-191 (+adv.; gate accepted, no production) → CB-215 (compile only) → CB-216 (compile only) → TB-EXEC-192 (execution PASS) → TB-REV-192 (test gate accepted only; +adv. EE1–EE5) → AP4 DEFN (A0, Amendment 35) → CB-217 (compile only) → CB-218 (compile only) → TB-EXEC-193 (execution PASS) → TB-REV-193 (test gate accepted only) → switch DEFN → CB-219 (compile only) → TB-EXEC-194 (execution complete, 1013 PASS, prediction STOP) → TB-REV-194 (test gate and pinned O51 accepted; numeric obligation carried).
- **TB-REV-192 adv.** ([record](Architecture_M6_CP3_TB_REV_192_Adversarial_Review_20261127.md)): gate upheld; EE1 ports exact; EE2 non-reciprocal; EE3 deletion exact; EE4 slivers 2/4 = O52 (corrects DD2); EE5 classifier hardening first.
- **AP4 DEFN** ([record](Architecture_M6_CP3_DEFN_P13_A2a_Partial_CoTrace_Removal_20261127.md)): user delegated → A0 deletion with typed fail-closed (Amendment 35); staged off (27 sphere rows); [manifest](gates/Architecture_M6_CP3_CB217_CB218_TB193_CoTrace_Deletion_Exact_Manifest.md).

```text
NEXT_TURN: M6-CP3-DEFN-P13-A4-DISC-CORNERS
Owner: runtime-free definition review only. Use TB-REV-194 and the retained A2b/A3 schedules to define exact A4 disc-corner ownership, including O52 slivers 2/4. Entry precondition: obtain or independently derive the D7 metric and parity input for the two joined arcs (new node pairs 1–3 and 4–5); do not assume 35 or 37. If evidence is absent, STOP with a bounded exact-input receipt plan before freezing any count-dependent implementation. See Architecture_M6_CP3_DEFN_P13_A4_Disc_Corners_Review_Entry_20261128.md for scope and falsifiers.
Authority: Architecture_M6_CP3_TB_REV_194_CoTrace_Deletion_Switch_Independent_Review_20261128.md; DESIGN §5, §7.2.1 Amendment 35, D7 and 65C; TB194 result 15255025606/source 26eef1ce54b7b311cbf1cedf597ee0c106be52c2; original frozen contract preserved. Do not implement, build, execute tests, use legacy fallback, activate chains, or promote production. O52 is open; O51 trace ownership accepted for the pinned witness only. Subsequent Vase and unequal-side work remain held until the definition is frozen.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-REV-177 | Adversarial records TB-REV-162…177 (`Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`); TB169 993/993 accepted; TB170–TB177 rejected (same 7 RED); D13 = A ([TB-REV-173](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md)). |
| COMPLETE | CB-199A → … → TB-REV-183 (TB179–TB183; 1003→1005 accepted) | Reports and reviews folded in [Vol D3](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md); adversarial records `Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`. |
| COMPLETE | CB-204 → TB-EXEC-184 (1005/1005) → TB-REV-184 (+[adv.](Architecture_M6_CP3_TB_REV_184_Adversarial_Review_20261125.md)) → CB-205 → TB185/185R/185S (invalid) → CB-205R/S/T → TB185T → TB-REV-185T (+[adv.](Architecture_M6_CP3_TB_REV_185T_Adversarial_Review_20261125.md)) | [TB185T](Architecture_M6_CP3_TB185T_Reach_Termination_Diagnostic_Execution_Report_20261125.md); others via CHANGELOG, invalid attempts in Vol D3. |
| COMPLETE | CB-205V → TB-EXEC-185V (1006/1006) → TB-REV-185 (+[adv.](Architecture_M6_CP3_TB_REV_185_Adversarial_Review_20261125.md); X1 corrected by TB-REV-188 adv.) → CB-207A/B → TB-EXEC-187Q (1006/1006) → TB-REV-187Q (+[adv.](Architecture_M6_CP3_TB_REV_187Q_Adversarial_Review_20261126.md)) | [TB185V](Architecture_M6_CP3_TB185V_Reach_Receipt_Reader_Selection_Scope_Full_Gate_Execution_Report_20261125.md), [TB187Q](Architecture_M6_CP3_TB187Q_QF1_Behaviour_Preservation_Full_Gate_Execution_Report_20261126.md); other records via CHANGELOG. |
| COMPLETE | TB-EXEC-186 RED → TB-REV-186 (+adv.) → CB-209/210 → TB-EXEC-188 → TB-REV-188 (gate accepted, V5 unaccepted; +[adv.](Architecture_M6_CP3_TB_REV_188_Adversarial_Review_20261127.md)) | [Review](Architecture_M6_CP3_TB_REV_188_Completion_Receipt_Activated_Full_Gate_Independent_Review_20261127.md). |
| COMPLETE | CB-211R → CB-212 → TB-EXEC-189 (1006/1006) → TB-REV-189 (+[adv.](Architecture_M6_CP3_TB_REV_189_Adversarial_Review_20261127.md)) | [Manifest](gates/Architecture_M6_CP3_CB211R_CB212_TB189_Sphere_Route_Witness_Exact_Manifest.md). |
| COMPLETE | DEFN-65C → CB-214 → TB-EXEC-191 (1008/1008) → TB-REV-191 (+[adv.](Architecture_M6_CP3_TB_REV_191_Adversarial_Review_20261127.md)) | [Manifest](gates/Architecture_M6_CP3_CB214_TB191_Region_Boundary_Schedule_Exact_Manifest.md). |
| **4D NEXT** | A2a arrival DEFN → CB-215 → CB-216 → TB-EXEC-192 → TB-REV-192 (+adv.) → AP4 DEFN (all COMPLETE) → 1 CB-217 (COMPLETE, compile only) → 2 CB-218 (COMPLETE, compile only) → 3 `M6-CP3-TB-EXEC-193` (COMPLETE, execution PASS) → 4 `M6-CP3-TB-REV-193` (COMPLETE, test gate accepted only) → 5 `M6-CP3-DEFN-P13-A2A-COTRACE-DELETION-SWITCH` (COMPLETE, CB-219 frozen) → `M6-CP3-CB-219-P13-COTRACE-DELETION-SWITCH` (COMPLETE, compile only) → TB-EXEC-194 (COMPLETE, prediction STOP) → TB-REV-194 (COMPLETE, test gate and pinned O51 accepted) → 6 NEXT `M6-CP3-DEFN-P13-A4-DISC-CORNERS` + O52 → CB/TB → 7 Vase row → 8 A4 unequal-side construction → 9 fill → 65B → 65D (O50, Amendment-19) → O41/switch | One DEFN → CB → TB each. B2 a separate Review item; B1, parameter deletion → V3b → R1 → O48, CB-207D held. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | CB-213 `c251d83b…` + TB-EXEC-190/TB-REV-190 (TB-REV-189 adv. CC1–CC2); prose CB-211 plan (TB-REV-188 adv. BB4); CB-208 diff `15dd890d…` (TB-REV-186T adv. Z1); CB-206 → full gate before QF1 (TB-REV-185 adv. X1); prose CB-205U (TB-REV-185T adv. W3); prose CB-200 plan + C4 assertion (TB-REV-179 adv. M2); CB-199A `4f458361…` (TB-REV-177 adv. J4); prose CB-198 (176 H1); older prose CBs, CB-194, CB-191, DEFN-161A/159A, CB-185 v1 — see TB-REV-162…177 adversarial records | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | Fallback repeated-node owner unadjudicated; BunnyRandom cost witness carried. CB-207C conditional; CB-207D held. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [disc-corners entry plan](Architecture_M6_CP3_DEFN_P13_A4_Disc_Corners_Review_Entry_20261128.md); [TB-REV-194](Architecture_M6_CP3_TB_REV_194_CoTrace_Deletion_Switch_Independent_Review_20261128.md); [TB194 report](Architecture_M6_CP3_TB194_CoTrace_Deletion_Switch_Execution_Report_20261128.md); [DEFN-65C](Architecture_M6_CP3_DEFN_P13_A4_Disc_Domain_Construction_20261127.md); [TB-REV-192 adv.](Architecture_M6_CP3_TB_REV_192_Adversarial_Review_20261127.md); [DESIGN.md](DESIGN.md) §5, §7; [LESSONS.md](LESSONS.md). Earlier authority linked in the review/entry plan and CHANGELOG.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff. Earlier CB/TB/RA records and diffs: [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
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
