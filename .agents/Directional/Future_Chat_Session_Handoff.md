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
| Reviewed findings (RA-81, RA-82) | RA-81: vertex 4 is the **interior vertex of the open rail 1–4–7** (contact {1,7}); no V/I/C branch admits an endpoint there, so the RA-79 contract is **incomplete**. RA-82: the verifier rejects such an endpoint in **two layers** — route level (`SurfaceCellTracing.cpp:8581-8615`, an open-rail front needs a terminal endpoint) and per endpoint (`:8699-8721`) — so the middle front of a longer rail fails whatever per-endpoint branch is added. A reviewer reading that R10A must confirm or falsify. No producer implicated; no remedy approved. |
| Open blockers | `RP-01` open, localized to the consumer endpoint contract plus the verifier's route-level terminal requirement; downstream `RP-02` unentered; Gate C suspended. Sole produced-witness debt: M6 `G4-B002` closed-complex candidate extraction. Stable accounting **66 events / 17 categories / 49 recurrences**, debt **1**; see `Regression_Root_Cause_Tracker.md`. |
| Lifecycle | R10A census completed as source-only factual analysis on exact snapshot `9c4da0f1d0b4205e1fb952df50175575636eed23`. Two-table record `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md` confirms verifier's two-layer R endpoint rejection and identifies un-published named-rail membership; no rule approved. Next independent Review `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV`; history-sensitive gates remain Review-owned (RA-82.3). |

## Mandatory next turn — `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV` — EXACT NEXT

- **Type:** independent Review, authorized by RA-82.5. Audit `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md` against frozen source, RA-81 and RA-82 decisions, R9A/R9B facts, and RA-65.5/RA-68.3/RA-79/RA-81/RA-82.
- **Goal:** falsify or verify every six-shape consumer/verifier outcome, actual fixture versus hypothetical status, independence of each published witness, timing of the junction certificate, and conditional two-hard-edge star-path answer. Record corrections explicitly.
- **Review gates:** run history-dependent `review_check.py` checks (`authority`, `boundary`, `ledgers`) on a real-history checkout and the `document_drift_audit.py --base` check per RA-82.3. R10A ran the no-base audit: `Audit: 0 error(s), 0 warning(s).`
- **Boundary:** no new endpoint rule, source, test, fixture, selector, workflow, compile, runtime, or acceptance change. R10B is only planned until this Review authorizes a concrete successor.

## Turn Sequence

| Step | Canonical turn | Condition |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV` | Independent census review and history-sensitive gates. |
| 2 — conditional | `UNKNOWN` (R10B planned) | Only upon explicit Review authorization, without Code + Build authority. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review**. Use independent Review guidance, not Definition or Code + Build.

Minimum successor context after mandatory durable policies and checklist:

0. `.agents/Directional/ORIENTATION.md` — project authority.
1. `.agents/Directional/ROADMAP.md` — milestone status.
2. This handoff, root `STATUS`, and `TODO.md` — lifecycle.
3. `.agents/Directional/Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md` — source-backed census requiring independent Review.
4. RA-82 (`Architecture_M6_CP3_R10_Prework_Verification_Review_Decision.md`) and RA-81 review decisions, R9A comparison census, R9B equivalence contract.
5. Frozen definitions (RA-65.5/RA-68.3/RA-79/RA-81/RA-82), regression tracker; `SurfaceCellTracing.cpp:64-97,8166-8220,8486-8890,19068-20245`.

**Review tooling:** `.agents/Directional/tools/`: `review_check.py authority|boundary|ledgers`, `document_drift_audit.py --base`; full Git history required. See `tools/README.md`.

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
