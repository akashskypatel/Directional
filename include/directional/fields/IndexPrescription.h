// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2018 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_INDEX_PRESCRIPTION_H
#define DIRECTIONAL_INDEX_PRESCRIPTION_H

#include <Eigen/Core>
#include <vector>
#include <cmath>
#include <numbers>
#include <directional/core/CartesianField.h>
#include <directional/fields/RotationToRaw.h>


namespace directional
{
// Computes the rotation angles that are required to reproduce a prescribed set of indices on the dual cycles of the mesh.
// In case the sum of curvature is not consistent with the topology, the system is solved in least squares and unexpected singularities may appear elsewhere. linfError will mostl like be far from zero.
// Input:
//  cycleIndices:   a prescribed index per cycle (either local, generator, or boundary). This must it the cycles in the type of the field.
//  N:              degree of the field
//  globalRotation: the orientation of the directional in the first tangent space (mostly arbitrary)
//  ldltSolver:     Since index prescription can benefit from prefactoring, this is an option to give the already-factored solver.
//  field:          Cartesian field object.
// Output:
//  rotationAngles: #adjSpaces rotation angles (difference from parallel transport) per inner space adjacency relation
//  linfError:      l_infinity error of the computation. If this is not approximately 0, the prescribed indices are likely inconsistent (don't add up to the correct sum).
void index_prescription(const Eigen::VectorXi& cycleIndices,
                               const int N,
                               const double globalRotation,
                               Eigen::SimplicialLDLT<Eigen::SparseMatrix<double> >& ldltSolver,
                               directional::CartesianField& field,
                               Eigen::VectorXd& rotationAngles,
                               double &linfError);

//Minimal version: without a provided solver
void index_prescription(const Eigen::VectorXi& cycleIndices,
                               const int N,
                               const double globalRotation,
                               directional::CartesianField& field,
                               Eigen::VectorXd& rotationAngles,
                               double &error);
}



#endif


