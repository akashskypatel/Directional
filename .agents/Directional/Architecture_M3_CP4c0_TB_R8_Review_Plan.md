# M3-CP4c-0-TB-R8 Independent Review + Plan

## Status

`proposed_pending_review` — **EXACT NEXT** after the interrupted TB-R8 run.

No runtime, compile, build, source/test/fixture/selector mutation, tolerance change, or TB-R8 retry is permitted in this review.

## Evidence authority

- semantic source: `19ba8e9c5e58f9c33c14b309841165d3f0401db5`
- immutable CB8 package: `9628445643`
- TB-R8 run/job: `33028238313 / 98374531360`
- partial result artifact: `9629797616` / `50462c5023a5cab817859eefb00b3f523e6cfe1e6d601188cd7c1e14a149c287`
- log artifact: `9629798008` / `217523d273a844c6f3c8f8a3e4c6d0314352d7620c8af24760b239a4d989977a`
- canonical report: `Architecture_M3_CP4c0_TB_R8_Test_Benchmark_Report.md`

## Binding observations

1. Selector ordinals 1-337 are green.
2. Ordinal 338 fails after `853.437 s` with `gcd(): while running too long!` after the prescribed-sphere singularity-7 partition locus at edge `(43,49)`.
3. Ordinals 339-342 are green.
4. Ordinal 343 did not return before user cancellation; it was the only selector process still missing because the gate executes synchronously in selector order.
5. `BigInteger::gcd` already has a 10,000-iteration emergency guard; it is too late to be a practical product termination policy for this path.
6. `FieldAlignedTraceTraversalGuard` already has exact-state recurrence and a structural step budget, but the prescribed sphere receives a budget of **1,775,616** steps. Its state includes the exact boundary point, so changing rational parameters can prevent early recurrence detection.
7. Do not re-run TB-R8 until a deterministic product-level guard is implemented and compiled.

## Review questions

1. Reconstruct the exact ordinal-338 and ordinal-343 candidate-trace progression from the CB8 source. Which loop or progression rule can repeat or accumulate exact-rational complexity without semantic progress?
2. Does CB8 grazing `EdgeTransit` allow a topological state to revisit the same face/branch/carrier with a different exact parameter? If so, what monotone or finite state component defines genuine progress?
3. What is the smallest safe deterministic guard?
   - Prefer a semantic cycle/progress invariant over a wall-clock timeout.
   - A finite step/operation budget may supplement the invariant but must be practical and derived from reachable topology.
   - Do not make the global `BigInteger` emergency limit the primary tracing policy unless evidence proves the defect is arithmetic-library-wide rather than tracing-local.
4. What typed error should own exhaustion, and which locus/history fields must be published so a future failure is actionable?
5. Can the guard reject any legitimate multi-edge/grazing trace? Prove the bound against the accepted witnesses and the prescribed sphere before authorizing code.
6. Is an exact-arithmetic operand/operation-growth guard also required, or is a corrected trace-progress guard sufficient to keep rational size bounded?

## Required review output

Freeze exactly one bounded Code + Build successor with:

- owning function(s) and invariant;
- deterministic guard semantics;
- typed diagnostic/error behavior;
- minimum regression-source additions, if any;
- compile targets;
- future artifact-only TB acceptance criteria;
- explicit statement that no workflow/test timeout substitutes for the product guard.

If the evidence cannot prove a safe invariant, stop and request a narrower diagnostic Code + Build turn. Do not guess by lowering arbitrary constants.
