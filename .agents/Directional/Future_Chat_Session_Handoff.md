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
| Currency | 2026-10-18, after `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT-REV` (RA-92) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b` (CB13A). Production code is unchanged since CB13 (`70217cc2`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, 403/497). The R3 baseline is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED); artifact `11661044443` expires 2026-10-24. |
| Latest candidate or rejected evidence | TB13C census on CB13A: **420/497** (`12136761296`; inventory `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`). TB13D bisect: P1 (+32) 422/497 (`12138931233`); P4 (CB12) 420/497 (`12138633102`), identical to CB13A. The 8 identities that passed at R3 and fail now are all test debt (RA-92.3). |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected. There is no new production regression. Eight test-debt items remain: curved disk ×4 (repair CB14A); 174, the 191 family, 242 and 442 (scheduled later). See `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-87.3): B1 cleared (U3 closed); B2 R endpoint → U4/U5 (11 identities); B3 inexact I parameter → U6, DEFN first (19 identities). The hold on U4–U6 is discharged (RA-92.5); the curved-disk `make` control is restored first. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE` — EXACT NEXT

- **Type / owner:** `CB`, test-only Code + Build. Compile only; no runtime. The specification is RA-92.6 in `Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md`.
- **Objective:** restore the curved disk as a control of `make` accepting a hard-feature product. Its fixture predates the provenance contract of `c7cb5d68b`/`715fe2d66` (S:8479-8483, S:8529-8534).
- **Change** (`tests/SurfaceCellsPhase10Tests.cpp` only):
  1. **Rails.** In `make_curved_disk_fixture` (P10:2438), build the rails for the 8 boundary hard edges with `pipeline::build_authoritative_surface_cell_rails(TriMesh, AdaptiveFeatureMap)`. The precedent is REPackage:184-212.
     - Each feature edge carries its actual single incident face. Use one closed curve over the 8 edges.
     - The edge class follows the boundary positive in `RailBuildRejectionCarriesFailureWithoutConsumableRails`; record the choice.
  2. **Provenance.** Set `options.authoritativeRails`, `hardRailTerminalContacts`, `hardRailClosedChains` and `hardRailOpenChains` from `pipeline::hard_rail_source_provenance_from_rails(rails, vertexCount)`.
     - Throw if the build is not `Produced`, the provenance is empty, or the union of rail edges is not exactly the 8 boundary edges.
     - Hand-built chains, contacts or edge lists are not allowed. The `reverseFaceRows` variant follows the same procedure.
  3. **Diagnostics.** Using one small helper, the first `ASSERT_EQ(Produced, …)` in 235, 236, 294 and 299 prints the rejection-reason name, plus `publishedProductError` and `publishedProductSourceAuthorityDetail` as integers when present.
- **Out of scope:**
  - any assertion or production change;
  - other fixtures, including the 174, 191, 242 and 442 debt;
  - selector or harness changes;
  - running tests.
- **Build:** GMP/GMPXX compile and package of all eight targets, as for CB13A. Record the package ID, ZIP SHA-256, root-manifest SHA-256, source-archive SHA-256 and source SHA, with `runtimeExecution=false`. These five values become TB14A's inputs. The CB record is 25 lines or fewer.
- **On completion:** `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS`. **On failure/blocker:** `UNKNOWN — STOP`; a compile failure follows `Turn_Cadence.md`.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT` | P1 and P4 measured; P2 and P3 cancelled while pending; closed out by Review (RA-92.1). |
| 1 — next | `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE` | Test-only CB (above). |
| 2 — conditional | `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS` | The unchanged census harness `947a95ee…`, one dispatch, `--execute`, on the CB14A package (RA-92.7). Predictions: 235/236/294/299 PASS; every other identity keeps its TB13C status except 199/250, which are observed only. Report of 25 lines or fewer. |
| 3 — conditional | `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV` | Review: adjudicates TB14A, issues DEFN-U6, sets the U4/U5 order, and schedules the 174, 191, 242 and 442 test-debt repairs. |

A RED TB goes to Review (rule 4); orchestration failures follow rule 5. A turn that dispatches several runs waits for each one to start before pushing the next, because the dispatcher holds one pending run. Anything beyond step 3 is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — test-only CB14A: bind `make_curved_disk_fixture` to producer-built rail provenance and print the typed factory code; compile and package only, with no production, assertion, selector or harness change.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md` (RA-92), `Architecture_M6_CP3_TB13C_Census_Review_Decision.md` (RA-91) and its inventory TSV, `tests/SurfaceCellsPhase10Tests.cpp` (P10:2438-2560 curved-disk fixture; 3276-3380 tests), `tests/SurfaceCellREPackageTests.cpp:184-212` (rail-provenance precedent), `Architecture_M6_Frozen_Definitions.md` RA-87–RA-92.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats. History gates (`authority|boundary|ledgers`, drift `--base`) are Review gates (RA-82.3); implementation turns run `document_drift_audit.py --root .` only.

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
