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
| Currency | 2026-10-31 **CB58 + TB57 local** ([CB58 record](Architecture_M6_CB58_Diag_Retain_A5_A7_Snapshots_Code_Build_Record_20261031.md), [TB57 report](Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md)). The exact RA-184.7 patch is built (source `58ddfef0…`, package `241aeebd…`) and the 861-row gate gives the pre-registered **860/861** (only row 283, O16), membership 943. The A5–A7 diagnostic snapshots are landed; DR1–DR3 stay open ([RA-184](Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md) §.4). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB57 860/1 local candidate** (CB58 `58ddfef0…`, 861 gated; [report](Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md)). The prior reviewed local candidate is TB54 856/1 (RA-181). **TB52 853/0** is the latest reviewed Linux candidate (RA-177). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 82 DEFERRED ([ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv)): FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. RP-01 closed (RA-179); O15 discharged (RA-181); O15c is owned by P13. Linux CI confirmation of rows 854–859 is carried. Local mode: row 283 (O16) is pre-registered. |
| Active boundary | **NEXT `M6-DEFN-DIAG-RETAIN-CLI-GUI`** (DEFN, R, local): expose the retained snapshots through a CLI diagnostics dump and GUI display layers, and rule on DR2. CP2 491/491 last accepted; CP3 not accepted. |

## Mandatory next turn — `M6-DEFN-DIAG-RETAIN-CLI-GUI` (type DEFN; Review track, run locally) — EXACT NEXT

- **Authority:** the user-directed DIAG-RETAIN item (`TODO.md`) and [RA-184](Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md) §.4 (DR2). The snapshots exist as of CB58 (`SurfaceCellDiagnosticProductSnapshots::occurrenceComplex`, `quotientProduct`, `sourceAttachedGeometry`).
- **Scope:**
  - Inventory the consumers: the CLI retention flag (`src/cli/RemeshCommand.cpp`, `--surface-cell-preserve-debug-artifacts`), which reads no snapshots, and the GUI snapshot readers (`src/gui/GuiRemesh.cpp`).
  - Define a CLI diagnostics dump of the three products and the GUI display layers. Both must be read-only observers with no admission, return-value or ordering change.
  - Rule on DR2: merge per-component snapshots in the multi-component path, or expose them per component.
  - The CI flag set builds neither the CLI nor the GUI (`DIRECTIONAL_BUILD_CLI=OFF`, `DIRECTIONAL_BUILD_GUI=OFF`). The DEFN must say how each CB builds and tests its layer, for example through a testable adapter in `directional_pipeline`, as the A2a network layer did.
  - Probe the patches, then freeze one exact CB per layer and its gate manifest (TB57's 861 plus the new rows; ledger v4 82).
- **Outcomes:**
  - Frozen CBs → the first CB, then its TB.
  - Not expressible as a read-only observer → `M6-PLAN-DIAG-RETAIN-CLI-GUI-STOP`.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | RP-01 closure (RA-174…RA-179) → O15 (RA-180/RA-181) → row 935 (RA-182, TB55) → O2 entry gate (RA-183, TB56) → DIAG-RETAIN snapshots (RA-184, CB58, TB57) | — | History is in `CHANGELOG.md` and the records. Local baseline TB57 860/861: 861 gated, [ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv) 82, membership 943. |
| 1 — NEXT | `M6-DEFN-DIAG-RETAIN-CLI-GUI` → its CB/TB pairs (CLI dump; GUI layers) | DEFN / R; CB, TB-EXEC / local | Read-only observers of the CB58 snapshots; DR2 ruled. |
| 2 | P13 probe DEFN (Cylinder first, which passes locally in 179 s; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | Linux CI confirmation (rows 854–859); DR1 (needs an A6/A7 rejection stimulus), DR3; O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). Local mode: `tools/m6_cp3_local_gate_driver.py`; packages at default arithmetic (RA-180.5); row 283 (O16) is pre-registered. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-DEFN-DIAG-RETAIN-CLI-GUI** (DEFN, Review track, run locally). Read [RA-184](Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md) §.1–§.4 and the [TB57 report](Architecture_M6_TB57_Diag_Retain_Full_Gate_Local_Test_Report_20261031.md). Inventory the CLI and GUI snapshot consumers, define the dump and display layers as read-only observers, rule on DR2, decide how the CLI/GUI layers are built and tested under the CI flags, then probe and freeze one exact CB per layer. Local baseline TB57 860/861 (membership 943). CP2 491/491 last accepted; stable 66/17/49, debt 1.

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
