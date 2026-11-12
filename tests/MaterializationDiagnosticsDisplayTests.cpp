#include <directional/core/TriMesh.h>
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/visualization/MaterializationDiagnosticsDisplay.h>

#include "TestFixturePaths.h"

#include <gtest/gtest.h>

#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace {

Eigen::MatrixXd read_rawfield(const std::filesystem::path &path,
                              const int expectedFaces) {
  std::ifstream stream(path);
  int degree = 0;
  int faceCount = 0;
  if (!stream || !(stream >> degree >> faceCount) || degree != 4 ||
      faceCount != expectedFaces) {
    throw std::runtime_error("Invalid rawfield fixture: " + path.string());
  }
  Eigen::MatrixXd raw(faceCount, 3 * degree);
  for (int face = 0; face < faceCount; ++face) {
    for (int column = 0; column < 3 * degree; ++column) {
      stream >> raw(face, column);
    }
  }
  if (!stream) {
    throw std::runtime_error("Truncated rawfield fixture: " + path.string());
  }
  return raw;
}

// The plane stopped after tracing, as in the CB58 retention test: A5-A7 all
// complete, and the injected failure keeps the run on the diagnostic path.
directional::pipeline::RemeshResult plane_materialization(const bool retain) {
  directional::TriMesh mesh;
  if (!directional::readOBJ(
          directional::tests::benchmark_fixture_path("milestone-g/plane.obj")
              .string(),
          mesh)) {
    throw std::runtime_error("Cannot read the plane fixture");
  }
  const Eigen::MatrixXd raw = read_rawfield(
      directional::tests::benchmark_fixture_path("milestone-g/plane.rawfield"),
      static_cast<int>(mesh.F.rows()));
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = retain;
  options.surfaceCells.injectFailureAfterStage = 3;
  return directional::pipeline::remesh_from_raw_cross_field(mesh.V, mesh.F, raw,
                                                            options);
}

std::size_t count_prefix(const std::string &text, const std::string &prefix) {
  std::istringstream lines(text);
  std::size_t count = 0;
  for (std::string line; std::getline(lines, line);) {
    if (line.rfind(prefix, 0) == 0) {
      ++count;
    }
  }
  return count;
}

} // namespace

TEST(MaterializationDiagnosticsDisplay,
     RetainedPlaneProductsBecomeConsistentDisplayGeometry) {
  const auto result = plane_materialization(true);
  const auto &snapshots = result.surfaceCellContext.productSnapshots;
  ASSERT_NE(nullptr, snapshots.occurrenceComplex);
  ASSERT_NE(nullptr, snapshots.quotientProduct);
  ASSERT_NE(nullptr, snapshots.sourceAttachedGeometry);
  const auto &complex = *snapshots.occurrenceComplex;
  const auto &quotient = *snapshots.quotientProduct;
  const auto &geometry = *snapshots.sourceAttachedGeometry;

  const auto display =
      directional::visualization::materialization_diagnostics_display(
          snapshots);
  EXPECT_TRUE(display.hasOccurrenceComplex);
  EXPECT_TRUE(display.hasQuotientProduct);
  EXPECT_TRUE(display.hasSourceAttachedGeometry);

  const auto occurrences =
      static_cast<Eigen::Index>(complex.occurrences().size());
  ASSERT_GT(occurrences, 0);
  ASSERT_EQ(occurrences, display.occurrencePoints.rows());
  ASSERT_EQ(4 * static_cast<Eigen::Index>(complex.cells().size()),
            display.occurrenceSides.rows());
  ASSERT_EQ(static_cast<Eigen::Index>(complex.owned_relations().size()),
            display.occurrenceRelations.rows());
  ASSERT_EQ(occurrences, display.occurrenceClass.size());
  for (Eigen::Index row = 0; row < occurrences; ++row) {
    EXPECT_EQ(
        complex.occurrences()[static_cast<std::size_t>(row)].point.position,
        display.occurrencePoints.row(row).transpose());
  }
  // A side joins two corners of its own cell.
  for (Eigen::Index edge = 0; edge < display.occurrenceSides.rows(); ++edge) {
    const auto &cell = complex.cells()[static_cast<std::size_t>(edge / 4)];
    for (int end = 0; end < 2; ++end) {
      const auto &occurrence = complex.occurrences()[static_cast<std::size_t>(
          display.occurrenceSides(edge, end))];
      EXPECT_EQ(cell.id, occurrence.id.cell());
    }
  }
  // Every occurrence is in exactly the class that lists it.
  std::size_t classedMembers = 0;
  for (std::size_t ordinal = 0; ordinal < quotient.classes().size();
       ++ordinal) {
    classedMembers += quotient.classes()[ordinal].members.size();
  }
  EXPECT_EQ(static_cast<std::size_t>(occurrences), classedMembers);
  EXPECT_GE(display.occurrenceClass.minCoeff(), 0);
  EXPECT_LT(display.occurrenceClass.maxCoeff(),
            static_cast<int>(quotient.classes().size()));

  ASSERT_EQ(static_cast<Eigen::Index>(geometry.vertices().size()),
            display.geometryPoints.rows());
  ASSERT_EQ(static_cast<Eigen::Index>(geometry.topology().size()),
            display.geometryQuads.rows());
  for (Eigen::Index cell = 0; cell < display.geometryQuads.rows(); ++cell) {
    for (Eigen::Index corner = 0; corner < 4; ++corner) {
      const auto row = display.geometryQuads(cell, corner);
      EXPECT_EQ(
          geometry.topology()[static_cast<std::size_t>(cell)]
              .corners[static_cast<std::size_t>(corner)],
          geometry.vertices()[static_cast<std::size_t>(row)].quotientClass);
    }
  }

  std::ostringstream dump;
  directional::visualization::write_materialization_diagnostics(dump,
                                                                snapshots);
  const std::string text = dump.str();
  EXPECT_EQ(1U, count_prefix(text, "A5 occurrence-complex cells="));
  EXPECT_EQ(complex.occurrences().size(), count_prefix(text, "occurrence "));
  EXPECT_EQ(complex.owned_relations().size(), count_prefix(text, "relation "));
  EXPECT_EQ(1U, count_prefix(text, "A6 quotient-product classes="));
  EXPECT_EQ(quotient.classes().size(), count_prefix(text, "class "));
  EXPECT_EQ(1U, count_prefix(text, "A7 source-attached-geometry vertices="));
  EXPECT_EQ(geometry.vertices().size(), count_prefix(text, "vertex "));
  EXPECT_EQ(0U, count_prefix(text, "A5 occurrence-complex absent"));
}

TEST(MaterializationDiagnosticsDisplay,
     UnretainedProductsLeaveEmptyFieldsAndAreReportedAbsent) {
  const auto result = plane_materialization(false);
  const auto &snapshots = result.surfaceCellContext.productSnapshots;
  ASSERT_EQ(nullptr, snapshots.occurrenceComplex);
  ASSERT_EQ(nullptr, snapshots.quotientProduct);
  ASSERT_EQ(nullptr, snapshots.sourceAttachedGeometry);

  const auto display =
      directional::visualization::materialization_diagnostics_display(
          snapshots);
  EXPECT_FALSE(display.hasOccurrenceComplex);
  EXPECT_FALSE(display.hasQuotientProduct);
  EXPECT_FALSE(display.hasSourceAttachedGeometry);
  EXPECT_EQ(0, display.occurrencePoints.rows());
  EXPECT_EQ(0, display.occurrenceSides.rows());
  EXPECT_EQ(0, display.occurrenceRelations.rows());
  EXPECT_EQ(0, display.occurrenceClass.size());
  EXPECT_EQ(0, display.geometryPoints.rows());
  EXPECT_EQ(0, display.geometryQuads.rows());

  std::ostringstream dump;
  directional::visualization::write_materialization_diagnostics(dump,
                                                                snapshots);
  EXPECT_EQ("A5 occurrence-complex absent\n"
            "A6 quotient-product absent\n"
            "A7 source-attached-geometry absent\n",
            dump.str());
}
