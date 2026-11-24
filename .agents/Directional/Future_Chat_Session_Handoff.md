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
| Currency | 2026-11-24 UTC. **TB179 execution complete; gate rejected, independent review required.** 1,002/1,003 PASS, six existing RED recovered, row786 remains RED. [Report](Architecture_M6_CP3_TB179_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261124.md). Next only `M6-CP3-TB-REV-179`. |
| Branch / source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; exact CB-199B source `5d9468d168ee3c9eed086bd787979ced7f86843b`, GMP/GMPXX [run 45332816377](https://github.com/akashskypatel/Directional/actions/runs/45332816377), package `14893165901` SHA-256 `0ff23208d9329a02951d1aea83c0631ac7790b92bb3bfb46639d52d33e7c225c`, 28/28 hashes, eight targets, `runtimeExecution=false`. [Code + Build record](Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Code_Build_Record_20261124.md). |
| Current TB evidence | TB179 [run 45338168889](https://github.com/akashskypatel/Directional/actions/runs/45338168889), result `14895572803` ZIP SHA-256 `aeaacb099ea7d51292706802ccf3a9a64702abf70575d01bd8c52847acb0c636`, 2014/2014 checks; 1,002/1,003 PASS, row1003 PASS, zero green→red; 594 exact, 385 N1/N2, two N3, 21 changed inherited rows; zero committedSlide record changes. [Report](Architecture_M6_CP3_TB179_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261124.md). TB178 remains the comparison baseline. |
| Accepted comparison | TB169 run `45104059492`, result ZIP `14787082075` (`dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`), 993/993 accepted; CP2 491/491 accepted. Frozen prefix SHA-256 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. |
| Regression / debt | Existing TB170 mechanical recurrence: rows 445/652/653/656/658/660 pass; row786 remains RED at a later predicate. No new green→red; Review pending. Historical 67 events / 17 categories / 50 recurrences; witness debt1, deferred81. |
| First unresolved failure | Row786 `region_frontier_interior_arc_census_is_valid(*row)` at `FieldAlignedCurveNetworkTests.cpp:20101`; plan now exists. Row652 PASS, two region certificates, A2a 12→8 traces and graph E26→22/F6→2. Evidence supports removal of four co-traced zero-area lens orbits on this witness; D13=A. Row979 staged `RegionContainsInteriorSingularity` at source vertex8 remains held. |

## Mandatory next turn

- **COMPLETE (execution, rejected gate):** TB179. [Report](Architecture_M6_CP3_TB179_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261124.md). TB-REV-178 K1–K6 remain authoritative (links in Context Load Plan). No product acceptance.

```text
NEXT_TURN: M6-CP3-TB-REV-179
Owner: independent Test + Benchmark Review; runtime-free, no source changes
Authority: Architecture_M6_CP3_TB179_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261124.md; TB-REV-178 K1–K6; CB-199B exact source 5d9468d168ee3c9eed086bd787979ced7f86843b
Evidence: TB179 result 14895572803; TB178 result 14885616510; full hashes in report.
Scope: rederive 1,002 comparisons, row1003 and 21 changes (K4); verify two row652 regions; identify row786 cause before freezing CB-200. Retain every-region-owns-a-face assertion and J6 struck-reference obligation.
Stop: unexplained record, missing proof, violated contract, or authority mismatch. No CB-200 reader implementation, row979, Branch A, E5 or acceptance promotion during Review.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-EXEC/REV-165 | Adversarial records [TB-REV-162](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md), [163](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md), [164](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md), [165](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md). |
| COMPLETE | CB-185 → … → TB-EXEC-172 | Records: adversarial TB-REV-166…171 files; TB169 993/993 accepted; TB170 986/993, TB171/TB172 987/994 rejected; CB-192 package `14797941489`, CB-193 package `14805640405` (source `587b8ba7…f881`). |
| COMPLETE (rejected) | TB-REV-172 | [Independent](Architecture_M6_CP3_TB_REV_172_Along_Edge_Visit_Region_Receipt_Independent_Review_20261123.md), [adv. 1](Architecture_M6_CP3_TB_REV_172_Adversarial_Review_20261123.md), [adv. 2](Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md): co-traced digons, A2a root cause, D13 pending. |
| COMPLETE | CB-194 → TB-EXEC-173 → CB-195 → TB-EXEC-174 → CB-196 → TB-EXEC-175 (993/1000) | Unwired helpers; same 7 RED. Reviews TB-REV-173 ([D13](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md)), [174 adv.](Architecture_M6_CP3_TB_REV_174_Adversarial_Review_20261123.md), [175 adv.](Architecture_M6_CP3_TB_REV_175_Adversarial_Review_20261123.md). |
| COMPLETE | CB-197A → … → TB-REV-177 (TB176 994/1001, TB177 994/1001 rejected) | Adversarial records TB-REV-176/177; four row-652 pairs confirmed. |
| COMPLETE | CB-199A amended unwired remap helper + guard (compile only) | [Record](Architecture_M6_CP3_CB199A_P13_Retraced_Trace_Reference_Remap_Code_Build_Record_20261124.md). |
| COMPLETE (rejected) | TB-EXEC-178 (995/1002, comparison satisfied) | [Execution report](Architecture_M6_CP3_TB178_P13_Retraced_Trace_Reference_Remap_Full_Gate_Execution_Report_20261124.md). |
| COMPLETE | TB-REV-178 | [Independent](Architecture_M6_CP3_TB_REV_178_Retraced_Trace_Reference_Remap_Independent_Review_20261124.md) + [adversarial](Architecture_M6_CP3_TB_REV_178_Adversarial_Review_20261124.md); rejection upheld, CB-199B accepted. |
| COMPLETE (compile only) | `M6-CP3-CB-199B-P13-RETRACED-TRACE-SELECTION` | [Build record](Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Code_Build_Record_20261124.md); package 14893165901; runtime measured in TB179. |
| COMPLETE (rejected) | `M6-CP3-TB-EXEC-179-P13-RETRACED-TRACE-SELECTION-FULL-GATE` | Report above; row1003 PASS, six recoveries, row786 RED, 21 changed rows. |
| **1 NEXT** | `M6-CP3-TB-REV-179` | Compare evidence; identify row786 cause before CB-200. |
| 3 HELD | CB-200 scoped by TB-REV-179 (K5: no reader yet shown to need `arrivalPort`) + every-region-owns-a-face assertion → TB | All mechanical controls green, preserve row652 2 regions. |
| 3A | Digest-neutral rename of exact piece helpers out of `embedded_graph_topology_detail` (K6) → byte-identical TB | After controls green. |
| 4 | Row979 `RegionContainsInteriorSingularity` (vertex 8) | After mechanical controls green; read printed locus first. |
| 4A | Branch A (only after the staged plan builds): activation CB → TB (BunnyRandom census, V5) → parameter-deletion CB → V3b → R1 → O48 | Activation = single-source default (V11) + exact premise rows 393/648/858/971/972/978 only. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | CB-199A `4f458361…` sourcePort/junction ownership encoding (TB-REV-177 adv. J4); prose CB-198 (TB-REV-176 adv. H1); prose CB-197A (TB-REV-175 adv.); prose CB-196 arrival-port receipt (TB-REV-174 adv. F1); prose CB-195 arrival-port proof (TB-REV-173 E1); D13 user gate (E1); CB-194 interval receipt, both forms (TB-REV-172 adv. 2 C1); prose CB-193 (TB-REV-171 adv. B5); CB-191 reason receipt (TB-REV-170 adv. A1/A6); prose CB-180 (X2); DEFN-161A (W3); prose CB-178 (V2); DEFN-159A (U1); prose CB-175; CB-174 v3; CB-172A; prose CB-173; old CB-181/182 plan (Y1); prose CB-183 (Z1); activation-before-plan (G5); CB-185 v1 (K3/K4); prose CB-186 (L2–L7); prose CB-187 `…-EXACT-FACE-CUT-READER`, v1–v5, S5 STOP (P2–P7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB179 execution report](Architecture_M6_CP3_TB179_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261124.md), [TB-REV-178 adversarial K1–K6](Architecture_M6_CP3_TB_REV_178_Adversarial_Review_20261124.md), [CB-199B Code + Build record and TB179 request](Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Code_Build_Record_20261124.md), [TB179 frozen case manifest](gates/Architecture_M6_TB179_P13_Retraced_Trace_Selection_Full_Gate_Case_Manifest.tsv), [TB-REV-178 review](Architecture_M6_CP3_TB_REV_178_Retraced_Trace_Reference_Remap_Independent_Review_20261124.md), [CB-199B exact plan](gates/Architecture_M6_CP3_CB199B_P13_Retraced_Trace_Selection_Exact_Manifest.md), [TB178 execution report](Architecture_M6_CP3_TB178_P13_Retraced_Trace_Reference_Remap_Full_Gate_Execution_Report_20261124.md), [Independent review](Architecture_M6_CP3_TB_REV_177_Mechanical_Retrace_Selection_Independent_Review_20261124.md), [CB-199A Code + Build record](Architecture_M6_CP3_CB199A_P13_Retraced_Trace_Reference_Remap_Code_Build_Record_20261124.md), [TB178 case manifest](gates/Architecture_M6_TB178_P13_Retraced_Trace_Reference_Remap_Full_Gate_Case_Manifest.tsv), [Adversarial review](Architecture_M6_CP3_TB_REV_177_Adversarial_Review_20261124.md), [TB176 execution report](Architecture_M6_CP3_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Execution_Report_20261123.md), [CB-197B Code + Build record](Architecture_M6_CP3_CB197B_P13_Exact_Source_Retrace_Ordered_Stretches_Code_Build_Record_20261123.md), [TB-REV-175 adversarial](Architecture_M6_CP3_TB_REV_175_Adversarial_Review_20261123.md), [CB-197A/B manifest](gates/Architecture_M6_CP3_CB197AB_P13_Exact_Manifest.md), [TB175 execution report](Architecture_M6_CP3_TB175_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261123.md), [CB-196 Code + Build record](Architecture_M6_CP3_CB196_P13_Exact_Source_Retraced_Trace_Selection_Code_Build_Record_20261123.md), [TB174 execution report](Architecture_M6_CP3_TB174_P13_Retrace_Oracle_Full_Gate_Execution_Report_20261123.md), [CB-195 Code + Build evidence](Architecture_M6_CP3_CB195_P13_Exact_Source_Path_Retrace_Along_Edges_Progress_20261123.md), [TB-REV-173 D13 resolution](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md). Older Reviews resolve through [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17) and the Turn Sequence links.

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
