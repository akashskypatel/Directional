// This file is part of Directional, a library for directional field processing.
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#include <array>
#include <cstddef>
#include <cstdint>
#include <map>
#include <optional>
#include <set>
#include <variant>
#include <vector>

#include <Eigen/Core>

#include <directional/geometry/GlobalTopologyPlan.h>

namespace directional::geometry::embedded_graph_topology_detail {

/** Exact source-triangle record used by the shared embedded-graph authority. */
struct SourceFaceRecord {
  authority::SourceFaceTopologyKey topology;
  authority::SourceFaceId row;
  std::array<authority::SourceVertexId, 3> vertices;
  std::array<authority::SourceEdgeTopologyKey, 3> edges;
  authority::SourceComponentId component;
  authority::TopologyRegionId topologyRegion;
};

struct SourceTopologyIndex {
  std::map<authority::SourceFaceTopologyKey, SourceFaceRecord> faces;
  std::map<authority::SourceEdgeTopologyKey,
           std::vector<authority::SourceFaceTopologyKey>>
      incidentFaces;
  std::map<authority::SourceVertexId,
           std::vector<authority::SourceFaceTopologyKey>>
      incidentFacesByVertex;
};

/** Semantic identity of a cut-created node where one trace crosses a cut edge. */
struct CutCrossingKey {
  authority::SourceEdgeTopologyKey sourceEdge;
  authority::TraceId trace;
  std::size_t segmentPosition = 0U;

  auto operator<=>(const CutCrossingKey &) const = default;
};

struct CutCrossingBinding {
  CutCrossingKey key;
  authority::ExactUnitParameter parameter;
  authority::NetworkNodeId node;

  auto operator<=>(const CutCrossingBinding &) const = default;
};

/** Binding from exact source loci to existing or cut-created graph nodes. */
struct CutNodeBindings {
  std::map<authority::SourceVertexId, authority::NetworkNodeId> nodeByVertex;
  std::map<authority::NetworkNodeId, authority::SourceVertexId> syntheticVertices;
  std::map<CutCrossingKey, CutCrossingBinding> crossingByKey;
  std::map<authority::NetworkNodeId, CutCrossingBinding> syntheticCrossings;
  std::size_t combinedNodeExtent = 0U;
};

struct NodeLocus {
  std::optional<authority::SourceVertexId> vertex;
  std::optional<authority::SourceEdgeTopologyKey> edge;
};

struct FaceWalkResult {
  std::vector<std::vector<GlobalTopologyOrientedArc>> orbits;
  std::vector<std::size_t> orbitByDart;
};

/**
 * Single pre-region semantic authority for the actual embedded graph
 * FieldAlignedCurveNetwork union cutEdges.
 *
 * Degree convention:
 * - degree 0 is invalid authority because no dart can be assigned a face walk;
 * - degree 1 has a singleton cyclic order, so the incoming reverse dart turns
 *   back onto the sole outgoing dart;
 * - degree 2 uses the deterministic two-ray cyclic source order and therefore
 *   exposes the two oriented sides of a simple closed cycle.
 */
struct EmbeddedGraphTopology {
  SourceTopologyIndex sourceTopology;
  CutNodeBindings cutNodes;
  std::vector<GlobalTopologyArc> arcs;
  std::vector<GlobalTopologyNodeRotation> rotations;
  FaceWalkResult faceWalk;
};

using CutNodeBindingResult =
    std::variant<CutNodeBindings, GlobalTopologyPlanError>;
using ArcBuildResult =
    std::variant<std::vector<GlobalTopologyArc>, GlobalTopologyPlanError>;
using NodeLocusResult =
    std::variant<std::map<authority::NetworkNodeId, NodeLocus>,
                 GlobalTopologyPlanError>;
using RotationBuildResult =
    std::variant<std::vector<GlobalTopologyNodeRotation>,
                 GlobalTopologyPlanError>;
using FaceWalkBuildResult =
    std::variant<FaceWalkResult, GlobalTopologyPlanError>;
using EmbeddedGraphTopologyBuildResult =
    std::variant<EmbeddedGraphTopology, GlobalTopologyPlanError>;
using ExteriorOrbitBuildResult =
    std::variant<std::set<std::size_t>, GlobalTopologyPlanError>;

[[nodiscard]] std::optional<SourceTopologyIndex> build_source_index(
    const Eigen::MatrixXi &sourceFaces, std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority);
[[nodiscard]] bool face_orients_edge_forward(
    const SourceFaceRecord &face,
    const authority::SourceEdgeTopologyKey &edge);
[[nodiscard]] std::optional<std::size_t> local_edge_index(
    const SourceFaceRecord &face,
    const authority::SourceEdgeTopologyKey &edge);
[[nodiscard]] std::uint64_t network_binding_digest(
    const FieldAlignedCurveNetwork &network) noexcept;

[[nodiscard]] CutNodeBindingResult build_cut_node_bindings(
    const FieldAlignedCurveNetwork &network,
    const std::vector<authority::SourceEdgeTopologyKey> &cutEdges);
[[nodiscard]] ArcBuildResult build_arcs(
    const FieldAlignedCurveNetwork &network,
    const std::vector<authority::SourceEdgeTopologyKey> &cutEdges,
    const CutNodeBindings &cutNodes);
[[nodiscard]] NodeLocusResult build_node_loci(
    const FieldAlignedCurveNetwork &network,
    const CutNodeBindings &cutNodes);
[[nodiscard]] const FieldAlignedCandidateTrace *find_trace(
    const FieldAlignedCurveNetwork &network, authority::TraceId trace);
[[nodiscard]] const FieldAlignedMandatoryEdge *find_mandatory(
    const FieldAlignedCurveNetwork &network,
    authority::NetworkEdgeId edge);
[[nodiscard]] RotationBuildResult build_rotation_system(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const CutNodeBindings &cutNodes,
    const std::vector<GlobalTopologyArc> &arcs);

[[nodiscard]] std::size_t dart_index(GlobalTopologyOrientedArc incidence);
[[nodiscard]] GlobalTopologyOrientedArc reversed(
    GlobalTopologyOrientedArc incidence);
void canonicalize_cycle(std::vector<GlobalTopologyOrientedArc> &cycle);
[[nodiscard]] FaceWalkBuildResult walk_graph_faces(
    const std::vector<GlobalTopologyArc> &arcs,
    const std::vector<GlobalTopologyNodeRotation> &rotations);

/** Build every actual-graph term exactly once before any region is derived. */
[[nodiscard]] EmbeddedGraphTopologyBuildResult build_embedded_graph_topology(
    const Eigen::MatrixXi &sourceFaces, std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const FieldAlignedCurveNetwork &network,
    const std::vector<authority::SourceEdgeTopologyKey> &cutEdges);

/**
 * Identify exactly the dart orbit outside each source boundary rail loop.
 * Closed sources return an empty set. Multiple boundary loops contribute one
 * excluded exterior orbit each when the mandatory rails faithfully represent
 * the source boundary.
 */
[[nodiscard]] ExteriorOrbitBuildResult exterior_boundary_orbits(
    const SourceTopologyIndex &topology,
    const FieldAlignedCurveNetwork &network,
    const std::vector<GlobalTopologyArc> &arcs,
    const FaceWalkResult &walk);

/** Number of connected components of the actual graph, including all nodes. */
[[nodiscard]] std::size_t actual_graph_component_count(
    const EmbeddedGraphTopology &topology);

/** Exact number of source boundary loops; nullopt means malformed boundary. */
[[nodiscard]] std::optional<std::size_t> source_boundary_loop_count(
    const SourceTopologyIndex &topology);

} // namespace directional::geometry::embedded_graph_topology_detail
