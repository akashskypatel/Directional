#include <directional/fields/PowerField.h>

namespace directional {

void power_field(const TangentBundle& tb,
                        const Eigen::VectorXi& constSpaces,
                        const Eigen::MatrixXd& constVectors,
                        const Eigen::VectorXd& alignWeights,
                        const int N,
                        directional::CartesianField& field,
                        const bool normalizeField)
{

    PolyVectorData pvData;
    pvData.N = N;
    pvData.tb = &tb;
    //pvData.verbose = true;
    if (constSpaces.size()!=0) {
        pvData.constSpaces = constSpaces;
        pvData.constVectors = constVectors;
        pvData.wAlignment = alignWeights;
    }else{
        pvData.constSpaces.resize(1); pvData.constSpaces(0)=0;
        Eigen::RowVector2d intConstVector; intConstVector<<1.0,0.0;
        pvData.constVectors = tb.project_to_extrinsic(pvData.constSpaces, intConstVector);
        pvData.wAlignment = Eigen::VectorXd::Constant(pvData.constSpaces.size(),-1.0);
    }
    pvData.wSmooth = 1.0;
    pvData.wRoSy = -1.0;  //Perfect RoSy
    polyvector_field(pvData, field);
    field.fieldType = fieldTypeEnum::POWER_FIELD;
    //getting rid of the redundant zeros, in case they were allocated.
    field.intField.conservativeResize(field.intField.rows(),2);
    field.extField.conservativeResize(field.extField.rows(),3);
    if (normalizeField){
        Eigen::MatrixXd intField = field.intField;
        intField = intField.array().colwise() / intField.rowwise().norm().array();
        field.set_intrinsic_field(intField);
    }
}

} // namespace directional
