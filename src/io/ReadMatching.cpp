#include <directional/io/ReadMatching.h>

#include <fstream>

namespace directional {

bool read_matching(const std::string &fileName,
                              Eigen::VectorXi& matching,
                              Eigen::MatrixXi& EF,
                              Eigen::MatrixXi& EV,
                              Eigen::MatrixXi& FE,
                              int & N)
{
    try
    {
        std::ifstream f(fileName);
        int numEdges = 0;
        int numFaces = 0;
        f >> N >> numEdges >> numFaces;
        matching.conservativeResize(numEdges);
        EF.conservativeResize(numEdges,2);
        EV.conservativeResize(numEdges,2);
        FE.conservativeResize(numFaces,3);

        for (int i=0;i<numEdges;i++)
            f >> EF(i,0)>> EF(i,1) >> EV(i, 0) >> EV(i, 1) >> matching(i);

        for (int i=0;i<numFaces;i++)
            f >> FE(i,0) >> FE(i,1) >> FE(i,2);

        f.close();
        return f.fail();
    }
    catch (std::exception e)
    {
        return false;
    }
}

} // namespace directional
