# Milestone G P5-TB37 Artifact-Only R2E9 Test/Benchmark Report

**Date:** 2026-08-05  
**Turn type:** Test + Benchmark, artifact-only  
**Branch:** `agent/surface_cell_quad/p5-recover-bridge-healing`  
**Base:** `surface_cell_quad`  
**Draft PR:** #8 — keep open, draft, and unmerged  
**Review policy:** `never`

## Disposition

P5-R2E9 is **not accepted** and is a regression from P5-R2E8.

The two target fixtures now fail earlier than P5-TB36:

- planar fails its first incidence assertion with `BoundaryFanSectorCoverConflict` before any normalized successor cover is published;
- interior hard rail fails its first incidence assertion with the same typed failure before bounded-orbit root authority can be validated.

The focused R2 count remains **13/16**, but that unchanged count is misleading: both target producers moved backward from post-publication topology/embedding failures to pre-publication incidence rejection.

R2E9 also loses all six Phase 17 natural restorations established by R2E8:

- Phase 17 regresses from **26/26** to **20/26**;
- Phase 14–18 regresses from **241/244** to **235/244**;
- the complete suite regresses from **603/625** to **597/625**.

Source-chart, feature/barrier, recovery, degree-two, genuine four-disk, permutation, pinched-fan, close-sheet, bridge/support, nested, and nonmanifold authority remains passing. Cylinder and bunny remain independent producers.

R2 remains open. Do not advance to R2F or R3.

This turn did not configure, build, relink, patch, regenerate, or modify source, tests, fixtures, validators, workflows, or build logic.

## Package authority

Validation used artifact `8946700183`, `surface-cell-p5-r2e9-github-source-linux-release`.

- archive SHA-256: `bae182ef1e3e5fbbc9fff25ea60a56821e31e4e6fe81787137cdac58f30c6a3a`;
- exact compiled source: `a5b9382c2877ef72a3280ad9dbca2d5b20caaa1c`;
- workflow event commit: `29e71770a3c2ff001fa6daa687a2bdf957dd79c4`;
- `SurfaceArrangement.cpp` blob: `fec7b37c0692a0e23d28727d8fad60215bd7fa6c`;
- header blob: `b172625cd82862d16b81b6f3b8d52686b5fda41c`;
- Phase 16 test blob: `e58bceda098f7768b8a7203cca00564f82a7d831`;
- Milestone D test blob: `e673e60133a39ddfc657fc9bc65ce538a5147930`;
- recursive manifest: **19/19**;
- original package files: **20**, including the manifest;
- executable-relative fixture files staged without content changes: **26**;
- recursive submodule records: **9**;
- packaged source status: empty.

The fixture set is byte-identical to the P5-TB36 validated fixture set. GitHub comparison from R2E8 source to R2E9 source shows no `test-data` change; only the approved arrangement implementation/header/tests and turn documentation/workflow records changed.

The authority gate passed before packaged test or benchmark execution. The packaged source archive was extracted only for blob verification and source inspection; no source file was compiled or modified.

## Focused results

| Scope | P5-TB37 | P5-TB36 comparison |
|---|---:|---|
| Source chart + source validator | **17/17** | preserved |
| Core R2E9 producers | **0/3** | planar/hard rail regress earlier; cylinder unchanged |
| R2 focused | **13/16** | same count, worse failure stage |
| Milestone D | **5/7** | same count, hard rail regressed to incidence |
| Phase 16 | **45/47** | same count, planar regressed to incidence |
| Phase 17 | **20/26** | **-6 regressions** |
| Phase 18 | **57/57** | preserved |
| Phase 14–18 | **235/244** | **-6** |
| Phase 20 | **46/48** | preserved count |
| Graph-dependent | **5/6** | bunny only; preserved |
| Recovery authority | **9/9** | preserved |
| Feature/barrier | **8/8** | preserved |

### Exact Phase 17 regressions

The six tests naturally restored by R2E8 fail again without any Phase 17 change:

- `SimplifySurfaceCellComplexReturnsMutatedComplex`;
- `ComplexCandidateRecomputationCreatesRealQueuedCandidates`;
- `TransactionalMutationCommitsExtractedOversampledCandidate`;
- `TransactionalMutationPreservesHardRailSupport`;
- `MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies`;
- `OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains`.

The failures show empty or non-committable upstream arrangement inputs. They are downstream consequences of the R2E9 boundary fan-cover rejection and must not be patched in Phase 17.

## R2E9 producer diagnosis

### Planar canonical boundary cover

`SurfaceArrangementPhase16.EulerBoundaryAndAreaChecksPassOnPlanarFixture` now stops at:

```text
incidenceValid == false
BoundaryFanSectorCoverConflict
```

No planar wrap count, Euler, disk, embedding, or aggregate topology assertion is reached. This is strictly earlier than P5-TB36, where incidence published and the fixture reached topology validation with wrap count `0` and Euler `0`.

### Interior hard rail

`MilestoneDClosure.InteriorHardRailIsNotClassifiedAsExteriorBoundary` also stops at:

```text
incidenceValid == false
BoundaryFanSectorCoverConflict
```

No root-orbit, embedding, cell-count, disk, loop, Euler, or aggregate topology assertion is reached. This is strictly earlier than P5-TB36, where incidence, one-exterior/two-bounded inventory, disk, loop, Euler, ownership, and distinct bounded rail-twin owners passed before embedding failed.

### Source inspection

The R2E9 producer now enumerates a cyclic pair list for every `nodeWedges` fan identity, resolves candidate chart corners for each directed pair, excludes one exact exterior relation, and then requires every remaining pair to have exactly one candidate and the combined records to form one local incoming/target cover.

The runtime evidence proves that this inventory is rejected before publishation on both target fixtures. Existing output does not identify whether the first rejected normalized pair has zero chart candidates, multiple chart candidates, an equivalent duplicate fan identity, or a mismatched exterior relation. The next producer must reconcile those cases from canonical directed records; it must not restore the R2E8 omission by returning to chart-filtered consecutive-list enumeration.

The next plan therefore targets node-level canonical pair normalization, continuous chart-corner wrap resolution, exact exterior-pair identification, and complete transactional cover publication. The R2E9 hard-rail orbit-root audit remains conceptually valid but cannot be accepted until the boundary cover reaches it.

### Independent cylinder

`MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` remains uncommitted with invalid incidence:

```text
invalid-cell cell=-1 halfedge=0 twin=1 next=-1
```

Cylinder remains outside the immediate R2E10 healing scope.

## Direct analytic cases

All cases used backend `SurfaceCells`, fallback `Fail`, source-grid recovery disabled, no legacy execution, and no returned-input substitution.

 | Case | Arrangement | Simplified | Quads | Result | Earliest failure | Peak working set |
|---|---:|---:|---:|---|---|---:|
| plane | 9 | 9 | 12 | fail | `completion/output-validation: AggregateCompletionValidationFailure` | 8,761,344 B |
| multi-face seam | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 8,302,592 B |
| close sheets | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 8,577,024 B |
| cylinder | 0 | 0 | 0 | fail | `completion: SideSubdivisionRepair:InvalidInputIncidence` | 9,969,664 B |

The object counts and failure classes are unchanged from P5-TB36. No direct analytic production case closed. Pre-completion stage counts and hashes remain stable; completion hashes changed with the R2E9 compiled source but did not produce valid output.

## Bunny production evidence

Two independent processes executed `bunny_1k_random__surface_cells` with fallback `Fail` and source-grid recovery disabled.

| Run | Wall time | Peak working set | Arrangement | Quads | Result |
|---|---:|---:|---:|---:|---|
| 1 | 22.999296 s | 271,302,656 B | 0 | 0 | `NotProductionReady/completion` |
| 2 | 22.519749 s | 271,179,776 B | 0 | 0 | `NotProductionReady/completion` |

Both report `SideSubdivisionRepair:InvalidInputIncidence`. Every stage object count and structural hash matches between the two runs. Bunny remains deterministic and fail-closed, but not production success.

## Complete suite

The retained authoritative complete-suite execution reports:

- tests: **625**;
- passed: **597**;
- failures: **28**;
- errors: **0**;
- disabled: **0**;
- XML runtime: **70.736 s**;
- measured wall time: **70.74 s**;
- maximum RSS: **281,668 KiB**;
- normal process termination: yes;
- exit status: `1`, from test failures.

The failure set is exactly P5-TB36's 22 failures plus the six regressed Phase 17 tests. No P5-TB36 failure closed and no other new failure appeared.

An initial orchestration call was interrupted after spawning its complete-suite child, so its wrapper exit file was not retained. That child still completed with **597/625** and the same 28-test failure set. A clean second execution was then run solely to capture authoritative wrapper exit, wall-time, and RSS evidence. The second execution above is the retained authority; the duplicate incomplete wrapper record was removed from the final evidence archive.

## Decision

Proceed with **P5-R2E10 canonical wrap-pair chart-witness and unique boundary fan-cover reconciliation Code + Build**.

R2E10 must:

1. normalize canonical pairs at the node level by directed incidence identity before chart resolution;
2. reconcile equivalent fan-identity records only when their source entity, chart, and transition-root authority agree;
3. resolve canonical wrap pairs in one continuous exact chart-corner interval, including the required `2*pi` lift where appropriate;
4. identify and exclude the independently proven exterior relation exactly once;
5. publish only a complete one-to-one incoming/itarget cover;
6. retain the R2E9 complete hard-rail orbit-root audit and authoritative embedding-root materialization;
7. restore planar and hard-rail valid incidence and the six Phase 17 tests without Phase 17 changes;
8. leave cylinder, bunny, FlowRep, completion, optimizer, fallback/recovery, fixtures, and downstream validators unchanged;
9. compile only the four approved targets and execute no project binary.

## Evidence

- machine-readable summary: `benchmark-results/p5-tb37-summary.json`;
- evidence archive: `directional-p5-tb37-8946700183-evidence.zip`;
- evidence archive SHA-256: `246debf82198c5369c27975886d30ce38dbd3a3d8c21ad46325dd1cfa022c614`;
- evidence archive entries: **163**;
- evidence files: **133**;
- raw XML, logs, benchmark JSON, manifest and blob checks, machine context, source inspection, fixture checksums, and machine-readable summary are included.

P5 remains open. PR #8 remains open, draft, and unmerged.
