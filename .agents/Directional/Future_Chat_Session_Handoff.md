# Directional Surface-Cell Quadrangulation — Session Handoff

**Updated:** 2026-08-04  
**Repository:** `akashskypatel/Directional`  
**Base:** `surface_cell_quad`  
**Working branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Current checkpoint

P5-TB29 artifact-only validation is complete against exact source `de0aa1a58a5861954dc9e14e731e681b5e5feb87` and artifact `8914900872`.

R2E does not close an additional runtime gate. The complete suite remains **595/623** with the same 28 failures as P5-TB28. Exact source-side evidence now fails the hard-rail case closed with `BoundaryLoopOwnerCount`, but the implementation still applies source-loop cardinality to generic raw successor orbits rather than constructing the authoritative exterior continuation.

The next turn is **P5-R2E2 authoritative boundary-exterior successor construction plus compile-only build**. Do not advance to intrinsic-fan R2F or R3.

## Read first

1. `TODO`
2. `MILESTONE_G_TODO.md`
3. `.agents/Directional/Milestone_G_P5_TB29_Artifact_Only_R2E_Test_Benchmark_Report.md`
4. `.agents/Directional/Milestone_G_P5_R2E2_Boundary_Exterior_Orbit_Code_Build_Plan.md`
5. `benchmark-results/p5-tb29-summary.json`
6. `.agents/Directional/Milestone_G_P5_R2E_Code_Build_Report.md`
7. `.agents/Directional/Milestone_G_P5_R2E_Test_Benchmark_Plan.md`
8. `.agents/Directional/REORIENTATION_PLAN.md`
9. `.agents/Directional/DESIGN.md`
10. `.agents/Directional/GitHub_Workflow_Policy.md`

## P5-TB29 package authority

- exact tested source: `de0aa1a58a5861954dc9e14e731e681b5e5feb87`;
- implementation commit: `f5afd014cced8205d485bea4f1470725e1fd8be1`;
- workflow event commit: `2a40add65b13137d4d7183e0715c6807dbd6a10a`;
- artifact: `8914900872`, `surface-cell-p5-r2e-corrected-github-source-linux-release`;
- artifact SHA-256: `418518d879ec8686296ed3dd30d24e3b9e3b9df4280278996292fa1eba4d1d1c`;
- workflow-log artifact: `8914901042`, SHA-256 `351462cc5e3c72440fd2933bb31e3c2c63ee8560b61af20b9de8361a6713e0a3`;
- empty source status;
- recursive checksums **45/45**;
- package files **46**;
- fixtures **26**;
- recursive submodules **9**;
- all four target hashes verified;
- one base workflow and zero temporary patch payloads;
- no configure, rebuild, relink, patch, regeneration, or source modification during validation.

## Runtime summary

- source-chart R1 **11/11**;
- Phase 22 validator **6/6**;
- recovery authority **9/9**;
- feature/barrier authority **8/8**;
- graph-dependent **5/6**;
- R2/R2C/R2D/R2E focused **11/14**;
- Milestone D **5/7**;
- Phase 14–18 **233/242**;
- Phase 16 **43/45**;
- Phase 17 **20/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48**;
- direct plane/seam/close sheets/cylinder **0/4**;
- complete suite **595/623**, 28 failures, **200.707 seconds**.

The full-suite failure set is identical to P5-TB28. Exact maximum RSS is unavailable because the outer timing wrapper detached; sampled RSS reached at least **204,108 KiB**. XML and complete logs finalized normally.

## Earliest remaining producer

`SourceBoundaryTopology` currently stores unordered edge membership only. The implementation first forms generic directed-wedge successor orbits, labels those raw orbits with source-side evidence, and then requires one negative-side raw orbit per source loop.

This is invalid when boundary-ending traces or hard rails split the exterior continuation at a source-boundary vertex. The hard-rail test now exposes the issue as `BoundaryLoopOwnerCount`; cylinder publication is cleared and leaves `cell == -1`; planar still has no exterior orbit, Euler `-1`, and area error `1`.

P5-R2E2 must:

1. retain ordered authoritative source-boundary loops;
2. inventory exact boundary subsegments and their edge parameters;
3. construct exterior `next` pointers directly from source-loop order before orbit audit;
4. bypass interior hard-rail wedges only for the exterior-side continuation;
5. audit and publish exactly one exterior cell per source loop transactionally;
6. preserve R2E structural Euler accounting after valid publication.

Do not merge or decompose cells after orbit extraction.

## Direct analytic disposition

All cases used `SurfaceCells`, fallback `Fail`, recovery disabled, and no legacy execution.

- plane: 9 arrangement cells, 12 quads, 15 output-validation failures;
- multi-face seam: 0 cells/quads, `NotProductionReady/completion`;
- close sheets: 0 cells/quads, `NotProductionReady/completion`;
- cylinder: 0 cells/quads, `NotProductionReady/completion`.

## First actions for P5-R2E2

1. Confirm the branch descends from this documentation commit and contains only base workflows and no patch payloads.
2. Read the P5-TB29 report and R2E2 plan.
3. Inspect `SourceBoundaryTopology`, boundary rail subdivision/provenance, directed-wedge successor assignment, and pre-publication orbit audit.
4. Add ordered source-loop and exact subsegment continuation authority.
5. Override only exterior boundary-halfedge successors before complete orbit audit.
6. Preserve interior wedge successors and every passing R2C/R2D/R2E contract.
7. Keep bunny singularity-fan work deferred because its fixture disables boundary rails.
8. Commit and push before compiling.
9. Compile exactly the four required targets and execute no project binary.
10. Always upload a separate detailed workflow-log artifact and verify the recursive manifest before upload.

## Mandatory working-branch hygiene

At the start and end of every Code + Build turn:

- remove every superseded workflow, trigger marker, patch fragment, patch README, generated transfer file, and temporary build artifact;
- retain only base workflows plus the single bounded active workflow/payload while a remote build is running;
- self-remove the active workflow/payload from the exact compiled source or delete it immediately in the handoff commit;
- verify the final branch and packaged source contain no stale temporary artifacts;
- never leave historical workflow YAML on the working branch;
- generate checksum manifests outside the package and never include a manifest in its own checksum input.

## Key lessons

- Fail-closed owner-count evidence is useful, but cardinality cannot repair an incorrect raw successor partition.
- Exterior continuation is authoritative source topology and must be installed before generic orbit audit.
- Interior hard rails may partition bounded cells but cannot partition the exterior of a source boundary loop.
- Structural Euler accounting cannot be validated while publication is cleared.
- The bunny fan remains an independent R2 producer and must not broaden the boundary turn.
- Stale workflows and malformed artifact manifests are active failure sources; remove and verify them every CB turn.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition or cell merging;
- no timeout-as-correctness.
