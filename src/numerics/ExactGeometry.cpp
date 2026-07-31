#include <directional/numerics/ExactGeometry.h>

namespace directional {

std::ostream &operator<<(std::ostream &os, const Segment2 &seg) {
  os << "Segment2(" << seg.source << "->" << seg.target << ")";
  return os;
}

} // namespace directional

namespace directional {

std::ostream &operator<<(std::ostream &os, const Line2 &line) {
  os << "Line2(" << line.point << " + " << line.direction << ")";
  return os;
}

} // namespace directional

namespace directional {

ENumber squaredDistance(const EVector3 &v1, const EVector3 &v2) {
  ENumber sd(0);
  for (int i = 0; i < 3; i++)
    sd += (v1[i] - v2[i]) * (v1[i] - v2[i]); // maybe it's not efficient

  return sd;
}

} // namespace directional

namespace directional {

void exactSparseMult(const Eigen::SparseMatrix<int> &M,
                            const std::vector<ENumber> &x,
                            std::vector<ENumber> &y) {
  y.resize(M.rows());

  for (int i = 0; i < y.size(); i++)
    y[i] = ENumber(0);

  for (int k = 0; k < M.outerSize(); ++k)
    for (Eigen::SparseMatrix<int>::InnerIterator it(M, k); it; ++it) {
      y[it.row()] += ENumber((long)it.value()) * x[it.col()];
    }
}

} // namespace directional

namespace directional {

void exactDenseMult(const Eigen::MatrixXi &nM, const Eigen::MatrixXi &dM,
                           const std::vector<ENumber> &x,
                           std::vector<ENumber> &y) {
  y.resize(nM.rows());
  for (int i = 0; i < y.size(); i++)
    y[i] = ENumber(0);
  for (int i = 0; i < nM.rows(); i++)
    for (int j = 0; j < nM.cols(); j++)
      y[i] += x[j] * ENumber(nM(i, j), dM(i, j));
}

} // namespace directional

namespace directional {

int connectedComponents(const std::vector<std::pair<int, int>> &matches,
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
      components[nextVertex] = numComponents++;
    }

    // Otherwise, doing DFS on edges
    for (int i = 0; i < VV[nextVertex].size(); i++) {
      if (components[VV[nextVertex][i]] == -1) {
        components[VV[nextVertex][i]] = components[nextVertex];
        nextVertexQueue.push_front(VV[nextVertex][i]);
      } else {
        if (components[VV[nextVertex][i]] != components[nextVertex]) {
          throw std::runtime_error(
              "connectedComponents(): components mismatch!");
        }
      }
    }
  }
  return numComponents;
}

} // namespace directional

namespace directional {

int line_line_intersection(const Line2 &line1, const Line2 &line2,
                                  ENumber &t1, ENumber &t2) {
  ENumber v1v2 = line1.direction.cross(line2.direction);
  if (v1v2 == ENumber(0)) {
    EVector2 pointVec = line1.point - line2.point;
    return (pointVec.cross(line1.direction) == ENumber(0) ? 2 : 0);
  }
  EVector2 p12 = line2.point - line1.point;
  t1 = p12.cross(line2.direction) / v1v2;
  t2 = p12.cross(line1.direction) / v1v2;
  return 1;
}

} // namespace directional

namespace directional {

int linepencil_intersection(const LinePencil &lp1, const LinePencil &lp2,
                                   Eigen::Matrix<ENumber, 2, 1> &t00,
                                   Eigen::Matrix<ENumber, 2, 2> &I2dt,
                                   EInt &iso1Overlap) {

  /*
   * Always initialize outputs. Parallel pencil pairs do not produce an
   * affine point-intersection grid, and callers must not observe stale data.
   */
  t00.setZero();
  I2dt.setZero();
  iso1Overlap = EInt(0);

  const ENumber determinant =
      lp1.direction[0] * lp2.direction[1] - lp1.direction[1] * lp2.direction[0];

  if (determinant == ENumber(0)) {

    /*
     * Two complete parallel pencils have no isolated point intersections.
     *
     * The original code asserted that lp2 contained one line, but that
     * condition is not guaranteed for general integrated fields. Return 0
     * and let the caller skip intersections between this pencil pair.
     */
    if (lp2.numLines != 1) {

      return 0;
    }

    const ENumber deltaX = lp2.p0[0] - lp1.p0[0];
    const ENumber deltaY = lp2.p0[1] - lp1.p0[1];
    const ENumber spacingCrossDirection =
        lp1.pVec[0] * lp1.direction[1] - lp1.pVec[1] * lp1.direction[0];

    if (spacingCrossDirection == ENumber(0)) {
      throw std::runtime_error(
          "linepencil_intersection(): degenerate first-pencil spacing");
    }

    const ENumber overlapIso =
        (deltaX * lp1.direction[1] - deltaY * lp1.direction[0]) /
        spacingCrossDirection;

    int result = 0;
    if (enumber_den(overlapIso) == EInt(1)) {
      iso1Overlap = enumber_num(overlapIso);
      const long long overlapIndex = iso1Overlap.convert();
      if (overlapIndex >= 0 &&
          overlapIndex < static_cast<long long>(lp1.numLines)) {
        result = 2;
      }
    }

    return result;
  }

  const ENumber inverseDeterminant = ENumber(1) / determinant;
  const ENumber deltaX = lp2.p0[0] - lp1.p0[0];
  const ENumber deltaY = lp2.p0[1] - lp1.p0[1];

  const ENumber t00First =
      (deltaX * lp2.direction[1] - deltaY * lp2.direction[0]) *
      inverseDeterminant;

  const ENumber t00Second =
      (deltaX * lp1.direction[1] - deltaY * lp1.direction[0]) *
      inverseDeterminant;

  const ENumber step00 =
      -(lp1.pVec[0] * lp2.direction[1] - lp1.pVec[1] * lp2.direction[0]) *
      inverseDeterminant;

  const ENumber step01 =
      (lp2.pVec[0] * lp2.direction[1] - lp2.pVec[1] * lp2.direction[0]) *
      inverseDeterminant;

  const ENumber step10 =
      -(lp1.pVec[0] * lp1.direction[1] - lp1.pVec[1] * lp1.direction[0]) *
      inverseDeterminant;

  const ENumber step11 =
      (lp2.pVec[0] * lp1.direction[1] - lp2.pVec[1] * lp1.direction[0]) *
      inverseDeterminant;

  t00(0) = t00First;
  t00(1) = t00Second;
  I2dt(0, 0) = step00;
  I2dt(0, 1) = step01;
  I2dt(1, 0) = step10;
  I2dt(1, 1) = step11;

  return 1;
}

} // namespace directional

namespace directional {

int linepencil_single_line_intersection(
    const LinePencil &pencil, const EVector2 &linePoint,
    const EVector2 &lineDirection, ENumber &lineParameter0,
    ENumber &edgeParameter0, ENumber &lineParameterStep,
    ENumber &edgeParameterStep, EInt &overlapLine) {

  const ENumber determinant = pencil.direction[0] * lineDirection[1] -
                              pencil.direction[1] * lineDirection[0];

  if (determinant == ENumber(0)) {

    const ENumber spacingCrossDirection = pencil.pVec[0] * pencil.direction[1] -
                                          pencil.pVec[1] * pencil.direction[0];

    if (spacingCrossDirection == ENumber(0)) {
      throw std::runtime_error(
          "linepencil_single_line_intersection(): degenerate pencil spacing");
    }

    const ENumber deltaX = linePoint[0] - pencil.p0[0];
    const ENumber deltaY = linePoint[1] - pencil.p0[1];
    const ENumber overlapIso =
        (deltaX * pencil.direction[1] - deltaY * pencil.direction[0]) /
        spacingCrossDirection;

    int result = 0;
    if (enumber_den(overlapIso) == EInt(1)) {
      overlapLine = enumber_num(overlapIso);
      const long long overlapIndex = overlapLine.convert();
      if (overlapIndex >= 0 &&
          overlapIndex < static_cast<long long>(pencil.numLines)) {
        result = 2;
      }
    }

    return result;
  }

  const ENumber inverseDeterminant = ENumber(1) / determinant;
  const ENumber deltaX = linePoint[0] - pencil.p0[0];
  const ENumber deltaY = linePoint[1] - pencil.p0[1];

  lineParameter0 = (deltaX * lineDirection[1] - deltaY * lineDirection[0]) *
                   inverseDeterminant;

  edgeParameter0 =
      (deltaX * pencil.direction[1] - deltaY * pencil.direction[0]) *
      inverseDeterminant;

  lineParameterStep =
      -(pencil.pVec[0] * lineDirection[1] - pencil.pVec[1] * lineDirection[0]) *
      inverseDeterminant;

  edgeParameterStep = -(pencil.pVec[0] * pencil.direction[1] -
                        pencil.pVec[1] * pencil.direction[0]) *
                      inverseDeterminant;

  return 1;
}

} // namespace directional

namespace directional {

std::vector<std::pair<ENumber, ENumber>>
segment_segment_intersection(const Segment2 &seg1, const Segment2 &seg2) {

  ENumber t1, t2;
  int result = line_line_intersection(
      Line2(seg1.source, seg1.target - seg1.source),
      Line2(seg2.source, seg2.target - seg2.source), t1, t2);

  if (result == 0) {
    return std::vector<std::pair<ENumber, ENumber>>(); // no intersection
  }

  if (result == 1) { // a single intersection at most; should check t1 and t2
    if ((t1 >= ENumber(0)) && (t1 <= ENumber(1)) && (t2 >= ENumber(0)) &&
        (t2 <= ENumber(1))) {
      std::vector<std::pair<ENumber, ENumber>> point(1);
      point[0] = std::pair<ENumber, ENumber>(t1, t2);
      return point;
    } else {
      return std::vector<std::pair<ENumber, ENumber>>(); // no intersection
    }
  }

  if (result == 2) { // lines overlap; should check the segments overlap and
                     // then return both overlap points (order not important)
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
      // and
      return points;
    } else {
      return std::vector<std::pair<ENumber, ENumber>>(); // no intersection
    }
  }
  return std::vector<std::pair<ENumber, ENumber>>();
}

} // namespace directional

namespace directional {

std::vector<ENumber> line_segment_intersection(const Line2 &line,
                                                      const Segment2 &segment) {
  Line2 segLine(segment.source, segment.target - segment.source);
  ENumber t1, t2;
  int intersectType = line_line_intersection(line, segLine, t1, t2);
  if (intersectType == 0) { // no intersection
    return std::vector<ENumber>();
  } else if (intersectType == 2) { // the entire segment is contained in the
                                   // line
    std::vector<ENumber> result(2);
    result[0] = line.point_param(segment.source);
    result[1] = line.point_param(segment.target);
    return result;
  } else { //(intersectType==1)
    if ((t2 >= ENumber(0)) && (t2 <= ENumber(1))) {
      std::vector<ENumber> result(1);
      result[0] = t1;
      return result;
    } else {
      return std::vector<ENumber>();
    }
  }
}

} // namespace directional

namespace directional {

void line_triangle_intersection(const Line2 &line,
                                       const std::vector<EVector2> &triangle,
                                       bool &intEdge, bool &intFace,
                                       ENumber &inParam, ENumber &outParam) {

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
}

} // namespace directional

namespace directional {

void linepencil_triangle_intersection(
    const LinePencil &lp, const std::vector<EVector2> &triangle,
    std::vector<bool> &intEdges, std::vector<bool> &intFaces,
    std::vector<ENumber> &inParams, std::vector<ENumber> &outParams,
    std::vector<std::vector<ENumber>> &triParams, const int triangleIndex,
    const int localPencilIndex, const int originalFunctionIndex,
    const std::array<int, 3> *originalHalfedges) {
  (void)triangleIndex;
  (void)localPencilIndex;
  (void)originalFunctionIndex;
  (void)originalHalfedges;

  if (triangle.size() != 3) {
    throw std::invalid_argument(
        "linepencil_triangle_intersection(): triangle must contain "
        "exactly three vertices");
  }

  if (lp.numLines < 0) {
    throw std::invalid_argument(
        "linepencil_triangle_intersection(): negative line count");
  }

  const std::size_t lineCount = static_cast<std::size_t>(lp.numLines);

  const ENumber positiveSentinel(3276700);
  const ENumber negativeSentinel(-3276700);
  const ENumber zero(0);
  const ENumber one(1);

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

  for (int edgeIndex = 0; edgeIndex < 3; ++edgeIndex) {

    const EVector2 &edgeSource = triangle[static_cast<std::size_t>(edgeIndex)];

    const EVector2 &edgeTarget =
        triangle[static_cast<std::size_t>((edgeIndex + 1) % 3)];

    const EVector2 edgeDirection = edgeTarget - edgeSource;

    /*
     * The specialized helper needs only the edge source/direction and the
     * first affine parameter column used by the line sweep.
     */
    ENumber lineParameter;
    ENumber edgeParameter;
    ENumber lineParameterStep;
    ENumber edgeParameterStep;
    EInt overlappingIsoValue;

    const int intersectionType = linepencil_single_line_intersection(
        lp, edgeSource, edgeDirection, lineParameter, edgeParameter,
        lineParameterStep, edgeParameterStep, overlappingIsoValue);

    if (intersectionType == 2) {

      const long long overlapLineValue = overlappingIsoValue.convert();

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
      const Line2 overlapGeometry = lp.line(static_cast<int>(overlapLine));

      const ENumber sourceParameter = overlapGeometry.point_param(edgeSource);

      const ENumber targetParameter = overlapGeometry.point_param(edgeTarget);

      if (sourceParameter < targetParameter) {
        inParams[overlapLine] = sourceParameter;
        outParams[overlapLine] = targetParameter;
      } else {
        inParams[overlapLine] = targetParameter;
        outParams[overlapLine] = sourceParameter;
      }

      triParams[static_cast<std::size_t>(edgeIndex)].push_back(zero);
      triParams[static_cast<std::size_t>(edgeIndex)].push_back(one);

      continue;
    }

    if (intersectionType != 1) {
      continue;
    }

    /*
     * For a fixed edge pencil line index 0:
     *
     *   [line parameter, edge parameter]^T
     *       = t00 + I2dt.col(0) * lineIndex
     *
     * Generate that affine sequence incrementally. This removes one exact
     * integer construction and four exact multiplications per line.
     */
    auto &edgeParameters = triParams[static_cast<std::size_t>(edgeIndex)];

    for (std::size_t lineIndex = 0; lineIndex < lineCount; ++lineIndex) {
      if (edgeParameter >= zero && edgeParameter <= one) {

        edgeParameters.push_back(edgeParameter);

        if (lineParameter > outParams[lineIndex]) {
          outParams[lineIndex] = lineParameter;
        }

        if (lineParameter < inParams[lineIndex]) {
          inParams[lineIndex] = lineParameter;
        }
      }

      /*
       * Advance to the next line in the pencil after consuming the current
       * exact parameters.
       */
      lineParameter = lineParameter + lineParameterStep;

      edgeParameter = edgeParameter + edgeParameterStep;
    }
  }

  for (std::size_t lineIndex = 0; lineIndex < lineCount; ++lineIndex) {
    if (!intEdges[lineIndex] && inParams[lineIndex] != outParams[lineIndex] &&
        inParams[lineIndex] != positiveSentinel &&
        outParams[lineIndex] != negativeSentinel) {
      intFaces[lineIndex] = true;
    }
  }
}

} // namespace directional

namespace directional {

ENumber slope_function(const EVector2 &vec) {
  // predicates might be expensive, so precomputing
  bool x0 = vec[0] > ENumber(0);
  bool y0 = vec[1] > ENumber(0);
  // bool xy = (y0 && vec[1]>vec[0])||(!y0 && vec[1]<=vec[0]);
  bool xy = vec[1].abs() > vec[0].abs();

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

} // namespace directional

namespace directional {

double slope_function_double(const Eigen::RowVector2d &vec) {
  // predicates might be expensive, so precomputing
  bool x0 = vec[0] > 0.0;
  bool y0 = vec[1] > 0.0;
  // bool xy = (y0 && vec[1]>vec[0])||(!y0 && vec[1]<=vec[0]);
  bool xy = std::abs(vec[1]) > std::abs(vec[0]);

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

} // namespace directional

namespace directional {

double signed_face_area(const std::vector<EVector2> &faceVectors) {
  Eigen::RowVector2d currVertex =
      Eigen::RowVector2d::Zero(); // currVertex[0]=currVertex[1]=ENumber(0);
  double sfa = 0.0;
  for (int i = 0; i < faceVectors.size(); i++) {
    Eigen::RowVector2d nextVector = faceVectors[i].to_double();
    Eigen::RowVector2d nextVertex = currVertex + nextVector;
    sfa = sfa + currVertex[0] * nextVertex[1] - currVertex[1] * nextVertex[0];
    currVertex = nextVertex;
  }
  return sfa;
}

} // namespace directional

namespace directional {

ENumber triangle_area(const std::vector<EVector2> &tri) {
  EVector2 e12 = tri[1] - tri[0];
  EVector2 e13 = tri[2] - tri[0];
  return (e12[0] * e13[1] - e13[0] * e12[1]) / ENumber(2);
}

} // namespace directional

namespace directional {

void div_mod(const EInt a, const EInt b, EInt &q, EInt &r) {
  // mpz_tdiv_qr(q.get_mpz_t(),r.get_mpz_t(),a,b);
  q = a / b;
  r = a - b * q;
}

} // namespace directional
