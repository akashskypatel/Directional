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
| Currency | 2026-10-31 **TB61 Linux eight-target gate independently confirmed / CLI+GUI Linux compile evidence outstanding**; [TB61 execution report](Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md). CB62 GMP Linux package `13034987618` (semantic SHA `e7c27b0a5f53…`) executed unchanged at [run 41182654107](https://github.com/akashskypatel/Directional/actions/runs/41182654107): **863/863 PASS**, postflight true, exit 0, membership 945. TB60 macOS 862/863 remains platform-specific O16 (row 283); no CP3 acceptance. DR1/DR3 open; DR2/DR4 → M8-CP2. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB61 Linux 863/863 PASS, independently checked on eight targets**, artifact `13037097822`, run `41182654107`; [execution report](Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md). TB60 macOS 862/863, only row 283 O16, remains distinct ([TB60 report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md)). **TB61 863/863** is the latest independently reviewed Linux candidate (eight targets only). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Ledger v4 retains 82 DEFERRED: FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. TB61 Linux gate 863/863 (854 GUARD, 9 POSITIVE), membership 945, rows 854–863 PASS, row 283 Linux PASS versus macOS TB60 RED (O16 carried). No new Linux regression identified; selector497 remains unpromoted. |
| Active boundary | **TB61 independent review closed; NEXT `M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE`**: Linux gate and full-history review checks pass, but CB62 omitted Linux CLI/GUI targets. Follow the bounded [CB63 plan](Architecture_M6_CB63_Linux_CLI_GUI_Compile_Plan_20261031.md); do not begin P13 or promote CP3. |

## Mandatory next turn — `M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE` (Code + Build) — EXACT NEXT

- **Owner-authorized 2026-10-31.** Follow the [bounded compile plan](Architecture_M6_CB63_Linux_CLI_GUI_Compile_Plan_20261031.md) and the independent [TB61 review](Architecture_M6_TB61_Linux_Full_Gate_Independent_Review_20261031.md). The existing CB62 eight-target package omitted Linux CLI/GUI because both CMake options were OFF; the reusable compile workflow presently hardcodes these OFF. A mere dispatcher target-list change cannot repair the compile configuration.
- **Objective:** perform the minimal workflow/build correction, compile/link **both Linux CLI and GUI** alongside the same eight targets under GMP/GMPXX, and package exact compile evidence. **Code + Build only:** do not run product binaries, tests, benchmarks or GUI, and do not change product/test/fixture/selector semantics.
- **Falsifiers:** non-ON CMake flags, missing `directional`/`directional-ui` compiled target/binary, failed link/GMP/GMPXX receipt, wrong source SHA, incomplete package manifest, or `runtimeExecution` not false. Preserve all failure evidence.
- **Authorized successor on successful compile:** `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC` (immutable artifact-only full 863-case gate plus separately registered CLI/GUI verification). A semantic RED follows Review + Plan; orchestration failure follows corrective CB. **No P13** until that verification is adjudicated.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | RP-01 closure (RA-174…RA-179) → O15 (RA-180/RA-181) → row 935 (RA-182, TB55) → O2 entry gate (RA-183, TB56) → DIAG-RETAIN snapshots (RA-184, CB58, TB57) → display adapter (RA-185, CB59, TB58) → CLI sidecar (RA-186, CB60, TB59) → GUI layers (RA-187, CB61, TB60): DIAG-RETAIN closed | — | History is in `CHANGELOG.md` and the records. Latest independently reviewed Linux eight-target gate: TB61 863/863 PASS; TB60 macOS 862/863 remains carried O16 row 283. The ledger v4 has 82 deferred; membership 945. |
| 1 — NEXT | `M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE` | CB / I | Owner-authorized Linux CLI+GUI compile/link evidence; 8 existing targets + both executables, GMP/GMPXX, runtime-free; [exact plan](Architecture_M6_CB63_Linux_CLI_GUI_Compile_Plan_20261031.md). |
| 2 — on CB63 success | `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC` | TB-EXEC / I | Immutable full 863-case gate, membership 945, registered CLI checks and GUI link evidence. No rebuild or repair. |
| 2b — after verification | `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` (Cylinder first; O6, exact-atlas, O9 and O15c) | DEFN / R | Conditional on discharged Linux platform compile debt and TB verification; RA-174.3, ledger v4 P13 rows 360/362/365, 300-second bounded probes. |
| 3 | retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | DR1 (needs an A6/A7 rejection stimulus), DR3, DR2 and DR4 (→ M8-CP2); O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). CB and TB run on the Linux workflow runner; a TB always runs the full current gate, even after a CLI- or GUI-only CB (RA-187). The current gate is the TB58 manifest (863 rows) with ledger v4 (82). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE** (CB, runtime-free). Read [exact build plan](Architecture_M6_CB63_Linux_CLI_GUI_Compile_Plan_20261031.md), [TB61 independent review](Architecture_M6_TB61_Linux_Full_Gate_Independent_Review_20261031.md), [CB62 build record](Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md), `.github/workflows/agent-compile-reusable.yml`, `.github/workflows/agent-operation-dispatcher.yml`, and the GMP/workflow policies. CB62 flags both CLI/GUI OFF; ten-target Linux build with both flags ON is owed. On compiled package success, separate `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC` must execute the full frozen 863-case TB58 gate, ledger v4 82, membership 945 plus registered CLI/GUI checks. Full-history review-check on [run 41200958419](https://github.com/akashskypatel/Directional/actions/runs/41200958419) passed both `boundary` and `ledgers` on unshallow history. Accepted CP2 491/491 unchanged, stable 66/17/49 debt 1, O16 macOS separate; P13 and selector497 remain deferred.

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
