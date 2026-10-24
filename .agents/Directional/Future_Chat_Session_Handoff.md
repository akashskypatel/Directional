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
| Currency | 2026-10-24, TB34 measured seven inherited A3 CycleTransportMismatch RED at S1 LocalVertex row0 region0; five controls passed; awaiting independent TB34-REV, no runtime acceptance. |
| Source/package | CB33 semantic `f807c2b890b990fc53ea8f84c7228edd94f0659d`; [compile run 40084311360](https://github.com/akashskypatel/Directional/actions/runs/40084311360), package `12556364042`, ZIP `f984368a213012b2adf5996afe7443817b024f2cb9ef579e5e77e1c99e5ca291`; 28/28 hashes, eight GMP/GMPXX targets, `runtimeExecution=false`. |
| Reviewed decision | [Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Review_Decision_20261024.md](Architecture_M6_CP3_CB33_A3_Cycle_Mismatch_Locus_Diagnostic_Review_Decision_20261024.md): S1 `cycle-transport` carries local row/kind; S2 boundary correction cannot change residue mod4. TB34 must collect seven true S1 loci without inferring S2 failure. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500** (19 inherited RED); TB34 **5 PASS / 7 inherited RED** (12 measured), TB33 synthetic **6/6** only; selector497 frozen; stable **66/17/49**, debt 1. RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV` — EXACT NEXT

- **Type:** Independent Review of immutable TB34 evidence, no code/fixture/test/selector changes and no new test execution.
- **Evidence:** CB33 immutable package `12556364042`, source `f807c2b890b990fc53ea8f84c7228edd94f0659d`; TB34 [run 40090972464](https://github.com/akashskypatel/Directional/actions/runs/40090972464), result artifact `12558378347`, outer SHA-256 `0755af052c5a2642d5a0f132c348eccb0dd2b6e8312e0805effdfaae19c98118`, 17/17 packaged checksums; [report](Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Report_20261024.md).
- **Observed:** selector189–195 all RED at first `CycleTransportMismatch`, `site=cycle-transport`, `cycleKind=LocalVertex`, region-local `cycleRowIndex=0`, `topologyRegion=0`; two atlas guards and three TB33 controls PASS; 12/12 terminal, zero missing.
- **Review questions:** re-open all seven raw logs and original source/fixtures, independently derive cycle authority and whether shared row0 is invalid fixture construction or real producer contract failure; preserve S2 mathematical unreachability, distinguish region-local S1 index from S2 atlas-global index, check guard non-vacuity, determine required correction without guessing. No diagnostic-only acceptance or direct production credit.
- **Accounting:** CP2 accepted 491/491, TB32 481/500 candidate with 19 inherited RED, selector497 unchanged; stable 66/17/49 debt1, RP-01 open, RP-02 unreached, Gate C suspended.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV` | Independent evidence Review and exact owner adjudication, no TB/CB work. |
| 2 — conditional | UNKNOWN | Review assigns authorized successor based on first-error findings. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **independent Review** — TB34 run `40090972464`, result `12558378347`, [report](Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Report_20261024.md), exact manifest and raw logs, CB33 source/package, CB33-REV S2 unreachability, TB32 19 inherited REDs and accepted CP2 491/491.

Minimum context after mandatory policies:
0. ORIENTATION, ROADMAP, TODO, this handoff, TB34 report/result and frozen manifest.
1. Independently read TB34 raw logs and ledger, checksum every result entry, compare actual first failures to 12 frozen identities.
2. Re-derive `LocalVertex` row0 S1 predicate against CB33 source and test fixture, using CB33-REV S2 proof; independently check atlas guards and TB33 controls.
3. Keep all 19 inherited REDs and CP3 acceptance debt carried; do not use S2 as an independent cause.

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
