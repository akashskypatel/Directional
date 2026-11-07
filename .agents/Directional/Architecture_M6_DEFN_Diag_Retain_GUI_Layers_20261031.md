# RA-187 — DIAG-RETAIN: GUI layers; full-gate correction for the CLI slice (2026-10-31)

**Turn:** `M6-DEFN-DIAG-RETAIN-GUI-LAYERS` (DEFN, Review track), run locally. It adds GUI layers over the CB59 adapter ([RA-185](Architecture_M6_DEFN_Diag_Retain_Materialization_Display_20261031.md)) and corrects how the CLI slice ([RA-186](Architecture_M6_DEFN_Diag_Retain_CLI_Materialization_Sidecar_20261031.md)) was tested.
- **Method:** probes are diagnostic only. Source is CB60 `a31f2d39…`, unchanged in `src/`, `include/`, `tests/`, `CMakeLists.txt` and `cmake/` at HEAD. The probe is a GUI-ON reconfigure of the probe build tree (CB59 source plus the CB60 and CB61 patches). The Review agent designed, probed and ruled.

## RA-187.1 Findings

- **GUI data path.** `run_surface_cell_diagnostics` (`src/gui/GuiRemesh.cpp`) already runs with `retainIntermediateGeometry = true` and, for the quick view, `injectFailureAfterStage = 3`, so A5–A7 are retained whenever tracing completes. Each product becomes an optional field of `SurfaceCellDiagnosticsData` (`src/gui/GuiBackend.h`), drawn by `visualize_surface_cell_diagnostics` (`src/gui/Main.cpp`), which also owns layer removal and transform sync.
- **No GUI tests exist**, and polyscope needs a display, so the only automatable GUI check is a clean compile and link. The data the layers draw is already gate-tested through the CB59 adapter (rows 862–863).
- **Cadence correction.** `Turn_Cadence.md` §2 requires every TB to execute the full current gate. TB59 ran only the three CLI cases, because the CB60 package held only the CLI. That was a deviation: the CLI slice has no full-gate TB. CB60 changed only `src/cli/`, which none of the gate binaries compile, so no gate verdict can have changed, but the cadence still requires the run.

## RA-187.2 Rulings

- **CB61: the GUI layers** (`src/gui/GuiBackend.h` `5 0`, `GuiRemesh.cpp` `5 0`, `Main.cpp` `52 8`).
  - `SurfaceCellDiagnosticsData` gains `std::optional<MaterializationDiagnosticsDisplay> materialization`, filled whenever any of the three snapshots is present.
  - Three layers: `A5 occurrence cell sides` (curve network), `A5 corner occurrences` (point cloud with the categorical `A6 quotient class` quantity when A6 was retained) and `A7 source-attached geometry` (quad surface mesh, off by default). They are removed and transform-synced with the other SurfaceCells layers. Relations are left out of the GUI because related occurrences coincide; the dump keeps them.
  - The layers only read the display arrays. No pipeline option, admission or ordering changes.
- **CB61 builds everything once, and TB60 runs the full gate plus the CLI cases.** One fresh configure with the CI flags plus `-DDIRECTIONAL_BUILD_CLI=ON -DDIRECTIONAL_BUILD_GUI=ON` builds the eight gate targets, `directional_cli` and `directional_gui`. It stages two packages from that tree:
  - `pkg.zip`, the standard eight-target package, for the gate;
  - `tools.zip`, holding `bin/directional` and `bin/directional-ui`, with the same metadata layout.

  TB60 runs the 863-row TB58 gate on `pkg.zip` and the three RA-186.3 CLI cases on `tools.zip`, and checks that `directional-ui` links against the same GMP. This gives both the CLI slice and the GUI slice a full-gate TB.
- **Manual check.** The layers' appearance needs a person at the GUI. It is not an agent gate; the user can open a SurfaceCells diagnostics run and toggle the three layers.

## RA-187.3 Probe evidence

- GUI-ON reconfigure and `directional_gui` build of the probe tree: configure 0, build 0 (the first GUI-ON build took about a minute); with the CB61 patch, the incremental rebuild compiles and links `directional-ui` with no errors and no new warnings in the three files.
- The CLI-ON probe and the TB59 runs (RA-186.3, TB59) are unchanged by CB61, which touches only `src/gui/`.
- No full-gate probe: CB61 changes no gate binary source. TB60 runs the full gate.

## RA-187.4 CB61 — exact patch

**Turn:** `M6-CB61-DIAG-RETAIN-GUI-LAYERS` (CB), run locally; Code + Build.
- **Checks:**
  - The RA-187.7 block, extracted verbatim with a trailing newline, has SHA-256 `afab7d5dc08ec1976b0ef36b22c34757b295f6b010753edf2b26fa7565983e4e`.
  - `git apply --check`, then apply; the numstat must be exactly `5 0` (`src/gui/GuiBackend.h`), `5 0` (`src/gui/GuiRemesh.cpp`) and `52 8` (`src/gui/Main.cpp`).
  - The resulting SHA-256 must be `6cc1c79ad345788abf234153e86d5b38bf0926e96dfc1de18bfbfdf462423a48` (`GuiBackend.h`), `8a4ed4a95205b6c30b1d27a882da94e80218e0bf8885b2f2625f806422becbd9` (`GuiRemesh.cpp`) and `c601f6e717f3e36ef46d6c5d3018724788dc7231e0cccb530b0ef9e739b851c5` (`Main.cpp`).
- **Build:** a fresh configure of a clean worktree with the CI flags plus `-DDIRECTIONAL_BUILD_CLI=ON -DDIRECTIONAL_BUILD_GUI=ON`, at default arithmetic. Build the eight gate targets, `directional_cli` and `directional_gui`. Stage `build/local-evidence/CB61/pkg.zip` (the standard eight-target layout) and `build/local-evidence/CB61/tools.zip` (`bin/directional`, `bin/directional-ui`, the same metadata files with `compiled-targets.txt` = `directional_cli` and `directional_gui`). No native runs.

| CB61 result | Successor |
|---|---|
| All exact, both packages built | `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC` |
| Mismatch | `M6-PLAN-DIAG-RETAIN-GUI-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CB61A-DIAG-RETAIN-GUI-ORCH`, then one retry |

## RA-187.5 TB60 frozen inputs

- **Gate:** the TB58 manifest [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv) unchanged (863 rows, `31c1360a…`); ledger v4 (82, `36241caa…`); membership 945.
- **CLI cases:** the three RA-186.3 runs with the TB59 check script (`build/local-evidence/TB59/tb59_check.sh`, `16137c4e…`) against `tools.zip`'s `bin/directional`.
- **GUI link check:** `otool -L bin/directional-ui` lists the same Homebrew GMP libraries as `pkg.zip`'s `gmp-evidence.txt`.

| TB60 result (local) | Successor |
|---|---|
| Gate 862/863 with row 283 (O16) the only RED, postflight true, membership 945; CLI checks 11/11; GUI link check true | P13 probe DEFN (DIAG-RETAIN closed; no separate REV) |
| Any other non-PASS | `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-REV` (R) |
| Membership error | `M6-PLAN-DIAG-RETAIN-GUI-MEMBERSHIP-STOP` (PLAN, R) |

## RA-187.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CB61-DIAG-RETAIN-GUI-LAYERS` → `M6-TB60-DIAG-RETAIN-GUI-FULL-GATE-EXEC` | CB, TB-EXEC / local | 862/863 (only 283), CLI 11/11, GUI link true |
| then | P13 probe DEFN (Cylinder first; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | DR1, DR3 (RA-184.4); DR2, DR4 → M8-CP2; O2b, O15b, O15c, O16; Linux CI confirmation of rows 854–859 | — | — |

## RA-187.7 Exact CB61 patch

~~~diff
diff --git a/src/gui/GuiBackend.h b/src/gui/GuiBackend.h
index 18901faec..81a9d48e3 100644
--- a/src/gui/GuiBackend.h
+++ b/src/gui/GuiBackend.h
@@ -12,6 +12,7 @@
 #include <directional/fields/CompareCrossFields.h>
 #include <directional/visualization/CutGraphDisplay.h>
 #include <directional/visualization/FieldAlignedNetworkPolylines.h>
+#include <directional/visualization/MaterializationDiagnosticsDisplay.h>
 #include <directional/visualization/SourceRegionDisplay.h>
 #include <directional/visualization/SurfaceCellTracingDisplay.h>
 #include <directional/visualization/TargetSizeDisplay.h>
@@ -133,6 +134,10 @@ struct SurfaceCellDiagnosticsData {
   std::optional<visualization::FieldAlignedNetworkPolylines> network;
   /// The A2a' cut graph and A2b disc regions, when either was published.
   std::optional<visualization::CutGraphDisplay> cutGraph;
+  /// The A5-A7 occurrences, quotient classes and source-attached geometry,
+  /// when the run completed them.
+  std::optional<visualization::MaterializationDiagnosticsDisplay>
+      materialization;
   /// Where the run stopped and, when quad tracing produced them, its cells.
   visualization::SurfaceCellTracingDisplay tracing;
   bool pipelineProduced = false;
diff --git a/src/gui/GuiRemesh.cpp b/src/gui/GuiRemesh.cpp
index 1b4c85e8c..a6f7dd3a0 100644
--- a/src/gui/GuiRemesh.cpp
+++ b/src/gui/GuiRemesh.cpp
@@ -89,6 +89,11 @@ SurfaceCellDiagnosticsData run_surface_cell_diagnostics(
         snapshots.surfaceCutGraph ? &*snapshots.surfaceCutGraph : nullptr,
         snapshots.globalTopologyPlan ? &*snapshots.globalTopologyPlan : nullptr);
   }
+  if (snapshots.occurrenceComplex || snapshots.quotientProduct ||
+      snapshots.sourceAttachedGeometry) {
+    result.materialization =
+        visualization::materialization_diagnostics_display(snapshots);
+  }
   const auto &context = remesh.surfaceCellContext;
   result.tracing = visualization::surface_cell_tracing_display(
       mesh.vertices, mesh.faces, remesh.diagnostics,
diff --git a/src/gui/Main.cpp b/src/gui/Main.cpp
index 558069605..f41e138ed 100644
--- a/src/gui/Main.cpp
+++ b/src/gui/Main.cpp
@@ -57,6 +57,10 @@ constexpr const char *kStopEdgesName = "SurfaceCells stop edges";
 constexpr const char *kStopVerticesName = "SurfaceCells stop vertices";
 constexpr const char *kTracedCellsName = "A4 traced cells";
 constexpr const char *kTracedCornersName = "A4 cell corners";
+constexpr const char *kOccurrenceSidesName = "A5 occurrence cell sides";
+constexpr const char *kOccurrencesName = "A5 corner occurrences";
+constexpr const char *kQuotientClassQuantity = "A6 quotient class";
+constexpr const char *kGeometryQuadsName = "A7 source-attached geometry";
 constexpr const char *kCutEdgesName = "A2a' cut edges";
 constexpr const char *kGraphArcsName = "A2b graph arcs";
 constexpr const char *kFaceDiscRegionQuantity = "A2b disc region";
@@ -418,19 +422,22 @@ private:
   void remove_surface_cell_layers() {
     for (const char *name : {kNetworkTracesName, kNetworkMandatoryName,
                              kRegionSeamsName, kRegionBoundariesName,
-                             kStopEdgesName, kTracedCellsName}) {
+                             kStopEdgesName, kTracedCellsName,
+                             kOccurrenceSidesName}) {
       if (polyscope::hasCurveNetwork(name)) {
         polyscope::removeCurveNetwork(name);
       }
     }
     for (const char *name : {kNetworkSingularitiesName, kStopVerticesName,
-                             kTracedCornersName}) {
+                             kTracedCornersName, kOccurrencesName}) {
       if (polyscope::hasPointCloud(name)) {
         polyscope::removePointCloud(name);
       }
     }
-    if (polyscope::hasSurfaceMesh(kStopFacesName)) {
-      polyscope::removeSurfaceMesh(kStopFacesName);
+    for (const char *name : {kStopFacesName, kGeometryQuadsName}) {
+      if (polyscope::hasSurfaceMesh(name)) {
+        polyscope::removeSurfaceMesh(name);
+      }
     }
     if (polyscope::hasSurfaceMesh(kInputMeshName)) {
       auto *inputMesh = polyscope::getSurfaceMesh(kInputMeshName);
@@ -836,19 +843,22 @@ private:
                              kRegionSeamsName, kRegionBoundariesName,
                              kStreamlinesName, kStopEdgesName,
                              kTracedCellsName, kCutEdgesName,
-                             kGraphArcsName, kFeatureEdgesName}) {
+                             kGraphArcsName, kFeatureEdgesName,
+                             kOccurrenceSidesName}) {
       if (polyscope::hasCurveNetwork(name)) {
         sync(polyscope::getCurveNetwork(name));
       }
     }
     for (const char *name : {kNetworkSingularitiesName, kStopVerticesName,
-                             kTracedCornersName}) {
+                             kTracedCornersName, kOccurrencesName}) {
       if (polyscope::hasPointCloud(name)) {
         sync(polyscope::getPointCloud(name));
       }
     }
-    if (polyscope::hasSurfaceMesh(kStopFacesName)) {
-      sync(polyscope::getSurfaceMesh(kStopFacesName));
+    for (const char *name : {kStopFacesName, kGeometryQuadsName}) {
+      if (polyscope::hasSurfaceMesh(name)) {
+        sync(polyscope::getSurfaceMesh(name));
+      }
     }
   }
 
@@ -967,6 +977,37 @@ private:
     }
   }
 
+  void visualize_materialization(
+      const directional::visualization::MaterializationDiagnosticsDisplay
+          &products) {
+    if (products.occurrenceSides.rows() > 0) {
+      auto *sides = polyscope::registerCurveNetwork(
+          kOccurrenceSidesName, products.occurrencePoints,
+          products.occurrenceSides);
+      sides->setColor({0.85F, 0.45F, 0.10F});
+      sides->setRadius(0.0012F);
+    }
+    if (products.occurrencePoints.rows() > 0) {
+      auto *occurrences = polyscope::registerPointCloud(
+          kOccurrencesName, products.occurrencePoints);
+      occurrences->setPointRadius(0.003F);
+      // -1 marks an occurrence that no retained A6 class lists.
+      if (products.hasQuotientProduct) {
+        occurrences
+            ->addScalarQuantity(kQuotientClassQuantity,
+                                products.occurrenceClass,
+                                polyscope::DataType::CATEGORICAL)
+            ->setEnabled(true);
+      }
+    }
+    if (products.geometryQuads.rows() > 0) {
+      auto *geometry = polyscope::registerSurfaceMesh(
+          kGeometryQuadsName, products.geometryPoints, products.geometryQuads);
+      geometry->setEdgeWidth(1.0);
+      geometry->setEnabled(false);
+    }
+  }
+
   void apply_streamline_style() {
     if (!streamlines_.has_value() || !polyscope::hasCurveNetwork(kStreamlinesName)) {
       return;
@@ -1012,6 +1053,9 @@ private:
     if (surfaceCellDiagnostics_->network.has_value()) {
       visualize_field_network(*surfaceCellDiagnostics_->network);
     }
+    if (surfaceCellDiagnostics_->materialization.has_value()) {
+      visualize_materialization(*surfaceCellDiagnostics_->materialization);
+    }
     visualize_quad_tracing(surfaceCellDiagnostics_->tracing);
     sync_overlay_transforms();
   }
~~~
