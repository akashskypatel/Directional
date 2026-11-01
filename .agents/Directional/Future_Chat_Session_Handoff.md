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
| Currency | 2026-11-01 **[RA-192](Architecture_M6_CP3_DEFN_P13_Slit_Cycle_Basis_Probe_Adjudication_20261101.md) probe-adjudicated RA-191; CB66 exact patch next.** RA-191's diagnosis stands. Its general edge-side incidence product and open-ended CB66 are replaced by a narrow A1 slit adapter (DESIGN Amendment 25, rewritten). Probes: the 869-row candidate gate is unchanged except O16, and BunnyRandom passes the cut identity and reaches P13-e. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation; immutable semantic source `dbc38661efabdfa051f48f8f71ee3c604841842c`. |
| Last accepted semantic runtime | **CP2 491/491**, accepted 2026-10-06, unchanged. TB63 is a verified Linux candidate, not selector497/CP3 acceptance. |
| Latest candidate | **CB65 compile-only eight-target Linux** [run 41253674256](https://github.com/akashskypatel/Directional/actions/runs/41253674256), artifact `13062413347`, source `dbc38661efabdfa051f48f8f71ee3c604841842c`. Latest runtime TB64 866/866 (run 41256874416, result 13063712419), plus census 1 PASS / 2 pre-registered RED (run 41256885685, result 13064115441). macOS O16 remains. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. Ledger v5 81 rows (47 FIXTURE, 7 PRODUCT, 22 OPEN, 5 RETIRE). TB64 gate membership 947. Selector497 not promoted. DR1/DR3 open; DR2/DR4 → M8-CP2. |
| Active boundary | **CB65 runtime verified by TB64 (866/866 Linux, membership 947, two expected OBSERVE REDs); P13-c has an exact patch (RA-192).** O15c discharged for A2a. BunnyRandom: after CB66 the next failure is A1 `SingularityPortClassCountMismatch` at vertex 49 (P13-e), on macOS and FMA-off. Vase: A7 completion `SideSubdivisionRepair:InvalidInputIncidence` (P13-d/O18), with no slit. O19 (handle generator across a slit, genus > 0 only) is open and not CP3-blocking. No CP3 acceptance. |

## Mandatory next turn — `M6-CP3-CB66-P13-SLIT-CYCLE-BASIS` — EXACT NEXT

- **Type / owner:** Code + Build, implementation agent, Linux workflow runner. Exact patch only; no design latitude, no runtime, no selector promotion. RA-191's `M6-CP3-CB66-P13-CUT-SIDE-INCIDENCE` contract is superseded by [RA-192](Architecture_M6_CP3_DEFN_P13_Slit_Cycle_Basis_Probe_Adjudication_20261101.md) §5 and §8.
- **Precheck:** `git diff --quiet dbc38661efabdfa051f48f8f71ee3c604841842c HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** apply the RA-192.8 block verbatim plus a trailing newline (keep its seven single-space context lines). SHA-256 `c83fefa2298e8fb5fc1b6ef14a8fe47f46ce5cf92d0acc89f4fd6d7da0c4377c`. Run `git apply --check`, then apply.
- **Expected diff:** numstat `1 0` FieldTransportAtlas.h, `173 33` FieldTransportAtlas.cpp, `182 0` FieldAlignedCurveNetworkTests.cpp; result SHA-256s per RA-192.5.
- **Build:** `agent-compile-reusable.yml` with CI flags, eight targets. Record the artifact ID, ZIP and root `SHA256SUMS` SHA-256, and the source-archive SHA-256.
- **Routes:** exact → `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC`; patch, numstat or compile mismatch → `M6-CP3-PLAN-P13-SLIT-STOP` (Review); infrastructure failure → `M6-CP3-CB66A-P13-SLIT-ORCH` (one retry).
- **Carried:** P13-e (BunnyRandom vertex 49) and P13-d/O18 (Vase) are separate Review DEFNs. O19 is open and not CP3-blocking. Stable 66/17/49, debt 1; CP2 491/491; selector497/CP3 not promoted.

## Turn Sequence

| Step | Canonical turn | Track / condition |
|---|---|---|
| 1 — COMPLETE | `M6-CP3-TB64-P13-CANONICAL-DYADIC-FULL-GATE-EXEC` | Linux 866/866, membership 947, Cylinder PASS, BunnyRandom/Vase expected RED |
| 2 — COMPLETE | `M6-CP3-DEFN-P13-SINGLE-EDGE-BARRIER-SLIT` | RA-191 diagnosis, then RA-192 probe adjudication: slit adapter, exact patch, 869 manifest frozen |
| 3 — NEXT | `M6-CP3-CB66-P13-SLIT-CYCLE-BASIS` | Implementation agent, Linux; exact patch, compile only |
| 4 | `M6-CP3-TB65-P13-SLIT-FULL-GATE-EXEC` | Implementation agent, Linux; gate 869/869, membership 950, census 3 per RA-192.6. Mismatch → `M6-CP3-TB65-P13-SLIT-FULL-GATE-REV` (Review); infrastructure → `M6-CP3-TB65A-P13-SLIT-ORCH` |
| 5 (Review, parallel with 3–4) | `M6-CP3-DEFN-P13-VASE-COMPLETION-INCIDENCE` (P13-d with O18) → CB → TB | Probe DEFN, then exact patch |
| 6 (Review, after 4) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) → CB → TB | Probe DEFN, then exact patch |
| 7 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-CB66-P13-SLIT-CYCLE-BASIS** (Code + Build; exact patch).

Read first:
- [RA-192](Architecture_M6_CP3_DEFN_P13_Slit_Cycle_Basis_Probe_Adjudication_20261101.md): §5 CB66 spec, §8 the exact patch, §6 TB65 inputs and outcomes, §7 turn order. DESIGN.md Amendment 25 for the semantics.
- [RA-191](Architecture_M6_CP3_DEFN_P13_Single_Edge_Barrier_Slit_Review_Decision_20261101.md) is history: its diagnosis stands; its incidence product, CB66 scope and falsifiers are superseded (RA-192.1).
- [TB64 report](Architecture_M6_CP3_TB64_P13_Canonical_Dyadic_Full_Gate_Execution_Report_20261101.md) for the last executed gate; do not re-run TB64.

Inputs:

| Input | Value |
|---|---|
| CB66 base | Source `dbc38661efabdfa051f48f8f71ee3c604841842c` (CB65); no semantic change since |
| TB65 gate | Manifest 869 `Architecture_M6_TB65_P13_Slit_Cycle_Basis_Full_Gate_Case_Manifest.tsv` `baaef9e70081dc147fb9a7d91326038c1a4a9708ab1f46fcbfa141a0bf030466` (TB64 866 `289d887c…` byte-identical prefix plus rows 867–869); ledger v5 81 `fd433f54709e9fcb7637977728af00e53810ce86857011f91af8b3ca4fdd64ce`; membership 950 |
| TB65 census | `3af1dc0dfac386f95da1bd9375e1033eadbcca0c7b30c3d0b3b9848ac827e793` |
| Harness | P8 `78b8002c…`, unchanged |

Standing state: CP2 491/491 accepted; stable 66/17/49, debt 1; selector497 unpromoted. O16 (macOS), O17, O18, O19, P13-d, P13-e, DR1/DR3 and DR2/DR4 are carried.

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
