# M4-CP-COND-CB1 Code + Build Record

**Turn:** `M4-CP-COND-CB1`  
**Disposition:** COMPLETE / COMPILE-ONLY GREEN  
**Runtime:** not executed  
**Mandatory successor:** `M4-CP-COND-TB1-EXEC`

## Authority

- Frozen definition authority: `Architecture_M4_CP_COND_Frozen_Definitions.md`.
- Code/build plan: `Architecture_M4_CP_COND_CB1_Code_Build_Plan.md`.
- Exact pre-turn source snapshot: `a64e371bbd2e98b8df0d19f279c27c93a327c444`.
- Semantic implementation source: `b576d061e23873b7b4193b158138d2097c75a728`.
- Recovery patch SHA-256: `dd641f1245c7aecb73f1db450460305677a52f3fc84e8d9e9995d6133513c780`.
- The semantic implementation patch changes eight durable product/test files: **2082 insertions / 20 deletions**. Temporary workflow callers, trigger markers and schema-validation payloads are orchestration state and are not semantic implementation authority.

## Implemented seam

CB1 introduces the bounded Amendment-20 conditioning seam without widening accepted M4 semantics:

- typed `ConditionedSourceProduct`, `ConditioningCertificate`, `ConditioningPolicy`, correspondence records and typed `ConditioningFailure` codes;
- one pre-A0 `InputConditioner` SurfaceCells entry point and independently recomputing certificate validation;
- finite binary64 exactification and exact dyadic policy mechanics;
- only the frozen operation set: exactification, dyadic lattice quantization, exact-equality safe merge, exact sliver refusal and canonical `Z4` field reindex;
- production identity policy at the live SurfaceCells boundary; coarsening behavior exists only under explicit non-default witness policy;
- legacy `BoundedMeshPreconditioner` and tolerant raw-field finalization are prevented from substituting for conditioner certificate authority;
- A3/A4 semantics and accepted selector408 are unchanged;
- test/build registration for the new focused CP-COND surface.

No topology-changing sliver repair, epsilon/proximity authority, field perturb-until-pass, CP-SCALE threshold calibration, M5/M6/M7 semantics or CP4 debt work was introduced.

## Authored test surface

`tests/InputConditionerTests.cpp` contains **15** CP-COND identities. Fourteen are prospective gating identities for TB1-EXEC:

1. `IdentityProducedSeparatesRawAndSemanticDigests`
2. `ExactDyadicQuantizationRecordsNonEmptyOperation`
3. `ExactEqualityMergeUsesMinimumRawOwner`
4. `UnsafeDisconnectedExactMergeIsTypedRefusal`
5. `ExactRationalSliverPredicateRefusesWithoutRepair`
6. `HighValenceRawPreconditionIsIndependentAndProduced`
7. `NegativeIndexRawPreconditionIsIndependentAndPreserved`
8. `ContradictoryExactZ4PairingIsTypedRefusal`
9. `CertificateTamperMatrixRejectsEveryAuthorityClass`
10. `IdempotenceHoldsForCleanAndNonEmptyOperationProducts`
11. `ExactSameLatticeCellPerturbationsShareSemanticDigest`
12. `LegacyPreconditionerCannotSubstituteForCertificate`
13. `TolerantRawFieldFinalizationCannotReplaceExactCertificate`
14. `SurfaceCellsRawEntryRejectsAtConditionerBeforeA0`

`BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` is explicitly **report-only / non-selector** because CB1 does not independently prove later A2a separatrix reachability. It must remain a named skip/blocker rather than green credit.

No test identity was executed in CB1.

## Compile-only evidence

GitHub Actions compile run/job: `34740201494 / 103678514188` — **GREEN**.

The compile workflow checked out and packaged exactly semantic source `b576d061e23873b7b4193b158138d2097c75a728` and compiled/link-checked:

- `directional_pipeline`
- `directional_surface_cell_producer_tests`
- `directional_compiled_api_tests`

Result artifact `10312168742` (`m4-cp-cond-cb1-result-34740201494`) has provider/downloaded ZIP SHA-256 `90c5e4c8bd41ced2311d11e1cb1e03cfd6dc71542c862981363aa31df2c03265`. Compile log artifact `10312427946` has provider SHA-256 `21628f148b64642a7338705cdb8a5d15ca7fc21b3b51beba92e0cbf4c2111cb6`.

Package verification:

- build exit `0`; preflight exit `0`;
- every root `SHA256SUMS` entry verified;
- source status is empty before configure, after configure, after build and final;
- `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `semanticContracts=compiled-not-executed`;
- exact arithmetic backend records GMP with both GMP and GMPXX available and linked;
- packaged accepted selector `Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt` is exactly **408 LF rows** with unchanged SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`.

No `ctest`, gtest binary, benchmark, custom runtime probe, configure outside the compile workflow, or local build was executed by the control plane.

## Runtime plan

`Architecture_M4_CP_COND_CB1_Artifact_Only_Test_Benchmark_Plan.md` is frozen for `M4-CP-COND-TB1-EXEC`. EXEC must use artifact `10312168742` immutably, run each of the 14 prospective CP-COND gates in a fresh exact-filter process, run the boundary-truncated identity as report-only blocker evidence, then execute the complete accepted selector408 census in fresh processes. No rebuild/configure/relink/package repair/source-test-fixture-selector mutation is authorized.

Mechanical EXEC results remain unadjudicated until mandatory successor `M4-CP-COND-TB1-REV`.

## Closeout

The consumed Google Drive recovery patch was permanently retired after verified apply. Repository orchestration callers, trigger markers and schema-validation payloads are temporary state and are removed by the turn-closeout cleanup path after this record and the live handoff/TODO are durable.

CB1 does **not** promote runtime acceptance, a new selector, stable-event accounting, or checkpoint closure. CP-COND remains OPEN pending TB1-EXEC and TB1-REV.
