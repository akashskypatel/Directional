# Future Chat Session Handoff

## Purpose

This file contains only durable operating policy, exact next action, current immutable authority, and resume-critical blockers. Architecture belongs in `DESIGN.md` / `REORIENTATION_PLAN.md`; active tasks belong in `TODO.md`; exact runtime evidence belongs in the R-A T+B report; completed history belongs in `CHANGELOG.md`.

## Mandatory start-of-turn checklist

1. Review the turn-based-coding-agent skill and **Code + Build** boundary.
2. Review this handoff, `TODO.md`, `RETENTION_POLICY.md`, `GitHub_Workflow_Policy.md`, and the active Code + Build plan.
3. Resolve the current branch head and compare it with exact retry-4 tested source `aa16449577c48bac72257b7b9915e2b70dad3b82` before any implementation write.
4. Review retry-4 failure evidence in `Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md`.

## Mandatory next turn — Code + Build only

Resolve `R-A-TB4-CB-01` through `R-A-TB4-CB-04` from `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`.

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
PR: #8 remains open, draft, and unmerged.

Entering immutable runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`.

### Retry-4 immutable evidence

- semantic implementation tested: `199b06f429d8004a5b51c89f94ae33748f4ec38c`;
- exact tested source: `aa16449577c48bac72257b7b9915e2b70dad3b82`;
- compile run/job: `31674780558 / 94366870676`;
- compile result `9171125667`, SHA-256 `0190d60057001cc2fdcb56f64e436b7bf4670bb7a571c0ae0f3af8a296594a83`;
- compile log `9171126075`, SHA-256 `bc54bd79251bc935a171d04cd81994f211096d060904341169ce6e5777442380`;
- runtime run/job: `31679754667 / 94382280555`;
- runtime result `9173016395`, SHA-256 `39f71abb285ac1e806f2fdaded58a3675d6491b3a8177999def697b9aa6678ac`;
- runtime log `9173016645`, SHA-256 `9c1ff473c56cf867e3cd6f8600f888ba438955dfbb96bf3c1084578112ab2176`.

Immutable boundary: preflight PASS, regenerated static inventory **19 affected paths / 60 probes / 270 matches / PASS**, discovery non-vacuous (**13 / 235 / 180 / 84** by executable), postflight PASS, `rebuild=false`, `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `packageRepair=false`, `orchestration_failed=0`.

Semantic result: **92 unique selected / 88 passed / 4 failed**. R-A remains open.

### Runtime-green closures

- R-A-TB3-CB-01 stale-cache direct group: **2/2 PASS**.
- R-A-TB3-CB-03 provenance direct group: **1/1 PASS**.
- F1 retained-source authority: PASS.
- F2/F3 completion/stitch reason capture: **4/4 PASS** with the required exact outcomes.
- F5 feature-option conservation/no-leakage: **2/2 PASS**.
- All broad groups except `SurfaceCellAuthorityContractCutover.*` are fully green; that group is **26/30 PASS**.

### Remaining four failures

1. `ComponentFeatureRailTamperRejectsAtAggregationSeam` — expected `component-merge-authority`, actual `completion`; expected `ChangedComponentValidationAuthority`, actual empty first-invalid-producer reason.
2. `FinalMergedOracleRejectsMissingRemappedFeatureAuthority` — final-oracle seam not reached.
3. `FinalMergedOracleRejectsChangedRemappedFeatureRailContent` — final-oracle seam not reached.
4. `FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority` — non-empty feature authority never observed at final oracle.

## Resume-critical source diagnosis

The retry-3 CB-02 exact lineage projection is downstream of a precondition this witness does not satisfy.

- Source-topology-region construction treats hard feature edges as barriers.
- The current witness is a square made from two triangles with its shared diagonal marked hard; the barrier therefore creates one-triangle regions.
- The curved bounded-disk phase-front producer returns `NotApplicable` when a region has fewer than four boundary edges/vertices; each of these regions has three.
- With no produced phase-front product, `useAuthoritativePhaseFront` is false and `project_materialized_hard_feature_rails_from_lineage(...)` is not entered.
- A later generic completion rejection can overwrite an earlier producer diagnostic with the completion/lineage reason, including an empty string. The disconnected aggregate already copies the inner component fields directly, so the remaining diagnostic loss is inside the component pipeline, not the aggregate copy.

The exact two-triangle diagonal witness is therefore outside the **current bounded-disk phase-front producer's supported domain**. This does not make hard features optional and does not justify boundary-only/empty substitution.

## Exact next Code + Build scope

1. **R-A-TB4-CB-01 — earliest typed feature-production failure.** Preserve a prior non-empty producer stage/reason instead of overwriting it with an empty generic completion reason. Make the undersized hard-feature-separated topology explicitly typed/fail-closed, with zero semantic output. Retain a direct contract for the two-triangle diagonal witness.
2. **R-A-TB4-CB-02 — feasible internal hard-feature witness.** Replace only the four aggregate/final-oracle feature tests' witness with a sufficiently resolved internal hard-feature mesh whose separated topology regions satisfy current phase-front bounded-disk preconditions and naturally reach materialization/completion with non-empty feature authority. Keep the unsupported two-triangle witness separately. No callback rail synthesis, boundary-only feature, or validator weakening.
3. **R-A-TB4-CB-03 — retain retry-4 green authority.** Preserve stale-cache, provenance, F1, F2/F3, F5, and all other 88 passing contracts.
4. **R-A-TB4-CB-04 — static/compile closure.** Regenerate the complete R-A inventory and create one fresh exact-source compile package. **Do not execute generated tests/benchmarks/discovery/runtime during Code + Build.**

The following turn is immutable artifact-only **R-A retry 5**. R-A closes only on an organic all-pass with clean preflight/static/discovery/postflight.

No new stable regression accounting was assigned; historical totals remain **34 events / 14 categories / 20 recurrences**.

## Current authority and stable backlog

- Normative architecture: `.agents/Directional/DESIGN.md`.
- Migration ordering: `.agents/Directional/REORIENTATION_PLAN.md`.
- Deferred post-R-A hygiene: `RA-REV-23-F3`, `RA-REV-22-F6`.
- R-B through R-G remain blocked behind R-A.
- Full-M1 representative/benchmark acceptance remains dormant until a fresh complete R-A-through-R-G package exists.
- Product blockers remain `G4-B001` through `G4-B004`; Bunny/Vase remain later representative gates.

## Resume-critical lessons

- Compile/review acceptance is not semantic runtime acceptance.
- A negative proves only the guard it actually reaches.
- Hard-feature barriers change the topology-region domain seen by phase-front producers.
- A post-materialization authority correction cannot repair a witness that never produces the materialized product.
- Preserve the earliest typed failure; later generic failure handling must not erase stronger producer evidence.
- Materialized hard-feature membership is semantic lineage/mesh incidence, not geometric proximity.
- A counterfactual mutation must be proven semantically different from its baseline.
- Do not answer semantic failure by weakening validation, fixtures, authority, lineage, or no-substitution contracts.
- A zero-selected filter is orchestration failure, never pass.

## Mandatory end-of-turn checklist

1. Apply `CLEAN_UP_POLICY.md` and `RETENTION_POLICY.md`.
2. Update `TODO.md` and active plan with exact completed/open scope.
3. Update `CHANGELOG.md` only for durable completed changes/evidence.
4. Update the regression tracker only if a stable accepted regression event/pattern changes.
5. Replace this handoff with the exact next action and fresh package authority.
6. Update PR #8 durable description if stale.
7. Remove temporary workflows/markers/payloads in policy order.
8. Add one final summarized PR #8 conversation comment **after every other branch/PR write**.

## Core references

- `TODO.md`
- `.agents/Directional/DESIGN.md`
- `.agents/Directional/REORIENTATION_PLAN.md`
- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`
- `.agents/Directional/Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md`
- `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Artifact_Only_Test_Benchmark_Plan.md`
- `.agents/Directional/Architecture_Redesign_and_M1_RA_Independent_Review_Report.md`
- `.agents/Directional/R_A_Closure_Inventory.py`
- `.agents/Directional/R_A_Closure_Inventory_Report.md`
- `.agents/Directional/Regression_Root_Cause_Tracker.md`
- `.agents/Directional/PR_8_Regression_Audit_Inventory.md`
- `.agents/Directional/CHANGELOG.md`
- `.agents/Directional/CLEAN_UP_POLICY.md`
- `.agents/Directional/RETENTION_POLICY.md`
- `.agents/Directional/GitHub_Workflow_Policy.md`
- `tests/TESTING_STRATEGY.md`
