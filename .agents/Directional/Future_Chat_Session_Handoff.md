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
| Currency | 2026-10-28, after verified TB48 immutable gate 502/2 ([report](Architecture_M6_CP3_TB48_RP01_Full_Gate_Test_Benchmark_Report_20261028.md)) and CB48 exact-test compile ([record](Architecture_M6_CP3_CB48_RP01_Gauge_Cluster_Tests_Code_Build_Record_20261028.md)) and [RA-167](Architecture_M6_CP3_TB47_REV_Gauge_Cluster_Decision_And_Canonical_Turn_Sequence_20261028.md) (`M6-CP3-TB47-RP01-FULL-GATE-REV`, type TB-REV). It closes the stalled `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (R1–R62 kept as provenance), which the canonical classifier labels TB-EXEC. Probe-backed gauge-cluster decisions: G1 and G2 test-authority errors re-homed (both pass); G3 re-homed to a source odd-gauge witness that exposes production defect **P-G3** (A4 periodic endpoint states not gauge-covariant). Turn IDs follow `turn_type_from_turn` (RA-167.6). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB48 **502/2** verified candidate, run `40731722985`, result `12836819707`; CB48 compile-only package **12834041300** / source `4c611941…` unpromoted; TB47 **500/4** valid expected-RED ([report](Architecture_M6_CP3_TB47_RP01_Full_Gate_Test_Benchmark_Report_20261027.md); CB47 source `08d41626e`, package `12732383172`, result `12734719880`). Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). P-G3 reproduced on CI in TB48; stable-ledger adjudication remains Review-owned. |
| Active boundary | RP-01 open, RP-02 unreached. [TB48 manifest](Architecture_M6_CP3_TB48_Full_Gate_Case_Manifest.tsv) `a3187d55…00bb` observed **502/2**: cp3entry:1 RED `TQ:3027` (P-G3), cp3entry:2 RED `TQ:3183` (E2). Carried: O1, O2, O6, O7, O8, O9, **O10** (non-hard isolation-barrier producer), **O11** (5 off-gate TQ tests failing at HEAD), **O12** (R61 `review_check.py` selector collision), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-TB48-RP01-FULL-GATE-REV` (type TB-REV) — EXACT NEXT

- **Authority:** RA-167.5/6 and [TB48 report](Architecture_M6_CP3_TB48_RP01_Full_Gate_Test_Benchmark_Report_20261028.md); immutable source `4c611941f0bee7dc2515755fbd159402463879e2`, artifact `12834041300`, run `40731722985`, result `12836819707`. Independently verify 504/504 result and the two first-site REDs (`TQ:3027`, `TQ:3183`), confirm P-G3 CI-produced witness, review stable regression accounting and freeze the exact TB49 manifest as authorized.
- **Scope/stop:** Review only; no Code + Build, harness, source, fixture, selector, or manifest mutation in this TB48-EXEC. CB49 and CB49E are not authorized until Review closes. Preserve CP2 491/491 accepted, selector497 frozen, RP-01 open.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | TB47 (500/4) → stalled DEFN-G (R1–R62) → RA-167 `M6-CP3-TB47-RP01-FULL-GATE-REV` | TB-REV / R | G1/G2 re-homed; G3 witness → P-G3. |
| 1 — complete | `M6-CP3-CB48-RP01-GAUGE-CLUSTER-TESTS` | CB / I | Exact patch `b32d6381…`; 8 targets compiled. |
| 2 — complete (502/2) | `M6-CP3-TB48-RP01-FULL-GATE-EXEC` | TB-EXEC / I | Predict 502/2 → step 3. |
| 1∥ | `M6-CP3-DEFN-RP01-G3-PERIODIC-GAUGE-COVARIANCE` | DEFN / R | Root-cause and probe-verified production patch for P-G3 (`SCT:19088–19123`, `:8194–8218`). |
| 2∥ | `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` | DEFN / R | Exact cp3entry:2 rewrite to RA-166 D2. |
| 3 — next | `M6-CP3-TB48-RP01-FULL-GATE-REV` | TB-REV / R | Confirms TB48; freezes TB49 manifest; releases steps 4 and 5. |
| 4 | `M6-CP3-CB49-RP01-G3-PERIODIC-ENDPOINT-STATE` → `M6-CP3-CB49E-RP01-E2-RAIL-VERTEX-ADJACENCY` | CB / I | Exact patches. |
| 5 | `M6-CP3-TB49-RP01-FULL-GATE-EXEC` → `M6-CP3-TB49-RP01-FULL-GATE-REV` | TB-EXEC / I → TB-REV / R | Predict 504/0, a green full gate. |
| 6 | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` → `M6-CP3-CB50-RP01-O4-O5-RAIL-PROVENANCE` → `M6-CP3-TB50-RP01-FULL-GATE-EXEC` → `…-REV` | DEFN → CB → TB | O4, O5, P1-a/P1-b, RA-162 C1. |
| 7 | `M6-CP3-PLAN-RP01-CLOSURE` | PLAN / R | RP-01 Review: O6 scope; O7–O12 owners. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS`, then `M6-DEFN-DIAG-RETAIN-A5-A7` | DEFN / R | RA-160.4 + RA-161 T2. |
| rule | RA-167.6 naming; RA-164.3 P1–P6; RA-165.2 F1/F2; RA-166.6 F6/F7 | — | DEFN/PLAN IDs carry no `-CB<n>`/`-TB<n>` segment and no final R+letters qualifier. A DEFN or PLAN that cannot finish closes BLOCKED with a named successor; no R1…Rn same-turn loops. STOP codes S1–S3 → `PLAN-RP01-<topic>-STOP`; S4 → `TB<n>-…-REV`; S5 → `CB<n>A-RP01-ORCH` → `TB<n>-…-EXEC-R<k>`. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB48-RP01-FULL-GATE-REV** (TB-REV) — read [RA-167.5](Architecture_M6_CP3_TB47_REV_Gauge_Cluster_Decision_And_Canonical_Turn_Sequence_20261028.md); independently verify TB48 immutable result `12836819707` and frozen TB48 manifest `a3187d55…`; decide P-G3 stable accounting, preserve E2, freeze TB49 manifest; no successor implementation before Review.

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
