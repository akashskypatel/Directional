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
| Currency | 2026-10-26: CB41 selector189 re-home Code + Build compiled on exact source `53830149ea16473d0321e53da2587695916fd9cb` in run 40275357335, artifact 12630300861; test-only, no runtime or CP3/selector497 promotion. CB41-REV approved selector189 with authentic-Git boundary and source-authority PASS in run 40282179241; CB42 follows final beacon. Stable 66/17/49, debt 1. |
| Previous reviewed package | CB40 test-only `0d227875d8f031a467e661be2da4dd901846797c`; [compile 40264202131](https://github.com/akashskypatel/Directional/actions/runs/40264202131), artifact `12625069994`, ZIP SHA256 `0f5e554b975bd1306df587f7bb0031707136f2a629fb550beab61e02301e3d41`; eight GMP/GMPXX targets, `runtimeExecution=false`. [CB40 record](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Code_Build_Record_20261026.md); [CB40-REV independent review decision](Architecture_M6_CP3_CB40_Turning_Field_Monodromy_Rehome_Independent_Review_Decision_20261026.md) and [authentic Git check 40271541658](https://github.com/akashskypatel/Directional/actions/runs/40271541658) PASS. Prior CB39 source/package and Review remain preserved in their separate record and decision. |
| Latest compile | CB41 test-only `53830149ea16473d0321e53da2587695916fd9cb`; [compile 40275357335](https://github.com/akashskypatel/Directional/actions/runs/40275357335), artifact `12630300861` ZIP SHA256 `4e0d81532a8c33733b06ffb5be2054fc32e451fd54205d3784d778ab9fb0b2b1`; 28/28 file hashes, eight GMP/GMPXX targets, `runtimeExecution=false`. [CB41 record](Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Code_Build_Record_20261026.md). |
| Reviewed decision | [CB41-REV](Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Independent_Review_Decision_20261026.md) statically accepted own-field selector189 A3/A4 oracle and compile package; RA-155.3 C satisfied (runtime TB41 pending). [RA-157](Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md): TB40 re-verified (29/29 hashes, 13/13 rows; the CB37→CB38 diff is the test hunk only). K1: CB39 needs an untampered-A3 baseline, `code`+`sourceEdge` assertions, and removal of the unsatisfiable A4 negatives. K2/O4: A4 `MissingTransitionProvenance` loses its only witness. K4: doc drift fixed. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500**; TB37 focused **14/16 reviewed**; TB38 independently reviewed **candidate 490/504** (497 prefix 483/14), unpromoted; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN` — TEST-ONLY CODE + BUILD

- **Entry gate:** CB41-REV accepted selector189 ±4 own-field A3/A4 oracle. Authentic-Git `review_check.py boundary` and `authority` both PASS in [run 40282179241](https://github.com/akashskypatel/Directional/actions/runs/40282179241). No runtime, selector497 or CP3 promotion.
- **Authority:** RA-156 J3/O3: assert `cell=-1,side=-1` rejection locus in polygonal-disk cases 251, 252 and `:2936`, retaining reason, fixtures and source ownership.
- **Boundary:** compile-only with GMP/GMPXX; no product, selector, benchmark, workflow or runtime changes. Stop if source-owned rejection does not expose the locus; never weaken assertions. CB42-REV follows before artifact-only TB41.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB38 → CB38-REV → TB40 → TB40-REV → audit ([RA-157](Architecture_M6_CP3_TB40_REV_Audit_CB39_A3_Tamper_Spec_Decision_20261025.md)) | 250 focused candidate discharge; CB39 spec re-bound. |
| done | `M6-CP3-CB40-RP01-TURNING-FIELD-MONODROMY-REHOME-REV` | Static Review accepted with authentic Git-history PASS; no runtime or promotion. |
| done | `M6-CP3-CB41-RP01-EQUIVALENT-LIFT-A3-INGRESS-REHOME-REV` | Static accepted; authentic-Git boundary/source authority PASS, run 40282179241. |
| 1 — next | `M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN` → `…-REV` | RA-156 J3/O3: `cell=-1,side=-1` in 251, 252, `:2936`; test-only. |
| 4 | `M6-CP3-TB41-RP01-REHOMED-ORACLE-VERIFY` → `…-REV` | Artifact-only: 189, 191, 192, 204, 247, 250, 251, 252 + TB40 guards. |
| 5 | `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` → `…-REV` | 190, 242, O2, O4; design only. |
| 6 | 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; Review assigns the canonical IDs. |
| 7 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O2, O3 (until CB42), O4 (until DEFN), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB42-RP01-POLYGONAL-DISK-LOCUS-PIN** — CB41-REV history checks passed; begin test-only Code + Build. Read [CB41-REV decision](Architecture_M6_CP3_CB41_Equivalent_Lift_A3_Ingress_Rehome_Independent_Review_Decision_20261026.md), [RA-156](Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md), TODO, frozen selector/test contracts and GMP policy. Only 251, 252 and `:2936`; pin `cell=-1,side=-1` with source-authoritative failure; compile-only, no runtime or selector/CP3 promotion. Next independent CB42-REV.

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
