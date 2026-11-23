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
| Currency | 2026-11-23 UTC. The immutable CB-188 source `b2e976f204fa5b2988a9cbe5a77defd106a96aad` passed TB169 full gate 993/993 in run `45104059492`, result artifact `14787082075`. CP2 491/491 and membership 1074; no prior normalized differences outside four approved row979 face counts. Stable 66/17/49, debt1, deferred81. [TB-REV-169](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md) independently accepted the narrow correction; CB-189 compile-only is next. |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-188 source `b2e976f204fa5b2988a9cbe5a77defd106a96aad`, eight-target compile run `45101939539`, package `14786260085`, ZIP SHA-256 `d877a0ea4c05cfe93275506823652abb6b0e012dd3a5925103606e28e69625a5`, GMP/GMPXX, `runtimeExecution=false` ([record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md)). CB-187 predecessor source `486704038a6bf659a253a2e2f99edde5d03c7ffe`, package `14781561211`, run `45090657623` ([record](Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Code_Build_Record_20261123.md)). |
| Current gate / census | [TB169 report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md): [run 45104059492](https://github.com/akashskypatel/Directional/actions/runs/45104059492), result `14787082075` ZIP SHA-256 `dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`, 993/993 PASS, CP2 491/491, membership 1074, 1,994 hashes, all normalized TB168 rows identical except four approved count changes. No production census; latest three-case census remains TB165. |
| Accepted history | CP2 491/491, package `11391685901`. CP3's 497 identities are frozen and unpromoted. |
| Regression/debt | TB169 plus independent TB-REV-169 add no new regression or candidate and no PASS-to-RED change. Stable 66 events/17 categories/49 recurrences, produced-witness debt 1, deferred 81. Staged sphere remains at `SourceFaceCarriesMultipleTraceCuts`; production sphere still at `CutSearchExhaustedBeforeCellularity`. CP3/497/D0/H4 held. |
| Active boundary | The production sphere still stops at `CutSearchExhaustedBeforeCellularity`. The staged row-979 plan stops at `SourceFaceCarriesMultipleTraceCuts`, `6-8-9`: a singular corner (node 1) with rays from traces 3 and 4, slide arrivals from traces 0 and 9, and trace 0's segment 6 split at node 12 into arcs 0 and 1. Activation is held until the staged plan builds (G5). |

## Mandatory next turn

- **COMPLETE (Code + Build):** CB-188 exact region reader, source `b2e976f204fa5b2988a9cbe5a77defd106a96aad`, compiled eight targets with GMP/GMPXX; package `14786260085`.
- **COMPLETE (Test + Benchmark):** `M6-CP3-TB-EXEC-169-P13-REGION-VISIT-READER-FULL-GATE`, [report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md), [run 45104059492](https://github.com/akashskypatel/Directional/actions/runs/45104059492), result `14787082075`, 993/993 PASS; CP2 491/491; membership 1074; four expected count changes, no other allowed comparison change; no census or rebuild.
- **COMPLETE (independent Review):** `M6-CP3-TB-REV-169-P13-REGION-VISIT-READER-FULL-GATE`. [Review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md) checked 993 exact rows and 1,994 checksums per archive, confirmed only four authorized count changes, and rejected all product/promotion claims. Runtime-free.
- **NEXT (Code + Build only):** `M6-CP3-CB-189-P13-CORNER-VISIT-READER`. Apply only the frozen amended corner-reader diff, compile without executing binaries, and stop on exact preimage/hash or compile failure. No CP3/497/D0/H4 or production promotion.

```
NEXT_TURN: M6-CP3-CB-189-P13-CORNER-VISIT-READER
Owner: Code + Build agent; exact amended corner reader patch, compile only; no runtime execution
Authority: Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md; Architecture_M6_CP3_TB_REV_168_Adversarial_Review_20261123.md; Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Exact.diff
Tested source: b2e976f204fa5b2988a9cbe5a77defd106a96aad
Package: 14786260085; compile run 45101939539; runtimeExecution=false
Result: run 45104059492; artifact 14787082075; SHA-256 dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5
Reviewed gate: 993/993 PASS, CP2 491/491, membership 1074; full N1-N3 agreement except four approved row979 counts
Next exact patch SHA-256: 6e391678934f776d83b1bbae6652724e080763329d6171c7cdb1c5663259e3b8; CB-188 postimage required
Following TB-EXEC-170 falsifiers: rows except 979 unchanged; row 979 builds staged plan or reaches next typed stage; row 652 PASS; C1/C2 witnessed only if printed
Outcome: SourceFaceCarriesMultipleTraceCuts sourceFace=6-8-9 remains; production sphere CutSearchExhaustedBeforeCellularity
Regression: no new candidate; stable 66/17/49, debt1, deferred81; no census
Stop on patch preimage/hash/compile failure. No test execution, activation or CP3/497/D0/H4 promotion.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-EXEC/REV-165 | Adversarial records [TB-REV-162](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md), [163](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md), [164](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md), [165](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md). |
| COMPLETE | CB-185 → TB-EXEC-166 → TB-REV-166 ([adv.](Architecture_M6_CP3_TB_REV_166_Adversarial_Review_20261122.md)) → CB-186 → TB-EXEC-167 | [TB167](Architecture_M6_CP3_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Execution_Report_20261122.md): 989/989. |
| COMPLETE (Review) | `M6-CP3-TB-REV-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE` | [Independent](Architecture_M6_CP3_TB_REV_167_Face_Cut_Corner_Partition_Helper_Independent_Review_20261122.md) + [adversarial](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md) (P1–P8). |
| COMPLETE (Code + Build) | `M6-CP3-CB-187-P13-ARC-FACE-VISIT-ADAPTER` | Exact diff `806a64fe…96ac`; compiled in [run 45090657623](https://github.com/akashskypatel/Directional/actions/runs/45090657623); package `14781561211`; no runtime. |
| COMPLETE (Test + Benchmark) | `M6-CP3-TB-EXEC-168-P13-ARC-FACE-VISIT-ADAPTER-FULL-GATE` | [TB168](Architecture_M6_CP3_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Execution_Report_20261123.md) 993/993; CP2 491/491; membership 1074; prior 989 unchanged. |
| COMPLETE (Review) | `M6-CP3-TB-REV-168-…` | [Independent](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md) + [adversarial](Architecture_M6_CP3_TB_REV_168_Adversarial_Review_20261123.md) (Q1–Q7). CB-188 `5f06c14b…5944`; CB-189 amended `6e391678…e3b8`. |
| COMPLETE (Code + Build) | CB-188 | [Record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md), exact source `b2e976f204fa5b2988a9cbe5a77defd106a96aad`; compile run `45101939539`, package `14786260085`, no runtime. |
| COMPLETE TB / Review | TB-EXEC-169 → TB-REV-169 | [TB169 report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md), [independent Review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md): 993/993 PASS, 1074 membership, four exact row979 face changes; no promotion. |
| NEXT | CB-189 → TB-EXEC-170 → TB-REV-170 | Amended diff `6e391678…e3b8`. Row 979 builds the staged plan or prints the next typed stage. Row 652 still passes. C1/C2 count as witnessed only if printed. |
| 4 | CB-190 | S4/S6/S7 diagnostic conformity (off critical path). |
| 5 | Activation → TB → V3b → R1 → O48 | After the staged plan builds. |
| Withdrawn | prose CB-180 (X2); DEFN-161A (W3); prose CB-178 (V2); DEFN-159A (U1); prose CB-175; CB-174 v3; CB-172A; prose CB-173; old CB-181/182 plan (Y1); prose CB-183 (Z1); activation-before-plan (G5); CB-185 v1 (K3/K4); prose CB-186 (L2–L7); prose CB-187 `…-EXACT-FACE-CUT-READER`, v1–v5, S5 STOP (P2–P7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB-REV-169 review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md), [TB169 report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md), [CB-188 record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-168 independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md), [CB-188 manifest](gates/Architecture_M6_CP3_CB188_P13_Visit_Reader_Exact_Manifest.md), [CB-189 manifest](gates/Architecture_M6_CP3_CB189_P13_Visit_Reader_Exact_Manifest.md), [TB168 execution report](Architecture_M6_CP3_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Execution_Report_20261123.md), [CB-187 code/build record](Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Code_Build_Record_20261123.md), [TB-REV-167 adversarial record](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md), [TB-REV-167 independent review](Architecture_M6_CP3_TB_REV_167_Face_Cut_Corner_Partition_Helper_Independent_Review_20261122.md), [TB167 report](Architecture_M6_CP3_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Execution_Report_20261122.md).

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
