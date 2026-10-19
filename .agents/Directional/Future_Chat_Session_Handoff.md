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
| Currency | 2026-10-19, after TB16 immutable twelve-case harvest. One CB16 test-oracle falsifier; B3 progressed to later front 97/283 but remains RED. Independent Review required. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Latest semantic source is `1c45e89ae0ca7a072c5140aea2b95be6387ec078` (CB16). CB16 compile package `12154623660` (ZIP SHA-256 `821edfc6653af356c902d2debedc065a0ee6b51d287c27bdfd0679ef3a619956`), run `39176761903`; `runtimeExecution=false`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. The R3 baseline (403/497) is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`. |
| Latest candidate or rejected evidence | TB16 [run 39246335010](https://github.com/akashskypatel/Directional/actions/runs/39246335010), artifact `12183498229`: 6 PASS / 6 RED; test #3 falsifier candidate invalid mutation, B2 unchanged, B3 front 97/283. Full census still TB14A **425/497**. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; no production regression. Fixture debt covers 174, 191, 242, 442, 250 and the adjacent-sheet helper (RA-96.6 order). |
| Active boundary | `RP-01` (RA-87.3):<br>• B1 is cleared.<br>• B2 (R endpoint, 11 identities) is U4/U5 = CB17/CB18; its spec is re-derived from the TB16C census.<br>• B3 (19 identities, one template) is U6. CB15 measured a bound witness `1,4@1/5` on both sides, and CB16 makes the checkers use it.<br>`RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — independent TB16 Review + Plan; canonical ID UNKNOWN

- **Type:** independent Review + Plan; no implementation or test-source mutation during Review.
- **Authority:** RA-97.5 falsifier triggered by `ExactWitnessUnboundFailsClosedAndMixedKeepsLegacy` RED (ordinal 3 of TB16); Review turn identifier has not been assigned.
- **Immutable TB16 evidence:** [run 39246335010](https://github.com/akashskypatel/Directional/actions/runs/39246335010), artifact `12183498229`, ZIP SHA-256 `8a329317a610a014cb834947d841fac788ffa55813519dc5259c342a3b62dc32`; CB16 package `12154623660`, semantic source `1c45e89ae0ca7a072c5140aea2b95be6387ec078`.
- **Measured:** 12/12 selected, 6 PASS / 6 RED, immutable. Test #3's reverse `nextafter` becomes the other accepted orientation rounding. B2 ordinals 8/9 byte-match TB15 #5/6, with carrier-orientation as subcondition. B3 ordinals 10–12 leave front 17/203 and fail at front 97/283. No forbidden probe labels observed.
- **Review obligations:** adjudicate oracle validity without weakening requirements; distinguish subcondition from top-level predicate; classify the new B3 failure before specifying any correction or reauthorizing TB16C. Do not run TB16C, CB17 or later work in this turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` | Producer witness; no admission change. |
| done | `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` | 9/9 as predicted; witness `1,4@1/5`, bound on both sides. |
| done | `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER-REV` | RA-97: CB15 accepted; CB16 specified; RA-95.3's "p ≠ 1/5" withdrawn. |
| done | `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | Compile-only, GMP eight-target package; no runtime. |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | 12 identities, test #3 falsifier; Review required. |
| next (ID UNKNOWN) | independent TB16 Review + Plan | Adjudicate falsifier, reauthorize conditional path if justified. |
| 3 — conditional | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS` | Only if TB16 holds. Unchanged 497 harness; compared with TB14A. |
| 4 — conditional | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV` | Re-derives and issues the CB17 (U4) spec from the census. |
| planned, not authorized | CB17 → TB17 → CB18 → TB18 → fixture debt (242 → 174 → 250 → adjacent-sheet → 191 → 442) → census → RP-01 Review | Each CB follows a reviewed TB; a RED TB goes to Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — adjudicate TB16 test #3 oracle and B3 front 97/283 from immutable result artifact `12183498229` (run `39246335010`). RA-97.5 falsifier blocks TB16C pending Review.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-96/RA-97 (`Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`), `src/geometry/SurfaceCellTracing.cpp` S:60-182, S:8850-8862, S:19540-19560 and S:20110-20190, `include/directional/geometry/SurfaceCellTracing.h` H:90-96 and H:1555-1570, the three CB15 tests at the end of `tests/SurfaceCellsPhase10Tests.cpp`, `LESSONS.md` §3, §4 and §7, `TODO.md`.

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
