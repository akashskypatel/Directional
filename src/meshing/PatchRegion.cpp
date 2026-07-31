#include <directional/meshing/PatchRegion.h>

namespace directional::detail {

[[nodiscard]] std::size_t
patch_boundary_edge_count(const PatchRegion &region) {
  std::size_t total = 0;
  for (const int count : region.sideEdgeCounts) {
    if (count <= 0) {
      return 0;
    }
    total += static_cast<std::size_t>(count);
  }
  return total;
}

} // namespace directional::detail

namespace directional::detail {

[[nodiscard]] PatchBoundaryEdge
canonical_patch_edge(const int first, const int second) {
  return first <= second ? PatchBoundaryEdge{first, second}
                         : PatchBoundaryEdge{second, first};
}

} // namespace directional::detail
