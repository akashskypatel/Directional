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
| Currency | 2026-10-22, after the TB26 Review (RA-129). CB25 works at A5, and A6 now admits the untampered certified seam relation (TB26's report said A6 was not reached; corrected). All nine RED rows stop in A7. Its OrdinaryFront cross-sheet rule (RP:7543–7603) can never pass when the endpoints share no sheet, because it needs a wedge transition that no occurrence can hold, and it ignores the typed seam certificate. Next: DEFN-SEAM-A7 (documents only). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. CB25 semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679` (compile GREEN); CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). CB25 changes only RP A5 shared-node predicates relative to `dae267a82`; no other RP-01 source file changed, and Linux CI compile behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB26 [run 39727886868](https://github.com/akashskypatel/Directional/actions/runs/39727886868), result `12403479548` (ZIP `3f7df8c2…ac2d`), expires 2026-10-29T05:26:45Z; 18/18, 9 PASS / 9 RED; reviewed by RA-129 (`Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`). CB25 package `12399179446`, source `c5e0b242f` (RA-128). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **Seam family (12 rows):** `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448` (incl. G4-B002); `cp3entry:3, 5`. A5 (CB25) and A6 now admit shared-node certified seam relations; `focused30:26–28` PASS individually. The other nine stop in A7: eight with `UncertifiedCrossSheetBinding`, and `focused30:24` with its code unprinted. The owner is A7's OrdinaryFront cross-sheet rule (RA-129.3). The D3 tamper is still unmeasured. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` — EXACT NEXT

- **Type / owner:** DEFN (documents-only contract); implementation agent. Authority: RA-129.4 (`Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`).
- **Objective:** define how A7 certifies a cross-sheet OrdinaryFront relation that carries a typed seam certificate, after a complete audit of every stage that decides cross-sheet admissibility.
- **Read before work:**
  - RA-129 (all), RA-127, RA-124.3;
  - the TB26 report `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Report_20261022.md`;
  - RP:3855–3920 (A5 side and direction), RP:5204–5262 (relation evidence), RP:5804–5905 (A6 seam branch), RP:7120–7610 (A7), RP:8240–8290 (verification), RP:9265–9300 (failure mapping); TQ:2725–2814 (D3 helper);
  - `LESSONS.md` "Keep definitions and their validation mutually traceable".
- **In scope:** write `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md` (at most 90 lines, anchored at HEAD) with:
  1. a **consumer audit** of every stage after A5 that decides cross-sheet admissibility (search `cornerWedgeSheets`, `cornerWedgeIsolation`, `isolationTransitions`, `SideIsolationEvidence`, `isolationSeamTransportCertificate`), with each predicate's verdict on a shared-node certified seam relation;
  2. whether `relationCertified` can hold for these relations (RP:5214–5233);
  3. the **amended A7 rule**:
     - for an OrdinaryFront edge with disjoint endpoint sheets and a typed seam certificate, the crossing is certified only if `certified_seam_direction` (the relation's spans and certificate) returns a direction and the endpoint sheets equal the certificate's sheets on the sides it selects;
     - no re-derived side and no bare sheet labels;
     - relations without a certificate, and all Periodic relations, keep the existing rule;
  4. the **diagnostic**: append A7's `site` to `result.failure` for `UncertifiedCrossSheetBinding` (RP:9276–9280); the D3 helper records the A7 code and site;
  5. a **non-weakening table** with the rejecting clause per case;
  6. **TB27 predictions and falsifiers**, including the `cp3entry:3` D3 tamper rejecting as `RelationCertificateConflict`.
- **Out of scope:** any code, compile or runtime; changes to A5, A6 or D3; nonzero-turn seams; Periodic cross-sheet semantics; DIAG-RETAIN.
- **Success evidence:** the contract is committed with all six parts, and STATUS is COMPLETE.
- **On success:** `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV` (Review, mandatory). It adjudicates the contract and, if accepted, issues CB26.
- **On failure/blocker:** STOP and return to Review if a further consumer cannot be stated without changing A6, or if `relationCertified` cannot be decided statically.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` | DEFN, per RA-129.4: A7 consumer audit, certified-seam cross-sheet rule, diagnostic site, non-weakening table, TB27 predictions. |
| 2 — conditional | `M6-CP3-DEFN-SEAM-A7-RP01-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV` | Review, only after step 1 completes: adjudicates the contract; issues CB26 if accepted. |
| later — UNKNOWN until assigned | CB26 (RP: A7 rule and failure-site suffix; TQ: helper record only) → CB26-REV → TB27 (the same 18 TB26 selections) → TB27-REV → CB27 (negative tests for RA-127.4b and the A7 table; TQ only) → CB27-REV → TB28 (new tests + selector-497 census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` only after a nonzero-turn witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **plan** — DEFN-SEAM-A7: documents-only A7 certified-seam cross-sheet contract with full consumer audit (RA-129.4); no code, compile or runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md` (RA-129: TB26 attribution, A6 correction, A7 proof, DEFN-SEAM-A7 scope); `Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Report_20261022.md`; `Architecture_M6_CP3_DEFN_SEAM_A5_Shared_Node_Side_Authority_Review_Decision_20261022.md` (RA-127); `LESSONS.md` "Keep definitions and their validation mutually traceable".
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
