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
| Currency | 2026-10-22, after the DEFN-SEAM Review (RA-127). The contract is accepted with binding amendments: a shared node also needs equal lattice coordinates (A1); the rejection-site classifier must mirror the rule (A2); TB26 must report the A6 seam branch and D3 tamper for `cp3entry:3/5` (A3); negative tests follow in CB26 (A4). CB25 (RP only, compile only) is authorized. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). All other RP-01 sources remain byte-identical to `dae267a82`, and Linux CI build behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB25 [run 39682528031](https://github.com/akashskypatel/Directional/actions/runs/39682528031), result `12384333036` (ZIP `f10ef778…cbc`), expires 2026-10-28T21:56:02Z; 11/11, 6 PASS / 5 RED; reviewed by RA-126 (`Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`). CB24 package `12378590512` (RA-125). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **A5-ISO (12 rows):** `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448` (incl. G4-B002); `cp3entry:3, 5`. One mechanism: the A5 certified-seam face clauses (RP:3891–3892) on shared-node relations with identity turn. Fix (RA-126.4, RA-127): skip those clauses only when support, `selectedFace` and lattice coordinate are all equal; classifier mirrors; A6/D3 source unchanged; nonzero-turn seams deferred (`DEFN-SEAM-NZ`). **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` — EXACT NEXT

- **Type / owner:** Code + Build, compile only; implementation agent. Authority: RA-127.5 (`Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`), on the contract `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` as amended by RA-127.2–127.3.
- **Objective:** apply the shared-node exemption to the A5 certified-seam face clauses and to its rejection-site classifier, with one shared predicate, and prove it compiles.
- **Read before work:** RA-127 (all), the DEFN-SEAM contract §§1–3, RA-118.2; RP:3855–3911, RP:4686–4702, RP:5250–5345, RP:5860–5905; `LESSONS.md` §§3, 5.
- **In scope** (`src/pipeline/RemeshPipeline.cpp` only):
  1. A file-local helper `certified_seam_shared_node(first, second)`: true only if `support`, `placement.selectedFace` and `placement.lattice.latticeCoordinate` are all equal (RA-127.2).
  2. In `certified_seam_direction` (RP:3880–3911): when the helper holds, skip the two face-equality clauses (RP:3891–3892). Every other clause and the side logic stay byte-identical.
  3. In the rejection-site classifier (RP:5303–5333): when the helper holds, skip the `first-face`/`second-face` labels so the labels mirror (2). Keep the site text format.
  4. Lines at most 100 columns; no other edit.
- **Out of scope:** A6 (including RP:5860–5905), A2, headers, TQ and other tests, fixtures, selectors, workflows, runtime execution, nonzero-turn seams, any new site token.
- **Success evidence:**
  - the diff touches only RP and only the three places above;
  - eight targets compile with GMP/GMPXX, `runtimeExecution=false`;
  - record `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Code_Build_Record_20261022.md` (at most 30 lines) with the diff hunks, package id and hashes;
  - STATUS is COMPLETE.
- **On success:** `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV` (Review, mandatory): static adjudication of the diff; issues TB26.
- **On failure/blocker:** STOP, record it, return to Review on a compile error, any need to edit outside RP, or if the classifier cannot use the shared helper.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` | Code + Build, compile only, per RA-127.5: RP shared-node predicate, face-clause exemption, classifier mirror. |
| 2 — conditional | `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV` | Review, only after step 1 completes: static diff adjudication; issues TB26. |
| later — UNKNOWN until assigned | CB25-REV → TB26 (12 A5-ISO rows reporting RA-127.4 for `cp3entry:3/5`; guard `selector:447`; TB25 controls) → TB26-REV → CB26 (RA-127.4b negative tests, TQ only) → CB26-REV → TB27 (new tests + selector-497 census) → TB27-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` only after a nonzero-turn witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB25: RP-only shared-node exemption and classifier mirror (RA-127.5); compile only, no runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` (RA-127: amendments A1–A4 and the CB25 scope); `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` §§1–3; RA-118.2 in `Architecture_M6_Frozen_Definitions.md`; `LESSONS.md` §§3, 5.
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
