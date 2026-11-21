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
| Currency | 2026-11-21 UTC. TB-REV-157 COMPLETE, gate upheld, and its [adversarial continuation](Architecture_M6_CP3_TB_REV_157_Adversarial_Review_20261121.md) re-read artifact `14719149475`. That continuation withdrew CB-174 v3 (W1 duplicate stop builder, W2 committed walls only, W3 missed binding consumer) and froze the exact CB-174 slide-contact cut-binding diff. |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB-173 source `47a874ee8baa86284eeee11b4a28f9cca06d73f9`, [compile 44932960771](https://github.com/akashskypatel/Directional/actions/runs/44932960771), artifact `14718074764`, ZIP SHA-256 `cad613506dbadff3179f17a8492a57062d31cf27cfff6d1378417f351ab5ad09`; eight GMP/GMPXX targets. |
| Current gate | **TB157 scoped gate (not CP3):** 975/975 PASS, rows 1–972 MATCH TB156 N1–N3 with empty allowance, CP2 491/491. [Report](Architecture_M6_CP3_TB157_P13_Edge_Locus_Along_Edge_Ray_Key_Full_Gate_Execution_Report_20261121.md); artifact `14719149475` SHA-256 `9609b0e0eb8b51d692118859fef7f0556f7de5e69c336c1bb5033d2694194d11`. 564 `slideContactArrival` lines, all `later`, `wallCommitted=1`. |
| Current census | TB157 census 3/3 MATCH TB156 N1–N4 (Cylinder PASS; BunnyRandom, Vase expected RED); artifact `14719268782` ZIP SHA-256 `9e8f561953ba4ad552a5c30cd2430d0e23c22230e074abd3e2c4ce60b92ebd63`. |
| Accepted history | CP2 491/491, package `11391685901`. TB125 scoped 950/950; TB127 gate 951/951. CP3's 497 identities remain frozen/unpromoted. |
| Regression/debt | TB-REV-157-W3/W4, RA-281 F1/F2/F3, RA-275 S4a, O47/C5/O48/O49, V3b and sphere χ+4 carried. Stable 66/17/49, debt1, deferred81. |
| Active boundary | Sphere ends `CutSearchExhaustedBeforeCellularity` (rows644/669/698); row686 V18/E30/F18, χ6 vs 2; four slide contacts dropped at `SurfaceCellTracing.cpp:4428`. Slide carriers withheld from cuts (Amendment 14 interim). `build_cut_node_bindings` is entry-only, so a slide-interior stop would be rejected (W3). |

## Mandatory next turn — `M6-CP3-CB-174-P13-SLIDE-CONTACT-CUT-BINDING` — EXACT NEXT

- **Type:** Code + Build; compile/package only. No tests or benchmarks.
- **Authority:** [TB-REV-157 adversarial record](Architecture_M6_CP3_TB_REV_157_Adversarial_Review_20261121.md) W1–W5. The CB-174 v3 helper (`684d53d6…7d238`, Drive) is WITHDRAWN; do not apply it.
- **Apply exactly:** [diff](Architecture_M6_CP3_CB174_P13_Slide_Contact_Cut_Binding_Exact.diff), SHA-256 `236290050270f19b56d849915cfb727a87551477d0be726ac294fd0603fe1c44`. Preimages h `592daad7…a5`, cpp `1ef094af…e7`, tests `20a11166…4c`; postimages `3a6103e2…900`, `2bb4b746…6c8`, `e840b2aa…217` (full values in the record).
- **Does:** adds `carrier_contact_cut_position` (entry, else slide interior) and `CarrierContactBinding::struckParameter`. `build_arcs` cuts the wall at `{segment, struckParameter}`. A slide contact on a selected cut edge fails closed (unreachable under Amendment 14; R1 replaces it). New test → manifest row 976.
- **Then:** TB-EXEC-158 (manifest [976 rows](gates/Architecture_M6_TB158_P13_Slide_Contact_Cut_Binding_Full_Gate_Case_Manifest.tsv) `6a37e461…af0f`). STOP unless 976/976 PASS, CP2 491/491, rows 1–975 MATCH TB157 `14719149475` N1–N3 with EMPTY allowance, census 3/3 vs `14719268782` N1–N4, and no new `InvalidCutGraphBinding`. Then TB-REV-158 freezes producer switch CB-175 exactly (record §Successor obligations).
- **On failure:** the diff does not apply or the compile fails → STATUS BLOCKED, return to Review.
- **Do not:** edit beyond the diff; run tests; touch the tracer/producer; change selectors; promote CP3/497/D0/H4.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB152 EXEC/REV, RA-250–RA-276, CB150–CB168O | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); [TB151 REV + RA-274](Architecture_M6_CP3_TB151_P13_Source_Piece_Counts_Full_Gate_Independent_Review_20261120.md); [TB152 REV + RA-275/276](Architecture_M6_CP3_TB152_P13_Edge_Piece_Face_Side_Full_Gate_Independent_Review_20261120.md). |
| COMPLETE | CB168R, CB168Q, TB153, CB169, TB-EXEC/REV-154, RA-277, CB-169S, RA-278, CB-170, CB-171 | [TB154 Review](Architecture_M6_CP3_TB154_P13_Trace_Piece_Ray_Helpers_Full_Gate_Independent_Review_20261121.md); [RA-278](Architecture_M6_CP3_RA278_RA277_And_CB169S_Adversarial_Review_20261121.md). |
| COMPLETE (RED + Review) | `M6-CP3-TB-EXEC-155-…`, `M6-CP3-TB-REV-155-P13-TRACE-PIECE-PRODUCER-SWITCH-FULL-GATE` | 970/971 row858; continued after handover by [RA-280](Architecture_M6_CP3_RA280_TB_REV_155_Adversarial_Review_20261121.md) and [RA-281](Architecture_M6_CP3_RA281_RA280_Adversarial_Review_20261121.md) (Amendment 14 interim; R1 after stop switch). |
| COMPLETE | `M6-CP3-CB-172B-…`, `M6-CP3-TB-EXEC-156-…`, `M6-CP3-TB-REV-156-P13-SLIDE-CARRIER-CUT-ADMISSIBILITY-FULL-GATE` | 972/972; [adversarial record](Architecture_M6_CP3_TB_REV_156_Adversarial_Review_20261121.md) froze CB-173. |
| COMPLETE | `M6-CP3-CB-173-P13-STOP-SWITCH-RAY-HELPERS`, `M6-CP3-TB-EXEC-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE` | [CB record](Architecture_M6_CP3_CB173_P13_Edge_Locus_Along_Edge_Ray_Key_Code_Build_Record_20261121.md); [TB157](Architecture_M6_CP3_TB157_P13_Edge_Locus_Along_Edge_Ray_Key_Full_Gate_Execution_Report_20261121.md) 975/975. |
| COMPLETE (Review) | `M6-CP3-TB-REV-157-P13-EDGE-LOCUS-ALONG-EDGE-RAY-KEY-FULL-GATE` | [Review](Architecture_M6_CP3_TB157_P13_Edge_Locus_Along_Edge_Ray_Key_Independent_Review_20261121.md) (V3a/V3b split); continued after handover: [adversarial record](Architecture_M6_CP3_TB_REV_157_Adversarial_Review_20261121.md) (W1–W5). |
| **NEXT** (Code + Build) | `M6-CP3-CB-174-P13-SLIDE-CONTACT-CUT-BINDING` | Exact diff, compile only. |
| then (Test + Benchmark) | `M6-CP3-TB-EXEC-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE` | 976 rows, empty allowance vs TB157. |
| then (Review) | `M6-CP3-TB-REV-158-P13-SLIDE-CONTACT-CUT-BINDING-FULL-GATE` | If green: freeze CB-175 producer switch exactly (Later-only shared predicate at wall loop `:4659` + pair loop `:4549`, queued carrier event, receipt via predicate, V3b test, per-row predictions). |
| Prospective | CB-175 stop switch → TB-EXEC/REV-159 → slide-start subdivision (R1; deletes Amendment 14 interim + selected-cut slide fail-closed) → TB/REV → slide-plan conformity (RA-275 S4a) → O48 | O49 off the switch path. |
| Withdrawn | `M6-CP3-CB-174-P13-LATER-ENTRY-SLIDE-STOP-HELPER` (v3; TB-REV-157 W1–W3, W5); `M6-CP3-CB-172A-…` (RA-280 D3); prose CB-173 plan; `M6-CP3-DEFN-P13-SOURCE-ARC-READER-CLASSIFICATION` | — |
| Held | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`; `M6-CP3-DEFN-P13-FACE-CONTACT-OUTCOME` (FC-6); row 858 face-witness DEFN | 858 after the sphere repair. |
| Parked | `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | C4/exact grazing parked. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB-REV-157 adversarial record](Architecture_M6_CP3_TB_REV_157_Adversarial_Review_20261121.md), [CB-174 diff](Architecture_M6_CP3_CB174_P13_Slide_Contact_Cut_Binding_Exact.diff), [TB158 manifest](gates/Architecture_M6_TB158_P13_Slide_Contact_Cut_Binding_Full_Gate_Case_Manifest.tsv), [TB-REV-157 Review](Architecture_M6_CP3_TB157_P13_Edge_Locus_Along_Edge_Ray_Key_Independent_Review_20261121.md), [V3 feasibility](Architecture_M6_CP3_TB_REV_157_V3_Reaching_Test_Feasibility_20261121.md), [CB-173 diff](Architecture_M6_CP3_CB173_P13_Edge_Locus_Along_Edge_Ray_Key_Exact.diff), [TB156 Review](Architecture_M6_CP3_TB156_P13_Slide_Carrier_Cut_Admissibility_Full_Gate_Independent_Review_20261121.md), [TB150 Review + RA-273](Architecture_M6_CP3_TB150_P13_Slide_Interior_Cut_Position_Full_Gate_Independent_Review_20261120.md), [RA-271](Architecture_M6_CP3_TB149_P13_Slide_Contact_Arrival_Full_Gate_Independent_Review_20261120.md), [TB148 Review](Architecture_M6_CP3_TB148_P13_Sphere_Entry_On_Sliding_Wall_Full_Gate_Independent_Review_20261120.md), [RA-268](Architecture_M6_CP3_TB146_P13_Transverse_Entry_Mutual_Stop_Full_Gate_Independent_Review_20261119.md#ra-268--adversarial-re-review-of-this-review-2026-11-19-utc); earlier records resolve through these Reviews. Mandatory policies apply.

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
