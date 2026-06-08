//
// Created by Amir Vaxman on 20.04.24.
//

#ifndef DIRECTIONAL_N_FUNCTION_MESHER
#define DIRECTIONAL_N_FUNCTION_MESHER

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <directional/dcel.h>
#include <directional/exact_geometric_definitions.h>
#include <directional/setup_mesher.h>
#include <limits>
#include <math.h>
#include <queue>
#include <set>
#include <stdexcept>
#include <unordered_map>
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

  static constexpr std::size_t kVertexMatchWarnPairs = 100'000;
  static constexpr std::size_t kVertexMatchGreedyPairLimit = 250'000;
  static constexpr std::size_t kVertexMatchMaxDpCells = 20'000'000;
  static constexpr std::size_t kVertexMatchInitialBand = 64;
  static constexpr std::size_t kVertexMatchMaxBand = 4096;

  static bool exact_point_equal(const EVector3 &a, const EVector3 &b) {
    return (a - b).max_abs() == ENumber(0);
  }

  static double vertex_match_cost(const EVector3 &a, const EVector3 &b) {
    return (a - b).max_abs().to_double();
  }

  class VertexCoordinateView {
  public:
    VertexCoordinateView(const FunctionDCEL &dcel,
                         const std::vector<int> &vertexIndices)
        : dcel_(&dcel), vertexIndices_(&vertexIndices) {}

    std::size_t size() const noexcept { return vertexIndices_->size(); }

    bool empty() const noexcept { return vertexIndices_->empty(); }

    const EVector3 &operator[](const std::size_t index) const {
      const int vertex = (*vertexIndices_)[index];

      return dcel_->vertices[vertex].data.eCoords;
    }

    int vertex_index(const std::size_t index) const {
      return (*vertexIndices_)[index];
    }

  private:
    const FunctionDCEL *dcel_;
    const std::vector<int> *vertexIndices_;
  };

  template <typename PointSet1, typename PointSet2>
  std::vector<std::pair<int, int>>
  FindVertexMatchGreedyExact(const bool verbose, const PointSet1 &Set1,
                             const PointSet2 &Set2) {
    using Clock = std::chrono::steady_clock;
    const auto startTime = Clock::now();
    const std::size_t pointCount = Set1.size();
    const std::size_t candidatePairCount = pointCount * pointCount;

    if (candidatePairCount >= kVertexMatchWarnPairs) {
      std::cerr << "[Directional::NFunctionMesher::"
                   "FindVertexMatchGreedyExact()]: generating "
                << candidatePairCount << " exact candidate pairs from "
                << pointCount << " x " << pointCount << " boundary vertices"
                << std::endl;
    }

    std::set<PointPair> PairSet;
    for (std::size_t i = 0; i < pointCount; ++i) {
      for (std::size_t j = 0; j < pointCount; ++j) {
        PairSet.insert(PointPair(static_cast<int>(i), static_cast<int>(j),
                                 Set1[i] - Set2[j]));
      }

      if (verbose && pointCount >= 1000) {
        const std::size_t step = std::max<std::size_t>(1, pointCount / 10);
        if (i == 0 || i + 1 == pointCount || (i + 1) % step == 0) {
          std::cout << "[Directional::NFunctionMesher::"
                       "FindVertexMatchGreedyExact()]: candidate rows "
                    << (i + 1) << "/" << pointCount << std::endl;
        }
      }
    }

    std::vector<bool> Set1Connect(pointCount, false);
    std::vector<bool> Set2Connect(pointCount, false);
    std::vector<std::pair<int, int>> Result;
    Result.reserve(pointCount);

    Result.emplace_back(0, 0);
    Set1Connect[0] = true;
    Set2Connect[0] = true;

    if (pointCount > 1) {
      const int last = static_cast<int>(pointCount - 1);
      Result.emplace_back(last, last);
      Set1Connect[last] = true;
      Set2Connect[last] = true;
    }

    std::size_t processed = 0;
    const std::size_t progressStep =
        std::max<std::size_t>(1, candidatePairCount / 10);

    for (const PointPair &currentPair : PairSet) {
      ++processed;
      if (verbose && candidatePairCount >= kVertexMatchWarnPairs &&
          (processed == 1 || processed == candidatePairCount ||
           processed % progressStep == 0)) {
        std::cout << "[Directional::NFunctionMesher::"
                     "FindVertexMatchGreedyExact()]: candidates "
                  << processed << "/" << candidatePairCount << std::endl;
      }

      if (Set1Connect[currentPair.Index1] && Set2Connect[currentPair.Index2])
        continue;

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

      if (foundConflict)
        continue;

      Result.emplace_back(currentPair.Index1, currentPair.Index2);
      Set1Connect[currentPair.Index1] = true;
      Set2Connect[currentPair.Index2] = true;
    }

    if (verbose) {
      const double seconds =
          std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                                startTime)
              .count() /
          1e6;
      std::cout << "[Directional::NFunctionMesher::"
                   "FindVertexMatchGreedyExact()]: completed in "
                << seconds << " s" << std::endl;
    }

    return Result;
  }

  struct BandedMatchResult {
    bool success = false;
    bool touchedBandBoundary = false;
    std::size_t visitedCells = 0;
    std::vector<std::pair<int, int>> matches;
  };

  template <typename PointSet1, typename PointSet2>
  BandedMatchResult
  FindVertexMatchBanded(const bool verbose, const PointSet1 &Set1,
                        const PointSet2 &Set2, const std::size_t band) {
    using Clock = std::chrono::steady_clock;
    const auto startTime = Clock::now();
    const std::size_t n = Set1.size();
    const double infinity = std::numeric_limits<double>::infinity();

    BandedMatchResult output;
    if (n == 0) {
      output.success = true;
      return output;
    }

    struct PredRow {
      std::size_t begin = 0;
      std::vector<std::uint8_t> direction;
    };

    // 1 = diagonal, 2 = up, 3 = left, 4 = start.
    std::vector<PredRow> predecessors(n);
    std::vector<double> previousCosts;
    std::size_t previousBegin = 0;

    const std::size_t rowWidth = std::min<std::size_t>(n, 2 * band + 1);
    if (rowWidth != 0 && n > kVertexMatchMaxDpCells / rowWidth) {
      return output;
    }
    const std::size_t estimatedCells = n * rowWidth;
    if (estimatedCells > kVertexMatchMaxDpCells) {
      return output;
    }

    for (std::size_t i = 0; i < n; ++i) {
      const std::size_t begin = i > band ? i - band : 0;
      const std::size_t end = std::min<std::size_t>(n - 1, i + band);
      const std::size_t width = end - begin + 1;

      predecessors[i].begin = begin;
      predecessors[i].direction.assign(width, 0);
      std::vector<double> currentCosts(width, infinity);

      for (std::size_t j = begin; j <= end; ++j) {
        ++output.visitedCells;
        const std::size_t local = j - begin;
        const double localCost = vertex_match_cost(Set1[i], Set2[j]);

        if (i == 0 && j == 0) {
          currentCosts[local] = localCost;
          predecessors[i].direction[local] = 4;
          continue;
        }

        double best = infinity;
        std::uint8_t direction = 0;

        // Prefer diagonal on ties, then up, then left. This minimizes
        // unnecessary one-to-many matches when costs are equal.
        if (i > 0 && j > 0 && j - 1 >= previousBegin &&
            j - 1 < previousBegin + previousCosts.size()) {
          best = previousCosts[j - 1 - previousBegin];
          direction = 1;
        }

        if (i > 0 && j >= previousBegin &&
            j < previousBegin + previousCosts.size()) {
          const double candidate = previousCosts[j - previousBegin];
          if (candidate < best) {
            best = candidate;
            direction = 2;
          }
        }

        if (j > begin && currentCosts[local - 1] < best) {
          best = currentCosts[local - 1];
          direction = 3;
        }

        if (direction != 0 && std::isfinite(best)) {
          currentCosts[local] = best + localCost;
          predecessors[i].direction[local] = direction;
        }
      }

      previousCosts.swap(currentCosts);
      previousBegin = begin;

      if (verbose && n >= 1000) {
        const std::size_t step = std::max<std::size_t>(1, n / 10);
        if (i == 0 || i + 1 == n || (i + 1) % step == 0) {
          std::cout << "[Directional::NFunctionMesher::"
                       "FindVertexMatchBanded()]: rows "
                    << (i + 1) << "/" << n << ", band " << band << std::endl;
        }
      }
    }

    if (n - 1 < previousBegin ||
        n - 1 >= previousBegin + previousCosts.size() ||
        !std::isfinite(previousCosts[n - 1 - previousBegin])) {
      return output;
    }

    std::size_t i = n - 1;
    std::size_t j = n - 1;
    output.matches.reserve(2 * n);

    while (true) {
      output.matches.emplace_back(static_cast<int>(i), static_cast<int>(j));
      if (band > 0 && (i > j ? i - j : j - i) == band)
        output.touchedBandBoundary = true;

      const PredRow &row = predecessors[i];
      if (j < row.begin || j >= row.begin + row.direction.size()) {
        output.matches.clear();
        return output;
      }

      const std::uint8_t direction = row.direction[j - row.begin];
      if (direction == 4)
        break;
      if (direction == 1) {
        --i;
        --j;
      } else if (direction == 2) {
        --i;
      } else if (direction == 3) {
        --j;
      } else {
        output.matches.clear();
        return output;
      }
    }

    std::reverse(output.matches.begin(), output.matches.end());
    output.success = true;

    if (verbose) {
      const double seconds =
          std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                                startTime)
              .count() /
          1e6;
      std::cout << "[Directional::NFunctionMesher::"
                   "FindVertexMatchBanded()]: visited "
                << output.visitedCells << " cells with band " << band << " in "
                << seconds << " s" << std::endl;
    }

    return output;
  }

  template <typename PointSet1, typename PointSet2>
  std::vector<std::pair<int, int>> FindVertexMatch(const bool verbose,
                                                   const PointSet1 &Set1,
                                                   const PointSet2 &Set2) {
    if (Set1.size() != Set2.size()) {
      throw std::invalid_argument(
          "Directional::NFunctionMesher::FindVertexMatch(): "
          "the two point sets must have equal sizes");
    }

    if (Set1.empty())
      return {};

    const std::size_t pointCount = Set1.size();

    // Most paired boundary strips already have the same ordered sampling.
    // Detect that common case in linear time and avoid any candidate search.
    bool identityMatch = true;
    for (std::size_t i = 0; i < pointCount; ++i) {
      if (!exact_point_equal(Set1[i], Set2[i])) {
        identityMatch = false;
        break;
      }
    }

    if (identityMatch) {
      std::vector<std::pair<int, int>> result;
      result.reserve(pointCount);
      for (std::size_t i = 0; i < pointCount; ++i)
        result.emplace_back(static_cast<int>(i), static_cast<int>(i));

      return result;
    }

    if (pointCount > 0 &&
        pointCount > std::numeric_limits<std::size_t>::max() / pointCount) {
      throw std::overflow_error(
          "Directional::NFunctionMesher::FindVertexMatch(): "
          "candidate pair count overflows size_t");
    }

    const std::size_t candidatePairCount = pointCount * pointCount;
    if (candidatePairCount <= kVertexMatchGreedyPairLimit)
      return FindVertexMatchGreedyExact(verbose, Set1, Set2);

    std::cerr << "[Directional::NFunctionMesher::FindVertexMatch()]: "
              << "switching from exact all-pairs matching to bounded "
                 "order-preserving matching for "
              << pointCount << " vertices (" << candidatePairCount
              << " all-pairs candidates avoided)" << std::endl;

    const std::size_t maxBand =
        std::min<std::size_t>(pointCount - 1, kVertexMatchMaxBand);
    std::size_t band = std::min<std::size_t>(
        maxBand,
        std::max<std::size_t>(kVertexMatchInitialBand, pointCount / 100));

    while (true) {
      const std::size_t rowWidth =
          std::min<std::size_t>(pointCount, 2 * band + 1);
      if (rowWidth != 0 && pointCount > kVertexMatchMaxDpCells / rowWidth) {
        throw std::runtime_error(
            "Directional::NFunctionMesher::FindVertexMatch(): "
            "bounded matching would overflow or exceed the configured DP "
            "work budget");
      }
      const std::size_t estimatedCells = pointCount * rowWidth;
      if (estimatedCells > kVertexMatchMaxDpCells) {
        throw std::runtime_error(
            "Directional::NFunctionMesher::FindVertexMatch(): "
            "bounded matching would exceed the configured DP work budget");
      }

      BandedMatchResult result =
          FindVertexMatchBanded(verbose, Set1, Set2, band);
      if (!result.success) {
        throw std::runtime_error(
            "Directional::NFunctionMesher::FindVertexMatch(): "
            "bounded order-preserving matching failed");
      }

      if (!result.touchedBandBoundary || band == maxBand)
        return result.matches;

      const std::size_t nextBand = std::min<std::size_t>(maxBand, 2 * band);
      if (nextBand == band)
        return result.matches;

      std::cerr << "[Directional::NFunctionMesher::FindVertexMatch()]: "
                << "optimal path touched band boundary; retrying with band "
                << nextBand << std::endl;
      band = nextBand;
    }
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
    return genDcel.check_consistency(
        mData.verbose,
        true,   // check halfedge repetition
        false,  // twins may not yet be finalized
        false); // pure-boundary requirement deferred
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
    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    const auto validOrig = [&](const int orig) -> bool {
      return orig >= 0 && orig <= scratch.maxOrigHE;
    };

    const auto fail = [&](const char *message, const int seed,
                          const int current = -1) -> bool {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "visit_boundary_seeds()]: "
                  << message << " (seed " << seed;

        if (current >= 0) {
          std::cerr << ", current halfedge " << current;
        }

        std::cerr << ")\n";
      }

      return false;
    };

    if (scratch.maxOrigHE < 0) {
      /*
       * No original boundary IDs is a valid no-op.
       */
      scratch.visitedOrig.clear();
      return true;
    }

    scratch.visitedOrig.assign(static_cast<std::size_t>(scratch.maxOrigHE + 1),
                               false);

    for (int seed = 0; seed < halfedgeCount; ++seed) {

      log_progress("boundary seed scan", seed, halfedgeCount);

      if (!genDcel.valid_halfedge(seed)) {
        continue;
      }

      const int seedOrig = genDcel.halfedges[seed].data.origHalfedge;

      if (seedOrig < 0) {
        continue;
      }

      if (!validOrig(seedOrig)) {
        return fail("seed has an out-of-range original "
                    "halfedge ID",
                    seed);
      }

      if (scratch.visitedOrig[seedOrig]) {
        continue;
      }

      std::vector<unsigned char> visitedHalfedges(
          static_cast<std::size_t>(halfedgeCount),
          static_cast<unsigned char>(0));

      int current = seed;
      bool closedAtSeed = false;

      for (int step = 0; step < halfedgeCount; ++step) {

        if (!genDcel.valid_halfedge(current)) {
          return fail("boundary traversal reached an invalid "
                      "halfedge",
                      seed, current);
        }

        if (visitedHalfedges[current]) {
          if (current == seed) {
            closedAtSeed = true;
            break;
          }

          return fail("boundary traversal entered a "
                      "non-seed cycle",
                      seed, current);
        }

        visitedHalfedges[current] = 1;

        const int orig = genDcel.halfedges[current].data.origHalfedge;

        if (orig >= 0) {
          if (orig > scratch.maxOrigHE)
            return false;

          scratch.visitedOrig[orig] = true;
        }

        int nextBoundary = current;

        if (!genDcel.walk_boundary(nextBoundary, mData.verbose,
                                   "visit_boundary_seeds")) {
          return fail("DCEL boundary walk failed", seed, current);
        }

        if (!genDcel.valid_halfedge(nextBoundary)) {
          return fail("boundary walk returned an invalid "
                      "halfedge",
                      seed, nextBoundary);
        }

        current = nextBoundary;

        if (current == seed) {
          closedAtSeed = true;
          break;
        }
      }

      if (!closedAtSeed) {
        return fail("boundary traversal exceeded the "
                    "halfedge bound without returning to "
                    "its seed",
                    seed, current);
      }
    }

    return true;
  }

  bool next_boundary_halfedge(const int current, int &next_boundary,
                              const char *context) const {
    const int halfedge_count = static_cast<int>(genDcel.halfedges.size());

    if (!genDcel.valid_halfedge(current)) {
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
      if (!genDcel.valid_halfedge(cursor)) {
        if (mData.verbose) {
          std::cerr << "[Directional::NFunctionMesher::" << context
                    << "]: invalid fan halfedge " << cursor << '\n';
        }
        return false;
      }

      const int next = genDcel.halfedges[cursor].next;
      if (!genDcel.valid_halfedge(next)) {
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

      if (!genDcel.valid_halfedge(twin)) {
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

  bool build_vertex_matches(SimplifyScratch &scratch) {
    scratch.vertexMatches.clear();

    /*
     * Reserve based only on paired strips. One-sided strips cannot
     * generate matches.
     */
    std::size_t estimatedMatchCount = 0;

    for (int i = 0; i <= scratch.maxOrigHE; ++i) {
      const auto &set1 = scratch.vertexSets1[i];
      const auto &set2 = scratch.vertexSets2[i];

      if (!set1.empty() && !set2.empty()) {
        estimatedMatchCount += std::max(set1.size(), set2.size());
      }
    }

    scratch.vertexMatches.reserve(estimatedMatchCount);

    for (int i = 0; i <= scratch.maxOrigHE; ++i) {
      log_progress("vertex match build", i, scratch.maxOrigHE + 1);

      const auto &vertexSet1 = scratch.vertexSets1[i];

      const auto &vertexSet2 = scratch.vertexSets2[i];

      /*
       * A match requires two corresponding strips.
       *
       * Both empty:
       *   this original halfedge produced no boundary strip.
       *
       * One empty:
       *   this is an external/open boundary with no opposite side to
       *   identify. Leave its vertices independent.
       */
      if (vertexSet1.empty() || vertexSet2.empty()) {
        if (mData.verbose && vertexSet1.empty() != vertexSet2.empty()) {
          std::cout << "[Directional::NFunctionMesher::"
                       "build_vertex_matches()]: "
                    << "skipping one-sided boundary strip for "
                       "original halfedge "
                    << i << "; strip sizes " << vertexSet1.size() << " and "
                    << vertexSet2.size() << '\n';
        }

        continue;
      }

      /*
       * The current matching implementation requires equal-size strips.
       * This is still a real inconsistency because both sides exist but
       * have different sampling counts.
       */
      if (vertexSet1.size() != vertexSet2.size()) {
        if (mData.verbose) {
          std::cerr << "[Directional::NFunctionMesher::"
                       "build_vertex_matches()]: "
                    << "mismatched paired strip sizes for original halfedge "
                    << i << ": " << vertexSet1.size() << " versus "
                    << vertexSet2.size() << '\n';
        }

        return false;
      }

      /*
       * Validate vertex IDs before exposing their coordinates through
       * VertexCoordinateView.
       */
      for (const int vertex : vertexSet1) {
        if (!genDcel.valid_vertex(vertex)) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "build_vertex_matches()]: "
                      << "first strip contains invalid vertex " << vertex
                      << " for original halfedge " << i << '\n';
          }

          return false;
        }
      }

      for (const int vertex : vertexSet2) {
        if (!genDcel.valid_vertex(vertex)) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "build_vertex_matches()]: "
                      << "second strip contains invalid vertex " << vertex
                      << " for original halfedge " << i << '\n';
          }

          return false;
        }
      }

      /*
       * No EVector3 arrays are allocated or copied. These lightweight
       * views read exact coordinates directly from the DCEL vertices.
       */
      const VertexCoordinateView pointSet1(genDcel, vertexSet1);

      const VertexCoordinateView pointSet2(genDcel, vertexSet2);

      std::vector<std::pair<int, int>> currentMatches;

      try {
        currentMatches = FindVertexMatch(mData.verbose, pointSet1, pointSet2);

      } catch (const std::exception &error) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "build_vertex_matches()]: "
                  << "matching failed for original halfedge " << i
                  << " with strip sizes " << pointSet1.size() << " and "
                  << pointSet2.size() << ": " << error.what() << '\n';

        return false;
      }

      for (const auto &match : currentMatches) {
        const int firstLocal = match.first;

        const int secondLocal = match.second;

        if (firstLocal < 0 ||
            firstLocal >= static_cast<int>(vertexSet1.size()) ||
            secondLocal < 0 ||
            secondLocal >= static_cast<int>(vertexSet2.size())) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "build_vertex_matches()]: "
                      << "matcher returned an out-of-range local index "
                      << "for original halfedge " << i << ": (" << firstLocal
                      << ", " << secondLocal << ")\n";
          }

          return false;
        }

        scratch.vertexMatches.emplace_back(
            vertexSet1[static_cast<std::size_t>(firstLocal)],
            vertexSet2[static_cast<std::size_t>(secondLocal)]);
      }
    }

    return true;
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

  bool prune_remap_created_degenerates(const std::vector<int> &preRemapOrigin,
                                       const std::vector<int> &preRemapTarget) {
    int prunedCount = 0;
    int detailedLogs = 0;

    /*
     * Removing one degenerate may expose another, so repeat
     * until a complete pass makes no change.
     *
     * Each successful removal strictly reduces the number of
     * valid halfedges, which guarantees termination.
     */
    for (;;) {
      bool changed = false;

      const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

      for (int he = 0; he < halfedgeCount; ++he) {
        if (!genDcel.valid_halfedge(he))
          continue;

        const int next = genDcel.halfedges[he].next;

        if (!genDcel.valid_halfedge(next))
          return false;

        if (genDcel.halfedges[he].vertex != genDcel.halfedges[next].vertex) {
          continue;
        }

        if (mData.verbose && detailedLogs < 8) {
          std::cout << "[Directional::NFunctionMesher::"
                       "prune_remap_created_degenerates()]: "
                    << "removing degenerate halfedge " << he << " origHalfedge="
                    << genDcel.halfedges[he].data.origHalfedge
                    << " face=" << genDcel.halfedges[he].face
                    << " edge=" << genDcel.halfedges[he].edge
                    << " twin=" << genDcel.halfedges[he].twin << " before=("
                    << preRemapOrigin[he] << " -> " << preRemapTarget[he]
                    << ") after=(" << genDcel.halfedges[he].vertex << " -> "
                    << genDcel.halfedges[next].vertex << ")" << std::endl;

          ++detailedLogs;
        }

        const std::size_t validBefore =
            std::count_if(genDcel.halfedges.begin(), genDcel.halfedges.end(),
                          [](const auto &halfedge) { return halfedge.valid; });

        if (!genDcel.remove_degenerate_edge(he, mData.verbose)) {
          return false;
        }

        const std::size_t validAfter =
            std::count_if(genDcel.halfedges.begin(), genDcel.halfedges.end(),
                          [](const auto &halfedge) { return halfedge.valid; });

        if (validAfter >= validBefore) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "prune_remap_created_degenerates()]: "
                      << "successful removal did not reduce "
                         "valid halfedge count"
                      << std::endl;
          }

          return false;
        }

        ++prunedCount;
        changed = true;

        /*
         * Topology changed; restart from index zero.
         */
        break;
      }

      if (!changed)
        break;
    }

    if (!genDcel.rebuild_representative_halfedges(mData.verbose, true)) {
      return false;
    }

    if (mData.verbose) {
      std::cout << "[Directional::NFunctionMesher::"
                   "prune_remap_created_degenerates()]: "
                << "removed degenerate edges: " << prunedCount << std::endl;
    }

    return true;
  }

  int retwin_halfedges() {
    int preservedTwinPairs = 0;
    int staleTwinPairsCleared = 0;
    int twinPairsCreated = 0;

    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    const auto fail = [&](const char *message, const int index = -1) -> int {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "retwin_halfedges()]: "
                  << message;

        if (index >= 0) {
          std::cerr << " (index " << index << ")";
        }

        std::cerr << '\n';
      }

      return -1;
    };

    const auto endpoints = [&](const int halfedge, int &source,
                               int &target) -> bool {
      if (!genDcel.valid_halfedge(halfedge)) {
        return false;
      }

      const int next = genDcel.halfedges[halfedge].next;

      if (!genDcel.valid_halfedge(next)) {
        return false;
      }

      source = genDcel.halfedges[halfedge].vertex;

      target = genDcel.halfedges[next].vertex;

      if (!genDcel.valid_vertex(source) || !genDcel.valid_vertex(target)) {
        return false;
      }

      if (source == target) {
        return false;
      }

      return true;
    };

    const auto directedEdgeKey = [](const int source,
                                    const int target) -> std::uint64_t {
      const std::uint64_t sourceBits =
          static_cast<std::uint64_t>(static_cast<std::uint32_t>(source));

      const std::uint64_t targetBits =
          static_cast<std::uint64_t>(static_cast<std::uint32_t>(target));

      return (sourceBits << 32U) | targetBits;
    };

    /*
     * ------------------------------------------------------------
     * Phase 1: validate existing twin pairs after vertex remapping.
     *
     * Keep pairs whose endpoint directions are still opposite.
     * Clear stale pairs symmetrically so they can be rebuilt below.
     * ------------------------------------------------------------
     */
    std::vector<unsigned char> existingTwinVisited(
        static_cast<std::size_t>(halfedgeCount), static_cast<unsigned char>(0));

    for (int he = 0; he < halfedgeCount; ++he) {
      if (!genDcel.halfedges[he].valid) {
        continue;
      }

      if (existingTwinVisited[he]) {
        continue;
      }

      const int twin = genDcel.halfedges[he].twin;

      if (twin == -1) {
        continue;
      }

      if (twin < -1) {
        return fail("halfedge has invalid negative twin", he);
      }

      if (!genDcel.valid_halfedge(twin)) {
        return fail("halfedge references invalid twin", he);
      }

      if (twin == he) {
        return fail("halfedge is twinned with itself", he);
      }

      /*
       * Mark both now so the pair is handled once.
       */
      existingTwinVisited[he] = static_cast<unsigned char>(1);

      existingTwinVisited[twin] = static_cast<unsigned char>(1);

      const bool mutual = genDcel.halfedges[twin].twin == he;

      int source = -1;
      int target = -1;
      int twinSource = -1;
      int twinTarget = -1;

      if (!endpoints(he, source, target)) {
        return fail("failed to determine halfedge endpoints", he);
      }

      if (!endpoints(twin, twinSource, twinTarget)) {
        return fail("failed to determine twin endpoints", twin);
      }

      const bool reversedEndpoints =
          source == twinTarget && target == twinSource;

      if (mutual && reversedEndpoints) {
        /*
         * This pair is still geometrically and topologically valid.
         */
        ++preservedTwinPairs;
        continue;
      }

      /*
       * Clear both directions if either side still references the other.
       *
       * A non-mutual stale relationship must not survive into the hash
       * rebuild.
       */
      if (genDcel.halfedges[he].twin == twin) {
        genDcel.halfedges[he].twin = -1;
      }

      if (genDcel.halfedges[twin].twin == he) {
        genDcel.halfedges[twin].twin = -1;
      }

      /*
       * If the relationship was non-mutual, clear the current halfedge
       * regardless. Its referenced counterpart will be independently
       * validated when encountered.
       */
      if (!mutual) {
        genDcel.halfedges[he].twin = -1;
      }

      ++staleTwinPairsCleared;
    }

    /*
     * A stale non-mutual relationship may point to another halfedge
     * that still carries an unrelated twin. Perform a final cleanup:
     * every remaining twin must now be mutual and endpoint-reversed.
     */
    for (int he = 0; he < halfedgeCount; ++he) {
      if (!genDcel.halfedges[he].valid) {
        continue;
      }

      const int twin = genDcel.halfedges[he].twin;

      if (twin < 0) {
        continue;
      }

      if (!genDcel.valid_halfedge(twin) || genDcel.halfedges[twin].twin != he) {
        genDcel.halfedges[he].twin = -1;
        continue;
      }

      int source = -1;
      int target = -1;
      int twinSource = -1;
      int twinTarget = -1;

      if (!endpoints(he, source, target) ||
          !endpoints(twin, twinSource, twinTarget)) {
        return fail("failed to validate surviving twin endpoints", he);
      }

      if (source != twinTarget || target != twinSource) {
        genDcel.halfedges[he].twin = -1;

        if (genDcel.halfedges[twin].twin == he) {
          genDcel.halfedges[twin].twin = -1;
        }
      }
    }

    /*
     * ------------------------------------------------------------
     * Phase 2: hash all currently unmatched directed halfedges.
     * ------------------------------------------------------------
     */
    std::unordered_map<std::uint64_t, int> pendingTwins;

    pendingTwins.reserve(genDcel.halfedges.size());

    pendingTwins.max_load_factor(0.7f);

    for (int he = 0; he < halfedgeCount; ++he) {
      log_progress("halfedge twinning", he, halfedgeCount);

      if (!genDcel.halfedges[he].valid) {
        continue;
      }

      /*
       * Correct existing pairs survived Phase 1 and need no work.
       */
      if (genDcel.halfedges[he].twin >= 0) {
        continue;
      }

      int source = -1;
      int target = -1;

      if (!endpoints(he, source, target)) {
        return fail("invalid endpoints for unmatched halfedge", he);
      }

      const std::uint64_t reverseKey = directedEdgeKey(target, source);

      const auto reverse = pendingTwins.find(reverseKey);

      if (reverse == pendingTwins.end()) {
        const std::uint64_t forwardKey = directedEdgeKey(source, target);

        const auto insertion = pendingTwins.emplace(forwardKey, he);

        /*
         * Two unmatched halfedges with identical direction indicate
         * duplicate or non-manifold topology. Silently keeping one would
         * leave the other incorrectly classified as a boundary.
         */
        if (!insertion.second) {
          if (mData.verbose) {
            std::cerr << "[Directional::NFunctionMesher::"
                         "retwin_halfedges()]: "
                      << "duplicate unmatched directed edge " << source
                      << " -> " << target << " at halfedges "
                      << insertion.first->second << " and " << he << '\n';
          }

          return -1;
        }

        continue;
      }

      const int other = reverse->second;

      if (!genDcel.valid_halfedge(other)) {
        return fail("hash table contains invalid halfedge", other);
      }

      if (genDcel.halfedges[other].twin >= 0) {
        return fail("hash candidate is already twinned", other);
      }

      int otherSource = -1;
      int otherTarget = -1;

      if (!endpoints(other, otherSource, otherTarget)) {
        return fail("invalid hash candidate endpoints", other);
      }

      if (otherSource != target || otherTarget != source) {
        return fail("hash candidate endpoint mismatch", other);
      }

      /*
       * ----------------------------------------------------------
       * Create mutual twin relationship.
       * ----------------------------------------------------------
       */
      genDcel.halfedges[other].twin = he;
      genDcel.halfedges[he].twin = other;

      const int otherEdge = genDcel.halfedges[other].edge;

      const int currentEdge = genDcel.halfedges[he].edge;

      if (!genDcel.valid_edge(otherEdge)) {
        return fail("candidate twin references invalid edge", otherEdge);
      }

      if (!genDcel.valid_edge(currentEdge)) {
        return fail("current halfedge references invalid edge", currentEdge);
      }

      if (otherEdge != currentEdge) {
        /*
         * Preserve the current implementation's ownership rule:
         *
         * currentEdge survives;
         * otherEdge is retired;
         * both halfedges point at currentEdge.
         */
        genDcel.edges[otherEdge].valid = false;
        genDcel.edges[otherEdge].halfedge = -1;

        genDcel.halfedges[other].edge = currentEdge;
      }

      genDcel.edges[currentEdge].valid = true;
      genDcel.edges[currentEdge].halfedge = he;

      if (genDcel.halfedges[he].data.isFunction ||
          genDcel.halfedges[other].data.isFunction) {
        genDcel.halfedges[he].data.isFunction = true;
        genDcel.halfedges[other].data.isFunction = true;
      }

      pendingTwins.erase(reverse);
      ++twinPairsCreated;
    }

    /*
     * ------------------------------------------------------------
     * Phase 3: validate all resulting twin relationships.
     * ------------------------------------------------------------
     */
    for (int he = 0; he < halfedgeCount; ++he) {
      if (!genDcel.halfedges[he].valid) {
        continue;
      }

      const int twin = genDcel.halfedges[he].twin;

      if (twin == -1) {
        continue;
      }

      if (!genDcel.valid_halfedge(twin)) {
        return fail("resulting twin is invalid", he);
      }

      if (genDcel.halfedges[twin].twin != he) {
        return fail("resulting twin relationship is not mutual", he);
      }

      int source = -1;
      int target = -1;
      int twinSource = -1;
      int twinTarget = -1;

      if (!endpoints(he, source, target) ||
          !endpoints(twin, twinSource, twinTarget)) {
        return fail("failed to validate final twin endpoints", he);
      }

      if (source != twinTarget || target != twinSource) {
        return fail("final twin endpoints are not reversed", he);
      }

      if (genDcel.halfedges[he].edge != genDcel.halfedges[twin].edge) {
        return fail("final twin pair references different edges", he);
      }
    }

    if (mData.verbose) {
      std::cout << "[Directional::NFunctionMesher::"
                   "retwin_halfedges()]: preserved "
                << preservedTwinPairs << " existing twin pairs, cleared "
                << staleTwinPairsCleared << " stale pairs, created "
                << twinPairsCreated
                << " new twin pairs; unmatched boundary halfedges: "
                << pendingTwins.size() << '\n';
    }

    return twinPairsCreated;
  }

  bool classify_triangle_regions(SimplifyScratch &scratch) {
    const int vertexCount = static_cast<int>(genDcel.vertices.size());

    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

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

      if (!genDcel.valid_vertex_index(origin)) {
        return fail("valid halfedge references invalid origin vertex",
                    halfedge);
      }

      const int next = he.next;

      if (!genDcel.valid_halfedge_index(next)) {
        return fail("valid halfedge has invalid next link", halfedge);
      }

      const int target = genDcel.halfedges[next].vertex;

      if (!genDcel.valid_vertex_index(target)) {
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
      } else if (!genDcel.valid_halfedge(he.twin)) {
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

      if (!genDcel.valid_halfedge(incident)) {
        return fail("valid vertex references invalid incident halfedge",
                    vertex);
      }

      if (genDcel.halfedges[incident].vertex != vertex) {
        return fail("vertex incident halfedge has different origin", vertex);
      }

      const int prev = genDcel.halfedges[incident].prev;

      if (!genDcel.valid_halfedge_index(prev)) {
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

      if (incidentTwin >= 0 && !genDcel.valid_halfedge(incidentTwin)) {
        return fail("incident halfedge has invalid twin", incident);
      }

      if (prevTwin >= 0 && !genDcel.valid_halfedge(prevTwin)) {
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

      if (!genDcel.valid_halfedge(heBegin)) {
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
          if (!genDcel.valid_halfedge(heBegin)) {
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

          if (!genDcel.valid_halfedge_index(prev)) {
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

          if (!genDcel.valid_halfedge(twin)) {
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
        if (!genDcel.valid_halfedge(he)) {
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

        if (!genDcel.valid_halfedge(twin)) {
          return fail(i,
                      "invalid twin during forward "
                      "fan walk",
                      twin);
        }

        const int next = genDcel.halfedges[twin].next;

        if (!genDcel.valid_halfedge_index(next)) {
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

        if (!genDcel.valid_halfedge(current) ||
            !genDcel.valid_halfedge(successor)) {
          return fail(i,
                      "invalid retained halfedge before "
                      "rewiring",
                      current);
        }

        if (!genDcel.valid_halfedge(twin)) {
          return fail(i,
                      "retained nonterminal halfedge has "
                      "no valid twin",
                      current);
        }
      }

      int boundaryPrev = -1;

      if (scratch.isBoundary[i]) {
        boundaryPrev = genDcel.halfedges[heBegin].prev;

        if (!genDcel.valid_halfedge(boundaryPrev)) {
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

  bool collect_face_cycle(const int startHalfedge, std::vector<int> &cycle,
                          const char *context,
                          const int expectedFace = -1) const {
    cycle.clear();

    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    const int faceCount = static_cast<int>(genDcel.faces.size());

    const auto fail = [&](const char *message, const int index = -1) -> bool {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::" << context
                  << "]: " << message;

        if (index >= 0) {
          std::cerr << " (index " << index << ")";
        }

        std::cerr << '\n';
      }

      cycle.clear();
      return false;
    };

    if (halfedgeCount == 0) {
      return fail("DCEL contains no halfedges");
    }

    if (!genDcel.valid_halfedge(startHalfedge)) {
      return fail("invalid starting halfedge", startHalfedge);
    }

    if (expectedFace >= 0 && !genDcel.valid_face_index(expectedFace)) {
      return fail("expected face is out of range", expectedFace);
    }

    std::vector<unsigned char> visited(static_cast<std::size_t>(halfedgeCount),
                                       static_cast<unsigned char>(0));

    int current = startHalfedge;

    for (int step = 0; step < halfedgeCount; ++step) {

      if (!genDcel.valid_halfedge_index(current)) {
        return fail("face walk reached an out-of-range "
                    "halfedge",
                    current);
      }

      if (!genDcel.halfedges[current].valid) {
        return fail("face walk reached an invalid halfedge", current);
      }

      if (visited[current]) {
        if (current == startHalfedge) {
          return !cycle.empty();
        }

        return fail("face walk entered a cycle that does not "
                    "return to its starting halfedge",
                    current);
      }

      visited[current] = 1;

      if (expectedFace >= 0 &&
          genDcel.halfedges[current].face != expectedFace) {
        return fail("halfedge in cycle references a different "
                    "face",
                    current);
      }

      cycle.push_back(current);

      const int next = genDcel.halfedges[current].next;

      if (!genDcel.valid_halfedge_index(next)) {
        return fail("face walk encountered an out-of-range "
                    "next link",
                    next);
      }

      if (!genDcel.halfedges[next].valid) {
        return fail("face walk next link points to an invalid "
                    "halfedge",
                    next);
      }

      current = next;

      if (current == startHalfedge) {
        return true;
      }
    }

    return fail("face walk exceeded the halfedge traversal bound",
                startHalfedge);
  }

  bool realign_faces() {
    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    const int faceCount = static_cast<int>(genDcel.faces.size());

    const auto fail = [&](const char *message, const int index = -1) -> bool {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "realign_faces()]: "
                  << message;

        if (index >= 0) {
          std::cerr << " (index " << index << ")";
        }

        std::cerr << '\n';
      }

      return false;
    };

    std::vector<unsigned char> globallyVisited(
        static_cast<std::size_t>(halfedgeCount), static_cast<unsigned char>(0));

    std::vector<unsigned char> usedFace(static_cast<std::size_t>(faceCount),
                                        static_cast<unsigned char>(0));

    std::vector<int> cycle;

    for (int seed = 0; seed < halfedgeCount; ++seed) {

      log_progress("face realignment", seed, halfedgeCount);

      if (!genDcel.halfedges[seed].valid || globallyVisited[seed]) {
        continue;
      }

      const int currentFace = genDcel.halfedges[seed].face;

      if (!genDcel.valid_face_index(currentFace)) {
        return fail("valid halfedge references an "
                    "out-of-range face",
                    seed);
      }

      /*
       * Collect the complete cycle before mutating any
       * face assignments.
       *
       * expectedFace is deliberately -1 here because this
       * function is itself repairing face ownership.
       */
      if (!collect_face_cycle(seed, cycle, "realign_faces", -1)) {
        return false;
      }

      if (cycle.empty()) {
        return fail("collected an empty face cycle", seed);
      }

      /*
       * A cycle must not overlap one already assigned from
       * another seed.
       */
      for (const int he : cycle) {
        if (globallyVisited[he]) {
          return fail("face cycle overlaps a previously "
                      "processed cycle",
                      he);
        }
      }

      /*
       * Commit only after the whole cycle was validated.
       */
      genDcel.faces[currentFace].valid = true;
      genDcel.faces[currentFace].halfedge = seed;
      usedFace[currentFace] = 1;

      for (const int he : cycle) {
        genDcel.halfedges[he].face = currentFace;

        globallyVisited[he] = 1;
      }
    }

    /*
     * Any face that no longer owns a surviving cycle is
     * invalidated.
     */
    for (int face = 0; face < faceCount; ++face) {

      if (!usedFace[face]) {
        genDcel.faces[face].valid = false;
        genDcel.faces[face].halfedge = -1;
      }
    }

    return true;
  }

  bool prune_low_quality_faces_and_count_valence(SimplifyScratch &scratch) {
    const int vertexCount = static_cast<int>(genDcel.vertices.size());

    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    const int edgeCount = static_cast<int>(genDcel.edges.size());

    const int faceCount = static_cast<int>(genDcel.faces.size());

    /*
     * Preserve the complete DCEL so that any failure during mutation can
     * restore the exact topology that existed before this function.
     */
    const FunctionDCEL backupDcel = genDcel;

    const auto rollback = [&]() { genDcel = backupDcel; };

    const auto fail = [&](const std::string &message,
                          const int index = -1) -> bool {
      rollback();

      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "prune_low_quality_faces_and_count_valence()]: "
                  << message;

        if (index >= 0) {
          std::cerr << " (index " << index << ")";
        }

        std::cerr << std::endl;
      }

      return false;
    };

    const auto validVertexIndex = [&](const int index) -> bool {
      return index >= 0 && index < vertexCount;
    };

    const auto validHalfedgeIndex = [&](const int index) -> bool {
      return index >= 0 && index < halfedgeCount;
    };

    const auto validEdgeIndex = [&](const int index) -> bool {
      return index >= 0 && index < edgeCount;
    };

    const auto validFaceIndex = [&](const int index) -> bool {
      return index >= 0 && index < faceCount;
    };

    const auto validVertex = [&](const int index) -> bool {
      return validVertexIndex(index) && genDcel.vertices[index].valid;
    };

    const auto validHalfedge = [&](const int index) -> bool {
      return validHalfedgeIndex(index) && genDcel.halfedges[index].valid;
    };

    const auto validEdge = [&](const int index) -> bool {
      return validEdgeIndex(index) && genDcel.edges[index].valid;
    };

    const auto validFace = [&](const int index) -> bool {
      return validFaceIndex(index) && genDcel.faces[index].valid;
    };

    /*
     * Safely collect one complete face cycle.
     *
     * This function performs no topology mutation.
     */
    const auto collectFaceCycle = [&](const int faceIndex,
                                      std::vector<int> &cycle) -> bool {
      cycle.clear();

      if (!validFace(faceIndex)) {
        return false;
      }

      const int start = genDcel.faces[faceIndex].halfedge;

      if (!validHalfedge(start)) {
        return false;
      }

      std::vector<unsigned char> visited(
          static_cast<std::size_t>(halfedgeCount),
          static_cast<unsigned char>(0));

      int current = start;

      for (int step = 0; step < halfedgeCount; ++step) {
        if (!validHalfedge(current)) {
          return false;
        }

        if (visited[current]) {
          /*
           * Returning to the original halfedge is valid. Repeating any
           * other halfedge indicates a malformed subcycle.
           */
          return current == start && !cycle.empty();
        }

        const auto &halfedge = genDcel.halfedges[current];

        if (halfedge.face != faceIndex) {
          return false;
        }

        visited[current] = static_cast<unsigned char>(1);

        cycle.push_back(current);

        const int next = halfedge.next;

        if (!validHalfedge(next)) {
          return false;
        }

        if (genDcel.halfedges[next].prev != current) {
          return false;
        }

        current = next;

        if (current == start) {
          return true;
        }
      }

      return false;
    };

    /*
     * Compute valence from the current topology.
     *
     * On a boundary halfedge, count the target vertex in addition to the
     * origin vertex. This preserves the behavior of the original code.
     */
    const auto computeCurrentValences =
        [&](std::vector<int> &valences) -> bool {
      valences.assign(static_cast<std::size_t>(vertexCount), 0);

      for (int he = 0; he < halfedgeCount; ++he) {
        if (!genDcel.halfedges[he].valid) {
          continue;
        }

        const auto &halfedge = genDcel.halfedges[he];

        const int origin = halfedge.vertex;

        if (!validVertex(origin)) {
          return false;
        }

        ++valences[origin];

        if (halfedge.twin < 0) {
          const int next = halfedge.next;

          if (!validHalfedge(next)) {
            return false;
          }

          const int target = genDcel.halfedges[next].vertex;

          if (!validVertex(target)) {
            return false;
          }

          ++valences[target];
        }
      }

      return true;
    };

    /*
     * ------------------------------------------------------------------
     * Phase 1: calculate pre-pruning valences.
     * ------------------------------------------------------------------
     */
    std::vector<int> prePruneValences;

    if (!computeCurrentValences(prePruneValences)) {
      return fail("failed to compute valid pre-pruning vertex valences");
    }

    /*
     * ------------------------------------------------------------------
     * Phase 2: collect every valid face cycle and decide which faces
     * should be removed.
     *
     * No topology is changed during this phase.
     * ------------------------------------------------------------------
     */
    std::vector<int> facesToRemove;
    std::vector<std::vector<int>> removalCycles;

    facesToRemove.reserve(static_cast<std::size_t>(faceCount));

    removalCycles.reserve(static_cast<std::size_t>(faceCount));

    std::vector<unsigned char> halfedgeScheduledForRemoval(
        static_cast<std::size_t>(halfedgeCount), static_cast<unsigned char>(0));

    std::vector<int> cycle;

    for (int face = 0; face < faceCount; ++face) {
      log_progress("low-quality face scan", face, faceCount);

      if (!genDcel.faces[face].valid) {
        continue;
      }

      if (!collectFaceCycle(face, cycle)) {
        return fail("failed to collect a valid closed face cycle", face);
      }

      if (cycle.size() < 3) {
        return fail("valid face contains fewer than three halfedges", face);
      }

      int highValenceCornerCount = 0;

      for (const int he : cycle) {
        const int vertex = genDcel.halfedges[he].vertex;

        if (!validVertex(vertex)) {
          return fail("face cycle references an invalid vertex", he);
        }

        if (prePruneValences[vertex] > 2) {
          ++highValenceCornerCount;
        }
      }

      /*
       * Preserve faces containing at least three high-valence corners.
       */
      if (highValenceCornerCount >= 3) {
        continue;
      }

      /*
       * A valid halfedge must not occur in more than one face cycle.
       */
      for (const int he : cycle) {
        if (halfedgeScheduledForRemoval[he]) {
          return fail("halfedge occurs in more than one "
                      "face-removal cycle",
                      he);
        }

        halfedgeScheduledForRemoval[he] = static_cast<unsigned char>(1);
      }

      facesToRemove.push_back(face);
      removalCycles.push_back(cycle);
    }

    /*
     * ------------------------------------------------------------------
     * Phase 3: validate all scheduled removals before changing topology.
     * ------------------------------------------------------------------
     */
    for (std::size_t removalIndex = 0; removalIndex < removalCycles.size();
         ++removalIndex) {
      const int face = facesToRemove[removalIndex];

      if (!validFace(face)) {
        return fail("scheduled removal face became invalid before mutation",
                    face);
      }

      for (const int he : removalCycles[removalIndex]) {
        if (!validHalfedge(he)) {
          return fail("scheduled removal contains an invalid halfedge", he);
        }

        const auto &halfedge = genDcel.halfedges[he];

        if (halfedge.face != face) {
          return fail("scheduled halfedge references the wrong face", he);
        }

        if (!validHalfedge(halfedge.prev)) {
          return fail("scheduled halfedge has an invalid prev link", he);
        }

        if (!validHalfedge(halfedge.next)) {
          return fail("scheduled halfedge has an invalid next link", he);
        }

        if (genDcel.halfedges[halfedge.prev].next != he) {
          return fail("scheduled halfedge prev.next relation "
                      "is inconsistent",
                      he);
        }

        if (genDcel.halfedges[halfedge.next].prev != he) {
          return fail("scheduled halfedge next.prev relation "
                      "is inconsistent",
                      he);
        }

        if (!validEdge(halfedge.edge)) {
          return fail("scheduled halfedge references an invalid edge", he);
        }

        if (!validVertex(halfedge.vertex)) {
          return fail("scheduled halfedge references an invalid vertex", he);
        }

        const int twin = halfedge.twin;

        if (twin < -1) {
          return fail("scheduled halfedge has an invalid negative twin", he);
        }

        if (twin >= 0) {
          if (!validHalfedge(twin)) {
            return fail("scheduled halfedge references an invalid twin", he);
          }

          if (genDcel.halfedges[twin].twin != he) {
            return fail("scheduled halfedge twin relation is not mutual", he);
          }

          if (genDcel.halfedges[twin].edge != halfedge.edge) {
            return fail("twin halfedges reference different edges", he);
          }
        }
      }
    }

    /*
     * Optional pre-mutation edge ownership validation.
     *
     * Every manifold edge may have at most two valid halfedge users.
     */
    {
      std::vector<int> validUsersPerEdge(static_cast<std::size_t>(edgeCount),
                                         0);

      for (int he = 0; he < halfedgeCount; ++he) {
        if (!genDcel.halfedges[he].valid) {
          continue;
        }

        const int edge = genDcel.halfedges[he].edge;

        if (!validEdgeIndex(edge)) {
          return fail("valid halfedge references an out-of-range edge", he);
        }

        ++validUsersPerEdge[edge];

        if (validUsersPerEdge[edge] > 2) {
          return fail("edge is referenced by more than two "
                      "valid halfedges before pruning",
                      edge);
        }
      }
    }

    /*
     * ------------------------------------------------------------------
     * Phase 4: invalidate all scheduled faces and halfedges.
     *
     * Edge records are intentionally not invalidated here. Their final
     * status is rebuilt globally from the complete surviving halfedge set
     * in Phase 5.
     * ------------------------------------------------------------------
     */
    for (std::size_t removalIndex = 0; removalIndex < removalCycles.size();
         ++removalIndex) {
      const int face = facesToRemove[removalIndex];

      if (!validFace(face)) {
        return fail("scheduled removal face became invalid during commit",
                    face);
      }

      for (const int he : removalCycles[removalIndex]) {
        if (!validHalfedge(he)) {
          return fail("scheduled removal halfedge became invalid "
                      "during commit",
                      he);
        }

        const int twin = genDcel.halfedges[he].twin;

        /*
         * If the opposite side survives, convert it to a boundary
         * halfedge. Its edge representative is rebuilt later.
         */
        if (twin >= 0 && !halfedgeScheduledForRemoval[twin]) {
          if (!validHalfedge(twin)) {
            return fail("removed halfedge has an invalid surviving twin", he);
          }

          if (genDcel.halfedges[twin].twin != he) {
            return fail("removed halfedge has a non-mutual "
                        "surviving twin",
                        he);
          }

          genDcel.halfedges[twin].twin = -1;
        }

        genDcel.halfedges[he].twin = -1;
        genDcel.halfedges[he].valid = false;
      }

      genDcel.faces[face].valid = false;
      genDcel.faces[face].halfedge = -1;
    }

    /*
     * ------------------------------------------------------------------
     * Phase 5: rebuild every edge from the halfedges that actually
     * survived the complete removal set.
     *
     * A manifold edge has at most two valid halfedge users, so fixed
     * storage avoids one vector allocation per edge.
     * ------------------------------------------------------------------
     */
    struct EdgeSurvivors {
      int first = -1;
      int second = -1;
      std::uint8_t count = 0;
    };

    std::vector<EdgeSurvivors> survivingHalfedgesByEdge(
        static_cast<std::size_t>(edgeCount));

    for (int he = 0; he < halfedgeCount; ++he) {
      if (!genDcel.halfedges[he].valid) {
        continue;
      }

      const int edge = genDcel.halfedges[he].edge;

      if (!validEdgeIndex(edge)) {
        return fail("surviving halfedge references an out-of-range edge", he);
      }

      EdgeSurvivors &entry =
          survivingHalfedgesByEdge[static_cast<std::size_t>(edge)];

      if (entry.count == 0) {
        entry.first = he;
        entry.count = 1;
      } else if (entry.count == 1) {
        entry.second = he;
        entry.count = 2;
      } else {
        return fail("edge has more than two surviving halfedges", edge);
      }
    }

    /*
     * Clear all edge records first. Surviving edges are explicitly
     * reactivated below.
     */
    for (int edge = 0; edge < edgeCount; ++edge) {
      genDcel.edges[edge].valid = false;
      genDcel.edges[edge].halfedge = -1;
    }

    for (int edge = 0; edge < edgeCount; ++edge) {
      const EdgeSurvivors &entry =
          survivingHalfedgesByEdge[static_cast<std::size_t>(edge)];

      if (entry.count == 0) {
        continue;
      }

      if (entry.count == 1) {
        const int he = entry.first;

        if (!validHalfedge(he)) {
          return fail("edge rebuild found an invalid sole survivor", edge);
        }

        if (genDcel.halfedges[he].edge != edge) {
          return fail("sole surviving halfedge references a different edge",
                      edge);
        }

        genDcel.edges[edge].valid = true;
        genDcel.edges[edge].halfedge = he;

        /*
         * One surviving side means this is now a boundary edge.
         */
        genDcel.halfedges[he].twin = -1;
        continue;
      }

      if (entry.count == 2) {
        const int first = entry.first;
        const int second = entry.second;

        if (!validHalfedge(first) || !validHalfedge(second)) {
          return fail("edge rebuild found an invalid two-sided survivor", edge);
        }

        if (first == second) {
          return fail("edge rebuild recorded the same halfedge twice", edge);
        }

        if (genDcel.halfedges[first].edge != edge ||
            genDcel.halfedges[second].edge != edge) {
          return fail("surviving halfedge edge ownership is inconsistent",
                      edge);
        }

        if (genDcel.halfedges[first].twin != second ||
            genDcel.halfedges[second].twin != first) {
          return fail("two surviving halfedges sharing an edge "
                      "are not mutual twins",
                      edge);
        }

        genDcel.edges[edge].valid = true;
        genDcel.edges[edge].halfedge = first;
        continue;
      }

      /*
       * The population loop above rejects count > 2, so reaching this
       * branch means the fixed-storage invariant was corrupted.
       */
      return fail("edge survivor count is outside the supported range", edge);
    }

    /*
     * ------------------------------------------------------------------
     * Phase 6: rebuild vertex, edge, and face representative pointers
     * from valid surviving halfedges.
     * ------------------------------------------------------------------
     */
    for (auto &vertex : genDcel.vertices) {
      vertex.halfedge = -1;
    }

    for (auto &edge : genDcel.edges) {
      edge.halfedge = -1;
    }

    for (auto &face : genDcel.faces) {
      face.halfedge = -1;
    }

    for (int he = 0; he < halfedgeCount; ++he) {
      if (!genDcel.halfedges[he].valid) {
        continue;
      }

      const auto &halfedge = genDcel.halfedges[he];

      const int vertex = halfedge.vertex;
      const int edge = halfedge.edge;
      const int face = halfedge.face;

      if (!validVertexIndex(vertex) || !genDcel.vertices[vertex].valid) {
        return fail("surviving halfedge references an invalid vertex", he);
      }

      if (!validEdgeIndex(edge) || !genDcel.edges[edge].valid) {
        return fail("surviving halfedge references an invalid edge", he);
      }

      if (!validFaceIndex(face) || !genDcel.faces[face].valid) {
        return fail("surviving halfedge references an invalid face", he);
      }

      if (genDcel.vertices[vertex].halfedge < 0) {
        genDcel.vertices[vertex].halfedge = he;
      }

      if (genDcel.edges[edge].halfedge < 0) {
        genDcel.edges[edge].halfedge = he;
      }

      if (genDcel.faces[face].halfedge < 0) {
        genDcel.faces[face].halfedge = he;
      }
    }

    /*
     * Vertices with no surviving incident halfedge are isolated and
     * should no longer remain active.
     */
    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      if (!genDcel.vertices[vertex].valid) {
        continue;
      }

      if (genDcel.vertices[vertex].halfedge < 0) {
        genDcel.vertices[vertex].valid = false;
      }
    }

    /*
     * Every surviving edge and face must have a representative
     * halfedge.
     */
    for (int edge = 0; edge < edgeCount; ++edge) {
      if (genDcel.edges[edge].valid && genDcel.edges[edge].halfedge < 0) {
        return fail("surviving edge has no representative halfedge", edge);
      }
    }

    for (int face = 0; face < faceCount; ++face) {
      if (genDcel.faces[face].valid && genDcel.faces[face].halfedge < 0) {
        return fail("surviving face has no representative halfedge", face);
      }
    }

    /*
     * ------------------------------------------------------------------
     * Phase 7: validate rebuilt edge ownership.
     * ------------------------------------------------------------------
     */
    for (int edge = 0; edge < edgeCount; ++edge) {
      if (!genDcel.edges[edge].valid) {
        continue;
      }

      const EdgeSurvivors &entry =
          survivingHalfedgesByEdge[static_cast<std::size_t>(edge)];

      if (entry.count == 0 || entry.count > 2) {
        return fail("valid rebuilt edge has an invalid survivor count", edge);
      }

      const int representative = genDcel.edges[edge].halfedge;

      if (!validHalfedge(representative)) {
        return fail("valid rebuilt edge has an invalid representative", edge);
      }

      if (genDcel.halfedges[representative].edge != edge) {
        return fail("rebuilt edge representative points to a different edge",
                    edge);
      }

      if (entry.count == 1) {
        if (representative != entry.first) {
          return fail(
              "single-sided edge representative does not match survivor", edge);
        }

        if (genDcel.halfedges[entry.first].twin != -1) {
          return fail("single-sided rebuilt edge is not marked as a boundary",
                      edge);
        }

        continue;
      }

      const int first = entry.first;
      const int second = entry.second;

      if (!validHalfedge(first) || !validHalfedge(second)) {
        return fail("two-sided rebuilt edge contains an invalid survivor",
                    edge);
      }

      if (representative != first && representative != second) {
        return fail("two-sided edge representative is not one of its survivors",
                    edge);
      }

      if (genDcel.halfedges[first].edge != edge ||
          genDcel.halfedges[second].edge != edge) {
        return fail("two-sided rebuilt edge has inconsistent ownership", edge);
      }

      if (genDcel.halfedges[first].twin != second ||
          genDcel.halfedges[second].twin != first) {
        return fail("two-sided rebuilt edge does not contain mutual twins",
                    edge);
      }
    }

    /*
     * ------------------------------------------------------------------
     * Phase 8: recompute valences from the post-pruning topology.
     *
     * This prevents stale pre-pruning values from being passed into the
     * low-valence unification stage.
     * ------------------------------------------------------------------
     */
    if (!computeCurrentValences(scratch.valences)) {
      return fail("failed to compute post-pruning vertex valences");
    }

    /*
     * Final topology validation. Any failure restores the complete
     * pre-function DCEL.
     */
    if (!genDcel.check_consistency(mData.verbose, true, true, true)) {
      return fail("post-pruning DCEL consistency check failed");
    }

    if (mData.verbose) {
      std::cout << "[Directional::NFunctionMesher::"
                   "prune_low_quality_faces_and_count_valence()]: "
                << "removed " << facesToRemove.size() << " low-quality faces"
                << std::endl;
    }

    return true;
  }

  bool refresh_low_valence_cache(SimplifyScratch &scratch) {
    const int vertexCount = static_cast<int>(genDcel.vertices.size());
    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    const auto fail = [&](const char *message, const int index = -1) {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "refresh_low_valence_cache()]: "
                  << message;

        if (index >= 0)
          std::cerr << " (index " << index << ")";

        std::cerr << '\n';
      }

      return false;
    };

    /*
     * Every topology mutation may invalidate or replace representative
     * halfedges. Rebuild those pointers before deriving cached state.
     */
    if (!genDcel.rebuild_representative_halfedges(mData.verbose, true)) {
      return false;
    }

    scratch.valences.assign(static_cast<std::size_t>(vertexCount), 0);
    scratch.isBoundary.assign(static_cast<std::size_t>(vertexCount), false);
    scratch.isEar.assign(static_cast<std::size_t>(vertexCount), false);

    /*
     * Recompute valence using the same convention already used by
     * prune_low_quality_faces_and_count_valence():
     *
     * - each valid halfedge contributes to its origin;
     * - a boundary halfedge also contributes to its target.
     */
    for (int he = 0; he < halfedgeCount; ++he) {
      if (!genDcel.halfedges[he].valid)
        continue;

      const auto &halfedge = genDcel.halfedges[he];
      const int origin = halfedge.vertex;

      if (!genDcel.valid_vertex(origin)) {
        return fail("valid halfedge references invalid origin vertex", he);
      }

      ++scratch.valences[origin];

      if (halfedge.twin == -1) {
        scratch.isBoundary[origin] = true;

        const int next = halfedge.next;

        if (!genDcel.valid_halfedge(next)) {
          return fail("boundary halfedge has invalid next", he);
        }

        const int target = genDcel.halfedges[next].vertex;

        if (!genDcel.valid_vertex(target)) {
          return fail("boundary halfedge references invalid target vertex", he);
        }

        ++scratch.valences[target];
        scratch.isBoundary[target] = true;

      } else if (halfedge.twin < -1) {
        return fail("halfedge has invalid negative twin sentinel", he);

      } else if (!genDcel.valid_halfedge(halfedge.twin)) {
        return fail("halfedge references invalid twin", he);
      }
    }

    /*
     * Recompute ears from all outgoing halfedges. This avoids making ear
     * classification depend on the arbitrary representative halfedge selected
     * by rebuild_representative_halfedges().
     */
    for (int he = 0; he < halfedgeCount; ++he) {
      if (!genDcel.halfedges[he].valid)
        continue;

      const auto &halfedge = genDcel.halfedges[he];
      const int vertex = halfedge.vertex;

      if (!genDcel.valid_vertex(vertex)) {
        return fail("valid halfedge references invalid vertex during ear scan",
                    he);
      }

      if (halfedge.twin != -1)
        continue;

      const int prev = halfedge.prev;

      if (!genDcel.valid_halfedge(prev)) {
        return fail("boundary halfedge has invalid prev during ear scan", he);
      }

      const int prevTwin = genDcel.halfedges[prev].twin;

      if (prevTwin == -1) {
        scratch.isEar[vertex] = true;
        scratch.isBoundary[vertex] = true;

      } else if (prevTwin < -1) {
        return fail("previous halfedge has invalid twin sentinel", prev);

      } else if (!genDcel.valid_halfedge(prevTwin)) {
        return fail("previous halfedge references invalid twin", prev);
      }
    }

    return true;
  }

  bool recompute_current_valences(SimplifyScratch &scratch) {
    const int vertexCount = static_cast<int>(genDcel.vertices.size());
    const int halfedgeCount = static_cast<int>(genDcel.halfedges.size());

    scratch.valences.assign(static_cast<std::size_t>(vertexCount), 0);

    for (int he = 0; he < halfedgeCount; ++he) {
      if (!genDcel.halfedges[he].valid)
        continue;

      const auto &halfedge = genDcel.halfedges[he];
      const int origin = halfedge.vertex;

      if (!genDcel.valid_vertex(origin))
        return false;

      ++scratch.valences[origin];

      if (halfedge.twin == -1) {
        const int next = halfedge.next;

        if (!genDcel.valid_halfedge(next))
          return false;

        const int target = genDcel.halfedges[next].vertex;

        if (!genDcel.valid_vertex(target))
          return false;

        ++scratch.valences[target];

      } else if (halfedge.twin < -1 || !genDcel.valid_halfedge(halfedge.twin)) {
        return false;
      }
    }

    return true;
  }

  bool unify_low_valence_vertices(const SimplifyScratch &scratch,
                                  int &unifyCount) {
    unifyCount = 0;

    const int vertexCount = static_cast<int>(genDcel.vertices.size());

    if (scratch.valences.size() != genDcel.vertices.size() ||
        scratch.isEar.size() != genDcel.vertices.size()) {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "unify_low_valence_vertices()]: "
                  << "scratch cache size does not match vertex count\n";
      }

      return false;
    }

    if (!genDcel.rebuild_representative_halfedges(mData.verbose, true)) {
      return false;
    }

    /*
     * Build the immutable Pass-2-compatible candidate list once.
     */
    std::vector<int> eligibleVertices;
    eligibleVertices.reserve(static_cast<std::size_t>(vertexCount));

    for (int vertex = 0; vertex < vertexCount; ++vertex) {
      if (!genDcel.valid_vertex(vertex))
        continue;

      if (scratch.valences[vertex] > 2)
        continue;

      if (scratch.isEar[vertex])
        continue;

      eligibleVertices.push_back(vertex);
    }

    if (mData.verbose) {
      std::cout << "[Directional::NFunctionMesher::"
                   "unify_low_valence_vertices()]: "
                << "eligible=" << eligibleVertices.size() << '\n';
    }

    /*
     * One transaction for the entire phase instead of one complete
     * DCEL copy per operation.
     */
    const FunctionDCEL backupDcel = genDcel;

    const auto rollback = [&]() { genDcel = backupDcel; };

    for (std::size_t candidateIndex = 0;
         candidateIndex < eligibleVertices.size(); ++candidateIndex) {
      const int vertex = eligibleVertices[candidateIndex];

      log_progress("low-valence edge unification",
                   static_cast<int>(candidateIndex),
                   static_cast<int>(eligibleVertices.size()));

      /*
       * A previous operation may have already removed this candidate.
       * Preserve fixed-snapshot semantics by skipping it rather than
       * introducing new candidates.
       */
      if (!genDcel.valid_vertex(vertex))
        continue;

      const int halfedge = genDcel.vertices[vertex].halfedge;

      if (!genDcel.valid_halfedge(halfedge)) {
        rollback();

        if (mData.verbose) {
          std::cerr << "[Directional::NFunctionMesher::"
                       "unify_low_valence_vertices()]: "
                    << "vertex has no valid outgoing halfedge " << vertex
                    << '\n';
        }

        return false;
      }

      /*
       * Fast batch operation:
       * - no whole-DCEL backup;
       * - no global representative rebuild;
       * - no global consistency check.
       *
       * The function must still perform all local topology
       * validation before mutation.
       */
      if (!genDcel.unify_edges_in_place(halfedge, mData.verbose, false,
                                        false)) {
        rollback();
        return false;
      }

      /*
       * A successful low-valence operation must retire its selected
       * vertex. This replaces two full count_if() scans.
       */
      if (genDcel.valid_vertex(vertex)) {
        rollback();

        if (mData.verbose) {
          std::cerr << "[Directional::NFunctionMesher::"
                       "unify_low_valence_vertices()]: "
                    << "unification did not retire vertex " << vertex << '\n';
        }

        return false;
      }

      ++unifyCount;

#ifndef NDEBUG
      /*
       * Periodic debug validation without paying the full cost for
       * every operation.
       */
      constexpr int validationInterval = 256;

      if ((unifyCount % validationInterval) == 0) {
        if (!genDcel.rebuild_representative_halfedges(mData.verbose, true) ||
            !genDcel.check_consistency(mData.verbose, true, true, false)) {
          rollback();
          return false;
        }
      }
#endif
    }

    /*
     * One global repair and one strict validation for the completed
     * transaction.
     */
    if (!genDcel.rebuild_representative_halfedges(mData.verbose, true)) {
      rollback();
      return false;
    }

    if (!genDcel.check_consistency(mData.verbose, true, true, true)) {
      rollback();
      return false;
    }

    if (mData.verbose) {
      std::cout << "[Directional::NFunctionMesher::"
                   "unify_low_valence_vertices()]: "
                << "completed " << unifyCount << " operations\n";
    }

    return true;
  }

  bool finalize_clean_mesh() {
    const auto fail = [&](const char *message) -> bool {
      if (mData.verbose) {
        std::cerr << "[Directional::NFunctionMesher::"
                     "finalize_clean_mesh()]: "
                  << message << '\n';
      }

      return false;
    };

    /*
     * Snapshot pre-compaction sizes for monotonicity validation.
     */
    const std::size_t oldVertexCount = genDcel.vertices.size();
    const std::size_t oldHalfedgeCount = genDcel.halfedges.size();
    const std::size_t oldEdgeCount = genDcel.edges.size();
    const std::size_t oldFaceCount = genDcel.faces.size();

    const std::size_t expectedVertexCount = static_cast<std::size_t>(
        std::count_if(genDcel.vertices.begin(), genDcel.vertices.end(),
                      [](const auto &entry) { return entry.valid; }));

    const std::size_t expectedHalfedgeCount = static_cast<std::size_t>(
        std::count_if(genDcel.halfedges.begin(), genDcel.halfedges.end(),
                      [](const auto &entry) { return entry.valid; }));

    const std::size_t expectedEdgeCount = static_cast<std::size_t>(
        std::count_if(genDcel.edges.begin(), genDcel.edges.end(),
                      [](const auto &entry) { return entry.valid; }));

    const std::size_t expectedFaceCount = static_cast<std::size_t>(
        std::count_if(genDcel.faces.begin(), genDcel.faces.end(),
                      [](const auto &entry) { return entry.valid; }));

    /*
     * Finalization must begin from a fully consistent state.
     */
    if (!genDcel.check_consistency(mData.verbose, true, true, true)) {
      return fail("pre-clean consistency check failed");
    }

    if (!genDcel.clean_mesh(mData.verbose)) {
      return fail("transactional DCEL compaction failed");
    }

    /*
     * Compaction must preserve exactly the valid entities that existed
     * before the operation.
     */
    if (genDcel.vertices.size() != expectedVertexCount) {
      return fail("compacted vertex count does not match valid "
                  "pre-clean vertex count");
    }

    if (genDcel.halfedges.size() != expectedHalfedgeCount) {
      return fail("compacted halfedge count does not match valid "
                  "pre-clean halfedge count");
    }

    if (genDcel.edges.size() != expectedEdgeCount) {
      return fail("compacted edge count does not match valid "
                  "pre-clean edge count");
    }

    if (genDcel.faces.size() != expectedFaceCount) {
      return fail("compacted face count does not match valid "
                  "pre-clean face count");
    }

    /*
     * Compaction can only preserve or reduce container sizes.
     */
    if (genDcel.vertices.size() > oldVertexCount ||
        genDcel.halfedges.size() > oldHalfedgeCount ||
        genDcel.edges.size() > oldEdgeCount ||
        genDcel.faces.size() > oldFaceCount) {
      return fail("compaction unexpectedly increased an entity count");
    }

    /*
     * No invalid records may remain after compaction.
     */
    if (!std::all_of(genDcel.vertices.begin(), genDcel.vertices.end(),
                     [](const auto &entry) { return entry.valid; })) {
      return fail("invalid vertex survived compaction");
    }

    if (!std::all_of(genDcel.halfedges.begin(), genDcel.halfedges.end(),
                     [](const auto &entry) { return entry.valid; })) {
      return fail("invalid halfedge survived compaction");
    }

    if (!std::all_of(genDcel.edges.begin(), genDcel.edges.end(),
                     [](const auto &entry) { return entry.valid; })) {
      return fail("invalid edge survived compaction");
    }

    if (!std::all_of(genDcel.faces.begin(), genDcel.faces.end(),
                     [](const auto &entry) { return entry.valid; })) {
      return fail("invalid face survived compaction");
    }

    /*
     * Verify dense IDs after compaction.
     */
    for (int index = 0; index < static_cast<int>(genDcel.vertices.size());
         ++index) {
      if (genDcel.vertices[index].ID != index) {
        return fail("vertex IDs are not dense after compaction");
      }
    }

    for (int index = 0; index < static_cast<int>(genDcel.halfedges.size());
         ++index) {
      if (genDcel.halfedges[index].ID != index) {
        return fail("halfedge IDs are not dense after compaction");
      }
    }

    for (int index = 0; index < static_cast<int>(genDcel.edges.size());
         ++index) {
      if (genDcel.edges[index].ID != index) {
        return fail("edge IDs are not dense after compaction");
      }
    }

    for (int index = 0; index < static_cast<int>(genDcel.faces.size());
         ++index) {
      if (genDcel.faces[index].ID != index) {
        return fail("face IDs are not dense after compaction");
      }
    }

    /*
     * Final independent topology validation.
     *
     * clean_mesh() already validates its candidate before commit. Keeping
     * this second check verifies the committed object itself and protects
     * against future changes to clean_mesh().
     */
    if (!genDcel.check_consistency(mData.verbose, true, true, true)) {
      return fail("post-clean consistency check failed");
    }

    if (mData.verbose) {
      std::cout << "[Directional::NFunctionMesher::"
                   "finalize_clean_mesh()]: "
                << "compaction validated successfully: "
                << genDcel.vertices.size() << " vertices, "
                << genDcel.halfedges.size() << " halfedges, "
                << genDcel.edges.size() << " edges, " << genDcel.faces.size()
                << " faces\n";
    }

    return true;
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

    if (!build_vertex_matches(scratch))
      return false;
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

    if (!prune_remap_created_degenerates(preRemapOrigin, preRemapTarget)) {
      return false;
    }

    if (!genDcel.check_consistency(mData.verbose, true, false, false)) {
      return false;
    }

    logPhase("Post-remap pre-twinning consistency check");

    const int retwinned = retwin_halfedges();

    if (retwinned < 0) {
      return false;
    }

    logPhase("Halfedge twinning");

    if (!genDcel.check_consistency(mData.verbose, true, true, true)) {
      return false;
    }

    logPhase("Post-twinning consistency check");
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

    if (!prune_low_quality_faces_and_count_valence(scratch))
      return false;

    logPhase("Low-quality face pruning");

    if (!genDcel.check_consistency(mData.verbose, true, true, true))
      return false;
    logPhase("Post-pruning consistency check");

    int unifyCount = 0;

    if (!unify_low_valence_vertices(scratch, unifyCount)) {
      return false;
    }

    if (mData.verbose) {
      std::cout << "[Directional::NFunctionMesher::simplify_mesh()]: "
                << "Low-valence edge unification finished after " << unifyCount
                << " operations" << std::endl;
    }
    logPhase("Low-valence edge unification and validation");

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
