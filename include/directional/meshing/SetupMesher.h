// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_MESHING_SETUP_MESHER_H
#define DIRECTIONAL_MESHING_SETUP_MESHER_H

#include <directional/core/Export.h>

namespace directional {

class TriMesh;
struct IntegrationData;
struct MesherData;

/** @brief Converts integration output into mesher input data. */
DIRECTIONAL_PIPELINE_API void
setup_mesher(const TriMesh &meshCut, const IntegrationData &integrationData,
             MesherData &mesherData);

} // namespace directional

#endif // DIRECTIONAL_MESHING_SETUP_MESHER_H
