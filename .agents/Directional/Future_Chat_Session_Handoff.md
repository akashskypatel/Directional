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
| Currency | 2026-10-18, after `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE-REV` (RA-96): U6A trace accepted. Representation amended: a canonical witness inside `SurfaceTracePoint`, bound bit for bit to one rounding helper. U6 goes first as CB15 (producer witness, no admission change), then CB16 (checkers). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Latest semantic source `2ee499a3403c07be05e8084a669f30c1c735f04a` (CB14A, test-only); production code unchanged since CB13 (`70217cc2`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. The R3 baseline (source `d82e34427`, 403/497) is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED). |
| Latest candidate or rejected evidence | TB14A [run 39143325285](https://github.com/akashskypatel/Directional/actions/runs/39143325285), result `12141843937` (ZIP `1b06e43e…d455`, retained 14 days), on CB14A package `12140756646`: **425/497**. Exactly five tests went RED → PASS against TB13C (199/235/236/294/299), and the 72 REDs are unchanged in substance (RA-94.2). Report: `Architecture_M6_CP3_TB14A_Curved_Disk_Control_Census_Report_20261018.md`. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; no production regression. 425 = 403 + 26 RED → PASS − 4 test-debt REDs (174, 191, 242, 442). Fixture debt also covers 250 and the adjacent-sheet curved-disk helper. See `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-87.3): B1 cleared (U3); B2 R endpoint → U4/U5 (now CB17/CB18), 11 identities; B3 inexact I parameter → U6 (CB15/CB16), 19 identities, one template (RA-95.2). B3 origin: one exact `location_parameter` that `boundary_trace_point` rounds per orientation (RA-95.3, verified by U6A). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` — EXACT NEXT

- **Type:** Code + Build, compile only. No test execution, dispatch of TB, census or admission change.
- **Authority:** RA-96.4 in `Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`, amending the U6A deliverable as RA-96.2 A1–A4.
- **Scope:**
  1. H:90-93 `SurfaceTracePoint` gains `std::optional<authority::ExactSourceEdgePoint> exactEdgePoint` (comment: provenance, never identity unless bound). Include `ExactSourcePath.h`.
  2. Detail helpers declared beside H:1557:
     - `accepted_boundary_trace_point`: the S:16944-16972 arithmetic unchanged, plus a witness only when `canonical_exact_source_edge_point` yields an edge point. The lambda calls it.
     - `exact_interior_witness_binds`: the edge is the carrier edge, the face contains both edge vertices, and the doubles equal the helper's output bit for bit for one orientation.
  3. Dedup (S:17190-17194): if the two witnesses differ, clear the kept point's witness. Never reject.
  4. Probe: after the `railEnd` loop (S:20092-20100), append `a2bProbeFromExact`, `a2bProbeFromExactBinds`, `a2bProbeToExact` and `a2bProbeToExactBinds`, formatted like the ordinals (S:19858-19864).
  5. Unchanged: S:64-97, factory S:8773, consumer S:19480, S:20065, other producers.
  6. Three P10 tests (RA-96.4 item 6), compiled, not run.
- **Build:** GMP/GMPXX compile and package. Record of 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.
- **Stop:** if a compile-time constraint forbids the field, stop and report; no workaround.
- **Docs:** in place only (handoff live sections, top `TODO.md` section, one `CHANGELOG.md` entry).
- **STATUS:** `IN_PROGRESS` with an empty Successor while working; `COMPLETE` with the successor below as the final write.
- **Conditional successor:** `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` (RA-96.5: nine identities; predictions and falsifiers there). Nothing beyond it is authorized.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE` | Trace verified; representation (a) recommended. |
| done | `M6-CP3-DEFN-U6A-I-ENDPOINT-EXACT-ORIGIN-TRACE-REV` | RA-96: accepted with amendments A1–A4; U6 first; IDs renumbered. |
| 1 — next | `M6-CP3-CB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` | Compile only (RA-96.4). |
| 2 — conditional | `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER` | Nine identities (RA-96.5). A falsifier goes to Review. |
| 3 — conditional | `M6-CP3-TB15-R10-EXACT-I-ENDPOINT-WITNESS-PRODUCER-REV` | Issues the CB16 spec (checkers use the bound witness). |
| planned, not authorized | `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` → TB16 → REV → `M6-CP3-CB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` → TB17 → `M6-CP3-CB18-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` → TB18 → fixture debt (242 → 174 → 250 → adjacent-sheet → 191 → 442) → census → RP-01 Review | Each CB follows a reviewed TB; a RED TB goes to Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code_build** — CB15 compile-only producer witness at `2ee499a3`; no test execution.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-95/RA-96 (`Architecture_M6_CP3_DEFN_U6_Exact_I_Origin_Review_Decision.md`), `Architecture_M6_CP3_DEFN_U6A_I_Endpoint_Exact_Origin_Trace_20261018.md`, `include/directional/authority/ExactSourcePath.h`, `src/geometry/SurfaceCellTracing.cpp` S:16944-17300 and S:19840-20105, `include/directional/geometry/SurfaceCellTracing.h` H:90-93 and H:1550-1570, `LESSONS.md` §3, §4 and §7, `TODO.md`.

**Review tooling:** `.agents/Directional/tools/` holds read-only `review_check.py`, `selector_probe.py`, and `fixture_probe.py`; history-sensitive review gates require real committed history, not a synthesized snapshot.

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
