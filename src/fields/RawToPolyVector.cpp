#include <directional/fields/RawToPolyVector.h>

namespace directional {

void raw_to_polyvector(const Eigen::MatrixXd& intField,
                              const int N,
                              Eigen::MatrixXcd& pvField,
                              const bool signSymmetry){


    pvField=Eigen::MatrixXcd::Zero(intField.rows(),intField.cols()/2);
    Eigen::MatrixXcd actualRoots;
    int actualN;
    if ((signSymmetry)&&(N%2==0)){
        actualRoots.resize(intField.rows(), intField.cols()/4);
        actualN = N/2;
        for (int i=0;i<actualN;i++)
            for (int j=0;j<intField.rows();j++)
                actualRoots(j,i)=std::complex<double>(intField(j,2*i), intField(j,2*i+1));

        actualRoots = actualRoots.array().square();
    }else {
        actualRoots.resize(intField.rows(), intField.cols()/2);
        actualN = N;
        for (int i=0;i<actualN;i++)
            for (int j=0;j<intField.rows();j++)
                actualRoots(j,i)=std::complex<double>(intField(j,2*i), intField(j,2*i+1));
    }

    int jump = ((signSymmetry)&&(N%2==0) ? 2 : 1);
    Eigen::MatrixXcd actualPVField(pvField.rows(), 1);
    actualPVField.col(0)=-actualRoots.col(0);
    //std::cout<<"actualRoots: "<<actualRoots<<std::endl;
    for (int i=1;i<actualN;i++)
        multiply_polynomials(actualPVField, -actualRoots.col(i));

    for (int i=0;i<N;i+=jump)
        pvField.col(i)=actualPVField.col(i/jump);
}

} // namespace directional

namespace directional {

void raw_to_polyvector(const CartesianField& rawField,
                              CartesianField& pvField,
                              const bool signSymmetry){

    Eigen::MatrixXcd pvFieldComplex;
    raw_to_polyvector(rawField.intField, rawField.N, pvFieldComplex, signSymmetry);
    pvField.init(*(rawField.tb), fieldTypeEnum::POLYVECTOR_FIELD, rawField.N);
    pvField.set_intrinsic_field(pvFieldComplex);
}

} // namespace directional
