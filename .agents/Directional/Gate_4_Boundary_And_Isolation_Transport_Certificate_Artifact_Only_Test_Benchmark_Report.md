# Gate 4 Boundary and Isolation-Transport Certificate — Artifact-Only Test + Benchmark Report

Status: **blocked with material progress**  
Turn type: **Test + Benchmark only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Decision

Artifact **`9026181778`** is exact and executable, but it does not satisfy Gate 4. The candidate restores genuine-boundary handling far enough for **multi-face seam to complete directly and deterministically 3/3**, and all certificate-negative, semantic-digest, topology/isolation, polygonal/curved/mixed, validation, and API groups named below pass. Plane, close sheets, cylinder, and torus still fail before output. Sphere and the broader benchmark manifest were correctly skipped.

This run is material progress under `DESIGN.md`: an active direct fixture now passes and the previously missing certificate/counterfactual authority is live. The mandatory no-progress review guard therefore does not reactivate. The next authority is a bounded Code + Build plan for canonical interior transition identity and the retain/release contract.

## Immutable authority

Runtime used exactly:

- build artifact **`9026181778`** and log artifact **`9026181889`**;
- workflow run/job **`31272661747 / 93141125742`**;
- event commit `9f0e6de3e4a1f70eb02d2946072305c7b8c9b5ad`;
- implementation `82151bf51bce9af9859282b2a03e295a0ee5a309`;
- cleanup/build `846b23a1175f541d86e880c993784715c995ef20`;
- build/log ZIP SHA-256 `0682ae9fe6e98eefac8e4ddb2ccc8db8407326d7b872ec6da1d945aa8a59b79d` / `d53a060c2b3b20205ce71b3cf44f0fe9f14a2a207a176ec74faf9a8d57e9c890`;
- internal manifest SHA-256 `c63931f3cd9c6261710bd9db255a49aa03029a39d062fe21c714529c4b31fdb1`, recursive **48/48**;
- source archive SHA-256 `08fa7f4403145216c1316240a4494c7fa069d77f2518ddbc6346812bcb91bdba`;
- packaged/decoded patch SHA-256 `b092219704f360e2f013cdeab83a12c870ac8e804f52f325edcfca2d2a17faac` / `b93f420d7f9c8139663f8ff573613eeb23dd3c30073ff76c8b563c537fd07f10`.

Both ZIPs pass integrity checks. The package has the expected **49 files, 27 fixtures, five ELF executables, two valid project static libraries, Release/static/Ninja metadata, `PRE_TEST`, seven approved targets, and `runtimeExecution=false`**. All six recorded source blobs, dependency revisions, committed fixture blobs, packaged source/fixture copies, build/configure/toolchain/submodule logs, and library resolution match. Code + Build logs contain compile/link activity only and no generated project runtime invocation.

The only runtime mutation was the permitted extracted-copy symlink:

```text
artifact/bin/test-data -> ../test-data
```

Artifact and fixture bytes were unchanged. Within workflow and turn-state paths, the source closure contains only the durable `.github/workflows/agent-source-snapshot.yml` and no temporary trigger/payload file.

## Discovery and invocation integrity

`directional_surface_cell_producer_tests --gtest_list_tests` was executed exactly once. It discovered all **33/33** independently named `SurfaceCellTransitionQuotient.*` tests and the required strengthened `SurfaceCellsPhase10` tests.

An initial focused invocation from the extraction root exposed a packaged fixture-helper working-directory fallback and was retained only as an invocation-path diagnostic; seven fixture-backed cases could not locate their committed inputs. The authoritative focused and subsequent commands ran from `artifact/bin`, where the permitted symlink resolves every packaged fixture. No test, binary, manifest, or fixture was changed.

## Focused and retained tests

These groups overlap and are reported separately rather than summed:

| Group | Result | Runtime / peak RSS | Classification |
|---|---:|---:|---|
| `SurfaceCellTransitionQuotient.*` | **24/33** | `0.111350 s` / `13,992 KiB` | nine active contract failures |
| topology/isolation/hard-rail retained group | **10/10** | `0.023740 s` / `13,992 KiB` | retained |
| polygonal/curved/mixed retained group | **12/12** | `0.095348 s` / `13,992 KiB` | retained |
| periodic/torus/cylinder group | **5/7** | `0.082673 s` / `13,992 KiB` | torus hard-rail and cylinder route failures |
| remaining non-overlap `SurfaceCellsPhase10` | **35/39** | `0.842151 s` / `17,472 KiB` | one historical timing plus three active failures |
| direct G0-G3 GoogleTests | **1/4** | `0.838237 s` / `13,988 KiB` | only multi-face seam passes |

The 24 focused passes include topology-only genuine boundary, invented boundary index rejection, the certificate positive path and all five broken-certificate cases, coincident disconnected authority, reciprocal ordinary orientation, hard-rail positive/missing/ambiguous cases, malformed incidence cases, and all six semantic-digest invariance/sensitivity cases.

The nine focused failures are:

1. two multi-isolation/equivalence-lineage assertions do not observe a quotient vertex spanning multiple local sheets or a seam-bearing equivalence;
2. two winding-cylinder tests stop in the producer at `PeriodicHolonomyMismatch`;
3. three torus relation-owner tests stop before their assertions at `InvalidHardRailPairing`;
4. the cylinder incidence test stops at `InvalidPeriodicCutAuthority`;
5. the retain/release test sees `NotProductionReady` before its injected stage, and the `retain=false` result still exposes trace authority.

The retained 39-test group has the unchanged scheduler-sensitive `StrictValidatorOverheadStaysBelowFivePercent` failure plus `UniformPhaseFrontReliefGuidanceOnlyBlocksWhenEmbedded` (`InvalidAuthoritativeTransitionSourceEdge`), `PeriodicPhaseFrontDerivesAnnulusFromSourceTopology` (`InvalidPeriodicCutAuthority`), and exact plane (`NotProductionReady` at tracing).

## Direct deterministic matrix

Each fixture ran in three independent processes with `SurfaceCells`, fallback `Fail`, recovery disabled, zero warmups, and one measured run.

| Fixture | Result | First invalid authority | Stable authority / internal wall seconds |
|---|---:|---|---|
| plane | **0/3** | `tracing/phase-front-materialization / InvalidAuthoritativeTransitionSourceEdge`, cell/edge `63/162` | one region; consumed `0/0/0`; `0.006742 / 0.006883 / 0.006870` |
| multi-face seam | **3/3** | none | 81 vertices, 64 pure quads, one component, one boundary loop, Euler 1; structural `48661113839528d4`; semantic `99c8be7159d05c2f`; `0.754891 / 0.738027 / 0.785310` |
| close sheets | **0/3** | `tracing/phase-front-materialization / InvalidAuthoritativeTransitionSourceEdge`, cell/edge `199/12` | two regions; consumed `0/0/0`; `0.018118 / 0.021179 / 0.019734` |
| cylinder | **0/3** | `tracing/phase-front-materialization / InvalidPeriodicCutAuthority`, cell/edge `287/3` | one region, one periodic relation; consumed `0/0/0`; `0.034635 / 0.040580 / 0.034484` |

Multi-face seam reports `CompletedSurfaceCells`, complete valid lineage, strict-valid pure quads, no fallback/recovery, and identical structural and semantic hashes in all three processes. Its estimated simultaneous owned-memory peak is `530,468 B`; wrapper peak RSS is `13,984 / 13,992 / 13,984 KiB`.

Every failed process has phase-front disposition `Produced`, output origin `None`, and no fallback, legacy/input fallback, generic substitution, or source-grid recovery.

## Exact torus

Exact torus fails deterministically **0/3** at:

```text
tracing/phase-front-materialization / InvalidPeriodicCutAuthority
cell/edge 191/0
```

All three processes retain:

- phase-front disposition `Produced`;
- four topology regions, eight isolation seams, and four periodic relations;
- region Euler characteristics `[0,0,0,0]`;
- genuine boundary-loop counts `[2,2,2,2]`;
- local-isolation cardinalities `[1,1,2,1]`;
- periodic serialization `r=0`, `t=(24,0)`, route 24, cut 2;
- consumed region/seam/relation counts `0/0/0` and no materialized output;
- internal wall seconds `0.027633 / 0.027358 / 0.027539`.

Sphere was correctly skipped because torus did not close. The broader committed benchmark manifest was also skipped because focused/direct acceptance did not pass.

## Bounded suites

The producer suite excluded only the documented long BunnyRandom and Vase design-acceptance parameters.

| Suite | Result | Wrapper runtime | Peak RSS | Classification |
|---|---:|---:|---:|---|
| producer | **143/161** | `3.091359 s` | `23,144 KiB` | 18 failures described below |
| completion/simplification | **154/164** | `0.058797 s` | `13,972 KiB` | exact same ten historical failures |
| validation | **60/60** | `0.023067 s` | `13,908 KiB` | retained |
| compiled API | **8/8** | `0.018083 s` | `13,992 KiB` | retained |
| aggregate bounded | **365/393** | — | — | 28 failures |

The producer failures are the nine focused failures, the historical timing assertion, relief/annulus/exact plane, exact torus/cylinder, and the three direct plane/close-sheets/cylinder design-acceptance cases. Completion's ten failures are byte-for-byte the established FlowRep, PatchDescriptor, and simplification set; no new completion failure appeared.

## Source-bounded active failures

### 1. Two edge-index domains are conflated

`CrossField.cpp` records `CrossFieldEdgeTransition.sourceEdge` in the full `mesh.EF` row domain, which includes boundary edges. `edge_matching_indices()` deliberately enumerates only two-face interior source edges in a separate compact domain. When transitions exist, `source_edge_provenance()` returns the full `EF` row; without transitions it returns the compact matching index. Cell paths and periodic relations therefore serialize two meanings into the same `int` route.

Materialization reconstructs the compact interior table and interprets every `transitionSourceEdges`, `sourceRouteEdges`, and `cutSourceEdges` entry in that domain. Plane/close-sheets fail when a full `EF` row is looked up as a compact index; cylinder/torus fail when a periodic route's numeric entry does not match the compact index for its accompanying topology.

The correction must keep `edge_matching_indices()` interior-only, retain canonical topology separately, validate any supplied CrossField transition against that topology/faces, and emit one unambiguous **source-wide** compact interior matching index to materializer-facing routes. A region-local compact table is also invalid because it renumbers later topology regions. Numeric equality between full `EF` rows, region-local indices, and the source-wide compact domain may never be assumed.

### 2. Failure retention uses an internal need as a public request

`RemeshPipeline.cpp` currently computes:

```text
retainIntermediateGeometry = requested || injectFailureAfterStage >= 0
```

The same forced value controls returned context. Both branches of the true/false counterfactual inject a failure, so `retain=false` is silently promoted to retained public authority. The route-identity rejection also occurs before the intended injected failure.

The implementation must separate temporary internal ownership needed to reach an injected stage from the caller's public retain/release request, and every failure exit must publish or clear context according to the request only.

### 3. Nonidentity periodic rotation is rejected by construction

The periodic annulus producer accumulates reciprocal field matching, rejects whenever `normalized_branch(totalMatching) != 0`, and then hard-codes `quarterTurnRotation = 0`. The committed winding-cylinder fixture intentionally supplies a continuous cross field with nonzero `Z4` holonomy. The two focused failures are therefore a real missing producer capability, not a malformed fixture.

This remains deferred from the next narrow slice. A later implementation must retain the nonzero rotation and apply the complete affine action `R^r p + t` to cut endpoint lattice/branch state before materialization.

### 4. Hard-rail counterparts are generated independently

The aggregator groups hard-rail fronts by exact endpoint support and canonical route and requires exactly two entries. Exact torus at the Phase10 target size reaches `InvalidHardRailPairing`, proving that independently generated region fronts do not yet provide a conforming one-to-one breakpoint schedule on every shared hard rail.

This remains deferred until canonical transition identity is repaired. The eventual correction must derive or reconcile a shared source-authoritative rail breakpoint schedule; it may not pair by proximity, IDs, order, counts, or output geometry.

### 5. The multi-isolation positive witness is incomplete

The split-isolation fixture materializes successfully and its certificate is accepted, but no produced quotient class spans more than one local sheet and no output lineage contains a seam-bearing equivalence. The next test change must first establish a real reciprocal cross-sheet quotient precondition. If the current fixture does not create one, replace it with a valid authoritative scenario that does; do not weaken the assertion or synthesize lineage metadata. Product code changes are warranted only if that valid precondition is present and provenance is lost.

## Process decision and next authority

Compared with artifact `9024549134`, the candidate removes the common `InvalidFrontBoundaryAuthority` blocker, makes all 33 reviewed counterfactuals executable, validates the seam-certificate family, and restores direct multi-face seam. That is material product/contract progress even though G4 remains blocked.

With review policy `never` and no mandatory guard activation, the sole next authority is:

`.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Plan.md`

PR #8 remains open, draft, and unmerged.
