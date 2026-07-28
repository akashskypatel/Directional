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

directional::geometry::SurfaceArrangementArc arc(
    const int id, const Eigen::RowVector3d &a, const Eigen::RowVector3d &b,
    const int family = 0) {
  directional::geometry::SurfaceArrangementArc result;
  result.id = id;
  result.sourceFace = 0;
  result.startBarycentric = a;
  result.endBarycentric = b;
  result.family = family;
  result.strand = id;
  return result;
}

directional::geometry::SurfaceCellComplex two_strand_complex() {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  return directional::geometry::build_surface_cell_complex(
      vertices, faces,
      {arc(0, {0.5, 0.5, 0.0}, {0.25, 0.25, 0.5}),
       arc(1, {0.25, 0.25, 0.5}, {0.5, 0.0, 0.5})});
}

int first_removable_halfedge(
    const directional::geometry::SurfaceCellComplex &complex) {
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.id < halfedge.twin && halfedge.family >= 0 &&
        !halfedge.hardFeature) {
      return halfedge.id;
    }
  }
  return -1;
}

std::vector<int> complete_interface_for_halfedge(
    const directional::geometry::SurfaceCellComplex &complex,
    const int halfedgeId) {
  if (halfedgeId < 0 ||
      halfedgeId >= static_cast<int>(complex.halfedges.size())) {
    return {};
  }
  const auto &selected = complex.halfedges[static_cast<std::size_t>(halfedgeId)];
  if (selected.twin < 0 ||
      selected.twin >= static_cast<int>(complex.halfedges.size())) {
    return {};
  }
  const int cellA = selected.cell;
  const int cellB =
      complex.halfedges[static_cast<std::size_t>(selected.twin)].cell;
  std::vector<int> result;
  for (const auto &halfedge : complex.halfedges) {
    if (halfedge.id > halfedge.twin || halfedge.family < 0 ||
        halfedge.hardFeature) {
      continue;
    }
    const int twinCell =
        complex.halfedges[static_cast<std::size_t>(halfedge.twin)].cell;
    if ((halfedge.cell == cellA && twinCell == cellB) ||
        (halfedge.cell == cellB && twinCell == cellA)) {
      result.push_back(halfedge.id);
    }
  }
  std::sort(result.begin(), result.end());
  return result;
}

struct OversampledFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  directional::geometry::SurfaceCellComplex complex;
};

OversampledFixture oversampled_parallel_complex() {
  OversampledFixture fixture;
  fixture.vertices.resize(3, 3);
  fixture.vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  fixture.faces.resize(1, 3);
  fixture.faces << 0, 1, 2;
  std::vector<directional::geometry::SurfaceArrangementArc> arcs;
  int id = 0;
  for (const double t : {0.25, 0.40, 0.55, 0.70}) {
    auto value = arc(id++, {1.0 - t, t, 0.0}, {1.0 - t, 0.0, t}, 0);
    value.strand = id;
    arcs.push_back(value);
  }
  fixture.complex = directional::geometry::build_surface_cell_complex(
      fixture.vertices, fixture.faces, arcs);
  return fixture;
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

TEST(SurfaceComplexSimplificationPhase17,
     SimplifySurfaceCellComplexReturnsMutatedComplex) {
  const auto complex = two_strand_complex();
  const int removable = first_removable_halfedge(complex);
  ASSERT_GE(removable, 0);
  const std::vector<int> interface =
      complete_interface_for_halfedge(complex, removable);
  ASSERT_FALSE(interface.empty());
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          100,
          directional::geometry::SurfaceSimplificationCandidateType::RedundantStrand,
          interface, -1.0)};

  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, candidates, permissive_options());

  EXPECT_TRUE(result.hasComplexOutput);
  EXPECT_GE(result.committed, 1);
  EXPECT_LT(result.complex.halfedges.size(), complex.halfedges.size());
  EXPECT_LE(result.complex.nodes.size(), complex.nodes.size());
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
  EXPECT_EQ(result.complex.diagnostics.eulerCharacteristic,
            complex.diagnostics.eulerCharacteristic);
  EXPECT_GT(result.incidenceRebuilds, 0);
  EXPECT_GT(result.validationPasses, 0);
  EXPECT_NE(result.finalHash,
            directional::geometry::surface_simplification_detail::
                complex_structural_hash(complex));
}

TEST(SurfaceComplexSimplificationPhase17,
     ComplexRollbackPreservesHashOnRejectedTrial) {
  const auto complex = two_strand_complex();
  const int removable = first_removable_halfedge(complex);
  ASSERT_GE(removable, 0);
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          101, directional::geometry::SurfaceSimplificationCandidateType::OpenStrip,
          {removable}, 1.0)};
  const auto before =
      directional::geometry::surface_simplification_detail::complex_structural_hash(
          complex);

  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, candidates, permissive_options());

  ASSERT_EQ(result.transactions.size(), 1U);
  EXPECT_FALSE(result.transactions.front().committed);
  EXPECT_EQ(result.transactions.front().beforeHash, before);
  EXPECT_EQ(result.transactions.front().afterHash, before);
  EXPECT_EQ(result.finalHash, before);
}

TEST(SurfaceComplexSimplificationPhase17,
     ComplexCandidateRecomputationCreatesRealQueuedCandidates) {
  const auto fixture = oversampled_parallel_complex();
  auto extracted = directional::geometry::extract_surface_simplification_candidates(
      fixture.complex, fixture.vertices, fixture.faces);
  const auto found = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &candidate) {
        return !candidate.touchesHardFeature && !candidate.touchesBoundary &&
               !candidate.touchesSingularity && !candidate.changesTopology &&
               candidate.sideFeasible;
      });
  ASSERT_NE(found, extracted.candidates.end());

  const auto result = directional::geometry::simplify_surface_cell_complex(
      fixture.complex, fixture.vertices, fixture.faces, {*found},
      permissive_options());

  EXPECT_GT(result.committed, 0);
  EXPECT_GT(result.recomputedCandidates, 0);
  EXPECT_GT(result.transactions.size(), 1U);
}

TEST(SurfaceComplexSimplificationPhase17,
     CandidateExtractionIsDeterministicAndCarriesAuthoritativeSupport) {
  const auto complex = two_strand_complex();
  const auto first =
      directional::geometry::extract_surface_simplification_candidates(complex);
  const auto second =
      directional::geometry::extract_surface_simplification_candidates(complex);

  ASSERT_FALSE(first.candidates.empty());
  ASSERT_EQ(first.candidates.size(), second.candidates.size());
  EXPECT_EQ(first.structuralHash, second.structuralHash);
  for (std::size_t i = 0; i < first.candidates.size(); ++i) {
    const auto &candidate = first.candidates[i];
    EXPECT_EQ(candidate.stableId, static_cast<int>(i));
    EXPECT_FALSE(candidate.elementIds.empty());
    EXPECT_FALSE(candidate.affectedNodeIds.empty());
    EXPECT_FALSE(candidate.affectedStrandIds.empty());
    EXPECT_GT(candidate.removedLength, 0.0);
    EXPECT_TRUE(std::isfinite(candidate.deltaSurface));
    EXPECT_TRUE(std::isfinite(candidate.deltaSize));
    EXPECT_TRUE(std::isfinite(candidate.deltaQuad));
    EXPECT_TRUE(std::is_sorted(candidate.elementIds.begin(),
                               candidate.elementIds.end()));
  }
}

TEST(SurfaceComplexSimplificationPhase17,
     OversampledArrangementGeneratesRealNonemptyCandidateSet) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  std::vector<directional::geometry::SurfaceArrangementArc> arcs;
  int id = 0;
  for (const double t : {0.20, 0.30, 0.40, 0.50, 0.60, 0.70}) {
    auto value = arc(id++, {1.0 - t, t, 0.0},
                     {1.0 - t, 0.0, t}, 0);
    value.strand = id;
    arcs.push_back(value);
  }
  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, arcs);
  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(complex);

  EXPECT_GT(extracted.candidates.size(), 0U);
  EXPECT_GT(extracted.openStripCandidates + extracted.closedLoopCandidates +
                extracted.redundantStrandCandidates,
            0);
  EXPECT_TRUE(std::any_of(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &candidate) {
        return !candidate.elementIds.empty() &&
               candidate.type == directional::geometry::
                                     SurfaceSimplificationCandidateType::OpenStrip;
      }));
}

TEST(SurfaceComplexSimplificationPhase17,
     CandidateExtractionMarksProtectedSupportInsteadOfSilentlyDroppingIt) {
  auto complex = two_strand_complex();
  const int removable = first_removable_halfedge(complex);
  ASSERT_GE(removable, 0);
  complex.halfedges[static_cast<std::size_t>(removable)].hardFeature = true;
  const int twin = complex.halfedges[static_cast<std::size_t>(removable)].twin;
  complex.halfedges[static_cast<std::size_t>(twin)].hardFeature = true;

  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(complex);
  EXPECT_GT(extracted.protectedCandidates, 0);
  EXPECT_TRUE(std::any_of(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &candidate) {
        return candidate.touchesHardFeature &&
               candidate.featurePenalty > 0.0;
      }));
}


TEST(SurfaceComplexSimplificationPhase17,
     TransactionalMutationCommitsExtractedOversampledCandidate) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;
  std::vector<directional::geometry::SurfaceArrangementArc> arcs;
  int id = 0;
  for (const double t : {0.25, 0.40, 0.55, 0.70}) {
    auto value = arc(id++, {1.0 - t, t, 0.0}, {1.0 - t, 0.0, t}, 0);
    value.strand = id;
    arcs.push_back(value);
  }
  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, arcs);
  auto extracted = directional::geometry::extract_surface_simplification_candidates(complex);
  ASSERT_FALSE(extracted.candidates.empty());

  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, extracted.candidates, permissive_options());

  EXPECT_GT(result.committed, 0);
  EXPECT_LT(result.finalActiveElements, result.initialActiveElements);
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
  EXPECT_EQ(result.complex.diagnostics.eulerCharacteristic,
            complex.diagnostics.eulerCharacteristic);
  EXPECT_GT(result.recomputedCandidates, 0);
  EXPECT_TRUE(std::all_of(result.transactions.begin(), result.transactions.end(),
                          [](const auto &transaction) {
                            return transaction.committed ||
                                   transaction.beforeHash == transaction.afterHash;
                          }));
}

TEST(SurfaceComplexSimplificationPhase17,
     TransactionalMutationPreservesHardRailSupport) {
  auto complex = two_strand_complex();
  int protectedHalfedge = -1;
  for (auto &halfedge : complex.halfedges) {
    if (halfedge.id < halfedge.twin && halfedge.family < 0) {
      protectedHalfedge = halfedge.id;
      halfedge.hardFeature = true;
      halfedge.railId = 77;
      auto &twin = complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
      twin.hardFeature = true;
      twin.railId = 77;
      break;
    }
  }
  ASSERT_GE(protectedHalfedge, 0);
  const int removable = first_removable_halfedge(complex);
  ASSERT_GE(removable, 0);
  const std::vector<int> interface =
      complete_interface_for_halfedge(complex, removable);
  ASSERT_FALSE(interface.empty());
  std::vector<directional::geometry::SurfaceSimplificationCandidate> candidates = {
      directional::geometry::make_removal_candidate(
          210, directional::geometry::SurfaceSimplificationCandidateType::RedundantStrand,
          interface, -1.0)};

  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, candidates, permissive_options());

  ASSERT_GT(result.committed, 0);
  EXPECT_TRUE(std::any_of(result.complex.halfedges.begin(), result.complex.halfedges.end(),
                          [](const auto &halfedge) {
                            return halfedge.hardFeature && halfedge.railId == 77;
                          }));
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
}
