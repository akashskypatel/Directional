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
| Currency | 2026-10-21, TB21 Review (RA-115). The selector-497 census on the CB20A package is regression-free: 449/497, 0 PASS→RED, `cp3entry:6` RED→PASS, no gauge-pin site in any log. The six torus RED rows are reclassified (RA-115.3): TQ:1697 is the frozen D2 / RA-33.2 odd-gauge selection, which `88aa8eae0` placed in a fixture shared with six CP2-GREEN rows. Next: CB21, a test-only change that confines D2 to `cp3entry:1` and measures every witness predicate. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source `e22c5da5f8ab86a39650c670340a658847a2ac7e`; HEAD `src`, `include` and `tests` are identical to it. |
| Last compiled semantic source | CB20A eight-target GMP/GMPXX compile [39520787768](https://github.com/akashskypatel/Directional/actions/runs/39520787768), package `12310848591`, ZIP SHA-256 `0c9f048e9a67fdaf61231b2ffa6834ee21a48e142f9cdae9e7ab14e015fc3ff5`; hashes `28/28`, statuses clean, `runtimeExecution=false`; **expires 2026-10-28T00:23:30Z**; accepted by RA-113. Record: `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md` (RA-113.1). |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate / rejected evidence | TB21: run [39533914719](https://github.com/akashskypatel/Directional/actions/runs/39533914719), result `12317287104` (ZIP `12279a26…9c8d`), expires 2026-11-04T02:46:55Z; 497/497 executed, 449 PASS / 48 RED, 0 PASS→RED; verified harvest in `Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md` (RA-115.1); census baseline `Architecture_M6_CP3_TB21_Selector_497_Red_Inventory.tsv` (`6eb5022a…7c34`). TB20: run `39527537505`, result `12314700010`, expires 2026-11-04; 26 rows; RA-114.1. TB19A `12292268624` and TB19 `12285225197` (expire 2026-11-03): pin-site harvests accepted by RA-110/RA-109. TB18 Part A `12231529583` and Part B `12232299548` (448/497), expire 2026-11-03; superseded as candidate evidence by TB21. |
| Regression accounting | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 **449/497** (was TB18 448/497). |
| Active boundary | `RP-01` open. CB20/CB20A is regression-free on the 497 selector (RA-115.2). M2 residue: six torus rows fail at the D2 odd-gauge selection inherited from the shared fixture (RA-115.3; test-scope defect, CB21); `cp3entry:1` alone requires D2, and D2's attainability on this torus goes to DEFN-T1 after TB22; `cp3entry:2` and `focused30:12` go to the M1 DEFN. M1 (10 identities, RA-105.3) unchanged. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE` — EXACT NEXT

- **Type / owner:** Code + Build, test-only; implementation agent. Authority: RA-115.5 (`Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md`).
- **Objective:** confine D2's odd-gauge selection to `cp3entry:1`, the identity that requires it, and make every torus witness predicate measurable on every candidate. Only `tests/SurfaceCellTransitionQuotientTests.cpp` (TQ) changes.
- **Read before work:**
  - RA-115 (§3 and §5);
  - D2 in `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md` and its review in `Architecture_M6_DEFN_R5_R2_Review_Record.md`;
  - `LESSONS.md` §2: **A fixture change reaches every fixture built from it**, **A failure hidden behind an earlier one is unmeasured**.
- **In scope (TQ lines at `e22c5da5f`):**
  1. **Predicates.** In `make_nonzero_z4_torus_witness_fixture` (selection loop TQ:1687–1744), evaluate each candidate independently, with no early `continue` on the delta:
     - gauge presence;
     - `delta`;
     - the reciprocal tracer pair (unchanged test);
     - the holonomy match (unchanged test).
  2. **Selection.**
     - Take the first candidate that passes every non-gauge predicate with `delta ∈ {1,3}`.
     - If there is none, take the first candidate that passes every non-gauge predicate.
     - Throw only when no candidate passes the non-gauge predicates.
  3. **Receipt.**
     - The seven counts, each counted over all candidates: `sourceA3Candidates`, `sourceFaceGaugePairs`, `oddFaceGaugePairs`, `reciprocalTracerPairs`, `holonomyMatchedPairs`, `publishedPeriodicHolonomies`, `nonzeroHardCarriers`.
     - One `c<i>=<carrier>:delta=<d>;recip=<0|1>;holo=<0|1>` entry per candidate.
     - `selected=c<i>` or `selected=none`.

     Append the receipt to the throw message, and remove "and odd selected-face gauge delta" from its text.
  4. **Fixture member.** Add `std::string selectionReceipt` as the last member of `ProducedTorusWitnessFixture` (TQ:903), and fill it in the return at TQ:1771.
  5. **`cp3entry:1`.** Keep the TQ:2802 D2 assertion and its message, and append `<< " receipt=" << fixture.selectionReceipt`. Nothing else in the test changes.
  6. **Compile.** The eight-target GMP/GMPXX compile, as for CB20A, with `runtimeExecution=false`.
  7. **Record.** `Architecture_M6_CP3_CB21_Torus_Witness_Scope_Code_Build_Record_20261021.md`, at most 30 lines: source SHA, diff stat, compile run, package id, ZIP digest, hash count, expiry, and the root-manifest and source-archive SHA-256s.
- **Out of scope:**
  - `src` and `include`;
  - any other test or helper, including `enumerate_torus_source_witnesses` and `produced_semantic_relation_for_witness`;
  - D2's requirement;
  - selectors, harnesses and workflows;
  - any runtime execution;
  - DEFN-T1 and the M1 DEFN.
- **Success evidence:**
  - the diff touches only TQ: the struct member, the selection loop and receipt, the return, and the `cp3entry:1` stream;
  - the compile is GREEN;
  - the package is verified: hashes, clean statuses, `runtimeExecution=false`;
  - the record is committed and STATUS is COMPLETE.

  If the compile is still running at your closeout bound, leave STATUS `IN_PROGRESS`, and Review will harvest it.
- **On success:** `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE-REV` (Review, mandatory). It checks the diff statically and sets the TB22 rows and predictions:
  - P1: the five CP2 rows get past the fixture;
  - P2: `cp3entry:1` fails at its own D2 assertion, with the receipt;
  - P3: `focused30:12` is unchanged;
  - falsifier: the fixture throws with `reciprocalTracerPairs=0` or `holonomyMatchedPairs=0`.
- **On failure/blocker:** STOP and return to Review on:
  - a compile failure;
  - any need to touch `src`, `include` or another test.

  There is no repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE` | Code + Build, test-only (TQ), per RA-115.5. Compile only; no runtime. |
| 2 — mandatory | `M6-CP3-CB21-RP01-TORUS-WITNESS-SCOPE-REV` | Review: static diff check; TB22 rows and predictions. |
| planned, not authorized | TB22 (the seven torus consumers, `cp3entry:6`, three controls) → TB22-REV → DEFN-T1 (D2 attainability on the torus under RA-111.3, from the TB22 receipt) → DEFN-M1 (M1 binding owner, RA-105.3; also `cp3entry:2`, `focused30:12`) → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as each Review assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB21, test-only witness-selection scope in TQ (RA-115.5); compile only, no runtime.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB21_Selector_497_Census_Review_Decision.md` (RA-115, the CB21 specification); D2 in `Architecture_M6_DEFN_R5_R1_CP3_Entry_Recovery_Definition_Record.md` and `Architecture_M6_DEFN_R5_R2_Review_Record.md`; `Architecture_M6_CP3_CB20A_Gauge_Pin_Domain_Review_Decision.md` (RA-113, compile facts); `LESSONS.md` §§2, 7.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md`.

**Review tooling:** `.agents/Directional/tools/` holds read-only `review_check.py`, `selector_probe.py`, and `fixture_probe.py`; history-sensitive review gates require real committed history, not a synthesized snapshot.

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
