#include <directional/geometry/SurfaceComplexSimplification.h>

#include <algorithm>
#include <cmath>
#include <vector>

#include <gtest/gtest.h>

namespace {

std::vector<directional::geometry::SurfaceSimplificationElement>
make_elements(const int count) {
  std::vector<directional::geometry::SurfaceSimplificationElement> elements;
  for (int i = 0; i < count; ++i) {
    directional::geometry::SurfaceSimplificationElement element;
    element.id = i;
    element.cellOrHalfedge = i;
    element.length = 1.0;
    elements.push_back(element);
  }
  return elements;
}

directional::geometry::SurfaceSimplificationOptions permissive_options() {
  directional::geometry::SurfaceSimplificationOptions options;
  options.objectiveTolerance = 0.0;
  options.maxDescriptivenessWorsening = 0.05;
  return options;
}

} // namespace

TEST(SurfaceComplexSimplificationPhase17, OpenStripRemovalCommitsCoherently) {
  auto elements = make_elements(6);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          10, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {1, 2}, -1.0)};

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  EXPECT_EQ(result.committed, 1);
  EXPECT_EQ(result.finalActiveElements, 4);
  EXPECT_FALSE(result.elements[1].active);
  EXPECT_FALSE(result.elements[2].active);
}

TEST(SurfaceComplexSimplificationPhase17, ClosedLoopRemovalCommitsAsOneObject) {
  auto elements = make_elements(8);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          11, directional::geometry::SurfaceSimplificationCandidateType::ClosedLoop,
          {2, 3, 4, 5}, -2.0)};

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  EXPECT_EQ(result.committed, 1);
  EXPECT_EQ(result.finalActiveElements, 4);
}

TEST(SurfaceComplexSimplificationPhase17, StripEndingAtFeatureIsRejected) {
  auto elements = make_elements(4);
  elements[2].hardFeature = true;
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          12, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {1, 2}, -1.0)};

  const auto before =
      directional::geometry::surface_simplification_detail::structural_hash(
          elements);
  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  ASSERT_EQ(result.transactions.size(), 1U);
  EXPECT_FALSE(result.transactions.front().committed);
  EXPECT_EQ(result.transactions.front().rejection,
            directional::geometry::SurfaceSimplificationRejectionReason::
                ProtectedFeature);
  EXPECT_EQ(result.transactions.front().beforeHash, before);
  EXPECT_EQ(result.transactions.front().afterHash, before);
}

TEST(SurfaceComplexSimplificationPhase17, StripAroundHandleIsRejected) {
  auto elements = make_elements(4);
  elements[1].handleCritical = true;
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          13, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {1}, -1.0)};

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  ASSERT_EQ(result.transactions.size(), 1U);
  EXPECT_EQ(result.transactions.front().rejection,
            directional::geometry::SurfaceSimplificationRejectionReason::
                TopologyChanged);
}

TEST(SurfaceComplexSimplificationPhase17, CandidateInvalidationRecordsOverlap) {
  auto elements = make_elements(5);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          14, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {1, 2}, -2.0),
      directional::geometry::make_removal_candidate(
          15, directional::geometry::SurfaceSimplificationCandidateType::ClosedLoop,
          {2, 3}, -1.0)};

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  EXPECT_EQ(result.committed, 1);
  EXPECT_GE(result.invalidatedCandidates, 1);
  EXPECT_GE(result.recomputedCandidates, 1);
  ASSERT_EQ(result.transactions.size(), 2U);
  EXPECT_EQ(result.transactions.back().rejection,
            directional::geometry::SurfaceSimplificationRejectionReason::
                StaleCandidate);
}

TEST(SurfaceComplexSimplificationPhase17, TargetSizeStopsQueue) {
  auto elements = make_elements(6);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          16, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {0}, -3.0),
      directional::geometry::make_removal_candidate(
          17, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {1}, -2.0),
      directional::geometry::make_removal_candidate(
          18, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {2}, -1.0)};
  auto options = permissive_options();
  options.targetActiveElements = 4;

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, options);

  EXPECT_EQ(result.committed, 2);
  EXPECT_EQ(result.finalActiveElements, 4);
}

TEST(SurfaceComplexSimplificationPhase17, RollbackPreservesHashOnObjectiveFailure) {
  auto elements = make_elements(3);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          19,
          directional::geometry::SurfaceSimplificationCandidateType::
              ParallelCurveMerge,
          {0}, 1.0)};
  const auto before =
      directional::geometry::surface_simplification_detail::structural_hash(
          elements);

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  ASSERT_EQ(result.transactions.size(), 1U);
  EXPECT_FALSE(result.transactions.front().committed);
  EXPECT_EQ(result.transactions.front().rejection,
            directional::geometry::SurfaceSimplificationRejectionReason::
                ObjectiveWorsened);
  EXPECT_EQ(result.finalHash, before);
}

TEST(SurfaceComplexSimplificationPhase17, ObjectiveTieBreaksByTypeThenStableId) {
  auto elements = make_elements(4);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          22, directional::geometry::SurfaceSimplificationCandidateType::ClosedLoop,
          {2}, -1.0),
      directional::geometry::make_removal_candidate(
          21,
          directional::geometry::SurfaceSimplificationCandidateType::RedundantStrand,
          {1}, -1.0)};

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  ASSERT_FALSE(result.transactions.empty());
  EXPECT_EQ(result.transactions.front().candidateId, 21);
}

TEST(SurfaceComplexSimplificationPhase17, PoleSingularityProtectionRejectsRemoval) {
  auto elements = make_elements(3);
  elements[1].singularityProtected = true;
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          23,
          directional::geometry::SurfaceSimplificationCandidateType::
              ReliefArtifact,
          {1}, -1.0)};

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  ASSERT_EQ(result.transactions.size(), 1U);
  EXPECT_EQ(result.transactions.front().rejection,
            directional::geometry::SurfaceSimplificationRejectionReason::
                ProtectedSingularity);
}

TEST(SurfaceComplexSimplificationPhase17, RootLabelProtectionRejectsRemoval) {
  auto elements = make_elements(3);
  elements[1].rootLabelProtected = true;
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          24,
          directional::geometry::SurfaceSimplificationCandidateType::
              ReliefArtifact,
          {1}, -1.0)};

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  ASSERT_EQ(result.transactions.size(), 1U);
  EXPECT_EQ(result.transactions.front().rejection,
            directional::geometry::SurfaceSimplificationRejectionReason::
                ProtectedRoot);
}

TEST(SurfaceComplexSimplificationPhase17, ReductionGateAndDescriptivenessBound) {
  auto elements = make_elements(10);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates;
  for (int i = 0; i < 3; ++i) {
    auto candidate = directional::geometry::make_removal_candidate(
        30 + i, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
        {i}, -1.0);
    candidate.descriptivenessWorsening = 0.04;
    candidates.push_back(candidate);
  }

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());

  EXPECT_LE(result.finalActiveElements, 8);
  EXPECT_GE(static_cast<double>(result.initialActiveElements -
                                result.finalActiveElements) /
                static_cast<double>(result.initialActiveElements),
            0.20);
  for (const auto &transaction : result.transactions) {
    if (transaction.committed) {
      EXPECT_LE(transaction.objectiveCost, 0.0);
    }
  }
}

TEST(SurfaceComplexSimplificationPhase17, OverlayExposesBeforeAfterTransactions) {
  auto elements = make_elements(3);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          40, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {1}, -1.0)};

  const auto result = directional::geometry::simplify_surface_complex(
      elements, candidates, permissive_options());
  const auto overlay =
      directional::geometry::make_surface_simplification_overlay(result);

  EXPECT_EQ(overlay.candidateType.size(),
            static_cast<int>(result.transactions.size()));
  EXPECT_EQ(overlay.rejectionReason.size(),
            static_cast<int>(result.transactions.size()));
  EXPECT_EQ(overlay.objectiveCost.size(),
            static_cast<int>(result.transactions.size()));
  EXPECT_EQ(overlay.retained.size(), static_cast<int>(result.elements.size()));
  EXPECT_EQ(overlay.removed.size(), static_cast<int>(result.elements.size()));
}

TEST(SurfaceComplexSimplificationPhase17, BuildsElementsFromPhase16Complex) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  directional::geometry::SurfaceArrangementArc arc;
  arc.id = 0;
  arc.sourceFace = 0;
  arc.startBarycentric << 0.5, 0.5, 0.0;
  arc.endBarycentric << 0.5, 0.0, 0.5;
  arc.family = 0;

  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, {arc});
  auto elements =
      directional::geometry::make_simplification_elements_from_complex(complex);

  ASSERT_FALSE(elements.empty());
  EXPECT_TRUE(std::any_of(elements.begin(), elements.end(),
                          [](const auto &element) { return element.boundary; }));
  EXPECT_TRUE(std::any_of(elements.begin(), elements.end(),
                          [](const auto &element) {
                            return !element.boundary && !element.hardFeature;
                          }));
}

TEST(SurfaceComplexSimplificationPhase17, EmpiricalWorkScalesNLogNOnSyntheticGrids) {
  double previousRatio = 0.0;
  for (const int n : {16, 32, 64}) {
    auto elements = make_elements(n);
    std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates;
    for (int i = 0; i < n; ++i) {
      candidates.push_back(directional::geometry::make_removal_candidate(
          i, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {i}, -1.0));
    }
    const auto result = directional::geometry::simplify_surface_complex(
        elements, candidates, permissive_options());
    const double ratio =
        result.empiricalWork / (static_cast<double>(n) * std::log2(n));
    if (previousRatio > 0.0) {
      EXPECT_LE(ratio, previousRatio * 1.25);
    }
    previousRatio = ratio;
  }
}
