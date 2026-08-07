# Milestone G Production Readiness TODO

Last updated: 2026-08-06

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Active gate: **G1 — Uniform phase-front plane**.
- Completed turn: **Gate 1 Phase-Front Orientation and Direct-Cell Materialization Code + Build**.
- Next turn: **Gate 1 Phase-Front Orientation Artifact-Only Test + Benchmark**.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.

## Source and build authority

- [x] uniform phase-front source synchronized at `4842911b6134c60410c92496d85d1152164a73c7`;
- [x] orientation/direct-cell source synchronized at `b2b826eeb975e913f31516c5dd3e6d0a0b554d9e`;
- [x] payload cleanup commit `54a79a17f48bd3974367c3e043507d0550fb8daa`;
- [x] final five source/test blobs verified;
- [x] Release static compile: **7/7** approved targets;
- [x] artifact SHA-256 `e2f81db0a7d84367e052e1ed82c7d5d22c5ef40279d5ef3cd10858761a0a36ca`;
- [x] package closure: 5 executables, 2 libraries, 26 fixtures, 45 checksums;
- [x] no generated binary executed during Code + Build;
- [x] temporary workflows, markers, and synchronized payloads removed.

## G1 implementation checkpoint

- [x] first-class phase, lattice coordinates, branch rotation, and scale level;
- [x] directed front ownership and typed events;
- [x] authoritative proposal-cycle arrangement path;
- [x] four distinct corners and ordered side continuity;
- [x] component/sheet consistency;
- [x] source-normal winding and transactional complete-cycle reversal;
- [x] exactly one filled cell and reciprocal-opposite-or-exterior classification per directed edge;
- [x] one accepted four-sided phase-front cell directly materializes as one quad-domain cell;
- [x] generic completion bypass for authoritative direct cells;
- [x] fail-closed orientation/incidence boundary before completion;
- [x] two stale non-direct producer tests corrected without weakening validation;
- [ ] plane direct acceptance proven by artifact-only execution;
- [ ] pure-quad `CompletedSurfaceCells` output with no fallback/recovery.

## Latest runtime baseline

The preceding artifact remains the runtime comparison authority:

- plane: 352 traces, 65 arrangement cells, 409 quads, `completion/output-validation:FlippedFace`, 100 validation failures;
- seam/close sheets/cylinder: zero cells, `SideSubdivisionRepair:InvalidInputIncidence`;
- direct acceptance: **0/4**;
- non-overlapping default total: **299/315**.

## Next Test + Benchmark

- [ ] verify new artifact SHA-256 and all 45 checksums;
- [ ] verify synchronized source commits and five final blobs;
- [ ] run plane first in a fresh process;
- [ ] report whether one-to-one direct materialization replaces the prior 65-to-409 expansion;
- [ ] report whether `FlippedFace` is eliminated or invalid incidence fails earlier;
- [ ] run seam, close sheets, and cylinder only after plane evidence;
- [ ] run remaining default suites;
- [ ] run three independent bounded benchmark processes per analytic fixture;
- [ ] perform no rebuild or source/test/fixture/validator edit.

## Gate order

G0 truthful authority [passed] → G1 plane [active] → G2 seam/close sheets → G3 cylinder → G4 topology/singularities → G5 adaptivity/features → G6 bunny → G7 hardening.

Do not begin a blocked gate.

Every completed turn ends with a new top-level PR #8 comment after all other writes.

P5 remains open.
