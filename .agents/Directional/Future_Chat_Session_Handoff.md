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
| Currency | 2026-10-27, CB47A [tool-only record](Architecture_M6_CP3_CB47A_Harness_Manifest_Pins_Code_Record_20261027.md): 504/504 offline ledger/log replay matched 498 PASS / 6 RED, six manifest pins plus 12 falsifiers, no compile/runtime. Previous TB46 rerun [report](Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md): immutable CB46B package `12716018703` (source `8f0d4329695d`), [run 40468913755](https://github.com/akashskypatel/Directional/actions/runs/40468913755) verified 504/504, **498 PASS / 6 registered RED**, all 497 guards and selector174 positive pass, zero control violations, harness exit0. [DEFN-E Review](Architecture_M6_CP3_DEFN_TB46_Endpoint_Cluster_Review_Decision_20261027.md) classified E1/E2/E3; TB47 manifest frozen; CB47A complete, CB47 next. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | [TB46 rerun report](Architecture_M6_CP3_TB46_RP01_Full_Gate_Rerun_Report_20261027.md), result artifact `12719412600`, SHA256 `2a33427b…5fd37`; logs `12719912170`, wrapper `12719462521`; 1,014/1,014 checked members, 504/504 raw process joins, postflight true. Expected E failures: 201, cp3entry:2, cp3entry:4 D5 (`:4063`); expected G: 442, focused30:12, cp3entry:1. Original run `40448739180` remains S5 invalid attempt. Last previously valid full gate TB38 490/504 candidate; no production change since. Selector497 frozen/unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached; DEFN-E reviewed E1 stale terminal assertion, E2 missing A4 2-carrier junction, E3 missing source-valid A5 OrdinaryFront fixture; [TB47 manifest](Architecture_M6_CP3_TB47_Full_Gate_Case_Manifest.tsv) site/witness pins frozen and harness migration verified offline; next CB47. G (`selector:442`, `focused30:12`, `cp3entry:1`) later. Source-line pins now derive from frozen TB47 manifest; any movement requires a matching manifest/authority update. Carried O1, O2 (post-RP-01), O6, O7, DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ, RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES` — EXACT NEXT

- **Authority:** [DEFN-E decision](Architecture_M6_CP3_DEFN_TB46_Endpoint_Cluster_Review_Decision_20261027.md), [RA-165](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md), frozen TB47 504-row manifest SHA-256 `6f9b3582900951eef5f94309b7f7053412148faca4935a619e504bad9b73a09b`. CB47A tool-only migration is verified in its [record](Architecture_M6_CP3_CB47A_Harness_Manifest_Pins_Code_Record_20261027.md); no runtime gate was run for that turn.
- **Scope:** E1 `selector:201` outdated blanket T/R/I terminal assertion (preserve authentic open-rail and source-carrier obligations); E2 `cp3entry:2` real produced paired two-carrier A4 witness or independently justified source-valid stimulus; E3 `cp3entry:4` real reciprocal A5 OrdinaryFront positive and discriminating negatives. Correct earliest proven producer or oracle source, never synthetic output. Respect RA-165 F1/F2, exact hunk/path audits, and immutable selector/manifest. Compile-only through mandatory GMP/GMPXX reusable workflow; no runtime.
- **Successor only after CB47 complete:** `M6-CP3-TB47-RP01-FULL-GATE` (immutable 504-case artifact-only Test + Benchmark), then Review-owned G-cluster disposition. CP2 491/491 accepted; selector497 and CP3 unpromoted; stable 66/17/49 debt1, RP-01 open.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — complete | `M6-CP3-CB47A-HARNESS-MANIFEST-PINS` | Tool-only pin migration verified against 504 saved logs; no compile/runtime |
| 2 — next | `M6-CP3-CB47-RP01-ENDPOINT-WITNESSES` | CB47A verified;  implement E1–E3 at proven owner, compile-only GMP/GMPXX |
| 3 — conditional | `M6-CP3-TB47-RP01-FULL-GATE` | Immutable 504-case artifact-only run; route G-cluster after evidence |
| rule | RA-164.3 P1–P6; RA-165.2 F1/F2 | Until CB47A, test edits above pinned source lines MUST be line-neutral; never weaken accepted selector or validators |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB47-RP01-ENDPOINT-WITNESSES** — read [DEFN-E](Architecture_M6_CP3_DEFN_TB46_Endpoint_Cluster_Review_Decision_20261027.md), [RA-165](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md), [CB47A record](Architecture_M6_CP3_CB47A_Harness_Manifest_Pins_Code_Record_20261027.md), frozen [TB47 manifest](Architecture_M6_CP3_TB47_Full_Gate_Case_Manifest.tsv), and selectors 201, cp3entry:2, cp3entry:4 plus A4/A5 producers. Implement independently validated E1/E2/E3 corrections only; eight-target GMP/GMPXX compile-only, no product runtime. Separate TB47 gate follows the completed CB47 turn.

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
