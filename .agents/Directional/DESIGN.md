# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed design gate. Every implementation turn declares the active gate, earliest failing fixture, missing contract, smallest general change, observable material-progress condition, and explicitly deferred work.

## Architecture

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, route, feature, and ownership state. Fronts advance only through exact source topology and reciprocal field transport. Authoritative metadata is strict and fail-closed when present. A coherent prescribed raw field may omit precomputed matching/transition containers; in that case, a planar phase-front proof may use exact physical forward/reverse transport, but never proximity, fixture identity, or arbitrary branch choice.

When a phase-front segment meets a source vertex, continuity is not a positional jump. A valid route must traverse a unique ordered incident-face fan and apply every crossed authoritative edge transition. Ambiguous, non-manifold, disconnected, or nonreciprocal fans fail closed.

An authoritative cell has four ordered source-attached corners and sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, and exact directed ownership. One accepted cell maps to one quad. Arrangement may canonicalize exact identities and crossings but may not infer topology by count/order/frequency, position, fallback, or post-hoc decomposition.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** **active.** The first restoration artifact was tested and rejected because the live complete-metadata path remained unchanged.
3. **G2 — Cross-chart and close-sheet propagation:** seam sub-contract proven; blocked by G1 and close-sheet failure.
4. **G3 — Periodic closure and holonomy:** blocked.
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Current runtime evidence

| Fixture | Result | Traces | Arrangement | Output quads |
|---|---:|---:|---:|---:|
| plane | fail | 106 | 9 | 0 |
| seam | **pass** | 256 | 65 | 64 |
| close sheets | fail | 158 | 0 | 0 |
| cylinder | fail | 732 | 0 | 0 |
| bunny | fail | 80,862 | 0 | 0 |
| vase | fail | 116,922 | 0 | 0 |

All cases were structurally deterministic, used direct `SurfaceCells`, fallback `Fail`, and no recovery. The seam output hash is `a8972efd7c4900a4`. Direct acceptance is 1/6.

## Active Gate 1 contract

The prescribed plane enters tracing with populated matching, effort, and edge-transition metadata. Gate 1 therefore requires the uniform phase-front producer to consume complete zero-turn authoritative metadata, including exact source-topology transitions at segment endpoints and source vertices.

The next Code + Build turn must make the first phase-front rejection typed and observable, then repair only the confirmed general predicate. The leading candidate is the shared-edge-only assumption between consecutive selected intervals; it is not yet runtime-proven.

Material progress requires a live consumed producer contract and, in the following artifact-only turn, plane direct success while retaining seam direct success. Diagnostics alone, a different legacy failure, or higher aggregate totals are insufficient.

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
