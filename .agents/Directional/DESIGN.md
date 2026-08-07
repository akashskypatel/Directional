# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed design gate. Every implementation turn declares the active gate, earliest failing fixture, missing contract, smallest general change, observable material-progress condition, and explicitly deferred work.

## Producer authority model

The current mixed `phaseFront.succeeded`/generic fall-through model is being replaced at a bounded boundary. An authoritative producer must return one of three semantically distinct outcomes:

```text
NotApplicable
Produced
Rejected
```

- `NotApplicable`: this producer does not represent the source topology yet; another explicitly selected producer may run.
- `Produced`: authoritative cells/fronts are complete and materialize directly one cell to one quad.
- `Rejected`: the producer was applicable but a fail-closed invariant failed; retain the typed reason and stop this backend request. Do not silently launch generic seeds/traces/proposals.

Applicability is decided from general topology/field state before execution, never from fixture identity or from whether a producer happened to fail.

## Authoritative phase/front representation

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, ordered route, feature, and ownership state. Fronts advance only through exact source topology and reciprocal field transport.

A source-vertex crossing is an ordered incident-face fan, never a positional jump. Every crossed canonical source edge is recorded and transported through strict reciprocal transition logic. Ambiguous, disconnected, repeated, non-manifold, nonreciprocal, missing-provenance, or branch-mismatched routes fail closed.

Hard-feature barriers remain authoritative constraints. Relief separatrices are guidance until embedded; `reliefBarrierEdges` may stop authoritative transport only when `reliefBarriersEmbedded == true`, matching the tracing-option contract.

An authoritative cell has four ordered source-attached corners/sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, exact component/sheet ownership, and complete route provenance. One accepted cell maps to one quad.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** **active; bounded producer replacement proof selected.**
3. **G2 — Cross-chart and close-sheet propagation:** seam sub-contract proven; blocked by G1 and close-sheet failure.
4. **G3 — Periodic closure and holonomy:** blocked.
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Runtime authority

| Fixture | Result | Traces | Arrangement | Output quads |
|---|---:|---:|---:|---:|
| plane | fail | 106 | 9 | 0 |
| seam | **pass** | 256 | 65 | 64 |
| close sheets | fail | 158 | 0 | 0 |
| cylinder | fail | 732 | 0 | 0 |
| bunny | fail | 80,862 | 0 | 0 |
| vase | fail | 116,922 | 0 | 0 |

Direct acceptance is 1/6. The seam remains direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, no fallback/recovery, hash `a8972efd7c4900a4`.

The plane has remained at 106 traces / 9 arrangement cells / 12 completion candidates across two bounded implementation attempts. Contract tests passed but did not materially advance the exact production route.

## Review conclusion

The successful Gate 1 parent already contained the generic producer, but the plane never reached it because direct phase-front construction succeeded. Gate 2 made phase-front construction transition-aware; once it rejected the production plane, `build_surface_cell_network()` silently substituted the generic producer. Later completion diagnostics then overwrote the typed phase-front rejection.

This is the controlling architecture defect: `NotApplicable` and `Rejected` are currently collapsed into one Boolean non-success state.

The exact production plane also consumes preprocessing state absent from the synthetic fan tests, including finalized matching/transitions, adaptive target size, source labels, and feature/relief state. A proven semantic inconsistency additionally exists where phase-front transport treats relief edges as hard barriers even when `reliefBarriersEmbedded == false`.

## Next implementation authority

Use `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Code_Build_Plan.md`.

Minimum architectural progress in the following artifact is removal of the silent 106/9/12 generic substitution after authoritative rejection. Gate 1 itself still requires direct valid plane output while preserving seam direct success.

## Non-negotiable prohibitions

- no validator weakening;
- no count/order/frequency ownership selection;
- no arbitrary subset search;
- no fallback/recovery substitution;
- no synthetic counters or Euler correction;
- no positional merging across unrelated sheets;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
