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
4. **G3 — Periodic closure and holonomy:** **active; periodic topology, source-strip conformity, and quotient authority are runtime-proven; adjacent-ring field correspondence remains ambiguous.**
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed-gate runtime authority

Artifact `9004509871`, source `2783ea718ffb15f8fb3868795173472ab8636c1c`, preserves the direct passed gates:

| Fixture | Result | Producer | Traces | Quads | Validation | Output hash |
|---|---:|---|---:|---:|---:|---|
| plane | **pass** | `Produced` | 352 | 64 | 0 | `730caeae49ec872c` |
| seam | **pass** | `Produced` | 256 | 64 | 0 | `5bdf34d7802e9fb0` |
| close sheets | **pass** | `Produced` | 1,104 | 200 | 0 | `89b052762f52a5af` |

All three are direct `CompletedSurfaceCells` pure-quad outputs, deterministic 3/3, with no fallback/recovery. The close-sheet output remains two isolated source-authoritative components.

## G2 source-sheet contract — retained invariant

The authoritative producer partitions state by `(source component, local sheet)` before front construction. World-space distance, nearest projection, or overlap may not join unrelated sheets. Phase, ownership, route, capture, collision, boundary loops, and materialization identity remain sheet-local unless exact source topology establishes a connection.

## G3 periodic contract — runtime consumed

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
- periodic transport is reciprocal, integral, branch-compatible, and source-routed;
- invalid periodic state is typed `Rejected` and cannot fall through to generic tracing;
- artificial-cut front counterparts pair through exact source/phase/lattice authority, never Euclidean welding;
- the artificial cut is not an exterior output boundary;
- the two genuine annulus boundaries remain exterior;
- direct materialization quotients periodic duplicates exactly and preserves one accepted cell → one quad;
- source-face row ordering may change incidental DCEL numbering but not canonical source-route/cut identity or holonomy semantics;
- every canonical source-ring strip boundary is a mandatory intrinsic periodic lattice breakpoint.

Artifact `9004509871` proves these bounded contracts are consumed on the exact cylinder:

- disposition `Produced`;
- holonomy `r=0`, `t=(32,0)`, ordered route 32 edges, cut four edges;
- 2,237 source-attached traces;
- zero generic arrangement cells;
- 320 direct completed quads;
- 352 provenance vertices;
- source-strip breakpoint and canonical row-order contracts pass;
- no fallback/recovery;
- deterministic 3/3.

## Active G3 failure authority

The cylinder remains red at `completion/output-validation:AggregateCompletionValidationFailure`. Non-invasive inspection of the exact packaged runtime's in-memory `SurfaceFinalValidationReport` identifies three failed scalar thresholds:

- `normalP95Degrees = 16.6272734366` > `15.0`;
- `fieldP95Degrees = 37.9670987281` > `15.0`;
- `warpageP95Degrees = 30.6213792811` > `30.0`.

All represented discrete strict/source-authoritative topology, boundary, provenance, component/sheet, manifold, inversion, self-intersection, convexity, valence, Euler, feature-rail, and boundary-cycle checks pass. Validators are unchanged.

The source-strip correction is retained: it improves source-to-output P95 approximately `0.104464 -> 0.008174` and quad-to-source P95 approximately `0.068328 -> 0.031281`. It does not solve cross-field alignment; field P95 remains exactly `37.9670987281°`.

## Active G3 ring-correspondence contract

A triangulated annulus strip can admit more than one source-topologically valid bijection between adjacent canonical rings. On the exact cylinder each ring pair permits both:

- a same-column axial correspondence aligned with the intended cross-field family; and
- a diagonal/sheared correspondence through the strip triangulation.

Current source enumerates topology-compatible candidates, sorts their source-vertex sequences lexicographically, and chooses `valid.front()`. That incidental source-ID ordering is not authoritative topology or field semantics. On the committed cylinder it selects the diagonal correspondence. The selected inter-ring source edge is exactly `37.9670987281°` away from the axial cross-field family, matching the failed field P95.

The next design invariant is therefore:

> Adjacent canonical annulus-ring correspondence must be selected from reciprocal transported cross-field family/sign authority over the complete ring, not source vertex ID, lexicographic order, count, frequency, or Euclidean proximity. Exactly one field-authoritative correspondence may be consumed. Zero or genuinely multiple field-equivalent candidates fail closed with typed periodic authority.

Implementation must preserve:

- topology-derived annulus applicability;
- deterministic true boundaries and cut;
- first-class holonomy and ordered route;
- canonical source-strip breakpoints and per-strip target subdivisions;
- exact periodic quotient and artificial-cut ownership;
- source provenance;
- one accepted cell → one output quad.

Do not normalize or choose a candidate solely because it minimizes a world-space angle without reciprocal cross-field transport semantics. Do not use source ID/count/order/frequency as ownership authority.

## Next implementation authority

Execute `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Code_Build_Plan.md` as Code + Build only.

G3 closes only when artifact validation proves the exact cylinder is direct deterministic strict-valid `Produced` `CompletedSurfaceCells` pure-quad output with zero validation failures, field P95 <= 15°, normal P95 <= 15°, warpage P95 <= 30°, correct periodic quotient/provenance, no false exterior cut seam, no fallback/recovery, and plane/seam/close sheets green. Then advance to G4.

Do not broaden G3 into torus/general genus, singularity topology, adaptive 2:1 transitions, hard-feature expansion, bunny/vase production, or performance hardening.

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