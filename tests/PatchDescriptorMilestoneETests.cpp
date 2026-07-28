#include <directional/geometry/PatchDescriptor.h>

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
  for (int i = 0; i < boundaryCount; ++i) {
    const double angle = 2.0 * pi * static_cast<double>(i) /
                         static_cast<double>(boundaryCount);
    fixture.V.row(i + 1) << std::cos(angle), std::sin(angle), 0.0;
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
     CompletesAuthoritativeComplexThroughMilestoneEEntryPoint) {
  const Fixture fixture = make_patch({2, 2, 2, 2});
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
  Fixture fixture = make_patch({2, 2, 2, 2});
  auto invalidCell = fixture.complex.cells.front();
  invalidCell.id = 1;
  fixture.complex.cells.push_back(std::move(invalidCell));

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
  Fixture fixture = make_patch({2, 2, 2, 2});
  auto exteriorCell = fixture.complex.cells.front();
  exteriorCell.id = 1;
  exteriorCell.cellClass =
      directional::geometry::SurfaceArrangementCellClass::Exterior;
  exteriorCell.boundaryCycle = true;
  fixture.complex.cells.push_back(std::move(exteriorCell));

  const auto completion = directional::geometry::complete_surface_cell_complex(
      fixture.complex, fixture.V, fixture.F);

  ASSERT_TRUE(completion.success) << completion.failure;
  EXPECT_EQ(1U, completion.descriptors.descriptors.size());
  EXPECT_EQ(1, completion.attemptedPatches);
  EXPECT_EQ(0, completion.failedPatches);
  EXPECT_EQ(1U, completion.completedPatches.size());
}
