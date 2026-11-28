#include <directional/geometry/GlobalConformityBaseline.h>

#include "EmbeddedGraphTopology.h"

#include <map>
#include <optional>
#include <vector>

// The A4 corner reading of the A3 region boundary schedule. It is kept out of
// GlobalConformityBaseline.cpp, whose parity binder stays free of arc kinds.

namespace directional::geometry {

const char *region_corner_sides_failure_reason_name(
    RegionCornerSidesFailureReason reason) noexcept {
  switch (reason) {
  case RegionCornerSidesFailureReason::TopologyPlanMismatch:
    return "topology-plan-mismatch";
  case RegionCornerSidesFailureReason::NetworkMismatch:
    return "network-mismatch";
  case RegionCornerSidesFailureReason::UnsupportedArcKind:
    return "unsupported-arc-kind";
  case RegionCornerSidesFailureReason::UnsupportedContactNode:
    return "unsupported-contact-node";
  case RegionCornerSidesFailureReason::PortNotFound:
    return "port-not-found";
  case RegionCornerSidesFailureReason::TurningNotFourQuarterTurns:
    return "turning-not-four-quarter-turns";
  }
  return "unknown";
}

RegionCornerSidesResult
build_region_corner_sides(const GlobalTopologyPlan &topology,
                          const FieldAlignedCurveNetwork &network,
                          const std::vector<RegionBoundarySchedule> &schedules) {
  using Reason = RegionCornerSidesFailureReason;
  if (embedded_graph_topology_detail::network_binding_digest(network) !=
      topology.network_digest()) {
    return RegionCornerSidesFailure{Reason::NetworkMismatch, std::nullopt,
                                    std::nullopt};
  }
  std::map<authority::TraceId, const FieldAlignedCandidateTrace *> traces;
  for (const FieldAlignedCandidateTrace &trace : network.candidate_traces()) {
    traces.emplace(trace.id, &trace);
  }
  std::map<authority::SingularityPortId, const FieldAlignedSingularityPort *>
      ports;
  std::map<authority::NetworkNodeId, int> portCountByNode;
  for (const FieldAlignedSingularityPort &port : network.singularity_ports()) {
    ports.emplace(port.id, &port);
    ++portCountByNode[port.node];
  }
  // The port an arc end occupies at `node`: its trace's own port where the end
  // is the trace's departure, its arrival port where it is the trace's
  // singular arrival.
  const auto port_at = [&](const GlobalTopologyArc &arc, const bool atFirstNode,
                           const authority::NetworkNodeId node)
      -> const FieldAlignedSingularityPort * {
    const auto trace = traces.find(*arc.trace);
    if (trace == traces.end()) return nullptr;
    std::optional<authority::SingularityPortId> id;
    if (atFirstNode && arc.firstSegment == 0U) {
      id = trace->second->port;
    } else if (!atFirstNode &&
               arc.onePastLastSegment == trace->second->segments.size() &&
               trace->second->terminalSingularity.has_value()) {
      id = trace->second->arrivalPort;
    }
    if (!id.has_value()) return nullptr;
    const auto port = ports.find(*id);
    return port != ports.end() && port->second->node == node ? port->second
                                                              : nullptr;
  };
  // Consecutive pieces of one trace: the next piece starts in the segment the
  // previous one ends in (a cut inside it) or at the following segment.
  const auto follows = [](const GlobalTopologyArc &previous,
                          const GlobalTopologyArc &next) {
    return next.firstSegment <= previous.onePastLastSegment &&
           next.firstSegment + 1U >= previous.onePastLastSegment;
  };

  std::vector<RegionCornerSides> result;
  result.reserve(schedules.size());
  for (const RegionBoundarySchedule &schedule : schedules) {
    const GlobalTopologyRegionDiscCertificate *certificate =
        topology.find_region_certificate(schedule.region);
    if (certificate == nullptr) {
      return RegionCornerSidesFailure{Reason::TopologyPlanMismatch,
                                      schedule.region, std::nullopt};
    }
    const std::size_t sideCount = schedule.sides.size();
    std::vector<const GlobalTopologyArc *> arcs(sideCount, nullptr);
    for (std::size_t index = 0U; index < sideCount; ++index) {
      arcs[index] = topology.find_arc(schedule.sides[index].arc.arc);
      if (arcs[index] == nullptr) {
        return RegionCornerSidesFailure{Reason::TopologyPlanMismatch,
                                        schedule.region, index};
      }
    }
    RegionCornerSides region{schedule.region, {}, {}};
    int turning = 0;
    for (std::size_t outgoing = 0U; outgoing < sideCount; ++outgoing) {
      const std::size_t incoming = (outgoing + sideCount - 1U) % sideCount;
      const GlobalTopologyArc &in = *arcs[incoming];
      const GlobalTopologyArc &out = *arcs[outgoing];
      const authority::NetworkNodeId node = schedule.sides[outgoing].startNode;
      const auto failure = [&](const Reason reason) {
        return RegionCornerSidesFailure{reason, schedule.region, outgoing};
      };
      if (in.kind != GlobalTopologyArcKind::Trace ||
          out.kind != GlobalTopologyArcKind::Trace || !in.trace.has_value() ||
          !out.trace.has_value()) {
        return failure(Reason::UnsupportedArcKind);
      }
      const bool inForward = schedule.sides[incoming].arc.orientation ==
                             authority::Orientation::Forward;
      const bool outForward = schedule.sides[outgoing].arc.orientation ==
                              authority::Orientation::Forward;
      int gap = 0;
      const auto valence = portCountByNode.find(node);
      if (*in.trace == *out.trace && in.id != out.id && inForward == outForward &&
          (inForward ? follows(in, out) : follows(out, in))) {
        gap = 2;
      } else if (valence != portCountByNode.end()) {
        // The walk leaves the outgoing arc at its first node when it runs
        // forward, and reaches the incoming arc's first node when it runs
        // reversed. The region lies counter-clockwise of the outgoing arc and
        // port ordinals grow counter-clockwise.
        const FieldAlignedSingularityPort *from = port_at(out, outForward, node);
        const FieldAlignedSingularityPort *to = port_at(in, !inForward, node);
        if (from == nullptr || to == nullptr) {
          return failure(Reason::PortNotFound);
        }
        const int sectors = valence->second;
        gap = ((to->ordinal - from->ordinal) % sectors + sectors) % sectors;
        if (gap == 0) gap = sectors;
      } else {
        const GlobalTopologyNodeRotation *rotation = topology.find_rotation(node);
        if (rotation == nullptr || rotation->counterClockwise.size() != 3U ||
            *in.trace == *out.trace) {
          return failure(Reason::UnsupportedContactNode);
        }
        gap = 1;
      }
      turning += 2 - gap;
      if (gap != 2) region.corners.push_back({node, outgoing, gap});
    }
    if (certificate->interiorSingularityFree && turning != 4) {
      return RegionCornerSidesFailure{Reason::TurningNotFourQuarterTurns,
                                      schedule.region, std::nullopt};
    }
    for (std::size_t corner = 0U; corner < region.corners.size(); ++corner) {
      const std::size_t first = region.corners[corner].scheduleSide;
      const std::size_t next =
          region.corners[(corner + 1U) % region.corners.size()].scheduleSide;
      const std::size_t run =
          next > first ? next - first : next + sideCount - first;
      EInt count(0);
      for (std::size_t offset = 0U; offset < run; ++offset) {
        count += schedule.sides[(first + offset) % sideCount].spanCount;
      }
      region.sides.push_back({first, run, count});
    }
    result.push_back(std::move(region));
  }
  return result;
}

} // namespace directional::geometry
