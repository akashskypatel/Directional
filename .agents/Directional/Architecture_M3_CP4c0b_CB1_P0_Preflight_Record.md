# M3 CP4c-0b CB1 — P0 Preflight Record

**Turn:** `M3-CP4c-0b-CB1`
**Status:** **STOPPED BEFORE IMPLEMENTATION — P0.3 FALSE AS WRITTEN**
**Source inspection authority:** semantic head `49831e30433d72504a69b5a8c817aa6fa00f953c`; verified source-snapshot event SHA `a850b99e7d6b8d8053fee98fefba1e0bcca37704`, run `33084860326`, source artifact `9651687435`.
**Runtime:** none. No Directional binary, test, benchmark, discovery command, CLI, fuzzer, or custom input executed.

## Result

The frozen CB1 plan says **all P0 items are binding preconditions** and requires an immediate return to review if any fails. P0.3 requires `FieldAlignedNetworkEventKind::TraceIntersection` to be declared but produced by nothing. That precondition is false on the accepted source.

Independent static evidence is mutually reinforcing:

1. `M3_CP3_Closure_Record.md` §3 states that accepted CP3b delivered a typed first-contact/intersection/termination event graph, names `TraceIntersection`, and states that crossings become graph nodes at declaration time.
2. `src/geometry/SurfaceCellTracing.cpp::finalize_field_aligned_events` contains three production emission sites for `FieldAlignedNetworkEventKind::TraceIntersection` (singularity junction, first-contact finalization, and recurrence/closure finalization in the inspected source).
3. `tests/FieldAlignedCurveNetworkTests.cpp` contains accepted positive identities such as `DeclaresTraceIntersectionsAsTypedNetworkEvents` that require a produced `TraceIntersection`.
4. The public header comment for `FieldAlignedCurveNetwork` says CP3b extends candidate traces with a typed first-contact/intersection/termination event graph.

Therefore CB1 cannot legally reinterpret P0.3 as “no proper-crossing contact terminus yet” inside Code + Build. That may be the intended corrected baseline, but changing the frozen statement requires the independent review/plan boundary.

## Other P0 items

- **P0.1 supported:** CP4c-0 is accepted **346/346** with frozen selector SHA-256 `20d3b0b1400d5cab6af4a339a858c56fb7fd0359fb995a395dad215b20f3e46a`.
- **P0.2 supported:** `FieldAlignedCandidateTrace` still has `terminalBarrier` and `terminalSingularity` and no `terminalContact`.
- **P0.4 supported:** N1/N2/N4 backstops remain present and unmodified in the inspected source.
- **P0.5 supported:** the durable compile workflow is GMP-backed and records `exactArithmeticBackend=GMP`.

## GMP requirement

By explicit user instruction on 2026-08-27, GMP/GMPXX linkage is mandatory for **all future compiles**. Durable authority is `.agents/Directional/GMP_COMPILE_POLICY.md`. The existing `.github/workflows/agent-compile-reusable.yml` already provisions `libgmp-dev`, forces `DIRECTIONAL_ENABLE_GMP=ON`, uses `GMP_ROOT=/usr`, verifies discovery and both GMP libraries on a generated link command, and packages `exactArithmeticBackend=GMP`; no weakening workflow edit was necessary.

## Exact successor

**`M3-CP4c-0b-P0.3-REVIEW-PLAN` — independent review/planning only.** It must reconcile the frozen P0.3 wording with accepted CP3b authority and return the minimal corrected precondition. The agent loop stops completely at this boundary.
