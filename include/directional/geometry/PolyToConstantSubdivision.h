// This file is part of Directional, a library for directional field processing.
//
// Copyright (C) 2021 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_POLY_TO_CONSTANT_SUBDIVISION_H
#define DIRECTIONAL_POLY_TO_CONSTANT_SUBDIVISION_H

#include <Eigen/Core>
#include <vector>
#include <directional/fields/PointwiseVectors.h>
#include <directional/core/TriMesh.h>


namespace directional{



//subdividing a mesh with a polynomial field (of order K) into a mesh with a piecewise constant sampled field. Used for visualization alone!
//subdividing 4-1 subdDepth
void poly_to_constant_subdivision(const TriMesh& mesh,
                                         const Eigen::MatrixXd& rawField,
                                         const int K,
                                         const int subdDepth,
                                         TriMesh& subdMesh,
                                         Eigen::VectorXi& FFK,
                                         Eigen::MatrixXd& rawFieldK);




}


#endif /* poly_to_constant_subdivision_h */
