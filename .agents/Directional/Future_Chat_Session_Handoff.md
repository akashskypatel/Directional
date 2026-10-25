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
| Currency | 2026-10-25, control-plane-only CB36 corrected the five-row uniqueness gate and two failure-location regex uses in runner commit `0ba22724c97e9231f24a6d9bc7201e58b3c6da81` (SHA-256 `343cdc6e53daf33da7d2893086751e0f762e6a3ed2111e69bf077555a4e3f439`); static checks passed, **no tests executed**. First TB36 attempt `40155549123` remains invalid orchestration (0/5). New artifact-only M6-CP3-TB36-R1-RP01-PERIODIC-MONODROMY-BASELINE is next; semantic/package and accepted authority unchanged. |
| Source/package | CB35-R2 exact semantic `7de805c487fa66bcb96744f51b8bfbe7210ee8dc`; [compile run 40147720351](https://github.com/akashskypatel/Directional/actions/runs/40147720351), package `12580989509`, ZIP `a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54`; 28/28 hashes, eight GMP/GMPXX targets, `runtimeExecution=false`; no runtime/tests/benchmarks. [R2 record](Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Code_Build_Record_20261025.md). Earlier R1/CB35/CB34 packages remain in records. |
| Reviewed decision | [CB35-R2-REV](Architecture_M6_CP3_CB35_R2_Oriented_Route_Identity_Oracle_Independent_Review_20261025.md) accepts static directed-route R-2 with independent 32-edge reconstruction and 28/28 package hashes; [CB35-R1-REV](Architecture_M6_CP3_CB35_R1_Published_Route_Oracle_Independent_Review_20261024.md) rejects directed-route non-vacuity (R-2), while discharging R1 canonical and translation obligations; [RA-152](Architecture_M6_CP3_TB35_REV_Audit_Periodic_Route_Transport_Decision_20261024.md) accepts TB35-REV evidence and non-promotion, corrects its owner (F1), decides single-writer D1–D4, and replaces the ingress DEFN with CB35 → TB36 → CB36 → TB37 → legacy-oracle DEFN. [TB35-REV](Architecture_M6_CP3_TB35_Periodic_Route_Gauge_Independent_Review_Decision_20261024.md) (RA-151) verified 13/13, 11 PASS / 2 RED. |
| Accepted vs candidate | CP2 accepted **491/491**; TB32 candidate **481/500** (19 inherited RED); TB34 **5 PASS / 7 inherited RED** (12 measured), TB33 synthetic **6/6** only; selector497 frozen; stable **66/17/49**, debt 1. RP-01 open, RP-02 unreached. |

## Mandatory next turn — `M6-CP3-TB36-R1-RP01-PERIODIC-MONODROMY-BASELINE` — artifact-only Test + Benchmark

- **Orchestration fix completed:** `M6-CP3-CB36-ORCH-RP01-TB36-HARNESS-CORRECTION` changed only `.agents/Directional/tools/m6_cp3_tb36_periodic_monodromy_baseline_harness.sh` at `0ba22724c97e9231f24a6d9bc7201e58b3c6da81`. Corrected runner SHA-256 `343cdc6e53daf33da7d2893086751e0f762e6a3ed2111e69bf077555a4e3f439`; static Bash/Python/manifest/regex checks pass, no compile or Directional runtime. See [CB36 record](Architecture_M6_CP3_CB36_TB36_Harness_Orchestration_Correction_Record_20261025.md).
- **Frozen executor/package gate:** exact new executor SHA must contain the corrected runner and unchanged [five-row manifest](Architecture_M6_CP3_TB36_Periodic_Monodromy_Baseline_Case_Manifest.tsv) (`ab2711b2efc64103a9106b9a63f03064c63dc6e93a16c0602f3c6b3f866c1d0c`); use immutable semantic source `7de805c487fa66bcb96744f51b8bfbe7210ee8dc` and existing package `12580989509` (ZIP `a594b8617493087ff9ab50391e30cc7a8870f2dcf92427c03899b076e344bb54`). No rebuild, relink, fixture/test/selector changes or source repair.
- **Execute five identities in fresh processes:** quarter and half monodromy, published directed-route oracle, frozen selector191 and selector192. Preserve stop rules: unexpected GREEN of a new witness, A3 rejecting k=2, or a first failure before the authorized periodic producer. An early stop must be reported, not smoothed into a 5/5 result. Verify exact harness and manifest hashes, package checksums, GMP runtime and immutable postflight.
- **Invalid attempt remains invalid:** TB36 run `40155549123`, 0/5 tests, is orchestration provenance only. After valid new-run evidence, route to `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE-REV` (independent Review), not directly to CB36 production repair. RA-152 F1 and accepted CP2 accounting remain unchanged.

## Turn Sequence

| Step | Canonical turn | Condition / boundary |
|---|---|---|
| done | `M6-CP3-CB34-RP01-PERIODIC-ROUTE-FACE-GAUGE-REPAIR` → `…-REV` | Gauge helper/oracle compiled and statically accepted; TB35 manifest issued. |
| done | `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY` → `…-REV` (RA-151) | 13 cases, 11 PASS / 2 RED; 191/192 mutate discarded containers; 189/190 non-discriminating. |
| done | `M6-CP3-TB35-RP01-PERIODIC-ROUTE-GAUGE-VERIFY-REV-AUDIT` (RA-152) | F1 found: atlas-path route steps identity, guard dead; ingress DEFN withdrawn. |
| done | `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS` | Test-only helper + 3 witnesses compiled; no runtime. |
| done, not accepted | `M6-CP3-CB35-RP01-PERIODIC-MONODROMY-WITNESS-REV` | Found incomplete published-route identity assertion; no TB36 manifest. |
| done | `M6-CP3-CB35-R1-RP01-PUBLISHED-ROUTE-ORACLE-CORRECTION` | Test-only R-1 correction compiled and packaged without execution. |
| done, not accepted | `M6-CP3-CB35-R1-RP01-PUBLISHED-ROUTE-ORACLE-CORRECTION-REV` | R-2 canonical-versus-oriented false positive; TB36 still prohibited. |
| done, statically accepted | `M6-CP3-CB35-R2-RP01-ORIENTED-ROUTE-IDENTITY-ORACLE` | Exact test-only directed 32-step and reversal-negative; eight GMP/GMPXX targets compiled without runtime. |
| done, accepted static Review | `M6-CP3-CB35-R2-RP01-ORIENTED-ROUTE-IDENTITY-ORACLE-REV` | Directed-route identity and reversal rejection re-derived; no runtime promotion. |
| invalid attempt | `M6-CP3-TB36-RP01-PERIODIC-MONODROMY-BASELINE` | Harness preflight 0/5; no semantic evidence; control-plane-only CB required. |
| done | `M6-CP3-CB36-ORCH-RP01-TB36-HARNESS-CORRECTION` | Corrected five-row cardinalities and both source-location regex uses; no Directional runtime, compile-free static checks. [Record](Architecture_M6_CP3_CB36_TB36_Harness_Orchestration_Correction_Record_20261025.md). |
| next | `M6-CP3-TB36-R1-RP01-PERIODIC-MONODROMY-BASELINE` | Fresh artifact-only baseline attempt on same immutable package; then independent TB36 Review. |
| 4 | `M6-CP3-CB36-RP01-PERIODIC-ROUTE-ATLAS-TRANSPORT` → `…-REV` | Production D2 only: observed steps read `atlas->transport`; missing transport fails closed with location; compile only. |
| 5 | `M6-CP3-TB37-RP01-PERIODIC-ROUTE-ATLAS-VERIFY` → `…-REV` | Witnesses GREEN, TB35 13 cases, full 497 census (route digests change). |
| 6 | `M6-CP3-DEFN-RP01-PERIODIC-LEGACY-ORACLE-HOMES` → CB/TB | Runtime-free re-homing of frozen 189–192 (D4). |
| 7 | Untyped 7 (`selector:174,201,204,242,247,250,405`) → `focused30:12` → `cp3entry:4` → `selector:442` → DEFN-T1 (`cp3entry:1/2`) | One owner per turn; DEFN or diagnostic first. |
| 8 | Census → RP-01 Review | Review-owned 497(+) manifest. |
| carried | `DIAG-RETAIN` (A5–A7 diagnostic snapshots; full scope in TODO CURRENT) | Review places it clear of RP-01 corrective turns; edits `RemeshPipeline.cpp`. |
| carried | RA-152.5 axis-binding, DEFN-SEAM-NZ, Periodic follow-up, RA-146.2/4, RA-45.4, G4-B002 | After a witness / separate gates. |

## Context Load Plan - DURABLE, DO NOT DELETE

`load_next`: **M6-CP3-TB36-R1-RP01-PERIODIC-MONODROMY-BASELINE**, artifact-only Test + Benchmark, no compile/repair. Freeze exact corrected executor SHA and harness hash `343cdc6e53daf33da7d2893086751e0f762e6a3ed2111e69bf077555a4e3f439`, unchanged frozen five-row manifest and immutable CB35-R2 semantic package; apply the five stop rules in [TB36 original attempt report](Architecture_M6_CP3_TB36_Baseline_Orchestration_Attempt_20261025.md). See [CB36 correction record](Architecture_M6_CP3_CB36_TB36_Harness_Orchestration_Correction_Record_20261025.md). Invalid run 40155549123 gives 0/5 orchestration provenance only; valid TB36 evidence must route through independent Review.

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
