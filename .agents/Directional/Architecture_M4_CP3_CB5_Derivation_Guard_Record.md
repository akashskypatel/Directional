# M4-CP3-CB5 pre-mutation derivation guard — exact A3→A4 shared-boundary authority

**Turn:** `M4-CP3-CB5`
**Status:** PASS / STATIC / PRE-MUTATION GUARD
**Runtime:** none
**Guard authority:** `.agents/Directional/Architecture_M4_CP3_CB5_Code_Build_Plan.md` §3

## 1. Decision

The mandatory CB5 derivation guard **passes** for the bounded hard-rail producer that the cutover will change. The accepted A2b/A3 products already contain enough exact identity to determine every shared A4 hard-rail subdivision segment without tolerance, rounded barycentrics, local target/grid counts, synthetic-node allocation order, or post-hoc partner agreement.

No upstream semantic convention is added by CB5. The cutover only transports and consumes authority that already exists.

## 2. Accepted identity chain

The derivation is one-way and exact:

```text
A2b GlobalTopologyArc.id (NetworkArcId)
  -> ConformitySpanId::from_network_arc(arc.id)
  -> A3 GlobalConformityBaselinePlan::find_schedule(span)
  -> schedule.count + schedule.supportPieces
  -> baseline.breakpoint_location(span, ordinal)
  -> exact consecutive ordinal interval [j,j+1]
  -> A4 chart orientation from ordered source-boundary traversal
  -> SurfaceSharedBoundaryInterval{arc.id,j,j+1,orientation}
```

`ConformitySpanId` is definitionally bound 1:1 to the owning A2b `NetworkArcId`; the A4 receipt stores the underlying `NetworkArcId` because it is the stable semantic identifier used by `ConformitySpanId::from_network_arc(...)`. No geometric key is substituted for this mapping.

## 3. Proof obligations

### G1 — unique owning A2b arc / A3 span

For one A4 bounded-disk boundary source edge, the existing boundary run publishes the exact `SourceEdgeTopologyKey` and mandatory-edge authority. The accepted `GlobalTopologyPlan` publishes mandatory arcs with:

- `kind == GlobalTopologyArcKind::Mandatory`;
- exactly one `mandatoryEdge` owner;
- exactly one canonical exact source-path piece on the source edge for the bounded producer path.

CB5 filters only those accepted mandatory arcs whose `mandatoryEdge` equals the run's accepted mandatory-edge identity and whose single exact support carrier is the same source edge. Each accepted arc maps to exactly one `ConformitySpanId` through `ConformitySpanId::from_network_arc(arc.id)`.

The bounded source edge may be represented by one whole-edge arc or two accepted contiguous sub-arcs. The accepted source-path endpoints are exact source vertices/edge points; after sorting by exact source-edge parameter, the admissible set must cover `[0,1]` exactly and adjacent sub-arcs must meet exactly. Any empty, overlapping, gapped, multi-piece, or otherwise ambiguous mapping rejects as `InvalidFrontBoundaryAuthority`.

### G2 — exact consecutive breakpoint ordinals

For each accepted span, A3 owns `schedule.count`. CB5 converts only positive bounded exact counts and queries `GlobalConformityBaselinePlan::breakpoint_location(span, j)` and `breakpoint_location(span, j+1)` for every consecutive ordinal pair.

The interval identity is therefore the exact integer pair `(j,j+1)` attached to the exact span. The A4 local target size does not select, round, or renumber those ordinals.

### G3 — exact chart orientation

The bounded boundary run already publishes ordered `sourceVertices` for each source edge. `SourceEdgeTopologyKey` publishes the canonical ordered edge endpoints. Comparing the run's first source vertex with `edge.first()` determines whether the chart copy traverses increasing or decreasing canonical edge parameter.

That orientation determines whether A4 emits `(j,j+1,Forward)` or `(j+1,j,Reverse)`. Opposite chart copies therefore carry the same span and same unordered consecutive ordinal pair with reversed endpoints and opposite orientation.

### G4 — identical shared identity independent of floating geometry

`SurfaceSharedBoundaryInterval` is derived before hard-rail pairing. Pairing groups by:

- source component;
- accepted A2b arc / A3 span identity;
- exact low/high consecutive ordinal values;
- canonical route steps.

The opposite-edge validation additionally requires reversed interval endpoints, opposite orientation, reversed canonical route, and preserved A4-local family/sign compatibility.

The former `support_key` tolerance/rounded-barycentric identity is removed from shared-boundary pairing authority. Floating barycentrics remain only the geometric representation used to place the already-identified accepted breakpoint on the source edge.

### G5 — no forbidden local authority

The shared interval identity does not depend on:

- `defaultTargetSize` or target-size mean;
- locally rounded `gridU/gridV`;
- epsilon endpoint classification;
- `1e12` barycentric quantization;
- synthetic node indices;
- post-hoc matching of chart copies.

When accepted conformity authority is present, the bounded producer sets its boundary subdivision count from the exact accepted A3 interval count. Uniform and periodic producers that cannot publish this A3 hard-rail provenance defer instead of manufacturing a second shared-boundary authority.

## 4. Negative authority checks

CB5 rejects rather than repairs when:

- only one of `GlobalTopologyPlan` / `GlobalConformityBaselinePlan` is supplied;
- baseline `topology_plan_digest()` does not match the topology-plan semantic digest;
- schedule cardinality or source support disagrees with the accepted topology plan;
- a hard-rail edge under an accepted conformity receipt lacks a typed shared interval;
- interval endpoints are not consecutive exact ordinals;
- interval orientation disagrees with ordinal direction;
- opposite edges disagree on span, reversed ordinals, or orientation.

These failures are `InvalidFrontBoundaryAuthority` / `InvalidSharedBoundaryInterval` / `InvalidHardRailPairing` depending on the publication boundary. There is no geometry-based fallback.

## 5. Scope conclusion

All five frozen guard obligations are derivable from accepted products. CB5 is therefore authorized to perform the bounded production cutover described in §4 of the code/build plan.

This record proves only static authority sufficiency. It does **not** claim compile success, runtime success, torus acceptance, CP3 closure, or package promotion. Those remain owned by the mandatory remote compile and later immutable artifact-only TB + Review.
