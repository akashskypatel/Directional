#include <directional/io/WriteSingularities.h>

#include <fstream>

namespace directional {

bool write_singularities(const std::string &fileName,
                                    const int N,
                                    const Eigen::VectorXi &singLocalCycles,
                                    const Eigen::VectorXi &singIndices)
{
    std::ofstream f(fileName, std::ios::trunc);
    f << N << " " << singIndices.size() << std::endl;

    for (int i=0;i<singIndices.rows();i++)
        f << singLocalCycles(i) << " " << singIndices(i) << std::endl;

    f.close();
    return !f.fail();
}

} // namespace directional
