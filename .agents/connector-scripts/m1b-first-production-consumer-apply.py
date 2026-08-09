from pathlib import Path


def replace_once(path: str, old: str, new: str) -> None:
    p = Path(path)
    text = p.read_text()
    count = text.count(old)
    if count != 1:
        raise SystemExit(f"{path}: expected exactly one replacement match, found {count}")
    p.write_text(text.replace(old, new, 1))


replace_once(
    "CMakeLists.txt",
    "add_library(\n  directional_core\n  src/core/Library.cpp\n",
    "add_library(\n  directional_core\n  src/authority/AuthorityKernel.cpp\n  src/core/Library.cpp\n",
)

replace_once(
    "cmake/DirectionalTests.cmake",
    "add_executable(\n  directional_surface_cell_authority_kernel_tests\n  src/authority/AuthorityKernel.cpp\n  tests/SurfaceCellAuthorityKernelTests.cpp)\n",
    "add_executable(\n  directional_surface_cell_authority_kernel_tests\n  tests/SurfaceCellAuthorityKernelTests.cpp)\n",
)

replace_once(
    "include/directional/geometry/SurfaceOptimizationRailConstraints.h",
    "#include <Eigen/Dense>\n\n#include <directional/geometry/SurfaceCellTracing.h>\n",
    "#include <Eigen/Dense>\n\n#include <directional/authority/AuthorityIds.h>\n#include <directional/geometry/SurfaceCellTracing.h>\n",
)
replace_once(
    "include/directional/geometry/SurfaceOptimizationRailConstraints.h",
    "bool source_face_contains_vertex(const Eigen::MatrixXi &faces,\n                                        const int face,\n                                        const int vertex);\n",
    "bool source_face_contains_vertex(\n    const Eigen::MatrixXi &faces, authority::SourceFaceId face,\n    authority::SourceVertexId vertex);\n",
)

rail_cpp = r'''#include <directional/geometry/SurfaceOptimizationRailConstraints.h>

#include <directional/authority/LegacyAuthorityAdapters.h>

#include <limits>

namespace directional::geometry::surface_optimization_rail_detail {

namespace {

// M1b preserves the legacy consumer's source-vertex truth table: this seam
// previously rejected negative values but did not introduce a sourceVertices
// row-bound check. Use the complete nonnegative legacy-int domain as the
// compatibility extent; upstream topology validation remains authoritative.
constexpr std::size_t legacy_source_vertex_extent =
    static_cast<std::size_t>(std::numeric_limits<int>::max()) + 1U;

} // namespace

bool source_face_contains_vertex(
    const Eigen::MatrixXi &faces, authority::SourceFaceId face,
    authority::SourceVertexId vertex) {
  using authority::LegacyAuthorityAdapters;
  if (faces.cols() != 3 ||
      LegacyAuthorityAdapters::to_legacy_index(face) >=
          static_cast<std::size_t>(faces.rows())) {
    return false;
  }
  const auto matches = [&](const int corner) {
    return static_cast<std::int64_t>(faces(
               static_cast<Eigen::Index>(
                   LegacyAuthorityAdapters::to_legacy_index(face)),
               corner)) ==
           static_cast<std::int64_t>(
               LegacyAuthorityAdapters::to_legacy_index(vertex));
  };
  return matches(0) || matches(1) || matches(2);
}

} // namespace directional::geometry::surface_optimization_rail_detail

namespace directional::geometry::surface_optimization_rail_detail {

bool provenance_supports_interval_sheet(
    const SurfacePoint &provenance,
    const SurfaceFeatureCurveInterval &interval,
    const SurfaceOptimizationConstraints &constraints) {
  using authority::LegacyAuthorityAdapters;
  using authority::SourceFaceId;
  using authority::SourceVertexId;
  if (provenance.component >= 0 && interval.component >= 0 &&
      provenance.component != interval.component) {
    return false;
  }
  if (provenance.sheet < 0 || interval.sheet < 0 ||
      provenance.sheet == interval.sheet) {
    return true;
  }
  if (!provenance.valid() || provenance.face < 0 ||
      provenance.face >= constraints.sourceFaces.rows() ||
      interval.sourceFace < 0 ||
      interval.sourceFace >= constraints.sourceFaces.rows() ||
      constraints.sourceFaces.cols() != 3 ||
      !provenance.barycentric.allFinite()) {
    return false;
  }

  const std::size_t sourceFaceExtent =
      static_cast<std::size_t>(constraints.sourceFaces.rows());
  const auto provenanceFaceResult = LegacyAuthorityAdapters::source_face(
      provenance.face, sourceFaceExtent);
  const auto intervalFaceResult = LegacyAuthorityAdapters::source_face(
      interval.sourceFace, sourceFaceExtent);
  if (!provenanceFaceResult || !intervalFaceResult) {
    return false;
  }
  const SourceFaceId provenanceFace = provenanceFaceResult.value();
  const SourceFaceId intervalFace = intervalFaceResult.value();

  // A point on a source edge or vertex legitimately belongs to every
  // incident local sheet. Its stored provenance face is only one valid chart.
  // Accept a rail interval from another sheet only when both charts share the
  // exact source entity supporting the point; interior points remain confined
  // to their authoritative sheet.
  std::vector<SourceVertexId> supportVertices;
  for (int corner = 0; corner < 3; ++corner) {
    if (provenance.barycentric(corner) > 1.0e-8) {
      const int legacySourceVertex = constraints.sourceFaces(
          static_cast<Eigen::Index>(
              LegacyAuthorityAdapters::to_legacy_index(provenanceFace)),
          corner);
      if (legacySourceVertex < 0) {
        return false;
      }
      const auto sourceVertexResult = LegacyAuthorityAdapters::source_vertex(
          legacySourceVertex, legacy_source_vertex_extent);
      if (!sourceVertexResult) {
        return false;
      }
      supportVertices.push_back(sourceVertexResult.value());
    }
  }
  if (supportVertices.empty() || supportVertices.size() >= 3U) {
    return false;
  }
  for (const SourceVertexId sourceVertex : supportVertices) {
    if (!source_face_contains_vertex(constraints.sourceFaces, intervalFace,
                                     sourceVertex)) {
      return false;
    }
  }

  if (interval.component >= 0 &&
      constraints.sourceFaceComponent.size() ==
          static_cast<std::size_t>(constraints.sourceFaces.rows()) &&
      constraints.sourceFaceComponent[
          LegacyAuthorityAdapters::to_legacy_index(intervalFace)] !=
          interval.component) {
    return false;
  }
  if (interval.sheet >= 0 &&
      constraints.sourceFaceSheet.size() ==
          static_cast<std::size_t>(constraints.sourceFaces.rows()) &&
      constraints.sourceFaceSheet[
          LegacyAuthorityAdapters::to_legacy_index(intervalFace)] !=
          interval.sheet) {
    return false;
  }
  return true;
}
'''

rail_path = Path("src/geometry/SurfaceOptimizationRailConstraints.cpp")
rail_text = rail_path.read_text()
start = rail_text.index("#include <directional/geometry/SurfaceOptimizationRailConstraints.h>")
marker = "\nnamespace directional::geometry {\n\nvoid fill_surface_optimization_rail_constraints("
end = rail_text.index(marker)
rail_path.write_text(rail_cpp + rail_text[end:])

replace_once(
    "tests/SurfaceMeshOptimizerPhase22Tests.cpp",
    "#include <directional/geometry/SurfaceMeshOptimizer.h>\n",
    "#include <directional/authority/LegacyAuthorityAdapters.h>\n#include <directional/geometry/SurfaceMeshOptimizer.h>\n",
)
replace_once(
    "tests/SurfaceMeshOptimizerPhase22Tests.cpp",
    "#include <set>\n#include <vector>\n",
    "#include <set>\n#include <type_traits>\n#include <vector>\n",
)

test_append = r'''

namespace {

using RailContainsVertexFn = bool (*)(
    const Eigen::MatrixXi &, directional::authority::SourceFaceId,
    directional::authority::SourceVertexId);

static_assert(std::is_same_v<
              decltype(&directional::geometry::surface_optimization_rail_detail::
                           source_face_contains_vertex),
              RailContainsVertexFn>);
static_assert(!std::is_invocable_r_v<
              bool, RailContainsVertexFn, const Eigen::MatrixXi &,
              directional::authority::SourceVertexId,
              directional::authority::SourceFaceId>);

directional::geometry::SurfaceOptimizationConstraints
make_m1b_sheet_constraints() {
  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceFaces.resize(3, 3);
  constraints.sourceFaces << 0, 1, 2,
      0, 2, 3,
      4, 5, 6;
  constraints.sourceFaceComponent = {7, 7, 7};
  constraints.sourceFaceSheet = {0, 1, 1};
  return constraints;
}

directional::geometry::SurfacePoint m1b_provenance(
    const Eigen::Vector3d &barycentric) {
  directional::geometry::SurfacePoint point;
  point.face = 0;
  point.component = 7;
  point.sheet = 0;
  point.barycentric = barycentric;
  point.squaredDistance = 0.0;
  return point;
}

directional::geometry::SurfaceFeatureCurveInterval m1b_interval(
    const int sourceFace) {
  directional::geometry::SurfaceFeatureCurveInterval interval;
  interval.sourceFace = sourceFace;
  interval.component = 7;
  interval.sheet = 1;
  return interval;
}

} // namespace

TEST(SurfaceOptimizationRailAuthorityMigration,
     SameSheetRailAssignmentRemainsAccepted) {
  auto constraints = make_m1b_sheet_constraints();
  constraints.sourceFaceSheet = {0, 0, 1};

  directional::geometry::SurfaceCellRail rail;
  rail.id = 5;
  rail.curveId = 9;
  rail.component = 7;
  rail.samples.resize(2);
  rail.samples[0].sourceFace = 0;
  rail.samples[0].railParameter = 0.0;
  rail.samples[0].position << 0.0, 0.0, 0.0;
  rail.samples[1].sourceFace = 0;
  rail.samples[1].railParameter = 1.0;
  rail.samples[1].position << 1.0, 0.0, 0.0;

  Eigen::MatrixXd output(1, 3);
  output << 0.5, 0.0, 0.0;
  auto provenance = m1b_provenance(Eigen::Vector3d(0.5, 0.5, 0.0));
  provenance.sheet = 0;

  directional::geometry::fill_surface_optimization_rail_constraints(
      {rail}, output, {provenance}, constraints);

  ASSERT_EQ(constraints.featureVertices, std::vector<int>({0}));
  ASSERT_EQ(constraints.featureCurveIds.size(), 1);
  EXPECT_EQ(constraints.featureCurveIds(0), 9);
  EXPECT_EQ(constraints.featureRailIds(0), 5);
}

TEST(SurfaceOptimizationRailAuthorityMigration,
     CrossSheetExactVertexAndEdgeIncidenceRemainAccepted) {
  const auto constraints = make_m1b_sheet_constraints();
  const auto interval = m1b_interval(1);

  EXPECT_TRUE(directional::geometry::surface_optimization_rail_detail::
                  provenance_supports_interval_sheet(
                      m1b_provenance(Eigen::Vector3d(1.0, 0.0, 0.0)),
                      interval, constraints));
  EXPECT_TRUE(directional::geometry::surface_optimization_rail_detail::
                  provenance_supports_interval_sheet(
                      m1b_provenance(Eigen::Vector3d(0.5, 0.0, 0.5)),
                      interval, constraints));
}

TEST(SurfaceOptimizationRailAuthorityMigration,
     CrossSheetInteriorProvenanceRemainsRejected) {
  const auto constraints = make_m1b_sheet_constraints();
  EXPECT_FALSE(directional::geometry::surface_optimization_rail_detail::
                   provenance_supports_interval_sheet(
                       m1b_provenance(Eigen::Vector3d(0.2, 0.3, 0.5)),
                       m1b_interval(1), constraints));
}

TEST(SurfaceOptimizationRailAuthorityMigration,
     InvalidLegacySourceFacesRemainRejected) {
  const auto constraints = make_m1b_sheet_constraints();
  const auto point = m1b_provenance(Eigen::Vector3d(1.0, 0.0, 0.0));

  EXPECT_FALSE(directional::geometry::surface_optimization_rail_detail::
                   provenance_supports_interval_sheet(point, m1b_interval(-1),
                                                       constraints));
  EXPECT_FALSE(directional::geometry::surface_optimization_rail_detail::
                   provenance_supports_interval_sheet(point, m1b_interval(3),
                                                       constraints));
  auto invalidPoint = point;
  invalidPoint.face = 3;
  EXPECT_FALSE(directional::geometry::surface_optimization_rail_detail::
                   provenance_supports_interval_sheet(
                       invalidPoint, m1b_interval(1), constraints));
}

TEST(SurfaceOptimizationRailAuthorityMigration,
     WrongSourceFaceWithoutTypedSupportRemainsRejected) {
  const auto constraints = make_m1b_sheet_constraints();
  EXPECT_FALSE(directional::geometry::surface_optimization_rail_detail::
                   provenance_supports_interval_sheet(
                       m1b_provenance(Eigen::Vector3d(0.5, 0.0, 0.5)),
                       m1b_interval(2), constraints));
}

TEST(SurfaceOptimizationRailAuthorityMigration,
     SourceFaceComponentAndSheetAuthorityMismatchRemainRejected) {
  const auto point = m1b_provenance(Eigen::Vector3d(1.0, 0.0, 0.0));
  const auto interval = m1b_interval(1);

  auto componentMismatch = make_m1b_sheet_constraints();
  componentMismatch.sourceFaceComponent[1] = 8;
  EXPECT_FALSE(directional::geometry::surface_optimization_rail_detail::
                   provenance_supports_interval_sheet(
                       point, interval, componentMismatch));

  auto sheetMismatch = make_m1b_sheet_constraints();
  sheetMismatch.sourceFaceSheet[1] = 2;
  EXPECT_FALSE(directional::geometry::surface_optimization_rail_detail::
                   provenance_supports_interval_sheet(point, interval,
                                                       sheetMismatch));
}
'''

test_path = Path("tests/SurfaceMeshOptimizerPhase22Tests.cpp")
test_text = test_path.read_text()
if "TEST(SurfaceOptimizationRailAuthorityMigration," in test_text:
    raise SystemExit("M1b focused tests already present")
test_path.write_text(test_text.rstrip() + test_append + "\n")
