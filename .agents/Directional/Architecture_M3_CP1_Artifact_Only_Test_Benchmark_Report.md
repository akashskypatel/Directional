# Architecture M3 CP1 — Artifact-Only Test + Benchmark Report

Date: 2026-08-19 UTC
Turn: `M3-CP1-TB-R3`
Status: **PASS / CP1 ACCEPTED**
Exact successor: **`M3-POST-CP1-ALLOC-REPLAN` (Review/planning only)**

## Current immutable R3 authority and accepted result

- semantic source/package: `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046`;
- Code + Build run/job: `32257160818 / 96081424766`; package SHA-256 `5d779d578f900597053527e2edf7e61f3382de94a1852e94e2fdb712460595a7`;
- Code + Build log `9366752647`, SHA-256 `6d664f0bcc767958f4dbfddcba808f7e86fede6515595b9c5265414298dee3a9`;
- source archive SHA-256 `50566ca66d26b92db4a008ce735a1164b061eb273206d10800b554af236d8c73`, **554** members, zero symlinks; five source-status snapshots empty;
- TB run/job: `32263614534 / 96102598799`;
- TB result `9369359878`, outer SHA-256 `829f51e1510ba6aab2eb6f6eed716bd736dcd662b1932b05a6fe16d6223917fd`;
- TB log `9369360425`, outer SHA-256 `b624982cd6f5479cd167124c3897725533c6ce460fb6ce96751dfcfcfb18572c`;
- retained M2 selector **275**, SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`; A1 selector **6**, SHA-256 `bd00fc5d7840b398b76d834a65fbd30ed400c8ec4a1dab54eeeb554c8ae587ea`; combined **281**, SHA-256 `c73403ab665770282a924dd4534ca261fbdb249d8b832d6644d6a868b452fa83`.

Artifact verification, recursive package manifest, source identity, Code + Build runtime boundary, dependency closure, and selector reconciliation all passed. All **281/281** identities selected exactly through frozen direct filters; no generated discovery was used. Package and materialized packaged source were byte-identical before/after runtime. `repositoryCheckout=false`, `rebuild=false`, `relink=false`, `packageRepair=false`, `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `generatedDiscovery=false`, and `benchmarkExecution=false`.

Runtime result is **281/281 PASS**. Partitions are A1 **6/6**, CP4 closed products **2/2**, retained M2 CP1 **5/5**, retained M2 CP2 **34/34**, M1 authority **19/19**, M1 producer **138/138**, M1 completion **36/36**, and M1 validation **41/41**. `failedIdentities=[]`. The final immutable gate-enforcement step passed.

### R3 regression reconciliation

No runtime regression remains in the frozen gate. The three formerly red A1 positives/oracles are now green, so `M3-CP1-TB-CAND-01` is **RESOLVED NON-STABLE**. Every one of the 20 retained predecessor identities still red in package-6 R2 is restored, including M1 producer from **118/138** to **138/138**, so `PR8-R038 / M3-CP1-R001` is **RESOLVED STABLE / RECURRENCE**.

The accepted root cause is the bounded representation defect corrected by R5: sparse cycle aggregation could retain exact algebraic-zero entries; `MeshTopology.cpp` treated a stored zero as positive-sign curvature support while atlas transport construction ignored it. R5 canonicalizes only exact zero before curvature/support iteration, making exact lift/index and composed typed transport consume one semantic cycle support. The strengthened planar square independently exercises that cancellation boundary and now passes with identity transport and exact relative-boundary lift `4`.

**Regression accounting:** resolving the existing stable regression does not erase historical incidence, and the A1 first-runtime candidate never had an accepted-green predecessor. There are no new stable events or recurrences. Historical totals remain **38 events / 14 categories / 24 recurrences**; produced-witness debt remains **5**.

**Disposition:** **M3 CP1 ACCEPTED** on exact `9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` by immutable TB-R3 `32263614534 / 96102598799` at **281/281**. This source/package is now the latest accepted semantic runtime authority. CP1 package consumption remains **7/7** and cumulative M3 remains **8/11**. Exact successor is planning-only `M3-POST-CP1-ALLOC-REPLAN`; CP2 may not start until three remaining M3 packages are explicitly reconciled against the four currently planned Code + Build checkpoints (`CP2`, `CP3a`, `CP3b`, `CP4`).

## Historical package-6 R2 authority and result

- semantic source/package: `95006048225df765b5b9c31e235fed82330a1469 / 9354456191`;
- Code + Build run/job: `32222669309 / 95976032350`; package SHA-256 `da1b4e111642c4b637746c81df1f7d24eb56d47dda9ac3de0a69b5d126313c18`;
- Code + Build log `9354456667`, SHA-256 `2a1b91ff7667b8071e5647bbe9f3004f1fe34851f8ed917fea90a8ef0f1a6d97`;
- source archive SHA-256 `29784cf2c05d56628ece7618d10b7c097eedcd98fde51ade045c8d7008ec63f0`, **557** members, zero symlinks; five source-status snapshots empty;
- TB run/job: `32226787294 / 95987961593`;
- TB result `9355788148`, outer SHA-256 `0aa97b371e0081c094791ed568117685e1c8cfe79b8488fe8c0b28d3e6dd00b8`;
- TB log `9355788629`, outer SHA-256 `9097f7f3859676c6130ab1dc1c8015beae909008af90c325cfcd673292b6040e`;
- retained M2 selector **275**, SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`; A1 selector **6**, SHA-256 `bd00fc5d7840b398b76d834a65fbd30ed400c8ec4a1dab54eeeb554c8ae587ea`; combined **281**, SHA-256 `c73403ab665770282a924dd4534ca261fbdb249d8b832d6644d6a868b452fa83`.

Artifact verification, package manifest, source identity, Code + Build runtime boundary, dependency closure, and selector reconciliation all passed. All **281/281** identities selected. Package and materialized packaged source were byte-identical before/after runtime. `repositoryCheckout=false`, `rebuild=false`, `relink=false`, `packageRepair=false`, `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `generatedDiscovery=false`, and `benchmarkExecution=false`. The evidence-producing runtime step completed successfully; the workflow failed only at the final gate-enforcement step because `gate-status=FAIL`.

Runtime result is **258/281 PASS, 23 FAIL**, exactly the same partition counts as package-5 R1: A1 **3/6**, retained M2 **255/275**. Retained partitions are CP4 **2/2**, M2 CP1 **5/5**, M2 CP2 **34/34**, M1 authority **19/19**, M1 producer **118/138**, M1 completion **36/36**, and M1 validation **41/41**.

### R2 A1 reds — unchanged `M3-CP1-TB-CAND-01`

The same three new A1 contracts still fail because valid baseline atlas construction returns false before their intended positive/oracle proof:

- `FieldTransportAtlas.PublishesReciprocalTypedAuthorityAndRelativeBoundaryWitness` (`built=false`);
- `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix` (`built=false`);
- `FieldTransportAtlas.IndependentTreeCotreeOracleSurvivesRowAndBranchRelabeling` (`baseline=false`).

The other three A1 contracts remain green. These are still first-runtime CP1 contracts with no accepted-green CP1 predecessor, so `M3-CP1-TB-CAND-01` remains **OPEN NON-STABLE** and adds no stable event or recurrence.

### R2 retained predecessor loss — unchanged `PR8-R038 / M3-CP1-R001`

The same **20** retained M2 identities remain red, all within M1 producer (**118/138**). Representative earliest production diagnostics remain `InvalidFieldTransportAtlas:field-transport-atlas/CycleTransportMismatch`; downstream wrong-variant exceptions and unreached mutation/final-oracle seams remain dependent effects of that earlier rejection. No other retained partition regressed.

R4 removed whole-cycle reversal/sign search, made the expected lift immutable, and made the test oracle independently reconstruct source connection/matching/effort, cycle support/orientation, curvature, and exact lift. Immutable R2 nevertheless reproduces the same baseline `CycleTransportMismatch`. This is decisive stop-and-rescope evidence: the prior F5 planning conclusion has not been established against the repository's actual cycle-row/transport convention. TB does **not** prove which premise is wrong; the unresolved boundary may be the mapping from signed `dual_cycles` coefficients to directed edge transport, the curvature/index sign convention, the matching/effort convention, or another assumption in the abstract-to-code derivation. It must be re-derived from one concrete valid baseline before any further semantic mutation.

**Regression accounting:** `PR8-R038 / M3-CP1-R001` remains the same open stable recurrence, not a new event or an additional recurrence. `M3-CP1-TB-CAND-01` remains the same non-stable three-test candidate. Historical totals remain **38 events / 14 categories / 24 recurrences**; produced-witness debt remains **5**.

**Disposition:** CP1 remains **NOT ACCEPTED**, **6/6**; M3 remains **7/11**. M2 remains latest accepted runtime authority at **275/275 + static K=0**. No CP1 package 7 is authorized. Exact next is **`M3-CP1-A1-RESCOPE` Review/planning only**. It must reopen the prior F5 derivation at the concrete repository convention boundary, enumerate and hand-check a valid baseline cycle, and either produce a corrected falsifiable invariant or recommend an explicit A1 design amendment. It may not search another sign, weaken or bypass A1, mutate product/tests/fixtures, compile/package, or execute generated Directional runtime. CP2+ remain blocked.

## Historical package-5 R1 authority and result

- semantic source/package: `f6b46be6eaa3f73cb84c7e6c27b7328d22e5c667 / 9350420635`;
- Code + Build run/job: `32209993498 / 95940623789`; package SHA-256 `553da343e6400ed1acee2272acadafd5f61f59e4d1b8bdf51c3552cb339cc370`;
- source archive SHA-256 `159c70690ca8dfb744fae58dfb4f4058e0425416949eb66798c2df9844eea073`, **550** members, zero symlinks; five source-status snapshots empty;
- TB run/job: `32211699382 / 95945506893`;
- TB result `9350958978`, outer SHA-256 `eb43ba06e63ba230cf9c77bcdf1efc5e856b2adb660b04ce5fac8e3378286793`;
- TB log `9350959164`, outer SHA-256 `a5346129311c70d084124b342f59f3c2c0097e198606ff14dca69a1f4ed6c03e`; contained `activity.log` SHA-256 `de44fd0ee2f63e7d55704782931c66562ec51b5de44d508f849dd9b7bb89bd7f`;
- retained M2 selector **275**, SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`; A1 selector **6**, SHA-256 `bd00fc5d7840b398b76d834a65fbd30ed400c8ec4a1dab54eeeb554c8ae587ea`; combined **281**, SHA-256 `c73403ab665770282a924dd4534ca261fbdb249d8b832d6644d6a868b452fa83`.

Artifact verification, package manifest, source identity, Code + Build runtime boundary, dependency closure, and selector reconciliation all passed. All **281/281** identities selected. Package and materialized packaged source were byte-identical before/after runtime. `repositoryCheckout=false`, `rebuild=false`, `relink=false`, `packageRepair=false`, `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `generatedDiscovery=false`, and `benchmarkExecution=false`.

Runtime result is **258/281 PASS, 23 FAIL**: A1 **3/6**, retained M2 **255/275**. Retained partitions are CP4 **2/2**, M2 CP1 **5/5**, M2 CP2 **34/34**, M1 authority **19/19**, M1 producer **118/138**, M1 completion **36/36**, M1 validation **41/41**. The evidence-producing runtime step completed successfully; the workflow failed only at the final gate-enforcement step because `gate-status=FAIL`.

### R1 A1 reds — `M3-CP1-TB-CAND-01` remains non-stable

Three of the six A1 contracts remain red because valid baseline atlas construction returns false before the intended positive/oracle seam:

- `FieldTransportAtlas.PublishesReciprocalTypedAuthorityAndRelativeBoundaryWitness`;
- `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix`;
- `FieldTransportAtlas.IndependentTreeCotreeOracleSurvivesRowAndBranchRelabeling`.

`FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts` is now green, as are the two previously green rejection contracts. This narrows the first-runtime A1 candidate from four reds to three; it remains non-stable because CP1 has no accepted-green predecessor.

### R1 retained predecessor loss — `PR8-R038 / M3-CP1-R001` remains open

The retained M2 gate improves from **254/275** to **255/275**. `SurfaceCellAuthorityContractCutover.HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped` is restored. The remaining **20** reds are all in M1 producer (**118/138**) and continue to fail before their intended later seams. Representative earliest diagnostics are `InvalidFieldTransportAtlas:field-transport-atlas/CycleTransportMismatch`; later `std::get: wrong index for variant`, `mutated=false`, and unreached final-oracle callbacks are dependent outcomes of that earlier rejection, not separate roots.

The R3 fixes therefore removed the observed `IncompleteCycleBasis` sparse-storage failure and the trivial one-face `CanonicalBindingMismatch` path from the surviving gate reds, but they did not establish A1. The residual failure is now localized to the explicit cycle witness consistency check that compares composed typed `QuarterTurn` transport with normalized cycle `turningLift`. This TB evidence does **not** determine whether the remaining defect is orientation/sign convention, lift derivation, cycle-row interpretation, or another representation-to-authority translation error; that mechanism is the required subject of `M3-CP1-RUNTIME-REPLAN-R2`.

**Regression accounting:** no new independent stable category or accepted-behavior event was exposed. The 20 retained reds are the same already-counted accepted-predecessor loss under `PR8-R038 / M3-CP1-R001`; R1 is refinement/partial repair of that open event, not another recurrence event. Stable totals therefore remain **38 events / 14 categories / 24 recurrences**; produced-witness debt remains **5**.

**Disposition:** CP1 remains **NOT ACCEPTED**, **5/5**, M3 **6/11**. M2 remains latest accepted runtime authority. No CP1 package 6 is authorized. Exact next is **`M3-CP1-RUNTIME-REPLAN-R2` Review/planning only**; it must independently determine the residual `CycleTransportMismatch` mechanism and bound any correction before any request to reopen CP1 package budget. CP2+ remain blocked.

## Prior package-4 immutable runtime evidence

## Immutable authority and boundary

- semantic source/package: `9f54c77ae92161226e833cf313bf38e516aa276c / 9347879320`;
- Code + Build run/job: `32201987864 / 95917547662`;
- package SHA-256: `213cc0dfd06370da71e964271f36e49494bf31633a70c1ae9bfe6bba1b8bcb4a`;
- Code + Build log `9347879687`, SHA-256 `d5ab6b1f7f771b480277f9d298cd4af71e5174be04bc5c0b2f67c4c1eb021b89`;
- retained M2 selector: 275 identities, SHA-256 `67e5e323c8ee3bdea0b5a7117313c9d1586dee0b0ecaf3f6319cc572c474757b`;
- CP1 A1 selector: 6 identities, SHA-256 `bd00fc5d7840b398b76d834a65fbd30ed400c8ec4a1dab54eeeb554c8ae587ea`;
- combined selector: 281 identities, SHA-256 `c73403ab665770282a924dd4534ca261fbdb249d8b832d6644d6a868b452fa83`.

No repository checkout substituted semantic source. `rebuild=false`, `relink=false`, `packageRepair=false`, `sourceMutation=false`, `testMutation=false`, `fixtureMutation=false`, `generatedDiscovery=false`, and `benchmarkExecution=false`. Package and materialized packaged source were byte-identical before/after runtime.

## Runtime evidence

- authoritative TB run/job: `32204335734 / 95924452913`;
- result `9348592210`, outer SHA-256 `3673d8a9ee65fc1a18f69791e152772c4d482d034dae08e4afcf06d8ce8bb8f5`;
- log `9348592414`, outer SHA-256 `911994d141bb53d7e5a930c9bbc194b2d2d85ef196a99afcddf7987b1a6725dc`;
- all **281/281** identities selected; zero-selected filters: **0**;
- **256/281 PASS, 25 FAIL**;
- CP1 A1 **2/6**; retained M2 **254/275**;
- retained groups: CP4 **2/2**, M2 CP1 **5/5**, M2 CP2 **34/34**, M1 authority **19/19**, producer **117/138**, completion **36/36**, validation **41/41**.

The evidence-producing runtime step completed. The workflow conclusion is failure because the final enforcement step correctly rejected `gate-status=FAIL`.

## Four new A1 failures — `M3-CP1-TB-CAND-01`

- `FieldTransportAtlas.PublishesReciprocalTypedAuthorityAndRelativeBoundaryWitness`;
- `FieldTransportAtlas.IndependentOracleRejectsCompleteTypedTamperMatrix`;
- `FieldTransportAtlas.ClassifiesHardFeaturesAsNontraversableCuts`;
- `FieldTransportAtlas.IndependentTreeCotreeOracleSurvivesRowAndBranchRelabeling`;

All four fail before their intended positive/oracle proof because the baseline atlas is not constructed. They are semantic evidence but non-stable because new CP1 capability has no accepted-green predecessor.

## Twenty-one accepted predecessor regressions — `PR8-R038 / M3-CP1-R001`

- `SurfaceCellPipelinePhase20.AuthoritativePhaseFrontPropagatesBoundaryAndHardFeatureRailsThroughFlowRepAndArrangement`;
- `SurfaceCellsPhase10.ExactCommittedPlaneUsesAuthoritativeProductionProducerBoundary`;
- `SurfaceCellAuthorityContractCutover.ProductionAggregationCounterfactualIgnoresPreConsumerRawProjectionTamper`;
- `SurfaceCellAuthorityContractCutover.ProductionAggregationRejectsUnownedTypedRemapWithZeroPublication`;
- `SurfaceCellAuthorityContractCutover.PostMoveSingleComponentOptimizerUsesRetainedSourceAuthority`;
- `SurfaceCellAuthorityContractCutover.DisconnectedAggregationPublishesGlobalOwnerAndRebuildsIdentityCaches`;
- `SurfaceCellAuthorityContractCutover.DisconnectedAggregationDoesNotPublishStalePreRemapIdentityCaches`;
- `SurfaceCellAuthorityContractCutover.AggregateIdentityRebuildReportsInvalidPatchMetadataSubInvariant`;
- `SurfaceCellAuthorityContractCutover.ComponentBoundaryRailTamperRejectsAtAggregationSeam`;
- `SurfaceCellAuthorityContractCutover.HardFeatureRegionDeclinedByAllPhaseFrontProducersFailsClosedTyped`;
- `SurfaceCellAuthorityContractCutover.RectangularInternalHardFeatureProducesAuthoritativePhaseFrontPerComponent`;
- `SurfaceCellAuthorityContractCutover.FinalOracleRejectsMissingForeignOrUncertifiedHardRailChartAuthority`;
- `SurfaceCellAuthorityContractCutover.ComponentFeatureRailTamperRejectsAtAggregationSeam`;
- `SurfaceCellAuthorityContractCutover.FinalMergedOracleRejectsMissingRemappedBoundaryAuthority`;
- `SurfaceCellAuthorityContractCutover.FinalMergedOracleRejectsMissingRemappedFeatureAuthority`;
- `SurfaceCellAuthorityContractCutover.FinalMergedOracleRejectsChangedRemappedBoundaryLoopContent`;
- `SurfaceCellAuthorityContractCutover.FinalMergedOracleRejectsChangedRemappedFeatureRailContent`;
- `SurfaceCellAuthorityContractCutover.FeatureBearingFinalMergedOracleAcceptsPresentRemappedFeatureAuthority`;
- `SurfaceCellAuthorityContractCutover.FinalOracleOutcomePublishesWhenComponentValidationReportIsMissing`;
- `SurfaceCellAuthorityContractCutover.SecondComponentAuthorityFailurePublishesNoSemanticAggregateContext`;
- `SurfaceCellAuthorityContractCutover.FinalMergedOracleRejectsPostComponentProvenanceTamper`;

Representative earliest diagnostics are `InvalidFieldTransportAtlas:field-transport-atlas/IncompleteCycleBasis` on valid plane/disconnected/hard-feature production paths and `field-transport-atlas/CanonicalBindingMismatch` on the retained hard-feature decline path. Later `std::get: wrong index for variant` and unreached mutation seams are dependent outcomes of the earlier atlas rejection, not separate roots.

## Root cause

CP1 inserted `FieldTransportAtlas::make` before phase-front/tracing. The factory reconstructs a local region mesh, initializes `PCFaceTangentBundle`, and consumes its `dual_cycles`/`bundle.cycles` representation as complete A1 cycle/topology authority. That is a stage-local tangent-bundle representation: boundary vertex cycles are aggregated/restricted to its interior-edge representation and its generic tree/cotree path omits boundary generators. It is not the CP0-frozen source-bound A1 proof requiring explicit oriented relative-boundary cycles, checkable cut-to-disc/tree-cotree authority, and exact relative-index facts. Local reconstruction is also elevated into source binding, consistent with the retained `CanonicalBindingMismatch` failure.

**Classification:** `PR8-R038 / M3-CP1-R001`, `RP-01 / AUTHORITY_DOMAIN_CONFLATION`; detection escape `RP-02 / TEST_AUTHORITY_COVERAGE_GAP`. The 21 retained failures share this single earlier production rejection. Historical totals become **38 events / 14 categories / 24 recurrences**; produced-witness debt remains **5**.

## Disposition

CP1 is **NOT ACCEPTED**. CP1 is 4/4, M3 is 5/11, and no package 5 is authorized. M2 remains latest accepted runtime authority at `9fda64e88ddc885ce993ff8da3ad6a51765724a4 / 9340456431`, `32183306224 / 95861164621`, **275/275 + static K=0**.

Exact next is **`M3-CP1-RUNTIME-REPLAN` Review/planning only**. It must independently review the A1 source-binding/relative-boundary cycle boundary, decide whether the frozen A1 design remains correct or needs an explicit amendment, bound the smallest correction, and require explicit user authorization for any additional CP1 package/local-cap change. No product/test/build edit, compile, package, or generated runtime is authorized in that review.
