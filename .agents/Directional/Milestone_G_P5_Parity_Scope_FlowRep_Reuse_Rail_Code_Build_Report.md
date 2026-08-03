# Milestone G P5-CB83 through P5-CB90 Code + Build Report

**Updated:** 2026-08-03  
**Repository:** `akashskypatel/Directional`  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged

## Exact checkpoint

- Source implementation commit: `57be334c7a5d41538dcfd7011f429da525d2d2ca`.
- Exact clean compiled source: `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`.
- Compile-only workflow run: `30849904147` — **success**.
- Artifact: `8870351914`, `surface-cell-p5-cb90-parity-flowrep-reuse-rail-linux-release`.
- Artifact digest: `sha256:ce6ca28d8eb41562c3486077934302643100fab575f34ea8a341e3212964a7e4`.
- Temporary source-transfer workflows and patch payloads were removed before the authoritative clean build.

## Implemented

### P5-CB83 — high-cardinality FlowRep ownership

- Removed stale references across `FlowRepArc` vector growth by reacquiring the authoritative arc after insertion.
- Preserved deterministic input, sparse selection, and endpoint-completion ownership under vector reallocation.
- Added a high-cardinality regression source that forces reallocation instead of relying on incidental capacity.

### P5-CB84 — authoritative parity scope

- Replaced dominant-frequency scope voting with the exact source scope inherited from the pre-transaction cell.
- Replacement pieces and twins now retain one authoritative component/sheet scope through the parity transaction.
- Mixed-scope rejection remains fail-closed and reports the selected and available scopes.

### P5-CB85 — exact semantic completion reuse

- Reworked reusable-product identity around canonical authoritative source-domain dependencies.
- Removed allocation-local cell identity and regenerated arrangement numbering from the reuse key.
- Canonicalized cyclic and reversed boundary dependency order while preserving exact source ownership.

### P5-CB86 — final rail and provenance propagation

- Preserved rail identity independently from the cell-level component/sheet scope selected during final arrangement rebinding.
- Final oriented halfedges retain authoritative `railId`, `curveId`, feature class, and rail parameters from complete provenance.
- Retained the stage-six arrangement in diagnostic context so rail lineage is inspectable at the intended stage boundary.

### P5-CB87 — valid regression fixtures

- Split missing-common-chart and invalid-midpoint behavior into separate valid fixtures.
- The invalid-midpoint fixture now keeps one exact chart and scope but constructs a non-normalizable midpoint after transactional mutation begins.
- Rebuilt the cylinder simplification fixture so each intrinsic source edge is represented once instead of by coincident per-face duplicates.

### P5-CB88 — production producer corrections

- Applied source-supported ownership, rail, scope, and lifetime corrections used by the plane, cylinder, seam, torus, and mechanical-feature producer paths.
- Full production-output disposition is intentionally deferred to P5-TB16; this compile-only turn does not claim runtime closure.

### P5-CB89 — complete stage-owned memory telemetry

- Added current and peak owned-byte accounting for tracing, FlowRep, arrangement, and simplification.
- Added maximum simultaneous live-large-structure telemetry and explicit release flags at stage boundaries.
- Counted nested vector capacities and relevant container payload ownership without double-counting moved buffers.
- Released superseded trace, FlowRep-selection, embedded-arrangement, and simplification-candidate storage at authoritative handoff points.
- Serialized and aggregated the new telemetry through pipeline and benchmark diagnostics.

### P5-CB90 — regression sources and compile/package gate

- Added and strengthened regression sources for reallocation safety, exact scope inheritance, semantic reuse, rail lineage, valid midpoint failure, cylinder incidence, and ownership telemetry.
- Removed all temporary source-transfer files before the final authoritative build.

## Compile evidence

The clean optimized static build configured successfully with Ninja and compiled only:

- `directional_core`;
- `directional_pipeline`;
- `directional_phase1_tests`;
- `directional_benchmarks`.

The workflow also verified:

- clean source status;
- shallow recursive submodule closure;
- required benchmark fixture closure, including `bunny_1k_random.obj`;
- packaged libraries, executables, source archive, logs, and file checksums.

No test executable, benchmark executable, custom mesh command, help/list command, or discovery command ran during this turn.

## Disposition

P5 remains open. Compilation proves source and link validity only; it does not prove runtime correctness or production readiness.

The next authoritative turn is **P5-TB16 artifact-only test and benchmark** using artifact `8870351914` directly without rebuilding. It must validate the FlowRep crash, parity scope, positive reuse, final rail identity, corrected fixtures, production outputs, determinism, wall time, and memory telemetry.
