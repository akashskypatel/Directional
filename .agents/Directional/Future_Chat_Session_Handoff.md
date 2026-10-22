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
| Currency | 2026-10-22, CB27-REV independently rejected the fourth A7 negative oracle: copying the second binding also collapses opposite-side orientation, so the test remains green when wedge membership is removed. Three other negatives are statically discriminating, not runtime verified. Same-side omitted for the D7 witness. CB27A test-only correction must precede CB28 and TB29; RA-134 RED partition and TB28 462/497 candidate retained. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`; PR #8 draft/open. Exact CB27 test-only source **`175c70e44d2c162d72812c842149f30c53c1fa25`**, compiled package `12443015113` (CB26 semantic base `e3d60337ed34538547d3a6d519bafae5b184330e`); later control/document/tooling commits do not replace semantic source. Refresh current branch HEAD before mutation. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, semantic `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 **403/497** rejected. |
| Latest candidate evidence | RA-133-reviewed TB28 [run 39772864202](https://github.com/akashskypatel/Directional/actions/runs/39772864202), result artifact **`12424484672`**, ZIP SHA-256 `a54110dbb5475b76e6b6a6baa8fc1b7dcabd7aa50c95c5b390532509d1c656e6`; 1019/1019 manifest, 497/497 executed, **462 PASS/35 RED**, 13 RED→PASS and no PASS→RED vs TB21 449/48. Owning report `Architecture_M6_CP3_TB28_Selector_497_Census_Report_20261022.md`; TSV inventory and full ledger. **Not promoted.** |
| Regression accounting and debt | **66 events / 17 categories / 49 recurrences**, witness debt **1**, selector **497 frozen**, TB28 candidate 462/497, RP-01 OPEN. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. The seam family (12) and `selector:447` PASS at TB28. **35 REDs by first failing component (RA-134.2):**<br>- checked phase-front factory: 17 (13 silent: `focused30:3, 22, 23`; `selector:139, 140, 142, 220, 221, 296, 302, 304, 439`; `cp3entry:4`. 4 with the wrong code: `selector:211, 219, 227, 230`);<br>- A3 atlas: 8 (`selector:189–195` silent, `selector:442`);<br>- A5: `focused30:12`;<br>- producer disposition or oracle: 7 (`selector:174, 201, 204, 242, 247, 250, 405`);<br>- witness absence: `cp3entry:1` (D2), `cp3entry:2`.<br>CB27 four negatives compiled, but CB27-REV rejected the outside-wedge oracle as non-discriminating; CB27A and independent review required before runtime verification. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION` — EXACT NEXT

- **Type / owner:** Code + Build; `tests/SurfaceCellTransitionQuotientTests.cpp` only. Authorized by CB27-REV (Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md); no product, other-test, selector, fixture, benchmark or workflow change.
- **Objective:** replace the outside-wedge negative with a source-produced D7 binding that keeps both certificate sides opposite and first endpoint face/sheet unchanged while violating first-wedge membership alone. Demonstrate the counterfactual: removing only wedge membership would admit this tamper. If no valid D7 binding exists, STOP and report the missing witness rather than synthesizing invalid source authority.
- **Verification:** binding-specific preconditions, A5 republish success, original A6 forest, A7 exact rejection path, and independent evidence of non-vacuity. Retain the three other negative tests and D3/D7 controls. Eight-target GMP/GMPXX compile only, `runtimeExecution=false`.
- **On success:** independent CB27A-REV must adjudicate before CB28. CB28 diagnostics and TB29 remain conditional, not started.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|
| 1 — next | `M6-CP3-CB27A-RP01-A7-WEDGE-MEMBERSHIP-ORACLE-CORRECTION` | Correct only the A7 wedge-membership negative and compile/package, no runtime. STOP if no legitimate D7 mutation can isolate the predicate. |
| later — conditional | CB27A-REV → CB28 → CB28-REV → TB29 → TB29-REV | CB27A-REV decides whether the correction is a valid oracle; CB28 message-only work only after acceptance. |
| later — UNKNOWN until assigned | DEFN-M1 → DEFN-M1-REV → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review; `DEFN-SEAM-NZ` and Periodic after witnesses; `DIAG-RETAIN` deferred | Planned; do not start without review-authorized next edge. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — test-only CB27A wedge membership correction; compile-only, no runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Review_Decision_20261022.md` (binding successor and falsifiers), `Architecture_M6_CP3_CB27_A7_Certified_Seam_Negative_Oracles_Code_Build_Record_20261022.md` (exact compile authority), and `Architecture_M6_CP3_TB28_Census_Review_Audit_Decision_20261022.md` (RA-134: CB28 scope); TQ:4065–4286 and RP:3855–3925, 7587–7619.
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
