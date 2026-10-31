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
| Currency | 2026-10-31 **DIAG-RETAIN closed** (RA-184…RA-187; CB58–CB61; [CB61 record](Architecture_M6_CB61_Diag_Retain_GUI_Layers_Code_Build_Record_20261031.md), [TB60 report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md)). Source `e1fd0e4b…` adds the A5–A7 snapshots, their display adapter and text dump, the CLI `<prefix>.materialization.txt` sidecar and three GUI layers. TB57–TB60 ran on macOS arm64 only; the latest, TB60, gave **862/863** on the 863-row TB58 manifest (only row 283, the macOS-only O16 failure), membership 945. Open: DR1, DR3; DR2 and DR4 → M8-CP2. CB and TB turns run on the Linux workflow runner. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing` / verify fresh before mutation. |
| Last accepted semantic runtime | CP2 **491/491** accepted 2026-10-06 (selector449 `d4a0d1b7…d6414`, focused12 `2aa57aac…c67374ed`). Nothing newer is accepted. |
| Latest candidate or rejected evidence | **TB60 862/1 macOS candidate** (CB61 `e1fd0e4b…`, 863 gated; [report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md)); not yet run on Linux CI. The prior reviewed macOS candidate is TB54 856/1 (RA-181). **TB52 853/0** is the latest reviewed Linux candidate (RA-177). Last accepted CP2 491/491. |
| Regression accounting and debt | Stable **66/17/49**, debt **1**, unchanged. 82 DEFERRED ([ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv)): FIXTURE 47, PRODUCT 7, OPEN 23, RETIRE 5. RP-01 closed (RA-179); O15 discharged (RA-181); O15c is owned by P13. A Linux CI full gate of current source is carried (TB58 manifest, rows 854–863 not yet run on Linux); on Linux, row 283 is expected to PASS, because it fails only on macOS (O16). |
| Active boundary | **NEXT `M6-CB62-DIAG-RETAIN-LINUX-PACKAGE`** (CB, I, Linux workflow runner): build a Linux package of the current source, then `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC` (I) and `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` (R) confirm CB58–CB61 on Linux before `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`. CP2 491/491 last accepted; CP3 not accepted. |

## Mandatory next turn — `M6-CB62-DIAG-RETAIN-LINUX-PACKAGE` (type CB; implementation agent; Linux workflow runner) — EXACT NEXT

- **Authority:** user direction (2026-10-31): confirm CB58–CB61 on Linux before the P13 DEFN. TB57–TB60 ran only on macOS arm64.
- **Source:** no patch. Dispatch the branch HEAD, whose `src/`, `include/`, `tests/`, `benchmarks/`, `CMakeLists.txt` and `cmake/` must be identical to CB61 `e1fd0e4b7560c4fa5bde96853b978d336c522e8f` (`git diff --quiet e1fd0e4b… HEAD -- src include tests benchmarks CMakeLists.txt cmake`).
- **Build:** the standard compile workflow (`agent-compile-reusable.yml`) with the CI flags: Release, static, GMP, tests and benchmarks ON, the eight targets. Publish the immutable package artifact and record its artifact ID, ZIP SHA-256, root `SHA256SUMS` and source archive SHA-256. No native tests. The standard package does not build the CLI or the GUI.
- **Outcomes:**
  - Package built and source identity exact → `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC`.
  - Source differs from `e1fd0e4b…` → `M6-PLAN-DIAG-RETAIN-LINUX-SOURCE-STOP` (PLAN, R).
  - Infrastructure failure → `M6-CB62A-DIAG-RETAIN-LINUX-ORCH`, then one retry.

**Then `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC`** (TB-EXEC, I, Linux workflow runner): run the P8 harness (`tools/m6_cp3_targeted_artifact_harness.sh`, SHA-256 `78b8002c…`) on the CB62 package over the gate [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv) (863 rows, `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`) with `MEMBERSHIP_LEDGER` = [ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv) (82 rows, `36241caa…`). Pre-registered: **863/863 PASS** (row 283 included, because its failure is macOS-only), postflight true, harness exit 0, membership **945**. Every result goes to `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV`; an orchestration failure goes to a CB orchestration fix and a re-run (`Turn_Cadence.md` §5).

**Then `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV`** (TB-REV, R): verify the result against the pre-registration and review CB58–CB61 on Linux. Check rows 854–863 (854–855 RP-01, 856–857 O15, 858 row 935, 859 O2, 860–861 A5–A7 snapshots, 862–863 display adapter). Compare every verdict with TB60 (macOS; the only expected difference is row 283). Decide whether a Linux compile of the CLI and GUI (CB60, CB61) is owed. A confirmed result → `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`; any Linux-only red is a determinism defect (RA-176) → `M6-PLAN-DIAG-RETAIN-LINUX-SPLIT-STOP` (PLAN, R).

## Turn Sequence

Canonical types: CB, TB-EXEC, TB-REV, DEFN, PLAN (`turn_type_from_turn`). **I** = implementation agent (exact patches and frozen manifests only); **R** = probe-capable Review agent. ∥ marks steps that may run in parallel.

| Step | Canonical turn | Type / track | Condition / boundary |
|---|---|---|---|
| done | RP-01 closure (RA-174…RA-179) → O15 (RA-180/RA-181) → row 935 (RA-182, TB55) → O2 entry gate (RA-183, TB56) → DIAG-RETAIN snapshots (RA-184, CB58, TB57) → display adapter (RA-185, CB59, TB58) → CLI sidecar (RA-186, CB60, TB59) → GUI layers (RA-187, CB61, TB60): DIAG-RETAIN closed | — | History is in `CHANGELOG.md` and the records. Latest gate: TB60 862/863 on macOS arm64 (not yet on Linux CI): 863 gated, [ledger v4](Architecture_M6_CP3_RP01_Off_Gate_Deferred_Ledger_v4.tsv) 82, membership 945. |
| 1 — NEXT | `M6-CB62-DIAG-RETAIN-LINUX-PACKAGE` → `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC` → `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV` | CB, TB-EXEC / I (Linux workflow runner); TB-REV / R | Linux confirmation of CB58–CB61: package of source `e1fd0e4b…`; gate TB58 manifest 863 + ledger v4 82, membership 945; 863/863 expected. |
| 2 | `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE` (Cylinder first; O6, exact-atlas, O9 and O15c checks) | DEFN / R | RA-174.3 and the ledger v4 P13 rows 360 BunnyRandom (RED), 362 Cylinder, 365 Vase (CI timeout 124; Cylinder completed in 179 s in a probe without the CI limit). Bounded per-fixture probes (300 s); frozen P13 slices or a PLAN stop. |
| 3 | retire CB → FIXTURE slices → PRODUCT CBs → OPEN probe DEFNs (P02a, P02b, P07b, P09b, P12b, P14c, O7, O8, O10) → CP3-REV | per slice | RA-174.3 CP3-exit conditions; each slice moves its rows from the ledger to the gate. |
| carried | DR1 (needs an A6/A7 rejection stimulus), DR3, DR2 and DR4 (→ M8-CP2); O2b (no-atlas API and legacy-branch retirement); O16 (row 283, LegacyInteger macOS); O15b; O15c | — | RA-179.4, RA-181.2, RA-183.2. |
| rule | RA-167.6 naming; one CB per patch; no R1…Rn loops | — | Every gate run needs `MEMBERSHIP_LEDGER`. A DEFN must have a reachable exit (RA-172.1). CB and TB run on the Linux workflow runner; a TB always runs the full current gate, even after a CLI- or GUI-only CB (RA-187). The current gate is the TB58 manifest (863 rows) with ledger v4 (82). |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CB62-DIAG-RETAIN-LINUX-PACKAGE** (CB, implementation agent, Linux workflow runner). No patch: confirm that HEAD's source equals CB61 `e1fd0e4b…`, run the standard compile workflow with the CI flags and record the package identity. Next `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-EXEC` (TB58 manifest 863 `31c1360a…`, ledger v4 82, membership 945; 863/863 expected) and `M6-TB61-DIAG-RETAIN-LINUX-FULL-GATE-REV`, then `M6-CP3-DEFN-P13-DESIGN-ACCEPTANCE-MATRIX-PROBE`. The latest gate is TB60 862/863 on macOS ([report](Architecture_M6_TB60_Diag_Retain_GUI_Full_Gate_Local_Test_Report_20261031.md)). CP2 491/491 last accepted; stable 66/17/49, debt 1.

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
