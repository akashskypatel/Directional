# M4-CP-SCALE-CB18 — Separating Hard-Feature Singularity Ownership Code + Build Plan

**Turn:** `M4-CP-SCALE-CB18`
**Type:** Code + Build
**Owner from:** `M4-CP-SCALE-TB12-R4-REV`
**Generated Directional runtime:** forbidden
**Selector publication:** forbidden

## 1. Goal

Repair the one product authority seam proven by R4 Review: a prescribed globally-interior singularity that lies on a **hard feature which separates source topology regions** is globally nontraversable but is absent from every region's intra-region `barrierVertices`; current `FieldTransportAtlas` therefore gives it neither a local-cycle owner nor a slit/boundary owner and fails `SingularityMismatch`.

CB18 must give that singularity one deterministic boundary-cycle ownership path without changing source-region partition semantics, CB16 multi-component cycle ordering, retained genus-two authority, the S5 focus, or accepted selector bytes.

## 2. Allowed semantic surface

Expected minimal files:

- `src/authority/FieldTransportAtlas.cpp` — production ownership classification/binding only.
- `tests/FieldTransportAtlasTests.cpp` — direct independent regression control for a separating-hard-feature singularity.
- `include/directional/authority/FieldTransportAtlas.h` **only if required** to publish an honestly named non-authoritative diagnostic count that distinguishes separating-feature-boundary ownership from the existing intra-region slit count.

No other product/test file is authorized without STOP/replan. In particular do **not** change:

- `src/geometry/SurfaceCellTracing.cpp` source topology-region partitioning;
- `dual_cycles` / cycle-row construction or CB16 closed-component ordering;
- `benchmarks/fixtures/milestone-g/genus_two.obj`, `.rawfield`, or `.fixturemeta.json`;
- `M4CPScaleS5.GenusTwoProducedWitnessReachesA3WithVerifiedTopology`;
- selector426 or any prior selector; no selector427;
- CMake, benchmark semantics, package repair logic or accepted predecessor fixtures.

## 3. Product invariant

For each prescribed globally-interior singularity:

1. Preserve the existing local-vertex owner when the singularity is genuinely interior to one transport region.
2. Preserve the existing intra-region hard-barrier/slit path and `BarrierAbsorbed` semantics for non-separating hard barriers.
3. If the singularity is incident to a hard feature that is a **source-topology region boundary**, treat that source fact as a distinct absorbed-boundary authority. It must receive exactly one valid `BoundaryLoop` cycle owner from an incident region and `FieldSingularityFact::PortPolicy::BarrierAbsorbed`.
4. If multiple incident topology regions provide valid boundary-cycle candidates, choose the owner by stable canonical IDs (minimum/canonical `(TopologyRegionId, FieldCycleId)` or an equivalently explicit deterministic key). Container/region iteration order is not authority.
5. The chosen cycle must satisfy the same kind/index contract already required of other singularity boundary owners: `FieldCycleKind::BoundaryLoop`, matching singularity turning/index numerator, valid incident source region.
6. A separating-feature absorbed singularity must publish **zero origin port attachments**. Existing downstream `singularity_region_from_source(...)` already permits an explicit incident region and must not be weakened.
7. Ownership classes remain exclusive: a prescribed singularity may not silently acquire both a local interior-cycle owner and an absorbed boundary owner.

If diagnostics are changed, do not relabel a separating-feature boundary as an intra-region “slit”. Add/rename only enough diagnostic state to keep the domain explicit and keep `unboundSingularityCount` arithmetic truthful.

## 4. Independent regression control

Add one direct synthetic control in `tests/FieldTransportAtlasTests.cpp`, using an independently established fan or equivalent small mesh.

The control must establish **before** accepting atlas output that:

- the center/source singularity vertex is globally interior;
- at least two hard radial edges are supplied and actually split the source topology into multiple regions;
- each selected hard edge has its incident faces in different topology regions, so the test cannot accidentally exercise the already-covered intra-region slit path;
- the prescribed field has a nonzero, independently certified singularity index at the center;
- pre-CB18 ownership semantics would leave that center outside the local `barrierVertices` path.

Then require the corrected atlas to:

- build successfully;
- publish exactly one singularity fact for the center with the expected index;
- select one deterministic incident topology region and one `BoundaryLoop` cycle whose turning lift equals the singularity numerator;
- publish `PortPolicy::BarrierAbsorbed`;
- publish no singularity-origin port attachment for that singularity;
- leave `unboundSingularityCount == 0` under any new/adjusted diagnostics.

Preserve and re-run existing controls for ordinary emitted interior singularities, `ClassifiesHardFeaturesAsNontraversableCuts`, the non-separating barrier/slit path, branch topology, and CB16 cycle ordering.

## 5. Required compile/package boundary

Compile/package the standard eight targets under GMP/GMPXX using the repository reusable compile workflow. No local build and no generated Directional runtime.

Package must retain:

- exact accepted selector426 and first425 prefix hashes;
- exact retained genus-two fixture/rawfield/metadata hashes;
- no selector427;
- `runtimeExecution=false`;
- complete package/source manifest and normal executable/library modes.

The resulting package is an **unpromoted candidate**. Code+Build cannot grant S5/A3 or selector acceptance credit.

## 6. Falsifiers / STOP rules

STOP and return to Review/Plan rather than broadening the patch if any occurs:

1. The new separating-feature control does not fail against pre-CB18 ownership semantics; the gate is vacuous or does not isolate the R4 mechanism.
2. Correctness appears to require changing retained genus-two field/fixture bytes or `build_source_topology_regions` partition semantics.
3. An ordinary interior `Emit` singularity or the existing non-separating `BarrierAbsorbed` path changes unexpectedly.
4. A separating-hard-feature singularity gains origin ports.
5. Owner choice changes when region/container iteration order changes while canonical IDs remain the same.
6. CB16 cycle-row support decomposition/order semantics, `dual_cycles`, or the S5 focus must change.
7. selector426 changes, selector427 is introduced, or any accepted selector prefix changes.
8. The correction cannot keep owner classes exclusive or requires both local-cycle and absorbed-boundary authority for the same singularity.
9. The standard eight-target GMP/GMPXX compile/package gate is not green or any runtime executes in CB18.

## 7. Success condition and later runtime

CB18 succeeds only when the surgical product/test change and independent control compile/package GREEN with all frozen bytes/invariants preserved and no runtime. It does not close `M4-CP-SCALE-TB12-R4-EXEC-CAND-01`.

A later artifact-only Test+Benchmark turn must re-open the immutable CB18 package, execute direct separating-feature authority controls plus the frozen Gate-A controls, retry unchanged S5, and run selector426 only if all focused gates are green. Any semantic RED routes to mandatory Review before another correction.
