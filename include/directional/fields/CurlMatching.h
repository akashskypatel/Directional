// This file is part of Directional, a library for directional field processing.
// Copyright (C) 2018 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can

// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_CURL_MATCHING_H
#define DIRECTIONAL_CURL_MATCHING_H

#include <vector>
#include <cmath>
#include <Eigen/Core>
#include <directional/core/TriMesh.h>
#include <directional/core/CartesianField.h>
#include <directional/fields/FieldMatching.h>
#include <directional/fields/PCFaceTangentBundle.h>

namespace directional
{
// Takes a field in raw form and computes both the curl-matching effort and the consequent curl matching on every tangent-space adjacency.
// Important: if the Raw field in not CCW ordered, the result is meaningless.
// Note: curl is only (future work...) defined for face-based fields.
// Input:
//  rawField:   RAW_FIELD type field
// Output:
//  curlNorm:   L2-norm of the curl vector
//  rawField:   With input field matching, effort, and singularities computed
void curl_matching(directional::CartesianField& rawField,
                          Eigen::VectorXd& curlNorm);
}


#endif


