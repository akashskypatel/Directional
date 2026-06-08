// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_EXACT_GEOMETRIC_DEFINITIONS_H
#define DIRECTIONAL_EXACT_GEOMETRIC_DEFINITIONS_H

#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <algorithm>
#include <cassert>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <iostream>
#include <limits>
#include <math.h>
#include <queue>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#ifdef USE_GMP_ENABLED
#include <directional/ENumber_GMP.h>
#else
#include <directional/ENumber_internal.h>
#endif

// This header file concentrates geometric operations on vectors, segments,
// lines, and arrangement in exact rational numbers.
namespace directional {

#ifndef DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
#define DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING 1
#endif


template <size_t Size> class EVector {
public:
  EVector() : data(Size) {}

  // Other methods can be added as needed
  const ENumber &operator[](const size_t index) const { return data[index]; }

  ENumber &operator[](const size_t index) { return data[index]; }

  EVector<Size> operator+(const EVector<Size> &ev) const {
    EVector<Size> newVec;
    for (int i = 0; i < Size; i++)
      newVec.data[i] = data[i] + ev.data[i];

    return newVec;
  }
  EVector<Size> operator-() const {
    EVector<Size> newVec;
    for (int i = 0; i < Size; i++)
      newVec.data[i] = -data[i];

    return newVec;
  }
  EVector<Size> operator-(const EVector<Size> &ev) const {
    EVector<Size> newVec;
    for (int i = 0; i < Size; i++)
      newVec.data[i] = data[i] - ev.data[i];

    return newVec;
  }

  EVector<Size> operator*(const ENumber &s) const {
    EVector<Size> newVec;
    for (int i = 0; i < Size; i++)
      newVec.data[i] = data[i] * s;

    return newVec;
  }

  bool operator==(const EVector<Size> &ev) const {
    bool equal = true;
    for (int i = 0; i < Size; i++)
      equal = equal & (ev.data[i] == data[i]);
    return equal;
  }

  // for the sake of sorting
  bool operator<(const EVector<Size> &ev) const {
    for (int i = 0; i < Size; i++)
      if (data[i] != ev.data[i])
        return data[i] < ev.data[i];
    return false;
  }

  EVector(const std::initializer_list<ENumber> &args) {
    data.insert(data.end(), args.begin(), args.end());
  }

  EVector &operator=(const EVector<Size> &evec) = default;

  Eigen::RowVectorXd to_double() const {
    Eigen::RowVectorXd doubleVec(Size);
    for (int i = 0; i < Size; i++)
      doubleVec(i) = data[i].to_double();
    return doubleVec;
  }

  ENumber cross(const EVector<Size> &evec) const {
    static_assert("This method only works for Size==2" && Size == 2);
    return data[0] * evec.data[1] - data[1] * evec.data[0];
  }

  ENumber max_abs() const {
    ENumber maxAbs(-1);
    for (int i = 0; i < Size; i++)
      if (data[i].abs() > maxAbs)
        maxAbs = data[i].abs();
    return maxAbs;
  }

  ENumber operator*(const EVector<Size> &evec) const {
    ENumber dotProd(0);
    for (int i = 0; i < Size; i++)
      dotProd += data[i] * evec.data[i];
    return dotProd;
  }

  template <size_t _Size>
  friend std::ostream &operator<<(std::ostream &os, const EVector<_Size> &evec);

  /*void canonicalize(){
   for (int i=0;i<Size;i++)
   data[i].canonicalize();
   }*/

  // protected:
  std::vector<ENumber> data;
};

template <size_t Size>
EVector<Size> operator*(ENumber scalar, const EVector<Size> &vec) {
  return vec * scalar; // Leverage the previous operator*
}

template <size_t Size>
std::ostream &operator<<(std::ostream &os, const EVector<Size> &evec) {
  os << "(";
  for (int i = 0; i < Size - 1; i++)
    os << evec[i].to_double() << ",";
  os << evec[Size - 1].to_double() << ")";
  return os;
}

typedef EVector<2> EVector2;
typedef EVector<3> EVector3;

struct Segment2 {
public:
  EVector2 source, target;
  Segment2(const EVector2 &_source, const EVector2 &_target) {
    source = _source;
    target = _target;
  }

  Segment2 &operator=(const Segment2 &seg2) = default;

  Segment2() {}

  friend std::ostream &operator<<(std::ostream &os, const Segment2 &seg);
};

inline std::ostream &operator<<(std::ostream &os, const Segment2 &seg) {
  os << "Segment2(" << seg.source << "->" << seg.target << ")";
  return os;
}

struct Line2 {
public:
  EVector2 point, direction;
  Line2(const EVector2 &_point, const EVector2 &_direction) {
    point = _point;
    direction = _direction;
  }

  friend std::ostream &operator<<(std::ostream &os, const Line2 &seg);

  ENumber point_param(const EVector2 &p)
      const { // if the point is not on the line, this is the parameter of the
              // orthogonally-projected point
    return (direction * (p - point)) / (direction * direction);
  }
};

inline std::ostream &operator<<(std::ostream &os, const Line2 &line) {
  os << "Line2(" << line.point << " + " << line.direction << ")";
  return os;
}

struct LinePencil {
  int numLines;
  EVector2 direction; // the mutual direction along the line
  EVector2 p0, pVec;  // p0 is the origin of the first line. pVec is the vector
                      // between the origins of the lines (p0(I+1)-p0(I) = pvec)

  inline Line2 line(const int lineNum) const {
    return Line2(p0 + pVec * ENumber(lineNum), direction);
  }
};

inline ENumber squaredDistance(const EVector3 &v1, const EVector3 &v2) {
  ENumber sd(0);
  // assert("vectors are of different dimensions!" && v1.size()==v2.size());
  for (int i = 0; i < 3; i++)
    sd += (v1[i] - v2[i]) * (v1[i] - v2[i]); // maybe it's not efficient

  return sd;
}

// produces y = M*x
inline void exactSparseMult(const Eigen::SparseMatrix<int> &M,
                     const std::vector<ENumber> &x, std::vector<ENumber> &y) {
  y.resize(M.rows());

  for (int i = 0; i < y.size(); i++)
    y[i] = ENumber(0);

  for (int k = 0; k < M.outerSize(); ++k)
    for (Eigen::SparseMatrix<int>::InnerIterator it(M, k); it; ++it) {
      /*if (it.row()==219){
       std::cout<<"it.value(): "<<it.value()<<std::endl;
       std::cout<<"x[it.col()]: "<<x[it.col()].to_double()<<std::endl;
       std::cout<<"ENumber((long)it.value())*x[it.col()]:
       "<<(ENumber((long)it.value())*x[it.col()]).to_double()<<std::endl;
       std::cout<<"y[it.row()]: "<<y[it.row()].to_double()<<std::endl;
       }*/
      y[it.row()] += ENumber((long)it.value()) * x[it.col()];
    }
}

inline void exactDenseMult(const Eigen::MatrixXi &nM, const Eigen::MatrixXi &dM,
                    const std::vector<ENumber> &x, std::vector<ENumber> &y) {
  y.resize(nM.rows());
  for (int i = 0; i < y.size(); i++)
    y[i] = ENumber(0);
  for (int i = 0; i < nM.rows(); i++)
    for (int j = 0; j < nM.cols(); j++)
      y[i] += x[j] * ENumber(nM(i, j), dM(i, j));
}

// This assumes components is already resized to the correct |v|
// not very efficient but probably not terrible
inline int connectedComponents(const std::vector<std::pair<int, int>> &matches,
                        std::vector<int> &components) {
  for (int i = 0; i < components.size(); i++)
    components[i] = -1;

  std::vector<std::vector<int>> VV(components.size());
  for (int i = 0; i < matches.size(); i++) {
    VV[matches[i].first].push_back(matches[i].second);
    VV[matches[i].second].push_back(matches[i].first);
  }

  std::deque<int> nextVertexQueue;
  for (int i = 0; i < components.size(); i++)
    nextVertexQueue.push_front(i);

  int numComponents = 0;
  while (!nextVertexQueue.empty()) {
    int nextVertex = nextVertexQueue.front();
    nextVertexQueue.pop_front();
    if (components[nextVertex] == -1) { // first components
      // std::cout << "New component " << numComponents << " seed vertex " <<
      // nextVertex << std::endl;
      components[nextVertex] = numComponents++;
    }

    // Otherwise, doing DFS on edges
    for (int i = 0; i < VV[nextVertex].size(); i++) {
      if (components[VV[nextVertex][i]] == -1) {
        components[VV[nextVertex][i]] = components[nextVertex];
        // std::cout<<"adding vertex "<<VV[nextVertex][i]<<" to component
        // "<<components[nextVertex]<<std::endl;
        nextVertexQueue.push_front(VV[nextVertex][i]);
      } else
        assert(components[VV[nextVertex][i]] == components[nextVertex]);
    }
  }
  return numComponents;
}

inline int line_line_intersection(const Line2 &line1, const Line2 &line2, ENumber &t1,
                           ENumber &t2) {
  // std::cout<<"Computing intersection between line: "<<line1<<" and line
  // "<<line2<<std::endl;
  ENumber v1v2 = line1.direction.cross(line2.direction);
  if (v1v2 == ENumber(0)) {
    EVector2 pointVec = line1.point - line2.point;
    // std::cout<<"lines are parallel"<<std::endl;
    return (pointVec.cross(line1.direction) == ENumber(0) ? 2 : 0);
  }

  // std::cout<<"exact line2.point[0]-line1.point[0]:
  // "<<(line2.point[0]-line1.point[0]).to_double()<<std::endl;
  // std::cout<<"double line2.point[0]-line1.point[0]:
  // "<<(line2.point[0].to_double()-line1.point[0].to_double())<<std::endl;

  // std::cout<<"exact (line2.point[0]-line1.point[0])*(line2.direction[1]):
  // "<<((line2.point[0]-line1.point[0])*(line2.direction[1])).to_double()<<std::endl;
  // std::cout<<"double (line2.point[0]-line1.point[0])*(line2.direction[1]):
  // "<<(line2.point[0].to_double()-line1.point[0].to_double())*(line2.direction[1].to_double())<<std::endl;
  EVector2 p12 = line2.point - line1.point;
  t1 = p12.cross(line2.direction) / v1v2;
  t2 = p12.cross(line1.direction) / v1v2;
  // std::cout<<"t1, t2: "<<t1.to_double()<<","<<t2.to_double()<<std::endl;
  // std::cout<<"line1.point+t1*line1.direction:
  // "<<line1.point+t1*line1.direction<<std::endl;
  // std::cout<<"line2.point+t2*line2.direction:
  // "<<line2.point+t2*line2.direction<<std::endl; EVector2 diff =
  // (line1.point+t1*line1.direction) - (line2.point+t2*line2.direction);
  // diff.canonicalize();
  // assert("line_line_intersection is wrong!" && diff == EVector2());
  // std::cout<<"lines intersect at
  // "<<(line1.point+t1*line1.direction)<<std::endl; std::cout<<"parameters:
  // t1:"<<t1.get_d()<<", t2: "<<t2.get_d()<<std::endl;
  return 1;
}

// returns a generator for the grid of intersections, parameterized by p00 +
// pVec1*isoValue1 + pVec2*isoValue2, txp00 is the t(1 or 2) of the p00 point in
// each respective line dtx (1 or 2) is the dt going along each pVecx (1 or 2)
// for iso1 and iso2 in the respective line pencil ranges
// result = 2 is only acceptable if |lp2| = 1, not handling parallel full line
// pencils (shouldn't be unless the parameterization is degenerate).
struct LinePencilIntersectionTimings {
  std::size_t genericCalls = 0;
  std::size_t singleLineCalls = 0;
  std::size_t parallelCases = 0;
  std::size_t overlapCases = 0;
  std::size_t nonParallelCases = 0;

  double determinant = 0.0;
  double parallelClassification = 0.0;
  double baseParameters = 0.0;
  double stepParameters = 0.0;
  double outputWrite = 0.0;
  double total = 0.0;
};

inline LinePencilIntersectionTimings &
linepencil_intersection_timings_accumulator() {
  static LinePencilIntersectionTimings timings;
  return timings;
}

inline void reset_linepencil_intersection_timings() {
  linepencil_intersection_timings_accumulator() =
      LinePencilIntersectionTimings{};
}

inline double exact_geometry_seconds_since(
    const std::chrono::high_resolution_clock::time_point &start) {
  return std::chrono::duration<double>(
             std::chrono::high_resolution_clock::now() - start)
      .count();
}

inline void print_linepencil_intersection_timings(
    const LinePencilIntersectionTimings &timings) {
  std::cout
      << "[Directional::linepencil_intersection()]: timing summary\n"
      << "  generic calls:          " << timings.genericCalls << '\n'
      << "  single-line calls:      " << timings.singleLineCalls << '\n'
      << "  parallel cases:         " << timings.parallelCases << '\n'
      << "  overlap cases:          " << timings.overlapCases << '\n'
      << "  non-parallel cases:     " << timings.nonParallelCases << '\n'
      << "  determinant:            " << timings.determinant << " s\n"
      << "  parallel classification:" << timings.parallelClassification
      << " s\n"
      << "  base parameters:        " << timings.baseParameters << " s\n"
      << "  step parameters:        " << timings.stepParameters << " s\n"
      << "  output write:           " << timings.outputWrite << " s\n"
      << "  total:                  " << timings.total << " s\n";
}

/*
 * Scalar implementation of line-pencil intersection.
 *
 * Compared with the former Eigen-expression implementation, this version:
 * - computes the determinant once;
 * - computes one reciprocal and multiplies by it, avoiding six divisions;
 * - avoids temporary EVector/Eigen expressions in the hot path;
 * - uses runtime validation instead of release-disabled assertions.
 */
inline int linepencil_intersection(
    const LinePencil &lp1, const LinePencil &lp2,
    Eigen::Matrix<ENumber, 2, 1> &t00,
    Eigen::Matrix<ENumber, 2, 2> &I2dt,
    EInt &iso1Overlap) {
  using Clock = std::chrono::high_resolution_clock;

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  LinePencilIntersectionTimings &timings =
      linepencil_intersection_timings_accumulator();
  ++timings.genericCalls;
  const auto totalStart = Clock::now();
  auto phaseStart = totalStart;
#endif

  const ENumber determinant =
      lp1.direction[0] * lp2.direction[1] -
      lp1.direction[1] * lp2.direction[0];

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  timings.determinant += exact_geometry_seconds_since(phaseStart);
#endif

  if (determinant == ENumber(0)) {
#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
    ++timings.parallelCases;
    phaseStart = Clock::now();
#endif

    if (lp2.numLines != 1) {
      throw std::invalid_argument(
          "linepencil_intersection(): parallel second pencil must contain "
          "exactly one line");
    }

    const ENumber deltaX = lp2.p0[0] - lp1.p0[0];
    const ENumber deltaY = lp2.p0[1] - lp1.p0[1];
    const ENumber spacingCrossDirection =
        lp1.pVec[0] * lp1.direction[1] -
        lp1.pVec[1] * lp1.direction[0];

    if (spacingCrossDirection == ENumber(0)) {
      throw std::runtime_error(
          "linepencil_intersection(): degenerate first-pencil spacing");
    }

    const ENumber overlapIso =
        (deltaX * lp1.direction[1] -
         deltaY * lp1.direction[0]) /
        spacingCrossDirection;

    int result = 0;
    if (enumber_den(overlapIso) == EInt(1)) {
      iso1Overlap = enumber_num(overlapIso);
      const long long overlapIndex = iso1Overlap.convert();
      if (overlapIndex >= 0 &&
          overlapIndex < static_cast<long long>(lp1.numLines)) {
        result = 2;
#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
        ++timings.overlapCases;
#endif
      }
    }

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
    timings.parallelClassification +=
        exact_geometry_seconds_since(phaseStart);
    timings.total += exact_geometry_seconds_since(totalStart);
#endif
    return result;
  }

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  ++timings.nonParallelCases;
  phaseStart = Clock::now();
#endif

  const ENumber inverseDeterminant = ENumber(1) / determinant;
  const ENumber deltaX = lp2.p0[0] - lp1.p0[0];
  const ENumber deltaY = lp2.p0[1] - lp1.p0[1];

  const ENumber t00First =
      (deltaX * lp2.direction[1] -
       deltaY * lp2.direction[0]) *
      inverseDeterminant;

  const ENumber t00Second =
      (deltaX * lp1.direction[1] -
       deltaY * lp1.direction[0]) *
      inverseDeterminant;

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  timings.baseParameters += exact_geometry_seconds_since(phaseStart);
  phaseStart = Clock::now();
#endif

  const ENumber step00 =
      -(lp1.pVec[0] * lp2.direction[1] -
        lp1.pVec[1] * lp2.direction[0]) *
      inverseDeterminant;

  const ENumber step01 =
      (lp2.pVec[0] * lp2.direction[1] -
       lp2.pVec[1] * lp2.direction[0]) *
      inverseDeterminant;

  const ENumber step10 =
      -(lp1.pVec[0] * lp1.direction[1] -
        lp1.pVec[1] * lp1.direction[0]) *
      inverseDeterminant;

  const ENumber step11 =
      (lp2.pVec[0] * lp1.direction[1] -
       lp2.pVec[1] * lp1.direction[0]) *
      inverseDeterminant;

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  timings.stepParameters += exact_geometry_seconds_since(phaseStart);
  phaseStart = Clock::now();
#endif

  t00(0) = t00First;
  t00(1) = t00Second;
  I2dt(0, 0) = step00;
  I2dt(0, 1) = step01;
  I2dt(1, 0) = step10;
  I2dt(1, 1) = step11;

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  timings.outputWrite += exact_geometry_seconds_since(phaseStart);
  timings.total += exact_geometry_seconds_since(totalStart);
#endif

  return 1;
}

/*
 * Specialized hot-path intersection between a line pencil and one line.
 * Only the first affine column is needed by triangle clipping, so this avoids
 * constructing a temporary LinePencil and avoids computing two unused values.
 */
inline int linepencil_single_line_intersection(
    const LinePencil &pencil,
    const EVector2 &linePoint,
    const EVector2 &lineDirection,
    ENumber &lineParameter0,
    ENumber &edgeParameter0,
    ENumber &lineParameterStep,
    ENumber &edgeParameterStep,
    EInt &overlapLine) {
  using Clock = std::chrono::high_resolution_clock;

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  LinePencilIntersectionTimings &timings =
      linepencil_intersection_timings_accumulator();
  ++timings.singleLineCalls;
  const auto totalStart = Clock::now();
  auto phaseStart = totalStart;
#endif

  const ENumber determinant =
      pencil.direction[0] * lineDirection[1] -
      pencil.direction[1] * lineDirection[0];

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  timings.determinant += exact_geometry_seconds_since(phaseStart);
#endif

  if (determinant == ENumber(0)) {
#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
    ++timings.parallelCases;
    phaseStart = Clock::now();
#endif

    const ENumber spacingCrossDirection =
        pencil.pVec[0] * pencil.direction[1] -
        pencil.pVec[1] * pencil.direction[0];

    if (spacingCrossDirection == ENumber(0)) {
      throw std::runtime_error(
          "linepencil_single_line_intersection(): degenerate pencil spacing");
    }

    const ENumber deltaX = linePoint[0] - pencil.p0[0];
    const ENumber deltaY = linePoint[1] - pencil.p0[1];
    const ENumber overlapIso =
        (deltaX * pencil.direction[1] -
         deltaY * pencil.direction[0]) /
        spacingCrossDirection;

    int result = 0;
    if (enumber_den(overlapIso) == EInt(1)) {
      overlapLine = enumber_num(overlapIso);
      const long long overlapIndex = overlapLine.convert();
      if (overlapIndex >= 0 &&
          overlapIndex < static_cast<long long>(pencil.numLines)) {
        result = 2;
#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
        ++timings.overlapCases;
#endif
      }
    }

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
    timings.parallelClassification +=
        exact_geometry_seconds_since(phaseStart);
    timings.total += exact_geometry_seconds_since(totalStart);
#endif
    return result;
  }

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  ++timings.nonParallelCases;
  phaseStart = Clock::now();
#endif

  const ENumber inverseDeterminant = ENumber(1) / determinant;
  const ENumber deltaX = linePoint[0] - pencil.p0[0];
  const ENumber deltaY = linePoint[1] - pencil.p0[1];

  lineParameter0 =
      (deltaX * lineDirection[1] -
       deltaY * lineDirection[0]) *
      inverseDeterminant;

  edgeParameter0 =
      (deltaX * pencil.direction[1] -
       deltaY * pencil.direction[0]) *
      inverseDeterminant;

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  timings.baseParameters += exact_geometry_seconds_since(phaseStart);
  phaseStart = Clock::now();
#endif

  lineParameterStep =
      -(pencil.pVec[0] * lineDirection[1] -
        pencil.pVec[1] * lineDirection[0]) *
      inverseDeterminant;

  edgeParameterStep =
      -(pencil.pVec[0] * pencil.direction[1] -
        pencil.pVec[1] * pencil.direction[0]) *
      inverseDeterminant;

#if DIRECTIONAL_ENABLE_EXACT_GEOMETRY_TIMING
  timings.stepParameters += exact_geometry_seconds_since(phaseStart);
  timings.total += exact_geometry_seconds_since(totalStart);
#endif

  return 1;
}

inline std::vector<std::pair<ENumber, ENumber>>
segment_segment_intersection(const Segment2 &seg1, const Segment2 &seg2) {

  ENumber t1, t2;
  // std::cout<<"Computing intersection of "<<seg1<<" and "<<seg2<<std::endl;
  int result = line_line_intersection(
      Line2(seg1.source, seg1.target - seg1.source),
      Line2(seg2.source, seg2.target - seg2.source), t1, t2);

  if (result == 0) {
    // std::cout<<"supporting lines don't intersect"<<std::endl;
    return std::vector<std::pair<ENumber, ENumber>>(); // no intersection
  }

  if (result == 1) { // a single intersection at most; should check t1 and t2
    // std::cout<<"single intersection"<<std::endl;
    if ((t1 >= ENumber(0)) && (t1 <= ENumber(1)) && (t2 >= ENumber(0)) &&
        (t2 <= ENumber(1))) {
      std::vector<std::pair<ENumber, ENumber>> point(1);
      point[0] = std::pair<ENumber, ENumber>(t1, t2);
      // std::cout<<"Intersecting at parameters
      // "<<point[0].first.get_d()<<","<<point[0].second.get_d()<<std::endl;
      return point;
    } else {
      // std::cout<<"Intersecting out of parameter bounds"<<std::endl;
      return std::vector<std::pair<ENumber, ENumber>>(); // no intersection
    }
  }

  if (result == 2) { // lines overlap; should check the segments overlap and
                     // then return both overlap points (order not important)
    // std::cout<<"Supporting lines overlap"<<std::endl;
    EVector2 vec = seg1.target - seg1.source;
    int axis = (vec[0] != ENumber(0) ? 0 : 1);
    Segment2 sortSeg1, sortSeg2;
    if (seg1.source[axis] < seg1.target[axis])
      sortSeg1 = seg1;
    else
      sortSeg1 = Segment2(seg1.target, seg1.source);
    if (seg2.source[axis] < seg2.target[axis])
      sortSeg2 = seg2;
    else
      sortSeg2 = Segment2(seg2.target, seg2.source);
    EVector2 startPoint =
        (sortSeg1.source[axis] > sortSeg2.source[axis] ? sortSeg1.source
                                                       : sortSeg2.source);
    EVector2 endPoint =
        (sortSeg1.target[axis] > sortSeg2.target[axis] ? sortSeg2.target
                                                       : sortSeg1.target);

    // TODO: what is the policy with segment-vertex tangency?
    if (startPoint[axis] <
        endPoint[axis]) { // there is a (non-zero) intersection
      ENumber startAtSeg1 = (startPoint[axis] - seg1.source[axis]) /
                            (seg1.target[axis] - seg1.source[axis]);
      ENumber startAtSeg2 = (startPoint[axis] - seg2.source[axis]) /
                            (seg2.target[axis] - seg2.source[axis]);
      ENumber endAtSeg1 = (endPoint[axis] - seg1.source[axis]) /
                          (seg1.target[axis] - seg1.source[axis]);
      ENumber endAtSeg2 = (endPoint[axis] - seg2.source[axis]) /
                          (seg2.target[axis] - seg2.source[axis]);
      std::vector<std::pair<ENumber, ENumber>> points(2);
      points[0] = std::pair<ENumber, ENumber>(startAtSeg1, startAtSeg2);
      points[1] = std::pair<ENumber, ENumber>(endAtSeg1, endAtSeg2);
      // std::cout<<"Intersecting at parameters
      // "<<points[0].first.to_double()<<","<<points[0].second.to_double()<<"
      // and
      // "<<points[1].first.to_double()<<","<<points[1].second.to_double()<<std::endl;
      return points;
    } else {
      // std::cout<<"parameters don't overlap"<<std::endl;
      return std::vector<std::pair<ENumber, ENumber>>(); // no intersection
    }
  }
}

inline std::vector<ENumber> line_segment_intersection(const Line2 &line,
                                               const Segment2 &segment) {

  // std::cout<<"Computing intersection between line :"<<line<<" and segment
  // "<<segment<<std::endl;
  Line2 segLine(segment.source, segment.target - segment.source);
  ENumber t1, t2;
  int intersectType = line_line_intersection(line, segLine, t1, t2);
  if (intersectType == 0) { // no intersection
    // std::cout<<"No intersection (lines parallel)"<<std::endl;
    return std::vector<ENumber>();
  } else if (intersectType == 2) { // the entire segment is contained in the
                                   // line
    std::vector<ENumber> result(2);
    result[0] = ENumber(0);
    result[1] =
        ENumber(1); // This is wrong! should have been the line parameters
    std::cout << "[Directional::line_segment_intersection()]: " << "Entire segment is contained in line" << std::endl;
    return result;
  } else { //(intersectType==1)
    if ((t2 >= ENumber(0)) && (t2 <= ENumber(1))) {
      std::vector<ENumber> result(1);
      result[0] = t1;
      // std::cout<<"Intersecting at line parameter t1:"<<t1.get_d()<<std::endl;
      return result;
    } else {
      // std::cout<<"No intersection  (out of segment parameter)"<<std::endl;
      return std::vector<ENumber>();
    }
  }
}

inline void line_triangle_intersection(const Line2 &line,
                                const std::vector<EVector2> &triangle,
                                bool &intEdge, bool &intFace, ENumber &inParam,
                                ENumber &outParam) {

  inParam = ENumber(3276700);
  outParam = ENumber(-3276700);
  intFace = intEdge = false;
  for (int i = 0; i < 3; i++) {
    Segment2 edgeSegment(triangle[i], triangle[(i + 1) % 3]);
    std::vector<ENumber> result = line_segment_intersection(line, edgeSegment);
    for (int j = 0; j < result.size(); j++) {
      inParam = (inParam < result[j] ? inParam : result[j]);
      outParam = (outParam > result[j] ? outParam : result[j]);
    }
    if (result.size() == 2) {
      std::cout << "line triangle overlap!!!" << std::endl;
      intEdge = true;
      intFace = false;
      return;
    }
    if (result.size() == 1)
      intFace = true;
  }
  if (inParam == outParam) // intersecting the triangle only by a vertex;
                           // ignored
    intFace = intEdge = false;
  /*if (intFace){
   std::cout<<"Intersecting within the face with parameters
   "<<inParam.get_d()<<"->"<<outParam.get_d()<<std::endl;
   }*/
  /*else if (intEdge){
   std::cout<<"Intersecting an edge with parameters
   "<<inParam.get_d()<<"->"<<outParam.get_d()<<std::endl; } else
   std::cout<<"Line doesn't intersect triangle"<<std::endl;*/
}

struct LinePencilTriangleTimings {
  std::size_t calls = 0;
  std::size_t triangleEdgesProcessed = 0;
  std::size_t candidateLines = 0;
  std::size_t acceptedEdgeHits = 0;
  std::size_t overlapCases = 0;

  double outputInitialization = 0.0;
  double edgePencilSetup = 0.0;
  double pencilIntersection = 0.0;
  double overlapHandling = 0.0;
  double affineLineSweep = 0.0;
  double finalClassification = 0.0;
  double total = 0.0;
};

inline LinePencilTriangleTimings &
linepencil_triangle_timings_accumulator() {
  static LinePencilTriangleTimings timings;
  return timings;
}

inline void reset_linepencil_triangle_timings() {
  linepencil_triangle_timings_accumulator() =
      LinePencilTriangleTimings{};
}

inline double linepencil_triangle_seconds_since(
    const std::chrono::high_resolution_clock::time_point &start) {
  return std::chrono::duration<double>(
             std::chrono::high_resolution_clock::now() - start)
      .count();
}

inline void print_linepencil_triangle_timings(
    const LinePencilTriangleTimings &timings) {
  std::cout
      << "[Directional::linepencil_triangle_intersection()]: "
         "timing summary\n"
      << "  calls:                 " << timings.calls << '\n'
      << "  triangle edges:        "
      << timings.triangleEdgesProcessed << '\n'
      << "  candidate lines:       " << timings.candidateLines << '\n'
      << "  accepted edge hits:    " << timings.acceptedEdgeHits << '\n'
      << "  overlap cases:         " << timings.overlapCases << '\n'
      << "  output initialization: " << timings.outputInitialization
      << " s\n"
      << "  edge-pencil setup:     " << timings.edgePencilSetup << " s\n"
      << "  pencil intersection:   " << timings.pencilIntersection
      << " s\n"
      << "  overlap handling:      " << timings.overlapHandling << " s\n"
      << "  affine line sweep:     " << timings.affineLineSweep << " s\n"
      << "  final classification:  " << timings.finalClassification
      << " s\n"
      << "  total:                 " << timings.total << " s\n";
}

/*
 * Intersect every line in a pencil with a CCW triangle.
 *
 * Optimizations relative to the original implementation:
 *
 * 1. The triangle is passed by const reference instead of copied.
 * 2. Dynamic Eigen matrices containing all per-line parameter pairs are
 *    eliminated.
 * 3. Per-line parameters are generated with an affine recurrence:
 *
 *      t(j + 1) = t(j) + dt
 *
 *    rather than constructing ENumber(j) and multiplying for every line.
 * 4. The triangle-edge parameter interval is known exactly to be [0, 1],
 *    because each temporary edge pencil uses the edge's source as p0 and the
 *    edge vector as its direction. Two exact point_param() divisions per edge
 *    are therefore removed.
 * 5. Output buffers are initialized in bulk and reused by callers when their
 *    capacity is retained.
 */
inline void linepencil_triangle_intersection(
    const LinePencil &lp,
    const std::vector<EVector2> &triangle,
    std::vector<bool> &intEdges,
    std::vector<bool> &intFaces,
    std::vector<ENumber> &inParams,
    std::vector<ENumber> &outParams,
    std::vector<std::vector<ENumber>> &triParams) {
  using Clock = std::chrono::high_resolution_clock;

  LinePencilTriangleTimings &timings =
      linepencil_triangle_timings_accumulator();

  ++timings.calls;

  const auto totalStart = Clock::now();

  if (triangle.size() != 3) {
    throw std::invalid_argument(
        "linepencil_triangle_intersection(): triangle must contain "
        "exactly three vertices");
  }

  if (lp.numLines < 0) {
    throw std::invalid_argument(
        "linepencil_triangle_intersection(): negative line count");
  }

  const std::size_t lineCount =
      static_cast<std::size_t>(lp.numLines);

  timings.candidateLines += lineCount;

  const ENumber positiveSentinel(3276700);
  const ENumber negativeSentinel(-3276700);
  const ENumber zero(0);
  const ENumber one(1);

  auto phaseStart = Clock::now();

  inParams.assign(lineCount, positiveSentinel);
  outParams.assign(lineCount, negativeSentinel);
  intEdges.assign(lineCount, false);
  intFaces.assign(lineCount, false);

  triParams.clear();
  triParams.resize(3);

  for (auto &parameters : triParams) {
    parameters.clear();
    parameters.reserve(lineCount);
  }

  timings.outputInitialization +=
      linepencil_triangle_seconds_since(phaseStart);

  for (int edgeIndex = 0; edgeIndex < 3; ++edgeIndex) {
    ++timings.triangleEdgesProcessed;

    phaseStart = Clock::now();

    const EVector2 &edgeSource =
        triangle[static_cast<std::size_t>(edgeIndex)];

    const EVector2 &edgeTarget =
        triangle[static_cast<std::size_t>((edgeIndex + 1) % 3)];

    const EVector2 edgeDirection =
        edgeTarget - edgeSource;

    /*
     * The specialized helper needs only the edge source/direction and the
     * first affine parameter column used by the line sweep.
     */
    ENumber lineParameter;
    ENumber edgeParameter;
    ENumber lineParameterStep;
    ENumber edgeParameterStep;
    EInt overlappingIsoValue;

    timings.edgePencilSetup +=
        linepencil_triangle_seconds_since(phaseStart);

    phaseStart = Clock::now();

    const int intersectionType =
        linepencil_single_line_intersection(
            lp,
            edgeSource,
            edgeDirection,
            lineParameter,
            edgeParameter,
            lineParameterStep,
            edgeParameterStep,
            overlappingIsoValue);

    timings.pencilIntersection +=
        linepencil_triangle_seconds_since(phaseStart);

    if (intersectionType == 2) {
      phaseStart = Clock::now();
      ++timings.overlapCases;

      const long long overlapLineValue =
          overlappingIsoValue.convert();

      if (overlapLineValue < 0 ||
          overlapLineValue >= static_cast<long long>(lineCount)) {
        throw std::runtime_error(
            "linepencil_triangle_intersection(): overlapping line index "
            "is outside the pencil");
      }

      const std::size_t overlapLine =
          static_cast<std::size_t>(overlapLineValue);

      intEdges[overlapLine] = true;

      /*
       * The overlap is rare, so retain the exact projection path here.
       * Construct the line once instead of calling lp.line() twice.
       */
      const Line2 overlapGeometry =
          lp.line(static_cast<int>(overlapLine));

      const ENumber sourceParameter =
          overlapGeometry.point_param(edgeSource);

      const ENumber targetParameter =
          overlapGeometry.point_param(edgeTarget);

      if (sourceParameter < targetParameter) {
        inParams[overlapLine] = sourceParameter;
        outParams[overlapLine] = targetParameter;
      } else {
        inParams[overlapLine] = targetParameter;
        outParams[overlapLine] = sourceParameter;
      }

      triParams[static_cast<std::size_t>(edgeIndex)].push_back(zero);
      triParams[static_cast<std::size_t>(edgeIndex)].push_back(one);

      timings.overlapHandling +=
          linepencil_triangle_seconds_since(phaseStart);

      continue;
    }

    if (intersectionType != 1) {
      continue;
    }

    phaseStart = Clock::now();

    /*
     * For a fixed edge pencil line index 0:
     *
     *   [line parameter, edge parameter]^T
     *       = t00 + I2dt.col(0) * lineIndex
     *
     * Generate that affine sequence incrementally. This removes one exact
     * integer construction and four exact multiplications per line.
     */
    auto &edgeParameters =
        triParams[static_cast<std::size_t>(edgeIndex)];

    for (std::size_t lineIndex = 0;
         lineIndex < lineCount;
         ++lineIndex) {
      if (edgeParameter >= zero && edgeParameter <= one) {
        ++timings.acceptedEdgeHits;

        edgeParameters.push_back(edgeParameter);

        if (lineParameter > outParams[lineIndex]) {
          outParams[lineIndex] = lineParameter;
        }

        if (lineParameter < inParams[lineIndex]) {
          inParams[lineIndex] = lineParameter;
        }
      }

      /* ENumber does not consistently expose compound assignment. */
      lineParameter = lineParameter + lineParameterStep;
      edgeParameter = edgeParameter + edgeParameterStep;
    }

    timings.affineLineSweep +=
        linepencil_triangle_seconds_since(phaseStart);
  }

  phaseStart = Clock::now();

  for (std::size_t lineIndex = 0;
       lineIndex < lineCount;
       ++lineIndex) {
    if (!intEdges[lineIndex] &&
        inParams[lineIndex] != outParams[lineIndex] &&
        inParams[lineIndex] != positiveSentinel &&
        outParams[lineIndex] != negativeSentinel) {
      intFaces[lineIndex] = true;
    }
  }

  timings.finalClassification +=
      linepencil_triangle_seconds_since(phaseStart);

  timings.total +=
      linepencil_triangle_seconds_since(totalStart);
}

// according to this:
// https://math.stackexchange.com/questions/1450498/rational-ordering-of-vectors
inline ENumber slope_function(const EVector2 &vec) {
  // predicates might be expensive, so precomputing
  bool x0 = vec[0] > ENumber(0);
  bool y0 = vec[1] > ENumber(0);
  // bool xy = (y0 && vec[1]>vec[0])||(!y0 && vec[1]<=vec[0]);
  bool xy = vec[1].abs() > vec[0].abs();

  // std::cout<<"vec: "<<vec<<std::endl;

  if (xy) {
    if (y0)
      return ENumber(1) - vec[0] / vec[1]; // case 1
    else
      return ENumber(5) - vec[0] / vec[1]; // case 3
  } else {
    if (x0) {
      if (y0)
        return vec[1] / vec[0] - ENumber(1); // case 0
      else
        return vec[1] / vec[0] + ENumber(7); // case 4
    } else {
      return vec[1] / vec[0] + ENumber(3); // case 2
    }
  }
}

inline double slope_function_double(const Eigen::RowVector2d &vec) {
  // predicates might be expensive, so precomputing
  bool x0 = vec[0] > 0.0;
  bool y0 = vec[1] > 0.0;
  // bool xy = (y0 && vec[1]>vec[0])||(!y0 && vec[1]<=vec[0]);
  bool xy = std::abs(vec[1]) > std::abs(vec[0]);

  // std::cout<<"vec: "<<vec<<std::endl;

  if (xy) {
    if (y0)
      return 1.0 - vec[0] / vec[1]; // case 1
    else
      return 5.0 - vec[0] / vec[1]; // case 3
  } else {
    if (x0) {
      if (y0)
        return vec[1] / vec[0] - 1.0; // case 0
      else
        return vec[1] / vec[0] + 7.0; // case 4
    } else {
      return vec[1] / vec[0] + 3.0; // case 2
    }
  }
}

inline double signed_face_area(const std::vector<EVector2> &faceVectors) {
  Eigen::RowVector2d currVertex =
      Eigen::RowVector2d::Zero(); // currVertex[0]=currVertex[1]=ENumber(0);
  double sfa = 0.0;
  for (int i = 0; i < faceVectors.size(); i++) {
    Eigen::RowVector2d nextVector = faceVectors[i].to_double();
    Eigen::RowVector2d nextVertex = currVertex + nextVector;
    sfa = sfa + currVertex[0] * nextVertex[1] - currVertex[1] * nextVertex[0];
    // std::cout<<"curr sfa: "<<sfa.get_d()<<std::endl;
    currVertex = nextVertex;
  }
  return sfa;
}

inline ENumber triangle_area(const std::vector<EVector2> &tri) {
  EVector2 e12 = tri[1] - tri[0];
  EVector2 e13 = tri[2] - tri[0];
  return (e12[0] * e13[1] - e13[0] * e12[1]) / ENumber(2);
}

inline void div_mod(const EInt a, const EInt b, EInt &q, EInt &r) {
  // mpz_tdiv_qr(q.get_mpz_t(),r.get_mpz_t(),a,b);
  q = a / b;
  r = a - b * q;
}
} // namespace directional

#endif // DIRECTIONAL_GMP_DEFINITIONS_H
