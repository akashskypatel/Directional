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
| Currency | 2026-11-17 UTC, RA-247 adversarial re-review of TB127-REV (appended to its record); [TB127 execution](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Full_Gate_Execution_Report_20261117.md): gate MATCH, combined MISMATCH under [RA-246 §5](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md#5-tb127-frozen). [TB127 independent Review](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md): comparison discrepancy independently adjudicated; historical MISMATCH upheld. |
| Branch and source | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify HEAD before work. CB146 source `48e6f97d278b2226036f658ce9060a38b8a374b5`, package `14301616031`; [compile record](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Code_Build_Record_20261117.md). CB144 product source unchanged; CB144B and CB146 test-only changes both included. |
| Accepted evidence | [TB125](Architecture_M6_CP3_TB125_P13_Edge_Terminal_Exact_Inventory_Execution_Report_20261117.md) scoped 950/950; artifacts `14289730737`/`14289927334`. Accepted CP2 491/491, package `11391685901`; 497 CP3 identities frozen, not promoted. |
| Latest candidate | [TB127](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Full_Gate_Execution_Report_20261117.md): gate `14302887671`, 951/951 PASS; all 950 inherited records match [TB126](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Full_Gate_Execution_Report_20261117.md). Census `14302668940`: Cylinder PASS 288, BunnyRandom and Vase RED unchanged. Four assertion line numbers shift +61; remaining allowed-normalized lines and terminal prefixes match. RA-246 does not authorize line-number normalization. |
| Regression and debt | Stable 66/17/49, one produced-witness debt, 81 deferred. [Tracker](Regression_Root_Cause_Tracker.md). C5/O42/O43 open; narrow C3/O44/C1 closed. Middle-piece rotation witness remains open. D11=A, D12=A; D10 deferred, D6 pending. `chainRimSchedules=false`. |
| Active boundary | BunnyRandom `RotationSystemInconsistent` / `CellularityNotEstablished`, face `(5,104,359)` (candidate C5). Verbatim suffix: `rotationReason=TraceEventPositionInvalid trace=0 eventIndex=18 eventPositionReason=NoCarrierMatch eventPositionPass=SourceEdgeUnavailable`. The exact no-edge non-origin/non-terminal rejection is in trace_event_position, before ray ordering. Actual event kind/node/point and struck segment are not published; no product fix is frozen. Vase completion RED unchanged. CP3/D0 not accepted. |

## Mandatory next turn — `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` — EXACT NEXT

Until root [STATUS](../../STATUS) records COMPLETE for `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV`, resume that Review closeout only. Do not start the successor in the current turn.

- **Type / owner:** Definition Review, runtime-free; authorized by [TB127 independent Review](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md), not by retroactively declaring TB127 MATCH.
- **Objective (realigned by RA-247):** Define the face-interior contact node in A2a′.
  - **Established, do not reopen:**
    - Event 18 is a trace–trace contact inside face `(5,104,359)`, involving trace 0, whose two segments share no carrier edge (G1).
    - Every node consumer assumes a vertex or an edge locus: position, `NodeLocus`, rotation, and ten arc-range consumers (G2).
    - The common-carrier rule is a proxy (G3, O45).
    - No user decision is needed; DESIGN Amendments 13 and 14 already require this (G5).
  - **No runtime observation is needed.**
- **Required outputs ([RA-247 §3](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md#owner-requested-adversarial-re-review-ra-247-2026-11-17-utc)):**
  1. The representation: face locus plus exact point, an interior `TraceCut`, and a shared segment index with exact partial paths.
  2. An audit of all ten range consumers.
  3. An exact ray-order rule at face nodes.
  4. A fixture or hand-built network that reaches the face-interior branch.
  5. CB147 frozen as an exact diff, and the CB148, CB149 and TB128 contents fixed.
  6. A plan for the middle-piece direction witness.
- **Stop rule:** if a range consumer would need a new DESIGN contract to share a segment index, stop and name the decision.
- **Out of scope:** no compile, runtime, source/test/fixture/manifest change, CB145, promotion, change to the common-carrier proxy (O45), or validator relaxation.

## Turn Sequence

| Step | Canonical turn | Boundary |
|---|---|---|
| COMPLETE | `M6-CP3-TB127-P13-GUARD-AND-ROTATION-LOCUS-FULL-GATE-REV` | Independent Review; frozen comparison MISMATCH upheld, non-semantic discrepancy established. |
| COMPLETE | RA-247 adversarial re-review of TB127-REV | Upheld MISMATCH, narrow C3 and the C5 site; decided event 18's class from source; widened the DEFN to all node-locus consumers. |
| NEXT | `M6-CP3-DEFN-P13-EDGE-TERMINAL-CORRECTION-OUTCOME` | Definition Review only: face-interior contact node contract, freezes CB147 (RA-247 §3). |
| then | `M6-CP3-CB147-P13-FACE-CONTACT-EXACT-HELPERS` | Code + Build: pure exact helpers, not wired, with unit tests. First implementation-agent turn. |
| then | `M6-CP3-CB148-P13-FACE-NODE-LOCUS-AND-INTERIOR-CUT` | Code + Build: representation plus consumer updates, not wired, with an equal-product test. |
| then | `M6-CP3-CB149-P13-FACE-CONTACT-SWITCH` | Code + Build: contacts with no common carrier go through the face-node path, with a reaching unit test. |
| then | `M6-CP3-TB128-P13-FACE-CONTACT-FULL-GATE-EXEC` | Test + Benchmark: gate unchanged by construction; census BunnyRandom moves past C5. |
| then | Outcome Review | Closes C5, or classifies the next terminal. |
| parked | `M6-CP3-CB145-P13-VERTEX-FOLLOW-BOUNDARY` | C4 and exact grazing; not next. |
| parked | O45 common-carrier conformance switch | Amendment 13 debt; staged later, not blocking. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: Definition Review only after root STATUS records TB127 independent Review complete. Use `references/turns/REVIEW.md` and read all mandatory policies first.

0. [ORIENTATION.md](ORIENTATION.md) — project context, read first.
1. [ROADMAP.md](ROADMAP.md) — milestone position only.
2. This handoff, [TB127 independent Review](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Independent_Review_20261117.md), [TB127](Architecture_M6_CP3_TB127_P13_Guard_And_Rotation_Locus_Full_Gate_Execution_Report_20261117.md), [CB146](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Code_Build_Record_20261117.md), [CB144B](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Code_Build_Record_20261117.md) and [RA-245](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Independent_Review_20261117.md), [RA-244](Architecture_M6_CP3_DEFN_P13_Edge_Terminal_Equivalence_Decision_Review_20261117.md) §5, [CB144](Architecture_M6_CP3_CB144_P13_Edge_Terminal_Owner_Correction_Code_Build_Record_20261117.md), [TB126](Architecture_M6_CP3_TB126_P13_Edge_Terminal_Correction_Full_Gate_Execution_Report_20261117.md) and [TB125](Architecture_M6_CP3_TB125_P13_Edge_Terminal_Exact_Inventory_Execution_Report_20261117.md); verify the [exact diff](Architecture_M6_CP3_CB144B_P13_Edge_Terminal_Guard_Extent_Exact.diff), the [CB146 diff](Architecture_M6_CP3_CB146_P13_Rotation_Terminal_Locus_Print_Exact.diff) (RA-246 §4) and the committed manifests.
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
