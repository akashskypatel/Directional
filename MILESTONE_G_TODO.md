# Milestone G Production Readiness TODO

Last updated: 2026-08-06

## Active phase

- P5 producer-correct direct surface paving.
- G1 plane: **passed**.
- G2 cross-chart and close-sheet propagation: **active**.
- Completed: Gate 2 Cross-Chart Transport and Mandatory Production Fixtures Code + Build.
- Next: artifact-only validation of the six mandatory direct fixtures.
- PR #8 remains open, draft, and unmerged; review policy `never`.

## Compile authority

- source commit `21f081b330418a0f34709f61d857f54a03d2fd48`;
- cleanup commit `98fe525bb46f348cddcad91b0525353796b9e061`;
- artifact SHA-256 `f5c2be0e2131dbce7a6460e3c61da2de57f7d256c00a5401ac6285d6a0145755`;
- 45/45 checksums, 5 executables, 2 libraries, 27 fixture files;
- 7/7 approved targets, 95/95 compile/link actions;
- no generated binary executed.

## Mandatory fixture gates

- [x] plane established regression;
- [ ] multi-face seam;
- [ ] close sheets;
- [ ] cylinder;
- [ ] randomized bunny production mesh;
- [ ] open-boundary vase production mesh.

Bunny and vase are mandatory correctness fixtures, not demonstrations. Their exact topology and hashes are asserted. Both use generated smooth cross fields and the ordinary direct `SurfaceCells` pipeline.

## Gate 2 state

- [x] source-chart and transition-edge provenance in constructive trace state;
- [x] per-face transported branch rotation;
- [x] reciprocal quarter-turn transition validation;
- [x] deterministic chart construction on the current planar transport slice;
- [x] chart/transition hashing;
- [ ] nonzero authoritative seam cells under artifact execution;
- [ ] seam success;
- [ ] close-sheet isolation success;
- [ ] general non-planar chart transport for production fixtures;

## Next test turn

Verify the artifact and all checksums, then run in order: plane, seam, close sheets, cylinder, bunny, vase. Run all six even when an earlier gate fails, but do not use later results to bypass gate order.

Every completed turn ends with a new top-level PR #8 comment after all other writes.

P5 remains open.
