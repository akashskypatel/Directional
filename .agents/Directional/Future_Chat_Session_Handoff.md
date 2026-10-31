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
| Latest candidate or rejected evidence | **TB61 Linux 863/863 PASS, independently checked on eight targets**, artifact `13037097822`, run `41182654107`; [execution report](Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md). TB60 macOS 862/863, only row 283 O16, remains distinct ([TB60 report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md)). **TB52 853/0** remains latest reviewed Linux candidate until TB61-REV. Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Ledger v4 retains 82 DEFERRED: FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. TB61 Linux gate 863/863 (854 GUARD, 9 POSITIVE), membership 945, rows 854–863 PASS, row 283 Linux PASS versus macOS TB60 RED (O16 carried). No new Linux regression identified; no stable promotion before TB61-REV. |
| Active boundary | **CURRENT `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV`**: Linux gate independently verified, but CB62 CMakeCache turns CLI/GUI OFF. Pending review closeout and authorization of a bounded Linux CLI/GUI compile+verification successor; do not begin P13 or promote CP3. |

## Mandatory next turn — `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` (type TB-REV; independent Review track) — EXACT NEXT

- **Authority:** [TB61 immutable execution report](Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md), [CB62 package record](Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md), [TB60 macOS report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md), RA-187 and the frozen 863-row TB58 manifest / deferred ledger v4.
- **Review evidence (independently verified):** TB61 result artifact `13037097822` (ZIP SHA-256 `5e62807c270d9124688dd280a0af718900f5bbabd4ec678107745ca1a648acc8`), harness log artifact `13037416966`, reusable log `13037536687`, and orphan-mailbox run `41182654107` at source `e7c27b0a5f53788569109c85a028e3be44035aaf`. The execution agent measured 863/863 PASS, postflight true, harness exit 0, membership 863+82=945.
- **Adjudication:** compare every verdict against TB60's macOS 862/863 (sole row 283 O16), verify rows 854–863 individually (all PASS on TB61), classify the platform distinction under RA-176 without silently declaring O16 repaired, and decide whether Linux CB60 CLI / CB61 GUI compilation is still owed. Confirm scope adequacy, package integrity, status of any regression candidates, and project gates.
- **Out of scope:** implementation, test, benchmark or selector edits, independent runtime execution in this review, CP3 promotion, or P13 probes.
- **Conditional successor (compile debt is present, not discharged):** confirmed Linux gate and no outstanding platform compile debt → `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`; confirmed Linux-only RED/determinism defect → `M6-PLAN-DIAG-RETAIN-LINUX-SPLIT-STOP`; if additional Linux CLI/GUI compile evidence is owed, plan an explicitly authorized bounded compile/verification turn before P13. Do not invent an unapproved successor ID.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | RP-01 closure (RA-174…RA-179) → O15 (RA-180/RA-181) → row 935 (RA-182, TB55) → O2 entry gate (RA-183, TB56) → DIAG-RETAIN snapshots (RA-184, CB58, TB57) → display adapter (RA-185, CB59, TB58) → CLI sidecar (RA-186, CB60, TB59) → GUI layers (RA-187, CB61, TB60): DIAG-RETAIN closed | — | History is in `CHANGELOG.md` and the records. Latest Linux gate: TB61 863/863 PASS (review pending); TB60 macOS 862/863 remains carried O16 row 283. The ledger v4 has 82 deferred; membership 945. |
| 1 — NEXT | `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` | TB-REV / R | TB61 Linux 863/863 PASS at run `41182654107`, source `e7c27b0a…`, result `13037097822`; review not yet completed. Compare TB60, O16 and CLI/GUI compile debt before conditional P13. |
| 2 | `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` (Cylinder first; O6, exact-atlas, O9 and O15c checks) | DEFN / R | RA-174.3 and the ledger v4 P13 rows 360 BunnyRandom (RED), 362 Cylinder, 365 Vase (CI timeout 124; Cylinder completed in 179 s in a probe without the CI limit). Bounded per-fixture probes (300 s); frozen P13 slices or a PLAN stop. |
| 3 | retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | DR1 (needs an A6/A7 rejection stimulus), DR3, DR2 and DR4 (→ M8-CP2); O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). CB and TB run on the Linux workflow runner; a TB always runs the full current gate, even after a CLI- or GUI-only CB (RA-187). The current gate is the TB58 manifest (863 rows) with ledger v4 (82). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV** (same-turn review closeout pending explicit Linux CLI/GUI successor authority). Read [independent review](Architecture_M6_TB61_Linux_Full_Gate_Independent_Review_20261031.md) and then [TB61 execution report](Architecture_M6_TB61_Diag_Retain_Linux_Full_Gate_Execution_Report_20261031.md) and artifacts `13037097822` (result), `13037416966` (harness log), `13037536687` (wrapper log), [CB62 package record](Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md), and [TB60 report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md). Exact run `41182654107` at source `e7c27b0a5f53788569109c85a028e3be44035aaf`; 863/863 PASS, 82 deferred, membership 945; row 283 Linux PASS/macOS RED O16; rows 854–863 PASS. Check a potential Linux CLI/GUI compile debt before any P13 move. CP2 491/491 remains last accepted; stable 66/17/49, debt 1. No acceptance promotion yet.

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
