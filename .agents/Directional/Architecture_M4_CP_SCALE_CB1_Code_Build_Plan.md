# M4-CP-SCALE-CB1 — S1 Exact Trace-Scale Census Code + Build Plan

**Turn:** `M4-CP-SCALE-CB1`
**Type:** Code + Build only; runtime prohibited
**Predecessor:** `M4-CP-SCALE-DEFN`
**Accepted runtime authority entering:** package `10331193451` / selector423 423/423.

## Objective

Add one passive, deterministic diagnostic surface that measures exact A2a trace-entry rational scale without changing any production decision. Compile/package the exact pushed revision for artifact-only TB1. This CB does **not** implement S2-S5 and does not append a selector row.

## Authorized source surfaces

1. `include/directional/geometry/SurfaceCellTracing.h`
   - define the minimal diagnostic row/result types and a package-visible diagnostic entry point, style-matched to the existing contact census;
2. `src/geometry/SurfaceCellTracing.cpp`
   - collect exact trace-step samples from the canonical construction path only when a diagnostic sink is supplied;
   - derive numerator/denominator/magnitude bit widths from the existing exact rational, with no conversion to double;
   - preserve all control flow and production outputs when the sink is null;
3. `tests/FieldAlignedCurveNetworkTests.cpp`
   - author the non-gating S1 diagnostic identity and a decision-neutrality/tamper-resistant measurement oracle;
   - use non-default/distinct exact parameters so an inert/default census cannot pass.

No other semantic source is authorized without STOP + Review. `cmake/DirectionalTests.cmake` is touched only if compilation/package ownership proves the new identity is otherwise omitted; no selector literal is added.

## Frozen diagnostic contract

Each row records `{trace, step, sourceFace, branch, incomingCarrier, sampleClass, numeratorBits, denominatorBits, magnitudeBits}` for the exact `entryPoint.parameter.value`. Aggregates use exact integer sums/maxima and exact `sum/count` means. Row ordering is canonical trace id then step. GMP/GMPXX measurements are authoritative for the package.

The diagnostic is **decision-neutral**: enabling/disabling collection must produce byte/semantic-equal normal network success/error result. No threshold, warning-to-error conversion, heuristic pruning or replacement of `kFieldExactContinuationMagnitudeBits` is permitted.

## Compile/build acceptance

- Exact intended files only; `git diff --check` clean.
- Required affected library + `directional_surface_cell_producer_tests` compile/link on the pushed evidence commit.
- Produce a complete immutable package containing every owner required by accepted selector423 for the successor TB; selector423 bytes/hash remain unchanged.
- Record GMP/GMPXX linkage and a self-excluding package checksum manifest.
- `runtimeExecution=false`; no generated Directional binary, test discovery, test, benchmark, CLI/help/version, fuzzer or custom input may execute.

## Required authored test properties (compile only in CB1)

`M4CPScaleS1.ExactTraceParameterScaleCensusIsDeterministicAndDecisionNeutral` must be able, in TB1, to prove:

1. at least one nontrivial exact rational sample is emitted;
2. independently recomputed numerator/denominator/magnitude widths equal the published row;
3. repeated census order/aggregate is deterministic;
4. collection enabled versus disabled leaves the semantic network result unchanged;
5. a deliberately changed exact parameter changes the measured width/value-class evidence, so the diagnostic is not a constant/default receipt.

## Successor TB1

Artifact-only `M4-CP-SCALE-TB1-EXEC` consumes the immutable CB1 package without rebuild/repair. It runs:
- package/source immutability preflight;
- the S1 diagnostic identity over the four retained witness families where their existing production/direct construction permits it, reporting coverage/deepest stage without inventing threshold credit;
- accepted selector423 **423/423** unchanged;
- immutable postflight.

S1 remains non-gating regardless of measured numbers. TB1 Review may freeze the next bounded CP-SCALE slice only after interpreting those measurements.

## STOP / falsifiers

STOP if implementation requires a guessed bit threshold, alters tracing decisions/errors, changes the 4096 guard, adds a selector row, executes runtime in CB, needs S2-S5 source changes, cannot show decision-neutral collection, cannot package all selector423 owners, or discovers the measurement cannot be derived from exact GMP-backed state without floating approximation.
