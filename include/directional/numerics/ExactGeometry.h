// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_NUMERICS_EXACT_GEOMETRY_H
#define DIRECTIONAL_NUMERICS_EXACT_GEOMETRY_H

#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <deque>
#include <ostream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

#include <Eigen/Dense>
#include <Eigen/Sparse>

#ifdef USE_GMP_ENABLED
#include <directional/numerics/ENumberGMP.h>
#else
#include <directional/numerics/ExactNumber.h>
#endif

// This header file concentrates geometric operations on vectors, segments,
// lines, and arrangement in exact rational numbers.

/**
 * @file ExactGeometry.h
 * @brief Exact two-dimensional geometry predicates and constructions.
 *
 * Provides exact vectors, segments, lines, line pencils, intersections, area computations, and helper routines used by the N-function mesher to avoid floating-point robustness failures.
 */

namespace directional {

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
      doubleVec(i) = static_cast<double>(data[i].to_double());
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

/** @brief Exact 2D segment represented by two endpoints. */
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

std::ostream &operator<<(std::ostream &os, const Segment2 &seg);

/** @brief Exact implicit 2D line with integer/rational coefficients. */
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

std::ostream &operator<<(std::ostream &os, const Line2 &line);

/** @brief Family of parallel or related exact lines generated from a base line. */
struct LinePencil {
  int numLines;
  EVector2 direction; // the mutual direction along the line
  EVector2 p0, pVec;  // p0 is the origin of the first line. pVec is the vector
                      // between the origins of the lines (p0(I+1)-p0(I) = pvec)

  inline Line2 line(const int lineNum) const {
    return Line2(p0 + pVec * ENumber(lineNum), direction);
  }
};

ENumber squaredDistance(const EVector3 &v1, const EVector3 &v2);

// produces y = M*x
void exactSparseMult(const Eigen::SparseMatrix<int> &M,
                            const std::vector<ENumber> &x,
                            std::vector<ENumber> &y);

void exactDenseMult(const Eigen::MatrixXi &nM, const Eigen::MatrixXi &dM,
                           const std::vector<ENumber> &x,
                           std::vector<ENumber> &y);

// This assumes components is already resized to the correct |v|
// not very efficient but probably not terrible
int connectedComponents(const std::vector<std::pair<int, int>> &matches,
                               std::vector<int> &components);

int line_line_intersection(const Line2 &line1, const Line2 &line2,
                                  ENumber &t1, ENumber &t2);

// returns a generator for the grid of intersections, parameterized by p00 +
// pVec1*isoValue1 + pVec2*isoValue2, txp00 is the t(1 or 2) of the p00 point in
// each respective line dtx (1 or 2) is the dt going along each pVecx (1 or 2)
// for iso1 and iso2 in the respective line pencil ranges
// result = 2 is only acceptable if |lp2| = 1, not handling parallel full line
// pencils (shouldn't be unless the parameterization is degenerate).
/*
 * Scalar implementation of line-pencil intersection.
 *
 * Compared with the former Eigen-expression implementation, this version:
 * - computes the determinant once;
 * - computes one reciprocal and multiplies by it, avoiding six divisions;
 * - avoids temporary EVector/Eigen expressions in the hot path;
 * - uses runtime validation instead of release-disabled assertions.
 */
int linepencil_intersection(const LinePencil &lp1, const LinePencil &lp2,
                                   Eigen::Matrix<ENumber, 2, 1> &t00,
                                   Eigen::Matrix<ENumber, 2, 2> &I2dt,
                                   EInt &iso1Overlap);

/*
 * Specialized hot-path intersection between a line pencil and one line.
 * Only the first affine column is needed by triangle clipping, so this avoids
 * constructing a temporary LinePencil and avoids computing two unused values.
 */
int linepencil_single_line_intersection(
    const LinePencil &pencil, const EVector2 &linePoint,
    const EVector2 &lineDirection, ENumber &lineParameter0,
    ENumber &edgeParameter0, ENumber &lineParameterStep,
    ENumber &edgeParameterStep, EInt &overlapLine);

std::vector<std::pair<ENumber, ENumber>>
segment_segment_intersection(const Segment2 &seg1, const Segment2 &seg2);

std::vector<ENumber> line_segment_intersection(const Line2 &line,
                                                      const Segment2 &segment);

void line_triangle_intersection(const Line2 &line,
                                       const std::vector<EVector2> &triangle,
                                       bool &intEdge, bool &intFace,
                                       ENumber &inParam, ENumber &outParam);

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
void linepencil_triangle_intersection(
    const LinePencil &lp, const std::vector<EVector2> &triangle,
    std::vector<bool> &intEdges, std::vector<bool> &intFaces,
    std::vector<ENumber> &inParams, std::vector<ENumber> &outParams,
    std::vector<std::vector<ENumber>> &triParams, const int triangleIndex = -1,
    const int localPencilIndex = -1, const int originalFunctionIndex = -1,
    const std::array<int, 3> *originalHalfedges = nullptr);

// according to this:
// https://math.stackexchange.com/questions/1450498/rational-ordering-of-vectors
ENumber slope_function(const EVector2 &vec);

double slope_function_double(const Eigen::RowVector2d &vec);

double signed_face_area(const std::vector<EVector2> &faceVectors);

ENumber triangle_area(const std::vector<EVector2> &tri);

void div_mod(const EInt a, const EInt b, EInt &q, EInt &r);
} // namespace directional

#endif // DIRECTIONAL_NUMERICS_EXACT_GEOMETRY_H
