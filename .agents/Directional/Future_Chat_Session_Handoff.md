# Future Chat Session Handoff

> **EXPLICIT USER AUTHORIZATION REQUIRED** to modify or delete this file; unauthorized changes must be reverted during documentation drift audit. This rewrite was expressly requested on 2026-10-16.</br>
> Edits to this document must follow the format laid out in `.agents/Directional/Future_Chat_Session_Handoff_Template.md`.

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
| Currency | 2026-11-03 · **[RA-201](Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md) closes the P13-k Review/Definition by scratch probes.** It resumed from ChatGPT's `REVIEW_BLOCKER`, which was procedural: the DEFN needed scratch execution. P13-k is one class at five instances: a per-query binding check or a per-query BVH, label support or chart graph in the surface-optimizer stage. → DESIGN **Amendment 33**, four exact patches **CB80–CB83**, TB74/TB75/TB76 manifests 888/890/893. With all four, Vase on the scratch build reaches its verdict in **about 250 s** (HEAD: timeout; sites 1–2 only: 1,521 s). The verdict is **P13-l**: the completed mesh fails its pre-optimization validation. Topology passes, but **27,966 interior edges are traversed the same way by both quads**, 7,681 quads oppose the source normal, and 250 self-intersect. Scratch gate 892/893 (only O16 row 283). TB73 886/886, membership 967. CP2 491/491 accepted; selector497/CP3 unpromoted. |
| Working branch / compiled source | `agent/surface_cell_quad/p5-recover-bridge-healing` · **CB79 exact compiled source `3feb2a4182a5a12c2a9f306272756f8333a44b59`, artifact `13261460152`** ([record](Architecture_M6_CP3_CB79_P13_Node_Stitch_Key_Code_Build_Record_20261103.md), `runtimeExecution=false`); predecessor CB78 exact semantic base `afd72107d3213a396ed7f35b53f67dceeea7e7ca`, immutable GMP/GMPXX eight-target compile artifact `13181887585` (28/28 hashes, `runtimeExecution=false`). TB72A exercised this package without rebuild. Earlier CB77/CB76 sources and artifacts remain in their Code + Build records. The prior RA-200 Review changed documentation only; CB79 changed two semantic source/test files. |
| Last accepted semantic runtime | **CP2 491/491**, accepted 2026-10-06; unchanged. TB71 remains unpromoted candidate only. |
| Latest candidate | **TB73** immutable CB79 artifact-only gate **886/886 PASS**, 81 deferred, membership **967**, [run 41702614233](https://github.com/akashskypatel/Directional/actions/runs/41702614233), 1,780/1,780 checksums; independent census [41702722579](https://github.com/akashskypatel/Directional/actions/runs/41702722579) matched Cylinder PASS, BunnyRandom P13-e RED, Vase ABNORMAL 600 s timeout (9/9 hashes). [Report](Architecture_M6_CP3_TB73_P13_Node_Stitch_Key_Full_Gate_Execution_Report_20261103.md). No acceptance promotion. |
| Regression accounting and debt | Accepted CP2 **491/491**; stable **66/17/49**, debt **1**; ledger v5 81 deferred (47 FIXTURE, 7 PRODUCT, 22 OPEN, 5 RETIRE), current membership **967**; selector497 and CP3 unpromoted. DR1/DR3 open, DR2/DR4 to M8-CP2. |
| Active boundary | **Cylinder direct PASS** (it never calls the patch stitcher). **BunnyRandom P13-e** `SingularityPortClassCountMismatch;sourceVertex=49`, separate. **Vase on CB79: P13-k** (ABNORMAL 600 s, inside the surface-optimizer stage), corrected by CB80–CB83 (RA-201). After them the Vase verdict is **P13-l**: `NotProductionReady:completion`, detail `SelfIntersectingFace` (stage `completion/output-validation`, quad 16034, cell 510). The rejecting check is known; the owner is not. Leads: per-quad `orient_quads_to_source_normals`, or mixed patch winding → Review DEFN `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION`. |

## Mandatory next turn — `M6-CP3-CB80-P13-RAIL-BINDING-ONCE` (Code + Build, Linux)

- **[RA-201](Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md)** closes `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` by scratch probes; the [static preflight](Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Static_Preflight_20261103.md)'s requirements are met.
  - **Findings:**
    - The three preflight sites are one class at five instances. Lending the label support alone left Vase in `consistent_source_scope`, because `source_face_scope` ran its O(F) binding check per chart face. `SourcePointLabelSupport::available()` repeats that check on every point query.
    - Vase verdict in about 250 s with all fixes (sites 1–2 only: 1,521 s; HEAD: timeout). The verdict and completed counts are unchanged, so the fixes change cost only.
    - P13-l is named: the pre-optimization validation of the completed mesh. Topology passes. `FlippedFace` occurs 27,966 times in edge form and 7,681 in face form; `SelfIntersectingFace` 250; T-junctions 3. The diagnostics carried the reason, but the terminal dropped it (`detail=None`).
  - **Amendment 33.** The optimizer stage checks the binding once and lends its projection cache and label support by exact inputs.
  - **Exact patches**, one CB per site and each with behaviour and scale GUARD rows: CB80 rail binding, CB81 lent projection cache, CB82 lent label support, CB83 typed terminal detail. They are committed as `.diff` files beside RA-201 and verified as a chain on a clean HEAD worktree.
  - **Scratch verification on the final state:** gate 892/893 (only O16 row 283); every mutant is killed by its row (RA-201.12).
- **Order (implementation agent, one turn each):** CB80 → TB74 → CB81 → TB75 → CB82 → CB83 → TB76. Specs are RA-201.4–.10. TB74 and TB75 register Vase ABNORMAL at 600 s. TB76 registers Vase RED with `detail=SelfIntersectingFace` within 600 s.
- **Review track, can start now:** `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l, on the RA-201 scratch state) and `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e).

### Earlier: RA-200, CB79 and TB73 verified

- **[RA-200](Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md)** closes `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` by scratch probes.
  - **Findings:**
    - At Vase nodes 5351/5355/5356/5357/5359 the stitcher's lineage certificates (support, region 0, sheet 0, literal chart sets) are identical on both sides. Only `boundaryNodeIdentities` differs, because `derive_patch_descriptor` keys a corner by the scope of the halfedge leaving it.
    - This is systemic: 23,221 of 66,783 Vase nodes split, and the HEAD assembly has Euler −19,442.
    - Row 97 was passing on a two-component assembly (O26).
  - **Amendment 32:** the boundary key is the node's identity over all of its occurrences.
  - **Exact CB79 on the scratch build:**
    - gate 885/886 (only O16 row 283), ledger 0/81 unchanged (row 365 = the Vase census, now a timeout past assembly);
    - Cylinder PASS; BunnyRandom unchanged;
    - Vase assembles (Euler 1, one boundary loop), then **P13-k**;
    - mutants M1 and M3 each fail a GUARD row.
- **CB79 COMPLETE:** [Code + Build record](Architecture_M6_CP3_CB79_P13_Node_Stitch_Key_Code_Build_Record_20261103.md); exact source `3feb2a4182a5a12c2a9f306272756f8333a44b59`, 8-target GMP/GMPXX compile run `41693542399`, artifact `13261460152`, `runtimeExecution=false`. **Mandatory next separate turn:** `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-EXEC` (RA-200.5; manifest 886 `5d09fa33…`, membership 967; Vase ABNORMAL 600 s timeout after assembly).
- **TB73 COMPLETE:** [report](Architecture_M6_CP3_TB73_P13_Node_Stitch_Key_Full_Gate_Execution_Report_20261103.md), 886/886 gate, 967 membership, independent census matches all three registered outcomes. **Next separate Review turn:** `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (P13-k, on the CB79 scratch state); P13-e `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` remains parallel.

### Earlier: CB78 and TB72A verified

- **Type / owner (closed by RA-200):** the P13-j Review/Definition, [RA-199.3/6](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md); ChatGPT's 13 same-turn records are superseded as open work by RA-200 (their measured facts stand).
- **Latest immutable evidence:** TB72A corrected [gate run 41540264758](https://github.com/akashskypatel/Directional/actions/runs/41540264758) from immutable CB78 package `13181887585`, source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`: **883/883 PASS**, 81 deferred, membership 964, result artifact `13186997448`, ZIP SHA-256 `5b0d73f2293896afdff831c5902f579843b23ee42e2bef8f8d08177049b213fb`, 1,774/1,774 packaged hashes, `postflight=true`, no configure/compile/relink/benchmark. Independent census [run 41533460744](https://github.com/akashskypatel/Directional/actions/runs/41533460744) registered 1 PASS / 2 expected RED (Cylinder PASS, BunnyRandom P13-e RED vertex49, Vase P13-j RED `AssemblyRejected/NonManifoldStitchedVertex` in 277.58 s). [TB72A record](Architecture_M6_CP3_TB72A_Orchestration_Record_20261102.md) and [TB72 invalid attempt](Architecture_M6_CP3_TB72_Orchestration_Failure_Report_20261102.md) remain separate.
- **Next edge (now resolved):** RA-200 closed the P13-j Review and authorized CB79 → TB73. Stable 66/17/49, debt 1, accepted CP2 491/491 and selector497 remain unchanged; no CP3 promotion.

### Earlier: RA-199, CB78 and the TB72 corrected full gate

- **[RA-199](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md)** closes `M6-CP3-DEFN-P13-FLOWREP-SELECTION` by scratch probes. Selection cannot see whether a support trace meets the layout: seed traces never end on another trace, so every support is a single flowline touching only its rail. Of 115 retained supports, exactly 10 are crossed or touched by nothing and return to the rail they left; all five lenses are among them. Coverage is not the criterion (lenses 20/422/612 lie 2–6 % of target size from the rail, tolerance 2 %; cross-face coverage still leaves 3 lenses). **Amendment 31:** `build_flow_rep_selection_input` does not admit an unmet support chord; one pass is the fixed point. Exact CB78 on the scratch build: Vase reaches **P13-j** `AssemblyRejected`/`NonManifoldStitchedVertex`; Cylinder PASS; BunnyRandom unchanged (A1); scratch gate 882/883 (only O16 row 283), ledger 0/81 unchanged; mutants M1–M3 each fail a GUARD row.
- **CB78 COMPLETE:** [Code + Build record](Architecture_M6_CP3_CB78_P13_Support_Chord_Admission_Code_Build_Record_20261102.md): source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`, Linux compile run `41531251636`, immutable package `13181887585` (28/28 checksums), GMP/GMPXX eight targets, `runtimeExecution=false`. **Mandatory next turn:** `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC` (RA-199.5; manifest 883 `e9eabb06…`, membership 964).
- **Review track, can start now:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (P13-j, on the CB78 scratch state) and `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e).

### Earlier: verified TB71

- [TB71 report](Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md) verifies [gate 41492237758](https://github.com/akashskypatel/Directional/actions/runs/41492237758) **881/881 PASS** (871 GUARD, 10 POSITIVE), 1770/1770 artifact hashes, 962 membership, 81 deferred. [Census 41492364954](https://github.com/akashskypatel/Directional/actions/runs/41492364954) 9/9 hashes: Cylinder PASS; BunnyRandom P13-e RED vertex49; Vase P13-i RED `completion` / `PatchCompletionRejected` / `IncompleteSurfaceCellComplex` / `side-count-unsupported` (288.680 s, within 600 s). All registered RA-198.5 outcomes MATCH, no rebuild, no selector or CP3 promotion; mismatch and orchestration branches not triggered.
- **Review-track authority after TB71 (RA-198.6, now closed by RA-199):** `M6-CP3-DEFN-P13-FLOWREP-SELECTION` (P13-i). In parallel, `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e). Both are independent probe DEFNs on an authorized scratch build; do not start either as part of TB71. The implementation-agent RA-198.6 scope (CB77 → TB71) is complete.
- **Standing state:** stable 66/17/49, debt 1, CP2 491/491, ledger v5 81 deferred, selector497 unpromoted. Vase and BunnyRandom remain unsuccessful on direct production; O16/O17/O19/O20/O21/O22/O23/O24/O6/O9 and DR1/DR3, DR2/DR4 remain carried.

## Turn Sequence

| Step | Canonical turn | Track / condition |
|---|---|---|
| 1 — COMPLETE | `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC` | Linux 869/869, membership 950, census as registered |
| 2 — COMPLETE | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` | Static decision; RA-193 probe adjudication (exact patches, TB67 manifest 871); RA-194 review of the landed diagnostics and its revert |
| 3 — COMPLETE | `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` | Implementation agent, Linux; exact revert (RA-194.6), source equality with `911840c1…`, no build |
| 4 — COMPLETE | `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | Implementation agent, Linux; RA-193.10 (`35727214…`, `29 1`), spec RA-193.5, compile only. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TERMINAL-STOP`; infrastructure → `M6-CP3-CB69A-P13-ARRANGEMENT-TERMINAL-ORCH` |
| 5 — COMPLETE | `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869/869, membership 950, census per RA-193.6 (Vase `arrangement` / `RepeatedNodeCycle`). Mismatch → `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-REV`; infrastructure → `M6-CP3-TB66A-P13-ARRANGEMENT-TERMINAL-ORCH` |
| 6 — COMPLETE | `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION` | Implementation agent, Linux; RA-193.11 (`e93f5d8c…`, `37 30` / `95 0`), spec RA-193.7, compile only. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-WEDGE-STOP`; infrastructure → `M6-CP3-CB70A-P13-ARRANGEMENT-WEDGE-ORCH` |
| 7 — COMPLETE | `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | Implementation agent, Linux; gate 871/871, membership 952, census per RA-193.8 (Vase ABNORMAL 600 s timeout). Mismatch → `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-REV`; infrastructure → `M6-CP3-TB67A-P13-ARRANGEMENT-WEDGE-ORCH` |
| 8 — Review COMPLETE | `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (P13-f) | Static decision, then RA-195 probe adjudication: Amendment 27, exact CB71/CB72, TB68 manifest 873 |
| 9 — COMPLETE | `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` | Implementation agent, Linux; RA-195.8 (`8512400f…`), spec RA-195.4, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-GRAPH-STOP`; infrastructure → `M6-CP3-CB71A-P13-COMPLETION-GRAPH-ORCH` |
| 10 — COMPLETE | `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH` | Implementation agent, Linux; RA-195.9 (`514c6d87…`), spec RA-195.5, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-PASS-GRAPH-STOP`; infrastructure → `M6-CP3-CB72A-P13-COMPLETION-PASS-GRAPH-ORCH` |
| 11 — COMPLETE | `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 873 `3b6b9f42…` + ledger v5, 873/873, membership 954; census per RA-195.6. Mismatch → `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-REV`; infrastructure → `M6-CP3-TB68A-P13-COMPLETION-GRAPH-ORCH` |
| 12 — Review COMPLETE | `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING` (P13-g) | Static decision (no probe, open A/B CB73), then [RA-196](Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md) probe adjudication: Amendment 28, exact CB73/CB74/CB75, TB69 manifest 878 |
| 13 — COMPLETE | `M6-CP3-CB73-P13-COMPLETION-EMBEDDING` | **COMPLETE**; exact RA-196.9 patch source `57c24325f539`, eight-target compile package 13104267023. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-EMBEDDING-STOP`; infrastructure → `M6-CP3-CB73A-P13-COMPLETION-EMBEDDING-ORCH` |
| 14 — COMPLETE | `M6-CP3-CB74-P13-COMPLETION-QUADRANGULATION-SEARCH` | Implementation agent, Linux; RA-196.10 (`b2c6a251…`), spec RA-196.5, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-QUADRANGULATION-STOP`; infrastructure → `M6-CP3-CB74A-P13-COMPLETION-QUADRANGULATION-ORCH` |
| 15 — COMPLETE | `M6-CP3-CB75-P13-COMPLETION-TERMINAL-DETAIL` | Implementation agent, Linux; RA-196.11 (`d1f5652a…`), spec RA-196.6, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-TERMINAL-STOP`; infrastructure → `M6-CP3-CB75A-P13-COMPLETION-TERMINAL-ORCH` |
| 16 — COMPLETE | `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 878 `aaaba077…` + ledger v5, 878/878, membership 959; census per RA-196.7 (Vase RED `completion` / `PatchCompletionRejected` / `closed-form`). Mismatch → `M6-CP3-TB69-P13-COMPLETION-EMBEDDING-FULL-GATE-REV`; infrastructure → `M6-CP3-TB69A-P13-COMPLETION-EMBEDDING-ORCH` |
| 17 — Review COMPLETE | `M6-CP3-DEFN-P13-COMPLETION-GRID-EMBEDDING` (P13-h; P13-i classified) | ChatGPT review WIP (blocked: "no trace"), then [RA-197](Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md) probe adjudication: Amendment 29, exact CB76, TB70 manifest 880 |
| 18 — COMPLETE | `M6-CP3-CB76-P13-PATCH-BOUNDARY-SIDE-START` | Implementation agent, Linux; RA-197.7 (`5c7918fb…`), spec RA-197.4, compile only. Mismatch → `M6-CP3-PLAN-P13-PATCH-SIDE-START-STOP`; infrastructure → `M6-CP3-CB76A-P13-PATCH-SIDE-START-ORCH` |
| 19 — COMPLETE | `M6-CP3-TB70-P13-PATCH-SIDE-START-FULL-GATE-EXEC` | [Report](Architecture_M6_CP3_TB70_P13_Patch_Side_Start_Full_Gate_Execution_Report_20261102.md): 880/880 PASS, membership 961, census Cylinder PASS / BunnyRandom P13-e RED / Vase generated-vertex P13-h2 RED, registered outcomes MATCH; no mismatch or infrastructure route |
| 20 — Review COMPLETE | `M6-CP3-DEFN-P13-ARRANGEMENT-SLIVER-CELLS` (P13-h2, P13-i) | ChatGPT review WIP (BLOCKED: "Review policy prohibits runtime probes"), then [RA-198](Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md) probe adjudication: Amendment 30, exact CB77, TB71 manifest 881; P13-i → selection DEFN |
| 21 — COMPLETE | `M6-CP3-CB77-P13-NEEDLE-GRID-BOUNDARY-SEARCH` | Implementation agent, Linux; RA-198.8 (`673010d4…`), spec RA-198.4, compile only. Mismatch → `M6-CP3-PLAN-P13-NEEDLE-GRID-STOP`; infrastructure → `M6-CP3-CB77A-P13-NEEDLE-GRID-ORCH` |
| 22 — COMPLETE | `M6-CP3-TB71-P13-NEEDLE-GRID-FULL-GATE-EXEC` | [Report](Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md): 881/881 PASS, membership 962; census Cylinder PASS / BunnyRandom P13-e RED / Vase P13-i `side-count-unsupported` RED; registered outcomes MATCH, no mismatch or infrastructure route |
| 23 — Review COMPLETE | `M6-CP3-DEFN-P13-FLOWREP-SELECTION` (P13-i) | ChatGPT preflight (BLOCKED: no scratch execution), then [RA-199](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md) probe adjudication: unmet support chords → Amendment 31, exact CB78, TB72 manifest 883; O25; next failure P13-j |
| 24 — COMPLETE | `M6-CP3-CB78-P13-SUPPORT-CHORD-ADMISSION` | Implementation agent, Linux; RA-199.8 (`1d8b80e7…`, `119 0` / `153 0`, keep 3 single-space context lines), spec RA-199.4, compile only. Mismatch → `M6-CP3-PLAN-P13-SUPPORT-CHORD-STOP`; infrastructure → `M6-CP3-CB78A-P13-SUPPORT-CHORD-ORCH` |
| 25 — INVALID ORCHESTRATION | `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 883 `e9eabb06…` + ledger v5, 883/883, membership 964; census per RA-199.5 (Vase RED `completion` / `AssemblyRejected` / `NonManifoldStitchedVertex`, within 600 s). Mismatch → `M6-CP3-TB72-P13-SUPPORT-CHORD-FULL-GATE-REV`; infrastructure → `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH` |
| 25A — COMPLETE | `M6-CP3-TB72A-P13-SUPPORT-CHORD-ORCH` | Corrected executor; run 41540264758, 883/883 PASS, 81 deferred, membership964, 1774/1774 hashes; invalid TB72 attempt retained. |
| 26 — Review COMPLETE | `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (P13-j, Vase) | ChatGPT same-turn records (BLOCKED: completed lineage unmeasured, no C++), then [RA-200](Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md) probe adjudication: node-intrinsic boundary key → Amendment 32, exact CB79, TB73 manifest 886; O26; next failure P13-k |
| 27 — COMPLETE | `M6-CP3-CB79-P13-NODE-STITCH-KEY` | Implementation agent, Linux; RA-200.8 (`89f37001…`, `25 2` / `95 0`, keep 1 single-space context line), spec RA-200.4, compile only. Mismatch → `M6-CP3-PLAN-P13-NODE-STITCH-KEY-STOP`; infrastructure → `M6-CP3-CB79A-P13-NODE-STITCH-KEY-ORCH` |
| 28 — COMPLETE | `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 886 `5d09fa33…` + ledger v5, 886/886, membership 967; census per RA-200.5 (Vase **ABNORMAL** 600 s timeout after assembly; any verdict before 600 s is a mismatch). Mismatch → `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-REV`; infrastructure → `M6-CP3-TB73A-P13-NODE-STITCH-KEY-ORCH` |
| 29 — Review COMPLETE | `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (P13-k, Vase) | ChatGPT static preflight (BLOCKED: needs scratch execution), then [RA-201](Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md) probe adjudication: five instances of one class → Amendment 33, exact CB80–CB83, TB74–TB76 manifests; P13-l named (pre-optimization output validation; detail `SelfIntersectingFace`) |
| 30 — NEXT | `M6-CP3-CB80-P13-RAIL-BINDING-ONCE` | Implementation agent, Linux; RA-201.4: patch file `d4dda97e…` (281 lines, keep its 11 single-space context lines), numstat `15 8` / `31 23` / `128 0`, compile only. Mismatch → `M6-CP3-PLAN-P13-RAIL-BINDING-STOP`; infrastructure → `M6-CP3-CB80A-P13-RAIL-BINDING-ORCH` |
| 31 | `M6-CP3-TB74-P13-RAIL-BINDING-ONCE-FULL-GATE-EXEC` | Implementation agent; manifest 888 `bb4e771f…` + ledger v5, 888/888, membership 969; census Cylinder PASS, BunnyRandom P13-e, **Vase ABNORMAL 600 s**. Mismatch → `…-FULL-GATE-REV`; infrastructure → `M6-CP3-TB74A-P13-RAIL-BINDING-ONCE-ORCH` |
| 32 | `M6-CP3-CB81-P13-LENT-PROJECTION-CACHE` | Implementation agent; RA-201.6: `ffa4b554…` (169 lines, 6 single-space context lines), numstat `7 1` / `29 11` / `58 0`. Mismatch → `M6-CP3-PLAN-P13-LENT-PROJECTION-CACHE-STOP`; infrastructure → `M6-CP3-CB81A-P13-LENT-PROJECTION-CACHE-ORCH` |
| 33 | `M6-CP3-TB75-P13-LENT-PROJECTION-CACHE-FULL-GATE-EXEC` | Implementation agent; manifest 890 `a134d941…`, 890/890, membership 971; census as TB74 (**Vase ABNORMAL 600 s**) |
| 34 | `M6-CP3-CB82-P13-LENT-LABEL-SUPPORT` | Implementation agent; RA-201.8: `b963ea3d…` (349 lines, 10 single-space context lines), numstat `19 5` / `3 2` / `54 13` / `122 0`. Mismatch → `M6-CP3-PLAN-P13-LENT-LABEL-SUPPORT-STOP`; infrastructure → `M6-CP3-CB82A-P13-LENT-LABEL-SUPPORT-ORCH` |
| 35 | `M6-CP3-CB83-P13-OUTPUT-VALIDATION-TERMINAL-DETAIL` | Implementation agent; RA-201.9: `3741697e…` (16 lines, 1 single-space context line), numstat `4 1` `RemeshPipeline.cpp`. Mismatch → `M6-CP3-PLAN-P13-OUTPUT-VALIDATION-TERMINAL-STOP`; infrastructure → `M6-CP3-CB83A-P13-OUTPUT-VALIDATION-TERMINAL-ORCH` |
| 36 | `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-EXEC` | Implementation agent; manifest 893 `3b727161…`, 893/893, membership 974; census Cylinder PASS, BunnyRandom P13-e, **Vase RED within 600 s, `NotProductionReady:completion detail=SelfIntersectingFace`**. Timeout → CB82 did not take; `detail=None` → CB83 did not take. Mismatch → `M6-CP3-TB76-P13-OPTIMIZER-SOURCE-QUERY-FULL-GATE-REV`; infrastructure → `M6-CP3-TB76A-P13-OPTIMIZER-SOURCE-QUERY-ORCH` |
| 37 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l, Vase) → CB → TB | Probe DEFN on the RA-201 scratch state (Claude). First measurement: same-direction interior edges right after assembly and after `orient_quads_to_source_normals`, by patch. Then decide whether the pre-optimization gate applies final quality thresholds (DESIGN §4.9). RA-201.3 item 5 |
| 38 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) → CB → TB | Probe DEFN, then exact patch |
| 39 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

The implementation agent takes rows 30–36, in order, one turn each, and starts a row only after the previous one is verified. Rows 37–38 are probe DEFNs on the Review track (Claude, scratch build); a turn that cannot run a scratch probe must not start them (RA-172, RA-198 to RA-201).

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB80-P13-RAIL-BINDING-ONCE** (Code + Build, Linux, compile only; RA-201.4). Then TB74, CB81, TB75, CB82, CB83 and TB76, one turn each (RA-201.11). Review track in parallel: `M6-CP3-DEFN-P13-COMPLETED-MESH-ORIENTATION` (P13-l) and the P13-e Review, each only with scratch-build execution. Earlier: `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` is closed by RA-201; CB79 and TB73 are complete; do not replay them.

Read first:
- [RA-201](Architecture_M6_CP3_DEFN_P13_Optimizer_Source_Query_Cost_Probe_Adjudication_20261103.md): §1 findings (five instances of one class; P13-l named); §3 rulings; §4–§10 CB80, TB74, CB81, TB75, CB82, CB83, TB76 specs with the four `.diff` files; §11 sequence; §12 scratch verification; DESIGN Amendment 33.
- [RA-200](Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Probe_Adjudication_20261103.md): §1 findings (identical certificates, halfedge-scoped key, 23,221 split nodes, P13-k next); §2 probes; §3 rulings (closes the earlier Review's open conditions); §4 CB79 and §5 TB73 specs; §6 sequence; §8 exact patch; DESIGN Amendment 32.
- [RA-199](Architecture_M6_CP3_DEFN_P13_FlowRep_Selection_Probe_Adjudication_20261102.md): §1 findings (lenses are unmet support chords; coverage and degrees not the owner; P13-j next); §2 probes; §4 CB78 and §5 TB72 specs; §6 sequence; §8 exact patch; DESIGN Amendment 31.
- [TB71 report](Architecture_M6_CP3_TB71_P13_Needle_Grid_Full_Gate_Execution_Report_20261102.md): immutable CB77 gate 881/881 and census (Vase P13-i).
- [RA-198](Architecture_M6_CP3_DEFN_P13_Arrangement_Sliver_Cells_Probe_Adjudication_20261102.md): §1 findings (P13-h2 owner completion; P13-i owner selection, which removes 0 of 4,057 candidates); §2 probes; §4 CB77 and §5 TB71 specs; §6 sequence; §8 exact patch; DESIGN Amendment 30.
- [TB70 report](Architecture_M6_CP3_TB70_P13_Patch_Side_Start_Full_Gate_Execution_Report_20261102.md): exact Linux immutable gate/census evidence and new post-CB76 Vase failure.
- [RA-197](Architecture_M6_CP3_DEFN_P13_Completion_Grid_Embedding_Probe_Adjudication_20261102.md): §1 findings (owner: side-0 registration); §2 probes (first-pass census, rotation, interpolants, P13-i lenses); §4 CB76 and §5 TB70 specs; §6 sequence; §7 exact patch; DESIGN Amendment 29.
- [TB69 report](Architecture_M6_CP3_TB69_P13_Completion_Embedding_Full_Gate_Execution_Report_20261102.md): immutable CB75 gate 878/878 and census (Vase P13-h at patch 4).
- [RA-196](Architecture_M6_CP3_DEFN_P13_Completion_Quad_Embedding_Probe_Adjudication_20261101.md): §1 findings on the static decision; §2 probes (first-pass failure census); §4–§7 CB73, CB74, CB75, TB69 specs; §8 sequence; §9–§11 exact patches; DESIGN Amendment 28.
- [TB68 full gate and production census report](Architecture_M6_CP3_TB68_P13_Completion_Graph_Full_Gate_Execution_Report_20261101.md): exact immutable source, gate, census and P13-g failure locus.
- [CB72 Code + Build record](Architecture_M6_CP3_CB72_Completion_Pass_Graph_Code_Build_Record_20261101.md): exact source, immutable compile artifact, 28 checks and no-runtime boundary.
- [CB71 Code + Build record](Architecture_M6_CP3_CB71_Completion_Chart_Graph_Reuse_Code_Build_Record_20261101.md): frozen exact source/patch, successful compile artifacts and no-runtime boundary.
- [RA-195](Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md): §4–§6 CB71, CB72, TB68 specs; §7 sequence; §8–§9 exact patches; DESIGN Amendment 27.
- [TB67 report](Architecture_M6_CP3_TB67_P13_Arrangement_Wedge_Full_Gate_Execution_Report_20261101.md): immutable 871/871 gate, exact result artifacts, independent census, timeout limits and no acceptance promotion.
- [RA-193](Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md): §8 registered timeout, §9 P13-f Review successor and earlier O(F) probe attribution; use current renumbering from [RA-194](Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md).
- [CB70 report](Architecture_M6_CP3_CB70_Arrangement_Wedge_Rotation_Code_Build_Record_20261101.md): immutable source/package boundary, not runtime acceptance.
- [TB66 report](Architecture_M6_CP3_TB66_P13_Arrangement_Terminal_Full_Gate_Execution_Report_20261101.md): predecessor baseline and P13-e signature.
- Relevant `DESIGN.md` Amendments 26–33, `LESSONS.md` §§1, 2, 3, 5, 6, 7 and `Regression_Root_Cause_Tracker.md` P13-f candidate.

Inputs:

| Input | Value |
|---|---|
| CB68 completed | [`90fa3a15`](https://github.com/akashskypatel/Directional/commit/90fa3a155930c2683ed0789ef88e9f8f52775437); restored source byte-identical to compiled `911840c1…` on all source/build/test paths; workflow `41306617232`, `runtimeExecution=false` |
| TB66 evidence | gate [41312768151](https://github.com/akashskypatel/Directional/actions/runs/41312768151) / `13086562028`; census [41312834931](https://github.com/akashskypatel/Directional/actions/runs/41312834931) / `13086079391`; 869/869, 1 PASS / 2 registered RED; all hashes/pass boundaries verified. |
| CB71 package | Source `042979f7a264dff21de4e3b1af25a1a27fe27c95`, [run 41329208274](https://github.com/akashskypatel/Directional/actions/runs/41329208274), artifact `13092069619`, ZIP `729a5ff0020ea81d762ef7fa2276e40c07288a93c75219918408de0dabc2d9e0`, 28/28 checks, no runtime. |
| CB72 package | Source `7b85b450bc98abfb65db511fdcd524eb11f537f8`, [run 41333097065](https://github.com/akashskypatel/Directional/actions/runs/41333097065), artifact `13093439789`, ZIP `9b9482fd92af01bc4de0e72964459765c70bca3acb4583a12df0ac5ccb7c7e20`, 28/28, GMP/GMPXX, `runtimeExecution=false` |
| CB69 package | Source `5b08abe42f91f88fd6d09e225c7cf32d0aeb1ef3`, [run 41310503404](https://github.com/akashskypatel/Directional/actions/runs/41310503404), artifact `13084749209`, eight GMP/GMPXX targets, compile-only |
| TB66 gate | TB65 manifest 869 `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`, unchanged; ledger v5 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; membership 950 |
| TB67 gate | Manifest 871 `Architecture_M6_TB67_P13_Arrangement_Wedge_Full_Gate_Case_Manifest.tsv` `434e6d373c327d909f6b458fb9b10bd8cdac5d3c073dfefe11fbb30ee34a385b` (TB65 869 byte-identical prefix plus rows 870–871); same ledger; membership 952 |
| TB68 gate | Manifest 873 `Architecture_M6_TB68_P13_Completion_Graph_Reuse_Full_Gate_Case_Manifest.tsv` `3b6b9f425d4061885b393ccd2d530cbcd3d4f39916859e0db197ce1e6029ea60` (TB67 871 byte-identical prefix plus rows 872–873); same ledger; membership 954; `SELF_CHECK_PASS cases=873 deferred=81` |
| CB75 package | Source `8656c4fed5070a467da491b60ead5c8ab1d99dbd`, [compile 41365067300](https://github.com/akashskypatel/Directional/actions/runs/41365067300), artifact `13107147891`, ZIP SHA-256 `a689c5b3254682a6345f2e17e43e3a8e571401c1ed6a224d13a4a5f84c8bc7d2`, 28/28 internal hashes; GMP/GMPXX, no runtime. |
| TB69 gate | Manifest 878 `Architecture_M6_TB69_P13_Completion_Embedding_Full_Gate_Case_Manifest.tsv` `aaaba077a067853a00310683946f82394c60247bd42717fd283b4d7cde423c82` (TB68 873 byte-identical prefix plus GUARD rows 874–878); same ledger; membership 959; `SELF_CHECK_PASS cases=878 deferred=81` |
| TB70 gate | Manifest 880 `Architecture_M6_TB70_P13_Patch_Side_Start_Full_Gate_Case_Manifest.tsv` `a9f964c843a5620f281bf2ca2f07e7df9b8d11a7769218a635a5b707aaf2b03b` (TB69 878 byte-identical prefix plus GUARD rows 879–880); same ledger; membership 961; `SELF_CHECK_PASS cases=880 deferred=81` |
| TB71 gate | Manifest 881 `Architecture_M6_TB71_P13_Needle_Grid_Full_Gate_Case_Manifest.tsv` `f2503dcaf91b13c4a221d52fe7a18899327ab6f96862c3688a67f8f8d14c78a6` (TB70 880 byte-identical prefix plus GUARD row 881); same ledger; membership 962; `SELF_CHECK_PASS cases=881 deferred=81` |
| TB72 gate | Manifest 883 `Architecture_M6_TB72_P13_Support_Chord_Full_Gate_Case_Manifest.tsv` `e9eabb064fba1aa625b20931f1b85cf3f441c0c877a81cccd49b73bb5ebd3031` (TB71 881 byte-identical prefix plus GUARD rows 882–883); same ledger; membership 964; `SELF_CHECK_PASS cases=883 deferred=81` |
| TB73 gate | Manifest 886 `Architecture_M6_TB73_P13_Node_Stitch_Key_Full_Gate_Case_Manifest.tsv` `5d09fa337b42adc8629f4bded8ea35b2181e468fb9dd91f7db5414fa534cfc4a` (TB72 883 byte-identical prefix plus GUARD rows 884–886); same ledger; membership 967; `SELF_CHECK_PASS cases=886 deferred=81` |
| CB80–CB83 patches | `Architecture_M6_CP3_CB80_P13_Rail_Binding_Once.diff` `d4dda97eeea13c4c50ca107fa06bf093b7a173abce9a0bbfb268e8793da265fe`; `…CB81_P13_Lent_Projection_Cache.diff` `ffa4b5548b6bf45f044dac4b46fb2cca51db051b324d2ca7c0116faae99a4e30`; `…CB82_P13_Lent_Label_Support.diff` `b963ea3d4b440fea66b65926478861b7bb6c489166f21b7db41769dc31cde1d2`; `…CB83_P13_Output_Validation_Terminal_Detail.diff` `3741697ed34d219579a97081db3763126292a3d103a445e2ceda6cbbf37df682`. They apply in that order on CB79 source; result hashes are in RA-201.4/.6/.8/.9 |
| TB74 gate | Manifest 888 `Architecture_M6_TB74_P13_Rail_Binding_Once_Full_Gate_Case_Manifest.tsv` `bb4e771fd911d9aefdb83c89cf2ac8def41e464bb41f26778a1b3a98adbee4da` (TB73 886 byte-identical prefix plus GUARD rows 887–888); same ledger; membership 969; `SELF_CHECK_PASS cases=888 deferred=81` |
| TB75 gate | Manifest 890 `Architecture_M6_TB75_P13_Lent_Projection_Cache_Full_Gate_Case_Manifest.tsv` `a134d9411bd5885fa85d7405e2a733da7cd4d5899d17a83f6dbcb501d18326c6` (TB74 888 prefix plus rows 889–890); membership 971; `SELF_CHECK_PASS cases=890 deferred=81` |
| TB76 gate | Manifest 893 `Architecture_M6_TB76_P13_Optimizer_Source_Query_Full_Gate_Case_Manifest.tsv` `3b72716137800726f9ce46a7ea6aee1f8a7db0122be29df97c359ea098545bf8` (TB75 890 prefix plus rows 891–893); membership 974; `SELF_CHECK_PASS cases=893 deferred=81` |
| Census | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Harness | P8 `78b8002c…`, unchanged |

Standing state: CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted. O16 (macOS), O17, O19, O20, O21, O22, O23, P13-e, P13-g gated by CB73–CB75/TB69, P13-h CB76/TB70 verified; P13-h2 → CB77/TB71 verified; P13-i → Amendment 31, CB78/TB72A verified (RA-199); P13-j → Amendment 32, CB79/TB73 verified (RA-200); P13-k → Amendment 33, CB80–CB83/TB74–TB76 (RA-201); P13-l → completed-mesh orientation DEFN; O24, O25, O26 new; DR1/DR3, DR2/DR4 and O6/O9 are carried.

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
