# M4-CP4-TB1-R2-EXEC — corrected artifact-only Test + Benchmark plan

**Turn:** `M4-CP4-TB1-R2-EXEC`
**Type:** artifact-only Test + Benchmark
**Predecessor:** `M4-CP4-CB3`
**Candidate artifact:** `10575545321`
**Exact compiled source:** `ad54c12774e10480fd3cef8138cacb8d5dec1529`

## 1. Purpose

Re-execute the frozen CP4 focused+cumulative runtime gate after CB3 corrected only `M4-CP4-TB1-R1-ORCH-01`. R2 must establish trustworthy semantic evidence without rebuilding, relinking, repairing, mutating or discovering generated Directional runtime. Candidate package and every semantic byte remain unchanged from CB2/R1.

## 2. Frozen immutable authority

Before any generated process, verify exactly:

- candidate artifact ID `10575545321`;
- provider/package ZIP SHA-256 `602632ed05f2d6e8a4c9ccbfb1ef135417b1d1e2eb30c2c29e74892007f7ba00`;
- package source commit `ad54c12774e10480fd3cef8138cacb8d5dec1529`;
- packaged source archive SHA-256 `781155c61419f999ebb9631136ca24e998f01dff0c160b071240c946b4afa4ed`;
- complete recursive 28-entry package manifest;
- all five actual clean source-status receipts;
- `runtimeExecution=false`, `exactArithmeticBackend=GMP`, `semanticContracts=compiled-not-executed` package boundaries;
- GMPXX + GMP link evidence;
- selector `Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt`: exactly **427 LF rows**, no CRs, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`;
- independently reconstructed owner partition **30 / 281 / 75 / 41**;
- all four selector-owner executables present and executable with archived mode `0755`.

Artifact extraction must preserve archived executable modes. Do not chmod, rewrite, repair or repack the candidate.

## 3. Frozen R2 controls

Recover exact frozen bytes from the CB3 recovery commits before execution:

- harness recovery commit `9bf694a11f0c5d3b5516f5569f9bf931a3b9321a`: **19,885 bytes**, SHA-256 `78ab110f8ad851b66fcc331ef02b3a02388f51147efcd4672f2c9bfc7fd750dd`;
- caller-draft recovery commit `3e49e0fe25f37db01a263fccf6aaaa2f9f2c45c2`: **4,974 bytes**, SHA-256 `e21b17f12b18b7e3a45d97dba322a063cc8a64cf911e040fb6bbe60f832e5a2d`.

Install the caller as `.github/workflows/m4-cp4-tb1-r2-exec.yml` without changing its bytes except the already-frozen draft path becoming the active workflow path. The caller was SchemaStore-validated green in CB3 run/job `35416505731 / 105826099635`. Freeze and re-record harness/caller receipts at the R2 event SHA before runtime.

CB3 changed only `run_one` process-status capture so it no longer toggles caller `errexit`; semantic nonzero may return to the outer loop without terminating the harness. Do not broaden or reinterpret this correction.

## 4. Runtime boundary

Forbidden in R2:

- configure, compile, relink or generated-code regeneration;
- generated test discovery, list/help/version calls or `ctest`;
- package/source/test/fixture/selector mutation;
- chmod or other mode repair;
- benchmark execution or custom inputs;
- retrying a semantic RED in the same turn;
- elapsed-time cutoff on the complete semantic gate.

Every selected identity executes in a **fresh generated test process** with `GTEST_FAIL_IF_NO_TEST_SELECTED=1`. Zero-selected, multiple-selected or skipped identities are not passes.

## 5. Focused surface — six rows, exact order

Execute all six focused rows unless orchestration integrity fails:

1. `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated`
2. `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle`
3. `M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering`
4. `M4CP4.ProducedTorusMissingPeriodicRelationOwnerIsRejected`
5. `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder`
6. `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection`

A semantic RED/SKIP/crash in this focused phase is valid evidence and must **not** stop the remaining focused rows. Only orchestration invalidity stops the focused surface. Record exactly-one-selected, exit status, PASS/RED/SKIP/crash classification and raw-log SHA-256 for every executed row.

## 6. Cumulative selector427

If orchestration remains valid after the focused phase, execute selector427 in exact file order, one fresh process per identity. The selector phase stops after its **first semantic non-green** because that is sufficient gating evidence; orchestration invalidity stops immediately. If no semantic non-green occurs, all **427/427** rows must execute and pass.

The complete planned ledger has **433 rows = 6 focus + 427 selector**. Benchmark execution count is **0**.

## 7. Mandatory immutable postflight

Whenever generated runtime starts, postflight is mandatory even when semantic evidence is non-green. Re-census and compare:

- untouched package tree bytes + modes;
- extracted packaged-source tree bytes + modes;
- immutable execution-view bytes + modes;
- recursive package manifest re-verification.

Any mismatch makes the attempt orchestration-invalid. Preserve the final 433-row ledger with unexecuted rows explicit, raw per-process logs, boundary counters, pre/post censuses and recursive result-manifest evidence.

## 8. Disposition

- **Orchestration valid + semantic outcome (green or non-green):** next turn is mandatory runtime-free **`M4-CP4-TB1-R2-REV`**. Review independently adjudicates focused evidence, any selector stop, immutable postflight, produced-witness/debt credit, test-vs-product ownership and any publication requirement. EXEC does not promote the package itself.
- **Orchestration invalid:** no semantic acceptance credit; route to the smallest diagnosed control/package correction CB without changing semantic bytes unless Review/Plan separately authorizes it.

The R1 row-2 rawfield-header observation remains diagnostic-only until R2 completes this trustworthy control/postflight contract and Review adjudicates it.
