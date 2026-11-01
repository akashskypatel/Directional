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
| Currency | 2026-11-01 **[RA-194](Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md): the withdrawn diagnostics CB67 landed anyway (`829a47b2d`, uncompiled); it is reverted exactly by CB68, then [RA-193](Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md)'s patches run as CB69 and CB70.** RA-193 stands: Vase's arrangement publishes zero cells because its directed wedges split per face chart (R1) and half its edge rotations are mirrored (R2), and the pipeline ignores the arrangement's typed failure (R3, O18). No new accepted regression or CP3 promotion. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh at next turn. Last compiled and tested source `911840c195b52ce1800b3ac7ff3ea7380137ad9c` (CB66); HEAD source is that plus the uncompiled `829a47b2d`, which CB68 removes. |
| Last accepted semantic runtime | **CP2 491/491**, accepted 2026-10-06, unchanged; TB65 is candidate-only. |
| Latest candidate | **TB65 Linux gate 869/869 PASS, membership 950**, [run 41275216693](https://github.com/akashskypatel/Directional/actions/runs/41275216693), artifact `13071357793`, ZIP `b9064cfa9172d3e2b30b6da401dec287e5ef40f63a55857d5619174d3ad638df`, 1746/1746 checksums; **census 1 PASS, 2 registered RED**, [run 41275273919](https://github.com/akashskypatel/Directional/actions/runs/41275273919), artifact `13071376917`, ZIP `f8d6ed26819454ac313ccf687238d3e28304c776a04fe43526d49dedf602eebd`, 9/9 checksums. Both no rebuild. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Deferred ledger v5 **81** rows (47 FIXTURE, 7 PRODUCT, 22 OPEN, 5 RETIRE), membership 950. Selector497 not promoted. DR1/DR3 open; DR2/DR4 → M8-CP2. |
| Active boundary | TB65 869/869; Cylinder PASS. **BunnyRandom P13-e:** A1 `SingularityPortClassCountMismatch` at vertex 49. **Vase P13-d:** the arrangement has 0 cells (`RepeatedNodeCycle`, node 33); probes show RA-193's two patches (now CB69 + CB70) make it valid (26,827 cells) and move Vase into completion, where **P13-f** (O(F) `SourceChartTransitionGraph` rebuilt per vertex, then per patch) exceeds 600 s. O19 genus > 0 carried. No CP3 acceptance. |

## Mandatory next turn — `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` — EXACT NEXT

- **Type / owner:** Code, implementation agent, Linux workflow runner. Exact revert only; no design latitude, no build, no runtime. Authority: [RA-194](Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md) §4 and §6. The withdrawn `M6-CP3-CB67-P13-VASE-INCIDENCE-BOUNDARY-PROBE` is closed by this revert; do not compile or test `829a47b2d`.
- **Precheck:** `git diff --quiet 829a47b2d96eb7313e64402c3de666266725ba7e HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** apply the RA-194.6 block verbatim plus a trailing newline (keep its 13 single-space context lines). SHA-256 `a6b8cf62c8f9543bfa35766782906dc28c9d6cbe7263d5db0d1cabc1d4174c21`. Run `git apply --check`, then apply.
- **Expected diff:** numstat `0 8` PatchDescriptor.h, `0 23` SurfaceCellFeasibilityRepair.h, `0 14` PatchDescriptor.cpp, `46 85` SurfaceCellFeasibilityRepair.cpp, `0 49` RemeshPipeline.cpp, `0 34` MilestoneDClosureTests.cpp.
- **Postcheck (replaces the build):** `git diff --quiet 911840c195b52ce1800b3ac7ff3ea7380137ad9c HEAD -- src include tests benchmarks CMakeLists.txt cmake`. The compiled source is then CB66's, packaged as `13067780359` and run 869/869 by TB65.
- **Routes:** exact → `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL`; patch, numstat or postcheck mismatch → `M6-CP3-PLAN-P13-INCIDENCE-PROBE-REVERT-STOP` (Review); infrastructure failure → `M6-CP3-CB68A-P13-INCIDENCE-PROBE-REVERT-ORCH` (one retry).
- **Carried:** P13-e and P13-f are Review DEFNs. O16, O17, O19, O6/O9, DR1/DR3, DR2/DR4 carried. Stable 66/17/49, debt 1; CP2 491/491; selector497/CP3 not promoted.

## Turn Sequence

| Step | Canonical turn | Track / condition |
|---|---|---|
| 1 — COMPLETE | `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC` | Linux 869/869, membership 950, census as registered |
| 2 — COMPLETE | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` | Static decision; RA-193 probe adjudication (exact patches, TB67 manifest 871); RA-194 review of the landed diagnostics and its revert |
| 3 — NEXT | `M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE` | Implementation agent, Linux; exact revert (RA-194.6), source equality with `911840c1…`, no build |
| 4 | `M6-CP3-CB69-P13-ARRANGEMENT-INCIDENCE-TERMINAL` | Implementation agent, Linux; RA-193.10 (`35727214…`, `29 1`), spec RA-193.5, compile only. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-TERMINAL-STOP`; infrastructure → `M6-CP3-CB69A-P13-ARRANGEMENT-TERMINAL-ORCH` |
| 5 | `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869/869, membership 950, census per RA-193.6 (Vase `arrangement` / `RepeatedNodeCycle`). Mismatch → `M6-CP3-TB66-P13-ARRANGEMENT-TERMINAL-FULL-GATE-REV`; infrastructure → `M6-CP3-TB66A-P13-ARRANGEMENT-TERMINAL-ORCH` |
| 6 | `M6-CP3-CB70-P13-ARRANGEMENT-WEDGE-ROTATION` | Implementation agent, Linux; RA-193.11 (`e93f5d8c…`, `37 30` / `95 0`), spec RA-193.7, compile only. Mismatch → `M6-CP3-PLAN-P13-ARRANGEMENT-WEDGE-STOP`; infrastructure → `M6-CP3-CB70A-P13-ARRANGEMENT-WEDGE-ORCH` |
| 7 | `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-EXEC` | Implementation agent, Linux; gate 871/871, membership 952, census per RA-193.8 (Vase ABNORMAL 600 s timeout). Mismatch → `M6-CP3-TB67-P13-ARRANGEMENT-WEDGE-FULL-GATE-REV`; infrastructure → `M6-CP3-TB67A-P13-ARRANGEMENT-WEDGE-ORCH` |
| 8 (Review, parallel with 3–7) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) → CB → TB | Probe DEFN, then exact patch |
| 9 (Review, after 7) | `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (P13-f) → CB → TB | Probe DEFN; must name Vase's next failure, or a PASS, within 600 s |
| 10 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB68-P13-REVERT-INCIDENCE-BOUNDARY-PROBE** (Code; exact revert, no build).

Read first:
- [RA-194](Architecture_M6_CP3_DEFN_P13_Vase_Landed_Incidence_Probe_Revert_20261101.md): §2 findings on the landed patch, §3 renumbering, §4 CB68, §6 the exact revert, §5 turn order.
- [RA-193](Architecture_M6_CP3_DEFN_P13_Vase_Arrangement_Rotation_Probe_Adjudication_20261101.md): §5–§8 specs and §10–§11 patches for CB69 (its "CB67") and CB70 (its "CB68"). DESIGN.md Amendment 26 for the semantics.
- The [Vase decision](Architecture_M6_CP3_DEFN_P13_Vase_Completion_Incidence_Review_Decision_20261101.md) is history: its F1 rule stands; its CB67 contract is superseded (RA-193.1) and its landed patch is reverted (RA-194).
- [TB65 report](Architecture_M6_CP3_TB65_P13_Slit_Full_Gate_Execution_Report_20261101.md) for the last executed gate; do not re-run TB65.

Inputs:

| Input | Value |
|---|---|
| CB68 base | HEAD source = `911840c1…` + `829a47b2d` (uncompiled); CB68 restores `911840c1…` |
| CB69 base | Source `911840c195b52ce1800b3ac7ff3ea7380137ad9c` (after CB68) |
| TB66 gate | TB65 manifest 869 `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466`, unchanged; ledger v5 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; membership 950 |
| TB67 gate | Manifest 871 `Architecture_M6_TB67_P13_Arrangement_Wedge_Full_Gate_Case_Manifest.tsv` `434e6d373c327d909f6b458fb9b10bd8cdac5d3c073dfefe11fbb30ee34a385b` (TB65 869 byte-identical prefix plus rows 870–871); same ledger; membership 952 |
| Census | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Harness | P8 `78b8002c…`, unchanged |

Standing state: CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted. O16 (macOS), O17, O19, P13-e, P13-f, DR1/DR3, DR2/DR4 and O6/O9 are carried.

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
