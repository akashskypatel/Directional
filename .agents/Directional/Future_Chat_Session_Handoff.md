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
| Currency | 2026-11-24 UTC. **TB-REV-181 accepts TB181 1003/1003; K6 closed.** TB170 recurrence closed at seven-control boundary. [Independent review](Architecture_M6_CP3_TB_REV_181_Region_Corner_Ownership_Independent_Review_20261124.md). |
| Branch / source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; exact CB-201 source `b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3`, GMP/GMPXX [run 45488907549](https://github.com/akashskypatel/Directional/actions/runs/45488907549), package `14966635283` SHA-256 `fbad076e0d30e099ece6e197191f7a5ec98016a8713a286a4a391ede0cdb644a`, 28/28 hashes, eight targets, `runtimeExecution=false`. [Code + Build record](Architecture_M6_CP3_CB201_P13_Exact_Trace_Segment_Namespace_Code_Build_Record_20261124.md). |
| Current TB evidence | TB181 [run 45492294397](https://github.com/akashskypatel/Directional/actions/runs/45492294397), result `14967943314` ZIP SHA-256 `877efb75d3ed801aab7fdc9931356254155162a114d9fc36a2f680f02ec9fa6b`, 2014/2014 checks, 1003/1003 PASS, 607 exact + 393 N1/N2 + 3 N3 (164/172/176), zero material differences. [TB181 report](Architecture_M6_CP3_TB181_P13_Trace_Segment_Namespace_Full_Gate_Execution_Report_20261124.md). |
| Accepted comparison | TB181 result `14967943314`, package `14966635283`, 1003/1003 accepted. TB180 result `14951803089` is historical comparison authority. Manifest `2928fd3181eb06e635c0b88527550cddc7ff602b95b757ebd8d569e699e2f724`; historic TB169 prefix `82581dd14064efe3729923cfd94333ef70113b0bb84e6bb8eabfb2ec61cce436`; CP2 491/491 prefix `483f11016d1f51049921aed879c2b23f523d045efc1a2833889a12bb9852a038`. TB169 remains historical authority. |
| Regression / debt | TB170 mechanical recurrence closed: controls 445/652/653/656/658/660/786 PASS; no new accepted-green loss. Historical 67 events / 17 categories / 50 recurrences; witness debt1/deferred81. J6 production contact case not exercised. K6 namespace correction independently accepted. |
| First unresolved failure | Row979 staged `RegionContainsInteriorSingularity` (vertex8 = node1, 5 arc ends) **unclassified**: candidate P1 face-granular singularity reach vs fragment regions ([TB-REV-180 adv.](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-181-folded-records--2026-11-24-utc) N2–N4). |

## Mandatory next turn

- **COMPLETE:** [TB-REV-181 independent review](Architecture_M6_CP3_TB_REV_181_Region_Corner_Ownership_Independent_Review_20261124.md): TB181 accepted, K6 closed, row979 remains unclassified.
- **COMPLETE:** [TB-REV-181 adversarial](Architecture_M6_CP3_TB_REV_181_Adversarial_Review_20261124.md): CB-202 upheld unamended — syntax 0 errors/no new warnings (O1); TB181 census: plan codes only in row979 (O2); union branch = bounded debt D-U (O3); certificate digest risk caught by STOP (O4).

```text
NEXT_TURN: M6-CP3-CB-202-P13-REGION-CORNER-SINGULARITY-REACH
Owner: Code + Build only, eight GMP/GMPXX targets, runtimeExecution=false
Authority: gates/Architecture_M6_CP3_CB202_P13_Region_Corner_Singularity_Reach_Exact_Manifest.md; TB-REV-181 independent + Architecture_M6_CP3_TB_REV_181_Adversarial_Review_20261124.md (O1 compile verified, O2 census)
  exact proposed diff Architecture_M6_CP3_CB202_P13_Region_Corner_Singularity_Reach_Exact.diff; SHA-256 26ec484d0434afd3f0376661e945bdbd73d1c9a1fc206e7b589be34bb3ba5332 (25159 B, 3 paths, +297/-105)
  semantic preimage b9d79c4d9e951cab787d3bfdc3b8f20aaf7195c3; GlobalTopologyPlan.cpp 44395316... -> 37b7cd52...; RegionCornerOwnership.h ABSENT -> c5d376fe...; tests af320470... -> 9f08edd7...
  build only; new guard (row1004) and row979 region= receipt frozen
Then: M6-CP3-TB-EXEC-182-P13-REGION-CORNER-SINGULARITY-REACH-FULL-GATE (manifest d778afbe65e181391116a67ada06f4482e9786917ca58dd2a17f7b7459d8ca5f, 1004+81=1085; expect 1004/1004 PASS; vs TB181 14967943314 under N1-N3 only row979 raw receipt + row1004 may differ; no line moves; anything else STOP) -> M6-CP3-TB-REV-182 (classify row979: built -> Branch A activation CB; new error -> one exact receipt/correction; still RegionContainsInteriorSingularity -> A2a node1 + D-U removal)
On failure: preimage/hash mismatch or compile failure -> STATUS BLOCKED, report verbatim, return to Review
Do not: execute runtime, broaden diff, edit row355 or any existing assertion, activate Branch A, promote CP3/497/D0/H4 or repair J6/E5/CB-190
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → … → TB-REV-177 | Adversarial records TB-REV-162…177 (`Architecture_M6_CP3_TB_REV_1NN_Adversarial_Review_*.md`); TB169 993/993 accepted; TB170–TB177 rejected (same 7 RED); D13 = A ([TB-REV-173](Architecture_M6_CP3_TB_REV_173_D13_Resolution_From_Design_20261123.md)). |
| COMPLETE | CB-199A → TB-EXEC-178 (995/1002) → TB-REV-178 → CB-199B → TB-EXEC-179 (1002/1003, six recoveries) → TB-REV-179 | [TB179 report](Architecture_M6_CP3_TB179_P13_Retraced_Trace_Selection_Full_Gate_Execution_Report_20261124.md); reviews linked above. |
| COMPLETE | CB-200 → TB-EXEC-180 → TB-REV-180 | [TB180 report](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-181-folded-records--2026-11-24-utc) 1003/1003; [independent](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-181-folded-records--2026-11-24-utc) + [adversarial](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-181-folded-records--2026-11-24-utc) reviews. |
| COMPLETE | `M6-CP3-CB-201-P13-EXACT-TRACE-SEGMENT-NAMESPACE` | [Build record](Architecture_M6_CP3_CB201_P13_Exact_Trace_Segment_Namespace_Code_Build_Record_20261124.md); compile only. |
| COMPLETE | `M6-CP3-TB-EXEC-181-P13-TRACE-SEGMENT-NAMESPACE-FULL-GATE` | 1003 rows N1–N3-equal to TB180; zero material differences. |
| COMPLETE | `M6-CP3-TB-REV-181` | Independent + [adversarial](Architecture_M6_CP3_TB_REV_181_Adversarial_Review_20261124.md); K6 closed; CB-202 frozen per [TB-REV-180 adv.](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-181-folded-records--2026-11-24-utc) requirements 1–6. |
| **1 NEXT ONLY** | `M6-CP3-CB-202-P13-REGION-CORNER-SINGULARITY-REACH` | [Exact manifest](gates/Architecture_M6_CP3_CB202_P13_Region_Corner_Singularity_Reach_Exact_Manifest.md); compile only. |
| 2 | TB-EXEC-182 | 1004 cases (`d778afbe…a5ca`), only row979 receipt + row1004 may differ under N1–N3; else STOP. |
| 3 | TB-REV-182 | Classify row979 by `region=`/outcome: (a) built → Branch A activation CB (4A); (b) new earliest error → one exact receipt/correction; (c) still interior singularity → A2a node1 + remove D-U ([adv. O3](Architecture_M6_CP3_TB_REV_181_Adversarial_Review_20261124.md)). |
| 4A | Branch A (only after the staged plan builds): activation CB → TB (BunnyRandom census, V5) → parameter-deletion CB → V3b → R1 → O48 | Activation = single-source default (V11) + exact premise rows 393/648/858/971/972/978 only. |
| 5 | CB-190 | S4/S6/S7 diagnostic conformity plus W6 obsolete-code comments (off critical path). |
| Withdrawn | prose CB-200 plan + C4 assertion (TB-REV-179 adv. M2); CB-199A `4f458361…` (TB-REV-177 adv. J4); prose CB-198 (176 H1); prose CB-197A/196/195/193/187/186/183/180/178/175/173, CB-194, CB-191, DEFN-161A/159A, CB-185 v1, activation-before-plan — see TB-REV-162…177 adversarial records | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [Exact CB-202 manifest](gates/Architecture_M6_CP3_CB202_P13_Region_Corner_Singularity_Reach_Exact_Manifest.md), [TB-REV-181](Architecture_M6_CP3_TB_REV_181_Region_Corner_Ownership_Independent_Review_20261124.md), [TB181 execution report](Architecture_M6_CP3_TB181_P13_Trace_Segment_Namespace_Full_Gate_Execution_Report_20261124.md), [CB201 compile record](Architecture_M6_CP3_CB201_P13_Exact_Trace_Segment_Namespace_Code_Build_Record_20261124.md), [TB182 frozen case manifest](gates/Architecture_M6_TB182_P13_Region_Corner_Singularity_Reach_Full_Gate_Case_Manifest.tsv), [TB180 requirements and earlier records](M6_Consolidated_Record_Vol_D3_CP3_P13_from_20261109.md#tb-rev-181-folded-records--2026-11-24-utc), [LESSONS.md](LESSONS.md). Historical evidence resolves through the folded index and Turn Sequence.

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
