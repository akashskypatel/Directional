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
| Currency | 2026-11-21 UTC: [TB155 execution](Architecture_M6_CP3_TB155_P13_Trace_Piece_Producer_Switch_Full_Gate_Execution_Report_20261121.md) is **RED** on CB-171 compiled source `65ae140e49db5bd04d202390e71b50f455ff152e`: full gate 970/971, row858 RED and prohibited shared-edge reason at 644/669/698. Census matches 3/3. Independent [M6-CP3-TB-REV-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE](Architecture_M6_CP3_TB155_P13_Trace_Piece_Producer_Switch_Full_Gate_Independent_Review_20261121.md) rejects promotion and owns a bounded next CB. |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`; immutable CB-171 source `65ae140e49db5bd04d202390e71b50f455ff152e`, artifact `14702459291`, ZIP SHA-256 `b6484dc9c88b33e2456d07f92019360999426fb02eff862950caa929cf5c88f6`; eight GMP/GMPXX targets, compile-only source package. No new compile in TB155. |
| Current gate | [TB155 gate 44895154802](https://github.com/akashskypatel/Directional/actions/runs/44895154802), result `14704220616` ZIP SHA-256 `e4e08a887f2d9b1ccddb174cba19e78d71df1934e603a51e7e57431a06f46358`, 1,950/1,950 checks, 970 PASS/1 RED row858; 960/960 non-A MATCH TB154; prohibited `RotationTraceRaysAlongSharedEdge` rows644/669/698. TB154 971/971 remains last green gate. |
| Current census | [TB155 census 44895169959](https://github.com/akashskypatel/Directional/actions/runs/44895169959), result `14704657114` ZIP SHA-256 `fcd296b4664ecfb905a81ff204637a51d831cd44de469b10e5ddbee4276ed68b`, 9/9 checks; 3/3 MATCH TB151 N1–N4, platform digest unchanged: Cylinder PASS, BunnyRandom/Vase expected RED at `:493`. |
| Accepted history | CP2 491/491, package `11391685901`. TB125 scoped 950/950, package `14289730737`/`14289927334`; TB127 gate 951/951. CP3's 497 identities remain frozen/unpromoted. |
| Regression/debt | **TB155 new candidate:** accepted row858 lost PASS and shared-edge guard triggers at 644/669/698. Stable ledger remains 66/17/49 pending independent attribution; one produced-witness debt, 81 deferred. O47/C5/O48/O49 and sphere χ+4 remain open; CP2 491/491 accepted. |
| Active boundary | TB155 sphere production exits with `CellularityNotEstablished/origin=RotationSystemInconsistent` on trace14 edge0–69, before cut-search exhaustion; independent row686 still reports `V18/E30/F18`, χ6 vs sourceχ2. Four unowned slide contacts remain. Stop switch and downstream work held for TB-REV-155. |

## Mandatory next turn — `M6-CP3-CB-172A-P13-CUT-CANDIDATE-SHARED-EDGE-INCIDENCE` — EXACT NEXT

- **Type:** Code + Build, compile only, **not** authorized for execution in this Review chat. Its frozen scope, falsifiers and STOP gates are in [Architecture_M6_CP3_CB172A_P13_Cut_Candidate_Shared_Edge_Incidence_Code_Build_Plan_20261121.md](Architecture_M6_CP3_CB172A_P13_Cut_Candidate_Shared_Edge_Incidence_Code_Build_Plan_20261121.md). First identify both exact incidences at the trace14 source edge 0–69, including new cut candidates. A plausible source is cut-graph saturation; it is not a proven root cause until the second owner is identified.
- **Evidence authority:** independent [M6-CP3-TB-REV-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE](Architecture_M6_CP3_TB155_P13_Trace_Piece_Producer_Switch_Full_Gate_Independent_Review_20261121.md) rejected TB155 970/971, row858 accepted assertion, forbidden reasons rows644/669/698; confirmed 960/960 protected rows, census 3/3 and CP2 491/491. Three-case TB151 baselines remain unchanged. RA-275 S4a seed and four sphere slide contacts are carried.
- **Prohibited:** deleting the guard, inventing an along-edge ordering, weakening row858, changing accepted selectors, running tests in CB, or starting the stop switch, O48/O49 or release work.
- **After CB, not before:** fresh artifact-only TB and independent Review. No checkpoint acceptance yet.


## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB141 EXEC/REV, RA-250–RA-262, CB150–CB166 | H1/H2, FC-7′; contact receipts; slide contact and pieces defined; EPO contract (RA-262). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-263–RA-274, CB167, CB168A–CB168N, TB142–TB151 EXEC/REV | O47 track; mutual stop (CB168F/G); four sphere slide contacts = +4; slide cut (CB168L); counts field (CB168N); [TB151 REV + RA-274](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Independent_Review_20261120.md) reader classification S3. |
| COMPLETE | CB168O (`1df6a09ad`, pkg `14628449217`), TB152 EXEC/REV | `edge_piece_face_side`, row 967; 967/967 PASS. |
| COMPLETE (Review) | RA-275 | TB152 upheld; TB152-REV's CB168P/CB168Q withdrawn (retained in Git at `e3a7bfc38`). |
| COMPLETE (Review) | RA-276 | RA-275's CB168P withdrawn (failing row 968, one of three ownership readers, O49 off the switch path), retained in Git at `41b94c585`. Real-piece reach receipt and rebased oracle frozen. |
| Withdrawn | `M6-CP3-DEFN-P13-SOURCE-ARC-READER-CLASSIFICATION` (RA-274); older provisional routes (RA-251–RA-267) | [Record](Architecture_M6_CP3_DEFN_P13_Source_Arc_Reader_Classification_Plan_20261120.md). |
| COMPLETE | CB168R, CB168Q, TB153 EXEC/REV, CB169, TB-EXEC-154, TB-REV-154 | Real-piece reach/oracle; piece-ray helpers; [TB154 execution](Architecture_M6_CP3_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Execution_Report_20261121.md) 971/971; [TB154 Review](Architecture_M6_CP3_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Independent_Review_20261121.md). |
| COMPLETE (Review) | `M6-CP3-RA-277-TB-REV-154-ADVERSARIAL-REVIEW` | [Qualified PASS](Architecture_M6_CP3_RA277_TB154_Adversarial_ReReview_20261121.md); RA-277-NV1. |
| COMPLETE (Code + Build) | `M6-CP3-CB-169S-P13-TRACE-PIECE-PRODUCER-SWITCH` | `ee0f478ad`, pkg `14700703142`; [record](Architecture_M6_CP3_CB169S_P13_Trace_Piece_Producer_Switch_Code_Build_Record_20261121.md); unexecuted. |
| COMPLETE (Review) | `M6-CP3-RA-278-RA-277-AND-CB-169S-ADVERSARIAL-REVIEW` | [RA-278](Architecture_M6_CP3_RA278_RA277_And_CB169S_Adversarial_Review_20261121.md): CB169S kept; C1–C4 corrections frozen; RA-273 S2.3 withdrawn. |
| COMPLETE (Code + Build) | `M6-CP3-CB-170-P13-SEMANTIC-DIGEST-AND-PIECE-COUNT-ORACLE-RESTORE` | [Record](Architecture_M6_CP3_CB170_P13_Semantic_Digest_And_Piece_Count_Oracle_Restore_Code_Build_Record_20261121.md); digest revert and row 966 oracle compiled, no runtime. |
| COMPLETE (Code + Build) | `M6-CP3-CB-171-P13-EDGE-LOCUS-RANK-AND-ALONG-EDGE-COINCIDENCE` | [Record](Architecture_M6_CP3_CB171_P13_Edge_Locus_Rank_And_Along_Edge_Coincidence_Code_Build_Record_20261121.md); C2/C3 exact frozen patch, `65ae140e49db5bd04d202390e71b50f455ff152e`, artifact `14702459291`, eight GMP targets, no runtime. |
| COMPLETE (Test + Benchmark, RED) | `M6-CP3-TB-EXEC-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE` | [Report](Architecture_M6_CP3_TB155_P13_Trace_Piece_Producer_Switch_Full_Gate_Execution_Report_20261121.md): 970/971; row858 RED, forbidden reason rows644/669/698, all 960 non-A MATCH; census3/3 MATCH, CP2 491/491. |
| COMPLETE (Review, rejection) | `M6-CP3-TB-REV-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE` | [Report](Architecture_M6_CP3_TB155_P13_Trace_Piece_Producer_Switch_Full_Gate_Independent_Review_20261121.md): TB155 STOP upheld, candidate shared-edge and row858 loss attributed; C3 actual collision unresolved; RA-275 S4a carried; no promotion. |
| NEXT (Code + Build) | `M6-CP3-CB-172A-P13-CUT-CANDIDATE-SHARED-EDGE-INCIDENCE` | [Frozen plan](Architecture_M6_CP3_CB172A_P13_Cut_Candidate_Shared_Edge_Incidence_Code_Build_Plan_20261121.md): exact conflicting incident-pair authority then guarded source correction; compile only. |
| Prospective | stop-switch helper CB → stop-switch CB → TB → slide-plan conformity turn → O48 carrier turns (formerly provisional "CB-170–CB-172", renumbered when frozen) | O49 off the switch path (RA-276 S2.3). |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | 858 after the sphere repair. |
| Parked | `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked. |


## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB155 execution + exact A-row annex](Architecture_M6_CP3_TB155_P13_Trace_Piece_Producer_Switch_Full_Gate_Execution_Report_20261121.md), [TB155 exact differences](Architecture_M6_CP3_TB155_First_Normalized_Difference_Pairs_20261121.txt), [CB171 compiled record](Architecture_M6_CP3_CB171_P13_Edge_Locus_Rank_And_Along_Edge_Coincidence_Code_Build_Record_20261121.md), [CB170 compiled record](Architecture_M6_CP3_CB170_P13_Semantic_Digest_And_Piece_Count_Oracle_Restore_Code_Build_Record_20261121.md), [RA-278](Architecture_M6_CP3_RA278_RA277_And_CB169S_Adversarial_Review_20261121.md), [CB170 diff](Architecture_M6_CP3_CB170_P13_Digest_And_Piece_Count_Oracle_Restore_Exact.diff), [CB171 diff](Architecture_M6_CP3_CB171_P13_Edge_Locus_Rank_And_Along_Edge_Coincidence_Exact.diff), [CB169S record](Architecture_M6_CP3_CB169S_P13_Trace_Piece_Producer_Switch_Code_Build_Record_20261121.md), [RA-277](Architecture_M6_CP3_RA277_TB154_Adversarial_ReReview_20261121.md), [TB154 Review](Architecture_M6_CP3_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Independent_Review_20261121.md), [TB154 execution](Architecture_M6_CP3_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Execution_Report_20261121.md), [CB169 record](Architecture_M6_CP3_CB169_P13_Trace_Piece_Ray_Helpers_Code_Build_Record_20261121.md), [TB153 Review](Architecture_M6_CP3_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Independent_Review_20261121.md), [CB169 diff](Architecture_M6_CP3_CB169_P13_Trace_Piece_Ray_Helpers_Exact.diff), [TB154 manifest](gates/Architecture_M6_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Case_Manifest.tsv), [TB153 execution](Architecture_M6_CP3_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Execution_Report_20261121.md), [CB168Q record](Architecture_M6_CP3_CB168Q_P13_Row686_Real_Piece_Oracle_Code_Build_Record_20261121.md), [CB168R record](Architecture_M6_CP3_CB168R_P13_Sphere_Real_Piece_Reach_Receipt_Code_Build_Record_20261121.md), [TB152 Review + RA-275 + RA-276](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Independent_Review_20261120.md), [CB168R diff](Architecture_M6_CP3_CB168R_P13_Sphere_Real_Piece_Reach_Receipt_Exact.diff), [CB168Q diff](Architecture_M6_CP3_CB168Q_Row686_Real_Piece_Oracle_On_Receipt_Exact.diff), [TB153 manifest](gates/Architecture_M6_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Case_Manifest.tsv), [TB152 execution](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Execution_Report_20261120.md), [CB168O record](Architecture_M6_CP3_CB168O_P13_Edge_Piece_Face_Side_Helper_Code_Build_Record_20261120.md), [TB151 Review + RA-274](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Independent_Review_20261120.md), [CB168M EPO-3 plan](Architecture_M6_CP3_CB168M_P13_Source_Piece_Counts_Binding_Plan_20261120.md), [TB150 Review + RA-273](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Independent_Review_20261120.md), [RA-271](Architecture_M6_CP3_TB149_P13_Slide_Contact_Arrival_Full_Gate_Independent_Review_20261120.md), [TB148 Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md), [RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc), [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc); compile records, diffs and executions resolve through these Reviews; RA-266–RA-259. Mandatory policies apply.

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
