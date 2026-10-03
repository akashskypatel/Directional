# M6-CP1-CB11-G4 — A6 closed-complex boundary / `G4-B002` mechanism Code + Build plan

**Held until:** `M6-CP1-TB10-A5V-REV` accepts CB10/TB10.
**Type:** Code + Build only; no Directional runtime.
**Successor if green:** `M6-CP1-TB11-G4-EXEC` -> mandatory `M6-CP1-TB11-G4-REV`.

## Goals

1. Implement R4 D3 `SurfaceQuotientClosedComplexView` as an immutable A6-owned projection, never reconstructed from retained arrangement authority.
2. Preserve multigraph edge identity with canonical side-incidence IDs; derive exact HardRail/Periodic labels from A5/A6 relation evidence and fail closed on partial/mixed/conflicting labels.
3. Derive strip identity from opposite-edge transitive closure in classed quads; do not import arrangement `family/strand` as semantic authority.
4. Add candidate-extraction support for the A6 boundary without `SurfaceCellPipelineContext::hasArrangement`.
5. On the existing produced torus fixture, author the migration-equivalence and independent-oracle tests specified by D3. Retained arrangement is test-only comparison authority, never a production input.

## Tests authored in this CB

Append after focused 1-24:

25. `M6CP1.A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus`
26. `M6CP1.A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels`
27. `M6CP1.A6ClosedComplexBoundaryPreservesQuotientVertexLineage`
28. `M6CP1.A6BoundaryCandidateExtractionHasIndependentEligibilityOracle`

Identity 28 includes a mechanism-only HardRail tamper and explicitly receives **zero direct-production debt credit**. Create focused-28 with focused-24 as an exact prefix and record its digest. Compile only; TB11 executes **28+449=477** fresh processes.

## Equivalence oracle

Use `milestone-g/torus.obj` + `milestone-g/torus.rawfield` with the existing 18 HardRails and fail-closed SurfaceCells options. Equivalence is labeled combinatorial isomorphism over class/quad/edge-side incidence, exact HardRail/Periodic owners and sorted occurrence-member vertex lineage. Positions, epsilons and hashes cannot establish the bijection.

## Compile/documentation gate

Use mandatory reusable GMP compile/package authority, standard eight targets and `runtimeExecution=false`. Preserve selector449, focused-12/20/24 bytes and all fixtures. Compile-green advances only to immutable TB11 and Review; it does not close `G4-B002` or CP1.
