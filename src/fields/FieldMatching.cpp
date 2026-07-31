#include <directional/fields/FieldMatching.h>

namespace directional {

void effort_to_indices(const Eigen::SparseMatrix<double> &basisCycles,
                              const Eigen::VectorXd &effort,
                              const Eigen::VectorXd &cycleCurvature,
                              const int N, Eigen::VectorXi &indices) {
  using namespace std;
  Eigen::VectorXd dIndices =
      ((basisCycles * effort + (double)N * cycleCurvature).array() /
       (2.0 * std::numbers::pi)); // this should already be an integer up to
                                  // numerical precision

  indices.conservativeResize(dIndices.size());
  for (int i = 0; i < indices.size(); i++) {
    if (fabs(std::round(dIndices(i)) - dIndices(i)) >= 1e-6) {
      throw std::runtime_error("Indices are not naturally integer!");
    }
    indices(i) = static_cast<int>(std::round(dIndices(i)));
  }
}

} // namespace directional

namespace directional {

void effort_to_indices(directional::CartesianField &field) {
  Eigen::VectorXd effortInner(field.tb->innerAdjacencies.size());
  for (int i = 0; i < field.tb->innerAdjacencies.size(); i++)
    effortInner(i) = field.effort(field.tb->innerAdjacencies(i));
  Eigen::VectorXi fullIndices;
  directional::effort_to_indices(field.tb->cycles, effortInner,
                                 field.tb->cycleCurvatures, field.N,
                                 fullIndices);

  Eigen::VectorXi indices(field.tb->local2Cycle.size());
  for (int i = 0; i < field.tb->local2Cycle.size(); i++)
    indices(i) = fullIndices(field.tb->local2Cycle(i));

  std::vector<int> singCyclesList;
  std::vector<int> singIndicesList;
  for (int i = 0; i < field.tb->local2Cycle.size(); i++)
    if (indices(i) != 0) {
      singCyclesList.push_back(i);
      singIndicesList.push_back(indices(i));
    }

  Eigen::VectorXi singCycles(singCyclesList.size());
  Eigen::VectorXi singIndices(singIndicesList.size());
  for (int i = 0; i < singCyclesList.size(); i++) {
    singCycles(i) = singCyclesList[i];
    singIndices(i) = singIndicesList[i];
  }
  field.set_singularities(singCycles, singIndices);
}

} // namespace directional

namespace directional {

void principal_matching(directional::CartesianField &field,
                               const bool isSingularities) {

  typedef std::complex<double> Complex;
  using namespace Eigen;
  using namespace std;

  field.matching.conservativeResize(field.tb->adjSpaces.rows());
  field.matching.setConstant(-1);

  field.effort = VectorXd::Zero(field.tb->adjSpaces.rows());
  for (int i = 0; i < field.tb->adjSpaces.rows(); i++) {
    if (field.tb->adjSpaces(i, 0) == -1 || field.tb->adjSpaces(i, 1) == -1)
      continue;

    double minRotAngle = 10000.0;
    int indexMinFromZero = 0;

    // computing some effort and the extracting principal one
    Complex freeCoeff(1.0, 0.0);
    // finding where the 0 vector in EF(i,0) goes to with smallest rotation
    // angle in EF(i,1), computing the effort, and then adjusting the matching
    // to have principal effort.
    RowVector2d vec0f =
        field.intField.block(field.tb->adjSpaces(i, 0), 0, 1, 2);
    Complex vec0fc = Complex(vec0f(0), vec0f(1));
    Complex transvec0fc = vec0fc * field.tb->connection(i);
    for (int j = 0; j < field.N; j++) {
      RowVector2d vecjf =
          field.intField.block(field.tb->adjSpaces(i, 0), 2 * j, 1, 2);
      Complex vecjfc = Complex(vecjf(0), vecjf(1));
      RowVector2d vecjg =
          field.intField.block(field.tb->adjSpaces(i, 1), 2 * j, 1, 2);
      Complex vecjgc = Complex(vecjg(0), vecjg(1));
      Complex transvecjfc = vecjfc * field.tb->connection(i);
      freeCoeff *= (vecjgc / transvecjfc);
      double currRotAngle = arg(vecjgc / transvec0fc);
      if (abs(currRotAngle) < abs(minRotAngle)) {
        indexMinFromZero = j;
        minRotAngle = currRotAngle;
      }

      // taking principal effort
    }
    field.effort(i) = arg(freeCoeff);

    // finding the matching that implements effort(i)
    // This is still not perfect
    double currEffort = 0;
    for (int j = 0; j < field.N; j++) {
      RowVector2d vecjf =
          field.intField.block(field.tb->adjSpaces(i, 0), 2 * j, 1, 2);
      Complex vecjfc = Complex(vecjf(0), vecjf(1));
      RowVector2d vecjg = field.intField.block(
          field.tb->adjSpaces(i, 1),
          2 * ((j + indexMinFromZero + field.N) % field.N), 1, 2);
      Complex vecjgc = Complex(vecjg(0), vecjg(1));
      Complex transvecjfc = vecjfc * field.tb->connection(i);
      currEffort += arg(vecjgc / transvecjfc);
    }

    field.matching(i) = static_cast<int>(
        indexMinFromZero -
        std::round((currEffort - field.effort(i)) / (2.0 * std::numbers::pi)));
  }

  // Getting final singularities and their indices
  if (isSingularities)
    effort_to_indices(field);
}

} // namespace directional
