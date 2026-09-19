# M4-CP4-TB2-EXEC — artifact-only M4-owned focused re-proof + selector427

**Turn type:** Test + Benchmark / immutable artifact-only execution
**Authorized by:** `M4-CP4-CB5`
**Runtime boundary:** generated test binaries may execute; configure/compile/relink/discovery/repair/mutation/benchmark execution is forbidden

## 1. Purpose

Re-prove the four M4-owned CP4 focused identities after CB5's two bounded test-authority corrections while preserving exact cumulative selector427 authority. The two periodic focused identities re-homed to M5 by DEFN-R1 are deliberately excluded from this M4 gate and remain byte-unchanged.

A trustworthy semantic result routes to mandatory runtime-free `M4-CP4-TB2-REV`.

## 2. Immutable input authorities

### 2.1 Full CB4 package — unchanged owner binaries

Artifact `10578784752`, exact source `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a`, provider ZIP SHA-256 `d26610d6e14c72a0dad63e60bb0c3ecc94c0e48dfd72f8261cb110bd3c4c3b9a`, packaged-source archive SHA-256 `dd7dd3351ad3ea10f56ef9ce2021fc8ea84e10d682560b93f70ca1d79b089175`, package manifest **28/28**.

Use this package only for owner executables whose compiled semantic inputs are unchanged since CB4:

- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_validation_tests`.

### 2.2 CB5 delta package — corrected owner binaries

Artifact `10582435470`, exact compiled source `4e9ff5003c8dd165dd614c25dd95f0308403719b`, provider ZIP SHA-256 `3e889c4682b35f6de2d30b38b9bf016f0dea526a10e46a0b9f1b404610443ad3`, packaged-source archive SHA-256 `b904ba5fec938d74d432501396f94de0c015072de6d9009c6213e6d547c19c81`, manifest **24/24** with manifest SHA-256 `f5239fa4cb8fb31551599d6f836ca16e44ab203056dc262eb5c26141ed62d270`.

Use this package only for the two CB5-recompiled owner executables:

- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`.

The delta package records `runtimeExecution=false`, exact GMP/GMPXX linkage, and clean source receipts.

### 2.3 Why the composite view is authoritative

Repository comparison `c2224f6af6a4fab47b928c1a0cd2fad677b87b9a -> 4e9ff5003c8dd165dd614c25dd95f0308403719b` changes compiled C++ test semantics only in:

- `tests/FieldTransportAtlasTests.cpp` — authority-kernel owner;
- `tests/SurfaceComplexSimplificationPhase17Tests.cpp` — completion owner.

All other changes are documentation/control state. There are no changes to `src/**`, `include/**`, CMake/build semantics, committed fixtures, producer-target test source, or validation-target test source. Therefore the producer/validation bytes from the full CB4 package and authority/completion bytes from the CB5 delta package form the exact owner-wise runtime surface required by this gate.

Neither input package may be modified. Build a runner-temporary execution view by hard-linking/copying the four verified executable bytes from the designated immutable package owners while preserving archived executable modes. Fixture materialization, when required by the test binaries, must use immutable packaged source bytes and the existing executable-relative fixture contract; it may not alter either package.

## 3. Mandatory preflight

Before the first generated Directional process:

1. download each required artifact once and verify its provider SHA-256;
2. extract without permission/content repair; Python `zipfile.extractall` is prohibited for executable payloads unless archived modes are explicitly restored and verified;
3. verify each package's complete self-excluding `SHA256SUMS` manifest and exact source commit;
4. verify all packaged source-status receipts are empty and compile boundary says `runtimeExecution=false` / GMP;
5. verify exact designated executable bytes/modes and record a package-origin map for every owner;
6. verify selector427 is exactly `.agents/Directional/Architecture_M4_CP_SCALE_CB24_Required_Green_Selector_427.txt`, **427 LF rows**, 34,783 bytes, SHA-256 `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`, with exact owner census **30 authority-kernel / 281 producer / 75 completion / 41 validation**;
7. freeze byte+mode censuses for both package trees, both packaged-source trees, and the composite execution view;
8. fail orchestration before runtime on any artifact/hash/mode/source/owner/selector mismatch or missing executable.

A zero-selected exact filter is orchestration failure, never PASS or SKIP.

## 4. Focused execution surface — exactly four fresh processes

Execute in this order, each in a fresh process with exact filter, fail-on-zero-selection, and selected-count `1`:

1. `M4CP4.ProductionBaselineWorkReceiptIsBoundedAndIndependentlyValidated` — producer binary from full CB4 package;
2. `M4CP4.ProducedClosedComplexCandidateExtractionHasIndependentEligibilityOracle` — completion binary from CB5 delta package;
3. `M4CP4.ProducedSameRegionMultiplicityTwoSurvivesA2bToBaselineBinder` — producer binary from full CB4 package;
4. `M4CP4.ZeroTransportFieldPreconditionDistinguishesFlatSuccessFromNonFlatRejection` — authority-kernel binary from CB5 delta package.

Required focused result is **4/4 PASS**. In particular:

- row2 receives credit only if the fail-closed/recovery-disabled produced torus reaches retained incidence-valid arrangement authority and the independent candidate oracle plus its authoritative-support/protection tamper pass;
- row6 receives credit only if flat zero transport succeeds, nonzero apex defect is independently established, the non-flat witness rejects, and the exact typed expectation `NonIntegralCycleLift` passes.

Do **not** execute or count for M4:

- `M4CP4.ProducedTorusPeriodicRelationOwnersSurviveContainerReordering`;
- `M4CP4.ProducedTorusMissingPeriodicRelationOwnerIsRejected`.

Their two underlying `G4-B002` debts remain M5-owned with original discriminators intact.

## 5. Cumulative selector427 re-proof — 427 fresh processes

After focused execution, execute the exact 427-row selector in file order, one fresh process per identity. Route every identity by the frozen owner map to the composite execution view:

- authority-kernel rows -> CB5 delta authority-kernel binary;
- completion rows -> CB5 delta completion binary;
- producer rows -> full CB4 producer binary;
- validation rows -> full CB4 validation binary.

Require exactly one selected test and zero skips for every row. Required cumulative result is **427/427 PASS**. Benchmark execution count must be `0`.

Focused semantic RED does not authorize omission of later focused rows or selector427: execute the complete **431-process** gate and preserve the first semantic RED as the stop-reason summary while still collecting the complete ledger, unless an orchestration failure makes continued execution invalid.

## 6. Mandatory immutable postflight

After generated runtime, re-run exact byte+mode censuses and require equality for:

- full CB4 package tree;
- full CB4 packaged-source tree;
- CB5 delta package tree;
- CB5 delta packaged-source tree;
- composite execution view;
- selector427.

Re-verify both package manifests. Record complete per-process raw logs, selected/skipped counts, exit classification, owner/package routing, complete 431-row ledger, evidence boundary, and self-excluding result manifest.

No configure, compile, relink, generated discovery/list/help/version, chmod/permission repair, source/test/fixture/selector mutation, package mutation, or benchmark command is permitted.

## 7. Regression documentation gate and successor

Every semantic non-green result must be classified in `Regression_Root_Cause_Tracker.md` before TB closeout. Do not alter stable counts unless evidence justifies a stable regression; otherwise record a non-stable candidate and why totals remain unchanged.

For any orchestration-valid semantic result, exact successor is runtime-free **`M4-CP4-TB2-REV`**. Review must independently re-open both input packages and TB2 evidence, re-derive composite owner authority, selector/prefix/owner census, focused non-vacuity/tampers, complete ledger, and postflight before deciding:

- closure of `M4-CP4-TB1-R3-CAND-01` and/or `CAND-03`;
- discharge of the remaining M4-owned `G4-B002` produced closed-complex debt;
- M4-CP4 closure/publication sequencing;
- any package/runtime promotion question.

TB2 itself grants no promotion, no debt credit, and no M5 periodic credit.
