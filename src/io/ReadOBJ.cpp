#include <directional/io/ReadOBJ.h>

#include <directional/core/TriMesh.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

namespace directional {

bool readOBJ(const std::string objFileName,
                    directional::TriMesh& mesh) {
    Eigen::MatrixXd V;
    Eigen::MatrixXi F;
    std::ifstream file(objFileName);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << objFileName << std::endl;
        return false;
    }

    std::string line;
    std::vector<Eigen::RowVector3d> vertexList;
    std::vector<Eigen::RowVector3i> faceList;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string type;
        ss >> type;

        if (type == "v") {
            Eigen::RowVector3d newVertex;
            ss >> newVertex(0) >> newVertex(1) >> newVertex(2);
            vertexList.push_back(newVertex);
        } else if (type == "f") {
            Eigen::RowVector3i newFace;
            std::string v_str;

            for (int i = 0; i < 3; ++i) {
                ss >> v_str;
                std::stringstream vs(v_str);
                std::string idx_str;
                std::getline(vs, idx_str, '/'); // take only the first part
                newFace(i) = std::stoi(idx_str); // OBJ is 1-indexed
            }

            faceList.push_back(newFace);
        }
    }

    file.close();

    V.resize(vertexList.size(), 3);
    for (int i = 0; i < vertexList.size(); ++i)
        V.row(i) = vertexList[i];

    F.resize(faceList.size(), 3);
    for (int i = 0; i < faceList.size(); ++i)
        F.row(i) = faceList[i];

    // Convert to 0-indexing
    int minIndex = F.minCoeff();
    F.array() -= minIndex;

    mesh.set_mesh(V, F);
    return true;
}

} // namespace directional
