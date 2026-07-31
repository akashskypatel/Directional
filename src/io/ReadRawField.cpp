#include <directional/io/ReadRawField.h>

#include <directional/core/CartesianField.h>
#include <directional/core/TangentBundle.h>

#include <fstream>

namespace directional {

bool read_raw_field(const std::string &fileName,
                           const directional::TangentBundle& tb,
                           int& N,
                           directional::CartesianField& field)
{
    try
    {
        std::ifstream f(fileName);
        if (!f.is_open()) {
            return false;
        }
        int numT;
        f>>N;
        f>>numT;
        Eigen::MatrixXd extField;
        extField.conservativeResize(numT, 3*N);

        //Can we do better than element-wise reading?
        for (int i=0;i<extField.rows();i++)
            for (int j=0;j<extField.cols();j++)
                f>>extField(i,j);

        f.close();
        assert(tb.sources.rows()==extField.rows());
        assert(tb.hasEmbedding() && "This tangent bundle doesn't admit an extrinsic embedding");
        field.init(tb, fieldTypeEnum::RAW_FIELD, N);
        field.set_extrinsic_field(extField);
        return f.good();
    }
    catch (std::exception e)
    {
        return false;
    }
}

} // namespace directional
