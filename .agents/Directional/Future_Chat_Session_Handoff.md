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
| Currency | 2026-11-18 UTC: [RA-259](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md#ra-259--adversarial-re-review-of-this-review-2026-11-18-utc) upholds TB137 MATCH (zero departure-chord crossings; 48 edge-port departures, BunnyRandom only) and accepts CB161. It defines slide contact (closes RA-257 S5.2, folds in S5.4) and freezes the unwired helpers CB162/CB163 with TB139. |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD. CB160 source `66fb0c5ec42fa57614a504437724b18d7004cbb1`, package `14414860103`, ZIP SHA-256 `8b2277e9e5ac2fc71ffe4e61a6012e5ac892f2a92c0f03b24613d695437aaec2`; [compile record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md). Prior identities: retained records in load list. |
| Accepted evidence | [TB125](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb125_p13_edge_terminal_exact_inventory_execution_report_20261117md) scoped 950/950; artifacts `14289730737`/`14289927334`. CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. TB127 comparison authority: package `14301616031`, source `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate `14302887671` 951/951, census `14302668940`. |
| Latest candidate | [TB137 independent Review](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md): MATCH: gate `14418131624` 954/955, census `14416913949` Cylinder PASS/288, BunnyRandom/Vase RED; 957/957 existing rows + row 955 PASS; 68 receipts byte-identical; zero departure-chord crossings, 48 edge-port departures (BunnyRandom). 491/491 accepted prefix. Comparator TB136 gate `14406791564` / census `14406826878`. TB135 slide starts and onset ratio: [TB135 report](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Execution_Report_20261118.md). |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43/O46/O47/O48 open; narrow C3/O44/C1 and O45 (consumer proxy only) closed. Middle-piece direction witness open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | Sphere traces 4/6 cross at P on edge (0,2): C5/O47. BunnyRandom 43/15: shared interval [X43, v94] on (94,210); 43 earlier, so trace 15 should end at X43 (O48). CB158 stores the slide start (`edgeTransitEntry`); classifier never checks slide pieces; on edge-departure segments both loops test a chord that was never traced (H3, RA-257 S1, RA-258 S2); CB160 counts the ProperCrossings this produces; TB137 measured zero such lines in 955 gate and three census rows (48 edge-port departure lines, all in BunnyRandom). H3 remains open; the independent zero-line result authorizes the isolated CB161 switch, with TB138 equality. O45 narrow closure kept; 858 permitted RED at :155, 648 unreached. FC-6, H2, terminal-cut held. No CP3/D0 acceptance. RA-259 S3: carrier contact ends 15 at X43; S5.3 (slide-locus cut) remains. |

## Mandatory next turn — `M6-CP3-CB161-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH` — EXACT NEXT (Code + Build; compile only)

Apply only the [frozen exact diff](Architecture_M6_CP3_CB161_P13_Departure_Chord_Classifier_Switch_Exact.diff) under [TB137 independent Review](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md), SHA-256 `133a940200872ad956da25faae135b9f25b956986eba064134dfe493a7983095`. Verify current product/test bytes equal CB160; preserve accepted selectors. Correct the common face-exit lookup to read `edgeTransitEntry` when present. Add the frozen fail-before/pass-after test; compile eight RA-245 GMP targets only. Stop if authority or test preconditions fail. After formal CB161 completion, route to `M6-CP3-TB138-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH-FULL-GATE-EXEC` using the [956-row manifest](gates/Architecture_M6_TB138_P13_Departure_Chord_Classifier_Switch_Full_Gate_Case_Manifest.tsv), SHA-256 `95e61be9132e159a5c3f041a20b875aed4d55ea5cf7bade0c93e07b329a6641a`; 958/958 prior rows equal, row 956 PASS. Review defines exact gates and failure routes. No runtime in CB161, no CP3 promotion. Parallel overlap DEFN and sphere remainder stay separate.

After TB138 MATCH and its Review: `M6-CP3-CB162-P13-SLIDE-ARRIVAL-HELPER` (diff `Architecture_M6_CP3_CB162_P13_Slide_Arrival_Helper_Exact.diff`, `1a3cbb1a…`, 139 lines, +12/+32/+65), then `M6-CP3-CB163-P13-CARRIER-CONTACT-HELPER` (`Architecture_M6_CP3_CB163_P13_Carrier_Contact_Helper_Exact.diff`, `3a7f96f2…`, 175 lines, +20/+44/+81). Both are compile only and stacked on CB161. Then TB139 per [RA-259](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md#ra-259--adversarial-re-review-of-this-review-2026-11-18-utc) S5 (manifest `gates/Architecture_M6_TB139_P13_Slide_Arrival_And_Carrier_Contact_Helpers_Full_Gate_Case_Manifest.tsv` `96766f76…`, 958 rows, membership 1,039).

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB131 EXEC/REV, RA-250–RA-252, CB150–CB154 | H1/H2, FC-7′ switch; TB131 literal MISMATCH (presentation only). Records via the load list and [folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). |
| COMPLETE | RA-253–RA-255, CB155–CB157, TB132–TB134 EXEC, TB132/TB133-REV | Receipts and contact-kind measurement, MATCH 956/956 each; four-ray proof; O48 opened. Records in the load list. |
| COMPLETE | TB134-REV + RA-256, CB158, TB135 EXEC, TB135-REV | Onset X43 certified and measured; [CB158 record](Architecture_M6_CP3_CB158_P13_Edge_Transit_Entry_Record_Code_Build_Record_20261118.md); [TB135 report](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Execution_Report_20261118.md) 956/956. |
| COMPLETE | RA-257, CB159, TB136 EXEC/REV, [RA-258](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md#ra-258--adversarial-re-review-of-this-review-2026-11-18-utc), CB160, TB137 EXEC/REV | H3 real and measured: [TB137 MATCH](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Execution_Report_20261118.md) 957/957 + row 955, zero crossing lines, 48 departure lines; [CB160 record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md). |
| COMPLETE (Review) | [RA-259](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md#ra-259--adversarial-re-review-of-this-review-2026-11-18-utc) | CB161 accepted; CB160 receipt unreachable after CB161 (delete it in wiring); slide contact defined; CB162/CB163/TB139 frozen. |
| EXACT NEXT | `M6-CP3-CB161-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH` | Frozen diff; compile only. After completion, TB138 artifact-only equality. |
| Then | `M6-CP3-TB138-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH-FULL-GATE-EXEC` → `…-REV` | Equality gate (TB137 Review); the real tests are row 956 and the 958-row equality. |
| Then | `M6-CP3-CB162-P13-SLIDE-ARRIVAL-HELPER` → `M6-CP3-CB163-P13-CARRIER-CONTACT-HELPER` → `M6-CP3-TB139-P13-SLIDE-CONTACT-HELPERS-FULL-GATE-EXEC` → `…-REV` | Unwired helpers, compile only each; TB139 per RA-259 S5. |
| Then | slide-contact wiring CB + TB | Frozen by the S5.3 DEFN; deletes CB160 receipt. |
| Parallel (Review) | `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` (narrowed to RA-257 S5.3) | Publication and cut position of a locus in a slide or at an entry; freezes the wiring CB. `M6-CP3-DEFN-P13-OPPOSING-TRACE-OVERLAP` is discharged by RA-259 S3. |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | After the TB132 Review; 858 after the sphere repair. |
| Withdrawn | `M6-CP3-CB149B-P13-TERMINAL-CUT-AUTHORITY-RECEIPT`; `M6-CP3-CB152-P13-COMMON-CARRIER-CONTACT-CENSUS`; `M6-CP3-DEFN-P13-CARRIER-CONTACT-SWITCH-COMPARISON` (prior provisional routes only) | Replaced by CB151; by CB153 (RA-251); by RA-253 S1/S7 N3–N5; by CB156/TB133 (RA-254). |
| Parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked; O45 consumer proxy closed narrowly. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: `M6-CP3-CB161-P13-DEPARTURE-CHORD-CLASSIFIER-SWITCH` (Code + Build): read the [TB137 independent Review](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md) recommendation, [RA-259](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Independent_Review_20261118.md#ra-259--adversarial-re-review-of-this-review-2026-11-18-utc) S1–S6, the exact diff and the [CB160 record](Architecture_M6_CP3_CB160_P13_Departure_Chord_Crossing_Receipt_Code_Build_Record_20261118.md) (orchestration shape). Review track: `M6-CP3-DEFN-P13-EDGE-ENDPOINT-CONTACT` reads RA-259 S3 and RA-257 S5.3. Mandatory policies apply.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [TB137 execution report](Architecture_M6_CP3_TB137_P13_Departure_Chord_Crossing_Receipt_Full_Gate_Execution_Report_20261118.md), [TB136 independent Review](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Independent_Review_20261118.md), [TB136 execution report](Architecture_M6_CP3_TB136_P13_Carrier_Occupancy_Helpers_Full_Gate_Execution_Report_20261118.md), [TB135 independent Review](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Independent_Review_20261118.md), [Execution report](Architecture_M6_CP3_TB135_P13_Edge_Transit_Entry_Full_Gate_Execution_Report_20261118.md), [CB158 compile record](Architecture_M6_CP3_CB158_P13_Edge_Transit_Entry_Record_Code_Build_Record_20261118.md), [TB134 execution report](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Execution_Report_20261118.md), [TB134 independent Review](Architecture_M6_CP3_TB134_P13_Trace_Path_Receipt_Full_Gate_Independent_Review_20261118.md),  [CB157 compile record](Architecture_M6_CP3_CB157_P13_Trace_Path_Receipt_Code_Build_Record_20261118.md), [TB133 independent Review](Architecture_M6_CP3_TB133_P13_Same_Face_Segment_Pair_Receipt_Full_Gate_Independent_Review_20261118.md), [TB133 execution report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#architecture_m6_cp3_tb133_p13_same_face_segment_pair_receipt_full_gate_execution_report_20261118md), [CB156 compile record](Architecture_M6_CP3_CB156_P13_Same_Face_Segment_Pair_Receipt_Code_Build_Record_20261117.md). Earlier CB/TB/RA records (TB132 back to RA-244) and preserved exact diffs: Prior records resolve through [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17). [RA-245/246](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [TB127 Review/RA-247](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) retain earlier evidence obligations.
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
