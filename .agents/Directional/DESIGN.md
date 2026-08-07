# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed high-level gate. Every implementation turn declares:

```text
Active design gate:
Earliest failing fixture:
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
4. **G3 — Periodic closure and holonomy:** **production runtime closure contract satisfied; formal closure pending one field-correspondence test-witness correction.**
5. **G4 — Topology-distinct completion and singularities:** blocked until formal G3 closure.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed-gate runtime authority

Artifact `9010838200`, source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc`, preserves G0-G2 and satisfies the production G3 cylinder contract:

| Fixture | Producer | Direct output | Validation | Determinism |
|---|---|---|---:|---|
| plane | `Produced` | 81 V / 64 Q, hash `730caeae49ec872c` | 0 | 3/3 |
| seam | `Produced` | 81 V / 64 Q, hash `5bdf34d7802e9fb0` | 0 | 3/3 |
| close sheets | `Produced` | 242 V / 200 Q / 2 isolated components, hash `89b052762f52a5af` | 0 | 3/3 |
| cylinder | `Produced` | 320 V / 288 Q, hash `32135be51d7a0a26` | 0 | 3/3 |

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

Required production contract:

> Enumerate topology-compatible correspondences, propagate reciprocal 4-RoSy family/sign authority across the complete source strip, and consume exactly one field-authoritative optimum. Zero valid field candidates or genuinely field-equivalent best candidates fail closed with typed periodic authority.

Current production preserves typed `InvalidPeriodicRingCorrespondence` and `AmbiguousPeriodicRingCorrespondence`. The obsolete diagonal candidate must not be restored: its inter-ring direction is `37.9670987281°` from the cylinder's axial family and produced the earlier field-P95 failure.

## Canonical periodic chart geometry

Coverage tolerance and emitted geometry are separate authorities:

> Coverage tolerance may determine which source chart triangle owns an interval, but emitted periodic-chart geometry must be canonical source-simplex geometry. Breakpoints come from exact simplex crossings; barycentrics near exact simplex boundaries are canonicalized/renormalized; consecutive sides preserve exact shared source breakpoints; tolerance-only zero-length segments are not emitted. Real overlap remains rejected by the unchanged strict validator.

Source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc` implements this contract. Artifact `9010838200` runtime-proves both endpoint-canonicalization tests, restores the six nominal G3 periodic contracts that had regressed at `InvalidPeriodicChart`, and advances the exact cylinder to direct strict-valid periodic output.

## Exact G3 production runtime closure evidence

Artifact `9010838200` exact cylinder:

- producer disposition `Produced`;
- direct output origin `CompletedSurfaceCells`;
- periodic holonomy `r=0`, `t=(32,0)`, ordered route 32 edges, cut 4 edges;
- 1,728 trace segments;
- 290 arrangement / 290 simplified cells;
- 288 completed/output quads;
- 320 provenance/output vertices;
- zero non-quads;
- validation failures `0`;
- field P95 `8.537736463e-07°`;
- surface approximation P95 `2.832791574e-16`;
- zero nonmanifold edges, T-junctions, duplicate faces, self-intersections and degenerate output faces;
- topology and boundary preserved;
- output structural hash `32135be51d7a0a26`, deterministic 3/3;
- no fallback/recovery.

The benchmark JSON does not serialize raw normal/warpage P95 values, but `surfaceCellValidationFailures=0` is authoritative because production validation failure counting includes normal P95 <=15°, field P95 <=15°, warpage P95 <=30°, and the other strict thresholds. Independent serialized-geometry checks report zero warpage and approximately `8.54e-7°` nearest-source normal error.

Output topology has exactly 64 boundary edges in two 32-edge degree-2 loops, one at z=-1 and one at z=+1. Therefore only the two genuine annulus boundaries are exterior; the artificial periodic cut is not.

This is material runtime progress from artifact `9008118764`, which rejected at `InvalidPeriodicChart` cell 29 before traces. The G3 no-progress counter resets to zero.

## Formal G3 closure blocker — test witness, not production

Focused/retained raw result is **16/17**. The sole failure is:

`SurfaceCellsPhase10.PeriodicPhaseFrontUsesFieldAuthoritativeAdjacentRingCorrespondence`

Production reaches `Produced`; only `exactInterRingEdges > 0` fails. That witness is structurally invalid for the test's own setup:

- source inter-ring spacing is 0.5;
- target size is 0.25;
- the authoritative V lattice therefore subdivides every source inter-ring edge into two front edges;
- no single V front edge can span two distinct exact source-ring vertices.

The fixture remains valid and must not be replaced merely to make the test pass. Formal closure requires a subdivision-invariant test of the same field-authority contract: inspect nonzero source-attached V-family boundary-path segments, reconstruct their source-space direction from face+barycentric provenance, compare against the local authoritative V family, and require a nonempty observation set. This strengthens the intended behavior rather than weakening it.

## Next authority

Execute `.agents/Directional/Gate_3_Field_Correspondence_Test_Witness_Code_Build_Plan.md` as Code + Build only.

Expected production source change: none. Correct only the invalid test witness; preserve endpoint canonicalization, typed ambiguity rejection, annulus/cut/holonomy/quotient/source-strip authority, G0-G2, validators, and no fallback/recovery. Compile/package the seven approved targets without executing generated project binaries.

The following artifact-only turn must produce 17/17 focused/retained contracts and retain the exact cylinder direct strict-valid periodic output. On that result, formally mark G3 passed and activate G4.

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
