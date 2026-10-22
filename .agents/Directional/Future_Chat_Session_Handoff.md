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
| Currency | 2026-10-22, after the DEFN-SEAM-A7 Review (RA-130). Accepted with amendments B1–B6. The frozen D7 test `cp3entry:5` already requires A7 to accept the certified seam relation and to reject its evidence tamper with site `cross-sheet`. Spans are bound to canonical endpoints. The duplicate pair check is dropped. A7's evidence check must find the certificate's own transition. Every cross-sheet rejection gets a distinct site. Periodic is recorded as latent. CB26 (compile only) is authorized. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. CB25 semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679` (compile GREEN); CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). CB25 changes only RP A5 shared-node predicates relative to `dae267a82`; no other RP-01 source file changed, and Linux CI compile behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB26 [run 39727886868](https://github.com/akashskypatel/Directional/actions/runs/39727886868), result `12403479548` (ZIP `3f7df8c2…ac2d`), expires 2026-10-29T05:26:45Z; 18/18, 9 PASS / 9 RED; reviewed by RA-129 (`Architecture_M6_CP3_TB26_Shared_Node_Seam_Witness_Harvest_Review_Decision_20261022.md`). CB25 package `12399179446`, source `c5e0b242f` (RA-128). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **Seam family (12 rows):** `focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448` (incl. G4-B002); `cp3entry:3, 5`. A5 (CB25) and A6 admit; nine rows stop at A7's cross-sheet rule (RA-129.3). Fix (RA-130.8): the certified-seam branch uses `certified_seam_direction` on canonical endpoints plus a relation-evidence check bound to the certificate's transition; Periodic and no-certificate relations are unchanged. D3 and D7 tampers unmeasured. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` — EXACT NEXT

- **Type / owner:** Code + Build, compile only; implementation agent. Authority: RA-130.8 (`Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`), on `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md` §§3–4 as amended by B1–B6.
- **Objective:** let A7 certify a cross-sheet OrdinaryFront relation that carries a typed seam certificate, using the same direction function as A5 and A6 plus an evidence check bound to that certificate, with an identifiable site on every rejection.
- **Read before work:** RA-130 (all); the contract §§3–5; RP:3855–3934, 5204–5262, 5804–5905, 7543–7603, 9265–9300; TQ:2725–2814 and 3977–4056 (D7 witness); `LESSONS.md` §§3, 5.
- **In scope:**
  1. **RP A7 forest-edge branch (RP:7543–7603).** For an OrdinaryFront edge with disjoint sheets and a typed certificate:
     - direction = `certified_seam_direction` on the `relation.id.first/second` occurrences and the relation's endpoint spans; none → reject, site `cross-sheet:seam-direction`;
     - otherwise the relation evidence (three lists) must contain the certificate's transition `{region, seam, sheets as the direction orders them}` in either orientation; missing → reject, site `cross-sheet` (pinned by D7);
     - `occurrenceCertified` is not evaluated in this branch.
     - Other cases keep today's predicate, with sites `cross-sheet:no-certificate` (OrdinaryFront) and `cross-sheet:periodic`.
  2. **RP RP:9276–9280:** append `":" + site` to `result.failure` for `UncertifiedCrossSheetBinding` when the site is not empty.
  3. **TQ:2811:** the helper records `"A7:" + geometry_embedding_failure_name(code) + ":" + site`.
  4. Nothing else. No explicit pair or binding equality (B3). Lines at most 100 columns.
- **Out of scope:** A5, A6, per-member A7 checks, A8, headers, other tests, selectors, workflows, runtime, Periodic semantics, nonzero-turn seams.
- **Success evidence:**
  - the diff touches only the places above;
  - eight targets compile with GMP/GMPXX, `runtimeExecution=false`;
  - record `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Code_Build_Record_20261022.md` (at most 30 lines) with the hunks, package id and hashes;
  - STATUS is COMPLETE.
- **On success:** `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV` (Review, mandatory): static diff adjudication; issues TB27 per RA-130.9.
- **On failure/blocker:** STOP and return to Review on a compile error, any needed edit outside the scope above, or if B4 cannot be stated from data A7 already holds.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY` | Code + Build, compile only, per RA-130.8: A7 certified-seam branch, site labels, failure suffix, helper record. |
| 2 — conditional | `M6-CP3-CB26-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-AUTHORITY-REV` | Review, only after step 1 completes: static diff adjudication; issues TB27. |
| later — UNKNOWN until assigned | TB27 (18 TB26 selections + 3 A7 site guards; D3 and D7 tamper falsifiers) → TB27-REV → CB27 (negative tests, TQ only: RA-127.4b + A7 unrelated-seam evidence and no-direction) → CB27-REV → TB28 (new tests + selector-497 census) → TB28-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up (RA-130.7) only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB26: A7 certified-seam cross-sheet branch with site labels and diagnostics (RA-130.8); compile only, no runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md` (RA-130: amendments B1–B6 and the CB26 scope); `Architecture_M6_CP3_DEFN_SEAM_A7_Certified_Seam_Cross_Sheet_Authority_20261022.md` §§3–5; TQ:3977–4056 (D7 witness); `LESSONS.md` §§3, 5.
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
