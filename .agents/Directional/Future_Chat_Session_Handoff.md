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
| Currency | 2026-10-22, RA-128 independently accepted CB25 RP-only source and compile package; TB26 artifact-only runtime verification pending. The contract includes binding amendments: a shared node also needs equal lattice coordinates (A1); the rejection-site classifier must mirror the rule (A2); TB26 must report the A6 seam branch and D3 tamper for `cp3entry:3/5` (A3); negative tests follow in CB26 (A4). CB25 completed and RA-128 compile-reviewed; TB26 is the one authorized next turn. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. CB25 semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679` (compile GREEN); CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). CB25 changes only RP A5 shared-node predicates relative to `dae267a82`; no other RP-01 source file changed, and Linux CI compile behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB25 [run 39682528031](https://github.com/akashskypatel/Directional/actions/runs/39682528031), result `12384333036` (ZIP `f10ef778…cbc`), expires 2026-10-28T21:56:02Z; 11/11, 6 PASS / 5 RED; reviewed by RA-126 (`Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Review_Decision_20261022.md`). CB25 package `12399179446` (GREEN compile, 28/28 independently verified by RA-128, no runtime); CB24 package `12378590512` (RA-125). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **A5-ISO (12 rows):** `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448` (incl. G4-B002); `cp3entry:3, 5`. One mechanism: the A5 certified-seam face clauses (RP:3891–3892) on shared-node relations with identity turn. Fix (RA-126.4, RA-127): skip those clauses only when support, `selectedFace` and lattice coordinate are all equal; classifier mirrors; A6/D3 source unchanged; nonzero-turn seams deferred (`DEFN-SEAM-NZ`). **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST` — EXACT NEXT

- **Type / owner:** artifact-only Test + Benchmark, no rebuild, repair, test/fixture/selector/source change; source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679`, eight-target GMP/GMPXX package `12399179446`, SHA-256 `a82c75e0f648fa8f1c8e34e07934d7a01321692e12e993638f02465766f236e9`.
- **Review authority:** `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` (RA-128). Independently verified source diff at `c5e0...`, matching RP bytes in package and 28/28 package hashes, no runtime.
- **Scope:** harvest 12 A5-ISO rows (`focused30:6,20,24,25,26,27,28`; `selector:444,446,448`; `cp3entry:3,5`), guard `selector:447` and six TB25 controls. For `cp3entry:3/5`, explicitly report certified reciprocal relation and untampered A6 result; for `cp3entry:3`, existing D3 face-gauge quarter-turn tamper must reject `RelationCertificateConflict`.
- **Stop/falsifiers:** any original exempted A5 face-label still rejects an exact shared-node pair, missing certified relation, admitted invalid wedge/side/sheet/certificate, control PASS→RED, D3 tamper admitted, or artifact/hash/source mismatch. Publish exact first failure; no synthetic PASS or green credit. Details RA-128 §3.
- **Deferred:** CB26 negative tests (RA-127 A4, test-only), `DEFN-SEAM-NZ`, M1, D2 and DIAG-RETAIN stay outside TB26. Stable **66/17/49**, debt **1**, CP2 accepted **491/491**, R3 **403/497** rejected, TB21 candidate **449/497**, selector497 frozen; RP-01 open.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — done | `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY` | Code + Build; exact source and package in CB25 record; no runtime. |
| 2 — done | `M6-CP3-CB25-RP01-A5-SHARED-NODE-SIDE-AUTHORITY-REV` | RA-128 accepted scoped code and compile-only evidence. |
| 3 — next | `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST` | TB26 immutable artifact-only harvest; A3/D3 decisive runtime evidence. |
| later — UNKNOWN until assigned | TB26-REV → CB26 (RA-127.4b negative tests, TQ only) → CB26-REV → TB27 (new tests + selector-497 census) → TB27-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` only after a nonzero-turn witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test_benchmark** — TB26 immutable CB25 package; A5/A6/D3 witness harvest only.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` (RA-128 TB26 source/limits), `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` (RA-127 A1–A4); `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` §§1–3; RA-118.2 in `Architecture_M6_Frozen_Definitions.md`; `LESSONS.md` §§3, 5.
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
