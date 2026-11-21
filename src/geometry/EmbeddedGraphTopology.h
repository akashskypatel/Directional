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

/**
 * A trace that ends with a carrier locus: the struck trace is cut at the
 * boundary before `struckSegment`, the segment it enters at that locus.
 */
struct CarrierContactBinding {
  authority::TraceId struckTrace;
  std::size_t struckSegment = 0U;

  auto operator<=>(const CarrierContactBinding &) const = default;
};

/** Binding from exact source loci to existing or cut-created graph nodes. */
struct CutNodeBindings {
  std::map<authority::SourceVertexId, authority::NetworkNodeId> nodeByVertex;
  std::map<authority::NetworkNodeId, authority::SourceVertexId> syntheticVertices;
  std::map<CutCrossingKey, CutCrossingBinding> crossingByKey;
  /** Crossing by node. A crossing struck by a carrier contact keeps the
   * contact's network node instead of a cut-created one. A mutual carrier
   * contact on a selected cut edge splits it at the contact's network node,
   * listed here only, since neither trace crosses there. */
  std::map<authority::NetworkNodeId, CutCrossingBinding> syntheticCrossings;
  std::map<authority::NetworkNodeId, CarrierContactBinding> carrierContacts;
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
/**
 * The dart whose face-walk orbit holds `face` when an arc runs along one of
 * the face's edges as the edge piece `piece` without entering the face:
 * Forward exactly when `face` traverses that edge in the piece's direction,
 * as the incident face of a mandatory arc takes its forward dart; the face
 * across the edge takes the other dart. Empty when `piece` is not carried by
 * an edge of `face` or does not advance along it. This is the side rule for
 * a trace segment that only slides along its face's edge; unwired until the
 * coordinated graph cutover.
 */
[[nodiscard]] std::optional<authority::Orientation> edge_piece_face_side(
    const SourceFaceRecord &face,
    const authority::ExactSourceSupportPiece &piece);
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
 * along that segment. On a segment with a slide the point lies on the slide's
 * edge piece, at fraction `parameter` from the slide start to the slide end.
 * The defaulted order is the order along the trace.
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
 * Where a terminal carrier contact cuts the struck trace when the contact is
 * that trace's entry crossing: the boundary before the struck segment. Empty
 * when `struck` is not the record's struck trace, the record has no carrier
 * locus, the struck segment does not exist, or the locus is not that
 * segment's entry crossing at an interior edge parameter (a contact inside a
 * slide, or at a vertex, is not handled here).
 */
[[nodiscard]] std::optional<TraceCutPosition> carrier_contact_struck_position(
    const FieldAlignedCandidateTrace &struck,
    const FieldAlignedTerminalContact &record);

/**
 * Where a terminal carrier contact cuts the struck trace when the locus lies
 * strictly inside the struck segment's slide on the same edge: that segment,
 * at the locus's fraction of the slide. Empty when `struck` is not the
 * record's struck trace, the record has no carrier locus, the struck segment
 * does not exist or has no slide on the locus edge, or the locus is not
 * strictly between the slide's ends.
 */
[[nodiscard]] std::optional<TraceCutPosition> carrier_contact_slide_position(
    const FieldAlignedCandidateTrace &struck,
    const FieldAlignedTerminalContact &record);

/**
 * True when `ending` and `struck` stopped together at one carrier locus, the
 * outcome of an inconclusive arrival at a shared entry crossing: neither trace
 * entered its next segment there. Each record names the other trace at that
 * trace's end (`struckSegmentIndex` equal to its segment count) at the same
 * edge and interior parameter, and each trace's last segment lies in its
 * record's face and leaves it through that edge without a slide.
 */
[[nodiscard]] bool carrier_contact_is_mutual(
    const FieldAlignedCandidateTrace &ending,
    const FieldAlignedCandidateTrace &struck);

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
 * Concatenate the real segment pieces in [first, second). Interior cuts
 * clip ordinary face pieces, or the edge piece of a traversed slide; the arc
 * after a slide cut starts on the edge piece. When `pieceCounts` is given,
 * it receives how many pieces each segment in the range contributed (1 or 2).
 * The committed trace-arc source path is the graph producer after cutover.
 */
[[nodiscard]] std::optional<authority::ExactSourcePath>
exact_trace_piece_path_between(const FieldAlignedCandidateTrace &trace,
                               const TraceCutPosition &first,
                               const TraceCutPosition &second,
                               std::vector<std::size_t> *pieceCounts = nullptr);

/**
 * The source piece along which the ray of the trace arc between `first` and
 * `second` leaves its node: for the Forward ray the first piece of
 * exact_trace_piece_path_between, for the Reverse ray its last piece with the
 * endpoints swapped, so the piece always starts at the ray's node. Empty when
 * that path is. Unwired until the coordinated graph cutover.
 */
[[nodiscard]] std::optional<authority::ExactSourceSupportPiece>
exact_trace_arc_ray_piece(const FieldAlignedCandidateTrace &trace,
                          const TraceCutPosition &first,
                          const TraceCutPosition &second,
                          authority::Orientation orientation);

/** Where a trace arc's source path fails to split into its segments' pieces. */
struct SourcePieceBindingFailure {
  /** The failing segment; empty when the counts do not partition the path. */
  std::optional<std::size_t> segment;

  bool operator==(const SourcePieceBindingFailure &) const = default;
};

/**
 * Checks the exact segment-to-piece binding of a trace arc. Segment k owns
 * the next `sourcePieceCounts[k]` pieces of `sourcePath`, which must be
 * `[face(sourceFaces[k])]`, `[face(sourceFaces[k]), edge of sourceFaces[k]]`
 * or `[edge of sourceFaces[k]]`. An edge piece ends at a source vertex unless
 * it is the path's last piece. Path canonicity is checked separately.
 */
[[nodiscard]] std::optional<SourcePieceBindingFailure>
source_piece_binding_failure(
    const std::vector<authority::SourceFaceTopologyKey> &sourceFaces,
    const std::vector<std::size_t> &sourcePieceCounts,
    const authority::ExactSourcePath &sourcePath);

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

/**
 * Exact barycentric coordinates of `point` in the oriented corner order of
 * `face`: a source vertex is its unit corner, an edge point weights the two
 * corners of its edge, and a face point's canonical coordinates are listed in
 * corner order. Empty when the point is not on the closure of `face`: a vertex
 * that is not a corner, an edge point off the face's edges, or a point of
 * another face. Coordinate signs are not checked. Unwired until the
 * coordinated graph cutover.
 */
[[nodiscard]] std::optional<FaceChartPoint> exact_source_point_barycentric(
    const SourceFaceRecord &face, const authority::ExactSourcePoint &point);

/** A trace ray that leaves a vertex locus along a mesh edge. */
struct VertexPieceRayAlongEdge {
  authority::SourceEdgeTopologyKey edge;

  bool operator==(const VertexPieceRayAlongEdge &) const = default;
};

/**
 * A trace ray that leaves a vertex locus into the wedge of `face`, with the
 * within-wedge parameter of vertex_locus_secondary_parameter.
 */
struct VertexPieceRayInWedge {
  authority::SourceFaceTopologyKey face;
  authority::FieldExactRational parameter;

  bool operator==(const VertexPieceRayInWedge &) const = default;
};

enum class VertexPieceRayFailure : std::uint8_t {
  /** The piece does not start at the locus. */
  PieceStartsElsewhere,
  /** The carrier is neither the face's interior, with the locus as a corner,
   * nor an edge of the face through the locus. */
  CarrierNotAtLocus,
  /** The far end lies off the carrier, or an edge piece ends at the locus. */
  FarEndOffCarrier,
  /** The far end gives no within-wedge parameter: the condition
   * vertex_locus_secondary_parameter reports as InvalidDenominator. */
  InvalidDenominator,
};

using VertexPieceRay = std::variant<VertexPieceRayAlongEdge,
                                    VertexPieceRayInWedge, VertexPieceRayFailure>;

/**
 * How a trace ray leaves the vertex `locus` in its source face `face`, read
 * from the ray's source piece oriented away from the locus (see
 * exact_trace_arc_ray_piece). An edge piece runs along its mesh edge, which
 * must be an edge of `face` through `locus` and hold the piece's far end. A
 * face piece of `face` lies in the face's wedge at `locus`; its parameter is
 * the far end's exact opposite-edge parameter, by the formula and failure
 * condition of vertex_locus_secondary_parameter. Assigns no rotation key.
 * The committed trace-arc source path is the graph producer after cutover.
 */
[[nodiscard]] VertexPieceRay vertex_piece_ray(
    const SourceFaceRecord &face, authority::SourceVertexId locus,
    const authority::ExactSourceSupportPiece &piece);

/** A trace ray that leaves an edge locus along the locus edge itself. */
struct EdgePieceRayAlongLocusEdge {
  /** True toward the edge's second endpoint, false toward its first. */
  bool towardSecondEndpoint = false;

  bool operator==(const EdgePieceRayAlongLocusEdge &) const = default;
};

/**
 * A trace ray that leaves an edge locus into `face`, through its interior or
 * along another of its edges from an endpoint of the locus edge, toward
 * `farEnd`.
 */
struct EdgePieceRayIntoFace {
  authority::SourceFaceTopologyKey face;
  authority::ExactSourcePoint farEnd;

  bool operator==(const EdgePieceRayIntoFace &) const = default;
};

enum class EdgePieceRayFailure : std::uint8_t {
  /** The piece does not start on the locus edge: neither at a point of it
   * nor at one of its endpoints. */
  PieceStartsOffLocus,
  /** The carrier is neither the interior of the face nor one of its edges;
   * on the locus edge, that edge does not bound the face. */
  CarrierNotOfFace,
  /** An end of the piece lies off its carrier. */
  PieceOffCarrier,
  /** The piece does not leave its start. */
  ZeroLength,
};

using EdgePieceRay = std::variant<EdgePieceRayAlongLocusEdge,
                                  EdgePieceRayIntoFace, EdgePieceRayFailure>;

/**
 * How a trace ray leaves a node on the source edge `locus` in its source face
 * `face`, read from the ray's source piece oriented away from the node (see
 * exact_trace_arc_ray_piece). An edge piece on the locus edge runs along it,
 * toward the endpoint its exact parameters advance to. A face piece of `face`,
 * or an edge piece on another edge of `face` (the node then sits at an
 * endpoint of the locus edge), leaves into `face` toward the piece's far end.
 * Exposes geometry only and assigns no rotation key. Unwired until the
 * coordinated graph cutover.
 */
[[nodiscard]] EdgePieceRay edge_piece_ray(
    const SourceFaceRecord &face, const authority::SourceEdgeTopologyKey &locus,
    const authority::ExactSourceSupportPiece &piece);

/**
 * Primary slot of a ray that runs along an edge locus, whether it is an edge
 * arc or a trace piece on the locus edge: 0 toward the edge's second endpoint,
 * 2 toward its first.
 */
[[nodiscard]] std::size_t edge_locus_edge_ray_primary(bool towardSecondEndpoint);

/**
 * Primary slot of a trace ray that leaves an edge locus into the face of side
 * rank `sideRank`, given the locus's total edge-ray count. Without edge rays
 * the slot is the side rank; with two, it is the odd slot between the two
 * edge-ray slots.
 */
[[nodiscard]] std::size_t edge_locus_into_face_primary(std::size_t sideRank,
                                                       std::size_t edgeRayCount);

/**
 * Whether an edge locus may carry `arcEdgeRays` edge arcs and
 * `traceAlongEdgeRays` trace rays along the locus edge: neither kind, or
 * exactly two of one kind. Mixed pairs are not admitted.
 */
[[nodiscard]] bool edge_locus_edge_ray_composition_valid(
    std::size_t arcEdgeRays, std::size_t traceAlongEdgeRays);

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
