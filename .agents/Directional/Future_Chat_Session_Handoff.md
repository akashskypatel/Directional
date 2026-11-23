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
| Currency | 2026-11-23 UTC. TB-EXEC-173 completed as a **rejected** full gate: 989/996 PASS, 7 mechanical RED. Both CB-194 oracle cases 995/996 PASS; all 994 TB172 shared rows and normalized logs unchanged. Independent TB-REV-173 is next. D13 remains pending. |
| Branch / source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft; immutable CB-194 source `fae9eb71bb5806d71901cc2ccb8c925201be0c0a`, GMP/GMPXX build run `45173887503`, artifact `14820355596` (`817583b75f8d9a5f7b9e7300426756d1044d535e9f63ebf3ec5d5cf88fe45ec6`), `runtimeExecution=false`; TB173 no rebuild. |
| Current TB evidence | TB173 [run `45180338549`](https://github.com/akashskypatel/Directional/actions/runs/45180338549), result artifact `14821438542` ZIP SHA-256 `22851acd9b27eb56ff504f038f9e9761f5b9d07fda854682da512f5022bb223d`, 2000/2000 members verified, **989/996**, CP2 candidate 490/491, membership 1077. TB172 [run `45149928894`](https://github.com/akashskypatel/Directional/actions/runs/45149928894), artifact `14805479282` (`e9ddc7fd80d3e33b25b18901c783fbb21ec2eaf5c1b86438f887e93cee03edbc`), 1996/1996, 987/994. All common 994 logs and verdicts match under N1/N2 alone; no N3 or assertion-location exception. [TB173 report](Architecture_M6_CP3_TB173_P13_Shared_Edge_Oracle_Full_Gate_Execution_Report_20261123.md). |
| Accepted comparison | TB169 run `45104059492`, result ZIP `14787082075` (`dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`), 993/993 accepted; CP2 491/491 accepted. Frozen prefix SHA-256 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. |
| Regression / debt | Existing seven accepted-green mechanical failures at rows 445/652/653/656/658/660/786 remain RED. No new stable event; historical 67 events / 17 categories / 50 recurrences; witness debt1, deferred81. |
| First unresolved failure | Row652 `RegionElectedCutComponentEmpty`, four co-traced zero-area lens orbits 1/3/4/5 from A2a; review D13 before any producer repair. Row979 staged `RegionContainsInteriorSingularity` at source vertex8; not production success. |

## Mandatory next turn

- **COMPLETE (rejected semantic gate):** `M6-CP3-TB-EXEC-173-P13-SHARED-EDGE-ORACLE-FULL-GATE`. Immutable artifact-only 996-case gate executed with no build or source mutation. Two new oracle tests PASS; seven mechanical controls remain RED. [Report](Architecture_M6_CP3_TB173_P13_Shared_Edge_Oracle_Full_Gate_Execution_Report_20261123.md).
- **NEXT (separate independent review):** `M6-CP3-TB-REV-173-P13-SHARED-EDGE-ORACLE-FULL-GATE` — reopen both TB172/TB173 result archives, recheck N1–N3 and oracle evidence, and re-ask D13 for singularity-port arrival before any code repair. Do not activate CP3/497/D0/H4 or start CB-195/CB-196 without that decision.
- **Held:** CB-195/CB-196; row979 sphere stage; Branch A activation and production sphere; CB-190 and CP3/497/D0/H4. TB169/CP2 remain accepted.

```text
NEXT_TURN: M6-CP3-TB-REV-173-P13-SHARED-EDGE-ORACLE-FULL-GATE
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-EXEC/REV-165 | Adversarial records [TB-REV-162](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md), [163](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md), [164](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md), [165](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md). |
| COMPLETE | CB-185 → … → TB-EXEC-172 | Records: adversarial TB-REV-166…171 files; TB169 993/993 accepted; TB170 986/993, TB171/TB172 987/994 rejected; CB-192 package `14797941489`, CB-193 package `14805640405` (source `587b8ba7…f881`). |
| COMPLETE (rejected) | TB-REV-172 | [Independent](Architecture_M6_CP3_TB_REV_172_Along_Edge_Visit_Region_Receipt_Independent_Review_20261123.md), [adv. 1](Architecture_M6_CP3_TB_REV_172_Adversarial_Review_20261123.md), [adv. 2](Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md): co-traced digons, A2a root cause, D13 pending. |
| COMPLETE | CB-194 shared-edge oracle | Exact two-file diff compiled, no runtime, helper remains unwired. |
| COMPLETE (rejected) | TB-EXEC-173 | 996 rows; 989 PASS, same 7 RED; oracle 995/996 PASS. |
| **NEXT** | TB-REV-173 | Independent archive review and D13 question; no producer mutation. |
| 3 | TB-REV-173 → CB-195 (A2a helpers) → TB → CB-196 (D13 wiring + region-owns-face assertion) → TB | D13 re-asked first; mechanical controls must turn green with 2 regions. |
| 4 | Row979 `RegionContainsInteriorSingularity` (vertex 8) | After mechanical controls green; read printed locus first. |
| 4A | Branch A (only after the staged plan builds): activation CB → TB (BunnyRandom census, V5) → parameter-deletion CB → V3b → R1 → O48 | Activation = single-source default (V11) + exact premise rows 393/648/858/971/972/978 only. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | CB-194 interval receipt, both forms (TB-REV-172 adv. 2 C1); prose CB-193 (TB-REV-171 adv. B5); CB-191 reason receipt (TB-REV-170 adv. A1/A6); prose CB-180 (X2); DEFN-161A (W3); prose CB-178 (V2); DEFN-159A (U1); prose CB-175; CB-174 v3; CB-172A; prose CB-173; old CB-181/182 plan (Y1); prose CB-183 (Z1); activation-before-plan (G5); CB-185 v1 (K3/K4); prose CB-186 (L2–L7); prose CB-187 `…-EXACT-FACE-CUT-READER`, v1–v5, S5 STOP (P2–P7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB173 execution report](Architecture_M6_CP3_TB173_P13_Shared_Edge_Oracle_Full_Gate_Execution_Report_20261123.md), [CB-194 Code + Build record](Architecture_M6_CP3_CB194_P13_Exact_Source_Path_Shared_Edge_Oracle_Code_Build_Record_20261123.md), [TB-REV-172 second adversarial continuation](Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md), [TB171 RED report](Architecture_M6_CP3_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Execution_Report_20261123.md), [TB-REV-170 adversarial review](Architecture_M6_CP3_TB_REV_170_Adversarial_Review_20261123.md), [CB-192 Code + Build](Architecture_M6_CP3_CB192_P13_Along_Edge_Face_Piece_Classifier_Code_Build_Record_20261123.md), [CB-189 Code + Build](Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-169 review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md), [TB169 report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md), [CB-188 record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-168 independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md), [CB-188 manifest](gates/Architecture_M6_CP3_CB188_P13_Visit_Reader_Exact_Manifest.md), [CB-189 manifest](gates/Architecture_M6_CP3_CB189_P13_Visit_Reader_Exact_Manifest.md), [TB168 execution report](Architecture_M6_CP3_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Execution_Report_20261123.md), [CB-187 code/build record](Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Code_Build_Record_20261123.md), [TB-REV-167 adversarial record](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md), [TB-REV-167 independent review](Architecture_M6_CP3_TB_REV_167_Face_Cut_Corner_Partition_Helper_Independent_Review_20261122.md), [TB167 report](Architecture_M6_CP3_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Execution_Report_20261122.md).

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
