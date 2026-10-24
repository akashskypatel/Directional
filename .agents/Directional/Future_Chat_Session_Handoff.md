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
| Currency | 2026-10-24, after the TB33 review (RA-149). TB33 (6/6) is accepted for the synthetic odd-atlas and checked-factory oracles only; this discharges RA-146.3 within that scope. Realigned onto the **19 residual REDs**, largest cluster first: A3 `CycleTransportMismatch` (`selector:189–195`). It is raised at two sites (FTA:2582–2585 per-cycle; FTA:2691–2695 corrected boundary lift) that both drop their locus. CB33 adds a diagnostic-only `site` and cycle locus, after which TB34 measures them. |
| Source and package | Branch `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB32 semantic `30e46b9aabc44925643f46bab20db40962a5e494`; CB32 compile package `12541198172`, immutable ZIP SHA-256 `17a121aac12d288892853a2455d3f72411a5538eeda512a7d2c9c096a7d47651`, GMP/GMPXX, `runtimeExecution=false`. |
| Current runtime candidate | [TB33 run 40051854120](https://github.com/akashskypatel/Directional/actions/runs/40051854120); artifact `12543546779`, ZIP SHA256 `217f6b214707b4165252a23537284f5aa6ebf242e2de1d8b691774d35272c09d`, **15/15 checksums, six/6 PASS, zero RED/invalid/missing/duplicate/skip**, postflight verified. New six-case manifest `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Cases.tsv`. |
| Accepted vs candidate | Accepted CP2 **491/491**. TB32 **481/500 PASS, 19 inherited RED** candidate remains; TB33 synthetic odd source oracle run does not promote periodic/A5/A6 or CP3. Stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached; selector497 frozen. |

## Mandatory next turn — `M6-CP3-CB33-RP01-A3-CYCLE-MISMATCH-LOCUS-DIAGNOSTIC` — EXACT NEXT

- **Type / owner:** Code + Build, compile only, diagnostic only; implementation agent. Authority: RA-149.4 (`Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Review_Decision_20261024.md`).
- **Objective:** make the seven A3 `CycleTransportMismatch` failures say which raise site and which cycle failed, without changing any code path or error code.
- **Read before work:** RA-149 (all); `include/directional/authority/FieldTransportAtlas.h:132–143, 251–264`; `src/authority/FieldTransportAtlas.cpp:2540–2700`; `tests/SurfaceCellsPhase10Tests.cpp:73–90` (formatter) and 4380–4402 (fixture helper); `tests/FieldTransportAtlasTests.cpp:2015–2024, 2437–2480, 2621–2666` (code-only comparisons).
- **In scope:**
  1. **Header:** add `std::string site;` to `FieldAtlasBuildError` (default empty).
  2. **FTA S1 (2582–2585):** `site = "cycle-transport"`; set `cycleOrderingDiagnostics = orderingDiagnostics`; set `sourceVertex` for LocalVertex cycles only if it is known before the return, with no reordering.
  3. **FTA S2 (2691–2695):** `site = "cycle-boundary-corrected-lift"`; `cycleOrderingDiagnostics` with `cycleKind = BoundaryLoop` and `cycleRowIndex` = the canonical boundary index.
  4. **SP10 formatter:** also print `site`, `cycleRowIndex` and `cycleKind` when present.

  Lines at most 100 columns.
- **Out of scope:** any other error path, code value, return or control flow; other files; tests' assertions; selectors, workflows; runtime.
- **Success evidence:**
  - the diff is limited to the four places above;
  - eight targets compile with GMP/GMPXX, `runtimeExecution=false`;
  - record `Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Code_Build_Record_20261024.md` (at most 30 lines) with the hunks, package id and hashes;
  - STATUS COMPLETE.
- **On success:** `M6-CP3-CB33-RP01-A3-CYCLE-MISMATCH-LOCUS-DIAGNOSTIC-REV` (Review, mandatory): static check; issues the TB34 manifest.
- **On failure/blocker:** STOP and return to Review if S1's locus requires reordering, or if any code or return would change.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB33-RP01-A3-CYCLE-MISMATCH-LOCUS-DIAGNOSTIC` | Code + Build, compile only, diagnostic only (RA-149.4). |
| 2 — conditional | `M6-CP3-CB33-RP01-A3-CYCLE-MISMATCH-LOCUS-DIAGNOSTIC-REV` | Review, only after step 1 completes: static check; issues the TB34 manifest. |
| later — UNKNOWN until assigned | TB34 (targeted harness: `selector:189–195` RED with site and cycle locus + 2 A3 cycle guards + 3 TB33 factory controls; manifest at CB33-REV) → TB34-REV (owner from S1 versus S2) → A3-cycle owner turn → per-row pins for `selector:174, 201, 204, 242, 247, 250, 405` → `focused30:12` DEFN → `cp3entry:4` DEFN → `selector:442` → DEFN-T1 (`cp3entry:1/2`) → census → RP-01 Review; carried: RA-146.2, RA-146.4/RA-45.4, G4-B002, `DEFN-SEAM-NZ`, Periodic follow-up | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB33: diagnostic-only A3 cycle-mismatch site and locus (header field, two raise sites, SP10 formatter); compile only.

Minimum context after mandatory policies:
0. ORIENTATION, ROADMAP, this handoff, TODO, TB33 report, exact TB33 manifest, CB32-REV decision/CB32 source oracle tests, original immutable package authority.
1. Immutable [TB33 run 40051854120](https://github.com/akashskypatel/Directional/actions/runs/40051854120), result artifact `12543546779`, ZIP SHA-256 `217f6b214707b4165252a23537284f5aa6ebf242e2de1d8b691774d35272c09d`, ledger and raw logs.
2. RA-148 TB32 reviewed 481/500 candidate and 19 inherited RED; RA-146.2–4, RA-45.4, G4-B002, retained CP2 491/491 and stable 66/17/49 debt1.
3. `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Review_Decision_20261024.md` (RA-149: TB33 accepted, residual-RED order, A3 diagnostic scope); `Architecture_M6_CP3_TB33_Odd_Atlas_Oracle_Verification_Report_20261024.md`; `Architecture_M6_CP3_TB32_Residual_Red_Inventory.tsv`; tracker owners; `LESSONS.md` §2.

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
