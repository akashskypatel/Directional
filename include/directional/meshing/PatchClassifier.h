// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_PATCH_CLASSIFIER_H
#define DIRECTIONAL_MESHING_PATCH_CLASSIFIER_H

#include <directional/meshing/PatchRegion.h>

namespace directional {
namespace detail {

struct PatchClassification {
  PatchClass patchClass = PatchClass::Unsupported;
  bool accepted = false;
};

class PatchClassifier {
public:
  [[nodiscard]] static PatchClassification classify(const PatchRegion &region) {
    if (!basic_boundary_is_valid(region)) {
      return {};
    }

    const std::size_t sideCount = region.sideEdgeCounts.size();
    if (sideCount == 4 && region.sideEdgeCounts[0] == region.sideEdgeCounts[2] &&
        region.sideEdgeCounts[1] == region.sideEdgeCounts[3]) {
      return {PatchClass::FourSidedDisk, true};
    }

    if ((sideCount == 3 || sideCount == 5 || sideCount == 6) &&
        patch_boundary_edge_count(region) % 2 == 0) {
      if (sideCount == 3) {
        return {PatchClass::SimpleThreeSided, true};
      }
      if (sideCount == 5) {
        return {PatchClass::SimpleFiveSided, true};
      }
      return {PatchClass::SimpleSixSided, true};
    }

    return {};
  }

private:
  [[nodiscard]] static bool basic_boundary_is_valid(const PatchRegion &region) {
    if (!region.diskTopology || region.sideEdgeCounts.empty()) {
      return false;
    }
    const std::size_t edgeCount = patch_boundary_edge_count(region);
    return edgeCount >= 3 && edgeCount == region.boundaryVertices.size();
  }
};

} // namespace detail
} // namespace directional

#endif // DIRECTIONAL_MESHING_PATCH_CLASSIFIER_H
