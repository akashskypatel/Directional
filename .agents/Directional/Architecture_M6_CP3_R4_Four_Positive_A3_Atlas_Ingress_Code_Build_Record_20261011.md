# M6-CP3-CB1-ENTRY-R4 — four Phase10 original-source A3 positive ingress corrections (2026-10-11)

Canonical R4 `IN_PROGRESS`, successor `UNKNOWN`; Code + Build only. PR #8 draft/unmerged.

## Frozen authority and code change

- Verified exact source snapshot workflow `38169914358`, event `78f0d5edebb91b23094c28a61b3a55afffeb9500`, outer ZIP SHA-256 `9cc3565c31b1ba29ca1def744c1af412c35b44272cf12c62e869b02540c3a582`, inner source archive `e2c4d3edb78e9791f08a1dc40a7df28c28495a9753c94f84ee8189f1efcbca4b`; `6252/6252` source entries verified, snapshot `runtimeExecution=false`.
- The following **existing produced-positive test bodies** passed null `fieldTransportAtlas` to direct `build_surface_cell_network`: `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`; `SurfaceCellsPhase10.PeriodicPhaseFrontRetainsCanonicalBoundaryStripBreakpoints`; `SurfaceCellsPhase10.PeriodicPhaseFrontCanonicalizesSourceSimplexEndpoints`; `SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`.
- Source-exact test patch replaces only those four direct calls with `build_phase10_with_source_atlas(mesh,crossField,targetSize,options)`, which builds original-source A2 topology and independent A3 atlas and fails closed if invalid. No production implementation, test names/expected outcomes, source fields, source mesh/labels/fixture, selectors or permissions altered. The test-only helper already existed and is used for other Phase10 positives.
- Exact patch SHA-256 `3c778ce7af8da99e0e30fe347d0932655a1750c64beb09f0ae717dc663843df4`; body `ab726f1c5456cdb5f13bc6b827269c79e39340d65d9aa9f5a83dabfef15f9063`; base `a6235df3e2a793b69a61c98def0b3b45f2ed8a06`. `git diff --check`, `git apply --check` passed. Backed up to ChatGPT Library `/Directional/Evidence/Directional_M6_CP3_R4_Four_Positive_A3_Atlas_Ingress.patch` and applied via Drive workflow `38170296491`, exact semantic commit `ee800cce8d3bef34a8f2f891d0482cd8ff7a9f68`; applied digest and changed path verified, consumed stage owner-deleted.

## Compile-only evidence

Eight-target source-exact GMP/GMPXX compile **GREEN**: workflow `38170442175`, job `114561804678`, source `ee800cce8d3bef34a8f2f891d0482cd8ff7a9f68`; preflight/build exits `0/0`, 8/8 targets, CMake `DIRECTIONAL_ENABLE_GMP=ON`, both `libgmpxx.so` and `libgmp.so` linked, package `SHA256SUMS` 28/28, clean source, `exactArithmeticBackend=GMP`, `runtimeExecution=false`; result artifact `11713818041` outer ZIP SHA-256 `dd506cef5b50423857893f35266404c699ed4dea42ebaff6345187c86c7eb269`, diagnostic artifact `11713098129` ZIP SHA-256 `b3c68ccf3dda22893daf2daaf80a237b618876a54140084e9d0a323a7388228a`.

## Limits and next continuation

No generated Directional binary, test, benchmark, `--list`, selector discovery or frozen 497 acceptance executed or authorized. These four positive fixtures are not credited as current R3 RED restorations: historical R3 `403/497`, 94 RED, 88 lost prior accepted CP2 identities; CP2 accepted baseline `491/491`. The original R4 39 endpoint, 34 Phase10, seven DCEL, 88 CP2, six CP3 gates, producer-valid multi-carrier/odd-tau, and dual-path independent architecture decision remain outstanding. A later formally authorized separate artifact-only Test + Benchmark must prove runtime outcomes before totals change.
