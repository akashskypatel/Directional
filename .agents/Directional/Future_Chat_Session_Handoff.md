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
| Currency | 2026-11-01 **[RA-195](Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md) probe-adjudicated P13-f. Exact CB71 → CB72 → TB68 next** (DESIGN Amendment 27). The decision's open-ended CB71 plan is superseded; the turn ID is kept for the exact patch. TB67 ([report](Architecture_M6_CP3_TB67_P13_Arrangement_Wedge_Full_Gate_Execution_Report_20261101.md)) matched RA-193.8; no CP3 promotion. |
| Working branch / compiled source | `agent/surface_cell_quad/p5-recover-bridge-healing`; CB70 source [`9754500b2058`](https://github.com/akashskypatel/Directional/commit/9754500b2058229b7f0a6268838953650690b031), compile package `13087332886`; preceding CB69 semantic source [`5b08abe42f91`](https://github.com/akashskypatel/Directional/commit/5b08abe42f91f88fd6d09e225c7cf32d0aeb1ef3), immutable package `13084749209`; no code/tests/build/selector mutations in TB66. |
| Last accepted semantic runtime | **CP2 491/491**, accepted 2026-10-06; unchanged, TB67 candidate only. |
| Latest candidate | **TB67 Linux gate 871/871 PASS, membership 952**, [run 41318594024](https://github.com/akashskypatel/Directional/actions/runs/41318594024), result `13089225030`, ZIP `cc3dd211d243081c8fc9861923fd1a01c332c9b8182692e8f1f7dad693642dce`, 1750/1750 hashes; independent **census Cylinder PASS, BunnyRandom expected RED, Vase expected ABNORMAL 600 s timeout**, [run 41318624551](https://github.com/akashskypatel/Directional/actions/runs/41318624551), result `13089595542`, ZIP `fb80af756d9a740d1393c7f12b66bcf4f8f399544056b467c4207fe89487621e`, 9/9 hashes; both postflight true, no rebuild. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**; v5 deferred 81 (47 FIXTURE, 7 PRODUCT, 22 OPEN, 5 RETIRE), membership 952, unchanged; selector497 unpromoted. DR1/DR3 open, DR2/DR4 → M8-CP2. |
| Active boundary | **Cylinder PASS**. **BunnyRandom P13-e** `SingularityPortClassCountMismatch` at source vertex 49, no produced quads. **Vase:** TB67 timed out at 600 s. RA-195 probes attribute that to P13-f (per-vertex and per-patch graph rebuilds, 93.5 % of completion CPU). With CB71 + CB72 the macOS probe ends at a typed **P13-g** RED at `completion`: `InvalidCompletionQuadEmbedding`, patch 1200, bounded-combinatorial, variant 15, bow-tie, in 138 s. O18 discharged; O20 (residual per-call O(F) work) new, non-blocking; O16/O17/O19/O6/O9 carried. |

## Mandatory next turn — `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` — EXACT NEXT

- **Predecessor:** `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST`. The [static decision](Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Review_Decision_20261101.md) named the sites but froze an open-ended plan and left the next Vase failure unnamed. [RA-195](Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md) probe-adjudicated it (findings F1–F7). The [CB71 plan](Architecture_M6_CP3_CB71_P13_Completion_Chart_Graph_Reuse_Code_Build_Plan_20261101.md) is superseded.
- **CB71 (Code; implementation agent; Linux workflow runner; compile only):**
  - Precheck `git diff --quiet 9754500b2058229b7f0a6268838953650690b031 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
  - Apply the RA-195.8 block verbatim plus a trailing newline. Keep its 6 single-space context lines. SHA-256 `8512400fe56c59f35ac3770383890366f35028c47346ba1fdeb04ca5014e5852`; `git apply --check`.
  - Numstat `14 0` PureQuadCompletion.h, `18 0` SourceChartTransitions.h, `49 9` PureQuadCompletion.cpp, `86 0` PureQuadCompletionPhase18Tests.cpp. Result SHA-256s per RA-195.4.
  - One eight-target GMP/GMPXX compile; no binary runs.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-GRAPH-STOP`; infrastructure → `M6-CP3-CB71A-P13-COMPLETION-GRAPH-ORCH`.
- **Then CB72** (RA-195.9, `514c6d87…`, numstat `6 1` / `10 1` / `17 6` / `58 0`) and **TB68** (RA-195.6: 873/873, membership 954; Vase RED at `completion` / `InvalidCompletionQuadEmbedding` within 600 s).
- **Carried:** P13-g and P13-e DEFNs (Review track, can start now); O16/O17/O19/O20/O6/O9, DR1/DR3, DR2/DR4; stable 66/17/49 debt 1, CP2 accepted 491/491, selector497 frozen.

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
| 9 — NEXT | `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` | Implementation agent, Linux; RA-195.8 (`8512400f…`), spec RA-195.4, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-GRAPH-STOP`; infrastructure → `M6-CP3-CB71A-P13-COMPLETION-GRAPH-ORCH` |
| 10 | `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH` | Implementation agent, Linux; RA-195.9 (`514c6d87…`), spec RA-195.5, compile only. Mismatch → `M6-CP3-PLAN-P13-COMPLETION-PASS-GRAPH-STOP`; infrastructure → `M6-CP3-CB72A-P13-COMPLETION-PASS-GRAPH-ORCH` |
| 11 | `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-EXEC` | Implementation agent, Linux; manifest 873 `3b6b9f42…` + ledger v5, 873/873, membership 954; census per RA-195.6. Mismatch → `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-REV`; infrastructure → `M6-CP3-TB68A-P13-COMPLETION-GRAPH-ORCH` |
| 12 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING` (P13-g, Vase patch 1200 bow-tie) → CB → TB | Probe DEFN on the RA-195 scratch build; name the owner; close `detail=None`; then exact patch |
| 13 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) → CB → TB | Probe DEFN, then exact patch |
| 14 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE** (Code + Build, compile only; exact patch [RA-195](Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md).8, spec RA-195.4; no runtime). The ChatGPT CB71 plan is superseded and is not an authority.

Read first:
- [RA-195](Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Probe_Adjudication_20261101.md): §4–§6 CB71, CB72, TB68 specs; §7 sequence; §8–§9 exact patches; DESIGN Amendment 27.
- [TB67 report](Architecture_M6_CP3_TB67_P13_Arrangement_Wedge_Full_Gate_Execution_Report_20261101.md): immutable 871/871 gate, exact result artifacts, independent census, timeout limits and no acceptance promotion.
- [RA-193](Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md): §8 registered timeout, §9 P13-f Review successor and earlier O(F) probe attribution; use current renumbering from [RA-194](Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md).
- [CB70 report](Architecture_M6_CP3_CB70_Arrangement_Wedge_Rotation_Code_Build_Record_20261101.md): immutable source/package boundary, not runtime acceptance.
- [TB66 report](Architecture_M6_CP3_TB66_P13_Arrangement_Terminal_Full_Gate_Execution_Report_20261101.md): predecessor baseline and P13-e signature.
- Relevant `DESIGN.md` Amendments 26–27, `LESSONS.md` §§1, 2, 3, 5, 6, 7 and `Regression_Root_Cause_Tracker.md` P13-f candidate.

Inputs:

| Input | Value |
|---|---|
| CB68 completed | [`90fa3a15`](https://github.com/akashskypatel/Directional/commit/90fa3a155930c2683ed0789ef88e9f8f52775437); restored source byte-identical to compiled `911840c1…` on all source/build/test paths; workflow `41306617232`, `runtimeExecution=false` |
| TB66 evidence | gate [41312768151](https://github.com/akashskypatel/Directional/actions/runs/41312768151) / `13086562028`; census [41312834931](https://github.com/akashskypatel/Directional/actions/runs/41312834931) / `13086079391`; 869/869, 1 PASS / 2 registered RED; all hashes/pass boundaries verified. |
| CB69 package | Source `5b08abe42f91f88fd6d09e225c7cf32d0aeb1ef3`, [run 41310503404](https://github.com/akashskypatel/Directional/actions/runs/41310503404), artifact `13084749209`, eight GMP/GMPXX targets, compile-only |
| TB66 gate | TB65 manifest 869 `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`, unchanged; ledger v5 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; membership 950 |
| TB67 gate | Manifest 871 `Architecture_M6_TB67_P13_Arrangement_Wedge_Full_Gate_Case_Manifest.tsv` `434e6d373c327d909f6b458fb9b10bd8cdac5d3c073dfefe11fbb30ee34a385b` (TB65 869 byte-identical prefix plus rows 870–871); same ledger; membership 952 |
| TB68 gate | Manifest 873 `Architecture_M6_TB68_P13_Completion_Graph_Reuse_Full_Gate_Case_Manifest.tsv` `3b6b9f425d4061885b393ccd2d530cbcd3d4f39916859e0db197ce1e6029ea60` (TB67 871 byte-identical prefix plus rows 872–873); same ledger; membership 954; `SELF_CHECK_PASS cases=873 deferred=81` |
| Census | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Harness | P8 `78b8002c…`, unchanged |

Standing state: CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted. O16 (macOS), O17, O19, O20, P13-e, P13-f (until TB68), P13-g, DR1/DR3, DR2/DR4 and O6/O9 are carried.

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
