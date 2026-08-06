# Milestone G Production Readiness TODO

Last updated: 2026-08-06

## Active phase

- Phase: P5 — producer-correct direct surface paving.
- Branch: `agent/surface_cell_quad/p5-recover-bridge-healing`.
- Draft PR: #8; keep open, draft, and unmerged.
- Review policy: `never`.
- Completed turn: **P5-TB42 artifact-only R2E14 Test + Benchmark**.
- Next turn: **P5-R2E15 chart-local lifted interval authority Code + Build**.
- P5-R2E14 is not accepted.
- R2 remains open. Do not advance to R2F or R3.

## P5-TB42 runtime authority

- Exact tested source: `2a8b9870b8e3854ae77a7e4eeae6da29a7899968`.
- Artifact `8958361834`, SHA-256 `1f2607859ecf84d2cb82597f2c4f8f9341491df62d99b694510241f8df719db6`, size **12,307,622 bytes**.
- Manifest **20/20**; package files **21**; recursive submodules **9**; source status empty; executable-relative fixtures **26**.
- Only packaged binaries executed. No configure, rebuild, relink, patch, regeneration, implementation/test/fixture/validator/workflow/build change, or binary replacement.
- Evidence archive SHA-256: `41a2a7b58cc16ac96944a796a67d6a42ec00559b86a6cdb6991e0e9b04500fa3`.

## P5-TB42 focused disposition

- Planar, three byte-identical runs:
  - `BoundaryFanSectorCoverConflict / InvalidOrientedInterval(8)`;
  - tuple `3/5/4/9`;
  - canonical pairs **3**;
  - exterior exclusions **1**;
  - cyclic-wrap sectors **0**.
- Interior hard rail, three byte-identical runs:
  - advanced from P5-TB41 `ExteriorPairMismatch(2)` to `InvalidOrientedInterval(8)`;
  - tuple `1/5/4/1`;
  - publication counters remain zero because interval resolution fails before candidate publication.
- The earliest common remaining producer is chart interval normalization for an already-authoritative non-exterior pair.
- Do not infer separator, orbit, Euler, or topology validity beyond the first rejection.

## Current runtime results

- source chart + validator **17/17**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**;
- R2 focused **13/16**;
- Milestone D **5/7**;
- Phase 16 **45/47**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 14–18 **235/244**;
- Phase 20 **46/48**;
- normal single-process full suite **597/625**, 28 failures, 0 errors, 0 disabled;
- complete split inventory **597/625**, exact same 28 failures as P5-TB41.

The single-process 625-test run completed normally in **74.23 s** with maximum RSS **282,848 KiB**. The prior P27/bunny cumulative-state stop was not reproduced and remains historical performance evidence, not correctness evidence.

All direct plane, seam, close-sheet, cylinder, and bunny processes remain `success=false` under backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution. Structural lineage is deterministic within each measured case.

## Required P5-R2E15 work

- [ ] preserve node-level canonical pair existence and exact normalized entity/root ownership;
- [ ] preserve R2E14 endpoint-specific excluded exterior charts, roots, sides, and provenance;
- [ ] keep every non-exterior pair's one exact common transition root;
- [ ] use the existing unique wedge-local lifted angle as the sole chart interval coordinate;
- [ ] retain and validate the integer lift turn for each ray;
- [ ] remove the second raw-global-angle adjacency authority;
- [ ] require exact directed adjacency in lifted chart order;
- [ ] reject reverse order, non-adjacency, third-ray intrusion, unsupported turn differences, non-positive span, and span outside the chart wedge;
- [ ] set `cyclicWrap` only from an exact one-turn source/target lift difference for a valid adjacent pair;
- [ ] keep raw angle only as diagnostic provenance;
- [ ] preserve complete witness, cover, predecessor, exterior exclusion, hard-rail separator, bounded-orbit, embedding, disk, Euler, orientation, area, ownership, and aggregate topology gates;
- [ ] compile exactly the four approved targets;
- [ ] execute no project binary in the Code + Build turn;
- [ ] produce P5-TB43 artifact-only validation authority.

## Current authority

- `.agents/Directional/Milestone_G_P5_TB42_Artifact_Only_R2E14_Test_Benchmark_Report.md`
- `.agents/Directional/Milestone_G_P5_R2E15_Chart_Local_Lifted_Interval_Authority_Code_Build_Plan.md`
- `benchmark-results/p5-tb42-summary.json`
- `.agents/Directional/Future_Chat_Session_Handoff.md`
- durable design, reorientation, remediation, and workflow-policy documents
- `MILESTONE_G_TODO.md`

Every completed turn ends with a final top-level PR #8 handoff comment after all documentation and PR metadata writes.

P5 remains open.
