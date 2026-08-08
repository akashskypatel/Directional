# Milestone G Production Readiness TODO

Last updated: 2026-08-08 UTC

## Current gate

G0 truthful authority [accepted baseline] → G1 uniform phase-front plane [accepted baseline] → G2 cross-chart / close-sheet isolation [accepted baseline] → G3 periodic closure / holonomy [accepted baseline] → **G4 topology-distinct completion and singularities [active; blocked with material progress]** → G5 adaptivity/features → G6 bunny/vase production success → G7 hardening.

## Completed artifact-only Test + Benchmark

Exact artifact **`9026181778`**, implementation `82151bf51bce9af9859282b2a03e295a0ee5a309`:

- build/log artifacts `9026181778 / 9026181889`;
- workflow run/job `31272661747 / 93141125742`;
- cleanup/build `846b23a1175f541d86e880c993784715c995ef20`;
- outer SHA-256 `0682ae9fe6e98eefac8e4ddb2ccc8db8407326d7b872ec6da1d945aa8a59b79d` / `d53a060c2b3b20205ce71b3cf44f0fe9f14a2a207a176ec74faf9a8d57e9c890`;
- internal manifest `c63931f3cd9c6261710bd9db255a49aa03029a39d062fe21c714529c4b31fdb1`, recursive **48/48**;
- Release/static/Ninja **113/113**, five executables, two project libraries, 27 fixtures, `runtimeExecution=false`;
- exact source/dependency/fixture/log authority verified before execution;
- all **33/33** transition-quotient counterfactuals discovered;
- no source/test/build/fixture/validator edit, configure, rebuild, relink, or artifact substitution.

Runtime report:
`.agents/Directional/Gate_4_Boundary_And_Isolation_Transport_Certificate_Artifact_Only_Test_Benchmark_Report.md`

## Material progress retained

- topology-only genuine source boundaries now pass their positive and invented-index counterfactuals;
- reciprocal isolation-seam certificate positive, missing, duplicate, wrong-owner, wrong-sheet, and nonreciprocal cases pass;
- topology/isolation/hard-rail group **10/10**;
- polygonal/curved/mixed group **12/12**;
- semantic-digest permutation invariance and connectivity/winding/source-support/component/lineage sensitivity pass;
- multi-face seam completes directly **3/3** with 64 pure quads, complete lineage, stable structural `48661113839528d4`, stable semantic `99c8be7159d05c2f`, and no fallback/recovery;
- validation **60/60** and API **8/8** remain exact;
- completion/simplification remains **154/164** with the same historical ten failures.

This satisfies the repository's material-progress definition, so the mandatory no-progress Review guard is not active. Optional review policy remains `never`.

## Current direct blockers

| Fixture | Result, three processes | First invalid authority |
|---|---:|---|
| plane | **0/3** | `InvalidAuthoritativeTransitionSourceEdge`, `63/162` |
| close sheets | **0/3** | `InvalidAuthoritativeTransitionSourceEdge`, `199/12` |
| cylinder | **0/3** | `InvalidPeriodicCutAuthority`, `287/3` |
| torus | **0/3** | `InvalidPeriodicCutAuthority`, `191/0` |

Torus remains phase-front `Produced` with four topology regions, eight internal isolation seams, four periodic relations, and consumed authority `0/0/0`. Sphere is deferred.

Focused totals are transition quotient **24/33**, periodic/torus/cylinder **5/7**, remaining Phase10 **35/39**, and direct G0-G3 GoogleTests **1/4**. Producer bounded is **143/161**; bounded aggregate is **365/393**.

## Canonical transition-index blocker

The producer has two numeric edge domains:

- full `mesh.EF` rows in `CrossFieldEdgeTransition.sourceEdge`;
- one source-wide compact two-face interior domain from `edge_matching_indices(edge_faces(full source faces))`.

`source_edge_provenance()` writes the full `EF` meaning when CrossField transitions are present, while region producers may also rebuild a region-local compact numbering. Materialization always validates against the source-wide compact table. Canonical topology already travels beside the route and must remain exact; the numeric route must be normalized to the source-wide compact interior index after validating the supplied CrossField transition's topology and reciprocal faces. Genuine one-face boundaries retain topology-only authority and no invented interior index.

## Public failure-retention blocker

Failure injection currently forces `retainIntermediateGeometry` true internally and the same value controls returned context. Internal lifetime and public retention must be separated so identical injected failures expose trace authority iff the caller requested it.

## Explicit follow-on blockers

- nonzero periodic `Z4` holonomy is rejected before relation construction and rotation is hard-coded zero;
- independently produced exact hard-rail sides need one shared source-authoritative breakpoint schedule;
- the multi-isolation positive test needs a proven reciprocal cross-sheet quotient precondition before product lineage can be judged.

These are not included in the next narrow implementation slice.

## Mandatory next turn

**Code + Build only** under:

`.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Code_Build_Plan.md`

Allowed production/test files:

- `include/directional/geometry/SurfaceCellTracing.h`;
- `src/geometry/SurfaceCellTracing.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceCellTransitionQuotientTests.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp` only if needed to expose the normalized integration contract.

CMake, fixtures, manifests, validators, benchmarks, completion/simplification, cross-field extraction, and unrelated tests remain unchanged. Compile/package only; no generated runtime command.

## Next artifact acceptance

The following immutable artifact-only turn must prove:

- valid routes whose full `EF` row and region-local compact value differ from the source-wide compact index materialize, while either substituted alternate is rejected;
- plane/close sheets move past `InvalidAuthoritativeTransitionSourceEdge`;
- cylinder/torus move past route-index `InvalidPeriodicCutAuthority`;
- the retain true/false test reaches identical `InjectedStageFailure / tracing` and exposes context iff requested;
- every previously green certificate, boundary, digest, topology/isolation, polygonal/curved/mixed, validation, API, and multi-face-seam contract remains green;
- no fallback/recovery, fixture-specific behavior, predicted count, or validator relaxation.

G4 remains active until exact torus directly produces strict-valid pure quads with complete lineage, one component, zero boundary loops, Euler zero, and all `4/8/4` authority consumed. PR #8 remains open, draft, and unmerged.

Every completed turn ends with a new top-level PR #8 conversation comment as the final repository write.
