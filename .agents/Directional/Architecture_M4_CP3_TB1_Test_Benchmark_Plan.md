# M4-CP3-TB1 Test + Benchmark Plan — package118 family-free parity A3 acceptance

**Status:** READY / FROZEN EXECUTION PLAN
**Successor state:** `M4-CP3-TB1-EXEC`
**Execution boundary:** artifact-only Test + Benchmark runtime execution
**Package artifact:** `10182447649` — `m4-cp3-cb2-package118-result-34555543569`
**Package SHA-256:** `1e7b260b5175b77e161bede7ec791a305d11550dd392a11b56757c864d9544d5`
**Exact compiled source:** `c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc`
**Candidate selector:** `Architecture_M4_CP3_Required_Green_Selector_394.txt`, 394 rows
**Accepted predecessor:** package117 / selector382 **382/382**

## 1. Turn boundary

TB-EXEC is runtime execution only. It consumes the immutable package118 artifact produced by CB2.

Allowed: download and verify the exact artifact, extract it while preserving archived modes, run only packaged binaries against packaged/source-owned inputs, collect raw logs/receipts/metrics, and preserve immutable evidence.

Forbidden: configure, compile, relink, regenerate discovery/code, patch source/package/test/fixture/selector bytes, repair executable permissions, alter expectations, run a replacement source revision, production-wire A3→A4, or promote package118. A zero-selected filter is an orchestration failure, never a pass.

TB-EXEC must stop after raw execution evidence is complete. Diagnostic adjudication, regression classification, package promotion and next corrective planning belong to `M4-CP3-TB1-REV`.

## 2. Immutable preflight

### 2.1 Artifact identity

1. Download GitHub Actions artifact ID `10182447649` exactly once.
2. Require the downloaded ZIP SHA-256 to equal:

```text
1e7b260b5175b77e161bede7ec791a305d11550dd392a11b56757c864d9544d5
```

3. Record artifact ID, name, provider digest, downloaded digest and byte size in raw evidence.

Any mismatch is an orchestration failure and execution stops.

### 2.2 Extraction and package manifest

Use ordinary `unzip`/`tar` extraction that preserves archived executable mode bits. **Do not use Python `zipfile.extractall`, `chmod`, content repair, relinking, or fixture copying into the package tree.** A missing executable bit is an orchestration failure.

From the immutable extraction root:

```bash
sha256sum -c SHA256SUMS
```

Require **28/28** manifest entries to verify and require the self-excluding manifest path set to equal the actual package file set excluding `SHA256SUMS`.

Record a pre-execution recursive census containing path, byte count, mode and SHA-256 for every package file.

### 2.3 Compile/source authority

Require:

```text
metadata/source-commit.txt = c8d8fc8ae92c067fce04a365bc8dd3b21ddad8dc
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

Require the packaged GMP evidence to prove `DIRECTIONAL_ENABLE_GMP=ON` and a generated authoritative link command containing both `gmpxx` and `gmp`.

All packaged source-status files must be empty.

### 2.4 Source archive and selector authority

Extract the packaged source archive with ordinary `tar -xzf` into a separate read-only analysis directory. Do not modify it.

Verify:

- selector394 has exactly `394` LF rows;
- selector394 LF SHA-256 is `6c27b3a0fc7259c5817bc9bbf41d5e2a23b7dd20f41fb75db8789abeb2cfba68`;
- its first 382 LF rows are byte-identical to selector382 and hash to `1d59b1f709e51854f8ceaee1a161687ff882a128dabdc79882712c97a15ca84f`;
- each selector identity has exactly one static test definition;
- static owner mapping is exactly **30 authority-kernel / 248 producer / 75 completion / 41 validation**;
- accepted prefix owner mapping is exactly **30 / 236 / 75 / 41**.

Do not invoke generated test discovery. Derive owner mapping statically from packaged source/CMake/test definitions.

## 3. Execution view

If execution requires an extracted working view, derive it only from immutable package-owned bytes and record a separate pre/post census. Do not alter package source, fixtures, binaries, modes or selectors.

The authoritative binaries are the package-owned executables:

```text
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
```

`directional_compiled_api_tests` and `directional_benchmarks` are compile evidence only for this TB unless explicitly named by a selector row. Do not run benchmarks in TB1; CB2 defines no performance acceptance metric.

Every test process must set `GTEST_FAIL_IF_NO_TEST_SELECTED=1` or the equivalent supported strict-selection environment so an unmatched filter cannot pass vacuously.

## 4. Focused new-contract gate — rows 383-394 twice

Execute each appended selector394 identity in a **fresh process**, first in phase `focused-a`, then repeat the exact same ordered vector in phase `focused-b`.

The twelve identities are:

```text
GlobalConformityBaseline.MixedMandatoryTraceCutKindsUseFamilyFreeParitySemantics
GlobalConformityBaseline.RegionParityUsesBoundaryIncidenceMultiplicity
GlobalConformityBaseline.SameRegionDoubleIncidenceIsZeroEffectSelfLoop
GlobalConformityBaseline.OneEndedTerminalUsesComponentLocalExterior
GlobalConformityBaseline.MinimumCardinalityTJoinBeatsLocalGreedyChoice
GlobalConformityBaseline.CanonicalLexPrefixChoosesLeastCountVectorAcrossEqualTJoins
GlobalConformityBaseline.ParityFlipMapsOneToTwoAndLargerToPredecessor
GlobalConformityBaseline.IndependentTinyExhaustiveOracleMatchesParityOptimumAndLexTie
GlobalConformityBaseline.IndependentValidatorRejectsParityCertificateTamperMatrix
GlobalConformityBaseline.CanonicalPermutationAndReverseOrdinalConsumptionAreInvariant
GlobalConformityBaseline.AllEvenConstructiveWitnessHasNoBaselineInfeasibilityOutcome
GlobalConformityBaseline.ProductionBaselineBinderIsStructurallySeparateFromFramedSolver
```

For every process require:

- exact owner binary selected from static mapping;
- exactly one `[ RUN      ]` receipt for the requested identity;
- exactly one `[       OK ]` receipt for the same identity;
- zero `[  FAILED  ]`, zero `[  SKIPPED ]` and exit code `0`;
- no selection mismatch and no second test executed.

Expected focused result: **12/12 twice**, with byte-identical ordered PASS/FAIL verdict vectors between `focused-a` and `focused-b`.

The test source intentionally has no success-only custom receipt emitter. Do not invent one. Determinism is established by exact requested identity, fresh-process RUN/OK receipts, exit status and repeated ordered verdict vector; semantic expected values remain enforced by the independent assertions compiled into the test source.

A bounded per-process watchdog may be used only to detect a hung individual process. A timeout is **RED/orchestration failure**, never PASS/SKIP, and does not authorize omitting the required cumulative gate.

## 5. Accepted predecessor gate — selector382

Execute all 382 accepted predecessor identities from selector394 rows 1-382, each in a fresh process under its statically mapped owner binary.

Require:

```text
382 PASS / 0 RED / 0 SKIP / 0 selection mismatch
owner totals = 30 / 236 / 75 / 41
```

This is the compatibility gate. Any accepted-prefix failure is blocking even if all twelve new rows pass. Do not weaken, drop, rewrite or remap an accepted identity to obtain green output.

## 6. Cumulative candidate gate — selector394

Execute selector394 rows 1-394 in order, each in a fresh process, without rebuilding or changing the execution view.

Require:

```text
394 PASS / 0 RED / 0 SKIP / 0 selection mismatch
accepted predecessor = 382/382
new CP3 rows = 12/12
owner totals = 30 / 248 / 75 / 41
```

The cumulative gate must run to organic process outcomes. Do not partition/retry/stitch continuations merely to evade elapsed runtime, and do not impose an overall suite timeout. An individual process timeout is a failure that must be preserved for review.

## 7. Raw evidence requirements

Preserve at minimum:

- artifact/provider/download digests and immutable preflight report;
- package and source/execution-view pre-censuses;
- selector count/hash/prefix/owner-map report;
- one raw stdout/stderr log per process;
- per-process command, requested identity, owner binary, exit status, elapsed time and timeout state;
- `focused-a` and `focused-b` ordered verdict vectors plus equality check;
- predecessor382 ledger and totals;
- cumulative394 ledger and totals;
- owner-partition totals for predecessor and candidate;
- post-execution package and source/execution-view censuses;
- explicit command-boundary statement that no configure/compile/relink/discovery/package repair occurred.

The raw result must distinguish semantic RED from orchestration failure. Do not silently retry a semantic failure.

## 8. Immutable postflight

After all required execution, recompute the package census and any derived source/execution-view census. Require exact equality with preflight for path set, modes, sizes and SHA-256 values.

Re-run `sha256sum -c SHA256SUMS` on the immutable package and require 28/28 again.

No source, test, fixture, selector, packaged binary, metadata or manifest byte may have changed.

## 9. TB-EXEC exit and stop rules

TB-EXEC is complete when all planned commands have organic terminal outcomes and raw evidence is packaged, even if one or more semantic rows are RED. TB-EXEC itself does **not** promote package118 or edit implementation/test/build logic.

- If all focused, predecessor and cumulative gates are green and postflight is immutable, report measured green and stop at `M4-CP3-TB1-REV`.
- If any semantic row is RED, preserve the first failure plus all required completed evidence and stop at `M4-CP3-TB1-REV`; do not patch or rebuild.
- If orchestration fails before semantic evidence is trustworthy, preserve the exact orchestration failure and stop for review/repair. Do not synthesize PASS.
- Any observed regression must be categorized in `Regression_Root_Cause_Tracker.md` before the overall Test + Benchmark turn is durably closed; under the configured split, TB-REV owns that diagnosis/documentation after TB-EXEC preserves raw evidence.

Package118 remains **candidate/unpromoted** until TB-REV independently re-opens the evidence and explicitly adjudicates promotion. Production A3→A4 cutover remains deferred regardless of TB-EXEC outcome.
