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
4. **G3 — Periodic closure and holonomy:** active. Periodic topology/cut/quotient/source-strip authority is runtime-proven; field-authoritative ring correspondence is retained; endpoint-canonicalization correction is compile-valid and awaits artifact runtime validation.
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Passed-gate runtime authority

Latest executed artifact `9008118764` preserves G0-G2:

| Fixture | Producer | Direct output | Determinism |
|---|---|---|---|
| plane | `Produced` | 81 V / 64 strict-valid quads, hash `730caeae49ec872c` | 3/3 |
| seam | `Produced` | 81 V / 64 strict-valid quads, hash `5bdf34d7802e9fb0` | 3/3 |
| close sheets | `Produced` | 242 V / 200 strict-valid quads / 2 isolated components, hash `89b052762f52a5af` | 3/3 |

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

Required contract:

> Enumerate topology-compatible correspondences, propagate reciprocal 4-RoSy family/sign authority across the complete source strip, and consume exactly one field-authoritative optimum. Zero valid field candidates or genuinely field-equivalent best candidates fail closed with typed periodic authority.

Source `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a` made this contract compile-valid with typed `InvalidPeriodicRingCorrespondence` and `AmbiguousPeriodicRingCorrespondence`. Artifact `9008118764` proves the ambiguity fail-closed contract at runtime but regresses the nominal valid cylinder downstream in periodic chart boundary construction. Do not restore the former diagonal/lexicographic correspondence: immutable reconstruction shows that candidate is exactly `37.9670987281°` from the axial field and caused the prior field-P95 defect.

## Active G3 endpoint-canonicalization invariant

The exact cylinder currently rejects `InvalidPeriodicChart` at phase-front cell 29. The reproduced defect is representational:

- chart coverage uses approximately `1e-10` tolerance;
- the old producer also emitted those tolerance-expanded interval endpoints as source geometry;
- adjacent sides that mathematically shared an exact source vertex acquired microscopic tails on one source face;
- the unchanged strict shared-endpoint/self-intersection predicate correctly rejected the emitted overlap.

Required contract:

> Coverage tolerance may determine which source chart triangle owns an interval, but emitted periodic-chart geometry must be canonical source-simplex geometry. Breakpoints come from exact simplex crossings; barycentrics near exact simplex boundaries are canonicalized/renormalized; consecutive sides preserve exact shared source breakpoints; tolerance-only zero-length segments are not emitted. Real overlap remains rejected by the unchanged strict validator.

Compile-valid source `0279946920dfca6e9ac44b7ea31b38e929d1f5fc` implements this bounded contract:

- exact zero-barycentric crossings define emitted breakpoints while tolerance-expanded bounds remain coverage evidence only;
- periodic chart lattice points and segment endpoints share one canonical barycentric normalization;
- source-vertex endpoints become exact one-hot barycentrics;
- tolerance-only collapsed segments are omitted;
- strict `validate_closed_boundary_paths()` and `segments_intersect_beyond_shared_endpoint_2d()` are unchanged;
- field-authoritative correspondence, annulus cut/holonomy/quotient/source-strip authority, provenance and one-cell-to-one-quad mapping are preserved.

Compile-only artifact authority:

- run/job `31221873296 / 93007996817`;
- artifact `9010838200`, SHA-256 `b90a2bc3c0d35287048f8ddd2d3eccfdce8058031192ad3092213526907be9db`;
- log artifact `9010837410`, SHA-256 `2b994f158e8a28ecdc52fd3c532b48edf936aeaaf8284053a728b56a58979973`;
- 44/44 recursive checksums;
- 111/111 compile/link actions;
- `runtimeExecution=false`.

## Next authority

Execute `.agents/Directional/Gate_3_Periodic_Chart_Endpoint_Canonicalization_Artifact_Only_Test_Benchmark_Plan.md` against artifact `9010838200` as Test + Benchmark only.

Material progress requires restoring all six nominal G3 periodic regressions and advancing cylinder beyond cell 29 with field authority and G0-G2 intact. G3 closes only when exact cylinder is direct deterministic strict-valid periodic `Produced` `CompletedSurfaceCells` pure-quad output with zero validation failures, normal/field P95 <= 15°, warpage P95 <= 30°, correct cut/holonomy/quotient/provenance, no false exterior seam, and no fallback/recovery.

If this artifact also establishes no material G3 progress, the next turn is mandatorily a design review or bounded producer replacement proof.

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
