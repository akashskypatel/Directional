// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2020 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_POLYVECTOR_TO_RAW_H
#define DIRECTIONAL_POLYVECTOR_TO_RAW_H

#include <iostream>
#include <numbers>
#include <Eigen/Geometry>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>
#include <Eigen/Eigenvalues>
#include <directional/core/TriMesh.h>
#include <directional/core/CartesianField.h>


namespace directional {


//Aiding functions

void multiply_polynomials(Eigen::RowVectorXcd &p1,
                                 const Eigen::RowVectorXcd &p2);

void multiply_polynomials(Eigen::MatrixXcd &p1,
                                 const Eigen::MatrixXcd &p2);

void polynomial_eval_from_roots(const Eigen::RowVectorXcd &roots,
                                       const std::complex<double> &evalPoint,
                                       std::complex<double> &polyValue);

void polynomial_eval_from_roots(const Eigen::MatrixXcd &roots,
                                       const Eigen::VectorXcd &evalPoints,
                                       Eigen::VectorXcd &polyValues);

void polynomial_eval(const Eigen::RowVectorXcd &coeffs,
                            const std::complex<double> &evalPoint,
                            std::complex<double> &polyValue);

void polynomial_eval(const Eigen::MatrixXcd &coeffs,
                            const Eigen::VectorXcd &evalPoints,
                            Eigen::VectorXcd &polyValues);


// Converts a field in PolyVector representation to raw represenation. This is done by the fixed-point Durand-Kerner method.
// Input:
//  pvField:    a POLYVECTOR_FIELD type cartesian field object
//  signSymmetry: if the field is sign-symmetric (so comprising line-fields). Then all odd PV coefficients are zero.
//  rootTolerance:  the numerical tolerance for the root computation.
//
// Output:
//  roots:              #TangentSpaces by N complex matrix with all N roots of the PolyVectors in order
//    returns true if succeeded
bool polyvector_to_raw(const Eigen::MatrixXd& pvField,
                              const int N,
                              Eigen::MatrixXcd &roots,
                              const bool _signSymmetry = true,
                              const bool normalizeRoots = false,
                              const double rootTolerance = 1e-8);

// Converts a field in PolyVector representation to raw represenation. This is done by the fixed-point Durand-Kerner method.
// Input:
//  pvField:                a POLYVECTOR_FIELD type cartesian field object
//  signSymmetry:           if the field is sign-symmetric (so comprising line-fields). Then all odd PV coefficients are zero.
//  rootTolerance:          the numerical tolerance for the root computation.
//
// Output:
//  rawField:               #the outpur Cartesian field in raw representation
//    returns true if succeeded
bool polyvector_to_raw(const directional::CartesianField &pvField,
                              directional::CartesianField &rawField,
                              const bool signSymmetry = true,
                              const bool normalizeRoots = false,
                              const double rootTolerance = 1e-8);

}

#endif
