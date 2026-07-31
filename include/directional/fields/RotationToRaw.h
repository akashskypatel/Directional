// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2017 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_ROTATION_TO_RAW_H
#define DIRECTIONAL_ROTATION_TO_RAW_H

#include <numbers>
#include <directional/core/CartesianField.h>

namespace directional
{

/*** Converts the rotation angle representation + global rotation to raw format
 Input:
 tb              The tangent bundle on which the field should be defined. The field is initialized with this tangent bundle (by reference!)
 rotationAngles: #E angles that encode deviation from parallel transport EF(i,0)->EF(i,1)
 N:              The degree of the field.
 globalRotation: The angle between the vector on the first face and its basis in radians.
 Output:
 field:          The raw Cartesian field.
 ***/

void rotation_to_raw(const TangentBundle& tb,
                            const Eigen::VectorXd& rotationAngles,
                            const int N,
                            const double globalRotation,
                            directional::CartesianField& field);
}

#endif
