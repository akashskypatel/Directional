// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_LOCAL_PATCH_VALIDATOR_H
#define DIRECTIONAL_MESHING_LOCAL_PATCH_VALIDATOR_H

#include <algorithm>
#include <cstddef>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

namespace directional {
namespace detail {

enum class LocalPatchRejectionReason {
  None,
  InvalidPatch,
  DisconnectedRegion,
  RepeatedBoundaryVertex,
  ConsecutiveDuplicateEdge,
  FaceDegreeBelowThree,
  ZeroLengthBoundaryEdge,
  EulerCharacteristicChanged,
  ProtectedSeamMutation,
  ComponentSplit,
  NewBoundaryOnClosedRegion
};

struct LocalPatchValidationResult {
  bool accepted = false;
  LocalPatchRejectionReason reason = LocalPatchRejectionReason::InvalidPatch;
};

struct LocalPatchDescriptor {
  std::vector<std::pair<int, int>> regionAdjacency;
  std::vector<std::vector<int>> postEditBoundaryLoops;
  std::vector<int> postEditFaceDegrees;
  int expectedEulerCharacteristic = 0;
  int postEditEulerCharacteristic = 0;
  int expectedComponentCount = 1;
  int postEditComponentCount = 1;
  bool mutatesProtectedSeam = false;
  bool wasClosedRegion = false;
  bool introducesBoundary = false;
};

class LocalPatchValidator {
public:
  [[nodiscard]] static const char *
  reason_name(const LocalPatchRejectionReason reason) {
    switch (reason) {
    case LocalPatchRejectionReason::None:
      return "none";
    case LocalPatchRejectionReason::InvalidPatch:
      return "invalidPatch";
    case LocalPatchRejectionReason::DisconnectedRegion:
      return "disconnectedRegion";
    case LocalPatchRejectionReason::RepeatedBoundaryVertex:
      return "repeatedBoundaryVertex";
    case LocalPatchRejectionReason::ConsecutiveDuplicateEdge:
      return "consecutiveDuplicateEdge";
    case LocalPatchRejectionReason::FaceDegreeBelowThree:
      return "faceDegreeBelowThree";
    case LocalPatchRejectionReason::ZeroLengthBoundaryEdge:
      return "zeroLengthBoundaryEdge";
    case LocalPatchRejectionReason::EulerCharacteristicChanged:
      return "eulerCharacteristicChanged";
    case LocalPatchRejectionReason::ProtectedSeamMutation:
      return "protectedSeamMutation";
    case LocalPatchRejectionReason::ComponentSplit:
      return "componentSplit";
    case LocalPatchRejectionReason::NewBoundaryOnClosedRegion:
      return "newBoundaryOnClosedRegion";
    }
    return "unknown";
  }

  [[nodiscard]] static LocalPatchValidationResult
  validate(const LocalPatchDescriptor &patch) {
    if (patch.expectedComponentCount <= 0 || patch.postEditComponentCount <= 0) {
      return reject(LocalPatchRejectionReason::InvalidPatch);
    }
    for (const int degree : patch.postEditFaceDegrees) {
      if (degree < 3) {
        return reject(LocalPatchRejectionReason::FaceDegreeBelowThree);
      }
    }
    for (const std::vector<int> &loop : patch.postEditBoundaryLoops) {
      const LocalPatchRejectionReason loopReason = validate_boundary_loop(loop);
      if (loopReason != LocalPatchRejectionReason::None) {
        return reject(loopReason);
      }
    }
    if (patch.expectedEulerCharacteristic != patch.postEditEulerCharacteristic) {
      return reject(LocalPatchRejectionReason::EulerCharacteristicChanged);
    }
    if (patch.mutatesProtectedSeam) {
      return reject(LocalPatchRejectionReason::ProtectedSeamMutation);
    }
    if (patch.postEditComponentCount > patch.expectedComponentCount) {
      return reject(LocalPatchRejectionReason::ComponentSplit);
    }
    if (!region_connected(patch)) {
      return reject(LocalPatchRejectionReason::DisconnectedRegion);
    }
    if (patch.wasClosedRegion && patch.introducesBoundary) {
      return reject(LocalPatchRejectionReason::NewBoundaryOnClosedRegion);
    }
    return {true, LocalPatchRejectionReason::None};
  }

private:
  [[nodiscard]] static LocalPatchValidationResult
  reject(const LocalPatchRejectionReason reason) {
    return {false, reason};
  }

  [[nodiscard]] static bool region_connected(const LocalPatchDescriptor &patch) {
    if (patch.postEditComponentCount != 1) {
      return false;
    }
    std::set<int> vertices;
    for (const auto &edge : patch.regionAdjacency) {
      vertices.insert(edge.first);
      vertices.insert(edge.second);
    }
    for (const auto &loop : patch.postEditBoundaryLoops) {
      vertices.insert(loop.begin(), loop.end());
    }
    if (vertices.empty()) {
      return false;
    }
    if (patch.regionAdjacency.empty()) {
      return vertices.size() <= 1;
    }

    std::set<int> visited;
    std::queue<int> pending;
    pending.push(*vertices.begin());
    visited.insert(*vertices.begin());

    while (!pending.empty()) {
      const int current = pending.front();
      pending.pop();
      for (const auto &edge : patch.regionAdjacency) {
        int next = -1;
        if (edge.first == current) {
          next = edge.second;
        } else if (edge.second == current) {
          next = edge.first;
        }
        if (next >= 0 && visited.insert(next).second) {
          pending.push(next);
        }
      }
    }

    return std::all_of(vertices.begin(), vertices.end(), [&](const int vertex) {
      return visited.count(vertex) != 0;
    });
  }

  [[nodiscard]] static LocalPatchRejectionReason
  validate_boundary_loop(const std::vector<int> &loop) {
    if (loop.empty()) {
      return LocalPatchRejectionReason::None;
    }
    if (loop.size() < 3) {
      return LocalPatchRejectionReason::FaceDegreeBelowThree;
    }

    std::set<int> seen;
    for (const int vertex : loop) {
      if (vertex < 0) {
        return LocalPatchRejectionReason::InvalidPatch;
      }
      if (!seen.insert(vertex).second) {
        return LocalPatchRejectionReason::RepeatedBoundaryVertex;
      }
    }

    for (std::size_t index = 0; index < loop.size(); ++index) {
      const int current = loop[index];
      const int next = loop[(index + 1) % loop.size()];
      if (current == next) {
        return LocalPatchRejectionReason::ZeroLengthBoundaryEdge;
      }
      if (index > 0 && loop[index - 1] == next) {
        return LocalPatchRejectionReason::ConsecutiveDuplicateEdge;
      }
    }
    return LocalPatchRejectionReason::None;
  }
};

} // namespace detail
} // namespace directional

#endif // DIRECTIONAL_MESHING_LOCAL_PATCH_VALIDATOR_H
