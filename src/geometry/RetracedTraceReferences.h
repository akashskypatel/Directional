// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <algorithm>
#include <map>
#include <optional>
#include <set>
#include <utility>

#include "ExactTraceSegmentPieces.h"

namespace directional::geometry::surface_cell_tracing_detail {

// A selected pair's references, before publication. The arrival binding is
// returned here, not written into the events: every incidence keeps its own
// trace's origin port, as the producer publishes it, so the producer must
// store the binding with the kept trace itself. The old candidate is untouched.
struct RetracedTraceReferences {
  FieldAlignedCurveNetworkCandidate candidate;
  authority::TraceId arrivalTrace;
  authority::SingularityPortId arrivalPort;
};

// Use the same strict entry/slide and face-chord admissibility as the cut
// reader. A terminal sentinel is not an interior contact. A face contact is
// not silently converted to a carrier contact when the chart changes.
[[nodiscard]] inline bool retraced_trace_contact_segment(
    const FieldAlignedCandidateTrace &trace, std::size_t index,
    const FieldAlignedTerminalContact &contact) {
  if (index >= trace.segments.size()) return false;
  const auto &segment = trace.segments[index];
  namespace exact = exact_trace_segment_detail;
  if (contact.carrierLocus) {
    const auto &locus = *contact.carrierLocus;
    const auto zero = authority::FieldExactRational::from_integer(0);
    const auto one = authority::FieldExactRational::from_integer(1);
    const auto barycentric = exact::canonical_boundary_barycentric(
        contact.sourceFace, locus);
    if (!barycentric || *barycentric != contact.barycentric ||
        !(zero < locus.parameter.value && locus.parameter.value < one)) {
      return false;
    }
    const auto entry = field_aligned_segment_entry_occupancy(segment);
    if (entry && entry->carrier == locus.edge &&
        entry->from == locus.parameter.value) return true;
    const auto slide = field_aligned_segment_slide_occupancy(segment);
    return slide && slide->carrier == locus.edge &&
           field_aligned_slide_interior_fraction(*slide, locus.parameter.value)
               .has_value();
  }
  if (segment.sourceFace != contact.sourceFace || segment.edgeTransitExit) {
    return false;
  }
  const auto entry = exact::canonical_boundary_barycentric(
      segment.sourceFace, segment.entryPoint);
  const auto exit = index + 1U < trace.segments.size()
      ? std::optional<authority::FieldBoundaryPoint>{
            trace.segments[index + 1U].entryPoint}
      : trace.terminalPoint;
  if (!entry || !exit) return false;
  const auto end = exact::canonical_boundary_barycentric(segment.sourceFace, *exit);
  return end && exact::face_chart_segment_parameter(
                    *entry, *end, contact.barycentric).has_value();
}

// Remap one exact, oppositely directed singular-to-singular retrace. The caller
// selects disjoint pairs in port order and publishes only after all succeed.
// This helper is not a network constructor and does not change port identities.
[[nodiscard]] inline std::optional<RetracedTraceReferences>
remap_retraced_trace_references(const FieldAlignedCurveNetworkCandidate &input,
                                authority::TraceId keptId,
                                authority::TraceId removedId) {
  using Kind = FieldAlignedNetworkEventKind;
  using Role = FieldAlignedTraceEventRole;
  const auto trace_for = [&](authority::TraceId id) {
    return std::find_if(input.candidateTraces.begin(), input.candidateTraces.end(),
                        [&](const auto &trace) { return trace.id == id; });
  };
  const auto kept = trace_for(keptId);
  const auto removed = trace_for(removedId);
  if (kept == input.candidateTraces.end() ||
      removed == input.candidateTraces.end() || keptId == removedId ||
      !(kept->port < removed->port) ||
      kept->sourceComponent != removed->sourceComponent ||
      kept->sourceTopologyRegion != removed->sourceTopologyRegion ||
      kept->singularity == removed->singularity ||
      kept->sourceVertex == removed->sourceVertex) return std::nullopt;
  const auto unique_trace = [&](const FieldAlignedCandidateTrace &trace) {
    return std::count_if(input.candidateTraces.begin(), input.candidateTraces.end(),
                         [&](const auto &other) {
      return other.id == trace.id || other.port == trace.port;
    }) == 1;
  };
  if (!unique_trace(*kept) || !unique_trace(*removed)) return std::nullopt;
  const auto arrives_at = [](const auto &from, const auto &to) {
    return from.terminalSingularity == to.singularity && from.terminalPoint &&
           !from.terminalBarrier && !from.terminalContact &&
           !from.terminalLimitCycle &&
           authority::canonical_exact_source_boundary_point(*from.terminalPoint) ==
               authority::ExactSourcePoint{to.sourceVertex};
  };
  if (!arrives_at(*kept, *removed) || !arrives_at(*removed, *kept)) {
    return std::nullopt;
  }
  const auto path = [](const FieldAlignedCandidateTrace &trace)
      -> std::optional<authority::ExactSourcePath> {
    authority::ExactSourcePath result;
    for (std::size_t i = 0; i < trace.segments.size(); ++i) {
      const auto pieces =
          exact_trace_segment_detail::exact_trace_segment_pieces(trace, i);
      if (!pieces || pieces->empty() ||
          (!result.empty() && result.back().second != pieces->front().first)) {
        return std::nullopt;
      }
      result.insert(result.end(), pieces->begin(), pieces->end());
    }
    if (result.empty() ||
        result.front().first != authority::ExactSourcePoint{trace.sourceVertex}) {
      return std::nullopt;
    }
    return result;
  };
  const auto a = path(*kept);
  const auto b = path(*removed);
  if (!a || !b || !authority::exact_source_paths_retrace_along_edges(*a, *b)) {
    return std::nullopt;
  }
  const auto port_for = [&](const FieldAlignedCandidateTrace &trace) {
    return std::find_if(input.singularityPorts.begin(), input.singularityPorts.end(),
                        [&](const auto &port) {
      return port.id == trace.port && port.singularity == trace.singularity &&
             port.sourceVertex == trace.sourceVertex &&
             port.sourceComponent == trace.sourceComponent &&
             port.sourceTopologyRegion == trace.sourceTopologyRegion;
    });
  };
  const auto first = port_for(*kept);
  const auto last = port_for(*removed);
  if (first == input.singularityPorts.end() ||
      last == input.singularityPorts.end() || first->node == last->node) {
    return std::nullopt;
  }
  const auto unique_port = [&](authority::SingularityPortId id) {
    return std::count_if(input.singularityPorts.begin(), input.singularityPorts.end(),
                         [&](const auto &port) { return port.id == id; }) == 1;
  };
  if (!unique_port(kept->port) || !unique_port(removed->port)) return std::nullopt;
  RetracedTraceReferences result{input, keptId, removed->port};
  // For every redirected contact require both event records at its exact node.
  std::map<authority::NetworkNodeId, std::pair<std::size_t, std::size_t>> redirectedEvents;
  std::map<authority::NetworkNodeId, authority::ExactSourcePoint> nodePoints;
  std::map<authority::ExactSourcePoint, authority::NetworkNodeId> contactNodes;
  for (auto &trace : result.candidate.candidateTraces) {
    if (!trace.terminalContact ||
        (trace.terminalContact->struckTrace != keptId &&
         trace.terminalContact->struckTrace != removedId)) continue;
    auto &record = *trace.terminalContact;
    const bool redirects = record.struckTrace == removedId;
    const auto &old = redirects ? *removed : *kept;
    if (trace.sourceComponent != old.sourceComponent ||
        trace.sourceTopologyRegion != old.sourceTopologyRegion ||
        !retraced_trace_contact_segment(old, record.struckSegmentIndex, record)) {
      return std::nullopt;
    }
    std::optional<std::size_t> match;
    for (std::size_t i = 0; i < kept->segments.size(); ++i) {
      if (!retraced_trace_contact_segment(*kept, i, record)) continue;
      if (match) return std::nullopt;
      match = i;
    }
    if (!match || (!redirects && *match != record.struckSegmentIndex)) {
      return std::nullopt;
    }
    // The contact's node is identified by the original terminal incidence,
    // not by NetworkNode.sourceVertex (which may just be chart provenance).
    std::optional<authority::NetworkNodeId> node;
    for (const auto &event : input.events) {
      if (event.kind != Kind::TraceIntersection ||
          event.sourceFace != record.sourceFace) continue;
      const auto has = [&](authority::TraceId id, Role role) {
        return std::any_of(event.incidences.begin(), event.incidences.end(),
                           [&](const auto &incidence) {
          return incidence.trace == id && incidence.role == role;
        });
      };
      if (!has(trace.id, Role::Terminal) || !has(old.id, Role::Interior)) continue;
      if (node) return std::nullopt;
      node = event.node;
    }
    const auto point = authority::canonical_exact_source_face_point(
        record.sourceFace, record.barycentric);
    if (!node || !point || *node == first->node || *node == last->node) {
      return std::nullopt;
    }
    const auto [it, inserted] = contactNodes.emplace(*point, *node);
    if (!inserted && it->second != *node) return std::nullopt;
    const auto [nodeIt, nodeInserted] = nodePoints.emplace(*node, *point);
    if (!nodeInserted && nodeIt->second != *point) return std::nullopt;
    if (redirects) redirectedEvents.try_emplace(*node);
    record.struckTrace = keptId;
    record.struckSegmentIndex = *match;
  }
  std::size_t keptArrivals = 0, removedArrivals = 0, removedOrigins = 0, keptOrigins = 0;
  std::size_t keptContacts = 0, removedContacts = 0;
  for (auto &event : result.candidate.events) {
    auto &incidences = event.incidences;
    if (incidences.empty()) return std::nullopt;
    for (auto it = incidences.begin(); it != incidences.end();) {
      if (it->trace == keptId && event.kind == Kind::SingularityPortOrigin) {
        if (event.node != first->node || event.sourceEdge ||
            it->role != Role::Origin || it->sourcePort != kept->port) return std::nullopt;
        ++keptOrigins;
      }
      if (it->trace == keptId && event.node == last->node &&
          ((event.kind == Kind::SingularityTermination && it->role == Role::Terminal) ||
           (event.kind == Kind::FirstContact && it->role == Role::Interior))) {
        if (it->sourcePort != kept->port || event.sourceEdge != kept->terminalPoint->edge) {
          return std::nullopt;
        }
        if (event.kind == Kind::SingularityTermination) ++keptArrivals;
        else ++keptContacts;
      }
      if (it->trace != removedId) { ++it; continue; }
      if (it->sourcePort != removed->port) return std::nullopt;
      if (event.node == last->node && event.kind == Kind::SingularityPortOrigin &&
          it->role == Role::Origin && !event.sourceEdge) {
        ++removedOrigins;
        it = incidences.erase(it);
        continue;
      }
      if (event.node == first->node &&
          event.sourceEdge == removed->terminalPoint->edge &&
          ((event.kind == Kind::SingularityTermination && it->role == Role::Terminal) ||
           (event.kind == Kind::FirstContact && it->role == Role::Interior))) {
        if (event.kind == Kind::SingularityTermination) ++removedArrivals;
        else ++removedContacts;
        it = incidences.erase(it);
        continue;
      }
      if (event.node == last->node && event.kind == Kind::SingularityPortJunction &&
          it->role == Role::Interior && !event.sourceEdge) {
        // A junction lists traces leaving one node together; the removed
        // trace no longer leaves it. The kept arrival is in its own events.
        it = incidences.erase(it);
        continue;
      } else if (redirectedEvents.count(event.node) &&
                 (event.kind == Kind::FirstContact || event.kind == Kind::TraceIntersection) &&
                 it->role == Role::Interior) {
        auto &counts = redirectedEvents.at(event.node);
        if (event.kind == Kind::FirstContact) ++counts.first;
        else ++counts.second;
        it->trace = keptId;
        it->sourcePort = kept->port;
      } else {
        return std::nullopt;
      }
      ++it;
    }
    // The producer publishes a junction only for two or more departures.
    if (event.kind == Kind::SingularityPortJunction && incidences.size() < 2U) {
      incidences.clear();
      continue;
    }
    // A mapped incidence may not duplicate an already published incidence.
    if (std::set<FieldAlignedNetworkEventIncidence>(incidences.begin(), incidences.end()).size() != incidences.size()) {
      return std::nullopt;
    }
  }
  for (const auto &entry : redirectedEvents) {
    if (entry.second.first != 1 || entry.second.second != 1) return std::nullopt;
  }
  if (keptArrivals != 1 || removedArrivals != 1 || removedOrigins != 1 || keptOrigins != 1 ||
      keptContacts != 1 || removedContacts != 1) return std::nullopt;
  auto &events = result.candidate.events;
  events.erase(std::remove_if(events.begin(), events.end(), [](const auto &event) {
    return event.incidences.empty();
  }), events.end());
  auto &traces = result.candidate.candidateTraces;
  traces.erase(std::remove_if(traces.begin(), traces.end(), [&](const auto &trace) {
    return trace.id == removedId;
  }), traces.end());
  return result;
}

} // namespace directional::geometry::surface_cell_tracing_detail
