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
| Currency | 2026-10-27 TB46 504-process execution complete but **S5 invalid gate**; [TB46 report](Architecture_M6_CP3_TB46_Full_Gate_Test_Benchmark_Report_20261027.md). RA-164.5 / RA-164.3 P4 govern correction. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`; verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491**, accepted 2026-10-06. Nothing newer accepted; selector497 unpromoted. |
| Exact attempted evidence | CB46 semantic `c05d52dd7...`, package `12708707491`; full gate [run 40448739180](https://github.com/akashskypatel/Directional/actions/runs/40448739180), job `122006250303`, result `12711165610` (ZIP SHA-256 `158b8d25...9ed1`), harness log `12711016096`, reusable log `12711205512`. 504/504 raw processes and clean immutable postflight, 497 PASS / 7 RED, 2 POSITIVE controls failed; harness exit90. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, [tracker](Regression_Root_Cause_Tracker.md). TB46 raw ledger retained as S5 invalid-attempt provenance; no stable event. |
| Active boundary | RP-01 open. Five REDs remain pinned (`focused30:12`, `selector:201`, `selector:442`, `cp3entry:1`, `cp3entry:2`). Cluster E D1/D2 and G D3 messages harvested. POSITIVE 174: uncaught DCEL exception `unknown file` (not localized to later site); POSITIVE cp3entry:4: later failure `ordinaryCarrier` at `:4063`. RA-164.5 latent-fail allowance conflicts with frozen harness `control_bad` rejection. |

## Mandatory next turn — `M6-CP3-TB46A-ORCH` — EXACT NEXT (S5 Code + Build)

- **Authority:** RA-164.3 P4 S5 and RA-164.5. Initial TB46 attempt is invalid for acceptance because the unchanged artifact harness exits 90 `required controls failed` on two POSITIVE failures even though RA-164.5 recognizes source-proven later failure outcomes. Neither should be synthetically marked PASS.
- **Required scope:** orchestration/control-plane correction only, preserve exact CB46 package `12708707491`, frozen 504-case manifest SHA-256 `717f4f0f...6bb087`, five RED first-site pins and meaningful guards. Reconcile harness with published RA-164.5 outcome table using independently source-attributed later-predicate classification, and **fail closed** on early/unknown failures (selector174 remains unresolved). No production/fixture/assertion modification without a separately authorized scope/review. Use existing reusable workflow; compile-only if source changes are necessary, execute no tests in CB. Preserve original run 40448739180 and artifacts as invalid-attempt provenance.
- **Exit:** source-verified control-plane fix and compile-only evidence -> repeat the same full-gate TB46 as a distinct artifact-only turn, then apply RA-164.5. If a required semantic/oracle decision cannot be made in Code + Build, stop and route to Review rather than weakening the test. **Do not enter DEFN-E yet.**

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | CB46 | 8 GMP/GMPXX targets, `runtimeExecution=false`. |
| done with S5 stop | `M6-CP3-TB46-RP01-FULL-GATE` (attempt 1) | 504/504, 497/7, harness control contract failure; not accepted. |
| 1 — next | `M6-CP3-TB46A-ORCH` (Code + Build) | Correct S5 orchestration contract without weakening evidence; preserve package/manifest. |
| 2 | `M6-CP3-TB46-RP01-FULL-GATE` (re-execute) | Immutable artifact-only full gate; apply RA-164.5 to authoritative result. |
| gated | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review) → CB47 → TB47 | Only after valid TB46; E: 201, cp3entry:2. |
| later | `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review) → CB48 → TB48 | G: 442, focused30:12, cp3entry:1. |
| later | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review) → CB49 → TB49 | O4/O5, P1-a/P1-b, RA-162 C1, A5 reachability. |
| after green gate | RP-01 Review | Own O6 nonrectangular disk scope. |
| post-RP-01 | O2/T2 DEFN, then DIAG-RETAIN | Preserve original deferred constraints. |
| carried | O1, O6, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002 | Separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **`M6-CP3-TB46A-ORCH`** — RA-164.3 P4 S5 orchestration-only correction. Start with [TB46 report](Architecture_M6_CP3_TB46_Full_Gate_Test_Benchmark_Report_20261027.md), RA-164.5 outcome table, original run `40448739180` raw evidence, and harness `m6_cp3_targeted_artifact_harness.sh` unchanged SHA `436f5fff...3c9a`. Do not re-run tests or rebuild semantic package in the correction turn. Inspect selector174's unlocalized DCEL exception before any later-failure allowance.

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
