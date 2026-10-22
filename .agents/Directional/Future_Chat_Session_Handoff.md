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
| Currency | 2026-10-22, TB26 artifact-only runtime harvest completed without acceptance (18/18, 9 PASS / 9 RED); RA-128 §3 stop/falsifier requires independent Review because `cp3entry:3/5` lack the certified reciprocal relation and A6/D3 guards were not reached. CB25 remains compile-reviewed only. The TB26 Review canonical ID is UNKNOWN until assigned. A4 negative tests/CB26 and other downstream turns remain unauthorized. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. CB25 semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679` (compile GREEN); CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). CB25 changes only RP A5 shared-node predicates relative to `dae267a82`; no other RP-01 source file changed, and Linux CI compile behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB26 [run 39727886868](https://github.com/akashskypatel/Directional/actions/runs/39727886868), result `12403479548` (ZIP `3f7df8c2ecbd9587127c4621feb3965abe383df31deae57bd48cf0283080ac2d`), 21/21 hashes, 18/18 executed, 9 PASS / 9 RED, 6/6 controls PASS; 12 A5-ISO = 3 PASS / 9 RED; A6/D3 obligations unreached. Owner: `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Report_20261022.md`. CB25 immutable package `12399179446`, source `c5e0b242...` (28/28 GMP, RA-128). Last broader candidate TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **A5-ISO (12 rows):** `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448` (incl. G4-B002); `cp3entry:3, 5`. RA-127 shared-node exemption was compiled and reviewed but TB26 reveals six upstream uncertified cross-sheet bindings, one absent A7 and two failed certified-reciprocal seam fixture searches. Causal relation to the changed A5 clauses is unresolved; A6/D3 paths were never reached. Independent Review must adjudicate before correction. Nonzero-turn seams deferred (`DEFN-SEAM-NZ`). **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `UNKNOWN` (independent TB26 Review) — EXACT NEXT

- **Type / owner:** independent Review; canonical identifier is not assigned by available authority, so assign/confirm it before starting substantive Review. Do not invent an ID or initiate implementation.
- **Objective:** independently review immutable TB26 evidence and RA-128 §3 falsifiers; adjudicate why the 12 A5-ISO witnesses yield 3 PASS / 9 RED despite the CB25 shared-node change, including the six `UncertifiedCrossSheetBinding`, one absent A7 and the two `A7:rejected-certified-seam` fixture searches.
- **Read before work:** `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Report_20261022.md` and its full raw result artifact `12403479548`; RA-128 `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md`, RA-127 contract review and regression tracker.
- **In scope:** independent source-of-failure/fixture attribution and bounded decision about how to obtain a certified reciprocal seam to exercise A6 untampered and D3 tamper; confirm controls and non-regression. Keep candidate status unless independently proven otherwise.
- **Out of scope:** runtime acceptance from 9 PASS, edit to source/fixtures/selectors, rerun/compile in this completed TB26 turn, speculative CB26/DEFN/NZ/M1/D2/DIAG-RETAIN work.
- **Success evidence:** a retained independent Review decision with explicit falsifiers, causal attribution or declared unresolved facts, and an authorized exact next corrective turn (or STOP if unknown).
- **On success:** `UNKNOWN` until the Review assigns the successor. **On failure/blocker:** `UNKNOWN` — stop, do not silently continue.
- **Frozen authority:** CP2 **491/491** accepted, R3 **403/497** rejected, TB21 candidate **449/497**, stable **66/17/49**, debt **1**, selector497 frozen; RP-01 open and RP-02 UNREACHED.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — done | `M6-CP3-TB26-RP01-A5-SHARED-NODE-SEAM-WITNESS-HARVEST` | Verified diagnostic harvest (9 PASS / 9 RED); missing certified seam falsifier stops acceptance. |
| 2 — next, ID UNKNOWN | Independent TB26 Review | Must first assign canonical ID; adjudicate root cause and issue bounded next turn. |
| 3 — conditional UNKNOWN | CB26 / subsequent correction and separate TB | Not authorized without independent Review decision. `DIAG-RETAIN` deferred. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — TB26 evidence, falsifiers and candidate/non-stable classification; no new code or runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Report_20261022.md` (run 39727886868, 18 logs, unresolved A6/D3); `Architecture_M6_CP3_CB25_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` (RA-128 stop/falsifiers), `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` (RA-127 A1–A4); `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_20261022.md` §§1–3; RA-118.2 in `Architecture_M6_Frozen_Definitions.md`; `LESSONS.md` §§3, 5.
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
