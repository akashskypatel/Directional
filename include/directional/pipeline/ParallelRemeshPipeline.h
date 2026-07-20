// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_PIPELINE_PARALLEL_REMESH_PIPELINE_H
#define DIRECTIONAL_PIPELINE_PARALLEL_REMESH_PIPELINE_H

#include <directional/pipeline/RemeshPipeline.h>

namespace directional::pipeline {

inline RemeshResult parallel_remesh_from_raw_cross_field(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    const Eigen::MatrixXd &rawCrossField, RemeshOptions options = {}) {
  options.parallelizeComponents = true;
  return remesh_from_raw_cross_field(vertices, faces, rawCrossField, options);
}

inline RemeshResult parallel_remesh_from_mesh(
    const Eigen::MatrixXd &vertices, const Eigen::MatrixXi &faces,
    RemeshOptions options = {}) {
  options.parallelizeComponents = true;
  return remesh_from_mesh(vertices, faces, options);
}

} // namespace directional::pipeline

#endif // DIRECTIONAL_PIPELINE_PARALLEL_REMESH_PIPELINE_H
