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
| Currency | 2026-10-31 **RA-186 CLI sidecar DEFN** ([record](Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md); local). The CLI writes `<prefix>.materialization.txt` from the CB59 dump before its produced-result check, when the snapshots are retained. A CLI-ON probe pins three runs (A–C). New **DR4**: the existing `--diagnostics-prefix` cut-mesh sidecars throw on every SurfaceCells product (pre-existing, M8-CP2). CB60 `d14aaeff…`; GUI layers → their own DEFN. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB58 862/1 local candidate** (CB59 `39a77d2e…`, 863 gated; [report](Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Local_Test_Report_20261031.md)). The prior reviewed local candidate is TB54 856/1 (RA-181). **TB52 853/0** is the latest reviewed Linux candidate (RA-177). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 82 DEFERRED ([ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv)): FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. RP-01 closed (RA-179); O15 discharged (RA-181); O15c is owned by P13. Linux CI confirmation of rows 854–859 is carried. Local mode: row 283 (O16) is pre-registered. |
| Active boundary | **NEXT `M6-CB60-DIAG-RETAIN-CLI-SIDECAR`** (CB, local): the exact RA-186.7 patch, built CLI-ON (`directional_cli` only). Then TB59-EXEC: the three registered CLI runs. CP2 491/491 last accepted; CP3 not accepted. |

## Mandatory next turn — `M6-CB60-DIAG-RETAIN-CLI-SIDECAR` (type CB; run locally) — EXACT NEXT

- **Authority:** [RA-186](Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md) §.4 and §.7.
- **Patch:** the RA-186.7 block, extracted verbatim with a trailing newline. Its SHA-256 must be `d14aaeff98b662c70e49f0a64f3dfad4df355e97320301a6341d4d7ad2e2a784`. Apply it with `git apply`; the numstat must be exactly `12 0` (`src/cli/RemeshCommand.cpp`) and `2 0` (`src/cli/Usage.cpp`). The resulting SHA-256 values are in RA-186.4.
- **Build:** commit; a clean worktree with the CI flags **plus `-DDIRECTIONAL_BUILD_CLI=ON`**, building only `directional_cli`; stage `bin/directional` with the standard metadata under `build/local-evidence/CB60/`. Haiku may stage it; verify the result. No native runs.
- **Outcomes:**
  - All exact → `M6-TB59-DIAG-RETAIN-CLI-EXEC` (runs A–C of RA-186.3/§.5; a registered pass leads to `M6-DEFN-DIAG-RETAIN-GUI-LAYERS` with no REV).
  - Mismatch → `M6-PLAN-DIAG-RETAIN-CLI-STOP`.
  - Infrastructure failure → `M6-CB60A-DIAG-RETAIN-CLI-ORCH`.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | RP-01 closure (RA-174…RA-179) → O15 (RA-180/RA-181) → row 935 (RA-182, TB55) → O2 entry gate (RA-183, TB56) → DIAG-RETAIN snapshots (RA-184, CB58, TB57) → display adapter (RA-185, CB59, TB58) → CLI sidecar DEFN (RA-186) | — | History is in `CHANGELOG.md` and the records. Local baseline TB58 862/863: 863 gated, [ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv) 82, membership 945. |
| 1 — NEXT | `M6-CB60-DIAG-RETAIN-CLI-SIDECAR` → `M6-TB59-DIAG-RETAIN-CLI-EXEC` → `M6-DEFN-DIAG-RETAIN-GUI-LAYERS` | CB, TB-EXEC / local; DEFN / R | CLI-ON build and three registered runs; then a GUI-ON build probe. The five-binary gate is unchanged (TB58). |
| 2 | P13 probe DEFN (Cylinder first, which passes locally in 179 s; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | Linux CI confirmation (rows 854–859); DR1 (needs an A6/A7 rejection stimulus), DR3, DR2 and DR4 (→ M8-CP2); O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). Local mode: `tools/m6_cp3_local_gate_driver.py`; packages at default arithmetic (RA-180.5); row 283 (O16) is pre-registered. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CB60-DIAG-RETAIN-CLI-SIDECAR** (CB, run locally). Read [RA-186](Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md) §.3–§.5 and §.7. Extract and verify the patch (`d14aaeff…`, numstats `12 0` / `2 0` and both file SHAs), apply and commit it, build `directional_cli` CLI-ON and stage it. Next is TB59-EXEC (runs A–C). Local gate baseline TB58 862/863 (membership 945). CP2 491/491 last accepted; stable 66/17/49, debt 1.

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
