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
| Currency | 2026-10-18, after `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE-REV` (RA-87) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `b1b02d5bed43898af0708d76dcd70ada96aeecc9` (CB12). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. Frozen selector last measured at R3 (source `d82e34427`, result `11661044443`, 403/497). |
| Latest candidate or rejected evidence | TB12 run `39103358061`, result `12127706461`, on CB12 package `12125223513`: gates 2/2 PASS (U2 closed); the 4 RP-01 diagnostics are RED as predicted. `cp3entry:2/6` first fail at B3 (`endpoint-1`, front 17/203, face-0 sum 1 + 2⁻⁵⁵), RA-87.2. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` has three blocker shapes (RA-87.3): B1 I–I anchor → U3 (CB13, authorized); B2 R endpoint → U4/U5; B3 inexact I parameter → U6 (DEFN first). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` — EXACT NEXT

- **Type / owner:** `CB` (compile only); unit U3. The specification is RA-87.4 and is binding item by item.
- **Objective:** replace the open-rail terminal anchor with the open-chain interval rule (RA-85.4) in both checkers, make chains mandatory, and carry the real chains through every hand-built input.
- **Read before work:** RA-87 record; RA-85.4; the CB12 record; S:8150-8190 (helper), S:8262-8300 (entry validator), S:8667-8679 and the closed-chain interval at S:8679-8716 (template), S:8764-8765, S:20296-20316; P10:6380-6440; TQ:1775-1862.
- **In scope:** RA-87.4 items 1–7, exactly:
  1. the helper `open_rail_route_interval_valid`, and deletion of `open_rail_route_anchor_valid`;
  2. the factory call;
  3. the consumer call with predicate `open-rail-chain-interval`;
  4. no empty-map exemption;
  5. the I-branch comment;
  6. real chains in every hand-built input with contacts;
  7. the new truth table and the flipped CB12 expectation.

  Then GMP/GMPXX compile and package.
- **Out of scope:** R or I admission (U4–U6); endpoint predicates; probes; tolerance; selector, harness or workflow changes; running tests.
- **Success evidence:** compile green; package ID, ZIP SHA-256 and source SHA recorded; `runtimeExecution=false`; a list of every direct `make` call site and how it now receives chains; a CB13 record of 40 lines or fewer.
- **On success:** `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` (RA-87.5).
- **On failure/blocker:** `UNKNOWN — STOP`; orchestration failures follow `Turn_Cadence.md` rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` | U3, compile only (RA-87.4). |
| 2 — conditional | `M6-CP3-TB13-R10-OPEN-RAIL-CHAIN-INTERVAL-ROUTE` | After CB13 is packaged. Six identities (RA-87.5): two gates; the P10 midline tests predicted to move past front 29/147 to B2; `cp3entry:2/6` byte-identical to TB12. |
| 3 — conditional | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS` | Same CB13 package; the unchanged 497 harness; the first failure of every RED classified as B1/B2/B3/other; identities that passed at R3 and are now RED listed. No interpretation. |
| 4 — conditional | `M6-CP3-TB13C-R10-SELECTOR-497-CENSUS-REV` | Review of TB13 and TB13C. It orders U4/U5/U6 and issues the DEFN for U6 (the exact I-endpoint parameter). |

Orchestration failures follow rule 5. Anything beyond step 4 is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — use the turn-based-coding-agent Code + Build guidance; no runtime execution.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md` (RA-87), `Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md` (RA-85.4), `Architecture_M6_CP3_CB12_R10_Open_Rail_Chain_Provenance_Code_Build_Record_20261018.md`, `Architecture_M6_Frozen_Definitions.md` RA-85/RA-87, `GMP_COMPILE_POLICY.md`.
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
