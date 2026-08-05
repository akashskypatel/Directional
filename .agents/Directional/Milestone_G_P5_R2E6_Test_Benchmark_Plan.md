# Milestone G P5-R2E6 Artifact-Only Test/Benchmark Plan

**Date:** 2026-08-05  
**Turn:** P5-TB34 artifact-only R2E6 validation  
**Artifact:** `8936470245`  
**Exact source:** `2444c38b8216656b636f4dad9f8acfa70b86bd41`

## Boundary

Run only packaged binaries and packaged fixtures. Do not configure, build, relink, patch, regenerate, modify source/tests/build logic, or alter fixtures. Preserve raw stdout, stderr, XML, commands, wall time, and RSS evidence. Execute the complete suite exactly once, after all focused scopes.

## Package authority gate

Before executing a packaged binary, require:

- archive SHA-256 `bcc2c0d81e4382368a7fcafe7818c79a2e5bdb23d9a044232a4f3294f4554bf5`;
- exact source `2444c38b8216656b636f4dad9f8acfa70b86bd41`;
- workflow event `6cd5a5c10aa0f15eb5e1312145425395b8a8372d`;
- reviewed/applied diff `e4196fd4ed1a68d31ba6310af8e8a4822533fac3c1f0248f75721521785f8d3d`;
- empty source status;
- recursive manifest **48/48**;
- physical package files **49**;
- fixtures **26**;
- recursive submodules **9**;
- exact target hashes from the Code/Build report;
- cleaned source with only `agent-source-snapshot.yml` and zero payloads;
- exclusion list containing only `.github/workflows/agent-build-p5-r2e6.yml`.

Fail the turn before runtime if any authority item differs.

## Focused execution order

1. Source-chart R1 authority — require **11/11**.
2. Source validator authority — require **6/6**.
3. Recovery authority — require **9/9**.
4. Feature/barrier authority — require **8/8**.
5. Graph-dependent authority — require **5/6**, bunny only.
6. All R2/R2C/R2D/R2E/R2E2/R2E3/R2E4/R2E5/R2E6 contracts.
7. Milestone D.
8. Phase 14–18 aggregate.
9. Phase 16 independently.
10. Phase 17 independently — require **26/26**.
11. Phase 18 independently — require **57/57**.
12. Phase 20.
13. Direct analytic plane, seam, close sheets, disconnected close sheets when packaged, and cylinder.
14. Complete suite exactly once.

## R2E6 acceptance contracts

### Degree-two preservation

- exact two-ray inventory;
- authoritative exterior continuation;
- complementary interior continuation;
- one exterior and one bounded disk;
- `boundaryFanSectorNodeCount == 0` on the boundary-only triangle;
- no regression in orientation or source-row identity.

### Genuine higher-valence partition

The corrected fixture uses three non-crossing spokes from one source-boundary vertex to distinct points on the opposite boundary edge. Require:

- incidence valid;
- one-to-one node-local successor relation;
- `boundaryFanSectorNodeCount > 0`;
- at least four audited interior sectors at the high-valence node;
- zero hard-rail separators in this case;
- no repeated node or edge cycle;
- one exterior cell;
- four bounded disk cells;
- complete halfedge ownership;
- topology valid.

Do not accept the former dangling-slit input as evidence of a bounded-cell partition.

### Interior hard rail

Require:

- incidence valid with no `BoundaryRotationalSystemConflict` or `BoundaryFanSectorCoverConflict`;
- one canonical arrangement node at each hard-rail endpoint;
- complete local predecessor/target cardinality;
- audited fan-sector nodes;
- at least two hard-rail separators across the two endpoints;
- one exterior and two bounded disks;
- zero repeated-node/edge cycles;
- complete ownership, topology validity, and area equality;
- exterior continuation remains on source loop side `-1`.

### Fail-closed authority

Any missing/duplicate incoming, duplicate target, non-adjacent sector, wrapping interior sector, contradictory fan identity, invalid twin, endpoint discontinuity, or hard-rail crossing must fail transactionally as `BoundaryFanSectorCoverConflict`. No partial successor publication is allowed.

### Preserved structural authority

Require no regression in:

- source-face row permutation and whole-orientation incidence hashes;
- pinched vertex fans and close-sheet separation;
- bridge/core ownership and support-only cycles;
- nested annular non-disk classification;
- nonmanifold preflight;
- global predecessor multiplicity;
- repeated-edge/node, disk, ownership, Euler, boundary-loop, and area validators.

## Minimum acceptance thresholds

- source-chart **11/11**;
- validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**, bunny only;
- R2 focused at least **14/16**, with only planar and bunny allowed;
- Milestone D at least **6/7**, with cylinder only allowed;
- Phase 14–18 at least **242/244**;
- Phase 16 at least **45/47**, with only planar and bunny allowed;
- Phase 17 **26/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48** or better;
- complete suite at least **604/625**, with no failure absent from the P5-TB33 failure set except a deliberately corrected test disposition supported by topology evidence.

## Direct analytic cases

Use backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution. Record success/failure, earliest stage/failure, arrangement/simplified/completed/quad inventories, fallback/recovery/legacy flags, wall time, and peak RSS.

Preserve plane's minimum inventory of 9 arrangement cells, 9 simplified cells, and 12 candidate quads. Seam, close sheets, and cylinder remain unacceptable at zero arrangement inventory but must not regress.

## Decision

- If higher-valence and hard rail close, diagnose planar Euler and cylinder independently and prepare the smallest coherent next Code + Build plan.
- Do not patch completion while arrangement inputs remain invalid.
- Do not advance to R2F until planar, hard rail, cylinder, and all boundary/orbit/disk/owner/Euler gates close and bunny is the sole remaining R2 producer.
- Do not advance to R3 until every R2 gate closes.

## Required outputs

- `.agents/Directional/Milestone_G_P5_TB34_Artifact_Only_R2E6_Test_Benchmark_Report.md`;
- `benchmark-results/p5-tb34-summary.json`;
- bounded evidence bundle;
- updated `TODO`, `MILESTONE_G_TODO.md`, and live handoff;
- one smallest coherent next Code + Build plan if R2 remains open;
- a new final PR #8 handoff comment as the final repository write.
