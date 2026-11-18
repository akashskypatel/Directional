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
| Currency | 2026-11-18 UTC: [RA-258](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md#ra-258--adversarial-re-review-of-this-review-2026-11-18-utc) upholds TB136 MATCH (956/956 + row 954), finds the H3 receipt skipped and the implementation agent idle, and freezes CB160/TB137 (departure-chord crossing receipt). |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD. CB160 source `66fb0c5ec42fa57614a504437724b18d7004cbb1`, package `14414860103`, ZIP SHA-256 `8b2277e9e5ac2fc71ffe4e61a6012e5ac892f2a92c0f03b24613d695437aaec2`; [compile record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md). Prior identities: retained records in load list. |
| Accepted evidence | [TB125](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb125_p13_edge_terminal_exact_inventory_execution_report_20261117md) scoped 950/950; artifacts `14289730737`/`14289927334`. CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. TB127 comparison authority: package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate `14302887671` 951/951, census `14302668940`. |
| Latest candidate | TB136 execution MATCH under RA-257 S4: gate `14406791564` 953/954, census `14406826878` Cylinder PASS/288, BunnyRandom/Vase RED. 956/956 existing rows match TB135 and row 954 helper PASS; 68 receipts byte-identical. [TB136 report](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Execution_Report_20261118.md). [TB136 independent Review](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md) upholds the result; accepted prefix 491/491; independent comparison and package checks complete. Comparator: TB135 independent 956/956 MATCH under RA-256 S5; gate `14398029488` 952/953 and census `14398329619` Cylinder PASS/288, BunnyRandom/Vase RED; accepted prefix 491/491. 66 sphere receipts on 19 rows have no slide tokens; both BunnyRandom receipts carry precisely 43:11, 43:13, 15:19. On (94,210), t43=0.26324148596788688, t15=0.93470265131543506, ratio=0.0886278847694711840154612716578249278676129003001871014945774 (relative 1e-12 criterion met). [Execution report](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Execution_Report_20261118.md) Both postflight valid. [TB135 independent Review](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Independent_Review_20261118.md). Comparator TB134 gate `14390702505`, census `14391390784`. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48 open; narrow C3/O44/C1 and O45 (consumer proxy only) closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Sphere traces 4/6 cross at P on edge (0,2): C5/O47. BunnyRandom 43/15: shared interval [X43, v94] on (94,210); 43 earlier, so trace 15 should end at X43 (O48). CB158 stores the slide start (`edgeTransitEntry`); classifier never checks slide pieces; on edge-departure segments both loops test a chord that was never traced (H3, RA-257 S1, RA-258 S2); CB160 counts the ProperCrossings this produces. O45 narrow closure kept; 858 permitted RED at :155, 648 unreached. FC-6, H2, terminal-cut held. No CP3/D0 acceptance. |

## Mandatory next turn — `M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-EXEC` — EXACT NEXT (Test + Benchmark, artifact only)

CB160 exact patch compiled; [record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md) owns immutable source/package, verified hashes, eight targets and the frozen input inventory. Execute TB137 per [RA-258](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md#ra-258--adversarial-re-review-of-this-review-2026-11-18-utc) S4. Manifest `gates/Architecture_M6_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Case_Manifest.tsv` (`46200a60…`), 955 gate rows, membership 1,036; 3 census rows. Compare TB136 gate `14406791564` / census `14406826878`; N5 drops only `departureChordCrossing` lines; other receipts byte-identical; row 955 PASS; report counts per row and distinct crossing lines. No rebuild, repair, changed frozen inputs or discovery. Mismatch: `M6-CP3-PLAN-P13-DEPARTURE-CHORD-RECEIPT-STOP`; infrastructure: `M6-CP3-CB160A-P13-DEPARTURE-CHORD-RECEIPT-ORCH`. Review track in parallel: `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` (RA-257 S5.2). No CP3 promotion.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB131 EXEC/REV, RA-250–RA-252, CB150–CB154 | H1/H2, FC-7′ switch; TB131 literal MISMATCH (presentation only). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-253–RA-255, CB155–CB157, TB132–TB134 EXEC, TB132/TB133-REV | Receipts and contact-kind measurement, MATCH 956/956 each; four-ray proof; O48 opened. Records in the load list. |
| COMPLETE | TB134-REV + RA-256, CB158, TB135 EXEC, TB135-REV | Onset X43 certified and measured; [CB158 record](Architecture_M6_CP3_CB158_P13_Edge_Transit_Entry_Record_Code_Build_Record_20261118.md); [TB135 report](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Execution_Report_20261118.md) 956/956. |
| COMPLETE | [RA-257](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Independent_Review_20261118.md#ra-257--adversarial-re-review-of-this-review-2026-11-18-utc), CB159, TB136 EXEC + REV | H3 shown real; unwired carrier-occupancy helpers; [TB136 MATCH](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Execution_Report_20261118.md) 956/956 + row 954. |
| COMPLETE (Review) | [RA-258](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md#ra-258--adversarial-re-review-of-this-review-2026-11-18-utc) | Routing skipped the H3 receipt; H3 covers both loops; CB160/TB137 frozen. |
| COMPLETE (compile only) | `M6-CP3-CB160-P13-DEPARTURE-CHORD-CROSSING-RECEIPT` | [CB160 record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md); no runtime. |
| EXACT NEXT | `M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-EXEC` → `…-FULL-GATE-REV` | RA-258 S4 MATCH + receipt counts; REV routes per S5: zero lines → CB161 classifier reads stored exit (TB138 equality); any lines → switch coupled with S5.2. |
| Parallel (Review) | `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` → `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` | RA-257 S5.2 slide-piece contact; then S5.3 terminal-in-slide/cut ordering and S5.4 sphere entry equality; each a helpers CB + wiring CB. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | After the TB132 Review; 858 after the sphere repair. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS`; `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON` (prior provisional routes only) | Replaced by CB151; by CB153 (RA-251); by RA-253 S1/S7 N3–N5; by CB156/TB133 (RA-254). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked; O45 consumer proxy closed narrowly. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: `M6-CP3-TB137-P13-DEPARTURE-CHORD-CROSSING-RECEIPT-FULL-GATE-EXEC` (Test + Benchmark): read [CB160 compile record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md), [RA-258](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md#ra-258--adversarial-re-review-of-this-review-2026-11-18-utc) S4–S6 and the TB136 execution report (orchestration shape). Review track: `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` reads RA-257 S5 and the TB135 slide-start evidence. Mandatory policies apply.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [TB136 independent Review](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md), [TB136 execution report](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Execution_Report_20261118.md), [TB135 independent Review](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Independent_Review_20261118.md), [Execution report](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Execution_Report_20261118.md), [CB158 compile record](Architecture_M6_CP3_CB158_P13_Edge_Transit_Entry_Record_Code_Build_Record_20261118.md), [TB134 execution report](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Execution_Report_20261118.md), [TB134 independent Review](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md),  [CB157 compile record](Architecture_M6_CP3_CB157_P13_Trace_Path_Receipt_Code_Build_Record_20261118.md), [TB133 independent Review](Architecture_M6_CP3_TB133_P13_Same_Face_Segment_Pair_Receipt_Full_Gate_Independent_Review_20261118.md), [TB133 execution report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb133_p13_same_face_segment_pair_receipt_full_gate_execution_report_20261118md), [CB156 compile record](Architecture_M6_CP3_CB156_P13_Same_Face_Segment_Pair_Receipt_Code_Build_Record_20261117.md). Earlier CB/TB/RA records (TB132 back to RA-244) and preserved exact diffs: Prior records resolve through [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
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
