# M3-CP4c-3 CB8 — Exact Single-Authority Vertex Transit Code + Build Report

**Turn:** `M3-CP4c-3-CB8`
**Type:** Code + Build only
**Verdict:** **ARCHITECTURAL STOP / BUILD GREEN / RUNTIME-FREE**
**Semantic source audited and compiled:** `0d943f95b42e49813060399e83a1e4180e8348f6`

## 1. Result

CB8 triggered the mandatory **AW1 stop rule** before any product, test, fixture, selector, or topology-semantic edit.
The existing source/atlas products do not publish an exact or certified representation capable of carrying **one
arbitrary incoming tangent ray** across a general non-coplanar vertex fan and re-expressing that same ray in every
candidate face. Reusing `nextPairing->direction`, treating `signedLift` as geometric-ray transport, or restoring the
CB6 world-space `double` round trip would each violate the frozen CB8 plan and Amendments 17/18.

No semantic implementation was attempted after this finding. In particular:

- `resolve_field_vertex_transit` is unchanged;
- `direction_in_vertex_sector` is unchanged and remains exact/half-open;
- barrier and `FaceInterior` semantics are unchanged;
- selector 373 remains byte-identical and **selector 374 was not created** because the required regression identity
  could not truthfully be strengthened to prove a single-datum invariant;
- no immutable semantic package was created, because there is no new semantic source or valid selector-374 authority;
- ordinal 370, the prescribed sphere, and saturation remain untouched.

The next bounded work is independent **Review + Plan**, not TB: the project first needs a single-writer exact/certified
ray-transport authority (or a different upstream continuation-owner representation) before CB8 can be re-entered.

## 2. AW0/AW1 source audit

The frozen premises were re-established on the exact source snapshot.

### 2.1 Current election still substitutes a target-local representative

`resolve_field_vertex_transit` seeds `TransitState::incomingDirection` from the arrival
`FieldBranchBoundaryPairing::direction`. Across a fan adjacency it transports only the branch label with
`directed->signedLift`, locates the target pairing, and pushes:

```cpp
pending.push_back(TransitState{*nextFace, nextBranch,
                               nextPairing->direction,
                               std::move(transportPath), nextSignedLift});
```

The exact sector predicate then consumes that per-state `incomingDirection`. This is precisely the TB6-REV cause.

### 2.2 Atlas transport authority is branch correspondence only

The relevant public transport payloads contain no exact arbitrary-ray transform:

- `FieldTransportAdjacency`: source edge/faces, quarter-turn forward/reverse, integer `forwardLift`, and floating
  `effort`;
- `FieldBranchTransportAdjacency`: source edge/faces, quarter-turn forward/reverse, integer `forwardLift`, and
  floating `effort`;
- `FieldDirectedBranchTransport`: quarter-turn, integer `signedLift`, and floating `effort`.

`FieldBranchBoundaryPairing::direction` is an **independently constructed face-local value**. The builder projects
that face's floating cross-field representative into the face basis, converts the resulting binary doubles exactly
into `FieldExactRational`, and stores the resulting barycentric derivative. Exact storage does not make two such
face-local representatives one transported ray.

### 2.3 No alternative exact common fan chart exists in current products

The other nearby authority does not close the gap:

- `SourceChartTransitionGraph` publishes topological chart connectivity, shared-edge orientation, and corner
  permutation. It has no tangent metric/rotation or exact ray projection operator.
- The phase-front path has a special planar case that accepts physical zero-turn transport after floating
  planarity/alignment checks. That path is explicitly planar and tolerance-based; it is not a certified general
  non-coplanar fan transport and cannot feed this topological decision under Amendment 18.

For a non-coplanar fan, parallel/unfolded transport of an arbitrary tangent ray requires geometric metric/rotation
information not represented by the current rational branch-correspondence payload. `signedLift` can identify the
corresponding cross branch; it cannot recover the continuous transported ray. Therefore AW1's required
`one datum -> exact/certified face projections` chain cannot be constructed from current authority without either
inventing new authority or passing through uncontrolled floating point.

### 2.4 Production diagnostic loss remains real but is downstream of the stop

`FieldAlignedCurveNetworkError::vertexTransitStates` still retains the resolver's exact state rows, while
`RemeshPipeline.cpp::network_failure_locus` projects only the coarse locus into
`SurfaceCellFailureLocusDiagnostics`. CB8 did **not** extend this DTO because AW3 requires the missing single-datum
identity/projection to be part of each production row. Publishing richer rows for the known-invalid per-face datum
would improve observability while falsely suggesting the semantic prerequisite exists.

## 3. Selector governance

Frozen selector 373 remains:

- line count: **373**;
- SHA-256: `b47c269851fad1384b5dc9baaf674b3d4ad80ec6c2b40f7f8eda2055c6f44834`.

The existing identity
`ResolvedBranchCorrection.MinimalExactVertexTransitWitnessPublishesKnownFanState` remains outside selector 373.
It was intentionally **not** appended as ordinal 374 because its current assertions only prove an evaluated exact
state exists; they do not falsify `incomingDirection = nextPairing->direction` or establish a unique owner of one
transported datum. Append-only governance therefore remains unconsumed rather than being weakened.

## 4. Runtime-free compile evidence

A blocker compile was executed only to preserve the Code + Build boundary and prove the unchanged semantic source
remains compilable under the mandatory exact-arithmetic configuration.

- workflow run: `33467212874`;
- semantic source: `0d943f95b42e49813060399e83a1e4180e8348f6`;
- compile result artifact: `9785279716`, SHA-256
  `aa85ae5f6c4ca3d4e0a559f033ffea9c04030ceb6dcfc58fe7cbbdb4f64251f2`;
- compile log artifact: `9785279945`, SHA-256
  `febed58abc2d515505ce7a5d3a937fff4650d5c2a86c4bed42fd6de96ba6f25f`;
- `preflight_exit=0`, `build_exit=0`;
- all eight standard targets compiled/linked;
- `DIRECTIONAL_ENABLE_GMP=ON`;
- generated link evidence contains both `/usr/lib/x86_64-linux-gnu/libgmpxx.so` and
  `/usr/lib/x86_64-linux-gnu/libgmp.so`;
- `exactArithmeticBackend=GMP`;
- all recorded source-status snapshots are empty;
- `runtimeExecution=false`.

No Directional executable, test, benchmark, discovery/list/help/version command, or custom runtime input executed.
No package was created from this compile because CB8 produced no new semantic source or selector 374.

## 5. Deferred and stable authority

- Accepted prefix remains **365/365** from CP4c-2.
- TB6 remains the latest semantic result: first red ordinal 366 at vertex 30, with the 367–373 report-only remainder
  at 1 PASS / 6 RED and zero gate credit.
- Stable regression accounting remains **44 events / 14 categories / 30 recurrences**.
- Produced-witness debt remains **5**.
- Authoritative semantic M3 package count remains **73**; package 75 remains the latest semantic package envelope.
- Ordinal 370 remains independently owned by `SurfaceCutGraph::canonical_candidate`.
- Sphere `NoCarrierMatch / SourceEdgeUnavailable` and saturation remain deferred.

## 6. Mandatory successor

Stop the CB/TB loop at this architectural boundary. Exact next turn:

**`M3-CP4c-3-CB8-REV` — independent Review + Plan only**, under
`Architecture_M3_CP4c3_CB8_Independent_Review_Plan.md`.

That review must choose and freeze a single-writer representation capable of exact/certified non-coplanar fan
projection, or explicitly replace Amendment 17's transport-the-ray mechanism with another single-authority
continuation owner allowed by `DESIGN.md`. It must not authorize a target-local cross representative, raw
`signedLift`, tolerance, candidate ordering, or uncontrolled world-space floating transport as the correction.
