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
| Currency | 2026-10-31 **TB56 run locally** ([report](Architecture_M6_CP3_TB56_O2_Full_Gate_Local_Test_Report_20261031.md)) on the CB57 package: **858/859**, row 283 (O16) the only red, membership 941; the Haiku audit is clean; result `9e138c01…`. **The O2 entry gate is landed** (pre-registered outcome met, no separate REV). Prior: RA-183 (O2), RA-182 (row 935), RA-181 (O15), RA-179 (RP-01). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB56 858/1 local candidate** (CB57 `fb4f637b…`, 859 gated; [report](Architecture_M6_CP3_TB56_O2_Full_Gate_Local_Test_Report_20261031.md)). The prior reviewed local candidate is TB54 856/1 (RA-181). **TB52 853/0** is the latest reviewed Linux candidate (RA-177). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 82 DEFERRED ([ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv)): FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. RP-01 closed (RA-179); O15 discharged (RA-181); O15c is owned by P13. Linux CI confirmation of rows 854–858 is carried. Local mode: row 283 (O2) is pre-registered. |
| Active boundary | **NEXT `M6-DEFN-DIAG-RETAIN-A5-A7`** (DEFN, R): the user-directed A5–A7 diagnostic snapshot retention (see TODO). The local baseline is TB56: 859 gated, ledger v4 82, membership 941. CP2 491/491 last accepted; CP3 not accepted. |

## Mandatory next turn — `M6-DEFN-DIAG-RETAIN-A5-A7` (type DEFN, Review track) — EXACT NEXT

- **Authority:** the user-directed DIAG-RETAIN item (TODO, 2026-10-21). It is unblocked now that RP-01 is closed (RA-179); RA-183's ordering is O2 → DIAG-RETAIN → P13.
- **Objective:** whenever `retainIntermediateGeometry` is set, retain these as one-way diagnostic snapshots in `SurfaceCellDiagnosticProductSnapshots`, including every product completed before a rejection:
  - the A5 corner occurrences (support, placement, wedge bindings);
  - the A5 occurrence relations (kind, endpoints, evidence);
  - the A6 merged quotient classes;
  - the A7 final vertex geometry.

  Then make them reachable from a CLI diagnostics dump and from GUI display layers.
- **Constraints:**
  - snapshots are never read back as stage authority;
  - no admission, return-value or ordering change;
  - bounded memory;
  - nothing is retained when retention is off.
- **The DEFN must deliver** snapshot types, the retention point for each stage, behaviour on rejection, and a memory bound. Then one narrow CB+TB per product, each with a no-read-back test: A5 occurrences and relations, A6 classes, A7 geometry. Then the CLI dump, then the GUI layers. Each step gets an exact patch, a frozen manifest (the TB56 baseline plus new rows) and an outcome table.
- **Local mode:** delegate read-only traces to Sonnet and mechanical staging and audits to Haiku. Row 283 (O16) stays pre-registered.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → TB49 504/0 → … → TB51 831/0 → TB51-REV (RA-173) → PLAN-RP01-CLOSURE ([RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md)) → CB53 (P8) → TB52C 22/1 → TB52C-REV (RA-175) → PLAN-A3-ATLAS-EXACTNESS ([RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md), O15) | CB, TB / I; REV, DEFN, PLAN / R | P8 harness `78b8002c…`; Linux package `12918290481`. |
| done | TB52 853/0 → TB52-REV ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md)) → DEFN-RP01-TERMINAL-PATH-WITNESSES ([RA-178](Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md)) → CB54 ([record](Architecture_M6_CP3_CB54_RP01_Terminal_Path_Witnesses_Code_Build_Record_20261030.md), local) → TB53 836/19 ([report](Architecture_M6_CP3_TB53_RP01_Full_Gate_Local_Test_Report_20261030.md), local) → TB53-REV ([RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)) | TB / I; REV, DEFN / R; CB, TB local | **RP-01 closed.** Gate 855 `5239f81a…`, ledger v3 83 `32b43fc5…`, membership 938. |
| done | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` ([RA-180](Architecture_M6_CP3_DEFN_A3_Exact_Branch_Topology_Predicates_20261030.md)) | DEFN / R | T1–T3 exact; CB55 patch `824e64cc…`; TB54 gate 857 `53683907…`; O15b (fields-stage matching tie) carried. |
| done | CB55 → TB54 856/857 → TB54-REV ([RA-181](Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md)) | CB, TB local; TB-REV / R | **O15 discharged**; O15c (continuation width) owned by P13; O15b carried. |
| done | `M6-CP3-DEFN-API-DISPLAY-VERTEX-STOP-WITNESS` ([RA-182](Architecture_M6_CP3_DEFN_API_Display_Vertex_Stop_Witness_20261031.md)) | DEFN / R | +½-singularity fan witness; CB56 patch `ffb723f4…`; TB55 858 / ledger v4 82. |
| done | CB56 → TB55 857/858 ([report](Architecture_M6_CP3_TB55_API_Display_Full_Gate_Local_Test_Report_20261031.md)) | CB, TB-EXEC / local | Expected 857/858, with only 283 red; any other non-PASS → `M6-CP3-TB55-API-DISPLAY-FULL-GATE-REV`. |
| done | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` ([RA-183](Architecture_M6_CP3_DEFN_O2_No_Atlas_Entry_Gate_20261031.md)) | DEFN / R | D2/D5 fixed by the entry gate; T2 discharged; O2b and O16 carried. |
| done | CB57 → TB56 858/859 ([report](Architecture_M6_CP3_TB56_O2_Full_Gate_Local_Test_Report_20261031.md)) | CB, TB-EXEC / local | Expected 858/859, with only 283 red. |
| 1 — NEXT | `M6-DEFN-DIAG-RETAIN-A5-A7` → one CB+TB per product (A5 occurrences and relations; A6 classes; A7 geometry) → CLI dump → GUI layers | DEFN / R; CB, TB local | Snapshots are one-way; no-read-back tests. |
| 4 | P13 probe DEFN (Cylinder first, which passes locally in 179 s; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | Linux CI confirmation (rows 854–859); O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). Local mode: `tools/m6_cp3_local_gate_driver.py`; row 283 is pre-registered. Packages are built FMA-free until CB55 (RA-179.4) and at default arithmetic from CB55 on (RA-180.5). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-DEFN-DIAG-RETAIN-A5-A7** (DEFN, Review, local). Read the TODO's DIAG-RETAIN item and the existing `SurfaceCellDiagnosticProductSnapshots` contract. Freeze the snapshot types, the retention points, behaviour on rejection, a memory bound, and exact narrow CB patches with no-read-back tests. The local baseline is TB56 (859, ledger v4 82, membership 941, row 283 the only red). RP-01, O15, row 935 and O2 are done; CP2 491/491 last accepted; stable 66/17/49, debt 1.

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
