# RA-195 — P13-f completion ownership cost: probe adjudication; exact CB71/CB72, TB68 (2026-11-01)

**Turn:** `M6-CP3-DEFN-P13-COMPLETION-OWNERSHIP-COST` (Review/Definition), reopened at `fa06ae4ff`. The [static decision](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_DEFN_P13_Completion_Ownership_Cost_Review_Decision_20261101.md") (ChatGPT, `55b8e18b6`) named the right two cost sites. But it ran no probe, so it did not name Vase's next failure. It also froze an open-ended Code + Build plan ([CB71 plan](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_CP3_CB71_P13_Completion_Chart_Graph_Reuse_Code_Build_Plan_20261101.md")) whose API, binding rule and tests the implementation agent would have had to design. RA-193.4 gave this DEFN one exit: name Vase's next failure, or a PASS, within the 600 s harness bound. RA-195 meets that exit with probes on current source and replaces the plan with two exact patches.

Source at review: HEAD `fa06ae4ff`; `src include tests benchmarks CMakeLists.txt cmake` are byte-equal to CB70 `9754500b2058229b7f0a6268838953650690b031` (TB67 package `13087332886`, 871/871). Nothing landed after TB67 except documents.

## RA-195.1 Findings on the decision

1. **F1 — exit not met.** The decision is "static source/evidence review only". It leaves the next Vase verdict to a later TB ("no semantic result can be presumed here"). RA-193.4 and TODO required the DEFN to name it. Probes name it in RA-195.2: Vase ends at `completion` with `InvalidCompletionQuadEmbedding` (P13-g) in 138 s.
2. **F2 — monolithic, open-ended CB.** The plan has five open items. Graph lifetime is left to the agent ("establish graph lifetime/source binding"), and so is the API ("make caller proof explicit in the API or refuse reuse"). It also asks for six categories of new tests and refactors two validators and a patch-cache path. It has no patch, no numstat and no result hashes. Implementation agents receive exact patches only.
3. **F3 — the binding rule contradicts itself and the graph's design.** The decision forbids "implicit pointer-identity acceptance", yet says that re-running `matches_source_faces` per patch "would nullify the win". `SourceChartTransitionGraph` already borrows its inputs by pointer and records the binding check once, at build (CB64, RA-188: "the graph borrows immutable stage products, so queries do not re-validate every row"). Stage products are immutable `const` views (DESIGN §7.3). A graph that borrows exactly the same face matrix, authority, hard-edge set and tolerance therefore answers every query as a fresh graph would; that identity *is* the binding proof. Ruled in Amendment 27.
4. **F4 — cost inventory unmeasured.** The decision lists the two validator sites correctly (`PureQuadCompletion.cpp:869`, `:1322`; callers `:1282`, `:1582`, `PatchDescriptor.cpp:2842`). It never measured their share, and it treats the per-vertex `matches_source_faces` as a check to keep rather than the same O(F) work. The profile (RA-195.2) puts graph construction at 93.5 % of completion CPU and the per-vertex closure at 83.2 %. Other per-call O(F) work the decision missed is measured or bounded as residual: the per-patch `SurfaceProjectionBvh` (1.0 %), `matches_source_faces` per vertex (0.9 %), assembly's per-certificate `matches_source_faces` and the per-lineage graph in `rebuild_aggregate_output_identity_caches` (multi-component aggregation only). They are O20, not CB scope.
5. **F5 — TB obligations that a TB cannot observe.** "Instrument graph-construction count … one per completion batch" cannot be executed by an artifact-only TB. Replaced: the reuse rule is proven by two unit tests with mutation checks (RA-195.4–5), and the TB registers time-to-verdict.
6. **F6 — lifetime question left open, now resolved.** `complete_surface_cell_complex_pass` already builds one `SurfacePointSourceSupportResolver` per pass and passes it by `const` pointer through `PureQuadCompletionOptions`. The graph follows the same pattern and the same scope, which covers generated, retried and cache-reused patches. Standalone callers pass nothing and get a local graph.
7. **F7 — what stands.** The site attribution, O((P+V)·F), keeping assembly's existing shared graph, no promised Vase PASS, and keeping every ownership check.

## RA-195.2 Probes (macOS, scratch, diagnostic only)

Build `bld61` (Release `-O3`, GMP) of the exact CB70 source. Probe switch `PROBE_P13F` in a scratch copy of `PureQuadCompletion.cpp` only: `0` = HEAD; `1` = one graph per validator call, reused by every vertex; `2` = `1` plus one graph and BVH per pass. Every Vase run is one fresh process of `UniformPhaseFront/SurfaceCellDesignAcceptance.ProducesDirectSourceAuthoritativePureQuadOutput/Vase`.

| Probe | Result |
|---|---|
| HEAD stack, 8 s sample at ~4 min | completion pass 6,193 samples: `validate_completion_domain_ownership` 6,124 (98.9 %), `close_completion_lineage_source_authority` 5,152 (83.2 %), `SourceChartTransitionGraph` construction 5,790 (93.5 %), `SurfaceProjectionBvh` 61 (1.0 %), `matches_source_faces` 56 (0.9 %) |
| Mode 0 (HEAD), uncapped | completion entered at 152.9 s; 20,000 patches by 891 s; 280,000 per-vertex graph builds by 1,690 s; **same RED** (`InvalidCompletionQuadEmbedding;patch=1200;…;bow-tie-intersection`), **1,732 s** wall. TB67's 600 s timeout was this run cut short |
| Mode 1 (per-vertex reuse only) | completion entered at 206.7 s; 20,000 patches by 306.1 s (≈ 5 ms per patch, still one graph + one BVH each); **RED** `NotProductionReady:completion`, `completion=InvalidCompletionQuadEmbedding;patch=1200;backend=bounded-combinatorial;variant=15;localQuad=2;classification=bow-tie-intersection`; 386 s wall with two other processes running |
| Mode 2 (per-vertex + per-pass) | completion entered at 135.1 s, more than 280,000 lineage closures done by 136.3 s; **same RED**, 138 s wall |
| Production CB71 + CB72 (clean build of the RA-195.8–9 patches, no probe code) | Vase **same RED**, 213 s wall while the 873-row gate (3 workers) and two other processes ran. New rows 872–873 PASS; `PureQuadCompletionPhase18.*` 74/74. Mutant M1 (closure reuses any lent graph) fails only row 872; mutant M2 (validator reuses any lent graph) fails only row 873. The CB71-only state passes `-fsyntax-only` for `PureQuadCompletion.cpp`, `PatchDescriptor.cpp`, `RemeshPipeline.cpp` and the test file. The chain CB71 → CB72 applies to `fa06ae4ff` and reproduces every result SHA-256 |
| Gate and ledger, production build | TB68 manifest (873): **872/873**, only row 283 (O16, macOS LegacyInteger). Against the CB70 baseline gate (RA-193, 870/871), no shared row changes; new rows 872–873 PASS. Ledger v5: 0/81 PASS, as before; only row 365 (Vase) changes, TIMEOUT → RED in 164 s. A first gate run that by mistake used an M2-mutant completion binary failed only row 873, which confirms M2 is caught by that row alone in the full gate |
| Cylinder (mode 0) | PASS 8.0 s; it uses the authoritative phase-front path (`validate_materialized_completion_domain_ownership`), not patch completion |

The next failure is the same in both modes, and the same as HEAD's (mode 0 row), so it does not depend on the change. **P13-g** (new): patch 1200, completed by the bounded-combinatorial fallback at ownership variant 15, embeds local quad 2 as a bow-tie; the pass then publishes no quads. The terminal also reads `detail=None` while the typed cause sits only in `completion=` (an Amendment 19 attribution gap of the O18 kind). Both go to `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING`.

## RA-195.3 Rulings

- **DESIGN Amendment 27** (added): a stage builds one `SourceChartTransitionGraph` per invocation and passes it to its per-patch and per-vertex checks. Reuse requires `borrows()`: the same face matrix, authority, hard-edge set and barycentric tolerance objects. The borrowed graph's `source_bound()` stands for `matches_source_faces` on those inputs. A graph that does not borrow exactly the callee's inputs is ignored, and the callee builds its own, which is the pre-change path. It is never accepted on trust and never a new failure. No check, failure code or check order changes.
- **CB71** (exact, RA-195.8): per-vertex reuse in both ownership validators. **CB72** (exact, RA-195.9): one graph per completion pass, threaded through `PureQuadCompletionOptions::sourceTransitions` and the cache-reuse validation. CB72 is needed: with CB71 alone each patch still costs ≈ 5 ms (mode 1), which leaves Vase too close to the 600 s bound.
- One TB after both (TB68). A TB after CB71 alone would have to pre-register a timing-dependent Vase outcome (≈ 390 s on macOS, unknown on Linux).
- **O20** (new, residual, non-blocking): the per-patch BVH in `complete_pure_quad_patch`, assembly's per-certificate `matches_source_faces` (`owner_validated_typed_authority_certificate`), and the per-lineage graph in `rebuild_aggregate_output_identity_caches` (multi-component aggregation only). Owner: a performance slice, or the first fixture whose census times out in one of them.
- The decision's CB71 plan is superseded. The turn ID `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` is kept for the exact patch.

## RA-195.4 CB71 — `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE`

Code + Build, implementation agent, Linux workflow runner, compile only.

- **Precheck:** `git diff --quiet 9754500b2058229b7f0a6268838953650690b031 HEAD -- src include tests benchmarks CMakeLists.txt cmake`.
- **Patch:** the RA-195.8 block verbatim plus a trailing newline. Keep its 6 single-space context lines. SHA-256 `8512400fe56c59f35ac3770383890366f35028c47346ba1fdeb04ca5014e5852` (261 lines, 12,237 bytes). `git apply --check`, then apply.

| Path | Numstat | Base SHA-256 | Result SHA-256 |
|---|---|---|---|
| `include/directional/geometry/PureQuadCompletion.h` | `14 0` | `274058762297c11a…` | `37fcd5b041da1820762bd584de2ee3bccb073fe9e8eb2f742f985107da862bdf` |
| `include/directional/geometry/SourceChartTransitions.h` | `18 0` | `aa981c5a916f0ddf…` | `21553d343a10d603e1faffe62ab7b3560fb396ac464c0793642e5ccd6736ead7` |
| `src/geometry/PureQuadCompletion.cpp` | `49 9` | `1b13f454a45fd0df…` | `6a78a3e4226840483e0f6aa0a71a6c1bfb64d9304ae9944c808c5870b2009b1c` |
| `tests/PureQuadCompletionPhase18Tests.cpp` | `86 0` | `d7c7914dfd15e159…` | `6de658cc973176e97bdd15f348dfa6798093a4ab1b221955236df71025da1bab` |

- **What it does:**
  - Adds `SourceChartTransitionGraph::borrows()` and `source_bound()`.
  - Adds a `close_completion_lineage_source_authority` overload that takes a lent graph; the original signature forwards with none.
  - `validate_materialized_completion_domain_ownership` builds one graph per mesh.
  - `validate_completion_domain_ownership` lends its existing graph to every vertex.
  - No check, failure code or check order changes (Amendment 27).
- **New test** (gate row 872, `ra195:closure-graph`): `PureQuadCompletionPhase18.LineageClosureReusesOnlyAGraphBorrowingItsExactInputs`.
  - On every row of a produced patch, a borrowing graph, a graph over a copied face matrix and an unbound graph over foreign authority each give the standalone result and failure.
  - Unbound inputs fail with `CompletionOwnershipInvalidSourceAuthorityClosure` in both overloads.
  - Mutant M1 (reuse any lent graph) fails it; probe-verified.
- **Compile:** one eight-target Linux Release/static GMP/GMPXX package, `runtimeExecution=false`. No binary runs.
- **Outcomes:**
  - Exact → `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH`.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-GRAPH-STOP`.
  - Infrastructure → `M6-CP3-CB71A-P13-COMPLETION-GRAPH-ORCH` (one retry).

## RA-195.5 CB72 — `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH`

Code + Build, implementation agent, Linux workflow runner, compile only.

- **Precheck:** `git diff --name-only 9754500b2058229b7f0a6268838953650690b031 HEAD -- src include tests benchmarks CMakeLists.txt cmake` lists exactly CB71's four paths, each at its RA-195.4 result SHA-256.
- **Patch:** the RA-195.9 block verbatim plus a trailing newline. Keep its 5 single-space context lines. SHA-256 `514c6d87b7ad47083262b802e7b59da931a9bbeb71e0f3c14af49a6668ff5d6f` (178 lines, 9,539 bytes). `git apply --check`, then apply.

| Path | Numstat | Base SHA-256 | Result SHA-256 |
|---|---|---|---|
| `include/directional/geometry/PureQuadCompletion.h` | `6 1` | `37fcd5b041da1820…` (CB71) | `ba998d51a484e87ec698fc94f0aeaccf391e02de0662468a739e75ad070ec371` |
| `src/geometry/PatchDescriptor.cpp` | `10 1` | `c4cf22ea313961d0…` | `c864fd4a3e12e6ac0b48981aa250005c96b73ab7d368490deaf2a5e1c600e564` |
| `src/geometry/PureQuadCompletion.cpp` | `17 6` | `6a78a3e422684048…` (CB71) | `eac7161b328bb27b2bd4c0c905bc0a564e59429ddbbcb5f035c7b92181ef6b6c` |
| `tests/PureQuadCompletionPhase18Tests.cpp` | `58 0` | `6de658cc973176e9…` (CB71) | `37db444abea6791f364203cbf9209beb588552bcf724bacdcf292585b76697d3` |

- **What it does:**
  - Adds `PureQuadCompletionOptions::sourceTransitions` and a defaulted trailing `sourceTransitions` parameter on `validate_completion_domain_ownership`.
  - `complete_surface_cell_complex_pass` builds one graph next to its existing `SurfacePointSourceSupportResolver`.
  - It lends that graph to every generated patch and to the cache-reuse validation (`PatchDescriptor.cpp:2842`).
  - A graph that does not borrow exactly the patch's inputs is ignored (Amendment 27). Public callers default to `nullptr`.
- **New test** (gate row 873, `ra195:pass-graph`): `PureQuadCompletionPhase18.PatchOwnershipReusesOnlyASharedGraphBorrowingItsExactInputs`.
  - On the vertex/edge alias fixture, a borrowing graph and a graph split by a hard diagonal each give the local product: the same provenance face, charts and support.
  - The split graph is shown to be discriminating: with the diagonal really hard, the alias cannot rebind, and the local and shared calls reject with one detail.
  - Mutant M2 (the validator reuses any lent graph) fails it; probe-verified.
- **Compile:** as CB71.
- **Outcomes:**
  - Exact → TB68.
  - Mismatch → `M6-CP3-PLAN-P13-COMPLETION-PASS-GRAPH-STOP`.
  - Infrastructure → `M6-CP3-CB72A-P13-COMPLETION-PASS-GRAPH-ORCH` (one retry).

## RA-195.6 TB68 — `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-EXEC`

Test + Benchmark, artifact-only, CB72's immutable package.

- **Gate:** [manifest](M6_Consolidated_Record.md#m6-folded-document-index-2026-11-09--durable-do-not-delete "folded: Architecture_M6_TB68_P13_Completion_Graph_Reuse_Full_Gate_Case_Manifest.tsv"), 873 rows, SHA-256 `3b6b9f425d4061885b393ccd2d530cbcd3d4f39916859e0db197ce1e6029ea60`: TB67's 871 plus rows 872–873. Ledger v5 `fd433f54…`; harness P8 `78b8002c…`, `SELF_CHECK_PASS cases=873 deferred=81`. Pre-registered **873/873**, membership **954** (873 + 81).
- **Census:** `3af1dc0d…`, unchanged.
  - Cylinder: PASS.
  - BunnyRandom: P13-e unchanged (`SingularityPortClassCountMismatch;sourceVertex=49`).
  - **Vase: RED within 600 s**, `terminal=NotProductionReady:completion` with `completion=InvalidCompletionQuadEmbedding;…`. The registered match is that stage and that code. The macOS locus (patch 1200, `bounded-combinatorial`, variant 15, `bow-tie-intersection`) is recorded, not registered, because an exact tie may resolve differently on Linux (RA-176).
  - An ABNORMAL Vase (timeout) is a mismatch.
- **Outcomes:**
  - Mismatch → `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-REV` (Review).
  - Infrastructure → `M6-CP3-TB68A-P13-COMPLETION-GRAPH-ORCH` (one retry).

## RA-195.7 Turn sequence

| Step | Turn | Track |
|---|---|---|
| 1 — NEXT | `M6-CP3-CB71-P13-COMPLETION-CHART-GRAPH-REUSE` | Implementation agent, Linux; RA-195.8, compile only |
| 2 | `M6-CP3-CB72-P13-COMPLETION-PASS-GRAPH` | Implementation agent, Linux; RA-195.9, compile only |
| 3 | `M6-CP3-TB68-P13-COMPLETION-GRAPH-FULL-GATE-EXEC` | Implementation agent, Linux; gate 873/873, membership 954; Vase RED `completion` / `InvalidCompletionQuadEmbedding` within 600 s |
| 4 (Review, can start now) | `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING` (P13-g) | Probe DEFN. The scratch build reproduces it in 138 s. Name the owner: bounded-combinatorial template, projection, or the ownership-variant search. Close the `detail=None` attribution gap. Then an exact patch |
| 5 (Review, parallel) | `M6-CP3-DEFN-P13-SINGULARITY-PORT-COUNT` (P13-e, BunnyRandom vertex 49) | Probe DEFN, then an exact patch |
| 6 | P13 re-census → O6/O9 where reached → matrix 6/6 → retire/FIXTURE/PRODUCT/OPEN slices → CP3-REV | One slice at a time |

## RA-195.8 Exact CB71 patch

Base: CB70 source `9754500b2…` (HEAD `fa06ae4ff`). SHA-256 `8512400fe56c59f35ac3770383890366f35028c47346ba1fdeb04ca5014e5852` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PureQuadCompletion.h b/include/directional/geometry/PureQuadCompletion.h
index 990479f65..ce7eadeb0 100644
--- a/include/directional/geometry/PureQuadCompletion.h
+++ b/include/directional/geometry/PureQuadCompletion.h
@@ -510,6 +510,20 @@ bool close_completion_lineage_source_authority(
     const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
     std::string &failure);
 
+/**
+ * The same closure against a caller-built source-chart graph, so a validator
+ * builds one graph per mesh rather than one per vertex. A graph that does not
+ * borrow exactly these inputs is not used; a local graph is built instead.
+ */
+bool close_completion_lineage_source_authority(
+    PureQuadVertexLineage &lineage,
+    const SurfacePointSourceSupport &support,
+    const Eigen::MatrixXi *sourceFaces,
+    const SourceTopologyRegions *sourceAuthority,
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    const SourceChartTransitionGraph &sourceTransitions,
+    std::string &failure);
+
 /**
  * Validate and close a materialized authoritative phase-front mesh before it
  * may be published as a successful completion result. This adapter performs
diff --git a/include/directional/geometry/SourceChartTransitions.h b/include/directional/geometry/SourceChartTransitions.h
index 6e4c96f69..000b78bce 100644
--- a/include/directional/geometry/SourceChartTransitions.h
+++ b/include/directional/geometry/SourceChartTransitions.h
@@ -215,6 +215,24 @@ public:
                static_cast<std::size_t>(faces_->rows());
   }
 
+  /**
+   * True when this graph borrows exactly these inputs. Borrowed stage
+   * products are immutable, so such a graph answers every query exactly as a
+   * graph freshly built from the same inputs.
+   */
+  [[nodiscard]] bool borrows(
+      const Eigen::MatrixXi *sourceFaces,
+      const SourceTopologyRegions *sourceAuthority,
+      const std::set<authority::SourceEdgeTopologyKey> &hardFeatureEdges,
+      const double barycentricTolerance = 1.0e-8) const {
+    return faces_ == sourceFaces && authority_ == sourceAuthority &&
+           hardFeatureEdges_ == &hardFeatureEdges &&
+           barycentricTolerance_ == std::max(0.0, barycentricTolerance);
+  }
+
+  /** build()'s SourceTopologyRegions::matches_source_faces() result. */
+  [[nodiscard]] bool source_bound() const { return sourceBound_; }
+
   [[nodiscard]] std::optional<SourceProjectionChart>
   chart(const int sourceFace) const {
     if (!available() || sourceFace < 0 || sourceFace >= faces_->rows() ||
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
index f4d647a9e..6fea2d005 100644
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -847,15 +847,24 @@ std::optional<std::pair<int, int>> completion_certified_hard_rail_components(
   return components;
 }
 
-bool close_completion_lineage_source_authority(
+bool close_lineage_source_authority_with_graph(
     PureQuadVertexLineage &lineage,
     const SurfacePointSourceSupport &support,
     const Eigen::MatrixXi *sourceFaceMatrix,
     const SourceTopologyRegions *sourceAuthority,
     const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
-    std::string &failure) {
+    const SourceChartTransitionGraph *callerGraph, std::string &failure) {
+  const std::set<authority::SourceEdgeTopologyKey> &hardFeatureEdges =
+      sourceHardFeatureEdges != nullptr ? *sourceHardFeatureEdges
+                                        : empty_hard_feature_edges();
+  // A borrowing graph recorded matches_source_faces() for these immutable
+  // inputs when it was built; any other graph is ignored.
+  const bool reuseGraph =
+      callerGraph != nullptr &&
+      callerGraph->borrows(sourceFaceMatrix, sourceAuthority, hardFeatureEdges);
   if (sourceFaceMatrix == nullptr || sourceAuthority == nullptr ||
-      !sourceAuthority->matches_source_faces(*sourceFaceMatrix) ||
+      !(reuseGraph ? callerGraph->source_bound()
+                   : sourceAuthority->matches_source_faces(*sourceFaceMatrix)) ||
       !lineage.sourcePoint.valid() || !support.valid()) {
     failure = "CompletionOwnershipInvalidSourceAuthorityClosure";
     return false;
@@ -866,10 +875,12 @@ bool close_completion_lineage_source_authority(
     return false;
   }
 
-  const SourceChartTransitionGraph transitionGraph(
-      sourceFaceMatrix, sourceAuthority, sourceHardFeatureEdges != nullptr
-          ? *sourceHardFeatureEdges
-          : empty_hard_feature_edges());
+  std::optional<SourceChartTransitionGraph> localGraph;
+  if (!reuseGraph) {
+    localGraph.emplace(sourceFaceMatrix, sourceAuthority, hardFeatureEdges);
+  }
+  const SourceChartTransitionGraph &transitionGraph =
+      reuseGraph ? *callerGraph : localGraph.value();
   if (!transitionGraph.available()) {
     failure = "CompletionOwnershipMissingPublishedSourceChart";
     return false;
@@ -1237,6 +1248,31 @@ bool close_completion_lineage_source_authority(
   return true;
 }
 
+bool close_completion_lineage_source_authority(
+    PureQuadVertexLineage &lineage,
+    const SurfacePointSourceSupport &support,
+    const Eigen::MatrixXi *sourceFaceMatrix,
+    const SourceTopologyRegions *sourceAuthority,
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    std::string &failure) {
+  return close_lineage_source_authority_with_graph(
+      lineage, support, sourceFaceMatrix, sourceAuthority,
+      sourceHardFeatureEdges, nullptr, failure);
+}
+
+bool close_completion_lineage_source_authority(
+    PureQuadVertexLineage &lineage,
+    const SurfacePointSourceSupport &support,
+    const Eigen::MatrixXi *sourceFaceMatrix,
+    const SourceTopologyRegions *sourceAuthority,
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    const SourceChartTransitionGraph &sourceTransitions,
+    std::string &failure) {
+  return close_lineage_source_authority_with_graph(
+      lineage, support, sourceFaceMatrix, sourceAuthority,
+      sourceHardFeatureEdges, &sourceTransitions, failure);
+}
+
 bool validate_materialized_completion_domain_ownership(
     PureQuadMesh &mesh, const Eigen::MatrixXi &sourceFaces,
     const SourceTopologyRegions *sourceAuthority,
@@ -1255,6 +1291,10 @@ bool validate_materialized_completion_domain_ownership(
     failure = "CompletionOwnershipInvalidSourceSupport";
     return false;
   }
+  const SourceChartTransitionGraph transitionGraph(
+      &sourceFaces, sourceAuthority, sourceHardFeatureEdges != nullptr
+          ? *sourceHardFeatureEdges
+          : empty_hard_feature_edges());
   std::set<int> outputVertices;
   for (std::size_t row = 0; row < mesh.vertices.size(); ++row) {
     const int outputVertex = mesh.vertices[row];
@@ -1281,7 +1321,7 @@ bool validate_materialized_completion_domain_ownership(
     }
     if (!close_completion_lineage_source_authority(
             lineage, support, &sourceFaces, sourceAuthority,
-            sourceHardFeatureEdges, failure)) {
+            sourceHardFeatureEdges, transitionGraph, failure)) {
       return false;
     }
   }
@@ -1581,7 +1621,7 @@ bool validate_completion_domain_ownership(
       lineage.sourceSupport = support.identity;
       if (!close_completion_lineage_source_authority(
               lineage, support, sourceFaceMatrix, sourceAuthority,
-              sourceHardFeatureEdges, failure)) {
+              sourceHardFeatureEdges, transitionGraph, failure)) {
         return false;
       }
     }
diff --git a/tests/PureQuadCompletionPhase18Tests.cpp b/tests/PureQuadCompletionPhase18Tests.cpp
index 8b28513e7..5ea9866e4 100644
--- a/tests/PureQuadCompletionPhase18Tests.cpp
+++ b/tests/PureQuadCompletionPhase18Tests.cpp
@@ -1409,6 +1409,92 @@ TEST(PureQuadCompletionPhase18,
   EXPECT_FALSE(rejection.boundaryVertex);
 }
 
+TEST(PureQuadCompletionPhase18,
+     LineageClosureReusesOnlyAGraphBorrowingItsExactInputs) {
+  const CompletionFixture fixture = generated_plane_patch();
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 38;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  const auto sourceAuthority = test_source_authority(
+      fixture.faces, {0, 0, 1}, {0, 0, 1});
+  options.sourceAuthority = &sourceAuthority;
+  const auto completion = directional::geometry::complete_pure_quad_patch(
+      fixture.patch, options);
+  ASSERT_TRUE(completion.is_produced());
+
+  const auto &hard = no_hard_feature_edges();
+  const directional::geometry::SourceChartTransitionGraph borrowed(
+      &fixture.faces, &sourceAuthority, hard);
+  ASSERT_TRUE(borrowed.borrows(&fixture.faces, &sourceAuthority, hard));
+  ASSERT_TRUE(borrowed.source_bound());
+  const Eigen::MatrixXi copiedFaces = fixture.faces;
+  const directional::geometry::SourceChartTransitionGraph copied(
+      &copiedFaces, &sourceAuthority, hard);
+  EXPECT_FALSE(copied.borrows(&fixture.faces, &sourceAuthority, hard));
+  Eigen::MatrixXi foreignFaces(3, 3);
+  foreignFaces << 0, 1, 3,
+                  1, 2, 3,
+                  4, 5, 6;
+  const auto foreignAuthority =
+      test_source_authority(foreignFaces, {0, 0, 1}, {0, 0, 1});
+  const directional::geometry::SourceChartTransitionGraph unbound(
+      &fixture.faces, &foreignAuthority, hard);
+  ASSERT_FALSE(unbound.source_bound());
+  ASSERT_FALSE(unbound.available());
+
+  const directional::geometry::SurfacePointSourceSupportResolver resolver(
+      fixture.faces);
+  int closedRows = 0;
+  for (std::size_t row = 0; row < completion.product().vertexLineage.size();
+       ++row) {
+    const auto support =
+        resolver.resolve(completion.product().vertexProvenance[row]);
+    auto expected = completion.product().vertexLineage[row];
+    std::string expectedFailure;
+    const bool expectedClosed = directional::geometry::pure_quad_detail::
+        close_completion_lineage_source_authority(
+            expected, support, &fixture.faces, &sourceAuthority, &hard,
+            expectedFailure);
+    closedRows += expectedClosed ? 1 : 0;
+    for (const auto *graph : {&borrowed, &copied, &unbound}) {
+      auto actual = completion.product().vertexLineage[row];
+      std::string failure;
+      EXPECT_EQ(expectedClosed,
+                directional::geometry::pure_quad_detail::
+                    close_completion_lineage_source_authority(
+                        actual, support, &fixture.faces, &sourceAuthority,
+                        &hard, *graph, failure))
+          << "row " << row << ": " << failure;
+      EXPECT_EQ(expectedFailure, failure) << "row " << row;
+      EXPECT_EQ(expected.sourceCharts, actual.sourceCharts) << "row " << row;
+      EXPECT_EQ(expected.sourceTopologyRegions, actual.sourceTopologyRegions)
+          << "row " << row;
+      EXPECT_EQ(expected.sourceIsolationSheets, actual.sourceIsolationSheets)
+          << "row " << row;
+    }
+
+    // Inputs that fail the source binding fail identically with a graph
+    // that borrows those same inputs.
+    auto unboundExpected = completion.product().vertexLineage[row];
+    auto unboundActual = unboundExpected;
+    std::string unboundExpectedFailure;
+    std::string unboundFailure;
+    EXPECT_FALSE(directional::geometry::pure_quad_detail::
+                     close_completion_lineage_source_authority(
+                         unboundExpected, support, &fixture.faces,
+                         &foreignAuthority, &hard, unboundExpectedFailure));
+    EXPECT_FALSE(directional::geometry::pure_quad_detail::
+                     close_completion_lineage_source_authority(
+                         unboundActual, support, &fixture.faces,
+                         &foreignAuthority, &hard, unbound, unboundFailure));
+    EXPECT_EQ("CompletionOwnershipInvalidSourceAuthorityClosure",
+              unboundExpectedFailure);
+    EXPECT_EQ(unboundExpectedFailure, unboundFailure);
+  }
+  EXPECT_GT(closedRows, 0);
+}
+
 TEST(PureQuadCompletionPhase18,
      CompletionRejectsComponentSheetMismatchAtSharedSourceEntity) {
   CompletionFixture fixture = source_support_alias_patch();
```

## RA-195.9 Exact CB72 patch

Base: CB71's result. SHA-256 `514c6d87b7ad47083262b802e7b59da931a9bbeb71e0f3c14af49a6668ff5d6f` with a trailing newline.

```diff
diff --git a/include/directional/geometry/PureQuadCompletion.h b/include/directional/geometry/PureQuadCompletion.h
index ce7eadeb0..7560d895d 100644
--- a/include/directional/geometry/PureQuadCompletion.h
+++ b/include/directional/geometry/PureQuadCompletion.h
@@ -409,6 +409,10 @@ struct PureQuadCompletionOptions {
   const SurfacePointSourceSupportResolver *sourceSupportResolver = nullptr;
   const SourceTopologyRegions *sourceAuthority = nullptr;
   const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges = nullptr;
+  // Optional source-chart graph shared by every patch of one completion pass.
+  // Used only when it borrows exactly the source inputs above; otherwise
+  // ownership validation builds its own graph for the patch.
+  const SourceChartTransitionGraph *sourceTransitions = nullptr;
 };
 
 struct PureQuadCompletionEvidence {
@@ -543,7 +547,8 @@ bool validate_completion_domain_ownership(
     const Eigen::MatrixXi *sourceFaces,
     const SourceTopologyRegions *sourceAuthority, std::string &failure,
     PureQuadCompletionOwnershipRejection *ownershipRejection,
-    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges);
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    const SourceChartTransitionGraph *sourceTransitions = nullptr);
 
 } // namespace pure_quad_detail
 
diff --git a/src/geometry/PatchDescriptor.cpp b/src/geometry/PatchDescriptor.cpp
index b9da3c5f8..9866dfba2 100644
--- a/src/geometry/PatchDescriptor.cpp
+++ b/src/geometry/PatchDescriptor.cpp
@@ -2480,6 +2480,13 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     ReusableCompletionProducts *reusableProducts = nullptr) {
   SurfaceCellComplexCompletionDraft result;
   const SurfacePointSourceSupportResolver sourceSupportResolver(F);
+  // One source-chart graph for every patch of this pass; ownership validation
+  // reuses it instead of rebuilding it from F for each patch.
+  const SourceChartTransitionGraph sourceTransitions(
+      &F, options.sourceAuthority,
+      options.sourceHardFeatureEdges != nullptr
+          ? *options.sourceHardFeatureEdges
+          : empty_hard_feature_edges());
   SurfaceCellParityRepairResult parityRepair =
       repair_surface_cell_boundary_parity(std::move(complex));
   std::optional<SurfaceCellParityRepairProduct> parityProduct;
@@ -2729,6 +2736,7 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
     completionOptions.sourceAuthority = options.sourceAuthority;
     completionOptions.sourceHardFeatureEdges =
         options.sourceHardFeatureEdges;
+    completionOptions.sourceTransitions = &sourceTransitions;
     return complete_pure_quad_patch(descriptor.patch, completionOptions);
   };
 
@@ -2843,7 +2851,8 @@ SurfaceCellComplexCompletionDraft complete_surface_cell_complex_pass(
                 descriptor.patch, reused, completionVariant,
                 &sourceSupportResolver, &F, options.sourceAuthority,
                 ownershipFailure,
-                &ownershipRejection, options.sourceHardFeatureEdges);
+                &ownershipRejection, options.sourceHardFeatureEdges,
+                &sourceTransitions);
         const bool topologyValid =
             ownershipValid && pure_quad_topology_is_disk(reused) &&
             !reused.quads.empty();
diff --git a/src/geometry/PureQuadCompletion.cpp b/src/geometry/PureQuadCompletion.cpp
index 6fea2d005..08f044b39 100644
--- a/src/geometry/PureQuadCompletion.cpp
+++ b/src/geometry/PureQuadCompletion.cpp
@@ -1335,7 +1335,8 @@ bool validate_completion_domain_ownership(
     const Eigen::MatrixXi *sourceFaceMatrix,
     const SourceTopologyRegions *sourceAuthority, std::string &failure,
     PureQuadCompletionOwnershipRejection *ownershipRejection,
-    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges) {
+    const std::set<authority::SourceEdgeTopologyKey> *sourceHardFeatureEdges,
+    const SourceChartTransitionGraph *sourceTransitions) {
   if (mesh.vertices.size() != mesh.vertexProvenance.size() ||
       mesh.vertices.size() != mesh.vertexLineage.size()) {
     failure = "CompletionOwnershipIncompleteVertexLineage";
@@ -1359,10 +1360,19 @@ bool validate_completion_domain_ownership(
       patchSourceFaces.end());
   const std::set<int> sourceFaces(patchSourceFaces.begin(),
                                   patchSourceFaces.end());
-  const SourceChartTransitionGraph transitionGraph(
-      sourceFaceMatrix, sourceAuthority, sourceHardFeatureEdges != nullptr
-          ? *sourceHardFeatureEdges
-          : empty_hard_feature_edges());
+  const std::set<authority::SourceEdgeTopologyKey> &hardFeatureEdges =
+      sourceHardFeatureEdges != nullptr ? *sourceHardFeatureEdges
+                                        : empty_hard_feature_edges();
+  const bool reuseGraph =
+      sourceTransitions != nullptr &&
+      sourceTransitions->borrows(sourceFaceMatrix, sourceAuthority,
+                                 hardFeatureEdges);
+  std::optional<SourceChartTransitionGraph> localGraph;
+  if (!reuseGraph) {
+    localGraph.emplace(sourceFaceMatrix, sourceAuthority, hardFeatureEdges);
+  }
+  const SourceChartTransitionGraph &transitionGraph =
+      reuseGraph ? *sourceTransitions : localGraph.value();
   const bool transitionAuthorityAvailable = transitionGraph.available();
   std::size_t sourceVertexExtent = 0U;
   if (sourceFaceMatrix != nullptr && sourceFaceMatrix->cols() == 3) {
@@ -2274,7 +2284,8 @@ PureQuadCompletionResult complete_pure_quad_patch(
   if (!pure_quad_detail::validate_completion_domain_ownership(
           patch, mesh, options.completionVariant, sourceSupportResolver,
           options.sourceFaces, options.sourceAuthority, ownershipFailure,
-          &result.ownershipRejection, options.sourceHardFeatureEdges)) {
+          &result.ownershipRejection, options.sourceHardFeatureEdges,
+          options.sourceTransitions)) {
     result.failureReason = PureQuadPatchRejectReason::TopologyValidationFailed;
     result.failure = ownershipFailure;
     return close_pure_quad_completion(std::move(result));
diff --git a/tests/PureQuadCompletionPhase18Tests.cpp b/tests/PureQuadCompletionPhase18Tests.cpp
index 5ea9866e4..fd11e5c38 100644
--- a/tests/PureQuadCompletionPhase18Tests.cpp
+++ b/tests/PureQuadCompletionPhase18Tests.cpp
@@ -1288,6 +1288,64 @@ TEST(PureQuadCompletionPhase18,
   EXPECT_EQ(nullptr, completion.rejection());
 }
 
+TEST(PureQuadCompletionPhase18,
+     PatchOwnershipReusesOnlyASharedGraphBorrowingItsExactInputs) {
+  const CompletionFixture fixture = source_support_alias_patch();
+  const auto sourceAuthority =
+      test_source_authority(fixture.faces, {0, 0}, {0, 1});
+  const auto &hard = no_hard_feature_edges();
+  const std::set<directional::authority::SourceEdgeTopologyKey> diagonal{
+      directional::authority::SourceEdgeTopologyKey::from_indices(0, 2, 4U)
+          .value()};
+  directional::geometry::PureQuadCompletionOptions options;
+  options.sourcePatch = 28;
+  options.sourceVertices = &fixture.vertices;
+  options.sourceFaces = &fixture.faces;
+  options.sourceAuthority = &sourceAuthority;
+  options.sourceHardFeatureEdges = &hard;
+  const auto local = directional::geometry::complete_pure_quad_patch(
+      fixture.patch, options);
+  ASSERT_TRUE(local.is_produced());
+
+  const directional::geometry::SourceChartTransitionGraph borrowed(
+      &fixture.faces, &sourceAuthority, hard);
+  const directional::geometry::SourceChartTransitionGraph splitByDiagonal(
+      &fixture.faces, &sourceAuthority, diagonal);
+  ASSERT_TRUE(borrowed.borrows(&fixture.faces, &sourceAuthority, hard));
+  ASSERT_FALSE(splitByDiagonal.borrows(&fixture.faces, &sourceAuthority, hard));
+  for (const auto *graph : {&borrowed, &splitByDiagonal}) {
+    options.sourceTransitions = graph;
+    const auto shared = directional::geometry::complete_pure_quad_patch(
+        fixture.patch, options);
+    ASSERT_TRUE(shared.is_produced())
+        << (shared.rejection() != nullptr ? shared.rejection()->detail : "");
+    ASSERT_EQ(local.product().vertexLineage.size(),
+              shared.product().vertexLineage.size());
+    for (std::size_t row = 0; row < local.product().vertexLineage.size();
+         ++row) {
+      EXPECT_EQ(local.product().vertexProvenance[row].face,
+                shared.product().vertexProvenance[row].face);
+      EXPECT_EQ(local.product().vertexLineage[row].sourceCharts,
+                shared.product().vertexLineage[row].sourceCharts);
+      EXPECT_EQ(local.product().vertexLineage[row].sourceSupport,
+                shared.product().vertexLineage[row].sourceSupport);
+    }
+  }
+
+  // The ignored graph is discriminating: with the diagonal really hard, the
+  // vertex alias cannot rebind to the patch face, shared graph or not.
+  options.sourceHardFeatureEdges = &diagonal;
+  options.sourceTransitions = nullptr;
+  const auto splitLocal = directional::geometry::complete_pure_quad_patch(
+      fixture.patch, options);
+  options.sourceTransitions = &splitByDiagonal;
+  const auto splitShared = directional::geometry::complete_pure_quad_patch(
+      fixture.patch, options);
+  ASSERT_TRUE(splitLocal.is_rejected());
+  ASSERT_TRUE(splitShared.is_rejected());
+  EXPECT_EQ(splitLocal.rejection()->detail, splitShared.rejection()->detail);
+}
+
 TEST(PureQuadCompletionPhase18,
      CompletionRejectsFaceInteriorOutsidePatchSupport) {
   CompletionFixture fixture = source_support_alias_patch();
```

## Review closeout

| Duty | Answer |
|---|---|
| Accepted selector prefix re-hashed | n/a: no selector change. The TB68 manifest is TB67's 871 rows byte for byte plus rows 872–873; `SELF_CHECK_PASS cases=873 deferred=81` with harness P8 `78b8002c…` |
| Decisive claims independently re-derived | HEAD stack sample; probe modes 1 and 2; production build of the exact patches (Vase, gate, ledger); mutants M1/M2; CB71-only syntax check; patch chain applied to `fa06ae4ff` with every result SHA-256 reproduced; embedded blocks re-hashed |
| Non-vacuity checked | Row 872 fails under M1 and row 873 under M2. Row 873's split graph is shown to be discriminating, because with the diagonal really hard the alias rejects. Row 872 requires at least one closed row |
| Prior obligations discharged/carried | F1–F7 ruled. P13-f is attributed and routed (CB71/CB72/TB68), and P13-g is new. O18 is recorded discharged (TB66). Carried: P13-e, O6, O9, O16, O17, O19, O20 (new), DR1/DR3, DR2/DR4, O2b, O15b, O7 (the oracle target still does not compile; seen in the probe build) |
| Stable accounting | 66/17/49, debt 1; CP2 491/491; selector497 unpromoted |
| New candidates/obligations recorded | P13-g (Vase quad embedding) → `M6-CP3-DEFN-P13-COMPLETION-QUAD-EMBEDDING`; O20 residual per-call O(F) |
| ORIENTATION currency line | Updated to RA-195 / CB71 next |
| ORIENTATION §3 / §4 / §7 / §8 | §3 boundary row, §7 Immediate and priority 1, §8 pattern updated. §4: n/a, no executed gate or witness change |
| CHANGELOG | Entry added |
| ROADMAP | Now line and CP3 boundary updated |
| Selector manifest | n/a |
| LESSONS | New lesson: for a cost defect, measure the cost and remove it in a probe before writing the plan |
| Consolidation under CLEAN_UP_POLICY | The decision and its CB71 plan stay as history, each with a superseded note pointing here |
| Successor frozen | CB71 (RA-195.4, exact RA-195.8) → CB72 (RA-195.5, exact RA-195.9) → TB68 (RA-195.6) |
| Turn boundary held | No product, test, fixture or selector change in the repository; probes ran in scratch only |
| `review_check.py boundary` | ALL CHECKS PASSED on the full-history checkout; `ledgers --base fa06ae4ff` PASSED |
| `STATUS` lifecycle maintained | COMPLETE, Successor CB71 |
| Pushed to origin, branch in sync | Yes, fast-forward, no force |
