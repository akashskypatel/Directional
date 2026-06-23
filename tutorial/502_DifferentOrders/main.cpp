#include <iostream>
#include <Eigen/Core>
#include <directional/core/TriMesh.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/core/CartesianField.h>
#include <directional/io/ReadOFF.h>
#include <directional/io/ReadRawField.h>
#include <directional/io/WriteRawField.h>
#include <directional/fields/CurlMatching.h>
#include <directional/fields/FieldCombing.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/integration/Integrate.h>
#include <directional/geometry/CutMesh.h>
#include <directional/geometry/BranchedIsolines.h>
#include <directional/visualization/DirectionalViewer.h>
#include <directional/integration/IntegrationData.h>

#define NUM_N 4

int N[NUM_N];
int currN = 0;
directional::TriMesh meshWhole, meshCut[NUM_N];
directional::PCFaceTangentBundle ftb;
directional::CartesianField rawField[NUM_N], combedField[NUM_N];
Eigen::MatrixXd NFunction[NUM_N], NCornerFunction[NUM_N];
directional::DirectionalViewer viewer;

int main()
{
    directional::readOFF(TUTORIAL_DATA_PATH "/vase.off", meshWhole);
    ftb.init(meshWhole);
    directional::read_raw_field(TUTORIAL_DATA_PATH "/vase-2.rawfield", ftb, N[0], rawField[0]);
    directional::read_raw_field(TUTORIAL_DATA_PATH "/vase-4.rawfield", ftb, N[1], rawField[1]);
    directional::read_raw_field(TUTORIAL_DATA_PATH "/vase-7.rawfield", ftb, N[2], rawField[2]);
    directional::read_raw_field(TUTORIAL_DATA_PATH "/vase-11.rawfield", ftb, N[3], rawField[3]);
    
    //combing and cutting
    viewer.init();
    viewer.set_surface_mesh(meshWhole);
    for (int i=0;i<NUM_N;i++){
        directional::principal_matching(rawField[i]);
        
        directional::IntegrationData intData(N[i]);
        std::cout<<"Setting up Integration N="<<N[i]<<std::endl;
        directional::setup_integration(rawField[i], intData, meshCut[i], combedField[i]);
        
        intData.verbose=false;
        intData.integralSeamless=true;
        intData.roundSeams=false;
        
        std::cout<<"Solving integration N=" << N[i]<<std::endl;
        directional::integrate(combedField[i],  intData, meshCut[i], NFunction[i],NCornerFunction[i]);
        
        std::cout<<"Done!"<<std::endl;
        viewer.set_cartesian_field(combedField[i], std::to_string(N[i]) + "-field", i);
        viewer.set_isolines(meshCut[i],NFunction[i],std::to_string(N[i]) + "-function",  i, 0.05);
        if (i!=0){
            viewer.toggle_cartesian_field(false, i);
            viewer.toggle_singularities(false, i);
            viewer.toggle_isolines(false, i);
        }
    }
    
    viewer.launch();
}


