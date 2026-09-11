# M4-CP3-TB1-R1 Test + Benchmark Plan — package119 test-authority recovery acceptance

**Status:** READY / FROZEN EXECUTION PLAN
**Successor state:** `M4-CP3-TB1-R1-EXEC`
**Execution boundary:** artifact-only Test + Benchmark runtime execution
**Post-build candidate designation:** package119 / selector394, unpromoted
**Package artifact:** `10185370005` — `m4-cp3-cb3-package-result-34564069513`
**Package ZIP SHA-256:** `9fdfe9a1c8f92d52669a82da0ddfca75d58fd8dc7317d5100faff5a85c820fc8`
**Exact compiled source:** `fd532c2f768d0ff6493260deb670cb34b6757712`
**Candidate selector:** `Architecture_M4_CP3_Required_Green_Selector_394.txt`, 394 rows
**Accepted predecessor:** package117 / selector382 **382/382**

## 1. Validation objective and turn boundary

TB-EXEC is runtime execution only. It must determine whether the CB3 test-authority corrections make the seven previously blocked identities non-vacuously green while preserving the accepted selector382 prefix and the full selector394 candidate surface.

Allowed: download and verify the exact immutable artifact, extract package-owned bytes while preserving archived modes, execute only packaged test binaries against package/source-owned inputs, collect raw logs/receipts/timings, and preserve immutable evidence.

Forbidden: configure, compile, relink, regenerate discovery/code, patch source/package/test/fixture/selector bytes, repair executable permissions, alter expectations, run a replacement source revision, modify production A3/A4 code, or promote package119. A zero-selected filter is an orchestration failure, never a pass.

TB-EXEC stops after complete raw execution evidence. Diagnostic adjudication, regression classification, promotion/disposition and next planning belong to `M4-CP3-TB1-R1-REV`.

## 2. Preconditions and immutable artifact integrity

### 2.1 Artifact identity

1. Download GitHub Actions artifact ID `10185370005` exactly once.
2. Require downloaded ZIP SHA-256 exactly:

```text
9fdfe9a1c8f92d52669a82da0ddfca75d58fd8dc7317d5100faff5a85c820fc8
```

3. Record artifact ID, artifact name, provider digest, downloaded digest and byte size.

Any mismatch stops execution as orchestration failure.

### 2.2 Extraction and package manifest

Use ordinary `unzip`/`tar` extraction that preserves archived executable mode bits. Do not use Python `zipfile.extractall`, `chmod`, content repair, relinking, or fixture copying into the package tree. Missing executable mode is an orchestration failure.

From the immutable extraction root run:

```bash
sha256sum -c SHA256SUMS
```

Require **28/28** entries and require the self-excluding manifest path set to equal the actual package file set excluding `SHA256SUMS`.

Record a recursive pre-execution package census: path, byte count, mode and SHA-256 for every package file.

### 2.3 Compile/source authority

Require:

```text
metadata/source-commit.txt = fd532c2f768d0ff6493260deb670cb34b6757712
metadata/preflight-exit-code.txt = 0
metadata/build-exit-code.txt = 0
```

Require `metadata/command-boundary.txt` to contain at least:

```text
runtimeExecution=false
turnBoundary=Code+Build-only
exactArithmeticBackend=GMP
preflightCompile=true
semanticContracts=compiled-not-executed
manifestExcludesSelf=true
buildLocation=runner-temp-out-of-tree
```

Require packaged GMP evidence to show `DIRECTIONAL_ENABLE_GMP=ON` and an authoritative link command containing both `gmpxx` and `gmp`. All packaged source-status files must be empty.

### 2.4 Source archive and selector authority

Extract the package-owned source archive into a separate read-only analysis directory. Verify:

- selector394 has exactly **394 LF rows**;
- selector394 SHA-256 is `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- rows 1-382 hash to `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f` and are byte-identical to accepted selector382;
- each selector identity has exactly one static definition;
- static owner mapping remains exactly **30 authority-kernel / 248 producer / 75 completion / 41 validation**;
- accepted-prefix owner mapping remains exactly **30 / 236 / 75 / 41**.

Derive owner mapping statically from packaged source/CMake/test definitions. Do not invoke generated test discovery.

## 3. Execution view and process discipline

Authoritative runtime binaries are package-owned:

```text
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
```

`directional_compiled_api_tests` and `directional_benchmarks` are compile evidence only unless a selector row names them. No benchmark is planned for R1.

If an execution view is required, derive it only from immutable package-owned bytes and census it before and after. Do not alter package source, fixtures, binaries, modes or selectors.

Every test invocation must use a fresh process and `GTEST_FAIL_IF_NO_TEST_SELECTED=1` or equivalent strict-selection behavior. Per process require exactly one requested `[ RUN      ]`, exactly one matching `[       OK ]` for PASS, zero second-test execution, and record exit status, elapsed time and timeout state. A timeout is RED/orchestration failure, never PASS/SKIP.

## 4. Focused recovery gate — rows 383-394, pass A

Execute rows 383-394 in selector order, one fresh process per identity:

```text
383 GlobalConformityBaseline.MixedMandatoryTraceCutKindsUseFamilyFreeParitySemantics
384 GlobalConformityBaseline.RegionParityUsesBoundaryIncidenceMultiplicity
385 GlobalConformityBaseline.SameRegionDoubleIncidenceIsZeroEffectSelfLoop
386 GlobalConformityBaseline.OneEndedTerminalUsesComponentLocalExterior
387 GlobalConformityBaseline.MinimumCardinalityTJoinBeatsLocalGreedyChoice
388 GlobalConformityBaseline.CanonicalLexPrefixChoosesLeastCountVectorAcrossEqualTJoins
389 GlobalConformityBaseline.ParityFlipMapsOneToTwoAndLargerToPredecessor
390 GlobalConformityBaseline.IndependentTinyExhaustiveOracleMatchesParityOptimumAndLexTie
391 GlobalConformityBaseline.IndependentValidatorRejectsParityCertificateTamperMatrix
392 GlobalConformityBaseline.CanonicalPermutationAndReverseOrdinalConsumptionAreInvariant
393 GlobalConformityBaseline.AllEvenConstructiveWitnessHasNoBaselineInfeasibilityOutcome
394 GlobalConformityBaseline.ProductionBaselineBinderIsStructurallySeparateFromFramedSolver
```

Expected result: **12/12 PASS**, zero skip/selection mismatch/timeout.

### 4.1 Mandatory success-visible receipts

For ordinals **386, 388, 389, 390, 391, 392, 394**, each focused process must contain **exactly one** line beginning:

```text
M4_CP3_BASELINE_RECEIPT ordinal=<N>
```

Missing or duplicate receipt is blocking even when GTest reports PASS.

Parse and enforce the following live invariants:

- **386:** component count `1`, `hasExterior=true`, `exteriorDemandOdd=true`, terminal-span count `3`.
- **388:** exact count vector, minimum flip count and lex-receipt count are present; the process assertions remain authoritative for expected values.
- **389:** receipt proves both map cases: preferred/final `1 -> 2` and independently fixture-derived `2 -> 1`.
- **390:** `spanCount > 0`; `assignmentsExamined > 0`; `parityFeasibleAssignments > 0`; `assignmentsExamined == 2^spanCount`; emitted region-span multiplicity matrix is nonempty and the process is PASS.
- **391:** `tamperRows == 9`.
- **392:** `preferredCount == 4`; final `entryCount > 1`; forward exact ordinal `1`; reverse exact ordinal `entryCount - 1`; both live local denominators equal `entryCount`.
- **394:** topology boundary-incidence count equals produced baseline incidence count; both compile-time structural-separation assertions remain compiled into the identity.

Record the exact receipt bytes per corrected ordinal.

## 5. Determinism gate — focused pass B

Repeat the exact same rows 383-394, same order, one fresh process per identity.

Require:

- **12/12 PASS**;
- ordered PASS/FAIL verdict vector byte-identical to pass A;
- for corrected ordinals 386/388/389/390/391/392/394, the exact parsed receipt line bytes are byte-identical to pass A;
- zero timeout, skip or selection mismatch.

Any receipt-value drift is deterministic-evidence failure even if both GTest verdicts are PASS.

## 6. Accepted predecessor compatibility gate — selector382

Execute selector394 rows 1-382 in order, each in a fresh process under its statically mapped owner binary.

Require exactly:

```text
382 PASS / 0 RED / 0 SKIP / 0 selection mismatch / 0 timeout
owner totals = 30 / 236 / 75 / 41
```

Any accepted-prefix failure is blocking. Do not weaken, drop, rewrite, remap or retry a semantic failure into PASS.

## 7. Cumulative candidate gate — selector394

Execute selector394 rows 1-394 in order, each in a fresh process without rebuilding or changing the execution view.

Require exactly:

```text
394 PASS / 0 RED / 0 SKIP / 0 selection mismatch / 0 timeout
accepted predecessor = 382/382
new CP3 rows = 12/12
owner totals = 30 / 248 / 75 / 41
```

For cumulative executions of corrected ordinals, preserve any emitted receipt as raw evidence. Focused A/B receipt checks remain the normative non-vacuity/determinism gate.

Do not impose an overall suite timeout or partition/retry/stitch continuations to evade elapsed runtime. An individual process timeout is a preserved failure.

Expected total semantic runtime processes across focused A, focused B, predecessor and cumulative gates: **800**.

## 8. Raw evidence requirements

Preserve at minimum:

- artifact/provider/download digests and immutable preflight report;
- package/source/execution-view pre-censuses;
- selector count/hash/prefix/owner-map report;
- one raw stdout/stderr log per process;
- per-process command, requested identity, owner binary, exit status, elapsed time and timeout state;
- focused-A and focused-B ordered verdict vectors and exact equality result;
- parsed receipt ledger for 386/388/389/390/391/392/394 in both focused phases plus byte-equality result;
- predecessor382 per-row ledger and totals;
- cumulative394 per-row ledger and totals;
- owner-partition totals for predecessor and candidate;
- post-execution package/source/execution-view censuses;
- explicit command-boundary statement proving no configure/compile/relink/generated discovery/package repair occurred.

Raw evidence must distinguish semantic RED from orchestration failure. Do not silently retry a semantic failure.

## 9. Immutable postflight

After all required execution:

1. recompute package and derived source/execution-view censuses;
2. require exact pre/post equality for path set, modes, sizes and SHA-256 values;
3. re-run `sha256sum -c SHA256SUMS` on the immutable package and require **28/28** again;
4. confirm no source, test, fixture, selector, packaged binary, metadata or manifest byte changed.

## 10. Benchmark plan

**Applicable:** no.

CB3 changed test authority only and defines no performance/resource acceptance metric. Do not execute `directional_benchmarks` merely because it is packaged compile evidence.

## 11. Unit-test design check

- **Contract under test:** frozen §17 exact shared subdivision + region parity and independent validation surface.
- **Scenario/boundary:** DCEL-valid triangular-boundary disk with exactly three terminals; same-region double incidence; exterior terminal parity; equal-optimum lex refinement; `d=1` and `d>1` flip mapping; independent exhaustive parity oracle; certificate tamper rejection; permutation/reverse-breakpoint invariance; production/framed binder structural separation.
- **Why fixture values expose plausible broken behavior:** the prior one-face helper violated production topology before intended predicates; target size `0.25` independently forces ordinal392 into a true interior-breakpoint case; multiplicity-aware oracle catches interior self-loop spans rather than assuming them away.
- **Isolation rationale:** no mocks/test doubles are needed; tests use production topology/baseline APIs but independent fixture/oracle authority.
- **Assertion semantics:** PASS alone is insufficient for previously blocked rows; live success-visible receipts must prove intended assertions/calls were reached.

## 12. Stop and blocker conditions

Stop and preserve evidence when:

- artifact/source identity or package digest differs from this plan;
- `SHA256SUMS`, source status, GMP evidence or selector authority fails preflight;
- a required executable/mode/dependency is unavailable;
- a selector filter selects zero or more than one test;
- any focused receipt is missing, duplicated, unparsable or violates its parsed invariant;
- focused A/B verdict vectors differ;
- corrected focused A/B receipt bytes differ;
- a process times out;
- continuing would require source/package mutation, rebuild, relink or permission repair.

A semantic RED is not authorization to patch. Continue only as required to complete the frozen evidence matrix when doing so does not invalidate later evidence; then stop at TB-REV with the complete ledger.

## 13. Plan-defined reruns

Allowed runtime repetitions are only the explicitly planned focused A and focused B executions. No ad hoc semantic retries are permitted. An orchestration retry is allowed only if the failed attempt produced no trustworthy semantic execution and the immutable package/execution view can be proven unchanged; preserve the failed orchestration attempt separately.

No random seed or order permutations are authorized. The frozen selector order is the required order.

## 14. Completion criteria and next boundary

TB-EXEC is complete when all plan items have a recorded organic result or explicit blocker, raw evidence is immutable/preserved, and a later reviewer can evaluate every criterion without reconstructing intent from chat context.

- If all focused, receipt, predecessor and cumulative gates are green and postflight is immutable, report measured green and stop at `M4-CP3-TB1-R1-REV`.
- If any semantic row is RED, preserve the complete evidence and stop at `M4-CP3-TB1-R1-REV`; do not diagnose by editing.
- If orchestration invalidates semantic evidence, preserve the blocker and stop for review/repair.

Package119 remains **candidate/unpromoted** until TB-REV independently reopens the evidence and explicitly adjudicates disposition. Production A3→A4 cutover remains deferred regardless of TB-EXEC outcome.
