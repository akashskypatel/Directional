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
| Currency | 2026-10-30 **RA-176 audit of TB52C-REV** ([record](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md)): TB52C evidence and the frozen 853/86 TB52 inputs re-verified. Row 19 is red because the A3 atlas makes floating-point decisions at exact ties (FMA on vs off), not because a producer changed. New CP3-exit obligation **O15** (exact A3 predicates). TB52C 22 PASS / 1 RED; CB53 P8 harness `78b8002c…` applied. TB51 831/0 remains a reviewed candidate, not CP3 acceptance. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB51 831/0 reviewed candidate**, [run 41021857497](https://github.com/akashskypatel/Directional/actions/runs/41021857497), result `12963899691` (`e6339e12…`), log `12964417597`; 831/831 native joins, no non-PASS, postflight true. Prior TB50-R2 **508/0** was superseded as the reviewed candidate; CB52 source `7cf0857b…`, package `12918290481`. Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 86 DEFERRED ([ledger v2](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv)): FIXTURE 50, PRODUCT 7, OPEN 24, RETIRE 5 (original TB51 ledger 85 remains immutable). RP-01 blockers are rows 223, 225 and 261 plus the O9 ruling (RA-174.3). Every other deferred row blocks CP3 exit, not RP-01. The API-binary 23-row census had 22 PASS and one classified non-stable FIXTURE RED; the five-binary TB52 gate has 853 and ledger v2 has 86. **O15 (RA-176):** 18 gated `mechanical_feature` rows are green only for x86-64 rounding; the exact answer agrees with Linux. |
| Active boundary | **NEXT `M6-CP3-TB52-RP01-FULL-GATE-EXEC`** (TB-EXEC, I): independently frozen 853-case five-binary gate plus 86-case deferred ledger v2, with mandatory P8 membership preflight; RA-175 classified row19 FIXTURE; RA-176 kept the class but corrected the cause (A3 floating point, O15). [TB52C report](Architecture_M6_CP3_TB52C_RP01_API_Binary_Census_Artifact_Only_Report_20261030.md); [run 41064596683](https://github.com/akashskypatel/Directional/actions/runs/41064596683). Prior TB51 831/0 is reviewed candidate, CP2 491/491 last accepted. 86 deferred, RP-01 rows 223/225/261 + O9, and all CP3-exit obligations remain unchanged. |

## Mandatory next turn — `M6-CP3-TB52-RP01-FULL-GATE-EXEC` (type TB-EXEC, implementation track) — EXACT NEXT

- **Authority:** [RA-175 independent review](Architecture_M6_CP3_TB52C_REV_API_Binary_Census_Independent_Disposition_20261030.md) as audited by [RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md) (inputs unchanged), RA-174 P8, immutable CB52 package `12918290481` at semantic source `7cf0857b4818186638ce77e4859adacbeebd288f`, harness P8 SHA `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`.
- **Gate:** `.agents/Directional/Architecture_M6_CP3_TB52_RP01_Full_Gate_Case_Manifest.tsv` (853 cases, SHA-256 `95a7af662fd94306c92145050eff18fa0cc57de4eed19d1e4704938fc5532211`, first 831 rows byte-identical to TB51). **Ledger:** `.agents/Directional/Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv` (86 cases, SHA-256 `77c1d33b25f65837aa24c446b99657bfc1932fb8ab7636cc9c3ded598c38c78d`). Set `MEMBERSHIP_LEDGER`, `MEMBERSHIP_LEDGER_SHA256`, `CASE_MANIFEST`, `CASE_MANIFEST_SHA256` and `EXPECTED_CASE_COUNT=853`; execute with the immutable package under the authorized artifact-only harness, no recompile, relink or fixture repair.
- **Falsifiers:** wrong binary/test membership (`--gtest_list_tests` preflight), stale/gapped/duplicate test, altered first 831 rows, any non-PASS of 853, incomplete postflight. Do not suppress RED; report as evidence for next independent TB52-REV.
- **Outcomes (RA-176.4):** 853/853 PASS, postflight true and `membership=939` → TB52-REV. A P8 membership error before any native row → `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP`. Any non-PASS → TB52-REV classifies it, with no retry. Dispatcher failure → `M6-CP3-CB53A-RP01-ORCH`, then one retry.
- **Boundary:** no selector497 or CP3 acceptance; last accepted CP2 491/491; stable 66/17/49 debt1; the 86 deferred tests (50 FIXTURE,7 PRODUCT,24 OPEN,5 RETIRE) and RP-01 223/225/261 + O9 carry forward.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → TB49 **504/0** → TB49-REV (RA-169/170) → CB50–CB52 (P3–P6) → TB50-R2 **508/0** → TB50-REV (RA-171) → CB50C (P7) → TB50C-R2 census **323/83/2/0** | CB, TB / I; TB-REV, DEFN / R | Source `7cf0857b…`, package `12918290481`; [RA-171](Architecture_M6_CP3_TB50_REV_Gate_Closeout_Census_Observe_Harness_20261029.md); [census report](Architecture_M6_CP3_TB50C_RP01_Off_Gate_Census_R2_Test_Benchmark_Report_20261029.md). |
| done | DEFN off-selector disposition ([RA-172](Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Disposition_20261030.md), ledger 85) → TB51 **831/0** → TB51-REV ([RA-173](Architecture_M6_CP3_TB51_REV_Independent_Full_Gate_Review_20261030.md)) → `M6-CP3-PLAN-RP01-CLOSURE` ([RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md)) | DEFN, PLAN / R; TB-EXEC / I; TB-REV / R | RP-01 blockers 223/225/261 + O9; CP3-exit conditions; P8 frozen; [TB51 report](Architecture_M6_CP3_TB51_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md). |
| done | CB53 (P8 at `a9a1f16`) → TB52C census **22/1** → TB52C-REV ([RA-175](Architecture_M6_CP3_TB52C_REV_API_Binary_Census_Independent_Disposition_20261030.md)) → `M6-CP3-PLAN-A3-ATLAS-EXACTNESS` ([RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md)) | CB, TB-EXEC / I; TB-REV, PLAN / R | Gate 853 / ledger v2 86 frozen and re-verified. Row 19 is caused by FMA-dependent A3 decisions at exact ties, a DESIGN Amendment 18 violation, now **O15**. [TB52C report](Architecture_M6_CP3_TB52C_RP01_API_Binary_Census_Artifact_Only_Report_20261030.md). |
| 4 — NEXT | `M6-CP3-TB52-RP01-FULL-GATE-EXEC` → `M6-CP3-TB52-RP01-FULL-GATE-REV` | TB-EXEC / I; TB-REV / R | First gate run with `MEMBERSHIP_LEDGER` over all five packaged test binaries. |
| R∥ 1 | `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES` → CB54 → TB53 → TB53-REV | DEFN / R; CB, TB / I; TB-REV / R | Probe and repair 223, 225 and 261 without weakening; rule on O9. RP-01 closes at TB53-REV. |
| R∥ 2 | `M6-CP3-DEFN-A3-ATLAS-EXACT-SECTOR-PREDICATES` → CB55 (exact predicates + red-first test) → CB56 (exact witness for row 935) → TB54 → TB54-REV | DEFN / R; CB, TB / I; TB-REV / R | O15 (RA-176.3): inventory the A3 float decisions (`FieldTransportAtlas.cpp:276–296`, `:517–521`) and apply the half-open exact rule. The red-first witness must fail on Linux CI. Row 935 then moves to the gate (ledger v3, 85 rows). |
| then | P13 probe DEFN (Cylinder first; O6; check exact-atlas ties first) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. A FIXTURE DEFN first confirms the production pipeline reaches the stage under test. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 legacy-path reachability folds into O2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | CB53/TB52C mismatch or preflight error → `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP`; dispatcher failure → `M6-CP3-CB53A-RP01-ORCH`, then one retry. After CB53 every gate run needs `MEMBERSHIP_LEDGER`, so TB51 cannot be re-run. A DEFN must have a reachable exit (RA-172.1). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB52-RP01-FULL-GATE-EXEC** (TB-EXEC): [RA-175](Architecture_M6_CP3_TB52C_REV_API_Binary_Census_Independent_Disposition_20261030.md) froze 853 tests in `Architecture_M6_CP3_TB52_RP01_Full_Gate_Case_Manifest.tsv` SHA-256 `95a7af662fd94306c92145050eff18fa0cc57de4eed19d1e4704938fc5532211`, and 86 deferred in `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v2.tsv` SHA-256 `77c1d33b25f65837aa24c446b99657bfc1932fb8ab7636cc9c3ded598c38c78d`. Run P8 membership first; unchanged CB52 artifact `12918290481`; expected `membership=939`. [RA-176](Architecture_M6_CP3_PLAN_A3_Atlas_Exactness_TB52C_REV_Audit_20261030.md) audited these inputs and found them unchanged; O15 runs on the Review track. No compile, repair, selector or CP3 acceptance; next independent TB52-REV. CP2 491/491 last accepted; TB51 831/0 reviewed candidate; 86 deferred.

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
