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
| Currency | 2026-10-20, Review of the CB19 compile failure (RA-106). CB19 (`1f73d0abd`) failed the GMP compile in `directional_core` preflight: 28 labels concatenate two string literals. The RA-105.5 diagnostic design stands, and no second defect is masked. Next: the corrective build CB19A (RA-106.6). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 draft); refetch before mutation. Last compiled semantic source `3bd24682c5e18eece541ab4d1f38f781a2230e41`, CB18 package `12227516380` (ZIP `d09c32d6…31cdc4`, expires 2026-10-26), compile-only. CB19 source `1f73d0abd` did not compile: run `39428435345`, log artifact `12265949093`, no package. Record: `Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Failure_20261020.md`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB18 Part A: run `39349041417`, result `12231529583` (ZIP `e08b092d…b459`), 12/14. TB18 Part B: run `39349459268`, result `12232299548` (ZIP `b3ba4566…6e9b`), 448/497. Both expire 2026-11-03 and are adjudicated as candidate evidence (RA-104 as corrected by RA-105). Inventory `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`. Not promoted. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected. RA-105 records candidate attributions only, with no count change: M1 (`80fc1688f`, certificate binding) and M2 (`1eaea310f`, gauge-pin domain). |
| Active boundary | `RP-01`: B2 is cleared. `cp3entry:1/2/6` end at checked-factory rejection. RA-105 found two mechanisms: M1 validation-order shadowing (10 identities) and M2, the gauge-pin domain hypothesis H-pin (torus 6 + `focused30:12`). The clause that rejects `cp3entry:2/6` is unknown. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE` — EXACT NEXT

- **Type / owner:** Code + Build, compile only; corrects CB19 with no admission change. Authority: RA-106.3, RA-106.4 and RA-106.6 (`Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Review_Decision.md`), on top of RA-105.5.
- **Objective:** compile CB19's rejection-site labels so that TB19 can name the clause that rejects each `PublishedProductRejected` identity.
- **In scope** (on top of `1f73d0abd`):
  1. S, certificate loop: insert `certificate_site`, `endpoint_site` and `junction_site` lambdas at the loop heads (S:8776, S:8901, S:9035), as RA-106.3 gives them.
  2. Rewrite the 26 scoped labels as calls to those lambdas.
  3. Give the two pin labels a `std::string` first operand, wrapped to the file's width.
  4. TQ:1892 new test: both edge vertices must be corners of face 0.
  5. GMP/GMPXX, eight targets, package with `runtimeExecution=false`. The CB19A record has the label → S-line table.
  6. CB19's staged transport file is removed at closeout.
- **Out of scope:**
  - the header and S:13146;
  - any other test;
  - selectors, harnesses and fixtures;
  - `RemeshPipeline.cpp`;
  - any condition, ordering or code;
  - running anything.
- **Success evidence:**
  - the eight targets compile;
  - the package and source SHA-256 match;
  - against `3bd24682c`, the `make` diff is insertions only;
  - 47 labels, unique, byte-identical to CB19's;
  - no line in `make` is longer than 100 columns.
- **On success:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE`, pinned to the CB19A package.
- **On failure/blocker:** STOP on any compile error. Record the first diagnostic of each distinct error and return to Review. There is no second repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE` | Compile failure (`1f73d0abd`). Reviewed by RA-106. |
| 1 — next | `M6-CP3-CB19A-RP01-FACTORY-REJECTION-SITE` | CB, compile only; RA-106.6. |
| 2 — conditional | `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` | TB, artifact-only; the 22 identities of RA-105.6, with RA-106.5's falsifier. Runs only after CB19A compiles. |
| 3 — mandatory | `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV` | Review: rules on H-pin, on the `cp3entry:2/6` clause and on the RA-103.5 R-route falsifier, and orders the DEFN. |
| planned, not authorized | DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as TB19-REV assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code+build** — CB19A corrective build of the factory site labels (RA-106.6), GMP compile only, no runtime.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_CB19_Factory_Rejection_Site_Compile_Review_Decision.md` (RA-106) and `Architecture_M6_CP3_TB18_REV_Factory_Rejection_Review_Decision.md` (RA-105.5); `src/geometry/SurfaceCellTracing.cpp` S:8439–9577 (CB19 labels; loop heads S:8776, S:8901, S:9035); TQ:1892–1931 (new test); `LESSONS.md` §§5, 7.
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
