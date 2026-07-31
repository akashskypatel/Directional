// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_MESHER_H
#define DIRECTIONAL_MESHING_MESHER_H

#include <Eigen/Core>

#include <directional/core/Export.h>

namespace directional {

class TriMesh;
struct MesherData;

/** @brief Generates polygonal output from prepared integration data. */
DIRECTIONAL_API bool mesher(const TriMesh &origMesh, MesherData &mesherData,
                            Eigen::MatrixXd &outputVertices,
                            Eigen::VectorXi &outputDegrees,
                            Eigen::MatrixXi &outputFaces);

} // namespace directional

#endif // DIRECTIONAL_MESHING_MESHER_H
