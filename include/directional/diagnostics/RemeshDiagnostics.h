// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_DIAGNOSTICS_REMESH_DIAGNOSTICS_H
#define DIRECTIONAL_DIAGNOSTICS_REMESH_DIAGNOSTICS_H

#include <directional/diagnostics/IntegrationDiagnostics.h>
#include <directional/diagnostics/MesherDiagnostics.h>

namespace directional {

/** @brief Aggregate machine-readable diagnostics for the remesh pipeline. */
struct RemeshDiagnostics {
  double tangentBundleInitializationSeconds = 0.0;
  double fieldSetupSeconds = 0.0;
  double principalMatchingSeconds = 0.0;
  double setupIntegrationSeconds = 0.0;
  double integrationTotalSeconds = 0.0;
  double setupMesherSeconds = 0.0;
  double mesherTotalSeconds = 0.0;
  double overallPipelineSeconds = 0.0;

  IntegrationDiagnostics integration;
  MesherDiagnostics mesher;
};

} // namespace directional

#endif // DIRECTIONAL_DIAGNOSTICS_REMESH_DIAGNOSTICS_H
