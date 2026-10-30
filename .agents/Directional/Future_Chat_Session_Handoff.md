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
| Currency | 2026-10-30 **CB55 built locally** ([record](Architecture_M6_CP3_CB55_A3_Exact_Branch_Topology_Code_Build_Record_20261030.md)): the exact RA-180.7 patch at source `04027167…`, default arithmetic, package `69104b95…`. Prior: **RA-180 O15 DEFN** (exact A3 gauge, derivatives and port order; FMA and FMA-free builds give identical 854/855 and identical atlas partitions). RA-179 closed RP-01. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB53 836/19 reviewed local candidate** (macOS arm64, source `2a49b873…`, [RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)): every red is classified as a platform failure (O15 or O2); variant B (FMA-free) gives 854/855. **TB52 853/0** is the latest reviewed Linux candidate ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md), run 41100261157). CB52 Linux package `12918290481`. Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 83 DEFERRED ([ledger v3](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv)): FIXTURE 48, PRODUCT 7, OPEN 23, RETIRE 5. **RP-01 closed** (RA-179.4). Falsifier: the first Linux CI gate fails row 854 or 855; a Linux confirmation run is carried. **O15 (RA-176, list corrected by RA-179):** 21 gated `mechanical_feature` rows depend on A3 rounding; on macOS with FMA, 18 of them fail. **Local-mode convention:** build local packages with `-ffp-contract=off` and pre-register row 283 (O2). |
| Active boundary | **NEXT `M6-CP3-TB54-O15-FULL-GATE-EXEC`** (TB-EXEC, local): the CB55 package `build/local-evidence/CB55/pkg.zip` with gate 857 and ledger v3 83, through `tools/m6_cp3_local_gate_driver.py`. Expected 856/857, with row 283 the only red; then TB54-REV. CP2 491/491 last accepted. |

## Mandatory next turn — `M6-CP3-TB54-O15-FULL-GATE-EXEC` (type TB-EXEC; run locally) — EXACT NEXT

- **Authority:** [RA-180.6](Architecture_M6_CP3_DEFN_A3_Exact_Branch_Topology_Predicates_20261030.md) and the [CB55 record](Architecture_M6_CP3_CB55_A3_Exact_Branch_Topology_Code_Build_Record_20261030.md).
- **Command** (from the repository root):
  `python3 -I .agents/Directional/tools/m6_cp3_local_gate_driver.py --harness .agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh --harness-sha 78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94 --package-zip build/local-evidence/CB55/pkg.zip --package-zip-sha 69104b95a433104e91ca698e61f73dd865eea610a06170283163dc3be6aebb51 --root-manifest-sha 3479136027cbc61fd69fbf33446957cb5a4bc6b188b5e0b6d605a92bbee4bebc --source-sha 0402716703e26cb640f6bc8a423389c31987107f --source-archive-sha 6066039e58c5a4c0a009e6a52828c532f8f1825360d64c398cd6ce08945eb946 --manifest .agents/Directional/Architecture_M6_CP3_TB54_O15_Full_Gate_Case_Manifest.tsv --manifest-sha 53683907397327faf1147c7e7ced73c1a839701db47241933134c9a20b0bec3c --count 857 --ledger .agents/Directional/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv --ledger-sha 32b43fc5415c6811a8de1e8934b0e0361a84ab689ed76dc1cfa9b84d4663be78 --work build/local-evidence/TB54/run --jobs 3`
- **Outcomes (RA-180.6):**
  - 856/857 PASS, with row 283 the only RED, postflight true and membership 940 → TB54-REV.
  - Any other non-PASS → TB54-REV classifies it, with no retry.
  - A membership error → `M6-CP3-PLAN-O15-MEMBERSHIP-STOP`.
- **Report** counts and first failures only; do not classify.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → TB49 504/0 → … → TB51 831/0 → TB51-REV (RA-173) → PLAN-RP01-CLOSURE ([RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md)) → CB53 (P8) → TB52C 22/1 → TB52C-REV (RA-175) → PLAN-A3-ATLAS-EXACTNESS ([RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md), O15) | CB, TB / I; REV, DEFN, PLAN / R | P8 harness `78b8002c…`; Linux package `12918290481`. |
| done | TB52 853/0 → TB52-REV ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md)) → DEFN-RP01-TERMINAL-PATH-WITNESSES ([RA-178](Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md)) → CB54 ([record](Architecture_M6_CP3_CB54_RP01_Terminal_Path_Witnesses_Code_Build_Record_20261030.md), local) → TB53 836/19 ([report](Architecture_M6_CP3_TB53_RP01_Full_Gate_Local_Test_Report_20261030.md), local) → TB53-REV ([RA-179](Architecture_M6_CP3_TB53_REV_Local_Gate_Platform_Attribution_RP01_Closure_20261030.md)) | TB / I; REV, DEFN / R; CB, TB local | **RP-01 closed.** Gate 855 `5239f81a…`, ledger v3 83 `32b43fc5…`, membership 938. |
| done | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` ([RA-180](Architecture_M6_CP3_DEFN_A3_Exact_Branch_Topology_Predicates_20261030.md)) | DEFN / R | T1–T3 exact; CB55 patch `824e64cc…`; TB54 gate 857 `53683907…`; O15b (fields-stage matching tie) carried. |
| 1 — NEXT | CB55 **done** ([record](Architecture_M6_CP3_CB55_A3_Exact_Branch_Topology_Code_Build_Record_20261030.md), package `69104b95…`) → **`M6-CP3-TB54-O15-FULL-GATE-EXEC`** → `M6-CP3-TB54-O15-FULL-GATE-REV` | CB, TB-EXEC / local; TB-REV / R | Expected result 856/857, with row 283 (O2) the only red; TB54-REV rules O15 discharged. |
| 2 | `M6-CP3-DEFN-API-DISPLAY-VERTEX-STOP-WITNESS` → CB56 (row 935 witness) → TB55 → TB55-REV | DEFN / R; CB, TB / local | No `milestone-g` fixture stops with a vertex locus under exact A3 (RA-180.4); construct one. Row 935 then moves to the gate (ledger v4, 82). |
| 3 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS` (now including row 283), then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 folds into O2. |
| 4 | P13 probe DEFN (Cylinder first; O6; exact-atlas and route-step (O9) checks) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | TB53 Linux confirmation (CI) | TB-EXEC / I | RP-01 falsifier (RA-179.4). |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). Local mode: `tools/m6_cp3_local_gate_driver.py`; row 283 is pre-registered. Packages are built FMA-free until CB55 (RA-179.4) and at default arithmetic from CB55 on (RA-180.5). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB54-O15-FULL-GATE-EXEC** (TB-EXEC, run locally). Run the exact command in the mandatory-next section: CB55 package `69104b95…`, gate 857 `53683907…`, ledger v3 83, expected membership 940, and row 283 the only expected red. Report counts and first failures only. Next is TB54-REV (R), which rules on O15 discharge. RP-01 closed; CP2 491/491 last accepted; stable 66/17/49, debt 1.

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
