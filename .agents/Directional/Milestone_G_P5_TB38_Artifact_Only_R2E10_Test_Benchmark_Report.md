# Milestone G P5-TB38 Artifact-Only R2E10 Test/Benchmark Report

**Date:** 2026-08-05  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E10 is **not accepted**.

R2E10 compiles the intended normalized canonical pair inventory, but runtime behavior remains at the P5-TB37/R2E9 regression baseline:

- planar fails its first incidence assertion with `BoundaryFanSectorCoverConflict` before successor publication;
- interior hard rail fails its first incidence assertion with the same typed failure before bounded-orbit root authority can be validated;
- Phase 17 remains **20/26**, so the six natural restorations established by R2E8 are still lost;
- the complete suite remains **597/625**, 28 failures.

The focused R2 count remains **13/16**, but the failure stage is the deciding evidence. R2E10 does not restore the R2E8 post-publication planar topology and hard-rail embedding checkpoints.

Source-chart, recovery, feature/barrier, degree-two, genuine four-disk, permutation, pinched-fan, close-sheet, bridge/support, nested, and nonmanifold authority remains passing. Cylinder, bunny, FlowRep pre-ring, and downstream completion failures remain independent.

R2 remains open. Do not advance to R2F or R3.

This turn did not configure, build, relink, patch, regenerate, or modify source, tests, fixtures, validators, workflows, or build logic.

## Package authority

Validation used artifact `8948771075`, `surface-cell-p5-r2e10-github-source-linux-release`.

- archive SHA-256: `d0815a8423cd71758eb4f1033c0d3f19fd34261df4ea5c32efcf80b2069c3210`;
- exact compiled source: `bf33049157dfee51a1b6c48dff35a97ce980e49f`;
- workflow event commit: `4831349b3d8c996a44bbd804f12ad01be9e3446f`;
- workflow run/job: `31051610854` / `92459824013`;
- `SurfaceArrangement.cpp` blob: `359ae620448e777731d2d2292eda3d0050c42c61`;
- header blob: `b172625cd82862d16b81b6f3b8d52686b5fda41c`;
- Phase 16 test blob: `e58bceda098f7768b8a7203cca00564f82a7d831`;
- Milestone D test blob: `015a9f02354a91ca07d0e0c6bf6b2632055436ae`;
- recursive manifest: **19/19**;
- package files: **20**, including the manifest;
- executable-relative fixture files staged byte-identically: **26**;
- recursive submodule records: **9**;
- packaged source status: empty;
- build-log artifact: `8948771526`, SHA-256 `e2a8b1ab9399952f3ffd029e747cc09271bb64906b5a8509e2ed6447e9f8bf20`.

The built source is an ancestor of the documentation checkpoint, and only allowed documentation/workflow-cleanup records changed after it. The artifact authority gate passed before any packaged executable ran.

## Environment

- Debian GNU/Linux 13 (`trixie`), Linux 6.18.35, x86-64;
- AMD EPYC 9V74, 5 available logical CPUs;
- approximately 5.9 GiB RAM, no swap;
- packaged Release binaries compiled with GNU C++ 13.3, `-O2 -DNDEBUG`.

## Focused and aggregate results

| Scope | P5-TB38 | P5-TB37 comparison | P5-TB36 comparison |
|---|---:|---|---|
| Source chart + source validator | **17/17** | preserved | preserved |
| Recovery authority | **9/9** | preserved | preserved |
| Feature/barrier | **8/8** | preserved | preserved |
| Graph-dependent | **5/6** | bunny only; preserved | bunny only; preserved |
| R2 focused | **13/16** | same count and failure stage | same count, worse stage |
| Milestone D | **5/7** | unchanged | unchanged count, hard rail earlier |
| Phase 16 | **45/47** | unchanged | unchanged count, planar earlier |
| Phase 17 | **20/26** | unchanged | **-6** |
| Phase 18 | **57/57** | preserved | preserved |
| Phase 14–18 | **235/244** | unchanged | **-6** |
| Phase 20 | **46/48** | unchanged | unchanged |
| Complete suite | **597/625** | unchanged | **-6** |

### Planar producer

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` stops at:

```text
incidenceValid == false
BoundaryFanSectorCoverConflict
```

No normalized successor publication, cyclic-wrap count, Euler, disk, embedding, orientation, area, or aggregate topology assertion is reached. R2E10 therefore does not restore the R2E8 state where incidence published and the unchanged topology validators exposed wrap count `0` and Euler `0`.

### Interior hard rail

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` stops at:

```text
incidenceValid == false
BoundaryFanSectorCoverConflict
```

No complete-orbit root, opposite-side root, embedding, cell-count, disk, loop, Euler, ownership, or aggregate topology assertion is reached. R2E10 therefore does not restore the R2E8 state where those topology and ownership checks passed before embedding failed.

### Independent cylinder and bunny producers

- `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` remains invalid at `invalid-cell cell=-1 halfedge=0 twin=1 next=-1`.
- `SurfaceArrangementPhase16.BunnySingularityFanUsesIntrinsicSourceVertexRotation` remains the only graph-dependent failure.

Neither is part of the immediate R2E11 boundary-cover scope.

### Phase 17 consequences

The exact six tests restored naturally by R2E8 still fail without any Phase 17 implementation change:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

They continue to receive invalid or non-committable upstream arrangements. Do not modify Phase 17 to compensate.

## Source-supported diagnosis

The current diagnostics expose only the aggregate typed failure `BoundaryFanSectorCoverConflict`, so the exact rejected pair is not directly identified. The following is a source-supported inference, not a proven subreason.

R2E10 normalizes equivalent source-entity fan identities when constructing `canonicalPairInventory` by applying `canonical_entity_key` and retaining all agreeing original fan identities as provenance. During chart resolution, however, it still iterates each original `fanIdentity` and requires:

```text
transitionGraph.resolve_entity(nodePoint).canonical == fanIdentity
```

That exact-identity gate is stricter than the earlier normalized-equivalence contract. A chart whose resolved entity has the same normalized canonical entity key and transition root can be rejected solely because its original provenance identity variant differs. Candidate collection also remains nested under the original fan-identity loops, so a pair can fail before all equivalent provenance witnesses are reconciled at the pair level.

The next producer should make normalized pair ownership authoritative throughout chart resolution. Exact original fan identities should remain provenance, not become a second ownership gate. It should also add derived conflict subreasons/counters so zero candidate, multiple candidate, normalized-entity mismatch, root mismatch, and conflicting score cases are distinguishable without weakening the aggregate fail-closed gate.

## Direct analytic cases

Each case used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, no legacy execution, no returned-input substitution, one warmup, and five measured runs.

| Case | Arrangement | Simplified | Quads | Result | Earliest failure | Median | CV |
|---|---:|---:|---:|---|---|---:|---:|
| plane | 9 | 9 | 12 | fail | `completion/output-validation: AggregateCompletionValidationFailure` | 0.013167 s | 1.98% |
| multi-face seam | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 0.013084 s | 1.02% |
| close sheets | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 0.020599 s | 3.01% |
| cylinder | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 0.134497 s | 1.83% |

Every measured run reports `success=false`. A clean benchmark-process exit is not production success. Within each case, stage object counts and structural lineage hashes are deterministic.

## Bunny production evidence

Two independent packaged processes executed `bunny_1k_random__surface_cells` with fallback `Fail`, source-grid recovery disabled, and no legacy backend.

| Run | Wall time | Peak working set | Arrangement | Quads | Result |
|---|---:|---:|---:|---:|---|
| 1 | 21.846814 s | 271,106,048 B | 0 | 0 | `NotProductionReady/completion` |
| 2 | 21.368318 s | 271,237,120 B | 0 | 0 | `NotProductionReady/completion` |

Both report `SideSubdivisionRepair:InvalidInputIncidence`. Every stage object count and structural hash is identical between the two runs. Bunny remains deterministic and fail-closed, but not production success.

## Complete suite

The retained authoritative complete-suite execution reports:

- tests: **625**;
- passed: **597**;
- failures: **28**;
- errors: **0**;
- disabled: **0**;
- XML runtime: **72.587 s**;
- measured wall time: **72.60 s**;
- maximum RSS: **281,456 KiB**;
- normal process termination: yes;
- exit status: `1`, from test failures.

The failure inventory matches the P5-TB37 runtime baseline: P5-TB36's 22 failures plus the same six Phase 17 regressions. No P5-TB37 failure closed and no additional product failure appeared.

Interrupted wrapper/orchestration attempts made while obtaining a complete wall/RSS record are retained in the evidence archive for transparency, but they are not product authority and are not treated as timeout-based correctness evidence. The authoritative process above completed normally.

## Failure classification

- planar and hard rail: **production implementation**, pre-publication normalized chart-witness reconciliation;
- six Phase 17 failures: **production implementation consequence**, invalid upstream arrangement; do not patch downstream;
- cylinder, bunny, FlowRep pre-ring, completion, P23/P24/P26/P27, and PatchDescriptor failures: **existing independent production implementation failures**;
- no evidence supports a structurally invalid fixture or incorrect expectation for the target planar/hard-rail tests;
- no nondeterminism was observed in direct analytic or bunny lineage evidence;
- no performance acceptance is claimed because correctness remains failed.

## Decision

Proceed with **P5-R2E11 normalized chart-entity ownership and pair-first witness reconciliation Code + Build**.

R2E11 must:

1. retain the normalized node-level canonical directed-pair inventory and exact exterior relation;
2. resolve chart witnesses pair-first rather than treating each original fan identity as independent ownership;
3. normalize the chart-resolved entity with the same `canonical_entity_key` contract used by the pair inventory;
4. require normalized chart entity and transition root agreement with the pair record while preserving exact original identities only as provenance;
5. reconcile all agreeing provenance witnesses before requiring exactly one authoritative chart/root witness per non-exterior pair;
6. preserve the complete hard-rail bounded-orbit root audit and transactional publication gate;
7. add derived diagnostic subreasons without weakening failure semantics;
8. restore planar/hard-rail incidence and Phase 17 **26/26** without modifying Phase 17;
9. leave cylinder, bunny, FlowRep, completion, optimizer, fallback/recovery, fixtures, and downstream validators unchanged;
10. compile only the four approved targets and execute no project binary.

## Evidence

- machine-readable summary: `benchmark-results/p5-tb38-summary.json`;
- evidence archive: `directional-p5-tb38-8948771075-evidence.zip`;
- evidence archive SHA-256: `e5991d8a3fd58a16e9b62366e6a83b1953f2164806f7de9952db2d38d3853b19`;
- evidence archive entries: **140**;
- evidence archive size: **438,425 bytes**;
- raw XML, logs, benchmark JSON, failure images, manifest and blob records, fixture checksums, source inspection, machine context, and machine-readable runtime summary are included.

P5 remains open. PR #8 remains open, draft, and unmerged.
