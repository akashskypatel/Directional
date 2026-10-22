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
| Currency | 2026-10-22, after the CB28 review (RA-136). CB28 is accepted as message-only and covers 18 of the 21 silent REDs. It missed the asserts of `focused30:12` (A5) and `focused30:22/23`, the M1 frozen-precedence tests, because RA-134.5 cited stale line numbers without test names. CB28A adds those three messages, by test name, before TB29. CB27A (wedge withdrawal) was spot-checked against RA-135. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/open. Exact CB28 test-only source **`19aeb3e60e2d762006d95dc4a5007af54f094ee7`**, compile package `12460974720` (run `39861294132`); historical CB27A source `f021e8f7b876c261b8337334596f519f4b7652a7` and package `12452346647` remain reviewed prior evidence. Refresh current branch HEAD before mutation. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, semantic `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 **403/497** rejected. |
| Latest candidate evidence | RA-133-reviewed TB28 [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result artifact **`12424484672`**, ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`; 1019/1019 manifest, 497/497 executed, **462 PASS/35 RED**, 13 RED→PASS and no PASS→RED vs TB21 449/48. Owning report `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md`; TSV inventory and full ledger. **Not promoted.** |
| Regression accounting and debt | **66 events / 17 categories / 49 recurrences**, witness debt **1**, selector **497 frozen**, TB28 candidate 462/497, RP-01 OPEN. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. The seam family (12) and `selector:447` PASS at TB28. **35 REDs by first failing component (RA-134.2):**<br>- checked phase-front factory: 17 (13 silent: `focused30:3, 22, 23`; `selector:139, 140, 142, 220, 221, 296, 302, 304, 439`; `cp3entry:4`. 4 with the wrong code: `selector:211, 219, 227, 230`);<br>- A3 atlas: 8 (`selector:189–195` silent, `selector:442`);<br>- A5: `focused30:12`;<br>- producer disposition or oracle: 7 (`selector:174, 201, 204, 242, 247, 250, 405`);<br>- witness absence: `cp3entry:1` (D2), `cp3entry:2`.<br>CB27A-REV accepted the static oracle; CB28 adds diagnostic text only, pending independent Review before TB29. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS` — EXACT NEXT

- **Type / owner:** Code + Build, test-only, compile only; implementation agent. Authority: RA-136.3 (`Architecture_M6_CP3_CB28_Factory_Error_Diagnostics_Review_Decision_20261022.md`), completing RA-134.5 (`Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md`).
- **Objective:** make the last three silent RED rows report their typed rejection, so TB29 measures every M1 precedence row.
- **Read before work:** RA-136 (all); RA-134.5; the CB28 diff `19aeb3e60` (formatter and guarded pattern at TQ:3948).
- **In scope** (`tests/SurfaceCellTransitionQuotientTests.cpp` only). Locate each assert **by test name**; line numbers are advisory:
  1. `M6CP1.RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant` (`focused30:12`): `ASSERT_NE(relabelledA5, nullptr)` (about TQ:5525) streams `a5_rejection_message(relabelledA5Construction)`.
  2. `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames` (`focused30:22`): `ASSERT_NE(front, nullptr)` (about TQ:6309) streams `describe_phase_front_product_error` of `construction`'s error alternative, using the guarded `get_if` pattern.
  3. `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport` (`focused30:23`): the same at its `ASSERT_NE(front, nullptr)` (about TQ:6350).
- **Out of scope:** any other assert, test or file; production code; selectors, workflows; runtime.
- **Success evidence:**
  - a message-only diff at exactly three asserts;
  - eight targets compile with GMP/GMPXX, `runtimeExecution=false`;
  - record `Architecture_M6_CP3_CB28A_M1_Precedence_Assert_Diagnostics_Code_Build_Record_20261022.md` (at most 20 lines) with the package id and hashes;
  - STATUS is COMPLETE.
- **On success:** `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS-REV` (Review, mandatory): static check; issues TB29 (RA-136.4).
- **On failure/blocker:** STOP and return to Review on a compile error, or if an assert cannot be found by test name.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS` | Code + Build, test-only, compile only (RA-136.3): three assert messages, located by test name. |
| 2 — conditional | `M6-CP3-CB28A-RP01-M1-PRECEDENCE-ASSERT-DIAGNOSTICS-REV` | Review, only after step 1 completes: static check; issues TB29 (RA-136.4). |
| later — UNKNOWN until assigned | TB29 (targeted artifact-only harness on the CB28A package: 4 A7 negatives + D3/D7 + 3 A7 guards + all 35 TB28 REDs; typed-reason attribution table; RA-136.4) → TB29-REV → DEFN-M1 (scoped from measured factory clauses) → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up (RA-130.7) only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB28A: three test-only assert messages for `focused30:12/22/23` (RA-136.3); compile only, no runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_CB28_Factory_Error_Diagnostics_Review_Decision_20261022.md` (RA-136: CB28 accepted, 18/21 covered, three asserts missed, TB29 scope); `Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md` §RA-134.5; CB28 diff `19aeb3e60`.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats.

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
