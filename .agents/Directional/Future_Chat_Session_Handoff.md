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
| Currency | 2026-10-20, CB20 compile-stop Review (RA-112). The CB20 S patch `7dc9b89ec` matches the frozen domain (RA-111.4), statically. The compile failed only on five test lines that dereference `DomainResult` with `*`; the type offers `value()` instead. RA-112.4 tightens `RegionGaugeShiftPassesPin` to require a product. Next: CB20A corrects the tests (TQ only, compile only). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Last compiled semantic source `d2c7483cde8e65d6c35c5df06fa880465a4da46c`. CB20 source `7dc9b89ecd13753173057577d1da320db9515ebb` is not compiled. |
| Last compiled semantic source | CB19A eight-target GMP/GMPXX compile [39446712217](https://github.com/akashskypatel/Directional/actions/runs/39446712217), package `12275794192`, ZIP SHA-256 `e4a39cdb2db5ef9953748cffd3e031e4294ddaf348f4a64fee3b97e08bdd723a`; hashes `28/28`, statuses clean, `runtimeExecution=false`; expires 2026-10-27T15:24Z; accepted by RA-107. Record: `Architecture_M6_CP3_CB19A_Factory_Rejection_Site_Code_Build_Record_20261020.md`. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate / rejected evidence | CB20 compile RED: run [39512680019](https://github.com/akashskypatel/Directional/actions/runs/39512680019), log artifact `12306507832`; five test accessor errors; record `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md`, reviewed by RA-112. TB19A: run `39484475466`, artifact `12292268624` (ZIP `25d48ed7…7efa7c`), expires 2026-11-03; 7/7 selected, control `selector:443` PASS, 6 torus RED at `gauge-pin-consistency;edge=0,3`; report `Architecture_M6_CP3_TB19A_Torus_Rejection_Site_Harvest_Report_20261020.md`, accepted by RA-110. TB19: run `39464430751`, artifact `12285225197` (ZIP `2b5dfacf…dec0`), expires 2026-11-03; 16 valid rows; report `Architecture_M6_CP3_TB19_Factory_Rejection_Site_Harvest_Report_20261020.md`, accepted by RA-109. TB18 Part A `12231529583` (12/14) and Part B `12232299548` (448/497), expire 2026-11-03; candidate evidence per RA-105. First failures: `Architecture_M6_CP3_TB18_Selector_497_Red_Inventory.tsv`. |
| Regression accounting | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected, TB18 candidate 448/497. |
| Active boundary | `RP-01` open. M2 = H-pin, CONFIRMED (RA-110.3). The corrected domain (RA-111.4) is implemented in `7dc9b89ec` and accepted statically by RA-112.2, but it is not yet compiled. All nine M2 identities still stop at the old pin, so the RA-103.5 R-route falsifier stays undetermined until TB20. Cut-set inclusion is open but fail-closed (RA-111.5). M1 certificate shadowing (10 identities, RA-105.3) is unchanged; its DEFN follows TB20-REV. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-CB20A-RP01-GAUGE-PIN-TEST-ACCESSOR` — EXACT NEXT

- **Type / owner:** Code + Build, compile only; implementation agent. Authority: RA-112.5 (`Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md`).
- **Objective:** correct the CB20 test accessors, tighten the item 5 oracle, and produce the compiled package for the CB20 source.
- **Read before work:**
  - RA-112;
  - TQ:1933–2012 (the two new tests) at `7dc9b89ec`;
  - `include/directional/authority/AuthorityIds.h:73–93` (`DomainResult`);
  - the CB20 stop record (build procedure, diagnostics).
- **In scope (TQ only):**
  1. **Accessors.** On TQ:1941, 1947, 1972, 1978 and 1979, replace `*face0` with `face0.value()` and `*face` with `face.value()`.
  2. **Item 5 oracle.** In `RegionGaugeShiftPassesPin`, replace the product-or-other-error branch with one assertion that the result is a `SurfacePhaseFrontProduct`. The failure message prints the error's `sourceAuthoritySite`.
  3. **Build.** GMP/GMPXX eight-target compile with the package and `runtimeExecution=false`. The CB20A record gives the TQ diff against `7dc9b89ec`, the package hashes and the 48-label count.
- **Out of scope:**
  - S, `include` and every file other than TQ, which stay byte-identical to `7dc9b89ec`;
  - any runtime, test execution or benchmark;
  - the M1 binding and the R-route.
- **Success evidence:**
  - the TQ diff against `7dc9b89ec` touches only items 1–2;
  - `git diff 7dc9b89ec -- src include` is empty;
  - no line is longer than 100 columns;
  - the compile is green, with verified package hashes and `runtimeExecution=false`;
  - the record is committed.
- **On success:** `M6-CP3-CB20A-RP01-GAUGE-PIN-DOMAIN-REV` (Review, mandatory). It accepts CB20 and CB20A together, authorizes TB20 and sets its rows.
- **On failure/blocker:** STOP and return to Review on any of:
  - a compile error (record the first diagnostic of each distinct error);
  - any need to change a line outside items 1–2.

  There is no second repair inside the turn.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-CB20A-RP01-GAUGE-PIN-TEST-ACCESSOR` | Code + Build, compile only, TQ only, per RA-112.5. No runtime. |
| 2 — mandatory | `M6-CP3-CB20A-RP01-GAUGE-PIN-DOMAIN-REV` | Review of the CB20 and CB20A source and the package; it authorizes TB20 and sets its rows. |
| planned, not authorized | TB20 (artifact-only: the nine M2, the ten M1 as a no-regression check, the `SurfaceCellFactoryRejectionSite` suite, controls) → TB20-REV → DEFN on the M1 binding owner (RA-105.3) → corrective CB/TB → fixture debt (242, 174, 250, adjacent-sheet, 191, 442, plus the I/R sites) → census → RP-01 Review | Only as CB20A-REV assigns them. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **code-build** — CB20A, compile only, TQ only (RA-112.5); never Test + Benchmark.

Minimum successor context after the mandatory start checklist and policies:

0. `.agents/Directional/ORIENTATION.md`.
1. `.agents/Directional/ROADMAP.md`.
2. This handoff.
3. `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Compile_Stop_Review_Decision.md` (RA-112, the CB20A specification); `Architecture_M6_CP3_CB20_Gauge_Pin_Domain_Code_Build_Stop_Record_20261020.md` (build procedure); `Architecture_M6_CP3_DEFN_P1_Gauge_Pin_Domain_Review_Decision.md` (RA-111, the frozen domain); `Architecture_M6_Frozen_Definitions.md` (RA-45); `LESSONS.md` §§2, 6, 7.
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
