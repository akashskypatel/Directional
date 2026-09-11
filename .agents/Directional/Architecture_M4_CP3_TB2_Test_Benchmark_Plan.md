# M4-CP3-TB2 Test + Benchmark Plan — exact A2b path publication and production A3 binder acceptance

**Status:** FROZEN / ARTIFACT-ONLY / READY FOR `M4-CP3-TB2-EXEC`
**Turn:** `M4-CP3-TB2-EXEC`
**Execution mode:** artifact-only Test + Benchmark execution
**Evidence source:** `3f909a5a2cfd305d423faf7a260bc465c7b06892`
**Candidate:** package120 / selector403
**Accepted predecessor:** package119 / selector394 **394/394**
**Normative authority:** `Architecture_M4_DEFN_Frozen_Definitions.md` §§17 and 17.12
**Next boundary after execution:** `M4-CP3-TB2-REV`

## 1. Objective and boundary

Prove the new CB4-R1 boundary from immutable package120 bytes:

1. every A2b arc kind publishes canonical exact ordered support;
2. split Mandatory/Cut arcs publish strict exact subintervals;
3. multi-segment Trace support is ordered and contiguous;
4. reverse incidence derives the reverse support without mutating canonical arc authority;
5. independent A2b validation rejects support tamper;
6. face barycentrics use canonical topology-key order;
7. production A3 copies one A2b path into one span without family/sign invention;
8. independent A3 validation rejects redundant non-canonical exact-point encoding;
9. production publishes exactly one independently valid A3 baseline immediately after A2b;
10. the accepted selector394 prefix remains green on the changed semantic source.

TB-EXEC may execute only the commands frozen here and preserve raw evidence. It must not diagnose by editing, configure, compile, relink, regenerate discovery/code, change fixtures/selectors, repair package permissions/content, or invoke source-grid/legacy fallbacks outside what the selected tests themselves exercise.

TB-EXEC stops after raw evidence is complete. Interpretation, regression classification, promotion/disposition and next planning belong to `M4-CP3-TB2-REV`.

## 2. Immutable artifact preflight

### 2.1 Artifact identity

Download exactly once:

```text
artifact ID   = 10280703200
artifact name = m4-cp3-cb4-r1-package-r2-result-34643014511
ZIP SHA-256   = 3f0ae49f1549ff2f5c4f821ee1db5bc0314405f8f726c04cecaaf5fa3cdf80a4
source SHA    = 3f909a5a2cfd305d423faf7a260bc465c7b06892
```

Record provider digest, downloaded digest and byte size. Any mismatch is orchestration failure and stops semantic execution.

### 2.2 Extraction and manifest

Use ordinary `unzip`/`tar` extraction that preserves archived executable mode bits. **Do not use Python `zipfile.extractall`.** Do not `chmod`, repair, relink or alter package bytes.

From the immutable package root:

```bash
sha256sum -c SHA256SUMS
```

Require **28/28** entries and require the manifest path set to equal every package file except the self-excluded `SHA256SUMS`.

Record a recursive pre-execution package census: path, byte count, mode and SHA-256. The four selector-owner executables must already be executable (`0755` as packaged):

```text
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
```

Missing executable mode is orchestration failure; do not repair it.

### 2.3 Compile/source boundary

Require:

```text
metadata/source-commit.txt = 3f909a5a2cfd305d423faf7a260bc465c7b06892
metadata/preflight-target.txt = directional_surface_cell_producer_tests
metadata/preflight-exit-code.txt = 0
metadata/build-exit-code.txt = 0
```

Require `metadata/command-boundary.txt` to include:

```text
runtimeExecution=false
turnBoundary=Code+Build-only
exactArithmeticBackend=GMP
preflightCompile=true
semanticContracts=compiled-not-executed
manifestExcludesSelf=true
buildLocation=runner-temp-out-of-tree
```

Require GMP evidence to contain both `gmpxx` and `gmp` on an authoritative generated link command. Require every packaged source-status file to be empty.

### 2.4 Source/selector authority

Extract the package-owned source archive into a separate analysis directory. This is read-only authority; never patch it.

Require:

```text
selector403 rows             = 403
selector403 SHA-256          = e8f4fe72cfbbd458289779125c7ff65d7344370df6a6fc98749b4ed9007de802
selector403 first394 SHA-256 = 6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68
selector403 first382 SHA-256 = 1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f
```

Rows 1-394 must be byte-identical to packaged `Architecture_M4_CP3_Required_Green_Selector_394.txt`.

Derive test ownership statically from packaged `cmake/DirectionalTests.cmake` plus test definitions; do not run generated test discovery. Require selector403 owner totals:

```text
authority-kernel = 30
producer         = 257
completion       = 75
validation       = 41
total            = 403
```

Require accepted selector394 totals **30 / 248 / 75 / 41**. Each selector identity must resolve to exactly one default-build definition after excluding historical/non-default owners according to CMake authority.

## 3. Execution view and process discipline

Runtime binaries are the immutable package-owned four selector owners listed in §2.2. `directional_compiled_api_tests` and `directional_benchmarks` are compile evidence only; do not execute them unless a frozen selector identity unexpectedly maps to them, which itself is an authority mismatch and stop condition.

Some producer tests consume fixture paths relative to a build-style execution view. If required, create a **separate disposable execution view** derived only from immutable package-owned bytes:

1. copy/symlink package-owned executables without changing their bytes or modes;
2. materialize `test-data/benchmarks/fixtures` only from the package-owned source archive's `benchmarks/fixtures`;
3. record a complete execution-view census before the first process and after the last process;
4. require exact pre/post equality.

Do not place derived fixture files inside the immutable package tree.

Every selector row runs in a **fresh process** with strict single-test selection, for example:

```bash
GTEST_FAIL_IF_NO_TEST_SELECTED=1 <owner-binary> --gtest_filter='<Suite.Test>'
```

Per process record: ordinal, identity, owner binary, exact command, exit status, elapsed time, timeout state and raw stdout/stderr. Require exactly one requested `[ RUN      ]`, exactly one matching `[       OK ]` for PASS, no `[  SKIPPED ]`, and no second selected test. Zero-selection is orchestration failure, never PASS.

A focused diagnostic process may have a justified per-process timeout, but timeout is RED/orchestration failure and never PASS/SKIP. Do not impose an aggregate/full-gate timeout that terminates the required cumulative selector run.

## 4. Focused new-authority gate — rows 395-403, pass A

Execute exactly these nine rows in selector order, one fresh process per identity, all under `directional_surface_cell_producer_tests`:

```text
395 GlobalTopologyPlan.ExactSourcePathsAreCanonicalForEveryPublishedArcKind
396 GlobalTopologyPlan.SplitMandatoryAndCutArcsPublishExactStrictSubintervalSupport
397 GlobalTopologyPlan.MultiSegmentTracePublishesOrderedCanonicalFaceSupport
398 GlobalTopologyPlan.ReverseIncidenceReversesExactSourcePathWithoutMutatingCanonicalArc
399 GlobalTopologyPlan.IndependentValidationRejectsExactSourcePathTamperMatrix
400 ExactSourcePath.FaceBarycentricCoordinatesUseCanonicalTopologyKeyOrderNotSourceRowOrder
401 GlobalConformityBaseline.ProductionBinderCopiesExactA2bSupportOneToOneWithoutFamilyOrSign
402 GlobalConformityBaseline.IndependentValidatorRejectsNonCanonicalRedundantExactPointEncoding
403 RemeshPipeline.PublishesOneValidatedGlobalConformityBaselineImmediatelyAfterA2b
```

Expected result: **9/9 PASS**, zero skip/selection mismatch/timeout.

### 4.1 Non-vacuity obligations

Before crediting a focused PASS, TB evidence must bind each runtime identity to its exact packaged source definition. TB-REV will independently re-open these definitions, but TB-EXEC must preserve a source-location census proving exactly one default-build definition for every row.

The exact source assertions establish the following required witness semantics:

- **395:** both fixtures build and the observed A2b arcs include Mandatory, Trace and Cut; every inspected path is non-empty and canonical.
- **396:** the Mandatory witness and the trace-crossed Cut witness each contain an exact strict interior split interval.
- **397:** a Trace arc with more than one support piece exists; piece count matches source-face count and adjacent exact endpoints are equal.
- **398:** forward orientation equals stored canonical authority; reverse orientation equals exact path reversal; reversing twice restores the stored path.
- **399:** the independent rebuild rejects all five encoded tamper classes: path order, arc kind, carrier, point coordinate and overbroad split subinterval.
- **400:** deliberately permuted source-row order differs from canonical topology-key order while the resulting face point retains the supplied canonical barycentric components and is canonical.
- **401:** span count equals arc count; IDs are `from_network_arc`; every support vector exactly equals its A2b arc path; the built A3 topology digest equals A2b topology digest.
- **402:** endpoint-as-edge-point redundant encoding is rejected rather than normalized.
- **403:** the mechanical production fixture publishes both A2b and A3; A3 independently validates, schedule/span counts equal arc count, exactly one `global-conformity-baseline` debug product exists, and it immediately follows `global-topology-plan`.

A source definition that has been skipped, disabled, remapped outside the default owner, or altered relative to the package source invalidates credit even if a similarly named runtime filter passes.

## 5. Determinism gate — focused pass B

Repeat rows 395-403 exactly once, same order, one fresh process each.

Require:

- **9/9 PASS**;
- ordered verdict vector identical to pass A;
- same owner mapping and one-test selection ledger;
- zero skip/selection mismatch/timeout.

The new tests intentionally use semantic assertions rather than detached receipt lines; determinism credit is the identical selected-identity/verdict vector plus exact immutable source/package authority. Do not invent synthetic receipt output in TB.

## 6. Accepted-predecessor compatibility gate — selector394

Execute rows 1-394 of selector403 in order, one fresh process per identity under the statically mapped owner binary.

Require exactly:

```text
394 PASS / 0 RED / 0 SKIP / 0 selection mismatch / 0 timeout
owner totals = 30 / 248 / 75 / 41
```

This is a compatibility rerun on the new semantic source; package119's historical acceptance does not substitute for it. Any accepted-prefix failure is blocking and must be preserved as runtime evidence without patching.

## 7. Cumulative candidate gate — selector403

Execute all 403 selector rows in order, one fresh process per identity under the same static owner map.

Require exactly:

```text
403 PASS / 0 RED / 0 SKIP / 0 selection mismatch / 0 timeout
accepted prefix = 394/394
new R1 rows      = 9/9
owner totals     = 30 / 257 / 75 / 41
```

Do not partition/retry/stitch continuation results merely to evade elapsed runtime. If the complete cumulative gate cannot reach an organic process result because of external infrastructure failure, record orchestration failure rather than semantic PASS.

Expected semantic runtime process count for the frozen matrix is **815**:

```text
focused A   9
focused B   9
prefix394 394
candidate  403
-----------
total      815
```

## 8. Raw evidence requirements

Preserve at minimum:

- artifact/provider/download digest and immutable preflight report;
- package/source/execution-view pre-censuses;
- selector count/hash/prefix/owner-map report;
- exact source-definition census for rows 395-403;
- one raw stdout/stderr log per process;
- per-process ordinal, identity, owner, exact command, exit status, elapsed time and timeout state;
- focused-A and focused-B ordered verdict vectors and equality result;
- selector394 per-row ledger and totals;
- selector403 per-row ledger and totals;
- owner-partition totals for both cumulative gates;
- post-execution package/source/execution-view censuses;
- explicit command-boundary statement proving no configure/compile/relink/generated discovery/package repair occurred.

Raw evidence must distinguish semantic RED from orchestration failure. Do not silently retry semantic failures.

## 9. Immutable postflight

After all required execution:

1. recompute package and derived execution-view censuses;
2. require exact pre/post equality for path set, modes, sizes and SHA-256 values;
3. rerun `sha256sum -c SHA256SUMS` on the immutable package and require **28/28** again;
4. confirm no packaged source, test, fixture, selector, binary, library, metadata or manifest byte changed.

## 10. Benchmark plan

**Applicable:** no.

CB4-R1 adds exact authority publication/binding and test coverage but freezes no performance/resource acceptance metric. Do not execute `directional_benchmarks` merely because it is packaged compile evidence.

## 11. Stop conditions and reruns

Stop and preserve evidence if:

- artifact/source/package digest or manifest differs from §2;
- GMP/source-status/command-boundary preflight fails;
- required binary or archived executable mode is absent;
- selector403/prefix hashes or owner counts differ;
- any filter selects zero or multiple tests;
- any focused or cumulative row is RED/SKIP/timeout;
- package/source/execution-view bytes change;
- continuing would require configure, compile, relink, source/test/fixture/selector mutation, `chmod` or package repair.

The only planned repetition is focused pass B. No ad hoc semantic retry is permitted. An orchestration retry is allowed only when the failed attempt produced no trustworthy semantic result and complete package/execution-view immutability can be proven; preserve the failed attempt separately.

## 12. Completion and next boundary

TB2-EXEC is complete when every frozen execution has an organic result or explicit blocker and all raw evidence is preserved so review can adjudicate without reconstructing intent from chat context.

- If every gate is green and postflight is immutable, report measured green and stop at `M4-CP3-TB2-REV`.
- If any semantic row is RED, preserve the complete ledger and stop at `M4-CP3-TB2-REV` without diagnosis-by-edit.
- If orchestration invalidates evidence, preserve the blocker and stop at `M4-CP3-TB2-REV` for disposition/repair planning.

Package120 remains **candidate / unpromoted** until `M4-CP3-TB2-REV` independently reopens the artifact evidence and explicitly accepts or rejects it. Even a green TB2-EXEC does not authorize A4 mutation; only the review boundary may authorize `M4-CP3-CB5`.
