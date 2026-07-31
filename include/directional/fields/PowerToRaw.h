// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2018 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_POWER_TO_RAW_H
#define DIRECTIONAL_POWER_TO_RAW_H

#include <numbers>
#include <directional/core/TangentBundle.h>
#include <directional/core/CartesianField.h>

namespace directional
{
// Converts the power complex representation to raw representation.
// Input:
//  powerField: a POWER_FIELD field object
//  N: the degree of the field.
//  normalize: whether to produce a normalized result (length = 1)
// Output:
//  rawField: a RAW_FIELD object representing the (CCW sorted) roots of the power field.
void power_to_raw(const directional::CartesianField& powerField,
                         int N,
                         directional::CartesianField& rawField,
                         bool normalize=false);

}

#endif
