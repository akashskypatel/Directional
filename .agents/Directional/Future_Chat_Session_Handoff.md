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
| Currency | 2026-10-21, after documents-only DEFN-ISO-A seam-node representative census (commit `d2e2dc523d802ae83f81bdf7afec1eb44c70c0cb`); mandatory independent Review next. TB24 held P1/P2: both occurrences of the failing seam relation are the same vertex-61 node and carry one per-node representative face `121/0`; it lies inside occurrence (0,1)'s wedge but outside (1,0)'s (`97/2`, other sheet). The site is neither B-across nor B-fan; the owner is the A2 per-node corner representative (RA-72.4 class). Relaxing the A5 face clauses is inadmissible (A6 relies on them). DEFN-ISO is split: census (A), then contract (B). |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Semantic source CB23 `e859175333f879273a75e3bfc321600e451048aa`; HEAD `src`, `include` and `tests` are identical to it. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB24: run [39641426480](https://github.com/akashskypatel/Directional/actions/runs/39641426480), result `12364838156` (ZIP `dcf42df9…220d3`), expires 2026-10-28T17:12:14Z; 9/9, 3 A5 RED / 6 PASS; report `Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Report_20261021.md`, reviewed by RA-123 (`Architecture_M6_CP3_TB24_Torus_A5_Seam_Face_Harvest_Review_Decision_20261021.md`). CB23 package `12355892070` (RA-122). Census: TB21 **449/497** (RA-115). **Not promoted.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. Static census `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md` inventories consumers and gauge writers. Runtime producer branch, vertex-61 origin and alternate representative/A6 seam-turn equivalence remain unproven; the Review adjudicates whether a rejection-only compile/probe is needed. **A5-ISO**: 10 rows (`focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448`; incl. G4-B002), one site; owner the A2 per-node representative (RA-123.3–123.6). Unestablished premises: one representative per occurrence serves every consumer; lattice re-expression at another face is exact and A6's stripped-turn check is meaningful. No clause relaxation, no minimum-face rule, no new producer certificate. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). Restriction: no contract or implementation before independent DEFN-ISO-A Review. `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS-REV` — EXACT NEXT

- **Type / owner:** independent Review (RA-123.7), not Code + Build.
- **Objective:** adjudicate the completed static census without converting unproved frame premises into an implementation rule.
- **Read before work:** `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md` (DEFN-ISO-A, 49 lines); RA-123, RA-72.4–72.6, RA-78.10, RA-79.4; TB24 harvest report, `LESSONS.md` §§3, 5, 6.
- **In scope:** independently verify census completeness and line-anchored enforcers; distinguish provable producer/consumer semantics from undecidable torus runtime data; check whether the proposed rejection-only producer probe is necessary and sufficient; issue the next authoritative bounded DEFN-ISO-B contract turn **or** an authorized compile-only probe, with named falsifiers and explicit guards.
- **Out of scope:** code, tests, selectors, workflow edits, compilation, runtime, fixes, A5 clause relaxation, a minimum-face rule, or a new certificate without Review authority. Do not promote R3 or alter stable accounting.
- **Success evidence:** committed independent Review decision with preserved source authority and explicit disposition of each unproved premise; current `STATUS` complete with authorized successor, or a justified formal stop.
- **On success:** follow only the newly authorized Review decision. Subsequent DEFN-ISO-B/probe ID is `UNKNOWN` until assigned.
- **On failure/blocker:** document the precise missing proof/decision and stop without speculative implementation.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-DEFN-ISO-A-RP01-SEAM-NODE-REPRESENTATIVE-CENSUS-REV` | Review the 49-line census, reconcile frame premises, assign next bounded edge. |
| 2 — conditional | `UNKNOWN` | DEFN-ISO-B contract or compile-only rejection probe, only if assigned by Review. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — independent DEFN-ISO-A census adjudication (RA-123.7); no code, compile or runtime.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md` (static census and undecidable premises); RA-123 TB24 Review, RA-72.4–72.6, RA-78.10, RA-79.4; TB24 report; `LESSONS.md` §§3, 5, 6.
4. `.agents/Directional/Regression_Root_Cause_Tracker.md` and `TODO.md` — unresolved issues and scope; required policy readings still govern.

**Review tooling:** `.agents/Directional/tools/` holds read-only helpers — `review_check.py authority <sha>` and
`review_check.py boundary`, `selector_probe.py` for selector hashes, ordinal ↔ identity and identity-existence
checks, and `fixture_probe.py` for fixture topology and vertex fans. See `tools/README.md` for the caveats.

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
