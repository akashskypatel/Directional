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
| Currency | 2026-10-31 **CB65 exact patch and Linux compile COMPLETE.** [CB65 report](Architecture_M6_CP3_CB65_P13_Canonical_Dyadic_Trace_Exit_Code_Build_Report_20261031.md). RA-190's accepted dyadic exit and frozen TB64 gate remain normative; next is immutable TB64 execution. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation; immutable semantic source `dbc38661efabdfa051f48f8f71ee3c604841842c`. |
| Last accepted semantic runtime | **CP2 491/491**, accepted 2026-10-06, unchanged. TB63 is a verified Linux candidate, not selector497/CP3 acceptance. |
| Latest candidate | **CB65 compile-only eight-target Linux** [run 41253674256](https://github.com/akashskypatel/Directional/actions/runs/41253674256), artifact `13062413347`, source `dbc38661efabdfa051f48f8f71ee3c604841842c`. Latest runtime remains TB63 863/863 (run 41224438897, result 13051413577), plus P13 census 1 PASS / 2 expected RED. macOS O16 remains. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Ledger v5 81 rows (47 FIXTURE, 7 PRODUCT, 22 OPEN, 5 RETIRE). TB64 gate membership 947. Selector497 not promoted. DR1/DR3 open; DR2/DR4 → M8-CP2. |
| Active boundary | **CB65 runtime untested.** RA-190 probe evidence: 864 candidate 863/864 (O16), 74 rounding cases PASS, 81/81 deferred verdicts unchanged. Vase passes A4, then fails at `SideSubdivisionRepair:InvalidInputIncidence` (P13-d); BunnyRandom A3 single-edge slit (P13-c) remains. No CP3 acceptance. |

## Mandatory next turn — `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` — EXACT NEXT

- **Type / owner:** TB-EXEC, implementation agent, Linux workflow runner. Artifact-only immutable execution; **no rebuild, implementation repair, tests source edits or benchmark source edits**.
- **Authority:** [RA-190 §6](Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md), [CB65 compile record](Architecture_M6_CP3_CB65_P13_Canonical_Dyadic_Trace_Exit_Code_Build_Report_20261031.md), Turn Cadence, frozen gate and deferred ledger.
- **Immutable source/package:** `dbc38661efabdfa051f48f8f71ee3c604841842c`, artifact `13062413347`, ZIP SHA-256 `1a2ab39d43742cfa5d3b7b2c09242482ef63712b2efbaf9644a54b83e2b0948b`, root manifest SHA-256 `0c69aaea7a2eea6d1a9fe1fcd78724a0c3a320f757357de0b07aece738286ff5`, source archive SHA-256 `c30b58f0aa85375480ed7d794c543faa59f5c613480dba1aaa3df0647cbd3ba5`. Verify all before executing.
- **Gate:** `Architecture_M6_TB64_P13_Dyadic_Exit_Full_Gate_Case_Manifest.tsv` 866 rows (`289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce`); deferred `MEMBERSHIP_LEDGER` v5, 81 rows (`fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`). Expected **866/866**, membership **947**.
- **Independent census:** TB63 three-case P13 manifest (`3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`), no ledger:
  - Cylinder PASS.
  - BunnyRandom RED `CutTransportDomainIdentityMismatch`, `cutChi=-3`.
  - Vase RED `terminal=NotProductionReady:completion`, `completion=SideSubdivisionRepair:InvalidInputIncidence`, no `BranchContinuationExactMagnitudeExceeded`.
- **Outcomes:** Matching → advance according to RA-190 authority; mismatch → `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-REV` (Review); infrastructure → `M6-CP3-TB64A-P13-CANONICAL-DYADIC-ORCH`.

## Turn Sequence

| Step | Canonical turn | Track / condition |
|---|---|---|
| 1 — NEXT | `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` | TB-EXEC; implementation agent; Linux; immutable CB65 artifact; gate 866 + census 3 (RA-190.6) |
| 3 (Review, parallel with 1–2) | `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` (BunnyRandom, P13-c) → CB66 → TB65 | DEFN with probes on the Review track; then exact patch |
| 4 (Review, after 2) | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (P13-d plus O18) → CB → TB | DEFN with probes on the Review track; then exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC** (TB-EXEC, immutable CB65 artifact).

Read first:
- [RA-190](Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md): §6 is the TB64 gate/census and outcomes; §5/§8 are fulfilled CB65 patch history. Read the CB65 compile report for immutable package hashes.
- DESIGN.md Amendment 24 for the semantics. [RA-189](Architecture_M6_CP3_DEFN_P13_O15C_Continuation_Width_Review_20261031.md) is history: its §3 Cylinder promotion stands, and its §2 obligations and §4 scope are superseded.
- [TB63 report](Architecture_M6_CP3_TB63_P13_Census_Full_Gate_Execution_Report_20261031.md) for the prior immutable evidence.

Inputs:

| Input | Value |
|---|---|
| CB65 base | Source `d56d990580163f4fd0ceda4137f7ecd16ceb6027` (CB64); no semantic change since |
| TB64 gate | Manifest 866 `289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce`; ledger v5 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; membership 947. The 864-row RA-189 candidate `b50463ea…` is its byte-identical prefix and is not run on its own |
| TB64 census | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Harness | P8 `78b8002c…`, unchanged |

Standing state: CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted. O16 (macOS), O17, O18, DR1/DR3 and DR2/DR4 are carried.

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
