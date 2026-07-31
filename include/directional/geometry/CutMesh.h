// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_INTEGRATION_CUT_MESH_H
#define DIRECTIONAL_INTEGRATION_CUT_MESH_H

#include <set>
#include <vector>

#include <Eigen/Core>


namespace directional {
class TriMesh;
} // namespace directional

/**
 * @file CutMesh.h
 * @brief Mesh cutting utilities driven by singularities and matching.
 *
 * Cuts a mesh along selected halfedges so that field singularities and branch cuts can be represented as an explicitly cut triangle mesh.
 */

namespace directional {

/**
 * @brief Computes a face-edge cut mask that opens a mesh around singularities.
 * @param mesh Source mesh with populated DCEL and face adjacency data.
 * @param singularities Vertex ids that must lie on the cut boundary.
 * @param face2cut Output #F-by-3 matrix; nonzero entries mark face edges to cut.
 *
 * The routine builds a spanning disk by flood filling across dual edges, then
 * retracts valence-one cut branches that do not terminate at singularities. The
 * output uses the source mesh's per-face edge ordering.
 */
void cut_mesh_with_singularities(const TriMesh &mesh,
                                 const Eigen::VectorXi &singularities,
                                 Eigen::MatrixXi &face2cut);

}; // namespace directional

#endif
