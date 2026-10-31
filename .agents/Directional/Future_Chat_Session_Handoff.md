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
| Currency | 2026-10-31 **RA-188 P13 probe adjudication: the three deferred rows have three different causes. CB64 (chart-binding cache) is next.** [RA-188](Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md) replaces the P13 decision's unstarted CB64/TB63. [TB62 report](Architecture_M6_TB62_Linux_CLI_GUI_Full_Gate_Execution_Report_20261031.md). No CP3 acceptance. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | **CP2 491/491**, accepted 2026-10-06, unchanged. TB62 is a verified Linux candidate, not selector497/CP3 acceptance. |
| Latest candidate | **TB62 Linux ten-target 863/863** [run 41205693716](https://github.com/akashskypatel/Directional/actions/runs/41205693716), result `13046191343` ZIP SHA-256 `95a1b5f87b711e4a9587210fce9ff474623f078726e4c416f47ce2f4d0c5c303`; exact CB63 package `13043004468` source `f6113c4e…`; 11/11 CLI, GUI binary/link checked (no GUI launch). TB61 prior eight-target 863/863; macOS TB60 862/863 with separately carried O16 row283. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged; deferred ledger v4 82 (47 FIXTURE, 7 PRODUCT, 23 OPEN, 5 RETIRE), membership 945; zero new Linux RED. Selector497 not promoted. DR1/DR3 open, DR2/DR4 → M8-CP2, macOS O16 remains. |
| Active boundary | **RA-188: P13-a Cylinder is a performance defect (PASS, 182 s → 7.8 s with CB64); P13-b Vase hits O15c (A4 width about 200 bits per step, fails at step 21); P13-c BunnyRandom hits an Amendment 15 slit gap (two tip–tip single-edge barriers). NEXT `M6-CP3-CB64-P13-CHART-BINDING-CACHE`.** No GUI appearance claim, no CP3 acceptance, no selector promotion. |

## Mandatory next turn — `M6-CP3-CB64-P13-CHART-BINDING-CACHE` — EXACT NEXT

- **Type:** CB (Code + Build); implementation agent; Linux workflow runner. Authority: [RA-188.4](Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md). No Directional runtime.
- **Patch:** the RA-188.8 block, verbatim with a trailing newline, has SHA-256 `fad8986caf897b4fc5eba3f9e667f30518077b81143823e7b65c65314f536c1e`.
  - It changes `SourceChartTransitionGraph::available()`. Instead of re-running the O(F) `matches_source_faces` check on every query, it reads a flag that `build()` sets after its existing check.
  - The design-acceptance `failure_context` gains `detail=<terminalFailureDetailCode>`, with the same line count.
  - No verdict, ordering or output changes.
- **Checks:**
  - Before applying, HEAD must equal `e1fd0e4b7560c4fa5bde96853b978d336c522e8f` in `src include tests benchmarks CMakeLists.txt cmake`.
  - Run `git apply --check`, then apply. The numstat must be exactly `7 4` (`include/directional/geometry/SourceChartTransitions.h`) and `2 2` (`tests/SurfaceCellDesignAcceptanceTests.cpp`).
  - Resulting SHA-256: `aa981c5a916f0ddfff0f4f78fd5acccd3e33148ccbce7a9a7a42f3d1cad256dd` and `fff33d6c1f2b99a92af22ac7fcf24b14ab735ef621eb443a67e5a14ba2422590`.
- **Build:** the standard `agent-compile-reusable.yml` with the CI flags (Release, static, GMP/GMPXX, tests and benchmarks ON, CLI and GUI OFF), eight targets. Record the artifact ID, the ZIP and root `SHA256SUMS` SHA-256s and the source archive SHA-256.
- **Outcomes:**

  | CB64 result | Successor |
  |---|---|
  | Exact, package built | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` |
  | Mismatch | `M6-CP3-PLAN-P13-CHART-BINDING-STOP` |
  | Infrastructure failure | `M6-CP3-CB64A-P13-CHART-BINDING-ORCH`, then one retry |

- **Then `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC`** (TB-EXEC; implementation agent; Linux). It makes two P8 `--execute` runs on the CB64 package (harness `78b8002c…`, unchanged).
  1. **The gate:** TB58 manifest (863 rows, `31c1360a…`) with `MEMBERSHIP_LEDGER` = ledger v4 (82 rows, `36241caa…`). Pre-registered: **863/863**, postflight true, membership 945.
  2. **The census:** `Architecture_M6_TB63_P13_Census_Case_Manifest.tsv` (3 OBSERVE rows, `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793`), with no ledger. Pre-registered:
     - row 1, Cylinder: **PASS**;
     - row 2, BunnyRandom: **RED** with `CutTransportDomainIdentityMismatch` and `cutChi=-3`;
     - row 3, Vase: **RED** with `detail=BranchContinuationExactMagnitudeExceeded`.

  | TB63 result | Successor |
  |---|---|
  | Both as pre-registered | `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` (Review); no TB-REV |
  | Gate RED, or a census difference (a platform split is RA-176) | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-REV` |
  | Membership error | `M6-CP3-PLAN-P13-CENSUS-MEMBERSHIP-STOP` |
  | Orchestration failure | `M6-CP3-CB64A-P13-CHART-BINDING-ORCH` → `…-EXEC-R1` |

- **Out of scope:** any other producer change; gate or ledger edits; Cylinder promotion (owned by the next DEFN); GUI, O16, selector497 or CP3 promotion.

## Turn Sequence

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| 1 — NEXT | `M6-CP3-CB64-P13-CHART-BINDING-CACHE` | CB / implementation agent, Linux | RA-188.8 exact patch; eight-target package |
| 2 | `M6-CP3-TB63-P13-CENSUS-FULL-GATE-EXEC` | TB-EXEC / implementation agent, Linux | Gate 863/863 plus the three-row census, as pre-registered |
| 3 | `M6-CP3-DEFN-P13-O15C-CONTINUATION-WIDTH` | DEFN / Review, probes; may start during steps 1–2 | Vase: chooses the bounded continuation policy (RA-188.3) and promotes Cylinder (manifest 864, ledger v5 81) → CB65 → TB64 |
| 4 | `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` | DEFN / Review, probes; independent of step 3 | BunnyRandom: amends DESIGN Amendment 15 for tip–tip arcs → CB66 → TB65 |
| 5 | P13 re-census → O6 / O9 where reached → matrix 6/6 | per slice | Then retire → FIXTURE → PRODUCT → OPEN → CP3-REV |
| carried | DR1, DR3; DR2/DR4 and O17 → M8-CP2; O2b, O15b, O16 | — | Not P13 |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB64-P13-CHART-BINDING-CACHE** (CB; no runtime).

Read first:
- [RA-188](Architecture_M6_CP3_DEFN_P13_Probe_Adjudication_20261031.md): §4 is the CB, §5 the TB63 inputs, §8 the patch.
- `GitHub_Workflow_Policy.md` and `GMP_COMPILE_POLICY.md`.
- `Patch_Application_Strategy.md`.

Inputs:

| Input | Value |
|---|---|
| Source identity | `e1fd0e4b7560c4fa5bde96853b978d336c522e8f` in code, test and build paths (the CB63 semantic source `f6113c4e…`) |
| TB63 gate | TB58 manifest 863 `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`; ledger v4 82 `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d` |
| TB63 census | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Latest Linux candidate | TB62 863/863 (CB63 package `13043004468`) |

Standing state: CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted. O16 (macOS), DR1/DR3, DR2/DR4 and O17 remain carried.

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
