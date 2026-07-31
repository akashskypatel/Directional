// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2022 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_READ_OBJ_H
#define DIRECTIONAL_READ_OBJ_H
#include <string>


namespace directional
{

class TriMesh;

//Reading an OBJ file into a surface TriMesh class.
bool readOBJ(const std::string objFileName,
                    directional::TriMesh& mesh);
}

#endif
