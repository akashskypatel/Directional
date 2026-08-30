# M3-CP4c-2 CB8 — Code + Build Report

## Verdict

`M3-CP4c-2-CB8` is **COMPLETE / BUILD GREEN / RUNTIME-FREE**.

The semantic/test correction is commit `05f9ef299ee54f8c9d50318fc9a37e5a5503740d`. CB8 changes no product
implementation source. It corrects exactly the two R8-REV witness identities at ordinals 359 and 361, adds the
required closed-witness non-vacuity guard, replaces the fabricated default-error sentinel with typed stage
outcomes, records the unresolved empty-network product question without widening scope, and compiles all eight
standard package targets with GMP/GMPXX. No Directional test, benchmark, gate, or other generated executable ran.

Stable accounting remains **44 / 14 / 30**, produced-witness debt **5**. This successful build creates authoritative
M3 package **66**. `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`; CP4c-2
remains runtime-unaccepted.

## Source and immutable package authority

- semantic/test source: `05f9ef299ee54f8c9d50318fc9a37e5a5503740d`
- successful build-transport source: `997d215e9ce0502f4a10afc62d08b2cd1fb3b037`
- compile run/job: `33292137782 / 99205507393`
- result package artifact: `9726295440`
- result artifact SHA-256: `1017a2f40829c171a0ec066b16e1f9f5436588f5e2376742e340ce1617d2556f`
- compile-log artifact: `9726295559`
- compile-log SHA-256: `ee5aedc4edbce10d4f7e48fcfaa76fe10b1ab6dec2cd7ba3afe2f3bed4172694`
- packaged source archive SHA-256: `ec9b9b7929521e3f2cd1df4e21beb2f01012f97ff1907ffbf5ae2b35334fd20c`
- exact Eigen gitlink: `769c72fd8019e389810d1de1e7c243521a43b594`

The successful transport source differs from the semantic source only by the temporary Eigen remote substitution
needed to avoid a GitLab service-load failure, plus control-plane state. The Eigen gitlink remains exact. The
canonical GitLab URL was restored after packaging. A source-surface comparison of the packaged semantic tree against
the intended CB8 workspace found all 342 tracked production/test/build-facing files byte-identical; `.gitmodules`
was the expected transport-only difference.

## AH1 retained-evidence result

No new runtime was used for AH1. Retained R8 result artifact `9725240893`, ordinal 359 process
`R8-CHECKPOINT-41e8933d9b0e719a`, contains **no `ADD_FAILURE` lines** and terminates only at
`FieldAlignedCurveNetworkTests.cpp:2381`, `ASSERT_TRUE(baselineCutGraph)`.

Therefore the source-authority, atlas, and network early-failure branches were not taken; the former empty-network
witness reached `SurfaceCutGraph::make(...)`, which returned failure. R8 did not print the real cut-graph error code
or `originatingTopologyError`, so CB8 does not infer or fabricate either. This is retained as active non-gating
product question `M3-CP4c2-TB-X2-R8-CAND-02` under AH7.

## Test-identity correction

CB8 implements AH2/AH4/AH5 without product changes:

1. ordinals 359 and 361 obtain one production feature authority from the production pipeline products;
2. `authoritativeRails`, hard-feature edges derived from those rails, component labels, and sheet labels are threaded
   together into the local `SourceTopologyRegions` / atlas / network reconstruction;
3. face-row permutations also permute the per-face component and sheet labels, while vertex-keyed rails/hard-feature
   edges remain invariant;
4. a closed witness now fails visibly if `rails_from_atlas(...)` is vacuous where the fixture requires feature rails;
5. the helper returns a typed stage outcome instead of a default-constructed `SurfaceCutGraphError` sentinel.

AH3 is preserved: the test does **not** re-run the whole pipeline per ordering. AH8 is preserved: no sphere fix, new
gate identity, selector byte, topology-error mapping, benchmark, or product implementation change was absorbed.

## Build evidence

The successful run used the durable `agent-compile-reusable.yml`, Release static PRE_TEST configuration, out-of-tree
build, the durable compiler-cache namespace, and exact GMP backend requirements. Preflight and full-build exit codes
are `0`; all source-status snapshots are clean; package internal manifest verification is **28/28 PASS**.

All eight standard targets compiled and linked:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

GMP/GMPXX linkage was verified. Compile evidence records `runtimeExecution=false` and
`turnBoundary=Code+Build-only`. No packaged executable was run.

## Orchestration-only failures

Two preceding control/build attempts are explicitly non-semantic:

- run `33291741324` was a workflow startup failure because the caller granted `contents: read` while the nested
  observer permission union requires `contents: write`; it created zero workload jobs and ran no Directional code;
- run `33291972464` stopped in exact-source submodule checkout when GitLab returned a service-load error while
  fetching Eigen. Configure/compile/package steps did not run and no Directional executable ran.

The caller permission correction and mirror-transport correction were schema-validated before the successful run.
These failures consume no semantic acceptance and create no regression count.

## Frozen gate authority

Selector **365** is unchanged:

- first 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- first 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
- first 361: `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`
- whole 365: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- cardinality / uniqueness: **365 / 365**

CB8 neither selects nor executes the gate.

## Successor

Exact next turn is **`M3-CP4c-2-TB-X2-R9-EXEC`**, artifact-only Test + Benchmark on immutable package
`9726295440`, following `Architecture_M3_CP4c2_TB_X2_R9_Artifact_Only_Test_Benchmark_Plan.md` exactly. It must
re-run selector 365 from ordinal 1, preserve the first-semantic-red hard stop, execute no benchmark, and satisfy AH6
if ordinals 363-365 are reached. CP4c-3 remains blocked.
