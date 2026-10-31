# M6-CP1-CB9-A7 Code + Build Report

**Turn:** `M6-CP1-CB9-A7`
**Authority:** RA-18 in `Architecture_M6_CP1_CB9_A7_Code_Build_Plan.md` and the accepted R4 amendment
**Final semantic source:** `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`
**Boundary:** Code + Build only; runtime forbidden and not executed
**Successor:** `M6-CP1-TB9-A7-EXEC` -> mandatory `M6-CP1-TB9-A7-REV`

## 1. Implemented A7 / RA-18 scope

The final semantic delta is confined to:

- `include/directional/pipeline/RemeshPipeline.h`
- `src/pipeline/RemeshPipeline.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp`
- `.agents/Directional/Architecture_M6_CP1_Required_Green_Focused_20.txt`

The implementation publishes immutable `SourceAttachedGeometryProduct` / `SourceAttachedGeometryProducer` authority over A6 quotient classes, carries A5 typed source support into A7, and replaces the adapter's semantic `1e-9` geometry coincidence check with the RA-18 certificate:

1. exact typed common source support from A5 `SurfaceOccurrence::support` only;
2. a reject-only same-simplex point guard using A5's `1e-8` barycentric tolerance;
3. `SourceSupportPointMismatch` / `:support-point` on guard failure;
4. no cross-kind coercion, merge, acceptance, or representative selection from that floating guard.

A7 representation is class-preserving: one A7 vertex per A6 quotient class, deterministic representative selection is representation-only, lineage projects A5/A6 authority without consuming placement transport, and A6 topology is copied without class mutation. Materialized completion ownership is exercised by the focused nonzero-Z4 production witness.

## 2. Focused gate authority

`Architecture_M6_CP1_Required_Green_Focused_20.txt` contains exactly 20 rows. Its first 12 rows are byte-identical to `Architecture_M6_CP1_Required_Green_Focused_12.txt`.

Focused-20 SHA-256:

`15d04a2a09eeb678923b0bfcf70bf9c07b79e7ff343ec468316f6510b16827d2`

Rows 13-20 are:

13. `M6CP1.A7PublishesOneEmbeddedVertexPerA6Class`
14. `M6CP1.A7ExactSourceSupportAcceptsVertexEdgeAndFaceInteriorClasses`
15. `M6CP1.A7RejectsSupportKindIdentityAndSameSimplexPointMismatches`
16. `M6CP1.A7RepresentativeIsInvariantToOccurrenceAndSourceRowOrder`
17. `M6CP1.A7ProjectsCompleteClassLineageAndSelectedRelationValues`
18. `M6CP1.A7NeverConsumesPlacementTransportForGeometryOrLineage`
19. `M6CP1.A7CopiesA6TopologyWithoutClassMutation`
20. `M6CP1.NonzeroZ4WitnessPassesProductionCompletionOwnership`

TB9 therefore remains exactly **20 focused + selector449 = 469** fresh exact-filter processes.

## 3. Compile-only repairs

The first bounded compile retry, run `37157543054`, compiled source `ab4f7557962123a964e1e3e6d181f110b6452b81` and exposed only non-default-construction errors for typed A7 aggregate values (`SourceSupportCertificate`, `SourceAttachedGeometryVertex`, and the local certified-cell record). Commit `19083f5451cdc394fdb1bc2a6bcbf8717b704aaf` replaces those invalid default constructions with explicit aggregate initialization.

The second compile retry, run `37159741505`, reached the new focused A7 tests and exposed only incorrect dereference syntax on typed `DomainResult` values. Commit `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8` changes those test-local accesses to `.value()` without altering production semantics.

No generated Directional executable ran in either failed compile attempt.

## 4. Mandatory compile/package result — GREEN

Authoritative compile/package evidence:

- workflow run/job: `37160018910 / 111311373537`;
- exact compiled source: `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8`;
- result/candidate artifact: `11287202960`;
- result artifact digest: `sha256:9bd87689c0155c3544de83159bd00169a4c8f932be4e878dbdd3dc7e7b5a179c`;
- compile-log artifact: `11287377799`;
- compile-log digest: `sha256:f3ebe94b0ce58abdd3a5f1376de5c222da6d9a600e9cb3e74dd5f6768c905ce5`;
- all eight standard targets compiled:
  `directional_core`, `directional_pipeline`,
  `directional_surface_cell_authority_kernel_tests`,
  `directional_surface_cell_producer_tests`,
  `directional_surface_cell_completion_tests`,
  `directional_surface_cell_validation_tests`,
  `directional_compiled_api_tests`, `directional_benchmarks`;
- `DIRECTIONAL_ENABLE_GMP=ON`;
- package metadata records `exactArithmeticBackend=GMP`;
- authoritative link evidence contains both `gmpxx` and `gmp`;
- the recursive self-excluding `SHA256SUMS` manifest verifies;
- source status is clean at the compiled authority;
- `runtimeExecution=false`.

No test, benchmark, generated Directional binary, discovery command, `ctest`, CLI, fuzzer, help/version command, or custom input was executed in this Code + Build turn.

## 5. Turn disposition

`M6-CP1-CB9-A7` is compile/package GREEN and runtime-free. The candidate is **not promoted** by Code + Build. Current reviewed runtime authority therefore remains TB8 `11265967968 / 8e0818b1...` until TB9 and its mandatory Review.

Stable accounting remains **60 / 16 / 44**, project debt remains 1.

Exact successor is `M6-CP1-TB9-A7-EXEC`, consuming immutable candidate artifact `11287202960` / source `b8d27b63425c11c27c45a1e7b9e2b866b0e1e8b8` and executing focused-20 in file order followed by selector449 in file order: **469 fresh exact-filter processes**, then mandatory `M6-CP1-TB9-A7-REV`. CB10 remains held until that Review.
