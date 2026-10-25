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
| Currency | 2026-10-25: CB38 test-only source and eight GMP/GMPXX compile targets verified; no runtime evidence for selector 250. CB38-REV accepted and froze TB40 manifest (RA-156.4). CP3 and selector remain unpromoted. |
| Source/package | CB38 test-only `41f39ba920eace2dad7b36d2b26c8073ce740239`; [compile 40232132945](https://github.com/akashskypatel/Directional/actions/runs/40232132945), artifact `12613073521`, ZIP SHA256 `ca7358b7de3ff7ce5bc234f69c2b06036a7a5681f96d9a2d6c9e7cd298797ab3`; 28/28 hashes, eight GMP/GMPXX targets, clean, `runtimeExecution=false`. [CB38 record](Architecture_M6_CP3_CB38_Selector250_Rail_Authority_Code_Build_Record_20261025.md). CB37 predecessor preserved in its separate record. |
| Reviewed decision | [RA-156](Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md): TB39 re-verified (17/17 hashes, 7 log hashes, 6 PASS / 1 RED). J1: derive `authoritativeRails` plus the three provenance maps through the production functions. J2: the 250 owner moves first. J3/O3: the polygonal-disk rejection oracles are vacuous on the reason alone. J4: guard set. J5: sequence numbering fixed. RA-155 homes A/B/C and the narrowed DEFN still stand. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500**; TB37 focused **14/16 reviewed**; TB38 independently reviewed **candidate 490/504** (497 prefix 483/14), unpromoted; selector497 frozen and unpromoted; stable **66/17/49**, debt 1; RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY` — artifact-only Test + Benchmark

- Independently accepted CB38's **static test-authority repair** and its immutable eight-target GMP/GMPXX compile; **selector250 has not run** after CB38.
- Frozen [13-case TB40 manifest](Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Verification_Case_Manifest.tsv) SHA-256 `5dd7d9499918b04a277b907835993beb7829e6d9f52c4cc345faf5e3cd2158e4`. `selector:250` remains RED/RED with PASS as `unexpected_pass` success signal; twelve GUARD/PASS rows are 199,235,236,249,251,252, TB36's three witnesses and 193–195.
- Execute immutable CB38 source/package `41f39ba920eace2dad7b36d2b26c8073ce740239` / artifact `12613073521`; no rebuild, relink, edits, selector mutation or invented PASS. TB40-REV binds the next owner for any RED; no CP3 promotion.
- [CB38-REV decision](Architecture_M6_CP3_CB38_Selector250_Rail_Authority_Independent_Review_Decision_20261025.md) contains independent findings, falsifiers and stop conditions.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | TB38 → TB38-REV → audit ([RA-155](Architecture_M6_CP3_TB38_REV_Audit_Tamper_Oracle_Homes_Decision_20261025.md)) | 490/504 candidate; homes A/B/C bound; DEFN narrowed. |
| done | CB37 → REV → TB39 → TB39-REV → audit ([RA-156](Architecture_M6_CP3_TB39_REV_Audit_Selector250_Rail_Provenance_Decision_20261025.md)) | 250 site `hard-rail-contact-missing`; fixture rail authority; 250 owner first. |
| done | `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY` | Test-only hunk compiled, exact package verified; no runtime. |
| done | `M6-CP3-CB38-RP01-SELECTOR250-RAIL-AUTHORITY-REV` | Independent review freezes TB40 manifest (RA-156.4), if accepted. |
| 1 — next | `M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY` → REV | 250 kind RED; GUARD rows 199, 235, 236, 249, 251, 252, the 3 TB36 witnesses and 193–195. The REV discharges 250 or binds one new owner. |
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

`load_next`: **M6-CP3-TB40-RP01-SELECTOR250-RAIL-AUTHORITY-VERIFY** — [CB38-REV](Architecture_M6_CP3_CB38_Selector250_Rail_Authority_Independent_Review_Decision_20261025.md), [TB40 frozen manifest](Architecture_M6_CP3_TB40_Selector250_Rail_Authority_Verification_Case_Manifest.tsv), exact CB38 compile artifact `12613073521`, RA-156.4; artifact-only no-rebuild evaluation.

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
