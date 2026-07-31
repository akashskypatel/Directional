// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2021 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_POLYVECTOR_FIELD_H
#define DIRECTIONAL_POLYVECTOR_FIELD_H

#include <Eigen/Geometry>
#include <Eigen/Sparse>
#include <Eigen/SparseCholesky>
#include <Eigen/Eigenvalues>
#include <unsupported/Eigen/Polynomials>
#include <iostream>
#include <directional/core/TangentBundle.h>
#include <directional/core/CartesianField.h>
#include <directional/fields/PolyVectorToRaw.h>
#include <directional/fields/RawToPolyVector.h>
#include <directional/fields/FieldMatching.h>
#include <directional/util/EigenSparseUtils.h>
#include <directional/fields/PolyVectorIteration.h>
#include <directional/fields/PolyVectorData.h>

namespace directional
{


// Precalculate the operators needed for PolyVector computation according to the user-prescribed parameters. Must be called whenever any of them changes
// Input:
//  pvField: POLYVECTOR_FIELD cartesian field initalized with the tangent bundle
//  pvData: the details of the algorithm
//
// Output:
//  pvField: the computer field (returned in the input parameter)
//  pvData:  Updated structure with all operators
void polyvector_precompute(directional::CartesianField& pvField,
                                  PolyVectorData& pvData);


// Computes a polyvector field on the entire mesh, where precomputation has taken place.
// Inputs:
//  PolyVectorData: The data structure which should have been initialized with polyvector_precompute()
// Outputs:
//  pvField: a POLYVECTOR_FIELD type cartesian field object
void polyvector_field(PolyVectorData& pvData,
                             directional::CartesianField& pvField);


// Computes iterations of the extended PolyVector algorithm, which includes a single implicit step and running the set of projection iteration functions by order once.
// Inputs:
//  pvData: The data structure which should have been initialized with polyvector_precompute()
//  pvField: The current POLYVECTOR_FIELD type cartesian field object
//  iterationFunctions: the iteration functions, as objects of type PvIterationFunction (see examples in polyvector_iteration_functions.h)
//  terminationFUnction: the function that determines if to terminate iterations by some condition.
//  numIterations: how many iterations (of everyting) to run
// Outputs:
//  pvField: a POLYVECTOR_FIELD type cartesian field object
void polyvector_iterate(PolyVectorData& pvData,
                               directional::CartesianField& pvField,
                               const std::vector<directional::PvIterationFunction> iterationFunctions,
                               const int numIterations = 1,
                               const directional::PvTerminationFunction terminationFunction = directional::default_termination);

}

#endif
