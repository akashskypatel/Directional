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
| Lifecycle | Root `STATUS`: `M6-CP3-R10-PREWORK-VERIFICATION-REV` COMPLETE, successor `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS`. The R10 turn blocked only because its snapshot has no `.git`; RA-82 verified its pre-work on a full clone (`Architecture_M6_CP3_R10_Prework_Verification_Review_Decision.md`) and replaced R10 with R10A/R10B. **History-dependent gates are Review gates (RA-82.3).** |

## Mandatory next turn — `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS` — EXACT NEXT

- **Type / owner:** `DEFN`, documents only, **facts only**; authorized by RA-82 (`Architecture_M6_CP3_R10_Prework_Verification_Review_Decision.md`).
- **Objective:** establish from source text how both checkers treat a front endpoint at an **interior vertex of an open rail**, and which independently published witnesses exist for it. **No rule and no recommendation** — that is R10B.
- **Read before work:** RA-82 decision (its RA-82.4 is a reviewer reading to confirm or falsify, not a given); RA-81 decision; `Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_20261016.md`; `Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md`; Frozen RA-65.5, RA-68.3, RA-79, RA-81, RA-82.
- **Deliverable:** one document, `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md`, with two tables and one answer.
  1. **Rejection trace.** Endpoint kinds: **T** published rail terminal, **R** interior vertex of an open rail, **I** strict interior point of a carrier edge. For front shapes T–R, R–R, I–R, plus controls T–T, T–I, I–I: the outcome in the consumer (`SurfaceCellTracing.cpp:19265-19495`) and in the verifier (`:8528-8870`) — first rejecting line with reason or error code, or "admits". Mark which shapes the frozen fixtures produce (cite the fixture line) and which are hypothetical.
  2. **Witness inventory.** For each fact an R endpoint needs — the front's rail; the vertex is on that rail; it is not a terminal; the two rail edges at it; the certificate's carrier edge is one of them; exact one-hot attachment of both trace points; one unique non-hard star path per side; orientation; the adjacent front's endpoint at the same vertex and the junction certificate built after admission (RA-68.3) — give the publisher (type and header line, producing function and line) and whether it is independent of the certificate being checked, or write **absent** (RA-65.5). Say which checks of the verifier's junction certificate (`:8775-8870`) would carry over.
  3. **Star-path answer.** Does `unique_terminal_star_path` (`:8166-8220`) return `Unique` per side at a vertex where two hard rail edges meet, or does it assume one hard edge? Answer with line references.
- **In scope:** static source reading; the census document; in-place updates to this handoff, `TODO.md` and the tracker; one short root `CHANGELOG.md` entry.
- **Out of scope:** stating or recommending a rule; any source, test, fixture, selector, harness, workflow, tool or benchmark change; compile or runtime; any epsilon or tolerance; a producer-authored vertex-star certificate (gate C stays suspended).
- **Gates (RA-82.3):** run `document_drift_audit.py --root .` without `--base` and paste its last line. Report `review_check.py` and the `--base` audit as *deferred to Review*; do not stop because `.git` is missing.
- **Success evidence:** every table cell has a `file:line` or **absent**; each RA-82.4 claim is marked confirmed or falsified with a line reference.
- **On success:** `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV`.
- **On failure/blocker:** `UNKNOWN — STOP`; record what could not be established. A partial census with its boundary stated is acceptable.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS` | Documents only, facts only: rejection trace and witness inventory. No rule. |
| 2 — conditional | `M6-CP3-DEFN-R10A-RAIL-INTERIOR-VERTEX-WITNESS-CENSUS-REV` | Only after step 1 delivers. Frozen plan after it (RA-82.5, not yet authorized): R10B rule → its Review → code only if that Review authorizes it. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **plan**. Use turn-based-coding-agent **Definition/plan** guidance, **not** its Code + Build instructions.

Minimum successor context **after** mandatory durable policies/start checklist:

0. `.agents/Directional/ORIENTATION.md` — read first for project/fixtures.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. This handoff, repository-root `STATUS`, and `TODO.md` — live authority/lifecycle.
3. `.agents/Directional/Architecture_M6_CP3_R10_Prework_Verification_Review_Decision.md` — RA-82, the authorizing review; then the RA-81 decision it builds on.
4. `.agents/Directional/Architecture_M6_CP3_R9A_Endpoint_Face_Comparison_Census_20261016.md` and `Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md` — both checkers' comparison sites and the contract being extended.
5. `.agents/Directional/Architecture_M6_Frozen_Definitions.md` (RA-65.5, RA-68.3, RA-79, RA-81, RA-82) and `Regression_Root_Cause_Tracker.md` — constraints and the open fault.

**Review tooling:** `.agents/Directional/tools/`: `review_check.py authority <sha>`, `review_check.py boundary`, `review_check.py ledgers --base 8b7299b43` (these need full Git history: Review only, RA-82.3), `selector_probe.py` (selector hashes/identities), `fixture_probe.py` (topology/vertex fans). See `tools/README.md`.

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
