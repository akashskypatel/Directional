#include <directional/io/WriteOBJ.h>

#include <directional/core/TriMesh.h>

#include <fstream>
#include <stdexcept>

namespace directional {

bool writeOBJ(const std::string& fileName,
              const directional::TriMesh& mesh,
              const Eigen::MatrixXd& TC,
              const Eigen::MatrixXi& FTC,
              const std::string& mtlFileName,
              const std::string& textureName)
{
    std::ofstream out(fileName);
    if (!out.is_open())
        throw std::runtime_error("Failed to open file: " + fileName);

    // Write reference to MTL file if provided
    if (!mtlFileName.empty())
        out << "mtllib " << mtlFileName << "\n";

    // Use material if name is provided
    if (!textureName.empty())
        out << "usemtl " << textureName << "\n";

    // Write vertices
    for (int i = 0; i < mesh.V.rows(); ++i)
        out << "v " << mesh.V(i, 0) << " " << mesh.V(i, 1) << " " << mesh.V(i, 2) << "\n";

    // Write texture coordinates
    for (int i = 0; i < TC.rows(); ++i)
        out << "vt " << TC(i, 0) << " " << TC(i, 1) << "\n";

    // Write faces with texture indices
    for (int i = 0; i < mesh.F.rows(); ++i) {
        out << "f";
        for (int j = 0; j < 3; ++j) {
            int v_idx = mesh.F(i, j) + 1;    // OBJ uses 1-based indexing
            int vt_idx = FTC(i, j) + 1;
            out << " " << v_idx << "/" << vt_idx;
        }
        out << "\n";
    }

    out.close();
    return true;
}

} // namespace directional
