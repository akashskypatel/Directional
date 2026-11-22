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
| Currency | 2026-11-22 UTC. [TB-REV-165 review](Architecture_M6_CP3_TB_REV_165_Nearest_Chord_Seed_Full_Gate_Review_20261122.md) (G1–G5) resolves the TB165 rule-3 STOP. The fault was my oracle: Established=0, not 2, and the 21 extra lines are seeds that agree with already-established components. The CB-183/CB-184 nearest-chord seed is accepted: 192/192 established, `sourceFaceCellularity=1`. The staged plan now stops at `SourceFaceCarriesMultipleTraceCuts`, face `6-8-9`, arc 1. No production or selector promotion. |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-184 source `5b5cdf15a670236635d74a15f3791422b182ffe0`, compile run `45039218665`, package `14760674864`, ZIP `e1717c59…bec3`, GMP/GMPXX ([record](Architecture_M6_CP3_CB184_P13_Nearest_Chord_Seed_Switch_Code_Build_Record_20261122.md)). |
| Current gate / census | [TB165](Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Full_Gate_Execution_Report_20261122.md): full run `45041398551`, result `14762295772` (`67b5e27d…bc92d5`), 984/984, CP2 491/491, membership 1065; census run `45041524093`, result `14762602145` (`892bd5cc…fc1b`), 3/3 unchanged. [Raw receipt](evidence/Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Raw_20261122.txt). |
| Accepted history | CP2 491/491, package `11391685901`. CP3's 497 identities are frozen and unpromoted. |
| Regression/debt | TB165-F1 is reclassified as a defective review oracle. Z6 is closed (G1). Open or carried: G2/G3, the plan corner reader's one-cut-per-face assumption (RA-275 S4a site, owner CB-185 → TB-REV-166); Y7 narrowed by Z3; Z5 (disc fixtures); X4/H5 elsewhere; TB-REV-159-U3/V3–V11; W3/W4/W6/W7; RA-281 F1–F3; Amendment 14; O47/C5/O48/O49; sphere χ+4. Stable 66/17/49, debt1, deferred81. |
| Active boundary | The production sphere still stops at `CutSearchExhaustedBeforeCellularity`. The staged row-979 plan stops at `SourceFaceCarriesMultipleTraceCuts`, `6-8-9`: a singular corner (node 1) with rays from traces 3 and 4, slide arrivals from traces 0 and 9, and trace 0's segment 6 split at node 12 into arcs 0 and 1. Activation is held until the staged plan builds (G5). |

## Mandatory next turn

- **Authority:** [TB-REV-165 review](Architecture_M6_CP3_TB_REV_165_Nearest_Chord_Seed_Full_Gate_Review_20261122.md) G1–G5.
- **NEXT:** `M6-CP3-CB-185-P13-STAGED-MULTI-CUT-FACE-RECEIPT` (Code + Build, compile only).
  - Apply exactly the [CB-185 diff](Architecture_M6_CP3_CB185_P13_Staged_Multi_Cut_Face_Receipt_Exact.diff) `77e025a8…159d`: test-only, +81/−0, row-979 `SphereStagedMultiCutVisit` / `SphereStagedMultiCutFaces`.
  - Test `fea486ed…68e27` → `d417d635e1bcd887d4f3eefce27513464ff6e316c38525e26ed41e76ad960e0d`.
- **Then:** `M6-CP3-TB-EXEC-166-P13-STAGED-MULTI-CUT-FACE-RECEIPT-FULL-GATE`.
  - Run the TB165 manifest `8d56ee1d…1e69` (984 rows), no census.
  - Apply rules 1–6 from the review.
  - Predicted: face `6-8-9` with arcs 0/1/5/6/12, and all 16 component-1/5 opposite faces with at least two visits.
- **Then:** `M6-CP3-TB-REV-166-…`, which freezes the corner-partition helper CB-186 and the reader switch CB-187.
- **On failure:** a hash mismatch or compile failure means STATUS BLOCKED and a return to Review. Never edit beyond the diff, change product source, run tests in a CB, or change selectors or manifests.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → TB-EXEC/REV-162 → CB-180 → TB-EXEC/REV-163 | [TB-REV-162 adv.](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md); [TB-REV-163 adv.](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md) (Y1–Y7). |
| COMPLETE | CB-181 → CB-182 → TB-EXEC/REV-164 | [TB164](Architecture_M6_CP3_TB164_P13_Third_Edge_Side_Owner_Census_Full_Gate_Execution_Report_20261122.md); [TB-REV-164 adv.](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md) (Z1–Z6). |
| COMPLETE | CB-183 → CB-184 → TB-EXEC-165 (STOP) → TB-REV-165 | [CB-183](Architecture_M6_CP3_CB183_P13_Nearest_Chord_Seed_Decision_Helper_Code_Build_Record_20261122.md); [CB-184](Architecture_M6_CP3_CB184_P13_Nearest_Chord_Seed_Switch_Code_Build_Record_20261122.md); [TB165](Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Full_Gate_Execution_Report_20261122.md); [TB-REV-165 review](Architecture_M6_CP3_TB_REV_165_Nearest_Chord_Seed_Full_Gate_Review_20261122.md) accepts the seed switch. |
| **NEXT (Code + Build)** | `M6-CP3-CB-185-P13-STAGED-MULTI-CUT-FACE-RECEIPT` | Exact test-only receipt; compile only. |
| Then (Test + Benchmark) | `M6-CP3-TB-EXEC-166-P13-STAGED-MULTI-CUT-FACE-RECEIPT-FULL-GATE` | 984 rows; row-979 receipt; no census. |
| Then (Review) | `M6-CP3-TB-REV-166-P13-STAGED-MULTI-CUT-FACE-RECEIPT-FULL-GATE` | Classify faces; freeze CB-186 helper + CB-187 switch. |
| Prospective | CB-186 → CB-187 → TB-EXEC/REV-167 (staged plan built) → CB-188 activation (V3–V5, V10, V11) → TB-EXEC/REV-168 → CB-189 V3b → R1 → O48 | O49 off the switch path. |
| Withdrawn | prose CB-180 (X2); DEFN-161A (W3); prose CB-178 activation (V2); DEFN-159A (U1); prose CB-175; CB-174 v3 helper; CB-172A; prose CB-173; old CB-181/CB-182 wiring plan (Y1); prose CB-183 (Z1); activation-before-plan order (G5) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB165 execution STOP](Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Full_Gate_Execution_Report_20261122.md), [TB165 verbatim row979](evidence/Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Raw_20261122.txt), [TB-REV-164 independent review](Architecture_M6_CP3_TB_REV_164_Third_Edge_Side_Owner_Census_Independent_Review_20261122.md), [TB164 execution report](Architecture_M6_CP3_TB164_P13_Third_Edge_Side_Owner_Census_Full_Gate_Execution_Report_20261122.md), [TB164 raw 16-line receipt](evidence/Architecture_M6_CP3_TB164_P13_Third_Edge_Side_Owner_Census_Raw_20261122.txt), [TB-REV-163 adversarial decision](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md), [CB-182 record](Architecture_M6_CP3_CB182_P13_Third_Edge_Side_Owner_Census_Code_Build_Record_20261122.md), [TB163 report](Architecture_M6_CP3_TB163_P13_Staged_Uncut_Owner_Census_Receipt_Full_Gate_Execution_Report_20261122.md), [TB161 census comparison reference](Architecture_M6_CP3_TB161_P13_Staged_Slide_Entry_Stop_Downstream_Receipt_Full_Gate_Execution_Report_20261122.md), [TB-REV-163 independent review](Architecture_M6_CP3_TB_REV_163_Staged_Uncut_Owner_Census_Receipt_Independent_Review_20261122.md).

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
