#include <directional/util/GraphUtils.h>

#include <queue>
#include <utility>

namespace directional {

void tree(const Eigen::MatrixXi &EV, Eigen::VectorXi &tE,
          Eigen::VectorXi &tEf) {
  using namespace Eigen;
  int numV = EV.maxCoeff() + 1;
  VectorXi Valences = VectorXi::Zero(numV);
  for (int i = 0; i < EV.rows(); i++) {
    if (EV(i, 0) == -1 || EV(i, 1) == -1)
      continue;
    Valences(EV(i, 0))++;
    Valences(EV(i, 1))++;
  }

  MatrixXi VE(numV, Valences.maxCoeff());
  Valences.setZero();
  for (int i = 0; i < EV.rows(); i++) {
    if (EV(i, 0) == -1 || EV(i, 1) == -1)
      continue;
    VE(EV(i, 0), Valences(EV(i, 0))++) = i;
    VE(EV(i, 1), Valences(EV(i, 1))++) = i;
  }

  Eigen::VectorXi usedVertices = VectorXi::Zero(numV);
  std::queue<std::pair<int, int>> edgeVertices;

  tE.resize(numV - 1);
  tEf.resize(numV);
  tEf.setConstant(-2);
  int currEdgeIndex = 0;
  int start = 0;

  while (Valences[start] == 0)
    if (++start > Valences.size())
      return;

  edgeVertices.push(std::pair<int, int>(-1, start));
  do {
    std::pair<int, int> currEdgeVertex = edgeVertices.front();
    edgeVertices.pop();
    if (usedVertices(currEdgeVertex.second))
      continue;

    if (currEdgeVertex.first != -1)
      tE(currEdgeIndex++) = currEdgeVertex.first;
    tEf(currEdgeVertex.second) = currEdgeVertex.first;
    usedVertices(currEdgeVertex.second) = 1;

    for (int i = 0; i < Valences(currEdgeVertex.second); i++) {
      int nextEdge = VE(currEdgeVertex.second, i);
      int nextVertex =
          (EV(nextEdge, 0) == currEdgeVertex.second ? EV(nextEdge, 1)
                                                    : EV(nextEdge, 0));
      if (!usedVertices(nextVertex))
        edgeVertices.push(std::pair<int, int>(nextEdge, nextVertex));
    }
  } while (edgeVertices.size() != 0);

  tE.conservativeResize(usedVertices.sum() - 1);
}

} // namespace directional
