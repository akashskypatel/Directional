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
| Currency | 2026-10-23, after TB31 artifact-only census. Exact 497/497, 472 PASS / 25 inherited RED / 0 INVALID; ten RED→PASS, zero PASS→RED vs TB28. RA-144.3 prediction confirmed without promotion. TB31-REV mandatory next. |
| Branch/source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open. CB29 semantic `2602e7398cdc6f1281abe11a758de35166b6590c`; CB29 compile [run 39932638282](https://github.com/akashskypatel/Directional/actions/runs/39932638282), package `12492950387` ZIP SHA `9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`; GMP eight targets, 28/28 hashes, compile-only. |
| TB30 runtime evidence | [run 39949886169](https://github.com/akashskypatel/Directional/actions/runs/39949886169), immutable result `12500088095` ZIP SHA-256 `bba928eb45957a29521a221ad093891de29f6a498c156691acc9c68b3a7308bf`; all 29 identities once, 22 PASS / 7 typed RED, 61/61 result hashes, no missing/skip/invalid/duplicates/unexpected PASS, no rebuild. Owning `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Report_20261023.md`. |
| Unresolved first failures | Six `face-gauge-missing` (`selector:220,221,296,302,304,439`) and one `open-rail-chain` (`cp3entry:4`) remain inherited typed RED, no new stable regression or resolved causal assignment. |
| TB31 runtime evidence | [run 39959505758](https://github.com/akashskypatel/Directional/actions/runs/39959505758), result `12506242253`, ZIP SHA-256 `97828fac57a63b5d8ca85ef0e5fd35fb7d5ed71c2b2579cd463bacc20d5e947b`; 1,000/1,000 checksum entries and 497/497 raw logs verified. All 497 Review-owned manifest rows matched exact test/binary/expected outcome; exit 0, postflight true, no compile/relink/benchmark. Report `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md`, RED inventory retained. |
| Accepted versus candidate | CP2 491/491 accepted. R3 403/497 rejected; TB28 462/497 superseded as candidate by TB31 472/497, **unaccepted**. Selector 497 byte-frozen; stable 66/17/49, debt 1; RP-01 open, RP-02 unreached, Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS-REV` — EXACT NEXT

- **Type / owner:** independent Review of TB31 immutable 497-identity census; Review may be done by the same agent provided its evidence and re-derivation are independent. Source authority RA-144.3.
- **Read before work:** `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md`, `Architecture_M6_CP3_TB31_Selector_497_Red_Inventory.tsv`, original GitHub Actions result `12506242253` from run `39959505758`, `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md` (RA-144), and frozen `Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv`.
- **Review objective:** independently rehash the immutable result and audit every executed identity against the frozen Review-owned manifest and TB28 ledger. Adjudicate the exact 472 PASS / 25 inherited RED / 0 INVALID, ten historical RED→PASS and zero PASS→RED. Confirm classified first-failure owners without upgrading untyped evidence to proven causes.
- **Required outcome:** Review decision and per-owner sequence; document remaining failures and falsifiers. Maintain CP2 491/491 accepted, CP3 unaccepted, stable 66/17/49 and debt 1 unless independently demonstrated otherwise. Do not change tests, source, harness, selector or workflow in this Review.
- **Successor:** UNKNOWN until this Review assigns one; no per-owner work is authorized during TB31 or before the Review.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS-REV` | Review the completed TB31 497-case result, adjudicate every RED and issue the per-owner sequence. |
| later — UNKNOWN until assigned | per-owner turns (each DEFN or diagnostic first): face-gauge-missing (6) → A3 cycle locus (7, diagnostic) → untyped producer/oracle rows (7) → A5 `focused30:12` → `cp3entry:4` open-rail-chain → `selector:442` → DEFN-T1 (`cp3entry:1/2`) → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — TB31-REV: independently adjudicate immutable 497-case census (472/497); no product changes or runtime.

Minimum next context after mandatory start/policies:

0. `.agents/Directional/ORIENTATION.md`; `.agents/Directional/ROADMAP.md`; `LESSONS.md` and REVIEW policy.
1. `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md`, `Architecture_M6_CP3_TB31_Selector_497_Red_Inventory.tsv`, result `12506242253` from run `39959505758`; re-verify outer ZIP SHA and 1,000 packaged checksums.
2. `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md` (RA-144.2 25 RED owner partition, RA-144.3 predictions), Review-owned manifest SHA `b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e`; TB28 full ledger.
3. CB29 source/package receipts, TB30 owning report, Regression Root Cause Tracker; reviewers independently adjudicate remaining typed and untyped first failures.
4. Do not interpret synthetic snapshot git-history checks as authoritative; do not rerun already-measured TB31.

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
