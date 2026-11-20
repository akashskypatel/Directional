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
| Currency | 2026-11-20 UTC: TB148 Review + [RA-270](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md#ra-270--adversarial-re-review-of-this-review-2026-11-20-utc). Gate 963/963, 962/962 MATCH TB147, 491/491. Four unowned sphere entry-on-sliding-wall contacts confirmed (RA-269 prediction held). Prose CB168K consumer withdrawn; exact CB168K diagnostic receipt compiled at `0955d28e37a4f17f2488f0f4dd196a2d24aa3c11` ([run 44679070165](https://github.com/akashskypatel/Directional/actions/runs/44679070165)); next TB149 measures arrival order before any repair. |
| Branch and immutable package | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB168I source `0f738b1c6d3971c1e414039623336d1baa7965d1`, package `14589748220` ZIP SHA-256 `5c74512cdc1cef967ee2968a7055b3323722298259170cae3cc74b8755864bb0`. |
| CB168J compiled receipt | Compile-only run [44665889239](https://github.com/akashskypatel/Directional/actions/runs/44665889239), exact source `d78404724a7f0bfb0c9c73769e6a68b9f2addd81`, immutable package `14596864941` (ZIP SHA-256 `d7b9a99a5b9bf3d50cf9f8df7890d2cabb5f61004a338a9cd1c80e9dac3064b4`); eight RA-245 GMP/GMPXX targets, `runtimeExecution=false`, no tests. [Record](Architecture_M6_CP3_CB168J_P13_Sphere_Entry_On_Sliding_Wall_Receipt_Code_Build_Record_20261120.md). |
| CB168K compiled arrival receipt | Exact +28/-0 diagnostic to `src/geometry/SurfaceCellTracing.cpp` at `0955d28e37a4f17f2488f0f4dd196a2d24aa3c11`, [compile run 44679070165](https://github.com/akashskypatel/Directional/actions/runs/44679070165), immutable artifact `14603866682` (archive SHA-256 `b5da1e638be05ec80dd946a15d417e40f3613b5ada6652224bea1fdba5fef8d8`), eight GMP/GMPXX targets, `runtimeExecution=false`, no tests. [Record](Architecture_M6_CP3_CB168K_P13_Slide_Contact_Arrival_Receipt_Code_Build_Record_20261120.md). |
| Current gate | [TB148 run 44668273156](https://github.com/akashskypatel/Directional/actions/runs/44668273156), result artifact `14598534659` (ZIP SHA-256 `dac729fa05bb68c53c908476b4c32dfebe21f5f21d82743bcff58e31c7294c4e`); 963/963 PASS, accepted 491/491, membership 1044 including deferred81, 962/962 prior-row MATCH TB147 under N1–N3. Row963 four exact same-face committed sliding-wall entries, sharedEvents=0 each. [TB148 report](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Execution_Report_20261120.md). |
| Current census | [Run 44654270153](https://github.com/akashskypatel/Directional/actions/runs/44654270153), result artifact `14591964172`; 1/3 PASS/expected RED. See report for exact Cylinder/BunnyRandom/Vase outcomes and comparison with TB145. |
| Accepted history | CP2 491/491, package `11391685901`. TB125 scoped 950/950, package `14289730737`/`14289927334`; TB127 gate 951/951. CP3's 497 identities remain frozen/unpromoted. |
| Regression/debt | Stable 66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48 open; C3/O44/C1 and O45 narrow proxy closed. D11=A, D12=A, D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Row686 χ6 vs 2 (+4 = four unowned slide contacts); rows669/698 `CutSearchExhaustedBeforeCellularity`. No cut position on a slide edge piece exists (`exact_trace_interior_point` fails closed on slides). Row686 oracle reads slides as chords and must switch to real pieces BEFORE the repair TB ([RA-270](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md#ra-270--adversarial-re-review-of-this-review-2026-11-20-utc) S2.3). No H4/O49/O48/FC-6 change. |

## Mandatory next turn — `M6-CP3-TB149-P13-SLIDE-CONTACT-ARRIVAL-FULL-GATE-EXEC` — Test + Benchmark (immutable artifact only)

Consume the CB168K compiled package, source `0955d28e37a4f17f2488f0f4dd196a2d24aa3c11`, without rebuild or source/test changes. Run the existing unchanged TB148 manifest SHA-256 `4350378c95fefeb0dbab6e742b50dcd976af406f865ddef45cc03b35f7b4c01c` (963 gate identities plus 81 deferred). Normalize only the new `FieldAlignedCurveNetwork.slideContactArrival` diagnostic lines; then 963/963 prior rows must MATCH TB148 and accepted prefix 491/491 must remain PASS. Run the three-case census and require 3/3 comparison MATCH TB147 after the same normalization. Preserve all new receipt lines verbatim for independent Review. Prediction: four sphere records `wallCommitted=1 movingArrival=later`; this remains unverified. STOP on any mismatch. No consumer, stop switch, oracle, or cut-position change in this TB. [RA-270](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md#ra-270--adversarial-re-review-of-this-review-2026-11-20-utc) S3 owns this boundary.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB131 EXEC/REV, RA-250–RA-252, CB150–CB154 | H1/H2, FC-7′ switch; TB131 literal MISMATCH (presentation only). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-253–RA-262, CB155–CB166, TB132–TB141 EXEC/REV | Contact receipts, H3 closed narrowly, slide contact (RA-259 S3) and pieces (RA-260 S2) defined, EPO contract (RA-262); MATCH through [TB141](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Execution_Report_20261118.md) 962/962; records via the load list and folded index. |
| COMPLETE | RA-263–RA-266, CB167, CB168A–CB168E, TB142–TB145 EXEC/REV | O47 track before H4; EC1 receipt; framing single-write; carrier-contact helper + edge-node binding (inert); arrival/face receipt; MATCH through TB145 964/964. Records via RA-266/RA-267 and the folded index. |
| COMPLETE (Review) | `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-REV` + [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc) | 964/964 MATCH upheld; DEFN withdrawn (rule exists); CB168F/CB168G/TB146 frozen ([plan](Architecture_M6_CP3_CB168F_P13_Transverse_Entry_Mutual_Stop_Plan_20261119.md)). |
| COMPLETE (Code + Build) | CB168F (`3825f82ee`), CB168G/EC3 (`ebbe893bd`, pkg `14566343560`) | Exact diffs compiled: mutual consumer + cut-edge split; transverse entry mutual stop. |
| COMPLETE | TB146 EXEC (RED row393) / REV + [RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc); CB168H, CB168I; TB147 EXEC/REV + [RA-269](Architecture_M6_CP3_TB147_P13_Mutual_Carrier_End_Oracle_Full_Gate_Independent_Review_20261120.md#ra-269--adversarial-re-review-of-this-review-2026-11-20-utc) | Row393 stale premise fixed by reciprocal oracle; 962/962; four sphere slide contacts = +4; CB168J receipt frozen. |
| COMPLETE | CB168J (`d78404724`), [TB148 EXEC](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Execution_Report_20261120.md), [TB148 REV](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md) | 963/963, 491/491; four contacts unowned, strictly inside slides, on four carriers. |
| COMPLETE (Review) | [RA-270](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md#ra-270--adversarial-re-review-of-this-review-2026-11-20-utc) | Gate upheld; prose CB168K consumer withdrawn (restates helper, no reader); missing deciding measurement = arrival order; oracle switch moved before repair TB. |
| COMPLETE (Code + Build) | `M6-CP3-CB168K-P13-SLIDE-CONTACT-ARRIVAL-RECEIPT` | Exact +28/-0 source diagnostic compiled; [run 44679070165](https://github.com/akashskypatel/Directional/actions/runs/44679070165); immutable artifact `14603866682`, no tests. |
| NEXT (Test + Benchmark) | `M6-CP3-TB149-P13-SLIDE-CONTACT-ARRIVAL-FULL-GATE-EXEC` | TB148 manifest `4350378c…4c01c` unchanged; delete `slideContactArrival` lines → rows 1–963 MATCH TB148, 491/491; census 3/3 MATCH TB147; lines verbatim to Review. Prediction: four `wallCommitted=1 movingArrival=later`. |
| Then (Review) | `M6-CP3-TB149-P13-SLIDE-CONTACT-ARRIVAL-FULL-GATE-REV` | All later → freeze slide-piece cut position CB → oracle slide-piece CB → wall-loop stop switch CB → TB; any earlier → slide-vs-exit detection receipt; else design stop. |
| Prospective (held) | → CB168 binding → [O49] → CB169 H4 remainder → CB170 → CB171 → CB172 (O48) | CB172 requires vertex-overlap rule + tie control. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | After the TB132 Review; 858 after the sphere repair. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS`; `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON`; `M6-CP3-DEFN-P13-SYMMETRIC-TRANSVERSE-ENTRY-EDGE-BINDING` (prior provisional routes only) | Replaced by CB151; by CB153 (RA-251); by RA-253 S1/S7 N3–N5; by CB156/TB133 (RA-254); by CB168F/CB168G (RA-267). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked; O45 consumer proxy closed narrowly. |


## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [CB168K compile record](Architecture_M6_CP3_CB168K_P13_Slide_Contact_Arrival_Receipt_Code_Build_Record_20261120.md), [TB148 independent Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md), [CB168K plan](Architecture_M6_CP3_CB168K_P13_Exact_Slide_Interior_Contact_Consumer_Plan_20261120.md), [TB148 execution](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Execution_Report_20261120.md), [CB168J compile record](Architecture_M6_CP3_CB168J_P13_Sphere_Entry_On_Sliding_Wall_Receipt_Code_Build_Record_20261120.md), [TB147 independent Review](Architecture_M6_CP3_TB147_P13_Mutual_Carrier_End_Oracle_Full_Gate_Independent_Review_20261120.md), [TB147 execution](Architecture_M6_CP3_TB147_P13_Mutual_Carrier_End_Oracle_Full_Gate_Execution_Report_20261120.md), [TB146 Review / RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168I compile record](Architecture_M6_CP3_CB168I_P13_Slide_Coincidence_Receipt_Code_Build_Record_20261120.md), [CB168H compile record](Architecture_M6_CP3_CB168H_P13_Mutual_Carrier_End_Oracle_Code_Build_Record_20261120.md), [RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168I diff](Architecture_M6_CP3_CB168I_P13_Slide_Coincidence_Receipt_Exact.diff), [CB168H diff](Architecture_M6_CP3_CB168H_P13_Mutual_Carrier_End_Oracle_Exact.diff), [TB146 execution](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Execution_Report_20261119.md), CB168G/CB168F records, [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168F/G plan](Architecture_M6_CP3_CB168F_P13_Transverse_Entry_Mutual_Stop_Plan_20261119.md), TB145 Review/execution, RA-266, RA-265, RA-264, RA-263, RA-262 S2–S5, RA-261 S2–S5, RA-260 S2–S4, RA-259 S3. Mandatory policies apply.

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
