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
| Currency | 2026-10-28, after [RA-169](Architecture_M6_CP3_TB49_REV_Closeout_C1_Rail_Cover_DEFN_Patches_20261028.md): `M6-CP3-TB49-RP01-FULL-GATE-REV` **COMPLETE** (authentic-history `review_check.py boundary` and `ledgers` PASS; CB49/CB49E bytes equal RA-168 P1/P2) and Review DEFN `M6-CP3-DEFN-RP01-C1-ORPHAN-HARD-EDGE-COVER` complete. RA-162 C1 confirmed by probe: the checked factory accepts an orphan hard edge when open rails exist (masked on 3×3 fixtures by `gauge-pin-span`), and the A4 consumer runs on unchecked rail authority. Exact P3 (ingress) and P4 (factory) patches; the bundled O4/O5 DEFN is split per mechanism (RA-169.8). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB49 **504 PASS / 0 RED** artifact-only ([report](Architecture_M6_CP3_TB49_RP01_Full_Gate_Test_Benchmark_Report_20261028.md), [run 40776332136](https://github.com/akashskypatel/Directional/actions/runs/40776332136), result 12857282498); CB49E compile-only `092b52eba881e3bafbff4fa263f84f96cf648838` ([record](Architecture_M6_CP3_CB49E_RP01_E2_Rail_Vertex_Adjacency_Code_Build_Record_20261028.md), run 40770409537, artifact 12852132570, 28/28 package members); CB49 compile-only `9c84ba9cc8e44acf556d17e2357b1e9458337cca` ([record](Architecture_M6_CP3_CB49_RP01_G3_A5_Periodic_Placement_Gauge_Code_Build_Record_20261028.md), run 40766433076, artifact 12850662095); TB48 **502/2** independently reviewed candidate, run `40731722985`, result `12836819707`; CB48 compile-only package **12834041300** / source `4c611941…` unpromoted; TB47 **500/4** valid expected-RED ([report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md); CB47 source `08d41626e`, package `12732383172`, result `12734719880`). Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)); TB49 504/0 adds no stable event. C1 is a production-unreachable fail-closed gap (no accepted-green loss). |
| Active boundary | RP-01 open, RP-02 unreached. [TB50 manifest](Architecture_M6_CP3_TB50_Full_Gate_Case_Manifest.tsv) `6d5b788671487fa2…` (508 rows: TB49 504 + 7414/7614 guards + two C1 positives) predicts 508/0 after CB50 + CB50F; local probe in RA-169.4. Carried: O1, O2, O6, O7, O8, O9, O10, O11 (5 off-gate TQ tests), O12, O13 (off-gate `ProducedHardCarriersAreAtlasBarriers…` RED at HEAD), P1-a (8219 RED, off-gate), P1-b, O4, O5 coverage, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` (type CB) — EXACT NEXT

- **Authority:** [RA-169](Architecture_M6_CP3_TB49_REV_Closeout_C1_Rail_Cover_DEFN_Patches_20261028.md).5. Extract the RA-169.10 `~~~diff` block verbatim (+ trailing newline); SHA-256 must be `9874d1269b052aa975b4a42bf085ea48acfba1773246c973b05f76d492a1c1fb`; `git apply`, no hand edits. Numstat exactly `37 0 src/geometry/SurfaceCellTracing.cpp`, `47 0 tests/SurfaceCellsPhase10Tests.cpp`.
- **Evidence:** established eight GMP/GMPXX targets, `runtimeExecution=false`, record ≤25 lines. No tests, no other edits; do not combine with CB50F.
- **Outcome:** compile OK + exact numstat → `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` (RA-169.6, P4 `c8af43a28a7aa694d8cb2c43d461773061b34f2ba811649509d3def95127a426`) → `M6-CP3-TB50-RP01-FULL-GATE-EXEC`. Apply/compile failure → `M6-CP3-PLAN-RP01-C1-COVER-STOP` (Review). Orchestration failure → `M6-CP3-CB50A-RP01-ORCH`, then retry.
- **Frozen:** CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted; TB49 504/0 is a reviewed candidate, not CP3 acceptance.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | CB49 → CB49E → TB49-EXEC (504/0) → `M6-CP3-TB49-RP01-FULL-GATE-REV` + `M6-CP3-DEFN-RP01-C1-ORPHAN-HARD-EDGE-COVER` | CB, TB / I; TB-REV, DEFN / R | RA-168 patches exact; RA-169 history checks PASS; C1 probed. |
| 1 — next | `M6-CP3-CB50-RP01-C1-INGRESS-ORPHAN-HARD-EDGE` | CB / I | Exact P3 (RA-169.5/.10); compile only. |
| 2 | `M6-CP3-CB50F-RP01-C1-FACTORY-RAIL-COVER` | CB / I | Exact P4 on CB50 (RA-169.6/.11); compile only. |
| 3 | `M6-CP3-TB50-RP01-FULL-GATE-EXEC` | TB-EXEC / I | Manifest `6d5b7886…`, 508 rows; predict 508/0. |
| 4 | `M6-CP3-TB50-RP01-FULL-GATE-REV` | TB-REV / R | Independent review of TB50. |
| ∥ 1–4 | `M6-CP3-DEFN-RP01-P1A-TERMINAL-A3-PATH-WITNESS` → `M6-CP3-DEFN-RP01-P1B-NETWORK-OWNERSHIP-DIFFERENTIAL` → `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-WITNESS` | DEFN / R | RA-169.8; probe-backed; each emits one exact patch or an accepted-defensive classification. |
| 5 | CB51, CB52, … (one per DEFN patch) → `M6-CP3-TB51-RP01-FULL-GATE-EXEC` → `…-REV` | CB, TB / I, R | Manifest frozen by the last DEFN. |
| 6 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | O5 off-selector coverage, O6 scope, O7–O12 owners, O9 junction path. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | STOP S1–S3 → `M6-CP3-PLAN-RP01-C1-COVER-STOP`; S5 → `M6-CP3-CB50A-RP01-ORCH` → `M6-CP3-TB50-RP01-FULL-GATE-EXEC-R2`. Superseded: `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE`, `M6-CP3-CB50-RP01-O4-O5-RAIL-PROVENANCE`. |

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
