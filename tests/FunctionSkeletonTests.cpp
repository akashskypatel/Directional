#include <algorithm>
#include <vector>

#include <Eigen/Core>
#include <gtest/gtest.h>

#include <directional/meshing/FunctionSkeletonBuilder.h>
#include <directional/meshing/FunctionSkeletonSimplifier.h>

namespace {

struct TestSegmentData {
  bool isFunction = false;
  int origNFunctionIndex = -1;
  int localPencilIndex = -1;
  int lineInPencil = -1;
  int origHalfedge = -1;
};

struct TestVertexData {
  Eigen::RowVector3d coords = Eigen::RowVector3d::Zero();
};

struct TestVertex {
  int ID = -1;
  bool valid = true;
  int halfedge = -1;
  TestVertexData data;
};

struct TestHalfedge {
  int ID = -1;
  bool valid = true;
  int vertex = -1;
  int face = -1;
  int edge = -1;
  int next = -1;
  int prev = -1;
  int twin = -1;
  TestSegmentData data;
};

struct TestDcel {
  std::vector<TestVertex> vertices;
  std::vector<TestHalfedge> halfedges;

  [[nodiscard]] bool valid_halfedge(const int halfedge) const {
    return halfedge >= 0 && halfedge < static_cast<int>(halfedges.size()) &&
           halfedges[static_cast<std::size_t>(halfedge)].valid;
  }
};

TestDcel make_dcel(const int vertexCount) {
  TestDcel dcel;
  dcel.vertices.resize(static_cast<std::size_t>(vertexCount));
  for (int vertex = 0; vertex < vertexCount; ++vertex) {
    dcel.vertices[static_cast<std::size_t>(vertex)].ID = vertex;
    dcel.vertices[static_cast<std::size_t>(vertex)].data.coords =
        Eigen::RowVector3d(static_cast<double>(vertex), 0.0, 0.0);
  }
  return dcel;
}

void add_function_edge(TestDcel &dcel, const int source, const int target,
                       const int family = 0, const bool protectedSeam = false) {
  const int first = static_cast<int>(dcel.halfedges.size());
  const int second = first + 1;
  TestHalfedge forward;
  forward.ID = first;
  forward.vertex = source;
  forward.face = first;
  forward.twin = second;
  forward.data.isFunction = true;
  forward.data.origNFunctionIndex = family;
  forward.data.origHalfedge = protectedSeam ? first : -1;

  TestHalfedge backward;
  backward.ID = second;
  backward.vertex = target;
  backward.face = second;
  backward.twin = first;
  backward.data.isFunction = true;
  backward.data.origNFunctionIndex = family;
  backward.data.origHalfedge = protectedSeam ? second : -1;

  dcel.vertices[static_cast<std::size_t>(source)].halfedge = first;
  dcel.vertices[static_cast<std::size_t>(target)].halfedge = second;
  dcel.halfedges.push_back(forward);
  dcel.halfedges.push_back(backward);
}

void add_boundary_function_edge(TestDcel &dcel, const int source,
                                const int target, const int family = 0) {
  const int first = static_cast<int>(dcel.halfedges.size());
  TestHalfedge forward;
  forward.ID = first;
  forward.vertex = source;
  forward.face = first;
  forward.twin = -1;
  forward.data.isFunction = true;
  forward.data.origNFunctionIndex = family;

  dcel.vertices[static_cast<std::size_t>(source)].halfedge = first;
  dcel.vertices[static_cast<std::size_t>(target)].halfedge = first;
  dcel.halfedges.push_back(forward);
}

} // namespace

TEST(FunctionSkeletonPhase04, SkeletonCollapsesDegreeTwoFunctionChain) {
  TestDcel dcel = make_dcel(4);
  add_function_edge(dcel, 0, 1);
  add_function_edge(dcel, 1, 2);
  add_function_edge(dcel, 2, 3);

  const directional::FunctionSkeleton skeleton =
      directional::detail::FunctionSkeletonBuilder::build(dcel);

  ASSERT_TRUE(skeleton.matchesFunctionConnectivity);
  EXPECT_EQ(skeleton.rawFunctionEdgeCount, 3);
  EXPECT_EQ(skeleton.nodes.size(), 2);
  ASSERT_EQ(skeleton.edges.size(), 1);
  EXPECT_EQ(skeleton.edges.front().halfedgeChain.size(), 6);
  EXPECT_DOUBLE_EQ(skeleton.edges.front().geometricLength, 3.0);
}

TEST(FunctionSkeletonPhase04, SkeletonPreservesJunctions) {
  TestDcel dcel = make_dcel(4);
  add_function_edge(dcel, 0, 1);
  add_function_edge(dcel, 1, 2);
  add_function_edge(dcel, 1, 3);

  const directional::FunctionSkeleton skeleton =
      directional::detail::FunctionSkeletonBuilder::build(dcel);

  ASSERT_TRUE(skeleton.matchesFunctionConnectivity);
  const auto junction = std::find_if(
      skeleton.nodes.begin(), skeleton.nodes.end(),
      [](const directional::FunctionSkeletonNode &node) {
        return node.dcelVertex == 1 && node.functionDegree == 3 && node.branch;
      });
  EXPECT_NE(junction, skeleton.nodes.end());
  EXPECT_EQ(skeleton.edges.size(), 3);
}

TEST(FunctionSkeletonPhase04, SkeletonPreservesSingularNodes) {
  TestDcel dcel = make_dcel(5);
  add_function_edge(dcel, 0, 1);
  add_function_edge(dcel, 1, 2);
  add_function_edge(dcel, 2, 3);
  add_function_edge(dcel, 2, 4);

  const directional::FunctionSkeleton skeleton =
      directional::detail::FunctionSkeletonBuilder::build(dcel);

  const auto singularLikeBranch = std::find_if(
      skeleton.nodes.begin(), skeleton.nodes.end(),
      [](const directional::FunctionSkeletonNode &node) {
        return node.dcelVertex == 2 && node.functionDegree == 3;
      });
  ASSERT_NE(singularLikeBranch, skeleton.nodes.end());
  EXPECT_TRUE(singularLikeBranch->branch);
}

TEST(FunctionSkeletonPhase04, SkeletonPreservesProtectedBoundaryChains) {
  TestDcel dcel = make_dcel(3);
  add_boundary_function_edge(dcel, 0, 1);
  add_boundary_function_edge(dcel, 1, 2);

  const directional::FunctionSkeleton skeleton =
      directional::detail::FunctionSkeletonBuilder::build(dcel);

  ASSERT_TRUE(skeleton.matchesFunctionConnectivity);
  const auto protectedMiddle = std::find_if(
      skeleton.nodes.begin(), skeleton.nodes.end(),
      [](const directional::FunctionSkeletonNode &node) {
        return node.dcelVertex == 1 && node.boundaryProtected;
      });
  EXPECT_NE(protectedMiddle, skeleton.nodes.end());
}

TEST(FunctionSkeletonPhase04, SkeletonEditPlanIsDeterministic) {
  TestDcel dcel = make_dcel(4);
  add_function_edge(dcel, 0, 1);
  add_function_edge(dcel, 1, 2);
  add_function_edge(dcel, 2, 3);

  const directional::FunctionSkeleton skeleton =
      directional::detail::FunctionSkeletonBuilder::build(dcel);
  const directional::FunctionSkeletonEditPlan first =
      directional::detail::FunctionSkeletonSimplifier::plan_read_only(skeleton);
  const directional::FunctionSkeletonEditPlan second =
      directional::detail::FunctionSkeletonSimplifier::plan_read_only(skeleton);

  EXPECT_EQ(first.degreeOneInteriorLeaves, second.degreeOneInteriorLeaves);
  EXPECT_EQ(first.redundantDegreeTwoNodes, second.redundantDegreeTwoNodes);
  EXPECT_EQ(first.plannedEdits, 0);
  EXPECT_EQ(first.appliedEdits, 0);
}

TEST(FunctionSkeletonPhase04, SkeletonPlansDanglingChainCleanup) {
  TestDcel dcel = make_dcel(4);
  add_function_edge(dcel, 0, 1);
  add_function_edge(dcel, 1, 2);
  add_function_edge(dcel, 2, 3);

  const directional::FunctionSkeleton skeleton =
      directional::detail::FunctionSkeletonBuilder::build(dcel);
  const directional::FunctionSkeletonEditPlan plan =
      directional::detail::FunctionSkeletonSimplifier::plan_safe_cleanup(
          skeleton);

  EXPECT_EQ(plan.plannedEdits, 1);
  EXPECT_EQ(plan.rejectedEdits, 0);
  EXPECT_EQ(plan.clearFunctionHalfedges.size(), 6);
  EXPECT_TRUE(std::is_sorted(plan.clearFunctionHalfedges.begin(),
                            plan.clearFunctionHalfedges.end()));
}

TEST(FunctionSkeletonPhase04, SkeletonPlanPreservesProtectedChains) {
  TestDcel dcel = make_dcel(3);
  add_boundary_function_edge(dcel, 0, 1);
  add_boundary_function_edge(dcel, 1, 2);

  const directional::FunctionSkeleton skeleton =
      directional::detail::FunctionSkeletonBuilder::build(dcel);
  const directional::FunctionSkeletonEditPlan plan =
      directional::detail::FunctionSkeletonSimplifier::plan_safe_cleanup(
          skeleton);

  EXPECT_EQ(plan.plannedEdits, 0);
  EXPECT_TRUE(plan.clearFunctionHalfedges.empty());
}

TEST(FunctionSkeletonPhase04, ReadOnlySkeletonMatchesLegacyFunctionConnectivity) {
  TestDcel dcel = make_dcel(3);
  add_function_edge(dcel, 0, 1);
  add_function_edge(dcel, 1, 2);

  const directional::FunctionSkeleton skeleton =
      directional::detail::FunctionSkeletonBuilder::build(dcel);

  EXPECT_TRUE(skeleton.matchesFunctionConnectivity);
  EXPECT_EQ(skeleton.rawFunctionHalfedgeCount, 4);
  EXPECT_EQ(skeleton.rawFunctionEdgeCount, 2);
}
