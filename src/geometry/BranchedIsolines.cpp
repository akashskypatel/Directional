#include <directional/geometry/BranchedIsolines.h>

namespace directional {

void branched_isolines(const Eigen::MatrixXd& V,
                              const Eigen::MatrixXi& F,
                              const Eigen::MatrixXd& NFunction,
                              Eigen::MatrixXd& isoV,
                              Eigen::MatrixXi& isoE,
                              Eigen::MatrixXi& isoOrigE,
                              Eigen::MatrixXd& isoN,
                              Eigen::VectorXi& funcNum)
{

    int N = NFunction.cols();
    int jumps = (N%2 == 0 ? 2 : 1);
    Eigen::MatrixXd isoVPart, isoNPart;
    Eigen::MatrixXi isoEPart, isoOrigEPart;

    for (int i=0;i<NFunction.cols()/jumps;i++){
        Eigen::VectorXd currFunc = NFunction.col(i);
        directional::isolines(V,F, currFunc, 100, isoVPart, isoEPart, isoOrigEPart, isoNPart);

        int oldVSize = isoV.rows();
        int oldESize = isoE.rows();
        isoV.conservativeResize(oldVSize+isoVPart.rows(),3);
        isoE.conservativeResize(oldESize+isoEPart.rows(),2);
        isoOrigE.conservativeResize(oldESize+isoOrigEPart.rows(),3);
        isoN.conservativeResize(oldESize+isoNPart.rows(),3);
        funcNum.conservativeResize(oldESize+isoEPart.rows());

        isoV.block(oldVSize,0,isoVPart.rows(),3) = isoVPart;
        isoE.block(oldESize,0,isoEPart.rows(),2) = isoEPart.array()+oldVSize;
        isoOrigE.block(oldESize,0,isoOrigEPart.rows(),3) = isoOrigEPart;
        isoN.block(oldESize,0,isoNPart.rows(),3) = isoNPart;
        funcNum.tail(isoNPart.rows()).setConstant(i);
    }
}

} // namespace directional
