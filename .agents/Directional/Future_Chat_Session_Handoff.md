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
| Currency | 2026-10-29 **RA-171 TB50-REV complete; TB50C-R2 native OBSERVE census complete** ([run 40965775275](https://github.com/akashskypatel/Directional/actions/runs/40965775275); [verified 408-row report](Architecture_M6_CP3_TB50C_RP01_Off_Gate_Census_R2_Test_Benchmark_Report_20261029.md)). TB50-R2 selected gate 508/508 remains independently reviewed candidate. CB50C P7 harness/manifest frozen (`600c6455…` / `91823900…`); unchanged CB52 source/package. Census 408/408: 323 PASS, 83 RED, 2 ABNORMAL, 0 INVALID, postflight true, 822/822 checksums. All 85 non-PASS await separate DEFN disposition; no CP3 acceptance. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB50-R2 508/0 reviewed candidate** (RA-171.2; [report](Architecture_M6_CP3_TB50_RP01_Full_Gate_R2_Test_Benchmark_Report_20261029.md), [run 40941114716](https://github.com/akashskypatel/Directional/actions/runs/40941114716), result `12929917136`, log `12930316247`, 508/508 per-case joins and 1,022/1,022 checksums). Frozen CB52 source `7cf0857b4818186638ce77e4859adacbeebd288f` / package `12918290481`; no recompilation. TB50 first attempt S5 0/508 was orchestration-only and was fixed by CB50A. Earlier TB49 504/0 reviewed candidate; TB48 502/2, TB47 500/4 prior candidates. No CP3 acceptance or selector497 promotion. |
| Regression accounting and debt | Stable **66/17/49**, debt **1** ([tracker](Regression_Root_Cause_Tracker.md)), unchanged. TB50C-R2 CI census: **83 RED + 2 ABNORMAL / 408**; each of 85 non-PASS records remains unclassified, not yet a stable regression or platform attribution. RA-170's local macOS 101/408 was earlier provisional evidence, not the frozen CI census. |
| Active boundary | `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC-R2` completed against unchanged CB52 package `12918290481` ([run 40965775275](https://github.com/akashskypatel/Directional/actions/runs/40965775275)); **NEXT `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION`**, Review/planning only. Classify all 85 non-PASS rows by cause; retire only with evidence and freeze TB51 gate = 508 + (408 − retired) (RA-171.5). Carried O1/O2/O6–O13, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002, 8219. RP-01 open, RP-02 unreached; selector497 unpromoted. |

## Mandatory next turn — `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` (type DEFN, Review track) — EXACT NEXT

- **Authority:** RA-171.5/.6 and [TB50C-R2 native census report](Architecture_M6_CP3_TB50C_RP01_Off_Gate_Census_R2_Test_Benchmark_Report_20261029.md). The 408-case OBSERVE census completed under [run 40965775275](https://github.com/akashskypatel/Directional/actions/runs/40965775275): 323 PASS, 83 RED, 2 ABNORMAL, 0 INVALID; postflight true; 822/822 checksums; all 408 joins. Native package/source unchanged.
- **Action:** classify every one of 85 non-PASS records by exact first-failure/typed-reason group (stale oracle / regression / O2 legacy / platform / retire), without prematurely adding stable regressions. Produce exact corrective patch proposals by causal group, with one CB per group; decide retirement reason for each removed off-gate case; freeze TB51 gate = 508 + (408 - retired).
- **Boundary:** planning/review only; no implementation, fixture edits, source changes, compile or runtime. CP2 491/491 accepted, TB50-R2 508/508 reviewed candidate, stable 66/17/49 debt1 until adjudication, no CP3 or selector497 promotion.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → CB49E → TB49-EXEC (504/0) → `M6-CP3-TB49-RP01-FULL-GATE-REV` (RA-169, re-derived RA-170.1); DEFNs C1, P1-a, P1-b, O4 | CB, TB / I; TB-REV, DEFN / R | RA-169/170 probes; P3–P6 round-trip exact. |
| done | `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` | CB / I | Exact P3 (RA-169.10), source `88249ebbb27b`, eight GMP targets compile-only; no runtime. |
| done | `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` | CB / I | Exact P4 on CB50; source `b8c07a6f24664e0de70026951c9ab3dd408d8f80`, eight GMP targets compile-only. |
| done | `M6-CP3-CB51-RP01-P1B-NETWORK-OWNER-WITNESS` | CB / I | P5 (RA-170.7) applied exactly, eight GMP targets compile-only; no runtime. |
| done | `M6-CP3-CB52-RP01-E2-FACTORY-SITE-PINS` | CB / I | P6 (RA-170.8) on CB51; test-only. |
| done — S5 | `M6-CP3-TB50-RP01-FULL-GATE-EXEC` | TB-EXEC / I | Orchestration preflight rejected site pin row 505, 0/508 executed; [report](Architecture_M6_CP3_TB50_RP01_Full_Gate_Orchestration_Failure_Report_20261029.md). |
| done | `M6-CP3-CB50A-RP01-ORCH` | CB / I | Repair site-pin harness/manifest contract under RA-170 S5; no native runtime. |
| done | `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2` | TB-EXEC / I | [Run 40941114716](https://github.com/akashskypatel/Directional/actions/runs/40941114716) **508/0** exact native selected gate; [report](Architecture_M6_CP3_TB50_RP01_Full_Gate_R2_Test_Benchmark_Report_20261029.md); no CP3 acceptance. |
| done — S5 | `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC` | TB-EXEC / I | [Run 40952631880](https://github.com/akashskypatel/Directional/actions/runs/40952631880) preflight `row 360: invalid gtest name`, 0/408; [report](Architecture_M6_CP3_TB50C_Off_Gate_Census_Orchestration_Failure_Report_20261029.md). |
| done | `M6-CP3-TB50-RP01-FULL-GATE-REV` | TB-REV / R | [RA-171](Architecture_M6_CP3_TB50_REV_Gate_Closeout_Census_Observe_Harness_20261029.md): TB50-R2 verified; census contract P7; manifest re-frozen `91823900…`. |
| done | `M6-CP3-CB50C-RP01-CENSUS-HARNESS-ORCH` | CB / I | P7 exact, SHA-256 `600c6455…`; offline 21/21 and 504/508/408 checks; [run 40962940548](https://github.com/akashskypatel/Directional/actions/runs/40962940548), commit `9355721b6739…`; no native run. |
| done | `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC-R2` | TB-EXEC / I | [Run 40965775275](https://github.com/akashskypatel/Directional/actions/runs/40965775275): 408/408, 323 PASS, 83 RED, 2 ABNORMAL, 0 INVALID. Postflight true; no classification. |
| 1 — NEXT | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` | DEFN / R | Classify each non-PASS row (stale oracle / regression / O2 legacy / platform / retire), grouped by first failure; exact patches; freeze TB51 manifest. |
| 3 | CB53… (one per cause group) → `M6-CP3-TB51-RP01-FULL-GATE-EXEC` → `M6-CP3-TB51-RP01-FULL-GATE-REV` | CB, TB-EXEC / I; TB-REV / R | TB51 = 508 + (408 − retired) (RA-171.5). |
| 4 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | O6 scope; O7–O12 owners; O9 junction path. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 legacy-path reachability folds into O2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | CB50C stop → `M6-CP3-PLAN-RP01-CENSUS-HARNESS-STOP`; CB50C orchestration → `M6-CP3-CB50CA-RP01-ORCH`; TB50C-R2 without a complete ledger → the same PLAN stop. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION** (DEFN, Review): read the complete 85-row non-PASS evidence and per-suite counts in the TB50C-R2 report; group first failures, classify observations, and define exact patches/retirements before freezing TB51 manifest. Do not implement or run native work in DEFN. CP2 accepted, TB50-R2 508/0 reviewed candidate, regression 66/17/49 debt1 unchanged.

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
