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

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component, topology-region identity, local isolation-sheet identity, transition edge, ordered route, feature, ownership, and periodic state. Fronts advance only through exact source topology and reciprocal field transport.

A source-vertex crossing is an ordered incident-face fan, never a positional jump. Every crossed canonical source edge is recorded and transported through strict reciprocal transition logic. Ambiguous, disconnected, repeated, non-manifold, nonreciprocal, missing-provenance, or branch-mismatched routes fail closed.

An authoritative cell has four ordered source-attached corners/sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, exact topology-region/local-sheet provenance, complete route provenance, and any required periodic quotient identity. One accepted authoritative cell maps directly to one output quad.

Hard-feature barriers remain authoritative constraints. Relief separatrices are guidance until embedded; `reliefBarrierEdges` may stop authoritative transport only when `reliefBarriersEmbedded == true`.

## Source-topology region versus local isolation sheet

This distinction is mandatory.

### Source-topological producer region

A producer region is connected by **exact source-mesh adjacency** and is split only by authority whose semantics require a topological/chart boundary: genuine source boundaries, hard features, embedded hard barriers, or equivalent explicit source constraints.

Producer applicability, Euler characteristic, boundary-loop classification, annulus/disk topology, exact-once region ownership, and whole-region coverage are determined from this source-topological authority.

A non-hard shared source edge does **not** become an exterior producer boundary merely because its incident faces have different local isolation-sheet labels.

### Local isolation sheet

Local sheet labels are a geometric safety partition. They protect proximity/capture/projection/collision/candidate association from jumping between nearby unrelated pieces of surface. The close/opposing-sheet classifier may therefore split one source-topological producer region into several local isolation labels.

Different local labels may communicate only through an **exact shared source edge or source-vertex fan** and valid reciprocal field transport. This does not authorize world-space joining, nearest-point welding, or proximity-based ownership.

A valid non-hard exact-adjacent cross-sheet edge inside one topology region is an **internal isolation seam**, not an exterior chart rail. Crossing it must retain exact transition provenance and both pre/post local-sheet authority.

Hard features and genuine source boundaries remain true topology boundaries. Spatially close but source-disconnected sheets/components remain separate topology regions.

The implementation must preserve both identities. Never overwrite a local sheet label with a topology-region ID or infer a topology-region union from counts, IDs, frequency, discovery order, boundary length, or arbitrary subset search.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** passed.
3. **G2 — Cross-chart and close-sheet propagation:** passed; local isolation safety remains mandatory.
4. **G3 — Periodic closure and holonomy:** passed.
5. **G4 — Topology-distinct completion and singularities:** **active**. Exact torus is the earliest topology fixture; prescribed singular sphere follows only after the torus topology slice closes.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed G0-G3 runtime authority

Current artifact `9021175280` preserves the accepted direct authority:

| Fixture | Producer | Direct output | Hash | Determinism |
|---|---|---|---|---|
| plane | `Produced` | 81 V / 64 strict-valid quads | `730caeae49ec872c` | 3/3 |
| seam | `Produced` | 81 V / 64 strict-valid quads | `5bdf34d7802e9fb0` | 3/3 |
| close sheets | `Produced` | 242 V / 200 strict-valid quads / 2 isolated components | `89b052762f52a5af` | 3/3 |
| cylinder | `Produced` | 320 V / 288 strict-valid quads | `32135be51d7a0a26` | 3/3 |

Cylinder periodic authority remains `r=0`, `t=(32,0)`, route 32, cut 4; validation failures are zero; exactly two genuine annulus exterior loops remain and the artificial cut is not exterior. No passing direct case uses fallback or source-grid recovery.

Retained G0-G3 focused contracts are **17/17**.

## G2 isolation invariant

World-space distance, overlap, or nearest projection may not join unrelated sheets. Local sheet identity remains authoritative wherever an operation could otherwise capture or project onto nearby unrelated geometry.

The new topology-region distinction does **not** weaken this rule. Crossing a local-sheet boundary requires exact source adjacency plus reciprocal source-field transport; proximity alone can never establish continuity.

## G3 periodic invariant

A periodic source region carries first-class quotient authority:

```text
periodic relation =
  quarter-turn rotation r in Z4
  + integer lattice translation t in Z2
  + ordered canonical source route/cut identity
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

## Field-authoritative correspondence

Where source topology admits multiple valid correspondences, source vertex numbering, lexicographic order, candidate count, discovery order/frequency, or proximity are not authority. Enumerate topology-compatible possibilities, propagate reciprocal 4-RoSy family/sign authority, and consume a unique field-authoritative optimum; zero valid candidates or genuine field-equivalent ambiguity fails closed.

Coverage tolerance may determine source-triangle ownership, but emitted geometry is canonical source-simplex geometry. Exact simplex crossings define emitted breakpoints; source vertices use exact one-hot barycentrics; tolerance-only collapsed segments are omitted; genuine overlap remains rejected by strict validation.

## G4 progression

### Multi-relation periodic authority

Multiple compatible periodic relations are first-class and runtime-live. Equivalent/reversed descriptions canonicalize; conflicting or genuinely ambiguous/dependent relation authority fails closed. Every retained relation is consumed, not merely counted.

### Curved bounded-disk producer

The curved producer recognizes a source-topological disk with Euler characteristic 1 and one manifold boundary, propagates reciprocal 4-RoSy branch gauge, and constructs source-attached boundary/chart/front authority. Topology, transport, boundary phase, chart, and front-pairing failures are typed.

The planar bounded and periodic producers remain separate first-class paths. Whole-surface aggregation is exact-once.

### Field-authoritative polygonal boundary phase — runtime-valid on structural witnesses

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

### Current G4 blocker — producer region / isolation-sheet decoupling

Exact torus under artifact `9021175280` deterministically rejects at `InvalidBoundedDiskBoundaryTurn` with **zero retained phase/run/polygon/chart state**. This does not satisfy the planned material-progress condition.

Read-only exact-source reconstruction proves the apparent disk is created by local isolation classification: two classifier-local disk labels reconnect through non-hard exact source adjacency into one annular hard-feature region. Their shared non-hard classifier seam is internal to source topology, not a physical exterior boundary. Treating it as a bounded-disk rail creates the invalid field turn where that artificial seam meets a true hard-feature rail.

Therefore the next implementation must introduce and consume source-topological producer regions independently of local isolation-sheet labels. Boundary turn/index/alignment validation must **not** be relaxed to hide this partition error.

Diagnostic torus vertex IDs, local sheet counts, hard-edge counts, relation counts, analytical fixture parameters and observed boundary lengths are evidence only and are prohibited as production/test ownership keys.

G4 is not passed until required topology and singularity fixtures complete directly with strict-valid pure-quad output and complete provenance.

## G4 prescribed singularity

The prescribed sphere remains deferred until the exact torus topology slice reaches direct strict-valid production. A downstream sphere completion observation must never preempt the earlier torus producer/topology invariant.

## Current next authority

Execute `.agents/Directional/Gate_4_Source_Topology_Region_Isolation_Sheet_Decoupling_Code_Build_Plan.md` as **Code + Build only**.

Current no-progress Code + Build count is **1**. If the next Code + Build's following artifact-only validation also fails to demonstrate material progress, mandatory design review or bounded producer-replacement proof is required before another ordinary implementation turn.

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