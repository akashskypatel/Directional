# M1c Field-Transition Consumer — Code + Build Plan

**Status:** authoritative next turn  
**Turn type:** Code + Build only  
**Architecture milestone:** M1 — authority kernel and compatibility boundary  
**Depends on:** immutable accepted M1a + M1b  
**Product behavior delta intended:** none  
**Review policy:** `never`

## 1. Objective

Migrate exactly one additional real production consumer to the accepted M1 authority kernel without changing product behavior:

`build_surface_cell_network / trace_surface_field -> surface_cell_tracing_detail::resolve_branch_transition`

The bounded seam is the authoritative `fields::CrossFieldEdgeTransition` path inside `resolve_branch_transition`. Today this path consumes source faces, source-edge vertices, and quarter-turn matching as bare integers. M1c makes those semantic facts typed at the point of consumption while leaving the legacy field-result representation intact as a compatibility boundary.

M1c is **not** a field-system refactor. It must not migrate producers, public `CrossFieldResult`, chart ownership, canonical routes, topology-region planning, periodic certificates, rail scheduling, completion, validation, or product policy.

## 2. Accepted entering authority

M1b is immutable accepted under:

`.agents/Directional/Architecture_M1b_First_Production_Consumer_Artifact_Only_Test_Benchmark_Report.md`.

Exact comparison authority:

| Evidence | Value |
|---|---|
| M1b implementation | `0340addf21473854856266ff00cb68915ce24ef0` |
| M1b build/event | `17c61b8d2eb835bd734010e160e6cd6b7dc9f5cf` |
| M1b result artifact | `9042940168` |
| M1b result SHA-256 | `9a24672179dc6fbc57fedcd4d5826fb4a7c4cf4cb1962c06013e1e84758bb46b` |
| M1b log artifact | `9042940336` |
| M1b log SHA-256 | `c39995e4ce496b6cb64608807a23b999330fa8b5333de61ebf939c3b5e391614` |
| Package manifest | **53/53**, `319cb95e6d283f6b786565c0c9863755777ff0518ff5375364521c61583e39f1` |
| M1b focused | **6/6** |
| validation | **77/77** |
| M1a authority | exact 14, **14/14** |
| T1 oracle | exact 29, **29/29** |
| Direct required-green | Plane / MultiFaceSeam / CloseSheets / Cylinder green and oracle-clean |

Bunny remains known-red `NotProductionReady:completion` with independent-oracle-before-fatal evidence; Vase remains bounded/nonreturning at 60 seconds. Neither is an accepted green baseline.

## 3. Current legacy seam

`resolve_branch_transition` currently receives:

- raw `sourceFace` / `targetFace` integers;
- a raw source-edge `uint64_t` representation key;
- `CrossFieldEdgeTransition.firstFace`, `secondFace`, `sourceVertex0`, `sourceVertex1`, and `matching` as integers;
- an authoritative `edgeTransitions != nullptr` branch which fails closed if the transition is missing, has the wrong reciprocal faces, or has the wrong source edge;
- a separate legacy `edgeMatching` vector branch used only when `edgeTransitions == nullptr`.

Current authoritative matching behavior is:

```text
matching := transition.matching
if traversing secondFace -> firstFace:
  matching := -matching
targetBranch := mod4(sourceBranch + matching)
```

M1c must preserve that truth table exactly while making the semantic decision use checked source IDs, canonical source-edge identity, and `QuarterTurn` algebra.

## 4. Allowed implementation scope

Default allowed paths:

1. `src/geometry/SurfaceCellTracing.cpp`;
2. `tests/SurfaceCellsPhase10Tests.cpp`.

`include/directional/geometry/SurfaceCellTracing.h` may be changed **only** if a narrowly typed detail-helper signature is genuinely required for compile-time domain proof. Prefer a `.cpp`-local typed helper and avoid public/detail-header expansion when possible.

No CMake change is expected: M1 authority support is already linked once through `directional_core`, and `SurfaceCellsPhase10Tests.cpp` is already part of `directional_surface_cell_producer_tests`.

Any need to edit a different production/test/build path is a stop condition requiring plan revision before coding.

## 5. Required implementation

### 5.1 Checked source-face consumption

Within the authoritative `edgeTransitions != nullptr` path:

1. preserve existing topology/adjacency checks first;
2. convert `sourceFace` and `targetFace` through `LegacyAuthorityAdapters::source_face(..., faces.rows())`;
3. convert the selected transition's `firstFace` and `secondFace` through the same named adapter;
4. typed conversion failure returns the existing invalid `BranchTransitionResult` path; do not clamp, wrap, substitute, or fall back.

Face reciprocity for the authoritative transition must be decided from `SourceFaceId`, not raw numeric coincidence.

### 5.2 Canonical typed source-edge identity

For the selected authoritative transition:

1. convert `sourceVertex0` and `sourceVertex1` with `LegacyAuthorityAdapters::source_vertex(..., vertices.rows())`;
2. construct `SourceEdgeTopologyKey::make(v0, v1)`;
3. reject typed conversion or degenerate-edge failure through the existing invalid-result path;
4. compare the typed canonical edge to the existing raw `edgeKey` only at the compatibility representation boundary by explicitly converting the typed endpoints back to legacy row indices and calling the existing representation-key function.

Endpoint order must not become semantic identity. Do not add a second hash/key scheme.

`EdgeTransitionLookup` and its `uint64_t` map storage remain legacy representation in this slice. M1c changes the **consumer validation boundary**, not the lookup producer/storage schema.

### 5.3 Exact quarter-turn transport

For authoritative transition matching:

1. create `QuarterTurn transport = QuarterTurn::from_integer(transition.matching)`;
2. if traversing the transition in reverse, use `transport.inverse()` for the semantic branch transport;
3. compute the target branch from the typed quarter turn modulo four;
4. preserve `BranchTransitionResult.matching`'s existing legacy signed integer value (`matching` forward, `-matching` reverse) so downstream diagnostics/certificate behavior does not change in this slice.

This explicitly separates semantic transport from compatibility representation. Do not replace the public/internal result field with `QuarterTurn` in M1c.

### 5.4 Preserve the fallback branch

When `edgeTransitions == nullptr`, the current `edgeMatching` / `edgeEffort` vector path remains **byte-for-semantics unchanged**. It is a separate legacy compatibility boundary and must not be migrated opportunistically.

When `edgeTransitions != nullptr`, malformed/missing authoritative transition metadata must continue to fail closed. It must never fall through to the legacy matching vector or geometric best-turn inference.

## 6. Explicit non-goals

Do not change in M1c:

- `fields::CrossFieldEdgeTransition` public layout or `CrossFieldResult` storage;
- `sourceEdge` representation or introduce `InteriorTransitionId` into the producer yet;
- `FieldChartId`, `TransitionStep`, `CanonicalRoute`, or chart construction;
- `edge_transition_lookup` ownership/storage schema beyond any strictly necessary local compatibility call;
- `edgeMatching` fallback semantics;
- effort calculation/storage;
- geometric tangent transport, ray orientation, family/sign encoding, or best-turn fallback;
- topology-region, isolation-seam, periodic-holonomy, certificate, rail, arrangement, completion, quotient, optimization, validation, or diagnostic policy;
- fixtures or benchmark acceptance;
- G4-R007, G4-B002/B003/B004, Bunny, or Vase behavior.

## 7. Mandatory regression-pattern review

### `RP-01` — authority-domain conflation

**Touched.** Source face and source vertex integers must cross named checked adapters once before semantic comparisons. Face IDs and vertex IDs must remain non-interconvertible.

Invariant: no raw face/vertex numeric coincidence decides authoritative transition reciprocity or source-edge identity after conversion.

Counterexamples: out-of-range transition face; out-of-range/negative transition source vertex; face/vertex domain swap if a typed helper is exposed.

### `RP-05` — representation-dependent identity

**Touched.** Source-edge endpoint order/hash representation must not define semantic edge identity.

Invariant: `SourceEdgeTopologyKey(v0,v1) == SourceEdgeTopologyKey(v1,v0)` while representation conversion occurs only at the existing map-key boundary.

Counterexample: endpoint-reversed authoritative transition must resolve identically.

### `RP-07` — cyclic topology linearization

**Touched.** Quarter-turn matching is cyclic modulo four and reverse traversal is algebraic inverse.

Invariant: `+5` has the same semantic branch transport as `+1`; reverse traversal composes with forward to identity modulo four. Preserve the legacy signed `BranchTransitionResult.matching` representation until its own later migration.

Counterexamples: `+5`, `-1`, forward/reverse round trip.

### `RP-02 / TA-05` — independent test authority

**Preservation boundary.** Focused transition tests are not product proof. The following immutable turn must preserve M1b/M1a/T1 and direct product evidence.

`RP-03/04/06/08/09` are not migrated by this slice and must remain behaviorally untouched.

## 8. Focused test additions

Add only the minimum semantic/counterexample coverage to the existing default-built `directional_surface_cell_producer_tests`, preferably under a dedicated suite such as `SurfaceCellFieldTransitionAuthorityMigration`.

Required contracts:

1. **ForwardQuarterTurnUsesTypedModuloTransport** — an authoritative `matching=+1` transition resolves the expected target family/sign/branch behavior.
2. **ReverseTraversalUsesExactQuarterTurnInverse** — resolving the same transition backward uses the exact inverse and round-trips the branch modulo four.
3. **EquivalentQuarterTurnsNormalizeSemantically** — `matching=+5` produces the same semantic target family/sign as `+1`, while compatibility `BranchTransitionResult.matching` retains the legacy raw signed value.
4. **ReversedSourceEdgeEndpointsPreserveSemanticIdentity** — swapping transition source endpoints does not change acceptance/semantic transition.
5. **MalformedAuthoritativeFaceOrEdgeFailsClosed** — wrong/out-of-range face or source-edge metadata rejects and does not fall back to `edgeMatching` or geometric inference.
6. **LegacyMatchingFallbackRemainsUnchangedWhenTransitionMetadataAbsent** — the explicit `edgeTransitions == nullptr` compatibility path retains its accepted behavior.

Use real `resolve_branch_transition` inputs or the narrowest real production call that establishes these relations. Do not assert only counts/status/no-crash, and do not derive expected results by calling the same implementation helper being tested.

Retain explicit existing counterexample visibility in the following immutable turn:

- `SurfaceCellsPhase10.NonReciprocalSourceAdjacentIsolationSeamFailsClosed`;
- `SurfaceCellsPhase10.CurvedBoundedDiskInvalidReciprocalTransportFailsClosed`;
- the existing cylinder periodic-holonomy tamper that requires `PeriodicHolonomyMismatch`.

Do not weaken or rewrite those tests merely to accommodate M1c.

## 9. Code + Build execution boundary

This turn may:

- edit only the approved source/test paths;
- run static source inspection;
- configure Release/static/Ninja;
- compile/link approved targets;
- package immutable binaries, fixtures, source diff/archive, compile database, source blobs, command-boundary metadata, and static test-name manifests.

This turn must **not** execute any generated Directional binary, GoogleTest discovery, test, benchmark, `ctest`, CLI/GUI/help/version command, fuzzer, or custom input.

Use `CMAKE_GTEST_DISCOVER_TESTS_DISCOVERY_MODE=PRE_TEST`.

Compile at minimum the existing acceptance matrix:

- `directional_core`;
- `directional_pipeline`;
- `directional_compiled_api_tests`;
- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_oracle_tests`;
- `directional_surface_cell_authority_kernel_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_surface_cell_validation_tests`;
- `directional_benchmarks`.

## 10. Code + Build acceptance

M1c Code + Build is complete only if:

1. the final implementation diff is bounded to the approved paths;
2. source-face/source-vertex authoritative transition checks use named checked adapters;
3. source-edge semantic identity is a `SourceEdgeTopologyKey` before representation-key comparison;
4. authoritative branch transport uses `QuarterTurn` and `.inverse()` rather than raw signed arithmetic for semantic resolution;
5. legacy result/fallback representations are intentionally preserved;
6. required semantic/counterexample tests are compiled into the default producer test target;
7. Release/static/Ninja approved targets compile and link completely;
8. package/source/manifest authority is complete and hashable;
9. `runtimeExecution=false` is explicit;
10. no generated project binary was executed.

Compile success does **not** accept M1c semantics.

## 11. Following immutable Test + Benchmark

The following turn must consume only the exact M1c artifact and must not rebuild or edit source.

Required evidence:

1. exact package/source/dependency/manifest preflight;
2. exact discovery of the new M1c focused suite and individual focused contracts all passing;
3. explicit existing transition counterexamples remain green;
4. complete relevant producer preservation, with zero-selection success rejected;
5. M1b six focused contracts + full validation **77/77** remain green;
6. M1a exact 14 discovery + **14/14**;
7. T1 exact 29 discovery + **29/29**;
8. Plane, MultiFaceSeam, CloseSheets, Cylinder remain green/oracle-clean;
9. Bunny and Vase remain explicit known-red/safety-only cases;
10. postflight package hashes remain exact.

### Long-running Bunny/Vase procedure

Per explicit user authorization, Bunny and Vase may execute through a temporary **GitHub Actions artifact-only runtime workflow** instead of the local container to avoid execution-tool timeouts. That workflow must:

- download the exact immutable M1c artifact by build run/artifact identity;
- verify the GitHub artifact digest, package manifest, every package checksum, implementation metadata, and selected producer executable hash before runtime;
- never configure, compile, relink, regenerate, substitute, or edit product/test/fixture content;
- restore executable mode only after content-hash verification if `actions/download-artifact` strips it;
- run exact selected existing tests under explicit process guards;
- retain stdout/stderr, filter, return code, elapsed time, and evidence-artifact digest;
- remove temporary workflow/trigger files before turn closeout so the net implementation/test/build diff remains zero.

Bunny/Vase workflow success is orchestration success only; the underlying test disposition must be interpreted from the retained logs.

## 12. Stop conditions

Stop and revise the plan before coding if the slice requires:

- changing the public `CrossFieldEdgeTransition`/`CrossFieldResult` schema;
- migrating chart/route/transition-ID ownership;
- changing fallback or producer disposition policy;
- changing topology/periodic certificates or G4 behavior;
- fixture/validator/benchmark changes;
- more than the approved narrow source/test paths.

If the immutable following turn finds any regression, remain at M1c and return to a corrective Code + Build. Do not advance to another consumer.
