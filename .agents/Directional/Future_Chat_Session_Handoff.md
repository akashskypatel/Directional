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
| Currency | 2026-10-31 **CB56 built locally** ([record](Architecture_M6_CP3_CB56_API_Display_Vertex_Stop_Witness_Code_Build_Record_20261031.md)): the exact RA-182.7 patch at source `567d1828…`, package `26d88d20…`. Prior: RA-182 (row 935 witness: a +½-singularity fan stops at A3 vertex 0); RA-181 discharged O15; RA-179 closed RP-01. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB54 856/1 reviewed local candidate** (CB55 `04027167…`, [RA-181](Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md)). TB53 836/19 was the prior local candidate (RA-179). **TB52 853/0** is the latest reviewed Linux candidate (RA-177). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Ledger v3: 83 DEFERRED; **ledger v4 (82)** is frozen for TB55, with row 935 moved to the gate (FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5). RP-01 closed (RA-179); O15 discharged (RA-181); O15c is owned by P13. Falsifier: a Linux CI gate fails rows 854–858. Local mode: row 283 (O2) is pre-registered. |
| Active boundary | **NEXT `M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC`** (TB-EXEC, local): the CB56 package with gate 858 and ledger v4 82; expected 857/858, with row 283 the only red. CP2 491/491 last accepted. |

## Mandatory next turn — `M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC` (type TB-EXEC; run locally) — EXACT NEXT

- **Authority:** [RA-182.5](Architecture_M6_CP3_DEFN_API_Display_Vertex_Stop_Witness_20261031.md) and the [CB56 record](Architecture_M6_CP3_CB56_API_Display_Vertex_Stop_Witness_Code_Build_Record_20261031.md).
- **Command** (from the repository root):
  `python3 -I .agents/Directional/tools/m6_cp3_local_gate_driver.py --harness .agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh --harness-sha 78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94 --package-zip build/local-evidence/CB56/pkg.zip --package-zip-sha 26d88d2097ff87057dc27c42a4bfd41f6c4c43bc840f2dccbb915dd10cb26cb0 --root-manifest-sha ddf68443ebd7588a2a7c631719c289d320ac43a12b1b9e705d5e33ad998e4f4d --source-sha 567d1828301f74a6e3c50bfcdfc4f7e6819d1ad3 --source-archive-sha 07c5c167b4bafb35092e68e28610d11fd15c6d8c0931d377dc1ba3646fb98323 --manifest .agents/Directional/Architecture_M6_CP3_TB55_API_Display_Full_Gate_Case_Manifest.tsv --manifest-sha eb508378644093ac98cb8fcb3351af12e66b49ad284d68714c22710c0d4f892c --count 858 --ledger .agents/Directional/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv --ledger-sha 36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d --work build/local-evidence/TB55/run --jobs 3`
- **Outcomes (RA-182.5):**
  - 857/858 PASS, with row 283 the only RED, postflight true and membership 940 → `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (no separate REV).
  - Any other non-PASS → `M6-CP3-TB55-API-DISPLAY-FULL-GATE-REV`.
  - A membership error → `M6-CP3-PLAN-API-DISPLAY-MEMBERSHIP-STOP`.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → TB49 504/0 → … → TB51 831/0 → TB51-REV (RA-173) → PLAN-RP01-CLOSURE ([RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md)) → CB53 (P8) → TB52C 22/1 → TB52C-REV (RA-175) → PLAN-A3-ATLAS-EXACTNESS ([RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md), O15) | CB, TB / I; REV, DEFN, PLAN / R | P8 harness `78b8002c…`; Linux package `12918290481`. |
| done | TB52 853/0 → TB52-REV ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md)) → DEFN-RP01-TERMINAL-PATH-WITNESSES ([RA-178](Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md)) → CB54 ([record](Architecture_M6_CP3_CB54_RP01_Terminal_Path_Witnesses_Code_Build_Record_20261030.md), local) → TB53 836/19 ([report](Architecture_M6_CP3_TB53_RP01_Full_Gate_Local_Test_Report_20261030.md), local) → TB53-REV ([RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)) | TB / I; REV, DEFN / R; CB, TB local | **RP-01 closed.** Gate 855 `5239f81a…`, ledger v3 83 `32b43fc5…`, membership 938. |
| done | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` ([RA-180](Architecture_M6_CP3_DEFN_A3_Exact_Branch_Topology_Predicates_20261030.md)) | DEFN / R | T1–T3 exact; CB55 patch `824e64cc…`; TB54 gate 857 `53683907…`; O15b (fields-stage matching tie) carried. |
| done | CB55 → TB54 856/857 → TB54-REV ([RA-181](Architecture_M6_CP3_TB54_REV_O15_Discharge_20261031.md)) | CB, TB local; TB-REV / R | **O15 discharged**; O15c (continuation width) owned by P13; O15b carried. |
| done | `M6-CP3-DEFN-API-DISPLAY-VERTEX-STOP-WITNESS` ([RA-182](Architecture_M6_CP3_DEFN_API_Display_Vertex_Stop_Witness_20261031.md)) | DEFN / R | +½-singularity fan witness; CB56 patch `ffb723f4…`; TB55 858 / ledger v4 82. |
| 1 — NEXT | CB56 **done** ([record](Architecture_M6_CP3_CB56_API_Display_Vertex_Stop_Witness_Code_Build_Record_20261031.md), package `26d88d20…`) → **`M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC`** | CB, TB-EXEC / local | Expected 857/858, with only 283 red; any other non-PASS → `M6-CP3-TB55-API-DISPLAY-FULL-GATE-REV`. |
| 3 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (now including row 283), then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 folds into O2. |
| 4 | P13 probe DEFN (Cylinder first, which passes locally in 179 s; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | Linux CI confirmation of TB53/TB54 (rows 854–857) | TB-EXEC / I | RP-01 and O15 falsifiers (RA-179.4, RA-181.2). |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). Local mode: `tools/m6_cp3_local_gate_driver.py`; row 283 is pre-registered. Packages are built FMA-free until CB55 (RA-179.4) and at default arithmetic from CB55 on (RA-180.5). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB55-API-DISPLAY-FULL-GATE-EXEC** (TB-EXEC, run locally). Run the exact command in the mandatory-next section: CB56 package `26d88d20…`, gate 858 `eb508378…`, ledger v4 82, membership 940, row 283 the only expected red. If the result is as registered, the next turn is `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`. RP-01 closed and O15 discharged; CP2 491/491 last accepted; stable 66/17/49, debt 1.

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
