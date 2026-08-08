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

Applicability derives from general topology/field state before authoritative metadata execution, never fixture identity or failure recovery.

## Authoritative phase/front representation

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, ordered route, feature, ownership, and periodic state. Fronts advance only through exact source topology and reciprocal field transport.

A source-vertex crossing is an ordered incident-face fan, never a positional jump. Every crossed canonical source edge is recorded and transported through strict reciprocal transition logic. Ambiguous, disconnected, repeated, non-manifold, nonreciprocal, missing-provenance, or branch-mismatched routes fail closed.

An authoritative cell has four ordered source-attached corners/sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, exact component/sheet ownership, complete route provenance, and any required periodic quotient identity. One accepted cell maps to one quad.

Hard-feature barriers remain authoritative constraints. Relief separatrices are guidance until embedded; `reliefBarrierEdges` may stop authoritative transport only when `reliefBarriersEmbedded == true`.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** passed.
3. **G2 — Cross-chart and close-sheet propagation:** passed.
4. **G3 — Periodic closure and holonomy:** production runtime closure contract **satisfied**; formal gate status remains active until corrected field-correspondence witness is artifact-validated with the full retained set.
5. **G4 — Topology-distinct completion and singularities:** blocked until formal G3 closure.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed G0-G2 runtime authority

Current executed G3 artifact `9010838200` preserves:

| Fixture | Producer | Direct output | Determinism |
|---|---|---|---|
| plane | `Produced` | 81 V / 64 strict-valid quads, hash `730caeae49ec872c` | 3/3 |
| seam | `Produced` | 81 V / 64 strict-valid quads, hash `5bdf34d7802e9fb0` | 3/3 |
| close sheets | `Produced` | 242 V / 200 strict-valid quads / 2 isolated components, hash `89b052762f52a5af` | 3/3 |

No passing case uses fallback or source-grid recovery.

## G2 source-sheet invariant

Authoritative state is partitioned by `(source component, local sheet)` before front construction. World-space distance, nearest projection, or overlap may not join unrelated sheets. Phase, ownership, route, capture, collision, boundary loops, and materialization identity remain sheet-local unless exact source topology establishes a connection.

## G3 periodic invariant

A connected singularity-free annulus has first-class periodic authority:

```text
periodic holonomy =
  quarter-turn rotation r in Z4
  + integer lattice translation t in Z2
  + ordered canonical source route
```

Required invariants:

- applicability derives from source topology, never fixture identity;
- one deterministic intrinsic source cut joins the two genuine annulus boundaries;
- cut-open chart construction does not require global world-space planarity;
- chart duplicates retain authoritative underlying source identity;
- periodic transport is reciprocal, integral, branch-compatible and source-routed;
- invalid periodic state is typed `Rejected` and cannot fall through to generic tracing;
- artificial-cut counterparts pair through exact source/phase/lattice authority, never Euclidean welding;
- the artificial cut is not an exterior output boundary;
- the two genuine annulus boundaries remain exterior;
- direct materialization quotients periodic duplicates exactly;
- every canonical source-ring strip boundary is an intrinsic periodic lattice breakpoint;
- one accepted phase-front cell maps directly to one output quad.

## Field-authoritative adjacent-ring correspondence

A triangulated annulus strip may admit multiple source-topologically valid bijections between adjacent canonical rings. Source vertex numbering, lexicographic order, candidate count, discovery order/frequency, or proximity are not authority.

Required contract:

> Enumerate topology-compatible correspondences, propagate reciprocal 4-RoSy family/sign authority across the complete source strip, and consume exactly one field-authoritative optimum. Zero valid field candidates or genuinely field-equivalent best candidates fail closed with typed periodic authority.

The production implementation at `0279946920dfca6e9ac44b7ea31b38e929d1f5fc` satisfies this contract at runtime. The obsolete diagonal candidate is approximately `37.9671°` from the axial field and must not be restored.

## Canonical periodic chart geometry

Coverage tolerance may determine source-triangle ownership, but emitted geometry must be exact canonical source-simplex geometry. Exact simplex crossings define emitted breakpoints; barycentrics near exact boundaries are canonicalized/renormalized; source vertices use exact one-hot barycentrics; tolerance-only collapsed segments are omitted; genuine overlap remains rejected by the unchanged strict validator.

Artifact `9010838200` proves this correction restores the valid periodic cylinder and satisfies the production G3 closure contract:

- cylinder `Produced / CompletedSurfaceCells`;
- holonomy `r=0`, `t=(32,0)`, route 32, cut 4;
- 288 pure output quads / 320 output vertices;
- zero completed/strict validation failures;
- field P95 approximately `8.54e-7°`;
- exactly two true annulus exterior boundary loops;
- artificial cut not exterior;
- no fallback/recovery;
- deterministic output hash `32135be51d7a0a26` 3/3.

## Test-witness invariant for field correspondence

A semantic field-authority regression test must not depend on one particular target subdivision. The cylinder source inter-ring spacing is 0.5 while the active test target is 0.25; therefore each source inter-ring connection is legitimately subdivided into multiple V-family phase-front edges.

Required test contract:

> Observe nonzero source-attached V-family phase-front boundary-path segments, reconstruct their source geometry from authoritative `(face, barycentric)` provenance, verify finite normalized source-simplex endpoints, discard only genuine zero-length segments, and require each observed segment to align with the local authoritative V field family. The witness must remain nonempty and subdivision-independent.

Evidence commit `117620ec2da2083ce11b205835e58fa404f163ef` implements only this test correction. Production blobs remain byte-identical to the runtime-proven G3 source.

Compile-only authority:

- artifact `9013161456`, SHA-256 `fbbdac0d85f8e9bd90dd44267c3f71d0932627e25014910077ad1fe659782c62`;
- run/job `31228899303 / 93028533210`;
- 44/44 recursive checksums;
- 111/111 compile/link actions;
- `runtimeExecution=false`.

## Next authority

Execute `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9013161456`.

Formal G3 closure requires **17/17 focused/retained contracts**, retained direct strict-valid cylinder production closure, and G0-G2 green. If satisfied, mark G3 passed and activate G4 topology-distinct completion and singularities.

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
