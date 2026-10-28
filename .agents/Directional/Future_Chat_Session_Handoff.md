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
| Currency | 2026-10-28, after TB49 immutable 504 PASS / 0 RED (independent evidence verified; authentic review closeout pending), following CB49E (exact P2 code + compile), following [RA-168](Architecture_M6_CP3_TB48_REV_Audit_G3_A5_Gauge_And_E2_Rail_Vertex_Patches_20261028.md): audit of `M6-CP3-TB48-RP01-FULL-GATE-REV` plus completion of both Review-track DEFNs (`M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE`, `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH`). TB48 evidence verified (502/2). Corrections: P-G3 is an **A5** defect (`periodic_endpoint_gauge`, `RemeshPipeline.cpp:4793–4820`), not A4; E2 is a stale junction-era oracle, since A4 already publishes the RA-166 D2 R-split. Exact probe-verified patches P1 (`5897798d…`) and P2 (`9ebef3cc…`). Turn IDs follow `turn_type_from_turn` (RA-167.6). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB49 **504 PASS / 0 RED** artifact-only ([report](Architecture_M6_CP3_TB49_RP01_Full_Gate_Test_Benchmark_Report_20261028.md), [run 40776332136](https://github.com/akashskypatel/Directional/actions/runs/40776332136), result 12857282498); CB49E compile-only `092b52eba881e3bafbff4fa263f84f96cf648838` ([record](Architecture_M6_CP3_CB49E_RP01_E2_Rail_Vertex_Adjacency_Code_Build_Record_20261028.md), run 40770409537, artifact 12852132570, 28/28 package members); CB49 compile-only `9c84ba9cc8e44acf556d17e2357b1e9458337cca` ([record](Architecture_M6_CP3_CB49_RP01_G3_A5_Periodic_Placement_Gauge_Code_Build_Record_20261028.md), run 40766433076, artifact 12850662095); TB48 **502/2** independently reviewed candidate, run `40731722985`, result `12836819707`; CB48 compile-only package **12834041300** / source `4c611941…` unpromoted; TB47 **500/4** valid expected-RED ([report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md); CB47 source `08d41626e`, package `12732383172`, result `12734719880`). Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)); P-G3 non-stable (unpromoted evidence), owner re-assigned to A5 by RA-168; E2 is test-authority, not a producer defect. |
| Active boundary | RP-01 open, RP-02 unreached. [TB49 manifest](Architecture_M6_CP3_TB49_Full_Gate_Case_Manifest.tsv) `a0e39fa25d70…` (kept by RA-168.1) predicts 504/0 after CB49 + CB49E; RA-168 local probe of all 504 cases: 502/504, with rows 492/493 passing; rows 283/445 fail on macOS with unpatched production too and pass on CI. Carried: O1, O2, O6, O7, O8, O9 (now test-locked: no junctions), O10, O11 (5 off-gate TQ tests), O12, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-TB49-RP01-FULL-GATE-REV` (type TB-REV) — EXACT NEXT

- **Entry evidence:** TB49 immutable full gate **504 PASS / 0 RED** on CB49E exact `092b52eba881e3bafbff4fa263f84f96cf648838` package, run `40776332136`, result `12857282498` (ZIP `3113383ccc64bda5747e9f115e95cafa60e67f569f84b40b22ed6c69cea692db`); 504/504 row/native-log coverage and verified immutable postflight. [Owning report](Architecture_M6_CP3_TB49_RP01_Full_Gate_Test_Benchmark_Report_20261028.md).
- **Authority:** RA-168.6 and frozen TB49 manifest `a0e39fa25d70…`. [Independent evidence record](Architecture_M6_CP3_TB49_RP01_Full_Gate_Independent_Review_Decision_20261028.md) reverified 1,014 result hashes, 28 package hashes, 504 exact native log joins and unchanged 491 accepted prefix. Full canonical Review remains open until authentic-Git history/boundary, document drift and remote closeout complete. Do not count TB-EXEC or selected gate success as CP3 milestone acceptance.
- **Frozen:** CP2 491/491 accepted; stable 66/17/49, debt1; selector497 unpromoted. PR #8 remains draft/open; CP3/RP-01 open pending independent Review. Do not start CB50 or RP-01 closure before Review authorization.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | TB48 (502/2) → `M6-CP3-TB48-RP01-FULL-GATE-REV` → RA-168 audit + `M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE` + `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` | TB-REV; DEFN / R | P-G3 → A5; E2 → D2; P1/P2 probed. |
| done | `M6-CP3-CB49-RP01-G3-A5-PERIODIC-PLACEMENT-GAUGE` | CB / I | Exact P1 compiled at `9c84ba9cc8e4`; [record](Architecture_M6_CP3_CB49_RP01_G3_A5_Periodic_Placement_Gauge_Code_Build_Record_20261028.md). |
| done | `M6-CP3-CB49E-RP01-E2-RAIL-VERTEX-ADJACENCY` | CB / I | Exact P2 compiled at `092b52eba881`; [record](Architecture_M6_CP3_CB49E_RP01_E2_Rail_Vertex_Adjacency_Code_Build_Record_20261028.md). |
| done | `M6-CP3-TB49-RP01-FULL-GATE-EXEC` | TB-EXEC / I | Observed 504 PASS / 0 RED; run 40776332136, artifact 12857282498. |
| 1 — active | `M6-CP3-TB49-RP01-FULL-GATE-REV` | TB-REV / R | 504/0 and frozen prefix independently verified; authentic-history review boundary and durable closeout still pending. |
| 5 | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` → `M6-CP3-CB50-RP01-O4-O5-RAIL-PROVENANCE` → `M6-CP3-TB50-RP01-FULL-GATE-EXEC` → `…-REV` | DEFN → CB → TB | O4, O5, P1-a/P1-b, RA-162 C1. |
| 6 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | RP-01 Review: O6 scope; O7–O12 owners; O9 junction-path retirement. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2. |
| rule | RA-167.6 naming; RA-164.3 P1–P6; RA-165.2 F1/F2; RA-166.6 F6/F7; RA-168 oracle rule | — | DEFN/PLAN IDs carry no `-CB<n>`/`-TB<n>` segment and no final R+letters qualifier. No R1…Rn same-turn loops. STOP S1–S3 → `PLAN-RP01-<topic>-STOP`; S4 → `TB<n>-…-REV`; S5 → `CB<n>A-RP01-ORCH` → `TB<n>-…-EXEC-R<k>`. One CB per patch. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB49-RP01-FULL-GATE-REV** (TB-REV) — independently verify [TB49 report](Architecture_M6_CP3_TB49_RP01_Full_Gate_Test_Benchmark_Report_20261028.md), immutable result artifact `12857282498`, 504 case/ledger/raw-log identities, source and execution authority, and RA-168 §.6. Adjudicate CP3 admission; no production/code/test mutations in Review.

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
