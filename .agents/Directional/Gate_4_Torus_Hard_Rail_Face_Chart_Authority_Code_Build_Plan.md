# Gate 4 Torus Hard-Rail Face-Chart Authority — Code + Build Plan

Status: **completed; see `.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Code_Build_Report.md`**
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Purpose

Thread exact quotient-retained multi-chart and hard-rail equivalence authority into final source-authoritative validation so each output quad is validated on its unique authorized source-chart side even when a hard-rail vertex's deterministic scalar `SurfacePoint` represents the opposite side.

This is not a validator relaxation. Scalar provenance remains exact positional authority, hard features remain chart barriers, and alternate chart use is permitted only through complete exact lineage plus explicit hard-rail equivalence provenance.

Entering runtime authority is:

`.agents/Directional/Gate_4_Canonical_Transition_Test_Authority_Remediation_Artifact_Only_Test_Benchmark_Report.md`

Artifact `9029584083` accepts all seven corrected focused contracts, retains plane, multi-face seam, close sheets, and cylinder direct strict-valid **3/3** behavior, and isolates exact torus **0/3** at `completion/output-validation / LocalSheetMismatch` after 192 quads, complete `4/8/4` authority consumption, and materialized `1/0/0` topology.

## Design-first statement

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: exact torus rejects 74 valid post-quotient faces as LocalSheetMismatch
Missing design contract: final validation must consume retained per-vertex chart/equivalence authority, not scalar representatives alone
Smallest general implementation change: project existing PureQuadVertexLineage authority into optimizer/validator face-chart compatibility
Observable material-progress condition: exact positive/negative authority tests compile and the packaged torus success contract remains unchanged
Explicitly deferred work: runtime execution; nonzero Z4 rotation; hard-rail scheduling; positive multi-isolation lineage; sphere and later gates
```

## Entering invariant

`build_authoritative_phase_front_mesh` already retains the required source truth:

- one deterministic exact scalar `SurfacePoint` per quotient vertex;
- complete sorted `PureQuadVertexLineage.sourceCharts`;
- complete `sourceTopologyRegions` and `sourceIsolationSheets`;
- exact `PureQuadEquivalenceProvenance`, including `HardRail` kind, rail identity, reciprocal front ownership, and canonical source-route topology.

The current loss occurs downstream: `SurfaceOptimizationConstraints` and `SourceAuthoritativeMeshValidatorOptions` carry scalar `vertexProvenance`, while the authoritative phase-front path leaves `outputQuadSourceFaces` unset. `SourcePointLabelSupport::compatible_chart_faces` then sees only one scalar declared chart per vertex. Because a hard feature correctly splits chart-transition components, a stitched rail vertex can authorize both sides in lineage while its scalar representative names only one. Quads on the other side fail.

Do not modify quotient formation or choose a different scalar representative to hide this loss. A single scalar point cannot represent both valid sides.

## Allowed files

Only:

- `include/directional/geometry/SurfaceMeshOptimizer.h`;
- `include/directional/validation/SourceAuthoritativeMeshValidator.h`;
- `src/geometry/SurfaceMeshOptimizer.cpp`;
- `src/validation/SourceAuthoritativeMeshValidator.cpp`;
- `src/pipeline/RemeshPipeline.cpp`;
- `tests/SurfaceMeshOptimizerPhase22Tests.cpp`.

No edit to `PureQuadCompletion`, phase-front quotient construction, tracing, source-chart graph construction, fixtures, manifests, CMake, workflows, benchmark code/acceptance, completion/simplification, or unrelated tests is authorized. The existing exact committed torus test already requires direct strict-valid success and must not be weakened.

If an implementation dependency outside this list is genuinely unavoidable, stop and document the exact type/layering reason before expanding scope. Do not silently broaden the patch.

## Required implementation

### 1. Carry a narrow validation-authority projection

Add the smallest value type needed by optimization/final validation to represent, per output vertex:

- the exact retained source charts relevant to validation;
- the exact hard-rail equivalence records that authorize crossing from the scalar representative's declared chart to another retained chart.

Project this data from `completedVertexLineage` in `RemeshPipeline.cpp` when constructing `SurfaceOptimizationConstraints`, and forward it unchanged through `validate_final_surface_mesh` into `SourceAuthoritativeMeshValidatorOptions`.

The projection must be sorted/deduplicated, cardinality-aligned with output vertices, and independent of source face-row order. It must not copy topology-region IDs or isolation-sheet counts as compatibility permission. Existing scalar `vertexProvenance` remains required and authoritative for barycentrics, position, component, sheet, and source-entity support.

Do not reinterpret `PureQuadFaceLineage::sourcePatch` as a source-triangle row. Do not populate `outputQuadSourceFaces` from an integer-ID coincidence. If a unique center/source face can be derived from exact chart authority, record it only through that derivation; otherwise carry the exact compatible chart-face set explicitly.

### 2. Resolve one exact compatible chart side per output face

Extend the source-label/chart compatibility path so a face is accepted only when its corner authority yields one unique compatible source-chart side.

For each output corner:

1. require valid scalar provenance exactly as today;
2. begin with the scalar point's declared chart/support;
3. admit an alternate retained chart only if:
   - that exact chart is present in the vertex's retained authority;
   - exact source support places the output point on the shared hard rail;
   - an explicit retained `HardRail` equivalence with matching rail/source-route topology authorizes that crossing;
   - the relation is reciprocal and unambiguous.

Intersect/propagate the four corner choices through existing exact source adjacency and chart-component rules. Acceptance requires one unique compatible chart side for the whole quad. Zero candidates remains `LocalSheetMismatch`; more than one genuinely distinct candidate must also fail closed rather than choosing by row, ID, count, lexical order, distance, or first occurrence.

Ordinary source-edge/vertex rebinding inside one chart component remains governed by the existing transition graph. Periodic equivalence does not become generic hard-rail chart permission. A hard rail remains a barrier unless the exact quotient lineage for that output vertex explicitly crossed it.

### 3. Use the same authority throughout optimization and final validation

Every optimizer helper that derives a quad label, compatible chart-face set, reference surface point, centroid projection, or final validator options must consume the same resolved authority. Do not make the checkpoint validator pass while leaving optimizer projection on the scalar-only path.

The initial completion checkpoint, optimization iterations, rollback validation, and final validation must agree on the face's authorized chart side. Optimization may update scalar `SurfacePoint` projections but may not invent, delete, or broaden retained chart/equivalence authority.

### 4. Fail closed on malformed authority

Reject at least:

- missing per-vertex authority when alternate-chart use is required;
- a retained chart not supported by exact source geometry;
- missing, wrong-kind, wrong-rail, wrong-route, nonreciprocal, or ambiguous hard-rail equivalence;
- an authority vector whose cardinality does not match output vertices;
- a face whose corners resolve to disconnected components or close/opposing sheets;
- an output face with more than one genuinely distinct compatible side.

Use the existing `LocalSheetMismatch` where it remains the precise public classification. Introduce a narrower typed code only if it adds exact diagnosability without changing accepted behavior; do not replace semantic assertions with a new name alone.

## Required tests

Add focused tests in `tests/SurfaceMeshOptimizerPhase22Tests.cpp` using small source-authoritative meshes, never fixture IDs or predicted output counts.

1. **Positive hard-rail stitch:** two output quads lie on opposite sides of one exact hard rail and share rail vertices. The deterministic scalar representatives at shared vertices name one side; complete retained charts plus reciprocal `HardRail` equivalence allow each quad to resolve its own unique side and pass.
2. **Missing equivalence:** remove the required hard-rail equivalence while retaining the alternate chart; the opposite-side quad fails `LocalSheetMismatch`.
3. **Tampered authority:** wrong rail identity or canonical route, and an unsupported extra chart, each fail closed.
4. **Ambiguous authority:** construct two genuinely distinct authorized candidates; validation rejects rather than selecting by order.
5. **Disconnected close sheets:** spatially coincident/near source sheets remain incompatible even if a chart record is injected without exact rail support.
6. **Face-row invariance:** reverse source face rows and remap exact authority; acceptance and the resolved semantic side remain unchanged.
7. **Scalar provenance preservation:** existing invalid barycentric, position, component, and sheet cases retain their exact failures. Full lineage must not mask them.

Retain the existing `SurfaceCellsPhase10.ExactCommittedTorusDoesNotTreatIsolationSeamAsBoundedDiskBoundary` assertions unchanged: direct success, no fallback/recovery, complete region/seam/relation consumption, one component, zero boundary loops, Euler zero, complete output lineage, and `CompletedSurfaceCells` origin.

## Static verification before build

Inspect the final diff and prove:

- only the six allowlisted files changed;
- quotient construction, scalar representative selection, fixtures, manifests, CMake, workflows, and benchmark acceptance are byte-identical;
- alternate chart compatibility requires both retained chart membership and matching explicit hard-rail equivalence;
- no global union across source hard-feature edges was introduced;
- no source face/region/sheet/rail numeric ID, container order, count, frequency, hash, proximity, analytical fixture parameter, or predicted cardinality selects authority;
- all new per-vertex/per-face authority has exact size and validity checks;
- existing scalar provenance and close-sheet protections remain active;
- the torus success assertion and all typed negative assertions remain unchanged;
- whitespace, syntax, include layering, and public-header compilation checks are clean.

## Compile-only boundary

Commit and push the exact implementation before compiling. Use Release/static/Ninja and GoogleTest `PRE_TEST`. Compile/package exactly:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Do not execute any generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI command, help/version command, or custom input. `runtimeExecution` must remain `false`.

Package the five executables, two static libraries, all committed fixtures, exact changed-source closure, patch, compile database, logs, metadata, and recursive checksums. Record exact source blobs, implementation/build commits, toolchain/submodules, target list, artifact digests, and retention. Any temporary workflow must be removed in safe order after artifact verification, retaining only `.github/workflows/agent-source-snapshot.yml`.

## Following artifact-only acceptance

The Code + Build turn must write an immutable artifact-only Test + Benchmark plan for its exact artifact. That next plan must:

- preflight every artifact/source/dependency identity before runtime;
- discover the four GoogleTest executables exactly once;
- run each new positive/negative face-chart authority test individually;
- run the seven accepted canonical transition/periodic/retention contracts individually;
- preserve topology/isolation/hard-rail, polygonal/curved/mixed, direct G0-G3, validation, API, and historical completion authority;
- run the exact committed torus GoogleTest individually;
- repeat plane → multi-face seam → close sheets → cylinder → torus with three fresh processes each and recovery disabled;
- require torus direct strict-valid **3/3**, no fallback/recovery, `4/8/4` consumption, materialized/final one component, zero boundary loops, Euler zero, pure quads, and complete lineage before running sphere;
- run prescribed sphere only if torus passes and its full evidence is recorded first.

The entering semantic digests are same-artifact evidence, not cross-version goldens. No raw output count or hash may replace semantic acceptance.

## Explicitly deferred work

Do not address in this Code + Build turn:

- nonzero periodic `Z4` rotation and full rotation/translation counterfactuals;
- target-size-dependent shared hard-rail breakpoint scheduling;
- the positive multi-isolation quotient-lineage witness;
- multiple periodic-relation owner counterfactuals except as unchanged regressions;
- the historical completion/simplification ten or validator timing;
- prescribed sphere runtime, bunny, vase, G5/G6, fallback/recovery, or optimization quality work.

PR #8 remains open, draft, and unmerged. After all branch files and PR-body updates, the final repository write must be one new top-level PR #8 conversation comment.

## Completion record

Implementation `8f37612148f34bac63cf294000c17c7de2e03b41` compiled all seven approved targets in workflow run/job `31288505364 / 93181547076` at **113/113**. Immutable artifact `9030700527` has outer SHA-256 `6eb42943aa8b27c88fa2afa45e22c5fbc9aa16da2d5cc52748de6e3e45474adf`; its **49/49** recursive entries verify with manifest digest `698ee033667624819a369a4e64bd958eecfb2598e2c4cdd5caf7763fe6acad97`. Log artifact `9030700699` has SHA-256 `a3d327bd6d98091e4f4394970aab1823a53324f0106c380cde37a31e99d61263`.

`runtimeExecution=false`. The bounded workflow was removed at `5f26d42e596b1258106cf3e2f149e7542fbdc645` before trigger cleanup at `15cbac9224b0e424e02a37f769ee2712ad450976`; only `.github/workflows/agent-source-snapshot.yml` remains.

The authoritative next turn is artifact-only Test + Benchmark under `.agents/Directional/Gate_4_Torus_Hard_Rail_Face_Chart_Authority_Artifact_Only_Test_Benchmark_Plan.md`.
