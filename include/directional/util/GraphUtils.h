// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_UTIL_GRAPH_UTILS_H
#define DIRECTIONAL_UTIL_GRAPH_UTILS_H

#include <Eigen/Core>


/**
 * @file GraphUtils.h
 * @brief Graph traversal helpers.
 *
 * Contains a breadth-first spanning-tree construction routine for edge-list graphs.
 */

namespace directional {

/// @brief Creates a tree from a graph given by the edges in EV
/// @param EV #E by 2 list of edges in the graph
/// @param tE #Te vector of edges (within EV) in the graph
/// @param tEf #V the edges leading to each vertex. -1 for the root
void tree(const Eigen::MatrixXi &EV, Eigen::VectorXi &tE,
          Eigen::VectorXi &tEf);

} // namespace directional

#endif
