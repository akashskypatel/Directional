# Gate 3 Periodic Chart Endpoint Canonicalization — Code + Build Plan

## Required design declaration

```text
Active design gate: G3 periodic closure / holonomy
Earliest failing fixture: cylinder__surface_cells at tracing/phase-front, Rejected/InvalidPeriodicChart, cell 29
Missing design contract: tolerance-aware periodic chart clipping must emit canonical source-simplex endpoints so segments that meet at an exact source vertex or edge remain exactly shared in source geometry; clipping tolerance may decide triangle coverage but may not create geometric tails that the strict self-intersection validator sees as overlap
Smallest general implementation change: canonicalize and renormalize periodic_chart_segment barycentric interval endpoints onto exact simplex boundaries, remove any segment that becomes zero-length after canonicalization, and preserve exact shared breakpoint identity across consecutive chart intervals without weakening validate_closed_boundary_paths or its self-intersection predicate
Observable material-progress condition: the six currently regressed nominal G3 periodic contracts return to Produced/expected behavior, the field-authoritative correspondence contract reaches and passes its axial-family assertion, exact cylinder advances beyond cell 29 without losing field-authoritative correspondence, and G0-G2 remain green
Explicitly deferred work: completed-output normal/field/warpage remediation after phase-front authority is restored, G4 singularities/topology-distinct completion, G5 adaptive transitions/features, G6 bunny/vase production, scheduler timing, historical completion/simplification failures, validator changes and unrelated optimization
```

## Turn boundary

Code + Build only. Source/tests may change and approved targets may be configured/compiled/linked. Execute **no** generated Directional binary, test, benchmark, ctest discovery, CLI, GUI, help or list command. Use `PRE_TEST` or equivalent discovery mode.

This is the first runtime-no-progress Code + Build result since the prior source-strip material-progress turn. The two-consecutive-Code+Build no-progress review rule is not yet triggered. If this next Code + Build later fails artifact-only runtime acceptance without material progress, the following turn must be the mandated design review or bounded producer replacement proof.

## Exact retained authority

Start from final source/test commit `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a` and preserve:

- field-authoritative adjacent-ring candidate scoring through reciprocal transported 4-RoSy family/sign authority;
- typed `InvalidPeriodicRingCorrespondence` and `AmbiguousPeriodicRingCorrespondence` fail-closed behavior;
- topology-derived annulus applicability;
- deterministic cut and first-class holonomy design;
- source-strip breakpoints/subdivisions;
- artificial-cut ownership and exact quotient;
- source provenance and one accepted cell -> one quad;
- G0-G2 behavior and validators.

Do not restore lexicographic/source-ID correspondence selection merely because the old sheared chart progressed farther.

## Reproduced defect to fix

Artifact `9008118764` deterministically rejects exact cylinder at `SurfacePhaseFrontFailureReason::InvalidPeriodicChart`, cell 29, before traces. Independent immutable-source reconstruction matches that exact first rejected cell.

The reproduced boundary has two segments on source face 30 that geometrically share a source vertex but carry tolerance-expanded barycentric tails from `periodic_chart_segment()` interval clipping:

- side 0 segment 1: approximately `(-9.9999e-11, 0) -> (0, 0)` in barycentric 2D;
- side 1 segment 0: approximately `(0, 0) -> (-1e-10, 1e-10)`.

The strict self-intersection predicate is behaving consistently with the emitted geometry. Fix the producer representation upstream.

## Bounded implementation contract

1. Add a small canonicalization helper for `PeriodicChartTriangle` barycentrics used by emitted segment endpoints.
2. For each computed endpoint, clamp coordinates within the chart clipping tolerance of `0` or `1` to the exact simplex value, reject materially out-of-simplex values, and renormalize to sum exactly/robustly to one.
3. Derive consecutive interval endpoints from the same exact chart breakpoint parameter and canonicalize both sides consistently.
4. After canonicalization, drop zero-length/tolerance-only segments rather than emitting a microscopic tail.
5. When merging same-face consecutive segments, preserve the canonical endpoint rather than reintroducing the tolerance-expanded endpoint.
6. Do **not** change `segments_intersect_beyond_shared_endpoint_2d()` thresholds to make this case disappear.
7. Do **not** broadly increase `validate_closed_boundary_paths()` tolerance or special-case cell 29, cylinder IDs, source vertex numbers, counts or angular positions.
8. Real non-shared intersections and materially invalid barycentrics must still reject.
9. `Rejected` must remain terminal; no generic tracing/fallback/recovery substitution.

A preferred implementation is to separate **coverage tolerance** from **emitted geometry**: use tolerance to determine which chart triangle owns an interval, but project/canonicalize the output endpoint to the exact simplex boundary represented by the mathematical breakpoint.

## Compile-only regression source

Add/retain focused tests that compile and later prove:

1. a periodic chart segment ending at an exact source vertex emits exact canonical barycentrics, not negative tolerance tails;
2. adjacent periodic cell sides meeting at that source vertex share the exact same source point and are not reported as self-intersecting;
3. a genuine beyond-shared-endpoint overlap remains rejected by the existing validator;
4. `PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence` reaches `Produced` and its axial-family assertion;
5. `PeriodicPhaseFrontFieldAmbiguousRingCorrespondenceFailsClosed` remains typed `Rejected/AmbiguousPeriodicRingCorrespondence` with no generic seeds/traces/proposals;
6. all six retained G3 periodic contracts compile unchanged and are not weakened;
7. G1 plane and G2 seam/close-sheet producer contracts compile unchanged.

Do not weaken the existing failing G3 contracts to accept `InvalidPeriodicChart`.

## Compile/package authority

Compile the same seven approved targets unless a narrower set demonstrably covers every modified production/test translation unit:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

Package an immutable artifact with source authority, changed blobs/patch SHA, five executables, two project libraries, packaged fixtures, logs, compile commands, `runtimeExecution=false`, recursive checksums and outer SHA-256. Execute no generated project binary during Code + Build.

If a bounded remote workflow is required, remove/disable the path-filtered workflow **before** deleting its trigger marker, then remove payload/trigger debris and verify only durable `agent-source-snapshot.yml` remains.

## Following artifact-only acceptance

The next Test + Benchmark turn must first rerun the 15 focused/retained producer contracts. Material runtime progress requires all six nominal G3 periodic regressions to be restored without losing the typed ambiguity contract or G0-G2.

Then exact cylinder must at minimum advance beyond `InvalidPeriodicChart` cell 29 while retaining field-authoritative ring correspondence, periodic cut/holonomy/quotient/provenance and no fallback/recovery. G3 closes only if it ultimately returns direct deterministic strict-valid `CompletedSurfaceCells` with zero validation failures and existing quality thresholds satisfied.
