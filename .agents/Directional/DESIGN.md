# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed high-level gate. Every implementation turn declares:

```text
Active design gate:
Earliest failing fixture/contract:
Missing design contract:
Smallest general implementation change:
Observable material-progress condition:
Explicitly deferred work:
```

Material progress means an active direct fixture passes, a missing first-class contract becomes live and consumed, or a general structural ambiguity is removed. Diagnostics/counters/hashes, equivalent failure movement, aggregate gains, performance changes, fallback/recovery, or fixture-specific behavior are not material progress alone.

## Producer authority model

An authoritative producer returns one of:

```text
NotApplicable
Produced
Rejected
```

- `NotApplicable`: this producer does not represent the source topology yet; another explicitly selected producer may run.
- `Produced`: authoritative cells/fronts are complete and materialize directly one cell to one quad.
- `Rejected`: the producer was applicable but a fail-closed invariant failed; retain the typed reason and stop the backend request. Do not silently launch generic seeds/traces/proposals.

Applicability derives from general source topology, field state, and first-class region authority, never fixture identity or failure recovery.

## Authoritative phase/front representation

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component, topology-region identity, local isolation-sheet provenance, transition edge, ordered route, feature, ownership, periodic state, and any bounded-disk phase state. Fronts advance only through exact source topology and reciprocal field transport.

A source-vertex crossing is an ordered incident-face fan, never a positional jump. Every crossed canonical source edge is recorded and transported through strict reciprocal transition logic. Ambiguous, disconnected, repeated, non-manifold, nonreciprocal, missing-provenance, or branch-mismatched routes fail closed.

An authoritative cell has four ordered source-attached corners/sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, exact topology-region/local-isolation provenance, complete route provenance, and any required periodic quotient identity. One accepted authoritative cell maps directly to one output quad.

Hard-feature barriers remain authoritative constraints. Relief separatrices are guidance until embedded; `reliefBarrierEdges` may stop authoritative transport only when `reliefBarriersEmbedded == true`.

## Source-topology region versus local isolation sheet

This distinction is mandatory.

### Source-topological producer region

A producer region is connected through **exact source-mesh adjacency** and is split only by authority whose semantics require a parent chart boundary: a genuine source boundary, hard feature, different source component, or equivalent explicit source constraint.

Producer applicability, Euler characteristic, genuine boundary-loop classification, annulus/disk topology, exact-once region ownership, and whole-region coverage are determined from this source-topological authority.

A non-hard shared source edge does **not** become an exterior producer boundary merely because its incident faces have different local isolation-sheet labels.

### Local isolation sheet

Local isolation labels are a geometric safety partition. They protect proximity/capture/projection/collision/candidate association from jumping between nearby unrelated surface pieces. The close/opposing-sheet classifier may therefore split one source-topological producer region into several local isolation labels.

Different local labels may communicate only through an **exact shared source edge or ordered source-vertex fan** and valid reciprocal field transport. This does not authorize world-space joining, nearest-point welding, or proximity-based ownership.

A valid non-hard exact-adjacent cross-sheet edge inside one topology region is an **internal isolation seam**, not an exterior chart rail. Crossing it must retain exact transition provenance and both pre/post local-isolation authority.

Embedded relief is first-class **internal cut/transport authority beneath the parent topology region**. It may split explicitly named producer domains when a local producer needs cut domains, but it does not change the parent's source Euler characteristic or genuine boundary-loop count. Once an embedded barrier is consumed by an applicable producer, unsupported domain coverage is `Rejected`; an all-`NotApplicable` child result may not fall through to generic tracing. Non-embedded relief remains guidance in every traversal path, including ordered source-vertex fans.

Hard features remain true producer-domain boundaries and cells may not cross them. Unless a hard rail coincides with a genuine source boundary, the two exact source-adjacent rail sides must be paired through reciprocal source/field/phase authority so the final mesh is conforming across the rail. Genuine source boundaries alone remain exterior. Spatially close but source-disconnected sheets/components remain separate topology regions.

The implementation must preserve both identities. Never overwrite a local isolation label with a topology-region ID or infer a topology-region union from counts, IDs, frequency, discovery order, boundary length, topology score, proximity, or arbitrary subset search.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** passed.
3. **G2 — Cross-chart and close-sheet propagation:** passed; local isolation safety remains mandatory.
4. **G3 — Periodic closure and holonomy:** passed.
5. **G4 — Topology-distinct completion and singularities:** **active**. Exact torus is the earliest topology fixture; prescribed singular sphere follows only after the torus topology slice closes.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Current runtime authority and retained baseline

Artifact **`9022061741`**, implementation `3ca89ab55efff461b050fb12033174be70e7464f`, remains the last candidate that directly produced all accepted plane/seam/close-sheets/cylinder baselines.

Artifact **`9026181778`**, implementation `82151bf51bce9af9859282b2a03e295a0ee5a309`, is the latest exact artifact-only runtime authority. Its static/source/checksum/dependency/fixture/log authority passes, all 33 transition-quotient counterfactuals are independently discoverable, and validation/API remain 60/60 and 8/8. G4 is still blocked, but this artifact makes material progress:

| Fixture | Result, three processes | First invalid authority | Output |
|---|---:|---|---|
| plane | 0/3 | `InvalidAuthoritativeTransitionSourceEdge` | none |
| multi-face seam | **3/3** | none | 81 vertices / 64 pure quads; semantic `99c8be7159d05c2f` |
| close sheets | 0/3 | `InvalidAuthoritativeTransitionSourceEdge` | none |
| cylinder | 0/3 | `InvalidPeriodicCutAuthority` | none |
| torus | 0/3 after phase-front `Produced` | `InvalidPeriodicCutAuthority` | none |

The multi-face result is direct `CompletedSurfaceCells`, complete-lineage, strict-valid, deterministic, and fallback/recovery-free. Torus retains four topology regions, eight internal isolation seams, and four periodic relations but consumes `0/0/0` before output. Sphere remains deferred.

Focused results are transition quotient **24/33**, topology/isolation/hard rail **10/10**, polygonal/curved/mixed **12/12**, periodic/torus/cylinder **5/7**, remaining non-overlap Phase10 **35/39**, and direct G0-G3 GoogleTests **1/4**. Bounded totals are producer **143/161**, completion/simplification **154/164** with the same historical ten, validation **60/60**, and API **8/8**.

The prior genuine-boundary representation is now proven: a one-face source boundary has non-empty canonical `sourceRouteTopology`, no invented interior index, and `edge_matching_indices()` remains interior-only. The reciprocal isolation-certificate positive and broken cases and all semantic-digest counterfactuals also execute and pass.

### Canonical interior transition identity

The latest runtime exposes a second representation defect. `CrossFieldEdgeTransition.sourceEdge` is a full `mesh.EF` row, including boundary edges. `edge_matching_indices(edge_faces(full source faces))` defines the materializer's source-wide compact index over two-face interior edges. `source_edge_provenance()` returns the full `EF` domain when CrossField transitions exist; local producers can also rebuild a different compact numbering from active-region faces. Phase-front segment/front/periodic routes currently store these alternate meanings in the same integer fields, while materialization always interprets them in the source-wide compact domain.

Materializer-facing two-face routes must carry exactly the source-wide compact interior index paired positionally with canonical topology. Region-local renumbering is not authority. Supplied CrossField transition data remains mandatory validation authority for topology, reciprocal incident faces, matching, and effort, but its full-`EF` row may not leak into the compact route. Genuine boundaries remain topology-only. Numeric equality between domains is never authority.

The public retention contract is also exact: temporary ownership needed to reach a deterministic injection point must not promote `retainIntermediateGeometry=false` into returned context. Public context is retained iff requested.

Nonzero periodic `Z4` rotation, shared hard-rail breakpoint scheduling, and a valid positive multi-isolation quotient witness remain explicit later G4 slices.

## G2 isolation invariant

World-space distance, overlap, or nearest projection may not join unrelated sheets. Local isolation identity remains authoritative wherever an operation could otherwise capture or project onto nearby unrelated geometry.

Topology-region continuity does **not** weaken this rule. Crossing a local-isolation boundary requires exact source adjacency plus reciprocal source-field transport; proximity alone can never establish continuity.

## G3 periodic invariant

A periodic source region carries first-class quotient authority:

```text
periodic relation =
  quarter-turn rotation r in Z4
  + integer lattice translation t in Z2
  + ordered canonical source route/cut identity
  + source-topology-region ownership
  + retained local-isolation provenance
```

Required invariants:

- applicability derives from source topology, never fixture identity;
- cut/chart construction does not require global world-space planarity;
- chart duplicates retain authoritative underlying source identity;
- periodic transport is reciprocal, integral, branch-compatible and source-routed;
- invalid periodic state is typed `Rejected` and cannot fall through to generic tracing;
- artificial-cut counterparts pair through exact source/phase/lattice authority, never Euclidean welding;
- the artificial cut is not an exterior output boundary;
- genuine source boundaries remain exterior;
- direct materialization quotients periodic duplicates exactly;
- every retained periodic relation is consumed by hashing, diagnostics, provenance, and materialization;
- one accepted phase-front cell maps directly to one output quad.

Multiple relations may belong to distinct source-topological regions. Relation ownership/basis selection may not use source numeric IDs, discovery order, count/frequency, arbitrary subset search, or proximity.

## Transition-quotient materialization invariant

Integer lattice coordinates validate field/phase transport; they are **not output vertex identity**. Parameter charts can overlap, so equal `(topologyRegion,u,v)` values do not prove that two occurrences are one mesh vertex.

Direct extraction operates on four explicit corner occurrences per authoritative cell. An output vertex is an equivalence class generated only by:

- reciprocal ordinary front-edge ownership;
- exact reciprocal hard-rail ownership across producer domains;
- an explicitly owned periodic relation applied as the full grid automorphism `R^r p + t`, with `r in Z4` and `t in Z2`.

World-space distance, coordinate equality without connectivity, relation order/count, or representative local sheet may not create equivalence. Every pair carries its owning cell side and relation/rail authority so materialization never infers ownership from container order. Genuine source-boundary sides alone remain unpaired exterior sides.

Source-supported side topology and interior transition indices are distinct domains. A genuine one-face boundary carries canonical topology but no interior matching index. Interior routes and actual cross-face transitions must retain their valid matching indices; no sentinel or expanded boundary-inclusive index table is permitted.

Internal local-isolation seams are not required to coincide with or cross every output cell side. Their exact reciprocal transport is retained in first-class canonical seam certificates. The materializer validates a bijection between retained seams and certificates, builds per-region local-sheet connectivity from them, and accepts multi-sheet state only when connected by this authority. Missing, duplicate, malformed, wrong-owner, wrong-sheet, or nonreciprocal certificates fail closed; unconditional consumption remains forbidden.

`SurfacePoint` remains one exact source-face projection chart. When an equivalence class contains several valid charts/local isolation sheets, one deterministic exact point may represent its position only after intrinsic source-support validation; lineage retains the full sorted chart set, local-isolation set, parent topology region, and rail/periodic equivalence provenance.

Output connected components, boundary loops, manifold incidence, and Euler characteristic are computed from the assembled quad complex. They may never be hard-coded or corrected synthetically.

## Field-authoritative correspondence and source geometry

Where source topology admits multiple valid correspondences, source vertex numbering, lexicographic order, candidate count, discovery order/frequency, or proximity are not authority. Enumerate topology-compatible possibilities, propagate reciprocal 4-RoSy family/sign authority, and consume a unique field-authoritative optimum; zero valid candidates or genuine field-equivalent ambiguity fails closed.

Coverage tolerance may determine source-triangle ownership, but emitted geometry is canonical source-simplex geometry. Exact simplex crossings define emitted breakpoints; source vertices use exact one-hot barycentrics; tolerance-only collapsed segments are omitted; genuine overlap remains rejected by strict validation.

## G4 progression

### Multi-relation periodic authority

Multiple compatible periodic relations are first-class and runtime-live. Equivalent/reversed descriptions canonicalize; conflicting or genuinely ambiguous/dependent relation authority fails closed. Every retained relation is consumed, not merely counted.

### Curved bounded-disk producer

The curved producer recognizes a source-topological disk with Euler characteristic 1 and one manifold boundary, propagates reciprocal 4-RoSy branch gauge, and constructs source-attached boundary/chart/front authority. Topology, transport, boundary phase, chart, and front-pairing failures are typed.

The planar bounded and periodic producers remain separate first-class paths. Whole-surface aggregation is exact-once.

### Field-authoritative polygonal boundary phase — runtime-valid

Artifact **`9021175280`** validates the generalized boundary-phase representation **5/5**.

`SurfaceBoundedDiskBoundaryPhase` retains ordered source-attached runs with transported branch/family/sign, exact source provenance, intrinsic lengths, signed reciprocal quarter-turns, cyclic index, boundary authority, polygon/chart state, and deterministic structural hash.

Required behavior:

- per-edge field-alignment threshold remains meaningful and unchanged without independent evidence;
- adjacent field runs require valid reciprocal quarter-turn transitions;
- cyclic field index must close consistently;
- runs are never inserted/deleted/merged/split merely to manufacture a desired side count;
- the established valid four-run rectangle remains an exact fast path;
- legitimate non-rectangular orthogonal/polygonal disks may construct an intrinsic source-authoritative chart;
- polygon/chart closure may not use a synthetic closing edge, Euler correction, Euclidean welding, or post-hoc cell merging;
- partial local cells never become whole-surface authority after a typed rejection.

A natural six-run reflex-corner witness constructs the generalized phase/chart and reaches the deliberately deferred `InvalidBoundedDiskFrontPairing` invariant. This proves the representation itself is real.

### Runtime diagnosis that motivated topology-region decoupling

Exact torus under artifact `9021175280` deterministically rejects at `InvalidBoundedDiskBoundaryTurn` with **zero retained phase/run/polygon/chart state**. This does not satisfy the planned material-progress condition.

Read-only exact-source reconstruction shows the apparent disk is created by local isolation classification: classifier-local disk labels reconnect through non-hard exact source adjacency into an annular hard-feature region. Their shared non-hard classifier seam is internal to source topology, not a physical exterior boundary. Treating it as a bounded-disk rail creates an invalid field turn where that artificial seam meets a true hard-feature rail.

Boundary turn/index/alignment validation must **not** be relaxed to hide this partition error.

### Topology-region / isolation-sheet architecture — runtime-live, quotient consumption blocked

Implementation **`3ca89ab55efff461b050fb12033174be70e7464f`**, exact artifact **`9022061741`**, validates first-class `SurfaceTopologyRegion` authority **9/9**:

- regions are built from exact source adjacency;
- different source components and hard features stop region continuity;
- local-isolation disagreement alone does not;
- region state retains exact source faces, Euler characteristic, genuine boundary-loop count, exact boundary topology, internal isolation-seam topology, local isolation labels, and a structural hash;
- non-hard exact-adjacent cross-sheet seams are internal when they lie in one region;
- reciprocal transport across such seams is required and malformed transport fails typed `InvalidTopologyRegionTransport`;
- producer applicability and exact-once aggregation operate by topology region while local-isolation provenance remains attached to cells/fronts/relations/phases;
- periodic relation identity carries topology-region scope;
- trace-network hashing and runtime diagnostics consume region/seam authority.

Artifact `9026181778` proves the reviewed boundary/certificate representation far enough to restore direct multi-face seam and execute all focused counterfactuals. It does not close the quotient:

1. plane and close sheets serialize full-`EF` transition rows into compact-index routes and fail at `InvalidAuthoritativeTransitionSourceEdge`;
2. cylinder and direct torus fail the same domain mismatch as `InvalidPeriodicCutAuthority`;
3. the winding-cylinder producer rejects nonzero accumulated branch matching before hard-coding periodic rotation zero;
4. exact torus at the Phase10 target size fails exact hard-rail pairing before relation-owner tests can execute;
5. the split-isolation positive fixture does not yet prove a quotient class spanning multiple local sheets;
6. injected failure temporarily forces retention and incorrectly exposes context when the caller requested release.

The sole next implementation slice normalizes the two-face route index and separates operational lifetime from public retention. The other blockers stay explicit and may not be hidden by assertion changes, fabricated lineage, proximity pairing, or fallback.

Diagnostic region counts, hashes, local-sheet counts, torus IDs, relation counts, analytical fixture parameters, and observed boundary lengths are evidence only and are prohibited as production/test ownership keys.

G4 is not passed until required topology and singularity fixtures complete directly with strict-valid pure-quad output and complete provenance.

## G4 prescribed singularity

The prescribed sphere remains deferred until exact torus reaches direct strict-valid production. A downstream sphere completion observation must never preempt the earlier torus producer/topology invariant.

## Current next authority

Latest runtime evidence is recorded in `.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`.

Because artifact `9026181778` restores an active direct fixture and activates missing first-class certificate/counterfactual authority, it is a material-progress turn and the mandatory no-progress Review guard does not activate. Optional review policy remains `never`.

The only authorized next turn is **Code + Build** under `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Plan.md`. It is compile-only and bounded to canonical interior transition indices plus the public retain/release contract. It executes no generated project runtime.

## Non-negotiable prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no Euclidean periodic seam welding;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
