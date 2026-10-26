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
| Currency | 2026-10-26: CB42 RA-156 J3/O3 test-only source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded` compiled in run 40285233031 (artifact 12634151125, 28/28 hashes, eight GMP/GMPXX targets, runtime disabled). First-rejection locus pinned in 251/252/`:2936` with no runtime execution. Independent CB42-REV accepted ([CB42-REV decision](Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Independent_Review_Decision_20261026.md)); TB41 is next and remains separate. Stable 66/17/49, debt 1. |
| Previous reviewed package | CB40 test-only `0d227875d8f031a467e661be2da4dd901846797c`; [compile 40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131), artifact `12625069994`, ZIP SHA256 `0f5e554b975bd1306df587f7bb0031707136f2a629fb550beab61e02301e3d41`; eight GMP/GMPXX targets, `runtimeExecution=false`. [CB40 record](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Code_Build_Record_20261026.md); [CB40-REV independent review decision](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Independent_Review_Decision_20261026.md) and [authentic Git check 40271541658](https://github.com/akashskypatel/Directional/actions/runs/40271541658) PASS. Prior CB39 source/package and Review remain preserved in their separate record and decision. |
| Latest compile | CB42 test-only `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`; [compile 40285233031](https://github.com/akashskypatel/Directional/actions/runs/40285233031), artifact `12634151125` ZIP SHA256 `d7f7b8302966b14acd919eeef4465d518a6179f1823fbb86ad0e5b1b43488b87`; 28/28 file hashes, eight GMP/GMPXX targets, `runtimeExecution=false`. [CB42 record](Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Code_Build_Record_20261026.md). Previous CB41 source/package retained in its record. |
| Reviewed decision | [CB41-REV](Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Independent_Review_Decision_20261026.md) statically accepted own-field selector189 A3/A4 oracle and compile package; RA-155.3 C satisfied (runtime TB41 pending). [RA-157](Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md): TB40 re-verified (29/29 hashes, 13/13 rows; the CB37→CB38 diff is the test hunk only). K1: CB39 needs an untampered-A3 baseline, `code`+`sourceEdge` assertions, and removal of the unsatisfiable A4 negatives. K2/O4: A4 `MissingTransitionProvenance` loses its only witness. K4: doc drift fixed. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500**; TB37 focused **14/16 reviewed**; TB38 independently reviewed **candidate 490/504** (497 prefix 483/14), unpromoted; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY` — ARTIFACT-ONLY TEST + BENCHMARK

- **Entry authority:** RA-156 J3/O3; CB39–CB42 independent static review chain including [CB42-REV decision](Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Independent_Review_Decision_20261026.md). Exact immutable CB42 compiled source `8dc8cdeae6f6ac05c28aaa4504ca2c42c3177ded`, compile [40285233031](https://github.com/akashskypatel/Directional/actions/runs/40285233031), artifact `12634151125`, 28/28 packaged checksums and eight GMP/GMPXX targets.
- **Objective:** separately execute manifest-authorized 189, 191, 192, 204, 247, 250, 251, 252 and the preapproved TB40 guards from the unchanged immutable artifact; independently record every PASS/RED, the first rejection locus for O3, exact source/package identity, complete raw logs and postflight.
- **Stop/falsifiers:** no rebuild or compile; no implementation/test/selector/fixture mutation; stop and preserve evidence on missing/invalid row, selector/package drift, wrong first-rejection locus, unexpected rejection, omitted logs, guard regression, nonpublication or failed postflight. No CP3 or selector497 promotion inside TB. An independent TB41-REV follows.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB38 → CB38-REV → TB40 → TB40-REV → audit ([RA-157](Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md)) | 250 focused candidate discharge; CB39 spec re-bound. |
| done | `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV` | Static Review accepted with authentic Git-history PASS; no runtime or promotion. |
| done | `M6-CP3-CB41-RP01-EQUIVALENT-LIFT-A3-INGRESS-REHOME-REV` | Static accepted; authentic-Git boundary/source authority PASS, run 40282179241. |
| done | CB42 compiled → CB42-REV | RA-156 J3/O3 locus assertions independently statically accepted; authentic full-history checks PASS; runtime remains separate. |
| 4 — next | `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY` → `…-REV` | Artifact-only: 189, 191, 192, 204, 247, 250, 251, 252 + TB40 guards; no rebuild. |
| 5 | `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` → `…-REV` | 190, 242, O2, O4; design only. |
| 6 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns the canonical IDs. |
| 7 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O2, O3 (compiled, pending Review/TB41), O4 (until DEFN), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY** — artifact-only TB. Load [CB42-REV decision](Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Independent_Review_Decision_20261026.md), [CB42 compile record](Architecture_M6_CP3_CB42_Polygonal_Disk_Locus_Pin_Code_Build_Record_20261026.md), frozen TB41 manifest/approved TB40 guards, immutable compile artifact and Test + Benchmark turn policy. Never rebuild or edit source in TB; independently capture all PASS/RED and postflight evidence.

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
