# RA-200 — P13-j stitched-vertex probe adjudication (2026-11-03)

**Turn:** `M6-CP3-DEFN-P13-ASSEMBLY-STITCHED-VERTEX` (Review/Definition) — **COMPLETE**. Resumed from the ChatGPT Review's `REVIEW_BLOCKER`. That blocker was procedural: the turn needed the completed lineage charts, typed authority and provenance at Vase nodes 5351/5356/5357/5359 and centre 5355, and that Review could not run C++. This adjudication ran that capture, and the follow-up probes, on the macOS scratch build (Claude, diagnostic only). It changes no product source in the repository.

**Base:** HEAD `d2e3c1f7a`, whose product source equals CB78 `afd72107d3213a396ed7f35b53f67dceeea7e7ca` (`git diff --quiet` over `src include tests benchmarks CMakeLists.txt cmake`). The scratch build reproduces the CI witness exactly: the first rejected stitched row is 3, with 6 incident quads, 2 of them reached; it is node 5355, contributed by patches 0/10942/22042/24674 (source cells 26569/3/26570/0).

**Supersedes as open work:** the 13 P13-j Review records of 2026-11-02/03 (preflight, breakpoint, three-fan, prepared ring, dual scope, typed source transition, V2 scratch verification, V2 sampling, ring non-vacuity, row-ranked counterexample, stitch-key dataflow, owner/cache preflight, completed-lineage gate). Their measured facts stand. Their open conditions are closed or ruled out of scope by RA-200.3. V2 and the reciprocal-DSU candidates are withdrawn; CB79 replaces them.

## RA-200.1 Findings

1. **The measurement the block asked for.** On HEAD, the stitcher's own lineage certificates at the five nodes, one line per shared-boundary corner:

   | Node | Corners (patch) | Support | Region / sheet | Literal source charts | Stitch keys |
   |---|---|---|---|---|---|
   | 5351 | 0, 1, 10941, 10942 | face (0,255,1248) | 0 / 0 | {0:(0,255,1248)} | 1 (control) |
   | 5355 | 0, 10942, 22042, 24674 | face (0,255,1248) | 0 / 0 | {0:(0,255,1248)} | 1 |
   | 5356 | 22042, 24674 | edge (0,1248) | 0 / 0 | {0:(0,255,1248), 0:(0,1208,1248)} on **both** | **2** |
   | 5357 | 0, 22042 | vertex 0 | 0 / 0 | {0:(0,255,1248), 0:(0,857,1208), 0:(0,1208,1248)} on **both** | **2** |
   | 5359 | 10942, 24674 | edge (255,1248) | 0 / 0 | {0:(0,255,1248), 0:(255,893,1248)} on **both** | **2** |

   Every certificate passes `owner_validated_typed_authority_certificate`, and the two sides of each split node carry identical certificates. This is branch (A) of the completed-lineage gate: the typed authority is compatible, and only the descriptor key differs.

2. **The key is not a property of the node.** `derive_patch_descriptor` publishes `arrangement_node_identity(node, F, source_scope(edge))`, where `edge` is the halfedge leaving the node in *this* cell. That function keeps only the node's occurrences in that one source scope. A node on a source edge or vertex is left through different source faces by different cells, so the cells around one prepared node publish different keys. The halfedge-scoped form is correct for `halfedge_identity`, because an oriented edge lies in one chart. It is wrong for a corner that several charts share.

3. **The fault is systemic; node 5355 is only where a validator first notices it.** On HEAD, Vase assembly sees 66,783 arrangement nodes and 186,780 boundary corners; **23,221 nodes (46,458 corners) resolve to two stitch keys**. The assembled mesh is shredded: 91,268 vertices, 67,829 quads, 85,762 boundary edges, Euler −19,442. Most split nodes leave two path-shaped fans, which pass the vertex-link check. Row 3 fails only because three cracks meet at one vertex.

4. **An existing gate row was passing on a cracked assembly.** Row 97, `PatchDescriptorMilestoneE.SharedEdgeParityRepairConforminglyCompletesTwoOddCells`, completes two triangles that share a source diagonal. On HEAD its assembly is two disjoint quads: 8 vertices, 8 boundary edges, Euler 2, with nodes 0 and 2 split. The test asserts only `quads not empty`. With the node key the assembly is the source disk: 6 vertices, 6 boundary edges, Euler 1. Downstream, the production `SourceAuthoritativeMeshValidator` compares components, Euler and boundary loops, so a census would not silently accept the cracks. The completion-level tests, however, never checked.

5. **Cylinder never reaches the patch stitcher.** It finishes through the authoritative phase-front mesh (`RemeshPipeline.cpp` ~14005), so Vase is the only census fixture that exercises `stitch_pure_quad_patches`.

6. **With a node key, assembly passes.** Key = the node's occurrences in **all** of its source scopes. Vase then has 0 split nodes, and each of the five nodes has one key with unchanged certificates. Assembly succeeds with 68,038 vertices, 67,829 quads, 135,866 edges, 416 boundary edges and Euler 1. The source has Euler 1 and one boundary loop (V 1274, F 2404, E 3677, 142 boundary edges). There is no `IncompatibleTypedStitchAuthority`, position or manifold rejection anywhere in Vase.

7. **The next failure is P13-k, a source-query cost after assembly, not a verdict.** The run reaches assembly at about 205 s on macOS and does not finish within 875 s. Four stack samples:
   - 3:42–6:30: **100 %** in `fill_surface_optimization_rail_constraints` → `provenance_supports_interval_sheet` → `source_face_scope` → `SourceTopologyRegions::matches_source_faces`. Every (output vertex × rail interval) pair revalidates the immutable source authority against all 2,404 source faces, twice.
   - After that: `evaluate_surface_optimization_energy_cached` → `project_vertices` → `nearest_source_point` → `SurfaceProjectionBvh::SurfaceProjectionBvh`. `nearest_source_point` (and `project_vertices` and the quad-label projection) construct a local `SourceProjectionCache`, and so a full source BVH, on **every call**, even when the caller passes a cache.

   O20 already named the same class of cost: per-query rebuilds of immutable source structures. The V2 timeouts in the earlier Review records were this stage, not V2 overhead. Their samples show the same two functions. Probe K (RA-200.2a) removes both costs. The run then reaches a third site of the same kind: final validation builds a chart graph per output quad.

## RA-200.2 Probes (macOS, scratch, diagnostic only)

| Probe | Switch | Result |
|---|---|---|
| J-count (HEAD) | `PROBE_J_COUNT` | 23,221 / 66,783 nodes split; HEAD mesh Euler −19,442; first rejection row 3 = node 5355 (matches CI) |
| J-nodes (HEAD) | `PROBE_J_NODES=5351,5355,5356,5357,5359` | Table in RA-200.1 item 1: identical certificates on both sides; keys split at 5356/5357/5359 |
| J-key | `PROBE_J_KEY` (node key over all scopes) | 0 split nodes; assembly passes (Euler 1, 416 boundary edges); Vase continues into P13-k |
| Two-cell row 97 | `PROBE_J_COUNT`, `PROBE_J_FAIL` | HEAD: two disjoint quads (Euler 2); node key: one disk (Euler 1) |
| Cylinder | `PROBE_J_COUNT` | Never calls the stitcher; PASS on HEAD and with the node key |
| Stack samples | `sample` ×4 after assembly | Rail fill: per-query `matches_source_faces`; then per-call projection BVH |
| K | `PROBE_K` (validate authority once; build the local projection cache only when none is passed), on CB79 | See RA-200.2a |

### RA-200.2a Vase past P13-k (probe K)

This was run on CB79 with `PROBE_K`. The probe validates the source authority once instead of in each `source_face_scope` call. It also builds the local `SourceProjectionCache` only when the caller passes none.

| Phase (macOS, one process) | HEAD source path | With `PROBE_K` |
|---|---|---|
| Assembly reached | ~205 s | ~205 s |
| `fill_surface_optimization_rail_constraints` (68,038 vertices × 142 rail intervals) | ~3 min, 100 % of samples in `matches_source_faces` | **0.1 s** |
| Optimizer energy / projection | BVH built per `nearest_source_point` call | passes in under 2 min |
| `validate_final_surface_mesh` | not reached by 875 s | ≥ 3.5 min and still running at the last sample (8:30 elapsed). Samples: `consistent_source_scope` → `SourcePointLabelSupport` → `SourceChartTransitionGraph::build`, **one graph per output quad** (67,829) |

The third site, `consistent_source_scope` (and the quad-label projection in `SurfaceMeshOptimizer.cpp`, which builds the same label support), is the Amendment 27 per-call graph build that RA-195 removed from completion. So P13-k is one cost class at three sites, all in the surface-optimizer and final-validation stage:

1. `source_face_scope` (`SurfaceMeshOptimizer.h` and `SurfaceOptimizationRailConstraints.cpp`) runs `matches_source_faces`, which is O(F), on every call.
2. `nearest_source_point`, `project_vertices` and the quad-label projection construct a `SourceProjectionCache`, and so a full source BVH, even when a cache is lent.
3. `consistent_source_scope` and the quad-label projection construct a `SourcePointLabelSupport`, and so a `SourceChartTransitionGraph`, per quad.

Vase's verdict after all three is not yet measured. The P13-k DEFN measures it with all three removed, then freezes exact patches (one CB per site, each with a cost GUARD in the RA-195 style).

### CB79 verification (scratch build, clean CB79 state)

- **Gate:** 886 rows (RA-200.5 manifest), **885/886**. The only red is row 283, the O16 macOS row, which was also red on CB78. No other verdict changed.
- **Ledger v5:** 0/81 pass, as on CB78. One deferred row changed: row 365 is the Vase census case itself, and it went from RED at 174 s to TIMEOUT at 600 s because it now passes assembly into P13-k.
- **Census:**
  - Cylinder PASS (10.4 s).
  - BunnyRandom unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`, P13-e).
  - Vase passes assembly and is then inside P13-k at 600 s.
- **Mutants:**
  - M1 (the call site keeps the halfedge-scoped key) fails rows 884 and 885.
  - M3 (a region-blind key) fails row 886.
  - Rows 91 (face-row permutation) and 97 stay green under both mutants and under clean CB79.

## RA-200.3 Rulings

1. **Owner: the completion-boundary identity producer** (`derive_patch_descriptor`). It is not the assembler and not the arrangement. The prepared arrangement is correct: node 5355 is a four-cell reciprocal ring. The assembler correctly fails closed.
2. **DESIGN Amendment 32:** a completed patch's boundary-node stitch key is the identity of the prepared arrangement node itself, meaning its occurrences in every source scope. It is not the view through the halfedge leaving the node in one cell. The reciprocal twins of the prepared complex are the certified relation (§8 rule 1). The assembler's typed-authority intersection, position and manifold checks remain the verification, unchanged. Halfedge and domain identities keep their chart-scoped endpoints.
3. **The open conditions from the earlier Review records:**
   - **Row/corner invariance:** the key reuses `source_point_identity` (typed vertex IDs, weights sorted by vertex, canonical chart faces). Row 91 (face-row permutation of `boundaryNodeIdentities`) stays green.
   - **Distinct nodes:** nodes are interned by `ScopedNodeKey` (position, region, vertex fan or sheet), and the key carries every occurrence's region and chart. Two distinct nodes collide only if their full occurrence sets are equal, which also collides HEAD's key for every shared scope; so CB79 is no weaker than HEAD here. Row 886 guards region separation, and it kills the region-blind mutant.
   - **Hard rail, sheet and fan sectors:** measured, not assumed. Across all of Vase, no corner pair that the node key joins fails the typed intersection.
   - **Repair-split nodes:** covered by the Vase run (repair passes) and by row 97 (the parity split on the shared diagonal).
   - **Completion cache with a changed owner:** conditional and unwitnessed. The initial pass has no cache. A node-intrinsic key removes the scope dependency that made rank aliasing plausible. No guard is added (CLAUDE.md §2); it reopens only on a witness.
   - **V2's 1e-8 rebind tolerance, row-ranked primary selection, quantized-anchor concerns:** they do not arise, because CB79 uses no tolerance, no rebind and no primary selection.
4. **Next Vase failure: P13-k** (RA-200.1 item 7, RA-200.2a), a cost in the surface-optimizer stage. Owner: the stage rebuilds immutable source structures per query, at three sites:
   - per-call revalidation of the source authority;
   - per-call construction of the projection BVH;
   - a per-quad label support and chart graph in final validation.

   This is the class O20 and Amendment 27 already recorded; P13-k is its first witness that blocks a fixture. → Review DEFN `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (Claude, scratch), which can start now.
5. **O26 (new, test oracle):** completion-level tests that assemble meshes assert counts or success, not the assembled topology. Row 97 passed on a two-component assembly. CB79's row 885 is the first assembly-topology assertion. Further strengthening goes with the CP3 test-quality slice; it is not a blocker.

## RA-200.4 CB79 — `M6-CP3-CB79-P13-NODE-STITCH-KEY`

Code + Build, compile only, implementation agent, Linux.

- **Precheck:** `git diff --quiet afd72107d3213a396ed7f35b53f67dceeea7e7ca HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** RA-200.8 verbatim plus a trailing newline. **Keep its 1 single-space context line** (line 7 of the block). SHA-256 `89f37001d6eea167672c32edf73178cbf98d23e0501e28ca8795fb79a0719028`, 146 lines; `git apply --check`, then apply.
- **Numstat and result SHA-256:**

  | Path | Numstat | Result SHA-256 |
  |---|---|---|
  | `src/geometry/PatchDescriptor.cpp` | `25 2` | `cef48a850cac9ba3c0a471491f1fb5e4d094571173dd6db916df6aa1683ce41f` |
  | `tests/PatchDescriptorMilestoneETests.cpp` | `95 0` | `068271a6d0afb08bba23ba391495ae82de86ff35d50826ca26bffa06ded985fc` |

- **Content:** `arrangement_node_stitch_identity(node, F)` (after `arrangement_node_identity`) builds the node's identity over the primary and every occurrence, each in its own scope; `derive_patch_descriptor` publishes it as `boundaryNodeIdentities`. `arrangement_node_identity` and its halfedge/domain callers are unchanged.
- **Tests (gate rows 884–886):**
  - `SharedNodeCornersPublishOneStitchKeyAcrossSourceCharts`: on the existing two-cell fixture, nodes 0 and 2 are left through different source charts by the two cells, yet both cells publish one key per node; the keys of nodes 0 and 2 differ.
  - `SharedInterfaceCompletesAsOneConnectedDisk`: `complete_surface_cell_complex` on that fixture assembles 2 quads, 6 vertices, 1 component, 1 boundary loop, Euler 1.
  - `CoincidentNodesInDistinctRegionsKeepDistinctStitchKeys`: the same authoritative patch in region 2 and in region 3, at identical source points, gives different keys at every corner.
- **Build:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`, no binary runs.
- **Outcomes:**
  - Precheck, apply, numstat or result-hash mismatch → `M6-CP3-PLAN-P13-NODE-STITCH-KEY-STOP`.
  - Infrastructure failure → `M6-CP3-CB79A-P13-NODE-STITCH-KEY-ORCH` (one retry).

## RA-200.5 TB73 — `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB79's immutable package.

- **Gate:** [manifest](Architecture_M6_TB73_P13_Node_Stitch_Key_Full_Gate_Case_Manifest.tsv), 886 rows, SHA-256 `5d09fa337b42adc8629f4bded8ea35b2181e468fb9dd91f7db5414fa534cfc4a`: TB72's 883 rows byte for byte plus GUARD rows 884–886 (`directional_surface_cell_completion_tests`).
  - Ledger v5 `fd433f54…`; harness P8 `78b8002c…`; `SELF_CHECK_PASS cases=886 deferred=81`.
  - Pre-registered **886/886**, membership **967**.
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: ABNORMAL, harness timeout (600 s, exit 124)**, after assembly, inside the surface-optimizer stage (P13-k).
  - Any Vase verdict before 600 s is a mismatch; `AssemblyRejected` (any completion code) means CB79 did not take.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB73A-P13-NODE-STITCH-KEY-ORCH` (one retry).

## RA-200.6 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB79-P13-NODE-STITCH-KEY` | Implementation agent, Linux; RA-200.8, compile only |
| 2 | `M6-CP3-TB73-P13-NODE-STITCH-KEY-FULL-GATE-EXEC` | Implementation agent, Linux; gate 886/886, membership 967; Vase ABNORMAL 600 s timeout after assembly |
| 3 (Review, can start now) | `M6-CP3-DEFN-P13-OPTIMIZER-SOURCE-QUERY-COST` (P13-k) | Probe DEFN on the CB79 scratch state (Claude), then an exact patch |
| 4 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 5 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

The implementation agent takes steps 1–2 only. Steps 3–4 are probe DEFNs on the Review track (Claude, scratch build). A Review turn that cannot run a scratch probe does not start them; that is a scheduling fact, not a block (RA-172, RA-198, RA-199, RA-200).

## RA-200.7 Probe scripts (scratch, not committed)

`scratchpad/p13j/`:
- `make_probe_j.py`: `PROBE_J_KEY/COUNT/NODES/FAIL`.
- `make_probe_k.py`: `PROBE_K`.
- `make_cb79.py`: the CB79 state and mutants M1/M3.
- `make_patch79.py`: the patch, apply check and result hashes.
- `run_long.sh`: one census process with a set cap.
- `tb73_manifest.tsv`.

The per-row gate driver is RA-198's `p13i/gate.py`.

## RA-200.8 Exact CB79 patch

```diff
diff --git a/src/geometry/PatchDescriptor.cpp b/src/geometry/PatchDescriptor.cpp
--- a/src/geometry/PatchDescriptor.cpp
+++ b/src/geometry/PatchDescriptor.cpp
@@ -437,6 +437,30 @@ SurfaceCellCanonicalIdentity arrangement_node_identity(
   return result;
 }
 
+// A completed patch's boundary corner is stitched by the arrangement node it
+// lies on, so every cell around that node must publish the same key. The key
+// is the node's occurrences in all of its source scopes; the scope of the
+// halfedge leaving the node in one cell selects only that cell's view.
+SurfaceCellCanonicalIdentity arrangement_node_stitch_identity(
+    const SurfaceArrangementNode &node, const Eigen::MatrixXi &F) {
+  std::vector<SurfaceCellCanonicalIdentity> occurrences;
+  occurrences.push_back(source_point_identity(F, node.sourceFace, node.barycentric, source_scope(node)));
+  for (const SurfaceArrangementNodeOccurrence &occurrence : node.occurrences) {
+    occurrences.push_back(source_point_identity(F, occurrence.sourceFace, occurrence.barycentric, source_scope(occurrence)));
+  }
+  occurrences.erase(std::remove_if(occurrences.begin(), occurrences.end(),
+                     [](const SurfaceCellCanonicalIdentity &identity) { return !identity.valid; }),
+                     occurrences.end());
+  std::sort(occurrences.begin(), occurrences.end());
+  occurrences.erase(std::unique(occurrences.begin(), occurrences.end()), occurrences.end());
+  SurfaceCellCanonicalIdentity result;
+  if (occurrences.empty()) return result;
+  result.valid = true;
+  result.values.push_back(static_cast<std::int64_t>(occurrences.size()));
+  for (const SurfaceCellCanonicalIdentity &occurrence : occurrences) append_identity(result, occurrence);
+  return result;
+}
+
 SurfaceCellCanonicalIdentity provenance_semantics(const SurfaceArrangementProvenance &provenance) {
   SurfaceCellCanonicalIdentity result;
   result.valid = true;
@@ -1756,8 +1780,7 @@ PatchDescriptor derive_patch_descriptor(
     patch.boundaryTopologyRegions.push_back(edge.sourceTopologyRegion.value());
     patch.boundaryCharts.push_back(edge.sourceChart.value());
     patch.boundaryNodeIdentities.push_back(
-        patch_descriptor_detail::arrangement_node_identity(
-            *node, F, patch_descriptor_detail::source_scope(edge)));
+        patch_descriptor_detail::arrangement_node_stitch_identity(*node, F));
     patch.boundaryProvenance.push_back(
         patch_descriptor_detail::node_surface_point(*node, V, F, edge));
     patch.hardFeatureCrossing =
diff --git a/tests/PatchDescriptorMilestoneETests.cpp b/tests/PatchDescriptorMilestoneETests.cpp
--- a/tests/PatchDescriptorMilestoneETests.cpp
+++ b/tests/PatchDescriptorMilestoneETests.cpp
@@ -2018,3 +2018,98 @@ TEST(PatchDescriptorMilestoneE, BentNeedleGridCompletesByTheBoundarySearch) {
   EXPECT_EQ(3U, mesh.quads.size());
   EXPECT_EQ(8U, mesh.vertices.size());
 }
+
+TEST(PatchDescriptorMilestoneE,
+     SharedNodeCornersPublishOneStitchKeyAcrossSourceCharts) {
+  const Fixture fixture = make_two_odd_cells_with_shared_interface();
+  const auto first = directional::geometry::derive_patch_descriptor(
+      fixture.complex, fixture.complex.cells[0], fixture.V, fixture.F);
+  const auto second = directional::geometry::derive_patch_descriptor(
+      fixture.complex, fixture.complex.cells[1], fixture.V, fixture.F);
+  const auto corner = [](const auto &patch, const int node) {
+    return static_cast<std::size_t>(std::distance(
+        patch.boundaryVertices.begin(),
+        std::find(patch.boundaryVertices.begin(), patch.boundaryVertices.end(),
+                  node)));
+  };
+  // Nodes 0 and 2 are source vertices of both source faces. Cell 0 leaves
+  // them through face-0 halfedges and cell 1 through face-1 halfedges; both
+  // cells still publish the node's one stitch key.
+  for (const int node : {0, 2}) {
+    const std::size_t a = corner(first.patch, node);
+    const std::size_t b = corner(second.patch, node);
+    ASSERT_LT(a, first.patch.boundaryNodeIdentities.size()) << "node=" << node;
+    ASSERT_LT(b, second.patch.boundaryNodeIdentities.size()) << "node=" << node;
+    ASSERT_NE(first.patch.boundaryCharts[a], second.patch.boundaryCharts[b])
+        << "node=" << node;
+    ASSERT_TRUE(first.patch.boundaryNodeIdentities[a].valid) << "node=" << node;
+    EXPECT_EQ(first.patch.boundaryNodeIdentities[a],
+              second.patch.boundaryNodeIdentities[b])
+        << "node=" << node;
+  }
+  EXPECT_NE(first.patch.boundaryNodeIdentities[corner(first.patch, 0)],
+            first.patch.boundaryNodeIdentities[corner(first.patch, 2)]);
+}
+
+TEST(PatchDescriptorMilestoneE, SharedInterfaceCompletesAsOneConnectedDisk) {
+  const Fixture fixture = make_two_odd_cells_with_shared_interface();
+  directional::geometry::SurfaceCellTracingOptions sourceAuthorityOptions;
+  sourceAuthorityOptions.sourceFaceComponents = {0, 0};
+  sourceAuthorityOptions.sourceFaceSheets = {0, 0};
+  const auto sourceAuthority =
+      directional::geometry::surface_cell_tracing_detail::
+          build_source_topology_regions(fixture.F, sourceAuthorityOptions);
+  ASSERT_TRUE(sourceAuthority.has_value());
+  directional::geometry::SurfaceCellComplexCompletionOptions completionOptions;
+  completionOptions.sourceAuthority = &sourceAuthority.value();
+  const auto completion = directional::geometry::complete_surface_cell_complex(
+      fixture.complex, fixture.V, fixture.F, completionOptions);
+  ASSERT_TRUE(completion.is_produced());
+  // The two cells share the source diagonal, so the assembly is the source
+  // disk, not two quads that only touch geometrically.
+  const auto &assembly = completion.product().assembly;
+  EXPECT_EQ(2U, assembly.mesh.quads.size());
+  EXPECT_EQ(6U, assembly.mesh.vertices.size());
+  EXPECT_EQ(1, assembly.connectedComponents);
+  EXPECT_EQ(1, assembly.boundaryLoopCount);
+  EXPECT_EQ(1, assembly.eulerCharacteristic);
+}
+
+TEST(PatchDescriptorMilestoneE,
+     CoincidentNodesInDistinctRegionsKeepDistinctStitchKeys) {
+  Fixture first = make_authoritative_patch({1, 1, 1, 1});
+  Fixture second = first;
+  const auto region = test_topology_region_id(3);
+  for (auto &node : second.complex.nodes) {
+    node.sourceTopologyRegion = region;
+    for (auto &occurrence : node.occurrences) {
+      occurrence.sourceTopologyRegion = region;
+    }
+  }
+  for (auto &edge : second.complex.halfedges) {
+    edge.sourceTopologyRegion = region;
+  }
+  for (auto &cell : second.complex.cells) {
+    cell.sourceTopologyRegion = region;
+  }
+  bind_patch_charts_to_source_topology(first.F, first.complex);
+  bind_patch_charts_to_source_topology(second.F, second.complex);
+  const auto a = directional::geometry::derive_patch_descriptor(
+      first.complex, first.complex.cells.front(), first.V, first.F);
+  const auto b = directional::geometry::derive_patch_descriptor(
+      second.complex, second.complex.cells.front(), second.V, second.F);
+  ASSERT_EQ(a.patch.boundaryVertices, b.patch.boundaryVertices);
+  ASSERT_EQ(4U, a.patch.boundaryNodeIdentities.size());
+  ASSERT_EQ(4U, b.patch.boundaryNodeIdentities.size());
+  for (std::size_t index = 0; index < 4U; ++index) {
+    ASSERT_TRUE(a.patch.boundaryNodeIdentities[index].valid);
+    ASSERT_TRUE(b.patch.boundaryNodeIdentities[index].valid);
+    EXPECT_EQ(a.patch.boundaryProvenance[index].face,
+              b.patch.boundaryProvenance[index].face);
+    EXPECT_EQ(a.patch.boundaryProvenance[index].barycentric,
+              b.patch.boundaryProvenance[index].barycentric);
+    EXPECT_NE(a.patch.boundaryNodeIdentities[index],
+              b.patch.boundaryNodeIdentities[index])
+        << "corner=" << index;
+  }
+}
```

## Review closeout

| Check | Result |
|---|---|
| Scope | Review/Definition only; no product, test, fixture, selector, benchmark or build file changed in the repository. Scratch probes only |
| Exact patch | Embedded block re-hashes to `89f37001…`; `git apply --check` and apply on a clean HEAD worktree; both result hashes match |
| Manifest | TB72 prefix byte-identical; `SELF_CHECK_PASS cases=886 deferred=81` with harness P8 |
| Accepted selector prefix re-hashed | n/a: no selector change |
| Standing state | CP2 491/491; stable 66/17/49, debt 1; ledger v5 81 deferred; selector497 and CP3 unpromoted |
| `review_check.py boundary` | ALL CHECKS PASSED on the history-bearing checkout; `review_check.py ledgers --base d2e3c1f7a` PASSED |
| Scratch state left | `wt61`/`bld61` = HEAD + clean CB79 + inert `PROBE_K` (unset = HEAD); scripts in `scratchpad/p13j/` |
