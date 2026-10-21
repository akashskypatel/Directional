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
| Currency | 2026-10-21, after TB22 Review (RA-117). CB21's fixture-selection scope works at runtime (reciprocal 5/5, holonomy 5/5). The five CP2 torus rows split into a fixture atlas defect (`focused30:6`, `selector:447`) and the unowned torus A5 isolation family (`focused30:20/24`, `selector:446`, already seen on `selector:444/448`, `focused30:26/27/28`). Next: CB22 fixes the atlas binding and makes A5 isolation rejections name their site. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB21 `8453e19e6ac7d976a9cac45978ad31104a52f034`; HEAD `src`, `include` and `tests` are identical to it. Last compiled: CB21 package `12318897957` (ZIP `f0ae4338…c606`, 28/28, GMP/GMPXX, `runtimeExecution=false`), expires 2026-10-28T03:54:02Z; accepted statically by RA-116, at runtime for its scope by RA-117.2. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB22: run [39549820087](https://github.com/akashskypatel/Directional/actions/runs/39549820087), result `12323004201` (ZIP `71569a41…8c87`), expires 2026-11-04T05:31:17Z; 11/11 executed, 4 PASS / 7 RED; report `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`, reviewed by RA-117 (`Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`). Census: TB21 result `12317287104`, **449/497**, 0 PASS→RED (RA-115); baseline `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv`. **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. Owned CP2 families: **A5-ISO** (torus A5 `MismatchedIsolationEvidence`, ≥ 8 rows incl. G4-B002 `focused30:28`; branch unknown: RP:4318/4359 side crossing or the post-CP2 RP:5205 reject from `8be01326d`; needs the site, RA-117.3); **F** (torus witness fixture lacks `fieldTransportAtlas`, 2 rows); **M1** (10 rows plus `focused30:12`, `cp3entry:2`, DEFN-M1). CP3-entry: D2 for `cp3entry:1` (DEFN-T1). Restriction: CB22 may not change any A5 decision. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE` — EXACT NEXT

- **Type / owner:** Code + Build; implementation agent. Authority: RA-117.5 (`Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md`).
- **Objective:** correct the torus witness fixture's missing atlas binding, and make every A5 isolation-evidence rejection name its site, without changing any accept/reject decision.
- **Read before work:**
  - RA-117 (§3 and §5);
  - `src/pipeline/RemeshPipeline.cpp` (RP): `transition_between` RP:4136–4165 and its callers RP:4318, 4359, 4470, 4551; `certified_seam_direction` RP:3880–3911; the relation reject RP:5205–5221; the legacy name RP:3231–3260; the mesh failure RP:8955–8970;
  - `LESSONS.md` §5 and §2 **A negative must reach the intended guard on a valid baseline**.
- **In scope:**
  1. **Part A (TQ, one line).** In `make_nonzero_z4_torus_witness_fixture`, after `fixture.network = snapshots.traceNetwork;` (TQ:1672), add `fixture.fieldTransportAtlas = snapshots.fieldTransportAtlas;`, as at TQ:649 and TQ:861.
  2. **Part B (RP and `include/directional/pipeline/RemeshPipeline.h`, rejection path only).**
     - Add `std::string isolationSite` as the last member of `SurfaceOccurrenceComplexError` (header :963–970).
     - Fill it only where `MissingIsolationEvidence` or `MismatchedIsolationEvidence` is returned:
       - `side-step` (RP:4318), `side-collinear` (RP:4359), `wedge-edge` (RP:4470), `wedge-fan` (RP:4551): `;region=<r>;seam=<a>,<b>;from=<row>/<sheet>;to=<row>/<sheet>;cert=<firstRow>/<firstSheet>-><secondRow>/<secondSheet>|none;cell=<id>`;
       - `relation-collinear-seam` (RP:5205–5221): `;region=<r>;seam=<a>,<b>;relation=<first>,<second>;first=<row>/<sheet>;second=<row>/<sheet>;certs=<n>`, plus, for each certificate with that region and seam, its faces/sheets and the first failing `certified_seam_direction` clause (`collinear`, `region`, `first-face`, `second-face`, `same-sheet`, `first-side`, `second-side`, `same-side`), or `ambiguous`.
     - At RP:8963, when `isolationSite` is non-empty, append `;site=<isolationSite>` to the legacy name. Every other failure string is unchanged.
  3. **Compile.** Eight-target GMP/GMPXX compile, `runtimeExecution=false`.
  4. **Record.** `Architecture_M6_CP3_CB22_Torus_A5_Isolation_Site_Code_Build_Record_20261021.md`, at most 30 lines: source SHA, per-file diff stat, compile run, package id, ZIP digest, hash count, expiry, root-manifest and source-archive SHA-256.
- **Out of scope:**
  - any A5 predicate, ordering, error code or return change; `transition_between` and `certified_seam_direction` must decide exactly as before;
  - any other test or helper; `src/geometry` and A4;
  - any repair of A5-ISO; selectors, harnesses, workflows; runtime;
  - DEFN-M1 and DEFN-T1.
- **Success evidence:**
  - the diff touches only the TQ line, the header member and the RP rejection paths and RP:8963;
  - the compile is GREEN;
  - the package is verified: hashes, clean statuses, `runtimeExecution=false`;
  - the record is committed and STATUS is COMPLETE.

  If the compile is still running at your closeout bound, leave STATUS `IN_PROGRESS`; Review harvests.
- **On success:** `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE-REV` (Review, mandatory). It checks the no-decision-change invariant statically and fixes the TB23 rows and predictions (RA-117.5 frame).
- **On failure/blocker:** STOP and return to Review on:
  - a compile failure;
  - any need to change an A5 decision, another test, or A4.

  There is no repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE` | Code + Build per RA-117.5: one-line fixture atlas binding; A5 isolation rejection site diagnostic; no decision change; compile only. |
| 2 — mandatory | `M6-CP3-CB22-RP01-TORUS-A5-ISOLATION-SITE-REV` | Review: static invariant check; fixes TB23 rows and predictions. |
| planned, not authorized | TB23 (torus A5 site harvest: `focused30:6/20/24/25/26/27/28`, `selector:444/446/447/448`, controls) → TB23-REV → DEFN-ISO (A4 seam certificate ↔ A5 binding contract; the `8be01326d` reject) → corrective CB/TB → DEFN-M1 (RA-105.3; also `focused30:12`, `cp3entry:2`) → corrective CB/TB → DEFN-T1 (D2 attainability) → fixture debt → census → RP-01 Review | Only as each Review assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB22: one-line torus fixture atlas binding and the A5 isolation rejection site diagnostic (RA-117.5); compile only, no runtime.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md` (RA-117, the CB22 specification); `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Review_Decision_20261021.md` (RA-116, compile facts); `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Report_20261021.md`; `LESSONS.md` §§2, 5, 7.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md`.

**Review tooling:** `.agents/Directional/tools/` holds read-only `review_check.py`, `selector_probe.py`, and `fixture_probe.py`; history-sensitive review gates require real committed history, not a synthesized snapshot.

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
