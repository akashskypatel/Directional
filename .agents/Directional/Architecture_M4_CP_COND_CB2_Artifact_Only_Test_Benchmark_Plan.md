# M4-CP-COND-CB2 Artifact-Only Test + Benchmark Plan

**Authoring turn:** `M4-CP-COND-CB2`
**Authorized runtime turn:** `M4-CP-COND-TB2-EXEC`
**Mandatory review successor:** `M4-CP-COND-TB2-REV`
**Immutable package:** artifact `10321878900`, ZIP SHA-256 `d8016a8d0b30c8edcbbd64ac96d752ee5087fd35dc568a1b1c9e4cef9a66ee28`
**Semantic source:** `b576d061e23873b7b4193b158138d2097c75a728`
**Execution boundary:** immutable CB2 package only; no rebuild, configure, relink, package repair, source/test/fixture/selector mutation, generated discovery, or benchmark substitution.

## 1. Objective

Re-run the semantic gate frozen for TB1 against the package-closed CB2 artifact. TB2 changes no semantic gate and introduces no new acceptance identity. Mechanical outcomes remain unadjudicated until `M4-CP-COND-TB2-REV`.

## 2. Immutable preflight — fail closed before any Directional process

Before runtime:

1. Verify artifact/provider SHA-256 exactly `d8016a8d0b30c8edcbbd64ac96d752ee5087fd35dc568a1b1c9e4cef9a66ee28` and every one of the 27 root `SHA256SUMS` entries; require manifest SHA-256 `10f45675750aca16d99fbc69a6affc1a75dd5b112977de5fb32da34e47bf37ad`.
2. Verify semantic-source receipt exactly `b576d061e23873b7b4193b158138d2097c75a728`, packaged source archive SHA-256 `31e667a6891f9f9d2c938da98c7d23d048c3d60f6960e139e379631e7aa70c10`, empty source-status receipts, build/preflight exits zero, GMP/GMPXX evidence and `runtimeExecution=false`.
3. Verify the exact existing owner/API binaries exist and retain executable mode in the immutable package:
   - `bin/directional_surface_cell_authority_kernel_tests`
   - `bin/directional_surface_cell_producer_tests`
   - `bin/directional_surface_cell_completion_tests`
   - `bin/directional_surface_cell_validation_tests`
   - `bin/directional_compiled_api_tests`
4. Re-hash `.agents/Directional/Architecture_M4_CP3_CB5_Required_Green_Selector_408.txt`: exactly 408 LF rows, SHA-256 `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`; first403 prefix SHA-256 `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`.
5. Resolve the 408 selector identities statically to the existing owner binaries, without generated discovery. The frozen ownership census is 30 authority-kernel / 262 producer / 75 completion / 41 validation = 408; require every identity to resolve to exactly one packaged owner.
6. Resolve all 14 focused CP-COND identities and the one report-only identity to exactly one packaged owner without executing a binary.
7. Materialize a separate execution view without altering package bytes or modes and census package/source/selector/execution-view before runtime.

Any mismatch is **PACKAGE/ORCHESTRATION PREFLIGHT RED**, stops before the first Directional process, and yields zero semantic test credit. Do not repair, chmod, rebuild, substitute or augment the package.

## 3. Fresh-process CP-COND focused census

Run each selected identity exactly once in its own process with an exact `--gtest_filter`. Record exit, selected-count, gtest status, elapsed time and exact stdout/stderr.

Prospective gating identities, unchanged from TB1:

1. `InputConditionerCPCondCB1.IdentityProducedSeparatesRawAndSemanticDigests`
2. `InputConditionerCPCondCB1.ExactDyadicQuantizationRecordsNonEmptyOperation`
3. `InputConditionerCPCondCB1.ExactEqualityMergeUsesMinimumRawOwner`
4. `InputConditionerCPCondCB1.UnsafeDisconnectedExactMergeIsTypedRefusal`
5. `InputConditionerCPCondCB1.ExactRationalSliverPredicateRefusesWithoutRepair`
6. `InputConditionerCPCondCB1.HighValenceRawPreconditionIsIndependentAndProduced`
7. `InputConditionerCPCondCB1.NegativeIndexRawPreconditionIsIndependentAndPreserved`
8. `InputConditionerCPCondCB1.ContradictoryExactZ4PairingIsTypedRefusal`
9. `InputConditionerCPCondCB1.CertificateTamperMatrixRejectsEveryAuthorityClass`
10. `InputConditionerCPCondCB1.IdempotenceHoldsForCleanAndNonEmptyOperationProducts`
11. `InputConditionerCPCondCB1.ExactSameLatticeCellPerturbationsShareSemanticDigest`
12. `InputConditionerCPCondCB1.LegacyPreconditionerCannotSubstituteForCertificate`
13. `InputConditionerCPCondCB1.TolerantRawFieldFinalizationCannotReplaceExactCertificate`
14. `InputConditionerCPCondCB1.SurfaceCellsRawEntryRejectsAtConditionerBeforeA0`

Do not semantic-fail-fast inside this focused census; collect all 14 mechanical outcomes.

## 4. Explicit blocker / report-only evidence

Run `InputConditionerCPCondCB1.BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker` exactly once after the focused census. It remains **report-only / non-selector** because raw later-stage separatrix reachability has not been independently proved. Its expected disposition is explicit gtest skip. It contributes no green selector credit and must not be relabeled as PASS.

## 5. Complete accepted selector408 census

Execute every one of the 408 accepted M4-CP3 selector identities from the immutable selector file in a fresh exact-filter process. Semantic fail-fast is disabled: run the census to completion and publish the complete RED/SKIP/crash/selection-mismatch set.

Mechanical green requires:

- 408/408 PASS;
- zero SKIP, crash, timeout and selection mismatch;
- accepted RED census empty;
- selector bytes unchanged before/after runtime.

No accepted identity may be silently skipped, reclassified or replaced with a CP-COND proxy.

## 6. Negative and invariance evidence

The focused ledger must independently expose the same distinctions frozen for TB1:

- clean production identity policy produces zero C1/C2/C4 operations;
- quantization, merge, reindex and sliver-refusal behavior exists only under explicit non-default witness policy;
- no topology-changing sliver repair, face deletion/retriangulation, vector perturbation, epsilon/proximity merge or legacy-preconditioner certificate authority appears;
- operation-record tamper is discriminated rather than merely counted;
- raw and conditioned digests remain distinct authority domains while same-cell S6 witnesses share conditioned semantic identity;
- invalid raw SurfaceCells field refusal terminates at `input-conditioning/*`, before A0.

## 7. Immutable postflight

After the final runtime process:

1. Recompute package, packaged-source, selector and execution-view byte+mode censuses and require exact equality with preflight.
2. Record `configure_execution=false`, `compile_execution=false`, `relink_execution=false`, `benchmark_execution=false`, `generated_discovery=false`, `package_repair=false`, and `source_test_fixture_selector_mutation=false`.
3. Upload one immutable result artifact containing the complete process ledger, focused outcomes, report-only outcome, selector408 census, pre/postflight hashes/censuses and machine-readable summary, plus the mandatory detailed log artifact.

## 8. Mechanical EXEC disposition

`M4-CP-COND-TB2-EXEC` reports mechanical evidence only. It may not close `M4-CP-COND-TB1-EXEC-CAND-01`, promote CP-COND, modify selector authority, change stable accounting or reinterpret any blocked precondition.

The exact successor is **always `M4-CP-COND-TB2-REV`** after an authoritative execution attempt. Preserve every RED/SKIP/crash/preflight mismatch verbatim for Review; do not repair the immutable package in EXEC.
