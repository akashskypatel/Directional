// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2024 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef FUNCTION_MESH_CLASS_HEADER_FILE
#define FUNCTION_MESH_CLASS_HEADER_FILE

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <algorithm>
#include <array>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <directional/NFunctionMesher.h>
#include <directional/dcel.h>
#include <directional/exact_geometric_definitions.h>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <math.h>
#include <queue>
#include <set>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>

// #include <operators/io_stream.hpp>

namespace directional {

struct ArrangementTimings {
  double linePencilBuild = 0.0;
  double lineClip = 0.0;
  double intersections = 0.0;
  double edgeBuild = 0.0;
  double vertexMerge = 0.0;
  double edgeMerge = 0.0;
  double dcelBuild = 0.0;
  double radialSort = 0.0;
  double faceBuild = 0.0;
  double outerFace = 0.0;
  double project3D = 0.0;
  double aggregate = 0.0;
  std::size_t calls = 0;

  double total() const {
    return linePencilBuild + lineClip + intersections + edgeBuild +
           vertexMerge + edgeMerge + dcelBuild + radialSort + faceBuild +
           outerFace + project3D + aggregate;
  }
};

inline ArrangementTimings &arrangement_timings_accumulator() {
  static thread_local ArrangementTimings timings;
  return timings;
}

inline void reset_arrangement_timings() {
  arrangement_timings_accumulator() = ArrangementTimings{};
}

inline double arrangement_seconds_since(
    const std::chrono::high_resolution_clock::time_point &start) {
  return std::chrono::duration<double>(
             std::chrono::high_resolution_clock::now() - start)
      .count();
}

inline void print_arrangement_timings(
    const ArrangementTimings &timings,
    const char *prefix = "[Directional::NFunctionMesher::generate_mesh()]: ") {
  std::cout << prefix << "arrangement timing summary over " << timings.calls
            << " triangles\n"
            << prefix << "  line pencils:  " << timings.linePencilBuild
            << " s\n"
            << prefix << "  line clipping: " << timings.lineClip << " s\n"
            << prefix << "  intersections: " << timings.intersections << " s\n"
            << prefix << "  edge build:    " << timings.edgeBuild << " s\n"
            << prefix << "  vertex merge:  " << timings.vertexMerge << " s\n"
            << prefix << "  edge merge:    " << timings.edgeMerge << " s\n"
            << prefix << "  DCEL build:    " << timings.dcelBuild << " s\n"
            << prefix << "  radial sort:   " << timings.radialSort << " s\n"
            << prefix << "  face build:    " << timings.faceBuild << " s\n"
            << prefix << "  outer face:    " << timings.outerFace << " s\n"
            << prefix << "  3D projection: " << timings.project3D << " s\n"
            << prefix << "  aggregation:   " << timings.aggregate << " s\n"
            << prefix << "  measured total:" << timings.total() << " s\n";
}

struct LineClippingTimings {
  std::size_t calls = 0;
  std::size_t pencilsProcessed = 0;
  std::size_t activePencils = 0;
  std::size_t candidateLines = 0;
  std::size_t acceptedSegments = 0;

  double bounds = 0.0;
  double edgeIntersections = 0.0;
  double exactComparisons = 0.0;
  double segmentConstruction = 0.0;
  double metadataConstruction = 0.0;
  double pencilIntersections = 0.0;
  double total = 0.0;
};

inline LineClippingTimings &line_clipping_timings_accumulator() {
  static LineClippingTimings timings;
  return timings;
}

inline void reset_line_clipping_timings() {
  line_clipping_timings_accumulator() =
      LineClippingTimings{};
}

inline void print_line_clipping_timings(
    const LineClippingTimings &timings) {
  std::cout
      << "[Directional::NFunctionMesher::arrange_on_triangle()]: "
         "line clipping timing summary\n"
      << "  calls:                 "
      << timings.calls << '\n'
      << "  pencils processed:     "
      << timings.pencilsProcessed << '\n'
      << "  active pencils:        "
      << timings.activePencils << '\n'
      << "  candidate lines:       "
      << timings.candidateLines << '\n'
      << "  accepted segments:     "
      << timings.acceptedSegments << '\n'
      << "  bounds/setup:          "
      << timings.bounds << " s\n"
      << "  triangle intersections:"
      << timings.edgeIntersections << " s\n"
      << "  exact comparisons:     "
      << timings.exactComparisons << " s\n"
      << "  segment construction:  "
      << timings.segmentConstruction << " s\n"
      << "  metadata construction: "
      << timings.metadataConstruction << " s\n"
      << "  pencil intersections:  "
      << timings.pencilIntersections << " s\n"
      << "  total clipping:        "
      << timings.total << " s\n";
}

// arranging a line set on a triangle
// triangle is represented by a 3x2 matrix of (CCW) coordinates
// lines are Nx4 matrices of (origin, direction).
// line data is an integer associated with data on the line that gets inherited
// to the halfedges output is the DCEL of the result Outer face is deleted in
// post-process
void NFunctionMesher::arrange_on_triangle(
    const std::vector<EVector2> &triangle,
    const std::vector<std::pair<int, bool>> &triangleData,
    const std::vector<LinePencil> &linePencils,
    const std::vector<int> &linePencilData, std::vector<EVector2> &V,
    FunctionDCEL &triDcel) {
  using namespace std;
  using namespace Eigen;

  using Clock = std::chrono::high_resolution_clock;

  LineClippingTimings &clipTimings = line_clipping_timings_accumulator();

  ArrangementTimings &arrangementTimings = arrangement_timings_accumulator();

  ++clipTimings.calls;
  clipTimings.pencilsProcessed += linePencils.size();

  const auto totalStart = Clock::now();

  /*
   * ------------------------------------------------------------
   * Phase 1: setup and capacity estimation.
   * ------------------------------------------------------------
   */
  auto phaseStart = Clock::now();

  if (triangle.size() != 3) {
    throw std::invalid_argument(
        "arrange_on_triangle(): triangle must contain exactly "
        "three vertices");
  }

  if (triangleData.size() != 3) {
    throw std::invalid_argument(
        "arrange_on_triangle(): triangleData must contain "
        "exactly three entries");
  }

  if (linePencilData.size() != linePencils.size()) {
    throw std::invalid_argument(
        "arrange_on_triangle(): linePencilData size does not "
        "match linePencils size");
  }

  V = triangle;

  std::size_t maximumSegmentCount = 3;

  for (const LinePencil &pencil : linePencils) {
    if (pencil.numLines < 0) {
      throw std::runtime_error(
          "arrange_on_triangle(): line pencil has a negative "
          "line count");
    }

    const std::size_t lineCount = static_cast<std::size_t>(pencil.numLines);

    if (lineCount >
        std::numeric_limits<std::size_t>::max() - maximumSegmentCount) {
      throw std::overflow_error(
          "arrange_on_triangle(): segment capacity overflow");
    }

    maximumSegmentCount += lineCount;

    clipTimings.candidateLines += lineCount;
  }

  std::vector<SegmentData> inData;
  std::vector<Segment2> inSegments;

  inData.reserve(maximumSegmentCount);

  inSegments.reserve(maximumSegmentCount);

  /*
   * uint8_t avoids std::vector<bool>'s proxy-reference behavior.
   */
  std::vector<std::uint8_t> isPencilActive(linePencils.size(), std::uint8_t{0});

  clipTimings.bounds += arrangement_seconds_since(phaseStart);

  /*
   * ------------------------------------------------------------
   * Phase 2: insert the three triangle boundary segments.
   * ------------------------------------------------------------
   */
  phaseStart = Clock::now();

  for (int edge = 0; edge < 3; ++edge) {
    SegmentData newData;

    newData.isFunction = false;
    newData.origHalfedge = triangleData[static_cast<std::size_t>(edge)].first;

    newData.origNFunctionIndex = -1;
    newData.lineInPencil = -1;

    newData.intParams.insert(ENumber(0));

    newData.intParams.insert(ENumber(1));

    inData.push_back(std::move(newData));
  }

  clipTimings.metadataConstruction += arrangement_seconds_since(phaseStart);

  phaseStart = Clock::now();

  for (int edge = 0; edge < 3; ++edge) {
    inSegments.emplace_back(triangle[static_cast<std::size_t>(edge)],
                            triangle[static_cast<std::size_t>((edge + 1) % 3)]);
  }

  clipTimings.segmentConstruction += arrangement_seconds_since(phaseStart);

  /*
   * ------------------------------------------------------------
   * Phase 3: clip every line pencil against the triangle.
   * ------------------------------------------------------------
   */
  for (std::size_t pencilIndex = 0; pencilIndex < linePencils.size();
       ++pencilIndex) {
    const LinePencil &pencil = linePencils[pencilIndex];

    std::vector<ENumber> inParams;
    std::vector<ENumber> outParams;
    std::vector<bool> intEdges;
    std::vector<bool> intFaces;
    std::vector<std::vector<ENumber>> triangleParameters;

    /*
     * This call contains the geometric clipping work. Exact
     * comparisons internal to the helper cannot be separated here
     * without instrumenting that helper itself.
     */
    phaseStart = Clock::now();

    linepencil_triangle_intersection(pencil, triangle, intEdges, intFaces,
                                     inParams, outParams, triangleParameters);

    clipTimings.edgeIntersections += arrangement_seconds_since(phaseStart);

    const std::size_t lineCount = static_cast<std::size_t>(pencil.numLines);

    if (intEdges.size() < lineCount || intFaces.size() < lineCount ||
        inParams.size() < lineCount || outParams.size() < lineCount) {
      throw std::runtime_error("arrange_on_triangle(): triangle intersection "
                               "returned undersized line-result arrays");
    }

    if (triangleParameters.size() != 3) {
      throw std::runtime_error("arrange_on_triangle(): triangle intersection "
                               "returned an invalid triangle-parameter count");
    }

    /*
     * Add intersections lying on each source triangle edge.
     */
    phaseStart = Clock::now();

    for (int edge = 0; edge < 3; ++edge) {
      const auto &parameters =
          triangleParameters[static_cast<std::size_t>(edge)];

      inData[static_cast<std::size_t>(edge)].intParams.insert(
          parameters.begin(), parameters.end());
    }

    clipTimings.metadataConstruction += arrangement_seconds_since(phaseStart);

    bool pencilActive = false;

    for (std::size_t lineIndex = 0; lineIndex < lineCount; ++lineIndex) {
      /*
       * These are Boolean result checks, not exact arithmetic.
       * Do not charge them to exactComparisons.
       */
      if (!intEdges[lineIndex] && !intFaces[lineIndex]) {
        continue;
      }

      pencilActive = true;
      ++clipTimings.acceptedSegments;

      /*
       * Build metadata independently from geometric segment
       * construction so the costs are visible separately.
       */
      phaseStart = Clock::now();

      SegmentData newData;

      newData.isFunction = true;
      newData.origHalfedge = -1;

      /*
       * The original code assigned this twice:
       *
       *   newData.origNFunctionIndex = i;
       *   newData.origNFunctionIndex = linePencilData[i];
       *
       * Only the second assignment had any effect.
       */
      newData.origNFunctionIndex = linePencilData[pencilIndex];

      newData.lineInPencil = static_cast<int>(lineIndex);

      newData.intParams.insert(inParams[lineIndex]);

      newData.intParams.insert(outParams[lineIndex]);

      inData.push_back(std::move(newData));

      clipTimings.metadataConstruction += arrangement_seconds_since(phaseStart);

      phaseStart = Clock::now();

      const ENumber lineOffset(static_cast<long long>(lineIndex), 1);

      const EVector2 basePoint = pencil.p0 + pencil.pVec * lineOffset;

      const EVector2 segmentSource =
          basePoint + pencil.direction * inParams[lineIndex];

      const EVector2 segmentTarget =
          basePoint + pencil.direction * outParams[lineIndex];

      inSegments.emplace_back(segmentSource, segmentTarget);

      clipTimings.segmentConstruction += arrangement_seconds_since(phaseStart);
    }

    if (pencilActive) {
      isPencilActive[pencilIndex] = std::uint8_t{1};

      ++clipTimings.activePencils;
    }
  }

  /*
   * ------------------------------------------------------------
   * Phase 4: precompute intersections between active line pencils.
   * ------------------------------------------------------------
   */
  phaseStart = Clock::now();

  const std::size_t pencilCount = linePencils.size();

  if (pencilCount > std::numeric_limits<std::size_t>::max() /
                        std::max<std::size_t>(pencilCount, std::size_t{1}) /
                        std::size_t{2}) {
    throw std::overflow_error(
        "arrange_on_triangle(): pencil-intersection matrix "
        "size overflow");
  }

  const std::size_t intersectionRowCount =
      std::size_t{2} * pencilCount * pencilCount;

  if (intersectionRowCount >
      static_cast<std::size_t>(std::numeric_limits<Eigen::Index>::max())) {
    throw std::overflow_error(
        "arrange_on_triangle(): pencil-intersection matrix "
        "exceeds Eigen index range");
  }

  Matrix<ENumber, Dynamic, 2> I2dts(
      static_cast<Eigen::Index>(intersectionRowCount), 2);

  Matrix<ENumber, Dynamic, 1> t00s(
      static_cast<Eigen::Index>(intersectionRowCount), 1);

  for (std::size_t first = 0; first < pencilCount; ++first) {
    if (!isPencilActive[first]) {
      continue;
    }

    for (std::size_t second = first + 1; second < pencilCount; ++second) {
      if (!isPencilActive[second]) {
        continue;
      }

      Matrix<ENumber, 2, 2> intersectionDelta;

      Matrix<ENumber, 2, 1> intersectionOrigin;

      EInt overlapIndex;

      linepencil_intersection(linePencils[first], linePencils[second],
                              intersectionOrigin, intersectionDelta,
                              overlapIndex);

      const std::size_t row =
          std::size_t{2} * second + std::size_t{2} * pencilCount * first;

      I2dts.block(static_cast<Eigen::Index>(row), 0, 2, 2) = intersectionDelta;

      t00s.segment(static_cast<Eigen::Index>(row), 2) = intersectionOrigin;
    }
  }

  clipTimings.pencilIntersections += arrangement_seconds_since(phaseStart);

  /*
   * This total intentionally covers only clipping/precomputation.
   * segment_arrangement() remains timed by ArrangementTimings.
   */
  const double clippingTotal = arrangement_seconds_since(totalStart);

  clipTimings.total += clippingTotal;

  arrangementTimings.lineClip += clippingTotal;

  segment_arrangement(inSegments, inData, I2dts, t00s, V, triDcel);
}

void NFunctionMesher::segment_arrangement(
    const std::vector<Segment2> &segments, const std::vector<SegmentData> &data,
    const Eigen::Matrix<ENumber, Eigen::Dynamic, 2> &I2dts,
    const Eigen::Matrix<ENumber, Eigen::Dynamic, 1> &t00s,
    std::vector<EVector2> &V, FunctionDCEL &triDcel) {

  ArrangementTimings &timings = arrangement_timings_accumulator();
  auto phaseStart = std::chrono::high_resolution_clock::now();

  // First creating a graph of segment intersection

  // Creating arrangement vertices
  std::vector<EVector2> arrVertices;
  std::vector<std::set<std::pair<ENumber, int>>> SV(
      segments.size()); // set of coordinates of intersection per segment
  int linePencilSize = sqrt(I2dts.rows() / 2); // should be integer naturally
  std::vector<ENumber> tScales(segments.size());
  std::vector<EVector2> segDirections(segments.size());

  // first unloading intersections with triangle - this assume they are the
  // first intersections
  for (int i = 0; i < segments.size(); i++) {
    tScales[i] =
        ENumber(1) / (*data[i].intParams.rbegin() - *data[i].intParams.begin());
    segDirections[i] = segments[i].target - segments[i].source;
    // std::cout<<"triangle edge"<<i<<std::endl;
    for (ENumber intParam : data[i].intParams) {
      ENumber t = (intParam - *data[i].intParams.begin()) * tScales[i];
      arrVertices.push_back(segments[i].source + segDirections[i] * t);
      // if (data[i].origNFunctionIndex!=-1)
      // arrVertices.push_back(linePencils[data[i].origNFunctionIndex].p0+
      //                       linePencils[data[i].origNFunctionIndex].pVec*EInt(data[i].lineInPencil)+
      //                       linePencils[data[i].origNFunctionIndex].direction*intParam);
      // else  //triangle segment
      //     arrVertices.push_back(segments[i].source * (ENumber(1) - intParam)
      //     + segments[i].target * intParam);
      SV[i].insert(std::pair<ENumber, int>(t, arrVertices.size() - 1));
      // std::cout<<"New arrangement vertex at
      // "<<arrVertices[arrVertices.size()-1]<<std::endl; std::cout<<"On segment
      // "<<segments[i].source<<"->"<<segments[i].target<<std::endl;
    }
  }

  // new intersections which are all
  for (int i = 3; i < segments.size();
       i++) { // starting from non-triangle segments
    for (int j = i + 1; j < segments.size(); j++) {
      if ((data[i].origNFunctionIndex == data[j].origNFunctionIndex) &&
          (data[i].isFunction) && (data[j].isFunction))
        continue; // don't try to intersect from the same line pencil

      Eigen::Matrix<ENumber, 2, 2> I2dt =
          I2dts.block(data[i].origNFunctionIndex * 2 * linePencilSize +
                          2 * data[j].origNFunctionIndex,
                      0, 2, 2);
      Eigen::Matrix<ENumber, 2, 1> t00 =
          t00s.segment(data[i].origNFunctionIndex * 2 * linePencilSize +
                           2 * data[j].origNFunctionIndex,
                       2);
      Eigen::Matrix<ENumber, 2, 1> currI;
      currI << ENumber(data[i].lineInPencil, 0.0),
          ENumber(data[j].lineInPencil, 0.0);
      Eigen::Matrix<ENumber, 2, 1> t1t2 = I2dt * currI + t00;
      // t1t2<<I2dt(0,0)*currI(0)+I2dt(0,1)*currI(1) +
      // t00(0),I2dt(1,0)*currI(0)+I2dt(1,1)*currI(1) + t00(1);
      if ((t1t2(0) < *data[i].intParams.begin()) ||
          (t1t2(0) > *data[i].intParams.rbegin()) ||
          (t1t2(1) < *data[j].intParams.begin()) ||
          (t1t2(1) > *data[j].intParams.rbegin())) // intersecting beyond the
                                                   // segment (and the triangle)
        continue;

      ENumber t1 = (t1t2(0) - *data[i].intParams.begin()) * tScales[i];
      ENumber t2 = (t1t2(1) - *data[j].intParams.begin()) * tScales[j];
      // std::vector<std::pair<ENumber, ENumber>> result =
      // segment_segment_intersection(segments[i], segments[j]);

      // EXPENSIVE TEST
      EVector2 p1 = segments[i].source + segDirections[i] * t1;
      // EVector2 p2 = segments[j].source * (ENumber(1) - t2) +
      // segments[j].target * t2;

      // assert("Both segment intersection points should be the same! " &&
      // p1==p2);

      // if (result.empty())  //no intersection
      //     continue;  //that means the segments intersect away from the
      //     triangle.

      // for (int r=0;r<result.size();r++){
      arrVertices.push_back(p1);
      // std::cout<<"New arrangement vertex at
      // "<<arrVertices[arrVertices.size()-1]<<std::endl; std::cout<<"On
      // segments "<<segments[i].source<<"->"<<segments[i].target<<" and
      // "<<segments[j].source<<"->"<<segments[j].target<<std::endl;
      /*VS.push_back(std::vector<int>());
       VS[arrVertices.size() - 1].push_back(i);
       VS[arrVertices.size() - 1].push_back(j);*/
      SV[i].insert(std::pair<ENumber, int>(t1, arrVertices.size() - 1));
      SV[j].insert(std::pair<ENumber, int>(t2, arrVertices.size() - 1));

      //}
      /*if (result.size) {  //pointwise intersection
       // TODO: figure out what happens if more than two lines at the same spot
       arrVertices.push_back(segments[i].first * (1 - t1) + segments[i].second *
       t1); VS[arrVertices.size() - 1].push_back(i); VS[arrVertices.size() -
       1].push_back(j); SV[i].insert(std::pair<ENumber, int>(t1,
       arrVertices.size() - 1)); SV[j].insert(std::pair<ENumber, int>(t2,
       arrVertices.size() - 1));
       }

       //Should make this aware of the double and put both into the edge data
       if (result==2) {  //subsegment; now entering two vertices, and letting
       the edges be entered later arrVertices.push_back(segments[i].first *
       (ENumber(1) - t1) + segments[i].second * t1);
       arrVertices.push_back(segments[j].first * (ENumber(1) - t2) +
       segments[j].second * t2); VS[arrVertices.size() - 2].push_back(i);
       VS[arrVertices.size() - 1].push_back(j);
       VS[arrVertices.size() - 2].push_back(i);
       VS[arrVertices.size() - 1].push_back(j);
       SV[i].insert(std::pair<ENumber, int>(t1, arrVertices.size() - 2));
       SV[j].insert(std::pair<ENumber, int>(t1, arrVertices.size() - 1));
       SV[i].insert(std::pair<ENumber, int>(t2, arrVertices.size() - 2));
       SV[j].insert(std::pair<ENumber, int>(t2, arrVertices.size() - 1));
       }*/
    }
  }

  timings.intersections += arrangement_seconds_since(phaseStart);
  phaseStart = std::chrono::high_resolution_clock::now();

  // Creating the arrangement edges
  std::vector<std::pair<int, int>> arrEdges;
  std::vector<std::vector<SegmentData>> edgeData;
  for (int i = 0; i < SV.size(); i++) {
    // std::cout<<"Enumerating segment i"<<std::endl;
    for (std::set<std::pair<ENumber, int>>::iterator si = SV[i].begin();
         si != SV[i].end(); si++) {
      // std::cout<<si->first.to_double()<<",";
      std::set<std::pair<ENumber, int>>::iterator nextsi = si;
      nextsi++;
      if (nextsi != SV[i].end()) {
        arrEdges.push_back(std::pair<int, int>(si->second, nextsi->second));
        // std::cout<<"Creating an edge ("<<si->second<<",
        // "<<nextsi->second<<")"<<std::endl;
        std::vector<SegmentData> newEdgeData(1);
        newEdgeData[0] = data[i];
        edgeData.push_back(newEdgeData);
      }
    }
    // std::cout<<std::endl;
  }

  timings.edgeBuild += arrangement_seconds_since(phaseStart);
  phaseStart = std::chrono::high_resolution_clock::now();

  // unifying vertices with the same coordinates (necessary because some
  // segments may intersect at the same point and segment overlaps
  auto VertexCompare = [](const std::pair<EVector2, int> a,
                          const std::pair<EVector2, int> b) {
    return a.first < b.first;
  };
  std::set<std::pair<EVector2, int>,
           std::function<bool(const std::pair<EVector2, int>,
                              const std::pair<EVector2, int>)>>
      uniqueVertices(VertexCompare);
  std::vector<int> uniqueVertexMap(arrVertices.size());
  std::vector<EVector2> uniqueArrVertices;
  int uniqueCounter = 0;
  for (int i = 0; i < arrVertices.size(); i++) {
    std::pair<EVector2, int> searchElement(arrVertices[i], -1);
    std::set<std::pair<EVector2, int>, decltype(VertexCompare)>::iterator si =
        uniqueVertices.find(searchElement);
    if (si == uniqueVertices.end()) {
      uniqueVertexMap[i] = uniqueCounter;
      std::pair<EVector2, int> newElement =
          std::pair<EVector2, int>(arrVertices[i], uniqueCounter++);
      uniqueVertices.insert(newElement);
      uniqueArrVertices.push_back(arrVertices[i]);
    } else {
      uniqueVertexMap[i] = si->second;
    }
  }

  arrVertices = uniqueArrVertices;
  V = arrVertices;
  for (int i = 0; i < arrEdges.size(); i++)
    arrEdges[i] = std::pair<int, int>(uniqueVertexMap[arrEdges[i].first],
                                      uniqueVertexMap[arrEdges[i].second]);

  timings.vertexMerge += arrangement_seconds_since(phaseStart);
  phaseStart = std::chrono::high_resolution_clock::now();

  // std::cout<<"Edges after unifying vertices "<<std::endl;
  /*
// unifying edges with the same vertices (aggregating data) or degenerated
Eigen::VectorXi isDeadEdge = Eigen::VectorXi::Constant(arrEdges.size(), 0);
for (int i = 0; i < arrEdges.size(); i++) {
// std::cout<<"("<<arrEdges[i].first<<",
// "<<arrEdges[i].second<<")"<<std::endl;
if (arrEdges[i].first == arrEdges[i].second)
  isDeadEdge[i] = 1;
for (int j = i + 1; j < arrEdges.size(); j++) {
  if (((arrEdges[i].first == arrEdges[j].first) &&
       (arrEdges[i].second == arrEdges[j].second)) ||
      ((arrEdges[i].first == arrEdges[j].first) &&
       (arrEdges[i].second == arrEdges[j].second))) {
    isDeadEdge(j) = 1;
    edgeData[i].insert(edgeData[i].end(), edgeData[j].begin(),
                       edgeData[j].end());
  }
}
}
// cleaning dead edges
std::vector<std::pair<int, int>> newArrEdges;
std::vector<std::vector<SegmentData>> newEdgeData;
for (int i = 0; i < arrEdges.size(); i++) {
if (isDeadEdge[i])
  continue;
newArrEdges.push_back(arrEdges[i]);
newEdgeData.push_back(edgeData[i]);
}
arrEdges = newArrEdges;
edgeData = newEdgeData;
  */
  /*
   * Unify duplicate undirected edges in expected O(E).
   *
   * Canonical edge key:
   *
   *     min(v0,v1), max(v0,v1)
   *
   * Degenerate edges are discarded.
   */
  const auto directedEdgeKey = [](const int first,
                                  const int second) -> std::uint64_t {
    return (static_cast<std::uint64_t>(static_cast<std::uint32_t>(first))
            << 32U) |
           static_cast<std::uint64_t>(static_cast<std::uint32_t>(second));
  };

  std::unordered_map<std::uint64_t, int> uniqueEdgeIndex;

  uniqueEdgeIndex.reserve(arrEdges.size());
  uniqueEdgeIndex.max_load_factor(0.7f);

  std::vector<std::pair<int, int>> uniqueArrEdges;

  std::vector<std::vector<SegmentData>> uniqueEdgeData;

  uniqueArrEdges.reserve(arrEdges.size());
  uniqueEdgeData.reserve(edgeData.size());

  for (std::size_t edgeIndex = 0; edgeIndex < arrEdges.size(); ++edgeIndex) {
    const int first = arrEdges[edgeIndex].first;

    const int second = arrEdges[edgeIndex].second;

    /*
     * Discard zero-length topology after vertex unification.
     */
    if (first == second) {
      continue;
    }

    const std::uint64_t key = directedEdgeKey(first, second);

    const auto existing = uniqueEdgeIndex.find(key);

    if (existing == uniqueEdgeIndex.end()) {
      const int newIndex = static_cast<int>(uniqueArrEdges.size());

      uniqueEdgeIndex.emplace(key, newIndex);

      uniqueArrEdges.emplace_back(first, second);

      uniqueEdgeData.push_back(std::move(edgeData[edgeIndex]));

      continue;
    }

    /*
     * Merge metadata into the first edge using this undirected pair.
     */
    std::vector<SegmentData> &destination =
        uniqueEdgeData[static_cast<std::size_t>(existing->second)];

    std::vector<SegmentData> &source = edgeData[edgeIndex];

    destination.insert(destination.end(),
                       std::make_move_iterator(source.begin()),
                       std::make_move_iterator(source.end()));
  }

  arrEdges = std::move(uniqueArrEdges);
  edgeData = std::move(uniqueEdgeData);

  timings.edgeMerge += arrangement_seconds_since(phaseStart);
  phaseStart = std::chrono::high_resolution_clock::now();
  // Generating the DCEL
  triDcel.vertices.resize(arrVertices.size());
  triDcel.edges.resize(arrEdges.size());
  triDcel.halfedges.resize(2 * arrEdges.size());

  for (int i = 0; i < arrVertices.size(); i++) {
    triDcel.vertices[i].ID = i;
  }

  std::vector<EVector2> slopeVecs(arrEdges.size());
  for (int i = 0; i < arrEdges.size(); i++) {
    triDcel.edges[i].ID = i;

    triDcel.halfedges[2 * i].ID = 2 * i;
    triDcel.halfedges[2 * i + 1].ID = 2 * i + 1;

    // Consolidating the edge data
    triDcel.halfedges[2 * i].data.isFunction = false;
    triDcel.halfedges[2 * i + 1].data.isFunction = false;
    for (int j = 0; j < edgeData[i].size(); j++) {
      if (edgeData[i][j].isFunction) {
        triDcel.halfedges[2 * i].data.isFunction =
            triDcel.halfedges[2 * i + 1].data.isFunction = true;
        triDcel.halfedges[2 * i].data.origNFunctionIndex =
            triDcel.halfedges[2 * i + 1].data.origNFunctionIndex =
                edgeData[i][j].origNFunctionIndex;
      }
      if (edgeData[i][j].origHalfedge >= 0)
        triDcel.halfedges[2 * i].data.origHalfedge =
            triDcel.halfedges[2 * i + 1].data.origHalfedge =
                edgeData[i][j].origHalfedge;
    }

    triDcel.edges[i].halfedge = 2 * i;
    triDcel.halfedges[2 * i].vertex = arrEdges[i].first;
    triDcel.halfedges[2 * i + 1].vertex = arrEdges[i].second;
    triDcel.vertices[arrEdges[i].first].halfedge = 2 * i;
    triDcel.vertices[arrEdges[i].second].halfedge = 2 * i + 1;
    triDcel.halfedges[2 * i].edge = triDcel.halfedges[2 * i + 1].edge = i;
    triDcel.halfedges[2 * i].twin = 2 * i + 1;
    triDcel.halfedges[2 * i + 1].twin = 2 * i;
    // EVector2 edgeVec = arrVertices[arrEdges[i].second] -
    // arrVertices[arrEdges[i].first]; slopeVec[i] = slope_function(edgeVec);
  }

  timings.dcelBuild += arrangement_seconds_since(phaseStart);
  phaseStart = std::chrono::high_resolution_clock::now();

  /*
   * Build vertex-to-edge incidence once in O(E).
   *
   * bool:
   *   true  -> vertex is arrEdges[edge].first
   *   false -> vertex is arrEdges[edge].second
   */
  std::vector<std::vector<std::pair<int, bool>>> adjacentEdges(
      arrVertices.size());

  for (int edge = 0; edge < static_cast<int>(arrEdges.size()); ++edge) {
    const int first = arrEdges[edge].first;

    const int second = arrEdges[edge].second;

    if (first < 0 || first >= static_cast<int>(arrVertices.size()) ||
        second < 0 || second >= static_cast<int>(arrVertices.size())) {
      throw std::runtime_error(
          "segment_arrangement(): edge endpoint out of range");
    }

    adjacentEdges[static_cast<std::size_t>(first)].emplace_back(edge, true);

    adjacentEdges[static_cast<std::size_t>(second)].emplace_back(edge, false);
  }

  // Orienting segments around each vertex by CCW order
  double tolerance = 1e-7;
  for (int i = 0; i < static_cast<int>(arrVertices.size()); ++i) {
    const auto &adjArrEdges = adjacentEdges[static_cast<std::size_t>(i)];

    if (adjArrEdges.empty()) {
      /*
       * This should not normally occur, but do not dereference an empty
       * ordering container below.
       */
      continue;
    }

    /*std::cout<<"Orienting vertex "<<i<<std::endl;
     for (int k=0;k<adjArrEdges.size();k++)
     std::cout<<"Adjacent edge "<<adjArrEdges[k].first<<" with vertices
     "<<arrEdges[adjArrEdges[k].first].first<<","<<arrEdges[adjArrEdges[k].first].second<<std::endl;*/

    // doing the lazy thing first, since this is very unlikely to fail unless
    // parameterization is very degenerate
    std::vector<std::pair<double, int>> dCCWSegments;

    dCCWSegments.reserve(adjArrEdges.size());

    for (int j = 0; j < static_cast<int>(adjArrEdges.size()); ++j) {
      const int edge = adjArrEdges[j].first;

      Eigen::RowVector2d edgeVec =
          arrVertices[arrEdges[edge].second].to_double() -
          arrVertices[arrEdges[edge].first].to_double();

      if (!adjArrEdges[j].second) {
        edgeVec = -edgeVec;
      }

      dCCWSegments.emplace_back(slope_function_double(edgeVec), j);
    }

    std::sort(dCCWSegments.begin(), dCCWSegments.end(),
              [](const auto &left, const auto &right) {
                if (left.first != right.first) {
                  return left.first < right.first;
                }

                return left.second < right.second;
              });
    // if two slopes are too close together, we use exact numbers
    bool tooClose = false;

    for (std::size_t index = 1; index < dCCWSegments.size(); ++index) {
      if (std::abs(dCCWSegments[index - 1].first - dCCWSegments[index].first) <
          tolerance) {
        tooClose = true;
        break;
      }
    }

    if (!tooClose && dCCWSegments.size() > 1) {
      const double firstSlope = dCCWSegments.front().first;

      const double lastSlope = dCCWSegments.back().first;

      if (lastSlope < 7.0 + tolerance && lastSlope > 7.0 - tolerance &&
          firstSlope > -1.0 - tolerance && firstSlope < -1.0 + tolerance) {
        tooClose = true;
      }
    }

    std::vector<int> edgeOrder;
    edgeOrder.reserve(adjArrEdges.size());

    if (!tooClose) {
      for (const auto &entry : dCCWSegments) {
        edgeOrder.push_back(entry.second);
      }
    } else {
      // doing everything in exact numbers
      // std::cout<<"resorting to slope_function() in exact numbers"<<std::endl;
      std::vector<std::pair<ENumber, int>> exactCCWSegments;

      exactCCWSegments.reserve(adjArrEdges.size());

      for (int j = 0; j < static_cast<int>(adjArrEdges.size()); ++j) {
        const int edge = adjArrEdges[j].first;

        EVector2 edgeVec = arrVertices[arrEdges[edge].second] -
                           arrVertices[arrEdges[edge].first];

        if (!adjArrEdges[j].second) {
          edgeVec = -edgeVec;
        }

        exactCCWSegments.emplace_back(slope_function(edgeVec), j);
      }
      std::sort(exactCCWSegments.begin(), exactCCWSegments.end(),
                [](const auto &left, const auto &right) {
                  if (left.first < right.first) {
                    return true;
                  }

                  if (right.first < left.first) {
                    return false;
                  }

                  return left.second < right.second;
                });

      for (const auto &entry : exactCCWSegments) {
        edgeOrder.push_back(entry.second);
      }
    }

    // std::cout<<"Ordering of edges"<<std::endl;
    /*for (std::set<std::pair<ENumber, int>>::iterator si =
     CCWSegments.begin(); si!=CCWSegments.end();si++)
     std::cout<<si->second<<","; std::cout<<std::endl;*/

    int currHE = -1;
    for (int s = 0; s < edgeOrder.size(); s++) {
      bool outgoing = adjArrEdges[edgeOrder[s]].second;
      int outCurrHE =
          (outgoing
               ? triDcel.edges[adjArrEdges[edgeOrder[s]].first].halfedge
               : triDcel
                     .halfedges[triDcel.edges[adjArrEdges[edgeOrder[s]].first]
                                    .halfedge]
                     .twin);
      int nexts = (s + 1) % edgeOrder.size();
      // std::set<std::pair<ENumber, int>>::iterator nextsi = si; nextsi++;
      // if (nextsi==CCWSegments.end())
      //     nextsi = CCWSegments.begin();

      outgoing = adjArrEdges[edgeOrder[nexts]].second;
      int outNextHE =
          (outgoing
               ? triDcel.edges[adjArrEdges[edgeOrder[nexts]].first].halfedge
               : triDcel
                     .halfedges[triDcel
                                    .edges[adjArrEdges[edgeOrder[nexts]].first]
                                    .halfedge]
                     .twin);
      triDcel.halfedges[outCurrHE].prev = triDcel.halfedges[outNextHE].twin;
      triDcel.halfedges[triDcel.halfedges[outNextHE].twin].next = outCurrHE;

      // triDcel.halfedges[triDcel.halfedges[outCurrHE].twin].next=outNextHE;
      // triDcel.halfedges[outNextHE].prev = triDcel.halfedges[outCurrHE].twin;
    }
  }

  timings.radialSort += arrangement_seconds_since(phaseStart);
  phaseStart = std::chrono::high_resolution_clock::now();

  // generating faces (at this stage, there is also an outer face)
  int currFace = 0;
  for (int i = 0; i < triDcel.halfedges.size(); i++) {
    if (triDcel.halfedges[i].face != -1)
      continue; // already been assigned

    FunctionDCEL::Face newFace;
    newFace.ID = currFace++;

    int beginHE = i;
    newFace.halfedge = beginHE;
    int currHE = beginHE;
    int counter = 0;
    do {
      // std::cout<<currHE<<",";
      triDcel.halfedges[currHE].face = newFace.ID;
      currHE = triDcel.halfedges[currHE].next;
      counter++;
      if (counter >= static_cast<int>(triDcel.halfedges.size()) + 1) {
        throw std::runtime_error("segment_arrangement(): "
                                 "face traversal did not close");
      }
    } while (currHE != beginHE);
    // std::cout<<std::endl;
    triDcel.faces.push_back(newFace);
  }
  int numFaces = currFace;

  constexpr bool checkLocalPureBoundaryFaces = false;

  if (!triDcel.check_consistency(mData.verbose, true, true,
                                 checkLocalPureBoundaryFaces)) {
    throw std::runtime_error(
        "segment_arrangement(): "
        "local DCEL is inconsistent before outer-face removal");
  }

  timings.faceBuild += arrangement_seconds_since(phaseStart);
  phaseStart = std::chrono::high_resolution_clock::now();

  // Removing the outer face and deleting all associated halfedges
  // identifying it by the only polygon with negative signed area (expensive?)
  int outerFace = -1;
  double minSfa = 32767.0;
  for (int f = 0; f < numFaces; ++f) {
    if (!triDcel.faces[f].valid) {
      continue;
    }

    std::vector<EVector2> faceVectors;

    const int beginHE = triDcel.faces[f].halfedge;

    if (!triDcel.valid_halfedge(beginHE)) {
      throw std::runtime_error("segment_arrangement(): "
                               "face has invalid representative halfedge");
    }

    int currHE = beginHE;
    bool closed = false;

    for (int step = 0; step < static_cast<int>(triDcel.halfedges.size());
         ++step) {
      if (!triDcel.valid_halfedge(currHE)) {
        throw std::runtime_error("segment_arrangement(): "
                                 "invalid halfedge during outer-face scan");
      }

      const int next = triDcel.halfedges[currHE].next;

      if (!triDcel.valid_halfedge(next)) {
        throw std::runtime_error(
            "segment_arrangement(): "
            "invalid next halfedge during outer-face scan");
      }

      faceVectors.push_back(V[triDcel.halfedges[next].vertex] -
                            V[triDcel.halfedges[currHE].vertex]);

      currHE = next;

      if (currHE == beginHE) {
        closed = true;
        break;
      }
    }

    if (!closed) {
      throw std::runtime_error(
          "segment_arrangement(): "
          "face traversal did not close during outer-face scan");
    }

    const double sfa = signed_face_area(faceVectors);

    if (sfa < minSfa) {
      minSfa = sfa;
    }

    if (sfa < -100.0 * tolerance) {
      outerFace = f;
      break;
    }
  }
  if (outerFace < 0) {
    throw std::runtime_error(
        "segment_arrangement(): failed to identify outer face");
  }

  // invalidating outer face
  triDcel.faces[outerFace].valid = false;
  triDcel.faces[outerFace].halfedge = -1;

  for (int i = 0; i < static_cast<int>(triDcel.halfedges.size()); ++i) {
    auto &halfedge = triDcel.halfedges[i];

    if (!halfedge.valid || halfedge.face != outerFace) {
      continue;
    }

    const int twin = halfedge.twin;
    const int edge = halfedge.edge;
    const int vertex = halfedge.vertex;

    if (twin >= 0) {
      if (!triDcel.valid_halfedge(twin)) {
        throw std::runtime_error("segment_arrangement(): "
                                 "outer-face halfedge has invalid twin");
      }

      triDcel.halfedges[twin].twin = -1;

      if (triDcel.valid_edge(edge)) {
        triDcel.edges[edge].halfedge = twin;
      }

      if (triDcel.valid_vertex(vertex)) {
        const int twinNext = triDcel.halfedges[twin].next;

        if (!triDcel.valid_halfedge(twinNext)) {
          throw std::runtime_error("segment_arrangement(): "
                                   "surviving twin has invalid next");
        }

        triDcel.vertices[vertex].halfedge = twinNext;
      }
    } else {
      if (triDcel.valid_edge(edge)) {
        triDcel.edges[edge].valid = false;
        triDcel.edges[edge].halfedge = -1;
      }

      if (triDcel.valid_vertex(vertex) &&
          triDcel.vertices[vertex].halfedge == i) {
        triDcel.vertices[vertex].halfedge = -1;
      }
    }

    halfedge.twin = -1;
    halfedge.valid = false;
  }

  // removing dead edges
  if (!triDcel.clean_mesh(mData.verbose, false)) {
    throw std::runtime_error(
        "segment_arrangement(): local DCEL cleanup failed");
  }

  if (!triDcel.check_consistency(mData.verbose, true, true, false)) {
    throw std::runtime_error("segment_arrangement(): "
                             "local DCEL is inconsistent after cleanup");
  }

  timings.outerFace += arrangement_seconds_since(phaseStart);
}

// The top mesh generation function
void NFunctionMesher::generate_mesh(const unsigned long resolution = 1e7) {

  using namespace std;
  using namespace Eigen;

  reset_arrangement_timings();

  const auto generationStart = std::chrono::high_resolution_clock::now();
  auto intervalStart = generationStart;

  const std::vector<EVector2> canonicalTriangle2D = {
      EVector2({ENumber(0), ENumber(0)}), EVector2({ENumber(1), ENumber(0)}),
      EVector2({ENumber(0), ENumber(1)})};

  const EVector2 canonicalE01({ENumber(1), ENumber(0)});
  const EVector2 canonicalE12({ENumber(-1), ENumber(1)});
  const EVector2 canonicalE20({ENumber(0), ENumber(-1)});

  const double coordinateTolerance = 1.0 / static_cast<double>(resolution);
  reset_line_clipping_timings();
  for (int findex = 0; findex < origMesh.F.rows(); ++findex) {
    const char *triangleStage = "triangle initialization";
    try {
      auto trianglePhaseStart = std::chrono::high_resolution_clock::now();

      if (mData.verbose && findex > 0 && (findex % 1000 == 0)) {
        const double intervalSeconds = arrangement_seconds_since(intervalStart);

        std::cout
            << "[Directional::NFunctionMesher::generate_mesh()]: Triangle "
            << findex
            << " completed; previous 1000 triangles: " << intervalSeconds
            << " seconds\n";

        print_arrangement_timings(arrangement_timings_accumulator());
        intervalStart = std::chrono::high_resolution_clock::now();
      }

      const std::vector<ENumber> &triExactNFunction = exactNFunction[findex];

      std::vector<ENumber> minFuncs(mData.N);
      std::vector<ENumber> maxFuncs(mData.N);

      for (int function = 0; function < mData.N; ++function) {
        minFuncs[function] = ENumber(327600);
        maxFuncs[function] = ENumber(-327600);
      }

      for (int corner = 0; corner < 3; ++corner) {
        for (int function = 0; function < mData.N; ++function) {
          const ENumber &value = triExactNFunction[mData.N * corner + function];

          if (value > maxFuncs[function]) {
            maxFuncs[function] = value;
          }

          if (value < minFuncs[function]) {
            minFuncs[function] = value;
          }
        }
      }

      std::array<EVector3, 3> trianglePoints3D;

      for (int corner = 0; corner < 3; ++corner) {
        const RowVector3d position = origMesh.V.row(origMesh.F(findex, corner));

        trianglePoints3D[corner] =
            EVector3({ENumber(position(0), coordinateTolerance),
                      ENumber(position(1), coordinateTolerance),
                      ENumber(position(2), coordinateTolerance)});
      }

      std::vector<std::pair<int, bool>> triangleData(3);
      int currentHalfedge = origMesh.dcel.faces[findex].halfedge;

      for (int corner = 0; corner < 3; ++corner) {
        const int twin = origMesh.dcel.halfedges[currentHalfedge].twin;

        triangleData[corner].first =
            twin < 0 || twin > currentHalfedge ? currentHalfedge : twin;

        triangleData[corner].second = twin < 0;
        currentHalfedge = origMesh.dcel.halfedges[currentHalfedge].next;
      }
      const auto linePencilStart = std::chrono::high_resolution_clock::now();
      std::vector<LinePencil> linePencils;
      std::vector<int> linePencilData;
      linePencils.reserve(mData.N);
      linePencilData.reserve(mData.N);

      for (int function = 0; function < mData.N; ++function) {
        EInt quotient;
        EInt remainder;

        div_mod(enumber_num(minFuncs[function]),
                enumber_den(minFuncs[function]), quotient, remainder);

        const EInt minIsoValue =
            quotient +
            (enumber_num(minFuncs[function]) < EInt(0) ? EInt(-1) : EInt(0));

        div_mod(enumber_num(maxFuncs[function]),
                enumber_den(maxFuncs[function]), quotient, remainder);

        const EInt maxIsoValue =
            quotient +
            (enumber_num(maxFuncs[function]) < EInt(0) ? EInt(0) : EInt(1));

        const EInt isoCountExact = maxIsoValue - minIsoValue + EInt(1);

        const long long isoCount = isoCountExact.convert();

        if (isoCount <= 0) {
          continue;
        }

        if (isoCount >
            static_cast<long long>(std::numeric_limits<int>::max())) {
          throw std::overflow_error(
              "generate_mesh(): iso-line count exceeds int range");
        }

        const EVector2 gradVector =
            triExactNFunction[2 * mData.N + function] *
                EVector2({-canonicalE01[1], canonicalE01[0]}) +
            triExactNFunction[0 * mData.N + function] *
                EVector2({-canonicalE12[1], canonicalE12[0]}) +
            triExactNFunction[1 * mData.N + function] *
                EVector2({-canonicalE20[1], canonicalE20[0]});

        const ENumber &a = triExactNFunction[0 * mData.N + function];
        const ENumber &b = triExactNFunction[1 * mData.N + function];
        const ENumber &c = triExactNFunction[2 * mData.N + function];

        if (a == b && b == c) {
          continue;
        }

        ENumber rhs[3];
        rhs[0] = ENumber(0);
        rhs[1] = -gradVector[0];
        rhs[2] = -gradVector[1];

        ENumber inverseMatrix[2][3];
        inverseMatrix[0][0] = ENumber(2) * a - b - c;
        inverseMatrix[0][1] = ENumber(2) * b - a - c;
        inverseMatrix[0][2] = ENumber(2) * c - b - a;
        inverseMatrix[1][0] = b * b - a * b + c * c - a * c;
        inverseMatrix[1][1] = a * a - b * a + c * c - b * c;
        inverseMatrix[1][2] = a * a - c * a + b * b - c * b;

        const ENumber denominator =
            ENumber(2) * (a * a - a * b - a * c + b * b - b * c + c * c);

        if (denominator == ENumber(0)) {
          continue;
        }

        const ENumber inverseDenominator = ENumber(1) / denominator;

        for (int row = 0; row < 2; ++row) {
          for (int column = 0; column < 3; ++column) {
            inverseMatrix[row][column] =
                inverseMatrix[row][column] * inverseDenominator;
          }
        }

        ENumber solution[2];
        solution[0] = inverseMatrix[0][0] * rhs[0] +
                      inverseMatrix[0][1] * rhs[1] +
                      inverseMatrix[0][2] * rhs[2];
        solution[1] = inverseMatrix[1][0] * rhs[0] +
                      inverseMatrix[1][1] * rhs[1] +
                      inverseMatrix[1][2] * rhs[2];

        LinePencil linePencil;
        linePencil.direction[0] = -gradVector[1];
        linePencil.direction[1] = gradVector[0];

        if (gradVector[1] != ENumber(0)) {
          linePencil.p0[0] = ENumber(0);
          linePencil.p0[1] =
              -(solution[0] * minIsoValue + solution[1]) / gradVector[1];
          linePencil.pVec[0] = ENumber(0);
          linePencil.pVec[1] = -solution[0] / gradVector[1];
        } else {
          if (gradVector[0] == ENumber(0)) {
            continue;
          }

          linePencil.p0[1] = ENumber(0);
          linePencil.p0[0] =
              -(solution[0] * minIsoValue + solution[1]) / gradVector[0];
          linePencil.pVec[1] = ENumber(0);
          linePencil.pVec[0] = -solution[0] / gradVector[0];
        }

        linePencil.numLines = static_cast<int>(isoCount);
        linePencils.push_back(std::move(linePencil));
        linePencilData.push_back(function);
      }

      FunctionDCEL localArrangement;
      std::vector<EVector2> localVertices2D;

      arrangement_timings_accumulator().linePencilBuild +=
          arrangement_seconds_since(trianglePhaseStart);

      triangleStage = "triangle arrangement";

      arrange_on_triangle(canonicalTriangle2D, triangleData, linePencils,
                          linePencilData, localVertices2D, localArrangement);

      trianglePhaseStart = std::chrono::high_resolution_clock::now();

      if (localArrangement.vertices.size() != localVertices2D.size()) {
        throw std::runtime_error(
            "generate_mesh(): local vertex/DCEL size mismatch");
      }
      triangleStage = "3D projection";
      for (std::size_t vertexIndex = 0; vertexIndex < localVertices2D.size();
           ++vertexIndex) {
        const ENumber &u = localVertices2D[vertexIndex][0];
        const ENumber &v = localVertices2D[vertexIndex][1];
        const ENumber w0 = ENumber(1) - u - v;

        const EVector3 point3D = trianglePoints3D[0] * w0 +
                                 trianglePoints3D[1] * u +
                                 trianglePoints3D[2] * v;

        auto &vertex = localArrangement.vertices[vertexIndex];
        vertex.data.eCoords = point3D;
        vertex.data.coords << point3D[0].to_double(), point3D[1].to_double(),
            point3D[2].to_double();
      }

      arrangement_timings_accumulator().project3D +=
          arrangement_seconds_since(trianglePhaseStart);
      trianglePhaseStart = std::chrono::high_resolution_clock::now();

      /*
       * Approximate global arrangement capacity.
       *
       * The values are estimates, not correctness requirements. The vectors
       * will still grow geometrically if the estimates are exceeded.
       */
      const std::size_t triangleCount =
          static_cast<std::size_t>(origMesh.F.rows());

      genDcel.vertices.reserve(std::max(genDcel.vertices.capacity(),
                                        triangleCount * std::size_t{8}));

      genDcel.halfedges.reserve(std::max(genDcel.halfedges.capacity(),
                                         triangleCount * std::size_t{16}));

      genDcel.edges.reserve(
          std::max(genDcel.edges.capacity(), triangleCount * std::size_t{8}));

      genDcel.faces.reserve(
          std::max(genDcel.faces.capacity(), triangleCount * std::size_t{4}));

      if (!genDcel.aggregate_dcel(localArrangement, mData.verbose, false)) {
        throw std::runtime_error("Failed to aggregate DCEL");
      }

      arrangement_timings_accumulator().aggregate +=
          arrangement_seconds_since(trianglePhaseStart);
    } catch (const std::exception &error) {
      std::cerr << "[Directional::NFunctionMesher::generate_mesh()]: "
                << "triangle " << findex << " failed during " << triangleStage
                << ": " << error.what() << '\n';

      throw;
    } catch (...) {
      std::cerr << "[Directional::NFunctionMesher::generate_mesh()]: "
                << "triangle " << findex << " failed during " << triangleStage
                << " with an unknown exception\n";

      throw;
    }
  }

  if (!genDcel.check_consistency(mData.verbose, false, false, false)) {
    throw std::runtime_error(
        "NFunctionMesher::generate_mesh(): generated DCEL is inconsistent");
  }

  if (mData.verbose) {
    const double totalSeconds = arrangement_seconds_since(generationStart);

    std::cout << "[Directional::NFunctionMesher::generate_mesh()]: completed "
              << origMesh.F.rows() << " triangles in " << totalSeconds
              << " seconds\n";

    print_arrangement_timings(arrangement_timings_accumulator());
    print_line_clipping_timings(line_clipping_timings_accumulator());
    print_linepencil_triangle_timings(linepencil_triangle_timings_accumulator());
  }
}

} // namespace directional

#endif
