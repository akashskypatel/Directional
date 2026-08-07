# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed design gate. Every implementation turn declares the active gate, earliest failing fixture, missing contract, smallest general change, observable material-progress condition, and explicitly deferred work.

## Architecture

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, route, feature, and ownership state. Fronts advance only through exact source topology and reciprocal field transitions. An authoritative cell has four ordered source-attached corners and sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, and exact directed ownership. One accepted cell maps to one quad. Arrangement may canonicalize exact identities and crossings but may not infer topology by count/order/frequency, position, fallback, or post-hoc decomposition.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** **regressed; active restoration gate.** Previous artifact passed 64/64, but Gate 2 artifact regressed to 106 traces, 9 arrangement cells, 12 invalid completion quads, and 15 validation failures.
3. **G2 — Cross-chart and close-sheet propagation:** seam sub-contract proven; blocked by G1 restoration and close-sheet failure. Seam now produces 64 deterministic direct quads with output hash `a8972efd7c4900a4`.
4. **G3 — Periodic closure and holonomy:** blocked.
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Current evidence

| Fixture | Result | Traces | Arrangement | Output quads |
|---|---:|---:|---:|---:|
| plane | fail | 106 | 9 | 0 |
| seam | pass | 256 | 65 | 64 |
| close sheets | fail | 158 | 0 | 0 |
| cylinder | fail | 732 | 0 | 0 |
| bunny | fail | 80,862 | 0 | 0 |
| vase | fail | 116,922 | 0 | 0 |

All results are deterministic and direct, with fallback `Fail` and no recovery.

## Active restoration contract

Restore the constant prescribed-field plane to the authoritative phase-front path without reverting or bypassing exact reciprocal chart transitions. Material progress requires plane direct success while retaining seam direct success. Diagnostics alone, a different legacy failure, or higher aggregate totals are insufficient.

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
