# Gate 4 Canonical Transition Test Authority Remediation — Code + Build Plan

Status: **completed by compile artifact `9029584083`**
Turn type: **Code + Build only**  
Active design gate: **G4 topology-distinct completion and singularities**  
Review policy: `never`

## Completion authority

Implementation `de5261c7185aef71807b0b4140c8f023a44874fd` compiled all seven approved targets in [workflow run 31284957305](https://github.com/akashskypatel/Directional/actions/runs/31284957305). Artifact `9029584083` has GitHub SHA-256 `b9c2926ac71d5c765ec6ed89da7dc4a3fecbf55d00f4b24deeb1d26336a05dad`; all 49 recursive manifest entries verify. `runtimeExecution=false`; runtime acceptance is deferred to the artifact-only plan named in the Code + Build report.

## Purpose

Repair five tests that encode an unexercised or obsolete transition-index witness so the already-compiled source-wide compact contract is tested organically. Do not change production behavior in this turn.

The following artifact-only report is entering runtime authority:

`.agents/Directional/Gate_4_Canonical_Transition_Index_And_Failure_Retention_Artifact_Only_Test_Benchmark_Report.md`

Implementation `edc14d38f862b94941b249f564050e2e1f8f5287`, exact artifact `9028103772`, proves direct plane, multi-face seam, close sheets, and cylinder **3/3** and moves torus to deterministic downstream `completion/output-validation / LocalSheetMismatch` after complete `4/8/4` authority consumption. The production normalization and retain/release patch remain unchanged while test authority is repaired.

## Design-first statement

```text
Active design gate: G4 topology-distinct completion and singularities
Earliest failing fixture/contract: canonical transition-domain counterfactuals do not reach materialization
Missing design contract: tests must select one actually serialized topology and keep compact/full-EF meanings distinct
Smallest general implementation change: repair two test files only
Observable material-progress condition: all five tests encode their intended invariant and compile in the packaged producer target
Explicitly deferred work: runtime execution; torus LocalSheetMismatch; nonzero Z4 rotation; hard-rail scheduling; multi-isolation lineage
```

## Allowed files

Only:

- `tests/SurfaceCellTransitionQuotientTests.cpp`;
- `tests/SurfaceCellsPhase10Tests.cpp`.

Production headers/sources, CMake, `cmake/DirectionalTests.cmake`, fixtures, manifests, validators, benchmarks, completion/simplification, cross-field extraction, and unrelated tests are forbidden.

## Required test corrections

### 1. Valid serialized canonical-domain witness

Replace the current off-route `transition_index_domain_witness()` assumption with a witness that is proven to occur in a materializer-facing cell segment.

Required procedure:

1. Enumerate produced cell `boundaryPaths` and each segment's parallel `transitionSourceTopology` / `transitionSourceEdges` positions.
2. For each actual topology, resolve:
   - its source-wide compact index from `edge_matching_indices(edge_faces(full source faces))`;
   - its region-local compact index from the owning topology region's active faces;
   - its full `EF` row from the validated `CrossFieldEdgeTransition` selected by canonical endpoint topology and reciprocal incident faces.
3. Select only an actual route position whose three numeric values are nonnegative and pairwise distinct.
4. If the existing disconnected-overlapping square cannot naturally produce such a route, replace or extend the synthetic topology with the smallest deterministic disconnected/multi-region planar fixture whose produced cell boundary genuinely crosses that later-region interior edge. Do not inject a fabricated route into the phase-front result.
5. Assert the witness route position exists before testing values.

The positive test must verify every numeric/topology sequence has equal length, every numeric entry equals the source-wide compact mapping for its parallel topology, genuine one-face boundaries remain topology-only, and materialization succeeds.

The two negative tests must mutate the exact witnessed route position to the full-`EF` row and region-local compact value respectively. Each helper must prove the replacement occurred. Materialization must fail as `InvalidAuthoritativeTransitionSourceEdge` in both cases.

Do not replace semantic assertions with helper-return or existence-only checks.

### 2. Face-row-invariant periodic route/cut authority

Repair `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`.

- Never interpret `sourceRouteEdges` or `cutSourceEdges` as `mesh.EV` rows.
- Compare `sourceRouteTopology` and `cutSourceTopology` as the canonical route/cut identities across face-row reversal.
- Independently reconstruct the source-wide compact map for each mesh and require each numeric entry to equal the compact index of the topology at the same position.
- Preserve grid, rotation, translation, route length/order, and cut length/order invariance.
- Preserve exact reciprocal field-row reversal; do not sort away meaningful route order.

### 3. Malformed holonomy CrossField tamper

Repair `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`.

- Select the intended route through `sourceRouteTopology`, not its compact numeric index.
- Locate exactly one `CrossFieldEdgeTransition` whose canonical endpoint topology matches and whose two incident faces are reciprocal authority for that edge.
- Require the transition's `sourceEdge` to be the valid full `EF` row for that topology before tampering.
- Mutate its matching as before.
- Preserve exact expectations: producer `Rejected`, reason `PeriodicHolonomyMismatch`, and empty seeds/traces/proposals.

No production relaxation or alternate accepted failure is allowed.

## Static verification before build

Inspect the final diff and prove:

- only the two allowlisted test files changed;
- no assertion or typed-failure expectation was removed or weakened;
- no compact route index is used to index `mesh.EV` or compare directly with `CrossFieldEdgeTransition.sourceEdge`;
- every canonical numeric route lookup is paired positionally with topology;
- the selected three-domain witness is an actually serialized route position;
- no fixture name, observed output count, source numeric ID, ordering accident, or predicted hash becomes production authority;
- whitespace and syntax checks are clean.

## Compile-only boundary

Commit and push the exact test correction before compiling. Use Release/static/Ninja and GoogleTest `PRE_TEST`. Compile/package exactly:

1. `directional_core`;
2. `directional_pipeline`;
3. `directional_compiled_api_tests`;
4. `directional_surface_cell_producer_tests`;
5. `directional_surface_cell_completion_tests`;
6. `directional_surface_cell_validation_tests`;
7. `directional_benchmarks`.

Do not execute any generated Directional binary, GoogleTest discovery/list command, test, benchmark, `ctest`, CLI/GUI command, help/version command, or custom input. `runtimeExecution` must remain `false`.

Package five executables, two static libraries, all 27 committed fixtures, exact source closure, the two-file patch, compile database, logs, metadata, and recursive checksums. Record exact source blobs, implementation/build commits, toolchain/submodules, target list, and artifact digests. Remove any bounded workflow and trigger in safe order after artifact verification; retain only `.github/workflows/agent-source-snapshot.yml`.

## Following artifact-only acceptance

Write an immutable artifact-only Test + Benchmark plan for the next turn. It must run individually:

- `SourceWideCompactTransitionIndexIsIndependentOfRegionPartition`;
- `FullEfTransitionRowCannotReplaceSourceWideCompactIndex`;
- `RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex`;
- `PeriodicPhaseFrontCutAndHolonomyIgnoreFaceRowEnumeration`;
- `PeriodicPhaseFrontMalformedHolonomyFailsClosedWithTypedReason`;
- `ComponentBoundaryAndEulerFactsAreComputedFromIncidence`;
- `DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested`.

It must also preserve the artifact `9028103772` retained groups and bounded-suite authority, then repeat plane, multi-face seam, close sheets, cylinder, and torus in order with three fresh processes. Torus must again precede sphere. The direct seam semantic digest remains `99c8be7159d05c2f` for same-artifact determinism only.

## Explicitly deferred production work

Do not address in this Code + Build turn:

- torus `completion/output-validation / LocalSheetMismatch` and its 74 issues;
- nonzero periodic `Z4` rotation;
- target-size-dependent hard-rail breakpoint scheduling;
- the positive multi-isolation quotient-lineage witness;
- the historical completion/simplification ten;
- validator timing thresholds;
- sphere, bunny, vase, G5/G6, fallback/recovery, or optimization.

PR #8 remains open, draft, and unmerged. After all branch files and PR-body updates, the final repository write must be one new top-level PR #8 conversation comment.
