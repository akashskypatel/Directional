# Gate 4 Boundary and Isolation-Transport Certificate - Code + Build Plan

Status: **authoritative next turn**
Turn type: **Code + Build only**
Validated source: `7f486632b154a303789df6c4dd44f602c8c71281`
Review decision: `.agents/Directional/Gate_4_Transition_Quotient_Runtime_Regression_Independent_Design_Review_Report.md`
Planning commit: `a54f5d00ef5ae3ac59de0f5a7d7e0b42e74ca045`

## Turn objective

Restore genuine source-boundary authority, replace the impossible cell-side-only seam check with explicit reciprocal seam-transport certificates, and package independently executable counterfactuals without changing the explicit occurrence quotient.

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest regressed contract: genuine one-face source boundary
Earliest active G4 blocker: materializer cannot consume internal isolation-seam authority
Smallest general change: topology-only exterior routes plus producer-issued reciprocal seam certificates
Observable CB condition: all approved targets compile and the immutable artifact contains every focused test source with runtimeExecution=false
Deferred: runtime acceptance, sphere, G5/G6, bunny/vase, historical completion repairs, validators, fallback/recovery, unrelated optimization
```

## Turn boundary

Allowed:

- edit only the file allowlist below;
- configure Release/static/Ninja with GoogleTest `PRE_TEST`;
- compile/link the existing seven approved targets;
- inspect source, compiler output, libraries, package contents, manifests, and checksums;
- repair compile errors within the same bounded contract.

Forbidden:

- execute any generated Directional binary, test, benchmark, CLI/GUI, help/version/list/discovery command, `ctest`, or custom input;
- edit fixtures, validators, benchmark inputs, tolerances, or unrelated implementation;
- enable the historical test suite;
- use fallback/recovery, representative sheets, lattice/position welding, synthetic topology, or fixture-specific behavior;
- merge or mark PR #8 ready.

## Exact file allowlist

Production:

- `include/directional/geometry/SurfaceCellTracing.h`
- `src/geometry/SurfaceCellTracing.cpp`
- `src/pipeline/RemeshPipeline.cpp`

Tests/build:

- `tests/SurfaceCellsPhase10Tests.cpp`
- `tests/SurfaceCellTransitionQuotientTests.cpp` (new)
- `cmake/DirectionalTests.cmake`

Planning/handoff records may be updated after the compile-only result. Any required change outside this list stops the turn for review rather than broadening silently.

## 1. Restore boundary authority

In `assign_open_front_boundary_authority()`:

- resolve exact source incidence before consulting the interior index;
- append canonical topology for every source-supported route segment;
- classify a one-face route as `GenuineSourceBoundary` without an interior index and require its `sourceRouteEdges` to remain empty;
- require a valid one-to-one interior index for hard rail and embedded relief routes;
- preserve periodic cut and ordinary transition strictness at their existing owners;
- reject mixed-kind paths, duplicate/noncanonical routes, boundary routes carrying invented indices, and interior routes missing indices.

Do not change the domain or ordering of `edge_matching_indices()`.

Compile-visible tests must distinguish genuine boundary, ordinary interior, hard rail, embedded relief, and periodic cut authority.

## 2. Add reciprocal internal-isolation-seam certificates

Add a first-class certificate type and a deterministically ordered collection on `SurfacePhaseFrontResult`.

Each certificate must retain:

- source component and topology-region owner;
- canonical source-edge topology and valid interior source-edge index;
- canonical incident source-face identities and local-isolation labels;
- forward/reverse reciprocal quarter-turn transport.

Create exactly one certificate for every retained `internalIsolationSeamTopology` entry only after the producer has validated exact adjacency and reciprocal field transport. Canonicalization and hashing must be invariant to face-row/discovery order and sensitive to topology, owner, sheet endpoints, index, and transport mutation.

Missing, duplicate, ambiguous, nonreciprocal, cross-component, cross-region, same-sheet, boundary, or malformed certificates reject with a typed reason before partial authority escapes.

## 3. Consume certificates in quotient materialization

Replace the current requirement that every seam appear in cell-boundary `transitionSourceEdges`.

Materialization must:

1. validate an exact bijection between region seam topology and certificates;
2. validate every certificate against source incidence and supplied component/sheet labels;
3. build the permitted local-sheet connectivity graph per topology region;
4. require every cell/front/relation/quotient lineage sheet set to be connected by that graph;
5. validate any explicit seam crossing/equivalence against the owned certificate and retain its canonical topology in equivalence lineage;
6. set consumed seam counts only after all checks pass;
7. hash and diagnose certificate authority deterministically.

Keep the existing explicit four-occurrence union-find. Equivalence remains generated only by reciprocal ordinary sides, exact hard-rail counterparts, or an explicitly owned full periodic `R^r p+t` relation. Do not merge by region/lattice/position and do not select a representative local sheet.

## 4. Supply default executable counterfactuals

Add `tests/SurfaceCellTransitionQuotientTests.cpp` to the existing default `directional_surface_cell_producer_tests` target. Link the existing `src/bench/BenchmarkQuality.cpp` into that target. Keep `DIRECTIONAL_BUILD_HISTORICAL_TESTS=OFF`.

The new/default executable must contain independently named tests for:

- topology-only genuine boundary and malformed boundary/index combinations;
- reciprocal seam-certificate positive path and missing/duplicate/wrong-owner/wrong-sheet/nonreciprocal mutations;
- multi-isolation materialization without representative-sheet substitution;
- equal lattice/chart occurrences without reciprocal connectivity remaining distinct;
- ordinary reciprocal endpoint orientation and wrong-endpoint rejection;
- full periodic rotation/translation positive path and tampered transform rejection;
- multiple periodic relations consumed by explicit owner under relation reordering, with swapped/missing owner rejection;
- hard-rail positive stitch plus missing/ambiguous counterpart rejection;
- scalar point plus complete sorted region/sheet/chart/support/equivalence lineage;
- repeated corner, nonmanifold edge/fan, artificial boundary, and computed Euler/component/boundary facts;
- identical deterministic pre-materialization failure retaining trace authority iff `retainIntermediateGeometry` is true;
- semantic digest invariance under vertex/face/component row permutation and sensitivity to connectivity, winding, source support, component separation, and lineage.

Counterfactuals must tamper semantic authority, not fixture IDs or expected output counts. Do not weaken existing assertions.

## 5. Strengthen retained integration contracts

Update `SurfaceCellsPhase10Tests.cpp` only where required to:

- require valid source boundaries to carry topology and no invented interior index;
- require the exact reciprocal isolation-seam fixture to materialize and consume its certificate;
- require the torus integration case to succeed directly once the quotient/certificate implementation is present; remove its permissive rejection branch;
- keep public topology diagnostics before retained-context dereference;
- keep a separate deterministic failure-path retention true/false test.

Do not encode torus cell, vertex, quad, or source-ID counts. The future Test + Benchmark may assert independently derived topology: one component, zero boundary loops, Euler zero, four retained regions, eight retained/consumed seams, and four retained/consumed periodic relations.

## 6. Compile-only verification and artifact

Before the authoritative build:

- review the exact diff and file allowlist;
- commit/push the coherent implementation;
- verify the remote head and clean source state;
- verify temporary workflow/payload paths are narrowly scoped.

Compile the existing approved target set in Release/static/Ninja with `PRE_TEST`. Package:

- the same five executables and two project libraries;
- exact source archive and implementation patch;
- source/blob/dependency/fixture authority;
- configure/build/toolchain/submodule logs;
- `runtimeExecution=false` command-boundary metadata;
- recursive checksum manifest.

Upload a separate always-produced detailed log artifact. Verify outer and recursive digests, source blobs, package closure, and absence of runtime commands. Remove the bounded workflow, trigger, and payloads after verification, preserving only `.github/workflows/agent-source-snapshot.yml`.

## Following artifact-only Test + Benchmark

The next turn must use only the immutable artifact and must not rebuild or patch it.

Required order:

1. verify artifact/source/dependency/fixture/log/checksum authority;
2. obtain focused names from packaged `--gtest_list_tests` and prove every reviewed counterfactual is present;
3. run focused boundary/certificate/quotient/lineage/incidence/retention/digest tests;
4. rerun retained topology-region, polygonal, curved, mixed, relief, hard-rail, periodic, validation, API, and bounded suites;
5. run plane, multi-face seam, close sheets, and cylinder in three independent processes and require direct deterministic strict-valid success with no fallback/recovery;
6. run exact torus in three independent processes and require direct pure-quad strict-valid output, complete lineage, one component, zero boundary loops, Euler zero, and all four regions/eight seams/four relations consumed;
7. skip sphere unless torus closes.

Any focused failure, retained G0-G3 regression, unconsumed authority, permissive torus rejection, missing semantic test, or fallback/recovery blocks acceptance. No predicted/golden torus output count is permitted.

## Exit record

Publish a Code + Build report with exact implementation/build commits, commands, target results, artifacts/digests, source blob manifest, checks deliberately not executed, and the exact artifact-only successor plan. Keep PR #8 open, draft, and unmerged. The final repository write is a new top-level PR #8 conversation comment.
