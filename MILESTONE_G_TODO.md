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
- [ ] P1 — Review Milestone G plan, failed-fix notes, current checkpoint patches, and benchmark/test harness. **In progress**
- [ ] P2 — Reproduce the current bunny failure and capture stage/cell diagnostics.
- [ ] P3 — Restore required nonempty singular separatrix prefixes with fail-closed termination rules.
- [ ] P4 — Implement and validate balanced regular-disk quadrangulation for high-side even boundaries.
- [ ] P5 — Diagnose and implement remaining non-disk/transition-sector completion cases without weakening validation.
- [ ] P6 — Validate topology, provenance, source projection, field alignment, determinism, and quality metrics.
- [ ] P7 — Run focused and broader regression tests; repair only real implementation or fixture defects.
- [ ] P8 — Run final bunny benchmark and document production-readiness evidence and remaining limitations.

## Current checkpoint

- Local archive HEAD matches remote commit `92db9c701fb9f0cdba3cd3127ebecccf7c77e410`.
- Recursive submodules are present.
- Working-tree CRLF archive noise was verified as end-of-line-only and normalized locally.
- Next action: inspect Milestone G notes and recover the two staged patch payloads into reviewable diffs before applying any implementation change.
