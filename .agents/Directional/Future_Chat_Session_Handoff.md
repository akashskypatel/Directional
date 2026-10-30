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
| Currency | 2026-10-30 **CB53 complete:** RA-174 P8 exact gate-membership preflight harness applied ([record](Architecture_M6_CP3_CB53_RP01_Gate_Membership_Preflight_Code_Build_Record_20261030.md), [commit `a9a1f16`](https://github.com/akashskypatel/Directional/commit/a9a1f16e779c6b648379d580ef7286442af33af7)); offline self-test 30 and all seven manifest/ledger checks passed. The packaged API binary's 23 tests remain uncensused; TB52C must observe them. TB51 831/0 remains a reviewed candidate, not CP3 acceptance. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB51 831/0 reviewed candidate**, [run 41021857497](https://github.com/akashskypatel/Directional/actions/runs/41021857497), result `12963899691` (`e6339e12…`), log `12964417597`; 831/831 native joins, no non-PASS, postflight true. Prior TB50-R2 **508/0** was superseded as the reviewed candidate; CB52 source `7cf0857b…`, package `12918290481`. Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 85 DEFERRED ([ledger](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger.tsv)): FIXTURE 49, PRODUCT 7, OPEN 24, RETIRE 5. RP-01 blockers are rows 223, 225 and 261 plus the O9 ruling (RA-174.3). Every other deferred row blocks CP3 exit, not RP-01. The 23 API-binary tests are uncensused. |
| Active boundary | **NEXT `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-EXEC`** (TB-EXEC, I): immutable CB52 package, 23 `OBSERVE` API-binary rows, no `MEMBERSHIP_LEDGER`; report observed outcomes without classification. Then TB52C-REV freezes the first five-binary gate. R∥: `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES` (223/225/261, O9). CP3 later requires P13 (Cylinder first) and all remaining ledger obligations. Carried O1/O2/O6–O10/O12, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, 8219. RP-02 unreached; selector497 unpromoted. |

## Mandatory next turn — `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-EXEC` (type TB-EXEC, implementation track) — EXACT NEXT

- **Authority:** [RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md).5/.6; [CB53 record](Architecture_M6_CP3_CB53_RP01_Gate_Membership_Preflight_Code_Build_Record_20261030.md). Complete and verify the 23-row API-binary census, not a gate or repair.
- **Frozen package:** CB52 semantic source `7cf0857b4818186638ce77e4859adacbeebd288f`, artifact `12918290481`, outer ZIP SHA-256 `89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`, root SHA256SUMS `6ae4eb5bf9552912fe068d9a9d3a90d76e2e27b9bd99896f83c216fd27fbc21f`, source archive `c02a0be4b25d64eca2c10e5681cd8721a465a848a3d17044275370eac132553b`.
- **Execution:** approved artifact-only harness `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`; `CASE_MANIFEST=.agents/Directional/Architecture_M6_CP3_TB52C_API_Binary_Census_Case_Manifest.tsv`, SHA-256 `81395065279e6ae6590c6feea30b719d661a328ecd90bea7ad8ef0f3a3a474ed`, `EXPECTED_CASE_COUNT=23`; **omit `MEMBERSHIP_LEDGER` and its SHA** (census is `OBSERVE`, not gated).
- **Evidence:** exact 23 ledger rows, per-row PASS/RED/ABNORMAL and every non-PASS `first_failure`, postflight and immutable artifact checksums; do not classify semantics in this turn.
- **On success:** postflight true with 23 rows → `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-REV` (separate Review).
- **On failure:** preflight error or no artifact → `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP`; dispatcher failure before harness starts → `M6-CP3-CB53A-RP01-ORCH`, then one retry.
- **Boundary:** no native rebuild, relink, configure, source/test/fixture/manifest/ledger edits, semantic fixes, selector promotion, or CP3 acceptance. Do not start TB52C-REV in the same turn.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → CB49E → TB49-EXEC (504/0) → `M6-CP3-TB49-RP01-FULL-GATE-REV` (RA-169, re-derived RA-170.1); DEFNs C1, P1-a, P1-b, O4 | CB, TB / I; TB-REV, DEFN / R | RA-169/170 probes; P3–P6 round-trip exact. |
| done | CB50 (P3) → CB50F (P4) → CB51 (P5) → CB52 (P6) → TB50-EXEC S5 → CB50A-ORCH → TB50-EXEC-R2 **508/0** → TB50C-EXEC S5 | CB, TB-EXEC / I | Source `7cf0857b…`, package `12918290481`; [TB50-R2 report](Architecture_M6_CP3_TB50_RP01_Full_Gate_R2_Test_Benchmark_Report_20261029.md); S5 runs were orchestration-only. |
| done | `M6-CP3-TB50-RP01-FULL-GATE-REV` → CB50C-ORCH (P7 `OBSERVE`, harness `600c6455…`) → TB50C-EXEC-R2 **323/83/2/0** | TB-REV / R; CB, TB-EXEC / I | [RA-171](Architecture_M6_CP3_TB50_REV_Gate_Closeout_Census_Observe_Harness_20261029.md); [census report](Architecture_M6_CP3_TB50C_RP01_Off_Gate_Census_R2_Test_Benchmark_Report_20261029.md), run 40965775275. |
| done | DEFN off-selector disposition → TB51-EXEC **831/0** → `M6-CP3-TB51-RP01-FULL-GATE-REV` | DEFN / R; TB-EXEC / I; TB-REV | [RA-172](Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Disposition_20261030.md) ledger of 85 + gate `d6961b59…`; [TB51 report](Architecture_M6_CP3_TB51_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md), run 41021857497; [RA-173](Architecture_M6_CP3_TB51_REV_Independent_Full_Gate_Review_20261030.md) review. |
| done | `M6-CP3-PLAN-RP01-CLOSURE` (+ TB51-REV audit) | PLAN / R | [RA-174](Architecture_M6_CP3_PLAN_RP01_Closure_TB51_REV_Audit_Membership_Harness_20261030.md): RP-01 blockers 223/225/261 + O9; CP3-exit conditions; F1 gap in the API binary; P8 frozen; TB52C census manifest `81395065…`. |
| done | `M6-CP3-CB53-RP01-GATE-MEMBERSHIP-PREFLIGHT` | CB / I | Exact P8 harness applied at `a9a1f16`; offline preflight passed; no native runtime. |
| 1 — NEXT | `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-EXEC` | TB-EXEC / I | CB52 package, harness `78b8002c…`, manifest `81395065…`, 23 OBSERVE rows, no `MEMBERSHIP_LEDGER`; report only. |
| 3 | `M6-CP3-TB52C-RP01-API-BINARY-CENSUS-REV` | TB-REV / R | Disposition of the 23; freeze the TB52 gate (831 + PASS rows) and ledger v2. |
| 4 | `M6-CP3-TB52-RP01-FULL-GATE-EXEC` → `M6-CP3-TB52-RP01-FULL-GATE-REV` | TB-EXEC / I; TB-REV / R | First gate run with `MEMBERSHIP_LEDGER` over all five packaged test binaries. |
| R∥ | `M6-CP3-DEFN-RP01-TERMINAL-PATH-WITNESSES` → CB54 → TB53 → TB53-REV | DEFN / R; CB, TB / I; TB-REV / R | Probe and repair 223, 225 and 261 without weakening; rule on O9. RP-01 closes at TB53-REV. |
| then | P13 probe DEFN (Cylinder first; O6) → retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. A FIXTURE DEFN first confirms the production pipeline reaches the stage under test. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 legacy-path reachability folds into O2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | CB53/TB52C mismatch or preflight error → `M6-CP3-PLAN-RP01-MEMBERSHIP-STOP`; dispatcher failure → `M6-CP3-CB53A-RP01-ORCH`, then one retry. After CB53 every gate run needs `MEMBERSHIP_LEDGER`, so TB51 cannot be re-run. A DEFN must have a reachable exit (RA-172.1). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB52C-RP01-API-BINARY-CENSUS-EXEC** (TB-EXEC, implementation): read RA-174.5/.6 and the CB53 record, then execute only the frozen 23-row API-binary census through the immutable CB52 package. No rebuild or semantic work. CP2 491/491 is accepted; TB51 831/0 is the reviewed candidate; 85 rows remain deferred.

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
