// This file is part of Directional, a library for directional field processing.
//
// Copyright (C) 2024 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_PROJECT_CURL
#define DIRECTIONAL_PROJECT_CURL

#include <Eigen/Core>
#include <vector>
#include <set>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/core/CartesianField.h>
#include <directional/operators/CurlMatrices.h>
#include <directional/util/SparseBlock.h>
#include <directional/operators/ExtrinsicIntrinsicMatrices.h>

namespace directional {

void gradient_descent(const Eigen::SparseMatrix<double>& A,
                             const Eigen::VectorXd& gradMasses,
                             const Eigen::VectorXd& b,
                             const Eigen::VectorXd& initx,
                             const double tol,
                             const int maxIterations,
                             Eigen::VectorXd& resultx);


//This only works with face based raw fields, with a given matching
//Reducing the curl of a field by solving for the closest raw field that is curl free.
//the optional objMatrix is in case we want to minimize an objective (default: closeness)
//The optional reducMatrix is if the field has reduced degrees of freedom (for instance, symmetry). We have that field = reducMatrix*trueDofField
//Currently hard constraints are ignored
void project_curl(const CartesianField& origField,
                         const Eigen::VectorXi& constFaces,   //these are only in case of hard constraints, otherwise leave empty (soft constraints should be baked into objMatrix
                         const Eigen::MatrixXd& constVectors,
                         CartesianField& curlFreeField,
                         const Eigen::SparseMatrix<double>& objMatrix=Eigen::SparseMatrix<double>(),
                         const Eigen::VectorXd& objRhs=Eigen::VectorXd(),
                         const Eigen::SparseMatrix<double>& reducMatrix = Eigen::SparseMatrix<double>());
};


#endif
