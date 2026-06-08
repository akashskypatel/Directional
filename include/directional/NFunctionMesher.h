//
// Created by Amir Vaxman on 20.04.24.
//

#ifndef DIRECTIONAL_N_FUNCTION_MESHER
#define DIRECTIONAL_N_FUNCTION_MESHER

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <algorithm>
#include <chrono>
#include <directional/dcel.h>
#include <directional/exact_geometric_definitions.h>
#include <directional/setup_mesher.h>
#include <limits>
#include <math.h>
#include <queue>
#include <set>
#include <stdexcept>
#include <utility>
#include <vector>


namespace directional {

class NFunctionMesher {
public:
  const TriMesh &origMesh;
  const MesherData &mData;

  struct SegmentData {
    bool isFunction;
    int origHalfedge;
    int origNFunctionIndex; // the original parameteric function assoicated with
                            // this edge
    int lineInPencil;
    std::set<ENumber> intParams;
    // double prescribedAngle;  //the actual prescribed angle

    SegmentData()
        : isFunction(false), origHalfedge(-1), origNFunctionIndex(-1),
          lineInPencil(-1), intParams() {} // prescribedAngle(-1.0){}
  };

  struct VData {
    Eigen::RowVector3d coords;
    EVector3 eCoords;
  };

  typedef DCEL<VData, SegmentData, bool, bool> FunctionDCEL;
  FunctionDCEL genDcel;

  // halfedge quantities
  Eigen::MatrixXd NFunction;
  std::vector<std::vector<ENumber>> exactNFunction;

  // mesh generation functions found in generate_mesh.h
  void
  arrange_on_triangle(const std::vector<EVector2> &triangle,
                      const std::vector<std::pair<int, bool>> &triangleData,
                      const std::vector<LinePencil> &linePencils,
                      const std::vector<int> &linePencilData,
                      std::vector<EVector2> &V, FunctionDCEL &triDcel);

  void
  segment_arrangement(const std::vector<Segment2> &segments,
                      const std::vector<SegmentData> &data,
                      const Eigen::Matrix<ENumber, Eigen::Dynamic, 2> I2dts,
                      const Eigen::Matrix<ENumber, Eigen::Dynamic, 1> t00s,
                      std::vector<EVector2> &V, FunctionDCEL &triDcel);

  void generate_mesh(const unsigned long Resolution);

  std::vector<int> TransVertices;
  std::vector<int> InStrip;
  std::vector<std::set<int>> VertexChains;

  struct MergeData {
    const bool operator()(const int &v1, const int &v2) const { return v1; }
  };

  void TestUnmatchedTwins();

  struct PointPair {
    int Index1, Index2;
    ENumber Distance;

    PointPair(int i1, int i2, const EVector3 &d) : Index1(i1), Index2(i2) {
      Distance = d.max_abs();
    }
    ~PointPair() {}

    const bool operator<(const PointPair &pp) const {
      if (Distance > pp.Distance)
        return false;
      if (Distance < pp.Distance)
        return true;

      if (Index1 > pp.Index1)
        return false;
      if (Index1 < pp.Index1)
        return true;

      if (Index2 > pp.Index2)
        return false;
      if (Index2 < pp.Index2)
        return true;

      return false;
    }
  };

  std::vector<std::pair<int, int>>
  FindVertexMatch(const bool verbose, const std::vector<EVector3> &Set1,
                  const std::vector<EVector3> &Set2) {
    if (Set1.size() != Set2.size()) {
      throw std::invalid_argument(
          "Directional::NFunctionMesher::FindVertexMatch(): "
          "the two point sets must have equal sizes");
    }

    // An empty strip is valid and has no vertex correspondences.
    if (Set1.empty()) {
      if (verbose) {
        std::cout << "[Directional::NFunctionMesher::FindVertexMatch()]: "
                  << "both point sets are empty; returning no matches"
                  << std::endl;
      }

      return {};
    }

    const std::size_t pointCount = Set1.size();

    /*
     * Build candidate pairs only after validating both inputs.
     */
    std::set<PointPair> PairSet;

    constexpr std::size_t warnPairCount = 1'000'000;
    constexpr std::size_t severePairCount = 10'000'000;

    const bool wouldOverflow =
        pointCount != 0 &&
        pointCount > std::numeric_limits<std::size_t>::max() / pointCount;

    if (wouldOverflow) {
      throw std::overflow_error(
          "Directional::NFunctionMesher::FindVertexMatch(): "
          "candidate pair count overflows size_t");
    }

    const std::size_t candidatePairCount = pointCount * pointCount;

    if (verbose && candidatePairCount >= warnPairCount) {
      std::cerr << "[Directional::NFunctionMesher::FindVertexMatch()]: "
                << "warning: generating " << candidatePairCount
                << " candidate pairs from " << pointCount << " x " << pointCount
                << " boundary vertices. "
                << "This is O(n^2) and may appear hung." << std::endl;
    }

    if (verbose && candidatePairCount >= severePairCount) {
      std::cerr << "[Directional::NFunctionMesher::FindVertexMatch()]: "
                << "severe warning: this allocation/sort may be very slow or "
                   "memory-heavy."
                << std::endl;
    }

    for (std::size_t i = 0; i < pointCount; ++i) {
      for (std::size_t j = 0; j < pointCount; ++j) {
        PairSet.insert(PointPair(static_cast<int>(i), static_cast<int>(j),
                                 Set1[i] - Set2[j]));
      }
    }

    std::vector<bool> Set1Connect(pointCount, false);
    std::vector<bool> Set2Connect(pointCount, false);

    std::vector<std::pair<int, int>> Result;
    Result.reserve(pointCount);

    /*
     * Categorically match both ends.
     *
     * For a one-point strip, the first and last endpoints are the
     * same and must only be inserted once.
     */
    Result.emplace_back(0, 0);
    Set1Connect[0] = true;
    Set2Connect[0] = true;

    if (pointCount > 1) {
      const int last = static_cast<int>(pointCount - 1);

      Result.emplace_back(last, last);
      Set1Connect[last] = true;
      Set2Connect[last] = true;
    }

    /*
     * Add legal connections greedily in ascending squared-distance
     * order while preserving monotonic ordering along both strips.
     */
    for (const PointPair &currentPair : PairSet) {
      /*
       * If both points are already represented, this pair adds
       * nothing. One-to-many mappings remain allowed by the
       * original algorithm.
       */
      if (Set1Connect[currentPair.Index1] && Set2Connect[currentPair.Index2]) {
        continue;
      }

      bool foundConflict = false;

      for (const auto &match : Result) {
        const bool crossesForward = match.first > currentPair.Index1 &&
                                    match.second < currentPair.Index2;

        const bool crossesBackward = match.first < currentPair.Index1 &&
                                     match.second > currentPair.Index2;

        if (crossesForward || crossesBackward) {
          foundConflict = true;
          break;
        }
      }

      if (foundConflict) {
        continue;
      }

      Result.emplace_back(currentPair.Index1, currentPair.Index2);

      Set1Connect[currentPair.Index1] = true;
      Set2Connect[currentPair.Index2] = true;
    }

    if (verbose) {
      for (std::size_t i = 0; i < pointCount; ++i) {
        if (!Set1Connect[i]) {
          std::cout << "[Directional::NFunctionMesher::"
                       "FindVertexMatch()]: "
                    << "Relative Vertex " << i << " in Set1 is unmatched!"
                    << std::endl;
        }
      }

      for (std::size_t i = 0; i < pointCount; ++i) {
        if (!Set2Connect[i]) {
          std::cout << "[Directional::NFunctionMesher::"
                       "FindVertexMatch()]: "
                    << "Relative Vertex " << i << " in Set2 is unmatched!"
                    << std::endl;
        }
      }

      for (const auto &match : Result) {
        const ENumber distance =
            squaredDistance(Set1[match.first], Set2[match.second]);

        if (distance > ENumber(0)) {
          std::cout << "[Directional::NFunctionMesher::"
                       "FindVertexMatch()]: "
                    << "(" << match.first << "," << match.second
                    << ") with dist " << distance.to_double() << std::endl;

          std::cout << "[Directional::NFunctionMesher::"
                       "FindVertexMatch()]: "
                    << "Distance is abnormally not zero!" << std::endl;
        }
      }
    }

    return Result;
  }

  struct SimplifyScratch {
    int maxOrigHE = -1;
    std::vector<bool> visitedOrig;
    std::vector<std::vector<int>> boundEdgeCollect1;
    std::vector<std::vector<int>> boundEdgeCollect2;
    std::vector<std::vector<int>> vertexSets1;
    std::vector<std::vector<int>> vertexSets2;
    std::vector<std::pair<int, int>> vertexMatches;
    std::vector<bool> marked;
    std::vector<bool> isPureTriangle;
    std::vector<bool> isBoundary;
    std::vector<bool> isEar;
    std::vector<int> valences;
  };

  bool should_log_progress(const int index, const int total) const {
    if (!mData.verbose || total <= 0)
      return false;
    if (index == 0 || index + 1 == total)
      return true;
    const int step = std::max(1, total / 10);
    return ((index + 1) % step) == 0;
  }

  void log_progress(const char *label, const int index, const int total) const {
    if (!should_log_progress(index, total))
      return;
    std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: " << label
              << ": " << (index + 1) << "/" << total << std::endl;
  }

  bool run_initial_consistency_check() {
    return genDcel.check_consistency(mData.verbose, false, false, false);
  }

  void scan_original_halfedge_range(SimplifyScratch &scratch) {
    scratch.maxOrigHE = -1;

    for (const auto &he : genDcel.halfedges) {
      if (!he.valid || he.data.origHalfedge < 0)
        continue;

      scratch.maxOrigHE = std::max(scratch.maxOrigHE, he.data.origHalfedge);
    }
  }

  bool visit_boundary_seeds(SimplifyScratch &scratch) {
    scratch.visitedOrig.assign(scratch.maxOrigHE + 1, false);
    for (int i = 0; i < genDcel.halfedges.size(); i++) {
      log_progress("boundary seed scan", i,
                   static_cast<int>(genDcel.halfedges.size()));
      if (genDcel.halfedges[i].data.origHalfedge < 0)
        continue;
      if (scratch.visitedOrig[genDcel.halfedges[i].data.origHalfedge])
        continue;

      const int hebegin = i;
      int heiterate = hebegin;
      do {
        const int orig = genDcel.halfedges[heiterate].data.origHalfedge;

        if (orig < 0 || orig > scratch.maxOrigHE) {
          return false;
        }

        scratch.visitedOrig[orig] = true;
        if (!genDcel.walk_boundary(heiterate, mData.verbose,
                                   "[Directional::DCEL] walk_boundary()")) {
          if (mData.verbose) {
            std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: "
                         "boundary seed walk failed for seed "
                      << i << " at halfedge " << heiterate << std::endl;
          }
          break;
        }
      } while (heiterate != hebegin);
    }

    return true;
  }

  bool next_boundary_halfedge(const int current, int &next_boundary,
                              const char *context) const {
    const int halfedge_count = static_cast<int>(genDcel.halfedges.size());

    const auto valid_halfedge = [&](const int he) {
      return he >= 0 && he < halfedge_count && genDcel.halfedges[he].valid;
    };

    if (!valid_halfedge(current)) {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::" << context
                  << "]: invalid starting halfedge " << current << '\n';
      }
      return false;
    }

    // This routine walks from one boundary halfedge to the next.
    if (genDcel.halfedges[current].twin >= 0) {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::" << context
                  << "]: halfedge " << current
                  << " is not a boundary halfedge\n";
      }
      return false;
    }

    int cursor = current;

    // A valid vertex fan cannot require more than the total number of
    // halfedges. This bound guarantees termination even for corrupt DCELs.
    for (int steps = 0; steps < halfedge_count; ++steps) {
      if (!valid_halfedge(cursor)) {
        if (mData.verbose) {
          std::cerr << "[Directional::NFunctionMesher::" << context
                    << "]: invalid fan halfedge " << cursor << '\n';
        }
        return false;
      }

      const int next = genDcel.halfedges[cursor].next;
      if (!valid_halfedge(next)) {
        if (mData.verbose) {
          std::cerr << "[Directional::NFunctionMesher::" << context
                    << "]: halfedge " << cursor << " has invalid next " << next
                    << '\n';
        }
        return false;
      }

      cursor = next;

      const int twin = genDcel.halfedges[cursor].twin;

      if (twin < 0) {
        next_boundary = cursor;
        return true;
      }

      if (!valid_halfedge(twin)) {
        if (mData.verbose) {
          std::cerr << "[Directional::NFunctionMesher::" << context
                    << "]: halfedge " << cursor << " has invalid twin " << twin
                    << '\n';
        }
        return false;
      }

      cursor = twin;

      // An interior cycle returned to the original boundary halfedge
      // without finding another boundary edge.
      if (cursor == current) {
        if (mData.verbose) {
          std::cerr << "[Directional::NFunctionMesher::" << context
                    << "]: closed fan cycle at halfedge " << current << '\n';
        }
        return false;
      }
    }

    if (mData.verbose) {
      std::cerr << "[Directional::NFunctionMesher::" << context
                << "]: traversal exceeded " << halfedge_count
                << " steps from halfedge " << current << '\n';
    }

    return false;
  }

  bool collect_boundary_strips(SimplifyScratch &scratch) {
    if (scratch.maxOrigHE < 0) {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "collect_boundary_strips]: "
                     "no valid original-halfedge IDs\n";
      }
      return false;
    }

    scratch.boundEdgeCollect1.assign(scratch.maxOrigHE + 1, std::vector<int>());

    scratch.boundEdgeCollect2.assign(scratch.maxOrigHE + 1, std::vector<int>());

    scratch.marked.assign(genDcel.halfedges.size(), false);

    const int halfedge_count = static_cast<int>(genDcel.halfedges.size());

    const auto valid_orig = [&](const int orig) {
      return orig >= 0 && orig <= scratch.maxOrigHE;
    };

    for (int seed = 0; seed < halfedge_count; ++seed) {
      log_progress("boundary strip collection", seed, halfedge_count);

      const auto &seed_he = genDcel.halfedges[seed];

      if (!seed_he.valid || seed_he.twin >= 0 ||
          !valid_orig(seed_he.data.origHalfedge) || scratch.marked[seed]) {
        continue;
      }

      /*
       * Find the first edge immediately after an origHalfedge
       * transition. This preserves the original behavior of beginning a
       * component at the start of an orig-ID run.
       *
       * Crucially, if the entire boundary component has one orig ID,
       * traversal returns to seed and we use seed as the beginning.
       */
      int begin_edge = seed;
      int current = seed;

      std::vector<unsigned char> transition_visited(
          static_cast<std::size_t>(halfedge_count), 0);

      while (true) {
        if (current < 0 || current >= halfedge_count) {
          return false;
        }

        if (transition_visited[current]) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "collect_boundary_strips]: "
                         "transition search entered an unexpected "
                         "cycle from seed "
                      << seed << '\n';
          }
          return false;
        }

        transition_visited[current] = 1;

        const int previous_orig = genDcel.halfedges[current].data.origHalfedge;

        int next = -1;

        if (!next_boundary_halfedge(
                current, next, "collect_boundary_strips transition search")) {
          return false;
        }

        // The complete component had no orig-ID transition.
        if (next == seed) {
          begin_edge = seed;
          break;
        }

        const int next_orig = genDcel.halfedges[next].data.origHalfedge;

        if (!valid_orig(next_orig)) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "collect_boundary_strips]: "
                         "invalid origHalfedge "
                      << next_orig << " at boundary halfedge " << next << '\n';
          }
          return false;
        }

        current = next;

        if (previous_orig != next_orig) {
          begin_edge = current;
          break;
        }
      }

      /*
       * Collect one complete boundary component.
       *
       * Do not write scratch.marked until the component closes
       * successfully. A failed traversal therefore leaves no partial
       * state behind.
       */
      std::vector<std::pair<int, int>> component;
      std::vector<unsigned char> component_visited(
          static_cast<std::size_t>(halfedge_count), 0);

      current = begin_edge;

      while (true) {
        if (current < 0 || current >= halfedge_count ||
            component_visited[current]) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "collect_boundary_strips]: "
                         "component starting at "
                      << begin_edge << " did not close correctly\n";
          }
          return false;
        }

        component_visited[current] = 1;

        const int orig = genDcel.halfedges[current].data.origHalfedge;

        if (!valid_orig(orig)) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "collect_boundary_strips]: "
                         "invalid origHalfedge "
                      << orig << " at halfedge " << current << '\n';
          }
          return false;
        }

        component.emplace_back(orig, current);

        int next = -1;

        if (!next_boundary_halfedge(current, next,
                                    "collect_boundary_strips component walk")) {
          return false;
        }

        if (next == begin_edge)
          break;

        if (scratch.marked[next]) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "collect_boundary_strips]: "
                         "component starting at "
                      << begin_edge
                      << " intersects an already collected component at "
                      << next << '\n';
          }
          return false;
        }

        current = next;
      }

      // Commit only after successful closure.
      for (const auto &[orig, halfedge] : component) {
        scratch.marked[halfedge] = true;
      }

      int previous_orig = -1;
      bool use_first_side = false;

      for (const auto &[orig, halfedge] : component) {
        if (orig != previous_orig) {
          use_first_side = scratch.boundEdgeCollect1[orig].empty();
        }

        if (use_first_side) {
          scratch.boundEdgeCollect1[orig].push_back(halfedge);
        } else {
          scratch.boundEdgeCollect2[orig].push_back(halfedge);
        }

        previous_orig = orig;
      }
    }

    return true;
  }

  void build_boundary_vertex_sets(SimplifyScratch &scratch) {
    scratch.vertexSets1.assign(scratch.maxOrigHE + 1, std::vector<int>());
    scratch.vertexSets2.assign(scratch.maxOrigHE + 1, std::vector<int>());

    for (int i = 0; i < scratch.maxOrigHE + 1; i++) {
      log_progress("vertex set build", i, scratch.maxOrigHE + 1);
      for (int j = 0; j < scratch.boundEdgeCollect1[i].size(); j++)
        scratch.vertexSets1[i].push_back(
            genDcel.halfedges[scratch.boundEdgeCollect1[i][j]].vertex);

      if (scratch.boundEdgeCollect1[i].size() > 0)
        scratch.vertexSets1[i].push_back(
            genDcel
                .halfedges
                    [genDcel
                         .halfedges
                             [scratch.boundEdgeCollect1
                                  [i][scratch.boundEdgeCollect1[i].size() - 1]]
                         .next]
                .vertex);

      for (int j = 0; j < scratch.boundEdgeCollect2[i].size(); j++)
        scratch.vertexSets2[i].push_back(
            genDcel.halfedges[scratch.boundEdgeCollect2[i][j]].vertex);

      if (scratch.boundEdgeCollect2[i].size() > 0)
        scratch.vertexSets2[i].push_back(
            genDcel
                .halfedges
                    [genDcel
                         .halfedges
                             [scratch.boundEdgeCollect2
                                  [i][scratch.boundEdgeCollect2[i].size() - 1]]
                         .next]
                .vertex);

      std::reverse(scratch.vertexSets2[i].begin(),
                   scratch.vertexSets2[i].end());
    }
  }

  void build_vertex_matches(SimplifyScratch &scratch) {
    scratch.vertexMatches.clear();
    for (int i = 0; i < scratch.maxOrigHE + 1; i++) {
      log_progress("vertex match build", i, scratch.maxOrigHE + 1);
      std::vector<EVector3> PointSet1(scratch.vertexSets1[i].size());
      std::vector<EVector3> PointSet2(scratch.vertexSets2[i].size());
      for (int j = 0; j < PointSet1.size(); j++)
        PointSet1[j] = genDcel.vertices[scratch.vertexSets1[i][j]].data.eCoords;

      for (int j = 0; j < PointSet2.size(); j++)
        PointSet2[j] = genDcel.vertices[scratch.vertexSets2[i][j]].data.eCoords;

      std::vector<std::pair<int, int>> CurrMatches;
      if ((!PointSet1.empty()) && (!PointSet2.empty()))
        CurrMatches = FindVertexMatch(mData.verbose, PointSet1, PointSet2);

      for (int j = 0; j < CurrMatches.size(); j++) {
        CurrMatches[j].first = scratch.vertexSets1[i][CurrMatches[j].first];
        CurrMatches[j].second = scratch.vertexSets2[i][CurrMatches[j].second];
      }

      scratch.vertexMatches.insert(scratch.vertexMatches.end(),
                                   CurrMatches.begin(), CurrMatches.end());
    }
  }

  double scan_vertex_match_distance(const SimplifyScratch &scratch) const {
    double MaxDist = -327670000.0;
    for (int i = 0; i < scratch.vertexMatches.size(); i++)
      MaxDist = std::max(
          MaxDist,
          (genDcel.vertices[scratch.vertexMatches[i].first].data.coords -
           genDcel.vertices[scratch.vertexMatches[i].second].data.coords)
              .squaredNorm());

    if (mData.verbose)
      std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: "
                << "Max matching distance: " << MaxDist << std::endl;

    return MaxDist;
  }

  int compute_vertex_representatives(const SimplifyScratch &scratch) {
    TransVertices.resize(genDcel.vertices.size());
    return connectedComponents(scratch.vertexMatches, TransVertices);
  }

  void rebuild_vertex_table(const int numNewVertices) {
    std::vector<bool> transClaimed(numNewVertices);
    for (int i = 0; i < numNewVertices; i++)
      transClaimed[i] = false;

    std::vector<FunctionDCEL::Vertex> NewVertices(numNewVertices);
    for (int i = 0; i < genDcel.vertices.size(); i++) {
      log_progress("vertex representative rebuild", i,
                   static_cast<int>(genDcel.vertices.size()));
      if (!genDcel.vertices[i].valid)
        continue;
      FunctionDCEL::Vertex NewVertex = genDcel.vertices[i];
      NewVertex.ID = TransVertices[i];
      transClaimed[TransVertices[i]] = true;
      NewVertices[TransVertices[i]] = NewVertex;
    }

    for (int i = 0; i < numNewVertices; i++)
      if (!transClaimed[i])
        NewVertices[i].valid = false;

    genDcel.vertices = NewVertices;
  }

  void remap_halfedge_vertices(std::vector<int> &preRemapOrigin,
                               std::vector<int> &preRemapTarget) {
    for (int i = 0; i < genDcel.halfedges.size(); i++) {
      log_progress("halfedge vertex remap", i,
                   static_cast<int>(genDcel.halfedges.size()));
      if (!genDcel.halfedges[i].valid)
        continue;
      preRemapOrigin[i] = genDcel.halfedges[i].vertex;
      if (genDcel.halfedges[i].next >= 0)
        preRemapTarget[i] = genDcel.halfedges[genDcel.halfedges[i].next].vertex;
      genDcel.halfedges[i].vertex = TransVertices[genDcel.halfedges[i].vertex];
      genDcel.vertices[genDcel.halfedges[i].vertex].halfedge = i;
    }
  }

  void prune_remap_created_degenerates(const std::vector<int> &preRemapOrigin,
                                       const std::vector<int> &preRemapTarget) {
    int prunedCount = 0;
    int detailedLogs = 0;
    for (int i = 0; i < genDcel.halfedges.size(); i++) {
      if (!genDcel.halfedges[i].valid)
        continue;
      const int next = genDcel.halfedges[i].next;
      if (next < 0 || !genDcel.halfedges[next].valid)
        continue;
      if (genDcel.halfedges[i].vertex != genDcel.halfedges[next].vertex)
        continue;

      if (mData.verbose && detailedLogs < 8) {
        std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: pruning "
                     "remap-created degenerate halfedge "
                  << i
                  << " origHalfedge=" << genDcel.halfedges[i].data.origHalfedge
                  << " face=" << genDcel.halfedges[i].face
                  << " edge=" << genDcel.halfedges[i].edge
                  << " twin=" << genDcel.halfedges[i].twin << " before=("
                  << preRemapOrigin[i] << " -> " << preRemapTarget[i] << ")"
                  << " after=(" << genDcel.halfedges[i].vertex << " -> "
                  << genDcel.halfedges[next].vertex << ")"
                  << " reps=("
                  << (preRemapOrigin[i] >= 0 ? TransVertices[preRemapOrigin[i]]
                                             : -1)
                  << ", "
                  << (preRemapTarget[i] >= 0 ? TransVertices[preRemapTarget[i]]
                                             : -1)
                  << ")" << std::endl;
        detailedLogs++;
      }

      const int twin = genDcel.halfedges[i].twin;
      if (twin >= 0)
        genDcel.halfedges[twin].twin = -1;
      if (genDcel.halfedges[i].edge >= 0)
        genDcel.edges[genDcel.halfedges[i].edge].valid = false;
      genDcel.halfedges[i].twin = -1;
      genDcel.halfedges[i].valid = false;
      prunedCount++;
    }

    if (mData.verbose)
      std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: pruned "
                   "remap-created degenerate halfedges: "
                << prunedCount << std::endl;

    int invalidatedVertices = 0;
    for (int i = 0; i < genDcel.vertices.size(); i++)
      genDcel.vertices[i].halfedge = -1;
    for (int i = 0; i < genDcel.halfedges.size(); i++) {
      if (!genDcel.halfedges[i].valid)
        continue;
      const int vertex = genDcel.halfedges[i].vertex;
      if (vertex >= 0 && genDcel.vertices[vertex].valid &&
          genDcel.vertices[vertex].halfedge < 0)
        genDcel.vertices[vertex].halfedge = i;
    }
    for (int i = 0; i < genDcel.vertices.size(); i++) {
      if (!genDcel.vertices[i].valid)
        continue;
      if (genDcel.vertices[i].halfedge >= 0)
        continue;
      genDcel.vertices[i].valid = false;
      invalidatedVertices++;
    }
    if (mData.verbose && invalidatedVertices > 0)
      std::cout
          << "[Directional::NFunctionMesher::simplify_mesh()]: invalidated "
             "vertices without valid halfedges after remap prune: "
          << invalidatedVertices << std::endl;
  }

  void retwin_halfedges() {
    std::set<FunctionDCEL::TwinFinder> Twinning;
    for (int i = 0; i < genDcel.halfedges.size(); i++) {
      log_progress("halfedge twinning", i,
                   static_cast<int>(genDcel.halfedges.size()));
      if ((genDcel.halfedges[i].twin >= 0) || (!genDcel.halfedges[i].valid))
        continue;

      std::set<FunctionDCEL::TwinFinder>::iterator Twinit =
          Twinning.find(FunctionDCEL::TwinFinder(
              0, genDcel.halfedges[genDcel.halfedges[i].next].vertex,
              genDcel.halfedges[i].vertex));
      if (Twinit != Twinning.end()) {
        if ((genDcel.halfedges[Twinit->index].twin != -1) && (mData.verbose))
          std::cout << "warning: halfedge " << Twinit->index
                    << " is already twinned to halfedge "
                    << genDcel.halfedges[Twinit->index].twin << std::endl;
        if ((genDcel.halfedges[i].twin != -1) && (mData.verbose))
          std::cout << "warning: halfedge " << i
                    << " is already twinned to halfedge "
                    << genDcel.halfedges[Twinit->index].twin << std::endl;
        genDcel.halfedges[Twinit->index].twin = i;
        genDcel.halfedges[i].twin = Twinit->index;

        genDcel.edges[genDcel.halfedges[Twinit->index].edge].valid = false;
        genDcel.halfedges[Twinit->index].edge = genDcel.halfedges[i].edge;

        if (genDcel.halfedges[i].data.isFunction) {
          genDcel.halfedges[Twinit->index].data.isFunction = true;
        } else if (genDcel.halfedges[Twinit->index].data.isFunction) {
          genDcel.halfedges[i].data.isFunction = true;
        }
        Twinning.erase(*Twinit);
      } else {
        Twinning.insert(FunctionDCEL::TwinFinder(
            i, genDcel.halfedges[i].vertex,
            genDcel.halfedges[genDcel.halfedges[i].next].vertex));
      }
    }
  }

  bool classify_triangle_regions(SimplifyScratch &scratch) {
    const int vertexCount = static_cast<int>(genDcel.vertices.size());

    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    const auto validVertex = [&](const int vertex) {
      return vertex >= 0 && vertex < vertexCount &&
             genDcel.vertices[vertex].valid;
    };

    const auto validHalfedge = [&](const int halfedge) {
      return halfedge >= 0 && halfedge < halfedgeCount &&
             genDcel.halfedges[halfedge].valid;
    };

    const auto fail = [&](const char *message, const int index = -1) {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "classify_triangle_regions]: "
                  << message;

        if (index >= 0)
          std::cerr << " " << index;

        std::cerr << '\n';
      }

      return false;
    };

    /*
     * Invalid vertices are never considered pure triangles,
     * boundaries, or ears.
     */
    scratch.isPureTriangle.assign(static_cast<std::size_t>(vertexCount), false);

    scratch.isBoundary.assign(static_cast<std::size_t>(vertexCount), false);

    scratch.isEar.assign(static_cast<std::size_t>(vertexCount), false);

    /*
     * Valid vertices start as pure-triangle candidates.
     */
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      log_progress("triangle component init", vertex, vertexCount);

      if (genDcel.vertices[vertex].valid)
        scratch.isPureTriangle[vertex] = true;
    }

    /*
     * Classify vertices touched by valid halfedges.
     */
    for (int halfedge = 0; halfedge < halfedgeCount; ++halfedge) {
      log_progress("triangle component classify", halfedge, halfedgeCount);

      const auto &he = genDcel.halfedges[halfedge];

      if (!he.valid)
        continue;

      const int origin = he.vertex;

      if (!validVertex(origin)) {
        return fail("valid halfedge references invalid origin vertex",
                    halfedge);
      }

      const int next = he.next;

      if (!validHalfedge(next)) {
        return fail("valid halfedge has invalid next link", halfedge);
      }

      const int target = genDcel.halfedges[next].vertex;

      if (!validVertex(target)) {
        return fail("valid halfedge references invalid target vertex",
                    halfedge);
      }

      /*
       * A function edge means both endpoints participate
       * in the retained non-triangular structure.
       */
      if (he.data.isFunction) {
        scratch.isPureTriangle[origin] = false;
        scratch.isPureTriangle[target] = false;
      }

      /*
       * Only valid halfedges may classify a boundary.
       */
      if (he.twin == -1) {
        scratch.isBoundary[origin] = true;
        scratch.isPureTriangle[origin] = false;
      } else if (he.twin < -1) {
        return fail("halfedge has invalid negative twin sentinel", halfedge);
      } else if (!validHalfedge(he.twin)) {
        return fail("halfedge has invalid twin", halfedge);
      }
    }

    /*
     * Detect ears.
     *
     * A boundary ear has two consecutive boundary halfedges
     * around the same origin vertex:
     *
     *     incident halfedge is boundary
     *     incident.prev is boundary
     */
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      log_progress("triangle ear classify", vertex, vertexCount);

      if (!genDcel.vertices[vertex].valid)
        continue;

      const int incident = genDcel.vertices[vertex].halfedge;

      if (!validHalfedge(incident)) {
        return fail("valid vertex references invalid incident halfedge",
                    vertex);
      }

      if (genDcel.halfedges[incident].vertex != vertex) {
        return fail("vertex incident halfedge has different origin", vertex);
      }

      const int prev = genDcel.halfedges[incident].prev;

      if (!validHalfedge(prev)) {
        return fail("incident halfedge has invalid prev link", incident);
      }

      const int incidentTwin = genDcel.halfedges[incident].twin;

      const int prevTwin = genDcel.halfedges[prev].twin;

      if (incidentTwin < -1) {
        return fail("incident halfedge has invalid twin sentinel", incident);
      }

      if (prevTwin < -1) {
        return fail("previous halfedge has invalid twin sentinel", prev);
      }

      if (incidentTwin >= 0 && !validHalfedge(incidentTwin)) {
        return fail("incident halfedge has invalid twin", incident);
      }

      if (prevTwin >= 0 && !validHalfedge(prevTwin)) {
        return fail("previous halfedge has invalid twin", prev);
      }

      const bool isEar = incidentTwin == -1 && prevTwin == -1;

      scratch.isEar[vertex] = isEar;

      if (isEar) {
        scratch.isBoundary[vertex] = true;
        scratch.isPureTriangle[vertex] = false;
      }
    }

    return true;
  }

  bool realign_hex_halfedges(const SimplifyScratch &scratch) {
    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    const int vertexCount = static_cast<int>(genDcel.vertices.size());

    const auto validHalfedge = [&](const int he) {
      return he >= 0 && he < halfedgeCount && genDcel.halfedges[he].valid;
    };

    const auto fail = [&](const int vertex, const char *message,
                          const int he = -1) {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "realign_hex_halfedges]: vertex "
                  << vertex << ": " << message;

        if (he >= 0)
          std::cerr << " (halfedge " << he << ")";

        std::cerr << '\n';
      }

      return false;
    };

    if (scratch.isPureTriangle.size() != genDcel.vertices.size() ||
        scratch.isBoundary.size() != genDcel.vertices.size()) {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "realign_hex_halfedges]: "
                     "classification arrays do not match "
                     "vertex count\n";
      }

      return false;
    }

    for (int i = 0; i < vertexCount; ++i) {
      log_progress("hex halfedge realignment", i, vertexCount);

      if (scratch.isPureTriangle[i] || !genDcel.vertices[i].valid) {
        continue;
      }

      int heBegin = genDcel.vertices[i].halfedge;

      if (!validHalfedge(heBegin)) {
        return fail(i, "invalid incident halfedge", heBegin);
      }

      /*
       * For a boundary vertex, rotate backward around
       * the fan until the preceding edge is a boundary
       * halfedge.
       */
      if (scratch.isBoundary[i]) {
        std::vector<unsigned char> visited(
            static_cast<std::size_t>(halfedgeCount), 0);

        bool foundBoundaryStart = false;

        for (int steps = 0; steps < halfedgeCount; ++steps) {
          if (!validHalfedge(heBegin)) {
            return fail(i,
                        "invalid halfedge during backward "
                        "fan walk",
                        heBegin);
          }

          if (visited[heBegin]) {
            return fail(i, "backward fan walk entered a cycle", heBegin);
          }

          visited[heBegin] = 1;

          const int prev = genDcel.halfedges[heBegin].prev;

          if (!validHalfedge(prev)) {
            return fail(i,
                        "invalid prev link during backward "
                        "fan walk",
                        prev);
          }

          const int twin = genDcel.halfedges[prev].twin;

          if (twin == -1) {
            foundBoundaryStart = true;
            break;
          }

          if (!validHalfedge(twin)) {
            return fail(i,
                        "invalid twin during backward "
                        "fan walk",
                        twin);
          }

          heBegin = twin;
        }

        if (!foundBoundaryStart) {
          return fail(i, "could not locate a boundary start "
                         "within the traversal bound");
        }
      }

      /*
       * Collect retained halfedges without modifying
       * topology. The mutation phase runs only after
       * this traversal fully succeeds.
       */
      std::vector<int> hexHEOrder;

      std::vector<unsigned char> visited(
          static_cast<std::size_t>(halfedgeCount), 0);

      int he = heBegin;
      bool fanClosed = false;
      bool reachedBoundaryEnd = false;

      for (int steps = 0; steps < halfedgeCount; ++steps) {
        if (!validHalfedge(he)) {
          return fail(i,
                      "invalid halfedge during forward "
                      "fan walk",
                      he);
        }

        if (visited[he]) {
          if (he == heBegin) {
            fanClosed = true;
            break;
          }

          return fail(i,
                      "forward fan walk entered a "
                      "non-start cycle",
                      he);
        }

        visited[he] = 1;

        if (genDcel.halfedges[he].vertex != i) {
          return fail(i,
                      "fan walk reached a halfedge with "
                      "a different origin vertex",
                      he);
        }

        if (genDcel.halfedges[he].data.isFunction ||
            genDcel.halfedges[he].twin == -1) {
          hexHEOrder.push_back(he);
        }

        const int twin = genDcel.halfedges[he].twin;

        if (twin == -1) {
          reachedBoundaryEnd = true;
          break;
        }

        if (!validHalfedge(twin)) {
          return fail(i,
                      "invalid twin during forward "
                      "fan walk",
                      twin);
        }

        const int next = genDcel.halfedges[twin].next;

        if (!validHalfedge(next)) {
          return fail(i,
                      "invalid next link during forward "
                      "fan walk",
                      next);
        }

        he = next;

        if (he == heBegin) {
          fanClosed = true;
          break;
        }
      }

      if (scratch.isBoundary[i]) {
        if (!reachedBoundaryEnd) {
          return fail(i, "boundary fan did not terminate at "
                         "a boundary halfedge");
        }
      } else if (!fanClosed) {
        return fail(i, "interior fan did not close within the "
                       "traversal bound");
      }

      if (hexHEOrder.empty()) {
        return fail(i, "fan contains no retained function or "
                       "boundary halfedges");
      }

      /*
       * A boundary fan forms an open chain. Its last
       * retained halfedge has no twin and must not be
       * used as the left side of a rewiring pair.
       *
       * An interior fan is cyclic, so every retained
       * halfedge participates.
       */
      const int linkCount = scratch.isBoundary[i]
                                ? static_cast<int>(hexHEOrder.size()) - 1
                                : static_cast<int>(hexHEOrder.size());

      if (linkCount < 0) {
        return fail(i, "invalid retained halfedge count");
      }

      /*
       * Validate all references needed by the commit
       * phase before changing any topology.
       */
      for (int j = 0; j < linkCount; ++j) {
        const int current = hexHEOrder[j];

        const int successor = hexHEOrder[(j + 1) % hexHEOrder.size()];

        const int twin = genDcel.halfedges[current].twin;

        if (!validHalfedge(current) || !validHalfedge(successor)) {
          return fail(i,
                      "invalid retained halfedge before "
                      "rewiring",
                      current);
        }

        if (!validHalfedge(twin)) {
          return fail(i,
                      "retained nonterminal halfedge has "
                      "no valid twin",
                      current);
        }
      }

      int boundaryPrev = -1;

      if (scratch.isBoundary[i]) {
        boundaryPrev = genDcel.halfedges[heBegin].prev;

        if (!validHalfedge(boundaryPrev)) {
          return fail(i,
                      "invalid boundary predecessor "
                      "before rewiring",
                      boundaryPrev);
        }
      }

      /*
       * Commit rewiring only after all traversals and
       * references have been validated.
       */
      for (int j = 0; j < linkCount; ++j) {
        const int current = hexHEOrder[j];

        const int successor = hexHEOrder[(j + 1) % hexHEOrder.size()];

        const int twin = genDcel.halfedges[current].twin;

        genDcel.halfedges[successor].prev = twin;

        genDcel.halfedges[twin].next = successor;

        const int origin = genDcel.halfedges[current].vertex;

        if (origin < 0 || origin >= vertexCount) {
          return fail(i,
                      "retained halfedge has invalid "
                      "origin vertex",
                      current);
        }

        genDcel.vertices[origin].halfedge = current;
      }

      if (scratch.isBoundary[i]) {
        const int first = hexHEOrder.front();

        genDcel.halfedges[first].prev = boundaryPrev;

        genDcel.halfedges[boundaryPrev].next = first;

        const int origin = genDcel.halfedges[first].vertex;

        if (origin < 0 || origin >= vertexCount) {
          return fail(i,
                      "first retained boundary halfedge "
                      "has invalid origin",
                      first);
        }

        genDcel.vertices[origin].halfedge = first;
      }
    }

    return true;
  }

  void invalidate_triangle_regions(const SimplifyScratch &scratch) {
    for (int i = 0; i < genDcel.vertices.size(); i++)
      if (scratch.isPureTriangle[i])
        genDcel.vertices[i].valid = false;

    for (int i = 0; i < genDcel.halfedges.size(); i++)
      if ((!genDcel.halfedges[i].data.isFunction) &&
          (genDcel.halfedges[i].twin != -1))
        genDcel.halfedges[i].valid =
            genDcel.edges[genDcel.halfedges[i].edge].valid = false;
  }

  bool realign_faces() {
    Eigen::VectorXi visitedHE = Eigen::VectorXi::Zero(genDcel.halfedges.size());
    Eigen::VectorXi usedFace = Eigen::VectorXi::Zero(genDcel.faces.size());
    for (int i = 0; i < genDcel.halfedges.size(); i++) {
      log_progress("face realignment", i,
                   static_cast<int>(genDcel.halfedges.size()));
      if ((!genDcel.halfedges[i].valid) || (visitedHE[i] != 0))
        continue;

      const int currFace = genDcel.halfedges[i].face;
      genDcel.faces[currFace].halfedge = i;
      usedFace[currFace] = 1;
      const int hebegin = i;
      int heiterate = hebegin;
      int infinityCounter = 0;
      do {
        infinityCounter++;
        if (infinityCounter > genDcel.halfedges.size()) {
          std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: "
                    << "Infinity loop in realigning faces on halfedge " << i
                    << std::endl;
          return false;
        }
        genDcel.halfedges[heiterate].face = currFace;
        visitedHE[heiterate] = 1;
        heiterate = genDcel.halfedges[heiterate].next;
      } while (heiterate != hebegin);
    }

    for (int i = 0; i < genDcel.faces.size(); i++)
      if (!usedFace[i])
        genDcel.faces[i].valid = false;

    return true;
  }

  void prune_low_quality_faces_and_count_valence(SimplifyScratch &scratch) {
    scratch.valences.assign(genDcel.vertices.size(), 0);
    for (int i = 0; i < genDcel.halfedges.size(); i++) {
      log_progress("valence counting", i,
                   static_cast<int>(genDcel.halfedges.size()));
      if (genDcel.halfedges[i].valid) {
        scratch.valences[genDcel.halfedges[i].vertex]++;
        if (genDcel.halfedges[i].twin < 0)
          scratch
              .valences[genDcel.halfedges[genDcel.halfedges[i].next].vertex]++;
      }
    }

    int countThree = 0;
    for (int i = 0; i < genDcel.faces.size(); i++) {
      if (!genDcel.faces[i].valid)
        continue;
      countThree = 0;
      const int hebegin = genDcel.faces[i].halfedge;
      int heiterate = hebegin;
      do {
        if (scratch.valences[genDcel.halfedges[heiterate].vertex] > 2)
          countThree++;
        heiterate = genDcel.halfedges[heiterate].next;
      } while (heiterate != hebegin);
      if (countThree < 3) {
        do {
          genDcel.halfedges[heiterate].valid = false;

          if (genDcel.halfedges[heiterate].twin != -1) {
            if (!genDcel.halfedges[genDcel.halfedges[heiterate].twin].valid)
              genDcel.edges[genDcel.halfedges[heiterate].edge].valid = false;
            else
              genDcel.edges[genDcel.halfedges[heiterate].edge].halfedge =
                  genDcel.halfedges[heiterate].twin;
          } else {
            genDcel.edges[genDcel.halfedges[heiterate].edge].valid = false;
          }

          if (genDcel.halfedges[heiterate].twin != -1)
            genDcel.halfedges[genDcel.halfedges[heiterate].twin].twin = -1;
          if ((genDcel.halfedges[heiterate].twin == -1) &&
              (genDcel.halfedges[genDcel.halfedges[heiterate].prev].twin == -1))
            genDcel.vertices[genDcel.halfedges[heiterate].vertex].valid = false;

          heiterate = genDcel.halfedges[heiterate].next;
        } while (heiterate != hebegin);
        genDcel.faces[i].valid = false;
      }
    }
  }

  void refresh_vertex_halfedge_pointers() {
    for (int i = 0; i < genDcel.halfedges.size(); i++)
      if (genDcel.halfedges[i].valid)
        genDcel.vertices[genDcel.halfedges[i].vertex].halfedge = i;
  }

  int unify_low_valence_vertices(const SimplifyScratch &scratch) {
    for (int i = 0; i < scratch.valences.size(); i++)
      if ((genDcel.vertices[i].valid) && (scratch.valences[i] < 2))
        genDcel.vertices[i].valid = false;

    int unifyCount = 0;
    for (int i = 0; i < genDcel.vertices.size(); i++) {
      log_progress("low-valence edge unification", i,
                   static_cast<int>(genDcel.vertices.size()));
      if ((genDcel.vertices[i].valid) && (scratch.valences[i] <= 2) &&
          (!scratch.isEar[i])) {
        genDcel.unify_edges(genDcel.vertices[i].halfedge);
        unifyCount++;
      }
    }

    return unifyCount;
  }

  bool finalize_clean_mesh() {
    genDcel.clean_mesh();
    return genDcel.check_consistency(mData.verbose, true, true, true);
  }

  bool simplify_mesh() {
    // unifying vertices which are similar

    using namespace std;
    using namespace Eigen;
    using Clock = std::chrono::high_resolution_clock;

    SimplifyScratch scratch;

    const auto simplifyStart = Clock::now();
    auto phaseStart = simplifyStart;
    const auto logPhase = [&](const char *label) {
      if (!mData.verbose)
        return;
      const auto now = Clock::now();
      const auto phaseSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(now -
                                                                phaseStart)
              .count() /
          1e+6;
      const auto totalSeconds =
          std::chrono::duration_cast<std::chrono::microseconds>(now -
                                                                simplifyStart)
              .count() /
          1e+6;
      std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: " << label
                << " completed in " << phaseSeconds << " s (total "
                << totalSeconds << " s)" << std::endl;
      phaseStart = now;
    };
    const auto shouldLogProgress = [&](int index, int total) {
      if (!mData.verbose || total <= 0)
        return false;
      if (index == 0 || index + 1 == total)
        return true;
      const int step = std::max(1, total / 10);
      return ((index + 1) % step) == 0;
    };
    const auto logProgress = [&](const char *label, int index, int total) {
      if (!shouldLogProgress(index, total))
        return;
      std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: " << label
                << ": " << (index + 1) << "/" << total << std::endl;
    };

    if (!run_initial_consistency_check())
      return false;
    logPhase("Initial consistency check");

    scan_original_halfedge_range(scratch);
    logPhase("Original halfedge range scan");

    if (!visit_boundary_seeds(scratch))
      return false;
    logPhase("Boundary visitation sweep");

    if (!collect_boundary_strips(scratch))
      return false;
    logPhase("Boundary strip collection");

    build_boundary_vertex_sets(scratch);
    logPhase("Boundary vertex set build");

    build_vertex_matches(scratch);
    logPhase("Vertex match build");

    // finding connected components, and uniting every component into a random
    // single vertex in it (it comes out the last mentioned)
    /*Graph MatchGraph;
     for (int i=0;i<vertices.size();i++)
     add_vertex(MatchGraph);
     for (int i=0;i<VertexMatches.size();i++)
     add_edge(VertexMatches[i].first, VertexMatches[i].second, MatchGraph);*/

    scan_vertex_match_distance(scratch);
    logPhase("Vertex match distance scan");

    int NumNewVertices = compute_vertex_representatives(scratch);
    logPhase("Connected components");

    if (!genDcel.check_consistency(mData.verbose, false, false, false))
      return false;
    logPhase("Post-components consistency check");

    rebuild_vertex_table(NumNewVertices);
    logPhase("Vertex representative rebuild");

    std::vector<int> preRemapOrigin(genDcel.halfedges.size(), -1);
    std::vector<int> preRemapTarget(genDcel.halfedges.size(), -1);
    remap_halfedge_vertices(preRemapOrigin, preRemapTarget);
    logPhase("Halfedge vertex remap");

    prune_remap_created_degenerates(preRemapOrigin, preRemapTarget);
    logPhase("Remap-created degenerate halfedge pruning");

    if (!genDcel.check_consistency(mData.verbose, true, false, false))
      return false;
    logPhase("Post-remap consistency check");

    retwin_halfedges();
    logPhase("Halfedge twinning");

    // check if there are any non-twinned edge which shouldn't be in a closed
    // mesh
    /*if (verbose){
     for (int i=0;i<Halfedges.size();i++){
     if (Halfedges[i].twin==-1)
     std::cout<<"Halfedge "<<i<<" does not have a twin!"<<std::endl;
     }
     }*/

    if (!genDcel.check_consistency(mData.verbose, true, true, true))
      return false;
    logPhase("Post-twinning consistency check");

    if (!classify_triangle_regions(scratch))
      return false;
    logPhase("Triangle component classification");

    if (!realign_hex_halfedges(scratch))
      return false;
    logPhase("Hex halfedge realignment");

    invalidate_triangle_regions(scratch);
    logPhase("Triangle invalidation");

    if (!realign_faces())
      return false;
    logPhase("Face realignment");
    logPhase("Unused face invalidation");

    prune_low_quality_faces_and_count_valence(scratch);
    logPhase("Valence counting and ear pruning");

    // need to realign all vertices pointing
    refresh_vertex_halfedge_pointers();
    logPhase("Vertex halfedge pointer refresh");

    if (!genDcel.check_consistency(mData.verbose, true, true, true))
      return false;
    logPhase("Post-pruning consistency check");

    int unifyCount = unify_low_valence_vertices(scratch);
    if (mData.verbose)
      std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: "
                   "Low-valence edge unification finished after "
                << unifyCount << " operations" << std::endl;
    logPhase("Low-valence edge unification");

    if (!genDcel.check_consistency(mData.verbose, true, true, true))
      return false;
    logPhase("Post-unification consistency check");

    // remove non-valid components
    if (!finalize_clean_mesh())
      return false;
    logPhase("DCEL clean_mesh");
    logPhase("Final consistency check");

    return true;
  }

  void RemoveDegree2Faces();

  /*void Allocate(int NumofVertices, int NumofFaces, int NumofHEdges)
   {
   Vertices.resize(NumofVertices);
   faces.resize(NumofFaces);
   Halfedges.resize(NumofHEdges);
   }*/

  /*void init(const TriMesh& origMesh,
   const Eigen::MatrixXd& cutV,
   const Eigen::MatrixXi& cutF,
   const Eigen::VectorXd& vertexNFunction,
   const int N,
   const Eigen::SparseMatrix<double>& vertexToCornerMat,
   const Eigen::SparseMatrix<int>& exactVertexToCornerMat,
   const Eigen::VectorXi& integerVars,
   const unsigned long resolution=1e7)*/
  void init(const unsigned long resolution = 1e7) {

    using namespace std;
    using namespace Eigen;

    // computing exact rational corner values by quantizing the free variables d
    // and then manually performing the sparse matrix multiplication
    vector<ENumber> exactVertexNFunction(mData.vertexNFunction.size());
    double tol = 1.0 / (double)resolution;
    for (int i = 0; i < mData.vertexNFunction.size(); i++) {
      // exactVertexNFunction[i]=ENumber((long long)round((long
      // double)(mData.vertexNFunction(i)*resolution)),(long long)resolution);
      exactVertexNFunction[i] = ENumber(mData.vertexNFunction(i), tol);

      /*if (abs(exactVertexNFunction[i].to_double() -
       mData.vertexNFunction(i))>2.0/(double)resolution) { cout <<
       "exactVertexNFunction[i].to_double(): " <<
       exactVertexNFunction[i].to_double() << endl; cout << "vertexNFunction(i):
       " << mData.vertexNFunction(i) << endl; cout << "(long
       double)(vertexNFunction(i)*resolution): " << (long
       double)(mData.vertexNFunction(i) * resolution) << endl;
       }*/
    }

    for (int i = 0; i < mData.integerVars.size(); i++) {
      exactVertexNFunction[mData.integerVars(i)] =
          ENumber((long)round(mData.vertexNFunction(mData.integerVars(i))));
      // cout<<"rounding diff of integer var "<<mData.integerVars(i)<<" is
      // "<<exactVertexNFunction[mData.integerVars(i)].to_double()-mData.vertexNFunction(mData.integerVars(i))<<endl;
    }

    VectorXd cutNFunctionVec = mData.orig2CutMat * mData.vertexNFunction;
    vector<ENumber> exactCutNFunctionVec;
    exactSparseMult(mData.exactOrig2CutMat, exactVertexNFunction,
                    exactCutNFunctionVec);

    // sanity check - comparing exact to double
    double maxError2 = -32767000.0;
    for (int i = 0; i < exactCutNFunctionVec.size(); i++) {
      double fromExact = exactCutNFunctionVec[i].to_double();
      if (abs(fromExact - cutNFunctionVec[i]) > maxError2) {
        maxError2 = abs(fromExact - cutNFunctionVec[i]);
        // cout<<"i, fromExact, cutNFunctionVec[i]:
        // "<<i<<","<<fromExact<<","<<cutNFunctionVec[i]<<endl;
      }
    }

    if (mData.verbose)
      cout << "double from exact in halfedges maxError2: " << maxError2 << endl;

    exactNFunction.resize(origMesh.F.size());
    NFunction.resize(origMesh.F.size(), 3 * mData.N);

    for (int i = 0; i < origMesh.F.rows(); i++) {
      exactNFunction[i].resize(3 * mData.N);
      for (int j = 0; j < 3; j++) {
        // Halfedges[FH(i,j)].exactNFunction.resize(N);
        NFunction.block(i, mData.N * j, 1, mData.N) =
            cutNFunctionVec.segment(mData.N * mData.cutF(i, j), mData.N)
                .transpose();
        for (int k = 0; k < mData.N; k++)
          exactNFunction[i][j * mData.N + k] =
              exactCutNFunctionVec[mData.N * mData.cutF(i, j) + k];
      }
    }
  }

  // corner angles is per vertex in each F
  void to_polygonal(Eigen::MatrixXd &generatedV, Eigen::VectorXi &generatedD,
                    Eigen::MatrixXi &generatedF) {
    generatedV.resize(genDcel.vertices.size(), 3);

    generatedD.resize(genDcel.faces.size());

    for (int i = 0; i < genDcel.vertices.size(); i++)
      generatedV.row(i) = genDcel.vertices[i].data.coords;

    for (int i = 0; i < genDcel.faces.size(); i++) {
      int hebegin = genDcel.faces[i].halfedge;
      // reseting to first vertex
      int vCount = 0;
      int heiterate = hebegin;
      do {
        vCount++;
        heiterate = genDcel.halfedges[heiterate].next;
      } while (heiterate != hebegin);
      generatedD(i) = vCount;
    }

    generatedF.resize(genDcel.faces.size(), generatedD.maxCoeff());
    for (int i = 0; i < genDcel.faces.size(); i++) {
      int hebegin = genDcel.faces[i].halfedge;
      int vCount = 0;
      int heiterate = hebegin;
      do {
        generatedF(i, vCount++) = genDcel.halfedges[heiterate].vertex;
        heiterate = genDcel.halfedges[heiterate].next;
      } while (heiterate != hebegin);
    }
  }

  NFunctionMesher(const TriMesh &_origMesh, const MesherData &_mData)
      : origMesh(_origMesh), mData(_mData) {}
  ~NFunctionMesher() {}

private:
  void
  arrange_on_triangle(const std::vector<EVector2> &triangle,
                      const std::vector<std::pair<EVector2, EVector2>> &lines,
                      const Eigen::VectorXi &lineData, std::vector<EVector2> &V,
                      FunctionDCEL &dcel, Eigen::VectorXi &dataH);

  void segment_arrangement(
      const std::vector<std::pair<EVector2, EVector2>> &segments,
      const std::vector<int> &data, std::vector<EVector2> &V,
      FunctionDCEL &dcel, Eigen::VectorXi &dataH);
};

} // namespace directional

#endif // DIRECTIONAL_N_FUNCTION_MESHER
