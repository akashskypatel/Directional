from pathlib import Path

path = Path('src/geometry/SurfaceCellTracing.cpp')
text = path.read_text()

old_decl = '''bool source_edge_provenance(
    const std::uint64_t edgeKey,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    int &sourceEdge);

VertexContinuationResult resolve_vertex_continuation(
'''
new_helper = '''bool continuation_source_edge_provenance(
    const std::uint64_t edgeKey,
    const std::map<std::uint64_t, std::array<int, 2>> &sourceEdgeFaces,
    const std::map<std::uint64_t, int> &sourceMatchingIndices,
    const EdgeTransitionLookup &transitionLookup,
    const std::vector<fields::CrossFieldEdgeTransition> *edgeTransitions,
    int &sourceEdge) {
  sourceEdge = -1;
  const auto incidence = sourceEdgeFaces.find(edgeKey);
  const auto compactIndex = sourceMatchingIndices.find(edgeKey);
  if (incidence == sourceEdgeFaces.end() || incidence->second[0] < 0 ||
      incidence->second[1] < 0 ||
      compactIndex == sourceMatchingIndices.end() ||
      compactIndex->second < 0) {
    return false;
  }
  if (edgeTransitions != nullptr) {
    const auto found = transitionLookup.byEdge.find(edgeKey);
    if (found == transitionLookup.byEdge.end() || found->second.sourceEdge < 0 ||
        edge_key(found->second.sourceVertex0,
                 found->second.sourceVertex1) != edgeKey ||
        !transition_faces_match(found->second, incidence->second[0],
                                incidence->second[1])) {
      return false;
    }
  }
  sourceEdge = compactIndex->second;
  return true;
}

VertexContinuationResult resolve_vertex_continuation(
'''
if text.count(old_decl) != 1:
    raise SystemExit(f'expected one outer provenance declaration, found {text.count(old_decl)}')
text = text.replace(old_decl, new_helper, 1)

old_call = '''      if (!source_edge_provenance(
              step.edgeKey, edgeFaces, edgeMatchingIndices, transitionLookup,
              edgeTransitions, sourceEdge)) {
'''
new_call = '''      if (!continuation_source_edge_provenance(
              step.edgeKey, edgeFaces, edgeMatchingIndices, transitionLookup,
              edgeTransitions, sourceEdge)) {
'''
if text.count(old_call) != 1:
    raise SystemExit(f'expected one M1f provenance call, found {text.count(old_call)}')
text = text.replace(old_call, new_call, 1)
path.write_text(text)
print('corrected M1f provenance helper namespace boundary')
