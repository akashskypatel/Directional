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
| Currency | 2026-10-30 **RA-178 DEFN RP-01 terminal-path witnesses + audit of TB52-REV** ([record](Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md)). RA-177's TB52 853/0 candidate is confirmed. Probe-backed dispositions: 225 and 223 are repaired by the exact CB54 patch `16a64128…`; 261 is retired, because its target predicate is accepted-defensive and its stimulus duplicates gated row 507. O9 is ruled: the junction path has no produced input under D2, it is removed from RP-01, and P13 owns the falsifier. TB53 is frozen at 855 + ledger v3 83, membership 938. O15 (RA-176) is unchanged. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB52 853/0 reviewed candidate** ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md), [run 41100261157](https://github.com/akashskypatel/Directional/actions/runs/41100261157), artifact `13004891149`); previously **TB51 831/0 reviewed candidate**, [run 41021857497](https://github.com/akashskypatel/Directional/actions/runs/41021857497), result `12963899691` (`e6339e12…`), log `12964417597`; 831/831 native joins, no non-PASS, postflight true. Prior TB50-R2 **508/0** was superseded as the reviewed candidate; CB52 source `7cf0857b…`, package `12918290481`. Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 86 DEFERRED ([ledger v2](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv)): FIXTURE 50, PRODUCT 7, OPEN 24, RETIRE 5 (original TB51 ledger 85 remains immutable). RP-01 now closes when TB53 passes 223 and 225, as repaired by CB54 (RA-178.3); 261 is retired and O9 ruled. Every other deferred row blocks CP3 exit, not RP-01. TB53 inputs: gate 855 `5239f81a…`, [ledger v3](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v3.tsv) 83 `32b43fc5…` (FIXTURE 48, PRODUCT 7, OPEN 23, RETIRE 5). **O15 (RA-176):** 18 gated `mechanical_feature` rows are green only for x86-64 rounding; the exact answer agrees with Linux. |
| Active boundary | **NEXT `M6-CP3-CB54-RP01-TERMINAL-PATH-WITNESSES`** (CB, I): apply the exact RA-178.7 test patch (SHA-256 `16a64128…`, numstat `90 17` / `0 46`) and build the package (compile-only). Then TB53-EXEC → TB53-REV. TB52 853/0 is the reviewed candidate ([report](Architecture_M6_CP3_TB52_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md)); CP2 491/491 last accepted. |

## Mandatory next turn — `M6-CP3-CB54-RP01-TERMINAL-PATH-WITNESSES` (type CB, implementation track) — EXACT NEXT

- **Authority:** [RA-178](Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md) §.4 and §.7. The patch is probe-verified: the repaired 223 and 225 pass with `-ffp-contract` both on and off.
- **Patch:** the RA-178.7 `~~~diff` block, extracted verbatim with a trailing newline. Its SHA-256 must be `16a64128ff3ab2279620686af60d0278e4620e463dfebd132f4a4f535fb8a75d`. Apply it with `git apply`; the numstat must be exactly `90 17` for `tests/SurfaceCellTransitionQuotientTests.cpp` and `0 46` for `tests/SurfaceCellsPhase10Tests.cpp`. The resulting SHA-256 must be `895ef38d…` and `de0dd49a…` (the full values are in RA-178.4).
- **Hunks:**
  - 225: the oracle classifies endpoints as T, R or I.
  - 223: the barrier stimulus is pinned to `gauge-pin-span`, and a new C1-valid wrong-sector stimulus reaches `MissingTerminalA3Path`.
  - 261: deleted (retired).
- **Build:** a GMP compile of the eight approved targets publishes the package. This is compile-only: no native tests, and no production, fixture, CMake, workflow, manifest or ledger edits.
- **Outcomes:**
  - All exact → `M6-CP3-TB53-RP01-FULL-GATE-EXEC`.
  - Any mismatch or compile error → `M6-CP3-PLAN-RP01-TERMINAL-WITNESS-STOP` (PLAN, R).
  - Dispatcher failure → `M6-CP3-CB54A-RP01-ORCH`, then one retry.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → TB49 **504/0** → TB49-REV (RA-169/170) → CB50–CB52 (P3–P6) → TB50-R2 **508/0** → TB50-REV (RA-171) → CB50C (P7) → TB50C-R2 census **323/83/2/0** | CB, TB / I; TB-REV, DEFN / R | Source `7cf0857b…`, package `12918290481`; [RA-171](Architecture_M6_CP3_TB50_REV_Gate_Closeout_Census_Observe_Harness_20261029.md); [census report](Architecture_M6_CP3_TB50C_RP01_Off_Gate_Census_R2_Test_Benchmark_Report_20261029.md). |
| done | DEFN off-selector disposition ([RA-172](Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Disposition_20261030.md), ledger 85) → TB51 **831/0** → TB51-REV ([RA-173](Architecture_M6_CP3_TB51_REV_Independent_Full_Gate_Review_20261030.md)) → `M6-CP3-PLAN-RP01-CLOSURE` ([RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md)) | DEFN, PLAN / R; TB-EXEC / I; TB-REV / R | RP-01 blockers 223/225/261 + O9; CP3-exit conditions; P8 frozen; [TB51 report](Architecture_M6_CP3_TB51_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md). |
| done | CB53 (P8 at `a9a1f16`) → TB52C census **22/1** → TB52C-REV ([RA-175](Architecture_M6_CP3_TB52C_REV_API_Binary_Census_Independent_Disposition_20261030.md)) → `M6-CP3-PLAN-A3-ATLAS-EXACTNESS` ([RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md)) | CB, TB-EXEC / I; TB-REV, PLAN / R | Gate 853 / ledger v2 86 frozen and re-verified. Row 19 is caused by FMA-dependent A3 decisions at exact ties, a DESIGN Amendment 18 violation, now **O15**. [TB52C report](Architecture_M6_CP3_TB52C_RP01_API_Binary_Census_Artifact_Only_Report_20261030.md). |
| done | TB52-EXEC **853/0**, membership 939 → TB52-REV ([RA-177](Architecture_M6_CP3_TB52_REV_Independent_Five_Binary_Gate_Review_20261030.md)) → `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES` ([RA-178](Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md)) | TB-EXEC / I; TB-REV, DEFN / R | TB52 is the reviewed candidate. Rows 223 and 225 are repaired by patch, 261 is retired, O9 is ruled. TB53 gate 855 / ledger v3 83 frozen. |
| 1 — NEXT | `M6-CP3-CB54-RP01-TERMINAL-PATH-WITNESSES` | CB / I | Exact RA-178.7 patch, compile-only package. Mismatch → `M6-CP3-PLAN-RP01-TERMINAL-WITNESS-STOP`. |
| 2 | `M6-CP3-TB53-RP01-FULL-GATE-EXEC` | TB-EXEC / I | CB54 package; gate `5239f81a…` 855; ledger v3 `32b43fc5…` 83; expected `membership=938` (RA-178.5 outcome table). |
| 3 | `M6-CP3-TB53-RP01-FULL-GATE-REV` | TB-REV / R | RP-01 closes if 855/855 is accepted. |
| R∥ | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` → CB55 (exact predicates + red-first test) → CB56 (exact witness for row 935) → TB54 → TB54-REV | DEFN / R; CB, TB / I; TB-REV / R | O15 (RA-176.3): inventory the A3 float decisions (`FieldTransportAtlas.cpp:276–296`, `:517–521`) and apply the half-open exact rule. The red-first witness must fail on Linux CI. Row 935 then moves to the gate (ledger v4, 82 rows). |
| then | P13 probe DEFN (Cylinder first; O6; check exact-atlas ties and maximum route steps (O9 falsifier) first) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. A FIXTURE DEFN first confirms the production pipeline reaches the stage under test. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 legacy-path reachability folds into O2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | CB54 mismatch → `M6-CP3-PLAN-RP01-TERMINAL-WITNESS-STOP`; TB53 preflight error → `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP`; dispatcher failure → `M6-CP3-CB54A-RP01-ORCH`, then one retry. After CB53 every gate run needs `MEMBERSHIP_LEDGER`, so TB51 cannot be re-run. A DEFN must have a reachable exit (RA-172.1). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB54-RP01-TERMINAL-PATH-WITNESSES** (CB, implementation track). Read [RA-178](Architecture_M6_CP3_DEFN_RP01_Terminal_Path_Witnesses_TB52_REV_Audit_20261030.md) §.4 and §.7 only. Extract the `~~~diff` block (SHA-256 `16a64128…`), `git apply`, check numstat `90 17` / `0 46` and both resulting file SHAs, then compile and package. No native tests and no other edits. Next is TB53-EXEC with gate 855 `5239f81a…`, ledger v3 83 `32b43fc5…` and `membership=938`. TB52 853/0 is the reviewed candidate; CP2 491/491 is last accepted; stable 66/17/49, debt 1.

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
