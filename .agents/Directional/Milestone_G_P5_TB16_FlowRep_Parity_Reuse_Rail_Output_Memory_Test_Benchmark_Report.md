# Milestone G P5 — TB16 FlowRep, Parity, Reuse, Rail, Output, and Memory Test + Benchmark Report

**Turn:** P5-TB16 artifact-only test and benchmark  
**Artifact:** `8870351914` (`surface-cell-p5-cb90-parity-flowrep-reuse-rail-linux-release`)  
**Exact compiled source:** `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`  
**Implementation commit:** `57be334c7a5d41538dcfd7011f429da525d2d2ca`  
**Digest:** `sha256:ce6ca28d8eb41562c3486077934302643100fab575f34ea8a341e3212964a7e4`  
**Review policy:** `never`  
**Rebuild performed:** no

## Disposition

P5-TB16 does **not** close P5.

The high-cardinality generated-smooth-field signal-11 fault is eliminated, final arrangement rail identity passes its focused regression, stage-owned memory telemetry is populated, and all eight bunny benchmark processes terminate deterministically within the wall and memory limits.

The authoritative parity-scope repair, positive exact reuse, invalid-midpoint fixture, cylinder simplification fixture, production output contracts, and complete RSS reconciliation remain open. Both face-edge and smooth-field bunny paths still fail closed at `BoundaryParityRepair:MixedCellSourceScope` before descriptor acceptance.

PR #8 remains open, draft, and unmerged.

## Artifact integrity

The artifact was downloaded and executed directly from arbitrary extraction and working directories.

- `source-commit.txt`: `d268ca00014935770f3b7fd74c5186c3d9ef3ddf`.
- Source status: empty.
- Artifact ZIP digest: exact match.
- Packaged checksums: **36/36 passed** after normalizing the archive-time `artifact/` prefix.
- Packaged fixture files: **26**.
- Packaged random bunny: **502 vertices / 1,000 triangle faces**.
- No source build or link step was executed in this turn.

## Test results

### Focused previous failure set

The ten prior assertion failures now pass **1/10**.

Newly passing:

- `SurfaceCellPipelinePhase20.LiveTracingConsumesAuthoritativeBoundaryAndHardFeatureRails`.

Still failing:

1. `MilestoneGP26.PlaneAndMechanicalFixturesCompleteEndToEnd`;
2. `MilestoneGP26.CylinderCompletesEndToEnd`;
3. `MilestoneGP26.MultiFaceSeamCompletesEndToEnd`;
4. `MilestoneGP26.TorusCompletesEndToEnd`;
5. `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved`;
6. `PatchDescriptorMilestoneE.WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger`;
7. `PatchDescriptorMilestoneE.OneCandidateBudgetIsExactAndDoesNotRecurse`;
8. `PatchDescriptorMilestoneE.FailedSubdivisionReturnsBitExactCommittedComplex`;
9. `SurfaceCellPipelinePhase20.CylinderFixtureCompletesProductionOutput`.

The rail regression now observes authoritative final halfedge `railId`, `curveId`, interval bounds, complete provenance, and nonzero tracing/FlowRep/arrangement memory telemetry.

### Authoritative suites

| Scope | Passed | Failed |
|---|---:|---:|
| Phase 14–18 aggregate | **230** | **0** |
| `PatchDescriptorMilestoneE.*` | 22 | 3 |
| Milestone G P23 + Phase 20 | 53 | 1 |
| Milestone D closure | 6 | 1 |
| Complete packaged binary | **583** | **10** |

The packaged binary contains **593 tests**. Complete disposition:

- **583/593 passed**;
- **10 assertion failures**;
- **0 signal-11 terminations**.

### Former signal-11 tests

All three formerly crashing cases now terminate normally:

- `MilestoneGP26.ProductionMatrixTerminatesWithoutHiddenFallback` — passed;
- `MilestoneGP27.ProductionSurfaceCellMatrixMatchesSupportedDisposition` — terminated and failed assertions because production cases still return unsuccessful results;
- `ProductionManifestCases/MilestoneGP27SurfaceCellCase.RunsIndependentlyAndOwnsReturnedDiagnostics/7` — passed.

The complete 593-test suite also terminates normally in **76.574 s**. This closes the P5-CB83 liveness fault without weakening the production assertions.

### Fixture and reuse findings

- `FlowRepStrandsPhase15.EndpointCompletionExtendsToRetainedSameSheetNetwork` passes while forcing vector reallocation.
- `PatchDescriptorMilestoneE.SubdivisionWithoutCommonSourceChartFailsBeforeMutation` passes as a distinct missing-chart contract.
- `PatchDescriptorMilestoneE.FailedSubdivisionReturnsBitExactCommittedComplex` still reports `MissingCommonSourceChart`, not `InvalidMidpointEmbedding`.
- `MilestoneDClosure.CylindricalOpenStrandCommitsWithTopologyPreserved` still fails the initial incidence validator before candidate extraction.
- Both positive exact-reuse regressions still report `completionOwnershipReusedPatchCompletions == 0`.

## Face-edge random-bunny processes

Four fresh independent processes used:

- case `bunny_1k_random_medium`;
- generated `face_edges` field;
- backend `SurfaceCells`;
- fallback `Fail`;
- source-grid recovery disabled;
- zero warmups and one measured run;
- arbitrary working directories.

| Run | Wall | Peak working set | Result |
|---|---:|---:|---|
| 1 | `17.475780 s` | `138,072,064 B` | deterministic fail-closed |
| 2 | `18.471857 s` | `130,195,456 B` | deterministic fail-closed |
| 3 | `19.086715 s` | `130,035,712 B` | deterministic fail-closed |
| 4 | `17.527104 s` | `130,236,416 B` | deterministic fail-closed |

All non-timing diagnostics are identical. Normalized structural digest:

`e2f51e7f3eb891e6e4f27926c36dbe6fd824d983303f05a05ba01f88e00d240b`

Common state:

```text
NotProductionReady/completion
completionFailure=BoundaryParityRepair:MixedCellSourceScope
```

- trace segments: `12,130`;
- retained strand arcs: `8,913`;
- arrangement/simplified cells: `7,405 / 7,405`;
- odd cells before/after rejected parity repair: `1,860 / 0`;
- descriptors/completed patches: `0 / 0`;
- exact reused/recomputed completions: `0 / 0`;
- fallback/recovery: neither used;
- output origin: `None`.

Versus P5-TB15, maximum wall changed by `-4.28%` and maximum peak working set changed by `+0.66%`.

## Smooth-field random-bunny processes

Four fresh independent processes used the production-manifest case `bunny_1k_random__surface_cells`, generated `smooth` field, debug retention, direct `SurfaceCells`, fallback `Fail`, and source-grid recovery disabled.

| Run | Wall | Peak working set | Result |
|---|---:|---:|---|
| 1 | `23.280920 s` | `283,176,960 B` | deterministic fail-closed |
| 2 | `24.560557 s` | `283,414,528 B` | deterministic fail-closed |
| 3 | `23.920054 s` | `283,557,888 B` | deterministic fail-closed |
| 4 | `23.580185 s` | `283,480,064 B` | deterministic fail-closed |

All four processes return normally. All non-timing diagnostics are identical. Normalized structural digest:

`b9b98dc5370526693f356177e809ef63a2db89c734cd6ae52a281d706ad16b72`

Common state:

```text
NotProductionReady/completion
completionFailure=BoundaryParityRepair:MixedCellSourceScope
```

- trace segments: `80,862`;
- retained strand arcs: `16,958`;
- arrangement/simplified cells: `21,298 / 21,298`;
- odd cells before/after rejected parity repair: `959 / 0`;
- open endpoints before completion: `3,959`;
- resolved/unresolved/required-unresolved endpoints: `3,956 / 3 / 0`;
- endpoint-completion added arcs: `2,050`;
- descriptors/completed patches: `0 / 0`;
- exact reused/recomputed completions: `0 / 0`;
- fallback/recovery: neither used;
- output origin: `None`.

The stage-four strands output is now deterministic with structural hash `db87260a9fca63a6` and `16,958` arcs. This is direct runtime evidence that the prior high-cardinality FlowRep ownership fault is closed.

## Resource gates

Every benchmark process passes the formal limits:

- wall limit: `39.228299 s`;
- peak working-set limit: `1,115,394,560 B`;
- observed maximum wall: `24.560557 s`;
- observed maximum peak working set: `283,557,888 B`.

Stage-owned telemetry is nonzero, deterministic, and records release flags plus a maximum of two simultaneous live large structures.

| Field path | Current stage-owned sum | Sum of per-stage peaks | Max RSS | Current/RSS | Peak-sum/RSS |
|---|---:|---:|---:|---:|---:|
| face edges | `45,076,354 B` | `54,578,696 B` | `138,072,064 B` | `32.65%` | `39.53%` |
| smooth | `121,068,482 B` | `134,058,650 B` | `283,557,888 B` | `42.70%` | `47.28%` |

The telemetry gate is only partially satisfied. The fields expose dominant containers and lifetime transitions, but current owned-byte sums leave `92,995,710 B` unexplained on face edges and `162,489,406 B` unexplained on smooth field. Allocator capacity, nested associative-node overhead, Eigen storage, retained diagnostics, and overlapping lifetime accounting still require reconciliation.

## Gate disposition

| P5-TB16 gate | Result |
|---|---|
| Previous ten assertion failures all pass | **Fail** |
| Former signal-11 tests terminate normally | **Pass** |
| Smooth-field benchmark processes return normally | **Pass** |
| Four face-edge runs deterministic | **Pass** |
| Four smooth-field runs deterministic | **Pass** |
| Both field paths produce valid nonempty pure-quad output | **Fail** |
| Positive exact completion reuse | **Fail** |
| Focused final rail identity | **Pass** |
| Every process satisfies wall and memory limits | **Pass** |
| Stage-owned telemetry populated | **Pass** |
| Stage-owned telemetry reconciles dominant RSS | **Fail** |
| Invalid-midpoint fixture reaches intended failure | **Fail** |
| Cylinder simplification fixture is topology-valid | **Fail** |
| Production output contracts pass | **Fail** |

## Root-cause disposition

### Closed

1. **P5-CB83 FlowRep liveness:** vector-growth ownership repair is validated by the forced-reallocation unit test, all former signal-11 tests, the complete suite, and four generated-smooth-field bunny processes.
2. **P5-CB86 focused rail propagation:** final arrangement halfedges retain authoritative rail identity and complete provenance in the intended stage-six regression.
3. **P5-CB90 compile/package gate:** artifact integrity and fixture closure pass.

### Still open

1. **Parity scope:** both bunny field paths still reach zero odd cells only inside a rejected transaction and return `BoundaryParityRepair:MixedCellSourceScope`. The pre-transaction scope selected by the new helper is either unavailable for affected cells or is not propagated to every replacement halfedge/twin before validation.
2. **Exact reuse:** the cache remains semantically over-keyed or lookup occurs after allocation-local state has already changed. Both positive regressions remain at zero reuse.
3. **Invalid midpoint fixture:** clearing node occurrences and setting only node-level source fields does not create the common occurrence chart required by subdivision lookup. The fixture must contain explicit compatible occurrences with malformed barycentrics.
4. **Cylinder fixture:** the rebuilt arc set still produces an invalid DCEL incidence relation. Correct source-edge canonicalization must be proven before simplification.
5. **Production output:** plane, cylinder, seam, torus, mechanical feature, and the Phase 20 cylinder remain invalid at completion or strict validation.
6. **Memory reconciliation:** telemetry covers key stage containers but not enough of process RSS to satisfy the ownership-accounting gate.

## Next turn

The next authoritative turn is **P5-CB91 through P5-CB98 code changes + compile-only build**.

It must:

- make parity replacement pieces inherit one exact pre-transaction scope, with typed diagnostics identifying the first missing replacement edge/twin;
- add field-level reusable-product key mismatch diagnostics and produce positive exact reuse;
- construct explicit compatible node occurrences for the invalid-midpoint fixture;
- rebuild the cylinder fixture from one canonical intrinsic edge representation and prove DCEL incidence before simplification;
- repair the earliest invalid producer for each remaining production-output case without weakening validation;
- reconcile Eigen, associative-container, nested diagnostic, and overlapping-lifetime memory ownership;
- add regression sources for each corrected contract;
- compile only the four required targets and execute no binary.

P5 remains open. PR #8 must remain open, draft, and unmerged.
