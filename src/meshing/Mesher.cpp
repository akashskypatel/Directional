#include <directional/meshing/Mesher.h>

#include <chrono>
#include <iostream>

#include <directional/core/TriMesh.h>
#include <directional/meshing/MesherData.h>
#include <directional/meshing/NFunctionMesher.h>

namespace directional {

bool mesher(const TriMesh &origMesh, MesherData &mData,
            Eigen::MatrixXd &VOutput, Eigen::VectorXi &DOutput,
            Eigen::MatrixXi &FOutput) {
  using Clock = std::chrono::high_resolution_clock;
  const auto mesherStart = Clock::now();
  mData.diagnostics = MesherDiagnostics{};

  report_progress(mData.progress, 2, 100, "Initializing mesh generator");
  NFunctionMesher functionMesher(origMesh, mData);
  functionMesher.init();
  report_progress(mData.progress, 8, 100,
                  "Mesh generator initialization complete");

  if (mData.verbose) {
    std::cout << "[Directional::mesher()]: Generating mesh" << std::endl;
  }

  report_progress(mData.progress, 10, 100, "Generating mesh topology");
  const auto generateStart = Clock::now();
  functionMesher.generate_mesh();
  mData.diagnostics.generateArrangementSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            generateStart)
          .count() /
      1.0e6;
  if (mData.verbose) {
    std::cout << "[Directional::mesher()]: Done generating!" << std::endl;
  }

  Eigen::VectorXi genInnerEdges, genTF;
  Eigen::MatrixXi genEV, genEFi, genEF, genFE, genTEdges;
  Eigen::MatrixXd genFEs, genCEdges, genVEdges;

  report_progress(mData.progress, 82, 100, "Simplifying generated mesh");
  bool success = false;
  if (mData.verbose) {
    std::cout << "[Directional::mesher()]: Cleaning Mesh" << std::endl;
    const auto start = Clock::now();
    success = functionMesher.simplify_mesh();
    const auto duration =
        std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                              start);
    std::cout << "[Directional::mesher()]: Mesh simplification time: "
              << duration.count() / 1e6 << " seconds" << std::endl;
  } else {
    success = functionMesher.simplify_mesh();
  }

  if (success) {
    if (mData.verbose) {
      std::cout << "[Directional::mesher()]: Cleaning succeeded!"
                << std::endl;
    }
    report_progress(mData.progress, 96, 100, "Assembling polygonal output");
    functionMesher.to_polygonal(VOutput, DOutput, FOutput);
    report_progress(mData.progress, 100, 100, "Output mesh generated");
  } else if (mData.verbose) {
    std::cout << "[Directional::mesher()]: Cleaning failed!" << std::endl;
  }

  mData.diagnostics.totalMesherSeconds =
      std::chrono::duration_cast<std::chrono::microseconds>(Clock::now() -
                                                            mesherStart)
          .count() /
      1.0e6;
  return success;
}

} // namespace directional
