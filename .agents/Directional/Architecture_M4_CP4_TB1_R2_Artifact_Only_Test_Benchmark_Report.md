# M4-CP4-TB1-R2-EXEC — corrected artifact-only Test + Benchmark report

**Turn:** `M4-CP4-TB1-R2-EXEC`
**Result:** **COMPLETE / ORCHESTRATION VALID / SEMANTIC NON-GREEN / REVIEW REQUIRED**
**Candidate artifact:** `10575545321`
**Exact compiled source:** `ad54c12774e10480fd3cef8138cacb8d5dec1529`
**Run / execute job:** `35417670510 / 105829346816`
**Event SHA:** `50b0fade072dd4cd938f7f2990ad0195dd4ff365`

## 1. Immutable preflight and control authority

R2 consumed candidate artifact `10575545321` exactly once and re-proved the frozen package/control authority before generated runtime:

- provider/package ZIP SHA-256 `602632ed05f2d6e8a4c9ccbfb1ef135417b1d1e2eb30c2c29e74892007f7ba00`;
- exact package source `ad54c12774e10480fd3cef8138cacb8d5dec1529`;
- packaged-source archive SHA-256 `781155c61419f999ebb9631136ca24e998f01dff0c160b071240c946b4afa4ed`;
- complete 28-entry package manifest and all five clean source-status receipts;
- `runtimeExecution=false`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed`, with GMPXX+GMP evidence;
- selector427 exactly **427 LF rows**, zero CR, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f` and independently reconstructed owners **30 / 281 / 75 / 41**;
- all four selector-owner executables present with archived mode `0755`;
- corrected R2 harness **19,885 bytes**, SHA-256 `78ab110f8ad851b66fcc331ef02b3a02388f51147efcd4672f2c9bfc7fd750dd`;
- R2 caller **4,974 bytes**, SHA-256 `e21b17f12b18b7e3a45d97dba322a063cc8a64cf911e040fb6bbe60f832e5a2d`.

No configure, compile, relink, generated discovery/list/help/version, package or mode repair, benchmark, custom input, or source/test/fixture/selector mutation occurred.

## 2. Focused CP4 evidence

All six focused identities executed as fresh one-selected processes. The corrected CB3 control flow successfully continued after semantic nonzero results.

| Row | Identity | Result | Raw-log SHA-256 | Decisive observation |
|---:|---|---|---|---|
| 1 | `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` | **PASS** | `2723c9c6d57c55f309c4889d95dd9c2a13cb2cb1c39d3ef6ed0ec5d54576665b` | one selected / one passed |
| 2 | `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` | **RED** | `fa57ce376664413ba4879a8e11cda3e2c1dce2c7d0b63bda61252351da011c05` | exception `Invalid rawfield fixture header` for packaged `milestone-g/torus.rawfield` |
| 3 | `M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering` | **RED** | `72d0d3a0d7689e2fd8b595c76a31d6bed4299a592065d1f2fd6a7ac9619e3aea` | produced torus pipeline stops at `InvalidBoundedDiskBoundaryTurn` |
| 4 | `M4CP4.ProducedTorusMissingPeriodicRelationOwnerIsRejected` | **RED** | `6b7c07c27d001b3d191dc095ab77a213ec5bc00b30c334ff339dc0704840a353` | same upstream `InvalidBoundedDiskBoundaryTurn` before the intended missing-owner discriminator |
| 5 | `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` | **PASS** | `f72ed051f59e9ccd0f842fe8c7a77ad3297eed731332df4ff5007038946978e8` | one selected / one passed on produced same-region multiplicity-2 |
| 6 | `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` | **RED** | `44df528545f3907407149ce08d114b2b77624b27870372be28d7c0e7a0192403` | `FieldTransportAtlasTests.cpp:311`: `nonFlatAtlas` actual `true`, expected `false` |

Focused total: **2 PASS / 4 RED / 0 SKIP / 0 selection mismatch**. EXEC records these observations only; test-vs-product ownership, debt credit and corrective scope belong to Review.

## 3. Cumulative accepted-prefix reproof

Despite focused semantic RED, orchestration remained valid, so the exact selector427 phase executed in order as required. It completed **427/427 PASS**, one fresh one-selected process per identity. No selector RED, SKIP, crash, selection mismatch or unexecuted row occurred. Historical row408 remained green, and final selector row427 `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology` passed with raw-log SHA-256 `3621f15cab27f8bd9c0b8acef14b78313e2c93b53cb64e6b73ef5d39ec4d47be`.

The complete 433-row ledger therefore records **429 PASS / 4 RED**: focus **2 PASS / 4 RED**, selector **427 PASS**. Benchmark execution count is `0`.

## 4. Mandatory immutable postflight

Generated runtime started, and mandatory immutable postflight completed successfully. Before/after byte+mode censuses are identical:

- package tree: `02e64671eaeeaeeade7925430d9164d35ba32bba23943bab26f886732c7ee0a4`;
- packaged-source tree: `da9332f2c6d0f38f6d49071ad6cac085f4bdc9643fc09159a664dc2e059ca742`;
- execution view: `bafff98c84d712eb85ebb2074ba5038e29f2c7d319836bc0ccbfb668b1808f85`.

The package manifest re-verifies all 28 entries after runtime. Result evidence contains 433 ledger rows and a recursive 451-entry `SHA256SUMS`, which verifies. Final boundary records `runtime_started=true`, `postflight_complete=true`, `orchestration_failure=false`, `semantic_non_green=true`, `focus_executed=6`, `selector_executed=427`, with all configure/compile/relink/discovery/repair/mutation counters and benchmark count equal to zero.

The boundary's `stop_reason=semantic_red_focus_6` reflects the last focused RED because `run_one` overwrites the reporting field on each semantic non-green even though its comment says to retain the first. The full ledger/raw logs remain unambiguous, so this is retained for Review as a reporting-control observation rather than an orchestration invalidator.

## 5. Immutable evidence

Primary result/log artifacts are `10576548553 / 10575999074`, provider SHA-256 `eb5b86fd219632f11358bafea6f9054a37795a13bd953805acca9dca1dfb971b / 3d4d2d15dc534eea9dc6b98014811b7142b274d9c9f96eedf063a43233714fd9`.

Closeout source snapshot run/job `35418348030 / 105831238306` captures exact post-runtime branch authority `101a28f58790da177ccffb180f18dafa17053abd`; snapshot/log artifacts are `10576745476 / 10576925250`, provider SHA-256 `b90c4071487067d5b4c192d0ccbc83e828214874619c122515d71267bf37547f / e47cb226d2182d9790943ef738948ac17469ae77e4f0a670d227931620e1346e`.

## 6. Disposition

R2 is **trustworthy semantic evidence** and therefore routes to mandatory runtime-free Review. EXEC does not promote candidate `10575545321`, decide whether the four focused REDs are product or test-authority defects, discharge produced-witness debt, change stable regression accounting, or publish new selector rows.

Accepted M4 runtime authority remains package `10565723112` / exact source `6fe075f7d9397a561fe50b79517b4f714fb9eeef` / selector427 **427/427**. Stable accounting remains provisionally **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**, pending Review adjudication.

## 7. Successor

Exact successor: **`M4-CP4-TB1-R2-REV`** under `Architecture_M4_CP4_TB1_R2_Review_Plan.md`. Review must independently adjudicate all four focused REDs, the two focused PASSes, selector427 cumulative evidence, immutable postflight, the `stop_reason` reporting mismatch, regression/debt accounting, and exactly one corrective/publication successor path.


## 8. Closeout transport and cleanup provenance

Durable R2 closeout documentation was transported as the exact preservation patch `Directional__M4-CP4-TB1-R2-EXEC__base-101a28f58790__work-preservation.patch`, based on `101a28f58790da177ccffb180f18dafa17053abd`, with full patch SHA-256 `0d33d2277902a9381bfa412399970243ab6aa59650efec4a1b746d8979f307d0` and diff-body SHA-256 `3df24234c5aa7bc7bcd0a71198ba69438149d6078a783d357d0b35518a27a042`. Google Drive apply run/job `35418711167 / 105832247460` consumed staged file ID `1qP868IC6zcdqZ6Zf6bF4DMd4Wy4po7TD`, verified the patch envelope, and pushed durable documentation commit `76c28b11102f910fdd45aa7d4fed9612330a086a` with `runtimeExecution=false`. Apply result/log artifacts are `10575999765 / 10576499278`, provider SHA-256 `25c75fa767758a3cfa961c7c2cd65d4ac1e29b32fb28bde73fdc9c988f39051a / b4f4f099c54d875d48fcc217b8aaca04f1fde8297c9280717672d9c960374c70`. The workflow reported owner-side retirement required; the exact staged File ID was already inaccessible to the owner-authorized Drive connector at the subsequent retirement check (404), so no remaining staged object could be mutated.

Temporary runtime and closeout workflow callers were deleted before cleanup. Mandatory batch cleanup run/job `35419084150 / 105833227904` consumed event SHA `96e97b7a525cb08febf30cedd688b513bedba447` and pushed cleanup commit `188cd891f6e213c21f0ef6d1dca827a0fe129778`. Cleanup result/log artifacts are `10577150922 / 10576711349`, provider SHA-256 `4027768c055979150539645e5335b67fc9c731e30e25cace2438b8491ad7bc17 / f5dd805138f59d6af19e9f7beb57e9fb790abc2916d59b192a277e1fd718af82`. Cleanup removed both R2 source-snapshot markers, the runtime trigger, frozen harness payload, closeout Drive marker and cleanup manifest; validated the seven-workflow durable inventory; deleted five PR conversation comments and zero inline review comments before observer publication; and recorded `runtimeExecution=false`.
