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
| Currency | 2026-10-21, after TB23: 16/16 artifact-only rows executed, 6 PASS / 10 RED, all 5 controls GREEN; P1–P5 observed. Nine A5-ISO rows plus F `focused30:6` agree on `relation-collinear-seam;region=0;seam=60,61;certs=1;cert0=120/0->97/2:first-face`. F `selector:447` PASS. Next mandatory Review adjudicates the A4/A5 certificate mismatch and F-family outcome; no root-cause verdict or stable promotion. |
| Working branch / source | `agent/surface_cell_quad/p5-recover-bridge-healing`, PR #8 draft/open; refetch before mutation. Immutable semantic CB22B source `c6e90916eb90bfd33bc8a38c5ece7def15dcc766`; compile package artifact `12341307713` (ZIP `b5f9a668…8ad5`, 28/28, GMP/GMPXX, compile `runtimeExecution=false`), expires 2026-10-28T11:21:37Z. TB23 executor `0948a81b09e5ff07d240d01f8968f225c285ac2c`; no source/fixture/selector edits in TB23. |
| Latest runtime evidence | TB23 [run 39609365590](https://github.com/akashskypatel/Directional/actions/runs/39609365590), result artifact `12348649684` (ZIP SHA-256 `5ce737452a23637e74f0241f5f8a9a0ebe34b874b83ad1ff2d0d6f4456ee34d6`), harness SHA-256 `bf2cb7bc2799137e9a3556816380dc93388e9e05ee134cf320b068411f982cbe`; 20/20 result manifest, zero skips, immutable postflight. Report `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md`; tracker and CHANGELOG updated. Last accepted CP2 `491/491`, package `11391685901`; R3 baseline `403/497` rejected; last candidate census TB21 `449/497` (artifact `12317287104`). |
| Regression accounting and debt | **66/17/49**, debt **1**, selector 497 frozen. TB23 does not alter stable accounting. Tracker `Regression_Root_Cause_Tracker.md`. |
| Active boundary | `RP-01` open; **A5-ISO** ten measured A5 rejections at `relation-collinear-seam` / `first-face` (H-ISO-2 candidate, not verdict). **F** fixture atlas binding corrected: `selector:447` PASS, `focused30:6` advances to A5 RED. **M1** ten plus `focused30:12`, `cp3entry:2` deferred to DEFN-M1; D2 `cp3entry:1` deferred to DEFN-T1. `RP-02` UNREACHED; Gate C suspended. Review must precede repair. |

## Mandatory next turn — `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV` — EXACT NEXT

- **Type / owner:** mandatory Review of artifact-only TB23; same agent is permitted by Turn_Cadence.md, independent evidence required. Primary authority: `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`, RA-120.4, RA-117.3 (H-ISO-1/2/3), and the immutable TB23 artifact.
- **Objective:** independently re-download and verify TB23 result `12348649684`; re-derive 16/16 selection, manifest/postflight, all row sites, and observed P1–P5; adjudicate whether the recorded `cert0=120/0->97/2:first-face` identifies H-ISO-2 or another contract problem. Verify F `selector:447` PASS and `focused30:6` A5 RED; do not infer an accepted production fix.
- **Decision:** write a bounded Review record/definition-routing plan for DEFN-ISO or record an explicit review stop if required evidence is absent; retain the frozen stable regression ledger, selector and gate authority. Review `LESSONS.md` and required policies; apply mandatory Review document consolidation, ORIENTATION update and documentation drift audit.
- **Prohibited:** runtime tests or benchmarks, new compile, source/test/fixture/selector edits, ad hoc A5 repair, DEFN-M1/DEFN-T1 work or CP3 acceptance. Only the Review may authorize its successor.
- **Evidence:** [TB23 run 39609365590](https://github.com/akashskypatel/Directional/actions/runs/39609365590), artifact `12348649684`, ZIP `5ce73745…4456ee34d6`, report `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Report_20261021.md` (32 lines), full result `ledger.tsv` and 16 raw logs.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB22B-RP01-TORUS-A5-SITE-TEST-MESSAGES-REV` | RA-120 statically accepted CB22B package and issued TB23. |
| done | `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST` | Artifact-only 16/16, 6 PASS/10 RED, P1–P5 observed; no source/build edit, report committed. |
| **1 — exact next** | `M6-CP3-TB23-RP01-TORUS-A5-SITE-HARVEST-REV` | Mandatory independent Review of `relation-collinear-seam` / `first-face`, H-ISO-1/2/3, and F outcomes. |
| planned, not authorized | DEFN-ISO → corrective CB/TB → DEFN-M1 → corrective CB/TB → DEFN-T1 → fixture debt → census → RP-01 Review | Only after each Review-authorized boundary. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **review** — TB23-REV of the immutable sixteen-row torus A5 site harvest (result `12348649684`, RA-120.4 and H-ISO-1/2/3). Do not start DEFN-ISO before Review.

Minimum next-turn context after mandatory checklist and policies:

0. `.agents/Directional/ORIENTATION.md` and `.agents/Directional/ROADMAP.md`.
1. This handoff, `TODO.md`, `Regression_Root_Cause_Tracker.md`, and the artifact-only TB23 report.
2. `Architecture_M6_CP3_TB23_Torus_A5_Site_Harvest_Plan_20261021.md`; `Architecture_M6_CP3_CB22B_Torus_A5_Site_Test_Messages_Review_Decision.md` (RA-120); `Architecture_M6_CP3_TB22_Torus_Witness_Harvest_Review_Decision.md` (RA-117.3); `Architecture_M6_CP3_CB22A_Torus_A5_Isolation_Site_Formatter_Review_Decision.md` (RA-119.5).
3. TB23 raw artifact `12348649684` (16 logs, `ledger.tsv`, `execution-boundary.txt`, `immutability.txt`) and `LESSONS.md` §§1, 5, 6, 7.
4. Review tooling `.agents/Directional/tools/` includes read-only `review_check.py`, `selector_probe.py`, `fixture_probe.py`; history-sensitive Review gates require real committed history, not a synthesized snapshot.

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
