#include <directional/geometry/AdaptiveFeatureMapVisualizer.h>

namespace directional::geometry {

AdaptiveFeatureMapOverlay
make_adaptive_feature_map_overlay(const AdaptiveFeatureMap &map) {
  AdaptiveFeatureMapOverlay overlay;
  overlay.edgeStrength.resize(static_cast<int>(map.edges.size()));
  overlay.edgeClass.resize(static_cast<int>(map.edges.size()));
  overlay.edgeCurveId.resize(static_cast<int>(map.edges.size()));
  for (int index = 0; index < static_cast<int>(map.edges.size()); ++index) {
    const AdaptiveFeatureEdge &edge = map.edges[static_cast<std::size_t>(index)];
    overlay.edgeStrength(index) = edge.strength;
    overlay.edgeClass(index) = static_cast<int>(edge.edgeClass);
    overlay.edgeCurveId(index) = edge.curve;
  }
  overlay.vertexDensity = map.vertexDensity;

  std::set<int> corners;
  std::set<int> junctions;
  for (const AdaptiveFeatureCurve &curve : map.curves) {
    corners.insert(curve.corners.begin(), curve.corners.end());
    junctions.insert(curve.junctions.begin(), curve.junctions.end());
  }
  overlay.cornerVertices.resize(static_cast<int>(corners.size()));
  overlay.junctionVertices.resize(static_cast<int>(junctions.size()));
  int row = 0;
  for (const int vertex : corners) {
    overlay.cornerVertices(row++) = vertex;
  }
  row = 0;
  for (const int vertex : junctions) {
    overlay.junctionVertices(row++) = vertex;
  }
  return overlay;
}

} // namespace directional::geometry
