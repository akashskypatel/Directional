#include <iostream>
#include <Eigen/Core>
#include <directional/io/ReadOBJ.h>
#include <directional/core/TriMesh.h>
#include <directional/core/CartesianField.h>
#include <directional/fields/PCFaceTangentBundle.h>
#include <directional/visualization/DirectionalViewer.h>
#include <directional/operators/CochainComplex.h>
#include <directional/operators/GradientMatrices.h>
#include <directional/operators/CurlMatrices.h>
#include <directional/operators/MassMatrices.h>
#include <directional/operators/ExtrinsicIntrinsicMatrices.h>

directional::TriMesh mesh;
directional::PCFaceTangentBundle ftb;
directional::CartesianField harmField;
directional::DirectionalViewer viewer;
Eigen::MatrixXd harmBasis;
Eigen::SparseMatrix<double> IE;
int currHarmBasis = 0;

void callbackFunc() {
    ImGui::PushItemWidth(100); // Make ui elements 100 pixels wide,
    ImGui::Text("Harmonic basis function: %d", currHarmBasis);
    ImGui::SameLine();
    if (ImGui::Button("+")) {
        currHarmBasis = (currHarmBasis + 1)%harmBasis.cols();
        //std::cout<<"currHarmBasis: "<<currHarmBasis<<std::endl;
        harmField.set_extrinsic_field(IE*harmBasis.col(currHarmBasis));
        viewer.set_cartesian_field(harmField, "Harmonic Field", 0, 0, 50.0);
        //std::cout<<"after set field"<<std::endl;
    }
    ImGui::SameLine();
    if (ImGui::Button("-")) {
        currHarmBasis = (currHarmBasis + harmBasis.cols() - 1)%harmBasis.cols();
        //std::cout<<"currHarmBasis: "<<currHarmBasis<<std::endl;
        harmField.set_extrinsic_field(IE*harmBasis.col(currHarmBasis));
        viewer.set_cartesian_field(harmField, "Harmonic Field", 0, 0, 50.0);
    }
    
    ImGui::PopItemWidth();
}


int main()
{
    directional::readOBJ(TUTORIAL_DATA_PATH "/129110__sf.obj",mesh);
    ftb.init(mesh);
    
    //Must use intrinsic since otherwise the harmonic field will have spurious normal components
    Eigen::SparseMatrix<double> G = directional::conf_gradient_matrix_2D<double>(mesh, true);
    Eigen::SparseMatrix<double> C = directional::curl_matrix_2D<double>(mesh, true);
    // G and C operate on intrinsic 2D face vectors, so the mass matrix must
    // have two entries per face. The default is three entries per face for
    // extrinsic vectors and causes an Eigen dimension assertion here.
    Eigen::SparseMatrix<double> Mx =
        directional::face_mass_matrix_2D<double>(mesh, false, 2);
    //Eigen::SparseMatrix<double> Mc = directional::edge_diamond_mass_matrix_2D<double>(mesh, true);
    IE = directional::face_intrinsic_to_extrinsic_matrix_2D<double>(mesh);
    
    int bettiNumber = mesh.EV.rows() - (mesh.V.rows()-1) - (mesh.F.rows()-1);
    std::cout<<"Computing cohomology basis..."<<std::endl;
    if (bettiNumber <= 0) {
        std::cerr << "The mesh has no non-trivial harmonic 1-form basis." << std::endl;
        return EXIT_FAILURE;
    }

    directional::cohomology_basis(G, C, Mx, bettiNumber, harmBasis);
    if (harmBasis.rows() != G.rows() || harmBasis.cols() != bettiNumber) {
        std::cerr << "Failed to compute the harmonic basis: expected "
                  << G.rows() << " x " << bettiNumber << ", got "
                  << harmBasis.rows() << " x " << harmBasis.cols() << std::endl;
        return EXIT_FAILURE;
    }

    std::cout<<"bettiNumber: "<<bettiNumber<<std::endl;
    std::cout<<"divergence of harmonic basis: "<<(G.adjoint()*Mx*harmBasis).cwiseAbs().maxCoeff()<<std::endl;
    std::cout<<"curl of harmonic basis: "<<(C*harmBasis).cwiseAbs().maxCoeff()<<std::endl;
    
    viewer.init();
    viewer.set_callback(&callbackFunc);
    viewer.set_surface_mesh(mesh);
    harmField.init(ftb, directional::fieldTypeEnum::RAW_FIELD, 1);
    harmField.set_extrinsic_field(IE*harmBasis.col(currHarmBasis));
    viewer.set_cartesian_field(harmField, "Harmonic Field", 0, 0, 50.0);
    viewer.launch();
}
