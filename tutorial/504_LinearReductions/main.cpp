#include <iostream>
#include <Eigen/Core>
#include <directional/core/TriMesh.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/core/CartesianField.h>
#include <directional/io/ReadOFF.h>
#include <directional/io/ReadRawField.h>
#include <directional/io/WriteRawField.h>
#include <directional/fields/CurlMatching.h>
#include <directional/integration/SetupIntegration.h>
#include <directional/integration/Integrate.h>
#include <directional/geometry/BranchedIsolines.h>
#include <directional/visualization/DirectionalViewer.h>
#include <directional/integration/IntegrationData.h>

int N;
directional::TriMesh meshWhole, meshCut;
directional::PCFaceTangentBundle ftb;
directional::CartesianField rawField, combedField;
Eigen::MatrixXd NFunctionSign, NFunctionTri, NCornerFunc;
directional::DirectionalViewer viewer;

typedef enum {SIGN_SYMMETRY, TRI_SYMMETRY} ViewingModes;
ViewingModes viewingMode=SIGN_SYMMETRY;


void callbackFunc(){
    
    const char* items[] = {"Sign Symmetry", "Triangular Symmetry"};
    static const char* current_item = NULL;
    
    ImGui::PushItemWidth(300);
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
                        viewingMode = SIGN_SYMMETRY;
                        viewer.set_isolines(meshCut, NFunctionSign);
                        break;
                    case 1:
                        viewingMode = TRI_SYMMETRY;
                        viewer.set_isolines(meshCut, NFunctionTri);
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
    
    directional::readOFF(TUTORIAL_DATA_PATH "/dome.off", meshWhole);
    ftb.init(meshWhole);
    directional::read_raw_field(TUTORIAL_DATA_PATH "/dome-6.rawfield", ftb, N, rawField);
    
    //combing and cutting
    directional::principal_matching(rawField);
    
    directional::IntegrationData intData(N);
    std::cout<<"Setting up Integration"<<std::endl;
    directional::setup_integration(rawField, intData,meshCut, combedField);
    
    intData.verbose=false;
    intData.integralSeamless=true;
    
    std::cout<<"Free (sign-symmetric) Integrating..."<<std::endl;
    directional::integrate(combedField, intData, meshCut, NFunctionSign, NCornerFunc);
    std::cout<<"Done!"<<std::endl;
    
    
    std::cout<<"Solving triangular-constrained integration..."<<std::endl;
    intData.set_triangular_symmetry(N);
    directional::setup_integration(rawField,intData, meshCut, combedField);
    directional::integrate(combedField,  intData, meshCut, NFunctionTri, NCornerFunc);
    std::cout<<"Done!"<<std::endl;
    
    viewer.init();
    viewer.set_surface_mesh(meshWhole);
    viewer.set_cartesian_field(rawField);
    //viewer.set_seams(combedField.matching);
    viewer.set_isolines(meshCut, NFunctionSign);
    viewer.set_callback(callbackFunc);
    viewer.launch();
    
}


