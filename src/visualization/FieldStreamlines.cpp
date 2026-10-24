// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/visualization/FieldStreamlines.h>

#include <directional/core/CartesianField.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/geometry/Streamlines.h>

#include <algorithm>
#include <array>
#include <cmath>
#include <map>
#include <numeric>
#include <random>
#include <stdexcept>
#include <vector>

namespace directional::visualization {
namespace {

constexpr int kCrossDirections = 4;

// Dart throwing over face barycenters in a shuffled, seeded order: a face is
// a seed when no earlier seed lies within `minimumDistance`. A uniform grid
// of cell size `minimumDistance` limits each test to 27 cells.
std::vector<int> select_seed_faces(const Eigen::MatrixXd &barycenters,
                                   const double minimumDistance,
                                   const unsigned int randomSeed) {
  std::vector<int> order(static_cast<std::size_t>(barycenters.rows()));
  std::iota(order.begin(), order.end(), 0);
  std::mt19937 generator(randomSeed);
  std::shuffle(order.begin(), order.end(), generator);
  if (!(minimumDistance > 0.0)) {
    return order;
  }

  const auto cell_of = [minimumDistance](const Eigen::RowVector3d &point) {
    return std::array<long long, 3>{
        static_cast<long long>(std::floor(point.x() / minimumDistance)),
        static_cast<long long>(std::floor(point.y() / minimumDistance)),
        static_cast<long long>(std::floor(point.z() / minimumDistance))};
  };
  std::map<std::array<long long, 3>, std::vector<int>> grid;
  std::vector<int> seeds;
  const double minimumSquared = minimumDistance * minimumDistance;
  for (const int face : order) {
    const Eigen::RowVector3d center = barycenters.row(face);
    const auto cell = cell_of(center);
    bool isolated = true;
    for (long long dx = -1; dx <= 1 && isolated; ++dx) {
      for (long long dy = -1; dy <= 1 && isolated; ++dy) {
        for (long long dz = -1; dz <= 1 && isolated; ++dz) {
          const auto found = grid.find({cell[0] + dx, cell[1] + dy, cell[2] + dz});
          if (found == grid.end()) continue;
          for (const int other : found->second) {
            if ((barycenters.row(other) - center).squaredNorm() <
                minimumSquared) {
              isolated = false;
              break;
            }
          }
        }
      }
    }
    if (isolated) {
      grid[cell].push_back(face);
      seeds.push_back(face);
    }
  }
  return seeds;
}

// The tracer records a segment's face and starting direction but not its
// line. Each init/next call appends the new segments line by line, in
// increasing line index (direction * seeds + seed), and leaves each line's
// last segment in currSegmentIndex. So the segments appended since `first`
// split into consecutive per-line blocks ending at those indices.
void assign_new_segments(const directional::StreamlineState &state,
                         const std::size_t first,
                         std::vector<int> &segmentLine) {
  segmentLine.resize(state.segStart.size(), -1);
  std::size_t cursor = first;
  for (Eigen::Index line = 0; line < state.currSegmentIndex.size(); ++line) {
    const auto last = static_cast<std::size_t>(state.currSegmentIndex(line));
    if (last < cursor || last >= segmentLine.size()) continue;
    for (; cursor <= last; ++cursor) {
      segmentLine[cursor] = static_cast<int>(line);
    }
  }
  if (cursor != segmentLine.size()) {
    throw std::logic_error("Streamline segments could not be assigned to lines.");
  }
}

} // namespace

FieldStreamlines trace_field_streamlines(const Eigen::MatrixXd &V,
                                         const Eigen::MatrixXi &F,
                                         const Eigen::MatrixXd &rawField,
                                         const FieldStreamlineOptions &options) {
  if (V.cols() != 3 || F.cols() != 3 || F.rows() == 0) {
    throw std::invalid_argument(
        "Streamlines need a non-empty triangle mesh with n x 3 vertices.");
  }
  if (rawField.rows() != F.rows() || rawField.cols() != 3 * kCrossDirections) {
    throw std::invalid_argument(
        "Streamlines need one 12-value raw cross per mesh face.");
  }
  if (options.steps <= 0 || !(options.stepLength > 0.0)) {
    throw std::invalid_argument(
        "Streamline steps and step length must be positive.");
  }

  directional::TriMesh mesh;
  mesh.set_mesh(V, F);
  const double edgeLength = mesh.avgEdgeLength;

  // Unit vectors make a line's length depend only on steps and step length.
  Eigen::MatrixXd unitField = rawField;
  for (Eigen::Index face = 0; face < unitField.rows(); ++face) {
    for (int direction = 0; direction < kCrossDirections; ++direction) {
      auto vector = unitField.block<1, 3>(face, 3 * direction);
      const double norm = vector.norm();
      if (norm > 0.0) vector /= norm;
    }
  }
  directional::PCFaceTangentBundle bundle;
  bundle.init(mesh);
  directional::CartesianField field;
  field.init(bundle, directional::fieldTypeEnum::RAW_FIELD, kCrossDirections);
  field.set_extrinsic_field(unitField);

  const std::vector<int> seeds = select_seed_faces(
      mesh.barycenters, options.seedSpacing * edgeLength, options.randomSeed);
  FieldStreamlines result;
  result.averageEdgeLength = edgeLength;
  result.seedFaces =
      Eigen::Map<const Eigen::VectorXi>(seeds.data(), static_cast<Eigen::Index>(seeds.size()));
  result.lineCount = 2 * seeds.size();

  directional::StreamlineData data;
  directional::StreamlineState state;
  std::vector<int> segmentLine;
  directional::streamlines_init(field, result.seedFaces, 0.0, data, state);
  assign_new_segments(state, 0, segmentLine);
  for (int step = 0; step < options.steps && state.segmentAlive.any(); ++step) {
    const std::size_t first = state.segStart.size();
    directional::streamlines_next(data, state, options.stepLength * edgeLength);
    assign_new_segments(state, first, segmentLine);
  }

  const int seedCount = static_cast<int>(seeds.size());
  const double lift = options.surfaceOffset * edgeLength;
  std::vector<std::size_t> kept;
  for (std::size_t segment = 0; segment < state.segStart.size(); ++segment) {
    // The tracer opens each half-line with a zero-length segment.
    if (state.segStart[segment] != state.segEnd[segment]) kept.push_back(segment);
  }
  const auto count = static_cast<Eigen::Index>(kept.size());
  result.points.resize(2 * count, 3);
  result.edges.resize(count, 2);
  result.edgeLine.resize(count);
  result.edgeFamily.resize(count);
  for (Eigen::Index row = 0; row < count; ++row) {
    const std::size_t segment = kept[static_cast<std::size_t>(row)];
    const Eigen::RowVector3d offset = lift * state.segNormal[segment];
    result.points.row(2 * row) = state.segStart[segment] + offset;
    result.points.row(2 * row + 1) = state.segEnd[segment] + offset;
    result.edges(row, 0) = static_cast<int>(2 * row);
    result.edges(row, 1) = static_cast<int>(2 * row + 1);
    // Half-line index = direction * seeds + seed; directions d and d + 2
    // form one family and one streamline.
    const int halfLine = segmentLine[segment];
    const int family = (halfLine / seedCount) % 2;
    result.edgeFamily(row) = family;
    result.edgeLine(row) = 2 * (halfLine % seedCount) + family;
  }
  return result;
}

} // namespace directional::visualization
