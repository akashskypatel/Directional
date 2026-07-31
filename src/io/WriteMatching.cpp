#include <directional/io/WriteMatching.h>

#include <fstream>

namespace directional {

bool write_matching(const std::string &fileName,
                           const Eigen::VectorXi& matching,
                           const Eigen::MatrixXi& EF,
                           const Eigen::MatrixXi& EV,
                           const Eigen::MatrixXi& FE,
                           int N)
{
    try
    {
        std::ofstream f(fileName);

        if (! f.is_open())
            return false;

        int numEdges = EF.rows();
        int numFaces = FE.rows();

        f << N << " " << numEdges << " " << numFaces << std::endl;
        for (int i = 0; i < numEdges; i++)
            f << EF(i,0) << " " << EF(i,1) << " " << EV(i, 0) << " " << EV(i, 1) << " "<< matching(i) << std::endl;

        for (int i=0;i<numFaces;i++)
            f << FE(i,0) <<" "<<FE(i,1)<<" "<<FE(i,2)<<std::endl;

        f.close();
        return f.fail();
    }
    catch (std::exception e)
    {
        return false;
    }
    return true;
}

} // namespace directional
