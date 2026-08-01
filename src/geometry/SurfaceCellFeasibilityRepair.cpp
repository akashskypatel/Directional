#include <directional/geometry/SurfaceCellFeasibilityRepair.h>

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <limits>
#include <queue>
#include <set>
#include <tuple>
#include <utility>

namespace directional::geometry::surface_cell_feasibility_detail {

int canonical_halfedge(const SurfaceCellComplex &complex, const int id) {
  if (id < 0 || id >= static_cast<int>(complex.halfedges.size())) {
    return -1;
  }
  const int twin = complex.halfedges[static_cast<std::size_t>(id)].twin;
  if (twin < 0 || twin >= static_cast<int>(complex.halfedges.size())) {
    return -1;
  }
  return std::min(id, twin);
}

Eigen::RowVector3d interpolated_barycentric(
    const SurfaceCellComplex &complex, const int from, const int to,
    const int face, const double alpha) {
  const Eigen::RowVector3d a =
      surface_arrangement_detail::node_barycentric_on_face(
          complex.nodes[static_cast<std::size_t>(from)], face);
  const Eigen::RowVector3d b =
      surface_arrangement_detail::node_barycentric_on_face(
          complex.nodes[static_cast<std::size_t>(to)], face);
  if (!a.allFinite() || !b.allFinite()) {
    return Eigen::RowVector3d::Constant(
        std::numeric_limits<double>::quiet_NaN());
  }
  Eigen::RowVector3d result = (1.0 - alpha) * a + alpha * b;
  for (int corner = 0; corner < 3; ++corner) {
    if (std::abs(result[corner]) <= 1.0e-14) {
      result[corner] = 0.0;
    }
  }
  const double sum = result.sum();
  if (!std::isfinite(sum) || std::abs(sum) <= 1.0e-14) {
    return Eigen::RowVector3d::Constant(
        std::numeric_limits<double>::quiet_NaN());
  }
  result /= sum;
  return result;
}

void split_provenance_interval(
    const std::vector<SurfaceArrangementProvenance> &source,
    const double alpha0, const double alpha1,
    std::vector<SurfaceArrangementProvenance> &target) {
  target = source;
  for (SurfaceArrangementProvenance &value : target) {
    const double sourceStart = value.sourceT0;
    const double sourceEnd = value.sourceT1;
    const double railStart = value.railT0;
    const double railEnd = value.railT1;
    value.sourceT0 = (1.0 - alpha0) * sourceStart + alpha0 * sourceEnd;
    value.sourceT1 = (1.0 - alpha1) * sourceStart + alpha1 * sourceEnd;
    value.railT0 = (1.0 - alpha0) * railStart + alpha0 * railEnd;
    value.railT1 = (1.0 - alpha1) * railStart + alpha1 * railEnd;
  }
}

int odd_bounded_cell_count(const SurfaceCellComplex &complex) {
  return static_cast<int>(std::count_if(
      complex.cells.begin(), complex.cells.end(), [](const auto &cell) {
        return !cell.boundaryCycle && cell.halfedges.size() % 2U != 0U;
      }));
}

bool validate_incidence_allowing_nondisk(const SurfaceCellComplex &complex) {
  for (int node = 0; node < static_cast<int>(complex.nodes.size()); ++node) {
    if (complex.nodes[static_cast<std::size_t>(node)].id != node) {
      return false;
    }
  }
  std::vector<int> useCount(complex.halfedges.size(), 0);
  for (int id = 0; id < static_cast<int>(complex.halfedges.size()); ++id) {
    const SurfaceArrangementHalfedge &edge =
        complex.halfedges[static_cast<std::size_t>(id)];
    if (edge.id != id || edge.twin < 0 ||
        edge.twin >= static_cast<int>(complex.halfedges.size()) ||
        edge.next < 0 ||
        edge.next >= static_cast<int>(complex.halfedges.size()) ||
        edge.from < 0 || edge.from >= static_cast<int>(complex.nodes.size()) ||
        edge.to < 0 || edge.to >= static_cast<int>(complex.nodes.size()) ||
        edge.from == edge.to || edge.cell < 0 ||
        edge.cell >= static_cast<int>(complex.cells.size())) {
      return false;
    }
    const SurfaceArrangementHalfedge &twin =
        complex.halfedges[static_cast<std::size_t>(edge.twin)];
    if (twin.twin != id || twin.from != edge.to || twin.to != edge.from) {
      return false;
    }
  }
  for (int id = 0; id < static_cast<int>(complex.cells.size()); ++id) {
    const SurfaceArrangementCell &cell =
        complex.cells[static_cast<std::size_t>(id)];
    if (cell.id != id || !cell.closed || cell.halfedges.size() < 2U ||
        cell.sideFamilies.size() != cell.sideEdgeCounts.size()) {
      return false;
    }
    std::set<int> seenHalfedges;
    for (int index = 0; index < static_cast<int>(cell.halfedges.size());
         ++index) {
      const int edgeId = cell.halfedges[static_cast<std::size_t>(index)];
      if (edgeId < 0 || edgeId >= static_cast<int>(complex.halfedges.size()) ||
          !seenHalfedges.insert(edgeId).second) {
        return false;
      }
      const SurfaceArrangementHalfedge &edge =
          complex.halfedges[static_cast<std::size_t>(edgeId)];
      const int nextId = cell.halfedges[static_cast<std::size_t>(
          (index + 1) % static_cast<int>(cell.halfedges.size()))];
      if (edge.cell != id || edge.next != nextId ||
          edge.to != complex.halfedges[static_cast<std::size_t>(nextId)].from) {
        return false;
      }
      ++useCount[static_cast<std::size_t>(edgeId)];
    }
  }
  return std::all_of(useCount.begin(), useCount.end(),
                     [](const int count) { return count == 1; });
}

} // namespace directional::geometry::surface_cell_feasibility_detail

namespace directional::geometry {

SurfaceCellSubdivisionResult subdivide_surface_cell_complex_edges(
    const SurfaceCellComplex &input,
    const std::map<int, int> &insertionsByHalfedge) {
  SurfaceCellSubdivisionResult result;
  result.complex = input;
  if (!surface_cell_feasibility_detail::
          validate_incidence_allowing_nondisk(input)) {
    result.failure = "InvalidInputIncidence";
    return result;
  }

  std::map<int, int> insertionCount;
  for (const auto &[id, count] : insertionsByHalfedge) {
    if (count <= 0) {
      result.failure = "InvalidInsertionCount";
      return result;
    }
    const int canonical =
        surface_cell_feasibility_detail::canonical_halfedge(input, id);
    if (canonical < 0) {
      result.failure = "InvalidHalfedge";
      return result;
    }
    const auto [iterator, inserted] = insertionCount.emplace(canonical, count);
    if (!inserted && iterator->second != count) {
      result.failure = "ConflictingTwinInsertionCount";
      return result;
    }
  }
  if (insertionCount.empty()) {
    result.success = true;
    return result;
  }

  SurfaceCellComplex rebuilt;
  rebuilt.nodes = input.nodes;
  rebuilt.cells = input.cells;
  rebuilt.diagnostics = input.diagnostics;
  std::vector<std::vector<int>> replacement(input.halfedges.size());
  std::vector<unsigned char> processed(input.halfedges.size(), 0);

  const auto append_halfedge = [&](SurfaceArrangementHalfedge value) {
    value.id = static_cast<int>(rebuilt.halfedges.size());
    value.next = -1;
    rebuilt.halfedges.push_back(std::move(value));
    return static_cast<int>(rebuilt.halfedges.size()) - 1;
  };

  for (int id = 0; id < static_cast<int>(input.halfedges.size()); ++id) {
    if (processed[static_cast<std::size_t>(id)] != 0U) {
      continue;
    }
    const SurfaceArrangementHalfedge &forward =
        input.halfedges[static_cast<std::size_t>(id)];
    const int twinId = forward.twin;
    if (twinId < 0 || twinId >= static_cast<int>(input.halfedges.size()) ||
        processed[static_cast<std::size_t>(twinId)] != 0U) {
      result.failure = "InvalidTwinPair";
      return result;
    }
    const SurfaceArrangementHalfedge &reverse =
        input.halfedges[static_cast<std::size_t>(twinId)];
    processed[static_cast<std::size_t>(id)] = 1U;
    processed[static_cast<std::size_t>(twinId)] = 1U;
    const int canonical = std::min(id, twinId);
    const auto requested = insertionCount.find(canonical);
    const int insertedVertices =
        requested == insertionCount.end() ? 0 : requested->second;
    const int parts = insertedVertices + 1;

    std::vector<int> pathNodes;
    pathNodes.reserve(static_cast<std::size_t>(parts + 1));
    pathNodes.push_back(forward.from);
    for (int split = 1; split < parts; ++split) {
      const double alpha = static_cast<double>(split) /
                           static_cast<double>(parts);
      SurfaceArrangementNode node;
      node.id = static_cast<int>(rebuilt.nodes.size());
      node.sourceFace = forward.sourceFace;
      node.barycentric =
          surface_cell_feasibility_detail::interpolated_barycentric(
              input, forward.from, forward.to, forward.sourceFace, alpha);
      if (!node.barycentric.allFinite() ||
          node.barycentric.minCoeff() < -1.0e-10 ||
          node.barycentric.maxCoeff() > 1.0 + 1.0e-10) {
        result.failure = "InvalidMidpointEmbedding";
        return result;
      }
      std::set<int> occurrenceFaces;
      for (const auto &occurrence :
           input.nodes[static_cast<std::size_t>(forward.from)].occurrences) {
        occurrenceFaces.insert(occurrence.sourceFace);
      }
      occurrenceFaces.insert(forward.sourceFace);
      occurrenceFaces.insert(reverse.sourceFace);
      for (const int face : occurrenceFaces) {
        const Eigen::RowVector3d barycentric =
            surface_cell_feasibility_detail::interpolated_barycentric(
                input, forward.from, forward.to, face, alpha);
        if (barycentric.allFinite() && barycentric.minCoeff() >= -1.0e-10 &&
            barycentric.maxCoeff() <= 1.0 + 1.0e-10) {
          node.occurrences.push_back({face, barycentric});
        }
      }
      if (node.occurrences.empty()) {
        node.occurrences.push_back({node.sourceFace, node.barycentric});
      }
      const SurfaceArrangementNode &fromNode =
          input.nodes[static_cast<std::size_t>(forward.from)];
      const SurfaceArrangementNode &toNode =
          input.nodes[static_cast<std::size_t>(forward.to)];
      if (fromNode.sourceEdge >= 0 &&
          fromNode.sourceEdge == toNode.sourceEdge) {
        node.sourceEdge = fromNode.sourceEdge;
        node.sourceEdgeParameter =
            (1.0 - alpha) * fromNode.sourceEdgeParameter +
            alpha * toNode.sourceEdgeParameter;
      }
      rebuilt.nodes.push_back(std::move(node));
      pathNodes.push_back(static_cast<int>(rebuilt.nodes.size()) - 1);
    }
    pathNodes.push_back(forward.to);

    std::vector<int> forwardPieces;
    std::vector<int> reversePieces;
    forwardPieces.reserve(static_cast<std::size_t>(parts));
    reversePieces.reserve(static_cast<std::size_t>(parts));
    for (int part = 0; part < parts; ++part) {
      const double alpha0 =
          static_cast<double>(part) / static_cast<double>(parts);
      const double alpha1 =
          static_cast<double>(part + 1) / static_cast<double>(parts);
      SurfaceArrangementHalfedge piece = forward;
      piece.from = pathNodes[static_cast<std::size_t>(part)];
      piece.to = pathNodes[static_cast<std::size_t>(part + 1)];
      piece.sourceT0 =
          (1.0 - alpha0) * forward.sourceT0 + alpha0 * forward.sourceT1;
      piece.sourceT1 =
          (1.0 - alpha1) * forward.sourceT0 + alpha1 * forward.sourceT1;
      piece.railT0 =
          (1.0 - alpha0) * forward.railT0 + alpha0 * forward.railT1;
      piece.railT1 =
          (1.0 - alpha1) * forward.railT0 + alpha1 * forward.railT1;
      surface_cell_feasibility_detail::split_provenance_interval(
          forward.provenance, alpha0, alpha1, piece.provenance);
      forwardPieces.push_back(append_halfedge(std::move(piece)));

      SurfaceArrangementHalfedge twinPiece = reverse;
      twinPiece.from = pathNodes[static_cast<std::size_t>(parts - part)];
      twinPiece.to = pathNodes[static_cast<std::size_t>(parts - part - 1)];
      twinPiece.sourceT0 =
          (1.0 - alpha0) * reverse.sourceT0 + alpha0 * reverse.sourceT1;
      twinPiece.sourceT1 =
          (1.0 - alpha1) * reverse.sourceT0 + alpha1 * reverse.sourceT1;
      twinPiece.railT0 =
          (1.0 - alpha0) * reverse.railT0 + alpha0 * reverse.railT1;
      twinPiece.railT1 =
          (1.0 - alpha1) * reverse.railT0 + alpha1 * reverse.railT1;
      surface_cell_feasibility_detail::split_provenance_interval(
          reverse.provenance, alpha0, alpha1, twinPiece.provenance);
      reversePieces.push_back(append_halfedge(std::move(twinPiece)));
    }
    for (int part = 0; part < parts; ++part) {
      const int forwardId = forwardPieces[static_cast<std::size_t>(part)];
      const int reverseId =
          reversePieces[static_cast<std::size_t>(parts - part - 1)];
      rebuilt.halfedges[static_cast<std::size_t>(forwardId)].twin = reverseId;
      rebuilt.halfedges[static_cast<std::size_t>(reverseId)].twin = forwardId;
    }
    replacement[static_cast<std::size_t>(id)] = forwardPieces;
    replacement[static_cast<std::size_t>(twinId)] = reversePieces;
    if (insertedVertices > 0) {
      ++result.splitUndirectedEdges;
      result.insertedVertices += insertedVertices;
      if (forward.hardFeature || reverse.hardFeature) {
        ++result.hardFeatureSplits;
      }
    }
  }

  for (SurfaceArrangementCell &cell : rebuilt.cells) {
    const std::vector<int> oldBoundary = cell.halfedges;
    std::vector<int> newBoundary;
    std::vector<int> newSideCounts(cell.sideEdgeCounts.size(), 0);
    const bool sideMetadataValid =
        cell.sideFamilies.size() == cell.sideEdgeCounts.size() &&
        std::accumulate(cell.sideEdgeCounts.begin(), cell.sideEdgeCounts.end(),
                        0) == static_cast<int>(oldBoundary.size());
    int side = 0;
    int usedOnSide = 0;
    for (const int oldId : oldBoundary) {
      if (oldId < 0 || oldId >= static_cast<int>(replacement.size()) ||
          replacement[static_cast<std::size_t>(oldId)].empty()) {
        result.failure = "MissingHalfedgeReplacement";
        return result;
      }
      const auto &pieces = replacement[static_cast<std::size_t>(oldId)];
      newBoundary.insert(newBoundary.end(), pieces.begin(), pieces.end());
      if (sideMetadataValid) {
        while (side < static_cast<int>(cell.sideEdgeCounts.size()) &&
               usedOnSide >= cell.sideEdgeCounts[static_cast<std::size_t>(side)]) {
          ++side;
          usedOnSide = 0;
        }
        if (side >= static_cast<int>(newSideCounts.size())) {
          result.failure = "InvalidSideMetadata";
          return result;
        }
        newSideCounts[static_cast<std::size_t>(side)] +=
            static_cast<int>(pieces.size());
        ++usedOnSide;
      }
    }
    cell.halfedges = std::move(newBoundary);
    if (sideMetadataValid) {
      cell.sideEdgeCounts = std::move(newSideCounts);
    } else {
      cell.sideFamilies.clear();
      cell.sideEdgeCounts.clear();
    }
    for (int index = 0; index < static_cast<int>(cell.halfedges.size());
         ++index) {
      const int halfedgeId = cell.halfedges[static_cast<std::size_t>(index)];
      SurfaceArrangementHalfedge &halfedge =
          rebuilt.halfedges[static_cast<std::size_t>(halfedgeId)];
      halfedge.cell = cell.id;
      halfedge.next = cell.halfedges[static_cast<std::size_t>(
          (index + 1) % static_cast<int>(cell.halfedges.size()))];
    }
    std::set<int> uniqueNodes;
    for (const int halfedgeId : cell.halfedges) {
      uniqueNodes.insert(
          rebuilt.halfedges[static_cast<std::size_t>(halfedgeId)].from);
    }
    cell.boundaryComponentCount = cell.closed ? 1 : 0;
    cell.eulerCharacteristic =
        static_cast<int>(uniqueNodes.size()) -
        static_cast<int>(cell.halfedges.size()) + (cell.closed ? 1 : 0);
    cell.disk = cell.closed && cell.boundaryComponentCount == 1 &&
                uniqueNodes.size() == cell.halfedges.size() &&
                cell.eulerCharacteristic == 1;
  }

  if (!surface_cell_feasibility_detail::
          validate_incidence_allowing_nondisk(rebuilt)) {
    result.failure = "InvalidOutputIncidence";
    return result;
  }
  rebuilt.diagnostics.incidenceValid = true;
  rebuilt.diagnostics.topologyValid =
      input.diagnostics.topologyValid && rebuilt.diagnostics.incidenceValid;
  result.complex = std::move(rebuilt);
  result.success = true;
  return result;
}

SurfaceCellParityRepairResult repair_surface_cell_boundary_parity(
    const SurfaceCellComplex &input) {
  SurfaceCellParityRepairResult result;
  result.complex = input;
  result.oddCellsBefore =
      surface_cell_feasibility_detail::odd_bounded_cell_count(input);
  if (result.oddCellsBefore == 0) {
    result.success = true;
    return result;
  }
  if (!surface_cell_feasibility_detail::
          validate_incidence_allowing_nondisk(input)) {
    result.failure = "InvalidInputIncidence";
    return result;
  }

  struct DualEdge {
    int neighbor = -1;
    int halfedge = -1;
    bool hardFeature = false;
  };
  std::vector<std::vector<DualEdge>> adjacency(input.cells.size());
  for (const SurfaceArrangementHalfedge &halfedge : input.halfedges) {
    if (halfedge.id > halfedge.twin) {
      continue;
    }
    const SurfaceArrangementHalfedge &twin =
        input.halfedges[static_cast<std::size_t>(halfedge.twin)];
    if (halfedge.cell == twin.cell) {
      continue;
    }
    const bool hard = halfedge.hardFeature || twin.hardFeature;
    adjacency[static_cast<std::size_t>(halfedge.cell)].push_back(
        {twin.cell, halfedge.id, hard});
    adjacency[static_cast<std::size_t>(twin.cell)].push_back(
        {halfedge.cell, halfedge.id, hard});
  }
  for (auto &neighbors : adjacency) {
    std::sort(neighbors.begin(), neighbors.end(),
              [](const DualEdge &a, const DualEdge &b) {
                return std::tie(a.hardFeature, a.halfedge, a.neighbor) <
                       std::tie(b.hardFeature, b.halfedge, b.neighbor);
              });
  }

  std::vector<unsigned char> globallyVisited(input.cells.size(), 0U);
  std::set<int> selected;
  for (int start = 0; start < static_cast<int>(input.cells.size()); ++start) {
    if (globallyVisited[static_cast<std::size_t>(start)] != 0U) {
      continue;
    }
    std::vector<int> component;
    std::queue<int> discover;
    discover.push(start);
    globallyVisited[static_cast<std::size_t>(start)] = 1U;
    while (!discover.empty()) {
      const int cell = discover.front();
      discover.pop();
      component.push_back(cell);
      for (const DualEdge &edge : adjacency[static_cast<std::size_t>(cell)]) {
        if (globallyVisited[static_cast<std::size_t>(edge.neighbor)] == 0U) {
          globallyVisited[static_cast<std::size_t>(edge.neighbor)] = 1U;
          discover.push(edge.neighbor);
        }
      }
    }
    int root = *std::min_element(component.begin(), component.end());
    for (const int cell : component) {
      if (input.cells[static_cast<std::size_t>(cell)].boundaryCycle) {
        root = cell;
        break;
      }
    }

    using QueueEntry = std::tuple<std::int64_t, int, int>;
    std::priority_queue<QueueEntry, std::vector<QueueEntry>,
                        std::greater<QueueEntry>> queue;
    std::vector<std::int64_t> distance(
        input.cells.size(), std::numeric_limits<std::int64_t>::max());
    std::vector<int> parent(input.cells.size(), -1);
    std::vector<int> parentEdge(input.cells.size(), -1);
    std::vector<int> order;
    distance[static_cast<std::size_t>(root)] = 0;
    queue.emplace(0, root, -1);
    while (!queue.empty()) {
      const auto [cost, cell, unused] = queue.top();
      (void)unused;
      queue.pop();
      if (cost != distance[static_cast<std::size_t>(cell)]) {
        continue;
      }
      order.push_back(cell);
      for (const DualEdge &edge : adjacency[static_cast<std::size_t>(cell)]) {
        const std::int64_t edgeCost =
            edge.hardFeature ? 1000000LL : 1LL;
        const std::int64_t candidate = cost + edgeCost;
        const auto candidateKey =
            std::make_tuple(candidate, cell, edge.halfedge);
        const auto previousKey = std::make_tuple(
            distance[static_cast<std::size_t>(edge.neighbor)],
            parent[static_cast<std::size_t>(edge.neighbor)],
            parentEdge[static_cast<std::size_t>(edge.neighbor)]);
        if (candidateKey < previousKey) {
          distance[static_cast<std::size_t>(edge.neighbor)] = candidate;
          parent[static_cast<std::size_t>(edge.neighbor)] = cell;
          parentEdge[static_cast<std::size_t>(edge.neighbor)] = edge.halfedge;
          queue.emplace(candidate, edge.neighbor, edge.halfedge);
        }
      }
    }
    if (order.size() != component.size()) {
      result.failure = "DisconnectedDualComponent";
      return result;
    }
    std::vector<unsigned char> parity(input.cells.size(), 0U);
    for (const int cell : component) {
      if (!input.cells[static_cast<std::size_t>(cell)].boundaryCycle &&
          input.cells[static_cast<std::size_t>(cell)].halfedges.size() % 2U !=
              0U) {
        parity[static_cast<std::size_t>(cell)] = 1U;
      }
    }
    for (auto iterator = order.rbegin(); iterator != order.rend(); ++iterator) {
      const int cell = *iterator;
      if (cell == root || parity[static_cast<std::size_t>(cell)] == 0U) {
        continue;
      }
      const int edge = parentEdge[static_cast<std::size_t>(cell)];
      const int ancestor = parent[static_cast<std::size_t>(cell)];
      if (edge < 0 || ancestor < 0) {
        result.failure = "UnpairableOddCell";
        return result;
      }
      selected.insert(edge);
      parity[static_cast<std::size_t>(ancestor)] ^= 1U;
    }
    if (!input.cells[static_cast<std::size_t>(root)].boundaryCycle &&
        parity[static_cast<std::size_t>(root)] != 0U) {
      result.failure = "UnpairableClosedComponentParity";
      return result;
    }
  }

  std::map<int, int> insertions;
  for (const int halfedge : selected) {
    insertions.emplace(halfedge, 1);
  }
  const SurfaceCellSubdivisionResult subdivision =
      subdivide_surface_cell_complex_edges(input, insertions);
  if (!subdivision.success) {
    result.failure = subdivision.failure;
    return result;
  }
  result.complex = subdivision.complex;
  result.hardFeatureSplits = subdivision.hardFeatureSplits;
  result.splitHalfedges.assign(selected.begin(), selected.end());
  result.oddCellsAfter =
      surface_cell_feasibility_detail::odd_bounded_cell_count(result.complex);
  result.success = result.oddCellsAfter == 0;
  if (!result.success) {
    result.failure = "ParityRepairIncomplete";
  }
  return result;
}

} // namespace directional::geometry
