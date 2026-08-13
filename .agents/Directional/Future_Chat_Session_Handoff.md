# Future Chat Session Handoff

## Purpose

This file contains only durable operating policy, exact next action, current immutable authority, and resume-critical blockers. Architecture belongs in `DESIGN.md` / `REORIENTATION_PLAN.md`; active tasks belong in `TODO.md`; exact runtime evidence belongs in the R-A T+B report; completed history belongs in `CHANGELOG.md`.

## Mandatory start-of-turn checklist

1. Review the turn-based-coding-agent skill and Code + Build boundary.
2. Review this handoff, `TODO.md`, `RETENTION_POLICY.md`, `GitHub_Workflow_Policy.md`, and the active Code + Build plan.
3. Confirm current branch head and compare it with the exact tested source before any implementation write.
4. Review retry-3 failure evidence in `Architecture_M1_RA_Closeout_Artifact_Only_Test_Benchmark_Report.md`.

## Mandatory next turn — Code + Build only

Resolve `R-A-TB3-CB-01` through `R-A-TB3-CB-04` from `.agents/Directional/Architecture_M1_Single_Authority_Cutover_Code_Build_Plan.md`.

Repository: `akashskypatel/Directional`  
Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`  
PR: #8 remains open, draft, and unmerged.

Entering immutable runtime authority remains M1l `bd140cff4572412e6f4ecd70a6ce0fe85310932c`.

Rejected retry-3 candidate:
- implementation commit `38d8d7d3e97f3b496e63979cb1348ed2cda304bc`;
- exact compile/tested source `555109796188b318c788ef5777f622705ee0aa94`;
- compile run/job `31665352874 / 94338607395`;
- compile result `9167759672`, SHA-256 `96401aac27a3a231533a785d107cb023cf50a304d06e821585e7c44597c6beb6`;
- compile log `9167759825`, SHA-256 `ed859f380103b183fda2241c71ff877fa0bbc3dc0c808f5c4f5f57290daadda8`;
- runtime run/job `31667380356 / 94344731465`;
- runtime result `9168437730`, SHA-256 `b0bf206ec0b93f7ae009ec4bf62c318ff3d2297b85af08c7bdafd83ce7e96ab5`;
- runtime log `9168437907`, SHA-256 `002785e52bf500489204e4c9c0616e3c91b6ac7d422056370596468da0d47919`.

Retry 3 immutable boundary is clean: package preflight PASS, regenerated static inventory **19 paths / 59 probes / 261 matches / PASS**, non-vacuous discovery, package postflight PASS, no rebuild/source/test/fixture mutation/package repair, `orchestration_failed=0`. Semantic result: **92 unique selected / 86 passed / 6 failed**. R-A remains open.

### Active failure clusters

1. **R-A-TB3-CB-01 — test fixture:** `DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches` expected zero cardinality rebuilds but never populated a same-cardinality stale cache. Production correctly counted two missing-cardinality component patches. Build a genuine same-cardinality stale counterfactual; keep canonical/valid anti-stale assertions and the separate exact missing-cardinality positive.

2. **R-A-TB3-CB-02 — feature-bearing completion:** four feature aggregate/final-oracle contracts stop earlier at component `completion`. RA-CB-F5 global-to-component feature conservation is runtime-green. Preserve/propagate the exact component completion reason, establish supported-domain status of the internal hard-edge witness, and make only the justified production/fixture correction. Do not synthesize rails, substitute empty/boundary-only feature authority, or weaken completion/final validation.

3. **R-A-TB3-CB-03 — test fixture:** provenance tamper `(1,0,0)` can be the already-valid source-corner certificate. Replace it with a guaranteed semantic mismatch and pre-assert that the certificate actually changed; require final-oracle fail-closed without validator weakening.

4. **R-A-TB3-CB-04 — static/compile closure:** regenerate the complete R-A inventory and create one fresh exact-source compile package with approved targets only. **Do not execute generated tests or benchmarks in this Code + Build turn.**

The following turn is immutable artifact-only **R-A retry 4** against that fresh package. Zero-selected discovery is orchestration failure. R-A closes only on an organic all-pass plus clean preflight/static/postflight.

## Current authority and stable backlog

- Normative architecture: `.agents/Directional/DESIGN.md`.
- Migration ordering: `.agents/Directional/REORIENTATION_PLAN.md`.
- Historical regression totals: **34 events / 14 categories / 20 recurrences**.
- Deferred post-R-A hygiene: `RA-REV-23-F3`, `RA-REV-22-F6`.
- R-B through R-G remain blocked behind R-A; full M1 artifact-only acceptance remains dormant until a fresh complete package exists.
- Product blockers remain `G4-B001` through `G4-B004`; Bunny/Vase remain later representative gates.

## Resume-critical lessons

- Compile success is build evidence, not semantic acceptance.
- A negative proves only the guard it actually reaches.
- Exact source-row topology pairing is authority; matching extent is not.
- Derived caches may be reconstructed only from canonical authority; cache presence is not source authority.
- Feature options entering compact components require explicit ownership/remap and conservation.
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
