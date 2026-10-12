# M6-CP3-CB1-ENTRY-R4 — RA-47 typed rail source-edge implementation WIP (2026-10-12)

**Boundary:** continuing Code + Build. This record describes source-only implementation; no test or benchmark was executed. Direct TB497 is forbidden until its own authorized turn.

## Exact source and work

Verified source snapshot `1bcc068cb3be7d994caa537307e61c5aabe2e646`, workflow `38270791118`, artifact `11756652418`, ZIP SHA-256 `b9d1b75358bd2a7d74c87d3cb3429982e6d61179efbf646586d268cf74312f5b`, 6,464 file checksums verified. PR #8 is draft; working branch `agent/surface_cell_quad/p5-recover-bridge-healing`.

RA-47 code changes (pending GitHub compile at time of patch preparation):

- `SurfaceCellRail::sourceEdges` is typed `SourceEdgeTopologyKey` rather than raw indices; authoritative producer uses validated interval endpoint pairs.
- Feature-map ordinals remain independent for `coveredEdges`, `failedEdgeIndex`, and producer-local diagnostic bookkeeping.
- Network consumer compares the typed key against the independently re-derived source-vertex-chain interval and retains `InvalidRailGeometry` first rejection.
- Rail hash uses typed edge endpoint IDs. Component aggregation regenerates global typed keys after vertex remapping and removes local/global EV-index conversion maps.
- Existing tests adopt typed keys; the one-triangle `(0,2)` rail producer regression explicitly distinguishes feature-map position 1 from DCEL EV position 2. Foreign and closing-key negatives remain.

## Outstanding before closing R4

Exact-source eight-target GMP/GMPXX compile and artifact evidence required before calling RA-47 compile-green; no binary tests/benchmarks run in this turn. A standalone source-level liveness question remains whether the field-aligned consumer is reached with producer-built rails on the default path (RA-47.12); it has not been proved here. Other R4 obligations include RA-48.3 closing TriMesh::set_mesh precomputed-EV injection validation, RA-48.5/RA-46.6 typed factory error details, RA-43.1/.2/.4, RA-46.5, and exact first-rejection coverage. Overfull-three-face A3 remains mathematically retired only under RA-48 guards, not runtime-passed. CP2 491/491 accepted, R3 403/497 rejected (94 RED / 88 losses), stable ledger 66/17/49, debt 1; no new runtime credit.

No successor is begun. `M6-CP3-CB1-ENTRY-R4` remains the canonical turn.
