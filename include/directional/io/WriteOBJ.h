// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2024 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef DIRECTIONAL_WRITE_OBJ_H
#define DIRECTIONAL_WRITE_OBJ_H


#include <Eigen/Core>
#include <string>


namespace directional
{

class TriMesh;

/***Writing an OBJ file
Input:
fileName:     Name of file
mesh:         Surface mesh
TC:           Texture coordinates
FTC:          Per face (so |F|x3) indices into TC to associate texture to corners
mtlFileName:  name of MTL file that associates with the texture
textureName:  texture name inside the MTL file.
***/

bool writeOBJ(const std::string& fileName,
              const directional::TriMesh& mesh,
              const Eigen::MatrixXd& TC,
              const Eigen::MatrixXi& FTC,
              const std::string& mtlFileName = "",
              const std::string& textureName = "");
}

#endif
