// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_GENERATE_MESH_H
#define DIRECTIONAL_MESHING_GENERATE_MESH_H

#include <algorithm>
#include <array>
#include <cmath>
#include <cstdint>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <queue>
#include <set>
#include <stdexcept>
#include <unordered_map>
#include <utility>
#include <vector>

#include <Eigen/Dense>
#include <Eigen/Sparse>

#include <directional/core/DCEL.h>
#include <directional/meshing/NFunctionMesher.h>
#include <directional/numerics/ExactGeometry.h>


/**
 * @file GenerateMesh.h
 * @brief Mesh generation implementation for integrated N-functions.
 *
 * Contains the implementation steps that trace integer isolines, arrange segments inside triangles, simplify the arrangement, and emit the final remeshed output.
 */

namespace directional {


} // namespace directional

#endif // DIRECTIONAL_MESHING_GENERATE_MESH_H
