#include <directional/geometry/FlowRepStrands.h>
#include <directional/geometry/SurfaceArrangement.h>

#include <algorithm>
#include <cstdint>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <gtest/gtest.h>
#include "TestAuthorityIds.h"

namespace {

using directional::geometry::FlowRepArc;
using directional::geometry::FlowRepCoverageSample;
using directional::geometry::FlowRepCycleInput;
using directional::geometry::FlowRepSelectionFailureCode;
using directional::geometry::FlowRepSparseNetwork;
using directional::geometry::FlowRepSparseOptions;

auto test_topology_region_id(const int value) {
  const auto id = directional::authority::TopologyRegionId::from_index(
      value, static_cast<std::size_t>(value + 1));
  if (!id) {
    throw std::runtime_error("Invalid test topology-region ID.");
  }
  return id.value();
}

auto test_isolation_sheet_id(const int value) {
  const auto id = directional::authority::IsolationSheetId::from_index(
      value, static_cast<std::size_t>(value + 1));
  if (!id) {
    throw std::runtime_error("Invalid test isolation-sheet ID.");
  }
  return id.value();
}

directional::authority::SourceEdgeTopologyKey test_source_edge_topology(
    const int firstVertex, const int secondVertex) {
  const auto topology = directional::authority::SourceEdgeTopologyKey::from_indices(
      firstVertex, secondVertex, static_cast<std::size_t>(
          std::max({firstVertex + 1, secondVertex + 1, 1})));
  if (!topology) throw std::runtime_error("Invalid test source-edge topology.");
  return topology.value();
}

directional::geometry::SourceTopologyRegions test_source_authority(
    const Eigen::MatrixXi &faces, const std::vector<int> &components,
    const std::vector<int> &sheets) {
  directional::geometry::SurfaceCellTracingOptions options;
  options.sourceFaceComponents = components;
  options.sourceFaceSheets = sheets;
  auto authority = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, options);
  if (!authority.has_value()) {
    throw std::runtime_error("Failed to construct typed test source authority.");
  }
  return std::move(*authority);
}

void attach_source_authority(
    directional::geometry::SurfaceCellNetwork &network,
    const Eigen::MatrixXi &faces, const std::vector<int> &components,
    const std::vector<int> &sheets) {
  auto sourceAuthority = test_source_authority(faces, components, sheets);
  if (sourceAuthority.regions().empty()) {
    throw std::runtime_error("Typed test source authority has no regions.");
  }
  const auto owner = sourceAuthority.regions().front().id();
  const auto cell = directional::authority::CellId::from_index(0, 1);
  if (!cell) {
    throw std::runtime_error("Failed to construct typed test cell ID.");
  }
  std::vector<directional::geometry::SurfacePhaseFrontCell> cells;
  cells.emplace_back(owner, cell.value());
  cells.back().orientationValidated = true;
  std::vector<directional::geometry::SurfaceFrontEdge> edges;
  edges.emplace_back(owner, cell.value());
  edges.back().filledSide = 0;
  edges.back().exterior = true;
  auto product = directional::geometry::SurfacePhaseFrontProduct::make(
      0, 0, std::move(sourceAuthority), {}, {}, {}, std::move(edges), {},
      std::move(cells));
  auto *value =
      std::get_if<directional::geometry::SurfacePhaseFrontProduct>(&product);
  if (value == nullptr) {
    throw std::runtime_error("Failed to construct typed test phase-front product.");
  }
  network.phaseFront = directional::geometry::SurfacePhaseFrontResult::produced(
      std::move(*value));
}

directional::geometry::FlowRepArc arc(const int id, const double x0,
                                      const double y0, const double x1,
                                      const double y1, const int family = 0) {
  directional::geometry::FlowRepArc a;
  a.id = id;
  a.start << x0, y0, 0.0;
  a.end << x1, y1, 0.0;
  a.family = family;
  return a;
}

directional::geometry::FlowRepArc embedded_arc(
    const int id, const Eigen::RowVector3d &start,
    const Eigen::RowVector3d &end) {
  auto a = arc(id, start[1], start[2], end[1], end[2]);
  a.sourceFace = 0;
  a.startBarycentric = start;
  a.endBarycentric = end;
  a.sourceTopologyRegion = test_topology_region_id(3);
  a.sourceIsolationSheet = test_isolation_sheet_id(5);
  a.strandProvenance = 7;
  a.featureProvenance = 11;
  return a;
}

directional::geometry::FlowRepCycleInput feasible_cycle() {
  directional::geometry::FlowRepCycleInput cycle;
  cycle.targetSize = 1.0;
  cycle.sideCounts = {2, 2, 2, 2};
  for (int i = 0; i < 9; ++i) {
    cycle.normals.push_back(Eigen::RowVector3d(0.0, 0.0, 1.0));
    cycle.boundaryNormalA.push_back(Eigen::RowVector3d(0.0, 0.0, 1.0));
    cycle.boundaryNormalB.push_back(Eigen::RowVector3d(0.0, 0.0, 1.0));
    cycle.distanceA.push_back(1.0);
    cycle.distanceB.push_back(1.0);
    cycle.surfaceDistances.push_back(0.01);
  }
  return cycle;
}

FlowRepArc selection_arc(const int id, const Eigen::RowVector3d &start,
                         const Eigen::RowVector3d &end, const int side,
                         const int segment = 0) {
  FlowRepArc value = arc(id, start.x(), start.y(), end.x(), end.y(), side % 2);
  value.sourceFace = 0;
  value.startBarycentric =
      side == 0   ? Eigen::RowVector3d(1.0, 0.0, 0.0)
      : side == 1 ? Eigen::RowVector3d(0.0, 1.0, 0.0)
      : side == 2 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
                  : Eigen::RowVector3d(0.5, 0.5, 0.0);
  value.endBarycentric =
      side == 0   ? Eigen::RowVector3d(0.0, 1.0, 0.0)
      : side == 1 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
      : side == 2 ? Eigen::RowVector3d(0.5, 0.5, 0.0)
                  : Eigen::RowVector3d(1.0, 0.0, 0.0);
  value.sourceTopologyRegion = test_topology_region_id(3);
  value.sourceIsolationSheet = test_isolation_sheet_id(5);
  value.strandProvenance = 0;
  value.proposalId = 0;
  value.proposalSeedId = 23;
  value.proposalSide = side;
  value.proposalBoundarySegment = segment;
  return value;
}

std::vector<FlowRepArc> square_selection_arcs() {
  return {
      selection_arc(0, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 0),
      selection_arc(1, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, 1),
      selection_arc(2, {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, 2),
      selection_arc(3, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, 3),
  };
}

FlowRepCoverageSample coverage_sample(const FlowRepArc &sourceArc,
                                      const double targetSize = 1.0,
                                      const Eigen::RowVector3d *position =
                                          nullptr) {
  FlowRepCoverageSample sample;
  sample.position =
      position == nullptr ? 0.5 * (sourceArc.start + sourceArc.end) : *position;
  sample.sourceFace = sourceArc.sourceFace;
  sample.barycentric =
      0.5 * (sourceArc.startBarycentric + sourceArc.endBarycentric);
  sample.sourceTopologyRegion = sourceArc.sourceTopologyRegion;
  sample.sourceIsolationSheet = sourceArc.sourceIsolationSheet;
  sample.targetSize = targetSize;
  sample.sourceArcId = sourceArc.id;
  return sample;
}

std::vector<FlowRepCoverageSample>
coverage_for_active_arcs(const std::vector<FlowRepArc> &arcs,
                         const double targetSize = 1.0) {
  std::vector<FlowRepCoverageSample> samples;
  for (const FlowRepArc &value : arcs) {
    if (value.initiallyActive) {
      samples.push_back(coverage_sample(value, targetSize));
    }
  }
  return samples;
}

struct TetrahedralSingularityFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  Eigen::VectorXd targetSize;
  directional::geometry::SurfaceCellNetwork network;
};

TetrahedralSingularityFixture tetrahedral_singularity_fixture() {
  TetrahedralSingularityFixture fixture;
  fixture.vertices.resize(4, 3);
  fixture.vertices << 0.0, 0.0, 1.0, 1.0, 0.0, 0.0, -0.5,
      0.8660254037844386, 0.0, -0.5, -0.8660254037844386, 0.0;
  fixture.faces.resize(4, 3);
  fixture.faces << 0, 1, 2, 0, 2, 3, 0, 3, 1, 1, 3, 2;
  fixture.targetSize = Eigen::VectorXd::Constant(4, 0.5);
  attach_source_authority(fixture.network, fixture.faces, {0, 0, 0, 0},
                          {0, 0, 0, 0});
  for (int branch = 0; branch < 3; ++branch) {
    directional::geometry::SurfaceSingularitySeparatrix separatrix;
    separatrix.sourceVertex = 0;
    separatrix.singularityIndexNumerator = 1;
    separatrix.expectedValence = 3;
    separatrix.branch = branch;
    separatrix.initialFace = branch;
    separatrix.family = branch % 2;
    separatrix.sign = branch == 1 ? -1 : 1;
    separatrix.trace.termination =
        directional::geometry::TraceTerminationReason::Budget;
    directional::geometry::SurfaceTraceSegment segment;
    segment.face = branch;
    segment.startBarycentric << 1.0, 0.0, 0.0;
    segment.endBarycentric << 0.20, 0.40, 0.40;
    segment.family = separatrix.family;
    segment.sign = separatrix.sign;
    separatrix.trace.segments.push_back(segment);
    separatrix.trace.length =
        (directional::geometry::surface_cell_tracing_detail::point_position(
             fixture.vertices, fixture.faces,
             directional::geometry::SurfaceTracePoint{
                 branch, segment.endBarycentric}) -
         fixture.vertices.row(0))
            .norm();
    fixture.network.singularSeparatrices.push_back(std::move(separatrix));
  }
  return fixture;
}

std::vector<directional::geometry::SurfaceArrangementArc>
arrangement_arcs(const std::vector<FlowRepArc> &arcs) {
  std::vector<directional::geometry::SurfaceArrangementArc> result;
  result.reserve(arcs.size());
  for (const FlowRepArc &arc : arcs) {
    directional::geometry::SurfaceArrangementArc embedded;
    embedded.id = static_cast<int>(result.size());
    embedded.sourceFace = arc.sourceFace;
    embedded.startBarycentric = arc.startBarycentric;
    embedded.endBarycentric = arc.endBarycentric;
    embedded.family = arc.family;
    embedded.strand = arc.strandProvenance;
    embedded.featureClass = arc.featureClass;
    embedded.hardFeature = arc.hardFeatureRail || arc.mandatoryRail;
    embedded.provenance = arc.id;
    embedded.sourceTopologyRegion = arc.sourceTopologyRegion;
    embedded.layoutSupport = arc.layoutSupport;
    embedded.singularitySupport = arc.singularitySupport;
    result.push_back(std::move(embedded));
  }
  return result;
}

bool node_is_source_vertex(
    const directional::geometry::SurfaceArrangementNode &node,
    const Eigen::MatrixXi &faces, const int sourceVertex) {
  for (const auto &occurrence : node.occurrences) {
    if (occurrence.sourceFace < 0 || occurrence.sourceFace >= faces.rows()) {
      continue;
    }
    for (int corner = 0; corner < 3; ++corner) {
      if (faces(occurrence.sourceFace, corner) == sourceVertex &&
          std::abs(occurrence.barycentric[corner] - 1.0) <= 1.0e-10) {
        return true;
      }
    }
  }
  return false;
}

FlowRepCycleInput square_cycle() {
  FlowRepCycleInput cycle = feasible_cycle();
  cycle.id = 0;
  cycle.proposalId = 0;
  cycle.sideArcIds = {{0}, {1}, {2}, {3}};
  cycle.boundaryArcIds = {0, 1, 2, 3};
  cycle.sideCounts = {1, 1, 1, 1};
  return cycle;
}

FlowRepArc mandatory_rail(const int id, const double y,
                          const int sourceSheet = 5) {
  FlowRepArc value = arc(id, 0.0, y, 1.0, y, -1);
  value.sourceFace = 0;
  value.startBarycentric << 1.0, 0.0, 0.0;
  value.endBarycentric << 0.0, 1.0, 0.0;
  value.sourceTopologyRegion = test_topology_region_id(3);
  value.sourceIsolationSheet = test_isolation_sheet_id(sourceSheet);
  value.mandatoryRail = true;
  value.boundaryRail = true;
  value.strandProvenance = id;
  value.featureProvenance = id;
  value.railId = directional::tests::test_hard_rail_id(id);
  value.curveId = id;
  return value;
}

std::uint64_t sparse_hash(
    const directional::geometry::FlowRepSparseNetwork &network) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  mix(network.selectionSucceeded ? 1 : 0);
  mix(static_cast<int>(network.failureCode));
  for (const int id : network.retainedArcIds) {
    mix(id);
  }
  mix(-1);
  for (const int id : network.removedArcIds) {
    mix(id);
  }
  mix(network.mandatoryRails);
  mix(network.retainedMandatoryRails);
  mix(network.cycleRebuilds);
  mix(network.acceptedTransactions);
  mix(network.attemptedStrandTransactions);
  mix(network.rejectedStrandTransactions);
  mix(network.retainedFlowlines);
  mix(network.removedFlowlines);
  for (const auto tag : network.endpointTags) {
    mix(static_cast<int>(tag));
  }
  return hash;
}

directional::fields::CrossFieldResult constant_cross_field(
    const int faceCount) {
  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(faceCount, 3);
  field.secondaryDirections.resize(faceCount, 3);
  for (int face = 0; face < faceCount; ++face) {
    field.primaryDirections.row(face) << 1.0, 0.0, 0.0;
    field.secondaryDirections.row(face) << 0.0, 1.0, 0.0;
  }
  field.matching.resize(0);
  field.effort.resize(0);
  return field;
}

FlowRepArc endpoint_completion_arc(
    const int id, const int sourceFace,
    const Eigen::RowVector3d &startBarycentric,
    const Eigen::RowVector3d &endBarycentric, const int sourceComponent,
    const int sourceSheet, const bool mandatory = false) {
  FlowRepArc value;
  value.id = id;
  value.start << startBarycentric[1], startBarycentric[2], 0.0;
  value.end << endBarycentric[1], endBarycentric[2], 0.0;
  value.sourceFace = sourceFace;
  value.startBarycentric = startBarycentric;
  value.endBarycentric = endBarycentric;
  value.sourceTopologyRegion = test_topology_region_id(sourceComponent);
  value.sourceIsolationSheet = test_isolation_sheet_id(sourceSheet);
  value.family = 0;
  value.strandProvenance = id;
  value.featureProvenance = id;
  value.layoutSupport = !mandatory;
  value.supportTraceId = mandatory ? -1 : id;
  value.supportSeedId = mandatory ? -1 : id;
  value.supportSegment = 0;
  value.sameStrandHint = id;
  value.mandatoryRail = mandatory;
  value.boundaryRail = mandatory;
  value.railId = mandatory
                     ? std::optional(directional::tests::test_hard_rail_id(id))
                     : std::nullopt;
  value.curveId = mandatory ? id : -1;
  return value;
}

} // namespace

TEST(FlowRepStrandsPhase15,
     EndpointCompletionExtendsToRetainedSameSheetNetwork) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  std::vector<FlowRepArc> arcs;
  arcs.push_back(endpoint_completion_arc(
      0, 0, {0.60, 0.25, 0.15}, {0.40, 0.45, 0.15}, 3, 5));
  arcs.push_back(endpoint_completion_arc(
      1, 0, {0.85, 0.10, 0.05}, {0.50, 0.10, 0.40}, 3, 5, true));
  arcs.push_back(endpoint_completion_arc(
      2, 0, {0.20, 0.75, 0.05}, {0.05, 0.75, 0.20}, 3, 5, true));

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {3};
  tracing.sourceFaceSheets = {5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  // Force generated connector insertion to reallocate the arc vector.
  // Committed diagnostics must reacquire the source by stable identity.
  arcs.shrink_to_fit();

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, constant_cross_field(1), tracing, arcs, {0, 1, 2},
      completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 2);
  EXPECT_EQ(result.resolvedEndpoints, 2);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  EXPECT_GE(result.addedArcs, 2);
  ASSERT_EQ(result.product().arcs.size(), arcs.size() + result.addedArcs);
  for (std::size_t index = arcs.size(); index < result.product().arcs.size(); ++index) {
    const FlowRepArc &added = result.product().arcs[index];
    EXPECT_EQ(added.sourceFace, 0);
    ASSERT_TRUE(added.sourceTopologyRegion.has_value());
    ASSERT_TRUE(added.sourceIsolationSheet.has_value());
    EXPECT_EQ(*added.sourceTopologyRegion, test_topology_region_id(3));
    EXPECT_EQ(*added.sourceIsolationSheet, test_isolation_sheet_id(5));
    EXPECT_TRUE(added.layoutSupport);
    EXPECT_TRUE(added.startBarycentric.allFinite());
    EXPECT_TRUE(added.endBarycentric.allFinite());
  }
}

TEST(FlowRepStrandsPhase15,
     EndpointCompletionIgnoresSubToleranceIntersectionAtTraceOrigin) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  std::vector<FlowRepArc> arcs;
  arcs.push_back(endpoint_completion_arc(
      0, 0, {0.60, 0.25, 0.15}, {0.40, 0.45, 0.15}, 3, 5));
  arcs.push_back(endpoint_completion_arc(
      1, 0, {0.85, 0.10, 0.05}, {0.50, 0.10, 0.40}, 3, 5, true));
  arcs.push_back(endpoint_completion_arc(
      2, 0, {0.20, 0.75, 0.05}, {0.05, 0.75, 0.20}, 3, 5, true));
  // This retained segment crosses the outgoing trace only 5e-10 source units
  // from its origin. Treating the dimensionless trace parameter as a spatial
  // tolerance clips the connector to a non-representable zero-length arc and
  // discards the valid continuation to arc 2.
  arcs.push_back(endpoint_completion_arc(
      3, 0, {0.4499999995, 0.4500000005, 0.10},
      {0.3499999995, 0.4500000005, 0.20}, 3, 5, true));

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {3};
  tracing.sourceFaceSheets = {5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  completion.intersectionTolerance = 1.0e-9;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, constant_cross_field(1), tracing, arcs, {0, 1, 2, 3},
      completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 2);
  EXPECT_EQ(result.resolvedEndpoints, 2);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  ASSERT_GT(result.addedArcs, 0);
  for (std::size_t index = arcs.size(); index < result.product().arcs.size(); ++index) {
    EXPECT_GT((result.product().arcs[index].end - result.product().arcs[index].start).norm(),
              completion.intersectionTolerance);
  }
}

TEST(FlowRepStrandsPhase15,
     EndpointCompletionOnlyCommitsArrangementReproducibleIntersections) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  const FlowRepArc source = endpoint_completion_arc(
      0, 0, {0.60, 0.25, 0.15}, {0.40, 0.45, 0.15}, 3, 5);
  std::vector<FlowRepArc> arcs = {
      source,
      endpoint_completion_arc(1, 0, {0.85, 0.10, 0.05},
                              {0.50, 0.10, 0.40}, 3, 5, true),
      endpoint_completion_arc(2, 0, {0.20, 0.75, 0.05},
                              {0.05, 0.75, 0.20}, 3, 5, true),
      // This segment is 5e-10 source units above the outgoing trace. The
      // endpoint-completion tolerance is intentionally looser than the exact
      // arrangement predicate. It is not an intersection and must not be
      // accepted as network ownership merely because the lines are nearly
      // parallel.
      endpoint_completion_arc(3, 0, {0.2999999995, 0.55, 0.1500000005},
                              {0.2499999995, 0.60, 0.1500000005}, 3, 5,
                              true)};

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {3};
  tracing.sourceFaceSheets = {5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  completion.intersectionTolerance = 1.0e-9;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, constant_cross_field(1), tracing, arcs, {0, 1, 2, 3},
      completion);

  ASSERT_TRUE(result.is_produced());
  const auto added = std::find_if(
      result.product().arcs.begin() + static_cast<std::ptrdiff_t>(arcs.size()),
      result.product().arcs.end(), [&](const FlowRepArc &arc) {
        return (arc.startBarycentric - source.endBarycentric).norm() < 1.0e-12;
      });
  ASSERT_NE(added, result.product().arcs.end());
  EXPECT_TRUE(added->endEmbeddedAnchor);
  EXPECT_NEAR(added->endBarycentric[1], 0.75, 1.0e-12);
  EXPECT_NEAR(added->endBarycentric[2], 0.15, 1.0e-12);
  const auto diagnostic = std::find_if(
      result.diagnostics.begin(), result.diagnostics.end(),
      [&](const auto &candidate) {
        return candidate.sourceArcId == source.id &&
               !candidate.startEndpoint;
      });
  ASSERT_NE(diagnostic, result.diagnostics.end());
  EXPECT_EQ(diagnostic->captureTargetArcId, 2);
  EXPECT_EQ(diagnostic->captureTraceSegment, 0);
  EXPECT_EQ(diagnostic->captureTargetSourceFace, 0);
  EXPECT_NEAR(diagnostic->captureBarycentric[1], 0.75, 1.0e-12);
  EXPECT_NEAR(diagnostic->captureBarycentric[2], 0.15, 1.0e-12);

  std::set<int> retained(result.product().retainedArcIds.begin(),
                         result.product().retainedArcIds.end());
  std::vector<directional::geometry::SurfaceArrangementArc> arrangementArcs;
  for (const FlowRepArc &arc : result.product().arcs) {
    if (retained.count(arc.id) == 0) {
      continue;
    }
    directional::geometry::SurfaceArrangementArc arrangementArc;
    arrangementArc.id = static_cast<int>(arrangementArcs.size());
    arrangementArc.sourceFace = arc.sourceFace;
    arrangementArc.startBarycentric = arc.startBarycentric;
    arrangementArc.endBarycentric = arc.endBarycentric;
    arrangementArc.family = arc.family;
    arrangementArc.provenance = arc.id;
    arrangementArc.sourceTopologyRegion = arc.sourceTopologyRegion;
    arrangementArcs.push_back(arrangementArc);
  }
  directional::geometry::SurfaceArrangementOptions arrangementOptions;
  arrangementOptions.insertBoundaryRails = false;
  arrangementOptions.sourceAuthority = &sourceAuthority;
  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, arrangementArcs, arrangementOptions);

  const auto endpointKey =
      directional::geometry::surface_arrangement_detail::make_node_key(
          faces, added->sourceFace,
          directional::geometry::surface_arrangement_detail::bary_to_uv(
              added->endBarycentric));
  int endpointNode = -1;
  for (std::size_t nodeIndex = 0; nodeIndex < complex.nodes.size();
       ++nodeIndex) {
    const auto &node = complex.nodes[nodeIndex];
    const auto matches = [&](const int sourceFace,
                             const Eigen::RowVector3d &barycentric) {
      const auto candidate =
          directional::geometry::surface_arrangement_detail::make_node_key(
              faces, sourceFace,
              directional::geometry::surface_arrangement_detail::bary_to_uv(
                  barycentric));
      return !(candidate < endpointKey) && !(endpointKey < candidate);
    };
    if (matches(node.sourceFace, node.barycentric) ||
        std::any_of(node.occurrences.begin(), node.occurrences.end(),
                    [&](const auto &occurrence) {
                      return matches(occurrence.sourceFace,
                                     occurrence.barycentric);
                    })) {
      endpointNode = static_cast<int>(nodeIndex);
      break;
    }
  }
  ASSERT_GE(endpointNode, 0);
  const int endpointDegree = static_cast<int>(std::count_if(
      complex.halfedges.begin(), complex.halfedges.end(),
      [&](const auto &halfedge) { return halfedge.from == endpointNode; }));
  EXPECT_GE(endpointDegree, 3);
}

TEST(FlowRepStrandsPhase15,
     SubToleranceIntrinsicCaptureReconcilesOpenEndpointWithoutTinyArc) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  constexpr double epsilon = 5.0e-10;
  FlowRepArc source = endpoint_completion_arc(
      0, 0, {0.40 - epsilon, 0.10 + epsilon, 0.50},
      {0.50 - epsilon, epsilon, 0.50}, 3, 5);
  source.startEmbeddedAnchor = true;
  source.singularitySupport = true;

  FlowRepArc target = endpoint_completion_arc(
      1, 0, {0.50, 0.0, 0.50}, {0.0, 0.0, 1.0}, 3, 5, true);
  target.startEmbeddedAnchor = true;
  target.endEmbeddedAnchor = true;

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {3};
  tracing.sourceFaceSheets = {5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  completion.intersectionTolerance = 1.0e-9;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, constant_cross_field(1), tracing, {source, target},
      {0, 1}, completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 1);
  EXPECT_EQ(result.resolvedEndpoints, 1);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedRequiredEndpoints, 0);
  EXPECT_EQ(result.addedArcs, 0);
  ASSERT_EQ(result.product().arcs.size(), 2U);
  EXPECT_TRUE(result.product().arcs[0].endEmbeddedAnchor);
  EXPECT_NEAR((result.product().arcs[0].end - target.start).norm(), 0.0, 1.0e-15);
  EXPECT_NEAR((result.product().arcs[0].endBarycentric - target.startBarycentric).norm(),
              0.0, 1.0e-15);
  ASSERT_EQ(result.diagnostics.size(), 1U);
  EXPECT_EQ(result.diagnostics.front().resolution,
            directional::geometry::FlowRepEndpointResolution::IntrinsicNode);
  EXPECT_EQ(result.diagnostics.front().skippedDegenerateSegments, 1);
}

TEST(FlowRepStrandsPhase15,
     AdjacentFaceFanCanonicalizesSubToleranceEndpointsToSourceVertex) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      0.0, -1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 0, 3;

  constexpr double epsilon = 5.0e-10;
  FlowRepArc source = endpoint_completion_arc(
      0, 0, {0.40, 0.30, 0.30}, {1.0 - epsilon, epsilon, 0.0}, 3, 5);
  source.startEmbeddedAnchor = true;
  source.singularitySupport = true;

  FlowRepArc chartTransition = endpoint_completion_arc(
      1, 1, {epsilon, 1.0 - epsilon, 0.0},
      {0.0, 1.0 - epsilon, epsilon}, 3, 6, true);
  chartTransition.start =
      chartTransition.startBarycentric[0] * vertices.row(faces(1, 0)) +
      chartTransition.startBarycentric[1] * vertices.row(faces(1, 1)) +
      chartTransition.startBarycentric[2] * vertices.row(faces(1, 2));
  chartTransition.end =
      chartTransition.endBarycentric[0] * vertices.row(faces(1, 0)) +
      chartTransition.endBarycentric[1] * vertices.row(faces(1, 1)) +
      chartTransition.endBarycentric[2] * vertices.row(faces(1, 2));
  chartTransition.layoutSupport = true;
  chartTransition.singularitySupport = true;

  FlowRepArc continuation = endpoint_completion_arc(
      2, 1, {0.0, 1.0 - epsilon, epsilon}, {0.10, 0.60, 0.30}, 3, 6,
      true);
  continuation.start =
      continuation.startBarycentric[0] * vertices.row(faces(1, 0)) +
      continuation.startBarycentric[1] * vertices.row(faces(1, 1)) +
      continuation.startBarycentric[2] * vertices.row(faces(1, 2));
  continuation.end =
      continuation.endBarycentric[0] * vertices.row(faces(1, 0)) +
      continuation.endBarycentric[1] * vertices.row(faces(1, 1)) +
      continuation.endBarycentric[2] * vertices.row(faces(1, 2));
  continuation.layoutSupport = true;
  continuation.singularitySupport = true;
  continuation.endEmbeddedAnchor = true;

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {3, 3};
  tracing.sourceFaceSheets = {5, 6};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  completion.intersectionTolerance = 1.0e-9;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, constant_cross_field(2), tracing,
      {source, chartTransition, continuation}, {0, 1, 2}, completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 0);
  EXPECT_EQ(result.addedArcs, 0);
  ASSERT_EQ(result.product().arcs.size(), 3U);
  const Eigen::RowVector3d vertex0 = vertices.row(0);
  EXPECT_NEAR((result.product().arcs[0].end - vertex0).norm(), 0.0, 1.0e-15);
  EXPECT_NEAR((result.product().arcs[1].start - vertex0).norm(), 0.0, 1.0e-15);
  EXPECT_NEAR((result.product().arcs[1].end - vertex0).norm(), 0.0, 1.0e-15);
  EXPECT_NEAR((result.product().arcs[2].start - vertex0).norm(), 0.0, 1.0e-15);
  EXPECT_TRUE(result.product().arcs[0].endEmbeddedAnchor);
  EXPECT_TRUE(result.product().arcs[1].startEmbeddedAnchor);
  EXPECT_TRUE(result.product().arcs[1].endEmbeddedAnchor);
  EXPECT_TRUE(result.product().arcs[2].startEmbeddedAnchor);

  std::vector<directional::geometry::SurfaceArrangementArc> arrangementArcs;
  for (const FlowRepArc &arc : result.product().arcs) {
    directional::geometry::SurfaceArrangementArc arrangementArc;
    arrangementArc.id = static_cast<int>(arrangementArcs.size());
    arrangementArc.sourceFace = arc.sourceFace;
    arrangementArc.startBarycentric = arc.startBarycentric;
    arrangementArc.endBarycentric = arc.endBarycentric;
    arrangementArc.family = arc.family;
    arrangementArc.provenance = arc.id;
    arrangementArc.sourceTopologyRegion = arc.sourceTopologyRegion;
    arrangementArcs.push_back(arrangementArc);
  }
  directional::geometry::SurfaceArrangementOptions arrangementOptions;
  arrangementOptions.insertBoundaryRails = false;
  arrangementOptions.sourceAuthority = &sourceAuthority;
  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, arrangementArcs, arrangementOptions);

  const auto vertexKey =
      directional::geometry::surface_arrangement_detail::make_node_key(
          faces, 0, Eigen::Vector2d(0.0, 0.0));
  int vertexNode = -1;
  for (std::size_t nodeIndex = 0; nodeIndex < complex.nodes.size();
       ++nodeIndex) {
    const auto &node = complex.nodes[nodeIndex];
    const auto matches = [&](const int sourceFace,
                             const Eigen::RowVector3d &barycentric) {
      const auto candidate =
          directional::geometry::surface_arrangement_detail::make_node_key(
              faces, sourceFace,
              directional::geometry::surface_arrangement_detail::bary_to_uv(
                  barycentric));
      return !(candidate < vertexKey) && !(vertexKey < candidate);
    };
    if (matches(node.sourceFace, node.barycentric) ||
        std::any_of(node.occurrences.begin(), node.occurrences.end(),
                    [&](const auto &occurrence) {
                      return matches(occurrence.sourceFace,
                                     occurrence.barycentric);
                    })) {
      vertexNode = static_cast<int>(nodeIndex);
      break;
    }
  }
  ASSERT_GE(vertexNode, 0);
  const int vertexDegree = static_cast<int>(std::count_if(
      complex.halfedges.begin(), complex.halfedges.end(),
      [&](const auto &halfedge) { return halfedge.from == vertexNode; }));
  EXPECT_EQ(vertexDegree, 2);
}

TEST(FlowRepStrandsPhase15,
     EndpointCompletionCapturesCanonicalVertexOwnedByAnotherFace) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      -1.0, 0.0, 0.0, 0.0, -1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 3, 4;

  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(2, 3);
  field.secondaryDirections.resize(2, 3);
  field.primaryDirections.row(0) << 1.0, 1.0, 0.0;
  field.secondaryDirections.row(0) << -1.0, 1.0, 0.0;
  field.primaryDirections.row(1) << 1.0, 0.0, 0.0;
  field.secondaryDirections.row(1) << 0.0, 1.0, 0.0;
  for (int face = 0; face < 2; ++face) {
    field.primaryDirections.row(face).normalize();
    field.secondaryDirections.row(face).normalize();
  }

  FlowRepArc source = endpoint_completion_arc(
      0, 0, {0.40, 0.30, 0.30}, {0.50, 0.25, 0.25}, 0, 5);
  source.startEmbeddedAnchor = true;
  FlowRepArc target = endpoint_completion_arc(
      1, 1, {1.0, 0.0, 0.0}, {0.80, 0.10, 0.10}, 0, 5, true);

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {0, 0};
  tracing.sourceFaceSheets = {5, 5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, field, tracing, {source, target}, {0, 1}, completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 1);
  EXPECT_EQ(result.resolvedEndpoints, 1);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedRequiredEndpoints, 0);
  ASSERT_EQ(result.diagnostics.size(), 1U);
  EXPECT_EQ(result.diagnostics.front().resolution,
            directional::geometry::FlowRepEndpointResolution::IntrinsicNode);
  EXPECT_GE(result.addedArcs, 1);
  EXPECT_TRUE(result.product().arcs.back().endEmbeddedAnchor);
}

TEST(FlowRepStrandsPhase15,
     CanonicalVertexCaptureRemainsSeparatedAcrossSourceSheets) {
  Eigen::MatrixXd vertices(5, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      -1.0, 0.0, 0.0, 0.0, -1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 0, 3, 4;

  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(2, 3);
  field.secondaryDirections.resize(2, 3);
  field.primaryDirections.row(0) << 1.0, 1.0, 0.0;
  field.secondaryDirections.row(0) << -1.0, 1.0, 0.0;
  field.primaryDirections.row(1) << 1.0, 0.0, 0.0;
  field.secondaryDirections.row(1) << 0.0, 1.0, 0.0;
  for (int face = 0; face < 2; ++face) {
    field.primaryDirections.row(face).normalize();
    field.secondaryDirections.row(face).normalize();
  }

  FlowRepArc source = endpoint_completion_arc(
      0, 0, {0.40, 0.30, 0.30}, {0.50, 0.25, 0.25}, 0, 5);
  source.startEmbeddedAnchor = true;
  FlowRepArc otherSheet = endpoint_completion_arc(
      1, 1, {1.0, 0.0, 0.0}, {0.80, 0.10, 0.10}, 0, 6, true);

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {0, 0};
  tracing.sourceFaceSheets = {5, 6};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, field, tracing, {source, otherSheet}, {0, 1},
      completion);

  EXPECT_FALSE(result.is_produced());
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(result.rejection()->detail, "UnresolvedFlowlineEndpoints");
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(
      directional::geometry::FlowRepEndpointCompletionFailureKind::
          UnresolvedRequiredEndpoints,
      result.rejection()->kind);
  EXPECT_EQ(result.openEndpointsBefore, 1);
  EXPECT_EQ(result.resolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedEndpoints, 1);
  ASSERT_EQ(result.diagnostics.size(), 1U);
  EXPECT_EQ(result.diagnostics.front().resolution,
            directional::geometry::FlowRepEndpointResolution::NoNetworkCapture);
  EXPECT_EQ(result.addedArcs, 0);
}

TEST(FlowRepStrandsPhase15,
     FeatureTerminationCapturesRailIntervalInAdjacentFaceChart) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;

  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(2, 3);
  field.secondaryDirections.resize(2, 3);
  field.primaryDirections.row(0) << 1.0, 1.0, 0.0;
  field.secondaryDirections.row(0) << -1.0, 1.0, 0.0;
  field.primaryDirections.row(1) << 1.0, 0.0, 0.0;
  field.secondaryDirections.row(1) << 0.0, 1.0, 0.0;
  for (int face = 0; face < 2; ++face) {
    field.primaryDirections.row(face).normalize();
    field.secondaryDirections.row(face).normalize();
  }

  FlowRepArc source = endpoint_completion_arc(
      0, 0, {0.60, 0.20, 0.20}, {0.40, 0.30, 0.30}, 0, 5);
  source.startEmbeddedAnchor = true;
  source.singularitySupport = true;
  FlowRepArc rail = endpoint_completion_arc(
      1, 1, {0.25, 0.0, 0.75}, {0.75, 0.0, 0.25}, 0, 5, true);
  rail.boundaryRail = false;
  rail.hardFeatureRail = true;
  rail.startEmbeddedAnchor = true;
  rail.endEmbeddedAnchor = true;
  rail.start = directional::geometry::surface_cell_tracing_detail::point_position(
      vertices, faces,
      directional::geometry::SurfaceTracePoint{rail.sourceFace,
                                                rail.startBarycentric});
  rail.end = directional::geometry::surface_cell_tracing_detail::point_position(
      vertices, faces,
      directional::geometry::SurfaceTracePoint{rail.sourceFace,
                                                rail.endBarycentric});

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.followCompatibleHardFeatureRails = false;
  tracing.hardFeatureEdges.insert(
      test_source_edge_topology(1, 2));
  tracing.sourceFaceComponents = {0, 0};
  tracing.sourceFaceSheets = {5, 5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, field, tracing, {source, rail}, {0, 1}, completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 1);
  EXPECT_EQ(result.resolvedEndpoints, 1);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedRequiredEndpoints, 0);
  ASSERT_EQ(result.diagnostics.size(), 1U);
  EXPECT_EQ(result.diagnostics.front().termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_EQ(result.diagnostics.front().resolution,
            directional::geometry::FlowRepEndpointResolution::IntrinsicNode);
  EXPECT_GE(result.addedArcs, 1);
  EXPECT_TRUE(result.product().arcs.back().endEmbeddedAnchor);
}

TEST(FlowRepStrandsPhase15,
     FeatureTerminationNearVertexCapturesIncidentAuthoritativeRail) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  constexpr double epsilon = 5.0e-10;
  const Eigen::Vector2d endpoint(0.20, 0.20);
  const Eigen::Vector2d terminal(epsilon, 1.0 - epsilon);
  Eigen::Vector2d direction = terminal - endpoint;
  direction.normalize();

  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(1, 3);
  field.secondaryDirections.resize(1, 3);
  field.primaryDirections.row(0) << direction.x(), direction.y(), 0.0;
  field.secondaryDirections.row(0) << -direction.y(), direction.x(), 0.0;

  const Eigen::Vector2d start = endpoint - 0.10 * (terminal - endpoint);
  FlowRepArc source = endpoint_completion_arc(
      0, 0, {1.0 - start.x() - start.y(), start.x(), start.y()},
      {0.60, endpoint.x(), endpoint.y()}, 0, 5);
  source.startEmbeddedAnchor = true;
  source.singularitySupport = true;

  // The trace terminates on feature edge (1,2), within the spatial endpoint
  // tolerance of vertex 2. The authoritative retained rail leaves vertex 2
  // through the other incident edge (0,2), so ownership must transfer through
  // the canonical source vertex rather than by matching the terminal edge.
  FlowRepArc rail = endpoint_completion_arc(
      1, 0, {1.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, 0, 5, true);
  rail.boundaryRail = false;
  rail.hardFeatureRail = true;
  rail.startEmbeddedAnchor = true;
  rail.endEmbeddedAnchor = true;

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.followCompatibleHardFeatureRails = false;
  tracing.hardFeatureEdges.insert(
      test_source_edge_topology(1, 2));
  tracing.sourceFaceComponents = {0};
  tracing.sourceFaceSheets = {5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  completion.intersectionTolerance = 1.0e-9;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, field, tracing, {source, rail}, {0, 1}, completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 1);
  EXPECT_EQ(result.resolvedEndpoints, 1);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedRequiredEndpoints, 0);
  ASSERT_EQ(result.diagnostics.size(), 1U);
  EXPECT_EQ(result.diagnostics.front().termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_EQ(result.diagnostics.front().resolution,
            directional::geometry::FlowRepEndpointResolution::IntrinsicNode);
  EXPECT_GT(result.diagnostics.front().terminalFeatureRailCandidates, 0);
  EXPECT_GT(result.diagnostics.front().terminalCompatibleFeatureRailCandidates,
            0);
}

TEST(FlowRepStrandsPhase15,
     FeatureTerminationNearVertexRejectsIncidentRailFromAnotherComponent) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  constexpr double epsilon = 5.0e-10;
  const Eigen::Vector2d endpoint(0.20, 0.20);
  const Eigen::Vector2d terminal(epsilon, 1.0 - epsilon);
  Eigen::Vector2d direction = terminal - endpoint;
  direction.normalize();

  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(1, 3);
  field.secondaryDirections.resize(1, 3);
  field.primaryDirections.row(0) << direction.x(), direction.y(), 0.0;
  field.secondaryDirections.row(0) << -direction.y(), direction.x(), 0.0;

  const Eigen::Vector2d start = endpoint - 0.10 * (terminal - endpoint);
  FlowRepArc source = endpoint_completion_arc(
      0, 0, {1.0 - start.x() - start.y(), start.x(), start.y()},
      {0.60, endpoint.x(), endpoint.y()}, 0, 5);
  source.startEmbeddedAnchor = true;
  source.singularitySupport = true;

  FlowRepArc otherComponentRail = endpoint_completion_arc(
      1, 0, {1.0, 0.0, 0.0}, {0.0, 0.0, 1.0}, 1, 5, true);
  otherComponentRail.boundaryRail = false;
  otherComponentRail.hardFeatureRail = true;
  otherComponentRail.startEmbeddedAnchor = true;
  otherComponentRail.endEmbeddedAnchor = true;

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.followCompatibleHardFeatureRails = false;
  tracing.hardFeatureEdges.insert(
      test_source_edge_topology(1, 2));
  tracing.sourceFaceComponents = {0};
  tracing.sourceFaceSheets = {5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  completion.intersectionTolerance = 1.0e-9;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, field, tracing, {source, otherComponentRail}, {0, 1},
      completion);

  EXPECT_FALSE(result.is_produced());
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(result.rejection()->detail, "UnresolvedFlowlineEndpoints");
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(
      directional::geometry::FlowRepEndpointCompletionFailureKind::
          UnresolvedRequiredEndpoints,
      result.rejection()->kind);
  EXPECT_EQ(result.resolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedEndpoints, 1);
  EXPECT_EQ(result.unresolvedRequiredEndpoints, 1);
  ASSERT_EQ(result.diagnostics.size(), 1U);
  EXPECT_EQ(result.diagnostics.front().termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_EQ(result.diagnostics.front().resolution,
            directional::geometry::FlowRepEndpointResolution::NoNetworkCapture);
  EXPECT_GT(result.diagnostics.front().terminalFeatureRailCandidates, 0);
  EXPECT_EQ(result.diagnostics.front().terminalCompatibleFeatureRailCandidates,
            0);
}

TEST(FlowRepStrandsPhase15,
     FeatureTerminationAcceptsEitherIncidentLocalSheetOfAuthoritativeRail) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;

  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(2, 3);
  field.secondaryDirections.resize(2, 3);
  field.primaryDirections.row(0) << 1.0, 1.0, 0.0;
  field.secondaryDirections.row(0) << -1.0, 1.0, 0.0;
  field.primaryDirections.row(1) << 1.0, 0.0, 0.0;
  field.secondaryDirections.row(1) << 0.0, 1.0, 0.0;
  for (int face = 0; face < 2; ++face) {
    field.primaryDirections.row(face).normalize();
    field.secondaryDirections.row(face).normalize();
  }

  FlowRepArc source = endpoint_completion_arc(
      0, 0, {0.60, 0.20, 0.20}, {0.40, 0.30, 0.30}, 0, 5);
  source.startEmbeddedAnchor = true;
  source.singularitySupport = true;
  FlowRepArc otherSheetRail = endpoint_completion_arc(
      1, 1, {0.25, 0.0, 0.75}, {0.75, 0.0, 0.25}, 0, 6, true);
  otherSheetRail.boundaryRail = false;
  otherSheetRail.hardFeatureRail = true;
  otherSheetRail.startEmbeddedAnchor = true;
  otherSheetRail.endEmbeddedAnchor = true;

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.followCompatibleHardFeatureRails = false;
  tracing.hardFeatureEdges.insert(
      test_source_edge_topology(1, 2));
  tracing.sourceFaceComponents = {0, 0};
  tracing.sourceFaceSheets = {5, 6};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, field, tracing, {source, otherSheetRail}, {0, 1},
      completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 1);
  EXPECT_EQ(result.resolvedEndpoints, 1);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedRequiredEndpoints, 0);
  ASSERT_EQ(result.diagnostics.size(), 1U);
  EXPECT_EQ(result.diagnostics.front().termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_EQ(result.diagnostics.front().resolution,
            directional::geometry::FlowRepEndpointResolution::IntrinsicNode);
  EXPECT_GE(result.addedArcs, 1);
}

TEST(FlowRepStrandsPhase15,
     FeatureTerminationRejectsAuthoritativeRailFromAnotherComponent) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;

  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(2, 3);
  field.secondaryDirections.resize(2, 3);
  field.primaryDirections.row(0) << 1.0, 1.0, 0.0;
  field.secondaryDirections.row(0) << -1.0, 1.0, 0.0;
  field.primaryDirections.row(1) << 1.0, 0.0, 0.0;
  field.secondaryDirections.row(1) << 0.0, 1.0, 0.0;
  for (int face = 0; face < 2; ++face) {
    field.primaryDirections.row(face).normalize();
    field.secondaryDirections.row(face).normalize();
  }

  FlowRepArc source = endpoint_completion_arc(
      0, 0, {0.60, 0.20, 0.20}, {0.40, 0.30, 0.30}, 0, 5);
  source.startEmbeddedAnchor = true;
  source.singularitySupport = true;
  FlowRepArc otherComponentRail = endpoint_completion_arc(
      1, 1, {0.25, 0.0, 0.75}, {0.75, 0.0, 0.25}, 1, 6, true);
  otherComponentRail.boundaryRail = false;
  otherComponentRail.hardFeatureRail = true;
  otherComponentRail.startEmbeddedAnchor = true;
  otherComponentRail.endEmbeddedAnchor = true;

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.followCompatibleHardFeatureRails = false;
  tracing.hardFeatureEdges.insert(
      test_source_edge_topology(1, 2));
  tracing.sourceFaceComponents = {0, 1};
  tracing.sourceFaceSheets = {5, 6};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, field, tracing, {source, otherComponentRail}, {0, 1},
      completion);

  EXPECT_FALSE(result.is_produced());
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(result.rejection()->detail, "UnresolvedFlowlineEndpoints");
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(
      directional::geometry::FlowRepEndpointCompletionFailureKind::
          UnresolvedRequiredEndpoints,
      result.rejection()->kind);
  EXPECT_EQ(result.openEndpointsBefore, 1);
  EXPECT_EQ(result.resolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedEndpoints, 1);
  EXPECT_EQ(result.unresolvedRequiredEndpoints, 1);
  ASSERT_EQ(result.diagnostics.size(), 1U);
  EXPECT_EQ(result.diagnostics.front().termination,
            directional::geometry::TraceTerminationReason::Feature);
  EXPECT_EQ(result.diagnostics.front().resolution,
            directional::geometry::FlowRepEndpointResolution::NoNetworkCapture);
  EXPECT_EQ(result.addedArcs, 0);
}

TEST(FlowRepStrandsPhase15,
     DegenerateEdgeTipReorientsMatchedFamilyAndReachesRetainedNetwork) {
  Eigen::MatrixXd vertices(4, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      1.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 1, 3, 2;

  directional::fields::CrossFieldResult field;
  field.primaryDirections.resize(2, 3);
  field.secondaryDirections.resize(2, 3);
  field.primaryDirections.row(0) << 1.0, 0.1, 0.0;
  field.secondaryDirections.row(0) << -0.1, 1.0, 0.0;
  field.primaryDirections.row(1) << 1.0, -1.2, 0.0;
  field.secondaryDirections.row(1) << 1.2, 1.0, 0.0;
  for (int face = 0; face < 2; ++face) {
    field.primaryDirections.row(face).normalize();
    field.secondaryDirections.row(face).normalize();
  }
  directional::fields::CrossFieldEdgeTransition transition;
  transition.sourceVertex0 = 1;
  transition.sourceVertex1 = 2;
  transition.firstFace = 0;
  transition.secondFace = 1;
  transition.matching = 0;
  transition.effort = 0.4;
  field.edgeTransitions.push_back(transition);

  std::vector<FlowRepArc> arcs;
  FlowRepArc required = endpoint_completion_arc(
      0, 0, {0.22, 0.30, 0.48}, {0.0, 0.5, 0.5}, 0, 5);
  required.start =
      directional::geometry::surface_cell_tracing_detail::point_position(
          vertices, faces,
          directional::geometry::SurfaceTracePoint{
              required.sourceFace, required.startBarycentric});
  required.end =
      directional::geometry::surface_cell_tracing_detail::point_position(
          vertices, faces,
          directional::geometry::SurfaceTracePoint{
              required.sourceFace, required.endBarycentric});
  required.startEmbeddedAnchor = true;
  required.singularitySupport = true;
  arcs.push_back(required);

  FlowRepArc retained = endpoint_completion_arc(
      1, 1, {0.32, 0.02, 0.66}, {0.22, 0.12, 0.66}, 0, 6, true);
  retained.start =
      directional::geometry::surface_cell_tracing_detail::point_position(
          vertices, faces,
          directional::geometry::SurfaceTracePoint{
              retained.sourceFace, retained.startBarycentric});
  retained.end =
      directional::geometry::surface_cell_tracing_detail::point_position(
          vertices, faces,
          directional::geometry::SurfaceTracePoint{
              retained.sourceFace, retained.endBarycentric});
  arcs.push_back(retained);

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {0, 0};
  tracing.sourceFaceSheets = {5, 6};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;

  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, field, tracing, arcs, {0, 1}, completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 1);
  EXPECT_EQ(result.resolvedEndpoints, 1);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  ASSERT_EQ(result.addedArcs, 1);
  ASSERT_EQ(result.product().arcs.size(), 3U);
  const FlowRepArc &connector = result.product().arcs.back();
  EXPECT_EQ(connector.sourceFace, 1);
  EXPECT_EQ(connector.family, 0);
  EXPECT_TRUE(connector.singularitySupport);
  EXPECT_TRUE(connector.endEmbeddedAnchor);
  EXPECT_TRUE(directional::geometry::flow_rep_detail::
                  arc_has_complete_provenance(connector));
}

TEST(FlowRepStrandsPhase15,
     OpenHardFeatureEndpointsExtendWithoutRemovingAuthoritativeRail) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  std::vector<FlowRepArc> arcs;
  auto feature = endpoint_completion_arc(
      0, 0, {0.60, 0.25, 0.15}, {0.40, 0.45, 0.15}, 3, 5, true);
  feature.boundaryRail = false;
  feature.hardFeatureRail = true;
  feature.family = -1;
  arcs.push_back(feature);
  arcs.push_back(endpoint_completion_arc(
      1, 0, {0.85, 0.10, 0.05}, {0.50, 0.10, 0.40}, 3, 5, true));
  arcs.push_back(endpoint_completion_arc(
      2, 0, {0.20, 0.75, 0.05}, {0.05, 0.75, 0.20}, 3, 5, true));

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {3};
  tracing.sourceFaceSheets = {5};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, constant_cross_field(1), tracing, arcs, {0, 1, 2},
      completion);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(result.openEndpointsBefore, 2);
  EXPECT_EQ(result.resolvedEndpoints, 2);
  EXPECT_EQ(result.unresolvedEndpoints, 0);
  EXPECT_GE(result.addedArcs, 2);
  ASSERT_LT(0, static_cast<int>(result.product().retainedArcIds.size()));
  EXPECT_EQ(result.product().retainedArcIds.front(), 0);
  EXPECT_TRUE(result.product().arcs.front().mandatoryRail);
  EXPECT_TRUE(result.product().arcs.front().hardFeatureRail);
  EXPECT_EQ(result.product().arcs.front().railId, feature.railId);
  for (std::size_t index = arcs.size(); index < result.product().arcs.size(); ++index) {
    EXPECT_TRUE(result.product().arcs[index].layoutSupport);
    EXPECT_FALSE(result.product().arcs[index].mandatoryRail);
    EXPECT_FALSE(result.product().arcs[index].singularitySupport);
    EXPECT_EQ(result.product().arcs[index].family, 0);
  }
}

TEST(FlowRepStrandsPhase15,
     EndpointCompletionDoesNotCaptureCoincidentOtherSheet) {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
      0.0, 0.0, 1.0e-6, 1.0, 0.0, 1.0e-6, 0.0, 1.0, 1.0e-6;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2, 3, 4, 5;

  std::vector<FlowRepArc> arcs;
  arcs.push_back(endpoint_completion_arc(
      0, 0, {0.60, 0.25, 0.15}, {0.40, 0.45, 0.15}, 3, 5));
  arcs.push_back(endpoint_completion_arc(
      1, 1, {0.85, 0.10, 0.05}, {0.50, 0.10, 0.40}, 4, 6, true));
  arcs.push_back(endpoint_completion_arc(
      2, 1, {0.20, 0.75, 0.05}, {0.05, 0.75, 0.20}, 4, 6, true));

  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.maxTraceLength = 2.0;
  tracing.maxTraceSegments = 16;
  tracing.sourceFaceComponents = {3, 4};
  tracing.sourceFaceSheets = {5, 6};
  const auto sourceAuthority = test_source_authority(
      faces, tracing.sourceFaceComponents, tracing.sourceFaceSheets);
  tracing.sourceAuthority = &sourceAuthority;
  directional::geometry::FlowRepEndpointCompletionOptions completion;
  completion.requireAllEndpointsResolved = true;
  const auto result = directional::geometry::complete_flow_rep_endpoints(
      vertices, faces, constant_cross_field(2), tracing, arcs, {0, 1, 2},
      completion);

  EXPECT_FALSE(result.is_produced());
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(result.rejection()->detail, "UnresolvedFlowlineEndpoints");
  ASSERT_NE(nullptr, result.rejection());
  EXPECT_EQ(
      directional::geometry::FlowRepEndpointCompletionFailureKind::
          UnresolvedRequiredEndpoints,
      result.rejection()->kind);
  EXPECT_EQ(result.openEndpointsBefore, 2);
  EXPECT_EQ(result.resolvedEndpoints, 0);
  EXPECT_EQ(result.unresolvedEndpoints, 2);
  EXPECT_EQ(result.addedArcs, 0);
  EXPECT_EQ(nullptr, result.produced_product());
}

TEST(FlowRepStrandsPhase15,
     RailTruncatedGenericSupportDoesNotInheritLaterTerminalAnchor) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  directional::geometry::SurfaceCellNetwork network;
  attach_source_authority(network, faces, {3}, {5});

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(7));
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.curveId = 11;
  rail.component = 3;
  directional::geometry::SurfaceCellRailSample railStart;
  railStart.sourceFace = 0;
  railStart.sourceEdge = 0;
  railStart.railParameter = 0.0;
  railStart.barycentric << 0.0, 0.5, 0.5;
  railStart.position = 0.5 * (vertices.row(1) + vertices.row(2));
  directional::geometry::SurfaceCellRailSample railEnd = railStart;
  railEnd.railParameter = 1.0;
  railEnd.barycentric << 0.0, 1.0, 0.0;
  railEnd.position = vertices.row(1);
  rail.samples = {railStart, railEnd};
  network.authoritativeRails.push_back(rail);

  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 0;
  seed.hardRailId = rail.id;
  seed.provenance = directional::geometry::SurfaceSeedProvenance::Boundary;
  seed.point.face = 0;
  seed.point.barycentric << 1.0, 0.0, 0.0;
  network.seeds.push_back(seed);
  network.traces.resize(4);
  directional::geometry::SurfaceTraceResult &trace = network.traces.front();
  trace.termination = directional::geometry::TraceTerminationReason::Boundary;
  directional::geometry::SurfaceTraceSegment prefix;
  prefix.face = 0;
  prefix.startBarycentric << 1.0, 0.0, 0.0;
  prefix.endBarycentric = railStart.barycentric;
  prefix.family = 0;
  prefix.sign = 1;
  directional::geometry::SurfaceTraceSegment railSuffix;
  railSuffix.face = 0;
  railSuffix.startBarycentric = railStart.barycentric;
  railSuffix.endBarycentric = railEnd.barycentric;
  railSuffix.family = 0;
  railSuffix.sign = 1;
  railSuffix.railId = rail.id;
  railSuffix.curveId = rail.curveId;
  railSuffix.railT0 = 0.0;
  railSuffix.railT1 = 1.0;
  trace.segments = {prefix, railSuffix};

  const auto arcs = directional::geometry::build_flow_rep_arcs_from_network(
      vertices, faces, network);

  ASSERT_EQ(arcs.size(), 2U);
  const FlowRepArc &railArc = arcs[0];
  const FlowRepArc &support = arcs[1];
  EXPECT_TRUE(railArc.mandatoryRail);
  EXPECT_TRUE(railArc.hardFeatureRail);
  EXPECT_TRUE(support.layoutSupport);
  EXPECT_FALSE(support.singularitySupport);
  EXPECT_TRUE(support.startEmbeddedAnchor);
  EXPECT_FALSE(support.endEmbeddedAnchor);
  EXPECT_EQ(support.supportSegment, 0);
  EXPECT_EQ(directional::geometry::flow_rep_detail::embedded_endpoint_key(
                support, false),
            directional::geometry::flow_rep_detail::embedded_endpoint_key(
                railArc, true));
}

TEST(FlowRepStrandsPhase15,
     RailTruncatedSingularitySupportDoesNotInheritLaterTerminalAnchor) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  directional::geometry::SurfaceCellNetwork network;
  attach_source_authority(network, faces, {3}, {5});

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(7));
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.curveId = 11;
  rail.component = 3;
  directional::geometry::SurfaceCellRailSample railStart;
  railStart.sourceFace = 0;
  railStart.sourceEdge = 0;
  railStart.railParameter = 0.0;
  railStart.barycentric << 0.0, 0.5, 0.5;
  railStart.position = 0.5 * (vertices.row(1) + vertices.row(2));
  directional::geometry::SurfaceCellRailSample railEnd = railStart;
  railEnd.railParameter = 1.0;
  railEnd.barycentric << 0.0, 1.0, 0.0;
  railEnd.position = vertices.row(1);
  rail.samples = {railStart, railEnd};
  network.authoritativeRails.push_back(rail);

  directional::geometry::SurfaceSingularitySeparatrix separatrix;
  separatrix.sourceVertex = 0;
  separatrix.singularityIndexNumerator = 1;
  separatrix.expectedValence = 3;
  separatrix.branch = 0;
  separatrix.initialFace = 0;
  separatrix.family = 0;
  separatrix.sign = 1;
  separatrix.trace.termination =
      directional::geometry::TraceTerminationReason::Feature;
  directional::geometry::SurfaceTraceSegment prefix;
  prefix.face = 0;
  prefix.startBarycentric << 1.0, 0.0, 0.0;
  prefix.endBarycentric = railStart.barycentric;
  prefix.family = 0;
  prefix.sign = 1;
  directional::geometry::SurfaceTraceSegment railSuffix;
  railSuffix.face = 0;
  railSuffix.startBarycentric = railStart.barycentric;
  railSuffix.endBarycentric = railEnd.barycentric;
  railSuffix.family = 0;
  railSuffix.sign = 1;
  railSuffix.railId = rail.id;
  railSuffix.curveId = rail.curveId;
  railSuffix.railT0 = 0.0;
  railSuffix.railT1 = 1.0;
  separatrix.trace.segments = {prefix, railSuffix};
  network.singularSeparatrices.push_back(separatrix);

  const auto arcs = directional::geometry::build_flow_rep_arcs_from_network(
      vertices, faces, network);

  ASSERT_EQ(arcs.size(), 2U);
  const FlowRepArc &railArc = arcs[0];
  const FlowRepArc &support = arcs[1];
  EXPECT_TRUE(railArc.mandatoryRail);
  EXPECT_TRUE(railArc.hardFeatureRail);
  EXPECT_TRUE(support.layoutSupport);
  EXPECT_TRUE(support.singularitySupport);
  EXPECT_TRUE(support.startEmbeddedAnchor);
  EXPECT_FALSE(support.endEmbeddedAnchor);
  EXPECT_EQ(support.supportSegment, 0);
  EXPECT_EQ(directional::geometry::flow_rep_detail::embedded_endpoint_key(
                support, false),
            directional::geometry::flow_rep_detail::embedded_endpoint_key(
                railArc, true));
}

TEST(FlowRepStrandsPhase15,
     IntraRingRailPrefixUsesCanonicalSingularitySpokeInsteadOfMicroLoop) {
  TetrahedralSingularityFixture fixture =
      tetrahedral_singularity_fixture();

  directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(7));
  rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
  rail.curveId = 11;
  rail.component = 0;
  directional::geometry::SurfaceCellRailSample railStart;
  railStart.sourceFace = 0;
  railStart.sourceEdge = 2;
  railStart.railParameter = 0.0;
  railStart.barycentric << 1.0, 0.0, 0.0;
  railStart.position = fixture.vertices.row(0);
  directional::geometry::SurfaceCellRailSample railEnd = railStart;
  railEnd.railParameter = 1.0;
  railEnd.barycentric << 0.0, 1.0, 0.0;
  railEnd.position = fixture.vertices.row(1);
  rail.samples = {railStart, railEnd};
  fixture.network.authoritativeRails.push_back(rail);

  auto &trace = fixture.network.singularSeparatrices.front().trace;
  directional::geometry::SurfaceTraceSegment prefix;
  prefix.face = 0;
  prefix.startBarycentric << 1.0, 0.0, 0.0;
  prefix.endBarycentric << 1.0 - 1.0e-6, 1.0e-6, 0.0;
  prefix.family = 0;
  prefix.sign = 1;
  directional::geometry::SurfaceTraceSegment suffix;
  suffix.face = 0;
  suffix.startBarycentric = prefix.endBarycentric;
  suffix.endBarycentric = railEnd.barycentric;
  suffix.family = 0;
  suffix.sign = 1;
  suffix.railId = rail.id;
  suffix.curveId = rail.curveId;
  suffix.railT0 = 1.0e-6;
  suffix.railT1 = 1.0;
  trace.segments = {prefix, suffix};
  trace.termination =
      directional::geometry::TraceTerminationReason::Feature;

  const auto input = directional::geometry::build_flow_rep_selection_input(
      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
      0.5);

  std::vector<const FlowRepArc *> branchArcs;
  for (const FlowRepArc &arc : input.arcs) {
    if (arc.singularitySupport && arc.family >= 0 &&
        arc.supportTraceId == 0) {
      branchArcs.push_back(&arc);
    }
  }
  ASSERT_EQ(branchArcs.size(), 2U);
  const FlowRepArc *inactivePrefix = nullptr;
  const FlowRepArc *canonicalSpoke = nullptr;
  for (const FlowRepArc *arc : branchArcs) {
    if (arc->initiallyActive) {
      canonicalSpoke = arc;
    } else {
      inactivePrefix = arc;
    }
  }
  ASSERT_NE(inactivePrefix, nullptr);
  ASSERT_NE(canonicalSpoke, nullptr);
  EXPECT_LT((inactivePrefix->end - inactivePrefix->start).norm(), 1.0e-4);
  EXPECT_GT((canonicalSpoke->end - canonicalSpoke->start).norm(), 1.0e-3);
  EXPECT_TRUE(canonicalSpoke->startEmbeddedAnchor);
  EXPECT_TRUE(canonicalSpoke->endEmbeddedAnchor);
  EXPECT_TRUE(canonicalSpoke->startBarycentric.isApprox(
      Eigen::RowVector3d(1.0, 0.0, 0.0), 0.0));

  std::vector<FlowRepArc> active;
  for (const FlowRepArc &arc : input.arcs) {
    if (arc.initiallyActive) {
      active.push_back(arc);
    }
  }
  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arrangement_arcs(active), options);

  int center = -1;
  for (const auto &node : complex.nodes) {
    if (node_is_source_vertex(node, fixture.faces, 0)) {
      center = node.id;
      break;
    }
  }
  ASSERT_GE(center, 0);
  int radialEdges = 0;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.twin >= 0 && halfedge.id < halfedge.twin &&
        halfedge.singularitySupport &&
        (halfedge.from == center || halfedge.to == center)) {
      ++radialEdges;
    }
  }
  EXPECT_EQ(radialEdges, 3);
  for (const auto &cell : complex.cells) {
    bool touchesCenter = false;
    for (const int halfedgeId : cell.halfedges) {
      const auto &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      touchesCenter = touchesCenter || halfedge.from == center ||
                      halfedge.to == center;
    }
    if (!cell.boundaryCycle && touchesCenter) {
      EXPECT_TRUE(cell.disk);
      EXPECT_EQ(cell.eulerCharacteristic, 1);
    }
  }
}

TEST(FlowRepStrandsPhase15,
     PreRingReturnRerootsRetainedSingularityContinuation) {
  TetrahedralSingularityFixture fixture =
      tetrahedral_singularity_fixture();

  auto &trace = fixture.network.singularSeparatrices.front().trace;
  directional::geometry::SurfaceTraceSegment outbound;
  outbound.face = 0;
  outbound.startBarycentric << 1.0, 0.0, 0.0;
  outbound.endBarycentric << 1.0 - 3.0e-6, 2.4e-6, 6.0e-7;
  outbound.family = 0;
  outbound.sign = 1;

  directional::geometry::SurfaceTraceSegment returning = outbound;
  returning.startBarycentric = outbound.endBarycentric;
  returning.endBarycentric << 1.0 - 2.0e-7, 1.6e-7, 4.0e-8;

  directional::geometry::SurfaceTraceSegment continuation = outbound;
  continuation.startBarycentric = returning.endBarycentric;
  continuation.endBarycentric << 0.20, 0.40, 0.40;

  trace.segments = {outbound, returning, continuation};
  trace.termination = directional::geometry::TraceTerminationReason::Budget;
  trace.length = 0.0;
  for (const auto &segment : trace.segments) {
    const auto start =
        directional::geometry::surface_cell_tracing_detail::point_position(
            fixture.vertices, fixture.faces,
            directional::geometry::SurfaceTracePoint{
                segment.face, segment.startBarycentric});
    const auto end =
        directional::geometry::surface_cell_tracing_detail::point_position(
            fixture.vertices, fixture.faces,
            directional::geometry::SurfaceTracePoint{
                segment.face, segment.endBarycentric});
    trace.length += (end - start).norm();
  }

  const auto input = directional::geometry::build_flow_rep_selection_input(
      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
      0.5);

  std::vector<const FlowRepArc *> branchArcs;
  for (const FlowRepArc &arc : input.arcs) {
    if (arc.singularitySupport && arc.family >= 0 &&
        arc.supportTraceId == 0) {
      branchArcs.push_back(&arc);
    }
  }
  ASSERT_EQ(branchArcs.size(), 3U);
  std::sort(branchArcs.begin(), branchArcs.end(),
            [](const FlowRepArc *first, const FlowRepArc *second) {
              return first->supportSegment < second->supportSegment;
            });
  EXPECT_FALSE(branchArcs[0]->initiallyActive);
  EXPECT_FALSE(branchArcs[1]->initiallyActive);
  ASSERT_TRUE(branchArcs[2]->initiallyActive);
  EXPECT_EQ(branchArcs[2]->supportSegment, 2);
  EXPECT_TRUE(branchArcs[2]->startEmbeddedAnchor);
  EXPECT_TRUE(branchArcs[2]->start.isApprox(fixture.vertices.row(0), 0.0));
  EXPECT_TRUE(branchArcs[2]->startBarycentric.isApprox(
      Eigen::RowVector3d(1.0, 0.0, 0.0), 0.0));
  EXPECT_TRUE(branchArcs[2]->endBarycentric.isApprox(
      continuation.endBarycentric, 0.0));

  std::vector<FlowRepArc> active;
  for (const FlowRepArc &arc : input.arcs) {
    if (arc.initiallyActive) {
      active.push_back(arc);
    }
  }
  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arrangement_arcs(active), options);

  int center = -1;
  for (const auto &node : complex.nodes) {
    if (node_is_source_vertex(node, fixture.faces, 0)) {
      ASSERT_EQ(center, -1);
      center = node.id;
    }
  }
  ASSERT_GE(center, 0);

  int radialEdges = 0;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.twin >= 0 && halfedge.id < halfedge.twin &&
        halfedge.singularitySupport &&
        (halfedge.from == center || halfedge.to == center)) {
      ++radialEdges;
    }
  }
  EXPECT_EQ(radialEdges, 3);

  for (const auto &cell : complex.cells) {
    bool touchesCenter = false;
    for (std::size_t index = 0; index < cell.halfedges.size(); ++index) {
      const int halfedgeId = cell.halfedges[index];
      const auto &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      touchesCenter = touchesCenter || halfedge.from == center ||
                      halfedge.to == center;
      if (!cell.boundaryCycle && !cell.halfedges.empty()) {
        const int nextId =
            cell.halfedges[(index + 1) % cell.halfedges.size()];
        EXPECT_NE(halfedge.twin, nextId);
      }
    }
    if (!cell.boundaryCycle && touchesCenter) {
      EXPECT_TRUE(cell.disk);
      EXPECT_EQ(cell.eulerCharacteristic, 1);
    }
  }
}

TEST(FlowRepStrandsPhase15,
     IndexAwareSingularitySeparatrixBecomesEmbeddedLayoutSupport) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  directional::geometry::SurfaceCellNetwork network;
  attach_source_authority(network, faces, {3}, {5});
  directional::geometry::SurfaceTraceSeed seed;
  seed.id = 0;
  seed.sourceId = 0;
  seed.provenance = directional::geometry::SurfaceSeedProvenance::Singularity;
  seed.point.face = 0;
  seed.point.barycentric << 1.0, 0.0, 0.0;
  network.seeds.push_back(seed);
  network.traces.resize(4);
  directional::geometry::SurfaceSingularitySeparatrix separatrix;
  separatrix.sourceVertex = 0;
  separatrix.singularityIndexNumerator = -1;
  separatrix.expectedValence = 5;
  separatrix.branch = 0;
  separatrix.initialFace = 0;
  separatrix.family = 0;
  separatrix.sign = 1;
  separatrix.trace.termination =
      directional::geometry::TraceTerminationReason::Budget;
  directional::geometry::SurfaceTraceSegment segment;
  segment.face = 0;
  segment.startBarycentric << 1.0, 0.0, 0.0;
  segment.endBarycentric << 0.5, 0.5, 0.0;
  segment.family = 0;
  segment.sign = 1;
  separatrix.trace.segments.push_back(segment);
  separatrix.trace.length = 0.5;
  network.singularSeparatrices.push_back(separatrix);

  const auto arcs = directional::geometry::build_flow_rep_arcs_from_network(
      vertices, faces, network);

  ASSERT_EQ(arcs.size(), 1U);
  EXPECT_TRUE(arcs.front().layoutSupport);
  EXPECT_TRUE(arcs.front().singularitySupport);
  EXPECT_TRUE(arcs.front().startEmbeddedAnchor);
  EXPECT_FALSE(arcs.front().endEmbeddedAnchor);
  EXPECT_FALSE(arcs.front().mandatoryRail);
  EXPECT_EQ(arcs.front().supportSeedId, 0);
  EXPECT_EQ(arcs.front().sourceFace, 0);
  ASSERT_TRUE(arcs.front().sourceTopologyRegion.has_value());
  ASSERT_TRUE(arcs.front().sourceIsolationSheet.has_value());
  EXPECT_EQ(*arcs.front().sourceTopologyRegion, test_topology_region_id(3));
  EXPECT_EQ(*arcs.front().sourceIsolationSheet, test_isolation_sheet_id(5));
  EXPECT_NEAR((arcs.front().start - vertices.row(0)).norm(), 0.0, 1.0e-12);
}

TEST(FlowRepStrandsPhase15,
     NonemptyDegenerateSingularitySeparatrixRemainsCompletionObligation) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  directional::geometry::SurfaceCellNetwork network;
  attach_source_authority(network, faces, {3}, {5});

  directional::geometry::SurfaceSingularitySeparatrix separatrix;
  separatrix.sourceVertex = 0;
  separatrix.singularityIndexNumerator = 1;
  separatrix.expectedValence = 3;
  separatrix.branch = 0;
  separatrix.initialFace = 0;
  separatrix.family = 0;
  separatrix.sign = 1;
  separatrix.trace.termination =
      directional::geometry::TraceTerminationReason::Degenerate;

  directional::geometry::SurfaceTraceSegment segment;
  segment.face = 0;
  segment.startBarycentric << 1.0, 0.0, 0.0;
  segment.endBarycentric << 0.25, 0.50, 0.25;
  segment.family = 0;
  segment.sign = 1;
  separatrix.trace.segments.push_back(segment);
  separatrix.trace.length =
      (directional::geometry::surface_cell_tracing_detail::point_position(
           vertices, faces,
           directional::geometry::SurfaceTracePoint{
               0, segment.endBarycentric}) -
       vertices.row(0))
          .norm();
  network.singularSeparatrices.push_back(separatrix);

  const auto arcs = directional::geometry::build_flow_rep_arcs_from_network(
      vertices, faces, network);

  ASSERT_EQ(arcs.size(), 1U);
  EXPECT_TRUE(arcs.front().layoutSupport);
  EXPECT_TRUE(arcs.front().singularitySupport);
  EXPECT_TRUE(arcs.front().startEmbeddedAnchor);
  EXPECT_FALSE(arcs.front().endEmbeddedAnchor);
  EXPECT_EQ(arcs.front().supportSeedId, 0);
  EXPECT_EQ(arcs.front().sourceFace, 0);
  ASSERT_TRUE(arcs.front().sourceTopologyRegion.has_value());
  ASSERT_TRUE(arcs.front().sourceIsolationSheet.has_value());
  EXPECT_EQ(*arcs.front().sourceTopologyRegion, test_topology_region_id(3));
  EXPECT_EQ(*arcs.front().sourceIsolationSheet, test_isolation_sheet_id(5));
}

TEST(FlowRepStrandsPhase15,
     InvalidSingularitySeparatrixMetadataStillFailsClosed) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  directional::geometry::SurfaceSingularitySeparatrix separatrix;
  separatrix.sourceVertex = 0;
  separatrix.singularityIndexNumerator = 1;
  separatrix.expectedValence = 3;
  separatrix.branch = 0;
  separatrix.initialFace = 0;
  separatrix.family = 0;
  separatrix.sign = 1;
  directional::geometry::SurfaceTraceSegment segment;
  segment.face = 0;
  segment.startBarycentric << 1.0, 0.0, 0.0;
  segment.endBarycentric << 0.25, 0.50, 0.25;
  segment.family = 0;
  segment.sign = 1;
  separatrix.trace.segments.push_back(segment);

  for (const auto termination :
       {directional::geometry::TraceTerminationReason::FieldMetadata,
        directional::geometry::TraceTerminationReason::SourceSheet}) {
    directional::geometry::SurfaceCellNetwork network;
    attach_source_authority(network, faces, {3}, {5});
    separatrix.trace.termination = termination;
    network.singularSeparatrices = {separatrix};

    const auto arcs = directional::geometry::build_flow_rep_arcs_from_network(
        vertices, faces, network);
    EXPECT_TRUE(arcs.empty());
  }
}

TEST(FlowRepStrandsPhase15,
     SingularityTransitionRingIsIntrinsicClosedAndDeterministic) {
  const TetrahedralSingularityFixture fixture =
      tetrahedral_singularity_fixture();

  const auto first = directional::geometry::build_flow_rep_selection_input(
      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
      0.5);
  const auto second = directional::geometry::build_flow_rep_selection_input(
      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
      0.5);

  ASSERT_EQ(first.arcs.size(), 6U);
  ASSERT_EQ(first.arcs.size(), second.arcs.size());
  std::vector<int> ringArcIds;
  std::map<std::uint64_t, int> ringEndpointDegree;
  int ringTraceId = -1;
  for (std::size_t index = 0; index < first.arcs.size(); ++index) {
    const FlowRepArc &arc = first.arcs[index];
    const FlowRepArc &repeat = second.arcs[index];
    EXPECT_EQ(arc.id, repeat.id);
    EXPECT_EQ(arc.sourceFace, repeat.sourceFace);
    EXPECT_EQ(arc.supportTraceId, repeat.supportTraceId);
    EXPECT_EQ(arc.supportSegment, repeat.supportSegment);
    EXPECT_TRUE(arc.startBarycentric.isApprox(repeat.startBarycentric, 0.0));
    EXPECT_TRUE(arc.endBarycentric.isApprox(repeat.endBarycentric, 0.0));
    if (!arc.singularitySupport || arc.family >= 0) {
      continue;
    }
    ringArcIds.push_back(arc.id);
    ringTraceId = ringTraceId < 0 ? arc.supportTraceId : ringTraceId;
    EXPECT_EQ(arc.supportTraceId, ringTraceId);
    EXPECT_EQ(arc.sameStrandHint, ringTraceId);
    EXPECT_EQ(arc.supportSeedId, 0);
    EXPECT_TRUE(arc.layoutSupport);
    EXPECT_FALSE(arc.mandatoryRail);
    EXPECT_TRUE(arc.startEmbeddedAnchor);
    EXPECT_TRUE(arc.endEmbeddedAnchor);
    EXPECT_TRUE(directional::geometry::flow_rep_detail::
                    arc_has_complete_provenance(arc));
    ++ringEndpointDegree[directional::geometry::flow_rep_detail::point_key(
        arc.start)];
    ++ringEndpointDegree[directional::geometry::flow_rep_detail::point_key(
        arc.end)];
  }
  ASSERT_EQ(ringArcIds.size(), 3U);
  ASSERT_EQ(ringEndpointDegree.size(), 3U);
  for (const auto &[endpoint, degree] : ringEndpointDegree) {
    (void)endpoint;
    EXPECT_EQ(degree, 2);
  }

  const FlowRepSparseNetwork selected =
      directional::geometry::select_sparse_flow_rep_network(
          first.arcs, first.coverageSamples, first.cycles);
  ASSERT_TRUE(selected.selectionSucceeded);
  const std::set<int> retained(selected.retainedArcIds.begin(),
                               selected.retainedArcIds.end());
  for (const int arcId : ringArcIds) {
    EXPECT_EQ(retained.count(arcId), 1U);
  }
}

TEST(FlowRepStrandsPhase15,
     SingularityTransitionRingMakesRadialSectorsNonBridgingDisks) {
  const TetrahedralSingularityFixture fixture =
      tetrahedral_singularity_fixture();
  const auto input = directional::geometry::build_flow_rep_selection_input(
      fixture.vertices, fixture.faces, fixture.targetSize, fixture.network,
      0.5);
  directional::geometry::SurfaceArrangementOptions options;
  options.insertBoundaryRails = false;
  const auto complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arrangement_arcs(input.arcs), options);

  int center = -1;
  for (const auto &node : complex.nodes) {
    if (node_is_source_vertex(node, fixture.faces, 0)) {
      ASSERT_EQ(center, -1);
      center = node.id;
    }
  }
  ASSERT_GE(center, 0);

  std::vector<std::vector<std::pair<int, int>>> adjacency(
      complex.nodes.size());
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.twin < 0 || halfedge.id > halfedge.twin) {
      continue;
    }
    adjacency[static_cast<std::size_t>(halfedge.from)].push_back(
        {halfedge.to, halfedge.id});
    adjacency[static_cast<std::size_t>(halfedge.to)].push_back(
        {halfedge.from, halfedge.id});
  }

  int radialEdges = 0;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.twin < 0 || halfedge.id > halfedge.twin ||
        !halfedge.singularitySupport ||
        (halfedge.from != center && halfedge.to != center)) {
      continue;
    }
    ++radialEdges;
    const int destination =
        halfedge.from == center ? halfedge.to : halfedge.from;
    std::vector<unsigned char> visited(complex.nodes.size(), 0);
    std::queue<int> queue;
    visited[static_cast<std::size_t>(center)] = 1;
    queue.push(center);
    while (!queue.empty()) {
      const int node = queue.front();
      queue.pop();
      for (const auto &[next, edgeId] :
           adjacency[static_cast<std::size_t>(node)]) {
        if (edgeId == halfedge.id ||
            visited[static_cast<std::size_t>(next)] != 0) {
          continue;
        }
        visited[static_cast<std::size_t>(next)] = 1;
        queue.push(next);
      }
    }
    EXPECT_NE(visited[static_cast<std::size_t>(destination)], 0)
        << "radial singularity support must be part of a local cycle";
  }
  EXPECT_EQ(radialEdges, 3);

  int centerCells = 0;
  for (const auto &cell : complex.cells) {
    bool touchesCenter = false;
    for (const int halfedgeId : cell.halfedges) {
      const auto &halfedge =
          complex.halfedges[static_cast<std::size_t>(halfedgeId)];
      touchesCenter = touchesCenter || halfedge.from == center ||
                      halfedge.to == center;
    }
    if (!cell.boundaryCycle && touchesCenter) {
      ++centerCells;
      EXPECT_TRUE(cell.disk);
      EXPECT_EQ(cell.boundaryComponentCount, 1);
      EXPECT_EQ(cell.eulerCharacteristic, 1);
    }
  }
  EXPECT_EQ(centerCells, 3);
}


TEST(FlowRepStrandsPhase15,
     IntrinsicEndpointKeyMatchesSharedSourceEdgeAcrossFaceCharts) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           1, 0, 3;

  FlowRepArc first;
  first.sourceFace = 0;
  first.sourceTopologyRegion = test_topology_region_id(7);
  first.startBarycentric << 0.25, 0.75, 0.0;
  first.endBarycentric << 0.10, 0.90, 0.0;

  FlowRepArc second;
  second.sourceFace = 1;
  second.sourceTopologyRegion = test_topology_region_id(7);
  second.startBarycentric << 0.75, 0.25, 0.0;
  second.endBarycentric << 0.90, 0.10, 0.0;

  directional::geometry::flow_rep_detail::assign_intrinsic_endpoint_keys(
      first, faces);
  directional::geometry::flow_rep_detail::assign_intrinsic_endpoint_keys(
      second, faces);

  ASSERT_TRUE(first.startIntrinsicEndpointKeyValid);
  ASSERT_TRUE(second.startIntrinsicEndpointKeyValid);
  EXPECT_EQ(directional::geometry::flow_rep_detail::embedded_endpoint_key(
                first, true),
            directional::geometry::flow_rep_detail::embedded_endpoint_key(
                second, true));
  EXPECT_EQ(directional::geometry::flow_rep_detail::embedded_endpoint_key(
                first, false),
            directional::geometry::flow_rep_detail::embedded_endpoint_key(
                second, false));
}

TEST(FlowRepStrandsPhase15,
     IntrinsicEndpointKeySeparatesWorldCloseSurfacePoints) {
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  FlowRepArc first;
  first.sourceFace = 0;
  first.sourceTopologyRegion = test_topology_region_id(2);
  first.start << 0.0, 0.0, 0.0;
  first.end << 1.0, 0.0, 0.0;
  first.startBarycentric << 1.0 - 1.0e-8, 1.0e-8, 0.0;
  first.endBarycentric << 0.0, 1.0, 0.0;

  FlowRepArc second = first;
  second.start << 4.0e-10, 0.0, 0.0;
  second.startBarycentric << 1.0 - 2.0e-8, 2.0e-8, 0.0;

  // The legacy world-space key rounds these distinct intrinsic points into
  // one endpoint. Production arcs must instead use their source-mesh key.
  EXPECT_EQ(directional::geometry::flow_rep_detail::embedded_endpoint_key(
                first, true),
            directional::geometry::flow_rep_detail::embedded_endpoint_key(
                second, true));

  directional::geometry::flow_rep_detail::assign_intrinsic_endpoint_keys(
      first, faces);
  directional::geometry::flow_rep_detail::assign_intrinsic_endpoint_keys(
      second, faces);

  ASSERT_TRUE(first.startIntrinsicEndpointKeyValid);
  ASSERT_TRUE(second.startIntrinsicEndpointKeyValid);
  EXPECT_NE(directional::geometry::flow_rep_detail::embedded_endpoint_key(
                first, true),
            directional::geometry::flow_rep_detail::embedded_endpoint_key(
                second, true));
}

TEST(FlowRepStrandsPhase15,
     ManualArcEndpointKeyRetainsWorldSpaceFallback) {
  FlowRepArc first = arc(0, 1.0, 2.0, 3.0, 4.0);
  FlowRepArc second = first;
  first.sourceTopologyRegion = test_topology_region_id(5);
  second.sourceTopologyRegion = test_topology_region_id(5);

  EXPECT_FALSE(first.startIntrinsicEndpointKeyValid);
  EXPECT_EQ(directional::geometry::flow_rep_detail::embedded_endpoint_key(
                first, true),
            directional::geometry::flow_rep_detail::embedded_endpoint_key(
                second, true));

  second.sourceTopologyRegion = test_topology_region_id(6);
  EXPECT_NE(directional::geometry::flow_rep_detail::embedded_endpoint_key(
                first, true),
            directional::geometry::flow_rep_detail::embedded_endpoint_key(
                second, true));
}

TEST(FlowRepStrandsPhase15, SignedAffinityCuesAreDeterministic) {
  directional::geometry::FlowRepSparseOptions options;
  const auto a = arc(0, 0.0, 0.0, 1.0, 0.0, 0);
  const auto b = arc(1, 1.0, 0.0, 2.0, 0.0, 0);
  const auto c = arc(2, 1.0, 0.0, 1.0, 1.0, 1);
  const auto d = arc(3, 0.5, -1.0, 0.5, 1.0, 1);
  auto f0 = arc(4, 3.0, 0.0, 4.0, 0.0, 0);
  auto f1 = arc(5, 4.0, 0.0, 5.0, 0.0, 0);
  f0.hardFeatureRail = true;
  f1.hardFeatureRail = true;
  f0.featureClass = 1;
  f1.featureClass = 2;

  const auto parallel =
      directional::geometry::compute_flow_rep_affinity(a, b, options);
  EXPECT_GT(parallel.score, 0.0);
  EXPECT_EQ(parallel.cue,
            directional::geometry::FlowRepAffinityCue::ParallelAdjacent);

  const auto orthogonal =
      directional::geometry::compute_flow_rep_affinity(a, c, options);
  EXPECT_LT(orthogonal.score, 0.0);
  EXPECT_EQ(orthogonal.cue,
            directional::geometry::FlowRepAffinityCue::OrthogonalJunction);

  const auto crossing =
      directional::geometry::compute_flow_rep_affinity(a, d, options);
  EXPECT_LT(crossing.score, 0.0);
  EXPECT_EQ(crossing.cue,
            directional::geometry::FlowRepAffinityCue::GeometricCrossing);

  const auto conflict =
      directional::geometry::compute_flow_rep_affinity(f0, f1, options);
  EXPECT_LT(conflict.score, 0.0);
  EXPECT_EQ(conflict.cue,
            directional::geometry::FlowRepAffinityCue::FeatureConflict);
}

TEST(FlowRepStrandsPhase15, GreedyMergeTieBreaksByClusterIds) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 1.0, 0.0, 2.0, 0.0),
      arc(2, 0.0, 1.0, 1.0, 1.0), arc(3, 1.0, 1.0, 2.0, 1.0)};

  const auto strands = directional::geometry::cluster_flow_rep_strands(arcs);

  ASSERT_EQ(strands.size(), 2U);
  ASSERT_EQ(strands[0].arcIds.size(), 2U);
  EXPECT_EQ(strands[0].arcIds[0], 0);
  EXPECT_EQ(strands[0].arcIds[1], 1);
}

TEST(FlowRepStrandsPhase15, SameStrandCrossingBlocksMerge) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 1.0), arc(1, 0.0, 1.0, 1.0, 0.0)};

  const auto strands = directional::geometry::cluster_flow_rep_strands(arcs);

  EXPECT_EQ(strands.size(), 2U);
}

TEST(FlowRepStrandsPhase15, ClosedLoopsArePreferredOverOpenLines) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 1.0, 0.0, 1.0, 1.0),
      arc(2, 1.0, 1.0, 0.0, 1.0), arc(3, 0.0, 1.0, 0.0, 0.0),
      arc(4, 2.0, 0.0, 3.0, 0.0), arc(5, 3.0, 0.0, 4.0, 0.0)};
  for (int i = 0; i < 4; ++i) {
    arcs[static_cast<std::size_t>(i)].family = i % 2;
    arcs[static_cast<std::size_t>(i)].sameStrandHint = 10;
  }

  const auto strands = directional::geometry::cluster_flow_rep_strands(arcs);

  ASSERT_FALSE(strands.empty());
  EXPECT_TRUE(strands.front().closed);
}

TEST(FlowRepStrandsPhase15, ExtractsMaximalFlowlinesFromStrands) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 1.0, 0.0, 2.0, 0.0),
      arc(2, 2.0, 0.0, 3.0, 0.0)};

  const auto strands = directional::geometry::cluster_flow_rep_strands(arcs);
  const auto flowlines =
      directional::geometry::extract_flow_rep_flowlines(arcs, strands);

  ASSERT_EQ(flowlines.size(), 1U);
  EXPECT_EQ(flowlines.front().arcIds.size(), 3U);
  EXPECT_FALSE(flowlines.front().closed);
  EXPECT_NEAR(flowlines.front().length, 3.0, 1.0e-12);
}

TEST(FlowRepStrandsPhase15, NetworkConversionUsesOnlyAcceptedClosedBoundaries) {
  directional::geometry::SurfaceCellNetwork network;
  directional::geometry::SurfaceTraceSegment halfTraceSegment;
  halfTraceSegment.face = 0;
  halfTraceSegment.startBarycentric << 0.5, 0.5, 0.0;
  halfTraceSegment.endBarycentric << 0.25, 0.25, 0.5;
  directional::geometry::SurfaceTraceResult halfTrace;
  halfTrace.segments.push_back(halfTraceSegment);
  network.traces.push_back(halfTrace);

  directional::geometry::SurfaceTraceSegment boundarySegment;
  boundarySegment.face = 0;
  boundarySegment.startBarycentric << 0.8, 0.2, 0.0;
  boundarySegment.endBarycentric << 0.6, 0.2, 0.2;
  boundarySegment.family = 1;
  directional::geometry::SurfaceCellProposal accepted;
  accepted.seedId = 17;
  accepted.accepted = true;
  accepted.rejection = directional::geometry::CellRejectionReason::Accepted;
  accepted.boundaryPaths[0].push_back(boundarySegment);
  network.proposals.push_back(accepted);

  directional::geometry::SurfaceCellProposal rejected = accepted;
  rejected.accepted = false;
  rejected.rejection = directional::geometry::CellRejectionReason::Closure;
  rejected.boundaryPaths[0][0].family = 0;
  network.proposals.push_back(rejected);

  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  attach_source_authority(network, faces, {3}, {5});

  const auto arcs =
      directional::geometry::build_flow_rep_arcs_from_network(vertices, faces,
                                                              network);

  ASSERT_EQ(arcs.size(), 1U);
  EXPECT_EQ(arcs[0].sourceFace, 0);
  EXPECT_EQ(arcs[0].family, 1);
  EXPECT_FALSE(arcs[0].mandatoryRail);
  EXPECT_FALSE(arcs[0].hardFeatureRail);
  ASSERT_TRUE(arcs[0].sourceTopologyRegion.has_value());
  ASSERT_TRUE(arcs[0].sourceIsolationSheet.has_value());
  EXPECT_EQ(*arcs[0].sourceTopologyRegion, test_topology_region_id(3));
  EXPECT_EQ(*arcs[0].sourceIsolationSheet, test_isolation_sheet_id(5));
  EXPECT_EQ(arcs[0].proposalId, 0);
  EXPECT_EQ(arcs[0].proposalSeedId, 17);
  EXPECT_EQ(arcs[0].proposalSide, 0);
  EXPECT_EQ(arcs[0].proposalBoundarySegment, 0);
  EXPECT_NEAR((arcs[0].startBarycentric - boundarySegment.startBarycentric)
                  .norm(),
              0.0, 1.0e-12);
  EXPECT_NEAR((arcs[0].endBarycentric - boundarySegment.endBarycentric).norm(),
              0.0, 1.0e-12);
}

TEST(FlowRepStrandsPhase15,
     RailEndpointTracesBecomeDeduplicatedOptionalLayoutSupport) {
  directional::geometry::SurfaceCellNetwork network;

  const Eigen::RowVector3d edge01Mid(0.5, 0.5, 0.0);
  const Eigen::RowVector3d edge12Mid(0.0, 0.5, 0.5);
  const auto make_rail = [&](const int id, const int curve,
                             const Eigen::RowVector3d &start,
                             const Eigen::RowVector3d &end) {
    directional::geometry::SurfaceCellRail rail(directional::tests::test_hard_rail_id(id));
    rail.curveId = curve;
    rail.component = 3;
    rail.kind = directional::geometry::SurfaceCellRailKind::HardFeature;
    directional::geometry::SurfaceCellRailSample a;
    a.sourceFace = 0;
    a.barycentric = start;
    a.position = Eigen::RowVector3d(start[1], start[2], 0.0);
    a.railParameter = 0.0;
    directional::geometry::SurfaceCellRailSample b = a;
    b.barycentric = end;
    b.position = Eigen::RowVector3d(end[1], end[2], 0.0);
    b.railParameter = 1.0;
    rail.samples = {a, b};
    return rail;
  };
  network.authoritativeRails.push_back(
      make_rail(7, 17, Eigen::RowVector3d(1.0, 0.0, 0.0),
                Eigen::RowVector3d(0.0, 1.0, 0.0)));
  network.authoritativeRails.push_back(
      make_rail(8, 18, Eigen::RowVector3d(0.0, 1.0, 0.0),
                Eigen::RowVector3d(0.0, 0.0, 1.0)));

  directional::geometry::SurfaceTraceSeed firstSeed;
  firstSeed.id = 41;
  firstSeed.point = {0, edge01Mid};
  firstSeed.provenance =
      directional::geometry::SurfaceSeedProvenance::Feature;
  directional::geometry::SurfaceTraceSeed secondSeed;
  secondSeed.id = 42;
  secondSeed.point = {0, edge12Mid};
  secondSeed.provenance =
      directional::geometry::SurfaceSeedProvenance::Feature;
  network.seeds = {firstSeed, secondSeed};
  network.traces.resize(8);

  directional::geometry::SurfaceTraceSegment forward;
  forward.face = 0;
  forward.startBarycentric = edge01Mid;
  forward.endBarycentric = edge12Mid;
  forward.family = 1;
  network.traces[0].segments = {forward};
  network.traces[0].termination =
      directional::geometry::TraceTerminationReason::Feature;
  directional::geometry::SurfaceTraceSegment reverse = forward;
  std::swap(reverse.startBarycentric, reverse.endBarycentric);
  reverse.sign = -1;
  network.traces[4].segments = {reverse};
  network.traces[4].termination =
      directional::geometry::TraceTerminationReason::Feature;

  directional::geometry::SurfaceTraceSegment unresolved = forward;
  unresolved.endBarycentric << 0.2, 0.4, 0.4;
  network.traces[1].segments = {unresolved};
  network.traces[1].termination =
      directional::geometry::TraceTerminationReason::Budget;

  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  attach_source_authority(network, faces, {3}, {5});
  const auto arcs = directional::geometry::build_flow_rep_arcs_from_network(
      vertices, faces, network);

  ASSERT_EQ(3U, arcs.size());
  const FlowRepArc &support = arcs.back();
  EXPECT_TRUE(support.layoutSupport);
  EXPECT_FALSE(support.mandatoryRail);
  EXPECT_FALSE(support.hardFeatureRail);
  EXPECT_FALSE(support.boundaryRail);
  EXPECT_EQ(0, support.supportTraceId);
  EXPECT_EQ(41, support.supportSeedId);
  EXPECT_EQ(0, support.supportSegment);
  EXPECT_EQ(support.supportTraceId, support.sameStrandHint);
  EXPECT_LT(support.strandProvenance, -1);
  EXPECT_TRUE(directional::geometry::flow_rep_detail::
                  arc_has_complete_provenance(support));
  EXPECT_TRUE(std::none_of(arcs.begin(), arcs.end(), [](const FlowRepArc &value) {
    return value.layoutSupport && value.supportTraceId == 1;
  }));

  const Eigen::VectorXd targetSize = Eigen::VectorXd::Ones(3);
  const auto selectionInput =
      directional::geometry::build_flow_rep_selection_input(
          vertices, faces, targetSize, network, 1.0);
  const FlowRepSparseNetwork selected =
      directional::geometry::select_sparse_flow_rep_network(
          selectionInput.arcs, selectionInput.coverageSamples,
          selectionInput.cycles);
  ASSERT_TRUE(selected.selectionSucceeded);
  EXPECT_EQ(FlowRepSelectionFailureCode::None, selected.failureCode);
  EXPECT_EQ(arcs.size(), selected.retainedArcIds.size());
  EXPECT_FALSE(selected.cycleEvidenceUsed);
  EXPECT_EQ(0, selected.cycleEvidenceCount);
}

TEST(FlowRepStrandsPhase15,
     SelectionInputBuildsNormalizedCoverageAndClosedCycleEvidence) {
  directional::geometry::SurfaceCellNetwork network;
  directional::geometry::SurfaceCellProposal proposal;
  proposal.seedId = 23;
  proposal.accepted = true;
  proposal.rejection = directional::geometry::CellRejectionReason::Accepted;
  for (int side = 0; side < 4; ++side) {
    directional::geometry::SurfaceTraceSegment segment;
    segment.face = 0;
    segment.family = side % 2;
    segment.startBarycentric =
        side == 0   ? Eigen::RowVector3d(1.0, 0.0, 0.0)
        : side == 1 ? Eigen::RowVector3d(0.0, 1.0, 0.0)
        : side == 2 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
                    : Eigen::RowVector3d(0.5, 0.5, 0.0);
    segment.endBarycentric =
        side == 0   ? Eigen::RowVector3d(0.0, 1.0, 0.0)
        : side == 1 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
        : side == 2 ? Eigen::RowVector3d(0.5, 0.5, 0.0)
                    : Eigen::RowVector3d(1.0, 0.0, 0.0);
    proposal.boundaryPaths[static_cast<std::size_t>(side)].push_back(segment);
  }
  network.proposals.push_back(proposal);

  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  attach_source_authority(network, faces, {3}, {5});
  Eigen::VectorXd targetSize(3);
  targetSize << 0.25, 0.5, 1.0;

  const auto input = directional::geometry::build_flow_rep_selection_input(
      vertices, faces, targetSize, network);

  ASSERT_EQ(input.arcs.size(), 4U);
  ASSERT_GT(input.coverageSamples.size(), input.arcs.size());
  ASSERT_EQ(input.cycles.size(), 1U);
  EXPECT_EQ(input.cycles[0].sideArcIds,
            (std::vector<std::vector<int>>{{0}, {1}, {2}, {3}}));
  EXPECT_EQ(input.cycles[0].boundaryArcIds, (std::vector<int>{0, 1, 2, 3}));
  std::set<int> sampledArcIds;
  for (const auto &sample : input.coverageSamples) {
    EXPECT_GT(sample.targetSize, 0.0);
    EXPECT_EQ(sample.sourceFace, 0);
    ASSERT_TRUE(sample.sourceTopologyRegion.has_value());
    ASSERT_TRUE(sample.sourceIsolationSheet.has_value());
    EXPECT_EQ(*sample.sourceTopologyRegion, test_topology_region_id(3));
    EXPECT_EQ(*sample.sourceIsolationSheet, test_isolation_sheet_id(5));
    sampledArcIds.insert(sample.sourceArcId);
  }
  EXPECT_EQ(sampledArcIds, (std::set<int>{0, 1, 2, 3}));
  const auto selected = directional::geometry::select_sparse_flow_rep_network(
      input.arcs, input.coverageSamples, input.cycles);
  EXPECT_TRUE(selected.selectionSucceeded);
  EXPECT_EQ(selected.failureCode, FlowRepSelectionFailureCode::None);
}

TEST(FlowRepStrandsPhase15,
     ProposalRailSegmentsRemainMandatoryCycleEvidence) {
  directional::geometry::SurfaceCellNetwork network;
  directional::geometry::SurfaceCellProposal proposal;
  proposal.seedId = 31;
  proposal.accepted = true;
  proposal.rejection = directional::geometry::CellRejectionReason::Accepted;
  for (int side = 0; side < 4; ++side) {
    directional::geometry::SurfaceTraceSegment segment;
    segment.face = 0;
    segment.family = side % 2;
    segment.startBarycentric =
        side == 0   ? Eigen::RowVector3d(1.0, 0.0, 0.0)
        : side == 1 ? Eigen::RowVector3d(0.0, 1.0, 0.0)
        : side == 2 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
                    : Eigen::RowVector3d(0.5, 0.5, 0.0);
    segment.endBarycentric =
        side == 0   ? Eigen::RowVector3d(0.0, 1.0, 0.0)
        : side == 1 ? Eigen::RowVector3d(0.0, 0.0, 1.0)
        : side == 2 ? Eigen::RowVector3d(0.5, 0.5, 0.0)
                    : Eigen::RowVector3d(1.0, 0.0, 0.0);
    if (side == 0) {
      segment.railId = directional::tests::test_hard_rail_id(8);
      segment.curveId = 9;
      segment.railT0 = 0.0;
      segment.railT1 = 1.0;
    }
    proposal.boundaryPaths[static_cast<std::size_t>(side)].push_back(segment);
  }
  network.proposals.push_back(proposal);

  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  attach_source_authority(network, faces, {3}, {5});
  const Eigen::VectorXd targetSize = Eigen::VectorXd::Ones(3);

  const auto input = directional::geometry::build_flow_rep_selection_input(
      vertices, faces, targetSize, network);
  ASSERT_EQ(input.cycles.size(), 1U);
  ASSERT_EQ(input.cycles[0].sideArcIds[0].size(), 1U);
  const int railArcId = input.cycles[0].sideArcIds[0][0];
  ASSERT_GE(railArcId, 0);
  ASSERT_LT(railArcId, static_cast<int>(input.arcs.size()));
  EXPECT_TRUE(input.arcs[static_cast<std::size_t>(railArcId)].mandatoryRail);
  EXPECT_EQ(input.arcs[static_cast<std::size_t>(railArcId)].proposalId, 0);

  const auto selected = directional::geometry::select_sparse_flow_rep_network(
      input.arcs, input.coverageSamples, input.cycles);
  EXPECT_TRUE(selected.selectionSucceeded);
  EXPECT_EQ(selected.retainedMandatoryRails, selected.mandatoryRails);
}

TEST(FlowRepStrandsPhase15,
     SourceTriangleSplitsRemainOneLogicalCycleSide) {
  std::vector<FlowRepArc> arcs = square_selection_arcs();
  FlowRepArc secondSegment = arcs[0];
  secondSegment.id = 4;
  secondSegment.proposalBoundarySegment = 1;
  secondSegment.start = arcs[0].end;
  secondSegment.end << 2.0, 0.0, 0.0;
  secondSegment.startBarycentric = arcs[0].endBarycentric;
  secondSegment.endBarycentric << 0.0, 0.0, 1.0;
  arcs.push_back(secondSegment);

  FlowRepCycleInput cycle = square_cycle();
  cycle.sideArcIds[0] = {0, 4};
  cycle.boundaryArcIds = {0, 1, 2, 3, 4};
  cycle.sideCounts = {1, 1, 1, 1};
  cycle.normals.push_back(Eigen::RowVector3d(0.0, 0.0, 1.0));
  cycle.boundaryNormalA.push_back(Eigen::RowVector3d(0.0, 0.0, 1.0));
  cycle.boundaryNormalB.push_back(Eigen::RowVector3d(0.0, 0.0, 1.0));
  cycle.distanceA.push_back(0.5);
  cycle.distanceB.push_back(0.5);
  cycle.surfaceDistances.push_back(0.0);

  const auto selected = directional::geometry::select_sparse_flow_rep_network(
      arcs, coverage_for_active_arcs(arcs), {cycle});
  ASSERT_TRUE(selected.selectionSucceeded);
  ASSERT_EQ(selected.cycleEvaluations.size(), 1U);
  EXPECT_EQ(selected.cycleEvaluations[0].patchClass,
            directional::geometry::FlowRepPatchClass::FourSided);
  EXPECT_TRUE(selected.cycleEvaluations[0].quadrangulable);
}

TEST(FlowRepStrandsPhase15, CrossingPredicateUsesSourceTriangleCoordinates) {
  auto a = embedded_arc(0, Eigen::RowVector3d(0.50, 0.50, 0.00),
                        Eigen::RowVector3d(0.25, 0.25, 0.50));
  auto b = embedded_arc(1, Eigen::RowVector3d(0.50, 0.00, 0.50),
                        Eigen::RowVector3d(0.25, 0.50, 0.25));
  a.start << 0.0, 0.0, 0.0;
  a.end << 0.0, 0.0, 1.0;
  b.start << 1.0, 0.0, 0.0;
  b.end << 1.0, 0.0, 1.0;

  const auto affinity = directional::geometry::compute_flow_rep_affinity(a, b);

  EXPECT_LT(affinity.score, 0.0);
  EXPECT_EQ(affinity.cue,
            directional::geometry::FlowRepAffinityCue::GeometricCrossing);
}

TEST(FlowRepStrandsPhase15, FlowlinesSplitAtJunctions) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 1.0, 0.0, 2.0, 0.0),
      arc(2, 1.0, 0.0, 1.0, 1.0)};
  for (auto &a : arcs) {
    a.sameStrandHint = 1;
  }

  directional::geometry::FlowRepStrand strand;
  strand.id = 0;
  strand.arcIds = {0, 1, 2};
  const auto flowlines =
      directional::geometry::extract_flow_rep_flowlines(arcs, {strand});

  EXPECT_EQ(flowlines.size(), 3U);
  for (const auto &flowline : flowlines) {
    EXPECT_EQ(flowline.arcIds.size(), 1U);
  }
}

TEST(FlowRepStrandsPhase15, InvalidArcIdentityFailsWithoutDroppingDenseArcs) {
  std::vector<FlowRepArc> arcs = square_selection_arcs();
  arcs[2].id = 17;

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, coverage_for_active_arcs(arcs), {square_cycle()});

  EXPECT_FALSE(network.selectionSucceeded);
  EXPECT_EQ(network.failureCode,
            FlowRepSelectionFailureCode::InvalidArcIdentity);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{0, 1, 2, 3}));
  EXPECT_TRUE(network.removedArcIds.empty());
}

TEST(FlowRepStrandsPhase15, EmptyEvidenceFailsClosedAndRetainsDenseNetwork) {
  const std::vector<FlowRepArc> arcs = square_selection_arcs();

  const auto network =
      directional::geometry::select_sparse_flow_rep_network(arcs);

  EXPECT_FALSE(network.selectionSucceeded);
  EXPECT_EQ(network.failureCode,
            FlowRepSelectionFailureCode::MissingCoverageEvidence);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{0, 1, 2, 3}));
  EXPECT_TRUE(network.removedArcIds.empty());
  EXPECT_EQ(network.acceptedTransactions, 0);
}

TEST(FlowRepStrandsPhase15, MissingCycleEvidenceFailsAfterCoverageValidation) {
  const std::vector<FlowRepArc> arcs = square_selection_arcs();
  const auto samples = coverage_for_active_arcs(arcs);

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {});

  EXPECT_FALSE(network.selectionSucceeded);
  EXPECT_TRUE(network.coverageEvidenceUsed);
  EXPECT_EQ(network.failureCode,
            FlowRepSelectionFailureCode::MissingCycleEvidence);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{0, 1, 2, 3}));
}

TEST(FlowRepStrandsPhase15, IncompleteEmbeddedProvenanceFailsClosed) {
  std::vector<FlowRepArc> arcs = square_selection_arcs();
  arcs[2].sourceIsolationSheet.reset();
  auto samples = coverage_for_active_arcs(arcs);

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {square_cycle()});

  EXPECT_FALSE(network.selectionSucceeded);
  EXPECT_EQ(network.failureCode,
            FlowRepSelectionFailureCode::IncompleteArcProvenance);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{0, 1, 2, 3}));
}

TEST(FlowRepStrandsPhase15,
     CoverageIsSameSheetIntrinsicAndNormalizedByLocalTargetSize) {
  std::vector<FlowRepArc> arcs = square_selection_arcs();
  FlowRepArc decoy = mandatory_rail(4, 0.02, 9);
  arcs.push_back(decoy);
  auto samples = coverage_for_active_arcs(arcs);
  const Eigen::RowVector3d offsetPosition(0.5, 0.02, 0.0);
  samples[0] = coverage_sample(arcs[0], 0.1, &offsetPosition);

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {square_cycle()});

  ASSERT_TRUE(network.selectionSucceeded)
      << directional::geometry::flow_rep_selection_failure_name(
             network.failureCode);
  EXPECT_TRUE(network.coverageEvidenceUsed);
  EXPECT_NEAR(network.denseCoverageMax, 0.2, 1.0e-12);
  EXPECT_NEAR(network.sparseCoverageMax, 0.2, 1.0e-12);
}

TEST(FlowRepStrandsPhase15, RejectedRemovalsRebuildAffectedCycles) {
  const std::vector<FlowRepArc> arcs = square_selection_arcs();
  const auto samples = coverage_for_active_arcs(arcs);

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {square_cycle()});

  ASSERT_TRUE(network.selectionSucceeded);
  EXPECT_EQ(network.acceptedTransactions, 0);
  EXPECT_EQ(network.cycleRebuilds, 4);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{0, 1, 2, 3}));
  ASSERT_EQ(network.cycleEvaluations.size(), 1U);
  EXPECT_TRUE(network.cycleEvaluations.front().descriptive);
  EXPECT_TRUE(network.cycleEvaluations.front().quadrangulable);
}

TEST(FlowRepStrandsPhase15,
     CyclePreservingSubstitutionRebuildsAndCommitsTransactionally) {
  std::vector<FlowRepArc> arcs = square_selection_arcs();
  FlowRepArc substitute = arcs[0];
  substitute.id = 4;
  substitute.initiallyActive = false;
  substitute.dominance = 0.1;
  substitute.alignmentCost = 0.1;
  arcs.push_back(substitute);
  arcs[0].dominance = 2.0;
  arcs[0].alignmentCost = 2.0;
  arcs[0].substitutions = {4};
  const auto samples = coverage_for_active_arcs(arcs);

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {square_cycle()});

  ASSERT_TRUE(network.selectionSucceeded);
  EXPECT_EQ(network.acceptedTransactions, 1);
  EXPECT_GT(network.cycleRebuilds, 4);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{1, 2, 3, 4}));
  EXPECT_EQ(network.removedArcIds, (std::vector<int>{0}));
  ASSERT_EQ(network.cycleEvaluations.size(), 1U);
  EXPECT_TRUE(network.cycleEvaluations.front().descriptive);
  EXPECT_TRUE(network.cycleEvaluations.front().quadrangulable);
}


TEST(FlowRepStrandsPhase15,
     MultiArcProposalSideIsRemovedOrRolledBackAsOneTransaction) {
  std::vector<FlowRepArc> arcs = {
      selection_arc(0, {0.0, 0.0, 0.0}, {0.5, 0.0, 0.0}, 0, 0),
      selection_arc(1, {0.5, 0.0, 0.0}, {1.0, 0.0, 0.0}, 0, 1),
      selection_arc(2, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, 1),
      selection_arc(3, {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, 2),
      selection_arc(4, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, 3),
  };
  FlowRepCycleInput cycle = feasible_cycle();
  cycle.id = 0;
  cycle.proposalId = 0;
  cycle.sideArcIds = {{0, 1}, {2}, {3}, {4}};
  cycle.boundaryArcIds = {0, 1, 2, 3, 4};
  cycle.sideCounts = {1, 1, 1, 1};

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, coverage_for_active_arcs(arcs), {cycle});

  ASSERT_TRUE(network.selectionSucceeded);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{0, 1, 2, 3, 4}));
  EXPECT_EQ(network.acceptedTransactions, 0);
  EXPECT_EQ(network.attemptedStrandTransactions, 4);
  EXPECT_EQ(network.rejectedStrandTransactions, 4);
  EXPECT_EQ(network.cycleRebuilds, 4);
  EXPECT_EQ(network.retainedFlowlines, 4);
  EXPECT_EQ(network.removedFlowlines, 0);
}

TEST(FlowRepStrandsPhase15,
     MultiArcStrandSubstitutionCommitsAllSegmentsAtomically) {
  std::vector<FlowRepArc> arcs = {
      selection_arc(0, {0.0, 0.0, 0.0}, {0.5, 0.0, 0.0}, 0, 0),
      selection_arc(1, {0.5, 0.0, 0.0}, {1.0, 0.0, 0.0}, 0, 1),
      selection_arc(2, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, 1),
      selection_arc(3, {1.0, 1.0, 0.0}, {0.0, 1.0, 0.0}, 2),
      selection_arc(4, {0.0, 1.0, 0.0}, {0.0, 0.0, 0.0}, 3),
  };
  for (int original = 0; original < 2; ++original) {
    FlowRepArc substitute = arcs[static_cast<std::size_t>(original)];
    substitute.id = static_cast<int>(arcs.size());
    substitute.initiallyActive = false;
    substitute.dominance = 0.05;
    substitute.alignmentCost = 0.05;
    arcs[static_cast<std::size_t>(original)].dominance = 2.0;
    arcs[static_cast<std::size_t>(original)].alignmentCost = 2.0;
    arcs[static_cast<std::size_t>(original)].substitutions = {substitute.id};
    arcs.push_back(substitute);
  }
  FlowRepCycleInput cycle = feasible_cycle();
  cycle.id = 0;
  cycle.proposalId = 0;
  cycle.sideArcIds = {{0, 1}, {2}, {3}, {4}};
  cycle.boundaryArcIds = {0, 1, 2, 3, 4};
  cycle.sideCounts = {1, 1, 1, 1};

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, coverage_for_active_arcs(arcs), {cycle});

  ASSERT_TRUE(network.selectionSucceeded);
  EXPECT_EQ(network.acceptedTransactions, 1);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{2, 3, 4, 5, 6}));
  EXPECT_EQ(network.removedArcIds, (std::vector<int>{0, 1}));
  EXPECT_EQ(network.retainedFlowlines, 4);
  EXPECT_EQ(network.removedFlowlines, 1);
}

TEST(FlowRepStrandsPhase15,
     TransactionalFlowlinesSplitAtNetworkJunctionsAcrossSourceFaces) {
  std::vector<FlowRepArc> arcs = {
      selection_arc(0, {0.0, 0.0, 0.0}, {1.0, 0.0, 0.0}, 0, 0),
      selection_arc(1, {1.0, 0.0, 0.0}, {2.0, 0.0, 0.0}, 0, 1),
      selection_arc(2, {1.0, 0.0, 0.0}, {1.0, 1.0, 0.0}, 1, 0),
  };
  arcs[1].sourceFace = 1;
  arcs[1].sourceTopologyRegion = arcs[0].sourceTopologyRegion;
  arcs[1].sourceIsolationSheet = arcs[0].sourceIsolationSheet;
  arcs[1].startBarycentric << 1.0, 0.0, 0.0;
  arcs[1].endBarycentric << 0.0, 1.0, 0.0;

  const auto flowlines =
      directional::geometry::flow_rep_detail::extract_transactional_flowlines(
          arcs, {0, 1, 2});

  ASSERT_EQ(flowlines.size(), 3U);
  for (const auto &flowline : flowlines) {
    EXPECT_EQ(flowline.arcIds.size(), 1U);
  }
}

TEST(FlowRepStrandsPhase15, CycleNormalInterpolationAndP90IgnoreOutlier) {
  auto cycle = feasible_cycle();
  cycle.normals.push_back(Eigen::RowVector3d(0.0, 0.0, -1.0));
  cycle.boundaryNormalA.push_back(Eigen::RowVector3d(0.0, 0.0, 1.0));
  cycle.boundaryNormalB.push_back(Eigen::RowVector3d(0.0, 0.0, 1.0));
  cycle.distanceA.push_back(1.0);
  cycle.distanceB.push_back(1.0);
  cycle.surfaceDistances.push_back(0.01);

  const auto evaluation = directional::geometry::evaluate_flow_rep_cycle(cycle);

  EXPECT_TRUE(evaluation.descriptive);
  EXPECT_TRUE(evaluation.quadrangulable);
  EXPECT_NEAR(evaluation.normalP90, 0.0, 1.0e-12);
  EXPECT_EQ(evaluation.patchClass,
            directional::geometry::FlowRepPatchClass::FourSided);
}

TEST(FlowRepStrandsPhase15, InfeasibleCycleRejectsOddBoundaryAndForbiddenTurn) {
  auto odd = feasible_cycle();
  odd.sideCounts = {1, 2, 2, 2};
  const auto oddEvaluation =
      directional::geometry::evaluate_flow_rep_cycle(odd);
  EXPECT_FALSE(oddEvaluation.quadrangulable);

  auto forbidden = feasible_cycle();
  forbidden.forbiddenTurn = true;
  const auto forbiddenEvaluation =
      directional::geometry::evaluate_flow_rep_cycle(forbidden);
  EXPECT_FALSE(forbiddenEvaluation.quadrangulable);
}

TEST(FlowRepStrandsPhase15, MandatoryRailsAreRetainedDuringSelection) {
  std::vector<FlowRepArc> arcs = square_selection_arcs();
  arcs.push_back(mandatory_rail(4, -0.1));
  FlowRepArc hard = mandatory_rail(5, 1.1);
  hard.boundaryRail = false;
  hard.hardFeatureRail = true;
  arcs.push_back(hard);
  const auto samples = coverage_for_active_arcs(arcs);

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {square_cycle()});

  ASSERT_TRUE(network.selectionSucceeded);
  EXPECT_EQ(network.mandatoryRails, 2);
  EXPECT_EQ(network.retainedMandatoryRails, 2);
  EXPECT_NE(std::find(network.retainedArcIds.begin(),
                      network.retainedArcIds.end(), 4),
            network.retainedArcIds.end());
  EXPECT_NE(std::find(network.retainedArcIds.begin(),
                      network.retainedArcIds.end(), 5),
            network.retainedArcIds.end());
}

TEST(FlowRepStrandsPhase15, IncompleteCycleCoverageFailsClosed) {
  std::vector<FlowRepArc> arcs = square_selection_arcs();
  const auto samples = coverage_for_active_arcs(arcs);
  FlowRepCycleInput cycle = square_cycle();
  cycle.sideArcIds = {{0}, {1}, {2}};
  cycle.sideCounts = {1, 1, 1};
  cycle.boundaryArcIds = {0, 1, 2};

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {cycle});

  EXPECT_FALSE(network.selectionSucceeded);
  EXPECT_EQ(network.failureCode,
            FlowRepSelectionFailureCode::IncompleteCycleCoverage);
  EXPECT_EQ(network.retainedArcIds, (std::vector<int>{0, 1, 2, 3}));
}

TEST(FlowRepStrandsPhase15,
     OverlayExposesRawRetainedRemovedAndPatchChannels) {
  const std::vector<FlowRepArc> arcs = square_selection_arcs();
  const auto strands = directional::geometry::cluster_flow_rep_strands(arcs);
  const auto samples = coverage_for_active_arcs(arcs);
  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {square_cycle()});
  ASSERT_TRUE(network.selectionSucceeded);

  const auto overlay =
      directional::geometry::make_flow_rep_overlay(arcs, strands, network);

  EXPECT_EQ(overlay.rawArcStarts.rows(), 4);
  EXPECT_EQ(overlay.rawArcEnds.rows(), 4);
  EXPECT_EQ(overlay.strandColor.size(), 4);
  EXPECT_EQ(overlay.retained.size(), 4);
  EXPECT_EQ(overlay.removed.size(), 4);
  EXPECT_EQ(overlay.cycleEnergy.size(), 1);
  EXPECT_EQ(overlay.patchClass.size(), 1);
}

TEST(FlowRepStrandsPhase15, TenRunSparseNetworkHashIsIdentical) {
  const std::vector<FlowRepArc> arcs = square_selection_arcs();
  const auto samples = coverage_for_active_arcs(arcs);
  const auto first = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {square_cycle()});
  ASSERT_TRUE(first.selectionSucceeded);
  const std::uint64_t hash = sparse_hash(first);

  for (int run = 0; run < 9; ++run) {
    const auto repeated = directional::geometry::select_sparse_flow_rep_network(
        arcs, samples, {square_cycle()});
    EXPECT_EQ(sparse_hash(repeated), hash);
  }
}
