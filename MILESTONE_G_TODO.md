# Milestone G Production Readiness TODO

Last updated: 2026-08-02 12:45 PDT
Branch: `surface_cell_quad`
Target fixture: `benchmark-results/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — resolve remaining direct-completion bridge/pinch topology defects.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: `#8` (`agent/surface_cell_quad/p5-recover-bridge-healing` → `surface_cell_quad`).
- Materialized source commit: `bb78dbe52fc4dbba74b220334c67cbde3305d04a`.
- Final direct-source build commit: `4c702c6a7ee7ba39ceab1aee0a1f8f9123c8425b`.
- Final build run: `30763728058`.
- Final build artifact: `8838345026`, digest `sha256:add7ff0934a07ca599f017832e61d2e0d6d29787003ba7719d1f6449ed21e285`.
- Recovery status: complete. The implementation is committed as ordinary files; encoded WIP checkpoints and build overlays are removed.
- Next authoritative turn: test and benchmark. Do not modify code until that turn classifies the compiled checkpoint.

## Success criteria

- Produce a conforming, manifold, source-faithful pure-quad mesh for the random-triangulated bunny.
- Preserve cross-field alignment, authoritative feature rails, source-sheet separation, and singularity ownership.
- Reject unsupported/non-disk topology honestly; do not convert failures into synthetic success.
- Keep focused unit/integration tests representative of their stated contracts.
- Pass focused Milestone G tests, Phase 15–20 integration tests, mesh connectivity validation, and the bunny benchmark locally.

## Work phases

- [x] P0 — Establish reproducible local source and dependency snapshot.
- [x] P1 — Review Milestone G plan, failed-fix notes, current checkpoint patches, and benchmark/test harness.
- [x] P2 — Reproduce the current bunny failure and capture stage/cell diagnostics.
- [x] P3 — Restore required nonempty singular separatrix prefixes with fail-closed termination rules.
- [x] P4 — Implement and validate balanced regular-disk quadrangulation for high-side even boundaries.
- [ ] P5 — Resolve required singular-support endpoints and remaining direct-completion failures without weakening validation. **In progress**
- [x] P5A — Make SurfaceCells fail closed without invoking legacy integration or meshing.
- [ ] P6 — Validate topology, provenance, source projection, field alignment, determinism, and quality metrics.
- [ ] P7 — Run focused and broader regression tests; repair only real implementation or fixture defects.
- [ ] P8 — Run final bunny benchmark and document production-readiness evidence and remaining limitations.

## Current checkpoint

- All required singular-support endpoints were resolved without deleting required topology.
- Arrangement-consistent endpoint interception and scale-aware pre-ring return rerooting reduced the direct random-bunny completion result to two complex repeated-node pinches before the latest intrinsic fan-ordering change.
- The latest implementation adds generalized intrinsic ordering of outgoing arrangement halfedges around source vertices using source-triangle fan connectivity, source component/sheet scope, and intrinsic corner angles. It contains no fixture-name, bunny vertex-ID, rejected-cell-ID, or expected-count special cases.
- Duplicate stitched-quad failures now report both authoritative source patches and local quad identities.
- The ordinary-source branch compiles successfully with shallow recursive submodules. `directional_phase1_tests`, `directional_benchmarks`, `libdirectional_core.a`, and `libdirectional_pipeline.a` were produced.
- No tests or benchmarks were run in the code/build turn.

## Next test and benchmark turn

- Verify artifact `8838345026` records source commit `4c702c6a7ee7ba39ceab1aee0a1f8f9123c8425b`.
- Run the minimized intrinsic source-vertex fan regression.
- Run the duplicate stitched-quad diagnostic regression.
- Run focused Phase 14–18 tests.
- Run P23 and Phase 20 fail-closed backend tests.
- Run the fast direct `bunny_1k_random.obj` benchmark with source-grid recovery disabled.
- Record direct completed/rejected descriptor counts, exact rejected-cell provenance, required endpoint counts, deterministic hashes, runtime, and peak memory.
- Make no code changes during that turn. Its results determine whether P5 closes or another code/build phase is required.
