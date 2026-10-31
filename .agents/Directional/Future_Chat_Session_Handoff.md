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
| Currency | 2026-10-31 **CB63 Linux ten-target Release/static/GMP compile package independently verified / TB62 artifact-only gate outstanding**; [TB61 execution report](Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md). CB62 GMP Linux package `13034987618` (semantic SHA `e7c27b0a5f53…`) executed unchanged at [run 41182654107](https://github.com/akashskypatel/Directional/actions/runs/41182654107): **863/863 PASS**, postflight true, exit 0, membership 945. TB60 macOS 862/863 remains platform-specific O16 (row 283); no CP3 acceptance. DR1/DR3 open; DR2/DR4 → M8-CP2. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB61 Linux 863/863 PASS, independently checked on eight targets**, artifact `13037097822`, run `41182654107`; [execution report](Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md). TB60 macOS 862/863, only row 283 O16, remains distinct ([TB60 report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md)). **TB61 863/863** is the latest independently reviewed Linux candidate (eight targets only). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Ledger v4 retains 82 DEFERRED: FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. TB61 Linux gate 863/863 (854 GUARD, 9 POSITIVE), membership 945, rows 854–863 PASS, row 283 Linux PASS versus macOS TB60 RED (O16 carried). No new Linux regression identified; selector497 remains unpromoted. |
| Active boundary | **CB63 compile/package closed; NEXT `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC`**: exact Linux ten-target GMP package `13043004468`, source `f6113c4e…`, [build report](Architecture_M6_CB63_Linux_CLI_GUI_Code_Build_Report_20261031.md). Follow [TB62 plan](Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Plan_20261031.md) for full immutable gate plus CLI checks. No P13 or CP3 promotion. |

## Mandatory next turn — `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC` (Test + Benchmark) — EXACT NEXT

- **Owner-authorized 2026-10-31.** Follow the [frozen TB62 plan](Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Plan_20261031.md) and the [CB63 build report](Architecture_M6_CB63_Linux_CLI_GUI_Code_Build_Report_20261031.md). CB63 compiled the original eight targets plus Linux CLI/GUI with the CMake switches ON and generated GMP/GMPXX link receipts; package `13043004468` SHA-256 `14b7589aba85ed1fa0fdf62d233007293150491d559820dc2b24b8e83df27462`.
- **Objective:** run the full 863-case frozen TB58 gate, preserve 82 DEFERRED (membership 945), and run separately registered existing Linux CLI checks against the immutable CB63 package. Verify GUI artifact/link receipts without GUI launch. **Artifact-only TB:** do not configure, compile, relink, rebuild or repair.
- **Falsifiers:** mismatched source/package/checksums, missing/extra case identities, wrong membership, unreconciled CLI checks, mutated package, rebuild or relink, failed postflight, or unsupported GUI display claim. Preserve all failure evidence.
- **After TB62:** route results under `Turn_Cadence.md`: semantic RED to independent Review + Plan, orchestration failure to corrective CB; any positive TB62 platform-coverage adjudication remains required before P13. No premature CP3 or selector promotion.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | RP-01 closure (RA-174…RA-179) → O15 (RA-180/RA-181) → row 935 (RA-182, TB55) → O2 entry gate (RA-183, TB56) → DIAG-RETAIN snapshots (RA-184, CB58, TB57) → display adapter (RA-185, CB59, TB58) → CLI sidecar (RA-186, CB60, TB59) → GUI layers (RA-187, CB61, TB60): DIAG-RETAIN closed | — | History is in `CHANGELOG.md` and the records. Latest independently reviewed Linux eight-target gate: TB61 863/863 PASS; TB60 macOS 862/863 remains carried O16 row 283. The ledger v4 has 82 deferred; membership 945. |
| done | `M6-CB63-DIAG-RETAIN-LINUX-CLI-GUI-COMPILE` | CB / I | Ten targets compile/link under GMP/GMPXX; package `13043004468`, source `f6113c4e…`, [CB63 report](Architecture_M6_CB63_Linux_CLI_GUI_Code_Build_Report_20261031.md). |
| 2 — NEXT | `M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC` | TB-EXEC / I | Immutable `13043004468`: full 863-case gate, membership 945, registered Linux CLI checks and GUI link evidence. No rebuild or repair; [plan](Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Plan_20261031.md). |
| 2b — after verification | `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` (Cylinder first; O6, exact-atlas, O9 and O15c) | DEFN / R | Conditional on discharged Linux platform compile debt and TB verification; RA-174.3, ledger v4 P13 rows 360/362/365, 300-second bounded probes. |
| 3 | retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | DR1 (needs an A6/A7 rejection stimulus), DR3, DR2 and DR4 (→ M8-CP2); O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). CB and TB run on the Linux workflow runner; a TB always runs the full current gate, even after a CLI- or GUI-only CB (RA-187). The current gate is the TB58 manifest (863 rows) with ledger v4 (82). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-TB62-DIAG-RETAIN-LINUX-CLI-GUI-FULL-GATE-EXEC** (artifact-only TB). Read [TB62 frozen plan](Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Plan_20261031.md), [CB63 verified report](Architecture_M6_CB63_Linux_CLI_GUI_Code_Build_Report_20261031.md), [TB61 independent review](Architecture_M6_TB61_Linux_Full_Gate_Independent_Review_20261031.md), `GitHub_Workflow_Policy.md`, `Turn_Cadence.md` and GMP/TB policies. Immutable package artifact `13043004468` from compile run `41202931582`, source `f6113c4eb0fbf6a02350eee2d37e7e4dab821429`, SHA-256 `14b7589aba85ed1fa0fdf62d233007293150491d559820dc2b24b8e83df27462`, 30/30 hashes verified. Ten targets compiled Release/static; CLI/GUI CMake flags ON, binaries present and generated GMPXX/GMP links proved. No native runtime was executed during CB63. TB62 must execute full frozen 863-case TB58 gate, ledger v4 82 (membership 945), plus registered Linux CLI checks and GUI artifact/link verification, all without rebuild or repair. Accepted CP2 491/491 unchanged; Linux TB61 863/863 remains eight-target previous candidate; stable 66/17/49 debt 1, macOS O16 separate. P13/selector497/CP3 promotion remain deferred.

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
