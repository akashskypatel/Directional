#include "BenchmarkQuality.h"
#include "TestFixturePaths.h"
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/validation/MeshValidator.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iterator>
#include <map>
#include <variant>
#include <numbers>
#include <set>
#include <stdexcept>
#include <string>
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
    const auto relationId = directional::authority::PeriodicRelationId::from_index(
        relationIndex, 2);
    if (!relationId) {
      throw std::runtime_error("Invalid direct periodic relation owner ID.");
    }
    const directional::authority::GridAutomorphism action{
        directional::authority::QuarterTurn{},
        relationIndex == 0 ? directional::authority::LatticeTranslation{4, 0}
                           : directional::authority::LatticeTranslation{0, 5}};
    auto relation = directional::geometry::SurfacePeriodicHolonomy::make(
        relationId.value(), regionId.value(), action,
        routes[static_cast<std::size_t>(relationIndex)],
        cuts[static_cast<std::size_t>(relationIndex)]);
    auto *relationValue =
        std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&relation);
    if (relationValue == nullptr) {
      throw std::runtime_error("Failed to construct direct periodic relation.");
    }
    relations.push_back(std::move(*relationValue));

    directional::geometry::SurfaceFrontEdge edge(regionId.value(),
                                                  ownerCell.value());
    edge.boundaryKind = SurfaceFrontBoundaryKind::PeriodicCut;
    edge.periodicRelation = relationId.value();
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
  namespace detail = directional::geometry::surface_cell_tracing_detail;
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
  fixture.components.assign(8U, 0);
  fixture.sheets.assign(8U, 0);
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, constant_xy_field(faces.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.2;
  options.sourceFaceComponents = fixture.components;
  options.sourceFaceSheets = fixture.sheets;
  options.hardFeatureEdges.insert(
      test_source_edge_topology(1, 4));
  options.hardFeatureEdges.insert(
      test_source_edge_topology(4, 7));

  const auto sourceEdgeFaces = detail::edge_faces(fixture.mesh.F);
  const auto appendRailInterval =
      [&](directional::geometry::SurfaceCellRail &rail, const int a,
          const int b, const double railT0, const double railT1) {
        const auto topology = test_source_edge_topology(
            a, b, static_cast<std::size_t>(fixture.mesh.V.rows()));
        const auto incident = sourceEdgeFaces.find(topology);
        if (incident == sourceEdgeFaces.end() || incident->second[0] < 0) {
          throw std::runtime_error("Missing test hard-rail source edge.");
        }
        const int sourceFace = incident->second[0];
        const int sourceEdge =
            detail::local_edge_for_key(fixture.mesh.F, sourceFace, topology);
        if (sourceEdge < 0) {
          throw std::runtime_error("Missing test hard-rail local edge.");
        }
        const auto makeSample = [&](const int sourceVertex,
                                    const double parameter,
                                    const double railParameter) {
          directional::geometry::SurfaceCellRailSample sample;
          sample.sourceFace = sourceFace;
          sample.sourceEdge = sourceEdge;
          sample.parameter = parameter;
          sample.railParameter = railParameter;
          sample.position = fixture.mesh.V.row(sourceVertex);
          for (int corner = 0; corner < 3; ++corner) {
            if (fixture.mesh.F(sourceFace, corner) == sourceVertex) {
              sample.barycentric[corner] = 1.0;
            }
          }
          return sample;
        };
        rail.samples.push_back(makeSample(a, 0.0, railT0));
        rail.samples.push_back(makeSample(b, 1.0, railT1));
      };
  const auto railId = directional::authority::HardRailId::from_index(0, 1);
  if (!railId) {
    throw std::runtime_error("Invalid test hard-rail ID.");
  }
  directional::geometry::SurfaceCellRail rail(railId.value());
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.curveId = 0;
  rail.component = 0;
  rail.sourceVertices = {1, 4, 7};
  appendRailInterval(rail, 1, 4, 0.0, 0.5);
  appendRailInterval(rail, 4, 7, 0.5, 1.0);
  options.authoritativeRails.push_back(std::move(rail));

  fixture.network = directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField,
      Eigen::VectorXd::Constant(vertices.rows(), 0.2), options);
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
          product.cells()};
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
      std::move(draft.events), std::move(draft.cells));
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
  const auto duplicateId = tampered.periodicHolonomies.front().id();
  tampered.periodicHolonomies[1] =
      tampered.periodicHolonomies[1].with_id(duplicateId);
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          DuplicatePeriodicRelationId);
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
      original.id(), foreignRegion.value(), original.action(), original.route(),
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
  const auto relationCount = tampered.periodicHolonomies.size();
  const auto unknownOwner =
      directional::authority::PeriodicRelationId::from_index(
          static_cast<std::int64_t>(relationCount), relationCount + 1U);
  ASSERT_TRUE(unknownOwner.has_value());
  tampered.edges.front().periodicRelation = unknownOwner.value();
  const auto construction = construct_phase_front_product(std::move(tampered));
  expect_phase_front_product_error(
      construction,
      directional::geometry::SurfacePhaseFrontProductErrorCode::
          InvalidPeriodicRelationOwner);
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

TEST(SurfaceCellTransitionQuotient,
     TamperedFullPeriodicTransformIsRejected) {
  const auto &fixture = direct_materializer_base_fixture();
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
  ASSERT_NE(originalAction, action); auto rebuilt = directional::geometry::SurfacePeriodicHolonomy::make(
      relation->id(), relation->sourceTopologyRegion(), action,
      relation->route(), relation->cutRoute());
  auto *value =
      std::get_if<directional::geometry::SurfacePeriodicHolonomy>(&rebuilt);
  ASSERT_NE(nullptr, value);
  *relation = std::move(*value);
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidPeriodicFrontTransport", result.failure);
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
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidPeriodicRelation", result.failure);
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
  const auto relationId =
      directional::authority::PeriodicRelationId::from_index(1, 2);
  ASSERT_TRUE(relationId);
  equivalence.periodicRelation = relationId.value();
  equivalence.action = {directional::authority::QuarterTurn::from_integer(1),
                        {2, -1}};
  equivalence.route = test_interior_route(0, 1, 0);
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
        relation.id(), relation.sourceTopologyRegion(), action, relation.route(),
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

} // namespace
