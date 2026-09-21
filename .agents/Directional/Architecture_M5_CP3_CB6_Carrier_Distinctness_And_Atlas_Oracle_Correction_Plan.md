# M5-CP3-CB6 Carrier-Distinctness and Atlas-Oracle Correction Plan

**Turn:** `M5-CP3-CB6`
**Boundary:** **Code + Build / runtime-free**
**Predecessor:** `M5-CP3-TB1-R4-REV`
**Candidate entering turn:** artifact `10627250028` / source `001dfe8f0fec8a8dc2475e534fadc29967cadf84` — unpromoted
**Accepted runtime authority remains:** package `10601978228` / source `0798547dedd8be05f9cd7a096b07e6bd94755316` / selector430 **430/430**
**If green, exact successor:** `M5-CP3-TB1-R5-EXEC`

## 1. Goal

Correct exactly the two authority defects independently adjudicated by R4 Review while holding every other variable fixed:

1. remove the unfrozen generator-versus-cut carrier-identity inequality rejection from same-region periodic promotion;
2. extend the independent `FieldTransportAtlas` test oracle so its snapshot/digest independently covers CB5's retained transition-value identity domain and the six accepted atlas tests again reach their intended discriminators.

No other product or test semantics are in scope.

## 2. Authorized paths

Semantic/test mutation is authorized only in:

- `src/geometry/SurfaceCellTracing.cpp`
- `tests/FieldTransportAtlasTests.cpp`

Durable reports/plans and temporary workflow-control files may change under the normal turn policies. Any requirement to change another product/test/fixture/header/CMake/selector path is a **stop and return to Review** condition.

## 3. Production correction

In the same-region promotion path, preserve:

- the exact A3 `Mandatory` `span` / `GlobalTopologyPlan` source-path carrier;
- CB4 exact source-edge-parameter orientation, including `ExactSourceEdgePoint` support;
- CB5 atlas-only `transition_value(sourceEdge, fromFace, toFace)` consumption;
- hard-feature nontraversability and `transport(...)` adjacency-only semantics;
- `periodic_action_for_pair(...)` exact lattice endpoint correspondence;
- required route/action rotation agreement;
- §14.2 same-region promotion predicates and reciprocal route/family/advance-sign checks;
- checked `SurfacePeriodicHolonomy::make(...)`, CP2 failure semantics, relation reciprocity and canonical identity;
- cross-region `HardRail` behavior and same-region `HardRail` materializer rejection.

Remove only the two checks that reject because `generatorRoute->carrier_identity()` equals the cut route carrier identity in either orientation. Equality alone is permitted by frozen §3/§14/§15; it does not waive validity, action, endpoint, reciprocity or checked-factory requirements.

Forbidden: alternate/global path search, floating inference, raw production transition ingress, making hard features traversable, weakening zero-translation/action validation, changing `PeriodicRelationId`, or synthesizing a second relation owner.

## 4. Independent atlas-oracle correction

Update `IndependentAtlasSnapshot` and its independent digest/validator in `tests/FieldTransportAtlasTests.cpp` so expected transition-value identity is derived from source authority rather than copied from production digest/private storage.

The independent derivation must cover every validated interior source edge, including hard-feature/nontraversable edges, and canonically represent at least:

- source edge;
- exact two source-face topology identities;
- forward and reverse quarter-turn;
- signed lift/matching;
- canonical effort value used by the published identity.

The independent digest must include these facts in the same **semantic domain and canonical ordering** as the public contract while deriving expected facts from `TriMesh`, `SourceTopologyRegions` and `CrossFieldResult::edgeTransitions` (plus the already-independent source/branch authority needed to map faces). It must not call the production atlas digest, copy the production retained transition-value collection as expected truth, or use `transition_value()` merely to obtain the answer being checked.

Retain separate checks that hard-feature transition value does **not** create traversal adjacency.

The six accepted selector identities at ordinals 18, 20, 21, 22, 23 and 25 keep their names and intended relabel/tamper assertions. Do not weaken or bypass those discriminators to make baseline validation green.

Add exactly one focused test in this already-authorized file:

`FieldTransportAtlas.RetainsDirectedTransitionValueForHardFeatureWithoutTraversalAdjacency`

It must independently prove a hard-feature interior edge has the expected directed transition value (including reverse semantics) while no traversal adjacency exists and the edge remains a `HardFeature` barrier.

## 5. Frozen surfaces

Do not change:

- selector430 or any selector manifest/order/census;
- existing six produced test identities or row408;
- fixtures or benchmark source;
- `FieldTransportAtlas` public header/implementation in CB6;
- `PeriodicRelationId` or `SurfacePeriodicHolonomy` factories;
- `RemeshPipeline`;
- CP2 relation failure semantics;
- M5 frozen definitions except durable status/reference updates owned by a later Review.

## 6. Static verification before compile

Before build, prove from the diff:

1. only the two authorized semantic/test paths changed;
2. production removed only the carrier-distinctness rejection and preserved all other gates named in §3;
3. no raw transition fallback or traversal widening was introduced;
4. the independent oracle derives transition-value expected authority without production-answer circularity;
5. the six existing atlas identities remain present with their discriminators intact;
6. the one new focused test has exactly one static owner;
7. selector430 remains 430 LF rows at SHA-256 `1c4128500cb2f70f3bf00b85aadc44363ab89fdab906bf4aa7b140a4955a9db6`; first427 remains `f9c88380135a14d20492e215758cce35cab78ffe167b09fe5267d5ba2beae86f`.

## 7. Mandatory build

Compile/package only with GMP/GMPXX and `runtimeExecution=false`. Build all eight standard targets:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

No generated Directional binary, GoogleTest, benchmark, discovery/list/help/version command, CLI/GUI, fuzzer or custom input may execute in CB6.

## 8. Stop rules

Stop and return to Review without broadening scope if:

- removing carrier inequality exposes a need to change relation identity/factory semantics;
- a valid relation would require zero translation or weakening endpoint/action reciprocity;
- the generator carrier cannot be resolved from exact A3 span + atlas-owned transition value;
- independent expected transition-value identity cannot be derived without using the production answer as oracle;
- restoring the six atlas discriminators requires changing their intended expectations rather than the stale baseline identity model;
- any selector, fixture, additional product/test path, CMake source or public atlas implementation/header must change;
- mandatory GMP compile/package is not green.

## 9. Green disposition and R5 falsifier

Static-faithful compile/package green CB6 produces one unpromoted candidate and routes to fresh artifact-only `M5-CP3-TB1-R5-EXEC`.

R5 must restart from process 1 with no semantic-credit reuse and execute exactly:

- 9 reviewed mechanism identities;
- 1 new focused atlas nontraversal-transition-value identity;
- 6 frozen produced identities;
- all 430 selector430 identities in exact file order;

for **446 fresh exact-filter processes**, exact-one selection, zero skips, immutable pre/postflight and benchmark execution **0**.

The production falsifier is that all six produced identities and ordinal408 become green without weakening their existing discriminators. The test-authority falsifier is that the six accepted atlas identities become green on valid baseline and still reject their intended relabel/tamper perturbations, while the new focused identity proves transition value without adjacency on a hard feature.
