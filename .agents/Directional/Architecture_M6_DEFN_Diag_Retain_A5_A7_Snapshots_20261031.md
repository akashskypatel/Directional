# RA-184 — DIAG-RETAIN: A5–A7 diagnostic snapshots (2026-10-31)

**Turn:** `M6-DEFN-DIAG-RETAIN-A5-A7` (DEFN, Review track), run locally. This is the user-directed DIAG-RETAIN item (TODO, 2026-10-21).
- **Method:** probes are diagnostic only. Source is CB57 `fb4f637b…`, unchanged in `src/`, `include/` and `tests/` at HEAD. A Sonnet subagent traced the snapshot contract and the A5–A7 producers (read-only); the Review agent designed the change, probed it and ruled.

## RA-184.1 Findings

- **A5, A6 and A7 run inside one helper**, `build_authoritative_phase_front_mesh_with_hard_features` (`src/pipeline/RemeshPipeline.cpp:9222–9405`), and the tracing stage calls it once (`:13341`).
  - The products are locals: A5 `SurfaceOccurrenceComplex`, A6 `SurfaceQuotientProduct`, A7 `SourceAttachedGeometryProduct`, then verification.
  - The helper returns only `AuthoritativePhaseFrontMeshResult` (mesh, counts, a failure string). On success it overwrites that result with `project_verified_surface_products(...)`.
  - A rejection at any stage returns early. **Today no A5–A7 product survives the helper.**
- **The snapshot contract** (`include/directional/pipeline/RemeshPipeline.h:300–344`) documents one-way copies that are never read back. It has no A5–A7 fields. No test mutates a snapshot to prove there is no read-back; the existing retention test compares runs with retention on and off (`SurfaceCellTransitionQuotientTests.cpp:9765`).
- **Consumers today:**
  - the GUI reads `sourceTopologyRegions`, `fieldAlignedCurveNetwork`, `surfaceCutGraph`, `globalTopologyPlan` and `traceNetwork` (`src/gui/GuiRemesh.cpp:75–101`);
  - the CLI sets retention for `--surface-cell-preserve-debug-artifacts` (`src/cli/RemeshCommand.cpp:176`) but reads no snapshots.
- **No memory cap exists**; only ownership accounting.
- **The public materializer's exact signature is pinned** (`SurfaceCellsPhase10Tests.cpp:10175`: `decltype(&build_authoritative_phase_front_mesh) == Materializer`). It is an authority contract: the materializer consumes only V, F and the published phase front.

## RA-184.2 Design (CB58)

- **Snapshot fields.** `SurfaceCellDiagnosticProductSnapshots` gains three members, each a `std::shared_ptr<const T>` (immutable, so it cannot be used as a mutable authority; a forward declaration is enough):
  - `occurrenceComplex` (A5: corner occurrences with support, placement and wedge bindings, plus relations with kind, endpoints and evidence);
  - `quotientProduct` (A6: merged quotient classes);
  - `sourceAttachedGeometry` (A7: final vertex geometry).
- **Copy points.**
  - The helper takes an optional `AuthoritativePhaseFrontDiagnostics *`. It copies each product **immediately after that stage succeeds and before the next stage runs**, so a later rejection keeps every product completed before it.
  - `build_authoritative_phase_front_mesh` keeps its pinned signature and passes `nullptr`. A separately named `build_authoritative_phase_front_mesh_with_diagnostics` exposes the copies.
- **Retention.**
  - The tracing stage passes the diagnostics only under `retainForExecution`, and moves the copies into the snapshots on both success and failure.
  - `clear_unrequested_intermediate_context` drops them when retention was not requested, as for `traceNetwork`.
- **No read-back.** Downstream code uses the helper's own locals and result. The snapshots are copies and nothing reads them. The tests require retained and released runs to give the same outcome.
- **Memory bound.**
  - At most one copy of each product per materialization, linear in the output: about 4 occurrences per cell plus relations, about one class per output vertex, and one geometry vertex per class.
  - The copies exist only while retention is on, and are released with the other unrequested intermediates.

## RA-184.3 Probe evidence

Builds are local CB57 source plus the CB58 patch, default arithmetic.

- **New `SurfaceCellTransitionQuotient.MaterializationProductsAreRetainedIfAndOnlyIfRequested`** passes. On the plane, stopped after tracing, all three snapshots are present when requested and absent otherwise; the failure code and stage are identical; cell and class counts are consistent.
- **New `SurfaceCellAuthorityContractCutover.MaterializationDiagnosticsAreCopiesAndStopAtTheFailingStage`** passes.
  - On success, the mesh is identical with and without diagnostics. Occurrence cells = classed cells = output quads, and classes = geometry vertices.
  - On the strict hard-rail transport negative (rejected **by A5**), the failure is unchanged and nothing is retained.
- **Failing-first evidence is compile-level:** both tests use the new API.
- **No regressions:** the signature pin stays green, and the existing retention test passes. The full gate (861) gives 860/861 (only 283); all 859 TB56 rows are unchanged; the 82 deferred rows have identical verdicts and first-failure sites.

## RA-184.4 Open items

- **DR1 (witness gap).** No current fixture gives a phase front that A5 accepts and A6, A7 or verification rejects; existing A6 negatives tamper A5 records and call A6 directly. So "products completed before a later in-helper rejection are kept" holds by construction and is witnessed only for a rejection after materialization (the injected failure). **Owner:** add the assertion when such a stimulus exists (for example from P13 fixtures).
- **DR2.** The multi-component aggregation path (`RemeshPipeline.cpp:17866–19365`) does not merge these snapshots. **Owner:** the CLI/GUI DEFN decides whether per-component products are exposed.
- **DR3 (pre-existing, unchanged).** Most existing snapshot fields are written even when retention is off; only four are cleared. Noted, not changed here.

## RA-184.5 CB58 — exact patch

**Turn:** `M6-CB58-DIAG-RETAIN-A5-A7-SNAPSHOTS` (CB), run locally; Code + Build.
- **Scope:**
  - `include/directional/pipeline/RemeshPipeline.h`: `27 0`.
  - `src/pipeline/RemeshPipeline.cpp`: `39 3`.
  - `tests/SurfaceCellTransitionQuotientTests.cpp`: `47 0`.
  - `tests/SurfaceCellsPhase10Tests.cpp`: `50 0`.
- **Checks:**
  - The RA-184.7 block, extracted verbatim with a trailing newline, has SHA-256 `c72e47cc54c407af5921bf80aaeec043bd3add928b24046dfc879f56e9041b0e`.
  - `git apply --check`, then apply; the numstat must be exactly as above.
  - The resulting SHA-256 must be:
    - header `37f85237555d843ce71934825197cb3e599cb007aba6529e8b1a97ea275b1a4d`;
    - source `47d77eb7ec4d7356f43890669b7b9158929b236695249956be2ddd8e264c410c`;
    - Phase10 `913b97e7a3731aff9899f108cb81d9499517f55071a87376355ddd8e6da27bac`;
    - TQ `358dabaddacf61798c6f6e5cf5d723c2367bca56d9e1e192f2165b61abe4b191`.
  - Build the eight targets at default arithmetic and stage the package. No native tests.

| CB58 result | Successor |
|---|---|
| All exact, package built | `M6-TB57-DIAG-RETAIN-FULL-GATE-EXEC` |
| Mismatch | `M6-PLAN-DIAG-RETAIN-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CB58A-DIAG-RETAIN-ORCH`, then one retry |

## RA-184.6 TB57 frozen inputs

- **Gate:** [`Architecture_M6_CP3_TB57_Diag_Retain_Full_Gate_Case_Manifest.tsv`](Architecture_M6_CP3_TB57_Diag_Retain_Full_Gate_Case_Manifest.tsv), 861 rows, SHA-256 `f898c9b67c6f6f2c7ffa5bfaf054cb82dc8b691db0f74f0d28e3bee5ceab2b32`.
  - The first 860 lines are TB56 (`c8437d61…`).
  - Rows 860 (`ra184:diag-retain-helper-copies`) and 861 (`ra184:diag-retain-iff-requested`) are GUARD rows in the producer binary.
- **Ledger:** v4 is unchanged (82).
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=861 deferred=82`. The real membership check of the patched binaries gives **943**.

| TB57 result (local) | Successor |
|---|---|
| 860/861 PASS, with row 283 (O16) the only RED, postflight true, membership 943 | `M6-DEFN-DIAG-RETAIN-CLI-GUI` (no separate REV) |
| Any other non-PASS | `M6-TB57-DIAG-RETAIN-FULL-GATE-REV` (R) |
| Membership error | `M6-PLAN-DIAG-RETAIN-MEMBERSHIP-STOP` (PLAN, R) |

## RA-184.7 Exact CB58 patch

~~~diff
diff --git a/include/directional/pipeline/RemeshPipeline.h b/include/directional/pipeline/RemeshPipeline.h
index a42489260..d7852d79e 100644
--- a/include/directional/pipeline/RemeshPipeline.h
+++ b/include/directional/pipeline/RemeshPipeline.h
@@ -22,6 +22,7 @@
 #include <iostream>
 #include <limits>
 #include <map>
+#include <memory>
 #include <numeric>
 #include <optional>
 #include <set>
@@ -289,6 +290,10 @@ struct RemeshOptions {
   std::function<void(const MesherData &)> mesherDataCallback;
 };
 
+class SurfaceOccurrenceComplex;
+class SurfaceQuotientProduct;
+class SourceAttachedGeometryProduct;
+
 struct SurfaceCellContextProductDebug {
   std::string name;
   std::string type;
@@ -341,6 +346,13 @@ struct SurfaceCellDiagnosticProductSnapshots {
   bool hasOptimizationResult = false;
   geometry::SurfaceFinalValidationReport validationResult;
   bool hasValidationResult = false;
+
+  // A5-A7 products of the phase-front materialization, including those
+  // completed before a later stage rejected. Retained only when intermediate
+  // geometry is retained; immutable copies, never read back.
+  std::shared_ptr<const SurfaceOccurrenceComplex> occurrenceComplex;
+  std::shared_ptr<const SurfaceQuotientProduct> quotientProduct;
+  std::shared_ptr<const SourceAttachedGeometryProduct> sourceAttachedGeometry;
 };
 
 /**
@@ -1560,6 +1572,13 @@ struct AuthoritativePhaseFrontMeshResult {
   std::optional<VerificationReport> verificationReport;
 };
 
+/// Diagnostic copies of each A5-A7 product as soon as it is produced.
+struct AuthoritativePhaseFrontDiagnostics {
+  std::shared_ptr<const SurfaceOccurrenceComplex> occurrenceComplex;
+  std::shared_ptr<const SurfaceQuotientProduct> quotientProduct;
+  std::shared_ptr<const SourceAttachedGeometryProduct> sourceAttachedGeometry;
+};
+
 std::string verification_failure_message(const VerificationReport &report);
 
 class SurfaceProductVerifier;
@@ -1634,6 +1653,14 @@ AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh(
     const Eigen::MatrixXi &sourceFaces,
     const geometry::SurfacePhaseFrontProduct &phaseFront);
 
+/// The same materialization, also copying each A5-A7 product into
+/// `diagnostics` as soon as it is produced (one-way observation only).
+AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh_with_diagnostics(
+    const Eigen::MatrixXd &sourceVertices,
+    const Eigen::MatrixXi &sourceFaces,
+    const geometry::SurfacePhaseFrontProduct &phaseFront,
+    AuthoritativePhaseFrontDiagnostics &diagnostics);
+
 using RemeshPipelineClock = std::chrono::steady_clock;
 
 double remesh_elapsed_seconds(
diff --git a/src/pipeline/RemeshPipeline.cpp b/src/pipeline/RemeshPipeline.cpp
index 1ec7a0474..5421e8e39 100644
--- a/src/pipeline/RemeshPipeline.cpp
+++ b/src/pipeline/RemeshPipeline.cpp
@@ -9224,7 +9224,8 @@ build_authoritative_phase_front_mesh_with_hard_features(
     const Eigen::MatrixXd &sourceVertices,
     const Eigen::MatrixXi &sourceFaces,
     const geometry::SurfacePhaseFrontProduct &phaseFront,
-    const std::set<authority::SourceEdgeTopologyKey> *hardFeatureRailEdges) {
+    const std::set<authority::SourceEdgeTopologyKey> *hardFeatureRailEdges,
+    AuthoritativePhaseFrontDiagnostics *diagnostics) {
   AuthoritativePhaseFrontMeshResult result;
 
   result.mesh.sourcePatch = 0;
@@ -9260,6 +9261,10 @@ build_authoritative_phase_front_mesh_with_hard_features(
     }
     return result;
   }
+  if (diagnostics != nullptr) {
+    diagnostics->occurrenceComplex =
+        std::make_shared<const SurfaceOccurrenceComplex>(*occurrenceComplex);
+  }
 
   auto quotientConstruction =
       hardFeatureRailEdges == nullptr
@@ -9313,6 +9318,10 @@ build_authoritative_phase_front_mesh_with_hard_features(
     }
     return result;
   }
+  if (diagnostics != nullptr) {
+    diagnostics->quotientProduct =
+        std::make_shared<const SurfaceQuotientProduct>(*quotientProduct);
+  }
 
   auto geometryConstruction = SourceAttachedGeometryProducer::produce(
       sourceVertices, sourceFaces, *occurrenceComplex, *quotientProduct);
@@ -9357,6 +9366,10 @@ build_authoritative_phase_front_mesh_with_hard_features(
     }
     return result;
   }
+  if (diagnostics != nullptr) {
+    diagnostics->sourceAttachedGeometry =
+        std::make_shared<const SourceAttachedGeometryProduct>(*geometryProduct);
+  }
 
   static const std::set<authority::SourceEdgeTopologyKey> kNoHardFeatureEdges;
   const auto &verificationHardFeatureEdges =
@@ -9409,7 +9422,16 @@ AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh(
     const Eigen::MatrixXi &sourceFaces,
     const geometry::SurfacePhaseFrontProduct &phaseFront) {
   return build_authoritative_phase_front_mesh_with_hard_features(
-      sourceVertices, sourceFaces, phaseFront, nullptr);
+      sourceVertices, sourceFaces, phaseFront, nullptr, nullptr);
+}
+
+AuthoritativePhaseFrontMeshResult build_authoritative_phase_front_mesh_with_diagnostics(
+    const Eigen::MatrixXd &sourceVertices,
+    const Eigen::MatrixXi &sourceFaces,
+    const geometry::SurfacePhaseFrontProduct &phaseFront,
+    AuthoritativePhaseFrontDiagnostics &diagnostics) {
+  return build_authoritative_phase_front_mesh_with_hard_features(
+      sourceVertices, sourceFaces, phaseFront, nullptr, &diagnostics);
 }
 
 } // namespace directional::pipeline
@@ -12380,6 +12402,9 @@ remesh_from_raw_cross_field_impl_with_stage_products(
       result.surfaceCellContext.hasEmbeddedArrangementArcs = false;
       result.surfaceCellContext.productSnapshots.arrangement = geometry::SurfaceCellComplex{};
       result.surfaceCellContext.hasArrangement = false;
+      result.surfaceCellContext.productSnapshots.occurrenceComplex.reset();
+      result.surfaceCellContext.productSnapshots.quotientProduct.reset();
+      result.surfaceCellContext.productSnapshots.sourceAttachedGeometry.reset();
 
       result.surfaceCellContext.tracingCurrentOwnedBytes = 0U;
       result.surfaceCellContext.flowRepCurrentOwnedBytes = 0U;
@@ -13337,10 +13362,21 @@ remesh_from_raw_cross_field_impl_with_stage_products(
     const bool useAuthoritativePhaseFront = phaseFrontProduct != nullptr;
     AuthoritativePhaseFrontMeshResult authoritativePhaseFrontMesh;
     if (useAuthoritativePhaseFront) {
+      AuthoritativePhaseFrontDiagnostics materializationDiagnostics;
       authoritativePhaseFrontMesh =
           build_authoritative_phase_front_mesh_with_hard_features(
               meshWhole.V, meshWhole.F, *phaseFrontProduct,
-              &hardFeatureRailEdges);
+              &hardFeatureRailEdges,
+              retainForExecution ? &materializationDiagnostics : nullptr);
+      if (retainForExecution) {
+        auto &snapshots = result.surfaceCellContext.productSnapshots;
+        snapshots.occurrenceComplex =
+            std::move(materializationDiagnostics.occurrenceComplex);
+        snapshots.quotientProduct =
+            std::move(materializationDiagnostics.quotientProduct);
+        snapshots.sourceAttachedGeometry =
+            std::move(materializationDiagnostics.sourceAttachedGeometry);
+      }
       if (!authoritativePhaseFrontMesh.success) {
         result.diagnostics.surfaceCellFirstInvalidProducerStage =
             "tracing/phase-front-materialization";
diff --git a/tests/SurfaceCellTransitionQuotientTests.cpp b/tests/SurfaceCellTransitionQuotientTests.cpp
index 219b20eb9..d6518abea 100644
--- a/tests/SurfaceCellTransitionQuotientTests.cpp
+++ b/tests/SurfaceCellTransitionQuotientTests.cpp
@@ -9805,6 +9805,53 @@ TEST(SurfaceCellTransitionQuotient,
             released.surfaceCellContext.productSnapshots.traceNetwork.phaseFront.produced_product());
 }
 
+// DIAG-RETAIN (RA-184): the A5-A7 materialization products are retained as
+// one-way snapshots iff intermediate geometry is requested, without changing
+// the outcome.
+TEST(SurfaceCellTransitionQuotient,
+     MaterializationProductsAreRetainedIfAndOnlyIfRequested) {
+  const auto meshPath = directional::tests::benchmark_fixture_path(
+      "milestone-g/plane.obj");
+  const auto fieldPath = directional::tests::benchmark_fixture_path(
+      "milestone-g/plane.rawfield");
+  directional::TriMesh mesh;
+  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
+  const Eigen::MatrixXd raw = read_rawfield(fieldPath, mesh.F.rows());
+  const auto run = [&](const bool retain) {
+    directional::pipeline::RemeshOptions options;
+    options.lengthRatio = 0.2;
+    options.integralSeamless = false;
+    options.roundSeams = false;
+    options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
+    options.surfaceCells.enabled = true;
+    options.surfaceCells.fallbackPolicy =
+        directional::pipeline::SurfaceCellFallbackPolicy::Fail;
+    options.surfaceCells.allowSourceGridRecovery = false;
+    options.surfaceCells.retainIntermediateGeometry = retain;
+    options.surfaceCells.injectFailureAfterStage = 3;
+    return directional::pipeline::remesh_from_raw_cross_field(
+        mesh.V, mesh.F, raw, options);
+  };
+  const auto retained = run(true);
+  const auto released = run(false);
+  EXPECT_EQ(retained.diagnostics.terminalFailureCode,
+            released.diagnostics.terminalFailureCode);
+  EXPECT_EQ(retained.diagnostics.terminalFailureStage,
+            released.diagnostics.terminalFailureStage);
+  const auto &kept = retained.surfaceCellContext.productSnapshots;
+  const auto &dropped = released.surfaceCellContext.productSnapshots;
+  ASSERT_NE(nullptr, kept.occurrenceComplex);
+  ASSERT_NE(nullptr, kept.quotientProduct);
+  ASSERT_NE(nullptr, kept.sourceAttachedGeometry);
+  EXPECT_EQ(kept.occurrenceComplex->cells().size(),
+            kept.quotientProduct->classed_cells().size());
+  EXPECT_EQ(kept.quotientProduct->classes().size(),
+            kept.sourceAttachedGeometry->vertices().size());
+  EXPECT_EQ(nullptr, dropped.occurrenceComplex);
+  EXPECT_EQ(nullptr, dropped.quotientProduct);
+  EXPECT_EQ(nullptr, dropped.sourceAttachedGeometry);
+}
+
 TEST(SurfaceCellTransitionQuotient,
      SemanticDigestIsInvariantToVertexFaceAndComponentRowPermutation) {
   const auto baseline = semantic_two_component_result();
diff --git a/tests/SurfaceCellsPhase10Tests.cpp b/tests/SurfaceCellsPhase10Tests.cpp
index e30db35fa..0694b23e7 100644
--- a/tests/SurfaceCellsPhase10Tests.cpp
+++ b/tests/SurfaceCellsPhase10Tests.cpp
@@ -9084,6 +9084,56 @@ TEST(SurfaceCellAuthorityContractCutover,
   EXPECT_EQ("InvalidHardRailTransport", rejected.failure);
 }
 
+// DIAG-RETAIN (RA-184): each A5-A7 product is copied as soon as it is
+// produced, the copies never change the materialization result, and a stage
+// that rejects leaves no copy of its own or any later product.
+TEST(SurfaceCellAuthorityContractCutover,
+     MaterializationDiagnosticsAreCopiesAndStopAtTheFailingStage) {
+  const auto fixture = build_rectangular_hard_rail_phase_front();
+  ASSERT_EQ(directional::geometry::SurfaceCellProducerDisposition::Produced,
+            fixture.network.phaseFront.disposition())
+      << hard_rail_first_failure_detail(fixture.network);
+  const auto &product = fixture.network.phaseFront.product();
+
+  directional::pipeline::AuthoritativePhaseFrontDiagnostics accepted;
+  const auto materialized =
+      directional::pipeline::build_authoritative_phase_front_mesh_with_diagnostics(
+          fixture.mesh.V, fixture.mesh.F, product, accepted);
+  const auto plain = directional::pipeline::build_authoritative_phase_front_mesh(
+      fixture.mesh.V, fixture.mesh.F, product);
+  ASSERT_TRUE(materialized.success) << materialized.failure;
+  EXPECT_EQ(plain.mesh.quads, materialized.mesh.quads);
+  EXPECT_TRUE(plain.mesh.vertexPositions == materialized.mesh.vertexPositions);
+  ASSERT_NE(nullptr, accepted.occurrenceComplex);
+  ASSERT_NE(nullptr, accepted.quotientProduct);
+  ASSERT_NE(nullptr, accepted.sourceAttachedGeometry);
+  EXPECT_EQ(materialized.mesh.quads.size(), accepted.occurrenceComplex->cells().size());
+  EXPECT_EQ(materialized.mesh.quads.size(), accepted.quotientProduct->classed_cells().size());
+  EXPECT_EQ(accepted.quotientProduct->classes().size(),
+            accepted.sourceAttachedGeometry->vertices().size());
+
+  // The strict hard-rail transport negative is rejected by A5 itself.
+  const auto pairs = hard_rail_phase_front_pairs(product);
+  ASSERT_FALSE(pairs.empty());
+  auto edges = product.edges();
+  auto &first = edges[static_cast<std::size_t>(pairs.front().first)];
+  auto &second = edges[static_cast<std::size_t>(pairs.front().second)];
+  second.route = first.route;
+  const auto tampered = rebuild_phase_front_with_edges(product, std::move(edges), fixture);
+  directional::pipeline::AuthoritativePhaseFrontDiagnostics rejectedDiagnostics;
+  const auto rejected =
+      directional::pipeline::build_authoritative_phase_front_mesh_with_diagnostics(
+          fixture.mesh.V, fixture.mesh.F, tampered, rejectedDiagnostics);
+  const auto plainRejected = directional::pipeline::build_authoritative_phase_front_mesh(
+      fixture.mesh.V, fixture.mesh.F, tampered);
+  EXPECT_FALSE(rejected.success);
+  EXPECT_EQ("InvalidHardRailTransport", rejected.failure);
+  EXPECT_EQ(plainRejected.failure, rejected.failure);
+  EXPECT_EQ(nullptr, rejectedDiagnostics.occurrenceComplex);
+  EXPECT_EQ(nullptr, rejectedDiagnostics.quotientProduct);
+  EXPECT_EQ(nullptr, rejectedDiagnostics.sourceAttachedGeometry);
+}
+
 TEST(SurfaceCellAuthorityContractCutover,
      HardRailPairChangedRouteContentRejectsStrictTransport) {
   const auto fixture = build_rectangular_hard_rail_phase_front();
~~~
