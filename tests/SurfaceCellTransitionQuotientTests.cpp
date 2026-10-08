#include "BenchmarkQuality.h"
#include "TestFixturePaths.h"
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/geometry/SurfaceMeshOptimizer.h>
#include <directional/validation/MeshValidator.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <limits>
#include <map>
#include <memory>
#include <variant>
#include <numbers>
#include <numeric>
#include <set>
#include <stdexcept>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

namespace {

directional::geometry::SourceProjectionChart test_projection_chart(
    const int fieldChart, const int sourceFaceToken) {
  const auto chart = directional::authority::FieldChartId::from_index(
      fieldChart, static_cast<std::size_t>(std::max(fieldChart + 1, 1)));
  const int firstIndex = 3 * sourceFaceToken;
  const std::size_t vertexExtent = static_cast<std::size_t>(
      std::max(firstIndex + 3, 1));
  const auto first = directional::authority::SourceVertexId::from_index(
      firstIndex, vertexExtent);
  const auto second = directional::authority::SourceVertexId::from_index(
      firstIndex + 1, vertexExtent);
  const auto third = directional::authority::SourceVertexId::from_index(
      firstIndex + 2, vertexExtent);
  if (!chart || !first || !second || !third) {
    throw std::runtime_error("Invalid test projection chart.");
  }
  const auto face = directional::authority::SourceFaceTopologyKey::make(
      {first.value(), second.value(), third.value()});
  if (!face) {
    throw std::runtime_error("Invalid test projection chart topology.");
  }
  return {chart.value(), face.value()};
}


directional::authority::TopologyRegionId test_topology_region_id(
    const int value) {
  const auto id = directional::authority::TopologyRegionId::from_index(
      value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) throw std::runtime_error("Invalid test topology-region ID.");
  return id.value();
}

directional::authority::IsolationSheetId test_isolation_sheet_id(
    const int value) {
  const auto id = directional::authority::IsolationSheetId::from_index(
      value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) throw std::runtime_error("Invalid test isolation-sheet ID.");
  return id.value();
}

directional::authority::SourceEdgeTopologyKey test_source_edge_topology(
    const int firstVertex, const int secondVertex,
    const std::size_t vertexExtent) {
  const auto topology = directional::authority::SourceEdgeTopologyKey::from_indices(
      firstVertex, secondVertex, vertexExtent);
  if (!topology) throw std::runtime_error("Invalid test source-edge topology.");
  return topology.value();
}

directional::authority::SourceEdgeTopologyKey test_source_edge_topology(
    const int firstVertex, const int secondVertex) {
  return test_source_edge_topology(
      firstVertex, secondVertex, static_cast<std::size_t>(
          std::max({firstVertex + 1, secondVertex + 1, 1})));
}

directional::authority::SourceSupport test_source_vertex_support(
    const int value) {
  const auto id = directional::authority::SourceVertexId::from_index(
      value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) throw std::runtime_error("Invalid test source-vertex support.");
  return directional::authority::SourceVertexSupport{id.value()};
}

using directional::geometry::SurfaceCellNetwork;
using directional::geometry::SurfaceCellProducerDisposition;
using directional::geometry::SurfaceFrontBoundaryKind;
using directional::geometry::SurfacePhaseFrontResult;
using directional::pipeline::AuthoritativePhaseFrontMeshResult;

bool route_is_all_boundary(const directional::authority::CanonicalRoute &route) {
  return !route.empty() &&
         std::all_of(route.steps().begin(), route.steps().end(), [](const auto &step) {
           return step.kind() ==
                  directional::authority::TransitionStepKind::Boundary;
         });
}

bool route_is_all_interior(const directional::authority::CanonicalRoute &route) {
  return !route.empty() &&
         std::all_of(route.steps().begin(), route.steps().end(), [](const auto &step) {
           return step.kind() ==
                      directional::authority::TransitionStepKind::Interior &&
                  step.interior().has_value();
         });
}

directional::authority::CanonicalRoute boundary_route_from_topology(
    const directional::authority::SourceEdgeTopologyKey &topology) {
  return directional::authority::CanonicalRoute::from_observed_steps({
      directional::authority::TransitionStep::boundary(
          topology, directional::authority::GridAutomorphism::identity(),
          directional::authority::Orientation::Forward)});
}

directional::authority::CanonicalRoute test_interior_route(
    const int firstVertex, const int secondVertex, const int transitionId,
    const std::size_t vertexExtent = 64,
    const std::size_t transitionExtent = 64) {
  const auto first = directional::authority::SourceVertexId::from_index(
      firstVertex, vertexExtent);
  const auto second = directional::authority::SourceVertexId::from_index(
      secondVertex, vertexExtent);
  const auto transition = directional::authority::InteriorTransitionId::from_index(
      transitionId, transitionExtent);
  if (!first || !second || !transition) {
    throw std::runtime_error("Invalid test interior-route authority.");
  }
  const auto topology = directional::authority::SourceEdgeTopologyKey::make(
      first.value(), second.value());
  if (!topology) throw std::runtime_error("Degenerate test route topology.");
  const auto step = directional::authority::TransitionStep::interior(
      topology.value(), transition.value(),
      directional::authority::GridAutomorphism::identity(),
      directional::authority::Orientation::Forward);
  if (!step) throw std::runtime_error("Invalid test interior-route step.");
  return directional::authority::CanonicalRoute::from_observed_steps(
      {step.value()});
}

std::vector<directional::authority::PeriodicCarrierStepIdentity>
independent_periodic_route_carrier(
    const directional::authority::CanonicalRoute &route) {
  std::vector<directional::authority::PeriodicCarrierStepIdentity> carrier;
  carrier.reserve(route.steps().size());
  for (const auto &step : route.oriented_steps()) {
    carrier.push_back({
        step.kind() == directional::authority::TransitionStepKind::Boundary
            ? directional::authority::PeriodicCarrierStepKind::Boundary
            : directional::authority::PeriodicCarrierStepKind::Interior,
        step.topology(), step.interior()});
  }
  return carrier;
}

std::pair<
    std::vector<directional::authority::PeriodicCarrierStepIdentity>,
    std::vector<directional::authority::PeriodicCarrierStepIdentity>>
independent_periodic_carrier_identity(
    const directional::authority::CanonicalRoute &route,
    const directional::authority::CanonicalRoute &cutRoute) {
  auto generator = independent_periodic_route_carrier(route);
  auto cut = independent_periodic_route_carrier(cutRoute);
  auto reversedGenerator = generator;
  auto reversedCut = cut;
  std::reverse(reversedGenerator.begin(), reversedGenerator.end());
  std::reverse(reversedCut.begin(), reversedCut.end());
  if (std::tie(reversedGenerator, reversedCut) < std::tie(generator, cut)) {
    generator = std::move(reversedGenerator);
    cut = std::move(reversedCut);
  }
  return {std::move(generator), std::move(cut)};
}

std::optional<directional::authority::PeriodicRelationId>
independent_periodic_relation_id(
    const directional::authority::TopologyRegionId region,
    const directional::authority::CanonicalRoute &route,
    const directional::authority::CanonicalRoute &cutRoute) {
  auto [generator, cut] =
      independent_periodic_carrier_identity(route, cutRoute);
  return directional::authority::PeriodicRelationId::from_carriers(
      region, std::move(generator), std::move(cut));
}

directional::authority::GridAutomorphism independent_route_transport(
    const directional::authority::CanonicalRoute &route) {
  auto transport = directional::authority::GridAutomorphism::identity();
  for (const auto &step : route.oriented_steps()) {
    transport = compose(step.transport(), transport);
  }
  return transport;
}

directional::authority::CanonicalRoute
tamper_route_transport_preserving_carrier(
    const directional::authority::CanonicalRoute &route) {
  auto steps = route.oriented_steps();
  if (steps.empty()) {
    throw std::runtime_error("Cannot tamper an empty periodic route.");
  }
  const auto &original = steps.front();
  auto transport = original.transport();
  ++transport.shift.x;
  if (original.kind() == directional::authority::TransitionStepKind::Boundary) {
    steps.front() = directional::authority::TransitionStep::boundary(
        original.topology(), transport, original.orientation());
  } else {
    const auto replacement = directional::authority::TransitionStep::interior(
        original.topology(), original.interior(), transport,
        original.orientation());
    if (!replacement) {
      throw std::runtime_error("Failed to tamper periodic interior route.");
    }
    steps.front() = replacement.value();
  }
  return directional::authority::CanonicalRoute::from_observed_steps(
      std::move(steps));
}

directional::geometry::SurfacePhaseFrontProduct
direct_periodic_owner_product() {
  const auto projection = test_projection_chart(0, 0);
  const auto component = directional::authority::SourceComponentId::from_index(0, 1);
  const auto sheet = directional::authority::IsolationSheetId::from_index(0, 1);
  const auto regionId = directional::authority::TopologyRegionId::from_index(0, 1);
  if (!component || !sheet || !regionId) {
    throw std::runtime_error("Invalid direct periodic-owner source IDs.");
  }

  const auto &vertices = projection.face.vertices();
  const auto edge01 = directional::authority::SourceEdgeTopologyKey::make(
      vertices[0], vertices[1]);
  const auto edge12 = directional::authority::SourceEdgeTopologyKey::make(
      vertices[1], vertices[2]);
  const auto edge20 = directional::authority::SourceEdgeTopologyKey::make(
      vertices[2], vertices[0]);
  if (!edge01 || !edge12 || !edge20) {
    throw std::runtime_error("Invalid direct periodic-owner boundary topology.");
  }

  std::vector<directional::authority::SourceEdgeTopologyKey>
      boundaryTopology = {edge01.value(), edge12.value(), edge20.value()};
  std::sort(boundaryTopology.begin(), boundaryTopology.end());
  boundaryTopology.erase(
      std::unique(boundaryTopology.begin(), boundaryTopology.end()),
      boundaryTopology.end());
  if (boundaryTopology.size() != 3U) {
    throw std::runtime_error(
        "Direct periodic-owner boundary topology is not three distinct edges.");
  }

  auto region = directional::geometry::SurfaceTopologyRegion::make(
      regionId.value(), component.value(),
      {{projection.face, sheet.value()}}, boundaryTopology, {}, 1, 1);
  if (!region.has_value()) {
    throw std::runtime_error("Failed to construct direct periodic-owner region.");
  }
  auto authority = directional::geometry::SourceTopologyRegions::make(
      {projection.face}, {component.value()}, {sheet.value()},
      {std::move(region.value())});
  if (!authority.has_value()) {
    throw std::runtime_error("Failed to construct direct periodic-owner authority.");
  }

  const auto ownerCell = directional::authority::CellId::from_index(0, 1);
  if (!ownerCell) {
    throw std::runtime_error("Invalid direct periodic-owner cell ID.");
  }
  std::vector<directional::geometry::SurfacePhaseFrontCell> cells;
  cells.emplace_back(regionId.value(), ownerCell.value());
  cells.back().orientationValidated = true;

  const std::array<directional::authority::CanonicalRoute, 2> routes = {
      test_interior_route(0, 1, 0), test_interior_route(1, 2, 1)};
  const std::array<directional::authority::CanonicalRoute, 2> cuts = {
      test_interior_route(2, 0, 2), test_interior_route(0, 2, 3)};
  std::vector<directional::geometry::SurfacePeriodicHolonomy> relations;
  std::vector<directional::geometry::SurfaceFrontEdge> edges;
  for (int relationIndex = 0; relationIndex < 2; ++relationIndex) {
    const directional::authority::GridAutomorphism action{
        directional::authority::QuarterTurn{},
        relationIndex == 0 ? directional::authority::LatticeTranslation{4, 0}
                           : directional::authority::LatticeTranslation{0, 5}};
    auto relation = directional::geometry::SurfacePeriodicHolonomy::make(
        regionId.value(), action, routes[static_cast<std::size_t>(relationIndex)],
        cuts[static_cast<std::size_t>(relationIndex)]);
    auto *relationValue =
        std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&relation);
    if (relationValue == nullptr) {
      throw std::runtime_error("Failed to construct direct periodic relation.");
    }
    const auto relationId = relationValue->id();
    relations.push_back(std::move(*relationValue));

    directional::geometry::SurfaceFrontEdge edge(regionId.value(),
                                                  ownerCell.value());
    edge.boundaryKind = SurfaceFrontBoundaryKind::PeriodicCut;
    edge.periodicRelation = relationId;
    edges.push_back(std::move(edge));
  }
  auto product = directional::geometry::SurfacePhaseFrontProduct::make(
      0, 0, std::move(authority.value()), {}, std::move(relations), {},
      std::move(edges), {}, std::move(cells));
  auto *value =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&product);
  if (value == nullptr) {
    throw std::runtime_error("Failed to construct direct periodic-owner product.");
  }
  return std::move(*value);
}

struct PhaseFrontFixture {
  directional::TriMesh mesh;
  std::vector<int> components;
  std::vector<int> sheets;
  SurfaceCellNetwork network;
};

Eigen::MatrixXd constant_xy_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    raw.row(face) << 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 0.0,
        0.0, -1.0, 0.0;
  }
  return raw;
}

Eigen::MatrixXd read_rawfield(const std::filesystem::path &path,
                              const int expectedFaces) {
  std::ifstream stream(path);
  if (!stream) {
    throw std::runtime_error("Failed to open rawfield fixture: " +
                             path.string());
  }
  int degree = 0;
  int faceCount = 0;
  if (!(stream >> degree >> faceCount) || degree != 4 ||
      faceCount != expectedFaces) {
    throw std::runtime_error("Invalid rawfield fixture header: " +
                             path.string());
  }
  Eigen::MatrixXd raw(faceCount, 3 * degree);
  for (int face = 0; face < faceCount; ++face) {
    for (int column = 0; column < raw.cols(); ++column) {
      if (!(stream >> raw(face, column))) {
        throw std::runtime_error("Invalid rawfield fixture payload: " +
                                 path.string());
      }
    }
  }
  return raw;
}

void require_produced(const PhaseFrontFixture &fixture,
                      const std::string &fixtureName) {
  if (fixture.network.phaseFront.disposition() !=
          SurfaceCellProducerDisposition::Produced ||
      !fixture.network.phaseFront.is_produced()) {
    throw std::runtime_error(
        fixtureName + " producer failed: " +
        directional::geometry::surface_phase_front_failure_reason_name(
            fixture.network.phaseFront.rejection_reason()));
  }
}

PhaseFrontFixture make_square_fixture(const bool splitIsolation,
                                      const bool overlappingComponents) {
  PhaseFrontFixture fixture;
  if (overlappingComponents) {
    Eigen::MatrixXd vertices(8, 3);
    vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
        1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
        1.0, 0.0;
    Eigen::MatrixXi faces(4, 3);
    faces << 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7;
    fixture.mesh.set_mesh(vertices, faces);
    fixture.components = {0, 0, 1, 1};
    fixture.sheets = {0, 0, 1, 1};
  } else {
    Eigen::MatrixXd vertices(4, 3);
    vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
        1.0, 0.0;
    Eigen::MatrixXi faces(2, 3);
    faces << 0, 1, 2, 0, 2, 3;
    fixture.mesh.set_mesh(vertices, faces);
    fixture.components = {0, 0};
    fixture.sheets = splitIsolation ? std::vector<int>{0, 1}
                                    : std::vector<int>{0, 0};
  }
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, constant_xy_field(fixture.mesh.F.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.5;
  options.sourceFaceComponents = fixture.components;
  options.sourceFaceSheets = fixture.sheets;
  const Eigen::VectorXd targetSize =
      Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 0.5);
  fixture.network = directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField, targetSize, options);
  require_produced(fixture, overlappingComponents
                                ? "overlapping disconnected squares"
                                : splitIsolation ? "split-isolation square"
                                                 : "square");
  return fixture;
}

PhaseFrontFixture make_square_fixture_with_reversed_source_face_rows() {
  PhaseFrontFixture fixture;
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 2, 3, 0, 1, 2;
  fixture.mesh.set_mesh(vertices, faces);
  fixture.components = {0, 0};
  fixture.sheets = {0, 0};

  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, constant_xy_field(fixture.mesh.F.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.5;
  options.sourceFaceComponents = fixture.components;
  options.sourceFaceSheets = fixture.sheets;
  fixture.network = directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField,
      Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 0.5), options);
  require_produced(fixture, "source-face-row-permuted square");
  return fixture;
}

PhaseFrontFixture make_split_isolation_fixture_with_reversed_source_face_rows() {
  PhaseFrontFixture fixture;
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 2, 3, 0, 1, 2;
  fixture.mesh.set_mesh(vertices, faces);
  fixture.components = {0, 0};
  fixture.sheets = {1, 0};

  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, constant_xy_field(fixture.mesh.F.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.5;
  options.sourceFaceComponents = fixture.components;
  options.sourceFaceSheets = fixture.sheets;
  fixture.network = directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField,
      Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 0.5), options);
  require_produced(fixture, "source-face-row-permuted split-isolation square");
  return fixture;
}

PhaseFrontFixture make_transition_domain_fixture() {
  PhaseFrontFixture fixture;
  Eigen::MatrixXd vertices(8, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0, 0.0,
      1.0, 0.0, 2.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0, 1.0, 0.0, 2.0,
      1.0, 0.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 2, 0, 2, 3, 4, 5, 6, 4, 6, 7;
  fixture.mesh.set_mesh(vertices, faces);
  fixture.components = {0, 0, 1, 1};
  fixture.sheets = {0, 0, 1, 1};
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, constant_xy_field(fixture.mesh.F.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.5;
  options.sourceFaceComponents = fixture.components;
  options.sourceFaceSheets = fixture.sheets;
  fixture.network = directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField,
      Eigen::VectorXd::Constant(vertices.rows(), 0.5), options);
  require_produced(fixture, "transition-domain rectangles");
  return fixture;
}

PhaseFrontFixture make_hard_rail_fixture() {
  PhaseFrontFixture fixture;
  Eigen::MatrixXd vertices(9, 3);
  int vertex = 0;
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++x) {
      vertices.row(vertex++) << static_cast<double>(x),
          static_cast<double>(y), 0.0;
    }
  }
  Eigen::MatrixXi faces(8, 3);
  int face = 0;
  for (int y = 0; y < 2; ++y) {
    for (int x = 0; x < 2; ++x) {
      const int lowerLeft = y * 3 + x;
      const int lowerRight = lowerLeft + 1;
      const int upperLeft = lowerLeft + 3;
      const int upperRight = upperLeft + 1;
      faces.row(face++) << lowerLeft, lowerRight, upperRight;
      faces.row(face++) << lowerLeft, upperRight, upperLeft;
    }
  }
  fixture.mesh.set_mesh(vertices, faces);

  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.lengthRatio = 0.2;
  options.surfaceCells.featureMap.userHardEdges.insert({1, 4});
  options.surfaceCells.featureMap.userHardEdges.insert({4, 7});

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      fixture.mesh.V, fixture.mesh.F, constant_xy_field(faces.rows()), options);
  const auto &snapshots = result.surfaceCellContext.productSnapshots;
  if (!snapshots.hasSourceSurfaceLabels ||
      !snapshots.sourceTopologyRegions.has_value() ||
      !snapshots.fieldAlignedCurveNetwork.has_value() ||
      !snapshots.globalTopologyPlan.has_value() ||
      !snapshots.globalConformityBaseline.has_value() ||
      !snapshots.hasAuthoritativeRails ||
      !result.surfaceCellContext.hasTraceNetwork) {
    throw std::runtime_error(
        "Production hard-rail fixture did not retain A2b/A3 tracing authority.");
  }

  fixture.components = snapshots.sourceSurfaceLabels.componentByFace;
  fixture.sheets = snapshots.sourceSurfaceLabels.localSheetByFace;
  fixture.network = snapshots.traceNetwork;
  require_produced(fixture, "internal-midline hard-rail rectangle");
  return fixture;
}

PhaseFrontFixture make_committed_fixture(const std::string &name,
                                         const bool windingField = false) {
  PhaseFrontFixture fixture;
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/" + name + ".obj");
  if (!directional::readOBJ(meshPath.string(), fixture.mesh)) {
    throw std::runtime_error("Failed to read committed fixture: " + name);
  }
  Eigen::MatrixXd raw;
  if (!windingField) {
    raw = read_rawfield(directional::tests::benchmark_fixture_path(
                            "milestone-g/" + name + ".rawfield"),
                        fixture.mesh.F.rows());
  } else {
    raw.resize(fixture.mesh.F.rows(), 12);
    for (int face = 0; face < fixture.mesh.F.rows(); ++face) {
      Eigen::Vector3d centroid = Eigen::Vector3d::Zero();
      for (int corner = 0; corner < 3; ++corner) {
        centroid += fixture.mesh.V.row(fixture.mesh.F(face, corner)).transpose();
      }
      centroid /= 3.0;
      double angle = std::atan2(centroid.y(), centroid.x());
      if (angle < 0.0) angle += 2.0 * std::numbers::pi;
      const Eigen::Vector3d circumferential(-std::sin(angle), std::cos(angle),
                                            0.0);
      const Eigen::Vector3d axial(0.0, 0.0, 1.0);
      const double fieldAngle = 0.25 * angle;
      const Eigen::Vector3d x = std::cos(fieldAngle) * circumferential +
                                std::sin(fieldAngle) * axial;
      const Eigen::Vector3d y = -std::sin(fieldAngle) * circumferential +
                                std::cos(fieldAngle) * axial;
      raw.row(face) << x.transpose(), y.transpose(), (-x).transpose(),
          (-y).transpose();
    }
  }
  const auto labels = directional::geometry::surface_cell_tracing_detail::
      classify_source_surface_labels(fixture.mesh.V, fixture.mesh.F);
  fixture.components = labels.componentByFace;
  fixture.sheets = labels.localSheetByFace;
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(fixture.mesh,
                                                                    raw);
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.25;
  options.sourceFaceComponents = fixture.components;
  options.sourceFaceSheets = fixture.sheets;
  fixture.network = directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField,
      Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 0.25), options);
  require_produced(fixture, windingField ? name + " winding field" : name);
  return fixture;
}

PhaseFrontFixture make_torus_pipeline_fixture() {
  PhaseFrontFixture fixture;
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/torus.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/torus.rawfield");
  if (!directional::readOBJ(meshPath.string(), fixture.mesh)) {
    throw std::runtime_error("Failed to read committed torus fixture");
  }
  const Eigen::MatrixXd raw =
      read_rawfield(fieldPath, fixture.mesh.F.rows());
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.featureMap.cadAbsoluteLowDegrees = 179.0;
  options.surfaceCells.featureMap.cadAbsoluteHighDegrees = 180.0;
  options.surfaceCells.featureMap.organicAbsoluteLowDegrees = 179.0;
  options.surfaceCells.featureMap.organicAbsoluteHighDegrees = 180.0;
  const std::array<int, 7> minorCycle{{0, 3, 25, 37, 49, 61, 0}};
  const std::array<int, 13> majorCycle{
      {0, 1, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 0}};
  const auto addCycle = [&options](const auto &cycle) {
    for (std::size_t i = 1U; i < cycle.size(); ++i) {
      const int a = cycle[i - 1U];
      const int b = cycle[i];
      options.surfaceCells.featureMap.userHardEdges.insert(
          {std::min(a, b), std::max(a, b)});
    }
  };
  addCycle(minorCycle);
  addCycle(majorCycle);
  if (options.surfaceCells.featureMap.userHardEdges.size() != 18U) {
    throw std::runtime_error(
        "Torus pipeline requires the row408 18-edge hard-rail authority");
  }
  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      fixture.mesh.V, fixture.mesh.F, raw, options);
  if (!result.surfaceCellContext.hasTraceNetwork) {
    throw std::runtime_error("Torus pipeline did not retain trace authority: " +
                             result.diagnostics.terminalFailureCode + "/" +
                             result.diagnostics.terminalFailureStage);
  }
  fixture.network = result.surfaceCellContext.productSnapshots.traceNetwork;
  require_produced(fixture, "torus pipeline");
  return fixture;
}

const PhaseFrontFixture &square_fixture() {
  static const PhaseFrontFixture fixture = make_square_fixture(false, false);
  return fixture;
}

const PhaseFrontFixture &split_isolation_fixture() {
  static const PhaseFrontFixture fixture = make_square_fixture(true, false);
  return fixture;
}

const PhaseFrontFixture &overlap_fixture() {
  static const PhaseFrontFixture fixture = make_square_fixture(false, true);
  return fixture;
}

const PhaseFrontFixture &transition_domain_fixture() {
  static const PhaseFrontFixture fixture = make_transition_domain_fixture();
  return fixture;
}

const PhaseFrontFixture &hard_rail_fixture() {
  static const PhaseFrontFixture fixture = make_hard_rail_fixture();
  return fixture;
}

PhaseFrontFixture make_nonconstant_hard_rail_fixture() {
  PhaseFrontFixture fixture;
  Eigen::MatrixXd vertices(9, 3);
  int vertex = 0;
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++x) {
      vertices.row(vertex++) << static_cast<double>(x),
          static_cast<double>(y), 0.0;
    }
  }
  Eigen::MatrixXi faces(8, 3);
  int face = 0;
  for (int y = 0; y < 2; ++y) {
    for (int x = 0; x < 2; ++x) {
      const int lowerLeft = y * 3 + x;
      const int lowerRight = lowerLeft + 1;
      const int upperLeft = lowerLeft + 3;
      const int upperRight = upperLeft + 1;
      faces.row(face++) << lowerLeft, lowerRight, upperRight;
      faces.row(face++) << lowerLeft, upperRight, upperLeft;
    }
  }
  fixture.mesh.set_mesh(vertices, faces);

  Eigen::MatrixXd raw = constant_xy_field(faces.rows());
  for (int row = 0; row < faces.rows(); ++row) {
    double centerX = 0.0;
    for (int corner = 0; corner < 3; ++corner) {
      centerX += vertices(faces(row, corner), 0);
    }
    centerX /= 3.0;
    if (centerX > 1.0) {
      raw.row(row) << 0.0, 1.0, 0.0, -1.0, 0.0, 0.0,
          0.0, -1.0, 0.0, 1.0, 0.0, 0.0;
    }
  }

  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.lengthRatio = 0.2;
  options.surfaceCells.featureMap.userHardEdges.insert({1, 4});
  options.surfaceCells.featureMap.userHardEdges.insert({4, 7});

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      fixture.mesh.V, fixture.mesh.F, raw, options);
  const auto &snapshots = result.surfaceCellContext.productSnapshots;
  if (!snapshots.hasSourceSurfaceLabels ||
      !snapshots.sourceTopologyRegions.has_value() ||
      !snapshots.fieldAlignedCurveNetwork.has_value() ||
      !snapshots.globalTopologyPlan.has_value() ||
      !snapshots.globalConformityBaseline.has_value() ||
      !snapshots.hasAuthoritativeRails ||
      !result.surfaceCellContext.hasTraceNetwork) {
    throw std::runtime_error(
        "Non-constant hard-rail fixture did not retain A2b/A3 authority.");
  }
  fixture.components = snapshots.sourceSurfaceLabels.componentByFace;
  fixture.sheets = snapshots.sourceSurfaceLabels.localSheetByFace;
  fixture.network = snapshots.traceNetwork;
  require_produced(fixture, "non-constant internal-midline hard-rail rectangle");
  return fixture;
}

const PhaseFrontFixture &nonconstant_hard_rail_fixture() {
  static const PhaseFrontFixture fixture = make_nonconstant_hard_rail_fixture();
  return fixture;
}

const PhaseFrontFixture &cylinder_fixture() {
  static const PhaseFrontFixture fixture =
      make_committed_fixture("cylinder", false);
  return fixture;
}

const PhaseFrontFixture &direct_materializer_base_fixture() {
  static const PhaseFrontFixture fixture =
      make_committed_fixture("cylinder", false);
  return fixture;
}

const PhaseFrontFixture &torus_fixture() {
  static const PhaseFrontFixture fixture = make_torus_pipeline_fixture();
  return fixture;
}

struct ProducedTorusSourceWitness {
  directional::authority::SourceEdgeTopologyKey carrier;
  directional::authority::NetworkArcId span;
  directional::authority::NetworkRegionId networkRegion;
  directional::geometry::SurfaceBoundaryOccurrenceId fromOccurrence;
  directional::geometry::SurfaceBoundaryOccurrenceId toOccurrence;
  directional::authority::SourceFaceId fromFace;
  directional::authority::SourceFaceId toFace;
  directional::authority::QuarterTurn sourceRotation;
  directional::authority::QuarterTurn atlasRotation;
  directional::authority::Orientation sourcePathOrientation =
      directional::authority::Orientation::Forward;
  directional::authority::CanonicalRoute generatorRoute;
};

struct ProducedTorusWitnessFixture {
  PhaseFrontFixture fixture;
  ProducedTorusSourceWitness witness;
};

std::set<directional::authority::SourceEdgeTopologyKey>
torus_row408_hard_edges(const directional::TriMesh &mesh) {
  const std::array<int, 7> minorCycle{{0, 3, 25, 37, 49, 61, 0}};
  const std::array<int, 13> majorCycle{
      {0, 1, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 0}};
  std::set<directional::authority::SourceEdgeTopologyKey> result;
  const auto append = [&](const auto &cycle) {
    for (std::size_t i = 1U; i < cycle.size(); ++i) {
      result.insert(test_source_edge_topology(
          cycle[i - 1U], cycle[i], static_cast<std::size_t>(mesh.V.rows())));
    }
  };
  append(minorCycle);
  append(majorCycle);
  if (result.size() != 18U) {
    throw std::runtime_error(
        "Torus witness requires the row408 18-edge hard-rail authority.");
  }
  return result;
}



directional::pipeline::RemeshResult run_retained_torus_pipeline() {
  const auto &fixture = torus_fixture();
  const Eigen::MatrixXd raw = read_rawfield(
      directional::tests::benchmark_fixture_path("milestone-g/torus.rawfield"),
      fixture.mesh.F.rows());
  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.featureMap.cadAbsoluteLowDegrees = 179.0;
  options.surfaceCells.featureMap.cadAbsoluteHighDegrees = 180.0;
  options.surfaceCells.featureMap.organicAbsoluteLowDegrees = 179.0;
  options.surfaceCells.featureMap.organicAbsoluteHighDegrees = 180.0;
  for (const auto &edge : torus_row408_hard_edges(fixture.mesh)) {
    options.surfaceCells.featureMap.userHardEdges.insert(
        {static_cast<int>(edge.first().index()),
         static_cast<int>(edge.second().index())});
  }
  return directional::pipeline::remesh_from_raw_cross_field(
      fixture.mesh.V, fixture.mesh.F, raw, options);
}

std::optional<directional::pipeline::SurfaceQuotientClosedComplexView>
build_torus_closed_complex_view(
    const directional::TriMesh &mesh,
    const directional::geometry::SurfacePhaseFrontProduct &phaseFront,
    const std::set<directional::authority::SourceEdgeTopologyKey> &hardEdges) {
  auto a5 = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      mesh.V, mesh.F, phaseFront);
  const auto *occurrences =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&a5);
  if (occurrences == nullptr) return std::nullopt;
  auto a6 = directional::pipeline::SurfaceQuotientProducer::produce(
      *occurrences, hardEdges);
  const auto *quotient =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(&a6);
  if (quotient == nullptr || !quotient->closed_complex_view().has_value()) {
    return std::nullopt;
  }
  return quotient->closed_complex_view().value();
}

Eigen::MatrixXd torus_nonzero_z4_raw_field(const directional::TriMesh &mesh) {
  Eigen::MatrixXd raw(mesh.F.rows(), 12);
  for (int face = 0; face < mesh.F.rows(); ++face) {
    Eigen::Vector3d centroid = Eigen::Vector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      centroid += mesh.V.row(mesh.F(face, corner)).transpose();
    }
    centroid /= 3.0;
    double majorAngle = std::atan2(centroid.y(), centroid.x());
    if (majorAngle < 0.0) majorAngle += 2.0 * std::numbers::pi;

    const Eigen::Vector3d normal = mesh.faceNormals.row(face).transpose();
    Eigen::Vector3d majorTangent(-std::sin(majorAngle),
                                 std::cos(majorAngle), 0.0);
    majorTangent -= majorTangent.dot(normal) * normal;
    if (!majorTangent.allFinite() || majorTangent.norm() <= 1.0e-12) {
      throw std::runtime_error("Degenerate torus major tangent.");
    }
    majorTangent.normalize();
    Eigen::Vector3d minorTangent = normal.cross(majorTangent);
    if (!minorTangent.allFinite() || minorTangent.norm() <= 1.0e-12) {
      throw std::runtime_error("Degenerate torus minor tangent.");
    }
    minorTangent.normalize();

    const double seamRampAngle = (std::numbers::pi - majorAngle) / 6.0;
    const Eigen::Vector3d x = std::cos(seamRampAngle) * majorTangent +
                              std::sin(seamRampAngle) * minorTangent;
    const Eigen::Vector3d y = -std::sin(seamRampAngle) * majorTangent +
                              std::cos(seamRampAngle) * minorTangent;
    raw.row(face) << x.transpose(), y.transpose(), (-x).transpose(),
        (-y).transpose();
  }
  return raw;
}

std::optional<directional::authority::FieldExactRational>
test_exact_edge_parameter(
    const directional::authority::ExactSourcePoint &point,
    const directional::authority::SourceEdgeTopologyKey &edge) {
  if (const auto *vertex =
          std::get_if<directional::authority::SourceVertexId>(&point)) {
    if (*vertex == edge.first()) {
      return directional::authority::FieldExactRational::from_integer(0);
    }
    if (*vertex == edge.second()) {
      return directional::authority::FieldExactRational::from_integer(1);
    }
    return std::nullopt;
  }
  const auto *edgePoint =
      std::get_if<directional::authority::ExactSourceEdgePoint>(&point);
  if (edgePoint == nullptr || edgePoint->edge != edge) return std::nullopt;
  return edgePoint->parameter;
}

const directional::fields::CrossFieldEdgeTransition *source_transition_for(
    const directional::TriMesh &mesh,
    const directional::fields::CrossFieldResult &crossField,
    const directional::authority::SourceEdgeTopologyKey &carrier) {
  const auto found = std::find_if(
      crossField.edgeTransitions.begin(), crossField.edgeTransitions.end(),
      [&](const auto &candidate) {
        return test_source_edge_topology(
                   candidate.sourceVertex0, candidate.sourceVertex1,
                   static_cast<std::size_t>(mesh.V.rows())) == carrier;
      });
  return found == crossField.edgeTransitions.end() ? nullptr : &*found;
}

std::optional<directional::authority::QuarterTurn>
directed_source_transition(
    const directional::TriMesh &mesh,
    const directional::fields::CrossFieldResult &crossField,
    const directional::authority::SourceEdgeTopologyKey &carrier,
    const directional::authority::SourceFaceId fromFace,
    const directional::authority::SourceFaceId toFace) {
  const auto *transition = source_transition_for(mesh, crossField, carrier);
  if (transition == nullptr) return std::nullopt;
  const auto firstFace = directional::authority::SourceFaceId::from_index(
      transition->firstFace, static_cast<std::size_t>(mesh.F.rows()));
  const auto secondFace = directional::authority::SourceFaceId::from_index(
      transition->secondFace, static_cast<std::size_t>(mesh.F.rows()));
  if (!firstFace || !secondFace) return std::nullopt;
  const auto forward = directional::authority::QuarterTurn::from_integer(
      transition->matching);
  if (fromFace == firstFace.value() && toFace == secondFace.value()) {
    return forward;
  }
  if (fromFace == secondFace.value() && toFace == firstFace.value()) {
    return forward.inverse();
  }
  return std::nullopt;
}

struct TorusChartAdmissibilityOracle {
  double minimumBoundaryAlignment = 1.0;
  std::vector<int> canonicalRunBranches;
  std::vector<double> runLengths;
  int signedQuarterTurnSum = 0;
  Eigen::Vector2d closureResidual = Eigen::Vector2d::Zero();
  double closureTolerance = 0.0;
};

int normalized_test_branch(const int branch) {
  return ((branch % 4) + 4) % 4;
}

TorusChartAdmissibilityOracle validate_nonzero_z4_torus_chart_subject(
    const directional::TriMesh &mesh, const Eigen::MatrixXd &raw,
    const directional::fields::CrossFieldResult &sourceCrossField,
    const std::set<directional::authority::SourceEdgeTopologyKey> &hardEdges) {
  constexpr double kBoundaryAlignment = 0.7;
  constexpr double kFrameTolerance = 1.0e-12;
  const std::array<int, 7> minorCycle{{0, 3, 25, 37, 49, 61, 0}};
  const std::array<int, 13> majorCycle{
      {0, 1, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 0}};

  if (hardEdges != torus_row408_hard_edges(mesh) || hardEdges.size() != 18U) {
    throw std::runtime_error(
        "Nonzero-Z4 torus chart oracle requires the exact 18 row408 hard edges.");
  }
  if (raw.rows() != mesh.F.rows() || raw.cols() != 12 ||
      sourceCrossField.primaryDirections.rows() != mesh.F.rows() ||
      sourceCrossField.primaryDirections.cols() != 3 ||
      sourceCrossField.secondaryDirections.rows() != mesh.F.rows() ||
      sourceCrossField.secondaryDirections.cols() != 3) {
    throw std::runtime_error(
        "Nonzero-Z4 torus chart oracle received incomplete field authority.");
  }

  // Re-derive the frozen source frame and exact seam ramp independently of
  // product output so a tuned or differently phased field fails before use.
  for (int face = 0; face < mesh.F.rows(); ++face) {
    Eigen::Vector3d centroid = Eigen::Vector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      centroid += mesh.V.row(mesh.F(face, corner)).transpose();
    }
    centroid /= 3.0;
    double majorAngle = std::atan2(centroid.y(), centroid.x());
    if (majorAngle < 0.0) majorAngle += 2.0 * std::numbers::pi;

    const Eigen::Vector3d normal = mesh.faceNormals.row(face).transpose();
    Eigen::Vector3d majorTangent(-std::sin(majorAngle),
                                 std::cos(majorAngle), 0.0);
    majorTangent -= majorTangent.dot(normal) * normal;
    if (!normal.allFinite() ||
        std::abs(normal.norm() - 1.0) > kFrameTolerance ||
        !majorTangent.allFinite() || majorTangent.norm() <= kFrameTolerance) {
      throw std::runtime_error(
          "Nonzero-Z4 torus chart oracle rejected the source frame.");
    }
    majorTangent.normalize();
    Eigen::Vector3d minorTangent = normal.cross(majorTangent);
    if (!minorTangent.allFinite() || minorTangent.norm() <= kFrameTolerance) {
      throw std::runtime_error(
          "Nonzero-Z4 torus chart oracle rejected the source frame.");
    }
    minorTangent.normalize();

    const double delta = (std::numbers::pi - majorAngle) / 6.0;
    const Eigen::Vector3d expectedX =
        std::cos(delta) * majorTangent + std::sin(delta) * minorTangent;
    const Eigen::Vector3d expectedY =
        -std::sin(delta) * majorTangent + std::cos(delta) * minorTangent;
    const Eigen::Vector3d authoredX = raw.block<1, 3>(face, 0).transpose();
    const Eigen::Vector3d authoredY = raw.block<1, 3>(face, 3).transpose();
    if (!expectedX.allFinite() || !expectedY.allFinite() ||
        std::abs(expectedX.norm() - 1.0) > kFrameTolerance ||
        std::abs(expectedY.norm() - 1.0) > kFrameTolerance ||
        std::abs(expectedX.dot(expectedY)) > kFrameTolerance ||
        expectedX.cross(expectedY).dot(normal) <= 1.0 - kFrameTolerance ||
        (authoredX - expectedX).norm() > kFrameTolerance ||
        (authoredY - expectedY).norm() > kFrameTolerance ||
        (raw.block<1, 3>(face, 6).transpose() + expectedX).norm() >
            kFrameTolerance ||
        (raw.block<1, 3>(face, 9).transpose() + expectedY).norm() >
            kFrameTolerance) {
      throw std::runtime_error(
          "Nonzero-Z4 torus chart oracle rejected the frozen seam-ramp frame.");
    }
  }

  struct FaceEdgeSide {
    int face = -1;
    int firstVertex = -1;
    int secondVertex = -1;
  };
  std::map<directional::authority::SourceEdgeTopologyKey,
           std::vector<FaceEdgeSide>> incidence;
  for (int face = 0; face < mesh.F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int first = mesh.F(face, corner);
      const int second = mesh.F(face, (corner + 1) % 3);
      incidence[test_source_edge_topology(
                    first, second, static_cast<std::size_t>(mesh.V.rows()))]
          .push_back({face, first, second});
    }
  }
  if (std::any_of(incidence.begin(), incidence.end(), [](const auto &entry) {
        return entry.second.size() != 2U;
      })) {
    throw std::runtime_error(
        "Nonzero-Z4 torus chart oracle requires a closed two-sided source mesh.");
  }

  // Establish one global branch gauge over the cut disk from finalized source
  // matching. Hard edges are omitted from the dual exactly because they are
  // the frozen row408 cut authority.
  std::vector<std::vector<std::pair<int,
      directional::authority::SourceEdgeTopologyKey>>> dual(
          static_cast<std::size_t>(mesh.F.rows()));
  for (const auto &[edge, sides] : incidence) {
    if (hardEdges.count(edge) != 0U) continue;
    dual[static_cast<std::size_t>(sides[0].face)].push_back(
        {sides[1].face, edge});
    dual[static_cast<std::size_t>(sides[1].face)].push_back(
        {sides[0].face, edge});
  }
  for (auto &neighbors : dual) std::sort(neighbors.begin(), neighbors.end());

  std::vector<int> faceBranchRotation(static_cast<std::size_t>(mesh.F.rows()),
                                      -1);
  faceBranchRotation[0] = 0;
  std::vector<int> pending{0};
  for (std::size_t index = 0U; index < pending.size(); ++index) {
    const int sourceFace = pending[index];
    const auto typedSource = directional::authority::SourceFaceId::from_index(
        sourceFace, static_cast<std::size_t>(mesh.F.rows()));
    if (!typedSource) {
      throw std::runtime_error(
          "Nonzero-Z4 torus chart oracle could not type a source face.");
    }
    for (const auto &[targetFace, edge] :
         dual[static_cast<std::size_t>(sourceFace)]) {
      const auto typedTarget = directional::authority::SourceFaceId::from_index(
          targetFace, static_cast<std::size_t>(mesh.F.rows()));
      if (!typedTarget) {
        throw std::runtime_error(
            "Nonzero-Z4 torus chart oracle could not type a target face.");
      }
      const auto transport = directed_source_transition(
          mesh, sourceCrossField, edge, typedSource.value(),
          typedTarget.value());
      if (!transport.has_value()) {
        throw std::runtime_error(
            "Nonzero-Z4 torus chart oracle found missing interior transport.");
      }
      const int targetRotation = normalized_test_branch(
          faceBranchRotation[static_cast<std::size_t>(sourceFace)] +
          static_cast<int>(transport->value()));
      int &stored = faceBranchRotation[static_cast<std::size_t>(targetFace)];
      if (stored < 0) {
        stored = targetRotation;
        pending.push_back(targetFace);
      } else if (stored != targetRotation) {
        throw std::runtime_error(
            "Nonzero-Z4 torus chart oracle found inconsistent interior transport.");
      }
    }
  }
  if (std::any_of(faceBranchRotation.begin(), faceBranchRotation.end(),
                  [](const int value) { return value < 0; })) {
    throw std::runtime_error(
        "Nonzero-Z4 torus chart oracle found a disconnected cut-domain dual.");
  }

  TorusChartAdmissibilityOracle oracle;
  const auto classify_cycle = [&](const auto &cycle) {
    std::optional<int> forwardBranch;
    std::optional<int> reverseBranch;
    double cycleLength = 0.0;
    for (std::size_t edgeIndex = 1U; edgeIndex < cycle.size(); ++edgeIndex) {
      const int cycleFirst = cycle[edgeIndex - 1U];
      const int cycleSecond = cycle[edgeIndex];
      const auto edge = test_source_edge_topology(
          cycleFirst, cycleSecond, static_cast<std::size_t>(mesh.V.rows()));
      const auto found = incidence.find(edge);
      if (hardEdges.count(edge) == 0U || found == incidence.end() ||
          found->second.size() != 2U) {
        throw std::runtime_error(
            "Nonzero-Z4 torus chart oracle lost a frozen hard-edge side.");
      }
      cycleLength +=
          (mesh.V.row(cycleSecond) - mesh.V.row(cycleFirst)).norm();
      for (const auto &side : found->second) {
        const bool forward = side.firstVertex == cycleFirst &&
                             side.secondVertex == cycleSecond;
        const bool reverse = side.firstVertex == cycleSecond &&
                             side.secondVertex == cycleFirst;
        if (!forward && !reverse) {
          throw std::runtime_error(
              "Nonzero-Z4 torus chart oracle found inconsistent edge orientation.");
        }
        const Eigen::Vector3d normal =
            mesh.faceNormals.row(side.face).transpose();
        Eigen::Vector3d edgeDirection =
            mesh.V.row(side.secondVertex).transpose() -
            mesh.V.row(side.firstVertex).transpose();
        edgeDirection -= edgeDirection.dot(normal) * normal;
        if (!edgeDirection.allFinite() || edgeDirection.norm() <= 0.0) {
          throw std::runtime_error(
              "Nonzero-Z4 torus chart oracle found a degenerate boundary edge.");
        }
        edgeDirection.normalize();
        const Eigen::Vector3d x =
            sourceCrossField.primaryDirections.row(side.face).transpose();
        const Eigen::Vector3d y =
            sourceCrossField.secondaryDirections.row(side.face).transpose();
        const std::array<Eigen::Vector3d, 4> branches{{x, y, -x, -y}};
        double bestAlignment = -2.0;
        double secondAlignment = -2.0;
        int bestLocalBranch = -1;
        for (int branch = 0; branch < 4; ++branch) {
          Eigen::Vector3d direction = branches[static_cast<std::size_t>(branch)];
          direction -= direction.dot(normal) * normal;
          if (!direction.allFinite() || direction.norm() <= 0.0) continue;
          direction.normalize();
          const double alignment = direction.dot(edgeDirection);
          if (alignment > bestAlignment) {
            secondAlignment = bestAlignment;
            bestAlignment = alignment;
            bestLocalBranch = branch;
          } else if (alignment > secondAlignment) {
            secondAlignment = alignment;
          }
        }
        const double ambiguityTolerance =
            256.0 * std::numeric_limits<double>::epsilon() *
            std::max(1.0, std::abs(bestAlignment));
        if (bestLocalBranch < 0 || !(bestAlignment > kBoundaryAlignment) ||
            std::abs(bestAlignment - secondAlignment) <= ambiguityTolerance) {
          throw std::runtime_error(
              "Nonzero-Z4 torus chart oracle rejected boundary alignment.");
        }
        oracle.minimumBoundaryAlignment =
            std::min(oracle.minimumBoundaryAlignment, bestAlignment);
        const int globalBranch = normalized_test_branch(
            bestLocalBranch -
            faceBranchRotation[static_cast<std::size_t>(side.face)]);
        auto &ownedBranch = forward ? forwardBranch : reverseBranch;
        if (ownedBranch.has_value() && *ownedBranch != globalBranch) {
          throw std::runtime_error(
              "Nonzero-Z4 torus chart oracle found a split branch run.");
        }
        ownedBranch = globalBranch;
      }
    }
    if (!forwardBranch.has_value() || !reverseBranch.has_value() ||
        !(cycleLength > 0.0) || !std::isfinite(cycleLength)) {
      throw std::runtime_error(
          "Nonzero-Z4 torus chart oracle found an incomplete hard-edge cycle.");
    }
    return std::tuple<int, int, double>{*forwardBranch, *reverseBranch,
                                        cycleLength};
  };

  const auto [majorForward, majorReverse, majorLength] =
      classify_cycle(majorCycle);
  const auto [minorForward, minorReverse, minorLength] =
      classify_cycle(minorCycle);
  const int globalQuarterTurn = majorForward;
  oracle.canonicalRunBranches = {
      0, normalized_test_branch(minorForward - globalQuarterTurn),
      normalized_test_branch(majorReverse - globalQuarterTurn),
      normalized_test_branch(minorReverse - globalQuarterTurn)};
  oracle.runLengths = {majorLength, minorLength, majorLength, minorLength};
  if (oracle.canonicalRunBranches != std::vector<int>({0, 1, 2, 3})) {
    throw std::runtime_error(
        "Nonzero-Z4 torus chart oracle rejected the canonical [0,1,2,3] runs.");
  }

  for (std::size_t run = 0U; run < oracle.canonicalRunBranches.size(); ++run) {
    const int delta = normalized_test_branch(
        oracle.canonicalRunBranches[(run + 1U) % 4U] -
        oracle.canonicalRunBranches[run]);
    if (delta == 1) {
      ++oracle.signedQuarterTurnSum;
    } else if (delta == 3) {
      --oracle.signedQuarterTurnSum;
    } else {
      throw std::runtime_error(
          "Nonzero-Z4 torus chart oracle found a non-quarter boundary turn.");
    }
  }
  if (oracle.signedQuarterTurnSum != 4) {
    throw std::runtime_error(
        "Nonzero-Z4 torus chart oracle rejected the +4 boundary turn sum.");
  }

  const std::array<Eigen::Vector2d, 4> chartDirections{{
      Eigen::Vector2d(1.0, 0.0), Eigen::Vector2d(0.0, 1.0),
      Eigen::Vector2d(-1.0, 0.0), Eigen::Vector2d(0.0, -1.0)}};
  double totalIntrinsicLength = 0.0;
  for (std::size_t run = 0U; run < oracle.runLengths.size(); ++run) {
    oracle.closureResidual += oracle.runLengths[run] * chartDirections[run];
    totalIntrinsicLength += oracle.runLengths[run];
  }
  oracle.closureTolerance =
      1.0e-10 * std::max(1.0, totalIntrinsicLength);
  if (oracle.closureResidual.norm() > oracle.closureTolerance) {
    throw std::runtime_error(
        "Nonzero-Z4 torus chart oracle rejected orthogonal chart closure.");
  }
  return oracle;
}

std::optional<directional::authority::SourceFaceId>
source_face_for_boundary_occurrence(
    const directional::TriMesh &mesh,
    const directional::geometry::SourceTopologyRegions &sourceAuthority,
    const directional::geometry::GlobalTopologyPlan &plan,
    const directional::geometry::SurfaceBoundaryOccurrenceId &occurrence,
    const directional::authority::NetworkArcId span,
    const directional::authority::SourceEdgeTopologyKey &carrier) {
  const auto region = std::find_if(
      plan.regions().begin(), plan.regions().end(), [&](const auto &candidate) {
        return candidate.id == occurrence.region;
      });
  if (region == plan.regions().end() ||
      occurrence.canonicalBoundaryOccurrenceOrdinal >= region->boundary.size()) {
    return std::nullopt;
  }
  const auto &orientedArc =
      region->boundary[occurrence.canonicalBoundaryOccurrenceOrdinal];
  if (orientedArc.arc != span) return std::nullopt;
  const auto *arc = plan.find_arc(span);
  if (arc == nullptr || arc->kind != directional::geometry::GlobalTopologyArcKind::Mandatory ||
      arc->sourcePath.size() != 1U) {
    return std::nullopt;
  }
  const auto orientedPath = directional::authority::exact_source_path_for_orientation(
      arc->sourcePath, orientedArc.orientation);
  if (orientedPath.size() != 1U) return std::nullopt;
  const auto *pathCarrier =
      std::get_if<directional::authority::SourceEdgeSupport>(
          &orientedPath.front().carrier);
  const auto *first = std::get_if<directional::authority::SourceVertexId>(
      &orientedPath.front().first);
  const auto *second = std::get_if<directional::authority::SourceVertexId>(
      &orientedPath.front().second);
  if (pathCarrier == nullptr || pathCarrier->edge != carrier || first == nullptr ||
      second == nullptr || *first == *second) {
    return std::nullopt;
  }

  std::set<directional::authority::SourceFaceId> activeFaces;
  for (const auto &topology : region->sourceFaces) {
    const auto row = sourceAuthority.row_for_topology(topology);
    if (!row.has_value()) return std::nullopt;
    activeFaces.insert(*row);
  }

  std::optional<directional::authority::SourceFaceId> owner;
  for (const auto candidate : activeFaces) {
    const int face = static_cast<int>(candidate.index());
    bool oriented = false;
    for (int corner = 0; corner < 3; ++corner) {
      if (mesh.F(face, corner) == static_cast<int>(first->index()) &&
          mesh.F(face, (corner + 1) % 3) ==
              static_cast<int>(second->index())) {
        oriented = true;
        break;
      }
    }
    if (!oriented) continue;
    if (owner.has_value()) return std::nullopt;
    owner = candidate;
  }
  return owner;
}

std::vector<ProducedTorusSourceWitness> enumerate_torus_source_witnesses(
    const directional::TriMesh &mesh,
    const directional::fields::CrossFieldResult &sourceCrossField,
    const directional::authority::FieldTransportAtlas &atlas,
    const directional::geometry::SourceTopologyRegions &sourceAuthority,
    const directional::geometry::GlobalTopologyPlan &plan,
    const std::set<directional::authority::SourceEdgeTopologyKey>
        &nonzeroHardCarriers) {
  const auto sourceIncidence =
      directional::geometry::surface_cell_tracing_detail::edge_faces(mesh.F);
  const auto sourceMatchingIndices = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);

  std::vector<ProducedTorusSourceWitness> candidates;
  for (const auto carrier : nonzeroHardCarriers) {
    for (const auto &region : plan.regions()) {
      std::map<directional::authority::NetworkArcId,
               std::vector<std::pair<std::size_t,
                                     directional::authority::Orientation>>>
          occurrences;
      for (std::size_t ordinal = 0U; ordinal < region.boundary.size(); ++ordinal) {
        const auto &incidence = region.boundary[ordinal];
        const auto *arc = plan.find_arc(incidence.arc);
        if (arc == nullptr ||
            arc->kind != directional::geometry::GlobalTopologyArcKind::Mandatory ||
            arc->sourcePath.size() != 1U) {
          continue;
        }
        const auto *pathCarrier =
            std::get_if<directional::authority::SourceEdgeSupport>(
                &arc->sourcePath.front().carrier);
        if (pathCarrier == nullptr || pathCarrier->edge != carrier) continue;
        occurrences[incidence.arc].push_back({ordinal, incidence.orientation});
      }

      for (const auto &[span, values] : occurrences) {
        if (values.size() != 2U) continue;
        std::optional<std::size_t> forwardOrdinal;
        std::optional<std::size_t> reverseOrdinal;
        for (const auto &[ordinal, orientation] : values) {
          if (orientation == directional::authority::Orientation::Forward) {
            if (forwardOrdinal.has_value()) {
              forwardOrdinal.reset();
              break;
            }
            forwardOrdinal = ordinal;
          } else {
            if (reverseOrdinal.has_value()) {
              reverseOrdinal.reset();
              break;
            }
            reverseOrdinal = ordinal;
          }
        }
        if (!forwardOrdinal.has_value() || !reverseOrdinal.has_value()) continue;

        const directional::geometry::SurfaceBoundaryOccurrenceId fromOccurrence{
            region.id, *forwardOrdinal};
        const directional::geometry::SurfaceBoundaryOccurrenceId toOccurrence{
            region.id, *reverseOrdinal};
        const auto fromFace = source_face_for_boundary_occurrence(
            mesh, sourceAuthority, plan, fromOccurrence, span, carrier);
        const auto toFace = source_face_for_boundary_occurrence(
            mesh, sourceAuthority, plan, toOccurrence, span, carrier);
        if (!fromFace.has_value() || !toFace.has_value() ||
            *fromFace == *toFace) {
          continue;
        }

        const auto sourceRotation = directed_source_transition(
            mesh, sourceCrossField, carrier, *fromFace, *toFace);
        const auto atlasValue =
            atlas.transition_value(carrier, *fromFace, *toFace);
        if (!sourceRotation.has_value() || !atlasValue.has_value() ||
            *sourceRotation == directional::authority::QuarterTurn{} ||
            atlasValue->transport != *sourceRotation) {
          continue;
        }

        const auto *arc = plan.find_arc(span);
        if (arc == nullptr || arc->sourcePath.size() != 1U) continue;
        const auto firstParameter = test_exact_edge_parameter(
            arc->sourcePath.front().first, carrier);
        const auto secondParameter = test_exact_edge_parameter(
            arc->sourcePath.front().second, carrier);
        if (!firstParameter.has_value() || !secondParameter.has_value() ||
            *firstParameter == *secondParameter) {
          continue;
        }
        const auto sourcePathOrientation =
            *firstParameter < *secondParameter
                ? directional::authority::Orientation::Forward
                : directional::authority::Orientation::Reverse;
        const auto transitionIndex = sourceMatchingIndices.find(carrier);
        if (transitionIndex == sourceMatchingIndices.end()) continue;
        const auto transitionId =
            directional::authority::InteriorTransitionId::from_index(
                transitionIndex->second, sourceMatchingIndices.size());
        if (!transitionId) continue;
        directional::authority::GridAutomorphism transport =
            directional::authority::GridAutomorphism::identity();
        transport.rotation = *sourceRotation;
        const auto step = directional::authority::TransitionStep::interior(
            carrier, transitionId.value(), transport, sourcePathOrientation);
        if (!step) continue;
        auto generatorRoute =
            directional::authority::CanonicalRoute::from_observed_steps(
                {step.value()});
        if (generatorRoute.empty() ||
            generatorRoute.composed_transport().rotation != *sourceRotation) {
          continue;
        }
        candidates.push_back(ProducedTorusSourceWitness{
            carrier,
            span,
            region.id,
            fromOccurrence,
            toOccurrence,
            *fromFace,
            *toFace,
            *sourceRotation,
            atlasValue->transport,
            sourcePathOrientation,
            std::move(generatorRoute)});
      }
    }
  }
  return candidates;
}

ProducedTorusWitnessFixture make_nonzero_z4_torus_witness_fixture() {
  PhaseFrontFixture fixture;
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/torus.obj");
  if (!directional::readOBJ(meshPath.string(), fixture.mesh)) {
    throw std::runtime_error("Failed to read committed torus fixture.");
  }
  const Eigen::MatrixXd raw = torus_nonzero_z4_raw_field(fixture.mesh);
  const auto sourceCrossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(fixture.mesh,
                                                                    raw);
  const auto hardEdges = torus_row408_hard_edges(fixture.mesh);
  std::set<directional::authority::SourceEdgeTopologyKey> nonzeroHardCarriers;
  for (const auto &carrier : hardEdges) {
    const auto *transition =
        source_transition_for(fixture.mesh, sourceCrossField, carrier);
    if (transition != nullptr &&
        directional::authority::QuarterTurn::from_integer(
            transition->matching) != directional::authority::QuarterTurn{}) {
      nonzeroHardCarriers.insert(carrier);
    }
  }
  if (nonzeroHardCarriers.empty()) {
    throw std::runtime_error(
        "Torus winding field did not produce a nonzero-Z4 row408 hard edge.");
  }
  const TorusChartAdmissibilityOracle chartOracle =
      validate_nonzero_z4_torus_chart_subject(
          fixture.mesh, raw, sourceCrossField, hardEdges);
  (void)chartOracle;

  directional::pipeline::RemeshOptions options;
  options.lengthRatio = 0.2;
  options.integralSeamless = false;
  options.roundSeams = false;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.featureMap.cadAbsoluteLowDegrees = 179.0;
  options.surfaceCells.featureMap.cadAbsoluteHighDegrees = 180.0;
  options.surfaceCells.featureMap.organicAbsoluteLowDegrees = 179.0;
  options.surfaceCells.featureMap.organicAbsoluteHighDegrees = 180.0;
  for (const auto &edge : hardEdges) {
    options.surfaceCells.featureMap.userHardEdges.insert(
        {static_cast<int>(edge.first().index()),
         static_cast<int>(edge.second().index())});
  }

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      fixture.mesh.V, fixture.mesh.F, raw, options);
  const auto &snapshots = result.surfaceCellContext.productSnapshots;
  if (!snapshots.hasCrossField || !snapshots.hasSourceSurfaceLabels ||
      !snapshots.fieldTransportAtlas.has_value() ||
      !snapshots.globalTopologyPlan.has_value() ||
      !snapshots.sourceTopologyRegions.has_value() ||
      !result.surfaceCellContext.hasTraceNetwork) {
    throw std::runtime_error(
        "Nonzero-Z4 torus pipeline did not retain source/A3 witness authority.");
  }
  fixture.components = snapshots.sourceSurfaceLabels.componentByFace;
  fixture.sheets = snapshots.sourceSurfaceLabels.localSheetByFace;
  fixture.network = snapshots.traceNetwork;
  require_produced(fixture, "torus nonzero-Z4 source witness");

  // D1: enumerate real source/A3 generators before selecting a reciprocal
  // tracer-produced Periodic relation. Source matching alone is insufficient.
  const auto candidates = enumerate_torus_source_witnesses(
      fixture.mesh, sourceCrossField, *snapshots.fieldTransportAtlas,
      *snapshots.sourceTopologyRegions, *snapshots.globalTopologyPlan,
      nonzeroHardCarriers);
  const auto &front = fixture.network.phaseFront.product();
  std::optional<ProducedTorusSourceWitness> witness;
  for (const auto &candidate : candidates) {
    const auto &rotations = front.sourceFaceBranchRotations();
    if (candidate.fromFace.index() >= rotations.size() ||
        candidate.toFace.index() >= rotations.size()) {
      continue;
    }
    const int delta =
        (rotations[candidate.toFace.index()] -
         rotations[candidate.fromFace.index()] + 4) % 4;
    if (delta != 1 && delta != 3) continue;

    const directional::geometry::SurfaceFrontEdge *forward = nullptr;
    const directional::geometry::SurfaceFrontEdge *reverse = nullptr;
    for (const auto &edge : front.edges()) {
      if (edge.boundaryKind != SurfaceFrontBoundaryKind::PeriodicCut ||
          !edge.periodicRelation.has_value() ||
          !edge.sharedBoundaryInterval.has_value() ||
          !edge.sharedBoundaryInterval->boundaryOccurrence.has_value() ||
          edge.sharedBoundaryInterval->span != candidate.span) {
        continue;
      }
      if (*edge.sharedBoundaryInterval->boundaryOccurrence ==
              candidate.fromOccurrence &&
          edge.sharedBoundaryInterval->orientation ==
              directional::authority::Orientation::Forward) {
        if (forward != nullptr) { forward = nullptr; break; }
        forward = &edge;
      } else if (*edge.sharedBoundaryInterval->boundaryOccurrence ==
                     candidate.toOccurrence &&
                 edge.sharedBoundaryInterval->orientation ==
                     directional::authority::Orientation::Reverse) {
        if (reverse != nullptr) { reverse = nullptr; break; }
        reverse = &edge;
      }
    }
    if (forward == nullptr || reverse == nullptr ||
        forward->periodicRelation != reverse->periodicRelation ||
        reverse->route != forward->route.reversed()) {
      continue;
    }
    const auto stored = std::find_if(
        front.periodicHolonomies().begin(), front.periodicHolonomies().end(),
        [&](const auto &relation) {
          return relation.id() == *forward->periodicRelation;
        });
    if (stored == front.periodicHolonomies().end() ||
        !directional::geometry::resolve_periodic_relation_semantic_action(
             *stored, *forward, *reverse).has_value() ||
        !(stored->cutRoute() == forward->route ||
          stored->cutRoute().reversed() == forward->route)) {
      continue;
    }
    witness = candidate;
    break;
  }
  if (!witness.has_value()) {
    throw std::runtime_error(
        "No tracer-produced reciprocal periodic torus witness with "
        "an exact source/A3 generator and odd selected-face gauge delta.");
  }

  const auto *pipelineTransition =
      source_transition_for(fixture.mesh, snapshots.crossField,
                            witness->carrier);
  const auto *sourceTransition =
      source_transition_for(fixture.mesh, sourceCrossField, witness->carrier);
  if (pipelineTransition == nullptr || sourceTransition == nullptr ||
      pipelineTransition->matching != sourceTransition->matching ||
      pipelineTransition->firstFace != sourceTransition->firstFace ||
      pipelineTransition->secondFace != sourceTransition->secondFace) {
    throw std::runtime_error(
        "Pipeline source transition diverged from the pre-finalized witness.");
  }
  return {std::move(fixture), *witness};
}

const ProducedTorusWitnessFixture &nonzero_z4_torus_witness_fixture() {
  static const ProducedTorusWitnessFixture fixture =
      make_nonzero_z4_torus_witness_fixture();
  return fixture;
}

AuthoritativePhaseFrontMeshResult materialize(
    const PhaseFrontFixture &fixture, const SurfacePhaseFrontResult &phaseFront) {
  return directional::pipeline::build_authoritative_phase_front_mesh(
      fixture.mesh.V, fixture.mesh.F, phaseFront.product());
}

struct PhaseFrontDraft {
  int gridU = 0;
  int gridV = 0;
  directional::geometry::SourceTopologyRegions sourceAuthority;
  std::vector<directional::geometry::SurfaceIsolationSeamTransportCertificate>
      certificates;
  std::vector<directional::geometry::SurfacePeriodicHolonomy> periodicHolonomies;
  std::vector<directional::geometry::SurfaceBoundedDiskBoundaryPhase>
      boundedDiskBoundaryPhases;
  std::vector<directional::geometry::SurfaceFrontEdge> edges;
  std::vector<directional::geometry::SurfaceFrontEvent> events;
  std::vector<directional::geometry::SurfacePhaseFrontCell> cells;
  std::set<directional::authority::SourceEdgeTopologyKey> hardFeatureEdges;
  std::vector<int> sourceFaceBranchRotations;
  std::vector<directional::geometry::SurfaceHardRailFieldTransition>
      hardRailFieldTransitions;
  std::vector<directional::geometry::SurfaceHardRailRouteCertificate>
      hardRailRouteCertificates;
};
PhaseFrontDraft direct_full_periodic_materializer_draft(); bool action_has_nonzero_turn(const directional::authority::GridAutomorphism &action);
PhaseFrontDraft phase_front_draft(
    const directional::geometry::SurfacePhaseFrontProduct &product) {
  return {product.gridU(),
          product.gridV(),
          product.sourceTopologyRegions(),
          product.isolationSeamTransportCertificates(),
          product.periodicHolonomies(),
          product.boundedDiskBoundaryPhases(),
          product.edges(),
          product.events(),
          product.cells(),
          product.hardFeatureEdges(),
          product.sourceFaceBranchRotations(),
          product.hardRailFieldTransitions(),
          product.hardRailRouteCertificates()};
}

PhaseFrontDraft phase_front_draft(const SurfacePhaseFrontResult &phaseFront) {
  return phase_front_draft(phaseFront.product());
}

directional::geometry::SurfacePhaseFrontProduct::ConstructionResult
construct_phase_front_product(PhaseFrontDraft draft) {
  return directional::geometry::SurfacePhaseFrontProduct::make(
      draft.gridU, draft.gridV, std::move(draft.sourceAuthority),
      std::move(draft.certificates), std::move(draft.periodicHolonomies),
      std::move(draft.boundedDiskBoundaryPhases), std::move(draft.edges),
      std::move(draft.events), std::move(draft.cells), std::nullopt,
      std::move(draft.hardFeatureEdges),
      std::move(draft.sourceFaceBranchRotations),
      std::move(draft.hardRailFieldTransitions),
      std::move(draft.hardRailRouteCertificates));
}

void expect_phase_front_product_error(
    const directional::geometry::SurfacePhaseFrontProduct::ConstructionResult
        &construction,
    const directional::geometry::SurfacePhaseFrontProductErrorCode expected) {
  const auto *error =
      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
          &construction);
  EXPECT_NE(nullptr, error);
  if (error != nullptr) {
    EXPECT_EQ(expected, error->code);
  }
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     EmptyCellsRejectAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(square_fixture().network.phaseFront);
  ASSERT_FALSE(tampered.cells.empty());
  tampered.cells.clear();
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::EmptyCells);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     EmptyEdgesRejectAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(square_fixture().network.phaseFront);
  ASSERT_FALSE(tampered.cells.empty());
  ASSERT_FALSE(tampered.edges.empty());
  tampered.edges.clear();
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::EmptyEdges);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     DuplicateCellIdentityRejectsAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(square_fixture().network.phaseFront);
  ASSERT_FALSE(tampered.cells.empty());
  tampered.cells.push_back(tampered.cells.front());
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::DuplicateCellId);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     ReorderedCellStoragePreservesTypedEdgeOwnershipAtCheckedFactory) {
  PhaseFrontDraft reordered = phase_front_draft(square_fixture().network.phaseFront);
  ASSERT_GT(reordered.cells.size(), 1U);
  std::reverse(reordered.cells.begin(), reordered.cells.end());
  const auto construction = construct_phase_front_product(std::move(reordered));
  const auto *product =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&construction);
  ASSERT_NE(nullptr, product);
  EXPECT_EQ(square_fixture().network.phaseFront.product().cells().size(),
            product->cells().size());
  for (const auto &edge : product->edges()) {
    const auto owner = std::find_if(
        product->cells().begin(), product->cells().end(),
        [&](const auto &cell) { return cell.id == edge.filledCell; });
    EXPECT_NE(product->cells().end(), owner);
  }
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     ForeignEdgeCellRejectsAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(square_fixture().network.phaseFront);
  ASSERT_FALSE(tampered.cells.empty());
  ASSERT_FALSE(tampered.edges.empty());
  const auto foreign = directional::authority::CellId::from_index(
      static_cast<std::int64_t>(tampered.cells.size()),
      tampered.cells.size() + 1U);
  ASSERT_TRUE(foreign.has_value());
  tampered.edges.front().filledCell = foreign.value();
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidEdgeCell);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     ForeignEventEdgeRejectsAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(square_fixture().network.phaseFront);
  ASSERT_FALSE(tampered.edges.empty());
  directional::geometry::SurfaceFrontEvent malformed;
  malformed.kind = directional::geometry::SurfaceFrontEventKind::BoundaryTermination;
  malformed.firstEdge = static_cast<int>(tampered.edges.size());
  malformed.secondEdge = -1;
  tampered.events.push_back(malformed);
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidEventEdge);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     DuplicatePeriodicRelationIdentityRejectsAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(direct_periodic_owner_product());
  ASSERT_GE(tampered.periodicHolonomies.size(), 2U);
  const auto duplicate = tampered.periodicHolonomies.front();
  const auto expectedCarrier = independent_periodic_carrier_identity(
      duplicate.route(), duplicate.cutRoute());
  EXPECT_EQ(expectedCarrier.first, duplicate.id().generator_carrier());
  EXPECT_EQ(expectedCarrier.second, duplicate.id().cut_carrier());
  tampered.periodicHolonomies.push_back(duplicate);

  PhaseFrontDraft reordered = tampered;
  std::reverse(reordered.periodicHolonomies.begin(),
               reordered.periodicHolonomies.end());
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          DuplicatePeriodicRelationId);
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(reordered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          DuplicatePeriodicRelationId);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     ConflictingPeriodicRelationValueRejectsAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(direct_periodic_owner_product());
  ASSERT_FALSE(tampered.periodicHolonomies.empty());
  const auto &original = tampered.periodicHolonomies.front();
  const auto expectedCarrier = independent_periodic_carrier_identity(
      original.route(), original.cutRoute());
  EXPECT_EQ(expectedCarrier.first, original.id().generator_carrier());
  EXPECT_EQ(expectedCarrier.second, original.id().cut_carrier());

  auto action = original.action();
  ++action.shift.x;
  auto rebuilt = directional::geometry::SurfacePeriodicHolonomy::make(
      original.sourceTopologyRegion(), action, original.route(),
      original.cutRoute());
  const auto *conflicting =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&rebuilt);
  ASSERT_NE(nullptr, conflicting);
  ASSERT_EQ(original.id(), conflicting->id());
  ASSERT_NE(original.action(), conflicting->action());
  tampered.periodicHolonomies.push_back(*conflicting);

  PhaseFrontDraft reordered = tampered;
  std::reverse(reordered.periodicHolonomies.begin(),
               reordered.periodicHolonomies.end());
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          ConflictingPeriodicRelation);
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(reordered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          ConflictingPeriodicRelation);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     ForeignPeriodicRelationRegionRejectsAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(direct_periodic_owner_product());
  ASSERT_FALSE(tampered.periodicHolonomies.empty());
  const auto regionCount = tampered.sourceAuthority.regions().size();
  const auto foreignRegion = directional::authority::TopologyRegionId::from_index(
      static_cast<std::int64_t>(regionCount), regionCount + 1U);
  ASSERT_TRUE(foreignRegion.has_value());
  const auto &original = tampered.periodicHolonomies.front();
  auto rebuilt = directional::geometry::SurfacePeriodicHolonomy::make(
      foreignRegion.value(), original.action(), original.route(),
      original.cutRoute());
  auto *rebuiltValue =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&rebuilt);
  ASSERT_NE(nullptr, rebuiltValue);
  tampered.periodicHolonomies.front() = std::move(*rebuiltValue);
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          InvalidPeriodicRelationRegion);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     UnknownPeriodicRelationOwnerRejectsAtCheckedFactory) {
  PhaseFrontDraft tampered = phase_front_draft(direct_periodic_owner_product());
  ASSERT_FALSE(tampered.periodicHolonomies.empty());
  ASSERT_FALSE(tampered.edges.empty());
  ASSERT_EQ(SurfaceFrontBoundaryKind::PeriodicCut,
            tampered.edges.front().boundaryKind);
  const auto unknownRoute = test_interior_route(40, 41, 40);
  const auto unknownCutRoute = test_interior_route(42, 43, 41);
  const auto unknownOwner = independent_periodic_relation_id(
      tampered.periodicHolonomies.front().sourceTopologyRegion(), unknownRoute,
      unknownCutRoute);
  ASSERT_TRUE(unknownOwner.has_value());
  const auto expectedCarrier =
      independent_periodic_carrier_identity(unknownRoute, unknownCutRoute);
  EXPECT_EQ(expectedCarrier.first, unknownOwner->generator_carrier());
  EXPECT_EQ(expectedCarrier.second, unknownOwner->cut_carrier());
  ASSERT_TRUE(std::none_of(
      tampered.periodicHolonomies.begin(), tampered.periodicHolonomies.end(),
      [&](const auto &relation) { return relation.id() == unknownOwner.value(); }));
  tampered.edges.front().periodicRelation = unknownOwner.value();
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          MissingPeriodicRelationOwner);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     NonReciprocalPeriodicRelationRejectsAtCheckedFactory) {
  PhaseFrontDraft tampered = direct_full_periodic_materializer_draft();
  std::size_t firstIndex = tampered.edges.size();
  for (std::size_t edgeIndex = 0; edgeIndex < tampered.edges.size(); ++edgeIndex) {
    const auto &edge = tampered.edges[edgeIndex];
    if (edge.boundaryKind == SurfaceFrontBoundaryKind::PeriodicCut &&
        edge.oppositeEdge > static_cast<int>(edgeIndex)) {
      firstIndex = edgeIndex;
      break;
    }
  }
  ASSERT_LT(firstIndex, tampered.edges.size());
  const std::size_t secondIndex = static_cast<std::size_t>(
      tampered.edges[firstIndex].oppositeEdge);
  ASSERT_LT(secondIndex, tampered.edges.size());
  const auto &first = tampered.edges[firstIndex];
  const auto beforeCarrier =
      independent_periodic_route_carrier(tampered.edges[secondIndex].route);
  auto expectedReverseCarrier = independent_periodic_route_carrier(first.route);
  std::reverse(expectedReverseCarrier.begin(), expectedReverseCarrier.end());
  EXPECT_EQ(expectedReverseCarrier, beforeCarrier);
  EXPECT_EQ(independent_route_transport(first.route).inverse(),
            independent_route_transport(tampered.edges[secondIndex].route));

  tampered.edges[secondIndex].route =
      tamper_route_transport_preserving_carrier(
          tampered.edges[secondIndex].route);
  EXPECT_EQ(beforeCarrier, independent_periodic_route_carrier(
                               tampered.edges[secondIndex].route));
  EXPECT_NE(independent_route_transport(first.route).inverse(),
            independent_route_transport(tampered.edges[secondIndex].route));
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          NonReciprocalPeriodicRelation);
}

TEST(SurfacePhaseFrontProductFactoryAuthority,
     RepresentationRenumberedPeriodicRelationRejectsAtCheckedFactory) {
  PhaseFrontDraft baseline = direct_full_periodic_materializer_draft();
  std::size_t firstIndex = baseline.edges.size();
  for (std::size_t edgeIndex = 0; edgeIndex < baseline.edges.size(); ++edgeIndex) {
    const auto &edge = baseline.edges[edgeIndex];
    if (edge.boundaryKind == SurfaceFrontBoundaryKind::PeriodicCut &&
        edge.oppositeEdge > static_cast<int>(edgeIndex)) {
      firstIndex = edgeIndex;
      break;
    }
  }
  ASSERT_LT(firstIndex, baseline.edges.size());
  const std::size_t secondIndex =
      static_cast<std::size_t>(baseline.edges[firstIndex].oppositeEdge);
  ASSERT_LT(secondIndex, baseline.edges.size());
  ASSERT_TRUE(baseline.edges[firstIndex].periodicRelation.has_value());
  const auto originalId = *baseline.edges[firstIndex].periodicRelation;
  const auto owner = std::find_if(
      baseline.periodicHolonomies.begin(), baseline.periodicHolonomies.end(),
      [&](const auto &relation) { return relation.id() == originalId; });
  ASSERT_NE(baseline.periodicHolonomies.end(), owner);
  const auto expectedCarrier =
      independent_periodic_carrier_identity(owner->route(), owner->cutRoute());
  EXPECT_EQ(expectedCarrier.first, originalId.generator_carrier());
  EXPECT_EQ(expectedCarrier.second, originalId.cut_carrier());

  auto unusedConstruction = directional::geometry::SurfacePeriodicHolonomy::make(
      owner->sourceTopologyRegion(), owner->action(), owner->cutRoute(),
      owner->route());
  const auto *unused =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(
          &unusedConstruction);
  ASSERT_NE(nullptr, unused);
  ASSERT_NE(originalId, unused->id());
  baseline.periodicHolonomies.push_back(*unused);
  const auto baselineConstruction = construct_phase_front_product(baseline);
  ASSERT_NE(nullptr,
            std::get_if<directional::geometry::SurfacePhaseFrontProduct>(
                &baselineConstruction));

  PhaseFrontDraft tampered = baseline;
  tampered.edges[firstIndex].periodicRelation = unused->id();
  tampered.edges[secondIndex].periodicRelation = unused->id();
  PhaseFrontDraft reordered = tampered;
  std::reverse(reordered.periodicHolonomies.begin(),
               reordered.periodicHolonomies.end());
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          RepresentationRenumberedPeriodicRelation);
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(reordered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          RepresentationRenumberedPeriodicRelation);
}

SurfacePhaseFrontResult publish_phase_front_draft(PhaseFrontDraft draft) {
  auto construction = construct_phase_front_product(std::move(draft));
  auto *product = std::get_if<directional::geometry::SurfacePhaseFrontProduct>(
      &construction);
  if (product == nullptr) {
    throw std::runtime_error("Malformed phase-front draft rejected at publication.");
  }
  return SurfacePhaseFrontResult::produced(std::move(*product));
}

AuthoritativePhaseFrontMeshResult materialize(
    const PhaseFrontFixture &fixture, PhaseFrontDraft draft) {
  auto construction = construct_phase_front_product(std::move(draft));
  auto *product = std::get_if<directional::geometry::SurfacePhaseFrontProduct>(
      &construction);
  if (product == nullptr) {
    AuthoritativePhaseFrontMeshResult result;
    result.failure = "InvalidPhaseFrontProduct";
    return result;
  }
  return directional::pipeline::build_authoritative_phase_front_mesh(
      fixture.mesh.V, fixture.mesh.F, *product);
}

std::vector<directional::geometry::SelectedRelationPathCertificate>
selected_relation_certificate_signature(
    const directional::geometry::PureQuadMesh &mesh) {
  std::vector<directional::geometry::SelectedRelationPathCertificate> result;
  for (const auto &lineage : mesh.vertexLineage) {
    result.insert(result.end(), lineage.selectedRelationPaths.begin(),
                  lineage.selectedRelationPaths.end());
  }
  std::sort(result.begin(), result.end());
  return result;
}

const directional::geometry::SurfacePeriodicHolonomy *
produced_relation_for_witness(const ProducedTorusWitnessFixture &fixture) {
  const auto &product = fixture.fixture.network.phaseFront.product();
  std::optional<directional::authority::PeriodicRelationId> ownerId;
  bool sawFrom = false;
  bool sawTo = false;
  for (const auto &edge : product.edges()) {
    if (!edge.sharedBoundaryInterval.has_value() ||
        !edge.sharedBoundaryInterval->boundaryOccurrence.has_value() ||
        edge.sharedBoundaryInterval->span != fixture.witness.span) {
      continue;
    }
    const auto occurrence =
        *edge.sharedBoundaryInterval->boundaryOccurrence;
    if (occurrence != fixture.witness.fromOccurrence &&
        occurrence != fixture.witness.toOccurrence) {
      continue;
    }
    if (edge.boundaryKind != SurfaceFrontBoundaryKind::PeriodicCut ||
        !edge.periodicRelation.has_value()) {
      return nullptr;
    }
    if (ownerId.has_value() && *ownerId != *edge.periodicRelation) {
      return nullptr;
    }
    ownerId = *edge.periodicRelation;
    sawFrom = sawFrom || occurrence == fixture.witness.fromOccurrence;
    sawTo = sawTo || occurrence == fixture.witness.toOccurrence;
  }
  if (!ownerId.has_value() || !sawFrom || !sawTo) return nullptr;
  const auto relation = std::find_if(
      product.periodicHolonomies().begin(), product.periodicHolonomies().end(),
      [&](const auto &candidate) { return candidate.id() == *ownerId; });
  return relation == product.periodicHolonomies().end() ? nullptr : &*relation;
}

struct ProducedTorusSemanticPeriodicRelation {
  const directional::geometry::SurfacePeriodicHolonomy *storedRelation = nullptr;
  const directional::geometry::SurfaceFrontEdge *forwardEdge = nullptr;
  const directional::geometry::SurfaceFrontEdge *reverseEdge = nullptr;
  directional::authority::GridAutomorphism semanticAction;
  directional::authority::CanonicalRoute semanticGeneratorRoute;
  bool storageInverted = false;
};

std::optional<ProducedTorusSemanticPeriodicRelation>
produced_semantic_relation_for_witness(
    const ProducedTorusWitnessFixture &fixture) {
  const auto *relation = produced_relation_for_witness(fixture);
  if (relation == nullptr) return std::nullopt;

  const auto &product = fixture.fixture.network.phaseFront.product();
  const directional::geometry::SurfaceFrontEdge *forwardEdge = nullptr;
  const directional::geometry::SurfaceFrontEdge *reverseEdge = nullptr;
  for (const auto &edge : product.edges()) {
    if (edge.periodicRelation != relation->id() ||
        !edge.sharedBoundaryInterval.has_value() ||
        !edge.sharedBoundaryInterval->boundaryOccurrence.has_value() ||
        edge.sharedBoundaryInterval->span != fixture.witness.span) {
      continue;
    }

    const auto occurrence =
        *edge.sharedBoundaryInterval->boundaryOccurrence;
    const auto orientation = edge.sharedBoundaryInterval->orientation;
    if (occurrence == fixture.witness.fromOccurrence &&
        orientation == directional::authority::Orientation::Forward) {
      if (forwardEdge != nullptr) return std::nullopt;
      forwardEdge = &edge;
    } else if (occurrence == fixture.witness.toOccurrence &&
               orientation == directional::authority::Orientation::Reverse) {
      if (reverseEdge != nullptr) return std::nullopt;
      reverseEdge = &edge;
    }
  }
  if (forwardEdge == nullptr || reverseEdge == nullptr) return std::nullopt;

  const auto semanticAction =
      directional::geometry::resolve_periodic_relation_semantic_action(
          *relation, *forwardEdge, *reverseEdge);
  if (!semanticAction.has_value()) return std::nullopt;

  if (relation->cutRoute() == forwardEdge->route) {
    return ProducedTorusSemanticPeriodicRelation{
        relation, forwardEdge, reverseEdge, *semanticAction, relation->route(),
        false};
  }
  if (relation->cutRoute().reversed() == forwardEdge->route) {
    return ProducedTorusSemanticPeriodicRelation{
        relation, forwardEdge, reverseEdge, *semanticAction,
        relation->route().reversed(), true};
  }
  return std::nullopt;
}

bool certificate_references_periodic_relation(
    const std::vector<directional::geometry::SelectedRelationPathCertificate>
        &certificates,
    const directional::authority::PeriodicRelationId id) {
  return std::any_of(
      certificates.begin(), certificates.end(), [&](const auto &certificate) {
        return std::any_of(
            certificate.orderedSteps.begin(), certificate.orderedSteps.end(),
            [&](const auto &step) { return step.periodicRelation == id; });
      });
}

TEST(SurfaceCellTransitionQuotient,
     CellStoragePermutationPreservesOccurrenceAndQuotientAuthority) {
  const auto &fixture = square_fixture();
  PhaseFrontDraft baselineDraft = phase_front_draft(fixture.network.phaseFront);
  PhaseFrontDraft reorderedDraft = phase_front_draft(fixture.network.phaseFront);
  ASSERT_GT(reorderedDraft.cells.size(), 1U);
  std::reverse(reorderedDraft.cells.begin(), reorderedDraft.cells.end());

  const auto baseline = materialize(fixture, std::move(baselineDraft));
  const auto reordered = materialize(fixture, std::move(reorderedDraft));
  ASSERT_TRUE(baseline.success) << baseline.failure;
  ASSERT_TRUE(reordered.success) << reordered.failure;

  const auto authoritySignature = [](const auto &result) {
    using Entry = std::pair<
        std::optional<directional::authority::QuotientClassId>,
        std::vector<directional::authority::OccurrenceId>>;
    std::vector<Entry> signature;
    signature.reserve(result.mesh.vertexLineage.size());
    for (const auto &lineage : result.mesh.vertexLineage) {
      signature.emplace_back(lineage.quotientClass, lineage.sourceOccurrences);
    }
    std::sort(signature.begin(), signature.end());
    return signature;
  };

  EXPECT_EQ(authoritySignature(baseline), authoritySignature(reordered));
}

namespace {

const directional::pipeline::SurfaceOccurrence *m6cp3_occurrence_by_id(
    const directional::pipeline::SurfaceOccurrenceComplex &product,
    const directional::authority::OccurrenceId id) {
  const auto found = std::find_if(
      product.occurrences().begin(), product.occurrences().end(),
      [&](const auto &candidate) { return candidate.id == id; });
  return found == product.occurrences().end() ? nullptr : &*found;
}

const directional::pipeline::SurfaceOccurrenceRelation *m6cp3_seam_ordinary(
    const directional::pipeline::SurfaceOccurrenceComplex &product) {
  const auto found = std::find_if(
      product.owned_relations().begin(), product.owned_relations().end(),
      [](const auto &relation) {
        return relation.id.kind ==
                   directional::pipeline::SurfaceOccurrenceRelationKind::OrdinaryFront &&
               relation.evidence.firstEndpointSpan.has_value() &&
               relation.evidence.secondEndpointSpan.has_value() &&
               relation.evidence.firstEndpointSpan->collinearEdge.has_value() &&
               relation.evidence.firstEndpointSpan->collinearEdge ==
                   relation.evidence.secondEndpointSpan->collinearEdge &&
               // Raw/global span sheet-label IDs are not A4's typed wedge
               // incidence proof; neither equality nor inequality selects it.
               relation.evidence.isolationSeamTransportCertificate.has_value();
      });
  return found == product.owned_relations().end() ? nullptr : &*found;
}

// This is a source-produced, axis-aligned seam family, not an A5 record
// constructor. A real reciprocal seam relation must exist before a test can
// select one; no hand-authored relation is accepted as positive evidence.
PhaseFrontFixture make_axis_aligned_isolation_seam_fixture(
    const double targetSize) {
  PhaseFrontFixture fixture;
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 2.0, 0.0, 0.0,
      0.0, 1.0, 0.0, 1.0, 1.0, 0.0, 2.0, 1.0, 0.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 4, 0, 4, 3, 1, 2, 5, 1, 5, 4;
  fixture.mesh.set_mesh(vertices, faces);
  fixture.components = {0, 0, 0, 0};
  fixture.sheets = {0, 0, 1, 1};
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, constant_xy_field(faces.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = targetSize;
  options.sourceFaceComponents = fixture.components;
  options.sourceFaceSheets = fixture.sheets;
  fixture.network = directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField,
      Eigen::VectorXd::Constant(vertices.rows(), targetSize), options);
  return fixture;
}

std::unique_ptr<PhaseFrontFixture> m6cp3_produced_seam_fixture() {
  for (const double size : {0.25, 0.5, 1.0}) {
    auto fixture = std::make_unique<PhaseFrontFixture>(
        make_axis_aligned_isolation_seam_fixture(size));
    if (!fixture->network.phaseFront.is_produced()) continue;
    const auto &front = fixture->network.phaseFront.product();
    const auto a5Construction =
        directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
            fixture->mesh.V, fixture->mesh.F, front);
    const auto *a5 =
        std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
            &a5Construction);
    if (a5 == nullptr) continue;
    const auto *relation = m6cp3_seam_ordinary(*a5);
    if (relation == nullptr) continue;
    const auto *first = m6cp3_occurrence_by_id(*a5, relation->id.first);
    const auto *second = m6cp3_occurrence_by_id(*a5, relation->id.second);
    if (first == nullptr || second == nullptr ||
        !relation->evidence.isolationSeamTransportCertificate.has_value()) {
      continue;
    }
    std::vector<directional::authority::IsolationSheetId> shared;
    std::set_intersection(first->cornerWedgeSheets.begin(),
                          first->cornerWedgeSheets.end(),
                          second->cornerWedgeSheets.begin(),
                          second->cornerWedgeSheets.end(),
                          std::back_inserter(shared));
    if (!shared.empty()) continue;
    const auto a6Construction =
        directional::pipeline::SurfaceQuotientProducer::produce(*a5);
    const auto *a6 =
        std::get_if<directional::pipeline::SurfaceQuotientProduct>(
            &a6Construction);
    if (a6 == nullptr ||
        !std::any_of(a6->selected_forest().begin(),
                     a6->selected_forest().end(),
                     [&](const auto &edge) {
                       return edge.relation == relation->id;
                     })) {
      continue;
    }
    const auto a7Construction =
        directional::pipeline::SourceAttachedGeometryProducer::produce(
            fixture->mesh.V, fixture->mesh.F, *a5, *a6);
    if (std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
            &a7Construction) != nullptr) {
      return fixture;
    }
  }
  return nullptr;
}

} // namespace

TEST(M6CP3, PeriodicExactA3UnequalFaceGaugeUsesRelationAndOccurrenceAuthority) {
  const auto &fixture = nonzero_z4_torus_witness_fixture();
  const auto semantic = produced_semantic_relation_for_witness(fixture);
  ASSERT_TRUE(semantic.has_value());
  ASSERT_NE(semantic->forwardEdge, nullptr);
  ASSERT_NE(semantic->reverseEdge, nullptr);
  const auto &front = fixture.fixture.network.phaseFront.product();
  ASSERT_EQ(front.sourceFaceBranchRotations().size(),
            static_cast<std::size_t>(fixture.fixture.mesh.F.rows()));
  const int fromGauge = front.sourceFaceBranchRotations().at(
      static_cast<std::size_t>(fixture.witness.fromFace.index()));
  const int toGauge = front.sourceFaceBranchRotations().at(
      static_cast<std::size_t>(fixture.witness.toFace.index()));
  const int gaugeDelta = (toGauge - fromGauge + 4) % 4;
  ASSERT_TRUE(gaugeDelta == 1 || gaugeDelta == 3)
      << "D1 requires unequal non-self-inverse face gauge authority";

  const auto endpointGauge = [](const auto &placement, const auto &interval,
                                const auto relationRotation,
                                const auto &published)
      -> std::optional<directional::authority::GridAutomorphism> {
    const auto relationState =
        directional::geometry::make_periodic_relation_endpoint_state(
            placement, interval, relationRotation, published.branchAuthority);
    if (!relationState.has_value() || relationState.value() != published) {
      return std::nullopt;
    }
    const auto placementBranch =
        directional::authority::QuarterTurn::from_integer(
            placement.branchRotation);
    const auto rotation =
        compose(relationState->branchRotation, placementBranch.inverse());
    return directional::authority::GridAutomorphism{
        rotation,
        relationState->latticeCoordinate -
            directional::authority::rotate(rotation,
                                           placement.latticeCoordinate)};
  };
  const auto *forward = semantic->forwardEdge;
  const auto *reverse = semantic->reverseEdge;
  ASSERT_TRUE(forward->sharedBoundaryInterval.has_value());
  ASSERT_TRUE(reverse->sharedBoundaryInterval.has_value());
  ASSERT_TRUE(forward->periodicFromLattice.has_value());
  ASSERT_TRUE(forward->periodicToLattice.has_value());
  ASSERT_TRUE(reverse->periodicFromLattice.has_value());
  ASSERT_TRUE(reverse->periodicToLattice.has_value());
  const auto gammaFrom = endpointGauge(
      forward->fromLattice, *forward->sharedBoundaryInterval,
      semantic->semanticAction.rotation, *forward->periodicFromLattice);
  const auto gammaTo = endpointGauge(
      reverse->toLattice, *reverse->sharedBoundaryInterval,
      semantic->semanticAction.rotation, *reverse->periodicToLattice);
  const auto gammaFromOther = endpointGauge(
      forward->toLattice, *forward->sharedBoundaryInterval,
      semantic->semanticAction.rotation, *forward->periodicToLattice);
  const auto gammaToOther = endpointGauge(
      reverse->fromLattice, *reverse->sharedBoundaryInterval,
      semantic->semanticAction.rotation, *reverse->periodicFromLattice);
  ASSERT_TRUE(gammaFrom.has_value());
  ASSERT_TRUE(gammaTo.has_value());
  ASSERT_TRUE(gammaFromOther.has_value());
  ASSERT_TRUE(gammaToOther.has_value());
  const auto expected = compose(
      gammaTo->inverse(), compose(semantic->semanticAction, *gammaFrom));
  EXPECT_EQ(expected, compose(gammaToOther->inverse(),
                              compose(semantic->semanticAction,
                                      *gammaFromOther)));
  const auto wrongDirection =
      compose(*gammaTo, compose(semantic->semanticAction,
                                gammaFrom->inverse()));
  EXPECT_NE(expected, wrongDirection)
      << "non-self-inverse gauges must kill the wrong Gamma direction";

  auto a5Result = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.fixture.mesh.V, fixture.fixture.mesh.F, front);
  const auto *a5 = std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
      &a5Result);
  ASSERT_NE(a5, nullptr);
  const auto relation = std::find_if(
      a5->owned_relations().begin(), a5->owned_relations().end(),
      [&](const auto &candidate) {
        return candidate.id.kind ==
                   directional::pipeline::SurfaceOccurrenceRelationKind::Periodic &&
               candidate.id.periodicRelation == semantic->storedRelation->id();
      });
  ASSERT_NE(relation, a5->owned_relations().end());
  ASSERT_TRUE(relation->evidence.canonicalTransport.has_value());
  EXPECT_TRUE(relation->evidence.canonicalTransport.value() == expected ||
              relation->evidence.canonicalTransport.value() == expected.inverse());
}

TEST(M6CP3, HardRailPublishedTauRequiresIncidentSourceFaces) {
  const auto &fixture = nonconstant_hard_rail_fixture();
  PhaseFrontDraft draft = phase_front_draft(fixture.network.phaseFront);
  ASSERT_FALSE(draft.hardRailFieldTransitions.empty());
  auto &record = draft.hardRailFieldTransitions.front();
  std::optional<directional::authority::SourceFaceTopologyKey> unrelated;
  for (const auto &region : fixture.network.phaseFront.product().sourceTopologyRegions().regions()) {
    for (const auto &face : region.faces()) {
      const auto &vertices = face.topology.vertices();
      if (face.topology == record.secondFace ||
          std::find(vertices.begin(), vertices.end(), record.edge.first()) !=
              vertices.end() ||
          std::find(vertices.begin(), vertices.end(), record.edge.second()) !=
              vertices.end()) continue;
      unrelated = face.topology;
      break;
    }
    if (unrelated.has_value()) break;
  }
  ASSERT_TRUE(unrelated.has_value());
  record.firstFace = *unrelated;
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(draft)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::InvalidSourceAuthority);
}

TEST(M6CP3, HardRailCrossRegionBranchCertificateStripsEndpointFaceGauge) {
  const auto &fixture = nonconstant_hard_rail_fixture();
  const auto &front = fixture.network.phaseFront.product();
  ASSERT_FALSE(front.hardRailRouteCertificates().empty())
      << "D2 requires at least one A4-produced, paired route certificate";
  for (const auto &route : front.hardRailRouteCertificates()) {
    ASSERT_FALSE(route.route.empty());
    for (const auto &endpoint : route.endpoints) {
      ASSERT_EQ(endpoint.orientedSteps.size(), route.route.steps().size());
      auto current = endpoint.firstAttachment;
      auto composedTurn = directional::authority::QuarterTurn::from_integer(0);
      for (const auto &step : endpoint.orientedSteps) {
        ASSERT_EQ(step.firstFace, current);
        current = step.secondFace;
        composedTurn = compose(step.firstToSecond, composedTurn);
      }
      EXPECT_EQ(current, endpoint.secondAttachment);
      EXPECT_EQ(composedTurn, endpoint.composedTurn);
    }
  }
  auto a5Result = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, front);
  if (const auto *a5Error =
          std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
              &a5Result)) {
    ADD_FAILURE()
        << "unexpected A5 rejection before withdrawn-certificate assertions: "
        << "code="
        << directional::pipeline::surface_occurrence_complex_error_name(
               a5Error->code)
        << " site=SurfaceOccurrenceComplexProducer::produce"
        << " relationKind="
        << (a5Error->relation.has_value()
                ? static_cast<int>(a5Error->relation->kind)
                : -1)
        << " relationFirstCell="
        << (a5Error->relation.has_value()
                ? static_cast<long long>(a5Error->relation->first.cell().index())
                : -1LL)
        << " relationFirstCorner="
        << (a5Error->relation.has_value()
                ? static_cast<int>(
                      a5Error->relation->first.canonical_corner_role())
                : -1)
        << " relationSecondCell="
        << (a5Error->relation.has_value()
                ? static_cast<long long>(a5Error->relation->second.cell().index())
                : -1LL)
        << " relationSecondCorner="
        << (a5Error->relation.has_value()
                ? static_cast<int>(
                      a5Error->relation->second.canonical_corner_role())
                : -1)
        << " hardRail="
        << (a5Error->relation.has_value() &&
                    a5Error->relation->hardRail.has_value()
                ? static_cast<long long>(
                      a5Error->relation->hardRail->index())
                : -1LL);
  }
  const auto *a5 = std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
      &a5Result);
  ASSERT_NE(a5, nullptr);

  const directional::pipeline::SurfaceOccurrenceRelation *witness = nullptr;
  const directional::geometry::SurfaceHardRailRouteCertificate *witnessRoute = nullptr;
  std::size_t witnessEndpoint = 0U;
  std::optional<directional::authority::QuarterTurn> witnessTau;
  for (const auto &relation : a5->owned_relations()) {
    if (relation.id.kind !=
            directional::pipeline::SurfaceOccurrenceRelationKind::HardRail ||
        !relation.id.hardRail.has_value() ||
        !relation.evidence.firstEndpointFaceGauge.has_value() ||
        !relation.evidence.secondEndpointFaceGauge.has_value() ||
        !relation.evidence.canonicalTransport.has_value()) continue;
    const auto fromFace = relation.evidence.firstEndpointFaceGauge->face;
    const auto toFace = relation.evidence.secondEndpointFaceGauge->face;
    for (const auto &certificate : front.hardRailRouteCertificates()) {
      if (certificate.rail != *relation.id.hardRail ||
          (relation.evidence.equivalence.route != certificate.route &&
           relation.evidence.equivalence.route != certificate.route.reversed()))
        continue;
      for (std::size_t endpointIndex = 0; endpointIndex < 2U; ++endpointIndex) {
        const auto &endpoint = certificate.endpoints[endpointIndex];
        const bool forward = endpoint.firstAttachment == fromFace &&
                             endpoint.secondAttachment == toFace;
        const bool reverse = endpoint.secondAttachment == fromFace &&
                             endpoint.firstAttachment == toFace;
        if (!forward && !reverse) continue;
        const auto tau = reverse ? endpoint.composedTurn.inverse()
                                 : endpoint.composedTurn;
        if (tau != directional::authority::QuarterTurn::from_integer(1) &&
            tau != directional::authority::QuarterTurn::from_integer(3))
          continue;
        const auto delta = compose(
            relation.evidence.secondEndpointFaceGauge->localFaceBranchRotation,
            relation.evidence.firstEndpointFaceGauge->localFaceBranchRotation.inverse());
        if (delta == tau) continue;
        witness = &relation;
        witnessRoute = &certificate;
        witnessEndpoint = endpointIndex;
        witnessTau = tau;
        break;
      }
      if (witness != nullptr) break;
    }
    if (witness != nullptr) break;
  }
  ASSERT_NE(witness, nullptr)
      << "D2 requires real-produced HardRail with odd oriented A3 tau != regional F difference";
  const auto *first = m6cp3_occurrence_by_id(*a5, witness->id.first);
  const auto *second = m6cp3_occurrence_by_id(*a5, witness->id.second);
  ASSERT_NE(first, nullptr);
  ASSERT_NE(second, nullptr);
  EXPECT_NE(first->topologyRegion, second->topologyRegion);
  SCOPED_TRACE("produced HardRail: F_a=" +
               std::to_string(witness->evidence.firstEndpointFaceGauge->localFaceBranchRotation.value()) +
               " F_b=" +
               std::to_string(witness->evidence.secondEndpointFaceGauge->localFaceBranchRotation.value()) +
               " tau=" + std::to_string(witnessTau->value()) +
               " R_coord=" +
               std::to_string(witness->evidence.canonicalTransport->rotation.value()) +
               " B_a=" + std::to_string(first->placement.lattice.branchRotation) +
               " B_b=" + std::to_string(second->placement.lattice.branchRotation));
  EXPECT_EQ(directional::authority::QuarterTurn::from_integer(
                second->placement.lattice.branchRotation -
                first->placement.lattice.branchRotation),
            compose(witness->evidence.canonicalTransport->rotation,
                    *witnessTau));

  ASSERT_NE(witnessRoute, nullptr);
  const auto &certifiedSteps = witnessRoute->endpoints[witnessEndpoint].orientedSteps;
  const auto oddCarrier = std::find_if(
      certifiedSteps.begin(), certifiedSteps.end(),
      [](const directional::geometry::SurfaceHardRailFieldTransition &step) {
        return step.firstToSecond ==
                   directional::authority::QuarterTurn::from_integer(1) ||
               step.firstToSecond ==
                   directional::authority::QuarterTurn::from_integer(3);
      });
  ASSERT_NE(oddCarrier, certifiedSteps.end());
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const auto sourceEdge = oddCarrier->edge;
  auto entry = std::find_if(
      tampered.hardRailFieldTransitions.begin(),
      tampered.hardRailFieldTransitions.end(),
      [&](const directional::geometry::SurfaceHardRailFieldTransition &value) {
        return value.edge == sourceEdge;
      });
  ASSERT_NE(entry, tampered.hardRailFieldTransitions.end());
  entry->firstToSecond = entry->firstToSecond.inverse();
  // Preserve the declared route/edge consistency while changing only the
  // A4-owned odd tau. This is an A5 discriminant, not malformed product input.
  for (auto &certificate : tampered.hardRailRouteCertificates) {
    for (auto &endpoint : certificate.endpoints) {
      auto accumulated = directional::authority::QuarterTurn::from_integer(0);
      for (auto &step : endpoint.orientedSteps) {
        if (step.edge == sourceEdge)
          step.firstToSecond = step.firstToSecond.inverse();
        accumulated = compose(step.firstToSecond, accumulated);
      }
      endpoint.composedTurn = accumulated;
    }
  }
  auto rebuilt = construct_phase_front_product(std::move(tampered));
  const auto *tamperedFront =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&rebuilt);
  ASSERT_NE(tamperedFront, nullptr);
  const auto tamperedA5 = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *tamperedFront);
  const auto *tamperedError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(&tamperedA5);
  ASSERT_NE(tamperedError, nullptr)
      << "Reversing odd A4-owned cross-rail tau must reject a produced HardRail";
  EXPECT_EQ(tamperedError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::HardRailTransportMismatch);

}

TEST(M6CP3, OrdinaryFrontIsolationSeamUsesCoordinateIdentityAndCertifiedSheetTransition) {
  const auto candidate = m6cp3_produced_seam_fixture();
  ASSERT_NE(candidate, nullptr)
      << "D3/D7: bounded axis-aligned real-tracer family produced no "
         "fully certified reciprocal cross-sheet OrdinaryFront";
  const auto &fixture = *candidate;
  auto a5Result = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 = std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
      &a5Result);
  ASSERT_NE(a5, nullptr);
  const auto *relation = m6cp3_seam_ordinary(*a5);
  ASSERT_NE(relation, nullptr)
      << "D3 requires a real-tracer seam-collinear OrdinaryFront";
  const auto *first = m6cp3_occurrence_by_id(*a5, relation->id.first);
  const auto *second = m6cp3_occurrence_by_id(*a5, relation->id.second);
  ASSERT_NE(first, nullptr);
  ASSERT_NE(second, nullptr);
  EXPECT_EQ(first->placement.lattice.latticeCoordinate,
            second->placement.lattice.latticeCoordinate);
  EXPECT_EQ(first->placement.lattice.scaleLevel,
            second->placement.lattice.scaleLevel);
  auto a6Result = directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Result);
  ASSERT_NE(a6, nullptr);

  auto records = a5->verification_records();
  auto altered = std::find_if(
      records.ownedRelations.begin(), records.ownedRelations.end(),
      [&](const auto &candidate) { return candidate.id == relation->id; });
  ASSERT_NE(altered, records.ownedRelations.end());
  ASSERT_TRUE(altered->evidence.secondEndpointFaceGauge.has_value());
  altered->evidence.secondEndpointFaceGauge->localFaceBranchRotation = compose(
      directional::authority::QuarterTurn::from_integer(1),
      altered->evidence.secondEndpointFaceGauge->localFaceBranchRotation);
  auto tamperedA5Result =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(std::move(records.cells),
                                         std::move(records.occurrences),
                                         std::move(records.ownedRelations));
  const auto *tamperedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &tamperedA5Result);
  ASSERT_NE(tamperedA5, nullptr);
  auto rejected = directional::pipeline::SurfaceQuotientProducer::produce(
      *tamperedA5);
  const auto *error =
      std::get_if<directional::pipeline::SurfaceQuotientProductError>(&rejected);
  ASSERT_NE(error, nullptr);
  EXPECT_EQ(error->code,
            directional::pipeline::SurfaceQuotientProductErrorCode::
                RelationCertificateConflict);
}

TEST(M6CP3, A5ChartBarriersConsumeTypedHardFeatureAuthorityAcrossRelationKinds) {
  const auto hasTransitionAcross = [](const auto &graph, const auto &edge) {
    return std::any_of(graph.transitions().begin(), graph.transitions().end(),
                       [&](const auto &transition) {
                         return transition.sharedEntity.edge == edge;
                       });
  };
  const auto verifyBlocked = [&](const auto &graph, const auto &edge) {
    EXPECT_TRUE(graph.is_hard_edge(static_cast<int>(edge.first().index()),
                                   static_cast<int>(edge.second().index())));
    EXPECT_FALSE(hasTransitionAcross(graph, edge));
  };

  const auto &torus = torus_fixture();
  const auto expectedHard = torus_row408_hard_edges(torus.mesh);
  const auto &front = torus.network.phaseFront.product();
  EXPECT_EQ(front.hardFeatureEdges(), expectedHard);
  directional::geometry::SourceChartTransitionGraph torusGraph(
      torus.mesh.F, front.sourceTopologyRegions(), front.hardFeatureEdges());
  ASSERT_TRUE(torusGraph.available());
  ASSERT_EQ(expectedHard.size(), 18U);
  for (const auto &edge : expectedHard) verifyBlocked(torusGraph, edge);

  auto baselineResult =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          torus.mesh.V, torus.mesh.F, front);
  const auto *baseline =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &baselineResult);
  ASSERT_NE(baseline, nullptr);

  const directional::pipeline::SurfaceOccurrenceRelation *periodicBarrier = nullptr;
  std::optional<directional::authority::SourceEdgeTopologyKey> removedCarrier;
  for (const auto &relation : baseline->owned_relations()) {
    if (relation.id.kind !=
            directional::pipeline::SurfaceOccurrenceRelationKind::Periodic ||
        !relation.evidence.firstEndpointSpan.has_value() ||
        !relation.evidence.firstEndpointSpan->collinearEdge.has_value()) {
      continue;
    }
    const auto carrier = relation.evidence.firstEndpointSpan->collinearEdge.value();
    if (expectedHard.contains(carrier)) {
      periodicBarrier = &relation;
      removedCarrier = carrier;
      break;
    }
  }
  ASSERT_NE(periodicBarrier, nullptr)
      << "D4 requires a produced PeriodicCut carrier that is also a typed hard feature";
  ASSERT_TRUE(removedCarrier.has_value());
  verifyBlocked(torusGraph, *removedCarrier);

  auto withoutPeriodicBarrier = front.hardFeatureEdges();
  ASSERT_EQ(withoutPeriodicBarrier.erase(*removedCarrier), 1U);
  directional::geometry::SourceChartTransitionGraph torusWithoutBarrier(
      torus.mesh.F, front.sourceTopologyRegions(), withoutPeriodicBarrier);
  ASSERT_TRUE(torusWithoutBarrier.available());
  EXPECT_FALSE(torusWithoutBarrier.is_hard_edge(
      static_cast<int>(removedCarrier->first().index()),
      static_cast<int>(removedCarrier->second().index())));
  EXPECT_TRUE(hasTransitionAcross(torusWithoutBarrier, *removedCarrier))
      << "removing the typed Periodic-carried barrier must restore the exact "
         "source-face transition across that carrier";

  const auto &rail = hard_rail_fixture();
  const auto &railFront = rail.network.phaseFront.product();
  directional::geometry::SourceChartTransitionGraph railGraph(
      rail.mesh.F, railFront.sourceTopologyRegions(), railFront.hardFeatureEdges());
  ASSERT_TRUE(railGraph.available());
  auto railA5Result =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          rail.mesh.V, rail.mesh.F, railFront);
  const auto *railA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&railA5Result);
  ASSERT_NE(railA5, nullptr);
  std::size_t hardRailCarrierCount = 0U;
  for (const auto &relation : railA5->owned_relations()) {
    if (relation.id.kind !=
        directional::pipeline::SurfaceOccurrenceRelationKind::HardRail) {
      continue;
    }
    for (const auto *span : {relation.evidence.firstEndpointSpan.has_value()
                                 ? &relation.evidence.firstEndpointSpan.value()
                                 : nullptr,
                             relation.evidence.secondEndpointSpan.has_value()
                                 ? &relation.evidence.secondEndpointSpan.value()
                                 : nullptr}) {
      if (span == nullptr || !span->collinearEdge.has_value()) continue;
      ++hardRailCarrierCount;
      EXPECT_TRUE(railFront.hardFeatureEdges().contains(*span->collinearEdge));
      verifyBlocked(railGraph, *span->collinearEdge);
    }
  }
  ASSERT_GT(hardRailCarrierCount, 0U)
      << "every produced HardRail carrier must be represented by typed hard-feature authority";

  PhaseFrontDraft missingRailAuthority = phase_front_draft(railFront);
  missingRailAuthority.hardFeatureEdges.clear();
  auto missingRailFrontResult =
      construct_phase_front_product(std::move(missingRailAuthority));
  const auto *missingRailFront =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(
          &missingRailFrontResult);
  ASSERT_NE(missingRailFront, nullptr);
  auto missingRailA5 =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          rail.mesh.V, rail.mesh.F, *missingRailFront);
  const auto *missingRailError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
          &missingRailA5);
  ASSERT_NE(missingRailError, nullptr);
  EXPECT_EQ(missingRailError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                InvalidHardRailAuthority);

  const auto &square = square_fixture();
  const auto &squareFront = square.network.phaseFront.product();
  directional::geometry::SourceChartTransitionGraph squareGraph(
      square.mesh.F, squareFront.sourceTopologyRegions(),
      squareFront.hardFeatureEdges());
  ASSERT_TRUE(squareGraph.available());
  // D5 must select an A5-published reciprocal OrdinaryFront relation, not
  // merely an unpaired A4 side whose boundaryKind happens to be ordinary.
  const auto squareA5Result =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          square.mesh.V, square.mesh.F, squareFront);
  const auto *squareA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &squareA5Result);
  ASSERT_NE(squareA5, nullptr);
  PhaseFrontDraft marked = phase_front_draft(squareFront);
  std::optional<directional::authority::SourceEdgeTopologyKey> ordinaryCarrier;
  std::optional<directional::authority::SourceEdgeTopologyKey> unaffectedCarrier;
  for (const auto &relation : squareA5->owned_relations()) {
    if (relation.id.kind !=
            directional::pipeline::SurfaceOccurrenceRelationKind::OrdinaryFront ||
        relation.firstFrontEdge < 0 || relation.secondFrontEdge < 0 ||
        relation.firstFrontEdge >= static_cast<int>(marked.edges.size()) ||
        relation.secondFrontEdge >= static_cast<int>(marked.edges.size())) {
      continue;
    }
    const auto &edge = marked.edges[static_cast<std::size_t>(relation.firstFrontEdge)];
    const auto &reciprocal =
        marked.edges[static_cast<std::size_t>(relation.secondFrontEdge)];
    if (edge.boundaryKind != SurfaceFrontBoundaryKind::OrdinaryInterior ||
        reciprocal.boundaryKind != SurfaceFrontBoundaryKind::OrdinaryInterior ||
        edge.oppositeEdge != relation.secondFrontEdge ||
        reciprocal.oppositeEdge != relation.firstFrontEdge ||
        edge.route.empty() || reciprocal.route != edge.route.reversed()) {
      continue;
    }
    for (const auto &step : edge.route.steps()) {
      const auto carrier = step.topology();
      if (marked.hardFeatureEdges.contains(carrier) ||
          !hasTransitionAcross(squareGraph, carrier)) {
        continue;
      }
      for (const auto &transition : squareGraph.transitions()) {
        if (transition.sharedEntity.edge != carrier &&
            !marked.hardFeatureEdges.contains(transition.sharedEntity.edge)) {
          ordinaryCarrier = carrier;
          unaffectedCarrier = transition.sharedEntity.edge;
          break;
        }
      }
      if (ordinaryCarrier.has_value()) break;
    }
    if (ordinaryCarrier.has_value()) break;
  }
  ASSERT_TRUE(ordinaryCarrier.has_value())
      << "D5 requires a real reciprocal A5 OrdinaryFront with an A4 route, "
         "eligible interior source transition and unrelated live carrier";
  ASSERT_TRUE(unaffectedCarrier.has_value());
  marked.hardFeatureEdges.insert(*ordinaryCarrier);
  directional::geometry::SourceChartTransitionGraph squareMarkedGraph(
      square.mesh.F, marked.sourceAuthority, marked.hardFeatureEdges);
  ASSERT_TRUE(squareMarkedGraph.available());
  verifyBlocked(squareMarkedGraph, *ordinaryCarrier);
  EXPECT_TRUE(hasTransitionAcross(squareMarkedGraph, *unaffectedCarrier));
}

TEST(M6CP3, ProducedSeamCollinearOrdinaryFrontRequiresExactCrossSheetTransition) {
  const auto candidate = m6cp3_produced_seam_fixture();
  ASSERT_NE(candidate, nullptr)
      << "D3/D7: bounded axis-aligned real-tracer family produced no "
         "fully certified reciprocal cross-sheet OrdinaryFront";
  const auto &fixture = *candidate;
  auto a5Result = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 = std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
      &a5Result);
  ASSERT_NE(a5, nullptr);
  const auto *relation = m6cp3_seam_ordinary(*a5);
  ASSERT_NE(relation, nullptr);
  const auto *first = m6cp3_occurrence_by_id(*a5, relation->id.first);
  const auto *second = m6cp3_occurrence_by_id(*a5, relation->id.second);
  ASSERT_NE(first, nullptr);
  ASSERT_NE(second, nullptr);
  std::vector<directional::authority::IsolationSheetId> shared;
  std::set_intersection(first->cornerWedgeSheets.begin(),
                        first->cornerWedgeSheets.end(),
                        second->cornerWedgeSheets.begin(),
                        second->cornerWedgeSheets.end(),
                        std::back_inserter(shared));
  ASSERT_TRUE(shared.empty())
      << "D7 witness must have disjoint endpoint sheet sets";

  auto a6Result = directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Result);
  ASSERT_NE(a6, nullptr);
  const bool selected = std::any_of(
      a6->selected_forest().begin(), a6->selected_forest().end(),
      [&](const auto &edge) { return edge.relation == relation->id; });
  ASSERT_TRUE(selected);
  auto a7Result = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  ASSERT_NE(std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
                &a7Result),
            nullptr);

  auto records = a5->verification_records();
  auto altered = std::find_if(
      records.ownedRelations.begin(), records.ownedRelations.end(),
      [&](const auto &candidate) { return candidate.id == relation->id; });
  ASSERT_NE(altered, records.ownedRelations.end());
  altered->evidence.firstSideIsolationEvidence.clear();
  altered->evidence.secondSideIsolationEvidence.clear();
  altered->evidence.equivalence.isolationTransitions.clear();
  auto tamperedA5Result =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(std::move(records.cells),
                                         std::move(records.occurrences),
                                         std::move(records.ownedRelations));
  const auto *tamperedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &tamperedA5Result);
  ASSERT_NE(tamperedA5, nullptr);
  auto rejected = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *tamperedA5, *a6);
  const auto *failure =
      std::get_if<directional::pipeline::GeometryEmbeddingFailure>(&rejected);
  ASSERT_NE(failure, nullptr);
  EXPECT_EQ(failure->code,
            directional::pipeline::GeometryEmbeddingFailureCode::
                UncertifiedCrossSheetBinding);
  EXPECT_EQ(failure->site, "cross-sheet");
}

TEST(M6CP3, HardRailCrossRegionBindingDoesNotCompareGlobalSheetLabels) {
  const auto &fixture = nonconstant_hard_rail_fixture();
  auto a5Result = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  if (const auto *a5Error =
          std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
              &a5Result)) {
    ADD_FAILURE() << "identity 6 A5 rejection: code="
                  << directional::pipeline::surface_occurrence_complex_error_name(
                         a5Error->code)
                  << " site=SurfaceOccurrenceComplexProducer::produce"
                  << " relationKind="
                  << (a5Error->relation.has_value()
                          ? static_cast<int>(a5Error->relation->kind)
                          : -1)
                  << " relationFirstCell="
                  << (a5Error->relation.has_value()
                          ? static_cast<long long>(
                                a5Error->relation->first.cell().index())
                          : -1LL)
                  << " relationFirstCorner="
                  << (a5Error->relation.has_value()
                          ? static_cast<int>(a5Error->relation->first
                                                 .canonical_corner_role())
                          : -1)
                  << " relationSecondCell="
                  << (a5Error->relation.has_value()
                          ? static_cast<long long>(
                                a5Error->relation->second.cell().index())
                          : -1LL)
                  << " relationSecondCorner="
                  << (a5Error->relation.has_value()
                          ? static_cast<int>(a5Error->relation->second
                                                 .canonical_corner_role())
                          : -1)
                  << " hardRail="
                  << (a5Error->relation.has_value() &&
                              a5Error->relation->hardRail.has_value()
                          ? static_cast<long long>(
                                a5Error->relation->hardRail->index())
                          : -1LL);
  }
  const auto *a5 = std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
      &a5Result);
  ASSERT_NE(a5, nullptr);
  auto a6Result = directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Result);
  ASSERT_NE(a6, nullptr);

  const directional::pipeline::QuotientForestEdge *hardRailEdge = nullptr;
  const directional::pipeline::SurfaceOccurrenceRelation *hardRailRelation = nullptr;
  for (const auto &edge : a6->selected_forest()) {
    const auto relation = std::find_if(
        a5->owned_relations().begin(), a5->owned_relations().end(),
        [&](const auto &candidate) { return candidate.id == edge.relation; });
    if (relation == a5->owned_relations().end() ||
        relation->id.kind !=
            directional::pipeline::SurfaceOccurrenceRelationKind::HardRail) {
      continue;
    }
    const auto *first = m6cp3_occurrence_by_id(*a5, edge.first);
    const auto *second = m6cp3_occurrence_by_id(*a5, edge.second);
    if (first != nullptr && second != nullptr &&
        first->topologyRegion != second->topologyRegion) {
      hardRailEdge = &edge;
      hardRailRelation = &*relation;
      break;
    }
  }
  ASSERT_NE(hardRailEdge, nullptr);
  ASSERT_NE(hardRailRelation, nullptr);
  auto baselineA7 = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  ASSERT_NE(std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
                &baselineA7),
            nullptr);

  auto records = a5->verification_records();
  auto altered = std::find_if(
      records.ownedRelations.begin(), records.ownedRelations.end(),
      [&](const auto &candidate) { return candidate.id == hardRailRelation->id; });
  ASSERT_NE(altered, records.ownedRelations.end());
  altered->evidence.firstEndpointFaceGauge.reset();
  auto tamperedA5Result =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(std::move(records.cells),
                                         std::move(records.occurrences),
                                         std::move(records.ownedRelations));
  const auto *tamperedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &tamperedA5Result);
  ASSERT_NE(tamperedA5, nullptr);
  auto rejected = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *tamperedA5, *a6);
  const auto *failure =
      std::get_if<directional::pipeline::GeometryEmbeddingFailure>(&rejected);
  ASSERT_NE(failure, nullptr);
  EXPECT_EQ(failure->code,
            directional::pipeline::GeometryEmbeddingFailureCode::
                UncertifiedCrossSheetBinding);
  EXPECT_EQ(failure->site, "cross-sheet:hard-rail");
}

TEST(M6CP1, SurfaceOccurrenceComplexPublishesFourSemanticCornersPerCell) {
  const auto &fixture = square_fixture();
  auto construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *product =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &construction);
  ASSERT_NE(product, nullptr);
  ASSERT_EQ(product->certificate().cellCount, product->cells().size());
  ASSERT_EQ(product->certificate().occurrenceCount,
            product->occurrences().size());
  EXPECT_EQ(product->occurrences().size(), product->cells().size() * 4U);
  EXPECT_TRUE(product->certificate().exactCellOwnership);
  EXPECT_TRUE(product->certificate().exactCornerOwnership);
  EXPECT_TRUE(product->certificate().exactDirectedSideCycles);
  EXPECT_TRUE(product->certificate().exactRelationEndpointOwnership);
  EXPECT_FALSE(product->certificate().geometricCoincidenceInferenceUsed);

  for (const auto &cell : product->cells()) {
    std::set<directional::authority::OccurrenceId> unique;
    for (std::size_t corner = 0; corner < 4U; ++corner) {
      const auto occurrence = cell.cornerOccurrences[corner];
      EXPECT_EQ(occurrence.cell(), cell.id);
      EXPECT_EQ(occurrence.canonical_corner_role(), corner);
      unique.insert(occurrence);
      EXPECT_EQ(cell.directedSides[corner].first, occurrence);
      EXPECT_EQ(cell.directedSides[corner].second,
                cell.cornerOccurrences[(corner + 1U) % 4U]);
    }
    EXPECT_EQ(unique.size(), 4U);
  }
}

TEST(M6CP1, CoincidentUnrelatedOccurrencesRemainDistinct) {
  const auto fixture = make_square_fixture(false, true);
  auto construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *product =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &construction);
  ASSERT_NE(product, nullptr);

  bool found = false;
  for (std::size_t first = 0; first < product->occurrences().size(); ++first) {
    for (std::size_t second = first + 1U; second < product->occurrences().size();
         ++second) {
      const auto &a = product->occurrences()[first];
      const auto &b = product->occurrences()[second];
      if ((a.point.position - b.point.position).norm() > 1.0e-12 ||
          a.placement.lattice.latticeCoordinate !=
              b.placement.lattice.latticeCoordinate ||
          a.id == b.id) {
        continue;
      }
      const bool explicitlyRelated = std::any_of(
          product->owned_relations().begin(), product->owned_relations().end(),
          [&](const auto &relation) {
            return (relation.firstOccurrence == a.id &&
                    relation.secondOccurrence == b.id) ||
                   (relation.firstOccurrence == b.id &&
                    relation.secondOccurrence == a.id);
          });
      if (!explicitlyRelated) {
        found = true;
        break;
      }
    }
    if (found) break;
  }
  EXPECT_TRUE(found)
      << "equal lattice coordinates/positions must not imply A5 identity";
}

TEST(M6CP1, SourceFaceRowPermutationPreservesOccurrenceIdentity) {
  const auto &baselineFixture = square_fixture();
  const auto permutedFixture = make_square_fixture_with_reversed_source_face_rows();
  auto baselineConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          baselineFixture.mesh.V, baselineFixture.mesh.F,
          baselineFixture.network.phaseFront.product());
  auto permutedConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          permutedFixture.mesh.V, permutedFixture.mesh.F,
          permutedFixture.network.phaseFront.product());
  const auto *baseline =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &baselineConstruction);
  const auto *permuted =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &permutedConstruction);
  ASSERT_NE(baseline, nullptr);
  ASSERT_NE(permuted, nullptr);

  const auto occurrenceIds = [](const auto &product) {
    std::vector<directional::authority::OccurrenceId> ids;
    for (const auto &occurrence : product.occurrences()) ids.push_back(occurrence.id);
    return ids;
  };
  const auto cellIds = [](const auto &product) {
    std::vector<directional::authority::CellId> ids;
    for (const auto &cell : product.cells()) ids.push_back(cell.id);
    return ids;
  };
  const auto relationIds = [](const auto &product) {
    std::vector<directional::pipeline::SurfaceOccurrenceRelationId> ids;
    for (const auto &relation : product.owned_relations()) ids.push_back(relation.id);
    return ids;
  };
  EXPECT_EQ(cellIds(*baseline), cellIds(*permuted));
  EXPECT_EQ(occurrenceIds(*baseline), occurrenceIds(*permuted));
  EXPECT_EQ(relationIds(*baseline), relationIds(*permuted));
}

TEST(M6CP1, SeamEndpointOccurrencesPublishCompleteCornerWedgeSheetAuthority) {
  const auto &baselineFixture = split_isolation_fixture();
  const auto permutedFixture =
      make_split_isolation_fixture_with_reversed_source_face_rows();

  auto baselineConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          baselineFixture.mesh.V, baselineFixture.mesh.F,
          baselineFixture.network.phaseFront.product());
  auto permutedConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          permutedFixture.mesh.V, permutedFixture.mesh.F,
          permutedFixture.network.phaseFront.product());
  const auto *baselineOccurrences =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &baselineConstruction);
  const auto *permutedOccurrences =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &permutedConstruction);
  ASSERT_NE(baselineOccurrences, nullptr);
  ASSERT_NE(permutedOccurrences, nullptr);

  const auto occurrenceSignature = [](const auto &product) {
    using Entry = std::tuple<
        directional::authority::OccurrenceId,
        std::vector<directional::authority::IsolationSheetId>,
        std::vector<directional::geometry::CornerWedgeIsolationTransition>>;
    std::vector<Entry> signature;
    signature.reserve(product.occurrences().size());
    for (const auto &occurrence : product.occurrences()) {
      signature.emplace_back(occurrence.id, occurrence.cornerWedgeSheets,
                             occurrence.cornerWedgeIsolation);
    }
    std::sort(signature.begin(), signature.end());
    return signature;
  };
  EXPECT_EQ(occurrenceSignature(*baselineOccurrences),
            occurrenceSignature(*permutedOccurrences));

  const auto baseline =
      materialize(baselineFixture, baselineFixture.network.phaseFront);
  const auto permuted =
      materialize(permutedFixture, permutedFixture.network.phaseFront);
  ASSERT_TRUE(baseline.success) << baseline.failure;
  ASSERT_TRUE(permuted.success) << permuted.failure;

  const auto &sourceAuthority =
      baselineFixture.network.phaseFront.product().sourceTopologyRegions();
  ASSERT_EQ(1U, sourceAuthority.regions().size());
  const auto expectedSheets = sourceAuthority.regions().front().isolation_sheets();
  ASSERT_EQ(2U, expectedSheets.size());
  const auto &certificates = baselineFixture.network.phaseFront.product()
                                 .isolationSeamTransportCertificates();
  ASSERT_EQ(1U, certificates.size());
  const auto &certificate = certificates.front();

  const auto cornerIsolation = [](const auto &lineage) {
    std::vector<std::vector<directional::geometry::CornerWedgeIsolationTransition>>
        evidence;
    for (const auto &equivalence : lineage.equivalences) {
      if (equivalence.kind !=
          directional::geometry::PureQuadEquivalenceKind::CornerWedgeIsolation) {
        continue;
      }
      evidence.push_back(equivalence.isolationTransitions);
    }
    std::sort(evidence.begin(), evidence.end());
    return evidence;
  };
  const auto hasTransition = [](
                                 const auto &evidence,
                                 const directional::authority::TopologyRegionId region,
                                 const directional::authority::SourceEdgeTopologyKey seam,
                                 const directional::authority::IsolationSheetId from,
                                 const directional::authority::IsolationSheetId to) {
    return std::any_of(evidence.begin(), evidence.end(), [&](const auto &sequence) {
      return std::find(sequence.begin(), sequence.end(),
                       directional::geometry::CornerWedgeIsolationTransition{
                           region, seam, from, to}) != sequence.end();
    });
  };
  const auto findLineageAt = [](const auto &mesh, const Eigen::Vector3d &point)
      -> const directional::geometry::PureQuadVertexLineage * {
    for (const auto &lineage : mesh.vertexLineage) {
      if ((lineage.sourcePoint.position - point).norm() <= 1.0e-12) {
        return &lineage;
      }
    }
    return nullptr;
  };

  const auto *v0 = findLineageAt(baseline.mesh, Eigen::Vector3d(0.0, 0.0, 0.0));
  const auto *center =
      findLineageAt(baseline.mesh, Eigen::Vector3d(0.5, 0.5, 0.0));
  const auto *v2 = findLineageAt(baseline.mesh, Eigen::Vector3d(1.0, 1.0, 0.0));
  ASSERT_NE(v0, nullptr);
  ASSERT_NE(center, nullptr);
  ASSERT_NE(v2, nullptr);

  EXPECT_EQ(expectedSheets, v0->sourceIsolationSheets);
  EXPECT_EQ(expectedSheets, center->sourceIsolationSheets);
  EXPECT_EQ(expectedSheets, v2->sourceIsolationSheets);
  const auto v0Evidence = cornerIsolation(*v0);
  const auto centerEvidence = cornerIsolation(*center);
  const auto v2Evidence = cornerIsolation(*v2);
  EXPECT_FALSE(v0Evidence.empty());
  EXPECT_FALSE(centerEvidence.empty());
  EXPECT_FALSE(v2Evidence.empty());
  EXPECT_TRUE(hasTransition(v0Evidence, certificate.region(), certificate.seam(),
                            expectedSheets[1], expectedSheets[0]));
  EXPECT_TRUE(hasTransition(v2Evidence, certificate.region(), certificate.seam(),
                            expectedSheets[0], expectedSheets[1]));
  for (const auto &sequence : centerEvidence) {
    for (const auto &transition : sequence) {
      EXPECT_EQ(certificate.region(), transition.region);
      EXPECT_EQ(certificate.seam(), transition.seam);
      EXPECT_NE(transition.fromSheet, transition.toSheet);
      EXPECT_TRUE(std::binary_search(expectedSheets.begin(), expectedSheets.end(),
                                     transition.fromSheet));
      EXPECT_TRUE(std::binary_search(expectedSheets.begin(), expectedSheets.end(),
                                     transition.toSheet));
    }
  }

  for (const auto &lineage : baseline.mesh.vertexLineage) {
    const bool isSeamEndpointOrCenter =
        &lineage == v0 || &lineage == center || &lineage == v2;
    if (!isSeamEndpointOrCenter) {
      EXPECT_EQ(1U, lineage.sourceIsolationSheets.size());
    }
    EXPECT_TRUE(lineage.selectedRelationPaths.empty());
  }

  const auto classSignature = [&](const auto &mesh) {
    using Evidence =
        std::vector<std::vector<directional::geometry::CornerWedgeIsolationTransition>>;
    using Entry = std::tuple<
        std::vector<directional::authority::OccurrenceId>,
        std::vector<directional::authority::IsolationSheetId>, Evidence>;
    std::vector<Entry> signature;
    signature.reserve(mesh.vertexLineage.size());
    for (const auto &lineage : mesh.vertexLineage) {
      signature.emplace_back(lineage.sourceOccurrences,
                             lineage.sourceIsolationSheets,
                             cornerIsolation(lineage));
    }
    std::sort(signature.begin(), signature.end());
    return signature;
  };
  EXPECT_EQ(classSignature(baseline.mesh), classSignature(permuted.mesh));
}

TEST(M6CP1,
     SurfaceOccurrenceComplexRejectsMalformedMissingAndDuplicateRelationEndpoints) {
  const auto firstDraftEdgeOfKind =
      [](const PhaseFrontDraft &draft, const SurfaceFrontBoundaryKind kind) {
        for (std::size_t index = 0; index < draft.edges.size(); ++index) {
          if (draft.edges[index].boundaryKind == kind) {
            return static_cast<int>(index);
          }
        }
        return -1;
      };
  const auto &fixture = square_fixture();
  auto construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *product =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &construction);
  ASSERT_NE(product, nullptr);
  ASSERT_FALSE(product->owned_relations().empty());

  auto missingRelations = product->owned_relations();
  const auto foreignCell = directional::authority::CellId::from_index(99, 100);
  ASSERT_TRUE(foreignCell.has_value());
  const auto foreignOccurrence =
      directional::authority::OccurrenceId::from_cell_corner(
          foreignCell.value(), 0);
  ASSERT_TRUE(foreignOccurrence.has_value());
  missingRelations.front().firstOccurrence = foreignOccurrence.value();
  auto missing =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(product->cells(), product->occurrences(),
                                         std::move(missingRelations));
  const auto *missingError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(&missing);
  ASSERT_NE(missingError, nullptr);
  EXPECT_EQ(missingError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                RelationEndpointMissing);

  auto duplicateEndpointRelations = product->owned_relations();
  duplicateEndpointRelations.front().secondOccurrence =
      duplicateEndpointRelations.front().firstOccurrence;
  auto duplicateEndpoint =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(product->cells(), product->occurrences(),
                                         std::move(duplicateEndpointRelations));
  const auto *duplicateEndpointError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
          &duplicateEndpoint);
  ASSERT_NE(duplicateEndpointError, nullptr);
  EXPECT_EQ(duplicateEndpointError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                RelationEndpointMissing);

  auto malformedRelations = product->owned_relations();
  malformedRelations.front().id.first = malformedRelations.front().secondOccurrence;
  auto malformed =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(product->cells(), product->occurrences(),
                                         std::move(malformedRelations));
  const auto *malformedError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(&malformed);
  ASSERT_NE(malformedError, nullptr);
  EXPECT_EQ(malformedError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                UnownedRelation);

  auto duplicateRelations = product->owned_relations();
  duplicateRelations.push_back(duplicateRelations.front());
  auto duplicate =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(product->cells(), product->occurrences(),
                                         std::move(duplicateRelations));
  const auto *duplicateError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
          &duplicate);
  ASSERT_NE(duplicateError, nullptr);
  EXPECT_EQ(duplicateError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                DuplicateRelationDeclaration);

  const auto &hardRailFixture = hard_rail_fixture();
  const auto produceHardRailOccurrences = [&](PhaseFrontDraft draft) {
    const auto front = publish_phase_front_draft(std::move(draft));
    return directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
        hardRailFixture.mesh.V, hardRailFixture.mesh.F, front.product());
  };

  PhaseFrontDraft invalidRoute =
      phase_front_draft(hardRailFixture.network.phaseFront);
  const int hardRail =
      firstDraftEdgeOfKind(invalidRoute, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &invalidRouteEdge =
      invalidRoute.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_TRUE(route_is_all_interior(invalidRouteEdge.route));
  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(hardRailFixture.mesh.F);
  const auto sourceTransitions = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  const int current = static_cast<int>(
      invalidRouteEdge.route.steps().front().interior()->index());
  int alternate = -1;
  for (const auto &[topology, compact] : sourceTransitions) {
    (void)topology;
    if (compact != current) {
      alternate = compact;
      break;
    }
  }
  ASSERT_GE(alternate, 0);
  const auto alternateId =
      directional::authority::InteriorTransitionId::from_index(
          alternate, sourceTransitions.size());
  ASSERT_TRUE(alternateId);
  std::vector<directional::authority::TransitionStep> steps(
      invalidRouteEdge.route.steps().begin(),
      invalidRouteEdge.route.steps().end());
  const auto replacement = directional::authority::TransitionStep::interior(
      steps.front().topology(), alternateId.value(),
      steps.front().transport(), steps.front().orientation());
  ASSERT_TRUE(replacement);
  steps.front() = replacement.value();
  invalidRouteEdge.route =
      directional::authority::CanonicalRoute::from_observed_steps(
          std::move(steps));
  const auto invalidRouteResult =
      produceHardRailOccurrences(std::move(invalidRoute));
  const auto *invalidRouteError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
          &invalidRouteResult);
  ASSERT_NE(invalidRouteError, nullptr);
  EXPECT_EQ(invalidRouteError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                HardRailRouteAuthorityInvalid);

  PhaseFrontDraft sameOrientation =
      phase_front_draft(hardRailFixture.network.phaseFront);
  const int sameOrientationRail =
      firstDraftEdgeOfKind(sameOrientation, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(sameOrientationRail, 0);
  const int opposite = sameOrientation.edges[static_cast<std::size_t>(
      sameOrientationRail)].oppositeEdge;
  ASSERT_GE(opposite, 0);
  sameOrientation.edges[static_cast<std::size_t>(opposite)].route =
      sameOrientation.edges[static_cast<std::size_t>(sameOrientationRail)].route;
  const auto sameOrientationResult =
      produceHardRailOccurrences(std::move(sameOrientation));
  const auto *sameOrientationError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
          &sameOrientationResult);
  ASSERT_NE(sameOrientationError, nullptr);
  EXPECT_EQ(sameOrientationError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                HardRailRouteMismatch);
}


TEST(M6CP1, QuotientClassIdIsSortedMemberSetAndStorageInvariant) {
  const auto &baselineFixture = square_fixture();
  const auto sourcePermutedFixture =
      make_square_fixture_with_reversed_source_face_rows();

  const auto produceQuotient = [](const PhaseFrontFixture &fixture,
                                  const directional::geometry::SurfacePhaseFrontProduct &front) {
    auto occurrenceConstruction =
        directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
            fixture.mesh.V, fixture.mesh.F, front);
    auto *occurrences =
        std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
            &occurrenceConstruction);
    if (occurrences == nullptr) {
      throw std::runtime_error("A5 occurrence production failed.");
    }
    return directional::pipeline::SurfaceQuotientProducer::produce(*occurrences);
  };
  const auto classSignature = [](const auto &product) {
    std::vector<directional::pipeline::SurfaceQuotientClassId> ids;
    for (const auto &quotient : product.classes()) {
      EXPECT_FALSE(quotient.id.members.empty());
      EXPECT_EQ(quotient.id.members, quotient.members);
      EXPECT_TRUE(std::is_sorted(quotient.id.members.begin(),
                                 quotient.id.members.end()));
      EXPECT_EQ(std::adjacent_find(quotient.id.members.begin(),
                                   quotient.id.members.end()),
                quotient.id.members.end());
      ids.push_back(quotient.id);
    }
    return ids;
  };
  const auto certificateSignature = [](const auto &product) {
    using Entry = std::tuple<
        directional::pipeline::SurfaceOccurrenceRelationId,
        directional::authority::OccurrenceId,
        directional::authority::OccurrenceId,
        directional::authority::GridAutomorphism>;
    std::vector<Entry> signature;
    for (const auto &certificate : product.relation_certificates()) {
      EXPECT_EQ(certificate.relation.first, certificate.first);
      EXPECT_EQ(certificate.relation.second, certificate.second);
      signature.emplace_back(certificate.relation, certificate.first,
                             certificate.second,
                             certificate.relationTransport);
    }
    return signature;
  };

  auto baselineConstruction = produceQuotient(
      baselineFixture, baselineFixture.network.phaseFront.product());
  auto sourcePermutedConstruction = produceQuotient(
      sourcePermutedFixture, sourcePermutedFixture.network.phaseFront.product());
  const auto *baseline =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &baselineConstruction);
  const auto *sourcePermuted =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &sourcePermutedConstruction);
  ASSERT_NE(baseline, nullptr);
  ASSERT_NE(sourcePermuted, nullptr);
  EXPECT_EQ(classSignature(*baseline), classSignature(*sourcePermuted));
  EXPECT_EQ(certificateSignature(*baseline),
            certificateSignature(*sourcePermuted));

  auto occurrenceConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          baselineFixture.mesh.V, baselineFixture.mesh.F,
          baselineFixture.network.phaseFront.product());
  const auto *occurrenceProduct =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &occurrenceConstruction);
  ASSERT_NE(occurrenceProduct, nullptr);
  auto cells = occurrenceProduct->cells();
  auto occurrences = occurrenceProduct->occurrences();
  auto relations = occurrenceProduct->owned_relations();
  std::reverse(cells.begin(), cells.end());
  std::reverse(occurrences.begin(), occurrences.end());
  std::reverse(relations.begin(), relations.end());
  auto reorderedA5 =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(std::move(cells), std::move(occurrences),
                                         std::move(relations));
  const auto *reorderedOccurrences =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&reorderedA5);
  ASSERT_NE(reorderedOccurrences, nullptr);
  auto reorderedConstruction =
      directional::pipeline::SurfaceQuotientProducer::produce(
          *reorderedOccurrences);
  const auto *reordered =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &reorderedConstruction);
  ASSERT_NE(reordered, nullptr);
  EXPECT_EQ(classSignature(*baseline), classSignature(*reordered));
  EXPECT_EQ(certificateSignature(*baseline), certificateSignature(*reordered));

  PhaseFrontDraft swapped =
      phase_front_draft(baselineFixture.network.phaseFront);
  int firstEdge = -1;
  int secondEdge = -1;
  for (int edge = 0; edge < static_cast<int>(swapped.edges.size()); ++edge) {
    if (swapped.edges[static_cast<std::size_t>(edge)].oppositeEdge > edge) {
      firstEdge = edge;
      secondEdge = swapped.edges[static_cast<std::size_t>(edge)].oppositeEdge;
      break;
    }
  }
  ASSERT_GE(firstEdge, 0);
  ASSERT_GE(secondEdge, 0);
  std::swap(swapped.edges[static_cast<std::size_t>(firstEdge)],
            swapped.edges[static_cast<std::size_t>(secondEdge)]);
  swapped.edges[static_cast<std::size_t>(firstEdge)].oppositeEdge = secondEdge;
  swapped.edges[static_cast<std::size_t>(secondEdge)].oppositeEdge = firstEdge;
  for (auto &event : swapped.events) {
    if (event.firstEdge == firstEdge) event.firstEdge = secondEdge;
    else if (event.firstEdge == secondEdge) event.firstEdge = firstEdge;
    if (event.secondEdge == firstEdge) event.secondEdge = secondEdge;
    else if (event.secondEdge == secondEdge) event.secondEdge = firstEdge;
  }
  const auto swappedFront = publish_phase_front_draft(std::move(swapped));
  auto swappedConstruction =
      produceQuotient(baselineFixture, swappedFront.product());
  const auto *swappedProduct =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &swappedConstruction);
  ASSERT_NE(swappedProduct, nullptr);
  EXPECT_EQ(classSignature(*baseline), classSignature(*swappedProduct));
  EXPECT_EQ(certificateSignature(*baseline),
            certificateSignature(*swappedProduct));
}

TEST(M6CP1, EveryOwnedRelationHasExactlyOneConsumptionRecord) {
  const auto &fixture = square_fixture();
  auto occurrenceConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *occurrences =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &occurrenceConstruction);
  ASSERT_NE(occurrences, nullptr);
  auto quotientConstruction =
      directional::pipeline::SurfaceQuotientProducer::produce(*occurrences);
  const auto *quotient =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &quotientConstruction);
  ASSERT_NE(quotient, nullptr);

  std::set<directional::pipeline::SurfaceOccurrenceRelationId> owned;
  std::set<directional::pipeline::SurfaceOccurrenceRelationId> certified;
  std::set<directional::pipeline::SurfaceOccurrenceRelationId> consumed;
  for (const auto &relation : occurrences->owned_relations()) owned.insert(relation.id);
  for (const auto &certificate : quotient->relation_certificates()) {
    certified.insert(certificate.relation);
    EXPECT_EQ(certificate.relation.first, certificate.first);
    EXPECT_EQ(certificate.relation.second, certificate.second);
  }
  std::size_t cycleClosing = 0U;
  for (const auto &row : quotient->relation_consumptions()) {
    consumed.insert(row.relation);
    if (row.disposition ==
        directional::pipeline::QuotientRelationDisposition::CycleClosing) {
      ++cycleClosing;
    }
  }
  EXPECT_EQ(owned, certified);
  EXPECT_EQ(owned, consumed);
  EXPECT_EQ(owned.size(), quotient->relation_certificates().size());
  EXPECT_EQ(owned.size(), quotient->relation_consumptions().size());
  EXPECT_GT(cycleClosing, 0U)
      << "fixture must non-vacuously exercise exact-once cycle consumption";
}

TEST(M6CP1, QuotientRejectsMissingDuplicateOrConflictingConsumption) {
  const auto &fixture = square_fixture();
  auto occurrenceConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *occurrences =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &occurrenceConstruction);
  ASSERT_NE(occurrences, nullptr);
  auto quotientConstruction =
      directional::pipeline::SurfaceQuotientProducer::produce(*occurrences);
  const auto *quotient =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &quotientConstruction);
  ASSERT_NE(quotient, nullptr);
  ASSERT_FALSE(quotient->relation_consumptions().empty());

  auto missingRecords = quotient->validation_records();
  missingRecords.relationConsumptions.pop_back();
  auto missing =
      directional::pipeline::SurfaceQuotientProducer::
          publish_records_for_validation(*occurrences, std::move(missingRecords));
  const auto *missingError =
      std::get_if<directional::pipeline::SurfaceQuotientProductError>(&missing);
  ASSERT_NE(missingError, nullptr);
  EXPECT_EQ(missingError->code,
            directional::pipeline::SurfaceQuotientProductErrorCode::
                RelationConsumptionMissing);

  auto duplicateRecords = quotient->validation_records();
  duplicateRecords.relationConsumptions.push_back(
      duplicateRecords.relationConsumptions.front());
  auto duplicate =
      directional::pipeline::SurfaceQuotientProducer::
          publish_records_for_validation(*occurrences,
                                         std::move(duplicateRecords));
  const auto *duplicateError =
      std::get_if<directional::pipeline::SurfaceQuotientProductError>(&duplicate);
  ASSERT_NE(duplicateError, nullptr);
  EXPECT_EQ(duplicateError->code,
            directional::pipeline::SurfaceQuotientProductErrorCode::
                RelationConsumptionDuplicate);

  auto conflictRecords = quotient->validation_records();
  conflictRecords.relationConsumptions.front().disposition =
      conflictRecords.relationConsumptions.front().disposition ==
              directional::pipeline::QuotientRelationDisposition::Joining
          ? directional::pipeline::QuotientRelationDisposition::CycleClosing
          : directional::pipeline::QuotientRelationDisposition::Joining;
  auto conflict =
      directional::pipeline::SurfaceQuotientProducer::
          publish_records_for_validation(*occurrences,
                                         std::move(conflictRecords));
  const auto *conflictError =
      std::get_if<directional::pipeline::SurfaceQuotientProductError>(&conflict);
  ASSERT_NE(conflictError, nullptr);
  EXPECT_EQ(conflictError->code,
            directional::pipeline::SurfaceQuotientProductErrorCode::
                RelationConsumptionConflict);

  auto certificateConflictRecords = quotient->validation_records();
  ASSERT_FALSE(certificateConflictRecords.relationCertificates.empty());
  certificateConflictRecords.relationCertificates.front().evidence.kind =
      directional::geometry::PureQuadEquivalenceKind::HardRail;
  auto certificateConflict =
      directional::pipeline::SurfaceQuotientProducer::
          publish_records_for_validation(*occurrences,
                                         std::move(certificateConflictRecords));
  const auto *certificateConflictError =
      std::get_if<directional::pipeline::SurfaceQuotientProductError>(
          &certificateConflict);
  ASSERT_NE(certificateConflictError, nullptr);
  EXPECT_EQ(certificateConflictError->code,
            directional::pipeline::SurfaceQuotientProductErrorCode::
                RelationCertificateConflict);
}

TEST(M6CP1, CycleClosingRelationTransportConflictRejected) {
  const auto &fixture = square_fixture();
  auto occurrenceConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *baselineOccurrences =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &occurrenceConstruction);
  ASSERT_NE(baselineOccurrences, nullptr);
  auto baselineQuotientConstruction =
      directional::pipeline::SurfaceQuotientProducer::produce(
          *baselineOccurrences);
  const auto *baselineQuotient =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &baselineQuotientConstruction);
  ASSERT_NE(baselineQuotient, nullptr);

  const auto cycle = std::find_if(
      baselineQuotient->relation_consumptions().begin(),
      baselineQuotient->relation_consumptions().end(), [](const auto &row) {
        return row.disposition ==
               directional::pipeline::QuotientRelationDisposition::CycleClosing;
      });
  ASSERT_NE(cycle, baselineQuotient->relation_consumptions().end());

  auto cells = baselineOccurrences->cells();
  auto occurrenceRows = baselineOccurrences->occurrences();
  auto relations = baselineOccurrences->owned_relations();
  auto relation = std::find_if(relations.begin(), relations.end(),
                               [&](const auto &candidate) {
                                 return candidate.id == cycle->relation;
                               });
  ASSERT_NE(relation, relations.end());
  const auto railId = directional::authority::HardRailId::from_index(0, 1);
  ASSERT_TRUE(railId.has_value());
  relation->id.kind = directional::pipeline::SurfaceOccurrenceRelationKind::HardRail;
  relation->id.hardRail = railId.value();
  relation->id.periodicRelation.reset();
  relation->evidence.canonicalTransport =
      directional::authority::GridAutomorphism::identity();
  relation->evidence.equivalence.kind =
      directional::geometry::PureQuadEquivalenceKind::HardRail;
  relation->evidence.equivalence.railId = railId.value();
  relation->evidence.equivalence.periodicRelation.reset();
  relation->evidence.equivalence.route = test_interior_route(0, 1, 0);
  relation->evidence.equivalence.action =
      directional::authority::GridAutomorphism::identity();
  ASSERT_TRUE(relation->evidence.firstEndpointSpan.has_value());
  ASSERT_TRUE(relation->evidence.secondEndpointSpan.has_value());
  const auto firstOccurrence = std::find_if(
      occurrenceRows.begin(), occurrenceRows.end(), [&](const auto &candidate) {
        return candidate.id == relation->id.first;
      });
  const auto secondOccurrence = std::find_if(
      occurrenceRows.begin(), occurrenceRows.end(), [&](const auto &candidate) {
        return candidate.id == relation->id.second;
      });
  ASSERT_NE(firstOccurrence, occurrenceRows.end());
  ASSERT_NE(secondOccurrence, occurrenceRows.end());
  directional::geometry::SelectedRelationStep step;
  step.relationKind = directional::geometry::SelectedRelationKind::HardRail;
  step.railId = railId.value();
  step.direction = directional::authority::Orientation::Forward;
  step.fromChart =
      relation->evidence.firstEndpointSpan->interiorBinding.chart;
  step.toChart = relation->evidence.secondEndpointSpan->interiorBinding.chart;
  step.fromChartComponent = firstOccurrence->chartComponent;
  step.toChartComponent = secondOccurrence->chartComponent;
  step.appliedTransport = directional::authority::GridAutomorphism::identity();
  ASSERT_TRUE(step.valid());
  relation->evidence.canonicalSelectedStep = step;

  auto syntheticA5 =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(std::move(cells),
                                         std::move(occurrenceRows),
                                         std::move(relations));
  const auto *cycleOccurrences =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&syntheticA5);
  ASSERT_NE(cycleOccurrences, nullptr);
  auto validCycleConstruction =
      directional::pipeline::SurfaceQuotientProducer::produce(*cycleOccurrences);
  const auto *validCycle =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &validCycleConstruction);
  ASSERT_NE(validCycle, nullptr);

  const auto hardRailCycle = std::find_if(
      validCycle->relation_consumptions().begin(),
      validCycle->relation_consumptions().end(), [&](const auto &row) {
        return row.relation.kind ==
                   directional::pipeline::SurfaceOccurrenceRelationKind::HardRail &&
               row.disposition ==
                   directional::pipeline::QuotientRelationDisposition::CycleClosing;
      });
  ASSERT_NE(hardRailCycle, validCycle->relation_consumptions().end());

  auto tampered = validCycle->validation_records();
  const directional::authority::GridAutomorphism conflictingTransport{
      directional::authority::QuarterTurn{}, {1, 0}};
  auto certificate = std::find_if(
      tampered.relationCertificates.begin(),
      tampered.relationCertificates.end(), [&](const auto &candidate) {
        return candidate.relation == hardRailCycle->relation;
      });
  ASSERT_NE(certificate, tampered.relationCertificates.end());
  certificate->relationTransport = conflictingTransport;
  ASSERT_TRUE(certificate->selectedRelationStep.has_value());
  certificate->selectedRelationStep->appliedTransport = conflictingTransport;
  certificate->evidence.action = conflictingTransport;

  auto rejected =
      directional::pipeline::SurfaceQuotientProducer::
          publish_records_for_validation(*cycleOccurrences, std::move(tampered));
  const auto *error =
      std::get_if<directional::pipeline::SurfaceQuotientProductError>(&rejected);
  ASSERT_NE(error, nullptr);
  EXPECT_EQ(error->code,
            directional::pipeline::SurfaceQuotientProductErrorCode::
                HolonomyConflict);
}

TEST(M6CP1, RelationPlacementTransportIsCoordinateRigidAndFaceGaugeInvariant) {
  const auto firstDraftEdgeOfKind =
      [](const PhaseFrontDraft &draft, const SurfaceFrontBoundaryKind kind) {
        for (std::size_t index = 0; index < draft.edges.size(); ++index) {
          if (draft.edges[index].boundaryKind == kind) {
            return static_cast<int>(index);
          }
        }
        return -1;
      };
  const auto produceA5 = [](const PhaseFrontFixture &fixture,
                            const directional::geometry::SurfacePhaseFrontProduct &front) {
    return directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
        fixture.mesh.V, fixture.mesh.F, front);
  };
  const auto occurrenceFor = [](const auto &occurrences,
                                const directional::authority::OccurrenceId id) {
    return std::find_if(occurrences.begin(), occurrences.end(),
                        [&](const auto &occurrence) {
                          return occurrence.id == id;
                        });
  };
  const auto classMemberSignature = [](const auto &quotient) {
    std::vector<std::vector<directional::authority::OccurrenceId>> members;
    members.reserve(quotient.classes().size());
    for (const auto &entry : quotient.classes()) members.push_back(entry.members);
    std::sort(members.begin(), members.end());
    return members;
  };

  const auto relationEndpointPairs = [](const auto &complex, const auto &front,
                                        const auto &relation)
      -> std::optional<std::array<
          std::pair<directional::authority::OccurrenceId,
                    directional::authority::OccurrenceId>,
          2>> {
    const int firstIndex = relation.evidence.equivalence.firstFrontEdge;
    const int secondIndex = relation.evidence.equivalence.secondFrontEdge;
    if (firstIndex < 0 || secondIndex < 0 ||
        firstIndex >= static_cast<int>(front.edges().size()) ||
        secondIndex >= static_cast<int>(front.edges().size())) {
      return std::nullopt;
    }
    const auto &firstEdge =
        front.edges()[static_cast<std::size_t>(firstIndex)];
    const auto &secondEdge =
        front.edges()[static_cast<std::size_t>(secondIndex)];
    if (firstEdge.filledSide < 0 || firstEdge.filledSide >= 4 ||
        secondEdge.filledSide < 0 || secondEdge.filledSide >= 4) {
      return std::nullopt;
    }
    const auto firstCell = std::find_if(
        complex.cells().begin(), complex.cells().end(), [&](const auto &cell) {
          return cell.id == firstEdge.filledCell;
        });
    const auto secondCell = std::find_if(
        complex.cells().begin(), complex.cells().end(), [&](const auto &cell) {
          return cell.id == secondEdge.filledCell;
        });
    if (firstCell == complex.cells().end() ||
        secondCell == complex.cells().end()) {
      return std::nullopt;
    }
    const std::size_t firstSide =
        static_cast<std::size_t>(firstEdge.filledSide);
    const std::size_t secondSide =
        static_cast<std::size_t>(secondEdge.filledSide);
    return std::array{
        std::pair{firstCell->cornerOccurrences[firstSide],
                  secondCell->cornerOccurrences[(secondSide + 1U) % 4U]},
        std::pair{firstCell->cornerOccurrences[(firstSide + 1U) % 4U],
                  secondCell->cornerOccurrences[secondSide]}};
  };

  const auto &hardRailFixture = hard_rail_fixture();
  auto baselineConstruction = produceA5(
      hardRailFixture, hardRailFixture.network.phaseFront.product());
  const auto *baseline =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &baselineConstruction);
  ASSERT_NE(baseline, nullptr);

  std::map<directional::pipeline::SurfaceOccurrenceRelationId,
           directional::authority::GridAutomorphism>
      hardRailTransportByRelation;
  std::size_t hardRailRelationCount = 0U;
  for (const auto &relation : baseline->owned_relations()) {
    if (relation.id.kind !=
        directional::pipeline::SurfaceOccurrenceRelationKind::HardRail) {
      continue;
    }
    ++hardRailRelationCount;
    ASSERT_TRUE(relation.evidence.canonicalTransport.has_value());
    ASSERT_TRUE(relation.evidence.canonicalRelationValue.has_value());
    ASSERT_TRUE(relation.evidence.canonicalSelectedStep.has_value());
    const auto endpointPairs = relationEndpointPairs(
        *baseline, hardRailFixture.network.phaseFront.product(), relation);
    ASSERT_TRUE(endpointPairs.has_value());
    const bool storageIsCanonical =
        relation.firstOccurrence == relation.id.first;
    for (const auto &[storageFirst, storageSecond] : endpointPairs.value()) {
      const auto fromId = storageIsCanonical ? storageFirst : storageSecond;
      const auto toId = storageIsCanonical ? storageSecond : storageFirst;
      const auto from = occurrenceFor(baseline->occurrences(), fromId);
      const auto to = occurrenceFor(baseline->occurrences(), toId);
      ASSERT_NE(from, baseline->occurrences().end());
      ASSERT_NE(to, baseline->occurrences().end());
      EXPECT_EQ(from->placement.lattice.scaleLevel,
                to->placement.lattice.scaleLevel);
      EXPECT_EQ(relation.evidence.canonicalTransport->apply(
                    from->placement.lattice.latticeCoordinate),
                to->placement.lattice.latticeCoordinate);
    }
    EXPECT_EQ(relation.evidence.equivalence.action,
              relation.evidence.equivalence.route.composed_transport());
    const auto storageRelationValue =
        relation.evidence.equivalence.route.composed_transport();
    const auto expectedRelationValue =
        relation.firstOccurrence == relation.id.first
            ? storageRelationValue
            : storageRelationValue.inverse();
    EXPECT_EQ(relation.evidence.canonicalRelationValue.value(),
              expectedRelationValue);
    EXPECT_EQ(relation.evidence.canonicalSelectedStep->appliedTransport,
              expectedRelationValue);
    hardRailTransportByRelation.emplace(
        relation.id, relation.evidence.canonicalTransport.value());
  }
  ASSERT_GT(hardRailRelationCount, 0U);

  auto baselineQuotientConstruction =
      directional::pipeline::SurfaceQuotientProducer::produce(*baseline);
  const auto *baselineQuotient =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &baselineQuotientConstruction);
  ASSERT_NE(baselineQuotient, nullptr);

  PhaseFrontDraft relabelled =
      phase_front_draft(hardRailFixture.network.phaseFront);
  const int firstHardRail =
      firstDraftEdgeOfKind(relabelled, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(firstHardRail, 0);
  const int opposite =
      relabelled.edges[static_cast<std::size_t>(firstHardRail)].oppositeEdge;
  ASSERT_GE(opposite, 0);
  const auto relabelRegion =
      relabelled.edges[static_cast<std::size_t>(opposite)].sourceTopologyRegion;
  std::size_t relabelledCells = 0U;
  std::size_t relabelledEdges = 0U;
  for (auto &cell : relabelled.cells) {
    if (cell.sourceTopologyRegion != relabelRegion) continue;
    ++relabelledCells;
    for (auto &state : cell.lattice) {
      state.branchRotation = (state.branchRotation + 1) % 4;
    }
  }
  for (auto &edge : relabelled.edges) {
    if (edge.sourceTopologyRegion != relabelRegion) continue;
    ++relabelledEdges;
    ASSERT_FALSE(edge.periodicFromLattice.has_value());
    ASSERT_FALSE(edge.periodicToLattice.has_value());
    edge.fromLattice.branchRotation = (edge.fromLattice.branchRotation + 1) % 4;
    edge.toLattice.branchRotation = (edge.toLattice.branchRotation + 1) % 4;
  }
  ASSERT_EQ(relabelled.sourceFaceBranchRotations.size(),
            static_cast<std::size_t>(hardRailFixture.mesh.F.rows()));
  std::size_t relabelledFaceGauges = 0U;
  for (const auto row : relabelled.sourceAuthority.rows_for_region(relabelRegion)) {
    auto &gauge =
        relabelled.sourceFaceBranchRotations.at(static_cast<std::size_t>(row.index()));
    ASSERT_GE(gauge, 0);
    ASSERT_LE(gauge, 3);
    gauge = (gauge + 1) % 4;
    ++relabelledFaceGauges;
  }
  ASSERT_GT(relabelledFaceGauges, 0U);
  ASSERT_GT(relabelledCells, 0U);
  ASSERT_GT(relabelledEdges, 0U);
  auto relabelledFrontConstruction =
      construct_phase_front_product(std::move(relabelled));
  const auto *relabelledFront =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(
          &relabelledFrontConstruction);
  ASSERT_NE(relabelledFront, nullptr);
  auto relabelledA5Construction = produceA5(hardRailFixture, *relabelledFront);
  const auto *relabelledA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &relabelledA5Construction);
  ASSERT_NE(relabelledA5, nullptr);
  std::size_t relabelledHardRailCount = 0U;
  for (const auto &relation : relabelledA5->owned_relations()) {
    if (relation.id.kind !=
        directional::pipeline::SurfaceOccurrenceRelationKind::HardRail) {
      continue;
    }
    ++relabelledHardRailCount;
    const auto expected = hardRailTransportByRelation.find(relation.id);
    ASSERT_NE(expected, hardRailTransportByRelation.end());
    ASSERT_TRUE(relation.evidence.canonicalTransport.has_value());
    EXPECT_EQ(relation.evidence.canonicalTransport.value(), expected->second);
  }
  EXPECT_EQ(relabelledHardRailCount, hardRailRelationCount);
  auto relabelledQuotientConstruction =
      directional::pipeline::SurfaceQuotientProducer::produce(*relabelledA5);
  const auto *relabelledQuotient =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &relabelledQuotientConstruction);
  ASSERT_NE(relabelledQuotient, nullptr);
  EXPECT_EQ(classMemberSignature(*baselineQuotient),
            classMemberSignature(*relabelledQuotient));

  const auto &periodicWitness = nonzero_z4_torus_witness_fixture();
  const auto semanticRelation =
      produced_semantic_relation_for_witness(periodicWitness);
  ASSERT_TRUE(semanticRelation.has_value());
  const auto g = semanticRelation->semanticAction;
  ASSERT_NE(g.rotation, directional::authority::QuarterTurn{});
  const directional::authority::GridAutomorphism zeroGauge{
      g.rotation.inverse(), {0, 0}};
  const auto expectedPlacement = compose(zeroGauge, g);

  auto periodicConstruction = produceA5(
      periodicWitness.fixture,
      periodicWitness.fixture.network.phaseFront.product());
  const auto *periodic =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &periodicConstruction);
  ASSERT_NE(periodic, nullptr);
  std::size_t witnessPeriodicRelations = 0U;
  for (const auto &relation : periodic->owned_relations()) {
    if (relation.id.kind !=
            directional::pipeline::SurfaceOccurrenceRelationKind::Periodic ||
        relation.id.periodicRelation != semanticRelation->storedRelation->id()) {
      continue;
    }
    ++witnessPeriodicRelations;
    ASSERT_TRUE(relation.evidence.canonicalTransport.has_value());
    ASSERT_TRUE(relation.evidence.canonicalRelationValue.has_value());
    ASSERT_TRUE(relation.evidence.canonicalSelectedStep.has_value());
    EXPECT_TRUE(relation.evidence.canonicalTransport.value() ==
                    expectedPlacement ||
                relation.evidence.canonicalTransport.value() ==
                    expectedPlacement.inverse());
    const auto endpointPairs = relationEndpointPairs(
        *periodic, periodicWitness.fixture.network.phaseFront.product(), relation);
    ASSERT_TRUE(endpointPairs.has_value());
    const bool storageIsCanonical =
        relation.firstOccurrence == relation.id.first;
    for (const auto &[storageFirst, storageSecond] : endpointPairs.value()) {
      const auto fromId = storageIsCanonical ? storageFirst : storageSecond;
      const auto toId = storageIsCanonical ? storageSecond : storageFirst;
      const auto from = occurrenceFor(periodic->occurrences(), fromId);
      const auto to = occurrenceFor(periodic->occurrences(), toId);
      ASSERT_NE(from, periodic->occurrences().end());
      ASSERT_NE(to, periodic->occurrences().end());
      EXPECT_EQ(from->placement.lattice.scaleLevel,
                to->placement.lattice.scaleLevel);
      EXPECT_EQ(relation.evidence.canonicalTransport->apply(
                    from->placement.lattice.latticeCoordinate),
                to->placement.lattice.latticeCoordinate);
    }
    EXPECT_TRUE(relation.evidence.canonicalRelationValue.value() == g ||
                relation.evidence.canonicalRelationValue.value() == g.inverse());
    EXPECT_EQ(relation.evidence.canonicalSelectedStep->appliedTransport,
              relation.evidence.canonicalRelationValue.value());
  }
  EXPECT_EQ(witnessPeriodicRelations, 2U);
}

TEST(M6CP1, A7PublishesOneEmbeddedVertexPerA6Class) {
  const auto &fixture = square_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Construction);
  ASSERT_NE(a6, nullptr);
  auto a7Construction =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  const auto *a7 =
      std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
          &a7Construction);
  ASSERT_NE(a7, nullptr);

  EXPECT_EQ(a6->classes().size(), a7->vertices().size());
  EXPECT_EQ(a6->classes().size(), a7->source_support_certificates().size());
  EXPECT_EQ(a6->classed_cells().size(), a7->topology().size());
  EXPECT_EQ(a7->certificate().quotientClassCount, a7->vertices().size());
  EXPECT_EQ(a7->certificate().embeddedVertexCount, a7->vertices().size());
  EXPECT_TRUE(a7->certificate().exactClassBijection);
  EXPECT_TRUE(a7->certificate().exactCellTopologyCopy);
  EXPECT_TRUE(a7->certificate().completeSourceSupport);
  EXPECT_TRUE(a7->certificate().materializedMeshValid);
}

TEST(M6CP1, A7ExactSourceSupportAcceptsVertexEdgeAndFaceInteriorClasses) {
  std::set<directional::authority::SourceSupportKind> observedKinds;
  const auto consume = [&](const PhaseFrontFixture &fixture) {
    auto a5Construction =
        directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
            fixture.mesh.V, fixture.mesh.F,
            fixture.network.phaseFront.product());
    const auto *a5 =
        std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
            &a5Construction);
    ASSERT_NE(a5, nullptr);
    auto a6Construction =
        directional::pipeline::SurfaceQuotientProducer::produce(*a5);
    const auto *a6 =
        std::get_if<directional::pipeline::SurfaceQuotientProduct>(
            &a6Construction);
    ASSERT_NE(a6, nullptr);
    auto a7Construction =
        directional::pipeline::SourceAttachedGeometryProducer::produce(
            fixture.mesh.V, fixture.mesh.F, *a5, *a6);
    const auto *a7 =
        std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
            &a7Construction);
    ASSERT_NE(a7, nullptr);
    for (const auto &certificate : a7->source_support_certificates()) {
      EXPECT_TRUE(certificate.exactCommonSupport);
      EXPECT_TRUE(certificate.everyMemberFaceIncident);
      EXPECT_TRUE(certificate.sameSimplexPointCoincidence);
      observedKinds.insert(
          directional::authority::support_kind(certificate.publishedSupport));
    }
  };

  consume(square_fixture());
  consume(hard_rail_fixture());
  EXPECT_EQ(observedKinds,
            (std::set<directional::authority::SourceSupportKind>{
                directional::authority::SourceSupportKind::Vertex,
                directional::authority::SourceSupportKind::Edge,
                directional::authority::SourceSupportKind::FaceInterior}));
}

TEST(M6CP1, A7RejectsSupportKindIdentityAndSameSimplexPointMismatches) {
  const auto &fixture = hard_rail_fixture();
  auto baselineConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *baseline =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &baselineConstruction);
  ASSERT_NE(baseline, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*baseline);
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Construction);
  ASSERT_NE(a6, nullptr);
  auto baselineA7Construction =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *baseline, *a6);
  const auto *baselineA7 =
      std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
          &baselineA7Construction);
  ASSERT_NE(baselineA7, nullptr);

  const auto occurrenceFor = [](auto &occurrences,
                                const directional::authority::OccurrenceId id) {
    return std::find_if(occurrences.begin(), occurrences.end(),
                        [&](const auto &occurrence) {
                          return occurrence.id == id;
                        });
  };
  const auto supportCertificateForKind = [&](const auto kind) {
    return std::find_if(
        baselineA7->source_support_certificates().begin(),
        baselineA7->source_support_certificates().end(),
        [&](const auto &certificate) {
          return certificate.members.size() > 1U &&
                 directional::authority::support_kind(
                     certificate.publishedSupport) == kind;
        });
  };
  const auto publishWithOccurrenceMutation = [&](const auto &mutate) {
    auto cells = baseline->cells();
    auto occurrences = baseline->occurrences();
    auto relations = baseline->owned_relations();
    mutate(occurrences);
    return directional::pipeline::SurfaceOccurrenceComplexProducer::
        publish_records_for_validation(std::move(cells), std::move(occurrences),
                                       std::move(relations));
  };
  const auto expectA7Failure = [&](auto a5Construction,
                                   const auto expectedCode,
                                   const std::string &expectedSite) {
    const auto *a5 =
        std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
            &a5Construction);
    ASSERT_NE(a5, nullptr);
    auto rejected =
        directional::pipeline::SourceAttachedGeometryProducer::produce(
            fixture.mesh.V, fixture.mesh.F, *a5, *a6);
    const auto *failure =
        std::get_if<directional::pipeline::GeometryEmbeddingFailure>(&rejected);
    ASSERT_NE(failure, nullptr);
    EXPECT_EQ(failure->code, expectedCode);
    EXPECT_EQ(failure->site, expectedSite);
  };

  const auto multiMember = std::find_if(
      baselineA7->source_support_certificates().begin(),
      baselineA7->source_support_certificates().end(),
      [](const auto &certificate) { return certificate.members.size() > 1U; });
  ASSERT_NE(multiMember, baselineA7->source_support_certificates().end());
  const auto kindTarget = *std::find_if(
      multiMember->members.begin(), multiMember->members.end(),
      [&](const auto member) { return member != multiMember->representative; });
  const auto kindMismatch = publishWithOccurrenceMutation([&](auto &occurrences) {
    auto target = occurrenceFor(occurrences, kindTarget);
    ASSERT_NE(target, occurrences.end());
    const int face = target->point.face;
    ASSERT_GE(face, 0);
    const auto vertex = directional::authority::SourceVertexId::from_index(
        fixture.mesh.F(face, 0),
        static_cast<std::size_t>(fixture.mesh.V.rows()));
    ASSERT_TRUE(vertex.has_value());
    if (directional::authority::support_kind(target->support) ==
        directional::authority::SourceSupportKind::Vertex) {
      const auto edge = directional::authority::SourceEdgeTopologyKey::
          from_indices(fixture.mesh.F(face, 0), fixture.mesh.F(face, 1),
                       static_cast<std::size_t>(fixture.mesh.V.rows()));
      ASSERT_TRUE(edge.has_value());
      target->support = directional::authority::SourceEdgeSupport{edge.value()};
    } else {
      target->support = directional::authority::SourceVertexSupport{vertex.value()};
    }
  });
  expectA7Failure(
      std::move(kindMismatch),
      directional::pipeline::GeometryEmbeddingFailureCode::
          SourceSupportKindMismatch,
      "support-kind");

  const auto exerciseIdentityMismatch =
      [&](const directional::authority::SourceSupportKind kind) {
        const auto certificate = supportCertificateForKind(kind);
        ASSERT_NE(certificate,
                  baselineA7->source_support_certificates().end());
        const auto targetId = *std::find_if(
            certificate->members.begin(), certificate->members.end(),
            [&](const auto member) {
              return member != certificate->representative;
            });
        auto identityMismatch =
            publishWithOccurrenceMutation([&](auto &occurrences) {
              auto target = occurrenceFor(occurrences, targetId);
              ASSERT_NE(target, occurrences.end());
              const int face = target->point.face;
              ASSERT_GE(face, 0);
              if (const auto *vertex =
                      std::get_if<directional::authority::SourceVertexSupport>(
                          &target->support)) {
                bool replaced = false;
                for (int corner = 0; corner < 3 && !replaced; ++corner) {
                  const auto alternate =
                      directional::authority::SourceVertexId::from_index(
                          fixture.mesh.F(face, corner),
                          static_cast<std::size_t>(fixture.mesh.V.rows()));
                  ASSERT_TRUE(alternate.has_value());
                  if (alternate.value() != vertex->vertex) {
                    target->support =
                        directional::authority::SourceVertexSupport{alternate.value()};
                    replaced = true;
                  }
                }
                ASSERT_TRUE(replaced);
              } else if (const auto *edge =
                             std::get_if<
                                 directional::authority::SourceEdgeSupport>(
                                 &target->support)) {
                bool replaced = false;
                for (int corner = 0; corner < 3 && !replaced; ++corner) {
                  const auto alternate =
                      directional::authority::SourceEdgeTopologyKey::
                          from_indices(
                              fixture.mesh.F(face, corner),
                              fixture.mesh.F(face, (corner + 1) % 3),
                              static_cast<std::size_t>(fixture.mesh.V.rows()));
                  ASSERT_TRUE(alternate.has_value());
                  if (alternate.value() != edge->edge) {
                    target->support =
                        directional::authority::SourceEdgeSupport{alternate.value()};
                    replaced = true;
                  }
                }
                ASSERT_TRUE(replaced);
              } else {
                const auto *faceSupport =
                    std::get_if<
                        directional::authority::SourceFaceInteriorSupport>(
                        &target->support);
                ASSERT_NE(faceSupport, nullptr);
                bool replaced = false;
                for (int row = 0;
                     row < fixture.mesh.F.rows() && !replaced; ++row) {
                  const auto first =
                      directional::authority::SourceVertexId::from_index(
                          fixture.mesh.F(row, 0),
                          static_cast<std::size_t>(fixture.mesh.V.rows()));
                  const auto second =
                      directional::authority::SourceVertexId::from_index(
                          fixture.mesh.F(row, 1),
                          static_cast<std::size_t>(fixture.mesh.V.rows()));
                  const auto third =
                      directional::authority::SourceVertexId::from_index(
                          fixture.mesh.F(row, 2),
                          static_cast<std::size_t>(fixture.mesh.V.rows()));
                  ASSERT_TRUE(first.has_value());
                  ASSERT_TRUE(second.has_value());
                  ASSERT_TRUE(third.has_value());
                  const std::array<directional::authority::SourceVertexId, 3>
                      vertices{first.value(), second.value(), third.value()};
                  const auto alternate =
                      directional::authority::SourceFaceTopologyKey::make(
                          vertices);
                  ASSERT_TRUE(alternate.has_value());
                  if (alternate.value() != faceSupport->face) {
                    target->support =
                        directional::authority::SourceFaceInteriorSupport{
                            alternate.value()};
                    replaced = true;
                  }
                }
                ASSERT_TRUE(replaced);
              }
            });
        expectA7Failure(
            std::move(identityMismatch),
            directional::pipeline::GeometryEmbeddingFailureCode::
                SourceSupportIdentityMismatch,
            "support-identity");
      };

  exerciseIdentityMismatch(
      directional::authority::SourceSupportKind::Vertex);
  exerciseIdentityMismatch(
      directional::authority::SourceSupportKind::Edge);
  exerciseIdentityMismatch(
      directional::authority::SourceSupportKind::FaceInterior);

  const auto edgeCertificate = supportCertificateForKind(
      directional::authority::SourceSupportKind::Edge);
  ASSERT_NE(edgeCertificate, baselineA7->source_support_certificates().end());
  const auto edgeTarget = *std::find_if(
      edgeCertificate->members.begin(), edgeCertificate->members.end(),
      [&](const auto member) { return member != edgeCertificate->representative; });
  const auto edgePointMismatch = publishWithOccurrenceMutation([&](auto &occurrences) {
    auto target = occurrenceFor(occurrences, edgeTarget);
    ASSERT_NE(target, occurrences.end());
    const auto *edge =
        std::get_if<directional::authority::SourceEdgeSupport>(&target->support);
    ASSERT_NE(edge, nullptr);
    int firstCorner = -1;
    int secondCorner = -1;
    for (int corner = 0; corner < 3; ++corner) {
      const auto id = directional::authority::SourceVertexId::from_index(
          fixture.mesh.F(target->point.face, corner),
          static_cast<std::size_t>(fixture.mesh.V.rows()));
      ASSERT_TRUE(id.has_value());
      if (id.value() == edge->edge.first()) firstCorner = corner;
      if (id.value() == edge->edge.second()) secondCorner = corner;
    }
    ASSERT_GE(firstCorner, 0);
    ASSERT_GE(secondCorner, 0);
    const double denominator =
        target->point.barycentric(firstCorner) +
        target->point.barycentric(secondCorner);
    ASSERT_NE(denominator, 0.0);
    const double currentParameter =
        target->point.barycentric(secondCorner) / denominator;
    const double changedParameter = currentParameter < 0.5 ? 0.8 : 0.2;
    ASSERT_GT(std::abs(changedParameter - currentParameter), 1.0e-8);
    target->point.barycentric.setZero();
    target->point.barycentric(firstCorner) = 1.0 - changedParameter;
    target->point.barycentric(secondCorner) = changedParameter;
    target->point.position = Eigen::Vector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      target->point.position +=
          target->point.barycentric(corner) *
          fixture.mesh.V.row(fixture.mesh.F(target->point.face, corner))
              .transpose();
    }
    target->point.squaredDistance = 0.0;
  });
  expectA7Failure(
      std::move(edgePointMismatch),
      directional::pipeline::GeometryEmbeddingFailureCode::
          SourceSupportPointMismatch,
      "support-point");

  const auto faceCertificate = supportCertificateForKind(
      directional::authority::SourceSupportKind::FaceInterior);
  ASSERT_NE(faceCertificate, baselineA7->source_support_certificates().end());
  const auto faceTarget = *std::find_if(
      faceCertificate->members.begin(), faceCertificate->members.end(),
      [&](const auto member) { return member != faceCertificate->representative; });
  const auto facePointMismatch = publishWithOccurrenceMutation([&](auto &occurrences) {
    auto target = occurrenceFor(occurrences, faceTarget);
    ASSERT_NE(target, occurrences.end());
    Eigen::Index largest = 0;
    target->point.barycentric.maxCoeff(&largest);
    const Eigen::Index destination = (largest + 1) % 3;
    const double delta = std::min(0.125, target->point.barycentric(largest) * 0.5);
    ASSERT_GT(delta, 1.0e-8);
    target->point.barycentric(largest) -= delta;
    target->point.barycentric(destination) += delta;
    target->point.position = Eigen::Vector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      target->point.position +=
          target->point.barycentric(corner) *
          fixture.mesh.V.row(fixture.mesh.F(target->point.face, corner))
              .transpose();
    }
    target->point.squaredDistance = 0.0;
  });
  expectA7Failure(
      std::move(facePointMismatch),
      directional::pipeline::GeometryEmbeddingFailureCode::
          SourceSupportPointMismatch,
      "support-point");
}

TEST(M6CP1, A7RepresentativeIsInvariantToOccurrenceAndSourceRowOrder) {
  const auto produce = [](const PhaseFrontFixture &fixture) {
    auto a5Construction =
        directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
            fixture.mesh.V, fixture.mesh.F,
            fixture.network.phaseFront.product());
    const auto *a5 =
        std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
            &a5Construction);
    if (a5 == nullptr) {
      throw std::runtime_error("A5 construction failed in A7 permutation test.");
    }
    auto a6Construction =
        directional::pipeline::SurfaceQuotientProducer::produce(*a5);
    const auto *a6 =
        std::get_if<directional::pipeline::SurfaceQuotientProduct>(
            &a6Construction);
    if (a6 == nullptr) {
      throw std::runtime_error("A6 construction failed in A7 permutation test.");
    }
    auto a7Construction =
        directional::pipeline::SourceAttachedGeometryProducer::produce(
            fixture.mesh.V, fixture.mesh.F, *a5, *a6);
    const auto *a7 =
        std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
            &a7Construction);
    if (a7 == nullptr) {
      throw std::runtime_error("A7 construction failed in A7 permutation test.");
    }
    return *a7;
  };

  const auto baseline = produce(square_fixture());
  const auto permuted = produce(make_square_fixture_with_reversed_source_face_rows());
  ASSERT_EQ(baseline.vertices().size(), permuted.vertices().size());
  for (std::size_t row = 0; row < baseline.vertices().size(); ++row) {
    const auto &first = baseline.vertices()[row];
    const auto match = std::find_if(
        permuted.vertices().begin(), permuted.vertices().end(),
        [&](const auto &candidate) {
          return candidate.quotientClass == first.quotientClass;
        });
    ASSERT_NE(match, permuted.vertices().end());
    EXPECT_EQ(first.representative, match->representative);
    EXPECT_EQ(first.support, match->support);
    EXPECT_TRUE(first.position.isApprox(match->position, 1.0e-12));
    EXPECT_EQ(first.sourceTopologyRegions, match->sourceTopologyRegions);
    EXPECT_EQ(first.sourceCharts, match->sourceCharts);
    EXPECT_EQ(first.sourceIsolationSheets, match->sourceIsolationSheets);
  }
}

TEST(M6CP1, A7ProjectsCompleteClassLineageAndSelectedRelationValues) {
  const auto &fixture = hard_rail_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Construction);
  ASSERT_NE(a6, nullptr);
  auto a7Construction =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  const auto *a7 =
      std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
          &a7Construction);
  ASSERT_NE(a7, nullptr);

  for (const auto &vertex : a7->vertices()) {
    const auto quotient = std::find_if(
        a6->classes().begin(), a6->classes().end(), [&](const auto &candidate) {
          return candidate.id == vertex.quotientClass;
        });
    ASSERT_NE(quotient, a6->classes().end());
    EXPECT_EQ(vertex.sourceOccurrences, quotient->members);
    EXPECT_EQ(vertex.equivalences, quotient->equivalences);

    std::set<directional::authority::TopologyRegionId> expectedRegions;
    std::set<directional::geometry::SourceProjectionChart> expectedCharts;
    std::set<directional::authority::IsolationSheetId> expectedSheets;
    for (const auto member : quotient->members) {
      const auto occurrence = std::find_if(
          a5->occurrences().begin(), a5->occurrences().end(),
          [&](const auto &candidate) { return candidate.id == member; });
      ASSERT_NE(occurrence, a5->occurrences().end());
      expectedRegions.insert(occurrence->topologyRegion);
      expectedSheets.insert(occurrence->cornerWedgeSheets.begin(),
                            occurrence->cornerWedgeSheets.end());
      for (const auto &binding : occurrence->cornerWedgeBindings) {
        expectedCharts.insert(binding.chart);
      }
    }
    EXPECT_EQ(vertex.sourceTopologyRegions,
              (std::vector<directional::authority::TopologyRegionId>(
                  expectedRegions.begin(), expectedRegions.end())));
    EXPECT_EQ(vertex.sourceCharts,
              (std::vector<directional::geometry::SourceProjectionChart>(
                  expectedCharts.begin(), expectedCharts.end())));
    EXPECT_EQ(vertex.sourceIsolationSheets,
              (std::vector<directional::authority::IsolationSheetId>(
                  expectedSheets.begin(), expectedSheets.end())));

    std::vector<directional::geometry::SelectedRelationPathCertificate>
        expectedPaths;
    for (const auto &path : a6->selected_paths()) {
      if (path.quotientClass == vertex.quotientClass &&
          path.legacyProjection.has_value()) {
        expectedPaths.push_back(*path.legacyProjection);
      }
    }
    std::sort(expectedPaths.begin(), expectedPaths.end());
    expectedPaths.erase(std::unique(expectedPaths.begin(), expectedPaths.end()),
                        expectedPaths.end());
    EXPECT_EQ(vertex.selectedRelationPaths, expectedPaths);
  }
}

TEST(M6CP1, A7NeverConsumesPlacementTransportForGeometryOrLineage) {
  const auto &fixture = hard_rail_fixture();
  auto baselineA5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *baselineA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &baselineA5Construction);
  ASSERT_NE(baselineA5, nullptr);
  auto baselineA6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*baselineA5);
  const auto *baselineA6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &baselineA6Construction);
  ASSERT_NE(baselineA6, nullptr);

  const auto joining = std::find_if(
      baselineA6->relation_consumptions().begin(),
      baselineA6->relation_consumptions().end(), [](const auto &consumption) {
        return consumption.disposition ==
               directional::pipeline::QuotientRelationDisposition::Joining;
      });
  ASSERT_NE(joining, baselineA6->relation_consumptions().end());

  auto cells = baselineA5->cells();
  auto occurrences = baselineA5->occurrences();
  auto relations = baselineA5->owned_relations();
  auto relation = std::find_if(relations.begin(), relations.end(),
                               [&](const auto &candidate) {
                                 return candidate.id == joining->relation;
                               });
  ASSERT_NE(relation, relations.end());
  ASSERT_TRUE(relation->evidence.canonicalTransport.has_value());
  relation->evidence.canonicalTransport->shift.x += 7;

  auto mutatedA5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::
          publish_records_for_validation(std::move(cells),
                                         std::move(occurrences),
                                         std::move(relations));
  const auto *mutatedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &mutatedA5Construction);
  ASSERT_NE(mutatedA5, nullptr);
  auto baselineA7Construction =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *baselineA5, *baselineA6);
  const auto *baselineA7 =
      std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
          &baselineA7Construction);
  ASSERT_NE(baselineA7, nullptr);
  auto mutatedA7Construction =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *mutatedA5, *baselineA6);
  const auto *mutatedA7 =
      std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
          &mutatedA7Construction);
  ASSERT_NE(mutatedA7, nullptr);

  ASSERT_EQ(baselineA7->vertices().size(), mutatedA7->vertices().size());
  for (std::size_t row = 0; row < baselineA7->vertices().size(); ++row) {
    const auto &first = baselineA7->vertices()[row];
    const auto &second = mutatedA7->vertices()[row];
    EXPECT_EQ(first.quotientClass, second.quotientClass);
    EXPECT_EQ(first.representative, second.representative);
    EXPECT_EQ(first.support, second.support);
    EXPECT_EQ(first.sourceOccurrences, second.sourceOccurrences);
    EXPECT_TRUE(first.position.isApprox(second.position, 1.0e-12));
    EXPECT_EQ(first.sourceTopologyRegions, second.sourceTopologyRegions);
    EXPECT_EQ(first.sourceCharts, second.sourceCharts);
    EXPECT_EQ(first.sourceIsolationSheets, second.sourceIsolationSheets);
    EXPECT_EQ(first.equivalences, second.equivalences);
    EXPECT_EQ(first.selectedRelationPaths, second.selectedRelationPaths);
  }
  EXPECT_EQ(baselineA7->topology(), mutatedA7->topology());
  EXPECT_EQ(baselineA7->boundary_loops(), mutatedA7->boundary_loops());
  EXPECT_TRUE(baselineA7->certificate().noPlacementTransportConsumed);
  EXPECT_TRUE(mutatedA7->certificate().noPlacementTransportConsumed);
}

TEST(M6CP1, A7CopiesA6TopologyWithoutClassMutation) {
  const auto &fixture = square_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Construction);
  ASSERT_NE(a6, nullptr);
  auto a7Construction =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  const auto *a7 =
      std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
          &a7Construction);
  ASSERT_NE(a7, nullptr);

  EXPECT_EQ(a7->topology(), a6->classed_cells());
  EXPECT_TRUE(a7->certificate().exactCellTopologyCopy);
  std::vector<directional::pipeline::SurfaceQuotientClassId> a6Classes;
  std::vector<directional::pipeline::SurfaceQuotientClassId> a7Classes;
  for (const auto &quotient : a6->classes()) a6Classes.push_back(quotient.id);
  for (const auto &vertex : a7->vertices()) a7Classes.push_back(vertex.quotientClass);
  EXPECT_EQ(a7Classes, a6Classes);
}

TEST(M6CP1, NonzeroZ4WitnessPassesProductionCompletionOwnership) {
  const auto &witness = nonzero_z4_torus_witness_fixture();
  const auto materialized =
      directional::pipeline::build_authoritative_phase_front_mesh(
          witness.fixture.mesh.V, witness.fixture.mesh.F,
          witness.fixture.network.phaseFront.product());
  ASSERT_TRUE(materialized.success) << materialized.failure;

  const auto hardEdges = torus_row408_hard_edges(witness.fixture.mesh);
  const auto &sourceAuthority =
      witness.fixture.network.phaseFront.product().sourceTopologyRegions();

  auto tampered = materialized.mesh;
  auto lineage = std::find_if(
      tampered.vertexLineage.begin(), tampered.vertexLineage.end(),
      [](const auto &candidate) {
        return !candidate.sourceOccurrences.empty() &&
               candidate.sourceIsolationSheets.size() >= 2U;
      });
  ASSERT_NE(lineage, tampered.vertexLineage.end());
  const auto representativeFace = directional::authority::SourceFaceId::from_index(
      lineage->sourcePoint.face, sourceAuthority.face_count());
  ASSERT_TRUE(representativeFace);
  const auto representativeSheet =
      sourceAuthority.sheet_for_row(representativeFace.value());
  const auto representativeSheetPosition =
      std::find(lineage->sourceIsolationSheets.begin(),
                lineage->sourceIsolationSheets.end(), representativeSheet);
  ASSERT_NE(representativeSheetPosition, lineage->sourceIsolationSheets.end());
  lineage->sourceIsolationSheets.erase(representativeSheetPosition);

  std::string failure;
  EXPECT_FALSE(directional::geometry::pure_quad_detail::
                   validate_materialized_completion_domain_ownership(
                       tampered, witness.fixture.mesh.F, &sourceAuthority,
                       &hardEdges, failure));
  EXPECT_EQ(
      "CompletionOwnershipInvalidRetainedSourceAuthority:representative-face",
      failure);

  auto mesh = materialized.mesh;
  failure.clear();
  EXPECT_TRUE(directional::geometry::pure_quad_detail::
                  validate_materialized_completion_domain_ownership(
                      mesh, witness.fixture.mesh.F, &sourceAuthority,
                      &hardEdges, failure))
      << failure;
  EXPECT_TRUE(failure.empty());
}


int first_edge_of_kind(const PhaseFrontDraft &phaseFront,
                       const SurfaceFrontBoundaryKind kind);

TEST(M6CP1, A5OwnsPhaseFrontRegionAndBoundaryValidationBeforeA6) {
  const auto &fixture = square_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int ordinary =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::OrdinaryInterior);
  ASSERT_GE(ordinary, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(ordinary)];
  const int opposite = edge.oppositeEdge;
  ASSERT_GE(opposite, 0);
  const auto interiorTopology = test_source_edge_topology(
      0, 2, static_cast<std::size_t>(fixture.mesh.V.rows()));
  edge.oppositeEdge = -1;
  edge.exterior = true;
  edge.boundaryKind = SurfaceFrontBoundaryKind::GenuineSourceBoundary;
  edge.route = boundary_route_from_topology(interiorTopology);
  auto &other = tampered.edges[static_cast<std::size_t>(opposite)];
  other.oppositeEdge = -1;
  other.exterior = true;
  other.boundaryKind = SurfaceFrontBoundaryKind::GenuineSourceBoundary;
  other.route = boundary_route_from_topology(interiorTopology);

  auto construction = construct_phase_front_product(std::move(tampered));
  const auto *front =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&construction);
  ASSERT_NE(front, nullptr);
  auto a5 = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *front);
  const auto *error =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(&a5);
  ASSERT_NE(error, nullptr);
  EXPECT_EQ(directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                FalseAuthoritativeSourceBoundary,
            error->code);
}

TEST(M6CP1, A5OwnsIsolationAndHardRailRouteValidationWithFrozenNames) {
  const auto &fixture = hard_rail_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_TRUE(route_is_all_interior(edge.route));
  std::vector<directional::authority::TransitionStep> steps(
      edge.route.steps().begin(), edge.route.steps().end());
  steps.push_back(steps.front());
  edge.route = directional::authority::CanonicalRoute::from_observed_steps(
      std::move(steps));

  auto construction = construct_phase_front_product(std::move(tampered));
  const auto *front =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&construction);
  ASSERT_NE(front, nullptr);
  auto a5 = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *front);
  const auto *error =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(&a5);
  ASSERT_NE(error, nullptr);
  EXPECT_TRUE(
      error->code == directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                         HardRailRouteAuthorityInvalid ||
      error->code == directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                         InvalidHardRailAuthority);

  const auto adapter = directional::pipeline::build_authoritative_phase_front_mesh(
      fixture.mesh.V, fixture.mesh.F, *front);
  EXPECT_FALSE(adapter.success);
  EXPECT_EQ("InvalidHardRailAuthority", adapter.failure);

  auto splitA5 = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      split_isolation_fixture().mesh.V, split_isolation_fixture().mesh.F,
      split_isolation_fixture().network.phaseFront.product());
  EXPECT_NE(std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&splitA5),
            nullptr);
}

TEST(M6CP1, A5ValidationPrecedencePreservesHardRailAuthorityBeforeTransport) {
  const auto &fixture = hard_rail_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_TRUE(route_is_all_interior(edge.route));
  std::vector<directional::authority::TransitionStep> steps(
      edge.route.steps().begin(), edge.route.steps().end());
  steps.push_back(steps.front());
  edge.route = directional::authority::CanonicalRoute::from_observed_steps(
      std::move(steps));

  auto construction = construct_phase_front_product(std::move(tampered));
  const auto *front =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&construction);
  ASSERT_NE(front, nullptr);
  auto a5 = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *front);
  const auto *a5Error =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(&a5);
  ASSERT_NE(a5Error, nullptr)
      << "A5 must stop malformed HardRail authority before A6 transport";
  const auto adapter = directional::pipeline::build_authoritative_phase_front_mesh(
      fixture.mesh.V, fixture.mesh.F, *front);
  EXPECT_FALSE(adapter.success);
  EXPECT_EQ("InvalidHardRailAuthority", adapter.failure);
}


TEST(M6CP1, ThinAdapterOutputIsPureProjectionOfStageProducts) {
  const auto expect_surface_point_equal = [](const auto &actual,
                                             const auto &expected) {
    EXPECT_EQ(actual.face, expected.face);
    EXPECT_EQ(actual.component, expected.component);
    EXPECT_EQ(actual.sheet, expected.sheet);
    for (int axis = 0; axis < 3; ++axis) {
      EXPECT_EQ(actual.barycentric(axis), expected.barycentric(axis));
      EXPECT_EQ(actual.position(axis), expected.position(axis));
    }
    EXPECT_EQ(actual.squaredDistance, expected.squaredDistance);
  };

  const auto verify = [&](const auto &fixture) {
    const auto &front = fixture.network.phaseFront.product();
    auto a5Construction =
        directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
            fixture.mesh.V, fixture.mesh.F, front);
    const auto *a5 =
        std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
            &a5Construction);
    ASSERT_NE(a5, nullptr);
    auto a6Construction = directional::pipeline::SurfaceQuotientProducer::produce(*a5);
    const auto *a6 =
        std::get_if<directional::pipeline::SurfaceQuotientProduct>(
            &a6Construction);
    ASSERT_NE(a6, nullptr);
    auto a7Construction =
        directional::pipeline::SourceAttachedGeometryProducer::produce(
            fixture.mesh.V, fixture.mesh.F, *a5, *a6);
    const auto *a7 =
        std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
            &a7Construction);
    ASSERT_NE(a7, nullptr);

    const auto adapter =
        directional::pipeline::build_authoritative_phase_front_mesh(
            fixture.mesh.V, fixture.mesh.F, front);
    ASSERT_TRUE(adapter.success) << adapter.failure;
    EXPECT_TRUE(adapter.failure.empty());
    EXPECT_EQ(adapter.invalidCell, -1);
    EXPECT_EQ(adapter.invalidEdge, -1);
    EXPECT_EQ(adapter.connectedComponents,
              a7->certificate().connectedComponents);
    EXPECT_EQ(adapter.boundaryLoopCount,
              static_cast<int>(a7->certificate().boundaryLoopCount));
    EXPECT_EQ(adapter.eulerCharacteristic,
              a7->certificate().eulerCharacteristic);

    std::set<directional::authority::TopologyRegionId> expectedRegions;
    for (const auto &occurrence : a5->occurrences()) {
      expectedRegions.insert(occurrence.topologyRegion);
    }
    EXPECT_EQ(adapter.consumedTopologyRegions, expectedRegions.size());
    EXPECT_EQ(adapter.consumedInternalIsolationSeams,
              a5->certificate().validatedIsolationCertificateCount);
    std::set<directional::authority::PeriodicRelationId> expectedPeriodic;
    for (const auto &certificate : a6->relation_certificates()) {
      if (certificate.relation.periodicRelation.has_value()) {
        expectedPeriodic.insert(certificate.relation.periodicRelation.value());
      }
    }
    EXPECT_EQ(adapter.consumedPeriodicHolonomies, expectedPeriodic.size());

    EXPECT_EQ(adapter.mesh.sourcePatch, 0);
    EXPECT_EQ(adapter.mesh.domainIdentity,
              directional::geometry::SurfaceCellDomainIdentity{});
    EXPECT_EQ(adapter.mesh.backend,
              directional::geometry::PureQuadCompletionBackend::ClosedForm);
    EXPECT_FALSE(adapter.mesh.usesCenterFan);
    EXPECT_TRUE(adapter.mesh.boundaryNodeIdentities.empty());
    EXPECT_TRUE(adapter.mesh.sourceSideEdgeCounts.empty());

    const std::size_t vertexCount = a7->vertices().size();
    ASSERT_EQ(adapter.mesh.vertices.size(), vertexCount);
    ASSERT_EQ(adapter.mesh.vertexPositions.rows(),
              static_cast<int>(vertexCount));
    ASSERT_EQ(adapter.mesh.vertexPositions.cols(), 3);
    ASSERT_EQ(adapter.mesh.vertexProvenance.size(), vertexCount);
    ASSERT_EQ(adapter.mesh.vertexLineage.size(), vertexCount);

    std::map<directional::pipeline::SurfaceQuotientClassId, int> rowByClass;
    for (std::size_t row = 0; row < vertexCount; ++row) {
      const auto &expected = a7->vertices()[row];
      ASSERT_TRUE(rowByClass.emplace(expected.quotientClass,
                                     static_cast<int>(row)).second);
      EXPECT_EQ(adapter.mesh.vertices[row], static_cast<int>(row));
      for (int axis = 0; axis < 3; ++axis) {
        EXPECT_EQ(adapter.mesh.vertexPositions(static_cast<int>(row), axis),
                  expected.position(axis));
      }
      expect_surface_point_equal(adapter.mesh.vertexProvenance[row],
                                 expected.sourcePoint);

      const auto &lineage = adapter.mesh.vertexLineage[row];
      EXPECT_EQ(lineage.outputVertex, static_cast<int>(row));
      EXPECT_EQ(lineage.kind,
                directional::geometry::PureQuadVertexLineageKind::SourceTriangle);
      expect_surface_point_equal(lineage.sourcePoint, expected.sourcePoint);
      const directional::geometry::PureQuadFeatureIntervalLineage defaultFeature{};
      EXPECT_EQ(lineage.featureInterval.railId, defaultFeature.railId);
      EXPECT_EQ(lineage.featureInterval.curveId, defaultFeature.curveId);
      expect_surface_point_equal(lineage.featureInterval.start,
                                 defaultFeature.start);
      expect_surface_point_equal(lineage.featureInterval.end,
                                 defaultFeature.end);
      EXPECT_EQ(lineage.featureInterval.parameter, defaultFeature.parameter);
      EXPECT_EQ(lineage.stitchIdentity,
                directional::geometry::PureQuadStitchIdentity{});
      EXPECT_EQ(lineage.authoritativeIdentity,
                directional::geometry::PureQuadStitchIdentity{});
      EXPECT_EQ(lineage.sourcePatch, 0);
      EXPECT_EQ(lineage.localVertex, static_cast<int>(row));
      EXPECT_EQ(lineage.sourceTopologyRegions, expected.sourceTopologyRegions);
      EXPECT_EQ(lineage.sourceCharts, expected.sourceCharts);
      EXPECT_EQ(lineage.sourceIsolationSheets, expected.sourceIsolationSheets);
      EXPECT_EQ(lineage.sourceSupport, expected.support);
      const auto compatibilityId = directional::authority::QuotientClassId::from_index(
          row, vertexCount);
      ASSERT_TRUE(compatibilityId);
      EXPECT_EQ(lineage.quotientClass, compatibilityId.value());
      EXPECT_EQ(lineage.sourceOccurrences, expected.sourceOccurrences);
      EXPECT_EQ(lineage.equivalences, expected.equivalences);
      EXPECT_EQ(lineage.selectedRelationPaths, expected.selectedRelationPaths);
    }

    const auto canonical_cycle = [](const std::vector<int> &cycle) {
      std::vector<int> best;
      for (std::size_t offset = 0; offset < cycle.size(); ++offset) {
        std::vector<int> rotated;
        rotated.reserve(cycle.size());
        for (std::size_t index = 0; index < cycle.size(); ++index) {
          rotated.push_back(cycle[(offset + index) % cycle.size()]);
        }
        if (best.empty() || rotated < best) best = std::move(rotated);
      }
      return best;
    };
    struct ExpectedQuad {
      std::vector<int> vertices;
      std::vector<int> canonical;
      int cellIndex = -1;
    };
    std::vector<ExpectedQuad> expectedQuads;
    for (const auto &cell : a7->topology()) {
      ExpectedQuad expected;
      expected.cellIndex = static_cast<int>(cell.id.index());
      for (const auto &corner : cell.corners) {
        expected.vertices.push_back(rowByClass.at(corner));
      }
      expected.canonical = canonical_cycle(expected.vertices);
      expectedQuads.push_back(std::move(expected));
    }
    std::sort(expectedQuads.begin(), expectedQuads.end(),
              [](const auto &first, const auto &second) {
                return first.canonical < second.canonical;
              });
    ASSERT_EQ(adapter.mesh.quads.size(), expectedQuads.size());
    ASSERT_EQ(adapter.mesh.quadLineage.size(), expectedQuads.size());
    for (std::size_t row = 0; row < expectedQuads.size(); ++row) {
      EXPECT_EQ(adapter.mesh.quads[row], expectedQuads[row].vertices);
      const auto &lineage = adapter.mesh.quadLineage[row];
      EXPECT_EQ(lineage.outputQuad, static_cast<int>(row));
      EXPECT_EQ(lineage.sourcePatch, 0);
      EXPECT_EQ(lineage.operation,
                directional::geometry::PureQuadCompletionBackend::ClosedForm);
      EXPECT_EQ(lineage.operationLocalQuad, expectedQuads[row].cellIndex);
      EXPECT_EQ(lineage.completionVariant, 0);
      EXPECT_FALSE(lineage.boundaryOnly);
      EXPECT_EQ(lineage.canonicalStitchCycleHash, 0U);
      EXPECT_EQ(lineage.canonicalAuthoritativeCycleHash, 0U);
    }

    std::vector<std::vector<int>> expectedBoundaryLoops;
    for (const auto &classLoop : a7->boundary_loops()) {
      std::vector<int> loop;
      for (const auto &quotientClass : classLoop) {
        loop.push_back(rowByClass.at(quotientClass));
      }
      if (!loop.empty()) {
        const auto minimum = std::min_element(loop.begin(), loop.end());
        std::rotate(loop.begin(), minimum, loop.end());
      }
      expectedBoundaryLoops.push_back(std::move(loop));
    }
    std::sort(expectedBoundaryLoops.begin(), expectedBoundaryLoops.end());
    EXPECT_EQ(adapter.mesh.boundaryLoops, expectedBoundaryLoops);
    std::vector<int> expectedBoundaryVertices;
    for (const auto &loop : expectedBoundaryLoops) {
      expectedBoundaryVertices.insert(expectedBoundaryVertices.end(),
                                      loop.begin(), loop.end());
    }
    EXPECT_EQ(adapter.mesh.boundaryVertices, expectedBoundaryVertices);
  };

  verify(hard_rail_fixture());
  verify(split_isolation_fixture());
  verify(nonzero_z4_torus_witness_fixture().fixture);
}


TEST(M6CP1, A6ClosedComplexBoundaryIsCombinatoriallyEquivalentOnProducedTorus) {
  const auto &fixture = torus_fixture();
  const auto hardEdges = torus_row408_hard_edges(fixture.mesh);
  const auto run = run_retained_torus_pipeline();
  ASSERT_TRUE(run.surfaceCellContext.hasTraceNetwork);
  ASSERT_TRUE(run.surfaceCellContext.hasArrangement);
  const auto &network = run.surfaceCellContext.productSnapshots.traceNetwork;
  const auto &phaseFront = network.phaseFront.product();
  ASSERT_EQ(network.proposals.size(), phaseFront.cells().size());
  const auto samePoint = [](const directional::geometry::SurfaceTracePoint &first,
                            const directional::geometry::SurfaceTracePoint &second) {
    return first.face == second.face &&
           (first.barycentric.array() == second.barycentric.array()).all();
  };
  const auto sameSegment = [](
                               const directional::geometry::SurfaceTraceSegment &first,
                               const directional::geometry::SurfaceTraceSegment &second) {
    return first.face == second.face &&
           (first.startBarycentric.array() == second.startBarycentric.array()).all() &&
           (first.endBarycentric.array() == second.endBarycentric.array()).all() &&
           first.family == second.family && first.sign == second.sign &&
           first.entryEdge == second.entryEdge && first.exitEdge == second.exitEdge &&
           first.matching == second.matching &&
           first.matchingEffort == second.matchingEffort &&
           first.sourceChart == second.sourceChart &&
           first.entryRoute == second.entryRoute && first.railId == second.railId &&
           first.curveId == second.curveId &&
           first.railIntervalIndex == second.railIntervalIndex &&
           first.railSideSign == second.railSideSign && first.railT0 == second.railT0 &&
           first.railT1 == second.railT1;
  };
  for (std::size_t row = 0; row < network.proposals.size(); ++row) {
    for (std::size_t corner = 0; corner < 4U; ++corner) {
      EXPECT_TRUE(samePoint(network.proposals[row].corners[corner],
                            phaseFront.cells()[row].corners[corner]));
    }
    for (std::size_t side = 0; side < 4U; ++side) {
      const auto &proposalPath = network.proposals[row].boundaryPaths[side];
      const auto &cellPath = phaseFront.cells()[row].boundaryPaths[side];
      ASSERT_EQ(proposalPath.size(), cellPath.size());
      for (std::size_t segment = 0; segment < proposalPath.size(); ++segment) {
        EXPECT_TRUE(sameSegment(proposalPath[segment], cellPath[segment]));
      }
    }
  }

  const auto view =
      build_torus_closed_complex_view(fixture.mesh, phaseFront, hardEdges);
  ASSERT_TRUE(view.has_value());
  ASSERT_TRUE(view->closed);
  ASSERT_TRUE(view->edgeIncidenceBijection);
  ASSERT_TRUE(view->protectionLabelsCertified);
  const auto &arrangement = run.surfaceCellContext.productSnapshots.arrangement;

  using ChainKey = std::pair<int, int>;
  std::map<ChainKey, std::set<int>> chainEdges;
  std::set<int> proposalOwnedEdges;
  for (const auto &halfedge : arrangement.halfedges) {
    if (halfedge.twin < 0 ||
        halfedge.twin >= static_cast<int>(arrangement.halfedges.size())) {
      continue;
    }
    const int canonical = std::min(halfedge.id, halfedge.twin);
    for (const auto &provenance : halfedge.provenance) {
      if (provenance.proposalId < 0 || provenance.proposalSide < 0) continue;
      ASSERT_LT(provenance.proposalId, static_cast<int>(network.proposals.size()));
      ASSERT_LT(provenance.proposalSide, 4);
      chainEdges[{provenance.proposalId, provenance.proposalSide}].insert(canonical);
      proposalOwnedEdges.insert(canonical);
    }
  }
  for (const auto &halfedge : arrangement.halfedges) {
    if (halfedge.twin < 0 || halfedge.id > halfedge.twin) continue;
    EXPECT_EQ(proposalOwnedEdges.count(halfedge.id), 1U)
        << "non-proposal arrangement edge " << halfedge.id;
  }

  struct ChainShape {
    std::set<int> edges;
    std::set<int> nodes;
    std::set<int> endpoints;
    bool hardFeature = false;
  };
  std::map<ChainKey, ChainShape> chains;
  for (const auto &[key, edgeIds] : chainEdges) {
    ChainShape shape;
    shape.edges = edgeIds;
    std::map<int, int> degree;
    std::optional<bool> hardFeature;
    for (const int edgeId : edgeIds) {
      ASSERT_GE(edgeId, 0);
      ASSERT_LT(edgeId, static_cast<int>(arrangement.halfedges.size()));
      const auto &edge = arrangement.halfedges[static_cast<std::size_t>(edgeId)];
      ASSERT_GE(edge.twin, 0);
      const auto &twin = arrangement.halfedges[static_cast<std::size_t>(edge.twin)];
      ++degree[edge.from];
      ++degree[edge.to];
      shape.nodes.insert(edge.from);
      shape.nodes.insert(edge.to);
      const bool edgeHardFeature = edge.hardFeature || twin.hardFeature;
      if (!hardFeature.has_value()) hardFeature = edgeHardFeature;
      EXPECT_EQ(edgeHardFeature, hardFeature.value());
    }
    for (const auto &[node, nodeDegree] : degree) {
      if (nodeDegree == 1) {
        shape.endpoints.insert(node);
      } else {
        EXPECT_EQ(nodeDegree, 2) << "chain interior node=" << node;
      }
    }
    EXPECT_EQ(shape.endpoints.size(), 2U);
    shape.hardFeature = hardFeature.value_or(false);
    chains.emplace(key, std::move(shape));
  }

  auto occurrenceConstruction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, phaseFront);
  const auto *occurrenceComplex =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &occurrenceConstruction);
  ASSERT_NE(occurrenceComplex, nullptr);

  std::map<directional::authority::CellId, int> rowByCell;
  std::map<directional::authority::CellId,
           const directional::pipeline::SurfaceOccurrenceCell *>
      occurrenceCellById;
  for (std::size_t row = 0; row < phaseFront.cells().size(); ++row) {
    rowByCell.emplace(phaseFront.cells()[row].id, static_cast<int>(row));
  }
  for (const auto &cell : occurrenceComplex->cells()) {
    occurrenceCellById.emplace(cell.id, &cell);
  }

  std::map<directional::authority::OccurrenceId, int> nodeByOccurrence;
  for (const auto &quad : view->quads) {
    const int row = rowByCell.at(quad.id);
    const auto *cell = occurrenceCellById.at(quad.id);
    for (int corner = 0; corner < 4; ++corner) {
      const auto &previous = chains.at({row, (corner + 3) % 4}).nodes;
      const auto &next = chains.at({row, corner}).nodes;
      std::vector<int> intersection;
      std::set_intersection(previous.begin(), previous.end(), next.begin(), next.end(),
                            std::back_inserter(intersection));
      ASSERT_EQ(intersection.size(), 1U);
      const auto occurrence = cell->cornerOccurrences[static_cast<std::size_t>(corner)];
      ASSERT_TRUE(nodeByOccurrence.emplace(occurrence, intersection.front()).second);
    }
  }
  EXPECT_EQ(nodeByOccurrence.size(), occurrenceComplex->occurrences().size());

  std::map<directional::pipeline::SurfaceOccurrenceRelationId,
           const directional::pipeline::SurfaceOccurrenceRelation *>
      relationById;
  for (const auto &relation : occurrenceComplex->owned_relations()) {
    ASSERT_TRUE(relationById.emplace(relation.id, &relation).second);
  }
  const auto relationHasIsolation = [](const auto &relation) {
    if (!relation.evidence.equivalence.isolationTransitions.empty() ||
        !relation.evidence.firstSideIsolationEvidence.empty() ||
        !relation.evidence.secondSideIsolationEvidence.empty()) {
      return true;
    }
    const auto spanHasIsolation = [](const auto &span) {
      return span.has_value() && !span->isolationTransitions.empty();
    };
    return spanHasIsolation(relation.evidence.firstEndpointSpan) ||
           spanHasIsolation(relation.evidence.secondEndpointSpan);
  };
  const auto sideHasIsolation = [&](const auto &side) {
    const auto *cell = occurrenceCellById.at(side.cell);
    const auto &authority =
        cell->directedSideAuthority[static_cast<std::size_t>(side.side)];
    if (!authority.isolationEvidence.empty()) return true;
    return std::any_of(authority.spans.begin(), authority.spans.end(),
                       [](const auto &span) {
                         return !span.isolationTransitions.empty();
                       });
  };

  std::map<directional::pipeline::SurfaceQuotientSideId, int> frontEdgeBySide;
  for (std::size_t edgeIndex = 0; edgeIndex < phaseFront.edges().size(); ++edgeIndex) {
    const auto &frontEdge = phaseFront.edges()[edgeIndex];
    if (frontEdge.filledSide < 0 || frontEdge.filledSide >= 4) continue;
    ASSERT_TRUE(frontEdgeBySide
                    .emplace(directional::pipeline::SurfaceQuotientSideId{
                                 frontEdge.filledCell,
                                 static_cast<std::uint8_t>(frontEdge.filledSide)},
                             static_cast<int>(edgeIndex))
                    .second);
  }

  for (const auto &edge : view->edges) {
    ASSERT_EQ(edge.id.incidentSides.size(), 2U);
    const auto firstSide = edge.id.incidentSides[0];
    const auto secondSide = edge.id.incidentSides[1];
    const auto *firstCell = occurrenceCellById.at(firstSide.cell);
    const auto *secondCell = occurrenceCellById.at(secondSide.cell);
    const auto firstDirected =
        firstCell->directedSides[static_cast<std::size_t>(firstSide.side)];
    const auto secondDirected =
        secondCell->directedSides[static_cast<std::size_t>(secondSide.side)];

    const auto &firstChain = chains.at(
        {rowByCell.at(firstSide.cell), static_cast<int>(firstSide.side)});
    const auto &secondChain = chains.at(
        {rowByCell.at(secondSide.cell), static_cast<int>(secondSide.side)});
    EXPECT_EQ(firstChain.hardFeature, edge.hardFeatureProtected);
    EXPECT_EQ(secondChain.hardFeature, edge.hardFeatureProtected);
    EXPECT_EQ(firstChain.endpoints,
              (std::set<int>{nodeByOccurrence.at(firstDirected.first),
                             nodeByOccurrence.at(firstDirected.second)}));
    EXPECT_EQ(secondChain.endpoints,
              (std::set<int>{nodeByOccurrence.at(secondDirected.first),
                             nodeByOccurrence.at(secondDirected.second)}));

    const int firstFront = frontEdgeBySide.at(firstSide);
    const int secondFront = frontEdgeBySide.at(secondSide);
    ASSERT_EQ(phaseFront.edges()[static_cast<std::size_t>(firstFront)].oppositeEdge,
              secondFront);
    ASSERT_EQ(phaseFront.edges()[static_cast<std::size_t>(secondFront)].oppositeEdge,
              firstFront);

    ASSERT_EQ(edge.evidence.size(), 2U);
    std::set<std::pair<directional::authority::OccurrenceId,
                       directional::authority::OccurrenceId>>
        expectedEndpointPairs;
    const auto canonicalPair = [](auto first, auto second) {
      if (second < first) std::swap(first, second);
      return std::pair{first, second};
    };
    expectedEndpointPairs.insert(
        canonicalPair(firstDirected.first, secondDirected.second));
    expectedEndpointPairs.insert(
        canonicalPair(firstDirected.second, secondDirected.first));
    std::set<std::pair<directional::authority::OccurrenceId,
                       directional::authority::OccurrenceId>>
        certifiedEndpointPairs;
    bool relationIsolation = false;
    for (const auto &relationId : edge.evidence) {
      const auto relation = relationById.find(relationId);
      ASSERT_NE(relation, relationById.end());
      certifiedEndpointPairs.insert(canonicalPair(
          relation->second->firstOccurrence, relation->second->secondOccurrence));
      relationIsolation = relationIsolation || relationHasIsolation(*relation->second);
      if (edge.relationKind ==
          directional::pipeline::SurfaceQuotientEdgeRelationKind::Ordinary) {
        EXPECT_EQ(relation->second->id.kind,
                  directional::pipeline::SurfaceOccurrenceRelationKind::OrdinaryFront);
      } else if (edge.relationKind ==
                 directional::pipeline::SurfaceQuotientEdgeRelationKind::HardRail) {
        EXPECT_EQ(relation->second->id.kind,
                  directional::pipeline::SurfaceOccurrenceRelationKind::HardRail);
        EXPECT_EQ(relation->second->id.hardRail, edge.hardRail);
      } else {
        EXPECT_EQ(relation->second->id.kind,
                  directional::pipeline::SurfaceOccurrenceRelationKind::Periodic);
        EXPECT_EQ(relation->second->id.periodicRelation, edge.periodicRelation);
      }
    }
    EXPECT_EQ(certifiedEndpointPairs, expectedEndpointPairs);

    const bool isolationSeam =
        relationIsolation || sideHasIsolation(firstSide) || sideHasIsolation(secondSide);
    const bool requiresExactSharedArrangement =
        edge.relationKind ==
            directional::pipeline::SurfaceQuotientEdgeRelationKind::Ordinary &&
        !isolationSeam;
    if (requiresExactSharedArrangement) {
      EXPECT_EQ(firstChain.edges, secondChain.edges);
      EXPECT_EQ(nodeByOccurrence.at(firstDirected.first),
                nodeByOccurrence.at(secondDirected.second));
      EXPECT_EQ(nodeByOccurrence.at(firstDirected.second),
                nodeByOccurrence.at(secondDirected.first));
    }
  }

}

TEST(M6CP1, A6ClosedComplexBoundaryPreservesHardRailAndPeriodicLabels) {
  const auto &fixture = torus_fixture();
  const auto hardEdges = torus_row408_hard_edges(fixture.mesh);
  auto a5Construction = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 = std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
      &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction = directional::pipeline::SurfaceQuotientProducer::produce(
      *a5, hardEdges);
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Construction);
  ASSERT_NE(a6, nullptr);
  ASSERT_TRUE(a6->closed_complex_view().has_value());
  const auto &view = a6->closed_complex_view().value();

  std::map<directional::authority::CellId,
           const directional::pipeline::SurfaceOccurrenceCell *> cellById;
  for (const auto &cell : a5->cells()) cellById.emplace(cell.id, &cell);
  std::set<directional::authority::SourceEdgeTopologyKey> protectedCarriers;
  std::size_t periodicProtected = 0U;
  for (const auto &edge : view.edges) {
    if (edge.relationKind ==
        directional::pipeline::SurfaceQuotientEdgeRelationKind::HardRail) {
      EXPECT_TRUE(edge.hardRail.has_value());
      EXPECT_TRUE(edge.hardFeatureProtected);
      EXPECT_FALSE(edge.periodicRelation.has_value());
    } else if (edge.relationKind ==
               directional::pipeline::SurfaceQuotientEdgeRelationKind::Periodic) {
      EXPECT_TRUE(edge.periodicRelation.has_value());
      EXPECT_FALSE(edge.hardRail.has_value());
      if (edge.hardFeatureProtected) ++periodicProtected;
    } else {
      EXPECT_FALSE(edge.hardRail.has_value());
      EXPECT_FALSE(edge.periodicRelation.has_value());
    }
    if (!edge.hardFeatureProtected) continue;
    for (const auto &side : edge.id.incidentSides) {
      const auto &sourceCell = *cellById.at(side.cell);
      for (const auto &span :
           sourceCell.directedSideAuthority[static_cast<std::size_t>(side.side)].spans) {
        if (span.collinearEdge.has_value()) {
          protectedCarriers.insert(span.collinearEdge.value());
        } else if (const auto *support =
                       std::get_if<directional::authority::SourceEdgeSupport>(
                           &span.support)) {
          protectedCarriers.insert(support->edge);
        }
      }
    }
  }
  EXPECT_GT(periodicProtected, 0U)
      << "produced torus hard features are PeriodicCut carriers";
  EXPECT_EQ(protectedCarriers, hardEdges);
}

TEST(M6CP1, A6ClosedComplexBoundaryPreservesQuotientVertexLineage) {
  const auto &fixture = torus_fixture();
  auto a5Construction = directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
      fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 = std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
      &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction = directional::pipeline::SurfaceQuotientProducer::produce(
      *a5, torus_row408_hard_edges(fixture.mesh));
  const auto *a6 = std::get_if<directional::pipeline::SurfaceQuotientProduct>(
      &a6Construction);
  ASSERT_NE(a6, nullptr);
  ASSERT_TRUE(a6->closed_complex_view().has_value());
  const auto &view = a6->closed_complex_view().value();
  ASSERT_EQ(view.vertices.size(), a6->classes().size());
  for (std::size_t row = 0; row < view.vertices.size(); ++row) {
    EXPECT_EQ(view.vertices[row], a6->classes()[row].id);
    EXPECT_EQ(view.vertices[row].members, a6->classes()[row].members);
    EXPECT_FALSE(view.vertices[row].members.empty());
  }
}

TEST(M6CP1, A6BoundaryCandidateExtractionHasIndependentEligibilityOracle) {
  const auto &fixture = torus_fixture();
  const auto view = build_torus_closed_complex_view(
      fixture.mesh, fixture.network.phaseFront.product(),
      torus_row408_hard_edges(fixture.mesh));
  ASSERT_TRUE(view.has_value());

  std::map<directional::pipeline::SurfaceQuotientClassId,
           std::vector<std::size_t>> incidentEdges;
  std::map<directional::pipeline::SurfaceQuotientEdgeId, std::size_t> edgeIndexById;
  for (std::size_t edgeIndex = 0; edgeIndex < view->edges.size(); ++edgeIndex) {
    const auto &edge = view->edges[edgeIndex];
    incidentEdges[edge.first].push_back(edgeIndex);
    incidentEdges[edge.second].push_back(edgeIndex);
    ASSERT_TRUE(edgeIndexById.emplace(edge.id, edgeIndex).second);
  }

  std::vector<std::size_t> parent(view->edges.size());
  std::iota(parent.begin(), parent.end(), 0U);
  const auto findRoot = [&](std::size_t value) {
    std::size_t root = value;
    while (parent[root] != root) root = parent[root];
    while (parent[value] != value) {
      const std::size_t next = parent[value];
      parent[value] = root;
      value = next;
    }
    return root;
  };
  const auto unite = [&](const std::size_t first, const std::size_t second) {
    const std::size_t a = findRoot(first);
    const std::size_t b = findRoot(second);
    if (a != b) parent[b] = a;
  };
  for (const auto &[vertex, edges] : incidentEdges) {
    (void)vertex;
    if (edges.size() != 4U ||
        std::any_of(edges.begin(), edges.end(), [&](const std::size_t edgeIndex) {
          return view->edges[edgeIndex].id.incidentSides.size() != 2U;
        })) {
      continue;
    }
    for (const std::size_t first : edges) {
      std::vector<std::size_t> opposite;
      for (const std::size_t second : edges) {
        if (second == first) continue;
        bool sharesQuad = false;
        for (const auto &firstSide : view->edges[first].id.incidentSides) {
          for (const auto &secondSide : view->edges[second].id.incidentSides) {
            sharesQuad = sharesQuad || firstSide.cell == secondSide.cell;
          }
        }
        if (!sharesQuad) opposite.push_back(second);
      }
      ASSERT_EQ(opposite.size(), 1U)
          << "regular quotient vertex must have one edge-loop continuation";
      unite(first, opposite.front());
    }
  }

  std::map<std::size_t, directional::pipeline::SurfaceQuotientEdgeId> minimumByRoot;
  for (std::size_t edgeIndex = 0; edgeIndex < view->edges.size(); ++edgeIndex) {
    const std::size_t root = findRoot(edgeIndex);
    const auto found = minimumByRoot.find(root);
    if (found == minimumByRoot.end() || view->edges[edgeIndex].id < found->second) {
      minimumByRoot[root] = view->edges[edgeIndex].id;
    }
  }
  std::vector<std::pair<directional::pipeline::SurfaceQuotientEdgeId, std::size_t>>
      orderedRoots;
  for (const auto &[root, minimumEdge] : minimumByRoot) {
    orderedRoots.emplace_back(minimumEdge, root);
  }
  std::sort(orderedRoots.begin(), orderedRoots.end());
  std::map<std::size_t, std::uint32_t> ordinalByRoot;
  for (std::size_t ordinal = 0; ordinal < orderedRoots.size(); ++ordinal) {
    ordinalByRoot.emplace(orderedRoots[ordinal].second,
                          static_cast<std::uint32_t>(ordinal));
  }
  std::map<std::uint32_t,
           std::vector<directional::pipeline::SurfaceQuotientEdgeId>>
      independentlyGroupedEdges;
  for (std::size_t edgeIndex = 0; edgeIndex < view->edges.size(); ++edgeIndex) {
    const std::uint32_t expected = ordinalByRoot.at(findRoot(edgeIndex));
    EXPECT_EQ(view->edges[edgeIndex].stripOrdinal, expected);
    independentlyGroupedEdges[expected].push_back(view->edges[edgeIndex].id);
  }
  for (auto &[ordinal, edges] : independentlyGroupedEdges) {
    (void)ordinal;
    std::sort(edges.begin(), edges.end());
  }

  directional::geometry::SurfaceSimplificationCandidateExtractionOptions options;
  options.includeProtectedCandidatesForDiagnostics = false;
  const auto extracted =
      directional::pipeline::extract_surface_quotient_simplification_candidates(
          *view, options);
  const auto independentlyEligible = [&](const auto &candidate,
                                         const auto &subject) {
    const auto expectedGroup = independentlyGroupedEdges.find(candidate.stripOrdinal);
    if (expectedGroup == independentlyGroupedEdges.end() || candidate.edges.empty()) {
      return false;
    }
    auto candidateEdges = candidate.edges;
    std::sort(candidateEdges.begin(), candidateEdges.end());
    if (candidateEdges != expectedGroup->second) return false;

    std::map<directional::pipeline::SurfaceQuotientClassId, int> globalValence;
    std::set<directional::pipeline::SurfaceQuotientClassId> boundaryVertices;
    for (const auto &edge : subject.edges) {
      ++globalValence[edge.first];
      ++globalValence[edge.second];
      if (edge.id.incidentSides.size() == 1U) {
        boundaryVertices.insert(edge.first);
        boundaryVertices.insert(edge.second);
      }
    }

    std::map<directional::pipeline::SurfaceQuotientClassId, int> degree;
    std::set<directional::pipeline::SurfaceQuotientClassId> vertices;
    std::set<directional::authority::CellId> cells;
    std::set<directional::authority::PeriodicRelationId> periodicRelations;
    bool touchesHardFeature = false;
    bool touchesBoundary = false;
    for (const auto &edgeId : candidateEdges) {
      const auto edgeIndex = edgeIndexById.find(edgeId);
      if (edgeIndex == edgeIndexById.end()) return false;
      const auto &edge = subject.edges[edgeIndex->second];
      if (edge.stripOrdinal != candidate.stripOrdinal) return false;
      ++degree[edge.first];
      ++degree[edge.second];
      vertices.insert(edge.first);
      vertices.insert(edge.second);
      touchesHardFeature = touchesHardFeature || edge.hardFeatureProtected;
      touchesBoundary = touchesBoundary || edge.id.incidentSides.size() == 1U;
      if (edge.periodicRelation.has_value()) {
        periodicRelations.insert(edge.periodicRelation.value());
      }
      for (const auto &side : edge.id.incidentSides) cells.insert(side.cell);
    }
    bool touchesSingularity = false;
    for (const auto &vertex : vertices) {
      if (boundaryVertices.count(vertex) == 0U && globalValence[vertex] != 4) {
        touchesSingularity = true;
      }
    }
    if (candidate.touchesHardFeature != touchesHardFeature ||
        candidate.touchesBoundary != touchesBoundary ||
        candidate.touchesSingularity != touchesSingularity ||
        candidate.sideFeasible != !cells.empty() || touchesHardFeature ||
        touchesBoundary || touchesSingularity) {
      return false;
    }
    if (candidate.vertices !=
        std::vector<directional::pipeline::SurfaceQuotientClassId>(
            vertices.begin(), vertices.end()) ||
        candidate.cells != std::vector<directional::authority::CellId>(
                               cells.begin(), cells.end()) ||
        candidate.periodicRelations !=
            std::vector<directional::authority::PeriodicRelationId>(
                periodicRelations.begin(), periodicRelations.end())) {
      return false;
    }

    int degreeOne = 0;
    for (const auto &[vertex, value] : degree) {
      (void)vertex;
      if (value == 1) {
        ++degreeOne;
      } else if (value != 2) {
        return false;
      }
    }
    if (candidate.type ==
        directional::geometry::SurfaceSimplificationCandidateType::ClosedLoop) {
      return degreeOne == 0;
    }
    return candidate.type ==
               directional::geometry::SurfaceSimplificationCandidateType::OpenStrip &&
           degreeOne == 2;
  };

  ASSERT_FALSE(extracted.candidates.empty());
  for (const auto &candidate : extracted.candidates) {
    EXPECT_TRUE(independentlyEligible(candidate, *view));
  }
  const auto found = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [&](const auto &candidate) {
        return candidate.type ==
                   directional::geometry::SurfaceSimplificationCandidateType::ClosedLoop &&
               independentlyEligible(candidate, *view);
      });
  ASSERT_NE(found, extracted.candidates.end());
  const auto originalEdges = found->edges;
  ASSERT_FALSE(originalEdges.empty());

  auto tampered = *view;
  const auto tamperedEdge = std::find_if(
      tampered.edges.begin(), tampered.edges.end(),
      [&](const auto &edge) { return edge.id == originalEdges.front(); });
  ASSERT_NE(tamperedEdge, tampered.edges.end());
  tamperedEdge->hardFeatureProtected = true;
  const auto tamperedCandidates =
      directional::pipeline::extract_surface_quotient_simplification_candidates(
          tampered, options);
  const auto unchanged = std::find_if(
      tamperedCandidates.candidates.begin(), tamperedCandidates.candidates.end(),
      [&](const auto &candidate) { return candidate.edges == originalEdges; });
  EXPECT_EQ(unchanged, tamperedCandidates.candidates.end());
  EXPECT_FALSE(independentlyEligible(*found, tampered));
}

int first_edge_of_kind(const SurfacePhaseFrontResult &phaseFront,
                       const SurfaceFrontBoundaryKind kind) {
  for (int edge = 0; edge < static_cast<int>(phaseFront.product().edges().size()); ++edge) {
    if (phaseFront.product().edges()[static_cast<std::size_t>(edge)].boundaryKind == kind) {
      return edge;
    }
  }
  return -1;
}

int first_edge_of_kind(const PhaseFrontDraft &phaseFront,
                       const SurfaceFrontBoundaryKind kind) {
  for (int edge = 0; edge < static_cast<int>(phaseFront.edges.size()); ++edge) {
    if (phaseFront.edges[static_cast<std::size_t>(edge)].boundaryKind == kind) {
      return edge;
    }
  }
  return -1;
}

struct TransitionIndexDomainWitness {
  std::size_t cell = 0;
  std::size_t side = 0;
  std::size_t segment = 0;
  std::size_t route = 0;
  directional::authority::SourceEdgeTopologyKey topology;
  int sourceWideCompact = -1;
  int regionLocalCompact = -1;
  int fullEfRow = -1;
};

TransitionIndexDomainWitness transition_index_domain_witness() {
  const auto &fixture = transition_domain_fixture();
  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceWide = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, constant_xy_field(fixture.mesh.F.rows()));

  for (std::size_t cellIndex = 0;
       cellIndex < fixture.network.phaseFront.product().cells().size(); ++cellIndex) {
    const auto &cell = fixture.network.phaseFront.product().cells()[cellIndex];
    const auto region = std::find_if(
        fixture.network.phaseFront.product().sourceTopologyRegions().regions().begin(),
        fixture.network.phaseFront.product().sourceTopologyRegions().regions().end(),
        [&](const auto &candidate) {
          return candidate.id() == cell.sourceTopologyRegion;
        });
    if (region == fixture.network.phaseFront.product().sourceTopologyRegions().regions().end() ||
        region->faces().empty()) {
      continue;
    }
    const auto regionalRows =
        fixture.network.phaseFront.product().sourceTopologyRegions().rows_for_region(
            region->id());
    Eigen::MatrixXi regionalFaces(
        static_cast<Eigen::Index>(regionalRows.size()), 3);
    for (std::size_t row = 0; row < regionalRows.size(); ++row) {
      regionalFaces.row(static_cast<Eigen::Index>(row)) =
          fixture.mesh.F.row(static_cast<Eigen::Index>(
              regionalRows[row].index()));
    }
    const auto regionalIncidence = directional::geometry::
        surface_cell_tracing_detail::edge_faces(regionalFaces);
    const auto regionLocal = directional::geometry::
        surface_cell_tracing_detail::edge_matching_indices(regionalIncidence);

    for (std::size_t side = 0; side < cell.boundaryPaths.size(); ++side) {
      const auto &path = cell.boundaryPaths[side];
      for (std::size_t segmentIndex = 0; segmentIndex < path.size();
           ++segmentIndex) {
        const auto &segment = path[segmentIndex];
        const auto routeSteps = segment.entryRoute.oriented_steps();
        for (std::size_t route = 0; route < routeSteps.size(); ++route) {
          const auto &step = routeSteps[route];
          if (step.kind() != directional::authority::TransitionStepKind::Interior ||
              !step.interior().has_value()) {
            continue;
          }
          const auto globalIndex = sourceWide.find(step.topology());
          const auto localIndex = regionLocal.find(step.topology());
          const auto incident = sourceIncidence.find(step.topology());
          if (globalIndex == sourceWide.end() ||
              localIndex == regionLocal.end() ||
              incident == sourceIncidence.end() || incident->second[0] < 0 ||
              incident->second[1] < 0 ||
              step.interior()->index() !=
                  static_cast<std::size_t>(globalIndex->second)) {
            continue;
          }
          const auto topology = globalIndex->first;

          int transitionCount = 0;
          int fullEfRow = -1;
          for (const auto &candidate : crossField.edgeTransitions) {
            const bool sameTopology =
                test_source_edge_topology(
                    candidate.sourceVertex0, candidate.sourceVertex1) ==
                topology;
            const bool reciprocalFaces =
                (candidate.firstFace == incident->second[0] &&
                 candidate.secondFace == incident->second[1]) ||
                (candidate.firstFace == incident->second[1] &&
                 candidate.secondFace == incident->second[0]);
            if (!sameTopology || !reciprocalFaces) continue;
            ++transitionCount;
            fullEfRow = candidate.sourceEdge;
          }
          if (transitionCount != 1 || fullEfRow < 0 ||
              fullEfRow >= fixture.mesh.EV.rows() ||
              test_source_edge_topology(
                  fixture.mesh.EV(fullEfRow, 0),
                  fixture.mesh.EV(fullEfRow, 1)) != topology) {
            continue;
          }
          const bool reciprocalEfFaces =
              (fixture.mesh.EF(fullEfRow, 0) == incident->second[0] &&
               fixture.mesh.EF(fullEfRow, 1) == incident->second[1]) ||
              (fixture.mesh.EF(fullEfRow, 0) == incident->second[1] &&
               fixture.mesh.EF(fullEfRow, 1) == incident->second[0]);
          if (!reciprocalEfFaces || globalIndex->second < 0 ||
              localIndex->second < 0 ||
              globalIndex->second == localIndex->second ||
              fullEfRow == globalIndex->second ||
              fullEfRow == localIndex->second) {
            continue;
          }
          return {cellIndex, side, segmentIndex, route, step.topology(),
                  globalIndex->second, localIndex->second, fullEfRow};
        }
      }
    }
  }
  throw std::runtime_error(
      "Missing serialized route topology with distinct source-wide, "
      "region-local, and EF transition indices");
}

bool replace_transition_index(PhaseFrontDraft &phaseFront,
                               const TransitionIndexDomainWitness &witness,
                               const int replacement) {
  if (witness.cell >= phaseFront.cells.size()) return false;
  auto &cell = phaseFront.cells[witness.cell];
  if (witness.side >= cell.boundaryPaths.size()) return false;
  auto &path = cell.boundaryPaths[witness.side];
  if (witness.segment >= path.size()) return false;
  auto &segment = path[witness.segment];
  auto steps = segment.entryRoute.oriented_steps();
  if (witness.route >= steps.size()) return false;
  const auto &original = steps[witness.route];
  if (original.kind() != directional::authority::TransitionStepKind::Interior ||
      !original.interior().has_value() || original.topology() != witness.topology ||
      original.interior()->index() !=
          static_cast<std::size_t>(witness.sourceWideCompact)) {
    return false;
  }
  const auto replacementId =
      directional::authority::InteriorTransitionId::from_index(
          replacement, static_cast<std::size_t>(replacement + 1));
  if (!replacementId) return false;
  const auto replacementStep = directional::authority::TransitionStep::interior(
      original.topology(), replacementId.value(), original.transport(),
      original.orientation());
  if (!replacementStep) return false;
  steps[witness.route] = replacementStep.value();
  segment.entryRoute =
      directional::authority::CanonicalRoute::from_observed_steps(
          std::move(steps));
  const auto mutated = segment.entryRoute.oriented_steps();
  return witness.route < mutated.size() && mutated[witness.route].interior() &&
         mutated[witness.route].interior()->index() ==
             static_cast<std::size_t>(replacement) &&
         mutated[witness.route].topology() == witness.topology;
}

directional::pipeline::RemeshResult semantic_two_component_result() {
  directional::pipeline::RemeshProduct result;
  result.vertices.resize(8, 3);
  result.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 1.0, 0.0,
      0.0, 1.0, 0.0, 3.0, 0.0, 0.0, 4.0, 0.0, 0.0, 4.0, 1.0, 0.0,
      3.0, 1.0, 0.0;
  result.faces.resize(2, 4);
  result.faces << 0, 1, 2, 3, 4, 5, 6, 7;
  result.degrees = Eigen::VectorXi::Constant(2, 4);
  for (int vertex = 0; vertex < 8; ++vertex) {
    const int component = vertex / 4;
    directional::geometry::PureQuadVertexLineage lineage;
    lineage.outputVertex = vertex;
    lineage.sourcePoint.face = component;
    lineage.sourcePoint.component = component;
    lineage.sourcePoint.sheet = component;
    lineage.sourcePoint.barycentric = Eigen::Vector3d(1.0, 0.0, 0.0);
    lineage.sourcePoint.position = result.vertices.row(vertex).transpose();
    lineage.sourcePoint.squaredDistance = 0.0;
    lineage.sourceTopologyRegions = {test_topology_region_id(component)};
    lineage.sourceIsolationSheets = {test_isolation_sheet_id(component)};
    lineage.sourceCharts = {test_projection_chart(component, component)};
    lineage.sourceSupport = test_source_vertex_support(vertex % 4);
    result.outputVertexLineage.push_back(std::move(lineage));
  }
  for (int face = 0; face < 2; ++face) {
    directional::geometry::PureQuadFaceLineage lineage;
    lineage.outputQuad = face;
    lineage.sourcePatch = face;
    lineage.operationLocalQuad = face;
    result.outputQuadLineage.push_back(lineage);
  }
  return directional::pipeline::RemeshResult::produced(
      std::move(result), directional::pipeline::RemeshProductKind::Meshed,
      true);
}

directional::pipeline::RemeshResult permute_semantic_output_rows(
    const directional::pipeline::RemeshResult &source) {
  directional::pipeline::RemeshProduct permuted = source.product();
  const std::array<int, 8> newToOld{7, 6, 5, 4, 3, 2, 1, 0};
  std::array<int, 8> oldToNew{};
  for (int vertex = 0; vertex < 8; ++vertex) {
    oldToNew[static_cast<std::size_t>(
        newToOld[static_cast<std::size_t>(vertex)])] = vertex;
    permuted.vertices.row(vertex) =
        source.product().vertices.row(newToOld[static_cast<std::size_t>(vertex)]);
  }
  for (int face = 0; face < 2; ++face) {
    const int oldFace = 1 - face;
    for (int corner = 0; corner < 4; ++corner) {
      permuted.faces(face, corner) = oldToNew[static_cast<std::size_t>(
          source.product().faces(oldFace, corner))];
    }
  }
  permuted.outputVertexLineage.clear();
  for (int vertex = 0; vertex < 8; ++vertex) {
    auto lineage = source.product().outputVertexLineage[static_cast<std::size_t>(
        newToOld[static_cast<std::size_t>(vertex)])];
    lineage.outputVertex = vertex;
    permuted.outputVertexLineage.push_back(std::move(lineage));
  }
  permuted.outputQuadLineage.clear();
  for (int face = 0; face < 2; ++face) {
    auto lineage = source.product().outputQuadLineage[static_cast<std::size_t>(1 - face)];
    lineage.outputQuad = face;
    permuted.outputQuadLineage.push_back(std::move(lineage));
  }
  const auto *publication = source.produced_product();
  if (publication == nullptr) {
    throw std::invalid_argument("Permutation requires a produced remesh product.");
  }
  return directional::pipeline::RemeshResult::produced(
      std::move(permuted), publication->kind, publication->crossFieldAccepted,
      source.surfaceCellContext, source.diagnostics);
}

TEST(SurfaceCellTransitionQuotient,
     SourceWideCompactTransitionIndexIsIndependentOfRegionPartition) {
  const auto &fixture = transition_domain_fixture();
  const auto witness = transition_index_domain_witness();
  ASSERT_GE(witness.sourceWideCompact, 0);
  ASSERT_GE(witness.regionLocalCompact, 0);
  ASSERT_GE(witness.fullEfRow, 0);
  EXPECT_NE(witness.sourceWideCompact, witness.regionLocalCompact);
  EXPECT_NE(witness.sourceWideCompact, witness.fullEfRow);
  EXPECT_NE(witness.regionLocalCompact, witness.fullEfRow);

  ASSERT_LT(witness.cell, fixture.network.phaseFront.product().cells().size());
  const auto &witnessCell = fixture.network.phaseFront.product().cells()[witness.cell];
  ASSERT_LT(witness.side, witnessCell.boundaryPaths.size());
  const auto &witnessPath = witnessCell.boundaryPaths[witness.side];
  ASSERT_LT(witness.segment, witnessPath.size());
  const auto &witnessSegment = witnessPath[witness.segment];
  const auto witnessSteps = witnessSegment.entryRoute.oriented_steps();
  ASSERT_LT(witness.route, witnessSteps.size());
  ASSERT_TRUE(witnessSteps[witness.route].interior().has_value());
  EXPECT_EQ(static_cast<std::size_t>(witness.sourceWideCompact),
            witnessSteps[witness.route].interior()->index());
  EXPECT_EQ(witness.topology, witnessSteps[witness.route].topology());

  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceWide = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  for (const auto &cell : fixture.network.phaseFront.product().cells()) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        for (const auto &step : segment.entryRoute.oriented_steps()) {
          ASSERT_EQ(directional::authority::TransitionStepKind::Interior,
                    step.kind());
          ASSERT_TRUE(step.interior().has_value());
          const auto expected = sourceWide.find(step.topology());
          ASSERT_NE(expected, sourceWide.end());
          EXPECT_EQ(static_cast<std::size_t>(expected->second),
                    step.interior()->index());
        }
      }
    }
  }

  bool observedGenuineBoundary = false;
  for (const auto &edge : fixture.network.phaseFront.product().edges()) {
    if (edge.boundaryKind != SurfaceFrontBoundaryKind::GenuineSourceBoundary) {
      continue;
    }
    observedGenuineBoundary = true;
    EXPECT_TRUE(route_is_all_boundary(edge.route));
  }
  EXPECT_TRUE(observedGenuineBoundary);

  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
}

TEST(SurfaceCellTransitionQuotient,
     FullEfTransitionRowCannotReplaceSourceWideCompactIndex) {
  const auto &fixture = transition_domain_fixture();
  const auto witness = transition_index_domain_witness();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  ASSERT_TRUE(replace_transition_index(tampered, witness, witness.fullEfRow));
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativeTransitionSourceEdge", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex) {
  const auto &fixture = transition_domain_fixture();
  const auto witness = transition_index_domain_witness();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  ASSERT_TRUE(
      replace_transition_index(tampered, witness, witness.regionLocalCompact));
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativeTransitionSourceEdge", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     TopologyOnlyGenuineBoundaryMaterializes) {
  const auto &fixture = square_fixture();
  std::size_t genuineBoundaries = 0U;
  for (const auto &edge : fixture.network.phaseFront.product().edges()) {
    if (edge.boundaryKind != SurfaceFrontBoundaryKind::GenuineSourceBoundary) {
      continue;
    }
    ++genuineBoundaries;
    EXPECT_TRUE(edge.exterior);
    EXPECT_LT(edge.oppositeEdge, 0);
    EXPECT_TRUE(route_is_all_boundary(edge.route));
  }
  EXPECT_GT(genuineBoundaries, 0U);
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(1, result.connectedComponents);
  EXPECT_EQ(1, result.boundaryLoopCount);
  EXPECT_EQ(1, result.eulerCharacteristic);
}

TEST(SurfaceCellTransitionQuotient,
     GenuineBoundaryWithInventedInteriorIndexIsRejected) {
  const auto &fixture = square_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int boundary = first_edge_of_kind(
      tampered, SurfaceFrontBoundaryKind::GenuineSourceBoundary);
  ASSERT_GE(boundary, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(boundary)];
  ASSERT_TRUE(route_is_all_boundary(edge.route));
  const auto transition =
      directional::authority::InteriorTransitionId::from_index(0, 1);
  ASSERT_TRUE(transition);
  const auto step = directional::authority::TransitionStep::interior(
      edge.route.steps().front().topology(), transition.value(),
      directional::authority::GridAutomorphism::identity(),
      directional::authority::Orientation::Forward);
  ASSERT_TRUE(step);
  edge.route = directional::authority::CanonicalRoute::from_observed_steps(
      {step.value()});
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidSourceBoundaryAuthority", result.failure);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     ReciprocalIsolationSeamCertificateMaterializes) {
  const auto &fixture = split_isolation_fixture();
  ASSERT_EQ(1U,
            fixture.network.phaseFront.product().isolationSeamTransportCertificates()
                .size());
  const auto &certificate =
      fixture.network.phaseFront.product().isolationSeamTransportCertificates().front();
  EXPECT_LT(certificate.transition().index(), fixture.mesh.EF.rows());
  EXPECT_NE(certificate.firstSheet(), certificate.secondSheet());
  EXPECT_EQ(certificate.forward().inverse(), certificate.reverse());
  EXPECT_NE(0U, directional::geometry::surface_cell_tracing_detail::
                    isolation_seam_transport_certificate_hash(certificate));
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(1U, result.consumedInternalIsolationSeams);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     MissingIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  ASSERT_FALSE(tampered.certificates.empty());
  tampered.certificates.clear();
  const auto construction = construct_phase_front_product(std::move(tampered));
  const auto *error =
      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
          &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontProductErrorCode::
                IsolationCertificateBijectionMismatch,
            error->code);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     DuplicateIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  ASSERT_FALSE(tampered.certificates.empty());
  tampered.certificates.push_back(tampered.certificates.front());
  const auto construction = construct_phase_front_product(std::move(tampered));
  const auto *error =
      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
          &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontProductErrorCode::
                DuplicateIsolationCertificate,
            error->code);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     WrongOwnerIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  const auto &product = fixture.network.phaseFront.product();
  ASSERT_FALSE(product.isolationSeamTransportCertificates().empty());
  const auto &certificate = product.isolationSeamTransportCertificates().front();
  const auto wrongRegion = directional::authority::TopologyRegionId::from_index(
      static_cast<std::int64_t>(product.sourceTopologyRegions().regions().size()),
      product.sourceTopologyRegions().regions().size() + 1U);
  ASSERT_TRUE(wrongRegion);
  const auto construction =
      directional::geometry::SurfaceIsolationSeamTransportCertificate::make(
          product.sourceTopologyRegions(), wrongRegion.value(),
          certificate.seam(), certificate.transition(), certificate.firstFace(),
          certificate.secondFace(), certificate.firstSheet(),
          certificate.secondSheet(), certificate.forward(),
          certificate.reverse());
  const auto *error = std::get_if<
      directional::geometry::SurfaceIsolationSeamTransportCertificateError>(
      &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::
                SurfaceIsolationSeamTransportCertificateErrorCode::UnknownRegion,
            error->code);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     WrongSheetIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  const auto &product = fixture.network.phaseFront.product();
  ASSERT_FALSE(product.isolationSeamTransportCertificates().empty());
  const auto &certificate = product.isolationSeamTransportCertificates().front();
  const auto wrongSheet = directional::authority::IsolationSheetId::from_index(
      99, 100);
  ASSERT_TRUE(wrongSheet);
  const auto construction =
      directional::geometry::SurfaceIsolationSeamTransportCertificate::make(
          product.sourceTopologyRegions(), certificate.region(),
          certificate.seam(), certificate.transition(), certificate.firstFace(),
          certificate.secondFace(), wrongSheet.value(),
          certificate.secondSheet(), certificate.forward(),
          certificate.reverse());
  const auto *error = std::get_if<
      directional::geometry::SurfaceIsolationSeamTransportCertificateError>(
      &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::
                SurfaceIsolationSeamTransportCertificateErrorCode::
                    SheetOwnershipMismatch,
            error->code);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     NonreciprocalIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  const auto &product = fixture.network.phaseFront.product();
  ASSERT_FALSE(product.isolationSeamTransportCertificates().empty());
  const auto &certificate = product.isolationSeamTransportCertificates().front();
  const auto wrongReverse = directional::authority::QuarterTurn::from_integer(
      static_cast<int>(certificate.reverse().value()) + 1);
  const auto construction =
      directional::geometry::SurfaceIsolationSeamTransportCertificate::make(
          product.sourceTopologyRegions(), certificate.region(),
          certificate.seam(), certificate.transition(), certificate.firstFace(),
          certificate.secondFace(), certificate.firstSheet(),
          certificate.secondSheet(), certificate.forward(), wrongReverse);
  const auto *error = std::get_if<
      directional::geometry::SurfaceIsolationSeamTransportCertificateError>(
      &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::
                SurfaceIsolationSeamTransportCertificateErrorCode::
                    NonReciprocalTransport,
            error->code);
}

TEST(SurfaceCellTransitionQuotient,
     MultiIsolationMaterializationRetainsAllLocalSheets) {
  const auto &fixture = split_isolation_fixture();
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  bool foundMultiIsolationLineage = false;
  for (const auto &lineage : result.mesh.vertexLineage) {
    if (lineage.sourceIsolationSheets.size() <= 1U) continue;
    foundMultiIsolationLineage = true;
    EXPECT_TRUE(std::is_sorted(lineage.sourceIsolationSheets.begin(),
                               lineage.sourceIsolationSheets.end()));
    EXPECT_TRUE(std::is_sorted(lineage.sourceCharts.begin(),
                               lineage.sourceCharts.end()));
    EXPECT_FALSE(lineage.equivalences.empty());
  }
  EXPECT_TRUE(foundMultiIsolationLineage);
}

TEST(SurfaceCellTransitionQuotient,
     EqualLatticeAndPositionWithoutReciprocalConnectivityRemainDistinct) {
  const auto &fixture = overlap_fixture();
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(2, result.connectedComponents);
  bool foundCoincidentDistinctVertices = false;
  for (int first = 0; first < result.mesh.vertexPositions.rows(); ++first) {
    for (int second = first + 1; second < result.mesh.vertexPositions.rows();
         ++second) {
      if ((result.mesh.vertexPositions.row(first) -
           result.mesh.vertexPositions.row(second))
              .norm() > 1.0e-12) {
        continue;
      }
      const auto &firstLineage =
          result.mesh.vertexLineage[static_cast<std::size_t>(first)];
      const auto &secondLineage =
          result.mesh.vertexLineage[static_cast<std::size_t>(second)];
      if (firstLineage.sourceTopologyRegions !=
          secondLineage.sourceTopologyRegions) {
        foundCoincidentDistinctVertices = true;
      }
    }
  }
  EXPECT_TRUE(foundCoincidentDistinctVertices);
}

TEST(SurfaceCellTransitionQuotient,
     OrdinaryReciprocalEndpointsMaterializeWithOrientedUnion) {
  const auto &fixture = square_fixture();
  const int ordinary = first_edge_of_kind(
      fixture.network.phaseFront, SurfaceFrontBoundaryKind::OrdinaryInterior);
  ASSERT_GE(ordinary, 0);
  const auto &edge =
      fixture.network.phaseFront.product().edges()[static_cast<std::size_t>(ordinary)];
  ASSERT_GE(edge.oppositeEdge, 0);
  const auto &opposite = fixture.network.phaseFront.product().edges()[
      static_cast<std::size_t>(edge.oppositeEdge)];
  const auto position = [&](const auto &point) {
    Eigen::Vector3d value = Eigen::Vector3d::Zero();
    for (int corner = 0; corner < 3; ++corner) {
      value += point.barycentric[corner] *
               fixture.mesh.V
                   .row(fixture.mesh.F(point.face, corner))
                   .transpose();
    }
    return value;
  };
  EXPECT_NEAR((position(edge.from) - position(opposite.to)).norm(), 0.0,
              1.0e-12);
  EXPECT_NEAR((position(edge.to) - position(opposite.from)).norm(), 0.0,
              1.0e-12);
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
}

TEST(SurfaceCellTransitionQuotient,
     OrdinaryReciprocalWrongEndpointStateIsRejected) {
  const auto &fixture = square_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int ordinary =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::OrdinaryInterior);
  ASSERT_GE(ordinary, 0);
  tampered.edges[static_cast<std::size_t>(ordinary)]
      .fromLattice.latticeCoordinate.x += 1;
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativePhaseFrontSideAuthority", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     FullPeriodicRotationAndTranslationMaterialize) {
  const auto &fixture = direct_materializer_base_fixture();
  PhaseFrontDraft direct = direct_full_periodic_materializer_draft();
  const auto relation = std::find_if(
      direct.periodicHolonomies.begin(),
      direct.periodicHolonomies.end(),
      [](const auto &candidate) {
        return candidate.action().rotation != directional::authority::QuarterTurn{} &&
               (candidate.action().shift.x != 0 || candidate.action().shift.y != 0);
      });
  ASSERT_NE(direct.periodicHolonomies.end(), relation)
      << "direct typed authority must exercise a non-identity Z4 action";
  const auto result = materialize(fixture, direct);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(direct.periodicHolonomies.size(),
            result.consumedPeriodicHolonomies);
}

TEST(M5CP1, SelectedRelationPathCertificateSurvivesRelationContainerPermutation) {
  const auto &fixture = direct_materializer_base_fixture();
  PhaseFrontDraft baselineDraft = direct_full_periodic_materializer_draft();
  ASSERT_FALSE(baselineDraft.periodicHolonomies.empty());
  const auto &owner = baselineDraft.periodicHolonomies.front();
  auto unusedConstruction = directional::geometry::SurfacePeriodicHolonomy::make(
      owner.sourceTopologyRegion(), owner.action(), owner.cutRoute(),
      owner.route());
  auto *unused =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(
          &unusedConstruction);
  ASSERT_NE(nullptr, unused);
  ASSERT_TRUE(std::none_of(
      baselineDraft.periodicHolonomies.begin(),
      baselineDraft.periodicHolonomies.end(),
      [&](const auto &relation) { return relation.id() == unused->id(); }));
  baselineDraft.periodicHolonomies.push_back(*unused);

  PhaseFrontDraft reorderedDraft = baselineDraft;
  ASSERT_GE(reorderedDraft.periodicHolonomies.size(), 2U);
  const auto firstStoredRelationId =
      reorderedDraft.periodicHolonomies.front().id();
  const auto lastStoredRelationId =
      reorderedDraft.periodicHolonomies.back().id();
  ASSERT_NE(firstStoredRelationId, lastStoredRelationId);
  std::reverse(reorderedDraft.periodicHolonomies.begin(),
               reorderedDraft.periodicHolonomies.end());
  EXPECT_NE(firstStoredRelationId,
            reorderedDraft.periodicHolonomies.front().id());

  const auto baseline = materialize(fixture, std::move(baselineDraft));
  const auto reordered = materialize(fixture, std::move(reorderedDraft));
  ASSERT_TRUE(baseline.success) << baseline.failure;
  ASSERT_TRUE(reordered.success) << reordered.failure;
  const auto baselineCertificates =
      selected_relation_certificate_signature(baseline.mesh);
  const auto reorderedCertificates =
      selected_relation_certificate_signature(reordered.mesh);
  ASSERT_FALSE(baselineCertificates.empty());
  EXPECT_EQ(baselineCertificates, reorderedCertificates);
  EXPECT_EQ(directional::pipeline::hash_completion(baseline.mesh),
            directional::pipeline::hash_completion(reordered.mesh));
  EXPECT_EQ(baseline.consumedPeriodicHolonomies,
            reordered.consumedPeriodicHolonomies);
}

TEST(M5CP1, UnusedValidPeriodicRelationDoesNotChangeSelectedCertificate) {
  const auto &fixture = direct_materializer_base_fixture();
  PhaseFrontDraft baselineDraft = direct_full_periodic_materializer_draft();
  PhaseFrontDraft extendedDraft = baselineDraft;
  ASSERT_FALSE(extendedDraft.periodicHolonomies.empty());
  const auto &owner = extendedDraft.periodicHolonomies.front();
  auto unusedConstruction = directional::geometry::SurfacePeriodicHolonomy::make(
      owner.sourceTopologyRegion(), owner.action(), owner.cutRoute(),
      owner.route());
  auto *unused =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(
          &unusedConstruction);
  ASSERT_NE(nullptr, unused);
  ASSERT_TRUE(std::none_of(
      extendedDraft.periodicHolonomies.begin(),
      extendedDraft.periodicHolonomies.end(),
      [&](const auto &relation) { return relation.id() == unused->id(); }));
  extendedDraft.periodicHolonomies.push_back(*unused);
  std::reverse(extendedDraft.periodicHolonomies.begin(),
               extendedDraft.periodicHolonomies.end());

  const auto baseline = materialize(fixture, std::move(baselineDraft));
  const auto extended = materialize(fixture, std::move(extendedDraft));
  ASSERT_TRUE(baseline.success) << baseline.failure;
  ASSERT_TRUE(extended.success) << extended.failure;
  const auto baselineCertificates =
      selected_relation_certificate_signature(baseline.mesh);
  ASSERT_FALSE(baselineCertificates.empty());
  EXPECT_EQ(baselineCertificates,
            selected_relation_certificate_signature(extended.mesh));
  EXPECT_EQ(directional::pipeline::hash_completion(baseline.mesh),
            directional::pipeline::hash_completion(extended.mesh));
  EXPECT_EQ(baseline.consumedPeriodicHolonomies,
            extended.consumedPeriodicHolonomies);
}

TEST(M5CP1, AlteredSelectedRelationTransformFailsCertificateValidation) {
  const auto &fixture = direct_materializer_base_fixture();
  const auto materialized =
      materialize(fixture, direct_full_periodic_materializer_draft());
  ASSERT_TRUE(materialized.success) << materialized.failure;

  auto tampered = materialized.mesh;
  auto lineage = std::find_if(
      tampered.vertexLineage.begin(), tampered.vertexLineage.end(),
      [](const auto &candidate) {
        return !candidate.selectedRelationPaths.empty() &&
               !candidate.selectedRelationPaths.front().orderedSteps.empty();
      });
  ASSERT_NE(tampered.vertexLineage.end(), lineage);
  auto &step = lineage->selectedRelationPaths.front().orderedSteps.front();
  step.appliedTransport.shift.x += 1;

  const auto noHardFeatures = directional::geometry::empty_hard_feature_edges();
  std::string failure;
  EXPECT_FALSE(directional::geometry::pure_quad_detail::
                   validate_materialized_completion_domain_ownership(
                       tampered, fixture.mesh.F,
                       &fixture.network.phaseFront.product().sourceTopologyRegions(),
                       &noHardFeatures, failure));
  EXPECT_EQ("CompletionOwnershipSelectedRelationValueMismatch", failure);
}

TEST(SurfaceCellTransitionQuotient,
     TamperedFullPeriodicTransformIsRejected) {
  PhaseFrontDraft tampered = direct_full_periodic_materializer_draft();
  const auto relation = std::find_if(
      tampered.periodicHolonomies.begin(), tampered.periodicHolonomies.end(),
      [](const auto &candidate) {
        return action_has_nonzero_turn(candidate.action()) && (candidate.action().shift.x != 0 || candidate.action().shift.y != 0);
      });
  ASSERT_NE(tampered.periodicHolonomies.end(), relation);
  auto action = relation->action(); const auto originalAction = action; ASSERT_TRUE(action_has_nonzero_turn(action));
  action.rotation = directional::authority::QuarterTurn::from_integer(
      static_cast<int>(action.rotation.value()) + 1);
  ASSERT_NE(originalAction, action);
  const auto originalId = relation->id();
  auto rebuilt = directional::geometry::SurfacePeriodicHolonomy::make(
      relation->sourceTopologyRegion(), action, relation->route(),
      relation->cutRoute());
  auto *value =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&rebuilt);
  ASSERT_NE(nullptr, value);
  EXPECT_EQ(originalId, value->id());
  *relation = std::move(*value);
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          NonReciprocalPeriodicRelation);
}

TEST(SurfaceCellTransitionQuotient,
     PeriodicRelationOwnersSurviveContainerReorderingBeforeMaterialization) {
  const auto original = direct_periodic_owner_product();
  ASSERT_EQ(2U, original.periodicHolonomies().size());
  ASSERT_EQ(2U, original.edges().size());

  std::map<directional::authority::PeriodicRelationId,
           directional::geometry::SurfacePeriodicHolonomy> ownerSnapshots;
  for (const auto &edge : original.edges()) {
    ASSERT_TRUE(edge.periodicRelation.has_value());
    const auto owner = std::find_if(
        original.periodicHolonomies().begin(), original.periodicHolonomies().end(),
        [&](const auto &relation) { return relation.id() == *edge.periodicRelation; });
    ASSERT_NE(original.periodicHolonomies().end(), owner);
    ownerSnapshots.emplace(*edge.periodicRelation, *owner);
  }
  ASSERT_EQ(2U, ownerSnapshots.size());
  EXPECT_NE(ownerSnapshots.begin()->second.route(),
            std::next(ownerSnapshots.begin())->second.route())
      << "relation owners must be semantically discriminating before reorder";

  PhaseFrontDraft reorderedDraft = phase_front_draft(original);
  std::reverse(reorderedDraft.periodicHolonomies.begin(),
               reorderedDraft.periodicHolonomies.end());
  auto construction = construct_phase_front_product(std::move(reorderedDraft));
  auto *reordered =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&construction);
  ASSERT_NE(nullptr, reordered);

  for (const auto &edge : reordered->edges()) {
    ASSERT_TRUE(edge.periodicRelation.has_value());
    const auto before = ownerSnapshots.find(*edge.periodicRelation);
    ASSERT_NE(ownerSnapshots.end(), before);
    const auto after = std::find_if(
        reordered->periodicHolonomies().begin(), reordered->periodicHolonomies().end(),
        [&](const auto &relation) { return relation.id() == *edge.periodicRelation; });
    ASSERT_NE(reordered->periodicHolonomies().end(), after);
    EXPECT_EQ(before->second.sourceTopologyRegion(), after->sourceTopologyRegion());
    EXPECT_EQ(before->second.action(), after->action());
    EXPECT_EQ(before->second.route(), after->route());
    EXPECT_EQ(before->second.cutRoute(), after->cutRoute());
  }
}

TEST(M4CP4, ProducedTorusPeriodicRelationOwnersSurviveContainerReordering) {
  const auto &fixture = torus_fixture();
  ASSERT_EQ(SurfaceCellProducerDisposition::Produced,
            fixture.network.phaseFront.disposition());
  const auto &original = fixture.network.phaseFront.product();
  ASSERT_GT(original.periodicHolonomies().size(), 1U);

  std::map<directional::authority::PeriodicRelationId,
           directional::geometry::SurfacePeriodicHolonomy> owners;
  for (const auto &relation : original.periodicHolonomies()) {
    ASSERT_TRUE(owners.emplace(relation.id(), relation).second);
  }
  std::vector<std::size_t> periodicEdges;
  for (std::size_t edgeIndex = 0U; edgeIndex < original.edges().size(); ++edgeIndex) {
    const auto &edge = original.edges()[edgeIndex];
    if (!edge.periodicRelation.has_value()) continue;
    ASSERT_NE(owners.end(), owners.find(*edge.periodicRelation));
    periodicEdges.push_back(edgeIndex);
  }
  ASSERT_GE(periodicEdges.size(), 2U);

  std::size_t second = 1U;
  while (second < periodicEdges.size() &&
         original.edges()[periodicEdges.front()].periodicRelation ==
             original.edges()[periodicEdges[second]].periodicRelation) {
    ++second;
  }
  ASSERT_LT(second, periodicEdges.size());
  const auto firstOwnerId =
      *original.edges()[periodicEdges.front()].periodicRelation;
  const auto secondOwnerId =
      *original.edges()[periodicEdges[second]].periodicRelation;
  ASSERT_NE(firstOwnerId, secondOwnerId);
  const auto &firstOwner = owners.at(firstOwnerId);
  const auto &secondOwner = owners.at(secondOwnerId);
  EXPECT_TRUE(firstOwner.sourceTopologyRegion() != secondOwner.sourceTopologyRegion() ||
              firstOwner.action() != secondOwner.action() ||
              firstOwner.route() != secondOwner.route() ||
              firstOwner.cutRoute() != secondOwner.cutRoute());

  PhaseFrontDraft reorderedDraft = phase_front_draft(original);
  std::reverse(reorderedDraft.periodicHolonomies.begin(),
               reorderedDraft.periodicHolonomies.end());
  auto construction = construct_phase_front_product(std::move(reorderedDraft));
  auto *reordered =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&construction);
  ASSERT_NE(nullptr, reordered);
  for (const auto &edge : reordered->edges()) {
    if (!edge.periodicRelation.has_value()) continue;
    const auto before = owners.find(*edge.periodicRelation);
    ASSERT_NE(owners.end(), before);
    const auto after = std::find_if(
        reordered->periodicHolonomies().begin(),
        reordered->periodicHolonomies().end(), [&](const auto &relation) {
          return relation.id() == *edge.periodicRelation;
        });
    ASSERT_NE(reordered->periodicHolonomies().end(), after);
    EXPECT_EQ(before->second.sourceTopologyRegion(), after->sourceTopologyRegion());
    EXPECT_EQ(before->second.action(), after->action());
    EXPECT_EQ(before->second.route(), after->route());
    EXPECT_EQ(before->second.cutRoute(), after->cutRoute());
  }

  PhaseFrontDraft tampered = phase_front_draft(original);
  std::swap(tampered.edges[periodicEdges.front()].periodicRelation,
            tampered.edges[periodicEdges[second]].periodicRelation);
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          NonReciprocalPeriodicRelation);
}

TEST(M4CP4, ProducedTorusMissingPeriodicRelationOwnerIsRejected) {
  const auto &fixture = torus_fixture();
  ASSERT_EQ(SurfaceCellProducerDisposition::Produced,
            fixture.network.phaseFront.disposition());
  const auto &original = fixture.network.phaseFront.product();
  std::set<directional::authority::PeriodicRelationId> relationIds;
  for (const auto &relation : original.periodicHolonomies()) {
    ASSERT_TRUE(relationIds.insert(relation.id()).second);
  }
  ASSERT_GE(relationIds.size(), 2U);
  std::size_t periodicEdgeCount = 0U;
  for (const auto &edge : original.edges()) {
    if (!edge.periodicRelation.has_value()) continue;
    ++periodicEdgeCount;
    ASSERT_NE(relationIds.end(), relationIds.find(*edge.periodicRelation));
  }
  ASSERT_GE(periodicEdgeCount, 2U);

  PhaseFrontDraft tampered = phase_front_draft(original);
  const int periodic = first_edge_of_kind(
      tampered, SurfaceFrontBoundaryKind::PeriodicCut);
  ASSERT_GE(periodic, 0);
  auto &periodicEdge = tampered.edges[static_cast<std::size_t>(periodic)];
  ASSERT_TRUE(periodicEdge.periodicRelation.has_value());
  const auto ownerId = *periodicEdge.periodicRelation;
  const auto owner = std::find_if(
      tampered.periodicHolonomies.begin(), tampered.periodicHolonomies.end(),
      [&](const auto &relation) { return relation.id() == ownerId; });
  ASSERT_NE(tampered.periodicHolonomies.end(), owner);
  EXPECT_EQ(ownerId, owner->id());
  EXPECT_FALSE(owner->route().empty());
  EXPECT_FALSE(owner->cutRoute().empty());

  periodicEdge.periodicRelation = std::nullopt;
  const auto construction = construct_phase_front_product(std::move(tampered));
  const auto *error =
      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
          &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontProductErrorCode::
                MissingPeriodicRelationOwner,
            error->code);
}

TEST(M5CP3, ProducedTorusPublishesTwoCanonicalPeriodicRelationsAndOwnedEdges) {
  const auto &fixture = torus_fixture();
  ASSERT_EQ(SurfaceCellProducerDisposition::Produced,
            fixture.network.phaseFront.disposition());
  const auto &product = fixture.network.phaseFront.product();
  ASSERT_EQ(1U, product.sourceTopologyRegions().regions().size());

  std::map<directional::authority::PeriodicRelationId,
           const directional::geometry::SurfacePeriodicHolonomy *> owners;
  std::set<std::pair<
      std::vector<directional::authority::PeriodicCarrierStepIdentity>,
      std::vector<directional::authority::PeriodicCarrierStepIdentity>>>
      independentCarriers;
  for (const auto &relation : product.periodicHolonomies()) {
    const auto expected = independent_periodic_relation_id(
        relation.sourceTopologyRegion(), relation.route(), relation.cutRoute());
    ASSERT_TRUE(expected.has_value());
    EXPECT_EQ(relation.id(), *expected);
    const auto carriers = independent_periodic_carrier_identity(
        relation.route(), relation.cutRoute());
    EXPECT_EQ(carriers.first, relation.id().generator_carrier());
    EXPECT_EQ(carriers.second, relation.id().cut_carrier());
    ASSERT_TRUE(independentCarriers.insert(carriers).second);
    ASSERT_TRUE(owners.emplace(relation.id(), &relation).second);
  }
  ASSERT_GE(owners.size(), 2U);

  std::size_t ownedPeriodicEdges = 0U;
  std::size_t promotedIntervalEdges = 0U;
  for (std::size_t edgeIndex = 0U; edgeIndex < product.edges().size();
       ++edgeIndex) {
    const auto &edge = product.edges()[edgeIndex];
    if (edge.boundaryKind != SurfaceFrontBoundaryKind::PeriodicCut) continue;
    ++ownedPeriodicEdges;
    ASSERT_TRUE(edge.periodicRelation.has_value());
    const auto owner = owners.find(*edge.periodicRelation);
    ASSERT_NE(owners.end(), owner);
    EXPECT_EQ(edge.sourceTopologyRegion,
              owner->second->sourceTopologyRegion());
    if (!edge.sharedBoundaryInterval.has_value()) continue;
    ++promotedIntervalEdges;
    ASSERT_GE(edge.oppositeEdge, 0);
    ASSERT_LT(static_cast<std::size_t>(edge.oppositeEdge),
              product.edges().size());
    const auto &opposite =
        product.edges()[static_cast<std::size_t>(edge.oppositeEdge)];
    ASSERT_TRUE(opposite.sharedBoundaryInterval.has_value());
    EXPECT_EQ(edge.periodicRelation, opposite.periodicRelation);
    EXPECT_EQ(edge.route, opposite.route.reversed());
    EXPECT_EQ(edge.sharedBoundaryInterval->span,
              opposite.sharedBoundaryInterval->span);
    EXPECT_EQ(edge.sharedBoundaryInterval->firstOrdinal,
              opposite.sharedBoundaryInterval->secondOrdinal);
    EXPECT_EQ(edge.sharedBoundaryInterval->secondOrdinal,
              opposite.sharedBoundaryInterval->firstOrdinal);
    EXPECT_NE(edge.sharedBoundaryInterval->orientation,
              opposite.sharedBoundaryInterval->orientation);
    ASSERT_TRUE(edge.sharedBoundaryInterval->boundaryOccurrence.has_value());
    ASSERT_TRUE(opposite.sharedBoundaryInterval->boundaryOccurrence.has_value());
    EXPECT_NE(edge.sharedBoundaryInterval->boundaryOccurrence,
              opposite.sharedBoundaryInterval->boundaryOccurrence);
  }
  EXPECT_GE(ownedPeriodicEdges, 2U);
  EXPECT_GE(promotedIntervalEdges, 2U);
}

TEST(M5CP4, ProducedTorusPeriodicRelationOwnsMultiIsolationRegion) {
  const auto &fixture = torus_fixture();
  ASSERT_EQ(SurfaceCellProducerDisposition::Produced,
            fixture.network.phaseFront.disposition())
      << "fact 1: committed torus phase front is pipeline-produced";
  ASSERT_TRUE(fixture.network.phaseFront.is_produced())
      << "fact 1: committed torus phase front is pipeline-produced";

  const auto &product = fixture.network.phaseFront.product();
  const auto &sourceAuthority = product.sourceTopologyRegions();
  const directional::geometry::SurfaceTopologyRegion *witnessRegion = nullptr;
  std::set<directional::authority::IsolationSheetId> witnessSheets;
  for (const auto &candidate : sourceAuthority.regions()) {
    std::set<directional::authority::IsolationSheetId> candidateSheets;
    const auto rows = sourceAuthority.rows_for_region(candidate.id());
    if (rows.size() != candidate.faces().size()) continue;
    for (const auto row : rows) {
      candidateSheets.insert(sourceAuthority.sheet_for_row(row));
    }
    if (candidateSheets.size() < 2U) continue;
    witnessRegion = &candidate;
    witnessSheets = std::move(candidateSheets);
    break;
  }
  ASSERT_NE(nullptr, witnessRegion)
      << "fact 2: one authoritative region spans >=2 isolation sheets";
  ASSERT_GE(witnessSheets.size(), 2U)
      << "fact 2: one authoritative region spans >=2 isolation sheets";

  const auto &region = *witnessRegion;
  ASSERT_FALSE(region.isolation_seams().empty())
      << "fact 3: the same multi-isolation region owns an internal isolation seam";

  const auto certificate = std::find_if(
      product.isolationSeamTransportCertificates().begin(),
      product.isolationSeamTransportCertificates().end(), [&](const auto &entry) {
        return entry.region() == region.id() &&
               std::binary_search(region.isolation_seams().begin(),
                                  region.isolation_seams().end(), entry.seam());
      });
  ASSERT_NE(product.isolationSeamTransportCertificates().end(), certificate)
      << "fact 4: the region/seam owns a checked reciprocal transport certificate";
  const auto *firstFace = region.find_face(certificate->firstFace());
  const auto *secondFace = region.find_face(certificate->secondFace());
  ASSERT_NE(nullptr, firstFace)
      << "fact 4: certificate first face is owned by the witness region";
  ASSERT_NE(nullptr, secondFace)
      << "fact 4: certificate second face is owned by the witness region";
  ASSERT_EQ(firstFace->sheet, certificate->firstSheet())
      << "fact 4: certificate first sheet matches authoritative face ownership";
  ASSERT_EQ(secondFace->sheet, certificate->secondSheet())
      << "fact 4: certificate second sheet matches authoritative face ownership";
  ASSERT_NE(certificate->firstSheet(), certificate->secondSheet())
      << "fact 4: certificate endpoint sheets are distinct";
  ASSERT_EQ(certificate->forward().inverse(), certificate->reverse())
      << "fact 4: certificate quarter-turn transport is reciprocal";
  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto seamIncidence = sourceIncidence.find(certificate->seam());
  ASSERT_NE(sourceIncidence.end(), seamIncidence)
      << "fact 4: certificate source faces are incident to the owned seam";
  ASSERT_GE(seamIncidence->second[0], 0)
      << "fact 4: certificate seam has a first incident source face";
  ASSERT_GE(seamIncidence->second[1], 0)
      << "fact 4: certificate seam has a second incident source face";
  const auto firstRow = sourceAuthority.row_for_topology(certificate->firstFace());
  const auto secondRow =
      sourceAuthority.row_for_topology(certificate->secondFace());
  ASSERT_TRUE(firstRow.has_value())
      << "fact 4: certificate first face has an authoritative source row";
  ASSERT_TRUE(secondRow.has_value())
      << "fact 4: certificate second face has an authoritative source row";
  const std::set<std::size_t> certificateRows{firstRow->index(),
                                               secondRow->index()};
  const std::set<std::size_t> incidentRows{
      static_cast<std::size_t>(seamIncidence->second[0]),
      static_cast<std::size_t>(seamIncidence->second[1])};
  ASSERT_EQ(incidentRows, certificateRows)
      << "fact 4: certificate source faces exactly own the seam incidence";
  const auto sourceMatchingIndices = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  const auto transition = sourceMatchingIndices.find(certificate->seam());
  ASSERT_NE(sourceMatchingIndices.end(), transition)
      << "fact 4: certificate seam has an explicit source transition";
  ASSERT_EQ(static_cast<std::size_t>(transition->second),
            certificate->transition().index())
      << "fact 4: certificate transition names the source-wide seam transition";

  std::map<directional::authority::PeriodicRelationId,
           const directional::geometry::SurfacePeriodicHolonomy *>
      canonicalRelations;
  for (const auto &relation : product.periodicHolonomies()) {
    if (relation.sourceTopologyRegion() != region.id()) continue;
    const auto expected = independent_periodic_relation_id(
        region.id(), relation.route(), relation.cutRoute());
    ASSERT_TRUE(expected.has_value())
        << "fact 5: same-region periodic relation has a canonical independent ID";
    ASSERT_EQ(relation.id(), *expected)
        << "fact 5: same-region periodic relation ID matches its canonical carriers";
    ASSERT_TRUE(canonicalRelations.emplace(relation.id(), &relation).second)
        << "fact 5: same-region periodic relation IDs are unique";
  }
  ASSERT_FALSE(canonicalRelations.empty())
      << "fact 5: the same multi-isolation region owns a canonical periodic relation";

  bool witnessedOwnedPeriodicPair = false;
  for (std::size_t edgeIndex = 0U; edgeIndex < product.edges().size();
       ++edgeIndex) {
    const auto &edge = product.edges()[edgeIndex];
    if (edge.boundaryKind != SurfaceFrontBoundaryKind::PeriodicCut ||
        edge.sourceTopologyRegion != region.id() ||
        !edge.periodicRelation.has_value() ||
        canonicalRelations.find(*edge.periodicRelation) == canonicalRelations.end() ||
        !edge.sharedBoundaryInterval.has_value()) {
      continue;
    }
    ASSERT_GE(edge.oppositeEdge, 0)
        << "fact 6: PeriodicCut owner has a reciprocal opposite edge";
    ASSERT_LT(static_cast<std::size_t>(edge.oppositeEdge), product.edges().size())
        << "fact 6: PeriodicCut reciprocal edge index is valid";
    const auto &opposite =
        product.edges()[static_cast<std::size_t>(edge.oppositeEdge)];
    ASSERT_EQ(SurfaceFrontBoundaryKind::PeriodicCut, opposite.boundaryKind)
        << "fact 6: reciprocal owner is also a PeriodicCut";
    ASSERT_EQ(static_cast<int>(edgeIndex), opposite.oppositeEdge)
        << "fact 6: PeriodicCut opposite ownership is reciprocal";
    ASSERT_EQ(region.id(), opposite.sourceTopologyRegion)
        << "fact 6: reciprocal PeriodicCut remains in the same topology region";
    ASSERT_EQ(edge.periodicRelation, opposite.periodicRelation)
        << "fact 6: reciprocal PeriodicCut names the exact same relation owner";
    ASSERT_TRUE(opposite.sharedBoundaryInterval.has_value())
        << "fact 6: reciprocal PeriodicCut retains shared-boundary provenance";
    ASSERT_EQ(edge.route, opposite.route.reversed())
        << "fact 6: reciprocal PeriodicCut source routes are reversed";
    ASSERT_EQ(edge.sharedBoundaryInterval->span,
              opposite.sharedBoundaryInterval->span)
        << "fact 6: reciprocal PeriodicCut provenance spans agree";
    ASSERT_EQ(edge.sharedBoundaryInterval->firstOrdinal,
              opposite.sharedBoundaryInterval->secondOrdinal)
        << "fact 6: reciprocal PeriodicCut provenance ordinals are reversed";
    ASSERT_EQ(edge.sharedBoundaryInterval->secondOrdinal,
              opposite.sharedBoundaryInterval->firstOrdinal)
        << "fact 6: reciprocal PeriodicCut provenance ordinals are reversed";
    ASSERT_NE(edge.sharedBoundaryInterval->orientation,
              opposite.sharedBoundaryInterval->orientation)
        << "fact 6: reciprocal PeriodicCut provenance orientations oppose";
    ASSERT_TRUE(edge.sharedBoundaryInterval->boundaryOccurrence.has_value())
        << "fact 6: forward PeriodicCut has an explicit boundary occurrence";
    ASSERT_TRUE(opposite.sharedBoundaryInterval->boundaryOccurrence.has_value())
        << "fact 6: reverse PeriodicCut has an explicit boundary occurrence";
    ASSERT_NE(edge.sharedBoundaryInterval->boundaryOccurrence,
              opposite.sharedBoundaryInterval->boundaryOccurrence)
        << "fact 6: reciprocal PeriodicCut occurrences are distinct";
    witnessedOwnedPeriodicPair = true;
    break;
  }
  ASSERT_TRUE(witnessedOwnedPeriodicPair)
      << "fact 6: reciprocal PeriodicCut pair names a canonical relation "
         "owned by the same region";
}

TEST(M5CP3,
     ProducedTorusPeriodicRelationStoragePermutationPreservesSelectedCertificate) {
  const auto &fixture = torus_fixture();
  const auto &product = fixture.network.phaseFront.product();
  ASSERT_GE(product.periodicHolonomies().size(), 2U);

  PhaseFrontDraft baselineDraft = phase_front_draft(product);
  PhaseFrontDraft reorderedDraft = baselineDraft;
  const auto firstStored = reorderedDraft.periodicHolonomies.front().id();
  const auto lastStored = reorderedDraft.periodicHolonomies.back().id();
  ASSERT_NE(firstStored, lastStored);
  std::reverse(reorderedDraft.periodicHolonomies.begin(),
               reorderedDraft.periodicHolonomies.end());
  EXPECT_NE(firstStored, reorderedDraft.periodicHolonomies.front().id());

  const auto baseline = materialize(fixture, std::move(baselineDraft));
  const auto reordered = materialize(fixture, std::move(reorderedDraft));
  ASSERT_TRUE(baseline.success) << baseline.failure;
  ASSERT_TRUE(reordered.success) << reordered.failure;
  const auto baselineCertificates =
      selected_relation_certificate_signature(baseline.mesh);
  const auto reorderedCertificates =
      selected_relation_certificate_signature(reordered.mesh);
  ASSERT_FALSE(baselineCertificates.empty());
  EXPECT_EQ(baselineCertificates, reorderedCertificates);
  EXPECT_EQ(directional::pipeline::hash_completion(baseline.mesh),
            directional::pipeline::hash_completion(reordered.mesh));
  EXPECT_EQ(baseline.consumedPeriodicHolonomies,
            reordered.consumedPeriodicHolonomies);
}

TEST(M5CP3, ProducedTorusMissingPeriodicRelationOwnerRejectsTyped) {
  const auto &fixture = torus_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int periodic =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::PeriodicCut);
  ASSERT_GE(periodic, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(periodic)];
  ASSERT_TRUE(edge.periodicRelation.has_value());
  edge.periodicRelation = std::nullopt;
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          MissingPeriodicRelationOwner);
}

TEST(M5CP3, PeriodicRelationRotationUsesBothAcceptedOccurrenceGauges) {
  const auto span = directional::authority::NetworkArcId::from_index(0U, 1U);
  const auto region =
      directional::authority::NetworkRegionId::from_index(0U, 1U);
  const auto forwardChart =
      directional::authority::FieldChartId::from_index(0U, 2U);
  const auto reverseChart =
      directional::authority::FieldChartId::from_index(1U, 2U);
  const auto forwardLocalFace =
      directional::authority::SourceFaceId::from_index(0U, 4U);
  const auto forwardOccurrenceFace =
      directional::authority::SourceFaceId::from_index(1U, 4U);
  const auto reverseLocalFace =
      directional::authority::SourceFaceId::from_index(2U, 4U);
  const auto reverseOccurrenceFace =
      directional::authority::SourceFaceId::from_index(3U, 4U);
  ASSERT_TRUE(span.has_value());
  ASSERT_TRUE(region.has_value());
  ASSERT_TRUE(forwardChart.has_value());
  ASSERT_TRUE(reverseChart.has_value());
  ASSERT_TRUE(forwardLocalFace.has_value());
  ASSERT_TRUE(forwardOccurrenceFace.has_value());
  ASSERT_TRUE(reverseLocalFace.has_value());
  ASSERT_TRUE(reverseOccurrenceFace.has_value());

  const directional::geometry::SurfaceSharedBoundaryInterval forwardInterval{
      span.value(),
      directional::authority::FieldExactRational::from_integer(0),
      directional::authority::FieldExactRational::from_integer(1),
      directional::authority::Orientation::Forward,
      directional::geometry::SurfaceBoundaryOccurrenceId{region.value(), 0U}};
  const directional::geometry::SurfaceSharedBoundaryInterval reverseInterval{
      span.value(),
      directional::authority::FieldExactRational::from_integer(1),
      directional::authority::FieldExactRational::from_integer(0),
      directional::authority::Orientation::Reverse,
      directional::geometry::SurfaceBoundaryOccurrenceId{region.value(), 1U}};

  directional::geometry::LocalLatticeState forward;
  forward.latticeCoordinate = {2, 1};
  forward.branchRotation = 3;
  forward.sourceChart = forwardChart.value();
  directional::geometry::LocalLatticeState reverse;
  reverse.latticeCoordinate = {5, -2};
  reverse.branchRotation = 1;
  reverse.sourceChart = reverseChart.value();

  const auto one = directional::authority::QuarterTurn::from_integer(1);
  const auto two = directional::authority::QuarterTurn::from_integer(2);
  const auto three = directional::authority::QuarterTurn::from_integer(3);
  const directional::geometry::SurfacePeriodicRelationEndpointBranchAuthority
      forwardAuthority{forwardLocalFace.value(), one,
                       forwardOccurrenceFace.value(), two};
  const directional::geometry::SurfacePeriodicRelationEndpointBranchAuthority
      reverseAuthority{reverseLocalFace.value(), three,
                       reverseOccurrenceFace.value(), one};

  const auto sourceTransport = one;
  const auto relationRotation =
      directional::geometry::periodic_relation_rotation(
          sourceTransport,
          forwardAuthority.occurrenceCarrierFaceBranchRotation,
          reverseAuthority.occurrenceCarrierFaceBranchRotation);
  const auto expectedRelationRotation = two;
  EXPECT_EQ(expectedRelationRotation, relationRotation);
  EXPECT_NE(sourceTransport, relationRotation);
  EXPECT_NE(
      relationRotation,
      compose(reverseAuthority.occurrenceCarrierFaceBranchRotation.inverse(),
              sourceTransport));
  EXPECT_NE(relationRotation,
            compose(sourceTransport,
                    forwardAuthority.occurrenceCarrierFaceBranchRotation));

  const auto forwardCutBranch = compose(
      forwardAuthority.localFaceBranchRotation.inverse(),
      directional::authority::QuarterTurn::from_integer(
          forward.branchRotation));
  const auto reverseCutBranch = compose(
      reverseAuthority.localFaceBranchRotation.inverse(),
      directional::authority::QuarterTurn::from_integer(
          reverse.branchRotation));
  ASSERT_EQ(two, forwardCutBranch);
  ASSERT_EQ(forwardCutBranch, reverseCutBranch);

  const auto forwardState =
      directional::geometry::make_periodic_relation_endpoint_state(
          forward, forwardInterval, relationRotation, forwardAuthority);
  const auto reverseState =
      directional::geometry::make_periodic_relation_endpoint_state(
          reverse, reverseInterval, relationRotation, reverseAuthority);
  ASSERT_TRUE(forwardState.has_value());
  ASSERT_TRUE(reverseState.has_value());
  EXPECT_EQ(forwardCutBranch, forwardState->branchRotation);
  EXPECT_EQ(compose(relationRotation, reverseCutBranch),
            reverseState->branchRotation);
  EXPECT_EQ(reverseState->branchRotation,
            compose(relationRotation, forwardState->branchRotation));
  EXPECT_EQ(forward.latticeCoordinate, forwardState->latticeCoordinate);
  EXPECT_EQ(directional::authority::rotate(relationRotation,
                                           reverse.latticeCoordinate),
            reverseState->latticeCoordinate);
  EXPECT_EQ(relationRotation, forwardState->relationRotation);
  EXPECT_EQ(relationRotation, reverseState->relationRotation);
}

TEST(M5CP3, StorageCanonicalPeriodicRelationResolvesSemanticForwardReverse) {
  const auto &fixture = torus_fixture();
  const auto &product = fixture.network.phaseFront.product();

  const directional::geometry::SurfacePeriodicHolonomy *storedRelation = nullptr;
  const directional::geometry::SurfaceFrontEdge *forwardEdge = nullptr;
  const directional::geometry::SurfaceFrontEdge *reverseEdge = nullptr;
  for (const auto &relation : product.periodicHolonomies()) {
    const directional::geometry::SurfaceFrontEdge *candidateForward = nullptr;
    const directional::geometry::SurfaceFrontEdge *candidateReverse = nullptr;
    for (const auto &edge : product.edges()) {
      if (edge.periodicRelation != relation.id() ||
          !edge.sharedBoundaryInterval.has_value() ||
          !edge.sharedBoundaryInterval->boundaryOccurrence.has_value()) {
        continue;
      }
      if (edge.sharedBoundaryInterval->orientation ==
          directional::authority::Orientation::Forward) {
        candidateForward = &edge;
      } else if (edge.sharedBoundaryInterval->orientation ==
                 directional::authority::Orientation::Reverse) {
        candidateReverse = &edge;
      }
    }
    if (candidateForward == nullptr || candidateReverse == nullptr) continue;
    if (relation.cutRoute().reversed() == candidateForward->route &&
        relation.cutRoute() == candidateReverse->route) {
      storedRelation = &relation;
      forwardEdge = candidateForward;
      reverseEdge = candidateReverse;
      break;
    }
  }

  ASSERT_NE(nullptr, storedRelation)
      << "ordinary torus must retain a relation whose storage-canonical "
         "representative is inverse to semantic A3 Forward -> Reverse";
  ASSERT_NE(nullptr, forwardEdge);
  ASSERT_NE(nullptr, reverseEdge);
  ASSERT_TRUE(forwardEdge->periodicFromLattice.has_value());
  ASSERT_TRUE(forwardEdge->periodicToLattice.has_value());
  ASSERT_TRUE(reverseEdge->periodicFromLattice.has_value());
  ASSERT_TRUE(reverseEdge->periodicToLattice.has_value());

  const auto canonical = directional::geometry::surface_cell_tracing_detail::
      canonicalize_periodic_holonomy(*storedRelation);
  EXPECT_EQ(storedRelation->id(), canonical.id());
  EXPECT_EQ(storedRelation->action(), canonical.action());
  EXPECT_EQ(storedRelation->route(), canonical.route());
  EXPECT_EQ(storedRelation->cutRoute(), canonical.cutRoute());

  const auto semanticAction =
      directional::geometry::resolve_periodic_relation_semantic_action(
          *storedRelation, *forwardEdge, *reverseEdge);
  ASSERT_TRUE(semanticAction.has_value());
  EXPECT_EQ(storedRelation->action().inverse(), *semanticAction);
  EXPECT_NE(storedRelation->action(), *semanticAction);

  auto semanticRelation = directional::geometry::SurfacePeriodicHolonomy::make(
      storedRelation->sourceTopologyRegion(), *semanticAction,
      storedRelation->route().reversed(), storedRelation->cutRoute().reversed());
  const auto *semanticValue =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(
          &semanticRelation);
  ASSERT_NE(nullptr, semanticValue);
  EXPECT_EQ(storedRelation->id(), semanticValue->id());
  const auto recanonicalized =
      directional::geometry::surface_cell_tracing_detail::
          canonicalize_periodic_holonomy(*semanticValue);
  EXPECT_EQ(storedRelation->id(), recanonicalized.id());
  EXPECT_EQ(storedRelation->action(), recanonicalized.action());
  EXPECT_EQ(storedRelation->route(), recanonicalized.route());
  EXPECT_EQ(storedRelation->cutRoute(), recanonicalized.cutRoute());

  const auto expectedForwardFrom =
      directional::geometry::make_periodic_relation_endpoint_state(
          forwardEdge->fromLattice, *forwardEdge->sharedBoundaryInterval,
          semanticAction->rotation,
          forwardEdge->periodicFromLattice->branchAuthority);
  const auto expectedForwardTo =
      directional::geometry::make_periodic_relation_endpoint_state(
          forwardEdge->toLattice, *forwardEdge->sharedBoundaryInterval,
          semanticAction->rotation,
          forwardEdge->periodicToLattice->branchAuthority);
  const auto expectedReverseFrom =
      directional::geometry::make_periodic_relation_endpoint_state(
          reverseEdge->fromLattice, *reverseEdge->sharedBoundaryInterval,
          semanticAction->rotation,
          reverseEdge->periodicFromLattice->branchAuthority);
  const auto expectedReverseTo =
      directional::geometry::make_periodic_relation_endpoint_state(
          reverseEdge->toLattice, *reverseEdge->sharedBoundaryInterval,
          semanticAction->rotation,
          reverseEdge->periodicToLattice->branchAuthority);
  ASSERT_TRUE(expectedForwardFrom.has_value());
  ASSERT_TRUE(expectedForwardTo.has_value());
  ASSERT_TRUE(expectedReverseFrom.has_value());
  ASSERT_TRUE(expectedReverseTo.has_value());
  EXPECT_EQ(*expectedForwardFrom, *forwardEdge->periodicFromLattice);
  EXPECT_EQ(*expectedForwardTo, *forwardEdge->periodicToLattice);
  EXPECT_EQ(*expectedReverseFrom, *reverseEdge->periodicFromLattice);
  EXPECT_EQ(*expectedReverseTo, *reverseEdge->periodicToLattice);
  EXPECT_EQ(reverseEdge->periodicToLattice->latticeCoordinate,
            semanticAction->apply(
                forwardEdge->periodicFromLattice->latticeCoordinate));
  EXPECT_EQ(reverseEdge->periodicFromLattice->latticeCoordinate,
            semanticAction->apply(
                forwardEdge->periodicToLattice->latticeCoordinate));
  EXPECT_EQ(
      reverseEdge->periodicToLattice->branchRotation,
      compose(semanticAction->rotation,
              forwardEdge->periodicFromLattice->branchRotation));
  EXPECT_EQ(
      reverseEdge->periodicFromLattice->branchRotation,
      compose(semanticAction->rotation,
              forwardEdge->periodicToLattice->branchRotation));

  EXPECT_FALSE(
      directional::geometry::resolve_periodic_relation_semantic_action(
          *storedRelation, *reverseEdge, *forwardEdge)
          .has_value());

  PhaseFrontDraft tampered = phase_front_draft(product);
  const auto relation = std::find_if(
      tampered.periodicHolonomies.begin(), tampered.periodicHolonomies.end(),
      [&](const auto &candidate) { return candidate.id() == storedRelation->id(); });
  ASSERT_NE(tampered.periodicHolonomies.end(), relation);
  auto tamperedAction = relation->action();
  ++tamperedAction.shift.x;
  ASSERT_NE(relation->action(), tamperedAction);
  auto rebuilt = directional::geometry::SurfacePeriodicHolonomy::make(
      relation->sourceTopologyRegion(), tamperedAction, relation->route(),
      relation->cutRoute());
  auto *rebuiltValue =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&rebuilt);
  ASSERT_NE(nullptr, rebuiltValue);
  ASSERT_EQ(relation->id(), rebuiltValue->id());
  *relation = std::move(*rebuiltValue);

  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          NonReciprocalPeriodicRelation);
}

TEST(M5CP3, ProducedTorusNonzeroZ4RotationTranslationMaterializes) {
  const auto &witnessFixture = nonzero_z4_torus_witness_fixture();
  const auto &fixture = witnessFixture.fixture;
  const auto &witness = witnessFixture.witness;
  ASSERT_EQ(directional::authority::QuarterTurn::from_integer(3),
            witness.sourceRotation);
  ASSERT_EQ(witness.sourceRotation, witness.atlasRotation);

  const auto semanticRelation =
      produced_semantic_relation_for_witness(witnessFixture);
  ASSERT_TRUE(semanticRelation.has_value())
      << "source/A3-selected nonzero-Z4 hard-edge witness must publish a "
         "deterministically resolvable semantic relation";
  const auto *relation = semanticRelation->storedRelation;
  const auto *forwardEdge = semanticRelation->forwardEdge;
  const auto *reverseEdge = semanticRelation->reverseEdge;
  ASSERT_NE(nullptr, relation);
  ASSERT_NE(nullptr, forwardEdge);
  ASSERT_NE(nullptr, reverseEdge);

  ASSERT_TRUE(semanticRelation->storageInverted)
      << "committed torus witness must exercise inverse canonical storage";
  ASSERT_EQ(relation->cutRoute().reversed(), forwardEdge->route);
  ASSERT_EQ(relation->cutRoute(), reverseEdge->route);
  EXPECT_NE(relation->action(), semanticRelation->semanticAction);
  EXPECT_NE(relation->route(), semanticRelation->semanticGeneratorRoute);
  EXPECT_EQ(witness.generatorRoute, semanticRelation->semanticGeneratorRoute)
      << "resolved semantic generator route must preserve independent A3 "
         "Forward -> Reverse authority";

  const auto storedId = independent_periodic_relation_id(
      relation->sourceTopologyRegion(), relation->route(), relation->cutRoute());
  ASSERT_TRUE(storedId.has_value());
  EXPECT_EQ(relation->id(), *storedId);
  const auto semanticId = independent_periodic_relation_id(
      relation->sourceTopologyRegion(),
      semanticRelation->semanticGeneratorRoute, forwardEdge->route);
  ASSERT_TRUE(semanticId.has_value());
  EXPECT_EQ(relation->id(), *semanticId);

  EXPECT_EQ(witness.sourceRotation, semanticRelation->semanticAction.rotation);
  EXPECT_NE(directional::authority::QuarterTurn{},
            semanticRelation->semanticAction.rotation);
  EXPECT_NE((directional::authority::LatticeTranslation{0, 0}),
            semanticRelation->semanticAction.shift);
  ASSERT_TRUE(forwardEdge->periodicFromLattice.has_value());
  ASSERT_TRUE(forwardEdge->periodicToLattice.has_value());
  ASSERT_TRUE(reverseEdge->periodicFromLattice.has_value());
  ASSERT_TRUE(reverseEdge->periodicToLattice.has_value());

  const auto expectedForwardFrom =
      directional::geometry::make_periodic_relation_endpoint_state(
          forwardEdge->fromLattice, *forwardEdge->sharedBoundaryInterval,
          semanticRelation->semanticAction.rotation,
          forwardEdge->periodicFromLattice->branchAuthority);
  const auto expectedForwardTo =
      directional::geometry::make_periodic_relation_endpoint_state(
          forwardEdge->toLattice, *forwardEdge->sharedBoundaryInterval,
          semanticRelation->semanticAction.rotation,
          forwardEdge->periodicToLattice->branchAuthority);
  const auto expectedReverseFrom =
      directional::geometry::make_periodic_relation_endpoint_state(
          reverseEdge->fromLattice, *reverseEdge->sharedBoundaryInterval,
          semanticRelation->semanticAction.rotation,
          reverseEdge->periodicFromLattice->branchAuthority);
  const auto expectedReverseTo =
      directional::geometry::make_periodic_relation_endpoint_state(
          reverseEdge->toLattice, *reverseEdge->sharedBoundaryInterval,
          semanticRelation->semanticAction.rotation,
          reverseEdge->periodicToLattice->branchAuthority);
  ASSERT_TRUE(expectedForwardFrom.has_value());
  ASSERT_TRUE(expectedForwardTo.has_value());
  ASSERT_TRUE(expectedReverseFrom.has_value());
  ASSERT_TRUE(expectedReverseTo.has_value());
  EXPECT_EQ(*expectedForwardFrom, *forwardEdge->periodicFromLattice);
  EXPECT_EQ(*expectedForwardTo, *forwardEdge->periodicToLattice);
  EXPECT_EQ(*expectedReverseFrom, *reverseEdge->periodicFromLattice);
  EXPECT_EQ(*expectedReverseTo, *reverseEdge->periodicToLattice);
  EXPECT_EQ(reverseEdge->periodicToLattice->latticeCoordinate,
            semanticRelation->semanticAction.apply(
                forwardEdge->periodicFromLattice->latticeCoordinate));
  EXPECT_EQ(reverseEdge->periodicFromLattice->latticeCoordinate,
            semanticRelation->semanticAction.apply(
                forwardEdge->periodicToLattice->latticeCoordinate));
  EXPECT_EQ(
      reverseEdge->periodicToLattice->branchRotation,
      compose(semanticRelation->semanticAction.rotation,
              forwardEdge->periodicFromLattice->branchRotation));
  EXPECT_EQ(
      reverseEdge->periodicFromLattice->branchRotation,
      compose(semanticRelation->semanticAction.rotation,
              forwardEdge->periodicToLattice->branchRotation));

  const auto materialized = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(materialized.success) << materialized.failure;
  const auto certificates =
      selected_relation_certificate_signature(materialized.mesh);
  ASSERT_FALSE(certificates.empty());
  const bool selected = std::any_of(
      certificates.begin(), certificates.end(), [&](const auto &certificate) {
        return std::any_of(
            certificate.orderedSteps.begin(), certificate.orderedSteps.end(),
            [&](const auto &step) {
              if (step.periodicRelation != relation->id()) return false;
              return step.appliedTransport == relation->action() ||
                     step.appliedTransport == relation->action().inverse();
            });
      });
  EXPECT_TRUE(selected);
  EXPECT_GT(materialized.consumedPeriodicHolonomies, 0U);
}

TEST(M5CP3,
     ProducedTorusPeriodicPairStorageSwapPreservesSemanticDirection) {
  const auto &witnessFixture = nonzero_z4_torus_witness_fixture();
  const auto *relation = produced_relation_for_witness(witnessFixture);
  ASSERT_NE(nullptr, relation);

  PhaseFrontDraft baseline =
      phase_front_draft(witnessFixture.fixture.network.phaseFront);
  PhaseFrontDraft reordered = baseline;
  int firstIndex = -1;
  int secondIndex = -1;
  for (int edgeIndex = 0; edgeIndex < static_cast<int>(reordered.edges.size());
       ++edgeIndex) {
    const auto &edge = reordered.edges[static_cast<std::size_t>(edgeIndex)];
    if (edge.periodicRelation != relation->id() || edge.oppositeEdge < 0) {
      continue;
    }
    firstIndex = edgeIndex;
    secondIndex = edge.oppositeEdge;
    break;
  }
  ASSERT_GE(firstIndex, 0);
  ASSERT_GE(secondIndex, 0);
  ASSERT_NE(firstIndex, secondIndex);
  std::swap(reordered.edges[static_cast<std::size_t>(firstIndex)],
            reordered.edges[static_cast<std::size_t>(secondIndex)]);
  reordered.edges[static_cast<std::size_t>(firstIndex)].oppositeEdge =
      secondIndex;
  reordered.edges[static_cast<std::size_t>(secondIndex)].oppositeEdge =
      firstIndex;
  for (auto &event : reordered.events) {
    if (event.firstEdge == firstIndex) {
      event.firstEdge = secondIndex;
    } else if (event.firstEdge == secondIndex) {
      event.firstEdge = firstIndex;
    }
    if (event.secondEdge == firstIndex) {
      event.secondEdge = secondIndex;
    } else if (event.secondEdge == secondIndex) {
      event.secondEdge = firstIndex;
    }
  }

  const auto baselineResult = materialize(witnessFixture.fixture, baseline);
  const auto reorderedResult = materialize(witnessFixture.fixture, reordered);
  ASSERT_TRUE(baselineResult.success) << baselineResult.failure;
  ASSERT_TRUE(reorderedResult.success) << reorderedResult.failure;
  EXPECT_EQ(selected_relation_certificate_signature(baselineResult.mesh),
            selected_relation_certificate_signature(reorderedResult.mesh));
}

TEST(M5CP3, ProducedTorusTamperedNonzeroZ4TransformRejectsTyped) {
  const auto &witnessFixture = nonzero_z4_torus_witness_fixture();
  const auto &witness = witnessFixture.witness;
  ASSERT_EQ(directional::authority::QuarterTurn::from_integer(3),
            witness.sourceRotation);
  ASSERT_EQ(witness.sourceRotation, witness.atlasRotation);

  const auto semanticRelation =
      produced_semantic_relation_for_witness(witnessFixture);
  ASSERT_TRUE(semanticRelation.has_value())
      << "source/A3-selected nonzero-Z4 hard-edge witness must publish a "
         "deterministically resolvable semantic relation";
  const auto *published = semanticRelation->storedRelation;
  const auto *forwardEdge = semanticRelation->forwardEdge;
  const auto *reverseEdge = semanticRelation->reverseEdge;
  ASSERT_NE(nullptr, published);
  ASSERT_NE(nullptr, forwardEdge);
  ASSERT_NE(nullptr, reverseEdge);

  ASSERT_TRUE(semanticRelation->storageInverted)
      << "committed torus witness must exercise inverse canonical storage";
  ASSERT_EQ(published->cutRoute().reversed(), forwardEdge->route);
  ASSERT_EQ(published->cutRoute(), reverseEdge->route);
  EXPECT_NE(published->action(), semanticRelation->semanticAction);
  EXPECT_NE(published->route(), semanticRelation->semanticGeneratorRoute);
  EXPECT_EQ(witness.generatorRoute, semanticRelation->semanticGeneratorRoute);
  EXPECT_EQ(witness.sourceRotation, semanticRelation->semanticAction.rotation);
  EXPECT_NE(directional::authority::QuarterTurn{},
            semanticRelation->semanticAction.rotation);
  EXPECT_NE((directional::authority::LatticeTranslation{0, 0}),
            semanticRelation->semanticAction.shift);

  const auto semanticId = independent_periodic_relation_id(
      published->sourceTopologyRegion(),
      semanticRelation->semanticGeneratorRoute, forwardEdge->route);
  ASSERT_TRUE(semanticId.has_value());
  EXPECT_EQ(published->id(), *semanticId);

  PhaseFrontDraft tampered =
      phase_front_draft(witnessFixture.fixture.network.phaseFront);
  const auto relation = std::find_if(
      tampered.periodicHolonomies.begin(), tampered.periodicHolonomies.end(),
      [&](const auto &candidate) { return candidate.id() == published->id(); });
  ASSERT_NE(tampered.periodicHolonomies.end(), relation);
  const auto originalId = relation->id();
  const auto originalAction = relation->action();
  auto action = originalAction;
  action.rotation = directional::authority::QuarterTurn::from_integer(
      static_cast<int>(action.rotation.value()) + 1);
  ASSERT_NE(originalAction, action);
  auto rebuilt = directional::geometry::SurfacePeriodicHolonomy::make(
      relation->sourceTopologyRegion(), action, relation->route(),
      relation->cutRoute());
  auto *value =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&rebuilt);
  ASSERT_NE(nullptr, value);
  ASSERT_EQ(originalId, value->id());
  *relation = std::move(*value);

  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          NonReciprocalPeriodicRelation);
}

TEST(M5CP3, ProducedTorusUnusedValidRelationDoesNotAlterSelectedCertificate) {
  const auto &fixture = torus_fixture();
  const auto &product = fixture.network.phaseFront.product();
  PhaseFrontDraft baselineDraft = phase_front_draft(product);
  const auto baseline = materialize(fixture, baselineDraft);
  ASSERT_TRUE(baseline.success) << baseline.failure;
  const auto baselineCertificates =
      selected_relation_certificate_signature(baseline.mesh);
  ASSERT_FALSE(baselineCertificates.empty());

  std::set<directional::authority::SourceEdgeTopologyKey> periodicCarriers;
  for (const auto &relation : product.periodicHolonomies()) {
    for (const auto &step : relation.route().carrier_identity()) {
      periodicCarriers.insert(step.topology);
    }
    for (const auto &step : relation.cutRoute().carrier_identity()) {
      periodicCarriers.insert(step.topology);
    }
  }

  const Eigen::MatrixXd raw = read_rawfield(
      directional::tests::benchmark_fixture_path("milestone-g/torus.rawfield"),
      fixture.mesh.F.rows());
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(fixture.mesh,
                                                                    raw);
  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceMatchingIndices = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  const auto &sourceAuthority = product.sourceTopologyRegions();
  std::map<directional::authority::TopologyRegionId,
           std::set<directional::authority::CanonicalRoute>>
      sourceRoutes;
  for (const auto &transition : crossField.edgeTransitions) {
    const auto carrier = test_source_edge_topology(
        transition.sourceVertex0, transition.sourceVertex1,
        static_cast<std::size_t>(fixture.mesh.V.rows()));
    if (periodicCarriers.count(carrier) != 0U) continue;
    const auto firstFace = directional::authority::SourceFaceId::from_index(
        transition.firstFace, static_cast<std::size_t>(fixture.mesh.F.rows()));
    const auto secondFace = directional::authority::SourceFaceId::from_index(
        transition.secondFace, static_cast<std::size_t>(fixture.mesh.F.rows()));
    if (!firstFace || !secondFace ||
        sourceAuthority.region_for_row(firstFace.value()) !=
            sourceAuthority.region_for_row(secondFace.value())) {
      continue;
    }
    const auto transitionIndex = sourceMatchingIndices.find(carrier);
    if (transitionIndex == sourceMatchingIndices.end()) continue;
    const auto transitionId =
        directional::authority::InteriorTransitionId::from_index(
            transitionIndex->second, sourceMatchingIndices.size());
    if (!transitionId) continue;
    directional::authority::GridAutomorphism transport =
        directional::authority::GridAutomorphism::identity();
    transport.rotation = directional::authority::QuarterTurn::from_integer(
        transition.matching);
    const auto step = directional::authority::TransitionStep::interior(
        carrier, transitionId.value(), transport,
        directional::authority::Orientation::Forward);
    if (!step) continue;
    sourceRoutes[sourceAuthority.region_for_row(firstFace.value())].insert(
        directional::authority::CanonicalRoute::from_observed_steps(
            {step.value()}));
  }

  std::optional<directional::authority::TopologyRegionId> unusedRegion;
  std::optional<directional::authority::CanonicalRoute> unusedGenerator;
  std::optional<directional::authority::CanonicalRoute> unusedCut;
  const directional::geometry::SurfacePeriodicHolonomy *actionOwner = nullptr;
  for (const auto &[region, routes] : sourceRoutes) {
    if (routes.size() < 2U) continue;
    const auto owner = std::find_if(
        product.periodicHolonomies().begin(), product.periodicHolonomies().end(),
        [&](const auto &relation) {
          return relation.sourceTopologyRegion() == region;
        });
    if (owner == product.periodicHolonomies().end()) continue;
    auto route = routes.begin();
    unusedRegion = region;
    unusedGenerator = *route++;
    unusedCut = *route;
    actionOwner = &*owner;
    break;
  }
  ASSERT_TRUE(unusedRegion.has_value());
  ASSERT_TRUE(unusedGenerator.has_value());
  ASSERT_TRUE(unusedCut.has_value());
  ASSERT_NE(nullptr, actionOwner);
  auto unusedConstruction = directional::geometry::SurfacePeriodicHolonomy::make(
      *unusedRegion, actionOwner->action(), *unusedGenerator, *unusedCut);
  const auto *unused =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(
          &unusedConstruction);
  ASSERT_NE(nullptr, unused);

  ASSERT_TRUE(std::none_of(
      baselineDraft.periodicHolonomies.begin(),
      baselineDraft.periodicHolonomies.end(), [&](const auto &relation) {
        return relation.id() == unused->id();
      }));
  ASSERT_TRUE(std::none_of(
      baselineDraft.edges.begin(), baselineDraft.edges.end(),
      [&](const auto &edge) { return edge.periodicRelation == unused->id(); }));
  ASSERT_FALSE(
      certificate_references_periodic_relation(baselineCertificates,
                                               unused->id()));

  PhaseFrontDraft extendedDraft = baselineDraft;
  const auto unusedId = unused->id();
  extendedDraft.periodicHolonomies.push_back(*unused);
  std::reverse(extendedDraft.periodicHolonomies.begin(),
               extendedDraft.periodicHolonomies.end());

  const auto extended = materialize(fixture, std::move(extendedDraft));
  ASSERT_TRUE(extended.success) << extended.failure;
  const auto extendedCertificates =
      selected_relation_certificate_signature(extended.mesh);
  EXPECT_EQ(baselineCertificates, extendedCertificates);
  EXPECT_EQ(directional::pipeline::hash_completion(baseline.mesh),
            directional::pipeline::hash_completion(extended.mesh));
  EXPECT_EQ(baseline.consumedPeriodicHolonomies,
            extended.consumedPeriodicHolonomies);
  EXPECT_FALSE(
      certificate_references_periodic_relation(extendedCertificates, unusedId));
}

TEST(SurfaceCellTransitionQuotient,
     MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner) {
  const auto &fixture = torus_fixture();
  PhaseFrontDraft reordered = phase_front_draft(fixture.network.phaseFront);
  ASSERT_GT(reordered.periodicHolonomies.size(), 1U);
  std::reverse(reordered.periodicHolonomies.begin(),
               reordered.periodicHolonomies.end());
  const auto result = materialize(fixture, reordered);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(reordered.periodicHolonomies.size(),
            result.consumedPeriodicHolonomies);
}

TEST(SurfaceCellTransitionQuotient,
     SwappedPeriodicRelationOwnersAreRejected) {
  const auto &fixture = torus_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  ASSERT_GT(tampered.periodicHolonomies.size(), 1U);
  std::vector<std::size_t> periodicEdges;
  for (std::size_t edgeIndex = 0; edgeIndex < tampered.edges.size(); ++edgeIndex) {
    if (tampered.edges[edgeIndex].periodicRelation.has_value()) {
      periodicEdges.push_back(edgeIndex);
    }
  }
  ASSERT_GE(periodicEdges.size(), 2U);
  std::size_t second = 1U;
  while (second < periodicEdges.size() &&
         tampered.edges[periodicEdges[0]].periodicRelation ==
             tampered.edges[periodicEdges[second]].periodicRelation) {
    ++second;
  }
  ASSERT_LT(second, periodicEdges.size());
  std::swap(tampered.edges[periodicEdges[0]].periodicRelation,
            tampered.edges[periodicEdges[second]].periodicRelation);
  expect_phase_front_product_error(
      construct_phase_front_product(std::move(tampered)),
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          NonReciprocalPeriodicRelation);
}

TEST(SurfaceCellTransitionQuotient,
     MissingPeriodicRelationOwnerIsRejected) {
  PhaseFrontDraft tampered = phase_front_draft(direct_periodic_owner_product());
  const int periodic =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::PeriodicCut);
  ASSERT_GE(periodic, 0);
  auto &periodicEdge = tampered.edges[static_cast<std::size_t>(periodic)];
  ASSERT_TRUE(periodicEdge.periodicRelation.has_value());
  const auto owner = periodicEdge.periodicRelation.value();
  const auto ownerRelation = std::find_if(
      tampered.periodicHolonomies.begin(), tampered.periodicHolonomies.end(),
      [&](const auto &relation) { return relation.id() == owner; });
  ASSERT_NE(tampered.periodicHolonomies.end(), ownerRelation);
  periodicEdge.periodicRelation = std::nullopt;
  const auto construction = construct_phase_front_product(std::move(tampered));
  const auto *error =
      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
          &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontProductErrorCode::
                MissingPeriodicRelationOwner,
            error->code);
}

TEST(SurfaceCellTransitionQuotient,
     ExactHardRailCounterpartsStitchAcrossTopologyRegions) {
  const auto &fixture = hard_rail_fixture();
  const int hardRail = first_edge_of_kind(fixture.network.phaseFront,
                                          SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  const auto &edge =
      fixture.network.phaseFront.product().edges()[static_cast<std::size_t>(hardRail)];
  ASSERT_GE(edge.oppositeEdge, 0);
  const auto &opposite = fixture.network.phaseFront.product().edges()[
      static_cast<std::size_t>(edge.oppositeEdge)];
  EXPECT_NE(edge.sourceTopologyRegion, opposite.sourceTopologyRegion);
  EXPECT_TRUE(route_is_all_interior(edge.route));
  EXPECT_TRUE(route_is_all_interior(opposite.route));
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(1, result.connectedComponents);
}

TEST(SurfaceCellTransitionQuotient,
     MissingHardRailCounterpartIsRejected) {
  const auto &fixture = hard_rail_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  tampered.edges[static_cast<std::size_t>(hardRail)].oppositeEdge = -1;
  const auto construction = construct_phase_front_product(std::move(tampered));
  const auto *error =
      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
          &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontProductErrorCode::
                InvalidOppositeEdge,
            error->code);
}

TEST(SurfaceCellTransitionQuotient,
     AmbiguousHardRailCounterpartIsRejected) {
  const auto &fixture = hard_rail_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  const int opposite =
      tampered.edges[static_cast<std::size_t>(hardRail)].oppositeEdge;
  ASSERT_GE(opposite, 0);
  tampered.edges[static_cast<std::size_t>(opposite)].oppositeEdge = opposite;
  const auto construction = construct_phase_front_product(std::move(tampered));
  const auto *error =
      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
          &construction);
  ASSERT_NE(nullptr, error);
  EXPECT_EQ(directional::geometry::SurfacePhaseFrontProductErrorCode::
                InvalidOppositeEdge,
            error->code);
}

TEST(SurfaceCellTransitionQuotient,
     QuotientLineageRetainsScalarPointAndCompleteSortedAuthority) {
  const auto &fixture = split_isolation_fixture();
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  ASSERT_FALSE(result.mesh.vertexLineage.empty());
  bool foundSeamEquivalence = false;
  for (const auto &lineage : result.mesh.vertexLineage) {
    EXPECT_TRUE(lineage.sourcePoint.valid());
    EXPECT_TRUE(lineage.sourceSupport.has_value());
    EXPECT_TRUE(lineage.quotientClass.has_value());
    EXPECT_FALSE(lineage.sourceOccurrences.empty());
    EXPECT_TRUE(std::is_sorted(lineage.sourceOccurrences.begin(),
                               lineage.sourceOccurrences.end()));
    EXPECT_FALSE(lineage.sourceTopologyRegions.empty());
    EXPECT_FALSE(lineage.sourceIsolationSheets.empty());
    EXPECT_FALSE(lineage.sourceCharts.empty());
    EXPECT_TRUE(std::is_sorted(lineage.sourceTopologyRegions.begin(),
                               lineage.sourceTopologyRegions.end()));
    EXPECT_TRUE(std::is_sorted(lineage.sourceIsolationSheets.begin(),
                               lineage.sourceIsolationSheets.end()));
    EXPECT_TRUE(
        std::is_sorted(lineage.sourceCharts.begin(), lineage.sourceCharts.end()));
    EXPECT_TRUE(
        std::is_sorted(lineage.equivalences.begin(), lineage.equivalences.end()));
    for (const auto &equivalence : lineage.equivalences) {
      foundSeamEquivalence |= !equivalence.route.empty();
    }
  }
  EXPECT_TRUE(foundSeamEquivalence);
}

TEST(SurfaceCellTransitionQuotient,
     RepeatedAuthoritativeCellCornerIsRejected) {
  const auto &fixture = square_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  ASSERT_FALSE(tampered.cells.empty());
  tampered.cells.front().corners[1] = tampered.cells.front().corners[0];
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
}

TEST(SurfaceCellTransitionQuotient,
     NonmanifoldSourceEdgeIsRejectedBeforeQuotient) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
      -1.0, 0.0, 0.0, 0.0, 1.0;
  Eigen::MatrixXi faces(3, 3);
  faces << 0, 1, 2, 1, 0, 3, 0, 1, 4;
  const auto validation =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces);
  EXPECT_FALSE(validation.accepted);
}

TEST(SurfaceCellTransitionQuotient,
     NonmanifoldSourceVertexFanIsRejectedBeforeQuotient) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, -1.0,
      0.0, 0.0, 0.0, -1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 3, 4;
  const auto validation =
      directional::validation::MeshValidator::validate_surface_mesh(vertices,
                                                                    faces);
  EXPECT_FALSE(validation.accepted);
}

TEST(SurfaceCellTransitionQuotient,
     ArtificialInteriorBoundaryIsRejected) {
  const auto &fixture = square_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int ordinary =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::OrdinaryInterior);
  ASSERT_GE(ordinary, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(ordinary)];
  const int opposite = edge.oppositeEdge;
  ASSERT_GE(opposite, 0);
  const auto interiorTopology = test_source_edge_topology(
      0, 2, static_cast<std::size_t>(fixture.mesh.V.rows()));
  edge.oppositeEdge = -1;
  edge.exterior = true;
  edge.boundaryKind = SurfaceFrontBoundaryKind::GenuineSourceBoundary;
  edge.route = boundary_route_from_topology(interiorTopology);
  auto &other = tampered.edges[static_cast<std::size_t>(opposite)];
  other.oppositeEdge = -1;
  other.exterior = true;
  other.boundaryKind = SurfaceFrontBoundaryKind::GenuineSourceBoundary;
  other.route = boundary_route_from_topology(interiorTopology);
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("FalseAuthoritativeSourceBoundary", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     ComponentBoundaryAndEulerFactsAreComputedFromIncidence) {
  const auto square = materialize(square_fixture(),
                                  square_fixture().network.phaseFront);
  const auto overlap = materialize(overlap_fixture(),
                                   overlap_fixture().network.phaseFront);
  const auto cylinder = materialize(cylinder_fixture(),
                                    cylinder_fixture().network.phaseFront);
  ASSERT_TRUE(square.success) << square.failure;
  ASSERT_TRUE(overlap.success) << overlap.failure;
  ASSERT_TRUE(cylinder.success) << cylinder.failure;
  EXPECT_EQ((std::array<int, 3>{1, 1, 1}),
            (std::array<int, 3>{square.connectedComponents,
                                square.boundaryLoopCount,
                                square.eulerCharacteristic}));
  EXPECT_EQ((std::array<int, 3>{2, 2, 2}),
            (std::array<int, 3>{overlap.connectedComponents,
                                overlap.boundaryLoopCount,
                                overlap.eulerCharacteristic}));
  EXPECT_EQ((std::array<int, 3>{1, 2, 0}),
            (std::array<int, 3>{cylinder.connectedComponents,
                                cylinder.boundaryLoopCount,
                                cylinder.eulerCharacteristic}));
}

TEST(SurfaceCellTransitionQuotient,
     DeterministicTracingFailureRetainsAuthorityIfAndOnlyIfRequested) {
  const auto meshPath = directional::tests::benchmark_fixture_path(
      "milestone-g/plane.obj");
  const auto fieldPath = directional::tests::benchmark_fixture_path(
      "milestone-g/plane.rawfield");
  directional::TriMesh mesh;
  ASSERT_TRUE(directional::readOBJ(meshPath.string(), mesh));
  const Eigen::MatrixXd raw = read_rawfield(fieldPath, mesh.F.rows());
  const auto run = [&](const bool retain) {
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
    return directional::pipeline::remesh_from_raw_cross_field(
        mesh.V, mesh.F, raw, options);
  };
  const auto retained = run(true);
  const auto released = run(false);
  EXPECT_TRUE(retained.is_rejected());
  EXPECT_TRUE(released.is_rejected());
  EXPECT_EQ(retained.diagnostics.terminalFailureCode,
            released.diagnostics.terminalFailureCode);
  EXPECT_EQ(retained.diagnostics.terminalFailureStage,
            released.diagnostics.terminalFailureStage);
  EXPECT_EQ("InjectedStageFailure", retained.diagnostics.terminalFailureCode);
  EXPECT_EQ("tracing", retained.diagnostics.terminalFailureStage);
  EXPECT_TRUE(retained.surfaceCellContext.hasTraceNetwork);
  EXPECT_FALSE(released.surfaceCellContext.hasTraceNetwork);
  ASSERT_TRUE(retained.surfaceCellContext.productSnapshots.traceNetwork.phaseFront.is_produced());
  EXPECT_FALSE(
      retained.surfaceCellContext.productSnapshots.traceNetwork.phaseFront.product().cells().empty());
  EXPECT_EQ(nullptr,
            released.surfaceCellContext.productSnapshots.traceNetwork.phaseFront.produced_product());
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestIsInvariantToVertexFaceAndComponentRowPermutation) {
  const auto baseline = semantic_two_component_result();
  const auto permuted = permute_semantic_output_rows(baseline);
  const std::uint64_t baselineHash =
      directional::bench::benchmark_output_semantic_hash(baseline);
  ASSERT_NE(0U, baselineHash);
  EXPECT_EQ(baselineHash,
            directional::bench::benchmark_output_semantic_hash(permuted));
  EXPECT_NE(directional::bench::benchmark_output_structural_hash(baseline),
            directional::bench::benchmark_output_structural_hash(permuted));
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestDetectsConnectivityMutation) {
  const auto baseline = semantic_two_component_result();
  auto mutation = baseline;
  std::swap(mutation.product().faces(0, 3),
            mutation.product().faces(1, 3));
  EXPECT_NE(directional::bench::benchmark_output_semantic_hash(baseline),
            directional::bench::benchmark_output_semantic_hash(mutation));
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestDetectsWindingMutation) {
  const auto baseline = semantic_two_component_result();
  auto mutation = baseline;
  std::swap(mutation.product().faces(0, 1),
            mutation.product().faces(0, 3));
  EXPECT_NE(directional::bench::benchmark_output_semantic_hash(baseline),
            directional::bench::benchmark_output_semantic_hash(mutation));
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestDetectsSourceSupportMutation) {
  const auto baseline = semantic_two_component_result();
  auto mutation = baseline;
  mutation.product().outputVertexLineage.front().sourceSupport =
      test_source_vertex_support(1);
  EXPECT_NE(directional::bench::benchmark_output_semantic_hash(baseline),
            directional::bench::benchmark_output_semantic_hash(mutation));
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestDetectsComponentSeparationMutation) {
  const auto baseline = semantic_two_component_result();
  auto mutation = baseline;
  for (std::size_t vertex = 4;
       vertex < mutation.product().outputVertexLineage.size(); ++vertex) {
    auto &lineage = mutation.product().outputVertexLineage[vertex];
    lineage.sourcePoint.component = 0;
    lineage.sourcePoint.sheet = 0;
    lineage.sourceTopologyRegions = {test_topology_region_id(0)};
    lineage.sourceIsolationSheets = {test_isolation_sheet_id(0)};
    lineage.sourceCharts = {test_projection_chart(0, 0)};
  }
  EXPECT_NE(directional::bench::benchmark_output_semantic_hash(baseline),
            directional::bench::benchmark_output_semantic_hash(mutation));
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestDetectsLineageMutation) {
  const auto baseline = semantic_two_component_result();
  auto mutation = baseline;
  directional::geometry::PureQuadEquivalenceProvenance equivalence;
  equivalence.kind =
      directional::geometry::PureQuadEquivalenceKind::PeriodicHolonomy;
  equivalence.firstFrontEdge = 3;
  equivalence.secondFrontEdge = 7;
  equivalence.action = {directional::authority::QuarterTurn::from_integer(1),
                        {2, -1}};
  equivalence.route = test_interior_route(0, 1, 0);
  equivalence.cutRoute = test_interior_route(1, 2, 1);
  const auto relationId = directional::authority::periodic_relation_id(
      test_topology_region_id(0), equivalence.route, equivalence.cutRoute);
  ASSERT_TRUE(relationId);
  equivalence.periodicRelation = relationId.value();
  mutation.product().outputVertexLineage.front().equivalences.push_back(
      equivalence);
  EXPECT_NE(directional::bench::benchmark_output_semantic_hash(baseline),
            directional::bench::benchmark_output_semantic_hash(mutation));
}


TEST(SurfaceCellTypedTransportAuthority,
     ValidHardRailRouteUsesTypedIdentity) {
  const auto &fixture = hard_rail_fixture();
  const int hardRail = first_edge_of_kind(fixture.network.phaseFront,
                                          SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  const auto &edge =
      fixture.network.phaseFront.product().edges()[static_cast<std::size_t>(hardRail)];
  ASSERT_TRUE(route_is_all_interior(edge.route));

  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceTransitions = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  for (const auto &step : edge.route.steps()) {
    ASSERT_TRUE(step.interior().has_value());
    const auto expected = sourceTransitions.find(step.topology());
    ASSERT_NE(sourceTransitions.end(), expected);
    EXPECT_EQ(static_cast<std::size_t>(expected->second),
              step.interior()->index());
  }

  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(1, result.connectedComponents);
}

TEST(SurfaceCellTypedTransportAuthority,
     ValidPeriodicCutRouteUsesTypedIdentity) {
  const auto &fixture = cylinder_fixture();
  const int periodic = first_edge_of_kind(fixture.network.phaseFront,
                                          SurfaceFrontBoundaryKind::PeriodicCut);
  ASSERT_GE(periodic, 0);
  const auto &edge =
      fixture.network.phaseFront.product().edges()[static_cast<std::size_t>(periodic)];
  ASSERT_TRUE(route_is_all_interior(edge.route));
  ASSERT_TRUE(edge.periodicRelation.has_value());
  const auto owner = std::find_if(
      fixture.network.phaseFront.product().periodicHolonomies().begin(),
      fixture.network.phaseFront.product().periodicHolonomies().end(),
      [&](const auto &relation) {
        return relation.id() == *edge.periodicRelation;
      });
  ASSERT_NE(fixture.network.phaseFront.product().periodicHolonomies().end(),
            owner);
  EXPECT_EQ(edge.sourceTopologyRegion, owner->sourceTopologyRegion());

  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(fixture.network.phaseFront.product().periodicHolonomies().size(),
            result.consumedPeriodicHolonomies);
}

TEST(SurfaceCellTypedTransportAuthority,
     MissingInteriorTransitionIsRejectedByTypedFactory) {
  constexpr std::size_t vertexExtent = 9U;
  const auto first = directional::authority::SourceVertexId::from_index(
      1, vertexExtent);
  const auto second = directional::authority::SourceVertexId::from_index(
      4, vertexExtent);
  ASSERT_TRUE(first);
  ASSERT_TRUE(second);
  const auto topology = directional::authority::SourceEdgeTopologyKey::make(
      first.value(), second.value());
  ASSERT_TRUE(topology);
  const auto invalid = directional::authority::TransitionStep::interior(
      topology.value(), std::nullopt,
      directional::authority::GridAutomorphism::identity(),
      directional::authority::Orientation::Forward);
  ASSERT_FALSE(invalid);
  EXPECT_EQ(directional::authority::DomainErrorCode::MissingInteriorTransition,
            invalid.error().code);
}

TEST(SurfaceCellTransitionQuotient,
     MaterializedCompletionHashIgnoresRawProjectionLabels) {
  const auto &fixture = split_isolation_fixture();
  const auto materialized = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(materialized.success) << materialized.failure;

  auto tampered = materialized.mesh;
  for (auto &point : tampered.vertexProvenance) {
    point.component = 401;
    point.sheet = 402;
  }
  for (auto &lineage : tampered.vertexLineage) {
    lineage.sourcePoint.component = 403;
    lineage.sourcePoint.sheet = 404;
    lineage.featureInterval.start.component = 405;
    lineage.featureInterval.start.sheet = 406;
    lineage.featureInterval.end.component = 407;
    lineage.featureInterval.end.sheet = 408;
  }

  EXPECT_EQ(directional::pipeline::hash_completion(materialized.mesh),
            directional::pipeline::hash_completion(tampered));
}


TEST(SurfaceCellTransitionQuotient,
     ComponentTypedAuthorityDomainComesFromPublishedSourceAuthority) {
  const auto &fixture = split_isolation_fixture();
  const auto components = directional::geometry::compact_face_components(
      fixture.mesh.V, fixture.mesh.F, nullptr);
  ASSERT_EQ(1U, components.size());
  const auto &sourceAuthority =
      fixture.network.phaseFront.product().sourceTopologyRegions();

  const auto domain = directional::pipeline::
      make_component_typed_authority_remap_domain(
          components.front(), sourceAuthority,
          directional::geometry::empty_hard_feature_edges(), 7U, 11U, 13U);
  ASSERT_TRUE(domain.has_value());
  EXPECT_TRUE(domain->complete());
  EXPECT_EQ(7U + sourceAuthority.regions().size(),
            domain->nextTopologyRegion);
  EXPECT_GT(domain->nextIsolationSheet, 11U);
  EXPECT_GT(domain->nextFieldChart, 13U);
  ASSERT_EQ(static_cast<std::size_t>(fixture.mesh.F.rows()),
            domain->localChartsByFace.size());

  const auto materialized = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(materialized.success) << materialized.failure;
  ASSERT_FALSE(materialized.mesh.vertexLineage.empty());
  auto lineage = materialized.mesh.vertexLineage.front();
  ASSERT_TRUE(directional::pipeline::remap_component_typed_lineage_authority(
      lineage, components.front(),
      static_cast<std::size_t>(fixture.mesh.V.rows()),
      static_cast<std::size_t>(fixture.mesh.F.rows()), domain.value()));
  for (const auto region : lineage.sourceTopologyRegions) {
    EXPECT_TRUE(std::any_of(
        domain->topologyRegions.begin(), domain->topologyRegions.end(),
        [&](const auto &entry) { return entry.second == region; }));
  }
  for (const auto sheet : lineage.sourceIsolationSheets) {
    EXPECT_TRUE(std::any_of(
        domain->isolationSheets.begin(), domain->isolationSheets.end(),
        [&](const auto &entry) { return entry.second == sheet; }));
  }
  for (const auto &chart : lineage.sourceCharts) {
    EXPECT_TRUE(std::any_of(
        domain->fieldCharts.begin(), domain->fieldCharts.end(),
        [&](const auto &entry) { return entry.second == chart.chart; }));
  }
}

TEST(SurfaceCellTransitionQuotient,
     ComponentTypedAuthorityRemapRejectsUnownedLocalIdsAndSupport) {
  const auto &fixture = split_isolation_fixture();
  const auto components = directional::geometry::compact_face_components(
      fixture.mesh.V, fixture.mesh.F, nullptr);
  ASSERT_EQ(1U, components.size());
  const auto &sourceAuthority =
      fixture.network.phaseFront.product().sourceTopologyRegions();
  const auto domain = directional::pipeline::
      make_component_typed_authority_remap_domain(
          components.front(), sourceAuthority,
          directional::geometry::empty_hard_feature_edges(), 3U, 5U, 7U);
  ASSERT_TRUE(domain.has_value());

  directional::geometry::PureQuadVertexLineage baseline;
  baseline.sourceTopologyRegions = {domain->localRegionsByFace.front()};
  baseline.sourceIsolationSheets = {domain->localSheetsByFace.front()};
  baseline.sourceCharts = {domain->localChartsByFace.front()};
  baseline.sourceSupport =
      directional::authority::SourceFaceInteriorSupport{
          domain->localChartsByFace.front().face};

  auto valid = baseline;
  EXPECT_TRUE(directional::pipeline::remap_component_typed_lineage_authority(
      valid, components.front(),
      static_cast<std::size_t>(fixture.mesh.V.rows()),
      static_cast<std::size_t>(fixture.mesh.F.rows()), domain.value()));

  auto unownedRegion = baseline;
  const auto sparseRegion = directional::authority::TopologyRegionId::from_index(
      99, 128);
  ASSERT_TRUE(sparseRegion);
  unownedRegion.sourceTopologyRegions = {sparseRegion.value()};
  EXPECT_FALSE(directional::pipeline::remap_component_typed_lineage_authority(
      unownedRegion, components.front(),
      static_cast<std::size_t>(fixture.mesh.V.rows()),
      static_cast<std::size_t>(fixture.mesh.F.rows()), domain.value()));

  auto unownedSheet = baseline;
  const auto sparseSheet = directional::authority::IsolationSheetId::from_index(
      99, 128);
  ASSERT_TRUE(sparseSheet);
  unownedSheet.sourceIsolationSheets = {sparseSheet.value()};
  EXPECT_FALSE(directional::pipeline::remap_component_typed_lineage_authority(
      unownedSheet, components.front(),
      static_cast<std::size_t>(fixture.mesh.V.rows()),
      static_cast<std::size_t>(fixture.mesh.F.rows()), domain.value()));

  auto wrongChart = baseline;
  const auto sparseChart = directional::authority::FieldChartId::from_index(
      99, 128);
  ASSERT_TRUE(sparseChart);
  wrongChart.sourceCharts = {directional::geometry::SourceProjectionChart(
      sparseChart.value(), domain->localChartsByFace.front().face)};
  EXPECT_FALSE(directional::pipeline::remap_component_typed_lineage_authority(
      wrongChart, components.front(),
      static_cast<std::size_t>(fixture.mesh.V.rows()),
      static_cast<std::size_t>(fixture.mesh.F.rows()), domain.value()));

  if (domain->localChartsByFace.size() > 1U) {
    auto wrongFaceSupport = baseline;
    wrongFaceSupport.sourceSupport =
        directional::authority::SourceFaceInteriorSupport{
            domain->localChartsByFace[1].face};
    EXPECT_FALSE(
        directional::pipeline::remap_component_typed_lineage_authority(
            wrongFaceSupport, components.front(),
            static_cast<std::size_t>(fixture.mesh.V.rows()),
            static_cast<std::size_t>(fixture.mesh.F.rows()), domain.value()));
  }

  auto incomplete = baseline;
  incomplete.sourceSupport.reset();
  EXPECT_FALSE(directional::pipeline::remap_component_typed_lineage_authority(
      incomplete, components.front(),
      static_cast<std::size_t>(fixture.mesh.V.rows()),
      static_cast<std::size_t>(fixture.mesh.F.rows()), domain.value()));
}

TEST(SurfaceCellTransitionQuotient,
     ComponentTypedAuthorityRemapRequiresCapturedHardFeatureChartDomain) {
  Eigen::MatrixXd vertices(9, 3);
  int vertex = 0;
  for (int y = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++x) {
      vertices.row(vertex++) << static_cast<double>(x),
          static_cast<double>(y), 0.0;
    }
  }
  Eigen::MatrixXi faces(8, 3);
  int face = 0;
  for (int y = 0; y < 2; ++y) {
    for (int x = 0; x < 2; ++x) {
      const int lowerLeft = y * 3 + x;
      const int lowerRight = lowerLeft + 1;
      const int upperLeft = lowerLeft + 3;
      const int upperRight = upperLeft + 1;
      faces.row(face++) << lowerLeft, lowerRight, upperRight;
      faces.row(face++) << lowerLeft, upperRight, upperLeft;
    }
  }
  directional::TriMesh mesh;
  mesh.set_mesh(vertices, faces);
  const auto components = directional::geometry::compact_face_components(
      mesh.V, mesh.F, nullptr);
  ASSERT_EQ(1U, components.size());
  const auto &component = components.front();
  ASSERT_EQ(9U, component.originalVertices.size());

  std::array<int, 9> localVertexByOriginal;
  localVertexByOriginal.fill(-1);
  for (std::size_t localVertex = 0;
       localVertex < component.originalVertices.size(); ++localVertex) {
    const int originalVertex = component.originalVertices[localVertex];
    ASSERT_GE(originalVertex, 0);
    ASSERT_LT(originalVertex, static_cast<int>(localVertexByOriginal.size()));
    localVertexByOriginal[static_cast<std::size_t>(originalVertex)] =
        static_cast<int>(localVertex);
  }
  ASSERT_GE(localVertexByOriginal[1], 0);
  ASSERT_GE(localVertexByOriginal[4], 0);
  ASSERT_GE(localVertexByOriginal[7], 0);

  const std::set<directional::authority::SourceEdgeTopologyKey> localHardFeatureEdges = {
      test_source_edge_topology(
          localVertexByOriginal[1], localVertexByOriginal[4],
          component.originalVertices.size()),
      test_source_edge_topology(
          localVertexByOriginal[4], localVertexByOriginal[7],
          component.originalVertices.size()),
  };
  ASSERT_EQ(2U, localHardFeatureEdges.size());

  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents.assign(
      static_cast<std::size_t>(component.faces.rows()), 0);
  options.sourceFaceSheets.assign(
      static_cast<std::size_t>(component.faces.rows()), 0);
  options.hardFeatureEdges = localHardFeatureEdges;
  const auto sourceAuthority = directional::geometry::
      surface_cell_tracing_detail::build_source_topology_regions(component.faces, options);
  ASSERT_TRUE(sourceAuthority.has_value());
  ASSERT_TRUE(sourceAuthority->matches_source_faces(component.faces, component.originalVertices.size()))
      << "direct remap witness authority must match compact component topology";
  ASSERT_EQ(2U, sourceAuthority->regions().size())
      << "direct remap witness requires two HardRail-separated topology regions";
  std::set<directional::authority::IsolationSheetId> sourceSheetIds;
  for (const auto &region : sourceAuthority->regions()) {
    for (const auto &ownedFace : region.faces()) {
      sourceSheetIds.insert(ownedFace.sheet);
    }
  }
  ASSERT_EQ(1U, sourceSheetIds.size())
      << "direct remap witness requires exactly one isolation sheet";

  const auto hardAwareDomain = directional::pipeline::
      make_component_typed_authority_remap_domain(
          component, sourceAuthority.value(), localHardFeatureEdges,
          3U, 5U, 7U);
  const auto barrierlessDomain = directional::pipeline::
      make_component_typed_authority_remap_domain(
          component, sourceAuthority.value(),
          directional::geometry::empty_hard_feature_edges(),
          3U, 5U, 7U);
  ASSERT_TRUE(hardAwareDomain.has_value());
  ASSERT_TRUE(barrierlessDomain.has_value());

  std::size_t witnessFace = hardAwareDomain->localChartsByFace.size();
  for (std::size_t sourceFace = 0;
       sourceFace < hardAwareDomain->localChartsByFace.size();
       ++sourceFace) {
    if (hardAwareDomain->localChartsByFace[sourceFace] !=
        barrierlessDomain->localChartsByFace[sourceFace]) {
      witnessFace = sourceFace;
      break;
    }
  }
  ASSERT_LT(witnessFace, hardAwareDomain->localChartsByFace.size())
      << "direct HardRail source authority must expose barrier-sensitive canonical charts";

  directional::geometry::PureQuadVertexLineage lineage;
  lineage.sourceTopologyRegions = {
      hardAwareDomain->localRegionsByFace[witnessFace]};
  lineage.sourceIsolationSheets = {
      hardAwareDomain->localSheetsByFace[witnessFace]};
  lineage.sourceCharts = {
      hardAwareDomain->localChartsByFace[witnessFace]};
  lineage.sourceSupport =
      directional::authority::SourceFaceInteriorSupport{
          hardAwareDomain->localChartsByFace[witnessFace].face};

  auto valid = lineage;
  EXPECT_TRUE(directional::pipeline::remap_component_typed_lineage_authority(
      valid, component,
      static_cast<std::size_t>(mesh.V.rows()),
      static_cast<std::size_t>(mesh.F.rows()), hardAwareDomain.value()));

  auto barrierless = lineage;
  EXPECT_FALSE(directional::pipeline::remap_component_typed_lineage_authority(
      barrierless, component,
      static_cast<std::size_t>(mesh.V.rows()),
      static_cast<std::size_t>(mesh.F.rows()), barrierlessDomain.value()));
}

TEST(SurfaceCellTypedTransportAuthority,
     OutOfDomainSourceVertexIsRejectedAtIngress) {
  constexpr std::size_t vertexExtent = 9U;
  const auto invalid = directional::authority::SourceVertexId::from_index(
      static_cast<std::int64_t>(vertexExtent), vertexExtent);
  ASSERT_FALSE(invalid);
  EXPECT_EQ(directional::authority::DomainErrorCode::IndexOutOfRange,
            invalid.error().code);
}

TEST(SurfaceCellTypedTransportAuthority,
     RouteTopologyTransitionMismatchFailsClosed) {
  const auto &fixture = hard_rail_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_TRUE(route_is_all_interior(edge.route));

  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceTransitions = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  const int current = static_cast<int>(edge.route.steps().front().interior()->index());
  int alternate = -1;
  for (const auto &[topology, compact] : sourceTransitions) {
    (void)topology;
    if (compact != current) {
      alternate = compact;
      break;
    }
  }
  ASSERT_GE(alternate, 0)
      << "hard-rail fixture must expose two valid compact transitions";
  const auto alternateId = directional::authority::InteriorTransitionId::from_index(
      alternate, sourceTransitions.size());
  ASSERT_TRUE(alternateId);
  std::vector<directional::authority::TransitionStep> steps(
      edge.route.steps().begin(), edge.route.steps().end());
  const auto replacement = directional::authority::TransitionStep::interior(
      steps.front().topology(), alternateId.value(), steps.front().transport(),
      steps.front().orientation());
  ASSERT_TRUE(replacement);
  steps.front() = replacement.value();
  edge.route = directional::authority::CanonicalRoute::from_observed_steps(
      std::move(steps));

  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidHardRailAuthority", result.failure);
}

TEST(SurfaceCellTypedTransportAuthority,
     DuplicateSemanticRouteTopologyFailsClosed) {
  const auto &fixture = hard_rail_fixture();
  PhaseFrontDraft tampered = phase_front_draft(fixture.network.phaseFront);
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.edges[static_cast<std::size_t>(hardRail)];
  ASSERT_TRUE(route_is_all_interior(edge.route));
  std::vector<directional::authority::TransitionStep> steps(
      edge.route.steps().begin(), edge.route.steps().end());
  steps.push_back(steps.front());
  edge.route = directional::authority::CanonicalRoute::from_observed_steps(
      std::move(steps));

  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidHardRailAuthority", result.failure);
}


bool same_materializer_state(
    const directional::geometry::LocalLatticeState &left,
    const directional::geometry::LocalLatticeState &right) {
  const auto &[leftPhase, leftCoordinate, leftBranch, leftScale, leftChart] = left;
  const auto &[rightPhase, rightCoordinate, rightBranch, rightScale, rightChart] = right;
  return leftCoordinate == rightCoordinate && leftBranch == rightBranch &&
         leftScale == rightScale && leftChart == rightChart &&
         (leftPhase - rightPhase).norm() <= 1.0e-12;
}

bool action_has_nonzero_turn(
    const directional::authority::GridAutomorphism &action) {
  const auto [turn, shift] = action;
  (void)shift;
  return turn != decltype(turn){};
}

directional::authority::GridAutomorphism action_with_nonzero_turn(
    const directional::authority::GridAutomorphism &action) {
  auto [turn, shift] = action;
  turn = decltype(turn)::from_integer(1);
  return {turn, shift};
}

int action_turn_step(const directional::authority::GridAutomorphism &action) {
  const auto origin = action.apply({0, 0});
  const auto basis = action.apply({1, 0}) - origin;
  if (basis == directional::authority::LatticeTranslation{1, 0}) return 0;
  if (basis == directional::authority::LatticeTranslation{0, 1}) return 1;
  if (basis == directional::authority::LatticeTranslation{-1, 0}) return 2;
  if (basis == directional::authority::LatticeTranslation{0, -1}) return 3;
  throw std::runtime_error("Invalid direct materializer action basis.");
}

directional::geometry::LocalLatticeState apply_materializer_action(
    const directional::geometry::LocalLatticeState &source,
    const directional::geometry::LocalLatticeState &targetTemplate,
    const directional::authority::GridAutomorphism &action) {
  const auto &[sourcePhase, sourceCoordinate, sourceBranch, sourceScale,
               sourceChart] = source;
  const auto &[targetPhase, targetCoordinate, targetBranch, targetScale,
               targetChart] = targetTemplate;
  (void)sourcePhase;
  (void)sourceChart;
  (void)targetCoordinate;
  (void)targetBranch;
  if (sourceScale != targetScale) {
    throw std::runtime_error("Direct materializer scale precondition failed.");
  }
  int branch = sourceBranch + action_turn_step(action);
  while (branch >= 4) branch -= 4;
  while (branch < 0) branch += 4;
  return {targetPhase, action.apply(sourceCoordinate), branch, targetScale,
          targetChart};
}

struct MaterializerStateReplacement {
  directional::geometry::LocalLatticeState before;
  directional::geometry::LocalLatticeState after;
};

void add_materializer_replacement(
    std::vector<MaterializerStateReplacement> &replacements,
    const directional::geometry::LocalLatticeState &before,
    const directional::geometry::LocalLatticeState &after) {
  for (const auto &replacement : replacements) {
    if (!same_materializer_state(replacement.before, before)) continue;
    if (!same_materializer_state(replacement.after, after)) {
      throw std::runtime_error("Conflicting direct materializer state map.");
    }
    return;
  }
  replacements.push_back({before, after});
}

int apply_materializer_replacements(
    directional::geometry::LocalLatticeState &state,
    const std::vector<MaterializerStateReplacement> &replacements) {
  for (const auto &replacement : replacements) {
    if (!same_materializer_state(state, replacement.before)) continue;
    state = replacement.after;
    return 1;
  }
  return 0;
}

PhaseFrontDraft direct_full_periodic_materializer_draft() {
  PhaseFrontDraft draft =
      phase_front_draft(direct_materializer_base_fixture().network.phaseFront);
  std::vector<MaterializerStateReplacement> replacements;
  bool transformed = false;

  for (auto &relation : draft.periodicHolonomies) {
    const auto baselineAction = relation.action();
    const auto [turn, shift] = baselineAction;
    if (turn != decltype(turn){} || (shift.x == 0 && shift.y == 0)) continue;

    const auto action = action_with_nonzero_turn(baselineAction);
    bool paired = false;
    for (int edgeIndex = 0; edgeIndex < static_cast<int>(draft.edges.size());
         ++edgeIndex) {
      const auto &first = draft.edges[static_cast<std::size_t>(edgeIndex)];
      if (first.boundaryKind != SurfaceFrontBoundaryKind::PeriodicCut ||
          !first.periodicRelation.has_value() ||
          first.periodicRelation.value() != relation.id() ||
          first.oppositeEdge <= edgeIndex) {
        continue;
      }
      if (first.oppositeEdge < 0 ||
          first.oppositeEdge >= static_cast<int>(draft.edges.size())) {
        throw std::runtime_error("Invalid direct materializer opposite edge.");
      }
      const auto &second =
          draft.edges[static_cast<std::size_t>(first.oppositeEdge)];
      if (second.oppositeEdge != edgeIndex ||
          second.boundaryKind != SurfaceFrontBoundaryKind::PeriodicCut ||
          second.periodicRelation != first.periodicRelation) {
        throw std::runtime_error("Invalid direct materializer pair authority.");
      }
      add_materializer_replacement(
          replacements, second.fromLattice,
          apply_materializer_action(first.toLattice, second.fromLattice, action));
      add_materializer_replacement(
          replacements, second.toLattice,
          apply_materializer_action(first.fromLattice, second.toLattice, action));
      paired = true;
    }
    if (!paired) {
      throw std::runtime_error("Direct materializer relation has no owned pair.");
    }

    auto rebuilt = directional::geometry::SurfacePeriodicHolonomy::make(
        relation.sourceTopologyRegion(), action, relation.route(),
        relation.cutRoute());
    auto *value =
        std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&rebuilt);
    if (value == nullptr) {
      throw std::runtime_error("Direct materializer relation factory rejected.");
    }
    relation = std::move(*value);
    transformed = true;
    break;
  }

  if (!transformed || replacements.empty()) {
    throw std::runtime_error("No direct materializer transform candidate.");
  }

  int rewritten = 0;
  for (auto &cell : draft.cells) {
    for (auto &state : cell.lattice) {
      rewritten += apply_materializer_replacements(state, replacements);
    }
  }
  for (auto &edge : draft.edges) {
    rewritten += apply_materializer_replacements(edge.fromLattice, replacements);
    rewritten += apply_materializer_replacements(edge.toLattice, replacements);
  }
  if (rewritten == 0) {
    throw std::runtime_error("Direct materializer state map was unreachable.");
  }

  auto construction = construct_phase_front_product(std::move(draft));
  auto *product = std::get_if<directional::geometry::SurfacePhaseFrontProduct>(
      &construction);
  if (product == nullptr) {
    throw std::runtime_error("Direct materializer authority factory rejected.");
  }
  return phase_front_draft(*product);
}


TEST(M6CP1, A7CrossSheetBindingRequiresConnectingIsolationTransition) {
  const auto &fixture = split_isolation_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F,
          fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &a6Construction);
  ASSERT_NE(a6, nullptr);

  auto baseline =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  ASSERT_NE(std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
                &baseline),
            nullptr);

  auto cells = a5->cells();
  auto occurrences = a5->occurrences();
  auto relations = a5->owned_relations();
  const auto bridge = std::find_if(
      occurrences.begin(), occurrences.end(), [](const auto &occurrence) {
        return occurrence.cornerWedgeSheets.size() > 1U;
      });
  ASSERT_NE(bridge, occurrences.end())
      << "split-isolation witness must contain a bridge occurrence";
  ASSERT_FALSE(bridge->cornerWedgeIsolation.empty());

  const auto unrelatedFirst = test_isolation_sheet_id(99);
  const auto unrelatedSecond = test_isolation_sheet_id(100);
  ASSERT_NE(unrelatedFirst, unrelatedSecond);
  for (auto &transition : bridge->cornerWedgeIsolation) {
    transition.fromSheet = unrelatedFirst;
    transition.toSheet = unrelatedSecond;
  }

  auto tampered = directional::pipeline::SurfaceOccurrenceComplexProducer::
      publish_records_for_validation(std::move(cells), std::move(occurrences),
                                     std::move(relations));
  const auto *tamperedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&tampered);
  ASSERT_NE(tamperedA5, nullptr);
  auto tamperedA6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*tamperedA5);
  const auto *tamperedA6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &tamperedA6Construction);
  ASSERT_NE(tamperedA6, nullptr);

  auto rejected =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *tamperedA5, *tamperedA6);
  const auto *failure =
      std::get_if<directional::pipeline::GeometryEmbeddingFailure>(&rejected);
  ASSERT_NE(failure, nullptr);
  EXPECT_EQ(failure->code,
            directional::pipeline::GeometryEmbeddingFailureCode::
                UncertifiedCrossSheetBinding);
  EXPECT_EQ(failure->site, "cross-sheet:wedge");
}


struct M6CP2VerificationFixture {
  const PhaseFrontFixture *fixture = nullptr;
  directional::pipeline::SurfaceOccurrenceVerificationRecords a5;
  directional::pipeline::SurfaceQuotientVerificationRecords a6;
  directional::pipeline::SourceAttachedGeometryVerificationRecords a7;
};

M6CP2VerificationFixture make_m6cp2_verification_fixture(
    const PhaseFrontFixture &fixture) {
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  if (a5 == nullptr) throw std::runtime_error("M6 CP2 A5 fixture failed.");
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &a6Construction);
  if (a6 == nullptr) throw std::runtime_error("M6 CP2 A6 fixture failed.");
  auto a7Construction =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  const auto *a7 =
      std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
          &a7Construction);
  if (a7 == nullptr) throw std::runtime_error("M6 CP2 A7 fixture failed.");
  return {&fixture, a5->verification_records(), a6->verification_records(),
          a7->verification_records()};
}

directional::pipeline::VerificationReport verify_m6cp2_records(
    const M6CP2VerificationFixture &records) {
  static const std::set<directional::authority::SourceEdgeTopologyKey>
      noHardFeatures;
  return directional::pipeline::SurfaceProductVerifier::verify_records(
      records.fixture->mesh.V, records.fixture->mesh.F,
      records.fixture->network.phaseFront.product().sourceTopologyRegions(),
      noHardFeatures, records.a5, records.a6, records.a7);
}

bool has_m6cp2_finding(
    const directional::pipeline::VerificationReport &report,
    const directional::pipeline::VerificationFailureCode code,
    const std::string &site = {}) {
  return std::any_of(report.findings.begin(), report.findings.end(),
                     [&](const auto &finding) {
                       return finding.code == code &&
                              (site.empty() || finding.locus.site == site);
                     });
}

template <typename A5>
concept M6CP2VerifierAcceptsA5 = requires(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const directional::geometry::SourceTopologyRegions &sourceAuthority,
    const std::set<directional::authority::SourceEdgeTopologyKey> &features,
    const A5 &a5, const directional::pipeline::SurfaceQuotientProduct &a6,
    const directional::pipeline::SourceAttachedGeometryProduct &a7) {
  directional::pipeline::SurfaceProductVerifier::verify(
      vertices, faces, sourceAuthority, features, a5, a6, a7);
};

template <typename Product>
concept M6CP2ProjectionAccepts = requires(const Product &product) {
  directional::pipeline::project_verified_surface_products(product);
};

template <typename Signature>
concept M6CP2VerifierHasRecordSignature = requires {
  static_cast<Signature>(
      &directional::pipeline::SurfaceProductVerifier::verify_records);
};

using M6CP2MutableRecordVerifier =
    directional::pipeline::VerificationReport (*)(
        Eigen::MatrixXd &, Eigen::MatrixXi &,
        directional::geometry::SourceTopologyRegions &,
        std::set<directional::authority::SourceEdgeTopologyKey> &,
        directional::pipeline::SurfaceOccurrenceVerificationRecords &,
        directional::pipeline::SurfaceQuotientVerificationRecords &,
        directional::pipeline::SourceAttachedGeometryVerificationRecords &);

static_assert(!M6CP2VerifierHasRecordSignature<M6CP2MutableRecordVerifier>);

static_assert(M6CP2ProjectionAccepts<
              directional::pipeline::VerifiedSurfaceProducts>);
static_assert(!M6CP2ProjectionAccepts<
              directional::pipeline::SurfaceOccurrenceComplex>);
static_assert(!M6CP2ProjectionAccepts<
              directional::pipeline::SurfaceQuotientProduct>);
static_assert(!M6CP2ProjectionAccepts<
              directional::pipeline::SourceAttachedGeometryProduct>);
static_assert(!M6CP2VerifierAcceptsA5<
              directional::pipeline::SurfaceOccurrenceComplexError>);

TEST(M6CP2, VerificationReportUsesSemanticFindingOrderAndIsPermutationInvariant) {
  auto records = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(records.a5.cells.empty());
  auto &cell = records.a5.cells.front();
  cell.directedSides[0] = {cell.cornerOccurrences[0], cell.cornerOccurrences[2]};
  const auto baseline = verify_m6cp2_records(records);
  ASSERT_FALSE(baseline.verified());
  ASSERT_TRUE(has_m6cp2_finding(
      baseline,
      directional::pipeline::VerificationFailureCode::DirectedSideCycleMismatch));

  auto reordered = records;
  std::reverse(reordered.a5.cells.begin(), reordered.a5.cells.end());
  std::reverse(reordered.a5.occurrences.begin(), reordered.a5.occurrences.end());
  std::reverse(reordered.a5.ownedRelations.begin(), reordered.a5.ownedRelations.end());
  std::reverse(reordered.a6.records.relationCertificates.begin(),
               reordered.a6.records.relationCertificates.end());
  std::reverse(reordered.a6.records.relationConsumptions.begin(),
               reordered.a6.records.relationConsumptions.end());
  std::reverse(reordered.a6.records.selectedForest.begin(),
               reordered.a6.records.selectedForest.end());
  std::reverse(reordered.a6.records.selectedPaths.begin(),
               reordered.a6.records.selectedPaths.end());
  std::reverse(reordered.a6.records.classes.begin(),
               reordered.a6.records.classes.end());
  std::reverse(reordered.a6.records.classedCells.begin(),
               reordered.a6.records.classedCells.end());
  std::reverse(reordered.a7.vertices.begin(), reordered.a7.vertices.end());
  std::reverse(reordered.a7.topology.begin(), reordered.a7.topology.end());
  std::reverse(reordered.a7.sourceSupportCertificates.begin(),
               reordered.a7.sourceSupportCertificates.end());
  EXPECT_EQ(baseline.findings, verify_m6cp2_records(reordered).findings);
}

TEST(M6CP2, VerifierRecomputesA0AndA5ElementaryIncidenceIndependently) {
  auto records = make_m6cp2_verification_fixture(split_isolation_fixture());
  ASSERT_TRUE(verify_m6cp2_records(records).verified());
  auto occurrence = std::find_if(
      records.a5.occurrences.begin(), records.a5.occurrences.end(),
      [](const auto &value) { return !value.cornerWedgeBindings.empty(); });
  ASSERT_NE(occurrence, records.a5.occurrences.end());
  occurrence->cornerWedgeBindings.front().sheet = test_isolation_sheet_id(1000);
  const auto report = verify_m6cp2_records(records);
  EXPECT_TRUE(has_m6cp2_finding(
      report, directional::pipeline::VerificationFailureCode::SourceIncidenceMismatch,
      "a5:wedge-bindings"));

  auto supportMismatch = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_GE(supportMismatch.a5.occurrences.size(), 2U);
  auto firstSupport = supportMismatch.a5.occurrences.begin();
  auto secondSupport = std::find_if(
      std::next(firstSupport), supportMismatch.a5.occurrences.end(),
      [&](const auto &candidate) { return candidate.support != firstSupport->support; });
  ASSERT_NE(secondSupport, supportMismatch.a5.occurrences.end());
  firstSupport->support = secondSupport->support;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(supportMismatch),
      directional::pipeline::VerificationFailureCode::SourceSupportIncidenceMismatch,
      "a5:support-resolver"));

  auto sourceMismatch = make_m6cp2_verification_fixture(square_fixture());
  Eigen::MatrixXi faces = sourceMismatch.fixture->mesh.F;
  faces(0, 2) = 3;
  ASSERT_FALSE(sourceMismatch.fixture->network.phaseFront.product()
                   .sourceTopologyRegions()
                   .matches_source_faces(
                       faces,
                       static_cast<std::size_t>(sourceMismatch.fixture->mesh.V.rows())));
  static const std::set<directional::authority::SourceEdgeTopologyKey> noHardFeatures;
  const auto a0Report = directional::pipeline::SurfaceProductVerifier::verify_records(
      sourceMismatch.fixture->mesh.V, faces,
      sourceMismatch.fixture->network.phaseFront.product().sourceTopologyRegions(),
      noHardFeatures, sourceMismatch.a5, sourceMismatch.a6, sourceMismatch.a7);
  EXPECT_TRUE(has_m6cp2_finding(
      a0Report,
      directional::pipeline::VerificationFailureCode::SourceIncidenceMismatch,
      "a0:source-faces"));

  auto hardFeature = make_m6cp2_verification_fixture(square_fixture());
  const std::set<directional::authority::SourceEdgeTopologyKey> invalidHardFeature{
      test_source_edge_topology(1, 3,
          static_cast<std::size_t>(hardFeature.fixture->mesh.V.rows()))};
  const auto hardFeatureReport =
      directional::pipeline::SurfaceProductVerifier::verify_records(
          hardFeature.fixture->mesh.V, hardFeature.fixture->mesh.F,
          hardFeature.fixture->network.phaseFront.product().sourceTopologyRegions(),
          invalidHardFeature, hardFeature.a5, hardFeature.a6, hardFeature.a7);
  EXPECT_TRUE(has_m6cp2_finding(
      hardFeatureReport,
      directional::pipeline::VerificationFailureCode::SourceIncidenceMismatch,
      "a0:hard-feature-edge"));

  auto duplicateOwner = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(duplicateOwner.a5.cells.empty());
  const auto ownerBefore = duplicateOwner.a5.cells.front().cornerOccurrences[1];
  duplicateOwner.a5.cells.front().cornerOccurrences[1] =
      duplicateOwner.a5.cells.front().cornerOccurrences[0];
  ASSERT_NE(ownerBefore, duplicateOwner.a5.cells.front().cornerOccurrences[1]);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(duplicateOwner),
      directional::pipeline::VerificationFailureCode::OccurrenceOwnershipMismatch,
      "a5:corner-owner"));

  auto sideCycle = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(sideCycle.a5.cells.empty());
  const auto sideBefore = sideCycle.a5.cells.front().directedSides[0];
  std::swap(sideCycle.a5.cells.front().directedSides[0].first,
            sideCycle.a5.cells.front().directedSides[0].second);
  ASSERT_NE(sideBefore, sideCycle.a5.cells.front().directedSides[0]);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(sideCycle),
      directional::pipeline::VerificationFailureCode::DirectedSideCycleMismatch,
      "a5:directed-side-cycle"));

  auto isolation = make_m6cp2_verification_fixture(split_isolation_fixture());
  auto isolatedOccurrence = std::find_if(
      isolation.a5.occurrences.begin(), isolation.a5.occurrences.end(),
      [](const auto &candidate) { return !candidate.cornerWedgeIsolation.empty(); });
  ASSERT_NE(isolatedOccurrence, isolation.a5.occurrences.end());
  const auto seamBefore = isolatedOccurrence->cornerWedgeIsolation.front().seam;
  bool replacedSeam = false;
  for (int face = 0; face < isolation.fixture->mesh.F.rows() && !replacedSeam; ++face) {
    for (int side = 0; side < 3 && !replacedSeam; ++side) {
      const auto candidate = test_source_edge_topology(
          isolation.fixture->mesh.F(face, side),
          isolation.fixture->mesh.F(face, (side + 1) % 3),
          static_cast<std::size_t>(isolation.fixture->mesh.V.rows()));
      const auto &region = isolation.fixture->network.phaseFront.product()
                               .sourceTopologyRegions()
                               .region(isolatedOccurrence->topologyRegion);
      if (candidate != seamBefore &&
          std::find(region.isolation_seams().begin(), region.isolation_seams().end(),
                    candidate) == region.isolation_seams().end()) {
        isolatedOccurrence->cornerWedgeIsolation.front().seam = candidate;
        replacedSeam = true;
      }
    }
  }
  ASSERT_TRUE(replacedSeam);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(isolation),
      directional::pipeline::VerificationFailureCode::SourceIncidenceMismatch,
      "a5:wedge-isolation"));
}

TEST(M6CP2, VerifierRecomputesA6TopologyAndMembershipIndependently) {
  auto records = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_TRUE(verify_m6cp2_records(records).verified());
  ASSERT_FALSE(records.a6.records.classedCells.empty());
  records.a6.records.classedCells.front().corners[0] =
      records.a6.records.classedCells.front().corners[1];
  const auto report = verify_m6cp2_records(records);
  EXPECT_TRUE(has_m6cp2_finding(
      report,
      directional::pipeline::VerificationFailureCode::QuadIncidenceMismatch));
  EXPECT_TRUE(has_m6cp2_finding(
      report,
      directional::pipeline::VerificationFailureCode::QuotientMembershipMismatch));

  auto splitRecords = make_m6cp2_verification_fixture(overlap_fixture());
  ASSERT_TRUE(verify_m6cp2_records(splitRecords).verified());
  auto joining = std::find_if(
      splitRecords.a6.records.relationConsumptions.begin(),
      splitRecords.a6.records.relationConsumptions.end(), [](const auto &row) {
        return row.disposition ==
               directional::pipeline::QuotientRelationDisposition::Joining;
      });
  ASSERT_NE(joining, splitRecords.a6.records.relationConsumptions.end());
  auto firstClass = std::find_if(
      splitRecords.a6.records.classes.begin(), splitRecords.a6.records.classes.end(),
      [&](const auto &row) {
        return std::find(row.members.begin(), row.members.end(),
                         joining->relation.second) != row.members.end();
      });
  ASSERT_NE(firstClass, splitRecords.a6.records.classes.end());
  auto otherClass = std::find_if(
      splitRecords.a6.records.classes.begin(), splitRecords.a6.records.classes.end(),
      [&](const auto &row) {
        return &row != &*firstClass && !row.members.empty() &&
               std::find(row.members.begin(), row.members.end(), joining->relation.first) ==
                   row.members.end();
      });
  ASSERT_NE(otherClass, splitRecords.a6.records.classes.end());
  auto secondMember = std::find(firstClass->members.begin(), firstClass->members.end(),
                                joining->relation.second);
  ASSERT_NE(secondMember, firstClass->members.end());
  std::swap(*secondMember, otherClass->members.front());
  std::sort(firstClass->members.begin(), firstClass->members.end());
  std::sort(otherClass->members.begin(), otherClass->members.end());
  firstClass->id.members = firstClass->members;
  otherClass->id.members = otherClass->members;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(splitRecords),
      directional::pipeline::VerificationFailureCode::QuotientMembershipMismatch,
      "a6:relation-class"));

  auto missingConsumption = make_m6cp2_verification_fixture(overlap_fixture());
  ASSERT_FALSE(missingConsumption.a6.records.relationConsumptions.empty());
  missingConsumption.a6.records.relationConsumptions.pop_back();
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(missingConsumption),
      directional::pipeline::VerificationFailureCode::QuotientMembershipMismatch,
      "a6:exact-once-ledger"));

  auto duplicateCertificate = make_m6cp2_verification_fixture(overlap_fixture());
  ASSERT_FALSE(duplicateCertificate.a6.records.relationCertificates.empty());
  duplicateCertificate.a6.records.relationCertificates.push_back(
      duplicateCertificate.a6.records.relationCertificates.front());
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(duplicateCertificate),
      directional::pipeline::VerificationFailureCode::QuotientMembershipMismatch,
      "a6:duplicate-certificate"));

  auto joiningMismatch = make_m6cp2_verification_fixture(overlap_fixture());
  auto joiningConsumption = std::find_if(
      joiningMismatch.a6.records.relationConsumptions.begin(),
      joiningMismatch.a6.records.relationConsumptions.end(), [](const auto &row) {
        return row.disposition ==
               directional::pipeline::QuotientRelationDisposition::Joining;
      });
  ASSERT_NE(joiningConsumption,
            joiningMismatch.a6.records.relationConsumptions.end());
  joiningConsumption->disposition =
      directional::pipeline::QuotientRelationDisposition::CycleClosing;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(joiningMismatch),
      directional::pipeline::VerificationFailureCode::QuotientMembershipMismatch,
      "a6:forest-joining-set"));

  auto forestMismatch = make_m6cp2_verification_fixture(overlap_fixture());
  ASSERT_FALSE(forestMismatch.a6.records.selectedForest.empty());
  forestMismatch.a6.records.selectedForest.pop_back();
  const auto forestReport = verify_m6cp2_records(forestMismatch);
  EXPECT_TRUE(has_m6cp2_finding(
      forestReport,
      directional::pipeline::VerificationFailureCode::QuotientMembershipMismatch,
      "a6:forest-cardinality"));

  auto edgeManifoldness = make_m6cp2_verification_fixture(overlap_fixture());
  ASSERT_GE(edgeManifoldness.a6.records.classedCells.size(), 3U);
  using QuotientEdge = std::pair<
      directional::pipeline::SurfaceQuotientClassId,
      directional::pipeline::SurfaceQuotientClassId>;
  const auto canonicalEdge = [](auto first, auto second) {
    if (second < first) std::swap(first, second);
    return QuotientEdge{first, second};
  };
  std::map<QuotientEdge, std::vector<std::size_t>> edgeOwners;
  for (std::size_t cell = 0;
       cell < edgeManifoldness.a6.records.classedCells.size(); ++cell) {
    const auto &corners = edgeManifoldness.a6.records.classedCells[cell].corners;
    for (std::size_t side = 0; side < 4U; ++side) {
      edgeOwners[canonicalEdge(corners[side], corners[(side + 1U) % 4U])]
          .push_back(cell);
    }
  }
  const auto sharedEdge = std::find_if(
      edgeOwners.begin(), edgeOwners.end(),
      [](const auto &entry) { return entry.second.size() == 2U; });
  ASSERT_NE(sharedEdge, edgeOwners.end());
  const auto thirdCell = std::find_if(
      edgeManifoldness.a6.records.classedCells.begin(),
      edgeManifoldness.a6.records.classedCells.end(), [&](const auto &cell) {
        const auto index = static_cast<std::size_t>(
            &cell - edgeManifoldness.a6.records.classedCells.data());
        return std::find(sharedEdge->second.begin(), sharedEdge->second.end(),
                         index) == sharedEdge->second.end();
      });
  ASSERT_NE(thirdCell, edgeManifoldness.a6.records.classedCells.end());
  const auto thirdBefore = thirdCell->corners;
  thirdCell->corners[0] = sharedEdge->first.first;
  thirdCell->corners[1] = sharedEdge->first.second;
  ASSERT_NE(thirdBefore, thirdCell->corners);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(edgeManifoldness),
      directional::pipeline::VerificationFailureCode::NonManifoldTopology,
      "a6:edge-manifoldness"));

  auto componentMismatch = make_m6cp2_verification_fixture(square_fixture());
  ++componentMismatch.a7.certificate.connectedComponents;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(componentMismatch),
      directional::pipeline::VerificationFailureCode::BoundaryOrEulerMismatch,
      "a6:components"));

  auto boundaryMismatch = make_m6cp2_verification_fixture(square_fixture());
  ++boundaryMismatch.a7.certificate.boundaryLoopCount;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(boundaryMismatch),
      directional::pipeline::VerificationFailureCode::BoundaryOrEulerMismatch,
      "a6:boundary-loops"));

  auto eulerMismatch = make_m6cp2_verification_fixture(square_fixture());
  ++eulerMismatch.a7.certificate.eulerCharacteristic;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(eulerMismatch),
      directional::pipeline::VerificationFailureCode::BoundaryOrEulerMismatch,
      "a6:euler"));
}

TEST(M6CP2, VerifierRecomputesA7SupportAndCertificatePayloadsIndependently) {
  auto supportRecords = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_TRUE(verify_m6cp2_records(supportRecords).verified());
  ASSERT_FALSE(supportRecords.a7.sourceSupportCertificates.empty());
  supportRecords.a7.sourceSupportCertificates.front().members.clear();
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(supportRecords),
      directional::pipeline::VerificationFailureCode::SourceSupportIncidenceMismatch));

  auto certificateRecords = make_m6cp2_verification_fixture(square_fixture());
  ++certificateRecords.a7.certificate.embeddedVertexCount;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(certificateRecords),
      directional::pipeline::VerificationFailureCode::CertificatePayloadMismatch,
      "certificate:a7"));

  const auto expectVertexBinding = [](M6CP2VerificationFixture records) {
    const auto report = verify_m6cp2_records(records);
    EXPECT_TRUE(has_m6cp2_finding(
        report,
        directional::pipeline::VerificationFailureCode::SourceSupportIncidenceMismatch,
        "a7:vertex-binding"));
  };

  auto nonMember = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(nonMember.a7.vertices.empty());
  auto &nonMemberVertex = nonMember.a7.vertices.front();
  const auto quotientClass = std::find_if(
      nonMember.a6.records.classes.begin(), nonMember.a6.records.classes.end(),
      [&](const auto &candidate) { return candidate.id == nonMemberVertex.quotientClass; });
  ASSERT_NE(quotientClass, nonMember.a6.records.classes.end());
  const auto outsider = std::find_if(
      nonMember.a5.occurrences.begin(), nonMember.a5.occurrences.end(),
      [&](const auto &candidate) {
        return std::find(quotientClass->members.begin(), quotientClass->members.end(),
                         candidate.id) == quotientClass->members.end();
      });
  ASSERT_NE(outsider, nonMember.a5.occurrences.end());
  nonMemberVertex.representative = outsider->id;
  expectVertexBinding(std::move(nonMember));

  auto movedPoint = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(movedPoint.a7.vertices.empty());
  movedPoint.a7.vertices.front().sourcePoint.position.x() += 1.0;
  movedPoint.a7.vertices.front().position =
      movedPoint.a7.vertices.front().sourcePoint.position.transpose();
  expectVertexBinding(std::move(movedPoint));

  auto movedPosition = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(movedPosition.a7.vertices.empty());
  movedPosition.a7.vertices.front().position.x() += 1.0;
  expectVertexBinding(std::move(movedPosition));

  auto mismatchedSupport = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(mismatchedSupport.a7.vertices.empty());
  const auto alternateSupport = std::find_if(
      mismatchedSupport.a5.occurrences.begin(),
      mismatchedSupport.a5.occurrences.end(), [&](const auto &candidate) {
        return candidate.support != mismatchedSupport.a7.vertices.front().support;
      });
  ASSERT_NE(alternateSupport, mismatchedSupport.a5.occurrences.end());
  mismatchedSupport.a7.vertices.front().support = alternateSupport->support;
  expectVertexBinding(std::move(mismatchedSupport));

  auto supportCover = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(supportCover.a7.sourceSupportCertificates.empty());
  supportCover.a7.sourceSupportCertificates.pop_back();
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(supportCover),
      directional::pipeline::VerificationFailureCode::SourceSupportIncidenceMismatch,
      "a7:support-cover"));

  auto topologyCopy = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_FALSE(topologyCopy.a7.topology.empty());
  std::swap(topologyCopy.a7.topology.front().corners[0],
            topologyCopy.a7.topology.front().corners[1]);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(topologyCopy),
      directional::pipeline::VerificationFailureCode::QuadIncidenceMismatch,
      "a7:topology-copy"));

  auto a5Certificate = make_m6cp2_verification_fixture(square_fixture());
  ++a5Certificate.a5.certificate.cellCount;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(a5Certificate),
      directional::pipeline::VerificationFailureCode::CertificatePayloadMismatch,
      "certificate:a5"));

  auto a6Certificate = make_m6cp2_verification_fixture(square_fixture());
  ++a6Certificate.a6.quotientCertificate.ownedRelationCount;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(a6Certificate),
      directional::pipeline::VerificationFailureCode::CertificatePayloadMismatch,
      "certificate:a6"));
}

TEST(M6CP2, VerifierRejectsEveryForbiddenRepairClassWithoutMutation) {
  struct ForbiddenClassWitness {
    const char *name;
    void (*run)();
  };

  const std::array<ForbiddenClassWitness, 10> witnesses{{
      {"create-or-renumber-ids", [] {
         auto records = make_m6cp2_verification_fixture(square_fixture());
         ASSERT_TRUE(verify_m6cp2_records(records).verified());
         ASSERT_GE(records.a5.occurrences.size(), 2U);
         const auto original = records.a5.occurrences.front().id;
         records.a5.occurrences.front().id = records.a5.occurrences[1].id;
         ASSERT_NE(records.a5.occurrences.front().id, original);
         EXPECT_TRUE(has_m6cp2_finding(
             verify_m6cp2_records(records),
             directional::pipeline::VerificationFailureCode::
                 OccurrenceOwnershipMismatch,
             "a5:duplicate-occurrence"));
       }},
      {"union-or-replace-representative", [] {
         auto records = make_m6cp2_verification_fixture(square_fixture());
         ASSERT_TRUE(verify_m6cp2_records(records).verified());
         ASSERT_FALSE(records.a7.vertices.empty());
         auto &vertex = records.a7.vertices.front();
         const auto quotientClass = std::find_if(
             records.a6.records.classes.begin(), records.a6.records.classes.end(),
             [&](const auto &candidate) {
               return candidate.id == vertex.quotientClass;
             });
         ASSERT_NE(quotientClass, records.a6.records.classes.end());
         const auto outsider = std::find_if(
             records.a5.occurrences.begin(), records.a5.occurrences.end(),
             [&](const auto &candidate) {
               return std::find(quotientClass->members.begin(),
                                quotientClass->members.end(), candidate.id) ==
                      quotientClass->members.end();
             });
         ASSERT_NE(outsider, records.a5.occurrences.end());
         const auto representativeBefore = vertex.representative;
         vertex.representative = outsider->id;
         ASSERT_NE(vertex.representative, representativeBefore);
         EXPECT_TRUE(has_m6cp2_finding(
             verify_m6cp2_records(records),
             directional::pipeline::VerificationFailureCode::
                 SourceSupportIncidenceMismatch,
             "a7:vertex-binding"));
       }},
      {"search-or-replace-route", [] {
         auto records = make_m6cp2_verification_fixture(hard_rail_fixture());
         ASSERT_TRUE(verify_m6cp2_records(records).verified());
         auto path = std::find_if(
             records.a6.records.selectedPaths.begin(),
             records.a6.records.selectedPaths.end(), [](const auto &candidate) {
               return candidate.orderedRelations.size() >= 2U;
             });
         ASSERT_NE(path, records.a6.records.selectedPaths.end());
         const auto before = path->orderedRelations;
         std::swap(path->orderedRelations[0], path->orderedRelations[1]);
         ASSERT_NE(path->orderedRelations, before);
         EXPECT_TRUE(has_m6cp2_finding(
             verify_m6cp2_records(records),
             directional::pipeline::VerificationFailureCode::NamedTransportMismatch,
             "a6:selected-path-structure"));
       }},
      {"infer-missing-authority", [] {
         auto records = make_m6cp2_verification_fixture(overlap_fixture());
         ASSERT_TRUE(verify_m6cp2_records(records).verified());
         ASSERT_FALSE(records.a5.ownedRelations.empty());
         const auto removed = records.a5.ownedRelations.front().id;
         records.a5.ownedRelations.erase(records.a5.ownedRelations.begin());
         ASSERT_TRUE(std::none_of(
             records.a5.ownedRelations.begin(), records.a5.ownedRelations.end(),
             [&](const auto &candidate) { return candidate.id == removed; }));
         EXPECT_TRUE(has_m6cp2_finding(
             verify_m6cp2_records(records),
             directional::pipeline::VerificationFailureCode::MissingPublishedAuthority,
             "a6:a5-relation"));
       }},
      {"canonicalize-malformed-state", [] {
         auto records = make_m6cp2_verification_fixture(square_fixture());
         ASSERT_TRUE(verify_m6cp2_records(records).verified());
         ASSERT_FALSE(records.a6.records.classes.empty());
         auto &members = records.a6.records.classes.front().members;
         ASSERT_FALSE(members.empty());
         members.push_back(members.front());
         const auto malformed = records.a6.records.classes;
         const auto report = verify_m6cp2_records(records);
         EXPECT_TRUE(has_m6cp2_finding(
             report,
             directional::pipeline::VerificationFailureCode::SemanticIdentityMismatch,
             "a6:class-identity"));
         EXPECT_EQ(records.a6.records.classes, malformed)
             << "the verifier must reject, never canonicalize producer state";
       }},
      {"substitute-equivalent-or-reverse-relation", [] {
         auto records = make_m6cp2_verification_fixture(overlap_fixture());
         ASSERT_TRUE(verify_m6cp2_records(records).verified());
         ASSERT_FALSE(records.a6.records.relationCertificates.empty());
         auto &certificate = records.a6.records.relationCertificates.front();
         const auto before = certificate.relation;
         const directional::pipeline::SurfaceOccurrenceRelationId reverse{
             before.kind, before.second, before.first, before.hardRail,
             before.periodicRelation};
         ASSERT_NE(reverse, before);
         ASSERT_TRUE(std::none_of(
             records.a5.ownedRelations.begin(), records.a5.ownedRelations.end(),
             [&](const auto &candidate) { return candidate.id == reverse; }));
         certificate.relation = reverse;
         ASSERT_NE(certificate.relation, before);
         EXPECT_TRUE(has_m6cp2_finding(
             verify_m6cp2_records(records),
             directional::pipeline::VerificationFailureCode::MissingPublishedAuthority,
             "a6:a5-relation"));
       }},
      {"weld", [] {
         auto pinched = make_m6cp2_verification_fixture(overlap_fixture());
         ASSERT_TRUE(verify_m6cp2_records(pinched).verified());
         auto &cells = pinched.a6.records.classedCells;
         ASSERT_GE(cells.size(), 2U);
         bool tampered = false;
         for (std::size_t first = 0; first < cells.size() && !tampered; ++first) {
           for (std::size_t second = first + 1U;
                second < cells.size() && !tampered; ++second) {
             std::set<directional::pipeline::SurfaceQuotientClassId> firstVertices(
                 cells[first].corners.begin(), cells[first].corners.end());
             const bool disjoint = std::none_of(
                 cells[second].corners.begin(), cells[second].corners.end(),
                 [&](const auto &corner) {
                   return firstVertices.contains(corner);
                 });
             if (!disjoint) continue;
             cells[second].corners[0] = cells[first].corners[0];
             tampered = true;
           }
         }
         ASSERT_TRUE(tampered);
         EXPECT_TRUE(has_m6cp2_finding(
             verify_m6cp2_records(pinched),
             directional::pipeline::VerificationFailureCode::NonManifoldTopology,
             "a6:vertex-link"));

         auto movedPoint = make_m6cp2_verification_fixture(square_fixture());
         ASSERT_TRUE(verify_m6cp2_records(movedPoint).verified());
         ASSERT_FALSE(movedPoint.a7.vertices.empty());
         const double before =
             movedPoint.a7.vertices.front().sourcePoint.position.x();
         movedPoint.a7.vertices.front().sourcePoint.position.x() += 1.0;
         movedPoint.a7.vertices.front().position =
             movedPoint.a7.vertices.front().sourcePoint.position.transpose();
         ASSERT_NE(movedPoint.a7.vertices.front().sourcePoint.position.x(), before);
         EXPECT_TRUE(has_m6cp2_finding(
             verify_m6cp2_records(movedPoint),
             directional::pipeline::VerificationFailureCode::
                 SourceSupportIncidenceMismatch,
             "a7:vertex-binding"));
       }},
      {"repair", [] {
         auto records = make_m6cp2_verification_fixture(square_fixture());
         ASSERT_TRUE(verify_m6cp2_records(records).verified());
         ASSERT_FALSE(records.a5.cells.empty());
         const auto before = records.a5.cells.front().directedSides[0];
         std::swap(records.a5.cells.front().directedSides[0].first,
                   records.a5.cells.front().directedSides[0].second);
         ASSERT_NE(records.a5.cells.front().directedSides[0], before);
         EXPECT_TRUE(has_m6cp2_finding(
             verify_m6cp2_records(records),
             directional::pipeline::VerificationFailureCode::DirectedSideCycleMismatch,
             "a5:directed-side-cycle"));
       }},
      {"mutate-products", [] {
         EXPECT_FALSE((M6CP2VerifierHasRecordSignature<
                       M6CP2MutableRecordVerifier>));
       }},
      {"upstream-failure", [] {
         EXPECT_FALSE((M6CP2VerifierAcceptsA5<
                       directional::pipeline::SurfaceOccurrenceComplexError>));
       }},
  }};

  for (const auto &witness : witnesses) {
    SCOPED_TRACE(witness.name);
    witness.run();
  }
}

TEST(M6CP2, CertificateChainRequiresExactA5A6A7PayloadBinding) {
  auto records = make_m6cp2_verification_fixture(square_fixture());
  ASSERT_TRUE(verify_m6cp2_records(records).verified());
  ASSERT_FALSE(records.a6.records.relationCertificates.empty());
  auto &certificate = records.a6.records.relationCertificates.front();
  const auto relation = std::find_if(
      records.a5.ownedRelations.begin(), records.a5.ownedRelations.end(),
      [&](const auto &candidate) { return candidate.id == certificate.relation; });
  ASSERT_NE(relation, records.a5.ownedRelations.end());
  ASSERT_TRUE(relation->evidence.canonicalTransport.has_value());
  ASSERT_EQ(certificate.relationTransport,
            relation->evidence.canonicalTransport.value());
  certificate.relationTransport.shift.x += 1;
  ASSERT_NE(certificate.relationTransport,
            relation->evidence.canonicalTransport.value());
  const auto bindingReport = verify_m6cp2_records(records);
  EXPECT_TRUE(has_m6cp2_finding(
      bindingReport,
      directional::pipeline::VerificationFailureCode::CertificatePayloadMismatch,
      "a6:a5-binding"));

  auto a7StepRecords = make_m6cp2_verification_fixture(hard_rail_fixture());
  ASSERT_TRUE(verify_m6cp2_records(a7StepRecords).verified());
  auto a7Vertex = std::find_if(
      a7StepRecords.a7.vertices.begin(), a7StepRecords.a7.vertices.end(),
      [](const auto &vertex) {
        return std::any_of(vertex.selectedRelationPaths.begin(),
                           vertex.selectedRelationPaths.end(),
                           [](const auto &path) {
                             return !path.orderedSteps.empty();
                           });
      });
  ASSERT_NE(a7Vertex, a7StepRecords.a7.vertices.end());
  auto a7Path = std::find_if(
      a7Vertex->selectedRelationPaths.begin(), a7Vertex->selectedRelationPaths.end(),
      [](const auto &path) { return !path.orderedSteps.empty(); });
  ASSERT_NE(a7Path, a7Vertex->selectedRelationPaths.end());
  const auto a7StepBefore = a7Path->orderedSteps.front().appliedTransport;
  a7Path->orderedSteps.front().appliedTransport.shift.x += 1;
  ASSERT_NE(a7Path->orderedSteps.front().appliedTransport, a7StepBefore);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(a7StepRecords),
      directional::pipeline::VerificationFailureCode::CertificatePayloadMismatch,
      "a7:selected-paths"));

  auto a6LegacyRecords = make_m6cp2_verification_fixture(hard_rail_fixture());
  ASSERT_TRUE(verify_m6cp2_records(a6LegacyRecords).verified());
  auto a6LegacyPath = std::find_if(
      a6LegacyRecords.a6.records.selectedPaths.begin(),
      a6LegacyRecords.a6.records.selectedPaths.end(), [](const auto &path) {
        return path.legacyProjection.has_value() &&
               !path.legacyProjection->orderedSteps.empty();
      });
  ASSERT_NE(a6LegacyPath, a6LegacyRecords.a6.records.selectedPaths.end());
  const auto a6StepBefore =
      a6LegacyPath->legacyProjection->orderedSteps.front().appliedTransport;
  a6LegacyPath->legacyProjection->orderedSteps.front().appliedTransport.shift.x += 1;
  ASSERT_NE(a6LegacyPath->legacyProjection->orderedSteps.front().appliedTransport,
            a6StepBefore);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(a6LegacyRecords),
      directional::pipeline::VerificationFailureCode::CertificatePayloadMismatch,
      "a6:legacy-projection"));

  auto a5ValueRecords = make_m6cp2_verification_fixture(hard_rail_fixture());
  ASSERT_TRUE(verify_m6cp2_records(a5ValueRecords).verified());
  auto a5ValueRelation = std::find_if(
      a5ValueRecords.a5.ownedRelations.begin(),
      a5ValueRecords.a5.ownedRelations.end(), [](const auto &row) {
        return row.evidence.canonicalSelectedStep.has_value() &&
               row.evidence.canonicalRelationValue.has_value();
      });
  ASSERT_NE(a5ValueRelation, a5ValueRecords.a5.ownedRelations.end());
  const auto a5ValueBefore = a5ValueRelation->evidence.canonicalRelationValue.value();
  a5ValueRelation->evidence.canonicalRelationValue->shift.x += 1;
  ASSERT_NE(a5ValueRelation->evidence.canonicalRelationValue.value(), a5ValueBefore);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(a5ValueRecords),
      directional::pipeline::VerificationFailureCode::CertificatePayloadMismatch,
      "a5:selected-step-value"));

  auto pathRecords = make_m6cp2_verification_fixture(hard_rail_fixture());
  ASSERT_TRUE(verify_m6cp2_records(pathRecords).verified());
  auto multiStepPath = std::find_if(
      pathRecords.a6.records.selectedPaths.begin(),
      pathRecords.a6.records.selectedPaths.end(), [](const auto &path) {
        return path.orderedRelations.size() >= 2U;
      });
  ASSERT_NE(multiStepPath, pathRecords.a6.records.selectedPaths.end());
  ASSERT_EQ(multiStepPath->orderedRelations.size(),
            multiStepPath->traversalOrientations.size());
  std::swap(multiStepPath->orderedRelations[0], multiStepPath->orderedRelations[1]);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(pathRecords),
      directional::pipeline::VerificationFailureCode::NamedTransportMismatch,
      "a6:selected-path-structure"));

  auto cycleRecords = make_m6cp2_verification_fixture(square_fixture());
  auto cycle = std::find_if(
      cycleRecords.a6.records.relationConsumptions.begin(),
      cycleRecords.a6.records.relationConsumptions.end(), [](const auto &row) {
        return row.disposition ==
               directional::pipeline::QuotientRelationDisposition::CycleClosing;
      });
  ASSERT_NE(cycle, cycleRecords.a6.records.relationConsumptions.end());
  cycle->selectedPathTransport.shift.x += 1;
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(cycleRecords),
      directional::pipeline::VerificationFailureCode::NamedTransportMismatch,
      "a6:cycle-closure"));
}

TEST(M6CP2, WeldPinchedRecordViewFailsIndependentManifoldness) {
  auto records = make_m6cp2_verification_fixture(overlap_fixture());
  ASSERT_TRUE(verify_m6cp2_records(records).verified());
  const auto classesBefore = records.a6.records.classes;
  const auto forestBefore = records.a6.records.selectedForest;
  const auto consumptionsBefore = records.a6.records.relationConsumptions;
  auto &cells = records.a6.records.classedCells;
  ASSERT_GE(cells.size(), 2U);
  bool tampered = false;
  for (std::size_t first = 0; first < cells.size() && !tampered; ++first) {
    for (std::size_t second = first + 1U; second < cells.size() && !tampered;
         ++second) {
      std::set<directional::pipeline::SurfaceQuotientClassId> firstVertices(
          cells[first].corners.begin(), cells[first].corners.end());
      const bool disjoint = std::none_of(
          cells[second].corners.begin(), cells[second].corners.end(),
          [&](const auto &corner) { return firstVertices.contains(corner); });
      if (!disjoint) continue;
      cells[second].corners[0] = cells[first].corners[0];
      tampered = true;
    }
  }
  ASSERT_TRUE(tampered);
  EXPECT_EQ(records.a6.records.classes, classesBefore);
  EXPECT_EQ(records.a6.records.selectedForest, forestBefore);
  EXPECT_EQ(records.a6.records.relationConsumptions, consumptionsBefore);
  EXPECT_TRUE(has_m6cp2_finding(
      verify_m6cp2_records(records),
      directional::pipeline::VerificationFailureCode::NonManifoldTopology,
      "a6:vertex-link"));
}

TEST(M6CP2, PipelineRunsVerifierAfterA7BeforeAdapterProjection) {
  const auto &fixture = square_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction = directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(&a6Construction);
  ASSERT_NE(a6, nullptr);
  auto a7Construction = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  const auto *a7 =
      std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(&a7Construction);
  ASSERT_NE(a7, nullptr);
  static const std::set<directional::authority::SourceEdgeTopologyKey> noHardFeatures;
  auto verifiedConstruction = directional::pipeline::produce_verified_surface_products(
      fixture.mesh.V, fixture.mesh.F,
      fixture.network.phaseFront.product().sourceTopologyRegions(), noHardFeatures,
      *a5, *a6, *a7);
  const auto *verified =
      std::get_if<directional::pipeline::VerifiedSurfaceProducts>(
          &verifiedConstruction);
  ASSERT_NE(verified, nullptr);
  EXPECT_TRUE(verified->report().verified());
  EXPECT_NE(&verified->occurrences(), a5);
  EXPECT_NE(&verified->quotient(), a6);
  EXPECT_NE(&verified->geometry(), a7);

  const auto originalA5 = a5->verification_records();
  const auto ownedA5 = verified->occurrences().verification_records();
  ASSERT_EQ(ownedA5.cells.size(), originalA5.cells.size());
  ASSERT_EQ(ownedA5.occurrences.size(), originalA5.occurrences.size());
  ASSERT_EQ(ownedA5.ownedRelations.size(), originalA5.ownedRelations.size());
  for (std::size_t i = 0; i < originalA5.cells.size(); ++i) {
    EXPECT_EQ(ownedA5.cells[i].id, originalA5.cells[i].id);
    EXPECT_EQ(ownedA5.cells[i].cornerOccurrences,
              originalA5.cells[i].cornerOccurrences);
    EXPECT_EQ(ownedA5.cells[i].directedSides, originalA5.cells[i].directedSides);
    EXPECT_EQ(ownedA5.cells[i].directedSideAuthority,
              originalA5.cells[i].directedSideAuthority);
  }
  for (std::size_t i = 0; i < originalA5.occurrences.size(); ++i) {
    const auto &actual = ownedA5.occurrences[i];
    const auto &expected = originalA5.occurrences[i];
    EXPECT_EQ(actual.id, expected.id);
    EXPECT_EQ(actual.point.face, expected.point.face);
    EXPECT_EQ(actual.point.component, expected.point.component);
    EXPECT_EQ(actual.point.sheet, expected.point.sheet);
    EXPECT_TRUE(actual.point.barycentric.isApprox(expected.point.barycentric, 0.0));
    EXPECT_TRUE(actual.point.position.isApprox(expected.point.position, 0.0));
    EXPECT_EQ(actual.point.squaredDistance, expected.point.squaredDistance);
    EXPECT_EQ(actual.support, expected.support);
    EXPECT_EQ(actual.chartComponent, expected.chartComponent);
    EXPECT_EQ(actual.topologyRegion, expected.topologyRegion);
    EXPECT_EQ(actual.cornerWedgeSheets, expected.cornerWedgeSheets);
    EXPECT_EQ(actual.cornerWedgeBindings, expected.cornerWedgeBindings);
    EXPECT_EQ(actual.placement.selectedFace, expected.placement.selectedFace);
    EXPECT_TRUE(actual.placement.lattice.phase.isApprox(
        expected.placement.lattice.phase, 0.0));
    EXPECT_EQ(actual.placement.lattice.latticeCoordinate,
              expected.placement.lattice.latticeCoordinate);
    EXPECT_EQ(actual.placement.lattice.branchRotation,
              expected.placement.lattice.branchRotation);
    EXPECT_EQ(actual.placement.lattice.scaleLevel,
              expected.placement.lattice.scaleLevel);
    EXPECT_EQ(actual.placement.lattice.sourceChart,
              expected.placement.lattice.sourceChart);
    EXPECT_EQ(actual.cornerWedgeIsolation, expected.cornerWedgeIsolation);
  }
  for (std::size_t i = 0; i < originalA5.ownedRelations.size(); ++i) {
    const auto &actual = ownedA5.ownedRelations[i];
    const auto &expected = originalA5.ownedRelations[i];
    EXPECT_EQ(actual.id, expected.id);
    EXPECT_EQ(actual.firstOccurrence, expected.firstOccurrence);
    EXPECT_EQ(actual.secondOccurrence, expected.secondOccurrence);
    EXPECT_EQ(actual.firstFrontEdge, expected.firstFrontEdge);
    EXPECT_EQ(actual.secondFrontEdge, expected.secondFrontEdge);
    EXPECT_EQ(actual.evidence.canonicalTransport, expected.evidence.canonicalTransport);
    EXPECT_EQ(actual.evidence.canonicalRelationValue,
              expected.evidence.canonicalRelationValue);
    EXPECT_EQ(actual.evidence.equivalence, expected.evidence.equivalence);
    EXPECT_EQ(actual.evidence.canonicalSelectedStep,
              expected.evidence.canonicalSelectedStep);
    EXPECT_EQ(actual.evidence.firstEndpointSpan, expected.evidence.firstEndpointSpan);
    EXPECT_EQ(actual.evidence.secondEndpointSpan, expected.evidence.secondEndpointSpan);
    EXPECT_EQ(actual.evidence.firstSideIsolationEvidence,
              expected.evidence.firstSideIsolationEvidence);
    EXPECT_EQ(actual.evidence.secondSideIsolationEvidence,
              expected.evidence.secondSideIsolationEvidence);
  }
  EXPECT_EQ(ownedA5.certificate.cellCount, originalA5.certificate.cellCount);
  EXPECT_EQ(ownedA5.certificate.occurrenceCount,
            originalA5.certificate.occurrenceCount);
  EXPECT_EQ(ownedA5.certificate.directedSideCount,
            originalA5.certificate.directedSideCount);
  EXPECT_EQ(ownedA5.certificate.ownedRelationCount,
            originalA5.certificate.ownedRelationCount);
  EXPECT_EQ(ownedA5.certificate.validatedIsolationCertificateCount,
            originalA5.certificate.validatedIsolationCertificateCount);
  EXPECT_EQ(ownedA5.certificate.exactCellOwnership,
            originalA5.certificate.exactCellOwnership);
  EXPECT_EQ(ownedA5.certificate.exactCornerOwnership,
            originalA5.certificate.exactCornerOwnership);
  EXPECT_EQ(ownedA5.certificate.exactDirectedSideCycles,
            originalA5.certificate.exactDirectedSideCycles);
  EXPECT_EQ(ownedA5.certificate.exactRelationEndpointOwnership,
            originalA5.certificate.exactRelationEndpointOwnership);
  EXPECT_EQ(ownedA5.certificate.geometricCoincidenceInferenceUsed,
            originalA5.certificate.geometricCoincidenceInferenceUsed);

  const auto originalA6 = a6->verification_records();
  const auto ownedA6 = verified->quotient().verification_records();
  EXPECT_EQ(ownedA6.records.relationCertificates,
            originalA6.records.relationCertificates);
  EXPECT_EQ(ownedA6.records.relationConsumptions,
            originalA6.records.relationConsumptions);
  EXPECT_EQ(ownedA6.records.selectedForest, originalA6.records.selectedForest);
  EXPECT_EQ(ownedA6.records.selectedPaths, originalA6.records.selectedPaths);
  EXPECT_EQ(ownedA6.records.classes, originalA6.records.classes);
  EXPECT_EQ(ownedA6.records.classedCells, originalA6.records.classedCells);
  EXPECT_EQ(ownedA6.quotientCertificate.ownedRelationCount,
            originalA6.quotientCertificate.ownedRelationCount);
  EXPECT_EQ(ownedA6.quotientCertificate.relationCertificateCount,
            originalA6.quotientCertificate.relationCertificateCount);
  EXPECT_EQ(ownedA6.quotientCertificate.consumptionCount,
            originalA6.quotientCertificate.consumptionCount);
  EXPECT_EQ(ownedA6.quotientCertificate.joiningCount,
            originalA6.quotientCertificate.joiningCount);
  EXPECT_EQ(ownedA6.quotientCertificate.cycleClosingCount,
            originalA6.quotientCertificate.cycleClosingCount);
  EXPECT_EQ(ownedA6.quotientCertificate.relationBijection,
            originalA6.quotientCertificate.relationBijection);
  EXPECT_EQ(ownedA6.quotientCertificate.exactForest,
            originalA6.quotientCertificate.exactForest);
  EXPECT_EQ(ownedA6.quotientCertificate.exactCycleConsistency,
            originalA6.quotientCertificate.exactCycleConsistency);
  EXPECT_EQ(ownedA6.quotientCertificate.exactTransitivePartition,
            originalA6.quotientCertificate.exactTransitivePartition);
  EXPECT_EQ(ownedA6.materializationCertificate.sourceCellCount,
            originalA6.materializationCertificate.sourceCellCount);
  EXPECT_EQ(ownedA6.materializationCertificate.classedCellCount,
            originalA6.materializationCertificate.classedCellCount);
  EXPECT_EQ(ownedA6.materializationCertificate.sourceOccurrenceCount,
            originalA6.materializationCertificate.sourceOccurrenceCount);
  EXPECT_EQ(ownedA6.materializationCertificate.classMemberCount,
            originalA6.materializationCertificate.classMemberCount);
  EXPECT_EQ(ownedA6.materializationCertificate.exactCellBijection,
            originalA6.materializationCertificate.exactCellBijection);
  EXPECT_EQ(ownedA6.materializationCertificate.exactOccurrencePartition,
            originalA6.materializationCertificate.exactOccurrencePartition);
  EXPECT_EQ(ownedA6.materializationCertificate.noDegenerateClassedQuad,
            originalA6.materializationCertificate.noDegenerateClassedQuad);
  ASSERT_EQ(ownedA6.closedComplexView.has_value(),
            originalA6.closedComplexView.has_value());
  if (ownedA6.closedComplexView.has_value()) {
    EXPECT_EQ(ownedA6.closedComplexView->vertices,
              originalA6.closedComplexView->vertices);
    EXPECT_EQ(ownedA6.closedComplexView->quads, originalA6.closedComplexView->quads);
    EXPECT_EQ(ownedA6.closedComplexView->edges, originalA6.closedComplexView->edges);
    EXPECT_EQ(ownedA6.closedComplexView->closed, originalA6.closedComplexView->closed);
    EXPECT_EQ(ownedA6.closedComplexView->edgeIncidenceBijection,
              originalA6.closedComplexView->edgeIncidenceBijection);
    EXPECT_EQ(ownedA6.closedComplexView->protectionLabelsCertified,
              originalA6.closedComplexView->protectionLabelsCertified);
  }

  const auto originalA7 = a7->verification_records();
  const auto ownedA7 = verified->geometry().verification_records();
  ASSERT_EQ(ownedA7.vertices.size(), originalA7.vertices.size());
  for (std::size_t i = 0; i < originalA7.vertices.size(); ++i) {
    const auto &actual = ownedA7.vertices[i];
    const auto &expected = originalA7.vertices[i];
    EXPECT_EQ(actual.quotientClass, expected.quotientClass);
    EXPECT_EQ(actual.representative, expected.representative);
    EXPECT_EQ(actual.sourcePoint.face, expected.sourcePoint.face);
    EXPECT_TRUE(actual.sourcePoint.barycentric.isApprox(
        expected.sourcePoint.barycentric, 0.0));
    EXPECT_TRUE(actual.sourcePoint.position.isApprox(expected.sourcePoint.position, 0.0));
    EXPECT_TRUE(actual.position.isApprox(expected.position, 0.0));
    EXPECT_EQ(actual.support, expected.support);
    EXPECT_EQ(actual.sourceOccurrences, expected.sourceOccurrences);
    EXPECT_EQ(actual.sourceTopologyRegions, expected.sourceTopologyRegions);
    EXPECT_EQ(actual.sourceCharts, expected.sourceCharts);
    EXPECT_EQ(actual.sourceIsolationSheets, expected.sourceIsolationSheets);
    EXPECT_EQ(actual.equivalences, expected.equivalences);
    EXPECT_EQ(actual.selectedRelationPaths, expected.selectedRelationPaths);
  }
  EXPECT_EQ(ownedA7.topology, originalA7.topology);
  EXPECT_EQ(ownedA7.sourceSupportCertificates,
            originalA7.sourceSupportCertificates);
  EXPECT_EQ(ownedA7.boundaryLoops, originalA7.boundaryLoops);
  EXPECT_EQ(ownedA7.certificate, originalA7.certificate);

  const auto projected =
      directional::pipeline::project_verified_surface_products(*verified);
  EXPECT_TRUE(projected.success);
  ASSERT_TRUE(projected.verificationReport.has_value());
  EXPECT_TRUE(projected.verificationReport->verified());
  EXPECT_EQ(projected.verificationReport->findings, verified->report().findings);

  const auto pipelineResult =
      directional::pipeline::build_authoritative_phase_front_mesh(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  ASSERT_TRUE(pipelineResult.success) << pipelineResult.failure;
  ASSERT_TRUE(pipelineResult.verificationReport.has_value());
  EXPECT_TRUE(pipelineResult.verificationReport->verified());

  auto records = a5->verification_records();
  records.cells.front().directedSides[0] =
      {records.cells.front().cornerOccurrences[0],
       records.cells.front().cornerOccurrences[2]};
  const auto rejected = directional::pipeline::SurfaceProductVerifier::verify_records(
      fixture.mesh.V, fixture.mesh.F,
      fixture.network.phaseFront.product().sourceTopologyRegions(), noHardFeatures,
      records, a6->verification_records(), a7->verification_records());
  EXPECT_EQ(directional::pipeline::verification_failure_message(rejected),
            "VerificationFailed:DirectedSideCycleMismatch:a5:directed-side-cycle");
}

TEST(M6CP2, AuthoritativeOptimizerProjectionStaysOnRepresentativeScope) {
  const auto &fixture = square_fixture();
  const auto produced = directional::pipeline::build_authoritative_phase_front_mesh(
      fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  ASSERT_TRUE(produced.success) << produced.failure;
  ASSERT_EQ(produced.mesh.vertexPositions.rows(),
            static_cast<int>(produced.mesh.vertexProvenance.size()));

  directional::geometry::SurfaceOptimizationConstraints constraints;
  constraints.sourceVertices = fixture.mesh.V;
  constraints.sourceFaces = fixture.mesh.F;
  constraints.sourceNormals = fixture.mesh.faceNormals;
  constraints.sourceFieldX = Eigen::MatrixXd::Zero(fixture.mesh.F.rows(), 3);
  constraints.sourceFieldY = Eigen::MatrixXd::Zero(fixture.mesh.F.rows(), 3);
  for (int face = 0; face < fixture.mesh.F.rows(); ++face) {
    constraints.sourceFieldX.row(face) = Eigen::RowVector3d(1.0, 0.0, 0.0);
    constraints.sourceFieldY.row(face) = Eigen::RowVector3d(0.0, 1.0, 0.0);
  }
  constraints.sourceAuthority =
      &fixture.network.phaseFront.product().sourceTopologyRegions();
  constraints.constrainVerticesToProvenanceEntities = true;
  constraints.vertexProvenance = produced.mesh.vertexProvenance;
  constraints.localTargetSize = Eigen::VectorXd::Constant(fixture.mesh.V.rows(), 0.5);
  constraints.sourceVertexFaces.resize(static_cast<std::size_t>(fixture.mesh.V.rows()));
  for (int face = 0; face < fixture.mesh.F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      const int first = fixture.mesh.F(face, corner);
      const int second = fixture.mesh.F(face, (corner + 1) % 3);
      constraints.sourceVertexFaces[static_cast<std::size_t>(first)].push_back(face);
      constraints.sourceEdgeFaces[std::minmax(first, second)].push_back(face);
    }
  }
  ASSERT_TRUE(directional::pipeline::project_surface_cell_vertex_chart_authority(
      produced.mesh.vertexLineage, produced.mesh.vertexPositions.rows(), 0U,
      constraints.vertexChartAuthority));

  int vertexSupportSeeds = 0;
  int edgeSupportSeeds = 0;
  for (const auto &lineage : produced.mesh.vertexLineage) {
    if (!lineage.sourceSupport.has_value()) continue;
    if (std::holds_alternative<directional::authority::SourceVertexSupport>(
            *lineage.sourceSupport)) ++vertexSupportSeeds;
    if (std::holds_alternative<directional::authority::SourceEdgeSupport>(
            *lineage.sourceSupport)) ++edgeSupportSeeds;
  }
  ASSERT_GT(vertexSupportSeeds, 0);
  ASSERT_GT(edgeSupportSeeds, 0);

  Eigen::MatrixXd candidates = produced.mesh.vertexPositions;
  for (int vertex = 0; vertex < candidates.rows(); ++vertex)
    candidates.row(vertex) += Eigen::RowVector3d(0.031, -0.019, 0.007);
  bool componentsOk = true;
  bool sheetsOk = true;
  std::vector<directional::geometry::SurfacePoint> projected;
  directional::geometry::surface_optimizer_detail::project_vertices(
      candidates, constraints, nullptr, nullptr, &componentsOk, &sheetsOk,
      nullptr, &projected);
  ASSERT_EQ(projected.size(), constraints.vertexProvenance.size());
  EXPECT_TRUE(componentsOk);
  EXPECT_TRUE(sheetsOk);
  for (std::size_t vertex = 0; vertex < projected.size(); ++vertex) {
    const auto &seed = constraints.vertexProvenance[vertex];
    if (!seed.valid()) continue;
    EXPECT_EQ(projected[vertex].face, seed.face);
    const auto &chartAuthority = constraints.vertexChartAuthority[vertex];
    if (!chartAuthority.retained) continue;
    const auto seedRow = directional::authority::SourceFaceId::from_index(
        seed.face, static_cast<std::size_t>(fixture.mesh.F.rows()));
    ASSERT_TRUE(seedRow.has_value());
    const auto seedSheet = constraints.sourceAuthority->sheet_for_row(seedRow.value());
    bool foundSheet = false;
    for (const auto &chart : chartAuthority.sourceCharts) {
      const auto row = constraints.sourceAuthority->row_for_topology(chart.face);
      ASSERT_TRUE(row.has_value());
      foundSheet = foundSheet ||
                   constraints.sourceAuthority->sheet_for_row(row.value()) == seedSheet;
    }
    EXPECT_TRUE(foundSheet);
  }
}

TEST(M6CP2, A7WedgeTransitionWrongRegionRejects) {
  const auto &fixture = split_isolation_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  ASSERT_NE(std::get_if<directional::pipeline::SurfaceQuotientProduct>(
                &a6Construction),
            nullptr);
  auto baseline = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *a5,
      std::get<directional::pipeline::SurfaceQuotientProduct>(a6Construction));
  ASSERT_NE(std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
                &baseline),
            nullptr);

  auto cells = a5->cells();
  auto occurrences = a5->occurrences();
  auto relations = a5->owned_relations();
  auto bridge = std::find_if(occurrences.begin(), occurrences.end(),
                             [](const auto &occurrence) {
                               return occurrence.cornerWedgeSheets.size() > 1U;
                             });
  ASSERT_NE(bridge, occurrences.end());
  ASSERT_FALSE(bridge->cornerWedgeIsolation.empty());
  const auto wrongRegion = test_topology_region_id(
      static_cast<int>(bridge->topologyRegion.index()) + 1);
  ASSERT_NE(wrongRegion, bridge->topologyRegion);
  for (auto &transition : bridge->cornerWedgeIsolation) {
    transition.region = wrongRegion;
  }

  auto tampered = directional::pipeline::SurfaceOccurrenceComplexProducer::
      publish_records_for_validation(std::move(cells), std::move(occurrences),
                                     std::move(relations));
  const auto *tamperedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&tampered);
  ASSERT_NE(tamperedA5, nullptr);
  auto tamperedA6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*tamperedA5);
  const auto *tamperedA6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &tamperedA6Construction);
  ASSERT_NE(tamperedA6, nullptr);
  auto rejected = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *tamperedA5, *tamperedA6);
  const auto *failure =
      std::get_if<directional::pipeline::GeometryEmbeddingFailure>(&rejected);
  ASSERT_NE(failure, nullptr);
  EXPECT_EQ(failure->code,
            directional::pipeline::GeometryEmbeddingFailureCode::
                UncertifiedCrossSheetBinding);
  EXPECT_EQ(failure->site, "cross-sheet:wedge");
}

TEST(M6CP2, A7WedgeTransitionTouchWithoutConnectivityRejects) {
  const auto &fixture = split_isolation_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  ASSERT_NE(std::get_if<directional::pipeline::SurfaceQuotientProduct>(
                &a6Construction),
            nullptr);
  auto baseline = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *a5,
      std::get<directional::pipeline::SurfaceQuotientProduct>(a6Construction));
  ASSERT_NE(std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
                &baseline),
            nullptr);

  auto cells = a5->cells();
  auto occurrences = a5->occurrences();
  auto relations = a5->owned_relations();
  auto bridge = std::find_if(occurrences.begin(), occurrences.end(),
                             [](const auto &occurrence) {
                               return occurrence.cornerWedgeSheets.size() > 1U;
                             });
  ASSERT_NE(bridge, occurrences.end());
  ASSERT_FALSE(bridge->cornerWedgeIsolation.empty());
  const auto inSet = bridge->cornerWedgeSheets.front();
  const auto outOfSet = test_isolation_sheet_id(1000);
  ASSERT_EQ(std::find(bridge->cornerWedgeSheets.begin(),
                      bridge->cornerWedgeSheets.end(), outOfSet),
            bridge->cornerWedgeSheets.end());
  for (auto &transition : bridge->cornerWedgeIsolation) {
    transition.fromSheet = inSet;
    transition.toSheet = outOfSet;
  }

  auto tampered = directional::pipeline::SurfaceOccurrenceComplexProducer::
      publish_records_for_validation(std::move(cells), std::move(occurrences),
                                     std::move(relations));
  const auto *tamperedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&tampered);
  ASSERT_NE(tamperedA5, nullptr);
  auto tamperedA6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*tamperedA5);
  const auto *tamperedA6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &tamperedA6Construction);
  ASSERT_NE(tamperedA6, nullptr);
  auto rejected = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *tamperedA5, *tamperedA6);
  const auto *failure =
      std::get_if<directional::pipeline::GeometryEmbeddingFailure>(&rejected);
  ASSERT_NE(failure, nullptr);
  EXPECT_EQ(failure->code,
            directional::pipeline::GeometryEmbeddingFailureCode::
                UncertifiedCrossSheetBinding);
  EXPECT_EQ(failure->site, "cross-sheet:wedge");
}

TEST(M6CP2, A7ThreeSheetPartialConnectivityRejects) {
  const auto &fixture = split_isolation_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F, fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  ASSERT_NE(std::get_if<directional::pipeline::SurfaceQuotientProduct>(
                &a6Construction),
            nullptr);
  auto baseline = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *a5,
      std::get<directional::pipeline::SurfaceQuotientProduct>(a6Construction));
  ASSERT_NE(std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
                &baseline),
            nullptr);

  auto cells = a5->cells();
  auto occurrences = a5->occurrences();
  auto relations = a5->owned_relations();
  auto bridge = std::find_if(occurrences.begin(), occurrences.end(),
                             [](const auto &occurrence) {
                               return occurrence.cornerWedgeSheets.size() > 1U;
                             });
  ASSERT_NE(bridge, occurrences.end());
  ASSERT_FALSE(bridge->cornerWedgeIsolation.empty());
  const auto phantomSheet = test_isolation_sheet_id(1000);
  ASSERT_EQ(std::find(bridge->cornerWedgeSheets.begin(),
                      bridge->cornerWedgeSheets.end(), phantomSheet),
            bridge->cornerWedgeSheets.end());
  bridge->cornerWedgeSheets.push_back(phantomSheet);
  std::sort(bridge->cornerWedgeSheets.begin(), bridge->cornerWedgeSheets.end());

  auto tampered = directional::pipeline::SurfaceOccurrenceComplexProducer::
      publish_records_for_validation(std::move(cells), std::move(occurrences),
                                     std::move(relations));
  const auto *tamperedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&tampered);
  ASSERT_NE(tamperedA5, nullptr);
  auto tamperedA6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*tamperedA5);
  const auto *tamperedA6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &tamperedA6Construction);
  ASSERT_NE(tamperedA6, nullptr);
  auto rejected = directional::pipeline::SourceAttachedGeometryProducer::produce(
      fixture.mesh.V, fixture.mesh.F, *tamperedA5, *tamperedA6);
  const auto *failure =
      std::get_if<directional::pipeline::GeometryEmbeddingFailure>(&rejected);
  ASSERT_NE(failure, nullptr);
  EXPECT_EQ(failure->code,
            directional::pipeline::GeometryEmbeddingFailureCode::
                UncertifiedCrossSheetBinding);
  EXPECT_EQ(failure->site, "cross-sheet:wedge");
}

TEST(M6CP3, A7TypedWedgeSheetMismatchRejectsCachedMembership) {
  const auto &fixture = split_isolation_fixture();
  auto a5Construction =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, fixture.mesh.F,
          fixture.network.phaseFront.product());
  const auto *a5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(
          &a5Construction);
  ASSERT_NE(a5, nullptr);
  auto a6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*a5);
  const auto *a6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &a6Construction);
  ASSERT_NE(a6, nullptr);
  auto baseline =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *a5, *a6);
  ASSERT_NE(std::get_if<directional::pipeline::SourceAttachedGeometryProduct>(
                &baseline),
            nullptr);

  auto cells = a5->cells();
  auto occurrences = a5->occurrences();
  auto relations = a5->owned_relations();
  auto bridge = std::find_if(
      occurrences.begin(), occurrences.end(), [](const auto &occurrence) {
        return occurrence.cornerWedgeSheets.size() > 1U &&
               !occurrence.cornerWedgeBindings.empty();
      });
  ASSERT_NE(bridge, occurrences.end());
  const auto phantom = test_isolation_sheet_id(1000);
  ASSERT_EQ(std::find(bridge->cornerWedgeSheets.begin(),
                      bridge->cornerWedgeSheets.end(), phantom),
            bridge->cornerWedgeSheets.end());
  // The flattened cache is left unchanged. A7 must use the A5-owned face
  // binding and reject this disagreement rather than accept the cache.
  bridge->cornerWedgeBindings.front().sheet = phantom;

  auto tampered = directional::pipeline::SurfaceOccurrenceComplexProducer::
      publish_records_for_validation(std::move(cells), std::move(occurrences),
                                     std::move(relations));
  const auto *tamperedA5 =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplex>(&tampered);
  ASSERT_NE(tamperedA5, nullptr);
  auto tamperedA6Construction =
      directional::pipeline::SurfaceQuotientProducer::produce(*tamperedA5);
  const auto *tamperedA6 =
      std::get_if<directional::pipeline::SurfaceQuotientProduct>(
          &tamperedA6Construction);
  ASSERT_NE(tamperedA6, nullptr);
  const auto rejected =
      directional::pipeline::SourceAttachedGeometryProducer::produce(
          fixture.mesh.V, fixture.mesh.F, *tamperedA5, *tamperedA6);
  const auto *failure =
      std::get_if<directional::pipeline::GeometryEmbeddingFailure>(&rejected);
  ASSERT_NE(failure, nullptr);
  EXPECT_EQ(failure->code,
            directional::pipeline::GeometryEmbeddingFailureCode::
                UncertifiedCrossSheetBinding);
  EXPECT_EQ(failure->site, "cross-sheet:wedge");
}

TEST(M6CP1, A5PhaseFrontSourceFailuresKeepDistinctDiagnostics) {
  const auto &fixture = square_fixture();
  const auto &front = fixture.network.phaseFront.product();

  // SurfacePhaseFrontProduct itself rejects an empty edge set, so the A5
  // defensive empty-front branch is not constructible through public product
  // authority. Pin both the upstream fact and the preserved A5 diagnostic.
  PhaseFrontDraft emptyEdges = phase_front_draft(front);
  emptyEdges.edges.clear();
  const auto emptyConstruction =
      construct_phase_front_product(std::move(emptyEdges));
  const auto *emptyError =
      std::get_if<directional::geometry::SurfacePhaseFrontProductError>(
          &emptyConstruction);
  ASSERT_NE(emptyError, nullptr);
  EXPECT_EQ(emptyError->code,
            directional::geometry::SurfacePhaseFrontProductErrorCode::
                EmptyEdges);
  EXPECT_STREQ(
      directional::pipeline::surface_occurrence_complex_error_name(
          directional::pipeline::SurfaceOccurrenceComplexErrorCode::
              MissingAuthoritativePhaseFront),
      "MissingAuthoritativePhaseFront");

  Eigen::MatrixXi wrongFaceCount =
      fixture.mesh.F.topRows(fixture.mesh.F.rows() - 1);
  auto sourceRejected =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, wrongFaceCount, front);
  const auto *sourceError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
          &sourceRejected);
  ASSERT_NE(sourceError, nullptr);
  EXPECT_EQ(sourceError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                InvalidAuthoritativePhaseFrontSource);
  const auto sourceAdapter =
      directional::pipeline::build_authoritative_phase_front_mesh(
          fixture.mesh.V, wrongFaceCount, front);
  EXPECT_FALSE(sourceAdapter.success);
  EXPECT_EQ(sourceAdapter.failure, "InvalidAuthoritativePhaseFrontSource");

  Eigen::MatrixXi reorderedFaces = fixture.mesh.F;
  ASSERT_GE(reorderedFaces.rows(), 2);
  const Eigen::RowVectorXi firstFace = reorderedFaces.row(0);
  reorderedFaces.row(0) = reorderedFaces.row(1);
  reorderedFaces.row(1) = firstFace;
  auto chartRejected =
      directional::pipeline::SurfaceOccurrenceComplexProducer::produce(
          fixture.mesh.V, reorderedFaces, front);
  const auto *chartError =
      std::get_if<directional::pipeline::SurfaceOccurrenceComplexError>(
          &chartRejected);
  ASSERT_NE(chartError, nullptr);
  EXPECT_EQ(chartError->code,
            directional::pipeline::SurfaceOccurrenceComplexErrorCode::
                InvalidAuthoritativeSourceChartTransitions);
  const auto chartAdapter =
      directional::pipeline::build_authoritative_phase_front_mesh(
          fixture.mesh.V, reorderedFaces, front);
  EXPECT_FALSE(chartAdapter.success);
  EXPECT_EQ(chartAdapter.failure,
            "InvalidAuthoritativeSourceChartTransitions");
}

} // namespace
