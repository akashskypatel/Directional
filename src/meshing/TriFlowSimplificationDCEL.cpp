#include <directional/meshing/TriFlowSimplificationDCEL.h>

namespace directional::detail {

EVector3 triflow_dcel_exact_from_double(const Eigen::RowVector3d &p) {
  return EVector3{ENumber(p.x(), 1e-9), ENumber(p.y(), 1e-9),
                  ENumber(p.z(), 1e-9)};
}

} // namespace directional::detail
