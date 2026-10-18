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
| Currency | 2026-10-18, after `M6-CP3-TB11-R10-OPEN-RAIL-ROUTE-ANCHOR-REV` (RA-85) |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft; refetch HEAD before mutation. Semantic source `9432aa05e` (CB11). |
| Last accepted semantic runtime | M6 CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. |
| Latest candidate or rejected evidence | TB11 run `39092477302`, result `12123605663`, on CB11 package `12121016836`: truth table PASS; two midline-fixture tests RED at `open-rail-route-anchor`, front 29/147. The fixture has never been `Produced`; **not a regression** (RA-85.2). Not promoted. |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 **403/497** rejected; `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01`: two blockers on subdivided open rails, the R endpoint (vertex 4) and I–I middle fronts. RA-85.4 replaces the terminal anchor with an open-chain interval rule; units U2–U5 (RA-85.5). Only U2 is authorized. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` — EXACT NEXT

- **Type / owner:** `CB` (compile only); unit U2 of RA-85.5.
- **Objective:** carry each open hard rail's ordered source-vertex chain to `SurfacePhaseFrontProduct::make`, validate it there, and expose it on the product. Admission is unchanged.
- **Read before work:** RA-85 and RA-84 records (RA-84.2, RA-84.4.3); `RemeshPipeline.cpp:9727-9767`, `:12476-12485`; `SurfaceCellTracing.cpp` closed-chain entry validation in `make` and the `publish_phase_front_result` call in the consumer; `SurfaceCellTracing.h:1534-1560`, `:1912-2030`, `:2246-2248`, `:2733`.
- **In scope:**
  1. Add `SurfaceHardRailOpenChain{component, vertices}` and a `SurfaceHardRailOpenChains` map keyed by `HardRailId`, beside the closed-chain type.
  2. `hard_rail_source_provenance_from_rails` also emits each open rail's full ordered `sourceVertices`; declare it in a header.
  3. Wire `SurfaceCellTracingOptions::hardRailOpenChains` → consumer publish call → `publish_phase_front_result` → `make` (trailing defaulted parameter) → product accessor `hardRailOpenChains()`.
  4. Add one pure detail validator, called at `make` entry beside the closed-chain check, that fails with `InvalidSourceAuthority`. For each chain it requires:
     - the rail has a terminal contact and no closed chain;
     - the component is ≥0 and equals the contact's component;
     - at least 2 vertices, all distinct;
     - the ends equal the contact's endpoints, in either order;
     - each consecutive pair is a valid edge, in `hardFeatureEdges`, and inside a source face of the component.

     When the map is non-empty, its rail ids equal the terminal-contact rail ids. An empty map is not checked.
- **Out of scope:** any admission or route-rule change (U3–U5); a ≥3-vertex rule; cross-rail edge uniqueness or coverage; I/C branches; tolerance; selector/harness/workflow/benchmark; running tests.
- **Success evidence (compiled tests, expectations written by hand):**
  - The real `build_authoritative_surface_cell_rails` run on the midline fixture projects chains equal to each rail's `sourceVertices` (e.g. `[1,4,7]`), with ends equal to its contact.
  - The validator accepts that projection, using the fixture's hard edges and `build_source_topology_regions`.
  - One tamper per clause is rejected: missing middle vertex, duplicate vertex, wrong component, rail id absent from the contacts, rail id also closed, ends ≠ contact, chain edge removed from `hardFeatureEdges`, 1-vertex chain.
  - A 2-vertex chain is valid.
  - Package ID and source SHA recorded, `runtimeExecution=false`.
- **On success:** `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE`. Prediction: TB11's three tests are unchanged.
- **On failure/blocker:** `UNKNOWN — STOP`; orchestration failures follow `Turn_Cadence.md` rule 5.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | Implementation; U2 only, compile only. |
| 2 — conditional | `M6-CP3-TB12-R10-OPEN-RAIL-CHAIN-PROVENANCE` | Only after CB12 is packaged and its diff reviewed. It runs CB12's tests and TB11's three tests; the TB11 locus is predicted unchanged. A red result goes to Review. |

U3–U5 (`CB13`–`CB15`, each followed by its TB) are frozen in RA-85.5. Each needs a reviewed predecessor TB; anything beyond is `UNKNOWN`.

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — use the turn-based-coding-agent Code + Build guidance; no runtime execution.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_TB11_Route_Anchor_Review_Decision.md` (RA-85), `Architecture_M6_CP3_R10B_Endpoint_Rule_Review_Decision.md` (RA-84), `Architecture_M6_Frozen_Definitions.md` RA-84/RA-85, `GMP_COMPILE_POLICY.md`.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats. History gates (`authority|boundary|ledgers`, drift `--base`) are Review gates (RA-82.3); implementation turns run `document_drift_audit.py --root .` only.

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
