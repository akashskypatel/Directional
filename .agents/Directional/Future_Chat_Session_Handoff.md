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
| Currency | 2026-10-31 **RA-187 GUI layers DEFN** ([record](Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md); local). CB61 adds three read-only GUI layers over the CB59 adapter; it compiles and links GUI-ON. Correction: TB59 ran only the CLI cases, but every TB must run the full gate, so CB61 builds the gate targets with the CLI and GUI, and TB60 runs the 863-row gate plus the CLI cases. CB61 `afab7d5d…`. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB58 862/1 local candidate** (CB59 `39a77d2e…`, 863 gated; [report](Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Local_Test_Report_20261031.md)). The prior reviewed local candidate is TB54 856/1 (RA-181). **TB52 853/0** is the latest reviewed Linux candidate (RA-177). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 82 DEFERRED ([ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv)): FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. RP-01 closed (RA-179); O15 discharged (RA-181); O15c is owned by P13. Linux CI confirmation of rows 854–859 is carried. Local mode: row 283 (O16) is pre-registered. |
| Active boundary | **NEXT `M6-CB61-DIAG-RETAIN-GUI-LAYERS`** (CB, local): the exact RA-187.7 patch, built CLI-ON and GUI-ON (eight gate targets plus `directional_cli` and `directional_gui`). Then TB60-EXEC: the 863-row gate, the three CLI cases and a GUI link check. CP2 491/491 last accepted; CP3 not accepted. |

## Mandatory next turn — `M6-CB61-DIAG-RETAIN-GUI-LAYERS` (type CB; run locally) — EXACT NEXT

- **Authority:** [RA-187](Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md) §.4 and §.7.
- **Patch:** the RA-187.7 block, extracted verbatim with a trailing newline. Its SHA-256 must be `afab7d5dc08ec1976b0ef36b22c34757b295f6b010753edf2b26fa7565983e4e`. Apply it with `git apply`; the numstat must be exactly `5 0` (`src/gui/GuiBackend.h`), `5 0` (`src/gui/GuiRemesh.cpp`) and `52 8` (`src/gui/Main.cpp`). The resulting SHA-256 values are in RA-187.4.
- **Build:** commit; a clean worktree with the CI flags **plus `-DDIRECTIONAL_BUILD_CLI=ON -DDIRECTIONAL_BUILD_GUI=ON`**; build the eight gate targets, `directional_cli` and `directional_gui`; stage `pkg.zip` (standard eight-target layout) and `tools.zip` (`bin/directional`, `bin/directional-ui`) under `build/local-evidence/CB61/`. Haiku may stage them; verify the result. No native runs.
- **Outcomes:**
  - All exact → `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC` (gate `31c1360a…` 863, ledger v4 82, membership 945, row 283 the only pre-registered red; CLI checks with `build/local-evidence/TB59/tb59_check.sh`; GUI link check; a registered pass closes DIAG-RETAIN and leads to the P13 probe DEFN with no REV).
  - Mismatch → `M6-PLAN-DIAG-RETAIN-GUI-STOP`.
  - Infrastructure failure → `M6-CB61A-DIAG-RETAIN-GUI-ORCH`.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | RP-01 closure (RA-174…RA-179) → O15 (RA-180/RA-181) → row 935 (RA-182, TB55) → O2 entry gate (RA-183, TB56) → DIAG-RETAIN snapshots (RA-184, CB58, TB57) → display adapter (RA-185, CB59, TB58) → CLI sidecar (RA-186, CB60, TB59; full-gate TB pending in TB60) → GUI layers DEFN (RA-187) | — | History is in `CHANGELOG.md` and the records. Local baseline TB58 862/863: 863 gated, [ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv) 82, membership 945. |
| 1 — NEXT | `M6-CB61-DIAG-RETAIN-GUI-LAYERS` → `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC` | CB, TB-EXEC / local | One CLI+GUI-ON build; TB60 = 863-row gate (862/863 expected) + CLI 11/11 + GUI link. Closes DIAG-RETAIN. |
| 2 | P13 probe DEFN (Cylinder first, which passes locally in 179 s; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | Linux CI confirmation (rows 854–859); DR1 (needs an A6/A7 rejection stimulus), DR3, DR2 and DR4 (→ M8-CP2); O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). Local mode: `tools/m6_cp3_local_gate_driver.py`; packages at default arithmetic (RA-180.5); row 283 (O16) is pre-registered. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CB61-DIAG-RETAIN-GUI-LAYERS** (CB, run locally). Read [RA-187](Architecture_M6_DEFN_Diag_Retain_GUI_Layers_20261031.md) §.4, §.5 and §.7. Extract and verify the patch (`afab7d5d…`, numstats `5 0` / `5 0` / `52 8` and the three file SHAs), apply and commit it, build CLI-ON and GUI-ON (eight gate targets plus CLI and GUI), and stage `pkg.zip` and `tools.zip`. Next is TB60-EXEC (gate 863 `31c1360a…`, membership 945, row 283 the only expected red; CLI 11/11; GUI link). CP2 491/491 last accepted; stable 66/17/49, debt 1.

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
