# Milestone G Production Readiness TODO

Last updated: 2026-08-06

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Active gate: **G2 — Cross-chart and close-sheet propagation**.
- Completed turn: **Gate 1 Phase-Front Orientation Artifact-Only Test + Benchmark**.
- Next turn: **Gate 2 Cross-Chart and Close-Sheet Propagation Code + Build**.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.

## Runtime authority

- tested artifact SHA-256: `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`;
- evidence archive SHA-256: `458afe01241e8bf0c4623b5064f00eb294b17ffe99b9e34188625c14fbd0f074`;
- internal checksums: **45/45**;
- source commits: `4842911b6134c60410c92496d85d1152164a73c7` then `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- no rebuild or source/test/fixture/validator edit occurred;
- all direct and benchmark processes executed the packaged artifact directly.

## Gate result

- [x] plane — direct success; 352 traces, 65 arrangement cells including exterior, 64 direct cells, 64 pure output quads, zero validation failures, `CompletedSurfaceCells`, no fallback/recovery;
- [ ] multi-face seam — 137 traces, zero cells/quads; `SideSubdivisionRepair:InvalidInputIncidence`;
- [ ] close sheets — 158 traces, zero cells/quads; `SideSubdivisionRepair:InvalidInputIncidence`;
- [ ] cylinder — 732 traces, zero cells/quads; blocked by Gate 2.

Plane stage counts, stage hashes, and output hash `730caeae49ec872c` were identical across three independent processes.

## Default-suite result

- direct acceptance: **1/4**;
- remaining producer: **78/79**;
- completion: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- total: **301/315**.

## G1 closure

- [x] first-class phase, lattice coordinates, branch rotation, and scale level;
- [x] directed front-edge state and bounded planar grid;
- [x] source-normal-consistent winding and whole-cycle reversal;
- [x] four-corner/side/component/sheet/ownership validation;
- [x] exactly one filled side or exterior classification per directed edge;
- [x] one accepted four-sided cell maps to one output quad;
- [x] plane direct strict validation;
- [x] pure-quad `CompletedSurfaceCells` success without fallback/recovery.

## G2 current subgate

- [ ] carry exact source-chart identity in the constructive state;
- [ ] use exact source-topology transitions rather than global planar projection;
- [ ] transport cross-field quarter-turn branch matching;
- [ ] transport phase and integer lattice coordinates across faces;
- [ ] preserve component, local-sheet, family/sign, and source-route provenance;
- [ ] require reciprocal inverse transitions;
- [ ] construct nonzero authoritative cells on the multi-face seam;
- [ ] merge only phase-compatible reciprocal fronts;
- [ ] prevent cross-sheet capture on close sheets;
- [ ] preserve direct one-cell-to-one-quad materialization;
- [ ] multi-face seam direct success;
- [ ] close sheets direct success.

## Next Code + Build

Use `.agents/Directional/Gate_2_Cross_Chart_Close_Sheet_Code_Build_Plan.md`.

Compile only the approved seven targets and execute no generated binary. Keep Gate 3 cylinder periodic logic and all later gates deferred.

## Gate order

G0 truthful authority [passed] → G1 plane [passed] → G2 seam/close sheets [active] → G3 cylinder → G4 topology/singularities → G5 adaptivity/features → G6 bunny → G7 hardening.

Every completed turn ends with a new top-level PR #8 comment after all other writes.

P5 remains open.
