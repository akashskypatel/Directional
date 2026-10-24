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
| Currency | 2026-10-24, RA-150 audit of TB34-REV: owner = invalid two-edge fixture (vertex-2 and vertex-3 stars) is kept; CB34 is corrected to a true face gauge (face-1 frame relabel + additive +1/−1/−1 on all three face-1 edges) proven by an A3 branch-topology invariance oracle. CB34 compile only next. |
| Source/package | CB33 semantic `f807c2b890b990fc53ea8f84c7228edd94f0659d`; [compile run 40084311360](https://github.com/akashskypatel/Directional/actions/runs/40084311360), package `12556364042`, ZIP `f984368a213012b2adf5996afe7443817b024f2cb9ef579e5e77e1c99e5ca291`; 28/28 hashes, eight GMP/GMPXX targets, `runtimeExecution=false`. |
| Reviewed decision | [RA-150](Architecture_M6_CP3_TB34_REV_Audit_Face_Gauge_Representation_Decision_20261024.md) amends [TB34-REV](Architecture_M6_CP3_TB34_A3_Cycle_Locus_Harvest_Review_Decision_20261024.md). S2 unreachable (RA-149.3 withdrawn). Switching `sourceField` to the unedited field is prohibited (RA-150.2). |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500** (19 inherited RED); TB34 **5 PASS / 7 inherited RED** (12 measured), TB33 synthetic **6/6** only; selector497 frozen; stable **66/17/49**, debt 1. RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR` — EXACT NEXT

- **Type:** Test-only Code + Build (`tests/SurfaceCellsPhase10Tests.cpp`); eight-target GMP/GMPXX compile, `runtimeExecution=false`.
- **Authority:** [CB34 plan (amended by RA-150)](Architecture_M6_CP3_CB34_Periodic_Route_Face_Gauge_Code_Build_Plan_20261024.md); [RA-150](Architecture_M6_CP3_TB34_REV_Audit_Face_Gauge_Representation_Decision_20261024.md) §3 governs.
- **Edit:** `balanced_periodic_route_field` → representation gauge g(face1)=+1:
  - face located by route topology;
  - precondition: the original three directed matchings are 0;
  - additive +1 (0→1) / −1 (1→30) / −1 (1→32), compact matching kept consistent, `effort` unchanged;
  - face-1 `primaryDirections`/`secondaryDirections`/`rawField` relabelled so A3 `rawGauge` shifts by +1.
- **Add:** `SurfaceCellPeriodicHolonomyRouteTransportAuthorityMigration.BalancedRouteFieldIsPureFaceGauge`:
  - A3 succeeds;
  - branch-topology digest, frames and transports equal those from the unedited field;
  - raw `transition_value` is +1/−1/−1;
  - the two-edge-only construction rejects at `cycle-transport` LocalVertex.
- **Stops:** nonzero original matching; no relabel satisfies the invariance on paper; any need to change `sourceField`, production, a frozen test body or a selector.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-TB34-RP01-A3-CYCLE-LOCUS-HARVEST-REV` → `…-REV-AUDIT` (RA-150) | Owner kept; CB34 transformation corrected. |
| 1 — next | `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR` | Test-only helper + one invariance-oracle test; compile only. |
| 2 | `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR-REV` | Static review; issues the TB35 manifest (7 rows + oracle + 2 A3 guards + 3 TB33 controls). |
| 3 | `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY` → TB35-REV | Targeted harness, fresh processes. S1-cleared A4 RED → DEFN for the periodic-producer owner (no fixture tuning). |
| 4 | Untyped 7 (`selector:174,201,204,242,247,250,405`) per-row first-site pins → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; DEFN or diagnostic first. |
| 5 | Census → RP-01 Review | Review-owned 497(+) manifest. |
| carried | `DIAG-RETAIN` (A5–A7 diagnostic snapshots; full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | DEFN-SEAM-NZ, Periodic follow-up, RA-146.2/4, RA-45.4, G4-B002 | After a witness / separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **Code + Build test-fixture gauge** — read RA-150 §2–3 and the amended CB34 plan; `tests/SurfaceCellsPhase10Tests.cpp:4182–4420` (rings, route, helper, source-atlas builder) and 4497–4760 (seven tests); `src/authority/FieldTransportAtlas.cpp:233–310` (rawGauge from `{p,s,−p,−s}`), 347–380 (canonical lift), 2020–2045 (raw `transition_value`); `cylinder.obj`/`.rawfield`. No production edit, no runtime.

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
