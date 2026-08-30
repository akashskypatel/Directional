# M3-CP4c-2 CB9 — Code + Build Report

## Verdict

`M3-CP4c-2-CB9` is **COMPLETE / BUILD GREEN / RUNTIME-FREE**.

Semantic/test source `57444781af7bdc460e38cc68930a9a8c8199eeea` implements the R9-REV AI0–AI9 corrective scope: it converts both stale Amendment-14 Cut-sub-arc consumers in A2b, publishes the requested fragment/orbit diagnostics, annotates the already-proved ordinal-359 semantic-digest rationale, and prevents two test helpers from falling through to `built.value()` after a typed failure. No selector byte, error enum, sphere correction, crossing producer, benchmark, or unrelated product behavior changed.

Stable accounting remains **44 events / 14 categories / 30 recurrences**, produced-witness debt **5**. This successful build creates authoritative M3 package **67**. `selected_r2_branch=NONE`, `selected_gate=NONE`, `gate_execution_authorized=false`; CP4c-2 remains runtime-unaccepted pending R10.

## Source and immutable package authority

- semantic/test source: `57444781af7bdc460e38cc68930a9a8c8199eeea`
- compile caller event/control SHA: `a4a34e77ea595be480d2499db812b6f985f12848`
- compile workflow run: `33325344311`
- changed-owner prepackage job: `99294371782`
- prepackage result artifact: `9736080970` / SHA-256 `901df0792f960365008e3d5d6993f61dcca7b708f5faa01cdae224717b52493f`
- prepackage log artifact: `9736081217` / SHA-256 `ec162d1df2496558fb04fb4f330212f48527463593133164bf184a50ac017f11`
- authoritative package job: `99294619815`
- result package artifact: `9736088354` / SHA-256 `78f542c775090968cde0d010cb9cd794d2c9deab15b42a7b29285f1d0490ebdf`
- compile-log artifact: `9736088507` / SHA-256 `8670377030da448b90e37500dda9811d081b13676d16034441ed305cc2906b00`
- packaged source archive SHA-256: `2ea3ffcd806e8f9ffc04efeb99cf05962017ce4ad03587f07d09b2aa4bc21c5e`
- internal package manifest: **28/28 PASS**
- exact arithmetic backend: **GMP**, with both `gmpxx` and `gmp` verified on the authoritative link command
- runtime evidence: `runtimeExecution=false`

The control SHA exists only to install/trigger the compile caller. The reusable compile workflow is explicitly bound to semantic source `57444781af7bdc460e38cc68930a9a8c8199eeea`; that semantic/test source is the package/runtime authority for R10.

## AI1 — independently re-derived consumer audit

The audit was produced from the frozen pre-edit source by searching every product reader of `arc.cutEdge`, `GlobalTopologyArcKind::Cut`, and `cutGraph.cut_edges()` before writing the corrective. The R9-REV §4 table was used only afterward as a cross-check.

| Site | Consumer intent | Verdict before CB9 | CB9 disposition |
|---|---|---|---|
| `EmbeddedGraphTopology.cpp:815-828` | order one Cut ray from its own endpoint parameters | arc-keyed and already sub-arc-correct | unchanged |
| `EmbeddedGraphTopology.cpp:939-1070` | vertex/edge-locus rotation for Mandatory/Cut rays | arc-keyed and already sub-arc-correct | unchanged |
| `GlobalTopologyPlan.cpp:420` | source-edge barrier set for region ownership | edge-keyed by intent | unchanged |
| `GlobalTopologyPlan.cpp:479-516` | bind Cut arc darts to incident source-face fragments | **arc-keyed and stale**: required exactly one derived Cut arc per source cut edge | **fixed by AI2** |
| `GlobalTopologyPlan.cpp:702/708` | source-edge barrier set while seeding face components | edge-keyed by intent | unchanged |
| `GlobalTopologyPlan.cpp:1152-1155` | source-edge barriers in disc-certificate fragment adjacency | edge-keyed by intent | unchanged |
| `GlobalTopologyPlan.cpp:1239-1242` | populate `boundaryVertices` skip-list authority | **arc-keyed and stale**: inserted both whole source-edge endpoints for every sub-arc | **fixed by AI3** |
| `GlobalTopologyPlan.cpp:1531-1532` | semantic digest of each arc | arc-keyed and already sub-arc-correct because arc id/endpoints/segment range are also consumed | unchanged |
| `GlobalTopologyPlan.cpp:1596` | build embedded graph from selected source cut edges | edge-keyed producer input by design | unchanged |
| `GlobalTopologyPlan.cpp:1774` | reconstruct exact cut-node bindings from selected source edges | edge-keyed by design | unchanged |
| `RemeshPipeline.cpp:6669` | resource metric `cut_edges().size()` | edge-keyed by intent | unchanged |

The independent search found additional syntactic Cut-kind/cut-edge uses inside rotation construction and canonical-candidate validation that the review table summarized rather than listing line-by-line. None assumed one arc per cut edge or whole-edge endpoints. No site required an Amendment-14 representation change, so AI7's definition stop did not trigger.

## Corrective implementation

### AI2 — region binding consumes every Cut sub-arc

`build_regions` still requires every selected cut source edge to have exactly two incident source faces, but it now rejects only a **zero** derived-Cut-arc binding. For every Cut sub-arc carrying that source edge, it runs the existing per-face dart/orbit body once.

The source comment records the required invariant explicitly: `build_arcs` emits all Cut sub-arcs in canonical `cutEdge.first() -> cutEdge.second()` order. Therefore the unchanged `face_orients_edge_forward(...)` plus `2*arc.id + side` formula selects the same interior side for every sub-arc.

When `DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS=1`, CB9 additionally publishes:

- `record=fragment_reconciliation` with `fragment_orbit_count`, `trace_piece_count`, and `expected_fragment_count=trace_piece_count+1` per populated source face;
- `record=cut_edge_orbit_evidence` with per-face/per-cut-edge orbit cardinality.

R10 must use this evidence on the Amendment-14 crossing witness rather than adopting R9-REV's reconciliation argument as proof.

### AI3 — boundary-vertex authority uses actual sub-arc endpoints

`build_region_certificates` now constructs the existing `NodeLocus` map once and threads that same authority into both pinch validation and region-certificate construction. A Cut boundary incidence contributes a source vertex to `boundaryVertices` only when the **actual arc endpoint node** has a vertex locus. A crossing node with only an edge locus contributes no source vertex.

This removes the silent whole-source-edge over-insertion without adding a second node-to-vertex lookup or weakening the interior-vertex ownership validator.

### AI4 / AI5

- `SurfaceCutGraph.cpp` now places the ordinal-359 falsifier next to the raw `face.orbit` semantic-digest rationale: the enumeration-invariance claim is recorded as **proved by ordinal 359**.
- `build_topology_plan` and `build_surface_cut_graph` retain typed error printing but return immediately after a failed build instead of unconditionally calling `built.value()`. No gated assertion meaning changed.

## Frozen authority and excluded scope

Selector authority was re-derived before edits and remains byte-identical:

- first 355: `e9d88f1196e412e06424294d6be22b32f01c9671ec5e4de119abd3f2fb5afeaa`
- first 357: `b896d0db7f26aeb0f3513418405efdeccbcf84fb6dc971500c6ddac9e364dc70`
- first 361: `61918d9fbd7bf757437886f0e86776b60665c58e4d7283b81d42caca03c0288b`
- whole 365: `6b5b6555d39c250c24cbf3faeafdeca93b4b11379118a29583253e6cfc14b8a1`
- cardinality / uniqueness: **365 / 365**

CB9 does **not** modify the prescribed-sphere `RotationSystemInconsistent`, any selector identity or byte, any error-enum/topology-error mapping, `EmbeddedGraphTopology.cpp` crossing emission, `proves_cellularity()`, the fragment-count invariant, or `UncutFaceComponentOrbitSeedNotUnique`. It executes no gate and no benchmark. `AH6` remains owed when ordinals 363-365 are all reached.

## Build evidence

The required changed-owner compile ran first against exact semantic source `57444781af7bdc460e38cc68930a9a8c8199eeea` and compiled `directional_surface_cell_producer_tests` in **105/105** Ninja actions without executing it.

The authoritative package job then compiled all eight standard targets through durable `agent-compile-reusable.yml`:

1. `directional_core`
2. `directional_pipeline`
3. `directional_surface_cell_authority_kernel_tests`
4. `directional_surface_cell_producer_tests`
5. `directional_surface_cell_completion_tests`
6. `directional_surface_cell_validation_tests`
7. `directional_compiled_api_tests`
8. `directional_benchmarks`

Package verification is **28/28 PASS**. All packaged source-status snapshots are empty. GMP/GMPXX evidence is present. No generated Directional executable, discovery command, test, benchmark, CLI, fuzzer, help/version command, or custom input ran.

## Successor

Exact next subturn is **`M3-CP4c-2-TB-X2-R10-EXEC`**, immutable artifact-only execution on package `9736088354`, under `Architecture_M3_CP4c2_TB_X2_R10_Artifact_Only_Test_Benchmark_Plan.md`. R10-EXEC owns runtime and raw evidence only; **R10-REV** owns diagnostics, regression/candidate disposition, and next-step planning. Do not rebuild, repair, mutate the package/source/tests/fixtures/selectors, or execute benchmarks.
