# Architecture M3 CP2 — Code + Build Report

Date: 2026-08-19 UTC  
Turn: `M3-CP2-CB`  
Turn type: **Code + Build**  
Status: **COMPILE/PACKAGE GREEN; CP2 NOT YET ACCEPTED**  
Exact successor: **`M3-CP2-TB` — immutable Test + Benchmark**

## 1. Frozen semantic authority

Exact CP2 semantic source is:

`6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff`

The final correction after the first compile diagnostics is exactly one source edit in
`src/geometry/SurfaceCellTracing.cpp`: the typed singularity-seed path calls
`surface_cell_tracing_detail::append_seed(...)` with the same namespace qualification as the
existing legacy helper path. No product/test/build semantic source changed after this SHA.

Relative to accepted CP1 source `9f7e222bab6c930a12d1369fa2aee869f5c0dcff`, the
product/test/build semantic delta is confined to the frozen eight-file CP2 surface:

1. `include/directional/authority/AuthorityIds.h`
2. `include/directional/geometry/SurfaceCellTracing.h`
3. `src/geometry/SurfaceCellTracing.cpp`
4. `include/directional/pipeline/RemeshPipeline.h`
5. `src/pipeline/RemeshPipeline.cpp`
6. `cmake/DirectionalTests.cmake`
7. `tests/FieldAlignedCurveNetworkTests.cpp`
8. `tests/SurfaceCellREPackageTests.cpp`

The implementation introduces checked `NetworkNodeId`, `NetworkEdgeId`,
`SingularityPortId`, and reserved `TraceId`; publishes the immutable checked
`FieldAlignedCurveNetwork`; binds typed singularity ports and mandatory boundary/hard-feature
edges to accepted source/atlas/rail authority; and cuts production tracing over to the typed
skeleton without repopulating raw singularity vectors. CP3a tracing-order, CP3b contact/event,
CP4 topology-selection, and M4 scheduling semantics remain outside this package.

## 2. Required external pre-package compile

The mandatory separate pre-package compile ran on literal semantic SHA
`6b046e0ba924a8d9f2aee158c64fd7734ab9a3ff` before package allocation was consumed.

- run/job: `32279124852 / 96153441513`
- result artifact: `9375262215`
- result outer SHA-256: `657b8ce20a98140e76e239437ce1b4c9df54241e1681b364d2df049bb29588cf`
- log artifact: `9375262622`
- log outer SHA-256: `49637b34d8c9cb99578117ee2bfc5e634341278fbf189a01315b5c080d705c3d`
- compiled closure: `directional_core`, `directional_pipeline`,
  `directional_surface_cell_producer_tests`
- build exit: `0`
- cacheable calls: `98/98`; hits `79`; misses `19`
- source status: clean before/after configure/build/package
- `runtimeExecution=false`

The pre-package run consumed no M3 package. The required post-preflight source/site-set audit
found no semantic change after the preflight and confirmed that the CP2 semantic delta remained
within the frozen eight-file surface.

## 3. Cumulative M3 package 9

Package 9 compiled and packaged the identical semantic SHA through the full approved reusable
owner closure.

- run/job: `32279806492 / 96155630834`
- package/result artifact: `9375452692`
- package outer SHA-256: `6f8865a3d3c28ea803a40cc9929f22de5a1d313f4810541f6474bbfba9b8ef79`
- Code + Build log artifact: `9375453342`
- log outer SHA-256: `d764d49de46c109061b3ad9f5e31aeb98293c7fee358ab2690e063a87a676f12`
- packaged source archive SHA-256: `5b1f047a986e9d58058b09efdf362112674ba63fe255230f5d2f4db2c0872870`
- source archive: `549` members, `0` symlinks
- package ZIP: `28` files
- self-excluding manifest: `27` entries, `0` self references
- source-status snapshots: five, all empty
- build exit: `0`; first-target preflight exit: `0`
- cacheable calls: `114/114`; hits `100`; misses `14`
- `runtimeExecution=false`

Compiled/packaged executable owners are `directional_surface_cell_authority_kernel_tests`,
`directional_surface_cell_producer_tests`, `directional_surface_cell_completion_tests`,
`directional_surface_cell_validation_tests`, `directional_compiled_api_tests`, and
`directional_benchmarks`, plus `libdirectional_core.a` and `libdirectional_pipeline.a`.
Compilation did not execute any generated Directional binary, test, benchmark, discovery,
`ctest`, CLI/GUI, fuzzer, help/version command, or custom mesh input.

Package 9 therefore consumes cumulative M3 allocation **9/12**. Compile/package green is
mechanics and packaging evidence only; CP2 remains semantically unaccepted until immutable
`M3-CP2-TB` passes the frozen gate.

## 4. Frozen immutable successor

`M3-CP2-TB` must consume artifact `9375452692` without rebuild, relink, repair, source/test/
fixture mutation, or generated discovery. Its required selector is accepted CP1 **281/281**
plus exactly the six frozen CP2 identities, for **287/287** total. A red immutable gate stops
for Review; no package 10 / CP3a Code + Build is authorized until CP2 is accepted.

Latest accepted runtime authority remains M3 CP1
`9f7e222bab6c930a12d1369fa2aee869f5c0dcff / 9366752046` at **281/281** until that
immutable CP2 gate passes.

## 5. Regression and control-plane disposition

No generated runtime executed in this Code + Build turn, so no runtime regression or candidate
was observed. Historical stable accounting remains **38 events / 14 categories / 24
recurrences** and produced-witness debt remains **5**.

The accidental `tmp-lowlevel-test` branch was audited: tip
`dd4141a5add457b6017e776acabe327674e56606` is an ancestor of the working-branch history,
was one commit behind at audit time, and has zero differing files. It contains no unique work.
The available connector exposes no branch-delete operation, so it remains disposable remote
control-plane residue rather than semantic authority.

All temporary CP2 correction/pre-package/package workflows, triggers, and observation files
were removed before closeout. `.github/workflows` is restored to exactly the three durable
workflows required by policy.
