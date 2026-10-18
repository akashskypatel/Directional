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
| Currency | 2026-10-18, after compiled CB12 (RA-85.5 U2); TB12 artifact-only next |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `b1b02d5bed43898af0708d76dcd70ada96aeecc9` (CB12). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. |
| Latest candidate or rejected evidence | TB11 run `39092477302`, result `12123605663`, on CB11 package `12121016836`: truth table PASS; two midline-fixture tests RED at `open-rail-route-anchor`, front 29/147. The fixture has never been `Produced`; **not a regression** (RA-85.2). Not promoted. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01`: two blockers on subdivided open rails, the R endpoint (vertex 4) and I–I middle fronts. U2 (ordered open source-chain provenance) is compiled; U3–U5 remain frozen until their reviewed predecessor TB. RA-85.4 specifies an open-chain interval route rule, not yet implemented. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` — EXACT NEXT

- **Type / owner:** `TB` artifact-only, RA-85.5 U2 verification. No code, rebuild, relink, fixture mutation, or implementation changes.
- **Objective:** independently run CB12's open-chain provenance contract tests and retained TB11 route-anchor tests on the immutable CB12 compile package. Report every observed outcome; CB12 did not run these tests.
- **Read before work:** `.agents/Directional/Architecture_M6_CP3_CB12_R10_Open_Rail_Chain_Provenance_Code_Build_Record_20261018.md`, RA-85 Review, RA-84 clauses, TB11 report and applicable frozen gates; immutable compile run `39097975393` / package `12125223513`.
- **In scope:** verify exact compiled semantic source `b1b02d5bed43898af0708d76dcd70ada96aeecc9`, package hashes/GMP/GMPXX, execute each authorized identity in a fresh process from the immutable package without rebuilding, and record both new contract behavior and the three TB11 tests. Red outcomes are independent evidence for Review, never repaired within TB.
- **Out of scope:** admission-rule implementation (U3–U5), changing production code, test expectations, harnesses, selector 497, baseline, artifacts or accepted semantic ledgers without an independent Review.
- **Success evidence:** immutable artifact identity, selected test counts, per-identity outcomes and source-authority receipts; report whether TB11's prior route-anchor locus is unchanged as predicted. Code + Build compilation alone is not acceptance.
- **On success:** the formally authorized successor of a green TB, if established by the applicable approved plan; otherwise `UNKNOWN — STOP` pending authoritative determination.
- **On semantic red:** `UNKNOWN — STOP`, mandatory independent Review + Plan; no speculative CB13.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | Artifact-only immutable CB12 verification. |
| 2 — conditional | `UNKNOWN` | Review if semantic RED; any later U3/CB13 implementation requires reviewed TB12 authority. |

U3–U5 (`CB13`–`CB15`, each followed by its TB) are frozen in RA-85.5; nothing beyond TB12 is initiated in this turn.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — consume the immutable compiled package; no rebuild or code edits.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_CB12_R10_Open_Rail_Chain_Provenance_Code_Build_Record_20261018.md`, `Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md` (RA-85), `Architecture_M6_Frozen_Definitions.md`, `GMP_COMPILE_POLICY.md`.
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
