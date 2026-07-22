#include <directional/geometry/FlowRepStrands.h>

#include <algorithm>
#include <cstdint>
#include <vector>

#include <gtest/gtest.h>

namespace {

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

std::uint64_t sparse_hash(
    const directional::geometry::FlowRepSparseNetwork &network) {
  std::uint64_t hash = 1469598103934665603ULL;
  const auto mix = [&](const std::int64_t value) {
    hash ^= static_cast<std::uint64_t>(value);
    hash *= 1099511628211ULL;
  };
  for (const int id : network.retainedArcIds) {
    mix(id);
  }
  mix(-1);
  for (const int id : network.removedArcIds) {
    mix(id);
  }
  mix(network.mandatoryRails);
  mix(network.retainedMandatoryRails);
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

TEST(FlowRepStrandsPhase15, MandatoryRailsAreRetainedDuringReduction) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 0.0, 0.1, 1.0, 0.1),
      arc(2, 0.0, 0.2, 1.0, 0.2), arc(3, 0.0, 0.3, 1.0, 0.3),
      arc(4, 0.0, 0.4, 1.0, 0.4)};
  arcs[0].mandatoryRail = true;
  arcs[0].boundaryRail = true;
  arcs[4].mandatoryRail = true;
  arcs[4].hardFeatureRail = true;
  for (auto &a : arcs) {
    a.dominance = 0.1;
  }
  std::vector<Eigen::RowVector3d> samples;
  for (const auto &a : arcs) {
    samples.push_back(0.5 * (a.start + a.end));
  }
  directional::geometry::FlowRepSparseOptions options;
  options.maxCoverageWorsening = 0.11;

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {feasible_cycle()}, options);

  EXPECT_EQ(network.mandatoryRails, 2);
  EXPECT_EQ(network.retainedMandatoryRails, 2);
  EXPECT_NE(std::find(network.retainedArcIds.begin(),
                      network.retainedArcIds.end(), 0),
            network.retainedArcIds.end());
  EXPECT_NE(std::find(network.retainedArcIds.begin(),
                      network.retainedArcIds.end(), 4),
            network.retainedArcIds.end());
}

TEST(FlowRepStrandsPhase15, OversampledFixtureReducesByAtLeastTwentyFivePercent) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 0.0, 0.1, 1.0, 0.1),
      arc(2, 0.0, 0.2, 1.0, 0.2), arc(3, 0.0, 0.3, 1.0, 0.3),
      arc(4, 0.0, 0.4, 1.0, 0.4)};
  for (auto &a : arcs) {
    a.start.y() *= 0.1;
    a.end.y() *= 0.1;
  }
  arcs[0].mandatoryRail = true;
  arcs[4].mandatoryRail = true;
  for (auto &a : arcs) {
    a.dominance = 0.1;
  }
  std::vector<Eigen::RowVector3d> samples;
  for (const auto &a : arcs) {
    samples.push_back(0.5 * (a.start + a.end));
  }
  directional::geometry::FlowRepSparseOptions options;
  options.maxCoverageWorsening = 0.02;

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {feasible_cycle()}, options);

  EXPECT_LE(network.retainedArcIds.size(), 3U);
  EXPECT_GE(static_cast<double>(arcs.size() - network.retainedArcIds.size()) /
                static_cast<double>(arcs.size()),
            0.25);
  EXPECT_LE(network.sparseCoverageMax - network.denseCoverageMax, 0.02);
  for (const auto tag : network.endpointTags) {
    EXPECT_TRUE(tag == directional::geometry::FlowRepEndpointTag::Boundary ||
                tag == directional::geometry::FlowRepEndpointTag::Feature ||
                tag == directional::geometry::FlowRepEndpointTag::NetworkJunction ||
                tag == directional::geometry::FlowRepEndpointTag::NeedsCompletion);
  }
}

TEST(FlowRepStrandsPhase15, RejectedRemovalAndStrictSubstitutionAreTransactional) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 0.0, 1.0, 1.0, 1.0)};
  arcs[0].dominance = 2.0;
  arcs[0].alignmentCost = 2.0;
  arcs[0].substitutions.push_back(1);
  arcs[1].dominance = 0.1;
  arcs[1].alignmentCost = 0.1;
  std::vector<Eigen::RowVector3d> samples = {
      Eigen::RowVector3d(0.5, 1.0, 0.0)};
  directional::geometry::FlowRepSparseOptions options;
  options.maxCoverageWorsening = 0.05;

  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {feasible_cycle()}, options);

  EXPECT_EQ(network.retainedArcIds.size(), 1U);
  EXPECT_EQ(network.retainedArcIds.front(), 1);
  EXPECT_EQ(network.removedArcIds.front(), 0);
}

TEST(FlowRepStrandsPhase15, OverlayExposesRawRetainedRemovedAndPatchChannels) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 1.0, 0.0, 2.0, 0.0)};
  const auto strands = directional::geometry::cluster_flow_rep_strands(arcs);
  directional::geometry::FlowRepSparseOptions options;
  options.maxCoverageWorsening = 10.0;
  const auto network = directional::geometry::select_sparse_flow_rep_network(
      arcs, {}, {feasible_cycle()}, options);

  const auto overlay =
      directional::geometry::make_flow_rep_overlay(arcs, strands, network);

  EXPECT_EQ(overlay.rawArcStarts.rows(), 2);
  EXPECT_EQ(overlay.rawArcEnds.rows(), 2);
  EXPECT_EQ(overlay.strandColor.size(), 2);
  EXPECT_EQ(overlay.retained.size(), 2);
  EXPECT_EQ(overlay.removed.size(), 2);
  EXPECT_EQ(overlay.cycleEnergy.size(), 1);
  EXPECT_EQ(overlay.patchClass.size(), 1);
}

TEST(FlowRepStrandsPhase15, TenRunSparseNetworkHashIsIdentical) {
  std::vector<directional::geometry::FlowRepArc> arcs = {
      arc(0, 0.0, 0.0, 1.0, 0.0), arc(1, 0.0, 0.1, 1.0, 0.1),
      arc(2, 0.0, 0.2, 1.0, 0.2), arc(3, 0.0, 0.3, 1.0, 0.3),
      arc(4, 0.0, 0.4, 1.0, 0.4)};
  for (auto &a : arcs) {
    a.start.y() *= 0.1;
    a.end.y() *= 0.1;
  }
  arcs[0].mandatoryRail = true;
  arcs[4].mandatoryRail = true;
  std::vector<Eigen::RowVector3d> samples;
  for (const auto &a : arcs) {
    samples.push_back(0.5 * (a.start + a.end));
  }
  directional::geometry::FlowRepSparseOptions options;
  options.maxCoverageWorsening = 0.02;
  const auto first = directional::geometry::select_sparse_flow_rep_network(
      arcs, samples, {feasible_cycle()}, options);
  const std::uint64_t hash = sparse_hash(first);

  for (int run = 0; run < 9; ++run) {
    const auto repeated = directional::geometry::select_sparse_flow_rep_network(
        arcs, samples, {feasible_cycle()}, options);
    EXPECT_EQ(sparse_hash(repeated), hash);
  }
}
