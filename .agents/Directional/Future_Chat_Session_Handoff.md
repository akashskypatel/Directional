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
| Currency | 2026-10-20, Review of TB18-REV (RA-105). TB18's measurements are confirmed. RA-104's locus, mechanism and priority are corrected. Every cross-region CP3-entry RED now ends at the checked factory (`PublishedProductRejected`), and the rejecting clause is not logged. Next: the rejection-only CB19 site diagnostic. RA-104's selector242 CB is deferred to fixture debt. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` (PR #8 draft); refetch before mutation. Semantic source `3bd24682c5e18eece541ab4d1f38f781a2230e41`; CB18 package `12227516380` (ZIP `d09c32d6…31cdc4`, expires 2026-10-26), compile-only. Record: `Architecture_M6_CP3_CB18_R10_Consumer_Rail_Vertex_Endpoint_Code_Build_Record_20261019.md`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB18 Part A: run `39349041417`, result `12231529583` (ZIP `e08b092d…b459`), 12/14. TB18 Part B: run `39349459268`, result `12232299548` (ZIP `b3ba4566…6e9b`), 448/497. Both expire 2026-11-03 and are adjudicated as candidate evidence (RA-104 as corrected by RA-105). Inventory `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`. Not promoted. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected. RA-105 records candidate attributions only, with no count change: M1 (`80fc1688f`, certificate binding) and M2 (`1eaea310f`, gauge-pin domain). |
| Active boundary | `RP-01`: B2 is cleared. `cp3entry:1/2/6` end at checked-factory rejection. RA-105 found two mechanisms: M1 validation-order shadowing (10 identities) and M2, the gauge-pin domain hypothesis H-pin (torus 6 + `focused30:12`). The clause that rejects `cp3entry:2/6` is unknown. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE` — EXACT NEXT

- **Type / owner:** Code + Build, compile only; a rejection-only diagnostic with no admission change. Authority: RA-105.5 (`Architecture_M6_CP3_TB18_REV_Factory_Rejection_Review_Decision.md`).
- **Objective:** label every `InvalidSourceAuthority` return of `SurfacePhaseFrontProduct::make`, so that TB19 can name the clause that rejects each `PublishedProductRejected` identity.
- **In scope:**
  1. Header: add `std::string sourceAuthoritySite` as the last member of `SurfacePhaseFrontProductError`, and `std::string publishedProductSourceAuthoritySite` as the last member of `SurfacePhaseFrontFailure`.
  2. `make` (S:8439–9530): immediately before each `InvalidSourceAuthority` `return error;`, add one assignment of a unique label.
     - Format: `<clause>`, plus `;edge=<v0>,<v1>` (pin), `;certificate=<k>;rail=<id>`, `;endpoint=<0|1>;kind=<T|R|I|TR>` or `;junction=<j>` as applicable.
     - Additive only.
  3. S:13097: copy the site into the failure.
  4. Test reporting only:
     - `require_produced` (TQ:426) prints ` product=<int> detail=<int|none> site=<site>`;
     - TQ:4980 streams the code and the site.
  5. A new suite `SurfaceCellFactoryRejectionSite`, outside every frozen selector, on `hard_rail_fixture()`:
     - positive control: the unmodified draft constructs;
     - negative: a one-face gauge +1 (mod 4) on a face that has an intra-region interior edge gives code 0 with the pin label and an edge incident to that face.
  6. GMP/GMPXX, eight targets, package with `runtimeExecution=false`. The CB record lists every label with its S line.
- **Out of scope:**
  - any change to a condition, an ordering or a code;
  - deleting or editing any existing line of `make`;
  - `RemeshPipeline.cpp`;
  - selectors, harnesses and fixtures;
  - every test oracle;
  - running anything.
- **Success evidence:**
  - the eight targets compile;
  - the package and source SHA-256 match;
  - the `make` diff is insertions only;
  - the label table is complete and unique.
- **On success:** `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE`.
- **On failure/blocker:** STOP if any label would require changing an existing line, or if the build fails. Record the evidence and return to Review.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB19-RP01-FACTORY-REJECTION-SITE` | CB, compile only; rejection-only site labels (RA-105.5). |
| 2 — conditional | `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE` | TB, artifact-only; the 22 identities, predictions and falsifiers of RA-105.6. Runs only after CB19 compiles. |
| 3 — mandatory | `M6-CP3-TB19-RP01-FACTORY-REJECTION-SITE-REV` | Review: rules on H-pin, on the `cp3entry:2/6` clause and on the RA-103.5 R-route falsifier, and orders the DEFN. |
| planned, not authorized | DEFN on the gauge-pin domain and the M1 binding owner → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as TB19-REV assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code+build** — CB19 rejection-only factory site labels (RA-105.5), GMP compile only, no runtime.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB18_REV_Factory_Rejection_Review_Decision.md` (RA-105); `src/geometry/SurfaceCellTracing.cpp` S:8439–9530 and S:13075–13103; `include/directional/geometry/SurfaceCellTracing.h` (`SurfacePhaseFrontProductError`, `SurfacePhaseFrontFailure`); TQ:426–445 and TQ:4934–4980; `LESSONS.md` §§5, 7.
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
