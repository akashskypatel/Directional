// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2024 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_BARYCENTRIC_SUBDIVISION_H
#define DIRECTIONAL_BARYCENTRIC_SUBDIVISION_H


#include <Eigen/Core>
#include <vector>

namespace directional
{

//Subdivides a mesh trivially in the middle
void barycentric_subdivision(const Eigen::MatrixXd& V,
                                    const Eigen::MatrixXi& F,
                                    Eigen::MatrixXd& VFine,
                                    Eigen::MatrixXi& FFine);
}




#endif


