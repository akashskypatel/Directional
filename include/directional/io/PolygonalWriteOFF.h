// This file is part of libhedra, a library for polyhedral mesh processing
//
// Copyright (C) 2016 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef HEDRA_POLYGONAL_WRITE_OFF_H
#define HEDRA_POLYGONAL_WRITE_OFF_H
#include <Eigen/Core>
#include <string>

namespace hedra
{
  // writes a polygonal mesh as an ascii OFF file
  // Inputs:
  //   str  path to .off file
  //  V  eigen double matrix  #V by 3 - vertex coordinates
  //  D  eigen int vector     #F by 1 - face degrees
  //  F  eigen int matrix     #F by max(D) - vertex indices in face
bool polygonal_write_OFF(const std::string& str,
                                      const Eigen::MatrixXd& V,
                                      const Eigen::VectorXi& D,
                                      const Eigen::MatrixXi& F);
}


#endif

