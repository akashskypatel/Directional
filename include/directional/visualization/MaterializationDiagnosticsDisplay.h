// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H
#define DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H

#include <directional/pipeline/RemeshPipeline.h>

#include <Eigen/Core>

#include <iosfwd>

namespace directional::visualization {

/**
 * Display geometry for the retained A5-A7 materialization snapshots.
 *
 * Diagnostic only: positions are the products' double approximations. Nothing
 * here is semantic authority, and no pipeline stage reads it. A product that
 * was not retained leaves its fields empty.
 */
struct MaterializationDiagnosticsDisplay {
  /// A5 corner occurrences, O x 3, in occurrence-complex order.
  Eigen::MatrixXd occurrencePoints;
  /// A5 directed cell sides as rows of occurrencePoints, 4C x 2.
  Eigen::MatrixXi occurrenceSides;
  /// A5 owned relations as rows of occurrencePoints, R x 2.
  Eigen::MatrixXi occurrenceRelations;
  /// A6 quotient-class ordinal of each occurrence, size O; -1 when the
  /// occurrence is in no class or no A6 product was retained.
  Eigen::VectorXi occurrenceClass;
  /// A7 vertex geometry, Q x 3, in A7 order.
  Eigen::MatrixXd geometryPoints;
  /// A7 cells as rows of geometryPoints, C x 4.
  Eigen::MatrixXi geometryQuads;

  bool hasOccurrenceComplex = false;
  bool hasQuotientProduct = false;
  bool hasSourceAttachedGeometry = false;
};

/// Converts the retained snapshots into display geometry.
MaterializationDiagnosticsDisplay materialization_diagnostics_display(
    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots);

/**
 * Writes a line-oriented text dump of the retained snapshots.
 *
 * Each product gets one header line with its counts, or `absent` when it was
 * not retained, followed by one line per occurrence and relation (A5), class
 * (A6) and geometry vertex (A7). Occurrences are written `cell:corner`.
 */
void write_materialization_diagnostics(
    std::ostream &out,
    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots);

} // namespace directional::visualization

#endif // DIRECTIONAL_VISUALIZATION_MATERIALIZATION_DIAGNOSTICS_DISPLAY_H
