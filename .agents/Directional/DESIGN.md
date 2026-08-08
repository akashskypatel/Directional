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

Artifact **`9022061741`**, implementation `3ca89ab55efff461b050fb12033174be70e7464f`, remains the last candidate that directly produced the accepted plane/seam/close-sheets/cylinder outputs. It validates topology-region/isolation authority **9/9**, but did not close G4 and retained only **16/17** G0-G3 contracts.

Artifact **`9024549134`**, implementation `7f486632b154a303789df6c4dd44f602c8c71281`, is now the latest exact artifact-only runtime observation. Its immutable authority passes, but its product state is **regressed and blocked**:

| Fixture | Artifact `9024549134` result, 3/3 | First invalid authority | Output |
|---|---|---|---|
| plane | deterministic failure | `InvalidFrontBoundaryAuthority` | none |
| seam | deterministic failure | `InvalidFrontBoundaryAuthority` | none |
| close sheets | deterministic failure | `InvalidFrontBoundaryAuthority` | none |
| cylinder | deterministic failure | `InvalidFrontBoundaryAuthority` | none |
| torus | phase-front `Produced`, then deterministic failure | `UnconsumedAuthoritativeIsolationSeam` | none |

The accepted older raw hashes remain same-artifact baseline evidence only. Artifact `9024549134` emits no candidate raw or semantic hash because all direct fixtures fail before output.

The semantic-digest permutation/mutation tests exist only in `tests/MilestoneGP27Tests.cpp`, under disabled `DIRECTIONAL_BUILD_HISTORICAL_TESTS`; they are absent from the five packaged executables. The digest contract therefore remains unvalidated despite source and compile presence.

The common boundary regression is representational: `edge_matching_indices()` maps only two-face interior source edges, but `assign_open_front_boundary_authority()` requires that index before classifying a one-face edge as `GenuineSourceBoundary`. Canonical source topology identity and optional interior transition index must be separated.

Mandatory independent Review is complete with decision **Approved with amendments**. A genuine one-face source boundary is represented by non-empty canonical `sourceRouteTopology` and an empty interior-index route. `edge_matching_indices()` remains interior-only; actual two-face ordinary, hard-rail, embedded-relief, and periodic transport retains strict index provenance.

The Review also rejects the current requirement that every internal isolation seam occur in a cell-side `transitionSourceEdges` route. Each retained seam instead requires one canonical producer-issued certificate of exact source adjacency, owning component/topology region, incident local sheets, interior edge identity, and reciprocal field transport. Materialization consumes these certificates as the region's local-sheet connectivity authority across cells, fronts, relations, quotient classes, lineage, hashing, and diagnostics. Certificate presence alone is insufficient.

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

Under artifact `9022061741`, exact torus has four annular topology regions, eight internal isolation seams, local-isolation cardinalities `[1,1,2,1]`, and four periodic relations. Phase-front authority reaches `Produced` and the former `InvalidBoundedDiskBoundaryTurn` no longer occurs; materialization then fails at `InvalidAuthoritativePhaseFrontCell`.

In runtime artifact `9022061741`, the materializer had not adopted the same authority model: multi-isolation region cells normalized to `sourceSheet=-1`, while `build_authoritative_phase_front_mesh()` rejected negative `sourceSheet` and keyed lattice/periodic materialization by `(component, sheet, lattice)`. Independent review rejected a simple replacement with `(component, topologyRegion, lattice)` because charts can overlap.

Artifact `9024549134` executes the explicit occurrence quotient far enough for torus phase-front `Produced`, then stops at **`tracing/phase-front-materialization / UnconsumedAuthoritativeIsolationSeam`**. It retains the same four regions/eight seams/four relations but records consumed regions/seams/relations `0/0/0`.

The materializer currently defines seam consumption only through `SurfaceTraceSegment.transitionSourceEdges` on cell boundary paths and requires every `internalIsolationSeamTopology` entry to appear. Mandatory Review determines that this observes the wrong event: a local-isolation seam is chart-transport authority and need not intersect an output side. The reviewed successor adds one reciprocal seam-transport certificate per retained seam and consumes it as the exact local-sheet connectivity graph. It does not remove seam validation or mark metadata consumed unconditionally.

Current runtime acceptance under artifact `9024549134` remains blocked by:

1. genuine source boundaries are rejected because topology identity is incorrectly coupled to an interior matching index;
2. internal-isolation-seam consumption ownership remains unresolved and torus consumes zero quotient authority;
3. broad retained producer authority regresses before relief, rail, polygonal, curved, mixed, and periodic contracts can execute;
4. semantic-digest tests and several quotient/retention counterfactuals are absent from default packaged executables.

The sole authorized correction is `.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Code_Build_Plan.md`. It preserves the explicit occurrence quotient and adds default executable counterfactual closure without enabling the broad historical suite.

The exact torus fixture and retention expectation remain valid. Artifact `9024549134` positively retains trace context when requested, but no independently packaged `retainIntermediateGeometry=false` counterpart proves the required if-and-only-if contract.

Diagnostic region counts, hashes, local-sheet counts, torus IDs, relation counts, analytical fixture parameters, and observed boundary lengths are evidence only and are prohibited as production/test ownership keys.

G4 is not passed until required topology and singularity fixtures complete directly with strict-valid pure-quad output and complete provenance.

## G4 prescribed singularity

The prescribed sphere remains deferred until exact torus reaches direct strict-valid production. A downstream sphere completion observation must never preempt the earlier torus producer/topology invariant.

## Current next authority

Artifact-only runtime evidence is recorded in `.agents/Directional/Gate_4_Transition_Quotient_Materialization_And_Retained_Authority_Artifact_Only_Test_Benchmark_Report.md`.

Mandatory Review is complete under `.agents/Directional/Gate_4_Transition_Quotient_Runtime_Regression_Independent_Design_Review_Report.md` with decision **Approved with amendments**.

The only authorized next turn is **Code + Build** under `.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Code_Build_Plan.md`. It is compile-only and bounded to the reviewed production/test/CMake allowlist. The following turn must validate one immutable artifact without rebuilding.

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
