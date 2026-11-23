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
| Currency | 2026-11-23 UTC. CB-188 exact region reader was compiled from source `b2e976f204fa5b2988a9cbe5a77defd106a96aad` in eight-target GMP/GMPXX run `45101939539`; package `14786260085`. No runtime tests ran in CB-188. Last acceptance TB168 remains 993/993 PASS, CP2 491/491, membership 1074; stable 66/17/49, debt1, deferred81. TB-EXEC-169 is next. CB-189 remains separate and held. |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-188 source `b2e976f204fa5b2988a9cbe5a77defd106a96aad`, eight-target compile run `45101939539`, package `14786260085`, ZIP SHA-256 `d877a0ea4c05cfe93275506823652abb6b0e012dd3a5925103606e28e69625a5`, GMP/GMPXX, `runtimeExecution=false` ([record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md)). CB-187 predecessor source `486704038a6bf659a253a2e2f99edde5d03c7ffe`, package `14781561211`, run `45090657623` ([record](Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Code_Build_Record_20261123.md)). |
| Current gate / census | [TB168 report](Architecture_M6_CP3_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Execution_Report_20261123.md): [run 45092627119](https://github.com/akashskypatel/Directional/actions/runs/45092627119), result `14781634158` (ZIP SHA-256 `db2f8f2981c7c2ac914f59598a1e40c553ea8b94b21a23e41b84e74dd1aafb09`), 993/993 PASS, CP2 491/491, membership 1074. TB167 artifact `14770748728` rows 1–989 agree under N1–N3: zero ledger/raw/complete-record differences. No census; most recent three-case census remains TB165 unchanged. |
| Accepted history | CP2 491/491, package `11391685901`. CP3's 497 identities are frozen and unpromoted. |
| Regression/debt | TB168 observed no new regression candidate or PASS-to-RED change. Stable totals 66/17/49, produced-witness debt1, deferred81 unchanged. Carried: G2/G3, RA-275 S4a, Y7/Z3, Z5, X4/H5, TB-REV-159-U3/V3–V11, W3/W4/W6/W7, RA-281 F1–F3, Amendment 14, O47/C5/O48/O49 and sphere χ+4. No CP3/497/D0/H4 promotion. |
| Active boundary | The production sphere still stops at `CutSearchExhaustedBeforeCellularity`. The staged row-979 plan stops at `SourceFaceCarriesMultipleTraceCuts`, `6-8-9`: a singular corner (node 1) with rays from traces 3 and 4, slide arrivals from traces 0 and 9, and trace 0's segment 6 split at node 12 into arcs 0 and 1. Activation is held until the staged plan builds (G5). |

## Mandatory next turn

- **COMPLETE (Code + Build):** `M6-CP3-CB-188-P13-REGION-VISIT-READER`, exact frozen diff `5f06c14b…005d05944`, source `b2e976f204fa5b2988a9cbe5a77defd106a96aad`. Eight-target GMP/GMPXX [compile run 45101939539](https://github.com/akashskypatel/Directional/actions/runs/45101939539) PASS. [Record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md). No compiled binary executed.
- **NEXT:** `M6-CP3-TB-EXEC-169-P13-REGION-VISIT-READER-FULL-GATE`, artifact-only on immutable package `14786260085`; then independent TB-REV-169. CB-189 is a later Code + Build turn.
- **HOLD:** no CP3/497/D0/H4 or production promotion; activation awaits staged plan G5.

```
NEXT_TURN: M6-CP3-TB-EXEC-169-P13-REGION-VISIT-READER-FULL-GATE
Owner: Test + Benchmark agent; do not rebuild or edit source/tests/selectors/manifests
Authority: .agents/Directional/Architecture_M6_CP3_TB_REV_168_Adversarial_Review_20261123.md (Q1-Q7) + Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md
Exact source: b2e976f204fa5b2988a9cbe5a77defd106a96aad
Immutable compiled artifact: 14786260085; ZIP SHA-256 d877a0ea4c05cfe93275506823652abb6b0e012dd3a5925103606e28e69625a5; compile run 45101939539; runtimeExecution=false
Manifest: unchanged TB168 993 rows
Gate: 993/993 PASS, CP2 491/491, membership 1074; rows other than 979 equal TB168 artifact 14781634158 under N1-N3 with zero allowance
Row 979: fragmentOwnerFace 6-8-9,16-20-21,32-33-34,40-45-46 each traceChordCount=4, expectedFragmentCount=5, ownerCount=5, ownerDeficit=0
Outcome: SourceFaceCarriesMultipleTraceCuts sourceFace=6-8-9 remains; every other row-979 line unchanged; any other change STOP to Review
No census. On completion: M6-CP3-TB-REV-169-P13-REGION-VISIT-READER-FULL-GATE
Do not execute CB-189, run a build, activate, or promote CP3/497/D0/H4
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
| **NEXT** | TB-EXEC-169 → TB-REV-169 | Immutable package `14786260085`. Row 979 expected 4 chords, 5 owners and zero deficit on four faces; all other rows unchanged. |
| 3 | CB-189 → TB-EXEC-170 → TB-REV-170 | Amended diff `6e391678…e3b8`. Row 979 builds the staged plan or prints the next typed stage. Row 652 still passes. C1/C2 count as witnessed only if printed. |
| 4 | CB-190 | S4/S6/S7 diagnostic conformity (off critical path). |
| 5 | Activation → TB → V3b → R1 → O48 | After the staged plan builds. |
| Withdrawn | prose CB-180 (X2); DEFN-161A (W3); prose CB-178 (V2); DEFN-159A (U1); prose CB-175; CB-174 v3; CB-172A; prose CB-173; old CB-181/182 plan (Y1); prose CB-183 (Z1); activation-before-plan (G5); CB-185 v1 (K3/K4); prose CB-186 (L2–L7); prose CB-187 `…-EXACT-FACE-CUT-READER`, v1–v5, S5 STOP (P2–P7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [CB-188 record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-168 independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md), [CB-188 manifest](gates/Architecture_M6_CP3_CB188_P13_Visit_Reader_Exact_Manifest.md), [CB-189 manifest](gates/Architecture_M6_CP3_CB189_P13_Visit_Reader_Exact_Manifest.md), [TB168 execution report](Architecture_M6_CP3_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Execution_Report_20261123.md), [CB-187 code/build record](Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Code_Build_Record_20261123.md), [TB-REV-167 adversarial record](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md), [TB-REV-167 independent review](Architecture_M6_CP3_TB_REV_167_Face_Cut_Corner_Partition_Helper_Independent_Review_20261122.md), [TB167 report](Architecture_M6_CP3_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Execution_Report_20261122.md).

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
