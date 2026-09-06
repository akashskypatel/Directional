# M3-CP4c-3-CB39 Code + Build Report

## Turn boundary

- Turn: `M3-CP4c-3-CB39`
- Mode: Code + Build only
- Runtime execution: **false**
- Evidence source: `7711b9c2c20d284823911aa4ca067bd33244f4e6`
- Compile run/job: `34061111130 / 101561719362`
- Result artifact: `9997560649` / `m3-cp4c3-cb39-result-34061111130`
- Result artifact SHA-256: `9a71fe17b789c94f70580116b822b3949dabecda7bf1d736afef10a1e6a9c3d2`
- Compile log artifact: `9997560940` / `m3-cp4c3-cb39-log-34061111130`
- Compile log artifact SHA-256: `6f11586812cf77cd601f0a2339b573d915d57cb2b1bfbda0cfecfa87066ed645`
- Packaged source archive SHA-256: `c0005445a764dda63a2fa2c6c30e512f26aabe84f944f23cde078046b4bf0fc7`

## Frozen scope implemented

CB39 implements only TB33-REV measures CU4–CU6.

1. **CU4 — correct the boundary-walk predicate.** `validate_single_boundary_walk` no longer rejects merely because a walk revisits its start node before consuming all incidences. The actual chain guard `next.first != current` and final closure guard `current != start` are unchanged.
2. **CU5 — typed boundary-walk evidence.** `RegionBoundaryWalkReason` distinguishes `ArcChainBroken`, `ClosedBeforeEnd`, and `WalkNotClosed`. `ClosedBeforeEnd` is recorded as evidence only and never rejects. The reason projects through remesh failure-locus diagnostics.
3. **CU6 — selector 409 hard negative.** Selector 408 remains byte-exact and is the first 408 lines of selector 409. Ordinal 409 is `GlobalTopologyPlan.RegionBoundaryWithTwoDisjointLoopsIsStillRejected`, which constructs two node-disjoint loops and requires rejection as `ArcChainBroken`.

Selector 409 count/SHA-256: **409** / `eea6d8c2bbc8e9247deb4bfbbe6763042c76002d1894dd62e35f80262403b53e`.
Selector 408 SHA-256 remains `2a742ba92dba744425fccaf81d5cc7a57885cbff37c779d525218fcd70500af6` and is an exact prefix.

## Scope audit

No topology construction, barrier semantics, ownership, separating-arc rule, retired guard, recovery policy, benchmark logic, accepted identities 1–365, or selector identities 397–408 were changed. No attempt was made to address carried rows 368/369/370/374/398 or to re-scope protected green witnesses 390/393/404/406/407/408.

The production behavior delta is intentionally narrow: a boundary sequence that returns to its own start node and then continues with a correctly chained next arc is no longer rejected solely for that revisit. Broken chains and non-closing walks still reject.

## Compile-only verification

The durable reusable compile workflow configured Release/static/PRE_TEST with GMP enabled and compiled/linked the eight standard targets:

```text
directional_core
directional_pipeline
directional_surface_cell_authority_kernel_tests
directional_surface_cell_producer_tests
directional_surface_cell_completion_tests
directional_surface_cell_validation_tests
directional_compiled_api_tests
directional_benchmarks
```

`runtimeExecution=false` throughout. No Directional test, benchmark, discovery, help/version command, CLI/GUI, `ctest`, fuzzer, or custom input was executed.

Compile evidence verified:

- exact pushed source equals `7711b9c2c20d284823911aa4ca067bd33244f4e6`;
- `DIRECTIONAL_ENABLE_GMP=ON`;
- GMP/GMPXX link evidence contains `gmpxx` and `gmp`;
- compile/build exits are zero;
- packaged command boundary records `turnBoundary=Code+Build-only` and `runtimeExecution=false`;
- root package checksums and packaged source authority are preserved in the immutable result artifact.

## Runtime claims deliberately not made

CB39 makes **no** runtime/semantic acceptance claim. TB33 remains the current valid semantic runtime authority at selector 408, 401 PASS / 7 RED, accepted 365/365. In particular, CB39 compile success does not establish that 366/367 advance or that ordinal 409 passes.

## Exact next turn

`M3-CP4c-3-TB34-EXEC`, artifact-only Test + Benchmark, consuming this exact immutable package and selector 409. Execute `.agents/Directional/Architecture_M3_CP4c3_TB34_Artifact_Only_Test_Benchmark_Plan.md` without rebuilding. After mechanically complete TB34-EXEC closeout, stop at independent `M3-CP4c-3-TB34-REV`.
