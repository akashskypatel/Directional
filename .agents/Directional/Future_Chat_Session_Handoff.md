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
| Currency | 2026-11-20 UTC: [RA-276](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Independent_Review_20261120.md#ra-276--adversarial-re-review-of-ra-275-2026-11-20-utc) re-reviewed RA-275. TB152 PASS stands (967/967, 966/966 MATCH TB151 N1–N3, CP2 491/491). RA-275's CB168P is withdrawn for four reasons: its row 968 would fail; it wired one of three ownership readers; O49 does not gate the producer switch; and the switch's precondition is unmeasured. Next are two test-only CBs: CB168R (sphere real-piece reach receipt, row 968) and CB168Q (row 686 fail-closed real-piece oracle). Then one TB153 (gate only; no census, since product source is unchanged). Re-confirmed at 15:31 UTC: no implementation commits since RA-276. At HEAD `f2d511c37` the precheck passes, both diffs apply stacked, and the tests file hashes `f19009d7…` → `db2bd6f0…` (after CB168R) → `632a147f1929ec45a2087176fb8196283e21295fe3dd2f437263a1f7cdfdcc59` (after CB168Q). |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB168O source `1df6a09ad386791a9befddd9658ddc4d5bb795f2`, artifact `14628449217` (ZIP SHA-256 `20c8aed1d38e42cd00fc6cd5f790fd8d23075fe3cb8bc25522304c54886b3709`); [record](Architecture_M6_CP3_CB168O_P13_Edge_Piece_Face_Side_Helper_Code_Build_Record_20261120.md), eight GMP/GMPXX targets, `runtimeExecution=false`. |
| Current gate | [TB152 run 44739657527](https://github.com/akashskypatel/Directional/actions/runs/44739657527), artifact `14630642490` (ZIP SHA-256 `5bfce8410e736c1fce63c4c6fa9b272b20ff91ceac8044bb339c814bfaa3cd04`); 967/967 PASS, 966/966 MATCH TB151 N1–N3, CP2 491/491, membership 1048, 504 unmasked slide-contact receipts. [Execution](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Execution_Report_20261120.md). |
| Current census | [TB151 run 44719007530](https://github.com/akashskypatel/Directional/actions/runs/44719007530), artifact `14621727104` (ZIP SHA-256 `4eacb6f3d9d272a2ee380527fc8f7abab516508a596d3dea3f955e8086a4c611`); Cylinder PASS, BunnyRandom/Vase expected RED at `:493`, 3/3 MATCH TB150 N1–N4. |
| Accepted history | CP2 491/491, package `11391685901`. TB125 scoped 950/950, package `14289730737`/`14289927334`; TB127 gate 951/951. CP3's 497 identities remain frozen/unpromoted. |
| Regression/debt | Stable 66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48/O49 open; C3/O44/C1 and O45 narrow proxy closed. D11=A, D12=A, D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Row 686: sphere χ6 vs 2 (+4 = four unowned slide contacts), producer `CutSearchExhaustedBeforeCellularity`. Rows 669/698 exhaust the same way. No gate row reaches source-face ownership, which needs a disc embedding. Production arcs and the row 686 oracle write slides as face chords. EPO-5 (RA-271 S4): slide-interior cuts exist on the edge piece in the piece path only. The stop switch waits for the producer switch. |

## Mandatory next turn — `M6-CP3-CB168R-P13-SPHERE-REAL-PIECE-REACH-RECEIPT` — Code + Build only (test-only)

Apply only the [exact diff](Architecture_M6_CP3_CB168R_P13_Sphere_Real_Piece_Reach_Receipt_Exact.diff), SHA-256 `5aee7b0984444dd35aff935764beabd10070b5ed766b25dbe19b882f7739bfec` (`86 0` tests/FieldAlignedCurveNetworkTests.cpp).
- Before applying: `git diff --quiet 1df6a09ad HEAD -- src include tests`; the tests preimage must be `f19009d7aa42c9b1fd5a02b2d1e8988f5a9153baff64368658e797bd26f42658`; then `git apply --check`.
- Build: compile the eight RA-245 GMP/GMPXX targets with `runtimeExecution=false`. Run no tests.
- Do not touch product source or start CB168Q in the same turn.

Then `M6-CP3-CB168Q-P13-ROW686-REAL-PIECE-ORACLE`, test-only: [diff](Architecture_M6_CP3_CB168Q_Row686_Real_Piece_Oracle_On_Receipt_Exact.diff) `0c096c94c8124dbf541e96abc07b4c5810d4705dd6ffd6e7f066ecd6aa91d2e5` (`72 4` tests). Its preimage is the tests file after CB168R, `db2bd6f04cca09ddb61804a2ec92feb7165ab82381ecba90928bbeb1fc691cb3`.

TB153 runs on source whose tests file hash is `632a147f…dcc59` and whose product source is unchanged from `1df6a09ad`. Then TB153: [manifest](gates/Architecture_M6_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Case_Manifest.tsv) `fc075b4c33e0f934d8636a4c9c4186d19fea24e5cd6ae88e516c5c6ff1514116`, 968 + 81, gate only. STOP rules are in [RA-276 S3](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Independent_Review_20261120.md#s3--realignment-exact--fsyntax-only-0-errors-warnings-42--head-stacked-git-apply---check-on-546243920).

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB141 EXEC/REV, RA-250–RA-262, CB150–CB166 | H1/H2, FC-7′; contact receipts; slide contact and pieces defined; EPO contract (RA-262). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-263–RA-274, CB167, CB168A–CB168N, TB142–TB151 EXEC/REV | O47 track; mutual stop (CB168F/G); four sphere slide contacts = +4; slide cut (CB168L); counts field (CB168N); [TB151 REV + RA-274](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Independent_Review_20261120.md) reader classification S3. |
| COMPLETE | CB168O (`1df6a09ad`, pkg `14628449217`), TB152 EXEC/REV | `edge_piece_face_side`, row 967; 967/967 PASS. |
| COMPLETE (Review) | RA-275 | TB152 upheld; TB152-REV's CB168P/CB168Q withdrawn (retained in Git at `e3a7bfc38`). |
| COMPLETE (Review) | RA-276 | RA-275's CB168P withdrawn (failing row 968, one of three ownership readers, O49 off the switch path), retained in Git at `41b94c585`. Real-piece reach receipt and rebased oracle frozen. |
| Withdrawn | `M6-CP3-DEFN-P13-SOURCE-ARC-READER-CLASSIFICATION` (RA-274); older provisional routes (RA-251–RA-267) | [Record](Architecture_M6_CP3_DEFN_P13_Source_Arc_Reader_Classification_Plan_20261120.md). |
| NEXT (Code + Build) | `M6-CP3-CB168R-P13-SPHERE-REAL-PIECE-REACH-RECEIPT` | Exact diff `5aee7b09…bfec`, test-only, compile only. |
| Then (Code + Build) | `M6-CP3-CB168Q-P13-ROW686-REAL-PIECE-ORACLE` | Exact diff `0c096c94…d2e5`, test-only, compile only. |
| Then (Test + Benchmark) | `M6-CP3-TB153-P13-REAL-PIECE-REACH-AND-ROW686-ORACLE-FULL-GATE-EXEC` | Gate 968, no census. Row 968 PASS with its lines reported; prior rows MATCH TB152 N1–N3 except row 686, whose two-ring and torus records stay equal and whose sphere record is reported. |
| Then (Review) | `M6-CP3-TB153-P13-REAL-PIECE-REACH-AND-ROW686-ORACLE-FULL-GATE-REV` | Use row 968 to decide the switch's shape: if it shows no failures, an unwired piece-ray helper then the switch CB; otherwise a producer-rule fix first. Use the walls' `terminalBarrier` to decide whether the stop switch needs arc-piece ownership in all three readers. |
| Prospective | Producer switch (paths + counts + rays + ranks, counts in the digest) → TB → [arc-piece ownership helper → readers, only if row 968 requires] → stop switch CB (`carrier_contact_slide_position`) → TB (row 686 χ=2, rows 669/698, four nodes, real-piece conformity) → CB170 → CB171 → CB172 (O48) | Paths and rays switch together (RA-261). O49 ownership is off the switch path (RA-276 S2.3); held until a witness exists. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | 858 after the sphere repair. |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked. |


## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB152 Review + RA-275 + RA-276](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Independent_Review_20261120.md), [CB168R diff](Architecture_M6_CP3_CB168R_P13_Sphere_Real_Piece_Reach_Receipt_Exact.diff), [CB168Q diff](Architecture_M6_CP3_CB168Q_Row686_Real_Piece_Oracle_On_Receipt_Exact.diff), [TB153 manifest](gates/Architecture_M6_TB153_P13_Real_Piece_Reach_And_Row686_Oracle_Full_Gate_Case_Manifest.tsv), [TB152 execution](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Execution_Report_20261120.md), [CB168O record](Architecture_M6_CP3_CB168O_P13_Edge_Piece_Face_Side_Helper_Code_Build_Record_20261120.md), [TB151 Review + RA-274](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Independent_Review_20261120.md), [CB168M EPO-3 plan](Architecture_M6_CP3_CB168M_P13_Source_Piece_Counts_Binding_Plan_20261120.md), [TB150 Review + RA-273](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Independent_Review_20261120.md), [RA-271](Architecture_M6_CP3_TB149_P13_Slide_Contact_Arrival_Full_Gate_Independent_Review_20261120.md), [TB148 Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md), [RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc), [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc); compile records, diffs and executions resolve through these Reviews; RA-266–RA-259. Mandatory policies apply.

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
