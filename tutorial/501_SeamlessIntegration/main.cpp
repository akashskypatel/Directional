#include <iostream>
#include <Eigen/Core>
#include <directional/core/TriMesh.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/core/CartesianField.h>
#include <directional/io/ReadOFF.h>
#include <directional/io/WriteOBJ.h>
#include <directional/io/ReadRawField.h>
#include <directional/io/WriteRawField.h>
#include <directional/fields/CurlMatching.h>
#include <directional/fields/FieldCombing.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/integration/Integrate.h>
#include <directional/geometry/CutMesh.h>
#include <directional/visualization/DirectionalViewer.h>
#include <directional/integration/IntegrationData.h>


int N;
directional::TriMesh meshWhole, meshCut;
directional::PCFaceTangentBundle ftb;
directional::CartesianField rawField, combedField;
Eigen::MatrixXd cutUVFull, cutUVRot, cornerWholeUV;
directional::DirectionalViewer viewer;

typedef enum {FIELD, ROT_INTEGRATION, FULL_INTEGRATION} ViewingModes;
ViewingModes viewingMode=FIELD;

//texture image
Eigen::Matrix<unsigned char,Eigen::Dynamic,Eigen::Dynamic> texture_R, texture_G, texture_B;

void callbackFunc(){
    ImGui::PushItemWidth(100);
    
    if (ImGui::Button("Save Textured OBJ File")){
        Eigen::MatrixXd emptyMat;
        directional::writeOBJ(TUTORIAL_OUTPUT_PATH "/horsers-param-rot-seamless.obj", meshCut, cutUVRot, meshCut.F, "squares.mtl", "material_0");
        directional::writeOBJ(TUTORIAL_OUTPUT_PATH "/horsers-param-full-seamless.obj", meshCut, cutUVFull, meshCut.F, "squares.mtl", "material_0");
    }
    
    ImGui::PopItemWidth();
}


int main()
{
    //setup_line_texture();
    directional::readOFF(TUTORIAL_DATA_PATH "/horsers.off", meshWhole);
    ftb.init(meshWhole);
    directional::read_raw_field(TUTORIAL_DATA_PATH "/horsers-cf.rawfield", ftb, N, rawField);
    
    //combing and cutting
    Eigen::VectorXd curlNorm;
    directional::curl_matching(rawField, curlNorm);
    std::cout<<"curlNorm max: "<<curlNorm.maxCoeff()<<std::endl;
    
    directional::IntegrationData intData(N);
    intData.verbose=true;
    
    std::cout<<"Setting up Integration"<<std::endl;
    directional::setup_integration(rawField, intData, meshCut, combedField);
    std::vector<int> seamsList;
    for (int i=0;i<meshWhole.F.rows();i++)
        for (int j=0;j<3;j++)
            if (intData.face2cut(i, j))
                seamsList.push_back(meshWhole.FE(i,j));
       
    Eigen::VectorXi seams = Eigen::VectorXi::Map(seamsList.data(), seamsList.size());
    intData.integralSeamless=false;
    std::cout<<"Solving for permutationally-seamless integration"<<std::endl;
    if (!directional::integrate(combedField, intData, meshCut, cutUVRot, cornerWholeUV)) {
        std::cerr << "Permutationally-seamless integration failed." << std::endl;
        return EXIT_FAILURE;
    }
    // Extract the UV pair from [U, V, -U, -V]. Evaluate before assigning
    // because the source block aliases cutUVRot and the assignment resizes it.
    cutUVRot = cutUVRot.leftCols(2).eval();
    std::cout<<"Done!"<<std::endl;
    
    intData.integralSeamless = true;
    std::cout<<"Solving for integrally-seamless integration"<<std::endl;
    if (!directional::integrate(combedField, intData, meshCut, cutUVFull, cornerWholeUV)) {
        std::cerr << "Integrally-seamless integration failed." << std::endl;
        return EXIT_FAILURE;
    }
    cutUVFull = cutUVFull.leftCols(2).eval();
    std::cout<<"Done!"<<std::endl;
    
    //viewer cut (texture) and whole (field) meshes
    viewer.init();
    viewer.set_surface_mesh(meshWhole, "Original Mesh", 0);
    viewer.set_surface_mesh(meshCut, "Cut Mesh", 1);
    viewer.set_cartesian_field(combedField);
    viewer.highlight_edges(seams, "Seams");
    viewer.set_uv(cutUVRot, "Rotationally Seamless UV", 1);
    viewer.set_uv(cutUVFull, "Full Seamless UV", 1);
    viewer.set_callback(callbackFunc);
    viewer.launch();
}


