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
| Currency | 2026-11-18 UTC: [RA-256](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md#ra-256--adversarial-re-review-of-this-review-2026-11-18-utc) upholds TB134 independent MATCH 956/956; [Review](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md); [execution report](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Execution_Report_20261118.md). Onset certified from the receipt: trace 15 is trace 43 scaled about v210 (k=0.0886278847694713), so the shared interval is [X43, v94]. The segment record drops the slide start, so CB158 records it. |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD. CB157 source `a8d1cc9603f9a556564f0b741692217ec6a791ef`, package `14389450751`, ZIP SHA-256 `d67682c649eefda89612ca9543951f9410560d15e31836e97043b6058a17f8f8`; [compile record](Architecture_M6_CP3_CB157_P13_Trace_Path_Receipt_Code_Build_Record_20261118.md). CB156 source `779fe661e260f506592c64791fbe655734029478`, package `14369087138`, ZIP SHA-256 `9bec7da392d32c0dafedb77bc08426a2aeaa795c7905e6e5facde7ad8c14d032`; [compile record](Architecture_M6_CP3_CB156_P13_Same_Face_Segment_Pair_Receipt_Code_Build_Record_20261117.md). CB155 and CB154/TB131: see compile records. CB151/TB129 authority remains in the TB129 execution report. |
| Accepted evidence | [TB125](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb125_p13_edge_terminal_exact_inventory_execution_report_20261117md) scoped 950/950; artifacts `14289730737`/`14289927334`. CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. TB127 comparison authority: package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate `14302887671` 951/951, census `14302668940`. |
| Latest candidate | TB134 gate `14390702505`, census `14391390784`, 956/956 MATCH, 952/953 gate; 66 sphere and two BunnyRandom lines with two path fields. Both postflight valid. [Report](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Execution_Report_20261118.md). Comparator TB133 gate `14381507340`, census `14383400603`. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48 open; narrow C3/O44/C1 and O45 (consumer proxy only) closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Sphere traces 4/6 cross at P on edge (0,2): C5/O47. BunnyRandom 43/15: shared co-directional interval [X43, v94] on (94,210) (RA-256 S1), then identical to trace82 (nodes220/222); 43 earlier, so trace 15 should end at X43. The slide start is not stored in `FieldAlignedCandidateTraceSegment` (RA-256 S2); H3 (classifier recompute on vertex-slide segments) unverified. O45 narrow closure kept; 858 permitted RED at :155, 648 unreached. FC-6, H2, terminal-cut held. No CP3/D0 acceptance. |

## Mandatory next turn — `M6-CP3-CB158-P13-EDGE-TRANSIT-ENTRY-RECORD` — EXACT NEXT (Code + Build, compile only)

Per [RA-256 S4](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md#ra-256--adversarial-re-review-of-this-review-2026-11-18-utc). Apply exactly `.agents/Directional/Architecture_M6_CP3_CB158_P13_Edge_Transit_Entry_Record_Exact.diff` (SHA-256 `17dd9ac558f9d2e24bd4d5010262b9d3092c9414c8d9d9bfbbbfa3b4ef12822f`, 51 lines; numstat `5 0` SurfaceCellTracing.h, `4 0` EmbeddedGraphTopology.cpp, `2 0` SurfaceCellTracing.cpp). Precheck `git diff --quiet a8d1cc9603f9a556564f0b741692217ec6a791ef HEAD -- src include tests`. Eight RA-245 GMP/GMPXX targets, runtimeExecution=false. Mismatch `M6-CP3-PLAN-P13-EDGE-TRANSIT-ENTRY-RECEIPT-STOP`; infrastructure `M6-CP3-CB158A-P13-EDGE-TRANSIT-ENTRY-RECEIPT-ORCH`. Then TB135 under RA-256 S5 (N1–N4 + N6, ratio prediction). Review track in parallel: `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` (shared edge-locus representation, RA-256 S3), then TB135-REV, then `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP`. FC-6, terminal-cut and row858 held.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB131 EXEC/REV, RA-250–RA-252, CB150–CB154 | H1/H2, FC-7′ switch; TB131 literal MISMATCH (presentation only). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-253, CB155, TB132 EXEC/REV, RA-254, CB156, TB133 EXEC | Site elimination; receipts; MATCH 956/956 each; contact-kind measurement. Records in the load list. |
| COMPLETE (MATCH upheld) | `M6-CP3-TB133-P13-SAME-FACE-SEGMENT-PAIR-RECEIPT-FULL-GATE-REV` | [Review](Architecture_M6_CP3_TB133_P13_Same_Face_Segment_Pair_Receipt_Full_Gate_Independent_Review_20261118.md): exact transverse endpoint and co-directional overlap. |
| COMPLETE | RA-255, `M6-CP3-CB157-P13-TRACE-PATH-RECEIPT`, `M6-CP3-TB134-P13-TRACE-PATH-RECEIPT-FULL-GATE-EXEC` | Four-ray proof, O48 opened; [CB157 compile](Architecture_M6_CP3_CB157_P13_Trace_Path_Receipt_Code_Build_Record_20261118.md); [TB134 report](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Execution_Report_20261118.md) MATCH 956/956. |
| Parallel (Review) | `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` | RA-255 S2 + RA-256 S3: shared edge-locus cut representation (slide-piece ordering); freezes helpers CB + wiring CB (O47). |
| COMPLETE (MATCH upheld) | `M6-CP3-TB134-P13-TRACE-PATH-RECEIPT-FULL-GATE-REV` + [RA-256](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md#ra-256--adversarial-re-review-of-this-review-2026-11-18-utc) | First equal entry v94; onset [X43, v94] certified (S1); slide start missing from the record (S2); CB158/TB135 frozen. |
| EXACT NEXT (impl) | `M6-CP3-CB158-P13-EDGE-TRANSIT-ENTRY-RECORD` | Compile only; exact +11/-0 diff. |
| Then (impl) | `M6-CP3-TB135-P13-EDGE-TRANSIT-ENTRY-FULL-GATE-EXEC` | Comparator TB134; N1–N4 + N6; criteria 1–6 of RA-256 S5. |
| Then (Review) | `M6-CP3-TB135-P13-EDGE-TRANSIT-ENTRY-FULL-GATE-REV` → `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` | DEFN uses TB135 values; freezes helpers CB then wiring CB. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | After the TB132 Review; 858 after the sphere repair. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS`; `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON` (prior provisional routes only) | Replaced by CB151; by CB153 (RA-251); by RA-253 S1/S7 N3–N5; by CB156/TB133 (RA-254). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked; O45 consumer proxy closed narrowly. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: `M6-CP3-CB158-P13-EDGE-TRANSIT-ENTRY-RECORD` (impl, compile only): read [RA-256 S4–S6](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md#ra-256--adversarial-re-review-of-this-review-2026-11-18-utc) and the exact diff; then TB135. Review track: sphere DEFN (RA-255 S2, RA-256 S3) in parallel. Mandatory policies apply.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [TB134 independent Review](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md),  [CB157 compile record](Architecture_M6_CP3_CB157_P13_Trace_Path_Receipt_Code_Build_Record_20261118.md), [TB133 independent Review](Architecture_M6_CP3_TB133_P13_Same_Face_Segment_Pair_Receipt_Full_Gate_Independent_Review_20261118.md), [TB133 execution report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb133_p13_same_face_segment_pair_receipt_full_gate_execution_report_20261118md), [CB156 compile record](Architecture_M6_CP3_CB156_P13_Same_Face_Segment_Pair_Receipt_Code_Build_Record_20261117.md), [TB132 independent Review](Architecture_M6_CP3_TB132_P13_Cut_Binding_Conflict_Receipt_Full_Gate_Independent_Review_20261117.md), [Execution report](Architecture_M6_CP3_TB132_P13_Cut_Binding_Conflict_Receipt_Full_Gate_Execution_Report_20261117.md), [CB155 compile record](Architecture_M6_CP3_CB155_P13_Cut_Binding_Conflict_Receipt_Code_Build_Record_20261117.md), [RA-253](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Independent_Review_20261117.md#ra-253--adversarial-re-review-of-this-review-2026-11-17-utc), [CB155 exact diff](Architecture_M6_CP3_CB155_P13_Cut_Binding_Conflict_Receipt_Exact.diff), [TB131 independent Review](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Independent_Review_20261117.md), [TB131 execution report](Architecture_M6_CP3_TB131_P13_Carrier_Contact_Switch_Full_Gate_Execution_Report_20261117.md), [CB154 Code + Build record](Architecture_M6_CP3_CB154_P13_Carrier_Contact_Node_Switch_Code_Build_Record_20261117.md), [RA-252 DEFN](Architecture_M6_CP3_DEFN_P13_Carrier_Contact_Switch_Review_20261117.md), [CB154 exact diff](Architecture_M6_CP3_CB154_P13_Carrier_Contact_Node_Switch_Exact.diff), [TB129 Review + RA-251](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Independent_Review_20261117.md), [TB129 execution report](Architecture_M6_CP3_TB129_P13_Terminal_Cut_Receipt_Full_Gate_Execution_Report_20261117.md), [TB128 independent Review](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Independent_Review_20261117.md), [TB128 execution report](Architecture_M6_CP3_TB128_P13_Face_Contact_Full_Gate_Execution_Report_20261117.md), [CB151 Code + Build record](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Code_Build_Record_20261117.md), [CB150 Code + Build record](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Code_Build_Record_20261117.md), exact [CB150](Architecture_M6_CP3_CB150_P13_Face_Chart_Witness_Correction_Exact.diff) and [CB151](Architecture_M6_CP3_CB151_P13_Terminal_Cut_Before_End_Receipt_Exact.diff) diffs, [CB149 compile record](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Code_Build_Record_20261117.md), [RA-249](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Freeze_Review_20261117.md) and [RA-248](Architecture_M6_CP3_DEFN_P13_Face_Contact_Node_Definition_Review_20261117.md). Preserve [CB147](Architecture_M6_CP3_CB147_P13_Face_Contact_Exact_Helpers_Exact.diff), [CB148](Architecture_M6_CP3_CB148_P13_Face_Contact_Node_Helpers_Exact.diff), [CB149](Architecture_M6_CP3_CB149_P13_Face_Contact_Node_Switch_Exact.diff) exact diffs and frozen gate/census. Prior records resolve through [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
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
