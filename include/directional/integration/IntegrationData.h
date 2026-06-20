
#pragma once

#ifndef DIRECTIONAL_INTEGRATION_INTEGRATION_DATA_H
#define DIRECTIONAL_INTEGRATION_INTEGRATION_DATA_H

#include <Eigen/Core>
#include <Eigen/Sparse>

namespace directional
{
//The data structure for seamless integration
struct IntegrationData
{
    int N;                                              // # uncompressed parametric functions
    int n;                                              // # independent parameteric functions
    Eigen::MatrixXi linRed;                             // Linear Reduction tying the n dofs to the full N
    Eigen::MatrixXi periodMat;                          // Function spanning integers
    Eigen::SparseMatrix<double> vertexTrans2CutMat;     // Map between the whole mesh (vertex + translational jump) representation to the vertex-based representation on the cut mesh
    Eigen::SparseMatrix<double> constraintMat;          // Linear constraints (resulting from non-singular nodes)
    Eigen::SparseMatrix<double> linRedMat;              // Global uncompression of n->N
    Eigen::SparseMatrix<double> intSpanMat;             // Spanning the translational jump lattice
    Eigen::SparseMatrix<double> singIntSpanMat;         // Layer for the singularities
    Eigen::VectorXi constrainedVertices;                // Constrained vertices (fixed points in the parameterization)
    Eigen::VectorXi integerVars;                        // Variables that are to be rounded.
    Eigen::MatrixXi face2cut;                           // |F|x3 map of which edges of faces are seams
    Eigen::VectorXd nVertexFunction;                    // Final compressed result (used for meshing)
    
    Eigen::VectorXi fixedIndices;                       // Translation fixing indices
    Eigen::VectorXd fixedValues;                        // Translation fixed values
    Eigen::VectorXi singularIndices;                    // Singular-vertex indices
    
    //integer versions, for exact seamless parameterizations (good for error-free meshing)
    Eigen::SparseMatrix<int> vertexTrans2CutMatInteger;
    Eigen::SparseMatrix<int> constraintMatInteger;
    Eigen::SparseMatrix<int> linRedMatInteger;
    Eigen::SparseMatrix<int> intSpanMatInteger;
    Eigen::SparseMatrix<int> singIntSpanMatInteger;
    
    double lengthRatio;                                 // Global scaling of functions
    //Flags
    bool integralSeamless;                              // Whether to do full translational seamless.
    bool roundSeams;                                    // Whether to round seams or round singularities
    bool verbose;                                       // Output the integration log.
    
    IntegrationData(int _N):lengthRatio(0.02), integralSeamless(false), roundSeams(true), verbose(false){
        N=_N;
        n=(N%2==0 ? N/2 : N);
        if (N%2==0)
            set_sign_symmetry(N);
        else linRed=Eigen::MatrixXi::Identity(N,n);
        set_default_period_matrix(n);
    }
    ~IntegrationData(){}
    
    inline void set_linear_reduction(const Eigen::MatrixXi& _linRed, const Eigen::MatrixXi& _periodMat){linRed =_linRed; N=linRed.rows(); n=linRed.cols(); periodMat=_periodMat;}
    
    //the default symmetry, where for even N there are N/2 lines
    inline void set_sign_symmetry(int N){
        assert(N%2==0);
        linRed.resize(N,N/2);
        linRed<<Eigen::MatrixXi::Identity(N/2,N/2),-Eigen::MatrixXi::Identity(N/2,N/2);
        n=N/2;
        set_default_period_matrix(n);
    }
    
    //the entire first N/3 lines are symmetric w.r.t. to the next two (N/3) packets, and where if N is even we also add sign symmetry.
    inline void set_triangular_symmetry(int N){
        assert(N%3==0);
        if (N%2==0){
            linRed.resize(N,N/3);
            linRed.block(0,0,N/2,N/3)<<Eigen::MatrixXi::Identity(N/3,N/3),-Eigen::MatrixXi::Identity(N/6,N/6),Eigen::MatrixXi::Identity(N/6,N/6);
            linRed.block(N/2,0,N/2,N/3)=-linRed.block(0,0,N/2,N/3);
            n=N/3;
        } else {
            linRed.resize(N,2*N/3);
            linRed<<Eigen::MatrixXi::Identity(2*N/3,2*N/3),-Eigen::MatrixXi::Identity(N/3,N/3),-Eigen::MatrixXi::Identity(N/3,N/3);
            n=2*N/3;
        }
        set_default_period_matrix(n);
    }
    
    inline void set_default_period_matrix(int n){
        periodMat=Eigen::MatrixXi::Identity(n,n);
    }
};
} // namespace directional

#endif // DIRECTIONAL_INTEGRATION_INTEGRATION_DATA_H
