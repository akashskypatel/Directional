#include <directional/geometry/FlowRepStrands.h>

#include <algorithm>
#include <cstdint>
#include <set>
#include <vector>

#include <gtest/gtest.h>

namespace {

using directional::geometry::FlowRepArc;
using directional::geometry::FlowRepCoverageSample;
using directional::geometry::FlowRepCycleInput;
using directional::geometry::FlowRepSelectionFailureCode;
using directional::geometry::FlowRepSparseNetwork;
using directional::geometry::FlowRepSparseOptions;

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
  a.sourceComponent = 3;
  a.sourceSheet = 5;
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
  value.sourceComponent = 3;
  value.sourceSheet = 5;
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
  sample.sourceComponent = sourceArc.sourceComponent;
  sample.sourceSheet = sourceArc.sourceSheet;
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
  value.sourceComponent = 3;
  value.sourceSheet = sourceSheet;
  value.mandatoryRail = true;
  value.boundaryRail = true;
  value.strandProvenance = id;
  value.featureProvenance = id;
  value.railId = id;
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

} // namespace

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
  network.sourceFaceComponents = {3};
  network.sourceFaceSheets = {5};

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

  const auto arcs =
      directional::geometry::build_flow_rep_arcs_from_network(vertices, faces,
                                                              network);

  ASSERT_EQ(arcs.size(), 1U);
  EXPECT_EQ(arcs[0].sourceFace, 0);
  EXPECT_EQ(arcs[0].family, 1);
  EXPECT_FALSE(arcs[0].mandatoryRail);
  EXPECT_FALSE(arcs[0].hardFeatureRail);
  EXPECT_EQ(arcs[0].sourceComponent, 3);
  EXPECT_EQ(arcs[0].sourceSheet, 5);
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
  network.sourceFaceComponents = {3};
  network.sourceFaceSheets = {5};

  const Eigen::RowVector3d edge01Mid(0.5, 0.5, 0.0);
  const Eigen::RowVector3d edge12Mid(0.0, 0.5, 0.5);
  const auto make_rail = [&](const int id, const int curve,
                             const Eigen::RowVector3d &start,
                             const Eigen::RowVector3d &end) {
    directional::geometry::SurfaceCellRail rail;
    rail.id = id;
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
  network.sourceFaceComponents = {3};
  network.sourceFaceSheets = {5};
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
    EXPECT_EQ(sample.sourceComponent, 3);
    EXPECT_EQ(sample.sourceSheet, 5);
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
  network.sourceFaceComponents = {3};
  network.sourceFaceSheets = {5};
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
      segment.railId = 8;
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
  arcs[2].sourceSheet = -1;
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
  arcs[1].sourceComponent = arcs[0].sourceComponent;
  arcs[1].sourceSheet = arcs[0].sourceSheet;
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
