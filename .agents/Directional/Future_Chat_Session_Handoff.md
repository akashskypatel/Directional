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
| Currency | 2026-10-22, after RA-131 CB26-REV: B1–B6 independently static-reviewed and compile package verified; **runtime unmeasured**. TB27 is the sole authorized next turn. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB26 semantic source `e3d60337ed34538547d3a6d519bafae5b184330e` (compile GREEN), later STATUS/control-plane commits are not semantic evidence; refetch HEAD before mutation. CB25 semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679` (compile GREEN); CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). CB25 changes only RP A5 shared-node predicates relative to `dae267a82`; no other RP-01 source file changed, and Linux CI compile behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | CB26 GMP compile [run 39744189868](https://github.com/akashskypatel/Directional/actions/runs/39744189868), artifact `12409939859`, outer SHA-256 `ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`, 28/28 manifest, `runtimeExecution=false`, exact source `e3d60337ed34538547d3a6d519bafae5b184330e` (compile-only; NOT runtime accepted); TB26 [run 39727886868](https://github.com/akashskypatel/Directional/actions/runs/39727886868), result `12403479548` (ZIP `3f7df8c2…ac2d`), expires 2026-10-29T05:26:45Z; 18/18, 9 PASS / 9 RED; reviewed by RA-129 (`Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`). CB25 package `12399179446`, source `c5e0b242f` (RA-128). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **Seam family (12 rows):** `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448` (incl. G4-B002); `cp3entry:3, 5`. TB26 found A5 and A6 admit while nine rows stopped at A7. CB26 now statically adds RA-130.8 certificate-bound A7 direction/evidence checking and diagnostic sites; no runtime effect has been measured. Periodic behavior unchanged (latent B6), D3 and D7 tamper outcomes unmeasured. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION` — EXACT NEXT

- **Type / owner:** immutable artifact-only Test + Benchmark; issued by RA-131 after independent CB26 source/compile review; use `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md` and RA-130.9.
- **Source/package:** `e3d60337ed34538547d3a6d519bafae5b184330e`, artifact `12409939859`, ZIP SHA-256 `ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`, 28/28 manifest, `runtimeExecution=false` at compile.
- **Selections:** 18 unchanged TB26 case identities (same six controls/guard) plus RA-130.9 three exact A7 site guards. Do not modify the frozen 497 selector. Run only packaged binaries, do not rebuild, reconfigure or change test source; preserve immutability.
- **Falsifiers:** eight target rows still at `cross-sheet:seam-direction`; D7 tamper passes or has a site other than exactly `cross-sheet`; D3 quarter-turn tamper passes; any TB26 control or A7 site guard RED; any `cross-sheet:periodic` event; missing/duplicate/skipped selected test; mutated/mismatched package.
- **On completion:** TB27-REV required; report measured first failures without inferred PASS and do not start CB27 or alter stable ledgers without independent Review.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION` | RA-131-authorized artifact-only TB27; 18 TB26 rows + three A7 site guards, D3/D7 falsifiers. |
| 2 — conditional | TB27-REV (canonical ID to be assigned by TB27 closeout) | Required independent adjudication of TB27 outcomes; no successor until Review. |
| later — unassigned | CB27 → CB27-REV → TB28 → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review | Planned only; each intervening Review must authorize its next edge. Periodic and nonzero-turn seams remain witness-gated. |
| later — unassigned | `DIAG-RETAIN` | User-directed diagnostic snapshots, queued clear of RP-01 turns in `TODO.md`. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test/benchmark** — RA-131-authorized TB27 immutable package, 21 exact identities, D3/D7 oracle.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. RA-131 (`Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`), RA-130 B1–B6, TB26 harness selections, CB26 code/build record, exact GMP package `12409939859`, TQ D3/D7 oracles; `LESSONS.md` evidence/witness sections.
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
