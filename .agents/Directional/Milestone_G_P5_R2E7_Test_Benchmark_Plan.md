# Milestone G P5-R2E7 Artifact-Only Test/Benchmark Plan

**Date:** 2026-08-05  
**Turn:** P5-TB35 artifact-only R2E7 validation  
**Artifact:** `8938299309`  
**Exact source:** `31c8d9a212f649df7c70fe9291d1fac8c4db7132`

## Boundary

Run only packaged binaries and packaged fixtures. Do not configure, build, relink, patch, regenerate, modify source/tests/build logic, or alter fixtures. Preserve raw stdout, stderr, XML, commands, wall time, and RSS evidence. Execute the complete suite exactly once after all focused scopes.

## Package authority gate

Before executing a packaged binary, require:

- archive SHA-256 `af34097d6579ff07eafbe24e75ed05db3dfec98170ef7576ce30a12b538f063e`;
- exact source `31c8d9a212f649df7c70fe9291d1fac8c4db7132`;
- workflow event `7d5450cb6411722818844548de59a09c8f4451d5`;
- reviewed/applied diff `711286a519d39c18b074caae3b999ec15a7202a9b9454e0eb04a8eb642cc2745`;
- empty source status;
- recursive manifest **48/48**;
- physical package files **49**;
- fixtures **26**;
- recursive submodules **9**;
- exact target hashes from the Code/Build report;
- cleaned source with only `agent-source-snapshot.yml` and zero payloads;
- exclusion list containing only `.github/workflows/agent-build-p5-r2e7.yml`.

Fail the turn before runtime if any authority item differs.

## Focused execution order

1. Source-chart R1 authority — require **11/11**.
2. Source validator authority — require **6/6**.
3. Recovery authority — require **9/9**.
4. Feature/barrier authority — require **8/8**.
5. Graph-dependent authority — require **5/6**, bunny only.
6. All R2/R2C/R2D/R2E/R2E2/R2E3/R2E4/R2E5/R2E6/R2E7 contracts.
7. Milestone D.
8. Phase 14–18 aggregate.
9. Phase 16 independently.
10. Phase 17 independently — require **26/26** without Phase 17 changes.
11. Phase 18 independently — require **57/57**.
12. Phase 20.
13. Direct analytic plane, seam, close sheets, disconnected close sheets when packaged, and cylinder.
14. Complete suite exactly once.

## R2E7 acceptance contracts

### Preserved degree-two and higher-valence authority

Require:

- boundary-only degree-two triangle remains one exterior plus one bounded disk;
- exact R2E5 two-sector mapping remains unchanged;
- genuine three-spoke higher-valence partition remains one exterior plus four bounded disks;
- no repeated edge/node cycle;
- complete ownership and topology validity;
- source-face-row and whole-orientation incidence hashes remain invariant.

### Cyclic-wrap source-interior sector

For the planar fixture and all relevant arrangement inputs require:

- fan adjacency is evaluated modulo fan size;
- at least one successfully audited source-interior sector may use vector wrap;
- `boundaryCyclicWrapInteriorSectorCount > 0` where the fixture contains that condition;
- the exact independently proven exterior pair is excluded once and only once;
- no other wrap adjacency is rejected merely for crossing stored-vector index zero;
- incidence and successor publication reach at least the P5-TB33 topology/Euler diagnostic position;
- prefer full planar topology/Euler closure when the corrected cover naturally supplies it.

### Directed hard-rail sides

Require the interior-hard-rail fixture to demonstrate:

- incidence validity and complete local predecessor/target cardinality;
- no `BoundaryRotationalSystemConflict` or `BoundaryFanSectorCoverConflict`;
- at least two audited hard-rail separators and two audited directed side pairs across the endpoints;
- each rail side uses the authoritative rail ray and its correct cyclicly adjacent non-rail ray;
- opposite directed rail twins belong to two distinct bounded cells;
- exactly one exterior and two bounded disk cells;
- embedding, orientation, disk, boundary-loop, Euler, ownership, and area subvalidations pass;
- no repeated node or edge cycle.

A mere inequality of fan IDs is insufficient.

### Phase 17 natural restoration

Do not modify or reinterpret Phase 17. Require all six P5-TB34 regressions to pass naturally through corrected arrangement inputs:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

Phase 17 must return to **26/26**.

### Fail-closed authority

Missing, duplicate, exterior-duplicate, invalid-twin, endpoint-discontinuous, cross-fan, wrong-order rail side, or incomplete cover evidence must fail transactionally as `BoundaryFanSectorCoverConflict`, with no partial successor publication.

### Preserved structural authority

Require no regression in:

- pinched vertex fans and close-sheet separation;
- bridge/core ownership and support-only cycles;
- nested annular non-disk classification;
- nonmanifold preflight;
- global predecessor multiplicity;
- repeated-edge/node, disk, ownership, Euler, boundary-loop, orientation, and area validators.

## Minimum acceptance thresholds

- source-chart **11/11**;
- validator **6/6**;
- recovery **9/9**;
- feature/barrier **8/8**;
- graph-dependent **5/6**, bunny only;
- R2 focused at least **14/16**, with only cylinder and bunny or a separately diagnosed planar Euler failure allowed;
- Milestone D at least **6/7**, cylinder only;
- Phase 14–18 at least **242/244** when planar and hard rail close, otherwise explain every remaining producer independently;
- Phase 16 **46/47** if planar closes, otherwise at least **45/47** with explicit planar diagnosis;
- Phase 17 **26/26**;
- Phase 18 **57/57**;
- Phase 20 **46/48** or better;
- complete suite at least **604/625**, with no failure absent from the P5-TB33 failure set after accounting for closed higher-valence authority.

## Direct analytic cases

Use backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, and no legacy execution. Record success/failure, earliest stage/failure, arrangement/simplified/completed/quad inventories, fallback/recovery/legacy flags, wall time, and peak RSS.

Preserve plane's minimum inventory of 9 arrangement cells, 9 simplified cells, and 12 candidate quads. Seam, close sheets, and cylinder remain unacceptable at zero arrangement inventory but must not regress.

## Decision

- If planar, Phase 17, and hard rail close, diagnose cylinder independently and determine whether bunny is the only remaining intrinsic R2 producer after cylinder remediation.
- If planar still reports Euler zero after valid cyclic cover, retain that as an independent producer; do not synthesize Euler correction.
- If hard rail remains topology-invalid, report the exact failing topology subflag and directed side/owner evidence rather than broadening scope.
- Do not patch completion while arrangement inputs remain invalid.
- Do not advance to R2F until planar, hard rail, cylinder, and all boundary/orbit/disk/owner/Euler gates close and bunny is the sole remaining R2 producer.
- Do not advance to R3 until every R2 gate closes.

## Required outputs

- `.agents/Directional/Milestone_G_P5_TB35_Artifact_Only_R2E7_Test_Benchmark_Report.md`;
- `benchmark-results/p5-tb35-summary.json`;
- bounded evidence bundle;
- updated `TODO`, `MILESTONE_G_TODO.md`, and live handoff;
- one smallest coherent next Code + Build plan if R2 remains open;
- a new final PR #8 handoff comment as the final repository write.
