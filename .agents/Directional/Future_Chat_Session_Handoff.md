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
| Currency | 2026-10-18, after `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV` (RA-91) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `e88ac65ffcf87548138d1c56f2cc6ed4a3d8177b` (CB13A). Production code is unchanged since CB13 (`70217cc2`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, 403/497). The R3 baseline is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED); artifact `11661044443` expires 2026-10-24. |
| Latest candidate or rejected evidence | TB13C run `39127652521`, result `12136761296` on CB13A package `12132184878`: **420/497 PASS, 77 RED** (R3 403/497). Inventory `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`: B1 0, B2 11, B3 19, other 47. 25 R3 RED → PASS (now measured controls); **8 R3 PASS → RED**, CANDIDATE / NON-STABLE (RA-91.3). |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; 8 unattributed TB13C REDs held as candidates until TB13D-REV; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-87.3): B1 cleared (U3 closed); B2 R endpoint → U4/U5 (11 identities); B3 inexact I parameter → U6, DEFN first (19 identities). U4–U6 wait on the regression attribution (RA-91.4). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT` — EXACT NEXT

- **Type / owner:** `TB`, artifact-only measurement. The specification is RA-91.4–91.5 in `Architecture_M6_CP3_TB13C_Census_Review_Decision.md`.
- **Objective:** run the frozen 497 on four older retained packages, so Review can find when each of the 8 new REDs first appeared. No interpretation.
- **Time limit:** package P1 expires **2026-10-20T10:36Z**. Run it first.
- **Run:** the unchanged harness `.agents/Directional/tools/m6_cp3_entry_497_artifact_only_harness.sh` (SHA-256 `947a95ee4f684143a0f8d7c768a39253ab893d921da488802b45fb6ed58879dd`) with `--execute`.
  - Use one dispatch per package, in the order P1, P2, P3, P4. Each dispatch takes the five environment inputs below.
  - In `agent-dispatch-request.json`, keep `operation`, `harness_path` and `harness_sha256`. Set `turn_id` to this turn and `semantic_source_sha` to that package's source. Change `request_id`, `mailbox_key`, `artifact_prefix`, `executor_sha` and `environment` per dispatch.

  | Pkg | `CANDIDATE_ARTIFACT_ID` | `EXPECTED_SOURCE_SHA` | `EXPECTED_CANDIDATE_ZIP_SHA256` | `EXPECTED_ROOT_MANIFEST_SHA256` | `EXPECTED_SOURCE_ARCHIVE_SHA256` |
  |---|---|---|---|---|---|
  | P1 | `11805220540` | `007585f8eac57a74e89e62a416a844e21c15fe35` | `e564eed3ea3636f1b36262dc91c29e9a65af6c229efc74e58d7935da0c07ddca` | `9da84df9cbae6152aaa06302f8a849a91bf538d29250a2959bc5be1ca63d706e` | `6519c6d4a886d09bdb915de5de0d94b7cf1edc58bfae430c521b9dea2ea19b1d` |
  | P2 | `11939982141` | `953f812ff1f431e3ad3af3b68a92284a7831c94a` | `2d5d1fc3f75b573307cae8af3c837da3dde2302ffdb4fe0ef3dd34d2aafeed7a` | `6c5938b9bc19377041649ce0546b86b2e6c6e2c9d6969fe01639da7baf4af203` | `3d0bf938f0bf2828ef407ceeb092254b003682336c97e83f88867efa2c3c38e9` |
  | P3 | `12121016836` | `9432aa05ef4719cbea912ae0feb2c5508c4e497a` | `e92158729bf4cfc13432678e8a05cffba4d922feca6e902d8154a535ab1f2676` | `2c00fd10667fab2ba54c00b358281e892676cfd05186fa60d45b4fc8c75ee488` | `ed45af9cbba9a07a568f7291bb13663aebed5f333574966633fe9deb08abc64b` |
  | P4 | `12125223513` | `b1b02d5bed43898af0708d76dcd70ada96aeecc9` | `c98ed3a509e9d1ccc1df83eaeb6112b8636bc0e7ee63b73140d789c32f38eeb6` | `6f90d5ffbdd4e4dbe1f9c5f8b010666e67a59b49abb0eff71020eef4f06782e0` | `3b131c687171ad336fc1dedb390e358ee5ce081da9107f828f54f4e97b1bffb0` |

- **Failures:** each package run is independent. If one fails orchestration, record it; rule 5 applies to that run only, and the next package still runs.
- **Deliver** a report of 25 lines or fewer. For each package, give:
  - the run ID, result artifact ID and ZIP SHA-256;
  - `orchestration_failure`;
  - totals per phase;
  - PASS or RED for selector ordinals 174, 191, 235, 236, 242, 294, 299 and 442.
- **Predictions:** 242 is RED at all four; the 30 B2/B3 identities are RED at all four. **Falsifier:** 242 PASS at any package → Review.
- **Out of scope:**
  - compile, relink and benchmarks;
  - any source, test, fixture, selector or harness change;
  - rerunning CB13A;
  - classification, interpretation, ledger changes or promotion.
- **On completion (any totals):** `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT-REV`. **On failure/blocker:** `UNKNOWN — STOP`. If all four runs fail orchestration, follow `Turn_Cadence.md` rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` | 420/497; closed out by Review (RA-91.1). |
| 1 — next | `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT` | Artifact-only bisect over P1–P4 (above). P1 expires 2026-10-20T10:36Z. |
| 2 — conditional | `M6-CP3-TB13D-R10-RETAINED-PACKAGE-BISECT-REV` | Review: attributes the 8 new REDs; specifies narrow repair turns (the curved-disk factory regression; the 242 test-spec repair); then orders U4/U5/U6 (B3 owns 19, B2 owns 11) and issues DEFN-U6. |

A RED TB goes to Review (rule 4); orchestration failures follow rule 5. Anything beyond step 2 is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — artifact-only bisect (TB13D): the unchanged 497 harness on four retained packages, P1 first; do not compile or modify source, tests, fixtures, selectors or harnesses.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB13C_Census_Review_Decision.md` (RA-91) and `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`, `Architecture_M6_CP3_TB13_Chain_Interval_Review_Decision.md` (RA-88–RA-90), `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (the R3 baseline), `Architecture_M6_Frozen_Definitions.md` RA-87–RA-91.
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
