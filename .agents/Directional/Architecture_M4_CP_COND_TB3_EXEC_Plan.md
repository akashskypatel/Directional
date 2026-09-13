# M4-CP-COND-TB3-EXEC Artifact-Only Test Plan

**Turn:** `M4-CP-COND-TB3-EXEC`
**Type:** Test + Benchmark EXEC / artifact-only / runtime execution
**Immutable CB3 package:** artifact `10325879420`
**Provider digest:** `sha256:d046b8cbdcfe22af5ca732139612e96673d597fef47b5e36d1a54b1542493b2b`
**Exact source:** `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`
**Selector408:** 408 LF / `c689c0cd8a51f9a8bd8c9ed3a2e8b603728d5a0359ee2732f776a422744b0484`
**First403:** `c3f509afc823cd73761bdebea0d072d497acf5587a013cb52b795f273af70cb7`
**Mandatory successor:** `M4-CP-COND-TB3-REV`

## 1. Purpose and authority boundary

Execute exactly the frozen CP-COND acceptance surface against the immutable CB3 package that contains the corrected raw-derived negative-index test oracle. EXEC reports mechanical outcomes only. It may not close `M4-CP-COND-TB2-REV-CAND-01`, promote the package, reprice stable accounting, or close CP-COND; those decisions belong only to `M4-CP-COND-TB3-REV`.

## 2. Hard artifact-only prohibitions

TB3-EXEC must not:

- configure, compile, relink, or rebuild;
- repair package bytes, executable modes, source, fixtures, selectors, filters, or manifests;
- generate or refresh test discovery;
- mutate repository product/test/fixture/CMake/selector source;
- substitute a locally built binary;
- skip a required row after semantic RED;
- treat a zero-selected exact filter as PASS; or
- impose a repository timeout intended to terminate the complete acceptance run.

Extract the archived package with a mode-preserving ordinary `unzip`/`tar` path. Python `zipfile.extractall` is forbidden for executable payloads. A missing executable bit is an orchestration RED; do not `chmod` or repair it.

## 3. Immutable preflight

Before the first Directional process:

1. verify artifact ID and provider digest exactly;
2. verify the package root `SHA256SUMS` **27/27**, and its file hash `d292ee76bd1234b073084ebdfc772e248dd6757ee477b484dded158463194c2d`;
3. verify `metadata/source-commit.txt` is exactly `4d9206cd059d7bb0c10fe3c0a0c91f8af248e675`;
4. verify packaged source archive hash `c5e8ea58d2564a6cf0f70691f14ee2329f3d92b855f0bd58c9e22811494c9c5c`;
5. verify `metadata/command-boundary.txt` contains `runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`, and `semanticContracts=compiled-not-executed`;
6. verify GMP/GMPXX evidence and the complete seven-target compile record;
7. verify all four selector-owner executables plus compiled API and required core/pipeline libraries exist with archived modes intact;
8. verify selector408 and first403 hashes/row counts exactly;
9. materialize the packaged source archive only as the immutable execution-view/fixture authority required by the packaged tests; do not repair or substitute repository HEAD bytes;
10. record byte+mode censuses for package payload, extracted source/execution view, selectors, and every package-owned input that postflight will compare.

Any mismatch stops before runtime with zero semantic test credit.

## 4. Focused CP-COND surface — 14 fresh exact-filter processes

Run each identity exactly once in a fresh process against its packaged owner executable, require exactly one selected test, and record raw stdout/stderr + exit status:

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

Focused mechanical GREEN requires **14/14 PASS**, zero selection mismatch, crash, or infrastructure repair.

## 5. Report-only boundary witness — one fresh process

Run exactly once:

`InputConditionerCPCondCB1.BoundaryTruncatedSeparatrixReachabilityRemainsNamedBlocker`

Expected result remains **SKIP** with its named reachability blocker. This identity is report-only / non-selector and contributes no accepted-selector PASS. A PASS, RED, crash, zero-selection, or changed blocker text must be recorded for Review; EXEC may not silently reclassify it.

## 6. Accepted selector408 — 408 fresh exact-filter processes

Execute all 408 accepted selector rows exactly once, in selector order, each as its own exact-filter process routed to the package's declared owner executable. Do not semantic-fail-fast: complete the entire 408-row census after any ordinary semantic RED so Review receives the full vector. Stop only for infrastructure conditions that make subsequent results invalid (package mutation, selection mismatch, missing owner, crash regime that prevents trustworthy continuation, or postflight authority loss).

Expected accepted owner census remains **30 authority-kernel / 262 producer / 75 completion / 41 validation = 408**.

## 7. Process/accounting contract

Expected complete execution is **423 processes**:

- 14 focused;
- 1 report-only boundary;
- 408 selector rows.

Mechanical GREEN is:

- focused **14/14 PASS**;
- boundary **1 expected report-only SKIP**;
- selector408 **408/408 PASS**;
- total gating PASS **422/422**;
- zero RED, crash, timeout, or selection mismatch;
- exact immutable postflight.

The focused negative-index PASS is necessary but not self-adjudicating; Review must inspect whether the corrected raw-derived oracle and mutation discriminator truly discharge the TB2 test-authority candidate.

## 8. Immutable postflight

After the last prescribed process, recompute the preflight byte+mode censuses and require exact equality. Explicitly prove:

- package bytes/modes unchanged;
- packaged source/execution-view bytes/modes unchanged;
- selector408/first403 unchanged;
- no configure/compile/relink/rebuild occurred;
- no package/mode repair occurred;
- no generated discovery occurred;
- no benchmark occurred;
- no source/test/fixture/selector mutation occurred.

Publish a process ledger containing every attempted identity, owner executable, selected-count evidence, exit status, verdict, and raw-log reference. Publish focused/report-only/selector ledger digests plus pre/postflight digests and all orchestration flags.

## 9. EXEC disposition rules

- If all mechanical gates are GREEN, report **COMPLETE / MECHANICALLY GREEN / SEMANTICALLY UNADJUDICATED** and stop at mandatory `M4-CP-COND-TB3-REV`.
- If any semantic identity is RED, complete the trustworthy prescribed census, report the exact RED set without root-cause assignment, and stop at Review.
- If preflight/postflight/selection/package integrity fails, report orchestration/package failure with zero or bounded semantic credit as appropriate and stop at Review.
- Do not modify code or create a corrective plan inside EXEC.

Stable accounting entering TB3 remains **49 events / 14 categories / 35 recurrences**, produced-witness debt **5**. Accepted semantic runtime authority entering TB3 remains CP3 package `10307919492` / selector408 **408/408** until Review explicitly promotes a successor.
