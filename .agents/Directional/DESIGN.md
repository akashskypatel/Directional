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
2. **G1 — Uniform phase-front plane:** **active; second bounded Code + Build complete, artifact-only verification pending.**
3. **G2 — Cross-chart and close-sheet propagation:** seam sub-contract proven; blocked by G1 and close-sheet failure.
4. **G3 — Periodic closure and holonomy:** blocked.
5. **G4 — Topology-distinct completion and singularities:** blocked.
6. **G5 — Adaptive scale and hard features:** blocked.
7. **G6 — Full production geometry:** blocked as a success gate; randomized bunny and vase remain mandatory observations.
8. **G7 — Operational hardening:** blocked.

## Last runtime evidence

| Fixture | Result | Traces | Arrangement | Output quads |
|---|---:|---:|---:|---:|
| plane | fail | 106 | 9 | 0 |
| seam | **pass** | 256 | 65 | 64 |
| close sheets | fail | 158 | 0 | 0 |
| cylinder | fail | 732 | 0 | 0 |
| bunny | fail | 80,862 | 0 | 0 |
| vase | fail | 116,922 | 0 | 0 |

All executed cases were structurally deterministic, used direct `SurfaceCells`, fallback `Fail`, and no recovery. The seam output hash is `a8972efd7c4900a4`. Direct acceptance remains 1/6 until the new artifact is tested.

## Current Gate 1 implementation authority

Static emulation of the exact committed plane triangulation and phase-front grid confirmed 16 transitions where consecutive selected intervals meet at a source vertex without sharing an edge. The implementation now has typed first-rejection state and deterministic ordered authoritative fan traversal while retaining the ordinary shared-edge path.

Artifact-only acceptance requires plane direct construction or material advancement beyond the 106/9/12 generic signature while retaining seam direct success. Diagnostics alone, a different legacy failure, or aggregate gains are insufficient.

This is the second bounded Code + Build attempt. If the artifact-only turn does not materially advance Gate 1, the next mandatory turn is a design review or bounded producer replacement proof.

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
