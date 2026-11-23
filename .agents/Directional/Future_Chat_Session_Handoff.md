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
| Currency | 2026-11-23 UTC. **M6-CP3-TB-REV-176 COMPLETE / GATE REJECTED**: independent archive review confirms TB176 994/1001 PASS, seven unchanged RED, run `45263429563`, artifact `14861444963`. Next **M6-CP3-CB-198-P13-MECHANICAL-RETRACE-SELECTION-RECEIPT** test-only receipt. CB-197B source and GMP package remain unchanged. [Review](Architecture_M6_CP3_TB_REV_176_P13_Piece_Builder_And_Ordered_Retrace_Independent_Review_20261123.md). |
| Branch / source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 open/draft; immutable CB-197B source `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`, GMP/GMPXX [run 45255304770](https://github.com/akashskypatel/Directional/actions/runs/45255304770), artifact `14859356205` SHA-256 `e6111ff21530f107ab8b1db724155aa2c4fbbe4a2765342fbfabbd4a9c4fc664`, log `14858416869` SHA-256 `724f34a99244c44b3b7fa1b613d64f395e18cd046e95a9c3dc564d9c1e36d860`, 28/28 checks, eight targets, `runtimeExecution=false`. [Code + Build record](Architecture_M6_CP3_CB197B_P13_Exact_Source_Retrace_Ordered_Stretches_Code_Build_Record_20261123.md). |
| Current TB evidence | TB176 [run `45263429563`](https://github.com/akashskypatel/Directional/actions/runs/45263429563), result `14861444963` SHA-256 `202cb81282d9e8a0bb6b711020af80450e407feb12b71de613b1be8cca110453`, **994/1001 PASS**, seven RED, **2010/2010** checksums, 1082 members. Against TB175: 1000/1000 inherited ledger fields match; 778 exact and 222 N1/N2 normalized logs, no unapproved changes. New row1001 PASS. [TB176 report](Architecture_M6_CP3_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Execution_Report_20261123.md). TB175 [run `45233825958`](https://github.com/akashskypatel/Directional/actions/runs/45233825958), result `14849271506` SHA-256 `be7a0f783d0afb025ccee2353921a765c340766340553f2d70b4b5c32992b347`, 993/1000, seven RED; 2008/2008 hashes. |
| Accepted comparison | TB169 run `45104059492`, result ZIP `14787082075` (`dc15a8df5226fc209717f6df2fd15140e9e04abb6e73f831d8285992e72f04e5`), 993/993 accepted; CP2 491/491 accepted. Frozen prefix SHA-256 `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. |
| Regression / debt | Existing seven accepted-green mechanical failures at rows 445/652/653/656/658/660/786 remain RED. No new stable event; historical 67 events / 17 categories / 50 recurrences; witness debt1, deferred81. |
| First unresolved failure | Row652 `RegionElectedCutComponentEmpty`, four co-traced zero-area lens orbits 1/3/4/5 from A2a; D13 = A (DESIGN); repair = A2a step-7 selection (CB-197). Row979 staged `RegionContainsInteriorSingularity` at source vertex8; not production success. |

## Mandatory next turn

- **COMPLETE:** CB-197A [Code + Build record](Architecture_M6_CP3_CB197A_P13_Exact_Trace_Piece_Builder_Extraction_Code_Build_Record_20261123.md): exact extraction, GMP/GMPXX compile-only [run 45250530743](https://github.com/akashskypatel/Directional/actions/runs/45250530743).
- **COMPLETE:** CB-197B [CB-197B Code + Build record](Architecture_M6_CP3_CB197B_P13_Exact_Source_Retrace_Ordered_Stretches_Code_Build_Record_20261123.md): exact +57/−27 two-file ordered-stretch retrace; source `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3`; GMP/GMPXX compile-only [run 45255304770](https://github.com/akashskypatel/Directional/actions/runs/45255304770), eight targets, 28/28 package checks, no runtime.
- **COMPLETE:** TB-REV-175 [independent](Architecture_M6_CP3_TB_REV_175_Retraced_Trace_Selection_Independent_Review_20261123.md) and [adversarial](Architecture_M6_CP3_TB_REV_175_Adversarial_Review_20261123.md). TB175 rejected 993/1000 with seven RED. The new helper remains unwired; no production acceptance.

- **COMPLETE / REJECTED:** TB-EXEC-176 [execution report](Architecture_M6_CP3_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Execution_Report_20261123.md), [run 45263429563](https://github.com/akashskypatel/Directional/actions/runs/45263429563), artifact `14861444963` SHA-256 `202cb81282d9e8a0bb6b711020af80450e407feb12b71de613b1be8cca110453`: 994/1001 PASS, seven existing RED, 2010/2010 hashes, all 1000 inherited rows identical after N1/N2 normalization, row1001 PASS. No source/test/selector/build changes. A2a remains unwired; no production acceptance.

```text
NEXT_TURN: M6-CP3-CB-198-P13-MECHANICAL-RETRACE-SELECTION-RECEIPT
Owner: separate Code + Build turn. Test-only receipt proving per-fixture exact source-pieces selection, no A2a product mutation.
Authority: M6-CP3-TB-REV-176 independent review and TB-REV-175 adversarial G1–G4.
Use source: 8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3; review snapshot: 6240ea392114da3d8be5ae9a7cbe019a880a782e
Test-only per-fixture selected/removed exact directed source path pairs; require positive-length reverse overlap and retain every lineage; missing path fails closed. Row652 four pair removals are predicted, not assumed.
Stop on absent source path, changed production output, new acceptance/regression, or false/unsupported ownership claim; return to Review rather than silently adjusting.
Compile-only GMP/GMPXX; no test/benchmark runtime in CB-198. After CB-198 the separately authorized TB-EXEC-177 is next, not part of this turn.
No CP3/497/D0/H4 promotion, selector edit, or A2a production wiring in this Review.
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-EXEC/REV-165 | Adversarial records [TB-REV-162](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md), [163](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md), [164](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md), [165](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md). |
| COMPLETE | CB-185 → … → TB-EXEC-172 | Records: adversarial TB-REV-166…171 files; TB169 993/993 accepted; TB170 986/993, TB171/TB172 987/994 rejected; CB-192 package `14797941489`, CB-193 package `14805640405` (source `587b8ba7…f881`). |
| COMPLETE (rejected) | TB-REV-172 | [Independent](Architecture_M6_CP3_TB_REV_172_Along_Edge_Visit_Region_Receipt_Independent_Review_20261123.md), [adv. 1](Architecture_M6_CP3_TB_REV_172_Adversarial_Review_20261123.md), [adv. 2](Architecture_M6_CP3_TB_REV_172_Adversarial_Continuation_Shared_Edge_20261123.md): co-traced digons, A2a root cause, D13 pending. |
| COMPLETE | CB-194 → TB-EXEC-173 → CB-195 → TB-EXEC-174 → CB-196 → TB-EXEC-175 (993/1000) | Unwired helpers; same 7 RED. Reviews TB-REV-173 ([D13](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md)), [174 adv.](Architecture_M6_CP3_TB_REV_174_Adversarial_Review_20261123.md), [175 adv.](Architecture_M6_CP3_TB_REV_175_Adversarial_Review_20261123.md). |
| **COMPLETE** CB-197A, CB-197B and TB-EXEC-176 (rejected); **COMPLETE** TB-REV-176; **NEXT** CB-198 | CB-197B source `8d2dd3d42ecb6b2f36d6934f72e43bdf8bb6efe3` measured 994/1001 PASS; the seven known RED remain. | Immutable run 45263429563 / artifact 14861444963, all 2010 checksums valid; full TB175 comparison matches under N1/N2. |
| 2 | TB-REV-176 COMPLETE → CB-198 test-only per-fixture selection receipt → TB-EXEC-177 | Row652 predicted 4 pairs; missing path fails closed. |
| 3 | TB-REV → CB-199 selection in `canonical_field_aligned_candidate` + remap `struckTrace`/incidences + arrival owns `Y.port`, fail-closed → TB | — |
| 3B | CB-200 port-set readers (EmbeddedGraphTopology 1793, GlobalTopologyPlan 410/2117, origin events) + every-region-owns-a-face assertion → TB | Mechanical controls green, row652 2 regions. |
| 4 | Row979 `RegionContainsInteriorSingularity` (vertex 8) | After mechanical controls green; read printed locus first. |
| 4A | Branch A (only after the staged plan builds): activation CB → TB (BunnyRandom census, V5) → parameter-deletion CB → V3b → R1 → O48 | Activation = single-source default (V11) + exact premise rows 393/648/858/971/972/978 only. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | prose CB-197A (TB-REV-175 adv.); prose CB-196 arrival-port receipt (TB-REV-174 adv. F1); prose CB-195 arrival-port proof (TB-REV-173 E1); D13 user gate (E1); CB-194 interval receipt, both forms (TB-REV-172 adv. 2 C1); prose CB-193 (TB-REV-171 adv. B5); CB-191 reason receipt (TB-REV-170 adv. A1/A6); prose CB-180 (X2); DEFN-161A (W3); prose CB-178 (V2); DEFN-159A (U1); prose CB-175; CB-174 v3; CB-172A; prose CB-173; old CB-181/182 plan (Y1); prose CB-183 (Z1); activation-before-plan (G5); CB-185 v1 (K3/K4); prose CB-186 (L2–L7); prose CB-187 `…-EXACT-FACE-CUT-READER`, v1–v5, S5 STOP (P2–P7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB176 execution report](Architecture_M6_CP3_TB176_P13_Piece_Builder_And_Ordered_Retrace_Full_Gate_Execution_Report_20261123.md), [CB-197B Code + Build record](Architecture_M6_CP3_CB197B_P13_Exact_Source_Retrace_Ordered_Stretches_Code_Build_Record_20261123.md), [TB-REV-175 adversarial](Architecture_M6_CP3_TB_REV_175_Adversarial_Review_20261123.md), [CB-197A/B manifest](gates/Architecture_M6_CP3_CB197AB_P13_Exact_Manifest.md), [TB175 execution report](Architecture_M6_CP3_TB175_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261123.md), [CB-196 Code + Build record](Architecture_M6_CP3_CB196_P13_Exact_Source_Retraced_Trace_Selection_Code_Build_Record_20261123.md), [TB174 execution report](Architecture_M6_CP3_TB174_P13_Retrace_Oracle_Full_Gate_Execution_Report_20261123.md), [CB-195 Code + Build evidence](Architecture_M6_CP3_CB195_P13_Exact_Source_Path_Retrace_Along_Edges_Progress_20261123.md), [TB-REV-173 D13 resolution](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md). Older Reviews resolve through [the folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17) and the Turn Sequence links.

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
