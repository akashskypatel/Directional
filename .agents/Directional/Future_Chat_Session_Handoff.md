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
| Currency | 2026-10-27, after [RA-166](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md) (CB47-REV). The CB47 E3 conflict is confirmed and resolved: RA-33.5 and the DEFN-E E3 witness demanded a nonempty `route` on `OrdinaryInterior` sides, which A5 forbids (`RP:3643–3650`) and A4 never writes. D5 is re-homed to boundary-path `entryRoute` crossings on `transition_domain_fixture()`. The D2 junction is re-homed to rail-vertex R-adjacency, because R-split is the canonical A4 representation (scratch sweep). The compiled E1 commit `dabb0970e` is defective; the exact probe-verified patch [Architecture_M6_CP3_RA166_CB47_Exact_Test_Patch_20261027.patch](Architecture_M6_CP3_RA166_CB47_Exact_Test_Patch_20261027.patch) (`2de51be6…24c1`) replaces it. RA-164.3 P1–P6, RA-165.2 F1/F2 and RA-166.6 F6/F7 bind. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB46 re-run **498/6** valid expected-RED ([report](Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md), result `12719412600`). [CB47A](Architecture_M6_CP3_CB47A_Harness_Manifest_Pins_Code_Record_20261027.md): manifest-driven pins, offline replay 504/504. CB47 E1 compile run `40489392387` (artifact `12728075441`) is superseded for gating ([interim](Architecture_M6_CP3_CB47_Endpoint_Witnesses_Interim_Investigation_20261027.md)). Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. [TB47 manifest](Architecture_M6_CP3_TB47_Full_Gate_Case_Manifest.tsv) **v2** `488a20b6…5955`, predicting **500/4**: RED `focused30:12` `:5581`, `selector:442`, cp3entry:1 `:2916`, cp3entry:2 `:3154`; 201 and cp3entry:4 POSITIVE. cp3entry:2's rewrite goes to Review-owned exact-patch turn E2-PATCH. Carried: O1, O2 (post-RP-01, + RA-161 T2), O6, O7, **O8** (producer `InvalidFrontBoundaryAuthority` at `lengthRatio=0.29`), **O9** (A4 junction path unwitnessed, no consumer), DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES` (resume) — EXACT NEXT

- **Authority:** [RA-166.4](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md). This supersedes the DEFN-E E2/E3 CB scope. Test-only Code + Build, compile only.
- **Action:** `git apply` exactly [Architecture_M6_CP3_RA166_CB47_Exact_Test_Patch_20261027.patch](Architecture_M6_CP3_RA166_CB47_Exact_Test_Patch_20261027.patch) (SHA-256 `2de51be649141f992871e48e93364e1ae6f7a91899dfa669f886b5151e4624c1`) on HEAD `764fa4e5d` lineage. Expected numstat: `26 18 tests/SurfaceCellREPackageTests.cpp`, `24 6 tests/SurfaceCellTransitionQuotientTests.cpp`. No other byte may change and no hand edits are allowed.
- **Evidence:** the established eight GMP/GMPXX targets, `runtimeExecution=false`, a record of at most 25 lines.
- **Outcome table:**
  - compile OK + exact numstat → `M6-CP3-TB47-RP01-FULL-GATE` (manifest v2, predict 500/4, table RA-166.5);
  - patch does not apply → S3; C2 compile error → S2 (no in-hunk edits). Both → `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES-REV`;
  - orchestration failure → Turn_Cadence rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB46 re-run → DEFN-E → CB47A → CB47 (BLOCKED on E3) → RA-166 | E3/D2 witness definitions re-homed; E1 defect fixed by exact patch. |
| 1 — next | `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES` (resume) | Exact RA-166 patch; 8 targets; → step 2 directly. |
| 2 | `M6-CP3-TB47-RP01-FULL-GATE` | Manifest v2 `488a20b6…`; predict 500/4; exit 0 → step 3; `control_violation` → TB47-REV; infra → `M6-CP3-TB47A-ORCH`. |
| 3 | `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review, probe-backed) | Absorbs TB47; decides G (442, `focused30:12`, cp3entry:1); emits exact hunks + TB48 manifest. |
| 4 | `M6-CP3-DEFN-RP01-E2-RAIL-VERTEX-ADJACENCY-PATCH` (Review, probe-backed) | Exact cp3entry:2 rewrite to RA-166.3 D2; junction tamper sections disposed per O9. |
| 5 | `M6-CP3-CB48-…` (G) → `M6-CP3-CB48E-RP01-E2-RAIL-VERTEX-ADJACENCY` → `M6-CP3-TB48-RP01-FULL-GATE` | Exact patches only. |
| 6 | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review) → CB49 → TB49 | O4, O5, P1-a/P1-b, RA-162 C1, H2 A5 reachability. |
| 7 | Green full gate → RP-01 Review | O6 scope; O7/O8/O9 owners. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT`, then `DIAG-RETAIN` | RA-160.4 + RA-161 T2. |
| rule | RA-164.3 P1–P6; RA-165.2 F1/F2; RA-166.6 F6/F7 | A Review scratch-probes every oracle it authorizes and hands CBs exact patches; witness definitions are checked against the producer and consumer invariants. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB47-RP01-ENDPOINT-WITNESSES** (resume) — read [RA-166.4](Architecture_M6_CP3_CB47_REV_Endpoint_Witness_Contract_Rehome_Decision_20261027.md) and [Architecture_M6_CP3_RA166_CB47_Exact_Test_Patch_20261027.patch](Architecture_M6_CP3_RA166_CB47_Exact_Test_Patch_20261027.patch); compile caller as in run `40489392387` (eight targets). No hand edits, runtime, harness, manifest or production changes.

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
