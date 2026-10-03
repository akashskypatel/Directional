# M6-CP1-CB11-G4 — A6 closed-complex boundary / `G4-B002` mechanism Code + Build plan

> **`M6-DEFN-R4-REV` amendment (RA-20, RA-21) — this block overrides the plan below where they conflict. Held until `M6-CP1-TB10-A5V-REV`.**
>
> **RA-20: two attributes per quotient edge.**
> - `relationKind` (Ordinary / HardRail / Periodic) from A6 certificates.
> - `hardFeatureProtected`, from typed source hard-feature authority: the HardFeature rail-edge set production passes to completion as `hardFeatureRailEdges`, supplied as an explicit input. An edge is protected iff every carrier step lies in that set.
>
> A HardRail edge that is not protected fails closed. Candidate extraction maps `hardFeatureProtected` to `touchesHardFeature`. Do not reuse A5's HardRail-route-only barrier set (`RemeshPipeline.cpp:3323-3331`).
>
> On the produced torus, the 18 user hard edges are **PeriodicCut** carriers (one region), not A5 HardRail relations. Identity 26 must show them protected.
>
> **RA-21: an executable oracle.**
> - Before identity 25, establish and record the static map: arrangement halfedge `(proposalId, proposalSide)` → `network.proposals[proposalId]` → A4 `CellId` and side.
> - Induce the vertex bijection from quad and side incidence. Arrangement nodes have no occurrence members; member-set lineage is checked on the A6 side only.
> - Compare `hardFeatureProtected` with the arrangement's `hardFeature`.
> - **Stop for Review** if the map is missing or not injective, if the arrangement subdivides proposal cells, or if the complexes are not isomorphic.
>
> Gate unchanged: **28+449 = 477**.

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
