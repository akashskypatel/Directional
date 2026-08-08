# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure when the active turn budget permits bounded execution; later fixtures cannot pass an earlier gate. A bounded timeout is failure only and does not synthesize a result.

Every direct success requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

Topology/singularity fixtures such as torus and the prescribed sphere are additional active-gate fixtures and do not replace the production matrix.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, bypassing, or special-casing either fixture is prohibited.

## Current runtime authority and mandatory review state

Exact artifact **`9022061741`**, implementation `3ca89ab55efff461b050fb12033174be70e7464f`, is artifact-only runtime validated.

Validated focused authority:

- topology-region / isolation-seam semantics **9/9**;
- generalized polygonal boundary phase **5/5**;
- retained non-torus curved-disk semantics **5/5**;
- non-torus sheet coverage **2/2**;
- G4 periodic-relation semantics **5/5**;
- retained G0-G3 **16/17** because `UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded` regressed.

Direct candidate results:

- plane `Produced / CompletedSurfaceCells`, 64 quads / 81 V, hash `730caeae49ec872c`, deterministic 3/3;
- seam `Produced / CompletedSurfaceCells`, 64 quads / 81 V, hash `5bdf34d7802e9fb0`, deterministic 3/3;
- close sheets `Produced / CompletedSurfaceCells`, 200 quads / 242 V / two components, strict-valid but candidate hash `aaec5574aa2e52f9` versus accepted baseline `89b052762f52a5af`; geometry is identical and component emission order is reversed;
- cylinder `Produced / CompletedSurfaceCells`, periodic `r=0`, `t=(32,0)`, route 32, cut 4, 288 quads / 320 V, zero validation failures, exactly two genuine exterior 32-edge loops, hash `32135be51d7a0a26`, deterministic 3/3;
- no passing direct case uses fallback or source-grid recovery.

Exact torus now proves topology-region authority and reaches `tracing/phase-front-materialization / InvalidAuthoritativePhaseFrontCell`: four annular topology regions, eight internal isolation seams, one region spanning two local isolation labels, four periodic relations, no fallback/recovery. The former `InvalidBoundedDiskBoundaryTurn` partition defect is gone.

Bounded suites: producer **124/127**, completion/simplification **154/164**, validation **60/60**, compiled API **8/8**.

Detailed runtime authority:
`.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Artifact_Only_Test_Benchmark_Report.md`.

Because accepted retained authority regressed, the two-no-progress process guard is active. **No ordinary Code + Build is authorized before mandatory independent Design Review.** Review plan: `.agents/Directional/Gate_4_Topology_Region_Mandatory_Design_Review_Plan.md`.

## Producer-authority contracts

The source distinguishes `NotApplicable`, `Produced`, and `Rejected`.

Mandatory behavior:

- applicable valid source regions may reach `Produced`;
- applicable invalid metadata reaches `Rejected`, not `NotApplicable`;
- `Rejected` generates no generic substitute work and remains terminal for the requested backend;
- typed rejection remains first-invalid authority;
- non-embedded relief guidance does not veto transport;
- **embedded relief barriers must remain fail-closed and cannot be bypassed because topology-region decomposition returns every local subproducer `NotApplicable`**;
- ordinary shared-edge and ordered source-vertex fan transport remain covered;
- reversed face ordering preserves structural results;
- malformed/duplicate/nonreciprocal transition data fails closed;
- source component, topology-region, and local isolation identity prevent unrelated capture;
- one accepted authoritative cell maps to exactly one quad;
- periodic source identity, field-authoritative correspondence, canonical source-simplex endpoints, exact quotient, and artificial-cut non-exterior behavior remain regressions.

## Topology-region versus local isolation-sheet contract

### Producer topology region

A topology region is connected only through exact source adjacency and is split by genuine source boundaries, hard features, or other review-approved explicit topological/barrier authority. Euler characteristic, genuine boundary-loop classification, disk/annulus applicability, region ownership, and exact-once coverage are evaluated on this region.

### Local isolation sheet

A local isolation sheet protects geometric operations from nearby unrelated surface capture/projection. Close/opposing-sheet classification may split one topology region into several local labels.

A non-hard edge whose exact source-adjacent incident faces have different local labels is **not automatically an exterior boundary**. It may be an internal isolation seam only if exact source adjacency and reciprocal field transition authority are valid. Proximity alone never establishes continuity.

Required regressions include:

- classifier-split annulus remains one topology region;
- face-row invariance of region/seam identity;
- exact reciprocal transport across a valid internal isolation seam;
- typed failure for malformed/nonreciprocal seam transport;
- hard-feature boundaries remain topology boundaries;
- spatially close but source-disconnected sheets/components remain isolated;
- exact-once aggregation across regions while preserving local-isolation provenance.

Do not union local labels by counts, IDs, frequency, discovery order, topology score, boundary length, proximity, or arbitrary subset search.

## Multi-isolation materialization contract — pending mandatory review

Runtime evidence proves tracing can produce authoritative cells in a topology region spanning multiple local isolation labels, but current materialization still requires one representative `sourceSheet` and keys lattice/periodic identity by `(component, sheet, lattice)`.

The mandatory reviewer must decide the complete public contract before implementation. Any approved solution must:

- use source-topology-region authority for phase/lattice/periodic ownership when one region spans multiple isolation labels;
- retain actual local-isolation provenance on exact source corners/lineage rather than erasing or arbitrarily selecting one sheet;
- prohibit world-space welding or proximity-based cross-sheet identity;
- keep true hard/source boundaries nontraversable;
- preserve one authoritative cell to one output quad and strict validation;
- retain cylinder periodic quotient semantics exactly.

## Deterministic output identity — pending mandatory review

Accepted direct hashes are currently:

- plane `730caeae49ec872c`;
- seam `5bdf34d7802e9fb0`;
- close sheets `89b052762f52a5af`;
- cylinder `32135be51d7a0a26`.

Artifact `9022061741` changes only close-sheets component emission order and therefore the raw output hash. **Do not update the baseline merely because the candidate differs.** The mandatory reviewer must decide whether exact component ordering is part of the deterministic product contract or whether the acceptance identity should instead be canonicalized independently of component order. Either decision requires independent contract justification and corresponding future tests.

## G4 polygonal boundary-phase contract

Retain the validated behavior:

- established rectangular curved disk follows the exact fast path;
- a natural non-rectangular orthogonal/reflex-corner disk constructs ordered source-attached transported runs and a deterministic polygonal chart without run coercion;
- invalid reciprocal turn fails typed `InvalidBoundedDiskBoundaryTurn`;
- cyclic field-index inconsistency fails typed;
- face-row re-enumeration preserves structural phase identity;
- source boundary and hard-feature provenance remain exact;
- mixed periodic/polygonal composition retains periodic authority without partial aggregate cells.

A changed error name is not progress by itself; real gate progress requires first-class state to be constructed and consumed.

## Exact torus contract test scope — pending mandatory review

`ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` currently aborts on `ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork)` because materialization fails before the trace network is moved into retained context. Public diagnostics nevertheless prove its intended topology-region/seam behavior.

The mandatory reviewer must determine whether `retainIntermediateGeometry` guarantees trace-network retention on this failure path. If not, future correction should assert the intended public topology/seam contract and separately test intermediate-retention semantics if needed. Assertions may not be weakened simply to obtain a pass.

## G3 periodic invariant

Periodic relation authority remains first-class:

- source topology and reciprocal transport identity;
- canonical equivalent/reversed representation;
- field-authoritative correspondence rather than ID/order/proximity choice;
- typed fail-closed conflict/ambiguity;
- every retained relation consumed by hashing, diagnostics, provenance and exact quotient materialization;
- single-annulus cylinder behavior retained exactly.

Artificial periodic cuts are never exterior output seams. No Euclidean seam welding is permitted.

## Contract tests versus production authority

Narrow synthetic/reconstructed fixtures isolate invariants but are not acceptance authority for the real pipeline. Exact committed fixture tests must enter production preprocessing/remesh and must not inject convenient topology-region unions, labels, transitions, target counts, or output cardinalities.

Tests verify semantic source/topology/transport identities instead of raw DCEL/source IDs or discovery order. Diagnostic torus vertex IDs, local-sheet counts, feature counts, relation counts, analytical parameters, and observed boundary lengths may not become production/test success keys.

## Default suites

Report direct acceptance separately. Explicitly executed focused/direct tests should be excluded from remaining aggregate totals where practical. Scheduler-sensitive wall-clock ratios are benchmark/closeout evidence only and cannot override semantic gate authority.

Current artifact `9022061741` bounded totals:

- producer **124/127**;
- completion/simplification **154/164**;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **346/359**.

## Turn boundaries

Code + Build may edit active-gate implementation and valid producer-level regression tests and compile approved targets, but executes no generated project binary. Test + Benchmark uses one exact immutable artifact and performs no rebuild or source/test/fixture/validator edit. Review turns do not edit production source/tests, compile, or run tests/benchmarks.

The current next turn is mandatory Review, not Code + Build.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, generic-producer substitution after authoritative rejection, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, Euclidean periodic seam welding, post-hoc cell merging, or timeout-as-correctness.
