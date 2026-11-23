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
| Currency | 2026-11-23 UTC. TB-EXEC-170 **986/993 PASS**, independent Review pending; [TB170 report](Architecture_M6_CP3_TB170_P13_Corner_Visit_Reader_Full_Gate_Execution_Report_20261123.md). Last independently accepted full gate remains TB169 993/993. |
| Branch and package | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB-189 source `178f17dd59aa9c61c2e6462e2378e3a42b0ee4f7`; eight-target compile run `45113944225`, immutable package `14790917101`, outer SHA-256 `0432359393d37cf00b9654339c832263f648733237005171ff3a8eb9cfa1ddfd`; GMP/GMPXX; `runtimeExecution=false`. |
| Latest gate / census | TB170 run `45118730914`, result `14793023424`, ZIP SHA-256 `930a4a42cd5f15c1479fd0ba098ff21e5860d5fbcf37520e2c1d7bb5ca652d55`; **986/993 PASS** with N1–N3 off-row differences **21** and measured row979 `SphereStagedPlan outcome=RegionContainsInteriorSingularity sourceFace=- sourceEdge=- trace=- secondTrace=- chi=- V=- E=- F=- fragmentOrbits=- tracePieces=- expectedFragments=-`. No new production census; latest three-case census remains TB165. |
| Accepted history | CP2 491/491, package `11391685901`; CP3 497 identities frozen, not promoted. TB169 independently accepted 993/993, result `14787082075`. |
| Regression / debt | Stable 66 events / 17 categories / 49 recurrences, one witness debt, 81 deferred. TB170 observation still requires independent classification. CP3/497/D0/H4 held. |
| Active boundary | Production sphere remains `CutSearchExhaustedBeforeCellularity`. CB-189 row979 staged output is an isolated test measurement; no accepted production result. |

## Mandatory next turn

**NEXT:** `M6-CP3-TB-REV-170-P13-CORNER-VISIT-READER-FULL-GATE` — independent Review of the already executed artifact-only TB170 and predecessor TB169. **Do not execute another gate, build, activate or proceed to any later branch within this current TB turn.**

**Evidence:** [TB170 execution report](Architecture_M6_CP3_TB170_P13_Corner_Visit_Reader_Full_Gate_Execution_Report_20261123.md); source `178f17dd59aa9c61c2e6462e2378e3a42b0ee4f7`, package `14790917101` with exact ZIP SHA-256 `0432359393d37cf00b9654339c832263f648733237005171ff3a8eb9cfa1ddfd`; run [45118730914](https://github.com/akashskypatel/Directional/actions/runs/45118730914), result `14793023424` SHA-256 `930a4a42cd5f15c1479fd0ba098ff21e5860d5fbcf37520e2c1d7bb5ca652d55`; TB169 baseline `45104059492` result `14787082075`.

**Review gate:** independently verify both artifact ZIPs, every internal hash, 993-row N1–N3 comparison showing 21 off-row differences, row652 RED, full row979 typed stage with source path; distinguish a true later-stage advance from an unaccepted/falsified prediction. Classify off-row changes and any candidate regressions using the frozen criteria. Preserve CP3/497/D0/H4 and fail-closed behavior.

```text
NEXT_TURN: M6-CP3-TB-REV-170-P13-CORNER-VISIT-READER-FULL-GATE
Owner: independent Review, read-only, separate turn
Source: 178f17dd59aa9c61c2e6462e2378e3a42b0ee4f7
Package: 14790917101 (SHA-256 0432359393d37cf00b9654339c832263f648733237005171ff3a8eb9cfa1ddfd)
Test run: 45118730914; result: 14793023424; ZIP SHA-256: 930a4a42cd5f15c1479fd0ba098ff21e5860d5fbcf37520e2c1d7bb5ca652d55
Reference: TB169 run 45104059492; result 14787082075; exact frozen 993-case manifest
Frozen comparisons: N1/N2/N3, row979 exception only; row652 RED
Result: 986/993 PASS, CP2 490/491, membership 1074, off-row differences 21; row979 SphereStagedPlan outcome=RegionContainsInteriorSingularity sourceFace=- sourceEdge=- trace=- secondTrace=- chi=- V=- E=- F=- fragmentOrbits=- tracePieces=- expectedFragments=-
Do not: rebuild, test, census, source edit, activate or promote CP3/497/D0/H4 in Review
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-EXEC/REV-165 | Adversarial records [TB-REV-162](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md), [163](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md), [164](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md), [165](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md). |
| COMPLETE | CB-185 → TB-EXEC-166 → TB-REV-166 ([adv.](Architecture_M6_CP3_TB_REV_166_Adversarial_Review_20261122.md)) → CB-186 → TB-EXEC-167 | [TB167](Architecture_M6_CP3_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Execution_Report_20261122.md): 989/989. |
| COMPLETE | TB-REV-167 ([adv.](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md)) → CB-187 → TB-EXEC-168 → TB-REV-168 ([adv.](Architecture_M6_CP3_TB_REV_168_Adversarial_Review_20261123.md)) | CB-187 package `14781561211`; TB168 993/993. CB-188 `5f06c14b…5944`; CB-189 amended `6e391678…e3b8`. |
| COMPLETE (Code + Build) | CB-188 | [Record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md), exact source `b2e976f204fa5b2988a9cbe5a77defd106a96aad`; compile run `45101939539`, package `14786260085`, no runtime. |
| COMPLETE TB / Review | TB-EXEC-169 → TB-REV-169 | [TB169 report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md), [independent](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md) + [adversarial](Architecture_M6_CP3_TB_REV_169_Adversarial_Review_20261123.md) (W1–W6): 993/993 PASS, four exact row979 face changes; no promotion. |
| **COMPLETE CB-189 and TB-EXEC-170 / NEXT TB-REV-170** | CB-189 → TB-EXEC-170 → TB-REV-170 | Amended diff `6e391678…e3b8`. Rows other than 979 equal TB169; row 652 passes. Row 979 is a measurement: predicted to clear the corner stage (W2), and a new-code outcome falsifies W2. TB-REV-170 freezes exact diffs for Branch A or B (W5). |
| 4A | Branch A (plan built): activation CB → TB (BunnyRandom census, V5) → parameter-deletion CB → V3b → R1 → O48 | Activation = single-source default (V11) + exact premise rows 393/648/858/971/972/978 only. Nothing else bundled. |
| 4B | Branch B (next typed stage): receipt CB **or** narrow repair CB → TB | Read the existing locus first (RA-235). W3's piece receipt only if a corner-stage RED is ambiguous. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | prose CB-180 (X2); DEFN-161A (W3); prose CB-178 (V2); DEFN-159A (U1); prose CB-175; CB-174 v3; CB-172A; prose CB-173; old CB-181/182 plan (Y1); prose CB-183 (Z1); activation-before-plan (G5); CB-185 v1 (K3/K4); prose CB-186 (L2–L7); prose CB-187 `…-EXACT-FACE-CUT-READER`, v1–v5, S5 STOP (P2–P7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [CB-189 Code + Build](Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-169 review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md), [TB169 report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md), [CB-188 record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-168 independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md), [CB-188 manifest](gates/Architecture_M6_CP3_CB188_P13_Visit_Reader_Exact_Manifest.md), [CB-189 manifest](gates/Architecture_M6_CP3_CB189_P13_Visit_Reader_Exact_Manifest.md), [TB168 execution report](Architecture_M6_CP3_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Execution_Report_20261123.md), [CB-187 code/build record](Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Code_Build_Record_20261123.md), [TB-REV-167 adversarial record](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md), [TB-REV-167 independent review](Architecture_M6_CP3_TB_REV_167_Face_Cut_Corner_Partition_Helper_Independent_Review_20261122.md), [TB167 report](Architecture_M6_CP3_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Execution_Report_20261122.md).

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
