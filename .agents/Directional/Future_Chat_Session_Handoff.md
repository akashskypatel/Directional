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
| Currency | 2026-10-20, TB19-REV (RA-110). The TB19A report is accepted and TB19A is closed by Review. All nine M2 identities reject at the gauge pin: the rectangle on rail carrier (1,4), the torus on minor-cycle hard edge {0,3}. H-pin is CONFIRMED: the producers establish face gauges per region and skip accepted cut edges, but the pin checks every two-face edge. The R-route is NOT REACHED. Next: DEFN-P1 defines the corrected pin domain (documents only). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`. |
| Last compiled semantic source | CB19A eight-target GMP/GMPXX compile [39446712217](https://github.com/akashskypatel/Directional/actions/runs/39446712217), package `12275794192`, ZIP SHA-256 `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`; hashes `28/28`, statuses clean, `runtimeExecution=false`; expires 2026-10-27T15:24Z; accepted by RA-107. Record: `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate / rejected evidence | TB19A: run `39484475466`, artifact `12292268624` (ZIP `25d48ed7…7efa7c`), expires 2026-11-03; 7/7 selected, control `selector:443` PASS, 6 torus RED at `gauge-pin-consistency;edge=0,3`; report `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`, accepted by RA-110. TB19: run `39464430751`, artifact `12285225197` (ZIP `2b5dfacf…dec0`), expires 2026-11-03; 16 valid rows; report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`, accepted by RA-109. TB18 Part A `12231529583` (12/14) and Part B `12232299548` (448/497), expire 2026-11-03; candidate evidence per RA-105. First failures: `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`. |
| Regression accounting | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected, TB18 candidate 448/497. |
| Active boundary | `RP-01` open. M2 = H-pin, CONFIRMED by RA-110.3: the pin (S:8509–8567) checks edges no producer relates. All nine M2 identities stop there, so the RA-103.5 R-route falsifier stays undetermined until the first TB after the correction. M1 certificate shadowing (10 identities, RA-105.3) is unchanged; its DEFN follows TB20-REV. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN` — EXACT NEXT

- **Type / owner:** Definition, documents only; implementation agent. Authority: RA-110.4 and RA-110.5 (`Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md`).
- **Objective:** define the exact domain of the RA-45.3 gauge pin as one predicate over `SurfacePhaseFrontProduct::make`'s inputs, matching the edges over which the producers establish the face gauge.
- **Read before work:**
  - RA-110 and RA-105.4;
  - RA-45 and RA-31a.1, RA-33.3, RA-34.3 in `Architecture_M6_Frozen_Definitions.md`;
  - S:8509–8567 (the pin), S:8717–8732 (`rail-transition-a3`), S:13104–13107, S:18336–18352 (producer dispatch);
  - the three producers: `build_uniform_phase_front_for_faces` (S:13178), `build_periodic_annulus_phase_front_for_faces` (S:13997), `build_curved_bounded_disk_phase_front_for_faces` (S:15284; cut set S:15333, S:15532, S:16000, S:16217, S:16346).
- **In scope:** the record `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Definition_Record_<date>.md`, containing:
  1. a producer table: function and S range, gauge root rule, and the two-face edges excluded from its gauge domain, with S lines;
  2. whether every `acceptedCutEdges` member (S:15532) is in `hardFeatureEdges`, by S-line proof or counterexample;
  3. whether the two faces at torus edge {0,3} share a topology region, statically, or a statement that this cannot be decided statically;
  4. the corrected domain as one predicate over `make`'s inputs, and a table naming the `make` clause that authenticates each excluded edge class, or the gap;
  5. a consumer census: does any production consumer read a face-gauge difference across an excluded edge (RA-45.1)? Give S and `RemeshPipeline.cpp` lines;
  6. an oracle plan for the later CB, not executed:
     - the nine M2 identities are predicted only to pass the pin;
     - the `SurfaceCellFactoryRejectionSite` negative still rejects, at (0,4);
     - at least one proposed negative shows a one-face gauge change inside a hard-feature region's gauge domain still rejects.
- **Out of scope:**
  - code, tests, builds, runs and dispatches;
  - the M1 binding (RA-105.3);
  - the R-route;
  - fixture debt;
  - edits to frozen RA text.
- **Success evidence:** the record answers items 1–6 with S lines; the predicate uses only `make` inputs, or names the one minimal added input; nothing outside the record (and the end-of-turn docs) changes.
- **On success:** `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN-REV` (Review, mandatory).
- **On failure/blocker:** STOP and return to Review if a producer's gauge domain includes a hard-feature carrier, or a production consumer reads a face-gauge difference across an excluded edge. Either would falsify H-pin. Record the S lines and do not propose a fix.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN` | Definition, documents only, per RA-110.5. No code, build or run. |
| 2 — mandatory | `M6-CP3-DEFN-P1-GAUGE-PIN-DOMAIN-REV` | Review of the record; it authorizes CB20 or returns DEFN-P1. |
| planned, not authorized | CB20 (pin domain, compile only) → TB20 (artifact-only: nine M2 plus controls) → TB20-REV → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as DEFN-P1-REV assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **definition** — DEFN-P1, documents only (RA-110.5); never Code + Build or Test + Benchmark.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_TB19_REV_Gauge_Pin_Domain_Review_Decision.md` (RA-110, the DEFN-P1 specification); `Architecture_M6_CP3_TB18_REV_Factory_Rejection_Review_Decision.md` (RA-105.3, RA-105.4); `Architecture_M6_Frozen_Definitions.md` (RA-45, RA-31a, RA-33.3, RA-34.3); the TB19 and TB19A harvest reports; `LESSONS.md` §§3, 4, 6.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md`.

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
