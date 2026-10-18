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
| Currency | 2026-10-18, after `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` (compile-only) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `70217cc2bf7d257bebd2969e1aa56b5a43326a70` (CB13). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, result `11661044443`, 403/497). |
| Latest candidate or rejected evidence | CB13 compile run `39109464680`, artifact `12130290543`, ZIP SHA-256 `7aea91a1b689f26ae9a4786c48152fe0a3d9c8e17382b6e155db0465e3445fd3`, source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`; eight GMP/GMPXX targets; `runtimeExecution=false`. No CB13 runtime acceptance; TB12 evidence and B3 remain the latest executed semantic observations. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` has three blocker shapes (RA-87.3): B1 I–I anchor → U3 compiled, TB13 not yet executed; B2 R endpoint → U4/U5; B3 inexact I parameter → U6 (DEFN first). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` — EXACT NEXT

- **Type / owner:** Test + Benchmark (artifact only). Execute the six RA-87.5 identities from the immutable CB13 package; no rebuild, relink, source/test/fixture mutation, or harness scope expansion.
- **Exact package:** source `70217cc2bf7d257bebd2969e1aa56b5a43326a70`; compile run `39109464680`, immutable artifact `12130290543`, outer ZIP SHA-256 `7aea91a1b689f26ae9a4786c48152fe0a3d9c8e17382b6e155db0465e3445fd3`. Verify package hashes, GMP runtime, `runtimeExecution=false`, and executable modes without repair before running.
- **Gates:** `SurfaceCellAuthorityContractCutover.OpenRailRouteChainIntervalTruthTable` and `SurfaceCellClosedProductContracts.OpenHardRailChainProvenanceIsSourceValidated` must each PASS.
- **Diagnostics:** execute both P10 midline fixtures; predict that the previous first failure at front 29/147 moves past `open-rail-route-anchor`, possibly to B2. Also run `cp3entry:2/6`; predict the same B3 `first_failure` bytes as TB12. Falsifiers: `open-rail-chain-interval` anywhere or P10 first failure still at front 29/147.
- **Boundaries:** TB harness may use only the frozen package and should follow TB12's six identities with changes only to source/artifact/digest and identities. No general 497 census in this TB13 turn. Maintain independent evidence: predictions are not outcomes.
- **Conditional next:** `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` after TB13; any required independent gate/Review decision takes precedence as specified by turn cadence. Never promote a candidate runtime gate absent Review.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — completed | `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` | U3 compiled; no runtime executed. |
| 2 — next | `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` | After CB13 is packaged. Six identities (RA-87.5): two gates; the P10 midline tests predicted to move past front 29/147 to B2; `cp3entry:2/6` byte-identical to TB12. |
| 3 — conditional | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` | Same CB13 package; the unchanged 497 harness; the first failure of every RED classified as B1/B2/B3/other; identities that passed at R3 and are now RED listed. No interpretation. |
| 4 — conditional | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV` | Review of TB13 and TB13C. It orders U4/U5/U6 and issues the DEFN for U6 (the exact I-endpoint parameter). |

Orchestration failures follow rule 5. Anything beyond step 4 is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — artifact-only six-identity TB13 harness; do not compile or modify source.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md` (RA-87.5 TB13 six-identity plan), `Architecture_M6_CP3_CB13_R10_Open_Rail_Chain_Interval_Route_Code_Build_Record_20261018.md` (CB13 package), `Architecture_M6_CP3_TB12_Open_Rail_Chain_Provenance_Harvest_Report_20261018.md` (B3 baseline), `Architecture_M6_Frozen_Definitions.md`, `GMP_COMPILE_POLICY.md`.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats. History gates (`authority|boundary|ledgers`, drift `--base`) are Review gates (RA-82.3); implementation turns run `document_drift_audit.py --root .` only.

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
