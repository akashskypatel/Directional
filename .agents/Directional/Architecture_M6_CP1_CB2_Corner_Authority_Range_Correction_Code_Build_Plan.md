# M6-CP1-CB2 — A5 corner-authority range correction Code + Build Plan

**Turn:** `M6-CP1-CB2`
**Type:** Code + Build only
**Predecessor:** `M6-CP1-TB1-REV`
**Boundary:** correct the single Review-proved cross-temporary `IsolationSheetId` membership range in A5; compile/package only; no generated Directional runtime

## Goal

Restore accepted behavior without changing A5/M5 semantics by correcting the invalid iterator range in `SurfaceOccurrenceComplexProducer::produce(...)`. Hold every other variable fixed so the next immutable gate can falsify or confirm this exact recovery.

## Proven root cause

`SurfaceTopologyRegion::isolation_sheets()` returns a `std::vector<IsolationSheetId>` by value. CB1 calls it separately for `begin()` and `end()` inside one `std::binary_search`, so the range endpoints belong to different temporary vectors. `M6-CP1-TB1-REV` independently proves this is the accepted->RED differential and corrects the stable category to singleton `CROSS_TEMPORARY_ITERATOR_RANGE`.

## Authorized implementation

1. Change only the A5 corner-authority membership check in `src/pipeline/RemeshPipeline.cpp`.
2. Materialize `isolation_sheets()` once into stable storage before the membership search, or use an equivalently stable precomputed region-sheet vector.
3. Use `begin()` and `end()` from the same stable object.
4. Preserve the existing source-region equality, source-component equality, typed sheet membership, source-support resolution, chart validation, occurrence identity, relation publication, and fail-closed error semantics.
5. Compile/package the standard eight approved targets through `agent-compile-reusable.yml` with mandatory GMP/GMPXX.

## Explicitly not authorized

- no test or fixture edits;
- no selector/routing publication or mutation;
- no `OccurrenceId`, A4 `CellId`, M5 relation, source-support, projection-chart, topology-region, component or isolation-sheet semantic changes;
- no barycentric/source-simplex canonicalization and no `SurfacePointSourceSupportResolver` contract change; that is a distinct downstream hypothesis not established by TB1 while the earlier iterator range is undefined;
- no A6/A7/A8 extraction or implementation;
- no hard-feature/isolation-sheet reclassification;
- no fallback/recovery or validator weakening;
- no benchmark semantic edits;
- no generated Directional runtime, test, discovery, benchmark, CLI/help/version execution.

## Static verification before compile

Code + Build must prove from exact source that:

1. no range algorithm in the changed A5 path obtains `begin()` and `end()` from separate calls to the by-value `isolation_sheets()` accessor;
2. the repaired range uses one stable container and preserves sorted `IsolationSheetId` membership semantics;
3. all three A5 corner-authority layers remain present: source face/region, component/sheet, then support/chart validity;
4. no product/test/fixture/selector/benchmark/header surface outside the single bounded correction changed;
5. selector449 remains exactly 449 LF rows at SHA-256 `d4a0d1b731cfd99e832f3c983e5741ab18cb27a314f380184c5ff84bd88d6414` and routing449 remains `9c88a5ed3de0419c313aa0a36c0e2cf63e7edcdc17c06d9b74311f371c6c5707`;
6. the six frozen CP1 focused identities remain present unchanged, including `SurfaceCellTransitionQuotient.MultiIsolationMaterializationRetainsAllLocalSheets` and `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`.
7. no unrelated support-resolution or barycentric admissibility behavior is changed to anticipate a possible later failure; CB2 holds that variable fixed.

## Compile/package outputs

Compile/link exactly the standard eight targets:

- `directional_core`
- `directional_pipeline`
- `directional_surface_cell_authority_kernel_tests`
- `directional_surface_cell_producer_tests`
- `directional_surface_cell_completion_tests`
- `directional_surface_cell_validation_tests`
- `directional_compiled_api_tests`
- `directional_benchmarks`

Package exact source, GMP/GMPXX linkage evidence, clean source-status receipts, command boundary and recursive self-excluding manifest. Require `runtimeExecution=false`.

## Falsifiers / stop rules

Stop and return to Review if the correction requires any of the following:

- removing or weakening region/component/sheet validation;
- changing projection-chart or canonical source-support semantics;
- changing any test/fixture/selector to make the candidate pass;
- altering A4/M5 semantic identity or relation ownership;
- touching A6/A7/A8 or fallback/recovery behavior;
- broad refactor beyond the one proven iterator-range defect;
- executing generated Directional runtime during Code + Build.

A compile-only syntax/integration failure may be repaired only if the repair remains within this exact source seam and does not expand semantic scope.

## Success criterion and exact successor

CB2 completes only with the bounded source correction, static guards above, all eight GMP/GMPXX targets compile/package green, complete immutable evidence, and no generated runtime.

The package remains a **candidate only**. Exact successor is **`M6-CP1-TB2-EXEC`**, which must run the unchanged six focused identities plus unchanged selector449 as exactly **455 fresh exact-filter processes**. Recovery requires **6/6 focused + 449/449 selector PASS**, exact-one selection, zero skips/crashes/selection mismatches and exact immutable postflight. Any RED is preserved and handed to mandatory runtime-free **`M6-CP1-TB2-REV`**; TB2 may not repair or rerun a valid semantic result.

Any post-range-repair `InvalidCornerAuthority` that reaches support-resolution or barycentric admissibility is fresh TB2 evidence for mandatory Review; it is not authorization to broaden CB2.

## Reviewing-agent amendment (`M6-CP1-TB1-REV` review) — binding on CB2 and pre-registered for TB2/TB2-REV

1. **Scope is confirmed sufficient.** A codebase-wide scan of all eight by-value container accessors in the headers (`isolation_sheets`, `oriented_steps`, `carrier_identity`, `region_by_face`, `singularity_vertices` and the string accessors) finds exactly one `X().begin() … X().end()` split range: `RemeshPipeline.cpp:3337-3338`. No other instance of this defect class exists, so the one-variable scope is sufficient. CB2's static check 1 should re-run this scan over the whole tree, not only the changed A5 path.
2. **TB1 focused PASSes carry no credit.** `…PublishesFourSemanticCornersPerCell`, `…SourceFaceRowPermutationPreservesOccurrenceIdentity` and `…RejectsMalformedMissingAndDuplicateRelationEndpoints` all PASSed in TB1. Each calls `SurfaceOccurrenceComplexProducer::produce` on the single-region `square_fixture()`, so they executed the undefined range and may have passed by chance. Only TB2, after the fix, can credit them.
3. **Pre-registered TB2 classification.** `M6-CP1-TB1-EXEC-CAND-01` counts as recovered only if both hold:
   - no process reports `OccurrenceInvalidCornerAuthority`;
   - accepted selector449 is 449/449.

   A focused RED whose **first failure is different** is a **new candidate**, classified on its own merits, not a failed recovery of CAND-01. This matters most for `M5CP3.ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection`, which has never run cleanly (in TB1 it stopped at the same A5 seam). A RED from it could be a latent M5 edge-storage-order dependence that predates CB1. Conversely, any remaining `OccurrenceInvalidCornerAuthority` is a failed recovery, and the new first sub-predicate must be localized before any further hypothesis, such as barycentric admissibility, is credited.
4. **Benchmark digests.** CB1's `BenchmarkQuality.cpp` edit hashes `OccurrenceId` as `(cell, canonical_corner_role)`. It was a necessary compile adaptation to the frozen semantic `OccurrenceId`, and it changes the benchmark semantic-digest domain but no benchmark input. CB2 must not touch it. Any stored benchmark baseline keyed on the old digests is superseded, and none is gated.
