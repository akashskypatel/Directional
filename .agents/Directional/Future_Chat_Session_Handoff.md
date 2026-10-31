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
| Currency | 2026-10-31 **CB62 Linux compile package complete** ([record](Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md)); immutable eight-target GMP package artifact `13034987618` from source `e7c27b0a5f53788569109c85a028e3be44035aaf`; no native runtime. TB57–TB60 ran only on macOS arm64 and TB60 remains **862/863** (O16 row 283). Linux TB61 is next; DR1 and DR3 open; DR2 and DR4 → M8-CP2. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB60 862/1 macOS candidate** (CB61 `e1fd0e4b…`, 863 gated; [report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md)); not yet run on Linux CI. The prior reviewed macOS candidate is TB54 856/1 (RA-181). **TB52 853/0** is the latest reviewed Linux candidate (RA-177). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 82 DEFERRED ([ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv)): FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. RP-01 closed (RA-179); O15 discharged (RA-181); O15c is owned by P13. A Linux CI full gate of current source is carried (TB58 manifest, rows 854–863 not yet run on Linux); on Linux, row 283 is expected to PASS, because it fails only on macOS (O16). |
| Active boundary | **NEXT `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC`** (TB-EXEC, I, Linux workflow runner): execute immutable CB62 package artifact `13034987618` with TB58 manifest 863 and ledger v4 82; pre-registered 863/863, membership 945. Then `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` (R) before P13. No CP3 acceptance. |

## Mandatory next turn — `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC` (type TB-EXEC; implementation agent; Linux workflow runner) — EXACT NEXT

- **Authority:** user direction 2026-10-31; [CB62 record](Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md) and the CB62 immutable GMP Linux package. `M6-CB62-DIAG-RETAIN-LINUX-PACKAGE` is complete; source `e7c27b0a5f53788569109c85a028e3be44035aaf` is semantically identical to CB61 `e1fd0e4b…` in all six protected code/test/build paths.
- **Execution:** use `.agents/Directional/tools/m6_cp3_targeted_artifact_harness.sh` (SHA-256 `78b8002c2973db7cbe05e880b020945cec9e7aee2814d8d4ff48a2e053f13e94`) on immutable package artifact `13034987618`. Use `Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv` (863 rows, SHA-256 `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`) and `MEMBERSHIP_LEDGER`=`Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv` (82 rows, SHA-256 `36241caa61d3d27aa062fee05cf3af12a62a81a5a11a42e3ea75e46b0590139d`). Fresh process per identity. No configuring, compiling, relinking, repairing package bytes, source editing, or gate mutation.
- **Pre-registered result:** **863/863 PASS**, including row 283 (macOS O16), postflight true, harness exit zero, membership **945**. Preserve every actual outcome including unexpected RED/ABNORMAL.
- **On result:** every result goes to `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` (TB-REV, R). An orchestration failure routes to a CB orchestration fix and re-run (`Turn_Cadence.md` §5).
- **After independent TB61-REV:** if confirmed, proceed to `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`; any Linux-only red → `M6-PLAN-DIAG-RETAIN-LINUX-SPLIT-STOP` (PLAN, R). The Review also decides whether Linux CLI/GUI compilation of CB60/CB61 is owed.

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | RP-01 closure (RA-174…RA-179) → O15 (RA-180/RA-181) → row 935 (RA-182, TB55) → O2 entry gate (RA-183, TB56) → DIAG-RETAIN snapshots (RA-184, CB58, TB57) → display adapter (RA-185, CB59, TB58) → CLI sidecar (RA-186, CB60, TB59) → GUI layers (RA-187, CB61, TB60): DIAG-RETAIN closed | — | History is in `CHANGELOG.md` and the records. Latest gate: TB60 862/863 on macOS arm64 (not yet on Linux CI): 863 gated, [ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv) 82, membership 945. |
| 1 — NEXT | `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC` → `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` | TB-EXEC / I (Linux workflow runner); TB-REV / R | CB62 GMP Linux package verified (artifact `13034987618`); gate TB58 manifest 863 + ledger v4 82, membership 945; 863/863 expected. |
| 2 | `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` (Cylinder first; O6, exact-atlas, O9 and O15c checks) | DEFN / R | RA-174.3 and the ledger v4 P13 rows 360 BunnyRandom (RED), 362 Cylinder, 365 Vase (CI timeout 124; Cylinder completed in 179 s in a probe without the CI limit). Bounded per-fixture probes (300 s); frozen P13 slices or a PLAN stop. |
| 3 | retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | DR1 (needs an A6/A7 rejection stimulus), DR3, DR2 and DR4 (→ M8-CP2); O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). CB and TB run on the Linux workflow runner; a TB always runs the full current gate, even after a CLI- or GUI-only CB (RA-187). The current gate is the TB58 manifest (863 rows) with ledger v4 (82). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC** (TB-EXEC, implementation agent, Linux workflow runner). Package artifact `13034987618` from CB62, source `e7c27b0a5f53788569109c85a028e3be44035aaf`, exact package outer SHA-256 `81c66418420b64c466e4b6c89d79129ef8ba4adbe6981469624d781644d91de5`; [CB62 record](Architecture_M6_CB62_Diag_Retain_Linux_Package_Code_Build_Record_20261031.md). Execute only the immutable TB58 863-row gate (`31c1360a…`) with deferred ledger v4 82 (`36241caa…`), membership 945, pre-registered 863/863 PASS. Route to `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` irrespective of verdict; then P13 only upon confirmed independent review. CP2 491/491 remains last accepted, stable 66/17/49, debt 1.

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
