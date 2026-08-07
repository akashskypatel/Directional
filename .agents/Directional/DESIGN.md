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
4. **G3 — Periodic closure and holonomy:** **active; periodic authority is runtime-proven and the source-strip output-validation correction is compile-valid, runtime verification pending.**
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

## G3 periodic contract — runtime consumed

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

Artifact-only execution of source `56f823273cad041a01ebb4d0772c3265ff248f4a`, artifact `9001168379`, proved the exact cylinder consumes this authority:

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

The latest executed cylinder remains red because the direct completed checkpoint reports two validation failures and terminates at `completion/output-validation:AggregateCompletionValidationFailure` before final output. The benchmark record does not expose the two individual validator threshold fields; they must not be guessed or relaxed.

The constructive invariant is:

> A periodic phase-front that is authoritative `Produced` must materialize a source-strip-conforming annular lattice. Every canonical source-ring strip boundary is a mandatory intrinsic lattice breakpoint, so a direct output side cannot shortcut a source topological corner merely because a global target-size count places a column across it.

Validation remains authoritative and unchanged.

## G3 source-strip correction — compile-valid checkpoint

Source commit `2783ea718ffb15f8fb3868795173472ab8636c1c` implements the bounded correction without changing validators or materialization repair behavior.

For every already-authoritative canonical source strip around the annulus, the periodic producer now:

1. retains the strip endpoint as an exact intrinsic periodic lattice breakpoint;
2. derives strip length from the transported canonical ring structure already used by the periodic chart;
3. samples local target size from both strip endpoints on every ring;
4. chooses a deterministic positive nearest-integer subdivision count from strip length / local target;
5. fails closed as `InvalidPeriodicChart` for non-finite or overflowing subdivision state;
6. builds the cumulative periodic chart coordinate sequence strip by strip, using each exact strip endpoint as the final coordinate of that strip;
7. defines `gridU` and the periodic lattice translation from the sum of strip-local subdivisions;
8. constructs phase-front points, cell corners, side paths, and intrinsic cell validation from those nonuniform strip-conforming coordinates.

The axial subdivision and genuine annulus boundaries remain unchanged. The exact periodic quotient, periodic ownership, source provenance, and one-cell-to-one-quad mapping remain upstream invariants. No post-hoc splitting/merging, proximity seam weld, nearest-point repair, fallback/recovery, fixture identity, or expected output count was added.

The previous translation `t=(29,0)` is runtime history, not a required future constant. A deterministic source-strip-conforming translation may differ; semantic holonomy/quotient correctness decides acceptance.

## Row-order semantic identity — corrected in source

Artifact evidence established that raw DCEL source-edge integer IDs can change after face-row reversal while ordered canonical source-edge endpoint identities remain equal.

The compiled row-order contract now maps each route/cut source-edge ID through that mesh's authoritative `EV` table to ordered canonical endpoint keys `(min(v0,v1), max(v0,v1))` and compares the **ordered key sequences**. It does not sort away route order or normalize production DCEL IDs.

Grid dimensions, rotation, lattice translation, route/cut cardinality, disposition, and the existing periodic semantic assertions remain in the test.

A new compiled structural contract also requires all genuine source-boundary vertices derived from authoritative boundary edges to occur as exact phase-front corners. It does not encode the committed cylinder ring count or expected output count.

These tests are compile-valid only until artifact execution.

## Compile authority

- source `2783ea718ffb15f8fb3868795173472ab8636c1c`;
- patch SHA-256 `74dc044caf0f05c108a1b2dc062927bc5a4bbfac6fb34584d20010f5d2d6fe9e`;
- build run/job `31204848178` / `92953250176`;
- artifact `9004509871`, SHA-256 `2ebc543d15bc5a134d664016b6437487de0ce73267bff2986d09ba1423b382fe`;
- detailed log artifact `9004508508`, SHA-256 `80c6ab8997caafb49306adf3496a9dd20f1e2c029f63f8a71237e9b7e68a292b`;
- recursive checksums **44/44**;
- compile/link **111/111** across seven approved targets;
- packaged command boundary `runtimeExecution=false`.

No generated project binary was executed during this Code + Build turn.

## Next implementation authority

Execute `.agents/Directional/Gate_3_Periodic_Output_Validation_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9004509871` as Test + Benchmark only. Do not rebuild or edit.

G3 closes only when exact cylinder remains authoritative periodic `Produced` and becomes direct deterministic strict-valid `CompletedSurfaceCells` pure-quad output with source-strip-conforming periodic lattice/quotient, zero completed-checkpoint validation failures, no false periodic exterior seam, complete provenance, no fallback/recovery, and plane/seam/close sheets green. Then advance to G4.

If artifact execution exposes another exact source-authoritative G3 structural/validation failure, remain in G3 and address only that general failure next.

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