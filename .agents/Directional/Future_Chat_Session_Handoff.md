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
| Currency | 2026-11-20 UTC: TB150 artifact-only full gate and census PASS/MATCH, [execution report](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Execution_Report_20261120.md), source `041bde764365710e6d5148c43751da91205ffd35`. Prior authority: CB168L compile-only SUCCESS (artifact 14608341511). TB149 REV [RA-271](Architecture_M6_CP3_TB149_P13_Slide_Contact_Arrival_Full_Gate_Independent_Review_20261120.md). TB149 PASS: gate 963/963 MATCH TB148, 491/491; census 3/3 MATCH TB147 under N1–N4 (RA-270 omitted frozen N4 = ASLR `GetParam` bytes; executor STOP was correct). Sphere: four `wallCommitted=1 movingArrival=later` (prediction held). Repair needs real slide pieces in the production graph (`build_arcs` uses chords) → CB168L unwired slide-interior cut position frozen. |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB168L source `041bde764365710e6d5148c43751da91205ffd35`, artifact `14608341511` (ZIP SHA-256 `d189282ce898af54c3cb48d2eaa47107ebaaf36ca2d0afcaec9689dec926084b`), [record](Architecture_M6_CP3_CB168L_P13_Slide_Interior_Cut_Position_Code_Build_Record_20261120.md). |
| Current gate | [TB150 run 44692445950](https://github.com/akashskypatel/Directional/actions/runs/44692445950), artifact `14609657696` (ZIP SHA-256 `9e2117dc4bf4d5e097beeaa90236b1c44ceafdba90bc3fd4751ef2cd2472874f`); 964/964 PASS, 963/963 MATCH TB149 N1–N3, 491/491, membership 1045, 504 unchanged `slideContactArrival` receipts. |
| Current census | [TB150 run 44692570324](https://github.com/akashskypatel/Directional/actions/runs/44692570324), artifact `14610319026` (ZIP SHA-256 `b5033d6939a14ce8716455f5dd5f6f20d15087b2ae229c8c646c96052c68225c`); Cylinder PASS, BunnyRandom/Vase expected RED at `:493`, 3/3 MATCH TB149 N1–N4. |
| Accepted history | CP2 491/491, package `11391685901`. TB125 scoped 950/950, package `14289730737`/`14289927334`; TB127 gate 951/951. CP3's 497 identities remain frozen/unpromoted. |
| Regression/debt | Stable 66 events / 17 categories / 49 recurrences; one produced-witness debt; 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48 open; C3/O44/C1 and O45 narrow proxy closed. D11=A, D12=A, D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Row686 χ6 vs 2 (+4 = four unowned slide contacts); rows669/698 `CutSearchExhaustedBeforeCellularity`. Production arcs (`exact_trace_path_between`) and the row686 oracle both write slides as face chords; the walls are `faceThenEdge`, so no chord passes through the contact. EPO-5 amended (RA-271 S4): slide-interior cuts allowed on the edge piece in the piece path only. Stop switch waits for EPO-3 + CB169 cutover. |

## Mandatory next turn — `M6-CP3-TB150-P13-SLIDE-INTERIOR-CUT-POSITION-FULL-GATE-REV` — independent Review

Reopen the immutable [TB150 execution report](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Execution_Report_20261120.md) and the gate/census artifacts. Independently verify 964/964 PASS, 963/963 MATCH under N1–N3 (all slide-contact receipts retained), CP2 491/491, and census 3/3 MATCH under N1–N4. Preserve 66/17/49, one debt, 81 deferred, open O47/C5 and no CP3/selector497/D0 promotion. Freeze only the supported exact EPO-3 binding Code + Build step (`sourcePieceCounts` on `ArcDraft`/`GlobalTopologyArc`, exact validator, producer all-ones, inert), followed by its separate TB. The cutover/stop switch remains for later turns; review is runtime-free.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB131 EXEC/REV, RA-250–RA-252, CB150–CB154 | H1/H2, FC-7′ switch; TB131 literal MISMATCH (presentation only). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-253–RA-262, CB155–CB166, TB132–TB141 EXEC/REV | Contact receipts, H3 closed narrowly, slide contact (RA-259 S3) and pieces (RA-260 S2) defined, EPO contract (RA-262); MATCH through [TB141](Architecture_M6_CP3_TB141_P13_Committed_Slide_Receipt_Full_Gate_Execution_Report_20261118.md) 962/962; records via the load list and folded index. |
| COMPLETE | RA-263–RA-266, CB167, CB168A–CB168E, TB142–TB145 EXEC/REV | O47 track before H4; EC1 receipt; framing single-write; carrier-contact helper + edge-node binding (inert); arrival/face receipt; MATCH through TB145 964/964. Records via RA-266/RA-267 and the folded index. |
| COMPLETE (Review) | `M6-CP3-TB145-P13-CARRIER-CONTACT-BINDING-AND-ARRIVAL-RECEIPT-FULL-GATE-REV` + [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc) | 964/964 MATCH upheld; DEFN withdrawn (rule exists); CB168F/CB168G/TB146 frozen ([plan](Architecture_M6_CP3_CB168F_P13_Transverse_Entry_Mutual_Stop_Plan_20261119.md)). |
| COMPLETE (Code + Build) | CB168F (`3825f82ee`), CB168G/EC3 (`ebbe893bd`, pkg `14566343560`) | Exact diffs compiled: mutual consumer + cut-edge split; transverse entry mutual stop. |
| COMPLETE | TB146–TB149 EXEC/REV, RA-268–RA-271, CB168H–CB168K | Row393 reciprocal oracle; four sphere slide contacts = +4, unowned, strictly inside committed wall slides, all `later`; TB149 PASS (N4 ruling). [RA-271](Architecture_M6_CP3_TB149_P13_Slide_Contact_Arrival_Full_Gate_Independent_Review_20261120.md). |
| COMPLETE (Code + Build) | `M6-CP3-CB168L-P13-SLIDE-INTERIOR-CUT-POSITION` | Frozen exact diff applied, source `041bde764365710e6d5148c43751da91205ffd35`, eight-target GMP/GMPXX compile SUCCESS, artifact `14608341511`, no runtime. |
| COMPLETE (Test + Benchmark) | `M6-CP3-TB150-P13-SLIDE-INTERIOR-CUT-POSITION-FULL-GATE-EXEC` | Gate 964/964 PASS, 963/963 MATCH TB149 N1–N3, CP2 491/491; census 3/3 MATCH TB149 N1–N4. [Report](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Execution_Report_20261120.md). |
| NEXT (Review) | `M6-CP3-TB150-P13-SLIDE-INTERIOR-CUT-POSITION-FULL-GATE-REV` | Freeze exact EPO-3 binding CB (`sourcePieceCounts`, exact validator, producer all-ones, inert) + its TB. |
| Prospective | → EPO-3 TB/REV → CB169 H4 cutover (EPO-2/3/4/6, O49, row686 oracle pieces) → TB/REV → wall-loop stop switch CB (struck cut from `carrier_contact_slide_position`) → TB (row686 χ=2, rows669/698 past exhaustion, four nodes) → CB170 → CB171 → CB172 (O48 incl. BunnyRandom pending/non-last slide contacts) | CB172 requires vertex-overlap rule + tie control. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | After the TB132 Review; 858 after the sphere repair. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS`; `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON`; `M6-CP3-DEFN-P13-SYMMETRIC-TRANSVERSE-ENTRY-EDGE-BINDING` (prior provisional routes only) | Replaced by CB151; by CB153 (RA-251); by RA-253 S1/S7 N3–N5; by CB156/TB133 (RA-254); by CB168F/CB168G (RA-267). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked; O45 consumer proxy closed narrowly. |


## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB150 execution](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Execution_Report_20261120.md), [CB168L compile record](Architecture_M6_CP3_CB168L_P13_Slide_Interior_Cut_Position_Code_Build_Record_20261120.md), [RA-271](Architecture_M6_CP3_TB149_P13_Slide_Contact_Arrival_Full_Gate_Independent_Review_20261120.md), [CB168K compile record](Architecture_M6_CP3_CB168K_P13_Slide_Contact_Arrival_Receipt_Code_Build_Record_20261120.md), [TB148 independent Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md), [CB168K plan](Architecture_M6_CP3_CB168K_P13_Exact_Slide_Interior_Contact_Consumer_Plan_20261120.md), [TB148 execution](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Execution_Report_20261120.md), [CB168J compile record](Architecture_M6_CP3_CB168J_P13_Sphere_Entry_On_Sliding_Wall_Receipt_Code_Build_Record_20261120.md), [TB147 independent Review](Architecture_M6_CP3_TB147_P13_Mutual_Carrier_End_Oracle_Full_Gate_Independent_Review_20261120.md), [TB147 execution](Architecture_M6_CP3_TB147_P13_Mutual_Carrier_End_Oracle_Full_Gate_Execution_Report_20261120.md), [TB146 Review / RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168I compile record](Architecture_M6_CP3_CB168I_P13_Slide_Coincidence_Receipt_Code_Build_Record_20261120.md), [CB168H compile record](Architecture_M6_CP3_CB168H_P13_Mutual_Carrier_End_Oracle_Code_Build_Record_20261120.md), [RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168I diff](Architecture_M6_CP3_CB168I_P13_Slide_Coincidence_Receipt_Exact.diff), [CB168H diff](Architecture_M6_CP3_CB168H_P13_Mutual_Carrier_End_Oracle_Exact.diff), [TB146 execution](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Execution_Report_20261119.md), CB168G/CB168F records, [RA-267](Architecture_M6_CP3_TB145_P13_Carrier_Contact_Binding_And_Arrival_Receipt_Full_Gate_Independent_Review_20261119.md#ra-267--adversarial-re-review-of-this-review-2026-11-19-utc), [CB168F/G plan](Architecture_M6_CP3_CB168F_P13_Transverse_Entry_Mutual_Stop_Plan_20261119.md), TB145 Review/execution, RA-266, RA-265, RA-264, RA-263, RA-262 S2–S5, RA-261 S2–S5, RA-260 S2–S4, RA-259 S3. Mandatory policies apply.

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
