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
| Currency | 2026-10-18, after `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV` (RA-94): TB14A closed out and adjudicated; DEFN-U6 is next. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Latest semantic source `2ee499a3403c07be05e8084a669f30c1c735f04a` (CB14A, test-only); production code unchanged since CB13 (`70217cc2`). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. The R3 baseline (source `d82e34427`, 403/497) is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv` (SHA-256 `890a105e…`, 94 RED). |
| Latest candidate or rejected evidence | TB14A [run 39143325285](https://github.com/akashskypatel/Directional/actions/runs/39143325285), result `12141843937` (ZIP `1b06e43e…d455`, retained 14 days), on CB14A package `12140756646`: **425/497**. Exactly five tests went RED → PASS against TB13C (199/235/236/294/299), and the 72 REDs are unchanged in substance (RA-94.2). Report: `Architecture_M6_CP3_TB14A_Curved_Disk_Control_Census_Report_20261018.md`. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; no production regression. 425 = 403 + 26 RED → PASS − 4 test-debt REDs (174, 191, 242, 442). Fixture debt also covers 250 and the adjacent-sheet curved-disk helper. See `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` (RA-87.3): B1 cleared (U3); B2 R endpoint → U4/U5, 11 identities; B3 inexact I parameter → U6, 19 identities (first on `cp3entry:2/6`). The curved-disk `make` control is restored (RA-94.4), so U4's precondition is met. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER` — EXACT NEXT

- **Type:** documents-only definition (DEFN absorbs Review + Plan; Turn Cadence). No code, build, dispatch or runtime.
- **Authority:** RA-94.6 in `Architecture_M6_CP3_TB14A_Curved_Disk_Control_Review_Decision.md`; U6 constraints from RA-87.3; R9B:29.
- **Deliverable:** `.agents/Directional/Architecture_M6_CP3_DEFN_U6_Exact_I_Endpoint_Parameter_20261018.md`, 120 lines or fewer, citing `file:line` at `2ee499a3`:
  1. **Producer-origin trace** of the template: `cp3entry:2`, front 17/203, endpoint-1, edge 1–4, faces 0 and 3; hexfloats in TB14A `raw/cp3entry/ordinal-002.log`. Cover every site that writes the compared barycentrics (S:91-97; factory S:8773; consumer S:19480), and say whether the two sides share one scalar and which operation makes the one-ULP difference.
  2. **Candidate exact parameter:** its exact inputs, its type (prefer `ExactSourceEdgePoint`/`FieldExactRational`), its orientation, the single site that computes it, and how it reaches both checkers. Compare the alternatives and recommend one.
  3. **Rule:** exact equality of that parameter, with the doubles used for geometry only. No epsilon, rounding or near-equality canonicalization, and no interval-only identity.
  4. **Satisfiability**, as exact rationals, on all 19 B3 identities (focused30 3/12/14/15/17/18/22/23/24; focused12 5/6; selector 211/217/219/227/230/231; `cp3entry` 2/6), each marked equal, unequal, or missing data (name the field and the probe). Also say what the rule does with RA-76's 324 one-ULP pairs.
  5. **Negatives the CB must test:**
     - crossings one ULP apart stay distinct;
     - 0/1 vertex masquerade rejected;
     - different edge rejected;
     - reversed orientation compares correctly;
     - tampered parameter rejected at the factory.
  6. **Narrow CB units**, each with TB predictions, falsifiers and named controls.
- **If no exact origin exists:** say so with evidence and propose alternatives. Never a tolerance.
- **Out of scope:** U4/U5, fixture debt, test, selector or harness changes.
- **Gates:** `document_drift_audit.py --root .`.
- **Docs:** in place only — handoff live sections, top `TODO.md` section, one `CHANGELOG.md` entry.
- **STATUS:** `IN_PROGRESS` with an empty Successor while working; `COMPLETE` with the successor below as the final write.
- **Conditional successor:** `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER-REV`. Nothing beyond it is authorized.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS` | 425/497; five RED → PASS; closed out by Review. |
| done | `M6-CP3-TB14A-R10-CURVED-DISK-CONTROL-CENSUS-REV` | RA-94: control restored; 199 explained; DEFN-U6 ordered first. |
| 1 — next | `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER` | Documents only (RA-94.6). |
| 2 — conditional | `M6-CP3-DEFN-U6-EXACT-I-ENDPOINT-PARAMETER-REV` | Accepts or amends U6 units, authorizes CB15 (U4), schedules fixture debt. |
| planned, not authorized | `M6-CP3-CB15-R10-FACTORY-RAIL-VERTEX-ENDPOINT` → TB15 → `M6-CP3-CB16-R10-CONSUMER-RAIL-VERTEX-ENDPOINT` → TB16 → U6 CB/TB units → RP-01 Review | Each CB follows a reviewed TB; a RED TB goes to Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **definition** — documents-only U6 design from source and retained TB14A raw logs; no code, build or runtime.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-94 (`Architecture_M6_CP3_TB14A_Curved_Disk_Control_Review_Decision.md`), RA-87 (`Architecture_M6_CP3_TB12_Chain_Provenance_Review_Decision.md`), the R9B contract (`Architecture_M6_CP3_R9B_Endpoint_Equivalence_Contract_Specification_20261016.md`), `Architecture_M6_CP3_TB13C_Selector_497_Red_Inventory.tsv`, TB14A result `12141843937`, `LESSONS.md` §3–§5, `TODO.md`.

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
