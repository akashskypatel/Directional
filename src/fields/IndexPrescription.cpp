#include <directional/fields/IndexPrescription.h>

namespace directional {

void index_prescription(const Eigen::VectorXi& cycleIndices,
                               const int N,
                               const double globalRotation,
                               Eigen::SimplicialLDLT<Eigen::SparseMatrix<double> >& ldltSolver,
                               directional::CartesianField& field,
                               Eigen::VectorXd& rotationAngles,
                               double &linfError)
{
    using namespace Eigen;
    using namespace std;

    VectorXd cycleNewCurvature = cycleIndices.cast<double>()*(2.0*std::numbers::pi/(double)N);

    //Initialize solver if never before
    if (!ldltSolver.rows())
    {
        SparseMatrix<double> AAt = field.tb->cycles*field.tb->cycles.transpose();
        ldltSolver.compute(AAt);
    }

    VectorXd innerRotationAngles = field.tb->cycles.transpose()*ldltSolver.solve(-field.tb->cycleCurvatures + cycleNewCurvature);
    rotationAngles.conservativeResize(field.tb->adjSpaces.rows());
    rotationAngles.setZero();
    for (int i=0;i<field.tb->innerAdjacencies.rows();i++)
        rotationAngles(field.tb->innerAdjacencies(i))=innerRotationAngles(i);

    linfError = (field.tb->cycles*innerRotationAngles - (-field.tb->cycleCurvatures + cycleNewCurvature)).template lpNorm<Infinity>();

    directional::rotation_to_raw(*(field.tb), rotationAngles,N,globalRotation,field);
}

} // namespace directional

namespace directional {

void index_prescription(const Eigen::VectorXi& cycleIndices,
                               const int N,
                               const double globalRotation,
                               directional::CartesianField& field,
                               Eigen::VectorXd& rotationAngles,
                               double &error)
{
    Eigen::SimplicialLDLT<Eigen::SparseMatrix<double> > ldltSolver;
    index_prescription(cycleIndices, N, globalRotation,ldltSolver,  field, rotationAngles, error);
}

} // namespace directional
