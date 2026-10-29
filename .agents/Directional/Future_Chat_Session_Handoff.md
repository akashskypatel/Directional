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
| Currency | 2026-10-28, after [RA-170](Architecture_M6_CP3_TB49_REV_Reaudit_P1_O4_DEFNs_E2_Site_Pins_OffGate_Census_20261028.md): TB49 504/0 independently re-derived (artifact 12857282498: 1014/1014, 504 manifest–ledger–log joins; package 12852132570 source `092b52eba881`); [RA-169](Architecture_M6_CP3_TB49_REV_Closeout_C1_Rail_Cover_DEFN_Patches_20261028.md) C1 patches show no gate or off-gate regression; Review DEFNs P1-a (accepted-defensive, O9), P1-b (rail-ID-swap witness, P5) and O4 (accepted-defensive) complete; cp3entry:2 negatives were code-only and are pinned to sites (P6). **Trajectory correction:** 101/408 off-gate tests in the four gate binaries fail locally at HEAD; RP-01 needs a CI census (TB50C) and the O5 disposition DEFN before closure. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB49 **504 PASS / 0 RED** artifact-only ([report](Architecture_M6_CP3_TB49_RP01_Full_Gate_Test_Benchmark_Report_20261028.md), [run 40776332136](https://github.com/akashskypatel/Directional/actions/runs/40776332136), result 12857282498); CB49E compile-only `092b52eba881e3bafbff4fa263f84f96cf648838` ([record](Architecture_M6_CP3_CB49E_RP01_E2_Rail_Vertex_Adjacency_Code_Build_Record_20261028.md), run 40770409537, artifact 12852132570, 28/28 package members); CB49 compile-only `9c84ba9cc8e44acf556d17e2357b1e9458337cca` ([record](Architecture_M6_CP3_CB49_RP01_G3_A5_Periodic_Placement_Gauge_Code_Build_Record_20261028.md), run 40766433076, artifact 12850662095); TB48 **502/2** independently reviewed candidate, run `40731722985`, result `12836819707`; CB48 compile-only package **12834041300** / source `4c611941…` unpromoted; TB47 **500/4** valid expected-RED ([report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md); CB47 source `08d41626e`, package `12732383172`, result `12734719880`). Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)); no new stable event. Off-gate REDs are unclassified census data (local macOS 101/408; CI pending via TB50C) — not yet counted as regressions or as platform. |
| Active boundary | RP-01 open, RP-02 unreached. [TB50 manifest](Architecture_M6_CP3_TB50_Full_Gate_Case_Manifest.tsv) `6d5b788671487fa2…` (508; predict 508/0 after CB50–CB52); [TB50C census manifest](Architecture_M6_CP3_TB50C_Off_Gate_Census_Case_Manifest.tsv) `800e7f26d7ef8935…` (408 off-gate rows, observe only). Carried: O1, O2, O6–O12, O13, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002; 8219 and all off-gate REDs go to `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION`. |

## Mandatory next turn — `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` (type CB) — EXACT NEXT

- **Authority:** [RA-169](Architecture_M6_CP3_TB49_REV_Closeout_C1_Rail_Cover_DEFN_Patches_20261028.md).5 (re-confirmed by [RA-170](Architecture_M6_CP3_TB49_REV_Reaudit_P1_O4_DEFNs_E2_Site_Pins_OffGate_Census_20261028.md).4). Extract the RA-169.10 `~~~diff` block verbatim (+ trailing newline); SHA-256 must be `9874d1269b052aa975b4a42bf085ea48acfba1773246c973b05f76d492a1c1fb`; `git apply`, no hand edits. Numstat exactly `37 0 src/geometry/SurfaceCellTracing.cpp`, `47 0 tests/SurfaceCellsPhase10Tests.cpp`.
- **Evidence:** established eight GMP/GMPXX targets, `runtimeExecution=false`, record ≤25 lines. No tests; do not combine with any later CB.
- **Outcome:** compile OK + exact numstat → `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` (P4) → `M6-CP3-CB51-RP01-P1B-NETWORK-OWNER-WITNESS` (P5) → `M6-CP3-CB52-RP01-E2-FACTORY-SITE-PINS` (P6) → TB50-EXEC → TB50C-EXEC. Apply/compile failure → `M6-CP3-PLAN-RP01-C1-COVER-STOP` (Review). Orchestration failure → `M6-CP3-CB50A-RP01-ORCH`, then retry.
- **Frozen:** CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted; TB49 504/0 is a reviewed candidate, not CP3 acceptance.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → CB49E → TB49-EXEC (504/0) → `M6-CP3-TB49-RP01-FULL-GATE-REV` (RA-169, re-derived RA-170.1); DEFNs C1, P1-a, P1-b, O4 | CB, TB / I; TB-REV, DEFN / R | RA-169/170 probes; P3–P6 round-trip exact. |
| 1 — next | `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` | CB / I | P3 (RA-169.10); compile only. |
| 2 | `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` | CB / I | P4 (RA-169.11) on CB50. |
| 3 | `M6-CP3-CB51-RP01-P1B-NETWORK-OWNER-WITNESS` | CB / I | P5 (RA-170.7) on CB50F; test-only. |
| 4 | `M6-CP3-CB52-RP01-E2-FACTORY-SITE-PINS` | CB / I | P6 (RA-170.8) on CB51; test-only. |
| 5 | `M6-CP3-TB50-RP01-FULL-GATE-EXEC` | TB-EXEC / I | CB52 package; manifest `6d5b7886…` (508); predict 508/0. |
| 6 | `M6-CP3-TB50C-RP01-OFF-GATE-CENSUS-EXEC` | TB-EXEC / I | Same package; manifest `800e7f26…` (408); observe, no prediction. |
| 7 | `M6-CP3-TB50-RP01-FULL-GATE-REV` | TB-REV / R | Adjudicates TB50 and TB50C. |
| 8 | `M6-CP3-DEFN-RP01-OFF-SELECTOR-COVERAGE-DISPOSITION` | DEFN / R | Classify each CI RED (stale oracle / regression / O2 legacy / retire); exact patches; freeze TB51 manifest. |
| 9 | CB53… (one per disposition patch) → `M6-CP3-TB51-RP01-FULL-GATE-EXEC` → `M6-CP3-TB51-RP01-FULL-GATE-REV` | CB, TB / I, R | — |
| 10 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | O6 scope; O7–O12 owners; O9 junction path. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2; O4 legacy-path reachability folds into O2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | STOP S1–S3 → `M6-CP3-PLAN-RP01-C1-COVER-STOP`; S5 → `M6-CP3-CB50A-RP01-ORCH` → `…-EXEC-R2`. Superseded: `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE`, RA-169.8 placeholder CB51/CB52. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE** (CB) — load [RA-169](Architecture_M6_CP3_TB49_REV_Closeout_C1_Rail_Cover_DEFN_Patches_20261028.md) §.5 and §.10 only; apply the exact P3 block, compile the eight GMP targets, no runtime.

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
