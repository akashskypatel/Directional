// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_CORE_LIBRARY_H
#define DIRECTIONAL_CORE_LIBRARY_H

#include <directional/core/Export.h>

/** @brief Returns a stable description of the linked Directional library. */
extern "C" DIRECTIONAL_API const char *directional_build_info();

#endif // DIRECTIONAL_CORE_LIBRARY_H
