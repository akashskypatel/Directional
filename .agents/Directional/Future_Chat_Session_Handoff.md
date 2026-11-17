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
| Currency | 2026-11-17 UTC, RA-245; [independent TB126 Review](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md). |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD before work. CB144 product/test source `7b0668d432ccb187c5a2d856494064f0bcb2fb95`, package `14293047782`; [compile record](Architecture_M6_CP3_CB144_P13_Edge_Terminal_Owner_Correction_Code_Build_Record_20261117.md). |
| Scoped runtime reference | [TB125](Architecture_M6_CP3_TB125_P13_Edge_Terminal_Exact_Inventory_Execution_Report_20261117.md): 950/950; gate `14289730737`, census `14289927334`. Accepted CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. |
| Latest candidate | [TB126](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Full_Gate_Execution_Report_20261117.md): gate `14294372593`, 950/951; census `14294313207`, Cylinder PASS 288, BunnyRandom and Vase RED. All 950 inherited rows match; row951 invalid test input, not a demonstrated split defect. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C3/O42/O43 open; O44/C1 closed. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | BunnyRandom `RotationSystemInconsistent` / `CellularityNotEstablished`, face `(5,104,359)`; exact rejecting predicate unresolved. No repair before actual evidence. Vase completion RED unchanged. CP3/D0 not accepted. |

## Mandatory next turn — `M6-CP3-CB144B-P13-EDGE-TERMINAL-GUARD-EXTENT-CORRECTION` — EXACT NEXT

Until root [STATUS](../../STATUS) records COMPLETE for `M6-CP3-TB126-P13-EDGE-TERMINAL-CORRECTION-FULL-GATE-REV`, resume that Review only. No successor execution is authorized within it.

- **Type / owner:** Code + Build, test-only, per [RA-245](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md) and [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) §5.
- **Objective:** Correct the invalid typed trace-ID extent in the new row951 test. Preserve every assertion and identity. No product behavior change.
- **In scope:** Apply exactly [frozen 19-line diff](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Exact.diff), SHA-256 `20aeaf0d6e999c12d634f7c505418628add662b4484fdfa6dddaa63c3b1ed4ae`, only `tests/FieldAlignedCurveNetworkTests.cpp`. Check semantic source, preimage hash and exact path; use eight approved GMP/GMPXX targets and durable dispatcher. Compile/package only; record exact source, targets, receipts, immutable package and hash manifest.
- **Out of scope:** No runtime, fixture, product, benchmark, selector, manifest, assertion or policy edit; no CB145, MATCH-only DEFN, rotation repair, acceptance promotion, or speculative implementation.
- **On success:** A separate immutable gate/census TB is conditional; require a canonical ID from its authorized plan, not an invented one. RA-245 specifies 951/951, membership 1,032, zero skips, identical inherited semantic rows and meaningful receipts. Do not run it in CB144B.
- **On failure:** Stop on any mismatch; use RA-245's evidence and routing. Retry legitimate transport/orchestration failures only. Unknown successor ID means stop for authorization.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| 1 — next after Review COMPLETE | `M6-CP3-CB144B-P13-EDGE-TERMINAL-GUARD-EXTENT-CORRECTION` | Exact test-only compile and immutable package; no runtime. |
| 2 — conditional | UNKNOWN | Separate corrected full gate and census per RA-245 after successful build, followed by independent Review. |

No additional turn is authorized here.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: Code + Build only after root STATUS records this Review complete. Use the turn-appropriate skill and read all mandatory policies first.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff and [RA-245](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) §5, [CB144](Architecture_M6_CP3_CB144_P13_Edge_Terminal_Owner_Correction_Code_Build_Record_20261117.md), [TB126](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Full_Gate_Execution_Report_20261117.md) and [TB125](Architecture_M6_CP3_TB125_P13_Edge_Terminal_Exact_Inventory_Execution_Report_20261117.md); verify the [exact diff](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Exact.diff) and committed manifests.
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
