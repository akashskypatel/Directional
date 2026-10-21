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
| Currency | 2026-10-21, after the DEFN-ISO-A census Review (RA-124). Static proof: an OrdinaryFront relation's two occurrences are one shared producer node with one `selectedFace`, so the A5 certified-seam face clauses can never hold (every certified collinear-seam OrdinaryFront is rejected), and A6's gauge-stripped turn is identity by construction in the uniform and curved producers (annulus never writes `branchRotation`). The frozen D3 seam rule (RA-30a.3) is satisfiable only for an identity turn. RA-123's DEFN-ISO-B (per-occurrence representative) is withdrawn as relocation. CB24 measures the gauge jump against the certificate turn before DEFN-SEAM. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB23 `e859175333f879273a75e3bfc321600e451048aa`; HEAD `src`, `include` and `tests` are identical to it. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB24: run [39641426480](https://github.com/akashskypatel/Directional/actions/runs/39641426480), result `12364838156` (ZIP `dcf42df9…220d3`), expires 2026-10-28T17:12:14Z; 9/9, 3 A5 RED / 6 PASS (RA-123). Static census `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md`, reviewed by RA-124 (`Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md`). CB23 package `12355892070` (RA-122). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **Seam contract (RA-124.3):** the A5 face clauses (RP:3891–3892) and frozen D3 (RA-30a.3, A6 RP:5832–5877) cannot pass on shared-node producer data. **A5-ISO**: 10 rows (`focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448`; incl. G4-B002) are instances. `cp3entry:3/5` (the D3 positive witnesses, filed as adjacent-sheet fixture debt) are contested; TB25 decides. Open runtime fact: does the published gauge jump at seam 60–61 equal the certificate turn? No clause relaxation, no per-occurrence representative change, no D3 amendment before TB25-REV. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE` — EXACT NEXT

- **Type / owner:** CB (Code + Build, compile only); implementation agent. Authority: RA-124.5 (`Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md`).
- **Objective:** add the frame values that decide the seam contract (gauges, branches, certificate turns) to the existing A5 seam rejection site, and route the D3 witness helper's A5 rejection through the existing site formatter. No decision changes.
- **Read before work:**
  - RA-124 (all), RA-123.3, RA-30a.3 (`Architecture_M6_Frozen_Definitions.md`, "D3 seam branch certification");
  - `src/pipeline/RemeshPipeline.cpp` (RP): RP:3855–3911, RP:4669–4684 (`endpoint_face_gauge`), the site block RP:5262–5412;
  - `tests/SurfaceCellTransitionQuotientTests.cpp` (TQ): TQ:960–972 (`a5_rejection_message`), TQ:2725–2800 (`m6cp3_produced_seam_fixture`);
  - `LESSONS.md` §§5, 7.
- **In scope:**
  1. RP, inside the relation-collinear-seam block, after the `spanOnlyN` loop and before `error.isolationSite = std::move(site);`, append in this order:
     - `;branch=<a>,<b>`: each canonical occurrence's `placement.lattice.branchRotation`;
     - `;gaugeSel=<a>,<b>`: `phaseFront.sourceFaceBranchRotations()[row(selectedFace)]`, or `none`;
     - `;gaugeSpan=<a>,<b>`: the same at each canonical span's `interiorBinding.face`, or `none`;
     - `;turnN=<f>,<r>`: for each matching certificate in `certN` order, `forward().value()`,`reverse().value()`.
  2. TQ:2756–2762, the A5 branch of `m6cp3_produced_seam_fixture`: record `a5_rejection_message(a5Construction)` instead of `"A5:" + error name`.
  3. Compile the eight targets with GMP/GMPXX and `runtimeExecution=false`. Write `Architecture_M6_CP3_CB24_Seam_Frame_Values_Site_Code_Build_Record_20261021.md` (at most 30 lines: source SHA, diff stat and ranges per file, compile run, package id, ZIP SHA-256, hash count, expiry, root-manifest and source-archive SHA-256).
- **Out of scope:**
  - any decision, return, error-code or assertion change; existing site text is appended to only;
  - the header and every other file (byte-identical to HEAD);
  - runtime, repair, clause relaxation, representative change, a D3 amendment.
- **Success evidence:** the diff is confined to the two hunks with no line over 100 columns; the compile is GREEN and the package verified; the record is committed and STATUS is COMPLETE. If the compile is still running at your closeout bound, leave STATUS `IN_PROGRESS`; Review harvests.
- **On success:** `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE-REV` (Review, mandatory). It verifies the diff and package and freezes the TB25 plan (RA-124.6).
- **On failure/blocker:** STOP and return to Review on any compile error or any need to edit outside the two hunks. There is no repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE` | CB, per RA-124.5: diagnostic-only frame values on the A5 seam site (RP) and the helper's A5 message (TQ); compile only. |
| 2 — conditional | `M6-CP3-CB24-RP01-SEAM-FRAME-VALUES-SITE-REV` | Review, only after step 1: verifies the diff and package; freezes the TB25 plan (RA-124.6). |
| later — UNKNOWN until assigned | TB25 (11 rows: three A5 rows, `cp3entry:3/5`, guard 447, five controls) → TB25-REV → DEFN-SEAM (seam contract for the shared-node model, per TB25 routing) → DEFN-SEAM-REV → corrective CB → CB-REV → TB → TB-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review | Planned, not authorized; each Review assigns the next edge. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB24: append the frame values (branch, gauges, certificate turns) to the A5 relation-collinear-seam site and route the D3 witness helper's A5 rejection through `a5_rejection_message` (RA-124.5); compile only, no runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md` (RA-124: P1–P3 static proof, realignment, CB24 specification, TB25 frame); RA-123 (`Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`); RA-30a.3 in `Architecture_M6_Frozen_Definitions.md`; `LESSONS.md` §§5, 7.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats.

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
