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

## Current immutable authority — 2026-10-17 (R10B Definition authored; independent Review next)

| Topic | Authority |
|---|---|
| Branch | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch head at next entry. |
| Milestones | M0–M5 CLOSED; M6 CP1/CP2 CLOSED; **M6 CP3 OPEN**, M7/M8 planned (`ROADMAP.md`). |
| Accepted baseline | M6 CP2 **491/491** PASS, package `11391685901` (source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`). CP3 selector 497 unchanged; R3 **403/497**, independently rejected. |
| Latest runtime | TB10 44/44 RED, 21 one-hot vertex records, 0/21 contact membership and 21/21 carrier endpoint membership, candidate evidence only. Run `38941839640`, result `12062873272`; compile artifact `12062565622`, source `d938ecb57e1040c2a73d5d25c4a613414556cb18`. |
| R10A/RA-83 | Interior rail vertex 4 on open rail 1–4–7 lacks V/I/C classification; verifier rejects at endpoint and route layers, while consumer can certify I–I. Ordered rail chain reaches consumer but is dropped from verifier projection. Source-owned facts in `Architecture_M6_CP3_R10A_Rail_Interior_Vertex_Witness_Census_20261017.md`; RA-83 decision in `Architecture_M6_CP3_R10A_Witness_Census_Review_Decision.md`. |
| R10B contract | `Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md` (Definition, pending Review). Choose independent ordered open-rail chain; exact R vertex + two named hard spokes + unique disjoint A3 sectors; allow T–R, I–R, R–R only conditionally, reject I–I symmetrically; retain T–T/T–I, strict I rationals and closed-rail C. Static source snapshot `df37ffc191ee3eaa8f27c9aeade25b2804f2a3b8`, run `39080614250`, artifact `12118283137`, 5,646/5,646 hashes. **No runtime/acceptance claim.** |
| Open accounting | `RP-01` unresolved; `RP-02` UNREACHED; Gate C suspended. Stable **66 events / 17 categories / 49 recurrences**, debt **1**; no selector, source or test changes. |
| Turn lifecycle | Root `STATUS` to be finalized by this turn. Next exact turn upon completion: `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV`. History gates belong to Review (RA-82.3). |

## Mandatory next turn — `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV` — EXACT NEXT, conditional on R10B closeout

- **Type:** independent Review of the R10B document; **not** a code/build or test/benchmark turn.
- **First:** verify the delivered rule against RA-83, R10A census, R9B branch V/I/C and RA-65.5/68.3/72.5/78.4; inspect exact producer→consumer→checked-factory paths in frozen source and the new R10B document.
- **Decide:** is the upstream ordered open-rail chain independent, source-authenticatable and sufficient to add R without a producer-authored vertex-star witness? Does the same per-endpoint and route-level anchor rule reject I–I in both checkers while preserving T–T, T–I and tamper negatives? Are T–R / I–R / R–R conditional gates complete, or is further independent witness required?
- **Check:** independently enumerate code sites and separate positive/negative test oracles in groups A–E; review the six-row outcome matrix and explicit R negatives. Verify no forbidden source/selector/acceptance modifications, no documentation drift, and full-history `review_check.py authority|boundary|ledgers` plus `document_drift_audit.py --base` (RA-82.3). The Definition's `--root` audit is not a substitute.
- **Disposition:** accept, amend, or reject with cited evidence. **Only an accepted Review** may authorize narrowly split Code + Build units; do not invent the next code turn or change frozen accounting. On a blocking design conflict, keep the R10B Review open and record the specific unresolved condition.

## Turn Sequence

| Step | Canonical turn | Condition |
|---|---|---|
| 1 — current Definition | `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE` | Documents-only proposal and closeout; no implementation. |
| 2 — next Review | `M6-CP3-DEFN-R10B-RAIL-INTERIOR-VERTEX-ENDPOINT-RULE-REV` | Only after step 1 is complete; independently review rule, code sites, tests and full-history gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **independent Review**. Use turn-based-coding-agent Review guidance; no Code + Build or Test + Benchmark is authorized.

Minimum R10B Review context after mandatory policies/start checklist: `ORIENTATION.md`, `ROADMAP.md`, this handoff, `STATUS`, `TODO.md`, `Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md`, `Architecture_M6_CP3_R10A_Witness_Census_Review_Decision.md`, R10A census, R9B contract, R9A census, `Architecture_M6_Frozen_Definitions.md` (RA-65.5/68.3/72.5/78.4/79/83), `Regression_Root_Cause_Tracker.md`, and both consumer/verifier source windows cited in R10B. The full-history Review checks require a genuine Git history, not the `.git`-free ChatGPT Web snapshot.

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
