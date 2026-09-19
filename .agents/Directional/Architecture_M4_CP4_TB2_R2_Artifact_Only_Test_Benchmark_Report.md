# M4-CP4-TB2-R2-EXEC — immutable composite Test + Benchmark report

**Turn:** `M4-CP4-TB2-R2-EXEC`
**Result:** **COMPLETE / ORCHESTRATION VALID / SEMANTIC NON-GREEN / REVIEW REQUIRED**
**Run / execute job:** `35449574130 / 105914294127`
**Event SHA:** `7fa7ee4351f35893194ebddd7890b0d00e1cd20a`

## 1. Frozen authority and pre-runtime controls

R2 consumed the unchanged immutable CB4+CB5 composite authorized by CB7. Full CB4 artifact `10578784752` remains source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a` with provider ZIP SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`; CB5 delta `10582435470` remains source `4e9ff5003c8dd165dd614c25dd95f0308403719b` with provider ZIP SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`. Package manifests re-verified **28/28 + 24/24**, clean source receipts and GMP/GMPXX compile evidence were present, and the only semantic source deltas were `tests/FieldTransportAtlasTests.cpp` and `tests/SurfaceComplexSimplificationPhase17Tests.cpp`.

The installed corrected caller is 5,532 bytes / SHA-256 `488326cd8cbf1ee4078796b8ecd7031f578b87272eb62df5fa2d7d42fd42d719`; the frozen harness is 30,249 bytes / SHA-256 `1dcdd6c6e638b0951af0af38ce2b0e34fafcc877843104e617caf175cf36aeba`. Installed-caller validation run `35449546449` is GREEN for SchemaStore validation and the independent static permission/timeout boundary. Its static receipt artifact `10585513093` has provider SHA-256 `f65de2c61802a3acd800cb6825077098f3d909d3f715716dd77a242d9b24e8a2` and records exact `actions: read / contents: write / issues: write / pull-requests: write`, `commit_run_file=false`, installed-equals-durable-draft, and `static_permission_ceiling_valid=true`.

Selector427 remained exact at **427 LF rows / 34,783 bytes / SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`** with reconstructed owner census **30 / 281 / 75 / 41**. Producer/validation rows used CB4; authority-kernel/completion rows used CB5. No prior TB2/R1 row received credit.

## 2. Focused M4-owned evidence

All four focused identities executed once in fresh exact-filter processes, with one selected test and zero skips each.

| Row | Identity | Package / owner | Result | Raw-log SHA-256 | Decisive observation |
|---:|---|---|---|---|---|
| 1 | `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` | CB4 / producer | **PASS** | `2723c9c6d57c55f309c4889d95dd9c2a13cb2cb1c39d3ef6ed0ec5d54576665b` | one selected / one passed |
| 2 | `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` | CB5 / completion | **RED** | `57600cae93bbc0e2b51a5f1535ef42806f52e9706fcf0510d68166bd8d7a1ac1` | `Produced torus did not retain arrangement authority: NotProductionReady/tracing` |
| 3 | `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` | CB4 / producer | **PASS** | `f72ed051f59e9ccd0f842fe8c7a77ad3297eed731332df4ff5007038946978e8` | produced multiplicity-two witness passes |
| 4 | `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` | CB5 / authority-kernel | **PASS** | `fe73d744fd4884e69cea92a58e131c45dee1e9fb3b7fe5f17e46f25a1713cb2d` | corrected exact typed expectation passes |

Focused total is **3 PASS / 1 RED / 0 SKIP / 0 selection mismatch**. The harness correctly retained the first semantic RED as focus row2 and continued through all later semantic rows.

## 3. Cumulative selector re-proof

After the focused phase, selector427 executed in exact frozen order as **427 fresh processes**. Result is **427/427 PASS**, zero selector RED/SKIP/crash/selection mismatch/unexecuted. Owner-pass census is exactly authority-kernel `30`, producer `281`, completion `75`, validation `41`.

The complete semantic ledger is therefore **431 rows = 430 PASS / 1 RED**, with `invalid_rows=0`. Benchmark execution count is `0`.

## 4. Immutable postflight and execution boundary

Runtime started and completed, so mandatory postflight ran and passed. `immutability.txt` records equality of both CB4/CB5 package censuses, both packaged-source censuses, the composite execution-view census, selector bytes, and both package manifests before/after runtime. Result `SHA256SUMS` verifies the complete harness evidence set.

`execution-boundary.txt` records `runtime_started=true`, `runtime_completed=true`, `preflight_completed=true`, `postflight_complete=true`, `orchestration_failure=false`, `semantic_non_green=true`, `selection_integrity=true`, `focus_executed=4`, `selector_executed=427`. Configure, compile, relink, generated discovery, repair, package repair, mode repair, source mutation, test mutation, fixture mutation, selector mutation and benchmark counters are all zero.

Primary result/log artifacts are `10586074692 / 10586214778`, provider SHA-256 `b1e29556f3d0506c0f2319634d7e94872dbc7267576712fa2180c2d55c92f615 / 2335b11c76e3d5026f5b237d007b426827976748e8cbf1fda8f33c10a011893e`.

Resume/closeout source snapshot run/job `35450891152 / 105917752054` captures exact branch authority at event SHA `426b78981c936e1314b8e83e45eadd286f2f8bc3`; source artifact `10585544264` has provider SHA-256 `a329cead3afe29751e241b24d3dccf921d10ac26f8ec1dd476b4e6c4e1ac8d23`, with `source.tar.gz` SHA-256 `8b76c2fb2554e535cce61a5e17123604fb4b489dfe26305e95c2da2325a4679d` and `runtimeExecution=false`.

## 5. Regression classification and semantic boundary

`M4-CP4-TB2-R2-CAND-01` is **OPEN / SAME ROOT AS `M4-CP4-TB1-R3-CAND-01` / TEST_AUTHORITY_WITNESS_REACHABILITY / NON-STABLE**. CB5 successfully aligned the test-local torus input options to the accepted row408 hard-rail setup, but that correction did not establish the later retained-arrangement precondition the focused candidate-extraction test actually requires. Accepted row408 proves its A3→A4 `phaseFront` reaches `Produced`; the focus row separately requires `surfaceCellContext.hasArrangement`, which is published only at the later arrangement stage. R2 stops at `NotProductionReady/tracing` before that later authority exists, so the independent candidate oracle/tamper remains unreached. This is an insufficient test-authority witness correction, not evidence of an accepted product regression.

No accepted selector row regressed. Consequently R2 adds **+0 stable event / +0 category / +0 recurrence**; stable totals remain **49 events / 14 categories / 35 recurrences**, produced-witness debt remains **5**, and accepted runtime authority remains package `10565723112` / source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**.

Focus row4 mechanically re-proves the CB5 `NonIntegralCycleLift` correction for `M4-CP4-TB1-R3-CAND-03`; focus row3 mechanically re-proves the produced same-region multiplicity-two identity. Final closure/debt/exit credit belongs to Review, not EXEC. The two periodic `G4-B002` debts remain M5-owned and receive no R2 credit.

## 6. Disposition and successor

R2 is **orchestration-valid semantic evidence** and therefore routes to mandatory runtime-free Review. EXEC does not promote the CB4/CB5 composite, discharge debt, close CP4, alter selector427, or authorize implementation.

Exact successor: **`M4-CP4-TB2-R2-REV`** under `Architecture_M4_CP4_TB2_R2_Review_Plan.md`.
