# Direct Surface-Cell Quadrangulation Design

## Product contract

Given an arbitrary triangle mesh and a supplied or generated cross field, produce a deterministic, source-authoritative, cross-field-aligned pure-quad surface mesh. Production success must come directly from `SurfaceCells`; fallback, source-grid recovery, synthetic topology repair, fixture-specific behavior, or validator relaxation cannot satisfy acceptance.

## Design-first rule

Always advance the earliest incomplete or regressed design gate. Every implementation turn declares the active gate, earliest failing fixture, missing contract, smallest general change, observable material-progress condition, and explicitly deferred work.

## Architecture

The producer carries first-class phase, integer lattice coordinate, branch rotation, family/sign, source face/chart/component/local-sheet, transition edge, route, feature, and ownership state. Fronts advance only through exact source topology and reciprocal field transport. Authoritative metadata is strict and fail-closed when present. A coherent prescribed raw field may omit precomputed matching/transition containers; in that case, a planar proof may use exact reciprocal physical transport, never proximity, fixture identity, or arbitrary branch choice.

When a phase-front segment meets a source vertex, continuity is not a positional jump. A valid route traverses exactly one directed incident-face fan selected from source topology and segment geometry, applies every authoritative edge transition, and records every canonical source-edge ID. Disconnected, repeated, non-manifold, ambiguous, missing-provenance, nonreciprocal, or branch-mismatched fans fail closed.

An authoritative cell has four ordered source-attached corners and sides, coherent transported state, nonzero intrinsic area, source-normal-consistent winding, and exact directed ownership. One accepted cell maps to one quad. Arrangement may canonicalize exact identities and crossings but may not infer topology by count/order/frequency, position, fallback, or post-hoc decomposition.

## Ordered gates

1. **G0 — Truthful authority:** passed and continuously enforced.
2. **G1 — Uniform phase-front plane:** **active mandatory architecture review.** Two bounded Code + Build attempts failed to materially advance the production plane; a third local predicate repair is prohibited.
3. **G2 — Cross-chart and close-sheet propagation:** seam sub-contract proven; blocked by G1 and close-sheet failure.
4. **G3 — Periodic closure and holonomy:** blocked.
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Current runtime evidence

| Fixture | Result | Traces | Arrangement | Completed | Output quads |
|---|---:|---:|---:|---:|---:|
| plane | fail | 106 | 9 | 12 | 0 |
| seam | **pass** | 256 | 65 | 64 | 64 |
| close sheets | fail | 158 | 0 | 0 | 0 |
| cylinder | fail | 732 | 0 | 0 | 0 |
| bunny | fail | 80,862 | 0 | 0 | 0 |
| vase | fail | 116,922 | 0 | 0 | 0 |

The tested source-vertex artifact was structurally deterministic, used direct `SurfaceCells`, fallback `Fail`, and no recovery. The seam remains direct `CompletedSurfaceCells`, 81 vertices, 64 pure quads, zero validation failures, hash `a8972efd7c4900a4`. Direct acceptance is 1/6.

## Gate 1 no-progress finding

All new source-vertex contract tests passed, but the production plane retained the exact 106/9/12 generic completion signature. Its tracing structural hash changed, which proves the new route/provenance state affected tracing identity, but this is not constructive progress because no authoritative phase-front output was produced.

The isolated contract fixture reconstructs the same rectangular geometry with different indexing and a directly injected constant target size. It does not prove equivalence to the exact committed `plane.obj` after production target-size computation, source labeling, cross-field finalization, and tracing-option construction.

The pipeline also reuses one mutable `surfaceCellFirstInvalidProducer*` diagnostic channel: a typed `tracing/phase-front` failure can be overwritten by later generic completion failure. The mandatory review must determine whether the deeper semantic problem is diagnostic loss only or whether an applicable authoritative phase-front failure is being silently substituted by a distinct generic producer path.

## Mandatory next direction

Execute `.agents/Directional/Gate_1_Producer_Architecture_Design_Review_Plan.md`.

The review must compare the last successful Gate 1 source `aea10409c73c490b92f78760b73191641ef823c6` against Gate 2 and current sources, reconstruct the exact production-plane authority path, explain why isolated contract success does not become production output, and select exactly one bounded architectural correction or bounded producer replacement proof.

No third isolated predicate repair is authorized.

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
