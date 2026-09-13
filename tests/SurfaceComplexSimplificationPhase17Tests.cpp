#include <directional/geometry/SurfaceComplexSimplification.h>
#include <directional/geometry/SourceChartTransitions.h>
#include <directional/geometry/SurfaceCellTracing.h>

#include <algorithm>
#include <cmath>
#include <memory>
#include <vector>

#include <gtest/gtest.h>
#include "TestAuthorityIds.h"










namespace {

const directional::geometry::SourceTopologyRegions *
row_identity_source_authority(const Eigen::MatrixXi &faces,
                              const std::vector<int> &components,
                              const std::vector<int> &sheets) {
  directional::geometry::SurfaceCellTracingOptions tracing;
  tracing.sourceFaceComponents = components;
  tracing.sourceFaceSheets = sheets;
  auto authority = directional::geometry::surface_cell_tracing_detail::
      build_source_topology_regions(faces, tracing);
  if (!authority.has_value()) {
    throw std::runtime_error("Failed to construct typed row-identity source authority.");
  }
  static std::vector<std::unique_ptr<directional::geometry::SourceTopologyRegions>> arena;
  arena.push_back(std::make_unique<directional::geometry::SourceTopologyRegions>(
      std::move(*authority)));
  return arena.back().get();
}


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


struct ClosedToroidalCandidateFixture {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
  directional::geometry::SurfaceCellComplex complex;
};

ClosedToroidalCandidateFixture closed_toroidal_candidate_complex() {
  ClosedToroidalCandidateFixture fixture;
  constexpr int uCount = 4;
  constexpr int vCount = 4;
  constexpr double pi = 3.14159265358979323846;
  constexpr double majorRadius = 2.0;
  constexpr double minorRadius = 0.5;

  const auto node_id = [](const int u, const int v) {
    const int wrappedU = (u % uCount + uCount) % uCount;
    const int wrappedV = (v % vCount + vCount) % vCount;
    return wrappedU * vCount + wrappedV;
  };
  const auto cell_id = [](const int u, const int v) {
    const int wrappedU = (u % uCount + uCount) % uCount;
    const int wrappedV = (v % vCount + vCount) % vCount;
    return wrappedU * vCount + wrappedV;
  };

  fixture.vertices.resize(uCount * vCount, 3);
  for (int u = 0; u < uCount; ++u) {
    const double theta = 2.0 * pi * static_cast<double>(u) /
                         static_cast<double>(uCount);
    for (int v = 0; v < vCount; ++v) {
      const double phi = 2.0 * pi * static_cast<double>(v) /
                         static_cast<double>(vCount);
      const double ring = majorRadius + minorRadius * std::cos(phi);
      fixture.vertices.row(node_id(u, v)) = Eigen::RowVector3d(
          ring * std::cos(theta), ring * std::sin(theta),
          minorRadius * std::sin(phi));
    }
  }

  fixture.faces.resize(2 * uCount * vCount, 3);
  int face = 0;
  for (int u = 0; u < uCount; ++u) {
    for (int v = 0; v < vCount; ++v) {
      const int a = node_id(u, v);
      const int b = node_id(u + 1, v);
      const int c = node_id(u, v + 1);
      const int d = node_id(u + 1, v + 1);
      fixture.faces.row(face++) = Eigen::RowVector3i(a, b, c);
      fixture.faces.row(face++) = Eigen::RowVector3i(b, d, c);
    }
  }

  auto &complex = fixture.complex;
  complex.nodes.reserve(uCount * vCount);
  for (int u = 0; u < uCount; ++u) {
    for (int v = 0; v < vCount; ++v) {
      directional::geometry::SurfaceArrangementNode node;
      node.id = node_id(u, v);
      node.sourceFace = 2 * cell_id(u, v);
      node.barycentric = Eigen::RowVector3d(1.0, 0.0, 0.0);
      directional::geometry::SurfaceArrangementNodeOccurrence occurrence;
      occurrence.sourceFace = node.sourceFace;
      occurrence.barycentric = node.barycentric;
      occurrence.provenance = node.id;
      node.occurrences.push_back(occurrence);
      complex.nodes.push_back(std::move(node));
    }
  }

  const auto add_pair = [&](const int from, const int to,
                            const int forwardCell, const int reverseCell,
                            const int family, const int strand,
                            const int sourceFace) {
    const int first = static_cast<int>(complex.halfedges.size());
    directional::geometry::SurfaceArrangementHalfedge forward;
    directional::geometry::SurfaceArrangementHalfedge reverse;
    for (directional::geometry::SurfaceArrangementHalfedge *edge :
         {&forward, &reverse}) {
      edge->sourceFace = sourceFace;
      edge->family = family;
      edge->strand = strand;
      edge->sourceArc = first / 2;
      directional::geometry::SurfaceArrangementProvenance provenance;
      provenance.sourceArc = first / 2;
      provenance.provenance = first / 2;
      provenance.sourceFace = sourceFace;
      provenance.family = family;
      provenance.strand = strand;
      edge->provenance.push_back(provenance);
    }
    forward.id = first;
    forward.twin = first + 1;
    forward.from = from;
    forward.to = to;
    forward.cell = forwardCell;
    reverse.id = first + 1;
    reverse.twin = first;
    reverse.from = to;
    reverse.to = from;
    reverse.cell = reverseCell;
    reverse.sourceT0 = 1.0;
    reverse.sourceT1 = 0.0;
    reverse.provenance.front().sourceT0 = 1.0;
    reverse.provenance.front().sourceT1 = 0.0;
    complex.halfedges.push_back(std::move(forward));
    complex.halfedges.push_back(std::move(reverse));
    return first;
  };

  std::vector<int> horizontal(static_cast<std::size_t>(uCount * vCount), -1);
  std::vector<int> vertical(static_cast<std::size_t>(uCount * vCount), -1);
  for (int u = 0; u < uCount; ++u) {
    for (int v = 0; v < vCount; ++v) {
      const int index = cell_id(u, v);
      const int sourceFace = 2 * index;
      horizontal[static_cast<std::size_t>(index)] = add_pair(
          node_id(u, v), node_id(u + 1, v), cell_id(u, v),
          cell_id(u, v - 1), 0, v, sourceFace);
      vertical[static_cast<std::size_t>(index)] = add_pair(
          node_id(u, v), node_id(u, v + 1), cell_id(u - 1, v),
          cell_id(u, v), 1, u, sourceFace);
    }
  }

  complex.cells.reserve(uCount * vCount);
  for (int u = 0; u < uCount; ++u) {
    for (int v = 0; v < vCount; ++v) {
      const int id = cell_id(u, v);
      directional::geometry::SurfaceArrangementCell cell;
      cell.id = id;
      cell.sourceFace = 2 * id;
      cell.sourceFaces = {2 * id, 2 * id + 1};
      cell.halfedges = {
          horizontal[static_cast<std::size_t>(cell_id(u, v))],
          vertical[static_cast<std::size_t>(cell_id(u + 1, v))],
          horizontal[static_cast<std::size_t>(cell_id(u, v + 1))] + 1,
          vertical[static_cast<std::size_t>(cell_id(u, v))] + 1};
      cell.closed = true;
      cell.disk = true;
      cell.boundaryCycle = false;
      cell.boundaryComponentCount = 1;
      cell.eulerCharacteristic = 1;
      cell.signedArea = 1.0;
      cell.area = 1.0;
      for (int edgeIndex = 0;
           edgeIndex < static_cast<int>(cell.halfedges.size()); ++edgeIndex) {
        const int halfedge = cell.halfedges[static_cast<std::size_t>(edgeIndex)];
        complex.halfedges[static_cast<std::size_t>(halfedge)].next =
            cell.halfedges[static_cast<std::size_t>(
                (edgeIndex + 1) % static_cast<int>(cell.halfedges.size()))];
      }
      complex.cells.push_back(std::move(cell));
    }
  }

  complex.diagnostics.eulerCharacteristic = 0;
  complex.diagnostics.sourceEulerCharacteristic = 0;
  complex.diagnostics.connectedComponentCount = 1;
  complex.diagnostics.sourceConnectedComponentCount = 1;
  complex.diagnostics.boundaryLoopCount = 0;
  complex.diagnostics.sourceBoundaryLoopCount = 0;
  complex.diagnostics.incidenceValid = true;
  complex.diagnostics.embeddingValid = true;
  complex.diagnostics.orientationValid = true;
  complex.diagnostics.cellsDiskValid = true;
  complex.diagnostics.boundaryLoopsValid = true;
  complex.diagnostics.eulerCharacteristicValid = true;
  complex.diagnostics.topologyValid = true;
  return fixture;
}


} // namespace

TEST(SurfaceComplexSimplificationPhase17,
     CandidateExtractionBaselineForCanonicalSourceScopeIdentityIsNonVacuous) {
  const ClosedToroidalCandidateFixture baseline =
      closed_toroidal_candidate_complex();
  const auto candidates =
      directional::geometry::extract_surface_simplification_candidates(
          baseline.complex, baseline.vertices, baseline.faces);
  const auto found = std::find_if(
      candidates.candidates.begin(), candidates.candidates.end(),
      [](const auto &candidate) {
        return !candidate.touchesHardFeature && !candidate.touchesBoundary &&
               !candidate.touchesSingularity && !candidate.changesTopology &&
               candidate.sideFeasible;
      });
  ASSERT_NE(found, candidates.candidates.end());
}

TEST(SurfaceComplexSimplificationPhase17,
     CanonicalSourceScopeIdentityIsRowIndependentWithNonVacuousCandidateBaseline) {
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           0, 2, 3;
  const std::vector<int> components = {0, 0};
  const std::vector<int> sheets = {0, 1};
  const auto *firstAuthority =
      row_identity_source_authority(faces, components, sheets);
  const directional::geometry::SourceChartTransitionGraph firstGraph(
      faces, *firstAuthority, directional::geometry::empty_hard_feature_edges());
  ASSERT_TRUE(firstGraph.available());
  const auto firstChart = firstGraph.chart(0);
  const auto distinctChart = firstGraph.chart(1);
  ASSERT_TRUE(firstChart.has_value());
  ASSERT_TRUE(distinctChart.has_value());
  EXPECT_NE(firstChart.value(), distinctChart.value());

  const auto regionResult =
      directional::authority::TopologyRegionId::from_index(0, 2);
  ASSERT_TRUE(regionResult.has_value());
  const std::optional<directional::authority::TopologyRegionId> region(
      regionResult.value());
  const directional::geometry::surface_simplification_detail::SourceScope
      firstIdentity{
          region, firstChart};

  Eigen::MatrixXi reorderedFaces = faces;
  reorderedFaces.row(0).swap(reorderedFaces.row(1));
  const std::vector<int> reorderedComponents = {0, 0};
  const std::vector<int> reorderedSheets = {1, 0};
  const auto *reorderedAuthority = row_identity_source_authority(
      reorderedFaces, reorderedComponents, reorderedSheets);
  const directional::geometry::SourceChartTransitionGraph reorderedGraph(
      reorderedFaces, *reorderedAuthority,
      directional::geometry::empty_hard_feature_edges());
  ASSERT_TRUE(reorderedGraph.available());
  const auto reorderedChart = reorderedGraph.chart(1);
  ASSERT_TRUE(reorderedChart.has_value());
  EXPECT_EQ(firstChart.value(), reorderedChart.value());

  const directional::geometry::surface_simplification_detail::SourceScope
      reorderedIdentity{
          region, reorderedChart};
  EXPECT_EQ(firstIdentity, reorderedIdentity);

  const directional::geometry::surface_simplification_detail::SourceScope
      distinctIdentity{
          region, distinctChart};
  EXPECT_NE(firstIdentity, distinctIdentity);
}

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
      halfedge.railId = directional::tests::test_hard_rail_id(77);
      auto &twin = complex.halfedges[static_cast<std::size_t>(halfedge.twin)];
      twin.hardFeature = true;
      twin.railId = directional::tests::test_hard_rail_id(77);
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
                            return halfedge.hardFeature && halfedge.railId == directional::tests::test_hard_rail_id(77);
                          }));
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
}

TEST(SurfaceComplexSimplificationPhase17,
     OptionalLayoutBridgeHealsPinchedCellTransactionally) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  auto dangling = arc(300, {0.5, 0.5, 0.0}, {0.4, 0.3, 0.3}, 0);
  dangling.layoutSupport = true;
  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, {dangling});
  const int beforeDefect = directional::geometry::
      surface_simplification_detail::non_disk_topology_defect(complex);
  ASSERT_GT(beforeDefect, 0);
  ASSERT_FALSE(complex.diagnostics.topologyValid);

  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(
          complex, vertices, faces);
  const auto healing = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &candidate) {
        return candidate.topologyHealing && !candidate.touchesHardFeature &&
               !candidate.touchesBoundary && !candidate.touchesSingularity;
      });
  ASSERT_NE(healing, extracted.candidates.end());
  EXPECT_FALSE(healing->affectedPatchDisk);

  auto options = permissive_options();
  options.topologyHealingOnly = true;
  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, vertices, faces, extracted.candidates, options);

  EXPECT_EQ(result.committed, 1);
  EXPECT_EQ(result.rejected, 0);
  ASSERT_EQ(result.transactions.size(), 1U);
  const auto &transaction = result.transactions.front();
  EXPECT_TRUE(transaction.topologyHealing);
  EXPECT_TRUE(transaction.committed);
  EXPECT_TRUE(transaction.trialBuilt);
  EXPECT_GT(transaction.beforeNonDiskDefect,
            transaction.afterNonDiskDefect);
  EXPECT_TRUE(transaction.incidenceValid);
  EXPECT_TRUE(transaction.embeddingValid);
  EXPECT_TRUE(transaction.orientationValid);
  EXPECT_TRUE(transaction.boundaryLoopsValid);
  EXPECT_TRUE(transaction.eulerCharacteristicValid);
  EXPECT_TRUE(transaction.noUnsplitCrossings);
  EXPECT_TRUE(transaction.noGeometricTJunctions);
  EXPECT_TRUE(transaction.protectedSupportPreserved);
  EXPECT_LT(result.complex.halfedges.size(), complex.halfedges.size());
  EXPECT_EQ(directional::geometry::surface_simplification_detail::
                non_disk_topology_defect(result.complex),
            0);
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
  EXPECT_EQ(result.complex.diagnostics.eulerCharacteristic,
            result.complex.diagnostics.sourceEulerCharacteristic);
  EXPECT_EQ(result.complex.diagnostics.boundaryLoopCount,
            result.complex.diagnostics.sourceBoundaryLoopCount);
}

TEST(SurfaceComplexSimplificationPhase17,
     MultipleOptionalBridgeExcursionsHealAtomicallyAcrossFamilies) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  auto firstLeaf = arc(310, {0.80, 0.20, 0.0}, {0.65, 0.20, 0.15}, 0);
  firstLeaf.strand = 900;
  firstLeaf.layoutSupport = true;
  auto secondLeaf = arc(311, {0.80, 0.0, 0.20}, {0.65, 0.15, 0.20}, 1);
  secondLeaf.strand = 901;
  secondLeaf.layoutSupport = true;

  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, {firstLeaf, secondLeaf});
  const int beforeDefect = directional::geometry::
      surface_simplification_detail::non_disk_topology_defect(complex);
  ASSERT_GT(beforeDefect, 0);

  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(
          complex, vertices, faces);
  const auto aggregate = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &candidate) {
        return candidate.topologyHealing && candidate.elementIds.size() == 2U &&
               candidate.affectedCellIds.size() == 1U &&
               !candidate.touchesHardFeature &&
               !candidate.touchesBoundary &&
               !candidate.touchesSingularity &&
               !candidate.touchesLocalSheetBoundary;
      });
  ASSERT_NE(aggregate, extracted.candidates.end());

  auto options = permissive_options();
  options.topologyHealingOnly = true;
  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, vertices, faces, extracted.candidates, options);

  EXPECT_EQ(result.committed, 1);
  EXPECT_TRUE(std::any_of(
      result.transactions.begin(), result.transactions.end(),
      [beforeDefect](const auto &transaction) {
        return transaction.committed && transaction.elementIds.size() == 2U &&
               transaction.beforeNonDiskDefect == beforeDefect &&
               transaction.afterNonDiskDefect == 0;
      }));
  EXPECT_EQ(directional::geometry::surface_simplification_detail::
                non_disk_topology_defect(result.complex),
            0);
  EXPECT_TRUE(result.complex.diagnostics.topologyValid);
  EXPECT_EQ(result.complex.diagnostics.eulerCharacteristic,
            result.complex.diagnostics.sourceEulerCharacteristic);
  EXPECT_EQ(result.complex.diagnostics.connectedComponentCount,
            result.complex.diagnostics.sourceConnectedComponentCount);
  EXPECT_EQ(result.complex.diagnostics.boundaryLoopCount,
            result.complex.diagnostics.sourceBoundaryLoopCount);
}

TEST(SurfaceComplexSimplificationPhase17,
     OptionalCellHealingCommitsWhileUnrelatedRequiredDefectRemains) {
  Eigen::MatrixXd vertices(6, 3);
  vertices << 0.0, 0.0, 0.0,
              1.0, 0.0, 0.0,
              0.0, 1.0, 0.0,
              3.0, 0.0, 0.0,
              4.0, 0.0, 0.0,
              3.0, 1.0, 0.0;
  Eigen::MatrixXi faces(2, 3);
  faces << 0, 1, 2,
           3, 4, 5;

  auto firstOptional =
      arc(320, {0.80, 0.20, 0.0}, {0.65, 0.20, 0.15}, 0);
  firstOptional.strand = 910;
  firstOptional.layoutSupport = true;
  auto secondOptional =
      arc(321, {0.80, 0.0, 0.20}, {0.65, 0.15, 0.20}, 1);
  secondOptional.strand = 911;
  secondOptional.layoutSupport = true;
  auto required = arc(322, {0.75, 0.25, 0.0}, {0.40, 0.30, 0.30}, 0);
  required.sourceFace = 1;
  required.strand = 912;
  required.layoutSupport = true;
  required.singularitySupport = true;

  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, {firstOptional, secondOptional, required});
  const int beforeDefect = directional::geometry::
      surface_simplification_detail::non_disk_topology_defect(complex);
  ASSERT_GT(beforeDefect, 1);

  const auto beforeProtected = directional::geometry::
      surface_simplification_detail::protected_support(complex);
  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(
          complex, vertices, faces);
  const auto aggregate = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &candidate) {
        return candidate.topologyHealing && candidate.elementIds.size() == 2U &&
               !candidate.touchesSingularity;
      });
  ASSERT_NE(aggregate, extracted.candidates.end());

  auto options = permissive_options();
  options.topologyHealingOnly = true;
  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, vertices, faces, extracted.candidates, options);

  EXPECT_EQ(result.committed, 1);
  const auto committed = std::find_if(
      result.transactions.begin(), result.transactions.end(),
      [](const auto &transaction) { return transaction.committed; });
  ASSERT_NE(committed, result.transactions.end());
  EXPECT_TRUE(committed->topologyMismatchNotWorse);
  EXPECT_TRUE(committed->protectedSupportPreserved);
  EXPECT_GT(committed->afterNonDiskDefect, 0);
  EXPECT_LT(committed->afterNonDiskDefect,
            committed->beforeNonDiskDefect);
  EXPECT_FALSE(result.complex.diagnostics.topologyValid);
  EXPECT_EQ(directional::geometry::surface_simplification_detail::
                protected_support(result.complex),
            beforeProtected);
  EXPECT_TRUE(std::any_of(
      result.complex.halfedges.begin(), result.complex.halfedges.end(),
      [](const auto &halfedge) { return halfedge.singularitySupport; }));
}

TEST(SurfaceComplexSimplificationPhase17,
     RequiredSingularityBridgeIsProtectedAndRollsBackExactly) {
  Eigen::MatrixXd vertices(3, 3);
  vertices << 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0;
  Eigen::MatrixXi faces(1, 3);
  faces << 0, 1, 2;

  auto separatrix = arc(301, {0.5, 0.5, 0.0}, {0.4, 0.3, 0.3}, 0);
  separatrix.layoutSupport = true;
  separatrix.singularitySupport = true;
  const auto complex = directional::geometry::build_surface_cell_complex(
      vertices, faces, {separatrix});
  const auto before = directional::geometry::surface_simplification_detail::
      complex_structural_hash(complex);

  const auto extracted =
      directional::geometry::extract_surface_simplification_candidates(
          complex, vertices, faces);
  const auto healing = std::find_if(
      extracted.candidates.begin(), extracted.candidates.end(),
      [](const auto &candidate) {
        return candidate.topologyHealing && candidate.touchesSingularity;
      });
  ASSERT_NE(healing, extracted.candidates.end());

  auto options = permissive_options();
  options.topologyHealingOnly = true;
  const auto result = directional::geometry::simplify_surface_cell_complex(
      complex, vertices, faces, extracted.candidates, options);

  ASSERT_EQ(result.transactions.size(), 1U);
  EXPECT_FALSE(result.transactions.front().committed);
  EXPECT_EQ(result.transactions.front().rejection,
            directional::geometry::SurfaceSimplificationRejectionReason::
                ProtectedSingularity);
  EXPECT_EQ(result.transactions.front().beforeHash, before);
  EXPECT_EQ(result.transactions.front().afterHash, before);
  EXPECT_EQ(result.finalHash, before);
}
