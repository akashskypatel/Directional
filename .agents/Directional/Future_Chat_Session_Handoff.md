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
| Currency | 2026-10-30 **RA-179 TB53 review — RP-01 CLOSED** ([record](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md); run locally, reduced independence). TB53 on the macOS CB54 package gave 836/19. Attribution builds of the same source: compiling only `FieldTransportAtlas.cpp` without FMA clears all 18 vertex-35 reds (**O15**); a fully FMA-free build passes 854/855. Row 283 is a pre-existing macOS legacy failure, not FMA (→ **O2**). Rows 223 and 225 pass in every build. O15's row list is corrected to 21 rows. RA-178.2's FMA-off check was ineffective (ninja 1.13) and has been re-verified. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB53 836/19 reviewed local candidate** (macOS arm64, source `2a49b873…`, [RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)): every red is classified as a platform failure (O15 or O2); variant B (FMA-free) gives 854/855. **TB52 853/0** is the latest reviewed Linux candidate ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md), run 41100261157). CB52 Linux package `12918290481`. Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 83 DEFERRED ([ledger v3](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv)): FIXTURE 48, PRODUCT 7, OPEN 23, RETIRE 5. **RP-01 closed** (RA-179.4). Falsifier: the first Linux CI gate fails row 854 or 855; a Linux confirmation run is carried. **O15 (RA-176, list corrected by RA-179):** 21 gated `mechanical_feature` rows depend on A3 rounding; on macOS with FMA, 18 of them fail. **Local-mode convention:** build local packages with `-ffp-contract=off` and pre-register row 283 (O2). |
| Active boundary | **NEXT `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES`** (DEFN, R): O15 exact A3 predicates (RA-176.3). The default macOS build gives a ready red-first signal (18 rows), and an FMA-free build is the Linux-like control. CP2 491/491 last accepted; CP3 not accepted. |

## Mandatory next turn — `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` (type DEFN, Review track) — EXACT NEXT

- **Authority:** [RA-176.3](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md) (O15 deliverables) and [RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md) (attribution and the corrected 21-row list).
- **Deliver:**
  - an inventory of every float- or tolerance-decided topology choice in A3 (at least `FieldTransportAtlas.cpp:118–124`, `:276–296`, `:517–521`);
  - an exact, probe-verified patch (GMP, or a certified filter that defers to exact) with a recorded tie rule;
  - an exact oracle test asserting 3 incidences at vertices 10/35/47/71 of `mechanical_feature`;
  - red-first evidence: the default (FMA) build fails the 18 rows before the patch and passes them after, and the FMA-free build passes before and after;
  - the replacement witness for row 935;
  - an outcome table for any gate row that changes.
- **Split** the work into narrow CBs: CB55 (exact predicates + oracle test), then CB56 (row 935 witness). Each has an exact patch, its own frozen manifest and an outcome table.
- **Local mode:** build and test locally (RA-179.4 convention); probes are diagnostic only.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → TB49 504/0 → … → TB51 831/0 → TB51-REV (RA-173) → PLAN-RP01-CLOSURE ([RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md)) → CB53 (P8) → TB52C 22/1 → TB52C-REV (RA-175) → PLAN-A3-ATLAS-EXACTNESS ([RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md), O15) | CB, TB / I; REV, DEFN, PLAN / R | P8 harness `78b8002c…`; Linux package `12918290481`. |
| done | TB52 853/0 → TB52-REV ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md)) → DEFN-RP01-TERMINAL-PATH-WITNESSES ([RA-178](Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md)) → CB54 ([record](Architecture_M6_CP3_CB54_RP01_Terminal_Path_Witnesses_Code_Build_Record_20261030.md), local) → TB53 836/19 ([report](Architecture_M6_CP3_TB53_RP01_Full_Gate_Local_Test_Report_20261030.md), local) → TB53-REV ([RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)) | TB / I; REV, DEFN / R; CB, TB local | **RP-01 closed.** Gate 855 `5239f81a…`, ledger v3 83 `32b43fc5…`, membership 938. |
| 1 — NEXT | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` | DEFN / R | O15 inventory, exact patch, oracle test, red-first evidence (default macOS build), row 935 witness. |
| 2 | CB55 (exact predicates + oracle test) → TB54 (full gate, FMA-free local package, plus default-build O15 rows) → CB56 (row 935 witness) → TB55 → TB-REV | CB, TB / I or local; TB-REV / R | O15 discharged; row 935 moves to the gate (ledger v4, 82). IDs are frozen by the DEFN. |
| 3 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (now including row 283), then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 folds into O2. |
| 4 | P13 probe DEFN (Cylinder first; O6; exact-atlas and route-step (O9) checks) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | TB53 Linux confirmation (CI) | TB-EXEC / I | RP-01 falsifier (RA-179.4). |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). Local mode: `tools/m6_cp3_local_gate_driver.py`; packages built with `-ffp-contract=off`; row 283 is pre-registered (RA-179.4). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES** (DEFN, Review track). Read RA-176.3 (O15 deliverables) and RA-179 (the attribution and the 21-row list: 86, 396, 397, 445, 637, 638, 649, 650, 652, 653, 656, 658, 660, 662, 665, 669, 687, 784, 786, 787, 788). Probe locally: the default macOS build is the red-first signal and the FMA-free build is the control. Freeze exact CB55/CB56 patches, manifests and outcome tables. RP-01 is closed; CP2 491/491 last accepted; stable 66/17/49, debt 1.

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
