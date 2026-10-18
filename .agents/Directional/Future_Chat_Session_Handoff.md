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
| Currency | 2026-10-17, after `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV` (RA-84) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Source unchanged since `d938ecb57`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. |
| Latest candidate or rejected evidence | TB10 44/44 RED (run `38941839640`, result `12062873272`, source `d938ecb57`): 21 one-hot vertex records, carrier membership 21/21, contact membership 0/21. Diagnostic only, **not promoted**. R3 **403/497** rejected. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01`: no endpoint branch admits an interior vertex of an open rail. The R10B rule is accepted with amendments (`Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md`, RA-84) and split into U1–U4 (RA-84.5). Only U1 is authorized. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR` — EXACT NEXT

- **Type / owner:** `CB` (compile only); unit U1 of RA-84.5.
- **Objective:** one pure open-rail route-anchor helper that both checkers call, so the consumer refuses, before its push, every open-rail route that `SurfacePhaseFrontProduct::make` refuses. No `Produced` result changes.
- **Read before work:** RA-84 record; R10B rule §3; `SurfaceCellTracing.cpp:8576-8615`, `:20225-20253`; `tests/SurfaceCellsPhase10Tests.cpp:7145-7190`.
- **In scope:**
  1. Move the open-rail branch at `:8576-8615` into one pure `surface_cell_tracing_detail` helper, with the same clauses (none added or dropped), and call it from the factory.
  2. Call the same helper in the consumer immediately before `:20243`. On failure, call `invalid_route(TerminalCarrier, -1, -1, "open-rail-route-anchor")`. Closed rails are unchanged.
  3. Tests below, then compile and package.
- **Out of scope:** R admission, open-chain plumbing (U2–U4), any other clause in `:8616-8890` or `:19265-19544`, I/C branches, tolerance, selector/harness/workflow/benchmark, running tests.
- **Success evidence:**
  - Helper truth table with hand-written expectations: T–T opposite admits, either order; T–T same terminal rejects; T–T whose carriers do not touch rejects; T–I with T at either end admits; non-contact T rejects; T not on its carrier rejects; I–I rejects.
  - Factory test: the produced T–I candidate with `endpoints[0].terminalVertex` cleared is refused (`InvalidSourceAuthority`).
  - The `:7145-7190` control is unmodified and the fixture stays `Produced`.
  - A consumer I–I test, or the record "consumer I–I: helper-covered, not end-to-end observed".
  - Compile package ID and source SHA, with `runtimeExecution=false`.
- **On success:** `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR`.
- **On failure/blocker:** `UNKNOWN — STOP`; orchestration failures follow `Turn_Cadence.md` rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB11-R10-OPEN-RAIL-ROUTE-ANCHOR` | Implementation; U1 only, compile only. |
| 2 — conditional | `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR` | Only after CB11 is packaged and its diff reviewed. It runs CB11's tests and the controls on the immutable package. A red result goes to Review. |

U2–U4 (`CB12`–`CB14`, each followed by its TB) are frozen in RA-84.5. Each needs a green, reviewed predecessor TB; anything beyond is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — use the turn-based-coding-agent Code + Build guidance; no runtime execution.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md` (RA-84), `Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md` §3, `Architecture_M6_Frozen_Definitions.md` RA-83/RA-84, `GMP_COMPILE_POLICY.md`.
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
