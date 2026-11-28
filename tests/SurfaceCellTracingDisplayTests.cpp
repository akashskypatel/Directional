#include <directional/core/TriMesh.h>
#include <directional/io/ReadOBJ.h>
#include <directional/pipeline/RemeshPipeline.h>
#include <directional/visualization/SurfaceCellTracingDisplay.h>

#include "TestFixturePaths.h"

#include <gtest/gtest.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <fstream>
#include <iostream>
#include <map>
#include <numbers>
#include <optional>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <variant>
#include <vector>

namespace {

directional::pipeline::RemeshOptions surface_cell_options(const int stopAfterStage) {
  directional::pipeline::RemeshOptions options;
  options.backend = directional::pipeline::RemeshBackend::SurfaceCells;
  options.surfaceCells.enabled = true;
  options.surfaceCells.fallbackPolicy =
      directional::pipeline::SurfaceCellFallbackPolicy::Fail;
  options.surfaceCells.allowSourceGridRecovery = false;
  options.surfaceCells.retainIntermediateGeometry = true;
  options.surfaceCells.injectFailureAfterStage = stopAfterStage;
  options.parallelizeComponents = false;
  return options;
}

struct FixtureRun {
  directional::TriMesh mesh;
  directional::pipeline::RemeshResult result;
};

FixtureRun run_fixture(const std::string &name) {
  FixtureRun run;
  const auto stem = directional::tests::benchmark_fixture_path("milestone-g/" + name);
  if (!directional::readOBJ(stem.string() + ".obj", run.mesh)) {
    throw std::runtime_error("Failed to read fixture " + name);
  }
  std::ifstream stream(stem.string() + ".rawfield");
  int degree = 0;
  int faces = 0;
  if (!(stream >> degree >> faces) || degree != 4 || faces != run.mesh.F.rows()) {
    throw std::runtime_error("Invalid rawfield for " + name);
  }
  Eigen::MatrixXd raw(faces, 12);
  for (int face = 0; face < faces; ++face) {
    for (int column = 0; column < 12; ++column) stream >> raw(face, column);
  }
  run.result = directional::pipeline::remesh_from_raw_cross_field(
      run.mesh.V, run.mesh.F, raw, surface_cell_options(-1));
  return run;
}

// An eight-triangle fan whose cross turns by half a turn around vertex 0: a
// +1/2 singularity, outside the index range that A3 singularity ports cover.
FixtureRun run_half_index_singularity_fan() {
  constexpr int ring = 8;
  FixtureRun run;
  Eigen::MatrixXd vertices(ring + 1, 3);
  vertices.row(0) << 0.0, 0.0, 0.0;
  for (int i = 0; i < ring; ++i) {
    const double angle = 2.0 * std::numbers::pi * i / ring;
    vertices.row(i + 1) << std::cos(angle), std::sin(angle), 0.0;
  }
  Eigen::MatrixXi faces(ring, 3);
  for (int i = 0; i < ring; ++i) faces.row(i) << 0, 1 + i, 1 + (i + 1) % ring;
  run.mesh.set_mesh(vertices, faces);
  Eigen::MatrixXd raw(ring, 12);
  for (int face = 0; face < ring; ++face) {
    const Eigen::RowVector3d center =
        (vertices.row(faces(face, 0)) + vertices.row(faces(face, 1)) +
         vertices.row(faces(face, 2))) / 3.0;
    const double turn = 0.5 * std::atan2(center[1], center[0]);
    for (int branch = 0; branch < 4; ++branch) {
      const double angle = turn + branch * std::numbers::pi / 2.0;
      raw(face, 3 * branch) = std::cos(angle);
      raw(face, 3 * branch + 1) = std::sin(angle);
      raw(face, 3 * branch + 2) = 0.0;
    }
  }
  run.result = directional::pipeline::remesh_from_raw_cross_field(
      run.mesh.V, run.mesh.F, raw, surface_cell_options(-1));
  return run;
}

directional::visualization::SurfaceCellTracingDisplay display_of(const FixtureRun &run) {
  const auto &context = run.result.surfaceCellContext;
  return directional::visualization::surface_cell_tracing_display(
      run.mesh.V, run.mesh.F, run.result.diagnostics,
      context.hasTraceNetwork ? &context.productSnapshots.traceNetwork : nullptr);
}

bool has_face(const directional::visualization::SurfaceCellTracingDisplay &display,
              const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
              const Eigen::Index row) {
  for (Eigen::Index face = 0; face < display.stopFaces.rows(); ++face) {
    bool same = true;
    for (int corner = 0; corner < 3; ++corner) {
      same = same && display.stopFaceVertices.row(display.stopFaces(face, corner)) ==
                         V.row(F(row, corner));
    }
    if (same) return true;
  }
  return false;
}

bool has_vertex(const directional::visualization::SurfaceCellTracingDisplay &display,
                const Eigen::RowVector3d &point) {
  for (Eigen::Index row = 0; row < display.stopVertices.rows(); ++row) {
    if (display.stopVertices.row(row) == point) return true;
  }
  return false;
}

Eigen::Index face_row_of(const Eigen::MatrixXi &F, std::array<std::size_t, 3> corners) {
  std::sort(corners.begin(), corners.end());
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    std::array<std::size_t, 3> key{static_cast<std::size_t>(F(face, 0)),
                                   static_cast<std::size_t>(F(face, 1)),
                                   static_cast<std::size_t>(F(face, 2))};
    std::sort(key.begin(), key.end());
    if (key == corners) return face;
  }
  return -1;
}

bool has_edge(const directional::visualization::SurfaceCellTracingDisplay &display,
              const Eigen::MatrixXd &V, std::size_t a, std::size_t b) {
  const Eigen::RowVector3d pa = V.row(static_cast<Eigen::Index>(a));
  const Eigen::RowVector3d pb = V.row(static_cast<Eigen::Index>(b));
  for (Eigen::Index edge = 0; edge < display.stopEdges.rows(); ++edge) {
    const Eigen::RowVector3d start = display.stopEdgePoints.row(display.stopEdges(edge, 0));
    const Eigen::RowVector3d end = display.stopEdgePoints.row(display.stopEdges(edge, 1));
    if ((start == pa && end == pb) || (start == pb && end == pa)) return true;
  }
  return false;
}

template <std::size_t N>
std::string indices_or_dash(const std::optional<std::array<std::size_t, N>> &value) {
  if (!value.has_value()) return "-";
  std::string text;
  for (std::size_t i = 0; i < N; ++i) {
    if (i > 0) text += ",";
    text += std::to_string((*value)[i]);
  }
  return text;
}

} // namespace

TEST(SurfaceCellTracingDisplay, StopLocationShowsWhatEachStageReported) {
  // Quad tracing (A4) rejects genus_two at a face.
  const FixtureRun genus = run_fixture("genus_two");
  const auto *failure =
      genus.result.surfaceCellContext.productSnapshots.traceNetwork.phaseFront.rejection();
  ASSERT_NE(nullptr, failure) << genus.result.diagnostics.terminalFailureStage;
  ASSERT_GE(failure->face, 0);
  const auto genusDisplay = display_of(genus);
  EXPECT_TRUE(has_face(genusDisplay, genus.mesh.V, genus.mesh.F, failure->face));
  const std::string reason =
      directional::geometry::surface_phase_front_failure_reason_name(failure->reason);
  EXPECT_TRUE(std::any_of(genusDisplay.stopNotes.begin(), genusDisplay.stopNotes.end(),
                          [&](const std::string &note) {
                            return note.find(reason) != std::string::npos;
                          }));

  // The field-transport atlas rejects a +1/2 singularity at its source vertex.
  // (mechanical_feature passes the atlas once A3 decides exact ties exactly.)
  const FixtureRun singular = run_half_index_singularity_fan();
  const auto &vertexLocus = singular.result.diagnostics.terminalFailureLocus;
  ASSERT_TRUE(vertexLocus.sourceVertex.has_value())
      << singular.result.diagnostics.terminalFailureStage;
  EXPECT_EQ(0U, *vertexLocus.sourceVertex);
  EXPECT_EQ("InvalidSingularityMetadata",
            singular.result.diagnostics.terminalFailureDetailCode);
  const auto singularDisplay = display_of(singular);
  EXPECT_TRUE(has_vertex(singularDisplay,
                         singular.mesh.V.row(static_cast<Eigen::Index>(
                             *vertexLocus.sourceVertex))));

  // Whichever stage stops sphere_prescribed, the display shows every source
  // locus that stage reported.
  const FixtureRun sphere = run_fixture("sphere_prescribed");
  const auto &sphereDiagnostics = sphere.result.diagnostics;
  const auto &sphereLocus = sphereDiagnostics.terminalFailureLocus;
  ASSERT_NE("None", sphereDiagnostics.terminalFailureCode)
      << sphereDiagnostics.terminalFailureStage;
  std::cout << "SphereDisplayStop stage=" << sphereDiagnostics.terminalFailureStage
            << " code=" << sphereDiagnostics.terminalFailureCode
            << " sourceFace=" << indices_or_dash(sphereLocus.sourceFace)
            << " relatedSourceFace=" << indices_or_dash(sphereLocus.relatedSourceFace)
            << " sourceEdge=" << indices_or_dash(sphereLocus.sourceEdge)
            << " sourceVertex="
            << (sphereLocus.sourceVertex ? std::to_string(*sphereLocus.sourceVertex)
                                         : std::string("-"))
            << '\n';
  std::cout << "SphereDisplayStopDetail detail=" << sphereDiagnostics.terminalFailureDetailCode
            << " firstInvalidStage=" << sphereDiagnostics.surfaceCellFirstInvalidProducerStage
            << " firstInvalidReason=" << sphereDiagnostics.surfaceCellFirstInvalidProducerReason
            << '\n';
  std::cout << "SphereCompletionFailure detail="
            << sphere.result.surfaceCellContext.completionFailure << '\n';
  {
    // Recorded witness of the route the sphere took after its plan was built:
    // the authoritative phase-front outcome and the plan regions it was
    // offered. Output only; nothing here is asserted.
    const auto &context = sphere.result.surfaceCellContext;
    const auto flag = [](const bool value) { return value ? 1 : 0; };
    std::string phaseFront = "NotRetained";
    if (context.hasTraceNetwork) {
      const auto &front = context.productSnapshots.traceNetwork.phaseFront;
      if (front.is_not_applicable()) {
        phaseFront = "NotApplicable";
      } else if (front.produced_product() != nullptr) {
        phaseFront = "Produced";
      } else if (const auto *failure = front.rejection(); failure != nullptr) {
        phaseFront = std::string("Rejected:") +
                     directional::geometry::surface_phase_front_failure_reason_name(
                         failure->reason);
      }
    }
    std::cout << "SphereRoute producerDisposition="
              << sphereDiagnostics.surfaceCellAuthoritativeProducerDisposition
              << " phaseFront=" << phaseFront << " uniformDeclined="
              << flag(sphereDiagnostics.surfaceCellUniformPhaseFrontProducerDeclined)
              << " periodicDeclined="
              << flag(sphereDiagnostics.surfaceCellPeriodicPhaseFrontProducerDeclined)
              << " boundedDiskDeclined="
              << flag(sphereDiagnostics.surfaceCellBoundedDiskPhaseFrontProducerDeclined)
              << " seeds=" << context.productSnapshots.traceNetwork.seeds.size()
              << " traces=" << context.productSnapshots.traceNetwork.traces.size()
              << '\n';
    const auto &plan = context.productSnapshots.globalTopologyPlan;
    if (!plan.has_value()) {
      std::cout << "SpherePlan retained=0\n";
    } else {
      std::array<int, 3> arcKinds{0, 0, 0};
      for (const auto &arc : plan->arcs()) {
        const auto kind = static_cast<std::size_t>(arc.kind);
        if (kind < arcKinds.size()) ++arcKinds[kind];
      }
      std::cout << "SpherePlan retained=1 arcs=" << plan->arcs().size()
                << " mandatory=" << arcKinds[0] << " trace=" << arcKinds[1]
                << " cut=" << arcKinds[2] << " regions=" << plan->regions().size()
                << " certificates=" << plan->region_certificates().size() << '\n';
      for (const auto &region : plan->regions()) {
        std::set<std::size_t> walkNodes;
        std::map<std::size_t, int> arcUses;
        std::array<int, 3> kinds{0, 0, 0};
        int missingArcs = 0;
        for (const auto &oriented : region.boundary) {
          const auto *arc = plan->find_arc(oriented.arc);
          if (arc == nullptr) {
            ++missingArcs;
            continue;
          }
          ++arcUses[oriented.arc.index()];
          walkNodes.insert(
              (oriented.orientation == directional::authority::Orientation::Forward
                   ? arc->firstNode
                   : arc->secondNode)
                  .index());
          const auto kind = static_cast<std::size_t>(arc->kind);
          if (kind < kinds.size()) ++kinds[kind];
        }
        int repeatedArcs = 0;
        for (const auto &use : arcUses) repeatedArcs += flag(use.second > 1);
        std::cout << "SpherePlanRegion region=" << region.id.index()
                  << " boundaryArcs=" << region.boundary.size()
                  << " walkNodes=" << walkNodes.size() << " repeatedArcs=" << repeatedArcs
                  << " missingArcs=" << missingArcs << " mandatory=" << kinds[0]
                  << " trace=" << kinds[1] << " cut=" << kinds[2]
                  << " sourceFaces=" << region.sourceFaces.size();
        const auto *certificate = plan->find_region_certificate(region.id);
        if (certificate == nullptr) {
          std::cout << " certificate=-";
        } else {
          std::cout << " disc=" << flag(certificate->proves_disc_topology())
                    << " interiorSingularityFree="
                    << flag(certificate->interiorSingularityFree)
                    << " boundarySingularities="
                    << certificate->boundarySingularities.size();
        }
        std::cout << '\n';
      }
    }
  }
  {
    // Recorded census of the complex the completion stage received (the
    // retained simplification output) and of the arrangement before it, plus
    // the input cell named by the first rejecting boundary audit. Output
    // only; nothing here is asserted.
    const auto &context = sphere.result.surfaceCellContext;
    const auto flag = [](const bool value) { return value ? 1 : 0; };
    const auto census = [&](const char *name, const bool retained,
                            const directional::geometry::SurfaceCellComplex &complex) {
      int closed = 0, disk = 0, cutCellDisk = 0, bridgeExcursion = 0, supportOnly = 0;
      int multiCycle = 0, oddBounded = 0, repeatedNode = 0, sameCellTwin = 0;
      int diskWithRepeatedNode = 0, invalidHalfedges = 0;
      const auto halfedgeCount = static_cast<int>(complex.halfedges.size());
      for (const auto &cell : complex.cells) {
        closed += flag(cell.closed);
        disk += flag(cell.disk);
        cutCellDisk += flag(cell.cutCellDisk);
        bridgeExcursion += flag(cell.bridgeExcursion);
        supportOnly += flag(cell.supportOnlyCycle);
        multiCycle += flag(cell.boundaryComponentCount > 1);
        oddBounded += flag(!cell.boundaryCycle && cell.halfedges.size() % 2U != 0U);
        std::set<int> nodes;
        bool repeated = false;
        bool twinInCell = false;
        for (const int id : cell.halfedges) {
          if (id < 0 || id >= halfedgeCount) {
            ++invalidHalfedges;
            continue;
          }
          const auto &edge = complex.halfedges[static_cast<std::size_t>(id)];
          repeated = !nodes.insert(edge.from).second || repeated;
          twinInCell = twinInCell ||
                       (edge.twin >= 0 && edge.twin < halfedgeCount &&
                        complex.halfedges[static_cast<std::size_t>(edge.twin)].cell ==
                            edge.cell);
        }
        repeatedNode += flag(repeated);
        sameCellTwin += flag(twinInCell);
        diskWithRepeatedNode += flag(cell.disk && repeated);
      }
      std::cout << "SphereCompletionInput complex=" << name
                << " retained=" << flag(retained) << " nodes=" << complex.nodes.size()
                << " halfedges=" << complex.halfedges.size()
                << " cells=" << complex.cells.size() << " closed=" << closed
                << " disk=" << disk << " cutCellDisk=" << cutCellDisk
                << " bridgeExcursion=" << bridgeExcursion
                << " supportOnlyCycle=" << supportOnly << " multiCycle=" << multiCycle
                << " oddBounded=" << oddBounded << " repeatedNodeCells=" << repeatedNode
                << " sameCellTwinCells=" << sameCellTwin
                << " diskWithRepeatedNode=" << diskWithRepeatedNode
                << " invalidHalfedges=" << invalidHalfedges << '\n';
    };
    census("arrangement", context.hasArrangement, context.productSnapshots.arrangement);
    census("simplified", context.hasSimplifiedComplex, context.simplifiedComplex);
    std::cout << "SphereSimplification candidates=" << context.simplificationCandidateCount
              << " healingCandidates="
              << context.simplificationTopologyHealingCandidateCount
              << " committed=" << context.simplificationCommitted
              << " rejected=" << context.simplificationRejected
              << " transactions=" << context.simplificationTransactions.size()
              << " oddBeforeRepair=" << context.completionOddCellsBeforeRepair << '\n';
    const auto &audit = context.completionDomainIdentityAudit;
    std::cout << "SphereCompletionAudit present="
              << flag(context.hasCompletionDomainIdentityAudit) << " failure="
              << directional::geometry::surface_cell_domain_identity_failure_name(
                     audit.failure)
              << " cell=" << audit.cellId << " halfedge=" << audit.halfedgeId
              << " node=" << audit.nodeId << " sourceFace=" << audit.sourceFace << '\n';
    const auto &input = context.simplifiedComplex;
    if (context.hasCompletionDomainIdentityAudit && context.hasSimplifiedComplex &&
        audit.cellId >= 0 && audit.cellId < static_cast<int>(input.cells.size()) &&
        input.cells[static_cast<std::size_t>(audit.cellId)].id == audit.cellId) {
      const auto &cell = input.cells[static_cast<std::size_t>(audit.cellId)];
      const auto halfedgeCount = static_cast<int>(input.halfedges.size());
      const auto bridgeTwin = [&](const int id) {
        const auto &edge = input.halfedges[static_cast<std::size_t>(id)];
        return edge.twin >= 0 && edge.twin < halfedgeCount &&
               input.halfedges[static_cast<std::size_t>(edge.twin)].cell == cell.id;
      };
      std::set<int> nodes;
      int auditedNodeOccurrences = 0;
      int sameCellTwinHalfedges = 0;
      for (const int id : cell.halfedges) {
        if (id < 0 || id >= halfedgeCount) continue;
        const auto &edge = input.halfedges[static_cast<std::size_t>(id)];
        nodes.insert(edge.from);
        auditedNodeOccurrences += flag(edge.from == audit.nodeId);
        sameCellTwinHalfedges += flag(bridgeTwin(id));
      }
      std::cout << "SphereAuditedInputCell cell=" << cell.id
                << " halfedges=" << cell.halfedges.size()
                << " distinctNodes=" << nodes.size()
                << " auditedNodeOccurrences=" << auditedNodeOccurrences
                << " boundaryCycle=" << flag(cell.boundaryCycle)
                << " closed=" << flag(cell.closed) << " disk=" << flag(cell.disk)
                << " cutCellDisk=" << flag(cell.cutCellDisk)
                << " bridgeExcursion=" << flag(cell.bridgeExcursion)
                << " supportOnlyCycle=" << flag(cell.supportOnlyCycle)
                << " components=" << cell.boundaryComponentCount
                << " cycleOffsets=" << cell.boundaryCycleOffsets.size()
                << " euler=" << cell.eulerCharacteristic
                << " sameCellTwinHalfedges=" << sameCellTwinHalfedges << " region="
                << (cell.sourceTopologyRegion.has_value()
                        ? std::to_string(cell.sourceTopologyRegion->index())
                        : std::string("-"))
                << '\n';
      for (const int id : cell.halfedges) {
        if (id < 0 || id >= halfedgeCount || !bridgeTwin(id)) continue;
        const auto &edge = input.halfedges[static_cast<std::size_t>(id)];
        if (edge.twin < id) continue;
        std::cout << "SphereAuditedBridge halfedge=" << id << " twin=" << edge.twin
                  << " from=" << edge.from << " to=" << edge.to
                  << " family=" << edge.family
                  << " layoutSupport=" << flag(edge.layoutSupport)
                  << " singularitySupport=" << flag(edge.singularitySupport)
                  << " hardFeature=" << flag(edge.hardFeature)
                  << " sourceArc=" << edge.sourceArc << " curve=" << edge.curveId << '\n';
      }
    } else {
      std::cout << "SphereAuditedInputCell unavailable\n";
    }
  }
  {
    // The A4 input of each certified plan region: its walk bound to A3.
    const auto print_schedules = [](const char *label, const FixtureRun &run,
                                    bool perRegion) {
      const auto &snapshots = run.result.surfaceCellContext.productSnapshots;
      if (!snapshots.globalTopologyPlan || !snapshots.globalConformityBaseline) {
        std::cout << label << "RegionBoundarySchedules unavailable\n";
        return;
      }
      const auto built = directional::geometry::build_region_boundary_schedules(
          *snapshots.globalTopologyPlan, *snapshots.globalConformityBaseline);
      if (const auto *failure =
              std::get_if<directional::geometry::RegionBoundaryScheduleFailure>(
                  &built)) {
        std::cout << label << "RegionBoundarySchedules built=0 failure="
                  << directional::geometry::region_boundary_schedule_failure_reason_name(
                         failure->reason)
                  << " region="
                  << (failure->region ? std::to_string(failure->region->index()) : "-")
                  << " ordinal="
                  << (failure->boundaryOrdinal
                          ? std::to_string(*failure->boundaryOrdinal)
                          : "-")
                  << '\n';
        return;
      }
      const auto &schedules =
          std::get<std::vector<directional::geometry::RegionBoundarySchedule>>(built);
      std::map<std::size_t, std::vector<std::pair<bool, std::string>>> uses;
      std::size_t sides = 0U;
      for (const auto &schedule : schedules) {
        sides += schedule.sides.size();
        for (const auto &side : schedule.sides) {
          uses[side.arc.arc.index()].push_back(
              {side.arc.orientation == directional::authority::Orientation::Forward,
               side.spanCount.to_string()});
        }
      }
      std::size_t paired = 0U;
      for (const auto &[arc, occurrences] : uses) {
        (void)arc;
        if (occurrences.size() == 2U &&
            occurrences[0].first != occurrences[1].first &&
            occurrences[0].second == occurrences[1].second) {
          ++paired;
        }
      }
      std::cout << label << "RegionBoundarySchedules built=1 regions="
                << schedules.size() << " sides=" << sides
                << " arcs=" << uses.size() << " pairedArcs=" << paired
                << " otherArcs=" << uses.size() - paired << '\n';
      if (!perRegion) return;
      for (const auto &schedule : schedules) {
        std::cout << label << "RegionBoundarySchedule region="
                  << schedule.region.index() << " sides=" << schedule.sides.size()
                  << " boundaryCount=" << schedule.boundaryCount.to_string()
                  << " even="
                  << (schedule.boundaryCount % EInt(2) == EInt(0) ? 1 : 0)
                  << " counts=";
        for (const auto &side : schedule.sides) {
          std::cout << side.spanCount.to_string() << ',';
        }
        std::cout << " nodes=";
        for (const auto &side : schedule.sides) {
          std::cout << side.startNode.index() << ',';
        }
        std::cout << '\n';
      }
    };
    print_schedules("Sphere", sphere, true);
    print_schedules("Genus", genus, false);
  }
  {
    // Each trace that ends at a singularity and the separatrix class of that
    // singularity its last piece realizes.
    const auto print_arrivals = [](const char *label, const FixtureRun &run,
                                   bool perArrival) {
      const auto &snapshots = run.result.surfaceCellContext.productSnapshots;
      if (!snapshots.fieldAlignedCurveNetwork || !snapshots.fieldTransportAtlas) {
        std::cout << label << "SingularityArrivals unavailable\n";
        return;
      }
      const auto arrivals =
          directional::geometry::classify_field_aligned_singularity_arrivals(
              *snapshots.fieldAlignedCurveNetwork, *snapshots.fieldTransportAtlas);
      if (!arrivals) {
        std::cout << label << "SingularityArrivals classified=0\n";
        return;
      }
      std::size_t radialEdge = 0U;
      std::size_t matched = 0U;
      std::size_t portTraced = 0U;
      for (const auto &arrival : *arrivals) {
        if (arrival.approach ==
            directional::geometry::FieldAlignedArrivalApproach::RadialEdge) {
          ++radialEdge;
        }
        if (arrival.port) ++matched;
        if (arrival.portTraced) ++portTraced;
      }
      std::cout << label << "SingularityArrivals classified=1 arrivals="
                << arrivals->size() << " radialEdge=" << radialEdge
                << " faceInterior=" << arrivals->size() - radialEdge
                << " matched=" << matched << " portTraced=" << portTraced << '\n';
      if (!perArrival) return;
      for (const auto &arrival : *arrivals) {
        std::cout << label << "SingularityArrival trace=" << arrival.trace.index()
                  << " node=" << arrival.node.index() << " approach="
                  << directional::geometry::field_aligned_arrival_approach_name(
                         arrival.approach)
                  << " edge="
                  << (arrival.radialEdge
                          ? std::to_string(arrival.radialEdge->first().index()) +
                                "-" +
                                std::to_string(arrival.radialEdge->second().index())
                          : std::string("-"))
                  << " port="
                  << (arrival.port ? std::to_string(arrival.port->index())
                                   : std::string("-"))
                  << " portTraced=" << (arrival.portTraced ? 1 : 0) << '\n';
      }
    };
    print_arrivals("Sphere", sphere, true);
    print_arrivals("Genus", genus, false);
  }
  {
    // The corners of each region boundary from the field's turning at its walk
    // nodes, and the schedule sides between them.
    const auto print_corner_sides = [](const char *label, const FixtureRun &run,
                                       bool perRegion) {
      const auto &snapshots = run.result.surfaceCellContext.productSnapshots;
      if (!snapshots.fieldAlignedCurveNetwork || !snapshots.globalTopologyPlan ||
          !snapshots.globalConformityBaseline) {
        std::cout << label << "RegionCornerSides unavailable\n";
        return;
      }
      const auto schedules = directional::geometry::build_region_boundary_schedules(
          *snapshots.globalTopologyPlan, *snapshots.globalConformityBaseline);
      const auto *bound =
          std::get_if<std::vector<directional::geometry::RegionBoundarySchedule>>(
              &schedules);
      if (bound == nullptr) {
        std::cout << label << "RegionCornerSides unavailable\n";
        return;
      }
      const auto built = directional::geometry::build_region_corner_sides(
          *snapshots.globalTopologyPlan, *snapshots.fieldAlignedCurveNetwork, *bound);
      if (const auto *failure =
              std::get_if<directional::geometry::RegionCornerSidesFailure>(&built)) {
        std::cout << label << "RegionCornerSides built=0 failure="
                  << directional::geometry::region_corner_sides_failure_reason_name(
                         failure->reason)
                  << '\n';
        return;
      }
      const auto &regions =
          std::get<std::vector<directional::geometry::RegionCornerSides>>(built);
      std::size_t corners = 0U;
      std::size_t sides = 0U;
      for (const auto &region : regions) {
        corners += region.corners.size();
        sides += region.sides.size();
      }
      std::cout << label << "RegionCornerSides built=1 regions=" << regions.size()
                << " corners=" << corners << " sides=" << sides << '\n';
      if (!perRegion) return;
      for (const auto &region : regions) {
        std::cout << label << "RegionCornerSide region=" << region.region.index()
                  << " corners=";
        for (std::size_t index = 0U; index < region.corners.size(); ++index) {
          std::cout << (index == 0U ? "" : ";") << region.corners[index].node.index()
                    << ',' << region.corners[index].quarterTurns;
        }
        std::cout << " sides=";
        for (std::size_t index = 0U; index < region.sides.size(); ++index) {
          std::cout << (index == 0U ? "" : ",") << region.sides[index].count.to_string();
        }
        std::cout << '\n';
      }
    };
    print_corner_sides("Sphere", sphere, true);
    print_corner_sides("Genus", genus, false);
  }
  const auto sphereDisplay = display_of(sphere);
  for (const auto *face : {&sphereLocus.sourceFace, &sphereLocus.relatedSourceFace,
                          &sphereLocus.edgeTraceFaceCorners}) {
    if (!face->has_value()) continue;
    const Eigen::Index row = face_row_of(sphere.mesh.F, **face);
    ASSERT_GE(row, 0);
    EXPECT_TRUE(has_face(sphereDisplay, sphere.mesh.V, sphere.mesh.F, row));
  }
  for (const auto *edge : {&sphereLocus.sourceEdge, &sphereLocus.traceIncomingCarrier,
                          &sphereLocus.traceOutgoingCarrier, &sphereLocus.edgeTraceOtherCarrier}) {
    if (!edge->has_value()) continue;
    const auto &e = **edge;
    EXPECT_TRUE(has_edge(sphereDisplay, sphere.mesh.V, e[0], e[1]));
  }
  if (sphereLocus.sourceVertex.has_value()) {
    const auto v = *sphereLocus.sourceVertex;
    EXPECT_TRUE(has_vertex(sphereDisplay,
                           sphere.mesh.V.row(static_cast<Eigen::Index>(v))));
  }
  // Completion can reject without naming a source entity. In that case the
  // display must report the stop in text, not invent a geometric location.
  const auto &sphereContext = sphere.result.surfaceCellContext;
  const bool hasSourceLocus =
      sphereLocus.sourceFace || sphereLocus.relatedSourceFace ||
      sphereLocus.edgeTraceFaceCorners || sphereLocus.sourceEdge ||
      sphereLocus.traceIncomingCarrier || sphereLocus.traceOutgoingCarrier ||
      sphereLocus.edgeTraceOtherCarrier || sphereLocus.sourceVertex;
  const bool hasPhaseFrontRejection =
      sphereContext.hasTraceNetwork &&
      sphereContext.productSnapshots.traceNetwork.phaseFront.rejection() != nullptr;
  if (!hasSourceLocus && !hasPhaseFrontRejection &&
      sphereDiagnostics.terminalFailureStage == "completion" &&
      sphereDiagnostics.terminalFailureCode == "NotProductionReady") {
    EXPECT_FALSE(sphereDisplay.has_stop_location());
    EXPECT_EQ(0, sphereDisplay.stopFaces.rows());
    EXPECT_EQ(0, sphereDisplay.stopEdges.rows());
    EXPECT_EQ(0, sphereDisplay.stopVertices.rows());
  } else {
    EXPECT_TRUE(sphereDisplay.has_stop_location());
  }
  for (const auto &note : {"stage: " + sphereDiagnostics.terminalFailureStage,
                           "code: " + sphereDiagnostics.terminalFailureCode}) {
    EXPECT_NE(sphereDisplay.stopNotes.end(),
              std::find(sphereDisplay.stopNotes.begin(), sphereDisplay.stopNotes.end(), note));
  }
  EXPECT_FALSE(sphere.result.is_produced());
  EXPECT_EQ(0U, sphereDisplay.cellCount);
  for (const auto *display : {&genusDisplay, &singularDisplay}) {
    EXPECT_TRUE(display->has_stop_location());
    EXPECT_EQ(0U, display->cellCount);
  }
}

TEST(SurfaceCellTracingDisplay, RequestedStopShowsTracedCells) {
  // A flat 2 x 2 square grid with a constant cross field traces quickly.
  Eigen::MatrixXd V(9, 3);
  for (int y = 0, vertex = 0; y < 3; ++y) {
    for (int x = 0; x < 3; ++x) V.row(vertex++) << x, y, 0.0;
  }
  Eigen::MatrixXi F(8, 3);
  for (int y = 0, face = 0; y < 2; ++y) {
    for (int x = 0; x < 2; ++x) {
      const int lowerLeft = 3 * y + x;
      F.row(face++) << lowerLeft, lowerLeft + 1, lowerLeft + 4;
      F.row(face++) << lowerLeft, lowerLeft + 4, lowerLeft + 3;
    }
  }
  Eigen::MatrixXd raw(F.rows(), 12);
  for (Eigen::Index face = 0; face < F.rows(); ++face) {
    raw.row(face) << 1, 0, 0, 0, 1, 0, -1, 0, 0, 0, -1, 0;
  }
  auto options = surface_cell_options(3);
  options.lengthRatio = 0.2;
  const auto result =
      directional::pipeline::remesh_from_raw_cross_field(V, F, raw, options);
  ASSERT_EQ("InjectedStageFailure", result.diagnostics.terminalFailureCode)
      << result.diagnostics.terminalFailureStage;
  const auto &network = result.surfaceCellContext.productSnapshots.traceNetwork;
  const auto *product = network.phaseFront.produced_product();
  ASSERT_NE(nullptr, product);

  const auto display = directional::visualization::surface_cell_tracing_display(
      V, F, result.diagnostics, &network);
  EXPECT_FALSE(display.has_stop_location());  // a requested stop names no place
  EXPECT_EQ(product->cells().size(), display.cellCount);
  ASSERT_GT(display.cellCount, 0U);

  // Independent reconstruction of every boundary segment, in cell order.
  Eigen::Index row = 0;
  for (const auto &cell : product->cells()) {
    for (const auto &path : cell.boundaryPaths) {
      for (const auto &segment : path) {
        ASSERT_LT(row, display.cellEdges.rows());
        Eigen::RowVector3d start = Eigen::RowVector3d::Zero();
        Eigen::RowVector3d end = Eigen::RowVector3d::Zero();
        for (int corner = 0; corner < 3; ++corner) {
          start += segment.startBarycentric(corner) * V.row(F(segment.face, corner));
          end += segment.endBarycentric(corner) * V.row(F(segment.face, corner));
        }
        EXPECT_LE((display.cellPoints.row(display.cellEdges(row, 0)) - start).norm(), 1e-12);
        EXPECT_LE((display.cellPoints.row(display.cellEdges(row, 1)) - end).norm(), 1e-12);
        ++row;
      }
    }
  }
  EXPECT_EQ(row, display.cellEdges.rows());

  // Every traced point lies on the flat square.
  for (const auto *points : {&display.cellPoints, &display.cellCorners}) {
    ASSERT_GT(points->rows(), 0);
    EXPECT_LE(points->col(2).cwiseAbs().maxCoeff(), 1e-12);
    EXPECT_GE(points->leftCols(2).minCoeff(), -1e-9);
    EXPECT_LE(points->leftCols(2).maxCoeff(), 2.0 + 1e-9);
  }
  RecordProperty("cells", static_cast<int>(display.cellCount));
}

TEST(SurfaceCellTracingDisplay, RejectsMalformedMatrices) {
  const directional::RemeshDiagnostics diagnostics;
  EXPECT_THROW(directional::visualization::surface_cell_tracing_display(
                   Eigen::MatrixXd(3, 2), Eigen::MatrixXi(1, 3), diagnostics, nullptr),
               std::invalid_argument);
  EXPECT_THROW(directional::visualization::surface_cell_tracing_display(
                   Eigen::MatrixXd(3, 3), Eigen::MatrixXi(1, 4), diagnostics, nullptr),
               std::invalid_argument);
}

TEST(SurfaceCellTracingDisplay, TerminalFaceLocusIsShownByItsCorners) {
  Eigen::MatrixXd V(4, 3);
  V << 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0;
  Eigen::MatrixXi F(2, 3);
  F << 0, 1, 2, 0, 2, 3;
  directional::RemeshDiagnostics diagnostics;
  diagnostics.terminalFailureStage = "surface-cut-graph";
  diagnostics.terminalFailureCode = "CutSearchExhaustedBeforeCellularity";
  diagnostics.terminalFailureLocus.sourceFace = std::array<std::size_t, 3>{3, 0, 2};

  const auto display =
      directional::visualization::surface_cell_tracing_display(V, F, diagnostics, nullptr);
  EXPECT_TRUE(display.has_stop_location());
  ASSERT_EQ(1, display.stopFaces.rows());
  EXPECT_TRUE(has_face(display, V, F, 1));
  EXPECT_FALSE(has_face(display, V, F, 0));
  EXPECT_EQ(0, display.stopEdges.rows());
  EXPECT_EQ(0, display.stopVertices.rows());
  EXPECT_TRUE(std::any_of(display.stopNotes.begin(), display.stopNotes.end(),
                          [](const std::string &note) {
                            return note == "code: CutSearchExhaustedBeforeCellularity";
                          }));
}

namespace {

const FixtureRun &prescribed_sphere_run() {
  static const FixtureRun run = run_fixture("sphere_prescribed");
  return run;
}

} // namespace

// Every region of the prescribed sphere's production plan turns through four
// one-quarter-turn corners, and the corners delimit the sides measured from
// its A3 schedule. A T-node is flat where one trace continues through it.
TEST(RegionCornerSides, PrescribedSphereRegionsTurnAtFourQuarterTurnCorners) {
  const auto &snapshots =
      prescribed_sphere_run().result.surfaceCellContext.productSnapshots;
  ASSERT_TRUE(snapshots.fieldAlignedCurveNetwork.has_value());
  ASSERT_TRUE(snapshots.globalTopologyPlan.has_value());
  ASSERT_TRUE(snapshots.globalConformityBaseline.has_value());
  const auto schedules = directional::geometry::build_region_boundary_schedules(
      *snapshots.globalTopologyPlan, *snapshots.globalConformityBaseline);
  const auto *bound =
      std::get_if<std::vector<directional::geometry::RegionBoundarySchedule>>(
          &schedules);
  ASSERT_NE(nullptr, bound);
  const auto built = directional::geometry::build_region_corner_sides(
      *snapshots.globalTopologyPlan, *snapshots.fieldAlignedCurveNetwork, *bound);
  const auto *regions =
      std::get_if<std::vector<directional::geometry::RegionCornerSides>>(&built);
  ASSERT_NE(nullptr, regions)
      << directional::geometry::region_corner_sides_failure_reason_name(
             std::get<directional::geometry::RegionCornerSidesFailure>(built)
                 .reason);

  struct Expected {
    std::vector<std::size_t> corners;
    std::vector<std::size_t> sides;
    std::set<std::size_t> flat;
  };
  const std::map<std::size_t, Expected> expected{
      {0U, {{8U, 0U, 4U, 5U}, {30U, 35U, 35U, 32U}, {}}},
      {1U, {{0U, 1U, 3U, 2U}, {31U, 35U, 35U, 31U}, {8U, 9U}}},
      {2U, {{1U, 8U, 5U, 10U}, {1U, 32U, 1U, 32U}, {}}},
      {3U, {{0U, 9U, 6U, 4U}, {30U, 32U, 35U, 35U}, {}}},
      {4U, {{9U, 2U, 11U, 6U}, {1U, 32U, 1U, 32U}, {}}},
      {5U, {{1U, 10U, 7U, 3U}, {32U, 30U, 35U, 35U}, {}}},
      {6U, {{11U, 2U, 3U, 7U}, {32U, 35U, 35U, 30U}, {}}},
      {7U, {{4U, 6U, 7U, 5U}, {35U, 31U, 31U, 35U}, {10U, 11U}}}};
  ASSERT_EQ(bound->size(), regions->size());
  ASSERT_EQ(expected.size(), regions->size());
  for (std::size_t index = 0U; index < regions->size(); ++index) {
    const auto &region = (*regions)[index];
    const auto &schedule = (*bound)[index];
    SCOPED_TRACE(::testing::Message() << "region=" << region.region.index());
    ASSERT_EQ(schedule.region, region.region);
    const auto found = expected.find(region.region.index());
    ASSERT_NE(expected.end(), found);
    const Expected &want = found->second;
    ASSERT_EQ(want.corners.size(), region.corners.size());
    ASSERT_EQ(want.sides.size(), region.sides.size());
    std::set<std::size_t> flat;
    for (const auto &side : schedule.sides) flat.insert(side.startNode.index());
    std::size_t covered = 0U;
    for (std::size_t k = 0U; k < region.corners.size(); ++k) {
      const auto &corner = region.corners[k];
      EXPECT_EQ(want.corners[k], corner.node.index());
      EXPECT_EQ(1, corner.quarterTurns);
      ASSERT_LT(corner.scheduleSide, schedule.sides.size());
      EXPECT_EQ(corner.node, schedule.sides[corner.scheduleSide].startNode);
      flat.erase(corner.node.index());
      const auto &side = region.sides[k];
      EXPECT_EQ(corner.scheduleSide, side.firstScheduleSide);
      EXPECT_EQ(std::to_string(want.sides[k]), side.count.to_string());
      covered += side.scheduleSideCount;
    }
    EXPECT_EQ(schedule.sides.size(), covered);
    EXPECT_EQ(want.flat, flat);
  }
}

// A walk run backwards keeps its arcs and nodes but puts the region on the
// other side: each one-quarter-turn singular corner reads as the remaining
// two of its node's three sectors, so the region does not turn by four
// quarter turns.
TEST(RegionCornerSides, ReversedPrescribedSphereWalkIsRejectedByItsTurning) {
  using directional::geometry::RegionCornerSidesFailure;
  using directional::geometry::RegionCornerSidesFailureReason;
  const auto &snapshots =
      prescribed_sphere_run().result.surfaceCellContext.productSnapshots;
  ASSERT_TRUE(snapshots.fieldAlignedCurveNetwork.has_value());
  ASSERT_TRUE(snapshots.globalTopologyPlan.has_value());
  ASSERT_TRUE(snapshots.globalConformityBaseline.has_value());
  const auto schedules = directional::geometry::build_region_boundary_schedules(
      *snapshots.globalTopologyPlan, *snapshots.globalConformityBaseline);
  const auto *bound =
      std::get_if<std::vector<directional::geometry::RegionBoundarySchedule>>(
          &schedules);
  ASSERT_NE(nullptr, bound);
  ASSERT_FALSE(bound->empty());
  ASSERT_TRUE(std::holds_alternative<
              std::vector<directional::geometry::RegionCornerSides>>(
      directional::geometry::build_region_corner_sides(
          *snapshots.globalTopologyPlan, *snapshots.fieldAlignedCurveNetwork,
          *bound)));

  auto reversed = *bound;
  auto &walk = reversed.front().sides;
  std::reverse(walk.begin(), walk.end());
  for (auto &side : walk) {
    side.arc.orientation =
        side.arc.orientation == directional::authority::Orientation::Forward
            ? directional::authority::Orientation::Reverse
            : directional::authority::Orientation::Forward;
    std::swap(side.startNode, side.endNode);
  }
  const auto built = directional::geometry::build_region_corner_sides(
      *snapshots.globalTopologyPlan, *snapshots.fieldAlignedCurveNetwork,
      reversed);
  const auto *failure = std::get_if<RegionCornerSidesFailure>(&built);
  ASSERT_NE(nullptr, failure);
  EXPECT_EQ(RegionCornerSidesFailureReason::TurningNotFourQuarterTurns,
            failure->reason);
  ASSERT_TRUE(failure->region.has_value());
  EXPECT_EQ(reversed.front().region, *failure->region);
  EXPECT_FALSE(failure->scheduleSide.has_value());
}
