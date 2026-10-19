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
| Currency | 2026-10-19, after `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV` (RA-102). The TB16C census is re-verified: 425/497 with 0 status changes against TB14A. B3 is cleared on all 19 and U6 is complete. RP-01 now has one blocker shape: 30 B2 records, all an I–R front ending at rail vertex 4. The R rule is satisfiable on that data, so CB17 (U4, the factory R branch) is next. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Latest semantic source is `7cfa5b4612ed67ec0bbddb747edbc6c53076b781` (test-only; production unchanged from CB16 `1c45e89a`). CB16A package `12193816372` ([run 39266100202](https://github.com/akashskypatel/Directional/actions/runs/39266100202)): ZIP `113a5d8d783dc77f6b60a4da7c338478b3bd753a7e342b01169e4115dc77b2a3`, root manifest `f5ebf229a8ac9fad6a8797aefb36d8acb34a7e7441bb8dd9edb9858b4dfbf556`, source archive `85d487e45086eb0a111207f790e67dcf7069517f1f06f3b3620573d56e29106b`. |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. The R3 baseline (403/497) is `Architecture_M6_CP3_TB1_Entry_R3_Red_Classification.tsv`. |
| Latest candidate or rejected evidence | TB16C [run 39295624822](https://github.com/akashskypatel/Directional/actions/runs/39295624822), result `12207970911` (ZIP SHA-256 `d10553f037a4ae92913db3c07b325636fe221335f79d955258d16b4671874fcb`): **425 PASS / 72 RED**, 497/497 identities; 19/19 prior B3 now B2; exact artifact/postflight immutable. `Architecture_M6_CP3_TB16C_Selector_497_Census_Report_20261019.md` and `Architecture_M6_CP3_TB16C_Selector_497_Red_Inventory.tsv`. No acceptance promotion before Review. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; no production regression. Fixture debt covers 174, 191, 242, 442, 250 and the adjacent-sheet helper (RA-96.6 order). |
| Active boundary | `RP-01` (RA-87.3, RA-102.3):<br>• B1 and B3 are cleared (U3, U6).<br>• B2 is the only blocker: 30 records, one I–R shape (rail 2, chain [1,4,7], route [1-4], R = vertex 4).<br>• U4 = CB17 (factory, RA-102.4), then U5 = CB18 (consumer; spec from TB17-REV).<br>`RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` — EXACT NEXT

- **Type:** Code + Build (U4), compile only. No test execution, TB dispatch or census.
- **Authority:** RA-102.4 in `Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`. Line numbers are at `7cfa5b46`.
- **Scope:** RA-102.4 items 1–9, summarized below.
  - H: append `railVertex` as the **last** member of `SurfaceHardRailRouteEndpointCertificate`.
  - Interval helper: add the defaulted trailing R anchors; an R end must sit strictly inside the chain.
  - New pure helper `open_rail_interior_vertex_valid`: the vertex is strictly interior, appears exactly once, and has exactly its two chain edges as hard spokes.
  - Factory:
    - seed star incidence for interior open-chain vertices;
    - pass the R anchors to the route check;
    - add the R endpoint branch (not a contact endpoint, eligibility, opposite orientation not both Unique; the T clauses shared);
    - reject `railVertex` on closed rails.
  - Digest: hash `railVertex` only when present.
  - Tests: the R rows in `OpenRailRouteChainIntervalTruthTable` and the new `OpenRailInteriorVertexEligibilityTruthTable`. No factory-level R test, because it would be vacuous.
- **Unchanged:** the consumer (no R emission until CB18), probes, and every T, I and C behaviour.
- **Build:** GMP/GMPXX compile and package with the eight CB16A targets. The record is 25 lines or fewer: package ID, ZIP SHA-256, source SHA, `runtimeExecution=false`.
- **Stop:** if a clause cannot be implemented as specified, or needs a line outside these sites, stop and report.
- **Docs:** in place only (handoff live sections, top `TODO.md` section, one `CHANGELOG.md` entry).
- **STATUS:** `IN_PROGRESS` with an empty Successor while working; `COMPLETE` with the successor below as the final write.
- **Conditional successor:** `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` (RA-102.5): the TB16A harness, changing only sha, artifact, digest and labels, plus appended #13 (the eligibility table). Predictions: #1–#7 and #13 PASS; #8–#12 byte-identical to TB16A. Nothing beyond it is authorized.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | Checker rule (RA-97.4). |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | #3 RED (spec defect); B3 → B2 on 10–12. |
| done | `M6-CP3-TB16-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV` | RA-98: CB16 accepted; CB16A specified. |
| done | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-PATCH-REV` | RA-99: the patch conforms; compile only. |
| done | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW` | Compiled `7cfa5b46`; package `12193816372`; no runtime. |
| done | `M6-CP3-CB16A-R10-EXACT-I-WITNESS-UNBOUND-ROW-REV` | RA-100: CB16A accepted; TB16A and TB16C inputs pinned. |
| done | `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS` | Run `39277232731`; all predictions met, 7 PASS / 5 expected RED; no source changes. |
| done | `M6-CP3-TB16A-R10-EXACT-I-ENDPOINT-WITNESS-CHECKERS-REV` | RA-101: re-verified; the U6 gates are closed; TB16C deliverables pinned. |
| done | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS` | 425/497; the 19 former B3 are now B2; no falsifier. |
| done | `M6-CP3-TB16C-R10-SELECTOR-497-CENSUS-REV` | RA-102: census verified; U6 complete; one I–R blocker shape; CB17 specified. |
| 1 — next | `M6-CP3-CB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` | U4, compile only (RA-102.4). |
| 2 — conditional | `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT` | 13 identities (RA-102.5). A falsifier goes to Review. |
| 3 — mandatory | `M6-CP3-TB17-R10-FACTORY-RAIL-VERTEX-ENDPOINT-REV` | Issues the CB18 (U5, consumer emits R) spec. |
| planned, not authorized | CB18 → TB18 (focused run plus census) → TB18-REV → fixture debt (242 → 174 → 250 → adjacent-sheet → 191 → 442) → census → RP-01 Review | Each CB follows a reviewed TB; a RED TB goes to Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code_build** — CB17 (U4, the factory R branch) at `7cfa5b46`; compile only.

Minimum context after mandatory policies/checklists: `.agents/Directional/ORIENTATION.md`, `.agents/Directional/ROADMAP.md`, this handoff, RA-102 (`Architecture_M6_CP3_TB16C_Census_U4_Review_Decision.md`), R10B §2 (`Architecture_M6_CP3_R10B_Rail_Interior_Vertex_Endpoint_Rule_20261017.md`), RA-84.4 (`Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md`), RA-85.4 (`Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md`), S:8249-8286 and S:8676-8935, H:1495-1580, P:2105-2135, P10:7224-7262, `LESSONS.md` §§2, 3, 7, `TODO.md`.

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
