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
| Currency | 2026-10-21, after CB24 independent Review (RA-125). Static proof: an OrdinaryFront relation's two occurrences are one shared producer node with one `selectedFace`, so the A5 certified-seam face clauses can never hold (every certified collinear-seam OrdinaryFront is rejected), and A6's gauge-stripped turn is identity by construction in the uniform and curved producers (annulus never writes `branchRotation`). The frozen D3 seam rule (RA-30a.3) is satisfiable only for an identity turn. RA-123's DEFN-ISO-B (per-occurrence representative) is withdrawn as relocation. CB24 diagnostics are independently compile-accepted; immutable TB25 will measure the gauge jump against the certificate turn before DEFN-SEAM. |
| Working branch / HEAD | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. CB24 semantic source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; CB24 independent Review RA-125 accepts compile-only evidence. Subsequent commits are documentation/control-plane only, except interim tooling commit `bf518b003` (GUI network display and its adapter tests; RP-01 sources byte-identical to `dae267a82`; record `Architecture_M6_TOOL_VIS_Field_Network_GUI_Layer_Record_20261021.md`). Exact current HEAD must be re-fetched. |
| Last accepted semantic runtime | CP2 **491/491**, package `11391685901`, source `5ce3132ec01748eff5b15f82be07a1abe2bd1af6`. R3 baseline **403/497** rejected. |
| Latest candidate or rejected evidence | TB24: run [39641426480](https://github.com/akashskypatel/Directional/actions/runs/39641426480), result `12364838156` (ZIP `dcf42df9…220d3`), expires 2026-10-28T17:12:14Z; 9/9, 3 A5 RED / 6 PASS (RA-123). Static census `Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_20261021.md`, reviewed by RA-124 (`Architecture_M6_CP3_DEFN_ISO_A_Seam_Node_Representative_Census_Review_Decision_20261021.md`). CB24 compile-only [run 39667030493](https://github.com/akashskypatel/Directional/actions/runs/39667030493), artifact `12378590512`, eight GMP/GMPXX targets, 28/28 manifest PASS, `runtimeExecution=false`; [CB24 build record](Architecture_M6_CP3_CB24_Seam_Frame_Values_Site_Code_Build_Record_20261021.md). TB21 **449/497** candidate (RA-115). **No CP3 promotion.** |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen; R3 403/497 rejected; candidate evidence TB21 449/497. Tracker: `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open. **Seam contract (RA-124.3, RA-125 compile review):** the A5 face clauses (RP:3891–3892) and frozen D3 (RA-30a.3, A6 RP:5832–5877) cannot pass on shared-node producer data. **A5-ISO**: 10 rows (`focused30:6, 20, 24, 25, 26, 27, 28`; `selector:444, 446, 448`; incl. G4-B002) are instances. `cp3entry:3/5` (the D3 positive witnesses, filed as adjacent-sheet fixture debt) are contested; TB25 decides. Open runtime fact: does the published gauge jump at seam 60–61 equal the certificate turn? No clause relaxation, no per-occurrence representative change, no D3 amendment before TB25-REV. **M1**: 10 rows plus `focused30:12`, `cp3entry:2` (DEFN-M1). CP3-entry: D2 `cp3entry:1` (DEFN-T1). `RP-02` UNREACHED; Gate C suspended. |

## Mandatory next turn — `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST` — EXACT NEXT

- **Type / owner:** artifact-only Test + Benchmark, authorized by RA-124.6 and RA-125; [frozen plan](Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Plan_20261021.md).
- **Objective:** measure each A5 seam site's producer branch, selected/span face gauges and certificate turns; classify gauge jump `d` against forward certificate turn `F`; inspect contested D3 `cp3entry:3/5` candidate sites before DEFN-SEAM.
- **Read before work:** RA-125, RA-124 §§3–7, CB24 build record, frozen D3 RA-30a.3, [TB25 plan](Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Plan_20261021.md), `REVIEW_TURN_POLICY.md` and artifact-only execution policy.
- **In scope:** exact CB24 package `12378590512` / source `dae267a82fb884ff9eba4fd0122ad61750d0c924`; 11 fresh single-identity processes (3 A5, 2 D3, 1 guard, 5 controls); full diagnostic and immutable postflight verification.
- **Out of scope:** compile/rebuild/relink; changed source, tests, selectors, fixtures, admission or D3 rules; executing a successor/DEFN-SEAM; candidate promotion without Review.
- **Success evidence:** eleven independent process logs, manifest and source hashes, exact disposition per row, producer signature, gauge/certificate routing and D3 candidate-stage inventory, immutable result package.
- **On success:** mandatory independent TB25 Review, canonical ID `UNKNOWN — STOP` until assigned by authority.
- **On failure/blocker:** preserve immutable evidence and report orchestration versus semantic status; no guessed repair or test weakening. `UNKNOWN — STOP` until Review authorizes the exact successor.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| 1 — next | `M6-CP3-TB25-RP01-SEAM-FRAME-VALUES-HARVEST` | Eleven-row CB24 artifact-only harvest; no new compilation |
| 2 — conditional | `UNKNOWN` (TB25 independent Review) | Only after immutable evidence and reviewed authority; DEFN-SEAM held |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **test-benchmark** — execute immutable eleven-row TB25 plan on the exact CB24 package, no rebuild or repair.

Minimum successor context **after the mandatory start checklist and policies**:

0. `.agents/Directional/ORIENTATION.md` — project context, read first.
1. `.agents/Directional/ROADMAP.md` — milestone position only.
2. `.agents/Directional/Future_Chat_Session_Handoff.md` — exact current handoff.
3. `Architecture_M6_CP3_CB24_Seam_Frame_Values_Site_Review_Decision_20261021.md`, `Architecture_M6_CP3_TB25_Seam_Frame_Values_Harvest_Plan_20261021.md`, CB24 build record, RA-124.6, RA-30a.3 in `Architecture_M6_Frozen_Definitions.md`, `TESTING_STRATEGY.md`, `REVIEW_TURN_POLICY.md`, and `LESSONS.md` §§5–7.
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
