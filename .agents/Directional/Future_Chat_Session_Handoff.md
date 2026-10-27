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
| Currency | 2026-10-27, after [RA-165](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md) (TB46A-REV): selector174 has **two** invalid TriMesh fixtures: isolated vertex 4 at `REPackageTests:439`, and all-boundary isolated triangles at `:569` (thrown since `b43fa8e95`, 10-14). Scratch probes: P0 reproduces TB46 row216 exactly; the TB46A fix alone (P1) still throws; both fixes (P2) pass the whole body. RA-164 H1 throw site corrected. TB46A harness `5e6de03fa` accepted. Line-neutral fixture CB46B authorized. RA-164.3 P1–P6 + RA-165.2 F1/F2 bind. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | TB46 run `40448739180` on CB46 package `12708707491`: 504/504 processes, 497 PASS / 7 RED, **invalid attempt (S5)** ([report](Architecture_M6_CP3_TB46_Full_Gate_Test_Benchmark_Report_20261027.md)); 497 GUARD green, 5 pinned REDs at pins, 174 uncaught DCEL exception, cp3entry:4 later `TQTests:4063`. TB46A harness compile run `40457083585` ([record](Architecture_M6_CP3_TB46A_Orchestration_Correction_Compile_Record_20261027.md)). Last valid full gate TB38 **490/504** candidate (`038ae7fd7`); no production change since. Selector497 frozen, unpromoted. |
| Regression accounting and debt | Stable **66/17/49**, debt 1 ([tracker](Regression_Root_Cause_Tracker.md)). No new stable event. |
| Active boundary | RP-01 open, RP-02 unreached. TB46 re-run predicted **498/6**: RED `selector:201`, `selector:442`, `focused30:12`, `cp3entry:1`, `cp3entry:2` at pins; cp3entry:4 RED at registered `:4063` (cluster E, D5); 174 PASS. Harness pins are hard-coded `file:line` until CB47A → edits above pinned lines must be line-neutral. Carried: O1, O2 (post-RP-01, + RA-161 T2), O6, **O7** (oracle-tests target non-compiling, RP-01 decides owner), DIAG-RETAIN, RA-152.5, DEFN-SEAM-NZ (+RA-163.4), RA-146.2/4, RA-45.4, G4-B002. |

## Mandatory next turn — `M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE` — EXACT NEXT

- **Authority:** [RA-165.3](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md). Test-only Code + Build, compile only, **line-neutral** (`git diff --numstat` equal +/− for `tests/SurfaceCellREPackageTests.cpp`; no other file).
- **Allowlist:** exact text in RA-165.3. F174-a `REPackageTests:439`, 1→1 line: `ASSERT_NO_THROW(manifoldHardSource.set_mesh(incidenceVertices.topRows(4), incidenceFaces));`. F174-b `:430–432`, comment 3→3 lines. F174-c `:564–569`, 6→6 lines: an 8-vertex, 4-face two-component source (adds faces `1,6,2` and `4,7,5`) and `ASSERT_NO_THROW` on `set_mesh`. F174-d `:561–562`, comment 2→2 lines. Expected numstat `12 12`. No assertion, helper, harness, manifest, workflow or production change.
- **Evidence:** established eight GMP/GMPXX targets (as run `40457083585`), `runtimeExecution=false`, record ≤25 lines with numstat and package ID.
- **Outcome table:** compile OK + allowlist + line-neutral → `M6-CP3-TB46-RP01-FULL-GATE` (re-run on CB46B package, harness `37b01215…`, manifest `717f4f0f…`, predict 498/6, table RA-165.4); C2 → in-hunk fix ≤2 attempts; S1/S2/S3/non-neutral → `M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE-REV`; orchestration → Turn_Cadence rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | RA-164 → CB46 → TB46 (S5) → TB46A-ORCH → RA-165 | TB46 invalid attempt; harness fail-closed correction accepted; 174 fixture authorized. |
| 1 — next | `M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE` | Line-neutral F174-a–d (`:439`, `:564–569`, and the two comments); 8 targets; → step 2 directly. |
| 2 | `M6-CP3-TB46-RP01-FULL-GATE` (re-run) | CB46B package; predict 498/6; exit 0 → step 3; `control_violation` → TB46-REV; infra → `M6-CP3-TB46B-ORCH`. |
| 3 | `M6-CP3-DEFN-RP01-TB46-ENDPOINT-CLUSTER` (Review) | Decides E: 201, cp3entry:2, cp3entry:4 D5 (`:4063`) from D1/D2 harvest; freezes TB47 manifest with `asserted_site` = `file:line\|witness`. |
| 4 | `M6-CP3-CB47A-HARNESS-MANIFEST-PINS` ∥ CB47 → `M6-CP3-TB47-RP01-FULL-GATE` | CB47A tool-only: pins from manifest; offline replay of step-2 logs reproduces verdicts; pin mutation fails closed. |
| 5 | `M6-CP3-DEFN-RP01-TB47-GAUGE-CLUSTER` (Review) → CB48 → `M6-CP3-TB48-RP01-FULL-GATE` | G: 442, `focused30:12`, cp3entry:1; RA-163 R2. |
| 6 | `M6-CP3-DEFN-RP01-O4-O5-RAIL-PROVENANCE` (Review) → CB49 → TB49 | O4, O5, P1-a/P1-b, RA-162 C1, H2 A5 reachability. |
| 7 | Green full gate → RP-01 Review | States O6 CP3 scope and O7 owner. |
| post-RP-01 | `M6-CP3-DEFN-POSTRP01-O2-NO-ATLAS-INGRESS-RETIREMENT`, then `DIAG-RETAIN` | RA-160.4 + RA-161 T2. |
| rule | RA-164.3 P1–P6; RA-165.2 F1/F2 | CB→TB direct; full-gate TBs; red TB → Review DEFN; STOP codes; outcome rows must map to harness branches; line-neutral above pins until CB47A. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB46B-RP01-SELECTOR174-MANIFOLD-FIXTURE** — read [RA-165.3](Architecture_M6_CP3_TB46A_REV_Selector174_Manifold_Fixture_Authorization_Decision_20261027.md), `tests/SurfaceCellREPackageTests.cpp:425–460, 556–570`, `include/directional/core/TriMesh.h:155–162, 331–340`, `include/directional/core/DCEL.h:50–57, 1255–1265`; compile caller as in run `40457083585` (eight targets). No runtime, harness, manifest or production edits.

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
