// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_POLYVECTOR_ITERATION_FUNCTIONS_H
#define DIRECTIONAL_POLYVECTOR_ITERATION_FUNCTIONS_H

#include <cassert>
#include <cmath>
#include <functional>
#include <stdexcept>
#include <iostream>

#include <Eigen/Geometry>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>

#include <directional/core/TangentBundle.h>
#include <directional/fields/IntrinsicVertexTangentBundle.h>
#include <directional/core/CartesianField.h>
#include <directional/fields/PolyVectorToRaw.h>
#include <directional/fields/RawToPolyVector.h>
#include <directional/fields/ProjectCurl.h>
#include <directional/fields/FieldMatching.h>
#include <directional/util/EigenSparseUtils.h>
#include <directional/fields/PolyVectorData.h>

namespace directional{


//This file contains a collection of functions that can be used in the "local" or "projection" steps of the extended polyvector algorithm.

typedef std::function<CartesianField(const CartesianField&, const PolyVectorData&)> PvIterationFunction;
typedef std::function<bool(const CartesianField&, const PolyVectorData&)>           PvTerminationFunction;


//Normalizes the field to have unit length on all its vectors
CartesianField hard_normalization(const CartesianField& pvField, const PolyVectorData& pvData);

//Projects the field into the nearest RoSy field
CartesianField hard_rosy(const CartesianField& pvField, const PolyVectorData& pvData);


//A single implicit step (with the pvData state coefficients) that makes the current field more RoSy.
CartesianField soft_rosy(const CartesianField& pvField, const PolyVectorData& pvData);

//Projects the field onto the nearest curl-free field.
CartesianField curl_projection(const CartesianField& pvField, const PolyVectorData& pvData);

//Projects a vector on a quadric (used for the conjugacy projection)
Eigen::RowVectorXd project_on_quadric(const Eigen::RowVectorXd& y0, const Eigen::MatrixXd& H);

//This is a "no termination" function which is the case by default
bool default_termination(const CartesianField& pvField, const PolyVectorData& pvData);


//Projecting a 2^2 Rosy field to a conjugate field
CartesianField conjugate(const CartesianField& pvField, const PolyVectorData& pvData);

bool conjugate_termination(const CartesianField& pvField, const PolyVectorData& pvData);

}


#endif
