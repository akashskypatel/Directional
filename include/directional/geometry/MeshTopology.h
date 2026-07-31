// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_GEOMETRY_MESH_TOPOLOGY_H
#define DIRECTIONAL_GEOMETRY_MESH_TOPOLOGY_H

#include <numbers>
#include <set>
#include <unordered_map>
#include <vector>

#include <Eigen/Core>

#include <directional/core/TriMesh.h>

#include <directional/util/EigenIndexUtils.h>
#include <directional/util/GraphUtils.h>


/**
 * @file MeshTopology.h
 * @brief Topology construction routines for primal and dual mesh cycles.
 *
 * Builds polygonal edge topology and cycle bases used by tangent bundles, field matching, integration constraints, and boundary handling.
 */

namespace directional {

/// @brief Initialize Edges and their topological relations
/// @param D eigen int vector     #F by 1 - face degrees
/// @param F eigen int matrix     #F by max(D) - vertex indices in face
/// @param EV #E by 2, Stores the edge description as pair of indices to
/// vertices
/// @param FE : #F by max(D), Stores the Face-Edge relation
/// @param EF : #E by 2: Stores the Edge-Face relation
/// @param EFi: #E by 2: corresponding to EF and stores the relative position of
/// the edge in the face (e.g., if the edge is (v1,v2) and the face has
/// (vx,vy,v2,v1,vz,va), then the value is 2) FEs: #F by max(D): if the edge is
/// oriented positively or negatively in the face (e.g. in the example above we
/// get -1) InnerEdges: indices into EV of which edges are internal (not
/// boundary)
void polygonal_edge_topology(const Eigen::VectorXi &D,
                                    const Eigen::MatrixXi &F,
                                    Eigen::MatrixXi &EV, Eigen::MatrixXi &FE,
                                    Eigen::MatrixXi &EF, Eigen::MatrixXi &EFi,
                                    Eigen::MatrixXd &FEs,
                                    Eigen::VectorXi &InnerEdges);

/// @brief Creates the set of independent dual cycles (closed loops of connected
/// faces that cannot be morphed to each other) on a mesh. Primarily used for
/// index prescription. The basis cycle matrix first contains #V-#b cycles for
/// every inner vertex (by order), then #b boundary cycles, and finally 2*g
/// generator cycles around all handles. Total #c cycles.The cycle matrix sums
/// information on the dual edges between the faces, and is indexed into the
/// inner edges alone (excluding boundary)
/// @param mesh TriMesh &mesh: #V by 3 vertices.
/// @param basisCycles #c by #iE basis cycles
/// @param cycleCurvature #c by 1 curvatures of each cycle (for inner-vertex
/// cycles, simply the Gaussian curvature. vertex2cycle:     #v by 1 map between
/// vertex and corresponding cycle (for comfort of input from the user's side;
/// inner vertices map to their cycles, boundary vertices to the bigger boundary
/// cycle. innerEdges:       #iE by 1 the subset of #EV that are inner edges,
/// and with the same ordering as the columns of basisCycles.
void dual_cycles(const TriMesh &mesh,
                        Eigen::SparseMatrix<double> &basisCycles,
                        Eigen::VectorXd &cycleCurvature,
                        Eigen::VectorXi &vertex2cycle,
                        Eigen::VectorXi &innerEdges);

} // namespace directional

#endif // DIRECTIONAL_GEOMETRY_MESH_TOPOLOGY_H
