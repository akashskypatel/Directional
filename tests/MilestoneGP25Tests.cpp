#include <algorithm>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include <directional/pipeline/RemeshPipeline.h>

namespace {

struct TestMesh {
  Eigen::MatrixXd vertices;
  Eigen::MatrixXi faces;
};

TestMesh make_interleaved_two_squares() {
  TestMesh mesh;
  mesh.vertices.resize(8, 3);
  mesh.vertices << 0.0, 0.0, 0.0,
                   1.0, 0.0, 0.0,
                   1.0, 1.0, 0.0,
                   0.0, 1.0, 0.0,
                   3.0, 0.0, 0.0,
                   4.0, 0.0, 0.0,
                   4.0, 1.0, 0.0,
                   3.0, 1.0, 0.0;
  mesh.faces.resize(4, 3);
  // Deliberately interleave source-face ownership between components.
  mesh.faces << 0, 1, 2,
                4, 5, 6,
                0, 2, 3,
                4, 6, 7;
  return mesh;
}

Eigen::MatrixXd constant_raw_field(const int faceCount) {
  Eigen::MatrixXd raw(faceCount, 12);
  for (int face = 0; face < faceCount; ++face) {
    raw.block(face, 0, 1, 3) << 1.0, 0.0, 0.0;
    raw.block(face, 3, 1, 3) << 0.0, 1.0, 0.0;
    raw.block(face, 6, 1, 3) << -1.0, 0.0, 0.0;
    raw.block(face, 9, 1, 3) << 0.0, -1.0, 0.0;
  }
  return raw;
}

directional::pipeline::RemeshOptions surface_options() {
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = true;
  options.parallelizeComponents = true;
  options.lengthRatio = 0.2;
  return options;
}

void expect_same_structure(
    const directional::pipeline::RemeshResult &lhs,
    const directional::pipeline::RemeshResult &rhs) {
  EXPECT_EQ(lhs.is_produced(), rhs.is_produced());
  EXPECT_EQ(lhs.product().vertices, rhs.product().vertices);
  EXPECT_EQ(lhs.product().faces, rhs.product().faces);
  EXPECT_EQ(lhs.product().degrees, rhs.product().degrees);
  EXPECT_EQ(lhs.product().rawCrossField, rhs.product().rawCrossField);
  EXPECT_EQ(lhs.product().crossFieldMatching, rhs.product().crossFieldMatching);
  EXPECT_EQ(lhs.product().crossFieldEffort, rhs.product().crossFieldEffort);
  EXPECT_EQ(lhs.product().crossFieldSingularCycles, rhs.product().crossFieldSingularCycles);
  EXPECT_EQ(lhs.product().crossFieldSingularIndices, rhs.product().crossFieldSingularIndices);
  ASSERT_EQ(lhs.product().outputVertexProvenance.size(),
            rhs.product().outputVertexProvenance.size());
  for (std::size_t index = 0; index < lhs.product().outputVertexProvenance.size();
       ++index) {
    const auto &a = lhs.product().outputVertexProvenance[index];
    const auto &b = rhs.product().outputVertexProvenance[index];
    EXPECT_EQ(a.face, b.face);
    EXPECT_EQ(a.component, b.component);
    EXPECT_EQ(a.sheet, b.sheet);
    EXPECT_TRUE(a.barycentric.isApprox(b.barycentric, 1.0e-12));
    EXPECT_TRUE(a.position.isApprox(b.position, 1.0e-12));
  }
  ASSERT_EQ(lhs.product().outputVertexLineage.size(), rhs.product().outputVertexLineage.size());
  for (std::size_t index = 0; index < lhs.product().outputVertexLineage.size(); ++index) {
    EXPECT_EQ(lhs.product().outputVertexLineage[index].outputVertex,
              rhs.product().outputVertexLineage[index].outputVertex);
    EXPECT_EQ(lhs.product().outputVertexLineage[index].sourcePoint.face,
              rhs.product().outputVertexLineage[index].sourcePoint.face);
    EXPECT_EQ(lhs.product().outputVertexLineage[index].sourcePoint.component,
              rhs.product().outputVertexLineage[index].sourcePoint.component);
  }
  ASSERT_EQ(lhs.product().outputQuadLineage.size(), rhs.product().outputQuadLineage.size());
  for (std::size_t index = 0; index < lhs.product().outputQuadLineage.size(); ++index) {
    EXPECT_EQ(lhs.product().outputQuadLineage[index].outputQuad,
              rhs.product().outputQuadLineage[index].outputQuad);
    EXPECT_EQ(lhs.product().outputQuadLineage[index].sourcePatch,
              rhs.product().outputQuadLineage[index].sourcePatch);
    EXPECT_EQ(lhs.product().outputQuadLineage[index].operationLocalQuad,
              rhs.product().outputQuadLineage[index].operationLocalQuad);
  }

  EXPECT_EQ(lhs.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed,
            rhs.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed);
  EXPECT_EQ(lhs.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize,
            rhs.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize);
  EXPECT_EQ(lhs.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSizeRelaxed,
            rhs.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSizeRelaxed);
  EXPECT_DOUBLE_EQ(
      lhs.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSizeMaxRelaxationRatio,
      rhs.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSizeMaxRelaxationRatio);
  if (lhs.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize &&
      rhs.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize) {
    EXPECT_EQ(lhs.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSize,
              rhs.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSize);
  }

  EXPECT_EQ(lhs.surfaceCellContext.productSnapshots.hasOptimizationResult,
            rhs.surfaceCellContext.productSnapshots.hasOptimizationResult);
  if (lhs.surfaceCellContext.productSnapshots.hasOptimizationResult) {
    const auto &aOptimization =
        lhs.surfaceCellContext.productSnapshots.optimizationResult;
    const auto &bOptimization =
        rhs.surfaceCellContext.productSnapshots.optimizationResult;
    EXPECT_EQ(aOptimization.vertices, bOptimization.vertices);
    EXPECT_EQ(aOptimization.quads, bOptimization.quads);
    EXPECT_EQ(aOptimization.topologyHash, bOptimization.topologyHash);
    EXPECT_EQ(aOptimization.monotonicEnergy,
              bOptimization.monotonicEnergy);
    EXPECT_EQ(aOptimization.topologyHashFixed,
              bOptimization.topologyHashFixed);
    EXPECT_EQ(aOptimization.projectionStayedOnComponents,
              bOptimization.projectionStayedOnComponents);
    EXPECT_EQ(aOptimization.projectionStayedOnSheets,
              bOptimization.projectionStayedOnSheets);
  }
  EXPECT_EQ(lhs.surfaceCellContext.productSnapshots.hasValidationResult,
            rhs.surfaceCellContext.productSnapshots.hasValidationResult);
  if (lhs.surfaceCellContext.productSnapshots.hasValidationResult) {
    const auto &aValidation = lhs.surfaceCellContext.productSnapshots.validationResult;
    const auto &bValidation = rhs.surfaceCellContext.productSnapshots.validationResult;
    EXPECT_EQ(aValidation.accepted, bValidation.accepted);
    EXPECT_EQ(aValidation.tJunctions, bValidation.tJunctions);
    EXPECT_EQ(aValidation.nonManifold, bValidation.nonManifold);
    EXPECT_EQ(aValidation.degenerate, bValidation.degenerate);
    EXPECT_EQ(aValidation.inverted, bValidation.inverted);
    EXPECT_EQ(aValidation.selfIntersecting,
              bValidation.selfIntersecting);
    EXPECT_EQ(aValidation.connectedComponentMismatchCount,
              bValidation.connectedComponentMismatchCount);
  }

  const auto &a = lhs.diagnostics;
  const auto &b = rhs.diagnostics;
  EXPECT_EQ(a.executedBackend, b.executedBackend);
  EXPECT_EQ(a.surfaceCellOutputOrigin, b.surfaceCellOutputOrigin);
  EXPECT_EQ(a.surfaceCellRemeshOccurred, b.surfaceCellRemeshOccurred);
  EXPECT_EQ(a.surfaceCellSourceGridRecoveryUsed,
            b.surfaceCellSourceGridRecoveryUsed);
  EXPECT_EQ(a.surfaceCellSourceGridRecoveryTargetSizeRelaxed,
            b.surfaceCellSourceGridRecoveryTargetSizeRelaxed);
  EXPECT_DOUBLE_EQ(
      a.surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio,
      b.surfaceCellSourceGridRecoveryTargetSizeMaxRelaxationRatio);
  EXPECT_EQ(a.componentCount, b.componentCount);
  EXPECT_EQ(a.failedComponentIndex, b.failedComponentIndex);
  ASSERT_EQ(a.surfaceCellStageLineage.size(),
            b.surfaceCellStageLineage.size());
  for (std::size_t index = 0; index < a.surfaceCellStageLineage.size();
       ++index) {
    const auto &la = a.surfaceCellStageLineage[index];
    const auto &lb = b.surfaceCellStageLineage[index];
    EXPECT_EQ(la.stage, lb.stage);
    EXPECT_EQ(la.componentIndex, lb.componentIndex);
    EXPECT_EQ(la.inputObject.type, lb.inputObject.type);
    EXPECT_EQ(la.inputObject.structuralHash,
              lb.inputObject.structuralHash)
        << "component=" << la.componentIndex << " stage=" << la.stage
        << " input";
    EXPECT_EQ(la.outputObject.type, lb.outputObject.type);
    EXPECT_EQ(la.outputObject.structuralHash,
              lb.outputObject.structuralHash)
        << "component=" << la.componentIndex << " stage=" << la.stage
        << " output";
    EXPECT_EQ(la.terminalFailureCode, lb.terminalFailureCode);
    EXPECT_EQ(la.terminalFailureStage, lb.terminalFailureStage);
  }
}

} // namespace

TEST(MilestoneGP25, ComponentCrossFieldRemapPreservesAuthoritativeMetadata) {
  const TestMesh mesh = make_interleaved_two_squares();
  directional::TriMesh sourceMesh;
  sourceMesh.set_mesh(mesh.vertices, mesh.faces);
  directional::fields::CrossFieldResult field =
      directional::pipeline::finalize_surface_cell_raw_cross_field(
          sourceMesh, constant_raw_field(mesh.faces.rows()));
  field.confidence.resize(4);
  field.confidence << 0.1, 0.2, 0.3, 0.4;
  field.singularCycles.resize(2);
  field.singularCycles << 0, 6;
  field.singularIndices.resize(2);
  field.singularIndices << 1, -1;

  const auto components = directional::geometry::compact_face_components(
      mesh.vertices, mesh.faces, &field.rawField);
  ASSERT_EQ(2U, components.size());
  ASSERT_EQ(std::vector<int>({1, 3}), components[1].originalFaces);

  directional::TriMesh componentMesh;
  componentMesh.set_mesh(components[1].vertices, components[1].faces);
  const directional::fields::CrossFieldResult local =
      directional::pipeline::remap_surface_cell_cross_field_component(
          sourceMesh, components[1], componentMesh, field);

  ASSERT_EQ(2, local.rawField.rows());
  EXPECT_DOUBLE_EQ(0.2, local.confidence(0));
  EXPECT_DOUBLE_EQ(0.4, local.confidence(1));
  ASSERT_EQ(1, local.singularCycles.size());
  EXPECT_EQ(2, local.singularCycles(0));
  EXPECT_EQ(-1, local.singularIndices(0));
  EXPECT_TRUE(local.matchingComputed);
  EXPECT_TRUE(local.singularitiesComputed);
  EXPECT_TRUE(local.confidenceComputed);
  EXPECT_TRUE(local.uncoveredFacePolicyApplied);
  ASSERT_EQ(componentMesh.EF.rows(), local.matching.size());
  ASSERT_EQ(static_cast<std::size_t>(componentMesh.EF.rows()),
            local.edgeTransitions.size());
  for (int edge = 0; edge < componentMesh.EF.rows(); ++edge) {
    const auto &transition = local.edgeTransitions[static_cast<std::size_t>(edge)];
    EXPECT_EQ(edge, transition.sourceEdge);
    EXPECT_EQ(componentMesh.EV(edge, 0), transition.sourceVertex0);
    EXPECT_EQ(componentMesh.EV(edge, 1), transition.sourceVertex1);
    EXPECT_EQ(componentMesh.EF(edge, 0), transition.firstFace);
    EXPECT_EQ(componentMesh.EF(edge, 1), transition.secondFace);
    EXPECT_EQ(local.matching(edge), transition.matching);
    EXPECT_DOUBLE_EQ(local.effort(edge), transition.effort);
  }
}

TEST(MilestoneGP25, SequentialAndParallelSchedulesAreStructurallyIdentical) {
  const TestMesh mesh = make_interleaved_two_squares();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());

  directional::pipeline::RemeshOptions sequential = surface_options();
  sequential.maxComponentThreads = 1;
  const auto sequentialResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, sequential);

  directional::pipeline::RemeshOptions parallel = surface_options();
  parallel.maxComponentThreads = 2;
  const auto parallelResult =
      directional::pipeline::remesh_from_raw_cross_field(
          mesh.vertices, mesh.faces, raw, parallel);

  ASSERT_TRUE(sequentialResult.is_produced());
  ASSERT_TRUE(parallelResult.is_produced());
  ASSERT_TRUE(sequentialResult.surfaceCellContext.productSnapshots.hasOptimizationResult);
  ASSERT_TRUE(sequentialResult.surfaceCellContext.productSnapshots.hasValidationResult);
  ASSERT_TRUE(sequentialResult.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed);
  ASSERT_TRUE(
      sequentialResult.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize);
  ASSERT_EQ(mesh.vertices.rows(),
            sequentialResult.surfaceCellContext.productSnapshots.sourceGridRecoveryTargetSize.size());
  ASSERT_TRUE(parallelResult.surfaceCellContext.productSnapshots.sourceGridRecoveryUsed);
  ASSERT_TRUE(
      parallelResult.surfaceCellContext.productSnapshots.hasSourceGridRecoveryTargetSize);
  EXPECT_EQ(sequentialResult.product().vertices,
            sequentialResult.surfaceCellContext.productSnapshots.optimizationResult.vertices);
  EXPECT_EQ(sequentialResult.product().faces,
            sequentialResult.surfaceCellContext.productSnapshots.optimizationResult.quads);
  EXPECT_EQ(sequentialResult.product().outputVertexProvenance.size(),
            sequentialResult.surfaceCellContext.productSnapshots.optimizationResult
                .vertexProvenance.size());
  expect_same_structure(sequentialResult, parallelResult);
  EXPECT_EQ(1U, sequentialResult.diagnostics.componentThreadsUsed);
  EXPECT_EQ(2U, parallelResult.diagnostics.componentThreadsUsed);
}

TEST(MilestoneGP25, RepeatedParallelSchedulesAreDeterministic) {
  const TestMesh mesh = make_interleaved_two_squares();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  directional::pipeline::RemeshOptions options = surface_options();
  options.maxComponentThreads = 2;

  const auto reference = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, raw, options);
  ASSERT_TRUE(reference.is_produced());
  for (int run = 0; run < 8; ++run) {
    const auto result = directional::pipeline::remesh_from_raw_cross_field(
        mesh.vertices, mesh.faces, raw, options);
    ASSERT_TRUE(result.is_produced()) << run;
    expect_same_structure(reference, result);
  }
}

TEST(MilestoneGP25, ProvenanceAndLineageAreRemappedToOriginalMesh) {
  const TestMesh mesh = make_interleaved_two_squares();
  directional::pipeline::RemeshOptions options = surface_options();
  options.maxComponentThreads = 2;
  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, constant_raw_field(mesh.faces.rows()),
      options);

  ASSERT_TRUE(result.is_produced());
  ASSERT_EQ(static_cast<std::size_t>(result.product().vertices.rows()),
            result.product().outputVertexProvenance.size());
  for (const auto &point : result.product().outputVertexProvenance) {
    EXPECT_GE(point.face, 0);
    EXPECT_LT(point.face, mesh.faces.rows());
    EXPECT_GE(point.component, 0);
    EXPECT_LT(point.component, 2);
  }
  ASSERT_EQ(static_cast<std::size_t>(result.product().vertices.rows()),
            result.product().outputVertexLineage.size());
  for (std::size_t index = 0; index < result.product().outputVertexLineage.size();
       ++index) {
    const auto &lineage = result.product().outputVertexLineage[index];
    EXPECT_EQ(static_cast<int>(index), lineage.outputVertex);
    if (lineage.kind ==
        directional::geometry::PureQuadVertexLineageKind::SourceTriangle) {
      EXPECT_GE(lineage.sourcePoint.face, 0);
      EXPECT_LT(lineage.sourcePoint.face, mesh.faces.rows());
    } else {
      EXPECT_GE(lineage.featureInterval.start.face, 0);
      EXPECT_LT(lineage.featureInterval.start.face, mesh.faces.rows());
      EXPECT_GE(lineage.featureInterval.end.face, 0);
      EXPECT_LT(lineage.featureInterval.end.face, mesh.faces.rows());
    }
  }
  ASSERT_EQ(static_cast<std::size_t>(result.product().faces.rows()),
            result.product().outputQuadLineage.size());
  for (std::size_t index = 0; index < result.product().outputQuadLineage.size(); ++index) {
    EXPECT_EQ(static_cast<int>(index),
              result.product().outputQuadLineage[index].outputQuad);
  }
}

TEST(MilestoneGP25, InjectedFailuresAreAtomicAndIdentifyComponentAndStage) {
  const TestMesh mesh = make_interleaved_two_squares();
  const Eigen::MatrixXd raw = constant_raw_field(mesh.faces.rows());
  const std::vector<std::string> stages = {
      "feature", "metric", "relief", "tracing", "strands",
      "embedding", "arrangement", "simplification", "completion",
      "optimization", "validation"};

  for (int stage = 0; stage < static_cast<int>(stages.size()); ++stage) {
    directional::pipeline::RemeshOptions options = surface_options();
    options.maxComponentThreads = 2;
    options.surfaceCells.injectFailureAfterStage = stage;
    options.surfaceCells.injectFailureComponentIndex = 1;

    const auto result = directional::pipeline::remesh_from_raw_cross_field(
        mesh.vertices, mesh.faces, raw, options);

    ASSERT_FALSE(result.is_produced()) << stage;
    EXPECT_EQ(nullptr, result.produced_product()) << stage;
    EXPECT_EQ(1U, result.diagnostics.failedComponentIndex) << stage;
    EXPECT_EQ(1U, result.diagnostics.failedComponentMinimumOriginalFace)
        << stage;
    EXPECT_EQ("InjectedStageFailure",
              result.diagnostics.terminalFailureCode)
        << stage;
    EXPECT_EQ(stages[static_cast<std::size_t>(stage)],
              result.diagnostics.terminalFailureStage)
        << stage;
    ASSERT_EQ(2U, result.diagnostics.components.size()) << stage;
    EXPECT_TRUE(result.diagnostics.components[0].success) << stage;
    EXPECT_FALSE(result.diagnostics.components[1].success) << stage;
    EXPECT_EQ("InjectedStageFailure",
              result.diagnostics.components[1].terminalFailureCode)
        << stage;
    EXPECT_EQ(stages[static_cast<std::size_t>(stage)],
              result.diagnostics.components[1].terminalFailureStage)
        << stage;
    EXPECT_EQ(directional::SurfaceCellOutputOrigin::None,
              result.diagnostics.surfaceCellOutputOrigin)
        << stage;
    EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred) << stage;
  }
}

TEST(MilestoneGP25, MixedFallbackMergeSupportsDifferentFaceDegrees) {
  const TestMesh mesh = make_interleaved_two_squares();
  directional::pipeline::RemeshOptions options = surface_options();
  options.maxComponentThreads = 2;
  options.surfaceCells.injectFailureAfterStage = 0;
  options.surfaceCells.injectFailureComponentIndex = 1;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::ReturnInputMesh;

  const auto result = directional::pipeline::remesh_from_raw_cross_field(
      mesh.vertices, mesh.faces, constant_raw_field(mesh.faces.rows()),
      options);

  ASSERT_TRUE(result.is_produced());
  EXPECT_EQ(directional::SurfaceCellOutputOrigin::Mixed,
            result.diagnostics.surfaceCellOutputOrigin);
  EXPECT_EQ("Mixed", result.diagnostics.executedBackend);
  EXPECT_TRUE(result.diagnostics.surfaceCellFallbackAttempted);
  EXPECT_TRUE(result.diagnostics.surfaceCellReturnedInputMeshFallback);
  EXPECT_FALSE(result.diagnostics.surfaceCellRemeshOccurred);
  ASSERT_EQ(result.product().faces.rows(), result.product().degrees.size());
  EXPECT_GE(result.product().faces.cols(), 4);
  bool sawTriangle = false;
  bool sawQuad = false;
  for (int face = 0; face < result.product().faces.rows(); ++face) {
    sawTriangle = sawTriangle || result.product().degrees(face) == 3;
    sawQuad = sawQuad || result.product().degrees(face) == 4;
    for (int corner = 0; corner < result.product().degrees(face); ++corner) {
      EXPECT_GE(result.product().faces(face, corner), 0);
      EXPECT_LT(result.product().faces(face, corner), result.product().vertices.rows());
    }
    for (int corner = result.product().degrees(face); corner < result.product().faces.cols();
         ++corner) {
      EXPECT_EQ(-1, result.product().faces(face, corner));
    }
  }
  EXPECT_TRUE(sawTriangle);
  EXPECT_TRUE(sawQuad);
}
