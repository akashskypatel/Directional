// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2022 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_RAW_TO_POLYVECTOR_H
#define DIRECTIONAL_RAW_TO_POLYVECTOR_H

#include <directional/core/CartesianField.h>
#include <directional/fields/PolyVectorToRaw.h>

namespace directional{

/***Conversion from raw to polyvector representation on a Cartesian field. This operator works directly on the intrinsic representations.
 This computes the polynomial coefficients for the given roots.
 Input:
 intField:                  #TangentSpaces x 2N (x,y,x,y...) representation of the raw intrinsic field
 N:                          Degree of the field.
 signSymmetry:      Whether the field has sign symmetry or not, only if N is even. Default: true
 Output:
 pvField:                   #TangentSpaces x N complex representation of the PolyVector.
 ***/
void raw_to_polyvector(const Eigen::MatrixXd& intField,
                              const int N,
                              Eigen::MatrixXcd& pvField,
                              const bool signSymmetry=true);


void raw_to_polyvector(const CartesianField& rawField,
                              CartesianField& pvField,
                              const bool signSymmetry=true);

}

#endif //DIRECTIONAL_RAW_TO_POLYVECTOR_H
