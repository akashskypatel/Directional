// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2022 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#pragma once

#ifndef DIRECTIONAL_CARTESIAN_FIELD_H
#define DIRECTIONAL_CARTESIAN_FIELD_H

#include <iostream>

#include <Eigen/Geometry>
#include <Eigen/Sparse>

#include <directional/core/TangentBundle.h>
#include <directional/util/EigenSparseUtils.h>




/**
 * @file CartesianField.h
 * @brief Cartesian field representation for directional fields on tangent bundles.
 *
 * Defines the in-memory representation used by the field-processing pipeline. A CartesianField stores intrinsic tangent-plane coordinates, synchronized extrinsic coordinates, optional edge matchings, and singularity indices for raw, power, and polyvector field representations.
 */

namespace directional {

/**
 * @brief Storage model used by CartesianField.
 *
 * RAW_FIELD stores the ordered vectors directly. POWER_FIELD and
 * POLYVECTOR_FIELD store polynomial-style representations that are converted
 * through complex intrinsic coordinates.
 */
enum class fieldTypeEnum { RAW_FIELD, POWER_FIELD, POLYVECTOR_FIELD };

/**
 * @brief Directional field values attached to a TangentBundle.
 *
 * The field has degree @ref N, meaning each tangent space stores @ref N vectors
 * or equivalent polynomial coefficients. Intrinsic coordinates are stored in
 * local tangent bases while extrinsic coordinates are stored in ambient xyz
 * coordinates for visualization and downstream meshing.
 */
class CartesianField {
public:
  /// Tangent bundle that owns the tangent spaces used by this field.
  const TangentBundle *tb = nullptr;

  /// Field degree: number of directions or roots per tangent space.
  int N = 0;

  /// Field representation used to interpret @ref intField and @ref extField.
  fieldTypeEnum fieldType = fieldTypeEnum::RAW_FIELD;

  /// Intrinsic tangent-plane coordinates; row count is the number of spaces.
  Eigen::MatrixXd intField;

  /// Ambient xyz coordinates; raw fields use 3 * N columns.
  Eigen::MatrixXd extField;

  /// Edge matching offsets across tangent-bundle adjacencies.
  Eigen::VectorXi matching;

  /// Parallel-transport deviation associated with each matching.
  Eigen::VectorXd effort;

  /// Local dual cycles that contain singularities.
  Eigen::VectorXi singLocalCycles;

  /// Singularity numerators; the fractional index is singIndices / N.
  Eigen::VectorXi singIndices;

  /// Constructs an empty field. Call @ref init before assigning field data.
  CartesianField() = default;

  /// Constructs a field handle attached to an existing tangent bundle.
  explicit CartesianField(const TangentBundle &_tb) : tb(&_tb) {}
  virtual ~CartesianField() = default;

  /**
   * @brief Initializes storage for a field on a tangent bundle.
   * @param _tb Tangent bundle whose tangent spaces define the field domain.
   * @param _fieldType Field representation to allocate.
   * @param _N Field degree.
   */
  void inline init(const TangentBundle &_tb, const fieldTypeEnum _fieldType,
                   const int _N) {
    tb = &_tb;
    fieldType = _fieldType;
    N = _N;
    intField.resize(tb->sources.rows(), 2 * N);
    extField.resize(tb->sources.rows(), 3 * N);
  };

  /**
   * @brief Assigns intrinsic tangent-space coordinates and refreshes extrinsic coordinates.
   * @param _intField Matrix with 2 columns for power fields or 2 * N columns
   *        for raw/polyvector fields.
   * @throws std::invalid_argument if the column count does not match @ref fieldType.
   */
  void inline set_intrinsic_field(const Eigen::MatrixXd &_intField) {
    if (fieldType == fieldTypeEnum::POWER_FIELD && _intField.cols() != 2) {
      throw std::invalid_argument(
          "CartesianField::init(): POWER_FIELD requires _intField to have "
          "exactly 2 columns");
    }

    if ((fieldType == fieldTypeEnum::POLYVECTOR_FIELD ||
         fieldType == fieldTypeEnum::RAW_FIELD) &&
        _intField.cols() != 2 * N) {
      throw std::invalid_argument(
          "CartesianField::init(): RAW_FIELD and POLYVECTOR_FIELD require "
          "_intField to have exactly 2 * N columns");
    }
    intField = _intField;

    extField = tb->project_to_extrinsic(Eigen::VectorXi(), intField);
  }

  /**
   * @brief Assigns intrinsic field values from complex tangent coordinates.
   * @param _intField Complex matrix whose real and imaginary parts become
   *        alternating x/y intrinsic columns.
   */
  void virtual inline set_intrinsic_field(const Eigen::MatrixXcd &_intField) {
    intField.resize(_intField.rows(), _intField.cols() * 2);
    for (int i = 0; i < N; i++) {
      intField.col(2 * i) = _intField.col(i).real();
      intField.col(2 * i + 1) = _intField.col(i).imag();
    }
    set_intrinsic_field(intField);
  }

  /**
   * @brief Assigns ambient xyz field values and projects them into the tangent bundle.
   * @param _extField Either a row-major #spaces-by-(3 * N) matrix or a flattened
   *        column vector with consecutive xyz blocks.
   */
  void inline set_extrinsic_field(const Eigen::MatrixXd &_extField) {
    if (_extField.cols() == 1) {
      extField.resize((_extField.size() / (3 * N)), 3 * N);
      for (int i = 0; i < extField.rows(); i++)
        extField.row(i) = _extField.block(3 * N * i, 0, 3 * N, 1).transpose();
    } else
      extField = _extField;
    intField = tb->project_to_intrinsic(
        Eigen::VectorXi::LinSpaced(static_cast<int>(extField.rows()), 0,
                                   static_cast<int>(extField.rows() - 1)),
        extField);
  }

  /**
   * @brief Returns intrinsic coordinates as complex tangent values.
   * @return Matrix whose columns are x + i y values for each field direction.
   */
  Eigen::MatrixXcd inline get_complex_intrinsic_field() const {
    Eigen::MatrixXcd complexIntField(intField.rows(), intField.cols() / 2);
    for (int i = 0; i < N; i++) {
      complexIntField.col(i).real() = intField.col(2 * i);
      complexIntField.col(i).imag() = intField.col(2 * i + 1);
    }
    return complexIntField;
  }

  /**
   * @brief Flattens a raw field into a single vector.
   * @param isIntrinsic When true, flatten @ref intField; otherwise flatten @ref extField.
   * @return Row-major vector ordered by tangent space, then coefficient.
   * @throws std::invalid_argument if the field is not a raw field.
   */
  Eigen::VectorXd flatten(const bool isIntrinsic = false) const {
    if (fieldType != fieldTypeEnum::RAW_FIELD) {
      throw std::invalid_argument(
          "CartesianField::flatten(): the real method is only good for raw "
          "fields");
    }
    Eigen::MatrixXd field = (isIntrinsic ? intField : extField);
    Eigen::VectorXd vecField(field.rows() * field.cols());
    for (int i = 0; i < field.rows(); i++)
      for (int j = 0; j < field.cols(); j++)
        vecField(i * field.cols() + j) = field(i, j);

    return vecField;
  }

  /**
   * @brief Stores singularity cycles and their integer indices.
   * @param _singLocalCycles Local dual-cycle ids that contain singularities.
   * @param _singIndices Integer numerators for the singularity index.
   *
   * This method records only local dual cycles. Generator and boundary-cycle
   * singularities are represented elsewhere in the topology data.
   */
  void inline set_singularities(const Eigen::VectorXi &_singLocalCycles,
                                const Eigen::VectorXi &_singIndices) {
    singLocalCycles = _singLocalCycles;
    singIndices = _singIndices;
  }
};

} // namespace directional

#endif
