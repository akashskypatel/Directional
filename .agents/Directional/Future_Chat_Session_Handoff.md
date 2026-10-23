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
| Currency | 2026-10-23, after the TB30 review (RA-144). CB29 matches RA-143.3. TB30 (29/29 as predicted) shows **M1 resolved on the targeted gate**: 10/10 PASS, the 7 non-M1 factory rows unchanged, all 12 controls and guards PASS. CB29 changed A4 admission for every hard-rail certificate, so a full census (TB31) runs next, on the CB29 package, with the crash-safe targeted harness and a Review-owned 497-row manifest. Predicted: 472/497. |
| Branch/source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open. CB29 semantic `2602e7398cdc6f1281abe11a758de35166b6590c`; CB29 compile [run 39932638282](https://github.com/akashskypatel/Directional/actions/runs/39932638282), package `12492950387` ZIP SHA `9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`; GMP eight targets, 28/28 hashes, compile-only. |
| TB30 runtime evidence | [run 39949886169](https://github.com/akashskypatel/Directional/actions/runs/39949886169), immutable result `12500088095` ZIP SHA-256 `bba928eb45957a29521a221ad093891de29f6a498c156691acc9c68b3a7308bf`; all 29 identities once, 22 PASS / 7 typed RED, 61/61 result hashes, no missing/skip/invalid/duplicates/unexpected PASS, no rebuild. Owning `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Report_20261023.md`. |
| Unresolved first failures | Six `face-gauge-missing` (`selector:220,221,296,302,304,439`) and one `open-rail-chain` (`cp3entry:4`) remain inherited typed RED, no new stable regression or resolved causal assignment. |
| Accepted versus candidate | CP2 491/491 accepted. R3 403/497 rejected; TB28 462/497 candidate only. Selector 497 byte-frozen, CP3 not accepted. Stable 66/17/49, debt 1; RP-01 open, RP-02 unreached, Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS` — EXACT NEXT

- **Type / owner:** Test + Benchmark, artifact-only census; implementation agent. Authority: RA-144.3 (`Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md`).
- **Objective:** measure all 497 frozen identities on the CB29 package with the crash-safe harness. Detect any regression from CB25, CB26 or CB29; confirm the 25-row RED set.
- **Read before work:** RA-144 (all); RA-139.3 (verdict rule); the TB30 report `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Report_20261023.md`; the manifest `Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv`.
- **In scope:** dispatch `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` (SHA-256 `436f5fff9c3bec97457f4bc6b7c2b6182cb3f47707eb14a66af3b6a3f3dc3c9a`) through `agent-test-benchmark-reusable.yml`, with `harness_env`:
  - `CANDIDATE_ARTIFACT_ID=12492950387`;
  - `EXPECTED_SOURCE_SHA=2602e7398cdc6f1281abe11a758de35166b6590c`;
  - `EXPECTED_CANDIDATE_ZIP_SHA256=9e2da1f4b5cf95ac45364e8c428f0bd9116dcfe96772de18d02a5a7bfb167319`;
  - `EXPECTED_ROOT_MANIFEST_SHA256=5f7259b7ec0f420c8d161973f450e99e76684b0643c8e21074d192931747320d`;
  - `EXPECTED_SOURCE_ARCHIVE_SHA256=e5ec539063d7bf6dfbe06b1552c081d117e052f8090a58aaa6ac754242e8f53a`;
  - `CASE_MANIFEST=.agents/Directional/Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv`;
  - `CASE_MANIFEST_SHA256=b1c135d429f8c659e190f648b8678669cb7c14d393e0db9069568ea3838aa43e`;
  - `EXPECTED_CASE_COUNT=497`.

  Then write `Architecture_M6_CP3_TB31_Selector_497_Census_Report_20261023.md` (totals, a row diff against TB28, every RED's typed reason, and a new RED inventory TSV).
- **Prediction:** 472/497; exactly the 25 RA-144.2 rows RED; 0 PASS→RED.
- **Reading the result:**
  - `control_bad > 0` is a measured regression (harness exit non-zero after evidence is published): report it, don't fix it;
  - `unexpected_pass` is a RED row that recovered: report it;
  - any `INVALID` row: STOP.
- **Out of scope:** any source, test, harness, manifest, selector or workflow change; compile, relink or benchmarks; promotion.
- **Success evidence:** the immutable result with a verified `SHA256SUMS`; 497 executed, no missing or skipped; the report committed; STATUS COMPLETE.
- **On success:** `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS-REV` (Review, mandatory): census adjudication; orders the per-owner turns.
- **On failure/blocker:** STOP and record it on an `INVALID` row, a hash mismatch or package expiry (2026-10-30T09:34:32Z). No reruns after runtime has started.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS` | Artifact-only census of 497 on CB29 package `12492950387` with the crash-safe harness and the RA-144.3 manifest; predicted 472/497. |
| 2 — conditional | `M6-CP3-TB31-RP01-SELECTOR-497-CENSUS-REV` | Review, only after step 1 completes: census adjudication; orders the per-owner turns. |
| later — UNKNOWN until assigned | per-owner turns (each DEFN or diagnostic first): face-gauge-missing (6) → A3 cycle locus (7, diagnostic) → untyped producer/oracle rows (7) → A5 `focused30:12` → `cp3entry:4` open-rail-chain → `selector:442` → DEFN-T1 (`cp3entry:1/2`) → census → RP-01 Review; `DEFN-SEAM-NZ` and the Periodic follow-up only after a witness | Planned, not authorized; each Review assigns the next edge. |
| later — UNKNOWN until assigned | `DIAG-RETAIN` (user-directed): retain A5 occurrences and relations, A6 merged classes and A7 vertex geometry as diagnostic snapshots for GUI/CLI; scope in `TODO.md` | Planned, not authorized; Review places it in the sequence clear of RP-01 turns. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — TB31: artifact-only 497 census with the targeted harness and the Review-owned manifest (RA-144.3); no build.

Minimum next context after mandatory start/policies:

0. `.agents/Directional/ORIENTATION.md`; `.agents/Directional/ROADMAP.md`.
1. `.agents/Directional/Future_Chat_Session_Handoff.md`, TB30 owning report, exact result `12500088095` and its 29-case ledger/raw logs.
2. CB29 independent Review decision/manifest, RA-143.4, RA-141/142 and TB29 raw evidence `12481556884`; TB28 RED inventory.
3. `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Review_Decision_20261023.md` (RA-144: TB30 verified, 25-row RED owners, census inputs); `Architecture_M6_CP3_TB31_Census_Case_Manifest.tsv`; `Architecture_M6_CP3_TB30_Certificate_Association_Ownership_Verification_Report_20261023.md`.
4. Review helpers in `.agents/Directional/tools/` for independent evidence. Do not interpret a synthetic snapshot's git-history checks as authoritative.

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
