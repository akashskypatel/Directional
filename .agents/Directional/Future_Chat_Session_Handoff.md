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
| Currency | 2026-10-22, after the TB27 Review (RA-132). The 12 seam-family rows, the D3 gauge tamper, the D7 evidence tamper and all guards and controls PASS (21/21, verified). RA-127.4 (iii) and RA-130 B1 are discharged at runtime. Three new A7 rejection paths and the B4 precision case are not covered by any test yet (CB27). Realigned: the selector-497 census (TB28) runs now, on the unchanged CB26 package, before the test-only CB27. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB26 semantic source `e3d60337ed34538547d3a6d519bafae5b184330e` (compile GREEN), later STATUS/control-plane commits are not semantic evidence; refetch HEAD before mutation. CB25 semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679` (compile GREEN); CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). CB25 changes only RP A5 shared-node predicates relative to `dae267a82`; no other RP-01 source file changed, and Linux CI compile behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB27 [run 39764327506](https://github.com/akashskypatel/Directional/actions/runs/39764327506), result `12420676412` (ZIP `33dc0878…babb`), 21/21 PASS, targeted; reviewed by RA-132 (`Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md`). CB26 package `12409939859` (ZIP `ee08279e…86fa`, source `e3d60337e`; expires 2026-10-29T08:00:15Z). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **Seam family (12 rows):** `focused30:6, 20, 24–28`; `selector:444, 446, 448`; `cp3entry:3, 5`. All PASS in targeted TB27 runs, after CB25 (A5) and CB26 (A7); census pending. Not yet tested: `cross-sheet:seam-direction`, `cross-sheet:no-certificate`, `cross-sheet:periodic`, B4 precision, RA-127.4b. Periodic is latent (RA-130.7). **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS` — EXACT NEXT

- **Type / owner:** Test + Benchmark, artifact-only census; implementation agent. Authority: RA-132.5 (`Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md`).
- **Objective:** measure the full frozen 497-row selector on the CB26 package and diff it row by row against TB21, so that any regression from CB25/CB26 is found before more work builds on them.
- **Read before work:**
  - RA-132 (all); RA-115 and the TB21 inventory `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv` (48 RED);
  - the TB27 report `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Report_20261022.md`;
  - the harness `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`) and `.github/workflows/agent-test-benchmark-reusable.yml`.
- **In scope:**
  1. Run the harness unchanged through the reusable workflow with:
     - `CANDIDATE_ARTIFACT_ID=12409939859`;
     - `EXPECTED_SOURCE_SHA=e3d60337ed34538547d3a6d519bafae5b184330e`;
     - `EXPECTED_CANDIDATE_ZIP_SHA256=ee08279e537af4e99f287d28595df0ef639e632aa345bc0b1986bbb361ee86fa`;
     - `EXPECTED_ROOT_MANIFEST_SHA256=0c9183b848e4b13afae4c0b84c23ddd18f0f1526ccdcf4d4da688dc893e8b1cf`;
     - `EXPECTED_SOURCE_ARCHIVE_SHA256=d37cfbdab24b92aad6ab2ecfd135d92702c0874f9c69a0164bf578705d78955c`.

     The package expires 2026-10-29T08:00:15Z.
  2. Write the report `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md`: totals; every PASS→RED and RED→PASS against TB21; the first failure of every RED; the A7 site of every `UncertifiedCrossSheetBinding`.
  3. Write the inventory `Architecture_M6_CP3_TB28_Selector_497_Red_Inventory.tsv`: the TB21 columns plus a TB21 verdict column.
- **Predictions:**
  - the 12 seam-family rows and `selector:447` go RED→PASS;
  - no TB21 PASS row becomes RED;
  - so at least **462/497**;
  - the other 35 TB21 RED rows are measured, not assumed.
- **Out of scope:** any source, test, fixture, selector, workflow or harness semantics (a fix to extraction mechanics only, recorded); compile, relink or benchmarks; promotion; classifying causes beyond first-failure facts.
- **Success evidence:** the immutable result artifact with a verified manifest; 497 executed, with no skip or duplicate; the report and inventory committed; STATUS COMPLETE.
- **On success:** `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV` (Review, mandatory): adjudicates the census and classifies the REDs; issues CB27.
- **On failure/blocker:** STOP and record it. Any PASS→RED, any `cross-sheet:seam-direction` or `cross-sheet:periodic` site, any RED seam-family row, or any hash mismatch goes to Review with evidence; never fix in-turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS` | Artifact-only census of 497 on CB26 package `12409939859`; row diff against TB21 (RA-132.5). |
| 2 — conditional | `M6-CP3-TB28-RP01-SELECTOR-497-CENSUS-REV` | Review, only after step 1 completes: census adjudication and RED classification; issues CB27. |
| later — UNKNOWN until assigned | CB27 (test-only, TQ: unrelated-seam evidence, no-certificate, lattice-coordinate and outside-wedge negatives; same-side if constructible; RA-132.6) → CB27-REV → TB29 (new tests + guards) → TB29-REV → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up (RA-130.7) only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — TB28: artifact-only selector-497 census on the CB26 package with a row diff against TB21 (RA-132.5); no build.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Review_Decision_20261022.md` (RA-132: TB27 adjudication, census-first realignment, TB28 inputs, CB27 scope); `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Report_20261022.md`; `Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md` and its inventory TSV; harness `m6_cp3_entry_497_artifact_only_harness.sh`.
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
