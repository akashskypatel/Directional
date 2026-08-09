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

The test-authority-only Code + Build turn is complete at implementation `de5261c7185aef71807b0b4140c8f023a44874fd`. It selects an exact serialized three-domain route position, validates every numeric/topology pair through the source-wide compact map, compares periodic authority through ordered topology, and selects malformed CrossField authority by canonical topology plus reciprocal faces. Assertions and typed failure expectations remain unchanged. Production source, fixtures, validators, CMake, benchmarks, and unrelated tests remain unchanged.

Current bounded totals are producer **150/164**, completion **154/164**, validation **60/60**, compiled API **8/8**, aggregate **372/396**. The direct seam semantic digest remains `99c8be7159d05c2f` for same-artifact determinism.

## Canonical test-authority artifact acceptance plan

Artifact `9029584083` is the sole next runtime candidate. It has outer SHA-256 `b9c2926ac71d5c765ec6ed89da7dc4a3fecbf55d00f4b24deeb1d26336a05dad` and verified **49/49** recursive entries. Release/static/Ninja compiled all seven approved targets at `113/113` with `PRE_TEST` and `runtimeExecution=false`.

Following exact preflight, run individually:

- the three canonical-domain counterfactuals;
- `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
- `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
- `ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
- `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

The positive witness must be an actual serialized later-region route position with pairwise-distinct source-wide compact, region-local compact, and full-`EF` values. Both substitutions must reach `InvalidAuthoritativeTransitionSourceEdge`. Face-row reversal must preserve ordered topology and per-mesh compact mappings. Malformed holonomy must remain exact `Rejected / PeriodicHolonomyMismatch / no proposals`.

Then preserve all prior-green groups and bounded suites and repeat plane, multi-face seam, close sheets, cylinder, and torus in order, three fresh processes each. Torus precedes and gates sphere. If focused authority passes and direct behavior is retained, torus `LocalSheetMismatch` becomes the earliest production invariant. No rebuild, artifact substitution, assertion weakening, fallback/recovery, validator relaxation, predicted count, or timeout-as-correctness is permitted.

## Canonical test-authority artifact acceptance — completed

Exact artifact `9029584083` was consumed without configure, rebuild, relink, source/test/fixture/validator edit, or artifact mixing. Discovery found producer 166, completion 164, validation 60, and compiled API 8 tests. One external wrapper attempt failed before binary invocation because `/usr/bin/time` was absent; corrected discovery then ran each GoogleTest executable exactly once.

The seven required focused contracts are **7/7**. In particular, the actual serialized three-domain witness passes, full-`EF` and region-local substitutions each reach `InvalidAuthoritativeTransitionSourceEdge`, periodic route/cut authority is face-row-invariant, malformed holonomy remains exact typed, incidence facts remain computed, and injected-failure context remains retained iff requested.

The plan's literal filter `-*BunnyRandom*:*Vase*` excludes three of 166 discovered producer tests. Report exact totals as producer **154/163**, completion **154/164**, validation **60/60**, API **8/8**, aggregate **376/395**. Do not compare this denominator directly with the prior stated **372/396**. An extra 164-test diagnostic ended without a GoogleTest summary and has no authoritative success total. Scheduler-sensitive timing remains diagnostic.

Direct three-process authority is plane, multi-face seam, close sheets, and cylinder strict-valid **3/3** each; torus **0/3** at `completion/output-validation / LocalSheetMismatch` after complete `4/8/4` consumption and materialized `1/0/0` topology. Sphere remains gated.

### Next face-chart validation contract

The next compile-only slice must add focused tests proving:

- exact retained charts plus reciprocal `HardRail` equivalence allow two quads on opposite rail sides even when shared scalar representatives name one side;
- missing, wrong-rail, wrong-route, unsupported, nonreciprocal, or ambiguous alternate authority fails closed;
- disconnected close sheets remain incompatible;
- face-row re-enumeration preserves the semantic chart side;
- full authority never masks scalar barycentric, position, component, or sheet failures.

Following compilation, artifact-only acceptance must run those tests individually, preserve the seven accepted focused contracts and prior-green groups, run the exact committed torus GoogleTest, and repeat plane → seam → close sheets → cylinder → torus in three fresh processes. Torus must reach direct strict-valid **3/3**, complete lineage, no fallback/recovery, `4/8/4` consumption, and final `1/0/0` topology before sphere may run.

## Hard-rail face-chart artifact acceptance plan

Implementation `8f37612148f34bac63cf294000c17c7de2e03b41` is compile-valid in exact artifact `9030700527` (outer SHA-256 `6eb42943aa8b27c88fa2afa45e22c5fbc9aa16da2d5cc52748de6e3e45474adf`; recursive manifest **49/49**, digest `698ee033667624819a369a4e64bd958eecfb2598e2c4cdd5caf7763fe6acad97`). Release/static/Ninja compiled the seven approved targets at `113/113` with `PRE_TEST` and `runtimeExecution=false`. This is not runtime evidence.

After immutable preflight, discover each GoogleTest executable exactly once and run the seven new `SurfaceMeshOptimizerPhase22` contracts individually. Positive authority must resolve distinct hard-rail sides and agree in optimizer/final validation. Missing/misaligned, wrong-rail, wrong-route, nonreciprocal, unsupported, ambiguous, and disconnected authority must fail closed; face-row invariance and scalar typed failures must remain exact.

Run the seven accepted canonical transition/periodic/retention contracts individually and the exact committed torus GoogleTest individually. Then execute the established bounded producer/completion/validation/API suites and prior-green focused groups. Report discovered denominators rather than predicting the validation increase.

Finally repeat plane, multi-face seam, close sheets, cylinder, and torus in three fresh recovery-disabled processes. Torus must be direct strict-valid **3/3**, with no fallback/recovery, complete `4/8/4` consumption, final `1/0/0` topology, pure quads, and complete lineage before prescribed sphere may run. No rebuild, artifact mixing, assertion weakening, global hard-feature chart union, validator relaxation, predicted count, or timeout-as-correctness is permitted.

## Hard-rail face-chart artifact acceptance — rejected

Artifact `9030700527` passed immutable preflight/postflight and discovered
166 producer, 164 completion, 67 validation, and 8 API tests. The seven new
face-chart tests and seven retained canonical tests are all green. Retained
groups remain **29/36**, **10/10**, **12/12**, **6/7**, **38/39**, and
**4/4**. Bounded suites are producer **154/163**, completion **154/164**,
validation **67/67**, API **8/8**, aggregate **383/402**.

Direct plane, seam, close sheets, and cylinder remain deterministic
strict-valid **3/3**. Direct torus remains **0/3** after complete `4/8/4`
consumption, 192 completed quads with complete lineage, and `1/0/0`
topology. It now reports 165 `LocalSheetMismatch` issues instead of 74.
Sphere was not run. The face-chart implementation is not accepted.

### Next focused authority

The next Code + Build turn must add compile-valid tests for:

- a scalar representative reaching a selected chart through two or more exact
  hard-rail relations;
- a face remaining valid when its vertices retain another valid unused
  relation;
- a reciprocal peer carried elsewhere in complete output authority rather
  than on the selected face;
- missing graph links, wrong rail/route/front identity, one-sided relations,
  unsupported charts, disconnected close sheets, and ambiguous intersections
  failing `LocalSheetMismatch`;
- source face-row invariance and preservation of all scalar typed failures.

The subsequent artifact-only turn must run those tests individually, retain
the existing 14 focused contracts and all bounded/group authority, then repeat
plane → seam → close sheets → cylinder → torus three times. Direct torus must
be strict-valid **3/3**; reduced mismatch count is not acceptance. The
historical exact-torus `InvalidHardRailPairing` result remains explicit and
continues to gate prescribed sphere until a separate scheduling slice fixes
it.

## Multi-rail chart-reachability artifact acceptance plan

Implementation `6af23d9aeca29e63aa13c4ae49f50d1748939c49`
is compile-valid in exact artifact `9031804178`. The artifact's outer
SHA-256 is
`27d16f485c357a236ffd43ce09c335bd246cb3f276cd9cc85b572ca543d87e9e`;
all **49/49** recursive entries verify with digest
`2fec5670eb81972233c52c9db1afe82e7eb92da812f1ab537a018bb0d31fb7e2`.
Release/static/Ninja compiled the seven approved targets at **113/113** with
GoogleTest `PRE_TEST` and `runtimeExecution=false`. This is compile
authority only.

After immutable preflight, discover each GoogleTest executable exactly once.
Run these four new `SurfaceMeshOptimizerPhase22` contracts individually:

- `MultiRailChainReachesSelectedChartWithoutConsumingUnusedRelation`;
- `MultiRailReciprocityMayBeCarriedOutsideTheSelectedFace`;
- `MissingMultiRailGraphLinkLeavesSelectedChartUnreachable`;
- `MultiRailChartReachabilityIsInvariantToSourceFaceRows`.

Then run the seven retained face-chart and seven canonical contracts
individually. The 18 focused checks must prove chained reachability, unused
valid relation tolerance, complete-authority off-face reciprocity, missing
link rejection, tamper/ambiguity/isolation rejection, row invariance, and
exact scalar typed failures.

Record the historical exact-torus GoogleTest separately; its entering
`InvalidHardRailPairing` result is a scheduling blocker outside this patch.
Preserve the six established focused groups and bounded
producer/completion/validation/API suites with discovered denominators.

Finally repeat plane, multi-face seam, close sheets, cylinder, and torus in
three fresh recovery-disabled processes. Torus acceptance is direct
strict-valid **3/3**, no fallback/recovery, complete `4/8/4` consumption,
final `1/0/0` topology, pure quads, and complete lineage. Reduced
`LocalSheetMismatch` count is not acceptance. Do not run prescribed sphere;
the independent scheduling blocker remains unresolved.

Every regression must update
`.agents/Directional/Regression_Root_Cause_Tracker.md` by stable ID and
earliest reason. Do not duplicate a recurring cause. `G4-R007` remains
`fix_pending_runtime` until this immutable artifact passes its direct-torus
gate. The repeated `AUTHORITY_DOMAIN_CONFLATION` and
`LOCAL_CONSUMPTION_OF_GLOBAL_AUTHORITY` families remain mandatory
architectural-review inputs.
