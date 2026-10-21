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
| Currency | 2026-10-21, after TB24 Review (RA-123). TB24 held P1/P2: both occurrences of the failing seam relation are the same vertex-61 node and carry one per-node representative face `121/0`; it lies inside occurrence (0,1)'s wedge but outside (1,0)'s (`97/2`, other sheet). The site is neither B-across nor B-fan; the owner is the A2 per-node corner representative (RA-72.4 class). Relaxing the A5 face clauses is inadmissible (A6 relies on them). DEFN-ISO is split: census (A), then contract (B). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB23 `e859175333f879273a75e3bfc321600e451048aa`; HEAD `src`, `include` and `tests` are identical to it. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB24: run [39641426480](https://github.com/akashskypatel/Directional/actions/runs/39641426480), result `12364838156` (ZIP `dcf42df9…220d3`), expires 2026-10-28T17:12:14Z; 9/9, 3 A5 RED / 6 PASS; report `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Report_20261021.md`, reviewed by RA-123 (`Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`). CB23 package `12355892070` (RA-122). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **A5-ISO**: 10 rows (`focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448`; incl. G4-B002), one site; owner the A2 per-node representative (RA-123.3–123.6). Unestablished premises: one representative per occurrence serves every consumer; lattice re-expression at another face is exact and A6's stripped-turn check is meaningful. No clause relaxation, no minimum-face rule, no new producer certificate. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). Restriction: DEFN-ISO-A is documents-only. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS` — EXACT NEXT

- **Type / owner:** DEFN (documents-only census); implementation agent. Authority: RA-123.7 (`Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`).
- **Objective:** enumerate every enforcer of the occurrence representative and settle the frame premises, so DEFN-ISO-B can write a contract without guessing.
- **Read before work:**
  - RA-123 (all), RA-72.4–72.6 (`Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Spec_Review_Decision.md`), RA-78.10, RA-79.4;
  - `src/pipeline/RemeshPipeline.cpp` (RP): RP:3855–3911, RP:4448–4458, RP:4669–4684, RP:5051–5052, RP:5832–5877;
  - `src/geometry/SurfaceCellTracing.cpp` (SCT): SCT:13404–13422, SCT:13191, SCT:13579, SCT:18037, SCT:18434;
  - `LESSONS.md` §§3, 5.
- **In scope:** write `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md` (at most 80 lines), each answer line-anchored at HEAD with the search commands printed verbatim:
  1. **Enforcers:** every read of `placement.selectedFace`, `placement.lattice` (`branchRotation`, `sourceChart`), `cornerWedgeBindings` and the endpoint face gauges in `src/`, each with the frame it assumes (face, sheet or region).
  2. **Frame semantics:** which writer fills `sourceFaceBranchRotations` on the torus path; whether the corner `branchRotation` equals the gauge at the node face by construction; what A6's stripped turn computes for same-sheet occurrences and for occurrences on the two certified sides; whether TB24's relation could satisfy `seam.forward()` with (1,0)'s representative at `97/2`.
  3. **Sufficiency:** per consumer kind (seam and non-seam `OrdinaryFront`, hard-rail endpoint, periodic), the face the representative must equal; whether one wedge face serves them all or the gauge must be per (occurrence, side).
  4. **Node face rule:** what put vertex 61's node on row 121, against RA-72.6's minimum-row prediction of 97.
  5. **Reach:** which A5-ISO rows share this relation shape, and which controls read a field that a representative change would touch.
- **Out of scope:**
  - any `src`/`include`/`tests`/selector/workflow change, compile or runtime;
  - any contract, rule or repair, including a clause relaxation, a minimum-face rule (RA-79.4) or a new producer certificate (RA-78.4).
- **Success evidence:** the record is committed with all five answers anchored or explicitly marked undecidable, and STATUS is COMPLETE.
- **On success:** `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS-REV` (Review, mandatory). It adjudicates the census and issues DEFN-ISO-B (the contract) or a compile-only probe.
- **On failure/blocker:** if a question cannot be answered statically, STOP: record what is known, name the compile-only, rejection-only probe that would answer it, and return to Review. Do not guess.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS` | DEFN, per RA-123.7: documents-only census of representative enforcers and frame premises. |
| 2 — conditional | `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS-REV` | Review, only after step 1: adjudicates the census; issues DEFN-ISO-B or a compile-only probe. |
| later — UNKNOWN until assigned | DEFN-ISO-B (contract: per-occurrence representative, lattice re-expression, non-weakening, falsifiers) → DEFN-ISO-B-REV → corrective CB → CB-REV → TB → TB-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review | Planned, not authorized; each Review assigns the next edge. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **plan** — DEFN-ISO-A: documents-only census of the occurrence-representative enforcers and frame premises (RA-123.7); no code, compile or runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md` (RA-123: decoded site, B-node owner, why relaxation is inadmissible, census questions); `Architecture_M6_CP3_R7_Corner_Face_Selection_Repair_Spec_Review_Decision.md` (RA-72.4–72.6); TB24 report; `LESSONS.md` §§3, 5.
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
