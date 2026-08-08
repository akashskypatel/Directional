# Gate 4 Canonical Transition Index and Failure Retention — Code + Build Plan

Status: **completed by compile artifact `9028103772`**  
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`  
Mandatory review guard: **not active; artifact 9026181778 made material progress**

## Completion authority

Implementation `edc14d38f862b94941b249f564050e2e1f8f5287` compiled all seven approved targets in [workflow run 31279574458](https://github.com/akashskypatel/Directional/actions/runs/31279574458). Compile artifact `9028103772` has GitHub SHA-256 `05ddd9628d39a8a56dac7d12502003f1d26e01758b9ff4303206e91c6a6e931a`; its 48-entry recursive manifest verifies. `runtimeExecution=false`; this completed turn makes no runtime claim.

See `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Report.md`. The authoritative next turn is `.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Plan.md`.

## Entering authority

Use the current branch head after artifact-only closeout. Runtime authority is artifact **`9026181778`**, implementation `82151bf51bce9af9859282b2a03e295a0ee5a309`, as recorded in:

`.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`

The exact earliest failures are:

- plane and close sheets: `InvalidAuthoritativeTransitionSourceEdge`;
- cylinder and direct torus: `InvalidPeriodicCutAuthority`;
- failure-retention counterfactual: `retain=false` still exposes trace authority and route rejection preempts the injected failure.

## Design declaration

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: plane materialization at cell/edge 63/162
Missing design contract: one canonical interior transition-index domain from producer through materializer, plus public retain iff requested
Smallest general implementation change: normalize materializer-facing transition/periodic routes to one source-wide edge_matching_indices() table after exact transition validation, and split internal temporary retention from returned-context retention
Observable material-progress condition: plane and close sheets move past InvalidAuthoritativeTransitionSourceEdge, cylinder/torus move past numeric InvalidPeriodicCutAuthority, and the retain true/false test reaches one identical injected failure with context present iff requested
Explicitly deferred work: nonzero Z4 periodic rotation, shared hard-rail breakpoint scheduling, multi-isolation positive-witness correction, sphere, G5/G6, bunny/vase, historical completion repair, validator/timing thresholds, fallback/recovery, and optimization
```

## Exact source/test allowlist

Production and active regression edits are limited to:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp` only if an existing exact integration assertion needs to expose the normalized route contract.

No fixture, manifest, validator, benchmark acceptance, completion/simplification implementation, cross-field extraction, or unrelated test may change. CMake should remain unchanged because executable coverage is already correct. A bounded temporary workflow/payload may be used only under `GitHub_Workflow_Policy.md` and must be removed after exact artifact verification.

## 1. Define one materializer-facing interior index

Construct one source-wide compact table from `edge_matching_indices(edge_faces(full source faces))` before topology-region producers run. For every two-face transition topology `edgeKey`:

1. Require the **source-wide** `edge_matching_indices()[edgeKey]` to exist and be nonnegative. Do not rebuild the serialized route domain from a region-local active-face subset.
2. If `CrossFieldEdgeTransition` authority is supplied, require exactly one transition for the same canonical endpoint topology and reciprocal incident faces; retain its matching/effort and full-`EF` identity only as CrossField validation authority.
3. Write the source-wide compact `edge_matching_indices()` value—not the full `mesh.EF` row or a region-local compact value—to `SurfaceTraceSegment.transitionSourceEdge(s)`, `SurfaceFrontEdge.sourceRouteEdges`, and `SurfacePeriodicHolonomy.sourceRouteEdges/cutSourceEdges`.
4. Continue to carry canonical topology in the corresponding topology route and require equal lengths and exact per-position topology/index agreement.

Update comments/names needed to make the compact-domain contract explicit. Do not expand `edge_matching_indices()`, invent an interior index for genuine one-face boundaries, accept a route by topology alone where two-face transport requires an index, or rely on accidental numeric equality between domains.

## 2. Preserve transition validation

Normalization is not permission to discard CrossField authority. The producer must still fail closed for missing, duplicate, wrong-edge, wrong-face, nonreciprocal, or inconsistent matching/effort data. Existing malformed-holonomy and certificate tests must retain their typed behavior.

Add focused counterfactuals whose full `EF` row differs from the source-wide compact interior index and whose later topology region would receive a different region-local compact index. They must prove:

- every valid route carries the source-wide compact index and accompanying canonical topology, independent of topology-region partition/order;
- materialization accepts that exact pair;
- substituting either the full `EF` row or a region-local compact index is rejected;
- a genuine boundary still has non-empty topology and an empty interior-index route.

The test must use general source topology, not a fixture name or predicted output count.

## 3. Separate operational and public retention

Use two meanings explicitly:

- `retainRequested`: exactly `options.surfaceCells.retainIntermediateGeometry`;
- `retainForExecution`: temporary ownership needed by later stages or deterministic failure injection.

Internal data may remain alive long enough to reach the requested injected stage, but every success/failure return must expose retained trace/flow/arrangement context only when `retainRequested` is true. When false, clear the public context and its presence flags before return without changing the terminal failure code/stage.

The focused true/false test must run the same committed valid input and options except the retain flag, reach the same `InjectedStageFailure / tracing`, retain a nonempty trace network only for `true`, and expose no trace network/cells for `false`. If plane still cannot reach that injection after the index correction, use another committed production fixture already proven to reach it; do not weaken the equality or iff assertions.

## 4. Compile-only verification

Compile the existing approved Release/static/Ninja targets, including:

- `directional_surface_cell_producer_tests`;
- `directional_surface_cell_completion_tests`;
- `directional_validation_tests`;
- `directional_api_compile_test`;
- `directional_benchmarks`;
- the two project static libraries.

Use `PRE_TEST` or equivalent compile-only-safe discovery. Do not execute any generated Directional binary, test, benchmark, `ctest`, discovery/list/help/version command, CLI/GUI command, or custom input. Compile success makes no runtime claim.

Package exact binaries, libraries, 27 fixtures, source closure/patch, compile/configure/toolchain/submodule logs, metadata, and recursive checksums. Record exact implementation/build commits, source blobs, workflow run/job, artifact IDs/names/digests, dependency revisions, compiler/CMake/Ninja versions, target counts, and `runtimeExecution=false`.

## 5. Required next artifact-only acceptance

The following Test + Benchmark turn must first prove immutable authority and discovery, then require:

- all previously green certificate, boundary, semantic-digest, topology/isolation, polygonal/curved/mixed, validation, and API tests remain green;
- the new mismatched-domain positive and tamper counterfactuals pass;
- `ComponentBoundaryAndEulerFactsAreComputedFromIncidence` passes for cylinder;
- `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested` passes exactly;
- plane and close sheets no longer report `InvalidAuthoritativeTransitionSourceEdge`;
- cylinder and torus no longer report `InvalidPeriodicCutAuthority` caused by route/index mismatch;
- direct multi-face seam remains deterministic with semantic digest `99c8be7159d05c2f` only as same-artifact semantic evidence, not a cross-version raw golden;
- no fallback, recovery, generic substitution, fixture-specific behavior, predicted output counts, or validator relaxation.

New truthful downstream failures may remain, but unchanged route-index failures do not satisfy material progress. Nonzero periodic rotation, hard-rail scheduling, and multi-isolation lineage remain separately reported blockers until a later bounded plan addresses them.

## Repository closeout

Keep PR #8 open, draft, and unmerged. Update the compile report, TODOs, design/testing docs, handoff, and next artifact-only plan only after exact artifact verification. Retain only `.github/workflows/agent-source-snapshot.yml`; remove bounded workflows, triggers, and payloads in the safe order. The final repository write is one new top-level PR #8 conversation comment.
