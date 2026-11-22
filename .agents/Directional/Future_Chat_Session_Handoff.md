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
| Currency | 2026-11-22 UTC. [TB166 immutable full gate](Architecture_M6_CP3_TB166_P13_Staged_Multi_Cut_Face_Receipt_Full_Gate_Execution_Report_20261122.md) **984/984 PASS**, CP2 **491/491**, 1065 membership, 179 exact new row979 lines. All six frozen rules pass. Staged plan still stops at `SourceFaceCarriesMultipleTraceCuts` face `6-8-9`, while production sphere still rejects cut search. [TB-REV-166](Architecture_M6_CP3_TB_REV_166_Staged_Multi_Cut_Face_Receipt_Independent_Review_20261122.md) independently discharged the specific K5 edge-supported overlap on the 24 recorded departures; no edge-supported port was present. G2/G3 and plan reader remain open. No CP3/497/D0/H4 or production promotion. |
| Branch and latest compiled package | `agent/surface_cell_quad/p5-recover-bridge-healing`. CB-185 exact source `2c1ec9ab370ed0e9d533d7694e03b486916b9b1a`, compile run `45050530173`, package `14765117630`, ZIP `288b8a7c1571…7056548d`, GMP/GMPXX ([record](Architecture_M6_CP3_CB185_P13_Staged_Multi_Cut_Face_Receipt_Code_Build_Record_20261122.md)). |
| Current gate / census | [TB166](Architecture_M6_CP3_TB166_P13_Staged_Multi_Cut_Face_Receipt_Full_Gate_Execution_Report_20261122.md): [run 45052316075](https://github.com/akashskypatel/Directional/actions/runs/45052316075), result `14765434765` (`9826a921…f044`), 984/984, CP2 491/491, membership 1065, 983 previous rows N1–N3 match, [179-line raw receipt](evidence/Architecture_M6_CP3_TB166_P13_Staged_Multi_Cut_Face_Receipt_Raw_20261122.txt). **No census in TB166.** Latest prior three-case census remains [TB165](Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Full_Gate_Execution_Report_20261122.md) 3/3 unchanged. |
| Accepted history | CP2 491/491, package `11391685901`. CP3's 497 identities are frozen and unpromoted. |
| Regression/debt | No new TB166 regression. TB165-F1 remains classified as defective review oracle. Z6 is closed (G1). Open or carried: K5 discharged for this witness; G2/G3 and plan corner reader one-cut-per-face assumption (RA-275 S4a); Y7 narrowed by Z3; Z5 disc fixtures; X4/H5; TB-REV-159-U3/V3–V11; W3/W4/W6/W7; RA-281 F1–F3; Amendment 14; O47/C5/O48/O49; sphere χ+4. Stable 66/17/49, debt1, deferred81. |
| Active boundary | The production sphere still stops at `CutSearchExhaustedBeforeCellularity`. The staged row-979 plan stops at `SourceFaceCarriesMultipleTraceCuts`, `6-8-9`: a singular corner (node 1) with rays from traces 3 and 4, slide arrivals from traces 0 and 9, and trace 0's segment 6 split at node 12 into arcs 0 and 1. Activation is held until the staged plan builds (G5). |

## Mandatory next turn

- **Authority:** [TB-REV-166 adversarial continuation](Architecture_M6_CP3_TB_REV_166_Adversarial_Review_20261122.md) (L1–L8), which upholds TB166 and the K5 discharge of the [independent review](Architecture_M6_CP3_TB_REV_166_Staged_Multi_Cut_Face_Receipt_Independent_Review_20261122.md) and **withdraws its prose CB-186** (not exact; would reject interior ends, ties at singular corners and corner-free strips on the sphere witness itself).
- **NEXT:** `M6-CP3-CB-186-P13-FACE-CUT-CORNER-PARTITION-HELPER` (Code + Build, compile only). Apply exactly `Architecture_M6_CP3_CB186_P13_Face_Cut_Corner_Partition_Helper_Exact.diff`, SHA-256 `a89c7a9ce54bfea2f893868550fe5250e4bf4aaa5f3db72da0951cd8a01eb4b7`. It adds the pure, unwired `src/geometry/FaceCutCornerPartition.h` (`cea68118…ce4e`) and five `FaceCutCornerPartition.*` tests (test file `c62c51b0…ffe2` → `8ccfc38b…1e24`). GMP/GMPXX dispatcher compile, runtimeExecution=false.
  - Then `M6-CP3-TB-EXEC-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE` with manifest `gates/Architecture_M6_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Case_Manifest.tsv` (`5c084199…8c50`, 989 rows). Rules:
    - 989/989 PASS; membership 1070;
    - rows 1–984 equal TB166 `14765434765` under N1–N3, with zero allowance;
    - no census.
  - Then `M6-CP3-TB-REV-167-…` freezes an exact CB-187 reader switch: arc-own face pieces with node-locus ends, every fragment orbit keyed, typed failures.
  - Preserve CP2 491/491, stable 66/17/49, debt1, deferred81 and 497/CP3/D0/H4 unpromoted. The production sphere still fails closed.

```
NEXT_TURN: M6-CP3-CB-186-P13-FACE-CUT-CORNER-PARTITION-HELPER
Owner: implementation agent (Code + Build, compile only)
Authority: .agents/Directional/Architecture_M6_CP3_TB_REV_166_Adversarial_Review_20261122.md (L1–L8); supersedes the prose CB-186 in the TB-REV-166 independent review
Apply exactly: .agents/Directional/Architecture_M6_CP3_CB186_P13_Face_Cut_Corner_Partition_Helper_Exact.diff
  SHA-256 a89c7a9ce54bfea2f893868550fe5250e4bf4aaa5f3db72da0951cd8a01eb4b7 (+400/−0)
  new src/geometry/FaceCutCornerPartition.h -> cea681185d69a83001999360ea37d173b6780c2a7ed3adac3caa42e49016ce4e (pure, unwired)
  tests/FieldAlignedCurveNetworkTests.cpp: c62c51b0…ffe2 -> 8ccfc38b237322e65962644593a81308142bee9f963ab3330784c094a98c1e24
Build: dispatcher compile, GMP/GMPXX targets incl. directional_surface_cell_producer_tests, runtimeExecution=false
Then: M6-CP3-TB-EXEC-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE
  manifest .agents/Directional/gates/Architecture_M6_TB167_P13_Face_Cut_Corner_Partition_Helper_Full_Gate_Case_Manifest.tsv (5c0841993d9b9c5537a3b78a3f7df39e61ee82e09b1ce9b4be3f4510ff088c50, 989 rows)
  rules: 989/989 PASS; CP2 491/491; membership 1070; rows 1–984 = TB166 result 14765434765 under N1–N3 (row 979 included), zero allowance; rows 985–989 PASS; no census
  -> M6-CP3-TB-REV-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE (freeze exact CB-187 reader switch)
On failure/blocker: hash mismatch, compile failure or any helper-test failure -> STATUS BLOCKED, report verbatim, return to Review
Do not: edit beyond the diff; wire the helper; change build_fragment_corner_incidence; edit tests to pass; change other selectors/manifests; activate; promote CP3/497/D0/H4
```

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | TB128–TB-REV-161, RA-250–RA-281, CB150–CB-178 | [Folded index](M6_Consolidated_Record.md#tb128-review-folded-execution-record-index-2026-11-17); adversarial records TB-REV-157 to TB-REV-161. |
| COMPLETE | CB-179 → TB-EXEC/REV-162 → CB-180 → TB-EXEC/REV-163 | [TB-REV-162 adv.](Architecture_M6_CP3_TB_REV_162_Adversarial_Review_20261122.md); [TB-REV-163 adv.](Architecture_M6_CP3_TB_REV_163_Adversarial_Review_20261122.md) (Y1–Y7). |
| COMPLETE | CB-181 → CB-182 → TB-EXEC/REV-164 | [TB164](Architecture_M6_CP3_TB164_P13_Third_Edge_Side_Owner_Census_Full_Gate_Execution_Report_20261122.md); [TB-REV-164 adv.](Architecture_M6_CP3_TB_REV_164_Adversarial_Review_20261122.md) (Z1–Z6). |
| COMPLETE | CB-183 → CB-184 → TB-EXEC-165 (STOP) → TB-REV-165 (+ [TB-REV-165 adversarial](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md)) | [CB-183](Architecture_M6_CP3_CB183_P13_Nearest_Chord_Seed_Decision_Helper_Code_Build_Record_20261122.md); [CB-184](Architecture_M6_CP3_CB184_P13_Nearest_Chord_Seed_Switch_Code_Build_Record_20261122.md); [TB165](Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Full_Gate_Execution_Report_20261122.md); [TB-REV-165 review](Architecture_M6_CP3_TB_REV_165_Nearest_Chord_Seed_Full_Gate_Review_20261122.md) accepts the seed switch. |
| COMPLETE (Code + Build) | `M6-CP3-CB-185-P13-STAGED-MULTI-CUT-FACE-RECEIPT` | Exact v2 test-only receipt (`a7a5922b…935a`); [GMP/GMPXX compiled](Architecture_M6_CP3_CB185_P13_Staged_Multi_Cut_Face_Receipt_Code_Build_Record_20261122.md). |
| COMPLETE (Test + Benchmark) | `M6-CP3-TB-EXEC-166-P13-STAGED-MULTI-CUT-FACE-RECEIPT-FULL-GATE` | [TB166](Architecture_M6_CP3_TB166_P13_Staged_Multi_Cut_Face_Receipt_Full_Gate_Execution_Report_20261122.md): all six frozen rules PASS, no census, no source changes. |
| COMPLETE (Review) | `M6-CP3-TB-REV-166-P13-STAGED-MULTI-CUT-FACE-RECEIPT-FULL-GATE` | [Independent K5 decision](Architecture_M6_CP3_TB_REV_166_Staged_Multi_Cut_Face_Receipt_Independent_Review_20261122.md) + [adversarial continuation](Architecture_M6_CP3_TB_REV_166_Adversarial_Review_20261122.md) (L1–L8): K5 discharge upheld; prose CB-186 withdrawn for an exact diff + 989-row manifest. |
| **1 NEXT (Code + Build)** | `M6-CP3-CB-186-P13-FACE-CUT-CORNER-PARTITION-HELPER` | Exact diff `a89c7a9c…b4b7`: pure unwired helper + 5 tests; compile only. |
| 2 (Test + Benchmark) | `M6-CP3-TB-EXEC-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE` | 989 rows (`5c084199…8c50`); rows 1–984 = TB166 under N1–N3; no census. |
| 3 (Review) | `M6-CP3-TB-REV-167-P13-FACE-CUT-CORNER-PARTITION-HELPER-FULL-GATE` | Freeze exact CB-187 reader switch (Review-only follow-on, RA-219). |
| Prospective | 4 CB-187 → 5 TB-EXEC/REV-168 (staged plan built or next stage) → 6 CB-188 activation (V3–V5, V10, V11) → 7 TB-EXEC/REV-169 → 8 CB-189 V3b → 9 R1 → O48 | O49 off the switch path. |
| Withdrawn | prose CB-180 (X2); DEFN-161A (W3); prose CB-178 activation (V2); DEFN-159A (U1); prose CB-175; CB-174 v3 helper; CB-172A; prose CB-173; old CB-181/CB-182 wiring plan (Y1); prose CB-183 (Z1); activation-before-plan order (G5); CB-185 v1 and per-class corner helpers (K3/K4); prose CB-186 `…-EXACT-BOUNDARY-WALK-…` (L2–L7) | — |
| Held / Parked | `M6-CP3-DEFN-P13-TERMINAL-CUT-OUTCOME`, `…-FACE-CONTACT-OUTCOME` (FC-6), row 858 face DEFN; `M6-CP3-CB-145-P13-VERTEX-FOLLOW-BOUNDARY` | 858 after the sphere repair. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: [TB-REV-166 independent K5 review](Architecture_M6_CP3_TB_REV_166_Staged_Multi_Cut_Face_Receipt_Independent_Review_20261122.md), [TB166 immutable execution](Architecture_M6_CP3_TB166_P13_Staged_Multi_Cut_Face_Receipt_Full_Gate_Execution_Report_20261122.md), [TB166 179-line verbatim receipt](evidence/Architecture_M6_CP3_TB166_P13_Staged_Multi_Cut_Face_Receipt_Raw_20261122.txt), [TB-REV-165 adversarial K1–K6](Architecture_M6_CP3_TB_REV_165_Adversarial_Review_20261122.md), [TB165 execution baseline](Architecture_M6_CP3_TB165_P13_Nearest_Chord_Seed_Full_Gate_Execution_Report_20261122.md), [CB-185 compile record](Architecture_M6_CP3_CB185_P13_Staged_Multi_Cut_Face_Receipt_Code_Build_Record_20261122.md); earlier historical evidence resolves through the consolidated index and prior handoff Git history.

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
