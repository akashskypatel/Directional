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
3. **G2 — Cross-chart and close-sheet propagation:** **passed.**
4. **G3 — Periodic closure and holonomy:** **active; periodic-annulus implementation is compile-valid and runtime verification is pending.**
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed-gate runtime authority

Artifact-only validation of source `218dd3ec3f6399dc82183390720a4ba4d3a70b42` using artifact `8994541137`, SHA-256 `f1efaeec80ede729439a1a16e0cadf56db2a1dee2c3380b2ffb4d2da8211f791`, established:

| Fixture | Result | Producer | Traces | Arrangement | Quads | Components | Output hash |
|---|---:|---|---:|---:|---:|---:|---|
| plane | **pass** | `Produced` | 352 | 65 | 64 | 1 | `730caeae49ec872c` |
| seam | **pass** | `Produced` | 256 | 65 | 64 | 1 | `5bdf34d7802e9fb0` |
| close sheets | **pass** | `Produced` | 1,104 | 202 | 200 | 2 | `89b052762f52a5af` |
| cylinder | fail | `NotApplicable` | 732 | 0 | 0 | — | — |
| bunny | fail | `NotApplicable` | 80,862 | 0 | 0 | — | — |
| vase | fail | `NotApplicable` | 116,922 | 0 | 0 | — | — |

Plane, seam, and close sheets are direct `CompletedSurfaceCells` pure-quad outputs with zero strict validation failures and no fallback/recovery. Each is deterministic across three independent processes. G0–G2 are closed.

## G2 source-sheet contract — retained invariant

The authoritative producer partitions state by `(source component, local sheet)` before front construction. World-space distance, nearest projection, or overlap may not join unrelated sheets. Phase, ownership, route, capture, collision, boundary loops, and materialization identity remain sheet-local unless exact source topology establishes a connection.

The exact close-sheet output contains two disconnected 121-vertex components at `z=-0.035` and `z=+0.035`; the focused producer contract verifies both source sheet keys and requires every twinned front edge to retain the same component/local-sheet identity.

## Active G3 contract

The authoritative phase/front producer must support a connected, orientable, singularity-free annular sheet with one periodic lattice direction without treating an artificial chart cut as a real output boundary.

Required first-class periodic authority:

```text
periodic holonomy =
  quarter-turn rotation r in Z4
  + integer lattice translation t in Z2
  + ordered canonical source route
```

Required invariants:

- applicability is derived from source topology, never fixture identity;
- the annulus is cut open through one deterministic source-topology route joining its two true boundary cycles;
- the cut-open phase chart is intrinsic and does not require world-space planarity;
- chart duplicates on the two cut sides retain one authoritative underlying source identity;
- transported phase/branch state around the periodic cycle closes through explicit reciprocal holonomy;
- non-integral, nonreciprocal, branch-incompatible, ambiguous, or missing-provenance holonomy is typed `Rejected` and cannot fall through to generic tracing;
- periodic front counterparts are paired through exact source-route/lattice-holonomy equivalence, never Euclidean welding;
- the artificial cut is not an output boundary;
- the two genuine cylinder boundary loops remain exterior boundaries;
- direct materialization quotients periodic chart duplicates by exact periodic identity and preserves one accepted cell → one quad;
- source-face row ordering cannot change the periodic construction except canonical renumbering.

## G3 compile-valid checkpoint

Source `56f823273cad041a01ebb4d0772c3265ff248f4a` implements a bounded canonical-ring periodic-annulus producer with explicit periodic holonomy state, deterministic intrinsic source cut/chart, typed periodic rejection reasons, `PeriodicFrontMerge` ownership, periodic structural hashing/diagnostics, and exact quotient materialization. The compile-only artifact is `9001168379`, SHA-256 `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`, with **44/44** recursive checksums and **111/111** compile/link actions across seven approved targets. No generated project binary was executed.

The bounded implementation assumes a canonical equal-cardinality source-ring structure; it is not a general arbitrary-annulus/genus solver. That limitation is explicit rather than inferred away. Artifact execution must establish whether the exact production cylinder satisfies the bounded contract.

Therefore this checkpoint makes no cylinder runtime-success claim. The latest executed cylinder remains `NotApplicable`, 732 generic traces, zero arrangement/completion, terminal `NotProductionReady:completion` until artifact `9001168379` is tested.

G3 closes only when exact cylinder artifact execution proves direct deterministic strict-valid `Produced` output with correct periodic holonomy/quotient while plane, seam, and close sheets remain green. A new typed periodic `Rejected` result with zero generic substitution is material progress but does not close G3.

## Next implementation authority

Execute `.agents/Directional/Gate_3_Periodic_Cylinder_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9001168379`. This is a Test + Benchmark turn: do not edit or rebuild. If G3 closes, the next implementation gate is G4 topology-distinct completion and singularities. If G3 remains open, the next Code + Build turn addresses only the exact general periodic rejection established by artifact evidence.

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
