# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed design gate. Every implementation turn declares the active gate, earliest failing fixture, missing contract, smallest general change, observable material-progress condition, and explicitly deferred work.

## Producer authority model

The bounded producer-selection replacement is now implemented at compile time. An authoritative producer returns one of three semantically distinct outcomes:

```text
NotApplicable
Produced
Rejected
```

- `NotApplicable`: this producer does not represent the source topology yet; another explicitly selected producer may run.
- `Produced`: authoritative cells/fronts are complete and materialize directly one cell to one quad.
- `Rejected`: the producer was applicable but a fail-closed invariant failed; retain the typed reason and stop this backend request. Do not silently launch generic seeds/traces/proposals.

Applicability is decided from general topology/field state before authoritative metadata execution, never from fixture identity or from whether a producer happened to fail.

The implementation now prevents generic producer substitution after `Rejected`, preserves typed rejection at the tracing producer boundary, serializes/hashes producer disposition, and lets only `NotApplicable` continue to a separately selected producer. Runtime verification of these semantics is pending the next artifact-only turn.

## Authoritative phase/front representation

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, ordered route, feature, and ownership state. Fronts advance only through exact source topology and reciprocal field transport.

A source-vertex crossing is an ordered incident-face fan, never a positional jump. Every crossed canonical source edge is recorded and transported through strict reciprocal transition logic. Ambiguous, disconnected, repeated, non-manifold, nonreciprocal, missing-provenance, or branch-mismatched routes fail closed.

Hard-feature barriers remain authoritative constraints. Relief separatrices are guidance until embedded; `reliefBarrierEdges` may stop authoritative transport only when `reliefBarriersEmbedded == true`, matching the tracing-option contract. This consistency is now implemented compile-time but awaits runtime verification.

An authoritative cell has four ordered source-attached corners/sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, exact component/sheet ownership, and complete route provenance. One accepted cell maps to one quad.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** **active; authoritative producer-boundary implementation compiled, runtime verification pending.**
3. **G2 — Cross-chart and close-sheet propagation:** seam sub-contract proven; blocked by G1 and close-sheet failure.
4. **G3 — Periodic closure and holonomy:** blocked.
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Latest executed runtime authority

No runtime was executed in the current Code + Build turn. The latest artifact-tested matrix remains:

| Fixture | Result | Traces | Arrangement | Output quads |
|---|---:|---:|---:|---:|
| plane | fail | 106 | 9 | 0 |
| seam | **pass** | 256 | 65 | 64 |
| close sheets | fail | 158 | 0 | 0 |
| cylinder | fail | 732 | 0 | 0 |
| bunny | fail | 80,862 | 0 | 0 |
| vase | fail | 116,922 | 0 | 0 |

Direct acceptance remains 1/6. The seam remains direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, no fallback/recovery, hash `a8972efd7c4900a4`.

## Latest compile-only authority

- source commit: `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3`;
- payload cleanup: `bcf934d34e9a15f5d0929628ffd26f6833643214`;
- patch SHA-256: `a9af7d502a237a3f0a58324639f0fe77129de5fe5f147ea14b1e077545c5ccef`;
- approved targets: 7/7;
- compile/link actions: 111/111;
- artifact SHA-256: `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031`;
- internal checksums: 44/44;
- runtime claims from current turn: none.

The source also contains an exact committed `plane.obj` + `plane.rawfield` production-route regression. It compiled but was not executed.

## Next implementation authority

Use `.agents/Directional/Gate_1_Authoritative_Producer_Boundary_Artifact_Only_Test_Benchmark_Plan.md` against the exact artifact above.

Acceptance hierarchy:

1. Gate 1 closure: plane is `Produced` with direct deterministic valid pure-quads and seam retains direct success.
2. Minimum architecture proof: plane is explicit immutable `Rejected`, stops at tracing, and the old 106/9/12 generic substitution disappears. G1 remains red.
3. No progress: `NotApplicable`/generic fall-through persists, rejection is overwritten, seam regresses, or acceptance is weakened.

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
