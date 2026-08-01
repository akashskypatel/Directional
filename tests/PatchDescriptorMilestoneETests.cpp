#include <directional/geometry/PatchDescriptor.h>
#include <directional/geometry/SurfaceComplexSimplification.h>

#include <gtest/gtest.h>

#include <numeric>
#include <vector>

namespace {

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
  cell.sourceFaces.resize(boundaryCount);
  std::iota(cell.sourceFaces.begin(), cell.sourceFaces.end(), 0);
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
    node.barycentric << 0.0, 1.0, 0.0;
    directional::geometry::SurfaceArrangementNodeOccurrence previousFace;
    previousFace.sourceFace = (i + boundaryCount - 1) % boundaryCount;
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
    edge.sourceComponent = 2;
    edge.sourceSheet = 4;
    edge.railId = side;
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
            (std::set<int>{0}));
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
  Eigen::MatrixXd V(4, 3);
  V << 0.0, 0.0, 0.0,
       1.0, 0.0, 0.0,
       1.0, 1.0, 0.0,
       0.0, 1.0, 0.0;
  Eigen::MatrixXi F(2, 3);
  F << 0, 1, 2,
       0, 2, 3;
  directional::geometry::SurfaceArrangementArc first;
  first.id = 0;
  first.sourceFace = 0;
  first.startBarycentric << 1.0, 0.0, 0.0;
  first.endBarycentric << 0.0, 0.0, 1.0;
  first.family = 0;
  first.strand = 7;
  first.sourceComponent = 0;
  first.sourceSheet = 0;
  directional::geometry::SurfaceArrangementArc second = first;
  second.id = 1;
  second.sourceFace = 1;
  second.startBarycentric << 1.0, 0.0, 0.0;
  second.endBarycentric << 0.0, 1.0, 0.0;
  const directional::geometry::SurfaceCellComplex complex =
      directional::geometry::build_surface_cell_complex(V, F, {first, second});
  ASSERT_TRUE(complex.diagnostics.topologyValid);
  const int oddBefore = static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && cell.halfedges.size() % 2U != 0U;
      }));
  ASSERT_EQ(2, oddBefore);

  const auto repaired =
      directional::geometry::repair_surface_cell_boundary_parity(complex);
  ASSERT_TRUE(repaired.success) << repaired.failure;
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

  const auto completion =
      directional::geometry::complete_surface_cell_complex(complex, V, F);
  ASSERT_TRUE(completion.success) << completion.failure;
  EXPECT_EQ(2, completion.parityOddCellsBefore);
  EXPECT_EQ(0, completion.parityOddCellsAfter);
  EXPECT_GT(completion.paritySplitEdges, 0);
  EXPECT_TRUE(completion.hasPreparedComplex);
  EXPECT_FALSE(completion.assembly.mesh.quads.empty());

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
  const auto perturbed =
      directional::geometry::subdivide_surface_cell_complex_edges(
          repaired.complex, {{sharedInterior, 1}});
  ASSERT_TRUE(perturbed.success) << perturbed.failure;
  const auto sideRepair =
      directional::geometry::repair_surface_cell_side_subdivisions(
          perturbed.complex, V, F);
  ASSERT_TRUE(sideRepair.success) << sideRepair.failure;
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
     FiveSidedRepairUsesBoundedClosedFormInsteadOfCompositionSearch) {
  const Fixture fixture = make_authoritative_patch({20, 1, 1, 1, 1});
  const auto before = directional::geometry::derive_patch_descriptor(
      fixture.complex, fixture.complex.cells.front(), fixture.V, fixture.F);
  ASSERT_EQ(5U, before.sides.size());
  ASSERT_EQ(directional::geometry::PureQuadPatchRejectReason::SideInequality,
            before.feasibility.reason);

  const auto repaired =
      directional::geometry::repair_surface_cell_side_subdivisions(
          fixture.complex, fixture.V, fixture.F);
  ASSERT_TRUE(repaired.success) << repaired.failure;
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
  const Fixture duplicate = make_authoritative_patch({2, 2, 2, 2});
  append_authoritative_component(duplicate.complex, fixture.complex);
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
  EXPECT_FALSE(completion.success);
  EXPECT_EQ("UnresolvedSingularityOwnership", completion.failure);
  EXPECT_TRUE(completion.completedPatches.empty());
}

TEST(PatchDescriptorMilestoneE,
     CompletesAuthoritativeComplexThroughMilestoneEEntryPoint) {
  const Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(completion.success) << completion.assembly.failure;
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(0, completion.failedPatches);
  ASSERT_EQ(1U, completion.completedPatches.size());
  EXPECT_EQ(4U, completion.assembly.mesh.quads.size());
  EXPECT_EQ(1, completion.assembly.connectedComponents);
  EXPECT_EQ(1, completion.assembly.boundaryLoopCount);
  EXPECT_EQ(1, completion.assembly.eulerCharacteristic);
}


TEST(PatchDescriptorMilestoneE,
     ComplexCompletionFailsClosedInsteadOfReturningPartialOutput) {
  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});
  Fixture invalid = make_authoritative_patch({2, 2, 2, 2});
  invalid.complex.cells.front().disk = false;
  invalid.complex.cells.front().cellClass =
      directional::geometry::SurfaceArrangementCellClass::NonDisk;
  append_authoritative_component(invalid.complex, fixture.complex);

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F);

  EXPECT_FALSE(completion.success);
  EXPECT_EQ("IncompleteSurfaceCellComplex", completion.failure);
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(1, completion.failedPatches);
  EXPECT_EQ(1U, completion.completedPatches.size());
  EXPECT_FALSE(completion.assembly.success);
  EXPECT_TRUE(completion.assembly.mesh.quads.empty());
}

TEST(PatchDescriptorMilestoneE,
     ExteriorArrangementCyclesAreNotAuthoritativeCompletionPatches) {
  Fixture fixture = make_authoritative_patch({2, 2, 2, 2});

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(completion.success) << completion.failure;
  EXPECT_EQ(1U, completion.descriptors.descriptors.size());
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(0, completion.failedPatches);
  EXPECT_EQ(1U, completion.completedPatches.size());
}
