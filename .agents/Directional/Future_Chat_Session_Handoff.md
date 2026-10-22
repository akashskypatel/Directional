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
| Currency | 2026-10-22, after TB27 corrected artifact-only verification: 21/21 targeted PASS with immutable package, **not yet independently reviewed or promoted**. The independent TB27 Review is the sole required next task; its canonical ID is not yet assigned. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; CB26 semantic source `e3d60337ed34538547d3a6d519bafae5b184330e` (compile GREEN), later STATUS/control-plane commits are not semantic evidence; refetch HEAD before mutation. CB25 semantic source `c5e0b242f3c3015f1f4f5f886058f0086fe1f679` (compile GREEN); CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Later non-documentation commits are GUI, build and README tooling only (A2a network display `bf518b003`, record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`; macOS GUI configure; Windows static libraries and `/bigobj`; GUI text wrapping; GUI SurfaceCells diagnostics and field streamlines, with two fixes to the legacy streamline tracer `src/geometry/Streamlines.*`, which SurfaceCells does not use; see CHANGELOG). CB25 changes only RP A5 shared-node predicates relative to `dae267a82`; no other RP-01 source file changed, and Linux CI compile behavior is unchanged. Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | Compliant TB27 [run 39764327506](https://github.com/akashskypatel/Directional/actions/runs/39764327506), result `12420676412` (ZIP SHA-256 `33dc0878cd4dd0592b1ad2ae0b436b2606c7a59e45cbc0e929358d6213f7babb`), source `e3d60337ed34538547d3a6d519bafae5b184330e`, CB26 GMP package `12409939859`: **21/21 PASS**, 24/24 result hashes, immutable postflight. Original run `39761406833` also 21/21 but noncompliant extract+chmod, diagnostic only. Evidence owner: `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Report_20261022.md`. **Candidate only; independent Review pending.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` still OPEN; TB27's targeted A5/D3/D7 seam suite (21) is GREEN; no selector-497/full-suite/Periodic/nonzero-turn seam promotion. Independent Review must audit validity, candidate accounting and pending CB27 negative-test debt. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — UNKNOWN — independent TB27 Review required (STOP until canonical ID assigned)

- **Type / owner:** independent Review of `M6-CP3-TB27-RP01-A7-CERTIFIED-SEAM-CROSS-SHEET-VERIFICATION`, the only required next task from RA-131/RA-130.9. Repository authority describes TB27-REV but has not assigned its canonical turn ID. **Do not invent one or begin conditional CB27.**
- **Read before work:** `Architecture_M6_CP3_CB26_A7_Certified_Seam_Cross_Sheet_Authority_Review_Decision_20261022.md`; `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Report_20261022.md`; RA-130 B1–B6; `Regression_Root_Cause_Tracker.md`; the exact 21-log immutable result artifact.
- **Scope:** independently inspect result artifact `12420676412` from [run 39764327506](https://github.com/akashskypatel/Directional/actions/runs/39764327506) and correct harness at `60414d738`; verify 21 unique fresh RUN/OK, raw oracle non-vacuity, D3/D7 tamper and A7 negative guards, frozen controls, GMP, package immutability, no source/build/relink/selector mutation. Decide only what targeted improvement supports. Original run `39761406833` is diagnostic due to invalid archive mode handling.
- **Out of scope:** new production/test/fixture/selector code; compile, benchmarks, full-497 gate, unapproved new witnesses; promotion or stable-count modification without independent evidence/Review authorization.
- **Success evidence:** written independent review disposition and candidate-accounting decision, exact artifact/commit verification; authoritative next conditional edge to CB27 only if explicitly assigned by Review.
- **On success/failure:** follow Review's frozen decision. Until it assigns canonical ID and next action, `UNKNOWN — STOP`.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `UNKNOWN` (required TB27-REV) | Independent Review of compliant TB27 green targeted evidence; canonical ID not yet assigned. |
| 2 — conditional | `UNKNOWN` (planned CB27) | Only if independent Review authorizes exact work; RA-127.4b negatives, unrelated-seam and no-direction tests remain owed. |


## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — independent TB27 A7 seam result adjudication (review ID UNKNOWN pending authority).

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. TB27 result report `Architecture_M6_CP3_TB27_A7_Certified_Seam_Cross_Sheet_Verification_Report_20261022.md`, exact result artifact `12420676412`, corrected harness `60414d738`, RA-131 and RA-130 B1–B6, 21 raw logs and TQ D3/D7 oracle; `LESSONS.md` evidence/witness sections.
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
