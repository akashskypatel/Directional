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
#include <utility>
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
/** One trace terminating on the interior of a mandatory source edge. */
struct MandatoryEdgeTerminalCut {
  authority::TraceId trace;
  authority::NetworkNodeId node;
  authority::ExactUnitParameter parameter;
};

/**
 * Exact order of the terminal cuts on one mandatory source edge that has two
 * or more of them. Cuts are sorted by exact edge parameter (trace id breaks
 * ties); orderClass[i] numbers the distinct parameters along the edge, so
 * equal parameters share a class.
 */
struct MandatoryEdgeTerminalInventory {
  authority::SourceEdgeTopologyKey sourceEdge;
  std::vector<MandatoryEdgeTerminalCut> cuts;
  std::vector<std::size_t> orderClass;
  std::size_t distinctParameters = 0U;
  /** True when every class of equal parameters binds a single network node. */
  bool equalParametersShareNode = true;
};

/** One piece of a mandatory source edge, from lower to higher edge parameter. */
struct MandatoryEdgePiece {
  authority::NetworkNodeId firstNode;
  authority::NetworkNodeId secondNode;
  authority::FieldExactRational firstParameter;
  authority::FieldExactRational secondParameter;
  /** The terminal cut at the piece's upper end, or the last cut for the final
   * piece; none when the edge has no terminal cut. */
  std::optional<authority::TraceId> adjacentTrace;
};

enum class MandatoryEdgeSplitFailureKind {
  /** A terminal cut binds one of the edge's endpoint nodes. */
  TerminalAtEndpoint,
  /** Two terminal cuts share one exact edge parameter. */
  EqualParameters,
  /** One node terminates two cuts at different edge parameters. */
  SharedNode,
};

struct MandatoryEdgeSplitFailure {
  MandatoryEdgeSplitFailureKind kind;
  authority::TraceId trace;
  std::optional<authority::TraceId> secondTrace;
};

using MandatoryEdgeSplit =
    std::variant<std::vector<MandatoryEdgePiece>, MandatoryEdgeSplitFailure>;

/**
 * Splits a mandatory edge running from `firstNode` (parameter 0) to
 * `secondNode` (parameter 1) at its terminal cuts, in exact parameter order.
 * N strictly ordered cuts with distinct interior nodes give N + 1 pieces.
 */
[[nodiscard]] MandatoryEdgeSplit split_mandatory_edge_at_terminals(
    authority::NetworkNodeId firstNode, authority::NetworkNodeId secondNode,
    std::vector<MandatoryEdgeTerminalCut> cuts);

/**
 * Exact barycentric coordinates of a point of one source face, listed in that
 * face's oriented corner order. Every predicate below is affine-invariant, so
 * no metric geometry is read.
 */
using FaceChartPoint = std::array<authority::FieldExactRational, 3>;

/**
 * Orientation of `a`, `b`, `c` in one face chart: +1 when they run
 * counter-clockwise in the corner order of their coordinates, -1 when
 * clockwise, 0 when collinear. Exact.
 */
[[nodiscard]] int face_chart_orientation(const FaceChartPoint &a,
                                         const FaceChartPoint &b,
                                         const FaceChartPoint &c);

/**
 * The exact t with point = entry + t * (exit - entry), when the point lies
 * strictly inside the straight segment from `entry` to `exit`. Empty when the
 * segment is degenerate, the point is off its line, or t is not in (0, 1).
 */
[[nodiscard]] std::optional<authority::FieldExactRational>
face_chart_segment_parameter(const FaceChartPoint &entry,
                             const FaceChartPoint &exit,
                             const FaceChartPoint &point);

/**
 * Counter-clockwise order of the rays leaving `origin` through each target,
 * as indices into `targets`, starting at index 0. Empty when a target equals
 * the origin or two rays leave in the same direction.
 */
[[nodiscard]] std::optional<std::vector<std::size_t>>
face_chart_counter_clockwise_ray_order(const FaceChartPoint &origin,
                                       const std::vector<FaceChartPoint> &targets);

/**
 * A position on a candidate trace. With no `parameter` it is the boundary
 * before segment `segment` (the trace's end when `segment` is the segment
 * count); otherwise it is the exact interior point at `parameter`, in (0, 1),
 * along that segment. The defaulted order is the order along the trace.
 */
struct TraceCutPosition {
  std::size_t segment = 0U;
  std::optional<authority::FieldExactRational> parameter;

  auto operator<=>(const TraceCutPosition &) const = default;
};

/**
 * Where a trace segment starts and ends in its own face, as exact barycentric
 * coordinates in the canonical vertex order of that face's topology key. The
 * end is the next segment's entry, or the trace's terminal point or contact.
 * Empty when the point is not available; the end is also empty for a segment
 * that transits along an edge, which is not straight in its face.
 */
[[nodiscard]] std::optional<FaceChartPoint> trace_segment_canonical_entry(
    const FieldAlignedCandidateTrace &trace, std::size_t segment);
[[nodiscard]] std::optional<FaceChartPoint> trace_segment_canonical_exit(
    const FieldAlignedCandidateTrace &trace, std::size_t segment);

/**
 * The exact parameter, in (0, 1), of a contact point strictly inside a
 * straight trace segment. `point` uses the canonical chart of the segment's
 * face. Empty when the segment's ends are unavailable or the point is not
 * strictly inside it.
 */
[[nodiscard]] std::optional<authority::FieldExactRational>
trace_segment_contact_parameter(const FieldAlignedCandidateTrace &trace,
                                std::size_t segment,
                                const FaceChartPoint &point);

/**
 * The exact source path segment `segment` of `trace` traverses. A segment
 * without an edge transit is one face piece to its end. A segment with an edge
 * transit is a face piece from its entry to the slide start, omitted when the
 * two are the same point, then an edge piece along its outgoing carrier to the
 * slide end. A terminal face contact on the last segment ends it on its face
 * piece, so the slide is not traversed. Empty when the record is incomplete or
 * inconsistent.
 */
[[nodiscard]] std::optional<authority::ExactSourcePath>
exact_trace_segment_pieces(const FieldAlignedCandidateTrace &trace,
                           std::size_t segment);

/** Segment range [first, onePastLast) of the arc between two positions. */
[[nodiscard]] std::pair<std::size_t, std::size_t>
trace_cut_segment_range(const TraceCutPosition &first,
                        const TraceCutPosition &second);

/**
 * The exact source path of a trace between two positions, `first` before
 * `second`. A piece starts or ends at an interior position's exact point;
 * between two segment boundaries it equals the whole-segment path.
 */
[[nodiscard]] std::optional<authority::ExactSourcePath>
exact_trace_path_between(const FieldAlignedCandidateTrace &trace,
                         const TraceCutPosition &first,
                         const TraceCutPosition &second);

/**
 * A network node at a trace-trace contact strictly inside a source face: a
 * non-port node with a TraceIntersection or TraceSelfClosure event, or with
 * contact events that have no source edge. A common-carrier source edge on
 * such an event is not the contact's locus.
 */
struct FaceContactNode {
  authority::SourceFaceTopologyKey face;
  /** Exact contact point in the canonical chart of `face`. */
  FaceChartPoint point;
  /** Traces that end at this node. */
  std::set<authority::TraceId> terminating;
  /** Interior positions of the struck traces at this node. */
  std::map<authority::TraceId, TraceCutPosition> interior;
};
using FaceContactNodeResult =
    std::variant<std::map<authority::NetworkNodeId, FaceContactNode>,
                 GlobalTopologyPlanError>;

/** Collects and validates every face-contact node of the network. */
[[nodiscard]] FaceContactNodeResult
collect_face_contact_nodes(const FieldAlignedCurveNetwork &network);

/** Inventories every source edge that carries two or more terminal cuts. */
[[nodiscard]] std::vector<MandatoryEdgeTerminalInventory>
inventory_mandatory_edge_terminals(
    const std::map<authority::SourceEdgeTopologyKey,
                   std::vector<MandatoryEdgeTerminalCut>> &cutsByEdge);
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

/** Exact ray parameter from the oriented start edge to end edge of one vertex wedge. */
[[nodiscard]] std::optional<authority::FieldExactRational>
vertex_locus_secondary_parameter(
    const SourceTopologyIndex &topology, authority::SourceVertexId locus,
    const GlobalTopologyArc &arc, authority::Orientation orientation,
    const FieldAlignedCandidateTrace &trace,
    VertexTraceSecondaryParameterFailureReason *failureReason = nullptr);

struct EdgeLocusSecondaryRankDiagnosticContext {
  std::optional<authority::SourceFaceTopologyKey> sourceFace;
  std::optional<authority::SourceEdgeTopologyKey> incomingCarrier;
  std::optional<authority::SourceEdgeTopologyKey> outgoingCarrier;
  std::optional<std::size_t> contactIndex;
  std::optional<authority::SourceEdgeTopologyKey> otherCarrier;
  std::optional<std::array<authority::SourceVertexId, 3>> faceCorners;
};

/** Exact edge-locus within-side rank with typed diagnostic-only failure output. */
[[nodiscard]] std::optional<std::size_t> edge_locus_secondary_rank(
    const SourceTopologyIndex &topology,
    const authority::SourceEdgeTopologyKey &locus,
    const GlobalTopologyArc &arc, authority::Orientation orientation,
    const FieldAlignedCandidateTrace &trace,
    EdgeTraceSecondaryRankFailureReason *failureReason = nullptr,
    EdgeLocusSecondaryRankDiagnosticContext *diagnosticContext = nullptr);

/** Dense exact ranks corresponding to input parameters; exact ties share a rank. */
[[nodiscard]] std::vector<std::size_t> vertex_trace_secondary_ranks(
    const std::vector<authority::FieldExactRational> &parameters);

[[nodiscard]] RotationSystemInconsistencyReason
vertex_trace_secondary_collision_reason(
    const authority::FieldExactRational &first,
    const authority::FieldExactRational &second) noexcept;

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

/** Exact fixed-candidate topology receipt used by the S4 necessary-condition accelerator. */
struct FixedCandidateTopologyInvariant {
  std::size_t vertexCount = 0U;
  std::size_t edgeCount = 0U;
  std::size_t observedComplementComponentCount = 0U;
  std::size_t graphComponentCount = 0U;
  std::size_t sourceComponentCount = 0U;
  std::int64_t firstBetti = 0;
  std::int64_t requiredFaceCount = 0;
  int sourceEulerCharacteristic = 0;
  bool rejects = false;

  auto operator<=>(const FixedCandidateTopologyInvariant &) const = default;
};

/**
 * Count connected components of the actual source-surface complement.
 *
 * This is not the dart-face-walk orbit count.  It subdivides each source
 * triangle by the already-built exact source paths, then stitches only
 * non-graph source-edge intervals across adjacent source triangles.  Failure
 * to establish that exact local arrangement returns nullopt so callers fall
 * back to the unchanged final certificate.
 */
[[nodiscard]] std::optional<std::size_t>
actual_complement_component_count(const EmbeddedGraphTopology &topology);

/** Exact S4 fixed-candidate necessary-condition receipt; nullopt means unavailable. */
[[nodiscard]] std::optional<FixedCandidateTopologyInvariant>
fixed_candidate_topology_invariant(const EmbeddedGraphTopology &topology);

/** Number of connected components of the actual graph, including all nodes. */
[[nodiscard]] std::size_t actual_graph_component_count(
    const EmbeddedGraphTopology &topology);

/** Exact number of source boundary loops; nullopt means malformed boundary. */
[[nodiscard]] std::optional<std::size_t> source_boundary_loop_count(
    const SourceTopologyIndex &topology);

} // namespace directional::geometry::embedded_graph_topology_detail

namespace directional::geometry::surface_cut_graph_test_detail {

struct S4ExecutionDiagnostics {
  std::size_t candidateEvaluations = 0U;
  std::size_t earlyRejectedCandidates = 0U;
  std::size_t fullCertificationAttempts = 0U;
  std::size_t bypassedFinalCertificationAttempts = 0U;

  auto operator<=>(const S4ExecutionDiagnostics &) const = default;
};

using CandidateResult =
    std::variant<SurfaceCutGraphCandidate, SurfaceCutGraphError>;

/** Last diagnostics produced by the public SurfaceCutGraph::make on this thread. */
[[nodiscard]] S4ExecutionDiagnostics last_s4_execution_diagnostics() noexcept;

/** Test-only reference seam: same canonical candidate search with S4 disabled. */
[[nodiscard]] CandidateResult canonical_candidate_without_s4_for_test(
    const Eigen::MatrixXi &sourceFaces, std::size_t sourceVertexCount,
    const SourceTopologyRegions &sourceAuthority,
    const authority::FieldTransportAtlas &fieldTransportAtlas,
    const FieldAlignedCurveNetwork &network,
    S4ExecutionDiagnostics *diagnostics = nullptr);

} // namespace directional::geometry::surface_cut_graph_test_detail
