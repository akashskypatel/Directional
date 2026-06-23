#include <iostream>
#include <Eigen/Core>
#include <directional/io/ReadOFF.h>
#include <directional/core/TriMesh.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/core/CartesianField.h>
#include <directional/io/ReadRawField.h>
#include <directional/io/WriteRawField.h>
#include <directional/fields/CurlMatching.h>
#include <directional/fields/FieldCombing.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/integration/Integrate.h>
#include <directional/geometry/BranchedIsolines.h>
#include <directional/visualization/DirectionalViewer.h>
#include <directional/geometry/CutMesh.h>
#include <directional/integration/IntegrationData.h>


int N;
directional::TriMesh meshWhole, meshCut;
directional::PCFaceTangentBundle ftb;
directional::CartesianField rawField, combedField;
Eigen::MatrixXd NFunctionSeams, NFunctionSings, NCornerFunc;

Eigen::MatrixXd P1Seams, P2Seams, P1Sings, P2Sings;
Eigen::VectorXi funcNumSeams, funcNumSings;

directional::DirectionalViewer viewer;

typedef enum {SEAMS_ROUNDING, SINGS_ROUNDING} ViewingModes;
ViewingModes viewingMode=SEAMS_ROUNDING;

void callbackFunc(){
    ImGui::PushItemWidth(100);
    
    const char* items[] = {"Rounding seams", "Rounding Singularities"};
    static const char* current_item = NULL;
    
    static float combo_width = 0.0f;
    if (combo_width == 0.0f) {
        ImGuiStyle& style = ImGui::GetStyle();
        for (auto& item : items)
            combo_width = std::max(combo_width, ImGui::CalcTextSize(item).x);
        combo_width += style.FramePadding.x * 5.0 + ImGui::GetFontSize() + style.ItemInnerSpacing.x;
    }
    
    ImGui::PushItemWidth(combo_width);
    if (ImGui::BeginCombo("Viewing Mode", current_item))
    {
        for (int n = 0; n < IM_ARRAYSIZE(items); n++)
        {
            bool is_selected = (current_item == items[n]); 
            if (ImGui::Selectable(items[n], is_selected)) {
                switch (n) {
                    case 0:
                        viewingMode = SEAMS_ROUNDING;
                        viewer.set_isolines(meshCut, NFunctionSeams);
                        break;
                    case 1:
                        viewingMode = SINGS_ROUNDING;
                        viewer.set_isolines(meshCut, NFunctionSings);
                        break;
                }
                
                current_item = items[n];
            }
            if (is_selected)
                ImGui::SetItemDefaultFocus();
        }
        ImGui::EndCombo();
    }
    
    ImGui::PopItemWidth();
}


int main()
{
    directional::readOFF(TUTORIAL_DATA_PATH "/train-station.off", meshWhole);
    ftb.init(meshWhole);
    directional::read_raw_field(TUTORIAL_DATA_PATH "/train-station-5.rawfield", ftb, N, rawField);
    
    //combing and cutting
    directional::principal_matching(rawField);
    directional::combing(rawField, combedField);
    
    directional::IntegrationData intData(N);
    std::cout<<"Setting up Integration"<<std::endl;
    directional::setup_integration(rawField, intData, meshCut, combedField);
    
    intData.verbose=false;
    intData.integralSeamless=true;
    intData.roundSeams=true;
    
    std::cout<<"Seams-rounding Integrating..."<<std::endl;
    directional::integrate(combedField, intData, meshCut,  NFunctionSeams,NCornerFunc);
    std::cout<<"Done!"<<std::endl;
    
    intData.roundSeams=false;
    directional::setup_integration(rawField, intData, meshCut,combedField);
    std::cout<<"Singularity-rounding integration..."<<std::endl;
    directional::integrate(combedField,  intData, meshCut, NFunctionSings,NCornerFunc);
    std::cout<<"Done!"<<std::endl;
    
    viewer.init();
    viewer.set_surface_mesh(meshWhole);
    viewer.set_cartesian_field(rawField);
    viewer.set_isolines(meshCut, NFunctionSeams);
    viewer.set_callback(callbackFunc);
    viewer.launch();
}


