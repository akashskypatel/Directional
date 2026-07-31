#include <directional/io/WriteRawField.h>

#include <directional/core/CartesianField.h>

#include <fstream>
#include <limits>

namespace directional {

bool write_raw_field(const std::string fileName,
                            const directional::CartesianField& rawField,
                            bool high_precision)
{
    std::ofstream f(fileName);
    if (high_precision)
    {
        f.flags(std::ios::scientific);
        f.precision(std::numeric_limits<double>::digits10 + 1);
    }

    f << rawField.N << " " << rawField.extField.rows() << std::endl;
    for (int i=0;i<rawField.extField.rows();i++)
    {
        for (int j=0;j<rawField.extField.cols();j++)
            f << rawField.extField(i,j) << " ";
        f << std::endl;
    }
    f.close();
    return !f.fail();
}

} // namespace directional
