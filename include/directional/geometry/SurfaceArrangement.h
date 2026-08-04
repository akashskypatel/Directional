// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2026 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H
#define DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <limits>
#include <map>
#include <numeric>
#include <set>
#include <stdexcept>
#include <tuple>
#include <utility>
#include <vector>

#include <Eigen/Dense>

#include <directional/geometry/SurfaceCellOwnership.h>
#include <directional/geometry/SurfaceCellTracing.h>

namespace directional::geometry {

enum class SurfaceArrangementCellClass : int {
  Exterior = 0,
  RegularQuad = 1,
  PatchCandidate = 2,
  NonDisk = 3,
};

enum class SurfaceArrangementRejectReason : int {
  None = 0,
  NonAlternatingFamilies = 1,
  NotFourSided = 2,
  OddBoundaryParity = 3,
  HardFeatureCrossing = 4,
  Sliver = 5,
};

enum class SurfaceArrangementIncidenceFailure : int {
  None = 0,
  SourceTransitionUnavailable = 1,
  MissingWedge = 2,
  AmbiguousWedge = 3,
  AmbiguousRayOrder = 4,
  InvalidTwin = 5,
  MissingSuccessor = 6,
  DuplicatePredecessor = 7,
  EndpointDiscontinuity = 8,
  IncompletePermutation = 9,
  RepeatedHalfedgeCycle = 10,
  RepeatedNodeCycle = 11,
  RepeatedEdgeCycle = 12,
  ShortCycle = 13,
};

inline const char *surface_arrangement_incidence_failure_name(
    const SurfaceArrangementIncidenceFailure failure) {
  switch (failure) {
  case SurfaceArrangementIncidenceFailure::None:
    return "None";
  case SurfaceArrangementIncidenceFailure::SourceTransitionUnavailable:
    return "SourceTransitionUnavailable";
  case SurfaceArrangementIncidenceFailure::MissingWedge:
    return "MissingWedge";
  case SurfaceArrangementIncidenceFailure::AmbiguousWedge:
    return "AmbiguousWedge";
  case SurfaceArrangementIncidenceFailure::AmbiguousRayOrder:
    return "AmbiguousRayOrder";
  case SurfaceArrangementIncidenceFailure::InvalidTwin:
    return "InvalidTwin";
  case SurfaceArrangementIncidenceFailure::MissingSuccessor:
    return "MissingSuccessor";
  case SurfaceArrangementIncidenceFailure::DuplicatePredecessor:
    return "DuplicatePredecessor";
  case SurfaceArrangementIncidenceFailure::EndpointDiscontinuity:
    return "EndpointDiscontinuity";
  case SurfaceArrangementIncidenceFailure::IncompletePermutation:
    return "IncompletePermutation";
  case SurfaceArrangementIncidenceFailure::RepeatedHalfedgeCycle:
    return "RepeatedHalfedgeCycle";
  case SurfaceArrangementIncidenceFailure::RepeatedNodeCycle:
    return "RepeatedNodeCycle";
  case SurfaceArrangementIncidenceFailure::RepeatedEdgeCycle:
    return "RepeatedEdgeCycle";
  case SurfaceArrangementIncidenceFailure::ShortCycle:
    return "ShortCycle";
  }
  return "Unknown";
}

struct SurfaceArrangementOptions {
  bool insertBoundaryRails = true;
  std::set<std::uint64_t> hardFeatureEdges;
  const std::vector<int> *sourceFaceComponents = nullptr;
  const std::vector<int> *sourceFaceSheets = nullptr;
};

struct SurfaceArrangementArc {
  int id = -1;
  int sourceFace = -1;
  Eigen::RowVector3d startBarycentric = Eigen::RowVector3d::Zero();
  Eigen::RowVector3d endBarycentric = Eigen::RowVector3d::Zero();
  int family = 0;
  int strand = -1;
  int featureClass = 0;
  bool hardFeature = false;
  int provenance = -1;
  int railId = -1;
  int curveId = -1;
  int sourceComponent = -1;
  int sourceSheet = -1;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  double railT0 = 0.0;
  double railT1 = 1.0;
  bool layoutSupport = false;
  bool singularitySupport = false;
};

struct SurfaceArrangementNodeOccurrence {
  int sourceFace = -1;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
  // Exact source-chart scope. Edge-interior arrangement nodes may be shared
  // geometrically by two source sheets, so the node-level primary chart is
  // not sufficient to select an oriented halfedge endpoint.
  int sourceComponent = -1;
  int sourceSheet = -1;
  int sourceArc = -1;
  int provenance = -1;
  int railId = -1;
  int curveId = -1;
  double sourceT0 = 0.0;
  double sourceT1 = 0.0;
  double railT0 = 0.0;
  double railT1 = 0.0;
};

struct SurfaceArrangementProvenance {
  int sourceArc = -1;
  int provenance = -1;
  int sourceFace = -1;
  int family = -1;
  int strand = -1;
  int featureClass = 0;
  bool hardFeature = false;
  bool layoutSupport = false;
  bool singularitySupport = false;
  int railId = -1;
  int curveId = -1;
  int sourceComponent = -1;
  int sourceSheet = -1;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  double sourceT0 = 0.0;
  double sourceT1 = 1.0;
  double railT0 = 0.0;
  double railT1 = 1.0;
};

struct SurfaceArrangementNode {
  int id = -1;
  int sourceFace = -1;
  int sourceComponent = -1;
  int sourceSheet = -1;
  bool hardBarrierCrossing = false;
  Eigen::RowVector3d barycentric = Eigen::RowVector3d::Zero();
  int sourceEdge = -1;
  double sourceEdgeParameter = 0.0;
  std::vector<SurfaceArrangementNodeOccurrence> occurrences;
};

struct SurfaceArrangementHalfedge {
  int id = -1;
  int twin = -1;
  int next = -1;
  int from = -1;
  int to = -1;
  int sourceArc = -1;
  int family = -1;
  int strand = -1;
  int featureClass = 0;
  int sourceFace = -1;
  double sourceT0 = 0.0;
  double sourceT1 = 1.0;
  bool hardFeature = false;
  bool layoutSupport = false;
  bool singularitySupport = false;
  int railId = -1;
  int curveId = -1;
  int sourceComponent = -1;
  int sourceSheet = -1;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  double railT0 = 0.0;
  double railT1 = 1.0;
  std::vector<SurfaceArrangementProvenance> provenance;
  int cell = -1;
};

struct SurfaceArrangementCell {
  int id = -1;
  int sourceFace = -1;
  // Exact ownership scope of the oriented cell.  Source-face support is kept
  // separately because one cell can span many source triangles while still
  // belonging to one connected component and one source sheet.
  int sourceComponent = -1;
  // Legacy representative chart. Exact per-face charts are kept in
  // sourceCharts and sourceOwnershipClass identifies their physical cell side.
  int sourceSheet = -1;
  SurfaceCellCanonicalIdentity sourceOwnershipClass;
  std::vector<SurfaceCellSourceChart> sourceCharts;
  std::vector<int> sourceFaces;
  std::vector<int> halfedges;
  std::vector<int> sideFamilies;
  std::vector<int> sideEdgeCounts;
  double signedArea = 0.0;
  double area = 0.0;
  bool boundaryCycle = false;
  bool closed = false;
  bool disk = false;
  int boundaryComponentCount = 0;
  int eulerCharacteristic = 0;
  bool quadReady = false;
  SurfaceArrangementCellClass cellClass =
      SurfaceArrangementCellClass::PatchCandidate;
  SurfaceArrangementRejectReason rejectReason =
      SurfaceArrangementRejectReason::None;
};

struct SurfaceArrangementDiagnostics {
  int plantedIntersections = 0;
  int uniqueIntersections = 0;
  int unsplitCrossings = 0;
  int geometricTJunctions = 0;
  int incompleteArcChains = 0;
  int hardBarrierCrossings = 0;
  int eulerCharacteristic = 0;
  int sourceEulerCharacteristic = 0;
  int connectedComponentCount = 0;
  int sourceConnectedComponentCount = 0;
  int boundaryLoopCount = 0;
  int sourceBoundaryLoopCount = 0;
  int directedWedgeCount = 0;
  int successorMissingCount = 0;
  int successorAmbiguityCount = 0;
  int predecessorMultiplicityFailureCount = 0;
  int repeatedNodeCycleCount = 0;
  int repeatedEdgeCycleCount = 0;
  SurfaceArrangementIncidenceFailure incidenceFailure =
      SurfaceArrangementIncidenceFailure::None;
  int incidenceFailureNode = -1;
  int incidenceFailureHalfedge = -1;
  int incidenceFailureTwin = -1;
  int incidenceFailureNext = -1;
  std::uint64_t directedIncidenceHash = 0U;
  bool incidenceValid = false;
  bool embeddingValid = false;
  bool orientationValid = false;
  bool cellsDiskValid = false;
  bool boundaryLoopsValid = false;
  bool eulerCharacteristicValid = false;
  bool topologyValid = false;
  int peakSegmentsPerFace = 0;
  double supportedArea = 0.0;
  double extractedArea = 0.0;
  double relativeAreaError = 0.0;
  double memoryRatioEstimate = 0.0;
  double measuredMemoryRatio = 0.0;
  std::uint64_t inputMemoryBytes = 0;
  std::uint64_t retainedMemoryBytes = 0;
  std::uint64_t peakMemoryBytes = 0;
};

struct SurfaceCellComplex {
  // Exact canonical ownership memberships are stored once per complex. Cells
  // retain only a fixed-size {component, ordinal} key and their incident chart
  // map, preventing O(cells * component-faces) duplication.
  std::vector<SurfaceCellOwnershipClassRecord> sourceOwnershipRegistry;
  std::vector<SurfaceArrangementNode> nodes;
  std::vector<SurfaceArrangementHalfedge> halfedges;
  std::vector<SurfaceArrangementCell> cells;
  SurfaceArrangementDiagnostics diagnostics;
};

struct SurfaceArrangementOverlay {
  Eigen::MatrixXd splitSegmentStarts;
  Eigen::MatrixXd splitSegmentEnds;
  Eigen::VectorXi sideFamily;
  Eigen::VectorXi cellId;
  Eigen::VectorXi cellClass;
  Eigen::VectorXi sliverCycle;
  Eigen::VectorXi hardRailCrossing;
};

namespace surface_arrangement_detail {

struct Segment2 {
  int sourceArc = -1;
  int provenance = -1;
  int sourceFace = -1;
  Eigen::Vector2d start = Eigen::Vector2d::Zero();
  Eigen::Vector2d end = Eigen::Vector2d::Zero();
  int family = -1;
  int strand = -1;
  int featureClass = 0;
  bool hardFeature = false;
  bool layoutSupport = false;
  bool singularitySupport = false;
  int railId = -1;
  int curveId = -1;
  int sourceComponent = -1;
  int sourceSheet = -1;
  int proposalId = -1;
  int proposalSeedId = -1;
  int proposalSide = -1;
  int proposalBoundarySegment = -1;
  double railT0 = 0.0;
  double railT1 = 1.0;
  double sourceT0 = 0.0;
  double sourceT1 = 1.0;
};

struct NodeKey {
  int kind = 2;
  int face = -1;
  std::int64_t edge = -1;
  std::int64_t edgeT = -1;
  int vertex = -1;
  std::int64_t u = 0;
  std::int64_t v = 0;

  bool operator<(const NodeKey &other) const {
    return std::tie(kind, vertex, edge, edgeT, face, u, v) <
           std::tie(other.kind, other.vertex, other.edge, other.edgeT,
                    other.face, other.u, other.v);
  }
};

double cross2(const Eigen::Vector2d &a, const Eigen::Vector2d &b);

Eigen::Vector2d bary_to_uv(const Eigen::RowVector3d &bary);

Eigen::RowVector3d uv_to_bary(const Eigen::Vector2d &uv);

double triangle_area_3d(const Eigen::MatrixXd &vertices,
                               const Eigen::MatrixXi &faces,
                               const int face);

Eigen::RowVector3d face_normal_3d(const Eigen::MatrixXd &vertices,
                                         const Eigen::MatrixXi &faces,
                                         const int face);

Eigen::RowVector3d barycentric_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const int face, const Eigen::RowVector3d &barycentric);

Eigen::RowVector3d node_position(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceArrangementNode &node);

Eigen::RowVector3d node_barycentric_on_face(
    const SurfaceArrangementNode &node, const int face);

Eigen::RowVector3d node_barycentric_on_face(
    const SurfaceArrangementNode &node, const int face,
    const int component, const int sheet);

Eigen::RowVector3d node_reference_normal(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const SurfaceArrangementNode &node);

bool tangent_basis(const Eigen::RowVector3d &normal,
                          Eigen::RowVector3d &axisX,
                          Eigen::RowVector3d &axisY);

bool polygon_geometry(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<int> &halfedges,
    const std::vector<SurfaceArrangementHalfedge> &allHalfedges,
    const std::vector<SurfaceArrangementNode> &nodes, double &signedArea,
    double &area, std::vector<int> &sourceFaces);

int source_edge(const Eigen::Vector2d &uv, const double eps = 1.0e-10);

Eigen::RowVector3d canonicalize_barycentric(
    const Eigen::RowVector3d &input, const double eps = 1.0e-10);

double local_edge_parameter(const Eigen::Vector2d &uv, const int edge);

double canonical_edge_parameter(const Eigen::MatrixXi &faces,
                                       const int face, const int edge,
                                       const Eigen::Vector2d &uv);

std::uint64_t source_edge_key(const Eigen::MatrixXi &faces,
                                     const int face, const int edge);

int source_vertex(const Eigen::RowVector3d &bary,
                         const double eps = 1.0e-10);

NodeKey make_node_key(const Eigen::MatrixXi &faces, const int face,
                             const Eigen::Vector2d &uv);

int canonical_source_edge_id(const Eigen::MatrixXi &faces, const int face,
                                    const int edge);

bool clip_to_triangle(Eigen::Vector2d &a, Eigen::Vector2d &b,
                             double &ta, double &tb);

bool segment_intersection_params(const Segment2 &a, const Segment2 &b,
                                        double &ta, double &tb,
                                        Eigen::Vector2d &point);

bool point_on_segment(const Eigen::Vector2d &p, const Segment2 &s);

double polygon_area(const std::vector<Eigen::Vector2d> &points);

bool point_in_polygon(const Eigen::Vector2d &point,
                             const std::vector<Eigen::Vector2d> &polygon);

bool proper_transverse_crossing(const Segment2 &a, const Segment2 &b,
                                       const double ta, const double tb);

std::uint64_t complex_storage_bytes(const SurfaceCellComplex &complex);

int graph_component_count(
    const int vertexCount, const std::vector<std::pair<int, int>> &edges,
    const std::vector<unsigned char> *activeMask = nullptr);

std::pair<int, bool> boundary_loop_count(
    const int vertexCount, const std::vector<std::pair<int, int>> &edges);

int boundary_orientation_vote(
    const std::vector<int> &cellHalfedges,
    const std::vector<SurfaceArrangementHalfedge> &halfedges,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXi &faces,
    const std::map<std::uint64_t, std::array<int, 2>> &edgeFaces);

void collect_cell_source_faces(
    const std::vector<int> &cellHalfedges,
    const std::vector<SurfaceArrangementHalfedge> &halfedges,
    std::vector<int> &sourceFaces);

bool same_family_collinear(
    const SurfaceArrangementHalfedge &a,
    const SurfaceArrangementHalfedge &b,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces);

/** Return whether two consecutive halfedges are one logical field line side. */
bool same_logical_side(
    const SurfaceArrangementHalfedge &a,
    const SurfaceArrangementHalfedge &b,
    const std::vector<SurfaceArrangementNode> &nodes,
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces);

} // namespace surface_arrangement_detail


const SurfaceCellOwnershipClassRecord *find_surface_cell_ownership_class(
    const SurfaceCellComplex &complex,
    const SurfaceCellCanonicalIdentity &key);

bool validate_surface_cell_ownership_registry(
    const SurfaceCellComplex &complex);

bool canonicalize_surface_cell_ownership(
    SurfaceCellComplex &complex, const Eigen::MatrixXi &faces);

SurfaceCellComplex build_surface_cell_complex(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const std::vector<SurfaceArrangementArc> &inputArcs,
    const SurfaceArrangementOptions &options = {});

SurfaceArrangementOverlay
make_surface_arrangement_overlay(const SurfaceCellComplex &complex);

std::uint64_t hash_surface_cell_complex(const SurfaceCellComplex &complex);

} // namespace directional::geometry

#endif // DIRECTIONAL_GEOMETRY_SURFACE_ARRANGEMENT_H
