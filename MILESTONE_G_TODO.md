# Milestone G Production Readiness TODO

Last updated: 2026-08-06

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Active gate: **G1 — Uniform phase-front plane**.
- Completed turn: **Gate 1 Uniform Phase-Front Artifact-Only Test + Benchmark**.
- Next turn: **Gate 1 Phase-Front Orientation and Direct-Cell Materialization Code + Build**.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.

## Runtime authority

- tested artifact SHA-256: `7e520acda5d402300711d1803a666e505ce4a03c0b92d969f5ae2ba3ca2d1f28`;
- internal checksums: **47/47**;
- exact source composition: base `e82fb47dccbefa1b878bc9ddff0ae63745f6efe9` plus patch blob `aa18d454877ccf40d16f71f173fdaf765f5f1086`;
- no rebuild or source/test/fixture/validator edit occurred;
- GitHub workflow usage during this turn: none.

## Direct gate result

- [ ] plane — 352 traces, 65 arrangement cells, 409 quads; `completion/output-validation:FlippedFace`, cell 38, source face 41, 100 validation failures;
- [ ] multi-face seam — 137 traces, zero cells/quads; `SideSubdivisionRepair:InvalidInputIncidence`;
- [ ] close sheets — 158 traces, zero cells/quads; `SideSubdivisionRepair:InvalidInputIncidence`;
- [ ] cylinder — 732 traces, zero cells/quads; `SideSubdivisionRepair:InvalidInputIncidence`.

The plane phase-front path is live and deterministic, but its winding/incidence and direct-cell materialization are not valid.

## Default-suite result

- direct acceptance: **0/4**;
- remaining producer: **77/79**;
- completion: **154/164**;
- validation: **60/60**;
- compiled API: **8/8**;
- total: **299/315**.

## G1 current subgate

- [x] first-class phase, lattice coordinates, branch rotation, and scale level;
- [x] directed front-edge state and bounded planar grid;
- [x] compatible merge and boundary termination events;
- [x] deterministic phase-front hashing;
- [x] authoritative proposal-cycle arrangement path;
- [x] phase-front data consumed by arrangement and completion;
- [ ] source-normal-consistent cell winding;
- [ ] ordered side and corner incidence validation before materialization;
- [ ] exactly one filled side or exterior classification per directed edge;
- [ ] one accepted four-sided phase-front cell materializes as one quad-domain cell;
- [ ] plane direct strict validation;
- [ ] pure-quad `CompletedSurfaceCells` success without fallback/recovery.

## Next Code + Build

- [ ] implement the orientation/incidence contract;
- [ ] reverse complete cell cycles transactionally when required;
- [ ] bypass generic patch expansion for authoritative four-sided phase-front cells;
- [ ] correct the two stale producer tests while preserving real recovery coverage;
- [ ] compile only the seven approved targets;
- [ ] run no generated binary.

## Remote source synchronization backlog

Keep this open until GitHub service recovery:

- [ ] commit the exact five current implementation blobs;
- [ ] verify each blob against `TODO`;
- [ ] do not use a workflow while the outage persists;
- [ ] keep the exact patch payload versioned until synchronization is complete;
- [ ] remove payloads only after exact verification.

## Gate order

G0 truthful authority [passed] → G1 plane [active] → G2 seam/close sheets → G3 cylinder → G4 topology/singularities → G5 adaptivity/features → G6 bunny → G7 hardening.

Do not begin a blocked gate.

Every completed turn ends with a new top-level PR #8 comment after all other writes.

P5 remains open.
