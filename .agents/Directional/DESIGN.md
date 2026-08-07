# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from the requested `SurfaceCells` backend. Fallback, source-grid recovery, synthetic topology repair, fixture-specific bypass, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete design gate. A later fixture, completion catalog, diagnostic taxonomy, cache, scheduler, memory optimization, or benchmark cannot displace an earlier constructive gate.

Every implementation turn declares the active gate, earliest failing fixture, missing contract, smallest general change, observable material-progress condition, and explicitly deferred work.

## Architecture

### Source authority

All decisions retain source triangle, chart, component, local-sheet, route, transition, and feature provenance. World-space proximity is never sufficient to select a sheet, chart, or connectivity relation.

### Orientation, phase, chart, and transition state

The cross field supplies local orientation, not connectivity. The producer carries first-class local phase, integer lattice coordinate, branch rotation, scale level, field family/sign, component, source-chart, local-sheet identity, and exact source transition provenance. This state is deterministic, hashable, and transported only through authoritative source topology.

### Directed phase front

A front edge owns source-attached endpoints, an ordered source route, lattice/chart/transition state, family/sign, and one filled side or explicit exterior classification. Missing or inconsistent transition, ownership, phase, route, component, or sheet state fails closed.

### Authoritative cell contract

A cell is authoritative only with four distinct source-attached corners, four ordered side paths, nonzero intrinsic area, source-normal-consistent winding, coherent phase/lattice/family/chart/sheet/route state, and exactly one filled side or exterior classification on every directed edge.

Opposite winding is corrected only by transactionally reversing the complete cycle. Positional sorting or index heuristics are prohibited.

### Materialization boundary

An accepted four-sided phase-front cell maps to one quad-domain cell. Arrangement may canonicalize exact source identities, split exact crossings, materialize halfedges/cycles, and validate provenance. It must not infer connectivity through fan-sector ranking, choose topology by count/order/frequency, merge unrelated sheets by position, expand an already-decided cell through generic completion, or decompose/merge cycles after the fact.

## Mandatory fixture policy

Simple analytic fixtures isolate contracts but are insufficient alone. The mandatory direct suite therefore contains:

1. plane;
2. multi-face seam;
3. close sheets;
4. cylinder;
5. randomized bunny;
6. open-boundary vase.

The bunny and vase are fixed real production meshes whose hashes and topology are asserted. They use generated smooth cross fields and the same direct production path. No implementation behavior may depend on fixture name, path, ID, vertex count, face count, or expected output count.

Later complex fixtures cannot be used to bypass an earlier failed gate. All mandatory cases still run so architecture failures are visible across the full matrix.

## Ordered gates

### G0 — Truthful authority

**Passed and continuously enforced.** Acceptance requires requested/executed `SurfaceCells`, fallback `Fail`, recovery disabled, valid `CompletedSurfaceCells`, and strict source-authoritative validation.

### G1 — Uniform phase-front plane

**Passed.** Exact artifact evidence produced 64 authoritative cells and 64 pure output quads, 81 vertices, zero validation failures, no fallback/recovery, and stable output hash `730caeae49ec872c`.

### G2 — Cross-chart and close-sheet propagation

**Active.** Exact source-chart/transition provenance, per-face branch transport, and reciprocal quarter-turn validation are now compile-valid for the first planar multi-face slice. Artifact execution must prove nonzero authoritative seam cells, seam success, close-sheet isolation, and preservation of Gate 1 materialization.

The mandatory bunny and vase additionally expose the need for general non-planar chart transport. They are required observations but cannot displace the seam as the earliest gate.

### G3 — Periodic closure and holonomy

Blocked by G2. Add explicit periodic phase reconciliation, complete directed incidence, and cylinder success.

### G4 — Topology-distinct completion and singularities

Blocked by G3. Add finite topology templates and intentional singularity handling without generic center-fan fallback.

### G5 — Adaptive scale and hard features

Blocked by G4. Add dyadic scale levels, 2:1 transitions, hard-feature rails, and no T-junctions or feature loss.

### G6 — Full production geometry

Blocked by G5 as a success gate, but bunny and vase remain mandatory observations in every Test + Benchmark turn. G6 exits only when real production meshes pass directly and deterministically with generated and supplied fields where applicable.

### G7 — Operational hardening

Blocked by G6. Address exact predicates, spatial indices, caches, parallelism, memory, performance, full matrix, and production-default decision.

## Current authority

- Gate 2 source commit: `21f081b330418a0f34709f61d857f54a03d2fd48`;
- compile artifact SHA-256: `f5c2be0e2131dbce7a6460e3c61da2de57f7d256c00a5401ac6285d6a0145755`;
- next plan: `.agents/Directional/Gate_2_Cross_Chart_Mandatory_Fixtures_Artifact_Only_Test_Benchmark_Plan.md`.

## Material progress

The next artifact must pass the seam or produce nonzero deterministic authoritative cross-chart cells reaching a first-class transport/materialization boundary. Unchanged zero-cell completion failure, fixture-specific success, new counters, or diagnostics alone are not progress.

If two consecutive Code + Build turns do not materially improve the active gate, the following turn must perform a bounded design review or producer replacement proof.

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
