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
| Currency | 2026-11-19 UTC: [RA-266](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md#ra-266--adversarial-re-review-of-this-review-2026-11-19-utc) upholds TB144 **963/963 prior MATCH** (source = frozen CB168B+CB168C diffs, Haiku-verified) and freezes exact CB168D/CB168E patches and TB145; CB168D and CB168E compile PASS, TB145 next; **no acceptance**. |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB168E source `d43d07dd1564be90bc1a89775b17b524d4e83039`, package `14508452647`, ZIP SHA-256 `5daeba011fc49fde4ad083f5104b5a3847abe8b6742dec841465762b0bd1b609`; [record](Architecture_M6_CP3_CB168E_P13_Entry_Coincidence_Arrival_Receipt_Code_Build_Record_20261119.md). CB168D source `60357edb20132b20263fc5a1997f8af50343e2ae`, compile artifact `14507741391`, SHA-256 `0cafed08563f6699ff4000b7975f880f2de46a1a91266daab539c85439fbe25a`; [record](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Code_Build_Record_20261119.md). CB168C source `e0f085eb65ed186bf836305f2896c69c6c90c519`, package `14498438448`, ZIP SHA-256 `041ee85006926b674b3692a1315e9ba0695397a144ea0f00c406b4a6cfee081f`; [compile record](Architecture_M6_CP3_CB168C_P13_Carrier_Contact_Struck_Position_Helper_Code_Build_Record_20261119.md). CB168B source `ddd4d158701bdcca73fe3eb5034d51dd4ff1b694`, package `14497790061` remains the product baseline. |
| Accepted evidence | [TB125](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb125_p13_edge_terminal_exact_inventory_execution_report_20261117md) scoped 950/950; artifacts `14289730737`/`14289927334`. CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. TB127 comparison authority: package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate `14302887671` 951/951, census `14302668940`. |
| Latest execution | [TB144 execution](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Execution_Report_20261119.md): gate run `44462908179`, artifact `14501920082`, **960 PASS / known row858 RED** of 961 cases, row961 PASS. Census run `44462935556`, artifact `14502085765`, Cylinder PASS/288, BunnyRandom/Vase RED. **1,939/1,939** result file hashes verified; **963/963 prior** logs/ledgers MATCH TB143 under N1–N7, zero doubled M3 lines, 1,266 slide proposal and committed receipts each unchanged, all 246 entry receipts preserved. No graph publication or product acceptance. |
| Latest reviewed evidence | [TB144 Review](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md) + [RA-266](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md#ra-266--adversarial-re-review-of-this-review-2026-11-19-utc): 963/963 prior logs and ledgers; CB168C package 28/28. Stable 66/17/49, debt1, deferred81; no product promotion. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48 open; narrow C3/O44/C1 and O45 (consumer proxy only) closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Sphere traces 4/6 cross at P on edge (0,2): C5/O47. BunnyRandom 43/15: shared interval [X43, v94] on (94,210); 43 earlier, so trace 15 should end at X43 (O48). H3 closed narrowly (CB160 receipt unreachable, delete in wiring). H4 (RA-261 S1): geometry consumers publish a grazing slide as entry→slide end, skipping the slide start; TB141: retained, not published. CB165 helper unwired. O49 (51 edge-only BunnyRandom receipts) before CB169. O45 narrow closure kept; 858 permitted RED at :155, 648 unreached. FC-6, H2, terminal-cut held. No CP3/D0 acceptance. RA-259 S3 contact rule; RA-260 S2 pieces/positions/edge node. |

## Mandatory next turn — `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-EXEC` — Test + Benchmark only

Use the immutable CB168E package `14508452647` from exact source `d43d07dd1564be90bc1a89775b17b524d4e83039`. Apply [the frozen TB145 plan](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Plan_20261119.md) without a rebuild, source edit or test/selector change. Compare the 964 required records under N1–N7 against TB144, delete only the appended receipt suffix for the prior-record comparison, and measure EC3 arrival and source-face results as specified. Preserve known row858 RED and all production-acceptance limits. Do not start TB145 in this CB168E turn.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB131 EXEC/REV, RA-250–RA-252, CB150–CB154 | H1/H2, FC-7′ switch; TB131 literal MISMATCH (presentation only). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-253–RA-262, CB155–CB166, TB132–TB141 EXEC/REV | Contact receipts, H3 closed narrowly, slide contact (RA-259 S3) and pieces (RA-260 S2) defined, EPO contract (RA-262); MATCH through [TB141](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Execution_Report_20261118.md) 962/962; records via the load list and folded index. |
| COMPLETE | TB141-REV + [RA-263](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Independent_Review_20261118.md#ra-263--adversarial-re-review-of-this-review-2026-11-18-utc), [CB167](Architecture_M6_CP3_CB167_P13_Trace_Piece_Path_Helper_Code_Build_Record_20261118.md), [TB142](Architecture_M6_CP3_TB142_P13_Trace_Piece_Path_Helper_Full_Gate_Execution_Report_20261118.md) | No slide published; O47 track before H4; TB144 strict; CB167 compiled; TB142 962/962, row 960 PASS. |
| COMPLETE (Review) | `M6-CP3-TB142-P13-TRACE-PIECE-PATH-HELPER-FULL-GATE-REV` + [RA-264](Architecture_M6_CP3_TB142_P13_Trace_Piece_Path_Helper_Full_Gate_Independent_Review_20261119.md#ra-264--adversarial-re-review-of-this-review-2026-11-19-utc) | MATCH upheld; EC1 re-frozen receipt-only; `carrierLocus` moved to EC2; TB143 frozen. |
| COMPLETE | CB168A, [TB143 EXEC](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb143_p13_entry_coincidence_receipt_full_gate_execution_report_20261119md), TB143-REV + [RA-265](Architecture_M6_CP3_TB143_P13_Entry_Coincidence_Receipt_Full_Gate_Independent_Review_20261119.md#ra-265--adversarial-re-review-of-this-review-2026-11-19-utc) | EC1 receipt compiled and measured; MATCH 962/962 (N3 per TB131); sphere witness 19/19. |
| COMPLETE | CB168B (`ddd4d1587`, pkg `14497790061`), CB168C/EC2a (`e0f085eb6`, pkg `14498438448`), [TB144 EXEC](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Execution_Report_20261119.md), TB144-REV + [RA-266](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md#ra-266--adversarial-re-review-of-this-review-2026-11-19-utc) | Framing single-write; helper unwired + row 961; 963/963 prior MATCH, row 858 known RED; prose EC2b replaced by exact patches. |
| COMPLETE (Code + Build) | `M6-CP3-CB168D-P13-CARRIER-CONTACT-EDGE-NODE-BINDING` (EC2b) | Exact diff `cf726ced…8de` ([plan](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Plan_20261119.md)): carrier contact is an edge node, validated binding, cut-crossing merge; inert; eight-target compile PASS; [record](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Code_Build_Record_20261119.md). |
| COMPLETE (Code + Build) | `M6-CP3-CB168E-P13-ENTRY-COINCIDENCE-ARRIVAL-RECEIPT` | Exact +34/-7 receipt diff committed as `d43d07dd1564be90bc1a89775b17b524d4e83039`, eight-target compile PASS, package `14508452647`; [record](Architecture_M6_CP3_CB168E_P13_Entry_Coincidence_Arrival_Receipt_Code_Build_Record_20261119.md). No runtime. |
| NEXT (Test + Benchmark) | `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-EXEC` | TB144 manifest `fc1264e9…e949`; 964 records vs TB144 (N1–N7, receipt suffix stripped); EC3 census. |
| Then (Review) | `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-REV` | Freezes EC3 transverse switch as exact patch. |
| Prospective (RA-266 S3) | EC3 transverse (entry, entry) switch, sphere O47 (TB) → CB168 binding → [O49] → CB169 H4 cutover → CB170 → CB171 → CB172 (O48, incl. same-face merge) | CB172 after vertex-overlap rule + tie control, deletes CB160/CB166 receipts. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | After the TB132 Review; 858 after the sphere repair. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS`; `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON` (prior provisional routes only) | Replaced by CB151; by CB153 (RA-251); by RA-253 S1/S7 N3–N5; by CB156/TB133 (RA-254). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked; O45 consumer proxy closed narrowly. |


## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [CB168E compile record](Architecture_M6_CP3_CB168E_P13_Entry_Coincidence_Arrival_Receipt_Code_Build_Record_20261119.md), [CB168D compile record](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Code_Build_Record_20261119.md), [RA-266](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md#ra-266--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168D/CB168E/TB145 plan](Architecture_M6_CP3_CB168D_P13_Carrier_Contact_Edge_Node_Binding_Plan_20261119.md), [TB144 Review](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Independent_Review_20261119.md), [TB144 execution report](Architecture_M6_CP3_TB144_P13_Framing_And_Struck_Position_Full_Gate_Execution_Report_20261119.md), [RA-265](Architecture_M6_CP3_TB143_P13_Entry_Coincidence_Receipt_Full_Gate_Independent_Review_20261119.md#ra-265--adversarial-re-review-of-this-review-2026-11-19-utc), TB143 Review/execution, CB168A record, RA-264 (TB142 Review), [RA-263](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Independent_Review_20261118.md#ra-263--adversarial-re-review-of-this-review-2026-11-18-utc), CB167 record, TB141 Review, [RA-262 S2–S5](Architecture_M6_CP3_TB140_P13_Trace_Segment_Pieces_Helper_Full_Gate_Independent_Review_20261118.md#ra-262--exact-piece-ownership-contract-design-stop-resolved-2026-11-18-utc), RA-261 S2–S5, RA-260 S2–S4, RA-259 S3. Mandatory policies apply.

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
