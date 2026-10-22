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
| Currency | 2026-10-22, after the TB25 Review (RA-126). On every measured seam the certified turn is identity (F = 0, gauge jump d = 0; curved torus and uniform D3 grid). Frozen D3 is therefore satisfiable there, and the only blocker is the A5 face clauses on shared-node relations. `cp3entry:3/5` join A5-ISO (12 rows). DEFN-SEAM is authorized, narrowed to A5 shared-node side authority; nonzero-turn seams are deferred. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). All other RP-01 sources remain byte-identical to `dae267a82`, and Linux CI build behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB25 [run 39682528031](https://github.com/akashskypatel/Directional/actions/runs/39682528031), result `12384333036` (ZIP `f10ef778…cbc`), expires 2026-10-28T21:56:02Z; 11/11, 6 PASS / 5 RED; reviewed by RA-126 (`Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`). CB24 package `12378590512` (RA-125). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **A5-ISO (12 rows):** `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448` (incl. G4-B002); `cp3entry:3, 5`. One mechanism: the A5 certified-seam face clauses (RP:3891–3892) on shared-node relations, with identity turn. Fix scope (RA-126.4): shared-node side authority in `certified_seam_direction` only; A6/D3 unchanged; nonzero-turn seams deferred (`DEFN-SEAM-NZ`). **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` — EXACT NEXT

- **Type / owner:** DEFN (documents-only contract); implementation agent. Authority: RA-126.4 (`Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`).
- **Objective:** state the exact amended A5 rule that lets a shared-node certified-seam relation take its direction from wedge side authority, with its enforcer impact, a non-weakening table and corrective-TB predictions.
- **Read before work:**
  - RA-126, RA-124.3 (P1–P3), RA-30a.3 (D3, `Architecture_M6_Frozen_Definitions.md`), RA-79.4, RA-78.4;
  - `src/pipeline/RemeshPipeline.cpp` (RP): RP:3855–3911 (`certified_seam_wedge_side`, `certified_seam_direction`); callers RP:4695, RP:5250–5262, RP:5293, RP:5878; A6 RP:5860–5905;
  - TB25 report; `LESSONS.md` §§3, 5.
- **In scope:** write `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` (at most 90 lines, anchored at HEAD):
  1. **The amended rule.** When both canonical occurrences are one shared node (equal `support` and equal `placement.selectedFace`), the two face-equality clauses do not apply, and direction comes from `certified_seam_wedge_side` with opposite sides. Every other clause is unchanged. Relations that are not shared-node keep the face clauses.
  2. **Enforcer impact:** every caller listed above, and a statement that A6, D3, the gauge-face check and the endpoint gauges are unchanged.
  3. **Non-weakening table:** shared node with the span outside the wedge; same side; equal sheets; two certificates; not shared-node with the face clause failing; shared node with a nonzero turn (still rejected at A6). Name the rejecting clause for each.
  4. **Predictions and falsifiers for the corrective TB:** the 12 A5-ISO rows get past the A5 seam reject; their next first failure is measured, not assumed green; the controls still pass; the TB21-PASS rows are unaffected.
- **Out of scope:** any code, compile or runtime; nonzero-turn seams; A2 per-occurrence representatives; any A6/D3 change; a minimum-face rule; new producer certificates.
- **Success evidence:** the contract is committed with all four parts, and STATUS is COMPLETE.
- **On success:** `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV` (Review, mandatory). It adjudicates the contract and, if accepted, issues CB25 (corrective, RP `certified_seam_direction` only).
- **On failure/blocker:** STOP and return to Review if the rule needs an A6 change, or if a caller depends on the face clause for anything other than side authority.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` | DEFN, per RA-126.4: documents-only A5 shared-node side-authority contract. |
| 2 — conditional | `M6-CP3-DEFN-SEAM-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV` | Review, only after step 1: adjudicates the contract; issues CB25 if accepted. |
| later — UNKNOWN until assigned | CB25 (corrective, RP `certified_seam_direction` only) → CB25-REV → TB26 (12 A5-ISO rows, guard, controls) → TB26-REV → selector-497 census → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` (nonzero-turn seams) when such a seam is observed | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **plan** — DEFN-SEAM: documents-only A5 shared-node side-authority contract (RA-126.4); no code, compile or runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md` (RA-126: TB25 routing, F = 0 branch, DEFN-SEAM scope); `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md` (RA-124.3 P1–P3); TB25 report; RA-30a.3 in `Architecture_M6_Frozen_Definitions.md`; `LESSONS.md` §§3, 5.
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
