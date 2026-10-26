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
| Currency | 2026-10-26: CB40 test-only turning-field k=1/k=2 oracle re-home compiled and independently source/package reviewed. CB40-REV is still open pending authentic-Git historical review checks and mandatory closeout; CB41 is conditional, not current. No runtime, selector497 or CP3 promotion. Stable 66/17/49, debt 1. |
| Source/package | CB40 test-only `0d227875d8f031a467e661be2da4dd901846797c`; [compile 40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131), artifact `12625069994`, ZIP SHA256 `0f5e554b975bd1306df587f7bb0031707136f2a629fb550beab61e02301e3d41`; eight GMP/GMPXX targets, `runtimeExecution=false`. [CB40 record](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Code_Build_Record_20261026.md); [CB40-REV pending review decision](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Independent_Review_Decision_20261026.md); formal historical closeout pending. Prior CB39 source/package and Review remain preserved in their separate record and decision. |
| Reviewed decision | [RA-157](Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md): TB40 re-verified (29/29 hashes, 13/13 rows; the CB37→CB38 diff is the test hunk only). K1: CB39 needs an untampered-A3 baseline, `code`+`sourceEdge` assertions, and removal of the unsatisfiable A4 negatives. K2/O4: A4 `MissingTransitionProvenance` loses its only witness. K4: doc drift fixed. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500**; TB37 focused **14/16 reviewed**; TB38 independently reviewed **candidate 490/504** (497 prefix 483/14), unpromoted; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV` — INDEPENDENT REVIEW

- **Authority:** RA-155.3 B / RA-157.4 and [CB40 Code + Build record](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Code_Build_Record_20261026.md); exactly compiled source `0d227875d8f031a467e661be2da4dd901846797c`, [run 40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131), artifact `12625069994`.
- **Scope:** independently review only the selectors 192 and 247 test hunks, A3 turning-field inputs/rotation prerequisites, original A4 assertions and source/package evidence. Re-verify eight-target GMP/GMPXX compile-only boundary, manifest and exact source; **no runtime** in this Review.
- **Acceptance / falsifiers:** reject an A3-invalid baseline, nondiscriminating or vacuous turning-field stimulus, unmet A4 assertion preservation, source drift or insufficient package evidence. No selector/CP3 promotion, runtime test or benchmark.
- **Evidence already recorded:** [CB40-REV independent static decision](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Independent_Review_Decision_20261026.md) checks test-oracle scope and compile package; its historical `review_check.py boundary` / `ledgers` attempts exited 1 because the snapshot contains no `.git`. Do not call the synthetic snapshot passes authority. Re-run both on authentic repo Git history, complete consolidation and drift audit, then close this Review.
- **On successful Review:** separately authorize the existing CB41 successor per RA-155; do not combine turns.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB38 → CB38-REV → TB40 → TB40-REV → audit ([RA-157](Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md)) | 250 focused candidate discharge; CB39 spec re-bound. |
| 1 — next | `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV` | Independent static Review of completed CB40 selector192/247 test-only compile; no runtime. |
| 2 | `M6-CP3-CB41-RP01-EQUIVALENT-LIFT-A3-INGRESS-REHOME` → `…-REV` | RA-155.3 C: 189, with each A3 built from its own ±4 field; test-only. |
| 3 | `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN` → `…-REV` | RA-156 J3/O3: `cell=-1,side=-1` in 251, 252, `:2936`; test-only. |
| 4 | `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY` → `…-REV` | Artifact-only: 189, 191, 192, 204, 247, 250, 251, 252 + TB40 guards. |
| 5 | `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` → `…-REV` | 190, 242, O2, O4; design only. |
| 6 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns the canonical IDs. |
| 7 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O2, O3 (until CB42), O4 (until DEFN), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV** — resume formal closeout of [CB40-REV independent static review](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Independent_Review_Decision_20261026.md); authenticated Git-history boundary/ledgers, remaining documentation and consolidation; [CB40 record](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Code_Build_Record_20261026.md), exact source `0d227875d8f031a467e661be2da4dd901846797c`, [compile 40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131), artifact `12625069994`. No runtime, promotion or next implementation until Review closes.

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
