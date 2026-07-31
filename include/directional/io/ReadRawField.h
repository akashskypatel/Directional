// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2018 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_READ_RAW_FIELD_H
#define DIRECTIONAL_READ_RAW_FIELD_H
#include <string>

namespace directional
{

class CartesianField;
class TangentBundle;

/***Reads a raw *extrinsic* cartesian field from a file and initializes a Cartesian file object, including projecting to the intrinsic tangent spaces
 Input:
 fileName:          The to be loaded file.
 tb:                    The underlying tangent bundle to the read field
 Output:
 N:                     The degree of the field
 field:                 The read RAW_FIELD field.
 Return:
 Whether or not the file was read successfully
 ***/
bool read_raw_field(const std::string &fileName,
                           const directional::TangentBundle& tb,
                           int& N,
                           directional::CartesianField& field);
}

#endif
