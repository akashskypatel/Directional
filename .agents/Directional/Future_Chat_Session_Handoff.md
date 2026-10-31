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
| Currency | 2026-10-31 **[RA-190](Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md) closed `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH`.** It keeps RA-189's dyadic exit and Cylinder promotion, corrects the design (one site in the resolver, open grid, no certificates or receipts), and freezes the exact CB65 patch and the TB64 866-row gate. The boundary checker passes on an authentic checkout. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | **CP2 491/491**, accepted 2026-10-06, unchanged. TB63 is a verified Linux candidate, not selector497/CP3 acceptance. |
| Latest candidate | **TB63 Linux eight-target 863/863** [run 41224438897](https://github.com/akashskypatel/Directional/actions/runs/41224438897), result `13051413577`; CB64 package `13050072901`, source `d56d9905…`. P13 census 1 PASS / 2 expected RED, result `13051470763`. macOS O16 remains. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Ledger v5: 81 rows (47 FIXTURE, 7 PRODUCT, 22 OPEN, 5 RETIRE). Membership becomes 947 after CB65 (two new tests). Selector497 not promoted. DR1/DR3 open; DR2/DR4 → M8-CP2. |
| Active boundary | RA-190 probes, macOS, diagnostic only. With the dyadic exit, the 864-row candidate gives 863/864 (only O16), and all 74 rounding rows pass. 81/81 deferred rows have unchanged verdicts. **Vase passes A4** and fails later at completion, `SideSubdivisionRepair:InvalidInputIncidence` (P13-d). Uncapped exact arithmetic fails at the same place. BunnyRandom's slit (P13-c) is unchanged. No CP3 acceptance. |

## Mandatory next turn — `M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT` — EXACT NEXT

- **Type / owner:** CB, implementation agent, Linux workflow runner. Exact patch only; no design latitude.
- **Authority:** [RA-190.5 / RA-190.8](Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md). RA-190 supersedes RA-189 §4's scope. DESIGN.md Amendment 24 is normative.
- **Precheck:** `git diff --quiet d56d990580163f4fd0ceda4137f7ecd16ceb6027 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** the RA-190.8 block, verbatim plus a trailing newline, SHA-256 `ed125319bb38f9ed5352c8b18b3513a53dc5e994d3e7f964d27f82341ac6f91b`.
  - Run `git apply --check`, then apply.
  - Numstat: `26 1` `SurfaceCellTracing.h`, `26 2` `SurfaceCellTracing.cpp`, `79 0` `FieldAlignedCurveNetworkTests.cpp`, `2 1` `SurfaceCellDesignAcceptanceTests.cpp`.
  - Result SHA-256 values are in RA-190.5.
- **Build:** `agent-compile-reusable.yml` with CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI/GUI OFF), eight targets.
  - Record the artifact ID, the ZIP and root `SHA256SUMS` SHA-256, and the source-archive SHA-256.
  - No native runs.
- **Outcomes:**
  - Exact → `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC`.
  - Patch, numstat or compile mismatch → `M6-CP3-PLAN-P13-DYADIC-EXIT-STOP` (Review).
  - Infrastructure → `M6-CP3-CB65A-P13-DYADIC-EXIT-ORCH` (one retry).
- **Then TB64** (TB-EXEC; implementation agent; Linux), on the immutable CB65 package.
  - **Gate:** manifest `Architecture_M6_TB64_P13_Dyadic_Exit_Full_Gate_Case_Manifest.tsv` (866 rows, `289d887c7d1eedcdfdc42c5869055915abf5aec8a0436a62e67acf566a99dbce`) with `MEMBERSHIP_LEDGER` v5 (81 rows, `fd433f54…`). Pre-registered **866/866**, membership **947**.
  - **Census:** the TB63 census manifest `3af1dc0d…`, no ledger, pre-registered as:
    - Cylinder PASS.
    - BunnyRandom RED `CutTransportDomainIdentityMismatch` `cutChi=-3`.
    - Vase RED `terminal=NotProductionReady:completion` with `completion=SideSubdivisionRepair:InvalidInputIncidence` and no `BranchContinuationExactMagnitudeExceeded`.
  - **Mismatch** → `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-REV`. **Infrastructure** → `M6-CP3-TB64A-P13-CANONICAL-DYADIC-ORCH`.

## Turn Sequence

| Step | Canonical turn | Track / condition |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT` | CB; implementation agent; Linux; RA-190.8 exact patch |
| 2 | `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` | TB-EXEC; implementation agent; Linux; gate 866 + census 3 (RA-190.6); no REV if everything matches |
| 3 (Review, parallel with 1–2) | `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` (BunnyRandom, P13-c) → CB66 → TB65 | DEFN with probes on the Review track; then exact patch |
| 4 (Review, after 2) | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (P13-d plus O18) → CB → TB | DEFN with probes on the Review track; then exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB65-P13-CANONICAL-DYADIC-TRACE-EXIT** (CB, exact patch).

Read first:
- [RA-190](Architecture_M6_CP3_DEFN_P13_O15C_Dyadic_Exit_Probe_Adjudication_20261031.md): §5 is the CB65 spec, §6 the TB64 inputs and outcomes, §8 the exact patch.
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
