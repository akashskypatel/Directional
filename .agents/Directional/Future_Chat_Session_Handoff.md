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
| Currency | 2026-11-23 UTC. CB-196 exact retraced-trace selection helper compiled (GMP/GMPXX, no runtime); TB-EXEC-175 is the one next turn. TB174 remains rejected 991/998 (same seven RED). |
| Branch / source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft; immutable CB-196 source `f4acd5d1f29d55f36c427e88fed8f5ca09ae7ee5`; GMP/GMPXX compile [run `45225040406`](https://github.com/akashskypatel/Directional/actions/runs/45225040406), artifact `14845101702` (SHA-256 `9afbf9c90c96697c49e97669ba108d68e61f57d0182cff3f42807d133be6034f`), log `14844220690` (SHA-256 `c9fe20e317b2cb8ab3d985af6171d38ce691df23ba15cc7ab239e425f15b945b`), 28/28 internal hashes, eight targets, clean source, `runtimeExecution=false`. |
| Current TB evidence | TB174 [run `45206305297`](https://github.com/akashskypatel/Directional/actions/runs/45206305297), result `14833644440` SHA-256 `f77730c1896c346b15de704c90326a5a6543816a3e8ab553d4d8a70b9e11d5a3`, 2004/2004 checksums, **991/998** (seven RED), CP2 candidate 490/491, membership 1079. TB173 result `14821438542` SHA-256 `22851acd9b27eb56ff504f038f9e9761f5b9d07fda854682da512f5022bb223d`, 2000/2000, 989/996. Complete 996-row comparison: 741 identical raw logs, 254 N1/N2, row179 N3 (24 exact diagnostic records reordered); no other drift. [TB174 report](Architecture_M6_CP3_TB174_P13_Retrace_Oracle_Full_Gate_Execution_Report_20261123.md). |
| Accepted comparison | TB169 run `45104059492`, result ZIP `14787082075` (`dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`), 993/993 accepted; CP2 491/491 accepted. Frozen prefix SHA-256 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. |
| Regression / debt | Existing seven accepted-green mechanical failures at rows 445/652/653/656/658/660/786 remain RED. No new stable event; historical 67 events / 17 categories / 50 recurrences; witness debt1, deferred81. |
| First unresolved failure | Row652 `RegionElectedCutComponentEmpty`, four co-traced zero-area lens orbits 1/3/4/5 from A2a; D13 = A (DESIGN); repair = A2a step-7 selection (CB-197). Row979 staged `RegionContainsInteriorSingularity` at source vertex8; not production success. |

## Mandatory next turn

- **COMPLETE:** TB-REV-174 [independent](Architecture_M6_CP3_TB_REV_174_Retrace_Oracle_Independent_Review_20261123.md) + [adversarial](Architecture_M6_CP3_TB_REV_174_Adversarial_Review_20261123.md): TB174 rejected 991/998 (same seven RED, predicted). Prose CB-196 receipt withdrawn: arrival port of a retraced duplicate = its own `Y.port` (F1).
- Removing a duplicate after tracing must remap `struckTrace` and event incidences naming it (F3); path builder must be piece-accurate `exact_trace_segment_pieces` (F4); missing path fails closed (F5).

```text
NEXT_TURN: M6-CP3-TB-EXEC-175-P13-RETRACED-TRACE-SELECTION-FULL-GATE
Owner: artifact-only Test + Benchmark execution agent; no source changes or rebuild
Source: f4acd5d1f29d55f36c427e88fed8f5ca09ae7ee5
Compile: run 45225040406, GMP/GMPXX, eight targets, 28/28 internal SHA-256 checks, runtimeExecution=false
Package: artifact 14845101702, ZIP SHA-256 9afbf9c90c96697c49e97669ba108d68e61f57d0182cff3f42807d133be6034f
Log: artifact 14844220690, ZIP SHA-256 c9fe20e317b2cb8ab3d985af6171d38ce691df23ba15cc7ab239e425f15b945b
Manifest: gates/Architecture_M6_TB175_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv
  SHA-256 e1d77fd2a10b67e71ecbc6712a92eec48713e91e0006c7282652dc2391b43e35, 1000 rows, membership 1081
Expect: 993 PASS, only seven known RED rows 445/652/653/656/658/660/786; new rows 999-1000 PASS
Compare: all 998 TB174 rows against immutable result 14833644440 under N1-N3; only diff-proven assertion-line shifts allowed (none expected)
STOP: any unexpected behavior difference; report to TB-REV-175; do not promote CP3/497/D0/H4
Then: M6-CP3-TB-REV-175 (decide CB-197a exact source piece-builder extraction and per-fixture receipt)
No CB-197a/CB-197b/CB-198 work, production wiring, selector edits, or tests during CB-196.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-EXEC/REV-165 | Adversarial records [TB-REV-162](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md), [163](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md), [164](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md), [165](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md). |
| COMPLETE | CB-185 → … → TB-EXEC-172 | Records: adversarial TB-REV-166…171 files; TB169 993/993 accepted; TB170 986/993, TB171/TB172 987/994 rejected; CB-192 package `14797941489`, CB-193 package `14805640405` (source `587b8ba7…f881`). |
| COMPLETE (rejected) | TB-REV-172 | [Independent](Architecture_M6_CP3_TB_REV_172_Along_Edge_Visit_Region_Receipt_Independent_Review_20261123.md), [adv. 1](Architecture_M6_CP3_TB_REV_172_Adversarial_Review_20261123.md), [adv. 2](Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md): co-traced digons, A2a root cause, D13 pending. |
| COMPLETE | CB-194 → TB-EXEC-173 (989/996) → CB-195 → TB-EXEC-174 (991/998) | Unwired helpers; same 7 RED; CB-195 source `29415df1…3b9d`. |
| COMPLETE | TB-REV-173 | Independent + [D13 resolution](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md): D13 = A by DESIGN. |
| COMPLETE | TB-REV-174 | Independent + [adversarial](Architecture_M6_CP3_TB_REV_174_Adversarial_Review_20261123.md) F1–F5. |
| COMPLETE | CB-196 exact retraced-trace selection helper | GMP/GMPXX compile run `45225040406`, package `14845101702`, unwired; no runtime. |
| **NEXT** 1 | TB-EXEC-175 (1000 rows, 993 expected PASS, same 7 RED) | Artifact-only immutable gate. |
| 2 | TB-REV-175 → CB-197a extract `exact_trace_segment_pieces` to A2a layer (product-neutral) → TB | Decide per-fixture selection receipt (row652 predicted 4 pairs). |
| 3 | TB-REV → CB-197b selection in `canonical_field_aligned_candidate` + remap `struckTrace`/incidences + arrival owns `Y.port`, fail-closed missing path → TB | — |
| 3B | CB-198 port-set readers (EmbeddedGraphTopology 1793, GlobalTopologyPlan 410/2117, origin events) + every-region-owns-a-face assertion → TB | Mechanical controls green, row652 2 regions. |
| 4 | Row979 `RegionContainsInteriorSingularity` (vertex 8) | After mechanical controls green; read printed locus first. |
| 4A | Branch A (only after the staged plan builds): activation CB → TB (BunnyRandom census, V5) → parameter-deletion CB → V3b → R1 → O48 | Activation = single-source default (V11) + exact premise rows 393/648/858/971/972/978 only. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | prose CB-196 arrival-port receipt (TB-REV-174 adv. F1); prose CB-195 arrival-port proof (TB-REV-173 E1); D13 user gate (E1); CB-194 interval receipt, both forms (TB-REV-172 adv. 2 C1); prose CB-193 (TB-REV-171 adv. B5); CB-191 reason receipt (TB-REV-170 adv. A1/A6); prose CB-180 (X2); DEFN-161A (W3); prose CB-178 (V2); DEFN-159A (U1); prose CB-175; CB-174 v3; CB-172A; prose CB-173; old CB-181/182 plan (Y1); prose CB-183 (Z1); activation-before-plan (G5); CB-185 v1 (K3/K4); prose CB-186 (L2–L7); prose CB-187 `…-EXACT-FACE-CUT-READER`, v1–v5, S5 STOP (P2–P7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [CB-196 Code + Build record](Architecture_M6_CP3_CB196_P13_Exact_Source_Retraced_Trace_Selection_Code_Build_Record_20261123.md), [TB174 execution report](Architecture_M6_CP3_TB174_P13_Retrace_Oracle_Full_Gate_Execution_Report_20261123.md), [CB-195 Code + Build evidence](Architecture_M6_CP3_CB195_P13_Exact_Source_Path_Retrace_Along_Edges_Progress_20261123.md), [TB-REV-173 D13 resolution](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md), [TB-REV-173 independent](Architecture_M6_CP3_TB_REV_173_Shared_Edge_Oracle_Independent_Review_20261123.md), [TB173 execution report](Architecture_M6_CP3_TB173_P13_Shared_Edge_Oracle_Full_Gate_Execution_Report_20261123.md), [CB-194 Code + Build record](Architecture_M6_CP3_CB194_P13_Exact_Source_Path_Shared_Edge_Oracle_Code_Build_Record_20261123.md), [TB-REV-172 second adversarial continuation](Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md), [TB171 RED report](Architecture_M6_CP3_TB171_P13_Along_Edge_Face_Piece_Full_Gate_Execution_Report_20261123.md), [TB-REV-170 adversarial review](Architecture_M6_CP3_TB_REV_170_Adversarial_Review_20261123.md), [CB-192 Code + Build](Architecture_M6_CP3_CB192_P13_Along_Edge_Face_Piece_Classifier_Code_Build_Record_20261123.md), [CB-189 Code + Build](Architecture_M6_CP3_CB189_P13_Corner_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-169 review](Architecture_M6_CP3_TB_REV_169_Region_Visit_Reader_Independent_Review_20261123.md), [TB169 report](Architecture_M6_CP3_TB169_P13_Region_Visit_Reader_Full_Gate_Execution_Report_20261123.md), [CB-188 record](Architecture_M6_CP3_CB188_P13_Region_Visit_Reader_Code_Build_Record_20261123.md), [TB-REV-168 independent review](Architecture_M6_CP3_TB_REV_168_Independent_Review_20261123.md), [CB-188 manifest](gates/Architecture_M6_CP3_CB188_P13_Visit_Reader_Exact_Manifest.md), [CB-189 manifest](gates/Architecture_M6_CP3_CB189_P13_Visit_Reader_Exact_Manifest.md), [TB168 execution report](Architecture_M6_CP3_TB168_P13_Arc_Face_Visit_Adapter_Full_Gate_Execution_Report_20261123.md), [CB-187 code/build record](Architecture_M6_CP3_CB187_P13_Arc_Face_Visit_Adapter_Code_Build_Record_20261123.md), [TB-REV-167 adversarial record](Architecture_M6_CP3_TB_REV_167_Adversarial_Review_20261123.md), [TB-REV-167 independent review](Architecture_M6_CP3_TB_REV_167_Face_Cut_Corner_Partition_Helper_Independent_Review_20261122.md), [TB167 report](Architecture_M6_CP3_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Execution_Report_20261122.md).

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
