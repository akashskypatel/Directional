# RA-185 — DIAG-RETAIN: materialization display adapter and text dump (2026-10-31)

**Turn:** `M6-DEFN-DIAG-RETAIN-CLI-GUI` (DEFN, Review track), run locally. It continues the user-directed DIAG-RETAIN item after CB58/TB57 landed the A5–A7 snapshots ([RA-184](Architecture_M6_DEFN_Diag_Retain_A5_A7_Snapshots_20261031.md)).
- **Method:** probes are diagnostic only. Source is CB58 `58ddfef0…`, unchanged in `src/`, `include/`, `tests/`, `CMakeLists.txt` and `cmake/` at HEAD. A Sonnet subagent traced the CLI, GUI, CMake and multi-component consumers (read-only); the Review agent designed the change, probed it and ruled.

## RA-185.1 Findings

- **CLI.** `--surface-cell-preserve-debug-artifacts` sets `preserveDebugArtifacts` and `retainIntermediateGeometry` (`src/cli/RemeshCommand.cpp:174–176`), but the CLI never reads `surfaceCellContext`. Its only file output beyond the mesh is the `--diagnostics-prefix` sidecar writer `write_remesh_diagnostics` (`src/cli/RemeshOutput.cpp:371`), whose inputs are mesh arrays and `RemeshDiagnostics`.
- **GUI.** `run_surface_cell_diagnostics` (`src/gui/GuiRemesh.cpp:~75–95`) converts snapshots through polyscope-free adapters in `src/visualization/` (compiled into `directional_pipeline`, `CMakeLists.txt:255–272`) and stores each result as an optional on `SurfaceCellDiagnosticsData` (`src/gui/GuiBackend.h:131–142`); `src/gui/Main.cpp` draws them. The adapters' tests are in `directional_compiled_api_tests` (`cmake/DirectionalTests.cmake:59–67`), a gate binary.
- **Build.** The CI flag set builds neither the CLI nor the GUI (`DIRECTIONAL_BUILD_CLI=OFF`, `DIRECTIONAL_BUILD_GUI=OFF`). Only adapter code in `directional_pipeline` is compiled and gate-tested.
- **DR2.** The multi-component aggregate (`RemeshPipeline.cpp:~17900–19400`) copies only `sourceTopologyRegions`, `authoritativeRails` and `completedPatches` into its snapshots. `traceNetwork`, `fieldAlignedCurveNetwork`, `surfaceCutGraph`, `globalTopologyPlan` and the three CB58 fields are all dropped, and a failed aggregate resets the whole context (`:17838`, `:18007`).

## RA-185.2 Rulings

- **CB59: one polyscope-free adapter in `directional_pipeline`** (`include/directional/visualization/MaterializationDiagnosticsDisplay.h`, `src/visualization/MaterializationDiagnosticsDisplay.cpp`).
  - `materialization_diagnostics_display(snapshots)` returns Eigen arrays: A5 occurrence points, directed cell sides and owned relations (as occurrence rows), the A6 class ordinal of each occurrence (−1 if none), and A7 vertex positions with quads as vertex rows. A product that was not retained leaves its fields empty and its `has…` flag false.
  - `write_materialization_diagnostics(out, snapshots)` writes a line-oriented text dump: a header line with counts per product (or `absent`), then one line per occurrence and relation, class and geometry vertex. Occurrences are written `cell:corner`.
  - Both take the snapshots by const reference, so they cannot feed back into any stage. No pipeline code calls them.
- **CLI and GUI wiring: deferred to a follow-up DEFN** (`M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING`), because neither target builds under the gate's flags. That DEFN freezes a CLI sidecar (for example `<prefix>.materialization.txt` written by the CB59 dump under `--diagnostics-prefix` when the snapshots are present) and the GUI layers, each with a CLI-ON or GUI-ON compile check.
- **DR2: carried, re-owned to M8-CP2** (diagnostics hardening). The drop is pre-existing and shared by every stage snapshot, so merging per-component products is a snapshot-contract change, not a DIAG-RETAIN slice. The adapter and dump already treat the products as optional, so a multi-component run reports them `absent`.
- **DR1 and DR3 unchanged** (RA-184.4).

## RA-185.3 Probe evidence

Builds are local CB58 source plus the CB59 patch, default arithmetic, incremental in the CB58 build tree.

- **New `MaterializationDiagnosticsDisplay.RetainedPlaneProductsBecomeConsistentDisplayGeometry` passes.** On the plane stopped after tracing (the CB58 fixture), all three products are present and non-empty. Every occurrence point equals its product's position. Every side joins two corners of its own cell, and every occurrence is in exactly one A6 class. Each A7 quad corner maps to the vertex of the same class. The dump has one header per product and one line per element.
- **New `MaterializationDiagnosticsDisplay.UnretainedProductsLeaveEmptyFieldsAndAreReportedAbsent` passes.** With retention off, all fields are empty, all flags are false and the dump is exactly the three `absent` lines.
- **Failing-first evidence is compile-level:** both tests use the new API.
- **No regressions:** `directional_compiled_api_tests` gives 25/25 (23 existing + 2 new). The change is additive: one new translation unit referenced only by the new test file, plus one list entry each in `CMakeLists.txt` and `cmake/DirectionalTests.cmake`. No existing source line changes, so the other four binaries are unaffected at source level. A full-gate probe was **not** run; TB58 runs the full gate.
- **Membership** of the five probe binaries is **945** = the TB58 manifest (863) plus ledger v4 (82), exactly.

## RA-185.4 CB59 — exact patch

**Turn:** `M6-CB59-DIAG-RETAIN-MATERIALIZATION-DISPLAY` (CB), run locally; Code + Build.
- **Scope:**
  - `CMakeLists.txt`: `1 0`.
  - `cmake/DirectionalTests.cmake`: `1 0`.
  - `include/directional/visualization/MaterializationDiagnosticsDisplay.h` (new): `65 0`.
  - `src/visualization/MaterializationDiagnosticsDisplay.cpp` (new): `167 0`.
  - `tests/MaterializationDiagnosticsDisplayTests.cpp` (new): `188 0`.
- **Checks:**
  - The RA-185.7 block, extracted verbatim with a trailing newline, has SHA-256 `78108421ae9e3ccff4cd537e0eb882f75d87d3caf3e6c04259e750dd9485023d`.
  - `git apply --check`, then apply; the numstat must be exactly as above.
  - The resulting SHA-256 must be:
    - `CMakeLists.txt` `7b3eadf6b73a30510dff503c45c2f1b46954c70cc0dc0f6eec8bc98b09c311ab`;
    - `cmake/DirectionalTests.cmake` `50c9f93861add728d4617b062d84e42a4188df9d3e787e648583e84afb12dd80`;
    - header `430e8650291b46478b7912b70712d4534804399c39aba40b63ae6c2fe9757da4`;
    - source `6c2a6f784b5a5c8793a64875caee44df74015beb67098d4313214ee9f7821920`;
    - tests `db2a2fa04dce70eeedabed02c416c0981f129dc2abf001830092aea842b0ee2b`.
  - Build the eight targets at default arithmetic and stage the package. No native tests.

| CB59 result | Successor |
|---|---|
| All exact, package built | `M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-EXEC` |
| Mismatch | `M6-PLAN-DIAG-RETAIN-DISPLAY-STOP` (PLAN, R) |
| Infrastructure failure | `M6-CB59A-DIAG-RETAIN-DISPLAY-ORCH`, then one retry |

## RA-185.5 TB58 frozen inputs

- **Gate:** [`Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv`](Architecture_M6_TB58_Diag_Retain_Display_Full_Gate_Case_Manifest.tsv), 863 rows, SHA-256 `31c1360ab5738cab682e628304914af4a3f7ad4dd077a8f688e79536bf371341`.
  - The first 862 lines are TB57 (`f898c9b6…`).
  - Rows 862 (`ra185:materialization-display-retained`) and 863 (`ra185:materialization-display-absent`) are GUARD rows in `directional_compiled_api_tests`.
- **Ledger:** v4 is unchanged (82, `36241caa…`).
- **Checks run:** `--self-check` gives `SELF_CHECK_PASS cases=863 deferred=82`. The real membership check of the patched binaries gives **945**.

| TB58 result (local) | Successor |
|---|---|
| 862/863 PASS, with row 283 (O16) the only RED, postflight true, membership 945 | `M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING` (no separate REV) |
| Any other non-PASS | `M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-REV` (R) |
| Membership error | `M6-PLAN-DIAG-RETAIN-DISPLAY-MEMBERSHIP-STOP` (PLAN, R) |

## RA-185.6 Turn sequence

| Step | Turn | Type / track | Exit |
|---|---|---|---|
| NEXT | `M6-CB59-DIAG-RETAIN-MATERIALIZATION-DISPLAY` → `M6-TB58-DIAG-RETAIN-DISPLAY-FULL-GATE-EXEC` | CB, TB-EXEC / local | 862/863, with only 283 red |
| then | `M6-DEFN-DIAG-RETAIN-CLI-GUI-WIRING` (CLI sidecar and GUI layers over the CB59 adapter, each with a CLI-ON or GUI-ON compile check) | DEFN / R | frozen wiring CBs |
| then | P13 probe DEFN (Cylinder first; O6; exact-atlas, route-step (O9) and continuation-width (O15c) checks) → FIXTURE / PRODUCT / OPEN slices → CP3-REV | per slice | CP3 exit |
| carried | DR1, DR3 (RA-184.4); DR2 → M8-CP2; O2b, O15b, O15c, O16; Linux CI confirmation of rows 854–859 | — | — |

## RA-185.7 Exact CB59 patch

~~~diff
diff --git a/CMakeLists.txt b/CMakeLists.txt
index c4f65b42c..3548d7b84 100644
--- a/CMakeLists.txt
+++ b/CMakeLists.txt
@@ -267,6 +267,7 @@ add_library(
   src/visualization/CutGraphDisplay.cpp
   src/visualization/FieldAlignedNetworkPolylines.cpp
   src/visualization/FieldStreamlines.cpp
+  src/visualization/MaterializationDiagnosticsDisplay.cpp
   src/visualization/SourceRegionDisplay.cpp
   src/visualization/SurfaceCellTracingDisplay.cpp
   src/visualization/TargetSizeDisplay.cpp)
diff --git a/cmake/DirectionalTests.cmake b/cmake/DirectionalTests.cmake
index 262e271b0..cdf060880 100644
--- a/cmake/DirectionalTests.cmake
+++ b/cmake/DirectionalTests.cmake
@@ -62,6 +62,7 @@ add_executable(
   tests/CutGraphDisplayTests.cpp
   tests/FieldAlignedNetworkPolylinesTests.cpp
   tests/FieldStreamlinesTests.cpp
+  tests/MaterializationDiagnosticsDisplayTests.cpp
   tests/SourceRegionDisplayTests.cpp
   tests/SurfaceCellTracingDisplayTests.cpp
   tests/TargetSizeDisplayTests.cpp)
diff --git a/include/directional/visualization/MaterializationDiagnosticsDisplay.h b/include/directional/visualization/MaterializationDiagnosticsDisplay.h
new file mode 100644
index 000000000..ccc0bece1
--- /dev/null
+++ b/include/directional/visualization/MaterializationDiagnosticsDisplay.h
@@ -0,0 +1,65 @@
+// This file is part of Directional, a library for directional field processing.
+// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
+//
+// This Source Code Form is subject to the terms of the Mozilla Public License
+// v. 2.0. If a copy of the MPL was not distributed with this file, You can
+// obtain one at http://mozilla.org/MPL/2.0/.
+
+#pragma once
+
+#ifndef DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H
+#define DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H
+
+#include <directional/pipeline/RemeshPipeline.h>
+
+#include <Eigen/Core>
+
+#include <iosfwd>
+
+namespace directional::visualization {
+
+/**
+ * Display geometry for the retained A5-A7 materialization snapshots.
+ *
+ * Diagnostic only: positions are the products' double approximations. Nothing
+ * here is semantic authority, and no pipeline stage reads it. A product that
+ * was not retained leaves its fields empty.
+ */
+struct MaterializationDiagnosticsDisplay {
+  /// A5 corner occurrences, O x 3, in occurrence-complex order.
+  Eigen::MatrixXd occurrencePoints;
+  /// A5 directed cell sides as rows of occurrencePoints, 4C x 2.
+  Eigen::MatrixXi occurrenceSides;
+  /// A5 owned relations as rows of occurrencePoints, R x 2.
+  Eigen::MatrixXi occurrenceRelations;
+  /// A6 quotient-class ordinal of each occurrence, size O; -1 when the
+  /// occurrence is in no class or no A6 product was retained.
+  Eigen::VectorXi occurrenceClass;
+  /// A7 vertex geometry, Q x 3, in A7 order.
+  Eigen::MatrixXd geometryPoints;
+  /// A7 cells as rows of geometryPoints, C x 4.
+  Eigen::MatrixXi geometryQuads;
+
+  bool hasOccurrenceComplex = false;
+  bool hasQuotientProduct = false;
+  bool hasSourceAttachedGeometry = false;
+};
+
+/// Converts the retained snapshots into display geometry.
+MaterializationDiagnosticsDisplay materialization_diagnostics_display(
+    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots);
+
+/**
+ * Writes a line-oriented text dump of the retained snapshots.
+ *
+ * Each product gets one header line with its counts, or `absent` when it was
+ * not retained, followed by one line per occurrence and relation (A5), class
+ * (A6) and geometry vertex (A7). Occurrences are written `cell:corner`.
+ */
+void write_materialization_diagnostics(
+    std::ostream &out,
+    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots);
+
+} // namespace directional::visualization
+
+#endif // DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H
diff --git a/src/visualization/MaterializationDiagnosticsDisplay.cpp b/src/visualization/MaterializationDiagnosticsDisplay.cpp
new file mode 100644
index 000000000..9660ee97f
--- /dev/null
+++ b/src/visualization/MaterializationDiagnosticsDisplay.cpp
@@ -0,0 +1,167 @@
+// This file is part of Directional, a library for directional field processing.
+// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
+//
+// This Source Code Form is subject to the terms of the Mozilla Public License
+// v. 2.0. If a copy of the MPL was not distributed with this file, You can
+// obtain one at http://mozilla.org/MPL/2.0/.
+
+#include <directional/visualization/MaterializationDiagnosticsDisplay.h>
+
+#include <iomanip>
+#include <map>
+#include <ostream>
+
+namespace directional::visualization {
+namespace {
+
+using OccurrenceRows = std::map<authority::OccurrenceId, int>;
+
+OccurrenceRows
+occurrence_rows(const pipeline::SurfaceOccurrenceComplex &complex) {
+  OccurrenceRows rows;
+  for (std::size_t row = 0; row < complex.occurrences().size(); ++row) {
+    rows.emplace(complex.occurrences()[row].id, static_cast<int>(row));
+  }
+  return rows;
+}
+
+std::ostream &write_occurrence(std::ostream &out,
+                               const authority::OccurrenceId &occurrence) {
+  return out << occurrence.cell().index() << ':'
+             << static_cast<int>(occurrence.canonical_corner_role());
+}
+
+std::ostream &write_position(std::ostream &out, const double x, const double y,
+                             const double z) {
+  return out << x << ' ' << y << ' ' << z;
+}
+
+} // namespace
+
+MaterializationDiagnosticsDisplay materialization_diagnostics_display(
+    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots) {
+  MaterializationDiagnosticsDisplay display;
+  OccurrenceRows rows;
+  if (const auto &complex = snapshots.occurrenceComplex) {
+    display.hasOccurrenceComplex = true;
+    rows = occurrence_rows(*complex);
+    const auto &occurrences = complex->occurrences();
+    display.occurrencePoints.resize(
+        static_cast<Eigen::Index>(occurrences.size()), 3);
+    for (std::size_t row = 0; row < occurrences.size(); ++row) {
+      display.occurrencePoints.row(static_cast<Eigen::Index>(row)) =
+          occurrences[row].point.position.transpose();
+    }
+    const auto &cells = complex->cells();
+    display.occurrenceSides.resize(static_cast<Eigen::Index>(4 * cells.size()),
+                                   2);
+    for (std::size_t cell = 0; cell < cells.size(); ++cell) {
+      for (std::size_t side = 0; side < 4; ++side) {
+        const auto &[from, to] = cells[cell].directedSides[side];
+        const auto edge = static_cast<Eigen::Index>(4 * cell + side);
+        display.occurrenceSides(edge, 0) = rows.at(from);
+        display.occurrenceSides(edge, 1) = rows.at(to);
+      }
+    }
+    const auto &relations = complex->owned_relations();
+    display.occurrenceRelations.resize(
+        static_cast<Eigen::Index>(relations.size()), 2);
+    for (std::size_t relation = 0; relation < relations.size(); ++relation) {
+      const auto row = static_cast<Eigen::Index>(relation);
+      display.occurrenceRelations(row, 0) =
+          rows.at(relations[relation].firstOccurrence);
+      display.occurrenceRelations(row, 1) =
+          rows.at(relations[relation].secondOccurrence);
+    }
+    display.occurrenceClass = Eigen::VectorXi::Constant(
+        static_cast<Eigen::Index>(occurrences.size()), -1);
+  }
+  if (const auto &quotient = snapshots.quotientProduct) {
+    display.hasQuotientProduct = true;
+    if (display.hasOccurrenceComplex) {
+      const auto &classes = quotient->classes();
+      for (std::size_t ordinal = 0; ordinal < classes.size(); ++ordinal) {
+        for (const auto &member : classes[ordinal].members) {
+          display.occurrenceClass(rows.at(member)) = static_cast<int>(ordinal);
+        }
+      }
+    }
+  }
+  if (const auto &geometry = snapshots.sourceAttachedGeometry) {
+    display.hasSourceAttachedGeometry = true;
+    const auto &vertices = geometry->vertices();
+    std::map<pipeline::SurfaceQuotientClassId, int> vertexRows;
+    display.geometryPoints.resize(static_cast<Eigen::Index>(vertices.size()),
+                                  3);
+    for (std::size_t row = 0; row < vertices.size(); ++row) {
+      vertexRows.emplace(vertices[row].quotientClass, static_cast<int>(row));
+      display.geometryPoints.row(static_cast<Eigen::Index>(row)) =
+          vertices[row].position;
+    }
+    const auto &cells = geometry->topology();
+    display.geometryQuads.resize(static_cast<Eigen::Index>(cells.size()), 4);
+    for (std::size_t cell = 0; cell < cells.size(); ++cell) {
+      for (std::size_t corner = 0; corner < 4; ++corner) {
+        display.geometryQuads(static_cast<Eigen::Index>(cell),
+                              static_cast<Eigen::Index>(corner)) =
+            vertexRows.at(cells[cell].corners[corner]);
+      }
+    }
+  }
+  return display;
+}
+
+void write_materialization_diagnostics(
+    std::ostream &out,
+    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots) {
+  const auto precision = out.precision(17);
+  if (const auto &complex = snapshots.occurrenceComplex) {
+    out << "A5 occurrence-complex cells=" << complex->cells().size()
+        << " occurrences=" << complex->occurrences().size()
+        << " relations=" << complex->owned_relations().size() << '\n';
+    for (const auto &occurrence : complex->occurrences()) {
+      write_occurrence(out << "occurrence ", occurrence.id)
+          << " face=" << occurrence.point.face << " position=";
+      write_position(out, occurrence.point.position.x(),
+                     occurrence.point.position.y(),
+                     occurrence.point.position.z())
+          << '\n';
+    }
+    for (const auto &relation : complex->owned_relations()) {
+      write_occurrence(out << "relation ", relation.firstOccurrence) << ' ';
+      write_occurrence(out, relation.secondOccurrence) << '\n';
+    }
+  } else {
+    out << "A5 occurrence-complex absent\n";
+  }
+  if (const auto &quotient = snapshots.quotientProduct) {
+    out << "A6 quotient-product classes=" << quotient->classes().size()
+        << " classed-cells=" << quotient->classed_cells().size() << '\n';
+    for (std::size_t ordinal = 0; ordinal < quotient->classes().size();
+         ++ordinal) {
+      out << "class " << ordinal << " members";
+      for (const auto &member : quotient->classes()[ordinal].members) {
+        write_occurrence(out << ' ', member);
+      }
+      out << '\n';
+    }
+  } else {
+    out << "A6 quotient-product absent\n";
+  }
+  if (const auto &geometry = snapshots.sourceAttachedGeometry) {
+    out << "A7 source-attached-geometry vertices="
+        << geometry->vertices().size()
+        << " cells=" << geometry->topology().size() << '\n';
+    for (const auto &vertex : geometry->vertices()) {
+      write_occurrence(out << "vertex ", vertex.representative) << " position=";
+      write_position(out, vertex.position.x(), vertex.position.y(),
+                     vertex.position.z())
+          << '\n';
+    }
+  } else {
+    out << "A7 source-attached-geometry absent\n";
+  }
+  out.precision(precision);
+}
+
+} // namespace directional::visualization
diff --git a/tests/MaterializationDiagnosticsDisplayTests.cpp b/tests/MaterializationDiagnosticsDisplayTests.cpp
new file mode 100644
index 000000000..5a6a18654
--- /dev/null
+++ b/tests/MaterializationDiagnosticsDisplayTests.cpp
@@ -0,0 +1,188 @@
+#include <directional/core/TriMesh.h>
+#include <directional/io/ReadOBJ.h>
+#include <directional/pipeline/RemeshPipeline.h>
+#include <directional/visualization/MaterializationDiagnosticsDisplay.h>
+
+#include "TestFixturePaths.h"
+
+#include <gtest/gtest.h>
+
+#include <filesystem>
+#include <fstream>
+#include <sstream>
+#include <stdexcept>
+#include <string>
+
+namespace {
+
+Eigen::MatrixXd read_rawfield(const std::filesystem::path &path,
+                              const int expectedFaces) {
+  std::ifstream stream(path);
+  int degree = 0;
+  int faceCount = 0;
+  if (!stream || !(stream >> degree >> faceCount) || degree != 4 ||
+      faceCount != expectedFaces) {
+    throw std::runtime_error("Invalid rawfield fixture: " + path.string());
+  }
+  Eigen::MatrixXd raw(faceCount, 3 * degree);
+  for (int face = 0; face < faceCount; ++face) {
+    for (int column = 0; column < 3 * degree; ++column) {
+      stream >> raw(face, column);
+    }
+  }
+  if (!stream) {
+    throw std::runtime_error("Truncated rawfield fixture: " + path.string());
+  }
+  return raw;
+}
+
+// The plane stopped after tracing, as in the CB58 retention test: A5-A7 all
+// complete, and the injected failure keeps the run on the diagnostic path.
+directional::pipeline::RemeshResult plane_materialization(const bool retain) {
+  directional::TriMesh mesh;
+  if (!directional::readOBJ(
+          directional::tests::benchmark_fixture_path("milestone-g/plane.obj")
+              .string(),
+          mesh)) {
+    throw std::runtime_error("Cannot read the plane fixture");
+  }
+  const Eigen::MatrixXd raw = read_rawfield(
+      directional::tests::benchmark_fixture_path("milestone-g/plane.rawfield"),
+      static_cast<int>(mesh.F.rows()));
+  directional::pipeline::RemeshOptions options;
+  options.lengthRatio = 0.2;
+  options.integralSeamless = false;
+  options.roundSeams = false;
+  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
+  options.surfaceCells.enabled = true;
+  options.surfaceCells.fallbackPolicy =
+      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
+  options.surfaceCells.allowSourceGridRecovery = false;
+  options.surfaceCells.retainIntermediateGeometry = retain;
+  options.surfaceCells.injectFailureAfterStage = 3;
+  return directional::pipeline::remesh_from_raw_cross_field(mesh.V, mesh.F, raw,
+                                                            options);
+}
+
+std::size_t count_prefix(const std::string &text, const std::string &prefix) {
+  std::istringstream lines(text);
+  std::size_t count = 0;
+  for (std::string line; std::getline(lines, line);) {
+    if (line.rfind(prefix, 0) == 0) {
+      ++count;
+    }
+  }
+  return count;
+}
+
+} // namespace
+
+TEST(MaterializationDiagnosticsDisplay,
+     RetainedPlaneProductsBecomeConsistentDisplayGeometry) {
+  const auto result = plane_materialization(true);
+  const auto &snapshots = result.surfaceCellContext.productSnapshots;
+  ASSERT_NE(nullptr, snapshots.occurrenceComplex);
+  ASSERT_NE(nullptr, snapshots.quotientProduct);
+  ASSERT_NE(nullptr, snapshots.sourceAttachedGeometry);
+  const auto &complex = *snapshots.occurrenceComplex;
+  const auto &quotient = *snapshots.quotientProduct;
+  const auto &geometry = *snapshots.sourceAttachedGeometry;
+
+  const auto display =
+      directional::visualization::materialization_diagnostics_display(
+          snapshots);
+  EXPECT_TRUE(display.hasOccurrenceComplex);
+  EXPECT_TRUE(display.hasQuotientProduct);
+  EXPECT_TRUE(display.hasSourceAttachedGeometry);
+
+  const auto occurrences =
+      static_cast<Eigen::Index>(complex.occurrences().size());
+  ASSERT_GT(occurrences, 0);
+  ASSERT_EQ(occurrences, display.occurrencePoints.rows());
+  ASSERT_EQ(4 * static_cast<Eigen::Index>(complex.cells().size()),
+            display.occurrenceSides.rows());
+  ASSERT_EQ(static_cast<Eigen::Index>(complex.owned_relations().size()),
+            display.occurrenceRelations.rows());
+  ASSERT_EQ(occurrences, display.occurrenceClass.size());
+  for (Eigen::Index row = 0; row < occurrences; ++row) {
+    EXPECT_EQ(
+        complex.occurrences()[static_cast<std::size_t>(row)].point.position,
+        display.occurrencePoints.row(row).transpose());
+  }
+  // A side joins two corners of its own cell.
+  for (Eigen::Index edge = 0; edge < display.occurrenceSides.rows(); ++edge) {
+    const auto &cell = complex.cells()[static_cast<std::size_t>(edge / 4)];
+    for (int end = 0; end < 2; ++end) {
+      const auto &occurrence = complex.occurrences()[static_cast<std::size_t>(
+          display.occurrenceSides(edge, end))];
+      EXPECT_EQ(cell.id, occurrence.id.cell());
+    }
+  }
+  // Every occurrence is in exactly the class that lists it.
+  std::size_t classedMembers = 0;
+  for (std::size_t ordinal = 0; ordinal < quotient.classes().size();
+       ++ordinal) {
+    classedMembers += quotient.classes()[ordinal].members.size();
+  }
+  EXPECT_EQ(static_cast<std::size_t>(occurrences), classedMembers);
+  EXPECT_GE(display.occurrenceClass.minCoeff(), 0);
+  EXPECT_LT(display.occurrenceClass.maxCoeff(),
+            static_cast<int>(quotient.classes().size()));
+
+  ASSERT_EQ(static_cast<Eigen::Index>(geometry.vertices().size()),
+            display.geometryPoints.rows());
+  ASSERT_EQ(static_cast<Eigen::Index>(geometry.topology().size()),
+            display.geometryQuads.rows());
+  for (Eigen::Index cell = 0; cell < display.geometryQuads.rows(); ++cell) {
+    for (Eigen::Index corner = 0; corner < 4; ++corner) {
+      const auto row = display.geometryQuads(cell, corner);
+      EXPECT_EQ(
+          geometry.topology()[static_cast<std::size_t>(cell)]
+              .corners[static_cast<std::size_t>(corner)],
+          geometry.vertices()[static_cast<std::size_t>(row)].quotientClass);
+    }
+  }
+
+  std::ostringstream dump;
+  directional::visualization::write_materialization_diagnostics(dump,
+                                                                snapshots);
+  const std::string text = dump.str();
+  EXPECT_EQ(1U, count_prefix(text, "A5 occurrence-complex cells="));
+  EXPECT_EQ(complex.occurrences().size(), count_prefix(text, "occurrence "));
+  EXPECT_EQ(complex.owned_relations().size(), count_prefix(text, "relation "));
+  EXPECT_EQ(1U, count_prefix(text, "A6 quotient-product classes="));
+  EXPECT_EQ(quotient.classes().size(), count_prefix(text, "class "));
+  EXPECT_EQ(1U, count_prefix(text, "A7 source-attached-geometry vertices="));
+  EXPECT_EQ(geometry.vertices().size(), count_prefix(text, "vertex "));
+  EXPECT_EQ(0U, count_prefix(text, "A5 occurrence-complex absent"));
+}
+
+TEST(MaterializationDiagnosticsDisplay,
+     UnretainedProductsLeaveEmptyFieldsAndAreReportedAbsent) {
+  const auto result = plane_materialization(false);
+  const auto &snapshots = result.surfaceCellContext.productSnapshots;
+  ASSERT_EQ(nullptr, snapshots.occurrenceComplex);
+  ASSERT_EQ(nullptr, snapshots.quotientProduct);
+  ASSERT_EQ(nullptr, snapshots.sourceAttachedGeometry);
+
+  const auto display =
+      directional::visualization::materialization_diagnostics_display(
+          snapshots);
+  EXPECT_FALSE(display.hasOccurrenceComplex);
+  EXPECT_FALSE(display.hasQuotientProduct);
+  EXPECT_FALSE(display.hasSourceAttachedGeometry);
+  EXPECT_EQ(0, display.occurrencePoints.rows());
+  EXPECT_EQ(0, display.occurrenceSides.rows());
+  EXPECT_EQ(0, display.occurrenceRelations.rows());
+  EXPECT_EQ(0, display.occurrenceClass.size());
+  EXPECT_EQ(0, display.geometryPoints.rows());
+  EXPECT_EQ(0, display.geometryQuads.rows());
+
+  std::ostringstream dump;
+  directional::visualization::write_materialization_diagnostics(dump,
+                                                                snapshots);
+  EXPECT_EQ("A5 occurrence-complex absent\n"
+            "A6 quotient-product absent\n"
+            "A7 source-attached-geometry absent\n",
+            dump.str());
+}
~~~
