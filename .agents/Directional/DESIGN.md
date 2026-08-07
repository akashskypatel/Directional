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
4. **G3 — Periodic closure and holonomy:** **active; periodic authority is runtime-proven, completed output validation remains.**
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed-gate runtime authority

Artifact `9001168379` preserves the direct passed gates:

| Fixture | Result | Producer | Traces | Quads | Validation | Output hash |
|---|---:|---|---:|---:|---:|---|
| plane | **pass** | `Produced` | 352 | 64 | 0 | `730caeae49ec872c` |
| seam | **pass** | `Produced` | 256 | 64 | 0 | `5bdf34d7802e9fb0` |
| close sheets | **pass** | `Produced` | 1,104 | 200 | 0 | `89b052762f52a5af` |

All three are direct `CompletedSurfaceCells` pure-quad outputs, deterministic 3/3, with no fallback/recovery. The close-sheet output remains two isolated source-authoritative components.

## G2 source-sheet contract — retained invariant

The authoritative producer partitions state by `(source component, local sheet)` before front construction. World-space distance, nearest projection, or overlap may not join unrelated sheets. Phase, ownership, route, capture, collision, boundary loops, and materialization identity remain sheet-local unless exact source topology establishes a connection.

## G3 periodic contract — now runtime consumed

A connected singularity-free annulus has first-class periodic authority:

```text
periodic holonomy =
  quarter-turn rotation r in Z4
  + integer lattice translation t in Z2
  + ordered canonical source route
```

Required invariants remain:

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
- source-face row ordering may change incidental DCEL numbering but not canonical source-route/cut identity or holonomy semantics.

Artifact-only execution of source `56f823273cad041a01ebb4d0772c3265ff248f4a`, artifact `9001168379`, SHA-256 `0b4ef04bd7d9641588a6f9d23882501d551367fdee56b9b99954becc19780b8c`, proved the exact cylinder now consumes this authority:

- disposition `Produced`;
- holonomy `r=0`, `t=(29,0)`, ordered route 32 edges, cut four edges;
- 2,163 source-attached traces;
- zero generic arrangement cells;
- 290 direct completed quads;
- 319 provenance vertices;
- no fallback/recovery;
- deterministic 3/3.

This is material progress over the prior `NotApplicable` generic path.

## Active G3 output-materialization contract

G3 remains open because the direct cylinder completed checkpoint reports two validation failures and terminates at `completion/output-validation:AggregateCompletionValidationFailure` before final output. The benchmark record does not expose the two individual validator threshold fields; they must not be guessed or relaxed.

The next constructive invariant is:

> A periodic phase-front that is authoritative `Produced` must materialize a source-strip-conforming annular lattice. Every canonical source-ring strip boundary is a mandatory intrinsic lattice breakpoint, so a direct output side cannot shortcut a source topological corner merely because a global target-size count places a column across it.

Implementation requirements:

- derive the ordered source-ring strips from canonical annulus topology already used by the periodic chart;
- assign each source strip a deterministic positive integer subdivision count from intrinsic strip length and local target size;
- preserve every strip boundary as an exact lattice column;
- define periodic translation as the cumulative integer strip subdivisions;
- preserve the exact cut quotient, source provenance, periodic ownership, and one-cell-to-one-quad mapping;
- fail closed if a reciprocal source-strip-conforming chart cannot be built;
- never special-case the committed ring count, current translation `29`, fixture name, or expected output counts.

This correction is upstream of validation. Validation remains authoritative and unchanged.

## Row-order semantic identity

The focused `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration` test currently compares raw DCEL source-edge integer IDs from independently enumerated meshes. DCEL edge numbering changes with face-row traversal. Artifact evidence maps both raw holonomy routes and cuts to identical ordered canonical source-vertex endpoint sequences.

The intended test contract is ordered **canonical source-edge endpoint identity**, not raw DCEL numbering. Correct the test in the next Code + Build turn while retaining route order, route/cut cardinality, grid dimensions, rotation, and lattice translation assertions. Production code must not normalize incidental DCEL IDs merely to satisfy a test.

## Next implementation authority

Execute `.agents/Directional/Gate_3_Periodic_Output_Validation_Code_Build_Plan.md` as Code + Build only.

G3 closes only when exact cylinder remains authoritative `Produced` and becomes direct deterministic strict-valid `CompletedSurfaceCells` pure-quad output with correct periodic quotient while plane, seam, and close sheets remain green. Then advance to G4.

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