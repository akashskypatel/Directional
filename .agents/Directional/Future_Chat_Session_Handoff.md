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
| Currency | 2026-10-18, after `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE-REV` (RA-93): CB14A accepted, and TB14A predictions sharpened. TB14A is next. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. CB14A semantic source `2ee499a3403c07be05e8084a669f30c1c735f04a` (test-only); production code unchanged since CB13 (`70217cc2`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, 403/497). The R3 baseline is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED); artifact `11661044443` expires 2026-10-24. |
| Latest candidate or rejected evidence | TB13C census on CB13A: **420/497** (`12136761296`; inventory `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`). TB13D bisect: P1 (+32) 422/497 (`12138931233`); P4 (CB12) 420/497 (`12138633102`), identical to CB13A. The 8 identities that passed at R3 and fail now are all test debt (RA-92.3). CB14A package `12140756646` was re-verified by Review (RA-93.1); it has not run yet. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected. There is no new production regression. Curved disk ×4 is now a compiled, unexecuted CB14A control; remaining test debt includes 174, the 191 family, 242, 442, 250 (a provenance-free composite) and the adjacent-sheet curved-disk helper (RA-93.3), all scheduled later. See `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-87.3): B1 cleared (U3 closed); B2 R endpoint → U4/U5 (11 identities); B3 inexact I parameter → U6, DEFN first (19 identities). The hold on U4–U6 is discharged (RA-92.5); curved-disk `make` control is now compiled but not yet measured (TB14A next). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS` — EXACT NEXT

- **Type / owner:** artifact-only Test + Benchmark. The CB14A GMP eight-target package has been verified; no recompilation, relinking, regeneration, code edits, fixture edits, or selector changes.
- **Immutable package:** workflow [39138385869](https://github.com/akashskypatel/Directional/actions/runs/39138385869), artifact `12140756646`. Exact compiled source `2ee499a3403c07be05e8084a669f30c1c735f04a`; outer ZIP SHA-256 `eee92aeb38ce098c8580a199f340ec65f3bf650df6464d5a3f2b7dfee5add906`, root manifest SHA-256 `495cf0b54322e54aee1020802d8f6f4a65297fdfe519cf0871509a70f74bb2d1`, source archive SHA-256 `f414dce2543edfbfd44e528b739edb0685172719f010680ffd4659da0ad945a2`.
- **Preflight:** 28/28 packaged checksums; eight targets compiled, configure/preflight and build 0/0; five empty statuses; `DIRECTIONAL_ENABLE_GMP=ON` and actual GMPXX/GMP link; `exactArithmeticBackend=GMP`; `runtimeExecution=false`. CB record: `.agents/Directional/Architecture_M6_CP3_CB14A_Curved_Disk_Rail_Provenance_Code_Build_Record_20261018.md`.
- **Execution:** dispatch the unchanged census harness `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd` with `--execute`, on this exact artifact. Extract packaged executables preserving executable mode bits; never chmod/repair package.
  - The harness inputs are `CANDIDATE_ARTIFACT_ID=12140756646`, `EXPECTED_SOURCE_SHA`, `EXPECTED_CANDIDATE_ZIP_SHA256`, `EXPECTED_ROOT_MANIFEST_SHA256` and `EXPECTED_SOURCE_ARCHIVE_SHA256`, with the values above. The dispatch file carries every field TB13C used, including `turn_id` and `semantic_source_sha`.
  - Make exactly one dispatch. Wait for the run to finish, then download and verify the result.
  - The turn is not complete until the report is committed. TB13C and TB13D stopped after dispatching; do not repeat that.
- **Predictions / falsifiers (RA-93.4, replacing RA-92.7):**
  - 235/236/294/299 PASS;
  - 237/253/254 PASS (a RED means a base-fixture guard threw at P10:2531/2541/2552);
  - 199 stays RED with its first failure moved off P10:5395 (expected at P10:5428). Still at 5395 alongside a 236 PASS is a falsifier;
  - 250 unchanged: RED at P10:3597, `PublishedProductRejected`;
  - every other identity keeps its TB13C status.

  Any other divergence goes to Review; no synthetic acceptance.
- **Deliver:** a TB report of 25 lines or fewer: run, immutable result, ZIP digest, per-phase totals, the status of the 9 named identities with first-failure line and reason for each RED, and every other divergence from TB13C. On semantic RED, independent Review + Plan; orchestration failure uses Turn Cadence rule 5.
- **Conditional successor:** `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV`. Nothing beyond it is authorized.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE` | Test-only source `2ee499a3403c`; verified GMP compile-only package `12140756646`. |
| done | `M6-CP3-CB14A-R10-CURVED-DISK-RAIL-PROVENANCE-REV` | RA-93: CB14A accepted; derived-fixture finding; TB14A predictions sharpened. |
| 1 — next | `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS` | Artifact-only unchanged selector-497 census, one dispatch (RA-92.7, with predictions from RA-93.4). |
| 2 — conditional | `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV` | Review adjudicates TB14A, issues DEFN-U6, sets U4/U5 order, schedules fixture debt (174, 191 family, 242, 442, 250, adjacent-sheet helper). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — execute unchanged selector-497 census on the verified immutable CB14A package; no compile, code, fixture, selector or recovery mutation.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-92 decision `Architecture_M6_CP3_TB13D_Bisect_Review_Decision.md` (RA-93 is appended there), the CB14A build record, `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv` and its owning Review, `Regression_Root_Cause_Tracker.md`, `TODO.md`. Use `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh` at hash above.

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
