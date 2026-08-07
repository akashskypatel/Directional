# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed design gate. Every implementation turn declares the active gate, earliest failing fixture, missing contract, smallest general change, observable material-progress condition, and explicitly deferred work.

## Producer authority model

An authoritative producer returns one of three semantically distinct outcomes:

```text
NotApplicable
Produced
Rejected
```

- `NotApplicable`: this producer does not represent the source topology yet; another explicitly selected producer may run.
- `Produced`: authoritative cells/fronts are complete and materialize directly one cell to one quad.
- `Rejected`: the producer was applicable but a fail-closed invariant failed; retain the typed reason and stop this backend request. Do not silently launch generic seeds/traces/proposals.

Applicability is decided from general topology/field state before authoritative metadata execution, never from fixture identity or from whether a producer happened to fail.

## Authoritative phase/front representation

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, ordered route, feature, ownership, and periodic state. Fronts advance only through exact source topology and reciprocal field transport.

A source-vertex crossing is an ordered incident-face fan, never a positional jump. Every crossed canonical source edge is recorded and transported through strict reciprocal transition logic. Ambiguous, disconnected, repeated, non-manifold, nonreciprocal, missing-provenance, or branch-mismatched routes fail closed.

Hard-feature barriers remain authoritative constraints. Relief separatrices are guidance until embedded; `reliefBarrierEdges` may stop authoritative transport only when `reliefBarriersEmbedded == true`.

An authoritative cell has four ordered source-attached corners/sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, exact component/sheet ownership, complete route provenance, and any required periodic quotient identity. One accepted cell maps to one quad.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** **passed.**
3. **G2 — Cross-chart and close-sheet propagation:** **passed.**
4. **G3 — Periodic closure and holonomy:** **active; field-authoritative ring correspondence is retained, but exact periodic chart endpoint representation regresses at `InvalidPeriodicChart` cell 29.**
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed-gate runtime authority

Artifact `9008118764`, source `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a`, preserves the direct passed gates:

| Fixture | Result | Producer | Traces | Quads | Output hash |
|---|---:|---|---:|---:|---|
| plane | **pass** | `Produced` | 352 | 64 | `730caeae49ec872c` |
| seam | **pass** | `Produced` | 256 | 64 | `5bdf34d7802e9fb0` |
| close sheets | **pass** | `Produced` | 1,104 | 200 | `89b052762f52a5af` |

All three are direct `CompletedSurfaceCells` pure-quad outputs, deterministic 3/3, with no fallback/recovery. The close-sheet output remains two isolated source-authoritative components.

## G2 source-sheet contract — retained invariant

The authoritative producer partitions state by `(source component, local sheet)` before front construction. World-space distance, nearest projection, or overlap may not join unrelated sheets. Phase, ownership, route, capture, collision, boundary loops, and materialization identity remain sheet-local unless exact source topology establishes a connection.

## G3 periodic contract — retained invariant

A connected singularity-free annulus has first-class periodic authority:

```text
periodic holonomy =
  quarter-turn rotation r in Z4
  + integer lattice translation t in Z2
  + ordered canonical source route
```

Required invariants:

- applicability derives from source topology, never fixture identity;
- one deterministic intrinsic source cut joins the two true annulus boundaries;
- the cut-open chart does not require global world-space planarity;
- chart duplicates retain authoritative underlying source identity;
- periodic transport is reciprocal, integral, branch-compatible and source-routed;
- invalid periodic state is typed `Rejected` and cannot fall through to generic tracing;
- artificial-cut front counterparts pair through exact source/phase/lattice authority, never Euclidean welding;
- the artificial cut is not an exterior output boundary;
- the two genuine annulus boundaries remain exterior;
- direct materialization quotients periodic duplicates exactly and preserves one accepted cell → one quad;
- source-face row ordering may change incidental DCEL numbering but not canonical source-route/cut identity or holonomy semantics;
- every canonical source-ring strip boundary is a mandatory intrinsic periodic lattice breakpoint.

Earlier artifact `9004509871` proved periodic `Produced`, source-strip authority and deterministic route/cut/holonomy on the exact cylinder. The latest artifact regresses earlier during chart construction; those design invariants remain required rather than being discarded.

## Field-authoritative adjacent-ring correspondence contract

A triangulated annulus strip can admit more than one source-topologically valid one-to-one bijection between adjacent canonical rings. Source vertex numbering, lexicographic order, candidate count or discovery frequency are not authority for choosing one.

The required contract is:

> Adjacent canonical annulus-ring correspondence is resolved from reciprocal transported cross-field family/sign authority over the complete source strip. Exactly one field-authoritative topology-compatible candidate may be consumed. Zero valid field candidates or genuinely field-equivalent best candidates fail closed with typed periodic authority.

The implementation must preserve source-topology compatibility first, then field authority:

1. enumerate only source-topologically compatible ring bijections;
2. propagate branch/family state across the candidate strip through reciprocal source-edge transition authority;
3. require forward/reverse branch consistency;
4. evaluate inter-ring connections against one transported cross-field family and circumferential source-ring connections against its orthogonal family;
5. select only a unique field-authoritative optimum;
6. never resolve ambiguity by source ID, lexicographic sequence, count, frequency, fixture identity, arbitrary subset search or proximity;
7. typed-reject no valid correspondence as `InvalidPeriodicRingCorrespondence`;
8. typed-reject genuinely field-equivalent best correspondences as `AmbiguousPeriodicRingCorrespondence`;
9. retain the annulus cut, holonomy, source-strip breakpoints/subdivisions, periodic quotient, provenance and one accepted cell → one quad.

Source `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a` implements this contract. Artifact-only execution confirms the deliberately field-equivalent ambiguity test still typed-rejects. Independent immutable-fixture reconstruction confirms the intended same-column cylinder correspondence is axial while the former diagonal candidate is `37.9670987281°` from the axial field; the old lexicographic candidate must not be restored.

## Periodic chart clipping / emitted-geometry contract

Tolerance used to decide chart-triangle **coverage** is not itself geometric source authority.

For every emitted periodic chart segment:

1. coverage/intersection classification may use a bounded numerical tolerance;
2. any interval endpoint mathematically lying on a source simplex vertex or edge must be canonicalized to that exact simplex boundary before it becomes emitted source geometry;
3. accepted barycentrics must be renormalized coherently and materially out-of-simplex values must reject;
4. consecutive intervals that share one mathematical chart breakpoint must consume one exact canonical source point;
5. tolerance-only zero-length segments must not be emitted;
6. merging same-face consecutive segments must preserve canonical endpoint identity;
7. strict boundary/self-intersection validation remains authoritative and must continue to reject real overlap beyond shared endpoints;
8. validator tolerance may not be broadened merely to hide producer-emitted tolerance tails.

This contract follows from the source-authoritative representation itself: numerical ownership tolerance may determine *which* source triangle represents an interval, but cannot perturb the represented source point away from the exact topology it claims.

## Current G3 endpoint checkpoint

Artifact `9008118764` deterministically returns `Rejected/InvalidPeriodicChart` at cell 29 before traces. Six nominal G3 periodic contracts regress at the same stage; G0-G2 and typed ambiguity rejection remain green.

Independent reconstruction of the immutable packaged cylinder chart reproduces first failure at cell 29/source face 30. Two adjacent sides that mathematically share a source vertex contain tolerance-expanded barycentric tails of order `1e-10`; the unchanged strict shared-endpoint/self-intersection predicate therefore rejects the emitted geometry consistently.

This is a producer representation defect, not a reason to weaken `validate_closed_boundary_paths()` or `segments_intersect_beyond_shared_endpoint_2d()`.

## Next authority

Execute `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Code_Build_Plan.md` as **Code + Build only**.

The smallest general change is to canonicalize/renormalize `periodic_chart_segment()` endpoints onto exact source-simplex boundaries, preserve exact shared breakpoint identity, and drop tolerance-only zero-length segments while retaining field-authoritative ring correspondence and strict validation.

Material progress in the following artifact-only turn requires the six nominal G3 regressions to return to their expected path, the field-authoritative correspondence assertion to execute/pass, exact cylinder to advance beyond cell 29 without losing periodic authority, and G0-G2 to remain green. G3 closes only when the exact cylinder ultimately becomes direct deterministic strict-valid periodic `Produced` `CompletedSurfaceCells` pure-quad output with zero validation failures and existing quality limits satisfied.

Do not broaden G3 into completed-output quality tuning before phase-front authority is restored, torus/general genus, singularity topology, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production, or performance hardening.

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
