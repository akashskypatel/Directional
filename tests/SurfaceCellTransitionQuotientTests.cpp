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
#include <numbers>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <gtest/gtest.h>

namespace {

directional::geometry::SourceProjectionChart test_projection_chart(
    const int fieldChart, const int sourceFace) {
  const auto chart = directional::authority::FieldChartId::from_index(
      fieldChart, static_cast<std::size_t>(std::max(fieldChart + 1, 1)));
  const auto face = directional::authority::SourceFaceId::from_index(
      sourceFace, static_cast<std::size_t>(std::max(sourceFace + 1, 1)));
  if (!chart || !face) {
    throw std::runtime_error("Invalid test projection chart.");
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

std::uint64_t raw_source_edge_key(
    const directional::authority::SourceEdgeTopologyKey &topology) {
  return directional::pipeline::surface_cell_source_edge_key(
      static_cast<int>(topology.first().index()),
      static_cast<int>(topology.second().index()));
}

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

directional::authority::CanonicalRoute boundary_route_from_raw_topology(
    const std::uint64_t topology, const std::size_t vertexExtent) {
  const auto first = directional::authority::SourceVertexId::from_index(
      static_cast<std::int64_t>(topology >> 32U), vertexExtent);
  const auto second = directional::authority::SourceVertexId::from_index(
      static_cast<std::int64_t>(topology & 0xffffffffULL), vertexExtent);
  if (!first || !second) throw std::runtime_error("Invalid boundary route vertices.");
  const auto key = directional::authority::SourceEdgeTopologyKey::make(
      first.value(), second.value());
  if (!key) throw std::runtime_error("Degenerate boundary route topology.");
  return directional::authority::CanonicalRoute::from_observed_steps({
      directional::authority::TransitionStep::boundary(
          key.value(), directional::authority::GridAutomorphism::identity(),
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
  PhaseFrontFixture fixture;
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 2.0, 0.0, 0.0, 0.0,
      1.0, 0.0, 1.0, 1.0, 0.0, 2.0, 1.0, 0.0;
  Eigen::MatrixXi faces(4, 3);
  faces << 0, 1, 4, 0, 4, 3, 1, 2, 5, 1, 5, 4;
  fixture.mesh.set_mesh(vertices, faces);
  fixture.components.assign(4U, 0);
  fixture.sheets.assign(4U, 0);
  const auto crossField =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          fixture.mesh, constant_xy_field(faces.rows()));
  directional::geometry::SurfaceCellTracingOptions options;
  options.defaultTargetSize = 0.5;
  options.sourceFaceComponents = fixture.components;
  options.sourceFaceSheets = fixture.sheets;
  options.hardFeatureEdges.insert(
      directional::pipeline::surface_cell_source_edge_key(1, 4));
  fixture.network = directional::geometry::build_surface_cell_network(
      fixture.mesh.V, fixture.mesh.F, crossField,
      Eigen::VectorXd::Constant(vertices.rows(), 0.5), options);
  require_produced(fixture, "hard-rail rectangle");
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
  fixture.network = result.surfaceCellContext.traceNetwork;
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

const PhaseFrontFixture &winding_cylinder_fixture() {
  static const PhaseFrontFixture fixture =
      make_committed_fixture("cylinder", true);
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

int first_edge_of_kind(const SurfacePhaseFrontResult &phaseFront,
                       const SurfaceFrontBoundaryKind kind) {
  for (int edge = 0; edge < static_cast<int>(phaseFront.product().edges.size()); ++edge) {
    if (phaseFront.product().edges[static_cast<std::size_t>(edge)].boundaryKind == kind) {
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
  std::uint64_t topology = 0;
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
       cellIndex < fixture.network.phaseFront.product().cells.size(); ++cellIndex) {
    const auto &cell = fixture.network.phaseFront.product().cells[cellIndex];
    const auto region = std::find_if(
        fixture.network.phaseFront.product().sourceTopologyRegions.regions().begin(),
        fixture.network.phaseFront.product().sourceTopologyRegions.regions().end(),
        [&](const auto &candidate) {
          return candidate.id() == cell.sourceTopologyRegion;
        });
    if (region == fixture.network.phaseFront.product().sourceTopologyRegions.regions().end() ||
        region->faces().empty()) {
      continue;
    }
    const auto regionalRows =
        fixture.network.phaseFront.product().sourceTopologyRegions.rows_for_region(
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
          const std::uint64_t topology =
              directional::pipeline::surface_cell_source_edge_key(
                  static_cast<int>(step.topology().first().index()),
                  static_cast<int>(step.topology().second().index()));
          const auto globalIndex = sourceWide.find(topology);
          const auto localIndex = regionLocal.find(topology);
          const auto incident = sourceIncidence.find(topology);
          if (globalIndex == sourceWide.end() ||
              localIndex == regionLocal.end() ||
              incident == sourceIncidence.end() || incident->second[0] < 0 ||
              incident->second[1] < 0 ||
              step.interior()->index() !=
                  static_cast<std::size_t>(globalIndex->second)) {
            continue;
          }

          int transitionCount = 0;
          int fullEfRow = -1;
          for (const auto &candidate : crossField.edgeTransitions) {
            const bool sameTopology =
                directional::pipeline::surface_cell_source_edge_key(
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
              directional::pipeline::surface_cell_source_edge_key(
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
          return {cellIndex, side, segmentIndex, route, topology,
                  globalIndex->second, localIndex->second, fullEfRow};
        }
      }
    }
  }
  throw std::runtime_error(
      "Missing serialized route topology with distinct source-wide, "
      "region-local, and EF transition indices");
}

bool replace_transition_index(SurfacePhaseFrontResult &phaseFront,
                               const TransitionIndexDomainWitness &witness,
                               const int replacement) {
  if (witness.cell >= phaseFront.product().cells.size()) return false;
  auto &cell = phaseFront.product().cells[witness.cell];
  if (witness.side >= cell.boundaryPaths.size()) return false;
  auto &path = cell.boundaryPaths[witness.side];
  if (witness.segment >= path.size()) return false;
  auto &segment = path[witness.segment];
  auto steps = segment.entryRoute.oriented_steps();
  if (witness.route >= steps.size()) return false;
  const auto &original = steps[witness.route];
  const std::uint64_t topology =
      directional::pipeline::surface_cell_source_edge_key(
          static_cast<int>(original.topology().first().index()),
          static_cast<int>(original.topology().second().index()));
  if (original.kind() != directional::authority::TransitionStepKind::Interior ||
      !original.interior().has_value() || topology != witness.topology ||
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
         directional::pipeline::surface_cell_source_edge_key(
             static_cast<int>(mutated[witness.route].topology().first().index()),
             static_cast<int>(mutated[witness.route].topology().second().index())) ==
             witness.topology;
}

directional::pipeline::RemeshResult semantic_two_component_result() {
  directional::pipeline::RemeshResult result;
  result.success = true;
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
  return result;
}

directional::pipeline::RemeshResult permute_semantic_output_rows(
    const directional::pipeline::RemeshResult &source) {
  directional::pipeline::RemeshResult permuted = source;
  const std::array<int, 8> newToOld{7, 6, 5, 4, 3, 2, 1, 0};
  std::array<int, 8> oldToNew{};
  for (int vertex = 0; vertex < 8; ++vertex) {
    oldToNew[static_cast<std::size_t>(
        newToOld[static_cast<std::size_t>(vertex)])] = vertex;
    permuted.vertices.row(vertex) =
        source.vertices.row(newToOld[static_cast<std::size_t>(vertex)]);
  }
  for (int face = 0; face < 2; ++face) {
    const int oldFace = 1 - face;
    for (int corner = 0; corner < 4; ++corner) {
      permuted.faces(face, corner) = oldToNew[static_cast<std::size_t>(
          source.faces(oldFace, corner))];
    }
  }
  permuted.outputVertexLineage.clear();
  for (int vertex = 0; vertex < 8; ++vertex) {
    auto lineage = source.outputVertexLineage[static_cast<std::size_t>(
        newToOld[static_cast<std::size_t>(vertex)])];
    lineage.outputVertex = vertex;
    permuted.outputVertexLineage.push_back(std::move(lineage));
  }
  permuted.outputQuadLineage.clear();
  for (int face = 0; face < 2; ++face) {
    auto lineage = source.outputQuadLineage[static_cast<std::size_t>(1 - face)];
    lineage.outputQuad = face;
    permuted.outputQuadLineage.push_back(std::move(lineage));
  }
  return permuted;
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

  ASSERT_LT(witness.cell, fixture.network.phaseFront.product().cells.size());
  const auto &witnessCell = fixture.network.phaseFront.product().cells[witness.cell];
  ASSERT_LT(witness.side, witnessCell.boundaryPaths.size());
  const auto &witnessPath = witnessCell.boundaryPaths[witness.side];
  ASSERT_LT(witness.segment, witnessPath.size());
  const auto &witnessSegment = witnessPath[witness.segment];
  const auto witnessSteps = witnessSegment.entryRoute.oriented_steps();
  ASSERT_LT(witness.route, witnessSteps.size());
  ASSERT_TRUE(witnessSteps[witness.route].interior().has_value());
  EXPECT_EQ(static_cast<std::size_t>(witness.sourceWideCompact),
            witnessSteps[witness.route].interior()->index());
  EXPECT_EQ(witness.topology,
            directional::pipeline::surface_cell_source_edge_key(
                static_cast<int>(witnessSteps[witness.route].topology().first().index()),
                static_cast<int>(witnessSteps[witness.route].topology().second().index())));

  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceWide = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  for (const auto &cell : fixture.network.phaseFront.product().cells) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        for (const auto &step : segment.entryRoute.oriented_steps()) {
          ASSERT_EQ(directional::authority::TransitionStepKind::Interior,
                    step.kind());
          ASSERT_TRUE(step.interior().has_value());
          const std::uint64_t topology =
              directional::pipeline::surface_cell_source_edge_key(
                  static_cast<int>(step.topology().first().index()),
                  static_cast<int>(step.topology().second().index()));
          const auto expected = sourceWide.find(topology);
          ASSERT_NE(expected, sourceWide.end());
          EXPECT_EQ(static_cast<std::size_t>(expected->second),
                    step.interior()->index());
        }
      }
    }
  }

  bool observedGenuineBoundary = false;
  for (const auto &edge : fixture.network.phaseFront.product().edges) {
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
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  ASSERT_TRUE(replace_transition_index(tampered, witness, witness.fullEfRow));
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativeTransitionSourceEdge", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     RegionLocalCompactTransitionIndexCannotReplaceSourceWideIndex) {
  const auto &fixture = transition_domain_fixture();
  const auto witness = transition_index_domain_witness();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
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
  for (const auto &edge : fixture.network.phaseFront.product().edges) {
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
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int boundary = first_edge_of_kind(
      tampered, SurfaceFrontBoundaryKind::GenuineSourceBoundary);
  ASSERT_GE(boundary, 0);
  auto &edge = tampered.product().edges[static_cast<std::size_t>(boundary)];
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
            fixture.network.phaseFront.product().isolationSeamTransportCertificates
                .size());
  const auto &certificate =
      fixture.network.phaseFront.product().isolationSeamTransportCertificates.front();
  EXPECT_LT(certificate.transition.index(), fixture.mesh.EF.rows());
  EXPECT_NE(certificate.firstSheet, certificate.secondSheet);
  EXPECT_EQ(certificate.forward.inverse(), certificate.reverse);
  EXPECT_NE(0U, directional::geometry::surface_cell_tracing_detail::
                    isolation_seam_transport_certificate_hash(certificate));
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(1U, result.consumedInternalIsolationSeams);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     MissingIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  ASSERT_FALSE(tampered.product().isolationSeamTransportCertificates.empty());
  tampered.product().isolationSeamTransportCertificates.clear();
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("IsolationSeamCertificateBijectionMismatch", result.failure);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     DuplicateIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  ASSERT_FALSE(tampered.product().isolationSeamTransportCertificates.empty());
  tampered.product().isolationSeamTransportCertificates.push_back(
      tampered.product().isolationSeamTransportCertificates.front());
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativeIsolationSeamCertificate", result.failure);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     WrongOwnerIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  ASSERT_FALSE(tampered.product().isolationSeamTransportCertificates.empty());
  auto &certificate = tampered.product().isolationSeamTransportCertificates.front();
  const auto wrongRegion = directional::authority::TopologyRegionId::from_index(
      static_cast<std::int64_t>(
          tampered.product().sourceTopologyRegions.regions().size()),
      tampered.product().sourceTopologyRegions.regions().size() + 1U);
  ASSERT_TRUE(wrongRegion);
  certificate.region = wrongRegion.value();
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativeIsolationSeamCertificate", result.failure);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     WrongSheetIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  ASSERT_FALSE(tampered.product().isolationSeamTransportCertificates.empty());
  auto &certificate = tampered.product().isolationSeamTransportCertificates.front();
  const auto wrongSheet = directional::authority::IsolationSheetId::from_index(
      99, 100);
  ASSERT_TRUE(wrongSheet);
  certificate.firstSheet = wrongSheet.value();
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("IsolationSeamCertificateSourceAuthorityMismatch", result.failure);
}

TEST(SurfaceCellIsolationSeamCertificateAuthority,
     NonreciprocalIsolationSeamCertificateIsRejected) {
  const auto &fixture = split_isolation_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  ASSERT_FALSE(tampered.product().isolationSeamTransportCertificates.empty());
  auto &certificate = tampered.product().isolationSeamTransportCertificates.front();
  certificate.reverse = directional::authority::QuarterTurn::from_integer(
      static_cast<int>(certificate.reverse.value()) + 1);
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativeIsolationSeamCertificate", result.failure);
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
      fixture.network.phaseFront.product().edges[static_cast<std::size_t>(ordinary)];
  ASSERT_GE(edge.oppositeEdge, 0);
  const auto &opposite = fixture.network.phaseFront.product().edges[
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
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int ordinary =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::OrdinaryInterior);
  ASSERT_GE(ordinary, 0);
  tampered.product().edges[static_cast<std::size_t>(ordinary)]
      .fromLattice.latticeCoordinate.x() += 1;
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativePhaseFrontSideAuthority", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     FullPeriodicRotationAndTranslationMaterialize) {
  const auto &fixture = winding_cylinder_fixture();
  ASSERT_FALSE(fixture.network.phaseFront.product().periodicHolonomies.empty());
  const auto relation = std::find_if(
      fixture.network.phaseFront.product().periodicHolonomies.begin(),
      fixture.network.phaseFront.product().periodicHolonomies.end(),
      [](const auto &candidate) {
        return candidate.action.rotation != directional::authority::QuarterTurn{} &&
               (candidate.action.shift.x != 0 || candidate.action.shift.y != 0);
      });
  ASSERT_NE(fixture.network.phaseFront.product().periodicHolonomies.end(), relation)
      << "the winding cross field must exercise a non-identity Z4 action";
  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(fixture.network.phaseFront.product().periodicHolonomies.size(),
            result.consumedPeriodicHolonomies);
}

TEST(SurfaceCellTransitionQuotient,
     TamperedFullPeriodicTransformIsRejected) {
  const auto &fixture = winding_cylinder_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const auto relation = std::find_if(
      tampered.product().periodicHolonomies.begin(), tampered.product().periodicHolonomies.end(),
      [](const auto &candidate) {
        return candidate.action.shift.x != 0 || candidate.action.shift.y != 0;
      });
  ASSERT_NE(tampered.product().periodicHolonomies.end(), relation);
  relation->action.rotation = directional::authority::QuarterTurn::from_integer(
      static_cast<int>(relation->action.rotation.value()) + 1);
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidPeriodicFrontTransport", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     MultiplePeriodicRelationsSurviveRelationReorderingByExplicitOwner) {
  const auto &fixture = torus_fixture();
  SurfacePhaseFrontResult reordered = fixture.network.phaseFront;
  const int relationCount =
      static_cast<int>(reordered.product().periodicHolonomies.size());
  ASSERT_GT(relationCount, 1);
  std::reverse(reordered.product().periodicHolonomies.begin(),
               reordered.product().periodicHolonomies.end());
  for (auto &edge : reordered.product().edges) {
    if (edge.periodicRelation.has_value()) {
      const std::size_t oldIndex = edge.periodicRelation->index();
      ASSERT_LT(oldIndex, static_cast<std::size_t>(relationCount));
      const std::size_t remappedIndex =
          static_cast<std::size_t>(relationCount - 1) - oldIndex;
      const auto remapped = directional::authority::PeriodicRelationId::from_index(
          static_cast<std::int64_t>(remappedIndex),
          static_cast<std::size_t>(relationCount));
      ASSERT_TRUE(remapped);
      edge.periodicRelation = remapped.value();
    }
  }
  const auto result = materialize(fixture, reordered);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(reordered.product().periodicHolonomies.size(),
            result.consumedPeriodicHolonomies);
}

TEST(SurfaceCellTransitionQuotient,
     SwappedPeriodicRelationOwnersAreRejected) {
  const auto &fixture = torus_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  ASSERT_GT(tampered.product().periodicHolonomies.size(), 1U);
  std::reverse(tampered.product().periodicHolonomies.begin(),
               tampered.product().periodicHolonomies.end());
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
}

TEST(SurfaceCellTransitionQuotient,
     MissingPeriodicRelationOwnerIsRejected) {
  const auto &fixture = torus_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int periodic =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::PeriodicCut);
  ASSERT_GE(periodic, 0);
  tampered.product().edges[static_cast<std::size_t>(periodic)].periodicRelation =
      std::nullopt;
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidPeriodicCutAuthority", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     ExactHardRailCounterpartsStitchAcrossTopologyRegions) {
  const auto &fixture = hard_rail_fixture();
  const int hardRail = first_edge_of_kind(fixture.network.phaseFront,
                                          SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  const auto &edge =
      fixture.network.phaseFront.product().edges[static_cast<std::size_t>(hardRail)];
  ASSERT_GE(edge.oppositeEdge, 0);
  const auto &opposite = fixture.network.phaseFront.product().edges[
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
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  tampered.product().edges[static_cast<std::size_t>(hardRail)].oppositeEdge = -1;
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativePhaseFrontOwnership", result.failure);
}

TEST(SurfaceCellTransitionQuotient,
     AmbiguousHardRailCounterpartIsRejected) {
  const auto &fixture = hard_rail_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  const int opposite =
      tampered.product().edges[static_cast<std::size_t>(hardRail)].oppositeEdge;
  ASSERT_GE(opposite, 0);
  tampered.product().edges[static_cast<std::size_t>(opposite)].oppositeEdge = opposite;
  const auto result = materialize(fixture, tampered);
  EXPECT_FALSE(result.success);
  EXPECT_EQ("InvalidAuthoritativePhaseFrontOwnership", result.failure);
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
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  ASSERT_FALSE(tampered.product().cells.empty());
  tampered.product().cells.front().corners[1] = tampered.product().cells.front().corners[0];
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
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int ordinary =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::OrdinaryInterior);
  ASSERT_GE(ordinary, 0);
  auto &edge = tampered.product().edges[static_cast<std::size_t>(ordinary)];
  const int opposite = edge.oppositeEdge;
  ASSERT_GE(opposite, 0);
  const std::uint64_t interiorTopology =
      directional::pipeline::surface_cell_source_edge_key(0, 2);
  edge.oppositeEdge = -1;
  edge.exterior = true;
  edge.boundaryKind = SurfaceFrontBoundaryKind::GenuineSourceBoundary;
  edge.route = boundary_route_from_raw_topology(
      interiorTopology, static_cast<std::size_t>(fixture.mesh.V.rows()));
  auto &other = tampered.product().edges[static_cast<std::size_t>(opposite)];
  other.oppositeEdge = -1;
  other.exterior = true;
  other.boundaryKind = SurfaceFrontBoundaryKind::GenuineSourceBoundary;
  other.route = boundary_route_from_raw_topology(
      interiorTopology, static_cast<std::size_t>(fixture.mesh.V.rows()));
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
  EXPECT_FALSE(retained.success);
  EXPECT_FALSE(released.success);
  EXPECT_EQ(retained.diagnostics.terminalFailureCode,
            released.diagnostics.terminalFailureCode);
  EXPECT_EQ(retained.diagnostics.terminalFailureStage,
            released.diagnostics.terminalFailureStage);
  EXPECT_EQ("InjectedStageFailure", retained.diagnostics.terminalFailureCode);
  EXPECT_EQ("tracing", retained.diagnostics.terminalFailureStage);
  EXPECT_TRUE(retained.surfaceCellContext.hasTraceNetwork);
  EXPECT_FALSE(released.surfaceCellContext.hasTraceNetwork);
  ASSERT_TRUE(retained.surfaceCellContext.traceNetwork.phaseFront.is_produced());
  EXPECT_FALSE(
      retained.surfaceCellContext.traceNetwork.phaseFront.product().cells.empty());
  EXPECT_EQ(nullptr,
            released.surfaceCellContext.traceNetwork.phaseFront.produced_product());
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
  std::swap(mutation.faces(0, 3), mutation.faces(1, 3));
  EXPECT_NE(directional::bench::benchmark_output_semantic_hash(baseline),
            directional::bench::benchmark_output_semantic_hash(mutation));
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestDetectsWindingMutation) {
  const auto baseline = semantic_two_component_result();
  auto mutation = baseline;
  std::swap(mutation.faces(0, 1), mutation.faces(0, 3));
  EXPECT_NE(directional::bench::benchmark_output_semantic_hash(baseline),
            directional::bench::benchmark_output_semantic_hash(mutation));
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestDetectsSourceSupportMutation) {
  const auto baseline = semantic_two_component_result();
  auto mutation = baseline;
  mutation.outputVertexLineage.front().sourceSupport =
      test_source_vertex_support(1);
  EXPECT_NE(directional::bench::benchmark_output_semantic_hash(baseline),
            directional::bench::benchmark_output_semantic_hash(mutation));
}

TEST(SurfaceCellTransitionQuotient,
     SemanticDigestDetectsComponentSeparationMutation) {
  const auto baseline = semantic_two_component_result();
  auto mutation = baseline;
  for (std::size_t vertex = 4; vertex < mutation.outputVertexLineage.size();
       ++vertex) {
    auto &lineage = mutation.outputVertexLineage[vertex];
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
  mutation.outputVertexLineage.front().equivalences.push_back(equivalence);
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
      fixture.network.phaseFront.product().edges[static_cast<std::size_t>(hardRail)];
  ASSERT_TRUE(route_is_all_interior(edge.route));

  const auto sourceIncidence = directional::geometry::
      surface_cell_tracing_detail::edge_faces(fixture.mesh.F);
  const auto sourceTransitions = directional::geometry::
      surface_cell_tracing_detail::edge_matching_indices(sourceIncidence);
  for (const auto &step : edge.route.steps()) {
    ASSERT_TRUE(step.interior().has_value());
    const auto expected = sourceTransitions.find(raw_source_edge_key(step.topology()));
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
      fixture.network.phaseFront.product().edges[static_cast<std::size_t>(periodic)];
  ASSERT_TRUE(route_is_all_interior(edge.route));
  ASSERT_TRUE(edge.periodicRelation.has_value());
  ASSERT_LT(edge.periodicRelation->index(),
            fixture.network.phaseFront.product().periodicHolonomies.size());

  const auto result = materialize(fixture, fixture.network.phaseFront);
  ASSERT_TRUE(result.success) << result.failure;
  EXPECT_EQ(fixture.network.phaseFront.product().periodicHolonomies.size(),
            result.consumedPeriodicHolonomies);
}

TEST(SurfaceCellTypedTransportAuthority,
     MissingInteriorTransitionIsRejectedByTypedFactory) {
  const auto &fixture = hard_rail_fixture();
  const int hardRail = first_edge_of_kind(fixture.network.phaseFront,
                                          SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  const auto &edge =
      fixture.network.phaseFront.product().edges[static_cast<std::size_t>(hardRail)];
  ASSERT_TRUE(route_is_all_interior(edge.route));
  const auto invalid = directional::authority::TransitionStep::interior(
      edge.route.steps().front().topology(), std::nullopt,
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
     ComponentSheetExtentUsesOnlyCompleteTypedLineage) {
  std::vector<directional::geometry::PureQuadVertexLineage> lineage(2);
  for (std::size_t vertex = 0; vertex < lineage.size(); ++vertex) {
    lineage[vertex].sourceTopologyRegions = {test_topology_region_id(0)};
    lineage[vertex].sourceIsolationSheets = {
        test_isolation_sheet_id(static_cast<int>(vertex) + 2)};
    lineage[vertex].sourceCharts = {
        test_projection_chart(static_cast<int>(vertex),
                              static_cast<int>(vertex))};
    lineage[vertex].sourceSupport =
        test_source_vertex_support(static_cast<int>(vertex));
    lineage[vertex].sourcePoint.sheet = 700 + static_cast<int>(vertex);
    lineage[vertex].sourcePoint.component = 800 + static_cast<int>(vertex);
  }
  const auto baseline = directional::pipeline::
      typed_component_isolation_sheet_extent(lineage, lineage.size());
  ASSERT_TRUE(baseline.has_value());
  EXPECT_EQ(3, *baseline);

  for (auto &vertex : lineage) {
    vertex.sourcePoint.sheet += 10000;
    vertex.sourcePoint.component += 10000;
  }
  const auto tampered = directional::pipeline::
      typed_component_isolation_sheet_extent(lineage, lineage.size());
  EXPECT_EQ(baseline, tampered);

  lineage.front().sourceSupport.reset();
  EXPECT_FALSE(directional::pipeline::typed_component_isolation_sheet_extent(
                   lineage, lineage.size())
                   .has_value());
}

TEST(SurfaceCellTypedTransportAuthority,
     OutOfDomainSourceVertexIsRejectedAtIngress) {
  const auto &fixture = hard_rail_fixture();
  const auto invalid = directional::authority::SourceVertexId::from_index(
      fixture.mesh.V.rows(), static_cast<std::size_t>(fixture.mesh.V.rows()));
  ASSERT_FALSE(invalid);
  EXPECT_EQ(directional::authority::DomainErrorCode::IndexOutOfRange,
            invalid.error().code);
}

TEST(SurfaceCellTypedTransportAuthority,
     RouteTopologyTransitionMismatchFailsClosed) {
  const auto &fixture = hard_rail_fixture();
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.product().edges[static_cast<std::size_t>(hardRail)];
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
  SurfacePhaseFrontResult tampered = fixture.network.phaseFront;
  const int hardRail =
      first_edge_of_kind(tampered, SurfaceFrontBoundaryKind::HardRail);
  ASSERT_GE(hardRail, 0);
  auto &edge = tampered.product().edges[static_cast<std::size_t>(hardRail)];
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

} // namespace
