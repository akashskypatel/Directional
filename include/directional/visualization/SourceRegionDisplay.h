// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VISUALIZATION_SOURCE_REGION_DISPLAY_H
#define DIRECTIONAL_VISUALIZATION_SOURCE_REGION_DISPLAY_H

#include <directional/geometry/SourceTopologyRegions.h>

#include <Eigen/Core>

#include <cstddef>

namespace directional::visualization {

/**
 * Display data for the published A0 source topology regions.
 *
 * Diagnostic only: labels and segments are read from the published regions
 * without reinterpretation, and no pipeline stage reads them back.
 */
struct SourceRegionDisplay {
  /// Topology region, isolation sheet and source component of each face row.
  Eigen::VectorXi faceRegion;
  Eigen::VectorXi faceSheet;
  Eigen::VectorXi faceComponent;

  /// Isolation seams published by the regions, 2S x 3 and S x 2, and the
  /// region that publishes each seam edge.
  Eigen::MatrixXd seamPoints;
  Eigen::MatrixXi seamEdges;
  Eigen::VectorXi seamRegion;

  /// Region boundary edges (source boundary and cuts between regions),
  /// 2B x 3 and B x 2. An edge shared by two regions appears once.
  Eigen::MatrixXd boundaryPoints;
  Eigen::MatrixXi boundaryEdges;

  std::size_t regionCount = 0;
  /// Distinct isolation sheet ids over all faces.
  std::size_t sheetCount = 0;
};

/**
 * Reads per-face labels and the published seam and boundary edges.
 *
 * Throws std::invalid_argument when `V` is not n x 3, when the regions do not
 * cover exactly the rows of `F`, or when an edge vertex is outside `V`.
 */
SourceRegionDisplay source_region_display(
    const Eigen::MatrixXd &V, const Eigen::MatrixXi &F,
    const geometry::SourceTopologyRegions &regions);

} // namespace directional::visualization

#endif // DIRECTIONAL_VISUALIZATION_SOURCE_REGION_DISPLAY_H
