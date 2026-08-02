# Milestone G Production Readiness TODO

Last updated: 2026-08-02 15:22 PDT
Base branch: `surface_cell_quad`
Target fixture: `benchmarks/fixtures/milestone-g/bunny_1k_random.obj`

## Active implementation branch

- Phase: P5 — resolve duplicate authoritative patch ownership during direct completion.
- Working branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: `#8` (`agent/surface_cell_quad/p5-recover-bridge-healing` → `surface_cell_quad`).
- Verified entry checkpoint: `c84e2e1d64e867e5975f414780f9c81e649612fb`.
- Exact implementation/build checkpoint: `d4c1bce4338b7f2e91264c349a73b6b260e80f54`.
- Compile-only workflow run: `30769701224` — **success**.
- Build artifact: `8840174777`, `surface-cell-p5-branch-linux-release`.
- Artifact digest: `sha256:a5659e86e0f1e90129d1b085e25ed0f2afff0ea882a43304fae15a5f18b9970a`.
- Next authoritative turn: **test and benchmark**. Do not modify code until the compiled checkpoint is classified.

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
- [x] P5-CB1 — Add canonical domain and stitch-vertex ownership identities.
- [x] P5-CB2 — Detect duplicate/overlapping arrangement ownership before completion with typed failure.
- [x] P5-CB3 — Stitch only equal authoritative identities; keep generated interiors patch-local.
- [x] P5-CB4 — Preserve duplicate validation and add ownership classification/hashes.
- [x] P5-CB5 — Add generalized ownership/ordering regression sources and compile them.
- [ ] P5-CB6 — Complete pipeline/structural-hash propagation after the next execution identifies any remaining gap.
- [ ] P6 — Validate topology, provenance, source projection, field alignment, determinism, and quality metrics.
- [ ] P7 — Run focused and broader regression tests; repair only real implementation or fixture defects.
- [ ] P8 — Run final bunny benchmark and document production-readiness evidence and remaining limitations.

## Current checkpoint

- The prior deterministic direct failure remained `DuplicateStitchedQuad` between source patches 241 and 255, with every descriptor completed and zero unresolved required endpoints.
- Patch descriptors now carry canonical orientation-aware arrangement-domain identity, source-support identity, component/sheet scope, and canonical boundary-node identities.
- Repeated oriented-domain ownership and overlapping undirected boundary ownership fail before completion instead of reaching global duplicate output.
- Global stitching now uses authoritative identity rather than raw local vertex number or positional coincidence; generated interior vertices are patch-qualified.
- Final duplicate global-quad validation remains transactional and reports both source patches plus typed ownership hashes.
- Regression sources cover reordered sparse duplicate IDs, source-face row order, coincident separate sheets, patch-local interiors, authoritative shared boundaries, patch-order invariance, active duplicate detection, and inconsistent shared geometry.
- `directional_core`, `directional_pipeline`, `directional_phase1_tests`, and `directional_benchmarks` compiled in a clean Release build.
- No test, benchmark, or custom mesh executable ran in this turn.
- The exact original bunny pair has not yet been executed against the new diagnostic, so P5 remains open.

## Next test and benchmark turn

- Verify artifact `8840174777` records source commit `d4c1bce4338b7f2e91264c349a73b6b260e80f54`, a clean source status, and the expected submodule revisions.
- Run the new minimized ownership/identity regressions.
- Run `SurfaceArrangementPhase16.*`, `PatchDescriptorMilestoneE.*`, and `PureQuadCompletionPhase18.*`.
- Run focused Phase 14–18, Milestone G P23, and Phase 20 fail-closed suites.
- Run direct `bunny_1k_random.obj` with source-grid recovery disabled and repeat it for determinism.
- Record whether the former pair is classified as duplicate-domain, overlapping-boundary, false-merge, or completion-template ownership.
- Record completed/rejected descriptor counts, required endpoint counts, structural hashes, runtime, peak memory, and whether assembly advances past the previous duplicate.
- Make no code changes during that turn. Its results determine whether P5 closes or another code/build phase is required.
