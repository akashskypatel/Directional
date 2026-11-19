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
| Currency | 2026-11-19 UTC: [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc) upholds the [TB145 Review](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md) MATCH (964/964, 491/491, row961 PASS, row858 known RED; source = frozen CB168D+CB168E diffs, Haiku-verified). It withdraws the definition-only successor: the symmetric rule already exists (`field_aligned_contact_termination_decision`: inconclusive → both stop), and the record follows from the pre-commit struck index. It freezes exact CB168F (consumer + cut-edge split) and CB168G (EC3 switch), plus TB146. **No production acceptance**. |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB168G source `ebbe893bd5415e05ea828d5587a265d08326d1fa`, package `14566343560`, ZIP SHA-256 `41fc237f91b24cdc369908f483579ef3e16d55b7c7743ccd97ded4f30b83c717` ([record](Architecture_M6_CP3_CB168G_P13_Transverse_Entry_Mutual_Stop_Code_Build_Record_20261119.md)); CB168F source `3825f82eefad94c2be7553037ba329b086bc15a3`, compile package `14516872541` SHA-256 `3fd84e86cd96a30d4ab01ce33ede8078067b659adf75a3eb152c0b112adf6cd2` ([record](Architecture_M6_CP3_CB168F_P13_Mutual_Carrier_Contact_Consumer_Code_Build_Record_20261119.md)); CB168E source `d43d07dd1564be90bc1a89775b17b524d4e83039`, package `14508452647`, ZIP SHA-256 `5daeba011fc49fde4ad083f5104b5a3847abe8b6742dec841465762b0bd1b609` ([record](Architecture_M6_CP3_CB168E_P13_Entry_Coincidence_Arrival_Receipt_Code_Build_Record_20261119.md)); CB168D `60357edb2` ([record](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Code_Build_Record_20261119.md)); CB168C `e0f085eb6`; CB168B `ddd4d1587`, package `14497790061`. |
| Accepted evidence | [TB125](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb125_p13_edge_terminal_exact_inventory_execution_report_20261117md) scoped 950/950; artifacts `14289730737`/`14289927334`. CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. TB127 comparison authority: package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate `14302887671` 951/951, census `14302668940`. |
| Latest execution | [TB146 execution](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Execution_Report_20261119.md): gate run `44603830217`, artifact `14569832286`, source `ebbe893bd5415e05ea828d5587a265d08326d1fa`, 961/962 PASS, accepted prefix **490/491** (row393 RED at :17144, four `7 vs 7` assertions), row858 PASS, rows961/962 PASS, 941/941 unaffected prior rows MATCH, all 240 entry receipts unchanged, 66→0 duplicate (0,2) records; cut-search exhaustion at 669/698. Required STOP: no three-row census. Candidate not adjudicated; stable 66/17/49, debt1, deferred81; no promotion. |
| Latest reviewed evidence | [TB145 Review](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md) + [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc): 964/964 prior records, 1,266 slides, 246 receipts. Stable 66/17/49, debt1, deferred81; no product promotion. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48 open; narrow C3/O44/C1 and O45 (consumer proxy only) closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Sphere transverse entry receipts 4/6 on cut (0,2), 15/19 on non-cut (25,27) unchanged; TB146 removed 66 duplicate records, but row393 required prefix RED on end-index assertion. Rows669/698 report cut-search exhaustion; row858 PASS, row648 PASS. Detailed trace records unavailable. O47/C5 remains open; BunnyRandom O48 unmeasured in TB146, H4/O49 held before CB169. FC-6, H2, terminal-cut held. No CP3/D0 acceptance. |

## Mandatory next turn — `M6-CP3-TB146-P13-TRANSVERSE-ENTRY-MUTUAL-STOP-FULL-GATE-REV` — independent Review, runtime-free

Reopen [TB146 execution](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Execution_Report_20261119.md), result `14569832286` and TB145 baseline; use the [frozen plan](Architecture_M6_CP3_CB168F_P13_Transverse_Entry_Mutual_Stop_Plan_20261119.md). Independently adjudicate row393, all 20 sphere rows (including 648/858), cut-search exhaustion and missing trace details. The accepted-prefix STOP prevented census dispatch. Freeze one bounded next turn only after evidence supports it. No runtime, product/test mutation or acceptance in Review.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB131 EXEC/REV, RA-250–RA-252, CB150–CB154 | H1/H2, FC-7′ switch; TB131 literal MISMATCH (presentation only). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-253–RA-262, CB155–CB166, TB132–TB141 EXEC/REV | Contact receipts, H3 closed narrowly, slide contact (RA-259 S3) and pieces (RA-260 S2) defined, EPO contract (RA-262); MATCH through [TB141](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Execution_Report_20261118.md) 962/962; records via the load list and folded index. |
| COMPLETE | TB141-REV + [RA-263](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Independent_Review_20261118.md#ra-263--adversarial-re-review-of-this-review-2026-11-18-utc), [CB167](Architecture_M6_CP3_CB167_P13_Trace_Piece_Path_Helper_Code_Build_Record_20261118.md), [TB142](Architecture_M6_CP3_TB142_P13_Trace_Piece_Path_Helper_Full_Gate_Execution_Report_20261118.md) | No slide published; O47 track before H4; TB144 strict; CB167 compiled; TB142 962/962, row 960 PASS. |
| COMPLETE (Review) | `M6-CP3-TB142-P13-TRACE-PIECE-PATH-HELPER-FULL-GATE-REV` + [RA-264](Architecture_M6_CP3_TB142_P13_Trace_Piece_Path_Helper_Full_Gate_Independent_Review_20261119.md#ra-264--adversarial-re-review-of-this-review-2026-11-19-utc) | MATCH upheld; EC1 re-frozen receipt-only; `carrierLocus` moved to EC2; TB143 frozen. |
| COMPLETE | CB168A, [TB143 EXEC](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb143_p13_entry_coincidence_receipt_full_gate_execution_report_20261119md), TB143-REV + [RA-265](Architecture_M6_CP3_TB143_P13_Entry_Coincidence_Receipt_Full_Gate_Independent_Review_20261119.md#ra-265--adversarial-re-review-of-this-review-2026-11-19-utc) | EC1 receipt compiled and measured; MATCH 962/962 (N3 per TB131); sphere witness 19/19. |
| COMPLETE | CB168B (`ddd4d1587`, pkg `14497790061`), CB168C/EC2a (`e0f085eb6`, pkg `14498438448`), [TB144 EXEC](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Execution_Report_20261119.md), TB144-REV + [RA-266](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md#ra-266--adversarial-re-review-of-this-review-2026-11-19-utc) | Framing single-write; helper unwired + row 961; 963/963 prior MATCH, row 858 known RED; prose EC2b replaced by exact patches. |
| COMPLETE | CB168D (EC2b, `60357edb2`), CB168E (`d43d07dd1`, pkg `14508452647`), [TB145 EXEC](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Execution_Report_20261119.md) | Exact diffs compiled (inert edge-node binding; arrival/face receipt); 964/964 prior MATCH; EC3 census. |
| COMPLETE (Review) | `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-REV` + [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc) | 964/964 MATCH upheld; DEFN withdrawn (rule exists); CB168F/CB168G/TB146 frozen ([plan](Architecture_M6_CP3_CB168F_P13_Transverse_Entry_Mutual_Stop_Plan_20261119.md)). |
| COMPLETE (Code + Build) | `M6-CP3-CB168F-P13-MUTUAL-CARRIER-CONTACT-CONSUMER` | Exact diff `1239c09d…1bc1c`; `carrier_contact_is_mutual` + unit test, cut-edge split at mutual node; inert; compile only. |
| COMPLETE (Code + Build) | `M6-CP3-CB168G-P13-TRANSVERSE-ENTRY-MUTUAL-STOP` (EC3) | Exact diff `4555af7c…6aa9`; source `ebbe893bd5415e05ea828d5587a265d08326d1fa`, package `14566343560`; compile only ([record](Architecture_M6_CP3_CB168G_P13_Transverse_Entry_Mutual_Stop_Code_Build_Record_20261119.md)). |
| COMPLETE (Test + Benchmark, RED) | `M6-CP3-TB146-P13-TRANSVERSE-ENTRY-MUTUAL-STOP-FULL-GATE-EXEC` | [Execution](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Execution_Report_20261119.md): 961/962 PASS; required row393 RED, prefix490/491. 941/941 unaffected MATCH; 858 PASS; STOP before census. |
| NEXT (Review) | `M6-CP3-TB146-P13-TRANSVERSE-ENTRY-MUTUAL-STOP-FULL-GATE-REV` | Adjudicate row393, sphere rows and missing trace census; freeze next exact turn. |
| Prospective (RA-267 S4) | CB168 binding → [O49] → CB169 H4 cutover → CB170 → CB171 → CB172 (O48, incl. same-face merge) | CB172 after vertex-overlap rule + tie control, deletes CB160/CB166 receipts. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | After the TB132 Review; 858 after the sphere repair. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS`; `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON`; `M6-CP3-DEFN-P13-SYMMETRIC-TRANSVERSE-ENTRY-EDGE-BINDING` (prior provisional routes only) | Replaced by CB151; by CB153 (RA-251); by RA-253 S1/S7 N3–N5; by CB156/TB133 (RA-254); by CB168F/CB168G (RA-267). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked; O45 consumer proxy closed narrowly. |


## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB146 execution](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Execution_Report_20261119.md), [CB168G compile record](Architecture_M6_CP3_CB168G_P13_Transverse_Entry_Mutual_Stop_Code_Build_Record_20261119.md), [CB168F compile record](Architecture_M6_CP3_CB168F_P13_Mutual_Carrier_Contact_Consumer_Code_Build_Record_20261119.md), [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168F/CB168G/TB146 plan](Architecture_M6_CP3_CB168F_P13_Transverse_Entry_Mutual_Stop_Plan_20261119.md), [TB145 Review](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md), [TB145 execution](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Execution_Report_20261119.md), CB168E/CB168D records, [RA-266](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md#ra-266--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168D/CB168E/TB145 plan](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Plan_20261119.md), TB144 Review/execution, RA-265, RA-264, RA-263, RA-262 S2–S5, RA-261 S2–S5, RA-260 S2–S4, RA-259 S3. Mandatory policies apply.

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
