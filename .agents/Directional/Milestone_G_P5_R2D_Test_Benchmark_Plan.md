# Milestone G P5-R2D Test and Benchmark Plan

**Date:** 2026-08-04  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`  
**Turn type:** Test + Benchmark, artifact only

## Authority

Execute artifact `8913777837`, `surface-cell-p5-r2d-github-source-linux-release`, directly.

- exact compiled source: `0ba0aa9f7a07d5ca6ba67280d705ee8439e1d760`;
- workflow event commit: `6757e6e98aa90e5b5eefce1db9645fbf523f2650`;
- reviewed source patch SHA-256: `c7355a7de3998638f596fa927117584fce274920ca00fcd84f08773bf75935e8`;
- applied commit-diff SHA-256: `de9b6e9e30bf182d73082330d1ef2dbaceca07ffb7a2aa1a938d8e71896319a8`;
- artifact SHA-256: `bcb9c6962677f2f638cf6a832eb25d88fdcd2a97e506a1435a7f936d4891416a`;
- workflow-log artifact: `8913778202`;
- workflow-log SHA-256: `04ba6f577b4d76519c365b564762b72844fa5b3f17e71c80bd7d292acf760384`.

Do not configure, build, relink, patch, regenerate, or modify implementation, test, benchmark, or build logic in P5-TB28.

## 1. Artifact integrity gate

Before executing either packaged binary, verify:

- outer artifact SHA-256;
- exact source commit and branch ancestry;
- empty source status;
- recursive checksum manifest **44/44**;
- **45** packaged files including the checksum manifest;
- **26** fixtures;
- **9** recursive submodule records;
- all four packaged target hashes;
- source archive contains `NonManifoldSourceEdge`, `boundaryCycleOffsets`, cycle-aware publication, and the strengthened focused contracts;
- source archive contains only `agent-source-snapshot.yml` under `.github/workflows` and no agent patch payloads.

Any authority mismatch is an infrastructure failure and ends runtime execution.

## 2. Preserve R1 and recovery authority

Run first:

- all `SourceChartTransitionsR1.*` tests;
- all `SourceAuthoritativeMeshValidatorPhase22.*` tests;
- the focused recovery-authority scope;
- the feature-rail/barrier authority scope;
- the graph-dependent scope used by P5-TB27.

Reference acceptance:

- source-chart **11/11**;
- Phase 22 validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **6/6**.

R2D must not restore local-sheet equality as topology, positional merging, source-triangle pairing, or recovery substitution.

## 3. R2/R2C/R2D focused contracts

Run all directed-incidence, bridge/core, cell-publication, and new R2D structural contracts. Require:

- the three-face source edge fails closed as `NonManifoldSourceEdge`;
- successor/predecessor/twin coverage remains exact;
- every valid halfedge belongs to exactly one audited structural record and one published cell;
- no valid halfedge retains `cell == -1`;
- a simple bounded planar core is disk, one-boundary, Euler one;
- a nested bounded cell is non-disk, two-boundary, Euler zero, with two exact cycle ranges;
- a cut-cell disk joined by valid bridge support remains disk and Euler one;
- dangling bridge excursions and isolated support-only twin pairs preserve the passing R2C contracts;
- malformed bridge multiplicity, repeated nonbridge nodes/edges, theta graphs, ambiguous successors, duplicate predecessors, and incomplete permutations fail closed;
- source-row, seam-start, and whole-orientation permutations preserve structural hashes and classifications.

Do not accept a later completion failure as proof that an arrangement contract passed.

## 4. Milestone D closure

Run all `MilestoneDClosure.*` tests and require **7/7**.

Pay specific attention to:

- interior hard rails do not create exterior source boundaries;
- branched strands retain the restored topology-changing evidence;
- cylindrical open strands preserve complete periodic cell ownership and final topology;
- no post-hoc cycle decomposition is reintroduced.

Any remaining Milestone D failure keeps R2 open.

## 5. Phase 14–18 regression gate

Run independently:

- complete Phase 14–18 aggregate;
- Phase 16;
- Phase 17;
- Phase 18.

P5-TB27 references:

- Phase 14–18 **231/242**;
- Phase 16 **41/45**;
- Phase 17 **20/26**;
- Phase 18 **57/57**.

Acceptance requires all R2D-focused additions and prior tests to pass, Phase 17 to receive naturally valid arrangement candidates, and Phase 18 to remain clean. Report exact numerators and denominators.

## 6. Direct analytic production

Run independently with backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution:

1. plane;
2. multi-face seam;
3. close sheets;
4. cylinder diagnostic;
5. packaged disconnected-close-sheet case when a direct entry exists.

Record success, output origin, incidence disposition, cells by structural class, boundary cycles, Euler data, unassigned halfedges, completed quads, final validators, earliest typed producer, wall time, and peak working set.

P5-TB27 references:

- plane: 9 cells, 12 quads, 15 completion-validation failures;
- seam: 0 cells/quads, `InvalidInputIncidence`;
- close sheets: 0 cells/quads, `InvalidInputIncidence`;
- cylinder: 0 cells/quads, `InvalidInputIncidence`.

R2D closes its arrangement defect only when seam, close sheets, and cylinder retain nonzero valid arrangement inventories, no valid halfedge is unassigned, and failures either close or move to later typed completion evidence.

## 7. Phase 20 and complete-suite gate

Run complete `SurfaceCellPipelinePhase20.*`, then the complete packaged suite once with a watchdog used only as a safety mechanism.

P5-TB27 references:

- Phase 20 **46/48**;
- complete suite **593/623** in **161.786 seconds**.

Record discovered/passed/failed counts, normal termination or exact watchdog endpoint, total duration, maximum RSS, and bunny execution durations. Faster early rejection is not progress. Do not run the full standalone bunny benchmark matrix unless focused and complete-suite evidence cannot identify the producer.

## 8. Decision rule

Advance to R3 only when:

- R1, validator, recovery, feature/barrier, and graph-dependent authority are clean;
- all R2/R2C/R2D focused contracts pass;
- source nonmanifoldness fails with typed evidence;
- planar and nested topology contracts pass;
- every valid halfedge has exact successor, predecessor, orbit, and cell ownership;
- Milestone D is **7/7**;
- Phase 16, Phase 17, and Phase 14–18 are clean, with Phase 18 retained;
- seam, close sheets, and cylinder have nonzero valid arrangement inventories;
- Phase 20 does not regress due to arrangement publication;
- the complete suite terminates.

If R2 remains causal, produce the smallest generalized R2 correction plan. If R2 closes and completion becomes the earliest producer, produce the focused R3 topology-distinct completion plan.

## Preserved prohibitions

- no validator weakening;
- no frequency/count/order ownership selection;
- no fallback/recovery substitution;
- no synthetic counters;
- no positional merging or source-triangle pairing;
- no arbitrary subset search;
- no fixture/ID special cases;
- no post-hoc cycle decomposition;
- no timeout-as-correctness.
