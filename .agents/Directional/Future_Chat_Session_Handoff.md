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
| Latest candidate | TB10 `M6-CP3-TB10-R9-CARRIER-ENDPOINT-SUBCONDITION-HARVEST`: **44/44 RED**, zero missing, 48 diagnostic records; **accepted as diagnostic evidence by RA-81** (`Architecture_M6_CP3_R9_Carrier_Endpoint_Subcondition_Review_Decision.md`). **Non-stable; no promotion, selector497 execution, or new gate credit.** |
| Exact evidence | Source `d938ecb57e1040c2a73d5d25c4a613414556cb18`; compiled artifact `12062565622`; run `38941839640`; result `12062873272`; ZIP SHA-256 `4db22a924f31a7bc6fdf1575a66849a2f660a760003e03e26e7f9277ac200513`. See `Architecture_M6_CP3_TB10_Carrier_Endpoint_Subcondition_Harvest_Report_20261016.md`. |
| Reviewed finding (RA-81) | Carrier canonical-edge membership **21/21**, published terminal-contact membership **0/21**. Vertex 4 is the **interior vertex of the open rail 1–4–7** (contact {1,7}); no RA-79 V/I/C branch admits an endpoint there, so that contract is **incomplete**. No producer implicated; no remedy approved. |
| Open blockers | `RP-01` open, localized to the consumer endpoint contract; downstream `RP-02` unentered; Gate C suspended. Sole produced-witness debt: M6 `G4-B002` closed-complex candidate extraction. Stable accounting **66 events / 17 categories / 49 recurrences**, debt **1**; see `Regression_Root_Cause_Tracker.md`. |
| Lifecycle | Root `STATUS`: `M6-CP3-R9-CARRIER-ENDPOINT-SUBCONDITION-REV` COMPLETE, successor `M6-CP3-DEFN-R10-RAIL-INTERIOR-VERTEX-ENDPOINT-SPEC`. `review_check.py`'s high-water/append-only checks on the handoff, ORIENTATION and tracker fail by construction since the authorized rewrite (RA-81.2); all other checks must pass. |

## Mandatory next turn — `M6-CP3-DEFN-R10-RAIL-INTERIOR-VERTEX-ENDPOINT-SPEC` — EXACT NEXT

- **Type / owner:** `DEFN`; authorized by RA-81 (`Architecture_M6_CP3_R9_Carrier_Endpoint_Subcondition_Review_Decision.md`).
- **Objective:** specify the missing endpoint case — a front-edge endpoint at an **interior vertex of an open rail** — or establish that it must be rejected, against **both** active checkers.
- **Read before work:** RA-81 decision; `Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md` (the V/I/C contract being extended); `Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_20261016.md` (both checkers' comparison sites); `Architecture_M6_Frozen_Definitions.md` RA-65.5, RA-68.3, RA-78.4, RA-79, RA-81.
- **In scope:** static source reading; one specification document; durable-document updates in place.
- **Out of scope:** any source, test, fixture, selector, harness, workflow or benchmark change; compile or runtime; any epsilon or tolerance; weakening `unique_terminal_star_path` or accepting `Missing`/`Ambiguous`; a producer-authored vertex-star certificate (gate C stays suspended); relaxing branch I's exact rational equality.
- **Success evidence:** (1) cite where each checker (`SurfaceCellTracing.cpp:19265-19495`, `:8621-8736`) currently rejects an interior-rail-vertex endpoint; (2) list every witness the new case needs with its existing publisher, or state it is absent (RA-65.5) — address the junction certificate ordered after admission (RA-68.3); (3) state the rule against both checkers and exhibit at least one endpoint it still rejects; (4) classify as repair or relocation.
- **On success:** `M6-CP3-DEFN-R10-RAIL-INTERIOR-VERTEX-ENDPOINT-SPEC-REV`.
- **On failure/blocker:** `UNKNOWN — STOP`; record what is missing. A partial result with its boundary stated is acceptable.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-R10-RAIL-INTERIOR-VERTEX-ENDPOINT-SPEC` | Documents only, per the mandatory next turn above. |
| 2 — conditional | `M6-CP3-DEFN-R10-RAIL-INTERIOR-VERTEX-ENDPOINT-SPEC-REV` | Only after step 1 delivers; no CB/TB before that Review authorizes one. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **plan**. Use turn-based-coding-agent **Definition/plan** guidance, **not** its Code + Build instructions.

Minimum successor context **after** mandatory durable policies/start checklist:

0. `.agents/Directional/ORIENTATION.md` — read first for project/fixtures.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. This handoff, repository-root `STATUS`, and `TODO.md` — live authority/lifecycle.
3. `.agents/Directional/Architecture_M6_CP3_R9_Carrier_Endpoint_Subcondition_Review_Decision.md` — RA-81, the authorizing review.
4. `.agents/Directional/Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md` and `Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_20261016.md` — the contract being extended and both checkers' comparison sites.
5. `.agents/Directional/Architecture_M6_Frozen_Definitions.md` (RA-65.5, RA-68.3, RA-78.4, RA-79, RA-81) and `Regression_Root_Cause_Tracker.md` — constraints and the open fault.

**Review tooling:** `.agents/Directional/tools/`: `review_check.py authority <sha>`, `review_check.py boundary`, `selector_probe.py` (selector hashes/identities), `fixture_probe.py` (topology/vertex fans). See `tools/README.md`.

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
