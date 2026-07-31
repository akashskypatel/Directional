#include <directional/io/ReadSingularities.h>

#include <directional/core/CartesianField.h>

#include <fstream>

namespace directional {

bool read_singularities(const std::string &fileName,
                               int& N,
                               Eigen::VectorXi& singElements,
                               Eigen::VectorXi& singIndices)
{
    try
    {
        std::ifstream f(fileName);
        int numSings;
        f >> N;
        f >> numSings;

        singElements = Eigen::VectorXi::Zero(numSings);
        singIndices = Eigen::VectorXi::Zero(numSings);

        for (int i=0;i<numSings;i++)
            f >> singElements.coeffRef(i)>> singIndices.coeffRef(i);

        f.close();
        return f.fail();
    }
    catch (std::exception e)
    {
        return false;
    }
}

} // namespace directional

namespace directional {

bool read_singularities(const std::string &fileName,
                               directional::CartesianField& field)
{
    try
    {
        std::ifstream f(fileName);
        int numSings,N;
        f >> N;
        assert(N==field.N && "Read singularities should be of the same degree as the field");
        f >> numSings;

        Eigen::VectorXi singElements = Eigen::VectorXi::Zero(numSings);
        Eigen::VectorXi singIndices = Eigen::VectorXi::Zero(numSings);

        for (int i=0;i<numSings;i++)
            f >> singElements.coeffRef(i)>> singIndices.coeffRef(i);

        f.close();
        field.set_singularities(singElements, singIndices);
        return f.fail();
    }
    catch (std::exception e)
    {
        return false;
    }
}

} // namespace directional
