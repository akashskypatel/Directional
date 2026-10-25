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
| Currency | 2026-10-25: RA-155 audit. TB38-REV is accepted (candidate 490/504). Its seven-oracle DEFN is replaced by Review-bound homes (A/B/C) and a narrowed DEFN (190, 242). The 250 factory-site message is first. CP3 and the selector stay unpromoted. |
| Source/package | CB36 exact semantic `038ae7fd7c290731c28225d2693a3e13866e325a`; [compile run 40173209091](https://github.com/akashskypatel/Directional/actions/runs/40173209091), artifact `12590917524`, ZIP SHA256 `6dcbfe5a468be5f548c368bfebeba411c6abd19ed4a4efd01be9923da9eb7d03`; 28/28 hashes, all eight GMP/GMPXX targets, clean source, `runtimeExecution=false`. [CB36 record](Architecture_M6_CP3_CB36_Periodic_Route_Atlas_Transport_Code_Build_Record_20261025.md). |
| Reviewed decision | [RA-155](Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md): TB38 re-verified (1,014/1,014 hashes, 490/14). H2/O2: `make` requires an atlas, so legacy paths cannot produce output. H3: 242 is a cross-region seam with no A2–A4 consumer. H4: 192's own stimulus is an S1 negative, not a monodromy. H5: 250 site exposure first. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500**; TB37 focused **14/16 reviewed**; TB38 independently reviewed **candidate 490/504** (497 prefix 483/14), unpromoted; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE` — CODE + BUILD (test-only)

- **Authority:** [RA-155.5](Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md).
- **Edit:** only the **streamed message** of the existing `ASSERT_EQ(Produced, network.phaseFront.disposition())` at `tests/SurfaceCellsPhase10Tests.cpp:3666–3669`. Replace it with `curved_disk_factory_rejection_detail(network.phaseFront)` (helper at `:2630`), followed by `" site="` and `rejection()->publishedProductSourceAuthoritySite`, null-guarded.
- **Must not change:** the assertion operands or macro, any other line, production code, selectors, the harness or workflows.
- **Evidence:** 8 GMP/GMPXX targets, `runtimeExecution=false`, and a record of 30 lines or fewer with the exact hunk.
- **STOP → Review:** the helper is not visible at the site, or the field name differs.
- **Preserve:** stable 66/17/49, debt 1; CP2 491/491; TB32 481/500 and TB38 490/504 candidate; selector497 frozen; RP-01 open; `DIAG-RETAIN`, O1, O2, RA-152.5, RA-146.2/.4, RA-45.4 and G4-B002 kept separate.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB35…TB37 chain (RA-152, RA-153, RA-154); CB36 D2 | F1 fixed and verified (focused 14/16). |
| done | TB38 → TB38-REV → `…-REV-AUDIT` ([RA-155](Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md)) | 490/504 candidate; homes A/B/C bound; DEFN narrowed. |
| 1 — next | `M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE` → `…-REV` | Message-only test edit; the REV issues the TB39 manifest. |
| 2 | `M6-CP3-TB39-RP01-SELECTOR250-FACTORY-SITE-HARVEST` → `…-REV` | 250 RED + 3 TB36 witnesses + 193–195 GUARD; the REV classifies the site (56–66 → periodic action / O1) and binds the 250 owner. |
| 3 | CB38-A (191+204 → A3 `NonReciprocalAdjacency`) → REV | Test-only; identities kept. |
| 4 | CB39-B (192 k=1, 247 k=2 turning-field monodromy) → REV | Test-only; original A4 assertions kept. |
| 5 | CB40-C (189: A3 from its own ±4 field) → REV | Test-only. |
| 6 | TB40 focused re-homes → REV | 189, 191, 192, 204, 247 + guards. |
| 7 | `M6-CP3-DEFN-RP01-LEGACY-PATH-AND-SEAM-ORACLES` → REV | 190, 242, O2; design only. |
| 8 | 250 owner → 405 → 174, 201 → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn. |
| 9 | Census → RP-01 Review | Review-owned manifest. |
| carried | `DIAG-RETAIN` (full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | O1 (cut-route identity), O2 (legacy branches unreachable), RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB37-RP01-SELECTOR250-FACTORY-SITE-MESSAGE** — [RA-155.5](Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md); `tests/SurfaceCellsPhase10Tests.cpp:2630` (helper) and `:3666–3669` (site); `SurfacePhaseFrontFailure` (`SurfaceCellTracing.h:1866–1890`). Message-only edit; compile only.

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
