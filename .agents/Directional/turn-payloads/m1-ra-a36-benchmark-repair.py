from pathlib import Path


def one(text, old, new, label):
    count = text.count(old)
    if count != 1:
        raise RuntimeError(f"{label}: expected 1 match, found {count}")
    return text.replace(old, new, 1)


path = Path("src/bench/DirectionalBenchmark.cpp")
text = path.read_text()

text = one(
    text,
    "  const RemeshDiagnostics &diagnostics = result.diagnostics;\n  out << \"{\"\n",
    '''  const RemeshDiagnostics &diagnostics = result.diagnostics;
  const geometry::SourceTopologyRegions *sourceAuthority =
      result.surfaceCellContext.traceNetwork.sourceTopologyRegions.has_value()
          ? &*result.surfaceCellContext.traceNetwork.sourceTopologyRegions
          : nullptr;
  const auto typed_sheet_index =
      [](const std::optional<authority::IsolationSheetId> &sheet) {
        return sheet.has_value() ? static_cast<int>(sheet->index()) : -1;
      };
  const auto source_component_for_region =
      [&](const std::optional<authority::TopologyRegionId> &region) {
        if (sourceAuthority == nullptr || !region.has_value() ||
            region->index() >= sourceAuthority->regions().size()) {
          return -1;
        }
        return static_cast<int>(sourceAuthority->region(*region).component().index());
      };
  const auto source_component_for_face = [&](const int sourceFace) {
    if (sourceAuthority == nullptr || sourceFace < 0) return -1;
    const auto row = authority::SourceFaceId::from_index(
        sourceFace, sourceAuthority->face_count());
    return row ? static_cast<int>(sourceAuthority->component_for_row(row.value()).index())
               : -1;
  };
  const auto source_sheet_for_face = [&](const int sourceFace) {
    if (sourceAuthority == nullptr || sourceFace < 0) return -1;
    const auto row = authority::SourceFaceId::from_index(
        sourceFace, sourceAuthority->face_count());
    return row ? static_cast<int>(sourceAuthority->sheet_for_row(row.value()).index())
               : -1;
  };
  const auto source_scope_for_faces = [&](const std::vector<int> &sourceFaces) {
    if (sourceFaces.empty()) return std::pair<int, int>{-1, -1};
    const int component = source_component_for_face(sourceFaces.front());
    const int sheet = source_sheet_for_face(sourceFaces.front());
    for (const int sourceFace : sourceFaces) {
      if (source_component_for_face(sourceFace) != component ||
          source_sheet_for_face(sourceFace) != sheet) {
        return std::pair<int, int>{-1, -1};
      }
    }
    return std::pair<int, int>{component, sheet};
  };
  out << "{"
''',
    "diagnostic source authority helpers",
)

text = one(
    text,
    '          << "\\\"sourceComponent\\\":" << halfedge.sourceComponent << ","\n          << "\\\"sourceSheet\\\":" << halfedge.sourceSheet << ","\n',
    '          << "\\\"sourceComponent\\\":"\n          << source_component_for_region(halfedge.sourceTopologyRegion) << ","\n          << "\\\"sourceSheet\\\":" << source_sheet_for_face(halfedge.sourceFace) << ","\n',
    "arrangement halfedge diagnostics",
)

text = one(
    text,
    '      << "\\\"completionOwnershipComponent\\\":"\n      << ownershipRejection.sourceComponent << ","\n      << "\\\"completionOwnershipSheet\\\":"\n      << ownershipRejection.sourceSheet << ","\n',
    '      << "\\\"completionOwnershipComponent\\\":"\n      << source_component_for_face(ownershipRejection.storedFace) << ","\n      << "\\\"completionOwnershipSheet\\\":"\n      << source_sheet_for_face(ownershipRejection.storedFace) << ","\n',
    "completion ownership diagnostics",
)

text = one(
    text,
    '  const geometry::PureQuadEmbeddingFailure &embeddingFailure =\n      result.surfaceCellContext.firstCompletionEmbeddingFailure;\n  out << "],"\n',
    '  const geometry::PureQuadEmbeddingFailure &embeddingFailure =\n      result.surfaceCellContext.firstCompletionEmbeddingFailure;\n  const auto embeddingScope = source_scope_for_faces(embeddingFailure.sourceFaces);\n  out << "],"\n',
    "embedding scope derivation",
)

text = one(
    text,
    '      << "\\\"completionEmbeddingComponent\\\":"\n      << embeddingFailure.sourceComponent << ","\n      << "\\\"completionEmbeddingSheet\\\":"\n      << embeddingFailure.sourceSheet << ","\n',
    '      << "\\\"completionEmbeddingComponent\\\":"\n      << embeddingScope.first << ","\n      << "\\\"completionEmbeddingSheet\\\":"\n      << embeddingScope.second << ","\n',
    "completion embedding diagnostics",
)

text = one(
    text,
    '      ++retainedFlowRepEndpointDegree[{arc.sourceComponent, arc.sourceSheet,\n                                      arc.startIntrinsicEndpointKey}];\n',
    '      ++retainedFlowRepEndpointDegree[{\n          source_component_for_region(arc.sourceTopologyRegion),\n          typed_sheet_index(arc.sourceIsolationSheet),\n          arc.startIntrinsicEndpointKey}];\n',
    "flowrep start endpoint key",
)
text = one(
    text,
    '      ++retainedFlowRepEndpointDegree[{arc.sourceComponent, arc.sourceSheet,\n                                      arc.endIntrinsicEndpointKey}];\n',
    '      ++retainedFlowRepEndpointDegree[{\n          source_component_for_region(arc.sourceTopologyRegion),\n          typed_sheet_index(arc.sourceIsolationSheet),\n          arc.endIntrinsicEndpointKey}];\n',
    "flowrep end endpoint key",
)
text = one(
    text,
    '        const auto found = retainedFlowRepEndpointDegree.find(\n            {arc.sourceComponent, arc.sourceSheet, key});\n',
    '        const auto found = retainedFlowRepEndpointDegree.find(\n            {source_component_for_region(arc.sourceTopologyRegion),\n             typed_sheet_index(arc.sourceIsolationSheet), key});\n',
    "flowrep endpoint lookup",
)

text = one(
    text,
    '                << "\\\"sourceComponent\\\":"\n                << provenance.sourceComponent << ","\n                << "\\\"sourceSheet\\\":" << provenance.sourceSheet << ","\n',
    '                << "\\\"sourceComponent\\\":"\n                << source_component_for_region(provenance.sourceTopologyRegion) << ","\n                << "\\\"sourceSheet\\\":"\n                << source_sheet_for_face(provenance.sourceFace) << ","\n',
    "arrangement provenance diagnostics",
)

text = one(
    text,
    '          << "\\\"sourceComponent\\\":" << arrangementArc.sourceComponent << ","\n          << "\\\"sourceSheet\\\":" << arrangementArc.sourceSheet << ","\n',
    '          << "\\\"sourceComponent\\\":"\n          << source_component_for_region(arrangementArc.sourceTopologyRegion) << ","\n          << "\\\"sourceSheet\\\":"\n          << source_sheet_for_face(arrangementArc.sourceFace) << ","\n',
    "arrangement arc diagnostics",
)

path.write_text(text)
