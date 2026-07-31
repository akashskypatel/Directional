// This file is part of Directional, a library for directional field processing.
//
// Copyright (C) 2021 Amir Vaxman <avaxman@gmail.com>
//
// This Source Code Form is subject to the terms of the Mozilla Public License
// v. 2.0. If a copy of the MPL was not distributed with this file, You can
// obtain one at http://mozilla.org/MPL/2.0/.

#ifndef DIRECTIONAL_POINTWISE_VECTORS_H
#define DIRECTIONAL_POINTWISE_VECTORS_H

#include <Eigen/Core>
#include <vector>
#include <directional/core/TriMesh.h>
#include <directional/fields/PolyVectorToRaw.h>
#include <directional/geometry/BarycentricCoordinates.h>


namespace directional{

//This function interpolates vectors inside each face from the polynomial dofs


/*IGL_INLINE void multiply_polynomials(Eigen::RowVectorXcd& p1,
 const Eigen::RowVectorXcd& p2)
 {
 Eigen::RowVectorXcd newp = Eigen::RowVectorXcd::Zero(p1.size()+p2.size());
 for (int i=0;i<p1.size();i++)
 for (int j=0;j<p2.size();j++)
 newp(i+j)+=p1(i)*p2(j);
 
 p1 =newp;
 }*/


void raw_to_polyvector_polynomial(const Eigen::MatrixXd& V,
                                         const Eigen::MatrixXi& F,
                                         const Eigen::MatrixXd& B1,
                                         const Eigen::MatrixXd& B2,
                                         const int N,
                                         const int K,
                                         const Eigen::MatrixXd& rawField,
                                         Eigen::MatrixXcd& pvField);


void pointwise_vectors(const TriMesh& mesh,
                              const Eigen::VectorXi& faces,
                              const Eigen::MatrixXd& locations,
                              const Eigen::MatrixXd& rawField,
                              const int order,
                              Eigen::MatrixXd& interpField);
}



#endif
