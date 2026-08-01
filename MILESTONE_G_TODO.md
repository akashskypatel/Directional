# Milestone G Production Readiness TODO

Last updated: 2026-08-01
Branch: `surface_cell_quad`
Target fixture: `benchmark-results/bunny_1k_random.obj`

## Success criteria

- Produce a conforming, manifold, source-faithful pure-quad mesh for the random-triangulated bunny.
- Preserve cross-field alignment, authoritative feature rails, source-sheet separation, and singularity ownership.
- Reject unsupported/non-disk topology honestly; do not convert failures into synthetic success.
- Keep focused unit/integration tests representative of their stated contracts.
- Pass focused Milestone G tests, Phase 15–20 integration tests, mesh connectivity validation, and the bunny benchmark locally.

## Work phases

- [x] P0 — Establish reproducible local source and dependency snapshot.
- [x] P1 — Review Milestone G plan, failed-fix notes, current checkpoint patches, and benchmark/test harness.
- [~] P2 — Reproduce the current bunny failure and capture stage/cell diagnostics. Debug benchmark is reproducible but too slow; optimized run remains pending.
- [x] P3 — Restore required nonempty singular separatrix prefixes with fail-closed termination rules.
- [x] P4 — Implement and validate balanced regular-disk quadrangulation for high-side even boundaries.
- [ ] P5 — Diagnose and implement remaining non-disk/transition-sector completion cases without weakening validation. **In progress**
- [ ] P6 — Validate topology, provenance, source projection, field alignment, determinism, and quality metrics.
- [ ] P7 — Run focused and broader regression tests; repair only real implementation or fixture defects.
- [ ] P8 — Run final bunny benchmark and document production-readiness evidence and remaining limitations.

## Current checkpoint

- Corrected Milestone G P26 fixture tests so the fieldless random bunny exercises the library-calculated cross-field path instead of passing an empty raw field. Prescribed-field-only tests still cover all eight paired field fixtures.
- Applied the narrow singular-separatrix contract change: nonempty required prefixes terminated by later geometric degeneracy remain explicit completion obligations; invalid field metadata and source-sheet terminations remain unusable.
- Added focused tests for both retained degenerate prefixes and fail-closed metadata/sheet terminations.
- Validation after P3: 6/6 focused tests passed; all 125 Phase 15–18 tests passed.
- Implemented balanced recursive quadrangulation for even regular-disk boundaries with more than six logical sides. It preserves the complete boundary, emits exactly `n/2 - 1` quads, distributes diagonal endpoints, and keeps unsupported non-disk/singular cases fail-closed.
- Validation after P4: 2/2 focused topology tests passed; all 127 Phase 15–18 tests passed.
- Test evidence: `build/mg-debug/p3-focused.json`, `build/mg-debug/p3-phase15-18.json`, `build/mg-debug/p4-focused.json`, `build/mg-debug/p4-phase15-18.json`.
- Next action: run the optimized random-bunny pipeline to identify the first remaining completion/validation failure after P3–P4.

- Local archive HEAD matches remote commit `92db9c701fb9f0cdba3cd3127ebecccf7c77e410`.
- Recursive submodules are present.
- Working-tree CRLF archive noise was verified as end-of-line-only and normalized locally.
