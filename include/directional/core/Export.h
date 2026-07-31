// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_CORE_EXPORT_H
#define DIRECTIONAL_CORE_EXPORT_H

#if defined(_WIN32) && defined(DIRECTIONAL_SHARED)
#if defined(DIRECTIONAL_BUILDING_LIBRARY)
#define DIRECTIONAL_API __declspec(dllexport)
#else
#define DIRECTIONAL_API __declspec(dllimport)
#endif
#elif defined(__GNUC__) && defined(DIRECTIONAL_BUILDING_LIBRARY)
#define DIRECTIONAL_API __attribute__((visibility("default")))
#else
#define DIRECTIONAL_API
#endif

#endif // DIRECTIONAL_CORE_EXPORT_H
