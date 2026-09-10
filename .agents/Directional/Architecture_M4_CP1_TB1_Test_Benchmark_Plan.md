# M4-CP1-TB1 Test + Benchmark Plan

**Status:** ISSUED / ARTIFACT-ONLY / NO REBUILD / EXECUTION IS A SEPARATE TURN
**Execution turn:** `M4-CP1-TB1-EXEC`
**Semantic source:** `680f9f1573d3c7e56a273366436463e40e196131`
**Immutable package:** package114, artifact `10142108806`

## 1. Purpose and hard boundary

Execute only the already-built CP1 authority carried by immutable package114. This turn is a runtime evidence turn,
not a build turn. It may execute the packaged test binary and selector-derived filters, collect deterministic
evidence, and classify every observed regression. It must not rebuild, relink, regenerate fixtures, mutate selector
bytes, modify package contents, or substitute a different source revision.

No CP2 or CP3 acceptance may be inferred from CP1 results.

## 2. Immutable preflight

Before any Directional binary executes, require all of the following:

1. artifact ID exactly `10142108806`;
2. provider artifact SHA-256 exactly
   `9a87181f771a1814fa854bc2056050b05880b6ec8dfe4ef9c9346102ee26fa36`;
3. packaged `metadata/source-commit.txt` exactly
   `680f9f1573d3c7e56a273366436463e40e196131`;
4. packaged `metadata/command-boundary.txt` contains
   `runtimeExecution=false`, `turnBoundary=Code+Build-only`,
   `exactArithmeticBackend=GMP`, and `semanticContracts=compiled-not-executed`;
5. packaged `metadata/gmp-evidence.txt` proves both GMP and GMPXX were found/linked;
6. `bin/directional_surface_cell_producer_tests` SHA-256 exactly
   `5b1064e6025b052aed7aeee66b8e1c3f6218bc73791d55fed4675484f4ea2afd`;
7. `lib/libdirectional_core.a` SHA-256 exactly
   `0325a5d45181014ff45783596c8d952a14f86d383b46d9f6ba43ccfc92315c4b`;
8. every entry in package `SHA256SUMS` verifies before execution;
9. `Architecture_M4_CP1_Required_Green_Selector_373.txt` has 373 LF rows, full hash
   `6d00cafa939a0e89c4816a6b0e8fec83232c0e7a94a468ae547b1667171e7d8b`, and first-365 prefix hash
   `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`.

Any mismatch is an **orchestration/evidence stop**. Do not run a nearly matching binary or repair the package.

## 3. Focused CP1 execution

Execute the following eight identities from the packaged binary, with zero-selected-filter treated as failure:

1. `GlobalConformityPlan.MultiPieceCompactOrdinalsAndReverseIncidenceSymmetry`
2. `GlobalConformityExactSolver.PreservesSameRowBidirectedMultiplicityPositivityAndParity`
3. `GlobalConformityPlan.ExactBinary64IngressCanonicalizesSignedZeroAndSubnormal`
4. `GlobalConformityExactSolver.HugeExactCapRadixAndLexObjectiveNeverNarrow`
5. `GlobalConformityExactSolver.FixedM2RefinementMatchesSeparateTinyExhaustiveOracle`
6. `GlobalConformityExactSolver.GenuinelyBidirectedLoopPermutationAndReversalAreDeterministic`
7. `GlobalConformityPlan.IndependentValidatorRejectsTamperMatrix`
8. `GlobalConformityExactSolver.ExactValuesExceedLibSatsumaAndBlossomScalarWidths`

Require **8 selected / 8 executed**. No identity receives credit merely because a broad filter returned zero tests.

The focused evidence must establish, from the compiled assertions:

- compact multi-piece breakpoint generation and reverse-ordinal symmetry;
- genuine same-row bidirected multiplicity, positivity and parity;
- exact binary64 ingress including signed zero and subnormal handling;
- `U/Q/L` and exact matching values beyond machine-width ranges;
- fixed-`M=2` exact refinement agreeing with the separately authored tiny exhaustive oracle;
- exact strict decrease on committed refinement steps and exact terminal non-improvement;
- deterministic genuinely bidirected loop behavior under permutation/reversal;
- independent validator rejection of count, binding, objective, cap, radix, ledger, incidence and parity tampering;
- exact-weight arithmetic beyond libSatsuma/Blossom bounded scalar widths.

## 4. Repeat/determinism receipt

Run the eight-identity focused filter a second time from the same immutable binary without modifying the extracted
artifact. Require the same selected count and verdict vector. The dedicated permutation/reversal identity must
remain green in both runs.

A repeat discrepancy is a semantic/determinism regression and routes to independent review; it is not retried until
green by repeated execution.

## 5. Cumulative selector373 execution

Execute the exact 373-row selector as the gtest filter against the same packaged binary.

Acceptance conditions for this execution:

- selected count exactly **373**;
- accepted predecessor rows **1–365 are all PASS**;
- CP1 rows **366–373 are all PASS**;
- no zero-selected identity and no skipped required-green identity;
- no test-name substitution, selector edit, fixture edit, rebuild, or relink.

The cumulative result is reported as `PASS / RED / SKIP` over all 373 rows. The first-365 result is reported
separately so M3 accepted authority cannot be hidden by an aggregate.

## 6. WorkLedger/runtime assertions

Where produced by the focused identities, retain the exact CP1 ledger evidence. Required semantic fields include:

- `algorithmIdentity=HeistermannWarnettBommes2023ExactBiMDFRefinementM2`;
- `matchingPrimitiveIdentity=LEMON-1.3.1-MaxWeightedPerfectMatching-exact-EInt-adapter`;
- `refinementM=2`;
- exact-capacity/target/objective bit widths, including the >64-bit witness;
- refinement count consistent with the emitted refinement evidence;
- every committed refinement has exact strictly smaller scalar objective;
- terminal exact non-improvement is validated;
- no tolerance terminal and no machine-width optimization-value narrowing.

Do not manufacture a runtime complexity class from refinement counts. The frozen outer theorem class remains
finite exact convergence.

## 7. Regression classification and routing

Every observed RED, crash, timeout, nondeterministic repeat, selector mismatch, or semantic assertion failure must
be recorded in `Regression_Root_Cause_Tracker.md` before TB1 closes. If evidence is insufficient for a stable
regression event/category, create or update a candidate/non-stable record and say why stable totals remain
unchanged.

Routing:

- all 373 green with immutable pre/postflight intact -> independent TB review/acceptance boundary according to the
  active turn policy; do not silently skip required review;
- any semantic RED/determinism failure -> `M4-CP1-TB1-REV` / Review + Plan;
- artifact/download/workflow-only failure before credible runtime evidence -> self-diagnose the orchestration path
  without rebuilding package114; only re-execute the unchanged artifact after the transport defect is corrected.

## 8. Immutable postflight

After all executions, verify package `SHA256SUMS` again and re-hash the test binary. The test binary must still be
`5b1064e6025b052aed7aeee66b8e1c3f6218bc73791d55fed4675484f4ea2afd`.

Record artifact ID, provider digest, source SHA, binary hash, selector full/prefix hashes, focused run 1, focused
run 2, cumulative selector result, elapsed/resource measurements, and `runtimeExecution=true` in the TB execution
record. Runtime evidence belongs to TB1 only; it must not be backdated into CB3.

## 9. Stop condition

If the package cannot be proven immutable or any required identity is absent, **stop**. Do not rebuild or modify
the package in the TB turn. If a semantic test fails, preserve the exact failing evidence and route it for review
instead of weakening the test, selector, exact arithmetic, incidence class, or fixed-`M=2` solver contract.
