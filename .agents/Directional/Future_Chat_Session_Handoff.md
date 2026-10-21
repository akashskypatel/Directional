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
| Currency | 2026-10-21, after TB23 Review (RA-121). One site owns all ten torus A5 rows: an `OrdinaryFront` relation on certified seam 60–61, where occurrence (0,1)'s chart face (`placement.selectedFace`) is not its own seam span's face 120. The A4 certificate agrees with both spans. The F fixture fix is confirmed at runtime (`selector:447` PASS). The owner (A2 corner placement or the A5 face clause) is not yet decidable, so CB23 measures the seam faces before DEFN-ISO. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB22B `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`; HEAD `src`, `include` and `tests` are identical to it. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB23: run [39609365590](https://github.com/akashskypatel/Directional/actions/runs/39609365590), result `12348649684` (ZIP `5ce73745…6d1`), expires 2026-11-04T13:37:29Z; 16/16, 6 PASS / 10 RED; report `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`, reviewed by RA-121 (`Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **A5-ISO**: 10 rows (`focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448`; incl. G4-B002), one site `relation-collinear-seam` / `first-face` (RA-121.3). The unknowns are the selected faces, the corner supports and the span-only direction, which separate B-across from B-fan (RA-121.4). Reverting `8be01326d`'s reject is not admissible. **F**: closed at candidate level. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). Restriction: CB23 is diagnostic-only, in RP's relation-seam block. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE` — EXACT NEXT

- **Type / owner:** CB (Code + Build, compile only); implementation agent. Authority: RA-121.5 (`Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md`).
- **Objective:** extend the `relation-collinear-seam` rejection site with the facts that separate B-across from B-fan, without changing any decision.
- **Read before work:**
  - RA-121 (§3–§6);
  - `src/pipeline/RemeshPipeline.cpp` (RP) at `c6e90916e`: `certified_seam_wedge_side` and `certified_seam_direction` RP:3850–3911; `isolation_binding_label` RP:4168; `selectedFace` RP:4448–4458; the relation site block RP:5262–5344;
  - `SourceTopologyRegions::row_for_topology` and `sheet_for_row`; `authority::support_kind`;
  - `LESSONS.md` §§5, 7.
- **In scope (RP only, inside the relation site block, before `error.isolationSite = std::move(site);`):** append, in this order:
  1. `;sel=<a>,<b>`: each canonical occurrence's `placement.selectedFace` as `<row>/<sheet>`, or `none`;
  2. `;support=<a>,<b>`: `vertex`, `edge` or `face`;
  3. `;wedge=<a>,<b>`: each occurrence's `cornerWedgeBindings` labels joined by `+`;
  4. `;spanOnlyN=<v>` for each matching certificate, in `certN` order: the existing classifier without the two face clauses (`same-sheet`, `first-side`, `second-side`, `same-side`, `forward` or `reverse`).

  Then compile the eight targets with GMP/GMPXX and `runtimeExecution=false`, and write `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Code_Build_Record_20261021.md` (at most 30 lines: source SHA, RP diff stat and ranges, compile run, package id, ZIP SHA-256, hash count, expiry, root-manifest and source-archive SHA-256).
- **Out of scope:**
  - any decision, return or error-code change;
  - any change to existing site text; the new fields are appended only;
  - the header, TQ and every other file (byte-identical to `c6e90916e`);
  - runtime, any repair, DEFN-ISO.
- **Success evidence:**
  - the diff is confined to the block, with no line over 100 columns;
  - the compile is GREEN and the package is verified;
  - the record is committed and STATUS is COMPLETE.

  If the compile is still running at your closeout bound, leave STATUS `IN_PROGRESS`; Review harvests.
- **On success:** `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE-REV` (Review, mandatory). It verifies the diff and package and issues the TB24 plan (RA-121.6 frame).
- **On failure/blocker:** STOP and return to Review on any compile error or any need to edit outside the block. There is no repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE` | CB, per RA-121.5: diagnostic-only seam-face site fields; RP relation block only; compile only. |
| 2 — conditional | `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE-REV` | Review, only after step 1: verifies the diff and package; issues the TB24 plan (RA-121.6). |
| later — UNKNOWN until assigned | TB24 (seam-face harvest: `focused30:20`, `selector:444`, `focused30:28`; guard `selector:447`; five controls) → TB24-REV → DEFN-ISO (B-across or B-fan) → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review | Planned, not authorized; each Review assigns the next edge. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB23: append the seam-face fields to the A5 `relation-collinear-seam` site (RA-121.5); RP only; compile only, no runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md` (RA-121: the site decoded, the two branches, the CB23 specification and the TB24 frame); `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md` (RA-119, site format); `LESSONS.md` §§5, 7.
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
