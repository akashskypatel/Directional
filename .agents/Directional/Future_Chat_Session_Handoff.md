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
| Currency | 2026-11-17 UTC, CB146 compile-only success; RA-245 + RA-246 (same record, §RA-246); [independent TB126 Review](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md). |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD before work. CB146 source `48e6f97d278b2226036f658ce9060a38b8a374b5`, package `14301616031`; [compile record](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Code_Build_Record_20261117.md). CB144 product source unchanged; CB144B and CB146 test-only changes both included. |
| Scoped runtime reference | [TB125](Architecture_M6_CP3_TB125_P13_Edge_Terminal_Exact_Inventory_Execution_Report_20261117.md): 950/950; gate `14289730737`, census `14289927334`. Accepted CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. |
| Latest candidate | [TB126](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Full_Gate_Execution_Report_20261117.md): gate `14294372593`, 950/951; census `14294313207`, Cylinder PASS 288, BunnyRandom and Vase RED. All 950 inherited rows match; row951 invalid test input, not a demonstrated split defect. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C3/O42/O43 open; O44/C1 closed. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | BunnyRandom `RotationSystemInconsistent` / `CellularityNotEstablished`, face `(5,104,359)` (candidate C5). RA-246 F3: the face-only locus excludes every edge-locus site, and CB144's changes reach none of the face-only sites, so this is a pre-existing defect that CB144 exposed, not one it caused. The exact site is unresolved; CB146 compiled the formatter for the already-published typed fields; TB127 must record them. No repair before that evidence. Vase completion RED unchanged. CP3/D0 not accepted. |


## Mandatory next turn — `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-EXEC` — EXACT NEXT

Until root [STATUS](../../STATUS) records COMPLETE for `M6-CP3-CB146-P13-ROTATION-TERMINAL-LOCUS-PRINT`, resume CB146 closeout only. No successor execution is authorized within it.

- **Type / owner:** Test + Benchmark, immutable artifact execution only, per [RA-246 §5](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md#5-tb127-frozen).
- **Objective:** Verify the corrected guard and print the existing BunnyRandom rotation terminal reason without changing prior census content.
- **In scope:** CB146 package `14301616031` at `48e6f97d278b2226036f658ce9060a38b8a374b5`, gate manifest `44d5a734a819a6d353bf3cb83254af86939e017dbd3a6dc3313d71f814ffdd1f` (951 rows, membership 1,032), census `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`. Require 951/951 PASS, 0 skipped, valid postflight; inherited ledger and raw log equivalence as specified by RA-246 §5. Census matches TB126 after approved normalization except `terminal=` text must retain TB126 as exact prefix. Cylinder PASS 288, Vase RED unchanged, BunnyRandom RED unchanged prefix and four inventory lines, nonempty ` rotationReason=`. Record suffix verbatim.
- **Out of scope:** No compile/relink/configure, source/test/fixture/selector/manifest change, CB145, rotation repair or promotion.
- **On MATCH:** Review-only `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` per RA-246 §6.
- **On mismatch:** `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV`; infrastructure: `M6-CP3-TB127A-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-ORCH`.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| 0 | `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-REV` (RA-245 + RA-246) | Review — COMPLETE. |
| 1 — COMPLETE | `M6-CP3-CB144B-P13-EDGE-TERMINAL-GUARD-EXTENT-CORRECTION` | Exact test-only compile and immutable package verified; no runtime. |
| 2 — COMPLETE | `M6-CP3-CB146-P13-ROTATION-TERMINAL-LOCUS-PRINT` | Exact test-only compile; [record](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Code_Build_Record_20261117.md), package `14301616031` verified; no runtime. |
| 3 — NEXT | `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-EXEC` | CB146 package; gate manifest `44d5a734…` (951 rows, membership 1,032); census `3af1dc0d…`. MATCH per RA-246 §5: 951/951 PASS; rows 1–950 equal to TB126; census lines equal to TB126 except that each `terminal=` line extends its TB126 text as a prefix; BunnyRandom has a non-empty `rotationReason=`. Mismatch → `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV`; infrastructure → `M6-CP3-TB127A-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-ORCH`. |
| 4 | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` | Review only: close C3, classify C5 by the printed reason, freeze the next narrow CB and the rotation-level middle-piece direction test (RA-246 §6). |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | After 4. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: Test + Benchmark only after root STATUS records CB146 complete. Use the turn-appropriate skill and read all mandatory policies first.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [CB146](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Code_Build_Record_20261117.md), [CB144B](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Code_Build_Record_20261117.md) and [RA-245](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) §5, [CB144](Architecture_M6_CP3_CB144_P13_Edge_Terminal_Owner_Correction_Code_Build_Record_20261117.md), [TB126](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Full_Gate_Execution_Report_20261117.md) and [TB125](Architecture_M6_CP3_TB125_P13_Edge_Terminal_Exact_Inventory_Execution_Report_20261117.md); verify the [exact diff](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Exact.diff), the [CB146 diff](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Exact.diff) (RA-246 §4) and the committed manifests.
3. [Architecture_M6_Frozen_Definitions.md](Architecture_M6_Frozen_Definitions.md) and [DESIGN.md](DESIGN.md) for normative constraints; [tracker](Regression_Root_Cause_Tracker.md) and [TODO](../../TODO.md) for unresolved issues and authorized scope.
4. [Historical record index](M6_Consolidated_Record.md#tb126-review-folded-record-index-2026-11-17) resolves superseded filenames; old turn ladders and navigation preimages are history only, not instructions. The CB84 Linux Vase diagnostic timing attempt, CB121A 16-row fan-resolver plan and CB102 remain withdrawn. Reviews remain runtime-free; no deprecated scratch-build authorization. D6 remains pending and the chain switch remains off.

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
