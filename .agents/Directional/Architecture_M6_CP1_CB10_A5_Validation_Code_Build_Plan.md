# M6-CP1-CB10-A5V — A5 validation migration / thin-adapter Code + Build plan

> **`M6-CP1-TB9-A7-R1-REV` release amendment — this block is authoritative with RA-19 below.**
>
> **Gate release.** R1 Review accepts/promotes `11292072930 / 584f80fe...` after **469/469**. The prior hold is discharged; `M6-CP1-CB10-A5V` is the exact next turn.
>
> **Shared `τ` obligation (mandatory, no tolerance-value change).** RA-18 defines the same-simplex point guard using A5's source-support resolver tolerance. A5 and A7 currently construct separate default `SurfacePointSourceSupportResolver` instances and A7 reads `barycentric_tolerance()` from its own instance. CB10 must make that accepted tolerance one canonical shared constant or accessor and make both A5 and A7 consume it. Preserve the accepted numeric default (`1.0e-8`) and all existing support predicates; this is authority single-sourcing, not a tolerance retune.
>
> **Evidence/falsifier.** The CB10 report must statically show one canonical `τ` owner and both A5/A7 reads. Focused15 remains the behavioral same-simplex falsifier inside the focused1-24 prefix. Stop for Review if single-sourcing requires changing the tolerance value, A7 support semantics, quotient identity/topology, fixtures, prior focused bytes, selector449, or unrelated source surfaces.
>
> **Still out of scope.** The A7 cross-sheet certification proxy remains owned by `M6-CP1-CLOSE-REV`.

> **Review-agent amendment (RA-22b, `M6-CP1-TB9-A7-R1-REV` addendum) — Goal T2 is added to CB10.**
>
> **Goal T2 — restore the representative-face guard.** Edit `src/geometry/PureQuadCompletion.cpp`, `close_completion_lineage_source_authority`, A7 branch only.
> - Before the retained-chart loop, require `region_for_row(sourcePoint.face) ∈ retainedSourceRegions` and `sheet_for_row(sourcePoint.face) ∈ retainedSourceSheets`.
> - Otherwise fail `CompletionOwnershipInvalidRetainedSourceAuthority:representative-face`.
> - Reject-only: the face values feed no destination, component, chart or lineage decision.
>
> **Test.** Strengthen focused 20's body (`M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`) with one negative, keeping the positive:
> - pick a materialized A7 vertex whose `sourceIsolationSheets` has at least two entries;
> - remove the representative face's sheet;
> - expect exactly the `:representative-face` failure.
>
> Do not rename the identity or edit the focused-20 file.
>
> **Gate neutrality (record in the CB10 report).** The pre-R1 TB9 run (`b8d27b63`) shows every gate process passed this exact preflight, so the restore cannot turn an accepted row RED.
>
> **Stop rule.** If T2 needs any change beyond restoring this guard, stop for Review.
>
> Gate unchanged: **24+449 = 473**.

> **`M6-DEFN-R4-REV` amendment (RA-19) — this block overrides the plan below where they conflict. Held until `M6-CP1-TB9-A7-REV`.**
>
> **Placement.** Moved category-(a) checks run inside A5 **after every check A5 performs today**, in their current relative and per-edge order. Earlier placement is allowed only with a per-required-test outcome proof in the CB10 report.
>
> **Identity 24** becomes `M6CP1.ThinAdapterOutputIsPureProjectionOfStageProducts`. On the hard-rail, split-isolation and produced-torus fixtures, the adapter's mesh, provenance and lineage must equal an independent test-side serialization of the A5/A6/A7 products, and no stage-valid input may be rejected.
>
> **Static check, not a test.** The "no semantic literal, tolerance or selection in the adapter" rule is a CB10-report check, not a gtest.
>
> Gate unchanged: **24+449 = 473**.

**Released by:** `M6-CP1-TB9-A7-R1-REV` after R1 recovery acceptance/promotion.
**Type:** Code + Build only; no Directional runtime.
**Successor if green:** `M6-CP1-TB10-A5V-EXEC` -> mandatory `M6-CP1-TB10-A5V-REV`.

## Goals

1. Move only R4 D2 category-(a) semantic predicates from `build_authoritative_phase_front_mesh` into the A5 producer boundary.
2. Remove duplicate adapter copies after A5 owns them; do not widen A5 semantics beyond the 31-site classification and its documented neighboring dynamic assignments.
3. Preserve validation precedence: individual HardRail route authority before pair/transport authority, and A5 before A6 before A7.
4. Make the adapter satisfy the R4 checkable thin predicate: stage invocation, typed-error mapping and serialization only.

## Frozen behavior

- `FalseAuthoritativeSourceBoundary` remains the public compatibility string for its accepted path.
- selector449 rows 227/230 remain `InvalidHardRailAuthority` for malformed individual routes.
- rows 139/140/142 remain `InvalidHardRailTransport` only after valid individual route authority reaches pair/transport validation.
- No adapter preflight, relation search, support/representative selection, topology repair or floating tolerance is allowed.

## Tests authored in this CB

Append after focused 1-20:

21. `M6CP1.A5OwnsPhaseFrontRegionAndBoundaryValidationBeforeA6`
22. `M6CP1.A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames`
23. `M6CP1.A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport`
24. `M6CP1.ThinAdapterPerformsNoSemanticValidationOrSelection`

The last identity is a source-structure/contract test and must fail if semantic decision logic reappears in the adapter. Create focused-24 with focused-20 as an exact prefix and record its digest. Compile only; TB10 executes **24+449=473** fresh processes.

## Compile/documentation gate

Use mandatory reusable GMP compile/package authority, standard eight targets and `runtimeExecution=false`. Preserve selector449 and every prior focused list. Close the CB with exact source/run/job/artifact/digest evidence and no runtime claim.
