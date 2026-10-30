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
| Currency | 2026-10-30 **TB51-EXEC immutable 831/0 full gate complete** ([TB51 report](Architecture_M6_CP3_TB51_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md)); run `41021857497`, result `12963899691`, postflight true and 1,668/1,668 result checksums. RA-172 deferred 85-row ledger remains separate. TB51-REV is next; not CP3 acceptance. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB51 831/0 unreviewed candidate**, [run 41021857497](https://github.com/akashskypatel/Directional/actions/runs/41021857497), result `12963899691` (`e6339e12…`), log `12964417597`; 831/831 native joins, no non-PASS, postflight true. Prior independently reviewed TB50-R2 **508/0** remains the reviewed candidate; CB52 source `7cf0857b…`, package `12918290481`. Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Frozen 85 DEFERRED: 49 FIXTURE, 7 PRODUCT, 24 OPEN, 5 RETIRE; none executed or classified by TB51. [Tracker](Regression_Root_Cause_Tracker.md), [deferred ledger](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger.tsv). |
| Active boundary | **TB51-EXEC COMPLETE; NEXT `M6-CP3-TB51-RP01-FULL-GATE-REV`** (TB-REV, R) to independently verify the 831/0 candidate artifact and 916-row gate∪deferred inventory. Then separately `M6-CP3-PLAN-RP01-CLOSURE` (RA-172.5 RP-01 blockers/O14/slice order). RP-01 open, RP-02 unreached; selector497 unpromoted. Carried O1/O2/O6–O10/O12/O14, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-TB51-RP01-FULL-GATE-REV` (TB-REV, Review track) — EXACT NEXT

- **Input:** [TB51 verified TB-EXEC report](Architecture_M6_CP3_TB51_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md), run `41021857497`, result `12963899691`, log `12964417597`; immutable CB52 package `12918290481`, source `7cf0857b…`, frozen 831-case manifest `d6961b59…`, harness `600c6455…`.
- **Independent gate:** verify all 831 native PASS rows and complete hashes/identity joins; inspect the 85 DEFERRED rows in `Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger.tsv` and disjoint 916-row inventory. Review the open RP-01 obligations and candidate status; no accepted-green/selector promotion without separately authorized proof.
- **No successor execution in this turn:** the subsequent `M6-CP3-PLAN-RP01-CLOSURE` is a separately authorized PLAN (Review). No CP3 acceptance, no code patch, and no inference that the excluded tests passed.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → CB49E → TB49-EXEC (504/0) → `M6-CP3-TB49-RP01-FULL-GATE-REV` (RA-169, re-derived RA-170.1); DEFNs C1, P1-a, P1-b, O4 | CB, TB / I; TB-REV, DEFN / R | RA-169/170 probes; P3–P6 round-trip exact. |
| done | CB50 (P3) → CB50F (P4) → CB51 (P5) → CB52 (P6) → TB50-EXEC S5 → CB50A-ORCH → TB50-EXEC-R2 **508/0** → TB50C-EXEC S5 | CB, TB-EXEC / I | Source `7cf0857b…`, package `12918290481`; [TB50-R2 report](Architecture_M6_CP3_TB50_RP01_Full_Gate_R2_Test_Benchmark_Report_20261029.md); S5 runs were orchestration-only. |
| done | `M6-CP3-TB50-RP01-FULL-GATE-REV` → CB50C-ORCH (P7 `OBSERVE`, harness `600c6455…`) → TB50C-EXEC-R2 **323/83/2/0** | TB-REV / R; CB, TB-EXEC / I | [RA-171](Architecture_M6_CP3_TB50_REV_Gate_Closeout_Census_Observe_Harness_20261029.md); [census report](Architecture_M6_CP3_TB50C_RP01_Off_Gate_Census_R2_Test_Benchmark_Report_20261029.md), run 40965775275. |
| done | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` | DEFN / R | [RA-172](Architecture_M6_CP3_DEFN_RP01_Off_Selector_Coverage_Disposition_20261030.md): 85 rows classified FIXTURE 49 / PRODUCT 7 / OPEN 24 / RETIRE 5 into a [deferred ledger](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger.tsv); TB51 = 508 + 323 = 831 frozen `d6961b59…`. |
| done | `M6-CP3-TB51-RP01-FULL-GATE-EXEC` | TB-EXEC / I | [TB51 report](Architecture_M6_CP3_TB51_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md), [run 41021857497](https://github.com/akashskypatel/Directional/actions/runs/41021857497): 831/0, postflight true; no recompilation or changes; candidate only. |
| 1 — NEXT | `M6-CP3-TB51-RP01-FULL-GATE-REV` | TB-REV / R | Independently verify 831/0 and disjoint gate ∪ deferred ledger = 916; disposition the candidate without promoting CP3 or selector497. |
| 2 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | RA-172.5 RP-01 blocker rule (P13, P12b by default); O14 gate completeness; O6 scope; owners for O7–O10, O12, O14; repair-slice order. |
| 3+ | Repair slices, one per RA-172.4 group | per slice | Retire CB first. FIXTURE/PRODUCT: exact patch (R) → CB (I) → TB (I) → REV (R). OPEN: probe DEFN (R) first. Each slice moves its rows from the ledger to the gate. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 legacy-path reachability folds into O2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | TB51 preflight/manifest error → `M6-CP3-PLAN-RP01-GATE-STOP`; dispatcher/runner failure before harness start → `M6-CP3-CB53-RP01-GATE-ORCH`, then one retry. A DEFN must have a reachable exit (RA-172.1). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB51-RP01-FULL-GATE-REV** (TB-REV, Review): independently inspect [TB51 831/0 immutable artifact](Architecture_M6_CP3_TB51_RP01_Full_Gate_Artifact_Only_Test_Benchmark_Report_20261030.md), recheck source/package/harness/manifest/result identities and complete 916-row gate∪deferred inventory; assess reviewed candidate status without treating deferred rows as passing. CP2 491/491 last accepted; stable 66/17/49, debt 1; selector497 frozen. Do not implement PLAN/repair during REV.

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
