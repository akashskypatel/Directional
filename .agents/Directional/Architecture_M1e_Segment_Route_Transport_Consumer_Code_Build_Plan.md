# M1e Segment Route Transport Consumer — Code + Build Plan

**Status:** consumed — compile/package complete; immutable runtime pending
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — authority kernel and staged production adoption  
**Review policy:** `never`  
**Runtime during this turn:** prohibited

Completion authority: `.agents/Directional/Architecture_M1e_Segment_Route_Transport_Consumer_Code_Build_Report.md`. The authoritative next turn is the artifact-only Test + Benchmark plan.

## 1. Objective

Migrate exactly one real transport-owning production seam:

`surface_cell_tracing_detail::segment_on_source -> ordered transition route between consecutive SurfaceTraceSegment attachments`

This is the first appropriate production consumer for `TransitionStep` / `CanonicalRoute`. Unlike M1d's route-identity validator, `segment_on_source` actually owns an ordered sequence of source-edge crossings and composes each crossing's field transport to determine the next attached segment's matching.

Current legacy shape:

```text
route: vector<VertexPathStep>
totalMatching = 0
for step in route:
    transition = resolve_branch_transition(...)
    sourceEdge = source_edge_provenance(...)
    sourceEdges.push_back(sourceEdge)
    sourceTopology.push_back(step.edgeKey)
    totalMatching += transition.matching
...
current.matching = normalized_branch(totalMatching)
```

The objective is to make ordered semantic route transport authoritative while preserving current public/raw representation and product behavior.

## 2. Accepted entering authority

M1d is immutable accepted:

- implementation `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25`;
- build artifact `9046308272`, SHA-256 `6a9dd880e2e7548b8afc88da48e7ed49935e6ce672ba1af208eee8f84678152c`;
- manifest **59/59**, SHA-256 `e9859b25bd6d3a721484abdae679fcf898a85e1903b176192696d4b6b9e7eef0`;
- producer discovery **178**;
- M1d focused **6/6** and existing route witnesses **3/3**;
- M1c **6/6** plus transition counterexamples **3/3**;
- required-green producer segment **163/163**;
- M1b **6/6** + validation **77/77**;
- M1a **14/14**;
- T1 **29/29**;
- Plane/MultiFaceSeam/CloseSheets/Cylinder green and independent-oracle clean;
- Bunny known-red `NotProductionReady:completion` with independent-oracle-before-fatal ordering;
- Vase bounded at 60 seconds, safety-only.

Authoritative M1d report:
`.agents/Directional/Architecture_M1d_Phase_Front_Route_Identity_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

At Code + Build start, fetch the fresh PR/head and verify `9446fc82d98d336d3bd59c190dd2bbbe94bd2e25` remains an ancestor. Documentation cleanup commits after that implementation are expected and are not product changes.

## 3. Exact selected seam

In `src/geometry/SurfaceCellTracing.cpp`, `segment_on_source` constructs an ordered `std::vector<VertexPathStep>` whenever adjacent geometric trace segments attach through a source edge or ordered source-vertex fan.

For every step it already owns all facts required by semantic transport:

- ordered source face before the crossing (`transitFace`);
- ordered target face (`step.face`);
- packed source-edge topology (`step.edgeKey`);
- authoritative compact source-edge/transition index from `source_edge_provenance`;
- directed branch transport from `resolve_branch_transition`;
- matching effort;
- observed route order from previous segment toward current segment.

This is a genuine transport consumer. Adopting `TransitionStep` / `CanonicalRoute` here does not manufacture semantics.

## 4. Required implementation

Default allowed product/test paths are exactly:

- `src/geometry/SurfaceCellTracing.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`.

No public header, CMake, fixture, benchmark, pipeline, validator, or schema change is expected. Any additional path is a stop condition requiring re-planning.

For the ordered step route only:

1. keep route discovery/order, source-vertex-fan selection, topology-region checks, hard-feature/relief barriers, and `resolve_branch_transition` unchanged;
2. decode each existing `step.edgeKey` only at an explicit compatibility boundary;
3. convert both decoded endpoints through checked `LegacyAuthorityAdapters::source_vertex(..., vertices.rows())`;
4. construct canonical `SourceEdgeTopologyKey::make` and require its packed compatibility representation to reproduce `step.edgeKey`;
5. continue requiring `source_edge_provenance`; convert the returned compact value through checked `LegacyAuthorityAdapters::interior_transition(..., sourceMatchingIndices.size())` before semantic use;
6. convert directed `transition.matching` to `QuarterTurn::from_integer` and represent this seam's per-step field transport as `GridAutomorphism{rotation, {0, 0}}`;
7. construct an interior `TransitionStep` for the observed step. The observed route is forward from `previous` toward `current`; do not invent endpoint orientation from packed key ordering;
8. collect observed typed steps and create `CanonicalRoute::from_observed_steps` only after every step has validated;
9. use `CanonicalRoute::oriented_steps()` to recover the observed route and compose its `GridAutomorphism`s in order; the final semantic rotation, not raw signed integer addition, determines `current.matching`;
10. write `current.matching` back as the existing integer compatibility representation only at the public/raw boundary;
11. preserve `matchingEffort`, `transitionSourceEdges`, `transitionSourceTopology`, and `transitionSourceEdge` exactly as existing ordered compatibility/provenance storage;
12. fail closed on malformed typed identity/route construction without geometric or legacy fallback when authoritative metadata is present;
13. preserve the existing explicit legacy matching path when authoritative `edgeTransitions` metadata is absent; its values still cross the same semantic `QuarterTurn`/route composition boundary before `current.matching` is written.

All lattice shifts in this seam are exactly zero. Periodic lattice translation is not owned here.

## 5. Critical algebra/order rule

`compose(left, right)` means apply `right` first, then `left`. Preserve the observed step order exactly.

Do not assume raw integer addition is an acceptable proof merely because quarter-turn rotations commute in this restricted zero-shift case. The production migration must use the typed transport operation so later nontrivial automorphism extensions cannot silently inherit unrestricted integer arithmetic.

`CanonicalRoute` canonical storage must not reorder the behaviorally observed path. Use `oriented_steps()` when consuming transport so the current `previous -> current` direction remains authoritative.

Reverse-route evidence must prove algebraic inverse behavior rather than sign-negation convention.

## 6. Explicit exclusions

Do not migrate in M1e:

- periodic-holonomy loop accumulation (`build_periodic_phase_front` / `totalMatching` around the annulus);
- `UniformPhaseFrame::faceChart` or `FieldChartId` production;
- public `SurfaceTraceSegment` matching/provenance field types;
- `SurfaceFrontEdge::sourceRouteEdges/sourceRouteTopology`;
- phase-front HardRail/PeriodicCut identity validation already accepted in M1d;
- cross-field edge transition production already accepted at the M1c consumer;
- topology-region planning, shared hard-rail scheduling, periodic relation ownership/certificates, quotient materialization, completion, validation, fallback/recovery, optimization, or G4 repair;
- any fixture-specific branch or synthetic expected-output logic.

The separate periodic-holonomy transport consumer is a later bounded M1 slice if still required after M1e acceptance.

## 7. Focused semantic test suite

Add exactly six tests to existing `tests/SurfaceCellsPhase10Tests.cpp` under suite:

`SurfaceCellSegmentRouteTransportAuthorityMigration`

Required contracts:

1. `MultiStepVertexFanComposesTypedRouteTransport`
   - exercise a real `segment_on_source` ordered vertex-fan route with multiple crossings;
   - prove produced attachment succeeds and final matching equals the semantic composition of the authoritative step transports.

2. `ReverseObservedRouteUsesExactTransportInverse`
   - exercise the same semantic crossing in reverse orientation through production behavior;
   - prove reverse composition is the exact algebraic inverse and preserves source attachment.

3. `EquivalentSignedQuarterTurnsComposeSemantically`
   - use authoritative step metadata whose raw signed quarter-turn representation differs by a multiple of four;
   - prove semantically equivalent transport gives the same production relation/output rather than depending on raw integer magnitude.

4. `RouteTopologyAndCompactTransitionProvenanceRemainUnchanged`
   - prove the migrated semantic route still publishes the exact ordered existing source topology and compact transition provenance expected by downstream consumers.

5. `MalformedAuthoritativeStepMetadataFailsClosedWithoutFallback`
   - corrupt the authoritative `sourceEdge` sentinel for a predetermined edge
     on the exact multi-step route;
   - prove planar transition validation still succeeds and the real
     `segment_on_source` consumer rejects that step as
     `MissingTransitionProvenance`, with concrete cell/side diagnostics and no
     geometric/legacy recovery.

6. `LegacyMatchingFallbackUsesSameTypedRouteComposition`
   - exercise the existing explicitly permitted `edgeTransitions`-absent matching path;
   - prove it still produces the accepted relation while composing through the typed transport boundary.

Tests must call real production entry points that execute `segment_on_source`; no standalone reimplementation of route composition is valid test authority. Each test must assert observable product/failure/provenance relations, not just construction mechanics.

If a proposed fixture does not actually create the intended multi-step route or transport variation, fix the test input/fixture construction rather than weakening the contract.

### 7.1 Review-authorized reachability correction

The independent Review turn found that the original malformed-step wording was
not reachable through the production entry point. After
`source_edge_provenance` succeeds, the step topology comes from a real mesh
edge, its compact transition value comes from a contiguous derived map, and
`TransitionStep::interior` is construction-total for those validated facts.
Corrupting a transition endpoint instead fails earlier in transition lookup and
does not test this consumer.

The corrected fifth contract therefore targets the immediately preceding
authoritative provenance boundary inside `segment_on_source`. A nonnegative
`CrossFieldEdgeTransition::sourceEdge` remains validation metadata only; it is
not promoted to the semantic `InteriorTransitionId`. The typed ID continues to
come exclusively from the compact value returned by
`source_edge_provenance`. This correction removes an unreachable test premise
without broadening M1e production scope.

## 8. Required preserved witnesses

The following existing behavior must remain source-identical and compiled for the following immutable turn:

- `SurfaceCellsPhase10.UniformPhaseFrontTraversesOrderedAuthoritativeSourceVertexFans`;
- `SurfaceCellsPhase10.UniformPhaseFrontVertexFanIsInvariantToFaceRowOrdering`;
- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- `SurfaceCellsPhase10.PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
- all M1d six route-identity contracts and three route counterexamples;
- all M1c six field-transition contracts;
- M1b/M1a/T1 authority;
- direct product and known-red accounting.

M1e must not change accepted Bunny/Vase disposition or `PR8-R034 / G4-R007`.

## 9. Regression-pattern controls

### RP-01 — authority-domain conflation

Packed edge endpoints and compact transition indices cross named checked source-vertex/interior-transition adapters before semantic route construction. No raw integer may stand in for multiple domains.

### RP-05 — representation-dependent identity

`SourceEdgeTopologyKey` and typed `InteriorTransitionId` are semantic step identity. Packed edge keys and compact vector indices remain compatibility representation only.

### RP-07 — cyclic topology linearization

This is the primary M1e pattern. Per-step matching must be a typed quarter-turn/grid automorphism and route composition must use algebraic composition/inverse, not unrestricted signed accumulation.

### RP-02 / TA-05 — test-authority coverage

The six focused tests cannot replace exact producer accounting, M1d/M1c/M1b/M1a/T1 preservation, direct product oracles, or explicit known-red evidence in the following immutable turn.

No new search/retry loop is introduced; `RP-04` remains untouched.

## 10. Code + Build boundary

This turn may:

- edit only the approved two product/test paths;
- perform static source inspection;
- configure the approved Release/static/Ninja build;
- compile/link the same approved targets used for M1d immutable packaging;
- package source, tests, fixtures, binaries, libraries, manifests, source blobs, toolchain/submodule data, focused static test names, and command-boundary metadata.

This turn must execute **no generated Directional binary**, including:

- no `--gtest_list_tests`;
- no GoogleTest test;
- no benchmark;
- no `ctest`;
- no CLI/GUI/help/version command;
- no fuzzer;
- no custom input.

Record `runtimeExecution=false`. Configuration and compilation are allowed; generated binary execution is not.

## 11. Build/package acceptance

Code + Build succeeds only if:

1. product/test diff is exactly the two approved paths;
2. the typed route composition is statically present at the selected seam with no periodic-holonomy or chart migration;
3. exactly six `SurfaceCellSegmentRouteTransportAuthorityMigration` tests are statically present;
4. accepted M1d/M1c/M1b/M1a/T1 source/test blobs not intentionally touched by M1e remain source-identical except the approved Phase10 test file extension;
5. Release/static/Ninja approved targets compile/link successfully;
6. runtime boundary metadata proves no generated binary execution;
7. an immutable artifact with recursive `SHA256SUMS`, exact source archive/patch, executable hashes, static manifests, and fixtures is uploaded;
8. the following turn is explicitly an artifact-only Test + Benchmark turn.

Compile success does not accept M1e semantics.

## 12. Following immutable turn

The M1e Test + Benchmark turn must consume the exact Code + Build artifact and prove at minimum:

- exact package/source/executable preflight/postflight;
- producer discovery increases by exactly the six new focused contracts unless an independently explained test-layout change occurs;
- exact M1e six-member discovery and **6/6** fresh-process success;
- the two existing ordered vertex-fan witnesses remain green;
- M1d six + three route counterexamples remain green;
- M1c six + three transition counterexamples remain green;
- M1b **6/6** + full validation **77/77**;
- M1a **14/14**;
- T1 **29/29**;
- complete producer required-green/known-red accounting;
- Plane/MultiFaceSeam/CloseSheets/Cylinder remain green and independent-oracle clean;
- Bunny known-red and Vase bounded safety-only dispositions remain evidence-based;
- package immutability remains exact.

Any required-green regression blocks M1e and returns to corrective Code + Build. Do not advance to periodic-holonomy transport, `FieldChartId`, M2, or G4 remediation until M1e is immutable accepted.
