#include <directional/fields/PowerToRaw.h>

namespace directional {

void power_to_raw(const directional::CartesianField& powerField,
                         int N,
                         directional::CartesianField& rawField,
                         bool normalize)
{
    assert(powerField.fieldType==fieldTypeEnum::POWER_FIELD && "The input field should be a power/PolyVector field");
    rawField.init(*(powerField.tb), fieldTypeEnum::RAW_FIELD,N);
    Eigen::MatrixXcd intFieldComplex(powerField.intField.rows(),N);
    Eigen::VectorXcd complexPowerField(powerField.intField.rows());

    //power fields are represented as -u^N since they are a special case of PVs.
    complexPowerField.array().real()=-powerField.intField.col(0);
    complexPowerField.array().imag()=-powerField.intField.col(1);
    intFieldComplex.col(0)=pow(complexPowerField.array(),1.0/(double)N);
    for (int i=1;i<N;i++)
        intFieldComplex.col(i)=intFieldComplex.col(0)*exp(std::complex<double>(0,2*std::numbers::pi*(double)i/(double)N));

    if (normalize)
        intFieldComplex.array()/=intFieldComplex.array().abs();

    Eigen::MatrixXd intField(intFieldComplex.rows(),2*N);
    for (int i=0;i<N;i++){
        intField.col(2*i)=intFieldComplex.col(i).real();
        intField.col(2*i+1)=intFieldComplex.col(i).imag();
    }

    rawField.set_intrinsic_field(intField);
}

} // namespace directional
