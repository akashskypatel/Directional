# M4-CP-COND-CB4 Code + Build Plan

**Turn:** `M4-CP-COND-CB4`
**Type:** Code + Build / selector-authority + package-closure only / runtime-free
**Owner candidate:** `M4-CP-COND-TB3-REV-CAND-01`
**Product semantic source:** unchanged `b576d061e23873b7b4193b158138d2097c75a728`
**Test-authority source:** unchanged `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`
**Accepted predecessor selector:** selector408, 408 LF rows / `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`
**Runtime in CB4:** forbidden

## 1. Objective

Satisfy the frozen CP-COND cumulative-selector exit contract without changing any semantic implementation or test byte. Publish one append-only selector422 consisting of the accepted selector408 prefix followed by the fourteen already-runtime-proved CP-COND gating identities in their frozen focused order, then compile/package the complete unchanged owner set for artifact-only TB4.

This is a control experiment. The only semantic authority change authorized is **selector membership/publication** for already-authored tests. It must not be combined with any product/test/fixture/CMake correction.

## 2. Mandatory pre-mutation falsifiers

Before creating selector422:

1. hash selector408 to exactly `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484` and first403 to `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`;
2. prove all fourteen identities below exist exactly once in the packaged/current unchanged test source and all resolve to `directional_surface_cell_producer_tests`;
3. prove none of the fourteen identities is already present in selector408;
4. prove the report-only `BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` identity is absent from selector408 and remains non-selector;
5. compare code/test/fixture/CMake surfaces against semantic/test source `4d9206cd...e675`; any drift beyond selector/manifest/docs is a STOP;
6. verify no selector row 1-408 would change byte-for-byte/LF-normalized.

If any falsifier fails, **STOP before selector mutation** and return to Review/DEFN. Do not repair a name, owner, test, product or prefix inside CB4.

## 3. Exact selector422 append order

Append exactly these fourteen identities after row 408:

409. `InputConditionerCPCondCB1.IdentityProducedSeparatesRawAndSemanticDigests`
410. `InputConditionerCPCondCB1.ExactDyadicQuantizationRecordsNonEmptyOperation`
411. `InputConditionerCPCondCB1.ExactEqualityMergeUsesMinimumRawOwner`
412. `InputConditionerCPCondCB1.UnsafeDisconnectedExactMergeIsTypedRefusal`
413. `InputConditionerCPCondCB1.ExactRationalSliverPredicateRefusesWithoutRepair`
414. `InputConditionerCPCondCB1.HighValenceRawPreconditionIsIndependentAndProduced`
415. `InputConditionerCPCondCB1.NegativeIndexRawPreconditionIsIndependentAndPreserved`
416. `InputConditionerCPCondCB1.ContradictoryExactZ4PairingIsTypedRefusal`
417. `InputConditionerCPCondCB1.CertificateTamperMatrixRejectsEveryAuthorityClass`
418. `InputConditionerCPCondCB1.IdempotenceHoldsForCleanAndNonEmptyOperationProducts`
419. `InputConditionerCPCondCB1.ExactSameLatticeCellPerturbationsShareSemanticDigest`
420. `InputConditionerCPCondCB1.LegacyPreconditionerCannotSubstituteForCertificate`
421. `InputConditionerCPCondCB1.TolerantRawFieldFinalizationCannotReplaceExactCertificate`
422. `InputConditionerCPCondCB1.SurfaceCellsRawEntryRejectsAtConditionerBeforeA0`

Update `Required_Green_Selector_Manifest.md` additively with selector422 line count, full LF SHA-256 and predecessor-prefix SHA after the file is created. Do not edit older selector files.

Expected owner census becomes **30 authority-kernel / 276 producer / 75 completion / 41 validation = 422**.

## 4. Frozen exclusions

No semantic changes to:

- `src/**`, `include/**`, `tests/**`, `benchmarks/**`, CMake/build ownership or fixtures;
- any existing selector file or row;
- product/public API/A0-A4 semantics;
- CP-COND witness bodies or expected outcomes;
- the report-only boundary identity or its blocker text;
- reusable workflow permissions/behavior.

No Directional runtime is authorized in CB4.

## 5. Compile/package gate

Compile only through the approved GitHub workflow with GMP/GMPXX and `runtimeExecution=false`.

Required target set:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`

Package all four selector-owner executables, compiled API, required libraries, selector422 + selector408 lineage, source archive, checksums/modes and clean source receipts. The package must state no Directional runtime occurred.

## 6. Frozen TB4 handoff

On compile/package GREEN, freeze `M4-CP-COND-TB4-EXEC` against that exact artifact:

- selector422: **422 fresh exact-filter processes**, one per row in selector order;
- report-only boundary identity: **1 fresh exact-filter process**, expected SKIP/non-selector;
- rows 1-408 must be exact accepted predecessor and **408/408 PASS**;
- rows 409-422 must be the fourteen CP-COND gates above and **14/14 PASS**;
- total processes **423**; gating total **422/422 PASS**;
- zero RED/crash/timeout/selection mismatch;
- exact package/source/selector/execution-view postflight;
- checksum-manifest generation must be non-self-referential so `sha256sum -c` passes its own published manifest without special casing.

TB4 must not rebuild/repair/mutate the artifact. Mandatory successor is `M4-CP-COND-TB4-REV`; only that Review may promote selector422/package authority and close CP-COND.

## 7. STOP rules

STOP and return to Review/DEFN if selector422 publication requires:

- changing any test body/name/owner;
- changing a product/API/CMake semantic;
- altering any selector408 prefix byte;
- placing the boundary report-only identity into the selector;
- weakening a precondition or expected result;
- repairing package/runtime bytes after compile; or
- treating compile GREEN as runtime acceptance.
