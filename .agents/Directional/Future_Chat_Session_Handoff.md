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
| Currency | 2026-10-25: RA-156 audit. TB39-REV accepted: 250 fails at the factory check `hard-rail-contact-missing` (code 0, detail 6), owned by the fixture, not O1. Its corrective spec is replaced: test 250 drops all four rail-authority fields that `make_curved_disk_fixture` already builds. The 250 owner moves first. CP3 and the selector stay unpromoted. |
| Source/package | CB37 exact semantic `c9d7c80f6d41abdbc2ecd02de7006c7847988df8`; [run 40216902065](https://github.com/akashskypatel/Directional/actions/runs/40216902065), package `12607777892`, ZIP SHA256 `fa437659c633de1b5e69dc93b35bcbb65dec84c212a957d005ada58e4dd01b58`; 28/28 hashes, eight GMP/GMPXX targets, clean source, `runtimeExecution=false`. [CB37 record](Architecture_M6_CP3_CB37_Selector250_Factory_Site_Message_Prepared_Patch_Record_20261025.md). |
| Reviewed decision | [RA-156](Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md): TB39 re-verified (17/17 hashes, 7 log hashes, 6 PASS / 1 RED). J1: derive `authoritativeRails` plus the three provenance maps through the production functions. J2: the 250 owner moves first. J3/O3: the polygonal-disk rejection oracles are vacuous on the reason alone. J4: guard set. J5: sequence numbering fixed. RA-155 homes A/B/C and the narrowed DEFN still stand. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500**; TB37 focused **14/16 reviewed**; TB38 independently reviewed **candidate 490/504** (497 prefix 483/14), unpromoted; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY` — CODE + BUILD (test-only)

- **Authority:** [RA-156.3](Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md).
- **Edit:** only the body of test 250 (`tests/SurfaceCellsPhase10Tests.cpp:3595`), inline. Insert it after the hard-edge insertions (`:3649–3662`) and before `build_phase10_with_source_atlas`:
  - Build a combined-mesh `AdaptiveFeatureMap` with one closed `Hard` curve, `component=2`, ring `{0,1,2,5,8,7,6,3,0}` plus `diskOffset`, and incidence taken from the combined `faces`; throw unless every edge has exactly 1 incident face.
  - Call `build_authoritative_surface_cell_rails(mesh, features)`.
  - Set `authoritativeRails`, `hardRailTerminalContacts`, `hardRailClosedChains` and `hardRailOpenChains` from `hard_rail_source_provenance_from_rails`.
  - Require that `closedChains` is non-empty and `hard_feature_edge_keys_from_rails(...) == options.hardFeatureEdges`.
  - Mirror the existing fixture code at `:2582–2626`.
- **Must not change:** the hard-edge insertions, the `:3666` assertion and its message, later assertions, `make_curved_disk_fixture`, production code, selectors, the harness or workflows.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, and a record of 30 lines or fewer with the exact hunk.
- **STOP → Review:** the rail builder rejects, the edge-key identity differs, or an edit outside test 250 is needed.
- **Preserve:** stable 66/17/49, debt 1; CP2 491/491; TB32 481/500 and TB38 490/504 candidate; selector497 frozen; RP-01 open; carried items listed below.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB38 → TB38-REV → audit ([RA-155](Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md)) | 490/504 candidate; homes A/B/C bound; DEFN narrowed. |
| done | CB37 → REV → TB39 → TB39-REV → audit ([RA-156](Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md)) | 250 site `hard-rail-contact-missing`; fixture rail authority; 250 owner first. |
| 1 — next | `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY` → REV | Test-only, compile only; the REV freezes the TB40 manifest (RA-156.4). |
| 2 | `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY` → REV | 250 kind RED; GUARD rows 199, 235, 236, 249, 251, 252, the 3 TB36 witnesses and 193–195. The REV discharges 250 or binds one new owner. |
| 3 | CB39-A (191+204 → A3 `NonReciprocalAdjacency`) → REV | RA-155.3 A; test-only. |
| 4 | CB40-B (192 k=1, 247 k=2 monodromy) → REV | RA-155.3 B; test-only. |
| 5 | CB41-C (189: A3 from its own ±4 field) → REV | RA-155.3 C; test-only. |
| 6 | CB42-O3 (polygonal locus `cell=-1,side=-1`: 251, 252, `:2936`) → REV | RA-156 J3; test-only. |
| 7 | TB41 focused (189, 191, 192, 204, 247, 251, 252 + guards) → REV | Artifact-only. |
| 8 | `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` → REV | 190, 242, O2; design only. |
| 9 | TB40-REV owner (if any) → 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 | One owner per turn. |
| 10 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1, O2, O3 (until CB42), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY** — [RA-156.3](Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md); `tests/SurfaceCellsPhase10Tests.cpp:2582–2626` (the fixture to mirror) and `:3595–3669` (test 250); `RemeshPipeline.h:1860–1879` (rail functions). Test-only; compile only.

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
