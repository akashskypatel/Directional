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
| Currency | 2026-10-26: TB41 immutable artifact-only run [40296007299](https://github.com/akashskypatel/Directional/actions/runs/40296007299) executed **18/18 PASS**, eight re-homed oracles and ten nonduplicated TB40 guards; 39/39 result hashes, `postflight=true`, no rebuild/relink. [TB41 report](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Report_20261026.md) retains exact source/package and raw logs; independent TB41-REV is next. Candidate only; CP2 491/491 accepted, TB38 490/504 candidate, selector497 frozen/unpromoted, stable 66/17/49 debt 1, RP-01 open. |
| Previous reviewed package | CB40 test-only `0d227875d8f031a467e661be2da4dd901846797c`; [compile 40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131), artifact `12625069994`, ZIP SHA256 `0f5e554b975bd1306df587f7bb0031707136f2a629fb550beab61e02301e3d41`; eight GMP/GMPXX targets, `runtimeExecution=false`. [CB40 record](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Code_Build_Record_20261026.md); [CB40-REV independent review decision](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Independent_Review_Decision_20261026.md) and [authentic Git check 40271541658](https://github.com/akashskypatel/Directional/actions/runs/40271541658) PASS. Prior CB39 source/package and Review remain preserved in their separate record and decision. |
| Latest compile | CB42 test-only `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`; [compile 40285233031](https://github.com/akashskypatel/Directional/actions/runs/40285233031), artifact `12634151125` ZIP SHA256 `d7f7b8302966b14acd919eeef4465d518a6179f1823fbb86ad0e5b1b43488b87`; 28/28 file hashes, eight GMP/GMPXX targets, `runtimeExecution=false`. [CB42 record](Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Code_Build_Record_20261026.md). Previous CB41 source/package retained in its record. |
| Reviewed decision | [CB41-REV](Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Independent_Review_Decision_20261026.md) statically accepted own-field selector189 A3/A4 oracle and compile package; RA-155.3 C satisfied (runtime TB41 pending). [RA-157](Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md): TB40 re-verified (29/29 hashes, 13/13 rows; the CB37→CB38 diff is the test hunk only). K1: CB39 needs an untampered-A3 baseline, `code`+`sourceEdge` assertions, and removal of the unsatisfiable A4 negatives. K2/O4: A4 `MissingTransitionProvenance` loses its only witness. K4: doc drift fixed. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500**; TB37 focused **14/16 reviewed**; TB38 independently reviewed **candidate 490/504** (497 prefix 483/14), unpromoted; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY-REV` — INDEPENDENT RUNTIME-EVIDENCE REVIEW

- **Entry authority:** [TB41 report](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Report_20261026.md), frozen [18-case manifest](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Case_Manifest.tsv), immutable CB42 source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, package `12634151125`, [run 40296007299](https://github.com/akashskypatel/Directional/actions/runs/40296007299), result artifact `12638251384` (ZIP SHA256 `1817f8295709a88bb3a561734b345cc50e81da056684501d714aac08fb7dd854`). TB41 measured 18/18 PASS and 39/39 hashes with `postflight=true`.
- **Review obligations:** independently rehash package, manifest, result and all 18 raw logs; join exact case/test identities and terminal assertions to ledger, verify no omissions/duplicates and preserved TB40 guards; re-derive CB42 O3 rejection locus and 189/191/192/204/247/250 reachability/non-vacuity from primary source and raw records; verify accepted-prefix, source authority, immutable execution and real-Git history. Classify any limitation explicitly and carry all unresolved owners.
- **Boundary and falsifiers:** Review is runtime-free and changes no product/test/selector/fixture/build sources. Stop promotion for an unverifiable log/hash, missing guard, wrong locus, vacuous prerequisite, accepted-prefix drift, or failed historical audit. Focused TB41 PASS is candidate evidence only: no CP3 or selector497 promotion without separate full-gate authority. Freeze exactly one successor in the independent decision.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB38 → CB38-REV → TB40 → TB40-REV → audit ([RA-157](Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md)) | 250 focused candidate discharge; CB39 spec re-bound. |
| done | `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV` | Static Review accepted with authentic Git-history PASS; no runtime or promotion. |
| done | `M6-CP3-CB41-RP01-EQUIVALENT-LIFT-A3-INGRESS-REHOME-REV` | Static accepted; authentic-Git boundary/source authority PASS, run 40282179241. |
| done | CB42 compiled → CB42-REV | RA-156 J3/O3 locus assertions independently statically accepted; authentic full-history checks PASS; runtime remains separate. |
| done → 4 — next | `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY` → `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY-REV` | TB41: 18/18 focused candidate PASS, immutable postflight; independent evidence Review next, no promotion. |
| 5 | `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` → `…-REV` | 190, 242, O2, O4; design only. |
| 6 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns the canonical IDs. |
| 7 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O2, O3 (TB41 focused candidate, pending independent Review), O4 (until DEFN), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY-REV** — independent evidence Review, not a repeated TB. Load [TB41 report](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Report_20261026.md), its [case manifest](Architecture_M6_CP3_TB41_Rehomed_Oracle_Verification_Case_Manifest.tsv), [CB42-REV decision](Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Independent_Review_Decision_20261026.md), exact CB42 package `12634151125` and TB41 result `12638251384`. Rehash and re-derive all 18 raw case outcomes, O3 locus non-vacuity, TB40 guard continuity and authentic authority; obey `REVIEW_TURN_POLICY.md` closeout and document consolidation. No runtime/rebuild or CP3/selector promotion without independent acceptance.

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
