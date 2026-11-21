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
| Currency | 2026-11-21 UTC: CB169 COMPLETE (compiled, not executed): unwired piece-ray helpers at `ef86370d0`, [record](Architecture_M6_CP3_CB169_P13_Trace_Piece_Ray_Helpers_Code_Build_Record_20261121.md). Baseline TB153 Review: PASS upheld (968/968; 966/966 MATCH TB152 N1–N3). TB154 EXEC is next. |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB169 source `ef86370d0a1436250bdc8417b6b1abdeb1df5a74`, artifact `14694154267` (ZIP SHA-256 `ad39099eba5b02262c9287613d2c5921bdabd24442a47ed21fdd70c9e0340d77`); run 44871935919, eight GMP/GMPXX targets, `runtimeExecution=false`. |
| Current gate | [TB153 run 44867242174](https://github.com/akashskypatel/Directional/actions/runs/44867242174), artifact `14692372657` (ZIP SHA-256 `5e102074ae1bbfcf9c1a94a928e8d354725b484c67fa7dc53410d887a12f8147`); 968/968 PASS, membership 1049, 492 unmasked slide-contact receipts, 1,742 M3 records. Baseline TB152 run 44739657527, artifact `14630642490`. |
| Current census | [TB151 run 44719007530](https://github.com/akashskypatel/Directional/actions/runs/44719007530), artifact `14621727104` (ZIP SHA-256 `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611`); Cylinder PASS, BunnyRandom/Vase expected RED at `:493`, 3/3 MATCH TB150 N1–N4. |
| Accepted history | CP2 491/491, package `11391685901`. TB125 scoped 950/950, package `14289730737`/`14289927334`; TB127 gate 951/951. CP3's 497 identities remain frozen/unpromoted. |
| Regression/debt | Stable 66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48/O49 open; C3/O44/C1 and O45 narrow proxy closed. D11=A, D12=A, D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Row 686: sphere χ6 vs 2 (+4 = four unowned slide contacts), producer `CutSearchExhaustedBeforeCellularity`; the real-piece oracle keeps χ6. Rows 669/698 exhaust the same way. No gate row reaches source-face ownership, which needs a disc embedding. Production arcs still write slides as face chords; the switch waits for TB154 and TB154-REV (CB169 helpers landed). The stop switch waits for the producer switch. |

## Mandatory next turn — `M6-CP3-TB154-P13-TRACE-PIECE-RAY-HELPERS-FULL-GATE-EXEC` — EXACT NEXT

- **Type / owner:** Test + Benchmark (artifact only), implementation agent.
- **Objective:** run the immutable CB169 package through the 971-row gate and a TB151-reproducing census, to check that the helpers are inert and the three block moves preserve behaviour.
- **Read before work:** [TB153 Review](Architecture_M6_CP3_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Independent_Review_20261121.md) S4 (STOP rules, census recipe); [CB169 record](Architecture_M6_CP3_CB169_P13_Trace_Piece_Ray_Helpers_Code_Build_Record_20261121.md).
- **In scope:**
  - gate manifest [TB154](gates/Architecture_M6_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Case_Manifest.tsv) SHA-256 `0f9c417c6bb4b563abc90e5707eee98656210df322f5e0d00af1efc8f9f4e305` (TB153 byte prefix + rows 969–971; 971 + 81) on package `14694154267` at `ef86370d0`; baseline TB153 result `14692372657`;
  - census: `gates/Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` (SHA-256 `3af1dc0d…e793`), harness `tools/m6_cp3_targeted_artifact_harness.sh` (`78b8002c…3e94`), baseline TB151 census artifact `14621727104`.
- **Out of scope:** any rebuild, source, test, fixture or manifest change; interpretation beyond the STOP rules.
- **Success evidence:** rows 969–971 PASS with row 971's `SpherePieceRayReceipt`, `SpherePieceRaySlideEnd` and `SpherePieceRay` lines verbatim; rows 1–968 MATCH TB153 under N1–N3, row 686 included; census 3/3 MATCH TB151 under N1–N4; CP2 491/491.
- **On success:** `M6-CP3-TB154-P13-TRACE-PIECE-RAY-HELPERS-FULL-GATE-REV`: checks the row 971 predictions and freezes the producer switch CB, with the RA-274 S5 checks.
- **On failure/blocker:** UNKNOWN — STOP; STATUS BLOCKED; return to Review; do not repair inside the gate.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB141 EXEC/REV, RA-250–RA-262, CB150–CB166 | H1/H2, FC-7′; contact receipts; slide contact and pieces defined; EPO contract (RA-262). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-263–RA-274, CB167, CB168A–CB168N, TB142–TB151 EXEC/REV | O47 track; mutual stop (CB168F/G); four sphere slide contacts = +4; slide cut (CB168L); counts field (CB168N); [TB151 REV + RA-274](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Independent_Review_20261120.md) reader classification S3. |
| COMPLETE | CB168O (`1df6a09ad`, pkg `14628449217`), TB152 EXEC/REV | `edge_piece_face_side`, row 967; 967/967 PASS. |
| COMPLETE (Review) | RA-275 | TB152 upheld; TB152-REV's CB168P/CB168Q withdrawn (retained in Git at `e3a7bfc38`). |
| COMPLETE (Review) | RA-276 | RA-275's CB168P withdrawn (failing row 968, one of three ownership readers, O49 off the switch path), retained in Git at `41b94c585`. Real-piece reach receipt and rebased oracle frozen. |
| Withdrawn | `M6-CP3-DEFN-P13-SOURCE-ARC-READER-CLASSIFICATION` (RA-274); older provisional routes (RA-251–RA-267) | [Record](Architecture_M6_CP3_DEFN_P13_Source_Arc_Reader_Classification_Plan_20261120.md). |
| COMPLETE (Code + Build) | `M6-CP3-CB168R-P13-SPHERE-REAL-PIECE-REACH-RECEIPT` | Row 968, `7061c8b84`, pkg `14691194223`; compiled, not executed. |
| COMPLETE (Code + Build) | `M6-CP3-CB168Q-P13-ROW686-REAL-PIECE-ORACLE` | Diff `0c096c94…d2e5`, `203150dff`, pkg `14692425922`; compiled, not executed. |
| COMPLETE (Test + Benchmark) | `M6-CP3-TB153-P13-REAL-PIECE-REACH-AND-ROW686-ORACLE-FULL-GATE-EXEC` | TB153 EXEC COMPLETE: [run 44867242174](https://github.com/akashskypatel/Directional/actions/runs/44867242174), artifact `14692372657`; 968/968 PASS, rows MATCH TB152 except 686, sphere record changed (finding). |
| COMPLETE (Review) | `M6-CP3-TB153-P13-REAL-PIECE-REACH-AND-ROW686-ORACLE-FULL-GATE-REV` | PASS upheld; row 686 attributed; CB169 frozen; arc-piece ownership held until the stop-switch TB measures suffix separation. |
| COMPLETE (Code + Build) | `M6-CP3-CB169-P13-TRACE-PIECE-RAY-HELPERS` | `ef86370d0`, pkg `14694154267`; compiled, not executed. |
| NEXT (Test + Benchmark) | `M6-CP3-TB154-P13-TRACE-PIECE-RAY-HELPERS-FULL-GATE-EXEC` | Gate 971 + census. |
| Then | `M6-CP3-TB154-…-FULL-GATE-REV` | Checks the row 971 predictions and freezes the producer switch CB. |
| Prospective | Producer switch (paths + counts + rays + ranks, counts in the digest) → TB → stop switch CB (+ suffix-separation receipt) (`carrier_contact_slide_position`) → TB (row 686 χ=2, rows 669/698, four nodes, real-piece conformity) → CB170 → CB171 → CB172 (O48) | Paths and rays switch together (RA-261). O49 ownership is off the switch path (RA-276 S2.3); needed only if a wall suffix separates, measured at the stop-switch TB. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | 858 after the sphere repair. |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked. |


## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [CB169 record](Architecture_M6_CP3_CB169_P13_Trace_Piece_Ray_Helpers_Code_Build_Record_20261121.md), [TB153 Review](Architecture_M6_CP3_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Independent_Review_20261121.md), [CB169 diff](Architecture_M6_CP3_CB169_P13_Trace_Piece_Ray_Helpers_Exact.diff), [TB154 manifest](gates/Architecture_M6_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Case_Manifest.tsv), [TB153 execution](Architecture_M6_CP3_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Execution_Report_20261121.md), [CB168Q record](Architecture_M6_CP3_CB168Q_P13_Row686_Real_Piece_Oracle_Code_Build_Record_20261121.md), [CB168R record](Architecture_M6_CP3_CB168R_P13_Sphere_Real_Piece_Reach_Receipt_Code_Build_Record_20261121.md), [TB152 Review + RA-275 + RA-276](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Independent_Review_20261120.md), [CB168R diff](Architecture_M6_CP3_CB168R_P13_Sphere_Real_Piece_Reach_Receipt_Exact.diff), [CB168Q diff](Architecture_M6_CP3_CB168Q_Row686_Real_Piece_Oracle_On_Receipt_Exact.diff), [TB153 manifest](gates/Architecture_M6_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Case_Manifest.tsv), [TB152 execution](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Execution_Report_20261120.md), [CB168O record](Architecture_M6_CP3_CB168O_P13_Edge_Piece_Face_Side_Helper_Code_Build_Record_20261120.md), [TB151 Review + RA-274](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Independent_Review_20261120.md), [CB168M EPO-3 plan](Architecture_M6_CP3_CB168M_P13_Source_Piece_Counts_Binding_Plan_20261120.md), [TB150 Review + RA-273](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Independent_Review_20261120.md), [RA-271](Architecture_M6_CP3_TB149_P13_Slide_Contact_Arrival_Full_Gate_Independent_Review_20261120.md), [TB148 Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md), [RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc), [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc); compile records, diffs and executions resolve through these Reviews; RA-266–RA-259. Mandatory policies apply.

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
