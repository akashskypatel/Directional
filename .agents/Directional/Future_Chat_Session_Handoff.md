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
| Currency | 2026-10-21, CB23 diagnostic-only seam-face site compiled GREEN from `e859175333f`; package `12355892070`, 28/28, eight GMP/GMPXX targets, no runtime. RA-121's A5-ISO owner (B-across vs B-fan) is undecided until a separate TB24 harvest. CB23 independent Review is the exact next turn. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB23 `e859175333f879273a75e3bfc321600e451048aa`; RP-only diagnostic increment over `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`. Refetch live HEAD before mutation. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | CB23 [compile 39623185718](https://github.com/akashskypatel/Directional/actions/runs/39623185718), package `12355892070` (ZIP SHA-256 `5215e5c2…af91f`), 28/28, no runtime; record `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Code_Build_Record_20261021.md`. Latest TB23: 16/16, 6 PASS / 10 RED (RA-121); TB21 census 449/497 (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **A5-ISO**: 10 rows (`focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448`; incl. G4-B002), one site `relation-collinear-seam` / `first-face` (RA-121.3). The unknowns are the selected faces, the corner supports and the span-only direction, which separate B-across from B-fan (RA-121.4). Reverting `8be01326d`'s reject is not admissible. **F**: closed at candidate level. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). Restriction: CB23 was diagnostic-only and is awaiting independent Review; new site fields have not yet been harvested at runtime. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE-REV` — EXACT NEXT

- **Type / owner:** independent Review; authority RA-121.5–121.6 and CB23's completed compile-only record.
- **Objective:** verify the source diff is confined to RP's relation-collinear-seam rejection block, the appended fields match RA-121.5, and the compile package is valid; issue a bounded TB24 plan based on RA-121.6.
- **Read before work:** RA-121 (§3–§6); `Architecture_M6_CP3_CB23_Torus_A5_Seam_Face_Site_Code_Build_Record_20261021.md`; exact diff `c6e90916e` → `e859175333f`; package `12355892070`; applicable review policy and LESSONS §§5, 7.
- **In scope:** independently inspect `;sel=`, `;support=`, `;wedge=`, `;spanOnlyN=` order/meaning and source scope; verify packaged SHA-256, 28/28 manifest, source tar, GMP/GMPXX, eight targets, empty source statuses and `runtimeExecution=false`; record an explicit acceptance/rejection verdict and issue TB24 plan if valid.
- **Out of scope:** no runtime, tests, benchmarks, implementation repairs, selector changes, relaxation of A5 isolation decisions, or acceptance promotion in Review.
- **Success evidence:** formal independent Review decision, durable tracker/handoff updates as needed, explicit TB24 plan using RA-121.6's three A5 rows, one guard and five controls.
- **On success:** TB24 only if this Review explicitly authorizes its canonical ID; otherwise `UNKNOWN` and STOP.
- **On failure/blocker:** STOP; issue bounded corrective authority rather than editing code in the Review.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB23-RP01-TORUS-A5-SEAM-FACE-SITE-REV` | Independent Review of RP-only diff and immutable compile package; issue TB24 plan. |
| later — conditional | TB24 ID `UNKNOWN` pending Review | Planned nine-row seam-face harvest (three A5, guard, five controls); not yet authorized. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — CB23 independent Review: verify RA-121.5 RP-only rejection-site diff and eight-target compile package; issue TB24 plan using RA-121.6; no runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Review_Decision.md` (RA-121), CB23 Code + Build record and the RP-only semantic diff; `LESSONS.md` §§5, 7.
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
