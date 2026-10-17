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

## Current immutable authority — 2026-10-17

| Topic | Status / owner |
|---|---|
| Branch | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8). Refetch HEAD on resume; a handoff edit is **not semantic evidence**. |
| Milestones | M0–M5 CLOSED. M6 CP1 and CP2 CLOSED; **M6 CP3 OPEN**. M7/M8 planned; see `ROADMAP.md`. |
| Last accepted runtime | **M6 CP2 491/491 PASS**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`; see `M6_CP2_Closure_Record.md`. |
| CP3 entry | Frozen gate **497** identities (30 + 12 + 449 + 6). R3 **403 PASS / 94 RED**, independently rejected. No CP3 gate is accepted. |
| Latest candidate | TB10 `M6-CP3-TB10-R9-CARRIER-ENDPOINT-SUBCONDITION-HARVEST`: **44/44 RED**, zero missing, 48 diagnostic records; accepted as diagnostic evidence by RA-81. **Non-stable; no promotion, selector497 execution, or new gate credit.** |
| Exact evidence | Source `d938ecb57e1040c2a73d5d25c4a613414556cb18` (unchanged at HEAD in `src`/`include`/`tests`); compiled artifact `12062565622`; run `38941839640`; result `12062873272`; ZIP SHA-256 `4db22a924f31a7bc6fdf1575a66849a2f660a760003e03e26e7f9277ac200513`. See `Architecture_M6_CP3_TB10_Carrier_Endpoint_Subcondition_Harvest_Report_20261016.md`. |
| Reviewed findings (RA-81–RA-83) | An endpoint at an **interior vertex of an open rail** (fixture rail 1–4–7, vertex 4) is admitted by no branch. The verifier rejects it per endpoint (`SurfaceCellTracing.cpp:8699-8721`) **and** at route level (`:8597-8614`: an open-rail front needs a published terminal end), and seeds star incidence only for published terminals (`:8495-8519`). The consumer has no route-level requirement, so it can certify an I–I front that publication then rejects (RA-83.2). The ordered open-rail chain already reaches the consumer (`SurfaceCellTracingOptions::authoritativeRails`, unused there) but not the verifier, whose input projection keeps only an open rail's two ends (`RemeshPipeline.cpp:9756-9765`; RA-83.3). Facts: `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md`; review: `Architecture_M6_CP3_R10A_Witness_Census_Review_Decision.md`. No remedy approved. |
| Open blockers | `RP-01` open, owned by the endpoint contract (per endpoint and route level); downstream `RP-02` unentered; Gate C suspended. Sole produced-witness debt: M6 `G4-B002` closed-complex candidate extraction. Stable accounting **66 events / 17 categories / 49 recurrences**, debt **1**; see `Regression_Root_Cause_Tracker.md`. |
| Lifecycle | Root `STATUS`: `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV` COMPLETE, successor `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE`. History-dependent gates are Review gates (RA-82.3): implementation turns run `document_drift_audit.py --root .` only. |

## Mandatory next turn — `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE` — EXACT NEXT

- **Type / owner:** `DEFN`, documents only; authorized by RA-83 (`Architecture_M6_CP3_R10A_Witness_Census_Review_Decision.md`).
- **Objective:** state **one** admission rule for a front endpoint at an interior vertex of an open rail (R) that both checkers apply identically, at both verifier layers — or establish that R must be rejected and say what then produces a rail's middle fronts.
- **Read before work:** RA-83 decision; the R10A census; `Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md` (contract being extended); `Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_20261016.md`; Frozen RA-65.5, RA-68.3, RA-72.5, RA-78.4, RA-79, RA-83.
- **Deliverable:** one document, `Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md`:
  1. **Witness source.** Which independent witness proves "R is an interior vertex of rail X, between rail edges e1 and e2". Compare (a) data already at both checkers (two hard spokes at R, the carrier) — say what it cannot prove — with (b) the ordered open-rail chain, which the consumer already holds (`SurfaceCellTracingOptions::authoritativeRails`, `SurfaceCellTracing.cpp:19059`) and the verifier lacks; say how it would reach `SurfacePhaseFrontProduct::make` (`:12858-12869`) — through `hard_rail_source_provenance_from_rails` (`RemeshPipeline.cpp:9756-9765`, as closed rails already are at `:9741-9754`) or otherwise. Choose one; classify it as repair or relocation (RA-72.5) and against the RA-78.4 / gate C boundary.
  2. **Per-endpoint rule** for both checkers (consumer `SurfaceCellTracing.cpp:19397-19425`; verifier `:8699-8721`), as a conjunction; each clause cites an R10A table-2 row or a `file:line`. Say how the verifier's star incidence (`:8495-8519`) covers R vertices.
  3. **Route-level rule:** what replaces or extends the verifier's "at least one published terminal" (`:8597-8614`) for fronts with no terminal end, and how the I–I disagreement (RA-83.2) closes. Both checkers admit or both reject.
  4. **Outcome matrix:** T–T, T–I, I–I, T–R, I–R, R–R × consumer/verifier after the rule, with no row where they differ. T–T and T–I unchanged. At least one R endpoint the rule still rejects, with the clause that rejects it.
  5. **Code sites and test obligations:** list each code site the rule touches (`file:line`) grouped into independently testable units, and for each unit the positive and tamper cases with expected outcomes. Existing tests that must keep their outcome include `SurfaceCellsPhase10Tests.cpp:7145-7187`. Names and expectations only; no code.
- **In scope:** static source reading; the one rule document; in-place updates to this handoff, `TODO.md` and the tracker; one short root `CHANGELOG.md` entry.
- **Out of scope:** any source, test, fixture, selector, harness, workflow, tool or benchmark change; compile or runtime; any epsilon or tolerance; weakening `unique_terminal_star_path` or accepting `Missing`/`Ambiguous`; a witness authored by the A4 producer (RA-65.5) or a producer-authored vertex-star certificate (gate C suspended); relaxing branch I's exact equality; changing T–T or T–I outcomes.
- **Gates (RA-82.3):** run `document_drift_audit.py --root .` and paste its last line; report `review_check.py` and the `--base` audit as *deferred to Review*.
- **Success evidence:** items 1–5 present; every rule clause cites a witness; the matrix has no consumer/verifier disagreement.
- **On success:** `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV`.
- **On failure/blocker:** `UNKNOWN — STOP`; record the boundary reached. A rule for the per-endpoint layer alone is **not** a partial success unless it states why the route layer cannot yet be decided.

## Turn Sequence

| Step | Canonical turn | Condition |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE` | Documents only: one rule for both checkers and both verifier layers, outcome matrix, code sites and test obligations. No code. |
| 2 — conditional | `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV` | Only after step 1 delivers. That Review splits any authorized code into narrow Code + Build units, one per code-site group. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **plan**. Use turn-based-coding-agent **Definition/plan** guidance, **not** its Code + Build instructions.

Minimum successor context **after** mandatory durable policies/start checklist:

0. `.agents/Directional/ORIENTATION.md` — read first for project/fixtures.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. This handoff, repository-root `STATUS`, and `TODO.md` — live authority/lifecycle.
3. `.agents/Directional/Architecture_M6_CP3_R10A_Witness_Census_Review_Decision.md` (RA-83, the authorizing review) and `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md` (the accepted facts).
4. `.agents/Directional/Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md` and `Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_20261016.md` — the contract being extended and both checkers' comparison sites.
5. `.agents/Directional/Architecture_M6_Frozen_Definitions.md` (RA-65.5, RA-68.3, RA-72.5, RA-78.4, RA-79, RA-83) and `Regression_Root_Cause_Tracker.md`; source `SurfaceCellTracing.cpp:8495-8890,19397-20245`, `RemeshPipeline.cpp:9404-9428,9732-9767`.

**Review tooling:** `.agents/Directional/tools/`: `review_check.py authority|boundary|ledgers` and `document_drift_audit.py --base` need full Git history and run at Review only (RA-82.3); implementation turns run `document_drift_audit.py --root .`. `selector_probe.py` and `fixture_probe.py` for selectors and fixture topology. See `tools/README.md`.

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
