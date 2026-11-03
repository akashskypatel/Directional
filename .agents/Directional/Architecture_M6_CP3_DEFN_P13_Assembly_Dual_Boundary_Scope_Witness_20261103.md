# P13-j — dual-scope boundary keys: two exact source-edge splits and one vertex-seam ambiguity (2026-11-03)

**Current Review/Definition turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX`; **INCOMPLETE**. This record adds a measured scratch-only witness, not production acceptance, an exact corrective patch, or an authorized successor.

## Immutable evidence

- CB78 base source `afd72107d3213a396ed7f35b53f67dceeea7e7ca`; prior [three-fan](Architecture_M6_CP3_DEFN_P13_Assembly_Stitched_Vertex_Three_Fan_Witness_20261103.md) and [prepared-ring](Architecture_M6_CP3_DEFN_P13_Assembly_Node5355_Prepared_Ring_Comparison_20261103.md) reports remain authoritative.
- Existing isolated scratch diagnostic ref `agent/p13j-diagnostic-first-vertex-20261103`; corrected diagnostic source **`6db6b8a5535db97da923982c6c6694ba3932c56b`** adds environment-gated `P13L` logging of complete compacted boundary-identity values, typed regions/chart source faces, prepared outgoing halfedges and node occurrences, and retains earlier `P13K/P13J` logs. `PureQuadCompletion.cpp` was verified byte-identical to the preceding scratch build; the diff in `PatchDescriptor.cpp` is 74 added log-only lines. No product/source edit on working branch; no validator relaxation.
- The first scratch compile **FAILED**, run `41574151313`, source `0c9c4d6d…`: diagnostic-only invalid member access `PureQuadMesh::boundaryCharts` / `boundaryTopologyRegions`; warnings about printf type mismatches. Corrected on scratch ref; do not call the first build successful. The retry used the existing mandatory GMP/GMPXX reusable workflow, [run 41574389289](https://github.com/akashskypatel/Directional/actions/runs/41574389289) **SUCCESS**, source `6db6b8a…`, package artifact `13202304778`, ZIP SHA-256 `99ee95193bf450573b8af115c550cc20bc4c991c0eab08e79ed56d1100449f93`; internal SHA256SUMS/source commit/GMP metadata independently verified; `runtimeExecution=false` for CI build.
- Prebuilt CI binary locally replayed (not locally compiled) with exact unchanged `benchmarks/fixtures/milestone-g/vase.off` via `milestone_g_manifest.json` case `vase__surface_cells`. Runtime **294.337s**, reporting process exit code 0 but benchmark `success=false`, original `NonManifoldStitchedVertex`. Each `P13J/K/L_BEGIN` and `END` appears exactly once. Binary SHA-256 unchanged before/after: `f49b7968673a8bbf025010ccb42242c417bde9a553a07edee57b75c53cd5448a`.
- `SurfaceCellCanonicalIdentity::hash()` mixes exact numeric values but only typed-array **sizes**, not typed elements; definitive key equality uses full values + typed fields. The comparison below checks full compacted values and sourceChart content, not hash alone.

## Measured per-neighbor identity and source scope

Four incident source cells are `26569,3,26570,0` around arrangement node `5355`. The prepared graph has four reciprocal twin edge pairs forming one ring; see prior record. The new per-corner output:

| Source arrangement node | Patch/cell first → second | Compacted identities | Outgoing source scopes | Equality |
|---|---|---|---|---|
| 5351 | 26569 → 3 | `(1,61357)` → `(1,61357)` | face155 → face155, chart0 | equal |
| 5356 | 26570 → 0 | `(1,50500)` → `(1,50501)` | face155 `(0,255,1248)` → face547 `(0,1208,1248)`, chart0 | **different** |
| 5357 | 26569 → 26570 | `(1,89848)` → `(1,89849)` | face155 `(0,255,1248)` → face1381 `(0,857,1208)`, chart0 | **different** |
| 5359 | 3 → 0 | `(1,50195)` → `(1,5144)` | face248 `(255,893,1248)` → face155 `(0,255,1248)`, chart0 | **different** |
| 5355 | all four | `(1,56731)` on all four | face155, chart0 | equal |

All reported scopes have topology region 0, chart ID 0. The exact typed chart-face triples change for three distinct neighbor keys. In the original source, `PatchDescriptor.cpp::arrangement_node_identity` filters node occurrences by `source_scope(edge)` of each **outgoing oriented boundary halfedge**, and `compact_patch_ownership_identities` assigns distinct compact rank to exactly different full records. Completed `PureQuadMesh.boundaryNodeIdentities` are then consumed verbatim by `PureQuadCompletion.cpp::resolved_stitch_identity`.

## Independent source mesh cross-check — different semantic classes

Parsed the immutable **OFF source triangles and coordinates**, not a reconstructed assembled mesh:

- **5356:** face155 barycentric `(0,.3420184032665,.6579815967335)` and face547 barycentric `(.6579815967335,.3420184032665,0)` refer to the **same exact source edge (0,1248)**. Positions agree to `2.22e-16`. Different descriptor keys arise from changing outgoing face scope despite shared source-edge support.
- **5359:** face155 barycentric `(.3382665797966,0,.6617334202034)` and face248 barycentric `(.6617334202034,0,.3382665797966)` refer to the **same exact source edge (255,1248)**. Source coordinates agree exactly. Different descriptor keys arise from changing outgoing face scope despite shared source-edge support.
- **5357:** face155 barycentric `(0,1,0)` corresponds to source vertex **0** in the unmodified OFF face's stored corner order `(255,0,1248)`; face1381 barycentric `(0,1,0)` also corresponds to source vertex **0** in stored corner order `(1208,0,857)`. **Both refer to source vertex 0**, and coordinates agree exactly. The source-chart face support nevertheless differs. (CAUTION: the diagnostic canonical source-chart keys print sorted vertex triples; their order is not the raw OFF triangle corner order. One must not infer source vertex 255 versus 857 merely from sorted chart-face order.) This is another candidate scope-fragmentation witness rather than proof of distinct source vertex topology.

**Adjudication precision:** the three different output keys on the same authoritative source node are caused by selecting different outgoing source-face scopes at the patch boundary; the prepared graph has reciprocal twins and all source points above share exact source-edge/vertex support in the respective raw OFF faces. The immediate producing source is the **descriptor/completion boundary identity construction**, not the assembly's fail-closed vertex-link validator. However, a safe corrective rule must preserve topology-region, isolation-sheet, chart-transition, barrier and hard-rail separation globally, so no broad node-ID/position merge is authorized. The exact corrected identity construction and negative falsifier have **not** been frozen; this Review remains open.

## Next focused Review action

Derive a **source-topology canonical endpoint key** for the same supported source edge/vertex across adjacent chart faces, using authoritative `SourceChartTransitionGraph` / typed source support and safeguarding chart/sheet/region and hard-feature disconnections. Establish from source code whether a precise descriptor-level normalization can be proven to unify only the three failing same-source endpoints without conflating non-equivalent sectors. Specify an adversarial negative fixture (coincident but different source-support/sheet) that would fail without correct scope guarding. Only then freeze a minimal corrective patch and one separately authorized Code+Build successor. Preserve original `NonManifoldStitchedVertex` validator. No CP3/selector promotion; accepted CP2 491/491, stable 66/17/49, debt1, unpromoted TB72A 883/883 unchanged.

**Remaining closeout:** authenticated Git-ancestry `review_check.py boundary`, full REVIEW_TURN_POLICY duties, ORIENTATION/CHANGELOG/tracker/TODO/handoff reconciliation and consolidation. Scratch diagnostic ref retained; no new test source or production code was changed.
