# M3-CP4c-2 CB7 — Code + Build Report

## Verdict

`M3-CP4c-2-CB7` is **COMPLETE / BUILD GREEN / RUNTIME-FREE**.

The semantic implementation is commit `4f0f3ca74a88ba260a20c019437bc4995f2056e0`. CB7 implements the deferred
AF0/AF2/AF3/AF4 work plus DEFN-R2 Amendment 14 under AG1–AG7, freezes selector **365**, compiles every standard
package target with GMP/GMPXX, and executes no Directional test, benchmark, gate, or other runtime.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**. The successful compile creates
authoritative M3 package **65**. `selected_r2_branch=NONE`, `selected_gate=NONE`,
`gate_execution_authorized=false`; CP4c-2 remains runtime-unaccepted.

## Source and immutable package authority

- semantic product/test source: `4f0f3ca74a88ba260a20c019437bc4995f2056e0`
- build-transport source: `1230621baff6d04fb20df3b1bf48903cd65b5d69`
- compile run/job: `33287281975 / 99192562149`
- result package artifact: `9724864897`
- result artifact SHA-256: `a4d9803eea326b5a22f6c4e21cc07e0908eaede944d02a726ae3c5f6d856734c`
- compile log artifact: `9724865018`
- log artifact SHA-256: `462090e66648fc6db583b770a2518aca0a3f63ee2ae167d900070fb4ed5460bd`
- packaged source archive SHA-256:
  `3b4decd367a3fdb932754c3c6e420b536fa7607755e8ff2541f137f1589d5544`
- exact Eigen gitlink: `769c72fd8019e389810d1de1e7c243521a43b594`

`4f0f3ca… -> 1230621b…` changes no `src/`, `include/`, `tests/`, fixture, selector, or other semantic byte. The
only build-transport difference is temporary control state plus `.gitmodules` changing Eigen's remote URL from
GitLab to the verified `eigen-mirror/eigen` GitHub mirror at the **same gitlink commit**. The canonical GitLab URL
was restored after packaging. This transport-only substitution was required because three checkout attempts on
run `33286695268` failed before compilation when GitLab returned a load error. Those attempts executed no
Directional runtime and produced no package. A malformed first mirror-control attempt (`33287210344`) instantiated
no build jobs; the durable reusable compile workflow was restored byte-for-byte before the successful build.

## Build evidence

The successful run used Release, static libraries, PRE_TEST discovery, out-of-tree build, and the durable compiler
cache namespace. `metadata/command-boundary.txt` records:

`runtimeExecution=false`, `turnBoundary=Code+Build-only`, `exactArithmeticBackend=GMP`,
`preflightCompile=true`, `semanticContracts=compiled-not-executed`.

Preflight and full build exit codes are both `0`; all source-status snapshots are empty. GMP evidence binds
`/usr/lib/x86_64-linux-gnu/libgmpxx.so` and `/usr/lib/x86_64-linux-gnu/libgmp.so` into the compiled test target.

All eight standard targets compiled and linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

The package contains 28 SHA-256-manifested files. No packaged executable was run.

## Implementation disposition

**AF0 — complete.** `SurfaceCutGraphError` carries optional `originatingTopologyError`; `topology_error(...)`
preserves the upstream `GlobalTopologyPlanErrorCode`, and pipeline/diagnostic publication prints it without
changing the existing surface-cut error mapping or enum semantics.

**AF2 — complete.** The old D2 localization harness no longer treats withdrawn source-edge-barrier line-number
sites as production authority. It is explicitly a `withdrawnBarrierProxy` diagnostic and compares against the
actual embedded-graph oracle instead of asserting stale `419/437/474` labels.

**AF3 / AF4 — complete at code/build scope.** Torus diagnostics now construct field authority from committed
`milestone-g/torus.rawfield` through `finalize_surface_cell_raw_cross_field`; enumeration invariance permutes mesh
rows and corresponding raw-field rows together. This removes the synthetic zero-transport substitute while
retaining the semantic-digest enumeration falsifier.

**AG1 — complete as one conversion.** The same change set adds exact edge-interior cut-crossing bindings, orders
crossings by exact canonical source-edge parameter, subdivides selected cut edges and trace arcs at the published
segment positions, admits trace-crossed edges to cut proposal, and extends edge-locus rotation.

**AG2 — complete.** `mandatory_ray_points_to_second_endpoint` was generalized to the single
`edge_ray_points_to_second_endpoint` owner; the existing four-sector ordering now handles both `Mandatory` and
`Cut` edge rays. No second ordering routine was introduced.

**AG3 — compiled publication surface complete.** The independent oracle publishes per-component topology,
`traceEndpointsAttached`, `noDegreeZeroNodes`, and exact cut-crossing counts/arcs. Runtime adjudication of the
sphere's component records is intentionally deferred to TB.

**AG4 — complete.** `CutSearchExhaustedBeforeCellularity` replaces the retired no-admissible-cut outcome.
Saturation is an explicit last resort and publishes `saturationUsed`, `saturationLocus`, and
`saturationPromotedEdgeCount`; cellularity is still proved afterward by the actual embedded-graph certificate.

**AG5 — compiled witness complete.** `build_cp4c_trace_crossed_cut_fixture()` constructs a bounded three-ring
witness and asserts at runtime that traces actually cross source edges and that a selected cut is classified
`TraceInteriorCrossing`. The identities then require two Cut plus two Trace rays at the synthetic crossing node.

**AG6 — complete.** The independent oracle reconstructs cut crossings from network segment entry points without
calling `SurfaceCutGraph`, rejects duplicate exact crossing loci, and publishes per-cut crossing-node and cut-arc
counts for term-by-term comparison.

**AG7 — complete.** The four required identities were appended in frozen order, producing selector **365**:

- ordinal 362 `GlobalTopologyPlan.RotationSystemAndFaceWalkAgreeOnTorusProducedWitness`
- ordinal 363 `SurfaceCutGraph.TraceCrossedSourceEdgeIsAdmissibleAndSubdividesBothArcs`
- ordinal 364 `SurfaceCutGraph.CutCrossingNodeRotationIsDerivedAtDegreeFour`
- ordinal 365 `SurfaceCutGraph.CutSetSaturationProvesCellularityWhenSearchIsExhausted`

Recomputed from the committed selector bytes:

- first 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- first 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
- first 361: `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`
- whole 365: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`

No prior selector byte changed.

## Successor

Exact next turn is **`M3-CP4c-2-TB-X2-R8-EXEC`**, artifact-only Test + Benchmark on immutable package
`9724864897`. CB7 does not select or execute selector 365. The next turn must perform immutable package/source/GMP
preflight, recompute selector 365 and all frozen prefixes, then follow the comprehensive R8 execution plan in
`Future_Chat_Session_Handoff.md`. CP4c-3 remains blocked.
