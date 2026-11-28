// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2025 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#include <directional/visualization/MaterializationDiagnosticsDisplay.h>

#include <iomanip>
#include <map>
#include <ostream>

namespace directional::visualization {
namespace {

using OccurrenceRows = std::map<authority::OccurrenceId, int>;

OccurrenceRows
occurrence_rows(const pipeline::SurfaceOccurrenceComplex &complex) {
  OccurrenceRows rows;
  for (std::size_t row = 0; row < complex.occurrences().size(); ++row) {
    rows.emplace(complex.occurrences()[row].id, static_cast<int>(row));
  }
  return rows;
}

std::ostream &write_occurrence(std::ostream &out,
                               const authority::OccurrenceId &occurrence) {
  return out << occurrence.cell().index() << ':'
             << static_cast<int>(occurrence.canonical_corner_role());
}

std::ostream &write_position(std::ostream &out, const double x, const double y,
                             const double z) {
  return out << x << ' ' << y << ' ' << z;
}

} // namespace

MaterializationDiagnosticsDisplay materialization_diagnostics_display(
    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots) {
  MaterializationDiagnosticsDisplay display;
  OccurrenceRows rows;
  if (const auto &complex = snapshots.occurrenceComplex) {
    display.hasOccurrenceComplex = true;
    rows = occurrence_rows(*complex);
    const auto &occurrences = complex->occurrences();
    display.occurrencePoints.resize(
        static_cast<Eigen::Index>(occurrences.size()), 3);
    for (std::size_t row = 0; row < occurrences.size(); ++row) {
      display.occurrencePoints.row(static_cast<Eigen::Index>(row)) =
          occurrences[row].point.position.transpose();
    }
    const auto &cells = complex->cells();
    display.occurrenceSides.resize(static_cast<Eigen::Index>(4 * cells.size()),
                                   2);
    for (std::size_t cell = 0; cell < cells.size(); ++cell) {
      for (std::size_t side = 0; side < 4; ++side) {
        const auto &[from, to] = cells[cell].directedSides[side];
        const auto edge = static_cast<Eigen::Index>(4 * cell + side);
        display.occurrenceSides(edge, 0) = rows.at(from);
        display.occurrenceSides(edge, 1) = rows.at(to);
      }
    }
    const auto &relations = complex->owned_relations();
    display.occurrenceRelations.resize(
        static_cast<Eigen::Index>(relations.size()), 2);
    for (std::size_t relation = 0; relation < relations.size(); ++relation) {
      const auto row = static_cast<Eigen::Index>(relation);
      display.occurrenceRelations(row, 0) =
          rows.at(relations[relation].firstOccurrence);
      display.occurrenceRelations(row, 1) =
          rows.at(relations[relation].secondOccurrence);
    }
    display.occurrenceClass = Eigen::VectorXi::Constant(
        static_cast<Eigen::Index>(occurrences.size()), -1);
  }
  if (const auto &quotient = snapshots.quotientProduct) {
    display.hasQuotientProduct = true;
    if (display.hasOccurrenceComplex) {
      const auto &classes = quotient->classes();
      for (std::size_t ordinal = 0; ordinal < classes.size(); ++ordinal) {
        for (const auto &member : classes[ordinal].members) {
          display.occurrenceClass(rows.at(member)) = static_cast<int>(ordinal);
        }
      }
    }
  }
  if (const auto &geometry = snapshots.sourceAttachedGeometry) {
    display.hasSourceAttachedGeometry = true;
    const auto &vertices = geometry->vertices();
    std::map<pipeline::SurfaceQuotientClassId, int> vertexRows;
    display.geometryPoints.resize(static_cast<Eigen::Index>(vertices.size()),
                                  3);
    for (std::size_t row = 0; row < vertices.size(); ++row) {
      vertexRows.emplace(vertices[row].quotientClass, static_cast<int>(row));
      display.geometryPoints.row(static_cast<Eigen::Index>(row)) =
          vertices[row].position;
    }
    const auto &cells = geometry->topology();
    display.geometryQuads.resize(static_cast<Eigen::Index>(cells.size()), 4);
    for (std::size_t cell = 0; cell < cells.size(); ++cell) {
      for (std::size_t corner = 0; corner < 4; ++corner) {
        display.geometryQuads(static_cast<Eigen::Index>(cell),
                              static_cast<Eigen::Index>(corner)) =
            vertexRows.at(cells[cell].corners[corner]);
      }
    }
  }
  return display;
}

void write_materialization_diagnostics(
    std::ostream &out,
    const pipeline::SurfaceCellDiagnosticProductSnapshots &snapshots) {
  const auto precision = out.precision(17);
  if (const auto &complex = snapshots.occurrenceComplex) {
    out << "A5 occurrence-complex cells=" << complex->cells().size()
        << " occurrences=" << complex->occurrences().size()
        << " relations=" << complex->owned_relations().size() << '\n';
    for (const auto &occurrence : complex->occurrences()) {
      write_occurrence(out << "occurrence ", occurrence.id)
          << " face=" << occurrence.point.face << " position=";
      write_position(out, occurrence.point.position.x(),
                     occurrence.point.position.y(),
                     occurrence.point.position.z())
          << '\n';
    }
    for (const auto &relation : complex->owned_relations()) {
      write_occurrence(out << "relation ", relation.firstOccurrence) << ' ';
      write_occurrence(out, relation.secondOccurrence) << '\n';
    }
  } else {
    out << "A5 occurrence-complex absent\n";
  }
  if (const auto &quotient = snapshots.quotientProduct) {
    out << "A6 quotient-product classes=" << quotient->classes().size()
        << " classed-cells=" << quotient->classed_cells().size() << '\n';
    for (std::size_t ordinal = 0; ordinal < quotient->classes().size();
         ++ordinal) {
      out << "class " << ordinal << " members";
      for (const auto &member : quotient->classes()[ordinal].members) {
        write_occurrence(out << ' ', member);
      }
      out << '\n';
    }
  } else {
    out << "A6 quotient-product absent\n";
  }
  if (const auto &geometry = snapshots.sourceAttachedGeometry) {
    out << "A7 source-attached-geometry vertices="
        << geometry->vertices().size()
        << " cells=" << geometry->topology().size() << '\n';
    for (const auto &vertex : geometry->vertices()) {
      write_occurrence(out << "vertex ", vertex.representative) << " position=";
      write_position(out, vertex.position.x(), vertex.position.y(),
                     vertex.position.z())
          << '\n';
    }
  } else {
    out << "A7 source-attached-geometry absent\n";
  }
  out.precision(precision);
}

} // namespace directional::visualization
