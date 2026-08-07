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
4. **G3 — Periodic closure and holonomy:** **active; periodic topology/source-strip authority is runtime-proven and field-authoritative adjacent-ring correspondence is compile-valid, runtime verification pending.**
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

## G3 periodic contract — retained invariant

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
- periodic transport is reciprocal, integral, branch-compatible and source-routed;
- invalid periodic state is typed `Rejected` and cannot fall through to generic tracing;
- artificial-cut front counterparts pair through exact source/phase/lattice authority, never Euclidean welding;
- the artificial cut is not an exterior output boundary;
- the two genuine annulus boundaries remain exterior;
- direct materialization quotients periodic duplicates exactly and preserves one accepted cell → one quad;
- source-face row ordering may change incidental DCEL numbering but not canonical source-route/cut identity or holonomy semantics;
- every canonical source-ring strip boundary is a mandatory intrinsic periodic lattice breakpoint.

Artifact `9004509871` proves periodic `Produced`, source-strip authority, canonical route/cut identity and deterministic holonomy on the exact cylinder, but its completed output is still runtime-red with normal/field/warpage P95 failures.

## Field-authoritative adjacent-ring correspondence contract

A triangulated annulus strip can admit more than one source-topologically valid one-to-one bijection between adjacent canonical rings. Source vertex numbering, lexicographic order, candidate count or discovery frequency are not authority for choosing one.

The required contract is:

> Adjacent canonical annulus-ring correspondence is resolved from reciprocal transported cross-field family/sign authority over the complete source strip. Exactly one field-authoritative topology-compatible candidate may be consumed. Zero valid field candidates or genuinely field-equivalent best candidates fail closed with typed periodic authority.

The implementation must preserve source-topology compatibility first, then field authority:

1. enumerate only source-topologically compatible ring bijections;
2. propagate branch/family state across the candidate strip through reciprocal source-edge transition authority;
3. require forward/reverse branch consistency;
4. evaluate inter-ring connections against one transported cross-field family and circumferential source-ring connections against its orthogonal family;
5. select only a unique field-authoritative optimum;
6. never resolve ambiguity by source ID, lexicographic sequence, count, frequency, fixture identity, arbitrary subset search or proximity;
7. typed-reject no valid correspondence as `InvalidPeriodicRingCorrespondence`;
8. typed-reject genuinely field-equivalent best correspondences as `AmbiguousPeriodicRingCorrespondence`;
9. retain the annulus cut, holonomy, source-strip breakpoints/subdivisions, periodic quotient, provenance and one accepted cell → one quad.

## Compile-valid G3 correspondence checkpoint

Source/test commit `c5d2c90fc97ca2ae71bf2e8b50c8e7766c0bdb9a` implements that bounded contract.

Final source blobs:

- `SurfaceCellTracing.h`: `c1b816a584d67a3f74c2d7389962bd92d52244c9`;
- `SurfaceCellTracing.cpp`: `6980850bd32d40b1da9350ebbe3f601b8ce5e07b`;
- `SurfaceCellsPhase10Tests.cpp`: `c4671ef674228d74b96e80499abbb6846bcdf3e3`.

New regression source requires:

- the exact cylinder's exact-source-vertex V-family phase-front edges to follow the authoritative axial field family rather than the topology-compatible diagonal strip edge;
- a synthetic field where the two topology-compatible ring candidates are truly field-equivalent to return typed `Rejected/AmbiguousPeriodicRingCorrespondence` with no generic seeds/traces/proposals.

Compile-only artifact authority:

- run/job `31214404170` / `92984429773`;
- artifact `9008118764`, SHA-256 `11e9e50e59aaf71149594f791c5f4c6465ab452111427760cb2f0c9065fea562`;
- log artifact `9008117677`, SHA-256 `a4cd22bb4662edc290ad558d76e09af4b34a440f5803a5474af5dc68421a1a77`;
- **44/44** recursive checksums;
- **111/111** compile/link actions across seven approved targets;
- command boundary `runtimeExecution=false`.

The first bounded compile attempt failed only in the new test helpers due Eigen expression-template typing after production source compiled. A test-source-only correction produced the successful compile authority above. No generated project binary was executed in either build attempt.

## Next authority

Execute `.agents/Directional/Gate_3_Periodic_Ring_Correspondence_Artifact_Only_Test_Benchmark_Plan.md` against exact artifact `9008118764` as Test + Benchmark only.

G3 closes only when artifact execution proves exact cylinder is direct deterministic strict-valid periodic `Produced` `CompletedSurfaceCells` pure-quad output with zero validation failures, field/normal P95 <= 15°, warpage P95 <= 30°, correct periodic cut/holonomy/quotient/provenance, no false exterior seam, no fallback/recovery, and plane/seam/close sheets green. Then advance to G4.

If the field-authoritative correspondence is consumed but another exact later G3 defect remains, preserve it and address only that general failure next.

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