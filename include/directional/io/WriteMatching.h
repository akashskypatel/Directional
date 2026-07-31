// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2018 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.
#ifndef DIRECTIONAL_WRITE_MATCHING_H
#define DIRECTIONAL_WRITE_MATCHING_H
#include <Eigen/Core>
#include <string>


namespace directional
{
//TODO: this file is not updated to the tangent-bundle paradigm.
/***Writes the vector field matching into a file. For the file format specification see: https://avaxman.github.io/Directional/file_formats/
 Inputs:
 fileName:  The to be loaded file.
 matching:  The matching per edge
 EF:        The edge to face matching
 EV:        The edge to vertices matching
 N:         The degree of the field
 Output:
 Whether or not the file was written successfully
 ***/
bool write_matching(const std::string &fileName,
                           const Eigen::VectorXi& matching,
                           const Eigen::MatrixXi& EF,
                           const Eigen::MatrixXi& EV,
                           const Eigen::MatrixXi& FE,
                           int N);
}

#endif
