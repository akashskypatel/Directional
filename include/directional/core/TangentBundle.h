// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2022 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_TANGENT_BUNDLE_H
#define DIRECTIONAL_TANGENT_BUNDLE_H

#include <cassert>
#include <iostream>

#include <Eigen/Geometry>
#include <Eigen/Sparse>

#include <directional/core/TriMesh.h>




/**
 * @file TangentBundle.h
 * @brief Base tangent-bundle abstraction for discrete tangent spaces.
 *
 * Stores tangent spaces, adjacency, connection data, mass matrices, local cycles, and basis cycles. Derived classes implement the source-specific geometry needed to project vectors between intrinsic and extrinsic coordinates.
 */

namespace directional {

/** @brief Concrete tangent-bundle discretization kind. */
enum class discTangTypeEnum { BASE_CLASS, FACE_SPACES, VERTEX_SPACES };

/** @brief Boundary condition type used when building curl constraints. */
enum class boundCondTypeEnum { DIRICHLET, NEUMANN };

/**
 * @brief Interface for discrete tangent bundles.
 *
 * A tangent bundle is represented as a graph whose nodes are tangent spaces and
 * whose edges are adjacency relations. It stores the connection, cycles, masses,
 * and optional embedding data needed by field matching, integration, and
 * visualization.
 */
class TangentBundle {
public:
  /**
   * @brief Returns the concrete tangent-bundle discretization.
   * @return The bundle kind; base class returns BASE_CLASS.
   */
  virtual discTangTypeEnum discTangType() const {
    return discTangTypeEnum::BASE_CLASS;
  }

  /** @brief Returns whether this bundle can project between intrinsic and extrinsic coordinates. */
  virtual bool hasEmbedding() const { return false; }

  /// Intrinsic dimension of each tangent space.
  int intDimension = 0;

  /// Number of tangent spaces in the bundle graph.
  int numSpaces = 0;

  /// Adjacent tangent-space pairs; boundary rows use -1 on the missing side.
  Eigen::Matrix<int, Eigen::Dynamic, 2> adjSpaces;

  /// Ordered tangent-space one-rings around each tangent space.
  Eigen::MatrixXi oneRing;

  /// Row indices in @ref adjSpaces that refer to interior adjacencies.
  Eigen::VectorXi innerAdjacencies;

  /// Cycle-edge incidence matrix used for holonomy and singularity analysis.
  Eigen::SparseMatrix<double> cycles;

  /// Integrated curvature associated with each cycle.
  Eigen::VectorXd cycleCurvatures;

  /// Mapping from local cycles to the global cycle list.
  Eigen::VectorXi local2Cycle;

  /// Complex metric connection between adjacent tangent spaces.
  Eigen::VectorXcd connection;

  /// Mass matrix over tangent-bundle adjacencies.
  Eigen::SparseMatrix<double> connectionMass;

  /// Inner-product mass matrix over tangent-space vector values.
  Eigen::SparseMatrix<double> tangentSpaceMass;

  /// Inverse of @ref tangentSpaceMass when assembled by a concrete bundle.
  Eigen::SparseMatrix<double> invTangentSpaceMass;

  /// Average geometric length across tangent-space adjacencies.
  double avgAdjLength = 0.0;

  /// Source point for each embedded tangent space.
  Eigen::MatrixXd sources;

  /// Normal for each embedded tangent space.
  Eigen::MatrixXd normals;

  /// Source point associated with each cycle.
  Eigen::MatrixXd cycleSources;

  /// Normal associated with each cycle.
  Eigen::MatrixXd cycleNormals;

  /// Constructs an empty tangent bundle.
  TangentBundle() = default;
  virtual ~TangentBundle() = default;

  /**
   * @brief Projects ambient vectors into local tangent-space coordinates.
   * @param sourceIndices Tangent-space indices for each row, or an empty vector
   *        when the implementation can infer all rows.
   * @param extField Ambient vector values, usually with xyz blocks.
   * @return Intrinsic two-dimensional coordinates in local tangent bases.
   * @throws std::logic_error in the base class because no embedding exists.
   */
  Eigen::MatrixXd virtual inline project_to_intrinsic(
      const Eigen::VectorXi &, const Eigen::MatrixXd &) const {
    throw std::logic_error("TangentBundle::project_to_intrinsic(): base "
                           "tangent bundle has no embedding");
  }

  /**
   * @brief Projects intrinsic tangent coordinates into ambient coordinates.
   * @param sourceIndices Tangent-space indices for each row, or empty for all rows.
   * @param intField Intrinsic coordinates in local tangent bases.
   * @return Ambient xyz vector values.
   * @throws std::logic_error in the base class because no embedding exists.
   */
  Eigen::MatrixXd virtual inline project_to_extrinsic(
      const Eigen::VectorXi &, const Eigen::MatrixXd &) const {
    throw std::logic_error("TangentBundle::project_to_extrinsic(): base "
                           "tangent bundle has no embedding");
  }

  /**
   * @brief Interpolates field values at positions described by barycentric data.
   *
   * Concrete bundles define how interpolation elements and coordinates are
   * interpreted. The base implementation returns empty matrices.
   */
  void virtual inline interpolate(const Eigen::MatrixXi &,
                                  const Eigen::MatrixXd &,
                                  const Eigen::MatrixXd &,
                                  Eigen::MatrixXd &interpSources,
                                  Eigen::MatrixXd &interpNormals,
                                  Eigen::MatrixXd &interpField) const {
    interpSources = Eigen::MatrixXd();
    interpNormals = Eigen::MatrixXd();
    interpField = Eigen::MatrixXd();
  }

  /**
   * @brief Builds a sparse curl matrix for scalar functions on this bundle.
   * @param boundaryCondition Boundary behavior requested by the caller.
   * @param constrainedCycles Optional cycle ids constrained by the caller.
   * @param localCyclesOnly Whether to assemble only local cycle constraints.
   * @return Sparse curl matrix; base implementation returns an empty matrix.
   */
  Eigen::SparseMatrix<double> virtual inline curl_matrix(
      const boundCondTypeEnum, const Eigen::VectorXi &,
      const bool = false) const {
    return Eigen::SparseMatrix<double>();
  }
};

} // namespace directional

#endif
