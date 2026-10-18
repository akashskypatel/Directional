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
| Currency | 2026-10-18, after `M6-CP3-TB12-R10-HARNESS-AUTHORITY-REV` (RA-86) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `b1b02d5bed43898af0708d76dcd70ada96aeecc9` (CB12). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. |
| Latest candidate or rejected evidence | CB12 package `12125223513` (run `39097975393`, ZIP SHA-256 `c98ed3a509e9d1ccc1df83eaeb6112b8636bc0e7ee63b73140d789c32f38eeb6`), verified by RA-86.2; tests not yet run. TB11 run `39092477302`: truth table PASS, two midline tests RED at `open-rail-route-anchor`, front 29/147 (RP-01, not a regression, RA-85.2). |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01`: on subdivided open rails, the R endpoint (vertex 4) and I–I middle fronts. U2 (CB12) is compiled and verified; TB12 measures it. U3–U5 frozen (RA-85.5), and U3 carries the RA-86.5 constraints. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` — EXACT NEXT

- **Type / owner:** `TB`, artifact-only, on the immutable CB12 package. It restarts the blocked attempt; nothing from that attempt was dispatched.
- **Objective:** measure U2 (gate) and record four RP-01 diagnostics against the RA-86.4 predictions.
- **Read before work:** RA-86 record; CB12 record; TB11 report and harness `.agents/Directional/tools/m6_cp3_r10_open_rail_route_anchor_harness.sh` (`763dee35a`).
- **In scope:**
  1. Add one new file, `.agents/Directional/tools/m6_cp3_r10_open_rail_chain_provenance_harness.sh`, derived from the TB11 harness. Only the deltas RA-86.1 allows: sha `b1b02d5bed43898af0708d76dcd70ada96aeecc9`, artifact `12125223513`, digest `c98ed3a509e9d1ccc1df83eaeb6112b8636bc0e7ee63b73140d789c32f38eeb6`, the six RA-86.4 identities in order, `TB12_` tags, and the ledger columns `role` and `first_failure`. Commit it alone and record its SHA-256 and the executor commit.
  2. Dispatch `test_benchmark` with that harness. Run one fresh process per identity, with no rebuild, relink, benchmark or selector run.
  3. Write a TB12 report of 40 lines or fewer. For each identity give the verdict and `first_failure`, and compare it with its RA-86.4 prediction. Compare #3 and #4 byte for byte with TB11's predicate. For #5 and #6, state whether `firstPredicate=` is present.
- **Out of scope:** product, test, workflow or existing-harness changes; selector 497; reinterpreting outcomes; any CB13 work.
- **Success evidence:** result artifact ID and ZIP SHA-256; 6 selected, 0 missing; immutability postflight; the ledger; the prediction comparison.
- **On any measured outcome:** `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV`, a Review that adjudicates the predictions and issues the CB13 specification. Orchestration failure: `Turn_Cadence.md` rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | Artifact-only; one new harness (RA-86.1); six identities (RA-86.4). |
| 2 — conditional | `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV` | Review after any measured TB12 outcome. It issues the CB13 specification under the RA-85.4 rule and the RA-86.5 constraints. |

Then U3 `CB13`/`TB13` → U4 `CB14`/`TB14` → U5 `CB15`/`TB15` (RA-85.5), each after a reviewed predecessor TB; anything beyond is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — consume the immutable CB12 package; author only the RA-86.1 harness; no rebuild or code edits.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB12_Harness_Authority_Review_Decision.md` (RA-86), `Architecture_M6_CP3_CB12_R10_Open_Rail_Chain_Provenance_Code_Build_Record_20261018.md`, `Architecture_M6_CP3_TB11_Open_Rail_Route_Anchor_Harvest_Report_20261018.md`, `Architecture_M6_Frozen_Definitions.md` RA-85/RA-86.
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
