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
| Currency | 2026-10-26, after TB42-REV independently accepted TB42 focused runtime (1/1 PASS), O3 now 3/3 focused candidate; [RA-158](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md) (TB41-REV confirmed; O3 owner assigned; DEFN split). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB41 focused **18/18 PASS**, candidate only: CB42 source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, package `12634151125` (ZIP `d7f7b830…8b87`, **expires 2026-11-02T07:22:41Z**), [run 40296007299](https://github.com/akashskypatel/Directional/actions/runs/40296007299), result `12638251384` (ZIP `1817f829…d854`); [report](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Report_20261026.md), [TB41-REV](Architecture_M6_CP3_TB41_Rehomed_Oracle_Independent_Review_Decision_20261026.md). TB32 481/500 and TB38 490/504 candidate; selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. O3 third locus test (`Phase10Tests:2940`) independently reviewed 1/1 PASS; O3 focused candidate 3/3, not cumulative acceptance. O5: 249 producer-binary tests are in no frozen gate (RA-158 L5). Carried: DIAG-RETAIN, O1, O2, O4, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` — EXACT NEXT

- **Authority:** RA-158.3 step 2, read [TB42-REV](Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Independent_Review_Decision_20261026.md) and [RA-158](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md) before acting.
- **Type / owner:** Definition-only review-and-plan; selector190 and O2 legacy matching paths.
- **Objective:** decide whether the legacy-only test is retired or re-homed as a checked A3 `MissingAdjacency` negative; establish accepted 449-prefix accounting and a separately discriminating consumer/witness or justify unreachability.
- **In scope:** immutable code/fixture inspection and planning decision; scope any future removal of unreachable branches.
- **Out of scope:** product/test/selector/benchmark/build mutations; no compilation or Directional runtime, no O4 or 242 implementation, no CP3 promotion.
- **Success evidence:** exact source-to-consumer path, counterexample/falsifier, reviewed selector-prefix disposition, one bounded CB or next-authorized turn if needed.
- **On success:** `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION-REV` (separate Review); then O4 only after that Review closes.
- **On failure/blocker:** stop within current DEFN and record exact missing authority/decision; do not invent a successor.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION` | 190/O2 Definition only; accepted-prefix accounting; exact falsifiers above. |
| 2 — conditional | `M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION-REV` | Independently review this Definition before any subsequent work. |
| 3 — later, frozen | `M6-CP3-DEFN-RP01-A4-PROVENANCE-GUARD-REACHABILITY` → REV | O4, only after prior Review. |
| 4 — later, frozen | `M6-CP3-DEFN-RP01-SELECTOR242-CROSS-REGION-SEAM-CONSUMER` → REV | Selector242; coordinate DEFN-SEAM-NZ. |
| 5 — subsequent | Code/TB turns assigned by the above Reviews → 405 → 174, 201 → focused30:12 → cp3entry:4 → selector442 → DEFN-T1 → O5 off-selector coverage DEFN → census → RP-01 Review | One owner per turn; no automatic successor jump. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-DEFN-RP01-LEGACY-MATCHING-PATH-DISPOSITION** — Definition-only inspection of 190/O2 legacy matching and checked A3 consumers. Read [RA-158](Architecture_M6_CP3_TB41_REV_Audit_O3_Owner_And_DEFN_Split_Decision_20261026.md), [TB42-REV](Architecture_M6_CP3_TB42_O3_Off_Selector_Locus_Independent_Review_Decision_20261026.md), exact source (`SurfaceCellTracing.cpp` and selector190), accepted prefix authority and relevant LESSONS §§1–3,6. No source changes or Directional runtime in this Definition.

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
