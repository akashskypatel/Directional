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
| Currency | 2026-10-29 CB50A harness/manifest S5 correction: **508/508 schema self-check only; native runtime not executed** ([CB50A record](Architecture_M6_CP3_CB50A_RP01_Orchestration_Correction_Record_20261029.md)); preceding TB50 CI preflight S5 **0/508 executed** ([report](Architecture_M6_CP3_TB50_RP01_Full_Gate_Orchestration_Failure_Report_20261029.md)); next TB50-EXEC-R2. After exact CB52 P6 test-only source `7cf0857b4818186638ce77e4859adacbeebd288f` and compile-only [CB52](Architecture_M6_CP3_CB52_RP01_E2_Factory_Site_Pins_Code_Build_Record_20261029.md); no new runtime. TB49 504/0 remains reviewed candidate; CP2 491/491 accepted; 101/408 locally RED off-gate cases await TB50C census; selector497 unpromoted, stable 66/17/49 debt1, RP-01 open. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB50 frozen 508 manifest and CB52 GMP package; [run 40934197625](https://github.com/akashskypatel/Directional/actions/runs/40934197625) failed during site-pin preflight `row 505: unexpected asserted-site pin` (rows 505–508 invalid), 0/508 executed, [S5 report](Architecture_M6_CP3_TB50_RP01_Full_Gate_Orchestration_Failure_Report_20261029.md), neither accepted nor semantic RED. Earlier CB52 exact P6 source `7cf0857b4818186638ce77e4859adacbeebd288f` / [compile-only record](Architecture_M6_CP3_CB52_RP01_E2_Factory_Site_Pins_Code_Build_Record_20261029.md), [run 40919618039](https://github.com/akashskypatel/Directional/actions/runs/40919618039), package `12918290481`, no runtime; CB51 exact P5 source `699837c68583f4039dc7971d3b4e0da57135d933` / [compile-only record](Architecture_M6_CP3_CB51_RP01_P1B_Network_Owner_Witness_Code_Build_Record_20261029.md), [run 40912598472](https://github.com/akashskypatel/Directional/actions/runs/40912598472), package `12914112895`, no runtime; CB50F exact P4 source `b8c07a6f24664e0de70026951c9ab3dd408d8f80` / [compile-only record](Architecture_M6_CP3_CB50F_RP01_C1_Factory_Rail_Cover_Code_Build_Record_20261029.md), no runtime; CB50 exact P3 source `88249ebbb27b997a6cbc7b3cf71bb57e4a77e53f`; TB49 **504 PASS / 0 RED** artifact-only ([report](Architecture_M6_CP3_TB49_RP01_Full_Gate_Test_Benchmark_Report_20261028.md), [run 40776332136](https://github.com/akashskypatel/Directional/actions/runs/40776332136), result 12857282498); CB49E compile-only `092b52eba881e3bafbff4fa263f84f96cf648838` ([record](Architecture_M6_CP3_CB49E_RP01_E2_Rail_Vertex_Adjacency_Code_Build_Record_20261028.md), run 40770409537, artifact 12852132570, 28/28 package members); CB49 compile-only `9c84ba9cc8e44acf556d17e2357b1e9458337cca` ([record](Architecture_M6_CP3_CB49_RP01_G3_A5_Periodic_Placement_Gauge_Code_Build_Record_20261028.md), run 40766433076, artifact 12850662095); TB48 **502/2** independently reviewed candidate, run `40731722985`, result `12836819707`; CB48 compile-only package **12834041300** / source `4c611941…` unpromoted; TB47 **500/4** valid expected-RED ([report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md); CB47 source `08d41626e`, package `12732383172`, result `12734719880`). Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)); no new stable event. Off-gate REDs are unclassified census data (local macOS 101/408; CI pending via TB50C) — not yet counted as regressions or as platform. |
| Active boundary | **S5 reconciled by CB50A**: rows 505–508 were typed native assertion reasons, not GoogleTest first-failure pins. Strict 508-row self-check passed; corrected manifest SHA-256 `eef8855e27df9401545a62afab7aea6c9a882bb4a15c58545f2cb49d62fc7caa` (unchanged harness). NEXT `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2` must run the immutable CB52 package before semantic acceptance. RP-01 open, RP-02 unreached. [TB50 manifest](Architecture_M6_CP3_TB50_Full_Gate_Case_Manifest.tsv) `6d5b788671487fa2…` (508; predict 508/0 after CB50–CB52); [TB50C census manifest](Architecture_M6_CP3_TB50C_Off_Gate_Census_Case_Manifest.tsv) `800e7f26d7ef8935…` (408 off-gate rows, observe only). Carried: O1, O2, O6–O12, O13, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002; 8219 and all off-gate REDs go to `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION`. |

## Mandatory next turn — `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2` (type TB-EXEC) — EXACT NEXT

- **Authority:** [CB50A corrected orchestration record](Architecture_M6_CP3_CB50A_RP01_Orchestration_Correction_Record_20261029.md) and [preceding S5 report](Architecture_M6_CP3_TB50_RP01_Full_Gate_Orchestration_Failure_Report_20261029.md). This is a *separate* artifact-only execution turn; do not rerun CB50A or modify the harness/manifest during it.
- **Inputs:** exact compiled CB52 package source `7cf0857b4818186638ce77e4859adacbeebd288f`, artifact `12918290481` (ZIP `89449f4f9c014c1d8c3235056c3dca2d2239ba136e09dd88e3e02710b253b5c1`); manifest `Architecture_M6_CP3_TB50_Full_Gate_Case_Manifest.tsv` SHA-256 `eef8855e27df9401545a62afab7aea6c9a882bb4a15c58545f2cb49d62fc7caa`; unchanged `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` SHA-256 `142321061c57d130a9c73548ce93f52147ebeaeb4c45d3d1c48830e72e2ef93d`; 508 rows.
- **Execution:** use durable artifact-only `test_benchmark` dispatcher, exact immutable source/package and checksums, no rebuilding/relinking. Record all 508 outcomes and first-failure evidence; do not infer green from harness preflight or earlier local macOS probes.
- **Success/failure evidence:** compare exact per-row outputs, raw logs, and ledger to frozen manifest, record regressions without changing accepted selector; then authorize the separate TB50C census as scheduled. Preserve CP2 491/491 accepted, TB49 504/0 candidate, stable 66/17/49 debt1, RP-01 open.

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
| 5B — NEXT | `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2` | TB-EXEC / I | Separate corrected frozen manifest against an authorized immutable package; 508 prediction unverified. |
| 6 | `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC` | TB-EXEC / I | Same package; manifest `800e7f26…` (408); observe, no prediction. |
| 7 | `M6-CP3-TB50-RP01-FULL-GATE-REV` | TB-REV / R | Adjudicates TB50 and TB50C. |
| 8 | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` | DEFN / R | Classify each CI RED (stale oracle / regression / O2 legacy / retire); exact patches; freeze TB51 manifest. |
| 9 | CB53… (one per disposition patch) → `M6-CP3-TB51-RP01-FULL-GATE-EXEC` → `M6-CP3-TB51-RP01-FULL-GATE-REV` | CB, TB / I, R | — |
| 10 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | O6 scope; O7–O12 owners; O9 junction path. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 legacy-path reachability folds into O2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | STOP S1–S3 → `M6-CP3-PLAN-RP01-C1-COVER-STOP`; S5 → `M6-CP3-CB50A-RP01-ORCH` → `…-EXEC-R2`. Superseded: `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE`, RA-169.8 placeholder CB51/CB52. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2** (TB-EXEC) — run corrected 508-case manifest `eef8855e27df9401545a62afab7aea6c9a882bb4a15c58545f2cb49d62fc7caa` against immutable CB52 GMP package `12918290481` with unchanged harness; see [CB50A record](Architecture_M6_CP3_CB50A_RP01_Orchestration_Correction_Record_20261029.md). No source/test/harness/manifest modifications or compilation within TB. Expected 508/0 is unverified.

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
