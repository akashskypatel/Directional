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

The implementation prevents generic producer substitution after `Rejected`, preserves typed rejection at the tracing producer boundary, serializes/hashes producer disposition, and lets only `NotApplicable` continue to a separately selected producer.

## Authoritative phase/front representation

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, ordered route, feature, and ownership state. Fronts advance only through exact source topology and reciprocal field transport.

A source-vertex crossing is an ordered incident-face fan, never a positional jump. Every crossed canonical source edge is recorded and transported through strict reciprocal transition logic. Ambiguous, disconnected, repeated, non-manifold, nonreciprocal, missing-provenance, or branch-mismatched routes fail closed.

Hard-feature barriers remain authoritative constraints. Relief separatrices are guidance until embedded; `reliefBarrierEdges` may stop authoritative transport only when `reliefBarriersEmbedded == true`, matching the tracing-option contract.

An authoritative cell has four ordered source-attached corners/sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, exact component/sheet ownership, and complete route provenance. One accepted cell maps to one quad.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** **passed.**
3. **G2 — Cross-chart and close-sheet propagation:** **active; bounded source-sheet producer extension is compile-valid and runtime verification is pending.** Multi-face seam is proven; disconnected close sheets remain the earliest failing runtime fixture until artifact validation executes.
4. **G3 — Periodic closure and holonomy:** blocked.
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Gate 1 runtime closure authority

Artifact-only validation of source commit `0e96ceb62f85353c9cd8a1eeed7c560babeaa7c3` using artifact SHA-256 `4dc3ec7d797fae2cebe7040a60712a92bfe63cdfe1052ba74796ef0a6602a031` established:

| Fixture | Result | Producer | Traces | Arrangement | Completed quads | Output |
|---|---:|---|---:|---:|---:|---|
| plane | **pass** | `Produced` | 352 | 65 | 64 | `CompletedSurfaceCells` |
| seam | **pass** | `Produced` | 256 | 65 | 64 | `CompletedSurfaceCells` |
| close sheets | fail | `NotApplicable` | 158 | 0 | 0 | none |
| cylinder | fail | `NotApplicable` | 732 | 0 | 0 | none |
| bunny | fail | `NotApplicable` | 80,862 | 0 | 0 | none |
| vase | timeout/fail | not fully observed | — | — | — | none |

Plane and seam both have 81 provenance/output vertices, 64 pure quads, zero strict validation failures, no fallback/recovery, and deterministic output hashes across three independent benchmark processes. The former plane 106/9/12 generic failing signature is eliminated. G1 is closed.

## Active G2 contract

The authoritative uniform phase/front producer must operate correctly across multiple disconnected or distinct local sheets that may be arbitrarily close in world space.

Required invariants:

- source component and local-sheet identity partition producer state before front construction;
- world-space distance, nearest projection, or overlap may not join unrelated sheets;
- phase, ownership, route, capture, and collision state are sheet-local unless exact source topology establishes a connection;
- each authoritative sheet uses the same proven ordinary-edge and ordered source-vertex-fan transport contracts independently;
- concatenating independent authoritative sheet outputs preserves source provenance and produces one accepted cell → one quad;
- materialization identity includes source component/local-sheet authority so equal lattice coordinates on unrelated sheets do not merge;
- boundary loops remain source-sheet-local;
- source component/local-sheet ordering or source-face row ordering cannot change structural output except for canonical renumbering;
- failure of one applicable sheet is `Rejected` for the selected authoritative producer, never silent generic substitution for that sheet;
- periodic domains such as the cylinder remain outside G2 and may remain `NotApplicable` until G3 holonomy support.

## G2 compile-valid checkpoint

Source commit `218dd3ec3f6399dc82183390720a4ba4d3a70b42` implements the bounded G2 contract above. The compile-only artifact is `8994541137`, SHA-256 `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`, with 45/45 internal checksums and 111/111 compile/link actions across seven approved targets. No project binary was executed, so this checkpoint does **not** claim G2 runtime success.

G2 closes only when the exact close-sheet production fixture becomes direct deterministic valid `Produced` output with no cross-sheet provenance/merge violation while plane and seam remain unchanged mandatory regressions.

## Next implementation authority

The next turn is **artifact-only Test + Benchmark** using `.agents/Directional/Gate_2_Close_Sheet_Artifact_Only_Test_Benchmark_Plan.md`. Do not edit implementation or validation logic and do not rebuild. If G2 closes, the next Code + Build gate becomes G3 periodic cylinder/holonomy. If G2 remains open, address only the exact general G2 failure established by artifact evidence.

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
