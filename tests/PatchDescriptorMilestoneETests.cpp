#include <directional/geometry/PatchDescriptor.h>
#include <directional/geometry/SurfaceComplexSimplification.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <gtest/gtest.h>

#include <array>
#include <limits>
#include <numeric>
#include <stdexcept>
#include <vector>
#include "TestAuthorityIds.h"

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


directional::geometry::SourceProjectionChart
canonical_projection_chart_for_source_row(
    const Eigen::MatrixXi &faces, const int sourceFace,
    const directional::authority::FieldChartId fieldChart) {
  if (faces.cols() != 3 || sourceFace < 0 || sourceFace >= faces.rows()) {
    throw std::runtime_error("Invalid canonical source-face test row.");
  }
  const std::size_t vertexExtent = static_cast<std::size_t>(
      std::max(faces.maxCoeff() + 1, 1));
  const auto first = directional::authority::SourceVertexId::from_index(
      faces(sourceFace, 0), vertexExtent);
  const auto second = directional::authority::SourceVertexId::from_index(
      faces(sourceFace, 1), vertexExtent);
  const auto third = directional::authority::SourceVertexId::from_index(
      faces(sourceFace, 2), vertexExtent);
  if (!first || !second || !third) {
    throw std::runtime_error("Invalid canonical source-face test vertex.");
  }
  const auto topology = directional::authority::SourceFaceTopologyKey::make(
      {first.value(), second.value(), third.value()});
  if (!topology) {
    throw std::runtime_error("Invalid canonical source-face test topology.");
  }
  return {fieldChart, topology.value()};
}

void bind_patch_charts_to_source_topology(
    const Eigen::MatrixXi &faces,
    directional::geometry::SurfaceCellComplex &complex) {
  const auto bind_optional =
      [&](const int sourceFace,
          std::optional<directional::geometry::SourceProjectionChart> &chart) {
        if (!chart.has_value()) {
          return;
        }
        chart = canonical_projection_chart_for_source_row(
            faces, sourceFace, chart->chart);
      };

  for (auto &node : complex.nodes) {
    bind_optional(node.sourceFace, node.sourceChart);
    for (auto &occurrence : node.occurrences) {
      bind_optional(occurrence.sourceFace, occurrence.sourceChart);
    }
  }
  for (auto &edge : complex.halfedges) {
    bind_optional(edge.sourceFace, edge.sourceChart);
    for (auto &provenance : edge.provenance) {
      bind_optional(provenance.sourceFace, provenance.sourceChart);
    }
  }
  for (auto &cell : complex.cells) {
    if (cell.sourceCharts.size() != cell.sourceFaces.size()) {
      throw std::runtime_error(
          "Patch test source-chart/source-face cardinality mismatch.");
    }
    for (std::size_t index = 0; index < cell.sourceCharts.size(); ++index) {
      cell.sourceCharts[index] = canonical_projection_chart_for_source_row(
          faces, cell.sourceFaces[index], cell.sourceCharts[index].chart);
    }
    std::sort(cell.sourceCharts.begin(), cell.sourceCharts.end());
    cell.sourceCharts.erase(
        std::unique(cell.sourceCharts.begin(), cell.sourceCharts.end()),
        cell.sourceCharts.end());
  }
  if (!complex.sourceOwnershipRegistry.empty()) {
    throw std::runtime_error(
        "Patch row-identity fixture must establish authority before registry "
        "materialization.");
  }
}


auto test_topology_region_id(const int value) {
  const auto id = directional::authority::TopologyRegionId::from_index(
      value, static_cast<std::size_t>(std::max(value + 1, 1)));
  if (!id) {
    throw std::runtime_error("Invalid test topology-region ID.");
  }
  return id.value();
}

struct Fixture {
  Eigen::MatrixXd V;
  Eigen::MatrixXi F;
  directional::geometry::SurfaceCellComplex complex;
};

Fixture make_patch(const std::vector<int> &sideCounts,
                   const bool hardBarrier = false) {
  const int boundaryCount =
      std::accumulate(sideCounts.begin(), sideCounts.end(), 0);
  Fixture fixture;
  fixture.V.resize(boundaryCount + 1, 3);
  fixture.V.row(0) << 0.0, 0.0, 0.0;
  constexpr double pi = 3.14159265358979323846;
  int boundaryVertex = 0;
  for (int side = 0; side < static_cast<int>(sideCounts.size()); ++side) {
    const double firstAngle =
        2.0 * pi * static_cast<double>(side) /
        static_cast<double>(sideCounts.size());
    const double secondAngle =
        2.0 * pi * static_cast<double>((side + 1) % sideCounts.size()) /
        static_cast<double>(sideCounts.size());
    const Eigen::RowVector3d first{std::cos(firstAngle), std::sin(firstAngle),
                                   0.0};
    const Eigen::RowVector3d second{
        std::cos(secondAngle), std::sin(secondAngle), 0.0};
    for (int local = 0; local < sideCounts[static_cast<std::size_t>(side)];
         ++local) {
      const double t = static_cast<double>(local) /
                       static_cast<double>(
                           sideCounts[static_cast<std::size_t>(side)]);
      fixture.V.row(++boundaryVertex) = (1.0 - t) * first + t * second;
    }
  }
  fixture.F.resize(boundaryCount, 3);
  for (int i = 0; i < boundaryCount; ++i) {
    fixture.F.row(i) << 0, i + 1, (i + 1) % boundaryCount + 1;
  }

  fixture.complex.nodes.resize(boundaryCount);
  fixture.complex.halfedges.resize(boundaryCount);
  directional::geometry::SurfaceArrangementCell cell;
  cell.id = 0;
  cell.sourceFace = 0;
  cell.sourceTopologyRegion = test_topology_region_id(2);
  cell.sourceFaces.resize(boundaryCount);
  std::iota(cell.sourceFaces.begin(), cell.sourceFaces.end(), 0);
  for (const int sourceFace : cell.sourceFaces) {
    cell.sourceCharts.push_back(test_projection_chart(0, sourceFace));
  }
  cell.sideEdgeCounts = sideCounts;
  cell.sideFamilies.resize(sideCounts.size());
  for (int i = 0; i < static_cast<int>(sideCounts.size()); ++i) {
    cell.sideFamilies[static_cast<std::size_t>(i)] = i & 1;
  }
  cell.disk = true;
  cell.closed = true;
  cell.boundaryCycle = true;
  cell.boundaryComponentCount = 1;
  cell.eulerCharacteristic = 1;
  cell.signedArea = 1.0;

  int side = 0;
  int sideEnd = sideCounts[0];
  for (int i = 0; i < boundaryCount; ++i) {
    if (i == sideEnd) {
      ++side;
      sideEnd += sideCounts[static_cast<std::size_t>(side)];
    }
    auto &node = fixture.complex.nodes[static_cast<std::size_t>(i)];
    node.id = i;
    node.sourceFace = i;
    node.sourceTopologyRegion = test_topology_region_id(2);
    node.sourceChart = test_projection_chart(0, i);
    node.barycentric << 0.0, 1.0, 0.0;
    directional::geometry::SurfaceArrangementNodeOccurrence previousFace;
    previousFace.sourceFace = (i + boundaryCount - 1) % boundaryCount;
    previousFace.sourceTopologyRegion = test_topology_region_id(2);
    previousFace.sourceChart =
        test_projection_chart(0, previousFace.sourceFace);
    previousFace.barycentric << 0.0, 0.0, 1.0;
    node.occurrences.push_back(previousFace);
    node.hardBarrierCrossing = hardBarrier && i == 0;

    auto &edge = fixture.complex.halfedges[static_cast<std::size_t>(i)];
    edge.id = i;
    edge.from = i;
    edge.to = (i + 1) % boundaryCount;
    edge.next = (i + 1) % boundaryCount;
    edge.cell = 0;
    edge.family = side & 1;
    edge.sourceFace = i;
    edge.sourceTopologyRegion = test_topology_region_id(2);
    edge.sourceChart = test_projection_chart(0, i);
    edge.railId = directional::tests::test_hard_rail_id(side);
    edge.curveId = 100 + side;
    edge.hardFeature = side == 0;
    cell.halfedges.push_back(i);
  }
  fixture.complex.cells.push_back(std::move(cell));
  return fixture;
}

Fixture make_authoritative_patch(const std::vector<int> &sideCounts) {
  Fixture fixture = make_patch(sideCounts);
  auto &interior = fixture.complex.cells.front();
  interior.boundaryCycle = false;
  interior.cellClass =
      directional::geometry::SurfaceArrangementCellClass::PatchCandidate;
  interior.signedArea = std::abs(interior.signedArea);

  const int edgeCount = static_cast<int>(fixture.complex.halfedges.size());
  directional::geometry::SurfaceArrangementCell exterior = interior;
  exterior.id = 1;
  exterior.boundaryCycle = true;
  exterior.cellClass =
      directional::geometry::SurfaceArrangementCellClass::Exterior;
  exterior.signedArea = -std::abs(interior.signedArea);
  exterior.halfedges.clear();

  fixture.complex.halfedges.reserve(static_cast<std::size_t>(2 * edgeCount));
  for (int edgeId = 0; edgeId < edgeCount; ++edgeId) {
    auto twin = fixture.complex.halfedges[static_cast<std::size_t>(edgeId)];
    twin.id = edgeCount + edgeId;
    twin.from = fixture.complex.halfedges[static_cast<std::size_t>(edgeId)].to;
    twin.to = fixture.complex.halfedges[static_cast<std::size_t>(edgeId)].from;
    twin.twin = edgeId;
    twin.cell = exterior.id;
    twin.next = edgeCount + (edgeId + edgeCount - 1) % edgeCount;
    fixture.complex.halfedges[static_cast<std::size_t>(edgeId)].twin = twin.id;
    fixture.complex.halfedges.push_back(std::move(twin));
  }
  for (int offset = 0; offset < edgeCount; ++offset) {
    exterior.halfedges.push_back(
        edgeCount + (edgeCount - offset) % edgeCount);
  }
  fixture.complex.cells.push_back(std::move(exterior));
  fixture.complex.diagnostics.incidenceValid = true;
  fixture.complex.diagnostics.topologyValid = true;
  return fixture;
}

directional::geometry::SurfaceCellComplexCompletionResult
complete_fixture_with_source_authority(
    directional::geometry::SurfaceCellComplex complex,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces) {
  bind_patch_charts_to_source_topology(faces, complex);

  directional::geometry::SurfaceCellTracingOptions authorityOptions;
  authorityOptions.sourceFaceComponents.assign(
      static_cast<std::size_t>(faces.rows()), 0);
  authorityOptions.sourceFaceSheets.assign(
      static_cast<std::size_t>(faces.rows()), 0);
  const auto authority =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(faces, authorityOptions);
  if (!authority.has_value()) {
    throw std::runtime_error(
        "Failed to construct completion source authority for fixture.");
  }

  const auto region_for_face = [&](const int sourceFace) {
    const auto row = directional::authority::SourceFaceId::from_index(
        sourceFace, static_cast<std::size_t>(faces.rows()));
    if (!row) {
      throw std::runtime_error("Invalid fixture source-face row.");
    }
    return authority->region_for_row(row.value());
  };
  for (auto &node : complex.nodes) {
    if (node.sourceFace >= 0) {
      node.sourceTopologyRegion = region_for_face(node.sourceFace);
    }
    for (auto &occurrence : node.occurrences) {
      if (occurrence.sourceFace >= 0) {
        occurrence.sourceTopologyRegion = region_for_face(occurrence.sourceFace);
      }
    }
  }
  for (auto &edge : complex.halfedges) {
    if (edge.sourceFace >= 0) {
      edge.sourceTopologyRegion = region_for_face(edge.sourceFace);
    }
    for (auto &provenance : edge.provenance) {
      if (provenance.sourceFace >= 0) {
        provenance.sourceTopologyRegion = region_for_face(provenance.sourceFace);
      }
    }
  }
  for (auto &cell : complex.cells) {
    if (cell.sourceFace >= 0) {
      cell.sourceTopologyRegion = region_for_face(cell.sourceFace);
    }
  }
  if (!directional::geometry::canonicalize_surface_cell_ownership(
          complex, faces)) {
    throw std::runtime_error(
        "Failed to canonicalize completion fixture ownership.");
  }

  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.sourceAuthority = &authority.value();
  return directional::geometry::complete_surface_cell_complex(
      std::move(complex), vertices, faces, options);
}


void append_authoritative_component(
    const directional::geometry::SurfaceCellComplex &component,
    directional::geometry::SurfaceCellComplex &destination) {
  const int nodeOffset = static_cast<int>(destination.nodes.size());
  const int edgeOffset = static_cast<int>(destination.halfedges.size());
  const int cellOffset = static_cast<int>(destination.cells.size());

  for (auto node : component.nodes) {
    node.id += nodeOffset;
    destination.nodes.push_back(std::move(node));
  }
  for (auto edge : component.halfedges) {
    edge.id += edgeOffset;
    edge.from += nodeOffset;
    edge.to += nodeOffset;
    edge.twin += edgeOffset;
    edge.next += edgeOffset;
    edge.cell += cellOffset;
    destination.halfedges.push_back(std::move(edge));
  }
  for (auto cell : component.cells) {
    cell.id += cellOffset;
    for (int &edge : cell.halfedges) {
      edge += edgeOffset;
    }
    destination.cells.push_back(std::move(cell));
  }
}

void append_fixture_component(const Fixture &component, Fixture &destination,
                              const bool shareCenterVertex,
                              const Eigen::RowVector3d &translation) {
  std::vector<int> vertexMap(static_cast<std::size_t>(component.V.rows()), -1);
  const int originalVertexCount = static_cast<int>(destination.V.rows());
  const int firstComponentVertex = shareCenterVertex ? 1 : 0;
  const int addedVertices = component.V.rows() - firstComponentVertex;
  destination.V.conservativeResize(originalVertexCount + addedVertices, 3);
  if (shareCenterVertex) {
    ASSERT_GT(originalVertexCount, 0);
    vertexMap[0] = 0;
  }
  for (int vertex = firstComponentVertex; vertex < component.V.rows(); ++vertex) {
    const int destinationVertex =
        originalVertexCount + vertex - firstComponentVertex;
    vertexMap[static_cast<std::size_t>(vertex)] = destinationVertex;
    destination.V.row(destinationVertex) = component.V.row(vertex) + translation;
  }

  const int faceOffset = static_cast<int>(destination.F.rows());
  destination.F.conservativeResize(faceOffset + component.F.rows(), 3);
  for (int face = 0; face < component.F.rows(); ++face) {
    for (int corner = 0; corner < 3; ++corner) {
      destination.F(faceOffset + face, corner) =
          vertexMap[static_cast<std::size_t>(component.F(face, corner))];
    }
  }

  directional::geometry::SurfaceCellComplex remapped = component.complex;
  for (auto &node : remapped.nodes) {
    if (node.sourceFace >= 0) {
      node.sourceFace += faceOffset;
    }
    for (auto &occurrence : node.occurrences) {
      if (occurrence.sourceFace >= 0) {
        occurrence.sourceFace += faceOffset;
      }
    }
  }
  for (auto &edge : remapped.halfedges) {
    if (edge.sourceFace >= 0) {
      edge.sourceFace += faceOffset;
    }
    for (auto &provenance : edge.provenance) {
      if (provenance.sourceFace >= 0) {
        provenance.sourceFace += faceOffset;
      }
    }
  }
  for (auto &cell : remapped.cells) {
    if (cell.sourceFace >= 0) {
      cell.sourceFace += faceOffset;
    }
    for (int &sourceFace : cell.sourceFaces) {
      sourceFace += faceOffset;
    }
  }
  append_authoritative_component(remapped, destination.complex);
}


Fixture make_two_odd_cells_with_shared_interface() {
  Fixture fixture;
  fixture.V.resize(4, 3);
  fixture.V << 0.0, 0.0, 0.0,
               1.0, 0.0, 0.0,
               1.0, 1.0, 0.0,
               0.0, 1.0, 0.0;
  fixture.F.resize(2, 3);
  fixture.F << 0, 1, 2,
               0, 2, 3;

  fixture.complex.nodes.resize(4);
  const std::array<Eigen::RowVector3d, 4> face0Bary{{
      Eigen::RowVector3d(1.0, 0.0, 0.0),
      Eigen::RowVector3d(0.0, 1.0, 0.0),
      Eigen::RowVector3d(0.0, 0.0, 1.0),
      Eigen::RowVector3d::Constant(
          std::numeric_limits<double>::quiet_NaN())}};
  const std::array<Eigen::RowVector3d, 4> face1Bary{{
      Eigen::RowVector3d(1.0, 0.0, 0.0),
      Eigen::RowVector3d::Constant(
          std::numeric_limits<double>::quiet_NaN()),
      Eigen::RowVector3d(0.0, 1.0, 0.0),
      Eigen::RowVector3d(0.0, 0.0, 1.0)}};
  for (int vertex = 0; vertex < 4; ++vertex) {
    auto &node = fixture.complex.nodes[static_cast<std::size_t>(vertex)];
    node.id = vertex;
    node.sourceTopologyRegion = test_topology_region_id(0);
    if (face0Bary[static_cast<std::size_t>(vertex)].allFinite()) {
      node.sourceFace = 0;
      node.sourceChart = test_projection_chart(0, 0);
      node.barycentric = face0Bary[static_cast<std::size_t>(vertex)];
      directional::geometry::SurfaceArrangementNodeOccurrence occurrence;
      occurrence.sourceFace = 0;
      occurrence.sourceTopologyRegion = test_topology_region_id(0);
      occurrence.sourceChart = test_projection_chart(0, 0);
      occurrence.barycentric = face0Bary[static_cast<std::size_t>(vertex)];
      node.occurrences.push_back(std::move(occurrence));
    }
    if (face1Bary[static_cast<std::size_t>(vertex)].allFinite()) {
      if (node.sourceFace < 0) {
        node.sourceFace = 1;
        node.sourceChart = test_projection_chart(0, 1);
        node.barycentric = face1Bary[static_cast<std::size_t>(vertex)];
      }
      directional::geometry::SurfaceArrangementNodeOccurrence occurrence;
      occurrence.sourceFace = 1;
      occurrence.sourceTopologyRegion = test_topology_region_id(0);
      occurrence.sourceChart = test_projection_chart(0, 1);
      occurrence.barycentric = face1Bary[static_cast<std::size_t>(vertex)];
      node.occurrences.push_back(std::move(occurrence));
    }
  }

  fixture.complex.halfedges.resize(10);
  const auto configureHalfedge = [&](const int id, const int twin,
                                     const int from, const int to,
                                     const int cell, const int next,
                                     const int sourceFace, const int family,
                                     const bool hardFeature) {
    auto &edge = fixture.complex.halfedges[static_cast<std::size_t>(id)];
    edge.id = id;
    edge.twin = twin;
    edge.from = from;
    edge.to = to;
    edge.cell = cell;
    edge.next = next;
    edge.sourceFace = sourceFace;
    edge.sourceArc = id / 2;
    edge.family = family;
    edge.strand = id / 2;
    edge.sourceTopologyRegion = test_topology_region_id(0);
    edge.sourceChart = test_projection_chart(0, sourceFace);
    edge.hardFeature = hardFeature;
    directional::geometry::SurfaceArrangementProvenance provenance;
    provenance.sourceArc = edge.sourceArc;
    provenance.sourceFace = sourceFace;
    provenance.family = family;
    provenance.strand = edge.strand;
    provenance.sourceTopologyRegion = test_topology_region_id(0);
    provenance.sourceChart = test_projection_chart(0, sourceFace);
    edge.provenance.push_back(provenance);
  };

  // Bounded cell 0: 0 -> 1 -> 2 -> 0.
  configureHalfedge(0, 1, 0, 1, 0, 2, 0, 0, true);
  configureHalfedge(2, 3, 1, 2, 0, 4, 0, 1, true);
  configureHalfedge(4, 5, 2, 0, 0, 0, 0, 0, false);
  // Bounded cell 1: 0 -> 2 -> 3 -> 0.
  configureHalfedge(5, 4, 0, 2, 1, 6, 1, 0, false);
  configureHalfedge(6, 7, 2, 3, 1, 8, 1, 1, true);
  configureHalfedge(8, 9, 3, 0, 1, 5, 1, 0, true);
  // Exterior boundary cycle: 1 -> 0 -> 3 -> 2 -> 1.
  configureHalfedge(1, 0, 1, 0, 2, 9, 0, 0, true);
  configureHalfedge(9, 8, 0, 3, 2, 7, 1, 1, true);
  configureHalfedge(7, 6, 3, 2, 2, 3, 1, 0, true);
  configureHalfedge(3, 2, 2, 1, 2, 1, 0, 1, true);

  fixture.complex.cells.resize(3);
  const auto configureCell = [&](const int id, std::vector<int> halfedges,
                                 const int sourceFace,
                                 const bool boundaryCycle) {
    auto &cell = fixture.complex.cells[static_cast<std::size_t>(id)];
    cell.id = id;
    cell.sourceFace = sourceFace;
    if (sourceFace >= 0) {
      cell.sourceTopologyRegion = test_topology_region_id(0);
      cell.sourceFaces = {sourceFace};
      cell.sourceCharts = {test_projection_chart(0, sourceFace)};
    }
    cell.halfedges = std::move(halfedges);
    cell.sideFamilies = boundaryCycle ? std::vector<int>{0, 1, 0, 1}
                                      : std::vector<int>{0, 1, 0};
    cell.sideEdgeCounts.assign(cell.sideFamilies.size(), 1);
    cell.boundaryCycle = boundaryCycle;
    cell.closed = true;
    cell.disk = true;
    cell.boundaryComponentCount = 1;
    cell.eulerCharacteristic = 1;
    cell.cellClass = boundaryCycle
                         ? directional::geometry::SurfaceArrangementCellClass::Exterior
                         : directional::geometry::SurfaceArrangementCellClass::PatchCandidate;
  };
  configureCell(0, {0, 2, 4}, 0, false);
  configureCell(1, {5, 6, 8}, 1, false);
  configureCell(2, {1, 9, 7, 3}, 0, true);
  auto &exterior = fixture.complex.cells[2];
  exterior.sourceFaces = {0, 1};
  exterior.sourceCharts = {
      test_projection_chart(0, 0),
      test_projection_chart(0, 1),
  };
  exterior.sourceTopologyRegion = test_topology_region_id(0);
  fixture.complex.cells[0].signedArea = 0.5;
  fixture.complex.cells[0].area = 0.5;
  fixture.complex.cells[1].signedArea = 0.5;
  fixture.complex.cells[1].area = 0.5;
  fixture.complex.cells[2].signedArea = -1.0;
  fixture.complex.cells[2].area = 1.0;

  auto &diagnostics = fixture.complex.diagnostics;
  diagnostics.embeddingValid = true;
  diagnostics.sourceEulerCharacteristic = 1;
  diagnostics.sourceConnectedComponentCount = 1;
  diagnostics.sourceBoundaryLoopCount = 1;
  diagnostics.supportedArea = 1.0;
  diagnostics.inputMemoryBytes = 1;
  diagnostics.unsplitCrossings = 0;
  diagnostics.geometricTJunctions = 0;
  // Manual DCEL fixtures enter production transactions through the same
  // canonical ownership boundary as generated arrangements. Establish that
  // baseline before deriving topology diagnostics so parity repair is tested
  // against a valid committed complex rather than a legacy pre-canonical
  // representation.
  bind_patch_charts_to_source_topology(fixture.F, fixture.complex);
  if (!directional::geometry::canonicalize_surface_cell_ownership(
          fixture.complex, fixture.F)) {
    diagnostics.embeddingValid = false;
  }
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(fixture.complex);
  return fixture;
}

Fixture make_same_corner_distinct_boundary_components() {
  const Fixture component = make_authoritative_patch({1, 1, 1, 1});
  Fixture fixture;
  fixture.V = component.V;
  fixture.F = component.F;
  append_authoritative_component(component.complex, fixture.complex);

  directional::geometry::SurfaceCellComplex alternate = component.complex;
  for (auto &edge : alternate.halfedges) {
    if (edge.railId.has_value()) {
      edge.railId = directional::tests::test_hard_rail_id(
          static_cast<int>(edge.railId->index()) + 1000);
    }
    edge.curveId += 2000;
    edge.proposalBoundarySegment += 3000;
    for (auto &provenance : edge.provenance) {
      if (provenance.railId.has_value()) {
        provenance.railId = directional::tests::test_hard_rail_id(
            static_cast<int>(provenance.railId->index()) + 1000);
      }
      provenance.curveId += 2000;
      provenance.proposalBoundarySegment += 3000;
    }
  }
  append_authoritative_component(alternate, fixture.complex);

  // This fixture is intentionally an overlapping ownership input. Derive
  // its diagnostics from the constructed DCEL instead of setting validity
  // flags. The production path must reject it before candidate expansion.
  fixture.complex.diagnostics.sourceEulerCharacteristic = 1;
  fixture.complex.diagnostics.sourceConnectedComponentCount = 1;
  fixture.complex.diagnostics.sourceBoundaryLoopCount = 1;
  fixture.complex.diagnostics.supportedArea = 1.0;
  fixture.complex.diagnostics.inputMemoryBytes = 1;
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(fixture.complex);
  return fixture;
}


Fixture make_valid_parallel_route_same_corner_complex() {
  Fixture fixture;
  // A triangulated annular source support.  Both arrangement domains use the
  // same four authoritative corner vertices, but their boundary curves carry
  // different complete face-route provenance through the annulus.
  fixture.V.resize(8, 3);
  fixture.V << -2.0, -2.0, 0.0,
                2.0, -2.0, 0.0,
                2.0,  2.0, 0.0,
               -2.0,  2.0, 0.0,
               -0.7, -0.7, 0.0,
                0.7, -0.7, 0.0,
                0.7,  0.7, 0.0,
               -0.7,  0.7, 0.0;
  fixture.F.resize(8, 3);
  fixture.F << 0, 1, 5,
               0, 5, 4,
               1, 2, 6,
               1, 6, 5,
               2, 3, 7,
               2, 7, 6,
               3, 0, 4,
               3, 4, 7;

  fixture.complex.nodes.resize(4);
  for (int vertex = 0; vertex < 4; ++vertex) {
    auto &node = fixture.complex.nodes[static_cast<std::size_t>(vertex)];
    node.id = vertex;
    node.sourceTopologyRegion = test_topology_region_id(0);
    for (int face = 0; face < fixture.F.rows(); ++face) {
      for (int corner = 0; corner < 3; ++corner) {
        if (fixture.F(face, corner) != vertex) continue;
        Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
        barycentric(corner) = 1.0;
        if (node.sourceFace < 0) {
          node.sourceFace = face;
          node.sourceChart = test_projection_chart(0, face);
          node.barycentric = barycentric;
        }
        directional::geometry::SurfaceArrangementNodeOccurrence occurrence;
        occurrence.sourceFace = face;
        occurrence.barycentric = barycentric;
        occurrence.sourceTopologyRegion = test_topology_region_id(0);
        occurrence.sourceChart = test_projection_chart(0, face);
        node.occurrences.push_back(std::move(occurrence));
      }
    }
  }

  fixture.complex.halfedges.resize(16);
  const auto configureEdge = [&](const int id, const int twin, const int from,
                                 const int to, const int cell, const int next,
                                 const int side, const bool alternateRoute) {
    auto &edge = fixture.complex.halfedges[static_cast<std::size_t>(id)];
    edge.id = id;
    edge.twin = twin;
    edge.from = from;
    edge.to = to;
    edge.cell = cell;
    edge.next = next;
    edge.family = side & 1;
    edge.sourceFace = 2 * side;
    edge.sourceArc = 100 * (alternateRoute ? 2 : 1) + side;
    edge.strand = edge.sourceArc;
    edge.sourceTopologyRegion = test_topology_region_id(0);
    edge.sourceChart = test_projection_chart(0, edge.sourceFace);
    edge.railId = directional::tests::test_hard_rail_id(
        (alternateRoute ? 1000 : 0) + side);
    edge.curveId = (alternateRoute ? 2000 : 1000) + side;
    edge.sourceT0 = 0.0;
    edge.sourceT1 = 1.0;
    const auto addProvenance = [&](const int face, const int ordinal) {
      directional::geometry::SurfaceArrangementProvenance provenance;
      provenance.sourceArc = edge.sourceArc + ordinal;
      provenance.sourceFace = face;
      provenance.family = edge.family;
      provenance.strand = edge.strand;
      provenance.sourceTopologyRegion = test_topology_region_id(0);
      provenance.sourceChart = test_projection_chart(0, face);
      provenance.railId = edge.railId;
      provenance.curveId = edge.curveId;
      provenance.sourceT0 = 0.0;
      provenance.sourceT1 = 1.0;
      edge.provenance.push_back(provenance);
    };
    addProvenance(2 * side, 0);
    if (alternateRoute) {
      addProvenance(2 * side + 1, 1);
      addProvenance((2 * ((side + 1) % 4) + 1) % 8, 2);
    }
  };

  // Domain A and its exterior twin loop.
  configureEdge(0, 1, 0, 1, 0, 2, 0, false);
  configureEdge(2, 3, 1, 2, 0, 4, 1, false);
  configureEdge(4, 5, 2, 3, 0, 6, 2, false);
  configureEdge(6, 7, 3, 0, 0, 0, 3, false);
  configureEdge(1, 0, 1, 0, 1, 7, 0, false);
  configureEdge(7, 6, 0, 3, 1, 5, 3, false);
  configureEdge(5, 4, 3, 2, 1, 3, 2, false);
  configureEdge(3, 2, 2, 1, 1, 1, 1, false);

  // Domain B has the same authoritative corners but a distinct complete
  // embedded route on every side.  Both completions are closed-form quads, so
  // no rotation variant can bypass the initial same-corner claim.
  configureEdge(8, 9, 0, 1, 2, 10, 0, true);
  configureEdge(10, 11, 1, 2, 2, 12, 1, true);
  configureEdge(12, 13, 2, 3, 2, 14, 2, true);
  configureEdge(14, 15, 3, 0, 2, 8, 3, true);
  configureEdge(9, 8, 1, 0, 3, 15, 0, true);
  configureEdge(15, 14, 0, 3, 3, 13, 3, true);
  configureEdge(13, 12, 3, 2, 3, 11, 2, true);
  configureEdge(11, 10, 2, 1, 3, 9, 1, true);

  fixture.complex.cells.resize(4);
  const std::vector<int> allFaces{0, 1, 2, 3, 4, 5, 6, 7};
  const auto configureCell = [&](const int id, std::vector<int> halfedges,
                                 const bool exterior) {
    auto &cell = fixture.complex.cells[static_cast<std::size_t>(id)];
    cell.id = id;
    cell.sourceFace = 0;
    cell.sourceTopologyRegion = test_topology_region_id(0);
    cell.sourceFaces = allFaces;
    for (const int sourceFace : allFaces) {
      cell.sourceCharts.push_back(test_projection_chart(0, sourceFace));
    }
    cell.halfedges = std::move(halfedges);
    cell.sideFamilies = {0, 1, 0, 1};
    cell.sideEdgeCounts = {1, 1, 1, 1};
    cell.boundaryCycle = exterior;
    cell.closed = true;
    cell.disk = true;
    cell.boundaryComponentCount = 1;
    cell.eulerCharacteristic = 1;
    cell.signedArea = exterior ? -3.0 : 3.0;
    cell.area = 3.0;
    cell.cellClass = exterior
        ? directional::geometry::SurfaceArrangementCellClass::Exterior
        : directional::geometry::SurfaceArrangementCellClass::PatchCandidate;
  };
  configureCell(0, {0, 2, 4, 6}, false);
  configureCell(1, {1, 7, 5, 3}, true);
  configureCell(2, {8, 10, 12, 14}, false);
  configureCell(3, {9, 15, 13, 11}, true);

  auto &diagnostics = fixture.complex.diagnostics;
  diagnostics.embeddingValid = true;
  diagnostics.sourceEulerCharacteristic = 0;
  diagnostics.sourceConnectedComponentCount = 1;
  diagnostics.sourceBoundaryLoopCount = 2;
  diagnostics.supportedArea = 6.0;
  diagnostics.inputMemoryBytes = 1;
  diagnostics.unsplitCrossings = 0;
  diagnostics.geometricTJunctions = 0;
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(fixture.complex);
  return fixture;
}

} // namespace

TEST(PatchDescriptorMilestoneE, DerivesOrderedSidesSubdivisionsAndFeatures) {
  const Fixture fixture = make_patch({2, 3, 2, 3});
  const auto descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);

  ASSERT_TRUE(descriptor.boundaryCycleValid);
  ASSERT_EQ(descriptor.sides.size(), 4U);
  EXPECT_EQ(descriptor.patch.sideEdgeCounts,
            (std::vector<int>{2, 3, 2, 3}));
  EXPECT_EQ(descriptor.patch.turns, (std::vector<int>{1, 1, 1, 1}));
  EXPECT_EQ(descriptor.patch.boundaryVertices.size(), 10U);
  EXPECT_EQ(descriptor.patch.boundaryProvenance.size(), 10U);
  EXPECT_TRUE(descriptor.sides.front().hardFeature);
  EXPECT_EQ(descriptor.sides.front().railIds,
            (std::set<directional::authority::HardRailId>{
                directional::tests::test_hard_rail_id(0)}));
  EXPECT_EQ(descriptor.sides.front().curveIds,
            (std::set<int>{100}));
  EXPECT_TRUE(descriptor.feasibility.admissible);
}

TEST(PatchDescriptorMilestoneE, SupportsThreeFourFiveAndSixSidedPatches) {
  const std::vector<std::vector<int>> cases = {
      {2, 1, 1}, {2, 3, 2, 3}, {2, 1, 1, 1, 1}, {2, 2, 1, 1, 1, 1}};
  for (const auto &counts : cases) {
    const Fixture fixture = make_patch(counts);
    const auto descriptor = directional::geometry::derive_patch_descriptor(
        fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
    EXPECT_EQ(descriptor.sides.size(), counts.size());
    EXPECT_EQ(descriptor.patch.sideEdgeCounts, counts);
    EXPECT_TRUE(descriptor.feasibility.admissible)
        << "side count " << counts.size();
  }
}

TEST(PatchDescriptorMilestoneE, RejectsOddBoundaryAndHardBarrierCrossing) {
  {
    const Fixture fixture = make_patch({1, 1, 1});
    const auto descriptor = directional::geometry::derive_patch_descriptor(
        fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
    EXPECT_EQ(descriptor.feasibility.reason,
              directional::geometry::PureQuadPatchRejectReason::OddBoundary);
  }
  {
    const Fixture fixture = make_patch({2, 2, 2}, true);
    const auto descriptor = directional::geometry::derive_patch_descriptor(
        fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
    EXPECT_FALSE(descriptor.featureConstraintsValid);
    EXPECT_EQ(
        descriptor.feasibility.reason,
        directional::geometry::PureQuadPatchRejectReason::HardFeatureCrossing);
  }
}

TEST(PatchDescriptorMilestoneE,
     SharedEdgeParityRepairConforminglyCompletesTwoOddCells) {
  const Fixture fixture = make_two_odd_cells_with_shared_interface();
  const Eigen::MatrixXd &V = fixture.V;
  const Eigen::MatrixXi &F = fixture.F;
  const directional::geometry::SurfaceCellComplex &complex = fixture.complex;
  const auto initialIncidence =
      directional::geometry::surface_simplification_detail::audit_complex_incidence(complex);
  ASSERT_TRUE(initialIncidence.valid)
      << directional::geometry::surface_simplification_detail::surface_cell_incidence_failure_name(
             initialIncidence.failure)
      << " cell=" << initialIncidence.cell
      << " halfedge=" << initialIncidence.halfedge
      << " twin=" << initialIncidence.twin
      << " next=" << initialIncidence.next;
  ASSERT_TRUE(complex.diagnostics.topologyValid);
  ASSERT_TRUE(
      directional::geometry::validate_surface_cell_ownership_registry(complex));
  for (const auto &cell : complex.cells) {
    ASSERT_TRUE(cell.sourceTopologyRegion.has_value())
        << "cell=" << cell.id;
    ASSERT_FALSE(cell.sourceFaces.empty()) << "cell=" << cell.id;
    ASSERT_EQ(cell.sourceFaces.size(), cell.sourceCharts.size())
        << "cell=" << cell.id;
    for (std::size_t index = 0; index < cell.sourceFaces.size(); ++index) {
      const auto expectedChart = canonical_projection_chart_for_source_row(
          F, cell.sourceFaces[index], cell.sourceCharts[index].chart);
      EXPECT_EQ(expectedChart, cell.sourceCharts[index])
          << "cell=" << cell.id << " sourceFace=" << cell.sourceFaces[index];
    }
  }
  const int oddBefore = static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && cell.halfedges.size() % 2U != 0U;
      }));
  ASSERT_EQ(2, oddBefore);

  const auto repairedResult =
      directional::geometry::repair_surface_cell_boundary_parity(complex);
  ASSERT_TRUE(repairedResult.is_produced());
  const auto &repaired = repairedResult.product();
  EXPECT_EQ(2, repaired.oddCellsBefore);
  EXPECT_EQ(0, repaired.oddCellsAfter);
  EXPECT_FALSE(repaired.splitHalfedges.empty());
  EXPECT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(repaired.complex));
  for (const auto &cell : repaired.complex.cells) {
    if (!cell.boundaryCycle) {
      EXPECT_EQ(0U, cell.halfedges.size() % 2U);
    }
  }

  directional::geometry::SurfaceCellTracingOptions sourceAuthorityOptions;
  sourceAuthorityOptions.sourceFaceComponents = {0, 0};
  sourceAuthorityOptions.sourceFaceSheets = {0, 0};
  const auto sourceAuthority =
      directional::geometry::surface_cell_tracing_detail::
          build_source_topology_regions(F, sourceAuthorityOptions);
  ASSERT_TRUE(sourceAuthority.has_value());
  ASSERT_TRUE(sourceAuthority->matches_source_faces(
      F, static_cast<std::size_t>(V.rows())));
  directional::geometry::SurfaceCellComplexCompletionOptions completionOptions;
  completionOptions.sourceAuthority = &sourceAuthority.value();
  const auto completion =
      directional::geometry::complete_surface_cell_complex(
          complex, V, F, completionOptions);
  ASSERT_TRUE(completion.is_produced());
  EXPECT_EQ(2, completion.parityOddCellsBefore);
  EXPECT_EQ(0, completion.parityOddCellsAfter);
  EXPECT_GT(completion.paritySplitEdges, 0);
  EXPECT_TRUE(completion.product().hasPreparedComplex);
  EXPECT_FALSE(completion.product().assembly.mesh.quads.empty());

  int sharedInterior = -1;
  for (const auto &edge : repaired.complex.halfedges) {
    if (edge.id > edge.twin) {
      continue;
    }
    const auto &twin = repaired.complex.halfedges[
        static_cast<std::size_t>(edge.twin)];
    if (!repaired.complex.cells[static_cast<std::size_t>(edge.cell)]
             .boundaryCycle &&
        !repaired.complex.cells[static_cast<std::size_t>(twin.cell)]
             .boundaryCycle) {
      sharedInterior = edge.id;
      break;
    }
  }
  ASSERT_GE(sharedInterior, 0);
  const auto perturbedResult =
      directional::geometry::subdivide_surface_cell_complex_edges(
          repaired.complex, {{sharedInterior, 1}});
  ASSERT_TRUE(perturbedResult.is_produced());
  const auto &perturbed = perturbedResult.product();
  const auto sideRepairResult =
      directional::geometry::repair_surface_cell_side_subdivisions(
          perturbed.complex, V, F);
  ASSERT_TRUE(sideRepairResult.is_produced());
  const auto &sideRepair = sideRepairResult.product();
  EXPECT_GT(sideRepair.infeasibleCellsBefore, 0);
  EXPECT_EQ(0, sideRepair.infeasibleCellsAfter);
  EXPECT_GT(sideRepair.insertedVertices, 0);
  EXPECT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(sideRepair.complex));
  const auto descriptors = directional::geometry::derive_patch_descriptors(
      sideRepair.complex, V, F);
  for (const auto &descriptor : descriptors.descriptors) {
    EXPECT_NE(directional::geometry::PureQuadPatchRejectReason::OddBoundary,
              descriptor.feasibility.reason);
    EXPECT_NE(directional::geometry::PureQuadPatchRejectReason::SideInequality,
              descriptor.feasibility.reason);
    EXPECT_NE(directional::geometry::PureQuadPatchRejectReason::HexParity,
              descriptor.feasibility.reason);
  }
}

TEST(PatchDescriptorMilestoneE,
     ParityRepairInvalidIncidenceRejectsWithoutConsumableProduct) {
  Fixture fixture = make_two_odd_cells_with_shared_interface();
  ASSERT_FALSE(fixture.complex.halfedges.empty());
  fixture.complex.halfedges.front().twin = -1;

  const auto result =
      directional::geometry::repair_surface_cell_boundary_parity(
          fixture.complex);

  ASSERT_TRUE(result.is_rejected());
  EXPECT_FALSE(result.is_produced());
  EXPECT_FALSE(result.is_not_applicable());
  EXPECT_EQ(nullptr, result.produced_product());
  const auto *failure = result.rejection();
  ASSERT_NE(nullptr, failure);
  EXPECT_EQ(
      directional::geometry::SurfaceCellParityRepairFailureKind::
          InvalidInputIncidence,
      failure->kind);
  EXPECT_EQ("InvalidInputIncidence", failure->detail);
}

TEST(PatchDescriptorMilestoneE,
     FiveSidedRepairUsesBoundedClosedFormInsteadOfCompositionSearch) {
  const Fixture fixture = make_authoritative_patch({20, 1, 1, 1, 1});
  const auto before = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
  ASSERT_EQ(5U, before.sides.size());
  ASSERT_EQ(directional::geometry::PureQuadPatchRejectReason::SideInequality,
            before.feasibility.reason);

  const auto repairedResult =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F);
  ASSERT_TRUE(repairedResult.is_produced());
  const auto &repaired = repairedResult.product();
  EXPECT_EQ(1, repaired.infeasibleCellsBefore);
  EXPECT_EQ(0, repaired.infeasibleCellsAfter);
  EXPECT_GT(repaired.insertedVertices, 0);
  EXPECT_LE(repaired.insertedVertices, 36);
  EXPECT_EQ(repaired.insertedVertices, repaired.attemptedInsertions);
  EXPECT_EQ(0, repaired.finalEquationDefect);

  const auto after = directional::geometry::derive_patch_descriptor(
      repaired.complex, repaired.complex.cells.front(), fixture.V, fixture.F);
  ASSERT_EQ(5U, after.sides.size());
  const int repairedBoundary =
      std::accumulate(after.patch.sideEdgeCounts.begin(),
                      after.patch.sideEdgeCounts.end(), 0);
  EXPECT_EQ(0, repairedBoundary % 2);
  EXPECT_LE(repairedBoundary, 60);
  EXPECT_TRUE(after.feasibility.admissible);
}


TEST(PatchDescriptorMilestoneE,
     SideRepairFallbackPreparationIsProducedBeforeGeneralCompletion) {
  Fixture fixture = make_authoritative_patch({20, 1, 1, 1, 1});
  bind_patch_charts_to_source_topology(fixture.F, fixture.complex);
  ASSERT_TRUE(directional::geometry::canonicalize_surface_cell_ownership(
      fixture.complex, fixture.F));
  ASSERT_TRUE(directional::geometry::validate_surface_cell_ownership_registry(
      fixture.complex));
  const auto incidence =
      directional::geometry::surface_simplification_detail::
          audit_complex_incidence(fixture.complex);
  ASSERT_TRUE(incidence.valid)
      << directional::geometry::surface_simplification_detail::
             surface_cell_incidence_failure_name(incidence.failure);

  const auto &cell = fixture.complex.cells.front();
  const auto domainAudit =
      directional::geometry::audit_surface_cell_domain_identity(
          fixture.complex, cell, cell.halfedges, fixture.F);
  ASSERT_TRUE(domainAudit.valid)
      << directional::geometry::surface_cell_domain_identity_failure_name(
             domainAudit.failure);

  const auto beforeDescriptor =
      directional::geometry::derive_patch_descriptor(
          fixture.complex, cell, fixture.V, fixture.F);
  ASSERT_EQ(5U, beforeDescriptor.sides.size());
  ASSERT_EQ(directional::geometry::PureQuadPatchRejectReason::SideInequality,
            beforeDescriptor.feasibility.reason);

  const std::uint64_t before =
      directional::geometry::surface_simplification_detail::
          complex_structural_hash(fixture.complex);
  directional::geometry::SurfaceCellSideRepairOptions repairOptions;
  repairOptions.maxInsertedVertices = 1;

  const auto result =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F, repairOptions);

  ASSERT_TRUE(result.is_produced());
  EXPECT_FALSE(result.is_rejected());
  EXPECT_FALSE(result.is_not_applicable());
  EXPECT_EQ(nullptr, result.rejection());
  const auto *preparation = result.produced_product();
  ASSERT_NE(nullptr, preparation);
  EXPECT_EQ(
      directional::geometry::SurfaceCellSideRepairProductKind::
          GeneralFallbackPreparation,
      preparation->kind);
  EXPECT_EQ(
      directional::geometry::SurfaceCellSideRepairPreparationReason::
          SideRepairInsertionLimit,
      preparation->preparationReason);
  EXPECT_EQ("SideRepairInsertionLimit", preparation->preparationDetail);
  EXPECT_GT(preparation->attemptedInsertions, 0);
  EXPECT_TRUE(preparation->rollbackEquivalent);
  EXPECT_EQ(preparation->rollbackIdentityHashBefore,
            preparation->rollbackIdentityHashAfter);
  EXPECT_EQ(before,
            directional::geometry::surface_simplification_detail::
                complex_structural_hash(preparation->complex));
}

TEST(PatchDescriptorMilestoneE,
     InvalidSideRepairOptionsRejectWithoutConsumableProduct) {
  const Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  const auto incidence =
      directional::geometry::surface_simplification_detail::
          audit_complex_incidence(fixture.complex);
  ASSERT_TRUE(incidence.valid)
      << directional::geometry::surface_simplification_detail::
             surface_cell_incidence_failure_name(incidence.failure);

  directional::geometry::SurfaceCellSideRepairOptions repairOptions;
  repairOptions.maxInsertedVertices = -1;
  const auto result =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F, repairOptions);

  ASSERT_TRUE(result.is_rejected());
  EXPECT_FALSE(result.is_produced());
  EXPECT_FALSE(result.is_not_applicable());
  EXPECT_EQ(nullptr, result.produced_product());
  const auto *failure = result.rejection();
  ASSERT_NE(nullptr, failure);
  EXPECT_EQ(
      directional::geometry::SurfaceCellSideRepairFailureKind::
          InvalidSideRepairOptions,
      failure->kind);
  EXPECT_EQ("InvalidSideRepairOptions", failure->detail);
  EXPECT_TRUE(failure->rollbackEquivalent);
  EXPECT_EQ(failure->rollbackIdentityHashBefore,
            failure->rollbackIdentityHashAfter);
  EXPECT_TRUE(result.rollback_matches(fixture.complex));
}

TEST(PatchDescriptorMilestoneE,
     SuccessfulSideSubdivisionPreservesCanonicalDomainIdentity) {
  const Fixture fixture = make_authoritative_patch({20, 1, 1, 1, 1});
  const auto repairedResult =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(repairedResult.is_produced());
  const auto &repaired = repairedResult.product();
  ASSERT_GT(repaired.insertedVertices, 0);
  ASSERT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(repaired.complex));

  for (const auto &cell : repaired.complex.cells) {
    if (cell.cellClass ==
        directional::geometry::SurfaceArrangementCellClass::Exterior) {
      continue;
    }
    const auto audit =
        directional::geometry::audit_surface_cell_domain_identity(
            repaired.complex, cell, cell.halfedges, fixture.F);
    EXPECT_TRUE(audit.valid)
        << directional::geometry::surface_cell_domain_identity_failure_name(
               audit.failure)
        << " cell=" << audit.cellId << " halfedge=" << audit.halfedgeId
        << " node=" << audit.nodeId << " sourceFace=" << audit.sourceFace
        << " component=" << audit.sourceComponent
        << " sheet=" << audit.sourceSheet;
  }

  const auto descriptors = directional::geometry::derive_patch_descriptors(
      repaired.complex, fixture.V, fixture.F);
  ASSERT_FALSE(descriptors.ownershipConflict.active());
  ASSERT_FALSE(descriptors.descriptors.empty());
  for (const auto &descriptor : descriptors.descriptors) {
    EXPECT_TRUE(descriptor.domainIdentityAudit.valid);
    EXPECT_TRUE(descriptor.patch.domainIdentity.valid);
  }
}

TEST(PatchDescriptorMilestoneE,
     PermittedSideRepairFailureReturnsExactRollbackForGeneralCompletion) {
  const Fixture fixture = make_authoritative_patch({20, 1, 1, 1, 1});
  const std::uint64_t before =
      directional::geometry::surface_simplification_detail::
          complex_structural_hash(fixture.complex);

  directional::geometry::SurfaceCellSideRepairOptions repairOptions;
  repairOptions.maxInsertedVertices = 1;
  repairOptions.maxLocalInsertedVertices = 512;
  repairOptions.maxPropagationPasses = 4096;
  repairOptions.maxStagnantPasses = 64;
  const auto preparationResult =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F, repairOptions);

  ASSERT_TRUE(preparationResult.is_produced());
  const auto &preparation = preparationResult.product();
  EXPECT_EQ(directional::geometry::SurfaceCellSideRepairProductKind::
                GeneralFallbackPreparation,
            preparation.kind);
  EXPECT_EQ(directional::geometry::SurfaceCellSideRepairPreparationReason::
                SideRepairInsertionLimit,
            preparation.preparationReason);
  EXPECT_EQ("SideRepairInsertionLimit", preparation.preparationDetail);
  EXPECT_GT(preparation.attemptedInsertions, 0);
  EXPECT_TRUE(preparation.rollbackEquivalent);
  EXPECT_EQ(preparation.rollbackIdentityHashBefore,
            preparation.rollbackIdentityHashAfter);
  EXPECT_EQ(before,
            directional::geometry::surface_simplification_detail::
                complex_structural_hash(preparation.complex));

  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.allowBoundedCombinatorialFallback = true;
  options.sideRepairOptions = repairOptions;
  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);
  EXPECT_TRUE(completion.sideRollbackEquivalent);
  EXPECT_EQ(completion.sideRollbackIdentityHashBefore,
            completion.sideRollbackIdentityHashAfter);
  EXPECT_TRUE(completion.is_produced());
  EXPECT_FALSE(completion.product().descriptors.descriptors.empty());
  EXPECT_FALSE(completion.product().assembly.mesh.quads.empty());
  EXPECT_EQ(nullptr, completion.rejection());
}

TEST(PatchDescriptorMilestoneE, RejectsNonDiskAndBrokenBoundaryCycle) {
  Fixture fixture = make_patch({2, 2, 2, 2});
  fixture.complex.cells.front().disk = false;
  auto descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
  EXPECT_EQ(descriptor.feasibility.reason,
            directional::geometry::PureQuadPatchRejectReason::NonDisk);

  fixture = make_patch({2, 2, 2, 2});
  fixture.complex.halfedges.front().to = 3;
  descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
  EXPECT_FALSE(descriptor.boundaryCycleValid);
  EXPECT_EQ(descriptor.feasibility.reason,
            directional::geometry::PureQuadPatchRejectReason::NonDisk);
}

TEST(PatchDescriptorMilestoneE, DerivesCompatibleInteriorSingularityValence) {
  Fixture fixture = make_patch({2, 1, 1});
  directional::geometry::PatchDescriptorOptions options;
  options.singularCycles.resize(1);
  options.singularIndices.resize(1);
  options.singularCycles << 0;
  options.singularIndices << 1;

  auto descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F,
      options);
  ASSERT_TRUE(descriptor.feasibility.admissible);
  EXPECT_EQ(descriptor.patch.singularityCount, 1);
  EXPECT_EQ(descriptor.feasibility.expectedInteriorValence, 3);

  options.singularIndices << -1;
  descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F,
      options);
  EXPECT_EQ(
      descriptor.feasibility.reason,
      directional::geometry::PureQuadPatchRejectReason::SingularityMismatch);
}

TEST(PatchDescriptorMilestoneE, BoundarySingularityDoesNotConsumeInteriorPole) {
  Fixture fixture = make_patch({2, 3, 2, 3});
  directional::geometry::PatchDescriptorOptions options;
  options.singularCycles.resize(1);
  options.singularIndices.resize(1);
  options.singularCycles << 1;
  options.singularIndices << 1;
  const auto descriptor = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F,
      options);
  EXPECT_EQ(descriptor.patch.singularityCount, 0);
  EXPECT_TRUE(descriptor.feasibility.admissible);
}

TEST(PatchDescriptorMilestoneE,
     GlobalDescriptorAssignmentUsesEmbeddedSingularityAsBoundaryTopology) {
  const Fixture fixture = make_authoritative_patch({2, 3, 2, 3});
  directional::geometry::PatchDescriptorOptions options;
  options.singularCycles.resize(1);
  options.singularIndices.resize(1);
  options.singularCycles << 1;
  options.singularIndices << 1;

  const auto descriptors = directional::geometry::derive_patch_descriptors(
      fixture.complex, fixture.V, fixture.F, options);
  ASSERT_TRUE(descriptors.unresolvedSingularVertices.empty());
  ASSERT_EQ(1U, descriptors.descriptors.size());
  EXPECT_EQ(0, descriptors.descriptors.front().patch.singularityCount);
  EXPECT_TRUE(descriptors.descriptors.front().feasibility.admissible);
}

TEST(PatchDescriptorMilestoneE,
     GlobalDescriptorAssignmentRejectsAmbiguousInteriorSingularity) {
  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  const Fixture secondDomain = make_authoritative_patch({2, 2, 2, 2});
  append_fixture_component(secondDomain, fixture, true,
                           Eigen::RowVector3d{2.5, 0.0, 0.0});
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.descriptorOptions.singularCycles.resize(1);
  options.descriptorOptions.singularIndices.resize(1);
  options.descriptorOptions.singularCycles << 0;
  options.descriptorOptions.singularIndices << 1;

  const auto descriptors = directional::geometry::derive_patch_descriptors(
      fixture.complex, fixture.V, fixture.F, options.descriptorOptions);
  ASSERT_EQ((std::vector<int>{0}), descriptors.unresolvedSingularVertices);
  ASSERT_EQ(2U, descriptors.descriptors.size());
  for (const auto &descriptor : descriptors.descriptors) {
    EXPECT_EQ(0, descriptor.patch.singularityCount);
  }

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);
  EXPECT_TRUE(completion.is_rejected());
  ASSERT_NE(nullptr, completion.rejection());
  EXPECT_EQ("UnresolvedSingularityOwnership", completion.rejection()->detail);
  EXPECT_EQ(nullptr, completion.produced_product());
  EXPECT_EQ(
      directional::geometry::SurfaceCellComplexCompletionFailureKind::
          UnresolvedSingularityOwnership,
      completion.rejection()->kind);
}

TEST(PatchDescriptorMilestoneE,
     CompletesAuthoritativeComplexThroughMilestoneEEntryPoint) {
  const Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  const auto completion = complete_fixture_with_source_authority(
      fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(completion.is_produced());
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(0, completion.failedPatches);
  ASSERT_EQ(1U, completion.product().completedPatches.size());
  EXPECT_EQ(4U, completion.product().assembly.mesh.quads.size());
  EXPECT_EQ(1, completion.product().assembly.connectedComponents);
  EXPECT_EQ(1, completion.product().assembly.boundaryLoopCount);
  EXPECT_EQ(1, completion.product().assembly.eulerCharacteristic);
}


TEST(PatchDescriptorMilestoneE,
     ComplexCompletionFailsClosedInsteadOfReturningPartialOutput) {
  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  Fixture invalid = make_authoritative_patch({2, 2, 2, 2});
  invalid.complex.cells.front().disk = false;
  invalid.complex.cells.front().cellClass =
      directional::geometry::SurfaceArrangementCellClass::NonDisk;
  append_fixture_component(invalid, fixture, false,
                           Eigen::RowVector3d{3.0, 0.0, 0.0});

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, {});

  EXPECT_TRUE(completion.is_rejected());
  ASSERT_NE(nullptr, completion.rejection());
  EXPECT_EQ(completion.rejection()->detail.rfind(
                "IncompleteSurfaceCellComplex", 0),
            0U);
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(1, completion.failedPatches);
  EXPECT_EQ(nullptr, completion.produced_product());
}

TEST(PatchDescriptorMilestoneE,
     ExteriorArrangementCyclesAreNotAuthoritativeCompletionPatches) {
  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});

  const auto completion = complete_fixture_with_source_authority(
      fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(completion.is_produced());
  EXPECT_EQ(1U, completion.product().descriptors.descriptors.size());
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(0, completion.failedPatches);
  EXPECT_EQ(1U, completion.product().completedPatches.size());
}


TEST(PatchDescriptorMilestoneE,
     DuplicateDomainsFailBeforePatchCompletion) {
  Fixture fixture = make_authoritative_patch({1, 1, 1, 1});
  directional::geometry::SurfaceCellComplex duplicate;
  append_authoritative_component(fixture.complex, duplicate);
  append_authoritative_component(fixture.complex, duplicate);
  duplicate.cells[0].id = 91;
  duplicate.cells[1].id = 92;
  duplicate.cells[2].id = 401;
  duplicate.cells[3].id = 402;
  for (auto &edge : duplicate.halfedges) {
    if (edge.cell == 0) edge.cell = 91;
    else if (edge.cell == 1) edge.cell = 92;
    else if (edge.cell == 2) edge.cell = 401;
    else if (edge.cell == 3) edge.cell = 402;
  }
  std::reverse(duplicate.cells.begin(), duplicate.cells.end());

  const auto descriptors = directional::geometry::derive_patch_descriptors(
      duplicate, fixture.V, fixture.F);

  ASSERT_TRUE(descriptors.ownershipConflict.active());
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                DuplicateOrientedDomain,
            descriptors.ownershipConflict.classification);
  EXPECT_EQ(91, descriptors.ownershipConflict.firstPatch);
  EXPECT_EQ(401, descriptors.ownershipConflict.secondPatch);
}

TEST(PatchDescriptorMilestoneE,
     DomainIdentityIsIndependentOfSourceFaceRowOrder) {
  Fixture first = make_authoritative_patch({2, 2, 2, 2});
  bind_patch_charts_to_source_topology(first.F, first.complex);
  ASSERT_TRUE(directional::geometry::canonicalize_surface_cell_ownership(
      first.complex, first.F));
  ASSERT_TRUE(directional::geometry::validate_surface_cell_ownership_registry(
      first.complex));

  const auto firstAudit =
      directional::geometry::audit_surface_cell_domain_identity(
          first.complex, first.complex.cells.front(),
          first.complex.cells.front().halfedges, first.F);
  ASSERT_TRUE(firstAudit.valid);
  ASSERT_TRUE(firstAudit.identity.valid);

  Fixture reordered = first;
  std::vector<int> permutation(reordered.F.rows());
  std::iota(permutation.begin(), permutation.end(), 0);
  std::reverse(permutation.begin(), permutation.end());
  Eigen::MatrixXi reorderedFaces = reordered.F;
  for (int row = 0; row < reordered.F.rows(); ++row) {
    reorderedFaces.row(row) = reordered.F.row(permutation[row]);
  }
  std::vector<int> inverse(permutation.size());
  for (int row = 0; row < static_cast<int>(permutation.size()); ++row) {
    inverse[static_cast<std::size_t>(permutation[row])] = row;
  }
  reordered.F = reorderedFaces;
  for (auto &node : reordered.complex.nodes) {
    node.sourceFace = inverse[static_cast<std::size_t>(node.sourceFace)];
    for (auto &occurrence : node.occurrences) {
      occurrence.sourceFace =
          inverse[static_cast<std::size_t>(occurrence.sourceFace)];
    }
  }
  for (auto &edge : reordered.complex.halfedges) {
    edge.sourceFace = inverse[static_cast<std::size_t>(edge.sourceFace)];
    for (auto &provenance : edge.provenance) {
      provenance.sourceFace =
          inverse[static_cast<std::size_t>(provenance.sourceFace)];
    }
  }
  for (auto &cell : reordered.complex.cells) {
    cell.sourceFace = inverse[static_cast<std::size_t>(cell.sourceFace)];
    for (int &face : cell.sourceFaces) {
      face = inverse[static_cast<std::size_t>(face)];
    }
  }

  ASSERT_NE(first.complex.nodes.front().sourceFace,
            reordered.complex.nodes.front().sourceFace);
  ASSERT_EQ(first.complex.nodes.front().sourceChart,
            reordered.complex.nodes.front().sourceChart);

  const auto reorderedAudit =
      directional::geometry::audit_surface_cell_domain_identity(
          reordered.complex, reordered.complex.cells.front(),
          reordered.complex.cells.front().halfedges, reordered.F);
  ASSERT_TRUE(reorderedAudit.valid);
  ASSERT_TRUE(reorderedAudit.identity.valid);

  const auto firstDescriptor = directional::geometry::derive_patch_descriptor(
      first.complex, first.complex.cells.front(), first.V, first.F);
  const auto reorderedDescriptor =
      directional::geometry::derive_patch_descriptor(
          reordered.complex, reordered.complex.cells.front(), reordered.V,
          reordered.F);

  ASSERT_TRUE(firstDescriptor.patch.domainIdentity.valid);
  ASSERT_TRUE(reorderedDescriptor.patch.domainIdentity.valid);
  EXPECT_TRUE(firstDescriptor.patch.domainIdentity.same_oriented_domain(
      reorderedDescriptor.patch.domainIdentity));
  EXPECT_EQ(firstDescriptor.patch.boundaryNodeIdentities,
            reorderedDescriptor.patch.boundaryNodeIdentities);
}

TEST(PatchDescriptorMilestoneE,
     WholeComplexParallelRouteRepairCompletesWithinOneGlobalLedger) {
  const Fixture fixture = make_valid_parallel_route_same_corner_complex();
  ASSERT_TRUE(directional::geometry::surface_simplification_detail::
                  validate_complex_incidence(fixture.complex));
  directional::geometry::SurfaceCellComplexCompletionOptions preconditionOptions;
  preconditionOptions.maxSameCornerBoundaryRepairs = 0;
  preconditionOptions.maxSameCornerCandidateEvaluations = 0;
  preconditionOptions.maxSameCornerFullCompletionPasses = 1;
  preconditionOptions.maxSameCornerVisitedStates = 1;
  preconditionOptions.maxSameCornerInsertedVertices = 0;
  const auto precondition =
      directional::geometry::complete_surface_cell_complex(
          fixture.complex, fixture.V, fixture.F, preconditionOptions);
  ASSERT_TRUE(precondition.is_rejected());
  ASSERT_NE(nullptr, precondition.rejection());
  ASSERT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                SameCornerDistinctBoundaryClaim,
            precondition.rejection()->ownershipConflict.classification);
  ASSERT_GT(precondition.completionOwnershipRouteCandidateCount, 0);

  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 4;
  options.maxSameCornerCandidateEvaluations = 4;
  options.maxSameCornerFullCompletionPasses = 5;
  options.maxSameCornerVisitedStates = 5;
  options.maxSameCornerInsertedVertices = 8;

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);

  ASSERT_TRUE(completion.is_produced());
  EXPECT_GE(completion.completionOwnershipStructuralRepairAttempts, 1);
  EXPECT_LE(completion.completionOwnershipStructuralRepairAttempts, 4);
  EXPECT_LE(completion.completionOwnershipStructuralCandidatesConsumed, 4);
  EXPECT_EQ(1, completion.completionOwnershipFullRecomputationPasses);
  EXPECT_GE(completion.completionOwnershipIncrementalRecomputationPasses, 1);
  EXPECT_GT(completion.completionOwnershipReusedPatchCompletions, 0);
  EXPECT_GT(completion.completionOwnershipRecomputedPatchCompletions, 0);
  EXPECT_TRUE(std::none_of(
      completion.completionOwnershipProductCacheMismatchVector.begin(),
      completion.completionOwnershipProductCacheMismatchVector.end(),
      [](const directional::geometry::PatchCompletionReuseMismatch &mismatch) {
        return mismatch.rebindValidation;
      }));
  EXPECT_LE(completion.completionOwnershipVisitedStateCount, 5);
  EXPECT_LE(completion.completionOwnershipInsertedBoundaryVertices, 8);
  EXPECT_EQ(1, completion.completionOwnershipPeakLiveCandidateComplexes);
  EXPECT_EQ(0, completion.completionOwnershipCurrentLiveCandidateComplexes);
  ASSERT_FALSE(completion.ownershipRepairAttempts.empty());
  EXPECT_GT(completion.ownershipRepairAttempts.front().routeIntervalCount, 1);
  EXPECT_EQ(completion.completionOwnershipRouteCandidateCount,
            completion.ownershipRepairAttempts.front().routeCandidateCount);
  EXPECT_EQ(
      directional::geometry::SurfaceCellOwnershipRepairAction::
          RouteCompleteBoundarySubdivision,
      completion.ownershipRepairAttempts.front().action);
  EXPECT_EQ(
      directional::geometry::SurfaceCellOwnershipRepairOutcome::
          AssemblySucceeded,
      completion.ownershipRepairAttempts.back().outcome);
  EXPECT_FALSE(completion.product().assembly.ownershipConflict.active());
}

TEST(PatchDescriptorMilestoneE,
     SemanticOnlySameCornerOverlapFailsBeforeCandidateExpansion) {
  const Fixture fixture = make_same_corner_distinct_boundary_components();
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 8;
  options.maxSameCornerCandidateEvaluations = 8;
  options.maxSameCornerFullCompletionPasses = 9;
  options.maxSameCornerVisitedStates = 9;
  options.maxSameCornerInsertedVertices = 16;

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);

  EXPECT_TRUE(completion.is_rejected());
  EXPECT_EQ(0, completion.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(0, completion.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(1, completion.completionOwnershipFullRecomputationPasses);
  EXPECT_EQ(
      directional::geometry::SurfaceCellStructuralRepairExhaustionReason::
          OwnershipOverlap,
      completion.completionOwnershipStructuralExhaustionReason);
  EXPECT_TRUE(completion.ownershipRepairAttempts.empty());
  ASSERT_NE(nullptr, completion.rejection());
  EXPECT_NE(std::string::npos,
            completion.rejection()->detail.find(
                "SameCornerDistinctBoundaryOverlap:"));
}

TEST(PatchDescriptorMilestoneE,
     ZeroStructuralBudgetFailsBeforeCandidateExpansion) {
  const Fixture fixture = make_valid_parallel_route_same_corner_complex();
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 0;
  options.maxSameCornerCandidateEvaluations = 0;
  options.maxSameCornerFullCompletionPasses = 1;
  options.maxSameCornerVisitedStates = 1;
  options.maxSameCornerInsertedVertices = 0;

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);

  EXPECT_TRUE(completion.is_rejected());
  ASSERT_NE(nullptr, completion.rejection());
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipConflictClass::
                SameCornerDistinctBoundaryClaim,
            completion.rejection()->ownershipConflict.classification);
  EXPECT_GT(completion.completionOwnershipRouteCandidateCount, 0);
  EXPECT_EQ(0, completion.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(0, completion.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(1, completion.completionOwnershipFullRecomputationPasses);
  EXPECT_EQ(
      directional::geometry::SurfaceCellStructuralRepairExhaustionReason::
          CandidateBudget,
      completion.completionOwnershipStructuralExhaustionReason);
  ASSERT_NE(nullptr, completion.rejection());
  EXPECT_NE(std::string::npos,
            completion.rejection()->detail.find(
                "SameCornerStructuralRepairExhausted:candidate-budget:"));
}

TEST(PatchDescriptorMilestoneE,
     OneCandidateBudgetIsExactAndDoesNotRecurse) {
  const Fixture fixture = make_valid_parallel_route_same_corner_complex();
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 1;
  options.maxSameCornerCandidateEvaluations = 1;
  options.maxSameCornerFullCompletionPasses = 2;
  options.maxSameCornerVisitedStates = 2;
  options.maxSameCornerInsertedVertices = 8;

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F, options);

  EXPECT_EQ(1, completion.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(1, completion.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(1, completion.completionOwnershipFullRecomputationPasses);
  EXPECT_EQ(1, completion.completionOwnershipIncrementalRecomputationPasses);
  EXPECT_GT(completion.completionOwnershipReusedPatchCompletions, 0);
  EXPECT_GT(completion.completionOwnershipRecomputedPatchCompletions, 0);
  EXPECT_TRUE(std::none_of(
      completion.completionOwnershipProductCacheMismatchVector.begin(),
      completion.completionOwnershipProductCacheMismatchVector.end(),
      [](const directional::geometry::PatchCompletionReuseMismatch &mismatch) {
        return mismatch.rebindValidation;
      }));
  EXPECT_LE(completion.completionOwnershipVisitedStateCount, 2);
  EXPECT_LE(completion.completionOwnershipPeakLiveCandidateComplexes, 1);
  EXPECT_EQ(0, completion.completionOwnershipCurrentLiveCandidateComplexes);
  ASSERT_EQ(1U, completion.ownershipRepairAttempts.size());
  EXPECT_EQ(directional::geometry::SurfaceCellOwnershipRepairAction::
                RouteCompleteBoundarySubdivision,
            completion.ownershipRepairAttempts.front().action);
  EXPECT_GT(completion.ownershipRepairAttempts.front().routeIntervalCount, 1);
  EXPECT_EQ(1, completion.ownershipRepairAttempts.front().candidateEvaluation);
  EXPECT_EQ(1, completion.ownershipRepairAttempts.front().structuralAttempt);
}

TEST(PatchDescriptorMilestoneE,
     StructuralRepairLedgerIsPatchOrderInvariant) {
  const Fixture first = make_valid_parallel_route_same_corner_complex();
  Fixture reordered = first;
  std::swap(reordered.complex.cells[0], reordered.complex.cells[2]);
  reordered.complex.cells[0].id = 0;
  reordered.complex.cells[2].id = 2;
  for (auto &edge : reordered.complex.halfedges) {
    if (edge.cell == 0) {
      edge.cell = 2;
    } else if (edge.cell == 2) {
      edge.cell = 0;
    }
  }
  directional::geometry::surface_simplification_detail::
      recompute_rebuilt_diagnostics(reordered.complex);
  directional::geometry::SurfaceCellComplexCompletionOptions options;
  options.maxSameCornerBoundaryRepairs = 4;
  options.maxSameCornerCandidateEvaluations = 4;
  options.maxSameCornerFullCompletionPasses = 5;
  options.maxSameCornerVisitedStates = 5;
  options.maxSameCornerInsertedVertices = 8;

  const auto a = directional::geometry::complete_surface_cell_complex(
      first.complex, first.V, first.F, options);
  const auto b = directional::geometry::complete_surface_cell_complex(
      reordered.complex, reordered.V, reordered.F, options);

  EXPECT_EQ(a.is_produced(), b.is_produced());
  EXPECT_EQ(a.completionOwnershipStructuralRepairAttempts,
            b.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(a.completionOwnershipStructuralCandidatesConsumed,
            b.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(a.completionOwnershipFullRecomputationPasses,
            b.completionOwnershipFullRecomputationPasses);
  EXPECT_EQ(a.completionOwnershipVisitedStateCount,
            b.completionOwnershipVisitedStateCount);
  EXPECT_EQ(a.completionOwnershipStructuralExhaustionReason,
            b.completionOwnershipStructuralExhaustionReason);
  ASSERT_FALSE(a.ownershipRepairAttempts.empty());
  ASSERT_EQ(a.ownershipRepairAttempts.size(), b.ownershipRepairAttempts.size());
  for (std::size_t index = 0; index < a.ownershipRepairAttempts.size(); ++index) {
    EXPECT_EQ(a.ownershipRepairAttempts[index].outcome,
              b.ownershipRepairAttempts[index].outcome);
    EXPECT_EQ(a.ownershipRepairAttempts[index].candidateEvaluation,
              b.ownershipRepairAttempts[index].candidateEvaluation);
    EXPECT_EQ(a.ownershipRepairAttempts[index].routeIdentityHash,
              b.ownershipRepairAttempts[index].routeIdentityHash);
    EXPECT_EQ(a.ownershipRepairAttempts[index].routeIntervalCount,
              b.ownershipRepairAttempts[index].routeIntervalCount);
    EXPECT_EQ(a.ownershipRepairAttempts[index].selectedHalfedges,
              b.ownershipRepairAttempts[index].selectedHalfedges);
  }
}



TEST(PatchDescriptorMilestoneE,
     AuthoritativeCellScopeOverridesMultiScopeBoundaryDuringSubdivision) {
  Fixture fixture = make_authoritative_patch({1, 1, 1, 1});
  auto &interior = fixture.complex.cells.front();
  ASSERT_TRUE(interior.sourceTopologyRegion.has_value());
  EXPECT_EQ(*interior.sourceTopologyRegion, test_topology_region_id(2));
  ASSERT_FALSE(interior.halfedges.empty());

  const int selectedHalfedge = interior.halfedges.front();
  auto &edge = fixture.complex.halfedges[
      static_cast<std::size_t>(selectedHalfedge)];
  directional::geometry::SurfaceArrangementProvenance alternate;
  alternate.sourceFace = edge.sourceFace;
  alternate.sourceTopologyRegion = test_topology_region_id(9);
  alternate.sourceChart = test_projection_chart(0, edge.sourceFace);
  alternate.sourceArc = edge.sourceArc;
  alternate.railId = edge.railId;
  alternate.curveId = edge.curveId;
  edge.provenance.push_back(alternate);
  auto &twin = fixture.complex.halfedges[
      static_cast<std::size_t>(edge.twin)];
  twin.provenance.push_back(alternate);

  const auto subdivisionResult =
      directional::geometry::subdivide_surface_cell_complex_edges(
          fixture.complex, {{selectedHalfedge, 1}});

  ASSERT_TRUE(subdivisionResult.is_produced());
  const auto &result = subdivisionResult.product();
  EXPECT_FALSE(result.firstScopeFailure.active);
  ASSERT_LT(static_cast<std::size_t>(interior.id), result.complex.cells.size());
  const auto &replacement =
      result.complex.cells[static_cast<std::size_t>(interior.id)];
  ASSERT_TRUE(replacement.sourceTopologyRegion.has_value());
  EXPECT_EQ(*replacement.sourceTopologyRegion, test_topology_region_id(2));
  for (const int halfedgeId : replacement.halfedges) {
    ASSERT_GE(halfedgeId, 0);
    ASSERT_LT(static_cast<std::size_t>(halfedgeId),
              result.complex.halfedges.size());
    const auto &replacementEdge =
        result.complex.halfedges[static_cast<std::size_t>(halfedgeId)];
    ASSERT_TRUE(replacementEdge.sourceTopologyRegion.has_value());
    ASSERT_TRUE(replacementEdge.sourceChart.has_value());
    EXPECT_EQ(*replacementEdge.sourceTopologyRegion, test_topology_region_id(2));
    for (const auto &provenance : replacementEdge.provenance) {
      ASSERT_TRUE(provenance.sourceTopologyRegion.has_value());
      ASSERT_TRUE(provenance.sourceChart.has_value());
      EXPECT_EQ(*provenance.sourceTopologyRegion, test_topology_region_id(2));
      EXPECT_EQ(*provenance.sourceChart, *replacementEdge.sourceChart);
    }
    for (const int nodeId : {replacementEdge.from, replacementEdge.to}) {
      ASSERT_GE(nodeId, 0);
      ASSERT_LT(static_cast<std::size_t>(nodeId), result.complex.nodes.size());
      const auto &node = result.complex.nodes[static_cast<std::size_t>(nodeId)];
      const bool hasAuthoritativeOccurrence = std::any_of(
          node.occurrences.begin(), node.occurrences.end(),
          [&](const auto &occurrence) {
            return occurrence.sourceFace == replacementEdge.sourceFace &&
                   occurrence.sourceTopologyRegion ==
                       replacementEdge.sourceTopologyRegion &&
                   occurrence.sourceChart == replacementEdge.sourceChart;
          });
      EXPECT_TRUE(hasAuthoritativeOccurrence);
    }
  }
}

TEST(PatchDescriptorMilestoneE,
     SubdivisionWithoutCommonSourceChartFailsBeforeMutation) {
  Fixture fixture = make_authoritative_patch({1, 1, 1, 1});
  const auto &badEdge = fixture.complex.halfedges[2];
  auto &badFrom =
      fixture.complex.nodes[static_cast<std::size_t>(badEdge.from)];
  auto &badTo =
      fixture.complex.nodes[static_cast<std::size_t>(badEdge.to)];
  badFrom.occurrences.clear();
  badTo.occurrences.clear();
  badFrom.sourceFace = badEdge.sourceFace;
  badTo.sourceFace =
      (badEdge.sourceFace + 1) % static_cast<int>(fixture.F.rows());

  const std::uint64_t before =
      directional::geometry::surface_simplification_detail::
          complex_structural_hash(fixture.complex);
  const auto result =
      directional::geometry::subdivide_surface_cell_complex_edges(
          fixture.complex, {{2, 1}});

  ASSERT_TRUE(result.is_rejected());
  const auto *failure = result.rejection();
  ASSERT_NE(nullptr, failure);
  EXPECT_EQ(directional::geometry::SurfaceCellSubdivisionFailureKind::
                MissingCommonSourceChart,
            failure->kind);
  EXPECT_EQ("MissingCommonSourceChart", failure->detail);
  EXPECT_TRUE(failure->rollbackEquivalent);
  EXPECT_EQ(before,
            directional::geometry::surface_simplification_detail::
                complex_structural_hash(fixture.complex));
  EXPECT_TRUE(result.rollback_matches(fixture.complex));
}

TEST(PatchDescriptorMilestoneE,
     FailedSubdivisionReturnsBitExactCommittedComplex) {
  Fixture fixture = make_authoritative_patch({1, 1, 1, 1});
  ASSERT_GE(fixture.complex.halfedges.size(), 4U);
  const auto &badEdge = fixture.complex.halfedges[2];
  ASSERT_GE(badEdge.from, 0);
  ASSERT_GE(badEdge.to, 0);
  ASSERT_LT(static_cast<std::size_t>(badEdge.from),
            fixture.complex.nodes.size());
  ASSERT_LT(static_cast<std::size_t>(badEdge.to),
            fixture.complex.nodes.size());

  // Keep edge 0 valid so the transaction appends a tentative node first.
  // Edge 2 still declares one exact common chart and source scope, but its
  // finite endpoint coordinates interpolate to a zero-sum barycentric point.
  // This reaches InvalidMidpointEmbedding after mutation has begun instead of
  // testing the earlier MissingCommonSourceChart contract.
  auto &badFrom =
      fixture.complex.nodes[static_cast<std::size_t>(badEdge.from)];
  auto &badTo =
      fixture.complex.nodes[static_cast<std::size_t>(badEdge.to)];
  // Preserve all unrelated charts on these shared nodes. The subdivision
  // implementation resolves an occurrence by exact edge provenance before
  // falling back to a face chart, so only the target edge is malformed.
  const int badProvenance = badEdge.provenance.empty()
                                ? -1
                                : badEdge.provenance.front().provenance;
  const auto eraseTargetOccurrence = [&](auto &node, const auto &edge) {
    node.occurrences.erase(
        std::remove_if(node.occurrences.begin(), node.occurrences.end(),
                       [&](const auto &occurrence) {
                         return occurrence.sourceFace == edge.sourceFace &&
                                occurrence.sourceTopologyRegion ==
                                    edge.sourceTopologyRegion &&
                                occurrence.sourceChart == edge.sourceChart &&
                                occurrence.sourceArc == edge.sourceArc &&
                                (badProvenance < 0 ||
                                 occurrence.provenance == badProvenance);
                       }),
        node.occurrences.end());
  };
  eraseTargetOccurrence(badFrom, badEdge);
  eraseTargetOccurrence(badTo, badEdge);

  const auto malformedOccurrence = [&](const auto &edge,
                                         const Eigen::RowVector3d &barycentric) {
    directional::geometry::SurfaceArrangementNodeOccurrence occurrence;
    occurrence.sourceFace = edge.sourceFace;
    occurrence.barycentric = barycentric;
    occurrence.sourceTopologyRegion = edge.sourceTopologyRegion;
    occurrence.sourceChart = edge.sourceChart;
    occurrence.sourceArc = edge.sourceArc;
    occurrence.provenance = edge.provenance.empty()
                                ? -1
                                : edge.provenance.front().provenance;
    occurrence.railId = edge.railId;
    occurrence.curveId = edge.curveId;
    occurrence.sourceT0 = edge.sourceT0;
    occurrence.sourceT1 = edge.sourceT1;
    occurrence.railT0 = edge.railT0;
    occurrence.railT1 = edge.railT1;
    return occurrence;
  };
  const auto &badTwin = fixture.complex.halfedges[
      static_cast<std::size_t>(badEdge.twin)];
  badFrom.occurrences.push_back(malformedOccurrence(
      badEdge, Eigen::RowVector3d(1.0, 0.0, 0.0)));
  badTo.occurrences.push_back(malformedOccurrence(
      badEdge, Eigen::RowVector3d(-1.0, 0.0, 0.0)));
  badFrom.occurrences.push_back(malformedOccurrence(
      badTwin, Eigen::RowVector3d(1.0, 0.0, 0.0)));
  badTo.occurrences.push_back(malformedOccurrence(
      badTwin, Eigen::RowVector3d(-1.0, 0.0, 0.0)));

  const auto occurrenceCount = [](const auto &complex) {
    return std::accumulate(
        complex.nodes.begin(), complex.nodes.end(), std::size_t{0},
        [](const std::size_t count, const auto &node) {
          return count + node.occurrences.size();
        });
  };
  const auto provenanceCount = [](const auto &complex) {
    return std::accumulate(
        complex.halfedges.begin(), complex.halfedges.end(), std::size_t{0},
        [](const std::size_t count, const auto &edge) {
          return count + edge.provenance.size();
        });
  };
  const std::size_t originalOccurrenceCount = occurrenceCount(fixture.complex);
  const std::size_t originalProvenanceCount = provenanceCount(fixture.complex);

  const std::uint64_t before =
      directional::geometry::surface_simplification_detail::
          complex_structural_hash(fixture.complex);
  const auto result =
      directional::geometry::subdivide_surface_cell_complex_edges(
          fixture.complex, {{0, 1}, {2, 1}});

  ASSERT_TRUE(result.is_rejected());
  const auto *failure = result.rejection();
  ASSERT_NE(nullptr, failure);
  EXPECT_EQ(directional::geometry::SurfaceCellSubdivisionFailureKind::
                InvalidMidpointEmbedding,
            failure->kind);
  EXPECT_EQ("InvalidMidpointEmbedding", failure->detail);
  EXPECT_TRUE(failure->rollbackEquivalent);
  EXPECT_EQ(failure->rollbackIdentityHashBefore,
            failure->rollbackIdentityHashAfter);
  EXPECT_EQ(before,
            directional::geometry::surface_simplification_detail::
                complex_structural_hash(fixture.complex));
  EXPECT_EQ(originalOccurrenceCount, occurrenceCount(fixture.complex));
  EXPECT_EQ(originalProvenanceCount, provenanceCount(fixture.complex));
  EXPECT_TRUE(result.rollback_matches(fixture.complex));
}

TEST(PatchDescriptorMilestoneE,
     AlreadySuccessfulComplexPerformsNoStructuralRepair) {
  const Fixture fixture = make_authoritative_patch({1, 1, 1, 1});
  const auto completion = complete_fixture_with_source_authority(
      fixture.complex, fixture.V, fixture.F);
  ASSERT_TRUE(completion.is_produced());
  ASSERT_FALSE(completion.product().descriptors.descriptors.empty());
  ASSERT_FALSE(completion.product().completedPatches.empty());
  ASSERT_FALSE(completion.product().assembly.mesh.quads.empty());
  EXPECT_TRUE(completion.product().assembly.failure.empty());
  EXPECT_EQ(0, completion.completionOwnershipStructuralRepairAttempts);
  EXPECT_EQ(0, completion.completionOwnershipStructuralCandidatesConsumed);
  EXPECT_EQ(0, completion.completionOwnershipRouteCandidateCount);
  EXPECT_TRUE(completion.ownershipRepairAttempts.empty());
}
