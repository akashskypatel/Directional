// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/geometry/GlobalTopologyPlan.h>

#include "SourceFaceComponentPartition.h"
#include "CertifiedSourceFaceOwnerConsistency.h"
#include "EmbeddedGraphTopology.h"

#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <map>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>
#include <variant>

namespace directional::geometry::global_topology_plan_detail {
namespace {

constexpr std::uint64_t kFnvOffset = 1469598103934665603ULL;
constexpr std::uint64_t kFnvPrime = 1099511628211ULL;
constexpr std::size_t kFragmentFailureEvidenceLimit = 8U;
constexpr std::size_t kFragmentFaceEvidenceLimit = 4096U;
constexpr std::size_t kFragmentOwnerCensusEvidenceLimit = 64U;
constexpr std::size_t kUncutComponentBoundaryEvidenceLimit = 64U;
constexpr std::size_t kUncutComponentSeedEvidenceLimit = 64U;

void hash_consume(std::uint64_t &hash, const std::uint64_t value) noexcept {
  hash ^= value;
  hash *= kFnvPrime;
}

template <typename Id>
void hash_id(std::uint64_t &hash, const Id id) noexcept {
  hash_consume(hash, static_cast<std::uint64_t>(Id::domain()));
  hash_consume(hash, id.index());
}

void hash_edge(std::uint64_t &hash,
               const authority::SourceEdgeTopologyKey &edge) noexcept {
  hash_id(hash, edge.first());
  hash_id(hash, edge.second());
}

void hash_face(std::uint64_t &hash,
               const authority::SourceFaceTopologyKey &face) noexcept {
  for (const authority::SourceVertexId vertex : face.vertices()) {
    hash_id(hash, vertex);
  }
}

template <typename Id>
Id make_id(const std::size_t index, const std::size_t extent) {
  return Id::from_index(static_cast<std::int64_t>(index), extent).value();
}

GlobalTopologyPlanError error(const GlobalTopologyPlanErrorCode code) {
  GlobalTopologyPlanError result;
  result.code = code;
  return result;
}

GlobalTopologyPlanError rotation_error(
    const RotationSystemInconsistencyReason reason) {
  GlobalTopologyPlanError result =
      error(GlobalTopologyPlanErrorCode::RotationSystemInconsistent);
  result.rotationSystemInconsistencyReason = reason;
  return result;
}

bool fragment_diagnostics_enabled() noexcept {
  const char *value = std::getenv("DIRECTIONAL_CP4AB_FRAGMENT_DIAGNOSTICS");
  return value != nullptr && std::strcmp(value, "1") == 0;
}

std::string diagnostic_face(
    const authority::SourceFaceTopologyKey &face) {
  std::ostringstream out;
  out << '[';
  for (std::size_t index = 0U; index < face.vertices().size(); ++index) {
    if (index != 0U) out << ',';
    out << face.vertices()[index].index();
  }
  out << ']';
  return out.str();
}

std::string diagnostic_edge(
    const authority::SourceEdgeTopologyKey &edge) {
  std::ostringstream out;
  out << '(' << edge.first().index() << ',' << edge.second().index() << ')';
  return out.str();
}

template <typename Value>
std::string diagnostic_values(const std::set<Value> &values) {
  std::ostringstream out;
  out << '[';
  bool first = true;
  for (const auto value : values) {
    if (!first) out << ',';
    first = false;
    if constexpr (std::is_integral_v<Value>) {
      out << value;
    } else {
      out << value.index();
    }
  }
  out << ']';
  return out.str();
}

struct FragmentDiagnosticTraceSegment {
  authority::TraceId trace;
  authority::NetworkArcId arc;
  std::size_t segment = 0U;
  std::size_t forwardOrbit = 0U;
  std::size_t reverseOrbit = 0U;
  authority::SourceFaceTopologyKey sourceFace;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
  authority::SourceEdgeTopologyKey outgoingCarrier;
  std::optional<authority::SourceVertexId> sourcePortVertex;
};

struct FragmentDiagnosticEvidence {
  std::set<std::size_t> exteriorOrbits;
  std::map<authority::SourceFaceTopologyKey, std::set<std::size_t>>
      fragmentOrbits;
  std::map<authority::SourceFaceTopologyKey, std::size_t> tracePieceCount;
  std::map<std::pair<authority::SourceFaceTopologyKey,
                    authority::SourceEdgeTopologyKey>,
           std::set<std::size_t>>
      edgeOrbitEvidence;
  std::vector<FragmentDiagnosticTraceSegment> traceSegments;
};

using FragmentExactPoint = std::array<authority::FieldExactRational, 3>;

struct FragmentLocalTraceChord {
  TraceCutFaceFragmentIncidenceDiagnostic incidence;
  std::optional<FragmentExactPoint> first;
  std::optional<FragmentExactPoint> second;
};

struct FragmentLocalArrangement {
  std::optional<std::size_t> fragmentCount;
  bool chordsCrossInside = false;
  bool evaluated = true;
};

[[nodiscard]] std::optional<FragmentExactPoint> boundary_point_barycentric(
    const embedded_graph_topology_detail::SourceFaceRecord &face,
    const authority::FieldBoundaryPoint &point) {
  std::optional<std::size_t> firstCorner;
  std::optional<std::size_t> secondCorner;
  for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
    if (face.vertices[corner] == point.edge.first()) firstCorner = corner;
    if (face.vertices[corner] == point.edge.second()) secondCorner = corner;
  }
  if (!firstCorner.has_value() || !secondCorner.has_value() ||
      !point.parameter.in_unit_interval()) {
    return std::nullopt;
  }
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto one = authority::FieldExactRational::from_integer(1);
  FragmentExactPoint result{zero, zero, zero};
  result[*firstCorner] = one - point.parameter.value;
  result[*secondCorner] = point.parameter.value;
  return result;
}

[[nodiscard]] std::optional<FragmentExactPoint> source_vertex_barycentric(
    const embedded_graph_topology_detail::SourceFaceRecord &face,
    const authority::SourceVertexId vertex) {
  const auto zero = authority::FieldExactRational::from_integer(0);
  const auto one = authority::FieldExactRational::from_integer(1);
  FragmentExactPoint result{zero, zero, zero};
  for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
    if (face.vertices[corner] == vertex) {
      result[corner] = one;
      return result;
    }
  }
  return std::nullopt;
}

[[nodiscard]] std::optional<FragmentExactPoint> trace_segment_exit_barycentric(
    const embedded_graph_topology_detail::SourceFaceRecord &face,
    const FieldAlignedCandidateTrace &trace, const std::size_t segmentIndex) {
  if (segmentIndex >= trace.segments.size()) return std::nullopt;
  const auto &segment = trace.segments[segmentIndex];
  if (segment.edgeTransitExit.has_value()) {
    return boundary_point_barycentric(face, *segment.edgeTransitExit);
  }
  if (segmentIndex + 1U < trace.segments.size()) {
    const auto support = trace.segments[segmentIndex + 1U].entryPoint.source_support();
    if (support.has_value()) {
      if (const auto *vertex =
              std::get_if<authority::SourceVertexSupport>(&*support)) {
        if (const auto point = source_vertex_barycentric(face, vertex->vertex);
            point.has_value()) {
          return point;
        }
      }
    }
  }
  if (trace.terminalContact.has_value() &&
      trace.terminalContact->sourceFace == segment.sourceFace) {
    return trace.terminalContact->barycentric;
  }
  if (trace.terminalPoint.has_value()) {
    return boundary_point_barycentric(face, *trace.terminalPoint);
  }
  return std::nullopt;
}

[[nodiscard]] bool point_strictly_inside_face(
    const FragmentExactPoint &point) {
  const auto zero = authority::FieldExactRational::from_integer(0);
  return point[0] > zero && point[1] > zero && point[2] > zero;
}

[[nodiscard]] FragmentLocalArrangement local_fragment_arrangement(
    const std::vector<FragmentLocalTraceChord> &chords) {
  using ContactKind =
      surface_cell_tracing_detail::FieldAlignedSegmentContactKind;
  FragmentLocalArrangement result;
  std::size_t fragmentCount = 1U;

  // Insert each exact boundary-to-boundary chord into the local triangle.
  // A new chord creates one region plus one for every distinct pre-existing
  // interior crossing it traverses. Collinear/unevaluated contacts make only
  // this observational census unavailable; they never alter product control.
  for (std::size_t chordIndex = 0U; chordIndex < chords.size(); ++chordIndex) {
    const auto &chord = chords[chordIndex];
    if (!chord.first.has_value() || !chord.second.has_value() ||
        *chord.first == *chord.second) {
      result.evaluated = false;
      return result;
    }
    std::set<FragmentExactPoint> interiorCrossings;
    for (std::size_t prior = 0U; prior < chordIndex; ++prior) {
      if (!chords[prior].first.has_value() ||
          !chords[prior].second.has_value()) {
        result.evaluated = false;
        return result;
      }
      const auto contact =
          surface_cell_tracing_detail::classify_field_aligned_barycentric_contact(
              *chord.first, *chord.second, *chords[prior].first,
              *chords[prior].second);
      if (contact.kind == ContactKind::CollinearOverlap ||
          contact.kind == ContactKind::Unevaluated) {
        result.evaluated = false;
        return result;
      }
      if (contact.kind == ContactKind::ProperCrossing &&
          contact.barycentric.has_value() &&
          point_strictly_inside_face(*contact.barycentric)) {
        interiorCrossings.insert(*contact.barycentric);
        result.chordsCrossInside = true;
      }
    }
    fragmentCount += 1U + interiorCrossings.size();
  }
  result.fragmentCount = fragmentCount;
  return result;
}

[[nodiscard]] bool is_terminal_slit(
    const FieldAlignedCandidateTrace &trace,
    const std::size_t segmentIndex) noexcept {
  return !trace.terminalBarrier.has_value() &&
         segmentIndex + 1U == trace.segments.size();
}

[[nodiscard]] std::optional<authority::SourceSupport> trace_segment_exit_support(
    const FieldAlignedCandidateTrace &trace, const std::size_t segmentIndex) {
  if (segmentIndex >= trace.segments.size()) return std::nullopt;
  const auto &segment = trace.segments[segmentIndex];
  if (segment.edgeTransitExit.has_value()) {
    return segment.edgeTransitExit->source_support();
  }
  if (segmentIndex + 1U == trace.segments.size() &&
      trace.terminalPoint.has_value()) {
    return trace.terminalPoint->source_support();
  }
  return std::nullopt;
}

struct CarrierlessCornerBinding {
  std::size_t sourceCorner = 0U;
  authority::SourceVertexId boundCorner;
  TraceCornerBindingProvenance provenance =
      TraceCornerBindingProvenance::SegmentEntrySupport;
};

[[nodiscard]] std::optional<CarrierlessCornerBinding>
resolve_carrierless_corner_binding(
    const embedded_graph_topology_detail::SourceFaceRecord &face,
    const FieldAlignedCandidateTrace &trace,
    const std::size_t segmentIndex,
    const FieldAlignedCandidateTraceSegment &segment) {
  const auto entrySupport = segment.entryPoint.source_support();
  if (!entrySupport.has_value()) return std::nullopt;
  const auto *entryVertex =
      std::get_if<authority::SourceVertexSupport>(&*entrySupport);
  if (entryVertex == nullptr) return std::nullopt;

  const bool firstSegment = segmentIndex == 0U;
  if (firstSegment && entryVertex->vertex != trace.sourceVertex) {
    return std::nullopt;
  }

  std::optional<std::size_t> sourceCorner;
  for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
    if (face.vertices[corner] == entryVertex->vertex) {
      sourceCorner = corner;
      break;
    }
  }
  if (!sourceCorner.has_value()) return std::nullopt;

  return CarrierlessCornerBinding{
      *sourceCorner, entryVertex->vertex,
      firstSegment ? TraceCornerBindingProvenance::TraceOrigin
                   : TraceCornerBindingProvenance::SegmentEntrySupport};
}

void annotate_trace_segment_incidence(
    GlobalTopologyPlanError &failure, const GlobalTopologyArc &arc,
    const FieldAlignedCandidateTrace &trace, const std::size_t segmentIndex,
    const FieldAlignedCandidateTraceSegment &segment,
    const std::optional<CarrierlessCornerBinding> &binding = std::nullopt) {
  // Segment indices always traverse the candidate trace in its forward
  // direction, independently of which face-walk side owns a resulting orbit.
  failure.arc = arc.id;
  failure.trace = trace.id;
  failure.singularity = trace.singularity;
  failure.sourceVertex = trace.sourceVertex;
  failure.traceSourcePort = trace.port;
  failure.traceSegmentOrientation = authority::Orientation::Forward;
  failure.traceFirstSegment = arc.firstSegment;
  failure.traceOnePastLastSegment = arc.onePastLastSegment;
  failure.traceSegmentIndex = segmentIndex;
  failure.traceSegmentIsFirst = segmentIndex == 0U;
  failure.traceIncomingCarrier = segment.incomingCarrier;
  failure.traceOutgoingCarrier = segment.outgoingCarrier;
  failure.traceEntrySupport = segment.entryPoint.source_support();
  failure.traceExitSupport = trace_segment_exit_support(trace, segmentIndex);
  if (binding.has_value()) {
    failure.traceBoundCorner = binding->boundCorner;
    failure.traceBoundCornerProvenance = binding->provenance;
  }
}

// Actual embedded-graph arc/rotation/orbit construction is owned by
// EmbeddedGraphTopology.cpp and consumed here as the single pre-region authority.
using namespace embedded_graph_topology_detail;
std::optional<std::size_t> region_orbit(
    const GlobalTopologyRegion &region, const FaceWalkResult &walk) {
  std::optional<std::size_t> result;
  for (std::size_t orbit = 0U; orbit < walk.orbits.size(); ++orbit) {
    if (walk.orbits[orbit] != region.boundary) continue;
    if (result.has_value()) return std::nullopt;
    result = orbit;
  }
  return result;
}

std::vector<std::size_t> mandatory_arc_indices(
    const std::vector<GlobalTopologyArc> &arcs,
    const authority::NetworkEdgeId edge) {
  std::vector<std::size_t> result;
  for (std::size_t index = 0U; index < arcs.size(); ++index) {
    if (arcs[index].kind == GlobalTopologyArcKind::Mandatory &&
        arcs[index].mandatoryEdge == edge) {
      result.push_back(index);
    }
  }
  return result;
}

using FragmentCornerIncidence =
    std::map<authority::SourceFaceTopologyKey,
             std::map<std::size_t, std::set<authority::SourceVertexId>>>;
using FragmentCornerBuildResult =
    std::variant<FragmentCornerIncidence, GlobalTopologyPlanError>;

FragmentCornerBuildResult build_fragment_corner_incidence(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const std::vector<GlobalTopologyArc> &arcs,
    const FaceWalkResult &walk) {
  struct RayCut {
    int ordinal = 0;
    std::size_t forwardOrbit = 0U;
    std::size_t reverseOrbit = 0U;
    std::size_t sourceCorner = 0U;
  };

  FragmentCornerIncidence result;
  std::map<authority::SourceFaceTopologyKey, bool> hasFullChord;
  std::map<authority::SourceFaceTopologyKey, std::vector<RayCut>> raysByFace;

  for (const GlobalTopologyArc &arc : arcs) {
    if (arc.kind != GlobalTopologyArcKind::Trace || !arc.trace.has_value()) {
      continue;
    }
    const FieldAlignedCandidateTrace *trace = find_trace(network, *arc.trace);
    if (trace == nullptr || arc.firstSegment >= arc.onePastLastSegment ||
        arc.onePastLastSegment > trace->segments.size()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.arc = arc.id;
      return failure;
    }
    const auto port = std::find_if(
        network.singularity_ports().begin(), network.singularity_ports().end(),
        [&](const auto &candidate) { return candidate.id == trace->port; });
    if (port == network.singularity_ports().end() || port->ordinal < 0 ||
        port->sourceVertex != trace->sourceVertex) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
      failure.arc = arc.id;
      failure.singularity = trace->singularity;
      return failure;
    }
    const std::size_t forwardDart = dart_index(
        GlobalTopologyOrientedArc{arc.id, authority::Orientation::Forward});
    const std::size_t reverseDart = dart_index(
        GlobalTopologyOrientedArc{arc.id, authority::Orientation::Reverse});
    if (forwardDart >= walk.orbitByDart.size() ||
        reverseDart >= walk.orbitByDart.size()) {
      return rotation_error(forwardDart >= walk.orbitByDart.size() ? RotationSystemInconsistencyReason::FragmentCornerForwardDartOutOfRange : RotationSystemInconsistencyReason::FragmentCornerReverseDartOutOfRange);
    }
    const std::size_t forwardOrbit = walk.orbitByDart[forwardDart];
    const std::size_t reverseOrbit = walk.orbitByDart[reverseDart];

    for (std::size_t segmentIndex = arc.firstSegment;
         segmentIndex < arc.onePastLastSegment; ++segmentIndex) {
      const FieldAlignedCandidateTraceSegment &segment =
          trace->segments[segmentIndex];
      const auto faceIt = topology.faces.find(segment.sourceFace);
      if (faceIt == topology.faces.end()) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        failure.arc = arc.id;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }
      if (is_terminal_slit(*trace, segmentIndex)) {
        // The retained outgoing carrier is only a hypothetical continuation.
        // A terminal slit is not a real face chord and contributes no fragment
        // separation. build_regions() applies the same predicate before any
        // fragment count, touched-edge, or orbit-evidence mutation.
        continue;
      }
      // FragmentCornerIncidence is an ownership map keyed by certified face
      // orbit, not a fragment identity. When both dart sides share one orbit,
      // the full-chord writes below intentionally merge all face corners into
      // that single owner's entry (DEFN-R4.1/R4.2).
      const SourceFaceRecord &face = faceIt->second;
      if (segment.incomingCarrier.has_value()) {
        if (hasFullChord[segment.sourceFace] ||
            !raysByFace[segment.sourceFace].empty()) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::SourceFaceCarriesMultipleTraceCuts);
          failure.arc = arc.id;
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const auto incoming =
            local_edge_index(face, *segment.incomingCarrier);
        const auto outgoing = local_edge_index(face, segment.outgoingCarrier);
        if (!incoming.has_value() || !outgoing.has_value() ||
            *incoming == *outgoing) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::TraceSegmentCarriersCoincide);
          failure.arc = arc.id;
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const std::size_t turn = (*outgoing + 3U - *incoming) % 3U;
        if (turn != 1U && turn != 2U) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::TraceSegmentTurnNotAdmissible);
          failure.arc = arc.id;
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        std::optional<std::size_t> sharedCorner;
        for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
          const authority::SourceVertexId vertex = face.vertices[corner];
          const bool onIncoming =
              vertex == segment.incomingCarrier->first() ||
              vertex == segment.incomingCarrier->second();
          const bool onOutgoing =
              vertex == segment.outgoingCarrier.first() ||
              vertex == segment.outgoingCarrier.second();
          if (onIncoming && onOutgoing) {
            if (sharedCorner.has_value()) {
              GlobalTopologyPlanError failure = error(
                  GlobalTopologyPlanErrorCode::TraceSegmentCarriersShareMultipleCorners);
              failure.arc = arc.id;
              failure.sourceFace = segment.sourceFace;
              return failure;
            }
            sharedCorner = corner;
          }
        }
        if (!sharedCorner.has_value()) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::TraceSegmentCarriersShareNoCorner);
          failure.arc = arc.id;
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const std::size_t sideOrbit =
            turn == 1U ? forwardOrbit : reverseOrbit;
        const std::size_t cornerOrbit =
            sideOrbit == forwardOrbit ? reverseOrbit : forwardOrbit;
        result[segment.sourceFace][cornerOrbit].insert(
            face.vertices[*sharedCorner]);
        for (std::size_t corner = 0U; corner < face.vertices.size(); ++corner) {
          if (corner != *sharedCorner) {
            result[segment.sourceFace][sideOrbit].insert(face.vertices[corner]);
          }
        }
        hasFullChord[segment.sourceFace] = true;
        continue;
      }

      if (hasFullChord[segment.sourceFace]) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::SourcePortFaceAlreadyCarriesTraceChord);
        failure.arc = arc.id;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }
      const auto binding = resolve_carrierless_corner_binding(
          face, *trace, segmentIndex, segment);
      const auto outgoing = local_edge_index(face, segment.outgoingCarrier);
      if (!binding.has_value() || !outgoing.has_value() ||
          *outgoing != (binding->sourceCorner + 1U) % 3U) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::TraceSourcePortCarrierNotAdmissible);
        failure.sourceFace = segment.sourceFace;
        annotate_trace_segment_incidence(failure, arc, *trace, segmentIndex,
                                         segment, binding);
        return failure;
      }
      raysByFace[segment.sourceFace].push_back(
          RayCut{port->ordinal, forwardOrbit, reverseOrbit,
                 binding->sourceCorner});
    }
  }

  for (auto &[faceKey, rays] : raysByFace) {
    if (rays.empty()) continue;
    if (hasFullChord[faceKey]) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::SourceFaceCarriesTraceChordAndRays);
      failure.sourceFace = faceKey;
      return failure;
    }
    const auto faceIt = topology.faces.find(faceKey);
    if (faceIt == topology.faces.end()) {
      return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
    }
    std::sort(rays.begin(), rays.end(), [](const RayCut &first,
                                            const RayCut &second) {
      return first.ordinal < second.ordinal;
    });
    for (std::size_t index = 0U; index < rays.size(); ++index) {
      if (rays[index].sourceCorner != rays.front().sourceCorner ||
          (index > 0U && rays[index - 1U].ordinal == rays[index].ordinal) ||
          (index > 0U &&
           rays[index - 1U].forwardOrbit != rays[index].reverseOrbit)) {
        GlobalTopologyPlanError failure =
            rotation_error(rays[index].sourceCorner != rays.front().sourceCorner ? RotationSystemInconsistencyReason::FragmentCornerSourceCornerMismatch : ((index > 0U && rays[index - 1U].ordinal == rays[index].ordinal) ? RotationSystemInconsistencyReason::FragmentCornerRayOrdinalDuplicate : RotationSystemInconsistencyReason::FragmentCornerOrbitChainMismatch));
        failure.sourceFace = faceKey;
        return failure;
      }
    }
    const SourceFaceRecord &face = faceIt->second;
    const std::size_t sourceCorner = rays.front().sourceCorner;
    const authority::SourceVertexId sourceVertex = face.vertices[sourceCorner];
    for (const RayCut &ray : rays) {
      result[faceKey][ray.forwardOrbit].insert(sourceVertex);
      result[faceKey][ray.reverseOrbit].insert(sourceVertex);
    }
    result[faceKey][rays.front().reverseOrbit].insert(
        face.vertices[(sourceCorner + 1U) % 3U]);
    result[faceKey][rays.back().forwardOrbit].insert(
        face.vertices[(sourceCorner + 2U) % 3U]);
  }

  return result;
}

struct RegionDraft {
  std::size_t orbit = 0U;
  std::vector<GlobalTopologyOrientedArc> boundary;
};

struct RegionFrontierEvidence {
  detail::SourceFaceComponentPartition partition;
  detail::CertifiedSourceFaceOwnerConsistency ownerConsistency;
};

struct RegionBuildSuccess {
  std::vector<GlobalTopologyRegion> regions;
  RegionFrontierEvidence frontier;
};

[[nodiscard]] bool contains_all_faces(
    const std::vector<authority::SourceFaceTopologyKey> &container,
    const std::vector<authority::SourceFaceTopologyKey> &contained) {
  return std::includes(container.begin(), container.end(), contained.begin(),
                       contained.end());
}

[[nodiscard]] const SurfaceCutGraphUncutComponentCensus *
find_corresponding_uncut_component_census(
    const SurfaceCutGraphCellularityCertificate &certificate,
    const std::vector<authority::SourceFaceTopologyKey> &planFaces) {
  const SurfaceCutGraphUncutComponentCensus *bestSubset = nullptr;
  for (const auto &candidate : certificate.uncutComponentCensuses) {
    if (candidate.faces == planFaces) return &candidate;
    if (!contains_all_faces(candidate.faces, planFaces)) continue;
    if (bestSubset == nullptr ||
        std::make_pair(candidate.faces.size(), candidate.component) <
            std::make_pair(bestSubset->faces.size(), bestSubset->component)) {
      bestSubset = &candidate;
    }
  }
  return bestSubset;
}

[[nodiscard]] UncutComponentPartitionIdentity
plan_uncut_component_partition_identity() {
  UncutComponentPartitionIdentity identity;
  identity.domainRule = UncutComponentPartitionDomainRule::EmptyFragmentOrbits;
  identity.barriers.cutGraphCutEdges = true;
  identity.barriers.networkMandatoryEdges = true;
  identity.barriers.nonTerminalTraceCarrierEdges = true;
  return identity;
}

[[nodiscard]] std::vector<std::size_t> region_frontier_components(
    const GlobalTopologyPlanError &failure,
    const RegionFrontierEvidence &frontier,
    const std::vector<GlobalTopologyRegion> *regions = nullptr) {
  std::set<std::size_t> components;
  const auto add_component = [&](const std::size_t component) {
    if (component < frontier.ownerConsistency.components.size())
      components.insert(component);
  };

  if (failure.uncutFaceComponent.has_value()) {
    add_component(*failure.uncutFaceComponent);
  } else if (failure.sourceFace.has_value()) {
    const auto component =
        frontier.partition.componentByFace.find(*failure.sourceFace);
    if (component != frontier.partition.componentByFace.end())
      add_component(component->second);
  } else if (regions != nullptr && failure.region.has_value()) {
    const auto region = std::find_if(
        regions->begin(), regions->end(), [&](const auto &candidate) {
          return candidate.id == *failure.region;
        });
    if (region != regions->end()) {
      for (const auto &face : region->sourceFaces) {
        const auto found = frontier.partition.componentByFace.find(face);
        if (found != frontier.partition.componentByFace.end())
          add_component(found->second);
      }
    }
  }

  if (components.empty() && frontier.partition.components.size() == 1U)
    add_component(0U);
  return {components.begin(), components.end()};
}

void annotate_region_frontier_evidence(
    GlobalTopologyPlanError &failure, const RegionFrontierFailureStage stage,
    const RegionFrontierEvidence &frontier,
    const SurfaceCutGraphCellularityCertificate &certificate,
    const std::vector<GlobalTopologyRegion> *regions = nullptr) {
  failure.regionFrontierFailureStage = stage;
  failure.regionFrontierComponents.clear();

  const UncutComponentPartitionIdentity planPartitionIdentity =
      plan_uncut_component_partition_identity();
  for (const std::size_t component :
       region_frontier_components(failure, frontier, regions)) {
    const auto &row = frontier.ownerConsistency.components[component];
    RegionFrontierComponentEvidenceDiagnostic evidence;
    evidence.component = component;
    evidence.partitionIdentity = planPartitionIdentity;
    evidence.faceSetDigest = detail::source_face_set_digest(row.faces);

    const auto *census =
        find_corresponding_uncut_component_census(certificate, row.faces);
    if (census != nullptr) {
      evidence.censusCorrespondence =
          census->faces == row.faces
              ? RegionFrontierCensusCorrespondence::Exact
              : RegionFrontierCensusCorrespondence::Superset;
      evidence.censusComponent = census->component;
      evidence.censusPartitionIdentity = census->partitionIdentity;
      evidence.censusFaceSetDigest = census->faceSetDigest;
      evidence.componentSubsetOfCensusComponent =
          contains_all_faces(census->faces, row.faces);
    }
    failure.regionFrontierComponents.push_back(std::move(evidence));
  }
  failure.regionFrontierComponentCount = failure.regionFrontierComponents.size();
  failure.regionFrontierComponentsTruncated = false;
}

void annotate_uncut_face_component_seed_evidence(
    GlobalTopologyPlanError &failure, const RegionFrontierEvidence &frontier,
    const SurfaceCutGraphCellularityCertificate &certificate) {
  annotate_region_frontier_evidence(
      failure, RegionFrontierFailureStage::UncutComponent, frontier,
      certificate);
  if (!failure.uncutFaceComponent.has_value() ||
      *failure.uncutFaceComponent >= frontier.ownerConsistency.components.size()) {
    return;
  }
  const std::size_t component = *failure.uncutFaceComponent;
  const auto &row = frontier.ownerConsistency.components[component];

  failure.uncutFaceComponentSeedCount = row.ownerMultiplicity.size();
  failure.uncutFaceComponentSeedState =
      row.ownerMultiplicity.empty()
          ? UncutFaceComponentSeedState::None
          : row.ownerMultiplicity.size() == 1U
                ? UncutFaceComponentSeedState::Unique
                : UncutFaceComponentSeedState::Multiple;
  failure.uncutFaceComponentFaceCount = row.faces.size();
  failure.uncutFaceComponentFaces = row.faces;
  failure.uncutFaceComponentFacesTruncated = false;
  failure.uncutFaceComponentPartitionIdentity =
      plan_uncut_component_partition_identity();
  failure.uncutFaceComponentFaceSetDigest =
      detail::source_face_set_digest(row.faces);

  const auto *census =
      find_corresponding_uncut_component_census(certificate, row.faces);
  if (census != nullptr) {
    failure.uncutComponentCensusComponent = census->component;
    failure.uncutComponentCensusPartitionIdentity = census->partitionIdentity;
    failure.uncutComponentCensusFaceSetDigest = census->faceSetDigest;
    failure.uncutComponentCensusMatchesFailingComponent =
        census->faces == row.faces;
    failure.uncutFaceComponentSubsetOfCensusComponent =
        contains_all_faces(census->faces, row.faces);
  }

  const std::set<authority::SourceFaceTopologyKey> failingPlanFaces(
      row.faces.begin(), row.faces.end());
  std::map<authority::NetworkArcId,
           SurfaceCutGraphUncutComponentArcIncidenceCensus>
      failingArcRows;
  for (const auto &certifierCensus : certificate.uncutComponentCensuses) {
    for (const auto &certifierArc : certifierCensus.interiorArcIncidences) {
      SurfaceCutGraphUncutComponentArcIncidenceCensus enriched = certifierArc;
      bool meetsFailingComponent = false;
      for (auto &crossedFace : enriched.crossedFaces) {
        const auto planComponent =
            frontier.partition.componentByFace.find(crossedFace.sourceFace);
        if (planComponent != frontier.partition.componentByFace.end()) {
          crossedFace.planComponent = planComponent->second;
        }
        if (failingPlanFaces.count(crossedFace.sourceFace) != 0U) {
          meetsFailingComponent = true;
        }
      }
      if (meetsFailingComponent) {
        failingArcRows.insert_or_assign(enriched.arc, std::move(enriched));
      }
    }
  }
  failure.uncutFaceComponentInteriorArcCensusPublished = true;
  failure.uncutFaceComponentInteriorArcIncidences.clear();
  failure.uncutFaceComponentInteriorArcIncidences.reserve(
      failingArcRows.size());
  for (auto &[arcId, arcRow] : failingArcRows) {
    (void)arcId;
    failure.uncutFaceComponentInteriorArcIncidences.push_back(
        std::move(arcRow));
  }
  failure.uncutFaceComponentInteriorArcCount =
      failure.uncutFaceComponentInteriorArcIncidences.size();
  failure.uncutFaceComponentInteriorArcIncidencesTruncated = false;

  failure.uncutFaceComponentCertifiedFaceObservationCount =
      row.ownerObservations.size();
  failure.uncutFaceComponentCertifiedFaceObservations.clear();
  failure.uncutFaceComponentCertifiedFaceObservations.reserve(
      row.ownerObservations.size());
  for (const auto &[sourceFace, certifiedFace] : row.ownerObservations) {
    failure.uncutFaceComponentCertifiedFaceObservations.push_back(
        UncutFaceComponentCertifiedFaceObservationDiagnostic{sourceFace,
                                                               certifiedFace});
  }
  failure.uncutFaceComponentCertifiedFaceObservationsTruncated = false;

  std::set<authority::SourceFaceTopologyKey> observedFaces;
  for (const auto &[sourceFace, certifiedFace] : row.ownerObservations) {
    (void)certifiedFace;
    observedFaces.insert(sourceFace);
  }
  failure.uncutFaceComponentCertifiedFaceUnavailableCount =
      row.faces.size() > observedFaces.size()
          ? row.faces.size() - observedFaces.size()
          : 0U;
  failure.uncutFaceComponentCertifiedFaceDistinctCount =
      row.ownerMultiplicity.size();
  failure.uncutFaceComponentCertifiedFaceMultiset.clear();
  for (const auto &[owner, multiplicity] : row.ownerMultiplicity) {
    if (failure.uncutFaceComponentCertifiedFaceMultiset.size() >=
        kUncutComponentSeedEvidenceLimit) {
      break;
    }
    failure.uncutFaceComponentCertifiedFaceMultiset.push_back(
        UncutFaceComponentCertifiedFaceMultiplicityDiagnostic{owner,
                                                               multiplicity});
  }
  failure.uncutFaceComponentCertifiedFaceMultisetTruncated =
      row.ownerMultiplicity.size() >
      failure.uncutFaceComponentCertifiedFaceMultiset.size();
}

using RegionBuildResult =
    std::variant<RegionBuildSuccess, GlobalTopologyPlanError>;

RegionBuildResult build_regions(
    const SourceTopologyIndex &topology,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph,
    const std::vector<GlobalTopologyArc> &arcs,
    const FaceWalkResult &walk, FragmentDiagnosticEvidence *diagnostics,
    TraceFragmentOwnerEvidenceDiagnostic *ownerEvidence) {
  (void)sourceAuthority;

  const auto exteriorBuild =
      exterior_boundary_orbits(topology, network, arcs, walk);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&exteriorBuild)) {
    return *failure;
  }
  std::set<std::size_t> exteriorOrbits =
      std::get<std::set<std::size_t>>(exteriorBuild);
  std::set<authority::SourceEdgeTopologyKey> mandatoryEdges;
  const std::set<authority::SourceEdgeTopologyKey> cutEdges(
      cutGraph.cut_edges().begin(), cutGraph.cut_edges().end());
  std::map<authority::SourceFaceTopologyKey, std::set<std::size_t>>
      fragmentOrbits;
  std::map<authority::SourceFaceTopologyKey, std::size_t> tracePieceCount;
  std::set<authority::SourceEdgeTopologyKey> traceTouchedEdges;
  std::map<std::pair<authority::SourceFaceTopologyKey,
                     authority::SourceEdgeTopologyKey>,
           std::set<std::size_t>>
      edgeOrbitEvidence;
  std::map<authority::SourceFaceTopologyKey,
           std::vector<FragmentLocalTraceChord>>
      localTraceChords;

  const auto add_fragment_orbit = [&](const authority::SourceFaceTopologyKey &face,
                                      const std::size_t orbit) {
    if (exteriorOrbits.count(orbit) == 0U) {
      fragmentOrbits[face].insert(orbit);
    }
  };

  // Mandatory source edges carry an exact interior-side dart. Boundary edges
  // additionally identify the exterior orbit. This is oriented network
  // evidence, not source-component or traversal-order authority.
  for (const auto &mandatory : network.mandatory_edges()) {
    mandatoryEdges.insert(mandatory.sourceEdge);
    const auto arcIndices = mandatory_arc_indices(arcs, mandatory.id);
    if (arcIndices.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary);
      failure.networkEdge = mandatory.id;
      failure.sourceEdge = mandatory.sourceEdge;
      return failure;
    }
    const auto incident = topology.incidentFaces.find(mandatory.sourceEdge);
    if (incident == topology.incidentFaces.end() || incident->second.empty()) {
      return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
    }
    for (const std::size_t arcIndex : arcIndices) {
      const GlobalTopologyArc &arc = arcs[arcIndex];
      for (const auto &faceKey : incident->second) {
        const auto face = topology.faces.find(faceKey);
        if (face == topology.faces.end()) {
          return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        }
        const bool forward =
            face_orients_edge_forward(face->second, mandatory.sourceEdge);
        const std::size_t interiorDart =
            2U * arc.id.index() + (forward ? 0U : 1U);
        if (interiorDart >= walk.orbitByDart.size()) {
          return rotation_error(RotationSystemInconsistencyReason::MandatoryBoundaryInteriorDartOutOfRange);
        }
        const std::size_t interiorOrbit = walk.orbitByDart[interiorDart];
        fragmentOrbits[faceKey].insert(interiorOrbit);
        edgeOrbitEvidence[std::make_pair(faceKey, mandatory.sourceEdge)]
            .insert(interiorOrbit);
      }
    }
  }

  // A2a' cuts are arrangement chords carried by selected source edges. A
  // trace-crossed cut edge owns one Cut sub-arc per consecutive exact point
  // pair, so every sub-arc contributes its two interior-side darts. build_arcs
  // emits those sub-arcs in canonical cutEdge.first() -> cutEdge.second()
  // order; the source-face orientation below therefore selects the same side
  // of every sub-arc with the unchanged dart formula.
  for (const auto &cutEdge : cutGraph.cut_edges()) {
    const auto incident = topology.incidentFaces.find(cutEdge);
    if (incident == topology.incidentFaces.end() || incident->second.size() != 2U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
      failure.sourceEdge = cutEdge;
      return failure;
    }
    std::vector<std::size_t> arcIndices;
    for (std::size_t index = 0U; index < arcs.size(); ++index) {
      if (arcs[index].kind == GlobalTopologyArcKind::Cut &&
          arcs[index].cutEdge == cutEdge) {
        arcIndices.push_back(index);
      }
    }
    if (arcIndices.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
      failure.sourceEdge = cutEdge;
      return failure;
    }
    for (const std::size_t arcIndex : arcIndices) {
      const GlobalTopologyArc &arc = arcs[arcIndex];
      for (const auto &faceKey : incident->second) {
        const auto face = topology.faces.find(faceKey);
        if (face == topology.faces.end()) {
          return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        }
        const bool forward = face_orients_edge_forward(face->second, cutEdge);
        const std::size_t interiorDart =
            2U * arc.id.index() + (forward ? 0U : 1U);
        if (interiorDart >= walk.orbitByDart.size()) {
          return rotation_error(RotationSystemInconsistencyReason::CutBoundaryInteriorDartOutOfRange);
        }
        const std::size_t interiorOrbit = walk.orbitByDart[interiorDart];
        fragmentOrbits[faceKey].insert(interiorOrbit);
        edgeOrbitEvidence[std::make_pair(faceKey, cutEdge)].insert(interiorOrbit);
      }
    }
  }

  std::vector<RegionDraft> drafts;
  for (std::size_t orbit = 0U; orbit < walk.orbits.size(); ++orbit) {
    if (exteriorOrbits.count(orbit) != 0U) continue;
    drafts.push_back(RegionDraft{orbit, walk.orbits[orbit]});
  }
  if (drafts.empty()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::EmbeddedGraphHasNoInteriorFace);
    failure.arc = walk.orbits.front().front().arc;
    return failure;
  }
  std::sort(drafts.begin(), drafts.end(), [](const RegionDraft &lhs,
                                             const RegionDraft &rhs) {
    return lhs.boundary < rhs.boundary;
  });
  std::map<std::size_t, std::size_t> draftByOrbit;
  for (std::size_t index = 0U; index < drafts.size(); ++index) {
    draftByOrbit.emplace(drafts[index].orbit, index);
  }

  // A trace segment is a topological chord of its source face. The two darts
  // of its graph arc are the two sides of that chord, and orbitByDart is the
  // sole owner label for those two fragments. Multiple chords in one face are
  // consistent exactly when their distinct dart orbits produce k+1 fragments.
  for (const auto &arc : arcs) {
    if (arc.kind != GlobalTopologyArcKind::Trace) continue;
    if (!arc.trace.has_value()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.arc = arc.id;
      return failure;
    }
    const auto *trace = find_trace(network, *arc.trace);
    if (trace == nullptr || arc.firstSegment >= arc.onePastLastSegment ||
        arc.onePastLastSegment > trace->segments.size()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.arc = arc.id;
      return failure;
    }
    const std::size_t forwardDart =
        dart_index(GlobalTopologyOrientedArc{arc.id,
                                             authority::Orientation::Forward});
    const std::size_t reverseDart =
        dart_index(GlobalTopologyOrientedArc{arc.id,
                                             authority::Orientation::Reverse});
    if (forwardDart >= walk.orbitByDart.size() ||
        reverseDart >= walk.orbitByDart.size()) {
      return rotation_error(forwardDart >= walk.orbitByDart.size() ? RotationSystemInconsistencyReason::TraceBoundaryForwardDartOutOfRange : RotationSystemInconsistencyReason::TraceBoundaryReverseDartOutOfRange);
    }
    const std::size_t forwardOrbit = walk.orbitByDart[forwardDart];
    const std::size_t reverseOrbit = walk.orbitByDart[reverseDart];
    const bool separatesCertifiedFaces = forwardOrbit != reverseOrbit;

    std::optional<authority::SourceVertexId> sourcePortVertex;
    if (diagnostics != nullptr) {
      const auto port = std::find_if(
          network.singularity_ports().begin(),
          network.singularity_ports().end(),
          [&](const auto &candidate) { return candidate.id == trace->port; });
      if (port != network.singularity_ports().end()) {
        sourcePortVertex = port->sourceVertex;
      }
    }

    for (std::size_t segmentIndex = arc.firstSegment;
         segmentIndex < arc.onePastLastSegment; ++segmentIndex) {
      const auto &segment = trace->segments[segmentIndex];
      const auto faceIt = topology.faces.find(segment.sourceFace);
      if (faceIt == topology.faces.end()) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        failure.arc = arc.id;
        failure.sourceFace = segment.sourceFace;
        return failure;
      }
      if (is_terminal_slit(*trace, segmentIndex) &&
          !separatesCertifiedFaces) {
        // No source-face chord was materialized: the retained outgoing carrier
        // is a hypothetical continuation only. A face with k real trace chords
        // has exactly k+1 fragments, so a non-separating terminal slit
        // contributes zero to k, touches no source edge, and publishes no orbit
        // evidence.
        continue;
      }
      ++tracePieceCount[segment.sourceFace];
      add_fragment_orbit(segment.sourceFace, forwardOrbit);
      add_fragment_orbit(segment.sourceFace, reverseOrbit);
      traceTouchedEdges.insert(segment.outgoingCarrier);
      if (segment.incomingCarrier.has_value()) {
        traceTouchedEdges.insert(*segment.incomingCarrier);
      }
      if (diagnostics != nullptr) {
        diagnostics->traceSegments.push_back(FragmentDiagnosticTraceSegment{
            trace->id, arc.id, segmentIndex, forwardOrbit, reverseOrbit,
            segment.sourceFace, segment.incomingCarrier,
            segment.outgoingCarrier, sourcePortVertex});
      }
      if (ownerEvidence != nullptr) {
        const auto first = boundary_point_barycentric(faceIt->second,
                                                      segment.entryPoint);
        const auto second = trace_segment_exit_barycentric(
            faceIt->second, *trace, segmentIndex);
        if (first.has_value() && second.has_value()) {
          localTraceChords[segment.sourceFace].push_back(FragmentLocalTraceChord{
              TraceCutFaceFragmentIncidenceDiagnostic{
                  trace->id, arc.id, segmentIndex,
                  authority::Orientation::Forward, segment.incomingCarrier,
                  segment.outgoingCarrier, forwardOrbit, reverseOrbit,
                  exteriorOrbits.count(forwardOrbit) != 0U,
                  exteriorOrbits.count(reverseOrbit) != 0U},
              first, second});
        } else {
          // Retain an explicit unevaluated marker for this face. The local
          // arrangement is evidence-only in CB21 and cannot reject input.
          localTraceChords[segment.sourceFace].push_back(FragmentLocalTraceChord{
              TraceCutFaceFragmentIncidenceDiagnostic{
                  trace->id, arc.id, segmentIndex,
                  authority::Orientation::Forward, segment.incomingCarrier,
                  segment.outgoingCarrier, forwardOrbit, reverseOrbit,
                  exteriorOrbits.count(forwardOrbit) != 0U,
                  exteriorOrbits.count(reverseOrbit) != 0U},
              std::nullopt, std::nullopt});
        }
      }

      // On a triangle, a chord between two carriers leaves the third edge
      // wholly on exactly one oriented side. Record that exact side so an
      // otherwise-uncut neighboring face can inherit the same graph-face orbit
      // without a flood fill or traversal-order choice.
      if (segment.incomingCarrier.has_value()) {
        const auto incoming =
            local_edge_index(faceIt->second, *segment.incomingCarrier);
        const auto outgoing =
            local_edge_index(faceIt->second, segment.outgoingCarrier);
        if (!incoming.has_value() || !outgoing.has_value() ||
            *incoming == *outgoing) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RegionTraceSegmentCarriersCoincide);
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        const std::size_t turn = (*outgoing + 3U - *incoming) % 3U;
        if (turn != 1U && turn != 2U) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RegionTraceSegmentTurnNotAdmissible);
          failure.sourceFace = segment.sourceFace;
          return failure;
        }
        std::size_t third = 0U;
        while (third == *incoming || third == *outgoing) ++third;
        const std::size_t sideOrbit = turn == 1U ? forwardOrbit : reverseOrbit;
        if (exteriorOrbits.count(sideOrbit) == 0U) {
          edgeOrbitEvidence[
              std::make_pair(segment.sourceFace, faceIt->second.edges[third])]
              .insert(sideOrbit);
        }
      } else {
        const auto binding = resolve_carrierless_corner_binding(
            faceIt->second, *trace, segmentIndex, segment);
        const auto outgoing =
            local_edge_index(faceIt->second, segment.outgoingCarrier);
        if (!binding.has_value() || !outgoing.has_value() ||
            *outgoing != (binding->sourceCorner + 1U) % 3U) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RegionTraceSourcePortCarrierNotAdmissible);
          failure.sourceFace = segment.sourceFace;
          annotate_trace_segment_incidence(failure, arc, *trace, segmentIndex,
                                           segment, binding);
          return failure;
        }
        const auto forwardEdge =
            faceIt->second.edges[(binding->sourceCorner + 2U) % 3U];
        const auto reverseEdge = faceIt->second.edges[binding->sourceCorner];
        if (exteriorOrbits.count(forwardOrbit) == 0U) {
          edgeOrbitEvidence[std::make_pair(segment.sourceFace, forwardEdge)]
              .insert(forwardOrbit);
        }
        if (exteriorOrbits.count(reverseOrbit) == 0U) {
          edgeOrbitEvidence[std::make_pair(segment.sourceFace, reverseEdge)]
              .insert(reverseOrbit);
        }
      }
    }
  }

  if (ownerEvidence != nullptr) {
    ownerEvidence->totalOrbitCount = walk.orbits.size();
    ownerEvidence->exteriorOrbitCount = exteriorOrbits.size();
    ownerEvidence->nonExteriorOrbitCount =
        walk.orbits.size() >= exteriorOrbits.size()
            ? walk.orbits.size() - exteriorOrbits.size()
            : 0U;
    ownerEvidence->arcCount = arcs.size();
    for (const auto &arc : arcs) {
      if (ownerEvidence->arcs.size() >= kFragmentOwnerCensusEvidenceLimit)
        break;
      const std::size_t forwardDart = dart_index(GlobalTopologyOrientedArc{
          arc.id, authority::Orientation::Forward});
      const std::size_t reverseDart = dart_index(GlobalTopologyOrientedArc{
          arc.id, authority::Orientation::Reverse});
      if (forwardDart >= walk.orbitByDart.size() ||
          reverseDart >= walk.orbitByDart.size()) {
        continue;
      }
      const std::size_t forwardOrbit = walk.orbitByDart[forwardDart];
      const std::size_t reverseOrbit = walk.orbitByDart[reverseDart];
      ownerEvidence->arcs.push_back(TraceArcOwnerCensusDiagnostic{
          arc.id, arc.trace, forwardOrbit, reverseOrbit,
          forwardOrbit == reverseOrbit});
    }
    ownerEvidence->arcsTruncated = ownerEvidence->arcCount > ownerEvidence->arcs.size();

    ownerEvidence->traceCount = network.candidate_traces().size();
    for (const auto &trace : network.candidate_traces()) {
      if (ownerEvidence->traces.size() >= kFragmentOwnerCensusEvidenceLimit)
        break;
      const bool terminalSlit = !trace.segments.empty() &&
          is_terminal_slit(trace, trace.segments.size() - 1U);
      ownerEvidence->traces.push_back(
          TraceTerminalSlitCensusDiagnostic{trace.id, terminalSlit});
    }
    ownerEvidence->tracesTruncated =
        ownerEvidence->traceCount > ownerEvidence->traces.size();
  }

  // Validate every directly cut face before extending single-fragment interiors.
  // A face with k real trace chords has k+1 fragments; a terminal slit is
  // not a chord and contributes zero to k. A face with no real chord has one.
  for (const auto &[faceKey, record] : topology.faces) {
    (void)record;
    const auto found = fragmentOrbits.find(faceKey);
    if (found == fragmentOrbits.end() || found->second.empty()) continue;
    const std::size_t expected = tracePieceCount[faceKey] + 1U;
    if (ownerEvidence != nullptr) {
      const auto chordIt = localTraceChords.find(faceKey);
      const std::vector<FragmentLocalTraceChord> emptyChords;
      const auto &chords = chordIt == localTraceChords.end()
                               ? emptyChords
                               : chordIt->second;
      FragmentLocalArrangement arrangement;
      arrangement = local_fragment_arrangement(chords);
      TraceCutFaceFragmentOwnerEvidenceDiagnostic row{faceKey};
      row.localFragmentCount = arrangement.fragmentCount;
      row.ownerCount = found->second.size();
      row.expectedFragmentCount = expected;
      row.ownerDeficit = expected > found->second.size()
                             ? expected - found->second.size()
                             : 0U;
      row.traceChordCount = tracePieceCount[faceKey];
      row.chordsCrossInside = arrangement.chordsCrossInside;
      row.localArrangementEvaluated = arrangement.evaluated;
      for (const auto &chord : chords) {
        if (chord.incidence.forwardOrbit != chord.incidence.reverseOrbit)
          continue;
        ++row.sharedOwnerChordCount;
        if (row.sharedOwnerChords.size() < kFragmentFailureEvidenceLimit) {
          row.sharedOwnerChords.push_back(chord.incidence);
        }
      }
      row.sharedOwnerChordsTruncated =
          row.sharedOwnerChordCount > row.sharedOwnerChords.size();
      ++ownerEvidence->faceCount;
      if (ownerEvidence->faces.size() < kFragmentFaceEvidenceLimit) {
        ownerEvidence->faces.push_back(std::move(row));
      }
      ownerEvidence->facesTruncated =
          ownerEvidence->faceCount > ownerEvidence->faces.size();
    }
    if (found->second.size() > expected) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::TraceCutFaceFragmentCountMismatch);
      failure.sourceFace = faceKey;
      failure.fragmentOrbitCount = found->second.size();
      failure.tracePieceCount = tracePieceCount[faceKey];
      failure.expectedFragmentCount = expected;

      // Retain only bounded, exact evidence for the failing face. This repeats
      // the already-completed trace/orbit read without mutating any count,
      // orbit, region, or control-flow decision. Segment indices traverse the
      // candidate trace in its Forward orientation.
      for (const auto &arc : arcs) {
        if (arc.kind != GlobalTopologyArcKind::Trace || !arc.trace.has_value())
          continue;
        const auto *trace = find_trace(network, *arc.trace);
        if (trace == nullptr) continue;
        const std::size_t forwardDart = dart_index(GlobalTopologyOrientedArc{
            arc.id, authority::Orientation::Forward});
        const std::size_t reverseDart = dart_index(GlobalTopologyOrientedArc{
            arc.id, authority::Orientation::Reverse});
        if (forwardDart >= walk.orbitByDart.size() ||
            reverseDart >= walk.orbitByDart.size())
          continue;
        const std::size_t forwardOrbit = walk.orbitByDart[forwardDart];
        const std::size_t reverseOrbit = walk.orbitByDart[reverseDart];
        for (std::size_t segmentIndex = arc.firstSegment;
             segmentIndex < arc.onePastLastSegment; ++segmentIndex) {
          const auto &segment = trace->segments[segmentIndex];
          if (segment.sourceFace != faceKey ||
              is_terminal_slit(*trace, segmentIndex))
            continue;
          ++failure.fragmentIncidenceCount;
          if (failure.fragmentIncidences.size() >=
              kFragmentFailureEvidenceLimit)
            continue;
          failure.fragmentIncidences.push_back(
              TraceCutFaceFragmentIncidenceDiagnostic{
                  trace->id, arc.id, segmentIndex,
                  authority::Orientation::Forward, segment.incomingCarrier,
                  segment.outgoingCarrier, forwardOrbit, reverseOrbit,
                  exteriorOrbits.count(forwardOrbit) != 0U,
                  exteriorOrbits.count(reverseOrbit) != 0U});
        }
      }
      failure.fragmentIncidencesTruncated =
          failure.fragmentIncidenceCount > failure.fragmentIncidences.size();

      for (const auto &edge : record.edges) {
        TraceCutFaceEdgeOrbitEvidenceDiagnostic row{edge, {}, 0U, false};
        const auto evidence =
            edgeOrbitEvidence.find(std::make_pair(faceKey, edge));
        if (evidence != edgeOrbitEvidence.end()) {
          row.totalOrbitCount = evidence->second.size();
          for (const std::size_t orbit : evidence->second) {
            if (row.orbitIds.size() >= kFragmentFailureEvidenceLimit) break;
            row.orbitIds.push_back(orbit);
          }
          row.truncated = row.totalOrbitCount > row.orbitIds.size();
        }
        failure.fragmentEdgeOrbitEvidence.push_back(std::move(row));
      }

      // The success-path diagnostic below remains unchanged; when fragment
      // diagnostics are enabled, publish that same record before this early
      // return so the first failing face is observable.
      if (diagnostics != nullptr) {
        std::cerr << "M3_CP4AB_FRAGMENT_DIAG record=fragment_reconciliation"
                  << " source_face=" << diagnostic_face(faceKey)
                  << " fragment_orbit_count=" << found->second.size()
                  << " trace_piece_count=" << tracePieceCount[faceKey]
                  << " expected_fragment_count=" << expected << '\n';
      }
      return failure;
    }
  }

  // Source-face ownership is certified by SurfaceCutGraph. GlobalTopologyPlan
  // consumes that total map directly; it does not reconstruct ownership from
  // component seeds. The component partition remains only as a consistency
  // guard that verifies one certified owner per uncut component.
  std::vector<authority::SourceFaceTopologyKey> unlabeledFaces;
  for (const auto &[faceKey, record] : topology.faces) {
    (void)record;
    const auto found = fragmentOrbits.find(faceKey);
    if (found != fragmentOrbits.end() && !found->second.empty()) continue;
    unlabeledFaces.push_back(faceKey);
  }

  std::set<authority::SourceEdgeTopologyKey> componentBarriers = mandatoryEdges;
  componentBarriers.insert(traceTouchedEdges.begin(), traceTouchedEdges.end());
  componentBarriers.insert(cutEdges.begin(), cutEdges.end());
  const auto componentPartition = detail::build_source_face_component_partition(
      unlabeledFaces, topology.incidentFaces, componentBarriers);
  const auto ownerConsistency = detail::check_certified_source_face_owner_consistency(
      componentPartition, cutGraph.certificate());

  if (ownerEvidence != nullptr) {
    ownerEvidence->componentCount = ownerConsistency.components.size();
    for (const auto &component : ownerConsistency.components) {
      if (ownerEvidence->components.size() >=
          kFragmentOwnerCensusEvidenceLimit) {
        break;
      }
      UncutFaceComponentSeedCensusDiagnostic row;
      row.component = component.component;
      row.faceCount = component.faces.size();
      row.seedCount = component.ownerMultiplicity.size();
      row.seedState = row.seedCount == 0U
                          ? UncutFaceComponentSeedState::None
                          : row.seedCount == 1U
                                ? UncutFaceComponentSeedState::Unique
                                : UncutFaceComponentSeedState::Multiple;
      row.seedOrbitCount = component.ownerMultiplicity.size();
      for (const auto &[owner, count] : component.ownerMultiplicity) {
        (void)count;
        if (row.seedOrbitIds.size() >= kUncutComponentSeedEvidenceLimit) break;
        row.seedOrbitIds.push_back(owner);
      }
      row.seedOrbitsTruncated = row.seedOrbitCount > row.seedOrbitIds.size();
      ownerEvidence->components.push_back(std::move(row));
    }
    ownerEvidence->componentsTruncated =
        ownerEvidence->componentCount > ownerEvidence->components.size();
  }

  const RegionFrontierEvidence frontier{componentPartition, ownerConsistency};
  const auto annotate_frontier = [&](GlobalTopologyPlanError failure) {
    annotate_region_frontier_evidence(
        failure, RegionFrontierFailureStage::RegionConstruction, frontier,
        cutGraph.certificate());
    return failure;
  };

  if (!ownerConsistency.consistent()) {
    const std::size_t component = *ownerConsistency.firstConflictComponent;
    const auto &row = ownerConsistency.components[component];
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::UncutFaceComponentOrbitSeedNotUnique);
    failure.sourceFace = row.invalidFace.has_value()
                             ? *row.invalidFace
                             : row.faces.front();
    failure.sourceFaceLocusKind =
        UncutFaceSourceFaceLocusKind::FirstUnlabeledFaceInIterationOrder;
    failure.uncutFaceComponent = component;
    annotate_uncut_face_component_seed_evidence(
        failure, frontier, cutGraph.certificate());
    return failure;
  }

  for (const auto &face : unlabeledFaces) {
    const auto *owner = cutGraph.certificate().find_source_face_owner(face);
    if (owner == nullptr || owner->trace_crossed() ||
        !owner->established() || owner->certifiedFaceOrbits.size() != 1U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitMissing);
      failure.sourceFace = face;
      return annotate_frontier(std::move(failure));
    }
    fragmentOrbits[face].insert(owner->certifiedFaceOrbits.front());
  }

  std::vector<std::vector<authority::SourceFaceTopologyKey>> owned(drafts.size());
  for (const auto &[faceKey, record] : topology.faces) {
    (void)record;
    const auto fragments = fragmentOrbits.find(faceKey);
    if (fragments == fragmentOrbits.end() || fragments->second.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitMissing);
      failure.sourceFace = faceKey;
      return annotate_frontier(std::move(failure));
    }
    for (const std::size_t orbit : fragments->second) {
      const auto draft = draftByOrbit.find(orbit);
      if (draft == draftByOrbit.end()) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitHasNoRegionDraft);
        failure.sourceFace = faceKey;
        return annotate_frontier(std::move(failure));
      }
      owned[draft->second].push_back(faceKey);
    }
  }

  std::vector<GlobalTopologyRegion> regions;
  regions.reserve(drafts.size());
  for (std::size_t index = 0U; index < drafts.size(); ++index) {
    std::sort(owned[index].begin(), owned[index].end());
    owned[index].erase(std::unique(owned[index].begin(), owned[index].end()),
                       owned[index].end());
    if (owned[index].empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionElectedCutComponentEmpty);
      failure.region = make_id<authority::NetworkRegionId>(index, drafts.size());
      return annotate_frontier(std::move(failure));
    }
    regions.push_back(GlobalTopologyRegion{
        make_id<authority::NetworkRegionId>(index, drafts.size()),
        std::move(drafts[index].boundary), std::move(owned[index])});
  }
  if (diagnostics != nullptr) {
    diagnostics->exteriorOrbits = exteriorOrbits;
    diagnostics->fragmentOrbits = fragmentOrbits;
    diagnostics->tracePieceCount = tracePieceCount;
    diagnostics->edgeOrbitEvidence = edgeOrbitEvidence;
    std::sort(diagnostics->traceSegments.begin(),
              diagnostics->traceSegments.end(),
              [](const auto &lhs, const auto &rhs) {
                return std::tie(lhs.trace, lhs.arc, lhs.segment,
                                lhs.forwardOrbit, lhs.reverseOrbit,
                                lhs.sourceFace, lhs.incomingCarrier,
                                lhs.outgoingCarrier, lhs.sourcePortVertex) <
                       std::tie(rhs.trace, rhs.arc, rhs.segment,
                                rhs.forwardOrbit, rhs.reverseOrbit,
                                rhs.sourceFace, rhs.incomingCarrier,
                                rhs.outgoingCarrier, rhs.sourcePortVertex);
              });
    for (const auto &[face, orbits] : diagnostics->fragmentOrbits) {
      const auto pieces = diagnostics->tracePieceCount.find(face);
      const std::size_t tracePieces =
          pieces == diagnostics->tracePieceCount.end() ? 0U : pieces->second;
      std::cerr << "M3_CP4AB_FRAGMENT_DIAG record=fragment_reconciliation"
                << " source_face=" << diagnostic_face(face)
                << " fragment_orbit_count=" << orbits.size()
                << " trace_piece_count=" << tracePieces
                << " expected_fragment_count=" << (tracePieces + 1U)
                << '\n';
    }
    for (const auto &cutEdge : cutEdges) {
      const auto incident = topology.incidentFaces.find(cutEdge);
      if (incident == topology.incidentFaces.end()) continue;
      for (const auto &face : incident->second) {
        const auto evidence = diagnostics->edgeOrbitEvidence.find(
            std::make_pair(face, cutEdge));
        const std::size_t orbitCount =
            evidence == diagnostics->edgeOrbitEvidence.end()
                ? 0U
                : evidence->second.size();
        std::cerr << "M3_CP4AB_FRAGMENT_DIAG record=cut_edge_orbit_evidence"
                  << " source_face=" << diagnostic_face(face)
                  << " source_edge=" << diagnostic_edge(cutEdge)
                  << " orbit_count=" << orbitCount << '\n';
      }
    }
  }
  return RegionBuildSuccess{std::move(regions), frontier};
}

std::pair<authority::NetworkNodeId, authority::NetworkNodeId>
oriented_arc_nodes(const GlobalTopologyArc &arc,
                   const authority::Orientation orientation) {
  return orientation == authority::Orientation::Forward
             ? std::make_pair(arc.firstNode, arc.secondNode)
             : std::make_pair(arc.secondNode, arc.firstNode);
}

std::optional<GlobalTopologyPlanError> validate_single_boundary_walk(
    const GlobalTopologyRegion &region,
    const std::map<authority::NetworkArcId, const GlobalTopologyArc *> &arcById) {
  if (region.boundary.empty()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
    failure.region = region.id;
    return failure;
  }
  const auto firstArc = arcById.find(region.boundary.front().arc);
  if (firstArc == arcById.end()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
    failure.region = region.id;
    failure.arc = region.boundary.front().arc;
    return failure;
  }
  const auto firstNodes =
      oriented_arc_nodes(*firstArc->second, region.boundary.front().orientation);
  const authority::NetworkNodeId start = firstNodes.first;
  authority::NetworkNodeId current = firstNodes.second;
  for (std::size_t index = 1U; index < region.boundary.size(); ++index) {
    const auto nextArc = arcById.find(region.boundary[index].arc);
    if (nextArc == arcById.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.region = region.id;
      failure.arc = region.boundary[index].arc;
      return failure;
    }
    const auto next =
        oriented_arc_nodes(*nextArc->second, region.boundary[index].orientation);
    if (current == start || next.first != current) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
      failure.region = region.id;
      failure.arc = region.boundary[index].arc;
      return failure;
    }
    current = next.second;
  }
  if (current != start) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
    failure.region = region.id;
    failure.arc = region.boundary.front().arc;
    return failure;
  }
  return std::nullopt;
}

std::optional<GlobalTopologyPlanError> validate_no_region_fragment_pinch(
    const SourceTopologyIndex &topology,
    const std::map<authority::NetworkNodeId, NodeLocus> &loci,
    const std::vector<GlobalTopologyNodeRotation> &rotations,
    const FaceWalkResult &walk, const GlobalTopologyRegion &region,
    const std::size_t owningOrbit) {
  const std::set<authority::SourceFaceTopologyKey> regionFaces(
      region.sourceFaces.begin(), region.sourceFaces.end());

  for (const auto &rotation : rotations) {
    const auto locus = loci.find(rotation.node);
    if (locus == loci.end() || rotation.counterClockwise.empty()) continue;

    const std::size_t count = rotation.counterClockwise.size();
    std::vector<bool> ownsSector(count, false);
    bool anyOwned = false;
    bool allOwned = true;
    for (std::size_t index = 0U; index < count; ++index) {
      const std::size_t incomingDart =
          dart_index(reversed(rotation.counterClockwise[index]));
      if (incomingDart >= walk.orbitByDart.size()) {
        GlobalTopologyPlanError failure =
            rotation_error(RotationSystemInconsistencyReason::RegionFragmentIncomingDartOutOfRange);
        failure.region = region.id;
        failure.sourceVertex = locus->second.vertex;
        failure.sourceEdge = locus->second.edge;
        return failure;
      }
      ownsSector[index] = walk.orbitByDart[incomingDart] == owningOrbit;
      anyOwned = anyOwned || ownsSector[index];
      allOwned = allOwned && ownsSector[index];
    }
    if (!anyOwned || allOwned) continue;

    std::size_t runCount = 0U;
    for (std::size_t index = 0U; index < count; ++index) {
      const std::size_t previous = (index + count - 1U) % count;
      if (ownsSector[index] && !ownsSector[previous]) ++runCount;
    }
    if (runCount <= 1U) continue;

    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionFragmentPinchedAtVertex);
    failure.region = region.id;
    failure.sourceVertex = locus->second.vertex;
    failure.sourceEdge = locus->second.edge;

    std::vector<authority::SourceFaceTopologyKey> witnesses;
    if (locus->second.vertex.has_value()) {
      const auto incident =
          topology.incidentFacesByVertex.find(*locus->second.vertex);
      if (incident != topology.incidentFacesByVertex.end()) {
        for (const auto &face : incident->second) {
          if (regionFaces.count(face) != 0U) witnesses.push_back(face);
        }
        if (witnesses.empty() && !incident->second.empty()) {
          witnesses.push_back(incident->second.front());
        }
      }
    } else if (locus->second.edge.has_value()) {
      const auto incident = topology.incidentFaces.find(*locus->second.edge);
      if (incident != topology.incidentFaces.end()) {
        for (const auto &face : incident->second) {
          if (regionFaces.count(face) != 0U) witnesses.push_back(face);
        }
        if (witnesses.empty() && !incident->second.empty()) {
          witnesses.push_back(incident->second.front());
        }
      }
    }
    if (!witnesses.empty()) {
      failure.sourceFace = witnesses.front();
      failure.secondSourceFace =
          witnesses.size() > 1U ? witnesses[1] : witnesses.front();
    }
    return failure;
  }
  return std::nullopt;
}

using RegionCertificateBuildResult =
    std::variant<GlobalTopologyRegionDiscCertificate, GlobalTopologyPlanError>;

using RegionSingularityValidationResult =
    std::variant<std::vector<authority::FieldSingularityId>,
                 GlobalTopologyPlanError>;

RegionSingularityValidationResult validate_region_interior_singularities(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const GlobalTopologyRegion &region,
    const std::map<authority::NetworkArcId, const GlobalTopologyArc *> &arcById) {
  std::set<authority::NetworkNodeId> boundaryNodes;
  for (const auto incidence : region.boundary) {
    const auto found = arcById.find(incidence.arc);
    if (found == arcById.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.region = region.id;
      failure.arc = incidence.arc;
      return failure;
    }
    const auto nodes = oriented_arc_nodes(*found->second, incidence.orientation);
    boundaryNodes.insert(nodes.first);
    boundaryNodes.insert(nodes.second);
  }

  const std::set<authority::SourceFaceTopologyKey> regionFaces(
      region.sourceFaces.begin(), region.sourceFaces.end());
  std::map<authority::SourceVertexId, authority::FieldSingularityId>
      singularityAtVertex;
  for (const auto &port : network.singularity_ports()) {
    singularityAtVertex.emplace(port.sourceVertex, port.singularity);
  }

  std::vector<authority::FieldSingularityId> boundarySingularities;
  for (const auto &[sourceVertex, singularity] : singularityAtVertex) {
    const auto incident = topology.incidentFacesByVertex.find(sourceVertex);
    if (incident == topology.incidentFacesByVertex.end()) continue;
    const bool reachesRegion = std::any_of(
        incident->second.begin(), incident->second.end(),
        [&](const auto &face) { return regionFaces.count(face) != 0U; });
    if (!reachesRegion) continue;
    const bool onBoundary = std::any_of(
        network.singularity_ports().begin(), network.singularity_ports().end(),
        [&](const auto &port) {
          return port.singularity == singularity &&
                 boundaryNodes.count(port.node) != 0U;
        });
    if (!onBoundary) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionContainsInteriorSingularity);
      failure.region = region.id;
      failure.singularity = singularity;
      failure.sourceVertex = sourceVertex;
      return failure;
    }
    boundarySingularities.push_back(singularity);
  }
  std::sort(boundarySingularities.begin(), boundarySingularities.end());
  boundarySingularities.erase(
      std::unique(boundarySingularities.begin(), boundarySingularities.end()),
      boundarySingularities.end());
  return boundarySingularities;
}

void emit_fragment_euler_diagnostics(
    const FragmentDiagnosticEvidence &diagnostics,
    const GlobalTopologyRegion &region, const std::size_t owningOrbit,
    const std::set<authority::SourceVertexId> &candidateVertices,
    const std::set<authority::SourceVertexId> &mandatoryBoundaryEndpoints,
    const std::set<authority::SourceVertexId> &tracePortBoundaryVertices,
    const std::set<authority::SourceVertexId> &interiorVertices,
    const GlobalTopologyRegionDiscCertificate &certificate) {
  {
    std::ostringstream out;
    out << "M3_CP4AB_FRAGMENT_DIAG record=exterior_orbits orbits="
        << diagnostic_values(diagnostics.exteriorOrbits);
    std::cerr << out.str() << '\n';
  }
  for (const auto &segment : diagnostics.traceSegments) {
    std::ostringstream out;
    out << "M3_CP4AB_FRAGMENT_DIAG record=trace_segment"
        << " trace=" << segment.trace.index()
        << " arc=" << segment.arc.index()
        << " segment=" << segment.segment
        << " forward_orbit=" << segment.forwardOrbit
        << " reverse_orbit=" << segment.reverseOrbit
        << " source_face=" << diagnostic_face(segment.sourceFace)
        << " incoming_carrier="
        << (segment.incomingCarrier.has_value()
                ? diagnostic_edge(*segment.incomingCarrier)
                : std::string{"none"})
        << " outgoing_carrier=" << diagnostic_edge(segment.outgoingCarrier)
        << " source_port_vertex=";
    if (segment.sourcePortVertex.has_value()) {
      out << segment.sourcePortVertex->index();
    } else {
      out << "none";
    }
    std::cerr << out.str() << '\n';
  }

  std::ostringstream out;
  out << "M3_CP4AB_FRAGMENT_DIAG record=euler_rejection"
      << " region=" << region.id.index()
      << " owning_orbit=" << owningOrbit
      << " support_faces=[";
  for (std::size_t index = 0U; index < region.sourceFaces.size(); ++index) {
    if (index != 0U) out << ';';
    out << diagnostic_face(region.sourceFaces[index]);
  }
  out << "] fragment_orbits=[";
  bool first = true;
  for (const auto &face : region.sourceFaces) {
    const auto found = diagnostics.fragmentOrbits.find(face);
    if (found == diagnostics.fragmentOrbits.end()) continue;
    if (!first) out << ';';
    first = false;
    out << diagnostic_face(face) << ':' << diagnostic_values(found->second);
  }
  out << "] edge_orbit_evidence=[";
  first = true;
  const std::set<authority::SourceFaceTopologyKey> supportFaces(
      region.sourceFaces.begin(), region.sourceFaces.end());
  for (const auto &[key, orbits] : diagnostics.edgeOrbitEvidence) {
    if (supportFaces.count(key.first) == 0U) continue;
    if (!first) out << ';';
    first = false;
    out << diagnostic_face(key.first) << '/' << diagnostic_edge(key.second)
        << ':' << diagnostic_values(orbits);
  }
  out << "] trace_piece_count=[";
  first = true;
  for (const auto &face : region.sourceFaces) {
    if (!first) out << ';';
    first = false;
    const auto found = diagnostics.tracePieceCount.find(face);
    out << diagnostic_face(face) << ':'
        << (found == diagnostics.tracePieceCount.end() ? 0U : found->second);
  }
  out << "] candidate_vertices=" << diagnostic_values(candidateVertices)
      << " mandatory_boundary_endpoints="
      << diagnostic_values(mandatoryBoundaryEndpoints)
      << " trace_port_boundary_vertices="
      << diagnostic_values(tracePortBoundaryVertices)
      << " interior_vertices=" << diagnostic_values(interiorVertices)
      << " V_int=" << certificate.vertexCount
      << " E_int=" << certificate.edgeCount
      << " F=" << certificate.faceCount
      << " chi=" << certificate.eulerCharacteristic;
  std::cerr << out.str() << '\n';
}

RegionCertificateBuildResult build_region_certificate(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph,
    const std::vector<GlobalTopologyArc> &arcs,
    const GlobalTopologyRegion &region, const std::size_t owningOrbit,
    const std::map<authority::NetworkArcId, const GlobalTopologyArc *> &arcById,
    const std::map<authority::NetworkNodeId, NodeLocus> &nodeLoci,
    std::vector<authority::FieldSingularityId> boundarySingularities,
    const FragmentCornerIncidence &fragmentCorners,
    const FragmentDiagnosticEvidence *diagnostics) {
  if (const auto failure = validate_single_boundary_walk(region, arcById);
      failure.has_value()) {
    return *failure;
  }

  GlobalTopologyRegionDiscCertificate certificate(region.id);
  certificate.boundaryWalkCount = 1U;
  certificate.faceCount = region.sourceFaces.size();

  certificate.boundarySingularities = std::move(boundarySingularities);
  certificate.interiorSingularityFree = true;

  using FragmentKey =
      std::pair<authority::SourceFaceTopologyKey, std::size_t>;
  std::set<FragmentKey> fragments;
  std::map<FragmentKey, std::vector<FragmentKey>> neighbors;
  for (const auto &face : region.sourceFaces) {
    const FragmentKey fragment{face, owningOrbit};
    fragments.insert(fragment);
    neighbors.emplace(fragment, std::vector<FragmentKey>{});
  }

  std::set<authority::SourceEdgeTopologyKey> mandatoryEdges;
  for (const auto &mandatory : network.mandatory_edges()) {
    mandatoryEdges.insert(mandatory.sourceEdge);
  }
  const std::set<authority::SourceEdgeTopologyKey> cutEdges(
      cutGraph.cut_edges().begin(), cutGraph.cut_edges().end());
  for (const auto &[edge, incident] : topology.incidentFaces) {
    if (incident.size() != 2U || mandatoryEdges.count(edge) != 0U ||
        cutEdges.count(edge) != 0U) {
      continue;
    }
    const FragmentKey first{incident[0], owningOrbit};
    const FragmentKey second{incident[1], owningOrbit};
    if (fragments.count(first) == 0U || fragments.count(second) == 0U) {
      continue;
    }
    neighbors[first].push_back(second);
    neighbors[second].push_back(first);
    ++certificate.edgeCount;
  }

  std::set<FragmentKey> visited;
  std::deque<FragmentKey> queue;
  const FragmentKey firstFragment{region.sourceFaces.front(), owningOrbit};
  queue.push_back(firstFragment);
  visited.insert(firstFragment);
  while (!queue.empty()) {
    const auto fragment = queue.front();
    queue.pop_front();
    for (const auto &next : neighbors[fragment]) {
      if (visited.insert(next).second) queue.push_back(next);
    }
  }
  if (visited.size() != fragments.size()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionInteriorDisconnected);
    failure.region = region.id;
    failure.sourceFace = region.sourceFaces.front();
    const auto disconnected = std::find_if(
        region.sourceFaces.begin(), region.sourceFaces.end(),
        [&](const auto &face) {
          return visited.count(FragmentKey{face, owningOrbit}) == 0U;
        });
    if (disconnected != region.sourceFaces.end()) {
      failure.secondSourceFace = *disconnected;
    }
    return failure;
  }
  certificate.sourceFacesConnected = true;

  std::set<authority::SourceVertexId> boundaryVertices;
  std::set<authority::SourceVertexId> mandatoryBoundaryEndpoints;
  std::set<authority::SourceVertexId> tracePortBoundaryVertices;
  std::set<authority::NetworkEdgeId> boundaryMandatoryEdges;
  std::set<authority::TraceId> boundaryTraces;
  for (const auto incidence : region.boundary) {
    const auto found = arcById.find(incidence.arc);
    if (found == arcById.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.region = region.id;
      failure.arc = incidence.arc;
      return failure;
    }
    if (found->second->mandatoryEdge.has_value()) {
      boundaryMandatoryEdges.insert(*found->second->mandatoryEdge);
      const auto *mandatory =
          find_mandatory(network, *found->second->mandatoryEdge);
      if (mandatory == nullptr) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
        failure.region = region.id;
        failure.arc = incidence.arc;
        return failure;
      }
      const auto addSourceEndpoint = [&](
          const authority::NetworkNodeId node) {
        if (node == mandatory->firstNode) {
          boundaryVertices.insert(mandatory->sourceEdge.first());
          if (diagnostics != nullptr) {
            mandatoryBoundaryEndpoints.insert(mandatory->sourceEdge.first());
          }
        }
        if (node == mandatory->secondNode) {
          boundaryVertices.insert(mandatory->sourceEdge.second());
          if (diagnostics != nullptr) {
            mandatoryBoundaryEndpoints.insert(mandatory->sourceEdge.second());
          }
        }
      };
      addSourceEndpoint(found->second->firstNode);
      addSourceEndpoint(found->second->secondNode);
    }
    if (found->second->cutEdge.has_value()) {
      for (const authority::NetworkNodeId node :
           {found->second->firstNode, found->second->secondNode}) {
        const auto locus = nodeLoci.find(node);
        if (locus == nodeLoci.end()) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
          failure.region = region.id;
          failure.arc = incidence.arc;
          failure.sourceEdge = found->second->cutEdge;
          return failure;
        }
        if (locus->second.vertex.has_value()) {
          boundaryVertices.insert(*locus->second.vertex);
        }
      }
    }
    if (found->second->trace.has_value()) {
      boundaryTraces.insert(*found->second->trace);
    }
  }
  for (const auto &trace : network.candidate_traces()) {
    if (boundaryTraces.count(trace.id) == 0U) continue;
    const auto port = std::find_if(
        network.singularity_ports().begin(), network.singularity_ports().end(),
        [&](const auto &candidate) { return candidate.id == trace.port; });
    if (port == network.singularity_ports().end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
      failure.region = region.id;
      failure.singularity = trace.singularity;
      return failure;
    }
    boundaryVertices.insert(port->sourceVertex);
    if (diagnostics != nullptr) {
      tracePortBoundaryVertices.insert(port->sourceVertex);
    }
  }

  // A fragment that reaches the source mesh boundary must expose that same
  // mandatory parent edge on the region walk. This prevents the independent
  // mesh-boundary V_int exclusion below from masking an incomplete walk.
  for (const auto &faceKey : region.sourceFaces) {
    const auto face = topology.faces.find(faceKey);
    if (face == topology.faces.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.region = region.id;
      failure.sourceFace = faceKey;
      return failure;
    }
    for (const auto &sourceEdge : face->second.edges) {
      const auto incident = topology.incidentFaces.find(sourceEdge);
      if (incident == topology.incidentFaces.end() ||
          incident->second.size() != 1U) {
        continue;
      }
      const auto mandatory = std::find_if(
          network.mandatory_edges().begin(), network.mandatory_edges().end(),
          [&](const auto &candidate) {
            return candidate.sourceEdge == sourceEdge;
          });
      if (mandatory == network.mandatory_edges().end() ||
          boundaryMandatoryEdges.count(mandatory->id) == 0U) {
        GlobalTopologyPlanError failure = error(
            GlobalTopologyPlanErrorCode::RegionOwnedBoundaryEdgeMissingFromWalk);
        failure.region = region.id;
        failure.sourceFace = faceKey;
        failure.sourceEdge = sourceEdge;
        if (mandatory != network.mandatory_edges().end()) {
          failure.networkEdge = mandatory->id;
        }
        return failure;
      }
    }
  }

  std::set<authority::SourceVertexId> meshBoundaryVertices;
  for (const auto &[sourceEdge, incident] : topology.incidentFaces) {
    if (incident.size() != 1U) continue;
    meshBoundaryVertices.insert(sourceEdge.first());
    meshBoundaryVertices.insert(sourceEdge.second());
  }

  std::set<authority::SourceVertexId> candidateVertices;
  std::set<authority::SourceVertexId> interiorVertices;
  const std::set<authority::SourceFaceTopologyKey> regionFaces(
      region.sourceFaces.begin(), region.sourceFaces.end());
  for (const auto &faceKey : region.sourceFaces) {
    const auto face = topology.faces.find(faceKey);
    if (face == topology.faces.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.region = region.id;
      failure.sourceFace = faceKey;
      return failure;
    }
    const auto cutFace = fragmentCorners.find(faceKey);
    if (cutFace == fragmentCorners.end()) {
      candidateVertices.insert(face->second.vertices.begin(),
                               face->second.vertices.end());
      continue;
    }
    const auto fragment = cutFace->second.find(owningOrbit);
    if (fragment == cutFace->second.end()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionSourceFaceOwningFragmentMissing);
      failure.region = region.id;
      failure.sourceFace = faceKey;
      return failure;
    }
    candidateVertices.insert(fragment->second.begin(), fragment->second.end());
  }

  for (const authority::SourceVertexId vertex : candidateVertices) {
    if (meshBoundaryVertices.count(vertex) != 0U ||
        boundaryVertices.count(vertex) != 0U) {
      continue;
    }
    const auto incident = topology.incidentFacesByVertex.find(vertex);
    if (incident == topology.incidentFacesByVertex.end() ||
        incident->second.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      failure.region = region.id;
      failure.sourceVertex = vertex;
      return failure;
    }

    bool allOwned = true;
    for (const auto &incidentFace : incident->second) {
      const auto cutFace = fragmentCorners.find(incidentFace);
      if (cutFace == fragmentCorners.end()) {
        if (regionFaces.count(incidentFace) == 0U) allOwned = false;
        continue;
      }

      bool hasCornerOwner = false;
      bool ownedByRegion = false;
      bool ownedByOtherRegion = false;
      for (const auto &[orbit, corners] : cutFace->second) {
        if (corners.count(vertex) == 0U) continue;
        hasCornerOwner = true;
        if (orbit == owningOrbit) {
          ownedByRegion = true;
        } else {
          ownedByOtherRegion = true;
        }
      }
      if (!hasCornerOwner) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::RegionInteriorVertexCornerOwnerMissing);
        failure.region = region.id;
        failure.sourceFace = incidentFace;
        failure.sourceVertex = vertex;
        return failure;
      }
      if (!ownedByRegion || ownedByOtherRegion) allOwned = false;
    }
    if (allOwned) interiorVertices.insert(vertex);
  }
  certificate.vertexCount = interiorVertices.size();
  certificate.faceCount = fragments.size();
  // The validated single boundary walk and no-pinch condition give
  // V_boundary == E_boundary, so the boundary terms cancel from chi.
  certificate.eulerCharacteristic =
      static_cast<int>(certificate.vertexCount) -
      static_cast<int>(certificate.edgeCount) +
      static_cast<int>(certificate.faceCount);
  if (certificate.eulerCharacteristic != 1) {
    if (diagnostics != nullptr) {
      emit_fragment_euler_diagnostics(
          *diagnostics, region, owningOrbit, candidateVertices,
          mandatoryBoundaryEndpoints, tracePortBoundaryVertices,
          interiorVertices, certificate);
    }
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionEulerCharacteristicNotOne);
    failure.region = region.id;
    failure.eulerCharacteristic = certificate.eulerCharacteristic;
    failure.vertexCount = certificate.vertexCount;
    failure.edgeCount = certificate.edgeCount;
    failure.faceCount = certificate.faceCount;
    return failure;
  }
  return certificate;
}

using RegionCertificatesBuildResult =
    std::variant<std::vector<GlobalTopologyRegionDiscCertificate>,
                 GlobalTopologyPlanError>;

RegionCertificatesBuildResult build_region_certificates(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph,
    const CutNodeBindings &cutNodes,
    const std::vector<GlobalTopologyNodeRotation> &rotations,
    const std::vector<GlobalTopologyArc> &arcs,
    const FaceWalkResult &walk,
    const std::vector<GlobalTopologyRegion> &regions,
    const FragmentDiagnosticEvidence *diagnostics) {
  const NodeLocusResult locusBuild = build_node_loci(network, cutNodes);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&locusBuild)) {
    return *failure;
  }
  const auto &nodeLoci =
      std::get<std::map<authority::NetworkNodeId, NodeLocus>>(locusBuild);
  std::map<authority::NetworkArcId, const GlobalTopologyArc *> arcById;
  for (const auto &arc : arcs) {
    if (!arcById.emplace(arc.id, &arc).second) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.arc = arc.id;
      return failure;
    }
  }
  const FragmentCornerBuildResult cornerBuild =
      build_fragment_corner_incidence(topology, network, arcs, walk);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&cornerBuild)) {
    return *failure;
  }
  const auto &fragmentCorners =
      std::get<FragmentCornerIncidence>(cornerBuild);
  std::vector<GlobalTopologyRegionDiscCertificate> certificates;
  certificates.reserve(regions.size());
  for (const auto &region : regions) {
    const auto singularities = validate_region_interior_singularities(
        topology, network, region, arcById);
    if (const auto *failure =
            std::get_if<GlobalTopologyPlanError>(&singularities)) {
      return *failure;
    }
    if (const auto failure = validate_single_boundary_walk(region, arcById);
        failure.has_value()) {
      return *failure;
    }
    const auto orbit = region_orbit(region, walk);
    if (!orbit.has_value()) {
      GlobalTopologyPlanError failure =
          rotation_error(RotationSystemInconsistencyReason::RegionOrbitMissing);
      failure.region = region.id;
      return failure;
    }
    if (const auto pinch = validate_no_region_fragment_pinch(
            topology, nodeLoci, rotations, walk, region, *orbit);
        pinch.has_value()) {
      return *pinch;
    }
    const auto built = build_region_certificate(
        topology, network, cutGraph, arcs, region, *orbit, arcById,
        nodeLoci,
        std::get<std::vector<authority::FieldSingularityId>>(singularities),
        fragmentCorners, diagnostics);
    if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&built)) {
      return *failure;
    }
    certificates.push_back(std::get<GlobalTopologyRegionDiscCertificate>(built));
  }
  return certificates;
}

void canonicalize_candidate(GlobalTopologyPlanCandidate &candidate) {
  std::sort(candidate.arcs.begin(), candidate.arcs.end(), [](const auto &lhs,
                                                             const auto &rhs) {
    return lhs.id < rhs.id;
  });
  for (auto &rotation : candidate.rotations) {
    canonicalize_cycle(rotation.counterClockwise);
  }
  std::sort(candidate.rotations.begin(), candidate.rotations.end(),
            [](const auto &lhs, const auto &rhs) { return lhs.node < rhs.node; });
  for (auto &region : candidate.regions) {
    canonicalize_cycle(region.boundary);
    std::sort(region.sourceFaces.begin(), region.sourceFaces.end());
  }
  std::sort(candidate.regions.begin(), candidate.regions.end(),
            [](const auto &lhs, const auto &rhs) { return lhs.id < rhs.id; });
  for (auto &certificate : candidate.regionCertificates) {
    std::sort(certificate.boundarySingularities.begin(),
              certificate.boundarySingularities.end());
    certificate.boundarySingularities.erase(
        std::unique(certificate.boundarySingularities.begin(),
                    certificate.boundarySingularities.end()),
        certificate.boundarySingularities.end());
  }
  std::sort(candidate.regionCertificates.begin(), candidate.regionCertificates.end(),
            [](const auto &lhs, const auto &rhs) { return lhs.region < rhs.region; });
}

std::uint64_t candidate_semantic_digest(
    const GlobalTopologyPlanCandidate &candidate,
    const FieldAlignedCurveNetwork &network) noexcept {
  std::uint64_t hash = kFnvOffset;
  hash_consume(hash, candidate.sourceDigest);
  // cutGraphDigest and network.semantic_digest() are semantic identities.
  // Exact network/atlas provenance lives in candidate.networkDigest, while
  // exact cut-graph provenance remains on SurfaceCutGraph::provenance_digest().
  hash_consume(hash, candidate.cutGraphDigest);
  hash_consume(hash, network.semantic_digest());
  hash_consume(hash, candidate.arcs.size());
  for (const auto &arc : candidate.arcs) {
    hash_id(hash, arc.id);
    hash_consume(hash, static_cast<std::uint64_t>(arc.kind));
    hash_id(hash, arc.firstNode);
    hash_id(hash, arc.secondNode);
    hash_consume(hash, arc.mandatoryEdge.has_value());
    if (arc.mandatoryEdge.has_value()) hash_id(hash, *arc.mandatoryEdge);
    hash_consume(hash, arc.trace.has_value());
    if (arc.trace.has_value()) hash_id(hash, *arc.trace);
    hash_consume(hash, arc.cutEdge.has_value());
    if (arc.cutEdge.has_value()) hash_edge(hash, *arc.cutEdge);
    hash_consume(hash, arc.firstSegment);
    hash_consume(hash, arc.onePastLastSegment);
    hash_consume(hash, arc.sourceFaces.size());
    for (const auto &face : arc.sourceFaces) hash_face(hash, face);
  }
  hash_consume(hash, candidate.rotations.size());
  for (const auto &rotation : candidate.rotations) {
    hash_id(hash, rotation.node);
    hash_consume(hash, rotation.counterClockwise.size());
    for (const auto incidence : rotation.counterClockwise) {
      hash_id(hash, incidence.arc);
      hash_consume(hash, static_cast<std::uint64_t>(incidence.orientation));
    }
  }
  hash_consume(hash, candidate.regions.size());
  for (const auto &region : candidate.regions) {
    hash_id(hash, region.id);
    hash_consume(hash, region.boundary.size());
    for (const auto incidence : region.boundary) {
      hash_id(hash, incidence.arc);
      hash_consume(hash, static_cast<std::uint64_t>(incidence.orientation));
    }
    hash_consume(hash, region.sourceFaces.size());
    for (const auto &face : region.sourceFaces) hash_face(hash, face);
  }
  hash_consume(hash, candidate.regionCertificates.size());
  for (const auto &certificate : candidate.regionCertificates) {
    hash_id(hash, certificate.region);
    hash_consume(hash, certificate.boundaryWalkCount);
    hash_consume(hash, certificate.sourceFacesConnected);
    hash_consume(hash, static_cast<std::uint64_t>(
                           static_cast<std::int64_t>(certificate.eulerCharacteristic)));
    hash_consume(hash, certificate.vertexCount);
    hash_consume(hash, certificate.edgeCount);
    hash_consume(hash, certificate.faceCount);
    hash_consume(hash, certificate.interiorSingularityFree);
    hash_consume(hash, certificate.boundarySingularities.size());
    for (const auto singularity : certificate.boundarySingularities) {
      hash_id(hash, singularity);
    }
  }
  return hash;
}

using CandidateBuildResult =
    std::variant<GlobalTopologyPlanCandidate, GlobalTopologyPlanError>;

CandidateBuildResult canonical_candidate(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph) {
  if (network.source_digest() == 0U) {
    return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
  }
  if (!cutGraph.certificate().proves_embedded_cellularity() ||
      cutGraph.source_digest() != network.source_digest() ||
      cutGraph.network_digest() != network.semantic_digest()) {
    return error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
  }

  const auto embeddedBuild = build_embedded_graph_topology(
      sourceFaces, sourceVertexCount, sourceAuthority, network,
      cutGraph.cut_edges());
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&embeddedBuild)) {
    return *failure;
  }
  const auto &embedded = std::get<EmbeddedGraphTopology>(embeddedBuild);

  FragmentDiagnosticEvidence diagnosticEvidence;
  FragmentDiagnosticEvidence *diagnostics =
      fragment_diagnostics_enabled() ? &diagnosticEvidence : nullptr;
  TraceFragmentOwnerEvidenceDiagnostic ownerEvidence;
  const auto has_owner_deficit = [&]() {
    return std::any_of(ownerEvidence.faces.begin(), ownerEvidence.faces.end(),
                       [](const auto &face) { return face.ownerDeficit != 0U; });
  };
  const auto annotate_owner_evidence = [&](GlobalTopologyPlanError failure) {
    const auto &census = cutGraph.certificate();
    failure.embeddedGraphEulerCensusComplete = true;
    failure.embeddedGraphNodeCount = census.vertexCount;
    failure.embeddedGraphArcCount = census.edgeCount;
    failure.embeddedGraphFaceWalkOrbitCount = census.totalOrbitCount;
    failure.embeddedGraphComponentCount = census.graphComponentCount;
    failure.embeddedGraphSourceEulerCharacteristic =
        census.sourceEulerCharacteristic;
    failure.embeddedGraphEulerResidual =
        static_cast<std::int64_t>(census.vertexCount) -
        static_cast<std::int64_t>(census.edgeCount) +
        static_cast<std::int64_t>(census.totalOrbitCount) -
        static_cast<std::int64_t>(census.sourceEulerCharacteristic);
    // The high-side mismatch keeps the byte-identical CB20 failure envelope.
    // Low-side evidence is observational and follows only later failures.
    if (failure.code !=
            GlobalTopologyPlanErrorCode::TraceCutFaceFragmentCountMismatch &&
        (has_owner_deficit() ||
         failure.code ==
             GlobalTopologyPlanErrorCode::UncutFaceComponentOrbitSeedNotUnique)) {
      failure.fragmentOwnerEvidence = ownerEvidence;
    }
    return failure;
  };
  const RegionBuildResult regionBuild = build_regions(
      embedded.sourceTopology, sourceAuthority, network, cutGraph,
      embedded.arcs, embedded.faceWalk, diagnostics, &ownerEvidence);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&regionBuild)) {
    return annotate_owner_evidence(*failure);
  }

  const auto &regionSuccess = std::get<RegionBuildSuccess>(regionBuild);
  GlobalTopologyPlanCandidate candidate;
  candidate.arcs = embedded.arcs;
  candidate.rotations = embedded.rotations;
  candidate.regions = regionSuccess.regions;
  const RegionCertificatesBuildResult certificateBuild =
      build_region_certificates(embedded.sourceTopology, network, cutGraph,
                                embedded.cutNodes, candidate.rotations,
                                candidate.arcs, embedded.faceWalk,
                                candidate.regions, diagnostics);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&certificateBuild)) {
    GlobalTopologyPlanError annotated = *failure;
    annotate_region_frontier_evidence(
        annotated, RegionFrontierFailureStage::RegionCertification,
        regionSuccess.frontier, cutGraph.certificate(), &candidate.regions);
    return annotate_owner_evidence(std::move(annotated));
  }
  candidate.regionCertificates =
      std::get<std::vector<GlobalTopologyRegionDiscCertificate>>(certificateBuild);
  candidate.sourceDigest = network.source_digest();
  candidate.networkDigest = network_binding_digest(network);
  candidate.cutGraphDigest = cutGraph.semantic_digest();
  candidate.fragmentOwnerEvidence = std::move(ownerEvidence);
  canonicalize_candidate(candidate);
  return candidate;
}

std::optional<GlobalTopologyPlanError> validate_candidate_structure(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph,
    GlobalTopologyPlanCandidate &candidate) {
  const auto topology =
      build_source_index(sourceFaces, sourceVertexCount, sourceAuthority);
  if (!topology.has_value() || candidate.sourceDigest != network.source_digest()) {
    return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
  }
  if (candidate.networkDigest != network_binding_digest(network)) {
    return error(GlobalTopologyPlanErrorCode::InvalidNetworkBinding);
  }
  if (candidate.cutGraphDigest != cutGraph.semantic_digest() ||
      !cutGraph.certificate().proves_cellularity()) {
    return error(GlobalTopologyPlanErrorCode::InvalidCutGraphBinding);
  }
  canonicalize_candidate(candidate);

  std::map<authority::NetworkArcId, const GlobalTopologyArc *> arcById;
  for (const auto &arc : candidate.arcs) {
    if (!arcById.emplace(arc.id, &arc).second) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
      failure.arc = arc.id;
      return failure;
    }
  }
  for (const auto &region : candidate.regions) {
    if (region.sourceFaces.empty()) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionCoversNoSourceFace);
      failure.region = region.id;
      return failure;
    }
    for (const auto incidence : region.boundary) {
      if (arcById.count(incidence.arc) == 0U) {
        GlobalTopologyPlanError failure = error(
            GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
        failure.region = region.id;
        failure.arc = incidence.arc;
        return failure;
      }
    }
  }

  // sourceFaces is the public support key for one fragment in this region;
  // the owning orbit is implicit in the region boundary. A crossed source face
  // therefore appears in more than one region by design. Structural validation
  // checks total source support here, then the canonical reconstruction below
  // proves the exact (SourceFaceTopologyKey, orbit) fragment assignment.
  std::set<authority::SourceFaceTopologyKey> coveredFaces;
  for (const auto &region : candidate.regions) {
    for (const auto &face : region.sourceFaces) {
      if (topology->faces.count(face) == 0U) {
        GlobalTopologyPlanError failure =
            error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
        failure.sourceFace = face;
        return failure;
      }
      coveredFaces.insert(face);
    }
  }
  for (const auto &[face, record] : topology->faces) {
    (void)record;
    if (coveredFaces.count(face) == 0U) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned);
      failure.sourceFace = face;
      return failure;
    }
  }

  const CandidateBuildResult canonical = canonical_candidate(
      sourceFaces, sourceVertexCount, sourceAuthority, network, cutGraph);
  if (const auto *failure = std::get_if<GlobalTopologyPlanError>(&canonical)) {
    return *failure;
  }
  GlobalTopologyPlanCandidate wanted =
      std::get<GlobalTopologyPlanCandidate>(canonical);
  canonicalize_candidate(wanted);

  bool canonicalRegionBoundaries =
      candidate.regions.size() == wanted.regions.size();
  if (canonicalRegionBoundaries) {
    for (std::size_t index = 0U; index < candidate.regions.size(); ++index) {
      if (candidate.regions[index].id != wanted.regions[index].id ||
          candidate.regions[index].boundary != wanted.regions[index].boundary) {
        canonicalRegionBoundaries = false;
        break;
      }
    }
  }
  if (canonicalRegionBoundaries) {
    for (std::size_t index = 0U; index < candidate.regions.size(); ++index) {
      // Exact canonical fragment ownership is part of the immutable construction
      // contract. The region identifies the orbit, so each sourceFaces element is
      // one (SourceFaceTopologyKey, orbit) fragment key.
      if (candidate.regions[index].sourceFaces !=
          wanted.regions[index].sourceFaces) {
        for (const auto &face : wanted.regions[index].sourceFaces) {
          if (!std::binary_search(candidate.regions[index].sourceFaces.begin(),
                                  candidate.regions[index].sourceFaces.end(),
                                  face)) {
            GlobalTopologyPlanError failure =
                error(GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned);
            failure.sourceFace = face;
            failure.region = wanted.regions[index].id;
            return failure;
          }
        }
        for (const auto &face : candidate.regions[index].sourceFaces) {
          if (!std::binary_search(wanted.regions[index].sourceFaces.begin(),
                                  wanted.regions[index].sourceFaces.end(),
                                  face)) {
            GlobalTopologyPlanError failure = error(
                GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned);
            failure.sourceFace = face;
            failure.region = candidate.regions[index].id;
            return failure;
          }
        }
        const auto duplicate = std::adjacent_find(
            candidate.regions[index].sourceFaces.begin(),
            candidate.regions[index].sourceFaces.end());
        if (duplicate != candidate.regions[index].sourceFaces.end()) {
          GlobalTopologyPlanError failure = error(
              GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned);
          failure.sourceFace = *duplicate;
          failure.region = candidate.regions[index].id;
          return failure;
        }
        return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
      }
    }
  }

  const auto validationCutNodes =
      build_cut_node_bindings(network, cutGraph.cut_edges());
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&validationCutNodes)) {
    return *failure;
  }
  const auto validationFaceWalk =
      walk_graph_faces(candidate.arcs, candidate.rotations);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&validationFaceWalk)) {
    return *failure;
  }
  const RegionCertificatesBuildResult certificateBuild =
      build_region_certificates(
          *topology, network, cutGraph,
          std::get<CutNodeBindings>(validationCutNodes), candidate.rotations,
          candidate.arcs, std::get<FaceWalkResult>(validationFaceWalk),
          candidate.regions, nullptr);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&certificateBuild)) {
    return *failure;
  }
  auto expectedCertificates =
      std::get<std::vector<GlobalTopologyRegionDiscCertificate>>(certificateBuild);
  std::sort(expectedCertificates.begin(), expectedCertificates.end(),
            [](const auto &lhs, const auto &rhs) { return lhs.region < rhs.region; });
  if (candidate.regionCertificates.size() != expectedCertificates.size()) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::InvalidRegionCertificateBinding);
    if (!candidate.regionCertificates.empty()) {
      failure.region = candidate.regionCertificates.front().region;
    } else if (!candidate.regions.empty()) {
      failure.region = candidate.regions.front().id;
    }
    return failure;
  }
  for (std::size_t index = 0U; index < expectedCertificates.size(); ++index) {
    if (candidate.regionCertificates[index] != expectedCertificates[index]) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::InvalidRegionCertificateBinding);
      failure.region = expectedCertificates[index].region;
      return failure;
    }
  }

  for (const auto &mandatory : network.mandatory_edges()) {
    std::vector<authority::NetworkArcId> pieces;
    for (const auto &candidateArc : candidate.arcs) {
      if (candidateArc.kind == GlobalTopologyArcKind::Mandatory &&
          candidateArc.mandatoryEdge == mandatory.id) {
        pieces.push_back(candidateArc.id);
      }
    }
    if (pieces.empty()) {
      GlobalTopologyPlanError failure = error(
          GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary);
      failure.networkEdge = mandatory.id;
      failure.sourceEdge = mandatory.sourceEdge;
      return failure;
    }
    for (const authority::NetworkArcId piece : pieces) {
      const bool represented = std::any_of(
          candidate.regions.begin(), candidate.regions.end(),
          [&](const auto &region) {
            return std::any_of(region.boundary.begin(), region.boundary.end(),
                               [&](const auto incidence) {
                                 return incidence.arc == piece;
                               });
          });
      if (!represented) {
        GlobalTopologyPlanError failure = error(
            GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary);
        failure.networkEdge = mandatory.id;
        failure.sourceEdge = mandatory.sourceEdge;
        failure.arc = piece;
        return failure;
      }
    }
  }

  if (candidate.arcs != wanted.arcs) {
    GlobalTopologyPlanError failure =
        error(GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork);
    if (!candidate.arcs.empty()) failure.arc = candidate.arcs.front().id;
    return failure;
  }
  if (candidate.rotations != wanted.rotations) {
    GlobalTopologyPlanError failure =
        rotation_error(RotationSystemInconsistencyReason::CandidateRotationSystemMismatch);
    if (!candidate.rotations.empty()) {
      failure.arc = candidate.rotations.front().counterClockwise.empty()
                        ? std::optional<authority::NetworkArcId>{}
                        : std::optional<authority::NetworkArcId>{
                              candidate.rotations.front().counterClockwise.front().arc};
    }
    return failure;
  }
  if (candidate.regions.size() != wanted.regions.size()) {
    return error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
  }
  for (std::size_t index = 0U; index < candidate.regions.size(); ++index) {
    if (candidate.regions[index].id != wanted.regions[index].id ||
        candidate.regions[index].boundary != wanted.regions[index].boundary) {
      GlobalTopologyPlanError failure =
          error(GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk);
      failure.region = candidate.regions[index].id;
      if (!candidate.regions[index].boundary.empty()) {
        failure.arc = candidate.regions[index].boundary.front().arc;
      }
      return failure;
    }
    // Exact canonical fragment ownership is part of the immutable construction
    // contract. The region identifies the orbit, so each sourceFaces element is
    // one (SourceFaceTopologyKey, orbit) fragment key.
    if (candidate.regions[index].sourceFaces !=
        wanted.regions[index].sourceFaces) {
      for (const auto &face : wanted.regions[index].sourceFaces) {
        if (!std::binary_search(candidate.regions[index].sourceFaces.begin(),
                                candidate.regions[index].sourceFaces.end(),
                                face)) {
          GlobalTopologyPlanError failure =
              error(GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned);
          failure.sourceFace = face;
          failure.region = wanted.regions[index].id;
          return failure;
        }
      }
      for (const auto &face : candidate.regions[index].sourceFaces) {
        if (!std::binary_search(wanted.regions[index].sourceFaces.begin(),
                                wanted.regions[index].sourceFaces.end(),
                                face)) {
          GlobalTopologyPlanError failure = error(
              GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned);
          failure.sourceFace = face;
          failure.region = candidate.regions[index].id;
          return failure;
        }
      }
      const auto duplicate = std::adjacent_find(
          candidate.regions[index].sourceFaces.begin(),
          candidate.regions[index].sourceFaces.end());
      if (duplicate != candidate.regions[index].sourceFaces.end()) {
        GlobalTopologyPlanError failure = error(
            GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned);
        failure.sourceFace = *duplicate;
        failure.region = candidate.regions[index].id;
        return failure;
      }
      return error(GlobalTopologyPlanErrorCode::InvalidSourceBinding);
    }
  }
  return std::nullopt;
}

} // namespace
} // namespace directional::geometry::global_topology_plan_detail

namespace directional::geometry {

GlobalTopologyPlanBuildResult GlobalTopologyPlan::make(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const SurfaceCutGraph &cutGraph) {
  const auto canonical = global_topology_plan_detail::canonical_candidate(
      sourceFaces, sourceVertexCount, sourceAuthority, network, cutGraph);
  if (const auto *failure =
          std::get_if<GlobalTopologyPlanError>(&canonical)) {
    return GlobalTopologyPlanBuildResult(*failure);
  }
  return make_from_candidate(
      sourceFaces, sourceVertexCount, sourceAuthority, network, cutGraph,
      std::get<GlobalTopologyPlanCandidate>(canonical));
}

GlobalTopologyPlanBuildResult GlobalTopologyPlan::make_from_candidate(
    const Eigen::MatrixXi &sourceFaces, const std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network, const SurfaceCutGraph &cutGraph,
    GlobalTopologyPlanCandidate candidate) {
  if (const auto failure =
          global_topology_plan_detail::validate_candidate_structure(
              sourceFaces, sourceVertexCount, sourceAuthority, network, cutGraph,
              candidate);
      failure.has_value()) {
    return GlobalTopologyPlanBuildResult(*failure);
  }
  const std::uint64_t semanticDigest =
      global_topology_plan_detail::candidate_semantic_digest(candidate, network);
  return GlobalTopologyPlanBuildResult(GlobalTopologyPlan(
      std::move(candidate.arcs), std::move(candidate.rotations),
      std::move(candidate.regions), std::move(candidate.regionCertificates),
      candidate.sourceDigest, candidate.networkDigest, candidate.cutGraphDigest,
      semanticDigest, std::move(candidate.fragmentOwnerEvidence)));
}

const GlobalTopologyArc *
GlobalTopologyPlan::find_arc(const authority::NetworkArcId arc) const noexcept {
  const auto found = std::lower_bound(
      arcs_.begin(), arcs_.end(), arc,
      [](const GlobalTopologyArc &candidate, const authority::NetworkArcId id) {
        return candidate.id < id;
      });
  return found != arcs_.end() && found->id == arc ? &*found : nullptr;
}

const GlobalTopologyNodeRotation *GlobalTopologyPlan::find_rotation(
    const authority::NetworkNodeId node) const noexcept {
  const auto found = std::lower_bound(
      rotations_.begin(), rotations_.end(), node,
      [](const GlobalTopologyNodeRotation &candidate,
         const authority::NetworkNodeId id) { return candidate.node < id; });
  return found != rotations_.end() && found->node == node ? &*found : nullptr;
}

const GlobalTopologyRegionDiscCertificate *
GlobalTopologyPlan::find_region_certificate(
    const authority::NetworkRegionId region) const noexcept {
  const auto found = std::lower_bound(
      regionCertificates_.begin(), regionCertificates_.end(), region,
      [](const GlobalTopologyRegionDiscCertificate &candidate,
         const authority::NetworkRegionId id) { return candidate.region < id; });
  return found != regionCertificates_.end() && found->region == region
             ? &*found
             : nullptr;
}

GlobalTopologyPlanCandidate GlobalTopologyPlan::validation_candidate() const {
  return GlobalTopologyPlanCandidate{arcs_, rotations_, regions_,
                                     regionCertificates_, sourceDigest_,
                                     networkDigest_, cutGraphDigest_,
                                     fragmentOwnerEvidence_};
}

const char *global_topology_plan_error_code_name(
    const GlobalTopologyPlanErrorCode code) noexcept {
  switch (code) {
  case GlobalTopologyPlanErrorCode::RegionBoundaryNotSingleWalk:
    return "RegionBoundaryNotSingleWalk";
  case GlobalTopologyPlanErrorCode::RegionInteriorDisconnected:
    return "RegionInteriorDisconnected";
  case GlobalTopologyPlanErrorCode::RegionEulerCharacteristicNotOne:
    return "RegionEulerCharacteristicNotOne";
  case GlobalTopologyPlanErrorCode::RegionContainsInteriorSingularity:
    return "RegionContainsInteriorSingularity";
  case GlobalTopologyPlanErrorCode::RegionCoversNoSourceFace:
    return "RegionCoversNoSourceFace";
  case GlobalTopologyPlanErrorCode::RegionSourceFaceUnowned:
    return "RegionSourceFaceUnowned";
  case GlobalTopologyPlanErrorCode::RegionSourceFaceMultiplyOwned:
    return "RegionSourceFaceMultiplyOwned";
  case GlobalTopologyPlanErrorCode::RegionBoundaryArcNotOwnedByNetwork:
    return "RegionBoundaryArcNotOwnedByNetwork";
  case GlobalTopologyPlanErrorCode::MandatoryEdgeNotOnAnyRegionBoundary:
    return "MandatoryEdgeNotOnAnyRegionBoundary";
  case GlobalTopologyPlanErrorCode::RotationSystemInconsistent:
    return "RotationSystemInconsistent";
  case GlobalTopologyPlanErrorCode::InvalidNetworkBinding:
    return "InvalidNetworkBinding";
  case GlobalTopologyPlanErrorCode::InvalidSourceBinding:
    return "InvalidSourceBinding";
  case GlobalTopologyPlanErrorCode::InvalidRegionCertificateBinding:
    return "InvalidRegionCertificateBinding";
  case GlobalTopologyPlanErrorCode::EmbeddedGraphHasNoInteriorFace:
    return "EmbeddedGraphHasNoInteriorFace";
  case GlobalTopologyPlanErrorCode::RegionCutComponentCountDeficit:
    return "RegionCutComponentCountDeficit";
  case GlobalTopologyPlanErrorCode::TraceArcDoesNotSeparateItsSides:
    return "TraceArcDoesNotSeparateItsSides";
  case GlobalTopologyPlanErrorCode::SourceFaceCarriesMultipleTraceCuts:
    return "SourceFaceCarriesMultipleTraceCuts";
  case GlobalTopologyPlanErrorCode::TraceSegmentCarriersCoincide:
    return "TraceSegmentCarriersCoincide";
  case GlobalTopologyPlanErrorCode::TraceSegmentTurnNotAdmissible:
    return "TraceSegmentTurnNotAdmissible";
  case GlobalTopologyPlanErrorCode::TraceSegmentCarriersShareMultipleCorners:
    return "TraceSegmentCarriersShareMultipleCorners";
  case GlobalTopologyPlanErrorCode::TraceSegmentCarriersShareNoCorner:
    return "TraceSegmentCarriersShareNoCorner";
  case GlobalTopologyPlanErrorCode::SourcePortFaceAlreadyCarriesTraceChord:
    return "SourcePortFaceAlreadyCarriesTraceChord";
  case GlobalTopologyPlanErrorCode::TraceSourcePortCarrierNotAdmissible:
    return "TraceSourcePortCarrierNotAdmissible";
  case GlobalTopologyPlanErrorCode::SourceFaceCarriesTraceChordAndRays:
    return "SourceFaceCarriesTraceChordAndRays";
  case GlobalTopologyPlanErrorCode::RegionTraceSegmentCarriersCoincide:
    return "RegionTraceSegmentCarriersCoincide";
  case GlobalTopologyPlanErrorCode::RegionTraceSegmentTurnNotAdmissible:
    return "RegionTraceSegmentTurnNotAdmissible";
  case GlobalTopologyPlanErrorCode::RegionTraceSourcePortCarrierNotAdmissible:
    return "RegionTraceSourcePortCarrierNotAdmissible";
  case GlobalTopologyPlanErrorCode::TraceCutFaceFragmentCountMismatch:
    return "TraceCutFaceFragmentCountMismatch";
  case GlobalTopologyPlanErrorCode::UncutFaceComponentOrbitSeedNotUnique:
    return "UncutFaceComponentOrbitSeedNotUnique";
  case GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitMissing:
    return "SourceFaceFragmentOrbitMissing";
  case GlobalTopologyPlanErrorCode::SourceFaceFragmentOrbitHasNoRegionDraft:
    return "SourceFaceFragmentOrbitHasNoRegionDraft";
  case GlobalTopologyPlanErrorCode::RegionSourceFaceOwningFragmentMissing:
    return "RegionSourceFaceOwningFragmentMissing";
  case GlobalTopologyPlanErrorCode::RegionInteriorVertexCornerOwnerMissing:
    return "RegionInteriorVertexCornerOwnerMissing";
  case GlobalTopologyPlanErrorCode::RegionBoundaryEvidenceMissing:
    return "RegionBoundaryEvidenceMissing";
  case GlobalTopologyPlanErrorCode::RegionElectedCutComponentEmpty:
    return "RegionElectedCutComponentEmpty";
  case GlobalTopologyPlanErrorCode::RegionFragmentPinchedAtVertex:
    return "RegionFragmentPinchedAtVertex";
  case GlobalTopologyPlanErrorCode::MandatoryEdgeTerminalOrderUnresolved:
    return "MandatoryEdgeTerminalOrderUnresolved";
  case GlobalTopologyPlanErrorCode::RegionOwnedBoundaryEdgeMissingFromWalk:
    return "RegionOwnedBoundaryEdgeMissingFromWalk";
  case GlobalTopologyPlanErrorCode::InvalidCutGraphBinding:
    return "InvalidCutGraphBinding";
  }
  return "Unknown";
}

const char *uncut_face_component_seed_state_name(
    const UncutFaceComponentSeedState state) noexcept {
  switch (state) {
  case UncutFaceComponentSeedState::None:
    return "None";
  case UncutFaceComponentSeedState::Unique:
    return "Unique";
  case UncutFaceComponentSeedState::Multiple:
    return "Multiple";
  }
  return "Unknown";
}

const char *region_frontier_failure_stage_name(
    const RegionFrontierFailureStage stage) noexcept {
  switch (stage) {
  case RegionFrontierFailureStage::UncutComponent:
    return "UncutComponent";
  case RegionFrontierFailureStage::RegionConstruction:
    return "RegionConstruction";
  case RegionFrontierFailureStage::RegionCertification:
    return "RegionCertification";
  }
  return "Unknown";
}

const char *region_frontier_census_correspondence_name(
    const RegionFrontierCensusCorrespondence correspondence) noexcept {
  switch (correspondence) {
  case RegionFrontierCensusCorrespondence::None:
    return "None";
  case RegionFrontierCensusCorrespondence::Exact:
    return "Exact";
  case RegionFrontierCensusCorrespondence::Superset:
    return "Superset";
  }
  return "Unknown";
}

const char *uncut_face_component_barrier_class_name(
    const UncutFaceComponentBarrierClass barrierClass) noexcept {
  switch (barrierClass) {
  case UncutFaceComponentBarrierClass::None:
    return "none";
  case UncutFaceComponentBarrierClass::Mandatory:
    return "mandatory";
  case UncutFaceComponentBarrierClass::Cut:
    return "cut";
  case UncutFaceComponentBarrierClass::TraceTouched:
    return "traceTouched";
  }
  return "unknown";
}

const char *uncut_face_component_no_seed_reason_name(
    const UncutFaceComponentNoSeedReason reason) noexcept {
  switch (reason) {
  case UncutFaceComponentNoSeedReason::IncidentFaceCountNotTwo:
    return "incidentFaceCountNotTwo";
  case UncutFaceComponentNoSeedReason::Barrier:
    return "barrier";
  case UncutFaceComponentNoSeedReason::OtherSideUnlabeled:
    return "otherSideUnlabeled";
  case UncutFaceComponentNoSeedReason::LabeledFaceHasNoOwner:
    return "labeledFaceHasNoOwner";
  case UncutFaceComponentNoSeedReason::EdgeOrbitEvidenceMissing:
    return "edgeOrbitEvidenceMissing";
  case UncutFaceComponentNoSeedReason::EdgeOrbitEvidenceNotUnique:
    return "edgeOrbitEvidenceNotUnique";
  }
  return "unknown";
}

const char *uncut_face_component_seed_rule_name(
    const UncutFaceComponentSeedRule rule) noexcept {
  switch (rule) {
  case UncutFaceComponentSeedRule::SingleFaceOwner:
    return "singleFaceOwner";
  case UncutFaceComponentSeedRule::EdgeOrbitEvidence:
    return "edgeOrbitEvidence";
  }
  return "unknown";
}

const char *uncut_face_source_face_locus_kind_name(
    const UncutFaceSourceFaceLocusKind kind) noexcept {
  switch (kind) {
  case UncutFaceSourceFaceLocusKind::FirstUnlabeledFaceInIterationOrder:
    return "FirstUnlabeledFaceInIterationOrder";
  }
  return "Unknown";
}

const char *rotation_system_inconsistency_reason_name(
    const RotationSystemInconsistencyReason reason) noexcept {
  switch (reason) {
  case RotationSystemInconsistencyReason::TraceEventPositionInvalid:
    return "TraceEventPositionInvalid";
  case RotationSystemInconsistencyReason::TraceEventPositionNodeConflict:
    return "TraceEventPositionNodeConflict";
  case RotationSystemInconsistencyReason::EventNodeLocusMissing:
    return "EventNodeLocusMissing";
  case RotationSystemInconsistencyReason::EventLocusMissingSourceEdge:
    return "EventLocusMissingSourceEdge";
  case RotationSystemInconsistencyReason::EventLocusSourceEdgeConflict:
    return "EventLocusSourceEdgeConflict";
  case RotationSystemInconsistencyReason::VertexTraceFaceMissingFromFan:
    return "VertexTraceFaceMissingFromFan";
  case RotationSystemInconsistencyReason::VertexTracePortOrdinalInvalid:
    return "VertexTracePortOrdinalInvalid";
  case RotationSystemInconsistencyReason::EdgeTraceFaceSideInvalid:
    return "EdgeTraceFaceSideInvalid";
  case RotationSystemInconsistencyReason::EdgeTraceSecondaryRankInvalid:
    return "EdgeTraceSecondaryRankInvalid";
  case RotationSystemInconsistencyReason::ArcTraceOriginPortMissing:
    return "ArcTraceOriginPortMissing";
  case RotationSystemInconsistencyReason::ArcTraceSegmentsEmpty:
    return "ArcTraceSegmentsEmpty";
  case RotationSystemInconsistencyReason::ArcTraceTerminalEventMissing:
    return "ArcTraceTerminalEventMissing";
  case RotationSystemInconsistencyReason::ArcTraceTerminalCutPositionMismatch:
    return "ArcTraceTerminalCutPositionMismatch";
  case RotationSystemInconsistencyReason::NodeLocusRegistrationMissing:
    return "NodeLocusRegistrationMissing";
  case RotationSystemInconsistencyReason::NodeLocusSourceVertexConflict:
    return "NodeLocusSourceVertexConflict";
  case RotationSystemInconsistencyReason::RotationNodeOutgoingIncidenceEmpty:
    return "RotationNodeOutgoingIncidenceEmpty";
  case RotationSystemInconsistencyReason::RotationNodeLocusMissing:
    return "RotationNodeLocusMissing";
  case RotationSystemInconsistencyReason::RotationVertexFanSlotsUnavailable:
    return "RotationVertexFanSlotsUnavailable";
  case RotationSystemInconsistencyReason::RotationVertexArcBindingMissing:
    return "RotationVertexArcBindingMissing";
  case RotationSystemInconsistencyReason::RotationVertexMandatoryArcMissingNetworkEdge:
    return "RotationVertexMandatoryArcMissingNetworkEdge";
  case RotationSystemInconsistencyReason::RotationVertexMandatoryNetworkEdgeMissing:
    return "RotationVertexMandatoryNetworkEdgeMissing";
  case RotationSystemInconsistencyReason::RotationVertexSourceEdgeMissingFromFan:
    return "RotationVertexSourceEdgeMissingFromFan";
  case RotationSystemInconsistencyReason::RotationVertexTraceBindingMissing:
    return "RotationVertexTraceBindingMissing";
  case RotationSystemInconsistencyReason::RotationVertexTraceMissing:
    return "RotationVertexTraceMissing";
  case RotationSystemInconsistencyReason::RotationVertexTraceRayFaceUnavailable:
    return "RotationVertexTraceRayFaceUnavailable";
  case RotationSystemInconsistencyReason::RotationEdgeIncidentFacesMissing:
    return "RotationEdgeIncidentFacesMissing";
  case RotationSystemInconsistencyReason::RotationEdgeIncidentFacesEmpty:
    return "RotationEdgeIncidentFacesEmpty";
  case RotationSystemInconsistencyReason::RotationEdgeSourceFaceMissing:
    return "RotationEdgeSourceFaceMissing";
  case RotationSystemInconsistencyReason::RotationEdgeRayCountInvalid:
    return "RotationEdgeRayCountInvalid";
  case RotationSystemInconsistencyReason::RotationEdgeRayValenceInvalid:
    return "RotationEdgeRayValenceInvalid";
  case RotationSystemInconsistencyReason::RotationEdgeArcBindingMissing:
    return "RotationEdgeArcBindingMissing";
  case RotationSystemInconsistencyReason::RotationEdgeNonTraceArcRequiresTwoRays:
    return "RotationEdgeNonTraceArcRequiresTwoRays";
  case RotationSystemInconsistencyReason::RotationEdgeMandatoryArcMissingNetworkEdge:
    return "RotationEdgeMandatoryArcMissingNetworkEdge";
  case RotationSystemInconsistencyReason::RotationEdgeCutArcLocusMismatch:
    return "RotationEdgeCutArcLocusMismatch";
  case RotationSystemInconsistencyReason::RotationEdgeRayEndpointDirectionUnavailable:
    return "RotationEdgeRayEndpointDirectionUnavailable";
  case RotationSystemInconsistencyReason::RotationEdgeTraceBindingMissing:
    return "RotationEdgeTraceBindingMissing";
  case RotationSystemInconsistencyReason::RotationEdgeTraceMissing:
    return "RotationEdgeTraceMissing";
  case RotationSystemInconsistencyReason::RotationNodeLocusUnsupported:
    return "RotationNodeLocusUnsupported";
  case RotationSystemInconsistencyReason::RotationRayOrderKeyCollision:
    return "RotationRayOrderKeyCollision";
  case RotationSystemInconsistencyReason::FaceWalkArcSetEmpty:
    return "FaceWalkArcSetEmpty";
  case RotationSystemInconsistencyReason::FaceWalkNodeRotationEmpty:
    return "FaceWalkNodeRotationEmpty";
  case RotationSystemInconsistencyReason::FaceWalkRotationDartOutOfRange:
    return "FaceWalkRotationDartOutOfRange";
  case RotationSystemInconsistencyReason::FaceWalkSuccessorAlreadyAssigned:
    return "FaceWalkSuccessorAlreadyAssigned";
  case RotationSystemInconsistencyReason::FaceWalkIncidenceCountInvalid:
    return "FaceWalkIncidenceCountInvalid";
  case RotationSystemInconsistencyReason::FaceWalkSuccessorMissing:
    return "FaceWalkSuccessorMissing";
  case RotationSystemInconsistencyReason::FaceWalkCurrentDartOutOfRange:
    return "FaceWalkCurrentDartOutOfRange";
  case RotationSystemInconsistencyReason::FaceWalkOrbitReenteredAtDifferentStart:
    return "FaceWalkOrbitReenteredAtDifferentStart";
  case RotationSystemInconsistencyReason::FaceWalkCycleDidNotCloseWithinDartBudget:
    return "FaceWalkCycleDidNotCloseWithinDartBudget";
  case RotationSystemInconsistencyReason::FaceWalkBoundaryEmpty:
    return "FaceWalkBoundaryEmpty";
  case RotationSystemInconsistencyReason::ExteriorBoundaryDartOutOfRange:
    return "ExteriorBoundaryDartOutOfRange";
  case RotationSystemInconsistencyReason::FragmentCornerForwardDartOutOfRange:
    return "FragmentCornerForwardDartOutOfRange";
  case RotationSystemInconsistencyReason::FragmentCornerReverseDartOutOfRange:
    return "FragmentCornerReverseDartOutOfRange";
  case RotationSystemInconsistencyReason::FragmentCornerSourceCornerMismatch:
    return "FragmentCornerSourceCornerMismatch";
  case RotationSystemInconsistencyReason::FragmentCornerRayOrdinalDuplicate:
    return "FragmentCornerRayOrdinalDuplicate";
  case RotationSystemInconsistencyReason::FragmentCornerOrbitChainMismatch:
    return "FragmentCornerOrbitChainMismatch";
  case RotationSystemInconsistencyReason::MandatoryBoundaryInteriorDartOutOfRange:
    return "MandatoryBoundaryInteriorDartOutOfRange";
  case RotationSystemInconsistencyReason::CutBoundaryInteriorDartOutOfRange:
    return "CutBoundaryInteriorDartOutOfRange";
  case RotationSystemInconsistencyReason::TraceBoundaryForwardDartOutOfRange:
    return "TraceBoundaryForwardDartOutOfRange";
  case RotationSystemInconsistencyReason::TraceBoundaryReverseDartOutOfRange:
    return "TraceBoundaryReverseDartOutOfRange";
  case RotationSystemInconsistencyReason::RegionFragmentIncomingDartOutOfRange:
    return "RegionFragmentIncomingDartOutOfRange";
  case RotationSystemInconsistencyReason::RegionOrbitMissing:
    return "RegionOrbitMissing";
  case RotationSystemInconsistencyReason::CandidateRotationSystemMismatch:
    return "CandidateRotationSystemMismatch";
  case RotationSystemInconsistencyReason::RotationVertexTraceRaysExactlyCoincident:
    return "RotationVertexTraceRaysExactlyCoincident";
  case RotationSystemInconsistencyReason::VertexTraceSecondaryParameterUnavailable:
    return "VertexTraceSecondaryParameterUnavailable";
  }
  return "Unknown";
}

const char *vertex_trace_secondary_parameter_failure_reason_name(
    const VertexTraceSecondaryParameterFailureReason reason) noexcept {
  switch (reason) {
  case VertexTraceSecondaryParameterFailureReason::TraceRayFaceUnavailable:
    return "TraceRayFaceUnavailable";
  case VertexTraceSecondaryParameterFailureReason::SourceFaceRecordUnavailable:
    return "SourceFaceRecordUnavailable";
  case VertexTraceSecondaryParameterFailureReason::LocusCornerUnavailable:
    return "LocusCornerUnavailable";
  case VertexTraceSecondaryParameterFailureReason::SecondPointUnavailable:
    return "SecondPointUnavailable";
  case VertexTraceSecondaryParameterFailureReason::InvalidDenominator:
    return "InvalidDenominator";
  }
  return "Unknown";
}

const char *edge_trace_secondary_rank_failure_reason_name(
    const EdgeTraceSecondaryRankFailureReason reason) noexcept {
  switch (reason) {
  case EdgeTraceSecondaryRankFailureReason::TraceRayFaceUnavailable:
    return "TraceRayFaceUnavailable";
  case EdgeTraceSecondaryRankFailureReason::SourceFaceRecordUnavailable:
    return "SourceFaceRecordUnavailable";
  case EdgeTraceSecondaryRankFailureReason::ContactEdgeUnavailable:
    return "ContactEdgeUnavailable";
  case EdgeTraceSecondaryRankFailureReason::OppositeCarrierNotInFace:
    return "OppositeCarrierNotInFace";
  case EdgeTraceSecondaryRankFailureReason::CoincidentLocalEdgeIndex:
    return "CoincidentLocalEdgeIndex";
  case EdgeTraceSecondaryRankFailureReason::SourceVertexFallbackUnbound:
    return "SourceVertexFallbackUnbound";
  }
  return "Unknown";
}

const char *trace_event_position_failure_reason_name(
    const TraceEventPositionFailureReason reason) noexcept {
  switch (reason) {
  case TraceEventPositionFailureReason::NoCarrierMatch:
    return "NoCarrierMatch";
  case TraceEventPositionFailureReason::AmbiguousCarrierMatch:
    return "AmbiguousCarrierMatch";
  }
  return "Unknown";
}

const char *trace_event_position_pass_name(
    const TraceEventPositionPass pass) noexcept {
  switch (pass) {
  case TraceEventPositionPass::FaceRestricted:
    return "FaceRestricted";
  case TraceEventPositionPass::WideningFallback:
    return "WideningFallback";
  case TraceEventPositionPass::SourceEdgeUnavailable:
    return "SourceEdgeUnavailable";
  }
  return "Unknown";
}

const char *trace_event_position_carrier_role_name(
    const TraceEventPositionCarrierRole role) noexcept {
  switch (role) {
  case TraceEventPositionCarrierRole::Incoming:
    return "Incoming";
  case TraceEventPositionCarrierRole::Outgoing:
    return "Outgoing";
  }
  return "Unknown";
}

const char *trace_corner_binding_provenance_name(
    const TraceCornerBindingProvenance provenance) noexcept {
  switch (provenance) {
  case TraceCornerBindingProvenance::TraceOrigin:
    return "TraceOrigin";
  case TraceCornerBindingProvenance::SegmentEntrySupport:
    return "SegmentEntrySupport";
  }
  return "Unknown";
}

std::uint64_t global_topology_plan_hash(
    const GlobalTopologyPlan &plan) noexcept {
  return plan.semantic_digest();
}

} // namespace directional::geometry
