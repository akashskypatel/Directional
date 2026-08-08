# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure when the active turn budget permits bounded execution; later fixtures cannot pass an earlier gate. A bounded timeout is failure only and does not synthesize a result.

Every direct success requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

Topology/singularity fixtures such as torus and the prescribed sphere are additional active-gate fixtures and do not replace the production matrix.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, bypassing, or special-casing either fixture is prohibited.

## Current runtime authority and review disposition

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

Mandatory independent review is complete with decision **Approved with amendments**. Its authorized implementation compiled as exact artifact **`9024549134`**, commit `7f486632b154a303789df6c4dd44f602c8c71281`, Release/static/Ninja **111/111**, with `runtimeExecution=false`. The next turn is artifact-only Test + Benchmark under `.agents/Directional/Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Plan.md`.

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

A topology region is connected only through exact source adjacency and is split by genuine source boundaries, hard features, different source components, or equivalent explicit parent-chart authority. Euler characteristic, genuine boundary-loop classification, disk/annulus applicability, region ownership, and exact-once coverage are evaluated on this region.

Embedded relief is internal cut/transport authority beneath the parent topology region. It may create explicit child producer domains, but it may not change parent Euler/boundary facts or turn all unsupported children into parent `NotApplicable`. Once an applicable producer consumes the embedded barrier, unsupported coverage is terminal `Rejected`. Non-embedded relief remains guidance on shared-edge and source-vertex-fan paths.

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
- embedded relief preserves parent topology facts and remains terminal once consumed;
- non-embedded relief does not block an ordered source-vertex fan;
- non-source-boundary hard rails stitch exact counterpart output sides while cells do not cross the rail.

Do not union local labels by counts, IDs, frequency, discovery order, topology score, boundary length, proximity, or arbitrary subset search.

## Transition-quotient materialization contract — review approved

Runtime artifact `9022061741` proves tracing can produce authoritative cells in a topology region spanning multiple local isolation labels, but its materializer still requires one representative `sourceSheet` and keys identity by `(component, sheet, lattice)` plus a position check. Candidate artifact `9024549134` compiles the explicit transition quotient below; this contract is not accepted until artifact-only execution proves it is consumed.

Equal integer coordinates are not output vertex identity because charts may overlap. Approved tests must require:

- four explicit occurrences per cell and equivalence only through reciprocal ordinary front pairs, exact hard-rail pairs, or an explicitly owned periodic `R^r p + t` relation;
- owning cell side, rail/boundary kind, exact route, and periodic relation are first-class—never inferred from order/count/position;
- equal `(region,u,v)` occurrences without reciprocal connectivity remain distinct;
- actual local-isolation/source-chart provenance is retained on lineage rather than erased or selected;
- scalar `SurfacePoint` remains one exact chart after intrinsic source-support compatibility is proven;
- cells cannot cross hard rails, exact rail counterparts stitch, and genuine source boundaries alone remain exterior;
- every retained periodic relation is explicitly consumed;
- connected components, boundary loops, manifoldness, and Euler characteristic are computed from output incidence;
- preserve one authoritative cell to one output quad and strict validation;
- retain cylinder periodic quotient semantics exactly.

Counterfactual coverage must reject a representative-sheet substitution, unconditional topology-region lattice merge, Euclidean seam weld, first-relation selection, missing/ambiguous rail counterpart, unconsumed relation, repeated cell corner, and synthetic output topology.

## Deterministic output identity — review approved

Accepted same-artifact raw-hash observations are:

- plane `730caeae49ec872c`;
- seam `5bdf34d7802e9fb0`;
- close sheets accepted artifact `89b052762f52a5af`, candidate artifact `aaec5574aa2e52f9`;
- cylinder `32135be51d7a0a26`.

Artifact `9022061741` changes only close-sheets component emission order. Review determines that neither raw value is a cross-version semantic golden. Keep raw hashing for 3/3 same-artifact repeatability and add a canonical component-order-independent digest over exact connectivity plus source-authoritative lineage. Swapping output row/component order must preserve the semantic digest; changing connectivity, source support, winding, or component separation must change it. Do not restore a raw hash by source-ID ordering and do not accept a new raw golden merely because it differs.

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

## Exact torus and failure-path retention contracts — review approved

Under runtime artifact `9022061741`, `ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` aborts on `ASSERT_TRUE(result.surfaceCellContext.hasTraceNetwork)` because materialization fails before the trace network is moved into retained context. Public diagnostics nevertheless prove its intended topology-region/seam behavior, and the public `retainIntermediateGeometry` documentation makes the retention expectation valid. Candidate artifact `9024549134` compiles the retention-order correction and separated assertions; runtime proof is pending.

Fix production retention before a materialization failure, then separate the assertions:

- the torus topology test checks public region/seam diagnostics before any fatal context dereference and, after the quotient change, requires direct strict-valid success;
- a focused deterministic materialization-failure test checks trace context is retained iff requested;
- no permissive torus `Rejected` branch remains once the quotient implementation is compiled;
- following artifact-only acceptance requires one component, zero boundary loops, Euler zero, full region/relation consumption, and no predicted output count.

Assertions may not be weakened merely to obtain a pass.

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

The current next turn is immutable artifact-only Test + Benchmark using only exact artifact `9024549134` after checksum/source verification. No rebuild or source/test/fixture/validator edit is permitted.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, generic-producer substitution after authoritative rejection, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, Euclidean periodic seam welding, post-hoc cell merging, or timeout-as-correctness.
