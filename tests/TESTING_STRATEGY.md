# Surface-Cell Testing Strategy

## Mandatory direct matrix

Run in order: plane, multi-face seam, close sheets, cylinder, randomized `bunny_1k_random`, vase. Run all six even after failure when the active turn budget permits bounded execution; later fixtures cannot pass an earlier gate. A bounded timeout is failure only and does not synthesize a result.

Every direct success requires requested/executed `SurfaceCells`, fallback `Fail`, no fallback attempt, recovery disabled, non-empty pure quads, `CompletedSurfaceCells`, complete source provenance, strict validation, and deterministic output.

Topology/singularity fixtures such as torus and the prescribed sphere are additional active-gate fixtures and do not replace the production matrix.

## Fixture integrity

- bunny SHA-256 `865d864f7afbd90283526d914e0d4d9718d83e9679943029060bde439b10ab05`: 502 vertices, 1,000 triangles, closed, one component;
- vase SHA-256 `5f7bedc1783486589a8721a7b9be881064f361e4a07fd8c5278d8b8f55b2c868`: 1,274 vertices, 2,404 triangles, one boundary loop and 142 boundary edges.

Both use generated smooth fields through production extraction. Replacing, simplifying, bypassing, or special-casing either fixture is prohibited.

## Previous runtime authority and process disposition

Exact artifact **`9026181778`**, implementation `82151bf51bce9af9859282b2a03e295a0ee5a309`, is the latest immutable artifact-only runtime authority. Exact checksum/source/dependency/fixture/log verification passed; all **33/33** transition-quotient tests were discovered.

Focused results:

- transition quotient **24/33**;
- topology/isolation/hard rail **10/10**;
- polygonal/curved/mixed **12/12**;
- periodic/torus/cylinder **5/7**;
- remaining non-overlap Phase10 **35/39**;
- direct G0-G3 GoogleTests **1/4**.

Direct three-process results:

- plane fails 0/3 at `InvalidAuthoritativeTransitionSourceEdge`, cell/edge `63/162`;
- multi-face seam succeeds directly 3/3 with 81 vertices / 64 pure quads, complete lineage, structural `48661113839528d4`, semantic `99c8be7159d05c2f`, and no fallback/recovery;
- close sheets fails 0/3 at `InvalidAuthoritativeTransitionSourceEdge`, `199/12`;
- cylinder fails 0/3 at `InvalidPeriodicCutAuthority`, `287/3`;
- torus fails 0/3 at `InvalidPeriodicCutAuthority`, `191/0`, while retaining four regions/eight seams/four relations and consuming `0/0/0`.

Bounded suites: producer **143/161**, completion/simplification **154/164** with the same historical ten failures, validation **60/60**, compiled API **8/8**, aggregate **365/393**.

The artifact materially advances the gate by restoring direct multi-face seam and making the boundary/certificate/digest counterfactuals executable and green. The mandatory no-progress Review guard is not active; optional review policy is `never`.

Detailed runtime authority:
`.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`.

The next turn is Code + Build only under `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Plan.md`.

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

Runtime artifact `9022061741` proves tracing can produce authoritative cells in a topology region spanning multiple local isolation labels, but its materializer still requires one representative `sourceSheet` and keys identity by `(component, sheet, lattice)` plus a position check. Artifact `9024549134` executes the explicit transition quotient below, but exact torus stops at `UnconsumedAuthoritativeIsolationSeam` before any region/seam/relation consumption commits. The contract is not accepted.

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

Every active counterfactual must be independently discoverable in a default packaged artifact. Artifact `9026181778` proves all 33 independently named tests are present. Runtime is **24/33**: every certificate-negative and semantic-digest counterfactual passes, while multi-isolation lineage, winding periodic action, torus relation ownership, cylinder incidence, and retain/release remain active failures. Presence alone does not excuse a failing contract.

Genuine source-boundary routes retain canonical source-edge topology even when no two-face interior matching index exists. An interior transition/matching index remains mandatory wherever transport semantics require it; absence cannot be accepted generically.

For two-face transport, the numeric materializer-facing route is specifically one source-wide compact `edge_matching_indices(edge_faces(full source faces))` domain. `CrossFieldEdgeTransition.sourceEdge` is a full `mesh.EF` row and region-local active-face compact tables also renumber the domain; neither is interchangeable. CrossField transition metadata must be validated against canonical topology and reciprocal faces, then normalized to the source-wide compact index while topology remains positionally paired. Tests must include cases where the full `EF` row and a later region's local compact value differ, plus tampers substituting either alternate.

Internal-isolation-seam consumption uses one canonical reciprocal seam-transport certificate per retained seam. Each certificate owns exact source topology, two-face interior index, incident face/sheet authority, source component/topology region, and forward/reverse transport. Materialization validates the certificate bijection and consumes the certificates as the region's local-sheet connectivity graph for cells, fronts, relations, quotient classes, lineage, hashing, and diagnostics.

Current cell-boundary `transitionSourceEdges` remains exact evidence for an actual crossing but is not required to intersect every source seam. Metadata-only/unconditional marking, representative-sheet selection, and count/order/ID/proximity/position/lattice inference remain prohibited.

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

Artifact `9026181778` proves the true/false retention test is executable but failing: failure injection is folded into the same boolean as the caller's retain request, so `retain=false` still exposes trace authority; an earlier route-index rejection also preempts the intended injected failure. Internal lifetime needed to reach injection must be separate from public context retention, and both branches must return the identical injected failure with context present iff requested.

Required test separation remains:

- the torus topology test checks public region/seam diagnostics before any fatal context dereference and, after the quotient change, requires direct strict-valid success;
- a focused deterministic materialization-failure test checks trace context is retained iff requested;
- no permissive torus `Rejected` branch remains once the quotient implementation is compiled;
- following artifact-only acceptance requires one component, zero boundary loops, Euler zero, all four regions/eight seams/four relations consumed, and no predicted output count.

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

Report direct acceptance separately. Explicit focused/direct groups overlap the producer executable and must not be double-counted as independent aggregate evidence. Scheduler-sensitive wall-clock ratios cannot override semantic authority.

Latest artifact `9026181778` bounded totals:

- producer **143/161**;
- completion/simplification **154/164**;
- validation **60/60**;
- compiled API **8/8**;
- aggregate **365/393**.

The historical timing assertion remains non-authoritative for semantic acceptance. Completion's ten failures are unchanged. Any new failure in previously green certificate, boundary, digest, topology/isolation, polygonal/curved/mixed, validation, API, or direct multi-face-seam authority is a regression.

## Turn boundaries

Code + Build may edit active-gate implementation and valid producer-level regression tests and compile approved targets, but executes no generated project binary. Test + Benchmark uses one exact immutable artifact and performs no rebuild or source/test/fixture/validator edit. Review turns do not edit production source/tests, compile, or run tests/benchmarks.

The previously designated Code + Build turn under `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Plan.md` is complete. Its immutable artifact-only outcome is recorded in the current acceptance section appended below.

## Validity and prohibitions

Tests must encode real production contracts and valid scenarios. Never weaken assertions to fit behavior. No validator weakening, fixture special cases, fallback/recovery substitution, generic-producer substitution after authoritative rejection, positional sheet merging, count/order/frequency ownership selection, arbitrary subset search, synthetic topology correction, Euclidean periodic seam welding, post-hoc cell merging, or timeout-as-correctness.

## Canonical transition-index artifact acceptance plan (completed)

Implementation `edc14d38f862b94941b249f564050e2e1f8f5287` compiled successfully into immutable artifact `9028103772` (outer SHA-256 `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a`; verified 48-entry recursive manifest). The build used Release/static/Ninja with `PRE_TEST` and `runtimeExecution=false`; it is not runtime evidence.

The completed Test + Benchmark turn performed artifact preflight before discovery or execution and did not configure, rebuild, relink, regenerate discovery, edit source/tests/fixtures/validators, or mix artifacts.

Focused acceptance requires these exact tests:

- `SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
- `FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
- `RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
- `ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
- `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

The valid witness must prove source-wide compact/topology agreement independent of region partition; full-`EF` and region-local substitutions must each be rejected; genuine boundaries remain topology-only; and retain true/false must reach identical `InjectedStageFailure / tracing` with intermediate authority present iff requested.

Previously green certificate, boundary, digest, topology/isolation, polygonal/curved/mixed, validation, compiled-API, and completion/simplification cases are regression authority. Direct fixtures run plane, multi-face seam, close sheets, cylinder, and torus in order, with three fresh processes each; torus precedes sphere. Plane/close sheets must move past `InvalidAuthoritativeTransitionSourceEdge`, cylinder/torus past numeric route-index `InvalidPeriodicCutAuthority`, and direct multi-face seam must preserve same-artifact semantic digest `99c8be7159d05c2f`.

Historical suite totals are comparison evidence, not predicted success counts. Timing remains diagnostic unless an existing authoritative threshold applies. No fallback/recovery, generic substitution, fixture special case, validator relaxation, arbitrary subset search, predicted count, or timeout-as-correctness is allowed.

## Current artifact acceptance — canonical transition index

Artifact `9028103772` is the latest runtime authority. Exact preflight/postflight passes and no rebuild or source/test/fixture/validator edit occurred.

Direct plane, multi-face seam, close sheets, and cylinder are **3/3** direct strict-valid pure-quad successes with no fallback/recovery. Torus is **0/3** at downstream `completion/output-validation / LocalSheetMismatch` after complete `4/8/4` authority consumption and materialized `1/0/0` topology. Sphere and the broader manifest remain deferred.

The three canonical-domain counterfactuals currently fail before their intended assertions because their chosen pairwise-distinct topology is not present in any serialized cell route. `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` incorrectly treats compact route values as `mesh.EV` rows. `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason` incorrectly uses a compact route value to select `CrossFieldEdgeTransition.sourceEdge` in the full-`EF` domain.

The next Code + Build turn is test-authority-only. It must select an actually serialized three-domain witness, validate each numeric/topology pair through the source-wide compact map, and select malformed CrossField authority by canonical topology plus reciprocal faces. Assertions and typed failure expectations remain unchanged. Production source, fixtures, validators, CMake, benchmarks, and unrelated tests are out of scope.

Current bounded totals are producer **150/164**, completion **154/164**, validation **60/60**, compiled API **8/8**, aggregate **372/396**. The direct seam semantic digest remains `99c8be7159d05c2f` for same-artifact determinism.
