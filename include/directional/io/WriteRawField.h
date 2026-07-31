// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2018 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef DIRECTIONAL_WRITE_RAW_FIELD_H
#define DIRECTIONAL_WRITE_RAW_FIELD_H

#include <string>

namespace directional
{

class CartesianField;

/*** Writes the extrinsic embedding of a directional field in raw format to file
 Input:
 filename:           The name used for the mesh and singularity file, without extention
 rawField:           Cartesian raw field of any tangent bundle type
 high_precision: if true the numerical precision is set to std::numeric_limits<double>::digits10 + 1, and the output is written in the scientific format
 Output:
 Whether or not the file was written successfully
 ***/
bool write_raw_field(const std::string fileName,
                            const directional::CartesianField& rawField,
                            bool high_precision = false);
}

#endif
